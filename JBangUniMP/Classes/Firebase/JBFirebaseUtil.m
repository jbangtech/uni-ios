//
//  JBFirebaseUtil.m
//  FamiDemo
//
//  Created by E·CHAN on 2022/5/24.
//

#import "JBFirebaseUtil.h"

@import FirebaseCore;
@import FirebaseAuth;
@import FirebaseStorage;

#import <JBUniMP/JBGcsInfo.h>

@interface JBFirebaseUtil ()

@property (nonatomic) FIRStorage *uniStorage;
@property (nonatomic) NSArray<NSString *> *fileURLs;
@property (nonatomic) NSMutableArray<NSString *> *fileLinks;
@property (nonatomic, copy) void(^uploadProgress)(NSNumber * _Nonnull index, NSNumber *progress);
@property (nonatomic, copy) void(^uploadFinished)(NSArray<NSString *> *fileLinks);

@end

@implementation JBFirebaseUtil

- (void)initFireBase:(JBGcsInfo *)info {
    if ([FIRApp appNamed:info.PROJECT_ID]) {
        NSLog(@"FIREBASE ALREADY EXIST!!");
        return;
    }
    if (!info) {
        NSLog(@"NO GCS INFO!!");
        return;
    }
    FIROptions *options = [[FIROptions alloc] initWithGoogleAppID:info.GOOGLE_APP_ID GCMSenderID:info.GCM_SENDER_ID];
    options.APIKey = info.API_KEY;
    options.projectID = info.PROJECT_ID;
    options.storageBucket = info.STORAGE_BUCKET;
    [FIRApp configureWithName:info.PROJECT_ID options:options];

    FIRApp *uniFIR = [FIRApp appNamed:info.PROJECT_ID];
    _uniStorage = [FIRStorage storageForApp:uniFIR];
    [[FIRAuth authWithApp:uniFIR] signInAnonymouslyWithCompletion:^(FIRAuthDataResult * _Nullable authResult, NSError * _Nullable error) { }];

    NSLog(@"FIREBASE INIT SUCCESS!!");
}

- (void)upload:(NSArray *)fileURLs type:(NSString *)type folder:(NSString *)folder progressCallback:(void (^)(NSNumber * _Nonnull index, NSNumber *progress))progressCallback callback:(void (^)(NSArray<NSString *> * _Nonnull fileLinks))callback {
    self.fileURLs = fileURLs;
    self.fileLinks = [NSMutableArray array];
    self.uploadProgress = ^(NSNumber * _Nonnull index, NSNumber *progress) {
        progressCallback(index, progress);
    };
    self.uploadFinished = ^(NSArray<NSString *> *fileLinks) {
        callback(fileLinks);
    };
    [self upload:0 folder:folder];
}

- (void)upload:(NSInteger)index folder:(NSString *)folder {
    if (index >= _fileURLs.count) {
        _uploadFinished(_fileLinks);
        return;
    }
    NSString *fileURL = _fileURLs[index];
    if (![fileURL hasPrefix:@"file://"]) {
        fileURL = [@"file://" stringByAppendingString:fileURL];
    }
    FIRStorageReference *fileReference = [_uniStorage.reference child:[NSString stringWithFormat:@"%@/%@", folder, [fileURL componentsSeparatedByString:@"/"].lastObject]];
    __weak typeof(self) _self = self;
    FIRStorageUploadTask *task = [fileReference putFile:[NSURL URLWithString:fileURL] metadata:nil completion:^(FIRStorageMetadata * _Nullable metadata, NSError * _Nullable error) {
        if (!metadata) { return; }
        [fileReference downloadURLWithCompletion:^(NSURL * _Nullable URL, NSError * _Nullable error) {
            __strong typeof(_self) self = _self;
            if (URL) {
                NSLog(@"FIREBASE UPLOAD SUCCESS!! ==> %@", URL.absoluteString);
                [self.fileLinks addObject:URL.absoluteString];
                [self upload:index + 1 folder:folder];
            } else if (error) {
                NSLog(@"FIREBASE UPLOAD Failure!!");
                [self.fileLinks addObject:@""];
            }
        }];
    }];
    [task observeStatus:(FIRStorageTaskStatusProgress) handler:^(FIRStorageTaskSnapshot * _Nonnull snapshot) {
        __strong typeof(_self) self = _self;
        NSLog(@"FIREBASE UPLOAD PROGRESS ==> %@, %f", @(index), snapshot.progress.fractionCompleted * 100);
        self.uploadProgress(@(index), @(snapshot.progress.fractionCompleted * 100));
    }];
}

@end
