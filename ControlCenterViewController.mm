#import "ControlCenterViewController.h"

@implementation ControlCenterViewController
@synthesize delegate;
@dynamic view;
- (id)initWithNibName:(NSString*)nibName bundle:(NSBundle*)bundle {
  self = [super initWithNibName:nibName bundle:bundle];
  return self;
}

- (void)controlCenterDidFinishTransition {
}
- (void)controlCenterWillBeginTransition {
}
- (void)controlCenterDidDismiss {
}
- (void)controlCenterWillPresent {
}

- (void)loadView {
  // Load view here
}

@end