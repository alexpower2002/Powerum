//
// Created by Alex Dol on 30.11.2022.
//

#include "Utils.h"

int Utils::ToInt32(unsigned char *buffer, int offset) {
    int a = buffer[0+offset] + (buffer[1+offset] << 8) + (buffer[2+offset] << 16) + (buffer[3+offset] << 24);

    return a;
}