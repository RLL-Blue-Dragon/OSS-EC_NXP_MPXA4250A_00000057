// License       : License.txt
// Specifications: Spec-MPXA4250A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPXA4250A.h
// Reason for change: 01.00.00 : 31/08/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __MPXA4250A_H__
#define __MPXA4250A_H__

#include "user_define.h"

// Components number
#define iMPXA4250A              100U                    // NXP MPXA4250A

// MPXA4250A System Parts definitions
#define iMPXA4250A_xoff         ( -0.04F*iADC_vdd )     // X offset [V]
#define iMPXA4250A_yoff         0.0F                    // Y offset [kPa]
#define iMPXA4250A_gain         ( 0.004F*iADC_vdd )     // Gain [V/kPa]
#define iMPXA4250A_max          250.0F                  // Pressure Max [kPa]
#define iMPXA4250A_min          20.0F                   // Pressure Min [kPa]

extern const tbl_adc_t tbl_MPXA4250A;

#endif /*__MPXA4250A_H__*/
