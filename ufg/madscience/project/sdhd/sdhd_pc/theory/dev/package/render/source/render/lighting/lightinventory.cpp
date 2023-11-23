// File Line: 17
// RVA: 0x1454220
__int64 Render::_dynamic_initializer_for__gLightGroupInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Render::gLightGroupInventory,
    "LightGroupInventory",
    0xF0A0724F,
    0x7480E00Fu,
    0,
    0);
  Render::gLightGroupInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Render::LightGroupInventory::`vftable;
  uid = 0;
  UFG::qBaseTreeRB::qBaseTreeRB(&stru_142135078);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gLightGroupInventory__);
}

// File Line: 26
// RVA: 0x28A40
void __fastcall Render::LightGroupInventory::Add(Render::LightGroupInventory *this, UFG::qResourceData *resource_data)
{
  unsigned int v4; // edi
  unsigned int mUID; // esi
  UFG::qBaseTreeRB *v6; // rax
  char *v7; // rbx

  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
  v4 = UFG::Metrics::msFrameCount;
  mUID = resource_data->mNode.mUID;
  if ( mUID && (v6 = UFG::qBaseTreeRB::Get(&this->mLightGroupFrameStamp.mTree.mTree, mUID)) != 0i64 )
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
      *((_DWORD *)v7 + 6) = mUID;
      *((_DWORD *)v7 + 8) = v4;
    }
    else
    {
      v7 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&this->mLightGroupFrameStamp.mTree.mTree, (UFG::qBaseNodeRB *)v7);
    *((_DWORD *)v7 + 8) = v4;
  }
}

// File Line: 40
// RVA: 0x28B00
void __fastcall Render::LightGroupInventory::Remove(
        Render::LightGroupInventory *this,
        UFG::qResourceData *resource_data)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseTreeRB *v6; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  UFG::qResourceInventory::Remove(this, resource_data);
  mUID = resource_data->mNode.mUID;
  if ( mUID )
  {
    v5 = UFG::qBaseTreeRB::Get(&this->mLightGroupFrameStamp.mTree.mTree, mUID);
    v6 = v5;
    if ( v5 )
    {
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mLightGroupFrameStamp,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)v5);
      operator delete[](v6);
    }
  }
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&resource_data->mResourceHandles);
  mPrev = resource_data->mResourceHandles.mNode.mPrev;
  mNext = resource_data->mResourceHandles.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  resource_data->mResourceHandles.mNode.mPrev = &resource_data->mResourceHandles.mNode;
  resource_data->mResourceHandles.mNode.mNext = &resource_data->mResourceHandles.mNode;
}

