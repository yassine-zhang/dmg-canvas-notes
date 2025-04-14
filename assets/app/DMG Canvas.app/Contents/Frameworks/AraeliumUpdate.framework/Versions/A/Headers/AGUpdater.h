//
//  AGUpdater.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 8/14/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@protocol AGUpdaterDelegate;
@class AGUpdate;
@class AGUpdateFeed;

NS_ASSUME_NONNULL_BEGIN

extern NSString * AGUpdateErrorDomain;



extern NSString * AGUpdatePrefAnonymousUUIDKey;
extern NSString * AGUpdatePrefUpdateCheckIntervalKey;
extern NSString * AGUpdatePrefAutomaticallyChecksForUpdatesKey;
extern NSString * AGUpdatePrefAutomaticallyDownloadsUpdatesKey;
extern NSString * AGUpdatePrefSendsSystemProfileKey;
extern NSString * AGUpdatePrefFeedURLKey;
extern NSString * AGUpdatePrefLastUpdateCheckDateKey;
extern NSString * AGUpdatePrefPostsCheckInfoKey;
extern NSString * AGUpdatePrefLightlyIgnoredVersionKey;
extern NSString * AGUpdatePrefLightlyIgnoredDateKey;


typedef NSComparisonResult (^AGUpdateVersionComparator)(NSString *, NSString *);
typedef void (^AGUpdateCheckHandler)(AGUpdateFeed * _Nullable feed, NSError * _Nullable error);


@interface AGUpdater : NSObject

@property (readwrite, assign, nullable) id<AGUpdaterDelegate> delegate;
@property (readwrite, copy) NSURL * feedURL;
@property (readwrite, copy) AGUpdateVersionComparator versionComparator;
@property (readwrite, assign, nonatomic) NSTimeInterval updateCheckInterval;
@property (readwrite, assign, nonatomic) BOOL automaticallyChecksForUpdates;
@property (readwrite, assign, nonatomic) BOOL automaticallyDownloadsUpdates;
@property (readwrite, assign, nonatomic) BOOL sendsSystemProfile;

@property (readonly, nullable) NSDate * lastUpdateCheckDate;
@property (readonly) BOOL isChecking;
@property (readonly) BOOL isUpdating;

@property (class, readonly) NSString * anonymousUUID;

+ (instancetype)sharedUpdater;

/// The handler is called on the main thread. If the handler is nil, then updater:didCheckForUpdate:error: on the delegate will be called on the main thread. The handler and delegate are called mutually exclusively.
/// May be called from any thread.
- (void)checkForUpdate:(AGUpdateCheckHandler _Nullable)handler;


@property (readonly) NSString * updateCacheDirectoryFilePath;

@end






@protocol AGUpdaterDelegate <NSObject>
@optional

// ------- Checking for updates ---------

// Provide extra parameters to the checking URL
- (NSDictionary *)feedParametersForUpdater:(AGUpdater *)updater;

// Only called for auto-checks. feed will be nil when there's an error
- (void)updater:(AGUpdater *)updater didCheckForUpdate:(AGUpdateFeed * _Nullable)feed error:(NSError * _Nullable)error;



// ------- Install / Relaunch

// Some apps *cannot* be relaunched in certain circumstances. They can use this method
// to prevent a relaunch
// - (BOOL)updaterShouldRelaunchApplication:(AGUpdater *)updater;

// Called immediately before relaunching.
// - (void)updaterWillRelaunchApplication:(AGUpdater *)updater;

// Sent immediately before installing the specified update.
// - (void)updater:(AGUpdater *)updater willInstallUpdate:(SUAppcastItem *)update;



// ------- Update Info
// If unimplemented, assumed to be nil.
- (NSDate * _Nullable)expirationDateForUpdatesWithCurrentLicense:(AGUpdater *)updater;




// Use this to override the default behavior for Sparkle prompting the user about automatic update checks.
// - (BOOL)updaterShouldPromptForPermissionToCheckForUpdates:(AGUpdater *)bundle;

// Implement this if you want to do some special handling with the appcast once it finishes loading.
// - (void)updater:(AGUpdater *)updater didFinishLoadingAppcast:(SUAppcast *)appcast;

// If you're using special logic or extensions in your appcast, implement this to use your own logic for finding
// a valid update, if any, in the given appcast.
// - (SUAppcastItem *)bestValidUpdateInAppcast:(SUAppcast *)appcast forUpdater:(AGUpdater *)bundle;

// Return YES to delay the relaunch until you do some processing; invoke the given NSInvocation to continue.
//	This is not called if the user didn't relaunch on the previous update, in that case it will immediately
//	restart.
// - (BOOL)updater:(AGUpdater *)updater shouldPostponeRelaunchForUpdate:(SUAppcastItem *)update untilInvoking:(NSInvocation *)invocation;




@end

NS_ASSUME_NONNULL_END
