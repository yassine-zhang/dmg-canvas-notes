//
//  NSURLComponentAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 3/17/19.
//  Copyright © 2019 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURLComponents (Additions)

- (NSURLQueryItem * _Nullable)queryItemWithName:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
