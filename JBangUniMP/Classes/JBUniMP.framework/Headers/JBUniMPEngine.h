//
//  JBUniMPEngine.h
//  JBUniMP
//
//  Created by ECHANLSAKFJOISYYZZZ on 2022/3/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JBUniMPConstant.h"

@class JBUniStatisticsModule;
@class JBUniMPFirebaseUtil;

NS_ASSUME_NONNULL_BEGIN

@interface JBUniMPEngine : NSObject

+ (void)initWithLaunchOptions:(nullable NSDictionary *)launchOptions;
+ (void)initWithLaunchOptions:(nullable NSDictionary *)launchOptions isDebug:(BOOL)isDebug;
+ (void)initWithModuleInfo:(nullable NSDictionary<JBUniModuleType,Class> *)info launchOptions:(nullable NSDictionary *)launchOptions isDebug:(BOOL)isDebug;

// MARK: - App Life Circle

+ (void)applicationDidBecomeActive:(UIApplication *)application;
+ (void)applicationWillResignActive:(UIApplication *)application;
+ (void)applicationDidEnterBackground:(UIApplication *)application;
+ (void)applicationWillEnterForeground:(UIApplication *)application;
+ (void)destory;

// MARK: - Open App

+ (void)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
+ (void)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity;

// MARK: - Uni

/// 检查运行目录是否存在应用资源，不存在则将应用资源部署到运行目录
+ (void)checkUniMPResource:(NSString *)appid;
/// 打开小程序
+ (void)openUniMP:(NSString *)appid completion:(void (^)(BOOL success))completion;
/// 打开小程序
+ (void)openUniMP:(NSString *)appid path:(NSString *)path completion:(void (^)(BOOL success))completion;
/// 打开小程序
+ (void)openUniMP:(NSString *)appid path:(NSString *)path extraData:(id)extraData completion:(void (^)(BOOL success))completion;
/// 打开小程序
+ (void)openUniMP:(NSString *)appid path:(NSString *)path extraData:(id)extraData enableBackground:(BOOL)enableBackground completion:(void (^)(BOOL success))completion;
/// 打开小程序
+ (void)openUniMP:(NSString *)appid path:(NSString *)path extraData:(id)extraData enableBackground:(BOOL)enableBackground openMode:(JBUniMPOpenMode)openMode completion:(void (^)(BOOL success))completion;
/// 预加载小程序
+ (void)preloadUniMP:(NSString *)appid completion:(void (^)(BOOL success))completion;
/// 预加载小程序
+ (void)preloadUniMP:(NSString *)appid path:(NSString *)path completion:(void (^)(BOOL success))completion;
/// 预加载小程序
+ (void)preloadUniMP:(NSString *)appid path:(NSString *)path extraData:(id)extraData completion:(void (^)(BOOL success))completion;
/// 预加载小程序
+ (void)preloadUniMP:(NSString *)appid path:(NSString *)path extraData:(id)extraData enableBackground:(BOOL)enableBackground completion:(void (^)(BOOL success))completion;
/// 预加载小程序
+ (void)preloadUniMP:(NSString *)appid path:(NSString *)path extraData:(id)extraData enableBackground:(BOOL)enableBackground openMode:(JBUniMPOpenMode)openMode completion:(void (^)(BOOL success))completion;
/// 打开指定路由页面
+ (void)openUniPage:(NSString *)appid path:(NSString *)path completion:(void (^)(BOOL success))completion;
/// 发送事件
+ (void)sendEvent:(NSString *)eventId data:(id)data;
/// 将应用资源部署到运行路径中
+ (void)releaseUniMP:(NSString *)appid wgtPath:(NSString *)wgtPath completion:(void (^)(BOOL success))completion;
/// 移除小程序资源
+ (void)removeUniResource:(NSString *)appid;
/// 更新指定小程序
//+ (void)updateUniMP:(nullable NSString *)appid;
/// 指定小程序是否正在运行
//+ (BOOL)isRunning:(NSString *)appid;
/// 关闭指定小程序
//+ (void)closeUniMP:(nullable NSString *)appid;
/// 获取当前控制器
+ (UIViewController *)getMPViewController;
/// 获取当前显示的小程序appid
+ (NSString *)getActiveMPAppid;

/// 获取Uni实例
//+ (DCUniMPInstance *)getUniMPInstance:(NSString *)appid;

/// 设置BaseURL
+ (void)setBaseURL:(NSString *)baseURL;
/// 能否重复下载同appid wgt
+ (void)setCanDownloadWgtForSameAppId:(BOOL)canDownload;
/// 设置自定义参数
+ (void)setCustomParam:(id)value forKey:(NSString *)key;
/// 设置自定义参数
+ (void)setCustomParam:(NSDictionary *)param;
/// 给控制器设置路由
+ (void)setRouter:(NSString *)router forViewController:(UIViewController *)viewController __attribute__((deprecated("Use -registerRouter:forViewController:")));
/// 给控制器设置路由
+ (void)registerRouter:(NSString *)router forViewController:(UIViewController *)viewController;

// MARK: - Module

+ (void)setStatisticsModule:(JBUniStatisticsModule *)statisticsModule;
+ (void)setFirebaseUtil:(JBUniMPFirebaseUtil *)firebaseUtil;

// MARK: - User

/// 设置用户id
+ (void)setUserId:(NSString *)userId;
/// 设置session
+ (void)setSession:(NSString *)session;
/// 获取加密token
+ (NSString *)getEncryptToken;
/// 登入
+ (void)login:(NSString *)userId callback:(void(^)(NSNumber *code, NSString *msg))callback;
/// 登出
+ (void)logout;

@end

NS_ASSUME_NONNULL_END
