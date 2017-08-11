#import <substrate.h>
#import "ControlCenterUI.h"

@interface ControlCenterViewController : UIViewController <CCUIControlCenterPageContentProviding>

@property (nonatomic, assign) id <CCUIControlCenterPageContentViewControllerDelegate> delegate;
- (id)initWithNibName:(NSString*)nibName bundle:(NSBundle*)bundle;
@end