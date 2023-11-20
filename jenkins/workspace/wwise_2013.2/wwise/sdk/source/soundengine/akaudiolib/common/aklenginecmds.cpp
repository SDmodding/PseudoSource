// File Line: 31
// RVA: 0x15BE090
__int64 dynamic_initializer_for__CAkLEngineCmds::m_listSrcsNotConnected__()
{
  return atexit(dynamic_atexit_destructor_for__CAkLEngineCmds::m_listSrcsNotConnected__);
}

// File Line: 33
// RVA: 0x15BE080
__int64 dynamic_initializer_for__CAkLEngineCmds::m_listCmd__()
{
  return atexit(dynamic_atexit_destructor_for__CAkLEngineCmds::m_listCmd__);
}

// File Line: 37
// RVA: 0xA79F30
signed __int64 __fastcall CAkLEngineCmds::Init()
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v0; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v1; // rcx
  signed __int64 result; // rax
  unsigned int v3; // edx
  signed __int64 v4; // rax

  CAkLEngineCmds::m_ulPlayEventID = 0;
  CAkLEngineCmds::m_listCmd.m_ulNumListItems = 0;
  CAkLEngineCmds::m_listCmd.m_ulMaxNumListItems = -1;
  CAkLEngineCmds::m_listCmd.m_pFree = 0i64;
  v0 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                  g_LEngineDefaultPoolId,
                                                                                  0x4000ui64);
  v1 = v0;
  CAkLEngineCmds::m_listCmd.m_pvMemStart = v0;
  if ( v0 )
  {
    CAkLEngineCmds::m_listCmd.m_ulMinNumListItems = 512;
    CAkLEngineCmds::m_listCmd.m_pFree = v0;
    v3 = 0;
    do
    {
      v4 = (signed __int64)&v1[1];
      ++v3;
      v1->pNextListItem = v1 + 1;
      ++v1;
    }
    while ( v3 < CAkLEngineCmds::m_listCmd.m_ulMinNumListItems );
    *(_QWORD *)(v4 - 32) = 0i64;
    result = 1i64;
  }
  else
  {
    result = 52i64;
  }
  CAkLEngineCmds::m_listCmd.m_pFirst = 0i64;
  CAkLEngineCmds::m_listCmd.m_pLast = 0i64;
  return result;
}

// File Line: 43
// RVA: 0xA7A6E0
void CAkLEngineCmds::Term(void)
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v0; // rdx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v1; // rcx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v2; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v3; // rcx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v4; // rbx

  CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst = 0i64;
  CAkLEngineCmds::m_listSrcsNotConnected.m_pLast = 0i64;
  if ( CAkLEngineCmds::m_listCmd.m_ulMaxNumListItems )
  {
    v0 = CAkLEngineCmds::m_listCmd.m_pFree;
    while ( 1 )
    {
      v1 = CAkLEngineCmds::m_listCmd.m_pFirst;
      if ( !CAkLEngineCmds::m_listCmd.m_pFirst )
        break;
      CAkLEngineCmds::m_listCmd.m_pFirst = CAkLEngineCmds::m_listCmd.m_pFirst->pNextListItem;
      v2 = CAkLEngineCmds::m_listCmd.m_pLast;
      if ( v1 == CAkLEngineCmds::m_listCmd.m_pLast )
        v2 = 0i64;
      CAkLEngineCmds::m_listCmd.m_pLast = v2;
      if ( v1 < CAkLEngineCmds::m_listCmd.m_pvMemStart
        || v1 >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
        v0 = CAkLEngineCmds::m_listCmd.m_pFree;
        --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
      }
      else
      {
        v1->pNextListItem = v0;
        --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
        v0 = v1;
        CAkLEngineCmds::m_listCmd.m_pFree = v1;
      }
    }
    v3 = CAkLEngineCmds::m_listCmd.m_pvMemStart;
    if ( v0 )
    {
      do
      {
        v4 = v0->pNextListItem;
        if ( v0 < v3 || v0 >= &v3[CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v0);
          v3 = CAkLEngineCmds::m_listCmd.m_pvMemStart;
        }
        v0 = v4;
      }
      while ( v4 );
    }
    if ( v3 )
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v3);
    *(_QWORD *)&CAkLEngineCmds::m_listCmd.m_ulMinNumListItems = 0i64;
    CAkLEngineCmds::m_listCmd.m_pFirst = 0i64;
    CAkLEngineCmds::m_listCmd.m_pLast = 0i64;
  }
}

// File Line: 53
// RVA: 0xA79C70
void __fastcall CAkLEngineCmds::DequeuePBI(CAkPBI *in_pPBI)
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v1; // r9
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v2; // r8
  CAkPBI *v3; // rbx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v4; // rdx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v5; // rax
  __m128i v6; // [rsp+20h] [rbp-28h]
  __m128i v7; // [rsp+30h] [rbp-18h]

  v1 = CAkLEngineCmds::m_listCmd.m_pFirst;
  v2 = 0i64;
  v3 = in_pPBI;
  v4 = CAkLEngineCmds::m_listCmd.m_pFirst;
  if ( CAkLEngineCmds::m_listCmd.m_pFirst )
  {
    do
    {
      if ( v4->Item.m_pCtx == v3 )
      {
        v6.m128i_i64[1] = (__int64)v2;
        v6.m128i_i64[0] = (__int64)v4->pNextListItem;
        if ( v4 == v1 )
          CAkLEngineCmds::m_listCmd.m_pFirst = v4->pNextListItem;
        else
          v2->pNextListItem = v4->pNextListItem;
        v5 = CAkLEngineCmds::m_listCmd.m_pLast;
        if ( v4 == CAkLEngineCmds::m_listCmd.m_pLast )
          v5 = v2;
        CAkLEngineCmds::m_listCmd.m_pLast = v5;
        if ( v4 < CAkLEngineCmds::m_listCmd.m_pvMemStart
          || v4 >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v4);
        }
        else
        {
          v4->pNextListItem = CAkLEngineCmds::m_listCmd.m_pFree;
          CAkLEngineCmds::m_listCmd.m_pFree = v4;
        }
        --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
        v1 = CAkLEngineCmds::m_listCmd.m_pFirst;
        _mm_store_si128(&v7, v6);
        v2 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v7.m128i_i64[1];
        v4 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v7.m128i_i64[0];
      }
      else
      {
        v2 = v4;
        v4 = v4->pNextListItem;
      }
    }
    while ( v4 );
  }
}

// File Line: 71
// RVA: 0xA79DE0
signed __int64 __fastcall CAkLEngineCmds::EnqueueAction(LEState in_eState, CAkPBI *in_pContext)
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v2; // r8
  CAkPBI *v3; // rdi
  LEState v4; // ebx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v5; // rax
  AkLECmd *v6; // rcx
  signed __int64 result; // rax
  char v8; // cl

  v2 = CAkLEngineCmds::m_listCmd.m_pFree;
  v3 = in_pContext;
  v4 = in_eState;
  if ( !CAkLEngineCmds::m_listCmd.m_pFree )
  {
    if ( CAkLEngineCmds::m_listCmd.m_ulNumListItems >= CAkLEngineCmds::m_listCmd.m_ulMaxNumListItems )
      return 2i64;
    v5 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                    g_LEngineDefaultPoolId,
                                                                                    (unsigned int)(LODWORD(CAkLEngineCmds::m_listCmd.m_pFree)
                                                                                                 + 32));
    v2 = v5;
    if ( !v5 )
      return 2i64;
    v5->pNextListItem = CAkLEngineCmds::m_listCmd.m_pFree;
    CAkLEngineCmds::m_listCmd.m_pFree = v5;
  }
  if ( CAkLEngineCmds::m_listCmd.m_pLast )
  {
    CAkLEngineCmds::m_listCmd.m_pLast->pNextListItem = v2;
    v2 = CAkLEngineCmds::m_listCmd.m_pFree;
  }
  else
  {
    CAkLEngineCmds::m_listCmd.m_pFirst = v2;
  }
  CAkLEngineCmds::m_listCmd.m_pLast = v2;
  CAkLEngineCmds::m_listCmd.m_pFree = v2->pNextListItem;
  v2->pNextListItem = 0i64;
  ++CAkLEngineCmds::m_listCmd.m_ulNumListItems;
  v6 = &CAkLEngineCmds::m_listCmd.m_pLast->Item;
  if ( CAkLEngineCmds::m_listCmd.m_pLast == (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)-8i64 )
    return 2i64;
  CAkLEngineCmds::m_listCmd.m_pLast->Item.m_eState = v4;
  v6->m_pCtx = v3;
  v6->m_ulSequenceNumber = CAkLEngineCmds::m_ulPlayEventID;
  v6->m_bSourceConnected = 0;
  v8 = CAkLEngineCmds::m_bProcessPlayCmdsNeeded;
  result = 1i64;
  if ( (unsigned int)v4 <= 1 )
    v8 = 1;
  CAkLEngineCmds::m_bProcessPlayCmdsNeeded = v8;
  return result;
}

// File Line: 101
// RVA: 0xA79EC0
signed __int64 __fastcall CAkLEngineCmds::EnqueueActionStop(CAkPBI *in_pCtx)
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v1; // rax
  CAkPBI *v2; // rbx

  v1 = CAkLEngineCmds::m_listCmd.m_pFirst;
  v2 = in_pCtx;
  if ( !CAkLEngineCmds::m_listCmd.m_pFirst )
    return CAkLEngineCmds::EnqueueAction(LEStateStop, in_pCtx);
  while ( v1->Item.m_pCtx != in_pCtx )
  {
    v1 = v1->pNextListItem;
    if ( !v1 )
      return CAkLEngineCmds::EnqueueAction(LEStateStop, in_pCtx);
  }
  if ( v1->Item.m_eState > 1u || in_pCtx->m_pCbx )
    return CAkLEngineCmds::EnqueueAction(LEStateStop, in_pCtx);
  CAkLEngineCmds::DequeuePBI(in_pCtx);
  CAkPBI::Destroy(v2, CtxDestroyReasonPlayFailed);
  return 1i64;
}

// File Line: 144
// RVA: 0xA79FD0
void CAkLEngineCmds::ProcessAllCommands(void)
{
  if ( CAkLEngineCmds::m_bProcessPlayCmdsNeeded )
    CAkLEngineCmds::ProcessPlayCommands();
  CAkLEngineCmds::ProcessPendingCommands();
}

// File Line: 158
// RVA: 0xA7A5C0
void CAkLEngineCmds::ProcessPlayCommands(void)
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v0; // rbx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v1; // rdi
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v2; // rax
  __m128i v3; // [rsp+20h] [rbp-28h]
  __m128i v4; // [rsp+30h] [rbp-18h]

  v0 = CAkLEngineCmds::m_listCmd.m_pFirst;
  v1 = 0i64;
  if ( CAkLEngineCmds::m_listCmd.m_pFirst )
  {
    do
    {
      if ( v0->Item.m_pCtx->m_pCbx || v0->Item.m_eState > 1u || (unsigned int)CAkLEngine::AddSound(&v0->Item) == 1 )
      {
        v1 = v0;
        v0 = v0->pNextListItem;
      }
      else
      {
        v3.m128i_i64[1] = (__int64)v1;
        v3.m128i_i64[0] = (__int64)v0->pNextListItem;
        if ( v0 == CAkLEngineCmds::m_listCmd.m_pFirst )
          CAkLEngineCmds::m_listCmd.m_pFirst = v0->pNextListItem;
        else
          v1->pNextListItem = v0->pNextListItem;
        v2 = CAkLEngineCmds::m_listCmd.m_pLast;
        if ( v0 == CAkLEngineCmds::m_listCmd.m_pLast )
          v2 = v1;
        CAkLEngineCmds::m_listCmd.m_pLast = v2;
        if ( v0 < CAkLEngineCmds::m_listCmd.m_pvMemStart
          || v0 >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v0);
        }
        else
        {
          v0->pNextListItem = CAkLEngineCmds::m_listCmd.m_pFree;
          CAkLEngineCmds::m_listCmd.m_pFree = v0;
        }
        --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
        _mm_store_si128(&v4, v3);
        v1 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v4.m128i_i64[1];
        v0 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v4.m128i_i64[0];
      }
    }
    while ( v0 );
    CAkLEngineCmds::m_bProcessPlayCmdsNeeded = 0;
  }
  else
  {
    CAkLEngineCmds::m_bProcessPlayCmdsNeeded = 0;
  }
}

// File Line: 214
// RVA: 0xA7A1C0
void CAkLEngineCmds::ProcessPendingCommands(void)
{
  __int128 v0; // di
  int v1; // er14
  char v2; // r12
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v3; // r15
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v4; // rbx
  CAkPBI *v5; // rcx
  CAkVPLSrcCbxNodeBase *v6; // rdx
  unsigned int v7; // eax
  CAkVPLSrcCbxNode *v8; // rbx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v9; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v10; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v11; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v12; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v13; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v14; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v15; // rax
  __m128i v16; // [rsp+20h] [rbp-50h]
  void *in_pvMemAddress[2]; // [rsp+30h] [rbp-40h]
  __m128i v18; // [rsp+40h] [rbp-30h]
  __m128i v19; // [rsp+50h] [rbp-20h]
  __m128i v20; // [rsp+60h] [rbp-10h]

$StartOverProcCmds:
  v0 = (unsigned __int64)CAkLEngineCmds::m_listCmd.m_pFirst;
  v16.m128i_i64[1] = 0i64;
LABEL_2:
  v16.m128i_i64[0] = v0;
LABEL_3:
  while ( (_QWORD)v0 )
  {
    v1 = *(_DWORD *)(v0 + 20);
    v2 = 0;
    _mm_store_si128((__m128i *)in_pvMemAddress, v16);
    v3 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)in_pvMemAddress[1];
    v4 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)in_pvMemAddress[0];
    do
    {
      if ( v1 != v4->Item.m_ulSequenceNumber )
        break;
      if ( !v4->Item.m_bSourceConnected && v4->Item.m_eState <= 1u )
      {
        v5 = v4->Item.m_pCtx;
        v6 = v5->m_pCbx;
        if ( v6->m_eState != 2 )
        {
          v7 = CAkLEngine::VPLTryConnectSource(v5, v6);
          if ( v7 == 2 )
          {
            if ( v4 == CAkLEngineCmds::m_listCmd.m_pFirst )
              CAkLEngineCmds::m_listCmd.m_pFirst = v4->pNextListItem;
            else
              v3->pNextListItem = v4->pNextListItem;
            v15 = CAkLEngineCmds::m_listCmd.m_pLast;
            if ( v4 == CAkLEngineCmds::m_listCmd.m_pLast )
              v15 = v3;
            CAkLEngineCmds::m_listCmd.m_pLast = v15;
            if ( v4 < CAkLEngineCmds::m_listCmd.m_pvMemStart
              || v4 >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
            {
              AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v4);
              --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
            }
            else
            {
              v4->pNextListItem = CAkLEngineCmds::m_listCmd.m_pFree;
              --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
              CAkLEngineCmds::m_listCmd.m_pFree = v4;
            }
            goto $StartOverProcCmds;
          }
          if ( v7 == 63 )
            v2 = 1;
          else
            v4->Item.m_bSourceConnected = 1;
        }
      }
      v3 = v4;
      v4 = v4->pNextListItem;
    }
    while ( v4 );
    if ( v2 )
    {
      while ( 1 )
      {
        *((_QWORD *)&v0 + 1) = v0;
        v16.m128i_i64[1] = v0;
        *(_QWORD *)&v0 = *(_QWORD *)v0;
        v16.m128i_i64[0] = v0;
        if ( !(_QWORD)v0 )
          return;
        if ( v1 != *(_DWORD *)(v0 + 20) )
          goto LABEL_3;
      }
    }
    if ( *(_BYTE *)(v0 + 24) )
    {
      v8 = *(CAkVPLSrcCbxNode **)(*(_QWORD *)(v0 + 8) + 176i64);
    }
    else
    {
      v8 = CAkLEngine::ResolveCommandVPL((AkLECmd *)(v0 + 8));
      if ( !v8 )
      {
        v9 = *(CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem **)v0;
        v18.m128i_i64[1] = *((_QWORD *)&v0 + 1);
        v18.m128i_i64[0] = (__int64)v9;
        if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 == CAkLEngineCmds::m_listCmd.m_pFirst )
          CAkLEngineCmds::m_listCmd.m_pFirst = v9;
        else
          **((_QWORD **)&v0 + 1) = v9;
        v10 = CAkLEngineCmds::m_listCmd.m_pLast;
        if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 == CAkLEngineCmds::m_listCmd.m_pLast )
          v10 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)*((_QWORD *)&v0 + 1);
        CAkLEngineCmds::m_listCmd.m_pLast = v10;
        if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 < CAkLEngineCmds::m_listCmd.m_pvMemStart
          || (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, (void *)v0);
        }
        else
        {
          *(_QWORD *)v0 = CAkLEngineCmds::m_listCmd.m_pFree;
          CAkLEngineCmds::m_listCmd.m_pFree = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0;
        }
        --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
        _mm_store_si128(&v16, v18);
        v0 = (__int128)v16;
        goto LABEL_3;
      }
    }
    if ( *(_BYTE *)(v0 + 24) )
    {
      switch ( *(_DWORD *)(v0 + 16) )
      {
        case 0:
          CAkVPLSrcCbxNodeBase::Start((CAkVPLSrcCbxNodeBase *)&v8->vfptr);
          break;
        case 1:
          CAkVPLSrcCbxNodeBase::Start((CAkVPLSrcCbxNodeBase *)&v8->vfptr);
          goto $LN8_126;
        case 2:
          v8->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v8->vfptr);
          break;
        case 3:
$LN8_126:
          v8->vfptr->Pause((CAkVPLSrcCbxNodeBase *)&v8->vfptr);
          break;
        case 4:
          v8->vfptr->Resume((CAkVPLSrcCbxNodeBase *)&v8->vfptr);
          break;
        case 5:
          v8->vfptr->StopLooping((CAkVPLSrcCbxNodeBase *)&v8->vfptr, *(CAkPBI **)(v0 + 8));
          break;
        case 6:
          v8->vfptr->SeekSource((CAkVPLSrcCbxNodeBase *)&v8->vfptr);
          break;
        default:
          break;
      }
      v11 = *(CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem **)v0;
      v19.m128i_i64[1] = *((_QWORD *)&v0 + 1);
      v19.m128i_i64[0] = (__int64)v11;
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 == CAkLEngineCmds::m_listCmd.m_pFirst )
        CAkLEngineCmds::m_listCmd.m_pFirst = v11;
      else
        **((_QWORD **)&v0 + 1) = v11;
      v12 = CAkLEngineCmds::m_listCmd.m_pLast;
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 == CAkLEngineCmds::m_listCmd.m_pLast )
        v12 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)*((_QWORD *)&v0 + 1);
      CAkLEngineCmds::m_listCmd.m_pLast = v12;
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 < CAkLEngineCmds::m_listCmd.m_pvMemStart
        || (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, (void *)v0);
      }
      else
      {
        *(_QWORD *)v0 = CAkLEngineCmds::m_listCmd.m_pFree;
        CAkLEngineCmds::m_listCmd.m_pFree = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0;
      }
      --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
      _mm_store_si128(&v16, v19);
      v0 = (__int128)v16;
    }
    else
    {
      if ( *(_DWORD *)(v0 + 16) != 2 || !v8 )
      {
        *((_QWORD *)&v0 + 1) = v0;
        v16.m128i_i64[1] = v0;
        *(_QWORD *)&v0 = *(_QWORD *)v0;
        goto LABEL_2;
      }
      v8->vfptr->Stop((CAkVPLSrcCbxNodeBase *)&v8->vfptr);
      v13 = *(CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem **)v0;
      v20.m128i_i64[0] = *(_QWORD *)v0;
      v20.m128i_i64[1] = *((_QWORD *)&v0 + 1);
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 == CAkLEngineCmds::m_listCmd.m_pFirst )
        CAkLEngineCmds::m_listCmd.m_pFirst = v13;
      else
        **((_QWORD **)&v0 + 1) = v13;
      v14 = CAkLEngineCmds::m_listCmd.m_pLast;
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 == CAkLEngineCmds::m_listCmd.m_pLast )
        v14 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)*((_QWORD *)&v0 + 1);
      CAkLEngineCmds::m_listCmd.m_pLast = v14;
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 < CAkLEngineCmds::m_listCmd.m_pvMemStart
        || (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0 >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, (void *)v0);
      }
      else
      {
        *(_QWORD *)v0 = CAkLEngineCmds::m_listCmd.m_pFree;
        CAkLEngineCmds::m_listCmd.m_pFree = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v0;
      }
      --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
      _mm_store_si128(&v16, v20);
      v0 = (__int128)v16;
    }
  }
}

// File Line: 383
// RVA: 0xA79FF0
void __fastcall CAkLEngineCmds::ProcessDisconnectedSources(unsigned int in_uFrames)
{
  CAkVPLSrcCbxNodeBase *v1; // rsi
  CAkVPLSrcCbxNodeBase *v2; // r15
  unsigned int v3; // er14
  CAkVPLSrcNode *v4; // rax
  int v5; // ecx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v6; // rbp
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v7; // rdi
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v8; // rbx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v9; // rax
  CAkVPLSrcCbxNodeBase *v10; // rax
  CAkVPLSrcCbxNodeBase *v11; // rax
  bool v12; // zf
  __m128i v13; // [rsp+20h] [rbp-58h]
  __int128 v14; // [rsp+30h] [rbp-48h]
  __m128i v15; // [rsp+40h] [rbp-38h]
  __m128i v16; // [rsp+50h] [rbp-28h]

  v1 = CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst;
  v2 = 0i64;
  v3 = in_uFrames;
  if ( CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst )
  {
    do
    {
      v4 = v1->m_pSources[0];
      if ( v4 )
        v4 = (CAkVPLSrcNode *)v4->m_pCtx;
      if ( v1->m_eState == 2 || BYTE5(v4[9].m_pInput) & 0x10 )
      {
        v6 = CAkLEngineCmds::m_listCmd.m_pFirst;
        v7 = 0i64;
        v8 = CAkLEngineCmds::m_listCmd.m_pFirst;
        if ( CAkLEngineCmds::m_listCmd.m_pFirst )
        {
          do
          {
            if ( v8->Item.m_pCtx == CAkVPLSrcCbxNodeBase::GetContext(v1) )
            {
              v13.m128i_i64[1] = (__int64)v7;
              v13.m128i_i64[0] = (__int64)v8->pNextListItem;
              if ( v8 == v6 )
                CAkLEngineCmds::m_listCmd.m_pFirst = v8->pNextListItem;
              else
                v7->pNextListItem = v8->pNextListItem;
              v9 = CAkLEngineCmds::m_listCmd.m_pLast;
              if ( v8 == CAkLEngineCmds::m_listCmd.m_pLast )
                v9 = v7;
              CAkLEngineCmds::m_listCmd.m_pLast = v9;
              if ( v8 < CAkLEngineCmds::m_listCmd.m_pvMemStart
                || v8 >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
              {
                AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v8);
              }
              else
              {
                v8->pNextListItem = CAkLEngineCmds::m_listCmd.m_pFree;
                CAkLEngineCmds::m_listCmd.m_pFree = v8;
              }
              --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
              v6 = CAkLEngineCmds::m_listCmd.m_pFirst;
              _mm_store_si128((__m128i *)&v14, v13);
              v7 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)*((_QWORD *)&v14 + 1);
              v8 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v14;
            }
            else
            {
              v7 = v8;
              v8 = v8->pNextListItem;
            }
          }
          while ( v8 );
        }
        v10 = v1->pNextItem;
        v15.m128i_i64[1] = (__int64)v2;
        v15.m128i_i64[0] = (__int64)v10;
        if ( v1 == CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst )
          CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst = v10;
        else
          v2->pNextItem = v10;
        v11 = CAkLEngineCmds::m_listSrcsNotConnected.m_pLast;
        v12 = v1 == CAkLEngineCmds::m_listSrcsNotConnected.m_pLast;
        _mm_store_si128(&v16, v15);
        if ( v12 )
          v11 = v2;
        CAkLEngineCmds::m_listSrcsNotConnected.m_pLast = v11;
        CAkLEngine::VPLDestroySource(v1, 0i64);
        v2 = (CAkVPLSrcCbxNodeBase *)v16.m128i_i64[1];
        v1 = (CAkVPLSrcCbxNodeBase *)v16.m128i_i64[0];
      }
      else
      {
        if ( SBYTE6(v4[9].m_pInput) < 0 )
          v3 = 8 * v3 >> 10;
        v5 = (int)v4[10].vfptr;
        if ( v5 >= 0 )
          LODWORD(v4[10].vfptr) = v5 - v3;
        v2 = v1;
        v1 = v1->pNextItem;
      }
    }
    while ( v1 );
  }
}

// File Line: 425
// RVA: 0xA79D50
void CAkLEngineCmds::DestroyDisconnectedSources(void)
{
  CAkVPLSrcCbxNodeBase *v0; // rax
  CAkVPLSrcCbxNodeBase *v1; // rdx
  CAkVPLSrcCbxNodeBase *v2; // rcx
  CAkVPLSrcCbxNodeBase *v3; // rbx
  CAkVPLSrcCbxNodeBase *v4; // rax
  bool v5; // zf
  __m128i v6; // [rsp+20h] [rbp-28h]
  __int128 v7; // [rsp+30h] [rbp-18h]

  v0 = CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst;
  v1 = 0i64;
  v2 = CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst;
  if ( CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst )
  {
    while ( 1 )
    {
      v3 = v2->pNextItem;
      v6.m128i_i64[1] = (__int64)v1;
      v6.m128i_i64[0] = (__int64)v2->pNextItem;
      if ( v2 == v0 )
        CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst = v2->pNextItem;
      else
        v1->pNextItem = v3;
      v4 = CAkLEngineCmds::m_listSrcsNotConnected.m_pLast;
      v5 = v2 == CAkLEngineCmds::m_listSrcsNotConnected.m_pLast;
      _mm_store_si128((__m128i *)&v7, v6);
      if ( v5 )
        v4 = v1;
      CAkLEngineCmds::m_listSrcsNotConnected.m_pLast = v4;
      CAkLEngine::VPLDestroySource(v2, 0i64);
      if ( !v3 )
        break;
      v1 = (CAkVPLSrcCbxNodeBase *)*((_QWORD *)&v7 + 1);
      v2 = (CAkVPLSrcCbxNodeBase *)v7;
      v0 = CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst;
    }
  }
}

// File Line: 435
// RVA: 0xA79B70
void __fastcall CAkLEngineCmds::DeleteAllCommandsForSource(CAkVPLSrcCbxNodeBase *in_pCbx)
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v1; // rsi
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v2; // rdi
  CAkVPLSrcCbxNodeBase *v3; // rbp
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v4; // rbx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v5; // rax
  __m128i v6; // [rsp+20h] [rbp-28h]
  __m128i v7; // [rsp+30h] [rbp-18h]

  v1 = CAkLEngineCmds::m_listCmd.m_pFirst;
  v2 = 0i64;
  v3 = in_pCbx;
  v4 = CAkLEngineCmds::m_listCmd.m_pFirst;
  if ( CAkLEngineCmds::m_listCmd.m_pFirst )
  {
    do
    {
      if ( v4->Item.m_pCtx == CAkVPLSrcCbxNodeBase::GetContext(v3) )
      {
        v6.m128i_i64[1] = (__int64)v2;
        v6.m128i_i64[0] = (__int64)v4->pNextListItem;
        if ( v4 == v1 )
          CAkLEngineCmds::m_listCmd.m_pFirst = v4->pNextListItem;
        else
          v2->pNextListItem = v4->pNextListItem;
        v5 = CAkLEngineCmds::m_listCmd.m_pLast;
        if ( v4 == CAkLEngineCmds::m_listCmd.m_pLast )
          v5 = v2;
        CAkLEngineCmds::m_listCmd.m_pLast = v5;
        if ( v4 < CAkLEngineCmds::m_listCmd.m_pvMemStart
          || v4 >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v4);
        }
        else
        {
          v4->pNextListItem = CAkLEngineCmds::m_listCmd.m_pFree;
          CAkLEngineCmds::m_listCmd.m_pFree = v4;
        }
        --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
        v1 = CAkLEngineCmds::m_listCmd.m_pFirst;
        _mm_store_si128(&v7, v6);
        v2 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v7.m128i_i64[1];
        v4 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v7.m128i_i64[0];
      }
      else
      {
        v2 = v4;
        v4 = v4->pNextListItem;
      }
    }
    while ( v4 );
  }
}

