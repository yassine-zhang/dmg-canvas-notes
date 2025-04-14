//
//  NSCharacterSetAdditions.h
//  NSCharacterSetAdditions
//
//  Created by Seth Willits on 2/16/22.
//  Copyright © 2022 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSCharacterSet (Additions)
@property (readonly, class, copy) NSCharacterSet * ag_hexadecimalCharacterSet;
@end

NS_ASSUME_NONNULL_END
