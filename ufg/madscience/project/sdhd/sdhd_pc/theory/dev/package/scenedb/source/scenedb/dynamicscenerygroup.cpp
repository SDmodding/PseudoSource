// File Line: 37
// RVA: 0x1470090
__int64 dynamic_initializer_for__UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList__);
}

// File Line: 38
// RVA: 0x232690
UFG::ComponentIDDesc *__fastcall UFG::DynamicSceneryInstance::GetDesc(UFG::DynamicSceneryInstance *this)
{
  return &UFG::DynamicSceneryInstance::_TypeIDesc;
}

// File Line: 42
// RVA: 0x22F3D0
void __fastcall UFG::DynamicSceneryInstance::DynamicSceneryInstance(UFG::DynamicSceneryInstance *this, unsigned int instance_name_uid, unsigned int model_name_uid, unsigned int tag_uid)
{
  unsigned int v4; // ebp
  unsigned int v5; // er12
  unsigned int v6; // esi
  UFG::DynamicSceneryInstance *v7; // r14
  UFG::qList<Render::Decal,Render::Decal,0,0> *v8; // rax
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v9; // rbx
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v10; // rax
  signed int v11; // ecx
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  signed __int64 v14; // rsi
  __m128 v15; // xmm3
  CullManager *v16; // rax
  CullInfo *v17; // rax
  float v18; // xmm1_4
  float v19; // xmm2_4
  CullInfo *v20; // rax
  float v21; // xmm1_4
  float v22; // xmm2_4

  v4 = tag_uid;
  v5 = model_name_uid;
  v6 = instance_name_uid;
  v7 = this;
  this->vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable;
  v8 = &this->mAttachedDecals;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, instance_name_uid);
  v9 = (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *)&v7->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  v7->vfptr = (Render::IDecalSceneryVtbl *)&UFG::DynamicSceneryInstance::`vftable{for `Render::IDecalScenery};
  v7->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DynamicSceneryInstance::`vftable{for `UFG::SimComponent};
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v7->mModelHandle.mPrev);
  v10 = UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mPrev;
  UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mPrev->mNext = (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *)&v7->mPrev;
  v9->mPrev = v10;
  v7->mNext = (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList;
  UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mPrev = (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *)&v7->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v7->vfptr,
    UFG::DynamicSceneryInstance::_DynamicSceneryInstanceTypeUID,
    "DynamicSceneryInstance");
  v7->mNameUID = v6;
  v7->mTagUID = v4;
  v7->mHidden = 0;
  v7->mSelfIlluminationOverride = 1.0;
  v7->mForceTransparencyState = -1;
  v11 = Illusion::gEngine.mFrameCount;
  if ( Render::TransparencySystem::msEnabled )
    v7->mTransparencyState[0] = 0;
  else
    v7->mTransparencyState[0] = Render::TransparencySystem::msOpaqueIndex;
  v7->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex;
  v7->mTransparencyState[2] = v11 + v11 / 255;
  v12 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v12;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v7->mModelHandle.mPrev, 0xA2ADCD77, v5, v12);
  v14 = (signed __int64)&v7->mLocalWorld;
  v15 = 0i64;
  v15.m128_f32[0] = (float)1;
  *(__m128 *)v14 = v15;
  *(__m128 *)(v14 + 16) = _mm_shuffle_ps(v15, v15, 81);
  *(__m128 *)(v14 + 32) = _mm_shuffle_ps(v15, v15, 69);
  *(__m128 *)(v14 + 48) = _mm_shuffle_ps(v15, v15, 21);
  v16 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(v16, &v7->mCullResults, &v7->mCullInfo, 0i64, 0i64, 0i64);
  v7->mCullInfo->mpLocalWorld = &v7->mLocalWorld.v0.x;
  v17 = v7->mCullInfo;
  v18 = UFG::qVector3::msZero.y;
  v19 = UFG::qVector3::msZero.z;
  v17->mAABBMin[0] = UFG::qVector3::msZero.x;
  v17->mAABBMin[1] = v18;
  v17->mAABBMin[2] = v19;
  v20 = v7->mCullInfo;
  v21 = UFG::qVector3::msZero.y;
  v22 = UFG::qVector3::msZero.z;
  v20->mAABBMax[0] = UFG::qVector3::msZero.x;
  v20->mAABBMax[1] = v21;
  v20->mAABBMax[2] = v22;
}

// File Line: 71
// RVA: 0x22FA80
void __fastcall UFG::DynamicSceneryInstance::~DynamicSceneryInstance(UFG::DynamicSceneryInstance *this)
{
  UFG::DynamicSceneryInstance *v1; // rbx
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v2; // rdi
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v3; // rcx
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v4; // rax
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  CullManager *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v10; // rdx
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v11; // rax

  v1 = this;
  this->vfptr = (Render::IDecalSceneryVtbl *)&UFG::DynamicSceneryInstance::`vftable{for `Render::IDecalScenery};
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DynamicSceneryInstance::`vftable{for `UFG::SimComponent};
  if ( this == UFG::DynamicSceneryInstance::s_DynamicSceneryInstancepCurrentIterator )
    UFG::DynamicSceneryInstance::s_DynamicSceneryInstancepCurrentIterator = (UFG::DynamicSceneryInstance *)&this->mPrev[-6].mNext;
  v2 = (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v5;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mModelHandle.mPrev, v5);
  Render::IDecalScenery::RemoveAttachedDecals((Render::IDecalScenery *)&v1->vfptr, 0xFFFFFFFF);
  v7 = CullManager::Instance();
  CullManager::FreePersistentCullInfo(v7, v1->mCullResults, v1->mCullInfo);
  v8 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v8;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mModelHandle.mPrev, v8);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mModelHandle.mPrev);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
  Render::IDecalScenery::~IDecalScenery((Render::IDecalScenery *)&v1->vfptr);
}

// File Line: 101
// RVA: 0x2318F0
void __fastcall UFG::DynamicSceneryInstance::ForceFadeOut(UFG::DynamicSceneryInstance *this)
{
  this->mForceTransparencyState = 0;
}

// File Line: 106
// RVA: 0x2330C0
_BOOL8 __fastcall UFG::DynamicSceneryInstance::HasFadedOut(UFG::DynamicSceneryInstance *this)
{
  return this->mTransparencyState[0] == 0;
}

// File Line: 111
// RVA: 0x231900
void __fastcall UFG::DynamicSceneryInstance::ForceVisible(UFG::DynamicSceneryInstance *this)
{
  signed int v1; // er8

  v1 = Illusion::gEngine.mFrameCount;
  this->mTransparencyState[0] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[2] = v1 + v1 / 255;
  this->mForceTransparencyState = Render::TransparencySystem::msOpaqueIndex;
}

// File Line: 117
// RVA: 0x230FE0
void __fastcall UFG::DynamicSceneryInstance::Draw(UFG::DynamicSceneryInstance *this, Render::View *view)
{
  Render::View *v2; // rsi
  UFG::DynamicSceneryInstance *v3; // rdi
  CullResults *v4; // rdx
  __int64 v5; // rcx
  unsigned __int64 v6; // r8
  BOOL v7; // ebp
  BOOL v8; // eax
  int *v9; // rcx
  CullResults *v10; // rax
  bool v11; // cf
  signed int v12; // er11
  __int16 v13; // ax
  int v14; // er10
  int v15; // er9
  int v16; // ebx
  int v17; // eax
  Render::ViewSettings *v18; // rdx
  int v19; // xmm0_4
  int v20; // xmm0_4
  Illusion::SubmitContext *v21; // rax
  UFG::qResourceData *v22; // rax
  int v23; // xmm1_4
  int v24; // xmm2_4
  int v25; // xmm1_4
  int v26; // xmm2_4
  AMD_HD3D *v27; // rax
  CullResults *v28; // r8
  void *v29; // rax
  void *v30; // rbx
  Illusion::StateValues *v31; // rax
  int v32; // [rsp+40h] [rbp-38h]
  int v33; // [rsp+44h] [rbp-34h]
  int v34; // [rsp+48h] [rbp-30h]
  int v35; // [rsp+4Ch] [rbp-2Ch]
  int v36; // [rsp+50h] [rbp-28h]
  int v37; // [rsp+54h] [rbp-24h]
  float distance_from_near_plane; // [rsp+90h] [rbp+18h]
  int v39; // [rsp+98h] [rbp+20h]
  int v40; // [rsp+9Ch] [rbp+24h]

  v2 = view;
  v3 = this;
  if ( !gDrawScenery || this->mHidden || !this->mModelHandle.mData )
    return;
  v4 = this->mCullResults;
  if ( v4 && (v5 = v2->mSettings->mCullIndex, (_DWORD)v5 != -1) )
  {
    v6 = 0i64;
    v7 = 0;
    if ( (signed int)v5 >= 0 )
      LOBYTE(v7) = v4->mViewResult[v5] > 1u;
  }
  else
  {
    v8 = Render::View::IsInView(v2, &v3->mModelHandle, &v3->mLocalWorld, &distance_from_near_plane);
    v6 = 0i64;
    v7 = v8 == 0;
  }
  v9 = 0i64;
  if ( v2->mSettings->mCullIndex )
    goto LABEL_35;
  v10 = v3->mCullResults;
  if ( v10 )
  {
    v11 = (float)(v2->mSettings->mCullPixelDensityThreshold * 1.0700001) < v10->mPixelCoverage[0];
    v12 = Render::TransparencySystem::msOpaqueIndex;
    v13 = v3->mForceTransparencyState;
    v14 = Render::TransparencySystem::msOpaqueIndex;
    if ( !v11 )
      v14 = 0;
    if ( v13 != -1 )
      v14 = v13;
    v15 = (unsigned __int8)v3->mTransparencyState[0];
    v16 = (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
    v17 = (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255
        - ((unsigned __int8)v3->mTransparencyState[2] + 1) % 255;
    if ( v17 < 0 )
      v17 = ((unsigned __int8)v3->mTransparencyState[2] + 1) % 255
          - (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
    if ( v17 <= 0 )
    {
      if ( v15 >= v14 )
      {
        if ( v15 > v14 )
          --v15;
      }
      else
      {
        ++v15;
      }
    }
    else
    {
      v15 = v14;
    }
    v3->mTransparencyState[1] = v14;
    v3->mTransparencyState[2] = v16;
    if ( v15 > 0 )
      LODWORD(v6) = v15;
    if ( (signed int)v6 < v12 )
      LOBYTE(v12) = v6;
    v3->mTransparencyState[0] = v12;
    if ( (_BYTE)v12 )
    {
      v18 = v2->mSettings;
      v6 = *(_QWORD *)v3->mTransparencyState;
      if ( v2->mSettings->mCullIndex >= 6 )
        v19 = 0;
      else
        v19 = LODWORD(v3->mCullResults->mDistance[v2->mSettings->mCullIndex]);
      v39 = v19;
      if ( v18->mCullIndex >= 6 )
        v20 = (signed int)FLOAT_1_0;
      else
        v20 = LODWORD(v3->mCullResults->mPixelCoverage[v18->mCullIndex]);
      v40 = v20;
      v9 = &v39;
LABEL_35:
      v21 = v2->mSubmitContext;
      v21[1].vfptr = (Illusion::SubmitContextVtbl *)v9;
      v21[1].mStateValues.mSetValueMask.mFlags[0] = v6;
      if ( gDrawDynamicCullResults && !v2->mSettings->mCullIndex )
      {
        v22 = v3->mModelHandle.mData;
        v23 = HIDWORD(v22[1].mNode.mChild[1]);
        v24 = v22[1].mNode.mUID;
        v32 = (int)v22[1].mNode.mChild[1];
        v33 = v23;
        v34 = v24;
        v25 = HIDWORD(v22[1].mNode.mParent);
        v26 = (int)v22[1].mNode.mChild[0];
        v35 = (int)v22[1].mNode.mParent;
        v36 = v25;
        v37 = v26;
        v27 = (AMD_HD3D *)CullManager::Instance();
        v28 = v3->mCullResults;
        _(v27);
      }
      if ( !v7 )
      {
        if ( !v2->mSettings->mCullIndex )
        {
          v29 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
          *(float *)v29 = UFG::qColour::White.r;
          v30 = v29;
          *((_DWORD *)v29 + 1) = LODWORD(UFG::qColour::White.g);
          *((_DWORD *)v29 + 2) = LODWORD(UFG::qColour::White.b);
          *((_DWORD *)v29 + 3) = LODWORD(UFG::qColour::White.a);
          *((_DWORD *)v29 + 4) = LODWORD(UFG::qColour::White.r);
          *((_DWORD *)v29 + 5) = LODWORD(UFG::qColour::White.g);
          *((_DWORD *)v29 + 6) = LODWORD(UFG::qColour::White.b);
          *((_DWORD *)v29 + 7) = LODWORD(UFG::qColour::White.a);
          *((_DWORD *)v29 + 7) = LODWORD(v3->mSelfIlluminationOverride);
          v31 = Render::View::GetStateValues(v2);
          v31->mSetValueMask.mFlags[0] |= 0x400000000ui64;
          v31->mParamValues[34] = v30;
        }
        SubmitRenderModel(v2, (Illusion::Model *)v3->mModelHandle.mData, &v3->mLocalWorld);
      }
      return;
    }
  }
}

// File Line: 192
// RVA: 0x2313B0
void __fastcall UFG::DynamicSceneryInstance::DrawAll(Render::View *view)
{
  Render::View *v1; // rsi
  UFG::DynamicSceneryInstance *v2; // rcx
  UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *v3; // rbx

  v1 = view;
  v2 = (UFG::DynamicSceneryInstance *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext;
  if ( &UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList - 88) )
  {
    do
    {
      v3 = (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)&v2->mNext[-6].mNext;
      UFG::DynamicSceneryInstance::Draw(v2, v1);
      v2 = (UFG::DynamicSceneryInstance *)v3;
    }
    while ( v3 != (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList
                                                                                            - 88) );
  }
}

// File Line: 398
// RVA: 0x2357E0
void __fastcall UFG::DynamicSceneryInstance::UpdateCullInfo(UFG::DynamicSceneryInstance *this)
{
  UFG::qResourceData *v1; // r8
  UFG::DynamicSceneryInstance *v2; // rbx
  CullInfo *v3; // rdx
  float v4; // xmm0_4
  float v5; // xmm1_4
  CullInfo *v6; // rcx
  float v7; // xmm0_4
  unsigned int v8; // xmm1_4

  v1 = this->mModelHandle.mData;
  v2 = this;
  if ( v1 )
  {
    if ( !this->mHidden )
    {
      v3 = this->mCullInfo;
      v4 = *((float *)&v1[1].mNode.mParent + 1);
      v5 = *(float *)v1[1].mNode.mChild;
      v3->mAABBMin[0] = *(float *)&v1[1].mNode.mParent;
      v3->mAABBMin[1] = v4;
      v3->mAABBMin[2] = v5;
      v6 = this->mCullInfo;
      v7 = *((float *)&v1[1].mNode.mChild[1] + 1);
      v8 = v1[1].mNode.mUID;
      v6->mAABBMax[0] = *(float *)&v1[1].mNode.mChild[1];
      v6->mAABBMax[1] = v7;
      LODWORD(v6->mAABBMax[2]) = v8;
      v2->mCullInfo->mPixelScaleBias = CullManager::Instance()->mPixelDensityDynamicBias;
    }
  }
}

// File Line: 416
// RVA: 0x232DA0
char __fastcall UFG::DynamicSceneryInstance::GetTransform(UFG::DynamicSceneryInstance *this, Render::Decal *decal, UFG::qMatrix44 *mat)
{
  char result; // al
  CullResults *v4; // rax
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1

  if ( this->mHidden )
    return 0;
  v4 = this->mCullResults;
  if ( v4 )
  {
    if ( v4->mViewResult[0] > 1u )
      return 0;
  }
  v5 = this->mLocalWorld.v1;
  v6 = this->mLocalWorld.v2;
  result = 1;
  v7 = this->mLocalWorld.v3;
  mat->v0 = this->mLocalWorld.v0;
  mat->v1 = v5;
  mat->v2 = v6;
  mat->v3 = v7;
  return result;
}

// File Line: 427
// RVA: 0x2351A0
void __fastcall UFG::TestDynamicSceneryForDecals(Render::DecalClipRequest *request, UFG::qBox *projBox)
{
  UFG::qBox *v2; // rdi
  UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *v3; // rbx
  Render::DecalClipRequest *v4; // rbp
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v5; // r14
  UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *v6; // rsi
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v7; // rax
  UFG::qMatrix44 *v8; // rcx
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::qMatrix44 *v13; // rax
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  UFG::qVector4 v16; // xmm0
  UFG::qResourceInventory *v17; // rax
  unsigned int v18; // er12
  UFG::qResourceWarehouse *v19; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qVector3 min; // [rsp+20h] [rbp-88h]
  UFG::qVector3 max; // [rsp+30h] [rbp-78h]
  UFG::qMatrix44 m; // [rsp+40h] [rbp-68h]

  v2 = projBox;
  v3 = (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext;
  v4 = request;
  if ( &UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList - 88) )
  {
    do
    {
      v5 = v3[9].mNode.mNext;
      v6 = (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)&v3[6].mNode.mPrev[-6].mNext;
      if ( v5 && !LOWORD(v3[6].mNode.mNext) )
      {
        v7 = v3[7].mNode.mPrev;
        v8 = &UFG::qMatrix44::msIdentity;
        v9 = *((float *)&v7->mPrev + 1);
        v10 = *(float *)&v7->mNext;
        min.x = *(float *)&v7->mPrev;
        min.y = v9;
        min.z = v10;
        v11 = *((float *)&v7[1].mPrev + 1);
        v12 = *(float *)&v7[1].mNext;
        max.x = *(float *)&v7[1].mPrev;
        max.y = v11;
        max.z = v12;
        v13 = (UFG::qMatrix44 *)v7[3].mNext;
        if ( v13 )
          v8 = v13;
        v14 = v8->v2;
        v15 = v8->v3;
        v16 = v8->v0;
        m.v1 = v8->v1;
        m.v2 = v14;
        m.v0 = v16;
        m.v3 = v15;
        TransformAABB(&m, &min, &max);
        if ( min.x <= v2->mMax.x
          && max.x >= v2->mMin.x
          && min.y <= v2->mMax.y
          && max.y >= v2->mMin.y
          && min.z <= v2->mMax.z
          && max.z >= v2->mMin.z )
        {
          v17 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
          v18 = (unsigned int)v5[1].mNext;
          if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
          {
            v19 = UFG::qResourceWarehouse::Instance();
            v17 = UFG::qResourceWarehouse::GetInventory(v19, 0xA2ADCD77);
            `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v17;
          }
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mModelProxy.mModelHandle.mPrev, 0xA2ADCD77, v18, v17);
          v4->mModelProxy.mRModel = 0i64;
          v20 = &v4->mComponentPtr;
          v4->mLocalToWorld.v0 = (UFG::qVector4)v3[11];
          v4->mLocalToWorld.v1 = (UFG::qVector4)v3[12];
          v4->mLocalToWorld.v2 = (UFG::qVector4)v3[13];
          v4->mLocalToWorld.v3 = (UFG::qVector4)v3[14];
          if ( v4->mComponentPtr.m_pPointer )
          {
            v21 = v20->mPrev;
            v22 = v4->mComponentPtr.mNext;
            v21->mNext = v22;
            v22->mPrev = v21;
            v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->mPrev;
            v4->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mComponentPtr.mPrev;
          }
          v4->mComponentPtr.m_pPointer = (UFG::SimComponent *)&v3[1].mNode.mNext;
          if ( v3 != (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)-24i64 )
          {
            v23 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v3[2].mNode.mPrev;
            v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->mPrev;
            v20->mPrev = v23;
            v4->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3[2];
            v3[2].mNode.mPrev = (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *)v20;
          }
          v4->mScenery = (Render::IDecalScenery *)v3;
          Render::DecalManager::AddClipQueue(&Render::gDecalManager, v4);
        }
      }
      v3 = v6;
    }
    while ( v6 != (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList
                                                                                            - 88) );
  }
}

