// File Line: 12
// RVA: 0x14702D0
__int64 UFG::_dynamic_initializer_for__gReflectionGroupInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gReflectionGroupInventory,
    "ReflectionGroupInventory",
    0xEFAA9CC0,
    0xD53B5BAC,
    0,
    0);
  UFG::gReflectionGroupInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ReflectionGroupInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gReflectionGroupInventory__);
}

// File Line: 32
// RVA: 0x234DC0
void __fastcall UFG::UIScreenInventory::Remove(UFG::ReflectionGroupInventory *this, UFG::qResourceData *resource_data)
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

