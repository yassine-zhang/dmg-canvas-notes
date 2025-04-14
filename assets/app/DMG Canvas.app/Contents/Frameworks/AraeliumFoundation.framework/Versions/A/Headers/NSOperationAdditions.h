//
//  NSOperationAdditions.h
//  AraeliumFoundation4
//
//  Created by Seth Willits on 9/7/11.
//  Copyright 2011 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSOperation (CostAdditions)
- (void)setCost:(NSInteger)cost;
- (NSInteger)cost;
@end

