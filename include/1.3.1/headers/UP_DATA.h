/***

FILE:		UP_DATA.H
DESCR:		Declaration of typedefs, structures & etc.
VER:		1.3.1     27 Apr 2016
COPYRIGHT:	Dell Inc.

***/

#ifndef __UP_DATA_H__
#define __UP_DATA_H__

#ifdef _WIN32
	#include <windows.h>
#endif

#ifdef _WIN32
	#define EXPORT_API 		__declspec(dllexport) 
#elif linux || defined __APPLE__
	#define EXPORT_API 		__attribute__((visibility("default"))) 
#endif

#if defined linux || defined __APPLE__
	typedef unsigned char		BYTE;
	typedef unsigned char 		BOOL;
	#define PBYTE				BYTE*
#endif

typedef unsigned char		UBYTE;
typedef unsigned short    	UWORD16;
typedef unsigned int		UWORD32;
typedef signed short		SWORD16;
typedef signed int			SWORD32;

#define TRUE				1
#define FALSE				0

/* RETURN CODES */
typedef enum 
{
	MONITOR_SUCCESS			= 0,	/* Function returns successfully */
	MONITOR_FAILURE			= -1,	/* General failure */
	MONITOR_ERR_TIMEOUT		= 1,	/* Function times out */
	MONITOR_ERR_PARAMS		= 2,	/* Errors in parameters, out of range, invalid or unsupported modes */
	MONITOR_ERR_CONNECT		= 3,	/* Errors in connecting to monitor */
	MONITOR_ERR_COMMS		= 4,	/* Errors in communicating with monitor */
	MONITOR_ERR_STATE		= 5,	/* Monitor in wrong state for API call */
	MONITOR_ERR_NOSUPPORT	= 6		/* Monitor does not support this API call */
}
MONITOR_CODE;  

/* POWER MANAGEMENT */
typedef enum
{
	POWER_STATE_OFF     = 0,
	POWER_STATE_ON      = 1,
	POWER_STATE_STANDBY = 2
}
POWER_STATE; 

typedef enum
{
	POWER_LED_OFF = 0,
	POWER_LED_ON  = 1
}
POWER_LED;

typedef enum
{
	POWER_USB_OFF = 0,
	POWER_USB_ON  = 1
}
POWER_USB;

/* IMAGE MANAGEMENT */
typedef enum
{
	ASPECT_RATIO_WIDE = 0,
	ASPECT_RATIO_AUTO = 1,
	ASPECT_RATIO_4X3  = 2,
	ASPECT_RATIO_1X1  = 3
}
ASPECT_RATIO;

typedef enum
{
	RESPONSE_TIME_NORMAL = 0,
	RESPONSE_TIME_FAST   = 1
}
RESPONSE_TIME;

/* COLOR MANAGEMENT */
typedef enum
{
	COLOR_TEMP_5000K  = 0x00000001,
	COLOR_TEMP_5700K  = 0x00000002,
	COLOR_TEMP_6500K  = 0x00000004,
	COLOR_TEMP_7500K  = 0x00000008,
	COLOR_TEMP_9300K  = 0x00000010, 
	COLOR_TEMP_10000K = 0x00000020
}
COLOR_TEMP;

typedef enum
{
	COLOR_SPACE_ADOBE_RGB = 0x00000001,
	COLOR_SPACE_SRGB	  = 0x00000002,
	COLOR_SPACE_REC_709   = 0x00000004,
	COLOR_SPACE_DCI_P3	  = 0x00000008, 
	COLOR_SPACE_CAL_1	  = 0x00000010,
	COLOR_SPACE_CAL_2	  = 0x00000020
}
COLOR_SPACE;

typedef enum
{
	INPUT_COLOR_FORMAT_RGB   = 0,
	INPUT_COLOR_FORMAT_YPBPR = 1
}
INPUT_COLOR_FORMAT;

typedef enum
{
	COLOR_PRESET_STANDARD     = 0x00000001,
	COLOR_PRESET_MULTIMEDIA   = 0x00000002,
	COLOR_PRESET_MOVIE        = 0x00000004,
	COLOR_PRESET_GAME         = 0x00000008,
	COLOR_PRESET_PAPER        = 0x00000010,
	COLOR_PRESET_COLOR_TEMP   = 0x00000020,
	COLOR_PRESET_COLOR_SPACE  = 0x00000040,
	COLOR_PRESET_CUSTOM_COLOR = 0x00000080,
	COLOR_PRESET_DICOM        = 0x00000100,
	COLOR_PRESET_COMFORTVIEW  = 0x00000200,
	COLOR_PRESET_WARM         = 0x00000400,
	COLOR_PRESET_COOL         = 0x00000800,
	COLOR_PRESET_SRGB         = 0x00001000,
	COLOR_PRESET_GAME_FPS     = 0x00002000,
	COLOR_PRESET_GAME_RTS     = 0x00004000,
	COLOR_PRESET_GAME_RPG     = 0x00008000
}
COLOR_PRESET;

typedef enum
{
	CUSTOM_COLOR_GAIN       = 0, /* RGB (0..100) */
	CUSTOM_COLOR_OFFSET     = 1, /* RGB (0..100) */
	CUSTOM_COLOR_HUE        = 2, /* RGB (0..100), CMY (0..100) */
	CUSTOM_COLOR_SATURATION = 3  /* RGB (0..100), CMY (0..100) */
}
CUSTOM_COLOR;

typedef enum
{
	GAMMA_MODE_PC  = 0,
	GAMMA_MODE_MAC = 1
}
GAMMA_MODE;

typedef enum
{
	UNIFORMITY_COMPESNATION_OFF             = 0,
	UNIFORMITY_COMPESNATION_CALIBRATED_HIGH = 2
}
UNIFORMITY_COMPENSATION;

typedef enum
{
	DYNAMIC_CONTRAST_OFF = 0,
	DYNAMIC_CONTRAST_ON  = 1
}
DYNAMIC_CONTRAST;

/* LUT MANAGEMENT */
typedef enum
{
	COLOR_CONTROL_DISABLE = 0,
	COLOR_CONTROL_ENABLE  = 1
}
COLOR_CONTROL;

/* VIDEO INPUT MANAGEMENT */
typedef enum
{
	AUTO_SELECT_OFF	= 0,
	AUTO_SELECT_ON	= 1
}
AUTO_SELECT;

typedef enum
{
	VIDEO_INPUT_HDMI1 = 0x0000001,
	VIDEO_INPUT_HDMI2 = 0x0000002,
	VIDEO_INPUT_HDMI3 = 0x0000004, 
	VIDEO_INPUT_DP1   = 0x0000008,
	VIDEO_INPUT_DP2   = 0x0000010,
	VIDEO_INPUT_DP3   = 0x0000020,
	VIDEO_INPUT_VGA1  = 0x0000040,
	VIDEO_INPUT_VGA2  = 0x0000080,
	VIDEO_INPUT_DVI1  = 0x0000100,
	VIDEO_INPUT_DVI2  = 0x0000200
}
VIDEO_INPUT;

/* PIP/PBP MANAGEMENT */
typedef enum
{
	PXP_OFF              = 0,
	PXP_PIP_SMALL        = 1,
	PXP_PIP_LARGE        = 2,
	PXP_PBP_ASPECT_RATIO = 3,
	PXP_PBP_FILL         = 4
}
PXP_MODE;

typedef enum
{
	PXP_PIP_LOCATION_TOP_RIGHT    = 0,
	PXP_PIP_LOCATION_TOP_LEFT     = 1,
	PXP_PIP_LOCATION_BOTTOM_RIGHT = 2,
	PXP_PIP_LOCATION_BOTTOM_LEFT  = 3
}
PXP_PIP_LOCATION;

/* OSD MANAGEMENT */
typedef enum
{
	OSD_LANGUAGE_ENGLISH			= 0,
	OSD_LANGUAGE_ESPANOL			= 1,
	OSD_LANGUAGE_FRANCAIS			= 2,
	OSD_LANGUAGE_DEUTSCH			= 3,
	OSD_LANGUAGE_PORTUGUES_BRASIL   = 4,
	OSD_LANGUAGE_PYCCKNN			= 5,
	OSD_LANGUAGE_CHINESE_SIMPLIFIED = 6,
	OSD_LANGUAGE_JAPANESE			= 7
}
OSD_LANGUAGE;

typedef enum
{
	OSD_ROTATION_0   = 0, /* 0 Degrees */
	OSD_ROTATION_90  = 1, /* 90 degrees */
	OSD_ROTATION_270 = 2, /* 270 degrees */
	OSD_ROTATION_180 = 3  /* 180 degrees */
}
OSD_ROTATION;

typedef enum
{
	OSD_BUTTON_UNLOCK = 0,
	OSD_BUTTON_LOCK	  = 1
}
OSD_BUTTON;

typedef enum
{
	OSD_SOUND_OFF = 0,
	OSD_SOUND_ON  = 1
}
OSD_SOUND;

/* SYSTEM MANAGEMENT */
typedef enum
{
	LCD_CONDITIONING_OFF = 0,
	LCD_CONDITIONING_ON  = 1
}
LCD_CONDITIONING;

typedef enum
{
	MST_OFF		= 0,
	MST_ON		= 1
}
MST;

typedef enum
{
	DB_OFF   = 0,
	DB_ERROR = 1,
	DB_WARN  = 2,
	DB_DEBUG = 3,
	DB_TRACE = 4
}
DBLEVEL;

#endif /*__UP_DATA_H__ */
