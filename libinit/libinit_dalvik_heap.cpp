/*
 * Copyright (C) 2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <sys/sysinfo.h>

#include <libinit_dalvik_heap.h>
#include <libinit_utils.h>

#define GB(b) (b * 1024ull * 1024 * 1024)

static const dalvik_heap_info_t dalvik_heap_info_6144 = {
    .heapstartsize = "16m",
    .heapgrowthlimit = "256m",
    .heapsize = "512m",
    .heapminfree = "8m",
    .heapmaxfree = "32m",
    .heaptargetutilization = "0.5",
};

static const dalvik_heap_info_t dalvik_heap_info_4096 = {
    .heapstartsize = "8m",
    .heapgrowthlimit = "256m",
    .heapsize = "512m",
    .heapminfree = "8m",
    .heapmaxfree = "16m",
    .heaptargetutilization = "0.6",
};

static const dalvik_heap_info_t dalvik_heap_info_2048 = {
    .heapstartsize = "8m",
    .heapgrowthlimit = "192m",
    .heapsize = "512m",
    .heapminfree = "512k",
    .heapmaxfree = "8m",
    .heaptargetutilization = "0.75",
};

void set_dalvik_heap() {
    struct sysinfo sys;
    const dalvik_heap_info_t *dhi;

    sysinfo(&sys);

    if (sys.totalram > GB(5))
        dhi = &dalvik_heap_info_6144;
    else if (sys.totalram > GB(3))
        dhi = &dalvik_heap_info_4096;
    else
        dhi = &dalvik_heap_info_2048;

    property_override("dalvik.vm.heapstartsize", dhi->heapstartsize);
    property_override("dalvik.vm.heapgrowthlimit", dhi->heapgrowthlimit);
    property_override("dalvik.vm.heapsize", dhi->heapsize);
    property_override("dalvik.vm.heapminfree", dhi->heaptargetutilization);
    property_override("dalvik.vm.heapmaxfree", dhi->heapminfree);
    property_override("dalvik.vm.heaptargetutilization", dhi->heapmaxfree);
}
