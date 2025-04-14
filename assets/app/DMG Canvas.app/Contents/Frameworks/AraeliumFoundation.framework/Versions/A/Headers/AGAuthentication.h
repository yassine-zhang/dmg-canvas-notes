//
//  AGAuthentication.h
//  Araelium Group
//
//  Created by Seth Willits on 4/7/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <SecurityFoundation/SFAuthorization.h>


@interface AGAuthentication : NSObject {
	NSTimer * mReleaseTimer;
	
	AuthorizationFlags mAuthFlags;
	AuthorizationItem mAuthItem;
	AuthorizationRights mAuthRights;
	AuthorizationRights * mAuthObtainedRights;
	AuthorizationRef mAuthorizationRef;
}

+ (id)sharedInstance;
+ (NSString *)authorizationErrorString:(OSStatus)err;
- (OSStatus)executeTask:(NSString *)taskLaunchPath arguments:(NSArray *)arguments options:(AuthorizationFlags)flags;

@end


@interface AGAuthentication (ConvenienceMethods)

- (BOOL)createFolderAtPath:(NSString *)path error:(NSError **)error;
- (BOOL)createFoldersInPath:(NSString *)path error:(NSError **)error;
- (BOOL)movePath:(NSString *)fromPath toPath:(NSString *)toPath error:(NSError **)error;
- (BOOL)removeItemAtPath:(NSString *)path error:(NSError **)error;

@end



