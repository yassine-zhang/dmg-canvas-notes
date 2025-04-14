//
//  AGUpdateSystemProfile.h
//  AGUpdate
//
//	Identical to AGFeedbackSystemProfile
//	in AraeliumFeedback.
//
//  Created by Seth Willits on 9/20/11.
//  Copyright 2011 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface AGUpdateSystemProfile : NSObject

+ (AGUpdateSystemProfile *)systemProfile;
- (NSString *)stringValue;
- (NSDictionary *)JSONDictionary;


// OS
@property (readonly) NSString *  OSVersion;
@property (readonly) NSString *  OSBuild;
@property (readonly) NSString *  language;

// Machine
@property (readonly) NSString *  machineName;
@property (readonly) NSString *  machineModel;
@property (readonly) BOOL        isAppleSilicon;
@property (readonly) BOOL        is64bit;
@property (readonly) NSString *  CPUFamily; // i5, i7, i9, Xeon, M1 ...
@property (readonly) NSString *  CPUType;  // Name (Quad-Core Intel i7)
@property (readonly) NSUInteger  CPUCount; // On Apple Silicon, unreliable values.
@property (readonly) NSUInteger  CPUSpeed; // On Apple Silicon, unreliable values.
@property (readonly) NSUInteger  RAM;

// Graphics
@property (readonly) NSString *  GPUType;
@property (readonly) NSUInteger  VRAM;
@property (readonly) NSUInteger  numberOfDisplays;
@property (readonly) NSString *  resolutions;


// Avoid gathering *everything*
+ (NSString *)CPUBrandString;
+ (NSString *)CPUFamily;

@end
