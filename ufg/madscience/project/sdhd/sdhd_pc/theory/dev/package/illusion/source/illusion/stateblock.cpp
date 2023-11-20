// File Line: 16
// RVA: 0x14581F0
__int64 Illusion::_dynamic_initializer_for__gStateBlockInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gStateBlockInventory.vfptr,
    "StateBlockInventory",
    0x4D04C7F2u,
    0xAF015A94,
    0,
    0);
  Illusion::gStateBlockInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::StateBlockInventory::`vftable;
  stru_142167250.mNode.mPrev = (UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *)&stru_142167250;
  stru_142167250.mNode.mNext = (UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *)&stru_142167250;
  return atexit(Illusion::_dynamic_atexit_destructor_for__gStateBlockInventory__);
}

// File Line: 23
// RVA: 0x92690
UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *__fastcall Illusion::StateBlockInventory::GetStateBlock(Illusion::StateBlockInventory *this, unsigned int name_uid, int return_default_data)
{
  Illusion::StateBlockInventory *v3; // r10
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *result; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **v7; // r8
  UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *v8; // rcx

  v3 = this;
  result = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)&this->mBlockList.mNode.mNext[-6].mNext;
  if ( result == &this->mInternalUnresolvedHandles[2] )
  {
LABEL_4:
    if ( return_default_data )
      result = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)this->mDefaultResourceData;
    else
      result = 0i64;
  }
  else
  {
    while ( name_uid != HIDWORD(result[7].mNode.mPrev) )
    {
      result = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)&result[6].mNode.mPrev[-6].mNext;
      if ( result == &this->mInternalUnresolvedHandles[2] )
        goto LABEL_4;
    }
    v5 = result[5].mNode.mNext;
    v6 = result[6].mNode.mPrev;
    v7 = &result[5].mNode.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    *v7 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v7;
    v7[1] = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v7;
    v8 = v3->mBlockList.mNode.mNext;
    v3->mBlockList.mNode.mNext = (UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *)&result[5].mNode.mNext;
    *v7 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v3->mBlockList;
    v7[1] = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v8;
    v8->mPrev = (UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *)&result[5].mNode.mNext;
  }
  return result;
}

// File Line: 40
// RVA: 0x8DE00
void __fastcall Illusion::StateBlockInventory::Add(Illusion::StateBlockInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  Illusion::StateBlockInventory *v3; // rdi
  UFG::qResourceData *v4; // rax
  UFG::qResourceData *v5; // rcx
  UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *v6; // rax

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    v4 = v2 + 1;
    v4->mNode.mParent = &v4->mNode;
    v4->mNode.mChild[0] = &v4->mNode;
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
  v5 = v2 + 1;
  v6 = v3->mBlockList.mNode.mPrev;
  v6->mNext = (UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *)&v2[1];
  v5->mNode.mParent = (UFG::qBaseNodeRB *)v6;
  v5->mNode.mChild[0] = (UFG::qBaseNodeRB *)&v3->mBlockList;
  v3->mBlockList.mNode.mPrev = (UFG::qNode<Illusion::StateBlock,Illusion::StateBlock> *)&v2[1];
}

// File Line: 52
// RVA: 0x94950
void __fastcall Illusion::StateBlockInventory::Remove(Illusion::StateBlockInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qResourceData *v3; // r8
  UFG::qBaseNodeRB *v4; // rcx
  UFG::qBaseNodeRB *v5; // rax
  UFG::qBaseNodeRB *v6; // rcx
  UFG::qBaseNodeRB *v7; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v10; // [rsp+48h] [rbp+10h]

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3 = v2 + 1;
  v4 = v2[1].mNode.mParent;
  v5 = v2[1].mNode.mChild[0];
  v4->mChild[0] = v5;
  v5->mParent = v4;
  v3->mNode.mParent = &v3->mNode;
  v3->mNode.mChild[0] = &v3->mNode;
  v6 = v2[1].mNode.mParent;
  v7 = v2[1].mNode.mChild[0];
  v6->mChild[0] = v7;
  v7->mParent = v6;
  v3->mNode.mParent = &v3->mNode;
  v2[1].mNode.mChild[0] = &v2[1].mNode;
  v10 = &v2->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v8 = v2->mResourceHandles.mNode.mPrev;
  v9 = v2->mResourceHandles.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v10->mNode.mPrev = &v10->mNode;
  v10->mNode.mNext = &v10->mNode;
}

