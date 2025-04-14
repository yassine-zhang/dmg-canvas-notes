//
//  NSMenuAdditions.h
//  AraeliumAppKit
//
//  Created by Seth Willits on 3/9/13.
//  Copyright (c) 2013 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>



NSMenuItem * NSMenuItemWith(NSString * title, id target, SEL action, NSString * keyEquiv, id representedObject, NSInteger state);


@interface NSMenu (AraeliumAdditions)
- (void)removeExtraSeparatorItems;
- (NSMenuItem *)ag_firstItemWithAction:(SEL)selector;
- (NSMenuItem *)ag_addSubmenuWithTitle:(NSString *)title block:(void (^)(NSMenu * submenu))block;
- (NSMenuItem *)ag_insertSubmenuWithTitle:(NSString *)title atIndex:(NSUInteger)index block:(void (^)(NSMenu * submenu))block;
- (void)ag_turnOffAllMenuItems;
@end


@interface NSMenuItem (AraeliumAdditions)
- (void)ag_addSubmenu:(void (^)(NSMenu * submenu))block;
@end

