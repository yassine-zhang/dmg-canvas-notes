//
//  AGRollingSampler.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 10/7/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef struct {
	double value;
	NSTimeInterval time;
} AGRollingSample;


typedef struct {
	double sum;
	NSUInteger count;
	NSTimeInterval time;
} AGRollingSampleResult;


@interface AGRollingSampler : NSObject
{
	dispatch_queue_t _queue;
	AGRollingSample * _samples;
	NSUInteger _samplesCapacity;
	NSUInteger _samplesCount;
}

- (instancetype)initWithWindowSize:(NSUInteger)maxSamples;
- (void)addSample:(double)sample;
- (AGRollingSampleResult)resultForPreviousSeconds:(NSTimeInterval)seconds;
- (void)removeAllSamples;

@end
