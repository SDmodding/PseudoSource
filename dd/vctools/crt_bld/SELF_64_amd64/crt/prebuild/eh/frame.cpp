// File Line: 323
// RVA: 0x12C4DFC
__int64 __fastcall _InternalCxxFrameHandler(
        EHExceptionRecord *pExcept,
        unsigned __int64 *pRN,
        _CONTEXT *pContext,
        _xDISPATCHER_CONTEXT *pDC,
        _s_FuncInfo *pFuncInfo,
        int CatchDepth,
        unsigned __int64 *pMarkerRN,
        unsigned __int8 recursive)
{
  unsigned int v12; // eax
  int v13; // eax
  int v14; // r9d
  unsigned __int64 *pExceptionObject; // rcx
  int pThrowImageBase; // esi
  unsigned __int64 v17; // rax
  __int64 (__fastcall *v18)(EHExceptionRecord *, unsigned __int64 *, _CONTEXT *, _xDISPATCHER_CONTEXT *, _s_FuncInfo *, int, unsigned __int64 *, _DWORD); // r10

  if ( !getptd()->_cxxReThrow
    && pExcept->ExceptionCode != -529697949
    && (pExcept->ExceptionCode != -2147483607
     || pExcept->NumberParameters != 15
     || *(_QWORD *)&pExcept[1].params.magicNumber != 429065504i64)
    && pExcept->ExceptionCode != -2147483610
    && (*(_DWORD *)pFuncInfo & 0x1FFFFFFFu) >= 0x19930522
    && (pFuncInfo->EHFlags & 1) != 0 )
  {
    return 1i64;
  }
  if ( (pExcept->ExceptionFlags & 0x66) != 0 )
  {
    if ( !pFuncInfo->maxState || CatchDepth )
      return 1i64;
    v12 = pExcept->ExceptionFlags & 0x20;
    if ( v12 && pExcept->ExceptionCode == -2147483610 )
    {
      v13 = __StateFromIp(pFuncInfo, pDC, pContext->Rip);
      if ( v13 < -1 || v13 >= pFuncInfo->maxState )
        _inconsistency();
      v14 = v13;
      pExceptionObject = pRN;
    }
    else
    {
      if ( !v12 || pExcept->ExceptionCode != -2147483607 )
      {
        __FrameUnwindToEmptyState(pRN, pDC, pFuncInfo);
        return 1i64;
      }
      pThrowImageBase = (int)pExcept->params.pThrowImageBase;
      if ( pThrowImageBase < -1 || pThrowImageBase >= pFuncInfo->maxState )
        _inconsistency();
      pExceptionObject = (unsigned __int64 *)pExcept->params.pExceptionObject;
      v14 = (int)pExcept->params.pThrowImageBase;
    }
    _FrameUnwindToState(pExceptionObject, pDC, pFuncInfo, v14);
  }
  else if ( pFuncInfo->nTryBlocks
         || (*(_DWORD *)pFuncInfo & 0x1FFFFFFFu) >= 0x19930521
         && (!pFuncInfo->dispESTypeList ? (v17 = 0i64) : (v17 = pFuncInfo->dispESTypeList + GetImageBase()), v17) )
  {
    if ( pExcept->ExceptionCode == -529697949
      && pExcept->NumberParameters >= 3
      && pExcept->params.magicNumber > 0x19930522 )
    {
      v18 = pExcept->params.pThrowInfo->pForwardCompat
          ? (__int64 (__fastcall *)(EHExceptionRecord *, unsigned __int64 *, _CONTEXT *, _xDISPATCHER_CONTEXT *, _s_FuncInfo *, int, unsigned __int64 *, _DWORD))(GetThrowImageBase() + pExcept->params.pThrowInfo->pForwardCompat)
          : 0i64;
      if ( v18 )
        return v18(pExcept, pRN, pContext, pDC, pFuncInfo, CatchDepth, pMarkerRN, recursive);
    }
    FindHandler(pExcept, pRN, pContext, pDC, pFuncInfo, recursive, CatchDepth, pMarkerRN);
  }
  return 1i64;
}

// File Line: 480
// RVA: 0x12C3F24
void __fastcall FindHandler(
        EHExceptionRecord *pExcept,
        unsigned __int64 *pRN,
        _CONTEXT *pContext,
        _xDISPATCHER_CONTEXT *pDC,
        _s_FuncInfo *pFuncInfo,
        char recursive,
        int CatchDepth,
        unsigned __int64 *pMarkerRN)
{
  _s_FuncInfo *v8; // rbx
  _CONTEXT *curcontext; // r14
  int UnwindTryBlock; // esi
  _tiddata *v14; // rax
  void *pThrowImageBase; // rcx
  _s_ESTypeList *curexcspec; // r14
  int v17; // r15d
  __int64 v18; // rsi
  __int64 v19; // rbx
  type_info *v20; // rax
  _s_TryBlockMapEntry *v21; // rax
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int *p_dispHandlerArray; // r14
  _s_HandlerType *v25; // r12
  int v26; // eax
  unsigned __int64 ThrowImageBase; // rax
  _s_ThrowInfo *pThrowInfo; // r8
  int dispESTypeList; // esi
  _s_ESTypeList *v31; // rdx
  unsigned __int64 *EstablisherFrame; // rax
  char v33; // [rsp+60h] [rbp-49h]
  unsigned int pStart; // [rsp+64h] [rbp-45h] BYREF
  unsigned int pEnd; // [rsp+68h] [rbp-41h] BYREF
  int v36; // [rsp+6Ch] [rbp-3Dh]
  int v37; // [rsp+70h] [rbp-39h]
  int *v38; // [rsp+78h] [rbp-31h]
  _s_CatchableType *pConv; // [rsp+80h] [rbp-29h]
  unsigned __int64 pEstablisher; // [rsp+88h] [rbp-21h] BYREF
  std::exception pExceptionObject; // [rsp+90h] [rbp-19h] BYREF
  char *_What; // [rsp+F0h] [rbp+47h] BYREF
  _CONTEXT *pContexta; // [rsp+100h] [rbp+57h]

  pContexta = pContext;
  v8 = pFuncInfo;
  curcontext = pContext;
  LOBYTE(_What) = 0;
  v33 = 0;
  UnwindTryBlock = __StateFromControlPc(pFuncInfo, pDC);
  _GetEstablisherFrame(pRN, pDC, v8, &pEstablisher);
  if ( UnwindTryBlock <= __GetUnwindTryBlock(pRN, pDC, v8) )
  {
    UnwindTryBlock = __GetUnwindTryBlock(pRN, pDC, v8);
  }
  else
  {
    __SetState(&pEstablisher, pDC, v8, UnwindTryBlock);
    __SetUnwindTryBlock(pRN, pDC, v8, UnwindTryBlock);
  }
  if ( UnwindTryBlock < -1 || UnwindTryBlock >= v8->maxState )
    _inconsistency();
  if ( pExcept->ExceptionCode != -529697949 )
    goto LABEL_69;
  if ( pExcept->NumberParameters == 4 && pExcept->params.magicNumber - 429065504 <= 2 && !pExcept->params.pThrowInfo )
  {
    if ( !getptd()->_curexception )
      return;
    pExcept = (EHExceptionRecord *)getptd()->_curexception;
    v14 = getptd();
    pThrowImageBase = pExcept->params.pThrowImageBase;
    curcontext = (_CONTEXT *)v14->_curcontext;
    LOBYTE(_What) = 1;
    pContexta = curcontext;
    SetThrowImageBase((unsigned __int64)pThrowImageBase);
    if ( !_ValidateWrite(pExcept, 1u) )
      _inconsistency();
    if ( pExcept->ExceptionCode == -529697949
      && pExcept->NumberParameters == 4
      && pExcept->params.magicNumber - 429065504 <= 2
      && !pExcept->params.pThrowInfo )
    {
      _inconsistency();
    }
    if ( getptd()->_curexcspec )
    {
      curexcspec = (_s_ESTypeList *)getptd()->_curexcspec;
      getptd()->_curexcspec = 0i64;
      if ( !IsInExceptionSpec(pExcept, curexcspec) )
      {
        v17 = 0;
        if ( curexcspec->nCount > 0 )
        {
          v18 = 0i64;
          do
          {
            if ( *(_DWORD *)(curexcspec->dispTypeArray + v18 + GetImageBase() + 4) )
            {
              v19 = *(int *)(curexcspec->dispTypeArray + v18 + GetImageBase() + 4);
              v20 = (type_info *)(v19 + GetImageBase());
            }
            else
            {
              v20 = 0i64;
            }
            if ( type_info::operator==(v20, &std::bad_exception `RTTI Type Descriptor) )
            {
              _DestructExceptionObject(pExcept, 1);
              _What = "bad exception";
              std::exception::exception(&pExceptionObject, (const char **)&_What);
              pExceptionObject.vfptr = (std::exceptionVtbl *)&std::bad_exception::`vftable;
              CxxThrowException(&pExceptionObject, (_s_ThrowInfo *)&TI2_AVbad_exception_std__);
            }
            ++v17;
            v18 += 20i64;
          }
          while ( v17 < curexcspec->nCount );
        }
        terminate();
      }
      curcontext = pContexta;
    }
  }
  if ( pExcept->ExceptionCode == -529697949
    && pExcept->NumberParameters == 4
    && pExcept->params.magicNumber - 429065504 <= 2 )
  {
    if ( !v8->nTryBlocks )
      goto LABEL_70;
    v21 = _GetRangeOfTrysToCheck(pRN, v8, CatchDepth, UnwindTryBlock, &pStart, &pEnd, pDC);
    v22 = pStart;
    v23 = pEnd;
    if ( pStart >= pEnd )
      goto LABEL_70;
    p_dispHandlerArray = &v21->dispHandlerArray;
    do
    {
      if ( *(p_dispHandlerArray - 4) <= UnwindTryBlock && UnwindTryBlock <= *(p_dispHandlerArray - 3) )
      {
        v25 = (_s_HandlerType *)(GetImageBase() + *p_dispHandlerArray);
        v26 = *(p_dispHandlerArray - 1);
        while ( 1 )
        {
          v36 = v26;
          if ( v26 <= 0 )
            break;
          v38 = (int *)(pExcept->params.pThrowInfo->pCatchableTypeArray + GetThrowImageBase() + 4);
          v37 = *(_DWORD *)(GetThrowImageBase() + pExcept->params.pThrowInfo->pCatchableTypeArray);
          if ( v37 > 0 )
          {
            while ( 1 )
            {
              ThrowImageBase = GetThrowImageBase();
              pThrowInfo = pExcept->params.pThrowInfo;
              pConv = (_s_CatchableType *)(*v38 + ThrowImageBase);
              if ( _TypeMatch(v25, pConv, pThrowInfo) )
                break;
              ++v38;
              if ( --v37 <= 0 )
                goto LABEL_43;
            }
            v33 = 1;
            CatchIt(pExcept, pRN, pContexta, pDC, v8, v25, pConv, (_s_TryBlockMapEntry *)(p_dispHandlerArray - 4));
            break;
          }
LABEL_43:
          v26 = v36 - 1;
          ++v25;
        }
        v23 = pEnd;
        v22 = pStart;
      }
      ++v22;
      p_dispHandlerArray += 5;
      pStart = v22;
    }
    while ( v22 < v23 );
    if ( !v33 )
    {
LABEL_70:
      if ( (*(_DWORD *)v8 & 0x1FFFFFFFu) >= 0x19930521 )
      {
        dispESTypeList = v8->dispESTypeList;
        if ( dispESTypeList ? dispESTypeList + GetImageBase() : 0i64 )
        {
          v31 = dispESTypeList ? (_s_ESTypeList *)(v8->dispESTypeList + GetImageBase()) : 0i64;
          if ( !IsInExceptionSpec(pExcept, v31) )
          {
            EstablisherFrame = _GetEstablisherFrame(pRN, pDC, v8, (unsigned __int64 *)&_What);
            UnwindNestedFrames((void **)pRN, pExcept, pContexta, EstablisherFrame, 0i64, 0xFFu);
          }
        }
      }
    }
  }
  else
  {
LABEL_69:
    if ( v8->nTryBlocks )
    {
      if ( recursive )
        terminate();
      FindHandlerForForeignException(pExcept, pRN, curcontext, pDC, v8, UnwindTryBlock, CatchDepth, pMarkerRN);
    }
  }
  if ( getptd()->_curexcspec )
    _inconsistency();
}

// File Line: 824
// RVA: 0x12C43D8
void __fastcall FindHandlerForForeignException(
        _s_FuncInfo *pExcept,
        unsigned __int64 *pRN,
        _CONTEXT *pContext,
        _xDISPATCHER_CONTEXT *pDC,
        _s_FuncInfo *pFuncInfo,
        int curState,
        int CatchDepth)
{
  _tiddata *v11; // rax
  _s_FuncInfo *v12; // rbp
  PVOID v13; // rbx
  int v14; // ebx
  int v15; // r14d
  _s_TryBlockMapEntry *v16; // rax
  unsigned int v17; // ecx
  int *p_nCatches; // rdi
  __int64 v19; // rbx
  __int64 v20; // rax
  __int64 v21; // rbx
  __int64 v22; // rax
  unsigned __int64 ImageBase; // rax
  unsigned int pEnd[18]; // [rsp+60h] [rbp-48h] BYREF
  unsigned int pStart; // [rsp+B0h] [rbp+8h] BYREF
  _CONTEXT *pContexta; // [rsp+C0h] [rbp+18h]

  pContexta = pContext;
  if ( *(_DWORD *)pExcept != -2147483645 )
  {
    v11 = getptd();
    v12 = pFuncInfo;
    if ( !v11->_translator
      || (v13 = EncodePointer(0i64), getptd()->_translator == v13)
      || *(_DWORD *)pExcept == -532459699 )
    {
      v14 = CatchDepth;
    }
    else
    {
      v14 = CatchDepth;
      if ( *(_DWORD *)pExcept != -532462766
        && (unsigned int)CallSETranslator(pExcept, pRN, (_s_FuncInfo *)pContext, pDC) )
      {
        return;
      }
    }
    if ( !v12->nTryBlocks )
      _inconsistency();
    v15 = curState;
    v16 = _GetRangeOfTrysToCheck(pRN, v12, v14, curState, &pStart, pEnd, pDC);
    v17 = pStart;
    if ( pStart < pEnd[0] )
    {
      p_nCatches = &v16->nCatches;
      do
      {
        if ( v15 >= *(p_nCatches - 3) && v15 <= *(p_nCatches - 2) )
        {
          if ( *(_DWORD *)(GetImageBase() + p_nCatches[1] + 20i64 * *p_nCatches - 16) )
          {
            v19 = *(int *)(GetImageBase() + p_nCatches[1] + 20i64 * *p_nCatches - 16);
            v20 = v19 + GetImageBase();
          }
          else
          {
            v20 = 0i64;
          }
          if ( !v20
            || (!*(_DWORD *)(GetImageBase() + p_nCatches[1] + 20i64 * *p_nCatches - 16)
              ? (v22 = 0i64)
              : (v21 = *(int *)(GetImageBase() + p_nCatches[1] + 20i64 * *p_nCatches - 16), v22 = v21 + GetImageBase()),
                !*(_BYTE *)(v22 + 16)) )
          {
            if ( (*(_BYTE *)(GetImageBase() + p_nCatches[1] + 20i64 * *p_nCatches - 20) & 0x40) == 0 )
            {
              ImageBase = GetImageBase();
              CatchIt(
                (EHExceptionRecord *)pExcept,
                pRN,
                pContexta,
                pDC,
                v12,
                (_s_HandlerType *)(p_nCatches[1] + ImageBase + 20i64 * (*p_nCatches - 1)),
                0i64,
                (_s_TryBlockMapEntry *)(p_nCatches - 3));
            }
          }
          v17 = pStart;
        }
        ++v17;
        p_nCatches += 5;
        pStart = v17;
      }
      while ( v17 < pEnd[0] );
    }
  }
}

// File Line: 910
// RVA: 0x12C5020
__int64 __fastcall _TypeMatch(_s_HandlerType *pCatch, _s_CatchableType *pCatchable, _s_ThrowInfo *pThrow)
{
  __int64 dispType; // rsi
  unsigned int v4; // ebx
  unsigned __int64 v8; // rcx
  __int64 v9; // rcx
  unsigned __int64 v10; // rsi
  unsigned __int64 v11; // rsi
  unsigned __int64 ThrowImageBase; // rax

  LODWORD(dispType) = pCatch->dispType;
  v4 = 0;
  if ( (_DWORD)dispType )
    v8 = (int)dispType + GetImageBase();
  else
    v8 = 0i64;
  if ( !v8 )
    return 1i64;
  if ( (_DWORD)dispType )
  {
    dispType = pCatch->dispType;
    v9 = dispType + GetImageBase();
  }
  else
  {
    v9 = 0i64;
  }
  if ( !*(_BYTE *)(v9 + 16) )
    return 1i64;
  if ( (_DWORD)dispType )
    v10 = pCatch->dispType + GetImageBase();
  else
    v10 = 0i64;
  if ( v10 != pCatchable->pType + GetThrowImageBase() )
  {
    v11 = pCatch->dispType ? pCatch->dispType + GetImageBase() : 0i64;
    ThrowImageBase = GetThrowImageBase();
    if ( strcmp((const char *)(v11 + 16), (const char *)(ThrowImageBase + pCatchable->pType + 16i64)) )
      return 0i64;
  }
  if ( ((pCatchable->properties & 2) == 0 || (pCatch->adjectives & 8) != 0)
    && ((pThrow->attributes & 1) == 0 || (pCatch->adjectives & 1) != 0)
    && ((pThrow->attributes & 4) == 0 || (pCatch->adjectives & 4) != 0)
    && ((pThrow->attributes & 2) == 0 || (pCatch->adjectives & 2) != 0) )
  {
    return 1;
  }
  return v4;
}

// File Line: 946
// RVA: 0x12C4C14
__int64 __fastcall _FrameUnwindFilter(_EXCEPTION_POINTERS *pExPtrs)
{
  _EXCEPTION_RECORD *ExceptionRecord; // rax
  _tiddata *v2; // rax

  ExceptionRecord = pExPtrs->ExceptionRecord;
  if ( pExPtrs->ExceptionRecord->ExceptionCode == -532462766 || ExceptionRecord->ExceptionCode == -532459699 )
  {
    if ( getptd()->_ProcessingThrow > 0 )
    {
      v2 = getptd();
      --v2->_ProcessingThrow;
    }
  }
  else if ( ExceptionRecord->ExceptionCode == -529697949 )
  {
    getptd()->_ProcessingThrow = 0;
    terminate();
  }
  return 0i64;
}

// File Line: 1017
// RVA: 0x12C4C68
void __fastcall _FrameUnwindToState(
        unsigned __int64 *pRN,
        _xDISPATCHER_CONTEXT *pDC,
        _s_FuncInfo *pFuncInfo,
        int targetState)
{
  int CurrentState; // edi
  _tiddata *v9; // rax
  __int64 v10; // r14
  __int64 v11; // rbx
  __int64 v12; // rax
  __int64 v13; // rbx
  __int64 v14; // rax
  _tiddata *v15; // rax
  unsigned __int64 ImageBaseToRestore; // [rsp+28h] [rbp-40h]

  ImageBaseToRestore = GetImageBase();
  CurrentState = __GetCurrentState(pRN, pDC, pFuncInfo);
  v9 = getptd();
  ++v9->_ProcessingThrow;
  while ( CurrentState != -1 && CurrentState > targetState )
  {
    if ( CurrentState <= -1 || CurrentState >= pFuncInfo->maxState )
      _inconsistency();
    v10 = CurrentState;
    CurrentState = *(_DWORD *)(pFuncInfo->dispUnwindMap + GetImageBase() + 8i64 * CurrentState);
    if ( *(_DWORD *)(pFuncInfo->dispUnwindMap + GetImageBase() + 8 * v10 + 4) )
    {
      v11 = *(int *)(pFuncInfo->dispUnwindMap + GetImageBase() + 8 * v10 + 4);
      v12 = v11 + GetImageBase();
    }
    else
    {
      v12 = 0i64;
    }
    if ( v12 )
    {
      __SetState(pRN, pDC, pFuncInfo, CurrentState);
      if ( *(_DWORD *)(pFuncInfo->dispUnwindMap + GetImageBase() + 8 * v10 + 4) )
      {
        v13 = *(int *)(pFuncInfo->dispUnwindMap + GetImageBase() + 8 * v10 + 4);
        v14 = v13 + GetImageBase();
      }
      else
      {
        v14 = 0i64;
      }
      CallSettingFrame(v14, pRN, 259i64);
      SetImageBase(ImageBaseToRestore);
    }
  }
  if ( getptd()->_ProcessingThrow > 0 )
  {
    v15 = getptd();
    --v15->_ProcessingThrow;
  }
  if ( CurrentState != -1 && CurrentState > targetState )
    _inconsistency();
  __SetState(pRN, pDC, pFuncInfo, CurrentState);
}

// File Line: 1068
// RVA: 0x1452152
__FrameUnwindToState$filt$0

// File Line: 1074
// RVA: 0x1452168
__FrameUnwindToState$fin$1

// File Line: 1134
// RVA: 0x12C3E60
void __fastcall CatchIt(
        EHExceptionRecord *pExcept,
        unsigned __int64 *pRN,
        _CONTEXT *pContext,
        _xDISPATCHER_CONTEXT *pDC,
        _s_FuncInfo *pFuncInfo,
        _s_HandlerType *pCatch,
        _s_CatchableType *pConv,
        _s_TryBlockMapEntry *pEntry)
{
  unsigned __int64 *EstablisherFrame; // rax
  _s_HandlerType *v12; // rsi
  unsigned __int64 *v13; // rdi
  unsigned __int64 ImageBase; // rax
  unsigned __int64 v15; // [rsp+88h] [rbp+10h] BYREF

  EstablisherFrame = _GetEstablisherFrame(pRN, pDC, pFuncInfo, &v15);
  v12 = pCatch;
  v13 = EstablisherFrame;
  if ( pConv )
    _BuildCatchObject(pExcept, EstablisherFrame, pCatch, pConv);
  ImageBase = GetImageBase();
  UnwindNestedFrames((void **)pRN, pExcept, pContext, v13, (void **)(v12->dispOfHandler + ImageBase), pEntry->tryLow);
}

// File Line: 1222
// RVA: 0x12C4A10
__int64 __fastcall _CxxCallCatchBlock(_EXCEPTION_RECORD *pExcept)
{
  void *curcontext; // r13
  EHExceptionRecord *v3; // rsi
  void *v4; // rbx
  _QWORD *v5; // r14
  _tiddata *v6; // rax
  FrameInfo *v7; // r12
  __int64 v8; // rbx
  unsigned __int64 v10; // [rsp+48h] [rbp-80h]
  unsigned __int64 v11; // [rsp+58h] [rbp-70h]
  FrameInfo pFrameInfo; // [rsp+78h] [rbp-50h] BYREF
  void *curexception; // [rsp+E0h] [rbp+18h]

  curcontext = getptd()->_curcontext;
  curexception = getptd()->_curexception;
  v3 = (EHExceptionRecord *)pExcept->ExceptionInformation[6];
  v10 = pExcept->ExceptionInformation[5];
  v4 = (void *)pExcept->ExceptionInformation[4];
  v11 = pExcept->ExceptionInformation[2];
  v5 = (_QWORD *)pExcept->ExceptionInformation[1];
  getptd()->_curexception = v3;
  getptd()->_curcontext = v4;
  v6 = getptd();
  v7 = CreateFrameInfo(&pFrameInfo, *((void **)v6->_curexception + 5));
  if ( pExcept->ExceptionInformation[7] )
    getptd();
  v8 = CallSettingFrame(v11, v5, 256i64);
  FindAndUnlinkFrame(v7);
  if ( v3->ExceptionCode == -529697949
    && v3->NumberParameters == 4
    && v3->params.magicNumber - 429065504 <= 2
    && (unsigned int)IsExceptionObjectToBeDestroyed(v3->params.pExceptionObject) )
  {
    _DestructExceptionObject(v3, 1);
  }
  getptd()->_curexception = curexception;
  getptd()->_curcontext = curcontext;
  *(_QWORD *)(*(int *)(v10 + 28) + *v5) = -2i64;
  return v8;
}

// File Line: 1267
// RVA: 0x1451FC8
__CxxCallCatchBlock$filt$0

// File Line: 1282
// RVA: 0x14520BC
__CxxCallCatchBlock$fin$1

// File Line: 1495
// RVA: 0x12C4810
__int64 __fastcall _BuildCatchObjectHelper(
        EHExceptionRecord *pExcept,
        char **pRN,
        _s_HandlerType *pCatch,
        _s_CatchableType *pConv)
{
  unsigned int v8; // edi
  int dispType; // r15d
  unsigned __int64 v10; // rdx
  unsigned __int64 v11; // rcx
  char *pExceptionObject; // rcx
  unsigned __int64 v13; // rcx
  bool v14; // zf
  void *v15; // rcx
  size_t sizeOrOffset; // rbx
  char *v17; // rax
  unsigned int v18; // edx
  void *v19; // rcx

  v8 = 0;
  dispType = pCatch->dispType;
  if ( dispType )
    v10 = dispType + GetImageBase();
  else
    v10 = 0i64;
  if ( v10 )
  {
    v11 = dispType ? pCatch->dispType + GetImageBase() : 0i64;
    if ( *(_BYTE *)(v11 + 16) && (pCatch->dispCatchObj || (pCatch->adjectives & 0x80000000) != 0) )
    {
      if ( (pCatch->adjectives & 0x80000000) == 0 )
        pRN = (char **)&(*pRN)[pCatch->dispCatchObj];
      if ( (pCatch->adjectives & 8) != 0 )
      {
        if ( _ValidateWrite(pExcept->params.pExceptionObject, 1u) && _ValidateWrite(pRN, 1u) )
        {
          pExceptionObject = (char *)pExcept->params.pExceptionObject;
          *pRN = pExceptionObject;
LABEL_17:
          *pRN = _AdjustPointer(pExceptionObject, &pConv->thisDisplacement);
          return v8;
        }
      }
      else if ( (pConv->properties & 1) != 0 )
      {
        if ( _ValidateWrite(pExcept->params.pExceptionObject, 1u) && _ValidateWrite(pRN, 1u) )
        {
          memmove(pRN, pExcept->params.pExceptionObject, pConv->sizeOrOffset);
          if ( pConv->sizeOrOffset != 8 || !*pRN )
            return v8;
          pExceptionObject = *pRN;
          goto LABEL_17;
        }
      }
      else
      {
        if ( pConv->copyFunction )
          v13 = pConv->copyFunction + GetThrowImageBase();
        else
          v13 = 0i64;
        v14 = v13 == 0;
        v15 = pExcept->params.pExceptionObject;
        if ( v14 )
        {
          if ( _ValidateWrite(v15, 1u) && _ValidateWrite(pRN, 1u) )
          {
            sizeOrOffset = pConv->sizeOrOffset;
            v17 = _AdjustPointer((char *)pExcept->params.pExceptionObject, &pConv->thisDisplacement);
            memmove(pRN, v17, sizeOrOffset);
            return v8;
          }
        }
        else if ( _ValidateWrite(v15, 1u) && _ValidateWrite(pRN, 1u) )
        {
          v19 = pConv->copyFunction ? (void *)(pConv->copyFunction + GetThrowImageBase()) : 0i64;
          if ( _ValidateWrite(v19, v18) )
            return (unsigned int)((pConv->properties & 4) != 0) + 1;
        }
      }
      _inconsistency();
    }
  }
  return 0i64;
}

// File Line: 1626
// RVA: 0x12C4758
void __fastcall _BuildCatchObject(
        EHExceptionRecord *pExcept,
        _QWORD *pRN,
        _s_HandlerType *pCatch,
        _s_CatchableType *pConv)
{
  _QWORD *v6; // rsi
  int v7; // eax
  void (__fastcall *v8)(_QWORD *, char *, __int64); // rbx
  char *v9; // rax
  void (__fastcall *v10)(_QWORD *, char *); // rbx
  char *v11; // rax

  if ( (pCatch->adjectives & 0x80000000) == 0 )
    v6 = (_QWORD *)(*pRN + pCatch->dispCatchObj);
  else
    v6 = pRN;
  v7 = _BuildCatchObjectHelper(pExcept, pRN, pCatch, pConv) - 1;
  if ( v7 )
  {
    if ( v7 == 1 )
    {
      v8 = 0i64;
      if ( pConv->copyFunction )
        v8 = (void (__fastcall *)(_QWORD *, char *, __int64))(pConv->copyFunction + GetThrowImageBase());
      v9 = _AdjustPointer((char *)pExcept->params.pExceptionObject, &pConv->thisDisplacement);
      v8(v6, v9, 1i64);
    }
  }
  else
  {
    v10 = 0i64;
    if ( pConv->copyFunction )
      v10 = (void (__fastcall *)(_QWORD *, char *))(GetThrowImageBase() + pConv->copyFunction);
    v11 = _AdjustPointer((char *)pExcept->params.pExceptionObject, &pConv->thisDisplacement);
    v10(v6, v11);
  }
}

// File Line: 1699
// RVA: 0x12C3D80
void __fastcall _DestructExceptionObject(EHExceptionRecord *pExcept, char fThrowNotAllowed)
{
  _s_ThrowInfo *pThrowInfo; // rax
  __int64 v3; // rcx

  if ( pExcept )
  {
    if ( pExcept->ExceptionCode == -529697949
      && pExcept->NumberParameters == 4
      && pExcept->params.magicNumber - 429065504 <= 2 )
    {
      pThrowInfo = pExcept->params.pThrowInfo;
      if ( pThrowInfo )
      {
        if ( pThrowInfo->pmfnUnwind )
        {
          ((void (__fastcall *)(void *))((char *)pExcept->params.pThrowImageBase + pThrowInfo->pmfnUnwind))(pExcept->params.pExceptionObject);
        }
        else if ( (pThrowInfo->attributes & 0x10) != 0 )
        {
          v3 = *(_QWORD *)pExcept->params.pExceptionObject;
          if ( v3 )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 16i64))(v3);
        }
      }
    }
  }
}

// File Line: 1726
// RVA: 0x145213A
__DestructExceptionObject$filt$0

// File Line: 1760
// RVA: 0x12C4734
char *__fastcall _AdjustPointer(char *pThis, PMD *pmd)
{
  char *result; // rax

  result = &pThis[pmd->mdisp];
  if ( pmd->pdisp >= 0 )
    result += pmd->pdisp + (__int64)*(int *)(pmd->vdisp + *(_QWORD *)&pThis[pmd->pdisp]);
  return result;
}

// File Line: 1785
// RVA: 0x12C4718
bool __fastcall __uncaught_exception()
{
  return getptd()->_ProcessingThrow != 0;
}

// File Line: 2100
// RVA: 0x12C4640
char __fastcall IsInExceptionSpec(EHExceptionRecord *pExcept, _s_ESTypeList *pESTypeList)
{
  int v4; // edi
  char i; // r14
  int *v6; // r15
  int v7; // ebp
  _s_CatchableType *v8; // rbx
  unsigned __int64 ImageBase; // rax

  if ( !pESTypeList )
    _inconsistency();
  v4 = 0;
  for ( i = 0; v4 < pESTypeList->nCount; ++v4 )
  {
    v6 = (int *)(GetThrowImageBase() + pExcept->params.pThrowInfo->pCatchableTypeArray + 4i64);
    v7 = *(_DWORD *)(GetThrowImageBase() + pExcept->params.pThrowInfo->pCatchableTypeArray);
    if ( v7 > 0 )
    {
      while ( 1 )
      {
        v8 = (_s_CatchableType *)(*v6 + GetThrowImageBase());
        ImageBase = GetImageBase();
        if ( _TypeMatch(
               (_s_HandlerType *)(ImageBase + 20i64 * v4 + pESTypeList->dispTypeArray),
               v8,
               pExcept->params.pThrowInfo) )
        {
          break;
        }
        --v7;
        ++v6;
        if ( v7 <= 0 )
          goto LABEL_8;
      }
      i = 1;
    }
LABEL_8:
    ;
  }
  return i;
}

