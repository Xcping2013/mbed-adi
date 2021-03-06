
/**
*   @file     config.h
*   @brief    Config file for driver diag tool
*   @author   Analog Devices Inc.
*
* For support please go to:
* Github: https://github.com/analogdevicesinc/mbed-adi
* Support: https://ez.analog.com/community/linux-device-drivers/microcontroller-no-os-drivers
* More: https://wiki.analog.com/resources/tools-software/mbed-drivers-all

********************************************************************************
* Copyright 2016(c) Analog Devices, Inc.
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*  - Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  - Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
*  - Neither the name of Analog Devices, Inc. nor the names of its
*    contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*  - The use of this software may or may not infringe the patent rights
*    of one or more patent holders.  This license does not release you
*    from the requirement that you obtain separate licenses from these
*    patent holders to use this software.
*  - Use of the software either in source or binary form, must be run
*    on or directly connected to an Analog Devices Inc. component.
*
* THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
********************************************************************************/

//#define AD7791_PRESENT
//#define CN0216_PRESENT
//#define AD7790_PRESENT
//#define AD5270_PRESENT
//#define CN0357_PRESENT
//#define ADXL362_PRESENT
//#define CN0398_PRESENT
//#define CN0397_PRESENT
#define CN0396_PRESENT
//#define AD7124_PRESENT
#define SPI_LOW_LEVEL

#ifdef AD7791_PRESENT
#include "AD7791.h"
#include "AD7791_Diag.h"
#endif

#ifdef CN0216_PRESENT
#include "CN0216.h"
#include "CN0216_Diag.h"
#endif

#ifdef AD7790_PRESENT
#include "AD7790.h"
#include "AD7790_Diag.h"
#endif

#ifdef AD5270_PRESENT
#include "AD5270.h"
#include "AD5270_Diag.h"
#endif

#ifdef CN0357_PRESENT
#include "CN0357.h"
#include "CN0357_Diag.h"
#endif

#ifdef ADXL362_PRESENT
#include "ADXL362.h"
#include "ADXL362_Diag.h"
#endif

#ifdef AD7124_PRESENT
#include "AD7124.h"
#include "AD7124_Diag.h"
#endif

#ifdef CN0398_PRESENT
#include "CN0398.h"
#include "CN0398_Diag.h"
#endif


#ifdef CN0397_PRESENT
#include "CN0397.h"
#include "CN0397_Diag.h"
#endif

#ifdef CN0396_PRESENT
#include "CN0396.h"
#include "CN0396_Diag.h"
#endif

using namespace std;
//------------------------------------
// Hyperterminal configuration
// 9600 bauds, 8-bit data, no parity
//------------------------------------

#ifdef SPI_LOW_LEVEL
//DigitalOut CSA_pin(D8); // cs adc
DigitalOut CSA_pin(D4); // cs accel
DigitalOut CSR_pin(D6); // cs rdac
SPI spibus(SPI_MOSI, SPI_MISO, SPI_SCK);
#endif

#ifdef AD7791_PRESENT
AD7791 ad7791(1.2, D8);
AD7791_Diag ad7791diag(ad7791);
#endif

#ifdef CN0216_PRESENT
CN0216 cn0216;
CN0216_Diag cn0216diag(cn0216);
#endif


#ifdef AD7790_PRESENT
AD7790 ad7790(1.2, D8);
AD7790_Diag ad7790diag(ad7790);
#endif

#ifdef AD5270_PRESENT
AD5270 ad5270(D6, 20000);
AD5270_Diag ad5270diag(ad5270);
#endif

#ifdef  CN0357_PRESENT
CN0357 cn0357;
CN0357_Diag cn0357diag(cn0357);
#endif


#ifdef  ADXL362_PRESENT
ADXL362 adxl362(D9);
ADXL362_Diag adxl362diag(adxl362);
#endif


#ifdef  AD7124_PRESENT
AD7124 ad7124(D10);
AD7124_Diag ad7124diag(ad7124);
#endif

#ifdef CN0398_PRESENT
CN0398 cn0398(D10);
CN0398_Diag cn0398diag(cn0398);

#endif

#ifdef CN0397_PRESENT
CN0397 cn0397(D10);
CN0397_Diag cn0397diag(cn0397);
#endif

#ifdef CN0396_PRESENT
#include "AD5270_Diag.h"
CN0396 cn0396(D10, D6, D4);
CN0396_Diag cn0396diag(cn0396);
AD5270_Diag ad5270diag(cn0396.rdac);
#endif
