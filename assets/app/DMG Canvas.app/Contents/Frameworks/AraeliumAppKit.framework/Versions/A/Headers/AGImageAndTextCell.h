//
//  AGImageAndTextCell.h
//  TextCellTest
//
//  Created by Seth Willits on 2/25/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>



typedef enum _AGImageAndTextCellStyle {
	
	// Typical text cell appearance.
	// Use this in a plain NSTableView with white, or alternating row backgrounds.
	AGImageAndTextCellStylePlain = 0,
	
	// No shadow, and uses thin focus ring.
	// Use this style in an AGGradientTableView.
	AGImageAndTextCellStyleShadowlessGradient,
	
	// Light shadow, white text for active and inactive highlight
	// Use this style in an AGGradientTableView.
	AGImageAndTextCellStyleLightShadowGradient,
	
} AGImageAndTextCellStyle;


typedef enum _AGVerticalTextAlignment {
	AGVerticalTextAlignmentCenter = 0,
	AGVerticalTextAlignmentTop,
	AGVerticalTextAlignmentBottom
} AGVerticalTextAlignment;


typedef enum _AGFocusRingStyle {
	AGFocusRingStyleNone,
	AGFocusRingStyleDefault,
	AGFocusRingStyleThin
} AGFocusRingStyle;



@interface AGImageAndTextCell : NSTextFieldCell {
	
	// Appearance
	AGVerticalTextAlignment mVerticalAlignment;
	CGFloat mIndentation;
	
	// Images
	NSImage	* mImage;
	NSImage * mRightImage;
	NSSize mImagePadding;
	NSSize mImageSize;
	NSSize mRightImageSize;
	
	// Text
	NSString * mDetailText;
	
	// Text Shadow
	NSShadow * mActiveHighlightTextShadow;
	NSShadow * mInactiveHighlightTextShadow;
	NSShadow * mTextShadow;
	
	// Text Color
	NSColor * mActiveHighlightTextColor;
	NSColor * mInactiveHighlightTextColor;
	
	// Focus Ring
	AGFocusRingStyle mFocusRingStyle;
	
	// Extremely Customized
	BOOL mIsSeparator;
	
	// --- Internal ---
	BOOL mIsHighlighted;
	BOOL mIsWindowActive;
	BOOL mIsControlActive;
	
	
	NSImageCell * mLeftImageImageCell;
	NSImageCell * mRightImageImageCell;
}




// Appearance
- (void)setCellStyle:(AGImageAndTextCellStyle)style;

// Layout
- (void)setVerticalAlignment:(AGVerticalTextAlignment)verticalAlignment;
- (AGVerticalTextAlignment)verticalAlignment;
- (void)setIndentation:(CGFloat)indentation;
- (CGFloat)indentation;

// Text
- (void)setTextShadow:(NSShadow *)textShadow;
- (void)setActiveHighlightTextShadow:(NSShadow *)textShadow;
- (void)setInactiveHighlightTextShadow:(NSShadow *)textShadow;
- (void)setActiveHighlightTextColor:(NSColor *)textColor;
- (void)setInactiveHighlightTextColor:(NSColor *)textColor;
- (NSShadow *)textShadow;
- (NSShadow *)activeHighlightTextShadow;
- (NSShadow *)inactiveHighlightTextShadow;
- (NSColor *)activeHighlightTextColor;
- (NSColor *)inactiveHighlightTextColor;

// Focus Ring
- (void)setFocusRingStyle:(AGFocusRingStyle)style;
- (AGFocusRingStyle)focusRingStyle;

// Images
- (void)setImage:(NSImage *)image;
- (void)setRightImage:(NSImage *)image;
- (void)setImageSize:(NSSize)imageSize;
- (void)setRightImageSize:(NSSize)imageSize;
- (void)setImagePadding:(NSSize)imageSize;
- (NSImage *)image;
- (NSImage *)rightImage;
- (NSSize)imagePadding;
- (NSSize)imageSize;
- (NSSize)rightImageSize;

// Drawn below the normal line of text (if space is available)
- (void)setDetailText:(NSString *)detailText;
- (NSString *)detailText;

// Extremely Customized (needs to be implemented)
- (void)setIsSeparator:(BOOL)separator;


@end
