//
//  AGUpdatePost.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 5/29/19.
//  Copyright © 2019 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AraeliumUpdate/AGUpdateItem.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, AGUpdatePostDisplayTime) {
	
	/// At launch or at time of check, but excludes At Quit
	AGUpdatePostDisplayTimeDefault = 0,
	
	/// Only at time of quit
	AGUpdatePostDisplayTimeAtQuit = 1,
	
	/// Don't display unless the user clicks on some UI element to display it
	AGUpdatePostDisplayTimePassive = 2,
};



@interface AGUpdatePost : NSObject <AGUpdateItem>

@property (readonly, copy) NSString * title;
@property (readonly, copy) NSURL * postURL;
@property (readonly) AGUpdatePostDisplayTime displayTime;
@property (readonly) NSSize preferredDisplaySize;

/// No longer show after this date
@property (readonly, copy, nullable) NSDate * endDate;
@property (readonly, copy, nullable) NSString * endDateString;

/// Combination of the date and title used for comparison
@property (readonly, copy) id identifier;

@end

NS_ASSUME_NONNULL_END
