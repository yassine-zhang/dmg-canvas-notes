//
//  AGUpdateFeed.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 8/14/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>
@class AGUpdate;
@class AGUpdateSystemProfile;
@class AGUpdateTrack;

NS_ASSUME_NONNULL_BEGIN

@interface AGUpdateFeed : NSObject

@property (readonly) NSURL * URL;

/// Updates within the standard release track
@property (readonly) NSArray<AGUpdate *> * updates;

/// Recommended update from the standard release track
/// -- Disabled to avoid accidentally using the wrong track.
//@property (readonly) AGUpdate * recommendedUpdate;

/// 
@property (readonly) NSDictionary<NSString*,AGUpdateTrack*> * releaseTracks; 

/// The handler is guaranteed to be called, and called on the main thread. The handler is guaranteed to have either a non-nil feed or a non-nil error.
+ (void)fetchFeedAtURL:(NSURL *)url
			parameters:(NSDictionary * _Nullable)params
			   profile:(AGUpdateSystemProfile * _Nullable)profile
	 completionHandler:(void (^)(AGUpdateFeed * _Nullable feed, NSError * _Nullable error))handler;

@end

NS_ASSUME_NONNULL_END
