// File Line: 31
// RVA: 0xAB4120
void __fastcall CAkContextualMusicSequencer::CAkContextualMusicSequencer(CAkContextualMusicSequencer *this)
{
  this->m_pFirst = 0i64;
  this->m_pLast = 0i64;
  this->vfptr = (CAkContextualMusicSequencerVtbl *)&CAkContextualMusicSequencer::`vftable';
}

// File Line: 35
// RVA: 0xAB4140
void __fastcall CAkContextualMusicSequencer::~CAkContextualMusicSequencer(CAkContextualMusicSequencer *this)
{
  this->vfptr = (CAkContextualMusicSequencerVtbl *)&CAkContextualMusicSequencer::`vftable';
  this->m_pFirst = 0i64;
  this->m_pLast = 0i64;
}

// File Line: 44
// RVA: 0xAB4320
void __fastcall CAkContextualMusicSequencer::ScheduleAction(CAkContextualMusicSequencer *this, AkMusicAction *in_pAction)
{
  AkMusicAction *v2; // rax
  AkMusicAction *v3; // r8
  AkMusicAction *v4; // rax

  v2 = this->m_pFirst;
  v3 = 0i64;
  if ( v2 )
  {
    while ( in_pAction->m_iTime >= v2->m_iTime )
    {
      v3 = v2;
      v2 = v2->pNextItem;
      if ( !v2 )
        goto LABEL_4;
    }
    in_pAction->pNextItem = v2;
    if ( v3 )
      v3->pNextItem = in_pAction;
    else
      this->m_pFirst = in_pAction;
  }
  else
  {
LABEL_4:
    in_pAction->pNextItem = 0i64;
    v4 = this->m_pLast;
    if ( v4 )
      v4->pNextItem = in_pAction;
    else
      this->m_pFirst = in_pAction;
    this->m_pLast = in_pAction;
  }
}

// File Line: 68
// RVA: 0xAB42D0
signed __int64 __fastcall CAkContextualMusicSequencer::PopImminentAction(CAkContextualMusicSequencer *this, int in_iNow, int in_iFrameDuration, AkMusicAction **out_pAction)
{
  AkMusicAction *v4; // r10
  AkMusicAction *v5; // rax
  AkMusicAction *v6; // rax
  signed __int64 result; // rax

  v4 = this->m_pFirst;
  if ( v4 && v4->m_iTime < in_iNow + in_iFrameDuration )
  {
    *out_pAction = v4;
    v5 = this->m_pFirst;
    if ( v5 )
    {
      v6 = v5->pNextItem;
      if ( !v6 )
        this->m_pLast = 0i64;
      this->m_pFirst = v6;
    }
    result = 45i64;
  }
  else
  {
    *out_pAction = 0i64;
    result = 17i64;
  }
  return result;
}

// File Line: 88
// RVA: 0xAB4190
void __fastcall CAkContextualMusicSequencer::ClearActionsByTarget(CAkContextualMusicSequencer *this, CAkMusicPBI *in_pTarget)
{
  AkMusicAction *v2; // rbx
  AkMusicAction *v3; // rdi
  CAkMusicPBI *v4; // rbp
  CAkContextualMusicSequencer *v5; // rsi
  AkMusicAction *v6; // rax
  int v7; // edi
  __int128 v8; // [rsp+20h] [rbp-28h]
  __m128i v9; // [rsp+30h] [rbp-18h]

  v2 = this->m_pFirst;
  v3 = 0i64;
  v4 = in_pTarget;
  v5 = this;
  while ( v2 )
  {
    if ( v2->vfptr->Type(v2) != 1 || (CAkMusicPBI *)v2[1].vfptr != v4 )
    {
      v3 = v2;
      v2 = v2->pNextItem;
    }
    else
    {
      v6 = v2->pNextItem;
      v9.m128i_i64[1] = (__int64)v3;
      v9.m128i_i64[0] = (__int64)v6;
      if ( v2 == v5->m_pFirst )
        v5->m_pFirst = v6;
      else
        v3->pNextItem = v6;
      if ( v2 == v5->m_pLast )
        v5->m_pLast = v3;
      v7 = g_DefaultPoolId;
      _mm_store_si128((__m128i *)&v8, v9);
      if ( v2 )
      {
        v2->vfptr->__vecDelDtor(v2, 0);
        AK::MemoryMgr::Free(v7, v2);
      }
      v3 = (AkMusicAction *)*((_QWORD *)&v8 + 1);
      v2 = (AkMusicAction *)v8;
    }
  }
}

// File Line: 106
// RVA: 0xAB4250
void __fastcall CAkContextualMusicSequencer::Flush(CAkContextualMusicSequencer *this)
{
  AkMusicAction *v1; // rbx
  CAkContextualMusicSequencer *v2; // rdi
  AkMusicAction *v3; // rax
  int v4; // esi

  v1 = this->m_pFirst;
  v2 = this;
  if ( v1 )
  {
    if ( !v1 )
      goto LABEL_6;
    do
    {
      v3 = v1->pNextItem;
      if ( v3 )
      {
        v2->m_pFirst = v3;
      }
      else
      {
        v2->m_pFirst = 0i64;
        v2->m_pLast = 0i64;
      }
LABEL_6:
      v4 = g_DefaultPoolId;
      if ( v1 )
      {
        v1->vfptr->__vecDelDtor(v1, 0);
        AK::MemoryMgr::Free(v4, v1);
      }
      v1 = v2->m_pFirst;
    }
    while ( v1 );
  }
}

