// File Line: 16
// RVA: 0x14688F0
__int64 dynamic_initializer_for__gUniqueUIDTableResourceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &gUniqueUIDTableResourceInventory,
    "UniqueUIDTableResourceInventory",
    0xEF00811C,
    0x2C40FA26u,
    0,
    0);
  gUniqueUIDTableResourceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UniqueUIDTableResourceInventory::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gUniqueUIDTableResourceInventory__);
}

// File Line: 24
// RVA: 0x18FFF0
void __fastcall UniqueUIDTableResourceInventory::Add(
        Illusion::LocatorsInventory *this,
        UFG::qResourceData *resource_data)
{
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 36
// RVA: 0x1911A0
void __fastcall UniqueUIDTableResourceInventory::Remove(
        UniqueUIDTableResourceInventory *this,
        UFG::qResourceData *resource_data)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&resource_data->mResourceHandles);
  mPrev = resource_data->mResourceHandles.mNode.mPrev;
  mNext = resource_data->mResourceHandles.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  resource_data->mResourceHandles.mNode.mPrev = &resource_data->mResourceHandles.mNode;
  resource_data->mResourceHandles.mNode.mNext = &resource_data->mResourceHandles.mNode;
}

