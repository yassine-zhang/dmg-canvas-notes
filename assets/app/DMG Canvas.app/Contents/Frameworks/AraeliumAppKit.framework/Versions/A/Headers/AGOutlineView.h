//
//  AGOutlineView.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 5/3/13.
//  Copyright (c) 2013 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
NS_ASSUME_NONNULL_BEGIN


@protocol AGOutlineViewDelegate <NSOutlineViewDelegate>
@optional

/// Return YES if the event was handled
- (BOOL)performKeyEquivalent:(NSEvent *)event inOutlineView:(NSOutlineView *)outlineView;

/// Return YES if the event was handled
- (BOOL)keyDown:(NSEvent *)event inOutlineView:(NSOutlineView *)outlineView;
@end




@interface AGOutlineView : NSOutlineView

@property (atomic, nullable, weak) id <AGOutlineViewDelegate> delegate;

@end
NS_ASSUME_NONNULL_END


