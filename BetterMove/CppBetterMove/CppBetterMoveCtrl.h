///////////////////////////////////////////////////////////////////////////////
// CppBetterMoveCtrl.h

#ifndef __CPPBETTERMOVECTRL_H__
#define __CPPBETTERMOVECTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define CPPBETTERMOVEDRV_NAME "CPPBETTERMOVE"

#include "resource.h"       // main symbols
#include "CppBetterMoveW32.h"
#include "TcBase.h"
#include "CppBetterMoveClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CCppBetterMoveCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CCppBetterMoveCtrl, &CLSID_CppBetterMoveCtrl>
	, public ICppBetterMoveCtrl
	, public ITcOCFCtrlImpl<CCppBetterMoveCtrl, CCppBetterMoveClassFactory>
{
public:
	CCppBetterMoveCtrl();
	virtual ~CCppBetterMoveCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_CPPBETTERMOVECTRL)
DECLARE_NOT_AGGREGATABLE(CCppBetterMoveCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCppBetterMoveCtrl)
	COM_INTERFACE_ENTRY(ICppBetterMoveCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __CPPBETTERMOVECTRL_H__
