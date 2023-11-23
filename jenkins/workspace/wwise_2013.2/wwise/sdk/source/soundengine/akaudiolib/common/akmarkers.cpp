// File Line: 23
// RVA: 0xAA0530
void __fastcall CAkMarkers::CAkMarkers(CAkMarkers *this)
{
  this->m_pMarkers = 0i64;
  this->m_hdrMarkers.uNumMarkers = 0;
}

// File Line: 33
// RVA: 0xAA0540
__int64 __fastcall CAkMarkers::Allocate(CAkMarkers *this, unsigned int in_uNumMarkers)
{
  AkAudioMarker *v3; // rax

  this->m_hdrMarkers.uNumMarkers = in_uNumMarkers;
  v3 = (AkAudioMarker *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 16i64 * in_uNumMarkers);
  this->m_pMarkers = v3;
  if ( v3 )
    return 1i64;
  this->m_hdrMarkers.uNumMarkers = 0;
  return 52i64;
}

// File Line: 48
// RVA: 0xAA06A0
void __fastcall CAkMarkers::Free(CAkMarkers *this)
{
  unsigned int i; // edi
  char *strLabel; // rdx

  if ( this->m_pMarkers )
  {
    for ( i = 0; i < this->m_hdrMarkers.uNumMarkers; ++i )
    {
      strLabel = this->m_pMarkers[i].strLabel;
      if ( strLabel )
      {
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, strLabel);
        this->m_pMarkers[i].strLabel = 0i64;
      }
    }
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, this->m_pMarkers);
    this->m_pMarkers = 0i64;
    this->m_hdrMarkers.uNumMarkers = 0;
  }
  else
  {
    this->m_hdrMarkers.uNumMarkers = 0;
  }
}

// File Line: 68
// RVA: 0xAA0830
__int64 __fastcall CAkMarkers::SetLabel(
        CAkMarkers *this,
        unsigned int in_idx,
        char *in_psLabel,
        unsigned int in_uStrSize)
{
  __int64 v4; // rbx
  char *v8; // rax
  char *v9; // rdi
  __int64 result; // rax

  v4 = in_uStrSize;
  v8 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, in_uStrSize + 1);
  v9 = v8;
  if ( !v8 )
    return 52i64;
  memmove(v8, in_psLabel, (unsigned int)v4);
  v9[v4] = 0;
  result = 1i64;
  this->m_pMarkers[in_idx].strLabel = v9;
  return result;
}

// File Line: 85
// RVA: 0xAA0580
void __fastcall CAkMarkers::CopyRelevantMarkers(
        CAkMarkers *this,
        CAkPBI *in_pCtx,
        AkPipelineBuffer *io_buffer,
        unsigned int in_ulBufferStartPos)
{
  unsigned int v8; // edi
  int uValidFrames; // r14d
  unsigned int v10; // edx
  unsigned int dwPosition; // r8d
  unsigned __int16 uNumMarkers; // ax
  AkBufferMarker *v13; // rax
  AkBufferMarker *v14; // r9
  AkAudioMarker *p_marker; // r8
  unsigned int v16; // ecx
  AkAudioMarker *m_pMarkers; // rcx

  if ( this->m_pMarkers && (in_pCtx->m_uRegisteredNotif & 4) != 0 )
  {
    v8 = 0;
    uValidFrames = io_buffer->uValidFrames;
    v10 = 0;
    io_buffer->pMarkers = 0i64;
    for ( io_buffer->uNumMarkers = 0; v10 < this->m_hdrMarkers.uNumMarkers; ++v10 )
    {
      dwPosition = this->m_pMarkers[v10].dwPosition;
      if ( dwPosition >= in_ulBufferStartPos && dwPosition < uValidFrames + in_ulBufferStartPos )
        ++io_buffer->uNumMarkers;
    }
    uNumMarkers = io_buffer->uNumMarkers;
    if ( uNumMarkers )
    {
      v13 = (AkBufferMarker *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 32i64 * uNumMarkers);
      v14 = v13;
      io_buffer->pMarkers = v13;
      if ( v13 )
      {
        if ( this->m_hdrMarkers.uNumMarkers )
        {
          p_marker = &v13->marker;
          do
          {
            v16 = this->m_pMarkers[v8].dwPosition;
            if ( v16 >= in_ulBufferStartPos && v16 < uValidFrames + in_ulBufferStartPos )
            {
              v14->pContext = in_pCtx;
              ++v14;
              p_marker += 2;
              LODWORD(p_marker[-3].strLabel) = this->m_pMarkers[v8].dwPosition - in_ulBufferStartPos;
              m_pMarkers = this->m_pMarkers;
              *(_QWORD *)&p_marker[-2].dwIdentifier = *(_QWORD *)&m_pMarkers[v8].dwIdentifier;
              p_marker[-2].strLabel = m_pMarkers[v8].strLabel;
            }
            ++v8;
          }
          while ( v8 < this->m_hdrMarkers.uNumMarkers );
        }
      }
      else
      {
        io_buffer->uNumMarkers = 0;
      }
    }
  }
}

// File Line: 133
// RVA: 0xAA07A0
void __fastcall CAkMarkers::NotifyRelevantMarkers(
        CAkMarkers *this,
        CAkPBI *in_pCtx,
        unsigned int in_uStartSample,
        unsigned int in_uStopSample)
{
  unsigned int i; // ebx
  AkAudioMarker *v9; // r8
  unsigned int dwPosition; // eax

  if ( this->m_pMarkers )
  {
    if ( (in_pCtx->m_uRegisteredNotif & 4) != 0 )
    {
      for ( i = 0; i < this->m_hdrMarkers.uNumMarkers; ++i )
      {
        v9 = &this->m_pMarkers[i];
        dwPosition = v9->dwPosition;
        if ( dwPosition >= in_uStartSample && dwPosition < in_uStopSample )
          CAkPlayingMgr::NotifyMarker(g_pPlayingMgr, in_pCtx, v9);
      }
    }
  }
}

// File Line: 148
// RVA: 0xAA0740
AkAudioMarker *__fastcall CAkMarkers::GetClosestMarker(CAkMarkers *this, unsigned int in_uPosition)
{
  unsigned int uNumMarkers; // r11d
  AkAudioMarker *v3; // r8
  unsigned int v4; // r10d
  unsigned int v5; // r9d
  AkAudioMarker *m_pMarkers; // rbx
  unsigned int *p_dwPosition; // rcx
  unsigned int v8; // eax

  uNumMarkers = this->m_hdrMarkers.uNumMarkers;
  v3 = 0i64;
  v4 = 0;
  v5 = 0;
  if ( this->m_hdrMarkers.uNumMarkers )
  {
    m_pMarkers = this->m_pMarkers;
    p_dwPosition = &m_pMarkers->dwPosition;
    do
    {
      v8 = abs32(*p_dwPosition - in_uPosition);
      if ( !v3 || v8 < v4 )
      {
        v4 = v8;
        v3 = &m_pMarkers[v5];
      }
      ++v5;
      p_dwPosition += 4;
    }
    while ( v5 < uNumMarkers );
  }
  return v3;
}

