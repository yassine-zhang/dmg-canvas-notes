//
//  NSViewAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 12/4/15.
//  Copyright © 2015 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSView (AraeliumAdditions)
- (void)ag_removeAllSubviews;
- (NSSize)ag_sizeSoSubview:(NSView *)subview isSize:(NSSize)subviewSize;
- (void)ag_resizeSoSubview:(NSView *)subview isSize:(NSSize)subviewSize;
- (void)ag_resizeToWidth:(CGFloat)width;

- (void)ag_moveTopLeftTo:(NSPoint)point;
- (void)ag_moveOriginTo:(NSPoint)point;

@end
