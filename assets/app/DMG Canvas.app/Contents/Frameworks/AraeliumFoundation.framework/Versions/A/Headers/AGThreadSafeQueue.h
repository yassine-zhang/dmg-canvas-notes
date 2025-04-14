//
//  AGThreadSafeQueue.h
//  AraeliumFoundation
//
//  Based on WHThreadSafeQueue written by Keith Bauer
//  Keith is the man.
//

#import <Cocoa/Cocoa.h>

@interface AGThreadSafeQueue : NSObject
{
    NSConditionLock *lock;
    NSMutableArray  *queue;
	NSUInteger maximumCapacity;
	BOOL replacesOldestObject;
}

@property (readwrite) BOOL replacesOldestObject;

- (id)init;
- (id)initWithMaximumCapacity:(NSUInteger)max;

- (void)enqueue:(id)object;
- (id)dequeue;
- (id)dequeueBeforeDate:(NSDate *)date;
- (BOOL)empty;

@end
