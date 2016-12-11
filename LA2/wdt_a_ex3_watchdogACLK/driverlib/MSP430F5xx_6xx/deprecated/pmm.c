/* --COPYRIGHT--,BSD
 * Copyright (c) 2014, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//*****************************************************************************
//
// pmm.c - Driver for the pmm Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup pmm_api pmm
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef DRIVERLIB_LEGACY_MODE

#ifdef __MSP430_HAS_PMM__
#include "pmm.h"

#include <assert.h>

void PMM_enableSvsL (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMLCTL) |= SVSLE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_disableSvsL (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMLCTL) &= ~SVSLE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_enableSvmL (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMLCTL) |= SVMLE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_disableSvmL (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMLCTL) &= ~SVMLE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_enableSvsH (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMHCTL) |= SVSHE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_disableSvsH (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMHCTL) &= ~SVSHE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_enableSvmH (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMHCTL) |= SVMHE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_disableSvmH (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMHCTL) &= ~SVMHE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_enableSvsLSvmL (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMLCTL) |= (SVSLE + SVMLE);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_disableSvsLSvmL (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMLCTL) &= ~(SVSLE + SVMLE);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_enableSvsHSvmH (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMHCTL) |= (SVSHE + SVMHE);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_disableSvsHSvmH (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMHCTL) &= ~(SVSHE + SVMHE);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_enableSvsLReset (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_PMMRIE) |= SVSLPE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_disableSvsLReset (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_PMMRIE) &= ~SVSLPE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_enableSvmLInterrupt (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_PMMRIE) |= SVMLIE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_disableSvmLInterrupt (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_PMMRIE) &= ~SVMLIE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_enableSvsHReset (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_PMMRIE) |= SVSHPE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_disableSvsHReset (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_PMMRIE) &= ~SVSHPE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_enableSvmHInterrupt (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_PMMRIE) |= SVMHIE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_disableSvmHInterrupt (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_PMMRIE) &= ~SVMHIE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_clearPMMIFGS (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_PMMIFG) = 0;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_SvsLEnabledInLPMFastWake (uint16_t baseAddress)
{
    //These settings use SVSH/LACE = 0
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMLCTL) |= (SVSLFP + SVSLMD);
    HWREG16(baseAddress + OFS_SVSMLCTL) &= ~SVSMLACE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_SvsLEnabledInLPMSlowWake (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMLCTL) |= SVSLMD;
    HWREG16(baseAddress + OFS_SVSMLCTL) &= ~(SVSLFP + SVSMLACE);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_SvsLDisabledInLPMFastWake (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMLCTL) |= SVSLFP;
    HWREG16(baseAddress + OFS_SVSMLCTL) &= ~(SVSLMD + SVSMLACE);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_SvsLDisabledInLPMSlowWake (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMLCTL) &= ~(SVSLFP + SVSMLACE + SVSLMD);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_SvsHEnabledInLPMNormPerf (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMHCTL) |= SVSHMD;
    HWREG16(baseAddress + OFS_SVSMHCTL) &= ~(SVSMHACE + SVSHFP);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_SvsHEnabledInLPMFullPerf (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMHCTL) |= (SVSHMD + SVSHFP);
    HWREG16(baseAddress + OFS_SVSMHCTL) &= ~SVSMHACE;
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_SvsHDisabledInLPMNormPerf (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMHCTL) &= ~(SVSMHACE + SVSHFP + SVSHMD);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_SvsHDisabledInLPMFullPerf (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMHCTL) |= SVSHFP;
    HWREG16(baseAddress + OFS_SVSMHCTL) &= ~(SVSMHACE + SVSHMD);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_SvsLOptimizedInLPMFastWake (uint16_t baseAddress)
{
    //These setting use SVSH/LACE = 1
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMLCTL) |= (SVSLFP + SVSLMD + SVSMLACE);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

void PMM_SvsHOptimizedInLPMFullPerf (uint16_t baseAddress)
{
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;
    HWREG16(baseAddress + OFS_SVSMHCTL) |= (SVSHMD + SVSHFP + SVSMHACE);
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
}

uint16_t PMM_setVCoreUp (uint16_t baseAddress, uint8_t level)
{
    uint32_t PMMRIE_backup, SVSMHCTL_backup, SVSMLCTL_backup;

    //The code flow for increasing the Vcore has been altered to work around
    //the erratum FLASH37.
    //Please refer to the Errata sheet to know if a specific device is affected
    //DO NOT ALTER THIS FUNCTION

    //Open PMM registers for write access
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;

    //Disable dedicated Interrupts
    //Backup all registers
    PMMRIE_backup = HWREG16(baseAddress + OFS_PMMRIE);
    HWREG16(baseAddress + OFS_PMMRIE) &= ~(SVMHVLRPE | SVSHPE | SVMLVLRPE |
                                          SVSLPE | SVMHVLRIE | SVMHIE |
                                          SVSMHDLYIE | SVMLVLRIE | SVMLIE |
                                          SVSMLDLYIE
                                          );
    SVSMHCTL_backup = HWREG16(baseAddress + OFS_SVSMHCTL);
    SVSMLCTL_backup = HWREG16(baseAddress + OFS_SVSMLCTL);

    //Clear flags
    HWREG16(baseAddress + OFS_PMMIFG) = 0;

    //Set SVM highside to new level and check if a VCore increase is possible
    HWREG16(baseAddress + OFS_SVSMHCTL) = SVMHE | SVSHE | (SVSMHRRL0 * level);

    //Wait until SVM highside is settled
    while ((HWREG16(baseAddress + OFS_PMMIFG) & SVSMHDLYIFG) == 0) ;

    //Clear flag
    HWREG16(baseAddress + OFS_PMMIFG) &= ~SVSMHDLYIFG;

    //Check if a VCore increase is possible
    if ((HWREG16(baseAddress + OFS_PMMIFG) & SVMHIFG) == SVMHIFG){
        //-> Vcc is too low for a Vcore increase
        //recover the previous settings
        HWREG16(baseAddress + OFS_PMMIFG) &= ~SVSMHDLYIFG;
        HWREG16(baseAddress + OFS_SVSMHCTL) = SVSMHCTL_backup;

        //Wait until SVM highside is settled
        while ((HWREG16(baseAddress + OFS_PMMIFG) & SVSMHDLYIFG) == 0) ;

        //Clear all Flags
        HWREG16(baseAddress +
            OFS_PMMIFG) &= ~(SVMHVLRIFG | SVMHIFG | SVSMHDLYIFG |
                             SVMLVLRIFG | SVMLIFG |
                             SVSMLDLYIFG
                             );

        //Restore PMM interrupt enable register
        HWREG16(baseAddress + OFS_PMMRIE) = PMMRIE_backup;
        //Lock PMM registers for write access
        HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
        //return: voltage not set
        return ( STATUS_FAIL) ;
    }

    //Set also SVS highside to new level
    //Vcc is high enough for a Vcore increase
    HWREG16(baseAddress + OFS_SVSMHCTL) |= (SVSHRVL0 * level);

    //Wait until SVM highside is settled
    while ((HWREG16(baseAddress + OFS_PMMIFG) & SVSMHDLYIFG) == 0) ;

    //Clear flag
    HWREG16(baseAddress + OFS_PMMIFG) &= ~SVSMHDLYIFG;

    //Set VCore to new level
    HWREG8(baseAddress + OFS_PMMCTL0_L) = PMMCOREV0 * level;

    //Set SVM, SVS low side to new level
    HWREG16(baseAddress + OFS_SVSMLCTL) = SVMLE | (SVSMLRRL0 * level) |
                                         SVSLE | (SVSLRVL0 * level);

    //Wait until SVM, SVS low side is settled
    while ((HWREG16(baseAddress + OFS_PMMIFG) & SVSMLDLYIFG) == 0) ;

    //Clear flag
    HWREG16(baseAddress + OFS_PMMIFG) &= ~SVSMLDLYIFG;
    //SVS, SVM core and high side are now set to protect for the new core level

    //Restore Low side settings
    //Clear all other bits _except_ level settings
    HWREG16(baseAddress + OFS_SVSMLCTL) &= (SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 +
                                           SVSMLRRL1 + SVSMLRRL2
                                           );

    //Clear level settings in the backup register,keep all other bits
    SVSMLCTL_backup &=
        ~(SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 + SVSMLRRL1 + SVSMLRRL2);

    //Restore low-side SVS monitor settings
    HWREG16(baseAddress + OFS_SVSMLCTL) |= SVSMLCTL_backup;

    //Restore High side settings
    //Clear all other bits except level settings
    HWREG16(baseAddress + OFS_SVSMHCTL) &= (SVSHRVL0 + SVSHRVL1 +
                                           SVSMHRRL0 + SVSMHRRL1 +
                                           SVSMHRRL2
                                           );

    //Clear level settings in the backup register,keep all other bits
    SVSMHCTL_backup &=
        ~(SVSHRVL0 + SVSHRVL1 + SVSMHRRL0 + SVSMHRRL1 + SVSMHRRL2);

    //Restore backup
    HWREG16(baseAddress + OFS_SVSMHCTL) |= SVSMHCTL_backup;

    //Wait until high side, low side settled
    while (((HWREG16(baseAddress + OFS_PMMIFG) & SVSMLDLYIFG) == 0) ||
           ((HWREG16(baseAddress + OFS_PMMIFG) & SVSMHDLYIFG) == 0)) ;

    //Clear all Flags
    HWREG16(baseAddress + OFS_PMMIFG) &= ~(SVMHVLRIFG | SVMHIFG | SVSMHDLYIFG |
                                          SVMLVLRIFG | SVMLIFG | SVSMLDLYIFG
                                          );

    //Restore PMM interrupt enable register
    HWREG16(baseAddress + OFS_PMMRIE) = PMMRIE_backup;

    //Lock PMM registers for write access
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;

    return ( STATUS_SUCCESS) ;
}

uint16_t PMM_setVCoreDown (uint16_t baseAddress, uint8_t level)
{
    uint32_t PMMRIE_backup, SVSMHCTL_backup, SVSMLCTL_backup;

    //The code flow for decreasing the Vcore has been altered to work around
    //the erratum FLASH37.
    //Please refer to the Errata sheet to know if a specific device is affected
    //DO NOT ALTER THIS FUNCTION

    //Open PMM registers for write access
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0xA5;

    //Disable dedicated Interrupts
    //Backup all registers
    PMMRIE_backup = HWREG16(baseAddress + OFS_PMMRIE);
    HWREG16(baseAddress + OFS_PMMRIE) &= ~(SVMHVLRPE | SVSHPE | SVMLVLRPE |
                                          SVSLPE | SVMHVLRIE | SVMHIE |
                                          SVSMHDLYIE | SVMLVLRIE | SVMLIE |
                                          SVSMLDLYIE
                                          );
    SVSMHCTL_backup = HWREG16(baseAddress + OFS_SVSMHCTL);
    SVSMLCTL_backup = HWREG16(baseAddress + OFS_SVSMLCTL);

    //Clear flags
    HWREG16(baseAddress + OFS_PMMIFG) &= ~(SVMHIFG | SVSMHDLYIFG |
                                          SVMLIFG | SVSMLDLYIFG
                                          );

    //Set SVM, SVS high & low side to new settings in normal mode
    HWREG16(baseAddress + OFS_SVSMHCTL) = SVMHE | (SVSMHRRL0 * level) |
                                         SVSHE | (SVSHRVL0 * level);
    HWREG16(baseAddress + OFS_SVSMLCTL) = SVMLE | (SVSMLRRL0 * level) |
                                         SVSLE | (SVSLRVL0 * level);

    //Wait until SVM high side and SVM low side is settled
    while ((HWREG16(baseAddress + OFS_PMMIFG) & SVSMHDLYIFG) == 0 ||
           (HWREG16(baseAddress + OFS_PMMIFG) & SVSMLDLYIFG) == 0) ;

    //Clear flags
    HWREG16(baseAddress + OFS_PMMIFG) &= ~(SVSMHDLYIFG + SVSMLDLYIFG);
    //SVS, SVM core and high side are now set to protect for the new core level

    //Set VCore to new level
    HWREG8(baseAddress + OFS_PMMCTL0_L) = PMMCOREV0 * level;

    //Restore Low side settings
    //Clear all other bits _except_ level settings
    HWREG16(baseAddress + OFS_SVSMLCTL) &= (SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 +
                                           SVSMLRRL1 + SVSMLRRL2
                                           );

    //Clear level settings in the backup register,keep all other bits
    SVSMLCTL_backup &=
        ~(SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 + SVSMLRRL1 + SVSMLRRL2);

    //Restore low-side SVS monitor settings
    HWREG16(baseAddress + OFS_SVSMLCTL) |= SVSMLCTL_backup;

    //Restore High side settings
    //Clear all other bits except level settings
    HWREG16(baseAddress + OFS_SVSMHCTL) &= (SVSHRVL0 + SVSHRVL1 + SVSMHRRL0 +
                                           SVSMHRRL1 + SVSMHRRL2
                                           );

    //Clear level settings in the backup register, keep all other bits
    SVSMHCTL_backup &=
        ~(SVSHRVL0 + SVSHRVL1 + SVSMHRRL0 + SVSMHRRL1 + SVSMHRRL2);

    //Restore backup
    HWREG16(baseAddress + OFS_SVSMHCTL) |= SVSMHCTL_backup;

    //Wait until high side, low side settled
    while (((HWREG16(baseAddress + OFS_PMMIFG) & SVSMLDLYIFG) == 0) ||
           ((HWREG16(baseAddress + OFS_PMMIFG) & SVSMHDLYIFG) == 0)) ;

    //Clear all Flags
    HWREG16(baseAddress + OFS_PMMIFG) &= ~(SVMHVLRIFG | SVMHIFG | SVSMHDLYIFG |
                                          SVMLVLRIFG | SVMLIFG | SVSMLDLYIFG
                                          );

    //Restore PMM interrupt enable register
    HWREG16(baseAddress + OFS_PMMRIE) = PMMRIE_backup;
    //Lock PMM registers for write access
    HWREG8(baseAddress + OFS_PMMCTL0_H) = 0x00;
    //Return: OK
    return ( STATUS_SUCCESS) ;
}

bool PMM_setVCore (uint16_t baseAddress, uint8_t level)
{
    uint8_t actlevel;
    bool status = STATUS_SUCCESS;

    //Set Mask for Max. level
    level &= PMMCOREV_3;

    //Get actual VCore
    actlevel = (HWREG16(baseAddress + OFS_PMMCTL0) & PMMCOREV_3);

    //step by step increase or decrease
    while ((level != actlevel) && (status == STATUS_SUCCESS))
    {
        if (level > actlevel){
            status = PMM_setVCoreUp(baseAddress, ++actlevel);
        } else   {
            status = PMM_setVCoreDown(baseAddress, --actlevel);
        }
    }

    return ( status) ;
}

uint16_t PMM_getInterruptStatus (uint16_t baseAddress,
    uint16_t mask)
{
    return ( (HWREG16(baseAddress + OFS_PMMIFG)) & mask );
}

#endif
#endif
//*****************************************************************************
//
//! Close the doxygen group for pmm_api
//! @}
//
//*****************************************************************************