/* 
 * THIS SOFTWARE IS SUBJECT TO COPYRIGHT PROTECTION AND IS OFFERED ONLY
 * PURSUANT TO THE 3DFX GLIDE GENERAL PUBLIC LICENSE. THERE IS NO RIGHT
 * TO USE THE GLIDE TRADEMARK WITHOUT PRIOR WRITTEN PERMISSION OF 3DFX
 * INTERACTIVE, INC. A COPY OF THIS LICENSE MAY BE OBTAINED FROM THE 
 * DISTRIBUTOR OR BY CONTACTING 3DFX INTERACTIVE INC(info@3dfx.com). 
 * THIS PROGRAM IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER 
 * EXPRESSED OR IMPLIED. SEE THE 3DFX GLIDE GENERAL PUBLIC LICENSE FOR A
 * FULL TEXT OF THE NON-WARRANTY PROVISIONS.  
 * 
 * USE, DUPLICATION OR DISCLOSURE BY THE GOVERNMENT IS SUBJECT TO
 * RESTRICTIONS AS SET FORTH IN SUBDIVISION (C)(1)(II) OF THE RIGHTS IN
 * TECHNICAL DATA AND COMPUTER SOFTWARE CLAUSE AT DFARS 252.227-7013,
 * AND/OR IN SIMILAR OR SUCCESSOR CLAUSES IN THE FAR, DOD OR NASA FAR
 * SUPPLEMENT. UNPUBLISHED RIGHTS RESERVED UNDER THE COPYRIGHT LAWS OF
 * THE UNITED STATES.  
 * 
 * COPYRIGHT 3DFX INTERACTIVE, INC. 1999, ALL RIGHTS RESERVED
 */

#ifndef _FXOS2_H_
#define _FXOS2_H_

#ifdef __cplusplus
extern "C" {
#endif

FxBool
hasDev3DfxOS2(void);

FxBool
pciCloseOS2( void );

FxBool 
pciMapPhysicalToLinearOS2( FxU32 *linear_addr, FxU32 physical_addr,
			FxU32 *length );
void 
pciUnmapPhysicalOS2( FxU32 linear_addr, FxU32 length );

int
getNumDevicesOS2(void);

FxU32
pciFetchRegisterOS2( FxU32 cmd, FxU32 size, FxU32 device);

int
pciUpdateRegisterOS2(FxU32 cmd, FxU32 data, FxU32 size, FxU32 device);

#ifdef __cplusplus
}
#endif

#endif
