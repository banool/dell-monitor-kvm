/***

FILE:		UP_API.H
DESCR:		Declaration of function prototypes
VER:		1.2.0	6 Oct 2015 
COPYRIGHT:	Dell Inc.

***/
#ifndef _UP_API_H_
#define _UP_API_H_

#include "UP_DATA.h"

#ifdef __cplusplus
extern "C" {
#endif

EXPORT_API MONITOR_CODE Initialize					(void);
EXPORT_API MONITOR_CODE Shutdown					(void); 

/* MONITOR MANAGEMENT */
EXPORT_API MONITOR_CODE GetAvailableMonitors		(BYTE *pbCount); /* Returns number of monitors */
EXPORT_API MONITOR_CODE ConnectMonitor				(BYTE iID); /* Index of monitor to connect */
EXPORT_API MONITOR_CODE DisconnectMonitor			(void);
EXPORT_API MONITOR_CODE GetAssetTag					(BYTE *pbyAssetTag); /* Returns asset tag ID */
EXPORT_API MONITOR_CODE SetAssetTag					(BYTE *pbyAssetTag);
EXPORT_API MONITOR_CODE GetMonitorName(BYTE *pbyMonitorName); /* Returns monitor name */
EXPORT_API MONITOR_CODE GetMonitorSerialNumber		(BYTE *pbySerialNumber); /* Returns monitor serial number */
EXPORT_API MONITOR_CODE GetBacklightHours			(SWORD16 *ps16Val); /* Returns backlight hours */

/* POWER MANAGEMENT */
EXPORT_API MONITOR_CODE GetPowerState				(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetPowerState				(UBYTE u8Val); 
EXPORT_API MONITOR_CODE GetPowerLED					(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetPowerLED					(UBYTE u8Val); 
EXPORT_API MONITOR_CODE GetPowerUSB					(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetPowerUSB					(UBYTE u8Val); 
EXPORT_API MONITOR_CODE ResetPower					(void);

/* IMAGE MANAGEMENT */
EXPORT_API MONITOR_CODE GetBrightness				(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetBrightness				(UBYTE u8Val); 
EXPORT_API MONITOR_CODE GetContrast					(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetContrast					(UBYTE u8Val); 
EXPORT_API MONITOR_CODE GetDynamicContrast			(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetDynamicContrast			(UBYTE u8Val); 
EXPORT_API MONITOR_CODE GetAspectRatio				(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetAspectRatio				(UBYTE u8Val); 
EXPORT_API MONITOR_CODE GetSharpness				(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetSharpness				(UBYTE u8Val); 
EXPORT_API MONITOR_CODE GetResponseTime				(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetResponseTime				(UBYTE u8Val); 

/* COLOR MANAGEMENT */
EXPORT_API MONITOR_CODE GetSaturation				(UBYTE *pu8Val); /* Applicable to Movie/Game only */
EXPORT_API MONITOR_CODE SetSaturation				(UBYTE u8Val); /* Applicable to Movie/Game only */
EXPORT_API MONITOR_CODE GetHue						(UBYTE *pu8Val); /* Applicable to Movie/Game only */
EXPORT_API MONITOR_CODE SetHue						(UBYTE u8Val); /* Applicable to Movie/Game only */
EXPORT_API MONITOR_CODE GetColorTempCaps			(UWORD32 *pu32Val);
EXPORT_API MONITOR_CODE GetColorTemp				(UWORD32 *pu32Val);
EXPORT_API MONITOR_CODE SetColorTemp				(UWORD32 u32Val); 
EXPORT_API MONITOR_CODE GetColorSpaceCaps			(UWORD32 *pu32Val);
EXPORT_API MONITOR_CODE GetColorSpaceState			(UWORD32 *pu32Val);
EXPORT_API MONITOR_CODE SetColorSpaceState			(UWORD32 u32Val); 
EXPORT_API MONITOR_CODE GetInputColorFormat			(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetInputColorFormat			(UBYTE u8Val); 
EXPORT_API MONITOR_CODE GetColorPresetCaps			(UWORD32 *pu32Val);
EXPORT_API MONITOR_CODE GetColorPreset				(UWORD32 *pu32Val);
EXPORT_API MONITOR_CODE SetColorPreset				(UWORD32 u32Val); 
EXPORT_API MONITOR_CODE GetCustomColor				(UBYTE u8Val, UBYTE *pu8ValR, UBYTE *pu8ValG, UBYTE *pu8ValB, UBYTE *pu8ValC, UBYTE *pu8ValM, UBYTE *pu8ValY );
EXPORT_API MONITOR_CODE SetCustomColor				(UBYTE u8Val, UBYTE u8ValR, UBYTE u8ValG, UBYTE u8ValB, UBYTE u8ValC, UBYTE u8ValM, UBYTE u8ValY );
EXPORT_API MONITOR_CODE GetGammaMode				(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetGammaMode				(UBYTE u8Val); 
EXPORT_API MONITOR_CODE GetUniformityCompensation	(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetUniformityCompensation	(UBYTE u8Val); 
EXPORT_API MONITOR_CODE ResetColor					(void);

/* VIDEO INPUT MANAGEMENT */
EXPORT_API MONITOR_CODE GetAutoSelect				(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetAutoSelect				(UBYTE u8Val); 
EXPORT_API MONITOR_CODE GetVideoInputCaps			(UWORD32 *pu32Val);
EXPORT_API MONITOR_CODE GetVideoInput				(UWORD32 *pu32Val);
EXPORT_API MONITOR_CODE SetVideoInput				(UWORD32 u32Val); 

/* PIP/PBP MANAGEMENT */
EXPORT_API MONITOR_CODE GetPxPMode					(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetPxPMode					(UBYTE u8Val); 
EXPORT_API MONITOR_CODE GetPxPSubInput				(UWORD32 *pu32Val);
EXPORT_API MONITOR_CODE SetPxPSubInput				(UWORD32 pu32Val);
EXPORT_API MONITOR_CODE GetPxPLocation				(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetPxPLocation				(UBYTE u8Val); 

/* OSD MANAGEMENT */
EXPORT_API MONITOR_CODE GetOSDTransparency			(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetOSDTransparency			(UBYTE u8Val);
EXPORT_API MONITOR_CODE GetOSDLanguage				(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetOSDLanguage				(UBYTE u8Val);
EXPORT_API MONITOR_CODE GetOSDRotation				(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetOSDRotation				(UBYTE u8Val);
EXPORT_API MONITOR_CODE GetOSDTimer					(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetOSDTimer					(UBYTE u8Val);
EXPORT_API MONITOR_CODE GetOSDButtonLock			(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetOSDButtonLock			(UBYTE u8Val);
EXPORT_API MONITOR_CODE GetButtonSound				(UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetButtonSound				(UBYTE u8Val);
EXPORT_API MONITOR_CODE ResetOSD					(void);

/* SYSTEM MANAGEMENT */
EXPORT_API MONITOR_CODE GetVersionFirmware          (BYTE *pbyFirmwareVersion); /* Returns firmware version */
EXPORT_API MONITOR_CODE GetVersionSDK               (SWORD16 *ps16Val); /* Returns SDK version */
EXPORT_API MONITOR_CODE GetMST                      (UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetMST                      (UBYTE u8Val);
EXPORT_API MONITOR_CODE GetLCDConditioning          (UBYTE *pu8Val);
EXPORT_API MONITOR_CODE SetLCDConditioning			(UBYTE u8Val);
EXPORT_API MONITOR_CODE FactoryReset				(void);
EXPORT_API MONITOR_CODE SetDebugLevel				(UBYTE u8Val);

/* LUT MANAGEMENT */
EXPORT_API MONITOR_CODE GetCalibrationHours         (SWORD16 *ps16Val); /* Returns calibration hours */
EXPORT_API MONITOR_CODE SetLUT						(UWORD16 arrPreGamma[3][1025], UWORD16 arrPostGamma[3][1025], UWORD16 arrColorMatrix[9]);
EXPORT_API MONITOR_CODE SetColorControl				(UBYTE u8Val);
EXPORT_API MONITOR_CODE SetCalBrightness			(UBYTE u8Val);
EXPORT_API MONITOR_CODE GetCalBrightness			(UBYTE *pu8Val);

#ifdef __cplusplus
}
#endif

#endif
