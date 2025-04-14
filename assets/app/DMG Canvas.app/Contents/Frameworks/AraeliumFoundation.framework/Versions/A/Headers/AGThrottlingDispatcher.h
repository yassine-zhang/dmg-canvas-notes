//
//  AGThrottlingDispatcher.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 7/12/13.
//  Copyright (c) 2013 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, AGThrottlingDispatcherMode) {
	/*!
		
		@field AGThrottlingDispatcherModeThrottlesTimeBetweenStarts
		@brief Simply requires 'seconds' to pass between blocks starting. If blocks take longer than 'seconds' to execute, there may be multiple blocks executing concurrently.
		
		@discussion Example of blocks which take 0 to 2 seconds to execute, the throttle is set to 1.0.
	 
			0.dispatch at 0.00
					0.start at 0.00
			1.dispatch at 0.15
			2.dispatch at 0.30
			3.dispatch at 0.46
			4.dispatch at 0.61
					0.done  at 0.64
			5.dispatch at 0.77
			6.dispatch at 0.92
					6.start at 1.01
			7.dispatch at 1.07
			8.dispatch at 1.22
			9.dispatch at 1.38
			10.dispatch at 1.53
			11.dispatch at 1.68
			12.dispatch at 1.83
			13.dispatch at 1.99
					13.start at 2.01
					6.done  at 2.10
			14.dispatch at 2.14
			15.dispatch at 2.29
			16.dispatch at 2.45
			17.dispatch at 2.60
			18.dispatch at 2.76
			19.dispatch at 2.91
					19.start at 3.01
			20.dispatch at 3.06
					13.done  at 3.23
					19.done  at 3.60
					20.start at 4.01
					20.done  at 5.49

		Note that some blocks DO execute concurrently (6 and 13), that there is no minimum time that must pass
		between the finish of the prior block, and the start of the next block (0 and 6), and there is only the
		minimum time that must pass between the start of one block, and the start of the next; The between the
		*starts* of each of these pairs (0-6, 6-13, 13-19, 19-20) is 1.0 seconds.
	 
	 */
	AGThrottlingDispatcherModeThrottlesTimeBetweenStarts = 0,
	
	
	/*!
		@field AGThrottlingDispatcherModeThrottlesTimeBetweenExecution
		@brief Requires 'seconds' to pass between the previous block finishing and the next one starting. Blocks are guaranteed to execute exclusively.
		 
		@discussion
			Example of blocks which take 0.5 seconds to execute, the throttle is set to 1.0 seconds. Notice that no blocks execute concurrently, are spaced 1.0 seconds apart, and the latest available block is always executed.

				0.dispatch at 0.0
						0.start at 0.0
				1.dispatch at 0.2
				2.dispatch at 0.3
				3.dispatch at 0.5
						0.done  at 0.5
				4.dispatch at 0.6
				5.dispatch at 0.8
				6.dispatch at 0.9
				7.dispatch at 1.1
				8.dispatch at 1.2
				9.dispatch at 1.4
						9.start at 1.5
				10.dispatch at 1.5
				11.dispatch at 1.7
				12.dispatch at 1.8
				13.dispatch at 2.0
						9.done  at 2.0
				14.dispatch at 2.2
				15.dispatch at 2.3
				16.dispatch at 2.5
				17.dispatch at 2.6
				18.dispatch at 2.8
				19.dispatch at 2.9
						19.start at 3.0
				20.dispatch at 3.1
						19.done  at 3.5
						20.start at 4.5
						20.done  at 5.0
	*/
	AGThrottlingDispatcherModeThrottlesTimeBetweenExecution = 1
};




//! @class AGThrottlingDispatcher
//! @discussion This object dispatches the blocks it receives, at most, once every 'seconds', (so that blocks executing no more often than 'seconds') with extra options depending on the mode.
@interface AGThrottlingDispatcher : NSObject
{
	dispatch_queue_t _executionQueue;
	double _throttleSeconds;
	NSUInteger _mode;
	
	// ------------
	
	dispatch_queue_t _throttlingQueue;
	dispatch_source_t _source;
	dispatch_block_t _blockToFire;
	BOOL _timerIsActive;
}


//! Designated initializer. `mode` determines how `seconds` is used.
- (instancetype)initWithQueue:(dispatch_queue_t)queue seconds:(double)seconds mode:(AGThrottlingDispatcherMode)mode NS_DESIGNATED_INITIALIZER;

//! Uses mode AGThrottlingDispatcherModeThrottlesTimeBetweenStarts
- (instancetype)initWithQueue:(dispatch_queue_t)queue seconds:(double)seconds DEPRECATED_ATTRIBUTE;
- (instancetype)init NS_UNAVAILABLE;

//! Enqueues a block to be dispatched. Blocks are coalesced, so that only the most recent block is run, at the correct time.
- (void)dispatch:(dispatch_block_t)block;

@end

