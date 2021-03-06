///////////////////////////////////////////////////////////////////////////////
// CppBetterMoveClassFactory.cpp
#include "TcPch.h"
#pragma hdrstop

#include "CppBetterMoveClassFactory.h"
#include "CppBetterMoveServices.h"
#include "CppBetterMoveVersion.h"
#include "GivePosition.h"

BEGIN_CLASS_MAP(CCppBetterMoveClassFactory)
///<AutoGeneratedContent id="ClassMap">
	CLASS_ENTRY(CID_CppBetterMoveCGivePosition, SRVNAME_CPPBETTERMOVE "!CGivePosition", CGivePosition)
///</AutoGeneratedContent>
END_CLASS_MAP()

CCppBetterMoveClassFactory::CCppBetterMoveClassFactory() : CObjClassFactory()
{
	TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME(SRVNAME_CPPBETTERMOVE)); 
#if defined(TCDBG_UNIT_VERSION)
	TcDbgUnitSetVersion(TCDBG_UNIT_VERSION(CppBetterMove));
#endif //defined(TCDBG_UNIT_VERSION)
}

