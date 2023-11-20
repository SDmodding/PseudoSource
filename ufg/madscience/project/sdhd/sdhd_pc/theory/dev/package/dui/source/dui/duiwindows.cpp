// File Line: 3
// RVA: 0x1468E20
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::DUIThemeEditorWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::DUIThemeEditorWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::DUIThemeEditorWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 4
// RVA: 0x1468D20
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::DUILogWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::DUILogWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::DUILogWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 17
// RVA: 0x192D30
void __fastcall UFG::DUIThemeEditorWindow::DUIThemeEditorWindow(UFG::DUIThemeEditorWindow *this)
{
  UFG::DUIThemeEditorWindow *v1; // r14

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::DUIThemeEditorWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIThemeEditorWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIThemeEditorWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&v1->mTextBoxString0);
  UFG::qString::qString(&v1->mTextBoxString1);
  UFG::qString::qString(&v1->mTextBoxString2);
  UFG::qString::qString(&v1->mTextBoxString3);
  UFG::qString::qString(&v1->mTextBoxWithSuggestionsString);
  UFG::qString::qString(&v1->mMessageBoxResponse);
  UFG::qString::Set(&v1->mTitle, "Theme Editor");
  v1->mScrollPos = 0i64;
  *(_QWORD *)&v1->mSlider = 1056964608i64;
  v1->mSliderI100 = 0;
  v1->mSliderI1000 = 2048;
  v1->mCollapsable_TextBox = 0;
  UFG::qString::Set(&v1->mTextBoxString0, "Hello, Im textbox one");
  UFG::qString::Set(&v1->mTextBoxString1, "Hello, Im textbox two");
  UFG::qString::Set(&v1->mTextBoxString2, "Hello, Im textbox three");
  UFG::qString::Set(&v1->mTextBoxString3, "Hello, Im textbox four");
  v1->mCollapsable_Comboxbox = 0;
  v1->mComboBoxCurrentIndex = 0;
  *(_WORD *)&v1->mCollapsable_MessageBox = 0;
  v1->mShowMessageBox2 = 0;
  *(_QWORD *)&v1->mCollapsable_DistField = 0i64;
  *(_DWORD *)&v1->mScrollView_IsOpen = 0;
  *(_WORD *)&v1->mSlider_IsOpen = 0;
  v1->mColourPicker_Colour.r = FLOAT_0_5;
  v1->mColourPicker_Colour.g = FLOAT_0_5;
  v1->mColourPicker_Colour.b = FLOAT_0_5;
  v1->mColourPicker_Colour.a = FLOAT_0_5;
}

// File Line: 55
// RVA: 0x1A0EE0
void __fastcall UFG::DUIThemeEditorWindow::UpdateUI(UFG::DUIThemeEditorWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  UFG::DUIThemeEditorWindow *v3; // rsi
  UFG::DUIRect *v4; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v5; // rax
  char *v6; // rbx
  UFG::qString *v7; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  UFG::qString *v11; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rax
  UFG::qString *v15; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  UFG::qString *v19; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v22; // rax
  UFG::qString *v23; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v24; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rax
  bool v27; // al
  bool v28; // al
  float v29; // xmm6_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  UFG::qString *v35; // rax
  bool v36; // bl
  float v37; // xmm0_4
  float v38; // xmm0_4
  float proportion; // ST28_4
  float v40; // xmm0_4
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v42; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v43; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v44; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v45; // rax
  UFG::DUITheme *v46; // rcx
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+30h] [rbp-31h]
  UFG::DUIRect result; // [rsp+40h] [rbp-21h]
  UFG::qString v49; // [rsp+50h] [rbp-11h]
  __int64 v50; // [rsp+78h] [rbp+17h]
  bool evaluate[8]; // [rsp+C8h] [rbp+67h]

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginScrollView(dui, &this->mScrollPos);
  v4 = UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(v2, v4, LayoutFlag_FillLastCol);
  *(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> **)((char *)&v5[5].mPrev + 4) = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)1;
  v5[6].mPrev = 0i64;
  v5[6].mNext = 0i64;
  UFG::DUIContext::Checkbox(v2, "Dynamic Theme", &v2->mSharedTheme->mDynamic);
  v6 = UFG::qString::FormatEx(
         &v49,
         "MPos  : %3d,%3d",
         (unsigned int)v2->mInputState.mMousePos.mX,
         (unsigned int)v2->mInputState.mMousePos.mY)->mData;
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(v2, &result);
  UFG::DUIContext::RenderText(v2, &result, v2->mTheme.mColour, v6, 0x10u);
  UFG::DUIContext::PopScissor(v2);
  UFG::qString::~qString(&v49);
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(v2, &result);
  UFG::DUIContext::RenderText(v2, &result, v2->mTheme.mColour, "Input", 0x10u);
  UFG::DUIContext::PopScissor(v2);
  UFG::DUIContext::Slider(v2, "mMouseWheelRows", &v2->mTheme.mMouseWheelRows, 1);
  UFG::DUIContext::Separator(v2);
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(v2, &result);
  UFG::DUIContext::RenderText(v2, &result, v2->mTheme.mColour, "ComboBox", 0x10u);
  UFG::DUIContext::PopScissor(v2);
  options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  v7 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  *(_QWORD *)evaluate = v7;
  if ( v7 )
  {
    UFG::qString::qString(v7, "hello world");
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = options.mNode.mPrev;
  options.mNode.mPrev->mNext = v9;
  v9->mPrev = v10;
  v9->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mPrev = v9;
  v11 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  *(_QWORD *)evaluate = v11;
  if ( v11 )
  {
    UFG::qString::qString(v11, "hello ufg");
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  v14 = options.mNode.mPrev;
  options.mNode.mPrev->mNext = v13;
  v13->mPrev = v14;
  v13->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mPrev = v13;
  v15 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  *(_QWORD *)evaluate = v15;
  if ( v15 )
  {
    UFG::qString::qString(v15, "hello santa");
    v17 = v16;
  }
  else
  {
    v17 = 0i64;
  }
  v18 = options.mNode.mPrev;
  options.mNode.mPrev->mNext = v17;
  v17->mPrev = v18;
  v17->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mPrev = v17;
  v19 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  *(_QWORD *)evaluate = v19;
  if ( v19 )
  {
    UFG::qString::qString(v19, "hello kyle");
    v21 = v20;
  }
  else
  {
    v21 = 0i64;
  }
  v22 = options.mNode.mPrev;
  options.mNode.mPrev->mNext = v21;
  v21->mPrev = v22;
  v21->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mPrev = v21;
  v23 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  *(_QWORD *)evaluate = v23;
  if ( v23 )
  {
    UFG::qString::qString(v23, "hello bacon");
    v25 = v24;
  }
  else
  {
    v25 = 0i64;
  }
  v26 = options.mNode.mPrev;
  options.mNode.mPrev->mNext = v25;
  v25->mPrev = v26;
  v25->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mPrev = v25;
  v49.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)"A tooltip for hello world";
  v49.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)"The tooltip for hello ufg";
  *(_QWORD *)&v49.mMagic = "Some tooltip for hello santa";
  v49.mData = "One tooltip for hello kyle";
  *(_QWORD *)&v49.mStringHash32 = "This tooltip for hello bacon";
  UFG::DUIContext::ComboBox(v2, &v3->mComboBoxCurrentIndex, &options, (const char **)&v49, 5u);
  UFG::DUIContext::Separator(v2);
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(v2, &result);
  UFG::DUIContext::RenderText(v2, &result, v2->mTheme.mColour, "TextBox", 0x10u);
  UFG::DUIContext::PopScissor(v2);
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  v27 = UFG::DUIContext::TakeFocus(v2, &result, &result, 1);
  evaluate[0] = 0;
  options.mNode.mPrev = 0i64;
  UFG::DUIContext::InternalTextControl(v2, &result, &v3->mTextBoxString0, v27);
  if ( evaluate[0] )
  {
    v2->mCaretPos = 0;
    v2->mHighlightStart = v3->mTextBoxString0.mLength;
  }
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  v28 = UFG::DUIContext::TakeFocus(v2, &result, &result, 1);
  evaluate[0] = 0;
  options.mNode.mPrev = 0i64;
  UFG::DUIContext::InternalTextControl(v2, &result, &v3->mTextBoxString1, v28);
  if ( evaluate[0] )
  {
    v2->mCaretPos = 0;
    v2->mHighlightStart = v3->mTextBoxString1.mLength;
  }
  UFG::DUIContext::TextBox(v2, &v3->mTextBoxString2, 0i64, 1, 0i64, 0xFFFFFFFF);
  UFG::DUIContext::TextBox(v2, &v3->mTextBoxString3, 0i64, 1, 0i64, 0xFFFFFFFF);
  UFG::DUIContext::Separator(v2);
  UFG::DUIContext::Label(v2, "TextBoxWithSuggestions");
  v49.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)"NorthPoint";
  v49.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)"Aberdeen";
  *(_QWORD *)&v49.mMagic = "Central";
  v49.mData = "Kennedy";
  *(_QWORD *)&v49.mStringHash32 = "Kowloon";
  v50 = 0i64;
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  UFG::DUIContext::TextBox(
    v2,
    &result,
    &v3->mTextBoxWithSuggestionsString,
    "this is a textbox",
    1,
    (const char **)&v49,
    0xFFFFFFFF);
  UFG::DUIContext::Separator(v2);
  v29 = 0.0;
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Message Box", &v3->mCollapsable_MessageBox) )
  {
    ++LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev);
    if ( (unsigned __int8)UFG::DUIContext::Button(v2, "Show MessageBox", 0x10u) )
    {
      v3->mShowMessageBox = 1;
      UFG::qString::Set(&v3->mMessageBoxResponse, "No Result");
    }
    if ( (unsigned __int8)UFG::DUIContext::Button(v2, "Show 2 MessageBoxes", 0x10u) )
      *(_WORD *)&v3->mShowMessageBox = 257;
    v49.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)"Ok";
    v49.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)"Quit";
    *(_QWORD *)&v49.mMagic = "Save";
    v49.mData = "Delete";
    *(_QWORD *)&v49.mStringHash32 = "Freeze";
    v50 = 0i64;
    *(_DWORD *)evaluate = 0;
    if ( v3->mShowMessageBox
      && UFG::DUIContext::MessageBox(
           v2,
           (unsigned int *)evaluate,
           "Hello MessageBox",
           "The quick brown fox jumps over the lazy dog!",
           (const char **)&v49) )
    {
      v3->mShowMessageBox = 0;
      UFG::qString::Set(&v3->mMessageBoxResponse, *((const char **)&v49.mPrev + *(unsigned int *)evaluate));
    }
    if ( v3->mShowMessageBox2
      && UFG::DUIContext::MessageBox(
           v2,
           (unsigned int *)evaluate,
           "Hello again MessageBox",
           "The lazy dog is jumped over by the quick brown fox!",
           (const char **)&v49) )
    {
      v3->mShowMessageBox2 = 0;
      UFG::qString::Set(&v3->mMessageBoxResponse, *((const char **)&v49.mPrev + *(unsigned int *)evaluate));
    }
    UFG::DUIContext::Label(v2, v3->mMessageBoxResponse.mData);
    v30 = (float)(LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v30 < 0.0 )
      v30 = 0.0;
    LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) = (signed int)v30;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Layout", &v3->mCollapsable_Layout) )
  {
    ++LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Slider(v2, "mRowHeight", &v2->mTheme.mRowHeight, 10);
    UFG::DUIContext::Slider(v2, "mIndent", &v2->mTheme.mIndent, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Client Inset X", (int *)&v2->mTheme.mClientInset, 0);
    UFG::DUIContext::Slider(v2, "Client Inset Y", &v2->mTheme.mClientInset.mY, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Control Inset X", (int *)&v2->mTheme.mControlInset, 0);
    UFG::DUIContext::Slider(v2, "Control Inset Y", &v2->mTheme.mControlInset.mY, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::ColourPicker(v2, "Text", v2->mTheme.mColour, 1);
    UFG::DUIContext::ColourPicker(v2, "Text Hot", &v2->mTheme.mColour[2], 1);
    v31 = (float)(LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v31 < 0.0 )
      v31 = 0.0;
    LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) = (signed int)v31;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Window", &v3->mCollapsable_Window) )
  {
    ++LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Title X", (int *)&v2->mTheme.mWindow_TitleInset, 0);
    UFG::DUIContext::Slider(v2, "Title Y", &v2->mTheme.mWindow_TitleInset.mY, 0);
    UFG::DUIContext::Slider(v2, "Title Height", &v2->mTheme.mWindow_TitleH, 4);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::ColourPicker(v2, "Window", &v2->mTheme.mColour[4], 1);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::ColourPicker(v2, "Title Text", &v2->mTheme.mColour[7], 1);
    UFG::DUIContext::ColourPicker(v2, "Title Back", &v2->mTheme.mColour[6], 1);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::ColourPicker(v2, "Title Text Hot", &v2->mTheme.mColour[9], 1);
    UFG::DUIContext::ColourPicker(v2, "Title Back Hot", &v2->mTheme.mColour[8], 1);
    v32 = (float)(LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v32 < 0.0 )
      v32 = 0.0;
    LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) = (signed int)v32;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "ScrollView", &v3->mScrollView_IsOpen) )
  {
    ++LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Slider(v2, "mScrollbarW", &v2->mTheme.mScrollbarW, 4);
    UFG::DUIContext::Slider(v2, "mScrollbarH", &v2->mTheme.mScrollbarH, 4);
    v33 = (float)(LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v33 < 0.0 )
      v33 = 0.0;
    LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) = (signed int)v33;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Seperator", &v3->mSeperator_IsOpen) )
  {
    ++LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Slider(v2, "RowH", &v2->mTheme.mSeperator_RowH, 4);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "TopLineY", &v2->mTheme.mSeperator_TopLineY, 0);
    UFG::DUIContext::Slider(v2, "TopLineH", &v2->mTheme.mSeperator_TopLineH, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "BotLineY", &v2->mTheme.mSeperator_BotLineY, 0);
    UFG::DUIContext::Slider(v2, "BotLineH", &v2->mTheme.mSeperator_BotLineH, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::ColourPicker(v2, "ColourTop", &v2->mTheme.mColour[16], 1);
    UFG::DUIContext::ColourPicker(v2, "ColourBot", &v2->mTheme.mColour[17], 1);
    v34 = (float)(LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v34 < 0.0 )
      v34 = 0.0;
    LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) = (signed int)v34;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Button", &v3->mCollapsable_Button) )
  {
    ++LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev);
    v35 = UFG::qString::FormatEx(&v49, "Times Pressed: %d", (unsigned int)v3->mButtonValue);
    v36 = UFG::DUIContext::Button(v2, v35->mData, 0x10u);
    UFG::qString::~qString(&v49);
    if ( v36 )
      ++v3->mButtonValue;
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Inset.mX", (int *)&v2->mTheme.mButton_Inset, 0);
    UFG::DUIContext::Slider(v2, "Inset.mY", &v2->mTheme.mButton_Inset.mY, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Text.mX", (int *)&v2->mTheme.mButton_Text, 0);
    UFG::DUIContext::Slider(v2, "Text.mY", &v2->mTheme.mButton_Text.mY, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::ColourPicker(v2, "mColour_ButtonBack", &v2->mTheme.mColour[11], 1);
    UFG::DUIContext::ColourPicker(v2, "mColour_ButtonBackHot", &v2->mTheme.mColour[12], 1);
    v37 = (float)(LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v37 < 0.0 )
      v37 = 0.0;
    LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) = (signed int)v37;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Checkbox", &v3->mCheckBox_IsOpen) )
  {
    ++LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Checkbox(v2, "Checkbox Tester", &v3->mCheckBox_Test);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Text.mX", (int *)&v2->mTheme.mCheckBox_Text, 0);
    UFG::DUIContext::Slider(v2, "Text.mY", &v2->mTheme.mCheckBox_Text.mY, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Border.mX", (int *)&v2->mTheme.mCheckBox_Border, 0);
    UFG::DUIContext::Slider(v2, "Border.mY", &v2->mTheme.mCheckBox_Border.mY, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Inset.mX", (int *)&v2->mTheme.mCheckBox_Inset, 0);
    UFG::DUIContext::Slider(v2, "Inset.mY", &v2->mTheme.mCheckBox_Inset.mY, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Check.mX", (int *)&v2->mTheme.mCheckBox_Check, 0);
    UFG::DUIContext::Slider(v2, "Check.mY", &v2->mTheme.mCheckBox_Check.mY, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::ColourPicker(v2, "ColourBorder", &v2->mTheme.mColour[13], 1);
    UFG::DUIContext::ColourPicker(v2, "ColourInset", &v2->mTheme.mColour[14], 1);
    UFG::DUIContext::ColourPicker(v2, "ColourCheck", &v2->mTheme.mColour[15], 1);
    v38 = (float)(LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v38 < 0.0 )
      v38 = 0.0;
    LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) = (signed int)v38;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "Slider", &v3->mSlider_IsOpen) )
  {
    ++LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Slider(v2, "Slider1", &v3->mSliderI2, -1);
    UFG::DUIContext::Slider(v2, "Slider2", &v3->mSliderI100, -10);
    proportion = v3->mSlider;
    UFG::DUIContext::Slider(v2, "Slider3", &v3->mSliderI1000, 0);
    UFG::DUIContext::Slider(v2, "Slider3 - Proportion", &v3->mSlider, 0.0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "mSliderSize", &v2->mTheme.mSliderSize, 4);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Inset.mX", (int *)&v2->mTheme.mSlider_Inset, 0);
    UFG::DUIContext::Slider(v2, "Inset.mY", &v2->mTheme.mSlider_Inset.mY, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Text.mX", (int *)&v2->mTheme.mSlider_Text, 0);
    UFG::DUIContext::Slider(v2, "Text.mY", &v2->mTheme.mSlider_Text.mY, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::Slider(v2, "Track.mX", (int *)&v2->mTheme.mSlider_Track, 0);
    UFG::DUIContext::Slider(v2, "Track.mY", &v2->mTheme.mSlider_Track.mY, 0);
    UFG::DUIContext::Separator(v2);
    UFG::DUIContext::ColourPicker(v2, "mSilder_Colour_Inset", &v2->mTheme.mColour[18], 1);
    UFG::DUIContext::ColourPicker(v2, "mSilder_Colour_Grip", &v2->mTheme.mColour[19], 1);
    v40 = (float)(LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v40 < 0.0 )
      v40 = 0.0;
    LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) = (signed int)v40;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(v2, "ColourPicker", &v3->mColourPicker_IsOpen) )
  {
    ++LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::ColourPicker(v2, "Test Colour", &v3->mColourPicker_Colour, 1);
    UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
    UFG::DUIContext::Slider(v2, "mColourPicker_Height", &v2->mTheme.mColourPicker_Height, 4);
    UFG::DUIContext::Slider(v2, "mColourPicker_SwatchW", &v2->mTheme.mColourPicker_SwatchW, 4);
    UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
    UFG::DUIContext::Slider(v2, "mColourPicker_Inset.mX", &v2->mTheme.mColourPicker_Inset.mX, -20);
    UFG::DUIContext::Slider(v2, "mColourPicker_Inset.mY", &v2->mTheme.mColourPicker_Inset.mY, -20);
    UFG::DUIContext::Slider(v2, "mColourPicker_Inset.mW", &v2->mTheme.mColourPicker_Inset.mW, -200);
    UFG::DUIContext::Slider(v2, "mColourPicker_Inset.mH", &v2->mTheme.mColourPicker_Inset.mH, -20);
    UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
    UFG::DUIContext::Slider(v2, "mColourPicker_Text.mX", (int *)&v2->mTheme.mColourPicker_Text, 0);
    UFG::DUIContext::Slider(v2, "mColourPicker_Text.mY", &v2->mTheme.mColourPicker_Text.mY, 0);
    UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
    UFG::DUIContext::Slider(v2, "mColourPicker_Track.mX", (int *)&v2->mTheme.mColourPicker_Track, 0);
    UFG::DUIContext::Slider(v2, "mColourPicker_Track.mY", &v2->mTheme.mColourPicker_Track.mY, -20);
    UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
    UFG::DUIContext::ColourPicker(v2, "Border Colour", &v2->mTheme.mColourPicker_SwatchBorderColour, 1);
    if ( (float)(LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) - 1) >= 0.0 )
      v29 = (float)(LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    LODWORD(v2->mLayoutStack.mNode.mNext[4].mPrev) = (signed int)v29;
  }
  for ( i = (UFG::qString *)options.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
        i = (UFG::qString *)options.mNode.mNext )
  {
    v42 = i->mPrev;
    v43 = i->mNext;
    v42->mNext = v43;
    v43->mPrev = v42;
    i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v44 = options.mNode.mPrev;
  v45 = options.mNode.mNext;
  options.mNode.mPrev->mNext = options.mNode.mNext;
  v45->mPrev = v44;
  options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  UFG::DUIContext::PopLayoutState(v2);
  UFG::DUIContext::EndScrollView(v2);
  v46 = v2->mSharedTheme;
  if ( v46->mDynamic )
  {
    UFG::DUITheme::operator=(v46, &v2->mTheme);
    v2->mSharedTheme->mDynamic = 1;
  }
}mNext;
  o

// File Line: 381
// RVA: 0x1928D0
void __fastcall UFG::DUILogWindow::DUILogWindow(UFG::DUILogWindow *this)
{
  UFG::DUILogWindow *v1; // rbx

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::DUILogWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUILogWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUILogWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  `eh vector constructor iterator(v1->mLines, 0x28ui64, 32, (void (__fastcall *)(void *))UFG::qString::qString);
  v1->mNumLines = 0i64;
  v1->mScrollPos = 0i64;
  UFG::qString::Set(&v1->mTitle, "Log");
  UFG::qAddPrintHandler(UFG::DUILogWindow::PrintHandler, v1);
}

// File Line: 389
// RVA: 0x1931B0
void __fastcall UFG::DUILogWindow::~DUILogWindow(UFG::DUILogWindow *this)
{
  UFG::DUILogWindow *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUILogWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUILogWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qRemovePrintHandler(UFG::DUILogWindow::PrintHandler, this);
  `eh vector destructor iterator(v1->mLines, 0x28ui64, 32, (void (__fastcall *)(void *))UFG::qString::~qString);
  UFG::DUIWindow::~DUIWindow((UFG::DUIWindow *)&v1->vfptr);
}

// File Line: 394
// RVA: 0x19C2B0
signed __int64 __fastcall UFG::DUILogWindow::PrintHandler(void *user_data, const char *text)
{
  const char *v2; // rsi
  _QWORD *v3; // rbp
  int i; // edi
  char *v5; // rax
  int v6; // ebx
  __int64 v7; // rax
  _QWORD insensitive[3]; // [rsp+20h] [rbp-58h]
  UFG::qDateTime date_time; // [rsp+38h] [rbp-40h]
  UFG::qString v11; // [rsp+48h] [rbp-30h]

  v2 = text;
  v3 = user_data;
  UFG::qString::qString(&v11);
  UFG::qGetDateTime(&date_time);
  LODWORD(insensitive[0]) = date_time.mSecond;
  UFG::qString::Format(&v11, "[%02d:%02d:%02d] ", date_time.mHour, date_time.mMinute, insensitive[0]);
  for ( i = UFG::qStringLength(v2); *v2; i += -1 - v6 )
  {
    if ( i == -1 )
      break;
    v5 = UFG::qStringFind(v2, i, "\n", 1, 0);
    v6 = v5 ? (_DWORD)v5 - (_DWORD)v2 : i;
    v7 = (signed int)v3[201] % -32;
    UFG::qString::Set((UFG::qString *)&v3[v7 + 4 * v7 + 41], v11.mData, v11.mLength, v2, v6);
    ++v3[201];
    v2 += v6 + 1;
  }
  UFG::qString::~qString(&v11);
  return 1i64;
}

// File Line: 432
// RVA: 0x1A0080
void __fastcall UFG::DUILogWindow::UpdateUI(UFG::DUILogWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rsi
  UFG::DUILogWindow *v3; // rbp
  float v4; // xmm0_4
  signed int v5; // er14
  signed int i; // edi
  const char *v7; // rbx
  UFG::DUIRect result; // [rsp+30h] [rbp-28h]

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginScrollView(dui, &this->mScrollPos);
  v4 = 0.0;
  if ( (float)(LODWORD(v3->mNumLines) - 32) >= 0.0 )
    v4 = (float)(LODWORD(v3->mNumLines) - 32);
  v5 = v3->mNumLines;
  for ( i = (signed int)v4; i < v5; ++i )
  {
    v7 = v3->mLines[i % 32].mData;
    UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
    result.mX += 4;
    result.mW -= 4;
    UFG::DUIContext::PushScissor(v2, &result);
    UFG::DUIContext::RenderText(v2, &result, v2->mTheme.mColour, v7, 0x10u);
    UFG::DUIContext::PopScissor(v2);
  }
  UFG::DUIContext::EndScrollView(v2);
}

