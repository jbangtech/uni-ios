//
//  JBUniMPConstant.h
//  JBUniMP
//
//  Created by ECHANLSAKFJOISYYZZZ on 2022/3/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NSString * JBUniModuleType NS_TYPED_ENUM;
UIKIT_EXTERN JBUniModuleType const JBUniModuleTypeUser NS_SWIFT_NAME(user);
UIKIT_EXTERN JBUniModuleType const JBUniModuleTypePush NS_SWIFT_NAME(push);
UIKIT_EXTERN JBUniModuleType const JBUniModuleTypeStatistics NS_SWIFT_NAME(statistics);
UIKIT_EXTERN JBUniModuleType const JBUniModuleTypeMap NS_SWIFT_NAME(map);
UIKIT_EXTERN JBUniModuleType const JBUniModuleTypeAction NS_SWIFT_NAME(action);

static NSString * const kJBUserIdKey = @"JBUserId";
static NSString * const kJBTokenKey = @"JB-Authorization";
static NSString * const kJBModuleInfoKey = @"JBModuleInfo";

static NSString * const kJBStartPayWebViewName = @"JBStartPayWebView";
static NSString * const kJBNavigateToPageName = @"JBNavigateToPage";

/// 打开小程序页面的方式
typedef NS_ENUM(NSUInteger,JBUniMPOpenMode) {
    JBUniMPOpenModePresent,
    JBUniMPOpenModePush
};
