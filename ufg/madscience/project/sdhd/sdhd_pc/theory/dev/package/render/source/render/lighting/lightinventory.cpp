// File Line: 17
// RVA: 0x1454220
__int64 Render::_dynamic_initializer_for__gLightGroupInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Render::gLightGroupInventory.vfptr,
    "LightGroupInventory",
    0xF0A0724F,
    0x7480E00Fu,
    0,
    0);
  Render::gLightGroupInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::LightGroupInventory::`vftable;
  uid = 0;
  UFG::qBaseTreeRB::qBaseTreeRB(&stru_142135078);
  return atexit(Render::_dynamic_atexit_destructor_for__gLightGroupInventory__);
}

// File Line: 26
// RVA: 0x28A40
void __fastcall Render::LightGroupInventory::Add(Render::LightGroupInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  Render::LightGroupInventory *v3; // rbp
  unsigned int v4; // edi
  unsigned int v5; // esi
  UFG::qBaseTreeRB *v6; // rax
  char *v7; // rbx

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
  v4 = UFG::Metrics::msFrameCount;
  v5 = v2->mNode.mUID;
  if ( v5 && (v6 = UFG::qBaseTreeRB::Get(&v3->mLightGroupFrameStamp.mTree.mTree, v5)) != 0i64 )
  {
    LODWORD(v6->mNULL.mParent) = v4;
  }
  else
  {
    v7 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
    if ( v7 )
    {
      *(_QWORD *)v7 = 0i64;
      *((_QWORD *)v7 + 1) = 0i64;
      *((_QWORD *)v7 + 2) = 0i64;
      *((_DWORD *)v7 + 6) = v5;
      *((_DWORD *)v7 + 8) = v4;
    }
    else
    {
      v7 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&v3->mLightGroupFrameStamp.mTree.mTree, (UFG::qBaseNodeRB *)v7);
    *((_DWORD *)v7 + 8) = v4;
  }
}

// File Line: 40
// RVA: 0x28B00
void __fastcall Render::LightGroupInventory::Remove(Render::LightGroupInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rdi
  Render::LightGroupInventory *v3; // rsi
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseTreeRB *v6; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax

  v2 = resource_data;
  v3 = this;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v4 = v2->mNode.mUID;
  if ( v4 )
  {
    v5 = UFG::qBaseTreeRB::Get(&v3->mLightGroupFrameStamp.mTree.mTree, v4);
    v6 = v5;
    if ( v5 )
    {
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mLightGroupFrameStamp,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)v5);
      operator delete[](v6);
    }
  }
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v7 = v2->mResourceHandles.mNode.mPrev;
  v8 = v2->mResourceHandles.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mResourceHandles.mNode.mPrev = &v2->mResourceHandles.mNode;
  v2->mResourceHandles.mNode.mNext = &v2->mResourceHandles.mNode;
}

