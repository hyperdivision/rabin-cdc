#ifndef _RABIN_H
#define _RABIN_H

#include <stdint.h>

#define POLYNOMIAL 0x3DA3358B4DC173LL
#define POLYNOMIAL_DEGREE 53
#define WINSIZE 64

struct rabin_t {
    size_t minsize;
    size_t maxsize;
    uint64_t mask;

    uint8_t window[WINSIZE];
    unsigned int wpos;
    unsigned int count;
    unsigned int pos;
    unsigned int start;
    uint64_t digest;
};

struct chunk_t {
    unsigned int start;
    unsigned int length;
    uint64_t cut_fingerprint;
};

extern struct chunk_t last_chunk;

void rabin_init(struct rabin_t *h);
void rabin_reset(struct rabin_t *h);
void rabin_slide(struct rabin_t *h, uint8_t b);
void rabin_append(struct rabin_t *h, uint8_t b);
int rabin_next_chunk(struct rabin_t *h, uint8_t *buf, unsigned int len);
struct chunk_t *rabin_finalize(struct rabin_t *h);

#endif
