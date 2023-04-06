# SIMPLE CRC 32 CHECKSUM

This code first generates a lookup table for CRC-32, then computes the CRC-32 checksum for the given data array. Note that this implementation uses the common CRC-32 polynomial `0x04C11DB7`. You can change the polynomial if necessary.

## Description of hard coded values

1. `0xEDB88320`: This value is derived from the CRC-32 polynomial `0x04C11DB7`. It's the reversed bit representation of the polynomial. In the code, it's used for generating the lookup table and computing the CRC.

2. `0xFFFFFFFF`: This value is the initial CRC value used for the calculation. It is a common starting value for CRC-32 calculations. The XOR operation with this value is used to ensure that a string of zeros doesn't result in a zero checksum. This value is also used at the end of the calculation to XOR with the computed CRC, essentially inverting all the bits, which is part of the standard CRC-32 calculation process.

3. `0x08`: This value represents the number of bits in a byte. The inner loop in the generate_crc32_table() function iterates 8 times, once for each bit in a byte. This loop is responsible for calculating the CRC-32 lookup table, which is later used to speed up the computation of the checksum.

4. `0xFF`: This value is used as a bitmask to extract the least significant byte from the current CRC value. This is done to determine the index for the lookup table.

These hardcoded values are standard for a CRC-32 implementation using the polynomial `0x04C11DB7`. If you decide to use a different polynomial or CRC method, you may need to update these values accordingly.
