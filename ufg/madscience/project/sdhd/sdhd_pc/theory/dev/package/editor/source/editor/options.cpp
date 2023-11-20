// File Line: 24
// RVA: 0x146C430
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::OptionsGlobal_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::OptionsGlobal", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::OptionsGlobal,UFG::qReflectObject>::sDeserializeOp,
    v0,
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::Editor::OptionsGlobal>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 25
// RVA: 0x146D140
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::OptionsView_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::OptionsView", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::OptionsView,UFG::qReflectObject>::sInventory.vfptr,
    "UFG::Editor::OptionsView",
    v0);
  UFG::qReflectObjectType<UFG::Editor::OptionsView,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::OptionsView>::`vftable;
  UFG::qReflectInventory<UFG::Editor::OptionsView>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::OptionsView,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::OptionsView,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::OptionsView_UFG::qReflectObject_::sInventory__);
}

// File Line: 26
// RVA: 0x146C4B0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::OptionsWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::OptionsWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::Editor::OptionsWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 27
// RVA: 0x146C630
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::SpawnStat_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::SpawnStat", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::SpawnStat,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::Editor::SpawnStat>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 33
// RVA: 0x212300
void __fastcall UFG::Editor::OptionsGlobal::Reset(UFG::Editor::OptionsGlobal *this)
{
  UFG::Editor::OptionsGlobal *v1; // rdi
  UFG::Editor::GizmoVisiblity *v2; // rcx
  bool *v3; // rbx
  UFG::Editor::SpawnStat *v4; // rcx

  *(_WORD *)&this->mIsOpen_General = 256;
  this->mGameCameraLensOnActivate = 0;
  *(_QWORD *)&this->mWindowRect.mX = 0i64;
  this->mWindowRect.mW = 1280;
  this->mMaxObjectDist = 75.0;
  this->mWindowRect.mH = 720;
  this->mDrawCursor = 1;
  this->mEditorTimeOfDay = -1;
  this->mSnapDrawPoints = 0;
  *(_QWORD *)&this->mSnapThresholdDistance = 1033476506i64;
  *(_QWORD *)&this->mRegionCreationShape = 0i64;
  *(_QWORD *)&this->mJoystickMode = 2i64;
  *(_WORD *)&this->mSkookumIDE = 0;
  *(_WORD *)&this->mCompassLock = 1;
  this->mRenderBasedSelection = 0;
  this->mSelectMarqueeMode = 0;
  this->mSelectClosestOnly = 0;
  this->mSelectPixelRadius = 5.0;
  this->mHoverDepth = 0.1;
  this->mBoxEdgeThickness = 4;
  *(_WORD *)&this->mForceSceneObjectSelection = 0;
  this->mNavJoyInvertY = 0;
  this->mNavJoyFactorFwdVel = 1.0;
  this->mNavJoyFactorYawVel = 1.0;
  this->mNavJoyFactorPitchVel = 1.0;
  this->mNavJoyFactorPanVel = 1.0;
  this->mNavJoyFactorPadPanVel = 1.0;
  this->mNavJoyFactorZoomVel = 1.0;
  this->mNavJoyFactorGlobalVel = 1.0;
  *(_WORD *)&this->mIsOpen_NavOrbit = 0;
  this->mNavOrbitInvertDolly = 0;
  this->mNavOrbitFactorHRotVel = 1.0;
  this->mNavOrbitFactorVRotVel = 1.0;
  this->mNavOrbitFactorDollyVel = 1.0;
  this->mNavOrbitDstPerWheelNotch = 0.5;
  *(_WORD *)&this->mIsOpen_NavFly = 0;
  this->mNavFlyInvertFwd = 0;
  this->mNavFlyFactorYawVel = 1.0;
  this->mNavFlyFactorPitchVel = 1.0;
  this->mNavFlyFactorFwdVel = 1.0;
  this->mNavFlyFactorAutoFwdVel = 1.0;
  this->mNavFlyDstPerWheelNotch = 0.5;
  *(_WORD *)&this->mIsOpen_NavOrtho = 0;
  this->mNavOrthoFactorDollyVel = 1.0;
  this->mNavOrthoDstPerWheelNotch = 0.2;
  this->mIsOpen_Gizmo = 0;
  this->mGizmoSize = 0.44999999;
  this->mGizmoArrowSize = 0.079999998;
  this->mGizmoOrthPlaneHandleSize = 0.333;
  this->mGizmoViewPlaneHandleSize = 0.80000001;
  this->mGizmoHandleOpacity = 1;
  *(_QWORD *)&this->mGizmoTranslateLocation = 0i64;
  this->mGizmoTranslateSpace = 1;
  this->mGizmoRotateSpace = 1;
  *(_QWORD *)&this->mGizmoTranslateScope = 1i64;
  *(_WORD *)&this->mGizmoTranslateChildLock = 0;
  this->mGizmoSnapMode = 0;
  v1 = this;
  if ( !(this->mGizmoVisiblity.mData.mFlags & 2) )
  {
    v2 = this->mGizmoVisiblity.mData.mItems;
    if ( v2 )
    {
      v3 = &v2[-1].mVisible;
      `eh vector destructor iterator(
        v2,
        0x28ui64,
        *(_DWORD *)&v2[-1].mVisible,
        (void (__fastcall *)(void *))UFG::Editor::GizmoVisiblity::~GizmoVisiblity);
      operator delete[](v3);
    }
  }
  v1->mGizmoVisiblity.mData.mItems = 0i64;
  *(_QWORD *)&v1->mGizmoVisiblity.mData.mNumItems = 0i64;
  if ( !(v1->mSpawnStats.mData.mFlags & 2) )
  {
    v4 = v1->mSpawnStats.mData.mItems;
    if ( v4 )
    {
      if ( LODWORD(v4[-1].mAssetID) )
        v4->vfptr->__vecDelDtor((UFG::qReflectObject *)&v4->vfptr, 3u);
      else
        operator delete[](&v4[-1].mAssetID);
    }
  }
  v1->mSpawnStats.mData.mItems = 0i64;
  *(_QWORD *)&v1->mSpawnStats.mData.mNumItems = 0i64;
}

// File Line: 222
// RVA: 0x212590
void __fastcall UFG::Editor::OptionsView::Reset(UFG::Editor::OptionsView *this)
{
  this->mIsOpen_View = 0;
  this->mDrawFlags = 102;
  *(_WORD *)&this->mBackfaceCull = 257;
  this->mProxyOpacity = 2;
  this->mDrawOrigin = 1;
  this->mGridColour.r = FLOAT_0_5;
  this->mGridColour.g = FLOAT_0_5;
  *(_QWORD *)&this->mViewMode = 0i64;
  this->mCameraMode = 0;
  this->mVertFOV = 45;
  this->mGridColour.b = FLOAT_0_51999998;
  this->mNearPlane = 0.5;
  *(_QWORD *)&this->mFarPlane = 1176256512i64;
  this->mPanYOffset = 0.0;
  this->mGradientColourTop.r = FLOAT_0_39899999;
  this->mGradientColourTop.g = FLOAT_0_43099999;
  *(_WORD *)&this->mGridVisible = 257;
  *(_QWORD *)&this->mGridSpacing = 1065353216i64;
  this->mGradientColourBot.r = FLOAT_0_15000001;
  this->mGradientColourTop.b = FLOAT_0_484;
  this->mGradientColourBot.g = FLOAT_0_153;
  LODWORD(this->mGridColour.a) = (_DWORD)FLOAT_1_0;
  this->mGradientColourBot.b = FLOAT_0_162;
  LODWORD(this->mGradientColourTop.a) = (_DWORD)FLOAT_1_0;
  LODWORD(this->mGradientColourBot.a) = (_DWORD)FLOAT_1_0;
}

// File Line: 368
// RVA: 0x201D70
void __fastcall UFG::Editor::OptionsWindow::OptionsWindow(UFG::Editor::OptionsWindow *this)
{
  UFG::Editor::OptionsWindow *v1; // rbx

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::OptionsWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::OptionsWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::OptionsWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mScrollPosition = 0i64;
  UFG::qString::Set(&v1->mTitle, "Options");
}

// File Line: 380
// RVA: 0x219AC0
void __fastcall UFG::Editor::OptionsWindow::UpdateUI(UFG::Editor::OptionsWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  UFG::Editor::OptionsWindow *v3; // rbx
  UFG::ReflectionDB *v4; // r14
  UFG::Editor::OptionsGlobal *v5; // rsi
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v7; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  UFG::qString *k; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  UFG::qString *l; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  UFG::qString *m; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v19; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rax
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *n; // rsi
  char *v22; // rax
  UFG::qString *ii; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v24; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rax
  UFG::qString *jj; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v28; // rax
  float *v29; // r8
  float v30; // xmm0_4
  UFG::qString *kk; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v32; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v33; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v35; // rax
  __int64 proportion; // [rsp+28h] [rbp-C0h]
  UFG::qList<UFG::qString,UFG::qString,1,0> strings; // [rsp+30h] [rbp-B8h]
  __int64 v38; // [rsp+40h] [rbp-A8h]
  char dest; // [rsp+50h] [rbp-98h]
  float current_value; // [rsp+1E8h] [rbp+100h]

  v38 = -2i64;
  v2 = dui;
  v3 = this;
  v4 = UFG::ReflectionDB::Instance();
  v5 = UFG::Editor::gOptions.mGlobal;
  UFG::DUIContext::BeginScrollView(v2, &v3->mScrollPosition);
  UFG::DUIContext::BeginVerticalLayout(v2);
  strings.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&strings;
  strings.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&strings;
  if ( (unsigned __int8)UFG::DUIContext::Button(v2, "Reset to Default", 0x10u) )
    UFG::Editor::OptionsGlobal::Reset(v5);
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "General", &v5->mIsOpen_General) )
  {
    UFG::DUIContext::BeginIndent(v2);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Checkbox(v2, "Pause Sim on Activate", &v5->mPauseSimOnActivate);
    UFG::DUIContext::Checkbox(v2, "Game Cam Lens on Activate", &v5->mGameCameraLensOnActivate);
    UFG::DUIContext::Separator(v2);
    LODWORD(proportion) = 0;
    UFG::DUIContext::Slider(v2, "Max Obj Dist", &v5->mMaxObjectDist, 0.0);
    UFG::DUIContext::Checkbox(v2, "Draw Cursor", &v5->mDrawCursor);
    UFG::DUIContext::Checkbox(v2, "Draw Snap Points", &v5->mSnapDrawPoints);
    UFG::DUIContext::NumericTextBox(v2, "Snap Distance", &v5->mSnapThresholdDistance, 1, -1.0);
    UFG::DUIContext::NumericTextBox(v2, "Snap Rotation Delta", &v5->mSnapRotationDelta, 1, -1.0);
    for ( i = (UFG::qString *)strings.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
          i = (UFG::qString *)strings.mNode.mNext )
    {
      v7 = i->mPrev;
      v8 = i->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
      i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
      UFG::qString::~qString(i);
      operator delete[](i);
    }
    UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::RegionShape", &strings);
    UFG::DUIContext::ComboBox(v2, (int *)&v5->mRegionCreationShape, &strings, 0i64, 3u);
    UFG::DUIContext::Separator(v2);
    for ( j = (UFG::qString *)strings.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
          j = (UFG::qString *)strings.mNode.mNext )
    {
      v10 = j->mPrev;
      v11 = j->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      j->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
      j->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
      UFG::qString::~qString(j);
      operator delete[](j);
    }
    UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::NavigationMode", &strings);
    UFG::DUIContext::ComboBox(v2, (int *)&v5->mNavigationMode, &strings, 0i64, 2u);
    for ( k = (UFG::qString *)strings.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
          k = (UFG::qString *)strings.mNode.mNext )
    {
      v13 = k->mPrev;
      v14 = k->mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      k->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&k->mPrev;
      k->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&k->mPrev;
      UFG::qString::~qString(k);
      operator delete[](k);
    }
    UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::JoystickMode", &strings);
    UFG::DUIContext::ComboBox(v2, (int *)&v5->mJoystickMode, &strings, 0i64, 3u);
    for ( l = (UFG::qString *)strings.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
          l = (UFG::qString *)strings.mNode.mNext )
    {
      v16 = l->mPrev;
      v17 = l->mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      l->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&l->mPrev;
      l->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&l->mPrev;
      UFG::qString::~qString(l);
      operator delete[](l);
    }
    UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::WindowMode", &strings);
    UFG::DUIContext::ComboBox(v2, (int *)&v5->mWindowMode, &strings, 0i64, 3u);
    UFG::DUIContext::EndIndent(v2);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Selection", &v5->mIsOpen_Selection) )
  {
    UFG::DUIContext::BeginIndent(v2);
    UFG::DUIContext::Checkbox(v2, "Render Based Selection", &v5->mRenderBasedSelection);
    for ( m = (UFG::qString *)strings.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
          m = (UFG::qString *)strings.mNode.mNext )
    {
      v19 = m->mPrev;
      v20 = m->mNext;
      v19->mNext = v20;
      v20->mPrev = v19;
      m->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&m->mPrev;
      m->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&m->mPrev;
      UFG::qString::~qString(m);
      operator delete[](m);
    }
    UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::MarqueeMode", &strings);
    UFG::DUIContext::ComboBox(v2, (int *)&v5->mSelectMarqueeMode, &strings, 0i64, 3u);
    UFG::DUIContext::Checkbox(v2, "Select Closest Only", &v5->mSelectClosestOnly);
    UFG::DUIContext::Slider(v2, "Select Pixel Radius", &v5->mSelectPixelRadius, 0.0);
    UFG::DUIContext::Slider(v2, "Hover Depth", &v5->mHoverDepth, 0.0);
    *(float *)&proportion = FLOAT_N1_0;
    UFG::DUIContext::Slider(v2, "Box Edge Thickness", &v5->mBoxEdgeThickness, 0);
    UFG::DUIContext::Checkbox(v2, "Force SceneObj Selection", &v5->mForceSceneObjectSelection);
    UFG::DUIContext::EndIndent(v2);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Navigation Joystick", &v5->mIsOpen_NavJoy) )
  {
    UFG::DUIContext::BeginIndent(v2);
    UFG::DUIContext::Checkbox(v2, "Invert Pitch", &v5->mNavJoyInvertY);
    UFG::DUIContext::Slider(v2, "Forward", &v5->mNavJoyFactorFwdVel, 0.0);
    UFG::DUIContext::Slider(v2, "Yaw", &v5->mNavJoyFactorYawVel, 0.0);
    UFG::DUIContext::Slider(v2, "Pitch", &v5->mNavJoyFactorPitchVel, 0.0);
    UFG::DUIContext::Slider(v2, "Pan", &v5->mNavJoyFactorPanVel, 0.0);
    UFG::DUIContext::Slider(v2, "D-Pad Pan", &v5->mNavJoyFactorPadPanVel, 0.0);
    UFG::DUIContext::Slider(v2, "Zoom", &v5->mNavJoyFactorZoomVel, 0.0);
    LODWORD(proportion) = 0;
    UFG::DUIContext::Slider(v2, "Global", &v5->mNavJoyFactorGlobalVel, 0.0);
    UFG::DUIContext::EndIndent(v2);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Navigation Orbit Mode", &v5->mIsOpen_NavOrbit) )
  {
    UFG::DUIContext::BeginIndent(v2);
    UFG::DUIContext::Checkbox(v2, "Invert Pitch", &v5->mNavOrbitInvertY);
    UFG::DUIContext::Checkbox(v2, "Invert Dolly", &v5->mNavOrbitInvertDolly);
    UFG::DUIContext::Slider(v2, "Horiz Rot", &v5->mNavOrbitFactorHRotVel, 0.0);
    UFG::DUIContext::Slider(v2, "Vert Rot", &v5->mNavOrbitFactorVRotVel, 0.0);
    LODWORD(proportion) = 0;
    UFG::DUIContext::Slider(v2, "Dolly Speed", &v5->mNavOrbitFactorDollyVel, 0.0);
    UFG::DUIContext::NumericTextBox(v2, "Meters/Wheel Notch", &v5->mNavOrbitDstPerWheelNotch, 1, -1.0);
    UFG::DUIContext::EndIndent(v2);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Navigation Fly Mode", &v5->mIsOpen_NavFly) )
  {
    UFG::DUIContext::BeginIndent(v2);
    UFG::DUIContext::Checkbox(v2, "Invert Pitch", &v5->mNavFlyInvertY);
    UFG::DUIContext::Checkbox(v2, "Invert Fwd", &v5->mNavFlyInvertFwd);
    UFG::DUIContext::Slider(v2, "Yaw", &v5->mNavFlyFactorYawVel, 0.0);
    UFG::DUIContext::Slider(v2, "Pitch", &v5->mNavFlyFactorPitchVel, 0.0);
    UFG::DUIContext::Slider(v2, "Fwd", &v5->mNavFlyFactorFwdVel, 0.0);
    LODWORD(proportion) = 0;
    UFG::DUIContext::Slider(v2, "Auto Fwd", &v5->mNavFlyFactorAutoFwdVel, 0.0);
    UFG::DUIContext::NumericTextBox(v2, "Meters/Wheel Notch", &v5->mNavFlyDstPerWheelNotch, 1, -1.0);
    UFG::DUIContext::EndIndent(v2);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Navigation Ortho Modes", &v5->mIsOpen_NavOrtho) )
  {
    UFG::DUIContext::BeginIndent(v2);
    UFG::DUIContext::Checkbox(v2, "Invert Dolly", &v5->mNavOrthoInvertDolly);
    LODWORD(proportion) = 0;
    UFG::DUIContext::Slider(v2, "Dolly Speed", &v5->mNavOrthoFactorDollyVel, 0.0);
    UFG::DUIContext::NumericTextBox(v2, "Meters/Wheel Notch", &v5->mNavOrthoDstPerWheelNotch, 1, -1.0);
    UFG::DUIContext::EndIndent(v2);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Gizmo", &v5->mIsOpen_Gizmo) )
  {
    UFG::DUIContext::BeginIndent(v2);
    UFG::DUIContext::Slider(v2, "Size", &v5->mGizmoSize, 0.1);
    UFG::DUIContext::Slider(v2, "Arrow Size", &v5->mGizmoArrowSize, 0.0099999998);
    UFG::DUIContext::Slider(v2, "Orth Plane Size", &v5->mGizmoOrthPlaneHandleSize, 0.0);
    UFG::DUIContext::Slider(v2, "View Plane Size", &v5->mGizmoViewPlaneHandleSize, 0.0);
    *(float *)&proportion = FLOAT_N1_0;
    UFG::DUIContext::Slider(v2, "Handle Opacity", &v5->mGizmoHandleOpacity, 0);
    UFG::DUIContext::EndIndent(v2);
  }
  for ( n = UFG::Editor::gOptions.mViews.mNode.mNext - 5;
        n != (UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *)(&UFG::Editor::gOptions.mViews - 5);
        n = n[5].mNext - 5 )
  {
    if ( LODWORD(n[6].mNext) )
      v22 = (char *)n[6].mPrev;
    else
      v22 = &customWorldMapCaption;
    UFG::qSPrintf(&dest, 256, "View %d : %s", 0i64, v22, proportion);
    if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, &dest, (bool *)&n[7]) )
    {
      UFG::DUIContext::BeginIndent(v2);
      if ( (unsigned __int8)UFG::DUIContext::Button(v2, "Reset to Default", 0x10u) )
        UFG::Editor::OptionsView::Reset((UFG::Editor::OptionsView *)n);
      UFG::DUIContext::Separator(v2);
      for ( ii = (UFG::qString *)strings.mNode.mNext;
            (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
            ii = (UFG::qString *)strings.mNode.mNext )
      {
        v24 = ii->mPrev;
        v25 = ii->mNext;
        v24->mNext = v25;
        v25->mPrev = v24;
        ii->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&ii->mPrev;
        ii->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&ii->mPrev;
        UFG::qString::~qString(ii);
        operator delete[](ii);
      }
      UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::DrawMode", &strings);
      UFG::DUIContext::ComboBox(v2, (int *)&n[7].mNext, &strings, 0i64, 3u);
      UFG::DUIContext::Label(v2, "Game:");
      UFG::DUIContext::Checkbox(v2, "Draw Scenery", (unsigned int *)&n[7].mNext + 1, 2u);
      UFG::DUIContext::Checkbox(v2, "Draw Wireframe Scenery", (unsigned int *)&n[7].mNext + 1, 0x200u);
      UFG::DUIContext::Checkbox(v2, "Draw Objects", (unsigned int *)&n[7].mNext + 1, 4u);
      UFG::DUIContext::Checkbox(v2, "Draw Post FX", (unsigned int *)&n[7].mNext + 1, 8u);
      UFG::DUIContext::Checkbox(v2, "Draw DOF", (unsigned int *)&n[7].mNext + 1, 0x10u);
      UFG::DUIContext::Label(v2, "Editor / Debug:");
      if ( !HIDWORD(n[7].mPrev) )
        UFG::DUIContext::Checkbox(v2, "Draw Gradient BG", (unsigned int *)&n[7].mNext + 1, 1u);
      UFG::DUIContext::Checkbox(v2, "Draw Motion Blur", (unsigned int *)&n[7].mNext + 1, 0x100u);
      UFG::DUIContext::Checkbox(v2, "Draw Parent Links", (unsigned int *)&n[7].mNext + 1, 0x20u);
      UFG::DUIContext::Checkbox(v2, "Draw Children Links", (unsigned int *)&n[7].mNext + 1, 0x40u);
      UFG::DUIContext::Checkbox(v2, "Draw Sibling Links", (unsigned int *)&n[7].mNext + 1, 0x80u);
      UFG::DUIContext::Checkbox(v2, "Draw Spawn Point Links", (unsigned int *)&n[7].mNext + 1, 0x400u);
      UFG::DUIContext::Separator(v2);
      UFG::DUIContext::ToggleButton(v2, "Backface Cull", (bool *)&n[8]);
      UFG::DUIContext::ToggleButton(v2, "Depth Test", (bool *)&n[8].mPrev + 1);
      UFG::DUIContext::Slider(v2, "Proxy Opacity", (int *)&n[8].mPrev + 1, 0);
      UFG::DUIContext::Checkbox(v2, "Draw Origin", (bool *)&n[8].mNext);
      UFG::DUIContext::Separator(v2);
      for ( jj = (UFG::qString *)strings.mNode.mNext;
            (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
            jj = (UFG::qString *)strings.mNode.mNext )
      {
        v27 = jj->mPrev;
        v28 = jj->mNext;
        v27->mNext = v28;
        v28->mPrev = v27;
        jj->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&jj->mPrev;
        jj->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&jj->mPrev;
        UFG::qString::~qString(jj);
        operator delete[](jj);
      }
      UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::CameraMode", &strings);
      UFG::DUIContext::ComboBox(v2, (int *)&n[8].mNext + 1, &strings, 0i64, 3u);
      UFG::DUIContext::Slider(v2, "Vert FOV", (int *)&n[9], 30);
      v29 = (float *)((char *)&n[9].mPrev + 4);
      if ( HIDWORD(n[7].mPrev) )
      {
        UFG::DUIContext::Slider(v2, "Cross Section Near", v29, -10000.0);
        current_value = *(float *)&n[9].mNext - *((float *)&n[9].mPrev + 1);
        if ( current_value < 1.0 )
          current_value = 1.0;
        UFG::DUIContext::Slider(v2, "Cross Section Thickness", &current_value, 0.0);
        v30 = current_value;
        if ( current_value < 1.0 )
        {
          v30 = *(float *)&FLOAT_1_0;
          current_value = *(float *)&FLOAT_1_0;
        }
        *(float *)&n[9].mNext = v30 + *((float *)&n[9].mPrev + 1);
      }
      else
      {
        UFG::DUIContext::Slider(v2, "Near Plane", v29, 0.0099999998);
        UFG::DUIContext::Slider(v2, "Far  Plane", (float *)&n[9].mNext, 10.0);
      }
      UFG::DUIContext::Slider(v2, "Pan Horiz", (float *)&n[9].mNext + 1, -1.0);
      LODWORD(proportion) = 0;
      UFG::DUIContext::Slider(v2, "Pan Vert", (float *)&n[10], -1.0);
      UFG::DUIContext::Separator(v2);
      UFG::DUIContext::Checkbox(v2, "Grid Visible", (bool *)&n[10].mPrev + 4);
      UFG::DUIContext::Checkbox(v2, "Grid Auto Spacing", (bool *)&n[10].mPrev + 5);
      UFG::DUIContext::NumericTextBox(v2, "Grid Spacing", (float *)&n[10].mNext, 1, -1.0);
      UFG::DUIContext::NumericTextBox(v2, "Grid Height", (float *)&n[10].mNext + 1, 1, -1.0);
      UFG::DUIContext::ColourPicker(v2, "Grid Colour", (UFG::qColour *)&n[11], 1);
      UFG::DUIContext::ColourPicker(v2, "Gradient Top", (UFG::qColour *)&n[12], 0);
      UFG::DUIContext::ColourPicker(v2, "Gradient Bot", (UFG::qColour *)&n[13], 0);
      UFG::DUIContext::EndIndent(v2);
    }
  }
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::EndScrollView(v2);
  for ( kk = (UFG::qString *)strings.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
        kk = (UFG::qString *)strings.mNode.mNext )
  {
    v32 = kk->mPrev;
    v33 = kk->mNext;
    v32->mNext = v33;
    v33->mPrev = v32;
    kk->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&kk->mPrev;
    kk->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&kk->mPrev;
    UFG::qString::~qString(kk);
    operator delete[](kk);
  }
  v34 = strings.mNode.mPrev;
  v35 = strings.mNode.mNext;
  strings.mNode.mPrev->mNext = strings.mNode.mNext;
  v35->mPrev = v34;
}

