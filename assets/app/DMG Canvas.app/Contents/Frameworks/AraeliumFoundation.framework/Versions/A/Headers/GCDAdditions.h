//
//  GCDAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 6/5/13.
//  Copyright (c) 2013 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface GCDCoalescer : NSObject
{
    uint64_t count;
}

- (void)dispatchOn:(dispatch_queue_t)queue after:(double)seconds block:(dispatch_block_t)block;
@end
