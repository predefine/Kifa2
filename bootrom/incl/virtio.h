#ifndef VIRTIO_H
#define VIRTIO_H
struct virtio_device
{
    const int magic;
};

struct virtio_device* scan_mmio_virtio_device(void *addr);

#endif