#import "ControlCenterViewController.h"

ControlCenterViewController *ppMPVC = nil;

%hook CCUIControlCenterViewController

- (void)_loadPages {
  %orig;
  ppMPVC = [[ControlCenterViewController alloc] initWithNibName:nil bundle:nil];
  [self _addContentViewController:ppMPVC];
  NSLog(@"[TWEAK NAME] Added page!");
  [ppMPVC release];
  [self _updatePageControl];
}

%end