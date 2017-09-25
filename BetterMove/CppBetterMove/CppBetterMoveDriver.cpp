///////////////////////////////////////////////////////////////////////////////
// CppBetterMoveDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "CppBetterMoveDriver.h"
#include "CppBetterMoveClassFactory.h"

DECLARE_GENERIC_DEVICE(CPPBETTERMOVEDRV)

IOSTATUS CCppBetterMoveDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CCppBetterMoveClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CCppBetterMoveDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CCppBetterMoveDriver::CPPBETTERMOVEDRV_GetVersion( )
{
	return( (CPPBETTERMOVEDRV_Major << 8) | CPPBETTERMOVEDRV_Minor );
}

