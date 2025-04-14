//
//  AGHotKeyCenter.h
//  UltimateScreenshot
//
//  Created by Seth Willits on 2/6/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <AppKit/AppKit.h>
#import <Carbon/Carbon.h>
@class AGHotKey;


NS_ASSUME_NONNULL_BEGIN

typedef void (^AGHotKeyHandler)(AGHotKey * hotkey, NSEvent * event);



@interface AGHotKey : NSObject
{
	AGHotKeyHandler mHandler;
	NSUInteger mKeyCode;
	NSUInteger mModifierFlags;
	
	UInt32 mHotKeyID;
	NSValue * mHotKeyRef;
}

@property (nonatomic, readonly, copy) AGHotKeyHandler handler;
@property (nonatomic, readonly) NSUInteger keyCode;
@property (nonatomic, readonly) NSUInteger modifierFlags;

@end





@interface AGHotKeyCenter : NSObject {
	NSMutableSet * mHotKeys;
	EventHandlerRef mEventHandler;
}

+ (instancetype)sharedHotKeyCenter;

- (AGHotKey * _Nullable)registerHotKeyWithKeyCode:(NSUInteger)keyCode modifierFlags:(NSUInteger)flags handler:(AGHotKeyHandler)handler;
- (void)unregisterHotKey:(AGHotKey *)hotKey;
//- (void)unregisterHotKeyWithKeyCode:(NSUInteger)keyCode modifierFlags:(NSUInteger)flags;

- (BOOL)hasRegisteredHotKeyWithKeyCode:(NSUInteger)keyCode modifierFlags:(NSUInteger)flags;
- (NSSet *)registeredHotKeys;


@end

NS_ASSUME_NONNULL_END
