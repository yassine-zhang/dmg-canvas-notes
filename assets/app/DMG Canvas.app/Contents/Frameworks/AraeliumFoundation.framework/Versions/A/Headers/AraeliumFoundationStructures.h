//
//  AraeliumFoundationStructures.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 5/21/09.
//  Copyright 2009 Araelium Group. All rights reserved.
//

#ifndef __AraeliumFoundationStructures_h
#define __AraeliumFoundationStructures_h


#define QGLOBAL	dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)
#define QMAIN	dispatch_get_main_queue()
#define dispatch_after_s(secs, queue, block) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, secs * NSEC_PER_SEC), queue, block)



#define NSARY(...)    [NSArray arrayWithObjects:__VA_ARGS__]
#define NSMARY(...)   [NSMutableArray arrayWithObjects:__VA_ARGS__]
#define NSSTRF(...)   [NSString stringWithFormat:__VA_ARGS__]


// NSDICT, NSMDICT provide a literal-like syntax for  creating an NS[Mutable]Dictionary,
// while accepting nil values. Where a value is nil, no object
// is set in the dictionary for that given key.

#define NSDICT_(firstKey, ...) NSDictionaryWithKeysAndValues(firstKey, __VA_ARGS__)
#define NSMDICT_(firstKey, ...) NSMutableDictionaryWithKeysAndValues(firstKey, __VA_ARGS__)

__attribute__ ((sentinel)) NSMutableDictionary * NSMutableDictionaryWithKeysAndValues(id firstKey, ...);
__attribute__ ((sentinel)) NSDictionary * NSDictionaryWithKeysAndValues(id firstKey, ...);



#define NSRECT(x)     [NSValue valueWithRect:x]
#define NSSIZE(x)     [NSValue valueWithSize:x]

//#define NSARCHIVE(x)  [NSKeyedArchiver archivedDataWithRootObject:x]
//#define NSUNARCHIVE(x) [NSKeyedUnarchiver unarchiveObjectWithData:x]


#define NSFIRST(...) _NSFIRST(nil, __VA_ARGS__, [NSNull null])
id _NSFIRST(id ignore, ...);

#define NSObjectsEqual(a, b) ((a != nil && b != nil && [a isEqual:b]) || (a == nil && b == nil))

/// -hash implementation convenience.
/*	- (NSUInteger)hash
	{
		NSUInteger hash = 0;
		hash = NSHashRotate(hash, property.hash);
		hash = NSHashRotate(hash, property.hash);
		return hash;
	}
*/
#define NSUINT_BIT (CHAR_BIT * sizeof(NSUInteger))
#define NSUINTROTATE(val, howmuch) ((((NSUInteger)val) << howmuch) | (((NSUInteger)val) >> (NSUINT_BIT - howmuch)))
#define NSHashRotate(hash, val) (hash ^ NSUINTROTATE(val, 2))

#define IS_FLAG_SET(a, b)    (((a) & (b)) == (b))
#define IS_FLAG_CLEAR(a, b)  (((a) & (b)) == 0)

//#define IS_FLAG_SET(a, b) \
//	({ typeof(a) _a = a; \
//	   typeof(a) _b = b; \
//	   ((_a & _b) == _b); \
//	})



void __AllowOnceEvery(double seconds, void (^block)(void), NSTimeInterval * lastTime);

#define AllowOnceEvery(seconds, block) \
		do {\
			static NSTimeInterval lastTime = 0;\
			__AllowOnceEvery(seconds, block, &lastTime);\
		} while (0)


#endif
