//
// Created by Alex Dol on 10.12.2022.
//

#define STBI_IMPLEMENTATION
#define STBI_ONLYPNG

//#include "stb_image.h"
/*
\**
 * Parse PNG format into pixels. Returns NULL or error, otherwise the returned data looks like
 *   ret[0] = width of the image
 *   ret[1] = height of the image
 *   ret[2..] = 32 bit ARGB pixels (blue channel in the least significant byte, alpha channel in the most)
 *\
unsigned int *png_parse(unsigned char *ptr, int size) {
    int i, w, h, f;
    unsigned char *img, *p;

    stbi__context s;
    stbi__result_info ri;

    s.read_from_callbacks = 0;

    s.img_buffer = s.img_buffer_original = ptr;

    s.img_buffer_end = s.img_buffer_original_end = ptr + size;

    ri.bits_per_channel = 8;

    img = p = (unsigned char *)stbi__png_load(&s, (int*)&w, (int*)&h, (int*)&f, 1, &ri);

    auto data = new unsigned int[w * h + 2];

    if (!data) {
        //free(img);
        return nullptr;
    }
// convert the returned image into frame buffer format
    for (
            i = 0;
            i < w * h;
            i++, p += f)
        switch (f) {
            case 1:
                data[2 + i] = 0xFF000000 | (p[0] << 16) | (p[0] << 8) | p[0];
                break;
            case 2:
                data[2 + i] = (p[1] << 24) | (p[0] << 16) | (p[0] << 8) | p[0];
                break;
            case 3:
                data[2 + i] = 0xFF000000 | (p[0] << 16) | (p[1] << 8) | p[2];
                break;
            case 4:
                data[2 + i] = (p[3] << 24) | (p[0] << 16) | (p[1] << 8) | p[2];
                break;
        }
    //free(img);
    data[0] = w;
    data[1] = h;
    return data;
}*/