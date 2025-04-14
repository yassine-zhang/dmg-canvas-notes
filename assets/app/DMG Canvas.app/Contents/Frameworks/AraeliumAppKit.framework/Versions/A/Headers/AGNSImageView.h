//
//  AGNSImageView.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 5/9/13.
//  Copyright (c) 2013 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AGNSImageView : NSImageView
{
	SEL _doubleAction;
}

@property (readwrite, assign) SEL doubleAction;

@end
