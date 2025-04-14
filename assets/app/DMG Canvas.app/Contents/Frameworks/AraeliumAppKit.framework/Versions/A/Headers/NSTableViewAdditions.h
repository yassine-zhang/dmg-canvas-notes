//
//  NSTableViewAdditions.h
//  Queries
//
//  Created by Seth Willits on 2/9/09.
//  Copyright 2009 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSTableView (Additions)

//- (void)scrollRowToVisible:(NSInteger)rowIndex;

#if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_5
- (NSIndexSet *)rowIndexesForManipulation;
#endif


- (void)ag_centerSelectedRowInScrollView;
- (void)ag_scrollRowToTop:(NSInteger)row;
- (void)ag_scrollRowToCenter:(NSInteger)row;
- (void)ag_scrollColumnToCenter:(NSInteger)col;

- (void)ag_flashColumn:(NSInteger)col;

- (BOOL)ag_isRowVisible:(NSInteger)row;
//- (BOOL)ag_isColumnVisible:(NSInteger)row;


//! Changes the table columns in the receiver to match those in the array, removing, adding, and re-ordering as necessary.
//! If a column in the array is already in the table, this method leaves the column in the table, and merely reorders it
//! as necessary. This strategy maintains the sort descriptors set on the table.
- (void)ag_changeTableColumns:(NSArray *)tableColumns;

@end



//#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_6
//@interface NSTableCellView (AraeliumAdditions)
//+ (id)tableCellViewWithNibNamed:(NSString *)nibName;
//@end
//#endif
