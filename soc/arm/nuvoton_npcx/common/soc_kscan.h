/*
 * Copyright (c) 2020 Nuvoton Technology Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _NUVOTON_NPCX_SOC_KSCAN_H_
#define _NUVOTON_NPCX_SOC_KSCAN_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Common keyboard raw device name for all NPCX series */
#define NPCX_KB_RAW_NAME "npcx-kscan-raw"

#include <device.h>

/**
 * @brief Finish intitialization after task scheduling has started.
 *
 * Call from the keyboard scan task.
 *
 * @param dev Pointer to the device structure for keyboard scan instance.
 */
void  npcx_kb_raw_task_start(const struct device *dev);

/**
 * @brief Drive the specified column low.
 *
 * Other columns are tristated.  See enum keyboard_column_index for special
 * values for <col>.
 *
 * @param dev Pointer to the device structure for keyboard scan instance.
 * @param col specified column mask that are driven to low.
 */
void npcx_kb_raw_drive_column(const struct device *dev, int col);

/**
 * @brief Read raw row state.
 *
 * Bits are 1 if signal is present, 0 if not present.
 *
 * @param dev Pointer to the device structure for keyboard scan instance.
 * @retval raw row state of keyboard.
 */
int npcx_kb_raw_read_row(const struct device *dev);

/**
 * @brief Enable or disable keyboard interrupts.
 *
 * Enabling interrupts will clear any pending interrupt bits.  To avoid missing
 * any interrupts that occur between the end of scanning and then, you should
 * call cros_kb_raw_read_rows() after this.  If it returns non-zero, disable
 * interrupts and go back to polling mode instead of waiting for an interrupt.
 *
 * @param dev Pointer to the device structure for keyboard scan instance.
 * @param enable Enable or disable keyboard interrupts.
 */
void npcx_kb_raw_enable_interrupt(const struct device *dev, int enable);

/**
 * @brief Keyboard scan callback called when user press/release
 * a key on a matrix keyboard.
 *
 * @param dev   Pointer to the device structure for keyboard driver instance.
 * @param col	Describes column change.
 * @param row	Describes row change.
 * @param pressed Describes the kind of key event.
 */
void npcx_kb_raw_callback(const struct device *dev, uint32_t row, uint32_t col,
							bool pressed);

#ifdef __cplusplus
}
#endif

#endif /* _NUVOTON_NPCX_SOC_KSCAN_H_ */
