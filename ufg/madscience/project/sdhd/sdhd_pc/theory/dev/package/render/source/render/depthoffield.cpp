// File Line: 37
// RVA: 0x1452910
__int64 Render::_dynamic_initializer_for__gDepthOfField__()
{
  UFG::qMemSet(&Render::gDepthOfField.mCurrFocus, 0, 0x18u);
  Render::gDepthOfField.mMaterial = 0i64;
  Render::gDepthOfField.mNearBlurRendered = 0;
  return atexit(Render::_dynamic_atexit_destructor_for__gDepthOfField__);
}

// File Line: 39
// RVA: 0x1452A00
__int64 Render::_dynamic_initializer_for__kDepthOfDieldPrePassUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DEPTHOFFIELD_PREPASS", 0xFFFFFFFF);
  kDepthOfDieldPrePassUID = result;
  return result;
}

// File Line: 40
// RVA: 0x14529A0
__int64 Render::_dynamic_initializer_for__kDepthOfDieldCalcNearCoCUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DEPTHOFFIELD_CALCNEARCOC", 0xFFFFFFFF);
  kDepthOfDieldCalcNearCoCUID = result;
  return result;
}

// File Line: 41
// RVA: 0x14529C0
__int64 Render::_dynamic_initializer_for__kDepthOfDieldDownsampleUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DEPTHOFFIELD_DOWNSAMPLE", 0xFFFFFFFF);
  kDepthOfDieldDownsampleUID = result;
  return result;
}

// File Line: 42
// RVA: 0x1452A20
__int64 Render::_dynamic_initializer_for__kDepthOfDieldUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DEPTHOFFIELD", 0xFFFFFFFF);
  kDepthOfDieldUID = result;
  return result;
}

// File Line: 43
// RVA: 0x14529E0
__int64 Render::_dynamic_initializer_for__kDepthOfDieldNISUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DEPTHOFFIELDNIS", 0xFFFFFFFF);
  kDepthOfDieldNISUID = result;
  return result;
}

// File Line: 44
// RVA: 0x1452A80
__int64 Render::_dynamic_initializer_for__kSimpleUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SIMPLE", 0xFFFFFFFF);
  kSimpleUID = result;
  return result;
}

// File Line: 47
// RVA: 0x1452980
__int64 Render::_dynamic_initializer_for__kAlphaStateModulateMaxAlphaUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32(Render::kAlphaStateModulateMaxAlpha, 0xFFFFFFFF);
  kAlphaStateModulateMaxAlphaUID = result;
  return result;
}

// File Line: 50
// RVA: 0x1452950
__int64 Render::_dynamic_initializer_for__gOverrideFocus__()
{
  UFG::qMemSet(&Render::gOverrideFocus, 0, 0x18u);
  return atexit(Render::_dynamic_atexit_destructor_for__gOverrideFocus__);
}

// File Line: 59
// RVA: 0x86A0
void __fastcall Render::DepthOfField::Focus::Focus(Render::DepthOfField::Focus *this)
{
  UFG::qMemSet(this, 0, 0x18u);
}

// File Line: 82
// RVA: 0x9330
void __fastcall Render::DepthOfField::Focus::Set(Render::DepthOfField::Focus *this, Render::DepthOfField::Focus *focus)
{
  this->mFocalDistance = focus->mFocalDistance;
  this->mInFocusRange = focus->mInFocusRange;
  this->mNearRange = focus->mNearRange;
  this->mNearBlurRadius = focus->mNearBlurRadius;
  this->mFarRange = focus->mFarRange;
  this->mFarBlurRadius = focus->mFarBlurRadius;
}

// File Line: 87
// RVA: 0x86C0
void __fastcall Render::DepthOfField::Focus::DisableFocus(Render::DepthOfField::Focus *this)
{
  this->mNearBlurRadius = 0.0;
  this->mFarBlurRadius = 0.0;
}

// File Line: 116
// RVA: 0x86D0
void __fastcall Render::DepthOfField::Init(Render::DepthOfField *this)
{
  Render::DepthOfField *v1; // rsi
  unsigned int v2; // eax
  Illusion::Material *v3; // rax
  unsigned int v4; // ebx
  Illusion::Material *v5; // rdi
  int v6; // eax
  Illusion::Material *v7; // rbx
  int v8; // eax
  Illusion::Material *v9; // rbx
  unsigned int v10; // eax
  Illusion::Material *v11; // rbx
  int v12; // eax
  Illusion::Material *v13; // rbx
  int v14; // eax
  Illusion::Material *v15; // rbx
  unsigned int v16; // eax
  Illusion::Material *v17; // rbx
  int v18; // eax
  UFG::qResourceWarehouse *v19; // rax
  unsigned int v20; // eax
  __int16 v21; // ax
  unsigned int v22; // edx
  UFG::qResourceData *v23; // rax
  UFG::qResourceData *v24; // rbx
  UFG::qResourceWarehouse *v25; // rax

  v1 = this;
  v2 = UFG::qStringHash32("DEPTHOFFIELD", 0xFFFFFFFF);
  v3 = Illusion::Factory::NewMaterial("DEPTHOFFIELD", v2, 7u, 0i64, 0i64, 0i64);
  v4 = kDepthOfDieldUID;
  v1->mMaterial = v3;
  LOWORD(v3[1].mNode.mChild[0]) = 0;
  v5 = v3;
  HIDWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v6 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v5[1].mTypeUID = -1957338719;
  LODWORD(v5[1].mResourceHandles.mNode.mNext) = v4;
  LODWORD(v5[1].mNode.mParent) = v6;
  v7 = v1->mMaterial;
  *(_WORD *)&v1->mMaterial[1].mDebugName[12] = 0;
  *(_DWORD *)&v7[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v8 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v7[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v7[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v7[1].mDebugName[4] = v8;
  v9 = v1->mMaterial;
  LOWORD(v1->mMaterial[1].mMaterialUser.mOffset) = 0;
  *(&v9[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v9[2].mResourceHandles.mNode.mPrev) = -1958479169;
  v9[2].mNode.mUID = 0;
  v9[1].mNumParams = v10;
  v11 = v1->mMaterial;
  LOWORD(v1->mMaterial[2].mTypeUID) = 0;
  HIDWORD(v11[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v12 = UFG::qStringHash32("texNear", 0xFFFFFFFF);
  *((_DWORD *)&v11[2].0 + 22) = -1958479169;
  *(_DWORD *)&v11[2].mDebugName[28] = 0;
  LODWORD(v11[2].mResourceHandles.mNode.mNext) = v12;
  v13 = v1->mMaterial;
  LOWORD(v1->mMaterial[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v13[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v14 = UFG::qStringHash32("texNearBlurred", 0xFFFFFFFF);
  LODWORD(v13[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v13[3].mNode.mChild[0]) = 0;
  LODWORD(v13[2].mStateBlockMask.mFlags[0]) = v14;
  v15 = v1->mMaterial;
  LOWORD(v1->mMaterial[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v15[3].mNode.mUID + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v16 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v15[3].mDebugName[20] = 315097330;
  *(_DWORD *)&v15[3].mDebugName[12] = 662883558;
  v15[3].mNode.mUID = v16;
  v17 = v1->mMaterial;
  *((_WORD *)&v1->mMaterial[3].0 + 44) = 0;
  *(_DWORD *)&v17[3].mDebugName[32] = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v18 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v17[4].mNode.mParent) = 1002903008;
  *(_DWORD *)&v17[3].mDebugName[28] = v18;
  LODWORD(v17[3].mMaterialUser.mOffset) = 1660426324;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, (UFG::qResourceData *)&v1->mMaterial->mNode);
  v20 = UFG::qStringHash32("cbDepthOfField", 0xFFFFFFFF);
  v21 = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, v20, "cbDepthOfField", 0);
  v22 = kAlphaStateModulateMaxAlphaUID;
  v1->mStateBlockIndex = v21;
  v23 = Illusion::Factory::NewAlphaState(Render::kAlphaStateModulateMaxAlpha, v22, 0i64, 0i64, 0i64);
  LOWORD(v23[1].mNode.mParent) = 1025;
  BYTE2(v23[1].mNode.mParent) = 5;
  LOWORD(v23[1].mNode.mChild[0]) = 1025;
  BYTE4(v23[1].mNode.mParent) = 2;
  BYTE2(v23[1].mNode.mChild[0]) = 6;
  v24 = v23;
  v25 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v25, v24);
  Render::gOverrideFocus.mFarRange = FLOAT_20_0;
  LODWORD(Render::gOverrideFocus.mNearBlurRadius) = (_DWORD)FLOAT_1_0;
  Render::gOverrideFocus.mFarBlurRadius = FLOAT_0_5;
  Render::gOverrideFocus.mFocalDistance = FLOAT_10_0;
  *(_QWORD *)&Render::gOverrideFocus.mInFocusRange = __PAIR__(LODWORD(FLOAT_7_0), LODWORD(FLOAT_3_0));
}

// File Line: 163
// RVA: 0x9300
void __fastcall Render::DepthOfField::Set(Render::DepthOfField *this, Render::DepthOfField::Focus *target_focus)
{
  this->mCurrFocus.mFocalDistance = target_focus->mFocalDistance;
  this->mCurrFocus.mInFocusRange = target_focus->mInFocusRange;
  this->mCurrFocus.mNearRange = target_focus->mNearRange;
  this->mCurrFocus.mNearBlurRadius = target_focus->mNearBlurRadius;
  this->mCurrFocus.mFarRange = target_focus->mFarRange;
  this->mCurrFocus.mFarBlurRadius = target_focus->mFarBlurRadius;
}

// File Line: 168
// RVA: 0x8A00
bool __fastcall Render::DepthOfField::IsEnabled(Render::DepthOfField *this)
{
  return this->mMaterial
      && (Render::gOverrideFocusEnabled
       || this->mCurrFocus.mFarBlurRadius > 0.050000001
       || this->mCurrFocus.mNearBlurRadius > 0.050000001);
}

// File Line: 187
// RVA: 0x8A30
void __fastcall Render::DepthOfField::Render(Render::DepthOfField *this, Render::DepthOfField::RenderContext *render_context, Illusion::SubmitContext *submit_context, float near_plane)
{
  Render::DepthOfField *v4; // rbx
  Illusion::SubmitContext *v5; // rdi
  Render::DepthOfField::RenderContext *v6; // rsi
  Render::DepthOfField::Focus *v7; // r15
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm9_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  char *v13; // r13
  float v14; // xmm6_4
  float v15; // xmm8_4
  Render::ViewSettings *v16; // rax
  unsigned int v17; // er14
  Illusion::StateValues *v18; // rax
  Illusion::Material *v19; // r14
  __int64 v20; // rax
  _WORD *v21; // rax
  Illusion::Material *v22; // r14
  unsigned int v23; // er8
  __int64 v24; // rax
  _WORD *v25; // rax
  Illusion::Material *v26; // r14
  unsigned int v27; // er8
  __int64 v28; // rax
  _WORD *v29; // rax
  char v30; // r15
  unsigned int v31; // er14
  Illusion::StateValues *v32; // rax
  Illusion::Material *v33; // r14
  __int64 v34; // rax
  _WORD *v35; // rax
  Illusion::Material *v36; // r14
  unsigned int v37; // er8
  __int64 v38; // rax
  _WORD *v39; // rax
  Illusion::Material *v40; // r14
  unsigned int v41; // er8
  __int64 v42; // rax
  _WORD *v43; // rax
  unsigned int v44; // er14
  Illusion::StateValues *v45; // rax
  Illusion::Material *v46; // r14
  __int64 v47; // rax
  _WORD *v48; // rax
  Illusion::Material *v49; // r14
  unsigned int v50; // er8
  __int64 v51; // rax
  _WORD *v52; // rax
  Illusion::Material *v53; // r14
  unsigned int v54; // er8
  __int64 v55; // rax
  _WORD *v56; // rax
  unsigned int v57; // er14
  Illusion::StateValues *v58; // rax
  unsigned int v59; // er8
  Illusion::Material *v60; // rdi
  __int64 v61; // rax
  _WORD *v62; // rax
  Illusion::Material *v63; // rdi
  unsigned int v64; // er8
  __int64 v65; // rax
  _WORD *v66; // rax
  Illusion::Material *v67; // rdi
  unsigned int v68; // er8
  __int64 v69; // rax
  _WORD *v70; // rax
  Illusion::Material *v71; // rdi
  unsigned int v72; // er8
  __int64 v73; // rax
  _WORD *v74; // rax
  Illusion::Material *v75; // rdi
  __int64 v76; // rax
  _WORD *v77; // rax
  unsigned int v78; // er8
  __int64 v79; // rax
  _WORD *v80; // rax
  __int64 v81; // rax
  _WORD *v82; // rax
  Illusion::Material *v83; // rdi
  __int64 v84; // rax
  _WORD *v85; // rax
  Render::View v86; // [rsp+50h] [rbp-88h]
  Render::Poly poly; // [rsp+238h] [rbp+160h]
  __int64 v88; // [rsp+260h] [rbp+188h]

  this->mNearBlurRendered = 0;
  v4 = this;
  v5 = submit_context;
  v6 = render_context;
  Render::gRenderUtilities.mSubmitContext = submit_context;
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>((Render::Poly *)&v88);
  v7 = &Render::gOverrideFocus;
  if ( !Render::gOverrideFocusEnabled )
    v7 = &v4->mCurrFocus;
  v8 = v7->mInFocusRange * 0.5;
  v9 = v7->mFocalDistance - v8;
  v10 = v7->mFocalDistance + v8;
  v11 = v9 - v7->mNearRange;
  v12 = v10 + v7->mFarRange;
  v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  UFG::qMemSet(v13, 0, 0x20u);
  v14 = v9 - v11;
  v15 = v12 - v10;
  *(float *)v13 = -1.0 / v14;
  *((float *)v13 + 1) = 1.0 - (float)((float)(-1.0 / v14) * v11);
  *((float *)v13 + 4) = 1.0 / v15;
  *((_DWORD *)v13 + 5) = COERCE_UNSIGNED_INT((float)(1.0 / v15) * v10) ^ _xmm[0];
  *((_DWORD *)v13 + 6) = LODWORD(v7->mFarBlurRadius);
  *((_DWORD *)v13 + 2) = LODWORD(v7->mNearBlurRadius);
  *((float *)v13 + 3) = near_plane;
  v16 = Render::ViewSettings::GetIdentity();
  Render::View::View(&v86, v16, v5);
  Render::View::BeginTarget(&v86, v6->mHalfSizeScratchTarget, "DepthOfField_Downsample", 0, 0, 0i64, 1, 0, 0, 0);
  v17 = v4->mStateBlockIndex;
  v18 = Render::View::GetStateValues(&v86);
  if ( v17 >= 0x40 )
    v18->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v17 - 64);
  else
    v18->mSetValueMask.mFlags[0] |= 1i64 << v17;
  v18->mParamValues[(signed __int16)v17] = v13;
  v19 = v4->mMaterial;
  if ( LODWORD(v4->mMaterial[1].mResourceHandles.mNode.mNext) != kDepthOfDieldDownsampleUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v19[1].mNode.mChild[1],
      v19[1].mTypeUID,
      kDepthOfDieldDownsampleUID);
    v20 = v19->mMaterialUser.mOffset;
    if ( v20 )
      v21 = (_WORD *)((char *)&v19->mMaterialUser + v20);
    else
      v21 = 0i64;
    *v21 |= 0x20u;
  }
  v22 = v4->mMaterial;
  v23 = v6->mSourceTarget->mTargetTexture[0]->mNode.mUID;
  if ( LODWORD(v4->mMaterial[1].mStateBlockMask.mFlags[0]) != v23 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v22[1].mDebugName[20], v22[1].mStateBlockMask.mFlags[1], v23);
    v24 = v22->mMaterialUser.mOffset;
    if ( v24 )
      v25 = (_WORD *)((char *)&v22->mMaterialUser + v24);
    else
      v25 = 0i64;
    *v25 |= 0x20u;
  }
  v26 = v4->mMaterial;
  v27 = v6->mDepthTexture->mNode.mUID;
  if ( v4->mMaterial[2].mNode.mUID != v27 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v26[2], (unsigned int)v26[2].mResourceHandles.mNode.mPrev, v27);
    v28 = v26->mMaterialUser.mOffset;
    if ( v28 )
      v29 = (_WORD *)((char *)&v26->mMaterialUser + v28);
    else
      v29 = 0i64;
    *v29 |= 0x20u;
  }
  Render::View::Draw(&v86, &poly, v4->mMaterial, 0i64);
  Render::View::EndTarget(&v86);
  if ( v4->mMaterial
    && (Render::gOverrideFocusEnabled
     || v4->mCurrFocus.mFarBlurRadius > 0.050000001
     || v4->mCurrFocus.mNearBlurRadius > 0.050000001) )
  {
    if ( v7->mNearRange <= 0.1 || v7->mNearBlurRadius <= 0.050000001 )
    {
      v30 = 0;
    }
    else
    {
      v30 = 1;
      Render::View::BeginTarget(&v86, v6->mNearBlur, "DepthOfField_PrePass", 0, 0, 0i64, 1, 0, 0, 0);
      v31 = v4->mStateBlockIndex;
      v32 = Render::View::GetStateValues(&v86);
      if ( v31 >= 0x40 )
        v32->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v31 - 64);
      else
        v32->mSetValueMask.mFlags[0] |= 1i64 << v31;
      v32->mParamValues[(signed __int16)v31] = v13;
      v33 = v4->mMaterial;
      if ( LODWORD(v4->mMaterial[1].mResourceHandles.mNode.mNext) != kDepthOfDieldPrePassUID )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v33[1].mNode.mChild[1],
          v33[1].mTypeUID,
          kDepthOfDieldPrePassUID);
        v34 = v33->mMaterialUser.mOffset;
        if ( v34 )
          v35 = (_WORD *)((char *)&v33->mMaterialUser + v34);
        else
          v35 = 0i64;
        *v35 |= 0x20u;
      }
      v36 = v4->mMaterial;
      v37 = v6->mHalfSizeScratchTarget->mTargetTexture[0]->mNode.mUID;
      if ( LODWORD(v4->mMaterial[1].mStateBlockMask.mFlags[0]) != v37 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v36[1].mDebugName[20],
          v36[1].mStateBlockMask.mFlags[1],
          v37);
        v38 = v36->mMaterialUser.mOffset;
        if ( v38 )
          v39 = (_WORD *)((char *)&v36->mMaterialUser + v38);
        else
          v39 = 0i64;
        *v39 |= 0x20u;
      }
      v40 = v4->mMaterial;
      v41 = v6->mDepthTexture->mNode.mUID;
      if ( v4->mMaterial[2].mNode.mUID != v41 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v40[2],
          (unsigned int)v40[2].mResourceHandles.mNode.mPrev,
          v41);
        v42 = v40->mMaterialUser.mOffset;
        if ( v42 )
          v43 = (_WORD *)((char *)&v40->mMaterialUser + v42);
        else
          v43 = 0i64;
        *v43 |= 0x20u;
      }
      Render::View::Draw(&v86, &poly, v4->mMaterial, 0i64);
      Render::View::EndTarget(&v86);
      Render::RenderUtilities::GaussBlur3x3(
        &Render::gRenderUtilities,
        v6->mNearBlur,
        v6->mQuarterSizeScratchTargetB,
        0,
        0i64,
        kGaussBlur3x3UID);
      Render::View::BeginTarget(&v86, v6->mQuarterSizeScratchTargetA, "CalcNearCoC", 0, 0, 0i64, 1, 0, 0, 0);
      v44 = v4->mStateBlockIndex;
      v45 = Render::View::GetStateValues(&v86);
      if ( v44 >= 0x40 )
        v45->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v44 - 64);
      else
        v45->mSetValueMask.mFlags[0] |= 1i64 << v44;
      v45->mParamValues[(signed __int16)v44] = v13;
      v46 = v4->mMaterial;
      if ( LODWORD(v4->mMaterial[1].mResourceHandles.mNode.mNext) != kDepthOfDieldCalcNearCoCUID )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v46[1].mNode.mChild[1],
          v46[1].mTypeUID,
          kDepthOfDieldCalcNearCoCUID);
        v47 = v46->mMaterialUser.mOffset;
        if ( v47 )
          v48 = (_WORD *)((char *)&v46->mMaterialUser + v47);
        else
          v48 = 0i64;
        *v48 |= 0x20u;
      }
      v49 = v4->mMaterial;
      v50 = v6->mNearBlur->mTargetTexture[0]->mNode.mUID;
      if ( *(_DWORD *)&v4->mMaterial[2].mDebugName[28] != v50 )
      {
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v49[2].mDebugName[4], *((_DWORD *)&v49[2].0 + 22), v50);
        v51 = v49->mMaterialUser.mOffset;
        if ( v51 )
          v52 = (_WORD *)((char *)&v49->mMaterialUser + v51);
        else
          v52 = 0i64;
        *v52 |= 0x20u;
      }
      v53 = v4->mMaterial;
      v54 = v6->mQuarterSizeScratchTargetB->mTargetTexture[0]->mNode.mUID;
      if ( LODWORD(v4->mMaterial[3].mNode.mChild[0]) != v54 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v53[2].mNumParams,
          (unsigned int)v53[3].mNode.mChild[1],
          v54);
        v55 = v53->mMaterialUser.mOffset;
        if ( v55 )
          v56 = (_WORD *)((char *)&v53->mMaterialUser + v55);
        else
          v56 = 0i64;
        *v56 |= 0x20u;
      }
      Render::View::Draw(&v86, &poly, v4->mMaterial, 0i64);
      Render::View::EndTarget(&v86);
      Render::RenderUtilities::GaussBlur3x3(
        &Render::gRenderUtilities,
        v6->mQuarterSizeScratchTargetB,
        v6->mNearBlur,
        0,
        0i64,
        kGaussBlur3x3UID);
    }
    Render::View::BeginTarget(&v86, v6->mDestTarget, "DepthOfField_FarBlur", 0, 0, 0i64, 1, 0, 0, 0);
    v57 = v4->mStateBlockIndex;
    v58 = Render::View::GetStateValues(&v86);
    if ( v57 >= 0x40 )
      v58->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v57 - 64);
    else
      v58->mSetValueMask.mFlags[0] |= 1i64 << v57;
    v59 = kDepthOfDieldUID;
    v58->mParamValues[(signed __int16)v57] = v13;
    v60 = v4->mMaterial;
    if ( v6->mQuality == 1 )
      v59 = kDepthOfDieldNISUID;
    if ( LODWORD(v60[1].mResourceHandles.mNode.mNext) != v59 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v60[1].mNode.mChild[1], v60[1].mTypeUID, v59);
      v61 = v60->mMaterialUser.mOffset;
      if ( v61 )
        v62 = (_WORD *)((char *)&v60->mMaterialUser + v61);
      else
        v62 = 0i64;
      *v62 |= 0x20u;
    }
    v63 = v4->mMaterial;
    v64 = v6->mHalfSizeScratchTarget->mTargetTexture[0]->mNode.mUID;
    if ( LODWORD(v4->mMaterial[1].mStateBlockMask.mFlags[0]) != v64 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v63[1].mDebugName[20], v63[1].mStateBlockMask.mFlags[1], v64);
      v65 = v63->mMaterialUser.mOffset;
      if ( v65 )
        v66 = (_WORD *)((char *)&v63->mMaterialUser + v65);
      else
        v66 = 0i64;
      *v66 |= 0x20u;
    }
    v67 = v4->mMaterial;
    v68 = v6->mDepthTexture->mNode.mUID;
    if ( v4->mMaterial[2].mNode.mUID != v68 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v67[2],
        (unsigned int)v67[2].mResourceHandles.mNode.mPrev,
        v68);
      v69 = v67->mMaterialUser.mOffset;
      if ( v69 )
        v70 = (_WORD *)((char *)&v67->mMaterialUser + v69);
      else
        v70 = 0i64;
      *v70 |= 0x20u;
    }
    v71 = v4->mMaterial;
    v72 = v6->mQuarterSizeScratchTargetA->mTargetTexture[0]->mNode.mUID;
    if ( *(_DWORD *)&v4->mMaterial[2].mDebugName[28] != v72 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v71[2].mDebugName[4], *((_DWORD *)&v71[2].0 + 22), v72);
      v73 = v71->mMaterialUser.mOffset;
      if ( v73 )
        v74 = (_WORD *)((char *)&v71->mMaterialUser + v73);
      else
        v74 = 0i64;
      *v74 |= 0x20u;
    }
    Render::View::Draw(&v86, &poly, v4->mMaterial, 0i64);
    if ( v30 )
    {
      v75 = Render::gRenderUtilities.mMaterial;
      if ( LODWORD(Render::gRenderUtilities.mMaterial[1].mResourceHandles.mNode.mNext) != kSimpleUID )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[1].mNode.mChild[1],
          Render::gRenderUtilities.mMaterial[1].mTypeUID,
          kSimpleUID);
        v76 = v75->mMaterialUser.mOffset;
        if ( v76 )
          v77 = (_WORD *)((char *)&v75->mMaterialUser + v76);
        else
          v77 = 0i64;
        *v77 |= 0x20u;
        v75 = Render::gRenderUtilities.mMaterial;
      }
      v78 = v6->mQuarterSizeScratchTargetA->mTargetTexture[0]->mNode.mUID;
      if ( LODWORD(v75[1].mStateBlockMask.mFlags[0]) != v78 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v75[1].mDebugName[20],
          v75[1].mStateBlockMask.mFlags[1],
          v78);
        v79 = v75->mMaterialUser.mOffset;
        if ( v79 )
          v80 = (_WORD *)((char *)&v75->mMaterialUser + v79);
        else
          v80 = 0i64;
        *v80 |= 0x20u;
        v75 = Render::gRenderUtilities.mMaterial;
      }
      if ( v75[2].mNode.mUID != kAlphaStateModulateMaxAlphaUID )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v75[2],
          (unsigned int)v75[2].mResourceHandles.mNode.mPrev,
          kAlphaStateModulateMaxAlphaUID);
        v81 = v75->mMaterialUser.mOffset;
        if ( v81 )
          v82 = (_WORD *)((char *)&v75->mMaterialUser + v81);
        else
          v82 = 0i64;
        *v82 |= 0x20u;
        v75 = Render::gRenderUtilities.mMaterial;
      }
      Render::View::Draw(&v86, &poly, v75, 0i64);
      v83 = Render::gRenderUtilities.mMaterial;
      if ( Render::gRenderUtilities.mMaterial[2].mNode.mUID != 0x2782CCE6 )
      {
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&Render::gRenderUtilities.mMaterial[2],
          (unsigned int)Render::gRenderUtilities.mMaterial[2].mResourceHandles.mNode.mPrev,
          0x2782CCE6u);
        v84 = v83->mMaterialUser.mOffset;
        if ( v84 )
          v85 = (_WORD *)((char *)&v83->mMaterialUser + v84);
        else
          v85 = 0i64;
        *v85 |= 0x20u;
      }
      v4->mNearBlurRendered = 1;
    }
    Render::View::EndTarget(&v86);
    Render::gRenderUtilities.mSubmitContext = 0i64;
  }
}

