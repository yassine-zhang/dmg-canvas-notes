//
//  NSPropertyListSerializationAdditions.h
//  Queries
//
//  Created by Seth Willits on 1/25/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
NS_ASSUME_NONNULL_BEGIN

@interface NSPropertyListSerialization (AraeliumAdditions)

+ (_Nullable id)mutablePropertyListFromURL:(NSURL *)url error:(NSError **)outError;
+ (BOOL)writePropertyList:(id)plist toFile:(NSString *)filePath error:(NSError **)error;

@end
NS_ASSUME_NONNULL_END

