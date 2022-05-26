//
//  JBUniMPFirebaseUtil.h
//  JBUniMP
//
//  Created by E·CHAN on 2022/5/24.
//

#import <UIKit/UIKit.h>

@class JBGcsInfo;

NS_ASSUME_NONNULL_BEGIN

@interface JBUniMPFirebaseUtil : NSObject

- (void)initFireBase:(JBGcsInfo *)info;
- (void)upload:(NSArray *)fileURLs type:(NSString *)type folder:(NSString *)folder progressCallback:(void (^)(NSNumber * _Nonnull index, NSNumber *progress))progressCallback callback:(void (^)(NSArray<NSString *> * _Nonnull fileLinks))callback;

@end

NS_ASSUME_NONNULL_END
