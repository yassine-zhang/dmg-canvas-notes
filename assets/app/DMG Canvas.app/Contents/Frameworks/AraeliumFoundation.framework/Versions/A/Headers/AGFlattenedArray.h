//
//  AGFlattenedArray.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 2/7/16.
//  Copyright © 2016 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface AGFlattenedArray<ObjectType> : NSArray<ObjectType>
{
	NSUInteger mCount;
	NSUInteger mArrayCount;
	NSArray<NSArray*> * mArrays;
	
}


@property (readonly) NSUInteger arrayCount;

- (instancetype)initWithArrays:(NSArray<NSArray*> *)arrays;
- (NSUInteger)countInArrayAtIndex:(NSUInteger)index;
- (NSArray<NSArray*> *)arrayAtIndex:(NSUInteger)index;



- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithObjects:(const ObjectType _Nonnull [_Nullable])objects count:(NSUInteger)cnt  NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end





@interface AGFlattenedArray<ObjectType> (Convenience)
- (NSUInteger)flattenedIndexForObjectAtIndex:(NSUInteger)subarrayIndex inArrayAtIndex:(NSUInteger)arrayIndex;
- (NSUInteger)arrayIndexForObjectAtFlattenedIndex:(NSUInteger)flattenedIndex;
- (void)getObjectIndex:(NSUInteger *)outObjectIndex arrayIndex:(NSUInteger *)outArrayIndex forObjectAtFlattenedIndex:(NSUInteger)flattenedIndex; 
@end



NS_ASSUME_NONNULL_END

