//
//  NSAlertAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 7/14/11.
//  Copyright 2011 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSAlert (AraeliumAdditions)
//! Delete button = NSAlertFirstButtonReturn
//! Cancel button = NSAlertSecondButtonReturn
+ (instancetype)deleteConfirmationWithMessage:(NSString *)message deleteButton:(NSString *)deleteButtonTitle cancelButton:(NSString *)cancelButtonTitle informativeText:(NSString *)informative;


//! Adds a Cmd-D button
- (void)addDontSaveButtonWithTitle:(NSString *)title;

//! Adds a Cmd-Delete button
- (void)addDeleteButtonWithTitle:(NSString *)title;

//! Adds a Escape button
- (void)addCancelButtonWithTitle:(NSString *)title;





- (NSTextView *)addScrollingTextView;

@end
