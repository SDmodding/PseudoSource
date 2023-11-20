// File Line: 41
// RVA: 0x12AD364
unsigned __int64 *__fastcall _GetEstablisherFrame(unsigned __int64 *pRN, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo, unsigned __int64 *pEstablisher)
{
  __int64 v4; // rdi
  unsigned __int64 *v5; // r12
  unsigned __int64 *v6; // rsi
  _s_FuncInfo *v7; // r14
  _xDISPATCHER_CONTEXT *v8; // r15
  int v9; // eax
  int v10; // ebp
  _DWORD *v11; // rbx
  PRUNTIME_FUNCTION v12; // rax
  unsigned int v13; // er9
  unsigned __int64 v14; // r8
  __int64 v15; // rcx
  _DWORD *v16; // rdx
  unsigned __int64 ImageBase; // [rsp+50h] [rbp+8h]

  LODWORD(v4) = pFuncInfo->nTryBlocks;
  v5 = pRN;
  v6 = pEstablisher;
  v7 = pFuncInfo;
  v8 = pDC;
  v9 = __StateFromControlPc(pFuncInfo, pDC);
  *v6 = *v5;
  v10 = v9;
  while ( (_DWORD)v4 )
  {
    v4 = (unsigned int)(v4 - 1);
    v11 = (_DWORD *)(v8->ImageBase + v7->dispTryBlockMap + 20 * v4);
    if ( v10 > v11[1] && v10 <= v11[2] )
    {
      v12 = RtlLookupFunctionEntry(v8->ControlPc, &ImageBase, 0i64);
      v13 = v11[3];
      v14 = ImageBase + (signed int)v11[4];
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
        *v6 = *(_QWORD *)(*(signed int *)(v14 + 20 * v15 + 16) + *v5);
        return v6;
      }
    }
  }
  return v6;
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
  _s_FuncInfo *v3; // rdi
  _xDISPATCHER_CONTEXT *v4; // rbp
  unsigned __int64 *v5; // r14
  int v6; // eax
  unsigned int v7; // ebx
  int v8; // esi
  unsigned __int64 v9; // rcx
  int v10; // er9
  unsigned __int64 pEstablisher; // [rsp+50h] [rbp+18h]

  v3 = pFuncInfo;
  v4 = pDC;
  v5 = _GetEstablisherFrame(pRN, pDC, pFuncInfo, &pEstablisher);
  v6 = __StateFromControlPc(v3, v4);
  v7 = v3->nTryBlocks;
  v8 = v6;
  while ( v7 )
  {
    v9 = v3->dispTryBlockMap + getptd()->_ImageBase + 20i64 * --v7;
    if ( v8 > *(_DWORD *)(v9 + 4) && v8 <= *(_DWORD *)(v9 + 8) )
      goto LABEL_6;
  }
  v9 = 0i64;
LABEL_6:
  if ( v9 )
    v10 = *(_DWORD *)(v9 + 4);
  else
    v10 = -1;
  _FrameUnwindToState(v5, v4, v3, v10);
}

// File Line: 185
// RVA: 0x12AD9A0
_EXCEPTION_DISPOSITION __fastcall _CxxFrameHandler3(EHExceptionRecord *pExcept, unsigned __int64 RN, _CONTEXT *pContext, _xDISPATCHER_CONTEXT *pDC)
{
  _xDISPATCHER_CONTEXT *v4; // rbx
  _CONTEXT *v5; // rdi
  EHExceptionRecord *v6; // rsi
  _tiddata *v7; // rax
  unsigned __int64 pRN; // [rsp+50h] [rbp+8h]

  v4 = pDC;
  v5 = pContext;
  v6 = pExcept;
  pRN = RN;
  getptd()->_ImageBase = pDC->ImageBase;
  getptd()->_ThrowImageBase = (unsigned __int64)v6->params.pThrowImageBase;
  v7 = getptd();
  return _InternalCxxFrameHandler(
           v6,
           &pRN,
           v5,
           v4,
           (_s_FuncInfo *)(v7->_ImageBase + *(unsigned int *)v4->HandlerData),
           0,
           0i64,
           0);
}

// File Line: 234
// RVA: 0x12AD5F0
signed __int64 __fastcall __SehTransFilter(_EXCEPTION_POINTERS *ExPtrs, EHExceptionRecord *pExcept, unsigned __int64 *pRN, _CONTEXT *pContext, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo, int *pResult)
{
  _CONTEXT *v7; // rsi
  unsigned __int64 *v8; // rbp
  EHExceptionRecord **v9; // rdi
  EHExceptionRecord *v10; // rbx
  signed __int64 result; // rax

  v7 = pContext;
  v8 = pRN;
  v9 = (EHExceptionRecord **)ExPtrs;
  getptd()->_pForeignException = pExcept;
  v10 = *v9;
  getptd()->_ThrowImageBase = (unsigned __int64)v10->params.pThrowImageBase;
  _InternalCxxFrameHandler(*v9, v8, v7, pDC, pFuncInfo, 0, 0i64, 1);
  getptd()->_pForeignException = 0i64;
  result = 1i64;
  *pResult = 1;
  return result;
}

// File Line: 258
// RVA: 0x12AD694
__int64 __fastcall CallSETranslator(EHExceptionRecord *pExcept, unsigned __int64 *pRN, _CONTEXT *pContext, _xDISPATCHER_CONTEXT *pDC)
{
  EHExceptionRecord *v4; // rbx
  _tiddata *v5; // rax
  _s_FuncInfo *v7; // [rsp+48h] [rbp-20h]
  int *pResult; // [rsp+50h] [rbp-18h]

  v4 = pExcept;
  v7 = (_s_FuncInfo *)pExcept;
  pResult = (int *)pContext;
  v5 = getptd();
  ((void (__fastcall *)(_QWORD, _s_FuncInfo **))v5->_translator)(v4->ExceptionCode, &v7);
  return 0i64;
}

// File Line: 281
// RVA: 0x1451C20
_CallSETranslator$filt$0

// File Line: 331
// RVA: 0x12AD430
_s_TryBlockMapEntry *__fastcall _GetRangeOfTrysToCheck(unsigned __int64 *pRN, _s_FuncInfo *pFuncInfo, int CatchDepth, int curState, unsigned int *pStart, unsigned int *pEnd, _xDISPATCHER_CONTEXT *pDC)
{
  unsigned int v7; // edi
  _s_FuncInfo *v8; // rbx
  int v9; // er12
  __int64 v10; // rsi
  int v11; // er14
  unsigned int v12; // edx
  __int64 v13; // r11
  __int64 v14; // r9
  __int64 v15; // rax
  unsigned int v16; // edx
  __int64 v17; // r9
  int *v18; // rcx
  __int64 v19; // rax

  v7 = pFuncInfo->nTryBlocks;
  v8 = pFuncInfo;
  v9 = curState;
  v10 = 0i64;
  v11 = __StateFromControlPc(pFuncInfo, pDC);
  if ( !v7 )
    _inconsistency();
  v12 = v7;
  *pEnd = -1;
  *pStart = -1;
  if ( v7 )
  {
    v13 = v8->dispTryBlockMap;
    do
    {
      v14 = v12 - 1;
      v15 = pDC->ImageBase + 20 * v14;
      if ( v11 > *(_DWORD *)(v15 + v13 + 4) && v11 <= *(_DWORD *)(v15 + v13 + 8) )
        break;
      --v12;
    }
    while ( (_DWORD)v14 );
  }
  if ( v12 )
    v10 = pDC->ImageBase + v8->dispTryBlockMap + 20i64 * (v12 - 1);
  v16 = 0;
  if ( v7 )
  {
    v17 = 0i64;
    do
    {
      v18 = (int *)(v17 + pDC->ImageBase + v8->dispTryBlockMap);
      if ( (!v10 || *v18 > *(_DWORD *)(v10 + 4) && v18[1] <= *(_DWORD *)(v10 + 8)) && v9 >= *v18 && v9 <= v18[1] )
      {
        if ( *pStart == -1 )
          *pStart = v16;
        *pEnd = v16 + 1;
      }
      ++v16;
      v17 += 20i64;
    }
    while ( v16 < v7 );
    v19 = *pStart;
    if ( (_DWORD)v19 != -1 )
      return (_s_TryBlockMapEntry *)(pDC->ImageBase + v8->dispTryBlockMap + 20 * v19);
  }
  *pStart = 0;
  *pEnd = 0;
  return 0i64;
}

// File Line: 377
// RVA: 0x12AD6E8
FrameInfo *__fastcall CreateFrameInfo(FrameInfo *pFrameInfo, void *pExceptionObject)
{
  FrameInfo *v2; // rbx
  FrameInfo *v3; // rcx

  v2 = pFrameInfo;
  pFrameInfo->pExceptionObject = pExceptionObject;
  if ( pFrameInfo >= getptd()->_pFrameInfoChain )
    v3 = 0i64;
  else
    v3 = (FrameInfo *)getptd()->_pFrameInfoChain;
  v2->pNext = v3;
  getptd()->_pFrameInfoChain = v2;
  return v2;
}

// File Line: 395
// RVA: 0x12AD7BC
signed __int64 __fastcall IsExceptionObjectToBeDestroyed(void *pExceptionObject)
{
  void *v1; // rbx
  void **i; // rdx

  v1 = pExceptionObject;
  for ( i = (void **)getptd()->_pFrameInfoChain; ; i = (void **)i[1] )
  {
    if ( !i )
      return 1i64;
    if ( *i == v1 )
      break;
  }
  return 0i64;
}

// File Line: 415
// RVA: 0x12AD72C
void __fastcall FindAndUnlinkFrame(FrameInfo *pFrameInfo)
{
  FrameInfo *v1; // rdi
  FrameInfo *i; // rbx

  v1 = pFrameInfo;
  if ( pFrameInfo != getptd()->_pFrameInfoChain )
    _inconsistency();
  for ( i = (FrameInfo *)getptd()->_pFrameInfoChain; ; i = i->pNext )
  {
    if ( !i )
      _inconsistency();
    if ( v1 == i )
      break;
  }
  getptd()->_pFrameInfoChain = i->pNext;
}

// File Line: 444
// RVA: 0x12AD828
void __fastcall UnwindNestedFrames(unsigned __int64 *pFrame, EHExceptionRecord *pExcept, _CONTEXT *pContext, unsigned __int64 *pEstablisher, void *Handler, int TargetUnwindState)
{
  EHExceptionRecord *v6; // r14
  _EXCEPTION_RECORD *v7; // rdx
  unsigned __int64 *v8; // r15
  char *v9; // rcx
  unsigned __int64 *v10; // rdi
  signed __int64 v11; // rax
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __int128 v15; // xmm0
  __int128 v16; // xmm1
  __int128 v17; // xmm0
  __int128 v18; // xmm1
  void *v19; // rax
  void *v20; // rdx
  void *v21; // rcx
  _UNWIND_HISTORY_TABLE *HistoryTable; // rax
  char Dst; // [rsp+30h] [rbp-B8h]
  void *(__fastcall *v24)(_EXCEPTION_RECORD *); // [rsp+50h] [rbp-98h]
  unsigned __int64 *v25; // [rsp+58h] [rbp-90h]
  __int64 v26; // [rsp+60h] [rbp-88h]
  EHExceptionRecord *v27; // [rsp+68h] [rbp-80h]
  __int64 v28; // [rsp+70h] [rbp-78h]
  __int64 v29; // [rsp+78h] [rbp-70h]
  _CONTEXT ContextRecord; // [rsp+B8h] [rbp-30h]
  __int64 v31; // [rsp+5D8h] [rbp+4F0h]
  int v32; // [rsp+5E0h] [rbp+4F8h]
  __int64 v33; // [rsp+5E8h] [rbp+500h]

  v6 = pExcept;
  v7 = &ExceptionTemplate;
  v8 = pFrame;
  v9 = &Dst;
  v10 = pEstablisher;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)&ExceptionTemplate) & 0xF )
  {
    memmove(&Dst, &ExceptionTemplate, 0x98ui64);
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
    v19 = v7->ExceptionAddress;
    *(_OWORD *)v9 = *(_OWORD *)&v7->ExceptionCode;
    *((_QWORD *)v9 + 2) = v19;
  }
  v20 = *(void **)Handler;
  v21 = (void *)*v8;
  v24 = _CxxCallCatchBlock;
  v26 = v31;
  v27 = (EHExceptionRecord *)v32;
  v25 = v10;
  v29 = v33;
  v28 = (unsigned __int8)TargetUnwindState;
  HistoryTable = (_UNWIND_HISTORY_TABLE *)*((_QWORD *)Handler + 8);
  v27 = v6;
  v29 = 429065504i64;
  RtlUnwindEx(v21, v20, (PEXCEPTION_RECORD)&Dst, 0i64, &ContextRecord, HistoryTable);
}

