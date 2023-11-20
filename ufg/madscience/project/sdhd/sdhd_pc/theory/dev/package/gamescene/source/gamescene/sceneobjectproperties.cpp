// File Line: 48
// RVA: 0x23E2A0
signed __int64 __fastcall UFG::PhantomVolumeComponent::GetTypeSize(UFG::qReflectInventory<UFG::PhysicsSurfaceProperties> *this)
{
  return 168i64;
}

// File Line: 94
// RVA: 0x237B30
void __fastcall UFG::SceneObjectProperties::SceneObjectProperties(UFG::SceneObjectProperties *this, UFG::qSymbol *name, UFG::SceneLayerResource *pLayerResource, UFG::qPropertySet *pLocalProperties, UFG::SceneObjectProperties *pParent, bool isChild)
{
  UFG::qPropertySet *v6; // rsi
  UFG::SceneLayerResource *v7; // rbx
  UFG::qSymbol *v8; // r14
  UFG::SceneObjectProperties *v9; // rdi
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v10; // rax
  UFG::qPropertySet *v11; // rax
  UFG::qPropertySet *v12; // rcx
  UFG::qPropertySet *v13; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v14; // [rsp+58h] [rbp+10h]

  v6 = pLocalProperties;
  v7 = pLayerResource;
  v8 = name;
  v9 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name->mUID);
  v10 = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v9->mPrev;
  v10->mPrev = v10;
  v10->mNext = v10;
  v9->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SceneObjectProperties::`vftable;
  v14 = &v9->mpOwner;
  v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v9->mpOwner.m_pPointer = 0i64;
  v9->mpLayerResource = v7;
  v9->mpParent = 0i64;
  v9->mChildren = 0ui64;
  v9->mDeleteChildSimObjectOnDestruct = 1;
  v9->mLastTeleportFrame = 0;
  v9->mPrevNameHash = 0;
  v9->mChildIndex = -1;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v9->vfptr,
    UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID,
    "SceneObjectProperties");
  if ( isChild )
  {
    v9->mpConstProperties = 0i64;
    v11 = UFG::qPropertySet::CreateContainedSet(&v6->mName, "ChildProperties");
    v9->mpWritableProperties = v11;
    UFG::qPropertySet::CopyFrom(v11, v6, 1);
    v12 = v9->mpWritableProperties;
  }
  else if ( v6 )
  {
    v9->mpConstProperties = v6;
    v9->mpWritableProperties = 0i64;
    v12 = v6;
  }
  else
  {
    v13 = UFG::qPropertySet::CreateContainedSet(v8, "SceneObject_PropertySet");
    v9->mpWritableProperties = v13;
    v9->mpConstProperties = 0i64;
    v12 = v13;
  }
  UFG::qPropertySet::AddRef(v12);
  UFG::SceneObjectProperties::SetParent(v9, pParent);
  if ( v9->mpParent )
    v9->m_Flags &= 0xFFF7u;
  else
    v9->m_Flags |= 8u;
}

// File Line: 142
// RVA: 0x237CA0
void __fastcall UFG::SceneObjectProperties::SceneObjectProperties(UFG::SceneObjectProperties *this, UFG::qPropertySet *pParentPropertySet, UFG::SceneLayerResource *pLayerResource)
{
  UFG::SceneLayerResource *v3; // rbx
  UFG::qPropertySet *v4; // rbp
  UFG::SceneObjectProperties *v5; // rdi
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v6; // rsi
  UFG::SceneLayerResource *v7; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v8; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // [rsp+58h] [rbp+10h]

  v3 = pLayerResource;
  v4 = pParentPropertySet;
  v5 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v6 = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SceneObjectProperties::`vftable;
  v10 = &v5->mpOwner;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v5->mpOwner.m_pPointer = 0i64;
  v5->mpLayerResource = v3;
  v5->mpParent = 0i64;
  v5->mChildren = 0ui64;
  v5->mDeleteChildSimObjectOnDestruct = 1;
  v5->mPrevNameHash = 0;
  v5->mChildIndex = -1;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID,
    "SceneObjectProperties");
  if ( v5->mpParent )
    v5->m_Flags &= 0xFFF7u;
  else
    v5->m_Flags |= 8u;
  v5->mpConstProperties = v4;
  UFG::qPropertySet::AddRef(v4);
  v5->mpWritableProperties = 0i64;
  v5->m_NameUID = v4->mName.mUID;
  v7 = v5->mpLayerResource;
  if ( v7 )
  {
    v8 = &v7->mObjects.mNode;
    v9 = v8->mPrev;
    v9->mNext = v6;
    v6->mPrev = v9;
    v5->mNext = v8;
    v8->mPrev = v6;
  }
  UFG::SceneObjectProperties::InstantiateChildObjects(v5, 0);
}

// File Line: 161
// RVA: 0x14753A0
__int64 UFG::_dynamic_initializer_for__gLocalPropertySet__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("WritableSceneObjProperties", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gLocalPropertySet, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gLocalPropertySet__);
}

// File Line: 165
// RVA: 0x23E2F0
UFG::qPropertySet *__fastcall UFG::SceneObjectProperties::GetWritableProperties(UFG::SceneObjectProperties *this)
{
  UFG::qPropertySet *result; // rax
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rax

  result = this->mpWritableProperties;
  v2 = this;
  if ( !result )
  {
    v3 = UFG::qPropertySet::CreateContainedSet(
           (UFG::qSymbol *)&UFG::gLocalPropertySet.mUID,
           "WritableSceneObjProperties");
    v2->mpWritableProperties = v3;
    UFG::qPropertySet::AddRef(v3);
    UFG::PSWrapper::AppendParentLocal(v2->mpWritableProperties, v2->mpConstProperties);
    result = v2->mpWritableProperties;
  }
  return result;
}

// File Line: 183
// RVA: 0x23E2D0
UFG::qPropertySet *__fastcall UFG::SceneObjectProperties::GetWritablePersistentProperties(UFG::SceneObjectProperties *this)
{
  UFG::qPropertySet *result; // rax

  result = this->mpConstProperties;
  if ( !result )
    result = this->mpWritableProperties;
  return result;
}

// File Line: 197
// RVA: 0x23BFE0
UFG::qResourceData *__fastcall UFG::SceneObjectProperties::GetArchetypeProperties(UFG::SceneObjectProperties *this)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qPropertySet *v2; // rcx
  UFG::qPropertySet *v3; // rcx

  v1 = this;
  v2 = this->mpConstProperties;
  if ( !v2 )
    v2 = v1->mpWritableProperties;
  if ( (unsigned int)UFG::qPropertySet::NumParents(v2) < 1 )
    return 0i64;
  v3 = v1->mpConstProperties;
  if ( !v3 )
    v3 = v1->mpWritableProperties;
  return UFG::qPropertySet::GetParentFromIdx(v3, 0);
}

// File Line: 228
// RVA: 0x23C030
UFG::qSymbol *__fastcall UFG::SceneObjectProperties::GetArchetypePropertiesName(UFG::SceneObjectProperties *this)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qPropertySet *v2; // rcx
  UFG::qPropertySet *v3; // rcx
  UFG::qResourceData *v4; // rax
  UFG::qSymbol *result; // rax

  v1 = this;
  v2 = this->mpConstProperties;
  if ( !v2 )
    v2 = v1->mpWritableProperties;
  if ( (unsigned int)UFG::qPropertySet::NumParents(v2) < 1 )
    goto LABEL_11;
  v3 = v1->mpConstProperties;
  if ( !v3 )
    v3 = v1->mpWritableProperties;
  v4 = UFG::qPropertySet::GetParentFromIdx(v3, 0);
  if ( v4 )
    result = (UFG::qSymbol *)&v4->mDebugName[12];
  else
LABEL_11:
    result = &UFG::gNullQSymbol;
  return result;
}

// File Line: 248
// RVA: 0x23D8C0
UFG::SceneLayerResource *__fastcall UFG::SceneObjectProperties::GetLayer(UFG::SceneObjectProperties *this)
{
  UFG::SceneLayerResource *result; // rax

  result = this->mpLayerResource;
  if ( result )
    result = (UFG::SceneLayerResource *)result->mpRuntimeSceneLayer;
  return result;
}

// File Line: 310
// RVA: 0x2386D0
void __fastcall UFG::SceneObjectProperties::~SceneObjectProperties(UFG::SceneObjectProperties *this)
{
  UFG::SceneObjectProperties *v1; // rdi
  qSetLogical<UFG::SceneObjectProperties,UFG::qSymbol> *v2; // rsi
  unsigned int v3; // er8
  UFG::SceneObjectProperties **v4; // rcx
  UFG::SceneObjectProperties *v5; // rbx
  int v6; // er8
  UFG::SimObject *v7; // rcx
  UFG::SceneObjectProperties **v8; // rcx
  int v9; // er8
  UFG::SimObject *v10; // rax
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v11; // rdx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v12; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v13; // rax
  UFG::qPropertySet *v14; // rcx
  UFG::qPropertySet *v15; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v21; // rdx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v22; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v23; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SceneObjectProperties::`vftable;
  v2 = &this->mChildren;
  v3 = this->mChildren.mCount;
  if ( v3 )
  {
    v4 = this->mChildren.mppArray;
    v5 = *v4;
    v6 = v3 - 1;
    v2->mCount = v6;
    UFG::qMemMove(v4, v4 + 1, 8 * v6);
    while ( v5 )
    {
      v5->mpParent = 0i64;
      v7 = v5->m_pSimObject;
      if ( v7 )
      {
        if ( v1->mDeleteChildSimObjectOnDestruct )
        {
          if ( v1->m_Flags & 8 )
            v5->m_Flags |= 8u;
          UFG::SimObject::Destroy(v7);
        }
      }
      else
      {
        v5->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v5->vfptr, 1u);
      }
      if ( !v2->mCount )
        break;
      v8 = v2->mppArray;
      v5 = *v8;
      v9 = v2->mCount - 1;
      v2->mCount = v9;
      UFG::qMemMove(v8, v8 + 1, 8 * v9);
    }
  }
  UFG::SceneObjectProperties::SetParent(v1, 0i64);
  v10 = v1->m_pSimObject;
  if ( v10 )
    v10->m_pSceneObj = 0i64;
  if ( v1->mpLayerResource )
  {
    v11 = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v1->mPrev;
    v12 = v1->mPrev;
    v13 = v1->mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = v11;
    v11->mNext = v11;
  }
  v14 = v1->mpWritableProperties;
  if ( v14 )
  {
    UFG::qPropertySet::ReleaseRef(v14);
    v1->mpWritableProperties = 0i64;
  }
  v15 = v1->mpConstProperties;
  if ( v15 )
  {
    UFG::qPropertySet::ReleaseRef(v15);
    v1->mpConstProperties = 0i64;
  }
  operator delete[](v2->mppArray);
  v16 = &v1->mpOwner;
  if ( v1->mpOwner.m_pPointer )
  {
    v17 = v16->mPrev;
    v18 = v1->mpOwner.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v1->mpOwner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpOwner.mPrev;
  }
  v1->mpOwner.m_pPointer = 0i64;
  v19 = v16->mPrev;
  v20 = v1->mpOwner.mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v16->mPrev;
  v1->mpOwner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpOwner.mPrev;
  v21 = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v1->mPrev;
  v22 = v1->mPrev;
  v23 = v1->mNext;
  v22->mNext = v23;
  v23->mPrev = v22;
  v21->mPrev = v21;
  v21->mNext = v21;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}
  v21->mPrev = v21;
  v21->mNext = v21;
  UFG::SimComponent::~SimCompo

// File Line: 426
// RVA: 0x23A450
UFG::SceneObjectProperties *__fastcall UFG::SceneObjectProperties::Create(UFG::qSymbol *objName, UFG::SceneLayer *pOwnerLayer, UFG::qPropertySet *parentSet)
{
  UFG::qPropertySet *v3; // rsi
  UFG::qSymbol *v4; // rbp
  UFG::SceneObjectProperties *v5; // rbx
  UFG::SceneLayerResource *v6; // rdi
  UFG::qMemoryPool *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SceneObjectProperties *v9; // rax
  UFG::qPropertySet *v10; // rcx
  UFG::qPropertySet *v11; // rax
  UFG::SceneLayerResource *v12; // rdx
  UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *v13; // rdx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v14; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v15; // rax

  v3 = parentSet;
  v4 = objName;
  v5 = 0i64;
  v6 = 0i64;
  if ( pOwnerLayer && (UFG::qBox *)&pOwnerLayer->mLayerResources.mNode.mNext[-6].mNext != &pOwnerLayer[-1].mBox )
    v6 = (UFG::SceneLayerResource *)&pOwnerLayer->mLayerResources.mNode.mNext[-6].mNext;
  v7 = UFG::GetSimulationMemoryPool();
  v8 = UFG::qMemoryPool::Allocate(v7, 0xA8ui64, "SceneObjectProperties", 0i64, 1u);
  if ( v8 )
  {
    UFG::SceneObjectProperties::SceneObjectProperties((UFG::SceneObjectProperties *)v8, v4, v6, 0i64, 0i64, 0);
    v5 = v9;
  }
  v10 = v5->mpWritableProperties;
  if ( !v10 )
  {
    v11 = UFG::qPropertySet::CreateContainedSet(
            (UFG::qSymbol *)&UFG::gLocalPropertySet.mUID,
            "WritableSceneObjProperties");
    v5->mpWritableProperties = v11;
    UFG::qPropertySet::AddRef(v11);
    UFG::PSWrapper::AppendParentLocal(v5->mpWritableProperties, v5->mpConstProperties);
    v10 = v5->mpWritableProperties;
  }
  UFG::PSWrapper::AppendParentLocal(v10, v3);
  v12 = v5->mpLayerResource;
  if ( v12 )
  {
    v13 = &v12->mObjects;
    v14 = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v5->mPrev;
    v15 = v13->mNode.mPrev;
    v15->mNext = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v5->mPrev;
    v14->mPrev = v15;
    v14->mNext = &v13->mNode;
    v13->mNode.mPrev = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v5->mPrev;
  }
  UFG::SceneObjectProperties::InstantiateChildObjects(v5, 0);
  return v5;
}

// File Line: 450
// RVA: 0x23A580
UFG::SceneObjectProperties *__fastcall UFG::SceneObjectProperties::Create(unsigned int prevNameUID, UFG::qPropertySet *parentSet, unsigned int child_index)
{
  unsigned int v3; // er14
  UFG::qPropertySet *v4; // rbp
  unsigned int v5; // esi
  unsigned __int64 v6; // rdx
  UFG::qMemoryPool *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SceneObjectProperties *v9; // rbx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v10; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // rax
  qSetLogical<UFG::SceneObjectProperties,UFG::qSymbol> *v12; // rax
  UFG::qPropertySet *v13; // rax
  UFG::qPropertySet *v14; // rcx
  UFG::qPropertySet *v15; // rax
  UFG::SceneLayerResource *v16; // r8
  UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *v17; // r8
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v18; // rdx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v19; // rcx
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+8h]
  UFG::allocator::free_link *v22; // [rsp+78h] [rbp+10h]
  qSetLogical<UFG::SceneObjectProperties,UFG::qSymbol> *v23; // [rsp+88h] [rbp+20h]

  v3 = child_index;
  v4 = parentSet;
  v5 = prevNameUID;
  v6 = ~(prevNameUID | ((unsigned __int64)parentSet->mName.mUID << 32))
     + ((prevNameUID | ((unsigned __int64)parentSet->mName.mUID << 32)) << 18);
  UFG::qSymbol::qSymbol(
    &result,
    65 * (21 * (v6 ^ (v6 >> 31)) ^ (21 * (v6 ^ (v6 >> 31)) >> 11)) ^ (65
                                                                    * (21 * (v6 ^ (v6 >> 31)) ^ (21 * (v6 ^ (v6 >> 31)) >> 11)) >> 22));
  v7 = UFG::GetSimulationMemoryPool();
  v8 = UFG::qMemoryPool::Allocate(v7, 0xA8ui64, "SceneObjectProperties", 0i64, 1u);
  v9 = (UFG::SceneObjectProperties *)v8;
  v22 = v8;
  if ( v8 )
  {
    UFG::SimComponent::SimComponent((UFG::SimComponent *)v8, result.mUID);
    v10 = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v9->mPrev;
    v10->mPrev = v10;
    v10->mNext = v10;
    v9->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SceneObjectProperties::`vftable;
    v11 = &v9->mpOwner;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v9->mpOwner.m_pPointer = 0i64;
    v9->mpLayerResource = 0i64;
    v9->mpParent = 0i64;
    v12 = &v9->mChildren;
    v23 = v12;
    *(_QWORD *)&v12->mCount = 0i64;
    v12->mppArray = 0i64;
    v9->mDeleteChildSimObjectOnDestruct = 1;
    v9->mLastTeleportFrame = 0;
    v9->mPrevNameHash = 0;
    v9->mChildIndex = -1;
    UFG::SimComponent::AddType(
      (UFG::SimComponent *)&v9->vfptr,
      UFG::SceneObjectProperties::_SceneObjectPropertiesTypeUID,
      "SceneObjectProperties");
    v13 = UFG::qPropertySet::CreateContainedSet((UFG::qSymbol *)&result, "SceneObject_PropertySet");
    v9->mpWritableProperties = v13;
    v9->mpConstProperties = 0i64;
    UFG::qPropertySet::AddRef(v13);
    UFG::SceneObjectProperties::SetParent(v9, 0i64);
    if ( v9->mpParent )
      v9->m_Flags &= 0xFFF7u;
    else
      v9->m_Flags |= 8u;
  }
  else
  {
    v9 = 0i64;
  }
  v14 = v9->mpWritableProperties;
  if ( !v14 )
  {
    v15 = UFG::qPropertySet::CreateContainedSet(
            (UFG::qSymbol *)&UFG::gLocalPropertySet.mUID,
            "WritableSceneObjProperties");
    v9->mpWritableProperties = v15;
    UFG::qPropertySet::AddRef(v15);
    UFG::PSWrapper::AppendParentLocal(v9->mpWritableProperties, v9->mpConstProperties);
    v14 = v9->mpWritableProperties;
  }
  UFG::PSWrapper::AppendParentLocal(v14, v4);
  v9->mPrevNameHash = v5;
  v9->mChildIndex = v3;
  v16 = v9->mpLayerResource;
  if ( v16 )
  {
    v17 = &v16->mObjects;
    v18 = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v9->mPrev;
    v19 = v17->mNode.mPrev;
    v19->mNext = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v9->mPrev;
    v18->mPrev = v19;
    v18->mNext = &v17->mNode;
    v17->mNode.mPrev = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v9->mPrev;
  }
  UFG::SceneObjectProperties::InstantiateChildObjects(v9, v5);
  return v9;
}

// File Line: 487
// RVA: 0x23A420
UFG::SceneObjectProperties *__fastcall UFG::SceneObjectProperties::Create(UFG::qSymbol *objName, UFG::SceneLayer *pOwnerLayer, UFG::qSymbol *parentSetName)
{
  UFG::qSymbol *v3; // rdi
  UFG::SceneLayer *v4; // rbx
  UFG::qPropertySet *v5; // rax

  v3 = objName;
  v4 = pOwnerLayer;
  v5 = UFG::PropertySetManager::GetPropertySet(parentSetName);
  return UFG::SceneObjectProperties::Create(v3, v4, v5);
}

// File Line: 503
// RVA: 0x239AA0
UFG::SimObject *__fastcall UFG::SceneObjectProperties::Activate(UFG::SceneObjectProperties *this, unsigned int instantiateFlags, UFG::qMatrix44 *pXFormOverride, UFG::TransformNodeComponent *parentTransform)
{
  UFG::TransformNodeComponent *v4; // rsi
  UFG::qMatrix44 *v5; // rbp
  unsigned int v6; // edi
  UFG::SceneObjectProperties *v7; // rbx
  UFG::qPropertySet *v8; // rax
  UFG::qPropertySet *v9; // rdi
  UFG::qSymbol *v10; // rax
  UFG::SimObject *v11; // rax
  UFG::qSymbol *v12; // rax
  UFG::SimObject *v13; // rdi
  UFG::qWiseSymbol result; // [rsp+20h] [rbp-18h]
  UFG::qWiseSymbol v16; // [rsp+24h] [rbp-14h]
  UFG::qSymbol v17; // [rsp+40h] [rbp+8h]

  v4 = parentTransform;
  v5 = pXFormOverride;
  v6 = instantiateFlags;
  v7 = this;
  if ( this->m_pSimObject )
    return 0i64;
  if ( !instantiateFlags )
    return 0i64;
  v8 = PropertyUtils::Get<unsigned long>(this, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID);
  if ( !v8 || (v6 & v8->mFlags) == 0 )
    return 0i64;
  v17.mUID = UFG::gNullQSymbol.mUID;
  if ( UFG::SceneObjectProperties::mspSimObjectFactoryFunc )
  {
    v9 = v7->mpWritableProperties;
    if ( !v9 )
      v9 = v7->mpConstProperties;
    v10 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v7->m_NameUID);
    v11 = UFG::SceneObjectProperties::mspSimObjectFactoryFunc(v9, v10, &v17);
  }
  else
  {
    v12 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v16, v7->m_NameUID);
    v11 = UFG::Simulation::CreateSimObject(&UFG::gSim, v12);
  }
  v13 = v11;
  v11->m_pSceneObj = v7;
  ((void (__fastcall *)(UFG::SimObject *, UFG::SceneObjectProperties *, signed __int64))v11->vfptr[1].__vecDelDtor)(
    v11,
    v7,
    0xFFFFFFFFi64);
  UFG::SimObject::StartDeferringAttachment(v13);
  UFG::SceneObjectProperties::mspActivateFunc(v7, v5, &v17, v4);
  UFG::SimObject::EndDeferringAttachment(v13);
  UFG::SceneObjectProperties::ActivateChildObjects(v7);
  return v13;
}

// File Line: 548
// RVA: 0x239BC0
__int64 __fastcall UFG::SceneObjectProperties::ActivateChildObjects(UFG::SceneObjectProperties *this)
{
  UFG::SceneObjectProperties **v1; // rbx
  unsigned int v2; // edi
  unsigned __int64 i; // rsi

  v1 = this->mChildren.mppArray;
  v2 = 0;
  for ( i = (unsigned __int64)&v1[this->mChildren.mCount]; (unsigned __int64)v1 < i; ++v1 )
  {
    if ( UFG::SceneObjectProperties::Activate(*v1, 1u, 0i64, 0i64) )
      ++v2;
  }
  return v2;
}

// File Line: 574
// RVA: 0x23EA50
__int64 __fastcall UFG::SceneObjectProperties::InstantiateChildObjects(UFG::SceneObjectProperties *this, unsigned int prevNameUID)
{
  unsigned int v2; // ebx
  UFG::SceneObjectProperties *v3; // rdi
  unsigned int v4; // esi
  UFG::qPropertySet *v5; // rcx
  __int64 *v6; // rax
  __int64 v7; // rcx
  UFG::qPropertyList *v8; // r9
  unsigned int v9; // ecx
  UFG::qPropertySet *v10; // rax
  char *v11; // rax
  UFG::qPropertySet *v12; // rsi
  char *v13; // rbx
  UFG::qResourceData *v14; // rax
  unsigned int v15; // eax
  unsigned __int64 v16; // rax
  char *v17; // rbx
  UFG::qSymbol *v18; // rax
  UFG::qMemoryPool *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::SceneObjectProperties *v21; // rax
  UFG::SceneObjectProperties *v22; // rbx
  unsigned int v23; // eax
  int v24; // esi
  UFG::SceneLayerResource *v25; // rcx
  unsigned int v27; // [rsp+30h] [rbp-D0h]
  unsigned int v28; // [rsp+34h] [rbp-CCh]
  UFG::qPropertySet *owningSet; // [rsp+38h] [rbp-C8h]
  UFG::qSymbol v30; // [rsp+40h] [rbp-C0h]
  UFG::qPropertyList *v31; // [rsp+48h] [rbp-B8h]
  UFG::qWiseSymbol v32; // [rsp+50h] [rbp-B0h]
  UFG::qWiseSymbol v33; // [rsp+54h] [rbp-ACh]
  UFG::qSymbol result; // [rsp+58h] [rbp-A8h]
  __int64 v35; // [rsp+60h] [rbp-A0h]
  UFG::allocator::free_link *v36; // [rsp+68h] [rbp-98h]
  char dest[2]; // [rsp+70h] [rbp-90h]
  char Dst; // [rsp+72h] [rbp-8Eh]
  bool v39; // [rsp+4A0h] [rbp+3A0h]
  unsigned int prevNameUIDa; // [rsp+4A8h] [rbp+3A8h]
  UFG::qSymbol name; // [rsp+4B0h] [rbp+3B0h]
  unsigned int v42; // [rsp+4B8h] [rbp+3B8h]

  prevNameUIDa = prevNameUID;
  v35 = -2i64;
  v2 = prevNameUID;
  v3 = this;
  v4 = 0;
  owningSet = 0i64;
  v5 = this->mpWritableProperties;
  if ( !v5 )
    v5 = v3->mpConstProperties;
  v6 = (__int64 *)UFG::qPropertySet::GetValuePtr(v5, 0x19u, SimSym_SimObjChildren.mUID, DEPTH_RECURSE, &owningSet);
  if ( !v6 )
    return 0i64;
  v7 = *v6;
  if ( !*v6 )
    return 0i64;
  v8 = (UFG::qPropertyList *)((char *)v6 + v7);
  v31 = (UFG::qPropertyList *)((char *)v6 + v7);
  if ( !(__int64 *)((char *)v6 + v7) )
    return 0i64;
  v9 = v8->mNumElements;
  v28 = v9;
  if ( !v9 )
    return 0i64;
  v27 = 0;
  v10 = v3->mpConstProperties;
  if ( !v10 )
    v10 = v3->mpWritableProperties;
  v39 = v10 == owningSet;
  v42 = 0;
  if ( v9 )
  {
    v27 = v9;
    do
    {
      v11 = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v4);
      if ( v11 && *(_QWORD *)v11 )
        v12 = (UFG::qPropertySet *)&v11[*(_QWORD *)v11];
      else
        v12 = 0i64;
      name.mUID = -1;
      if ( v2 )
      {
        name.mUID = v12->mName.mUID;
        v13 = UFG::qPropertySet::Get<char const *>(v12, (UFG::qSymbol *)&SimSym_NameRoot.mUID, DEPTH_RECURSE);
        if ( v13 )
        {
          strcpy(dest, ":");
          memset(&Dst, 0, 0x3FEui64);
          UFG::qStringCopy(&dest[1], 0x7FFFFFFF, v13, -1);
          v14 = (UFG::qResourceData *)v3->mpConstProperties;
          if ( !v14 )
          {
            if ( v3->mpParent )
              v14 = (UFG::qResourceData *)v3->mpWritableProperties;
            else
              v14 = UFG::qPropertySet::GetParentFromIdx(v3->mpWritableProperties, 0);
          }
          v15 = UFG::qSymbol::create_suffix(&result, (UFG::qSymbol *)&v14->mDebugName[12], dest)->mUID;
          name.mUID = v15;
        }
        else
        {
          v15 = name.mUID;
        }
        v16 = 21
            * ((((prevNameUIDa | ((unsigned __int64)v15 << 32)) << 18) + ~(prevNameUIDa | ((unsigned __int64)v15 << 32))) ^ ((((prevNameUIDa | ((unsigned __int64)v15 << 32)) << 18) + ~(prevNameUIDa | ((unsigned __int64)v15 << 32))) >> 31));
        name.mUID = UFG::qSymbol::qSymbol(&v33, 65 * (v16 ^ (v16 >> 11)) ^ (65 * (v16 ^ (v16 >> 11)) >> 22))->mUID;
      }
      else if ( v39 )
      {
        name.mUID = v12->mName.mUID;
      }
      else
      {
        v17 = UFG::qPropertySet::Get<char const *>(v12, (UFG::qSymbol *)&SimSym_NameRoot.mUID, DEPTH_RECURSE);
        strcpy(dest, ":");
        memset(&Dst, 0, 0x3FEui64);
        UFG::qStringCopy(&dest[1], 0x7FFFFFFF, v17, -1);
        v18 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v32, v3->m_NameUID);
        name.mUID = UFG::qSymbol::create_suffix(&v30, v18, dest)->mUID;
      }
      v19 = UFG::GetSimulationMemoryPool();
      v20 = UFG::qMemoryPool::Allocate(v19, 0xA8ui64, "SceneObjectProperties", 0i64, 1u);
      v36 = v20;
      if ( v20 )
      {
        UFG::SceneObjectProperties::SceneObjectProperties(
          (UFG::SceneObjectProperties *)v20,
          &name,
          v3->mpLayerResource,
          v12,
          v3,
          1);
        v22 = v21;
      }
      else
      {
        v22 = 0i64;
      }
      v23 = prevNameUIDa;
      v22->mPrevNameHash = prevNameUIDa;
      v24 = v42;
      v22->mChildIndex = v42;
      v25 = v22->mpLayerResource;
      if ( v25 )
      {
        UFG::SceneLayerResource::AddSOP(v25, v22);
        v23 = prevNameUIDa;
      }
      UFG::SceneObjectProperties::InstantiateChildObjects(v22, v23);
      v4 = v24 + 1;
      v42 = v4;
      v2 = prevNameUIDa;
      v8 = v31;
    }
    while ( v4 < v28 );
  }
  if ( v3->m_pSimObject )
    UFG::SceneObjectProperties::ActivateChildObjects(v3);
  return v27;
}

// File Line: 683
// RVA: 0x2464C0
void __fastcall UFG::SceneObjectProperties::UninstantiateChildObjects(UFG::SceneObjectProperties *this)
{
  unsigned int v1; // er8
  UFG::SceneObjectProperties *v2; // rdi
  UFG::SceneObjectProperties **v3; // rcx
  int v4; // er8
  UFG::SceneObjectProperties *v5; // rbx
  unsigned int v6; // er8
  UFG::SceneObjectProperties **v7; // rcx
  int v8; // er8

  v1 = this->mChildren.mCount;
  v2 = this;
  if ( v1 )
  {
    v3 = this->mChildren.mppArray;
    v4 = v1 - 1;
    v5 = *v3;
    v2->mChildren.mCount = v4;
    UFG::qMemMove(v3, v3 + 1, 8 * v4);
    while ( v5 )
    {
      v5->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v5->vfptr, 1u);
      v6 = v2->mChildren.mCount;
      if ( !v6 )
        break;
      v7 = v2->mChildren.mppArray;
      v8 = v6 - 1;
      v5 = *v7;
      v2->mChildren.mCount = v8;
      UFG::qMemMove(v7, v7 + 1, 8 * v8);
    }
  }
}

// File Line: 697
// RVA: 0x23ACC0
void __fastcall UFG::SceneObjectProperties::Deactivate(UFG::SceneObjectProperties *this)
{
  UFG::SceneObjectProperties::Deactivate(this, 3u);
}

// File Line: 702
// RVA: 0x23AE00
void __fastcall UFG::SceneObjectProperties::DeactivateDeferred(UFG::SceneObjectProperties *this)
{
  UFG::SceneObjectProperties::Deactivate(this, 4u);
}

// File Line: 712
// RVA: 0x23AB70
void __fastcall UFG::SceneObjectProperties::Deactivate(UFG::SceneObjectProperties *this, unsigned int createObjectFlags)
{
  UFG::SimObject *v2; // rbp
  char v3; // si
  UFG::SceneObjectProperties *v4; // rdi
  char v5; // bl
  UFG::qPropertySet *v6; // rax
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *v8; // rax
  UFG::SceneObjectProperties *v9; // rax
  __int64 v10; // rax
  UFG::SceneObjectProperties **v11; // rbx
  unsigned __int64 j; // rsi
  __int64 v13; // rax
  UFG::SceneObjectProperties **v14; // rbx
  unsigned __int64 i; // rsi

  v2 = this->m_pSimObject;
  v3 = createObjectFlags;
  v4 = this;
  if ( !v2 )
    return;
  v5 = 0;
  if ( (v2->m_Flags & 0x8000u) == 0 )
  {
    v6 = PropertyUtils::Get<unsigned long>(this, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID);
    if ( v6 && (v6->mFlags >> 2) & 1 )
    {
      v7 = PropertyUtils::Get<unsigned long>(v4, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID);
      if ( !v7 || !((v7->mFlags >> 2) & 1) || !(v3 & 4) )
        goto LABEL_9;
    }
    else if ( !(v3 & 4) )
    {
      v13 = v4->mChildren.mCount;
      if ( (_DWORD)v13 )
      {
        v14 = v4->mChildren.mppArray;
        for ( i = (unsigned __int64)&v14[v13]; (unsigned __int64)v14 < i; ++v14 )
          UFG::SceneObjectProperties::Deactivate(*v14, 3u);
      }
      goto LABEL_22;
    }
    v10 = v4->mChildren.mCount;
    if ( (_DWORD)v10 )
    {
      v11 = v4->mChildren.mppArray;
      for ( j = (unsigned __int64)&v11[v10]; (unsigned __int64)v11 < j; ++v11 )
        UFG::SceneObjectProperties::Deactivate(*v11, 4u);
    }
LABEL_22:
    UFG::SceneObjectProperties::mspDeactivateFunc(v4);
    UFG::SimObject::Destroy(v2);
    return;
  }
  v5 = 1;
LABEL_9:
  v8 = PropertyUtils::Get<unsigned long>(v4, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID);
  if ( v8 && (v8->mFlags >> 2) & 1 || v5 )
  {
    UFG::SceneObjectProperties::OnOrphaned(v4);
    v9 = v4->mpParent;
    if ( v9 )
      v9->mDeleteChildSimObjectOnDestruct = 0;
  }
}

// File Line: 775
// RVA: 0x243330
void __fastcall UFG::SceneObjectProperties::OnOrphaned(UFG::SceneObjectProperties *this)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::SimObject *v2; // rcx
  UFG::TransformNodeComponent *v3; // rcx

  this->m_Flags |= 8u;
  v1 = this;
  if ( this->mpParent )
  {
    v2 = this->m_pSimObject;
    if ( v2 )
    {
      v3 = v2->m_pTransformNodeComponent;
      if ( v3 )
      {
        if ( v3->mParent )
          UFG::TransformNodeComponent::SetParentKeepWorld(v3, 0i64, 0);
      }
    }
    v1->mpLayerResource = 0i64;
  }
  else
  {
    this->mpLayerResource = 0i64;
  }
}

// File Line: 801
// RVA: 0x243810
void __fastcall UFG::SceneObjectProperties::OnTeleportEvent(UFG::SceneObjectProperties *this, UFG::Event *event_p)
{
  this->mLastTeleportFrame = UFG::Metrics::msInstance.mSimFrameCount;
}

// File Line: 813
// RVA: 0x23BFB0
UFG::SceneObjectProperties *__fastcall UFG::SceneObjectProperties::GetAncestor(UFG::SceneObjectProperties *this, unsigned int ancestorLevel)
{
  UFG::SceneObjectProperties *result; // rax

  if ( !ancestorLevel )
    return 0i64;
  result = this->mpParent;
  if ( !result )
    return 0i64;
  while ( ancestorLevel != 1 )
  {
    result = result->mpParent;
    --ancestorLevel;
    if ( !result )
      return 0i64;
  }
  return result;
}

// File Line: 835
// RVA: 0x23D3A0
UFG::SceneObjectProperties *__fastcall UFG::SceneObjectProperties::GetChildAsSceneObject(UFG::SceneObjectProperties *this, unsigned int index)
{
  UFG::SceneObjectProperties *result; // rax

  if ( index >= this->mChildren.mCount )
    result = 0i64;
  else
    result = this->mChildren.mppArray[index];
  return result;
}

// File Line: 847
// RVA: 0x23D3C0
UFG::SimObject *__fastcall UFG::SceneObjectProperties::GetChildAsSimObject(UFG::SceneObjectProperties *this, unsigned int index)
{
  UFG::SimObject *result; // rax

  if ( index >= this->mChildren.mCount )
    result = 0i64;
  else
    result = this->mChildren.mppArray[index]->m_pSimObject;
  return result;
}

// File Line: 859
// RVA: 0x245540
void __fastcall UFG::SceneObjectProperties::SetParent(UFG::SceneObjectProperties *this, UFG::SceneObjectProperties *pParent)
{
  UFG::SceneObjectProperties *v2; // rax
  UFG::SceneObjectProperties *v3; // rbp
  UFG::SceneObjectProperties *v4; // rsi
  UFG::SceneObjectProperties *v5; // r14
  unsigned int v6; // edi
  unsigned int v7; // eax
  UFG::SceneObjectProperties **v8; // rbx
  unsigned __int64 i; // r15
  UFG::SceneObjectProperties **v10; // rcx
  UFG::qSymbol v11; // [rsp+50h] [rbp+8h]
  UFG::qSymbol result; // [rsp+58h] [rbp+10h]

  v2 = this->mpParent;
  v3 = pParent;
  v4 = this;
  if ( v2 != pParent )
  {
    if ( v2 )
    {
      UFG::SceneObjectProperties::operator UFG::qSymbol const(this, &result);
      v5 = v4->mpParent;
      v6 = 0;
      v7 = v5->mChildren.mCount;
      if ( v7 )
      {
        v8 = v5->mChildren.mppArray;
        for ( i = (unsigned __int64)&v8[v7 - 1]; (unsigned __int64)v8 <= i; ++v8 )
        {
          UFG::SceneObjectProperties::operator UFG::qSymbol const(*v8, &v11);
          if ( result.mUID == v11.mUID )
          {
            if ( v6 < 2 )
            {
              v10 = v5->mChildren.mppArray;
              UFG::qMemMove(
                &v10[(unsigned int)(v8 - v10)],
                &v10[(unsigned int)(v8 - v10) + 1],
                8 * (--v5->mChildren.mCount - (unsigned __int64)(v8 - v10)));
              break;
            }
            --v6;
          }
        }
      }
    }
    v4->mpParent = v3;
    if ( v3 )
    {
      v4->m_Flags &= 0xFFF7u;
      qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
        (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)&v3->mChildren.mCount,
        v4,
        "SceneObjectProperties::mChildren");
    }
    else
    {
      v4->m_Flags |= 8u;
    }
  }
}

// File Line: 884
// RVA: 0x23BD00
UFG::SceneLayer *__fastcall UFG::SceneObjectProperties::FindOwnerLayer(UFG::SceneObjectProperties *this)
{
  UFG::SimObject *v1; // rcx

  if ( this->mpLayerResource )
    return (UFG::SceneLayer *)this->mpLayerResource->mpRuntimeSceneLayer;
  while ( 1 )
  {
    v1 = this->mpOwner.m_pPointer;
    if ( !v1 )
      break;
    this = v1->m_pSceneObj;
    if ( !this )
      break;
    if ( this->mpLayerResource )
      return (UFG::SceneLayer *)this->mpLayerResource->mpRuntimeSceneLayer;
  }
  return 0i64;
}

