//
//  AGByteFormatter.h
//  Freak Softare
//
//  Created by Seth Willits on 2/2/05.
//  Copyright 2005 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface AGByteFormatter : NSFormatter {
	NSString * mNumberFormat;
}


- (void)setNumberFormat:(NSString *)format;
- (NSString *)numberFormat;


@end
