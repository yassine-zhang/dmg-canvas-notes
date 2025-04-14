//
//  AGTableView.h
//  Queries
//
//  Created by Seth Willits on 1/25/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
NS_ASSUME_NONNULL_BEGIN

@protocol AGTableViewDelegate <NSTableViewDelegate>

@optional

/// Return YES if it was handled.
/// If NO is returned, it call performKeyEquivalent: on super.
- (BOOL)performKeyEquivalent:(NSEvent *)event inTableView:(NSTableView *)tableView;

/// Return YES if it was handled.
/// If NO is returned, it call keyDown: on super.
- (BOOL)keyDown:(NSEvent *)event inTableView:(NSTableView *)tableView;

// Really don't want to use this
//@optional
//- (NSMenu * _Nullable)tableView:(NSTableView *)tableView menuForEvent:(NSEvent *)theEvent;

@end






@interface AGTableView : NSTableView {
	BOOL mDoesNOTForceRowSelectionOnRightClick; // inverted so it defaults the right way
}

@property (atomic, nullable, weak) id <AGTableViewDelegate> delegate;
//- (void)setDelegate:(id <AGTableViewDelegate>)delegate;
//- (id <AGTableViewDelegate>)delegate;

//@property (readwrite, assign) BOOL forcesRowSelectionOnRightClick;

@end
NS_ASSUME_NONNULL_END

