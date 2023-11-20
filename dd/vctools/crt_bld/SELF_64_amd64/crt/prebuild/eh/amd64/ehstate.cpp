// File Line: 25
// RVA: 0x12C51E4
signed __int64 __fastcall __StateFromIp(_s_FuncInfo *pFuncInfo, _xDISPATCHER_CONTEXT *pDC, __int64 Ip)
{
  __int64 v3; // rbp
  _s_FuncInfo *v4; // rbx
  unsigned int v5; // edi
  unsigned int v6; // ecx
  __int64 v7; // r8
  __int64 v8; // r9
  signed int *v9; // rdx
  signed __int64 result; // rax

  v3 = Ip;
  v4 = pFuncInfo;
  if ( !pFuncInfo )
    _inconsistency();
  v5 = pFuncInfo->nIPMapEntries;
  if ( !(pDC->ImageBase + pFuncInfo->dispIPtoStateMap) )
    _inconsistency();
  v6 = 0;
  if ( !v5 )
    goto LABEL_14;
  v7 = pDC->ImageBase;
  v8 = v4->dispIPtoStateMap;
  v9 = (signed int *)(v7 + v8);
  do
  {
    if ( v3 < v7 + *v9 )
      break;
    ++v6;
    v9 += 2;
  }
  while ( v6 < v5 );
  if ( v6 )
    result = *(unsigned int *)(v7 + 8i64 * (v6 - 1) + v8 + 4);
  else
LABEL_14:
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 55
// RVA: 0x12C51DC
int __fastcall __StateFromControlPc(_s_FuncInfo *pFuncInfo, _xDISPATCHER_CONTEXT *pDC)
{
  return __StateFromIp(pFuncInfo, pDC, pDC->ControlPc);
}

// File Line: 68
// RVA: 0x12C5140
int __fastcall __GetCurrentState(unsigned __int64 *pFrame, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo)
{
  int result; // eax

  result = *(_DWORD *)(pFuncInfo->dispUwindHelp + *pFrame);
  if ( result == -2 )
    result = __StateFromIp(pFuncInfo, pDC, pDC->ControlPc);
  return result;
}

// File Line: 82
// RVA: 0x12C5194
void __fastcall __SetState(unsigned __int64 *pRN, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo, int newState)
{
  *(_DWORD *)(pFuncInfo->dispUwindHelp + *pRN) = newState;
}

// File Line: 91
// RVA: 0x12C51A0
void __fastcall __SetUnwindTryBlock(unsigned __int64 *pRN, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo, int curState)
{
  int v4; // edi
  _s_FuncInfo *v5; // rbx
  unsigned __int64 v6; // rcx
  __int64 v7; // rax
  unsigned __int64 pEstablisher; // [rsp+40h] [rbp+18h]

  v4 = curState;
  v5 = pFuncInfo;
  v6 = *_GetEstablisherFrame(pRN, pDC, pFuncInfo, &pEstablisher);
  v7 = v5->dispUwindHelp;
  pEstablisher = v6;
  if ( v4 > *(_DWORD *)(v7 + v6 + 4) )
    *(_DWORD *)(v7 + v6 + 4) = v4;
}

// File Line: 103
// RVA: 0x12C5168
__int64 __fastcall __GetUnwindTryBlock(unsigned __int64 *pRN, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo)
{
  _s_FuncInfo *v3; // rbx
  unsigned __int64 v4; // rcx
  __int64 v5; // rax
  unsigned __int64 pEstablisher; // [rsp+40h] [rbp+18h]

  v3 = pFuncInfo;
  v4 = *_GetEstablisherFrame(pRN, pDC, pFuncInfo, &pEstablisher);
  v5 = v3->dispUwindHelp;
  pEstablisher = v4;
  return *(unsigned int *)(v5 + v4 + 4);
}

