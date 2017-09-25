///////////////////////////////////////////////////////////////////////////////
// CppBetterMoveDriver.h

#ifndef __CPPBETTERMOVEDRIVER_H__
#define __CPPBETTERMOVEDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define CPPBETTERMOVEDRV_NAME        "CPPBETTERMOVE"
#define CPPBETTERMOVEDRV_Major       1
#define CPPBETTERMOVEDRV_Minor       0

#define DEVICE_CLASS CCppBetterMoveDriver

#include "ObjDriver.h"

class CCppBetterMoveDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl CPPBETTERMOVEDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(CPPBETTERMOVEDRV)
	VxD_Service( CPPBETTERMOVEDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __CPPBETTERMOVEDRIVER_H__