//
//  NSEventAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 2/29/16.
//  Copyright © 2016 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


#define NSModifiersSet(a, b)    IS_FLAG_SET(a, b)
#define NSModifiersClear(a, b)  IS_FLAG_CLEAR(a, b)

//! Only compares shift, options, control, command, and function. Ignores caps lock.
#define NSModifiersEqual(a, b)  (((a) & (NSEventModifierFlagShift | NSEventModifierFlagOption | NSEventModifierFlagControl | NSEventModifierFlagCommand | NSEventModifierFlagFunction)) == (b))



@interface NSEvent (AraeliumAdditions)

- (BOOL)ag_isOptionLeftClick;

@end
