/*
 *  NSSavePanelAdditions.h
 *  Araelium Edit 2.1
 *
 *  Created by Seth Willits on 5/30/07.
 *  Copyright 2007 Araelium Group. All rights reserved.
 *
 */

#import <Cocoa/Cocoa.h>



@interface NSSavePanel (MethodsAppleIsTooLazyToExpose)
- (void)setShowsHiddenFiles:(BOOL)show;
@end
