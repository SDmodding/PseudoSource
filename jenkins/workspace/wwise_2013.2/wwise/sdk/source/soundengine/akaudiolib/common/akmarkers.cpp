// File Line: 23
// RVA: 0xAA0530
void __fastcall CAkMarkers::CAkMarkers(CAkMarkers *this)
{
  this->m_pMarkers = 0i64;
  this->m_hdrMarkers.uNumMarkers = 0;
}

// File Line: 33
// RVA: 0xAA0540
signed __int64 __fastcall CAkMarkers::Allocate(CAkMarkers *this, unsigned int in_uNumMarkers)
{
  CAkMarkers *v2; // rbx
  AkAudioMarker *v3; // rax

  this->m_hdrMarkers.uNumMarkers = in_uNumMarkers;
  v2 = this;
  v3 = (AkAudioMarker *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 16i64 * in_uNumMarkers);
  v2->m_pMarkers = v3;
  if ( v3 )
    return 1i64;
  v2->m_hdrMarkers.uNumMarkers = 0;
  return 52i64;
}

// File Line: 48
// RVA: 0xAA06A0
void __fastcall CAkMarkers::Free(CAkMarkers *this)
{
  CAkMarkers *v1; // rbx
  unsigned int v2; // edi
  char *v3; // rdx

  v1 = this;
  if ( this->m_pMarkers )
  {
    v2 = 0;
    if ( this->m_hdrMarkers.uNumMarkers > 0 )
    {
      do
      {
        v3 = v1->m_pMarkers[v2].strLabel;
        if ( v3 )
        {
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v3);
          v1->m_pMarkers[v2].strLabel = 0i64;
        }
        ++v2;
      }
      while ( v2 < v1->m_hdrMarkers.uNumMarkers );
    }
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1->m_pMarkers);
    v1->m_pMarkers = 0i64;
    v1->m_hdrMarkers.uNumMarkers = 0;
  }
  else
  {
    this->m_hdrMarkers.uNumMarkers = 0;
  }
}

// File Line: 68
// RVA: 0xAA0830
signed __int64 __fastcall CAkMarkers::SetLabel(CAkMarkers *this, unsigned int in_idx, char *in_psLabel, unsigned int in_uStrSize)
{
  __int64 v4; // rbx
  CAkMarkers *v5; // r14
  unsigned int v6; // ebp
  char *v7; // rsi
  char *v8; // rax
  char *v9; // rdi
  signed __int64 result; // rax

  v4 = in_uStrSize;
  v5 = this;
  v6 = in_idx;
  v7 = in_psLabel;
  v8 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, in_uStrSize + 1);
  v9 = v8;
  if ( !v8 )
    return 52i64;
  memmove(v8, v7, (unsigned int)v4);
  v9[v4] = 0;
  result = 1i64;
  v5->m_pMarkers[v6].strLabel = v9;
  return result;
}

// File Line: 85
// RVA: 0xAA0580
void __fastcall CAkMarkers::CopyRelevantMarkers(CAkMarkers *this, CAkPBI *in_pCtx, AkPipelineBuffer *io_buffer, unsigned int in_ulBufferStartPos)
{
  unsigned int v4; // ebp
  AkPipelineBuffer *v5; // rsi
  CAkPBI *v6; // r15
  CAkMarkers *v7; // rbx
  unsigned int v8; // edi
  int v9; // er14
  unsigned int v10; // edx
  unsigned int v11; // er8
  unsigned __int16 v12; // ax
  AkBufferMarker *v13; // rax
  CAkPBI **v14; // r9
  signed __int64 v15; // r8
  unsigned int v16; // ecx
  AkAudioMarker *v17; // rcx

  v4 = in_ulBufferStartPos;
  v5 = io_buffer;
  v6 = in_pCtx;
  v7 = this;
  if ( this->m_pMarkers && in_pCtx->m_uRegisteredNotif & 4 )
  {
    v8 = 0;
    v9 = io_buffer->uValidFrames;
    v10 = 0;
    io_buffer->pMarkers = 0i64;
    io_buffer->uNumMarkers = 0;
    if ( this->m_hdrMarkers.uNumMarkers )
    {
      do
      {
        v11 = this->m_pMarkers[v10].dwPosition;
        if ( v11 >= in_ulBufferStartPos && v11 < v9 + in_ulBufferStartPos )
          ++v5->uNumMarkers;
        ++v10;
      }
      while ( v10 < this->m_hdrMarkers.uNumMarkers );
    }
    v12 = v5->uNumMarkers;
    if ( v12 )
    {
      v13 = (AkBufferMarker *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 32i64 * v12);
      v14 = &v13->pContext;
      v5->pMarkers = v13;
      if ( v13 )
      {
        if ( v7->m_hdrMarkers.uNumMarkers > 0 )
        {
          v15 = (signed __int64)&v13->marker;
          do
          {
            v16 = v7->m_pMarkers[v8].dwPosition;
            if ( v16 >= v4 && v16 < v9 + v4 )
            {
              *v14 = v6;
              v14 += 4;
              v15 += 32i64;
              *(_DWORD *)(v15 - 40) = v7->m_pMarkers[v8].dwPosition - v4;
              v17 = v7->m_pMarkers;
              *(_QWORD *)(v15 - 32) = *(_QWORD *)&v17[v8].dwIdentifier;
              *(_QWORD *)(v15 - 24) = v17[v8].strLabel;
            }
            ++v8;
          }
          while ( v8 < v7->m_hdrMarkers.uNumMarkers );
        }
      }
      else
      {
        v5->uNumMarkers = 0;
      }
    }
  }
}

// File Line: 133
// RVA: 0xAA07A0
void __fastcall CAkMarkers::NotifyRelevantMarkers(CAkMarkers *this, CAkPBI *in_pCtx, unsigned int in_uStartSample, unsigned int in_uStopSample)
{
  unsigned int v4; // ebp
  unsigned int v5; // er14
  CAkPBI *v6; // rsi
  CAkMarkers *v7; // rdi
  unsigned int v8; // ebx
  AkAudioMarker *v9; // r8
  unsigned int v10; // eax

  v4 = in_uStopSample;
  v5 = in_uStartSample;
  v6 = in_pCtx;
  v7 = this;
  if ( this->m_pMarkers )
  {
    if ( in_pCtx->m_uRegisteredNotif & 4 )
    {
      v8 = 0;
      if ( this->m_hdrMarkers.uNumMarkers )
      {
        do
        {
          v9 = &v7->m_pMarkers[v8];
          v10 = v9->dwPosition;
          if ( v10 >= v5 && v10 < v4 )
            CAkPlayingMgr::NotifyMarker(g_pPlayingMgr, v6, v9);
          ++v8;
        }
        while ( v8 < v7->m_hdrMarkers.uNumMarkers );
      }
    }
  }
}

// File Line: 148
// RVA: 0xAA0740
AkAudioMarker *__fastcall CAkMarkers::GetClosestMarker(CAkMarkers *this, unsigned int in_uPosition)
{
  unsigned int v2; // er11
  signed __int64 v3; // r8
  unsigned int v4; // er10
  unsigned int v5; // er9
  AkAudioMarker *v6; // rbx
  unsigned int *v7; // rcx
  unsigned int v8; // eax

  v2 = this->m_hdrMarkers.uNumMarkers;
  v3 = 0i64;
  v4 = 0;
  v5 = 0;
  if ( this->m_hdrMarkers.uNumMarkers )
  {
    v6 = this->m_pMarkers;
    v7 = &v6->dwPosition;
    do
    {
      v8 = abs(*v7 - in_uPosition);
      if ( !v3 || v8 < v4 )
      {
        v4 = v8;
        v3 = (signed __int64)&v6[v5];
      }
      ++v5;
      v7 += 4;
    }
    while ( v5 < v2 );
  }
  return (AkAudioMarker *)v3;
}

