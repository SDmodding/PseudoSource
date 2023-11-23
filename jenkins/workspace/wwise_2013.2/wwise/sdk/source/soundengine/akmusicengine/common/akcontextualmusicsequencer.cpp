// File Line: 31
// RVA: 0xAB4120
void __fastcall CAkContextualMusicSequencer::CAkContextualMusicSequencer(CAkContextualMusicSequencer *this)
{
  this->m_pFirst = 0i64;
  this->m_pLast = 0i64;
  this->vfptr = (CAkContextualMusicSequencerVtbl *)&CAkContextualMusicSequencer::`vftable;
}

// File Line: 35
// RVA: 0xAB4140
void __fastcall CAkContextualMusicSequencer::~CAkContextualMusicSequencer(CAkContextualMusicSequencer *this)
{
  this->vfptr = (CAkContextualMusicSequencerVtbl *)&CAkContextualMusicSequencer::`vftable;
  this->m_pFirst = 0i64;
  this->m_pLast = 0i64;
}

// File Line: 44
// RVA: 0xAB4320
void __fastcall CAkContextualMusicSequencer::ScheduleAction(
        CAkContextualMusicSequencer *this,
        AkMusicAction *in_pAction)
{
  AkMusicAction *m_pFirst; // rax
  AkMusicAction *v3; // r8
  AkMusicAction *m_pLast; // rax

  m_pFirst = this->m_pFirst;
  v3 = 0i64;
  if ( m_pFirst )
  {
    while ( in_pAction->m_iTime >= m_pFirst->m_iTime )
    {
      v3 = m_pFirst;
      m_pFirst = m_pFirst->pNextItem;
      if ( !m_pFirst )
        goto LABEL_4;
    }
    in_pAction->pNextItem = m_pFirst;
    if ( v3 )
      v3->pNextItem = in_pAction;
    else
      this->m_pFirst = in_pAction;
  }
  else
  {
LABEL_4:
    in_pAction->pNextItem = 0i64;
    m_pLast = this->m_pLast;
    if ( m_pLast )
      m_pLast->pNextItem = in_pAction;
    else
      this->m_pFirst = in_pAction;
    this->m_pLast = in_pAction;
  }
}

// File Line: 68
// RVA: 0xAB42D0
__int64 __fastcall CAkContextualMusicSequencer::PopImminentAction(
        CAkContextualMusicSequencer *this,
        int in_iNow,
        int in_iFrameDuration,
        AkMusicAction **out_pAction)
{
  AkMusicAction *m_pFirst; // r10
  AkMusicAction *v5; // rax
  AkMusicAction *pNextItem; // rax

  m_pFirst = this->m_pFirst;
  if ( m_pFirst && m_pFirst->m_iTime < in_iNow + in_iFrameDuration )
  {
    *out_pAction = m_pFirst;
    v5 = this->m_pFirst;
    if ( v5 )
    {
      pNextItem = v5->pNextItem;
      if ( !pNextItem )
        this->m_pLast = 0i64;
      this->m_pFirst = pNextItem;
    }
    return 45i64;
  }
  else
  {
    *out_pAction = 0i64;
    return 17i64;
  }
}

// File Line: 88
// RVA: 0xAB4190
void __fastcall CAkContextualMusicSequencer::ClearActionsByTarget(
        CAkContextualMusicSequencer *this,
        CAkMusicPBI *in_pTarget)
{
  AkMusicAction *m_pFirst; // rbx
  AkMusicAction *v3; // rdi
  AkMusicAction *pNextItem; // rax
  int v7; // edi
  AkMusicAction *v8; // [rsp+30h] [rbp-18h]
  AkMusicAction *v9; // [rsp+38h] [rbp-10h]

  m_pFirst = this->m_pFirst;
  v3 = 0i64;
  while ( m_pFirst )
  {
    if ( m_pFirst->vfptr->Type(m_pFirst) == MusicActionTypeStop && (CAkMusicPBI *)m_pFirst[1].vfptr == in_pTarget )
    {
      pNextItem = m_pFirst->pNextItem;
      v9 = v3;
      v8 = pNextItem;
      if ( m_pFirst == this->m_pFirst )
        this->m_pFirst = pNextItem;
      else
        v3->pNextItem = pNextItem;
      if ( m_pFirst == this->m_pLast )
        this->m_pLast = v3;
      v7 = g_DefaultPoolId;
      m_pFirst->vfptr->__vecDelDtor(m_pFirst, 0);
      AK::MemoryMgr::Free(v7, m_pFirst);
      v3 = v9;
      m_pFirst = v8;
    }
    else
    {
      v3 = m_pFirst;
      m_pFirst = m_pFirst->pNextItem;
    }
  }
}

// File Line: 106
// RVA: 0xAB4250
void __fastcall CAkContextualMusicSequencer::Flush(CAkContextualMusicSequencer *this)
{
  AkMusicAction *i; // rbx
  AkMusicAction *pNextItem; // rax
  int v4; // esi

  for ( i = this->m_pFirst; i; i = this->m_pFirst )
  {
    pNextItem = i->pNextItem;
    if ( pNextItem )
    {
      this->m_pFirst = pNextItem;
    }
    else
    {
      this->m_pFirst = 0i64;
      this->m_pLast = 0i64;
    }
    v4 = g_DefaultPoolId;
    i->vfptr->__vecDelDtor(i, 0);
    AK::MemoryMgr::Free(v4, i);
  }
}

