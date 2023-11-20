// File Line: 35
// RVA: 0xA865C0
void __fastcall CAkPath::CAkPath(CAkPath *this)
{
  this->m_PBIsList.m_pItems = 0i64;
  *(_QWORD *)&this->m_PBIsList.m_uLength = 0i64;
  this->m_eState = 0;
  this->m_pPathsList = 0i64;
  this->m_pbPlayed = 0i64;
  this->m_pCurrentList = 0i64;
  this->m_ulListSize = 0;
  this->m_PathMode = 0;
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
  CAkPath *v1; // rbx
  CAkPBI **v2; // rdx
  bool *v3; // rdx
  float *v4; // rdx

  v1 = this;
  this->m_eState = 0;
  v2 = this->m_PBIsList.m_pItems;
  if ( v2 )
  {
    this->m_PBIsList.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    v1->m_PBIsList.m_pItems = 0i64;
    v1->m_PBIsList.m_ulReserved = 0;
  }
  if ( v1->m_PathMode & 2 )
  {
    v3 = v1->m_pbPlayed;
    if ( v3 )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, v3);
      v1->m_pbPlayed = 0i64;
    }
  }
  v4 = v1->m_pNoFollowOrientationRotation;
  if ( v4 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v4);
}

// File Line: 88
// RVA: 0xA86BC0
signed __int64 __fastcall CAkPath::Start(CAkPath *this, unsigned int in_CurrentBufferTick)
{
  AkPathListItem *v2; // r8
  signed int v3; // esi
  CAkPath *v4; // rbx
  float *v5; // rcx
  int v6; // eax
  signed int v7; // ecx
  float v8; // xmm8_4
  float v9; // xmm7_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm7_4
  CAkPBI **v15; // rax
  CAkGen3DParams *v16; // rdx
  signed int v17; // ecx
  signed __int64 result; // rax
  float v19; // xmm10_4

  v2 = this->m_pCurrentList;
  v3 = in_CurrentBufferTick;
  v4 = this;
  if ( !v2 )
    return 2i64;
  this->m_bWasStarted = 1;
  if ( v2->iNumVertices <= 0 )
    return 37i64;
  this->m_uCurrentVertex = 0;
  v5 = &v2->pVertices->Vertex.X;
  v4->m_uCurrentVertex = 1;
  v4->m_StartPosition.X = *v5;
  v4->m_StartPosition.Y = v5[1];
  v4->m_StartPosition.Z = v5[2];
  v6 = (AkAudioLibSettings::g_msPerBufferTick + *((_DWORD *)v5 + 3) - 1) / AkAudioLibSettings::g_msPerBufferTick;
  if ( !v6 )
    v6 = 1;
  v4->m_Duration = v6;
  v7 = v2->iNumVertices;
  if ( v7 <= 1 )
  {
    *(_QWORD *)&v4->m_Direction.X = 0i64;
    v4->m_Direction.Z = 0.0;
  }
  else
  {
    v8 = v2->pVertices[1].Vertex.X;
    v9 = v2->pVertices[1].Vertex.Z;
    v10 = v2->pVertices[1].Vertex.Y;
    if ( v8 != v4->m_StartPosition.X || v10 != v4->m_StartPosition.Y || v9 != v4->m_StartPosition.Z || v7 > 2 )
    {
      CAkPath::RandomizePosition(v4, &v4->m_StartPosition);
      v11 = v8 + (float)((float)((float)((float)rand() * 0.000061038882) - 1.0) * v4->m_pCurrentList->fRangeX);
      v12 = v9 + (float)((float)((float)((float)rand() * 0.000061038882) - 1.0) * v4->m_pCurrentList->fRangeY);
    }
    else
    {
      CAkPath::RandomizePosition(v4, &v4->m_StartPosition);
      v11 = v4->m_StartPosition.X;
      v10 = v4->m_StartPosition.Y;
      v12 = v4->m_StartPosition.Z;
    }
    v13 = v10 - v4->m_StartPosition.Y;
    v14 = v12 - v4->m_StartPosition.Z;
    v4->m_Direction.X = v11 - v4->m_StartPosition.X;
    v4->m_Direction.Y = v13;
    v4->m_Direction.Z = v14;
  }
  v15 = v4->m_PBIsList.m_pItems;
  if ( v15 != &v15[v4->m_PBIsList.m_uLength] )
  {
    do
    {
      v16 = (*v15)->m_p3DSound;
      if ( !(*((_BYTE *)&v16->m_Params + 68) & 4) )
      {
        v16->m_Params.m_Position.X = v4->m_StartPosition.X;
        v16->m_Params.m_Position.Y = v4->m_StartPosition.Y;
        v16->m_Params.m_Position.Z = v4->m_StartPosition.Z;
      }
      ++v15;
    }
    while ( v15 != &v4->m_PBIsList.m_pItems[v4->m_PBIsList.m_uLength] );
  }
  v17 = v4->m_Duration;
  v4->m_eState = 1;
  v4->m_StartTime = v3;
  v4->m_EndTime = v17 + v3;
  result = 1i64;
  v19 = 1.0 / (float)v17;
  v4->m_fa = v19;
  LODWORD(v4->m_fb) = COERCE_UNSIGNED_INT((float)v3 * v19) ^ _xmm[0];
  return result;
}

// File Line: 186
// RVA: 0xA86950
void __fastcall CAkPath::Pause(CAkPath *this, unsigned int in_CurrentBufferTick)
{
  this->m_TimePaused = in_CurrentBufferTick;
  this->m_eState = 2;
}

// File Line: 194
// RVA: 0xA86A90
void __fastcall CAkPath::Resume(CAkPath *this, unsigned int in_CurrentBufferTick)
{
  unsigned int v2; // edx
  signed int v3; // eax

  v2 = in_CurrentBufferTick - this->m_TimePaused;
  this->m_eState = 1;
  this->m_StartTime += v2;
  v3 = this->m_StartTime;
  this->m_EndTime += v2;
  LODWORD(this->m_fb) = COERCE_UNSIGNED_INT((float)v3 * this->m_fa) ^ _xmm[0];
}

// File Line: 208
// RVA: 0xA867B0
void __fastcall CAkPath::NextVertex(CAkPath *this)
{
  CAkPath *v1; // rdi
  AkPathListItem *v2; // rcx
  int v3; // eax
  float *v4; // rbx
  int v5; // eax
  AkPathVertex *v6; // rcx
  float v7; // xmm7_4
  float v8; // xmm8_4
  float v9; // xmm9_4
  float v10; // xmm7_4
  signed int v11; // eax
  signed int v12; // edx
  signed int v13; // ecx
  float v14; // xmm8_4
  float v15; // xmm0_4
  float v16; // xmm10_4

  v1 = this;
  v2 = this->m_pCurrentList;
  v3 = v1->m_uCurrentVertex;
  if ( v3 < v2->iNumVertices )
  {
    v4 = &v2->pVertices[v1->m_uCurrentVertex].Vertex.X;
    v1->m_uCurrentVertex = v3 + 1;
    v1->m_StartPosition.X = *v4;
    v1->m_StartPosition.Y = v4[1];
    v1->m_StartPosition.Z = v4[2];
    CAkPath::RandomizePosition(v1, &v1->m_StartPosition);
    v5 = (AkAudioLibSettings::g_msPerBufferTick + *((_DWORD *)v4 + 3) - 1) / AkAudioLibSettings::g_msPerBufferTick;
    if ( !v5 )
      v5 = 1;
    v1->m_Duration = v5;
  }
  if ( v1->m_uCurrentVertex < v1->m_pCurrentList->iNumVertices || (unsigned int)CAkPath::GetNextPathList(v1) == 1 )
  {
    v6 = v1->m_pCurrentList->pVertices;
    v7 = v6[v1->m_uCurrentVertex].Vertex.X;
    v8 = v6[v1->m_uCurrentVertex].Vertex.Y;
    v9 = v6[v1->m_uCurrentVertex].Vertex.Z;
    v10 = v7 + (float)((float)((float)((float)rand() * 0.000061038882) - 1.0) * v1->m_pCurrentList->fRangeX);
    v11 = rand();
    v12 = v1->m_EndTime;
    v13 = v1->m_Duration;
    v14 = v8 - v1->m_StartPosition.Y;
    v15 = (float)((float)((float)v11 * 0.000061038882) - 1.0) * v1->m_pCurrentList->fRangeY;
    v1->m_Direction.X = v10 - v1->m_StartPosition.X;
    v1->m_Direction.Y = v14;
    v1->m_StartTime = v12;
    v1->m_EndTime = v13 + v12;
    v16 = 1.0 / (float)v13;
    v1->m_Direction.Z = (float)(v9 + v15) - v1->m_StartPosition.Z;
    v1->m_fa = v16;
    LODWORD(v1->m_fb) = COERCE_UNSIGNED_INT((float)v12 * v16) ^ _xmm[0];
  }
  else
  {
    v1->m_eState = 0;
  }
}

// File Line: 281
// RVA: 0xA867A0
_BOOL8 __fastcall CAkPath::IsIdle(CAkPath *this)
{
  return this->m_eState == 0;
}

// File Line: 288
// RVA: 0xA86E80
void __fastcall CAkPath::UpdatePosition(CAkPath *this, unsigned int in_CurrentBufferTick)
{
  float v2; // xmm1_4
  unsigned int v3; // er9
  float v4; // xmm0_4
  CAkPBI **v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  CAkGen3DParams *v11; // rdx

  v2 = *(float *)&FLOAT_1_0;
  v3 = in_CurrentBufferTick;
  v4 = (float)((float)(signed int)in_CurrentBufferTick * this->m_fa) + this->m_fb;
  if ( v4 >= 1.0 || (v2 = 0.0, v4 <= 0.0) )
    v4 = v2;
  v5 = this->m_PBIsList.m_pItems;
  v6 = v4;
  v7 = v4;
  v8 = (float)(v4 * this->m_Direction.Z) + this->m_StartPosition.Z;
  v9 = (float)(v6 * this->m_Direction.X) + this->m_StartPosition.X;
  v10 = (float)(v7 * this->m_Direction.Y) + this->m_StartPosition.Y;
  if ( v5 != &v5[this->m_PBIsList.m_uLength] )
  {
    do
    {
      v11 = (*v5)->m_p3DSound;
      if ( !(*((_BYTE *)&v11->m_Params + 68) & 4) )
      {
        v11->m_Params.m_Position.X = v9;
        v11->m_Params.m_Position.Y = v10;
        v11->m_Params.m_Position.Z = v8;
      }
      ++v5;
    }
    while ( v5 != &this->m_PBIsList.m_pItems[this->m_PBIsList.m_uLength] );
  }
  if ( v3 >= this->m_EndTime )
    CAkPath::NextVertex(this);
}

// File Line: 328
// RVA: 0xA86AD0
__int64 __fastcall CAkPath::SetPathsList(CAkPath *this, AkPathListItem *in_pPathList, unsigned int in_ulListSize, AkPathMode in_PathMode, bool in_bIsLooping, AkPathState *in_pState)
{
  char v6; // bp
  CAkPath *v7; // rbx
  unsigned int v8; // esi
  bool *v9; // rcx
  __int64 v10; // rax
  unsigned int v11; // edi
  bool *v12; // rcx

  v6 = in_PathMode;
  v7 = this;
  v8 = 2;
  if ( this->m_eState == NotRunning )
  {
    this->m_pPathsList = in_pPathList;
    this->m_ulListSize = in_ulListSize;
    this->m_bIsLooping = in_bIsLooping;
    this->m_PathMode = in_PathMode;
    v9 = in_pState->pbPlayed;
    if ( v9 )
    {
      v7->m_pbPlayed = v9;
      v10 = LOWORD(in_pState->ulCurrentListIndex);
      v7->m_ulCurrentListIndex = v10;
      v7->m_pCurrentList = &in_pPathList[v10];
      return 1;
    }
    v7->m_pCurrentList = in_pPathList;
    v11 = 0;
    v7->m_ulCurrentListIndex = 0;
    v12 = (bool *)AK::MemoryMgr::Malloc(g_DefaultPoolId, in_ulListSize);
    v7->m_pbPlayed = v12;
    if ( v12 )
    {
      if ( v7->m_ulListSize > 0u )
      {
        do
        {
          *v12 = 0;
          ++v11;
          ++v12;
        }
        while ( v11 < v7->m_ulListSize );
      }
      if ( v6 & 1 )
        CAkPath::PickRandomList(v7);
      return 1;
    }
  }
  return v8;
}

// File Line: 384
// RVA: 0xA86600
signed __int64 __fastcall CAkPath::GetNextPathList(CAkPath *this)
{
  AkPathListItem *v1; // r8
  CAkPath *v2; // rbx
  AkPathMode v3; // edx
  bool v4; // cl
  unsigned __int16 v5; // ax

  v1 = this->m_pCurrentList;
  v2 = this;
  if ( !v1 )
    return 17i64;
  v3 = this->m_PathMode;
  if ( v3 & 1 )
  {
    v4 = CAkPath::PickRandomList(this);
  }
  else
  {
    v5 = ++this->m_ulCurrentListIndex;
    v4 = 0;
    if ( v5 >= v2->m_ulListSize )
    {
      if ( v3 & 2 )
        v2->m_pCurrentList = v2->m_pPathsList;
      v2->m_ulCurrentListIndex = 0;
      v4 = 1;
    }
    else if ( v3 & 2 )
    {
      v2->m_pCurrentList = v1 + 1;
    }
  }
  if ( !(v2->m_PathMode & 2) || v4 && !v2->m_bIsLooping )
    return 17i64;
  v2->m_uCurrentVertex = 0;
  return 1i64;
}

// File Line: 450
// RVA: 0xA86960
_BOOL8 __fastcall CAkPath::PickRandomList(CAkPath *this)
{
  int v1; // er8
  bool *v2; // rdx
  CAkPath *v3; // rdi
  bool v4; // bl
  bool *v5; // rax
  __int64 v6; // rcx
  unsigned int v7; // ecx
  int v8; // edx
  bool v9; // zf
  bool *v10; // rax

  v1 = this->m_ulListSize;
  v2 = this->m_pbPlayed;
  v3 = this;
  v4 = 1;
  v5 = this->m_pbPlayed;
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
    if ( v2 )
    {
      v7 = 0;
      if ( v1 )
      {
        do
        {
          *v2 = 0;
          ++v7;
          ++v2;
        }
        while ( v7 < v3->m_ulListSize );
      }
    }
  }
  v8 = rand() % v3->m_ulListSize;
  v9 = (v3->m_PathMode & 2) == 0;
  v3->m_ulCurrentListIndex = v8;
  if ( !v9 )
    v3->m_pCurrentList = &v3->m_pPathsList[(unsigned __int16)v8];
  v10 = v3->m_pbPlayed;
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
  CAkPBI **v1; // rax
  CAkGen3DParams *v2; // r8

  v1 = this->m_PBIsList.m_pItems;
  if ( v1 != &v1[this->m_PBIsList.m_uLength] )
  {
    do
    {
      v2 = (*v1)->m_p3DSound;
      if ( !(*((_BYTE *)&v2->m_Params + 68) & 4) )
      {
        v2->m_Params.m_Position.X = this->m_StartPosition.X;
        v2->m_Params.m_Position.Y = this->m_StartPosition.Y;
        v2->m_Params.m_Position.Z = this->m_StartPosition.Z;
      }
      ++v1;
    }
    while ( v1 != &this->m_PBIsList.m_pItems[this->m_PBIsList.m_uLength] );
  }
}

// File Line: 529
// RVA: 0xA866A0
signed __int64 __fastcall CAkPath::InitRotationMatricesForNoFollowMode(CAkPath *this, unsigned int in_uListeners)
{
  unsigned int v2; // ebx
  CAkPath *v3; // rdi
  float *v4; // rdx
  __int64 i; // r8
  float *v7; // rcx

  v2 = in_uListeners;
  v3 = this;
  if ( !this->m_pNoFollowOrientationRotation )
  {
    v4 = (float *)AK::MemoryMgr::Malloc(
                    g_DefaultPoolId,
                    36i64
                  * (((in_uListeners >> 7) & 1)
                   + ((in_uListeners >> 6) & 1)
                   + ((in_uListeners >> 5) & 1)
                   + ((in_uListeners >> 4) & 1)
                   + ((in_uListeners >> 3) & 1)
                   + ((in_uListeners >> 2) & 1)
                   + ((in_uListeners >> 1) & 1)
                   + (in_uListeners & 1)));
    v3->m_pNoFollowOrientationRotation = v4;
    if ( !v4 )
      return 2i64;
    for ( i = 0i64; v2; v2 >>= 1 )
    {
      if ( v2 & 1 )
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

