// File Line: 28
// RVA: 0x1514330
__int64 dynamic_initializer_for__UFG::ParkourComponent::s_ParkourComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ParkourComponent::s_ParkourComponentList__);
}

// File Line: 29
// RVA: 0x15139E0
__int64 dynamic_initializer_for__UFG::ParkourComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::ParkourComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::ParkourComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::ParkourComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::ParkourComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 41
// RVA: 0x44A180
void __fastcall UFG::ParkourComponent::ParkourComponent(
        UFG::ParkourComponent *this,
        unsigned int name_uid,
        UFG::ParkourInstanceData *d,
        int followBoneIndex)
{
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v7; // rsi
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm3
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *mPrev; // rax
  unsigned int mParkourContainerGuid; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v14; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  v7 = &this->UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent>;
  this->mPrev = &this->UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent>;
  this->mNext = &this->UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ParkourComponent::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mParkourContainer);
  this->mDisabledBits = 0i64;
  this->mFlags = 2;
  this->mTransformChangeId = -1;
  this->mFollowBoneIndex = followBoneIndex;
  if ( (d->mFlags & 1) != 0 )
  {
    v8 = UFG::qMatrix44::msIdentity.v1;
    v9 = UFG::qMatrix44::msIdentity.v2;
    v10 = UFG::qMatrix44::msIdentity.v3;
    this->mCachedInverseTransform.v0 = UFG::qMatrix44::msIdentity.v0;
    this->mCachedInverseTransform.v1 = v8;
    this->mCachedInverseTransform.v2 = v9;
    this->mCachedInverseTransform.v3 = v10;
  }
  else
  {
    this->mFlags = 6;
  }
  mPrev = UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev;
  UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev->mNext = v7;
  v7->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)&UFG::ParkourComponent::s_ParkourComponentList;
  UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev = &this->UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent>;
  UFG::SimComponent::AddType(this, UFG::ParkourComponent::_ParkourComponentTypeUID, "ParkourComponent");
  mParkourContainerGuid = d->mParkourContainerGuid;
  Inventory = `UFG::qGetResourceInventory<UFG::ParkourContainer>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::ParkourContainer>::`2::result )
  {
    v14 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v14, 0x15E16140u);
    `UFG::qGetResourceInventory<UFG::ParkourContainer>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mParkourContainer, 0x15E16140u, mParkourContainerGuid, Inventory);
}

// File Line: 66
// RVA: 0x44A080
void __fastcall UFG::ParkourComponent::ParkourComponent(
        UFG::ParkourComponent *this,
        unsigned int container_uid,
        int followBoneIndex)
{
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *mPrev; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v8; // rax

  UFG::SimComponent::SimComponent(this, container_uid);
  this->mPrev = &this->UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent>;
  this->mNext = &this->UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ParkourComponent::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mParkourContainer);
  this->mDisabledBits = 0i64;
  this->mFlags = 5;
  this->mTransformChangeId = -1;
  this->mFollowBoneIndex = followBoneIndex;
  mPrev = UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev;
  UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)&UFG::ParkourComponent::s_ParkourComponentList;
  UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev = &this->UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent>;
  UFG::SimComponent::AddType(this, UFG::ParkourComponent::_ParkourComponentTypeUID, "ParkourComponent");
  Inventory = `UFG::qGetResourceInventory<UFG::ParkourContainer>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::ParkourContainer>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v8, 0x15E16140u);
    `UFG::qGetResourceInventory<UFG::ParkourContainer>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mParkourContainer, 0x15E16140u, container_uid, Inventory);
}

// File Line: 76
// RVA: 0x450050
void __fastcall UFG::ParkourComponent::~ParkourComponent(UFG::ParkourComponent *this)
{
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v2; // rdi
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *mPrev; // rcx
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *mNext; // rax
  UFG::BitArray *mDisabledBits; // rcx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v8; // rcx
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v9; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ParkourComponent::`vftable;
  if ( this == UFG::ParkourComponent::s_ParkourComponentpCurrentIterator )
    UFG::ParkourComponent::s_ParkourComponentpCurrentIterator = (UFG::ParkourComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  mDisabledBits = this->mDisabledBits;
  if ( mDisabledBits )
    mDisabledBits->vfptr->__vecDelDtor(mDisabledBits, 1u);
  Inventory = `UFG::qGetResourceInventory<UFG::ParkourContainer>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::ParkourContainer>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x15E16140u);
    `UFG::qGetResourceInventory<UFG::ParkourContainer>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mParkourContainer, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mParkourContainer);
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 84
// RVA: 0x467F10
void __fastcall UFG::ParkourComponent::GetTransform(UFG::ParkourComponent *this, UFG::qMatrix44 *xform)
{
  UFG::SimObject *m_pSimObject; // rsi
  Creature *v3; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::qVector4 v7; // xmm3
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  UFG::SimObject *v10; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qVector4 v12; // xmm1
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm3

  m_pSimObject = this->m_pSimObject;
  v3 = 0i64;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  if ( m_pTransformNodeComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v7 = m_pTransformNodeComponent->mWorldTransform.v1;
    v8 = m_pTransformNodeComponent->mWorldTransform.v2;
    v9 = m_pTransformNodeComponent->mWorldTransform.v3;
    xform->v0 = m_pTransformNodeComponent->mWorldTransform.v0;
    xform->v1 = v7;
    xform->v2 = v8;
    xform->v3 = v9;
    if ( this->mFollowBoneIndex != -1 )
    {
      v10 = this->m_pSimObject;
      if ( v10 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(v10, UFG::BaseAnimationComponent::_TypeUID);
        if ( ComponentOfType )
          v3 = *(Creature **)&ComponentOfType[2].m_TypeUID;
      }
      if ( v3 )
        Creature::GetTransform(v3, this->mFollowBoneIndex, xform);
    }
  }
  else
  {
    v12 = UFG::qMatrix44::msIdentity.v1;
    v13 = UFG::qMatrix44::msIdentity.v2;
    v14 = UFG::qMatrix44::msIdentity.v3;
    xform->v0 = UFG::qMatrix44::msIdentity.v0;
    xform->v1 = v12;
    xform->v2 = v13;
    xform->v3 = v14;
  }
}

// File Line: 110
// RVA: 0x459CB0
void __fastcall UFG::ParkourComponent::BuildCachedInverseTransform(UFG::ParkourComponent *this)
{
  UFG::SimObject *m_pSimObject; // rdi
  Creature *v3; // rsi
  UFG::TransformNodeComponent *v4; // rdi
  bool v5; // zf
  float y; // xmm1_4
  float z; // xmm0_4
  float w; // xmm1_4
  float x; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  UFG::SimObject *v21; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-48h] BYREF

  if ( (this->mFlags & 4) != 0 )
  {
    m_pSimObject = this->m_pSimObject;
    v3 = 0i64;
    v4 = m_pSimObject ? m_pSimObject->m_pTransformNodeComponent : 0i64;
    if ( *(_QWORD *)&this->mTransformChangeId != (v4->mChangeID | 0xFFFFFFFF00000000ui64) )
    {
      this->mTransformChangeId = v4->mChangeID;
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      v5 = this->mFollowBoneIndex == -1;
      y = v4->mWorldTransform.v0.y;
      transform.v0.x = v4->mWorldTransform.v0.x;
      z = v4->mWorldTransform.v0.z;
      transform.v0.y = y;
      w = v4->mWorldTransform.v0.w;
      transform.v0.z = z;
      x = v4->mWorldTransform.v1.x;
      transform.v0.w = w;
      v10 = v4->mWorldTransform.v1.y;
      transform.v1.x = x;
      v11 = v4->mWorldTransform.v1.z;
      transform.v1.y = v10;
      v12 = v4->mWorldTransform.v1.w;
      transform.v1.z = v11;
      v13 = v4->mWorldTransform.v2.x;
      transform.v1.w = v12;
      v14 = v4->mWorldTransform.v2.y;
      transform.v2.x = v13;
      v15 = v4->mWorldTransform.v2.z;
      transform.v2.y = v14;
      v16 = v4->mWorldTransform.v2.w;
      transform.v2.z = v15;
      v17 = v4->mWorldTransform.v3.x;
      transform.v2.w = v16;
      v18 = v4->mWorldTransform.v3.y;
      transform.v3.x = v17;
      v19 = v4->mWorldTransform.v3.z;
      transform.v3.y = v18;
      v20 = v4->mWorldTransform.v3.w;
      transform.v3.z = v19;
      transform.v3.w = v20;
      if ( !v5 )
      {
        v21 = this->m_pSimObject;
        if ( v21 )
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(v21, UFG::BaseAnimationComponent::_TypeUID);
          if ( ComponentOfType )
            v3 = *(Creature **)&ComponentOfType[2].m_TypeUID;
        }
        if ( v3 )
          Creature::GetTransform(v3, this->mFollowBoneIndex, &transform);
      }
      UFG::qInverseAffine(&this->mCachedInverseTransform, &transform);
    }
  }
}

// File Line: 169
// RVA: 0x44A380
void __fastcall UFG::ParkourQueryManager::ParkourQueryManager(UFG::ParkourQueryManager *this)
{
  int v2; // r9d
  UFG::qList<UFG::ParkourQuery,UFG::ParkourQuery,1,0> *result; // [rsp+58h] [rbp+10h] BYREF

  `eh vector constructor iterator(this, 0x10ui64, 257, (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  this->mTempOutput.m_data = 0i64;
  this->mTempOutput.m_size = 0;
  this->mTempOutput.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->mInactiveSearchBucket = 0i64;
  *(_QWORD *)&this->mNumQueries = 0i64;
  result = &this->mQueries;
  this->mQueries.mNode.mPrev = &this->mQueries.mNode;
  this->mQueries.mNode.mNext = &this->mQueries.mNode;
  v2 = 1024;
  if ( (this->mTempOutput.m_capacityAndFlags & 0x3FFFFFFFu) < 0x400 )
  {
    if ( 2 * (this->mTempOutput.m_capacityAndFlags & 0x3FFFFFFF) > 1024 )
      v2 = 2 * (this->mTempOutput.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, &this->mTempOutput, v2, 8);
  }
}

// File Line: 184
// RVA: 0x454B20
void __fastcall UFG::ParkourQueryManager::AddAsyncQuery(UFG::ParkourQueryManager *this, UFG::ParkourQuery *query)
{
  UFG::qList<UFG::ParkourQuery,UFG::ParkourQuery,1,0> *p_mQueries; // rcx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *mPrev; // rax

  p_mQueries = &this->mQueries;
  mPrev = p_mQueries->mNode.mPrev;
  mPrev->mNext = query;
  query->mPrev = mPrev;
  query->mNext = &p_mQueries->mNode;
  p_mQueries->mNode.mPrev = query;
}

// File Line: 191
// RVA: 0x479600
void __fastcall UFG::ParkourQueryManager::Update(UFG::ParkourQueryManager *this)
{
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v2; // rbx
  UFG::ParkourQuery *mNext; // r15
  UFG::qList<UFG::ParkourComponent,UFG::ParkourComponent,1,0> *v4; // rcx
  UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *p_handlesOut; // r14
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v6; // rdi
  UFG::ParkourContainer *mPrev; // rsi
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *p_mTempOutput; // rbx
  int v9; // r12d
  __int64 v10; // r15
  UFG::ParkourData **m_data; // rbx
  __int64 v12; // r8
  bool v13; // zf
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v14; // rdx
  UFG::ParkourHandle *v15; // rax
  __int64 **p_m_SafePointerList; // rcx
  __int64 *v17; // rax
  __int64 size; // rsi
  unsigned int v19; // ebx
  unsigned int capacity; // edx
  unsigned int v21; // edx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v22; // rdx
  __int64 v23; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v26; // rax
  __int64 *v27; // rcx
  __int64 **v28; // rax
  __int64 *v29; // rcx
  __int64 **v30; // rax
  __int64 *v31; // [rsp+0h] [rbp-69h] BYREF
  __int64 **v32; // [rsp+8h] [rbp-61h]
  UFG::ParkourHandle *v33; // [rsp+10h] [rbp-59h]
  UFG::qVector3 v34; // [rsp+18h] [rbp-51h] BYREF
  float v0; // [rsp+28h] [rbp-41h] BYREF
  float v0_4; // [rsp+2Ch] [rbp-3Dh]
  __int64 v37; // [rsp+38h] [rbp-31h]
  UFG::qMatrix44 xform; // [rsp+40h] [rbp-29h] BYREF
  UFG::ParkourContainer *v39; // [rsp+D0h] [rbp+67h]
  UFG::qList<UFG::ParkourComponent,UFG::ParkourComponent,1,0> *i; // [rsp+D8h] [rbp+6Fh]
  UFG::ParkourQuery *v41; // [rsp+E0h] [rbp+77h]

  v37 = -2i64;
  ++this->mFrameNumber;
  this->mNumQueries = 0;
  v2 = UFG::ParkourComponent::s_ParkourComponentList.mNode.mNext - 4;
  for ( i = &UFG::ParkourComponent::s_ParkourComponentList - 4;
        v2 != (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)(&UFG::ParkourComponent::s_ParkourComponentList
                                                                        - 4);
        v2 = v2[4].mNext - 4 )
  {
    if ( v2[6].mPrev && ((__int64)v2[11].mNext & 8) == 0 && ((__int64)v2[2].mPrev & 2) == 0 )
      UFG::ParkourComponent::BuildCachedInverseTransform((UFG::ParkourComponent *)v2);
  }
  mNext = (UFG::ParkourQuery *)this->mQueries.mNode.mNext;
  v41 = mNext;
  if ( mNext != (UFG::ParkourQuery *)&this->mQueries )
  {
    v4 = &UFG::ParkourComponent::s_ParkourComponentList - 4;
    do
    {
      ++this->mNumQueries;
      p_handlesOut = (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&mNext->handlesOut;
      mNext->handlesOut.size = 0;
      v6 = UFG::ParkourComponent::s_ParkourComponentList.mNode.mNext - 4;
      if ( (UFG::qList<UFG::ParkourComponent,UFG::ParkourComponent,1,0> *)&UFG::ParkourComponent::s_ParkourComponentList.mNode.mNext[-4] == v4 )
        goto LABEL_43;
      do
      {
        if ( !v6[6].mPrev || ((__int64)v6[11].mNext & 8) != 0 || ((__int64)v6[2].mPrev & 2) != 0 )
          goto LABEL_42;
        this->mTempOutput.m_size = 0;
        UFG::ParkourComponent::GetTransform((UFG::ParkourComponent *)v6, &xform);
        mPrev = (UFG::ParkourContainer *)v6[6].mPrev;
        v39 = mPrev;
        p_mTempOutput = &this->mTempOutput;
        UFG::ParkourContainer::Query(mPrev, (UFG::ParkourComponent *)v6, mNext, &this->mTempOutput);
        v9 = 0;
        if ( this->mTempOutput.m_size <= 0 )
          goto LABEL_41;
        v10 = 0i64;
        do
        {
          m_data = p_mTempOutput->m_data;
          v12 = m_data[v10] - mPrev->mParkourData;
          if ( (_DWORD)v12 == -1 )
          {
            v13 = ((__int64)v6[11].mNext & 8) == 0;
            goto LABEL_19;
          }
          v14 = v6[11].mPrev;
          if ( v14 )
          {
            v13 = ((*((_DWORD *)&v14[1].mPrev->mPrev + ((unsigned int)v12 >> 5)) >> (v12 & 0x1F)) & 1) == 0;
LABEL_19:
            if ( !v13 )
              goto LABEL_39;
          }
          UFG::ParkourContainer::GetVerts(
            mPrev,
            (UFG::ParkourComponent *)v6,
            &xform,
            m_data[v10],
            &v34,
            (UFG::qVector3 *)&v0);
          if ( (float)((float)((float)(v0_4 - v34.y) * (float)(v0_4 - v34.y))
                     + (float)((float)(v0 - v34.x) * (float)(v0 - v34.x))) > 0.0049999999 )
          {
            v15 = UFG::ParkourQueryManager::UpdateOrCreateHandle(
                    this,
                    (UFG::ParkourComponent *)v6,
                    m_data[v10],
                    &v34,
                    (UFG::qVector3 *)&v0);
            v31 = (__int64 *)&v31;
            v32 = &v31;
            v33 = v15;
            if ( v15 )
            {
              p_m_SafePointerList = (__int64 **)&v15->m_SafePointerList;
              v17 = (__int64 *)v15->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev;
              v17[1] = (__int64)&v31;
              v31 = v17;
              v32 = p_m_SafePointerList;
              *p_m_SafePointerList = (__int64 *)&v31;
            }
            size = p_handlesOut->size;
            v19 = size + 1;
            capacity = p_handlesOut->capacity;
            if ( (int)size + 1 > capacity )
            {
              if ( capacity )
                v21 = 2 * capacity;
              else
                v21 = 1;
              for ( ; v21 < v19; v21 *= 2 )
                ;
              if ( v21 - v19 > 0x10000 )
                v21 = size + 65537;
              UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
                p_handlesOut,
                v21,
                "qArray.Add");
            }
            p_handlesOut->size = v19;
            v22 = &p_handlesOut->p[size];
            v23 = (__int64)v33;
            if ( v22->m_pPointer )
            {
              v24 = v22->mPrev;
              v25 = v22->mNext;
              v24->mNext = v25;
              v25->mPrev = v24;
              v22->mPrev = v22;
              v22->mNext = v22;
            }
            v22->m_pPointer = (UFG::Constraint *)v23;
            if ( v23 )
            {
              v26 = *(UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> **)(v23 + 8);
              v26->mNext = v22;
              v22->mPrev = v26;
              v22->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)(v23 + 8);
              *(_QWORD *)(v23 + 8) = v22;
            }
            if ( v33 )
            {
              v27 = v31;
              v28 = v32;
              v31[1] = (__int64)v32;
              *v28 = v27;
              v31 = (__int64 *)&v31;
              v32 = &v31;
            }
            v33 = 0i64;
            v29 = v31;
            v30 = v32;
            v31[1] = (__int64)v32;
            *v30 = v29;
            v31 = (__int64 *)&v31;
            v32 = &v31;
            mPrev = v39;
          }
LABEL_39:
          ++v9;
          ++v10;
          p_mTempOutput = &this->mTempOutput;
        }
        while ( v9 < this->mTempOutput.m_size );
        mNext = v41;
LABEL_41:
        v4 = i;
LABEL_42:
        v6 = v6[4].mNext - 4;
      }
      while ( v6 != (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)v4 );
LABEL_43:
      mNext = (UFG::ParkourQuery *)mNext->mNext;
      v41 = mNext;
    }
    while ( mNext != (UFG::ParkourQuery *)&this->mQueries );
  }
  UFG::ParkourQueryManager::DeleteInactive(this);
  UFG::ParkourQueryManager::UpdateConnectivity(this);
}

// File Line: 324
// RVA: 0x461F50
void __fastcall UFG::ParkourQueryManager::DispatchResults(UFG::ParkourQueryManager *this)
{
  UFG::qList<UFG::ParkourQuery,UFG::ParkourQuery,1,0> *p_mQueries; // rbx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *mNext; // rcx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v4; // rax
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *mPrev; // rdx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v6; // rax

  p_mQueries = &this->mQueries;
  if ( (UFG::qList<UFG::ParkourQuery,UFG::ParkourQuery,1,0> *)this->mQueries.mNode.mNext != &this->mQueries )
  {
    do
    {
      mNext = this->mQueries.mNode.mNext;
      v4 = mNext->mNext;
      mPrev = mNext->mPrev;
      mPrev->mNext = v4;
      v4->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v6 = mNext[1].mPrev;
      if ( v6 )
        ((void (__fastcall *)(UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *))v6)(mNext[1].mNext);
    }
    while ( (UFG::qList<UFG::ParkourQuery,UFG::ParkourQuery,1,0> *)p_mQueries->mNode.mNext != p_mQueries );
  }
}

// File Line: 362
// RVA: 0x47F8B0
void __fastcall UFG::ParkourQueryManager::UpdateOrCreateAllHandles(
        UFG::ParkourQueryManager *this,
        UFG::ParkourComponent *component,
        UFG::qArray<UFG::ParkourHandle *,0> *handles)
{
  UFG::ParkourContainer *mData; // r15
  UFG::ParkourQueryManager *v6; // rsi
  UFG::ParkourData *mParkourData; // rbx
  __int64 i; // r14
  UFG::ParkourHandle *v9; // rax
  __int64 size; // r13
  unsigned int capacity; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::ParkourHandle **v16; // rbp
  __int64 j; // r9
  __int64 v18; // r8
  UFG::ParkourHandle **p; // rax
  UFG::qVector3 v1; // [rsp+30h] [rbp-98h] BYREF
  UFG::qVector3 v0; // [rsp+40h] [rbp-88h] BYREF
  UFG::qMatrix44 transform; // [rsp+50h] [rbp-78h] BYREF
  UFG::ParkourHandle *v24; // [rsp+D8h] [rbp+10h]
  UFG::ParkourData *v25; // [rsp+E8h] [rbp+20h]

  mData = (UFG::ParkourContainer *)component->mParkourContainer.mData;
  v6 = this;
  if ( mData )
  {
    mParkourData = mData->mParkourData;
    v25 = mParkourData;
    UFG::ParkourComponent::GetTransform(component, &transform);
    for ( i = 0i64; (unsigned int)i < mData->mNumParkourData; p[size] = v24 )
    {
      UFG::ParkourContainer::GetVerts(mData, component, &transform, mParkourData, &v0, &v1);
      v9 = UFG::ParkourQueryManager::UpdateOrCreateHandle(v6, component, &mParkourData[i], &v0, &v1);
      size = handles->size;
      capacity = handles->capacity;
      v12 = size + 1;
      v24 = v9;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v13 = 2 * capacity;
        else
          v13 = 1;
        for ( ; v13 < v12; v13 *= 2 )
          ;
        if ( v13 <= 2 )
          v13 = 2;
        if ( v13 - v12 > 0x10000 )
          v13 = size + 65537;
        if ( v13 != (_DWORD)size )
        {
          v14 = 8i64 * v13;
          if ( !is_mul_ok(v13, 8ui64) )
            v14 = -1i64;
          v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
          v16 = (UFG::ParkourHandle **)v15;
          if ( handles->p )
          {
            for ( j = 0i64; (unsigned int)j < handles->size; v15[v18] = (UFG::allocator::free_link)handles->p[v18] )
            {
              v18 = j;
              j = (unsigned int)(j + 1);
            }
            operator delete[](handles->p);
          }
          handles->p = v16;
          handles->capacity = v13;
        }
      }
      p = handles->p;
      mParkourData = v25;
      handles->size = v12;
      v6 = this;
      i = (unsigned int)(i + 1);
    }
  }
}

// File Line: 384
// RVA: 0x47FA90
UFG::ParkourHandle *__fastcall UFG::ParkourQueryManager::UpdateOrCreateHandle(
        UFG::ParkourQueryManager *this,
        UFG::ParkourComponent *component,
        UFG::ParkourData *data,
        UFG::qVector3 *v0,
        UFG::qVector3 *v1)
{
  unsigned __int64 v8; // r10
  UFG::ParkourHandle *Handle; // r8
  char *v11; // rcx
  __int64 v12; // rax
  UFG::SimObject *v13; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v14; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimObject *m_pSimObject; // r9
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  UFG::ParkourHandle *m_pPointer; // rax
  UFG::ParkourHandle *v29; // rax

  v8 = (unsigned int)data | ((_QWORD)component << 32);
  Handle = 0i64;
  v11 = (char *)&this->mActiveHandles[v8 % 0x101 - 1] - 8;
  v12 = *((_QWORD *)v11 + 4) - 24i64;
  if ( (char *)v12 != v11 )
  {
    while ( *(_QWORD *)(v12 + 136) != v8 )
    {
      v12 = *(_QWORD *)(v12 + 32) - 24i64;
      if ( (char *)v12 == v11 )
        goto LABEL_6;
    }
    Handle = (UFG::ParkourHandle *)v12;
  }
LABEL_6:
  if ( Handle )
  {
    if ( !Handle->mSimObject.m_pPointer )
    {
      m_pSimObject = component->m_pSimObject;
      p_mSimObject = &Handle->mSimObject;
      if ( Handle->mSimObject.m_pPointer )
      {
        mPrev = p_mSimObject->mPrev;
        mNext = Handle->mSimObject.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mSimObject->mPrev = p_mSimObject;
        Handle->mSimObject.mNext = &Handle->mSimObject;
      }
      Handle->mSimObject.m_pPointer = m_pSimObject;
      if ( m_pSimObject )
      {
        v23 = m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v23->mNext = p_mSimObject;
        p_mSimObject->mPrev = v23;
        Handle->mSimObject.mNext = &m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mSimObject;
      }
    }
    y = v0->y;
    z = v0->z;
    Handle->v0.x = v0->x;
    Handle->v0.y = y;
    Handle->v0.z = z;
    v26 = v1->y;
    v27 = v1->z;
    Handle->v1.x = v1->x;
    Handle->v1.y = v26;
    Handle->v1.z = v27;
  }
  else
  {
    Handle = UFG::ParkourQueryManager::CreateHandle(this, v8, v0, v1, data->flags);
    v13 = component->m_pSimObject;
    v14 = &Handle->mSimObject;
    if ( Handle->mSimObject.m_pPointer )
    {
      v15 = v14->mPrev;
      v16 = Handle->mSimObject.mNext;
      v15->mNext = v16;
      v16->mPrev = v15;
      v14->mPrev = v14;
      Handle->mSimObject.mNext = &Handle->mSimObject;
    }
    Handle->mSimObject.m_pPointer = v13;
    if ( v13 )
    {
      p_m_SafePointerList = &v13->m_SafePointerList;
      v18 = v13->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v18->mNext = v14;
      v14->mPrev = v18;
      Handle->mSimObject.mNext = &p_m_SafePointerList->mNode;
      p_m_SafePointerList->mNode.mPrev = v14;
    }
  }
  m_pPointer = Handle->mCachedLeftNeighbor.m_pPointer;
  Handle->mFramesUntilDeleted = 10;
  if ( m_pPointer )
    m_pPointer->mFramesUntilDeleted = 10;
  v29 = Handle->mCachedRightNeighbor.m_pPointer;
  if ( v29 )
    v29->mFramesUntilDeleted = 10;
  return Handle;
}

// File Line: 417
// RVA: 0x4730D0
void __fastcall UFG::ParkourQueryManager::RemoveCachedHandle(
        UFG::ParkourQueryManager *this,
        UFG::ParkourComponent *component,
        UFG::ParkourData *data)
{
  unsigned __int64 v3; // r9
  char *v4; // rdx
  __int64 v5; // rcx

  v3 = (unsigned int)data | ((_QWORD)component << 32);
  v4 = (char *)&this->mActiveHandles[v3 % 0x101 - 1] - 8;
  v5 = *((_QWORD *)v4 + 4) - 24i64;
  if ( (char *)v5 != v4 )
  {
    while ( *(_QWORD *)(v5 + 136) != v3 )
    {
      v5 = *(_QWORD *)(v5 + 32) - 24i64;
      if ( (char *)v5 == v4 )
        return;
    }
    if ( v5 )
      (**(void (__fastcall ***)(__int64, __int64))v5)(v5, 1i64);
  }
}

// File Line: 429
// RVA: 0x45C9C0
UFG::ParkourHandle *__fastcall UFG::ParkourQueryManager::CreateHandle(
        UFG::ParkourQueryManager *this,
        unsigned __int64 guid,
        UFG::qVector3 *v0,
        UFG::qVector3 *v1,
        unsigned __int16 flags)
{
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax
  __int64 v11; // r8
  UFG::qList<UFG::ParkourHandle,UFG::ParkourHandle,1,0> *v12; // rdx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *mPrev; // rax

  v9 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xA0ui64, "ParkourHandle", 0i64, 1u);
  if ( v9 )
  {
    UFG::ParkourHandle::ParkourHandle((UFG::ParkourHandle *)v9, guid, v0, v1, flags);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = &this->mActiveHandles[guid % 0x101];
  mPrev = v12->mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(v11 + 24);
  *(_QWORD *)(v11 + 24) = mPrev;
  *(_QWORD *)(v11 + 32) = v12;
  v12->mNode.mPrev = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(v11 + 24);
  return (UFG::ParkourHandle *)v11;
}

// File Line: 442
// RVA: 0x4612D0
void __fastcall UFG::ParkourQueryManager::DeleteInactive(UFG::ParkourQueryManager *this)
{
  __int64 v2; // rbp
  unsigned int v3; // eax
  __int64 v4; // rax
  char *v5; // rdi
  char *p_mNext; // rcx
  __int64 v7; // rbx

  v2 = 257i64;
  do
  {
    v3 = ++this->mInactiveSearchBucket;
    if ( v3 >= 0x101 )
      v3 = 0;
    this->mInactiveSearchBucket = v3;
    v4 = v3;
    v5 = (char *)&this[-1].mNumQueries + v4 * 16;
    p_mNext = (char *)&this->mActiveHandles[v4].mNode.mNext[-2].mNext;
    if ( p_mNext != v5 )
    {
      do
      {
        v7 = *((_QWORD *)p_mNext + 4) - 24i64;
        if ( (*((_WORD *)p_mNext + 74) & 0x800) == 0
          && (p_mNext[152] & 1) == 0
          && (p_mNext[152] & 0x1C) == 0
          && --*((_DWORD *)p_mNext + 36) < 0 )
        {
          (**(void (__fastcall ***)(char *, __int64))p_mNext)(p_mNext, 1i64);
        }
        p_mNext = (char *)v7;
      }
      while ( (char *)v7 != v5 );
    }
    --v2;
  }
  while ( v2 );
}

// File Line: 475
// RVA: 0x47E290
void __fastcall UFG::ParkourQueryManager::UpdateConnectivity(UFG::ParkourQueryManager *this)
{
  __int64 v2; // rsi
  __int64 mConnectivityUpdateBucket; // rax
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **v4; // r11
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **i; // r9
  float *v6; // rax
  __int64 v7; // rdx
  __int64 v8; // r8
  float *v9; // rax
  unsigned int v10; // r10d
  unsigned int *p_mNumQueries; // rcx
  __int64 j; // rax
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **v13; // r10
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v14; // rcx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v15; // rax
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v16; // rax
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **v17; // r10
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v18; // rcx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v19; // rax
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v20; // rax
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v21; // rdx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *mPrev; // rcx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *mNext; // rax
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v24; // rax
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v25; // r8
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v26; // rcx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v27; // rax
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v28; // rax

  v2 = 2i64;
  do
  {
    mConnectivityUpdateBucket = this->mConnectivityUpdateBucket;
    v4 = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **)((char *)&this[-1].mNumQueries
                                                              + mConnectivityUpdateBucket * 16);
    this->mConnectivityUpdateBucket = (this->mConnectivityUpdateBucket + 1) % 0x101;
    for ( i = &this->mActiveHandles[mConnectivityUpdateBucket].mNode.mNext[-2].mNext; i != v4; i = &i[4][-2].mNext )
    {
      v6 = (float *)i[10];
      v7 = 0i64;
      v8 = 0i64;
      if ( v6
        && (float)((float)((float)((float)(v6[31] - *((float *)i + 28)) * (float)(v6[31] - *((float *)i + 28)))
                         + (float)((float)(v6[32] - *((float *)i + 29)) * (float)(v6[32] - *((float *)i + 29))))
                 + (float)((float)(v6[33] - *((float *)i + 30)) * (float)(v6[33] - *((float *)i + 30)))) <= 0.0025000002 )
      {
        v7 = (__int64)i[10];
      }
      v9 = (float *)i[13];
      if ( v9
        && (float)((float)((float)((float)(v9[28] - *((float *)i + 31)) * (float)(v9[28] - *((float *)i + 31)))
                         + (float)((float)(v9[29] - *((float *)i + 32)) * (float)(v9[29] - *((float *)i + 32))))
                 + (float)((float)(v9[30] - *((float *)i + 33)) * (float)(v9[30] - *((float *)i + 33)))) <= 0.0025000002 )
      {
        v8 = (__int64)i[13];
      }
      v10 = 0;
      p_mNumQueries = &this[-1].mNumQueries;
      do
      {
        if ( v7 && v8 )
          break;
        for ( j = *((_QWORD *)p_mNumQueries + 4) - 24i64;
              (unsigned int *)j != p_mNumQueries;
              j = *(_QWORD *)(j + 32) - 24i64 )
        {
          if ( v7 && v8 )
            break;
          if ( i != (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **)j )
          {
            if ( !v7
              && (float)((float)((float)((float)(*(float *)(j + 124) - *((float *)i + 28))
                                       * (float)(*(float *)(j + 124) - *((float *)i + 28)))
                               + (float)((float)(*(float *)(j + 128) - *((float *)i + 29))
                                       * (float)(*(float *)(j + 128) - *((float *)i + 29))))
                       + (float)((float)(*(float *)(j + 132) - *((float *)i + 30))
                               * (float)(*(float *)(j + 132) - *((float *)i + 30)))) <= 0.0025000002 )
            {
              v7 = j;
            }
            if ( !v8
              && (float)((float)((float)((float)(*(float *)(j + 116) - *((float *)i + 32))
                                       * (float)(*(float *)(j + 116) - *((float *)i + 32)))
                               + (float)((float)(*(float *)(j + 112) - *((float *)i + 31))
                                       * (float)(*(float *)(j + 112) - *((float *)i + 31))))
                       + (float)((float)(*(float *)(j + 120) - *((float *)i + 33))
                               * (float)(*(float *)(j + 120) - *((float *)i + 33)))) <= 0.0025000002 )
            {
              v8 = j;
            }
          }
        }
        ++v10;
        p_mNumQueries += 4;
      }
      while ( v10 < 0x101 );
      v13 = i + 8;
      if ( i[10] )
      {
        v14 = *v13;
        v15 = i[9];
        v14->mNext = v15;
        v15->mPrev = v14;
        *v13 = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)v13;
        i[9] = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(i + 8);
      }
      i[10] = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)v7;
      if ( v7 )
      {
        v16 = *(UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **)(v7 + 8);
        v16->mNext = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)v13;
        *v13 = v16;
        i[9] = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(v7 + 8);
        *(_QWORD *)(v7 + 8) = v13;
      }
      v17 = i + 11;
      if ( i[13] )
      {
        v18 = *v17;
        v19 = i[12];
        v18->mNext = v19;
        v19->mPrev = v18;
        *v17 = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)v17;
        i[12] = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(i + 11);
      }
      i[13] = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)v8;
      if ( v8 )
      {
        v20 = *(UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **)(v8 + 8);
        v20->mNext = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)v17;
        *v17 = v20;
        i[12] = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(v8 + 8);
        *(_QWORD *)(v8 + 8) = v17;
      }
      if ( v7 )
      {
        v21 = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(v7 + 88);
        if ( v21[1].mPrev )
        {
          mPrev = v21->mPrev;
          mNext = v21->mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          v21->mPrev = v21;
          v21->mNext = v21;
        }
        v21[1].mPrev = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)i;
        v24 = i[1];
        v24->mNext = v21;
        v21->mPrev = v24;
        v21->mNext = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(i + 1);
        i[1] = v21;
      }
      if ( v8 )
      {
        v25 = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(v8 + 64);
        if ( v25[1].mPrev )
        {
          v26 = v25->mPrev;
          v27 = v25->mNext;
          v26->mNext = v27;
          v27->mPrev = v26;
          v25->mPrev = v25;
          v25->mNext = v25;
        }
        v25[1].mPrev = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)i;
        v28 = i[1];
        v28->mNext = v25;
        v25->mPrev = v28;
        v25->mNext = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(i + 1);
        i[1] = v25;
      }
    }
    --v2;
  }
  while ( v2 );
}

// File Line: 560
// RVA: 0x471220
void __fastcall UFG::ParkourContainer::Query(
        UFG::ParkourContainer *this,
        UFG::ParkourComponent *component,
        UFG::qVector3 *queryAabbMin,
        UFG::qVector3 *queryAabbMax,
        hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *output)
{
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *v5; // rsi
  float x; // xmm0_4
  float v8; // xmm5_4
  unsigned int v9; // eax
  float y; // xmm4_4
  float z; // xmm8_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  float v19; // xmm8_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  float v22; // xmm10_4
  float *p_z; // rax
  __int64 v24; // rcx
  float v25; // xmm4_4
  float v26; // xmm8_4
  float v27; // xmm7_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v30; // xmm2_4
  float v31; // xmm5_4
  float v32; // xmm3_4
  float v33; // xmm1_4
  __int64 v34; // rsi
  float v35; // xmm1_4
  float v36; // xmm4_4
  float v37; // xmm5_4
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  UFG::ParkourData *v41; // r14
  UFG::qVector3 *mVertexBuffer; // rcx
  __int64 v43; // rax
  float v44; // xmm6_4
  float v45; // xmm6_4
  float v46; // xmm6_4
  float v47; // [rsp+40h] [rbp-B0h]
  float v48; // [rsp+44h] [rbp-ACh]
  UFG::qVector3 aabb1Min; // [rsp+50h] [rbp-A0h] BYREF
  UFG::qVector3 aabb1Max; // [rsp+60h] [rbp-90h] BYREF
  UFG::qMatrix44 d; // [rsp+70h] [rbp-80h] BYREF
  UFG::qMatrix44 xform; // [rsp+B0h] [rbp-40h] BYREF
  float v53; // [rsp+F0h] [rbp+0h]
  float v54; // [rsp+F4h] [rbp+4h]
  float v55; // [rsp+F8h] [rbp+8h]
  float v56; // [rsp+FCh] [rbp+Ch]
  float v57; // [rsp+100h] [rbp+10h]
  float v58; // [rsp+104h] [rbp+14h]
  float v59; // [rsp+108h] [rbp+18h]
  float v60; // [rsp+10Ch] [rbp+1Ch]
  float v61; // [rsp+110h] [rbp+20h]
  float v62; // [rsp+114h] [rbp+24h]
  float v63; // [rsp+118h] [rbp+28h]
  float v64; // [rsp+11Ch] [rbp+2Ch]
  float v65; // [rsp+120h] [rbp+30h]
  float v66; // [rsp+124h] [rbp+34h]
  float v67; // [rsp+128h] [rbp+38h]
  float v68; // [rsp+12Ch] [rbp+3Ch]
  float vars0; // [rsp+1F0h] [rbp+100h]
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *v70; // [rsp+210h] [rbp+120h]

  if ( this->mNumParkourData )
  {
    x = queryAabbMin->x;
    v8 = queryAabbMax->x;
    v70 = v5;
    v9 = component->mFlags >> 2;
    y = queryAabbMax->y;
    aabb1Min.x = queryAabbMin->x;
    aabb1Max.x = v8;
    z = queryAabbMax->z;
    v12 = queryAabbMin->y;
    v13 = queryAabbMin->z;
    aabb1Max.z = z;
    aabb1Min.y = v12;
    aabb1Min.z = v13;
    aabb1Max.y = y;
    if ( (v9 & 1) != 0 )
    {
      v14 = v8 - x;
      v15 = z;
      v16 = (float)(v8 + x) * 0.5;
      v17 = y - v12;
      v18 = (float)(y + v12) * 0.5;
      v19 = (float)(z + v13) * 0.5;
      v20 = v15 - v13;
      v21 = v14 + v16;
      v22 = v17 + v18;
      vars0 = v16 - v14;
      v48 = v18 - v17;
      v47 = v19 - v20;
      UFG::ParkourComponent::GetTransform(component, &xform);
      UFG::qInverseAffine(&d, &xform);
      d.v3.z = (float)((float)((float)(v22 * d.v0.x) + (float)(v21 * d.v0.x)) + (float)((float)(v20 + v19) * d.v1.x))
             + d.v2.x;
      d.v3.y = (float)((float)((float)(v22 * d.v0.y) + (float)(v21 * d.v0.y)) + (float)((float)(v20 + v19) * d.v1.y))
             + d.v2.y;
      d.v3.x = (float)((float)((float)(v22 * d.v0.z) + (float)(v21 * d.v0.z)) + (float)((float)(v20 + v19) * d.v1.z))
             + d.v2.z;
      xform.v0.x = d.v3.z;
      xform.v0.y = d.v3.y;
      xform.v0.z = d.v3.x;
      xform.v0.w = (float)((float)((float)(v22 * d.v0.w) + (float)(v21 * d.v0.w)) + (float)((float)(v20 + v19) * d.v1.w))
                 + d.v2.w;
      xform.v1.x = (float)((float)((float)(v22 * d.v0.x) + (float)(v21 * d.v0.x)) + (float)((float)(v19 - v20) * d.v1.x))
                 + d.v2.x;
      xform.v1.y = (float)((float)((float)(v22 * d.v0.y) + (float)(v21 * d.v0.y)) + (float)((float)(v19 - v20) * d.v1.y))
                 + d.v2.y;
      xform.v1.z = (float)((float)((float)(v22 * d.v0.z) + (float)(v21 * d.v0.z)) + (float)((float)(v19 - v20) * d.v1.z))
                 + d.v2.z;
      xform.v1.w = (float)((float)((float)(v22 * d.v0.w) + (float)(v21 * d.v0.w)) + (float)((float)(v19 - v20) * d.v1.w))
                 + d.v2.w;
      xform.v2.y = (float)((float)((float)(v48 * d.v0.y) + (float)(v21 * d.v0.y)) + (float)((float)(v20 + v19) * d.v1.y))
                 + d.v2.y;
      xform.v2.z = (float)((float)((float)(v48 * d.v0.z) + (float)(v21 * d.v0.z)) + (float)((float)(v20 + v19) * d.v1.z))
                 + d.v2.z;
      xform.v2.x = (float)((float)((float)(v48 * d.v0.x) + (float)(v21 * d.v0.x)) + (float)((float)(v20 + v19) * d.v1.x))
                 + d.v2.x;
      xform.v2.w = (float)((float)((float)(v48 * d.v0.w) + (float)(v21 * d.v0.w)) + (float)((float)(v20 + v19) * d.v1.w))
                 + d.v2.w;
      xform.v3.x = (float)((float)((float)(v48 * d.v0.x) + (float)(v21 * d.v0.x)) + (float)((float)(v19 - v20) * d.v1.x))
                 + d.v2.x;
      xform.v3.y = (float)((float)((float)(v48 * d.v0.y) + (float)(v21 * d.v0.y)) + (float)((float)(v19 - v20) * d.v1.y))
                 + d.v2.y;
      xform.v3.z = (float)((float)((float)(v48 * d.v0.z) + (float)(v21 * d.v0.z)) + (float)((float)(v19 - v20) * d.v1.z))
                 + d.v2.z;
      xform.v3.w = (float)((float)((float)(v48 * d.v0.w) + (float)(v21 * d.v0.w)) + (float)((float)(v19 - v20) * d.v1.w))
                 + d.v2.w;
      v54 = (float)((float)((float)(v22 * d.v0.y) + (float)(vars0 * d.v0.y)) + (float)((float)(v20 + v19) * d.v1.y))
          + d.v2.y;
      v55 = (float)((float)((float)(v22 * d.v0.z) + (float)(vars0 * d.v0.z)) + (float)((float)(v20 + v19) * d.v1.z))
          + d.v2.z;
      v53 = (float)((float)((float)(v22 * d.v0.x) + (float)(vars0 * d.v0.x)) + (float)((float)(v20 + v19) * d.v1.x))
          + d.v2.x;
      v56 = (float)((float)((float)(v22 * d.v0.w) + (float)(vars0 * d.v0.w)) + (float)((float)(v20 + v19) * d.v1.w))
          + d.v2.w;
      v58 = (float)((float)((float)(v22 * d.v0.y) + (float)(vars0 * d.v0.y)) + (float)((float)(v19 - v20) * d.v1.y))
          + d.v2.y;
      v57 = (float)((float)((float)(v22 * d.v0.x) + (float)(vars0 * d.v0.x)) + (float)((float)(v19 - v20) * d.v1.x))
          + d.v2.x;
      v59 = (float)((float)((float)(v22 * d.v0.z) + (float)(vars0 * d.v0.z)) + (float)((float)(v19 - v20) * d.v1.z))
          + d.v2.z;
      v60 = (float)((float)((float)(v22 * d.v0.w) + (float)(vars0 * d.v0.w)) + (float)((float)(v19 - v20) * d.v1.w))
          + d.v2.w;
      p_z = &xform.v1.z;
      v24 = 7i64;
      v61 = (float)((float)((float)(v48 * d.v0.x) + (float)(vars0 * d.v0.x)) + (float)((float)(v20 + v19) * d.v1.x))
          + d.v2.x;
      v63 = (float)((float)((float)(v48 * d.v0.z) + (float)(vars0 * d.v0.z)) + (float)((float)(v20 + v19) * d.v1.z))
          + d.v2.z;
      v62 = (float)((float)((float)(v48 * d.v0.y) + (float)(vars0 * d.v0.y)) + (float)((float)(v20 + v19) * d.v1.y))
          + d.v2.y;
      v64 = (float)((float)((float)(v48 * d.v0.w) + (float)(vars0 * d.v0.w)) + (float)((float)(v20 + v19) * d.v1.w))
          + d.v2.w;
      v65 = (float)((float)((float)(v48 * d.v0.x) + (float)(vars0 * d.v0.x)) + (float)((float)(v19 - v20) * d.v1.x))
          + d.v2.x;
      v25 = d.v3.z;
      v26 = d.v3.x;
      v27 = d.v3.x;
      v28 = d.v3.z;
      v29 = d.v3.y;
      v66 = (float)((float)((float)(v48 * d.v0.y) + (float)(vars0 * d.v0.y)) + (float)(v47 * d.v1.y)) + d.v2.y;
      v67 = (float)((float)((float)(v48 * d.v0.z) + (float)(vars0 * d.v0.z)) + (float)(v47 * d.v1.z)) + d.v2.z;
      v68 = (float)((float)((float)(v48 * d.v0.w) + (float)(vars0 * d.v0.w)) + (float)(v47 * d.v1.w)) + d.v2.w;
      v30 = d.v3.y;
      do
      {
        v31 = *p_z;
        v32 = *(p_z - 2);
        v33 = *(p_z - 1);
        if ( *p_z < v26 )
          v26 = *p_z;
        if ( v33 < v29 )
          v29 = *(p_z - 1);
        if ( v32 < v25 )
          v25 = *(p_z - 2);
        aabb1Min.x = v25;
        aabb1Min.y = v29;
        aabb1Min.z = v26;
        if ( v31 > v27 )
          v27 = v31;
        if ( v33 > v30 )
          v30 = v33;
        if ( v32 > v28 )
          v28 = v32;
        p_z += 4;
        aabb1Max.x = v28;
        aabb1Max.y = v30;
        aabb1Max.z = v27;
        --v24;
      }
      while ( v24 );
    }
    if ( UFG::ParkourContainer::TestOverlap(this, &aabb1Min, &aabb1Max, &this->mAabbMin, &this->mAabbMax) )
    {
      if ( this->mNumNodes )
      {
        UFG::ParkourContainer::VisitNodesRecursive(
          this,
          this->mNodes,
          &aabb1Min,
          &aabb1Max,
          &this->mAabbMin,
          &this->mAabbMax,
          v5);
      }
      else
      {
        v34 = 0i64;
        if ( this->mNumParkourData )
        {
          v35 = aabb1Min.z;
          v36 = aabb1Min.y;
          v37 = aabb1Min.x;
          v38 = aabb1Max.z;
          v39 = aabb1Max.y;
          v40 = aabb1Max.x;
          do
          {
            v41 = &this->mParkourData[v34];
            mVertexBuffer = this->mVertexBuffer;
            v43 = v41->v1;
            v44 = mVertexBuffer[v41->v0].x;
            if ( (v44 >= v37 || v37 <= mVertexBuffer[v43].x) && (v44 <= v40 || v40 >= mVertexBuffer[v43].x) )
            {
              v45 = mVertexBuffer[v41->v0].y;
              if ( (v45 >= v36 || v36 <= mVertexBuffer[v43].y) && (v45 <= v39 || v39 >= mVertexBuffer[v43].y) )
              {
                v46 = mVertexBuffer[v41->v0].z;
                if ( (v46 >= v35 || v35 <= mVertexBuffer[v43].z) && (v46 <= v38 || v38 >= mVertexBuffer[v43].z) )
                {
                  if ( v70->m_size == (v70->m_capacityAndFlags & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v70, 8);
                  v70->m_data[v70->m_size++] = v41;
                  v35 = aabb1Min.z;
                  v36 = aabb1Min.y;
                  v37 = aabb1Min.x;
                  v38 = aabb1Max.z;
                  v39 = aabb1Max.y;
                  v40 = aabb1Max.x;
                }
              }
            }
            v34 = (unsigned int)(v34 + 1);
          }
          while ( (unsigned int)v34 < this->mNumParkourData );
        }
      }
    }
  }
}

// File Line: 642
// RVA: 0x471C60
void __fastcall UFG::ParkourContainer::Query(
        UFG::ParkourContainer *this,
        UFG::ParkourComponent *component,
        UFG::ParkourQuery *query,
        hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *output)
{
  float x; // xmm4_4
  float z; // xmm5_4
  float y; // xmm6_4
  float w; // xmm7_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float mRadius; // xmm3_4
  UFG::qVector3 *p_mAabbMin; // rbp
  UFG::qVector3 *parentAabbMax; // rsi
  __int64 v16; // rsi
  float v17; // xmm2_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  UFG::ParkourData *v23; // rbp
  UFG::qVector3 *mVertexBuffer; // rcx
  __int64 v25; // rax
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  UFG::qVector3 aabb1Min; // [rsp+40h] [rbp-48h] BYREF
  UFG::qVector3 aabb1Max; // [rsp+50h] [rbp-38h] BYREF

  if ( this->mNumParkourData )
  {
    x = query->mCentre.x;
    z = query->mCentre.z;
    y = query->mCentre.y;
    w = query->mCentre.w;
    if ( (component->mFlags & 4) != 0 )
    {
      v10 = (float)((float)((float)(y * component->mCachedInverseTransform.v1.x)
                          + (float)(x * component->mCachedInverseTransform.v0.x))
                  + (float)(z * component->mCachedInverseTransform.v2.x))
          + (float)(w * component->mCachedInverseTransform.v3.x);
      v11 = (float)((float)((float)(x * component->mCachedInverseTransform.v0.y)
                          + (float)(y * component->mCachedInverseTransform.v1.y))
                  + (float)(z * component->mCachedInverseTransform.v2.y))
          + (float)(w * component->mCachedInverseTransform.v3.y);
      v12 = (float)(x * component->mCachedInverseTransform.v0.z) + (float)(y * component->mCachedInverseTransform.v1.z);
      x = v10;
      y = v11;
      z = (float)(v12 + (float)(query->mCentre.z * component->mCachedInverseTransform.v2.z))
        + (float)(w * component->mCachedInverseTransform.v3.z);
    }
    mRadius = query->mRadius;
    p_mAabbMin = &this->mAabbMin;
    parentAabbMax = &this->mAabbMax;
    aabb1Min.x = x - mRadius;
    aabb1Min.z = z - mRadius;
    aabb1Max.x = mRadius + x;
    aabb1Max.y = mRadius + y;
    aabb1Min.y = y - mRadius;
    aabb1Max.z = mRadius + z;
    if ( UFG::ParkourContainer::TestOverlap(this, &aabb1Min, &aabb1Max, &this->mAabbMin, &this->mAabbMax) )
    {
      if ( this->mNumNodes )
      {
        UFG::ParkourContainer::VisitNodesRecursive(
          this,
          this->mNodes,
          &aabb1Min,
          &aabb1Max,
          p_mAabbMin,
          parentAabbMax,
          output);
      }
      else
      {
        v16 = 0i64;
        if ( this->mNumParkourData )
        {
          v17 = aabb1Min.z;
          v18 = aabb1Min.y;
          v19 = aabb1Min.x;
          v20 = aabb1Max.z;
          v21 = aabb1Max.y;
          v22 = aabb1Max.x;
          do
          {
            v23 = &this->mParkourData[v16];
            mVertexBuffer = this->mVertexBuffer;
            v25 = v23->v1;
            v26 = mVertexBuffer[v23->v0].x;
            if ( (v26 >= v19 || v19 <= mVertexBuffer[v25].x) && (v26 <= v22 || v22 >= mVertexBuffer[v25].x) )
            {
              v27 = mVertexBuffer[v23->v0].y;
              if ( (v27 >= v18 || v18 <= mVertexBuffer[v25].y) && (v27 <= v21 || v21 >= mVertexBuffer[v25].y) )
              {
                v28 = mVertexBuffer[v23->v0].z;
                if ( (v28 >= v17 || v17 <= mVertexBuffer[v25].z) && (v28 <= v20 || v20 >= mVertexBuffer[v25].z) )
                {
                  if ( output->m_size == (output->m_capacityAndFlags & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, output, 8);
                  output->m_data[output->m_size++] = v23;
                  v17 = aabb1Min.z;
                  v18 = aabb1Min.y;
                  v19 = aabb1Min.x;
                  v20 = aabb1Max.z;
                  v21 = aabb1Max.y;
                  v22 = aabb1Max.x;
                }
              }
            }
            v16 = (unsigned int)(v16 + 1);
          }
          while ( (unsigned int)v16 < this->mNumParkourData );
        }
      }
    }
  }
}

// File Line: 718
// RVA: 0x4681F0
void __fastcall UFG::ParkourContainer::GetVerts(
        UFG::ParkourContainer *this,
        UFG::ParkourComponent *component,
        UFG::qMatrix44 *transform,
        UFG::ParkourData *pd,
        UFG::qVector3 *v0,
        UFG::qVector3 *v1)
{
  __int64 v6; // rax
  UFG::qVector3 *mVertexBuffer; // rdx
  float y; // xmm6_4
  float x; // xmm4_4
  float z; // xmm5_4
  float v11; // xmm7_4
  float v12; // xmm9_4
  float v13; // xmm8_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  UFG::qVector3 *v19; // rdx
  float v20; // xmm1_4
  float v21; // eax
  float v22; // xmm1_4
  float v23; // eax

  if ( component && (component->mFlags & 4) != 0 )
  {
    v6 = pd->v0;
    mVertexBuffer = this->mVertexBuffer;
    y = mVertexBuffer[v6].y;
    x = mVertexBuffer[v6].x;
    z = mVertexBuffer[v6].z;
    v11 = mVertexBuffer[pd->v1].x;
    v12 = mVertexBuffer[pd->v1].y;
    v13 = mVertexBuffer[pd->v1].z;
    v14 = (float)(x * transform->v0.x) + (float)(y * transform->v1.x);
    v15 = (float)((float)((float)(x * transform->v0.y) + (float)(y * transform->v1.y)) + (float)(z * transform->v2.y))
        + transform->v3.y;
    v16 = (float)((float)((float)(y * transform->v1.z) + (float)(x * transform->v0.z)) + (float)(z * transform->v2.z))
        + transform->v3.z;
    v0->x = (float)(v14 + (float)(z * transform->v2.x)) + transform->v3.x;
    v0->y = v15;
    v0->z = v16;
    v17 = (float)((float)((float)(v12 * transform->v1.x) + (float)(v11 * transform->v0.x))
                + (float)(v13 * transform->v2.x))
        + transform->v3.x;
    v18 = (float)((float)((float)(v12 * transform->v1.y) + (float)(v11 * transform->v0.y))
                + (float)(v13 * transform->v2.y))
        + transform->v3.y;
    v1->z = (float)((float)((float)(v12 * transform->v1.z) + (float)(v11 * transform->v0.z))
                  + (float)(v13 * transform->v2.z))
          + transform->v3.z;
    v1->x = v17;
    v1->y = v18;
  }
  else
  {
    v19 = this->mVertexBuffer;
    v20 = v19[pd->v0].z;
    v21 = v19[pd->v0].x;
    v0->y = v19[pd->v0].y;
    v0->z = v20;
    v0->x = v21;
    v22 = v19[pd->v1].z;
    v23 = v19[pd->v1].x;
    v1->y = v19[pd->v1].y;
    v1->z = v22;
    v1->x = v23;
  }
}

// File Line: 739
// RVA: 0x44A2D0
void __fastcall UFG::ParkourInstanceResource::ParkourInstanceResource(UFG::ParkourInstanceResource *this)
{
  __int64 i; // rbx
  UFG::ParkourInstanceData *RCX; // rsi
  UFG::allocator::free_link *v4; // rax

  UFG::qResourceData::qResourceData(this);
  this->mData = (UFG::ParkourInstanceData *)(((unsigned __int64)this[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64);
  for ( i = 0i64; (unsigned int)i < this->mNumInstances; i = (unsigned int)(i + 1) )
  {
    if ( &this->mData[i] )
      RCX = (UFG::ParkourInstanceData *)Assembly::GetRCX(&this->mData[i]);
    else
      RCX = 0i64;
    v4 = UFG::qMalloc(0xC8ui64, "ParkourComponent", 0x800ui64);
    if ( v4 )
      UFG::ParkourComponent::ParkourComponent((UFG::ParkourComponent *)v4, this->mNode.mUID, RCX, -1);
    RCX->mParkourComponent = (UFG::SimComponent *)v4;
  }
}

// File Line: 756
// RVA: 0x450140
void __fastcall UFG::ParkourInstanceResource::~ParkourInstanceResource(UFG::ParkourInstanceResource *this)
{
  __int64 i; // rdi
  UFG::ParkourInstanceData *v3; // rbx
  UFG::SimComponent *mParkourComponent; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *mNext; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rax

  for ( i = 0i64; (unsigned int)i < this->mNumInstances; i = (unsigned int)(i + 1) )
  {
    v3 = &this->mData[i];
    mParkourComponent = v3->mParkourComponent;
    if ( mParkourComponent )
      mParkourComponent->vfptr->__vecDelDtor(mParkourComponent, 1u);
    _((AMD_HD3D *)v3);
  }
  p_mResourceHandles = &this->mResourceHandles;
  mNext = (UFG::qResourceHandle *)this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  if ( mNext != (UFG::qResourceHandle *)&this->mResourceHandles )
  {
    do
    {
      mPrev = mNext->mPrev;
      v8 = mNext->mNext;
      mPrev->mNext = v8;
      v8->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::qResourceHandle::~qResourceHandle(mNext);
      operator delete[](mNext);
      mNext = (UFG::qResourceHandle *)this->mResourceHandles.UFG::qResourceData::mNode.mNext;
    }
    while ( mNext != (UFG::qResourceHandle *)p_mResourceHandles );
  }
  v9 = p_mResourceHandles->mNode.mPrev;
  v10 = this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  this->mResourceHandles.UFG::qResourceData::mNode.mNext = &this->mResourceHandles.UFG::qResourceData::mNode;
}

