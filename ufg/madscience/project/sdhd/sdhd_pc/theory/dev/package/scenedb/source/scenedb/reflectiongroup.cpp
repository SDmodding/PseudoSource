// File Line: 12
// RVA: 0x14702D0
__int64 UFG::_dynamic_initializer_for__gReflectionGroupInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gReflectionGroupInventory.vfptr,
    "ReflectionGroupInventory",
    0xEFAA9CC0,
    0xD53B5BAC,
    0,
    0);
  UFG::gReflectionGroupInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ReflectionGroupInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gReflectionGroupInventory__);
}

// File Line: 32
// RVA: 0x234DC0
void __fastcall UFG::UIScreenInventory::Remove(UFG::ReflectionGroupInventory *this, UFG::qResourceData *resource_data)
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

