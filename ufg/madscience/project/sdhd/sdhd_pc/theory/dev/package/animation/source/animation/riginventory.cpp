// File Line: 33
// RVA: 0x146AE40
__int64 UFG::_dynamic_initializer_for__gRigInventory__()
{
  UFG::qResourceInventory::qResourceInventory(&UFG::gRigInventory, "RigInventory", 0x39BC0A7Eu, 0x1418DD74u, 0, 0);
  UFG::gRigInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::RigInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gRigInventory__);
}

// File Line: 45
// RVA: 0x1BEC50
void __fastcall UFG::RigInventory::Add(UFG::RigInventory *this, UFG::RigResource *resource_data)
{
  if ( resource_data )
    UFG::RigResource::RigResource(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 55
// RVA: 0x1BED10
void __fastcall UFG::RigInventory::Remove(UFG::RigInventory *this, UFG::RigResource *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::RigResource::~RigResource(resource_data);
}

// File Line: 66
// RVA: 0x1BECA0
void __fastcall UFG::RigInventory::OnAttachHandle(
        UFG::RigInventory *this,
        UFG::qResourceHandle *handle,
        UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax

  mPrev = handle[1].mPrev;
  *(_QWORD *)&handle[1].mNameUID = handle->mData[3].mNode.mParent;
  if ( mPrev )
    ((void (__fastcall *)(UFG::qResourceHandle *, UFG::qResourceData *))mPrev)(handle, handle[1].mData);
}

// File Line: 74
// RVA: 0x1BECD0
void __fastcall UFG::RigInventory::OnDetachHandle(
        UFG::RigInventory *this,
        UFG::qResourceHandle *handle,
        UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  mNext = handle[1].mNext;
  if ( mNext )
  {
    ((void (__fastcall *)(UFG::qResourceHandle *, UFG::qResourceData *, UFG::qResourceData *))mNext)(
      handle,
      handle[1].mData,
      data);
    *(_QWORD *)&handle[1].mNameUID = 0i64;
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
  __int64 v2; // rsi
  char v3; // dl
  Skeleton *v4; // rbx
  char v5; // cl
  UFG::NativePackfileUtils::Fixups *v6; // rax
  char v7; // al
  __int64 m_size; // rcx
  unsigned int *v9; // r14
  __int64 v10; // r8
  UFG::RigResource::BoneLookupEntry *v11; // rax
  UFG::RigResource::ModelMap *v12; // rcx
  UFG::RigResource::CollisionMap *v13; // rdx
  unsigned int *v14; // rcx
  unsigned int *v15; // rdx
  __int64 mNumSkinMorphs; // rax
  unsigned int *v17; // rdx
  UFG::qMatrix44 *v18; // rcx
  unsigned int *v19; // rcx
  unsigned int *v20; // rcx
  unsigned int *v21; // rdx
  UFG::allocator::free_link *v22; // rax
  Skeleton *v23; // rax

  UFG::qResourceData::qResourceData(this);
  v2 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v3 = ++*(_BYTE *)(v2 + 80);
  *(_DWORD *)(v2 + 4i64 * v3) = 3;
  *(_QWORD *)(v2 + 8i64 * v3 + 16) = "RigPackfile";
  v4 = 0i64;
  *(_QWORD *)(v2 + 8i64 * v3 + 48) = 0i64;
  v5 = *(_BYTE *)(v2 + 81);
  if ( v3 > v5 )
    v5 = v3;
  *(_BYTE *)(v2 + 81) = v5;
  v6 = (UFG::NativePackfileUtils::Fixups *)UFG::qMemoryPool::Allocate(
                                             &gPhysicsMemoryPool,
                                             0x20ui64,
                                             "NativePackfileUtils::Fixups",
                                             0i64,
                                             1u);
  if ( v6 )
  {
    v6->nonZeroFixups.m_data = 0i64;
    v6->nonZeroFixups.m_size = 0;
    v6->nonZeroFixups.m_capacityAndFlags = 0x80000000;
    v6->zeroFixups.m_data = 0i64;
    v6->zeroFixups.m_size = 0;
    v6->zeroFixups.m_capacityAndFlags = 0x80000000;
  }
  else
  {
    v6 = 0i64;
  }
  this->mStreamingFixups = v6;
  this->mSkeleton = (hkaSkeleton *)UFG::NativePackfileUtils::loadInPlace(
                                     (hkPackfileSectionHeader *)(((unsigned __int64)this[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64),
                                     this->mHavokMemImagedDataSize,
                                     v6);
  v7 = *(_BYTE *)(v2 + 80);
  if ( v7 > 0 )
  {
    *(_BYTE *)(v2 + 80) = v7 - 1;
  }
  else
  {
    *(_BYTE *)(v2 + 80) = 0;
    *(_DWORD *)v2 = 3;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 48) = 0i64;
  }
  m_size = this->mSkeleton->m_bones.m_size;
  v9 = (unsigned int *)(this->mHavokMemImagedDataSize
                      + (((unsigned __int64)this[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64));
  this->mBoneNameGuids = v9;
  v10 = m_size;
  v11 = (UFG::RigResource::BoneLookupEntry *)&v9[m_size];
  this->mBoneNameToIndexLookup = v11;
  v12 = (UFG::RigResource::ModelMap *)&v11[m_size];
  this->mModelMap = v12;
  v13 = (UFG::RigResource::CollisionMap *)&v12[this->mNumModelMap];
  this->mCollisionMap = v13;
  v14 = (unsigned int *)&v13[this->mNumCollisionMap];
  this->mSkinGuids = v14;
  v15 = &v14[this->mNumSkins];
  this->mSkinMorphGuids = v15;
  mNumSkinMorphs = this->mNumSkinMorphs;
  v17 = &v15[mNumSkinMorphs];
  this->mSkinMorphBaseSkinID = v17;
  v18 = (UFG::qMatrix44 *)(((unsigned __int64)&v17[mNumSkinMorphs + 3] + 3) & 0xFFFFFFFFFFFFFFF0ui64);
  this->mInverseModelSpace = v18;
  v19 = (unsigned int *)&v18[v10];
  this->mDamageMarkers = v19;
  v20 = &v19[this->mNumDamageMarkers];
  this->mTriggerDamageMarkers = v20;
  v21 = &v20[this->mNumTriggerDamageMarkers];
  this->mBaseDamageMarkers = v21;
  this->mBaseDamageMarkerCounts = &v21[this->mNumBaseDamageMarkers];
  v22 = UFG::qMalloc(0x38ui64, "RigResource::Skeleton", 0x800ui64);
  if ( v22 )
  {
    Skeleton::Skeleton((Skeleton *)v22, this->mNode.mUID);
    v4 = v23;
  }
  this->mUFGSkeleton = v4;
  Skeleton::setHkaSkeleton(v4, this);
}

// File Line: 157
// RVA: 0x1BEBA0
void __fastcall UFG::RigResource::~RigResource(UFG::RigResource *this)
{
  Skeleton *mUFGSkeleton; // rdi
  UFG::NativePackfileUtils::Fixups *mStreamingFixups; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  mUFGSkeleton = this->mUFGSkeleton;
  if ( mUFGSkeleton )
  {
    _((AMD_HD3D *)this->mUFGSkeleton);
    operator delete[](mUFGSkeleton);
  }
  this->mUFGSkeleton = 0i64;
  mStreamingFixups = (UFG::NativePackfileUtils::Fixups *)this->mStreamingFixups;
  UFG::NativePackfileUtils::unloadInPlace(
    (_DWORD *)(((unsigned __int64)this[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64),
    this->mHavokMemImagedDataSize,
    mStreamingFixups);
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

