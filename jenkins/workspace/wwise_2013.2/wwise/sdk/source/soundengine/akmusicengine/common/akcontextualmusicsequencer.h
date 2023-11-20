// File Line: 94
// RVA: 0xAADB40
void __fastcall AkMusicActionPlay::~AkMusicActionPlay(AkMusicActionPlay *this)
{
  bool v1; // zf
  AkMusicActionPlay *v2; // rbx
  AkMusicAutomation *v3; // rdx

  v1 = this->m_listAutomation.m_pFirst == 0i64;
  v2 = this;
  this->vfptr = (AkMusicActionVtbl *)&AkMusicActionPlay::`vftable';
  if ( v1 )
  {
    this->vfptr = (AkMusicActionVtbl *)&AkMusicAction::`vftable';
  }
  else
  {
    do
    {
      v3 = v2->m_listAutomation.m_pFirst;
      if ( v3 )
      {
        v2->m_listAutomation.m_pFirst = v3->pNextLightItem;
        AK::MemoryMgr::Free(g_DefaultPoolId, v3);
      }
    }
    while ( v2->m_listAutomation.m_pFirst );
    v2->vfptr = (AkMusicActionVtbl *)&AkMusicAction::`vftable';
  }
}

// File Line: 117
// RVA: 0xAADE30
void __fastcall AkMusicActionPlay::AttachClipAutomation(AkMusicActionPlay *this, unsigned int in_uClipIndex, AkClipAutomationType in_eType, int in_iTimeStart)
{
  CAkMusicTrack *v4; // rax
  int v5; // esi
  AkMusicActionPlay *v6; // rdi
  CAkClipAutomation *v7; // rbx
  signed __int64 v8; // rax
  AkMusicAutomation *v9; // rax
  AkMusicAutomation *v10; // rcx

  v4 = this->m_pTrack;
  v5 = in_iTimeStart;
  v6 = this;
  v7 = v4->m_arClipAutomation.m_pItems;
  v8 = (signed __int64)&v7[v4->m_arClipAutomation.m_uLength];
  if ( v7 != (CAkClipAutomation *)v8 )
  {
    do
    {
      if ( v7->m_uClipIndex == in_uClipIndex && v7->m_eAutoType == in_eType )
        break;
      ++v7;
    }
    while ( v7 != (CAkClipAutomation *)v8 );
    if ( v7 != (CAkClipAutomation *)v8 )
    {
      if ( v7 )
      {
        v9 = (AkMusicAutomation *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
        if ( v9 )
        {
          v9->pAutomationData = v7;
          v9->iTimeStart = v5;
          v9->pPBI = 0i64;
          v10 = v6->m_listAutomation.m_pFirst;
          if ( v10 )
          {
            v9->pNextLightItem = v10;
            v6->m_listAutomation.m_pFirst = v9;
          }
          else
          {
            v6->m_listAutomation.m_pFirst = v9;
            v9->pNextLightItem = 0i64;
          }
        }
      }
    }
  }
}

