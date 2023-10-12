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

enum BlkFeature {
    BARRIER = (1ULL << 0),             // Device supports request barriers. (legacy)
    SIZE_MAX = (1ULL << 1),            // Maximum size of any single segment is in `size_max`.
    SEG_MAX = (1ULL << 2),             // Maximum number of segments in a request is in `seg_max`.
    GEOMETRY = (1ULL << 4),            // Disk-style geometry specified in geometry.
    RO = (1ULL << 5),                  // Device is read-only.
    BLK_SIZE = (1ULL << 6),            // Block size of the disk is in `blk_size`.
    SCSI = (1ULL << 7),                // Device supports SCSI packet commands. (legacy)
    FLUSH = (1ULL << 9),               // Cache flush command support.
    TOPOLOGY = (1ULL << 10),           // Device exports information on optimal I/O alignment.
    CONFIG_WCE = (1ULL << 11),         // Device can toggle its cache between writeback and writethrough modes.
    MQ = (1ULL << 12),                 // Device supports multiqueue.
    DISCARD = (1ULL << 13),            // Device can support the discard command.
    WRITE_ZEROES = (1ULL << 14),       // Device can support the write zeroes command.
    LIFETIME = (1ULL << 15),           // Device supports providing storage lifetime information.
    SECURE_ERASE = (1ULL << 16),       // Device can support the secure erase command.
    NOTIFY_ON_EMPTY = (1ULL << 24),    // Device independent (legacy).
    ANY_LAYOUT = (1ULL << 27),         // Device independent (legacy).
    RING_INDIRECT_DESC = (1ULL << 28), // Device independent.
    RING_EVENT_IDX = (1ULL << 29),     // Device independent.
    UNUSED = (1ULL << 30),             // Device independent (legacy).
    VERSION_1 = (1ULL << 32),          // Device independent (detect legacy).
    ACCESS_PLATFORM = (1ULL << 33),    // Since virtio v1.1.
    RING_PACKED = (1ULL << 34),        // Since virtio v1.1.
    IN_ORDER = (1ULL << 35),           // Since virtio v1.1.
    ORDER_PLATFORM = (1ULL << 36),     // Since virtio v1.1.
    SR_IOV = (1ULL << 37),             // Since virtio v1.1.
    NOTIFICATION_DATA = (1ULL << 38)   // Since virtio v1.1.
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
    const uint32_t hostfeaturessel;
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
    uint32_t status;
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

#endif