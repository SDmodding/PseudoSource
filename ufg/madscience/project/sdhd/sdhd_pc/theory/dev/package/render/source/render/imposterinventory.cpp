// File Line: 16
// RVA: 0x14542F0
__int64 Render::_dynamic_initializer_for__gImposterGroupInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Render::gImposterGroupInventory.vfptr,
    "ImposterGroupInventory",
    0x4E23B4B4u,
    0xAEDF1081,
    0,
    0);
  Render::gImposterGroupInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::ImposterGroupInventory::`vftable;
  Render::gImposterGroupInventory.mAddImposterGroupCallback = 0i64;
  Render::gImposterGroupInventory.mRemoveImposterGroupCallback = 0i64;
  return atexit(Render::_dynamic_atexit_destructor_for__gImposterGroupInventory__);
}

// File Line: 26
// RVA: 0x29550
void __fastcall Render::ImposterGroupInventory::Add(Render::ImposterGroupInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  Render::ImposterGroupInventory *v3; // rdi
  void (__fastcall *v4)(Render::ImposterGroup *); // rax

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
  v4 = v3->mAddImposterGroupCallback;
  if ( v4 )
    v4((Render::ImposterGroup *)v2);
}

// File Line: 41
// RVA: 0x295B0
void __fastcall Render::ImposterGroupInventory::Remove(Render::ImposterGroupInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  Render::ImposterGroupInventory *v3; // rdi
  void (__fastcall *v4)(Render::ImposterGroup *); // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v7; // [rsp+40h] [rbp+8h]

  v2 = resource_data;
  v3 = this;
  v4 = this->mRemoveImposterGroupCallback;
  if ( v4 )
    v4((Render::ImposterGroup *)resource_data);
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&v3->vfptr, v2);
  v7 = &v2->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v5 = v2->mResourceHandles.mNode.mPrev;
  v6 = v2->mResourceHandles.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
}

