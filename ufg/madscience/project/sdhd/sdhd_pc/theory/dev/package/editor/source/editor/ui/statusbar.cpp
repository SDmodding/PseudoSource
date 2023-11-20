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
  UFG::Editor::StatusBar *v2; // rbx

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::StatusBar::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::StatusBar::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->mStyle = 257;
  v2->mMinItemWidths[0] = 18;
  v2->mMinItemWidths[1] = 300;
  v2->mMinItemWidths[2] = 800;
  v2->mMinItemWidths[3] = 80;
  v2->mMinItemWidths[4] = 80;
  v2->mMinItemWidths[5] = 109;
  v2->mMinItemWidths[6] = 91;
  v2->mMinItemWidths[7] = 255;
  v2->mMinItemWidths[8] = 100;
  v2->mMinItemWidths[9] = 75;
  v2->mMinItemWidths[10] = 75;
  v2->mMinItemWidths[11] = 75;
  v2->mMinItemWidths[12] = 200;
}

// File Line: 42
// RVA: 0x202940
void __fastcall UFG::Editor::StatusBar::StatusBar(UFG::Editor::StatusBar *this)
{
  UFG::Editor::StatusBar *v1; // rbx
  int *v2; // rsi
  int *v3; // rdi
  signed __int64 i; // rcx

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::StatusBar,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::StatusBar", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::StatusBar::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::StatusBar::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mStyle = 257;
  v2 = v1->mMinItemWidths;
  v1->mMinItemWidths[0] = 18;
  v1->mMinItemWidths[1] = 300;
  v1->mMinItemWidths[2] = 800;
  v1->mMinItemWidths[3] = 80;
  v1->mMinItemWidths[4] = 80;
  v1->mMinItemWidths[5] = 109;
  v1->mMinItemWidths[6] = 91;
  v1->mMinItemWidths[7] = 255;
  v1->mMinItemWidths[8] = 100;
  v1->mMinItemWidths[9] = 75;
  v1->mMinItemWidths[10] = 75;
  v1->mMinItemWidths[11] = 75;
  v1->mMinItemWidths[12] = 200;
  v3 = v1->mItemWidths;
  for ( i = 13i64; i; --i )
  {
    *v3 = *v2;
    ++v2;
    ++v3;
  }
}

// File Line: 69
// RVA: 0x21D1D0
void __fastcall UFG::Editor::StatusBar::UpdateUI(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  int v2; // ebx
  UFG::DUIContext *v3; // rsi
  UFG::Editor::StatusBar *v4; // rdi
  bool *v5; // rax
  __int64 v6; // rax
  int v7; // er9
  int *v8; // rdx
  int v9; // er10
  signed __int64 v10; // r8
  int v11; // ecx
  int v12; // ecx
  int v13; // er8
  int *v14; // rax
  signed __int64 v15; // rdx
  int *v16; // rdx
  int v17; // ecx
  signed int v18; // er10
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
  UFG::qBaseTreeRB *v31; // rax
  char *v32; // rax
  char *v33; // rdx
  UFG::Editor::NavigationMode v34; // edx
  const char *v35; // r8
  char v36; // [rsp+30h] [rbp-188h]
  char name; // [rsp+70h] [rbp-148h]
  char v38; // [rsp+80h] [rbp-138h]
  char dest; // [rsp+90h] [rbp-128h]
  UFG::qSymbol result; // [rsp+1C0h] [rbp+8h]

  v2 = 0;
  v3 = dui;
  v4 = this;
  if ( UFG::Editor::mInitialized
    && (v5 = (bool *)&UFG::Editor::mViews.mNode.mNext[-1].mNext,
        (bool *)&UFG::Editor::mViews.mNode.mNext[-1].mNext != &UFG::Editor::mSavedGameRenderFeatures.mAO) )
  {
    while ( !v5[88] )
    {
      v5 = (bool *)(*((_QWORD *)v5 + 2) - 8i64);
      if ( v5 == &UFG::Editor::mSavedGameRenderFeatures.mAO )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v5 = 0i64;
  }
  v6 = *((_QWORD *)v5 + 9);
  v7 = 0;
  v8 = this->mMinItemWidths;
  v9 = *(_DWORD *)(v6 + 32);
  LODWORD(v6) = *(_DWORD *)(v6 + 36);
  this->mRect.mX = 0;
  this->mRect.mW = v9;
  this->mRect.mH = 24;
  this->mRect.mY = v6 - 24;
  v10 = 13i64;
  do
  {
    v11 = *v8;
    if ( *(v8 - 13) > *v8 )
      v11 = *(v8 - 13);
    ++v8;
    *(v8 - 14) = v11;
    v7 += *(v8 - 1);
    --v10;
  }
  while ( v10 );
  v12 = 0;
  v13 = 0;
  v4->mItemWidths[0] = v4->mMinItemWidths[0];
  v14 = &v4->mItemWidths[1];
  v15 = 6i64;
  do
  {
    v12 += *(v14 - 1);
    v13 += *v14;
    v14 += 2;
    --v15;
  }
  while ( v15 );
  v16 = &v4->mItemWidths[12];
  v17 = v4->mItemWidths[12] + v13 + v12 - v9;
  if ( v17 > 0 || v9 < v7 )
  {
    v18 = 12;
    v19 = &v4->mMinItemWidths[12];
    do
    {
      v20 = (float)v17;
      if ( (float)v17 >= (float)(*v16 - *v19) )
        v20 = (float)(*v16 - *v19);
      v21 = v17 - (signed int)v20;
      *v16 -= (signed int)v20;
      if ( v21 <= 0 )
        break;
      v22 = (float)v21;
      if ( (float)v21 >= (float)(*(v16 - 1) - *(v19 - 1)) )
        v22 = (float)(*(v16 - 1) - *(v19 - 1));
      v23 = v21 - (signed int)v22;
      *(v16 - 1) -= (signed int)v22;
      if ( v23 <= 0 )
        break;
      v24 = (float)v23;
      if ( (float)v23 >= (float)(*(v16 - 2) - *(v19 - 2)) )
        v24 = (float)(*(v16 - 2) - *(v19 - 2));
      v25 = v23 - (signed int)v24;
      *(v16 - 2) -= (signed int)v24;
      if ( v25 <= 0 )
        break;
      v26 = (float)v25;
      if ( (float)v25 >= (float)(*(v16 - 3) - *(v19 - 3)) )
        v26 = (float)(*(v16 - 3) - *(v19 - 3));
      v27 = v25 - (signed int)v26;
      *(v16 - 3) -= (signed int)v26;
      if ( v27 <= 0 )
        break;
      v28 = (float)v27;
      if ( (float)v27 >= (float)(*(v16 - 4) - *(v19 - 4)) )
        v28 = (float)(*(v16 - 4) - *(v19 - 4));
      v29 = v27 - (signed int)v28;
      *(v16 - 4) -= (signed int)v28;
      if ( v29 <= 0 )
        break;
      v30 = (float)v29;
      if ( (float)v29 >= (float)(*(v16 - 5) - *(v19 - 5)) )
        v30 = (float)(*(v16 - 5) - *(v19 - 5));
      v17 = v29 - (signed int)v30;
      *(v16 - 5) -= (signed int)v30;
      if ( v17 <= 0 )
        break;
      v18 -= 6;
      v19 -= 6;
      v16 -= 6;
    }
    while ( v18 > 0 );
  }
  UFG::DUIContext::BeginGridLayout(v3, 13, 1, v4->mItemWidths, 0i64, 11);
  UFG::DUIContext::PushColour(v3, 0, &UFG::qColour::Green);
  while ( 2 )
  {
    switch ( v2 )
    {
      case 0:
        UFG::Editor::StatusBar::UpdateUI_Connected(v4, v3);
        goto LABEL_64;
      case 1:
        if ( stru_142040928.size == 1
          && UFG::Editor::DAGPath::GetSystemName(&gWorkingLayerPath, &result)->mUID == UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID
          && (v31 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, stru_142040928.p)) != 0i64 )
        {
          v32 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v31->mRoot.mUID);
        }
        else
        {
          v32 = "NONE";
        }
        UFG::qSPrintf(&dest, 256, "LYR: %s", v32);
        v33 = &dest;
        goto LABEL_63;
      case 2:
        UFG::Editor::StatusBar::UpdateUI_Selected(v4, v3);
        goto LABEL_64;
      case 3:
        UFG::Editor::StatusBar::UpdateUI_DetailMode(v4, v3);
        goto LABEL_64;
      case 4:
        v34 = UFG::Editor::gOptions.mGlobal->mNavigationMode;
        if ( v34 )
        {
          if ( v34 != 1 )
            goto LABEL_50;
          v35 = "NAV: FLY";
        }
        else
        {
          v35 = "NAV: ORB";
        }
        goto LABEL_49;
      case 5:
        UFG::Editor::StatusBar::UpdateUI_GridSpacing(v4, v3);
        goto LABEL_64;
      case 6:
        UFG::qSPrintf(&v36, 64, "STM: GAME");
        if ( UFG::Metrics::msInstance.mSimPausedInGame
          || UFG::Metrics::msInstance.mSimPausedDebug
          || UFG::Metrics::msInstance.mSimTimeScaleDebug <= 0.0 )
        {
          v35 = "STM: PAUSED";
LABEL_49:
          UFG::qSPrintf(&v36, 64, v35);
LABEL_50:
          v33 = &v36;
        }
        else
        {
          UFG::qSPrintf(&v36, 64, "STM: %f", UFG::Metrics::msInstance.mSimTimeScaleDebug);
          v33 = &v36;
        }
LABEL_63:
        UFG::DUIContext::Label(v3, v33);
LABEL_64:
        if ( ++v2 < 13 )
          continue;
        UFG::DUIContext::PopColour(v3, 0);
        UFG::DUIContext::EndLayoutHorizontal(v3);
        return;
      case 7:
        UFG::Editor::StatusBar::UpdateUI_CamPos(v4, v3);
        goto LABEL_64;
      case 8:
        UFG::Editor::StatusBar::UpdateUI_ActiveView(v4, v3);
        goto LABEL_64;
      case 9:
        UFG::qSPrintf(&v36, 64, "FPS: %.2d", UFG::Metrics::msFramesPerSec);
        v33 = &v36;
        goto LABEL_63;
      case 10:
        UFG::qSPrintf(&v38, 16, "HID: %d", (unsigned int)UFG::Editor::VisibilityManager::mNumHidden);
        v33 = &v38;
        goto LABEL_63;
      case 11:
        UFG::qSPrintf(&name, 16, "FRZ: %d", (unsigned int)UFG::Editor::FreezeManager::mNumFrozen);
        v33 = &name;
        goto LABEL_63;
      case 12:
        UFG::Editor::StatusBar::UpdateUI_Hovered(v4, v3);
        goto LABEL_64;
      default:
        goto LABEL_64;
    }
  }
}

// File Line: 174
// RVA: 0x21DD40
void __fastcall UFG::Editor::StatusBar::UpdateUI_Connected(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rbx
  unsigned int v3; // eax
  UFG::DUIRect v4; // xmm0
  int v5; // er8
  int v6; // edx
  __m128i v7; // [rsp+30h] [rbp-38h]
  UFG::DUIRect result; // [rsp+40h] [rbp-28h]
  UFG::DUIRect rect; // [rsp+50h] [rbp-18h]

  v2 = dui;
  v3 = _S27;
  if ( !(_S27 & 1) )
  {
    _S27 |= 1u;
    connectedImg = UFG::qStringHashUpper32("Editor_Connected", 0xFFFFFFFF);
    v3 = _S27;
  }
  if ( !(v3 & 2) )
  {
    _S27 = v3 | 2;
    disconnectedImg = UFG::qStringHashUpper32("Editor_Disconnected", 0xFFFFFFFF);
  }
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  v4 = result;
  _mm_store_si128(&v7, (__m128i)result);
  v5 = v2->mTheme.mButton_Inset.mY;
  v6 = v2->mTheme.mButton_Inset.mX;
  v7.m128i_i32[0] = v6 + _mm_cvtsi128_si32((__m128i)v4);
  v7.m128i_i32[2] -= 2 * v6;
  v7.m128i_i32[1] += v5;
  v7.m128i_i32[3] -= 2 * v5;
  _mm_store_si128((__m128i *)&rect, v7);
  UFG::DUIContext::RenderRect(v2, &rect, &UFG::qColour::White, disconnectedImg);
}

// File Line: 202
// RVA: 0x21E0D0
void __fastcall UFG::Editor::StatusBar::UpdateUI_Selected(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  signed int v3; // eax
  UFG::Editor::DAGPath *v4; // rbx
  UFG::Editor::SmartHandleObject *v5; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v6; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v7; // rax
  UFG::Editor::DAGPath v8; // [rsp+20h] [rbp-D8h]
  __int64 v9; // [rsp+78h] [rbp-80h]
  UFG::qString v10; // [rsp+80h] [rbp-78h]
  char dest; // [rsp+A8h] [rbp-50h]

  v9 = -2i64;
  v2 = dui;
  v3 = (signed int)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext;
  if ( v3 <= 1 )
  {
    if ( v3 == 1 )
    {
      v4 = (UFG::Editor::DAGPath *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[4].mPrev;
      v8.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v8;
      v8.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v8;
      v8.mFnObject.mPtr = 0i64;
      v8.mFnObject.mTypeId = -1998658210;
      v8.mSystemName.mUID = -1;
      v8.mElements.p = 0i64;
      *(_QWORD *)&v8.mElements.size = 0i64;
      UFG::qArray<UFG::qSymbol,0>::Reallocate(&v8.mElements, 4u, "qArray.Reallocate(Constructor)");
      v8.mInterfaceName.mUID = -1;
      v8.mSubElements.p = 0i64;
      *(_QWORD *)&v8.mSubElements.size = 0i64;
      v8.mPathType = 0;
      if ( v4 != &v8 )
      {
        UFG::Editor::DAGPath::Clear(&v8);
        if ( v8.mPathType == Default )
        {
          v5 = v4->mFnObject.mPtr;
          if ( !v8.mFnObject.mPtr )
          {
            if ( v5 )
            {
              v8.mFnObject.mTypeId = v5->mTypeId;
              v8.mFnObject.mPtr = v5;
              v6 = &v5->mSmartHandleList.mNode;
              v7 = v6->mPrev;
              v7->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v8;
              v8.mFnObject.mPrev = v7;
              v8.mFnObject.mNext = v6;
              v6->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v8;
            }
          }
        }
        v8.mSystemName.mUID = v4->mSystemName.mUID;
        UFG::qArray<UFG::qSymbol,0>::Clone(&v4->mElements, &v8.mElements);
        v8.mInterfaceName.mUID = v4->mInterfaceName.mUID;
        UFG::qArray<UFG::qString,0>::Clone(&v4->mSubElements, &v8.mSubElements);
      }
      if ( v8.mElements.size )
      {
        UFG::qString::qString(&v10);
        UFG::Editor::DAGPath::GetAsString(&v8, &v10, 1);
        UFG::qSPrintf(&dest, 512, "SEL: %s", v10.mData, v8.mFnObject.mPrev, v8.mFnObject.mNext);
        UFG::qString::~qString(&v10);
      }
      else
      {
        UFG::qSPrintf(&dest, 512, "SEL: ERROR");
      }
      UFG::Editor::DAGPath::~DAGPath(&v8);
    }
    else
    {
      UFG::qSPrintf(&dest, 512, "SEL: NONE");
    }
  }
  else
  {
    UFG::qSPrintf(&dest, 512, "SEL: MULTIPLE (%d)", (unsigned int)v3);
  }
  UFG::DUIContext::Label(v2, &dest);
}

// File Line: 236
// RVA: 0x21DE30
void __fastcall UFG::Editor::StatusBar::UpdateUI_DetailMode(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // r15
  int v3; // er14
  int v4; // edi
  int v5; // esi
  UFG::Editor::DAGPath *v6; // rbx
  __int64 v7; // rbp
  const char *v8; // r8
  char dest; // [rsp+20h] [rbp-58h]

  v2 = dui;
  v3 = (int)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext;
  if ( v3 > 0 )
  {
    v4 = 0;
    v5 = 0;
    if ( v3 )
    {
      v6 = (UFG::Editor::DAGPath *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[4].mPrev;
      v7 = LODWORD(UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext);
      do
      {
        if ( UFG::Editor::SubobjectManager::IsInSubobjectMode(v6) )
          ++v4;
        else
          ++v5;
        ++v6;
        --v7;
      }
      while ( v7 );
    }
    if ( v4 == v3 )
    {
      v8 = "DET: ON";
    }
    else
    {
      v8 = "DET: OFF";
      if ( v5 != v3 )
        v8 = "DET: MIX";
    }
    UFG::qSPrintf(&dest, 64, v8);
    UFG::DUIContext::Label(v2, &dest);
  }
  else
  {
    UFG::qSPrintf(&dest, 64, "DET: NONE");
    UFG::DUIContext::Label(v2, &dest);
  }
}

// File Line: 292
// RVA: 0x21DF20
void __fastcall UFG::Editor::StatusBar::UpdateUI_GridSpacing(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rbx
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **v3; // rax
  const char *v4; // r8
  char dest; // [rsp+20h] [rbp-48h]

  v2 = dui;
  UFG::qSPrintf(&dest, 64, "GRD: NONE");
  if ( UFG::Editor::mInitialized
    && (v3 = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
    while ( !*((_BYTE *)v3 + 88) )
    {
      v3 = &v3[2][-1].mNext;
      if ( v3 == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v3 = 0i64;
  }
  v4 = "GRD: %.2f (A)";
  if ( !BYTE5(v3[8][10].mPrev) )
    v4 = "GRD: %.2f";
  UFG::qSPrintf(&dest, 64, v4, *((float *)v3 + 23));
  UFG::DUIContext::Label(v2, &dest);
}

// File Line: 324
// RVA: 0x21DC30
void __fastcall UFG::Editor::StatusBar::UpdateUI_CamPos(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  float *v2; // rbx
  UFG::DUIContext *v3; // rsi
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **v4; // rax
  float *v5; // rdi
  UFG::BaseCameraComponent *v6; // rax
  signed __int64 v7; // rax
  UFG::BaseCameraComponent *v8; // rcx
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  char dest; // [rsp+30h] [rbp-88h]

  v2 = 0i64;
  v3 = dui;
  if ( UFG::Editor::mInitialized
    && (v4 = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
    while ( !*((_BYTE *)v4 + 88) )
    {
      v4 = &v4[2][-1].mNext;
      if ( v4 == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v4 = 0i64;
  }
  v5 = (float *)v4[10];
  v6 = UFG::Director::Get()->mCurrentCamera;
  if ( v6 && (v7 = (signed __int64)&v6->mCamera) != 0 && !*(_BYTE *)(v7 + 256) )
  {
    v8 = UFG::Director::Get()->mCurrentCamera;
    if ( v8 )
      v2 = &v8->mCamera.mFOVOffset;
    v9 = v2[44];
    v10 = v2[45];
    v11 = v2[46];
  }
  else
  {
    v9 = v5[44];
    v10 = v5[45];
    v11 = v5[46];
  }
  UFG::qSPrintf(&dest, 128, "CAM: %09.3f %09.3f %09.3f", v9, v10, v11);
  UFG::DUIContext::Label(v3, &dest);
}

// File Line: 336
// RVA: 0x21DB60
void __fastcall UFG::Editor::StatusBar::UpdateUI_ActiveView(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rbx
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **v3; // rdx
  UFG::qString v4; // [rsp+38h] [rbp-70h]
  char dest; // [rsp+60h] [rbp-48h]

  v2 = dui;
  UFG::qSPrintf(&dest, 64, "VIEW: NONE");
  UFG::qString::qString(&v4);
  if ( UFG::Editor::mInitialized
    && (v3 = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
    while ( !*((_BYTE *)v3 + 88) )
    {
      v3 = &v3[2][-1].mNext;
      if ( v3 == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v3 = 0i64;
  }
  UFG::qString::Set(&v4, (const char *)v3[6], *((_DWORD *)v3 + 11), 0i64, 0);
  UFG::qSPrintf(&dest, 64, "VIEW: %s", v4.mData);
  UFG::DUIContext::Label(v2, &dest);
  UFG::qString::~qString(&v4);
}

// File Line: 384
// RVA: 0x21DFD0
void __fastcall UFG::Editor::StatusBar::UpdateUI_Hovered(UFG::Editor::StatusBar *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  signed int v3; // ecx
  UFG::qNode<UFG::Editor::HoverItem,UFG::Editor::HoverItem> *v4; // rbx
  UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *v5; // rax
  const char *v6; // r8
  UFG::qString v7; // [rsp+28h] [rbp-230h]
  char dest; // [rsp+50h] [rbp-208h]

  v2 = dui;
  v3 = 0;
  v4 = UFG::Editor::mHoverObjectList.mNode.mNext;
  v5 = (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)UFG::Editor::mHoverObjectList.mNode.mNext;
  if ( (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)UFG::Editor::mHoverObjectList.mNode.mNext == &UFG::Editor::mHoverObjectList )
    goto LABEL_10;
  do
  {
    ++v3;
    v5 = (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)v5->mNode.mNext;
  }
  while ( v5 != &UFG::Editor::mHoverObjectList );
  if ( v3 <= 1 )
  {
    if ( v3 == 1 )
    {
      if ( UFG::Editor::mHoverObjectList.mNode.mNext
        && (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)UFG::Editor::mHoverObjectList.mNode.mNext != &UFG::Editor::mHoverObjectList )
      {
        UFG::qString::qString(&v7);
        UFG::Editor::DAGPath::GetAsString((UFG::Editor::DAGPath *)&v4[1], &v7, 0);
        UFG::qSPrintf(&dest, 512, "HOV: %s", v7.mData, -2i64);
        UFG::qString::~qString(&v7);
        goto LABEL_12;
      }
      v6 = "HOV: ERROR";
LABEL_11:
      UFG::qSPrintf(&dest, 512, v6);
      goto LABEL_12;
    }
LABEL_10:
    v6 = "HOV: NONE";
    goto LABEL_11;
  }
  UFG::qSPrintf(&dest, 512, "HOV: MULTIPLE (%d)", (unsigned int)v3, -2i64);
LABEL_12:
  UFG::DUIContext::Label(v2, &dest);
}

