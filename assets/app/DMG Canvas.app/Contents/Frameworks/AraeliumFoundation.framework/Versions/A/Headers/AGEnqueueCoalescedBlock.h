//
//  AGEnqueueCoalescedBlock.h
//  EnqueuedBlocks
//
//  Created by Seth Willits on 2/26/15.
//  Copyright (c) 2015 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Executes the block on the given queue immediately if no block with 'key' is running. Otherwise, this block is enqeued,
//! replacing any previously-enqueued block with the same 'key'. Once the running block finishes, the enqueued block executes (if there is one).
void AGEnqueueCoalescedBlock(void * key, dispatch_queue_t queue, void (^block)(void));

//! Removes an enqueued block with the given key, preventing it from running.
void AGCancelEnqueuedBlock(void * key);
