//
//  NSAppearanceAdditions.h
//  Querious
//
//  Created by Seth Willits on 12/11/18.
//  Copyright © 2018 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSAppearance (MyAdditions)

- (BOOL)ag_isDark;
+ (BOOL)ag_hasReducedTransparency;

@end

NS_ASSUME_NONNULL_END
