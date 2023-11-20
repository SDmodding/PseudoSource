// File Line: 48
// RVA: 0x3E4490
void __fastcall Render::FXSettingsInventoryTemplate<Render::DecalSettings,2922524998,3702441219>::Remove(Render::TrackStripSettingsInventory *this, UFG::qResourceData *resource_data)
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

// File Line: 56
// RVA: 0x14CF0E0
__int64 UFG::_dynamic_initializer_for__gNISSpatialDataInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gNISSpatialDataInventory.vfptr,
    "NISSpatialDataInventory",
    0x59362AA3u,
    0xC762C801,
    0,
    0);
  UFG::gNISSpatialDataInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::NISSpatialDataInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gNISSpatialDataInventory__);
}

