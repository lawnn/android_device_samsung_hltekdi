/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm8974.h"

// internal header...
#define ISMATCH(a, b) (!strncmp((a), (b), PROP_VALUE_MAX))

void cdma_properties(char const* cdma_sub, char const* op_numeric, char const* op_alpha)
{
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.cdma.home.operator.numeric", op_numeric);
    property_set("ro.cdma.home.operator.alpha", op_alpha);
    property_set("ro.telephony.default_cdma_sub", cdma_sub);
    property_set("ro.telephony.default_network", "10");
    property_set("ro.telephony.ril.config", "newDriverCallU,newDialCode");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void init_target_properties()
{
    char platform[PROP_VALUE_MAX];
    int rc;


    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;


        /* hltekdi */
        property_set("ro.build.fingerprint", "KDDI/SCL22/SCL22:5.0/LRX21V/SCL22KDU2GPG2:user/release-keys");
        property_set("ro.build.description", "hltekdi-user 5.0 LRX21V SCL22KDU2GPG2 release-keys");
        property_set("ro.product.model", "SCL22");
        property_set("ro.product.device", "SCL22");
        cdma_properties("1", "44054", "KDDI");

}
