//
//  NSArrayAdditions.h
//  Queries
//
//  Created by Seth Willits on 7/29/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSArray (AraeliumAdditions)

- (id)firstObject;
- (id)objectWithValue:(id)value forKey:(NSString *)key;
- (NSUInteger)indexOfObjectWithValue:(id)value forKey:(NSString *)key;
- (NSIndexSet *)indexesOfObjectsInArray:(NSArray *)array;
- (NSIndexSet *)indexesOfObjectsInSet:(NSSet *)set;

- (NSArray *)arrayByInsertingObject:(id)object atIndex:(NSUInteger)index;
- (NSArray *)arrayByInsertingObjects:(NSArray *)objects atIndexes:(NSIndexSet *)indexes;

- (NSArray *)arrayByRemovingObject:(id)object;
- (NSArray *)arrayByRemovingObjectsInArray:(NSArray *)excludedObjects;
- (NSArray *)arrayByRemovingObjectAtIndex:(NSUInteger)index;
- (NSArray *)arrayByRemovingObjectsAtIndexes:(NSIndexSet *)indexes;

- (NSArray *)componentsEnclosedWith:(NSString *)encloser;
- (NSArray *)componentsEnclosedBy:(NSString *)start and:(NSString *)end;

- (NSArray *)objectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id obj, BOOL *stop))predicate;
- (id)ag_objectPassingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL *stop))predicate;



//! Moving objects within an array involves removing the objects, and then inserting the removed objects at a target index.
//! That target index can change after the removal (depending on how many removed items are before that index). This method
//! return the adjusted target index after the removal, appropriate for insertObjects:atIndex:
+ (NSUInteger)ajustedInsertionIndex:(NSUInteger)targetIndexBeforeMove forMovingObjectsAtIndexes:(NSIndexSet *)indexes;




//! Collects non-nil objects returned by the mapBlock into an array.
//! Always returns a non-nil array.
- (NSArray *)ag_map:(id (^)(id obj))mapBlock;


- (NSArray *)arrayByDuplicating:(NSUInteger)times;
- (NSArray *)arrayByDuplicatingUntilCount:(NSUInteger)count;

@end


@interface NSMutableArray (AraeliumAdditions)

//! Moves the objects at the given indexes to the new position. Consider it like drag and drop where the target index
//! is the index before the objects are removed and then re-inserted.
- (void)moveObjectsAtIndexes:(NSIndexSet *)indexes toIndex:(NSUInteger)targetIndexBeforeMove;

//! Inserts the objects in order starting at index.
//! Equivalent to: [self insertObjects:objects atIndexes:[NSIndexSet indexSetWithIndexesInRange:NSMakeRange(index, objects.count)]];
- (void)insertObjects:(NSArray *)objects atIndex:(NSUInteger)index;

//! Pops the first object out of the array.
- (id)ag_popFirstObject;

//! Pops the last object out of the array.
- (id)ag_popObject;

//! Pushes the object onto the end of the array.
- (void)ag_pushObject:(id)object;

@end


@interface NSArray (AraeliumFoundationSortingAddition)

- (NSArray *)sortedArrayUsingKey:(NSString *)key ascending:(BOOL)ascending selector:(SEL)selector;

@end


