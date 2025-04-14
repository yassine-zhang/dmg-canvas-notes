//
//  NSFileManagerAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 3/22/05.
//  Copyright 2005 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#import <Security/Security.h>


@interface NSFileManager (AraeliumFolderSizeAdditions)

//enum { 
//	AGLogicalSize		 = 1 << 0,
//	AGPhysicalSize		 = 1 << 2,
//	AGDataFork			 = 1 << 3,
//	AGResourceFork		 = 1 << 4,
//	AGSizeDefaultOptions = (AGDataFork | AGResourceFork | AGLogicalSize)
//};
//
//- (uint64_t)sizeOfItemAtPath:(NSString *)path options:(NSUInteger)options;

- (uint64_t)totalFileSizeOfItemAtPath:(NSString *)path;

@end



@interface NSFileManager (AraeliumAdditions)
- (NSString *)validatedFileName:(NSString *)filename;

//- (NSString *)findSystemFolderType:(NSInteger)folderType forDomain:(NSInteger)domain;
- (NSString *)fileTypeForFileAtPath:(NSString *)filePath;
- (NSString *)uniquePathForFileWithDesiredPath:(NSString *)inPath;
- (NSString *)pathForDuplicateOfFileAtPath:(NSString *)path;

#if MAC_OS_X_VERSION_MAX_ALLOWED < MAC_OS_X_VERSION_10_5
- (NSString *)duplicateFileAtPath:(NSString *)path handler:(id)handler;
#else
- (NSString *)duplicateFileAtPath:(NSString *)path error:(NSError **)error;
#endif


#if MAC_OS_X_VERSION_MAX_ALLOWED < MAC_OS_X_VERSION_10_5
- (BOOL)createDirectoryAtPath:(NSString *)path withIntermediateDirectories:(BOOL)createIntermediates attributes:(NSDictionary *)attributes error:(NSError **)error;
#endif

- (BOOL)moveContentsOfDirectoryAtPath:(NSString *)sourceDirectoryPath intoDirectoryAtPath:(NSString *)destinationDirectoryPath replace:(BOOL)replace;
- (BOOL)removeDirectoryAtPath:(NSString *)directoryPath;
@end


@interface NSFileManager (AraeliumAdditionsWithAuthorization)

// Do multiple ops under a single authorization
- (OSStatus)obtainAuthorization:(AuthorizationRef *)outAuthorizationRef flags:(AuthorizationFlags)flags;
- (void)freeAuthorization:(AuthorizationRef)authorizationRef;
- (OSStatus)removeFileAtPath:(NSString *)sourcePath removeDirectories:(BOOL)directories recursive:(BOOL)recursive withAuthorization:(AuthorizationRef)authorizationRef;
- (OSStatus)copyPath:(NSString *)sourcePath toPath:(NSString *)destinationPath replace:(BOOL)replace withAuthorization:(AuthorizationRef)authorizationRef;
- (OSStatus)movePath:(NSString *)sourcePath toPath:(NSString *)destinationPath replace:(BOOL)replace withAuthorization:(AuthorizationRef)authorizationRef;
- (OSStatus)moveContentsOfDirectoryAtPath:(NSString *)sourceDirPath intoDirectoryAtPath:(NSString *)destDirPath replace:(BOOL)replace withAuthorization:(AuthorizationRef)authorizationRef;

// Do discrete auths for each operation
- (OSStatus)authorizedRemoveFileAtPath:(NSString *)sourcePath removeDirectories:(BOOL)directories recursive:(BOOL)recursive;
- (OSStatus)authorizedCopyPath:(NSString *)sourcePath toPath:(NSString *)destinationPath replace:(BOOL)replace;
- (OSStatus)authorizedMovePath:(NSString *)sourcePath toPath:(NSString *)destinationPath replace:(BOOL)replace;
- (OSStatus)authorizedMoveContentsOfDirectoryAtPath:(NSString *)sourceDirPath intoDirectoryAtPath:(NSString *)destDirPath replace:(BOOL)replace;

@end


