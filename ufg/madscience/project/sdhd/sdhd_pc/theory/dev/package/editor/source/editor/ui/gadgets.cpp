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
    &UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::sInventory,
    "UFG::Editor::OrientationGadget",
    v0);
  UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::OrientationGadget>::`vftable;
  UFG::qReflectInventory<UFG::Editor::OrientationGadget>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    &UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::OrientationGadget_UFG::Editor::Gadget_::sInventory__);
}

// File Line: 26
// RVA: 0x146CD40
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::CompassGadget_UFG::Editor::Gadget_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::CompassGadget", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::sInventory,
    "UFG::Editor::CompassGadget",
    v0);
  UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::CompassGadget>::`vftable;
  UFG::qReflectInventory<UFG::Editor::CompassGadget>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::CompassGadget_UFG::Editor::Gadget_::sInventory__);
}

// File Line: 32
// RVA: 0x2017E0
void __fastcall UFG::Editor::Gadget::Gadget(UFG::Editor::Gadget *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::Gadget", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Gadget::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Gadget::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mStyle = Style_CloseButton|Style_ShowTitleText|Style_ShowTitleBar|Style_ShowBorder;
  UFG::qString::Set(&this->mTitle, "Gadget");
}

// File Line: 39
// RVA: 0x203370
void __fastcall UFG::Editor::Gadget::~Gadget(UFG::Editor::Gadget *this)
{
  this->UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Gadget::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Gadget::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::DUIWindow::~DUIWindow(this);
}

// File Line: 49
// RVA: 0x201E00
void __fastcall UFG::Editor::OrientationGadget::OrientationGadget(UFG::Editor::OrientationGadget *this)
{
  UFG::Editor::Gadget::Gadget(this);
  this->UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::OrientationGadget", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::OrientationGadget::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::OrientationGadget::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::Set(&this->mTitle, "Orient");
}

// File Line: 60
// RVA: 0x21AB20
void __fastcall UFG::Editor::OrientationGadget::UpdateUI(UFG::Editor::OrientationGadget *this, UFG::DUIContext *dui)
{
  bool v2; // zf
  __int64 v3; // [rsp+20h] [rbp-18h] BYREF
  int mW; // [rsp+28h] [rbp-10h]
  int v5; // [rsp+2Ch] [rbp-Ch]

  this->mRect.mW = 96;
  this->mRect.mH = 24;
  v3 = *(_QWORD *)&this->mRect.mX;
  mW = this->mRect.mW;
  v5 = 96;
  v2 = !dui->mBuildCommandList;
  HIDWORD(v3) += 24;
  if ( !v2 )
    this->UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr[2].__vecDelDtor(
      this,
      (unsigned int)&v3);
}

// File Line: 73
// RVA: 0x211C40
void __fastcall UFG::Editor::OrientationGadget::Render(UFG::Editor::OrientationGadget *this, UFG::DUIRect *clientArea)
{
  UFG::Editor::View *p_mNext; // rbx
  float v3; // xmm1_4
  UFG::qVector3 *v4; // rax
  float x; // xmm11_4
  float y; // xmm12_4
  float z; // xmm13_4
  float v8; // xmm6_4
  UFG::Editor::Camera *mCamera; // rdi
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *v11; // rax
  UFG::BaseCameraComponent *v12; // rax
  UFG::Camera *p_mCamera; // rax
  float v14; // xmm2_4
  __m128 y_low; // xmm0
  float v16; // xmm1_4
  float v17; // xmm8_4
  float a; // xmm1_4
  UFG::qVector3 *v19; // rax
  float v20; // xmm1_4
  UFG::qVector3 *v21; // rax
  float v22; // xmm1_4
  UFG::qVector3 *v23; // rax
  UFG::qVector3 result; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qVector3 ndc; // [rsp+40h] [rbp-B8h] BYREF
  UFG::Editor::DrawInterface v26; // [rsp+50h] [rbp-A8h] BYREF
  __int64 v27; // [rsp+A8h] [rbp-50h]

  v27 = -2i64;
  if ( UFG::Editor::mInitialized )
  {
    p_mNext = (UFG::Editor::View *)&UFG::Editor::mViews.mNode.mNext[-1].mNext;
    if ( &UFG::Editor::mViews.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
    {
      while ( !p_mNext->mActive )
      {
        p_mNext = (UFG::Editor::View *)&p_mNext->mNext[-1].mNext;
        if ( p_mNext == (UFG::Editor::View *)((char *)&UFG::Editor::mViews - 8) )
          return;
      }
      v26.mView = p_mNext;
      v26.mColour = UFG::qColour::Grey;
      memset(&v26.mNormal, 0, 24);
      LOBYTE(v26.mData1) = 1;
      HIDWORD(v26.mData1) = 1;
      *(_WORD *)&v26.mBackfaceCull = 1;
      *(&v26.mBackfaceCull + 2) = 0;
      v26.vfptr = (UFG::Editor::DrawInterfaceVtbl *)&UFG::Editor::DrawRenderI::`vftable;
      v3 = (float)((float)(1.0
                         - (float)((float)((float)((float)clientArea->mY + (float)(clientArea->mY + clientArea->mH))
                                         * 0.5)
                                 / (float)p_mNext->mDrawCtx->mTargetHeight))
                 * 2.0)
         - 1.0;
      ndc.x = (float)((float)((float)((float)((float)(clientArea->mX + clientArea->mW) + (float)clientArea->mX) * 0.5)
                            * 2.0)
                    / (float)p_mNext->mDrawCtx->mTargetWidth)
            - 1.0;
      ndc.y = v3;
      ndc.z = FLOAT_0_1;
      v4 = UFG::Editor::Utility::NDC_To_World(&result, p_mNext, &ndc);
      x = v4->x;
      y = v4->y;
      z = v4->z;
      ndc.x = v4->x;
      ndc.y = y;
      ndc.z = z;
      v8 = atan2f((float)((float)p_mNext->mOptions->mVertFOV * 3.1415927) * 0.0055555557, 2.0);
      mCamera = p_mNext->mCamera;
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera && (v11 = &mCurrentCamera->mCamera) != 0i64 && !v11->bUseOverrideMatrices )
      {
        v12 = UFG::Director::Get()->mCurrentCamera;
        if ( v12 )
          p_mCamera = &v12->mCamera;
        else
          p_mCamera = 0i64;
        v14 = p_mCamera->mTransformation.v3.x;
        y_low = (__m128)LODWORD(p_mCamera->mTransformation.v3.y);
        v16 = p_mCamera->mTransformation.v3.z;
      }
      else
      {
        v16 = mCamera->mCamera.v3.z;
        y_low = (__m128)LODWORD(mCamera->mCamera.v3.y);
        v14 = mCamera->mCamera.v3.x;
      }
      y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                                + (float)((float)(v14 - x) * (float)(v14 - x)))
                        + (float)((float)(v16 - z) * (float)(v16 - z));
      v17 = _mm_sqrt_ps(y_low).m128_f32[0] * (float)(v8 * 0.075000003);
      LOBYTE(v26.mData1) = 0;
      v26.mBackfaceCull = 0;
      HIDWORD(v26.mData1) = 0;
      a = v26.mColour.a;
      v26.mColour = UFG::qColour::Red;
      v26.mColour.a = a;
      result.x = (float)(UFG::qVector3::msAxisX.x * v17) + x;
      result.y = (float)(UFG::qVector3::msAxisX.y * v17) + y;
      result.z = (float)(UFG::qVector3::msAxisX.z * v17) + z;
      UFG::Editor::Primitive::FlatArrowFilled(&v26, &ndc, &result, 0.039999999);
      result.x = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisX.x) + x;
      result.y = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisX.y) + y;
      result.z = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisX.z) + z;
      v19 = UFG::Editor::Utility::World_To_NDC(
              (UFG::qVector3 *)&v26.mDepthTest,
              p_mNext,
              &result,
              &UFG::qMatrix44::msIdentity,
              0i64);
      Render::DebugDrawContext::DrawTextA(
        p_mNext->mDrawCtx,
        (int)(float)((float)((float)(v19->x + 1.0) * (float)p_mNext->mDrawCtx->mTargetWidth) * 0.5) - 3,
        (int)(float)((float)(1.0 - (float)((float)(v19->y + 1.0) * 0.5)) * (float)p_mNext->mDrawCtx->mTargetHeight) - 4,
        &UFG::qColour::White,
        "x");
      v20 = v26.mColour.a;
      v26.mColour = UFG::qColour::Green;
      v26.mColour.a = v20;
      result.x = (float)(UFG::qVector3::msAxisY.x * v17) + x;
      result.y = (float)(UFG::qVector3::msAxisY.y * v17) + y;
      result.z = (float)(UFG::qVector3::msAxisY.z * v17) + z;
      UFG::Editor::Primitive::FlatArrowFilled(&v26, &ndc, &result, 0.039999999);
      result.x = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisY.x) + x;
      result.y = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisY.y) + y;
      result.z = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisY.z) + z;
      v21 = UFG::Editor::Utility::World_To_NDC(
              (UFG::qVector3 *)&v26.mDepthTest,
              p_mNext,
              &result,
              &UFG::qMatrix44::msIdentity,
              0i64);
      Render::DebugDrawContext::DrawTextA(
        p_mNext->mDrawCtx,
        (int)(float)((float)((float)(v21->x + 1.0) * (float)p_mNext->mDrawCtx->mTargetWidth) * 0.5) - 3,
        (int)(float)((float)(1.0 - (float)((float)(v21->y + 1.0) * 0.5)) * (float)p_mNext->mDrawCtx->mTargetHeight) - 4,
        &UFG::qColour::White,
        "y");
      v22 = v26.mColour.a;
      v26.mColour = UFG::qColour::Blue;
      v26.mColour.a = v22;
      result.x = (float)(UFG::qVector3::msAxisZ.x * v17) + x;
      result.y = (float)(UFG::qVector3::msAxisZ.y * v17) + y;
      result.z = (float)(UFG::qVector3::msAxisZ.z * v17) + z;
      UFG::Editor::Primitive::FlatArrowFilled(&v26, &ndc, &result, 0.039999999);
      result.x = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisZ.x) + x;
      result.y = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisZ.y) + y;
      result.z = (float)((float)(v17 * 0.60000002) * UFG::qVector3::msAxisZ.z) + z;
      v23 = UFG::Editor::Utility::World_To_NDC(
              (UFG::qVector3 *)&v26.mDepthTest,
              p_mNext,
              &result,
              &UFG::qMatrix44::msIdentity,
              0i64);
      Render::DebugDrawContext::DrawTextA(
        p_mNext->mDrawCtx,
        (int)(float)((float)((float)(v23->x + 1.0) * (float)p_mNext->mDrawCtx->mTargetWidth) * 0.5) - 3,
        (int)(float)((float)(1.0 - (float)((float)(v23->y + 1.0) * 0.5)) * (float)p_mNext->mDrawCtx->mTargetHeight) - 4,
        &UFG::qColour::White,
        "z");
    }
  }
}

// File Line: 113
// RVA: 0x201260
void __fastcall UFG::Editor::CompassGadget::CompassGadget(UFG::Editor::CompassGadget *this)
{
  UFG::Editor::Gadget::Gadget(this);
  this->UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::CompassGadget", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::CompassGadget::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::CompassGadget::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::Set(&this->mTitle, "Compass");
}

// File Line: 124
// RVA: 0x218770
void __fastcall UFG::Editor::CompassGadget::UpdateUI(UFG::Editor::CompassGadget *this, UFG::DUIContext *dui)
{
  bool v4; // zf
  __int64 v5; // [rsp+20h] [rbp-18h] BYREF
  int mW; // [rsp+28h] [rbp-10h]
  int v7; // [rsp+2Ch] [rbp-Ch]

  this->mRect.mW = 96;
  this->mRect.mH = 48;
  UFG::DUIContext::BeginVerticalLayout(dui);
  UFG::DUIContext::ToggleButton(dui, "Lock", &UFG::Editor::gOptions.mGlobal->mCompassLock);
  UFG::DUIContext::EndLayoutHorizontal(dui);
  v5 = *(_QWORD *)&this->mRect.mX;
  mW = this->mRect.mW;
  v7 = 96;
  v4 = !dui->mBuildCommandList;
  HIDWORD(v5) += 48;
  if ( !v4 )
    this->UFG::qReflectObjectType<UFG::Editor::CompassGadget,UFG::Editor::Gadget>::UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr[2].__vecDelDtor(
      this,
      (unsigned int)&v5);
}

// File Line: 141
// RVA: 0x210F10
void __fastcall UFG::Editor::CompassGadget::Render(UFG::Editor::CompassGadget *this, UFG::DUIRect *clientArea)
{
  UFG::Editor::View *p_mNext; // r15
  float mX; // xmm1_4
  float v4; // xmm14_4
  float v5; // xmm15_4
  float v6; // xmm7_4
  float v7; // xmm14_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  __m128 y_low; // xmm2
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm15_4
  float a; // xmm1_4
  float v15; // xmm6_4
  float v16; // xmm15_4
  float v17; // xmm14_4
  float v18; // xmm10_4
  float v19; // xmm7_4
  float v20; // xmm6_4
  int v21; // edi
  float v22; // xmm11_4
  float v23; // xmm9_4
  float v24; // xmm8_4
  float v25; // xmm10_4
  float v26; // xmm7_4
  float v27; // xmm6_4
  float v28; // xmm5_4
  float x; // xmm13_4
  float v30; // xmm7_4
  float v31; // xmm9_4
  float y; // xmm12_4
  float v33; // xmm6_4
  float v34; // xmm8_4
  float v35; // xmm4_4
  int v36; // xmm14_4
  float v37; // xmm13_4
  float v38; // xmm12_4
  float v39; // xmm1_4
  float v40; // xmm11_4
  float v41; // xmm10_4
  float v42; // xmm9_4
  float v43; // xmm8_4
  float v44; // xmm7_4
  float v45; // xmm6_4
  float v46; // xmm15_4
  int v47; // ebx
  int v48; // r14d
  int v49; // edi
  int v50; // esi
  float v51; // xmm12_4
  float v52; // xmm11_4
  float v53; // xmm13_4
  float v54; // xmm10_4
  float v55; // xmm14_4
  float v56; // xmm1_4
  float v57; // xmm15_4
  float v58; // xmm8_4
  float v59; // xmm7_4
  float v60; // xmm6_4
  float v61; // [rsp+30h] [rbp-A8h]
  float v62; // [rsp+34h] [rbp-A4h]
  float v63; // [rsp+34h] [rbp-A4h]
  float v64; // [rsp+38h] [rbp-A0h] BYREF
  float v65; // [rsp+3Ch] [rbp-9Ch]
  float v66; // [rsp+40h] [rbp-98h]
  float v67; // [rsp+44h] [rbp-94h]
  float v68; // [rsp+48h] [rbp-90h]
  float v69; // [rsp+4Ch] [rbp-8Ch]
  float v70; // [rsp+50h] [rbp-88h]
  float v71; // [rsp+54h] [rbp-84h]
  UFG::qMatrix44 dest; // [rsp+58h] [rbp-80h] BYREF
  float v73; // [rsp+98h] [rbp-40h]
  float v74; // [rsp+9Ch] [rbp-3Ch]
  float v75; // [rsp+A0h] [rbp-38h]
  UFG::Editor::DrawInterface v76; // [rsp+A8h] [rbp-30h] BYREF
  UFG::qVector3 center; // [rsp+F8h] [rbp+20h] BYREF
  float v78; // [rsp+108h] [rbp+30h]
  UFG::qColour v79; // [rsp+10Ch] [rbp+34h]
  __int64 v80; // [rsp+120h] [rbp+48h]
  float v81; // [rsp+208h] [rbp+130h]
  float vars0; // [rsp+210h] [rbp+138h]

  v80 = -2i64;
  if ( UFG::Editor::mInitialized )
  {
    p_mNext = (UFG::Editor::View *)&UFG::Editor::mViews.mNode.mNext[-1].mNext;
    if ( &UFG::Editor::mViews.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
    {
      while ( !p_mNext->mActive )
      {
        p_mNext = (UFG::Editor::View *)&p_mNext->mNext[-1].mNext;
        if ( p_mNext == (UFG::Editor::View *)((char *)&UFG::Editor::mViews - 8) )
          return;
      }
      v76.mView = p_mNext;
      v76.mColour = UFG::qColour::Grey;
      *(_QWORD *)&v76.mNormal.x = 0i64;
      v76.mNormal.z = 1.0;
      v76.mData0 = 0i64;
      v76.mData1 = 0i64;
      v76.mBackfaceCull = 1;
      v76.mBlendMode = BlendMode_SrcAlpha_OneMinusSrcAlpha;
      *(_WORD *)&v76.mDepthTest = 1;
      v76.mOverlay = 0;
      v76.vfptr = (UFG::Editor::DrawInterfaceVtbl *)&UFG::Editor::DrawRenderI::`vftable;
      mX = (float)clientArea->mX;
      v4 = (float)(clientArea->mX + clientArea->mW);
      v5 = (float)((float)clientArea->mY + (float)(clientArea->mY + clientArea->mH)) * 0.5;
      v62 = v5;
      v6 = (float)(mX + v4) * 0.5;
      v81 = v6;
      center.x = v6;
      center.y = v5;
      center.z = 0.0;
      v7 = (float)(v4 - mX) * 0.5;
      v61 = v7;
      v76.mDepthTest = 0;
      *(_QWORD *)&v79.r = 0x3E99999A3E99999Ai64;
      *(_QWORD *)&v79.b = LODWORD(FLOAT_0_69999999) | 0x3F80000000000000i64;
      v76.mColour = v79;
      v76.mColour.a = UFG::qColour::Grey.a;
      UFG::Editor::Primitive::CircleSCR(&v76, &center, v7);
      UFG::Editor::Camera::GetDirForward(p_mNext->mCamera, &center);
      if ( COERCE_FLOAT(LODWORD(center.x) & _xmm) > 0.000099999997
        || COERCE_FLOAT(LODWORD(center.y) & _xmm) > 0.000099999997 )
      {
        y_low = (__m128)LODWORD(center.y);
        y_low.m128_f32[0] = (float)(center.y * center.y) + (float)(center.x * center.x);
        if ( y_low.m128_f32[0] == 0.0 )
          v11 = 0.0;
        else
          v11 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
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
        a = v76.mColour.a;
        v76.mColour = UFG::qColour::Red;
        v76.mColour.a = a;
        v15 = v81 + (float)(v7 * -0.25);
        v64 = v15;
        v65 = v13 + COERCE_FLOAT(COERCE_UNSIGNED_INT(v7 * 0.2) ^ _xmm[0]);
        v66 = v7 * 0.0;
        v67 = v6 + (float)(v7 * 0.0);
        v68 = v13 + COERCE_FLOAT(LODWORD(v7) ^ _xmm[0]);
        v69 = v7 * 0.0;
        v70 = v6 + (float)(v7 * 0.25);
        v71 = v65;
        dest.v0.x = v7 * 0.0;
        dest.v0.y = v15;
        dest.v0.z = v65;
        dest.v0.w = v7 * 0.0;
        v76.vfptr->DrawSCR(&v76, PrimMode_LineStrip, 1u, &v64, 4);
        v76.mColour.a = 0.5;
        v64 = v15;
        v65 = v13 + COERCE_FLOAT(COERCE_UNSIGNED_INT(v7 * 0.2) ^ _xmm[0]);
        v66 = v7 * 0.0;
        v67 = (float)(v7 * 0.0) + v81;
        v68 = v13 + COERCE_FLOAT(LODWORD(v7) ^ _xmm[0]);
        v69 = v7 * 0.0;
        v70 = v6 + (float)(v7 * 0.25);
        v71 = v65;
        dest.v0.x = v7 * 0.0;
        v76.vfptr->DrawSCR(&v76, PrimMode_TriStrip, 1u, &v64, 3);
        v76.mColour.a = 1.0;
        v16 = v13 - (float)(v7 * 0.5);
        v17 = v7 * 0.80000001;
        v18 = (float)((float)(dest.v1.x * v17) + (float)(dest.v0.x * 0.0)) + (float)(dest.v2.x * 0.0);
        v19 = (float)((float)(dest.v1.y * v17) + (float)(dest.v0.y * 0.0)) + (float)(dest.v2.y * 0.0);
        v20 = (float)((float)(dest.v1.z * v17) + (float)(dest.v0.z * 0.0)) + (float)(dest.v2.z * 0.0);
        v21 = (int)v81;
        Render::DebugDrawContext::DrawTextA(
          p_mNext->mDrawCtx,
          (int)v81 - (int)v18 - 3,
          (int)v16 - (int)v19 - 4,
          &UFG::qColour::White,
          "N");
        UFG::qRotationMatrixZ(&dest, 1.5707964);
        v22 = (float)((float)(dest.v1.x * v19) + (float)(dest.v0.x * v18)) + (float)(dest.v2.x * v20);
        v23 = (float)((float)(dest.v1.y * v19) + (float)(dest.v0.y * v18)) + (float)(dest.v2.y * v20);
        v24 = (float)((float)(dest.v1.z * v19) + (float)(dest.v0.z * v18)) + (float)(dest.v2.z * v20);
        Render::DebugDrawContext::DrawTextA(
          p_mNext->mDrawCtx,
          v21 - (int)v22 - 3,
          (int)v16 - (int)v23 - 4,
          &UFG::qColour::White,
          "E");
        v25 = (float)((float)(dest.v1.x * v23) + (float)(dest.v0.x * v22)) + (float)(dest.v2.x * v24);
        v26 = (float)((float)(dest.v1.y * v23) + (float)(dest.v0.y * v22)) + (float)(dest.v2.y * v24);
        v27 = (float)((float)(dest.v1.z * v23) + (float)(dest.v0.z * v22)) + (float)(dest.v2.z * v24);
        Render::DebugDrawContext::DrawTextA(
          p_mNext->mDrawCtx,
          v21 - (int)v25 - 3,
          (int)v16 - (int)v26 - 4,
          &UFG::qColour::White,
          "S");
        Render::DebugDrawContext::DrawTextA(
          p_mNext->mDrawCtx,
          v21
        - (int)(float)((float)((float)(dest.v1.x * v26) + (float)(dest.v0.x * v25)) + (float)(dest.v2.x * v27))
        - 3,
          (int)v16
        - (int)(float)((float)((float)(dest.v1.y * v26) + (float)(dest.v0.y * v25)) + (float)(dest.v2.y * v27))
        - 4,
          &UFG::qColour::White,
          "W");
      }
      else
      {
        v28 = v7 * 0.0;
        x = dest.v1.x;
        v30 = dest.v1.x * (float)(v7 * 0.2);
        v31 = dest.v2.x * (float)(v7 * 0.0);
        v73 = (float)((float)(dest.v0.x * (float)(v7 * -0.25)) + v30) + v31;
        y = dest.v1.y;
        v33 = dest.v1.y * (float)(v7 * 0.2);
        v34 = dest.v2.y * (float)(v7 * 0.0);
        v75 = (float)((float)(dest.v0.y * (float)(v7 * -0.25)) + v33) + v34;
        v35 = dest.v0.y * (float)(v7 * 0.2);
        *(float *)&v36 = (float)((float)(dest.v0.z * (float)(v7 * -0.25)) + v35)
                       + (float)(dest.v2.z * (float)(v7 * 0.0));
        v78 = *(float *)&v36;
        dest.v1.y = (float)((float)(dest.v1.x * v61) + (float)(dest.v0.x * v28)) + v31;
        v74 = (float)((float)(y * v61) + (float)(dest.v0.y * v28)) + v34;
        dest.v1.x = (float)((float)(dest.v0.y * v61) + (float)(dest.v0.z * v28)) + (float)(dest.v2.z * v28);
        vars0 = (float)((float)(dest.v0.x * (float)(v61 * 0.25)) + v30) + v31;
        dest.v1.z = (float)((float)(dest.v0.y * (float)(v61 * 0.25)) + v33) + v34;
        dest.v1.w = (float)((float)(dest.v0.z * (float)(v61 * 0.25)) + v35) + (float)(dest.v2.z * v28);
        v37 = (float)((float)(x * (float)(v61 * 0.5)) + (float)(dest.v0.x * v28)) + v31;
        v38 = (float)((float)(y * (float)(v61 * 0.5)) + (float)(dest.v0.y * v28)) + v34;
        v39 = v76.mColour.a;
        v76.mColour = UFG::qColour::White;
        v76.mColour.a = v39;
        v40 = dest.v1.z + v5;
        v41 = vars0 + v81;
        v42 = v5 + v74;
        v43 = v81 + dest.v1.y;
        v44 = v5 + v75;
        v45 = v81 + v73;
        v64 = v81 + v73;
        v65 = v5 + v75;
        v66 = *(float *)&v36;
        v67 = v81 + dest.v1.y;
        v68 = v5 + v74;
        v46 = dest.v1.x;
        v69 = dest.v1.x;
        v70 = vars0 + v81;
        v71 = v40;
        dest.v0.x = dest.v1.w;
        dest.v0.y = v81 + v73;
        dest.v0.z = v62 + v75;
        LODWORD(dest.v0.w) = v36;
        v76.vfptr->DrawSCR(&v76, PrimMode_LineStrip, 1u, &v64, 4);
        v76.mColour.a = 0.5;
        v64 = v45;
        v65 = v44;
        v66 = *(float *)&v36;
        v67 = v43;
        v68 = v42;
        v69 = v46;
        v70 = v41;
        v71 = v40;
        dest.v0.x = dest.v1.w;
        v76.vfptr->DrawSCR(&v76, PrimMode_TriStrip, 1u, &v64, 3);
        v76.mColour.a = 1.0;
        v47 = (int)v38;
        v48 = (int)v62;
        v49 = (int)v37;
        v50 = (int)v81;
        Render::DebugDrawContext::DrawTextA(
          p_mNext->mDrawCtx,
          (int)v37 + (int)v81 - 3,
          (int)v38 + (int)v62 - 4,
          &UFG::qColour::White,
          "S");
        UFG::qRotationMatrixZ(&dest, 3.1415927);
        v51 = (float)((float)(dest.v1.x * v75) + (float)(dest.v0.x * v73)) + (float)(dest.v2.x * *(float *)&v36);
        v52 = (float)((float)(dest.v1.y * v75) + (float)(dest.v0.y * v73)) + (float)(dest.v2.y * *(float *)&v36);
        v53 = (float)((float)(dest.v1.z * v75) + (float)(dest.v0.z * v73)) + (float)(dest.v2.z * v78);
        v54 = (float)((float)(dest.v1.z * v74) + (float)(dest.v0.z * dest.v1.y)) + (float)(dest.v2.z * dest.v1.x);
        v55 = (float)((float)(dest.v1.z * dest.v1.z) + (float)(dest.v0.z * vars0)) + (float)(dest.v2.z * dest.v1.w);
        v56 = v76.mColour.a;
        v76.mColour = UFG::qColour::Red;
        v76.mColour.a = v56;
        v57 = (float)((float)((float)(dest.v1.y * dest.v1.z) + (float)(dest.v0.y * vars0))
                    + (float)(dest.v2.y * dest.v1.w))
            + v62;
        v58 = (float)((float)((float)(dest.v1.x * dest.v1.z) + (float)(dest.v0.x * vars0))
                    + (float)(dest.v2.x * dest.v1.w))
            + v81;
        v59 = v62
            + (float)((float)((float)(dest.v0.y * dest.v1.y) + (float)(dest.v1.y * v74)) + (float)(dest.v2.y * dest.v1.x));
        v60 = v81
            + (float)((float)((float)(dest.v1.x * v74) + (float)(dest.v0.x * dest.v1.y)) + (float)(dest.v2.x * dest.v1.x));
        v63 = v62 + v52;
        v81 = v81 + v51;
        v64 = v81;
        v65 = v63;
        v66 = v53;
        v67 = v60;
        v68 = v59;
        v69 = v54;
        v70 = v58;
        v71 = v57;
        dest.v0.x = v55;
        dest.v0.y = v81;
        dest.v0.z = v63;
        dest.v0.w = v53;
        v76.vfptr->DrawSCR(&v76, PrimMode_LineStrip, 1u, &v64, 4);
        v76.mColour.a = 0.5;
        v64 = v81;
        v65 = v63;
        v66 = v53;
        v67 = v60;
        v68 = v59;
        v69 = v54;
        v70 = v58;
        v71 = v57;
        dest.v0.x = v55;
        v76.vfptr->DrawSCR(&v76, PrimMode_TriStrip, 1u, &v64, 3);
        v76.mColour.a = 1.0;
        Render::DebugDrawContext::DrawTextA(p_mNext->mDrawCtx, v50 - v49 - 3, v48 - v47 - 4, &UFG::qColour::Red, "N");
      }
    }
  }
}

