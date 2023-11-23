// File Line: 22
// RVA: 0x1514310
__int64 dynamic_initializer_for__UFG::DynamicCoverComponent::s_DynamicCoverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DynamicCoverComponent::s_DynamicCoverComponentList__);
}

// File Line: 23
// RVA: 0x468070
const char *__fastcall UFG::DynamicCoverComponent::GetTypeName(UFG::DynamicCoverComponent *this)
{
  return "DynamicCoverComponent";
}

// File Line: 31
// RVA: 0x449830
void __fastcall UFG::DynamicCoverComponent::DynamicCoverComponent(
        UFG::DynamicCoverComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *mPrev; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax
  unsigned __int64 mParent_low; // rcx
  int v8; // ebp
  __int64 v9; // rax
  bool v10; // cf
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  unsigned int v13; // ebx
  UFG::DynamicCoverCorner *v14; // rsi

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent>;
  this->mNext = &this->UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DynamicCoverComponent::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mDynamicCoverGroup);
  this->m_TransformNodeChangeID = -1;
  this->mEnabled = 1;
  mPrev = UFG::DynamicCoverComponent::s_DynamicCoverComponentList.mNode.mPrev;
  UFG::DynamicCoverComponent::s_DynamicCoverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *)&UFG::DynamicCoverComponent::s_DynamicCoverComponentList;
  UFG::DynamicCoverComponent::s_DynamicCoverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent>;
  UFG::SimComponent::AddType(this, UFG::DynamicCoverComponent::_DynamicCoverComponentTypeUID, "DynamicCoverComponent");
  Inventory = `UFG::qGetResourceInventory<UFG::DynamicCoverGroup>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::DynamicCoverGroup>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0xE5150EE3);
    `UFG::qGetResourceInventory<UFG::DynamicCoverGroup>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mDynamicCoverGroup, 0xE5150EE3, name_uid, Inventory);
  mParent_low = LODWORD(this->mDynamicCoverGroup.mData[1].mNode.mParent);
  this->m_uNumCorners = mParent_low;
  v8 = mParent_low;
  v9 = 104 * mParent_low;
  if ( !is_mul_ok(mParent_low, 0x68ui64) )
    v9 = -1i64;
  v10 = __CFADD__(v9, 8i64);
  v11 = v9 + 8;
  if ( v10 )
    v11 = -1i64;
  v12 = UFG::qMalloc(v11, "DynamicCoverCorner", 0i64);
  v13 = 0;
  if ( v12 )
  {
    LODWORD(v12->mNext) = v8;
    v14 = (UFG::DynamicCoverCorner *)&v12[1];
    `eh vector constructor iterator(
      &v12[1],
      0x68ui64,
      v8,
      (void (__fastcall *)(void *))UFG::DynamicCoverCorner::DynamicCoverCorner);
  }
  else
  {
    v14 = 0i64;
  }
  this->m_aDynamicCoverCorners = v14;
  if ( this->m_uNumCorners )
  {
    do
    {
      UFG::DynamicCoverCorner::Init(&this->m_aDynamicCoverCorners[v13], this, v13);
      ++v13;
    }
    while ( v13 < this->m_uNumCorners );
  }
}

// File Line: 50
// RVA: 0x44FCB0
void __fastcall UFG::DynamicCoverComponent::~DynamicCoverComponent(UFG::DynamicCoverComponent *this)
{
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *v2; // rdi
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *mPrev; // rcx
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *mNext; // rax
  UFG::DynamicCoverCorner *m_aDynamicCoverCorners; // rcx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *v8; // rcx
  UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent> *v9; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DynamicCoverComponent::`vftable;
  if ( this == UFG::DynamicCoverComponent::s_DynamicCoverComponentpCurrentIterator )
    UFG::DynamicCoverComponent::s_DynamicCoverComponentpCurrentIterator = (UFG::DynamicCoverComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::DynamicCoverComponent,UFG::DynamicCoverComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  m_aDynamicCoverCorners = this->m_aDynamicCoverCorners;
  if ( m_aDynamicCoverCorners )
  {
    if ( m_aDynamicCoverCorners[-1].m_uGroupIndex )
      m_aDynamicCoverCorners->vfptr->__vecDelDtor(m_aDynamicCoverCorners, 3u);
    else
      operator delete[](&m_aDynamicCoverCorners[-1].m_uGroupIndex);
  }
  Inventory = `UFG::qGetResourceInventory<UFG::DynamicCoverGroup>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::DynamicCoverGroup>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0xE5150EE3);
    `UFG::qGetResourceInventory<UFG::DynamicCoverGroup>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mDynamicCoverGroup, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mDynamicCoverGroup);
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
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
  UFG::TransformNodeComponent *m_pSimObject; // rbx
  UFG::qMatrix44 *p_mWorldTransform; // rbx

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  if ( m_pSimObject )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
    p_mWorldTransform = &m_pSimObject->mWorldTransform;
  }
  else
  {
    p_mWorldTransform = &UFG::qMatrix44::msIdentity;
  }
  return this->mEnabled && p_mWorldTransform->v2.z > 0.89999998;
}

// File Line: 103
// RVA: 0x477B90
void __fastcall UFG::DynamicCoverComponent::Update(UFG::DynamicCoverComponent *this, float __formal)
{
  UFG::SimObject *m_pSimObject; // rbx
  unsigned int v4; // esi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  unsigned int mChangeID; // eax
  float x; // xmm8_4
  float y; // xmm9_4
  float z; // xmm14_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm15_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  UFG::qBaseNodeRB *v15; // rcx
  UFG::DynamicCoverCorner *v16; // rbx
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm7_4
  float v24; // xmm6_4
  UFG::CoverDataInventory *Instance; // rax
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *mPrev; // rdx
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *mNext; // rcx
  UFG::GridIntrusive<UFG::CoverCorner> *p_m_CornerGrid; // r9
  float v29; // xmm6_4
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *p_mNode; // rdx
  UFG::qNode<UFG::CoverCorner,UFG::CoverCorner> *v31; // rax
  float v32; // [rsp+20h] [rbp-C8h]
  float v33; // [rsp+F0h] [rbp+8h]
  float v34; // [rsp+100h] [rbp+18h]
  float v35; // [rsp+108h] [rbp+20h]

  if ( this->mDynamicCoverGroup.mData )
  {
    m_pSimObject = this->m_pSimObject;
    v4 = 0;
    if ( m_pSimObject )
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    if ( m_pTransformNodeComponent )
    {
      mChangeID = m_pTransformNodeComponent->mChangeID;
      if ( mChangeID != this->m_TransformNodeChangeID )
      {
        this->m_TransformNodeChangeID = mChangeID;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        x = m_pTransformNodeComponent->mWorldTransform.v0.x;
        y = m_pTransformNodeComponent->mWorldTransform.v0.y;
        z = m_pTransformNodeComponent->mWorldTransform.v0.z;
        v10 = m_pTransformNodeComponent->mWorldTransform.v1.x;
        v11 = m_pTransformNodeComponent->mWorldTransform.v1.y;
        v12 = m_pTransformNodeComponent->mWorldTransform.v1.z;
        v13 = m_pTransformNodeComponent->mWorldTransform.v2.x;
        v14 = m_pTransformNodeComponent->mWorldTransform.v2.y;
        v35 = m_pTransformNodeComponent->mWorldTransform.v2.z;
        v33 = m_pTransformNodeComponent->mWorldTransform.v3.x;
        v34 = m_pTransformNodeComponent->mWorldTransform.v3.y;
        v32 = m_pTransformNodeComponent->mWorldTransform.v3.z;
        if ( this->m_uNumCorners )
        {
          do
          {
            v15 = this->mDynamicCoverGroup.mData[1].mNode.mChild[1];
            v16 = &this->m_aDynamicCoverCorners[v4];
            v17 = v11 * *((float *)&v15->mChild[1] + 9 * v4);
            v18 = y * *((float *)v15->mChild + 9 * v4 + 1);
            v19 = v14 * *((float *)&v15->mChild[1] + 9 * v4 + 1);
            v16->m_vWallNormal.x = (float)((float)(x * *((float *)v15->mChild + 9 * v4 + 1))
                                         + (float)(v10 * *((float *)&v15->mChild[1] + 9 * v4)))
                                 + (float)(v13 * *((float *)&v15->mChild[1] + 9 * v4 + 1));
            v16->m_vWallNormal.y = (float)(v18 + v17) + v19;
            v20 = *((float *)&v15->mParent + 9 * v4);
            v21 = *((float *)&v15->mParent + 9 * v4 + 1);
            v22 = *((float *)v15->mChild + 9 * v4);
            v23 = (float)((float)((float)(x * v20) + (float)(v10 * v21)) + (float)(v13 * v22)) + v33;
            v24 = (float)((float)((float)(y * v20) + (float)(v11 * v21)) + (float)(v14 * v22)) + v34;
            v16->m_vCornerPosition.x = v23;
            v16->m_vCornerPosition.y = v24;
            v16->m_vCornerPosition.z = (float)((float)((float)(z * v20) + (float)(v12 * v21)) + (float)(v35 * v22))
                                     + v32;
            Instance = UFG::CoverDataInventory::GetInstance();
            mPrev = v16->mPrev;
            mNext = v16->mNext;
            mPrev->mNext = mNext;
            mNext->mPrev = mPrev;
            p_m_CornerGrid = &Instance->m_CornerGrid;
            v16->mPrev = &v16->UFG::CoverCorner;
            v16->mNext = &v16->UFG::CoverCorner;
            v29 = v24 - Instance->m_CornerGrid.mYMin;
            --Instance->m_CornerGrid.mNodeCount;
            p_mNode = &Instance->m_CornerGrid.mGridNodes[(int)(float)((float)(v23 - Instance->m_CornerGrid.mXMin)
                                                                    * Instance->m_CornerGrid.mGridSizeInv)
                                                       + Instance->m_CornerGrid.mXDim
                                                       * (int)(float)(v29 * Instance->m_CornerGrid.mGridSizeInv)].mNode;
            v31 = p_mNode->mPrev;
            v31->mNext = &v16->UFG::CoverCorner;
            v16->mPrev = v31;
            v16->mNext = p_mNode;
            p_mNode->mPrev = &v16->UFG::CoverCorner;
            ++p_m_CornerGrid->mNodeCount;
            ++v4;
          }
          while ( v4 < this->m_uNumCorners );
        }
      }
    }
  }
}

// File Line: 144
// RVA: 0x468190
UFG::qVector3 *__fastcall UFG::DynamicCoverComponent::GetVelocity(UFG::DynamicCoverComponent *this)
{
  UFG::TransformNodeComponent *m_pSimObject; // rbx

  m_pSimObject = (UFG::TransformNodeComponent *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  if ( !m_pSimObject )
    return &UFG::qVector3::msZero;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
  return &m_pSimObject->mWorldVelocity;
}

// File Line: 222
// RVA: 0x44FE80
void __fastcall UFG::DynamicCoverGroupBundle::~DynamicCoverGroupBundle(UFG::DynamicCoverGroupBundle *this)
{
  __int64 i; // rbx
  UFG::qOffset64<UFG::DynamicCoverGroup *> *v3; // rdx
  UFG::qResourceData *v4; // rdx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *j; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rax

  for ( i = 0i64; (unsigned int)i < this->mNumCoverGroups; i = (unsigned int)(i + 1) )
  {
    v3 = &this->mCoverGroups[i];
    if ( v3->mOffset )
      v4 = (UFG::qResourceData *)((char *)v3 + v3->mOffset);
    else
      v4 = 0i64;
    UFG::qResourceInventory::Remove(&UFG::gDynamicCoverDataInventory, v4);
  }
  p_mResourceHandles = &this->mResourceHandles;
  for ( j = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext;
        j != (UFG::qResourceHandle *)p_mResourceHandles;
        j = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext )
  {
    mPrev = j->mPrev;
    mNext = j->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    j->mPrev = j;
    j->mNext = j;
    UFG::qResourceHandle::~qResourceHandle(j);
    operator delete[](j);
  }
  v9 = p_mResourceHandles->mNode.mPrev;
  v10 = p_mResourceHandles->mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  p_mResourceHandles->mNode.mNext = &p_mResourceHandles->mNode;
}

