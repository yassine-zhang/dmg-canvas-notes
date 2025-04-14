//
//  AGCache.h
//  AraeliumFoundation
//
//  Based on CNCache written by Keith Bauer
//  Keith is the man.
//

#import <Foundation/Foundation.h>
@class AGCache;



@protocol AGCacheGenerator <NSObject>
- (id)generateObjectForKey:(id)key;
@end



@protocol AGCacheExpiryPolicy <NSObject>
- (void)preInsertExpireFrom:(AGCache *)cache;
@end



@interface AGCache : NSObject {
    id <AGCacheGenerator>    generator;
    id <AGCacheExpiryPolicy> expiryPolicy;
    
    NSMutableDictionary *store;
}

+ (id)cacheWithExpiryPolicy:(id <AGCacheExpiryPolicy>)expiryPolicy;
+ (id)cacheWithGenerator:(id <AGCacheGenerator>)generator
            expiryPolicy:(id <AGCacheExpiryPolicy>)expiryPolicy;

- (id)objectForKey:(id)key;
- (void)setObject:(id)object forKey:(id)key;
- (NSUInteger)count;

@end



@interface AGCacheItem : NSObject
{
    NSDate *creationTime;
    NSDate *accessTime;
    id      object;
    id      key;
}

+ (id)cacheItemWithObject:(id)object key:(id)key;

- (void)setAccessTime:(NSDate *)accessTime;
- (NSDate *)creationTime;
- (NSDate *)accessTime;
- (id)object;
- (id)key;

@end



@interface AGCache (AGCacheInternals)

- (AGCacheItem *)cacheItemWithKey:(id)key;
- (void)removeCacheItemWithKey:(id)key;

- (NSArray *)cacheItems;

@end
