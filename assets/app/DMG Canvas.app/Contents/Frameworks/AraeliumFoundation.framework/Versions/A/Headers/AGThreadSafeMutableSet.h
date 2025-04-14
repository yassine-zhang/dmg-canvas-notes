//
//  AGThreadSafeMutableSet.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 12/2/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AGThreadSafeMutableSet : NSMutableSet
{
	dispatch_queue_t _queue;
	NSMutableSet * _set;
}

@end
