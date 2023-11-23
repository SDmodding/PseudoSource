// File Line: 48
// RVA: 0x3E4490
void __fastcall Render::FXSettingsInventoryTemplate<Render::DecalSettings,2922524998,3702441219>::Remove(
        Render::TrackStripSettingsInventory *this,
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

// File Line: 56
// RVA: 0x14CF0E0
__int64 UFG::_dynamic_initializer_for__gNISSpatialDataInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gNISSpatialDataInventory,
    "NISSpatialDataInventory",
    0x59362AA3u,
    0xC762C801,
    0,
    0);
  UFG::gNISSpatialDataInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::NISSpatialDataInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gNISSpatialDataInventory__);
}

