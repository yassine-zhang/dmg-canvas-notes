//
//  CALayerAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 10/12/14.
//  Copyright (c) 2014 Araelium Group. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CALayer (AraeliumAdditions)

//! Returns YES if @p layer is the receiver or a descendant layer of the receiver
- (BOOL)ag_layerTreeContainsLayer:(CALayer * _Nonnull)layer;

- (BOOL)ag_isDescendantOfLayer:(CALayer * _Nonnull)ancestor;

- (CALayer * _Nullable)ag_hitTest:(CGPoint)point;

@end
