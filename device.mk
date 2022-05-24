#
# Copyright (C) 2018 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from wayne-common
$(call inherit-product, device/xiaomi/wayne-common/wayne.mk)

# Overlays
DEVICE_PACKAGE_OVERLAYS += \
    device/xiaomi/wayne/overlay

# Init
PRODUCT_PACKAGES += \
    fstab.qcom

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Wifi
PRODUCT_PACKAGES += \
    WayneWifiOverlay

# Inherit the proprietary files
$(call inherit-product, vendor/xiaomi/wayne/wayne-vendor.mk)
