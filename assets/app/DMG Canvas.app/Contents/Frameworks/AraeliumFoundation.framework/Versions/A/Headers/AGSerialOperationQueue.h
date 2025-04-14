//
//  AGSerialOperationQueue.h
//  NSOpQueue
//
//  Created by Seth Willits on 7/5/11.
//  Copyright 2011 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_5
@interface AGSerialOperationQueue : NSOperationQueue {
	NSOperation * mPreviousOperation;
}

@end
#endif
