//
//  NSObjectAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 1/19/16.
//  Copyright © 2016 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (AraeliumAdditions)

/// A description string containing the receiver's class, pointer, and a list of all property values.
- (NSString *)ag_descriptionUsingAllProperties;
- (NSString *)ag_descriptionUsingProperties:(NSSet *)propertyKeyPaths;



@end
