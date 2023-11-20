// File Line: 16
// RVA: 0x14688F0
__int64 dynamic_initializer_for__gUniqueUIDTableResourceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&gUniqueUIDTableResourceInventory.vfptr,
    "UniqueUIDTableResourceInventory",
    0xEF00811C,
    0x2C40FA26u,
    0,
    0);
  gUniqueUIDTableResourceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UniqueUIDTableResourceInventory::`vftable;
  return atexit(dynamic_atexit_destructor_for__gUniqueUIDTableResourceInventory__);
}

// File Line: 24
// RVA: 0x18FFF0
void __fastcall UniqueUIDTableResourceInventory::Add(Illusion::LocatorsInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  Illusion::LocatorsInventory *v3; // rdi

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 36
// RVA: 0x1911A0
void __fastcall UniqueUIDTableResourceInventory::Remove(UniqueUIDTableResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v5; // [rsp+48h] [rbp+10h]

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v5 = &v2->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v3 = v2->mResourceHandles.mNode.mPrev;
  v4 = v2->mResourceHandles.mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
}

