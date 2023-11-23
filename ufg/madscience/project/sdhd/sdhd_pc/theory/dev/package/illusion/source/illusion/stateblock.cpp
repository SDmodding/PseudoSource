// File Line: 16
// RVA: 0x14581F0
__int64 Illusion::_dynamic_initializer_for__gStateBlockInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gStateBlockInventory,
    "StateBlockInventory",
    0x4D04C7F2u,
    0xAF015A94,
    0,
    0);
  Illusion::gStateBlockInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::StateBlockInventory::`vftable;
  stru_142167250.mNode.mPrev = (UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *)&stru_142167250;
  stru_142167250.mNode.mNext = (UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *)&stru_142167250;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gStateBlockInventory__);
}

// File Line: 23
// RVA: 0x92690
UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *__fastcall Illusion::StateBlockInventory::GetStateBlock(
        Illusion::StateBlockInventory *this,
        unsigned int name_uid,
        int return_default_data)
{
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *result; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rcx

  result = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)&this->mBlockList.mNode.mNext[-6].mNext;
  if ( result == &this->mInternalUnresolvedHandles[2] )
  {
LABEL_4:
    if ( return_default_data )
      return (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)this->mDefaultResourceData;
    else
      return 0i64;
  }
  else
  {
    while ( name_uid != HIDWORD(result[7].mNode.mPrev) )
    {
      result = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)&result[6].mNode.mPrev[-6].mNext;
      if ( result == &this->mInternalUnresolvedHandles[2] )
        goto LABEL_4;
    }
    mNext = result[5].mNode.mNext;
    mPrev = result[6].mNode.mPrev;
    mNext->mNext = mPrev;
    mPrev->mPrev = mNext;
    result[5].mNode.mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&result[5].mNode.mNext;
    result[6].mNode.mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&result[5].mNode.mNext;
    v7 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)this->mBlockList.mNode.mNext;
    this->mBlockList.mNode.mNext = (UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *)&result[5].mNode.mNext;
    result[5].mNode.mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&this->mBlockList;
    result[6].mNode.mPrev = v7;
    v7->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&result[5].mNode.mNext;
  }
  return result;
}

// File Line: 40
// RVA: 0x8DE00
void __fastcall Illusion::StateBlockInventory::Add(
        Illusion::StateBlockInventory *this,
        UFG::qResourceData *resource_data)
{
  UFG::qBaseNodeRB *mPrev; // rax

  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    resource_data[1].mNode.mParent = &resource_data[1].mNode;
    resource_data[1].mNode.mChild[0] = &resource_data[1].mNode;
  }
  UFG::qResourceInventory::Add(this, resource_data);
  mPrev = (UFG::qBaseNodeRB *)this->mBlockList.mNode.mPrev;
  mPrev->mChild[0] = &resource_data[1].mNode;
  resource_data[1].mNode.mParent = mPrev;
  resource_data[1].mNode.mChild[0] = (UFG::qBaseNodeRB *)&this->mBlockList;
  this->mBlockList.mNode.mPrev = (UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *)&resource_data[1];
}

// File Line: 52
// RVA: 0x94950
void __fastcall Illusion::StateBlockInventory::Remove(
        Illusion::StateBlockInventory *this,
        UFG::qResourceData *resource_data)
{
  UFG::qBaseNodeRB *mParent; // rcx
  UFG::qBaseNodeRB *v4; // rax
  UFG::qBaseNodeRB *v5; // rcx
  UFG::qBaseNodeRB *v6; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax

  UFG::qResourceInventory::Remove(this, resource_data);
  mParent = resource_data[1].mNode.mParent;
  v4 = resource_data[1].mNode.mChild[0];
  mParent->mChild[0] = v4;
  v4->mParent = mParent;
  resource_data[1].mNode.mParent = &resource_data[1].mNode;
  resource_data[1].mNode.mChild[0] = &resource_data[1].mNode;
  v5 = resource_data[1].mNode.mParent;
  v6 = resource_data[1].mNode.mChild[0];
  v5->mChild[0] = v6;
  v6->mParent = v5;
  resource_data[1].mNode.mParent = &resource_data[1].mNode;
  resource_data[1].mNode.mChild[0] = &resource_data[1].mNode;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&resource_data->mResourceHandles);
  mPrev = resource_data->mResourceHandles.mNode.mPrev;
  mNext = resource_data->mResourceHandles.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  resource_data->mResourceHandles.mNode.mPrev = &resource_data->mResourceHandles.mNode;
  resource_data->mResourceHandles.mNode.mNext = &resource_data->mResourceHandles.mNode;
}

