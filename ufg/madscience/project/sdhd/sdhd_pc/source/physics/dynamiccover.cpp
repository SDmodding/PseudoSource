// File Line: 22
// RVA: 0x1514310
__int64 dynamic_initializer_for__UFG::DynamicCoverComponent::s_DynamicCoverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::DynamicCoverComponent::s_DynamicCoverComponentList__);
}

// File Line: 23
// RVA: 0x468070
const char *__fastcall UFG::DynamicCoverComponent::GetTypeName(UFG::DynamicCoverComponent *this)
{
  return "DynamicCoverComponent";
}

// File Line: 31
// RVA: 0x449830
void __fastcall UFG::DynamicCoverComponent::DynamicCoverComponent(UFG::DynamicCoverComponent *this, unsigned int name_uid)
{
  unsigned int v2; // ebp
  UFG::DynamicCoverComponent *v3; // rdi
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *v4; // rbx
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *v5; // rax
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  unsigned __int64 v8; // rcx
  int v9; // ebp
  signed __int64 v10; // rax
  unsigned __int8 v11; // cf
  unsigned __int64 v12; // rax
  UFG::allocator::free_link *v13; // rax
  unsigned int v14; // ebx
  signed __int64 v15; // rsi

  v2 = name_uid;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v4 = (UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DynamicCoverComponent::`vftable';
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mDynamicCoverGroup.mPrev);
  v3->m_TransformNodeChangeID = -1;
  v3->mEnabled = 1;
  v5 = UFG::DynamicCoverComponent::s_DynamicCoverComponentList.mNode.mPrev;
  UFG::DynamicCoverComponent::s_DynamicCoverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *)&UFG::DynamicCoverComponent::s_DynamicCoverComponentList;
  UFG::DynamicCoverComponent::s_DynamicCoverComponentList.mNode.mPrev = (UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::DynamicCoverComponent::_DynamicCoverComponentTypeUID,
    "DynamicCoverComponent");
  v6 = `UFG::qGetResourceInventory<UFG::DynamicCoverGroup>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::DynamicCoverGroup>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0xE5150EE3);
    `UFG::qGetResourceInventory<UFG::DynamicCoverGroup>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mDynamicCoverGroup.mPrev, 0xE5150EE3, v2, v6);
  v8 = LODWORD(v3->mDynamicCoverGroup.mData[1].mNode.mParent);
  v3->m_uNumCorners = v8;
  v9 = v8;
  v10 = 104 * v8;
  if ( !is_mul_ok(v8, 0x68ui64) )
    v10 = -1i64;
  v11 = __CFADD__(v10, 8i64);
  v12 = v10 + 8;
  if ( v11 )
    v12 = -1i64;
  v13 = UFG::qMalloc(v12, "DynamicCoverCorner", 0i64);
  v14 = 0;
  if ( v13 )
  {
    LODWORD(v13->mNext) = v9;
    v15 = (signed __int64)&v13[1];
    `eh vector constructor iterator'(
      &v13[1],
      0x68ui64,
      v9,
      (void (__fastcall *)(void *))UFG::DynamicCoverCorner::DynamicCoverCorner);
  }
  else
  {
    v15 = 0i64;
  }
  v3->m_aDynamicCoverCorners = (UFG::DynamicCoverCorner *)v15;
  if ( v3->m_uNumCorners )
  {
    do
    {
      UFG::DynamicCoverCorner::Init(&v3->m_aDynamicCoverCorners[v14], v3, v14);
      ++v14;
    }
    while ( v14 < v3->m_uNumCorners );
  }
}

// File Line: 50
// RVA: 0x44FCB0
void __fastcall UFG::DynamicCoverComponent::~DynamicCoverComponent(UFG::DynamicCoverComponent *this)
{
  UFG::DynamicCoverComponent *v1; // rbx
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *v2; // rdi
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *v3; // rcx
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *v4; // rax
  UFG::DynamicCoverCorner *v5; // rcx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *v8; // rcx
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DynamicCoverComponent::`vftable';
  if ( this == UFG::DynamicCoverComponent::s_DynamicCoverComponentpCurrentIterator )
    UFG::DynamicCoverComponent::s_DynamicCoverComponentpCurrentIterator = (UFG::DynamicCoverComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->m_aDynamicCoverCorners;
  if ( v5 )
  {
    if ( v5[-1].m_uGroupIndex )
      v5->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::DynamicCoverCorner> *)&v5->vfptr, 3u);
    else
      operator delete[](&v5[-1].m_uGroupIndex);
  }
  v6 = `UFG::qGetResourceInventory<UFG::DynamicCoverGroup>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::DynamicCoverGroup>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0xE5150EE3);
    `UFG::qGetResourceInventory<UFG::DynamicCoverGroup>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mDynamicCoverGroup.mPrev, v6);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mDynamicCoverGroup.mPrev);
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 59
// RVA: 0x461D20
void __fastcall UFG::DynamicCoverComponent::DisableCoverCorners(UFG::DynamicCoverComponent *this)
{
  this->mEnabled = 0;
}

// File Line: 66
// RVA: 0x46AEC0
bool __fastcall UFG::DynamicCoverComponent::IsEnabled(UFG::DynamicCoverComponent *this)
{
  UFG::TransformNodeComponent *v1; // rbx
  UFG::DynamicCoverComponent *v2; // rdi
  UFG::qMatrix44 *v3; // rbx

  v1 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  v2 = this;
  if ( v1 )
    v1 = (UFG::TransformNodeComponent *)v1->mChildren.mNode.mNext;
  if ( v1 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v1);
    v3 = &v1->mWorldTransform;
  }
  else
  {
    v3 = &UFG::qMatrix44::msIdentity;
  }
  return v2->mEnabled && v3->v2.z > 0.89999998;
}

// File Line: 103
// RVA: 0x477B90
void __fastcall UFG::DynamicCoverComponent::Update(UFG::DynamicCoverComponent *this, float __formal)
{
  UFG::DynamicCoverComponent *v2; // rdi
  UFG::SimObject *v3; // rbx
  unsigned int v4; // esi
  UFG::TransformNodeComponent *v5; // rbx
  unsigned int v6; // eax
  float v7; // xmm8_4
  float v8; // xmm9_4
  float v9; // xmm14_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm15_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  UFG::qBaseNodeRB *v15; // rcx
  signed __int64 v16; // rbx
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm7_4
  float v24; // xmm6_4
  UFG::CoverDataInventory *v25; // rax
  __int64 v26; // rdx
  _QWORD *v27; // rcx
  signed __int64 v28; // r9
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> **v29; // r8
  float v30; // xmm6_4
  UFG::qList<UFG::CoverCorner,UFG::CoverCorner,1,0> *v31; // rdx
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *v32; // rax
  float v33; // [rsp+20h] [rbp-C8h]
  float v34; // [rsp+F0h] [rbp+8h]
  float v35; // [rsp+100h] [rbp+18h]
  float v36; // [rsp+108h] [rbp+20h]

  v2 = this;
  if ( this->mDynamicCoverGroup.mData )
  {
    v3 = this->m_pSimObject;
    v4 = 0;
    if ( v3 )
      v5 = v3->m_pTransformNodeComponent;
    else
      v5 = 0i64;
    if ( v5 )
    {
      v6 = v5->mChangeID;
      if ( v6 != this->m_TransformNodeChangeID )
      {
        this->m_TransformNodeChangeID = v6;
        UFG::TransformNodeComponent::UpdateWorldTransform(v5);
        v7 = v5->mWorldTransform.v0.x;
        v8 = v5->mWorldTransform.v0.y;
        v9 = v5->mWorldTransform.v0.z;
        v10 = v5->mWorldTransform.v1.x;
        v11 = v5->mWorldTransform.v1.y;
        v12 = v5->mWorldTransform.v1.z;
        v13 = v5->mWorldTransform.v2.x;
        v14 = v5->mWorldTransform.v2.y;
        v36 = v5->mWorldTransform.v2.z;
        v34 = v5->mWorldTransform.v3.x;
        v35 = v5->mWorldTransform.v3.y;
        v33 = v5->mWorldTransform.v3.z;
        if ( v2->m_uNumCorners > 0 )
        {
          do
          {
            v15 = v2->mDynamicCoverGroup.mData[1].mNode.mChild[1];
            v16 = (signed __int64)&v2->m_aDynamicCoverCorners[v4];
            v17 = v11 * *((float *)&v15->mChild[1] + 9 * v4);
            v18 = v8 * *((float *)v15->mChild + 9 * v4 + 1);
            v19 = v14 * *((float *)&v15->mChild[1] + 9 * v4 + 1);
            *(float *)(v16 + 52) = (float)((float)(v7 * *((float *)v15->mChild + 9 * v4 + 1))
                                         + (float)(v10 * *((float *)&v15->mChild[1] + 9 * v4)))
                                 + (float)(v13 * *((float *)&v15->mChild[1] + 9 * v4 + 1));
            *(float *)(v16 + 56) = (float)(v18 + v17) + v19;
            v20 = *((float *)&v15->mParent + 9 * v4);
            v21 = *((float *)&v15->mParent + 9 * v4 + 1);
            v22 = *((float *)v15->mChild + 9 * v4);
            v23 = (float)((float)((float)(v7 * v20) + (float)(v10 * v21)) + (float)(v13 * v22)) + v34;
            v24 = (float)((float)((float)(v8 * v20) + (float)(v11 * v21)) + (float)(v14 * v22)) + v35;
            *(float *)(v16 + 40) = v23;
            *(float *)(v16 + 44) = v24;
            *(float *)(v16 + 48) = (float)((float)((float)(v9 * v20) + (float)(v12 * v21)) + (float)(v36 * v22)) + v33;
            v25 = UFG::CoverDataInventory::GetInstance();
            v26 = *(_QWORD *)(v16 + 24);
            v27 = *(_QWORD **)(v16 + 32);
            *(_QWORD *)(v26 + 8) = v27;
            *v27 = v26;
            v28 = (signed __int64)&v25->m_CornerGrid;
            v29 = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> **)(v16 + 24);
            *v29 = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)v29;
            v29[1] = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)v29;
            v30 = v24 - v25->m_CornerGrid.mYMin;
            --*(_DWORD *)(v28 + 40);
            v31 = &v25->m_CornerGrid.mGridNodes[(signed int)(float)((float)(v23 - v25->m_CornerGrid.mXMin)
                                                                  * v25->m_CornerGrid.mGridSizeInv)
                                              + v25->m_CornerGrid.mXDim
                                              * (signed int)(float)(v30 * v25->m_CornerGrid.mGridSizeInv)];
            v32 = v31->mNode.mPrev;
            v32->mNext = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)(v16 + 24);
            *v29 = v32;
            v29[1] = &v31->mNode;
            v31->mNode.mPrev = (UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *)(v16 + 24);
            ++*(_DWORD *)(v28 + 40);
            ++v4;
          }
          while ( v4 < v2->m_uNumCorners );
        }
      }
    }
  }
}

// File Line: 144
// RVA: 0x468190
UFG::qVector3 *__fastcall UFG::DynamicCoverComponent::GetVelocity(UFG::DynamicCoverComponent *this)
{
  UFG::TransformNodeComponent *v1; // rbx

  v1 = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( v1 )
    v1 = (UFG::TransformNodeComponent *)v1->mChildren.mNode.mNext;
  if ( !v1 )
    return &UFG::qVector3::msZero;
  UFG::TransformNodeComponent::UpdateWorldTransform(v1);
  return &v1->mWorldVelocity;
}

// File Line: 222
// RVA: 0x44FE80
void __fastcall UFG::DynamicCoverGroupBundle::~DynamicCoverGroupBundle(UFG::DynamicCoverGroupBundle *this)
{
  UFG::DynamicCoverGroupBundle *v1; // rdi
  __int64 v2; // rbx
  UFG::qOffset64<UFG::DynamicCoverGroup *> *v3; // rdx
  UFG::qResourceData *v4; // rdx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v5; // rdi
  UFG::qResourceHandle *i; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rax

  v1 = this;
  v2 = 0i64;
  if ( this->mNumCoverGroups )
  {
    do
    {
      v3 = &v1->mCoverGroups[v2];
      if ( v3->mOffset )
        v4 = (UFG::qResourceData *)((char *)v3 + v3->mOffset);
      else
        v4 = 0i64;
      UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&UFG::gDynamicCoverDataInventory.vfptr, v4);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v1->mNumCoverGroups );
  }
  v5 = &v1->mResourceHandles;
  for ( i = (UFG::qResourceHandle *)v5->mNode.mNext;
        i != (UFG::qResourceHandle *)v5;
        i = (UFG::qResourceHandle *)v5->mNode.mNext )
  {
    v7 = i->mPrev;
    v8 = i->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    i->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&i->mPrev;
    UFG::qResourceHandle::~qResourceHandle(i);
    operator delete[](i);
  }
  v9 = v5->mNode.mPrev;
  v10 = v5->mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
}

