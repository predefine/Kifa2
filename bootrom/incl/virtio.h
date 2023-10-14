#include <stdint.h>

#ifndef VIRTIO_H
#define VIRTIO_H

enum device_status {
    ACKNOWLEDGE = 1,
    DRIVER = 2,
    FAILED = 128,
    FEATURES_OK = 8,
    DRIVER_OK = 4,
    DEVICE_NEEDS_RESET = 64
};

struct virtio_device
{
    const uint32_t magic;
    const uint32_t version;
    const uint32_t deviceid;
}; // Currently not used because qemu use legacy formatting, why? idk

struct virtio_device_legacy 
{
    const uint32_t magic;
    const uint32_t version;
    const uint32_t deviceid;
    const uint32_t vendorid;
    const uint32_t hostfeatures;
    uint32_t hostfeaturessel;
    const uint32_t ___res1[2];
    uint32_t guestfeatures;
    uint32_t guestfeaturessel;
    uint32_t guestpagesize;
    const uint32_t ___res2;
    uint32_t queuesel;
    const uint32_t queuenummax;
    uint32_t queuenum;
    uint32_t queuealign;
    volatile uint32_t queuepfn;
    const uint32_t ___res3[2];
    uint32_t queuenotify;
    const uint32_t ___res4[3];
    const uint32_t interruptstatus;
    uint32_t interruptack;
    const uint32_t ___res5[2];
    volatile uint32_t status;
    struct virtio_blk_config {
        int64_t capacity;               // le64 capacity
        int32_t size_max;              // le32 size_max
        int32_t seg_max;               // le32 seg_max
        
        struct virtio_blk_geometry {
            uint16_t cylinders;        // le16 cylinders
            uint8_t heads;             // u8 heads
            uint8_t sectors;           // u8 sectors
        } geometry;
        
        int32_t blk_size;              // le32 blk_size
        
        struct virtio_blk_topology {
            uint8_t physical_block_exp;  // u8 physical_block_exp
            uint8_t alignment_offset;    // u8 alignment_offset
            uint16_t min_io_size;       // le16 min_io_size
            int32_t opt_io_size;        // le32 opt_io_size
        } topology;
        
        uint8_t writeback;
        uint8_t unused0;
        uint16_t num_queues;
        int32_t max_discard_sectors;    // le32 max_discard_sectors
        int32_t max_discard_seg;        // le32 max_discard_seg
        int32_t discard_sector_alignment; // le32 discard_sector_alignment
        int32_t max_write_zeroes_sectors; // le32 max_write_zeroes_sectors
        int32_t max_write_zeroes_seg;     // le32 max_write_zeroes_seg
        uint8_t write_zeroes_may_unmap;
        uint8_t unused1[3];
        int32_t max_secure_erase_sectors; // le32 max_secure_erase_sectors
        int32_t max_secure_erase_seg;     // le32 max_secure_erase_seg
        int32_t secure_erase_sector_alignment; // le32 secure_erase_sector_alignment
    } config;
};




struct virtio_device* scan_mmio_virtio_device(void *addr);
struct virtio_device_legacy* scan_mmio_legacy_virtio_device(void *addr);
uint32_t legacy_virtio_begin_init(struct virtio_device_legacy* device);

#endif