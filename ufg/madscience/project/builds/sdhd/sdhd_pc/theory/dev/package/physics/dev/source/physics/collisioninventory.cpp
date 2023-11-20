// File Line: 31
// RVA: 0x1458EE0
__int64 UFG::_dynamic_initializer_for__gCollisionInstanceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gCollisionInstanceInventory.vfptr,
    "CollisionInstanceInventory",
    0x7970FB96u,
    0xA0B2CC13,
    0,
    0);
  UFG::gCollisionInstanceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::CollisionInstanceInventory::`vftable;
  return atexit(UFG::_dynamic_atexit_destructor_for__gCollisionInstanceInventory__);
}

// File Line: 32
// RVA: 0x1458F70
__int64 UFG::_dynamic_initializer_for__gCollisionMeshBundleInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gCollisionMeshBundleInventory.vfptr,
    "CollisionMeshBundleInventory",
    0x1723EA91u,
    0xBD226A08,
    0,
    0);
  UFG::gCollisionMeshBundleInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::CollisionMeshBundleInventory::`vftable;
  return atexit(UFG::_dynamic_atexit_destructor_for__gCollisionMeshBundleInventory__);
}

// File Line: 44
// RVA: 0x9FBF0
void __fastcall UFG::CollisionMeshBundleInventory::Add(UFG::CollisionMeshBundleInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::CollisionMeshBundleInventory *v3; // rdi

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::CollisionMeshBundle::CollisionMeshBundle((UFG::CollisionMeshBundle *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 56
// RVA: 0xAF4F0
void __fastcall UFG::CollisionMeshBundleInventory::Remove(UFG::CollisionMeshBundleInventory *this, UFG::qResourceData *resource_data)
{
  UFG::CollisionMeshBundle *v2; // rbx

  v2 = (UFG::CollisionMeshBundle *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::BasePhysicsSystem::mInstance->mForceRemoveEntitiesToBeBatched = 1;
  UFG::CollisionMeshBundle::~CollisionMeshBundle(v2);
  UFG::BasePhysicsSystem::EndRemoveEntityBatch(UFG::BasePhysicsSystem::mInstance);
}

// File Line: 86
// RVA: 0x9FB70
void __fastcall UFG::CollisionInstanceInventory::Add(UFG::CollisionInstanceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::CollisionInstanceResource *v2; // rbx
  UFG::CollisionInstanceInventory *v3; // rdi
  UFG::BasePhysicsSystem *v4; // rsi
  __int64 v5; // rdi

  v2 = (UFG::CollisionInstanceResource *)resource_data;
  v3 = this;
  if ( resource_data )
    UFG::CollisionInstanceResource::CollisionInstanceResource((UFG::CollisionInstanceResource *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v2->mNode);
  v4 = UFG::BasePhysicsSystem::mInstance;
  v5 = 0i64;
  if ( v2->mNumInstances )
  {
    do
    {
      (*((void (__fastcall **)(UFG::BasePhysicsSystem *, UFG::CollisionInstanceData *))&v4->vfptr->__vecDelDtor + 1))(
        v4,
        v2->mData[v5]);
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < v2->mNumInstances );
  }
}

// File Line: 126
// RVA: 0xAF400
void __fastcall UFG::CollisionInstanceInventory::Remove(UFG::CollisionInstanceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rdi
  UFG::CollisionInstanceInventory *v3; // rsi
  __int64 v4; // rbx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v5; // rdi
  UFG::qResourceHandle *i; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rax

  v2 = resource_data;
  v3 = this;
  UFG::BasePhysicsSystem::mInstance->mForceRemoveEntitiesToBeBatched = 1;
  v4 = 0i64;
  if ( LODWORD(resource_data[1].mNode.mChild[0]) )
  {
    do
    {
      UFG::BasePhysicsSystem::mInstance->vfptr->OnCollisionInstanceRemovedFromWorld(
        UFG::BasePhysicsSystem::mInstance,
        (UFG::CollisionInstanceData *)*((_QWORD *)&v2[1].mNode.mParent->mParent + v4));
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < LODWORD(v2[1].mNode.mChild[0]) );
  }
  UFG::BasePhysicsSystem::EndRemoveEntityBatch(UFG::BasePhysicsSystem::mInstance);
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&v3->vfptr, v2);
  v5 = &v2->mResourceHandles;
  for ( i = (UFG::qResourceHandle *)v5->mNode.mNext;
        i != (UFG::qResourceHandle *)v5;
        i = (UFG::qResourceHandle *)v5->mNode.mNext )
  {
    v7 = i->mPrev;
    v8 = i->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    i->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&i->mPrev;
    UFG::qResourceHandle::~qResourceHandle(i);
    operator delete[](i);
  }
  v9 = v5->mNode.mPrev;
  v10 = v5->mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
}

// File Line: 147
// RVA: 0xAE100
void __fastcall UFG::CollisionInstanceInventory::OnDetachHandle(UFG::CollisionMeshBundleInventory *this, UFG::qResourceHandle *handle, UFG::qResourceData *data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rcx

  if ( !LOBYTE(handle[1].mNext) )
  {
    v3 = handle[1].mPrev;
    if ( v3 )
    {
      LOBYTE(handle[1].mNext) = 1;
      ((void (__fastcall *)(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *, UFG::qResourceHandle *, UFG::qResourceData *))v3->mPrev[1].mPrev)(
        v3,
        handle,
        data);
    }
  }
}

