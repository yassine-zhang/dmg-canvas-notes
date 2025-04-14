//
//  EnforceSubclassImplementations.h
//
//  Created by Seth Willits on 2/9/15.
//  Copyright (c) 2015. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
extern "C" {
#endif

void EnforceSubclassesImplement(Class klass, Protocol * protocol, BOOL deeply);
void EnforceSubclassImplementationsNow(void);

#ifdef __cplusplus
}
#endif
