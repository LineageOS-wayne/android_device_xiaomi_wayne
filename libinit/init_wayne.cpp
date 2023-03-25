/*
 * Copyright (C) 2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <fstream>

#include <libinit_utils.h>
#include "vendor_init.h"

void setup_model_properties() {
    std::ifstream cmdline("/proc/cmdline");
    std::string buf;

    while (std::getline(cmdline, buf, ' '))
        if (buf.find("hwversion") != std::string::npos)
            break;
    cmdline.close();

    if (buf.find("2.31.0") != std::string::npos)
        property_override("ro.product.model", "MI 6X MIKU");
}

void vendor_load_properties() {
    setup_model_properties();
}
