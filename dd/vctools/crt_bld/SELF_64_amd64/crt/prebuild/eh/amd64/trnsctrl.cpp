// File Line: 41
// RVA: 0x12AD364
unsigned __int64 *__fastcall _GetEstablisherFrame(
        unsigned __int64 *pRN,
        _xDISPATCHER_CONTEXT *pDC,
        _s_FuncInfo *pFuncInfo,
        unsigned __int64 *pEstablisher)
{
  __int64 v4; // rdi
  int v9; // eax
  int v10; // ebp
  _DWORD *v11; // rbx
  PRUNTIME_FUNCTION v12; // rax
  unsigned int v13; // r9d
  unsigned __int64 v14; // r8
  __int64 v15; // rcx
  _DWORD *v16; // rdx
  unsigned __int64 ImageBase; // [rsp+50h] [rbp+8h] BYREF

  LODWORD(v4) = pFuncInfo->nTryBlocks;
  v9 = __StateFromControlPc(pFuncInfo, pDC);
  *pEstablisher = *pRN;
  v10 = v9;
  while ( (_DWORD)v4 )
  {
    v4 = (unsigned int)(v4 - 1);
    v11 = (_DWORD *)(pDC->ImageBase + pFuncInfo->dispTryBlockMap + 20 * v4);
    if ( v10 > v11[1] && v10 <= v11[2] )
    {
      v12 = RtlLookupFunctionEntry(pDC->ControlPc, &ImageBase, 0i64);
      v13 = v11[3];
      v14 = ImageBase + (int)v11[4];
      v15 = 0i64;
      if ( v13 )
      {
        v16 = (_DWORD *)(v14 + 12);
        do
        {
          if ( *v16 == (unsigned __int64)v12->BeginAddress )
            break;
          v15 = (unsigned int)(v15 + 1);
          v16 += 5;
        }
        while ( (unsigned int)v15 < v13 );
      }
      if ( (unsigned int)v15 < v13 )
      {
        *pEstablisher = *(_QWORD *)(*(int *)(v14 + 20 * v15 + 16) + *pRN);
        return pEstablisher;
      }
    }
  }
  return pEstablisher;
}

// File Line: 71
// RVA: 0x12AD78C
unsigned __int64 __fastcall GetImageBase()
{
  return getptd()->_ImageBase;
}

// File Line: 76
// RVA: 0x12AD7A4
unsigned __int64 __fastcall GetThrowImageBase()
{
  return getptd()->_ThrowImageBase;
}

// File Line: 81
// RVA: 0x12AD7F0
void __fastcall SetImageBase(unsigned __int64 ImageBaseToRestore)
{
  getptd()->_ImageBase = ImageBaseToRestore;
}

// File Line: 86
// RVA: 0x12AD80C
void __fastcall SetThrowImageBase(unsigned __int64 NewThrowImageBase)
{
  getptd()->_ThrowImageBase = NewThrowImageBase;
}

// File Line: 147
// RVA: 0x12AD55C
void __fastcall __FrameUnwindToEmptyState(unsigned __int64 *pRN, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo)
{
  unsigned __int64 *EstablisherFrame; // r14
  int v6; // eax
  unsigned int nTryBlocks; // ebx
  int v8; // esi
  unsigned __int64 v9; // rcx
  int v10; // r9d
  unsigned __int64 pEstablisher; // [rsp+50h] [rbp+18h] BYREF

  EstablisherFrame = _GetEstablisherFrame(pRN, pDC, pFuncInfo, &pEstablisher);
  v6 = __StateFromControlPc(pFuncInfo, pDC);
  nTryBlocks = pFuncInfo->nTryBlocks;
  v8 = v6;
  while ( nTryBlocks )
  {
    v9 = pFuncInfo->dispTryBlockMap + getptd()->_ImageBase + 20i64 * --nTryBlocks;
    if ( v8 > *(_DWORD *)(v9 + 4) && v8 <= *(_DWORD *)(v9 + 8) )
      goto LABEL_6;
  }
  v9 = 0i64;
LABEL_6:
  if ( v9 )
    v10 = *(_DWORD *)(v9 + 4);
  else
    v10 = -1;
  _FrameUnwindToState(EstablisherFrame, pDC, pFuncInfo, v10);
}

// File Line: 185
// RVA: 0x12AD9A0
_EXCEPTION_DISPOSITION __fastcall _CxxFrameHandler3(
        EHExceptionRecord *pExcept,
        unsigned __int64 RN,
        _CONTEXT *pContext,
        _xDISPATCHER_CONTEXT *pDC)
{
  _tiddata *v7; // rax
  unsigned __int64 pRN; // [rsp+50h] [rbp+8h] BYREF

  pRN = RN;
  getptd()->_ImageBase = pDC->ImageBase;
  getptd()->_ThrowImageBase = (unsigned __int64)pExcept->params.pThrowImageBase;
  v7 = getptd();
  return _InternalCxxFrameHandler(
           pExcept,
           &pRN,
           pContext,
           pDC,
           (_s_FuncInfo *)(v7->_ImageBase + *(unsigned int *)pDC->HandlerData),
           0,
           0i64,
           0);
}

// File Line: 234
// RVA: 0x12AD5F0
__int64 __fastcall __SehTransFilter(
        _EXCEPTION_POINTERS *ExPtrs,
        EHExceptionRecord *pExcept,
        unsigned __int64 *pRN,
        _CONTEXT *pContext,
        _xDISPATCHER_CONTEXT *pDC,
        _s_FuncInfo *pFuncInfo,
        int *pResult)
{
  _EXCEPTION_RECORD *ExceptionRecord; // rbx
  __int64 result; // rax

  getptd()->_pForeignException = pExcept;
  ExceptionRecord = ExPtrs->ExceptionRecord;
  getptd()->_ThrowImageBase = ExceptionRecord->ExceptionInformation[3];
  _InternalCxxFrameHandler((EHExceptionRecord *)ExPtrs->ExceptionRecord, pRN, pContext, pDC, pFuncInfo, 0, 0i64, 1);
  getptd()->_pForeignException = 0i64;
  result = 1i64;
  *pResult = 1;
  return result;
}

// File Line: 258
// RVA: 0x12AD694
__int64 __fastcall CallSETranslator(
        _s_FuncInfo *pExcept,
        unsigned __int64 *pRN,
        _s_FuncInfo *pContext,
        _xDISPATCHER_CONTEXT *pDC)
{
  _tiddata *v5; // rax
  _s_FuncInfo *v7[4]; // [rsp+48h] [rbp-20h] BYREF

  v7[0] = pExcept;
  v7[1] = pContext;
  v5 = getptd();
  ((void (__fastcall *)(_QWORD, _s_FuncInfo **))v5->_translator)(*(_DWORD *)pExcept, v7);
  return 0i64;
}

// File Line: 281
// RVA: 0x1451C20
_CallSETranslator$filt$0

// File Line: 331
// RVA: 0x12AD430
_s_TryBlockMapEntry *__fastcall _GetRangeOfTrysToCheck(
        unsigned __int64 *pRN,
        _s_FuncInfo *pFuncInfo,
        int CatchDepth,
        int curState,
        unsigned int *pStart,
        unsigned int *pEnd,
        _xDISPATCHER_CONTEXT *pDC)
{
  unsigned int nTryBlocks; // edi
  __int64 v10; // rsi
  int v11; // r14d
  unsigned int v12; // edx
  __int64 dispTryBlockMap; // r11
  __int64 v14; // r9
  __int64 v15; // rax
  unsigned int v16; // edx
  __int64 v17; // r9
  _DWORD *v18; // rcx
  __int64 v19; // rax

  nTryBlocks = pFuncInfo->nTryBlocks;
  v10 = 0i64;
  v11 = __StateFromControlPc(pFuncInfo, pDC);
  if ( !nTryBlocks )
    _inconsistency();
  v12 = nTryBlocks;
  *pEnd = -1;
  *pStart = -1;
  dispTryBlockMap = pFuncInfo->dispTryBlockMap;
  do
  {
    v14 = v12 - 1;
    v15 = pDC->ImageBase + 20 * v14;
    if ( v11 > *(_DWORD *)(v15 + dispTryBlockMap + 4) && v11 <= *(_DWORD *)(v15 + dispTryBlockMap + 8) )
      break;
    --v12;
  }
  while ( (_DWORD)v14 );
  if ( v12 )
    v10 = pDC->ImageBase + pFuncInfo->dispTryBlockMap + 20i64 * (v12 - 1);
  v16 = 0;
  v17 = 0i64;
  do
  {
    v18 = (_DWORD *)(v17 + pDC->ImageBase + pFuncInfo->dispTryBlockMap);
    if ( (!v10 || *v18 > *(_DWORD *)(v10 + 4) && v18[1] <= *(_DWORD *)(v10 + 8))
      && curState >= *v18
      && curState <= v18[1] )
    {
      if ( *pStart == -1 )
        *pStart = v16;
      *pEnd = v16 + 1;
    }
    ++v16;
    v17 += 20i64;
  }
  while ( v16 < nTryBlocks );
  v19 = *pStart;
  if ( (_DWORD)v19 != -1 )
    return (_s_TryBlockMapEntry *)(pDC->ImageBase + pFuncInfo->dispTryBlockMap + 20 * v19);
  *pStart = 0;
  *pEnd = 0;
  return 0i64;
}

// File Line: 377
// RVA: 0x12AD6E8
FrameInfo *__fastcall CreateFrameInfo(FrameInfo *pFrameInfo, void *pExceptionObject)
{
  FrameInfo *pFrameInfoChain; // rcx

  pFrameInfo->pExceptionObject = pExceptionObject;
  if ( pFrameInfo >= getptd()->_pFrameInfoChain )
    pFrameInfoChain = 0i64;
  else
    pFrameInfoChain = (FrameInfo *)getptd()->_pFrameInfoChain;
  pFrameInfo->pNext = pFrameInfoChain;
  getptd()->_pFrameInfoChain = pFrameInfo;
  return pFrameInfo;
}

// File Line: 395
// RVA: 0x12AD7BC
__int64 __fastcall IsExceptionObjectToBeDestroyed(void *pExceptionObject)
{
  void **i; // rdx

  for ( i = (void **)getptd()->_pFrameInfoChain; ; i = (void **)i[1] )
  {
    if ( !i )
      return 1i64;
    if ( *i == pExceptionObject )
      break;
  }
  return 0i64;
}

// File Line: 415
// RVA: 0x12AD72C
void __fastcall FindAndUnlinkFrame(FrameInfo *pFrameInfo)
{
  FrameInfo *i; // rbx

  if ( pFrameInfo != getptd()->_pFrameInfoChain )
    _inconsistency();
  for ( i = (FrameInfo *)getptd()->_pFrameInfoChain; ; i = i->pNext )
  {
    if ( !i )
      _inconsistency();
    if ( pFrameInfo == i )
      break;
  }
  getptd()->_pFrameInfoChain = i->pNext;
}

// File Line: 444
// RVA: 0x12AD828
void __fastcall UnwindNestedFrames(
        void **pFrame,
        EHExceptionRecord *pExcept,
        _CONTEXT *pContext,
        unsigned __int64 *pEstablisher,
        void **Handler,
        unsigned __int8 TargetUnwindState)
{
  _EXCEPTION_RECORD *v7; // rdx
  char *v9; // rcx
  __int64 v11; // rax
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __int128 v15; // xmm0
  __int128 v16; // xmm1
  __int128 v17; // xmm0
  __int128 v18; // xmm1
  void *ExceptionAddress; // rax
  void *v20; // rdx
  void *v21; // rcx
  _UNWIND_HISTORY_TABLE *HistoryTable; // rax
  char Dst[32]; // [rsp+30h] [rbp-B8h] BYREF
  void *(__fastcall *v24)(_EXCEPTION_RECORD *); // [rsp+50h] [rbp-98h]
  unsigned __int64 *v25; // [rsp+58h] [rbp-90h]
  __int64 v26; // [rsp+60h] [rbp-88h]
  EHExceptionRecord *v27; // [rsp+68h] [rbp-80h]
  __int64 v28; // [rsp+70h] [rbp-78h]
  __int64 v29; // [rsp+78h] [rbp-70h]
  _CONTEXT ContextRecord; // [rsp+B8h] [rbp-30h] BYREF
  __int64 v31; // [rsp+5D8h] [rbp+4F0h]
  int v32; // [rsp+5E0h] [rbp+4F8h]
  __int64 v33; // [rsp+5E8h] [rbp+500h]

  v7 = &ExceptionTemplate;
  v9 = Dst;
  if ( (((unsigned __int8)Dst | (unsigned __int8)&ExceptionTemplate) & 0xF) != 0 )
  {
    memmove(Dst, &ExceptionTemplate, 0x98ui64);
  }
  else
  {
    v11 = 1i64;
    do
    {
      v12 = *(_OWORD *)&v7->ExceptionAddress;
      *(_OWORD *)v9 = *(_OWORD *)&v7->ExceptionCode;
      v13 = *(_OWORD *)v7->ExceptionInformation;
      *((_OWORD *)v9 + 1) = v12;
      v14 = *(_OWORD *)&v7->ExceptionInformation[2];
      *((_OWORD *)v9 + 2) = v13;
      v15 = *(_OWORD *)&v7->ExceptionInformation[4];
      *((_OWORD *)v9 + 3) = v14;
      v16 = *(_OWORD *)&v7->ExceptionInformation[6];
      *((_OWORD *)v9 + 4) = v15;
      v17 = *(_OWORD *)&v7->ExceptionInformation[8];
      *((_OWORD *)v9 + 5) = v16;
      v18 = *(_OWORD *)&v7->ExceptionInformation[10];
      v7 = (_EXCEPTION_RECORD *)((char *)v7 + 128);
      *((_OWORD *)v9 + 6) = v17;
      v9 += 128;
      *((_OWORD *)v9 - 1) = v18;
      --v11;
    }
    while ( v11 );
    ExceptionAddress = v7->ExceptionAddress;
    *(_OWORD *)v9 = *(_OWORD *)&v7->ExceptionCode;
    *((_QWORD *)v9 + 2) = ExceptionAddress;
  }
  v20 = *Handler;
  v21 = *pFrame;
  v24 = _CxxCallCatchBlock;
  v26 = v31;
  v27 = (EHExceptionRecord *)v32;
  v25 = pEstablisher;
  v29 = v33;
  v28 = TargetUnwindState;
  HistoryTable = (_UNWIND_HISTORY_TABLE *)Handler[8];
  v27 = pExcept;
  v29 = 429065504i64;
  RtlUnwindEx(v21, v20, (PEXCEPTION_RECORD)Dst, 0i64, &ContextRecord, HistoryTable);
}

