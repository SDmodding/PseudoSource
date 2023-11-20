// File Line: 28
// RVA: 0x1514330
__int64 dynamic_initializer_for__UFG::ParkourComponent::s_ParkourComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ParkourComponent::s_ParkourComponentList__);
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
void __fastcall UFG::ParkourComponent::ParkourComponent(UFG::ParkourComponent *this, unsigned int name_uid, UFG::ParkourInstanceData *d, int followBoneIndex)
{
  int v4; // ebx
  UFG::ParkourInstanceData *v5; // r14
  UFG::ParkourComponent *v6; // rdi
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v7; // rsi
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm3
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v11; // rax
  unsigned int v12; // ebx
  UFG::qResourceInventory *v13; // rax
  UFG::qResourceWarehouse *v14; // rax

  v4 = followBoneIndex;
  v5 = d;
  v6 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v7 = (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)&v6->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ParkourComponent::`vftable';
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v6->mParkourContainer.mPrev);
  v6->mDisabledBits = 0i64;
  v6->mFlags = 2;
  v6->mTransformChangeId = -1;
  v6->mFollowBoneIndex = v4;
  if ( v5->mFlags & 1 )
  {
    v8 = UFG::qMatrix44::msIdentity.v1;
    v9 = UFG::qMatrix44::msIdentity.v2;
    v10 = UFG::qMatrix44::msIdentity.v3;
    v6->mCachedInverseTransform.v0 = UFG::qMatrix44::msIdentity.v0;
    v6->mCachedInverseTransform.v1 = v8;
    v6->mCachedInverseTransform.v2 = v9;
    v6->mCachedInverseTransform.v3 = v10;
  }
  else
  {
    v6->mFlags = 6;
  }
  v11 = UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev;
  UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev->mNext = v7;
  v7->mPrev = v11;
  v6->mNext = (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)&UFG::ParkourComponent::s_ParkourComponentList;
  UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev = (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)&v6->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v6->vfptr,
    UFG::ParkourComponent::_ParkourComponentTypeUID,
    "ParkourComponent");
  v12 = v5->mParkourContainerGuid;
  v13 = `UFG::qGetResourceInventory<UFG::ParkourContainer>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::ParkourContainer>'::`2'::result )
  {
    v14 = UFG::qResourceWarehouse::Instance();
    v13 = UFG::qResourceWarehouse::GetInventory(v14, 0x15E16140u);
    `UFG::qGetResourceInventory<UFG::ParkourContainer>'::`2'::result = v13;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6->mParkourContainer.mPrev, 0x15E16140u, v12, v13);
}

// File Line: 66
// RVA: 0x44A080
void __fastcall UFG::ParkourComponent::ParkourComponent(UFG::ParkourComponent *this, unsigned int container_uid, int followBoneIndex)
{
  int v3; // edi
  unsigned int v4; // er14
  UFG::ParkourComponent *v5; // rsi
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v6; // rbx
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax

  v3 = followBoneIndex;
  v4 = container_uid;
  v5 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, container_uid);
  v6 = (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ParkourComponent::`vftable';
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v5->mParkourContainer.mPrev);
  v5->mDisabledBits = 0i64;
  v5->mFlags = 5;
  v5->mTransformChangeId = -1;
  v5->mFollowBoneIndex = v3;
  v7 = UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev;
  UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)&v5->mPrev;
  v6->mPrev = v7;
  v5->mNext = (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)&UFG::ParkourComponent::s_ParkourComponentList;
  UFG::ParkourComponent::s_ParkourComponentList.mNode.mPrev = (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::ParkourComponent::_ParkourComponentTypeUID,
    "ParkourComponent");
  v8 = `UFG::qGetResourceInventory<UFG::ParkourContainer>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::ParkourContainer>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x15E16140u);
    `UFG::qGetResourceInventory<UFG::ParkourContainer>'::`2'::result = v8;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mParkourContainer.mPrev, 0x15E16140u, v4, v8);
}

// File Line: 76
// RVA: 0x450050
void __fastcall UFG::ParkourComponent::~ParkourComponent(UFG::ParkourComponent *this)
{
  UFG::ParkourComponent *v1; // rbx
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v2; // rdi
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v3; // rcx
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v4; // rax
  UFG::BitArray *v5; // rcx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v8; // rcx
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ParkourComponent::`vftable';
  if ( this == UFG::ParkourComponent::s_ParkourComponentpCurrentIterator )
    UFG::ParkourComponent::s_ParkourComponentpCurrentIterator = (UFG::ParkourComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mDisabledBits;
  if ( v5 )
    v5->vfptr->__vecDelDtor(v5, 1u);
  v6 = `UFG::qGetResourceInventory<UFG::ParkourContainer>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::ParkourContainer>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x15E16140u);
    `UFG::qGetResourceInventory<UFG::ParkourContainer>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mParkourContainer.mPrev, v6);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mParkourContainer.mPrev);
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 84
// RVA: 0x467F10
void __fastcall UFG::ParkourComponent::GetTransform(UFG::ParkourComponent *this, UFG::qMatrix44 *xform)
{
  UFG::SimObject *v2; // rsi
  Creature *v3; // rdi
  UFG::qMatrix44 *v4; // rbx
  UFG::ParkourComponent *v5; // rbp
  UFG::TransformNodeComponent *v6; // rsi
  UFG::qVector4 v7; // xmm3
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  UFG::SimObject *v10; // rcx
  UFG::SimComponent *v11; // rax
  UFG::qVector4 v12; // xmm1
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm3

  v2 = this->m_pSimObject;
  v3 = 0i64;
  v4 = xform;
  v5 = this;
  if ( v2 )
    v6 = v2->m_pTransformNodeComponent;
  else
    v6 = 0i64;
  if ( v6 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v6);
    v7 = v6->mWorldTransform.v1;
    v8 = v6->mWorldTransform.v2;
    v9 = v6->mWorldTransform.v3;
    v4->v0 = v6->mWorldTransform.v0;
    v4->v1 = v7;
    v4->v2 = v8;
    v4->v3 = v9;
    if ( v5->mFollowBoneIndex != -1 )
    {
      v10 = v5->m_pSimObject;
      if ( v10 )
      {
        v11 = UFG::SimObject::GetComponentOfType(v10, UFG::BaseAnimationComponent::_TypeUID);
        if ( v11 )
          v3 = *(Creature **)&v11[2].m_TypeUID;
      }
      if ( v3 )
        Creature::GetTransform(v3, v5->mFollowBoneIndex, v4);
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
  UFG::ParkourComponent *v1; // rbx
  UFG::SimObject *v2; // rdi
  Creature *v3; // rsi
  UFG::TransformNodeComponent *v4; // rdi
  unsigned int v5; // eax
  bool v6; // zf
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  UFG::SimObject *v22; // rcx
  UFG::SimComponent *v23; // rax
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-48h]

  v1 = this;
  if ( this->mFlags & 4 )
  {
    v2 = this->m_pSimObject;
    v3 = 0i64;
    v4 = v2 ? v2->m_pTransformNodeComponent : 0i64;
    v5 = v4->mChangeID;
    if ( *(_QWORD *)&this->mTransformChangeId != __PAIR__(-1, v5) )
    {
      this->mTransformChangeId = v5;
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      v6 = v1->mFollowBoneIndex == -1;
      v7 = v4->mWorldTransform.v0.y;
      transform.v0.x = v4->mWorldTransform.v0.x;
      v8 = v4->mWorldTransform.v0.z;
      transform.v0.y = v7;
      v9 = v4->mWorldTransform.v0.w;
      transform.v0.z = v8;
      v10 = v4->mWorldTransform.v1.x;
      transform.v0.w = v9;
      v11 = v4->mWorldTransform.v1.y;
      transform.v1.x = v10;
      v12 = v4->mWorldTransform.v1.z;
      transform.v1.y = v11;
      v13 = v4->mWorldTransform.v1.w;
      transform.v1.z = v12;
      v14 = v4->mWorldTransform.v2.x;
      transform.v1.w = v13;
      v15 = v4->mWorldTransform.v2.y;
      transform.v2.x = v14;
      v16 = v4->mWorldTransform.v2.z;
      transform.v2.y = v15;
      v17 = v4->mWorldTransform.v2.w;
      transform.v2.z = v16;
      v18 = v4->mWorldTransform.v3.x;
      transform.v2.w = v17;
      v19 = v4->mWorldTransform.v3.y;
      transform.v3.x = v18;
      v20 = v4->mWorldTransform.v3.z;
      transform.v3.y = v19;
      v21 = v4->mWorldTransform.v3.w;
      transform.v3.z = v20;
      transform.v3.w = v21;
      if ( !v6 )
      {
        v22 = v1->m_pSimObject;
        if ( v22 )
        {
          v23 = UFG::SimObject::GetComponentOfType(v22, UFG::BaseAnimationComponent::_TypeUID);
          if ( v23 )
            v3 = *(Creature **)&v23[2].m_TypeUID;
        }
        if ( v3 )
          Creature::GetTransform(v3, v1->mFollowBoneIndex, &transform);
      }
      UFG::qInverseAffine(&v1->mCachedInverseTransform, &transform);
    }
  }
}

// File Line: 169
// RVA: 0x44A380
void __fastcall UFG::ParkourQueryManager::ParkourQueryManager(UFG::ParkourQueryManager *this)
{
  UFG::ParkourQueryManager *v1; // rbx
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *v2; // r8
  UFG::qList<UFG::ParkourQuery,UFG::ParkourQuery,1,0> *v3; // rax
  int v4; // eax
  int v5; // er9
  int v6; // eax
  UFG::qList<UFG::ParkourQuery,UFG::ParkourQuery,1,0> *result; // [rsp+58h] [rbp+10h]

  v1 = this;
  `eh vector constructor iterator'(this, 0x10ui64, 257, (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  v2 = &v1->mTempOutput;
  v2->m_data = 0i64;
  v2->m_size = 0;
  v2->m_capacityAndFlags = 2147483648;
  *(_QWORD *)&v1->mInactiveSearchBucket = 0i64;
  *(_QWORD *)&v1->mNumQueries = 0i64;
  v3 = &v1->mQueries;
  result = v3;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v4 = v1->mTempOutput.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = 1024;
  if ( v4 < 1024 )
  {
    v6 = 2 * v4;
    if ( v6 > 1024 )
      v5 = v6;
    hkArrayUtil::_reserve((hkResult *)&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v5, 8);
  }
}

// File Line: 184
// RVA: 0x454B20
void __fastcall UFG::ParkourQueryManager::AddAsyncQuery(UFG::ParkourQueryManager *this, UFG::ParkourQuery *query)
{
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v2; // rcx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v3; // rax

  v2 = &this->mQueries.mNode;
  v3 = v2->mPrev;
  v3->mNext = (UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *)&query->mPrev;
  query->mPrev = v3;
  query->mNext = v2;
  v2->mPrev = (UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *)&query->mPrev;
}

// File Line: 191
// RVA: 0x479600
void __fastcall UFG::ParkourQueryManager::Update(UFG::ParkourQueryManager *this)
{
  UFG::ParkourQueryManager *v1; // r13
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v2; // rbx
  UFG::ParkourQuery *v3; // r15
  UFG::qList<UFG::ParkourComponent,UFG::ParkourComponent,1,0> *v4; // rcx
  UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *v5; // r14
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v6; // rdi
  UFG::ParkourContainer *v7; // rsi
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *v8; // rbx
  int v9; // er12
  __int64 v10; // r15
  UFG::ParkourData **v11; // rbx
  signed __int128 v12; // ax
  __int64 v13; // r8
  bool v14; // zf
  UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *v15; // rdx
  UFG::ParkourHandle *v16; // rax
  __int64 **v17; // rcx
  __int64 *v18; // rax
  __int64 v19; // rsi
  unsigned int v20; // ebx
  unsigned int v21; // edx
  unsigned int v22; // edx
  UFG::qSafePointer<UFG::Constraint,UFG::Constraint> *v23; // rdx
  __int64 v24; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *v27; // rax
  __int64 *v28; // rcx
  __int64 **v29; // rax
  __int64 *v30; // rcx
  __int64 **v31; // rax
  __int64 *v32; // [rsp+0h] [rbp-69h]
  __int64 **v33; // [rsp+8h] [rbp-61h]
  UFG::ParkourHandle *v34; // [rsp+10h] [rbp-59h]
  UFG::qVector3 v35; // [rsp+18h] [rbp-51h]
  UFG::qVector3 *v0; // [rsp+28h] [rbp-41h]
  __int64 v37; // [rsp+38h] [rbp-31h]
  UFG::qMatrix44 xform; // [rsp+40h] [rbp-29h]
  UFG::ParkourContainer *v39; // [rsp+D0h] [rbp+67h]
  UFG::qList<UFG::ParkourComponent,UFG::ParkourComponent,1,0> *i; // [rsp+D8h] [rbp+6Fh]
  UFG::ParkourQuery *v41; // [rsp+E0h] [rbp+77h]

  v37 = -2i64;
  v1 = this;
  ++this->mFrameNumber;
  this->mNumQueries = 0;
  v2 = UFG::ParkourComponent::s_ParkourComponentList.mNode.mNext - 4;
  for ( i = &UFG::ParkourComponent::s_ParkourComponentList - 4;
        v2 != (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)(&UFG::ParkourComponent::s_ParkourComponentList
                                                                        - 4);
        v2 = v2[4].mNext - 4 )
  {
    if ( v2[6].mPrev && !((LODWORD(v2[11].mNext) >> 3) & 1) && !((LOBYTE(v2[2].mPrev) >> 1) & 1) )
      UFG::ParkourComponent::BuildCachedInverseTransform((UFG::ParkourComponent *)v2);
  }
  v3 = (UFG::ParkourQuery *)v1->mQueries.mNode.mNext;
  v41 = v3;
  if ( v3 != (UFG::ParkourQuery *)&v1->mQueries )
  {
    v4 = &UFG::ParkourComponent::s_ParkourComponentList - 4;
    do
    {
      ++v1->mNumQueries;
      v5 = (UFG::qArray<UFG::qSafePointer<UFG::Constraint,UFG::Constraint>,0> *)&v3->handlesOut;
      v3->handlesOut.size = 0;
      v6 = UFG::ParkourComponent::s_ParkourComponentList.mNode.mNext - 4;
      if ( (UFG::qList<UFG::ParkourComponent,UFG::ParkourComponent,1,0> *)&UFG::ParkourComponent::s_ParkourComponentList.mNode.mNext[-4] == v4 )
        goto LABEL_43;
      do
      {
        if ( !v6[6].mPrev || (LODWORD(v6[11].mNext) >> 3) & 1 || (LOBYTE(v6[2].mPrev) >> 1) & 1 )
          goto LABEL_42;
        v1->mTempOutput.m_size = 0;
        UFG::ParkourComponent::GetTransform((UFG::ParkourComponent *)v6, &xform);
        v7 = (UFG::ParkourContainer *)v6[6].mPrev;
        v39 = v7;
        v8 = &v1->mTempOutput;
        UFG::ParkourContainer::Query(v7, (UFG::ParkourComponent *)v6, v3, &v1->mTempOutput);
        v9 = 0;
        if ( v1->mTempOutput.m_size <= 0 )
          goto LABEL_41;
        v10 = 0i64;
        do
        {
          v11 = v8->m_data;
          v12 = ((char *)v11[v10] - (char *)v7->mParkourData) * (signed __int128)3074457345618258603i64;
          v13 = *((_QWORD *)&v12 + 1) + (*((_QWORD *)&v12 + 1) >> 63);
          if ( (_DWORD)v13 == -1 )
          {
            v14 = ((LODWORD(v6[11].mNext) >> 3) & 1) == 0;
            goto LABEL_19;
          }
          v15 = v6[11].mPrev;
          if ( v15 )
          {
            v14 = ((*((_DWORD *)&v15[1].mPrev->mPrev + ((unsigned int)v13 >> 5)) >> (v13 & 0x1F)) & 1) == 0;
LABEL_19:
            if ( !v14 )
              goto LABEL_39;
          }
          UFG::ParkourContainer::GetVerts(v7, (UFG::ParkourComponent *)v6, &xform, v11[v10], &v35, (UFG::qVector3 *)&v0);
          if ( (float)((float)((float)(*((float *)&v0 + 1) - v35.y) * (float)(*((float *)&v0 + 1) - v35.y))
                     + (float)((float)(*(float *)&v0 - v35.x) * (float)(*(float *)&v0 - v35.x))) > 0.0049999999 )
          {
            v0 = (UFG::qVector3 *)&v0;
            v16 = UFG::ParkourQueryManager::UpdateOrCreateHandle(
                    v1,
                    (UFG::ParkourComponent *)v6,
                    v11[v10],
                    &v35,
                    (UFG::qVector3 *)&v0);
            v32 = (__int64 *)&v32;
            v33 = &v32;
            v34 = v16;
            if ( v16 )
            {
              v17 = (__int64 **)&v16->m_SafePointerList;
              v18 = (__int64 *)v16->m_SafePointerList.mNode.mPrev;
              v18[1] = (__int64)&v32;
              v32 = v18;
              v33 = v17;
              *v17 = (__int64 *)&v32;
            }
            v19 = v5->size;
            v20 = v19 + 1;
            v21 = v5->capacity;
            if ( (signed int)v19 + 1 > v21 )
            {
              if ( v21 )
                v22 = 2 * v21;
              else
                v22 = 1;
              for ( ; v22 < v20; v22 *= 2 )
                ;
              if ( v22 - v20 > 0x10000 )
                v22 = v19 + 65537;
              UFG::qArray<UFG::qSafePointer<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode>,0>::Reallocate(
                v5,
                v22,
                "qArray.Add");
            }
            v5->size = v20;
            v23 = &v5->p[v19];
            v24 = (__int64)v34;
            if ( v23->m_pPointer )
            {
              v25 = v23->mPrev;
              v26 = v23->mNext;
              v25->mNext = v26;
              v26->mPrev = v25;
              v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v23->mPrev;
              v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v23->mPrev;
            }
            v23->m_pPointer = (UFG::Constraint *)v24;
            if ( v24 )
            {
              v27 = *(UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> **)(v24 + 8);
              v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)&v23->mPrev;
              v23->mPrev = v27;
              v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Constraint>,UFG::qSafePointerNodeList> *)(v24 + 8);
              *(_QWORD *)(v24 + 8) = v23;
            }
            if ( v34 )
            {
              v28 = v32;
              v29 = v33;
              v32[1] = (__int64)v33;
              *v29 = v28;
              v32 = (__int64 *)&v32;
              v33 = &v32;
            }
            v34 = 0i64;
            v30 = v32;
            v31 = v33;
            v32[1] = (__int64)v33;
            *v31 = v30;
            v32 = (__int64 *)&v32;
            v33 = &v32;
            v7 = v39;
          }
LABEL_39:
          ++v9;
          ++v10;
          v8 = &v1->mTempOutput;
        }
        while ( v9 < v1->mTempOutput.m_size );
        v3 = v41;
LABEL_41:
        v4 = i;
LABEL_42:
        v6 = v6[4].mNext - 4;
      }
      while ( v6 != (UFG::qNode<UFG::ParkourComponent,UFG::ParkourComponent> *)v4 );
LABEL_43:
      v3 = (UFG::ParkourQuery *)v3->mNext;
      v41 = v3;
    }
    while ( v3 != (UFG::ParkourQuery *)&v1->mQueries );
  }
  UFG::ParkourQueryManager::DeleteInactive(v1);
  UFG::ParkourQueryManager::UpdateConnectivity(v1);
});
  }
  UFG::ParkourQueryManager::DeleteInactive(v1);
  UFG::ParkourQueryManager::UpdateConnectivity(v1);
}

// File Line: 324
// RVA: 0x461F50
void __fastcall UFG::ParkourQueryManager::DispatchResults(UFG::ParkourQueryManager *this)
{
  char **v1; // rbx
  UFG::ParkourQueryManager *v2; // rdi
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v3; // rcx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v4; // rax
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v5; // rdx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v6; // rax

  v1 = (char **)&this->mQueries;
  v2 = this;
  if ( (UFG::qList<UFG::ParkourQuery,UFG::ParkourQuery,1,0> *)this->mQueries.mNode.mNext != &this->mQueries )
  {
    do
    {
      v3 = v2->mQueries.mNode.mNext;
      v4 = v3->mNext;
      v5 = v3->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v3->mPrev = v3;
      v3->mNext = v3;
      v6 = v3[1].mPrev;
      if ( v6 )
        ((void (__fastcall *)(UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *))v6)(v3[1].mNext);
    }
    while ( v1[1] != (char *)v1 );
  }
}

// File Line: 362
// RVA: 0x47F8B0
void __fastcall UFG::ParkourQueryManager::UpdateOrCreateAllHandles(UFG::ParkourQueryManager *this, UFG::ParkourComponent *component, UFG::qArray<UFG::ParkourHandle *,0> *handles)
{
  UFG::ParkourContainer *v3; // r15
  UFG::qArray<UFG::ParkourHandle *,0> *v4; // rdi
  UFG::ParkourComponent *v5; // r12
  UFG::ParkourQueryManager *v6; // rsi
  UFG::ParkourData *v7; // rbx
  __int64 v8; // r14
  UFG::ParkourHandle *v9; // rax
  __int64 v10; // r13
  unsigned int v11; // ebx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::ParkourHandle **v16; // rbp
  signed __int64 v17; // r9
  signed __int64 v18; // r8
  UFG::ParkourHandle **v19; // rax
  UFG::qVector3 v1; // [rsp+30h] [rbp-98h]
  UFG::qVector3 v0; // [rsp+40h] [rbp-88h]
  UFG::qMatrix44 transform; // [rsp+50h] [rbp-78h]
  UFG::ParkourQueryManager *v23; // [rsp+D0h] [rbp+8h]
  UFG::ParkourHandle *v24; // [rsp+D8h] [rbp+10h]
  UFG::ParkourData *v25; // [rsp+E8h] [rbp+20h]

  v23 = this;
  v3 = (UFG::ParkourContainer *)component->mParkourContainer.mData;
  v4 = handles;
  v5 = component;
  v6 = this;
  if ( v3 )
  {
    v7 = v3->mParkourData;
    v25 = v3->mParkourData;
    UFG::ParkourComponent::GetTransform(component, &transform);
    v8 = 0i64;
    if ( v3->mNumParkourData )
    {
      do
      {
        UFG::ParkourContainer::GetVerts(v3, v5, &transform, v7, &v0, &v1);
        v9 = UFG::ParkourQueryManager::UpdateOrCreateHandle(v6, v5, &v7[v8], &v0, &v1);
        v10 = v4->size;
        v11 = v4->capacity;
        v12 = v10 + 1;
        v24 = v9;
        if ( (signed int)v10 + 1 > v11 )
        {
          if ( v11 )
            v13 = 2 * v11;
          else
            v13 = 1;
          for ( ; v13 < v12; v13 *= 2 )
            ;
          if ( v13 <= 2 )
            v13 = 2;
          if ( v13 - v12 > 0x10000 )
            v13 = v10 + 65537;
          if ( v13 != (_DWORD)v10 )
          {
            v14 = 8i64 * v13;
            if ( !is_mul_ok(v13, 8ui64) )
              v14 = -1i64;
            v15 = UFG::qMalloc(v14, "qArray.Add", 0i64);
            v16 = (UFG::ParkourHandle **)v15;
            if ( v4->p )
            {
              v17 = 0i64;
              if ( v4->size )
              {
                do
                {
                  v18 = v17;
                  v17 = (unsigned int)(v17 + 1);
                  v15[v18] = (UFG::allocator::free_link)v4->p[v18];
                }
                while ( (unsigned int)v17 < v4->size );
              }
              operator delete[](v4->p);
            }
            v4->p = v16;
            v4->capacity = v13;
          }
        }
        v19 = v4->p;
        v7 = v25;
        v4->size = v12;
        v6 = v23;
        v8 = (unsigned int)(v8 + 1);
        v19[v10] = v24;
      }
      while ( (unsigned int)v8 < v3->mNumParkourData );
    }
  }
}

// File Line: 384
// RVA: 0x47FA90
UFG::ParkourHandle *__fastcall UFG::ParkourQueryManager::UpdateOrCreateHandle(UFG::ParkourQueryManager *this, UFG::ParkourComponent *component, UFG::ParkourData *data, UFG::qVector3 *v0, UFG::qVector3 *v1)
{
  UFG::ParkourQueryManager *v5; // rdi
  UFG::ParkourComponent *v6; // rbx
  UFG::qVector3 *v7; // r11
  unsigned __int64 v8; // r10
  UFG::ParkourData *v9; // r9
  UFG::ParkourHandle *v10; // r8
  char *v11; // rcx
  signed __int64 v12; // rax
  UFG::SimObject *v13; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v14; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimObject *v19; // r9
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  UFG::ParkourHandle *v28; // rax
  UFG::ParkourHandle *v29; // rax

  v5 = this;
  v6 = component;
  v7 = v0;
  v8 = (unsigned int)data | ((_QWORD)component << 32);
  v9 = data;
  v10 = 0i64;
  v11 = (char *)&this->mActiveHandles[(signed int)(v8
                                                 - 257
                                                 * ((unsigned __int64)(v8 * (unsigned __int128)0xFF00FF00FF00FF01ui64 >> 64) >> 8))
                                    - 1]
      - 8;
  v12 = *((_QWORD *)v11 + 4) - 24i64;
  if ( (char *)v12 != v11 )
  {
    while ( *(_QWORD *)(v12 + 136) != v8 )
    {
      v12 = *(_QWORD *)(v12 + 32) - 24i64;
      if ( (char *)v12 == v11 )
        goto LABEL_6;
    }
    v10 = (UFG::ParkourHandle *)v12;
  }
LABEL_6:
  if ( v10 )
  {
    if ( !v10->mSimObject.m_pPointer )
    {
      v19 = component->m_pSimObject;
      v20 = &v10->mSimObject;
      if ( v10->mSimObject.m_pPointer )
      {
        v21 = v20->mPrev;
        v22 = v10->mSimObject.mNext;
        v21->mNext = v22;
        v22->mPrev = v21;
        v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20->mPrev;
        v10->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mSimObject.mPrev;
      }
      v10->mSimObject.m_pPointer = v19;
      if ( v19 )
      {
        v23 = v19->m_SafePointerList.mNode.mPrev;
        v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20->mPrev;
        v20->mPrev = v23;
        v10->mSimObject.mNext = &v19->m_SafePointerList.mNode;
        v19->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20->mPrev;
      }
    }
    v24 = v7->y;
    v25 = v7->z;
    v10->v0.x = v7->x;
    v10->v0.y = v24;
    v10->v0.z = v25;
    v26 = v1->y;
    v27 = v1->z;
    v10->v1.x = v1->x;
    v10->v1.y = v26;
    v10->v1.z = v27;
  }
  else
  {
    v10 = UFG::ParkourQueryManager::CreateHandle(v5, v8, v7, v1, v9->flags);
    v13 = v6->m_pSimObject;
    v14 = &v10->mSimObject;
    if ( v10->mSimObject.m_pPointer )
    {
      v15 = v14->mPrev;
      v16 = v10->mSimObject.mNext;
      v15->mNext = v16;
      v16->mPrev = v15;
      v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
      v10->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mSimObject.mPrev;
    }
    v10->mSimObject.m_pPointer = v13;
    if ( v13 )
    {
      v17 = &v13->m_SafePointerList.mNode;
      v18 = v13->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
      v14->mPrev = v18;
      v10->mSimObject.mNext = v17;
      v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
    }
  }
  v28 = v10->mCachedLeftNeighbor.m_pPointer;
  v10->mFramesUntilDeleted = 10;
  if ( v28 )
    v28->mFramesUntilDeleted = 10;
  v29 = v10->mCachedRightNeighbor.m_pPointer;
  if ( v29 )
    v29->mFramesUntilDeleted = 10;
  return v10;
}

// File Line: 417
// RVA: 0x4730D0
void __fastcall UFG::ParkourQueryManager::RemoveCachedHandle(UFG::ParkourQueryManager *this, UFG::ParkourComponent *component, UFG::ParkourData *data)
{
  unsigned __int64 v3; // r9
  char *v4; // rdx
  signed __int64 v5; // rcx

  v3 = (unsigned int)data | ((_QWORD)component << 32);
  v4 = (char *)&this->mActiveHandles[(signed int)((_DWORD)data
                                                - 257
                                                * ((unsigned __int64)(v3 * (unsigned __int128)0xFF00FF00FF00FF01ui64 >> 64) >> 8))
                                   - 1]
     - 8;
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
      (**(void (__fastcall ***)(signed __int64, signed __int64))v5)(v5, 1i64);
  }
}

// File Line: 429
// RVA: 0x45C9C0
UFG::ParkourHandle *__fastcall UFG::ParkourQueryManager::CreateHandle(UFG::ParkourQueryManager *this, unsigned __int64 guid, UFG::qVector3 *v0, UFG::qVector3 *v1, unsigned int flags)
{
  UFG::qVector3 *v5; // rdi
  UFG::qVector3 *v6; // rsi
  unsigned __int64 v7; // rbx
  UFG::ParkourQueryManager *v8; // rbp
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax
  __int64 v11; // r8
  UFG::qList<UFG::ParkourHandle,UFG::ParkourHandle,1,0> *v12; // rdx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **v13; // rcx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v14; // rax

  v5 = v1;
  v6 = v0;
  v7 = guid;
  v8 = this;
  v9 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0xA0ui64, "ParkourHandle", 0i64, 1u);
  if ( v9 )
  {
    UFG::ParkourHandle::ParkourHandle((UFG::ParkourHandle *)v9, v7, v6, v5, flags);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = &v8->mActiveHandles[(signed int)(v7
                                       - 257
                                       * ((unsigned __int64)(v7 * (unsigned __int128)0xFF00FF00FF00FF01ui64 >> 64) >> 8))];
  v13 = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> **)(v11 + 24);
  v14 = v12->mNode.mPrev;
  v14->mNext = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(v11 + 24);
  *v13 = v14;
  v13[1] = &v12->mNode;
  v12->mNode.mPrev = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)(v11 + 24);
  return (UFG::ParkourHandle *)v11;
}

// File Line: 442
// RVA: 0x4612D0
void __fastcall UFG::ParkourQueryManager::DeleteInactive(UFG::ParkourQueryManager *this)
{
  UFG::ParkourQueryManager *v1; // rsi
  signed __int64 v2; // rbp
  unsigned int v3; // eax
  signed __int64 v4; // rax
  signed __int64 v5; // rdi
  signed __int64 v6; // rcx
  signed __int64 v7; // rbx
  bool v8; // sf

  v1 = this;
  v2 = 257i64;
  do
  {
    v3 = ++v1->mInactiveSearchBucket;
    if ( v3 >= 0x101 )
      v3 = 0;
    v1->mInactiveSearchBucket = v3;
    v4 = v3;
    v5 = (signed __int64)&v1[-1].mNumQueries + v4 * 16;
    v6 = (signed __int64)&v1->mActiveHandles[v4].mNode.mNext[-2].mNext;
    if ( v6 != v5 )
    {
      do
      {
        v7 = *(_QWORD *)(v6 + 32) - 24i64;
        if ( !(*(_WORD *)(v6 + 148) & 0x800) && !(*(_BYTE *)(v6 + 152) & 1) && !(*(_BYTE *)(v6 + 152) & 0x1C) )
        {
          v8 = (*(_DWORD *)(v6 + 144))-- - 1 < 0;
          if ( v8 )
            (**(void (__fastcall ***)(signed __int64, signed __int64))v6)(v6, 1i64);
        }
        v6 = v7;
      }
      while ( v7 != v5 );
    }
    --v2;
  }
  while ( v2 );
}

// File Line: 475
// RVA: 0x47E290
void __fastcall UFG::ParkourQueryManager::UpdateConnectivity(UFG::ParkourQueryManager *this)
{
  UFG::ParkourQueryManager *v1; // rdi
  signed __int64 v2; // rsi
  signed __int64 v3; // rax
  signed __int64 v4; // r11
  signed __int64 i; // r9
  float *v6; // rax
  signed __int64 v7; // rdx
  signed __int64 v8; // r8
  float *v9; // rax
  unsigned int v10; // er10
  signed __int64 v11; // rcx
  signed __int64 j; // rax
  __int64 *v13; // r10
  __int64 v14; // rcx
  _QWORD *v15; // rax
  __int64 v16; // rax
  __int64 *v17; // r10
  __int64 v18; // rcx
  _QWORD *v19; // rax
  __int64 v20; // rax
  __int64 *v21; // rdx
  __int64 v22; // rcx
  _QWORD *v23; // rax
  __int64 v24; // rax
  __int64 *v25; // r8
  __int64 v26; // rcx
  _QWORD *v27; // rax
  __int64 v28; // rax

  v1 = this;
  v2 = 2i64;
  do
  {
    v3 = v1->mConnectivityUpdateBucket;
    v4 = (signed __int64)&v1[-1].mNumQueries + v3 * 16;
    v1->mConnectivityUpdateBucket = (v1->mConnectivityUpdateBucket + 1) % 0x101;
    for ( i = (signed __int64)&v1->mActiveHandles[v3].mNode.mNext[-2].mNext; i != v4; i = *(_QWORD *)(i + 32) - 24i64 )
    {
      v6 = *(float **)(i + 80);
      v7 = 0i64;
      v8 = 0i64;
      if ( v6
        && (float)((float)((float)((float)(v6[31] - *(float *)(i + 112)) * (float)(v6[31] - *(float *)(i + 112)))
                         + (float)((float)(v6[32] - *(float *)(i + 116)) * (float)(v6[32] - *(float *)(i + 116))))
                 + (float)((float)(v6[33] - *(float *)(i + 120)) * (float)(v6[33] - *(float *)(i + 120)))) <= 0.0025000002 )
      {
        v7 = *(_QWORD *)(i + 80);
      }
      v9 = *(float **)(i + 104);
      if ( v9
        && (float)((float)((float)((float)(v9[28] - *(float *)(i + 124)) * (float)(v9[28] - *(float *)(i + 124)))
                         + (float)((float)(v9[29] - *(float *)(i + 128)) * (float)(v9[29] - *(float *)(i + 128))))
                 + (float)((float)(v9[30] - *(float *)(i + 132)) * (float)(v9[30] - *(float *)(i + 132)))) <= 0.0025000002 )
      {
        v8 = *(_QWORD *)(i + 104);
      }
      v10 = 0;
      v11 = (signed __int64)&v1[-1].mNumQueries;
      do
      {
        if ( v7 && v8 )
          break;
        for ( j = *(_QWORD *)(v11 + 32) - 24i64; j != v11; j = *(_QWORD *)(j + 32) - 24i64 )
        {
          if ( v7 && v8 )
            break;
          if ( i != j )
          {
            if ( !v7
              && (float)((float)((float)((float)(*(float *)(j + 124) - *(float *)(i + 112))
                                       * (float)(*(float *)(j + 124) - *(float *)(i + 112)))
                               + (float)((float)(*(float *)(j + 128) - *(float *)(i + 116))
                                       * (float)(*(float *)(j + 128) - *(float *)(i + 116))))
                       + (float)((float)(*(float *)(j + 132) - *(float *)(i + 120))
                               * (float)(*(float *)(j + 132) - *(float *)(i + 120)))) <= 0.0025000002 )
            {
              v7 = j;
            }
            if ( !v8
              && (float)((float)((float)((float)(*(float *)(j + 116) - *(float *)(i + 128))
                                       * (float)(*(float *)(j + 116) - *(float *)(i + 128)))
                               + (float)((float)(*(float *)(j + 112) - *(float *)(i + 124))
                                       * (float)(*(float *)(j + 112) - *(float *)(i + 124))))
                       + (float)((float)(*(float *)(j + 120) - *(float *)(i + 132))
                               * (float)(*(float *)(j + 120) - *(float *)(i + 132)))) <= 0.0025000002 )
            {
              v8 = j;
            }
          }
        }
        ++v10;
        v11 += 16i64;
      }
      while ( v10 < 0x101 );
      v13 = (__int64 *)(i + 64);
      if ( *(_QWORD *)(i + 80) )
      {
        v14 = *v13;
        v15 = *(_QWORD **)(i + 72);
        *(_QWORD *)(v14 + 8) = v15;
        *v15 = v14;
        *v13 = (__int64)v13;
        *(_QWORD *)(i + 72) = i + 64;
      }
      *(_QWORD *)(i + 80) = v7;
      if ( v7 )
      {
        v16 = *(_QWORD *)(v7 + 8);
        *(_QWORD *)(v16 + 8) = v13;
        *v13 = v16;
        *(_QWORD *)(i + 72) = v7 + 8;
        *(_QWORD *)(v7 + 8) = v13;
      }
      v17 = (__int64 *)(i + 88);
      if ( *(_QWORD *)(i + 104) )
      {
        v18 = *v17;
        v19 = *(_QWORD **)(i + 96);
        *(_QWORD *)(v18 + 8) = v19;
        *v19 = v18;
        *v17 = (__int64)v17;
        *(_QWORD *)(i + 96) = i + 88;
      }
      *(_QWORD *)(i + 104) = v8;
      if ( v8 )
      {
        v20 = *(_QWORD *)(v8 + 8);
        *(_QWORD *)(v20 + 8) = v17;
        *v17 = v20;
        *(_QWORD *)(i + 96) = v8 + 8;
        *(_QWORD *)(v8 + 8) = v17;
      }
      if ( v7 )
      {
        v21 = (__int64 *)(v7 + 88);
        if ( v21[2] )
        {
          v22 = *v21;
          v23 = (_QWORD *)v21[1];
          *(_QWORD *)(v22 + 8) = v23;
          *v23 = v22;
          *v21 = (__int64)v21;
          v21[1] = (__int64)v21;
        }
        v21[2] = i;
        v24 = *(_QWORD *)(i + 8);
        *(_QWORD *)(v24 + 8) = v21;
        *v21 = v24;
        v21[1] = i + 8;
        *(_QWORD *)(i + 8) = v21;
      }
      if ( v8 )
      {
        v25 = (__int64 *)(v8 + 64);
        if ( v25[2] )
        {
          v26 = *v25;
          v27 = (_QWORD *)v25[1];
          *(_QWORD *)(v26 + 8) = v27;
          *v27 = v26;
          *v25 = (__int64)v25;
          v25[1] = (__int64)v25;
        }
        v25[2] = i;
        v28 = *(_QWORD *)(i + 8);
        *(_QWORD *)(v28 + 8) = v25;
        *v25 = v28;
        v25[1] = i + 8;
        *(_QWORD *)(i + 8) = v25;
      }
    }
    --v2;
  }
  while ( v2 );
}

// File Line: 560
// RVA: 0x471220
void __usercall UFG::ParkourContainer::Query(UFG::ParkourContainer *this@<rcx>, UFG::ParkourComponent *component@<rdx>, UFG::qVector3 *queryAabbMin@<r8>, UFG::qVector3 *queryAabbMax@<r9>, hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *a5@<rsi>, hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *output)
{
  UFG::ParkourContainer *v6; // rdi
  float v7; // xmm0_4
  float v8; // xmm5_4
  unsigned int v9; // eax
  float v10; // xmm4_4
  float v11; // xmm8_4
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
  float v23; // xmm7_4
  float v24; // ST44_4
  float v25; // ST40_4
  float *v26; // rax
  signed __int64 v27; // rcx
  float v28; // xmm4_4
  float v29; // xmm8_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm6_4
  float v33; // xmm2_4
  float v34; // xmm5_4
  float v35; // xmm3_4
  float v36; // xmm1_4
  __int64 v37; // rsi
  float v38; // xmm1_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  UFG::ParkourData *v44; // r14
  UFG::qVector3 *v45; // rcx
  __int64 v46; // rax
  float v47; // xmm6_4
  float v48; // xmm6_4
  float v49; // xmm6_4
  UFG::qVector3 aabb1Min; // [rsp+50h] [rbp-A0h]
  UFG::qVector3 aabb1Max; // [rsp+60h] [rbp-90h]
  UFG::qMatrix44 d; // [rsp+70h] [rbp-80h]
  UFG::qMatrix44 xform; // [rsp+B0h] [rbp-40h]
  float v54; // [rsp+F0h] [rbp+0h]
  float v55; // [rsp+F4h] [rbp+4h]
  float v56; // [rsp+F8h] [rbp+8h]
  float v57; // [rsp+FCh] [rbp+Ch]
  float v58; // [rsp+100h] [rbp+10h]
  float v59; // [rsp+104h] [rbp+14h]
  float v60; // [rsp+108h] [rbp+18h]
  float v61; // [rsp+10Ch] [rbp+1Ch]
  float v62; // [rsp+110h] [rbp+20h]
  float v63; // [rsp+114h] [rbp+24h]
  float v64; // [rsp+118h] [rbp+28h]
  float v65; // [rsp+11Ch] [rbp+2Ch]
  float v66; // [rsp+120h] [rbp+30h]
  float v67; // [rsp+124h] [rbp+34h]
  float v68; // [rsp+128h] [rbp+38h]
  float v69; // [rsp+12Ch] [rbp+3Ch]
  float vars0; // [rsp+1F0h] [rbp+100h]
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *v71; // [rsp+210h] [rbp+120h]

  v6 = this;
  if ( this->mNumParkourData )
  {
    v7 = queryAabbMin->x;
    v8 = queryAabbMax->x;
    v71 = a5;
    v9 = component->mFlags >> 2;
    v10 = queryAabbMax->y;
    aabb1Min.x = queryAabbMin->x;
    aabb1Max.x = v8;
    v11 = queryAabbMax->z;
    v12 = queryAabbMin->y;
    v13 = queryAabbMin->z;
    aabb1Max.z = queryAabbMax->z;
    aabb1Min.y = v12;
    aabb1Min.z = v13;
    aabb1Max.y = v10;
    if ( v9 & 1 )
    {
      v14 = v8 - v7;
      v15 = v11;
      v16 = (float)(v8 + v7) * 0.5;
      v17 = v10 - v12;
      v18 = (float)(v10 + v12) * 0.5;
      v19 = (float)(v11 + v13) * 0.5;
      v20 = v15 - v13;
      v21 = v14 + v16;
      v22 = v17 + v18;
      vars0 = v16 - v14;
      v23 = v20 + v19;
      v24 = v18 - v17;
      v25 = v19 - v20;
      UFG::ParkourComponent::GetTransform(component, &xform);
      UFG::qInverseAffine(&d, &xform);
      d.v3.z = (float)((float)((float)(v22 * d.v0.x) + (float)(v21 * d.v0.x)) + (float)((float)(v20 + v19) * d.v1.x))
             + d.v2.x;
      d.v3.y = (float)((float)((float)(v22 * d.v0.y) + (float)(v21 * d.v0.y)) + (float)((float)(v20 + v19) * d.v1.y))
             + d.v2.y;
      d.v3.x = (float)((float)((float)(v22 * d.v0.z) + (float)(v21 * d.v0.z)) + (float)((float)(v20 + v19) * d.v1.z))
             + d.v2.z;
      xform.v0.x = (float)((float)((float)(v22 * d.v0.x) + (float)(v21 * d.v0.x)) + (float)((float)(v20 + v19) * d.v1.x))
                 + d.v2.x;
      xform.v0.y = (float)((float)((float)(v22 * d.v0.y) + (float)(v21 * d.v0.y)) + (float)((float)(v20 + v19) * d.v1.y))
                 + d.v2.y;
      xform.v0.z = (float)((float)((float)(v22 * d.v0.z) + (float)(v21 * d.v0.z)) + (float)((float)(v20 + v19) * d.v1.z))
                 + d.v2.z;
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
      xform.v2.y = (float)((float)((float)(v24 * d.v0.y) + (float)(v21 * d.v0.y)) + (float)((float)(v20 + v19) * d.v1.y))
                 + d.v2.y;
      xform.v2.z = (float)((float)((float)(v24 * d.v0.z) + (float)(v21 * d.v0.z)) + (float)((float)(v20 + v19) * d.v1.z))
                 + d.v2.z;
      xform.v2.x = (float)((float)((float)(v24 * d.v0.x) + (float)(v21 * d.v0.x)) + (float)((float)(v20 + v19) * d.v1.x))
                 + d.v2.x;
      xform.v2.w = (float)((float)((float)(v24 * d.v0.w) + (float)(v21 * d.v0.w)) + (float)((float)(v20 + v19) * d.v1.w))
                 + d.v2.w;
      xform.v3.x = (float)((float)((float)(v24 * d.v0.x) + (float)(v21 * d.v0.x)) + (float)((float)(v19 - v20) * d.v1.x))
                 + d.v2.x;
      xform.v3.y = (float)((float)((float)(v24 * d.v0.y) + (float)(v21 * d.v0.y)) + (float)((float)(v19 - v20) * d.v1.y))
                 + d.v2.y;
      xform.v3.z = (float)((float)((float)(v24 * d.v0.z) + (float)(v21 * d.v0.z)) + (float)((float)(v19 - v20) * d.v1.z))
                 + d.v2.z;
      xform.v3.w = (float)((float)((float)(v24 * d.v0.w) + (float)(v21 * d.v0.w)) + (float)((float)(v19 - v20) * d.v1.w))
                 + d.v2.w;
      v55 = (float)((float)((float)(v22 * d.v0.y) + (float)(vars0 * d.v0.y)) + (float)((float)(v20 + v19) * d.v1.y))
          + d.v2.y;
      v56 = (float)((float)((float)(v22 * d.v0.z) + (float)(vars0 * d.v0.z)) + (float)((float)(v20 + v19) * d.v1.z))
          + d.v2.z;
      v54 = (float)((float)((float)(v22 * d.v0.x) + (float)(vars0 * d.v0.x)) + (float)((float)(v20 + v19) * d.v1.x))
          + d.v2.x;
      v57 = (float)((float)((float)(v22 * d.v0.w) + (float)(vars0 * d.v0.w)) + (float)((float)(v20 + v19) * d.v1.w))
          + d.v2.w;
      v59 = (float)((float)((float)(v22 * d.v0.y) + (float)(vars0 * d.v0.y)) + (float)((float)(v19 - v20) * d.v1.y))
          + d.v2.y;
      v58 = (float)((float)((float)(v22 * d.v0.x) + (float)(vars0 * d.v0.x)) + (float)((float)(v19 - v20) * d.v1.x))
          + d.v2.x;
      v60 = (float)((float)((float)(v22 * d.v0.z) + (float)(vars0 * d.v0.z)) + (float)((float)(v19 - v20) * d.v1.z))
          + d.v2.z;
      v61 = (float)((float)((float)(v22 * d.v0.w) + (float)(vars0 * d.v0.w)) + (float)((float)(v19 - v20) * d.v1.w))
          + d.v2.w;
      v26 = &xform.v1.z;
      v27 = 7i64;
      v62 = (float)((float)((float)(v24 * d.v0.x) + (float)(vars0 * d.v0.x)) + (float)((float)(v20 + v19) * d.v1.x))
          + d.v2.x;
      v64 = (float)((float)((float)(v24 * d.v0.z) + (float)(vars0 * d.v0.z)) + (float)((float)(v20 + v19) * d.v1.z))
          + d.v2.z;
      v63 = (float)((float)((float)(v24 * d.v0.y) + (float)(vars0 * d.v0.y)) + (float)((float)(v20 + v19) * d.v1.y))
          + d.v2.y;
      v65 = (float)((float)((float)(v24 * d.v0.w) + (float)(vars0 * d.v0.w)) + (float)((float)(v20 + v19) * d.v1.w))
          + d.v2.w;
      v66 = (float)((float)((float)(v24 * d.v0.x) + (float)(vars0 * d.v0.x)) + (float)((float)(v19 - v20) * d.v1.x))
          + d.v2.x;
      v28 = (float)((float)((float)(v22 * d.v0.x) + (float)(v21 * d.v0.x)) + (float)((float)(v20 + v19) * d.v1.x))
          + d.v2.x;
      v29 = (float)((float)((float)(v22 * d.v0.z) + (float)(v21 * d.v0.z)) + (float)((float)(v20 + v19) * d.v1.z))
          + d.v2.z;
      v30 = (float)((float)((float)(v22 * d.v0.z) + (float)(v21 * d.v0.z)) + (float)(v23 * d.v1.z)) + d.v2.z;
      v31 = d.v3.z;
      v32 = d.v3.y;
      v67 = (float)((float)((float)(v24 * d.v0.y) + (float)(vars0 * d.v0.y)) + (float)(v25 * d.v1.y)) + d.v2.y;
      v68 = (float)((float)((float)(v24 * d.v0.z) + (float)(vars0 * d.v0.z)) + (float)(v25 * d.v1.z)) + d.v2.z;
      v69 = (float)((float)((float)(v24 * d.v0.w) + (float)(vars0 * d.v0.w)) + (float)(v25 * d.v1.w)) + d.v2.w;
      v33 = d.v3.y;
      do
      {
        v34 = *v26;
        v35 = *(v26 - 2);
        v36 = *(v26 - 1);
        if ( *v26 < v29 )
          v29 = *v26;
        if ( v36 < v32 )
          v32 = *(v26 - 1);
        if ( v35 < v28 )
          v28 = *(v26 - 2);
        aabb1Min.x = v28;
        aabb1Min.y = v32;
        aabb1Min.z = v29;
        if ( v34 > v30 )
          v30 = v34;
        if ( v36 > v33 )
          v33 = v36;
        if ( v35 > v31 )
          v31 = v35;
        v26 += 4;
        aabb1Max.x = v31;
        aabb1Max.y = v33;
        aabb1Max.z = v30;
        --v27;
      }
      while ( v27 );
    }
    if ( UFG::ParkourContainer::TestOverlap(v6, &aabb1Min, &aabb1Max, &v6->mAabbMin, &v6->mAabbMax) )
    {
      if ( v6->mNumNodes )
      {
        UFG::ParkourContainer::VisitNodesRecursive(
          v6,
          v6->mNodes,
          &aabb1Min,
          &aabb1Max,
          &v6->mAabbMin,
          &v6->mAabbMax,
          a5);
      }
      else
      {
        v37 = 0i64;
        if ( v6->mNumParkourData )
        {
          v38 = aabb1Min.z;
          v39 = aabb1Min.y;
          v40 = aabb1Min.x;
          v41 = aabb1Max.z;
          v42 = aabb1Max.y;
          v43 = aabb1Max.x;
          do
          {
            v44 = &v6->mParkourData[v37];
            v45 = v6->mVertexBuffer;
            v46 = v44->v1;
            v47 = v45[v44->v0].x;
            if ( (v47 >= v40 || v40 <= v45[v46].x) && (v47 <= v43 || v43 >= v45[v46].x) )
            {
              v48 = v45[v44->v0].y;
              if ( (v48 >= v39 || v39 <= v45[v46].y) && (v48 <= v42 || v42 >= v45[v46].y) )
              {
                v49 = v45[v44->v0].z;
                if ( (v49 >= v38 || v38 <= v45[v46].z) && (v49 <= v41 || v41 >= v45[v46].z) )
                {
                  if ( v71->m_size == (v71->m_capacityAndFlags & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v71, 8);
                  v71->m_data[v71->m_size++] = v44;
                  v38 = aabb1Min.z;
                  v39 = aabb1Min.y;
                  v40 = aabb1Min.x;
                  v41 = aabb1Max.z;
                  v42 = aabb1Max.y;
                  v43 = aabb1Max.x;
                }
              }
            }
            v37 = (unsigned int)(v37 + 1);
          }
          while ( (unsigned int)v37 < v6->mNumParkourData );
        }
      }
    }
  }
}

// File Line: 642
// RVA: 0x471C60
void __fastcall UFG::ParkourContainer::Query(UFG::ParkourContainer *this, UFG::ParkourComponent *component, UFG::ParkourQuery *query, hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *output)
{
  hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *v4; // rbx
  UFG::ParkourContainer *v5; // rdi
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float v13; // xmm3_4
  UFG::qVector3 *v14; // rbp
  UFG::qVector3 *parentAabbMax; // rsi
  __int64 v16; // rsi
  float v17; // xmm2_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  UFG::ParkourData *v23; // rbp
  UFG::qVector3 *v24; // rcx
  __int64 v25; // rax
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  UFG::qVector3 aabb1Min; // [rsp+40h] [rbp-48h]
  UFG::qVector3 aabb1Max; // [rsp+50h] [rbp-38h]

  v4 = output;
  v5 = this;
  if ( this->mNumParkourData )
  {
    v6 = query->mCentre.x;
    v7 = query->mCentre.z;
    v8 = query->mCentre.y;
    v9 = query->mCentre.w;
    if ( (component->mFlags >> 2) & 1 )
    {
      v10 = (float)((float)((float)(v8 * component->mCachedInverseTransform.v1.x)
                          + (float)(v6 * component->mCachedInverseTransform.v0.x))
                  + (float)(v7 * component->mCachedInverseTransform.v2.x))
          + (float)(v9 * component->mCachedInverseTransform.v3.x);
      v11 = (float)((float)((float)(v6 * component->mCachedInverseTransform.v0.y)
                          + (float)(v8 * component->mCachedInverseTransform.v1.y))
                  + (float)(v7 * component->mCachedInverseTransform.v2.y))
          + (float)(v9 * component->mCachedInverseTransform.v3.y);
      v12 = (float)(v6 * component->mCachedInverseTransform.v0.z)
          + (float)(v8 * component->mCachedInverseTransform.v1.z);
      v6 = v10;
      v8 = v11;
      v7 = (float)(v12 + (float)(query->mCentre.z * component->mCachedInverseTransform.v2.z))
         + (float)(v9 * component->mCachedInverseTransform.v3.z);
    }
    v13 = query->mRadius;
    v14 = &this->mAabbMin;
    parentAabbMax = &this->mAabbMax;
    aabb1Min.x = v6 - v13;
    aabb1Min.z = v7 - v13;
    aabb1Max.x = v13 + v6;
    aabb1Max.y = v13 + v8;
    aabb1Min.y = v8 - v13;
    aabb1Max.z = v13 + v7;
    if ( UFG::ParkourContainer::TestOverlap(this, &aabb1Min, &aabb1Max, &this->mAabbMin, &this->mAabbMax) )
    {
      if ( v5->mNumNodes )
      {
        UFG::ParkourContainer::VisitNodesRecursive(v5, v5->mNodes, &aabb1Min, &aabb1Max, v14, parentAabbMax, v4);
      }
      else
      {
        v16 = 0i64;
        if ( v5->mNumParkourData )
        {
          v17 = aabb1Min.z;
          v18 = aabb1Min.y;
          v19 = aabb1Min.x;
          v20 = aabb1Max.z;
          v21 = aabb1Max.y;
          v22 = aabb1Max.x;
          do
          {
            v23 = &v5->mParkourData[v16];
            v24 = v5->mVertexBuffer;
            v25 = v23->v1;
            v26 = v24[v23->v0].x;
            if ( (v26 >= v19 || v19 <= v24[v25].x) && (v26 <= v22 || v22 >= v24[v25].x) )
            {
              v27 = v24[v23->v0].y;
              if ( (v27 >= v18 || v18 <= v24[v25].y) && (v27 <= v21 || v21 >= v24[v25].y) )
              {
                v28 = v24[v23->v0].z;
                if ( (v28 >= v17 || v17 <= v24[v25].z) && (v28 <= v20 || v20 >= v24[v25].z) )
                {
                  if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
                  v4->m_data[v4->m_size++] = v23;
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
          while ( (unsigned int)v16 < v5->mNumParkourData );
        }
      }
    }
  }
}

// File Line: 718
// RVA: 0x4681F0
void __fastcall UFG::ParkourContainer::GetVerts(UFG::ParkourContainer *this, UFG::ParkourComponent *component, UFG::qMatrix44 *transform, UFG::ParkourData *pd, UFG::qVector3 *v0, UFG::qVector3 *v1)
{
  __int64 v6; // rax
  UFG::qVector3 *v7; // rdx
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm7_4
  float v12; // xmm9_4
  float v13; // xmm8_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  UFG::qVector3 *v21; // rdx
  float v22; // xmm1_4
  float v23; // eax
  float v24; // xmm1_4
  float v25; // eax

  if ( component && (component->mFlags >> 2) & 1 )
  {
    v6 = pd->v0;
    v7 = this->mVertexBuffer;
    v8 = v7[v6].y;
    v9 = v7[v6].x;
    v10 = v7[v6].z;
    v11 = v7[pd->v1].x;
    v12 = v7[pd->v1].y;
    v13 = v7[pd->v1].z;
    v14 = (float)(v9 * transform->v0.x) + (float)(v8 * transform->v1.x);
    v15 = v7[pd->v1].x;
    v16 = v7[pd->v1].z;
    v17 = (float)((float)((float)(v9 * transform->v0.y) + (float)(v8 * transform->v1.y)) + (float)(v10 * transform->v2.y))
        + transform->v3.y;
    v18 = (float)((float)((float)(v8 * transform->v1.z) + (float)(v9 * transform->v0.z)) + (float)(v10 * transform->v2.z))
        + transform->v3.z;
    v0->x = (float)(v14 + (float)(v10 * transform->v2.x)) + transform->v3.x;
    v0->y = v17;
    v0->z = v18;
    v19 = (float)((float)((float)(v12 * transform->v1.x) + (float)(v15 * transform->v0.x))
                + (float)(v16 * transform->v2.x))
        + transform->v3.x;
    v20 = (float)((float)((float)(v12 * transform->v1.y) + (float)(v11 * transform->v0.y))
                + (float)(v13 * transform->v2.y))
        + transform->v3.y;
    v1->z = (float)((float)((float)(v12 * transform->v1.z) + (float)(v11 * transform->v0.z))
                  + (float)(v13 * transform->v2.z))
          + transform->v3.z;
    v1->x = v19;
    v1->y = v20;
  }
  else
  {
    v21 = this->mVertexBuffer;
    v22 = v21[pd->v0].z;
    v23 = v21[pd->v0].x;
    v0->y = v21[pd->v0].y;
    v0->z = v22;
    v0->x = v23;
    v24 = v21[pd->v1].z;
    v25 = v21[pd->v1].x;
    v1->y = v21[pd->v1].y;
    v1->z = v24;
    v1->x = v25;
  }
}

// File Line: 739
// RVA: 0x44A2D0
void __fastcall UFG::ParkourInstanceResource::ParkourInstanceResource(UFG::ParkourInstanceResource *this)
{
  UFG::ParkourInstanceResource *v1; // rdi
  __int64 v2; // rbx
  UFG::ParkourInstanceData *v3; // rsi
  UFG::allocator::free_link *v4; // rax

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v1->mData = (UFG::ParkourInstanceData *)(((unsigned __int64)v1[1].mNode.mChild + 7) & 0xFFFFFFFFFFFFFFF0ui64);
  v2 = 0i64;
  if ( v1->mNumInstances )
  {
    do
    {
      if ( &v1->mData[v2] )
        v3 = (UFG::ParkourInstanceData *)Assembly::GetRCX(&v1->mData[v2]);
      else
        v3 = 0i64;
      v4 = UFG::qMalloc(0xC8ui64, "ParkourComponent", 0x800ui64);
      if ( v4 )
        UFG::ParkourComponent::ParkourComponent((UFG::ParkourComponent *)v4, v1->mNode.mUID, v3, -1);
      v3->mParkourComponent = (UFG::SimComponent *)v4;
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v1->mNumInstances );
  }
}

// File Line: 756
// RVA: 0x450140
void __fastcall UFG::ParkourInstanceResource::~ParkourInstanceResource(UFG::ParkourInstanceResource *this)
{
  UFG::ParkourInstanceResource *v1; // rsi
  __int64 v2; // rdi
  signed __int64 v3; // rbx
  void (__fastcall ***v4)(_QWORD, signed __int64); // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v5; // rdi
  UFG::qResourceHandle *v6; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rax

  v1 = this;
  v2 = 0i64;
  if ( this->mNumInstances )
  {
    do
    {
      v3 = (signed __int64)&v1->mData[v2];
      v4 = *(void (__fastcall ****)(_QWORD, signed __int64))(v3 + 64);
      if ( v4 )
        (**v4)(v4, 1i64);
      _((AMD_HD3D *)v3);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v1->mNumInstances );
  }
  v5 = &v1->mResourceHandles;
  v6 = (UFG::qResourceHandle *)v1->mResourceHandles.mNode.mNext;
  if ( v6 != (UFG::qResourceHandle *)&v1->mResourceHandles )
  {
    do
    {
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v6->mPrev;
      v6->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v6->mPrev;
      UFG::qResourceHandle::~qResourceHandle(v6);
      operator delete[](v6);
      v6 = (UFG::qResourceHandle *)v1->mResourceHandles.mNode.mNext;
    }
    while ( v6 != (UFG::qResourceHandle *)v5 );
  }
  v9 = v5->mNode.mPrev;
  v10 = v1->mResourceHandles.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v5->mNode.mPrev = &v5->mNode;
  v1->mResourceHandles.mNode.mNext = &v1->mResourceHandles.mNode;
}

