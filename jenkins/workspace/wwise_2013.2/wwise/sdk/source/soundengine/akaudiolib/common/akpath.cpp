// File Line: 35
// RVA: 0xA865C0
void __fastcall CAkPath::CAkPath(CAkPath *this)
{
  this->m_PBIsList.m_pItems = 0i64;
  *(_QWORD *)&this->m_PBIsList.m_uLength = 0i64;
  this->m_eState = NotRunning;
  this->m_pPathsList = 0i64;
  this->m_pbPlayed = 0i64;
  this->m_pCurrentList = 0i64;
  this->m_ulListSize = 0;
  this->m_PathMode = AkStepSequence;
  *(_WORD *)&this->m_bWasStarted = 0;
  *(_WORD *)&this->m_iPotentialUsers = 0;
  *(_QWORD *)&this->m_StartTime = 0i64;
  this->m_Duration = 0;
  this->m_TimePaused = 0;
  *(_QWORD *)&this->m_ulSoundUniqueID = 0i64;
  this->m_pNoFollowOrientationRotation = 0i64;
}

// File Line: 63
// RVA: 0xA86E10
void __fastcall CAkPath::Term(CAkPath *this)
{
  CAkPBI **m_pItems; // rdx
  bool *m_pbPlayed; // rdx
  float *m_pNoFollowOrientationRotation; // rdx

  this->m_eState = NotRunning;
  m_pItems = this->m_PBIsList.m_pItems;
  if ( m_pItems )
  {
    this->m_PBIsList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_PBIsList.m_pItems = 0i64;
    this->m_PBIsList.m_ulReserved = 0;
  }
  if ( (this->m_PathMode & 2) != 0 )
  {
    m_pbPlayed = this->m_pbPlayed;
    if ( m_pbPlayed )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pbPlayed);
      this->m_pbPlayed = 0i64;
    }
  }
  m_pNoFollowOrientationRotation = this->m_pNoFollowOrientationRotation;
  if ( m_pNoFollowOrientationRotation )
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pNoFollowOrientationRotation);
}

// File Line: 88
// RVA: 0xA86BC0
__int64 __fastcall CAkPath::Start(CAkPath *this, signed int in_CurrentBufferTick)
{
  AkPathListItem *m_pCurrentList; // r8
  AkPathVertex *pVertices; // rcx
  int v6; // eax
  int iNumVertices; // ecx
  float X; // xmm8_4
  float Z; // xmm7_4
  float Y; // xmm9_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm7_4
  CAkPBI **m_pItems; // rax
  CAkGen3DParams *m_p3DSound; // rdx
  signed int m_Duration; // ecx
  __int64 result; // rax
  float v19; // xmm10_4

  m_pCurrentList = this->m_pCurrentList;
  if ( !m_pCurrentList )
    return 2i64;
  this->m_bWasStarted = 1;
  if ( m_pCurrentList->iNumVertices <= 0 )
    return 37i64;
  this->m_uCurrentVertex = 0;
  pVertices = m_pCurrentList->pVertices;
  this->m_uCurrentVertex = 1;
  this->m_StartPosition.X = pVertices->Vertex.X;
  this->m_StartPosition.Y = pVertices->Vertex.Y;
  this->m_StartPosition.Z = pVertices->Vertex.Z;
  v6 = (AkAudioLibSettings::g_msPerBufferTick + pVertices->Duration - 1) / AkAudioLibSettings::g_msPerBufferTick;
  if ( !v6 )
    v6 = 1;
  this->m_Duration = v6;
  iNumVertices = m_pCurrentList->iNumVertices;
  if ( iNumVertices <= 1 )
  {
    *(_QWORD *)&this->m_Direction.X = 0i64;
    this->m_Direction.Z = 0.0;
  }
  else
  {
    X = m_pCurrentList->pVertices[1].Vertex.X;
    Z = m_pCurrentList->pVertices[1].Vertex.Z;
    Y = m_pCurrentList->pVertices[1].Vertex.Y;
    if ( X == this->m_StartPosition.X
      && Y == this->m_StartPosition.Y
      && Z == this->m_StartPosition.Z
      && iNumVertices <= 2 )
    {
      CAkPath::RandomizePosition(this, &this->m_StartPosition);
      v11 = this->m_StartPosition.X;
      Y = this->m_StartPosition.Y;
      v12 = this->m_StartPosition.Z;
    }
    else
    {
      CAkPath::RandomizePosition(this, &this->m_StartPosition);
      v11 = X + (float)((float)((float)((float)rand() * 0.000061038882) - 1.0) * this->m_pCurrentList->fRangeX);
      v12 = Z + (float)((float)((float)((float)rand() * 0.000061038882) - 1.0) * this->m_pCurrentList->fRangeY);
    }
    v13 = Y - this->m_StartPosition.Y;
    v14 = v12 - this->m_StartPosition.Z;
    this->m_Direction.X = v11 - this->m_StartPosition.X;
    this->m_Direction.Y = v13;
    this->m_Direction.Z = v14;
  }
  m_pItems = this->m_PBIsList.m_pItems;
  if ( m_pItems != &m_pItems[this->m_PBIsList.m_uLength] )
  {
    do
    {
      m_p3DSound = (*m_pItems)->m_p3DSound;
      if ( (*((_BYTE *)&m_p3DSound->m_Params + 68) & 4) == 0 )
      {
        m_p3DSound->m_Params.m_Position.X = this->m_StartPosition.X;
        m_p3DSound->m_Params.m_Position.Y = this->m_StartPosition.Y;
        m_p3DSound->m_Params.m_Position.Z = this->m_StartPosition.Z;
      }
      ++m_pItems;
    }
    while ( m_pItems != &this->m_PBIsList.m_pItems[this->m_PBIsList.m_uLength] );
  }
  m_Duration = this->m_Duration;
  this->m_eState = Running;
  this->m_StartTime = in_CurrentBufferTick;
  this->m_EndTime = m_Duration + in_CurrentBufferTick;
  result = 1i64;
  v19 = 1.0 / (float)m_Duration;
  this->m_fa = v19;
  LODWORD(this->m_fb) = COERCE_UNSIGNED_INT((float)in_CurrentBufferTick * v19) ^ _xmm[0];
  return result;
}

// File Line: 186
// RVA: 0xA86950
void __fastcall CAkPath::Pause(CAkPath *this, unsigned int in_CurrentBufferTick)
{
  this->m_TimePaused = in_CurrentBufferTick;
  this->m_eState = Suspended;
}

// File Line: 194
// RVA: 0xA86A90
void __fastcall CAkPath::Resume(CAkPath *this, unsigned int in_CurrentBufferTick)
{
  int v2; // edx
  signed int m_StartTime; // eax

  v2 = in_CurrentBufferTick - this->m_TimePaused;
  this->m_eState = Running;
  this->m_StartTime += v2;
  m_StartTime = this->m_StartTime;
  this->m_EndTime += v2;
  LODWORD(this->m_fb) = COERCE_UNSIGNED_INT((float)m_StartTime * this->m_fa) ^ _xmm[0];
}

// File Line: 208
// RVA: 0xA867B0
void __fastcall CAkPath::NextVertex(CAkPath *this)
{
  AkPathListItem *m_pCurrentList; // rcx
  int m_uCurrentVertex; // eax
  __int64 v4; // rbx
  int v5; // eax
  AkPathVertex *pVertices; // rcx
  float X; // xmm7_4
  float Y; // xmm8_4
  float Z; // xmm9_4
  float v10; // xmm7_4
  int v11; // eax
  int m_EndTime; // edx
  signed int m_Duration; // ecx
  float v14; // xmm8_4
  float v15; // xmm0_4
  float v16; // xmm10_4

  m_pCurrentList = this->m_pCurrentList;
  m_uCurrentVertex = this->m_uCurrentVertex;
  if ( m_uCurrentVertex < m_pCurrentList->iNumVertices )
  {
    v4 = (__int64)&m_pCurrentList->pVertices[this->m_uCurrentVertex];
    this->m_uCurrentVertex = m_uCurrentVertex + 1;
    this->m_StartPosition.X = *(float *)v4;
    this->m_StartPosition.Y = *(float *)(v4 + 4);
    this->m_StartPosition.Z = *(float *)(v4 + 8);
    CAkPath::RandomizePosition(this, &this->m_StartPosition);
    v5 = (AkAudioLibSettings::g_msPerBufferTick + *(_DWORD *)(v4 + 12) - 1) / AkAudioLibSettings::g_msPerBufferTick;
    if ( !v5 )
      v5 = 1;
    this->m_Duration = v5;
  }
  if ( this->m_uCurrentVertex < this->m_pCurrentList->iNumVertices || (unsigned int)CAkPath::GetNextPathList(this) == 1 )
  {
    pVertices = this->m_pCurrentList->pVertices;
    X = pVertices[this->m_uCurrentVertex].Vertex.X;
    Y = pVertices[this->m_uCurrentVertex].Vertex.Y;
    Z = pVertices[this->m_uCurrentVertex].Vertex.Z;
    v10 = X + (float)((float)((float)((float)rand() * 0.000061038882) - 1.0) * this->m_pCurrentList->fRangeX);
    v11 = rand();
    m_EndTime = this->m_EndTime;
    m_Duration = this->m_Duration;
    v14 = Y - this->m_StartPosition.Y;
    v15 = (float)((float)((float)v11 * 0.000061038882) - 1.0) * this->m_pCurrentList->fRangeY;
    this->m_Direction.X = v10 - this->m_StartPosition.X;
    this->m_Direction.Y = v14;
    this->m_StartTime = m_EndTime;
    this->m_EndTime = m_Duration + m_EndTime;
    v16 = 1.0 / (float)m_Duration;
    this->m_Direction.Z = (float)(Z + v15) - this->m_StartPosition.Z;
    this->m_fa = v16;
    LODWORD(this->m_fb) = COERCE_UNSIGNED_INT((float)m_EndTime * v16) ^ _xmm[0];
  }
  else
  {
    this->m_eState = NotRunning;
  }
}

// File Line: 281
// RVA: 0xA867A0
_BOOL8 __fastcall CAkPath::IsIdle(CAkPath *this)
{
  return this->m_eState == NotRunning;
}

// File Line: 288
// RVA: 0xA86E80
void __fastcall CAkPath::UpdatePosition(CAkPath *this, unsigned int in_CurrentBufferTick)
{
  float v2; // xmm1_4
  float v4; // xmm0_4
  CAkPBI **m_pItems; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  CAkGen3DParams *m_p3DSound; // rdx

  v2 = *(float *)&FLOAT_1_0;
  v4 = (float)((float)(int)in_CurrentBufferTick * this->m_fa) + this->m_fb;
  if ( v4 >= 1.0 || (v2 = 0.0, v4 <= 0.0) )
    v4 = v2;
  m_pItems = this->m_PBIsList.m_pItems;
  v6 = v4;
  v7 = v4;
  v8 = (float)(v4 * this->m_Direction.Z) + this->m_StartPosition.Z;
  v9 = (float)(v6 * this->m_Direction.X) + this->m_StartPosition.X;
  v10 = (float)(v7 * this->m_Direction.Y) + this->m_StartPosition.Y;
  if ( m_pItems != &m_pItems[this->m_PBIsList.m_uLength] )
  {
    do
    {
      m_p3DSound = (*m_pItems)->m_p3DSound;
      if ( (*((_BYTE *)&m_p3DSound->m_Params + 68) & 4) == 0 )
      {
        m_p3DSound->m_Params.m_Position.X = v9;
        m_p3DSound->m_Params.m_Position.Y = v10;
        m_p3DSound->m_Params.m_Position.Z = v8;
      }
      ++m_pItems;
    }
    while ( m_pItems != &this->m_PBIsList.m_pItems[this->m_PBIsList.m_uLength] );
  }
  if ( in_CurrentBufferTick >= this->m_EndTime )
    CAkPath::NextVertex(this);
}

// File Line: 328
// RVA: 0xA86AD0
__int64 __fastcall CAkPath::SetPathsList(
        CAkPath *this,
        AkPathListItem *in_pPathList,
        unsigned int in_ulListSize,
        AkPathMode in_PathMode,
        bool in_bIsLooping,
        AkPathState *in_pState)
{
  char v6; // bp
  unsigned int v8; // esi
  bool *pbPlayed; // rcx
  __int64 ulCurrentListIndex_low; // rax
  unsigned int v11; // edi
  bool *v12; // rcx

  v6 = in_PathMode;
  v8 = 2;
  if ( this->m_eState == NotRunning )
  {
    this->m_pPathsList = in_pPathList;
    this->m_ulListSize = in_ulListSize;
    this->m_bIsLooping = in_bIsLooping;
    this->m_PathMode = in_PathMode;
    pbPlayed = in_pState->pbPlayed;
    if ( pbPlayed )
    {
      this->m_pbPlayed = pbPlayed;
      ulCurrentListIndex_low = LOWORD(in_pState->ulCurrentListIndex);
      this->m_ulCurrentListIndex = ulCurrentListIndex_low;
      this->m_pCurrentList = &in_pPathList[ulCurrentListIndex_low];
      return 1;
    }
    this->m_pCurrentList = in_pPathList;
    v11 = 0;
    this->m_ulCurrentListIndex = 0;
    v12 = (bool *)AK::MemoryMgr::Malloc(g_DefaultPoolId, in_ulListSize);
    this->m_pbPlayed = v12;
    if ( v12 )
    {
      if ( this->m_ulListSize )
      {
        do
        {
          *v12 = 0;
          ++v11;
          ++v12;
        }
        while ( v11 < this->m_ulListSize );
      }
      if ( (v6 & 1) != 0 )
        CAkPath::PickRandomList(this);
      return 1;
    }
  }
  return v8;
}

// File Line: 384
// RVA: 0xA86600
__int64 __fastcall CAkPath::GetNextPathList(CAkPath *this)
{
  AkPathListItem *m_pCurrentList; // r8
  AkPathMode m_PathMode; // edx
  bool v4; // cl
  unsigned __int16 v5; // ax

  m_pCurrentList = this->m_pCurrentList;
  if ( !m_pCurrentList )
    return 17i64;
  m_PathMode = this->m_PathMode;
  if ( (m_PathMode & 1) != 0 )
  {
    v4 = CAkPath::PickRandomList(this);
  }
  else
  {
    v5 = ++this->m_ulCurrentListIndex;
    v4 = 0;
    if ( v5 >= this->m_ulListSize )
    {
      if ( (m_PathMode & 2) != 0 )
        this->m_pCurrentList = this->m_pPathsList;
      this->m_ulCurrentListIndex = 0;
      v4 = 1;
    }
    else if ( (m_PathMode & 2) != 0 )
    {
      this->m_pCurrentList = m_pCurrentList + 1;
    }
  }
  if ( (this->m_PathMode & 2) == 0 || v4 && !this->m_bIsLooping )
    return 17i64;
  this->m_uCurrentVertex = 0;
  return 1i64;
}

// File Line: 450
// RVA: 0xA86960
_BOOL8 __fastcall CAkPath::PickRandomList(CAkPath *this)
{
  int m_ulListSize; // r8d
  bool *m_pbPlayed; // rdx
  bool v4; // bl
  bool *v5; // rax
  __int64 v6; // rcx
  unsigned int v7; // ecx
  int v8; // edx
  bool v9; // zf
  bool *v10; // rax

  m_ulListSize = this->m_ulListSize;
  m_pbPlayed = this->m_pbPlayed;
  v4 = 1;
  v5 = m_pbPlayed;
  if ( !this->m_ulListSize )
    goto LABEL_19;
  v6 = this->m_ulListSize;
  do
  {
    v4 = v4 && *v5++;
    --v6;
  }
  while ( v6 );
  if ( v4 )
  {
LABEL_19:
    if ( m_pbPlayed )
    {
      v7 = 0;
      if ( m_ulListSize )
      {
        do
        {
          *m_pbPlayed = 0;
          ++v7;
          ++m_pbPlayed;
        }
        while ( v7 < this->m_ulListSize );
      }
    }
  }
  v8 = rand() % this->m_ulListSize;
  v9 = (this->m_PathMode & 2) == 0;
  this->m_ulCurrentListIndex = v8;
  if ( !v9 )
    this->m_pCurrentList = &this->m_pPathsList[(unsigned __int16)v8];
  v10 = this->m_pbPlayed;
  if ( v10 )
    v10[(unsigned __int16)v8] = 1;
  return v4;
}

// File Line: 504
// RVA: 0xA86BB0
void __fastcall CAkPath::SetSoundUniqueID(CAkPath *this, unsigned int in_soundUniqueID)
{
  this->m_ulSoundUniqueID = in_soundUniqueID;
}

// File Line: 509
// RVA: 0xA86BA0
void __fastcall CAkPath::SetPlayingID(CAkPath *this, unsigned int in_playingID)
{
  this->m_playingID = in_playingID;
}

// File Line: 514
// RVA: 0xA86AC0
void __fastcall CAkPath::SetIsLooping(CAkPath *this, bool in_bIsLooping)
{
  this->m_bIsLooping = in_bIsLooping;
}

// File Line: 519
// RVA: 0xA86F40
void __fastcall CAkPath::UpdateStartPosition(CAkPath *this)
{
  CAkPBI **m_pItems; // rax
  CAkGen3DParams *m_p3DSound; // r8

  m_pItems = this->m_PBIsList.m_pItems;
  if ( m_pItems != &m_pItems[this->m_PBIsList.m_uLength] )
  {
    do
    {
      m_p3DSound = (*m_pItems)->m_p3DSound;
      if ( (*((_BYTE *)&m_p3DSound->m_Params + 68) & 4) == 0 )
        m_p3DSound->m_Params.m_Position = this->m_StartPosition;
      ++m_pItems;
    }
    while ( m_pItems != &this->m_PBIsList.m_pItems[this->m_PBIsList.m_uLength] );
  }
}

// File Line: 529
// RVA: 0xA866A0
__int64 __fastcall CAkPath::InitRotationMatricesForNoFollowMode(CAkPath *this, unsigned int in_uListeners)
{
  unsigned int v2; // ebx
  float *v4; // rdx
  __int64 i; // r8
  float *v7; // rcx

  v2 = in_uListeners;
  if ( !this->m_pNoFollowOrientationRotation )
  {
    v4 = (float *)AK::MemoryMgr::Malloc(
                    g_DefaultPoolId,
                    36i64
                  * (((in_uListeners >> 7) & 1)
                   + ((in_uListeners & 0x40) != 0)
                   + ((in_uListeners & 0x20) != 0)
                   + ((in_uListeners & 0x10) != 0)
                   + ((in_uListeners & 8) != 0)
                   + ((in_uListeners & 4) != 0)
                   + ((in_uListeners & 2) != 0)
                   + (in_uListeners & 1)));
    this->m_pNoFollowOrientationRotation = v4;
    if ( !v4 )
      return 2i64;
    for ( i = 0i64; v2; v2 >>= 1 )
    {
      if ( (v2 & 1) != 0 )
      {
        v7 = (float *)((char *)&unk_14249EFE0 + 144 * i);
        v4 += 9;
        *(v4 - 9) = *v7;
        *(v4 - 8) = v7[3];
        *(v4 - 7) = v7[6];
        *(v4 - 6) = v7[1];
        *(v4 - 5) = v7[4];
        *(v4 - 4) = v7[7];
        *(v4 - 3) = v7[2];
        *(v4 - 2) = v7[5];
        *(v4 - 1) = v7[8];
      }
      i = (unsigned int)(i + 1);
    }
  }
  return 1i64;
}

