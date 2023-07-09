#include <stdint.h>
#include <stdio.h>

int main(void) {
    const uint32_t K[0x40] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
    };
    register uint64_t N = 0x0000000000000000;
    for (register int8_t n = 0x3c; n >= 0x00; n -= 0x04) {
        register int c = getchar();
        register uint8_t x = '0' <= c && c <= '9'? c - '0':
                             'a' <= c && c <= 'f'? c - 'a' + 0x0a: 0x00;
        N = N | (uint64_t)x << n;
    }
    getchar();
    uint32_t H[0x08] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19,
    };
    for (register uint64_t i = 0x0000000000000000; i < N; i++) {
        uint32_t M[0x10] = {};
        for (register uint8_t t = 0x00; t < 0x10; t++) {
            for (register int8_t n = 0x1c; n >= 0x00; n -= 0x04) {
                register int c = getchar();
                register uint8_t x = '0' <= c && c <= '9'? c - '0':
                                     'a' <= c && c <= 'f'? c - 'a' + 0x0a: 0x00;
                M[t] = M[t] | (uint32_t)x << n;
            }
        }
        getchar();
        uint32_t W[0x40];
        for (register uint8_t t = 0x00; t < 0x40; t++) {
            W[t] = 0x00 <= t && t <= 0x0f? M[t]:
                   0x10 <= t && t <= 0x3f? ((W[t - 0x02] >> 0x11 | W[t - 0x02] << 0x0f) ^ (W[t - 0x02] >> 0x13 | W[t - 0x02] << 0x0d) ^ W[t - 0x02] >> 0x0a) + W[t - 0x07] +
                                           ((W[t - 0x0f] >> 0x07 | W[t - 0x0f] << 0x19) ^ (W[t - 0x0f] >> 0x12 | W[t - 0x0f] << 0x0e) ^ W[t - 0x0f] >> 0x03) + W[t - 0x10]: 0x00000000;
        }
        uint32_t a = H[0x00];
        uint32_t b = H[0x01];
        uint32_t c = H[0x02];
        uint32_t d = H[0x03];
        uint32_t e = H[0x04];
        uint32_t f = H[0x05];
        uint32_t g = H[0x06];
        uint32_t h = H[0x07];
        for (register uint8_t t = 0x00; t < 0x40; t++) {
            register uint32_t T1 = h + ((e >> 0x06 | e << 0x1a) ^ (e >> 0x0b | e << 0x15) ^ (e >> 0x19 | e << 0x07)) + (e & f ^ ~e & g) + K[t] + W[t];
            register uint32_t T2 = ((a >> 0x02 | a << 0x1e) ^ (a >> 0x0d | a << 0x13) ^ (a >> 0x16 | a << 0x0a)) + (a & b ^ a & c ^ b & c);
            h = g; g = f; f = e; e = d + T1; d = c; c = b; b = a; a = T1 + T2;
        }
        H[0x00] = a + H[0x00];
        H[0x01] = b + H[0x01];
        H[0x02] = c + H[0x02];
        H[0x03] = d + H[0x03];
        H[0x04] = e + H[0x04];
        H[0x05] = f + H[0x05];
        H[0x06] = g + H[0x06];
        H[0x07] = h + H[0x07];
    }
    for (register uint8_t i = 0x00; i < 0x08; i++) {
        for (register int8_t n = 0x1c; n >= 0x00; n -= 0x04) {
            register uint8_t x = (uint8_t)(H[i] >> n) & 0x0f;
            register int c = 0x00 <= x && x <= 0x09? x + '0':
                             0x0a <= x && x <= 0x0f? x - 0x0a + 'a': '\x00';
            putchar(c);
        }
    }
    putchar('\n');
    return 0;
}
