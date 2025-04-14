//
//  AGKVOMutableDictionary.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 7/10/13.
//  Copyright (c) 2013 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


// This NSMutableDictionary subclass is designed to send KVO notifications
// when an object is added or removed. This class should raaaarely be used.
// It was added here to mimic the behavior of NSProgress's userInfo dict.

@interface AGKVOMutableDictionary : NSMutableDictionary
{
	NSMutableDictionary * _dictionary;
}

@end
