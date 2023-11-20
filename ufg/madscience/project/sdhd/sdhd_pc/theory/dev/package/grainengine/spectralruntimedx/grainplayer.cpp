// File Line: 106
// RVA: 0x15C2C0
void __fastcall SpectralEngineCoreDX::GrainPlayerSource::GrainPlayerSource(SpectralEngineCoreDX::GrainPlayerSource *this)
{
  this->vfptr = (SpectralEngineCoreDX::AudioSourceVtbl *)&SpectralEngineCoreDX::AudioSource::`vftable';
  this->vfptr = (SpectralEngineCoreDX::AudioSourceVtbl *)&SpectralEngineCoreDX::GrainPlayerSource::`vftable';
  this->CurrentlyPlayingGrain.pGrainData = 0i64;
  *(_QWORD *)&this->CurrentlyPlayingGrain.nextSampleIndex = 0i64;
  *(_QWORD *)&this->CurrentlyPlayingGrain.targetFrequency = 0i64;
  this->CurrentlyPlayingGrain.prevIndexOffset = 0;
  *(_QWORD *)&this->CurrentlyPlayingGrain.readSpeed = 1065353216i64;
  this->CrossFadeGrain.pGrainData = 0i64;
  *(_QWORD *)&this->CrossFadeGrain.nextSampleIndex = 0i64;
  *(_QWORD *)&this->CrossFadeGrain.targetFrequency = 0i64;
  this->CrossFadeGrain.prevIndexOffset = 0;
  *(_QWORD *)&this->CrossFadeGrain.readSpeed = 1065353216i64;
  this->pGrainFileHeader = 0i64;
  *(_QWORD *)&this->CurrentFrequency = 0i64;
  *(_QWORD *)&this->CurrentUpdatePercentage = 0i64;
  this->crossFadeDuration = 50;
  this->desiredCrossFadeDuration = 50;
  if ( this->PlayState )
    this->PlayState = 0;
}

// File Line: 123
// RVA: 0x15D260
void __fastcall SpectralEngineCoreDX::GrainPlayerSource::Update(SpectralEngineCoreDX::GrainPlayerSource *this, SpectralEngineCoreDX::SpectralUpdateParameters *updateParams)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm0_4

  v2 = updateParams->Frequency;
  v3 = this->maxFrequency;
  this->DesiredFrequency = v2;
  if ( v2 > v3 )
    this->DesiredFrequency = v3;
  v4 = this->minFrequency;
  if ( v4 > this->DesiredFrequency )
    this->DesiredFrequency = v4;
  v5 = updateParams->UpdatePercentage;
  this->DesiredUpdatePercentage = updateParams->UpdatePercentage;
  if ( v5 > 1.0 )
    this->DesiredUpdatePercentage = 1.0;
  if ( this->DesiredUpdatePercentage < 0.0 )
    this->DesiredUpdatePercentage = 0.0;
  this->desiredCrossFadeDuration = updateParams->CrossFadeDuration;
  this->params.GrainWidth = updateParams->GrainWidth;
  this->params.LinkPlaybackPositionToUpdatePercentage = updateParams->LinkPlaybackPositionToUpdatePercentage;
  this->params.UpdatePercentage = updateParams->UpdatePercentage;
  this->params.Volume = updateParams->Volume;
}

// File Line: 158
// RVA: 0x15CC40
void __fastcall SpectralEngineCoreDX::GrainPlayerSource::Initialize(SpectralEngineCoreDX::GrainPlayerSource *this, GrainFileHeader *_pGrainFileHeader)
{
  GrainHeader *v2; // r8
  SpectralEngineCoreDX::GrainPlayerSource *v3; // r9
  int v4; // eax
  int v5; // er10
  bool v6; // zf
  float v7; // ST10_4
  __int64 v8; // ST08_8
  GrainFileHeader *v9; // r11
  float v10; // ecx
  int v11; // edx
  float v12; // xmm2_4
  float v13; // xmm1_4
  __int64 v14; // rax
  GrainHeader *v15; // rcx
  int v16; // er8
  float v17; // xmm0_4
  float v18; // xmm0_4
  __int64 v19; // [rsp+18h] [rbp-20h]
  __int64 v20; // [rsp+20h] [rbp-18h]

  this->pGrainFileHeader = _pGrainFileHeader;
  v2 = _pGrainFileHeader->pGrains;
  v3 = this;
  v4 = v2->Index;
  v5 = 0;
  v6 = this->PlayState == 1;
  v7 = v2->StartFrequency;
  LODWORD(v20) = (_DWORD)FLOAT_1_0;
  this->CurrentlyPlayingGrain.pGrainData = v2;
  HIDWORD(v8) = v4;
  LODWORD(v19) = 0;
  LODWORD(v8) = 0;
  v9 = _pGrainFileHeader;
  *(_QWORD *)&this->CurrentlyPlayingGrain.nextSampleIndex = v8;
  *(_QWORD *)&this->CurrentlyPlayingGrain.targetFrequency = LODWORD(v7);
  *(_QWORD *)&this->CurrentlyPlayingGrain.prevIndexOffset = v19;
  *(_QWORD *)&this->CurrentlyPlayingGrain.readSpeed = v20;
  this->CurrentFrequency = _pGrainFileHeader->pGrains->StartFrequency;
  v10 = _pGrainFileHeader->pGrains->StartFrequency;
  *(_QWORD *)&v3->CurrentUpdatePercentage = 0i64;
  *(_QWORD *)&v3->minFrequency = 1185669120i64;
  v3->DesiredFrequency = v10;
  if ( !v6 )
    v3->PlayState = 1;
  v11 = _pGrainFileHeader->NumberOfSamples;
  v3->smallestGrainSize = v11;
  if ( v9->NumberOfGrains > 0 )
  {
    v12 = FLOAT_22000_0;
    v13 = 0.0;
    v14 = 0i64;
    do
    {
      v15 = v9->pGrains;
      v16 = v15[v14].SizeOfGrain;
      if ( v16 < v11 )
      {
        v11 = v15[v14].SizeOfGrain;
        v3->smallestGrainSize = v16;
      }
      v17 = v15[v14].EndFrequency;
      if ( v17 < v12 )
      {
        v12 = v15[v14].EndFrequency;
        v3->minFrequency = v17;
      }
      v18 = v15[v14].StartFrequency;
      if ( v18 > v13 )
      {
        v13 = v15[v14].StartFrequency;
        v3->maxFrequency = v18;
      }
      ++v5;
      ++v14;
    }
    while ( v5 < v9->NumberOfGrains );
  }
}

// File Line: 199
// RVA: 0x15D2E0
void __fastcall SpectralEngineCoreDX::GrainPlayerSource::WriteToAudioBuffer(SpectralEngineCoreDX::GrainPlayerSource *this, SpectralEngineCoreDX::AudioBuffer *pBuffer)
{
  bool v2; // zf
  unsigned int v3; // er12
  float *v4; // r14
  signed int v5; // esi
  SpectralEngineCoreDX::AudioBuffer *v6; // r13
  SpectralEngineCoreDX::GrainPlayerSource *v7; // rbx
  __int64 v8; // rcx
  float *v9; // rdi
  bool v10; // al
  char v11; // cl
  __m128 v12; // xmm3
  signed int v13; // ecx
  unsigned int v14; // er9
  int v15; // eax
  int v16; // er8
  GrainFileHeader *v17; // rdx
  SpectralEngineCoreDX::GrainPlayer *v18; // rcx
  char v19; // al
  signed int v20; // edx
  int v21; // eax
  signed __int64 v22; // rcx
  __m128 v23; // xmm1
  signed int v24; // edx
  int v25; // ebp
  int v26; // eax
  int v27; // eax
  unsigned int size; // [rsp+80h] [rbp+8h]
  float *nextToWrite; // [rsp+88h] [rbp+10h]

  v2 = this->PlayState == 0;
  v3 = pBuffer->mMaxFrames;
  v4 = pBuffer->mpBuffer;
  v5 = pBuffer->mMaxFrames;
  size = pBuffer->mMaxFrames;
  nextToWrite = v4;
  v6 = pBuffer;
  v7 = this;
  if ( !v2 )
  {
    if ( !v3 )
    {
LABEL_44:
      v6->uValidFrames = v3;
      return;
    }
    while ( 1 )
    {
      switch ( v7->PlayState )
      {
        case 1:
          v10 = v7->params.LinkPlaybackPositionToUpdatePercentage;
          v11 = 0;
          if ( !v10 )
            goto LABEL_48;
          if ( v7->CurrentUpdatePercentage == v7->DesiredUpdatePercentage )
            v11 = 1;
          if ( !v10 )
          {
LABEL_48:
            if ( v7->DesiredFrequency == v7->CurrentFrequency )
              goto LABEL_47;
          }
          if ( v11 )
          {
LABEL_47:
            v12 = (__m128)COERCE_UNSIGNED_INT((float)(v7->CurrentlyPlayingGrain.pGrainData->SizeOfGrain
                                                    - v7->CurrentlyPlayingGrain.nextSampleIndex));
            v12.m128_f32[0] = (float)(v12.m128_f32[0] * (float)(1.0 / v7->CurrentlyPlayingGrain.readSpeed))
                            - (float)v7->crossFadeDuration;
            if ( v12.m128_f32[0] > (float)(signed int)(float)((float)v7->CurrentlyPlayingGrain.pGrainData->SizeOfGrain
                                                            * (float)(1.0 / v7->CurrentlyPlayingGrain.readSpeed)) )
              v12 = 0i64;
            v13 = (signed int)v12.m128_f32[0];
            if ( (signed int)v12.m128_f32[0] != 0x80000000 && (float)v13 != v12.m128_f32[0] )
              v12.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v12, v12)) & 1 ^ 1) + v13);
            v14 = v5;
            if ( (signed int)v12.m128_f32[0] < v5 )
              v14 = (signed int)v12.m128_f32[0];
            v15 = SpectralEngineCoreDX::GrainPlayerSource::PlaySamplesFromGrain(
                    v7,
                    &v7->CurrentlyPlayingGrain,
                    v4,
                    v14,
                    0);
            v5 -= v15;
            v4 += v15;
            if ( !v5 )
              goto LABEL_44;
            v16 = v7->params.GrainWidth;
            v17 = v7->pGrainFileHeader;
            v7->CrossFadeGrain.pGrainData = v7->CurrentlyPlayingGrain.pGrainData;
            v18 = &v7->CrossFadeGrain;
            *(_QWORD *)&v18->nextSampleIndex = *(_QWORD *)&v7->CurrentlyPlayingGrain.nextSampleIndex;
            *(_QWORD *)&v18->targetFrequency = *(_QWORD *)&v7->CurrentlyPlayingGrain.targetFrequency;
            *(_QWORD *)&v18->prevIndexOffset = *(_QWORD *)&v7->CurrentlyPlayingGrain.prevIndexOffset;
            *(_QWORD *)&v18->readSpeed = *(_QWORD *)&v7->CurrentlyPlayingGrain.readSpeed;
            SpectralEngineCoreDX::GrainPlayer::SelectAdjacentGrainCyclic(&v7->CrossFadeGrain, v17, v16);
LABEL_28:
            if ( v7->PlayState != 2 )
              v7->PlayState = 2;
            v20 = v7->crossFadeDuration;
            v21 = v7->CrossFadeGrain.indexOffset + v7->CrossFadeGrain.initialIndex;
            if ( v21 )
              v22 = (signed __int64)&v7->pGrainFileHeader->pGrains[v21 - 1];
            else
              v22 = (signed __int64)v7->CrossFadeGrain.pGrainData;
            v7->CrossFadeGrain.pGrainData = (GrainHeader *)v22;
            v23 = (__m128)COERCE_UNSIGNED_INT((float)v20);
            v23.m128_f32[0] = v23.m128_f32[0] * v7->CrossFadeGrain.readSpeed;
            v24 = (signed int)v23.m128_f32[0];
            if ( (signed int)v23.m128_f32[0] != 0x80000000 && (float)v24 != v23.m128_f32[0] )
              v23.m128_f32[0] = (float)(v24 - (_mm_movemask_ps(_mm_unpacklo_ps(v23, v23)) & 1));
            v7->CrossFadeGrain.nextSampleIndex = *(unsigned __int16 *)(v22 + 12) - (signed int)v23.m128_f32[0];
LABEL_37:
            if ( v7->PlayState != 3 )
              v7->PlayState = 3;
            v25 = v7->CurrentlyPlayingGrain.nextSampleIndex;
            v26 = SpectralEngineCoreDX::GrainPlayerSource::CrossFade(
                    v7,
                    &v7->CurrentlyPlayingGrain,
                    &v7->CrossFadeGrain,
                    v4,
                    v5);
            v5 -= v26;
            v4 += v26;
            v27 = v7->CurrentlyPlayingGrain.nextSampleIndex;
            size = v5;
            nextToWrite = v4;
            if ( !v27 || v27 < v25 )
            {
              v7->CurrentlyPlayingGrain.pGrainData = v7->CrossFadeGrain.pGrainData;
              *(_QWORD *)&v7->CurrentlyPlayingGrain.nextSampleIndex = *(_QWORD *)&v7->CrossFadeGrain.nextSampleIndex;
              *(_QWORD *)&v7->CurrentlyPlayingGrain.targetFrequency = *(_QWORD *)&v7->CrossFadeGrain.targetFrequency;
              *(_QWORD *)&v7->CurrentlyPlayingGrain.prevIndexOffset = *(_QWORD *)&v7->CrossFadeGrain.prevIndexOffset;
              *(_QWORD *)&v7->CurrentlyPlayingGrain.readSpeed = *(_QWORD *)&v7->CrossFadeGrain.readSpeed;
              v7->CurrentlyPlayingGrain.pGrainData = &v7->pGrainFileHeader->pGrains[v7->CurrentlyPlayingGrain.initialIndex
                                                                                  + v7->CurrentlyPlayingGrain.indexOffset];
              v7->CurrentlyPlayingGrain.nextSampleIndex = 0;
              v7->CrossFadeGrain.pGrainData = 0i64;
              *(_QWORD *)&v7->CrossFadeGrain.nextSampleIndex = 0i64;
              *(_QWORD *)&v7->CrossFadeGrain.targetFrequency = 0i64;
              v7->CrossFadeGrain.prevIndexOffset = 0;
              *(_QWORD *)&v7->CrossFadeGrain.readSpeed = 1065353216i64;
              v2 = v7->PlayState == 1;
              v7->CurrentFrequency = v7->CurrentlyPlayingGrain.targetFrequency;
              v7->CurrentUpdatePercentage = (float)v7->CurrentlyPlayingGrain.pGrainData->OffsetIntoSample
                                          / (float)v7->pGrainFileHeader->NumberOfSamples;
              if ( !v2 )
                v7->PlayState = 1;
            }
            break;
          }
          v19 = SpectralEngineCoreDX::GrainPlayerSource::ChangeCurrentGrain(v7, &nextToWrite, &size);
          v5 = size;
          v4 = nextToWrite;
          if ( v19 )
            goto LABEL_28;
          break;
        case 2:
          goto LABEL_28;
        case 3:
          goto LABEL_37;
      }
      if ( !v5 )
        goto LABEL_44;
    }
  }
  if ( v3 )
  {
    v8 = v3;
    v9 = v4;
    while ( v8 )
    {
      *v9 = 0.0;
      ++v9;
      --v8;
    }
  }
  pBuffer->uValidFrames = v3;
}

// File Line: 327
// RVA: 0x15C3A0
char __fastcall SpectralEngineCoreDX::GrainPlayerSource::ChangeCurrentGrain(SpectralEngineCoreDX::GrainPlayerSource *this, float **nextToWrite, unsigned int *size)
{
  GrainHeader *v3; // rax
  unsigned int *v4; // rsi
  SpectralEngineCoreDX::GrainPlayerSource *v5; // rbx
  float v6; // xmm2_4
  float **v7; // r14
  __m128 v8; // xmm3
  signed int v9; // ecx
  int v10; // eax
  GrainFileHeader *v12; // rsi
  float v13; // xmm2_4
  GrainHeader *v14; // rdx
  signed __int64 v15; // rcx
  GrainFileHeader *v16; // rdx
  float v17; // xmm6_4
  GrainHeader *v18; // rax
  __int64 v19; // rcx
  int v20; // eax
  float v21; // xmm0_4
  __int64 v22; // ST38_8
  GrainHeader *v23; // rax
  int v24; // ecx
  GrainHeader *v25; // r8
  __int64 v26; // [rsp+48h] [rbp-30h]
  __int64 v27; // [rsp+50h] [rbp-28h]

  v3 = this->CurrentlyPlayingGrain.pGrainData;
  v4 = size;
  v5 = this;
  v6 = 1.0 / this->CurrentlyPlayingGrain.readSpeed;
  v7 = nextToWrite;
  v8 = (__m128)COERCE_UNSIGNED_INT((float)(v3->SizeOfGrain - this->CurrentlyPlayingGrain.nextSampleIndex));
  v8.m128_f32[0] = (float)((float)(v3->SizeOfGrain - this->CurrentlyPlayingGrain.nextSampleIndex) * v6)
                 - (float)this->crossFadeDuration;
  if ( v8.m128_f32[0] > (float)(signed int)(float)((float)v3->SizeOfGrain * v6) )
    v8 = 0i64;
  if ( v8.m128_f32[0] >= (float)(signed int)*size )
  {
    v8.m128_f32[0] = (float)(signed int)*size;
  }
  else
  {
    v9 = (signed int)v8.m128_f32[0];
    if ( (signed int)v8.m128_f32[0] != 0x80000000 && (float)v9 != v8.m128_f32[0] )
      v8.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v8, v8)) & 1 ^ 1) + v9);
  }
  v10 = SpectralEngineCoreDX::GrainPlayerSource::PlaySamplesFromGrain(
          v5,
          &v5->CurrentlyPlayingGrain,
          *nextToWrite,
          (signed int)v8.m128_f32[0],
          0);
  *v4 -= v10;
  *v7 += v10;
  if ( !*v4 )
    return 0;
  if ( v5->params.LinkPlaybackPositionToUpdatePercentage )
  {
    v12 = v5->pGrainFileHeader;
    v13 = (float)v5->pGrainFileHeader->NumberOfSamples;
    v14 = SpectralEngineCoreDX::GrainPlayerSource::FindGrain(
            v5,
            (signed int)(float)((float)((float)((float)((float)v5->CurrentlyPlayingGrain.pGrainData->OffsetIntoSample
                                                      / v13)
                                              * 0.69999999)
                                      + (float)(v5->params.UpdatePercentage * 0.30000001))
                              * v13));
    if ( v14->Index == v5->CurrentlyPlayingGrain.initialIndex )
    {
      v15 = (signed __int64)&v5->CrossFadeGrain;
      v16 = v12;
      v5->DesiredUpdatePercentage = v5->CurrentUpdatePercentage;
      *(_QWORD *)v15 = v5->CurrentlyPlayingGrain.pGrainData;
      *(_QWORD *)(v15 + 8) = *(_QWORD *)&v5->CurrentlyPlayingGrain.nextSampleIndex;
      *(_QWORD *)(v15 + 16) = *(_QWORD *)&v5->CurrentlyPlayingGrain.targetFrequency;
      *(_QWORD *)(v15 + 24) = *(_QWORD *)&v5->CurrentlyPlayingGrain.prevIndexOffset;
      *(_QWORD *)(v15 + 32) = *(_QWORD *)&v5->CurrentlyPlayingGrain.readSpeed;
LABEL_19:
      SpectralEngineCoreDX::GrainPlayer::SelectAdjacentGrainCyclic(
        (SpectralEngineCoreDX::GrainPlayer *)v15,
        v16,
        v5->params.GrainWidth);
      goto LABEL_20;
    }
  }
  else
  {
    v17 = v5->DesiredFrequency;
    v18 = SpectralEngineCoreDX::GrainPlayerSource::FindGrainLinearSearch(
            v5,
            (float)((float)(v5->DesiredFrequency - v5->CurrentlyPlayingGrain.targetFrequency) * 0.2)
          + v5->CurrentlyPlayingGrain.targetFrequency);
    v14 = v18;
    v19 = v18->Index;
    if ( (_DWORD)v19 == v5->CurrentlyPlayingGrain.initialIndex )
    {
      if ( (_WORD)v19 && v17 < v18->StartFrequency )
      {
        v14 = &v5->pGrainFileHeader->pGrains[(signed int)v19 - 1];
      }
      else
      {
        v16 = v5->pGrainFileHeader;
        if ( (signed int)v19 >= v16->NumberOfGrains - 1 || (v25 = v16->pGrains, v17 <= v25[v19 + 1].StartFrequency) )
        {
          v15 = (signed __int64)&v5->CrossFadeGrain;
          v5->DesiredFrequency = v5->CurrentFrequency;
          *(_QWORD *)v15 = v5->CurrentlyPlayingGrain.pGrainData;
          *(_QWORD *)(v15 + 8) = *(_QWORD *)&v5->CurrentlyPlayingGrain.nextSampleIndex;
          *(_QWORD *)(v15 + 16) = *(_QWORD *)&v5->CurrentlyPlayingGrain.targetFrequency;
          *(_QWORD *)(v15 + 24) = *(_QWORD *)&v5->CurrentlyPlayingGrain.prevIndexOffset;
          *(_QWORD *)(v15 + 32) = *(_QWORD *)&v5->CurrentlyPlayingGrain.readSpeed;
          goto LABEL_19;
        }
        v14 = &v25[(signed int)v19 + 1];
      }
    }
  }
  v20 = v14->Index;
  v21 = v14->StartFrequency;
  v5->CrossFadeGrain.pGrainData = v14;
  HIDWORD(v22) = v20;
  LODWORD(v26) = 0;
  LODWORD(v22) = 0;
  *(_QWORD *)&v5->CrossFadeGrain.nextSampleIndex = v22;
  v15 = (signed __int64)&v5->CrossFadeGrain;
  *(_QWORD *)(v15 + 16) = LODWORD(v21);
  LODWORD(v27) = 1065353216;
  *(_QWORD *)(v15 + 24) = v26;
  *(_QWORD *)(v15 + 32) = v27;
  v23 = v5->CurrentlyPlayingGrain.pGrainData;
  v5->CrossFadeGrain.readSpeed = 1.0;
  if ( v5->CrossFadeGrain.initialIndex == v23->Index )
  {
    v16 = v5->pGrainFileHeader;
    goto LABEL_19;
  }
LABEL_20:
  v24 = v5->desiredCrossFadeDuration;
  if ( v24 > v5->smallestGrainSize - 50 )
    v24 = v5->smallestGrainSize - 50;
  if ( v24 != v5->crossFadeDuration )
    v5->crossFadeDuration = v24;
  return 1;
}

// File Line: 435
// RVA: 0x15D1D0
void __fastcall SpectralEngineCoreDX::GrainPlayer::SelectAdjacentGrainCyclic(SpectralEngineCoreDX::GrainPlayer *this, GrainFileHeader *pGrainFileHeader, int maxOffset)
{
  SpectralEngineCoreDX::GrainPlayer *v3; // r9
  int v4; // ecx
  GrainFileHeader *v5; // r10
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // er8
  int v10; // er8
  int v11; // ecx
  signed __int64 v12; // rax

  v3 = this;
  v4 = this->indexOffset;
  v5 = pGrainFileHeader;
  v6 = v3->prevIndexOffset;
  if ( v6 == v4 )
  {
LABEL_2:
    v7 = v4 + 1;
    goto LABEL_10;
  }
  if ( v6 < v4 )
  {
    if ( v4 >= maxOffset )
    {
      v7 = maxOffset - 1;
      goto LABEL_10;
    }
    goto LABEL_2;
  }
  if ( v6 <= v4 )
    goto LABEL_11;
  if ( v4 > -maxOffset )
    v7 = v4 - 1;
  else
    v7 = 1 - maxOffset;
LABEL_10:
  v3->indexOffset = v7;
LABEL_11:
  v8 = v3->initialIndex;
  v9 = v3->indexOffset;
  v3->prevIndexOffset = v4;
  v10 = v8 + v9;
  if ( v10 < 0 )
    v3->indexOffset = -v8;
  v11 = v5->NumberOfGrains;
  if ( v10 > v11 - 1 )
    v3->indexOffset = v11 - v8 - 1;
  v12 = (signed __int64)&v5->pGrains[v8 + v3->indexOffset];
  v3->nextSampleIndex = 0;
  v3->pGrainData = (GrainHeader *)v12;
}

// File Line: 519
// RVA: 0x15CD60
__int64 __fastcall SpectralEngineCoreDX::GrainPlayerSource::PlaySamplesFromGrain(SpectralEngineCoreDX::GrainPlayerSource *this, SpectralEngineCoreDX::GrainPlayer *grain, float *nextToWrite, unsigned int size, bool exitOnEnd)
{
  int v5; // esi
  float *v6; // r14
  SpectralEngineCoreDX::GrainPlayerSource *v7; // rbx
  float v8; // xmm2_4
  signed __int64 v9; // r10
  char *v10; // r8
  char *v11; // r9
  unsigned __int64 v12; // rcx
  signed __int64 v13; // rax
  float v14; // xmm0_4
  signed __int64 v15; // rcx
  signed __int64 v16; // rdx
  float v17; // xmm0_4

  v5 = size;
  v6 = nextToWrite;
  v7 = this;
  if ( exitOnEnd )
  {
    v8 = (float)(signed int)size;
    if ( (float)(signed int)(float)((float)(grain->pGrainData->SizeOfGrain - grain->nextSampleIndex)
                                  * (float)(1.0 / grain->readSpeed)) <= (float)(signed int)size )
      v8 = (float)(signed int)(float)((float)(grain->pGrainData->SizeOfGrain - grain->nextSampleIndex)
                                    * (float)(1.0 / grain->readSpeed));
    v5 = (signed int)v8;
  }
  SpectralEngineCoreDX::GrainPlayer::ReadSamples(grain, v5, this->pGrainFileHeader->WaveData, mixBufferA);
  v9 = 0i64;
  if ( v5 >= 4i64 )
  {
    v10 = (char *)((char *)mixBufferA - (char *)v6);
    v11 = (char *)((char *)&mixBufferA[1] - (char *)v6);
    v12 = ((unsigned __int64)(v5 - 4i64) >> 2) + 1;
    v13 = (signed __int64)(v6 + 2);
    v9 = 4 * v12;
    do
    {
      v14 = *(float *)&v10[v13 - 8];
      v13 += 16i64;
      *(float *)(v13 - 24) = v14 * v7->params.Volume;
      *(float *)(v13 - 20) = *(float *)&v11[v13 - 24] * v7->params.Volume;
      *(float *)(v13 - 16) = *(float *)&v10[v13 - 16] * v7->params.Volume;
      *(float *)(v13 - 12) = *(float *)&v11[v13 - 16] * v7->params.Volume;
      --v12;
    }
    while ( v12 );
  }
  if ( v9 < v5 )
  {
    v15 = (signed __int64)&v6[v9];
    v16 = v5 - v9;
    do
    {
      v17 = *(float *)(v15 + (char *)mixBufferA - (char *)v6);
      v15 += 4i64;
      *(float *)(v15 - 4) = v17 * v7->params.Volume;
      --v16;
    }
    while ( v16 );
  }
  return (unsigned int)v5;
}

// File Line: 578
// RVA: 0x15CEB0
void __fastcall SpectralEngineCoreDX::GrainPlayer::ReadSamples(SpectralEngineCoreDX::GrainPlayer *this, int numSamples, float *pWaveDataIn, float *pWaveDataOut)
{
  int v4; // er10
  SpectralEngineCoreDX::GrainPlayer *v5; // rbx
  signed __int64 v6; // r12
  int v7; // edi
  float *v8; // rsi
  float *v9; // r14
  signed __int64 v10; // r11
  signed __int64 v11; // rcx
  __m128 v12; // xmm1
  signed int v13; // er8
  signed __int64 v14; // r9
  GrainHeader *v15; // rdx
  int v16; // er10
  signed __int64 v17; // rax
  signed __int64 v18; // r11
  int v19; // er10
  signed __int64 v20; // rax
  signed __int64 v21; // r11
  int v22; // er10
  signed __int64 v23; // rax
  signed __int64 v24; // r11
  signed __int64 v25; // rax
  GrainHeader *v26; // rdx
  signed __int64 v27; // rax
  signed __int64 v28; // rdx
  char *v29; // rbp
  char *v30; // rsi
  char *v31; // r10
  char *v32; // r11
  unsigned __int64 v33; // r15
  signed __int64 v34; // rcx
  int v35; // xmm0_4
  int v36; // xmm0_4
  int v37; // xmm0_4
  int v38; // xmm0_4
  signed __int64 v39; // rcx
  float *v40; // rcx
  float v41; // xmm0_4
  signed __int64 v42; // rcx
  signed __int64 v43; // rdx
  unsigned __int64 v44; // r8

  v4 = this->nextSampleIndex;
  v5 = this;
  v6 = numSamples;
  v7 = 0;
  v8 = pWaveDataIn;
  v9 = pWaveDataOut;
  v10 = this->nextSampleIndex;
  v11 = 0i64;
  v12 = (__m128)COERCE_UNSIGNED_INT((float)numSamples);
  v12.m128_f32[0] = v12.m128_f32[0] * v5->readSpeed;
  v13 = (signed int)v12.m128_f32[0];
  if ( (signed int)v12.m128_f32[0] != 0x80000000 && (float)v13 != v12.m128_f32[0] )
    v12.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v12, v12)) & 1 ^ 1) + v13);
  v14 = (signed int)v12.m128_f32[0];
  if ( v14 >= 4 )
  {
    v15 = v5->pGrainData;
    do
    {
      v16 = v4 + 1;
      v17 = v10 + v15->OffsetIntoSample;
      v18 = v10 + 1;
      resampleBufferSrc[v11] = v8[v17];
      if ( v16 >= v5->pGrainData->SizeOfGrain )
      {
        v16 = 0;
        v18 = 0i64;
      }
      v19 = v16 + 1;
      v20 = v18 + v5->pGrainData->OffsetIntoSample;
      v21 = v18 + 1;
      resampleBufferSrc[v11 + 1] = v8[v20];
      if ( v19 >= v5->pGrainData->SizeOfGrain )
      {
        v19 = 0;
        v21 = 0i64;
      }
      v22 = v19 + 1;
      v23 = v21 + v5->pGrainData->OffsetIntoSample;
      v24 = v21 + 1;
      resampleBufferSrc[v11 + 2] = v8[v23];
      if ( v22 >= v5->pGrainData->SizeOfGrain )
      {
        v22 = 0;
        v24 = 0i64;
      }
      v4 = v22 + 1;
      v25 = v24 + v5->pGrainData->OffsetIntoSample;
      v10 = v24 + 1;
      resampleBufferSrc[v11 + 3] = v8[v25];
      v15 = v5->pGrainData;
      if ( v4 >= v5->pGrainData->SizeOfGrain )
      {
        v4 = 0;
        v10 = 0i64;
      }
      v11 += 4i64;
    }
    while ( v11 < (signed int)v12.m128_f32[0] - 3i64 );
  }
  if ( v11 < v14 )
  {
    v26 = v5->pGrainData;
    do
    {
      ++v4;
      v27 = v10++ + v26->OffsetIntoSample;
      resampleBufferSrc[v11] = v8[v27];
      v26 = v5->pGrainData;
      if ( v4 >= v5->pGrainData->SizeOfGrain )
      {
        v4 = 0;
        v10 = 0i64;
      }
      ++v11;
    }
    while ( v11 < v14 );
  }
  v5->nextSampleIndex = v4;
  v28 = 0i64;
  if ( v14 >= 4 )
  {
    v29 = (char *)((char *)&resampleBufferSrc[1] - (char *)v9);
    v30 = (char *)((char *)resampleBufferSrc - (char *)v9);
    v31 = (char *)((char *)resampleBufferDst - (char *)v9);
    v32 = (char *)((char *)&resampleBufferDst[1] - (char *)v9);
    v33 = ((unsigned __int64)(v14 - 4) >> 2) + 1;
    v7 = 4 * v33;
    v28 = 4 * v33;
    v34 = (signed __int64)(v9 + 2);
    do
    {
      v35 = *(_DWORD *)&v30[v34 - 8];
      v34 += 16i64;
      *(_DWORD *)&v31[v34 - 24] = v35;
      *(_DWORD *)(v34 - 24) = v35;
      v5->lastSample = *(float *)&v31[v34 - 24];
      v36 = *(_DWORD *)&v29[v34 - 24];
      *(_DWORD *)&v32[v34 - 24] = v36;
      *(_DWORD *)(v34 - 20) = v36;
      v5->lastSample = *(float *)&v32[v34 - 24];
      v37 = *(_DWORD *)&v30[v34 - 16];
      *(_DWORD *)&v31[v34 - 16] = v37;
      *(_DWORD *)(v34 - 16) = v37;
      v5->lastSample = *(float *)&v31[v34 - 16];
      v38 = *(_DWORD *)&v29[v34 - 16];
      *(_DWORD *)&v32[v34 - 16] = v38;
      *(_DWORD *)(v34 - 12) = v38;
      v5->lastSample = *(float *)&v32[v34 - 16];
      --v33;
    }
    while ( v33 );
  }
  if ( v28 < v14 )
  {
    v7 += v14 - v28;
    do
    {
      v39 = (char *)v9 - (char *)resampleBufferDst + 4 * v28++;
      v40 = (float *)((char *)resampleBufferDst + v39);
      v41 = *(float *)((char *)v40 + (char *)resampleBufferSrc - (char *)v9);
      resampleBufferDst[v28 - 1] = v41;
      *v40 = v41;
      v5->lastSample = resampleBufferDst[v28 - 1];
    }
    while ( v28 < v14 );
  }
  v42 = v7;
  if ( v7 < v6 )
  {
    if ( v6 - v7 >= 4 )
    {
      v43 = (signed __int64)&v9[v7 + 2];
      v44 = ((unsigned __int64)(v6 - v7 - 4) >> 2) + 1;
      v42 = v7 + 4 * v44;
      do
      {
        v43 += 16i64;
        *(float *)(v43 - 24) = v5->lastSample;
        *(float *)(v43 - 20) = v5->lastSample;
        *(float *)(v43 - 16) = v5->lastSample;
        *(float *)(v43 - 12) = v5->lastSample;
        --v44;
      }
      while ( v44 );
    }
    for ( ; v42 < v6; v9[v42 - 1] = v5->lastSample )
      ++v42;
  }
}

// File Line: 649
// RVA: 0x15C6B0
__int64 __fastcall SpectralEngineCoreDX::GrainPlayerSource::CrossFade(SpectralEngineCoreDX::GrainPlayerSource *this, SpectralEngineCoreDX::GrainPlayer *outGrain, SpectralEngineCoreDX::GrainPlayer *inGrain, float *nextToWrite, unsigned int size)
{
  int v5; // er11
  SpectralEngineCoreDX::GrainPlayerSource *v6; // rdi
  float *v7; // r14
  SpectralEngineCoreDX::GrainPlayer *v8; // rbp
  float v9; // xmm2_4
  __m128 v10; // xmm6
  float v11; // xmm1_4
  signed int v12; // ecx
  unsigned int v13; // esi
  float v14; // xmm0_4
  signed __int64 v15; // r9
  unsigned int v16; // edx
  signed __int64 v17; // rcx
  signed __int64 v18; // r12
  char *v19; // r10
  char *v20; // r11
  char *v21; // rbx
  char *v22; // rbp
  unsigned __int64 v23; // r15
  unsigned int v24; // er13
  signed __int64 v25; // r8
  __m128i v26; // xmm2
  int v27; // eax
  float v28; // xmm1_4
  __m128i v29; // xmm2
  signed __int64 v30; // r8
  __m128i v31; // xmm1

  v5 = this->crossFadeDuration;
  v6 = this;
  v7 = nextToWrite;
  v8 = inGrain;
  v10 = (__m128)(unsigned int)FLOAT_1_0;
  v9 = (float)((float)((float)this->crossFadeDuration * outGrain->readSpeed) + (float)outGrain->nextSampleIndex)
     - (float)outGrain->pGrainData->SizeOfGrain;
  v10.m128_f32[0] = (float)(1.0 / outGrain->readSpeed) * v9;
  v11 = v10.m128_f32[0];
  v12 = (signed int)v10.m128_f32[0];
  if ( (signed int)v10.m128_f32[0] != 0x80000000 && (float)v12 != v10.m128_f32[0] )
    v11 = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1 ^ 1) + v12);
  v13 = 0;
  if ( (float)(signed int)v9 < 0.0 )
    v10.m128_i32[0] = 0;
  v14 = (float)(signed int)size;
  if ( (float)(v5 - (signed int)v11) <= (float)(signed int)size )
    v14 = (float)(v5 - (signed int)v11);
  SpectralEngineCoreDX::GrainPlayer::ReadSamples(outGrain, (signed int)v14, v6->pGrainFileHeader->WaveData, mixBufferA);
  SpectralEngineCoreDX::GrainPlayer::ReadSamples(v8, (signed int)v14, v6->pGrainFileHeader->WaveData, mixBufferB);
  v15 = (signed int)v14;
  v16 = 0;
  v17 = 0i64;
  v18 = 0i64;
  if ( v15 >= 4 )
  {
    v19 = (char *)((char *)mixBufferA - (char *)v7);
    v20 = (char *)((char *)mixBufferB - (char *)v7);
    v21 = (char *)((char *)&mixBufferA[1] - (char *)v7);
    v22 = (char *)((char *)&mixBufferB[1] - (char *)v7);
    v23 = ((unsigned __int64)((signed int)v14 - 4i64) >> 2) + 1;
    v24 = 2;
    v17 = 4 * v23;
    v25 = (signed __int64)(v7 + 2);
    v13 = 4 * v23;
    v18 = 4 * v23;
    do
    {
      v26 = _mm_cvtsi32_si128(v16);
      v25 += 16i64;
      v16 += 4;
      v26.m128i_i32[0] = (unsigned __int128)_mm_cvtepi32_ps(v26);
      v27 = v24 + 1;
      *(float *)(v25 - 24) = (float)((float)((float)(1.0
                                                   - (float)((float)(*(float *)v26.m128i_i32 + v10.m128_f32[0])
                                                           / (float)v6->crossFadeDuration))
                                           * *(float *)&v19[v25 - 24])
                                   + (float)((float)((float)(*(float *)v26.m128i_i32 + v10.m128_f32[0])
                                                   / (float)v6->crossFadeDuration)
                                           * *(float *)&v20[v25 - 24]))
                           * v6->params.Volume;
      v28 = (float)((float)(1.0
                          - (float)((float)((float)(signed int)(v24 - 1) + v10.m128_f32[0])
                                  / (float)v6->crossFadeDuration))
                  * *(float *)&v21[v25 - 24])
          + (float)((float)((float)((float)(signed int)(v24 - 1) + v10.m128_f32[0]) / (float)v6->crossFadeDuration)
                  * *(float *)&v22[v25 - 24]);
      v29 = _mm_cvtsi32_si128(v24);
      v24 += 4;
      v29.m128i_i32[0] = (unsigned __int128)_mm_cvtepi32_ps(v29);
      *(float *)(v25 - 20) = v28 * v6->params.Volume;
      *(float *)(v25 - 16) = (float)((float)((float)(1.0
                                                   - (float)((float)(*(float *)v29.m128i_i32 + v10.m128_f32[0])
                                                           / (float)v6->crossFadeDuration))
                                           * *(float *)&v19[v25 - 16])
                                   + (float)((float)((float)(*(float *)v29.m128i_i32 + v10.m128_f32[0])
                                                   / (float)v6->crossFadeDuration)
                                           * *(float *)&v20[v25 - 16]))
                           * v6->params.Volume;
      *(float *)(v25 - 12) = (float)((float)((float)(1.0
                                                   - (float)((float)((float)v27 + v10.m128_f32[0])
                                                           / (float)v6->crossFadeDuration))
                                           * *(float *)&v21[v25 - 16])
                                   + (float)((float)((float)((float)v27 + v10.m128_f32[0]) / (float)v6->crossFadeDuration)
                                           * *(float *)&v22[v25 - 16]))
                           * v6->params.Volume;
      --v23;
    }
    while ( v23 );
  }
  if ( v17 < v15 )
  {
    v30 = (signed __int64)&v7[v18];
    v13 += v15 - v17;
    do
    {
      v31 = _mm_cvtsi32_si128(v16);
      ++v17;
      v30 += 4i64;
      ++v16;
      *(float *)v31.m128i_i32 = (float)(COERCE_FLOAT(_mm_cvtepi32_ps(v31)) + v10.m128_f32[0])
                              / (float)v6->crossFadeDuration;
      *(float *)(v30 - 4) = (float)((float)((float)(1.0 - *(float *)v31.m128i_i32) * mixBufferA[v17 - 1])
                                  + (float)(*(float *)v31.m128i_i32 * mixBufferB[v17 - 1]))
                          * v6->params.Volume;
    }
    while ( v17 < v15 );
  }
  return v13;
}

// File Line: 731
// RVA: 0x15C9F0
GrainHeader *__fastcall SpectralEngineCoreDX::GrainPlayerSource::FindGrain(SpectralEngineCoreDX::GrainPlayerSource *this, int sampleOffset)
{
  GrainFileHeader *v2; // rdi
  int v3; // er10
  int v4; // er9
  int v5; // ebp
  int v6; // er8
  GrainHeader *v7; // r11
  __int64 v8; // rdx
  int v9; // ebx
  bool v10; // sf
  unsigned __int8 v11; // of
  GrainHeader *result; // rax

  v2 = this->pGrainFileHeader;
  v3 = 0;
  v4 = sampleOffset;
  v5 = v2->NumberOfGrains;
  v6 = v5 - 1;
  if ( v5 - 1 < 0 )
  {
LABEL_11:
    if ( v3 == v5 )
      return &v2->pGrains[v5 - 1];
    if ( v6 )
      return 0i64;
    return v2->pGrains;
  }
  v7 = v2->pGrains;
  while ( 1 )
  {
    v8 = (v6 + v3) / 2;
    v9 = v7[v8].OffsetIntoSample;
    v11 = __OFSUB__(v9, v4);
    v10 = v9 - v4 < 0;
    if ( v9 <= v4 )
      break;
    if ( v7[v8 - 1].OffsetIntoSample <= v4 )
    {
      v11 = __OFSUB__(v9, v4);
      v10 = v9 - v4 < 0;
      break;
    }
    v6 = v8 - 1;
LABEL_10:
    if ( v3 > v6 )
      goto LABEL_11;
  }
  if ( v10 ^ v11 && v7[(v6 + v3) / 2 - 1].OffsetIntoSample < v4 )
  {
    v3 = v8 + 1;
    goto LABEL_10;
  }
  if ( (_DWORD)v8 )
    result = &v7[(signed int)v8 - 1];
  else
    result = v2->pGrains;
  return result;
}

// File Line: 785
// RVA: 0x15CAC0
GrainHeader *__fastcall SpectralEngineCoreDX::GrainPlayerSource::FindGrainLinearSearch(SpectralEngineCoreDX::GrainPlayerSource *this, float freq)
{
  GrainFileHeader *v2; // rax
  signed __int64 v3; // r10
  GrainHeader *v4; // r11
  signed __int64 v5; // r8
  signed __int64 v6; // rdx
  float v7; // xmm3_4
  float *v8; // rax
  float *v9; // rcx
  unsigned __int64 v10; // r9
  signed __int64 v11; // rcx
  signed __int64 v12; // r8

  v2 = this->pGrainFileHeader;
  v3 = 0i64;
  v4 = v2->pGrains;
  v5 = v2->NumberOfGrains;
  v6 = (signed __int64)v4;
  LODWORD(v7) = COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v4->EndFrequency - v4->StartFrequency) * 0.5)
                                                 + v4->StartFrequency)) & _xmm;
  if ( v5 >= 4 )
  {
    v8 = &v4->StartFrequency;
    v9 = &v4[1].StartFrequency;
    v10 = ((unsigned __int64)(v5 - 4) >> 2) + 1;
    v3 = 4 * v10;
    do
    {
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v8[1] - *v8) * 0.5) + *v8)) & _xmm) < v7 )
      {
        LODWORD(v7) = COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v8[1] - *v8) * 0.5) + *v8)) & _xmm;
        v6 = (signed __int64)(v8 - 1);
      }
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[1] - *v9) * 0.5) + *v9)) & _xmm) < v7 )
      {
        LODWORD(v7) = COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[1] - *v9) * 0.5) + *v9)) & _xmm;
        v6 = (signed __int64)(v8 + 3);
      }
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[5] - v9[4]) * 0.5) + v9[4])) & _xmm) < v7 )
      {
        LODWORD(v7) = COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[5] - v9[4]) * 0.5) + v9[4])) & _xmm;
        v6 = (signed __int64)(v8 + 7);
      }
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[9] - v9[8]) * 0.5) + v9[8])) & _xmm) < v7 )
      {
        LODWORD(v7) = COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[9] - v9[8]) * 0.5) + v9[8])) & _xmm;
        v6 = (signed __int64)(v8 + 11);
      }
      v8 += 16;
      v9 += 16;
      --v10;
    }
    while ( v10 );
  }
  if ( v3 < v5 )
  {
    v11 = (signed __int64)&v4[v3];
    v12 = v5 - v3;
    do
    {
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                          freq
                        - (float)((float)((float)(*(float *)(v11 + 8) - *(float *)(v11 + 4)) * 0.5) + *(float *)(v11 + 4))) & _xmm) < v7 )
      {
        LODWORD(v7) = COERCE_UNSIGNED_INT(
                        freq
                      - (float)((float)((float)(*(float *)(v11 + 8) - *(float *)(v11 + 4)) * 0.5) + *(float *)(v11 + 4))) & _xmm;
        v6 = v11;
      }
      v11 += 16i64;
      --v12;
    }
    while ( v12 );
  }
  return (GrainHeader *)v6;
}

