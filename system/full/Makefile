BUILD_DIR = ../build
TARGET_DIR = $(BUILD_DIR)/rootfs
ROOT_DIR = .

all: mkdirs extra_libs extra_driver extra_bin x_sbin x_bin
	@echo "all done."

mkdirs:
	@mkdir -p ${TARGET_DIR}/$(ROOT_DIR)/sbin/x
	@mkdir -p ${TARGET_DIR}/$(ROOT_DIR)/bin/x
	@cp -r ${ROOT_DIR}/etc ${TARGET_DIR}/$(ROOT_DIR)
	@cp -r ${ROOT_DIR}/data ${TARGET_DIR}/$(ROOT_DIR)

EXTRA_LIBS_DIR=libs
EXTRA_LIBXX_DIR=libs/cxx
extra_libs:
	cd $(EXTRA_LIBS_DIR)/graph; make
	cd $(EXTRA_LIBS_DIR)/fonts; make
	cd $(EXTRA_LIBS_DIR)/fb; make
	cd $(EXTRA_LIBS_DIR)/console; make
	cd $(EXTRA_LIBS_DIR)/upng; make
	cd $(EXTRA_LIBS_DIR)/sconf; make
	cd $(EXTRA_LIBS_DIR)/tiny-json; make
	cd $(EXTRA_LIBS_DIR)/x; make
	cd $(EXTRA_LIBXX_DIR)/cxx; make
	cd $(EXTRA_LIBXX_DIR)/graphxx; make
	cd $(EXTRA_LIBXX_DIR)/x++; make

EXTRA_BIN_DIR=bin
extra_bin:
	cd $(EXTRA_BIN_DIR)/grep;make
	cd $(EXTRA_BIN_DIR)/fbtool;make

X_DIR=x
x_bin:
	cd $(X_DIR)/bin/gtest;make
	cd $(X_DIR)/bin/launcher;make
	cd $(X_DIR)/bin/xconsole;make

x_sbin:
	cd $(X_DIR)/sbin/xmouse;make
	cd $(X_DIR)/sbin/xjoystick;make
	cd $(X_DIR)/sbin/xtouch;make
	cd $(X_DIR)/sbin/xim/none;make
	cd $(X_DIR)/sbin/xim/vkey;make
	cd $(X_DIR)/sbin/xwm/macos7;make

EXTRA_DRIVERS_DIR=drivers
extra_driver:
	cd $(EXTRA_DRIVERS_DIR)/consoled;make
	cd $(EXTRA_DRIVERS_DIR)/xserverd;make

clean:
	cd $(EXTRA_LIBS_DIR)/graph; make clean
	cd $(EXTRA_LIBS_DIR)/fb; make clean
	cd $(EXTRA_LIBS_DIR)/console; make clean
	cd $(EXTRA_LIBS_DIR)/fonts; make clean
	cd $(EXTRA_LIBS_DIR)/x; make clean
	cd $(EXTRA_LIBS_DIR)/upng; make clean
	cd $(EXTRA_LIBS_DIR)/sconf; make clean
	cd $(EXTRA_LIBS_DIR)/tiny-json; make clean
	cd $(EXTRA_LIBXX_DIR)/cxx; make clean
	cd $(EXTRA_LIBXX_DIR)/graphxx; make clean
	cd $(EXTRA_LIBXX_DIR)/x++; make clean
	cd $(EXTRA_DRIVERS_DIR)/consoled;make clean
	cd $(EXTRA_DRIVERS_DIR)/xserverd;make clean
	cd $(X_DIR)/sbin/xmouse;make clean
	cd $(X_DIR)/sbin/xjoystick;make clean
	cd $(X_DIR)/sbin/xtouch;make clean
	cd $(X_DIR)/sbin/xim/none;make clean
	cd $(X_DIR)/sbin/xim/vkey;make clean
	cd $(X_DIR)/sbin/xwm/macos7;make clean
	cd $(X_DIR)/bin/gtest;make clean
	cd $(X_DIR)/bin/launcher;make clean
	cd $(X_DIR)/bin/xconsole;make clean
	cd $(EXTRA_BIN_DIR)/grep;make clean
	cd $(EXTRA_BIN_DIR)/fbtool;make clean
