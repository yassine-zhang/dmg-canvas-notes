//
//  OSVersion.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 11/16/11.
//  Copyright 2011 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


enum {
	macOSVersionMajorMask = 0x00FF0000,
	macOSVersionMinorMask = 0x0000FF00,
	macOSVersionBugfixMask = 0x000000FF,
	macOSVersionMajorMinorMask = 0x00FFFF00,
	macOSVersion15_00 = 0x000F0000,
	macOSVersion14_00 = 0x000E0000,
	macOSVersion13_00 = 0x000D0000,
	macOSVersion12_00 = 0x000C0000,
	macOSVersion11_00 = 0x000B0000,
	macOSVersion10_15 = 0x000A0F00,
	macOSVersion10_14 = 0x000A0E00,
	macOSVersion10_13 = 0x000A0D00,
	macOSVersion10_12 = 0x000A0C00,
	macOSVersion10_11 = 0x000A0B00,
	macOSVersion10_10 = 0x000A0A00,
	macOSVersion10_9 = 0x000A0900,
	macOSVersion10_8 = 0x000A0800,
	macOSVersion10_7 = 0x000A0700,
	macOSVersion10_6 = 0x000A0600,
};

#define OSXVersion() macOSVersion()
uint32_t macOSVersion(void);
uint32_t macOSVersionMake(int major, int minor, int bugfix);
NSString * macOSVersionString(void);

#define IsSnowLeopard()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_6)
#define IsSnowLeopardOrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_6)
#define IsLion()				((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_7)
#define IsLionOrLater()			((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_7)
#define IsMountainLion()		((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_8)
#define IsMountainLionOrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_8)
#define IsMavericks()		    ((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_9)
#define IsMavericksOrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_9)
#define IsYosemite()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_10)
#define IsYosemiteOrLater()		((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_10)
#define IsElCapitan()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_11)
#define IsElCapitanOrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_11)
#define IsSierra()			    ((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_12)
#define IsSierraOrLater()	    ((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_12)
#define IsHighSierra()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_13)
#define IsHighSierraOrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_13)
#define IsMojave()				((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_14)
#define IsMojaveOrLater()		((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_14)
#define IsCatalina()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_15)
#define IsCatalinaOrLater()		((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_15)
#define IsBigSur()			    ((macOSVersion() & macOSVersionMajorMask) == macOSVersion11_00)
#define IsBigSurOrLater()		((macOSVersion() & macOSVersionMajorMask) >= macOSVersion11_00)
#define IsMonterey()			   ((macOSVersion() & macOSVersionMajorMask) == macOSVersion12_00)
#define IsMontereyOrLater()		((macOSVersion() & macOSVersionMajorMask) >= macOSVersion12_00)

#define macOSVersionIs_10_6()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_6)
#define macOSVersionIs_10_7()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_7)
#define macOSVersionIs_10_8()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_8)
#define macOSVersionIs_10_9()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_9)
#define macOSVersionIs_10_10()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_10)
#define macOSVersionIs_10_11()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_11)
#define macOSVersionIs_10_12()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_12)
#define macOSVersionIs_10_13()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_13)
#define macOSVersionIs_10_14()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_14)
#define macOSVersionIs_10_15()			((macOSVersion() & macOSVersionMajorMinorMask) == macOSVersion10_15)
#define macOSVersionIs_11_00()			((macOSVersion() & macOSVersionMajorMask) == macOSVersion11_00)
#define macOSVersionIs_12_00()			((macOSVersion() & macOSVersionMajorMask) == macOSVersion12_00)
#define macOSVersionIs_13_00()			((macOSVersion() & macOSVersionMajorMask) == macOSVersion13_00)
#define macOSVersionIs_14_00()			((macOSVersion() & macOSVersionMajorMask) == macOSVersion14_00)
#define macOSVersionIs_15_00()			((macOSVersion() & macOSVersionMajorMask) == macOSVersion15_00)

#define macOSVersionIs_10_6_OrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_6)
#define macOSVersionIs_10_7_OrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_7)
#define macOSVersionIs_10_8_OrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_8)
#define macOSVersionIs_10_9_OrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_9)
#define macOSVersionIs_10_10_OrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_10)
#define macOSVersionIs_10_11_OrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_11)
#define macOSVersionIs_10_12_OrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_12)
#define macOSVersionIs_10_13_OrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_13)
#define macOSVersionIs_10_14_OrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_14)
#define macOSVersionIs_10_15_OrLater()	((macOSVersion() & macOSVersionMajorMinorMask) >= macOSVersion10_15)
#define macOSVersionIs_11_00_OrLater()	((macOSVersion() & macOSVersionMajorMask) >= macOSVersion11_00)
#define macOSVersionIs_12_00_OrLater()	((macOSVersion() & macOSVersionMajorMask) >= macOSVersion12_00)
#define macOSVersionIs_13_00_OrLater()	((macOSVersion() & macOSVersionMajorMask) >= macOSVersion13_00)
#define macOSVersionIs_14_00_OrLater()	((macOSVersion() & macOSVersionMajorMask) >= macOSVersion14_00)
#define macOSVersionIs_15_00_OrLater()	((macOSVersion() & macOSVersionMajorMask) >= macOSVersion15_00)
