// File Line: 40
// RVA: 0xB02280
void __fastcall MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::UpdateProcessValues(
        MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *this)
{
  if ( this->mDSPMonoImpl )
    this->vfptr[1].UpdateProcessValues(this);
  if ( this->mDSPStereoImpl )
    ((void (__fastcall *)(MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *))this->vfptr[2].__vecDelDtor)(this);
  if ( this->mDSPSurroundImpl )
    ((void (__fastcall *)(MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *))this->vfptr[2].ProcessAudio)(this);
  if ( this->mDSPSurround71Impl )
    this->vfptr[2].UpdateProcessValues(this);
}

// File Line: 247
// RVA: 0xAFC750
AKRESULT __fastcall MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::Init(
        MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uChannelMask)
{
  int v5; // r8d
  int v6; // r8d
  int v7; // r8d
  AKRESULT result; // eax
  LimiterProcessSurround71FloatImpl *v9; // rax
  unsigned __int64 v10; // rax
  LimiterProcessSurroundFloatImpl *v11; // rax
  unsigned __int64 v12; // rax
  LimiterProcessMonoFloatImpl *v13; // rax
  unsigned __int64 v14; // rax
  LimiterProcessStereoFloatImpl *v15; // rax
  unsigned __int64 MemoryMapSize; // rax

  v5 = in_uChannelMask - 3;
  if ( !v5 )
  {
    if ( this->mDSPStereoImpl )
      return 1;
    v15 = (LimiterProcessStereoFloatImpl *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8i64);
    if ( v15 )
      LimiterProcessStereoFloatImpl::LimiterProcessStereoFloatImpl(v15);
    this->mDSPStereoImpl = v15;
    if ( v15 )
    {
      MemoryMapSize = LimiterProcessStereoFloatImpl::GetMemoryMapSize(v15);
      result = PooledMemoryAllocator::Init(&this->mDSPStereoImplAllocator, in_pAllocator, MemoryMapSize);
      if ( result != AK_Success )
        return result;
      result = LimiterProcessStereoFloatImpl::Init(
                 this->mDSPStereoImpl,
                 &this->mDSPStereoImplAllocator,
                 in_pAllocator,
                 this->mSampleRate);
      goto LABEL_31;
    }
    return 52;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    if ( this->mDSPMonoImpl )
      return 1;
    v13 = (LimiterProcessMonoFloatImpl *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8i64);
    if ( v13 )
      LimiterProcessMonoFloatImpl::LimiterProcessMonoFloatImpl(v13);
    this->mDSPMonoImpl = v13;
    if ( v13 )
    {
      v14 = LimiterProcessMonoFloatImpl::GetMemoryMapSize(v13);
      result = PooledMemoryAllocator::Init(&this->mDSPMonoImplAllocator, in_pAllocator, v14);
      if ( result != AK_Success )
        return result;
      result = LimiterProcessMonoFloatImpl::Init(
                 this->mDSPMonoImpl,
                 &this->mDSPMonoImplAllocator,
                 in_pAllocator,
                 this->mSampleRate);
      goto LABEL_31;
    }
    return 52;
  }
  v7 = v6 - 59;
  if ( !v7 )
  {
    if ( this->mDSPSurroundImpl )
      return 1;
    v11 = (LimiterProcessSurroundFloatImpl *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8i64);
    if ( v11 )
      LimiterProcessSurroundFloatImpl::LimiterProcessSurroundFloatImpl(v11);
    this->mDSPSurroundImpl = v11;
    if ( v11 )
    {
      v12 = LimiterProcessSurroundFloatImpl::GetMemoryMapSize(v11);
      result = PooledMemoryAllocator::Init(&this->mDSPSurroundImplAllocator, in_pAllocator, v12);
      if ( result != AK_Success )
        return result;
      result = LimiterProcessSurroundFloatImpl::Init(
                 this->mDSPSurroundImpl,
                 &this->mDSPSurroundImplAllocator,
                 in_pAllocator,
                 this->mSampleRate);
      goto LABEL_31;
    }
    return 52;
  }
  if ( v7 != 1536 )
    return 78;
  if ( this->mDSPSurround71Impl )
    return 1;
  v9 = (LimiterProcessSurround71FloatImpl *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8i64);
  if ( v9 )
    LimiterProcessSurround71FloatImpl::LimiterProcessSurround71FloatImpl(v9);
  this->mDSPSurround71Impl = v9;
  if ( !v9 )
    return 52;
  v10 = LimiterProcessSurround71FloatImpl::GetMemoryMapSize(v9);
  result = PooledMemoryAllocator::Init(&this->mDSPSurround71ImplAllocator, in_pAllocator, v10);
  if ( result != AK_Success )
    return result;
  result = LimiterProcessSurround71FloatImpl::Init(
             this->mDSPSurround71Impl,
             &this->mDSPSurround71ImplAllocator,
             in_pAllocator,
             this->mSampleRate);
LABEL_31:
  if ( result != AK_Success )
    return result;
  this->vfptr->UpdateProcessValues(this);
  return 1;
}_31:
  if (

// File Line: 316
// RVA: 0xAFC980
void __fastcall MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::Term(
        MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  LimiterProcessMonoFloatImpl *mDSPMonoImpl; // rsi
  LimiterProcessStereoFloatImpl *mDSPStereoImpl; // rsi
  LimiterProcessSurroundFloatImpl *mDSPSurroundImpl; // rsi
  LimiterProcessSurround71FloatImpl *mDSPSurround71Impl; // rsi

  if ( this->mDSPMonoImpl )
  {
    PooledMemoryAllocator::Term(&this->mDSPMonoImplAllocator, in_pAllocator);
    LimiterProcessMonoFloatImpl::Term(this->mDSPMonoImpl, in_pAllocator);
    mDSPMonoImpl = this->mDSPMonoImpl;
    if ( mDSPMonoImpl )
    {
      LimiterProcessMonoFloatImpl::~LimiterProcessMonoFloatImpl(this->mDSPMonoImpl);
      in_pAllocator->vfptr->Free(in_pAllocator, mDSPMonoImpl);
    }
    this->mDSPMonoImpl = 0i64;
  }
  else if ( this->mDSPStereoImpl )
  {
    PooledMemoryAllocator::Term(&this->mDSPStereoImplAllocator, in_pAllocator);
    LimiterProcessStereoFloatImpl::Term(this->mDSPStereoImpl, in_pAllocator);
    mDSPStereoImpl = this->mDSPStereoImpl;
    if ( mDSPStereoImpl )
    {
      LimiterProcessStereoFloatImpl::~LimiterProcessStereoFloatImpl(this->mDSPStereoImpl);
      in_pAllocator->vfptr->Free(in_pAllocator, mDSPStereoImpl);
    }
    this->mDSPStereoImpl = 0i64;
  }
  else if ( this->mDSPSurroundImpl )
  {
    PooledMemoryAllocator::Term(&this->mDSPSurroundImplAllocator, in_pAllocator);
    LimiterProcessSurroundFloatImpl::Term(this->mDSPSurroundImpl, in_pAllocator);
    mDSPSurroundImpl = this->mDSPSurroundImpl;
    if ( mDSPSurroundImpl )
    {
      LimiterProcessSurroundFloatImpl::~LimiterProcessSurroundFloatImpl(this->mDSPSurroundImpl);
      in_pAllocator->vfptr->Free(in_pAllocator, mDSPSurroundImpl);
    }
    this->mDSPSurroundImpl = 0i64;
  }
  else if ( this->mDSPSurround71Impl )
  {
    PooledMemoryAllocator::Term(&this->mDSPSurround71ImplAllocator, in_pAllocator);
    LimiterProcessSurround71FloatImpl::Term(this->mDSPSurround71Impl, in_pAllocator);
    mDSPSurround71Impl = this->mDSPSurround71Impl;
    if ( mDSPSurround71Impl )
    {
      LimiterProcessSurround71FloatImpl::~LimiterProcessSurround71FloatImpl(this->mDSPSurround71Impl);
      in_pAllocator->vfptr->Free(in_pAllocator, mDSPSurround71Impl);
    }
    this->mDSPSurround71Impl = 0i64;
  }
}

// File Line: 351
// RVA: 0xB021A0
void __fastcall MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::ProcessAudio(
        MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *this,
        AkAudioBuffer *processBuffer)
{
  char *v4; // rax
  char *v5; // rax
  char *v6; // rax
  float *PointerToPooledMemory; // rax

  switch ( processBuffer->uChannelMask )
  {
    case 3u:
      PointerToPooledMemory = (float *)PooledMemoryAllocator::GetPointerToPooledMemory(
                                         &this->mDSPStereoImplAllocator,
                                         0i64);
      LimiterProcessStereoFloatImpl::ProcessAudio(
        this->mDSPStereoImpl,
        PointerToPooledMemory,
        processBuffer,
        processBuffer);
      break;
    case 4u:
      v6 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->mDSPMonoImplAllocator, 0i64);
      LimiterProcessMonoFloatImpl::ProcessAudio(this->mDSPMonoImpl, v6, processBuffer, processBuffer);
      break;
    case 0x3Fu:
      v5 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->mDSPSurroundImplAllocator, 0i64);
      LimiterProcessSurroundFloatImpl::ProcessAudio(this->mDSPSurroundImpl, v5, processBuffer, processBuffer);
      break;
    case 0x63Fu:
      v4 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->mDSPSurround71ImplAllocator, 0i64);
      LimiterProcessSurround71FloatImpl::ProcessAudio(this->mDSPSurround71Impl, v4, processBuffer, processBuffer);
      break;
  }
}

