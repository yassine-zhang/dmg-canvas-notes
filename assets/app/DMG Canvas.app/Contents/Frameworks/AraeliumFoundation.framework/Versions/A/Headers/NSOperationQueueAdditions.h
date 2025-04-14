//
//  NSOperationQueueAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 9/5/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
NS_ASSUME_NONNULL_BEGIN



#define MAINQ [NSOperationQueue mainQueue]


@interface NSOperationQueue (DefaultInstanceAdditions)

// Generally houldn't use this
+ (id)defaultOperationQueue;

@end




@interface NSOperationQueue (Helpful)
- (NSOperation *)addOperationWithBlock:(void (^)(void))block dependencies:(NSArray<NSOperation*> *)dependencies;
@end


NS_ASSUME_NONNULL_END
