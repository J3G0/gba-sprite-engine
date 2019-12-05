
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "gtest/gtest.h"

#include <bitset>

const u32 kul_data [] = {
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x01, 0x01, 0x03, 0x04, 0x04, 0x04, 0x04, 0x04, 0x01, 0x01, 0x05, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x07, 0x08,
        0x01, 0x01, 0x05, 0x06, 0x06, 0x09, 0x08, 0x0A, 0x01, 0x01, 0x05, 0x06,
        0x06, 0x09, 0x0B, 0x0A, 0x01, 0x01, 0x05, 0x06, 0x06, 0x09, 0x0B, 0x0A,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0B, 0x06, 0x06, 0x08,
        0x0B, 0x0C, 0x0B, 0x0D, 0x0E, 0x0F, 0x10, 0x0A, 0x11, 0x12, 0x0A, 0x13,
        0x14, 0x15, 0x0A, 0x16, 0x15, 0x15, 0x0A, 0x17, 0x18, 0x13, 0x0A, 0x19,
        0x1A, 0x1B, 0x0A, 0x17, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x1C, 0x0B, 0x0D, 0x06, 0x06, 0x1C, 0x0B, 0x1C, 0x1D, 0x0A, 0x1E,
        0x0B, 0x1F, 0x1D, 0x0A, 0x1C, 0x20, 0x21, 0x22, 0x0B, 0x1F, 0x23, 0x24,
        0x1C, 0x20, 0x21, 0x22, 0x0B, 0x1F, 0x23, 0x24, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x0D, 0x06, 0x06, 0x06, 0x0D, 0x0B, 0x0B, 0x0B,
        0x11, 0x0D, 0x06, 0x1F, 0x11, 0x0A, 0x0A, 0x0A, 0x17, 0x0D, 0x06, 0x25,
        0x1E, 0x0A, 0x0A, 0x0A, 0x17, 0x0D, 0x06, 0x25, 0x1E, 0x0A, 0x26, 0x27,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0B, 0x0B, 0x28, 0x0B,
        0x28, 0x06, 0x28, 0x0B, 0x0A, 0x18, 0x10, 0x0A, 0x26, 0x06, 0x29, 0x0A,
        0x0A, 0x2A, 0x26, 0x0A, 0x2B, 0x06, 0x26, 0x0A, 0x27, 0x27, 0x2C, 0x0A,
        0x2B, 0x06, 0x26, 0x0A, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x0C, 0x08, 0x0C, 0x06, 0x2D, 0x0C, 0x0B, 0x0B, 0x2E, 0x0A, 0x2F, 0x0B,
        0x27, 0x0A, 0x30, 0x31, 0x32, 0x33, 0x16, 0x34, 0x35, 0x0A, 0x36, 0x19,
        0x37, 0x29, 0x38, 0x39, 0x1D, 0x0A, 0x2C, 0x2B, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x08, 0x0B, 0x0B, 0x08, 0x28, 0x0D, 0x08, 0x1C,
        0x0A, 0x0A, 0x0A, 0x0A, 0x3A, 0x3B, 0x0A, 0x1E, 0x0A, 0x0A, 0x0A, 0x0A,
        0x3A, 0x11, 0x0A, 0x0A, 0x0A, 0x3C, 0x34, 0x3D, 0x0D, 0x22, 0x0A, 0x0A,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x28, 0x0B, 0x1C,
        0x06, 0x06, 0x06, 0x06, 0x1C, 0x37, 0x0A, 0x3E, 0x06, 0x06, 0x06, 0x06,
        0x0B, 0x19, 0x0A, 0x3F, 0x06, 0x06, 0x06, 0x06, 0x39, 0x37, 0x0A, 0x3F,
        0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06, 0x06, 0x09, 0x0B, 0x0A,
        0x01, 0x01, 0x05, 0x06, 0x06, 0x09, 0x0B, 0x0A, 0x01, 0x01, 0x05, 0x06,
        0x06, 0x09, 0x0B, 0x0A, 0x01, 0x01, 0x05, 0x06, 0x06, 0x09, 0x0B, 0x0A,
        0x01, 0x01, 0x05, 0x06, 0x06, 0x09, 0x0B, 0x0A, 0x01, 0x01, 0x05, 0x06,
        0x06, 0x09, 0x0B, 0x0A, 0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x1C, 0x3E,
        0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0A, 0x0A, 0x30, 0x40,
        0x1F, 0x1B, 0x0A, 0x17, 0x0A, 0x0A, 0x18, 0x39, 0x41, 0x1B, 0x0A, 0x17,
        0x0A, 0x21, 0x0A, 0x13, 0x06, 0x42, 0x0A, 0x17, 0x30, 0x23, 0x0A, 0x18,
        0x23, 0x3D, 0x38, 0x31, 0x30, 0x43, 0x44, 0x0A, 0x32, 0x27, 0x30, 0x0A,
        0x45, 0x1C, 0x27, 0x0A, 0x16, 0x20, 0x46, 0x0A, 0x1B, 0x2D, 0x28, 0x35,
        0x39, 0x34, 0x2D, 0x1B, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x1C, 0x20, 0x21, 0x22, 0x0B, 0x1F, 0x23, 0x24, 0x1C, 0x20, 0x21, 0x22,
        0x0B, 0x1F, 0x23, 0x24, 0x1C, 0x20, 0x21, 0x22, 0x0B, 0x1F, 0x23, 0x24,
        0x08, 0x12, 0x0A, 0x37, 0x0D, 0x1F, 0x23, 0x24, 0x47, 0x2A, 0x0A, 0x2B,
        0x06, 0x25, 0x23, 0x18, 0x0A, 0x0A, 0x0E, 0x27, 0x48, 0x48, 0x23, 0x18,
        0x10, 0x49, 0x43, 0x06, 0x06, 0x09, 0x08, 0x23, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x17, 0x0D, 0x06, 0x25, 0x1E, 0x0A, 0x11, 0x37,
        0x17, 0x0D, 0x06, 0x25, 0x1E, 0x0A, 0x0A, 0x0A, 0x17, 0x0D, 0x06, 0x25,
        0x1E, 0x0A, 0x30, 0x1E, 0x1E, 0x0B, 0x06, 0x48, 0x1E, 0x0A, 0x23, 0x06,
        0x0A, 0x21, 0x0A, 0x2C, 0x11, 0x0A, 0x38, 0x21, 0x0A, 0x0A, 0x0A, 0x3C,
        0x11, 0x0A, 0x0A, 0x0A, 0x1D, 0x1D, 0x1D, 0x4A, 0x15, 0x1D, 0x1D, 0x1D,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x37, 0x1B, 0x2C, 0x0A,
        0x2B, 0x06, 0x26, 0x0A, 0x0A, 0x46, 0x2C, 0x0A, 0x2B, 0x06, 0x26, 0x0A,
        0x1E, 0x20, 0x2C, 0x0A, 0x46, 0x06, 0x10, 0x0A, 0x06, 0x2D, 0x26, 0x0A,
        0x22, 0x1C, 0x36, 0x0A, 0x21, 0x4B, 0x27, 0x0A, 0x0A, 0x2E, 0x0A, 0x18,
        0x0A, 0x0A, 0x1F, 0x16, 0x0A, 0x0A, 0x0A, 0x30, 0x1D, 0x1D, 0x48, 0x0D,
        0x4C, 0x10, 0x3E, 0x0D, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x19, 0x23, 0x0A, 0x32, 0x26, 0x0A, 0x39, 0x46, 0x10, 0x4D, 0x0A, 0x47,
        0x1E, 0x2F, 0x4A, 0x26, 0x10, 0x08, 0x2A, 0x0A, 0x0A, 0x13, 0x0B, 0x10,
        0x46, 0x28, 0x1E, 0x0A, 0x0A, 0x37, 0x48, 0x29, 0x1B, 0x1C, 0x3C, 0x0A,
        0x0A, 0x26, 0x41, 0x29, 0x09, 0x09, 0x20, 0x0A, 0x16, 0x23, 0x25, 0x2C,
        0x09, 0x09, 0x0B, 0x39, 0x1B, 0x0D, 0x09, 0x34, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x0A, 0x2E, 0x19, 0x22, 0x43, 0x37, 0x0A, 0x0A,
        0x0A, 0x0A, 0x0A, 0x0A, 0x23, 0x37, 0x0A, 0x0E, 0x0A, 0x45, 0x17, 0x31,
        0x34, 0x37, 0x0A, 0x2B, 0x0A, 0x39, 0x41, 0x09, 0x41, 0x37, 0x0A, 0x34,
        0x0A, 0x0A, 0x24, 0x0A, 0x37, 0x31, 0x0A, 0x4E, 0x0A, 0x0A, 0x0A, 0x0A,
        0x36, 0x4F, 0x0A, 0x15, 0x39, 0x1D, 0x1D, 0x1D, 0x3D, 0x15, 0x39, 0x0B,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x2E, 0x17, 0x0A, 0x3F,
        0x06, 0x06, 0x06, 0x06, 0x0A, 0x30, 0x0A, 0x3F, 0x06, 0x06, 0x06, 0x06,
        0x0E, 0x0A, 0x0A, 0x20, 0x06, 0x06, 0x06, 0x06, 0x31, 0x0A, 0x0A, 0x20,
        0x06, 0x06, 0x06, 0x06, 0x3E, 0x4B, 0x0A, 0x20, 0x06, 0x06, 0x06, 0x06,
        0x2D, 0x2F, 0x0A, 0x3F, 0x06, 0x06, 0x06, 0x06, 0x48, 0x15, 0x3E, 0x0F,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x01, 0x01, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x05, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
};

class SpriteWithStubOam : public Sprite {
public:
    SpriteWithStubOam(SpriteSize size) : Sprite(nullptr, imageSize, x, y, startX, startY, size) {
        oam = std::unique_ptr<OBJ_ATTR>(new OBJ_ATTR());
    }

    OBJ_ATTR* buildOamForTesting(int tileIndex = 0) {
        buildOam(tileIndex);
        return oam.get();
    }

};

class SpriteSuite : public ::testing::Test {
protected:
    SpriteWithStubOam *s;

    virtual void TearDown() {
        delete s;
    }

    virtual void SetUp() {
        s = new SpriteWithStubOam(SIZE_8_8);
    }
};

TEST_F(SpriteSuite, Sync_Animation_Updates_OAM_To_Next_Frame) {
    s = new SpriteWithStubOam(SIZE_16_32);
    s->makeAnimated(2, 0);
    auto oam = s->buildOamForTesting(208); // should start at 224 (11100000) after a frame update
    s->update();

    auto attr2 = std::bitset<16>(oam->attr2).to_string();

    ASSERT_EQ(std::string("0000000011100000"), attr2);
}


TEST_F(SpriteSuite, Animated_Sprite_Increases_Current_Frame_After_Delay) {
    s->makeAnimated(2, 5);

    ASSERT_EQ(0, s->getCurrentFrame());
    s->update();                     // 1 times
    ASSERT_EQ(0, s->getCurrentFrame());
    for(int i = 1; i <= 4; i++) {   // 4 times
        s->update();
    }
    ASSERT_EQ(0, s->getCurrentFrame());
    s->update();                    // 5th time
    ASSERT_EQ(1, s->getCurrentFrame());
}

TEST_F(SpriteSuite, Animated_Sprite_Resets_Current_Frame_After_Hitting_Max) {
    s->makeAnimated(2, 0);
    s->update();
    ASSERT_EQ(1, s->getCurrentFrame());
    s->update();
    ASSERT_EQ(0, s->getCurrentFrame());
}

TEST_F(SpriteSuite, CollidesWith_B_Right_Of_A_Does_Not_Collide) {
    auto a = SpriteBuilder<Sprite>().withLocation(10, 10).withSize(SIZE_16_16).buildPtr();
    auto b = SpriteBuilder<Sprite>().withLocation(40, 10).withSize(SIZE_16_16).buildPtr();

    ASSERT_FALSE(a->collidesWith(*b));
}

TEST_F(SpriteSuite, CollidesWith_B_Half_In_A_On_X_Axis_Collides) {
    auto a = SpriteBuilder<Sprite>().withLocation(10, 10).withSize(SIZE_16_16).buildPtr();
    auto b = SpriteBuilder<Sprite>().withLocation(20, 10).withSize(SIZE_16_16).buildPtr();

    ASSERT_TRUE(a->collidesWith(*b));
}

TEST_F(SpriteSuite, MovesToNegativeCoordsAreMaskedIntoOAM) {
    s->moveTo(-10, -15);
    auto oam = s->buildOamForTesting();
    auto attr0 = std::bitset<16>(oam->attr0).to_string();
    auto attr1 = std::bitset<16>(oam->attr1).to_string();

    ASSERT_EQ(std::string("0000000011110001"), attr0);
    ASSERT_EQ(std::string("0000000111110110"), attr1);
}

TEST_F(SpriteSuite, BuildingWithSize_SetsWidthAndHeight) {
    auto s = SpriteBuilder<Sprite>().withSize(SIZE_64_32).buildPtr();
    ASSERT_EQ(64, s->getWidth());
    ASSERT_EQ(32, s->getHeight());
}

TEST_F(SpriteSuite, SpriteBuilderFillsSpriteWithData) {
    auto sprite = SpriteBuilder<Sprite>()
        .withData(kul_data, sizeof(kul_data))
            .withLocation(10, 20)
            .withSize(SIZE_32_64)
        .buildPtr();

    ASSERT_EQ(32, sprite->getWidth());
    ASSERT_EQ(64, sprite->getHeight());
    ASSERT_EQ(10, sprite->getX());
    ASSERT_EQ(20, sprite->getY());
}
