#include <UIKit/UIKit.h>

@interface CCUIControlCenterViewController : UIViewController

- (void)_addContentViewController:(UIViewController*)arg1;
//- (void)_removeContentViewController:(UIViewController*)arg1;
- (void)_loadPages;
- (id)contentViewControllers;
- (void)_updatePageControl;
- (void)_updateScrollViewContentSize;
- (void)_layoutScrollView;
- (void)controlCenterWillPresent;
- (void)_addOrRemovePagesBasedOnVisibility;
- (void)scrollToPage:(unsigned long long)arg1 animated:(BOOL)arg2 withCompletion:(void(^)(BOOL))completion;

@end

@protocol CCUIControlCenterObserver
- (void)controlCenterDidFinishTransition;
- (void)controlCenterWillBeginTransition;
- (void)controlCenterDidDismiss;
- (void)controlCenterWillPresent;

@optional
- (void)controlCenterWillFinishTransitionOpen:(BOOL)arg1 withDuration:(NSTimeInterval)arg2;
@end

@class CCUIControlCenterContainerView;
@protocol CCUIControlCenterSystemAgent;

@protocol CCUIControlCenterPageContentProviding, CCUIControlCenterSystemAgent;

@protocol CCUIControlCenterPageContentViewControllerDelegate
- (void)endSuppressingPunchOutMaskCachingForReason:(NSString *)arg1;
- (void)beginSuppressingPunchOutMaskCachingForReason:(NSString *)arg1;
- (void)visibilityPreferenceChangedForContentViewController:(UIViewController<CCUIControlCenterPageContentProviding> *)arg1;
- (long long)layoutStyle;
- (id <CCUIControlCenterSystemAgent>)controlCenterSystemAgent;
- (void)contentViewControllerWantsDismissal:(UIViewController<CCUIControlCenterPageContentProviding> *)arg1;
@end


@protocol CCUIControlCenterPageContentProviding <CCUIControlCenterObserver>
@property (nonatomic, assign) id <CCUIControlCenterPageContentViewControllerDelegate> delegate;
@end

@interface CCUIControlCenterPagePlatterView : UIView
@property(retain, nonatomic) UIView *contentView;
@end


@interface CCUIControlCenterPageContainerViewController : UIViewController
@property(readonly, nonatomic) UIViewController<CCUIControlCenterPageContentProviding> *contentViewController;
@end


@protocol CCUIControlCenterContainerViewDelegate <NSObject>
- (id <CCUIControlCenterSystemAgent>)controlCenterSystemAgent;
- (struct UIEdgeInsets)pageInsetForContainerView:(CCUIControlCenterContainerView *)arg1;
- (struct UIEdgeInsets)marginInsetForContainerView:(CCUIControlCenterContainerView *)arg1;
- (UIPageControl *)pageControlForContainerView:(CCUIControlCenterContainerView *)arg1;
- (UIScrollView *)scrollViewForContainerView:(CCUIControlCenterContainerView *)arg1;
- (NSArray *)pagePlatterViewsForContainerView:(CCUIControlCenterContainerView *)arg1;
- (double)contentHeightForContainerView:(CCUIControlCenterContainerView *)arg1;
@end


@interface CCUIControlCenterContainerView : UIView
@property (nonatomic, assign) id <CCUIControlCenterContainerViewDelegate> delegate;
@end
