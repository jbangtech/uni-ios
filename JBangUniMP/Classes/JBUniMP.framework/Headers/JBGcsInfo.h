//
//  JBGcsInfo.h
//  JBUniMP
//
//  Created by E·CHAN on 2022/5/24.
//

#import <Foundation/Foundation.h>
#import "JBModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface JBGcsInfo : JBModel

@property (nonatomic) NSString *API_KEY;
@property (nonatomic) NSString *BUNDLE_ID;
@property (nonatomic) NSString *CLIENT_ID;
@property (nonatomic) NSString *createTime;
@property (nonatomic) NSString *GCM_SENDER_ID;
@property (nonatomic) NSString *GOOGLE_APP_ID;
@property (nonatomic) BOOL IS_ADS_ENABLED;
@property (nonatomic) BOOL IS_ANALYTICS_ENABLED;
@property (nonatomic) BOOL IS_APPINVITE_ENABLED;
@property (nonatomic) BOOL IS_GCM_ENABLED;
@property (nonatomic) BOOL IS_SIGNIN_ENABLED;
@property (nonatomic) NSString *PLIST_VERSION;
@property (nonatomic) NSString *PROJECT_ID;
@property (nonatomic) NSString *REVERSED_CLIENT_ID;
@property (nonatomic) NSString *STORAGE_BUCKET;
@property (nonatomic) NSString *updateTime;

@end

NS_ASSUME_NONNULL_END
