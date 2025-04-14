//
//  AGUpdateAppMover.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 1/28/13.
//  Copyright (c) 2013 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

enum {
	AGUpdateAppMoveFailed = -1,
	AGUpdateAppMoveCancelled = 0,
	AGUpdateAppMoveNotNeeded = 1
};
typedef NSInteger AGUpdateAppMoveResult;


@interface AGUpdateAppMover : NSObject
{
	NSString * mPreferredInstallLocation;
	BOOL mIsInstallingToUserFolder;
	
	NSString * mDestinationPath;
}

+ (AGUpdateAppMoveResult)moveToApplicationsFolderIfNecessary;
+ (AGUpdateAppMoveResult)moveToApplicationsFolderWithoutAsking;

@end
