/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Scott Shawcroft for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MICROPY_INCLUDED_SHARED_MODULE_DISPLAYIO_PALETTE_H
#define MICROPY_INCLUDED_SHARED_MODULE_DISPLAYIO_PALETTE_H

#include <stdbool.h>
#include <stdint.h>

#include "py/obj.h"

typedef struct {
    uint8_t depth;
    bool grayscale;
    bool pixels_in_byte_share_row;
    uint8_t hue;
} _displayio_colorspace_t;

typedef struct {
    uint32_t rgb888;
    uint16_t rgb565;
    uint8_t luma;
    bool transparent; // This may have additional bits added later for blending.
} _displayio_color_t;

typedef struct {
    mp_obj_base_t base;
    _displayio_color_t* colors;
    uint32_t color_count;
    bool needs_refresh;
} displayio_palette_t;

// Returns false if color fetch did not succeed (out of range or transparent).
// Returns true if color is opaque, and sets color.
bool displayio_palette_get_color(displayio_palette_t *palette, const _displayio_colorspace_t* colorspace, uint32_t palette_index, uint32_t* color);
bool displayio_palette_needs_refresh(displayio_palette_t *self);
void displayio_palette_finish_refresh(displayio_palette_t *self);

#endif // MICROPY_INCLUDED_SHARED_MODULE_DISPLAYIO_PALLETE_H
