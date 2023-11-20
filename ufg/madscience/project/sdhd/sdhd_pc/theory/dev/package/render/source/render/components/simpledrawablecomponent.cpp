// File Line: 28
// RVA: 0x1452490
__int64 dynamic_initializer_for__Render::SimpleDrawableComponent::s_SimpleDrawableComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__Render::SimpleDrawableComponent::s_SimpleDrawableComponentList__);
}

// File Line: 29
// RVA: 0x1A00
const char *__fastcall Render::SimpleDrawableComponent::GetTypeName(Render::SimpleDrawableComponent *this)
{
  return "SimpleDrawableComponent";
}

// File Line: 36
// RVA: 0x1100
void __fastcall Render::SimpleDrawableComponent::SimpleDrawableComponent(Render::SimpleDrawableComponent *this, unsigned __int64 model_data_uid)
{
  unsigned __int64 v2; // rbp
  Render::SimpleDrawableComponent *v3; // r15
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v4; // rdi
  __int64 *v5; // r14
  UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData> *v6; // rcx
  const char *v7; // rax
  unsigned __int64 v8; // rax
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v9; // rax
  UFG::qReflectObject *v10; // rdi
  unsigned int v11; // ebx
  char *v12; // rax
  signed __int64 v13; // rcx
  __int64 v14; // rcx
  UFG::qList<Render::Decal,Render::Decal,0,0> *v15; // [rsp+70h] [rbp+18h]

  v2 = model_data_uid;
  v3 = this;
  this->vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable';
  v15 = &this->mAttachedDecals;
  v15->mNode.mPrev = &v15->mNode;
  v15->mNode.mNext = &v15->mNode;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v4 = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (Render::IDecalSceneryVtbl *)&Render::SimpleDrawableComponent::`vftable'{for `Render::IDecalScenery'};
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::SimpleDrawableComponent::`vftable'{for `UFG::SimComponent'};
  v5 = (__int64 *)&v3->mModelWrappers;
  *v5 = (__int64)v5;
  v5[1] = (__int64)v5;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v3->mModelDataHandle.mPrev);
  v7 = UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData>::GetTypeName(v6);
  v8 = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)&v3->mModelDataHandle.mPrev, v8, v2);
  v9 = Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev;
  Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev->mNext = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)&v3->mPrev;
  v4->mPrev = v9;
  v3->mNext = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList;
  Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    Render::SimpleDrawableComponent::_SimpleDrawableComponentTypeUID,
    "SimpleDrawableComponent");
  v3->mCullInfo = 0i64;
  v3->mOcclusionCullInfo = 0i64;
  v3->mCullResults = 0i64;
  *((_DWORD *)v3 + 30) &= 0xFFFFFFFE;
  *((_DWORD *)v3 + 30) |= 4u;
  v3->mSceneryInstance.ColourTint[0] = UFG::qColour::White.r;
  v3->mSceneryInstance.ColourTint[1] = UFG::qColour::White.g;
  v3->mSceneryInstance.ColourTint[2] = UFG::qColour::White.b;
  v3->mSceneryInstance.ColourTint[3] = UFG::qColour::White.a;
  v3->mSceneryInstance.SIColourTint[0] = UFG::qColour::White.r;
  v3->mSceneryInstance.SIColourTint[1] = UFG::qColour::White.g;
  v3->mSceneryInstance.SIColourTint[2] = UFG::qColour::White.b;
  v3->mSceneryInstance.SIColourTint[3] = UFG::qColour::White.a;
  v10 = v3->mModelDataHandle.mData;
  v11 = 0;
  if ( LODWORD(v10[1].mBaseNode.mUID) )
  {
    do
    {
      v12 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
      if ( v12 )
      {
        v13 = (signed __int64)&v10[1].vfptr[7 * v11];
        *(_QWORD *)v12 = v12;
        *((_QWORD *)v12 + 1) = v12;
        *((_QWORD *)v12 + 2) = v13;
        *((_WORD *)v12 + 12) = 1;
      }
      else
      {
        v12 = 0i64;
      }
      v14 = *v5;
      *(_QWORD *)(v14 + 8) = v12;
      *(_QWORD *)v12 = v14;
      *((_QWORD *)v12 + 1) = v5;
      *v5 = (__int64)v12;
      ++v11;
    }
    while ( v11 < LODWORD(v10[1].mBaseNode.mUID) );
  }
  if ( Render::SimpleDrawableComponent::mDefaultCullLayer )
    Render::SimpleDrawableComponent::SetLayer(v3, Render::SimpleDrawableComponent::mDefaultCullLayer);
}

// File Line: 64
// RVA: 0x1300
void __fastcall Render::SimpleDrawableComponent::SimpleDrawableComponent(Render::SimpleDrawableComponent *this, unsigned __int64 model_data_uid, UFG::qArray<unsigned long,0> *nameUidFilter)
{
  UFG::qArray<unsigned long,0> *v3; // r15
  unsigned __int64 v4; // rbp
  Render::SimpleDrawableComponent *v5; // r12
  UFG::qList<Render::Decal,Render::Decal,0,0> *v6; // rax
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v7; // rdi
  UFG::qList<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper,1,0> *v8; // r14
  UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData> *v9; // rcx
  const char *v10; // rax
  unsigned __int64 v11; // rax
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v12; // rax
  UFG::qReflectObject *v13; // rsi
  unsigned int v14; // edi
  signed __int64 v15; // rbx
  UFG::qReflectObjectVtbl *v16; // rax
  const char *v17; // rcx
  int v18; // eax
  int v19; // ecx
  char *v20; // rax
  char *v21; // r8
  signed __int64 v22; // rdx
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *v23; // rax

  v3 = nameUidFilter;
  v4 = model_data_uid;
  v5 = this;
  this->vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable';
  v6 = &this->mAttachedDecals;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v7 = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)&v5->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  v5->vfptr = (Render::IDecalSceneryVtbl *)&Render::SimpleDrawableComponent::`vftable'{for `Render::IDecalScenery'};
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::SimpleDrawableComponent::`vftable'{for `UFG::SimComponent'};
  v8 = &v5->mModelWrappers;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v5->mModelDataHandle.mPrev);
  v10 = UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData>::GetTypeName(v9);
  v11 = UFG::qStringHash64(v10, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)&v5->mModelDataHandle.mPrev, v11, v4);
  v12 = Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev;
  Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev->mNext = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)&v5->mPrev;
  v7->mPrev = v12;
  v5->mNext = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList;
  Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mPrev = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    Render::SimpleDrawableComponent::_SimpleDrawableComponentTypeUID,
    "SimpleDrawableComponent");
  v5->mCullInfo = 0i64;
  v5->mOcclusionCullInfo = 0i64;
  v5->mCullResults = 0i64;
  *((_DWORD *)v5 + 30) &= 0xFFFFFFFE;
  *((_DWORD *)v5 + 30) |= 4u;
  v5->mSceneryInstance.ColourTint[0] = UFG::qColour::White.r;
  v5->mSceneryInstance.ColourTint[1] = UFG::qColour::White.g;
  v5->mSceneryInstance.ColourTint[2] = UFG::qColour::White.b;
  v5->mSceneryInstance.ColourTint[3] = UFG::qColour::White.a;
  v5->mSceneryInstance.SIColourTint[0] = UFG::qColour::White.r;
  v5->mSceneryInstance.SIColourTint[1] = UFG::qColour::White.g;
  v5->mSceneryInstance.SIColourTint[2] = UFG::qColour::White.b;
  v5->mSceneryInstance.SIColourTint[3] = UFG::qColour::White.a;
  v13 = v5->mModelDataHandle.mData;
  v14 = 0;
  if ( LODWORD(v13[1].mBaseNode.mUID) )
  {
    do
    {
      v15 = 7i64 * v14;
      v16 = v13[1].vfptr;
      if ( LODWORD(v16[v15].GetTypeName) )
        v17 = (const char *)v16[v15].__vecDelDtor;
      else
        v17 = &customWorldMapCaption;
      v18 = UFG::qStringHashUpper32(v17, 0xFFFFFFFF);
      v19 = 0;
      if ( v3->size )
      {
        while ( v18 != v3->p[v19] )
        {
          if ( ++v19 >= v3->size )
            goto LABEL_13;
        }
        v20 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
        v21 = v20;
        if ( v20 )
        {
          v22 = (signed __int64)&v13[1].vfptr[v15];
          *(_QWORD *)v20 = v20;
          *((_QWORD *)v20 + 1) = v20;
          *((_QWORD *)v20 + 2) = v22;
          *((_WORD *)v20 + 12) = 1;
        }
        else
        {
          v21 = 0i64;
        }
        v23 = v8->mNode.mPrev;
        v23->mNext = (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)v21;
        *(_QWORD *)v21 = v23;
        *((_QWORD *)v21 + 1) = v8;
        v8->mNode.mPrev = (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)v21;
      }
LABEL_13:
      ++v14;
    }
    while ( v14 < LODWORD(v13[1].mBaseNode.mUID) );
  }
  if ( Render::SimpleDrawableComponent::mDefaultCullLayer )
    Render::SimpleDrawableComponent::SetLayer(v5, Render::SimpleDrawableComponent::mDefaultCullLayer);
}

// File Line: 100
// RVA: 0x15F0
void __fastcall Render::SimpleDrawableComponent::~SimpleDrawableComponent(Render::SimpleDrawableComponent *this)
{
  Render::SimpleDrawableComponent *v1; // rsi
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v2; // rdi
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v3; // rcx
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v4; // rax
  CullManager *v5; // rax
  CullManager *v6; // rax
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *v7; // rdx
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *v8; // rax
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v9; // rdx
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v10; // rax

  v1 = this;
  this->vfptr = (Render::IDecalSceneryVtbl *)&Render::SimpleDrawableComponent::`vftable'{for `Render::IDecalScenery'};
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&Render::SimpleDrawableComponent::`vftable'{for `UFG::SimComponent'};
  if ( this == Render::SimpleDrawableComponent::s_SimpleDrawableComponentpCurrentIterator )
    Render::SimpleDrawableComponent::s_SimpleDrawableComponentpCurrentIterator = (Render::SimpleDrawableComponent *)&this->mPrev[-6].mNext;
  v2 = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  Render::IDecalScenery::RemoveAttachedDecals((Render::IDecalScenery *)&v1->vfptr, 0xFFFFFFFF);
  v5 = CullManager::Instance();
  CullManager::FreePersistentCullInfo(v5, v1->mCullResults, v1->mCullInfo);
  v6 = CullManager::Instance();
  CullManager::FreePersistentOcclusionInfo(v6, v1->mOcclusionCullInfo);
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mModelDataHandle.mPrev);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->mModelWrappers);
  v7 = v1->mModelWrappers.mNode.mPrev;
  v8 = v1->mModelWrappers.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mModelWrappers.mNode.mPrev = &v1->mModelWrappers.mNode;
  v1->mModelWrappers.mNode.mNext = &v1->mModelWrappers.mNode;
  v9 = v2->mPrev;
  v10 = v2->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
  Render::IDecalScenery::~IDecalScenery((Render::IDecalScenery *)&v1->vfptr);
}

// File Line: 110
// RVA: 0x1A70
void __fastcall Render::SimpleDrawableComponent::SetLayer(Render::SimpleDrawableComponent *this, CullLayer *cull_layer)
{
  CullInfo *v2; // rbx
  CullLayer *v3; // rdi
  Render::SimpleDrawableComponent *cull_info_param0; // rsi
  CullManager *v5; // rax
  CullManager *v6; // rax
  Render::SimpleDrawableComponent *v7; // rbx
  int v8; // ecx
  CullManager *v9; // rax
  CullManager *v10; // rax

  v2 = this->mCullInfo;
  v3 = cull_layer;
  cull_info_param0 = this;
  if ( v2 )
  {
    if ( v2->mCullLayer == cull_layer )
      return;
    v5 = CullManager::Instance();
    CullManager::FreePersistentCullInfo(v5, 0i64, v2);
  }
  v6 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(
    v6,
    &cull_info_param0->mCullResults,
    &cull_info_param0->mCullInfo,
    v3,
    cull_info_param0,
    cull_info_param0);
  v7 = (Render::SimpleDrawableComponent *)cull_info_param0->mModelWrappers.mNode.mNext;
  if ( v7 != (Render::SimpleDrawableComponent *)&cull_info_param0->mModelWrappers )
  {
    while ( 1 )
    {
      v8 = (int)v7->mAttachedDecals.mNode.mNext[2].mPrev;
      if ( v8 == 5 || v8 == 6 )
        break;
      if ( v8 == 4 )
      {
        v9 = CullManager::Instance();
        CullManager::AllocPersistentOcclusionInfo(v9, &cull_info_param0->mOcclusionCullInfo, 0i64);
        goto LABEL_12;
      }
      v7 = (Render::SimpleDrawableComponent *)v7->mAttachedDecals.mNode.mPrev;
      if ( v7 == (Render::SimpleDrawableComponent *)&cull_info_param0->mModelWrappers )
        goto LABEL_12;
    }
    v10 = CullManager::Instance();
    CullManager::AllocPersistentOcclusionInfo(v10, &cull_info_param0->mOcclusionCullInfo, 0i64);
    cull_info_param0->mOcclusionCullInfo->mParam1 = (void *)((_QWORD)v7->mAttachedDecals.mNode.mNext | (LODWORD(v7->mAttachedDecals.mNode.mNext[2].mPrev) == 6));
  }
LABEL_12:
  *((_DWORD *)cull_info_param0 + 30) |= 4u;
}

// File Line: 151
// RVA: 0x1EA0
void __fastcall Render::SimpleDrawableComponent::UpdateCullInfo(Render::SimpleDrawableComponent *this)
{
  Render::SimpleDrawableComponent *v1; // rbx
  UFG::qReflectObject *v2; // rax
  UFG::qReflectObject *v3; // rax
  _DWORD *v4; // rcx
  int v5; // xmm0_4
  int v6; // xmm1_4
  UFG::qReflectObject *v7; // rax
  _DWORD *v8; // rcx
  int v9; // xmm0_4
  int v10; // xmm1_4
  UFG::SimObject *v11; // rax
  UFG::qMatrix44 *v12; // rdi
  UFG::qMatrix44 *v13; // rcx
  CullInfoFull *v14; // rdx
  UFG::qReflectObject *v15; // rax
  _DWORD *v16; // rcx
  int v17; // xmm0_4
  int v18; // xmm1_4
  UFG::qReflectObject *v19; // rax
  _DWORD *v20; // rcx
  int v21; // xmm0_4
  int v22; // xmm1_4

  v1 = this;
  if ( this->mCullInfo )
  {
    v2 = this->mModelDataHandle.mData;
    if ( v2 )
    {
      this->mCullInfo->mViewsCulled = Illusion::eCastShadow::GetCastShadowViewsCulled(SHIDWORD(v2[1].mBaseNode.mNeighbours[0]));
      if ( *((_BYTE *)v1 + 120) & 4 )
      {
        v3 = v1->mModelDataHandle.mData;
        v4 = (_DWORD *)v1->mCullInfo->mAABBMin;
        v5 = HIDWORD(v3[1].mBaseNode.mParent);
        v6 = (int)v3[1].mBaseNode.mChildren[0];
        *v4 = v3[1].mBaseNode.mParent;
        v4[1] = v5;
        v4[2] = v6;
        v7 = v1->mModelDataHandle.mData;
        v8 = (_DWORD *)v1->mCullInfo->mAABBMin;
        v9 = HIDWORD(v7[1].mBaseNode.mChildren[1]);
        v10 = (int)v7[1].mBaseNode.mNeighbours[0];
        v8[4] = v7[1].mBaseNode.mChildren[1];
        v8[5] = v9;
        v8[6] = v10;
        v11 = v1->m_pSimObject;
        v12 = (UFG::qMatrix44 *)v11->m_pTransformNodeComponent;
        if ( v12 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v11->m_pTransformNodeComponent);
          v13 = v12 + 2;
        }
        else
        {
          v13 = &UFG::qMatrix44::msIdentity;
        }
        v1->mCullInfo->mpLocalWorld = &v13->v0.x;
        v14 = v1->mOcclusionCullInfo;
        if ( v14 )
        {
          v14->mpLocalWorld = v1->mCullInfo->mpLocalWorld;
          v15 = v1->mModelDataHandle.mData;
          v16 = (_DWORD *)v1->mOcclusionCullInfo->mAABBMin;
          v17 = HIDWORD(v15[1].mBaseNode.mParent);
          v18 = (int)v15[1].mBaseNode.mChildren[0];
          *v16 = v15[1].mBaseNode.mParent;
          v16[1] = v17;
          v16[2] = v18;
          v19 = v1->mModelDataHandle.mData;
          v20 = (_DWORD *)v1->mOcclusionCullInfo->mAABBMin;
          v21 = HIDWORD(v19[1].mBaseNode.mChildren[1]);
          v22 = (int)v19[1].mBaseNode.mNeighbours[0];
          v20[4] = v19[1].mBaseNode.mChildren[1];
          v20[5] = v21;
          v20[6] = v22;
        }
        *((_DWORD *)v1 + 30) &= 0xFFFFFFFB;
      }
    }
  }
}

// File Line: 188
// RVA: 0x1810
void __fastcall Render::SimpleDrawableComponent::Draw(Render::SimpleDrawableComponent *this, Render::View *view)
{
  Render::View *v2; // rbp
  Render::SimpleDrawableComponent *v3; // rdi
  char *v4; // rax
  char *v5; // rbx
  Illusion::StateValues *v6; // rax
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *i; // rbx
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *v8; // rdx
  UFG::qMatrix44 *v9; // r8

  v2 = view;
  v3 = this;
  if ( (this->m_Flags & 3) == 1 )
  {
    v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
    *(float *)v4 = v3->mSceneryInstance.ColourTint[0];
    v5 = v4;
    *((_DWORD *)v4 + 1) = LODWORD(v3->mSceneryInstance.ColourTint[1]);
    *((_DWORD *)v4 + 2) = LODWORD(v3->mSceneryInstance.ColourTint[2]);
    *((_DWORD *)v4 + 3) = LODWORD(v3->mSceneryInstance.ColourTint[3]);
    *((_DWORD *)v4 + 4) = LODWORD(v3->mSceneryInstance.SIColourTint[0]);
    *((_DWORD *)v4 + 5) = LODWORD(v3->mSceneryInstance.SIColourTint[1]);
    *((_DWORD *)v4 + 6) = LODWORD(v3->mSceneryInstance.SIColourTint[2]);
    *((_DWORD *)v4 + 7) = LODWORD(v3->mSceneryInstance.SIColourTint[3]);
    *((_DWORD *)v4 + 8) = LODWORD(v3->mSceneryInstance.Mask[0]);
    *((_DWORD *)v4 + 9) = LODWORD(v3->mSceneryInstance.Mask[1]);
    *((_DWORD *)v4 + 10) = LODWORD(v3->mSceneryInstance.Mask[2]);
    *((_DWORD *)v4 + 11) = LODWORD(v3->mSceneryInstance.Mask[3]);
    *((_DWORD *)v4 + 12) = LODWORD(v3->mSceneryInstance.Value0[0]);
    *((_DWORD *)v4 + 13) = LODWORD(v3->mSceneryInstance.Value0[1]);
    *((_DWORD *)v4 + 14) = LODWORD(v3->mSceneryInstance.Value0[2]);
    *((_DWORD *)v4 + 15) = LODWORD(v3->mSceneryInstance.Value0[3]);
    v6 = Render::View::GetStateValues(v2);
    v6->mSetValueMask.mFlags[0] |= 0x400000000ui64;
    v6->mParamValues[34] = v5;
    for ( i = v3->mModelWrappers.mNode.mNext;
          i != (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)&v3->mModelWrappers;
          i = i->mNext )
    {
      if ( LOWORD(i[1].mNext) )
      {
        v8 = i[1].mPrev;
        if ( !LODWORD(v8[2].mPrev) )
        {
          v9 = &UFG::qMatrix44::msIdentity;
          if ( v3->mCullInfo->mpLocalWorld )
            v9 = (UFG::qMatrix44 *)v3->mCullInfo->mpLocalWorld;
          Render::View::Draw(v2, (Illusion::rModel *)v8, v9, 0);
        }
      }
    }
  }
}

// File Line: 226
// RVA: 0x1B80
void __fastcall Render::SimpleDrawableComponent::SetVisibility(Render::SimpleDrawableComponent *this, unsigned int modelGuid, bool visible)
{
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *v3; // rbx
  UFG::qList<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper,1,0> *v4; // rdi
  bool v5; // bp
  unsigned int v6; // esi
  UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *v7; // rax
  const char *v8; // rcx

  v3 = this->mModelWrappers.mNode.mNext;
  v4 = &this->mModelWrappers;
  v5 = visible;
  v6 = modelGuid;
  if ( v3 != (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)&this->mModelWrappers )
  {
    while ( 1 )
    {
      v7 = v3[1].mPrev;
      v8 = (const char *)(LODWORD(v7->mNext) ? v7->mPrev : &customWorldMapCaption);
      if ( (unsigned int)UFG::qStringHashUpper32(v8, 0xFFFFFFFF) == v6 )
        break;
      v3 = v3->mNext;
      if ( v3 == (UFG::qNode<Render::SimpleDrawableComponent::ModelWrapper,Render::SimpleDrawableComponent::ModelWrapper> *)v4 )
        return;
    }
    LOWORD(v3[1].mNext) = v5;
  }
}

// File Line: 248
// RVA: 0x19B0
char __fastcall Render::SimpleDrawableComponent::GetTransform(Render::SimpleDrawableComponent *this, Render::Decal *decal, UFG::qMatrix44 *mat)
{
  char result; // al
  float *v4; // rcx
  UFG::qMatrix44 *v5; // rax
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1

  if ( *((_BYTE *)this + 120) & 1 )
    return 0;
  v4 = this->mCullInfo->mpLocalWorld;
  v5 = &UFG::qMatrix44::msIdentity;
  if ( v4 )
    v5 = (UFG::qMatrix44 *)v4;
  v6 = v5->v1;
  v7 = v5->v2;
  v8 = v5->v3;
  mat->v0 = v5->v0;
  mat->v1 = v6;
  result = 1;
  mat->v2 = v7;
  mat->v3 = v8;
  return result;
}

// File Line: 258
// RVA: 0x1C10
void __fastcall Render::TestSimpleDrawableForDecals(Render::DecalClipRequest *request, UFG::qBox *projBox)
{
  UFG::qBox *v2; // rbp
  UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *v3; // rdi
  Render::DecalClipRequest *v4; // r13
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v5; // rsi
  UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *v6; // r14
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v7; // rax
  const char *v8; // rcx
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v9; // r15
  UFG::qMatrix44 *v10; // rcx
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  unsigned int v15; // edx
  signed __int64 v16; // rbx
  unsigned int v17; // eax
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v18; // r8
  UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *v19; // rcx
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v22; // rdx
  UFG::qMatrix44 *v23; // rcx
  UFG::qVector4 v24; // xmm3
  UFG::qVector4 v25; // xmm2
  UFG::qVector4 v26; // xmm1
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qVector3 min; // [rsp+20h] [rbp-48h]
  UFG::qVector3 max; // [rsp+30h] [rbp-38h]

  v2 = projBox;
  v3 = (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mNext[-6].mNext;
  v4 = request;
  if ( &Render::SimpleDrawableComponent::s_SimpleDrawableComponentList.mNode.mNext[-6].mNext != (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> **)((char *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList - 88) )
  {
    do
    {
      v5 = v3[11].mNode.mNext;
      v6 = (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)&v3[6].mNode.mPrev[-6].mNext;
      if ( v5 && !((_QWORD)v3[7].mNode.mNext & 1) )
      {
        v7 = v5[5].mPrev;
        if ( LODWORD(v7->mNext) )
          v8 = (const char *)v7->mPrev;
        else
          v8 = &customWorldMapCaption;
        UFG::qStringFindInsensitive(v8, "Cube");
        v9 = v3[8].mNode.mPrev;
        v10 = &UFG::qMatrix44::msIdentity;
        v11 = *((float *)&v9->mPrev + 1);
        v12 = *(float *)&v9->mNext;
        min.x = *(float *)&v9->mPrev;
        min.y = v11;
        min.z = v12;
        v13 = *((float *)&v9[1].mPrev + 1);
        v14 = *(float *)&v9[1].mNext;
        max.x = *(float *)&v9[1].mPrev;
        max.y = v13;
        max.z = v14;
        if ( v9[3].mNext )
          v10 = (UFG::qMatrix44 *)v9[3].mNext;
        TransformAABB(v10, &min, &max);
        if ( min.x <= v2->mMax.x
          && max.x >= v2->mMin.x
          && min.y <= v2->mMax.y
          && max.y >= v2->mMin.y
          && min.z <= v2->mMax.z
          && max.z >= v2->mMin.z )
        {
          v15 = (unsigned int)v5[5].mNext;
          v16 = 0i64;
          v17 = 0;
          if ( v15 )
          {
            v18 = v5[5].mPrev;
            v19 = v18 + 2;
            while ( LODWORD(v19->mPrev) )
            {
              ++v17;
              v19 += 7;
              if ( v17 >= v15 )
                goto LABEL_21;
            }
            v16 = (signed __int64)&v18[7 * v17];
          }
LABEL_21:
          v20 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
          if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
          {
            v21 = UFG::qResourceWarehouse::Instance();
            v20 = UFG::qResourceWarehouse::GetInventory(v21, 0xA2ADCD77);
            `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v20;
          }
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mModelProxy.mModelHandle.mPrev, 0xA2ADCD77, 0, v20);
          v4->mModelProxy.mRModel = (Illusion::rModel *)v16;
          v22 = &v4->mComponentPtr;
          v23 = &UFG::qMatrix44::msIdentity;
          if ( v9[3].mNext )
            v23 = (UFG::qMatrix44 *)v9[3].mNext;
          v24 = v23->v1;
          v25 = v23->v2;
          v26 = v23->v3;
          v4->mLocalToWorld.v0 = v23->v0;
          v4->mLocalToWorld.v1 = v24;
          v4->mLocalToWorld.v2 = v25;
          v4->mLocalToWorld.v3 = v26;
          if ( v4->mComponentPtr.m_pPointer )
          {
            v27 = v22->mPrev;
            v28 = v4->mComponentPtr.mNext;
            v27->mNext = v28;
            v28->mPrev = v27;
            v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
            v4->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mComponentPtr.mPrev;
          }
          v4->mComponentPtr.m_pPointer = (UFG::SimComponent *)&v3[1].mNode.mNext;
          if ( v3 != (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)-24i64 )
          {
            v29 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v3[2].mNode.mPrev;
            v29->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
            v22->mPrev = v29;
            v4->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3[2];
            v3[2].mNode.mPrev = (UFG::qNode<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent> *)v22;
          }
          v4->mScenery = (Render::IDecalScenery *)v3;
          Render::DecalManager::AddClipQueue(&Render::gDecalManager, v4);
        }
      }
      v3 = v6;
    }
    while ( v6 != (UFG::qList<Render::SimpleDrawableComponent,Render::SimpleDrawableComponent,1,0> *)((char *)&Render::SimpleDrawableComponent::s_SimpleDrawableComponentList - 88) );
  }
}

