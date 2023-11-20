// File Line: 17
// RVA: 0xB01E50
void __fastcall LimiterProcess::LimiterProcess(LimiterProcess *this)
{
  LimiterProcess *v1; // rbx

  v1 = this;
  this->mSampleRate = 44100;
  this->vfptr = (ProcessVtbl *)&MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::`vftable;
  this->mDSPMonoImpl = 0i64;
  this->mDSPStereoImpl = 0i64;
  this->mDSPSurroundImpl = 0i64;
  this->mDSPSurround71Impl = 0i64;
  PooledMemoryAllocator::PooledMemoryAllocator(&this->mDSPMonoImplAllocator);
  PooledMemoryAllocator::PooledMemoryAllocator(&v1->mDSPStereoImplAllocator);
  PooledMemoryAllocator::PooledMemoryAllocator(&v1->mDSPSurroundImplAllocator);
  PooledMemoryAllocator::PooledMemoryAllocator(&v1->mDSPSurround71ImplAllocator);
  v1->vfptr = (ProcessVtbl *)&LimiterProcess::`vftable;
  v1->mParameters.ceiling = 0.0;
  v1->mParameters.release = 10.0;
  v1->mParameters.threshold = 0.0;
  v1->mParameters.knee = 0.0;
  v1->mParameters.character = 0;
}

// File Line: 23
// RVA: 0xB01F00
void __fastcall LimiterProcess::~LimiterProcess(LimiterProcess *this)
{
  LimiterProcess *v1; // rbx
  PooledMemoryAllocator *v2; // rcx

  v1 = this;
  v2 = &this->mDSPSurround71ImplAllocator;
  v2[-5].mCurrentPointer = (char *)&MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::`vftable;
  PooledMemoryAllocator::~PooledMemoryAllocator(v2);
  PooledMemoryAllocator::~PooledMemoryAllocator(&v1->mDSPSurroundImplAllocator);
  PooledMemoryAllocator::~PooledMemoryAllocator(&v1->mDSPStereoImplAllocator);
  PooledMemoryAllocator::~PooledMemoryAllocator(&v1->mDSPMonoImplAllocator);
  v1->vfptr = (ProcessVtbl *)&AK::IAkPluginMemAlloc::`vftable;
}

// File Line: 29
// RVA: 0xB01F60
void __fastcall LimiterProcess::SetMonoImplParameters(LimiterProcess *this, LimiterProcessMonoFloatImpl *monoImpl)
{
  LimiterProcessMonoFloatImpl::SetParameters(monoImpl, &this->mParameters);
}

// File Line: 36
// RVA: 0xB01F80
void __fastcall LimiterProcess::SetStereoImplParameters(LimiterProcess *this, LimiterProcessStereoFloatImpl *stereoImpl)
{
  __int128 v2; // xmm1
  __int128 v3; // [rsp+20h] [rbp-38h]
  __int128 v4; // [rsp+30h] [rbp-28h]
  __int64 v5; // [rsp+40h] [rbp-18h]

  v2 = *(_OWORD *)&this->mParameters.knee;
  v3 = *(_OWORD *)&this->mParameters.ceiling;
  v4 = v2;
  v5 = *(_QWORD *)&this->mParameters.character;
  LimiterProcessStereoFloatImpl::SetParameters(stereoImpl, (LimiterParameters *)&v3);
}

// File Line: 43
// RVA: 0xB01FD0
void __fastcall LimiterProcess::SetSurroundImplParameters(LimiterProcess *this, LimiterProcessSurroundFloatImpl *surroundImpl)
{
  __int128 v2; // xmm1
  __int128 v3; // [rsp+20h] [rbp-38h]
  __int128 v4; // [rsp+30h] [rbp-28h]
  __int64 v5; // [rsp+40h] [rbp-18h]

  v2 = *(_OWORD *)&this->mParameters.knee;
  v3 = *(_OWORD *)&this->mParameters.ceiling;
  v4 = v2;
  v5 = *(_QWORD *)&this->mParameters.character;
  LimiterProcessSurroundFloatImpl::SetParameters(surroundImpl, (LimiterParameters *)&v3);
}

// File Line: 50
// RVA: 0xB02020
void __fastcall LimiterProcess::SetSurround71ImplParameters(LimiterProcess *this, LimiterProcessSurround71FloatImpl *surround71Impl)
{
  __int128 v2; // xmm1
  __int128 v3; // [rsp+20h] [rbp-38h]
  __int128 v4; // [rsp+30h] [rbp-28h]
  __int64 v5; // [rsp+40h] [rbp-18h]

  v2 = *(_OWORD *)&this->mParameters.knee;
  v3 = *(_OWORD *)&this->mParameters.ceiling;
  v4 = v2;
  v5 = *(_QWORD *)&this->mParameters.character;
  LimiterProcessSurround71FloatImpl::SetParameters(surround71Impl, (LimiterParameters *)&v3);
}

// File Line: 58
// RVA: 0xB02070
signed __int64 __fastcall LimiterProcess::GetMeteringDataSize(LimiterProcess *this)
{
  signed __int64 result; // rax

  if ( this->mDSPSurround71Impl )
    return 72i64;
  if ( this->mDSPSurroundImpl )
    return 56i64;
  result = 16i64;
  if ( this->mDSPStereoImpl )
    result = 24i64;
  return result;
}

// File Line: 84
// RVA: 0xB020B0
void __fastcall LimiterProcess::FillMeteringData(LimiterProcess *this, char *pMeteringData)
{
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
    JUMPOUT(this->mDSPMonoImpl, 0i64, LimiterProcessMonoFloatImpl::FillMeteringData);
  }
}

