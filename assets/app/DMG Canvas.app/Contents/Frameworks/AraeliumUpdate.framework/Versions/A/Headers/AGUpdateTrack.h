//
//  AGUpdateTrack.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 5/29/19.
//  Copyright © 2019 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AraeliumUpdate/AGUpdatePost.h>
@class AGUpdate;
@class AGUpdatePost;

NS_ASSUME_NONNULL_BEGIN

@interface AGUpdateTrack : NSObject

@property (readonly, copy) NSString * name;
@property (readonly, copy) NSArray<AGUpdate *> * updates;
@property (readonly, copy) NSArray<AGUpdatePost *> * posts;

- (nullable instancetype)initWithName:(NSString *)name updates:(NSArray *)updates posts:(NSArray *)posts;

@property (readonly, nullable) AGUpdate * recommendedUpdate;

/// If the date is nil, this is equivalent to recommendedUpdate.
- (AGUpdate * _Nullable)recommendedUpdateBefore:(NSDate * _Nullable)date;


/// A list of all posts that are no older than 90 days.
/// This list only contains posts which meet the conditions for min/max app version and OS version.
/// The caller is responsible for determining if the post matches any other conditions.
@property (readonly) NSArray<AGUpdatePost*> * recentPosts;

/// A filtered list of recentPosts which are since the previously handled post.
@property (readonly) NSArray<AGUpdatePost*> * recentUnhandledPosts;

/// A filtered list of recentPosts which are unhandled and of the given display time.
- (NSArray<AGUpdatePost*> *)unhandledPostsWithDisplayTime:(AGUpdatePostDisplayTime)displayTime;

/// Mark these posts as handled.
- (void)updatePostsCheckInfoToHandlePosts:(NSArray<AGUpdatePost*> *)posts;

- (NSDictionary * _Nullable)postsCheckInfo;


@end

NS_ASSUME_NONNULL_END
