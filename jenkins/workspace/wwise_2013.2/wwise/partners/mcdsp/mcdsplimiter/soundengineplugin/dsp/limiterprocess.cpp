// File Line: 17
// RVA: 0xB01E50
void __fastcall LimiterProcess::LimiterProcess(LimiterProcess *this)
{
  this->mSampleRate = 44100;
  this->vfptr = (ProcessVtbl *)&MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::`vftable;
  this->mDSPMonoImpl = 0i64;
  this->mDSPStereoImpl = 0i64;
  this->mDSPSurroundImpl = 0i64;
  this->mDSPSurround71Impl = 0i64;
  PooledMemoryAllocator::PooledMemoryAllocator(&this->mDSPMonoImplAllocator);
  PooledMemoryAllocator::PooledMemoryAllocator(&this->mDSPStereoImplAllocator);
  PooledMemoryAllocator::PooledMemoryAllocator(&this->mDSPSurroundImplAllocator);
  PooledMemoryAllocator::PooledMemoryAllocator(&this->mDSPSurround71ImplAllocator);
  this->vfptr = (ProcessVtbl *)&LimiterProcess::`vftable;
  this->mParameters.ceiling = 0.0;
  this->mParameters.release = 10.0;
  this->mParameters.threshold = 0.0;
  this->mParameters.knee = 0.0;
  this->mParameters.character = eCharacterMode_Clean;
}

// File Line: 23
// RVA: 0xB01F00
void __fastcall LimiterProcess::~LimiterProcess(LimiterProcess *this)
{
  PooledMemoryAllocator *p_mDSPSurround71ImplAllocator; // rcx

  p_mDSPSurround71ImplAllocator = &this->mDSPSurround71ImplAllocator;
  p_mDSPSurround71ImplAllocator[-5].mCurrentPointer = (char *)&MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::`vftable;
  PooledMemoryAllocator::~PooledMemoryAllocator(p_mDSPSurround71ImplAllocator);
  PooledMemoryAllocator::~PooledMemoryAllocator(&this->mDSPSurroundImplAllocator);
  PooledMemoryAllocator::~PooledMemoryAllocator(&this->mDSPStereoImplAllocator);
  PooledMemoryAllocator::~PooledMemoryAllocator(&this->mDSPMonoImplAllocator);
  this->vfptr = (ProcessVtbl *)&AK::IAkPluginMemAlloc::`vftable;
}

// File Line: 29
// RVA: 0xB01F60
void __fastcall LimiterProcess::SetMonoImplParameters(LimiterProcess *this, LimiterProcessMonoFloatImpl *monoImpl)
{
  LimiterProcessMonoFloatImpl::SetParameters(monoImpl, &this->mParameters);
}

// File Line: 36
// RVA: 0xB01F80
void __fastcall LimiterProcess::SetStereoImplParameters(
        LimiterProcess *this,
        LimiterProcessStereoFloatImpl *stereoImpl)
{
  __int128 v2; // xmm1
  LimiterParameters v3; // [rsp+20h] [rbp-38h] BYREF

  v2 = *(_OWORD *)&this->mParameters.knee;
  *(_OWORD *)&v3.ceiling = *(_OWORD *)&this->mParameters.ceiling;
  *(_OWORD *)&v3.knee = v2;
  *(_QWORD *)&v3.character = *(_QWORD *)&this->mParameters.character;
  LimiterProcessStereoFloatImpl::SetParameters(stereoImpl, &v3);
}

// File Line: 43
// RVA: 0xB01FD0
void __fastcall LimiterProcess::SetSurroundImplParameters(
        LimiterProcess *this,
        LimiterProcessSurroundFloatImpl *surroundImpl)
{
  __int128 v2; // xmm1
  LimiterParameters v3; // [rsp+20h] [rbp-38h] BYREF

  v2 = *(_OWORD *)&this->mParameters.knee;
  *(_OWORD *)&v3.ceiling = *(_OWORD *)&this->mParameters.ceiling;
  *(_OWORD *)&v3.knee = v2;
  *(_QWORD *)&v3.character = *(_QWORD *)&this->mParameters.character;
  LimiterProcessSurroundFloatImpl::SetParameters(surroundImpl, &v3);
}

// File Line: 50
// RVA: 0xB02020
void __fastcall LimiterProcess::SetSurround71ImplParameters(
        LimiterProcess *this,
        LimiterProcessSurround71FloatImpl *surround71Impl)
{
  __int128 v2; // xmm1
  LimiterParameters v3; // [rsp+20h] [rbp-38h] BYREF

  v2 = *(_OWORD *)&this->mParameters.knee;
  *(_OWORD *)&v3.ceiling = *(_OWORD *)&this->mParameters.ceiling;
  *(_OWORD *)&v3.knee = v2;
  *(_QWORD *)&v3.character = *(_QWORD *)&this->mParameters.character;
  LimiterProcessSurround71FloatImpl::SetParameters(surround71Impl, &v3);
}

// File Line: 58
// RVA: 0xB02070
__int64 __fastcall LimiterProcess::GetMeteringDataSize(LimiterProcess *this)
{
  __int64 result; // rax

  if ( this->mDSPSurround71Impl )
    return 72i64;
  if ( this->mDSPSurroundImpl )
    return 56i64;
  result = 16i64;
  if ( this->mDSPStereoImpl )
    return 24i64;
  return result;
}

// File Line: 84
// RVA: 0xB020B0
void __fastcall LimiterProcess::FillMeteringData(LimiterProcess *this, char *pMeteringData)
{
  LimiterProcessMonoFloatImpl *mDSPMonoImpl; // rcx

  if ( this->mDSPSurround71Impl )
  {
    LimiterProcessSurround71FloatImpl::FillMeteringData(this->mDSPSurround71Impl, pMeteringData);
  }
  else if ( this->mDSPSurroundImpl )
  {
    LimiterProcessSurroundFloatImpl::FillMeteringData(this->mDSPSurroundImpl, pMeteringData);
  }
  else if ( this->mDSPStereoImpl )
  {
    LimiterProcessStereoFloatImpl::FillMeteringData(this->mDSPStereoImpl, pMeteringData);
  }
  else
  {
    mDSPMonoImpl = this->mDSPMonoImpl;
    if ( mDSPMonoImpl )
      LimiterProcessMonoFloatImpl::FillMeteringData(mDSPMonoImpl, pMeteringData);
  }
}

