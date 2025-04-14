//
//  NSSoundAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 3/2/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSSound (AraeliumAdditions)

+ (id)soundNamed:(NSString *)name inBundle:(NSBundle *)bundle;
+ (id)soundNamed:(NSString *)name inBundleForClass:(Class)aclass;

@end

