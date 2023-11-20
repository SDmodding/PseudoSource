// File Line: 24
// RVA: 0x146C870
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::Gadget_UFG::DUIWindow_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::sFactoryOp);
}

// File Line: 25
// RVA: 0x146D240
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::OrientationGadget_UFG::Editor::Gadget_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::OrientationGadget", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::sInventory.vfptr,
    "UFG::Editor::OrientationGadget",
    v0);
  UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::OrientationGadget>::`vftable';
  UFG::qReflectInventory<UFG::Editor::OrientationGadget>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::OrientationGadget_UFG::Editor::Gadget_::sInventory__);
}

// File Line: 26
// RVA: 0x146CD40
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::CompassGadget_UFG::Editor::Gadget_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::CompassGadget", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::sInventory.vfptr,
    "UFG::Editor::CompassGadget",
    v0);
  UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::CompassGadget>::`vftable';
  UFG::qReflectInventory<UFG::Editor::CompassGadget>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::CompassGadget_UFG::Editor::Gadget_::sInventory__);
}

// File Line: 32
// RVA: 0x2017E0
void __fastcall UFG::Editor::Gadget::Gadget(UFG::Editor::Gadget *this)
{
  UFG::Editor::Gadget *v1; // rbx

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::Gadget", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Gadget::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Gadget::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mStyle = 141;
  UFG::qString::Set(&v1->mTitle, "Gadget");
}

// File Line: 39
// RVA: 0x203370
void __fastcall UFG::Editor::Gadget::~Gadget(UFG::Editor::Gadget *this)
{
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Gadget::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  this->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Gadget::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  UFG::DUIWindow::~DUIWindow((UFG::DUIWindow *)&this->vfptr);
}

// File Line: 49
// RVA: 0x201E00
void __fastcall UFG::Editor::OrientationGadget::OrientationGadget(UFG::Editor::OrientationGadget *this)
{
  UFG::Editor::OrientationGadget *v1; // rbx

  v1 = this;
  UFG::Editor::Gadget::Gadget((UFG::Editor::Gadget *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::OrientationGadget", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::OrientationGadget::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::OrientationGadget::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  UFG::qString::Set(&v1->mTitle, "Orient");
}

// File Line: 60
// RVA: 0x21AB20
void __fastcall UFG::Editor::OrientationGadget::UpdateUI(UFG::Editor::OrientationGadget *this, UFG::DUIContext *dui)
{
  int v2; // eax
  bool v3; // zf
  __int64 v4; // [rsp+20h] [rbp-18h]
  int v5; // [rsp+28h] [rbp-10h]
  int v6; // [rsp+2Ch] [rbp-Ch]

  this->mRect.mW = 96;
  this->mRect.mH = 24;
  v4 = *(_QWORD *)&this->mRect.mX;
  v5 = this->mRect.mW;
  v2 = this->mRect.mH;
  v6 = 96;
  v3 = dui->mBuildCommandList == 0;
  HIDWORD(v4) += 24;
  if ( !v3 )
    this->vfptr[2].__vecDelDtor((UFG::qReflectObject *)this, (unsigned int)&v4);
}

// File Line: 73
// RVA: 0x211C40
void __fastcall UFG::Editor::OrientationGadget::Render(UFG::Editor::OrientationGadget *this, UFG::DUIRect *clientArea)
{
  UFG::Editor::View *v2; // rbx
  float v3; // xmm2_4
  UFG::qVector3 *v4; // rax
  float v5; // xmm11_4
  float v6; // xmm12_4
  float v7; // xmm13_4
  float v8; // xmm6_4
  UFG::Editor::Camera *v9; // rdi
  UFG::BaseCameraComponent *v10; // rax
  signed __int64 v11; // rax
  UFG::BaseCameraComponent *v12; // rax
  signed __int64 v13; // rax
  float v14; // xmm2_4
  __m128 v15; // xmm0
  float v16; // xmm1_4
  float v17; // xmm8_4
  float v18; // xmm1_4
  UFG::qVector3 *v19; // rax
  float v20; // xmm1_4
  UFG::qVector3 *v21; // rax
  float v22; // xmm1_4
  UFG::qVector3 *v23; // rax
  UFG::qVector3 result; // [rsp+30h] [rbp-C8h]
  UFG::qVector3 ndc; // [rsp+40h] [rbp-B8h]
  UFG::Editor::DrawInterface v26; // [rsp+50h] [rbp-A8h]
  __int64 v27; // [rsp+A8h] [rbp-50h]

  v27 = -2i64;
  if ( UFG::Editor::mInitialized )
  {
    v2 = (UFG::Editor::View *)&UFG::Editor::mViews.mNode.mNext[-1].mNext;
    if ( &UFG::Editor::mViews.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
    {
      while ( !v2->mActive )
      {
        v2 = (UFG::Editor::View *)&v2->mNext[-1].mNext;
        if ( v2 == (UFG::Editor::View *)((char *)&UFG::Editor::mViews - 8) )
          return;
      }
      v26.mView = v2;
      v26.mColour = UFG::qColour::Grey;
      *(_QWORD *)&v26.mNormal.x = 0i64;
      *(_QWORD *)&v26.mNormal.z = 0i64;
      v26.mData0 = 0i64;
      LOBYTE(v26.mData1) = 1;
      HIDWORD(v26.mData1) = 1;
      *(_WORD *)&v26.mBackfaceCull = 1;
      *(&v26.mBackfaceCull + 2) = 0;
      v26.vfptr = (UFG::Editor::DrawInterfaceVtbl *)&UFG::Editor::DrawRenderI::`vftable';
      v3 = (float)((float)((float)clientArea->mY + (float)(clientArea->mY + clientArea->mH)) * 0.5)
         / (float)v2->mDrawCtx->mTargetHeight;
      ndc.x = (float)((float)((float)((float)((float)(clientArea->mX + clientArea->mW) + (float)clientArea->mX) * 0.5)
                            * 2.0)
                    / (float)v2->mDrawCtx->mTargetWidth)
            - 1.0;
      ndc.y = (float)((float)(1.0 - v3) * 2.0) - 1.0;
      ndc.z = FLOAT_0_1;
      v4 = UFG::Editor::Utility::NDC_To_World(&result, v2, &ndc);
      v5 = v4->x;
      v6 = v4->y;
      v7 = v4->z;
      ndc.x = v4->x;
      ndc.y = v6;
      ndc.z = v7;
      v8 = atan2f((float)((float)v2->mOptions->mVertFOV * 3.1415927) * 0.0055555557, 2.0);
      v9 = v2->mCamera;
      v10 = UFG::Director::Get()->mCurrentCamera;
      if ( v10 && (v11 = (signed __int64)&v10->mCamera) != 0 && !*(_BYTE *)(v11 + 256) )
      {
        v12 = UFG::Director::Get()->mCurrentCamera;
        if ( v12 )
          v13 = (signed __int64)&v12->mCamera;
        else
          v13 = 0i64;
        v14 = *(float *)(v13 + 176);
        v15 = (__m128)*(unsigned int *)(v13 + 180);
        v16 = *(float *)(v13 + 184);
      }
      else
      {
        v16 = v9->mCamera.v3.z;
        v15 = (__m128)LODWORD(v9->mCamera.v3.y);
        v14 = v9->mCamera.v3.x;
      }
      v15.m128_f32[0] = (float)((float)((float)(v15.m128_f32[0] - v6) * (float)(v15.m128_f32[0] - v6))
                              + (float)((float)(v14 - v5) * (float)(v14 - v5)))
                      + (float)((float)(v16 - v7) * (float)(v16 - v7));
      v17 = COERCE_FLOAT(_mm_sqrt_ps(v15)) * (float)(v8 * 0.075000003);
      LOBYTE(v26.mData1) = 0;
      v26.mBackfaceCull = 0;
      HIDWORD(v26.mData1) = 0;
      v18 = v26.mColour.a;
      v26.mColour = UFG::qColour::Red;
      v26.mColour.a = v18;
      result.x = (float)(UFG::qVector3::msAxisX.x * v17) + v5;
      result.y = (float)(UFG::qVector3::msAxisX.y * v17) + v6;
      result.z = (float)(UFG::qVector3::msAxisX.z * v17) + v7;
      UFG::Editor::Primitive::FlatArrowFilled(&v26, &ndc, &result, 0.039999999);
      result.x = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisX.x) + v5;
      result.y = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisX.y) + v6;
      result.z = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisX.z) + v7;
      v19 = UFG::Editor::Utility::World_To_NDC(
              (UFG::qVector3 *)&v26.mDepthTest,
              v2,
              &result,
              &UFG::qMatrix44::msIdentity,
              0i64);
      Render::DebugDrawContext::DrawTextA(
        v2->mDrawCtx,
        (signed int)(float)((float)((float)(v19->x + 1.0) * (float)v2->mDrawCtx->mTargetWidth) * 0.5) - 3,
        (signed int)(float)((float)(1.0 - (float)((float)(v19->y + 1.0) * 0.5)) * (float)v2->mDrawCtx->mTargetHeight)
      - 4,
        &UFG::qColour::White,
        "x");
      v20 = v26.mColour.a;
      v26.mColour = UFG::qColour::Green;
      v26.mColour.a = v20;
      result.x = (float)(UFG::qVector3::msAxisY.x * v17) + v5;
      result.y = (float)(UFG::qVector3::msAxisY.y * v17) + v6;
      result.z = (float)(UFG::qVector3::msAxisY.z * v17) + v7;
      UFG::Editor::Primitive::FlatArrowFilled(&v26, &ndc, &result, 0.039999999);
      result.x = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisY.x) + v5;
      result.y = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisY.y) + v6;
      result.z = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisY.z) + v7;
      v21 = UFG::Editor::Utility::World_To_NDC(
              (UFG::qVector3 *)&v26.mDepthTest,
              v2,
              &result,
              &UFG::qMatrix44::msIdentity,
              0i64);
      Render::DebugDrawContext::DrawTextA(
        v2->mDrawCtx,
        (signed int)(float)((float)((float)(v21->x + 1.0) * (float)v2->mDrawCtx->mTargetWidth) * 0.5) - 3,
        (signed int)(float)((float)(1.0 - (float)((float)(v21->y + 1.0) * 0.5)) * (float)v2->mDrawCtx->mTargetHeight)
      - 4,
        &UFG::qColour::White,
        "y");
      v22 = v26.mColour.a;
      v26.mColour = UFG::qColour::Blue;
      v26.mColour.a = v22;
      result.x = (float)(UFG::qVector3::msAxisZ.x * v17) + v5;
      result.y = (float)(UFG::qVector3::msAxisZ.y * v17) + v6;
      result.z = (float)(UFG::qVector3::msAxisZ.z * v17) + v7;
      UFG::Editor::Primitive::FlatArrowFilled(&v26, &ndc, &result, 0.039999999);
      result.x = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisZ.x) + v5;
      result.y = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisZ.y) + v6;
      result.z = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisZ.z) + v7;
      v23 = UFG::Editor::Utility::World_To_NDC(
              (UFG::qVector3 *)&v26.mDepthTest,
              v2,
              &result,
              &UFG::qMatrix44::msIdentity,
              0i64);
      Render::DebugDrawContext::DrawTextA(
        v2->mDrawCtx,
        (signed int)(float)((float)((float)(v23->x + 1.0) * (float)v2->mDrawCtx->mTargetWidth) * 0.5) - 3,
        (signed int)(float)((float)(1.0 - (float)((float)(v23->y + 1.0) * 0.5)) * (float)v2->mDrawCtx->mTargetHeight)
      - 4,
        &UFG::qColour::White,
        "z");
    }
  }
}

// File Line: 113
// RVA: 0x201260
void __fastcall UFG::Editor::CompassGadget::CompassGadget(UFG::Editor::CompassGadget *this)
{
  UFG::Editor::CompassGadget *v1; // rbx

  v1 = this;
  UFG::Editor::Gadget::Gadget((UFG::Editor::Gadget *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::CompassGadget", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::CompassGadget::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::CompassGadget::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  UFG::qString::Set(&v1->mTitle, "Compass");
}

// File Line: 124
// RVA: 0x218770
void __fastcall UFG::Editor::CompassGadget::UpdateUI(UFG::Editor::CompassGadget *this, UFG::DUIContext *dui)
{
  UFG::Editor::CompassGadget *v2; // rdi
  UFG::DUIContext *v3; // rbx
  int v4; // eax
  bool v5; // zf
  __int64 v6; // [rsp+20h] [rbp-18h]
  int v7; // [rsp+28h] [rbp-10h]
  int v8; // [rsp+2Ch] [rbp-Ch]

  v2 = this;
  this->mRect.mW = 96;
  this->mRect.mH = 48;
  v3 = dui;
  UFG::DUIContext::BeginVerticalLayout(dui);
  UFG::DUIContext::ToggleButton(v3, "Lock", &UFG::Editor::gOptions.mGlobal->mCompassLock);
  UFG::DUIContext::EndLayoutHorizontal(v3);
  v6 = *(_QWORD *)&v2->mRect.mX;
  v7 = v2->mRect.mW;
  v4 = v2->mRect.mH;
  v8 = 96;
  v5 = v3->mBuildCommandList == 0;
  HIDWORD(v6) += 48;
  if ( !v5 )
    v2->vfptr[2].__vecDelDtor((UFG::qReflectObject *)&v2->vfptr, (unsigned int)&v6);
}

// File Line: 141
// RVA: 0x210F10
void __fastcall UFG::Editor::CompassGadget::Render(UFG::Editor::CompassGadget *this, UFG::DUIRect *clientArea)
{
  UFG::Editor::View *v2; // r15
  float v3; // xmm1_4
  float v4; // xmm14_4
  float v5; // xmm15_4
  float v6; // xmm7_4
  float v7; // xmm14_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  __m128 v10; // xmm2
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm15_4
  float v14; // xmm5_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm11_4
  float v18; // xmm9_4
  float v19; // xmm0_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  char *ST20_8_14; // ST20_8
  float v23; // xmm15_4
  float v24; // xmm14_4
  float v25; // xmm10_4
  float v26; // xmm7_4
  float v27; // xmm6_4
  signed int v28; // edi
  float v29; // xmm11_4
  float v30; // xmm9_4
  float v31; // xmm8_4
  float v32; // xmm10_4
  float v33; // xmm7_4
  float v34; // xmm6_4
  int v35; // er8
  int v36; // edx
  const char *format; // rax
  UFG::qColour *v38; // r9
  float v39; // xmm5_4
  float v40; // xmm13_4
  float v41; // xmm7_4
  float v42; // xmm9_4
  float v43; // xmm12_4
  float v44; // xmm6_4
  float v45; // xmm8_4
  float v46; // xmm4_4
  float v47; // xmm3_4
  int v48; // xmm14_4
  float v49; // xmm2_4
  float v50; // xmm1_4
  float v51; // xmm10_4
  float v52; // xmm5_4
  float v53; // xmm13_4
  float v54; // xmm12_4
  float v55; // xmm1_4
  float v56; // xmm11_4
  float v57; // xmm10_4
  float v58; // xmm9_4
  float v59; // xmm8_4
  float v60; // xmm7_4
  float v61; // xmm6_4
  float v62; // xmm15_4
  char *ST20_8_15; // ST20_8
  signed int v64; // ebx
  signed int v65; // er14
  signed int v66; // edi
  signed int v67; // esi
  float v68; // xmm12_4
  float v69; // xmm11_4
  float v70; // xmm13_4
  float v71; // xmm10_4
  float v72; // xmm14_4
  float v73; // xmm1_4
  float v74; // xmm15_4
  float v75; // xmm8_4
  float v76; // xmm7_4
  float v77; // xmm6_4
  float v78; // ST34_4
  char *ST20_8_15a; // ST20_8
  char *ST20_8_15b; // ST20_8
  float v81; // [rsp+30h] [rbp-A8h]
  float v82; // [rsp+34h] [rbp-A4h]
  float v83; // [rsp+38h] [rbp-A0h]
  float v84; // [rsp+3Ch] [rbp-9Ch]
  float v85; // [rsp+40h] [rbp-98h]
  float v86; // [rsp+44h] [rbp-94h]
  float v87; // [rsp+48h] [rbp-90h]
  float v88; // [rsp+4Ch] [rbp-8Ch]
  float v89; // [rsp+50h] [rbp-88h]
  float v90; // [rsp+54h] [rbp-84h]
  UFG::qMatrix44 dest; // [rsp+58h] [rbp-80h]
  float v92; // [rsp+98h] [rbp-40h]
  float v93; // [rsp+9Ch] [rbp-3Ch]
  float v94; // [rsp+A0h] [rbp-38h]
  UFG::Editor::DrawInterface v95; // [rsp+A8h] [rbp-30h]
  UFG::qVector3 center; // [rsp+F8h] [rbp+20h]
  float v97; // [rsp+108h] [rbp+30h]
  UFG::qColour v98; // [rsp+10Ch] [rbp+34h]
  __int64 v99; // [rsp+120h] [rbp+48h]
  float v100; // [rsp+208h] [rbp+130h]
  float vars0; // [rsp+210h] [rbp+138h]

  v99 = -2i64;
  if ( UFG::Editor::mInitialized )
  {
    v2 = (UFG::Editor::View *)&UFG::Editor::mViews.mNode.mNext[-1].mNext;
    if ( &UFG::Editor::mViews.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
    {
      while ( !v2->mActive )
      {
        v2 = (UFG::Editor::View *)&v2->mNext[-1].mNext;
        if ( v2 == (UFG::Editor::View *)((char *)&UFG::Editor::mViews - 8) )
          return;
      }
      v95.mView = v2;
      v95.mColour = UFG::qColour::Grey;
      *(_QWORD *)&v95.mNormal.x = 0i64;
      v95.mNormal.z = 1.0;
      v95.mData0 = 0i64;
      v95.mData1 = 0i64;
      v95.mBackfaceCull = 1;
      v95.mBlendMode = 1;
      *(_WORD *)&v95.mDepthTest = 1;
      v95.mOverlay = 0;
      v95.vfptr = (UFG::Editor::DrawInterfaceVtbl *)&UFG::Editor::DrawRenderI::`vftable';
      v3 = (float)clientArea->mX;
      v4 = (float)(clientArea->mX + clientArea->mW);
      v5 = (float)((float)clientArea->mY + (float)(clientArea->mY + clientArea->mH)) * 0.5;
      v82 = v5;
      v6 = (float)(v3 + v4) * 0.5;
      v100 = (float)(v3 + v4) * 0.5;
      center.x = (float)(v3 + v4) * 0.5;
      center.y = v5;
      center.z = 0.0;
      v7 = (float)(v4 - v3) * 0.5;
      v81 = v7;
      v95.mDepthTest = 0;
      *(_QWORD *)&v98.r = 4510805389542529434i64;
      *(_QWORD *)&v98.b = __PAIR__(1065353216, LODWORD(FLOAT_0_69999999));
      v95.mColour = v98;
      v95.mColour.a = UFG::qColour::Grey.a;
      UFG::Editor::Primitive::CircleSCR(&v95, &center, v7);
      UFG::Editor::Camera::GetDirForward(v2->mCamera, &center);
      if ( COERCE_FLOAT(LODWORD(center.x) & _xmm) > 0.000099999997
        || COERCE_FLOAT(LODWORD(center.y) & _xmm) > 0.000099999997 )
      {
        v10 = (__m128)LODWORD(center.y);
        v10.m128_f32[0] = (float)(center.y * center.y) + (float)(center.x * center.x);
        if ( v10.m128_f32[0] == 0.0 )
          v11 = 0.0;
        else
          v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
        v9 = v11 * center.y;
        v8 = center.x * v11;
      }
      else
      {
        v8 = *(float *)&FLOAT_1_0;
        v9 = 0.0;
      }
      v12 = atan2f(v9, v8);
      UFG::qRotationMatrixZ(&dest, v12);
      if ( UFG::Editor::gOptions.mGlobal->mCompassLock )
      {
        v13 = v5 + (float)(v7 * 0.5);
        LODWORD(v14) = COERCE_UNSIGNED_INT(v7 * 0.2) ^ _xmm[0];
        LODWORD(v15) = COERCE_UNSIGNED_INT(v7 * 0.2) ^ _xmm[0];
        v16 = v95.mColour.a;
        v95.mColour = UFG::qColour::Red;
        v95.mColour.a = v16;
        v17 = v13 + v15;
        v18 = v6 + (float)(v7 * 0.25);
        v19 = v6 + (float)(v7 * 0.0);
        v20 = v13 + v14;
        v21 = v100 + (float)(v7 * -0.25);
        v83 = v100 + (float)(v7 * -0.25);
        v84 = v13 + v14;
        v85 = v7 * 0.0;
        v86 = v19;
        v87 = v13 + COERCE_FLOAT(LODWORD(v7) ^ _xmm[0]);
        v88 = v7 * 0.0;
        v89 = v18;
        v90 = v13 + v15;
        dest.v0.x = v7 * 0.0;
        dest.v0.y = v100 + (float)(v7 * -0.25);
        dest.v0.z = v13 + v14;
        dest.v0.w = v7 * 0.0;
        v95.vfptr->DrawSCR(&v95, PrimMode_LineStrip, 1u, &v83, 4);
        v95.mColour.a = 0.5;
        v83 = v21;
        v84 = v20;
        v85 = v7 * 0.0;
        v86 = (float)(v7 * 0.0) + v100;
        v87 = v13 + COERCE_FLOAT(LODWORD(v7) ^ _xmm[0]);
        v88 = v7 * 0.0;
        v89 = v18;
        v90 = v17;
        dest.v0.x = v7 * 0.0;
        LODWORD(ST20_8_14) = 3;
        v95.vfptr->DrawSCR(&v95, PrimMode_TriStrip, 1u, &v83, (int)ST20_8_14);
        v95.mColour.a = 1.0;
        v23 = v13 - (float)(v7 * 0.5);
        v24 = v7 * 0.80000001;
        v25 = (float)((float)(dest.v1.x * v24) + (float)(dest.v0.x * 0.0)) + (float)(dest.v2.x * 0.0);
        v26 = (float)((float)(dest.v1.y * v24) + (float)(dest.v0.y * 0.0)) + (float)(dest.v2.y * 0.0);
        v27 = (float)((float)(dest.v1.z * v24) + (float)(dest.v0.z * 0.0)) + (float)(dest.v2.z * 0.0);
        v28 = (signed int)v100;
        Render::DebugDrawContext::DrawTextA(
          v2->mDrawCtx,
          (signed int)v100 - (signed int)v25 - 3,
          (signed int)v23 - (signed int)v26 - 4,
          &UFG::qColour::White,
          "N");
        UFG::qRotationMatrixZ(&dest, 1.5707964);
        v29 = (float)((float)(dest.v1.x * v26) + (float)(dest.v0.x * v25)) + (float)(dest.v2.x * v27);
        v30 = (float)((float)(dest.v1.y * v26) + (float)(dest.v0.y * v25)) + (float)(dest.v2.y * v27);
        v31 = (float)((float)(dest.v1.z * v26) + (float)(dest.v0.z * v25)) + (float)(dest.v2.z * v27);
        Render::DebugDrawContext::DrawTextA(
          v2->mDrawCtx,
          v28 - (signed int)v29 - 3,
          (signed int)v23 - (signed int)v30 - 4,
          &UFG::qColour::White,
          "E");
        v32 = (float)((float)(dest.v1.x * v30) + (float)(dest.v0.x * v29)) + (float)(dest.v2.x * v31);
        v33 = (float)((float)(dest.v1.y * v30) + (float)(dest.v0.y * v29)) + (float)(dest.v2.y * v31);
        v34 = (float)((float)(dest.v1.z * v30) + (float)(dest.v0.z * v29)) + (float)(dest.v2.z * v31);
        Render::DebugDrawContext::DrawTextA(
          v2->mDrawCtx,
          v28 - (signed int)v32 - 3,
          (signed int)v23 - (signed int)v33 - 4,
          &UFG::qColour::White,
          "S");
        v35 = (signed int)v23
            - (signed int)(float)((float)((float)(dest.v1.y * v33) + (float)(dest.v0.y * v32)) + (float)(dest.v2.y * v34))
            - 4;
        v36 = v28
            - (signed int)(float)((float)((float)(dest.v1.x * v33) + (float)(dest.v0.x * v32)) + (float)(dest.v2.x * v34))
            - 3;
        format = "W";
        v38 = &UFG::qColour::White;
      }
      else
      {
        v39 = v7 * 0.0;
        v40 = dest.v1.x;
        v41 = dest.v1.x * (float)(v7 * 0.2);
        v42 = dest.v2.x * (float)(v7 * 0.0);
        v92 = (float)((float)(dest.v0.x * (float)(v7 * -0.25)) + v41) + v42;
        v43 = dest.v1.y;
        v44 = dest.v1.y * (float)(v7 * 0.2);
        v45 = dest.v2.y * (float)(v7 * 0.0);
        v94 = (float)((float)(dest.v0.y * (float)(v7 * -0.25)) + v44) + v45;
        v46 = dest.v0.y * (float)(v7 * 0.2);
        v47 = dest.v2.z * (float)(v7 * 0.0);
        *(float *)&v48 = (float)((float)(dest.v0.z * (float)(v7 * -0.25)) + v46)
                       + (float)(dest.v2.z * (float)(v7 * 0.0));
        v97 = *(float *)&v48;
        v49 = dest.v0.x * v39;
        dest.v1.y = (float)((float)(dest.v1.x * v81) + (float)(dest.v0.x * v39)) + v42;
        v50 = dest.v0.y * v39;
        v93 = (float)((float)(v43 * v81) + (float)(dest.v0.y * v39)) + v45;
        dest.v1.x = (float)((float)(dest.v0.y * v81) + (float)(dest.v0.z * v39)) + (float)(dest.v2.z * v39);
        v51 = (float)((float)(dest.v0.x * (float)(v81 * 0.25)) + v41) + v42;
        vars0 = v51;
        v52 = (float)((float)(dest.v0.y * (float)(v81 * 0.25)) + v44) + v45;
        dest.v1.z = (float)((float)(dest.v0.y * (float)(v81 * 0.25)) + v44) + v45;
        dest.v1.w = (float)((float)(dest.v0.z * (float)(v81 * 0.25)) + v46) + v47;
        v53 = (float)((float)(v40 * (float)(v81 * 0.5)) + v49) + v42;
        v54 = (float)((float)(v43 * (float)(v81 * 0.5)) + v50) + v45;
        v55 = v95.mColour.a;
        v95.mColour = UFG::qColour::White;
        v95.mColour.a = v55;
        v56 = v52 + v5;
        v57 = v51 + v100;
        v58 = v5 + v93;
        v59 = v100 + dest.v1.y;
        v60 = v5 + v94;
        v61 = v100 + v92;
        v83 = v100 + v92;
        v84 = v5 + v94;
        v85 = *(float *)&v48;
        v86 = v100 + dest.v1.y;
        v87 = v5 + v93;
        v62 = dest.v1.x;
        v88 = dest.v1.x;
        v89 = v57;
        v90 = v52 + v82;
        dest.v0.x = (float)((float)(dest.v0.z * (float)(v81 * 0.25)) + v46) + v47;
        dest.v0.y = v100 + v92;
        dest.v0.z = v82 + v94;
        LODWORD(dest.v0.w) = v48;
        v95.vfptr->DrawSCR(&v95, PrimMode_LineStrip, 1u, &v83, 4);
        v95.mColour.a = 0.5;
        v83 = v61;
        v84 = v60;
        v85 = *(float *)&v48;
        v86 = v59;
        v87 = v58;
        v88 = v62;
        v89 = v57;
        v90 = v56;
        dest.v0.x = dest.v1.w;
        LODWORD(ST20_8_15) = 3;
        v95.vfptr->DrawSCR(&v95, PrimMode_TriStrip, 1u, &v83, (int)ST20_8_15);
        v95.mColour.a = 1.0;
        v64 = (signed int)v54;
        v65 = (signed int)v82;
        v66 = (signed int)v53;
        v67 = (signed int)v100;
        Render::DebugDrawContext::DrawTextA(
          v2->mDrawCtx,
          (signed int)v53 + (signed int)v100 - 3,
          (signed int)v54 + (signed int)v82 - 4,
          &UFG::qColour::White,
          "S");
        UFG::qRotationMatrixZ(&dest, 3.1415927);
        v68 = (float)((float)(dest.v1.x * v94) + (float)(dest.v0.x * v92)) + (float)(dest.v2.x * *(float *)&v48);
        v69 = (float)((float)(dest.v1.y * v94) + (float)(dest.v0.y * v92)) + (float)(dest.v2.y * *(float *)&v48);
        v70 = (float)((float)(dest.v1.z * v94) + (float)(dest.v0.z * v92)) + (float)(dest.v2.z * v97);
        v71 = (float)((float)(dest.v1.z * v93) + (float)(dest.v0.z * dest.v1.y)) + (float)(dest.v2.z * dest.v1.x);
        v72 = (float)((float)(dest.v1.z * dest.v1.z) + (float)(dest.v0.z * vars0)) + (float)(dest.v2.z * dest.v1.w);
        v73 = v95.mColour.a;
        v95.mColour = UFG::qColour::Red;
        v95.mColour.a = v73;
        v74 = (float)((float)((float)(dest.v1.y * dest.v1.z) + (float)(dest.v0.y * vars0))
                    + (float)(dest.v2.y * dest.v1.w))
            + v82;
        v75 = (float)((float)((float)(dest.v1.x * dest.v1.z) + (float)(dest.v0.x * vars0))
                    + (float)(dest.v2.x * dest.v1.w))
            + v100;
        v76 = v82
            + (float)((float)((float)(dest.v0.y * dest.v1.y) + (float)(dest.v1.y * v93)) + (float)(dest.v2.y * dest.v1.x));
        v77 = v100
            + (float)((float)((float)(dest.v1.x * v93) + (float)(dest.v0.x * dest.v1.y)) + (float)(dest.v2.x * dest.v1.x));
        v78 = v82 + v69;
        v100 = v100 + v68;
        v83 = v100;
        v84 = v78;
        v85 = v70;
        v86 = v77;
        v87 = v76;
        v88 = (float)((float)(dest.v1.z * v93) + (float)(dest.v0.z * dest.v1.y)) + (float)(dest.v2.z * dest.v1.x);
        v89 = v75;
        v90 = v74;
        dest.v0.x = (float)((float)(dest.v1.z * dest.v1.z) + (float)(dest.v0.z * vars0))
                  + (float)(dest.v2.z * dest.v1.w);
        dest.v0.y = v100;
        dest.v0.z = v78;
        dest.v0.w = v70;
        LODWORD(ST20_8_15a) = 4;
        v95.vfptr->DrawSCR(&v95, PrimMode_LineStrip, 1u, &v83, (int)ST20_8_15a);
        v95.mColour.a = 0.5;
        v83 = v100;
        v84 = v78;
        v85 = v70;
        v86 = v77;
        v87 = v76;
        v88 = v71;
        v89 = v75;
        v90 = v74;
        dest.v0.x = v72;
        LODWORD(ST20_8_15b) = 3;
        v95.vfptr->DrawSCR(&v95, PrimMode_TriStrip, 1u, &v83, (int)ST20_8_15b);
        v95.mColour.a = 1.0;
        v35 = v65 - v64 - 4;
        v36 = v67 - v66 - 3;
        format = "N";
        v38 = &UFG::qColour::Red;
      }
      Render::DebugDrawContext::DrawTextA(v2->mDrawCtx, v36, v35, v38, format);
    }
  }
}

