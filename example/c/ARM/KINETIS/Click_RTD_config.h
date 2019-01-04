#include "Click_RTD_types.h"

const uint32_t _RTD_SPI_CFG[ 2 ] = 
{ 
    5000000,
    _SPI_CFG_CLK_PHASE_CHG_LEADING |
    _SPI_CFG_CLK_IDLE_HIGH |
    _SPI_CFG_MASTER |
    _SPI_CFG_MSB_FIRST |
    _SPI_CFG_FRAME_SIZE_8BITS |
    _SPI_CFG_SELECT_CTAR0
};
