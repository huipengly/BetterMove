///////////////////////////////////////////////////////////////////////////////
// CppBetterMoveServices.h

#pragma once

#include "TcServices.h"

const ULONG DrvID_CppBetterMove = 0x3F000000;
#define SRVNAME_CPPBETTERMOVE "CppBetterMove"

///<AutoGeneratedContent id="ClassIDs">
const CTCID CID_CppBetterMoveCGivePosition = {0xb502fa80,0x9cb9,0x4335,{0x9a,0xda,0xcf,0x17,0x44,0x8f,0x31,0xa2}};
///</AutoGeneratedContent>

///<AutoGeneratedContent id="ParameterIDs">
const PTCID PID_GivePositionParameter = 0x00000001;
///</AutoGeneratedContent>

///<AutoGeneratedContent id="DataTypes">
typedef struct _GivePositionParameter
{
	ULONG data1;
	ULONG data2;
	double data3;
} GivePositionParameter, *PGivePositionParameter;

#pragma pack(push,1)
typedef struct _GivePositionInputs
{
	ULONG Value;
	ULONG Status;
	ULONG Data;
	bool CanGivenPosition;
	double NextPosition;
} GivePositionInputs, *PGivePositionInputs;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _GivePositionOutputs
{
	ULONG Value;
	ULONG Control;
	ULONG Data;
	bool IsGivenPositon;
	double GivenPosition;
} GivePositionOutputs, *PGivePositionOutputs;
#pragma pack(pop)

///</AutoGeneratedContent>



///<AutoGeneratedContent id="DataAreaIDs">
#define ADI_GivePositionInputs 0
#define ADI_GivePositionOutputs 1
///</AutoGeneratedContent>

///<AutoGeneratedContent id="InterfaceIDs">
///</AutoGeneratedContent>
