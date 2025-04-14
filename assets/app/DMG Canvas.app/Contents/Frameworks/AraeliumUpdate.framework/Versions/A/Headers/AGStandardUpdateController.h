//
//  AGStandardUpdateController.h
//  Screenflick
//
//  Created by Seth Willits on 1/17/13.
//
//

#import <Foundation/Foundation.h>
#import <AraeliumUpdate/AraeliumUpdate.h>
@class AGStandardUpdateController;


NS_ASSUME_NONNULL_BEGIN

@interface AGUpdateCurrentConditions : NSObject
@property (readwrite) AGUpdateConditionRegistration registration;
@property (readwrite) AGUpdateConditionLaunch launch;
@end


@protocol AGStandardUpdateControllerDelegate <NSObject>

/// Return whether it's the first launch, and the app is registered.
- (AGUpdateCurrentConditions *)currentConditionsForUpdating:(AGStandardUpdateController *)updateController NS_SWIFT_NAME(currentConditionsForUpdating(_:));

/// Update the UI to display whether checking is occurring or updates/posts are available.
- (void)updateInterfaceForUpdateControllerStatus:(AGStandardUpdateController *)updateController NS_SWIFT_NAME(updateInterfaceForUpdateControllerStatus(_:));


@optional
/// Return any extra query parameters for the URL when requesting the update feed.  
- (NSDictionary *)feedParametersForUpdating:(AGStandardUpdateController *)updateController NS_SWIFT_NAME(feedParametersForUpdating(_:));

/// Notifies after every time the request for the feed URL was successfully responded to.
/// This method can be used as a way to reset any values which should change the next time feedParametersForUpdating
/// is called. 
- (void)updaterDidCheckForUpdates:(AGStandardUpdateController *)updateController NS_SWIFT_NAME(updaterDidCheckForUpdates(_:));

/// If nil or unimplemented, alerts and panels are all modal.
- (NSWindow * _Nullable)sheetParentWindowForUpdater:(AGStandardUpdateController *)updateController;

@end



typedef NS_OPTIONS(NSInteger, AGStandardUpdateControllerStatus) {
	AGStandardUpdateControllerStatusNone = 0,
	AGStandardUpdateControllerStatusReadOnlyVolume = 1,
	AGStandardUpdateControllerStatusChecking = 2,
	AGStandardUpdateControllerStatusUpdateAvailable = 4,
	AGStandardUpdateControllerStatusPostAvailable = 8,
};



@interface AGStandardUpdateController : NSObject

/// The current status of checking, and whether there's an update available.
@property (readonly) AGStandardUpdateControllerStatus status;
@property (readwrite, assign, nullable) id<AGStandardUpdateControllerDelegate> delegate;


/// Must be called when the application finishes launching and auto-checking could begin.
- (void)setup;


/// Returns true if the application is on a read only volume, and displays an alert. Called
/// automatically in the update process, but can be called again manually if needed at other times.
- (BOOL)complainIfInReadOnlyVolume;




// ------------------------------------------------------------------------------------------
//   Updates
// ------------------------------------------------------------------------------------------

@property (readonly, nullable) AGUpdateFeed * feed;
@property (readonly, nullable) AGUpdate * bestUpdate;


/// The main method to manuall check for updates
- (void)checkForUpdateAndShowChecking:(BOOL)showChecking showUpdate:(BOOL)showUpdate NS_SWIFT_NAME(checkForUpdate(showChecking:showUpdate:));


/// If there is an update available, this will display the interface for suggesting that update.
- (void)showBestUpdateInPanel;



// ------------------------------------------------------------------------------------------
//   News Posts
// ------------------------------------------------------------------------------------------

/// News posts can be displayed at launch (default), passively (UI should indicate somewhere
/// that posts are available to be displayed, or at quit.
//
/// I _thought_ it would be a good idea to allow the "news posts" feature to force displaying a post
/// on quit, if such a post was in the feed. I no longer think that's a good idea for what I was
/// going to use it for (a new user trial survey), but the capability is wrapped up in this.
/// On-quit posts are displayed modally.

@property (readonly) BOOL hasPostsToShowAtQuit;
@property (readonly) BOOL hasPostsToShowPassively;

/// Call at the time of proposed application termination.
/// Returns YES if there are posts to show, or are currently already showing (when called previously)
- (BOOL)showPostsAtQuit;

- (BOOL)showPostsPassively;

@end

NS_ASSUME_NONNULL_END
