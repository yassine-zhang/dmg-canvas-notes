//
//  AGUpdatePanel.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 8/17/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AraeliumUpdate/AraeliumUpdate.h>
#import <WebKit/WebKit.h>
@class AGUpdatePanelBackgroundView;

NS_ASSUME_NONNULL_BEGIN


typedef NS_CLOSED_ENUM(NSInteger, AGUpdatePanelResponseCode) {
	AGUpdatePanelResponseOK = 1,
	AGUpdatePanelResponseCancel = 0,
	AGUpdatePanelResponseRenew = 2,
	AGUpdatePanelResponseUpgrade = 2
};


@interface AGUpdatePanel : NSPanel

- (void)setUpdates:(NSArray<AGUpdate *> * _Nonnull)updates designatedUpdate:(AGUpdate *)update;

@property (readwrite, assign) BOOL allowsDownloadingInBackground;
@property (readonly) NSArray<AGUpdate*> * updates;
@property (readonly) AGUpdate * designatedUpdate;


+ (instancetype)panel;
- (void)beginSheetModalForWindow:(NSWindow *)window completionHandler:(void (^)(AGUpdatePanelResponseCode result))handler;
- (NSInteger)runModal __attribute__((deprecated("Modal windows prevent the AGUpdate from downloading. Use 'showWindow' instead.")));
- (void)showWindow:(void (^ __nullable)(AGUpdatePanelResponseCode result))completionHandler;

@end
NS_ASSUME_NONNULL_END
