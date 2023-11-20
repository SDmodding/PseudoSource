// File Line: 29
// RVA: 0x14573B0
__int64 dynamic_initializer_for__UFG::DropShadowComponent::s_DropShadowComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::DropShadowComponent::s_DropShadowComponentList__);
}

// File Line: 30
// RVA: 0x74BF0
const char *__fastcall UFG::DropShadowComponent::GetTypeName(UFG::DropShadowComponent *this)
{
  return "DropShadowComponent";
}

// File Line: 38
// RVA: 0x743E0
void __fastcall UFG::DropShadowComponent::DropShadowComponent(UFG::DropShadowComponent *this)
{
  UFG::DropShadowComponent *v1; // rsi
  UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent> *v2; // rax
  unsigned int v3; // eax
  Illusion::Material *v4; // rdi
  int v5; // ebx
  UFG::qResourceWarehouse *v6; // rax

  v1 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v2 = (UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DropShadowComponent::`vftable;
  v1->mShadowTextureID = 0;
  v1->mScale.x = 0.75;
  v1->mScale.y = 0.75;
  v1->mDrawableComponent = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::DropShadowComponent::_DropShadowComponentTypeUID,
    "DropShadowComponent");
  if ( !UFG::msMaterial )
  {
    v3 = UFG::qStringHashUpper32("DropShadowMat", 0xFFFFFFFF);
    v4 = Illusion::Factory::NewMaterial("DropShadowMat", v3, 6u, 0i64, 0i64, 0i64);
    v5 = UFG::qStringHash32("DRBLOBSHADOW", 0xFFFFFFFF);
    LOWORD(v4[1].mNode.mChild[0]) = 0;
    HIDWORD(v4[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
    LODWORD(v4[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
    v4[1].mTypeUID = -1957338719;
    LODWORD(v4[1].mResourceHandles.mNode.mNext) = v5;
    *(_WORD *)&v4[1].mDebugName[12] = 0;
    *(_DWORD *)&v4[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    *(_DWORD *)&v4[1].mDebugName[4] = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
    LODWORD(v4[1].mStateBlockMask.mFlags[1]) = -1958479169;
    LODWORD(v4[1].mStateBlockMask.mFlags[0]) = 0;
    LOWORD(v4[1].mMaterialUser.mOffset) = 0;
    *(&v4[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    v4[1].mNumParams = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
    LODWORD(v4[2].mResourceHandles.mNode.mPrev) = -1958479169;
    v4[2].mNode.mUID = 0;
    LOWORD(v4[2].mTypeUID) = 0;
    HIDWORD(v4[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    LODWORD(v4[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    *((_DWORD *)&v4[2].0 + 22) = 315097330;
    *(_DWORD *)&v4[2].mDebugName[28] = 1478433551;
    LOWORD(v4[2].mStateBlockMask.mFlags[1]) = 0;
    HIDWORD(v4[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    LODWORD(v4[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    LODWORD(v4[3].mNode.mChild[1]) = 1002903008;
    LODWORD(v4[3].mNode.mChild[0]) = 1660426324;
    LOWORD(v4[3].mResourceHandles.mNode.mPrev) = 0;
    *(&v4[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    v4[3].mNode.mUID = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
    *(_DWORD *)&v4[3].mDebugName[20] = -1958479169;
    *(_DWORD *)&v4[3].mDebugName[12] = 0;
    v6 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v6, (UFG::qResourceData *)&v4->mNode);
    UFG::msMaterial = v4;
  }
}

// File Line: 64
// RVA: 0x74C50
UFG::DropShadowComponent *__fastcall UFG::DropShadowComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *sceneObject, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rsi
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::DropShadowComponent *v6; // rbx
  char *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  char *v10; // rax
  UFG::DropShadowComponent *v11; // rax
  UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent> *v12; // rcx
  UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent> *v13; // rax
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = sceneObject;
  v4 = sceneObject->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_DropShadow::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    v7 = 0i64;
  if ( !v2 && !v7 )
    return 0i64;
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x68ui64, "DropShadowComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::DropShadowComponent::DropShadowComponent((UFG::DropShadowComponent *)v10);
    v6 = v11;
  }
  v12 = (UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent> *)&v6->mPrev;
  v13 = UFG::DropShadowComponent::s_DropShadowComponentList.mNode.mPrev;
  UFG::DropShadowComponent::s_DropShadowComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent> *)&v6->mPrev;
  v12->mPrev = v13;
  v12->mNext = (UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent> *)&UFG::DropShadowComponent::s_DropShadowComponentList;
  UFG::DropShadowComponent::s_DropShadowComponentList.mNode.mPrev = (UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent> *)&v6->mPrev;
  UFG::SimObjectModifier::SimObjectModifier(&v14, v3->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v14, (UFG::SimComponent *)&v6->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v14);
  UFG::SimObjectModifier::~SimObjectModifier(&v14);
  v6->mScale.x = *(float *)v7;
  v6->mScale.y = *((float *)v7 + 1);
  v6->mShadowTextureID = *((_DWORD *)v7 + 2);
  return v6;
}

// File Line: 84
// RVA: 0x74C00
void __fastcall UFG::DropShadowComponent::OnAttach(UFG::DropShadowComponent *this, UFG::SimObject *object)
{
  if ( object )
    this->mDrawableComponent = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                                    object,
                                                                    UFG::CompositeDrawableComponent::_TypeUID);
  else
    this->mDrawableComponent = 0i64;
}

// File Line: 90
// RVA: 0x74C40
void __fastcall UFG::DropShadowComponent::OnDetach(UFG::DropShadowComponent *this)
{
  this->mDrawableComponent = 0i64;
}

// File Line: 95
// RVA: 0x74730
void __fastcall UFG::DropShadowComponent::Draw(UFG::DropShadowComponent *this, Render::View *view, Illusion::Target *depth_target)
{
  UFG::CompositeDrawableComponent *v3; // r8
  Render::View *v4; // rsi
  CullResults *v5; // r9
  _WORD *v6; // rdi
  float *v7; // rax
  UFG::qMatrix44 *v8; // r9
  float v9; // xmm11_4
  float v10; // xmm12_4
  float v11; // xmm8_4
  float v12; // xmm12_4
  float v13; // xmm1_4
  UFG::qMatrix44 *v14; // rax
  float v15; // xmm14_4
  float v16; // xmm15_4
  float v17; // xmm13_4
  float v18; // xmm10_4
  float v19; // xmm8_4
  float v20; // xmm7_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm8_4
  float v24; // xmm7_4
  float v25; // xmm10_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm2_4
  Illusion::Material *v31; // rbx
  CullInfo *v32; // rax
  unsigned int v33; // er8
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  __int64 v37; // rax
  UFG::qMatrix44 local_world; // [rsp+30h] [rbp-E8h]

  v3 = this->mDrawableComponent;
  v4 = view;
  if ( v3 )
  {
    v5 = v3->mCullResults;
    if ( v5 )
    {
      v6 = 0i64;
      if ( view->mSettings->mCullIndex < 0 || v5->mViewResult[view->mSettings->mCullIndex] <= 1u )
      {
        v7 = v3->mCullInfo->mAABBMin;
        v8 = &UFG::qMatrix44::msIdentity;
        v9 = (float)(v7[4] - *v7) * this->mScale.x;
        v10 = v7[5] - v7[1];
        local_world = UFG::qMatrix44::msIdentity;
        LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(
                                            (__m128)UFG::qMatrix44::msIdentity.v2,
                                            (__m128)UFG::qMatrix44::msIdentity.v2,
                                            170);
        v12 = v10 * this->mScale.y;
        LODWORD(v13) = (unsigned __int128)_mm_shuffle_ps(
                                            (__m128)UFG::qMatrix44::msIdentity.v2,
                                            (__m128)UFG::qMatrix44::msIdentity.v2,
                                            85);
        v14 = &UFG::qMatrix44::msIdentity;
        if ( v3->mCullInfo->mpLocalWorld )
          v14 = (UFG::qMatrix44 *)v3->mCullInfo->mpLocalWorld;
        v15 = v14->v0.y;
        v16 = v14->v0.z;
        v17 = v14->v0.x;
        v18 = (float)(v13 * v16) - (float)(v11 * v15);
        v19 = (float)(v11 * v14->v0.x) - (float)(UFG::qMatrix44::msIdentity.v2.x * v16);
        v20 = (float)(UFG::qMatrix44::msIdentity.v2.x * v15) - (float)(v13 * v14->v0.x);
        v21 = (float)((float)(v19 * v19) + (float)(v18 * v18)) + (float)(v20 * v20);
        if ( v21 == 0.0 )
          v22 = 0.0;
        else
          v22 = 1.0 / fsqrt(v21);
        v23 = v19 * v22;
        v24 = v20 * v22;
        v25 = v18 * v22;
        v26 = (float)(v24 * v15) - (float)(v23 * v16);
        v27 = (float)(v25 * v16) - (float)(v24 * v17);
        v28 = (float)(v23 * v17) - (float)(v25 * v15);
        v29 = (float)((float)(v27 * v27) + (float)(v26 * v26)) + (float)(v28 * v28);
        if ( v29 == 0.0 )
          v30 = 0.0;
        else
          v30 = 1.0 / fsqrt(v29);
        v31 = UFG::msMaterial;
        local_world.v2.w = 0.0;
        local_world.v0.x = v17 * v9;
        local_world.v0.y = v15 * v9;
        local_world.v0.z = v16 * v9;
        local_world.v1.x = v25 * v12;
        local_world.v1.y = v23 * v12;
        local_world.v1.z = v24 * v12;
        local_world.v0.w = v9 * 0.0;
        local_world.v1.w = v12 * 0.0;
        local_world.v2.x = (float)(v26 * v30) * 0.25;
        local_world.v2.y = (float)(v27 * v30) * 0.25;
        local_world.v2.z = (float)(v28 * v30) * 0.25;
        v32 = v3->mCullInfo;
        v33 = this->mShadowTextureID;
        if ( v32->mpLocalWorld )
          v8 = (UFG::qMatrix44 *)v32->mpLocalWorld;
        v34 = v8->v3.y;
        v35 = v8->v3.z;
        v36 = v8->v3.x;
        local_world.v3.w = 1.0;
        local_world.v3.x = v36;
        local_world.v3.y = v34;
        local_world.v3.z = v35;
        if ( *(_DWORD *)&UFG::msMaterial[3].mDebugName[12] != v33 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&UFG::msMaterial[3].mResourceHandles.mNode.mNext,
            *(_DWORD *)&UFG::msMaterial[3].mDebugName[20],
            v33);
          v37 = v31->mMaterialUser.mOffset;
          if ( v37 )
            v6 = (_WORD *)((char *)&v31->mMaterialUser + v37);
          *v6 |= 0x20u;
        }
        Render::View::Draw(v4, &gDeferredCube, &local_world, 0);
      }
    }
  }
}

// File Line: 131
// RVA: 0x74B30
void __fastcall UFG::DropShadowComponent::DrawAll(Render::View *view, Illusion::Target *depth_target)
{
  Illusion::Material *v2; // rbx
  Illusion::Target *v3; // rsi
  Render::View *v4; // rbp
  unsigned int v5; // er8
  _WORD *v6; // rax
  UFG::DropShadowComponent *v7; // rcx
  UFG::qList<UFG::DropShadowComponent,UFG::DropShadowComponent,1,0> *v8; // rbx

  v2 = UFG::msMaterial;
  v3 = depth_target;
  v4 = view;
  if ( UFG::msMaterial )
  {
    v5 = depth_target->mTargetTexture[0]->mNode.mUID;
    if ( UFG::msMaterial[2].mNode.mUID != v5 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&UFG::msMaterial[2],
        (unsigned int)UFG::msMaterial[2].mResourceHandles.mNode.mPrev,
        v5);
      v6 = (_WORD *)v2->mMaterialUser.mOffset;
      if ( v6 )
        v6 = (_WORD *)((char *)v6 + (_QWORD)v2 + 120);
      *v6 |= 0x20u;
    }
  }
  v7 = (UFG::DropShadowComponent *)&UFG::DropShadowComponent::s_DropShadowComponentList.mNode.mNext[-4];
  if ( (UFG::qList<UFG::DropShadowComponent,UFG::DropShadowComponent,1,0> *)&UFG::DropShadowComponent::s_DropShadowComponentList.mNode.mNext[-4] != &UFG::DropShadowComponent::s_DropShadowComponentList - 4 )
  {
    do
    {
      v8 = (UFG::qList<UFG::DropShadowComponent,UFG::DropShadowComponent,1,0> *)&v7->mNext[-4];
      UFG::DropShadowComponent::Draw(v7, v4, v3);
      v7 = (UFG::DropShadowComponent *)v8;
    }
    while ( v8 != &UFG::DropShadowComponent::s_DropShadowComponentList - 4 );
  }
}

