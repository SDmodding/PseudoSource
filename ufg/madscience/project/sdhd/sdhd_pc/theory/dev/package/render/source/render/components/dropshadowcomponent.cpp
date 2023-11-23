// File Line: 29
// RVA: 0x14573B0
__int64 dynamic_initializer_for__UFG::DropShadowComponent::s_DropShadowComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DropShadowComponent::s_DropShadowComponentList__);
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
  unsigned int v2; // eax
  Illusion::Material *v3; // rdi
  int v4; // ebx
  UFG::qResourceWarehouse *v5; // rax

  UFG::SimComponent::SimComponent(this, 0);
  this->mPrev = &this->UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent>;
  this->mNext = &this->UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DropShadowComponent::`vftable;
  this->mShadowTextureID = 0;
  this->mScale.x = 0.75;
  this->mScale.y = 0.75;
  this->mDrawableComponent = 0i64;
  UFG::SimComponent::AddType(this, UFG::DropShadowComponent::_DropShadowComponentTypeUID, "DropShadowComponent");
  if ( !UFG::msMaterial )
  {
    v2 = UFG::qStringHashUpper32("DropShadowMat", 0xFFFFFFFF);
    v3 = Illusion::Factory::NewMaterial("DropShadowMat", v2, 6u, 0i64, 0i64, 0i64);
    v4 = UFG::qStringHash32("DRBLOBSHADOW", 0xFFFFFFFF);
    LOWORD(v3[1].mNode.mChild[0]) = 0;
    HIDWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
    LODWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
    v3[1].mTypeUID = -1957338719;
    LODWORD(v3[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v4;
    *(_WORD *)&v3[1].mDebugName[12] = 0;
    *(_DWORD *)&v3[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    *(_DWORD *)&v3[1].mDebugName[4] = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
    LODWORD(v3[1].mStateBlockMask.mFlags[1]) = -1958479169;
    LODWORD(v3[1].mStateBlockMask.mFlags[0]) = 0;
    LOWORD(v3[1].mMaterialUser.mOffset) = 0;
    *(&v3[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    v3[1].mNumParams = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
    LODWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
    v3[2].mNode.mUID = 0;
    LOWORD(v3[2].mTypeUID) = 0;
    HIDWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    LODWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    *((_DWORD *)&v3[2].UFG::qResourceData + 22) = 315097330;
    *(_DWORD *)&v3[2].mDebugName[28] = 1478433551;
    LOWORD(v3[2].mStateBlockMask.mFlags[1]) = 0;
    HIDWORD(v3[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    LODWORD(v3[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    LODWORD(v3[3].mNode.mChild[1]) = 1002903008;
    LODWORD(v3[3].mNode.mChild[0]) = 1660426324;
    LOWORD(v3[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
    *(&v3[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    v3[3].mNode.mUID = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
    *(_DWORD *)&v3[3].mDebugName[20] = -1958479169;
    *(_DWORD *)&v3[3].mDebugName[12] = 0;
    v5 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v5, v3);
    UFG::msMaterial = v3;
  }
}

// File Line: 64
// RVA: 0x74C50
UFG::DropShadowComponent *__fastcall UFG::DropShadowComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *sceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::DropShadowComponent *v6; // rbx
  char *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  char *v10; // rax
  UFG::DropShadowComponent *v11; // rax
  UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent> *mPrev; // rax
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         &component_DropShadow::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
  else
    MemImagePtr = 0i64;
  if ( !required && !MemImagePtr )
    return 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x68ui64, "DropShadowComponent", 0i64, 1u);
  if ( v10 )
  {
    UFG::DropShadowComponent::DropShadowComponent((UFG::DropShadowComponent *)v10);
    v6 = v11;
  }
  mPrev = UFG::DropShadowComponent::s_DropShadowComponentList.mNode.mPrev;
  UFG::DropShadowComponent::s_DropShadowComponentList.mNode.mPrev->mNext = &v6->UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent>;
  v6->mPrev = mPrev;
  v6->mNext = (UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent> *)&UFG::DropShadowComponent::s_DropShadowComponentList;
  UFG::DropShadowComponent::s_DropShadowComponentList.mNode.mPrev = &v6->UFG::qNode<UFG::DropShadowComponent,UFG::DropShadowComponent>;
  UFG::SimObjectModifier::SimObjectModifier(&v13, sceneObject->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v13, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v13);
  UFG::SimObjectModifier::~SimObjectModifier(&v13);
  v6->mScale = *(UFG::qVector2 *)MemImagePtr;
  v6->mShadowTextureID = *((_DWORD *)MemImagePtr + 2);
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
void __fastcall UFG::DropShadowComponent::Draw(
        UFG::DropShadowComponent *this,
        Render::View *view,
        Illusion::Target *depth_target)
{
  UFG::CompositeDrawableComponent *mDrawableComponent; // r8
  CullResults *mCullResults; // r9
  _WORD *v6; // rdi
  float *mAABBMin; // rax
  UFG::qMatrix44 *v8; // r9
  float v9; // xmm11_4
  float v10; // xmm12_4
  float v11; // xmm8_4
  float v12; // xmm12_4
  float v13; // xmm1_4
  UFG::qMatrix44 *mpLocalWorld; // rax
  float y; // xmm14_4
  float z; // xmm15_4
  float x; // xmm13_4
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
  Illusion::Material *force_mat; // rbx
  CullInfo *mCullInfo; // rax
  unsigned int mShadowTextureID; // r8d
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  __int64 mOffset; // rax
  UFG::qMatrix44 local_world; // [rsp+30h] [rbp-E8h] BYREF

  mDrawableComponent = this->mDrawableComponent;
  if ( mDrawableComponent )
  {
    mCullResults = mDrawableComponent->mCullResults;
    if ( mCullResults )
    {
      v6 = 0i64;
      if ( view->mSettings->mCullIndex < 0 || mCullResults->mViewResult[view->mSettings->mCullIndex] <= 1u )
      {
        mAABBMin = mDrawableComponent->mCullInfo->mAABBMin;
        v8 = &UFG::qMatrix44::msIdentity;
        v9 = (float)(mAABBMin[4] - *mAABBMin) * this->mScale.x;
        v10 = mAABBMin[5] - mAABBMin[1];
        local_world.v0 = UFG::qMatrix44::msIdentity.v0;
        local_world.v1 = UFG::qMatrix44::msIdentity.v1;
        LODWORD(v11) = _mm_shuffle_ps((__m128)UFG::qMatrix44::msIdentity.v2, (__m128)UFG::qMatrix44::msIdentity.v2, 170).m128_u32[0];
        v12 = v10 * this->mScale.y;
        local_world.v2 = UFG::qMatrix44::msIdentity.v2;
        local_world.v3 = UFG::qMatrix44::msIdentity.v3;
        LODWORD(v13) = _mm_shuffle_ps((__m128)UFG::qMatrix44::msIdentity.v2, (__m128)UFG::qMatrix44::msIdentity.v2, 85).m128_u32[0];
        mpLocalWorld = &UFG::qMatrix44::msIdentity;
        if ( mDrawableComponent->mCullInfo->mpLocalWorld )
          mpLocalWorld = (UFG::qMatrix44 *)mDrawableComponent->mCullInfo->mpLocalWorld;
        y = mpLocalWorld->v0.y;
        z = mpLocalWorld->v0.z;
        x = mpLocalWorld->v0.x;
        v18 = (float)(v13 * z) - (float)(v11 * y);
        v19 = (float)(v11 * mpLocalWorld->v0.x) - (float)(UFG::qMatrix44::msIdentity.v2.x * z);
        v20 = (float)(UFG::qMatrix44::msIdentity.v2.x * y) - (float)(v13 * mpLocalWorld->v0.x);
        v21 = (float)((float)(v19 * v19) + (float)(v18 * v18)) + (float)(v20 * v20);
        if ( v21 == 0.0 )
          v22 = 0.0;
        else
          v22 = 1.0 / fsqrt(v21);
        v23 = v19 * v22;
        v24 = v20 * v22;
        v25 = v18 * v22;
        v26 = (float)(v24 * y) - (float)(v23 * z);
        v27 = (float)(v25 * z) - (float)(v24 * x);
        v28 = (float)(v23 * x) - (float)(v25 * y);
        v29 = (float)((float)(v27 * v27) + (float)(v26 * v26)) + (float)(v28 * v28);
        if ( v29 == 0.0 )
          v30 = 0.0;
        else
          v30 = 1.0 / fsqrt(v29);
        force_mat = UFG::msMaterial;
        local_world.v2.w = 0.0;
        local_world.v0.x = x * v9;
        local_world.v0.y = y * v9;
        local_world.v0.z = z * v9;
        local_world.v1.x = v25 * v12;
        local_world.v1.y = v23 * v12;
        local_world.v1.z = v24 * v12;
        local_world.v0.w = v9 * 0.0;
        local_world.v1.w = v12 * 0.0;
        local_world.v2.x = (float)(v26 * v30) * 0.25;
        local_world.v2.y = (float)(v27 * v30) * 0.25;
        local_world.v2.z = (float)(v28 * v30) * 0.25;
        mCullInfo = mDrawableComponent->mCullInfo;
        mShadowTextureID = this->mShadowTextureID;
        if ( mCullInfo->mpLocalWorld )
          v8 = (UFG::qMatrix44 *)mCullInfo->mpLocalWorld;
        v34 = v8->v3.y;
        v35 = v8->v3.z;
        v36 = v8->v3.x;
        local_world.v3.w = 1.0;
        local_world.v3.x = v36;
        local_world.v3.y = v34;
        local_world.v3.z = v35;
        if ( *(_DWORD *)&UFG::msMaterial[3].mDebugName[12] != mShadowTextureID )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&UFG::msMaterial[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
            *(_DWORD *)&UFG::msMaterial[3].mDebugName[20],
            mShadowTextureID);
          mOffset = force_mat->mMaterialUser.mOffset;
          if ( mOffset )
            v6 = (_WORD *)((char *)&force_mat->mMaterialUser + mOffset);
          *v6 |= 0x20u;
          force_mat = UFG::msMaterial;
        }
        Render::View::Draw(view, &gDeferredCube, &local_world, 0, force_mat);
      }
    }
  }
}

// File Line: 131
// RVA: 0x74B30
void __fastcall UFG::DropShadowComponent::DrawAll(Render::View *view, Illusion::Target *depth_target)
{
  Illusion::Material *v2; // rbx
  unsigned int mUID; // r8d
  _WORD *mOffset; // rax
  UFG::DropShadowComponent *v7; // rcx
  UFG::qList<UFG::DropShadowComponent,UFG::DropShadowComponent,1,0> *v8; // rbx

  v2 = UFG::msMaterial;
  if ( UFG::msMaterial )
  {
    mUID = depth_target->mTargetTexture[0]->mNode.mUID;
    if ( UFG::msMaterial[2].mNode.mUID != mUID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&UFG::msMaterial[2],
        (unsigned int)UFG::msMaterial[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
        mUID);
      mOffset = (_WORD *)v2->mMaterialUser.mOffset;
      if ( mOffset )
        mOffset = (_WORD *)((char *)mOffset + (_QWORD)v2 + 120);
      *mOffset |= 0x20u;
    }
  }
  v7 = (UFG::DropShadowComponent *)&UFG::DropShadowComponent::s_DropShadowComponentList.mNode.mNext[-4];
  if ( (UFG::qList<UFG::DropShadowComponent,UFG::DropShadowComponent,1,0> *)&UFG::DropShadowComponent::s_DropShadowComponentList.mNode.mNext[-4] != &UFG::DropShadowComponent::s_DropShadowComponentList - 4 )
  {
    do
    {
      v8 = (UFG::qList<UFG::DropShadowComponent,UFG::DropShadowComponent,1,0> *)&v7->mNext[-4];
      UFG::DropShadowComponent::Draw(v7, view, depth_target);
      v7 = (UFG::DropShadowComponent *)v8;
    }
    while ( v8 != &UFG::DropShadowComponent::s_DropShadowComponentList - 4 );
  }
}

