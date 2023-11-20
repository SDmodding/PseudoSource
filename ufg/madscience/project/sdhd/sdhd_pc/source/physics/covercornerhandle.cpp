// File Line: 10
// RVA: 0x4497E0
void __fastcall UFG::CoverCornerHandle::CoverCornerHandle(UFG::CoverCornerHandle *this)
{
  UFG::CoverCornerHandle *v1; // rbx
  UFG::qSafePointer<UFG::DynamicCoverCorner,UFG::DynamicCoverCorner> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->m_ResourceHandle.mPrev);
  v2 = &v1->m_pDynamicCoverCorner;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->m_pDynamicCoverCorner.m_pPointer = 0i64;
  v1->m_uCoverCornerIndex = -1;
}

// File Line: 15
// RVA: 0x449670
void __fastcall UFG::CoverCornerHandle::CoverCornerHandle(UFG::CoverCornerHandle *this, UFG::CoverCorner *pCorner)
{
  UFG::CoverCorner *v2; // rbp
  UFG::CoverCornerHandle *v3; // rsi
  UFG::qResourceHandle *v4; // r14
  UFG::qSafePointer<UFG::DynamicCoverCorner,UFG::DynamicCoverCorner> *v5; // r8
  signed __int64 v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::CoverDataInventory *v10; // rax
  Render::SkinningCacheNode *v11; // rbx
  UFG::CoverDataInventory *v12; // rax
  UFG::qBaseTreeRB *v13; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> *v14; // rax
  unsigned __int64 v15; // rdi
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax

  v2 = pCorner;
  v3 = this;
  v4 = (UFG::qResourceHandle *)&this->m_ResourceHandle.mPrev;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->m_ResourceHandle.mPrev);
  v5 = &v3->m_pDynamicCoverCorner;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v3->m_pDynamicCoverCorner.m_pPointer = 0i64;
  if ( v2->m_IsDynamic )
  {
    v6 = (signed __int64)&v2[-1].m_vCornerPosition.z;
    if ( v3->m_pDynamicCoverCorner.m_pPointer )
    {
      v7 = v5->mPrev;
      v8 = v3->m_pDynamicCoverCorner.mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      v3->m_pDynamicCoverCorner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v3->m_pDynamicCoverCorner.mPrev;
    }
    v3->m_pDynamicCoverCorner.m_pPointer = (UFG::DynamicCoverCorner *)v6;
    if ( v2 != (UFG::CoverCorner *)24 )
    {
      v9 = *(UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> **)(v6 + 8);
      v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      v5->mPrev = v9;
      v3->m_pDynamicCoverCorner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)(v6 + 8);
      *(_QWORD *)(v6 + 8) = v5;
    }
    goto LABEL_15;
  }
  UFG::CoverDataInventory::GetInstance();
  v10 = UFG::CoverDataInventory::GetInstance();
  v11 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v10->mResourceDatas);
  if ( !v11 )
  {
LABEL_15:
    v3->m_uCoverCornerIndex = -1;
    return;
  }
  while ( 1 )
  {
    v12 = UFG::CoverDataInventory::GetInstance();
    v13 = UFG::qBaseTreeRB::GetNext(&v12->mResourceDatas.mTree, (UFG::qBaseNodeRB *)v11);
    v14 = v11[2].mNode.mChild[1];
    if ( v14 )
      v14 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((char *)v14 + (_QWORD)v11 + 96);
    v15 = ((unsigned __int64)((unsigned __int128)(((char *)v2 - (char *)v14) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
        + ((signed __int64)((unsigned __int128)(((char *)v2 - (char *)v14) * (signed __int128)3074457345618258603i64) >> 64) >> 3);
    if ( (unsigned int)v15 < HIDWORD(v11[2].mNode.mChild0) )
      break;
    v11 = (Render::SkinningCacheNode *)v13;
    if ( !v13 )
      goto LABEL_15;
  }
  v16 = `UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result )
  {
    v17 = UFG::qResourceWarehouse::Instance();
    v16 = UFG::qResourceWarehouse::GetInventory(v17, 0x8DADDB7E);
    `UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result = v16;
  }
  UFG::qResourceHandle::Init(v4, 0x8DADDB7E, v11->mNode.mUID, v16);
  v3->m_uCoverCornerIndex = v15;
}e::Init(v4, 0x8DADDB7E, v11->mNode.mUID, v16);
  v3-

// File Line: 65
// RVA: 0x4527A0
UFG::CoverCornerHandle *__fastcall UFG::CoverCornerHandle::operator=(UFG::CoverCornerHandle *this, UFG::CoverCornerHandle *rhs)
{
  UFG::CoverCornerHandle *v2; // rbx
  UFG::CoverCornerHandle *v3; // rdi
  UFG::qResourceData *v4; // rax
  unsigned int v5; // esi
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::DynamicCoverCorner *v10; // r8
  UFG::qSafePointer<UFG::DynamicCoverCorner,UFG::DynamicCoverCorner> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v14; // rax

  v2 = this;
  v3 = rhs;
  UFG::CoverCornerHandle::Reset(this);
  v2->m_uCoverCornerIndex = v3->m_uCoverCornerIndex;
  v4 = v3->m_ResourceHandle.mData;
  if ( v4 )
  {
    v5 = v4->mNode.mUID;
    v6 = `UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x8DADDB7E);
      `UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result = v6;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->m_ResourceHandle.mPrev, 0x8DADDB7E, v5, v6);
  }
  else
  {
    v8 = `UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x8DADDB7E);
      `UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result = v8;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->m_ResourceHandle.mPrev, v8);
  }
  v10 = v3->m_pDynamicCoverCorner.m_pPointer;
  v11 = &v2->m_pDynamicCoverCorner;
  if ( v2->m_pDynamicCoverCorner.m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v2->m_pDynamicCoverCorner.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v2->m_pDynamicCoverCorner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v2->m_pDynamicCoverCorner.mPrev;
  }
  v2->m_pDynamicCoverCorner.m_pPointer = v10;
  if ( v10 )
  {
    v14 = v10->m_SafePointerList.mNode.mPrev;
    v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v11->mPrev = v14;
    v2->m_pDynamicCoverCorner.mNext = &v10->m_SafePointerList.mNode;
    v10->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  }
  return v2;
}

// File Line: 86
// RVA: 0x452890
UFG::CoverCornerHandle *__fastcall UFG::CoverCornerHandle::operator=(UFG::CoverCornerHandle *this, UFG::CoverCorner *pCorner)
{
  UFG::CoverCornerHandle *v2; // rbx
  UFG::CoverCornerHandle *v3; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::CoverCornerHandle rhs; // [rsp+30h] [rbp-48h]

  v2 = this;
  UFG::CoverCornerHandle::CoverCornerHandle(&rhs, pCorner);
  v3 = UFG::CoverCornerHandle::operator=(v2, &rhs);
  if ( rhs.m_pDynamicCoverCorner.m_pPointer )
  {
    v4 = rhs.m_pDynamicCoverCorner.mPrev;
    v5 = rhs.m_pDynamicCoverCorner.mNext;
    rhs.m_pDynamicCoverCorner.mPrev->mNext = rhs.m_pDynamicCoverCorner.mNext;
    v5->mPrev = v4;
    rhs.m_pDynamicCoverCorner.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&rhs.m_pDynamicCoverCorner.mPrev;
    rhs.m_pDynamicCoverCorner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&rhs.m_pDynamicCoverCorner.mPrev;
  }
  rhs.m_pDynamicCoverCorner.m_pPointer = 0i64;
  v6 = rhs.m_pDynamicCoverCorner.mPrev;
  v7 = rhs.m_pDynamicCoverCorner.mNext;
  rhs.m_pDynamicCoverCorner.mPrev->mNext = rhs.m_pDynamicCoverCorner.mNext;
  v7->mPrev = v6;
  rhs.m_pDynamicCoverCorner.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&rhs.m_pDynamicCoverCorner.mPrev;
  rhs.m_pDynamicCoverCorner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DynamicCoverCorner>,UFG::qSafePointerNodeList> *)&rhs.m_pDynamicCoverCorner.mPrev;
  v8 = `UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x8DADDB7E);
    `UFG::qGetResourceInventory<UFG::CoverDataResource>'::`2'::result = v8;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&rhs.m_ResourceHandle.mPrev, v8);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&rhs.m_ResourceHandle.mPrev);
  return v3;
}

