// File Line: 65
// RVA: 0x3A09F0
void __fastcall UFG::AnimationInventory::Add(UFG::AnimationInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::AnimationInventory *v3; // rdi

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::AnimationResource::AnimationResource((UFG::AnimationResource *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 76
// RVA: 0x3ADF30
void __fastcall UFG::AnimationInventory::Remove(UFG::AnimationInventory *this, UFG::qResourceData *resource_data)
{
  UFG::AnimationResource *v2; // rbx

  v2 = (UFG::AnimationResource *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::AnimationResource::~AnimationResource(v2);
}

// File Line: 88
// RVA: 0x3ABFC0
void __fastcall UFG::AnimationInventory::OnAttachHandle(UFG::AnimationInventory *this, UFG::qResourceHandle *handle, UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rcx

  v3 = handle[1].mPrev;
  LODWORD(handle[1].mNext) = 0;
  JUMPOUT(v3, 0i64, SkeletalAnimation::OnLoad);
}

// File Line: 98
// RVA: 0x3ABFE0
void __fastcall UFG::AnimationInventory::OnDetachHandle(UFG::AnimationInventory *this, UFG::qResourceHandle *handle, UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rcx

  if ( !LODWORD(handle[1].mNext) )
  {
    v3 = handle[1].mPrev;
    if ( v3 )
    {
      LODWORD(handle[1].mNext) = 1;
      SkeletalAnimation::OnUnload((SkeletalAnimation *)v3);
    }
  }
}

// File Line: 115
// RVA: 0x39D6F0
void __fastcall UFG::AnimationResource::AnimationResource(UFG::AnimationResource *this)
{
  UFG::AnimationResource *v1; // rbx
  signed __int64 v2; // rsi
  char v3; // dl
  __int64 v4; // rax
  char v5; // cl
  UFG::allocator::free_link *v6; // rax
  UFG::NativePackfileUtils::Fixups *v7; // rdi
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // eax
  int v12; // eax
  int v13; // er9
  int v14; // ecx
  int v15; // edx
  char v16; // al
  UFG::allocator::free_link *result; // [rsp+78h] [rbp+10h]

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v1->mStreamingFixups = 0i64;
  v1->m_pAnimationBinding = (hkaAnimationBinding *)(((unsigned __int64)v1[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64);
  if ( v1->m_uAnimationBindingSize )
  {
    v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
    v3 = ++*(_BYTE *)(v2 + 80);
    v4 = v3;
    *(_DWORD *)(v2 + 4 * v4) = 3;
    *(_QWORD *)(v2 + 8 * v4 + 16) = "AnimationPackfile";
    *(_QWORD *)(v2 + 8 * v4 + 48) = 0i64;
    v5 = *(_BYTE *)(v2 + 81);
    if ( v3 > v5 )
      v5 = v3;
    *(_BYTE *)(v2 + 81) = v5;
    v6 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x20ui64, "NativePackfileUtils::Fixups", 0i64, 1u);
    v7 = (UFG::NativePackfileUtils::Fixups *)v6;
    result = v6;
    if ( v6 )
    {
      v6->mNext = 0i64;
      LODWORD(v6[1].mNext) = 0;
      HIDWORD(v6[1].mNext) = 2147483648;
      v6[2].mNext = 0i64;
      LODWORD(v6[3].mNext) = 0;
      HIDWORD(v6[3].mNext) = 2147483648;
    }
    else
    {
      v7 = 0i64;
    }
    v8 = v7->nonZeroFixups.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < 16 )
    {
      v9 = 2 * v8;
      v10 = 16;
      if ( v9 > 16 )
        v10 = v9;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v7,
        v10,
        16);
    }
    v11 = v7->zeroFixups.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v11 < 16 )
    {
      v12 = 2 * v11;
      v13 = 16;
      if ( v12 > 16 )
        v13 = v12;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v7->zeroFixups,
        v13,
        8);
    }
    v1->mStreamingFixups = v7;
    v1->m_pAnimationBinding = (hkaAnimationBinding *)UFG::NativePackfileUtils::loadInPlace(
                                                       (void *)(((unsigned __int64)v1[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64),
                                                       v1->m_uAnimationBindingSize,
                                                       v7);
    v14 = v7->nonZeroFixups.m_size;
    if ( v14 < (v7->nonZeroFixups.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16, 0i64, v14);
    v15 = v7->zeroFixups.m_size;
    if ( v15 < (v7->zeroFixups.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->zeroFixups, 8, 0i64, v15);
    v16 = *(_BYTE *)(v2 + 80);
    if ( v16 > 0 )
    {
      *(_BYTE *)(v2 + 80) = v16 - 1;
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
  UFG::AnimationResource *v1; // rdi
  UFG::NativePackfileUtils::Fixups *v2; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rax

  v1 = this;
  v2 = (UFG::NativePackfileUtils::Fixups *)this->mStreamingFixups;
  UFG::NativePackfileUtils::unloadInPlace(
    (void *)(((unsigned __int64)this[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64),
    v1->m_uAnimationBindingSize,
    (UFG::NativePackfileUtils::Fixups *)v1->mStreamingFixups);
  if ( v2 )
  {
    UFG::NativePackfileUtils::Fixups::~Fixups(v2);
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v2);
  }
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v1->mResourceHandles);
  v3 = v1->mResourceHandles.mNode.mPrev;
  v4 = v1->mResourceHandles.mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v1->mResourceHandles.mNode.mPrev = &v1->mResourceHandles.mNode;
  v1->mResourceHandles.mNode.mNext = &v1->mResourceHandles.mNode;
}

// File Line: 159
// RVA: 0x3AAE90
void UFG::AnimationResource::Initialize(void)
{
  if ( !(_S9_7 & 1) )
  {
    _S9_7 |= 1u;
    UFG::qResourceInventory::qResourceInventory(
      (UFG::qResourceInventory *)&gAnimationInventory.vfptr,
      "AnimationInventory",
      0x53F1685Eu,
      0x8ACF9964,
      0,
      0x400u);
    gAnimationInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::AnimationInventory::`vftable';
    atexit(UFG::AnimationResource::Initialize_::_2_::_dynamic_atexit_destructor_for__gAnimationInventory__);
  }
}

