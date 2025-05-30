/*
 * SPDX-FileCopyrightText: 2025 KODE DIY, SL
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief ESP LCD touch: CST820
 */

#pragma once

#include "esp_lcd_touch.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Create a new CST820 touch driver
 *
 * @note  The I2C communication should be initialized before use this function.
 *
 * @param io LCD panel IO handle, it should be created by `esp_lcd_new_panel_io_i2c()`
 * @param config Touch panel configuration
 * @param tp Touch panel handle
 * @return
 *      - ESP_OK: on success
 */
esp_err_t esp_lcd_touch_new_i2c_cst820(const esp_lcd_panel_io_handle_t io, const esp_lcd_touch_config_t *config, esp_lcd_touch_handle_t *tp);

/**
 * @brief Sets the calibration offset for touch CST820
 * @param offset_x X-offset (positive displacement to the right)
 * @param offset_y Y-offset (positive downward displacement)
 */
void cst820_set_touch_offset(int16_t offset_x, int16_t offset_y);

/**
 * @brief Gets the current calibration offset of the touch CST820
 * @param offset_x Pointer where offset X is stored
 * @param offset_y Pointer where offset Y is stored
 */
void cst820_get_touch_offset(int16_t *offset_x, int16_t *offset_y);

/**
 * @brief I2C address of the CST820 controller
 *
 */
#define ESP_LCD_TOUCH_IO_I2C_CST820_ADDRESS    (0x15)

/**
 * @brief Touch IO configuration structure
 *
 */
#define ESP_LCD_TOUCH_IO_I2C_CST820_CONFIG()              \
    {                                                     \
        .dev_addr = ESP_LCD_TOUCH_IO_I2C_CST820_ADDRESS,  \
        .on_color_trans_done = 0,                         \
        .user_ctx = 0,                                    \
        .control_phase_bytes = 1,                         \
        .dc_bit_offset = 0,                               \
        .lcd_cmd_bits = 8,                                \
        .lcd_param_bits = 0,                              \
        .flags =                                          \
        {                                                 \
            .dc_low_on_data = 0,                          \
            .disable_control_phase = 1,                   \
        },                                                \
        .scl_speed_hz = 100000                            \
    }

#ifdef __cplusplus
}
#endif