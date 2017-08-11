include /opt/theos/makefiles/common.mk

TWEAK_NAME = ControlCenter
ControlCenter_FILES = Tweak.xm ControlCenterViewController.mm
ControlCenter_FRAMEWORKS = Foundation UIKit CoreGraphics QuartzCore SystemConfiguration

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 SpringBoard"
