// File Line: 28
// RVA: 0x146CB80
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::StatusBar_UFG::DUIWindow_::sFactoryOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::StatusBar", 0xFFFFFFFFFFFFFFFFui64);
  UFG::FactoryOperation::FactoryOperation(
    &UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::sFactoryOp,
    v0,
    UFG::OnCreateClass<UFG::Editor::StatusBar>,
    (void (__fastcall *)(char *))UFG::OnDeleteClass<UFG::DUIThemeEditorWindow>);
}

// File Line: 34
// RVA: 0x202860
void __fastcall UFG::Editor::StatusBar::StatusBar(UFG::Editor::StatusBar *this, MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::StatusBar::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::StatusBar::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mStyle = Style_Statusbar;
  this->mMinItemWidths[0] = 18;
  this->mMinItemWidths[1] = 300;
  this->mMinItemWidths[2] = 800;
  this->mMinItemWidths[3] = 80;
  this->mMinItemWidths[4] = 80;
  this->mMinItemWidths[5] = 109;
  this->mMinItemWidths[6] = 91;
  this->mMinItemWidths[7] = 255;
  this->mMinItemWidths[8] = 100;
  this->mMinItemWidths[9] = 75;
  this->mMinItemWidths[10] = 75;
  this->mMinItemWidths[11] = 75;
  this->mMinItemWidths[12] = 200;
}

// File Line: 42
// RVA: 0x202940
void __fastcall UFG::Editor::StatusBar::StatusBar(UFG::Editor::StatusBar *this)
{
  int *mMinItemWidths; // rsi
  int *mItemWidths; // rdi
  __int64 i; // rcx

  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::StatusBar", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::StatusBar::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::StatusBar::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mStyle = Style_Statusbar;
  mMinItemWidths = this->mMinItemWidths;
  this->mMinItemWidths[0] = 18;
  this->mMinItemWidths[1] = 300;
  this->mMinItemWidths[2] = 800;
  this->mMinItemWidths[3] = 80;
  this->mMinItemWidths[4] = 80;
  this->mMinItemWidths[5] = 109;
  this->mMinItemWidths[6] = 91;
  this->mMinItemWidths[7] = 255;
  this->mMinItemWidths[8] = 100;
  this->mMinItemWidths[9] = 75;
  this->mMinItemWidths[10] = 75;
  this->mMinItemWidths[11] = 75;
  this->mMinItemWidths[12] = 200;
  mItemWidths = this->mItemWidths;
  for ( i = 13i64; i; --i )
    *mItemWidths++ = *mMinItemWidths++;
}

// File Line: 69
// RVA: 0x21D1D0
void __fastcall UFG::Editor::StatusBar::UpdateUI(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  int v2; // ebx
  bool *p_mNext; // rax
  __int64 v6; // rax
  int v7; // r9d
  int *mMinItemWidths; // rdx
  int v9; // r10d
  __int64 v10; // r8
  int v11; // ecx
  int v12; // ecx
  int v13; // r8d
  int *v14; // rax
  __int64 v15; // rdx
  int *v16; // rdx
  int v17; // ecx
  int v18; // r10d
  int *v19; // r8
  float v20; // xmm0_4
  int v21; // ecx
  float v22; // xmm0_4
  int v23; // ecx
  float v24; // xmm0_4
  int v25; // ecx
  float v26; // xmm0_4
  int v27; // ecx
  float v28; // xmm0_4
  int v29; // ecx
  float v30; // xmm0_4
  UFG::qBaseTreeRB *Layer; // rax
  char *v32; // rax
  char *v33; // rdx
  UFG::Editor::NavigationMode mNavigationMode; // edx
  char v35[64]; // [rsp+30h] [rbp-188h] BYREF
  char name[16]; // [rsp+70h] [rbp-148h] BYREF
  char v37[16]; // [rsp+80h] [rbp-138h] BYREF
  char dest[256]; // [rsp+90h] [rbp-128h] BYREF
  UFG::qSymbol result; // [rsp+1C0h] [rbp+8h] BYREF

  v2 = 0;
  if ( !UFG::Editor::mInitialized
    || (p_mNext = (bool *)&UFG::Editor::mViews.mNode.mNext[-1].mNext,
        (bool *)&UFG::Editor::mViews.mNode.mNext[-1].mNext == &UFG::Editor::mSavedGameRenderFeatures.mAO) )
  {
LABEL_5:
    p_mNext = 0i64;
  }
  else
  {
    while ( !p_mNext[88] )
    {
      p_mNext = (bool *)(*((_QWORD *)p_mNext + 2) - 8i64);
      if ( p_mNext == &UFG::Editor::mSavedGameRenderFeatures.mAO )
        goto LABEL_5;
    }
  }
  v6 = *((_QWORD *)p_mNext + 9);
  v7 = 0;
  mMinItemWidths = this->mMinItemWidths;
  v9 = *(_DWORD *)(v6 + 32);
  LODWORD(v6) = *(_DWORD *)(v6 + 36);
  this->mRect.mX = 0;
  this->mRect.mW = v9;
  this->mRect.mH = 24;
  this->mRect.mY = v6 - 24;
  v10 = 13i64;
  do
  {
    v11 = *mMinItemWidths;
    if ( *(mMinItemWidths - 13) > *mMinItemWidths )
      v11 = *(mMinItemWidths - 13);
    *(++mMinItemWidths - 14) = v11;
    v7 += *(mMinItemWidths - 1);
    --v10;
  }
  while ( v10 );
  v12 = 0;
  v13 = 0;
  this->mItemWidths[0] = this->mMinItemWidths[0];
  v14 = &this->mItemWidths[1];
  v15 = 6i64;
  do
  {
    v12 += *(v14 - 1);
    v13 += *v14;
    v14 += 2;
    --v15;
  }
  while ( v15 );
  v16 = &this->mItemWidths[12];
  v17 = this->mItemWidths[12] + v13 + v12 - v9;
  if ( v17 > 0 || v9 < v7 )
  {
    v18 = 12;
    v19 = &this->mMinItemWidths[12];
    do
    {
      v20 = (float)v17;
      if ( (float)v17 >= (float)(*v16 - *v19) )
        v20 = (float)(*v16 - *v19);
      v21 = v17 - (int)v20;
      *v16 -= (int)v20;
      if ( v21 <= 0 )
        break;
      v22 = (float)v21;
      if ( (float)v21 >= (float)(*(v16 - 1) - *(v19 - 1)) )
        v22 = (float)(*(v16 - 1) - *(v19 - 1));
      v23 = v21 - (int)v22;
      *(v16 - 1) -= (int)v22;
      if ( v23 <= 0 )
        break;
      v24 = (float)v23;
      if ( (float)v23 >= (float)(*(v16 - 2) - *(v19 - 2)) )
        v24 = (float)(*(v16 - 2) - *(v19 - 2));
      v25 = v23 - (int)v24;
      *(v16 - 2) -= (int)v24;
      if ( v25 <= 0 )
        break;
      v26 = (float)v25;
      if ( (float)v25 >= (float)(*(v16 - 3) - *(v19 - 3)) )
        v26 = (float)(*(v16 - 3) - *(v19 - 3));
      v27 = v25 - (int)v26;
      *(v16 - 3) -= (int)v26;
      if ( v27 <= 0 )
        break;
      v28 = (float)v27;
      if ( (float)v27 >= (float)(*(v16 - 4) - *(v19 - 4)) )
        v28 = (float)(*(v16 - 4) - *(v19 - 4));
      v29 = v27 - (int)v28;
      *(v16 - 4) -= (int)v28;
      if ( v29 <= 0 )
        break;
      v30 = (float)v29;
      if ( (float)v29 >= (float)(*(v16 - 5) - *(v19 - 5)) )
        v30 = (float)(*(v16 - 5) - *(v19 - 5));
      v17 = v29 - (int)v30;
      *(v16 - 5) -= (int)v30;
      if ( v17 <= 0 )
        break;
      v18 -= 6;
      v19 -= 6;
      v16 -= 6;
    }
    while ( v18 > 0 );
  }
  UFG::DUIContext::BeginGridLayout(
    dui,
    13,
    1,
    this->mItemWidths,
    0i64,
    LayoutFlag_GridSplitting|LayoutFlag_FillLastCell);
  UFG::DUIContext::PushColour(dui, TextColour, &UFG::qColour::Green);
  while ( 2 )
  {
    switch ( v2 )
    {
      case 0:
        UFG::Editor::StatusBar::UpdateUI_Connected(this, dui);
        goto LABEL_63;
      case 1:
        if ( stru_142040928.size == 1
          && UFG::Editor::DAGPath::GetSystemName(&gWorkingLayerPath, &result)->mUID == UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID
          && (Layer = UFG::Scene::FindLayer(&UFG::Scene::msDefault, stru_142040928.p)) != 0i64 )
        {
          v32 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&Layer->mRoot.mUID);
        }
        else
        {
          v32 = "NONE";
        }
        UFG::qSPrintf(dest, 256, "LYR: %s", v32);
        v33 = dest;
        goto LABEL_62;
      case 2:
        UFG::Editor::StatusBar::UpdateUI_Selected(this, dui);
        goto LABEL_63;
      case 3:
        UFG::Editor::StatusBar::UpdateUI_DetailMode(this, dui);
        goto LABEL_63;
      case 4:
        mNavigationMode = UFG::Editor::gOptions.mGlobal->mNavigationMode;
        if ( mNavigationMode )
        {
          if ( mNavigationMode == NavigationMode_Fly )
            UFG::qSPrintf(v35, 64, "NAV: FLY");
        }
        else
        {
          UFG::qSPrintf(v35, 64, "NAV: ORB");
        }
        goto LABEL_49;
      case 5:
        UFG::Editor::StatusBar::UpdateUI_GridSpacing(this, dui);
        goto LABEL_63;
      case 6:
        UFG::qSPrintf(v35, 64, "STM: GAME");
        if ( UFG::Metrics::msInstance.mSimPausedInGame
          || UFG::Metrics::msInstance.mSimPausedDebug
          || UFG::Metrics::msInstance.mSimTimeScaleDebug <= 0.0 )
        {
          UFG::qSPrintf(v35, 64, "STM: PAUSED");
LABEL_49:
          v33 = v35;
        }
        else
        {
          UFG::qSPrintf(v35, 64, "STM: %f", UFG::Metrics::msInstance.mSimTimeScaleDebug);
          v33 = v35;
        }
LABEL_62:
        UFG::DUIContext::Label(dui, v33);
LABEL_63:
        if ( ++v2 < 13 )
          continue;
        UFG::DUIContext::PopColour(dui, 0);
        UFG::DUIContext::EndLayoutHorizontal(dui);
        return;
      case 7:
        UFG::Editor::StatusBar::UpdateUI_CamPos(this, dui);
        goto LABEL_63;
      case 8:
        UFG::Editor::StatusBar::UpdateUI_ActiveView(this, dui);
        goto LABEL_63;
      case 9:
        UFG::qSPrintf(v35, 64, "FPS: %.2d", UFG::Metrics::msFramesPerSec);
        v33 = v35;
        goto LABEL_62;
      case 10:
        UFG::qSPrintf(v37, 16, "HID: %d", (unsigned int)UFG::Editor::VisibilityManager::mNumHidden);
        v33 = v37;
        goto LABEL_62;
      case 11:
        UFG::qSPrintf(name, 16, "FRZ: %d", (unsigned int)UFG::Editor::FreezeManager::mNumFrozen);
        v33 = name;
        goto LABEL_62;
      case 12:
        UFG::Editor::StatusBar::UpdateUI_Hovered(this, dui);
        goto LABEL_63;
      default:
        goto LABEL_63;
    }
  }
}

// File Line: 174
// RVA: 0x21DD40
void __fastcall UFG::Editor::StatusBar::UpdateUI_Connected(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  unsigned int v3; // eax
  int mY; // r8d
  int mX; // edx
  UFG::DUIRect v6; // [rsp+30h] [rbp-38h]
  UFG::DUIRect result; // [rsp+40h] [rbp-28h] BYREF
  UFG::DUIRect rect; // [rsp+50h] [rbp-18h] BYREF

  v3 = _S27;
  if ( (_S27 & 1) == 0 )
  {
    _S27 |= 1u;
    connectedImg = UFG::qStringHashUpper32("Editor_Connected", -1);
    v3 = _S27;
  }
  if ( (v3 & 2) == 0 )
  {
    _S27 = v3 | 2;
    disconnectedImg = UFG::qStringHashUpper32("Editor_Disconnected", -1);
  }
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  mY = dui->mTheme.mButton_Inset.mY;
  mX = dui->mTheme.mButton_Inset.mX;
  v6.mX = mX + _mm_cvtsi128_si32((__m128i)result);
  v6.mW = result.mW - 2 * mX;
  v6.mY = mY + result.mY;
  v6.mH = result.mH - 2 * mY;
  rect = v6;
  UFG::DUIContext::RenderRect(dui, &rect, &UFG::qColour::White, disconnectedImg);
}

// File Line: 202
// RVA: 0x21E0D0
void __fastcall UFG::Editor::StatusBar::UpdateUI_Selected(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  int mNext; // eax
  UFG::Editor::DAGPath *mPrev; // rbx
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rax
  UFG::Editor::DAGPath v8; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v9; // [rsp+78h] [rbp-80h]
  UFG::qString v10; // [rsp+80h] [rbp-78h] BYREF
  char dest[520]; // [rsp+A8h] [rbp-50h] BYREF

  v9 = -2i64;
  mNext = (int)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext;
  if ( mNext <= 1 )
  {
    if ( mNext == 1 )
    {
      mPrev = (UFG::Editor::DAGPath *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[4].mPrev;
      v8.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v8;
      v8.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v8;
      v8.mFnObject.mPtr = 0i64;
      v8.mFnObject.mTypeId = -1998658210;
      v8.mSystemName.mUID = -1;
      v8.mElements.p = 0i64;
      *(_QWORD *)&v8.mElements.size = 0i64;
      UFG::qArray<UFG::qSymbol,0>::Reallocate(&v8.mElements, 4u, "qArray.Reallocate(Constructor)");
      v8.mInterfaceName.mUID = -1;
      memset(&v8.mSubElements, 0, 20);
      if ( mPrev != &v8 )
      {
        UFG::Editor::DAGPath::Clear(&v8);
        if ( v8.mPathType == Default )
        {
          mPtr = mPrev->mFnObject.mPtr;
          if ( !v8.mFnObject.mPtr )
          {
            if ( mPtr )
            {
              v8.mFnObject.mTypeId = mPtr->mTypeId;
              v8.mFnObject.mPtr = mPtr;
              p_mNode = &mPtr->mSmartHandleList.mNode;
              v7 = p_mNode->mPrev;
              v7->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v8;
              v8.mFnObject.mPrev = v7;
              v8.mFnObject.mNext = p_mNode;
              p_mNode->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v8;
            }
          }
        }
        v8.mSystemName.mUID = mPrev->mSystemName.mUID;
        UFG::qArray<UFG::qSymbol,0>::Clone(&mPrev->mElements, &v8.mElements);
        v8.mInterfaceName.mUID = mPrev->mInterfaceName.mUID;
        UFG::qArray<UFG::qString,0>::Clone(&mPrev->mSubElements, &v8.mSubElements);
      }
      if ( v8.mElements.size )
      {
        UFG::qString::qString(&v10);
        UFG::Editor::DAGPath::GetAsString(&v8, &v10, 1);
        UFG::qSPrintf(dest, 512, "SEL: %s", v10.mData);
        UFG::qString::~qString(&v10);
      }
      else
      {
        UFG::qSPrintf(dest, 512, "SEL: ERROR");
      }
      UFG::Editor::DAGPath::~DAGPath(&v8);
    }
    else
    {
      UFG::qSPrintf(dest, 512, "SEL: NONE");
    }
  }
  else
  {
    UFG::qSPrintf(dest, 512, "SEL: MULTIPLE (%d)", (unsigned int)mNext);
  }
  UFG::DUIContext::Label(dui, dest);
}

// File Line: 236
// RVA: 0x21DE30
void __fastcall UFG::Editor::StatusBar::UpdateUI_DetailMode(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  int mNext; // r14d
  int v4; // edi
  int v5; // esi
  UFG::Editor::DAGPath *mPrev; // rbx
  __int64 mNext_low; // rbp
  const char *v8; // r8
  char dest[88]; // [rsp+20h] [rbp-58h] BYREF

  mNext = (int)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext;
  if ( mNext > 0 )
  {
    v4 = 0;
    v5 = 0;
    mPrev = (UFG::Editor::DAGPath *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[4].mPrev;
    mNext_low = LODWORD(UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext);
    do
    {
      if ( UFG::Editor::SubobjectManager::IsInSubobjectMode(mPrev) )
        ++v4;
      else
        ++v5;
      ++mPrev;
      --mNext_low;
    }
    while ( mNext_low );
    if ( v4 == mNext )
    {
      UFG::qSPrintf(dest, 64, "DET: ON");
    }
    else
    {
      v8 = "DET: OFF";
      if ( v5 != mNext )
        v8 = "DET: MIX";
      UFG::qSPrintf(dest, 64, v8);
    }
    UFG::DUIContext::Label(dui, dest);
  }
  else
  {
    UFG::qSPrintf(dest, 64, "DET: NONE");
    UFG::DUIContext::Label(dui, dest);
  }
}

// File Line: 292
// RVA: 0x21DF20
void __fastcall UFG::Editor::StatusBar::UpdateUI_GridSpacing(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **p_mNext; // rax
  const char *v4; // r8
  char dest[72]; // [rsp+20h] [rbp-48h] BYREF

  UFG::qSPrintf(dest, 64, "GRD: NONE");
  if ( !UFG::Editor::mInitialized
    || (p_mNext = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
LABEL_5:
    p_mNext = 0i64;
  }
  else
  {
    while ( !*((_BYTE *)p_mNext + 88) )
    {
      p_mNext = &p_mNext[2][-1].mNext;
      if ( p_mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  v4 = "GRD: %.2f (A)";
  if ( !BYTE5(p_mNext[8][10].mPrev) )
    v4 = "GRD: %.2f";
  UFG::qSPrintf(dest, 64, v4, *((float *)p_mNext + 23));
  UFG::DUIContext::Label(dui, dest);
}

// File Line: 324
// RVA: 0x21DC30
void __fastcall UFG::Editor::StatusBar::UpdateUI_CamPos(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  float *p_mFOVOffset; // rbx
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **p_mNext; // rax
  float *v5; // rdi
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  UFG::BaseCameraComponent *v8; // rcx
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  char dest[128]; // [rsp+30h] [rbp-88h] BYREF

  p_mFOVOffset = 0i64;
  if ( !UFG::Editor::mInitialized
    || (p_mNext = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
LABEL_5:
    p_mNext = 0i64;
  }
  else
  {
    while ( !*((_BYTE *)p_mNext + 88) )
    {
      p_mNext = &p_mNext[2][-1].mNext;
      if ( p_mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  v5 = (float *)p_mNext[10];
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && (p_mCamera = &mCurrentCamera->mCamera) != 0i64 && !p_mCamera->bUseOverrideMatrices )
  {
    v8 = UFG::Director::Get()->mCurrentCamera;
    if ( v8 )
      p_mFOVOffset = &v8->mCamera.mFOVOffset;
    v9 = p_mFOVOffset[44];
    v10 = p_mFOVOffset[45];
    v11 = p_mFOVOffset[46];
  }
  else
  {
    v9 = v5[44];
    v10 = v5[45];
    v11 = v5[46];
  }
  UFG::qSPrintf(dest, 128, "CAM: %09.3f %09.3f %09.3f", v9, v10, v11);
  UFG::DUIContext::Label(dui, dest);
}

// File Line: 336
// RVA: 0x21DB60
void __fastcall UFG::Editor::StatusBar::UpdateUI_ActiveView(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **p_mNext; // rdx
  UFG::qString v4; // [rsp+38h] [rbp-70h] BYREF
  char dest[72]; // [rsp+60h] [rbp-48h] BYREF

  UFG::qSPrintf(dest, 64, "VIEW: NONE");
  UFG::qString::qString(&v4);
  if ( !UFG::Editor::mInitialized
    || (p_mNext = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
LABEL_5:
    p_mNext = 0i64;
  }
  else
  {
    while ( !*((_BYTE *)p_mNext + 88) )
    {
      p_mNext = &p_mNext[2][-1].mNext;
      if ( p_mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  UFG::qString::Set(&v4, (const char *)p_mNext[6], *((_DWORD *)p_mNext + 11), 0i64, 0);
  UFG::qSPrintf(dest, 64, "VIEW: %s", v4.mData);
  UFG::DUIContext::Label(dui, dest);
  UFG::qString::~qString(&v4);
}

// File Line: 384
// RVA: 0x21DFD0
void __fastcall UFG::Editor::StatusBar::UpdateUI_Hovered(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  int v3; // ecx
  UFG::qNode<UFG::Editor::HoverItem,UFG::Editor::HoverItem> *mNext; // rbx
  UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-230h] BYREF
  char dest[520]; // [rsp+50h] [rbp-208h] BYREF

  v3 = 0;
  mNext = UFG::Editor::mHoverObjectList.mNode.mNext;
  v5 = (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)UFG::Editor::mHoverObjectList.mNode.mNext;
  if ( (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)UFG::Editor::mHoverObjectList.mNode.mNext == &UFG::Editor::mHoverObjectList )
    goto LABEL_10;
  do
  {
    ++v3;
    v5 = (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)v5->mNode.mNext;
  }
  while ( v5 != &UFG::Editor::mHoverObjectList );
  if ( v3 > 1 )
  {
    UFG::qSPrintf(dest, 512, "HOV: MULTIPLE (%d)", (unsigned int)v3);
    goto LABEL_11;
  }
  if ( v3 != 1 )
  {
LABEL_10:
    UFG::qSPrintf(dest, 512, "HOV: NONE");
    goto LABEL_11;
  }
  if ( !UFG::Editor::mHoverObjectList.mNode.mNext
    || (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)UFG::Editor::mHoverObjectList.mNode.mNext == &UFG::Editor::mHoverObjectList )
  {
    UFG::qSPrintf(dest, 512, "HOV: ERROR");
  }
  else
  {
    UFG::qString::qString(&v6);
    UFG::Editor::DAGPath::GetAsString((UFG::Editor::DAGPath *)&mNext[1], &v6, 0);
    UFG::qSPrintf(dest, 512, "HOV: %s", v6.mData);
    UFG::qString::~qString(&v6);
  }
LABEL_11:
  UFG::DUIContext::Label(dui, dest);
}

