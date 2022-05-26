//
//  JBUniStatisticsModule.h
//  JBUniMP
//
//  Created by ECHANLSAKFJOISYYZZZ on 2022/3/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JBUniStatisticsModule : NSObject

/// 进入页面
- (void)onPageStart:(NSString *)pageName;

/// 退出页面
- (void)onPageEnd:(NSString *)pageName;

/// 点击事件
- (void)onEvent:(NSString *)eventId label:(NSString *)label acc:(NSInteger)acc attributes:(NSDictionary<NSString *, id> *)attributes;

/// 长按事件开始
- (void)onEventStart:(NSString *)eventId label:(NSString *)label;

/// 长按事件结束
- (void)onEventEnd:(NSString *)eventId label:(NSString *)label;

/// 自定义时长事件
- (void)onEventDuration:(NSString *)eventId label:(NSString *)label milliseconds:(long)milliseconds;

/// 自定义时长事件，带 attributes 参数
- (void)onEventDuration:(NSString *)eventId label:(NSString *)label milliseconds:(long)milliseconds attributes:(NSDictionary<NSString *, id> *)attributes;

@end

NS_ASSUME_NONNULL_END
