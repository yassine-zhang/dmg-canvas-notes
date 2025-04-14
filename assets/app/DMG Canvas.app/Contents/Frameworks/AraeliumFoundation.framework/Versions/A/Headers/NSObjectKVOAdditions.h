//
//  NSObjectKVOAdditions.h
//
//  Created by Seth Willits on 5/7/09.
//  Copyright 2009 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSObject (KVOHelperAdditions)

+ (NSSet *)keyPathsOfInterestForObserving;
+ (NSSet *)keysForAllProperties; // 10.5 only

@end



@interface NSObject (MAKVONotification)

- (void)addObserver:(id)observer forKeyPath:(NSString *)keyPath selector:(SEL)selector userInfo:(id)userInfo options:(NSKeyValueObservingOptions)options;
- (void)removeObserver:(id)observer forKeyPath:(NSString *)keyPath selector:(SEL)selector;

- (void)addObserver:(NSObject *)observer forKeyPaths:(NSSet *)keyPaths options:(NSKeyValueObservingOptions)options selector:(SEL)selector userInfo:(id)userInfo;
- (void)removeObserver:(NSObject *)observer forKeyPaths:(NSSet *)keyPaths selector:(SEL)selector;

// - (void)keyPath:(NSString *)keypath ofObject:(id)object didChange:(NSDictionary *)change userInfo:(id)userInfo;

@end

