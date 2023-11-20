// File Line: 33
// RVA: 0x146AE40
__int64 UFG::_dynamic_initializer_for__gRigInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gRigInventory.vfptr,
    "RigInventory",
    0x39BC0A7Eu,
    0x1418DD74u,
    0,
    0);
  UFG::gRigInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::RigInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gRigInventory__);
}

// File Line: 45
// RVA: 0x1BEC50
void __fastcall UFG::RigInventory::Add(UFG::RigInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::RigInventory *v3; // rdi

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::RigResource::RigResource((UFG::RigResource *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 55
// RVA: 0x1BED10
void __fastcall UFG::RigInventory::Remove(UFG::RigInventory *this, UFG::qResourceData *resource_data)
{
  UFG::RigResource *v2; // rbx

  v2 = (UFG::RigResource *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::RigResource::~RigResource(v2);
}

// File Line: 66
// RVA: 0x1BECA0
void __fastcall UFG::RigInventory::OnAttachHandle(UFG::RigInventory *this, UFG::qResourceHandle *handle, UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rax

  v3 = handle[1].mPrev;
  *(_QWORD *)&handle[1].mNameUID = handle->mData[3].mNode.mParent;
  if ( v3 )
    ((void (__fastcall *)(UFG::qResourceHandle *, UFG::qResourceData *))v3)(handle, handle[1].mData);
}

// File Line: 74
// RVA: 0x1BECD0
void __fastcall UFG::RigInventory::OnDetachHandle(UFG::RigInventory *this, UFG::qResourceHandle *handle, UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rax
  UFG::qResourceHandle *v4; // rbx

  v3 = handle[1].mNext;
  v4 = handle;
  if ( v3 )
  {
    ((void (__fastcall *)(UFG::qResourceHandle *, UFG::qResourceData *, UFG::qResourceData *))v3)(
      handle,
      handle[1].mData,
      data);
    *(_QWORD *)&v4[1].mNameUID = 0i64;
  }
  else
  {
    *(_QWORD *)&handle[1].mNameUID = 0i64;
  }
}

// File Line: 85
// RVA: 0x1BE980
void __fastcall UFG::RigResource::RigResource(UFG::RigResource *this)
{
  UFG::RigResource *v1; // rdi
  signed __int64 v2; // rsi
  char v3; // dl
  __int64 v4; // rax
  Skeleton *v5; // rbx
  char v6; // cl
  UFG::NativePackfileUtils::Fixups *v7; // rax
  char v8; // al
  __int64 v9; // rcx
  unsigned __int64 v10; // r14
  __int64 v11; // r8
  signed __int64 v12; // rax
  signed __int64 v13; // rcx
  signed __int64 v14; // rdx
  signed __int64 v15; // rcx
  signed __int64 v16; // rdx
  signed __int64 v17; // rax
  unsigned int *v18; // rdx
  unsigned __int64 v19; // rcx
  unsigned int *v20; // rcx
  signed __int64 v21; // rcx
  signed __int64 v22; // rdx
  UFG::allocator::free_link *v23; // rax
  Skeleton *v24; // rax

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v3 = ++*(_BYTE *)(v2 + 80);
  v4 = v3;
  *(_DWORD *)(v2 + 4 * v4) = 3;
  *(_QWORD *)(v2 + 8 * v4 + 16) = "RigPackfile";
  v5 = 0i64;
  *(_QWORD *)(v2 + 8 * v4 + 48) = 0i64;
  v6 = *(_BYTE *)(v2 + 81);
  if ( v3 > v6 )
    v6 = v3;
  *(_BYTE *)(v2 + 81) = v6;
  v7 = (UFG::NativePackfileUtils::Fixups *)UFG::qMemoryPool::Allocate(
                                             &gPhysicsMemoryPool,
                                             0x20ui64,
                                             "NativePackfileUtils::Fixups",
                                             0i64,
                                             1u);
  if ( v7 )
  {
    v7->nonZeroFixups.m_data = 0i64;
    v7->nonZeroFixups.m_size = 0;
    v7->nonZeroFixups.m_capacityAndFlags = 2147483648;
    v7->zeroFixups.m_data = 0i64;
    v7->zeroFixups.m_size = 0;
    v7->zeroFixups.m_capacityAndFlags = 2147483648;
  }
  else
  {
    v7 = 0i64;
  }
  v1->mStreamingFixups = v7;
  v1->mSkeleton = (hkaSkeleton *)UFG::NativePackfileUtils::loadInPlace(
                                   (void *)(((unsigned __int64)v1[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64),
                                   v1->mHavokMemImagedDataSize,
                                   v7);
  v8 = *(_BYTE *)(v2 + 80);
  if ( v8 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v8 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  v9 = v1->mSkeleton->m_bones.m_size;
  v10 = v1->mHavokMemImagedDataSize + (((unsigned __int64)v1[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64);
  v1->mBoneNameGuids = (unsigned int *)v10;
  v11 = v9;
  v12 = v10 + 4 * v9;
  v1->mBoneNameToIndexLookup = (UFG::RigResource::BoneLookupEntry *)v12;
  v13 = v12 + 8 * v9;
  v1->mModelMap = (UFG::RigResource::ModelMap *)v13;
  v14 = v13 + 8i64 * v1->mNumModelMap;
  v1->mCollisionMap = (UFG::RigResource::CollisionMap *)v14;
  v15 = v14 + 8i64 * v1->mNumCollisionMap;
  v1->mSkinGuids = (unsigned int *)v15;
  v16 = v15 + 4i64 * v1->mNumSkins;
  v1->mSkinMorphGuids = (unsigned int *)v16;
  v17 = v1->mNumSkinMorphs;
  v18 = (unsigned int *)(v17 * 4 + v16);
  v1->mSkinMorphBaseSkinID = v18;
  v19 = ((unsigned __int64)&v18[v17 + 3] + 3) & 0xFFFFFFFFFFFFFFF0ui64;
  v1->mInverseModelSpace = (UFG::qMatrix44 *)v19;
  v20 = (unsigned int *)((v11 << 6) + v19);
  v1->mDamageMarkers = v20;
  v21 = (signed __int64)&v20[v1->mNumDamageMarkers];
  v1->mTriggerDamageMarkers = (unsigned int *)v21;
  v22 = v21 + 4i64 * v1->mNumTriggerDamageMarkers;
  v1->mBaseDamageMarkers = (unsigned int *)v22;
  v1->mBaseDamageMarkerCounts = (unsigned int *)(v22 + 4i64 * v1->mNumBaseDamageMarkers);
  v23 = UFG::qMalloc(0x38ui64, "RigResource::Skeleton", 0x800ui64);
  if ( v23 )
  {
    Skeleton::Skeleton((Skeleton *)v23, v1->mNode.mUID);
    v5 = v24;
  }
  v1->mUFGSkeleton = v5;
  Skeleton::setHkaSkeleton(v5, v1);
}

// File Line: 157
// RVA: 0x1BEBA0
void __fastcall UFG::RigResource::~RigResource(UFG::RigResource *this)
{
  UFG::RigResource *v1; // rbx
  Skeleton *v2; // rdi
  UFG::NativePackfileUtils::Fixups *v3; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v6; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = this->mUFGSkeleton;
  if ( v2 )
  {
    _((AMD_HD3D *)this->mUFGSkeleton);
    operator delete[](v2);
  }
  v1->mUFGSkeleton = 0i64;
  v3 = (UFG::NativePackfileUtils::Fixups *)v1->mStreamingFixups;
  UFG::NativePackfileUtils::unloadInPlace(
    (void *)(((unsigned __int64)v1[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64),
    v1->mHavokMemImagedDataSize,
    (UFG::NativePackfileUtils::Fixups *)v1->mStreamingFixups);
  if ( v3 )
  {
    UFG::NativePackfileUtils::Fixups::~Fixups(v3);
    UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v3);
  }
  v6 = &v1->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v1->mResourceHandles);
  v4 = v1->mResourceHandles.mNode.mPrev;
  v5 = v1->mResourceHandles.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
}

