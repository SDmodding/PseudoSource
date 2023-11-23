// File Line: 106
// RVA: 0x15C2C0
void __fastcall SpectralEngineCoreDX::GrainPlayerSource::GrainPlayerSource(
        SpectralEngineCoreDX::GrainPlayerSource *this)
{
  this->vfptr = (SpectralEngineCoreDX::AudioSourceVtbl *)&SpectralEngineCoreDX::AudioSource::`vftable;
  this->vfptr = (SpectralEngineCoreDX::AudioSourceVtbl *)&SpectralEngineCoreDX::GrainPlayerSource::`vftable;
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
    this->PlayState = Uninitialized;
}

// File Line: 123
// RVA: 0x15D260
void __fastcall SpectralEngineCoreDX::GrainPlayerSource::Update(
        SpectralEngineCoreDX::GrainPlayerSource *this,
        SpectralEngineCoreDX::SpectralUpdateParameters *updateParams)
{
  float Frequency; // xmm0_4
  float maxFrequency; // xmm1_4
  float minFrequency; // xmm0_4
  float UpdatePercentage; // xmm0_4

  Frequency = updateParams->Frequency;
  maxFrequency = this->maxFrequency;
  this->DesiredFrequency = Frequency;
  if ( Frequency > maxFrequency )
    this->DesiredFrequency = maxFrequency;
  minFrequency = this->minFrequency;
  if ( minFrequency > this->DesiredFrequency )
    this->DesiredFrequency = minFrequency;
  UpdatePercentage = updateParams->UpdatePercentage;
  this->DesiredUpdatePercentage = updateParams->UpdatePercentage;
  if ( UpdatePercentage > 1.0 )
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
void __fastcall SpectralEngineCoreDX::GrainPlayerSource::Initialize(
        SpectralEngineCoreDX::GrainPlayerSource *this,
        GrainFileHeader *_pGrainFileHeader)
{
  GrainHeader *pGrains; // r8
  int Index; // eax
  int v5; // r10d
  bool v6; // zf
  float v8; // ecx
  int NumberOfSamples; // edx
  float v10; // xmm2_4
  float v11; // xmm1_4
  __int64 v12; // rax
  GrainHeader *v13; // rcx
  int SizeOfGrain; // r8d
  float EndFrequency; // xmm0_4
  float v16; // xmm0_4
  __int64 v17; // [rsp+8h] [rbp-30h]
  float StartFrequency; // [rsp+10h] [rbp-28h]
  __int64 v19; // [rsp+18h] [rbp-20h]
  __int64 v20; // [rsp+20h] [rbp-18h]

  this->pGrainFileHeader = _pGrainFileHeader;
  pGrains = _pGrainFileHeader->pGrains;
  Index = pGrains->Index;
  v5 = 0;
  v6 = this->PlayState == Playing;
  StartFrequency = pGrains->StartFrequency;
  LODWORD(v20) = (_DWORD)FLOAT_1_0;
  this->CurrentlyPlayingGrain.pGrainData = pGrains;
  HIDWORD(v17) = Index;
  LODWORD(v19) = 0;
  LODWORD(v17) = 0;
  *(_QWORD *)&this->CurrentlyPlayingGrain.nextSampleIndex = v17;
  *(_QWORD *)&this->CurrentlyPlayingGrain.targetFrequency = LODWORD(StartFrequency);
  *(_QWORD *)&this->CurrentlyPlayingGrain.prevIndexOffset = v19;
  *(_QWORD *)&this->CurrentlyPlayingGrain.readSpeed = v20;
  this->CurrentFrequency = _pGrainFileHeader->pGrains->StartFrequency;
  v8 = _pGrainFileHeader->pGrains->StartFrequency;
  *(_QWORD *)&this->CurrentUpdatePercentage = 0i64;
  *(_QWORD *)&this->minFrequency = 1185669120i64;
  this->DesiredFrequency = v8;
  if ( !v6 )
    this->PlayState = Playing;
  NumberOfSamples = _pGrainFileHeader->NumberOfSamples;
  this->smallestGrainSize = NumberOfSamples;
  if ( _pGrainFileHeader->NumberOfGrains > 0 )
  {
    v10 = FLOAT_22000_0;
    v11 = 0.0;
    v12 = 0i64;
    do
    {
      v13 = _pGrainFileHeader->pGrains;
      SizeOfGrain = v13[v12].SizeOfGrain;
      if ( SizeOfGrain < NumberOfSamples )
      {
        NumberOfSamples = v13[v12].SizeOfGrain;
        this->smallestGrainSize = SizeOfGrain;
      }
      EndFrequency = v13[v12].EndFrequency;
      if ( EndFrequency < v10 )
      {
        v10 = v13[v12].EndFrequency;
        this->minFrequency = EndFrequency;
      }
      v16 = v13[v12].StartFrequency;
      if ( v16 > v11 )
      {
        v11 = v13[v12].StartFrequency;
        this->maxFrequency = v16;
      }
      ++v5;
      ++v12;
    }
    while ( v5 < _pGrainFileHeader->NumberOfGrains );
  }
}

// File Line: 199
// RVA: 0x15D2E0
void __fastcall SpectralEngineCoreDX::GrainPlayerSource::WriteToAudioBuffer(
        SpectralEngineCoreDX::GrainPlayerSource *this,
        SpectralEngineCoreDX::AudioBuffer *pBuffer)
{
  bool v2; // zf
  unsigned int mMaxFrames; // r12d
  float *mpBuffer; // r14
  int v5; // esi
  __int64 v8; // rcx
  float *v9; // rdi
  char v10; // cl
  __m128 v11; // xmm3
  int v12; // ecx
  int v13; // r9d
  int v14; // eax
  int GrainWidth; // r8d
  GrainFileHeader *pGrainFileHeader; // rdx
  char v17; // al
  int crossFadeDuration; // edx
  int v19; // eax
  GrainHeader *pGrainData; // rcx
  __m128 v21; // xmm1
  int v22; // edx
  int nextSampleIndex; // ebp
  int v24; // eax
  int v25; // eax
  unsigned int size; // [rsp+80h] [rbp+8h] BYREF
  float *nextToWrite; // [rsp+88h] [rbp+10h] BYREF

  v2 = this->PlayState == Uninitialized;
  mMaxFrames = pBuffer->mMaxFrames;
  mpBuffer = pBuffer->mpBuffer;
  v5 = mMaxFrames;
  size = mMaxFrames;
  nextToWrite = mpBuffer;
  if ( !v2 )
  {
    if ( !mMaxFrames )
    {
LABEL_44:
      pBuffer->uValidFrames = mMaxFrames;
      return;
    }
    while ( 1 )
    {
      switch ( this->PlayState )
      {
        case Playing:
          v10 = 0;
          if ( this->params.LinkPlaybackPositionToUpdatePercentage )
          {
            if ( this->CurrentUpdatePercentage == this->DesiredUpdatePercentage )
              v10 = 1;
          }
          else if ( this->DesiredFrequency == this->CurrentFrequency )
          {
            goto LABEL_18;
          }
          if ( v10 )
          {
LABEL_18:
            v11 = (__m128)COERCE_UNSIGNED_INT((float)(this->CurrentlyPlayingGrain.pGrainData->SizeOfGrain
                                                    - this->CurrentlyPlayingGrain.nextSampleIndex));
            v11.m128_f32[0] = (float)(v11.m128_f32[0] * (float)(1.0 / this->CurrentlyPlayingGrain.readSpeed))
                            - (float)this->crossFadeDuration;
            if ( v11.m128_f32[0] > (float)(int)(float)((float)this->CurrentlyPlayingGrain.pGrainData->SizeOfGrain
                                                     * (float)(1.0 / this->CurrentlyPlayingGrain.readSpeed)) )
              v11 = 0i64;
            v12 = (int)v11.m128_f32[0];
            if ( (int)v11.m128_f32[0] != 0x80000000 && (float)v12 != v11.m128_f32[0] )
              v11.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v11, v11)) & 1) + v12);
            v13 = v5;
            if ( (int)v11.m128_f32[0] < v5 )
              v13 = (int)v11.m128_f32[0];
            v14 = SpectralEngineCoreDX::GrainPlayerSource::PlaySamplesFromGrain(
                    this,
                    &this->CurrentlyPlayingGrain,
                    mpBuffer,
                    v13,
                    0);
            v5 -= v14;
            mpBuffer += v14;
            if ( !v5 )
              goto LABEL_44;
            GrainWidth = this->params.GrainWidth;
            pGrainFileHeader = this->pGrainFileHeader;
            this->CrossFadeGrain.pGrainData = this->CurrentlyPlayingGrain.pGrainData;
            *(_QWORD *)&this->CrossFadeGrain.nextSampleIndex = *(_QWORD *)&this->CurrentlyPlayingGrain.nextSampleIndex;
            *(_QWORD *)&this->CrossFadeGrain.targetFrequency = *(_QWORD *)&this->CurrentlyPlayingGrain.targetFrequency;
            *(_QWORD *)&this->CrossFadeGrain.prevIndexOffset = *(_QWORD *)&this->CurrentlyPlayingGrain.prevIndexOffset;
            *(_QWORD *)&this->CrossFadeGrain.readSpeed = *(_QWORD *)&this->CurrentlyPlayingGrain.readSpeed;
            SpectralEngineCoreDX::GrainPlayer::SelectAdjacentGrainCyclic(
              &this->CrossFadeGrain,
              pGrainFileHeader,
              GrainWidth);
LABEL_28:
            if ( this->PlayState != SetupCrossfading )
              this->PlayState = SetupCrossfading;
            crossFadeDuration = this->crossFadeDuration;
            v19 = this->CrossFadeGrain.indexOffset + this->CrossFadeGrain.initialIndex;
            if ( v19 )
              pGrainData = &this->pGrainFileHeader->pGrains[v19 - 1];
            else
              pGrainData = this->CrossFadeGrain.pGrainData;
            this->CrossFadeGrain.pGrainData = pGrainData;
            v21 = (__m128)COERCE_UNSIGNED_INT((float)crossFadeDuration);
            v21.m128_f32[0] = v21.m128_f32[0] * this->CrossFadeGrain.readSpeed;
            v22 = (int)v21.m128_f32[0];
            if ( (int)v21.m128_f32[0] != 0x80000000 && (float)v22 != v21.m128_f32[0] )
              v21.m128_f32[0] = (float)(v22 - (_mm_movemask_ps(_mm_unpacklo_ps(v21, v21)) & 1));
            this->CrossFadeGrain.nextSampleIndex = pGrainData->SizeOfGrain - (int)v21.m128_f32[0];
LABEL_37:
            if ( this->PlayState != Crossfading )
              this->PlayState = Crossfading;
            nextSampleIndex = this->CurrentlyPlayingGrain.nextSampleIndex;
            v24 = SpectralEngineCoreDX::GrainPlayerSource::CrossFade(
                    this,
                    &this->CurrentlyPlayingGrain,
                    &this->CrossFadeGrain,
                    mpBuffer,
                    v5);
            v5 -= v24;
            mpBuffer += v24;
            v25 = this->CurrentlyPlayingGrain.nextSampleIndex;
            size = v5;
            nextToWrite = mpBuffer;
            if ( !v25 || v25 < nextSampleIndex )
            {
              this->CurrentlyPlayingGrain.pGrainData = this->CrossFadeGrain.pGrainData;
              *(_QWORD *)&this->CurrentlyPlayingGrain.nextSampleIndex = *(_QWORD *)&this->CrossFadeGrain.nextSampleIndex;
              *(_QWORD *)&this->CurrentlyPlayingGrain.targetFrequency = *(_QWORD *)&this->CrossFadeGrain.targetFrequency;
              *(_QWORD *)&this->CurrentlyPlayingGrain.prevIndexOffset = *(_QWORD *)&this->CrossFadeGrain.prevIndexOffset;
              *(_QWORD *)&this->CurrentlyPlayingGrain.readSpeed = *(_QWORD *)&this->CrossFadeGrain.readSpeed;
              this->CurrentlyPlayingGrain.pGrainData = &this->pGrainFileHeader->pGrains[this->CurrentlyPlayingGrain.initialIndex
                                                                                      + this->CurrentlyPlayingGrain.indexOffset];
              this->CurrentlyPlayingGrain.nextSampleIndex = 0;
              this->CrossFadeGrain.pGrainData = 0i64;
              *(_QWORD *)&this->CrossFadeGrain.nextSampleIndex = 0i64;
              *(_QWORD *)&this->CrossFadeGrain.targetFrequency = 0i64;
              this->CrossFadeGrain.prevIndexOffset = 0;
              *(_QWORD *)&this->CrossFadeGrain.readSpeed = 1065353216i64;
              v2 = this->PlayState == Playing;
              this->CurrentFrequency = this->CurrentlyPlayingGrain.targetFrequency;
              this->CurrentUpdatePercentage = (float)this->CurrentlyPlayingGrain.pGrainData->OffsetIntoSample
                                            / (float)this->pGrainFileHeader->NumberOfSamples;
              if ( !v2 )
                this->PlayState = Playing;
            }
            break;
          }
          v17 = SpectralEngineCoreDX::GrainPlayerSource::ChangeCurrentGrain(this, &nextToWrite, &size);
          v5 = size;
          mpBuffer = nextToWrite;
          if ( v17 )
            goto LABEL_28;
          break;
        case SetupCrossfading:
          goto LABEL_28;
        case Crossfading:
          goto LABEL_37;
      }
      if ( !v5 )
        goto LABEL_44;
    }
  }
  if ( mMaxFrames )
  {
    v8 = mMaxFrames;
    v9 = mpBuffer;
    while ( v8 )
    {
      *v9++ = 0.0;
      --v8;
    }
  }
  pBuffer->uValidFrames = mMaxFrames;
}

// File Line: 327
// RVA: 0x15C3A0
char __fastcall SpectralEngineCoreDX::GrainPlayerSource::ChangeCurrentGrain(
        SpectralEngineCoreDX::GrainPlayerSource *this,
        float **nextToWrite,
        unsigned int *size)
{
  GrainHeader *pGrainData; // rax
  float v6; // xmm2_4
  __m128 v8; // xmm3
  int v9; // ecx
  int v10; // eax
  GrainFileHeader *pGrainFileHeader; // rsi
  GrainHeader *Grain; // rdx
  SpectralEngineCoreDX::GrainPlayer *p_CrossFadeGrain; // rcx
  GrainFileHeader *v15; // rdx
  float DesiredFrequency; // xmm6_4
  GrainHeader *GrainLinearSearch; // rax
  __int64 Index; // rcx
  int v19; // eax
  float StartFrequency; // xmm0_4
  GrainHeader *v21; // rax
  int desiredCrossFadeDuration; // ecx
  GrainHeader *pGrains; // r8
  __int64 v24; // [rsp+38h] [rbp-40h]
  __int64 v25; // [rsp+48h] [rbp-30h]
  __int64 v26; // [rsp+50h] [rbp-28h]

  pGrainData = this->CurrentlyPlayingGrain.pGrainData;
  v6 = 1.0 / this->CurrentlyPlayingGrain.readSpeed;
  v8 = (__m128)COERCE_UNSIGNED_INT((float)(pGrainData->SizeOfGrain - this->CurrentlyPlayingGrain.nextSampleIndex));
  v8.m128_f32[0] = (float)((float)(pGrainData->SizeOfGrain - this->CurrentlyPlayingGrain.nextSampleIndex) * v6)
                 - (float)this->crossFadeDuration;
  if ( v8.m128_f32[0] > (float)(int)(float)((float)pGrainData->SizeOfGrain * v6) )
    v8 = 0i64;
  if ( v8.m128_f32[0] >= (float)(int)*size )
  {
    v8.m128_f32[0] = (float)(int)*size;
  }
  else
  {
    v9 = (int)v8.m128_f32[0];
    if ( (int)v8.m128_f32[0] != 0x80000000 && (float)v9 != v8.m128_f32[0] )
      v8.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v8, v8)) & 1) + v9);
  }
  v10 = SpectralEngineCoreDX::GrainPlayerSource::PlaySamplesFromGrain(
          this,
          &this->CurrentlyPlayingGrain,
          *nextToWrite,
          (int)v8.m128_f32[0],
          0);
  *size -= v10;
  *nextToWrite += v10;
  if ( !*size )
    return 0;
  if ( this->params.LinkPlaybackPositionToUpdatePercentage )
  {
    pGrainFileHeader = this->pGrainFileHeader;
    Grain = SpectralEngineCoreDX::GrainPlayerSource::FindGrain(
              this,
              (int)(float)((float)((float)((float)((float)this->CurrentlyPlayingGrain.pGrainData->OffsetIntoSample
                                                 / (float)pGrainFileHeader->NumberOfSamples)
                                         * 0.69999999)
                                 + (float)(this->params.UpdatePercentage * 0.30000001))
                         * (float)pGrainFileHeader->NumberOfSamples));
    if ( Grain->Index == this->CurrentlyPlayingGrain.initialIndex )
    {
      p_CrossFadeGrain = &this->CrossFadeGrain;
      v15 = pGrainFileHeader;
      this->DesiredUpdatePercentage = this->CurrentUpdatePercentage;
      this->CrossFadeGrain.pGrainData = this->CurrentlyPlayingGrain.pGrainData;
      *(_QWORD *)&this->CrossFadeGrain.nextSampleIndex = *(_QWORD *)&this->CurrentlyPlayingGrain.nextSampleIndex;
      *(_QWORD *)&this->CrossFadeGrain.targetFrequency = *(_QWORD *)&this->CurrentlyPlayingGrain.targetFrequency;
      *(_QWORD *)&this->CrossFadeGrain.prevIndexOffset = *(_QWORD *)&this->CurrentlyPlayingGrain.prevIndexOffset;
      *(_QWORD *)&this->CrossFadeGrain.readSpeed = *(_QWORD *)&this->CurrentlyPlayingGrain.readSpeed;
LABEL_19:
      SpectralEngineCoreDX::GrainPlayer::SelectAdjacentGrainCyclic(p_CrossFadeGrain, v15, this->params.GrainWidth);
      goto LABEL_20;
    }
  }
  else
  {
    DesiredFrequency = this->DesiredFrequency;
    GrainLinearSearch = SpectralEngineCoreDX::GrainPlayerSource::FindGrainLinearSearch(
                          this,
                          (float)((float)(DesiredFrequency - this->CurrentlyPlayingGrain.targetFrequency) * 0.2)
                        + this->CurrentlyPlayingGrain.targetFrequency);
    Grain = GrainLinearSearch;
    Index = GrainLinearSearch->Index;
    if ( (_DWORD)Index == this->CurrentlyPlayingGrain.initialIndex )
    {
      if ( (_WORD)Index && DesiredFrequency < GrainLinearSearch->StartFrequency )
      {
        Grain = &this->pGrainFileHeader->pGrains[(int)Index - 1];
      }
      else
      {
        v15 = this->pGrainFileHeader;
        if ( (int)Index >= v15->NumberOfGrains - 1
          || (pGrains = v15->pGrains, DesiredFrequency <= pGrains[Index + 1].StartFrequency) )
        {
          p_CrossFadeGrain = &this->CrossFadeGrain;
          this->DesiredFrequency = this->CurrentFrequency;
          this->CrossFadeGrain.pGrainData = this->CurrentlyPlayingGrain.pGrainData;
          *(_QWORD *)&this->CrossFadeGrain.nextSampleIndex = *(_QWORD *)&this->CurrentlyPlayingGrain.nextSampleIndex;
          *(_QWORD *)&this->CrossFadeGrain.targetFrequency = *(_QWORD *)&this->CurrentlyPlayingGrain.targetFrequency;
          *(_QWORD *)&this->CrossFadeGrain.prevIndexOffset = *(_QWORD *)&this->CurrentlyPlayingGrain.prevIndexOffset;
          *(_QWORD *)&this->CrossFadeGrain.readSpeed = *(_QWORD *)&this->CurrentlyPlayingGrain.readSpeed;
          goto LABEL_19;
        }
        Grain = &pGrains[(int)Index + 1];
      }
    }
  }
  v19 = Grain->Index;
  StartFrequency = Grain->StartFrequency;
  this->CrossFadeGrain.pGrainData = Grain;
  HIDWORD(v24) = v19;
  LODWORD(v25) = 0;
  LODWORD(v24) = 0;
  *(_QWORD *)&this->CrossFadeGrain.nextSampleIndex = v24;
  p_CrossFadeGrain = &this->CrossFadeGrain;
  *(_QWORD *)&this->CrossFadeGrain.targetFrequency = LODWORD(StartFrequency);
  LODWORD(v26) = 1065353216;
  *(_QWORD *)&this->CrossFadeGrain.prevIndexOffset = v25;
  *(_QWORD *)&this->CrossFadeGrain.readSpeed = v26;
  v21 = this->CurrentlyPlayingGrain.pGrainData;
  this->CrossFadeGrain.readSpeed = 1.0;
  if ( this->CrossFadeGrain.initialIndex == v21->Index )
  {
    v15 = this->pGrainFileHeader;
    goto LABEL_19;
  }
LABEL_20:
  desiredCrossFadeDuration = this->desiredCrossFadeDuration;
  if ( desiredCrossFadeDuration > this->smallestGrainSize - 50 )
    desiredCrossFadeDuration = this->smallestGrainSize - 50;
  if ( desiredCrossFadeDuration != this->crossFadeDuration )
    this->crossFadeDuration = desiredCrossFadeDuration;
  return 1;
}

// File Line: 435
// RVA: 0x15D1D0
void __fastcall SpectralEngineCoreDX::GrainPlayer::SelectAdjacentGrainCyclic(
        SpectralEngineCoreDX::GrainPlayer *this,
        GrainFileHeader *pGrainFileHeader,
        int maxOffset)
{
  int indexOffset; // ecx
  int prevIndexOffset; // eax
  int v7; // eax
  int initialIndex; // edx
  int v9; // r8d
  int v10; // r8d
  int NumberOfGrains; // ecx
  GrainHeader *v12; // rax

  indexOffset = this->indexOffset;
  prevIndexOffset = this->prevIndexOffset;
  if ( prevIndexOffset == indexOffset )
  {
LABEL_2:
    v7 = indexOffset + 1;
    goto LABEL_10;
  }
  if ( prevIndexOffset < indexOffset )
  {
    if ( indexOffset >= maxOffset )
    {
      v7 = maxOffset - 1;
      goto LABEL_10;
    }
    goto LABEL_2;
  }
  if ( prevIndexOffset <= indexOffset )
    goto LABEL_11;
  if ( indexOffset > -maxOffset )
    v7 = indexOffset - 1;
  else
    v7 = 1 - maxOffset;
LABEL_10:
  this->indexOffset = v7;
LABEL_11:
  initialIndex = this->initialIndex;
  v9 = this->indexOffset;
  this->prevIndexOffset = indexOffset;
  v10 = initialIndex + v9;
  if ( v10 < 0 )
    this->indexOffset = -initialIndex;
  NumberOfGrains = pGrainFileHeader->NumberOfGrains;
  if ( v10 > NumberOfGrains - 1 )
    this->indexOffset = NumberOfGrains - initialIndex - 1;
  v12 = &pGrainFileHeader->pGrains[initialIndex + this->indexOffset];
  this->nextSampleIndex = 0;
  this->pGrainData = v12;
}

// File Line: 519
// RVA: 0x15CD60
__int64 __fastcall SpectralEngineCoreDX::GrainPlayerSource::PlaySamplesFromGrain(
        SpectralEngineCoreDX::GrainPlayerSource *this,
        SpectralEngineCoreDX::GrainPlayer *grain,
        float *nextToWrite,
        int size,
        bool exitOnEnd)
{
  int v5; // esi
  float v8; // xmm2_4
  __int64 v9; // r10
  signed __int64 v10; // r8
  signed __int64 v11; // r9
  unsigned __int64 v12; // rcx
  float *v13; // rax
  float v14; // xmm0_4
  float *v15; // rcx
  __int64 v16; // rdx
  float v17; // xmm0_4

  v5 = size;
  if ( exitOnEnd )
  {
    v8 = (float)size;
    if ( (float)(int)(float)((float)(grain->pGrainData->SizeOfGrain - grain->nextSampleIndex)
                           * (float)(1.0 / grain->readSpeed)) <= (float)size )
      v8 = (float)(int)(float)((float)(grain->pGrainData->SizeOfGrain - grain->nextSampleIndex)
                             * (float)(1.0 / grain->readSpeed));
    v5 = (int)v8;
  }
  SpectralEngineCoreDX::GrainPlayer::ReadSamples(grain, v5, this->pGrainFileHeader->WaveData, mixBufferA);
  v9 = 0i64;
  if ( v5 >= 4i64 )
  {
    v10 = (char *)mixBufferA - (char *)nextToWrite;
    v11 = (char *)&mixBufferA[1] - (char *)nextToWrite;
    v12 = ((unsigned __int64)(v5 - 4i64) >> 2) + 1;
    v13 = nextToWrite + 2;
    v9 = 4 * v12;
    do
    {
      v14 = *(float *)((char *)v13 + v10 - 8);
      v13 += 4;
      *(v13 - 6) = v14 * this->params.Volume;
      *(v13 - 5) = *(float *)((char *)v13 + v11 - 24) * this->params.Volume;
      *(v13 - 4) = *(float *)((char *)v13 + v10 - 16) * this->params.Volume;
      *(v13 - 3) = *(float *)((char *)v13 + v11 - 16) * this->params.Volume;
      --v12;
    }
    while ( v12 );
  }
  if ( v9 < v5 )
  {
    v15 = &nextToWrite[v9];
    v16 = v5 - v9;
    do
    {
      v17 = *(float *)((char *)v15++ + (char *)mixBufferA - (char *)nextToWrite);
      *(v15 - 1) = v17 * this->params.Volume;
      --v16;
    }
    while ( v16 );
  }
  return (unsigned int)v5;
}

// File Line: 578
// RVA: 0x15CEB0
void __fastcall SpectralEngineCoreDX::GrainPlayer::ReadSamples(
        SpectralEngineCoreDX::GrainPlayer *this,
        int numSamples,
        float *pWaveDataIn,
        float *pWaveDataOut)
{
  int nextSampleIndex; // r10d
  __int64 v6; // r12
  int v7; // edi
  __int64 v10; // r11
  __int64 v11; // rcx
  __m128 v12; // xmm1
  int v13; // r8d
  __int64 v14; // r9
  GrainHeader *pGrainData; // rdx
  int v16; // r10d
  __int64 v17; // rax
  __int64 v18; // r11
  int v19; // r10d
  __int64 v20; // rax
  __int64 v21; // r11
  int v22; // r10d
  __int64 v23; // rax
  __int64 v24; // r11
  __int64 v25; // rax
  GrainHeader *v26; // rdx
  __int64 v27; // rax
  __int64 v28; // rdx
  signed __int64 v29; // rbp
  signed __int64 v30; // rsi
  signed __int64 v31; // r10
  signed __int64 v32; // r11
  unsigned __int64 v33; // r15
  float *v34; // rcx
  int v35; // xmm0_4
  int v36; // xmm0_4
  int v37; // xmm0_4
  int v38; // xmm0_4
  signed __int64 v39; // rcx
  float *v40; // rcx
  float v41; // xmm0_4
  __int64 v42; // rcx
  float *v43; // rdx
  unsigned __int64 v44; // r8

  nextSampleIndex = this->nextSampleIndex;
  v6 = numSamples;
  v7 = 0;
  v10 = nextSampleIndex;
  v11 = 0i64;
  v12 = (__m128)COERCE_UNSIGNED_INT((float)numSamples);
  v12.m128_f32[0] = v12.m128_f32[0] * this->readSpeed;
  v13 = (int)v12.m128_f32[0];
  if ( (int)v12.m128_f32[0] != 0x80000000 && (float)v13 != v12.m128_f32[0] )
    v12.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v12, v12)) & 1) + v13);
  v14 = (int)v12.m128_f32[0];
  if ( v14 >= 4 )
  {
    pGrainData = this->pGrainData;
    do
    {
      v16 = nextSampleIndex + 1;
      v17 = v10 + pGrainData->OffsetIntoSample;
      v18 = v10 + 1;
      resampleBufferSrc[v11] = pWaveDataIn[v17];
      if ( v16 >= this->pGrainData->SizeOfGrain )
      {
        v16 = 0;
        v18 = 0i64;
      }
      v19 = v16 + 1;
      v20 = v18 + this->pGrainData->OffsetIntoSample;
      v21 = v18 + 1;
      resampleBufferSrc[v11 + 1] = pWaveDataIn[v20];
      if ( v19 >= this->pGrainData->SizeOfGrain )
      {
        v19 = 0;
        v21 = 0i64;
      }
      v22 = v19 + 1;
      v23 = v21 + this->pGrainData->OffsetIntoSample;
      v24 = v21 + 1;
      resampleBufferSrc[v11 + 2] = pWaveDataIn[v23];
      if ( v22 >= this->pGrainData->SizeOfGrain )
      {
        v22 = 0;
        v24 = 0i64;
      }
      nextSampleIndex = v22 + 1;
      v25 = v24 + this->pGrainData->OffsetIntoSample;
      v10 = v24 + 1;
      resampleBufferSrc[v11 + 3] = pWaveDataIn[v25];
      pGrainData = this->pGrainData;
      if ( nextSampleIndex >= this->pGrainData->SizeOfGrain )
      {
        nextSampleIndex = 0;
        v10 = 0i64;
      }
      v11 += 4i64;
    }
    while ( v11 < (int)v12.m128_f32[0] - 3i64 );
  }
  if ( v11 < v14 )
  {
    v26 = this->pGrainData;
    do
    {
      ++nextSampleIndex;
      v27 = v10 + v26->OffsetIntoSample;
      ++v10;
      resampleBufferSrc[v11] = pWaveDataIn[v27];
      v26 = this->pGrainData;
      if ( nextSampleIndex >= this->pGrainData->SizeOfGrain )
      {
        nextSampleIndex = 0;
        v10 = 0i64;
      }
      ++v11;
    }
    while ( v11 < v14 );
  }
  this->nextSampleIndex = nextSampleIndex;
  v28 = 0i64;
  if ( v14 >= 4 )
  {
    v29 = (char *)&resampleBufferSrc[1] - (char *)pWaveDataOut;
    v30 = (char *)resampleBufferSrc - (char *)pWaveDataOut;
    v31 = (char *)resampleBufferDst - (char *)pWaveDataOut;
    v32 = (char *)&resampleBufferDst[1] - (char *)pWaveDataOut;
    v33 = ((unsigned __int64)(v14 - 4) >> 2) + 1;
    v7 = 4 * v33;
    v28 = 4 * v33;
    v34 = pWaveDataOut + 2;
    do
    {
      v35 = *(_DWORD *)((char *)v34 + v30 - 8);
      v34 += 4;
      *(_DWORD *)((char *)v34 + v31 - 24) = v35;
      *((_DWORD *)v34 - 6) = v35;
      this->lastSample = *(float *)((char *)v34 + v31 - 24);
      v36 = *(_DWORD *)((char *)v34 + v29 - 24);
      *(_DWORD *)((char *)v34 + v32 - 24) = v36;
      *((_DWORD *)v34 - 5) = v36;
      this->lastSample = *(float *)((char *)v34 + v32 - 24);
      v37 = *(_DWORD *)((char *)v34 + v30 - 16);
      *(_DWORD *)((char *)v34 + v31 - 16) = v37;
      *((_DWORD *)v34 - 4) = v37;
      this->lastSample = *(float *)((char *)v34 + v31 - 16);
      v38 = *(_DWORD *)((char *)v34 + v29 - 16);
      *(_DWORD *)((char *)v34 + v32 - 16) = v38;
      *((_DWORD *)v34 - 3) = v38;
      this->lastSample = *(float *)((char *)v34 + v32 - 16);
      --v33;
    }
    while ( v33 );
  }
  if ( v28 < v14 )
  {
    v7 += v14 - v28;
    do
    {
      v39 = (char *)pWaveDataOut - (char *)resampleBufferDst + 4 * v28++;
      v40 = (float *)((char *)resampleBufferDst + v39);
      v41 = *(float *)((char *)v40 + (char *)resampleBufferSrc - (char *)pWaveDataOut);
      resampleBufferDst[v28 - 1] = v41;
      *v40 = v41;
      this->lastSample = resampleBufferDst[v28 - 1];
    }
    while ( v28 < v14 );
  }
  v42 = v7;
  if ( v7 < v6 )
  {
    if ( v6 - v7 >= 4 )
    {
      v43 = &pWaveDataOut[v7 + 2];
      v44 = ((unsigned __int64)(v6 - v7 - 4) >> 2) + 1;
      v42 = v7 + 4 * v44;
      do
      {
        v43 += 4;
        *(v43 - 6) = this->lastSample;
        *(v43 - 5) = this->lastSample;
        *(v43 - 4) = this->lastSample;
        *(v43 - 3) = this->lastSample;
        --v44;
      }
      while ( v44 );
    }
    for ( ; v42 < v6; pWaveDataOut[v42 - 1] = this->lastSample )
      ++v42;
  }
}

// File Line: 649
// RVA: 0x15C6B0
__int64 __fastcall SpectralEngineCoreDX::GrainPlayerSource::CrossFade(
        SpectralEngineCoreDX::GrainPlayerSource *this,
        SpectralEngineCoreDX::GrainPlayer *outGrain,
        SpectralEngineCoreDX::GrainPlayer *inGrain,
        float *nextToWrite,
        signed int size)
{
  int crossFadeDuration; // r11d
  float v9; // xmm2_4
  __m128 v10; // xmm6
  float v11; // xmm1_4
  int v12; // ecx
  unsigned int v13; // esi
  float v14; // xmm0_4
  __int64 v15; // r9
  unsigned int v16; // edx
  __int64 v17; // rcx
  __int64 v18; // r12
  signed __int64 v19; // r10
  signed __int64 v20; // r11
  signed __int64 v21; // rbx
  signed __int64 v22; // rbp
  unsigned __int64 v23; // r15
  unsigned int v24; // r13d
  float *v25; // r8
  __m128i v26; // xmm2
  int v27; // eax
  float v28; // xmm1_4
  __m128i v29; // xmm2
  float *v30; // r8
  __m128i v31; // xmm1

  crossFadeDuration = this->crossFadeDuration;
  v10 = (__m128)(unsigned int)FLOAT_1_0;
  v9 = (float)((float)((float)crossFadeDuration * outGrain->readSpeed) + (float)outGrain->nextSampleIndex)
     - (float)outGrain->pGrainData->SizeOfGrain;
  v10.m128_f32[0] = (float)(1.0 / outGrain->readSpeed) * v9;
  v11 = v10.m128_f32[0];
  v12 = (int)v10.m128_f32[0];
  if ( (int)v10.m128_f32[0] != 0x80000000 && (float)v12 != v10.m128_f32[0] )
    v11 = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1) + v12);
  v13 = 0;
  if ( (float)(int)v9 < 0.0 )
    v10.m128_i32[0] = 0;
  v14 = (float)size;
  if ( (float)(crossFadeDuration - (int)v11) <= (float)size )
    v14 = (float)(crossFadeDuration - (int)v11);
  SpectralEngineCoreDX::GrainPlayer::ReadSamples(outGrain, (int)v14, this->pGrainFileHeader->WaveData, mixBufferA);
  SpectralEngineCoreDX::GrainPlayer::ReadSamples(inGrain, (int)v14, this->pGrainFileHeader->WaveData, mixBufferB);
  v15 = (int)v14;
  v16 = 0;
  v17 = 0i64;
  v18 = 0i64;
  if ( v15 >= 4 )
  {
    v19 = (char *)mixBufferA - (char *)nextToWrite;
    v20 = (char *)mixBufferB - (char *)nextToWrite;
    v21 = (char *)&mixBufferA[1] - (char *)nextToWrite;
    v22 = (char *)&mixBufferB[1] - (char *)nextToWrite;
    v23 = ((unsigned __int64)((int)v14 - 4i64) >> 2) + 1;
    v24 = 2;
    v17 = 4 * v23;
    v25 = nextToWrite + 2;
    v13 = 4 * v23;
    v18 = 4 * v23;
    do
    {
      v26 = _mm_cvtsi32_si128(v16);
      v25 += 4;
      v16 += 4;
      *(float *)v26.m128i_i32 = _mm_cvtepi32_ps(v26).m128_f32[0];
      v27 = v24 + 1;
      *(v25 - 6) = (float)((float)((float)(1.0
                                         - (float)((float)(*(float *)v26.m128i_i32 + v10.m128_f32[0])
                                                 / (float)this->crossFadeDuration))
                                 * *(float *)((char *)v25 + v19 - 24))
                         + (float)((float)((float)(*(float *)v26.m128i_i32 + v10.m128_f32[0])
                                         / (float)this->crossFadeDuration)
                                 * *(float *)((char *)v25 + v20 - 24)))
                 * this->params.Volume;
      v28 = (float)((float)(1.0
                          - (float)((float)((float)(int)(v24 - 1) + v10.m128_f32[0]) / (float)this->crossFadeDuration))
                  * *(float *)((char *)v25 + v21 - 24))
          + (float)((float)((float)((float)(int)(v24 - 1) + v10.m128_f32[0]) / (float)this->crossFadeDuration)
                  * *(float *)((char *)v25 + v22 - 24));
      v29 = _mm_cvtsi32_si128(v24);
      v24 += 4;
      *(float *)v29.m128i_i32 = _mm_cvtepi32_ps(v29).m128_f32[0];
      *(v25 - 5) = v28 * this->params.Volume;
      *(v25 - 4) = (float)((float)((float)(1.0
                                         - (float)((float)(*(float *)v29.m128i_i32 + v10.m128_f32[0])
                                                 / (float)this->crossFadeDuration))
                                 * *(float *)((char *)v25 + v19 - 16))
                         + (float)((float)((float)(*(float *)v29.m128i_i32 + v10.m128_f32[0])
                                         / (float)this->crossFadeDuration)
                                 * *(float *)((char *)v25 + v20 - 16)))
                 * this->params.Volume;
      *(v25 - 3) = (float)((float)((float)(1.0
                                         - (float)((float)((float)v27 + v10.m128_f32[0]) / (float)this->crossFadeDuration))
                                 * *(float *)((char *)v25 + v21 - 16))
                         + (float)((float)((float)((float)v27 + v10.m128_f32[0]) / (float)this->crossFadeDuration)
                                 * *(float *)((char *)v25 + v22 - 16)))
                 * this->params.Volume;
      --v23;
    }
    while ( v23 );
  }
  if ( v17 < v15 )
  {
    v30 = &nextToWrite[v18];
    v13 += v15 - v17;
    do
    {
      v31 = _mm_cvtsi32_si128(v16);
      ++v17;
      ++v30;
      ++v16;
      *(float *)v31.m128i_i32 = (float)(_mm_cvtepi32_ps(v31).m128_f32[0] + v10.m128_f32[0])
                              / (float)this->crossFadeDuration;
      *(v30 - 1) = (float)((float)((float)(1.0 - *(float *)v31.m128i_i32) * mixBufferA[v17 - 1])
                         + (float)(*(float *)v31.m128i_i32 * mixBufferB[v17 - 1]))
                 * this->params.Volume;
    }
    while ( v17 < v15 );
  }
  return v13;
}

// File Line: 731
// RVA: 0x15C9F0
GrainHeader *__fastcall SpectralEngineCoreDX::GrainPlayerSource::FindGrain(
        SpectralEngineCoreDX::GrainPlayerSource *this,
        int sampleOffset)
{
  GrainFileHeader *pGrainFileHeader; // rdi
  int v3; // r10d
  int NumberOfGrains; // ebp
  int v6; // r8d
  GrainHeader *pGrains; // r11
  __int64 v8; // rdx
  int OffsetIntoSample; // ebx
  bool v10; // cc

  pGrainFileHeader = this->pGrainFileHeader;
  v3 = 0;
  NumberOfGrains = pGrainFileHeader->NumberOfGrains;
  v6 = NumberOfGrains - 1;
  if ( NumberOfGrains - 1 < 0 )
  {
LABEL_11:
    if ( v3 == NumberOfGrains )
      return &pGrainFileHeader->pGrains[NumberOfGrains - 1];
    if ( v6 )
      return 0i64;
    return pGrainFileHeader->pGrains;
  }
  pGrains = pGrainFileHeader->pGrains;
  while ( 1 )
  {
    v8 = (v6 + v3) / 2;
    OffsetIntoSample = pGrains[v8].OffsetIntoSample;
    v10 = OffsetIntoSample < sampleOffset;
    if ( OffsetIntoSample <= sampleOffset )
      break;
    if ( pGrains[v8 - 1].OffsetIntoSample <= sampleOffset )
    {
      v10 = OffsetIntoSample < sampleOffset;
      break;
    }
    v6 = v8 - 1;
LABEL_10:
    if ( v3 > v6 )
      goto LABEL_11;
  }
  if ( v10 && pGrains[(v6 + v3) / 2 - 1].OffsetIntoSample < sampleOffset )
  {
    v3 = v8 + 1;
    goto LABEL_10;
  }
  if ( (_DWORD)v8 )
    return &pGrains[(int)v8 - 1];
  else
    return pGrainFileHeader->pGrains;
}

// File Line: 785
// RVA: 0x15CAC0
GrainHeader *__fastcall SpectralEngineCoreDX::GrainPlayerSource::FindGrainLinearSearch(
        SpectralEngineCoreDX::GrainPlayerSource *this,
        float freq)
{
  GrainFileHeader *pGrainFileHeader; // rax
  __int64 v3; // r10
  GrainHeader *pGrains; // r11
  __int64 NumberOfGrains; // r8
  float *p_OffsetIntoSample; // rdx
  float v7; // xmm3_4
  float *p_StartFrequency; // rax
  float *v9; // rcx
  unsigned __int64 v10; // r9
  float *v11; // rcx
  __int64 v12; // r8

  pGrainFileHeader = this->pGrainFileHeader;
  v3 = 0i64;
  pGrains = pGrainFileHeader->pGrains;
  NumberOfGrains = pGrainFileHeader->NumberOfGrains;
  p_OffsetIntoSample = (float *)&pGrains->OffsetIntoSample;
  LODWORD(v7) = COERCE_UNSIGNED_INT(
                  freq
                - (float)((float)((float)(pGrains->EndFrequency - pGrains->StartFrequency) * 0.5)
                        + pGrains->StartFrequency)) & _xmm;
  if ( NumberOfGrains >= 4 )
  {
    p_StartFrequency = &pGrains->StartFrequency;
    v9 = &pGrains[1].StartFrequency;
    v10 = ((unsigned __int64)(NumberOfGrains - 4) >> 2) + 1;
    v3 = 4 * v10;
    do
    {
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                          freq
                        - (float)((float)((float)(p_StartFrequency[1] - *p_StartFrequency) * 0.5) + *p_StartFrequency)) & _xmm) < v7 )
      {
        LODWORD(v7) = COERCE_UNSIGNED_INT(
                        freq
                      - (float)((float)((float)(p_StartFrequency[1] - *p_StartFrequency) * 0.5) + *p_StartFrequency)) & _xmm;
        p_OffsetIntoSample = p_StartFrequency - 1;
      }
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[1] - *v9) * 0.5) + *v9)) & _xmm) < v7 )
      {
        LODWORD(v7) = COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[1] - *v9) * 0.5) + *v9)) & _xmm;
        p_OffsetIntoSample = p_StartFrequency + 3;
      }
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[5] - v9[4]) * 0.5) + v9[4])) & _xmm) < v7 )
      {
        LODWORD(v7) = COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[5] - v9[4]) * 0.5) + v9[4])) & _xmm;
        p_OffsetIntoSample = p_StartFrequency + 7;
      }
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[9] - v9[8]) * 0.5) + v9[8])) & _xmm) < v7 )
      {
        LODWORD(v7) = COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v9[9] - v9[8]) * 0.5) + v9[8])) & _xmm;
        p_OffsetIntoSample = p_StartFrequency + 11;
      }
      p_StartFrequency += 16;
      v9 += 16;
      --v10;
    }
    while ( v10 );
  }
  if ( v3 < NumberOfGrains )
  {
    v11 = (float *)&pGrains[v3].OffsetIntoSample;
    v12 = NumberOfGrains - v3;
    do
    {
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v11[2] - v11[1]) * 0.5) + v11[1])) & _xmm) < v7 )
      {
        LODWORD(v7) = COERCE_UNSIGNED_INT(freq - (float)((float)((float)(v11[2] - v11[1]) * 0.5) + v11[1])) & _xmm;
        p_OffsetIntoSample = v11;
      }
      v11 += 4;
      --v12;
    }
    while ( v12 );
  }
  return (GrainHeader *)p_OffsetIntoSample;
}

