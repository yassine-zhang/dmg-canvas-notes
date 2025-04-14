//
//  NSURLConnectionAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 2/12/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURLConnection (AraeliumAdditions)

/// Replicates old Apple method
+ (NSData *)ag_sendSynchronousRequest:(NSURLRequest *)request response:(NSURLResponse **)outResponse error:(NSError **)outError;

+ (void)sendSynchronousRequest:(NSURLRequest *)request completionBlock:(void (^)(NSData *data, NSURLResponse *response, NSError *error))block;

+ (void)sendAsynchronousRequest:(NSURLRequest *)request completionBlock:(void (^)(NSData *data, NSURLResponse *response, NSError *error))block;

@end
