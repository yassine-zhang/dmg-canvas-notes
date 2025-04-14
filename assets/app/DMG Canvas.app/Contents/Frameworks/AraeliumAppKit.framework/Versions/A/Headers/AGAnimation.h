//
//  AGAnimation.h
//  Keypose
//
//  Created by Seth Willits on 2/12/08.
//  Copyright 2008 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>




double AGCubicBezierCurve(double x1, double y1, double x2, double y2, double t);
double AGEaseInOut(double t);
double AGEaseIn(double t);
double AGEaseOut(double t);
double AGEaseCurve(double t);












@interface AGAnimation : NSAnimation {
	#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_5
	void (^mProgressBlock)(NSAnimationProgress);
	void (^mFinishedBlock)(void);
	#endif
}

#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_5
- (void)startAnimation:(void (^)(NSAnimationProgress progress))progressBlock finished:(void (^)(void))finishedBlock;
#endif

@end


@protocol AGAnimationDelegate <NSObject>
- (void)animation:(NSAnimation *)animation didSetCurrentProgress:(NSAnimationProgress)progress;
@end







@interface AGViewAnimation : NSViewAnimation {
	void (^mProgressBlock)(NSAnimationProgress);
	void (^mFinishedBlock)(void);
}

- (void)startAnimation:(void (^)(NSAnimationProgress progress))progressBlock finished:(void (^)(void))finishedBlock;

@end

@protocol AGViewAnimationDelegate <NSObject>
- (void)animation:(NSAnimation *)animation didSetCurrentProgress:(NSAnimationProgress)progress;
@end
