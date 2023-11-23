// File Line: 25
// RVA: 0x12C51E4
__int64 __fastcall __StateFromIp(_s_FuncInfo *pFuncInfo, _xDISPATCHER_CONTEXT *pDC, __int64 Ip)
{
  unsigned int nIPMapEntries; // edi
  unsigned int v6; // ecx
  __int64 ImageBase; // r8
  __int64 dispIPtoStateMap; // r9
  int *v9; // rdx

  if ( !pFuncInfo )
    _inconsistency();
  nIPMapEntries = pFuncInfo->nIPMapEntries;
  if ( !(pDC->ImageBase + pFuncInfo->dispIPtoStateMap) )
    _inconsistency();
  v6 = 0;
  if ( !nIPMapEntries )
    return 0xFFFFFFFFi64;
  ImageBase = pDC->ImageBase;
  dispIPtoStateMap = pFuncInfo->dispIPtoStateMap;
  v9 = (int *)(ImageBase + dispIPtoStateMap);
  do
  {
    if ( Ip < ImageBase + *v9 )
      break;
    ++v6;
    v9 += 2;
  }
  while ( v6 < nIPMapEntries );
  if ( v6 )
    return *(unsigned int *)(ImageBase + 8i64 * (v6 - 1) + dispIPtoStateMap + 4);
  else
    return 0xFFFFFFFFi64;
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
    return __StateFromIp(pFuncInfo, pDC, pDC->ControlPc);
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
void __fastcall __SetUnwindTryBlock(
        unsigned __int64 *pRN,
        _xDISPATCHER_CONTEXT *pDC,
        _s_FuncInfo *pFuncInfo,
        int curState)
{
  unsigned __int64 v6; // rcx
  __int64 dispUwindHelp; // rax
  unsigned __int64 pEstablisher; // [rsp+40h] [rbp+18h] BYREF

  v6 = *_GetEstablisherFrame(pRN, pDC, pFuncInfo, &pEstablisher);
  dispUwindHelp = pFuncInfo->dispUwindHelp;
  pEstablisher = v6;
  if ( curState > *(_DWORD *)(dispUwindHelp + v6 + 4) )
    *(_DWORD *)(dispUwindHelp + v6 + 4) = curState;
}

// File Line: 103
// RVA: 0x12C5168
__int64 __fastcall __GetUnwindTryBlock(unsigned __int64 *pRN, _xDISPATCHER_CONTEXT *pDC, _s_FuncInfo *pFuncInfo)
{
  unsigned __int64 v4; // rcx
  __int64 dispUwindHelp; // rax
  unsigned __int64 pEstablisher; // [rsp+40h] [rbp+18h] BYREF

  v4 = *_GetEstablisherFrame(pRN, pDC, pFuncInfo, &pEstablisher);
  dispUwindHelp = pFuncInfo->dispUwindHelp;
  pEstablisher = v4;
  return *(unsigned int *)(dispUwindHelp + v4 + 4);
}

