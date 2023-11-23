// File Line: 94
// RVA: 0xAADB40
void __fastcall AkMusicActionPlay::~AkMusicActionPlay(AkMusicActionPlay *this)
{
  bool v1; // zf
  AkMusicAutomation *m_pFirst; // rdx

  v1 = this->m_listAutomation.m_pFirst == 0i64;
  this->vfptr = (AkMusicActionVtbl *)&AkMusicActionPlay::`vftable;
  if ( v1 )
  {
    this->vfptr = (AkMusicActionVtbl *)&AkMusicAction::`vftable;
  }
  else
  {
    do
    {
      m_pFirst = this->m_listAutomation.m_pFirst;
      if ( m_pFirst )
      {
        this->m_listAutomation.m_pFirst = m_pFirst->pNextLightItem;
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
      }
    }
    while ( this->m_listAutomation.m_pFirst );
    this->vfptr = (AkMusicActionVtbl *)&AkMusicAction::`vftable;
  }
}

// File Line: 117
// RVA: 0xAADE30
void __fastcall AkMusicActionPlay::AttachClipAutomation(
        AkMusicActionPlay *this,
        unsigned int in_uClipIndex,
        AkClipAutomationType in_eType,
        int in_iTimeStart)
{
  CAkMusicTrack *m_pTrack; // rax
  CAkClipAutomation *m_pItems; // rbx
  CAkClipAutomation *v8; // rax
  AkMusicAutomation *v9; // rax
  AkMusicAutomation *m_pFirst; // rcx

  m_pTrack = this->m_pTrack;
  m_pItems = m_pTrack->m_arClipAutomation.m_pItems;
  v8 = &m_pItems[m_pTrack->m_arClipAutomation.m_uLength];
  if ( m_pItems != v8 )
  {
    do
    {
      if ( m_pItems->m_uClipIndex == in_uClipIndex && m_pItems->m_eAutoType == in_eType )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v8 );
    if ( m_pItems != v8 )
    {
      if ( m_pItems )
      {
        v9 = (AkMusicAutomation *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
        if ( v9 )
        {
          v9->pAutomationData = m_pItems;
          v9->iTimeStart = in_iTimeStart;
          v9->pPBI = 0i64;
          m_pFirst = this->m_listAutomation.m_pFirst;
          if ( m_pFirst )
          {
            v9->pNextLightItem = m_pFirst;
            this->m_listAutomation.m_pFirst = v9;
          }
          else
          {
            this->m_listAutomation.m_pFirst = v9;
            v9->pNextLightItem = 0i64;
          }
        }
      }
    }
  }
}

