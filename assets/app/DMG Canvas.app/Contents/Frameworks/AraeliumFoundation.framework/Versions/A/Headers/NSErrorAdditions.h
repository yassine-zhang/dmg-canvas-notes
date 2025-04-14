//
//  NSErrorAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 2/18/12.
//  Copyright (c) 2012 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


#define AGMakeError_Description_Suggestion(domain, errorCode, description, recoverySuggestion) \
	[NSError errorWithDomain:(domain) code:(errorCode) userInfo:[NSDictionary dictionaryWithObjectsAndKeys: \
	(description), NSLocalizedDescriptionKey, (recoverySuggestion), NSLocalizedRecoverySuggestionErrorKey, nil]]

#define AGMakeError_Description_Reason(domain, errorCode, description, reason) \
	[NSError errorWithDomain:(domain) code:(errorCode) userInfo:[NSDictionary dictionaryWithObjectsAndKeys: \
	(description), NSLocalizedDescriptionKey, (reason), NSLocalizedFailureReasonErrorKey, nil]]

#define AGMakeError_Description_Reason_Suggestion(domain, errorCode, description, reason, recoverySuggestion) \
	[NSError errorWithDomain:(domain) code:(errorCode) userInfo:[NSDictionary dictionaryWithObjectsAndKeys: \
	(description), NSLocalizedDescriptionKey, (reason), NSLocalizedFailureReasonErrorKey, \
	(recoverySuggestion), NSLocalizedRecoverySuggestionErrorKey, nil]]


NSString * _Nonnull AGMakeStandardMacErrorString(NSString * _Nullable functionName, OSStatus errorCode);

NSError * _Nonnull AGWrapErrorWithDescription(NSError * _Nonnull error, NSString * _Nonnull description);

NSError * _Nonnull AGMakeErrorWithPOSIXError(int error);


@interface NSError (AraeliumAdditions)
- (NSError * _Nonnull)errorByAppendingUserInfo:(NSDictionary * _Nonnull)userInfo;
- (NSString * _Nonnull)localizedDescriptionFailureReasonAndSuggestion;

- (NSError * _Nullable)ag_underlyingError;
- (NSArray<NSError *> * _Nonnull)ag_underlyingErrors;
- (NSError * _Nullable)ag_underlyingErrorWithDomain:(NSString * _Nonnull)domain errorCode:(NSInteger)code;
@end


@interface AGNSErrorBuilder : NSObject
{
	NSString * _domain;
	NSInteger _code;
	NSDictionary * _userInfo;
	NSString * _localizedDescription;
	NSString * _localizedFailureReason;
	NSString * _localizedRecoverySuggestion;
	NSArray<NSString *> * _localizedRecoveryOptions;
	id _recoveryAttempter;
	NSError * _underlyingError;
	NSString * _helpAnchor;
	NSURL * _URL;
	NSString * _filePath;
}

@property (nonnull, readonly, nonatomic) NSError * error;

// Mutable properties
@property (nonnull, readwrite, copy) NSString * domain;
@property (readwrite) NSInteger code;
@property (nonnull, readwrite, copy) NSDictionary * userInfo;
@property (nonnull, readwrite, copy) NSString * localizedDescription;
@property (nullable, readwrite, copy) NSString * localizedFailureReason;
@property (nullable, readwrite, copy) NSString * localizedRecoverySuggestion;
@property (nullable, readwrite, copy) NSArray<NSString *> * localizedRecoveryOptions;
@property (nullable, readwrite, strong) id recoveryAttempter;
@property (nullable, readwrite, copy) NSError * underlyingError;
@property (nullable, readwrite, copy) NSString * helpAnchor;
@property (nullable, readwrite, copy) NSURL * URL;
@property (nullable, readwrite, copy) NSString * filePath;

- (void)appendUserInfo:(NSDictionary * _Nonnull)userInfo;


+ (instancetype _Nonnull)errorBuilder;
+ (NSError * _Nonnull)buildError:(void (^_Nonnull)(AGNSErrorBuilder * _Nonnull eb))block;
NSError * _Nonnull AGMakeError(void (^_Nonnull block)(AGNSErrorBuilder * _Nonnull eb));

@end

