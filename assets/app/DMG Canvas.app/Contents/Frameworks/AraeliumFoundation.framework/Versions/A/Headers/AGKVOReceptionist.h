//
//  AGKVOReceptionist.h
//  AGAutocomplete
//
//  Created by Seth Willits on 2/28/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef void (^KVOReceptionistBlock)(NSString *keyPath, id object, NSDictionary *change);

@interface AGKVOReceptionist : NSObject
{
	id _observedObject;
	NSString * _observedKeyPath;
	KVOReceptionistBlock _handler;
	BOOL _cancelled;
}


+ (instancetype)receptionistForKeyPath:(NSString *)keyPath object:(id)obj handler:(KVOReceptionistBlock)block;
- (void)cancel;

@property (nonatomic, readonly, getter=isCancelled) BOOL cancelled;

@end
