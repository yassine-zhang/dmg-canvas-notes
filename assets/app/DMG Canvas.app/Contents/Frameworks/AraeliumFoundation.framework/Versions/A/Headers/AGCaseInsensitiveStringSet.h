//
//  AGCaseInsensitiveStringSet.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 3/3/23.
//  Copyright © 2023 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AGCaseInsensitiveStringSet : NSObject

- (instancetype)initWithStrings:(NSArray<NSString*> *)strings;
- (BOOL)containsString:(NSString *)string;

@property (readonly) NSArray<NSString*> * allStrings;

@end

NS_ASSUME_NONNULL_END
