//
//  AGCacheLRUExpiryPolicy.h
//  AraeliumFoundation
//
//  Based on CNCache written by Keith Bauer
//  Keith is the man.
//

#import <Foundation/Foundation.h>
#import <AraeliumFoundation/AGCache.h>


@interface AGCacheLRUExpiryPolicy : NSObject <AGCacheExpiryPolicy>
{
	NSUInteger count;
	NSArray   *sortDescriptors;
}

+ (id)lruExpiryPolicyWithFixedCount:(NSUInteger)count;

@end

@interface AGCache (AGLRUCacheConvenience)

+ (id)lruCacheWithGenerator:(id <NSObject, AGCacheGenerator>)generator
				 fixedCount:(NSUInteger)count;
+ (id)lruCacheWithFixedCount:(NSUInteger)count;

@end



