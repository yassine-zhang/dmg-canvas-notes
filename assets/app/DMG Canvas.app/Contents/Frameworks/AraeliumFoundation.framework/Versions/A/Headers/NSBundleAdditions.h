//
//  NSBundleAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 6/14/07.
//  Copyright 2007 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSBundle (NSBundleAraeliumAdditions)

- (BOOL)ag_loadNibNamed:(NSString *)nibName owner:(id)owner topLevelObjects:(NSArray **)topLevelObjects;
+ (BOOL)loadNibNamed:(NSString *)nibName owner:(id)owner topLevelObjects:(NSArray **)topLevelObjects;
//+ (BOOL)loadNibFile:(NSString *)nibFilePath owner:(id)owner topLevelObjects:(NSArray **)topLevelObjects;

+ (NSArray *)loadWithTopLevelObjectsNibNamed:(NSString *)nibName bundle:(NSBundle *)bundle owner:(id)owner;
+ (NSArray *)loadWithTopLevelObjectsNibNamed:(NSString *)nibName owner:(id)owner;
//+ (NSArray *)loadWithTopLevelObjectsNibFile:(NSString *)nibFilePath owner:(id)owner;

@end


#define NSLocalizedStringf(key, comment, ...) \
	    [NSString stringWithFormat:[[NSBundle mainBundle] localizedStringForKey:(key) value:@"" table:nil], __VA_ARGS__]

#define NSLocalizedStringAppendf(format, key, comment, ...) \
		[NSString stringWithFormat:(format), NSLocalizedString((key), (comment)), __VA_ARGS__]
