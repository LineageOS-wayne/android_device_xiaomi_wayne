#
# Copyright (C) 2018 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from wayne-common
include device/xiaomi/wayne-common/BoardConfigCommon.mk

DEVICE_PATH := device/xiaomi/wayne

# Init
TARGET_INIT_VENDOR_LIB := //$(DEVICE_PATH):init_wayne
TARGET_RECOVERY_DEVICE_MODULES := init_wayne

# Recovery
TARGET_RECOVERY_FSTAB := $(DEVICE_PATH)/rootdir/etc/fstab.qcom

# Security patch level
VENDOR_SECURITY_PATCH := 2018-11-01

# Inherit the proprietary files
include vendor/xiaomi/wayne/BoardConfigVendor.mk
