//
//  AGGenerateProcessCoordinator.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 9/8/11.
//  Copyright 2011 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


// This function replicates a bit of a producer-consumer model where the generate
// block produces some type of result object, and the process block is given that
// object to do whatever it wants with it. The significant benefit to this function
// is that the processing of the previous result happens in parallel to the
// generation of the next result. Note that generation of the result N does not
// begin until result N-1 has been generated AND result N-2 has finished processing.
//     G:  1- 2--  3---- 4-
//     P:     1--- 2--   3--- 4--
void AGGenerateAndProcess(id (^generateBlock)(void), void (^processBlock)(id));

