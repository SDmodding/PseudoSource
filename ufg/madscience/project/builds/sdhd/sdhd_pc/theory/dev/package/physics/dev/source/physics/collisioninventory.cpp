// File Line: 31
// RVA: 0x1458EE0
__int64 UFG::_dynamic_initializer_for__gCollisionInstanceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gCollisionInstanceInventory,
    "CollisionInstanceInventory",
    0x7970FB96u,
    0xA0B2CC13,
    0,
    0);
  UFG::gCollisionInstanceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::CollisionInstanceInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gCollisionInstanceInventory__);
}

// File Line: 32
// RVA: 0x1458F70
__int64 UFG::_dynamic_initializer_for__gCollisionMeshBundleInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gCollisionMeshBundleInventory,
    "CollisionMeshBundleInventory",
    0x1723EA91u,
    0xBD226A08,
    0,
    0);
  UFG::gCollisionMeshBundleInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::CollisionMeshBundleInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gCollisionMeshBundleInventory__);
}

// File Line: 44
// RVA: 0x9FBF0
void __fastcall UFG::CollisionMeshBundleInventory::Add(
        UFG::CollisionMeshBundleInventory *this,
        UFG::CollisionMeshBundle *resource_data)
{
  if ( resource_data )
    UFG::CollisionMeshBundle::CollisionMeshBundle(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 56
// RVA: 0xAF4F0
void __fastcall UFG::CollisionMeshBundleInventory::Remove(
        UFG::CollisionMeshBundleInventory *this,
        UFG::CollisionMeshBundle *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::BasePhysicsSystem::mInstance->mForceRemoveEntitiesToBeBatched = 1;
  UFG::CollisionMeshBundle::~CollisionMeshBundle(resource_data);
  UFG::BasePhysicsSystem::EndRemoveEntityBatch(UFG::BasePhysicsSystem::mInstance);
}

// File Line: 86
// RVA: 0x9FB70
void __fastcall UFG::CollisionInstanceInventory::Add(
        UFG::CollisionInstanceInventory *this,
        UFG::CollisionInstanceResource *resource_data)
{
  UFG::BasePhysicsSystem *v4; // rsi
  __int64 i; // rdi

  if ( resource_data )
    UFG::CollisionInstanceResource::CollisionInstanceResource(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
  v4 = UFG::BasePhysicsSystem::mInstance;
  for ( i = 0i64; (unsigned int)i < resource_data->mNumInstances; i = (unsigned int)(i + 1) )
    (*((void (__fastcall **)(UFG::BasePhysicsSystem *, UFG::CollisionInstanceData *))&v4->vfptr->__vecDelDtor + 1))(
      v4,
      resource_data->mData[i]);
}

// File Line: 126
// RVA: 0xAF400
void __fastcall UFG::CollisionInstanceInventory::Remove(
        UFG::CollisionInstanceInventory *this,
        UFG::qResourceData *resource_data)
{
  __int64 i; // rbx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *j; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rax

  UFG::BasePhysicsSystem::mInstance->mForceRemoveEntitiesToBeBatched = 1;
  for ( i = 0i64; (unsigned int)i < LODWORD(resource_data[1].mNode.mChild[0]); i = (unsigned int)(i + 1) )
    UFG::BasePhysicsSystem::mInstance->vfptr->OnCollisionInstanceRemovedFromWorld(
      UFG::BasePhysicsSystem::mInstance,
      (UFG::CollisionInstanceData *)*((_QWORD *)&resource_data[1].mNode.mParent->mParent + i));
  UFG::BasePhysicsSystem::EndRemoveEntityBatch(UFG::BasePhysicsSystem::mInstance);
  UFG::qResourceInventory::Remove(this, resource_data);
  p_mResourceHandles = &resource_data->mResourceHandles;
  for ( j = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext;
        j != (UFG::qResourceHandle *)p_mResourceHandles;
        j = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext )
  {
    mPrev = j->mPrev;
    mNext = j->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    j->mPrev = j;
    j->mNext = j;
    UFG::qResourceHandle::~qResourceHandle(j);
    operator delete[](j);
  }
  v9 = p_mResourceHandles->mNode.mPrev;
  v10 = p_mResourceHandles->mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  p_mResourceHandles->mNode.mNext = &p_mResourceHandles->mNode;
}

// File Line: 147
// RVA: 0xAE100
void __fastcall UFG::CollisionInstanceInventory::OnDetachHandle(
        UFG::CollisionMeshBundleInventory *this,
        UFG::qResourceHandle *handle,
        UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx

  if ( !LOBYTE(handle[1].mNext) )
  {
    mPrev = handle[1].mPrev;
    if ( mPrev )
    {
      LOBYTE(handle[1].mNext) = 1;
      ((void (__fastcall *)(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *, UFG::qResourceHandle *, UFG::qResourceData *))mPrev->mPrev[1].mPrev)(
        mPrev,
        handle,
        data);
    }
  }
}

