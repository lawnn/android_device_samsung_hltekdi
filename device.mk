#
# Copyright (C) 2011 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

## (2) Also get non-open-source specific aspects if available
$(call inherit-product-if-exists, vendor/samsung/hltekdi/hltekdi-vendor.mk)

## overlays
DEVICE_PACKAGE_OVERLAYS += device/samsung/hltekdi/overlay

## common overlays
DEVICE_PACKAGE_OVERLAYS += device/samsung/hlte-common/overlay-cdma

# AOJP Recovery
$(call inherit-product-if-exists, bootable/recovery/etc/aojp.mk)

# AOJP Common
$(call inherit-product-if-exists, vendor/aojp/config/aojp.mk)

# Local Path
LOCAL_PATH := device/samsung/hltekdi

# Init Files
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/rootdir/init.carrier.rc:root/init.carrier.rc

# Default Locale
PRODUCT_PROPERTY_OVERRIDES += \
    ro.product.locale.language=ja \
    ro.product.locale.region=JP

# Inherit from hlte-common
$(call inherit-product, device/samsung/hlte-common/hlte-common.mk)
