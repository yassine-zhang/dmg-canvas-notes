//
//  AGTimeFormatter.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 4/27/10.
//  Copyright 2010 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


enum {
    AGTimeFormatterShortStyle = 0,	// 1d 2h 3m 4s
    AGTimeFormatterMediumStyle,		// 1 day 2 hrs 3 mins 4 secs
    AGTimeFormatterLongStyle,		// 1 day, 2 hours, 3 minutes, 4 seconds
    AGTimeFormatterFullStyle,		// ?
	
	AGTimeFormatterColonStyle,      // 2 days 24:18:31.24
};
typedef NSUInteger AGTimeStyle;


enum {
    AGTimeFormatterDefault = 0,
	AGTimeFormatterHideSecondsWhenHours = 1,
	AGTimeFormatterLargestUnitOnly = 2 // 3 days 4 hours 2 minutes --> "3 days"
};
typedef NSUInteger AGTimeFormattingOptions;



@interface AGTimeFormatter : NSFormatter {
	AGTimeStyle mTimeStyle;
	BOOL mShowsFractions;
	AGTimeFormattingOptions mOptions;
}

@property (nonatomic, readwrite, assign) AGTimeStyle timeStyle;
@property (nonatomic, readwrite, assign) BOOL showsFractions;
@property (nonatomic, readwrite, assign) AGTimeFormattingOptions options;


@end
