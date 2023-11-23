// File Line: 31
// RVA: 0x15BE090
__int64 dynamic_initializer_for__CAkLEngineCmds::m_listSrcsNotConnected__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkLEngineCmds::m_listSrcsNotConnected__);
}

// File Line: 33
// RVA: 0x15BE080
__int64 dynamic_initializer_for__CAkLEngineCmds::m_listCmd__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkLEngineCmds::m_listCmd__);
}

// File Line: 37
// RVA: 0xA79F30
__int64 __fastcall CAkLEngineCmds::Init()
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v0; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v1; // rcx
  __int64 result; // rax
  unsigned int v3; // edx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v4; // rax

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
      v4 = v1 + 1;
      ++v3;
      v1->pNextListItem = v1 + 1;
      ++v1;
    }
    while ( v3 < CAkLEngineCmds::m_listCmd.m_ulMinNumListItems );
    v4[-1].pNextListItem = 0i64;
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
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pFree; // rdx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pFirst; // rcx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pLast; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pvMemStart; // rcx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *pNextListItem; // rbx

  CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst = 0i64;
  CAkLEngineCmds::m_listSrcsNotConnected.m_pLast = 0i64;
  if ( CAkLEngineCmds::m_listCmd.m_ulMaxNumListItems )
  {
    m_pFree = CAkLEngineCmds::m_listCmd.m_pFree;
    while ( 1 )
    {
      m_pFirst = CAkLEngineCmds::m_listCmd.m_pFirst;
      if ( !CAkLEngineCmds::m_listCmd.m_pFirst )
        break;
      CAkLEngineCmds::m_listCmd.m_pFirst = CAkLEngineCmds::m_listCmd.m_pFirst->pNextListItem;
      m_pLast = CAkLEngineCmds::m_listCmd.m_pLast;
      if ( m_pFirst == CAkLEngineCmds::m_listCmd.m_pLast )
        m_pLast = 0i64;
      CAkLEngineCmds::m_listCmd.m_pLast = m_pLast;
      if ( m_pFirst < CAkLEngineCmds::m_listCmd.m_pvMemStart
        || m_pFirst >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pFirst);
        m_pFree = CAkLEngineCmds::m_listCmd.m_pFree;
        --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
      }
      else
      {
        m_pFirst->pNextListItem = m_pFree;
        --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
        m_pFree = m_pFirst;
        CAkLEngineCmds::m_listCmd.m_pFree = m_pFirst;
      }
    }
    m_pvMemStart = CAkLEngineCmds::m_listCmd.m_pvMemStart;
    if ( m_pFree )
    {
      do
      {
        pNextListItem = m_pFree->pNextListItem;
        if ( m_pFree < m_pvMemStart || m_pFree >= &m_pvMemStart[CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pFree);
          m_pvMemStart = CAkLEngineCmds::m_listCmd.m_pvMemStart;
        }
        m_pFree = pNextListItem;
      }
      while ( pNextListItem );
    }
    if ( m_pvMemStart )
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pvMemStart);
    *(_QWORD *)&CAkLEngineCmds::m_listCmd.m_ulMinNumListItems = 0i64;
    CAkLEngineCmds::m_listCmd.m_pFirst = 0i64;
    CAkLEngineCmds::m_listCmd.m_pLast = 0i64;
  }
}

// File Line: 53
// RVA: 0xA79C70
void __fastcall CAkLEngineCmds::DequeuePBI(CAkPBI *in_pPBI)
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pFirst; // r9
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v2; // r8
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v4; // rdx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pLast; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *pNextListItem; // [rsp+20h] [rbp-28h]
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v7; // [rsp+28h] [rbp-20h]

  m_pFirst = CAkLEngineCmds::m_listCmd.m_pFirst;
  v2 = 0i64;
  v4 = CAkLEngineCmds::m_listCmd.m_pFirst;
  while ( v4 )
  {
    if ( v4->Item.m_pCtx == in_pPBI )
    {
      v7 = v2;
      pNextListItem = v4->pNextListItem;
      if ( v4 == m_pFirst )
        CAkLEngineCmds::m_listCmd.m_pFirst = v4->pNextListItem;
      else
        v2->pNextListItem = v4->pNextListItem;
      m_pLast = CAkLEngineCmds::m_listCmd.m_pLast;
      if ( v4 == CAkLEngineCmds::m_listCmd.m_pLast )
        m_pLast = v2;
      CAkLEngineCmds::m_listCmd.m_pLast = m_pLast;
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
      m_pFirst = CAkLEngineCmds::m_listCmd.m_pFirst;
      v2 = v7;
      v4 = pNextListItem;
    }
    else
    {
      v2 = v4;
      v4 = v4->pNextListItem;
    }
  }
}

// File Line: 71
// RVA: 0xA79DE0
__int64 __fastcall CAkLEngineCmds::EnqueueAction(LEState in_eState, CAkPBI *in_pContext)
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pFree; // r8
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v5; // rax
  AkLECmd *p_Item; // rcx
  __int64 result; // rax
  char v8; // cl

  m_pFree = CAkLEngineCmds::m_listCmd.m_pFree;
  if ( !CAkLEngineCmds::m_listCmd.m_pFree )
  {
    if ( CAkLEngineCmds::m_listCmd.m_ulNumListItems >= CAkLEngineCmds::m_listCmd.m_ulMaxNumListItems )
      return 2i64;
    v5 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                    g_LEngineDefaultPoolId,
                                                                                    (unsigned int)(LODWORD(CAkLEngineCmds::m_listCmd.m_pFree)
                                                                                                 + 32));
    m_pFree = v5;
    if ( !v5 )
      return 2i64;
    v5->pNextListItem = CAkLEngineCmds::m_listCmd.m_pFree;
    CAkLEngineCmds::m_listCmd.m_pFree = v5;
  }
  if ( CAkLEngineCmds::m_listCmd.m_pLast )
  {
    CAkLEngineCmds::m_listCmd.m_pLast->pNextListItem = m_pFree;
    m_pFree = CAkLEngineCmds::m_listCmd.m_pFree;
  }
  else
  {
    CAkLEngineCmds::m_listCmd.m_pFirst = m_pFree;
  }
  CAkLEngineCmds::m_listCmd.m_pLast = m_pFree;
  CAkLEngineCmds::m_listCmd.m_pFree = m_pFree->pNextListItem;
  m_pFree->pNextListItem = 0i64;
  ++CAkLEngineCmds::m_listCmd.m_ulNumListItems;
  p_Item = &CAkLEngineCmds::m_listCmd.m_pLast->Item;
  if ( CAkLEngineCmds::m_listCmd.m_pLast == (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)-8i64 )
    return 2i64;
  CAkLEngineCmds::m_listCmd.m_pLast->Item.m_eState = in_eState;
  p_Item->m_pCtx = in_pContext;
  p_Item->m_ulSequenceNumber = CAkLEngineCmds::m_ulPlayEventID;
  p_Item->m_bSourceConnected = 0;
  v8 = CAkLEngineCmds::m_bProcessPlayCmdsNeeded;
  result = 1i64;
  if ( (unsigned int)in_eState <= LEStatePlayPause )
    v8 = 1;
  CAkLEngineCmds::m_bProcessPlayCmdsNeeded = v8;
  return result;
}

// File Line: 101
// RVA: 0xA79EC0
__int64 __fastcall CAkLEngineCmds::EnqueueActionStop(CAkPBI *in_pCtx)
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pFirst; // rax

  m_pFirst = CAkLEngineCmds::m_listCmd.m_pFirst;
  if ( !CAkLEngineCmds::m_listCmd.m_pFirst )
    return CAkLEngineCmds::EnqueueAction(LEStateStop, in_pCtx);
  while ( m_pFirst->Item.m_pCtx != in_pCtx )
  {
    m_pFirst = m_pFirst->pNextListItem;
    if ( !m_pFirst )
      return CAkLEngineCmds::EnqueueAction(LEStateStop, in_pCtx);
  }
  if ( m_pFirst->Item.m_eState > (unsigned int)LEStatePlayPause || in_pCtx->m_pCbx )
    return CAkLEngineCmds::EnqueueAction(LEStateStop, in_pCtx);
  CAkLEngineCmds::DequeuePBI(in_pCtx);
  CAkPBI::Destroy(in_pCtx, CtxDestroyReasonPlayFailed);
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
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pFirst; // rbx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v1; // rdi
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pLast; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *pNextListItem; // [rsp+20h] [rbp-28h]

  m_pFirst = CAkLEngineCmds::m_listCmd.m_pFirst;
  v1 = 0i64;
  if ( CAkLEngineCmds::m_listCmd.m_pFirst )
  {
    do
    {
      if ( m_pFirst->Item.m_pCtx->m_pCbx
        || m_pFirst->Item.m_eState > (unsigned int)LEStatePlayPause
        || (unsigned int)CAkLEngine::AddSound(&m_pFirst->Item) == 1 )
      {
        v1 = m_pFirst;
        m_pFirst = m_pFirst->pNextListItem;
      }
      else
      {
        pNextListItem = m_pFirst->pNextListItem;
        if ( m_pFirst == CAkLEngineCmds::m_listCmd.m_pFirst )
          CAkLEngineCmds::m_listCmd.m_pFirst = m_pFirst->pNextListItem;
        else
          v1->pNextListItem = m_pFirst->pNextListItem;
        m_pLast = CAkLEngineCmds::m_listCmd.m_pLast;
        if ( m_pFirst == CAkLEngineCmds::m_listCmd.m_pLast )
          m_pLast = v1;
        CAkLEngineCmds::m_listCmd.m_pLast = m_pLast;
        if ( m_pFirst < CAkLEngineCmds::m_listCmd.m_pvMemStart
          || m_pFirst >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pFirst);
        }
        else
        {
          m_pFirst->pNextListItem = CAkLEngineCmds::m_listCmd.m_pFree;
          CAkLEngineCmds::m_listCmd.m_pFree = m_pFirst;
        }
        --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
        m_pFirst = pNextListItem;
      }
    }
    while ( m_pFirst );
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
  __int128 m_pFirst; // rdi
  int v1; // r14d
  char v2; // r12
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v3; // r15
  __int64 *v4; // rbx
  CAkPBI *v5; // rcx
  CAkVPLSrcCbxNodeBase *m_pCbx; // rdx
  unsigned int v7; // eax
  CAkVPLSrcCbxNode *v8; // rbx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v9; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v10; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v11; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pLast; // rax
  __int128 v13; // [rsp+20h] [rbp-50h]
  __int128 v14; // [rsp+40h] [rbp-30h]
  __int128 v15; // [rsp+50h] [rbp-20h]
  __int128 v16; // [rsp+60h] [rbp-10h]

$StartOverProcCmds:
  m_pFirst = (unsigned __int64)CAkLEngineCmds::m_listCmd.m_pFirst;
  *((_QWORD *)&v13 + 1) = 0i64;
LABEL_2:
  *(_QWORD *)&v13 = m_pFirst;
LABEL_3:
  while ( (_QWORD)m_pFirst )
  {
    v1 = *(_DWORD *)(m_pFirst + 20);
    v2 = 0;
    v3 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)*((_QWORD *)&v13 + 1);
    v4 = (__int64 *)v13;
    do
    {
      if ( v1 != *((_DWORD *)v4 + 5) )
        break;
      if ( !*((_BYTE *)v4 + 24) && *((_DWORD *)v4 + 4) <= 1u )
      {
        v5 = (CAkPBI *)v4[1];
        m_pCbx = v5->m_pCbx;
        if ( m_pCbx->m_eState != NodeStateStop )
        {
          v7 = CAkLEngine::VPLTryConnectSource(v5, (CAkVPLSrcCbxNode *)m_pCbx);
          if ( v7 == 2 )
          {
            if ( v4 == (__int64 *)CAkLEngineCmds::m_listCmd.m_pFirst )
              CAkLEngineCmds::m_listCmd.m_pFirst = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)*v4;
            else
              v3->pNextListItem = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)*v4;
            m_pLast = CAkLEngineCmds::m_listCmd.m_pLast;
            if ( v4 == (__int64 *)CAkLEngineCmds::m_listCmd.m_pLast )
              m_pLast = v3;
            CAkLEngineCmds::m_listCmd.m_pLast = m_pLast;
            if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v4 < CAkLEngineCmds::m_listCmd.m_pvMemStart
              || (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v4 >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
            {
              AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v4);
              --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
            }
            else
            {
              *v4 = (__int64)CAkLEngineCmds::m_listCmd.m_pFree;
              --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
              CAkLEngineCmds::m_listCmd.m_pFree = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v4;
            }
            goto $StartOverProcCmds;
          }
          if ( v7 == 63 )
            v2 = 1;
          else
            *((_BYTE *)v4 + 24) = 1;
        }
      }
      v3 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)v4;
      v4 = (__int64 *)*v4;
    }
    while ( v4 );
    if ( v2 )
    {
      while ( 1 )
      {
        *((_QWORD *)&m_pFirst + 1) = m_pFirst;
        *((_QWORD *)&v13 + 1) = m_pFirst;
        *(_QWORD *)&m_pFirst = *(_QWORD *)m_pFirst;
        *(_QWORD *)&v13 = m_pFirst;
        if ( !(_QWORD)m_pFirst )
          return;
        if ( v1 != *(_DWORD *)(m_pFirst + 20) )
          goto LABEL_3;
      }
    }
    if ( *(_BYTE *)(m_pFirst + 24) )
    {
      v8 = *(CAkVPLSrcCbxNode **)(*(_QWORD *)(m_pFirst + 8) + 176i64);
    }
    else
    {
      v8 = CAkLEngine::ResolveCommandVPL((AkLECmd *)(m_pFirst + 8));
      if ( !v8 )
      {
        *((_QWORD *)&v14 + 1) = *((_QWORD *)&m_pFirst + 1);
        *(_QWORD *)&v14 = *(_QWORD *)m_pFirst;
        if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst == CAkLEngineCmds::m_listCmd.m_pFirst )
          CAkLEngineCmds::m_listCmd.m_pFirst = *(CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem **)m_pFirst;
        else
          **((_QWORD **)&m_pFirst + 1) = *(_QWORD *)m_pFirst;
        v9 = CAkLEngineCmds::m_listCmd.m_pLast;
        if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst == CAkLEngineCmds::m_listCmd.m_pLast )
          v9 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)*((_QWORD *)&m_pFirst + 1);
        CAkLEngineCmds::m_listCmd.m_pLast = v9;
        if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst < CAkLEngineCmds::m_listCmd.m_pvMemStart
          || (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
        {
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, (void *)m_pFirst);
        }
        else
        {
          *(_QWORD *)m_pFirst = CAkLEngineCmds::m_listCmd.m_pFree;
          CAkLEngineCmds::m_listCmd.m_pFree = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst;
        }
        --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
        v13 = v14;
        m_pFirst = v14;
        goto LABEL_3;
      }
    }
    if ( *(_BYTE *)(m_pFirst + 24) )
    {
      switch ( *(_DWORD *)(m_pFirst + 16) )
      {
        case 0:
          CAkVPLSrcCbxNodeBase::Start(v8);
          break;
        case 1:
          CAkVPLSrcCbxNodeBase::Start(v8);
          goto $LN8_126;
        case 2:
          v8->vfptr->Stop(v8);
          break;
        case 3:
$LN8_126:
          v8->vfptr->Pause(v8);
          break;
        case 4:
          v8->vfptr->Resume(v8);
          break;
        case 5:
          v8->vfptr->StopLooping(v8, *(CAkPBI **)(m_pFirst + 8));
          break;
        case 6:
          v8->vfptr->SeekSource(v8);
          break;
        default:
          break;
      }
      *((_QWORD *)&v15 + 1) = *((_QWORD *)&m_pFirst + 1);
      *(_QWORD *)&v15 = *(_QWORD *)m_pFirst;
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst == CAkLEngineCmds::m_listCmd.m_pFirst )
        CAkLEngineCmds::m_listCmd.m_pFirst = *(CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem **)m_pFirst;
      else
        **((_QWORD **)&m_pFirst + 1) = *(_QWORD *)m_pFirst;
      v10 = CAkLEngineCmds::m_listCmd.m_pLast;
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst == CAkLEngineCmds::m_listCmd.m_pLast )
        v10 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)*((_QWORD *)&m_pFirst + 1);
      CAkLEngineCmds::m_listCmd.m_pLast = v10;
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst < CAkLEngineCmds::m_listCmd.m_pvMemStart
        || (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, (void *)m_pFirst);
      }
      else
      {
        *(_QWORD *)m_pFirst = CAkLEngineCmds::m_listCmd.m_pFree;
        CAkLEngineCmds::m_listCmd.m_pFree = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst;
      }
      --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
      v13 = v15;
      m_pFirst = v15;
    }
    else
    {
      if ( *(_DWORD *)(m_pFirst + 16) != 2 || !v8 )
      {
        *((_QWORD *)&m_pFirst + 1) = m_pFirst;
        *((_QWORD *)&v13 + 1) = m_pFirst;
        *(_QWORD *)&m_pFirst = *(_QWORD *)m_pFirst;
        goto LABEL_2;
      }
      v8->vfptr->Stop(v8);
      *(_QWORD *)&v16 = *(_QWORD *)m_pFirst;
      *((_QWORD *)&v16 + 1) = *((_QWORD *)&m_pFirst + 1);
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst == CAkLEngineCmds::m_listCmd.m_pFirst )
        CAkLEngineCmds::m_listCmd.m_pFirst = *(CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem **)m_pFirst;
      else
        **((_QWORD **)&m_pFirst + 1) = *(_QWORD *)m_pFirst;
      v11 = CAkLEngineCmds::m_listCmd.m_pLast;
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst == CAkLEngineCmds::m_listCmd.m_pLast )
        v11 = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)*((_QWORD *)&m_pFirst + 1);
      CAkLEngineCmds::m_listCmd.m_pLast = v11;
      if ( (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst < CAkLEngineCmds::m_listCmd.m_pvMemStart
        || (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst >= &CAkLEngineCmds::m_listCmd.m_pvMemStart[(unsigned __int64)CAkLEngineCmds::m_listCmd.m_ulMinNumListItems] )
      {
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, (void *)m_pFirst);
      }
      else
      {
        *(_QWORD *)m_pFirst = CAkLEngineCmds::m_listCmd.m_pFree;
        CAkLEngineCmds::m_listCmd.m_pFree = (CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *)m_pFirst;
      }
      --CAkLEngineCmds::m_listCmd.m_ulNumListItems;
      v13 = v16;
      m_pFirst = v16;
    }
  }
}

// File Line: 383
// RVA: 0xA79FF0
void __fastcall CAkLEngineCmds::ProcessDisconnectedSources(unsigned int in_uFrames)
{
  CAkVPLSrcCbxNodeBase *m_pFirst; // rsi
  CAkVPLSrcCbxNodeBase *v2; // r15
  CAkVPLSrcNode *v4; // rax
  int vfptr; // ecx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v6; // rbp
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v7; // rdi
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v8; // rbx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pLast; // rax
  CAkVPLSrcCbxNodeBase *v10; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *pNextListItem; // [rsp+20h] [rbp-58h]
  CAkVPLSrcCbxNodeBase *pNextItem; // [rsp+40h] [rbp-38h]

  m_pFirst = CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst;
  v2 = 0i64;
  while ( m_pFirst )
  {
    v4 = m_pFirst->m_pSources[0];
    if ( v4 )
      v4 = (CAkVPLSrcNode *)v4->m_pCtx;
    if ( m_pFirst->m_eState == NodeStateStop || (BYTE5(v4[9].m_pInput) & 0x10) != 0 )
    {
      v6 = CAkLEngineCmds::m_listCmd.m_pFirst;
      v7 = 0i64;
      v8 = CAkLEngineCmds::m_listCmd.m_pFirst;
      while ( v8 )
      {
        if ( v8->Item.m_pCtx == CAkVPLSrcCbxNodeBase::GetContext(m_pFirst) )
        {
          pNextListItem = v8->pNextListItem;
          if ( v8 == v6 )
            CAkLEngineCmds::m_listCmd.m_pFirst = v8->pNextListItem;
          else
            v7->pNextListItem = v8->pNextListItem;
          m_pLast = CAkLEngineCmds::m_listCmd.m_pLast;
          if ( v8 == CAkLEngineCmds::m_listCmd.m_pLast )
            m_pLast = v7;
          CAkLEngineCmds::m_listCmd.m_pLast = m_pLast;
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
          v8 = pNextListItem;
        }
        else
        {
          v7 = v8;
          v8 = v8->pNextListItem;
        }
      }
      pNextItem = m_pFirst->pNextItem;
      if ( m_pFirst == CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst )
        CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst = m_pFirst->pNextItem;
      else
        v2->pNextItem = m_pFirst->pNextItem;
      v10 = CAkLEngineCmds::m_listSrcsNotConnected.m_pLast;
      if ( m_pFirst == CAkLEngineCmds::m_listSrcsNotConnected.m_pLast )
        v10 = v2;
      CAkLEngineCmds::m_listSrcsNotConnected.m_pLast = v10;
      CAkLEngine::VPLDestroySource(m_pFirst, 0i64);
      m_pFirst = pNextItem;
    }
    else
    {
      if ( SBYTE6(v4[9].m_pInput) < 0 )
        in_uFrames = (8 * in_uFrames) >> 10;
      vfptr = (int)v4[10].vfptr;
      if ( vfptr >= 0 )
        LODWORD(v4[10].vfptr) = vfptr - in_uFrames;
      v2 = m_pFirst;
      m_pFirst = m_pFirst->pNextItem;
    }
  }
}

// File Line: 425
// RVA: 0xA79D50
void CAkLEngineCmds::DestroyDisconnectedSources(void)
{
  CAkVPLSrcCbxNodeBase *m_pFirst; // rax
  CAkVPLSrcCbxNodeBase *v1; // rdx
  CAkVPLSrcCbxNodeBase *v2; // rcx
  CAkVPLSrcCbxNodeBase *pNextItem; // rbx
  CAkVPLSrcCbxNodeBase *m_pLast; // rax
  CAkVPLSrcCbxNodeBase *v5; // [rsp+28h] [rbp-20h]

  m_pFirst = CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst;
  v1 = 0i64;
  v2 = CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst;
  if ( CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst )
  {
    while ( 1 )
    {
      pNextItem = v2->pNextItem;
      v5 = v1;
      if ( v2 == m_pFirst )
        CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst = v2->pNextItem;
      else
        v1->pNextItem = pNextItem;
      m_pLast = CAkLEngineCmds::m_listSrcsNotConnected.m_pLast;
      if ( v2 == CAkLEngineCmds::m_listSrcsNotConnected.m_pLast )
        m_pLast = v1;
      CAkLEngineCmds::m_listSrcsNotConnected.m_pLast = m_pLast;
      CAkLEngine::VPLDestroySource(v2, 0i64);
      if ( !pNextItem )
        break;
      v1 = v5;
      v2 = pNextItem;
      m_pFirst = CAkLEngineCmds::m_listSrcsNotConnected.m_pFirst;
    }
  }
}

// File Line: 435
// RVA: 0xA79B70
void __fastcall CAkLEngineCmds::DeleteAllCommandsForSource(CAkVPLSrcCbxNodeBase *in_pCbx)
{
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pFirst; // rsi
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v2; // rdi
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *v4; // rbx
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *m_pLast; // rax
  CAkList2<AkLECmd,AkLECmd const &,1,ArrayPoolLEngineDefault>::ListItem *pNextListItem; // [rsp+20h] [rbp-28h]

  m_pFirst = CAkLEngineCmds::m_listCmd.m_pFirst;
  v2 = 0i64;
  v4 = CAkLEngineCmds::m_listCmd.m_pFirst;
  while ( v4 )
  {
    if ( v4->Item.m_pCtx == CAkVPLSrcCbxNodeBase::GetContext(in_pCbx) )
    {
      pNextListItem = v4->pNextListItem;
      if ( v4 == m_pFirst )
        CAkLEngineCmds::m_listCmd.m_pFirst = v4->pNextListItem;
      else
        v2->pNextListItem = v4->pNextListItem;
      m_pLast = CAkLEngineCmds::m_listCmd.m_pLast;
      if ( v4 == CAkLEngineCmds::m_listCmd.m_pLast )
        m_pLast = v2;
      CAkLEngineCmds::m_listCmd.m_pLast = m_pLast;
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
      m_pFirst = CAkLEngineCmds::m_listCmd.m_pFirst;
      v4 = pNextListItem;
    }
    else
    {
      v2 = v4;
      v4 = v4->pNextListItem;
    }
  }
}

