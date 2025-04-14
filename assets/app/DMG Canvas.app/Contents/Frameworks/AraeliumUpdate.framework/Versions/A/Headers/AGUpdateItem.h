//
//  AGUpdateItem.h
//  AraeliumUpdate
//
//  Created by Seth Willits on 5/29/19.
//  Copyright © 2019 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AraeliumUpdate/AGUpdateItemConditions.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AGUpdateItem <NSObject>

@property (readonly, copy) NSDate * date;
@property (readonly, copy) NSString * dateString;

@property (readonly, retain) AGUpdateItemConditions * conditions;

@end

NS_ASSUME_NONNULL_END
