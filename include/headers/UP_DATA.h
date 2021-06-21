/***

FILE:		UP_DATA.H
DESCR:		Declaration of typedefs, structures & etc.
VER:		3.0.0	18 Feb 2019
COPYRIGHT:	Dell Inc.

***/

#ifndef __UP_DATA_H__
#define __UP_DATA_H__

#ifdef _WIN32
	#include <windows.h>
	typedef unsigned short	UWORD16;
	typedef unsigned int	UWORD32;
#endif

#if defined __linux__ || defined __APPLE__
	#include <stdint.h>
	typedef unsigned char	BYTE;
	typedef BYTE*			LPBYTE;
	typedef uint8_t 		BOOL;
	typedef uint16_t    	UWORD16;
	typedef uint32_t		UWORD32;
	typedef float			FLOAT;
#endif

#ifdef _WIN32
	#define EXPORT_API 		__declspec(dllexport) 
#elif __linux__ || defined __APPLE__
	#define EXPORT_API 		__attribute__((visibility("default"))) 
#endif

#define FALSE				0
#define TRUE				1
#define OFF					0
#define ON					1

#define MAX_MONITOR_NAME_LEN 10
#define MAX_ASSET_TAG_LEN    10
#define MAX_SERIAL_NUM_LEN   12
#define MAX_SERVICE_TAG_LEN  7
#define MAX_FIRMWARE_VER_LEN 10

/* RETURN CODES */
typedef enum monitor_code
{
	MONITOR_SUCCESS			 = 0,	/* Function returns successfully */
	MONITOR_FAILURE			 = -1,	/* General failure */
	MONITOR_ERR_TIMEOUT		 = 1,	/* Function times out */
	MONITOR_ERR_PARAMS		 = 2,	/* Errors in parameters, out of range, invalid or unsupported modes */
	MONITOR_ERR_CONNECT		 = 3,	/* Errors in connecting to monitor */
	MONITOR_ERR_COMMS		 = 4,	/* Errors in communicating with monitor */
	MONITOR_ERR_STATE		 = 5,	/* Monitor in wrong state for API call */
	MONITOR_ERR_NOSUPPORT	 = 6,	/* Monitor does not support this API call */
	MONITOR_ERR_CHECKSUM     = 7,   /* Checksum error */
	MONITOR_ERR_MODULEOFF    = 8,   /* Error due to related module is powered off. eg) GetCalibrationModulePowerState = OFF */
	MONITOR_ERR_INUSE        = 9    /* Monitor is currently connected to another application 
									   Application should display message in similar fashion to the following:
									   "Cannot establish communication with monitor, please quit other monitor applications and launch again." */
}
MONITOR_CODE;  

typedef enum power_state
{
	POWER_STATE_OFF     = OFF,
	POWER_STATE_ON      = ON,
	POWER_STATE_STANDBY = 2
}
POWER_STATE; 

typedef enum power_usb
{
	POWER_USB_OFF = OFF,
	POWER_USB_ON  = ON
}
POWER_USB;

typedef enum power_tbt
{
	POWER_TBT_OFF = OFF,
	POWER_TBT_ON  = ON
}
POWER_TBT;

typedef enum auto_select
{
	AUTO_SELECT_OFF    = OFF,
	AUTO_SELECT_ON     = ON,
	AUTO_SELECT_PROMPT = 2
}
AUTO_SELECT;

typedef enum aspect_ratio
{
	ASPECT_RATIO_WIDE    = 0x00,
	ASPECT_RATIO_AUTO    = 0x01,
	ASPECT_RATIO_4X3     = 0x02,
	ASPECT_RATIO_1X1     = 0x03,
	ASPECT_RATIO_WIDTH   = 0x04,
	ASPECT_RATIO_HEIGHT  = 0x05,
	ASPECT_RATIO_17X9    = 0x06,
	ASPECT_RATIO_16X9    = 0x07,
	ASPECT_RATIO_PIXEL   = 0x08
}
ASPECT_RATIO;

typedef enum response_time
{
	RESPONSE_TIME_NORMAL = 0,
	RESPONSE_TIME_FAST   = 1
}
RESPONSE_TIME;

typedef enum hdr
{
	HDR_OFF = 0,
	HDR_NORMAL = 1,
	HDR_VIVID = 2
}
HDR;

typedef enum dci_masking
{
	DCI_MASK_ENTIRE = 1,
	DCI_MASK_1_85X1 = 2,
	DCI_MASK_2_39X1 = 3,
	DCI_MASK_2_35X1 = 4
}
DCI_MASKING;

typedef enum markers
{
	MARKERS_NONE = 0x00,
	MARKERS_1_85X1 = 0x01,
	MARKERS_2_39X1 = 0x02,
	MARKERS_2_35X1 = 0x03,
	MARKERS_1X1 = 0x04,
	MARKERS_16X9_EXTRACTION = 0x05,
	MARKERS_16X9_ACTION_SAFE = 0x06,
	MARKERS_16X9_TILE_SAFE = 0x07,
	MARKERS_4X3_EXTRACTION = 0x08,
	MARKERS_4X3_ACTION_SAFE = 0x09,
	MARKERS_4X3_TILE_SAFE = 0x0A,
	MARKERS_CENTER_CROSSHAIR = 0x0B,
	MARKERS_THIRDS = 0x0C,
	MARKERS_2_2X1 = 0x0D
}
MARKERS;

typedef enum markers_color
{
	MARKERS_COLOR_WHITE = 0,
	MARKERS_COLOR_RED = 1,
	MARKERS_COLOR_GREEN = 2,
	MARKERS_COLOR_BLUE = 3
}
MARKERS_COLOR;

typedef enum video_data_range
{
	VIDEO_DATA_RANGE_AUTO = 0,
	VIDEO_DATA_RANGE_FULL = 1,
	VIDEO_DATA_RANGE_LIMITED = 2
}
VIDEO_DATA_RANGE;

typedef enum color_temp
{
	COLOR_TEMP_5000K  = 0x00000001,
	COLOR_TEMP_5700K  = 0x00000002,
	COLOR_TEMP_6500K  = 0x00000004,
	COLOR_TEMP_7500K  = 0x00000008,
	COLOR_TEMP_9300K  = 0x00000010, 
	COLOR_TEMP_10000K = 0x00000020
}
COLOR_TEMP;

typedef enum color_space
{
	COLOR_SPACE_ADOBE_RGB		= 0x00000001,
	COLOR_SPACE_SRGB			= 0x00000002,
	COLOR_SPACE_REC_709			= 0x00000004,
	COLOR_SPACE_DCI_P3			= 0x00000008, 
	COLOR_SPACE_CAL_1			= 0x00000010,
	COLOR_SPACE_CAL_2			= 0x00000020,
	COLOR_SPACE_REC_2020		= 0x00000040,

	/* UP2720Q */
	COLOR_SPACE2_DCI_P3         = 0x10000001,
	COLOR_SPACE2_BT_709         = 0x10000002,
	COLOR_SPACE2_BT_2020        = 0x10000004,
	COLOR_SPACE2_SRGB           = 0x10000008,
	COLOR_SPACE2_ADOBE_RGB_D65  = 0x10000010,
	COLOR_SPACE2_ADOBE_RGB_D50  = 0x10000020,
	COLOR_SPACE2_NATIVE         = 0x10000040,
	COLOR_SPACE2_CUSTOM_1       = 0x10000080,
	COLOR_SPACE2_CUSTOM_2       = 0x10000100,
	COLOR_SPACE2_CUSTOM_3       = 0x10000200,
	COLOR_SPACE2_CAL_1          = 0x10000400,
	COLOR_SPACE2_CAL_2          = 0x10000800
}
COLOR_SPACE;

typedef enum color_space_mode
{
	/* UP2720Q */
	COLOR_SPACE_MODE_DCI_P3            = 0x00000000,
	COLOR_SPACE_MODE_BT_709            = 0x00000001,
	COLOR_SPACE_MODE_BT_2020           = 0x00000002,
	COLOR_SPACE_MODE_SRGB              = 0x00000003,
	COLOR_SPACE_MODE_ADOBE_RGB_D65     = 0x00000004,
	COLOR_SPACE_MODE_ADOBE_RGB_D50     = 0x00000005,
	COLOR_SPACE_MODE_CAL_1             = 0x00000006,
	COLOR_SPACE_MODE_CAL_2             = 0x00000007,
	COLOR_SPACE_MODE_DCI_P3_UC         = 0x00000008,
	COLOR_SPACE_MODE_BT_709_UC         = 0x00000009,
	COLOR_SPACE_MODE_BT_2020_UC        = 0x0000000A,
	COLOR_SPACE_MODE_SRGB_UC           = 0x0000000B,
	COLOR_SPACE_MODE_ADOBE_RGB_D65_UC  = 0x0000000C,
	COLOR_SPACE_MODE_ADOBE_RGB_D50_UC  = 0x0000000D,
	COLOR_SPACE_MODE_CAL_1_UC          = 0x0000000E,
	COLOR_SPACE_MODE_CAL_2_UC          = 0x0000000F
}
COLOR_SPACE_MODE;

typedef enum color_gamut
{
	COLOR_GAMUT_DCI_P3  = 0x10000001,
	COLOR_GAMUT_BT_709  = 0x10000002,
	COLOR_GAMUT_BT_2020 = 0x10000004,
	COLOR_GAMUT_SRGB    = 0x10000008,
	COLOR_GAMUT_ADOBE   = 0x10000010,
	COLOR_GAMUT_NATIVE  = 0x10000040
}
COLOR_GAMUT;

typedef enum input_color_format
{
	INPUT_COLOR_FORMAT_RGB   = 0,
	INPUT_COLOR_FORMAT_YPBPR = 1
}
INPUT_COLOR_FORMAT;

typedef enum color_preset
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

typedef enum custom_color
{
	CUSTOM_COLOR_GAIN       = 0, /* RGB (0..100) */
	CUSTOM_COLOR_OFFSET     = 1, /* RGB (0..100) */
	CUSTOM_COLOR_HUE        = 2, /* RGB (0..100), CMY (0..100) */
	CUSTOM_COLOR_SATURATION = 3, /* RGB (0..100), CMY (0..100) */
	CUSTOM_COLOR_LIGHTNESS  = 4  /* RGB (0..100), CMY (0..100) */
}
CUSTOM_COLOR;

typedef enum gamma_mode
{
	GAMMA_MODE_PC  = 0,
	GAMMA_MODE_MAC = 1
}
GAMMA_MODE;

typedef enum uniformity_compensation
{
	UNIFORMITY_COMPENSATION_OFF             = OFF,
	UNIFORMITY_COMPENSATION_ON              = 2, //ON
	UNIFORMITY_COMPENSATION_CALIBRATED_HIGH = 2
}
UNIFORMITY_COMPENSATION;

typedef enum white_point
{
	WHITE_POINT_D50 = 1,
	WHITE_POINT_D55 = 2,
	WHITE_POINT_D60 = 3,
	WHITE_POINT_D65 = 4,
	WHITE_POINT_DCI_P3 = 5,
	WHITE_POINT_NATIVE = 6
}
WHITE_POINT;

typedef enum gamma
{
	GAMMA_1_6 = 0x01,
	GAMMA_1_8 = 0x02,
	GAMMA_2_0 = 0x03,
	GAMMA_2_2 = 0x04,
	GAMMA_2_4 = 0x05,
	GAMMA_2_6 = 0x06,
	GAMMA_BT_1886 = 0x07,
	GAMMA_SRGB = 0x08,
	GAMMA_NATIVE = 0x09
}
GAMMA;

typedef enum gamma_type
{
	GAMMA_TYPE_NORMAL = 0x01, //Normal gamma value (Ex: 1.6, 2.2, etc.)
	GAMMA_TYPE_BT1886 = 0x20,
	GAMMA_TYPE_SRGB   = 0x21
}
GAMMA_TYPE;

/* VIDEO INPUT MANAGEMENT */
typedef enum video_input
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
	VIDEO_INPUT_DVI2  = 0x0000200,
	VIDEO_INPUT_TB1   = 0x0000400,
	VIDEO_INPUT_TB2   = 0x0000800
}
VIDEO_INPUT;

typedef enum video_input_name
{
	VIDEO_INPUT_NAME_OFF      = 0,
	VIDEO_INPUT_NAME_PC       = 1,
	VIDEO_INPUT_NAME_PC_1     = 2,
	VIDEO_INPUT_NAME_PC_2     = 3,
	VIDEO_INPUT_NAME_LAPTOP   = 4,
	VIDEO_INPUT_NAME_LAPTOP_1 = 5,
	VIDEO_INPUT_NAME_LAPTOP_2 = 6,
}
VIDEO_INPUT_NAME;

typedef enum audio_source
{
	AUDIO_SOURCE_MAIN = 0,
	AUDIO_SOURCE_SUB = 1
}
AUDIO_SOURCE;

typedef enum pxp_mode
{
	PXP_OFF              = 0,
	PXP_PIP_SMALL        = 1,
	PXP_PIP_LARGE        = 2,
	PXP_PBP_ASPECT_RATIO = 3,
	PXP_PBP_FILL         = 4,
	PXP_PBP_AA           = 5,
	PXP_PBP_AB           = 6
}
PXP_MODE;

typedef enum pxp_pip_location
{
	PXP_PIP_LOCATION_TOP_RIGHT    = 0,
	PXP_PIP_LOCATION_TOP_LEFT     = 1,
	PXP_PIP_LOCATION_BOTTOM_RIGHT = 2,
	PXP_PIP_LOCATION_BOTTOM_LEFT  = 3
}
PXP_PIP_LOCATION;

typedef enum osd_language
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

typedef enum osd_rotation
{
	OSD_ROTATION_0   = 0, 
	OSD_ROTATION_90  = 1, 
	OSD_ROTATION_270 = 2, 
	OSD_ROTATION_180 = 3,
	OSD_ROTATION_AUTO_ON = 4,
	OSD_ROTATION_AUTO_OFF = 5
}
OSD_ROTATION;

typedef enum osd_button
{
	OSD_BUTTON_UNLOCK = 0,                     //Unlock all Locks
	OSD_BUTTON_LOCK = 1,
	OSD_BUTTON_LOCK_OSD = 1,                   //Lock Menu Buttons
	OSD_BUTTON_LOCK_POWER = 2,                 //Lock Power Button
	OSD_BUTTON_LOCK_OSD_POWER = 3,             //Lock Menu + Power Button
	OSD_BUTTON_LOCK_COLOR_CUSTOM_SETTINGS = 4, //Lock Color Custom Settings
	OSD_BUTTON_LOCK_EXCEPT_POWER = 5           //Lock all except Power Button
}
OSD_BUTTON;

typedef enum software_lock
{
	SOFTWARE_LOCK_UNLOCK = OSD_BUTTON_UNLOCK,                             //Unlock all Locks
	SOFTWARE_LOCK_MENU = OSD_BUTTON_LOCK_OSD,                             //Lock Menu Buttons
	SOFTWARE_LOCK_POWER = OSD_BUTTON_LOCK_POWER,                          //Lock Power Button
	SOFTWARE_LOCK_MENU_POWER = OSD_BUTTON_LOCK_OSD_POWER,                 //Lock Menu + Power Button
	SOFTWARE_LOCK_COLOR_SETTINGS = OSD_BUTTON_LOCK_COLOR_CUSTOM_SETTINGS, //Lock Color Custom Settings
	SOFTWARE_LOCK_EXCEPT_POWER = OSD_BUTTON_LOCK_EXCEPT_POWER             //Lock all except Power Button
}
SOFTWARE_LOCK;

typedef enum usb_selection
{
	USB_SELECTION_USB_A = 1,
	USB_SELECTION_USB_C = 2
}
USB_SELECTION;

typedef enum auto_sleep
{
	AUTO_SLEEP_DISPLAY = 1,
	AUTO_SLEEP_PANEL_OFF = 2
}
AUTO_SLEEP;

typedef enum day_selection
{
	DAY_SELECTION_MON_FRI = 1,
	DAY_SELECTION_SAT_SUN = 2,
	DAY_SELECTION_DAILY = 3
}
DAY_SELECTION;

typedef enum reset_menu
{
	RESET_MENU_POWER = 0x01, /* replace ResetPower */
	RESET_MENU_COLOR = 0x02, 
	RESET_MENU_OSD = 0x03, /* replace ResetOSD */
	RESET_MENU_COLORSPACE = 0x04,
	RESET_MENU_INPUTSOURCE = 0x05,
	RESET_MENU_DISPLAY = 0x06,
	RESET_MENU_PXP = 0x07,
	RESET_MENU_PERSONALIZATION = 0x08,
	RESET_MENU_OTHERS = 0xFF
}
RESET_MENU;

/* LUT MANAGEMENT */
typedef enum cal_status
{
	CAL_STATUS_START = 0x01,
	CAL_STATUS_END = 0xFF
}
CAL_STATUS;

typedef enum color_control
{
	COLOR_CONTROL_DISABLE = OFF,
	COLOR_CONTROL_ENABLE = ON
}
COLOR_CONTROL;

typedef enum calibration_speed
{
	CALIBRATION_SPEED_EXPRESS = 1, //Express 
	CALIBRATION_SPEED_DETAIL  = 2  //Comprehensive
}
CALIBRATION_SPEED;

typedef enum colorimeter_profile
{
	COLORIMETER_PROFILE_BUILT_IN = 1,
	COLORIMETER_PROFILE_CORRELATED = 2
}
COLORIMETER_PROFILE;

typedef enum validation_pattern
{
	VALIDATION_PATTERN_BASIC_RGB = 1,
	VALIDATION_PATTERN_LCD_COLOR_CHECKER = 2
}
VALIDATION_PATTERN;

typedef enum calvalscheduler
{
	CALVALSCHEDULER_OFF							= 0x00,
	CALVALSCHEDULER_CALIBRATION_ONLY			= 0x01,
	CALVALSCHEDULER_VALIDATION_ONLY				= 0x02,
	CALVALSCHEDULER_CALIBRATION_AND_VALIDATION	= 0x03
}
CALVALSCHEDULER;

typedef enum calvalschedule_type
{
	CALVALSCHEDULE_TYPE_BACKLIGHT_HRS = 0x01,
	CALVALSCHEDULE_TYPE_QUARTERLY = 0x02,
	CALVALSCHEDULE_TYPE_MONTHLY = 0x03,
	CALVALSCHEDULE_TYPE_WEEKLY = 0x04,
	CALVALSCHEDULE_TYPE_DAILY = 0x05
}
CALVALSCHEDULE_TYPE;

typedef enum calvalschedule_quarter
{
	CALVALSCHEDULE_QUARTER_JAN = 0x00000001, /* Jan-Apr-Jul-Oct */
	CALVALSCHEDULE_QUARTER_FEB = 0x00000002, /* Feb-May-Aug-Nov */
	CALVALSCHEDULE_QUARTER_MAR = 0x00000003  /* Mar-Jun-Sep-Dec */
}
CALVALSCHEDULE_QUARTER;

typedef enum calvalschedule_week
{
	CALVALSCHEDULE_WEEK_1 = 0x00000010,
	CALVALSCHEDULE_WEEK_2 = 0x00000020,
	CALVALSCHEDULE_WEEK_3 = 0x00000030,
	CALVALSCHEDULE_WEEK_4 = 0x00000040,
	CALVALSCHEDULE_WEEK_5 = 0x00000050 //unused
}
CALVALSCHEDULE_WEEK;

typedef enum calvalschedule_day
{
	CALVALSCHEDULE_DAY_MON     = 0x00000100,
	CALVALSCHEDULE_DAY_TUE     = 0x00000200,
	CALVALSCHEDULE_DAY_WED     = 0x00000300,
	CALVALSCHEDULE_DAY_THU     = 0x00000400,
	CALVALSCHEDULE_DAY_FRI     = 0x00000500,
	CALVALSCHEDULE_DAY_SAT     = 0x00000600,
	CALVALSCHEDULE_DAY_SUN     = 0x00000700,
	CALVALSCHEDULE_DAY_DAILY   = 0x00000800,
	CALVALSCHEDULE_DAY_MON_FRI = 0x00000900,
	CALVALSCHEDULE_DAY_SAT_SUN = 0x00000A00
}
CALVALSCHEDULE_DAY;

typedef enum calvalschedule_op_mode
{
	CALVALSCHEDULER_OP_MODE_PROMPT = 1,
	CALVALSCHEDULER_OP_MODE_SLEEP = 2
}
CALVALSCHEDULER_OP_MODE;

typedef enum calblock
{
	CALBLOCK_PRE_LUT	= 0x01,
	CALBLOCK_3X3		= 0x02,
	CALBLOCK_POST_LUT	= 0x04,
	CALBLOCK_3D_LUT     = 0x08,
	CALBLOCK_UNIFORMITY = 0x10
}
CALBLOCK;

typedef enum colorimeter_arm
{
	COLORIMETER_ARM_INACTIVE	= OFF, /* arm down */
	COLORIMETER_ARM_ACTIVE		= ON /* arm up */
}
COLORIMETER_ARM;

/* DEBUG LEVEL */
typedef enum dblevel
{
	DB_OFF   = 0,
	DB_ERROR = 1,
	DB_WARN  = 2,
	DB_DEBUG = 3,
	DB_TRACE = 4
}
DBLEVEL;

/**********************************************
*
* STRUCTS
*
**********************************************/
//No padding
#pragma pack(push,1)

typedef struct MonitorDetailStruct {
	BYTE MonitorName[MAX_MONITOR_NAME_LEN + 1];
	BYTE ServiceTag[MAX_SERVICE_TAG_LEN + 1];
	BYTE InbuiltColorimeter; // 0 = No, 1 = Yes
	BYTE ColorimeterName[MAX_MONITOR_NAME_LEN + 1];
}
MonitorDetailStructType;

typedef struct ColorSpaceInfoStruct {
	UWORD32 ColorSpaceMode;          //refer to enum COLOR_SPACE_MODE;
	FLOAT Coordinate_R[2];           //(x,y) : 8bytes
	FLOAT Coordinate_G[2];           //(x,y) : 8bytes
	FLOAT Coordinate_B[2];           //(x,y) : 8bytes
	FLOAT Coordinate_W[2];           //(x,y) : 8bytes
	BYTE GammaValue;                 //0x10-0x1A: 1.6-2.6, 0x20:bt1886, 0x21:sRGB, 0x22:EPD, 0x24:EBU
	UWORD16 Luminance;
	BYTE stTargetCalibrationDate[5]; //(mm/hh/DD/MM/YY) 5 bytes
	BYTE stTargetValidationDate[5];  //(mm/hh/DD/MM/YY) 5 bytes
	BYTE stActualCalibrationDate[5]; //(mm/hh/DD/MM/YY) 5 bytes
	BYTE stActualValidationDate[5];  //(mm/hh/DD/MM/YY) 5 bytes
	BYTE CalibrationNow;             //unused
	BYTE UniformityStatus;           //0: OFF, 1: ON
	BYTE ColorBlocksState;           //Bit[0]: PreGamma, Bit[1]: Matrix, Bit[2]: PostGamma, Bit[3]: 3DLut, Bit[4]: CalMAN Ready calibrated
	UWORD16 UsageHours;				 //READ-ONLY - Number of hours this color space mode is used after last calibration
	UWORD16 reserved;
}
ColorSpaceInfoStructType;

typedef struct CustomColorSpaceInfoStruct {
	UWORD32 CustomColorSpace;		//refer to enum COLOR_SPACE
	UWORD32	ColorGamut;				//refer to enum COLOR_GAMUT
	BYTE WhitePoint;				//refer to enum WHITE_POINT
	BYTE Gamma;						//refer to enum GAMMA
	UWORD16 Luminance;				//UP2720Q: 45-250
	BYTE Gain[3];					//[0-2] = R G B 0-100
	BYTE Offset[3];					//[0-2] = R G B 0-100
	BYTE Hue;						//0-100
	BYTE Saturation;				//0-100
	BYTE SixAxis[6][3];				//[0-5]=[R G B C M Y] , [0-2] = H S L 0-100
}
CustomColorSpaceInfoStructType;

typedef struct CalibrationTargetInfoStruct {
	UWORD32 ColorSpace;			 //refer to enum COLOR_SPACE
	FLOAT Coordinate_R[2];       //(x,y) : 8bytes
	FLOAT Coordinate_G[2];       //(x,y) : 8bytes
	FLOAT Coordinate_B[2];       //(x,y) : 8bytes
	FLOAT Coordinate_W[2];       //(x,y) : 8bytes
	BYTE GammaValue;             //0x10-0x1A: 1.6-2.6, 0x20:bt1886, 0x21:sRGB, 0x22:EPD, 0x24:EBU
	UWORD16 Luminance;
	BYTE UniformityStatus;       //0: OFF, 1: ON
}
CalibrationTargetInfoStructType;

typedef struct CalibrationResultStruct {
	UWORD32 ColorSpaceMode;           //refer to enum COLOR_SPACE_MODE; 
	FLOAT RGBW[4][3];                 //4 patterns (X,Y,Z)
	FLOAT Gray[16][3];                //16 patterns (X,Y,Z)
	FLOAT Luminance;                  //Range: Luminance <= 400.
	BYTE GammaType;                   //refer to enum GAMMA_TYPE;
	FLOAT GammaValue;                 //Range: 10 <= GammaValue <= 26.
	BYTE stTargetCalibrationDate[5];  //(mm/hh/DD/MM/YY) 5 bytes
	BYTE stActualCalibrationDate[5];  //(mm/hh/DD/MM/YY) 5 bytes
	UWORD32 ColorTemp;                //Range: 2700 <= ColorTemp <= 10000.
	UWORD16 reserved;
}
CalibrationResultStructType;

typedef struct ValidationResultStruct {
	UWORD32 ColorSpaceMode;              //refer to enum COLOR_SPACE_MODE; 
	BYTE MeasureDataReady;
	BYTE Gamut;                          //0x00: Native, 0x01: AdobeRGB, 0x02: sRGB, 0x03:DCI-P3, 0x06: REC709, 0x07: REC2020.
	BYTE GammaType;                      //refer to enum GAMMA_TYPE;
	FLOAT GammaValue;                    //Range: 10 <= GammaValue <= 26.
	double Target_XYZ[41][3];            //Double X, Y, Z
	double Target_Lab[41][3];            //Double L, a, b
	double Measured_XYZ[49][3];          //Double X, Y, Z
	double Measured_Lab[41][3];          //Double L, a, b
	UWORD16 MeasuredXYZChecksum;
	FLOAT VerifiedGammaValue;
	FLOAT VerifiedColorTemp;
	FLOAT VerifiedGamutCoordinate[3][3]; //FLOAT X, Y, Z
	double DeltaE76[41];
	double DeltaH94[41];
	double DeltaE94[41];
	double DeltaH2K[41];
	double DeltaE2K[41];
	BYTE stTargetValidationDate[5];      //(mm/hh/DD/MM/YY) 5 bytes
	BYTE stActualValidationDate[5];      //(mm/hh/DD/MM/YY) 5 bytes
	UWORD16 reserved;
}
ValidationResultStructType;

#pragma pack(pop)

/**********************************************
 *
 * OBSELETE 
 *
 **********************************************/

/* OBSELETED, USE OFF/ON */
typedef enum power_led
{
	POWER_LED_OFF = OFF,
	POWER_LED_ON = ON
}
POWER_LED;

typedef enum mst
{
	MST_OFF = OFF,
	MST_ON = ON
}
MST;

typedef enum osd_sound
{
	OSD_SOUND_OFF = OFF,
	OSD_SOUND_ON = ON
}
OSD_SOUND;

typedef enum lcd_conditioning
{
	LCD_CONDITIONING_OFF = OFF,
	LCD_CONDITIONING_ON = ON
}
LCD_CONDITIONING;

typedef enum dynamic_contrast
{
	DYNAMIC_CONTRAST_OFF = OFF,
	DYNAMIC_CONTRAST_ON = ON
}
DYNAMIC_CONTRAST;

/* END OBSELETED, USE OFF/ON */

#endif /*__UP_DATA_H__ */
