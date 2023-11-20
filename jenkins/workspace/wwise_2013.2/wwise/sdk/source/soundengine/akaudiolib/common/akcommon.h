// File Line: 456
// RVA: 0xA65330
void __fastcall CAkOutputDevices::~CAkOutputDevices(CAkOutputDevices *this)
{
  CAkOutputDevices *v1; // rdi
  AkDeviceInfo *v2; // rbx
  int v3; // esi

  v1 = this;
  if ( this->m_listDeviceVolumes.m_pFirst )
  {
    do
    {
      v2 = v1->m_listDeviceVolumes.m_pFirst;
      if ( v1->m_listDeviceVolumes.m_pFirst )
        v1->m_listDeviceVolumes.m_pFirst = v2->pNextLightItem;
      v3 = g_LEngineDefaultPoolId;
      if ( v2 )
      {
        v2->vfptr->__vecDelDtor(v2, 0);
        AK::MemoryMgr::Free(v3, v2);
      }
    }
    while ( v1->m_listDeviceVolumes.m_pFirst );
    v1->m_listDeviceVolumes.m_pFirst = 0i64;
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
  int v1; // eax
  AkAudioBuffer *v2; // r9
  unsigned int v3; // er10
  unsigned int v4; // edx
  __int64 v5; // r8
  unsigned int i; // edi
  __int64 v7; // rdx
  _DWORD *v8; // rdi
  __int64 j; // rcx

  v1 = io_pAudioBuffer->uValidFrames;
  v2 = io_pAudioBuffer;
  v3 = io_pAudioBuffer->uMaxFrames - v1;
  if ( io_pAudioBuffer->uMaxFrames != v1 )
  {
    v4 = io_pAudioBuffer->uChannelMask;
    v5 = 0i64;
    for ( i = 0; v4; v4 &= v4 - 1 )
      ++i;
    if ( i )
    {
      v7 = i;
      do
      {
        v8 = (char *)v2->pData + 4 * (v2->uValidFrames + v5 * v2->uMaxFrames);
        if ( v3 )
        {
          for ( j = v3; j; --j )
          {
            *v8 = 0;
            ++v8;
          }
        }
        ++v5;
        --v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 579
// RVA: 0xA84AD0
void __fastcall ZeroPrePadBuffer(AkAudioBuffer *io_pAudioBuffer, unsigned int in_ulNumFramestoZero)
{
  __int64 v2; // r10
  AkAudioBuffer *v3; // r11
  __int64 v4; // r8
  unsigned int v5; // edi
  unsigned int i; // er9
  __int64 v7; // rdx
  _DWORD *v8; // rdi
  __int64 j; // rcx

  v2 = in_ulNumFramestoZero;
  v3 = io_pAudioBuffer;
  if ( in_ulNumFramestoZero )
  {
    v4 = 0i64;
    v5 = io_pAudioBuffer->uChannelMask;
    for ( i = 0; v5; v5 &= v5 - 1 )
      ++i;
    if ( i )
    {
      v7 = i;
      do
      {
        v8 = (char *)v3->pData + 4 * v4 * v3->uMaxFrames;
        if ( (_DWORD)v2 )
        {
          for ( j = v2; j; --j )
          {
            *v8 = 0;
            ++v8;
          }
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
  unsigned int v2; // eax
  int i; // er9

  if ( in_ulNumFramestoZero )
  {
    v2 = io_pAudioBuffer->uChannelMask;
    for ( i = 0; v2; v2 &= v2 - 1 )
      ++i;
    memset(io_pAudioBuffer->pData, 0, 4i64 * in_ulNumFramestoZero * i);
  }
}

