// File Line: 456
// RVA: 0xA65330
void __fastcall CAkOutputDevices::~CAkOutputDevices(CAkOutputDevices *this)
{
  AkDeviceInfo *m_pFirst; // rbx
  int v3; // esi

  if ( this->m_listDeviceVolumes.m_pFirst )
  {
    do
    {
      m_pFirst = this->m_listDeviceVolumes.m_pFirst;
      if ( this->m_listDeviceVolumes.m_pFirst )
        this->m_listDeviceVolumes.m_pFirst = m_pFirst->pNextLightItem;
      v3 = g_LEngineDefaultPoolId;
      if ( m_pFirst )
      {
        m_pFirst->vfptr->__vecDelDtor(m_pFirst, 0);
        AK::MemoryMgr::Free(v3, m_pFirst);
      }
    }
    while ( this->m_listDeviceVolumes.m_pFirst );
    this->m_listDeviceVolumes.m_pFirst = 0i64;
  }
  else
  {
    this->m_listDeviceVolumes.m_pFirst = 0i64;
  }
}

// File Line: 560
// RVA: 0xA7F180
void __fastcall ZeroPadBuffer(AkAudioBuffer *io_pAudioBuffer)
{
  unsigned int v2; // r10d
  unsigned int uChannelMask; // edx
  __int64 v4; // r8
  unsigned int i; // edi
  __int64 v6; // rdx
  _DWORD *v7; // rdi
  __int64 j; // rcx

  v2 = io_pAudioBuffer->uMaxFrames - io_pAudioBuffer->uValidFrames;
  if ( v2 )
  {
    uChannelMask = io_pAudioBuffer->uChannelMask;
    v4 = 0i64;
    for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++i;
    if ( i )
    {
      v6 = i;
      do
      {
        v7 = (char *)io_pAudioBuffer->pData + 4 * io_pAudioBuffer->uValidFrames + 4 * v4 * io_pAudioBuffer->uMaxFrames;
        for ( j = v2; j; --j )
          *v7++ = 0;
        ++v4;
        --v6;
      }
      while ( v6 );
    }
  }
}

// File Line: 579
// RVA: 0xA84AD0
void __fastcall ZeroPrePadBuffer(AkAudioBuffer *io_pAudioBuffer, unsigned int in_ulNumFramestoZero)
{
  __int64 v2; // r10
  __int64 v4; // r8
  unsigned int uChannelMask; // edi
  unsigned int i; // r9d
  __int64 v7; // rdx
  _DWORD *v8; // rdi
  __int64 j; // rcx

  v2 = in_ulNumFramestoZero;
  if ( in_ulNumFramestoZero )
  {
    v4 = 0i64;
    uChannelMask = io_pAudioBuffer->uChannelMask;
    for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++i;
    if ( i )
    {
      v7 = i;
      do
      {
        v8 = (char *)io_pAudioBuffer->pData + 4 * v4 * io_pAudioBuffer->uMaxFrames;
        if ( (_DWORD)v2 )
        {
          for ( j = v2; j; --j )
            *v8++ = 0;
        }
        ++v4;
        --v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 637
// RVA: 0xA84B40
void __fastcall ZeroPrePadBufferInterleaved(AkAudioBuffer *io_pAudioBuffer, unsigned int in_ulNumFramestoZero)
{
  unsigned int uChannelMask; // eax
  int i; // r9d

  if ( in_ulNumFramestoZero )
  {
    uChannelMask = io_pAudioBuffer->uChannelMask;
    for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++i;
    memset(io_pAudioBuffer->pData, 0, 4i64 * in_ulNumFramestoZero * i);
  }
}

