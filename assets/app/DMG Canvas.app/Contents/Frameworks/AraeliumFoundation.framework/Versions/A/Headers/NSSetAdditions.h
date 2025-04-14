//
//  NSSetAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 4/9/11.
//  Copyright 2011 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSSet (AraeliumAdditions)

- (NSSet *)setIntersectingSet:(NSSet *)otherSet;

- (NSSet *)setByRemovingObject:(id)anObject;
- (NSSet *)setByRemovingObjectsFromSet:(NSSet *)other;
- (NSSet *)setByRemovingObjectsFromArray:(NSArray *)other;


@end
