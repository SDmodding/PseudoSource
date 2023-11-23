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
    &UFG::qReflectObjectType<UFG::Editor::OptionsView,UFG::qReflectObject>::sInventory,
    "UFG::Editor::OptionsView",
    v0);
  UFG::qReflectObjectType<UFG::Editor::OptionsView,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::OptionsView>::`vftable;
  UFG::qReflectInventory<UFG::Editor::OptionsView>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::OptionsView,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::Editor::OptionsView,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::OptionsView_UFG::qReflectObject_::sInventory__);
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
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::Editor::OptionsWindow>,
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
  UFG::Editor::GizmoVisiblity *mItems; // rcx
  bool *p_mVisible; // rbx
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
  this->mSelectMarqueeMode = MarqueeMode_Auto;
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
  this->mGizmoTranslateSpace = GizmoSpace_World;
  this->mGizmoRotateSpace = GizmoSpace_World;
  *(_QWORD *)&this->mGizmoTranslateScope = 1i64;
  *(_WORD *)&this->mGizmoTranslateChildLock = 0;
  this->mGizmoSnapMode = GizmoSnapMode_None;
  if ( (this->mGizmoVisiblity.mData.mFlags & 2) == 0 )
  {
    mItems = this->mGizmoVisiblity.mData.mItems;
    if ( mItems )
    {
      p_mVisible = &mItems[-1].mVisible;
      `eh vector destructor iterator(
        mItems,
        0x28ui64,
        *(_DWORD *)&mItems[-1].mVisible,
        (void (__fastcall *)(void *))UFG::Editor::GizmoVisiblity::~GizmoVisiblity);
      operator delete[](p_mVisible);
    }
  }
  this->mGizmoVisiblity.mData.mItems = 0i64;
  *(_QWORD *)&this->mGizmoVisiblity.mData.mNumItems = 0i64;
  if ( (this->mSpawnStats.mData.mFlags & 2) == 0 )
  {
    v4 = this->mSpawnStats.mData.mItems;
    if ( v4 )
    {
      if ( LODWORD(v4[-1].mAssetID) )
        v4->vfptr->__vecDelDtor(v4, 3u);
      else
        operator delete[](&v4[-1].mAssetID);
    }
  }
  this->mSpawnStats.mData.mItems = 0i64;
  *(_QWORD *)&this->mSpawnStats.mData.mNumItems = 0i64;
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
  this->mCameraMode = CameraMode_Editor;
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
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::OptionsWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::OptionsWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::OptionsWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::OptionsWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mScrollPosition = 0i64;
  UFG::qString::Set(&this->mTitle, "Options");
}

// File Line: 380
// RVA: 0x219AC0
void __fastcall UFG::Editor::OptionsWindow::UpdateUI(UFG::Editor::OptionsWindow *this, UFG::DUIContext *dui)
{
  UFG::ReflectionDB *v4; // r14
  UFG::Editor::OptionsGlobal *mGlobal; // rsi
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  UFG::qString *k; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  UFG::qString *m; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  UFG::qString *n; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v19; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rax
  UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *ii; // rsi
  const char *v22; // rax
  UFG::qString *jj; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v24; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rax
  UFG::qString *kk; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v28; // rax
  float *v29; // r8
  float v30; // xmm0_4
  UFG::qString *mm; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v32; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v33; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v34; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v35; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> strings; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v37; // [rsp+40h] [rbp-A8h]
  char dest[400]; // [rsp+50h] [rbp-98h] BYREF
  float current_value; // [rsp+1E8h] [rbp+100h] BYREF

  v37 = -2i64;
  v4 = UFG::ReflectionDB::Instance();
  mGlobal = UFG::Editor::gOptions.mGlobal;
  UFG::DUIContext::BeginScrollView(dui, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mScrollPosition);
  UFG::DUIContext::BeginVerticalLayout(dui);
  strings.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&strings;
  strings.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&strings;
  if ( UFG::DUIContext::Button(dui, "Reset to Default", 0x10u) )
    UFG::Editor::OptionsGlobal::Reset(mGlobal);
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "General", &mGlobal->mIsOpen_General) )
  {
    UFG::DUIContext::BeginIndent(dui);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Checkbox(dui, "Pause Sim on Activate", &mGlobal->mPauseSimOnActivate);
    UFG::DUIContext::Checkbox(dui, "Game Cam Lens on Activate", &mGlobal->mGameCameraLensOnActivate);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Max Obj Dist", &mGlobal->mMaxObjectDist, 0.0);
    UFG::DUIContext::Checkbox(dui, "Draw Cursor", &mGlobal->mDrawCursor);
    UFG::DUIContext::Checkbox(dui, "Draw Snap Points", &mGlobal->mSnapDrawPoints);
    UFG::DUIContext::NumericTextBox(dui, "Snap Distance", &mGlobal->mSnapThresholdDistance, 1, -1.0);
    UFG::DUIContext::NumericTextBox(dui, "Snap Rotation Delta", &mGlobal->mSnapRotationDelta, 1, -1.0);
    for ( i = (UFG::qString *)strings.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
          i = (UFG::qString *)strings.mNode.mNext )
    {
      mPrev = i->mPrev;
      mNext = i->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      i->mPrev = i;
      i->mNext = i;
      UFG::qString::~qString(i);
      operator delete[](i);
    }
    UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::RegionShape", &strings);
    UFG::DUIContext::ComboBox(dui, (int *)&mGlobal->mRegionCreationShape, &strings, 0i64, 3u);
    UFG::DUIContext::Separator(dui);
    for ( j = (UFG::qString *)strings.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
          j = (UFG::qString *)strings.mNode.mNext )
    {
      v10 = j->mPrev;
      v11 = j->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      j->mPrev = j;
      j->mNext = j;
      UFG::qString::~qString(j);
      operator delete[](j);
    }
    UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::NavigationMode", &strings);
    UFG::DUIContext::ComboBox(dui, (int *)&mGlobal->mNavigationMode, &strings, 0i64, 2u);
    for ( k = (UFG::qString *)strings.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
          k = (UFG::qString *)strings.mNode.mNext )
    {
      v13 = k->mPrev;
      v14 = k->mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      k->mPrev = k;
      k->mNext = k;
      UFG::qString::~qString(k);
      operator delete[](k);
    }
    UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::JoystickMode", &strings);
    UFG::DUIContext::ComboBox(dui, (int *)&mGlobal->mJoystickMode, &strings, 0i64, 3u);
    for ( m = (UFG::qString *)strings.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
          m = (UFG::qString *)strings.mNode.mNext )
    {
      v16 = m->mPrev;
      v17 = m->mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      m->mPrev = m;
      m->mNext = m;
      UFG::qString::~qString(m);
      operator delete[](m);
    }
    UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::WindowMode", &strings);
    UFG::DUIContext::ComboBox(dui, (int *)&mGlobal->mWindowMode, &strings, 0i64, 3u);
    UFG::DUIContext::EndIndent(dui);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Selection", &mGlobal->mIsOpen_Selection) )
  {
    UFG::DUIContext::BeginIndent(dui);
    UFG::DUIContext::Checkbox(dui, "Render Based Selection", &mGlobal->mRenderBasedSelection);
    for ( n = (UFG::qString *)strings.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
          n = (UFG::qString *)strings.mNode.mNext )
    {
      v19 = n->mPrev;
      v20 = n->mNext;
      v19->mNext = v20;
      v20->mPrev = v19;
      n->mPrev = n;
      n->mNext = n;
      UFG::qString::~qString(n);
      operator delete[](n);
    }
    UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::MarqueeMode", &strings);
    UFG::DUIContext::ComboBox(dui, (int *)&mGlobal->mSelectMarqueeMode, &strings, 0i64, 3u);
    UFG::DUIContext::Checkbox(dui, "Select Closest Only", &mGlobal->mSelectClosestOnly);
    UFG::DUIContext::Slider(dui, "Select Pixel Radius", &mGlobal->mSelectPixelRadius, 0.0);
    UFG::DUIContext::Slider(dui, "Hover Depth", &mGlobal->mHoverDepth, 0.0);
    UFG::DUIContext::Slider(dui, "Box Edge Thickness", (unsigned int *)&mGlobal->mBoxEdgeThickness, 0);
    UFG::DUIContext::Checkbox(dui, "Force SceneObj Selection", &mGlobal->mForceSceneObjectSelection);
    UFG::DUIContext::EndIndent(dui);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Navigation Joystick", &mGlobal->mIsOpen_NavJoy) )
  {
    UFG::DUIContext::BeginIndent(dui);
    UFG::DUIContext::Checkbox(dui, "Invert Pitch", &mGlobal->mNavJoyInvertY);
    UFG::DUIContext::Slider(dui, "Forward", &mGlobal->mNavJoyFactorFwdVel, 0.0);
    UFG::DUIContext::Slider(dui, "Yaw", &mGlobal->mNavJoyFactorYawVel, 0.0);
    UFG::DUIContext::Slider(dui, "Pitch", &mGlobal->mNavJoyFactorPitchVel, 0.0);
    UFG::DUIContext::Slider(dui, "Pan", &mGlobal->mNavJoyFactorPanVel, 0.0);
    UFG::DUIContext::Slider(dui, "D-Pad Pan", &mGlobal->mNavJoyFactorPadPanVel, 0.0);
    UFG::DUIContext::Slider(dui, "Zoom", &mGlobal->mNavJoyFactorZoomVel, 0.0);
    UFG::DUIContext::Slider(dui, "Global", &mGlobal->mNavJoyFactorGlobalVel, 0.0);
    UFG::DUIContext::EndIndent(dui);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Navigation Orbit Mode", &mGlobal->mIsOpen_NavOrbit) )
  {
    UFG::DUIContext::BeginIndent(dui);
    UFG::DUIContext::Checkbox(dui, "Invert Pitch", &mGlobal->mNavOrbitInvertY);
    UFG::DUIContext::Checkbox(dui, "Invert Dolly", &mGlobal->mNavOrbitInvertDolly);
    UFG::DUIContext::Slider(dui, "Horiz Rot", &mGlobal->mNavOrbitFactorHRotVel, 0.0);
    UFG::DUIContext::Slider(dui, "Vert Rot", &mGlobal->mNavOrbitFactorVRotVel, 0.0);
    UFG::DUIContext::Slider(dui, "Dolly Speed", &mGlobal->mNavOrbitFactorDollyVel, 0.0);
    UFG::DUIContext::NumericTextBox(dui, "Meters/Wheel Notch", &mGlobal->mNavOrbitDstPerWheelNotch, 1, -1.0);
    UFG::DUIContext::EndIndent(dui);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Navigation Fly Mode", &mGlobal->mIsOpen_NavFly) )
  {
    UFG::DUIContext::BeginIndent(dui);
    UFG::DUIContext::Checkbox(dui, "Invert Pitch", &mGlobal->mNavFlyInvertY);
    UFG::DUIContext::Checkbox(dui, "Invert Fwd", &mGlobal->mNavFlyInvertFwd);
    UFG::DUIContext::Slider(dui, "Yaw", &mGlobal->mNavFlyFactorYawVel, 0.0);
    UFG::DUIContext::Slider(dui, "Pitch", &mGlobal->mNavFlyFactorPitchVel, 0.0);
    UFG::DUIContext::Slider(dui, "Fwd", &mGlobal->mNavFlyFactorFwdVel, 0.0);
    UFG::DUIContext::Slider(dui, "Auto Fwd", &mGlobal->mNavFlyFactorAutoFwdVel, 0.0);
    UFG::DUIContext::NumericTextBox(dui, "Meters/Wheel Notch", &mGlobal->mNavFlyDstPerWheelNotch, 1, -1.0);
    UFG::DUIContext::EndIndent(dui);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Navigation Ortho Modes", &mGlobal->mIsOpen_NavOrtho) )
  {
    UFG::DUIContext::BeginIndent(dui);
    UFG::DUIContext::Checkbox(dui, "Invert Dolly", &mGlobal->mNavOrthoInvertDolly);
    UFG::DUIContext::Slider(dui, "Dolly Speed", &mGlobal->mNavOrthoFactorDollyVel, 0.0);
    UFG::DUIContext::NumericTextBox(dui, "Meters/Wheel Notch", &mGlobal->mNavOrthoDstPerWheelNotch, 1, -1.0);
    UFG::DUIContext::EndIndent(dui);
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Gizmo", &mGlobal->mIsOpen_Gizmo) )
  {
    UFG::DUIContext::BeginIndent(dui);
    UFG::DUIContext::Slider(dui, "Size", &mGlobal->mGizmoSize, 0.1);
    UFG::DUIContext::Slider(dui, "Arrow Size", &mGlobal->mGizmoArrowSize, 0.0099999998);
    UFG::DUIContext::Slider(dui, "Orth Plane Size", &mGlobal->mGizmoOrthPlaneHandleSize, 0.0);
    UFG::DUIContext::Slider(dui, "View Plane Size", &mGlobal->mGizmoViewPlaneHandleSize, 0.0);
    UFG::DUIContext::Slider(dui, "Handle Opacity", (unsigned int *)&mGlobal->mGizmoHandleOpacity, 0);
    UFG::DUIContext::EndIndent(dui);
  }
  for ( ii = UFG::Editor::gOptions.mViews.mNode.mNext - 5;
        ii != (UFG::qNode<UFG::Editor::OptionsView,UFG::Editor::OptionsView> *)(&UFG::Editor::gOptions.mViews - 5);
        ii = ii[5].mNext - 5 )
  {
    if ( LODWORD(ii[6].mNext) )
      v22 = (const char *)ii[6].mPrev;
    else
      v22 = &customCaption;
    UFG::qSPrintf(dest, 256, "View %d : %s", 0i64, v22);
    if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, dest, (bool *)&ii[7]) )
    {
      UFG::DUIContext::BeginIndent(dui);
      if ( UFG::DUIContext::Button(dui, "Reset to Default", 0x10u) )
        UFG::Editor::OptionsView::Reset((UFG::Editor::OptionsView *)ii);
      UFG::DUIContext::Separator(dui);
      for ( jj = (UFG::qString *)strings.mNode.mNext;
            (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
            jj = (UFG::qString *)strings.mNode.mNext )
      {
        v24 = jj->mPrev;
        v25 = jj->mNext;
        v24->mNext = v25;
        v25->mPrev = v24;
        jj->mPrev = jj;
        jj->mNext = jj;
        UFG::qString::~qString(jj);
        operator delete[](jj);
      }
      UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::DrawMode", &strings);
      UFG::DUIContext::ComboBox(dui, (int *)&ii[7].mNext, &strings, 0i64, 3u);
      UFG::DUIContext::Label(dui, "Game:");
      UFG::DUIContext::Checkbox(dui, "Draw Scenery", (unsigned int *)&ii[7].mNext + 1, 2u);
      UFG::DUIContext::Checkbox(dui, "Draw Wireframe Scenery", (unsigned int *)&ii[7].mNext + 1, 0x200u);
      UFG::DUIContext::Checkbox(dui, "Draw Objects", (unsigned int *)&ii[7].mNext + 1, 4u);
      UFG::DUIContext::Checkbox(dui, "Draw Post FX", (unsigned int *)&ii[7].mNext + 1, 8u);
      UFG::DUIContext::Checkbox(dui, "Draw DOF", (unsigned int *)&ii[7].mNext + 1, 0x10u);
      UFG::DUIContext::Label(dui, "Editor / Debug:");
      if ( !HIDWORD(ii[7].mPrev) )
        UFG::DUIContext::Checkbox(dui, "Draw Gradient BG", (unsigned int *)&ii[7].mNext + 1, 1u);
      UFG::DUIContext::Checkbox(dui, "Draw Motion Blur", (unsigned int *)&ii[7].mNext + 1, 0x100u);
      UFG::DUIContext::Checkbox(dui, "Draw Parent Links", (unsigned int *)&ii[7].mNext + 1, 0x20u);
      UFG::DUIContext::Checkbox(dui, "Draw Children Links", (unsigned int *)&ii[7].mNext + 1, 0x40u);
      UFG::DUIContext::Checkbox(dui, "Draw Sibling Links", (unsigned int *)&ii[7].mNext + 1, 0x80u);
      UFG::DUIContext::Checkbox(dui, "Draw Spawn Point Links", (unsigned int *)&ii[7].mNext + 1, 0x400u);
      UFG::DUIContext::Separator(dui);
      UFG::DUIContext::ToggleButton(dui, "Backface Cull", (bool *)&ii[8]);
      UFG::DUIContext::ToggleButton(dui, "Depth Test", (bool *)&ii[8].mPrev + 1);
      UFG::DUIContext::Slider(dui, "Proxy Opacity", (unsigned int *)&ii[8].mPrev + 1, 0);
      UFG::DUIContext::Checkbox(dui, "Draw Origin", (bool *)&ii[8].mNext);
      UFG::DUIContext::Separator(dui);
      for ( kk = (UFG::qString *)strings.mNode.mNext;
            (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
            kk = (UFG::qString *)strings.mNode.mNext )
      {
        v27 = kk->mPrev;
        v28 = kk->mNext;
        v27->mNext = v28;
        v28->mPrev = v27;
        kk->mPrev = kk;
        kk->mNext = kk;
        UFG::qString::~qString(kk);
        operator delete[](kk);
      }
      UFG::ReflectionDB::TryGetEnumStrings(v4, "UFG::Editor::CameraMode", &strings);
      UFG::DUIContext::ComboBox(dui, (int *)&ii[8].mNext + 1, &strings, 0i64, 3u);
      UFG::DUIContext::Slider(dui, "Vert FOV", (unsigned int *)&ii[9], 30);
      v29 = (float *)&ii[9].mPrev + 1;
      if ( HIDWORD(ii[7].mPrev) )
      {
        UFG::DUIContext::Slider(dui, "Cross Section Near", v29, -10000.0);
        current_value = *(float *)&ii[9].mNext - *((float *)&ii[9].mPrev + 1);
        if ( current_value < 1.0 )
          current_value = 1.0;
        UFG::DUIContext::Slider(dui, "Cross Section Thickness", &current_value, 0.0);
        v30 = current_value;
        if ( current_value < 1.0 )
        {
          v30 = *(float *)&FLOAT_1_0;
          current_value = *(float *)&FLOAT_1_0;
        }
        *(float *)&ii[9].mNext = v30 + *((float *)&ii[9].mPrev + 1);
      }
      else
      {
        UFG::DUIContext::Slider(dui, "Near Plane", v29, 0.0099999998);
        UFG::DUIContext::Slider(dui, "Far  Plane", (float *)&ii[9].mNext, 10.0);
      }
      UFG::DUIContext::Slider(dui, "Pan Horiz", (float *)&ii[9].mNext + 1, -1.0);
      UFG::DUIContext::Slider(dui, "Pan Vert", (float *)&ii[10], -1.0);
      UFG::DUIContext::Separator(dui);
      UFG::DUIContext::Checkbox(dui, "Grid Visible", (bool *)&ii[10].mPrev + 4);
      UFG::DUIContext::Checkbox(dui, "Grid Auto Spacing", (bool *)&ii[10].mPrev + 5);
      UFG::DUIContext::NumericTextBox(dui, "Grid Spacing", (float *)&ii[10].mNext, 1, -1.0);
      UFG::DUIContext::NumericTextBox(dui, "Grid Height", (float *)&ii[10].mNext + 1, 1, -1.0);
      UFG::DUIContext::ColourPicker(dui, "Grid Colour", (UFG::qColour *)&ii[11], 1);
      UFG::DUIContext::ColourPicker(dui, "Gradient Top", (UFG::qColour *)&ii[12], 0);
      UFG::DUIContext::ColourPicker(dui, "Gradient Bot", (UFG::qColour *)&ii[13], 0);
      UFG::DUIContext::EndIndent(dui);
    }
  }
  UFG::DUIContext::EndLayoutHorizontal(dui);
  UFG::DUIContext::EndScrollView(dui);
  for ( mm = (UFG::qString *)strings.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)strings.mNode.mNext != &strings;
        mm = (UFG::qString *)strings.mNode.mNext )
  {
    v32 = mm->mPrev;
    v33 = mm->mNext;
    v32->mNext = v33;
    v33->mPrev = v32;
    mm->mPrev = mm;
    mm->mNext = mm;
    UFG::qString::~qString(mm);
    operator delete[](mm);
  }
  v34 = strings.mNode.mPrev;
  v35 = strings.mNode.mNext;
  strings.mNode.mPrev->mNext = strings.mNode.mNext;
  v35->mPrev = v34;
}m->mPrev;
    v33 = mm->mNext;
    v32->mNext = v33;
    v33->mPrev = v32;
    mm->mPrev = mm;
    mm->mNext = mm;
    UFG::qString::~qString(mm);
    operator delete[](mm);
  }
  v34 = strings.mNode.mPrev;
  v35 = strings.mNode.mNext;
  strings.mNode.mPrev->mNext = strings.mNode.mNext;
  v35-

