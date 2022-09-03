// License       : License.txt
// Specifications: Spec-MPXA4250A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPXA4250A.cpp
// Reason for change: 01.00.00 : 31/08/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "MPXA4250A.h"

#if     iMPXA4250A_ma == iSMA                           // Simple moving average filter
static float32 MPXA4250A_sma_buf[iMPXA4250A_SMA_num];
static sma_f32_t MPXA4250A_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iMPXA4250A_SMA_num ,                            // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &MPXA4250A_sma_buf[0]                           // buffer
};

#elif   iMPXA4250A_ma == iEMA                           // Exponential moving average filter
static ema_f32_t MPXA4250A_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iMPXA4250A_EMA_K                                // Exponential smoothing factor 
};

#elif   iMPXA4250A_ma == iWMA                           // Weighted moving average filter
static float32 MPXA4250A_wma_buf[iMPXA4250A_WMA_num];
static wma_f32_t MPXA4250A_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iMPXA4250A_WMA_num ,                            // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iMPXA4250A_WMA_num * (iMPXA4250A_WMA_num + 1)/2 , // kn sum
        &MPXA4250A_wma_buf[0]                           // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_MPXA4250A =
{
        iMPXA4250A              ,
        iMPXA4250A_pin          ,
        iMPXA4250A_xoff         ,
        iMPXA4250A_yoff         ,
        iMPXA4250A_gain         ,
        iMPXA4250A_max          ,
        iMPXA4250A_min          ,
        iMPXA4250A_ma           ,
        
#if     iMPXA4250A_ma == iSMA                           // Simple moving average filter
        &MPXA4250A_Phy_SMA      ,
        iDummy_adr              ,
        iDummy_adr
#elif   iMPXA4250A_ma == iEMA                           // Exponential moving average filter
        iDummy_adr              ,
        &MPXA4250A_Phy_EMA      ,
        iDummy_adr
#elif   iMPXA4250A_ma == iWMA                           // Weighted moving average filter
        iDummy_adr              ,
        iDummy_adr              ,
        &MPXA4250A_Phy_WMA
#else                                                   // Non-moving average filter
        iDummy_adr              ,
        iDummy_adr              ,
        iDummy_adr
#endif

};
