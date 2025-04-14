//
//  NSWorkspaceAdditions.h
//  Araelium Edit 2.1
//
//  Created by Seth Willits on 1/19/06.
//  Copyright 2006 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSWorkspace (AGAdditions)

- (NSImage *)cachedIconForFile:(NSString *)path;
- (NSInteger)FinderLabelColorIndexForFile:(NSString*)inPath;
- (void)setFinderLabelColorIndex:(NSInteger)index forFile:(NSString*)path;
- (NSColor *)FinderLabelColorForFile:(NSString*)inPath;
- (NSColor *)FinderLabelColorAtIndex:(NSInteger)index;
- (BOOL)isFileVisibleAtPath:(NSString *)path;

- (BOOL)openURLInBackground:(NSURL *)url;

@end
