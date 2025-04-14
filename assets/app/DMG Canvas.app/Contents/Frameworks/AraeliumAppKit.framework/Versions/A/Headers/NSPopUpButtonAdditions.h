//
//  NSPopUpButtonAdditions.h
//  Queries
//
//  Created by Seth Willits on 9/6/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSPopUpButton (HelpfulAdditions)

- (void)selectItemWithRepresentedObject:(id _Nullable)obj;
- (void)removeItemWithTag:(NSInteger)tag;

- (void)ag_sizeToFitSelectedItem;

@end
