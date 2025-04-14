//
//  AGUpdatePostWindowController.h
//
//  Created by Seth Willits on 10/13/24.
//  Copyright © 2024 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AraeliumUpdate/AraeliumUpdate.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * AGUpdatePostWindowDidCloseNotificationName;

typedef NS_ENUM(NSUInteger, AGUpdatePostCloseReturnCode) {
	AGUpdatePostCloseReturnCodeDefault,
	AGUpdatePostCloseReturnCodeShowAgainLater
};

@interface AGUpdatePostWindowController : NSWindowController

@property (class, readonly) AGUpdatePostWindowController * sharedInstance;
@property (nonatomic, readwrite, copy, nullable) NSArray<AGUpdatePost*> * posts;
@property (nonatomic, readwrite, copy, nullable) void (^onCloseHandler)(void);

- (AGUpdatePostCloseReturnCode)showWindowModally:(BOOL)atQuit;

@end

NS_ASSUME_NONNULL_END
