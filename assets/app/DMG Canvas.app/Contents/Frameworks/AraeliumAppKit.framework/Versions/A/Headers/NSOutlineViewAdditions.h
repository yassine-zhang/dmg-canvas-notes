//
//  NSOutlineViewAdditions.h
//  Araelium Edit 2.1
//
//  Created by Seth Willits on 6/15/07.
//  Copyright 2007 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSOutlineView (AraeliumAdditions)

- (NSArray *)itemsAtRowIndexes:(NSIndexSet *)rows;

- (NSArray *)selectedItems;
- (void)selectItems:(NSArray *)selectedItems;

@property (nonatomic, readonly) NSArray * ag_selectedItems;
@property (nonatomic, readonly) NSArray * ag_expandedItems;

// These can be quite dangerous if the selected items were deleted and deallocated
//- (void)reloadDataAndRestoreSelection;
//- (void)reloadItemAndRestoreSelection:(id)item reloadChildren:(BOOL)reloadChildren;

@end
