//
//  AGUpdate.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 8/14/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AraeliumUpdate/AGUpdateItem.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^AGUpdateDownloadProgressHandler)(double progress);
typedef void (^AGUpdateDownloadCompletionHandler)(NSError * _Nullable error);

typedef void (^AGUpdateInstallErrorHandler)(NSError * error);


enum {
	AGUpdateStatusInfoOnly = 0,
	AGUpdateStatusDownloading,
	AGUpdateStatusDownloaded,
	AGUpdateStatusUnarchiving,
	AGUpdateStatusUnarchived
};



@interface AGUpdate : NSObject <AGUpdateItem>

@property (readonly, copy) NSString * title;
@property (readonly, copy) NSString * version;
@property (readonly, copy) NSString * displayVersion;
@property (readonly, copy, nullable) NSString * itemDescription;
@property (readonly, copy, nullable) NSString * extra;
@property (readonly, copy) NSURL * releaseNotesURL;
@property (readonly, copy, nullable) NSURL * fileURL;
@property (readonly, copy, nullable) NSURL * linkURL;
@property (readonly, copy, nullable) NSString * licensedMinimumVersion;
@property (readonly) NSSize preferredDisplaySize;

/// A string
/// major, minor, bugfix
/// This property could be inferred from the displayVersion. If it's "x.0" or "x", then it's a major version. If it's "x.n" or "x.n.0" it's a minor. If it's "x.y.z" then it's bug fix.
//@property (readonly, copy, nullable) NSString * versionType;

/// Requires that the displayVersion be nonnull and in x.y.z form.
/// If it's "x.0" or "x", then it's a major version.
@property (readonly) BOOL isMajorVersion;

/// Requires that the displayVersion be nonnull and in x.y.z form.
/// If it's "x.n" or "x.n.0" it's a minor.
@property (readonly) BOOL isMinorVersion;

/// Requires that the displayVersion be nonnull and in x.y.z form.
/// If it's not major or minor, then it's bug fix.
@property (readonly) BOOL isBugfixVersion;



// OPTIONAL properties.
@property (readwrite, assign) BOOL requiresUpgrade;
@property (readwrite, assign) BOOL requiresRenewal;




- (void)ignore;
- (void)launch;


- (void)downloadWithProgress:(AGUpdateDownloadProgressHandler _Nullable)progressHandler completion:(AGUpdateDownloadCompletionHandler)completionHandler;
- (void)cancelDownload;


@property (readonly) BOOL excludeFromAutoDownloading;
@property (readonly) BOOL canBeDownloaded; //! Has a fileURL
@property (readonly) BOOL isDownloading;
@property (readonly) BOOL isDownloaded;
@property (readonly, copy) NSString * downloadPath;
@property (readonly) double downloadProgress;
@property (readonly) uint64_t downloadSize;


- (void)installWithErrorHandler:(AGUpdateInstallErrorHandler)errorHandler;
@property (readonly) BOOL isInstalling;
@property (readonly) BOOL isInstalled;

@end

NS_ASSUME_NONNULL_END
