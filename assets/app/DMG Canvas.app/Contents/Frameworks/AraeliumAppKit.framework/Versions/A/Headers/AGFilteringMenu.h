//
//  AGFilteringMenu.h
//  Created by Seth Willits on 2/23/23.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN
@class AGFilteringMenu;


extern const NSInteger AGFilteringMenuSearchItemTag;


@protocol AGFilteringMenuDelegate <NSMenuDelegate>
/// A nil string means no filter is being performed
- (void)filterItems:(NSArray<NSMenuItem*> *)items inMenu:(NSMenu *)menu forSearchString:(NSString * _Nullable)string;
@end


@interface AGFilteringMenu : NSMenu

- (instancetype)initWithTitle:(NSString *)title initiallyShowsSearch:(BOOL)initiallyShowsSearch;

/// The menu is its own delegate, but then forwards delegate methods to whatever is set using setDelegate: on self. Note that the delegate getter will always return self.
- (void)setDelegate:(id<AGFilteringMenuDelegate> _Nullable)delegate;
@end

NS_ASSUME_NONNULL_END
