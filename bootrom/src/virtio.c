#include <virtio.h>
#include <stddef.h>
#include <soc.h>

struct virtio_device* scan_mmio_virtio_device(void *addr) {
    return (struct virtio_device*)addr;
}

struct virtio_device_legacy* scan_mmio_legacy_virtio_device(void *addr) {
    return (struct virtio_device_legacy*)addr;
}