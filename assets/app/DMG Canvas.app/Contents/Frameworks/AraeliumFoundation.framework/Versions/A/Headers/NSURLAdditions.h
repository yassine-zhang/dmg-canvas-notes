//
//  NSURLAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 2/8/16.
//  Copyright © 2016 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (AraeliumAdditions)

/// Returns the volume name for the receiver if it's a file path URL.
/// Throws an exception if it's not a file path url.
/// Note that the volume must at least exist.
- (NSString * _Nonnull)ag_volumeName;


- (NSURL * _Nullable)ag_volumeRootURL;

@end
