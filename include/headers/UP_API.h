/***

FILE:		UP_API.H
DESCR:		Declaration of function prototypes
VER:		3.0.0
COPYRIGHT:	Dell Inc.

***/
#ifndef _UP_API_H_
#define _UP_API_H_

#include "UP_DATA.h"

#ifdef __cplusplus
extern "C" {
#endif

EXPORT_API MONITOR_CODE Initialize					(void); /* Initailize the SDK for use */
EXPORT_API MONITOR_CODE Shutdown					(void); /* Shutdown the SDK after use */

/* MONITOR MANAGEMENT */
EXPORT_API MONITOR_CODE GetAvailableMonitors		(BYTE *pu8Val);          /* Number of connected and supported monitor */
EXPORT_API MONITOR_CODE ConnectMonitor              (BYTE u8Val);            /* Index of monitor to connect (0-indexed) */
EXPORT_API MONITOR_CODE ConnectMonitorByServiceTag	(BYTE *serviceTag);      /* Service tag of monitor to connect*/
EXPORT_API MONITOR_CODE DisconnectMonitor           (void);                  /* Disconnect current connected monitor */
EXPORT_API MONITOR_CODE GetAssetTag					(BYTE *pbyAssetTag);     /* max len = 10 */
EXPORT_API MONITOR_CODE SetAssetTag					(BYTE *pbyAssetTag);     /* max len = 10 */
EXPORT_API MONITOR_CODE GetMonitorName              (BYTE *pbyMonitorName);  /* max len = 10 */
EXPORT_API MONITOR_CODE GetMonitorSerialNumber		(BYTE *pbySerialNumber); /* max len = 12 */
EXPORT_API MONITOR_CODE GetBacklightHours           (UWORD16 *pu16Val);      /* return number of hours */
EXPORT_API MONITOR_CODE GetServiceTag               (BYTE *pbyServiceTag);   /* max len = 7 */
EXPORT_API MONITOR_CODE GetAvailableMonitorsDetail  (BYTE *pu8Count, MonitorDetailStructType **arrMonitorDetail); /* Returns count and array of monitors with details */
EXPORT_API MONITOR_CODE IdentifyMonitor             (void);                  /* enumerate supported monitors and display monitor index (1-indexed instead of 0-indexed) */

/* POWER MANAGEMENT */
EXPORT_API MONITOR_CODE GetPowerState               (BYTE *pu8Val); /* enum POWER_STATE */
EXPORT_API MONITOR_CODE SetPowerState				(BYTE u8Val);   /* enum POWER_STATE */
EXPORT_API MONITOR_CODE GetPowerLED                 (BYTE *pu8Val); /* ON | OFF */
EXPORT_API MONITOR_CODE SetPowerLED					(BYTE u8Val);   /* ON | OFF */
EXPORT_API MONITOR_CODE GetPowerUSB                 (BYTE *pu8Val); /* enum POWER_USB */
EXPORT_API MONITOR_CODE SetPowerUSB					(BYTE u8Val);   /* enum POWER_USB */
EXPORT_API MONITOR_CODE GetPowerTBT                 (BYTE *pu8Val); /* enum POWER_TBT */
EXPORT_API MONITOR_CODE SetPowerTBT                 (BYTE u8Val);   /* enum POWER_TBT */

/* IMAGE MANAGEMENT */
EXPORT_API MONITOR_CODE GetBrightness               (BYTE *pu8Val); /* 0-100 Not valid for UP2720Q */ 
EXPORT_API MONITOR_CODE SetBrightness				(BYTE u8Val);   /* 0-100 Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetContrast					(BYTE *pu8Val); /* 0-100 Not valid for UP2720Q */
EXPORT_API MONITOR_CODE SetContrast					(BYTE u8Val);   /* 0-100 Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetDynamicContrast          (BYTE *pu8Val); /* ON | OFF Not valid for UP2720Q */
EXPORT_API MONITOR_CODE SetDynamicContrast			(BYTE u8Val);   /* ON | OFF Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetAspectRatio              (BYTE *pu8Val); /* enum ASPECT_RATIO */
EXPORT_API MONITOR_CODE SetAspectRatio				(BYTE u8Val);   /* enum ASPECT_RATIO */
EXPORT_API MONITOR_CODE GetSharpness                (BYTE *pu8Val); /* 0, 10, 20, 30, 40, 50, 60, 70, 80, 100 */
EXPORT_API MONITOR_CODE SetSharpness				(BYTE u8Val);   /* 0, 10, 20, 30, 40, 50, 60, 70, 80, 100 */
EXPORT_API MONITOR_CODE GetResponseTime             (BYTE *pu8Val); /* enum RESPONSE_TIME Not valid for UP2720Q */
EXPORT_API MONITOR_CODE SetResponseTime				(BYTE u8Val);   /* enum RESPONSE_TIME Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetHDR                      (BYTE *pu8Val); /* enum HDR Not valid for UP2720Q */
EXPORT_API MONITOR_CODE SetHDR                      (BYTE u8Val);   /* enum HDR Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetDCIMasking				(BYTE *pu8Mask, BYTE *pu8Opacity); /* Mask: enum DCI_MASKING | Opacity: 0, 20, 40, 60, 80, 100 */
EXPORT_API MONITOR_CODE SetDCIMasking				(BYTE u8Mask, BYTE u8Opacity);     /* Mask: enum DCI_MASKING | Opacity: 0, 20, 40, 60, 80, 100 */
EXPORT_API MONITOR_CODE GetMarkers                  (BYTE *pu8Val); /* enum MARKERS */
EXPORT_API MONITOR_CODE SetMarkers					(BYTE u8Val);   /* enum MARKERS */
EXPORT_API MONITOR_CODE GetMarkersColor             (BYTE *pu8Val); /* enum MARKERS_COLOR */
EXPORT_API MONITOR_CODE SetMarkersColor				(BYTE u8Val);   /* enum MARKERS_COLOR */
EXPORT_API MONITOR_CODE GetVideoDataRange           (BYTE *pu8Val); /* enum VIDEO_DATA_RANGE */
EXPORT_API MONITOR_CODE SetVideoDataRange			(BYTE u8Val);   /* enum VIDEO_DATA_RANGE */
EXPORT_API MONITOR_CODE GetOverscanFrame			(BYTE *pu8Val); /* ON | OFF */
EXPORT_API MONITOR_CODE SetOverscanFrame			(BYTE u8Val);   /* ON | OFF */
EXPORT_API MONITOR_CODE GetBlueChannelOnly			(BYTE *pu8Val); /* ON | OFF */
EXPORT_API MONITOR_CODE SetBlueChannelOnly			(BYTE u8Val);   /* ON | OFF */

/* COLOR MANAGEMENT */
EXPORT_API MONITOR_CODE GetSaturation				(BYTE *pu8Val);     /* 0-100 */
EXPORT_API MONITOR_CODE SetSaturation				(BYTE u8Val);       /* 0-100 */
EXPORT_API MONITOR_CODE GetHue						(BYTE *pu8Val);     /* 0-100 */
EXPORT_API MONITOR_CODE SetHue						(BYTE u8Val);       /* 0-100 */
EXPORT_API MONITOR_CODE GetColorTempCaps            (UWORD32 *pu32Val); /* enum COLOR_TEMP, bitwise OR-ed. Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetColorTemp				(UWORD32 *pu32Val); /* enum COLOR_TEMP Not valid for UP2720Q */
EXPORT_API MONITOR_CODE SetColorTemp				(UWORD32 u32Val);   /* enum COLOR_TEMP Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetColorSpaceCaps			(UWORD32 *pu32Val); /* enum COLOR_SPACE, bitwise OR-ed */
EXPORT_API MONITOR_CODE GetColorSpaceState          (UWORD32 *pu32Val); /* enum COLOR_SPACE */
EXPORT_API MONITOR_CODE SetColorSpaceState			(UWORD32 u32Val);   /* enum COLOR_SPACE */
EXPORT_API MONITOR_CODE GetInputColorFormat         (BYTE *pu8Val);     /* enum INPUT_COLOR_FORMAT Not valid for UP2720Q */
EXPORT_API MONITOR_CODE SetInputColorFormat			(BYTE u8Val);       /* enum INPUT_COLOR_FORMAT Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetColorPresetCaps          (UWORD32 *pu32Val); /* enum COLOR_PRESET, bitwise OR-ed. Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetColorPreset              (UWORD32 *pu32Val); /* enum COLOR_PRESET Not valid for UP2720Q */
EXPORT_API MONITOR_CODE SetColorPreset				(UWORD32 u32Val);   /* enum COLOR_PRESET Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetCustomColor              (BYTE u8Setting, BYTE *pu8ValR, BYTE *pu8ValG, BYTE *pu8ValB, BYTE *pu8ValC, BYTE *pu8ValM, BYTE *pu8ValY); /* Setting: enum CUSTOM_COLOR | ValRGBCMY: 0-100 */
EXPORT_API MONITOR_CODE SetCustomColor              (BYTE u8Setting, BYTE u8ValR, BYTE u8ValG, BYTE u8ValB, BYTE u8ValC, BYTE u8ValM, BYTE u8ValY);             /* Setting: enum CUSTOM_COLOR | ValRGBCMY: 0-100 */
EXPORT_API MONITOR_CODE GetGammaMode                (BYTE *pu8Val);     /* enum GAMMA_MODE Not valid for UP2720Q */
EXPORT_API MONITOR_CODE SetGammaMode                (BYTE u8Val);       /*enum GAMMA_MODE Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetUniformityCompensation   (BYTE *pu8Val);     /* enum UNIFORMITY_COMPENSATION */
EXPORT_API MONITOR_CODE SetUniformityCompensation	(BYTE u8Val);       /* enum UNIFORMITY_COMPENSATION */
EXPORT_API MONITOR_CODE GetColorSpaceInfo			(ColorSpaceInfoStructType *pData); /* set pData->ColorSpaceMode before passing structure to retrieve info */
EXPORT_API MONITOR_CODE SetColorSpaceInfo           (ColorSpaceInfoStructType *pData);
EXPORT_API MONITOR_CODE GetColorGamut               (UWORD32 *pu32Val); /* enum COLOR_GAMUT */
EXPORT_API MONITOR_CODE SetColorGamut				(UWORD32 u32Val);   /* enum COLOR_GAMUT */
EXPORT_API MONITOR_CODE GetWhitePoint               (BYTE *pu8Val);     /* enum WHITE_POINT */
EXPORT_API MONITOR_CODE SetWhitePoint				(BYTE u8Val);       /* enum WHITE_POINT */
EXPORT_API MONITOR_CODE GetGamma                    (BYTE *pu8Val);     /* enum GAMMA */
EXPORT_API MONITOR_CODE SetGamma					(BYTE u8Val);       /* enum GAMMA */
EXPORT_API MONITOR_CODE GetLuminance                (UWORD16 *pu16Val); /* UP2720Q: 45-250 */
EXPORT_API MONITOR_CODE SetLuminance				(UWORD16 u16Val);   /* UP2720Q: 45-250 */
EXPORT_API MONITOR_CODE GetCustomColorSpaceInfo		(CustomColorSpaceInfoStructType *pData); /* set pData->CustomColorSpace before passing structure to retrieve info */
EXPORT_API MONITOR_CODE ResetColor					(void);				/* Reset current color space */

/* VIDEO INPUT MANAGEMENT */
EXPORT_API MONITOR_CODE GetAutoSelect               (BYTE *pu8Val);     /* enum AUTO_SELECT */
EXPORT_API MONITOR_CODE SetAutoSelect				(BYTE u8Val);       /* enum AUTO_SELECT */
EXPORT_API MONITOR_CODE GetVideoInputCaps           (UWORD32 *pu32Val); /* enum VIDEO_INPUT, bitwise OR-ed */
EXPORT_API MONITOR_CODE GetVideoInput               (UWORD32 *pu32Val); /* enum VIDEO_INPUT */
EXPORT_API MONITOR_CODE SetVideoInput				(UWORD32 u32Val);   /* enum VIDEO_INPUT */
EXPORT_API MONITOR_CODE GetVideoInputName           (UWORD32 u32VideoInput, BYTE *pu8Name); /* VideoInput: enum VIDEO_INPUT | Name: enum VIDEO_INPUT_NAME */
EXPORT_API MONITOR_CODE SetVideoInputName			(UWORD32 u32VideoInput, BYTE u8Name);   /* VideoInput: enum VIDEO_INPUT | Name: enum VIDEO_INPUT_NAME */
EXPORT_API MONITOR_CODE GetAutoSelectTbt            (BYTE *pu8Val);     /* enum AUTO_SELECT */
EXPORT_API MONITOR_CODE SetAutoSelectTbt            (BYTE u8Val);       /* enum AUTO_SELECT */

/* PIP/PBP MANAGEMENT */
EXPORT_API MONITOR_CODE GetPxPMode                  (BYTE *pu8Val);     /* enum PXP_MODE */
EXPORT_API MONITOR_CODE SetPxPMode					(BYTE u8Val);       /* enum PXP_MODE */
EXPORT_API MONITOR_CODE GetPxPSubInput				(UWORD32 *pu32Val); /* enum VIDEO_INPUT */
EXPORT_API MONITOR_CODE SetPxPSubInput				(UWORD32 u32Val);   /* enum VIDEO_INPUT */
EXPORT_API MONITOR_CODE GetPxPLocation              (BYTE *pu8Val);     /* enum PXP_PIP_LOCATION Not valid for UP2720Q */
EXPORT_API MONITOR_CODE SetPxPLocation				(BYTE u8Val);       /* enum PXP_PIP_LOCATION Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetPxPColorGamut            (UWORD32 *pu32Val); /* enum COLOR_GAMUT */
EXPORT_API MONITOR_CODE SetPxPColorGamut            (UWORD32 u32Val);   /* enum COLOR_GAMUT */
EXPORT_API MONITOR_CODE GetPxPColorGamma			(BYTE *pu8Val);     /* enum GAMMA */
EXPORT_API MONITOR_CODE SetPxPColorGamma			(BYTE u8Val);       /* enum GAMMA */
EXPORT_API MONITOR_CODE GetPxPWhitePoint            (BYTE *pu8Val);     /* enum WHITE_POINT */
EXPORT_API MONITOR_CODE SetPxPWhitePoint            (BYTE u8Val);       /* enum WHITE_POINT */
EXPORT_API MONITOR_CODE GetPxPSharpness             (BYTE *pu8Val);     /* 0, 10, 20, 30, 40, 50, 60, 70, 80, 100 */
EXPORT_API MONITOR_CODE SetPxPSharpness				(BYTE u8Val);       /* 0, 10, 20, 30, 40, 50, 60, 70, 80, 100 */
EXPORT_API MONITOR_CODE GetPxPAudio                 (BYTE *pu8Val);     /* enum AUDIO_SOURCE */
EXPORT_API MONITOR_CODE SetPxPAudio					(BYTE u8Val);       /* enum AUDIO_SOURCE */
EXPORT_API MONITOR_CODE GetPxPVideoRange            (BYTE *pu8Val);     /* enum VIDEO_DATA_RANGE */
EXPORT_API MONITOR_CODE SetPxPVideoRange			(BYTE u8Val);       /* enum VIDEO_DATA_RANGE */
EXPORT_API MONITOR_CODE PxPInputToggle				(void);
EXPORT_API MONITOR_CODE PxPVideoSwap				(void);

/* OSD MANAGEMENT */
EXPORT_API MONITOR_CODE GetOSDTransparency          (BYTE *pu8Val); /*  0, 20, 40, 60, 80, 100 */
EXPORT_API MONITOR_CODE SetOSDTransparency			(BYTE u8Val);   /*  0, 20, 40, 60, 80, 100 */
EXPORT_API MONITOR_CODE GetOSDLanguage              (BYTE *pu8Val); /* enum OSD_LANGUAGE */
EXPORT_API MONITOR_CODE SetOSDLanguage				(BYTE u8Val);   /* enum OSD_LANGUAGE */
EXPORT_API MONITOR_CODE GetOSDRotation              (BYTE *pu8Val); /* enum OSD_ROTATION */
EXPORT_API MONITOR_CODE SetOSDRotation				(BYTE u8Val);   /* enum OSD_ROTATION */
EXPORT_API MONITOR_CODE GetOSDTimer                 (BYTE *pu8Val); /* 5-60 seconds */
EXPORT_API MONITOR_CODE SetOSDTimer					(BYTE u8Val);   /* 5-60 seconds */
EXPORT_API MONITOR_CODE GetOSDButtonLock            (BYTE *pu8Val); /* enum OSD_BUTTON */
EXPORT_API MONITOR_CODE SetOSDButtonLock			(BYTE u8Val);   /* enum OSD_BUTTON */
EXPORT_API MONITOR_CODE GetButtonSound              (BYTE *pu8Val); /* ON | OFF Not valid for UP2720Q */
EXPORT_API MONITOR_CODE SetButtonSound				(BYTE u8Val);   /* ON | OFF Not valid for UP2720Q */

/* SYSTEM MANAGEMENT */
EXPORT_API MONITOR_CODE GetVersionFirmware          (BYTE *pbyFirmwareVersion); /* max len = 10 */
EXPORT_API MONITOR_CODE GetVersionSDK               (UWORD16 *pu16Val); 
EXPORT_API MONITOR_CODE GetMST                      (BYTE *pu8Val);             /* ON | OFF Not valid for UP2720Q */
EXPORT_API MONITOR_CODE SetMST                      (BYTE u8Val);               /* ON | OFF Not valid for UP2720Q */
EXPORT_API MONITOR_CODE GetLCDConditioning          (BYTE *pu8Val);             /* ON | OFF */
EXPORT_API MONITOR_CODE SetLCDConditioning			(BYTE u8Val);               /* ON | OFF */
EXPORT_API MONITOR_CODE FactoryReset				(void);
EXPORT_API MONITOR_CODE SetDebugLevel               (BYTE u8Val);               /* enum DBLEVEL */
EXPORT_API MONITOR_CODE KeepAlive                   (void);                     /* Session expires in 5 mins if there are no activity. KeepAlive needs to be sent to monitor to keep session alive. */
EXPORT_API MONITOR_CODE GetDateTime					(struct tm *pData); 
EXPORT_API MONITOR_CODE SetDateTime					(struct tm *pData);
EXPORT_API MONITOR_CODE GetAutoSleep                (BYTE *pu8Val);             /* enum AUTO_SLEEP */
EXPORT_API MONITOR_CODE SetAutoSleep				(BYTE u8Val);               /* enum AUTO_SLEEP */
EXPORT_API MONITOR_CODE GetWarmUpTime               (BYTE *pu8Val, BYTE *pu8Day, BYTE *pu8Hour, BYTE *pu8Min); /* Val: ON|OFF | Day: enum DAY_SELECTION | Hour: 0-23 | Min: 0-59 */
EXPORT_API MONITOR_CODE SetWarmUpTime               (BYTE u8Val, BYTE u8Day, BYTE u8Hour, BYTE u8Min);         /* Val: ON|OFF | Day: enum DAY_SELECTION | Hour: 0-23 | Min: 0-59 */
EXPORT_API MONITOR_CODE GetSoftwareLock             (BYTE *pu8Val);             /* enum SOFTWARE_LOCK */
EXPORT_API MONITOR_CODE SetSoftwareLock             (BYTE u8Val);               /* enum SOFTWARE_LOCK */
EXPORT_API MONITOR_CODE ResetMenu                   (BYTE u8Val);               /* enum RESET_MENU */

/* CALIBRATION VALIDATION - OSD */
EXPORT_API MONITOR_CODE GetCalibrationTarget		(UWORD32 *pu32Val); /* enum COLOR_SPACE, bitwise OR-ed */
EXPORT_API MONITOR_CODE SetCalibrationTarget		(UWORD32 u32Val);   /* enum COLOR_SPACE, bitwise OR-ed */
EXPORT_API MONITOR_CODE GetCalibrationSpeed         (BYTE *pu8Val);     /* enum CALIBRATION_SPEED */
EXPORT_API MONITOR_CODE SetCalibrationSpeed			(BYTE u8Val);       /* enum CALIBRATION_SPEED */
EXPORT_API MONITOR_CODE GetCalibrationWarmUp        (BYTE *pu8Val);     /* 20, 30 mins */
EXPORT_API MONITOR_CODE SetCalibrationWarmUp		(BYTE u8Val);       /* 20, 30 mins */
EXPORT_API MONITOR_CODE GetColorimeterProfile       (BYTE *pu8Val);     /* enum COLORIMETER_PROFILE */
EXPORT_API MONITOR_CODE SetColorimeterProfile		(BYTE u8Val);       /* enum COLORIMETER_PROFILE */
EXPORT_API MONITOR_CODE GetCalibrationResult        (UWORD32 u32ColorSpaceMode, CalibrationResultStructType *pData); /* ColorSpaceMode: enum COLOR_SPACE_MODE */
EXPORT_API MONITOR_CODE StartCalibration			(void);
EXPORT_API MONITOR_CODE GetValidationTarget         (UWORD32 *pu32Val); /* enum COLOR_SPACE, bitwise OR-ed */
EXPORT_API MONITOR_CODE SetValidationTarget			(UWORD32 u32Val);   /* enum COLOR_SPACE, bitwise OR-ed */
EXPORT_API MONITOR_CODE GetAutoCalibrate            (BYTE *pu8Val);     /* ON | OFF */
EXPORT_API MONITOR_CODE SetAutoCalibrate			(BYTE u8Val);       /* ON | OFF */
EXPORT_API MONITOR_CODE GetValidationPattern        (BYTE *pu8Val);     /* enum VALIDATION_PATTERN */
EXPORT_API MONITOR_CODE SetValidationPattern        (BYTE u8Val);       /* enum VALIDATION_PATTERN */
EXPORT_API MONITOR_CODE GetValidationResult         (UWORD32 u32ColorSpaceMode, ValidationResultStructType *pData); /* ColorSpaceMode: enum COLOR_SPACE_MODE */
EXPORT_API MONITOR_CODE StartValidation				(void);
EXPORT_API MONITOR_CODE GetCalibrationModulePowerState   (BYTE *pu8Val);  /* ON | OFF */
EXPORT_API MONITOR_CODE SetCalibrationModulePowerState   (BYTE u8Val);    /* ON | OFF */
EXPORT_API MONITOR_CODE GetCalibrationValidationProgress (BYTE *pu8Val);  /* 0: Not in calibration/validation/setCorrelatedProfile | 1: In calibration/validation/setCorrelatedProfile */
EXPORT_API MONITOR_CODE AbortCalibrationValidation  (void);
EXPORT_API MONITOR_CODE GetCalibrationTargetInfo	(CalibrationTargetInfoStructType *pData); /* set pData-> ColorSpace before passing structure to retrieve info */
EXPORT_API MONITOR_CODE SetCalibrationTargetInfo	(CalibrationTargetInfoStructType *pData);

/* SCHEDULER */
EXPORT_API MONITOR_CODE GetCalValScheduler          (BYTE *pu8Val); /* enum CALVALSCHEDULER */
EXPORT_API MONITOR_CODE SetCalValScheduler			(BYTE u8Val);   /* enum CALVALSCHEDULER */
EXPORT_API MONITOR_CODE GetCalValSchedule           (BYTE *pu8Type, UWORD32 *pu32UsageQuarter, UWORD32 *pu32Week, UWORD32 *pu32Day, BYTE *pu8Hr, BYTE *pu8Min); /* Type: enum CALVALSCHEDULE_TYPE | UsageQuarter: backlight_hrs|enum CALVALSCHEDULE_QUARTER | Week: enum CALVALSCHEDULE_WEEK | Day: enum CALVALSCHEDULE_DAY | Hour: 0-23 | Min: 0-59 */
EXPORT_API MONITOR_CODE SetCalValSchedule           (BYTE pu8Type, UWORD32 pu32UsageQuarter, UWORD32 pu32Week, UWORD32 pu32Day, BYTE pu8Hr, BYTE pu8Min);       /* Type: enum CALVALSCHEDULE_TYPE | UsageQuarter: backlight_hrs|enum CALVALSCHEDULE_QUARTER | Week: enum CALVALSCHEDULE_WEEK | Day: enum CALVALSCHEDULE_DAY | Hour: 0-23 | Min: 0-59 */
EXPORT_API MONITOR_CODE GetCalValOpMode             (BYTE *pu8Val); /* enum CALVALSCHEDULER_OP_MODE */
EXPORT_API MONITOR_CODE SetCalValOpMode				(BYTE u8Val);   /* enum CALVALSCHEDULER_OP_MODE */

/* DECREPATED since SDK 3.0 */ 
EXPORT_API MONITOR_CODE ResetPower					(void); //use ResetMenu
EXPORT_API MONITOR_CODE ResetOSD					(void); //use ResetMenu

#ifdef __cplusplus
}
#endif

#endif
