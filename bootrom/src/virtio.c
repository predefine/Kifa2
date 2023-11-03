#include <virtio.h>
#include <stddef.h>
#include <soc.h>
#include <panic.h>
#include <uart.h>

#define INIT_STATUS (ACKNOWLEDGE | DRIVER)

struct virtio_device* scan_mmio_virtio_device(void *addr) {
    return (struct virtio_device*)addr;
}

struct virtio_device_legacy* scan_mmio_legacy_virtio_device(void *addr) {
    return (struct virtio_device_legacy*)addr;
}

void legacy_virtio_set_status(struct virtio_device_legacy* device, uint32_t status) {
    device->status = status;
}

uint64_t read_device_features(struct virtio_device_legacy* device) {
    device->hostfeaturessel = 0;
    uint32_t device_features_bits_low = device->hostfeatures;
    device->hostfeaturessel = 1;
    uint32_t device_features_bits_high = device->hostfeatures;
    return ((uint64_t)device_features_bits_high << 32) | (uint64_t)device_features_bits_low;
}

uint32_t legacy_virtio_begin_init(struct virtio_device_legacy* device) {
    if(device->magic != 0x74726976) {
        panic("Invalid VirtIO device passed!");
    }
    
    if(device->deviceid != 2) {
        panic("Not a block device!");
    }

    if(device->version != 1) {
        panic("not a old layout!");
    }  

    // Reset
    legacy_virtio_set_status(device, 0);

    while (device->status != 0);

    // Set acknowledge bit
    legacy_virtio_set_status(device, device->status | ACKNOWLEDGE);

    puthex(device->status);

    // Set driver bit
    legacy_virtio_set_status(device, device->status | DRIVER);

    puthex(device->status);

    if(device->status & DEVICE_NEEDS_RESET || device->status != (ACKNOWLEDGE | DRIVER)) {
        panic("Something went wrong with init");
    }

    return 0;
}