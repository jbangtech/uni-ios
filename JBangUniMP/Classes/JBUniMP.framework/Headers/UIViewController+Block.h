//
//  UIViewController+Block.h
//  JBUniMP
//
//  Created by E·CHAN on 2022/4/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (Block)

@property (nonatomic) NSDictionary *jbParams;
@property (nonatomic, copy) void(^jbBlock)(id data);

@end

NS_ASSUME_NONNULL_END
