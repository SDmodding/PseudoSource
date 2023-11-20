// File Line: 323
// RVA: 0x12C4DFC
__int64 __fastcall _InternalCxxFrameHandler(EHExceptionRecord *pExcept, unsigned __int64 *pRN, _CONTEXT *pContext, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo, int CatchDepth, unsigned __int64 *pMarkerRN, char recursive)
{
  _xDISPATCHER_CONTEXT *v8; // rbp
  _CONTEXT *v9; // r14
  unsigned __int64 *v10; // rsi
  EHExceptionRecord *v11; // rbx
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // er9
  unsigned __int64 *v16; // rcx
  int v17; // esi
  unsigned __int64 v18; // rax
  __int64 (__fastcall *v19)(EHExceptionRecord *, unsigned __int64 *, _CONTEXT *, _xDISPATCHER_CONTEXT *, _s_FuncInfo *, int, unsigned __int64 *, _DWORD); // r10

  v8 = pDC;
  v9 = pContext;
  v10 = pRN;
  v11 = pExcept;
  if ( !getptd()->_cxxReThrow
    && v11->ExceptionCode != -529697949
    && (v11->ExceptionCode != -2147483607
     || v11->NumberParameters != 15
     || *(_QWORD *)&v11[1].params.magicNumber != 429065504i64)
    && v11->ExceptionCode != -2147483610
    && (*(_DWORD *)pFuncInfo & 0x1FFFFFFFu) >= 0x19930522
    && pFuncInfo->EHFlags & 1 )
  {
    return 1i64;
  }
  v12 = v11->ExceptionFlags;
  if ( v12 & 0x66 )
  {
    if ( !pFuncInfo->maxState || CatchDepth )
      return 1i64;
    v13 = v11->ExceptionFlags & 0x20;
    if ( v13 && v11->ExceptionCode == -2147483610 )
    {
      v14 = __StateFromIp(pFuncInfo, v8, v9->Rip);
      if ( v14 < -1 || v14 >= pFuncInfo->maxState )
        _inconsistency();
      v15 = v14;
      v16 = v10;
    }
    else
    {
      if ( !v13 || v11->ExceptionCode != -2147483607 )
      {
        __FrameUnwindToEmptyState(v10, v8, pFuncInfo);
        return 1i64;
      }
      v17 = (int)v11->params.pThrowImageBase;
      if ( v17 < -1 || v17 >= pFuncInfo->maxState )
        _inconsistency();
      v16 = (unsigned __int64 *)v11->params.pExceptionObject;
      v15 = (int)v11->params.pThrowImageBase;
    }
    _FrameUnwindToState(v16, v8, pFuncInfo, v15);
  }
  else if ( pFuncInfo->nTryBlocks
         || (*(_DWORD *)pFuncInfo & 0x1FFFFFFFu) >= 0x19930521
         && (!pFuncInfo->dispESTypeList ? (v18 = 0i64) : (v18 = pFuncInfo->dispESTypeList + GetImageBase()), v18) )
  {
    if ( v11->ExceptionCode == -529697949 && v11->NumberParameters >= 3 && v11->params.magicNumber > 0x19930522 )
    {
      v19 = (__int64 (__fastcall *)(EHExceptionRecord *, unsigned __int64 *, _CONTEXT *, _xDISPATCHER_CONTEXT *, _s_FuncInfo *, int, unsigned __int64 *, _DWORD))(v11->params.pThrowInfo->pForwardCompat ? GetThrowImageBase() + v11->params.pThrowInfo->pForwardCompat : 0i64);
      if ( v19 )
        return v19(v11, v10, v9, v8, pFuncInfo, CatchDepth, pMarkerRN, (unsigned __int8)recursive);
    }
    FindHandler(v11, v10, v9, v8, pFuncInfo, recursive, CatchDepth, pMarkerRN);
  }
  return 1i64;
}

// File Line: 480
// RVA: 0x12C3F24
void __fastcall FindHandler(EHExceptionRecord *pExcept, unsigned __int64 *pRN, _CONTEXT *pContext, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo, char recursive, int CatchDepth, unsigned __int64 *pMarkerRN)
{
  _s_FuncInfo *v8; // rbx
  unsigned __int64 *v9; // r13
  EHExceptionRecord *v10; // rdi
  _xDISPATCHER_CONTEXT *v11; // r15
  _CONTEXT *v12; // r14
  int v13; // esi
  _tiddata *v14; // rax
  unsigned __int64 v15; // rcx
  _s_ESTypeList *v16; // r14
  int v17; // er15
  __int64 v18; // rsi
  __int64 v19; // rbx
  type_info *v20; // rax
  _s_TryBlockMapEntry *v21; // rax
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int *v24; // r14
  _s_HandlerType *v25; // r12
  int v26; // eax
  unsigned __int64 v27; // rax
  _s_ThrowInfo *v28; // r8
  int v29; // esi
  unsigned __int64 v30; // rax
  _s_ESTypeList *v31; // rdx
  unsigned __int64 *v32; // rax
  char v33; // [rsp+60h] [rbp-49h]
  unsigned int pStart; // [rsp+64h] [rbp-45h]
  unsigned int pEnd; // [rsp+68h] [rbp-41h]
  int v36; // [rsp+6Ch] [rbp-3Dh]
  int v37; // [rsp+70h] [rbp-39h]
  signed int *v38; // [rsp+78h] [rbp-31h]
  _s_CatchableType *pConv; // [rsp+80h] [rbp-29h]
  unsigned __int64 pEstablisher; // [rsp+88h] [rbp-21h]
  std::exception pExceptionObject; // [rsp+90h] [rbp-19h]
  char *_What; // [rsp+F0h] [rbp+47h]
  _CONTEXT *pContexta; // [rsp+100h] [rbp+57h]

  pContexta = pContext;
  v8 = pFuncInfo;
  v9 = pRN;
  v10 = pExcept;
  v11 = pDC;
  v12 = pContext;
  LOBYTE(_What) = 0;
  v33 = 0;
  v13 = __StateFromControlPc(pFuncInfo, pDC);
  _GetEstablisherFrame(v9, v11, v8, &pEstablisher);
  if ( v13 <= __GetUnwindTryBlock(v9, v11, v8) )
  {
    v13 = __GetUnwindTryBlock(v9, v11, v8);
  }
  else
  {
    __SetState(&pEstablisher, v11, v8, v13);
    __SetUnwindTryBlock(v9, v11, v8, v13);
  }
  if ( v13 < -1 || v13 >= v8->maxState )
    _inconsistency();
  if ( v10->ExceptionCode != -529697949 )
    goto LABEL_70;
  if ( v10->NumberParameters == 4 && v10->params.magicNumber - 429065504 <= 2 && !v10->params.pThrowInfo )
  {
    if ( !getptd()->_curexception )
      return;
    v10 = (EHExceptionRecord *)getptd()->_curexception;
    v14 = getptd();
    v15 = (unsigned __int64)v10->params.pThrowImageBase;
    v12 = (_CONTEXT *)v14->_curcontext;
    LOBYTE(_What) = 1;
    pContexta = v12;
    SetThrowImageBase(v15);
    if ( !_ValidateWrite(v10, 1u) )
      _inconsistency();
    if ( v10->ExceptionCode == -529697949
      && v10->NumberParameters == 4
      && v10->params.magicNumber - 429065504 <= 2
      && !v10->params.pThrowInfo )
    {
      _inconsistency();
    }
    if ( getptd()->_curexcspec )
    {
      v16 = (_s_ESTypeList *)getptd()->_curexcspec;
      getptd()->_curexcspec = 0i64;
      if ( !IsInExceptionSpec(v10, v16) )
      {
        v17 = 0;
        if ( v16->nCount > 0 )
        {
          v18 = 0i64;
          do
          {
            if ( *(_DWORD *)(v16->dispTypeArray + v18 + GetImageBase() + 4) )
            {
              v19 = *(signed int *)(v16->dispTypeArray + v18 + GetImageBase() + 4);
              v20 = (type_info *)(v19 + GetImageBase());
            }
            else
            {
              v20 = 0i64;
            }
            if ( type_info::operator==(v20, &std::bad_exception `RTTI Type Descriptor') )
            {
              _DestructExceptionObject(v10, 1);
              _What = "bad exception";
              std::exception::exception(&pExceptionObject, (const char *const *)&_What);
              pExceptionObject.vfptr = (std::exceptionVtbl *)&std::bad_exception::`vftable';
              CxxThrowException(&pExceptionObject, &TI2_AVbad_exception_std__);
            }
            ++v17;
            v18 += 20i64;
          }
          while ( v17 < v16->nCount );
        }
        terminate();
      }
      v12 = pContexta;
    }
  }
  if ( v10->ExceptionCode != -529697949 || v10->NumberParameters != 4 || v10->params.magicNumber - 429065504 > 2 )
  {
LABEL_70:
    if ( v8->nTryBlocks > 0 )
    {
      if ( recursive )
        terminate();
      FindHandlerForForeignException(v10, v9, v12, v11, v8, v13, CatchDepth, pMarkerRN);
    }
  }
  else
  {
    if ( v8->nTryBlocks <= 0 )
      goto LABEL_71;
    v21 = _GetRangeOfTrysToCheck(v9, v8, CatchDepth, v13, &pStart, &pEnd, v11);
    v22 = pStart;
    v23 = pEnd;
    if ( pStart >= pEnd )
      goto LABEL_71;
    v24 = &v21->dispHandlerArray;
    do
    {
      if ( *(v24 - 4) <= v13 && v13 <= *(v24 - 3) )
      {
        v25 = (_s_HandlerType *)(GetImageBase() + *v24);
        v26 = *(v24 - 1);
        while ( 1 )
        {
          v36 = v26;
          if ( v26 <= 0 )
            break;
          v38 = (signed int *)(v10->params.pThrowInfo->pCatchableTypeArray + GetThrowImageBase() + 4);
          v37 = *(_DWORD *)(GetThrowImageBase() + v10->params.pThrowInfo->pCatchableTypeArray);
          if ( v37 > 0 )
          {
            while ( 1 )
            {
              v27 = GetThrowImageBase();
              v28 = v10->params.pThrowInfo;
              pConv = (_s_CatchableType *)(*v38 + v27);
              if ( _TypeMatch(v25, pConv, v28) )
                break;
              ++v38;
              if ( --v37 <= 0 )
                goto LABEL_43;
            }
            v33 = 1;
            CatchIt(v10, v9, pContexta, v11, v8, v25, pConv, (_s_TryBlockMapEntry *)(v24 - 4));
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
      v24 += 5;
      pStart = v22;
    }
    while ( v22 < v23 );
    if ( !v33 )
    {
LABEL_71:
      if ( (*(_DWORD *)v8 & 0x1FFFFFFFu) >= 0x19930521 )
      {
        v29 = v8->dispESTypeList;
        v30 = v29 ? v29 + GetImageBase() : 0i64;
        if ( v30 )
        {
          v31 = (_s_ESTypeList *)(v29 ? v8->dispESTypeList + GetImageBase() : 0i64);
          if ( !IsInExceptionSpec(v10, v31) )
          {
            v32 = _GetEstablisherFrame(v9, v11, v8, (unsigned __int64 *)&_What);
            UnwindNestedFrames(v9, v10, pContexta, v32, 0i64, -1);
          }
        }
      }
    }
  }
  if ( getptd()->_curexcspec )
    _inconsistency();
}

// File Line: 824
// RVA: 0x12C43D8
void __fastcall FindHandlerForForeignException(EHExceptionRecord *pExcept, unsigned __int64 *pRN, _CONTEXT *pContext, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo, int curState, int CatchDepth)
{
  _xDISPATCHER_CONTEXT *v7; // r15
  _CONTEXT *v8; // rdi
  unsigned __int64 *v9; // r12
  EHExceptionRecord *v10; // rsi
  _tiddata *v11; // rax
  _s_FuncInfo *v12; // rbp
  PVOID v13; // rbx
  int v14; // ebx
  int v15; // er14
  _s_TryBlockMapEntry *v16; // rax
  unsigned int v17; // ecx
  int *v18; // rdi
  __int64 v19; // rbx
  unsigned __int64 v20; // rax
  __int64 v21; // rbx
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rax
  unsigned int pEnd; // [rsp+60h] [rbp-48h]
  unsigned int pStart; // [rsp+B0h] [rbp+8h]
  _CONTEXT *pContexta; // [rsp+C0h] [rbp+18h]

  pContexta = pContext;
  v7 = pDC;
  v8 = pContext;
  v9 = pRN;
  v10 = pExcept;
  if ( pExcept->ExceptionCode != -2147483645 )
  {
    v11 = getptd();
    v12 = pFuncInfo;
    if ( v11->_translator
      && (v13 = EncodePointer(0i64), getptd()->_translator != v13)
      && v10->ExceptionCode != -532459699 )
    {
      v14 = CatchDepth;
      if ( v10->ExceptionCode != -532462766 && (unsigned int)CallSETranslator(v10, v9, v8, v7) )
        return;
    }
    else
    {
      v14 = CatchDepth;
    }
    if ( !v12->nTryBlocks )
      _inconsistency();
    v15 = curState;
    v16 = _GetRangeOfTrysToCheck(v9, v12, v14, curState, &pStart, &pEnd, v7);
    v17 = pStart;
    if ( pStart < pEnd )
    {
      v18 = &v16->nCatches;
      do
      {
        if ( v15 >= *(v18 - 3) && v15 <= *(v18 - 2) )
        {
          if ( *(_DWORD *)(GetImageBase() + v18[1] + 20i64 * *v18 - 16) )
          {
            v19 = *(signed int *)(GetImageBase() + v18[1] + 20i64 * *v18 - 16);
            v20 = v19 + GetImageBase();
          }
          else
          {
            v20 = 0i64;
          }
          if ( !v20
            || (!*(_DWORD *)(GetImageBase() + v18[1] + 20i64 * *v18 - 16) ? (v22 = 0i64) : (v21 = *(signed int *)(GetImageBase() + v18[1] + 20i64 * *v18 - 16),
                                                                                            v22 = v21 + GetImageBase()),
                !*(_BYTE *)(v22 + 16)) )
          {
            if ( !(*(_BYTE *)(GetImageBase() + v18[1] + 20i64 * *v18 - 20) & 0x40) )
            {
              v23 = GetImageBase();
              CatchIt(
                v10,
                v9,
                pContexta,
                v7,
                v12,
                (_s_HandlerType *)(v18[1] + v23 + 20i64 * (*v18 - 1)),
                0i64,
                (_s_TryBlockMapEntry *)(v18 - 3));
            }
          }
          v17 = pStart;
        }
        ++v17;
        v18 += 5;
        pStart = v17;
      }
      while ( v17 < pEnd );
    }
  }
}

// File Line: 910
// RVA: 0x12C5020
signed __int64 __fastcall _TypeMatch(_s_HandlerType *pCatch, _s_CatchableType *pCatchable, _s_ThrowInfo *pThrow)
{
  __int64 v3; // rsi
  unsigned int v4; // ebx
  _s_ThrowInfo *v5; // r14
  _s_CatchableType *v6; // rbp
  _s_HandlerType *v7; // rdi
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rsi
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rax

  LODWORD(v3) = pCatch->dispType;
  v4 = 0;
  v5 = pThrow;
  v6 = pCatchable;
  v7 = pCatch;
  if ( (_DWORD)v3 )
    v8 = (signed int)v3 + GetImageBase();
  else
    v8 = 0i64;
  if ( !v8 )
    return 1i64;
  if ( (_DWORD)v3 )
  {
    v3 = v7->dispType;
    v9 = v3 + GetImageBase();
  }
  else
  {
    v9 = 0i64;
  }
  if ( !*(_BYTE *)(v9 + 16) )
    return 1i64;
  if ( (_DWORD)v3 )
    v10 = v7->dispType + GetImageBase();
  else
    v10 = 0i64;
  if ( v10 != v6->pType + GetThrowImageBase() )
  {
    v11 = v7->dispType ? v7->dispType + GetImageBase() : 0i64;
    v12 = GetThrowImageBase();
    if ( strcmp((const char *)(v11 + 16), (const char *)(v12 + v6->pType + 16i64)) )
      return 0i64;
  }
  if ( (!(v6->properties & 2) || v7->adjectives & 8)
    && (!(v5->attributes & 1) || v7->adjectives & 1)
    && (!(v5->attributes & 4) || v7->adjectives & 4)
    && (!(v5->attributes & 2) || v7->adjectives & 2) )
  {
    v4 = 1;
  }
  return v4;
}

// File Line: 946
// RVA: 0x12C4C14
__int64 __fastcall _FrameUnwindFilter(_EXCEPTION_POINTERS *pExPtrs)
{
  _EXCEPTION_RECORD *v1; // rax
  _tiddata *v2; // rax

  v1 = pExPtrs->ExceptionRecord;
  if ( pExPtrs->ExceptionRecord->ExceptionCode == -532462766 || v1->ExceptionCode == -532459699 )
  {
    if ( getptd()->_ProcessingThrow > 0 )
    {
      v2 = getptd();
      --v2->_ProcessingThrow;
    }
  }
  else if ( v1->ExceptionCode == -529697949 )
  {
    getptd()->_ProcessingThrow = 0;
    terminate();
  }
  return 0i64;
}

// File Line: 1017
// RVA: 0x12C4C68
void __fastcall _FrameUnwindToState(unsigned __int64 *pRN, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo, int targetState)
{
  int v4; // er12
  _s_FuncInfo *v5; // rsi
  _xDISPATCHER_CONTEXT *v6; // r13
  unsigned __int64 *v7; // r15
  int v8; // edi
  _tiddata *v9; // rax
  __int64 v10; // r14
  __int64 v11; // rbx
  unsigned __int64 v12; // rax
  __int64 v13; // rbx
  unsigned __int64 v14; // rax
  _tiddata *v15; // rax
  unsigned __int64 ImageBaseToRestore; // [rsp+28h] [rbp-40h]

  v4 = targetState;
  v5 = pFuncInfo;
  v6 = pDC;
  v7 = pRN;
  ImageBaseToRestore = GetImageBase();
  v8 = __GetCurrentState(v7, v6, v5);
  v9 = getptd();
  ++v9->_ProcessingThrow;
  while ( v8 != -1 && v8 > v4 )
  {
    if ( v8 <= -1 || v8 >= v5->maxState )
      _inconsistency();
    v10 = v8;
    v8 = *(_DWORD *)(v5->dispUnwindMap + GetImageBase() + 8i64 * v8);
    if ( *(_DWORD *)(v5->dispUnwindMap + GetImageBase() + 8 * v10 + 4) )
    {
      v11 = *(signed int *)(v5->dispUnwindMap + GetImageBase() + 8 * v10 + 4);
      v12 = v11 + GetImageBase();
    }
    else
    {
      v12 = 0i64;
    }
    if ( v12 )
    {
      __SetState(v7, v6, v5, v8);
      if ( *(_DWORD *)(v5->dispUnwindMap + GetImageBase() + 8 * v10 + 4) )
      {
        v13 = *(signed int *)(v5->dispUnwindMap + GetImageBase() + 8 * v10 + 4);
        v14 = v13 + GetImageBase();
      }
      else
      {
        v14 = 0i64;
      }
      CallSettingFrame(v14, v7, 259i64);
      SetImageBase(ImageBaseToRestore);
    }
  }
  if ( getptd()->_ProcessingThrow > 0 )
  {
    v15 = getptd();
    --v15->_ProcessingThrow;
  }
  if ( v8 != -1 && v8 > v4 )
    _inconsistency();
  __SetState(v7, v6, v5, v8);
}

// File Line: 1068
// RVA: 0x1452152
__FrameUnwindToState$filt$0

// File Line: 1074
// RVA: 0x1452168
__FrameUnwindToState$fin$1

// File Line: 1134
// RVA: 0x12C3E60
void __fastcall CatchIt(EHExceptionRecord *pExcept, unsigned __int64 *pRN, _CONTEXT *pContext, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo, _s_HandlerType *pCatch, _s_CatchableType *pConv, _s_TryBlockMapEntry *pEntry)
{
  unsigned __int64 *v8; // r14
  _CONTEXT *v9; // r12
  EHExceptionRecord *v10; // rbx
  unsigned __int64 *v11; // rax
  _s_HandlerType *v12; // rsi
  unsigned __int64 *v13; // rdi
  unsigned __int64 v14; // rax
  __int64 v15; // [rsp+88h] [rbp+10h]

  v8 = pRN;
  v9 = pContext;
  v10 = pExcept;
  v11 = _GetEstablisherFrame(pRN, pDC, pFuncInfo, (unsigned __int64 *)&v15);
  v12 = pCatch;
  v13 = v11;
  if ( pConv )
    _BuildCatchObject(v10, v11, pCatch, pConv);
  v14 = GetImageBase();
  UnwindNestedFrames(v8, v10, v9, v13, (void *)(v12->dispOfHandler + v14), pEntry->tryLow);
}

// File Line: 1222
// RVA: 0x12C4A10
__int64 __fastcall _CxxCallCatchBlock(_EXCEPTION_RECORD *pExcept)
{
  _EXCEPTION_RECORD *v1; // rdi
  void *v2; // r13
  EHExceptionRecord *v3; // rsi
  void *v4; // rbx
  _QWORD *v5; // r14
  _tiddata *v6; // rax
  FrameInfo *v7; // r12
  __int64 v8; // rbx
  unsigned __int64 v10; // [rsp+48h] [rbp-80h]
  unsigned __int64 v11; // [rsp+58h] [rbp-70h]
  FrameInfo pFrameInfo; // [rsp+78h] [rbp-50h]
  void *v13; // [rsp+E0h] [rbp+18h]
  void *v14; // [rsp+E8h] [rbp+20h]

  v1 = pExcept;
  v2 = getptd()->_curcontext;
  v13 = getptd()->_curexception;
  v3 = (EHExceptionRecord *)v1->ExceptionInformation[6];
  v10 = v1->ExceptionInformation[5];
  v4 = (void *)v1->ExceptionInformation[4];
  v11 = v1->ExceptionInformation[2];
  v5 = (_QWORD *)v1->ExceptionInformation[1];
  getptd()->_curexception = v3;
  getptd()->_curcontext = v4;
  v6 = getptd();
  v7 = CreateFrameInfo(&pFrameInfo, *((void **)v6->_curexception + 5));
  if ( v1->ExceptionInformation[7] )
    v14 = getptd()->_pForeignException;
  v8 = CallSettingFrame(v11, v5, 256i64);
  FindAndUnlinkFrame(v7);
  if ( v3->ExceptionCode == -529697949
    && v3->NumberParameters == 4
    && v3->params.magicNumber - 429065504 <= 2
    && (unsigned int)IsExceptionObjectToBeDestroyed(v3->params.pExceptionObject) )
  {
    _DestructExceptionObject(v3, 1);
  }
  getptd()->_curexception = v13;
  getptd()->_curcontext = v2;
  *(_QWORD *)(*(signed int *)(v10 + 28) + *v5) = -2i64;
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
__int64 __fastcall _BuildCatchObjectHelper(EHExceptionRecord *pExcept, void *pRN, _s_HandlerType *pCatch, _s_CatchableType *pConv)
{
  _s_CatchableType *v4; // rsi
  _s_HandlerType *v5; // rbx
  void **v6; // r14
  EHExceptionRecord *v7; // r13
  unsigned int v8; // edi
  int v9; // er15
  unsigned __int64 v10; // rdx
  unsigned __int64 v11; // rcx
  void *v12; // rcx
  unsigned __int64 v13; // rcx
  bool v14; // zf
  void *v15; // rcx
  size_t v16; // rbx
  char *v17; // rax
  unsigned int v18; // edx
  void *v19; // rcx

  v4 = pConv;
  v5 = pCatch;
  v6 = (void **)pRN;
  v7 = pExcept;
  v8 = 0;
  v9 = pCatch->dispType;
  if ( v9 )
    v10 = v9 + GetImageBase();
  else
    v10 = 0i64;
  if ( v10 )
  {
    v11 = v9 ? v5->dispType + GetImageBase() : 0i64;
    if ( *(_BYTE *)(v11 + 16) && (v5->dispCatchObj || (v5->adjectives & 0x80000000) != 0) )
    {
      if ( (v5->adjectives & 0x80000000) == 0 )
        v6 = (void **)((char *)*v6 + v5->dispCatchObj);
      if ( v5->adjectives & 8 )
      {
        if ( _ValidateWrite(v7->params.pExceptionObject, 1u) && _ValidateWrite(v6, 1u) )
        {
          v12 = v7->params.pExceptionObject;
          *v6 = v12;
LABEL_17:
          *v6 = _AdjustPointer(v12, &v4->thisDisplacement);
          return v8;
        }
      }
      else if ( v4->properties & 1 )
      {
        if ( _ValidateWrite(v7->params.pExceptionObject, 1u) && _ValidateWrite(v6, 1u) )
        {
          memmove(v6, v7->params.pExceptionObject, v4->sizeOrOffset);
          if ( v4->sizeOrOffset != 8 || !*v6 )
            return v8;
          v12 = *v6;
          goto LABEL_17;
        }
      }
      else
      {
        if ( v4->copyFunction )
          v13 = v4->copyFunction + GetThrowImageBase();
        else
          v13 = 0i64;
        v14 = v13 == 0;
        v15 = v7->params.pExceptionObject;
        if ( v14 )
        {
          if ( _ValidateWrite(v15, 1u) && _ValidateWrite(v6, 1u) )
          {
            v16 = v4->sizeOrOffset;
            v17 = _AdjustPointer(v7->params.pExceptionObject, &v4->thisDisplacement);
            memmove(v6, v17, v16);
            return v8;
          }
        }
        else if ( _ValidateWrite(v15, 1u) && _ValidateWrite(v6, 1u) )
        {
          v19 = (void *)(v4->copyFunction ? v4->copyFunction + GetThrowImageBase() : 0i64);
          if ( _ValidateWrite(v19, v18) )
            return (unsigned int)((v4->properties & 4) != 0) + 1;
        }
      }
      _inconsistency();
    }
  }
  return 0i64;
}

// File Line: 1626
// RVA: 0x12C4758
void __fastcall _BuildCatchObject(EHExceptionRecord *pExcept, void *pRN, _s_HandlerType *pCatch, _s_CatchableType *pConv)
{
  _s_CatchableType *v4; // rdi
  EHExceptionRecord *v5; // r14
  void *v6; // rsi
  int v7; // eax
  void (__fastcall *v8)(void *, char *, signed __int64); // rbx
  char *v9; // rax
  void (__fastcall *v10)(void *, char *); // rbx
  char *v11; // rax

  v4 = pConv;
  v5 = pExcept;
  if ( (pCatch->adjectives & 0x80000000) == 0 )
    v6 = (void *)(*(_QWORD *)pRN + pCatch->dispCatchObj);
  else
    v6 = pRN;
  v7 = _BuildCatchObjectHelper(pExcept, pRN, pCatch, pConv) - 1;
  if ( v7 )
  {
    if ( v7 == 1 )
    {
      v8 = 0i64;
      if ( v4->copyFunction )
        v8 = (void (__fastcall *)(void *, char *, signed __int64))(v4->copyFunction + GetThrowImageBase());
      v9 = _AdjustPointer(v5->params.pExceptionObject, &v4->thisDisplacement);
      v8(v6, v9, 1i64);
    }
  }
  else
  {
    v10 = 0i64;
    if ( v4->copyFunction )
      v10 = (void (__fastcall *)(void *, char *))(GetThrowImageBase() + v4->copyFunction);
    v11 = _AdjustPointer(v5->params.pExceptionObject, &v4->thisDisplacement);
    v10(v6, v11);
  }
}

// File Line: 1699
// RVA: 0x12C3D80
void __fastcall _DestructExceptionObject(EHExceptionRecord *pExcept, char fThrowNotAllowed)
{
  _s_ThrowInfo *v2; // rax
  __int64 v3; // rcx

  if ( pExcept )
  {
    if ( pExcept->ExceptionCode == -529697949
      && pExcept->NumberParameters == 4
      && pExcept->params.magicNumber - 429065504 <= 2 )
    {
      v2 = pExcept->params.pThrowInfo;
      if ( v2 )
      {
        if ( v2->pmfnUnwind )
        {
          ((void (__fastcall *)(void *))((char *)pExcept->params.pThrowImageBase + v2->pmfnUnwind))(pExcept->params.pExceptionObject);
        }
        else if ( v2->attributes & 0x10 )
        {
          v3 = *(_QWORD *)pExcept->params.pExceptionObject;
          if ( v3 )
            (*(void (**)(void))(*(_QWORD *)v3 + 16i64))();
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
char *__fastcall _AdjustPointer(void *pThis, PMD *pmd)
{
  char *result; // rax

  result = (char *)pThis + pmd->mdisp;
  if ( pmd->pdisp >= 0 )
    result += pmd->pdisp + (signed __int64)*(signed int *)(pmd->vdisp + *(_QWORD *)((char *)pThis + pmd->pdisp));
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
  _s_ESTypeList *v2; // rsi
  EHExceptionRecord *v3; // r13
  int v4; // edi
  char v5; // r14
  signed int *v6; // r15
  int v7; // ebp
  _s_CatchableType *v8; // rbx
  unsigned __int64 v9; // rax

  v2 = pESTypeList;
  v3 = pExcept;
  if ( !pESTypeList )
    _inconsistency();
  v4 = 0;
  v5 = 0;
  if ( pESTypeList->nCount > 0 )
  {
    do
    {
      v6 = (signed int *)(GetThrowImageBase() + v3->params.pThrowInfo->pCatchableTypeArray + 4i64);
      v7 = *(_DWORD *)(GetThrowImageBase() + v3->params.pThrowInfo->pCatchableTypeArray);
      if ( v7 > 0 )
      {
        while ( 1 )
        {
          v8 = (_s_CatchableType *)(*v6 + GetThrowImageBase());
          v9 = GetImageBase();
          if ( _TypeMatch((_s_HandlerType *)(v9 + 20i64 * v4 + v2->dispTypeArray), v8, v3->params.pThrowInfo) )
            break;
          --v7;
          ++v6;
          if ( v7 <= 0 )
            goto LABEL_8;
        }
        v5 = 1;
      }
LABEL_8:
      ++v4;
    }
    while ( v4 < v2->nCount );
  }
  return v5;
}

