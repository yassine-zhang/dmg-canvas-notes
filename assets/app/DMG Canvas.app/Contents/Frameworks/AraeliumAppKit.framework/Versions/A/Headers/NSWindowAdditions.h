//
//  NSWindowAdditions.h
//  Araelium Edit 2.1
//
//  Created by Seth Willits on 1/1/06.
//  Copyright 2006 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSWindow (AraeliumAdditions)

- (CGFloat)toolbarHeight;
- (void)resizeForContentSize:(NSSize)size;
- (void)resizeForContentSize:(NSSize)size animate:(BOOL)animate;

- (NSPoint)ag_convertPointToScreen:(NSPoint)point;
- (NSPoint)ag_convertPointFromScreen:(NSPoint)point;

- (void)ag_setFrameSize:(NSSize)newSize anchorPoint:(NSPoint)point display:(BOOL)display animate:(BOOL)animate;



// -----------------------------------------------
// Text Editing
// -----------------------------------------------

typedef NS_ENUM(NSUInteger, AGEndTextEditingOption) {
	AGEndTextEditingAndClearFirstResponder = 0,
	AGEndTextEditingAndMaintainFirstResponder,
};

//! Returns YES if the field editor voluntarily gives up first responder status. Also returns YES if nothing was being edited.
//! If the maintain option is used, the first responder is set to the field editor's text field.
//! Returns NO if the field didn't want to give up first responder, probably because of some validation issue. In this case, use ag_forcefullyEndTextEditing if needed.
- (BOOL)ag_endTextEditing:(AGEndTextEditingOption)option;

//! Forcefully sets the first responder to nil, forcing the field editor to give up first responder status, without asking it nicely. (endEditingFor: nil)
- (void)ag_forcefullyEndTextEditing;

//! Equivalent to:
//! if (![win ag_endTextEditing:AGEndTextEditingAndClearFirstResponder]) { [win ag_forcefullyEndTextEditing]; } 
- (void)ag_endTextEditing; //AndClearFirstResponderForcefullyIfNeeded;

@end



#if MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_5
#if !defined(NSWindowCollectionBehaviorCanJoinAllSpaces)
	#define NSWindowCollectionBehaviorCanJoinAllSpaces (1 << 0)
	#define NSWindowCollectionBehaviorMoveToActiveSpace (1 << 1)
#endif

// Simply defined so 10.4 apps can use respondsToSelector: and THEN use these methods
@interface NSWindow (InLeopard)
- (void)setCollectionBehavior:(NSInteger)behavior;
- (NSInteger)collectionBehavior;
@end
#endif

/*
@interface NSWindow (NSWindow_Theme)
- (void)_setShowOpaqueGrowBox:(BOOL)fp8;
@end
*/
