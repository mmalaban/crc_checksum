#include <stdio.h>
#include <stdint.h>

// CRC-32 polynomial: 0x04C11DB7
uint32_t crc32_table[256];

void generate_crc32_table() {
    uint32_t crc, i, j;

    for (i = 0; i < 256; i++) {
        crc = i;
        for (j = 0; j < 8; j++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ 0xEDB88320;
            } else {
                crc >>= 1;
            }
        }
        crc32_table[i] = crc;
    }
}

uint32_t crc32(const uint8_t *data, size_t length) {
    uint32_t crc = 0xFFFFFFFF;
    size_t i;

    for (i = 0; i < length; i++) {
        crc = (crc >> 8) ^ crc32_table[(crc ^ data[i]) & 0xFF];
    }

    return crc ^ 0xFFFFFFFF;
}

int main() {
    const uint8_t data[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x21}; // "Hello, World!"
    size_t data_length = sizeof(data) / sizeof(data[0]);

    generate_crc32_table();
    uint32_t crc = crc32(data, data_length);

    printf("CRC-32: 0x%08X\n", crc);

    return 0;
}
