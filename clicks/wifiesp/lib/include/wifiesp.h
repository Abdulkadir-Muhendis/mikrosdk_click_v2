/*
 * MikroSDK - MikroE Software Development Kit
 * Copyright© 2020 MikroElektronika d.o.o.
 * 
 * Permission is hereby granted, free of charge, to any person 
 * obtaining a copy of this software and associated documentation 
 * files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, merge, 
 * publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE 
 * OR OTHER DEALINGS IN THE SOFTWARE. 
 */

/*!
 * \file
 *
 * \brief This file contains API for Wifi ESP Click driver.
 *
 * \addtogroup wifiesp Wifi ESP Click Driver
 * @{
 */
// ----------------------------------------------------------------------------

#ifndef WIFIESP_H
#define WIFIESP_H

#include "drv_digital_out.h"
#include "drv_digital_in.h"
#include "drv_uart.h"


// -------------------------------------------------------------- PUBLIC MACROS 
/**
 * \defgroup macros Macros
 * \{
 */

/**
 * \defgroup map_mikrobus MikroBUS
 * \{
 */
#define WIFIESP_MAP_MIKROBUS( cfg, mikrobus ) \
  cfg.tx_pin  = MIKROBUS( mikrobus, MIKROBUS_TX ); \
  cfg.rx_pin  = MIKROBUS( mikrobus, MIKROBUS_RX ); \
  cfg.rst = MIKROBUS( mikrobus, MIKROBUS_RST ); \
  cfg.en = MIKROBUS( mikrobus, MIKROBUS_CS )
/** \} */

/**
 * \defgroup error_code Error Code
 * \{
 */
#define WIFIESP_RETVAL  uint8_t

#define WIFIESP_OK           0x00
#define WIFIESP_INIT_ERROR   0xFF
/** \} */

/**
 * \defgroup parser_error Parser error
 * \{
 */
#define WIFIESP_PARSER_NO_ERROR    0x00
#define WIFIESP_PARSER_ERROR_REF   0x01
#define WIFIESP_PARSER_ERROR_CMD   0x02
#define WIFIESP_PARSER_ERROR_DATA  0x04
/** \} */

/**
 * \defgroup click_status G2C 3G click status
 * \{
 */
#define WIFIESP_STATUS_DEVICE_READY            1
#define WIFIESP_STATUS_ACT_NETWORK_AND_BROKER  4
#define WIFIESP_STATUS_ACT_NETWORK             2
#define WIFIESP_STATUS_ACT_BROKER              3
#define WIFIESP_STATUS_DEVICE_BUSY             0
/** \} */

/**
 * \defgroup module_state Module power state
 * \{
 */
#define WIFIESP_MODULE_POWER_ON   1
#define WIFIESP_MODULE_POWER_OFF  0
/** \} */

/**
 * \defgroup at_command AT command 
 * \{
 */ 
#define WIFIESP_SINGLE_CMD_AT             "AT"
#define WIFIESP_SINGLE_CMD_AT_W           "AT+W"
#define WIFIESP_SINGLE_CMD_AT_R           "AT+R"
#define WIFIESP_SINGLE_CMD_ATE0           "ATE0"
#define WIFIESP_SINGLE_CMD_ATE1           "ATE1"
#define WIFIESP_SINGLE_CMD_AT_RST         "AT+RST"
#define WIFIESP_SINGLE_CMD_AT_CRST        "AT+CRST"
#define WIFIESP_SINGLE_CMD_AT_GMR         "AT+GMR"
#define WIFIESP_SINGLE_CMD_AT_GMSTA       "AT+GMSTA"
#define WIFIESP_SINGLE_CMD_AT_PUB         "AT+PUB"
#define WIFIESP_SINGLE_CMD_AT_CIPSTATUS   "AT+CIPSTATUS"
#define WIFIESP_SINGLE_CMD_AT_CIFSR       "AT+CIFSR"

#define WIFIESP_SINGLE_CMD_SET_AT_LRSP_1            "AT+LRSP=1"
#define WIFIESP_SINGLE_CMD_SET_AT_LRSP_0            "AT+LRSP=0"
#define WIFIESP_SINGLE_CMD_SET_AT_CEN_1             "AT+CEN=1"
#define WIFIESP_SINGLE_CMD_SET_AT_CEN_0             "AT+CEN=0"
#define WIFIESP_SINGLE_CMD_SET_AT_NWC_1             "AT+NWC=1"
#define WIFIESP_SINGLE_CMD_SET_AT_NWC_0             "AT+NWC=0"
#define WIFIESP_SINGLE_CMD_SET_AT_BRC_1             "AT+BRC=1"
#define WIFIESP_SINGLE_CMD_SET_AT_BRC_0             "AT+BRC=0"
#define WIFIESP_SINGLE_CMD_SET_AT_GPEN_0            "AT+GPEN=0"
#define WIFIESP_SINGLE_CMD_SET_AT_GPEN_1            "AT+GPEN=1"
#define WIFIESP_SINGLE_CMD_SET_AT_CWMODE_1          "AT+CWMODE=1"
#define WIFIESP_SINGLE_CMD_SET_AT_CIPMUX_1          "AT+CIPMUX=1"
#define WIFIESP_SINGLE_CMD_SET_AT_CIPSERVER_1_80    "AT+CIPSERVER=1,80"


#define WIFIESP_SINGLE_CMD_GET_AT_LRSP   "AT+LRSP?"
#define WIFIESP_SINGLE_CMD_GET_AT_CEN    "AT+CEN?"
#define WIFIESP_SINGLE_CMD_GET_AT_NWC    "AT+NWC?"
#define WIFIESP_SINGLE_CMD_GET_AT_BRC    "AT+BRC?"
#define WIFIESP_SINGLE_CMD_GET_AT_GPEN   "AT+GPEN?"
#define WIFIESP_SINGLE_CMD_GET_AT_NWCR   "AT+NWCR?"
#define WIFIESP_SINGLE_CMD_GET_AT_BRCR   "AT+BRCR?"
#define WIFIESP_SINGLE_CMD_GET_AT_DSET   "AT+DSET?"
#define WIFIESP_SINGLE_CMD_GET_AT_CIPSTO "AT+CIPSTO?"

#define WIFIESP_SINGLE_CMD_TEST_AT_LRSP "AT+LRSP=?"
#define WIFIESP_SINGLE_CMD_TEST_AT_CEN  "AT+CEN=?"
#define WIFIESP_SINGLE_CMD_TEST_AT_NWC  "AT+NWC=?"
#define WIFIESP_SINGLE_CMD_TEST_AT_BRC  "AT+BRC=?"
#define WIFIESP_SINGLE_CMD_TEST_AT_GPEN "AT+GPEN=?"
#define WIFIESP_SINGLE_CMD_TEST_AT_NWCR "AT+NWCR=?"
#define WIFIESP_SINGLE_CMD_TEST_AT_BRCR "AT+BRCR=?"
#define WIFIESP_SINGLE_CMD_TEST_AT_DSET "AT+DSET=?"

#define WIFIESP_MULTI_CMD_AT_DSET "AT+DSET"
#define WIFIESP_MULTI_CMD_AT_BRCR "AT+BRCR"
#define WIFIESP_MULTI_CMD_AT_NWCR "AT+NWCR"
/** \} */

/**
 * \defgroup driver Driver define
 * \{
 */
#define DRV_RX_BUFFER_SIZE 500
/** \} */

/** \} */ // End group macro 
// --------------------------------------------------------------- PUBLIC TYPES
/**
 * \defgroup type Types
 * \{
 */
/**
 * @brief Click ctx object definition.
 */
typedef struct
{
    // Output pins 

    digital_out_t rst;
    digital_out_t en;
    
    // Modules 

    uart_t uart;

    char uart_rx_buffer[ DRV_RX_BUFFER_SIZE ];
    char uart_tx_buffer[ DRV_RX_BUFFER_SIZE ];

} wifiesp_t;

/**
 * @brief Click configuration structure definition.
 */
typedef struct
{
    // Communication gpio pins 

    pin_name_t rx_pin;
    pin_name_t tx_pin;
    
    // Additional gpio pins 

    pin_name_t rst;
    pin_name_t en;

    // static variable 

    uint32_t          baud_rate;     // Clock speed.
    bool              uart_blocking;
    uart_data_bits_t  data_bit;      // Data bits.
    uart_parity_t     parity_bit;    // Parity bit.  
    uart_stop_bits_t  stop_bit;      // Stop bits.    

} wifiesp_cfg_t;

/**
 * @brief Error type 
 */
// Actuator switch type
typedef uint8_t wifiesp_actuator_sw_t;

// Actuator counter type
typedef int16_t wifiesp_actuator_cnt_t;

// Actuator string type
typedef char wifiesp_actuator_str_t;

// Parser error type
typedef uint8_t wifiesp_error_t;

/** \} */ // End types group
// ----------------------------------------------- PUBLIC FUNCTION DECLARATIONS

/**
 * \defgroup public_function Public function
 * \{
 */
 
#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Config Object Initialization function.
 *
 * @param cfg  Click configuration structure.
 *
 * @description This function initializes click configuration structure to init state.
 * @note All used pins will be set to unconnected state.
 */
void wifiesp_cfg_setup ( wifiesp_cfg_t *cfg );

/**
 * @brief Initialization function.
 * @param ctx Click object.
 * @param cfg Click configuration structure.
 * 
 * @description This function initializes all necessary pins and peripherals used for this click.
 */
WIFIESP_RETVAL wifiesp_init ( wifiesp_t *ctx, wifiesp_cfg_t *cfg );

/**
 * @brief Reset module.
 * @param ctx Click object.
 */
void wifiesp_reset ( wifiesp_t *ctx );

/**
 * @brief Generic write function.
 * @param ctx Click object.
 * @param data_buf Data buffer for sends.
 * @param len Number of bytes for sends.
 */
void wifiesp_generic_write ( wifiesp_t *ctx, char *data_buf, uint16_t len );

/**
 * @brief Generic read function.
 * @param ctx Click object.
 * @param data_buf Data buffer for read data.
 * @param max_len The maximum length of data that can be read.
 * @return Number of reads data.
 */
uint16_t wifiesp_generic_read ( wifiesp_t *ctx, char *data_buf, uint16_t max_len );

/**
 * @brief Send Command function.
 * @param ctx  Click object.
 * @param command  Command.
 * @description This function sends comamnd.
 */
void wifiesp_send_command ( wifiesp_t *ctx, char *command );

#ifdef __cplusplus
}
#endif
#endif  // _WIFIESP_H_

/** \} */ // End public_function group
/// \}    // End click Driver group  
/*! @} */
// ------------------------------------------------------------------------- END
