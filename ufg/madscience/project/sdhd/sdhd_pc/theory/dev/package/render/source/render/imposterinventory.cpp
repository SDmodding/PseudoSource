// File Line: 16
// RVA: 0x14542F0
__int64 Render::_dynamic_initializer_for__gImposterGroupInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gImposterGroupInventory,
    "ImposterGroupInventory",
    0x4E23B4B4u,
    0xAEDF1081,
    0,
    0);
  Render::gImposterGroupInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::ImposterGroupInventory::`vftable;
  Render::gImposterGroupInventory.mAddImposterGroupCallback = 0i64;
  Render::gImposterGroupInventory.mRemoveImposterGroupCallback = 0i64;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gImposterGroupInventory__);
}

// File Line: 26
// RVA: 0x29550
void __fastcall Render::ImposterGroupInventory::Add(
        Render::ImposterGroupInventory *this,
        Render::ImposterGroup *resource_data)
{
  void (__fastcall *mAddImposterGroupCallback)(Render::ImposterGroup *); // rax

  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
  mAddImposterGroupCallback = this->mAddImposterGroupCallback;
  if ( mAddImposterGroupCallback )
    mAddImposterGroupCallback(resource_data);
}

// File Line: 41
// RVA: 0x295B0
void __fastcall Render::ImposterGroupInventory::Remove(
        Render::ImposterGroupInventory *this,
        Render::ImposterGroup *resource_data)
{
  void (__fastcall *mRemoveImposterGroupCallback)(Render::ImposterGroup *); // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  mRemoveImposterGroupCallback = this->mRemoveImposterGroupCallback;
  if ( mRemoveImposterGroupCallback )
    mRemoveImposterGroupCallback(resource_data);
  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&resource_data->mResourceHandles);
  mPrev = resource_data->mResourceHandles.UFG::qResourceData::mNode.mPrev;
  mNext = resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  resource_data->mResourceHandles.UFG::qResourceData::mNode.mPrev = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
  resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
}

