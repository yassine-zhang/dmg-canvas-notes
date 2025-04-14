//
//  AGUpdateCheckingPanel.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 10/17/13.
//  Copyright (c) 2013 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AGUpdateCheckingPanel : NSPanel
{
	IBOutlet NSView * theContentView;
	IBOutlet NSTextField * titleField;
	IBOutlet NSTextField * messageField;
	IBOutlet NSButton * button;
	IBOutlet NSProgressIndicator * progressIndicator;
	NSArray * mTopLevelObjectsInNib;
	BOOL _running;
}


+ (instancetype)updateCheckingPanel;
- (NSInteger)runModal;
- (void)close;

- (void)showUpToDate;
- (void)showUpgradingRequired;

@end
