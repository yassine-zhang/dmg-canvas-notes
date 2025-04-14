//
//  AGNotificationQueue.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 2/4/16.
//  Copyright © 2016 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN


/// AGNotificationQueue enqueues NSNotifications to be posted to an NSNotificationCenter at a later date, from a specific NSOperationQueue. "Duplicate" notifications can be coalesced so that multiple enqueue-ings of the same notification (as determined by notification name and/or "sender" object) result in a single posting.   
@interface AGNotificationQueue : NSObject
{
	NSNotificationCenter * _notificationCenter;
	NSOperationQueue * _postingQueue;
	NSOperation * _operation;
	NSMutableArray * _notifications;
}


/// Returns a notification queue which uses the default notification center and the main thread's operation queue.
+ (instancetype)mainQueue;

/// Returns an initialized notification queue which posts notifications to `notificationCenter` from the operation queue `postingQueue`.
- (instancetype)initWithNotificationCenter:(NSNotificationCenter *)notificationCenter queue:(NSOperationQueue *)postingQueue NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/// Enqueues the notification to be posted on the receiver's posting queue as soon as possible.
/// If the notification is coalesced with an existing (yet-to-be-posted) notification, the newly enqueued notification replaces the previous notification.
- (void)enqueueNotification:(NSNotification *)notification coalesceMask:(NSNotificationCoalescing)coalesceMask;

/// Convenience method which calls enqueueNotification:coalesceMask:
- (void)enqueueNotificationName:(NSString *)name object:(id _Nullable)object userInfo:(NSDictionary * _Nullable)userInfo coalesceMask:(NSNotificationCoalescing)coalesceMask;




@end
NS_ASSUME_NONNULL_END
