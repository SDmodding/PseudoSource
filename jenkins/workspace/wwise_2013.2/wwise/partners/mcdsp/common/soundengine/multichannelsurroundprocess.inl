// File Line: 40
// RVA: 0xB02280
void __fastcall MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::UpdateProcessValues(MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *this)
{
  MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *v1; // rbx

  v1 = this;
  if ( this->mDSPMonoImpl )
    ((void (*)(void))this->vfptr[1].UpdateProcessValues)();
  if ( v1->mDSPStereoImpl )
    ((void (__fastcall *)(MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *))v1->vfptr[2].__vecDelDtor)(v1);
  if ( v1->mDSPSurroundImpl )
    ((void (__fastcall *)(MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *))v1->vfptr[2].ProcessAudio)(v1);
  if ( v1->mDSPSurround71Impl )
    v1->vfptr[2].UpdateProcessValues((Process *)&v1->vfptr);
}

// File Line: 247
// RVA: 0xAFC750
AKRESULT __fastcall MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::Init(MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uChannelMask)
{
  AK::IAkPluginMemAlloc *v3; // rdi
  MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *v4; // rbx
  unsigned int v5; // er8
  int v6; // er8
  int v7; // er8
  AKRESULT result; // eax
  LimiterProcessSurround71FloatImpl *v9; // rax
  unsigned __int64 v10; // rax
  LimiterProcessSurroundFloatImpl *v11; // rax
  unsigned __int64 v12; // rax
  LimiterProcessMonoFloatImpl *v13; // rax
  unsigned __int64 v14; // rax
  LimiterProcessStereoFloatImpl *v15; // rax
  unsigned __int64 v16; // rax

  v3 = in_pAllocator;
  v4 = this;
  v5 = in_uChannelMask - 3;
  if ( !v5 )
  {
    if ( this->mDSPStereoImpl )
      return 1;
    v15 = (LimiterProcessStereoFloatImpl *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8ui64);
    if ( v15 )
      LimiterProcessStereoFloatImpl::LimiterProcessStereoFloatImpl(v15);
    v4->mDSPStereoImpl = v15;
    if ( v15 )
    {
      v16 = LimiterProcessStereoFloatImpl::GetMemoryMapSize(v15);
      result = PooledMemoryAllocator::Init(&v4->mDSPStereoImplAllocator, v3, v16);
      if ( result != 1 )
        return result;
      result = LimiterProcessStereoFloatImpl::Init(
                 v4->mDSPStereoImpl,
                 &v4->mDSPStereoImplAllocator,
                 v3,
                 v4->mSampleRate);
      goto LABEL_31;
    }
    return 52;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    if ( this->mDSPMonoImpl )
      return 1;
    v13 = (LimiterProcessMonoFloatImpl *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8ui64);
    if ( v13 )
      LimiterProcessMonoFloatImpl::LimiterProcessMonoFloatImpl(v13);
    v4->mDSPMonoImpl = v13;
    if ( v13 )
    {
      v14 = LimiterProcessMonoFloatImpl::GetMemoryMapSize(v13);
      result = PooledMemoryAllocator::Init(&v4->mDSPMonoImplAllocator, v3, v14);
      if ( result != 1 )
        return result;
      result = LimiterProcessMonoFloatImpl::Init(v4->mDSPMonoImpl, &v4->mDSPMonoImplAllocator, v3, v4->mSampleRate);
      goto LABEL_31;
    }
    return 52;
  }
  v7 = v6 - 59;
  if ( !v7 )
  {
    if ( this->mDSPSurroundImpl )
      return 1;
    v11 = (LimiterProcessSurroundFloatImpl *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8ui64);
    if ( v11 )
      LimiterProcessSurroundFloatImpl::LimiterProcessSurroundFloatImpl(v11);
    v4->mDSPSurroundImpl = v11;
    if ( v11 )
    {
      v12 = LimiterProcessSurroundFloatImpl::GetMemoryMapSize(v11);
      result = PooledMemoryAllocator::Init(&v4->mDSPSurroundImplAllocator, v3, v12);
      if ( result != 1 )
        return result;
      result = LimiterProcessSurroundFloatImpl::Init(
                 v4->mDSPSurroundImpl,
                 &v4->mDSPSurroundImplAllocator,
                 v3,
                 v4->mSampleRate);
      goto LABEL_31;
    }
    return 52;
  }
  if ( v7 != 1536 )
    return 78;
  if ( this->mDSPSurround71Impl )
    return 1;
  v9 = (LimiterProcessSurround71FloatImpl *)in_pAllocator->vfptr->Malloc(in_pAllocator, 8ui64);
  if ( v9 )
    LimiterProcessSurround71FloatImpl::LimiterProcessSurround71FloatImpl(v9);
  v4->mDSPSurround71Impl = v9;
  if ( !v9 )
    return 52;
  v10 = LimiterProcessSurround71FloatImpl::GetMemoryMapSize(v9);
  result = PooledMemoryAllocator::Init(&v4->mDSPSurround71ImplAllocator, v3, v10);
  if ( result != 1 )
    return result;
  result = LimiterProcessSurround71FloatImpl::Init(
             v4->mDSPSurround71Impl,
             &v4->mDSPSurround71ImplAllocator,
             v3,
             v4->mSampleRate);
LABEL_31:
  if ( result != 1 )
    return result;
  v4->vfptr->UpdateProcessValues((Process *)&v4->vfptr);
  return 1;
}f ( result != 1 )
    return result;
  v4

// File Line: 316
// RVA: 0xAFC980
void __fastcall MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::Term(MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // rdi
  MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *v3; // rbx
  LimiterProcessMonoFloatImpl *v4; // rsi
  LimiterProcessStereoFloatImpl *v5; // rsi
  LimiterProcessSurroundFloatImpl *v6; // rsi
  LimiterProcessSurround71FloatImpl *v7; // rsi

  v2 = in_pAllocator;
  v3 = this;
  if ( this->mDSPMonoImpl )
  {
    PooledMemoryAllocator::Term(&this->mDSPMonoImplAllocator, in_pAllocator);
    LimiterProcessMonoFloatImpl::Term(v3->mDSPMonoImpl, v2);
    v4 = v3->mDSPMonoImpl;
    if ( v4 )
    {
      LimiterProcessMonoFloatImpl::~LimiterProcessMonoFloatImpl(v3->mDSPMonoImpl);
      v2->vfptr->Free(v2, v4);
    }
    v3->mDSPMonoImpl = 0i64;
  }
  else if ( this->mDSPStereoImpl )
  {
    PooledMemoryAllocator::Term(&this->mDSPStereoImplAllocator, in_pAllocator);
    LimiterProcessStereoFloatImpl::Term(v3->mDSPStereoImpl, v2);
    v5 = v3->mDSPStereoImpl;
    if ( v5 )
    {
      LimiterProcessStereoFloatImpl::~LimiterProcessStereoFloatImpl(v3->mDSPStereoImpl);
      v2->vfptr->Free(v2, v5);
    }
    v3->mDSPStereoImpl = 0i64;
  }
  else if ( this->mDSPSurroundImpl )
  {
    PooledMemoryAllocator::Term(&this->mDSPSurroundImplAllocator, in_pAllocator);
    LimiterProcessSurroundFloatImpl::Term(v3->mDSPSurroundImpl, v2);
    v6 = v3->mDSPSurroundImpl;
    if ( v6 )
    {
      LimiterProcessSurroundFloatImpl::~LimiterProcessSurroundFloatImpl(v3->mDSPSurroundImpl);
      v2->vfptr->Free(v2, v6);
    }
    v3->mDSPSurroundImpl = 0i64;
  }
  else if ( this->mDSPSurround71Impl )
  {
    PooledMemoryAllocator::Term(&this->mDSPSurround71ImplAllocator, in_pAllocator);
    LimiterProcessSurround71FloatImpl::Term(v3->mDSPSurround71Impl, v2);
    v7 = v3->mDSPSurround71Impl;
    if ( v7 )
    {
      LimiterProcessSurround71FloatImpl::~LimiterProcessSurround71FloatImpl(v3->mDSPSurround71Impl);
      v2->vfptr->Free(v2, v7);
    }
    v3->mDSPSurround71Impl = 0i64;
  }
}

// File Line: 351
// RVA: 0xB021A0
void __fastcall MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl>::ProcessAudio(MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *this, AkAudioBuffer *processBuffer)
{
  AkAudioBuffer *v2; // rbx
  MultiChannelSurroundProcess<LimiterProcessMonoFloatImpl,LimiterProcessStereoFloatImpl,LimiterProcessSurroundFloatImpl,LimiterProcessSurround71FloatImpl> *v3; // rdi
  char *v4; // rax
  char *v5; // rax
  char *v6; // rax
  char *v7; // rax

  v2 = processBuffer;
  v3 = this;
  switch ( processBuffer->uChannelMask )
  {
    case 3u:
      v7 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->mDSPStereoImplAllocator, 0i64);
      LimiterProcessStereoFloatImpl::ProcessAudio(v3->mDSPStereoImpl, v7, v2, v2);
      break;
    case 4u:
      v6 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->mDSPMonoImplAllocator, 0i64);
      LimiterProcessMonoFloatImpl::ProcessAudio(v3->mDSPMonoImpl, v6, v2, v2);
      break;
    case 0x3Fu:
      v5 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->mDSPSurroundImplAllocator, 0i64);
      LimiterProcessSurroundFloatImpl::ProcessAudio(v3->mDSPSurroundImpl, v5, v2, v2);
      break;
    case 0x63Fu:
      v4 = PooledMemoryAllocator::GetPointerToPooledMemory(&this->mDSPSurround71ImplAllocator, 0i64);
      LimiterProcessSurround71FloatImpl::ProcessAudio(v3->mDSPSurround71Impl, v4, v2, v2);
      break;
  }
}

