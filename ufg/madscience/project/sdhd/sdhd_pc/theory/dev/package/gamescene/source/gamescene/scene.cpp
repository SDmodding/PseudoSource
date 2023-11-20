// File Line: 72
// RVA: 0x1470E70
__int64 anonymous_namespace_::_dynamic_initializer_for__SceneLayer_type_id__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SceneLayer1", 0xFFFFFFFF);
  `anonymous namespace'::SceneLayer_type_id = result;
  return result;
}

// File Line: 73
// RVA: 0x1470E90
__int64 anonymous_namespace_::_dynamic_initializer_for__Scene_type_id__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Scene1", 0xFFFFFFFF);
  `anonymous namespace'::Scene_type_id = result;
  return result;
}

// File Line: 144
// RVA: 0x237840
void __fastcall UFG::SceneLayer::SceneLayer(UFG::SceneLayer *this, UFG::qSymbol *name)
{
  unsigned int v2; // eax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v3; // rax
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  UFG::qList<UFG::SceneLayerResource,UFG::SceneLayerResource,1,0> *v8; // [rsp+48h] [rbp+10h]

  v2 = name->mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v2;
  v3 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&this->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  *(_QWORD *)&this->mFlags = 0i64;
  v8 = &this->mLayerResources;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  *(_QWORD *)&this->mBox.mMin.x = 0i64;
  *(_QWORD *)&this->mBox.mMin.z = 0i64;
  *(_QWORD *)&this->mBox.mMax.y = 0i64;
  this->mDeactivateTimer = 0.0;
  this->mIndoorCategory.mUID = -1;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mBox.mMin.x = UFG::qVector3::msZero.x;
  this->mBox.mMin.y = v4;
  this->mBox.mMin.z = v5;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  this->mBox.mMax.x = UFG::qVector3::msZero.x;
  this->mBox.mMax.y = v6;
  this->mBox.mMax.z = v7;
  this->mGameProgressionBehaviour = UFG::ILayerActivationBehaviour::Create(this);
}

// File Line: 156
// RVA: 0x2383B0
void __fastcall UFG::SceneLayer::~SceneLayer(UFG::SceneLayer *this)
{
  UFG::SceneLayer *v1; // rdi
  UFG::qList<UFG::SceneLayerResource,UFG::SceneLayerResource,1,0> *v2; // rbx
  signed __int64 i; // rax
  _QWORD *v4; // rdx
  __int64 v5; // rcx
  _QWORD *v6; // rax
  UFG::ILayerActivationBehaviour *v7; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v8; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v9; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v10; // rdx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v12; // rax

  v1 = this;
  this->mFlags |= 0x200000u;
  UFG::SceneLayer::Empty(this);
  v2 = &v1->mLayerResources;
  for ( i = (signed __int64)&v1->mLayerResources.mNode.mNext[-6].mNext;
        (UFG::qBox *)i != &v1[-1].mBox;
        i = (signed __int64)&v1->mLayerResources.mNode.mNext[-6].mNext )
  {
    v4 = (_QWORD *)(i + 88);
    v5 = *(_QWORD *)(i + 88);
    v6 = *(_QWORD **)(i + 96);
    *(_QWORD *)(v5 + 8) = v6;
    *v6 = v5;
    *v4 = v4;
    v4[1] = v4;
  }
  v7 = v1->mGameProgressionBehaviour;
  if ( v7 )
    v7->vfptr->__vecDelDtor(v7, 1u);
  UFG::qList<UFG::SceneLayerResource,UFG::SceneLayerResource,1,0>::DeleteNodes(&v1->mLayerResources);
  v8 = v2->mNode.mPrev;
  v9 = v1->mLayerResources.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mNode.mPrev = &v2->mNode;
  v1->mLayerResources.mNode.mNext = &v1->mLayerResources.mNode;
  v10 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&v1->mPrev;
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v10->mPrev = v10;
  v10->mNext = v10;
}

// File Line: 179
// RVA: 0x23BAB0
UFG::qPropertySet *__fastcall UFG::SceneLayer::FindObjectPropertySet(UFG::SceneLayer *this, UFG::qSymbol *objectName)
{
  UFG::qBox *v2; // r14
  UFG::qSymbol *v3; // rbp
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **v4; // rdi
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v5; // rax
  signed __int64 v6; // rsi
  __int64 v7; // rbx
  __int64 v8; // rax
  UFG::qPropertySet *v9; // rcx
  UFG::qPropertySet *result; // rax

  v2 = &this[-1].mBox;
  v3 = objectName;
  v4 = &this->mLayerResources.mNode.mNext[-6].mNext;
  if ( v4 == (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **)&this[-1].mBox )
    return 0i64;
  while ( 1 )
  {
    v5 = v4[14];
    if ( v5 )
    {
      v6 = (signed __int64)v4 + (_QWORD)v5 + 112;
      if ( v6 )
      {
        v7 = 0i64;
        if ( *((_DWORD *)v4 + 27) )
          break;
      }
    }
LABEL_10:
    v4 = &v4[12][-6].mNext;
    if ( v4 == (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **)v2 )
      return 0i64;
  }
  while ( 1 )
  {
    v8 = *(_QWORD *)(v6 + 8 * v7);
    v9 = (UFG::qPropertySet *)(v8 ? v8 + v6 + 8 * v7 : 0i64);
    result = UFG::FindObjectPropertySetRecurse(v9, v3);
    if ( result )
      return result;
    v7 = (unsigned int)(v7 + 1);
    if ( (unsigned int)v7 >= *((_DWORD *)v4 + 27) )
      goto LABEL_10;
  }
}

// File Line: 213
// RVA: 0x23E100
UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **__fastcall UFG::SceneLayer::GetSingleEditorSceneLayerResource(UFG::SceneLayer *this)
{
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **result; // rax

  result = 0i64;
  if ( (UFG::qBox *)&this->mLayerResources.mNode.mNext[-6].mNext != &this[-1].mBox )
    result = &this->mLayerResources.mNode.mNext[-6].mNext;
  return result;
}

// File Line: 334
// RVA: 0x23B000
void __fastcall UFG::SceneLayer::Empty(UFG::SceneLayer *this)
{
  UFG::qBox *v1; // rbx
  UFG::SceneLayerResource *v2; // r14
  char v3; // r13
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v4; // rdx
  signed __int64 v5; // r12
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v6; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v7; // rax
  UFG::SceneObjectProperties *v8; // rbx
  UFG::SimObject *v9; // rbp
  char v10; // di
  UFG::qPropertySet *v11; // rcx
  UFG::SchemaDef *v12; // rax
  UFG::qPropertySet *v13; // rcx
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
  UFG::TransformNodeComponent *v26; // rcx
  UFG::SceneObjectProperties *v27; // rax
  __int64 v28; // rax
  UFG::SceneObjectProperties **v29; // rdi
  unsigned __int64 i; // rsi
  UFG::qBox *v31; // [rsp+68h] [rbp+10h]

  v1 = &this[-1].mBox;
  v2 = (UFG::SceneLayerResource *)&this->mLayerResources.mNode.mNext[-6].mNext;
  v31 = &this[-1].mBox;
  v3 = (this->mFlags >> 1) & 1;
  if ( v2 == (UFG::SceneLayerResource *)&this[-1].mBox )
    return;
  do
  {
    v4 = v2->mObjects.mNode.mNext;
    v5 = (signed __int64)&v2->mNext[-6].mNext;
    if ( &v4[-4] == (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v2->mDebugName[28] )
      goto LABEL_53;
    do
    {
      v6 = v4->mPrev;
      v7 = v4->mNext;
      v8 = (UFG::SceneObjectProperties *)&v4[-4];
      v6->mNext = v7;
      v7->mPrev = v6;
      v4->mPrev = v4;
      v4->mNext = v4;
      if ( !v3 )
        goto LABEL_51;
      v9 = v8->m_pSimObject;
      if ( !v9 )
        goto LABEL_51;
      v10 = 0;
      if ( (v9->m_Flags & 0x8000u) != 0 )
      {
        v10 = 1;
        goto LABEL_28;
      }
      v11 = v8->mpWritableProperties;
      if ( !v11 )
        v11 = v8->mpConstProperties;
      v12 = UFG::PropertySetManager::GetSchemaForProperty(v11, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID);
      if ( v12 )
      {
        v13 = v8->mpWritableProperties;
        if ( !v13 )
          v13 = v8->mpConstProperties;
        v14 = UFG::qPropertySet::Get<UFG::qPropertySet>(v13, &v12->mPropertyName, DEPTH_RECURSE);
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
      v15 = UFG::qPropertySet::Get<unsigned long>(v14, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID, DEPTH_RECURSE);
      if ( v15 && (*v15 >> 2) & 1 )
      {
        v16 = v8->mpWritableProperties;
        if ( !v16 )
          v16 = v8->mpConstProperties;
        v17 = UFG::PropertySetManager::GetSchemaForProperty(v16, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID);
        if ( v17 )
        {
          v18 = v8->mpWritableProperties;
          if ( !v18 )
            v18 = v8->mpConstProperties;
          v19 = UFG::qPropertySet::Get<UFG::qPropertySet>(v18, &v17->mPropertyName, DEPTH_RECURSE);
        }
        else
        {
          v19 = v8->mpWritableProperties;
          if ( v19 )
          {
LABEL_27:
            UFG::qPropertySet::Get<unsigned long>(v19, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID, DEPTH_RECURSE);
LABEL_28:
            v20 = v8->mpWritableProperties;
            if ( !v20 )
              v20 = v8->mpConstProperties;
            v21 = UFG::PropertySetManager::GetSchemaForProperty(v20, (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID);
            if ( v21 )
            {
              v22 = v8->mpWritableProperties;
              if ( !v22 )
                v22 = v8->mpConstProperties;
              v23 = UFG::qPropertySet::Get<UFG::qPropertySet>(v22, &v21->mPropertyName, DEPTH_RECURSE);
            }
            else
            {
              v23 = v8->mpWritableProperties;
              if ( v23 )
              {
LABEL_37:
                v24 = UFG::qPropertySet::Get<unsigned long>(
                        v23,
                        (UFG::qSymbol *)&SimSym_CreateObjectFlags.mUID,
                        DEPTH_RECURSE);
                if ( v24 && (*v24 >> 2) & 1 )
                {
LABEL_40:
                  v8->m_Flags |= 8u;
                  if ( v8->mpParent )
                  {
                    v25 = v8->m_pSimObject;
                    if ( v25 )
                    {
                      v26 = v25->m_pTransformNodeComponent;
                      if ( v26 )
                      {
                        if ( v26->mParent )
                          UFG::TransformNodeComponent::SetParentKeepWorld(v26, 0i64, 0);
                      }
                    }
                  }
                  v27 = v8->mpParent;
                  v8->mpLayerResource = 0i64;
                  if ( v27 )
                    v27->mDeleteChildSimObjectOnDestruct = 0;
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
      v28 = v8->mChildren.mCount;
      if ( (_DWORD)v28 )
      {
        v29 = v8->mChildren.mppArray;
        for ( i = (unsigned __int64)&v29[v28]; (unsigned __int64)v29 < i; ++v29 )
          UFG::SceneObjectProperties::Deactivate(*v29);
      }
      UFG::SceneObjectProperties::mspDeactivateFunc(v8);
      UFG::SimObject::Destroy(v9);
LABEL_51:
      v4 = v2->mObjects.mNode.mNext;
    }
    while ( &v4[-4] != (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&v2->mDebugName[28] );
    v1 = v31;
LABEL_53:
    if ( !(v2->mFlags & 1) )
    {
      if ( v2->mFlags & 2 )
      {
        UFG::qResourceInventory::Remove(
          (UFG::qResourceInventory *)&UFG::gSceneLayerInventory.vfptr,
          (UFG::qResourceData *)&v2->mNode);
        v2->mFlags &= 0xFFFFFFFD;
        if ( UFG::gSceneLayerInventory.m_onSceneLayerResourceUnloadedCallback )
          UFG::gSceneLayerInventory.m_onSceneLayerResourceUnloadedCallback(v2);
        if ( v2->mFlags & 1 )
          UFG::SceneLayerResource::~SceneLayerResource(v2);
      }
      UFG::SceneLayerResource::~SceneLayerResource(v2);
      UFG::qMemoryPool::Free(&gPropertySetMemoryPool, v2);
    }
    v2 = (UFG::SceneLayerResource *)v5;
  }
  while ( (UFG::qBox *)v5 != v1 );
}

// File Line: 372
// RVA: 0x23B380
void __fastcall UFG::SceneLayer::EnableActivate(UFG::SceneLayer *this, bool activate, UFG::SceneLayer::PERISTENCE peristence, bool forceSynchronous)
{
  UFG::SceneLayer *v4; // rdi
  unsigned int v5; // ecx
  bool v6; // bp
  UFG::SceneLayer::PERISTENCE v7; // er14
  bool v8; // bl
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v9; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v10; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rdx
  bool v12; // zf
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v13; // rbx
  signed __int64 v14; // rsi
  UFG::SceneLayerResource *j; // rbx
  UFG::SceneLayerResource *i; // rbx
  UFG::GeographicalLayerManager *v17; // rdx
  unsigned int v18; // eax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v19; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v20; // rax

  v4 = this;
  v5 = this->mFlags;
  v6 = forceSynchronous;
  v7 = peristence;
  v8 = activate;
  if ( activate != ((v5 >> 1) & 1) )
  {
    if ( (v5 >> 14) & 1 )
    {
      UFG::GeographicalLayerManager::GetInstance();
      if ( (v4->mFlags >> 15) & 1 )
      {
        v9 = v4->mPrev;
        v10 = v4->mNext;
        v11 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&v4->mPrev;
        v9->mNext = v10;
        v10->mPrev = v9;
        v11->mNext = v11;
        v11->mPrev = v11;
        v4->mFlags &= 0xFFFF7FFF;
      }
    }
    v12 = v8 == 0;
    v13 = v4->mLayerResources.mNode.mNext;
    v14 = (signed __int64)&v4[-1].mBox;
    if ( v12 )
    {
      v4->mFlags &= 0xFFFFFFFD;
      for ( i = (UFG::SceneLayerResource *)&v13[-6].mNext;
            i != (UFG::SceneLayerResource *)v14;
            i = (UFG::SceneLayerResource *)&i->mNext[-6].mNext )
      {
        if ( i->mFlags & 8 )
        {
          UFG::IncrementalActivateManager::Deactivate(i, v6);
          i->mFlags &= 0xFFFFFFF7;
        }
      }
    }
    else
    {
      v4->mFlags |= 2u;
      for ( j = (UFG::SceneLayerResource *)&v13[-6].mNext;
            j != (UFG::SceneLayerResource *)v14;
            j = (UFG::SceneLayerResource *)&j->mNext[-6].mNext )
      {
        if ( (!UFG::SceneLayer::sbManageSubLayerActivation
           || v7 == 1
           || !((v4->mFlags >> 14) & 1)
           || (j->mFlags >> 2) & 1
           || UFG::SceneLayerResource::IsGeoInFrustrum(j))
          && !(j->mFlags & 8) )
        {
          UFG::IncrementalActivateManager::Activate(j, v6);
          j->mFlags |= 8u;
        }
      }
    }
    if ( v7 == 1 )
      v4->mFlags |= 0x10u;
    if ( (v4->mFlags >> 14) & 1 )
    {
      v17 = UFG::GeographicalLayerManager::GetInstance();
      v18 = v4->mFlags;
      if ( !((v4->mFlags >> 15) & 1) )
      {
        v19 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&v4->mPrev;
        if ( (v18 >> 7) & 1 )
        {
          if ( !((v18 >> 1) & 1) )
            v17 = (UFG::GeographicalLayerManager *)((char *)v17 + 16);
        }
        else
        {
          v17 = (UFG::GeographicalLayerManager *)((char *)v17 + 32);
        }
        v20 = v17->mActiveLayers.mNode.mPrev;
        v20->mNext = v19;
        v19->mPrev = v20;
        v4->mNext = &v17->mActiveLayers.mNode;
        v17->mActiveLayers.mNode.mPrev = v19;
        v4->mFlags |= 0x8000u;
      }
    }
  }
}

// File Line: 472
// RVA: 0x23B810
void __fastcall UFG::SceneLayer::EnableGeographical(UFG::SceneLayer *this, bool geographical, UFG::SceneLayer::PERISTENCE peristence)
{
  UFG::SceneLayer *v3; // rbx
  unsigned int v4; // ecx
  UFG::SceneLayer::PERISTENCE v5; // edi
  UFG::GeographicalLayerManager *v6; // rdx
  unsigned int v7; // eax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v8; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v9; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v10; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v12; // rdx

  v3 = this;
  v4 = this->mFlags;
  v5 = peristence;
  if ( geographical != ((v4 >> 14) & 1) )
  {
    if ( geographical )
    {
      v3->mFlags = v4 | 0x4000;
      v6 = UFG::GeographicalLayerManager::GetInstance();
      v7 = v3->mFlags;
      if ( !((v3->mFlags >> 15) & 1) )
      {
        v8 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&v3->mPrev;
        if ( (v7 >> 7) & 1 )
        {
          if ( !((v7 >> 1) & 1) )
            v6 = (UFG::GeographicalLayerManager *)((char *)v6 + 16);
        }
        else
        {
          v6 = (UFG::GeographicalLayerManager *)((char *)v6 + 32);
        }
        v9 = v6->mActiveLayers.mNode.mPrev;
        v9->mNext = v8;
        v8->mPrev = v9;
        v3->mNext = &v6->mActiveLayers.mNode;
        v6->mActiveLayers.mNode.mPrev = v8;
        v3->mFlags |= 0x8000u;
      }
    }
    else
    {
      v3->mFlags = v4 & 0xFFFFBFFF;
      UFG::GeographicalLayerManager::GetInstance();
      if ( (v3->mFlags >> 15) & 1 )
      {
        v10 = v3->mPrev;
        v11 = v3->mNext;
        v12 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&v3->mPrev;
        v10->mNext = v11;
        v11->mPrev = v10;
        v12->mNext = v12;
        v12->mPrev = v12;
        v3->mFlags &= 0xFFFF7FFF;
      }
    }
  }
  if ( v5 == 1 )
    v3->mFlags |= 0x10u;
}

// File Line: 514
// RVA: 0x23BEF0
void __fastcall UFG::SceneLayer::GenerateUniqueNameForSkookum(UFG::SceneLayer *this, const char *objRootName, UFG::qSymbol *pObjName)
{
  const char *v3; // rbx
  UFG::qSymbol *v4; // rsi
  UFG::SceneLayer *v5; // rdi
  UFG::qSymbol *v6; // rax
  unsigned int v7; // eax
  signed __int64 v8; // rbx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v9; // rdx
  signed __int64 v10; // rdx
  signed __int64 v11; // rcx
  UFG::qSymbol name; // [rsp+40h] [rbp+8h]
  UFG::qSymbol v13; // [rsp+50h] [rbp+18h]
  UFG::qSymbol result; // [rsp+58h] [rbp+20h]

  v3 = objRootName;
  v4 = pObjName;
  v5 = this;
  v6 = UFG::qSymbol::create_suffix(&result, (UFG::qSymbol *)&this->mNode.mUID, "-");
  UFG::qSymbol::create_suffix(&v13, v6, v3);
  v7 = v13.mUID;
  v8 = (signed __int64)&v5[-1].mBox;
  while ( 1 )
  {
    v9 = v5->mLayerResources.mNode.mNext;
    name.mUID = v7;
    v10 = (signed __int64)&v9[-6].mNext;
    if ( v10 == v8 )
      break;
    while ( 1 )
    {
      v11 = *(_QWORD *)(v10 + 152) - 64i64;
      if ( v11 != v10 + 80 )
        break;
LABEL_6:
      v10 = *(_QWORD *)(v10 + 96) - 88i64;
      if ( v10 == v8 )
        goto LABEL_7;
    }
    while ( *(_DWORD *)(v11 + 28) != v7 )
    {
      v11 = *(_QWORD *)(v11 + 72) - 64i64;
      if ( v11 == v10 + 80 )
        goto LABEL_6;
    }
    v7 = UFG::qSymbol::create_increment(&result, &name, 1)->mUID;
  }
LABEL_7:
  v4->mUID = v7;
}

// File Line: 529
// RVA: 0x23DA50
UFG::qPropertySet *__fastcall UFG::SceneLayer::GetPropertySet(UFG::SceneLayer *this)
{
  UFG::SceneLayer *v1; // rdx
  UFG::qBaseNodeRB *v2; // rax
  UFG::qPropertySet *result; // rax

  v1 = (UFG::SceneLayer *)&this->mLayerResources.mNode.mNext[-6].mNext;
  if ( v1 != (UFG::SceneLayer *)&this[-1].mBox
    && this->mLayerResources.mNode.mNext != (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *)88
    && (v2 = v1[1].mNode.mChild[0]) != 0i64 )
  {
    result = (UFG::qPropertySet *)((char *)&v2[3].mUID + (_QWORD)v1);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 582
// RVA: 0x23D800
UFG::qSymbol *__fastcall UFG::SceneLayer::GetIndoorCategory(UFG::SceneLayer *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rax

  v2 = &this->mIndoorCategory;
  if ( !((this->mFlags >> 9) & 1) )
    v2 = &UFG::gNullQSymbol;
  result->mUID = v2->mUID;
  return result;
}

// File Line: 655
// RVA: 0x239EF0
void __fastcall UFG::SceneLayer::CachePropertySetData(UFG::SceneLayer *this)
{
  UFG::SceneLayer *v1; // rbx
  UFG::qBox *v2; // rax
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **v3; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v4; // rax
  UFG::qPropertySet *v5; // rdi
  unsigned int v6; // esi
  int v7; // esi
  bool *v8; // rax
  bool *v9; // rax
  bool *v10; // rax
  UFG::qSymbol *v11; // rax
  UFG::qSymbol *v12; // rcx
  unsigned int v13; // eax
  bool *v14; // rax
  bool *v15; // rax
  UFG::qVector3 *v16; // r14
  UFG::qVector3 *v17; // rax
  UFG::qVector3 *v18; // rsi
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // eax
  unsigned int v24; // ecx
  UFG::qVector3 *v25; // rax
  float v26; // xmm6_4
  __m128 v27; // xmm8
  float v28; // xmm7_4
  UFG::qVector3 *v29; // rax
  __m128 v30; // xmm2
  float v31; // xmm0_4
  char *v32; // rax
  UFG::ILayerActivationBehaviour *v33; // rcx

  v1 = this;
  v2 = &this[-1].mBox;
  v3 = &this->mLayerResources.mNode.mNext[-6].mNext;
  if ( v3 != (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **)v2 )
  {
    if ( v3 )
    {
      v4 = v3[15];
      if ( v4 )
      {
        v5 = (UFG::qPropertySet *)((char *)v3 + (_QWORD)v4 + 120);
        if ( v5 )
        {
          v6 = v1->mFlags;
          if ( !_bittest((const signed int *)&v6, 0xCu) )
          {
            v7 = v1->mFlags & 0x4890;
            v8 = UFG::qPropertySet::Get<bool>(
                   (UFG::qPropertySet *)((char *)v3 + (_QWORD)v4 + 120),
                   (UFG::qSymbol *)&SimSym_InitialActivate.mUID,
                   DEPTH_RECURSE);
            if ( v8 && *v8 )
              v1->mFlags |= 0x2000u;
            v9 = UFG::qPropertySet::Get<bool>(v5, (UFG::qSymbol *)&SimSym_Geographical.mUID, DEPTH_RECURSE);
            if ( v9 && *v9 )
              v1->mFlags |= 0x4000u;
            v10 = UFG::qPropertySet::Get<bool>(v5, (UFG::qSymbol *)&SimSym_AutoActivate.mUID, DEPTH_RECURSE);
            if ( !v10 || *v10 )
              v1->mFlags |= 0x80u;
            v11 = UFG::qPropertySet::Get<UFG::qSymbol>(v5, (UFG::qSymbol *)&SimSym_LayerCategory.mUID, DEPTH_RECURSE);
            v12 = &UFG::gNullQSymbol;
            if ( v11 )
              v12 = v11;
            v13 = v12->mUID;
            v1->mIndoorCategory = (UFG::qSymbol)v12->mUID;
            if ( v13 == -1 )
            {
              v1->mFlags |= 0x100u;
            }
            else
            {
              v1->mFlags |= 0x200u;
              v14 = UFG::qPropertySet::Get<bool>(v5, (UFG::qSymbol *)&SimSym_CategoryOut.mUID, DEPTH_RECURSE);
              if ( v14 && *v14 )
                v1->mFlags |= 0x100u;
              v15 = UFG::qPropertySet::Get<bool>(v5, (UFG::qSymbol *)&SimSym_CategoryAudio.mUID, DEPTH_RECURSE);
              if ( v15 && *v15 )
                v1->mFlags |= 0x400u;
            }
            v1->mFlags |= 0x1000u;
            if ( v1->mFlags & 0x10 )
              v1->mFlags = v7 | v1->mFlags & 0xFFFFB76F;
            v16 = UFG::qPropertySet::Get<UFG::qVector3>(v5, (UFG::qSymbol *)&SimSym_BoundsMin.mUID, DEPTH_RECURSE);
            v17 = UFG::qPropertySet::Get<UFG::qVector3>(v5, (UFG::qSymbol *)&SimSym_BoundsMax.mUID, DEPTH_RECURSE);
            v18 = v17;
            if ( v16 )
            {
              if ( v17 )
              {
                v19 = v16->y;
                v20 = v16->z;
                v1->mBox.mMin.x = v16->x;
                v1->mBox.mMin.y = v19;
                v1->mBox.mMin.z = v20;
                v21 = v17->y;
                v22 = v17->z;
                v23 = v17->x;
                v1->mBox.mMax.y = v21;
                v1->mBox.mMax.z = v22;
                v1->mBox.mMax.x = v23;
                v24 = v1->mFlags;
                if ( (v1->mFlags >> 1) & 1 || _bittest((const signed int *)&v24, 0xDu) )
                {
                  if ( (v24 >> 20) & 1 )
                  {
                    UFG::SceneLayer::RefreshLayerBoundingBox(v1);
                    v25 = UFG::qPropertySet::Get<UFG::qVector3>(
                            v5,
                            (UFG::qSymbol *)&SimSym_BoundsMin.mUID,
                            DEPTH_RECURSE);
                    v26 = v25->x;
                    v27 = (__m128)LODWORD(v25->y);
                    v28 = v25->z;
                    v29 = UFG::qPropertySet::Get<UFG::qVector3>(
                            v5,
                            (UFG::qSymbol *)&SimSym_BoundsMax.mUID,
                            DEPTH_RECURSE);
                    v27.m128_f32[0] = (float)((float)((float)(v27.m128_f32[0] - v16->y)
                                                    * (float)(v27.m128_f32[0] - v16->y))
                                            + (float)((float)(v26 - v16->x) * (float)(v26 - v16->x)))
                                    + (float)((float)(v28 - v16->z) * (float)(v28 - v16->z));
                    if ( COERCE_FLOAT(_mm_sqrt_ps(v27)) > 10.0
                      || (v30 = (__m128)LODWORD(v18->y),
                          v31 = v18->z - v29->z,
                          v30.m128_f32[0] = (float)((float)((float)(v30.m128_f32[0] - v29->y)
                                                          * (float)(v30.m128_f32[0] - v29->y))
                                                  + (float)((float)(v18->x - v29->x) * (float)(v18->x - v29->x)))
                                          + (float)(v31 * v31),
                          COERCE_FLOAT(_mm_sqrt_ps(v30)) > 10.0) )
                    {
                      v32 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1->mNode.mUID);
                      UFG::qPrintf("hmm? Layer with bounding box problem: %s\n", v32);
                    }
                  }
                }
              }
            }
            v33 = v1->mGameProgressionBehaviour;
            if ( v33 )
              v33->vfptr->CachePropertySetData(v33, v1, v5);
          }
        }
      }
    }
  }
}

// File Line: 782
// RVA: 0x23B520
void __fastcall UFG::SceneLayer::EnableAutoActivate(UFG::SceneLayer *this, bool enableAutoActivate, UFG::SceneLayer::PERISTENCE peristence)
{
  UFG::SceneLayer *v3; // rbx
  unsigned int v4; // ecx
  UFG::SceneLayer::PERISTENCE v5; // edi
  unsigned int v6; // ecx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v7; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v8; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v9; // rdx
  UFG::GeographicalLayerManager *v10; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v12; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v13; // rdx
  UFG::GeographicalLayerManager *v14; // rax

  v3 = this;
  v4 = this->mFlags;
  v5 = peristence;
  if ( enableAutoActivate != ((v4 >> 7) & 1) )
  {
    v6 = v4 >> 14;
    if ( enableAutoActivate )
    {
      if ( v6 & 1 )
      {
        UFG::GeographicalLayerManager::GetInstance();
        if ( (v3->mFlags >> 15) & 1 )
        {
          v7 = v3->mPrev;
          v8 = v3->mNext;
          v9 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&v3->mPrev;
          v7->mNext = v8;
          v8->mPrev = v7;
          v9->mNext = v9;
          v9->mPrev = v9;
          v3->mFlags &= 0xFFFF7FFF;
        }
      }
      v3->mFlags |= 0x80u;
      if ( (v3->mFlags >> 14) & 1 )
      {
        v10 = UFG::GeographicalLayerManager::GetInstance();
        UFG::GeographicalLayerManager::TrackLayer(v10, v3);
      }
    }
    else
    {
      if ( v6 & 1 )
      {
        UFG::GeographicalLayerManager::GetInstance();
        if ( (v3->mFlags >> 15) & 1 )
        {
          v11 = v3->mPrev;
          v12 = v3->mNext;
          v13 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&v3->mPrev;
          v11->mNext = v12;
          v12->mPrev = v11;
          v13->mNext = v13;
          v13->mPrev = v13;
          v3->mFlags &= 0xFFFF7FFF;
        }
      }
      v3->mFlags &= 0xFFFFFF7F;
      if ( (v3->mFlags >> 14) & 1 )
      {
        v14 = UFG::GeographicalLayerManager::GetInstance();
        UFG::GeographicalLayerManager::TrackLayer(v14, v3);
      }
      if ( (v3->mFlags >> 1) & 1 )
        UFG::SceneLayer::EnableActivate(v3, 0, 0, 0);
    }
  }
  if ( v5 == 1 )
    v3->mFlags |= 0x10u;
}

// File Line: 843
// RVA: 0x244E10
char __fastcall UFG::SceneLayer::RefreshLayerBoundingBox(UFG::SceneLayer *this)
{
  UFG::qBox *v1; // rbp
  UFG::SceneLayer *v2; // rsi
  UFG::SceneLayerResource *v3; // rbx
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  signed __int64 v9; // rax
  float v10; // xmm0_4
  __int64 v11; // rcx
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
  v1 = &this[-1].mBox;
  v2 = this;
  v3 = (UFG::SceneLayerResource *)&this->mLayerResources.mNode.mNext[-6].mNext;
  if ( v3 != (UFG::SceneLayerResource *)&this[-1].mBox )
  {
    do
    {
      UFG::SceneLayerResource::AccumulateBounds(v3, &v2->mBox);
      v3 = (UFG::SceneLayerResource *)&v3->mNext[-6].mNext;
    }
    while ( v3 != (UFG::SceneLayerResource *)v1 );
  }
  if ( 3.4028235e38 == v2->mBox.mMin.x )
  {
    v4 = UFG::qVector3::msZero.y;
    v5 = UFG::qVector3::msZero.z;
    v2->mBox.mMin.x = UFG::qVector3::msZero.x;
    v2->mBox.mMin.y = v4;
    v2->mBox.mMin.z = v5;
    v6 = UFG::qVector3::msZero.y;
    v7 = UFG::qVector3::msZero.z;
    v2->mBox.mMax.x = UFG::qVector3::msZero.x;
    v2->mBox.mMax.y = v6;
    v2->mBox.mMax.z = v7;
  }
  v8 = v2->mBox.mMin.y;
  v9 = (signed __int64)&v2->mLayerResources.mNode.mNext[-6].mNext;
  v2->mBox.mMin.x = v2->mBox.mMin.x - `anonymous namespace'::gPaddingAmount;
  v10 = v2->mBox.mMin.z;
  v2->mBox.mMin.y = v8 - `anonymous namespace'::gPaddingAmount;
  v2->mBox.mMin.z = v10 - `anonymous namespace'::gPaddingAmount;
  v2->mBox.mMax.x = `anonymous namespace'::gPaddingAmount + v2->mBox.mMax.x;
  v2->mBox.mMax.y = `anonymous namespace'::gPaddingAmount + v2->mBox.mMax.y;
  v2->mBox.mMax.z = `anonymous namespace'::gPaddingAmount + v2->mBox.mMax.z;
  if ( (UFG::qBox *)v9 != v1 && v9 && (v11 = *(_QWORD *)(v9 + 120)) != 0 )
    v12 = (UFG::qPropertySet *)(v11 + v9 + 120);
  else
    v12 = 0i64;
  UFG::qPropertySet::Set<UFG::qVector3>(v12, (UFG::qSymbol *)&SimSym_BoundsMin.mUID, &v2->mBox.mMin);
  UFG::qPropertySet::Set<UFG::qVector3>(v12, (UFG::qSymbol *)&SimSym_BoundsMax.mUID, &v2->mBox.mMax);
  v13 = &v2->mLayerResources.mNode.mNext[-6].mNext;
  if ( v13 != (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> **)v1
    && v2->mLayerResources.mNode.mNext != (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *)88 )
  {
    v14 = v2->mBox.mMin.y;
    v15 = v2->mBox.mMin.z;
    *((_DWORD *)v13 + 40) = LODWORD(v2->mBox.mMin.x);
    *((float *)v13 + 41) = v14;
    *((float *)v13 + 42) = v15;
    v16 = v2->mBox.mMax.y;
    v17 = v2->mBox.mMax.z;
    *((_DWORD *)v13 + 43) = LODWORD(v2->mBox.mMax.x);
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
  return atexit(dynamic_atexit_destructor_for__UFG::Scene::msDefault__);
}

// File Line: 912
// RVA: 0x238320
void __fastcall UFG::Scene::~Scene(UFG::Scene *this)
{
  UFG::Scene *v1; // rdi
  UFG::SceneLayer *i; // rbx

  v1 = this;
  for ( i = (UFG::SceneLayer *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
        i;
        i = (UFG::SceneLayer *)UFG::qBaseTreeRB::GetNext(&v1->mLayers.mTree, &i->mNode) )
  {
    if ( (i->mFlags >> 1) & 1 )
      UFG::SceneLayer::EnableActivate(i, 0, 0, 0);
  }
  UFG::qString::~qString(&v1->mSceneFilepath);
  UFG::qString::~qString(&v1->mSceneName);
  UFG::qTreeRB<UFG::SceneLayer,UFG::SceneLayer,1>::~qTreeRB<UFG::SceneLayer,UFG::SceneLayer,1>(&v1->mLayers);
}

// File Line: 919
// RVA: 0x243400
void __fastcall UFG::Scene::OnSceneLayerResourceLoad(UFG::SceneLayerResource *pSceneLayerResource)
{
  UFG::SceneLayerResource *v1; // rdi
  unsigned int v2; // edx
  UFG::SceneLayer *v3; // rbx
  bool v4; // bp
  UFG::allocator::free_link *v5; // rax
  UFG::SceneLayer *v6; // rax
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v7; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v8; // rax
  UFG::GeographicalLayerManager *v9; // rdx
  unsigned int v10; // eax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v11; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v12; // rax
  unsigned int v13; // eax
  UFG::ILayerActivationBehaviour *v14; // rcx
  UFG::allocator::free_link *v15; // rax
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v16; // rcx
  UFG::qNode<UFG::ActivatingLayer,UFG::ActivatingLayer> *v17; // rax
  unsigned int v18; // eax
  __int64 v19; // rsi
  __int64 v20; // rbp
  __int64 v21; // rax
  signed __int64 v22; // rcx
  signed __int64 v23; // rax
  __int64 v24; // rcx
  UFG::qPropertySet *v25; // rbx
  UFG::qMemoryPool *v26; // rax
  UFG::SceneObjectProperties *v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::Event *v29; // rdx
  unsigned int v30; // ecx
  UFG::allocator::free_link *v31; // rax
  UFG::allocator::free_link *v32; // [rsp+60h] [rbp+8h]
  void *v33; // [rsp+68h] [rbp+10h]

  v1 = pSceneLayerResource;
  v2 = pSceneLayerResource->mScriptUID;
  if ( v2 )
    v3 = (UFG::SceneLayer *)UFG::qBaseTreeRB::Get(&UFG::Scene::msDefault.mLayers.mTree, v2);
  else
    v3 = 0i64;
  v4 = v3 != 0i64;
  if ( !v3 )
  {
    v5 = UFG::qMalloc(0x70ui64, "SceneLayer", 0i64);
    v32 = v5;
    if ( v5 )
    {
      UFG::SceneLayer::SceneLayer((UFG::SceneLayer *)v5, (UFG::qSymbol *)&v1->mScriptUID);
      v3 = v6;
    }
    else
    {
      v3 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&UFG::Scene::msDefault.mLayers.mTree, &v3->mNode);
  }
  unk_1423AA4F8 = v3;
  v1->mpRuntimeSceneLayer = v3;
  v7 = (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *)&v1->mPrev;
  v8 = v3->mLayerResources.mNode.mPrev;
  v8->mNext = (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *)&v1->mPrev;
  v7->mPrev = v8;
  v7->mNext = &v3->mLayerResources.mNode;
  v3->mLayerResources.mNode.mPrev = (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *)&v1->mPrev;
  ++v3->mRefCount;
  UFG::SceneLayer::CachePropertySetData(v3);
  if ( (v3->mFlags >> 14) & 1 )
  {
    if ( !((v3->mFlags >> 15) & 1) )
    {
      v9 = UFG::GeographicalLayerManager::GetInstance();
      v10 = v3->mFlags;
      if ( !((v3->mFlags >> 15) & 1) )
      {
        v11 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&v3->mPrev;
        if ( (v10 >> 7) & 1 )
        {
          if ( !((v10 >> 1) & 1) )
            v9 = (UFG::GeographicalLayerManager *)((char *)v9 + 16);
        }
        else
        {
          v9 = (UFG::GeographicalLayerManager *)((char *)v9 + 32);
        }
        v12 = v9->mActiveLayers.mNode.mPrev;
        v12->mNext = v11;
        v11->mPrev = v12;
        v3->mNext = &v9->mActiveLayers.mNode;
        v9->mActiveLayers.mNode.mPrev = v11;
        v3->mFlags |= 0x8000u;
      }
    }
  }
  v13 = v3->mFlags;
  if ( v4 )
  {
    if ( (v13 >> 1) & 1 && !(v1->mFlags & 8) )
    {
      UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v32);
      if ( !UFG::gIncrementalActivateManager_Active || (v1->mFlags >> 2) & 1 )
      {
        v18 = v1->mPropertySetCount;
        if ( v18 )
        {
          v19 = 0i64;
          v20 = v18;
          do
          {
            v21 = v1->mPropertySets.mOffset;
            if ( v21 )
              v22 = (signed __int64)&v1->mPropertySets + v21;
            else
              v22 = 0i64;
            v23 = v19 + v22;
            v24 = *(_QWORD *)(v19 + v22);
            if ( v24 )
              v25 = (UFG::qPropertySet *)(v24 + v23);
            else
              v25 = 0i64;
            v26 = UFG::GetSimulationMemoryPool();
            v27 = (UFG::SceneObjectProperties *)UFG::qMemoryPool::Allocate(
                                                  v26,
                                                  0xA8ui64,
                                                  "SceneObjectProperties-Layer",
                                                  0i64,
                                                  1u);
            v33 = v27;
            if ( v27 )
              UFG::SceneObjectProperties::SceneObjectProperties(v27, v25, v1);
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
          v30 = UFG::gSceneLayerActivatedChannel.mUID;
          v31 = v28 + 1;
          v31->mNext = v31;
          v31[1].mNext = v31;
          v29->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
          v29->m_EventUID = v30;
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
          v15[2].mNext = (UFG::allocator::free_link *)v1;
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
      v1->mFlags |= 8u;
    }
  }
  else if ( (v13 >> 13) & 1 )
  {
    v14 = v3->mGameProgressionBehaviour;
    if ( v14 )
    {
      if ( v14->vfptr->LayerBelongsToCurrentFlow(v14, v3) )
        UFG::SceneLayer::EnableActivate(v3, 1, 0, 0);
    }
  }
}

// File Line: 1002
// RVA: 0x243700
void __fastcall UFG::Scene::OnSceneLayerResourceUnload(UFG::SceneLayerResource *pSceneLayerResource)
{
  UFG::SceneLayer *v1; // rbx
  UFG::SceneLayerResource *v2; // rdi
  UFG::SceneLayer *v3; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v4; // rcx
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v5; // rax
  UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *v6; // rdx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v7; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v8; // rax
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v9; // rdx
  bool v10; // zf

  v1 = (UFG::SceneLayer *)pSceneLayerResource->mpRuntimeSceneLayer;
  v2 = pSceneLayerResource;
  if ( v1 )
  {
    v3 = unk_1423AA4F8;
    if ( unk_1423AA4F8 == v1 )
      v3 = 0i64;
    unk_1423AA4F8 = v3;
    if ( (v1->mFlags >> 1) & 1 && pSceneLayerResource->mFlags & 8 )
    {
      UFG::IncrementalActivateManager::Deactivate(pSceneLayerResource, 0);
      v2->mFlags &= 0xFFFFFFF7;
    }
    if ( (v1->mFlags >> 14) & 1 )
    {
      if ( v1->mRefCount == 1 )
      {
        UFG::GeographicalLayerManager::GetInstance();
        if ( (v1->mFlags >> 15) & 1 )
        {
          v4 = v1->mPrev;
          v5 = v1->mNext;
          v6 = (UFG::qNode<UFG::SceneLayer,UFG::SceneLayer> *)&v1->mPrev;
          v4->mNext = v5;
          v5->mPrev = v4;
          v6->mNext = v6;
          v6->mPrev = v6;
          v1->mFlags &= 0xFFFF7FFF;
        }
      }
    }
    v7 = v2->mPrev;
    v8 = v2->mNext;
    v9 = (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *)&v2->mPrev;
    v7->mNext = v8;
    v8->mPrev = v7;
    v9->mPrev = v9;
    v9->mNext = v9;
    v2->mpRuntimeSceneLayer = 0i64;
    v10 = v1->mRefCount-- == 1;
    if ( v10 && !((v1->mFlags >> 4) & 1) && !((v1->mFlags >> 21) & 1) )
    {
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::Scene::msDefault,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)v1);
      UFG::SceneLayer::~SceneLayer(v1);
      operator delete[](v1);
    }
  }
}

// File Line: 1097
// RVA: 0x23B9B0
UFG::qBaseTreeRB *__fastcall UFG::Scene::FindLayer(UFG::Scene *this, UFG::qSymbol *name)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *result; // rax

  v2 = name->mUID;
  if ( v2 )
    result = UFG::qBaseTreeRB::Get(&this->mLayers.mTree, v2);
  else
    result = 0i64;
  return result;
}

// File Line: 1104
// RVA: 0x23BC80
UFG::qBaseTreeRB *__fastcall UFG::Scene::FindOrCreateLayer(UFG::Scene *this, UFG::qSymbol *name)
{
  UFG::qSymbol *v2; // rbx
  UFG::Scene *v3; // rdi
  unsigned int v4; // edx
  UFG::qBaseTreeRB *result; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SceneLayer *v7; // rax
  UFG::SceneLayer *v8; // rbx

  v2 = name;
  v3 = this;
  v4 = name->mUID;
  if ( !v4 || (result = UFG::qBaseTreeRB::Get(&this->mLayers.mTree, v4)) == 0i64 )
  {
    v6 = UFG::qMalloc(0x70ui64, "SceneLayer", 0i64);
    if ( v6 )
    {
      UFG::SceneLayer::SceneLayer((UFG::SceneLayer *)v6, v2);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    UFG::SceneLayer::CachePropertySetData(v8);
    UFG::qBaseTreeRB::Add(&v3->mLayers.mTree, &v8->mNode);
    result = (UFG::qBaseTreeRB *)v8;
  }
  return result;
}

// File Line: 1130
// RVA: 0x23B9C0
UFG::qBaseNodeRB *__fastcall UFG::Scene::FindLayerContainingObject(UFG::Scene *this, UFG::qSymbol *objectName, UFG::qPropertySet **ppObjectPropertySet)
{
  UFG::qPropertySet **v3; // r13
  UFG::qSymbol *v4; // rbp
  UFG::Scene *v5; // r12
  UFG::qBaseNodeRB *v6; // r15
  signed __int64 v7; // rdi
  __int64 v8; // rax
  signed __int64 v9; // rsi
  __int64 v10; // rbx
  __int64 v11; // rax
  UFG::qPropertySet *v12; // rcx
  UFG::qPropertySet *v13; // rax

  v3 = ppObjectPropertySet;
  v4 = objectName;
  v5 = this;
  v6 = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
  if ( !v6 )
    return 0i64;
  while ( 1 )
  {
    v7 = (signed __int64)v6[2].mParent[-3].mChild;
    if ( (UFG::qBaseNodeRB *)v7 != &v6[-1] )
      break;
LABEL_12:
    v6 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext(&v5->mLayers.mTree, v6);
    if ( !v6 )
      return 0i64;
  }
  while ( 1 )
  {
    v8 = *(_QWORD *)(v7 + 112);
    if ( v8 )
    {
      v9 = v8 + v7 + 112;
      if ( v9 )
      {
        v10 = 0i64;
        if ( *(_DWORD *)(v7 + 108) )
          break;
      }
    }
LABEL_11:
    v7 = *(_QWORD *)(v7 + 96) - 88i64;
    if ( (UFG::qBaseNodeRB *)v7 == &v6[-1] )
      goto LABEL_12;
  }
  while ( 1 )
  {
    v11 = *(_QWORD *)(v9 + 8 * v10);
    v12 = (UFG::qPropertySet *)(v11 ? v11 + v9 + 8 * v10 : 0i64);
    v13 = UFG::FindObjectPropertySetRecurse(v12, v4);
    if ( v13 )
      break;
    v10 = (unsigned int)(v10 + 1);
    if ( (unsigned int)v10 >= *(_DWORD *)(v7 + 108) )
      goto LABEL_11;
  }
  if ( v3 )
    *v3 = v13;
  return v6;
}

// File Line: 1183
// RVA: 0x2445D0
void __fastcall UFG::Scene::Purge(UFG::Scene *this)
{
  UFG::Scene *v1; // rsi
  UFG::SceneLayer *v2; // rbx
  UFG::qBaseTreeRB *v3; // rdi

  v1 = this;
  v2 = (UFG::SceneLayer *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
  if ( v2 )
  {
    do
    {
      v3 = UFG::qBaseTreeRB::GetNext(&v1->mLayers.mTree, &v2->mNode);
      if ( (v2->mFlags >> 1) & 1 )
        UFG::SceneLayer::EnableActivate(v2, 0, 0, 0);
      if ( (UFG::qBox *)&v2->mLayerResources.mNode.mNext[-6].mNext == &v2[-1].mBox )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)v1,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v2);
        UFG::SceneLayer::~SceneLayer(v2);
        operator delete[](v2);
      }
      v2 = (UFG::SceneLayer *)v3;
    }
    while ( v3 );
  }
}

// File Line: 1205
// RVA: 0x243390
void __fastcall UFG::Scene::OnRestoreCheckpoint(UFG::Scene *this)
{
  UFG::Scene *v1; // rdi
  UFG::SceneLayer *i; // rbx

  v1 = this;
  for ( i = (UFG::SceneLayer *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
        i;
        i = (UFG::SceneLayer *)UFG::qBaseTreeRB::GetNext(&v1->mLayers.mTree, &i->mNode) )
  {
    if ( !((i->mFlags >> 13) & 1) )
    {
      if ( (i->mFlags >> 1) & 1 )
        UFG::SceneLayer::EnableActivate(i, 0, 0, 0);
    }
  }
}

// File Line: 1271
// RVA: 0x239E30
void __fastcall UFG::SceneLayerResource::AddSOP(UFG::SceneLayerResource *this, UFG::SceneObjectProperties *pSOPToAdd)
{
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v2; // rdx
  UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *v3; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v4; // rax

  v2 = (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&pSOPToAdd->mPrev;
  v3 = &this->mObjects;
  v4 = v3->mNode.mPrev;
  v4->mNext = v2;
  v2->mPrev = v4;
  v2->mNext = &v3->mNode;
  v3->mNode.mPrev = v2;
}

