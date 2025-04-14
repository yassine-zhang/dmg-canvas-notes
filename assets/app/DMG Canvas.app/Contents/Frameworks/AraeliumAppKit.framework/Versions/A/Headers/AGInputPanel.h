//
//  AGInputPanel.h
//  Queries
//
//  Created by Seth Willits on 1/23/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>



typedef NS_ENUM(NSInteger, AGInputPanelReturn) {
	AGInputPanelReturnOK = 1,
	AGInputPanelReturnCancel = 0
};

@interface AGInputPanel : NSPanel {
	NSArray * mTopLevelObjectsInNib;
	
	IBOutlet NSView * theContentView;
	
	IBOutlet NSView * rightSideContainerView;
    IBOutlet NSImageView * imageView;
	IBOutlet NSTextField * titleField;
	IBOutlet NSTextField * messageField;
	
	IBOutlet NSTextField * inputField;
	IBOutlet NSSecureTextField * secureInputField;
	IBOutlet NSButton * showsTypingButton;
	
	BOOL mIsSecure;
	BOOL mShowsTyping;
}

+ (id)inputPanelWithTitle:(NSString *)title;
- (id)initWithTitle:(NSString *)title;

@property (readwrite, retain) NSImage * image;
@property (readwrite, assign) BOOL isSecure;
@property (readwrite, copy) NSString * title;
@property (readwrite, copy) NSString * message;
@property (readwrite, copy) NSString * stringValue;
 
- (void)layout;
- (NSInteger)runModal;
- (void)beginSheetModalForWindow:(NSWindow *)window completionHandler:(void (^)(NSInteger result))handler;

// Internal
- (IBAction)ok:(id)sender;
- (IBAction)cancel:(id)sender;
- (IBAction)showsTyping:(id)sender;

@end

// - (void)inputPanelDidEnd:(AGInputPanel *)panel returnCode:(NSInteger)returnCode contextInfo:(void *)contextInfo;


