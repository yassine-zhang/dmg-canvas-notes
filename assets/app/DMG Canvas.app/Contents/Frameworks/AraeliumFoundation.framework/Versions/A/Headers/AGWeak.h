//
//  Weak.h
//  Querious
//
//  Created by Seth Willits on 4/12/17.
//  Copyright © 2017 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
#if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_7

@interface AGWeak<ObjectType> : NSObject
{
	__weak id _ref;
}

+ (instancetype _Nonnull)ref:(ObjectType _Nullable)ref;
- (instancetype _Nonnull)initWithRef:(ObjectType _Nullable)ref;
@property (nonatomic, readonly, nullable) ObjectType ref;

#define WEAK(type) AGWeak<type*>
AGWeak * weak(id obj);

@end
#endif
NS_ASSUME_NONNULL_END
