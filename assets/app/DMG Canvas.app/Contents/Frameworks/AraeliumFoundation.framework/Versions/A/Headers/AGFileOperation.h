//
//  AGFileOperation.h
//
//  Created by Seth Willits on 4/27/10.
//  Copyright 2010 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>



typedef struct AGFileOperationItem {
	FSFileOperationRef operation;
	uint64_t totalBytes;
	uint64_t bytesComplete;
	uint64_t bytesRemaining;
	uint64_t totalObjects;
	uint64_t objectsComplete;
	uint64_t objectsRemaining;
	uint64_t totalUserVisibleObjects;
	uint64_t userVisibleObjectsComplete;
	uint64_t userVisibleObjectsRemaining;
	double throughput;
} AGFileOperationItem;





@interface AGFileOperation : NSObject {
	
	// Input
	NSString * mFromPath;
	NSString * mToPath;
	NSArray * mFromPaths;
	NSArray * mToPaths;
	OptionBits mOptions;
	id mDelegate;
	
	// Internal
	FSFileOperationRef mOperation;
	AGFileOperationItem * mOperations;
	NSUInteger mNumberOfOperations;
	NSUInteger mNumberOfUnfinishedOperations;
	
	// Status
	BOOL mIsCancelled;
	BOOL mIsExecuting;
	BOOL mIsFinished;
	NSString * mCurrentFile;
	uint64_t mTotalBytes;
	uint64_t mBytesComplete;
	uint64_t mBytesRemaining;
	uint64_t mTotalObjects;
	uint64_t mObjectsComplete;
	uint64_t mObjectsRemaining;
	uint64_t mTotalUserVisibleObjects;
	uint64_t mUserVisibleObjectsComplete;
	uint64_t mUserVisibleObjectsRemaining;
	double mThroughput;
}


@property (readwrite, assign) id delegate;

@property (readonly) BOOL	isCancelled;
@property (readonly) BOOL	isExecuting;
@property (readonly) BOOL	isFinished;

@property (readonly) NSString * fromPath;
@property (readonly) NSString * toPath;
@property (readonly) NSArray *	fromPaths;
@property (readonly) NSArray *	toPaths;
@property (readonly) NSString *	currentFile;

@property (readonly) uint64_t	totalBytes;
@property (readonly) uint64_t	bytesComplete;
@property (readonly) uint64_t	bytesRemaining;
@property (readonly) uint64_t	totalObjects;
@property (readonly) uint64_t	objectsComplete;
@property (readonly) uint64_t	objectsRemaining;
@property (readonly) uint64_t	totalUserVisibleObjects;
@property (readonly) uint64_t	userVisibleObjectsComplete;
@property (readonly) uint64_t	userVisibleObjectsRemaining;
@property (readonly) double		throughput;


- (OSStatus)moveFromPath:(NSString *)fromPath toPath:(NSString *)toPath options:(OptionBits)options;
- (OSStatus)copyFromPath:(NSString *)fromPath toPath:(NSString *)toPath options:(OptionBits)options;

- (OSStatus)beginMoveFromPath:(NSString *)fromPath toPath:(NSString *)toPath options:(OptionBits)options;
- (OSStatus)beginCopyFromPath:(NSString *)fromPath toPath:(NSString *)toPath options:(OptionBits)options;

- (BOOL)beginMoveItemsAtPaths:(NSArray *)fromPaths toPaths:(NSArray *)toPaths options:(OptionBits)options error:(NSError **)outError;
- (BOOL)beginCopyItemsAtPaths:(NSArray *)fromPaths toPaths:(NSArray *)toPaths options:(OptionBits)options error:(NSError **)outError;

- (void)cancel;


@end



@protocol AGFileOperationDelegate <NSObject>

- (void)fileOperationStatusChanged:(AGFileOperation *)operation;
- (void)fileOperationDidFinish:(AGFileOperation *)fileOperation error:(OSStatus)error;

@end

