// File Line: 65
// RVA: 0x3A09F0
void __fastcall UFG::AnimationInventory::Add(UFG::AnimationInventory *this, UFG::AnimationResource *resource_data)
{
  if ( resource_data )
    UFG::AnimationResource::AnimationResource(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 76
// RVA: 0x3ADF30
void __fastcall UFG::AnimationInventory::Remove(UFG::AnimationInventory *this, UFG::AnimationResource *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::AnimationResource::~AnimationResource(resource_data);
}

// File Line: 88
// RVA: 0x3ABFC0
void __fastcall UFG::AnimationInventory::OnAttachHandle(
        UFG::AnimationInventory *this,
        UFG::qResourceHandle *handle,
        UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx

  mPrev = handle[1].mPrev;
  LODWORD(handle[1].mNext) = 0;
  if ( mPrev )
    SkeletalAnimation::OnLoad((SkeletalAnimation *)mPrev);
}

// File Line: 98
// RVA: 0x3ABFE0
void __fastcall UFG::AnimationInventory::OnDetachHandle(
        UFG::AnimationInventory *this,
        UFG::qResourceHandle *handle,
        UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx

  if ( !LODWORD(handle[1].mNext) )
  {
    mPrev = handle[1].mPrev;
    if ( mPrev )
    {
      LODWORD(handle[1].mNext) = 1;
      SkeletalAnimation::OnUnload((SkeletalAnimation *)mPrev);
    }
  }
}

// File Line: 115
// RVA: 0x39D6F0
void __fastcall UFG::AnimationResource::AnimationResource(UFG::AnimationResource *this)
{
  __int64 v2; // rsi
  char v3; // dl
  char v4; // cl
  UFG::allocator::free_link *v5; // rax
  UFG::NativePackfileUtils::Fixups *v6; // rdi
  int v7; // r9d
  int v8; // r9d
  int m_size; // ecx
  int v10; // edx
  char v11; // al
  UFG::allocator::free_link *result; // [rsp+78h] [rbp+10h] BYREF

  UFG::qResourceData::qResourceData(this);
  this->mStreamingFixups = 0i64;
  this->m_pAnimationBinding = (hkaAnimationBinding *)(((unsigned __int64)this[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64);
  if ( this->m_uAnimationBindingSize )
  {
    v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v3 = ++*(_BYTE *)(v2 + 80);
    *(_DWORD *)(v2 + 4i64 * v3) = 3;
    *(_QWORD *)(v2 + 8i64 * v3 + 16) = "AnimationPackfile";
    *(_QWORD *)(v2 + 8i64 * v3 + 48) = 0i64;
    v4 = *(_BYTE *)(v2 + 81);
    if ( v3 > v4 )
      v4 = v3;
    *(_BYTE *)(v2 + 81) = v4;
    v5 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "NativePackfileUtils::Fixups", 0i64, 1u);
    v6 = (UFG::NativePackfileUtils::Fixups *)v5;
    result = v5;
    if ( v5 )
    {
      v5->mNext = 0i64;
      LODWORD(v5[1].mNext) = 0;
      HIDWORD(v5[1].mNext) = 0x80000000;
      v5[2].mNext = 0i64;
      LODWORD(v5[3].mNext) = 0;
      HIDWORD(v5[3].mNext) = 0x80000000;
    }
    else
    {
      v6 = 0i64;
    }
    if ( (v6->nonZeroFixups.m_capacityAndFlags & 0x3FFFFFFFu) < 0x10 )
    {
      v7 = 16;
      if ( 2 * (v6->nonZeroFixups.m_capacityAndFlags & 0x3FFFFFFF) > 16 )
        v7 = 2 * (v6->nonZeroFixups.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, v6, v7, 16);
    }
    if ( (v6->zeroFixups.m_capacityAndFlags & 0x3FFFFFFFu) < 0x10 )
    {
      v8 = 16;
      if ( 2 * (v6->zeroFixups.m_capacityAndFlags & 0x3FFFFFFF) > 16 )
        v8 = 2 * (v6->zeroFixups.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &v6->zeroFixups, v8, 8);
    }
    this->mStreamingFixups = v6;
    this->m_pAnimationBinding = (hkaAnimationBinding *)UFG::NativePackfileUtils::loadInPlace(
                                                         (hkPackfileSectionHeader *)(((unsigned __int64)this[1].mNode.mChild
                                                                                    + 7) & 0xFFFFFFFFFFFFFFF0ui64),
                                                         this->m_uAnimationBindingSize,
                                                         v6);
    m_size = v6->nonZeroFixups.m_size;
    if ( m_size < (v6->nonZeroFixups.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, v6, 16, 0i64, m_size);
    v10 = v6->zeroFixups.m_size;
    if ( v10 < (v6->zeroFixups.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, &v6->zeroFixups, 8, 0i64, v10);
    v11 = *(_BYTE *)(v2 + 80);
    if ( v11 > 0 )
    {
      *(_BYTE *)(v2 + 80) = v11 - 1;
    }
    else
    {
      *(_BYTE *)(v2 + 80) = 0;
      *(_DWORD *)v2 = 3;
      *(_QWORD *)(v2 + 16) = 0i64;
      *(_QWORD *)(v2 + 48) = 0i64;
    }
  }
}

// File Line: 142
// RVA: 0x39F380
void __fastcall UFG::AnimationResource::~AnimationResource(UFG::AnimationResource *this)
{
  UFG::NativePackfileUtils::Fixups *mStreamingFixups; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  mStreamingFixups = (UFG::NativePackfileUtils::Fixups *)this->mStreamingFixups;
  UFG::NativePackfileUtils::unloadInPlace(
    (_DWORD *)(((unsigned __int64)this[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64),
    this->m_uAnimationBindingSize,
    (UFG::NativePackfileUtils::Fixups *)this->mStreamingFixups);
  if ( mStreamingFixups )
  {
    UFG::NativePackfileUtils::Fixups::~Fixups(mStreamingFixups);
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, (char *)mStreamingFixups);
  }
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&this->mResourceHandles);
  mPrev = this->mResourceHandles.UFG::qResourceData::mNode.mPrev;
  mNext = this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mResourceHandles.UFG::qResourceData::mNode.mPrev = &this->mResourceHandles.UFG::qResourceData::mNode;
  this->mResourceHandles.UFG::qResourceData::mNode.mNext = &this->mResourceHandles.UFG::qResourceData::mNode;
}

// File Line: 159
// RVA: 0x3AAE90
void UFG::AnimationResource::Initialize(void)
{
  if ( (_S9_7 & 1) == 0 )
  {
    _S9_7 |= 1u;
    UFG::qResourceInventory::qResourceInventory(
      &gAnimationInventory,
      "AnimationInventory",
      0x53F1685Eu,
      0x8ACF9964,
      0,
      0x400u);
    gAnimationInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::AnimationInventory::`vftable;
    atexit(UFG::AnimationResource::Initialize_::_2_::_dynamic_atexit_destructor_for__gAnimationInventory__);
  }
}

