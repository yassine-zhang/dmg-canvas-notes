//
//  NSTextFieldAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 9/30/13.
//  Copyright (c) 2013 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSTextField (AraeliumAdditions)

//! Returns the field's suggest height to fit its text while fitting within the given width
- (NSSize)sizeFittingWidth:(CGFloat)width;

@end
