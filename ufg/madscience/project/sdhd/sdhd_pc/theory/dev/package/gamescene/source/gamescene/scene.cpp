// File Line: 72
// RVA: 0x1470E70
__int64 anonymous_namespace_::_dynamic_initializer_for__SceneLayer_type_id__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SceneLayer1", 0xFFFFFFFF);
  `anonymous namespace::SceneLayer_type_id = result;
  return result;
}

// File Line: 73
// RVA: 0x1470E90
__int64 anonymous_namespace_::_dynamic_initializer_for__Scene_type_id__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Scene1", 0xFFFFFFFF);
  `anonymous namespace::Scene_type_id = result;
  return result;
}

// File Line: 144
// RVA: 0x237840
void __fastcall UFG::SceneLayer::SceneLayer(UFG::SceneLayer *this, UFG::qSymbol *name)
{
  unsigned int mUID; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  mUID = name->mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = mUID;
  this->mPrev = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
  this->mNext = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
  *(_QWORD *)&this->mFlags = 0i64;
  this->mLayerResources.mNode.mPrev = &this->mLayerResources.mNode;
  this->mLayerResources.mNode.mNext = &this->mLayerResources.mNode;
  *(_QWORD *)&this->mBox.mMin.x = 0i64;
  *(_QWORD *)&this->mBox.mMin.z = 0i64;
  *(_QWORD *)&this->mBox.mMax.y = 0i64;
  this->mDeactivateTimer = 0.0;
  this->mIndoorCategory.mUID = -1;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mBox.mMin.x = UFG::qVector3::msZero.x;
  this->mBox.mMin.y = y;
  this->mBox.mMin.z = z;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  this->mBox.mMax.x = UFG::qVector3::msZero.x;
  this->mBox.mMax.y = v5;
  this->mBox.mMax.z = v6;
  this->mGameProgressionBehaviour = UFG::ILayerActivationBehaviour::Create(this);
}

// File Line: 156
// RVA: 0x2383B0
void __fastcall UFG::SceneLayer::~SceneLayer(UFG::SceneLayer *this)
{
  UFG::qList<UFG::SceneLayerResource,UFG::SceneLayerResource,1,0> *p_mLayerResources; // rbx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **i; // rax
  _QWORD *v4; // rdx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v5; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v6; // rax
  UFG::ILayerActivationBehaviour *mGameProgressionBehaviour; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *mPrev; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *mNext; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v10; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rax

  this->mFlags |= 0x200000u;
  UFG::SceneLayer::Empty(this);
  p_mLayerResources = &this->mLayerResources;
  for ( i = &this->mLayerResources.mNode.mNext[-6].mNext;
        i != (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **)&this[-1].mBox;
        i = &this->mLayerResources.mNode.mNext[-6].mNext )
  {
    v4 = i + 11;
    v5 = i[11];
    v6 = i[12];
    v5->mNext = v6;
    v6->mPrev = v5;
    *v4 = v4;
    v4[1] = v4;
  }
  mGameProgressionBehaviour = this->mGameProgressionBehaviour;
  if ( mGameProgressionBehaviour )
    mGameProgressionBehaviour->vfptr->__vecDelDtor(mGameProgressionBehaviour, 1u);
  UFG::qList<UFG::SceneLayerResource,UFG::SceneLayerResource,1,0>::DeleteNodes(&this->mLayerResources);
  mPrev = p_mLayerResources->mNode.mPrev;
  mNext = this->mLayerResources.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mLayerResources->mNode.mPrev = &p_mLayerResources->mNode;
  this->mLayerResources.mNode.mNext = &this->mLayerResources.mNode;
  v10 = this->mPrev;
  v11 = this->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mPrev = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
  this->mNext = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
}

// File Line: 179
// RVA: 0x23BAB0
UFG::qPropertySet *__fastcall UFG::SceneLayer::FindObjectPropertySet(UFG::SceneLayer *this, UFG::qSymbol *objectName)
{
  UFG::qBox *p_mBox; // r14
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **p_mNext; // rdi
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v5; // rax
  char *v6; // rsi
  __int64 v7; // rbx
  __int64 v8; // rax
  UFG::qPropertySet *v9; // rcx
  UFG::qPropertySet *result; // rax

  p_mBox = &this[-1].mBox;
  p_mNext = &this->mLayerResources.mNode.mNext[-6].mNext;
  if ( p_mNext == (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **)&this[-1].mBox )
    return 0i64;
  while ( 1 )
  {
    v5 = p_mNext[14];
    if ( v5 )
    {
      v6 = (char *)p_mNext + (_QWORD)v5 + 112;
      if ( v6 )
      {
        v7 = 0i64;
        if ( *((_DWORD *)p_mNext + 27) )
          break;
      }
    }
LABEL_10:
    p_mNext = &p_mNext[12][-6].mNext;
    if ( p_mNext == (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **)p_mBox )
      return 0i64;
  }
  while ( 1 )
  {
    v8 = *(_QWORD *)&v6[8 * v7];
    v9 = v8 ? (UFG::qPropertySet *)&v6[8 * v7 + v8] : 0i64;
    result = UFG::FindObjectPropertySetRecurse(v9, objectName);
    if ( result )
      return result;
    v7 = (unsigned int)(v7 + 1);
    if ( (unsigned int)v7 >= *((_DWORD *)p_mNext + 27) )
      goto LABEL_10;
  }
}

// File Line: 213
// RVA: 0x23E100
UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **__fastcall UFG::SceneLayer::GetSingleEditorSceneLayerResource(
        UFG::SceneLayer *this)
{
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **result; // rax

  result = 0i64;
  if ( (UFG::qBox *)&this->mLayerResources.mNode.mNext[-6].mNext != &this[-1].mBox )
    return &this->mLayerResources.mNode.mNext[-6].mNext;
  return result;
}

// File Line: 334
// RVA: 0x23B000
void __fastcall UFG::SceneLayer::Empty(UFG::SceneLayer *this)
{
  UFG::qBox *p_mBox; // rbx
  UFG::SceneLayerResource *p_mNext; // r14
  bool v3; // r13
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *mNext; // rdx
  __int64 v5; // r12
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *mPrev; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v7; // rax
  UFG::SceneObjectProperties *v8; // rbx
  UFG::SimObject *m_pSimObject; // rbp
  char v10; // di
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *v14; // rax
  unsigned int *v15; // rax
  UFG::qPropertySet *v16; // rcx
  UFG::SchemaDef *v17; // rax
  UFG::qPropertySet *v18; // rcx
  UFG::qPropertySet *v19; // rax
  UFG::qPropertySet *v20; // rcx
  UFG::SchemaDef *v21; // rax
  UFG::qPropertySet *v22; // rcx
  UFG::qPropertySet *v23; // rax
  unsigned int *v24; // rax
  UFG::SimObject *v25; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rcx
  UFG::SceneObjectProperties *mpParent; // rax
  __int64 mCount; // rax
  UFG::SceneObjectProperties **mppArray; // rdi
  UFG::SceneObjectProperties **i; // rsi
  UFG::qBox *v31; // [rsp+68h] [rbp+10h]

  p_mBox = &this[-1].mBox;
  p_mNext = (UFG::SceneLayerResource *)&this->mLayerResources.mNode.mNext[-6].mNext;
  v31 = &this[-1].mBox;
  v3 = (this->mFlags & 2) != 0;
  if ( p_mNext == (UFG::SceneLayerResource *)&this[-1].mBox )
    return;
  do
  {
    mNext = p_mNext->mObjects.mNode.mNext;
    v5 = (__int64)&p_mNext->mNext[-6].mNext;
    if ( &mNext[-4] == (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&p_mNext->mDebugName[28] )
      goto LABEL_53;
    do
    {
      mPrev = mNext->mPrev;
      v7 = mNext->mNext;
      v8 = (UFG::SceneObjectProperties *)&mNext[-4];
      mPrev->mNext = v7;
      v7->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      if ( !v3 )
        goto LABEL_51;
      m_pSimObject = v8->m_pSimObject;
      if ( !m_pSimObject )
        goto LABEL_51;
      v10 = 0;
      if ( (m_pSimObject->m_Flags & 0x8000u) != 0 )
      {
        v10 = 1;
        goto LABEL_28;
      }
      mpWritableProperties = v8->mpWritableProperties;
      if ( !mpWritableProperties )
        mpWritableProperties = v8->mpConstProperties;
      SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(
                            mpWritableProperties,
                            (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags);
      if ( SchemaForProperty )
      {
        mpConstProperties = v8->mpWritableProperties;
        if ( !mpConstProperties )
          mpConstProperties = v8->mpConstProperties;
        v14 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                mpConstProperties,
                (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
                DEPTH_RECURSE);
LABEL_15:
        if ( !v14 )
          goto LABEL_47;
        goto LABEL_16;
      }
      v14 = v8->mpWritableProperties;
      if ( !v14 )
      {
        v14 = v8->mpConstProperties;
        goto LABEL_15;
      }
LABEL_16:
      v15 = UFG::qPropertySet::Get<unsigned long>(
              v14,
              (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags,
              DEPTH_RECURSE);
      if ( v15 && (*v15 & 4) != 0 )
      {
        v16 = v8->mpWritableProperties;
        if ( !v16 )
          v16 = v8->mpConstProperties;
        v17 = UFG::PropertySetManager::GetSchemaForProperty(
                v16,
                (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags);
        if ( v17 )
        {
          v18 = v8->mpWritableProperties;
          if ( !v18 )
            v18 = v8->mpConstProperties;
          v19 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                  v18,
                  (UFG::qArray<unsigned long,0> *)&v17->mPropertyName,
                  DEPTH_RECURSE);
        }
        else
        {
          v19 = v8->mpWritableProperties;
          if ( v19 )
          {
LABEL_27:
            UFG::qPropertySet::Get<unsigned long>(
              v19,
              (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags,
              DEPTH_RECURSE);
LABEL_28:
            v20 = v8->mpWritableProperties;
            if ( !v20 )
              v20 = v8->mpConstProperties;
            v21 = UFG::PropertySetManager::GetSchemaForProperty(
                    v20,
                    (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags);
            if ( v21 )
            {
              v22 = v8->mpWritableProperties;
              if ( !v22 )
                v22 = v8->mpConstProperties;
              v23 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                      v22,
                      (UFG::qArray<unsigned long,0> *)&v21->mPropertyName,
                      DEPTH_RECURSE);
            }
            else
            {
              v23 = v8->mpWritableProperties;
              if ( v23 )
              {
LABEL_37:
                v24 = UFG::qPropertySet::Get<unsigned long>(
                        v23,
                        (UFG::qArray<unsigned long,0> *)&SimSym_CreateObjectFlags,
                        DEPTH_RECURSE);
                if ( v24 && (*v24 & 4) != 0 )
                {
LABEL_40:
                  v8->m_Flags |= 8u;
                  if ( v8->mpParent )
                  {
                    v25 = v8->m_pSimObject;
                    if ( v25 )
                    {
                      m_pTransformNodeComponent = v25->m_pTransformNodeComponent;
                      if ( m_pTransformNodeComponent )
                      {
                        if ( m_pTransformNodeComponent->mParent )
                          UFG::TransformNodeComponent::SetParentKeepWorld(
                            m_pTransformNodeComponent,
                            0i64,
                            eInheritXform_Full);
                      }
                    }
                  }
                  mpParent = v8->mpParent;
                  v8->mpLayerResource = 0i64;
                  if ( mpParent )
                    mpParent->mDeleteChildSimObjectOnDestruct = 0;
                  goto LABEL_51;
                }
LABEL_39:
                if ( !v10 )
                  goto LABEL_51;
                goto LABEL_40;
              }
              v23 = v8->mpConstProperties;
            }
            if ( !v23 )
              goto LABEL_39;
            goto LABEL_37;
          }
          v19 = v8->mpConstProperties;
        }
        if ( !v19 )
          goto LABEL_28;
        goto LABEL_27;
      }
LABEL_47:
      mCount = v8->mChildren.mCount;
      if ( (_DWORD)mCount )
      {
        mppArray = v8->mChildren.mppArray;
        for ( i = &mppArray[mCount]; mppArray < i; ++mppArray )
          UFG::SceneObjectProperties::Deactivate(*mppArray);
      }
      UFG::SceneObjectProperties::mspDeactivateFunc(v8);
      UFG::SimObject::Destroy(m_pSimObject);
LABEL_51:
      mNext = p_mNext->mObjects.mNode.mNext;
    }
    while ( &mNext[-4] != (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&p_mNext->mDebugName[28] );
    p_mBox = v31;
LABEL_53:
    if ( (p_mNext->mFlags & 1) == 0 )
    {
      if ( (p_mNext->mFlags & 2) != 0 )
      {
        UFG::qResourceInventory::Remove(&UFG::gSceneLayerInventory, p_mNext);
        p_mNext->mFlags &= ~2u;
        if ( UFG::gSceneLayerInventory.m_onSceneLayerResourceUnloadedCallback )
          UFG::gSceneLayerInventory.m_onSceneLayerResourceUnloadedCallback(p_mNext);
        if ( (p_mNext->mFlags & 1) != 0 )
          UFG::SceneLayerResource::~SceneLayerResource(p_mNext);
      }
      UFG::SceneLayerResource::~SceneLayerResource(p_mNext);
      UFG::qMemoryPool::Free(&gPropertySetMemoryPool, (char *)p_mNext);
    }
    p_mNext = (UFG::SceneLayerResource *)v5;
  }
  while ( (UFG::qBox *)v5 != p_mBox );
}UFG::SceneLayerResource::~SceneLayerResource(p_mNext);
      UFG::qMemoryPool::Free(&gPropertySetMemoryPool, (char *)p_mNext);
    }
    p_mNext = (UFG::SceneLayerResource *)v5;
  }

// File Line: 372
// RVA: 0x23B380
void __fastcall UFG::SceneLayer::EnableActivate(
        UFG::SceneLayer *this,
        bool activate,
        UFG::SceneLayer::PERISTENCE peristence,
        bool forceSynchronous)
{
  unsigned int mFlags; // ecx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mPrev; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mNext; // rax
  bool v11; // zf
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v12; // rbx
  UFG::qBox *p_mBox; // rsi
  UFG::SceneLayerResource *j; // rbx
  UFG::SceneLayerResource *i; // rbx
  UFG::GeographicalLayerManager *Instance; // rdx
  unsigned int v17; // eax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v18; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v19; // rax

  mFlags = this->mFlags;
  if ( activate != ((mFlags & 2) != 0) )
  {
    if ( (mFlags & 0x4000) != 0 )
    {
      UFG::GeographicalLayerManager::GetInstance();
      if ( (this->mFlags & 0x8000) != 0 )
      {
        mPrev = this->mPrev;
        mNext = this->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        this->mNext = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
        this->mPrev = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
        this->mFlags &= ~0x8000u;
      }
    }
    v11 = !activate;
    v12 = this->mLayerResources.mNode.mNext;
    p_mBox = &this[-1].mBox;
    if ( v11 )
    {
      this->mFlags &= ~2u;
      for ( i = (UFG::SceneLayerResource *)&v12[-6].mNext;
            i != (UFG::SceneLayerResource *)p_mBox;
            i = (UFG::SceneLayerResource *)&i->mNext[-6].mNext )
      {
        if ( (i->mFlags & 8) != 0 )
        {
          UFG::IncrementalActivateManager::Deactivate(i, forceSynchronous);
          i->mFlags &= ~8u;
        }
      }
    }
    else
    {
      this->mFlags |= 2u;
      for ( j = (UFG::SceneLayerResource *)&v12[-6].mNext;
            j != (UFG::SceneLayerResource *)p_mBox;
            j = (UFG::SceneLayerResource *)&j->mNext[-6].mNext )
      {
        if ( (!UFG::SceneLayer::sbManageSubLayerActivation
           || peristence == PERSISTENT
           || (this->mFlags & 0x4000) == 0
           || (j->mFlags & 4) != 0
           || UFG::SceneLayerResource::IsGeoInFrustrum(j))
          && (j->mFlags & 8) == 0 )
        {
          UFG::IncrementalActivateManager::Activate(j, forceSynchronous);
          j->mFlags |= 8u;
        }
      }
    }
    if ( peristence == PERSISTENT )
      this->mFlags |= 0x10u;
    if ( (this->mFlags & 0x4000) != 0 )
    {
      Instance = UFG::GeographicalLayerManager::GetInstance();
      v17 = this->mFlags;
      if ( (v17 & 0x8000) == 0 )
      {
        v18 = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
        if ( (v17 & 0x80) != 0 )
        {
          if ( (v17 & 2) == 0 )
            Instance = (UFG::GeographicalLayerManager *)((char *)Instance + 16);
        }
        else
        {
          Instance = (UFG::GeographicalLayerManager *)((char *)Instance + 32);
        }
        v19 = Instance->mActiveLayers.mNode.mPrev;
        v19->mNext = v18;
        v18->mPrev = v19;
        this->mNext = &Instance->mActiveLayers.mNode;
        Instance->mActiveLayers.mNode.mPrev = v18;
        this->mFlags |= 0x8000u;
      }
    }
  }
}

// File Line: 472
// RVA: 0x23B810
void __fastcall UFG::SceneLayer::EnableGeographical(
        UFG::SceneLayer *this,
        bool geographical,
        UFG::SceneLayer::PERISTENCE peristence)
{
  unsigned int mFlags; // ecx
  UFG::GeographicalLayerManager *Instance; // rdx
  unsigned int v7; // eax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v8; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mPrev; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v10; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mNext; // rax

  mFlags = this->mFlags;
  if ( geographical != ((mFlags & 0x4000) != 0) )
  {
    if ( geographical )
    {
      this->mFlags = mFlags | 0x4000;
      Instance = UFG::GeographicalLayerManager::GetInstance();
      v7 = this->mFlags;
      if ( (v7 & 0x8000) == 0 )
      {
        v8 = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
        if ( (v7 & 0x80) != 0 )
        {
          if ( (v7 & 2) == 0 )
            Instance = (UFG::GeographicalLayerManager *)((char *)Instance + 16);
        }
        else
        {
          Instance = (UFG::GeographicalLayerManager *)((char *)Instance + 32);
        }
        mPrev = Instance->mActiveLayers.mNode.mPrev;
        mPrev->mNext = v8;
        v8->mPrev = mPrev;
        this->mNext = &Instance->mActiveLayers.mNode;
        Instance->mActiveLayers.mNode.mPrev = v8;
        this->mFlags |= 0x8000u;
      }
    }
    else
    {
      this->mFlags = mFlags & 0xFFFFBFFF;
      UFG::GeographicalLayerManager::GetInstance();
      if ( (this->mFlags & 0x8000) != 0 )
      {
        v10 = this->mPrev;
        mNext = this->mNext;
        v10->mNext = mNext;
        mNext->mPrev = v10;
        this->mNext = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
        this->mPrev = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
        this->mFlags &= ~0x8000u;
      }
    }
  }
  if ( peristence == PERSISTENT )
    this->mFlags |= 0x10u;
}

// File Line: 514
// RVA: 0x23BEF0
void __fastcall UFG::SceneLayer::GenerateUniqueNameForSkookum(
        UFG::SceneLayer *this,
        char *objRootName,
        UFG::qSymbol *pObjName)
{
  UFG::qSymbol *suffix; // rax
  unsigned int mUID; // eax
  UFG::qBox *p_mBox; // rbx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *mNext; // rdx
  __int64 p_mNext; // rdx
  __int64 v11; // rcx
  UFG::qSymbol name; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol v13; // [rsp+50h] [rbp+18h] BYREF
  UFG::qSymbol result; // [rsp+58h] [rbp+20h] BYREF

  suffix = (UFG::qSymbol *)UFG::qSymbol::create_suffix(
                             (UFG::qWiseSymbol *)&result,
                             (UFG::qSymbol *)&this->mNode.mUID,
                             "-");
  UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&v13, suffix, objRootName);
  mUID = v13.mUID;
  p_mBox = &this[-1].mBox;
  while ( 1 )
  {
    mNext = this->mLayerResources.mNode.mNext;
    name.mUID = mUID;
    p_mNext = (__int64)&mNext[-6].mNext;
    if ( (UFG::qBox *)p_mNext == p_mBox )
      break;
    while ( 1 )
    {
      v11 = *(_QWORD *)(p_mNext + 152) - 64i64;
      if ( v11 != p_mNext + 80 )
        break;
LABEL_6:
      p_mNext = *(_QWORD *)(p_mNext + 96) - 88i64;
      if ( (UFG::qBox *)p_mNext == p_mBox )
        goto LABEL_7;
    }
    while ( *(_DWORD *)(v11 + 28) != mUID )
    {
      v11 = *(_QWORD *)(v11 + 72) - 64i64;
      if ( v11 == p_mNext + 80 )
        goto LABEL_6;
    }
    mUID = UFG::qSymbol::create_increment((UFG::qWiseSymbol *)&result, &name, 1)->mUID;
  }
LABEL_7:
  pObjName->mUID = mUID;
}

// File Line: 529
// RVA: 0x23DA50
UFG::qPropertySet *__fastcall UFG::SceneLayer::GetPropertySet(UFG::SceneLayer *this)
{
  UFG::SceneLayer *p_mNext; // rdx
  UFG::qBaseNodeRB *v2; // rax

  p_mNext = (UFG::SceneLayer *)&this->mLayerResources.mNode.mNext[-6].mNext;
  if ( p_mNext == (UFG::SceneLayer *)&this[-1].mBox )
    return 0i64;
  if ( this->mLayerResources.mNode.mNext == (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *)88 )
    return 0i64;
  v2 = p_mNext[1].mNode.mChild[0];
  if ( !v2 )
    return 0i64;
  else
    return (UFG::qPropertySet *)((char *)&v2[3].mChild[2] + (_QWORD)p_mNext);
}

// File Line: 582
// RVA: 0x23D800
UFG::qSymbol *__fastcall UFG::SceneLayer::GetIndoorCategory(UFG::SceneLayer *this, UFG::qSymbol *result)
{
  UFG::qSymbol *p_mIndoorCategory; // rax

  p_mIndoorCategory = &this->mIndoorCategory;
  if ( (this->mFlags & 0x200) == 0 )
    p_mIndoorCategory = &UFG::gNullQSymbol;
  result->mUID = p_mIndoorCategory->mUID;
  return result;
}

// File Line: 655
// RVA: 0x239EF0
void __fastcall UFG::SceneLayer::CachePropertySetData(UFG::SceneLayer *this)
{
  UFG::qBox *p_mBox; // rax
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **p_mNext; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v4; // rax
  UFG::qPropertySet *v5; // rdi
  unsigned int v6; // esi
  bool *v7; // rax
  bool *v8; // rax
  bool *v9; // rax
  UFG::qSymbol *v10; // rax
  UFG::qSymbol *v11; // rcx
  unsigned int mUID; // eax
  bool *v13; // rax
  bool *v14; // rax
  UFG::qVector3 *v15; // r14
  UFG::qVector3 *v16; // rax
  UFG::qVector3 *v17; // rsi
  float y; // xmm1_4
  float z; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float x; // eax
  unsigned int mFlags; // ecx
  UFG::qVector3 *v24; // rax
  float v25; // xmm6_4
  __m128 y_low; // xmm8
  float v27; // xmm7_4
  UFG::qVector3 *v28; // rax
  __m128 v29; // xmm2
  float v30; // xmm0_4
  char *v31; // rax
  UFG::ILayerActivationBehaviour *mGameProgressionBehaviour; // rcx

  p_mBox = &this[-1].mBox;
  p_mNext = &this->mLayerResources.mNode.mNext[-6].mNext;
  if ( p_mNext != (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **)p_mBox )
  {
    if ( p_mNext )
    {
      v4 = p_mNext[15];
      if ( v4 )
      {
        v5 = (UFG::qPropertySet *)((char *)p_mNext + (_QWORD)v4 + 120);
        if ( v5 )
        {
          if ( (this->mFlags & 0x1000) == 0 )
          {
            v6 = this->mFlags & 0x4890;
            v7 = UFG::qPropertySet::Get<bool>(
                   (UFG::qPropertySet *)((char *)p_mNext + (_QWORD)v4 + 120),
                   (UFG::qArray<unsigned long,0> *)&SimSym_InitialActivate,
                   DEPTH_RECURSE);
            if ( v7 && *v7 )
              this->mFlags |= 0x2000u;
            v8 = UFG::qPropertySet::Get<bool>(v5, (UFG::qArray<unsigned long,0> *)&SimSym_Geographical, DEPTH_RECURSE);
            if ( v8 && *v8 )
              this->mFlags |= 0x4000u;
            v9 = UFG::qPropertySet::Get<bool>(v5, (UFG::qArray<unsigned long,0> *)&SimSym_AutoActivate, DEPTH_RECURSE);
            if ( !v9 || *v9 )
              this->mFlags |= 0x80u;
            v10 = UFG::qPropertySet::Get<UFG::qSymbol>(
                    v5,
                    (UFG::qArray<unsigned long,0> *)&SimSym_LayerCategory,
                    DEPTH_RECURSE);
            v11 = &UFG::gNullQSymbol;
            if ( v10 )
              v11 = v10;
            mUID = v11->mUID;
            this->mIndoorCategory = (UFG::qSymbol)v11->mUID;
            if ( mUID == -1 )
            {
              this->mFlags |= 0x100u;
            }
            else
            {
              this->mFlags |= 0x200u;
              v13 = UFG::qPropertySet::Get<bool>(v5, (UFG::qArray<unsigned long,0> *)&SimSym_CategoryOut, DEPTH_RECURSE);
              if ( v13 && *v13 )
                this->mFlags |= 0x100u;
              v14 = UFG::qPropertySet::Get<bool>(
                      v5,
                      (UFG::qArray<unsigned long,0> *)&SimSym_CategoryAudio,
                      DEPTH_RECURSE);
              if ( v14 && *v14 )
                this->mFlags |= 0x400u;
            }
            this->mFlags |= 0x1000u;
            if ( (this->mFlags & 0x10) != 0 )
              this->mFlags = v6 | this->mFlags & 0xFFFFB76F;
            v15 = UFG::qPropertySet::Get<UFG::qVector3>(
                    v5,
                    (UFG::qArray<unsigned long,0> *)&SimSym_BoundsMin,
                    DEPTH_RECURSE);
            v16 = UFG::qPropertySet::Get<UFG::qVector3>(
                    v5,
                    (UFG::qArray<unsigned long,0> *)&SimSym_BoundsMax,
                    DEPTH_RECURSE);
            v17 = v16;
            if ( v15 )
            {
              if ( v16 )
              {
                y = v15->y;
                z = v15->z;
                this->mBox.mMin.x = v15->x;
                this->mBox.mMin.y = y;
                this->mBox.mMin.z = z;
                v20 = v16->y;
                v21 = v16->z;
                x = v16->x;
                this->mBox.mMax.y = v20;
                this->mBox.mMax.z = v21;
                this->mBox.mMax.x = x;
                mFlags = this->mFlags;
                if ( ((mFlags & 2) != 0 || (mFlags & 0x2000) != 0) && (mFlags & 0x100000) != 0 )
                {
                  UFG::SceneLayer::RefreshLayerBoundingBox(this);
                  v24 = UFG::qPropertySet::Get<UFG::qVector3>(
                          v5,
                          (UFG::qArray<unsigned long,0> *)&SimSym_BoundsMin,
                          DEPTH_RECURSE);
                  v25 = v24->x;
                  y_low = (__m128)LODWORD(v24->y);
                  v27 = v24->z;
                  v28 = UFG::qPropertySet::Get<UFG::qVector3>(
                          v5,
                          (UFG::qArray<unsigned long,0> *)&SimSym_BoundsMax,
                          DEPTH_RECURSE);
                  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v15->y)
                                                    * (float)(y_low.m128_f32[0] - v15->y))
                                            + (float)((float)(v25 - v15->x) * (float)(v25 - v15->x)))
                                    + (float)((float)(v27 - v15->z) * (float)(v27 - v15->z));
                  if ( _mm_sqrt_ps(y_low).m128_f32[0] > 10.0
                    || (v29 = (__m128)LODWORD(v17->y),
                        v30 = v17->z - v28->z,
                        v29.m128_f32[0] = (float)((float)((float)(v29.m128_f32[0] - v28->y)
                                                        * (float)(v29.m128_f32[0] - v28->y))
                                                + (float)((float)(v17->x - v28->x) * (float)(v17->x - v28->x)))
                                        + (float)(v30 * v30),
                        _mm_sqrt_ps(v29).m128_f32[0] > 10.0) )
                  {
                    v31 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mNode.mUID);
                    UFG::qPrintf("hmm? Layer with bounding box problem: %s\n", v31);
                  }
                }
              }
            }
            mGameProgressionBehaviour = this->mGameProgressionBehaviour;
            if ( mGameProgressionBehaviour )
              mGameProgressionBehaviour->vfptr->CachePropertySetData(mGameProgressionBehaviour, this, v5);
          }
        }
      }
    }
  }
}

// File Line: 782
// RVA: 0x23B520
void __fastcall UFG::SceneLayer::EnableAutoActivate(
        UFG::SceneLayer *this,
        bool enableAutoActivate,
        UFG::SceneLayer::PERISTENCE peristence)
{
  unsigned int mFlags; // ecx
  unsigned int v6; // ecx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mPrev; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mNext; // rax
  UFG::GeographicalLayerManager *Instance; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v10; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rax
  UFG::GeographicalLayerManager *v12; // rax

  mFlags = this->mFlags;
  if ( enableAutoActivate != ((mFlags & 0x80) != 0) )
  {
    v6 = mFlags >> 14;
    if ( enableAutoActivate )
    {
      if ( (v6 & 1) != 0 )
      {
        UFG::GeographicalLayerManager::GetInstance();
        if ( (this->mFlags & 0x8000) != 0 )
        {
          mPrev = this->mPrev;
          mNext = this->mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          this->mNext = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
          this->mPrev = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
          this->mFlags &= ~0x8000u;
        }
      }
      this->mFlags |= 0x80u;
      if ( (this->mFlags & 0x4000) != 0 )
      {
        Instance = UFG::GeographicalLayerManager::GetInstance();
        UFG::GeographicalLayerManager::TrackLayer(Instance, this);
      }
    }
    else
    {
      if ( (v6 & 1) != 0 )
      {
        UFG::GeographicalLayerManager::GetInstance();
        if ( (this->mFlags & 0x8000) != 0 )
        {
          v10 = this->mPrev;
          v11 = this->mNext;
          v10->mNext = v11;
          v11->mPrev = v10;
          this->mNext = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
          this->mPrev = &this->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
          this->mFlags &= ~0x8000u;
        }
      }
      this->mFlags &= ~0x80u;
      if ( (this->mFlags & 0x4000) != 0 )
      {
        v12 = UFG::GeographicalLayerManager::GetInstance();
        UFG::GeographicalLayerManager::TrackLayer(v12, this);
      }
      if ( (this->mFlags & 2) != 0 )
        UFG::SceneLayer::EnableActivate(this, 0, NON_PERSISTENT, 0);
    }
  }
  if ( peristence == PERSISTENT )
    this->mFlags |= 0x10u;
}

// File Line: 843
// RVA: 0x244E10
char __fastcall UFG::SceneLayer::RefreshLayerBoundingBox(UFG::SceneLayer *this)
{
  UFG::qBox *p_mBox; // rbp
  UFG::SceneLayerResource *p_mNext; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **v9; // rax
  float v10; // xmm0_4
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v11; // rcx
  UFG::qPropertySet *v12; // rbx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **v13; // rcx
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4

  this->mBox.mMin.x = 3.4028235e38;
  this->mBox.mMin.y = 3.4028235e38;
  this->mBox.mMin.z = 3.4028235e38;
  this->mBox.mMax.x = -3.4028235e38;
  this->mBox.mMax.y = -3.4028235e38;
  this->mBox.mMax.z = -3.4028235e38;
  p_mBox = &this[-1].mBox;
  p_mNext = (UFG::SceneLayerResource *)&this->mLayerResources.mNode.mNext[-6].mNext;
  if ( p_mNext != (UFG::SceneLayerResource *)&this[-1].mBox )
  {
    do
    {
      UFG::SceneLayerResource::AccumulateBounds(p_mNext, &this->mBox);
      p_mNext = (UFG::SceneLayerResource *)&p_mNext->mNext[-6].mNext;
    }
    while ( p_mNext != (UFG::SceneLayerResource *)p_mBox );
  }
  if ( 3.4028235e38 == this->mBox.mMin.x )
  {
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    this->mBox.mMin.x = UFG::qVector3::msZero.x;
    this->mBox.mMin.y = y;
    this->mBox.mMin.z = z;
    v6 = UFG::qVector3::msZero.y;
    v7 = UFG::qVector3::msZero.z;
    this->mBox.mMax.x = UFG::qVector3::msZero.x;
    this->mBox.mMax.y = v6;
    this->mBox.mMax.z = v7;
  }
  v8 = this->mBox.mMin.y;
  v9 = &this->mLayerResources.mNode.mNext[-6].mNext;
  this->mBox.mMin.x = this->mBox.mMin.x - `anonymous namespace::gPaddingAmount;
  v10 = this->mBox.mMin.z;
  this->mBox.mMin.y = v8 - `anonymous namespace::gPaddingAmount;
  this->mBox.mMin.z = v10 - `anonymous namespace::gPaddingAmount;
  this->mBox.mMax.x = `anonymous namespace::gPaddingAmount + this->mBox.mMax.x;
  this->mBox.mMax.y = `anonymous namespace::gPaddingAmount + this->mBox.mMax.y;
  this->mBox.mMax.z = `anonymous namespace::gPaddingAmount + this->mBox.mMax.z;
  if ( v9 != (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **)p_mBox && v9 && (v11 = v9[15]) != 0i64 )
    v12 = (UFG::qPropertySet *)((char *)v9 + (_QWORD)v11 + 120);
  else
    v12 = 0i64;
  UFG::qPropertySet::Set<UFG::qVector3>(v12, (UFG::qArray<unsigned long,0> *)&SimSym_BoundsMin, &this->mBox.mMin);
  UFG::qPropertySet::Set<UFG::qVector3>(v12, (UFG::qArray<unsigned long,0> *)&SimSym_BoundsMax, &this->mBox.mMax);
  v13 = &this->mLayerResources.mNode.mNext[-6].mNext;
  if ( v13 != (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **)p_mBox
    && this->mLayerResources.mNode.mNext != (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *)88 )
  {
    v14 = this->mBox.mMin.y;
    v15 = this->mBox.mMin.z;
    *((_DWORD *)v13 + 40) = LODWORD(this->mBox.mMin.x);
    *((float *)v13 + 41) = v14;
    *((float *)v13 + 42) = v15;
    v16 = this->mBox.mMax.y;
    v17 = this->mBox.mMax.z;
    *((_DWORD *)v13 + 43) = LODWORD(this->mBox.mMax.x);
    *((float *)v13 + 44) = v16;
    *((float *)v13 + 45) = v17;
  }
  return 1;
}

// File Line: 891
// RVA: 0x1470AD0
__int64 dynamic_initializer_for__UFG::Scene::msDefault__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::Scene::msDefault.mLayers.mTree);
  UFG::qString::qString(&stru_1423AA4A8);
  UFG::qString::qString(&stru_1423AA4D0);
  unk_1423AA4F8 = 0i64;
  UFG::gSceneLayerInventory.m_onSceneLayerResourceLoadedCallback = UFG::Scene::OnSceneLayerResourceLoad;
  UFG::gSceneLayerInventory.m_onSceneLayerResourceUnloadedCallback = UFG::Scene::OnSceneLayerResourceUnload;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Scene::msDefault__);
}

// File Line: 912
// RVA: 0x238320
void __fastcall UFG::Scene::~Scene(UFG::Scene *this)
{
  UFG::SceneLayer *i; // rbx

  for ( i = (UFG::SceneLayer *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
        i;
        i = (UFG::SceneLayer *)UFG::qBaseTreeRB::GetNext(&this->mLayers.mTree, &i->mNode) )
  {
    if ( (i->mFlags & 2) != 0 )
      UFG::SceneLayer::EnableActivate(i, 0, NON_PERSISTENT, 0);
  }
  UFG::qString::~qString(&this->mSceneFilepath);
  UFG::qString::~qString(&this->mSceneName);
  UFG::qTreeRB<UFG::SceneLayer,UFG::SceneLayer,1>::~qTreeRB<UFG::SceneLayer,UFG::SceneLayer,1>(&this->mLayers);
}

// File Line: 919
// RVA: 0x243400
void __fastcall UFG::Scene::OnSceneLayerResourceLoad(UFG::SceneLayerResource *pSceneLayerResource)
{
  unsigned int mScriptUID; // edx
  UFG::SceneLayer *v3; // rbx
  bool v4; // bp
  UFG::allocator::free_link *v5; // rax
  UFG::SceneLayer *v6; // rax
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *mPrev; // rax
  unsigned int mFlags; // ecx
  UFG::GeographicalLayerManager *Instance; // rdx
  unsigned int v10; // eax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v12; // rax
  unsigned int v13; // eax
  UFG::ILayerActivationBehaviour *mGameProgressionBehaviour; // rcx
  UFG::allocator::free_link *v15; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v16; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v17; // rax
  unsigned int mPropertySetCount; // eax
  __int64 v19; // rsi
  __int64 v20; // rbp
  __int64 mOffset; // rax
  char *v22; // rcx
  char *v23; // rax
  __int64 v24; // rcx
  UFG::qPropertySet *v25; // rbx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::SceneObjectProperties *v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::Event *v29; // rdx
  unsigned int mUID; // ecx
  UFG::allocator::free_link *v31; // rax
  UFG::allocator::free_link *v32; // [rsp+60h] [rbp+8h] BYREF
  void *v33; // [rsp+68h] [rbp+10h]

  mScriptUID = pSceneLayerResource->mScriptUID;
  if ( mScriptUID )
    v3 = (UFG::SceneLayer *)UFG::qBaseTreeRB::Get(&UFG::Scene::msDefault.mLayers.mTree, mScriptUID);
  else
    v3 = 0i64;
  v4 = v3 != 0i64;
  if ( !v3 )
  {
    v5 = UFG::qMalloc(0x70ui64, "SceneLayer", 0i64);
    v32 = v5;
    if ( v5 )
    {
      UFG::SceneLayer::SceneLayer((UFG::SceneLayer *)v5, (UFG::qSymbol *)&pSceneLayerResource->mScriptUID);
      v3 = v6;
    }
    else
    {
      v3 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&UFG::Scene::msDefault.mLayers.mTree, &v3->mNode);
  }
  unk_1423AA4F8 = v3;
  pSceneLayerResource->mpRuntimeSceneLayer = v3;
  mPrev = v3->mLayerResources.mNode.mPrev;
  mPrev->mNext = &pSceneLayerResource->UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource>;
  pSceneLayerResource->mPrev = mPrev;
  pSceneLayerResource->mNext = &v3->mLayerResources.mNode;
  v3->mLayerResources.mNode.mPrev = &pSceneLayerResource->UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource>;
  ++v3->mRefCount;
  UFG::SceneLayer::CachePropertySetData(v3);
  mFlags = v3->mFlags;
  if ( (mFlags & 0x4000) != 0 && (mFlags & 0x8000) == 0 )
  {
    Instance = UFG::GeographicalLayerManager::GetInstance();
    v10 = v3->mFlags;
    if ( (v10 & 0x8000) == 0 )
    {
      v11 = &v3->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
      if ( (v10 & 0x80) != 0 )
      {
        if ( (v10 & 2) == 0 )
          Instance = (UFG::GeographicalLayerManager *)((char *)Instance + 16);
      }
      else
      {
        Instance = (UFG::GeographicalLayerManager *)((char *)Instance + 32);
      }
      v12 = Instance->mActiveLayers.mNode.mPrev;
      v12->mNext = v11;
      v11->mPrev = v12;
      v3->mNext = &Instance->mActiveLayers.mNode;
      Instance->mActiveLayers.mNode.mPrev = v11;
      v3->mFlags |= 0x8000u;
    }
  }
  v13 = v3->mFlags;
  if ( v4 )
  {
    if ( (v13 & 2) != 0 && (pSceneLayerResource->mFlags & 8) == 0 )
    {
      UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v32);
      if ( !UFG::gIncrementalActivateManager_Active || (pSceneLayerResource->mFlags & 4) != 0 )
      {
        mPropertySetCount = pSceneLayerResource->mPropertySetCount;
        if ( mPropertySetCount )
        {
          v19 = 0i64;
          v20 = mPropertySetCount;
          do
          {
            mOffset = pSceneLayerResource->mPropertySets.mOffset;
            if ( mOffset )
              v22 = (char *)&pSceneLayerResource->mPropertySets + mOffset;
            else
              v22 = 0i64;
            v23 = &v22[v19];
            v24 = *(_QWORD *)&v22[v19];
            if ( v24 )
              v25 = (UFG::qPropertySet *)&v23[v24];
            else
              v25 = 0i64;
            SimulationMemoryPool = UFG::GetSimulationMemoryPool();
            v27 = (UFG::SceneObjectProperties *)UFG::qMemoryPool::Allocate(
                                                  SimulationMemoryPool,
                                                  0xA8ui64,
                                                  "SceneObjectProperties-Layer",
                                                  0i64,
                                                  1u);
            v33 = v27;
            if ( v27 )
              UFG::SceneObjectProperties::SceneObjectProperties(v27, v25, pSceneLayerResource);
            if ( !v27->mpParent )
              UFG::SceneObjectProperties::Activate(v27, 1u, 0i64, 0i64);
            v19 += 8i64;
            --v20;
          }
          while ( v20 );
        }
        v28 = UFG::qMalloc(0x38ui64, "layerActivatedEvent", 0i64);
        v29 = (UFG::Event *)v28;
        v33 = v28;
        if ( v28 )
        {
          mUID = UFG::gSceneLayerActivatedChannel.mUID;
          v31 = v28 + 1;
          v31->mNext = v31;
          v31[1].mNext = v31;
          v29->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
          v29->m_EventUID = mUID;
          v29->m_NamePTR = 0i64;
        }
        else
        {
          v29 = 0i64;
        }
        UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v29);
      }
      else
      {
        v15 = UFG::qMalloc(0x20ui64, "ActivatingLayer", 0i64);
        v16 = (UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *)v15;
        v33 = v15;
        if ( v15 )
        {
          v15->mNext = v15;
          v15[1].mNext = v15;
          v15[2].mNext = (UFG::allocator::free_link *)pSceneLayerResource;
          LODWORD(v15[3].mNext) = 0;
        }
        else
        {
          v16 = 0i64;
        }
        v17 = UFG::smActivatingLayers.mNode.mPrev;
        UFG::smActivatingLayers.mNode.mPrev->mNext = v16;
        v16->mPrev = v17;
        v16->mNext = (UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *)&UFG::smActivatingLayers;
        UFG::smActivatingLayers.mNode.mPrev = v16;
      }
      UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v32);
      pSceneLayerResource->mFlags |= 8u;
    }
  }
  else if ( (v13 & 0x2000) != 0 )
  {
    mGameProgressionBehaviour = v3->mGameProgressionBehaviour;
    if ( mGameProgressionBehaviour )
    {
      if ( mGameProgressionBehaviour->vfptr->LayerBelongsToCurrentFlow(mGameProgressionBehaviour, v3) )
        UFG::SceneLayer::EnableActivate(v3, 1, NON_PERSISTENT, 0);
    }
  }
}

// File Line: 1002
// RVA: 0x243700
void __fastcall UFG::Scene::OnSceneLayerResourceUnload(UFG::SceneLayerResource *pSceneLayerResource)
{
  UFG::SceneLayer *mpRuntimeSceneLayer; // rbx
  UFG::SceneLayer *v3; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mPrev; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *mNext; // rax
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v6; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v7; // rax
  unsigned int mFlags; // ecx

  mpRuntimeSceneLayer = (UFG::SceneLayer *)pSceneLayerResource->mpRuntimeSceneLayer;
  if ( mpRuntimeSceneLayer )
  {
    v3 = unk_1423AA4F8;
    if ( unk_1423AA4F8 == mpRuntimeSceneLayer )
      v3 = 0i64;
    unk_1423AA4F8 = v3;
    if ( (mpRuntimeSceneLayer->mFlags & 2) != 0 && (pSceneLayerResource->mFlags & 8) != 0 )
    {
      UFG::IncrementalActivateManager::Deactivate(pSceneLayerResource, 0);
      pSceneLayerResource->mFlags &= ~8u;
    }
    if ( (mpRuntimeSceneLayer->mFlags & 0x4000) != 0 && mpRuntimeSceneLayer->mRefCount == 1 )
    {
      UFG::GeographicalLayerManager::GetInstance();
      if ( (mpRuntimeSceneLayer->mFlags & 0x8000) != 0 )
      {
        mPrev = mpRuntimeSceneLayer->mPrev;
        mNext = mpRuntimeSceneLayer->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        mpRuntimeSceneLayer->mNext = &mpRuntimeSceneLayer->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
        mpRuntimeSceneLayer->mPrev = &mpRuntimeSceneLayer->UFG::qNode<UFG::SceneLayer,UFG::SceneLayer>;
        mpRuntimeSceneLayer->mFlags &= ~0x8000u;
      }
    }
    v6 = pSceneLayerResource->mPrev;
    v7 = pSceneLayerResource->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    pSceneLayerResource->mPrev = &pSceneLayerResource->UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource>;
    pSceneLayerResource->mNext = &pSceneLayerResource->UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource>;
    pSceneLayerResource->mpRuntimeSceneLayer = 0i64;
    if ( mpRuntimeSceneLayer->mRefCount-- == 1 )
    {
      mFlags = mpRuntimeSceneLayer->mFlags;
      if ( (mFlags & 0x10) == 0 && (mFlags & 0x200000) == 0 )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::Scene::msDefault,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)mpRuntimeSceneLayer);
        UFG::SceneLayer::~SceneLayer(mpRuntimeSceneLayer);
        operator delete[](mpRuntimeSceneLayer);
      }
    }
  }
}

// File Line: 1097
// RVA: 0x23B9B0
UFG::qBaseTreeRB *__fastcall UFG::Scene::FindLayer(UFG::Scene *this, UFG::qSymbol *name)
{
  unsigned int mUID; // edx

  mUID = name->mUID;
  if ( mUID )
    return UFG::qBaseTreeRB::Get(&this->mLayers.mTree, mUID);
  else
    return 0i64;
}

// File Line: 1104
// RVA: 0x23BC80
UFG::qBaseTreeRB *__fastcall UFG::Scene::FindOrCreateLayer(UFG::Scene *this, UFG::qSymbol *name)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *result; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SceneLayer *v7; // rax
  UFG::SceneLayer *v8; // rbx

  mUID = name->mUID;
  if ( !mUID || (result = UFG::qBaseTreeRB::Get(&this->mLayers.mTree, mUID)) == 0i64 )
  {
    v6 = UFG::qMalloc(0x70ui64, "SceneLayer", 0i64);
    if ( v6 )
    {
      UFG::SceneLayer::SceneLayer((UFG::SceneLayer *)v6, name);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    UFG::SceneLayer::CachePropertySetData(v8);
    UFG::qBaseTreeRB::Add(&this->mLayers.mTree, &v8->mNode);
    return (UFG::qBaseTreeRB *)v8;
  }
  return result;
}

// File Line: 1130
// RVA: 0x23B9C0
UFG::SceneLayer *__fastcall UFG::Scene::FindLayerContainingObject(
        UFG::Scene *this,
        UFG::qSymbol *objectName,
        UFG::qPropertySet **ppObjectPropertySet)
{
  UFG::qBaseNodeRB *Head; // r15
  __int64 mChild; // rdi
  __int64 v8; // rax
  __int64 v9; // rsi
  __int64 v10; // rbx
  __int64 v11; // rax
  UFG::qPropertySet *v12; // rcx
  UFG::qPropertySet *ObjectPropertySetRecurse; // rax

  Head = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
  if ( !Head )
    return 0i64;
  while ( 1 )
  {
    mChild = (__int64)Head[2].mParent[-3].mChild;
    if ( (UFG::qBaseNodeRB *)mChild != &Head[-1] )
      break;
LABEL_12:
    Head = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext(&this->mLayers.mTree, Head);
    if ( !Head )
      return 0i64;
  }
  while ( 1 )
  {
    v8 = *(_QWORD *)(mChild + 112);
    if ( v8 )
    {
      v9 = v8 + mChild + 112;
      if ( v9 )
      {
        v10 = 0i64;
        if ( *(_DWORD *)(mChild + 108) )
          break;
      }
    }
LABEL_11:
    mChild = *(_QWORD *)(mChild + 96) - 88i64;
    if ( (UFG::qBaseNodeRB *)mChild == &Head[-1] )
      goto LABEL_12;
  }
  while ( 1 )
  {
    v11 = *(_QWORD *)(v9 + 8 * v10);
    v12 = v11 ? (UFG::qPropertySet *)(v11 + v9 + 8 * v10) : 0i64;
    ObjectPropertySetRecurse = UFG::FindObjectPropertySetRecurse(v12, objectName);
    if ( ObjectPropertySetRecurse )
      break;
    v10 = (unsigned int)(v10 + 1);
    if ( (unsigned int)v10 >= *(_DWORD *)(mChild + 108) )
      goto LABEL_11;
  }
  if ( ppObjectPropertySet )
    *ppObjectPropertySet = ObjectPropertySetRecurse;
  return (UFG::SceneLayer *)Head;
}

// File Line: 1183
// RVA: 0x2445D0
void __fastcall UFG::Scene::Purge(UFG::Scene *this)
{
  UFG::SceneLayer *Head; // rbx
  UFG::qBaseTreeRB *Next; // rdi

  Head = (UFG::SceneLayer *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
  if ( Head )
  {
    do
    {
      Next = UFG::qBaseTreeRB::GetNext(&this->mLayers.mTree, &Head->mNode);
      if ( (Head->mFlags & 2) != 0 )
        UFG::SceneLayer::EnableActivate(Head, 0, NON_PERSISTENT, 0);
      if ( (UFG::qBox *)&Head->mLayerResources.mNode.mNext[-6].mNext == &Head[-1].mBox )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)this,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)Head);
        UFG::SceneLayer::~SceneLayer(Head);
        operator delete[](Head);
      }
      Head = (UFG::SceneLayer *)Next;
    }
    while ( Next );
  }
}

// File Line: 1205
// RVA: 0x243390
void __fastcall UFG::Scene::OnRestoreCheckpoint(UFG::Scene *this)
{
  UFG::SceneLayer *i; // rbx
  unsigned int mFlags; // edx

  for ( i = (UFG::SceneLayer *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
        i;
        i = (UFG::SceneLayer *)UFG::qBaseTreeRB::GetNext(&this->mLayers.mTree, &i->mNode) )
  {
    mFlags = i->mFlags;
    if ( (mFlags & 0x2000) == 0 && (mFlags & 2) != 0 )
      UFG::SceneLayer::EnableActivate(i, 0, NON_PERSISTENT, 0);
  }
}

// File Line: 1271
// RVA: 0x239E30
void __fastcall UFG::SceneLayerResource::AddSOP(UFG::SceneLayerResource *this, UFG::SceneObjectProperties *pSOPToAdd)
{
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v2; // rdx
  UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *p_mObjects; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *mPrev; // rax

  v2 = &pSOPToAdd->UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties>;
  p_mObjects = &this->mObjects;
  mPrev = p_mObjects->mNode.mPrev;
  mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = &p_mObjects->mNode;
  p_mObjects->mNode.mPrev = v2;
}

