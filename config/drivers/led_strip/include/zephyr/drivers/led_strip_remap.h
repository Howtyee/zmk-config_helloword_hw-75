/*
 * Copyright (c) 2022-2023 XiNGRZ
 * SPDX-License-Identifier: MIT
 */

/**
 * @file
 * @brief Extended public API for led_strip_remap
 */

#pragma once

#include <zephyr/drivers/led_strip.h>

#ifdef __cplusplus
extern "C" {
#endif

int led_strip_remap_set(const struct device *dev, const char *label, struct led_rgb *pixel);

int led_strip_remap_clear(const struct device *dev, const char *label);

/**
 * @brief Number of addressable LEDs in the logical layout (the `map` length).
 */
int led_strip_remap_get_count(const struct device *dev);

/**
 * @brief Take over (or release) the strip from the effect engine.
 *
 * While external is enabled, regular update_rgb() writes coming from the RGB
 * effect engine are ignored, so colors set via led_strip_remap_set_pixels()
 * are not overwritten. Indicator overlays keep working.
 */
int led_strip_remap_set_external(const struct device *dev, bool external);

/**
 * @brief Directly write raw RGB pixels at a logical offset.
 *
 * @param dev        led-strip-remap device
 * @param start      starting logical LED index
 * @param rgb        packed RGB bytes, 3 per LED (R, G, B)
 * @param num_pixels number of LEDs described by @p rgb
 * @param apply      push to the LED hardware after writing
 */
int led_strip_remap_set_pixels(const struct device *dev, uint32_t start, const uint8_t *rgb,
			       uint32_t num_pixels, bool apply);

#ifdef __cplusplus
}
#endif
