LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := server

include $(XASH3D_CONFIG)

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a-hard)
LOCAL_MODULE_FILENAME = libserver_hardfp
endif

LOCAL_CFLAGS += -ggdb

LOCAL_C_INCLUDES := $(LOCAL_PATH)/.

LOCAL_SRC_FILES := world.c \
	   pmove.c \
	   mathlib.c \
	   int.c \
	   util.c \
	   player.c \
	   client.c \
	   grenade.c

include $(BUILD_SHARED_LIBRARY)
