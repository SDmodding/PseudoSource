// File Line: 3
// RVA: 0x1468E20
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::DUIThemeEditorWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::DUIThemeEditorWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::DUIThemeEditorWindow>,
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
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::DUILogWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 17
// RVA: 0x192D30
void __fastcall UFG::DUIThemeEditorWindow::DUIThemeEditorWindow(UFG::DUIThemeEditorWindow *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::DUIThemeEditorWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIThemeEditorWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIThemeEditorWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIThemeEditorWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&this->mTextBoxString0);
  UFG::qString::qString(&this->mTextBoxString1);
  UFG::qString::qString(&this->mTextBoxString2);
  UFG::qString::qString(&this->mTextBoxString3);
  UFG::qString::qString(&this->mTextBoxWithSuggestionsString);
  UFG::qString::qString(&this->mMessageBoxResponse);
  UFG::qString::Set(&this->mTitle, "Theme Editor");
  this->mScrollPos = 0i64;
  *(_QWORD *)&this->mSlider = 1056964608i64;
  this->mSliderI100 = 0;
  this->mSliderI1000 = 2048;
  this->mCollapsable_TextBox = 0;
  UFG::qString::Set(&this->mTextBoxString0, "Hello, Im textbox one");
  UFG::qString::Set(&this->mTextBoxString1, "Hello, Im textbox two");
  UFG::qString::Set(&this->mTextBoxString2, "Hello, Im textbox three");
  UFG::qString::Set(&this->mTextBoxString3, "Hello, Im textbox four");
  this->mCollapsable_Comboxbox = 0;
  this->mComboBoxCurrentIndex = 0;
  *(_WORD *)&this->mCollapsable_MessageBox = 0;
  this->mShowMessageBox2 = 0;
  *(_QWORD *)&this->mCollapsable_DistField = 0i64;
  *(_DWORD *)&this->mScrollView_IsOpen = 0;
  *(_WORD *)&this->mSlider_IsOpen = 0;
  this->mColourPicker_Colour.r = FLOAT_0_5;
  this->mColourPicker_Colour.g = FLOAT_0_5;
  this->mColourPicker_Colour.b = FLOAT_0_5;
  this->mColourPicker_Colour.a = FLOAT_0_5;
}

// File Line: 55
// RVA: 0x1A0EE0
void __fastcall UFG::DUIThemeEditorWindow::UpdateUI(UFG::DUIThemeEditorWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIRect *LayoutRect; // rax
  UFG::DUILayoutState *v5; // rax
  char *mData; // rbx
  UFG::qString *v7; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
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
  float v39; // xmm0_4
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v41; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v43; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v44; // rax
  UFG::DUITheme *mSharedTheme; // rcx
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+30h] [rbp-31h] BYREF
  UFG::DUIRect result; // [rsp+40h] [rbp-21h] BYREF
  UFG::qString v48; // [rsp+50h] [rbp-11h] BYREF
  __int64 v49; // [rsp+78h] [rbp+17h]
  bool evaluate[8]; // [rsp+C8h] [rbp+67h] BYREF

  UFG::DUIContext::BeginScrollView(dui, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mScrollPos);
  LayoutRect = UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(dui, LayoutRect, LayoutFlag_FillLastCol);
  *(_QWORD *)&v5->mNumCols = 1i64;
  v5->mColWidths = 0i64;
  v5->mRowHeights = 0i64;
  UFG::DUIContext::Checkbox(dui, "Dynamic Theme", &dui->mSharedTheme->mDynamic);
  mData = UFG::qString::FormatEx(
            &v48,
            "MPos  : %3d,%3d",
            (unsigned int)dui->mInputState.mMousePos.mX,
            (unsigned int)dui->mInputState.mMousePos.mY)->mData;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(dui, &result);
  UFG::DUIContext::RenderText(dui, &result, dui->mTheme.mColour, mData, 0x10u);
  UFG::DUIContext::PopScissor(dui);
  UFG::qString::~qString(&v48);
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(dui, &result);
  UFG::DUIContext::RenderText(dui, &result, dui->mTheme.mColour, "Input", 0x10u);
  UFG::DUIContext::PopScissor(dui);
  UFG::DUIContext::Slider(dui, "mMouseWheelRows", (unsigned int *)&dui->mTheme.mMouseWheelRows, 1);
  UFG::DUIContext::Separator(dui);
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(dui, &result);
  UFG::DUIContext::RenderText(dui, &result, dui->mTheme.mColour, "ComboBox", 0x10u);
  UFG::DUIContext::PopScissor(dui);
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
  mPrev = options.mNode.mPrev;
  options.mNode.mPrev->mNext = v9;
  v9->mPrev = mPrev;
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
  v48.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)"A tooltip for hello world";
  v48.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)"The tooltip for hello ufg";
  *(_QWORD *)&v48.mMagic = "Some tooltip for hello santa";
  v48.mData = "One tooltip for hello kyle";
  *(_QWORD *)&v48.mStringHash32 = "This tooltip for hello bacon";
  UFG::DUIContext::ComboBox(dui, &this->mComboBoxCurrentIndex, &options, (char **)&v48, 5u);
  UFG::DUIContext::Separator(dui);
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(dui, &result);
  UFG::DUIContext::RenderText(dui, &result, dui->mTheme.mColour, "TextBox", 0x10u);
  UFG::DUIContext::PopScissor(dui);
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v27 = UFG::DUIContext::TakeFocus(dui, &result, &result, 1);
  evaluate[0] = 0;
  options.mNode.mPrev = 0i64;
  UFG::DUIContext::InternalTextControl(dui, &result, &this->mTextBoxString0, v27);
  if ( evaluate[0] )
  {
    dui->mCaretPos = 0;
    dui->mHighlightStart = this->mTextBoxString0.mLength;
  }
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v28 = UFG::DUIContext::TakeFocus(dui, &result, &result, 1);
  evaluate[0] = 0;
  options.mNode.mPrev = 0i64;
  UFG::DUIContext::InternalTextControl(dui, &result, &this->mTextBoxString1, v28);
  if ( evaluate[0] )
  {
    dui->mCaretPos = 0;
    dui->mHighlightStart = this->mTextBoxString1.mLength;
  }
  UFG::DUIContext::TextBox(dui, &this->mTextBoxString2, 0i64, 1, 0i64, -1);
  UFG::DUIContext::TextBox(dui, &this->mTextBoxString3, 0i64, 1, 0i64, -1);
  UFG::DUIContext::Separator(dui);
  UFG::DUIContext::Label(dui, "TextBoxWithSuggestions");
  v48.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)"NorthPoint";
  v48.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)"Aberdeen";
  *(_QWORD *)&v48.mMagic = "Central";
  v48.mData = "Kennedy";
  *(_QWORD *)&v48.mStringHash32 = "Kowloon";
  v49 = 0i64;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  UFG::DUIContext::TextBox(
    dui,
    &result,
    &this->mTextBoxWithSuggestionsString,
    "this is a textbox",
    1,
    (const char **)&v48,
    -1);
  UFG::DUIContext::Separator(dui);
  v29 = 0.0;
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Message Box", &this->mCollapsable_MessageBox) )
  {
    ++LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev);
    if ( UFG::DUIContext::Button(dui, "Show MessageBox", 0x10u) )
    {
      this->mShowMessageBox = 1;
      UFG::qString::Set(&this->mMessageBoxResponse, "No Result");
    }
    if ( UFG::DUIContext::Button(dui, "Show 2 MessageBoxes", 0x10u) )
      *(_WORD *)&this->mShowMessageBox = 257;
    v48.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)"Ok";
    v48.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)"Quit";
    *(_QWORD *)&v48.mMagic = "Save";
    v48.mData = "Delete";
    *(_QWORD *)&v48.mStringHash32 = "Freeze";
    v49 = 0i64;
    *(_DWORD *)evaluate = 0;
    if ( this->mShowMessageBox
      && UFG::DUIContext::MessageBox(
           dui,
           (unsigned int *)evaluate,
           "Hello MessageBox",
           "The quick brown fox jumps over the lazy dog!",
           (const char **)&v48) )
    {
      this->mShowMessageBox = 0;
      UFG::qString::Set(&this->mMessageBoxResponse, *((const char **)&v48.mPrev + *(unsigned int *)evaluate));
    }
    if ( this->mShowMessageBox2
      && UFG::DUIContext::MessageBox(
           dui,
           (unsigned int *)evaluate,
           "Hello again MessageBox",
           "The lazy dog is jumped over by the quick brown fox!",
           (const char **)&v48) )
    {
      this->mShowMessageBox2 = 0;
      UFG::qString::Set(&this->mMessageBoxResponse, *((const char **)&v48.mPrev + *(unsigned int *)evaluate));
    }
    UFG::DUIContext::Label(dui, this->mMessageBoxResponse.mData);
    v30 = (float)(LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v30 < 0.0 )
      v30 = 0.0;
    LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) = (int)v30;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Layout", &this->mCollapsable_Layout) )
  {
    ++LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Slider(dui, "mRowHeight", (unsigned int *)&dui->mTheme.mRowHeight, 10);
    UFG::DUIContext::Slider(dui, "mIndent", (unsigned int *)&dui->mTheme.mIndent, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Client Inset X", (unsigned int *)&dui->mTheme.mClientInset, 0);
    UFG::DUIContext::Slider(dui, "Client Inset Y", (unsigned int *)&dui->mTheme.mClientInset.mY, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Control Inset X", (unsigned int *)&dui->mTheme.mControlInset, 0);
    UFG::DUIContext::Slider(dui, "Control Inset Y", (unsigned int *)&dui->mTheme.mControlInset.mY, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::ColourPicker(dui, "Text", dui->mTheme.mColour, 1);
    UFG::DUIContext::ColourPicker(dui, "Text Hot", &dui->mTheme.mColour[2], 1);
    v31 = (float)(LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v31 < 0.0 )
      v31 = 0.0;
    LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) = (int)v31;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Window", &this->mCollapsable_Window) )
  {
    ++LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Title X", (unsigned int *)&dui->mTheme.mWindow_TitleInset, 0);
    UFG::DUIContext::Slider(dui, "Title Y", (unsigned int *)&dui->mTheme.mWindow_TitleInset.mY, 0);
    UFG::DUIContext::Slider(dui, "Title Height", (unsigned int *)&dui->mTheme.mWindow_TitleH, 4);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::ColourPicker(dui, "Window", &dui->mTheme.mColour[4], 1);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::ColourPicker(dui, "Title Text", &dui->mTheme.mColour[7], 1);
    UFG::DUIContext::ColourPicker(dui, "Title Back", &dui->mTheme.mColour[6], 1);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::ColourPicker(dui, "Title Text Hot", &dui->mTheme.mColour[9], 1);
    UFG::DUIContext::ColourPicker(dui, "Title Back Hot", &dui->mTheme.mColour[8], 1);
    v32 = (float)(LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v32 < 0.0 )
      v32 = 0.0;
    LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) = (int)v32;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "ScrollView", &this->mScrollView_IsOpen) )
  {
    ++LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Slider(dui, "mScrollbarW", (unsigned int *)&dui->mTheme.mScrollbarW, 4);
    UFG::DUIContext::Slider(dui, "mScrollbarH", (unsigned int *)&dui->mTheme.mScrollbarH, 4);
    v33 = (float)(LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v33 < 0.0 )
      v33 = 0.0;
    LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) = (int)v33;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Seperator", &this->mSeperator_IsOpen) )
  {
    ++LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Slider(dui, "RowH", (unsigned int *)&dui->mTheme.mSeperator_RowH, 4);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "TopLineY", (unsigned int *)&dui->mTheme.mSeperator_TopLineY, 0);
    UFG::DUIContext::Slider(dui, "TopLineH", (unsigned int *)&dui->mTheme.mSeperator_TopLineH, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "BotLineY", (unsigned int *)&dui->mTheme.mSeperator_BotLineY, 0);
    UFG::DUIContext::Slider(dui, "BotLineH", (unsigned int *)&dui->mTheme.mSeperator_BotLineH, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::ColourPicker(dui, "ColourTop", &dui->mTheme.mColour[16], 1);
    UFG::DUIContext::ColourPicker(dui, "ColourBot", &dui->mTheme.mColour[17], 1);
    v34 = (float)(LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v34 < 0.0 )
      v34 = 0.0;
    LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) = (int)v34;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Button", &this->mCollapsable_Button) )
  {
    ++LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev);
    v35 = UFG::qString::FormatEx(&v48, "Times Pressed: %d", (unsigned int)this->mButtonValue);
    v36 = UFG::DUIContext::Button(dui, v35->mData, 0x10u);
    UFG::qString::~qString(&v48);
    if ( v36 )
      ++this->mButtonValue;
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Inset.mX", (unsigned int *)&dui->mTheme.mButton_Inset, 0);
    UFG::DUIContext::Slider(dui, "Inset.mY", (unsigned int *)&dui->mTheme.mButton_Inset.mY, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Text.mX", (unsigned int *)&dui->mTheme.mButton_Text, 0);
    UFG::DUIContext::Slider(dui, "Text.mY", (unsigned int *)&dui->mTheme.mButton_Text.mY, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::ColourPicker(dui, "mColour_ButtonBack", &dui->mTheme.mColour[11], 1);
    UFG::DUIContext::ColourPicker(dui, "mColour_ButtonBackHot", &dui->mTheme.mColour[12], 1);
    v37 = (float)(LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v37 < 0.0 )
      v37 = 0.0;
    LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) = (int)v37;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Checkbox", &this->mCheckBox_IsOpen) )
  {
    ++LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Checkbox(dui, "Checkbox Tester", &this->mCheckBox_Test);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Text.mX", (unsigned int *)&dui->mTheme.mCheckBox_Text, 0);
    UFG::DUIContext::Slider(dui, "Text.mY", (unsigned int *)&dui->mTheme.mCheckBox_Text.mY, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Border.mX", (unsigned int *)&dui->mTheme.mCheckBox_Border, 0);
    UFG::DUIContext::Slider(dui, "Border.mY", (unsigned int *)&dui->mTheme.mCheckBox_Border.mY, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Inset.mX", (unsigned int *)&dui->mTheme.mCheckBox_Inset, 0);
    UFG::DUIContext::Slider(dui, "Inset.mY", (unsigned int *)&dui->mTheme.mCheckBox_Inset.mY, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Check.mX", (unsigned int *)&dui->mTheme.mCheckBox_Check, 0);
    UFG::DUIContext::Slider(dui, "Check.mY", (unsigned int *)&dui->mTheme.mCheckBox_Check.mY, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::ColourPicker(dui, "ColourBorder", &dui->mTheme.mColour[13], 1);
    UFG::DUIContext::ColourPicker(dui, "ColourInset", &dui->mTheme.mColour[14], 1);
    UFG::DUIContext::ColourPicker(dui, "ColourCheck", &dui->mTheme.mColour[15], 1);
    v38 = (float)(LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v38 < 0.0 )
      v38 = 0.0;
    LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) = (int)v38;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "Slider", &this->mSlider_IsOpen) )
  {
    ++LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::Slider(dui, "Slider1", (unsigned int *)&this->mSliderI2, -1);
    UFG::DUIContext::Slider(dui, "Slider2", (unsigned int *)&this->mSliderI100, -10);
    UFG::DUIContext::Slider(dui, "Slider3", (unsigned int *)&this->mSliderI1000, 0);
    UFG::DUIContext::Slider(dui, "Slider3 - Proportion", &this->mSlider, 0.0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "mSliderSize", (unsigned int *)&dui->mTheme.mSliderSize, 4);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Inset.mX", (unsigned int *)&dui->mTheme.mSlider_Inset, 0);
    UFG::DUIContext::Slider(dui, "Inset.mY", (unsigned int *)&dui->mTheme.mSlider_Inset.mY, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Text.mX", (unsigned int *)&dui->mTheme.mSlider_Text, 0);
    UFG::DUIContext::Slider(dui, "Text.mY", (unsigned int *)&dui->mTheme.mSlider_Text.mY, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::Slider(dui, "Track.mX", (unsigned int *)&dui->mTheme.mSlider_Track, 0);
    UFG::DUIContext::Slider(dui, "Track.mY", (unsigned int *)&dui->mTheme.mSlider_Track.mY, 0);
    UFG::DUIContext::Separator(dui);
    UFG::DUIContext::ColourPicker(dui, "mSilder_Colour_Inset", &dui->mTheme.mColour[18], 1);
    UFG::DUIContext::ColourPicker(dui, "mSilder_Colour_Grip", &dui->mTheme.mColour[19], 1);
    v39 = (float)(LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    if ( v39 < 0.0 )
      v39 = 0.0;
    LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) = (int)v39;
  }
  if ( (unsigned __int8)UFG::DUIContext::Collapsible(dui, "ColourPicker", &this->mColourPicker_IsOpen) )
  {
    ++LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev);
    UFG::DUIContext::ColourPicker(dui, "Test Colour", &this->mColourPicker_Colour, 1);
    UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
    UFG::DUIContext::Slider(dui, "mColourPicker_Height", (unsigned int *)&dui->mTheme.mColourPicker_Height, 4);
    UFG::DUIContext::Slider(dui, "mColourPicker_SwatchW", (unsigned int *)&dui->mTheme.mColourPicker_SwatchW, 4);
    UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
    UFG::DUIContext::Slider(dui, "mColourPicker_Inset.mX", (unsigned int *)&dui->mTheme.mColourPicker_Inset, -20);
    UFG::DUIContext::Slider(dui, "mColourPicker_Inset.mY", (unsigned int *)&dui->mTheme.mColourPicker_Inset.mY, -20);
    UFG::DUIContext::Slider(dui, "mColourPicker_Inset.mW", (unsigned int *)&dui->mTheme.mColourPicker_Inset.mW, -200);
    UFG::DUIContext::Slider(dui, "mColourPicker_Inset.mH", (unsigned int *)&dui->mTheme.mColourPicker_Inset.mH, -20);
    UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
    UFG::DUIContext::Slider(dui, "mColourPicker_Text.mX", (unsigned int *)&dui->mTheme.mColourPicker_Text, 0);
    UFG::DUIContext::Slider(dui, "mColourPicker_Text.mY", (unsigned int *)&dui->mTheme.mColourPicker_Text.mY, 0);
    UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
    UFG::DUIContext::Slider(dui, "mColourPicker_Track.mX", (unsigned int *)&dui->mTheme.mColourPicker_Track, 0);
    UFG::DUIContext::Slider(dui, "mColourPicker_Track.mY", (unsigned int *)&dui->mTheme.mColourPicker_Track.mY, -20);
    UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
    UFG::DUIContext::ColourPicker(dui, "Border Colour", &dui->mTheme.mColourPicker_SwatchBorderColour, 1);
    if ( (float)(LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) - 1) >= 0.0 )
      v29 = (float)(LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) - 1);
    LODWORD(dui->mLayoutStack.mNode.mNext[4].mPrev) = (int)v29;
  }
  for ( i = (UFG::qString *)options.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
        i = (UFG::qString *)options.mNode.mNext )
  {
    v41 = i->mPrev;
    mNext = i->mNext;
    v41->mNext = mNext;
    mNext->mPrev = v41;
    i->mPrev = i;
    i->mNext = i;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v43 = options.mNode.mPrev;
  v44 = options.mNode.mNext;
  options.mNode.mPrev->mNext = options.mNode.mNext;
  v44->mPrev = v43;
  options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  UFG::DUIContext::PopLayoutState(dui);
  UFG::DUIContext::EndScrollView(dui);
  mSharedTheme = dui->mSharedTheme;
  if ( mSharedTheme->mDynamic )
  {
    UFG::DUITheme::operator=(mSharedTheme, &dui->mTheme);
    dui->mSharedTheme->mDynamic = 1;
  }
}

// File Line: 381
// RVA: 0x1928D0
void __fastcall UFG::DUILogWindow::DUILogWindow(UFG::DUILogWindow *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::DUILogWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUILogWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUILogWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  `eh vector constructor iterator(this->mLines, 0x28ui64, 32, (void (__fastcall *)(void *))UFG::qString::qString);
  this->mNumLines = 0i64;
  this->mScrollPos = 0i64;
  UFG::qString::Set(&this->mTitle, "Log");
  UFG::qAddPrintHandler((UFG::allocator::free_link *)UFG::DUILogWindow::PrintHandler, (UFG::allocator::free_link *)this);
}

// File Line: 389
// RVA: 0x1931B0
void __fastcall UFG::DUILogWindow::~DUILogWindow(UFG::DUILogWindow *this)
{
  this->UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUILogWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUILogWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUILogWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qRemovePrintHandler(UFG::DUILogWindow::PrintHandler, this);
  `eh vector destructor iterator(this->mLines, 0x28ui64, 32, (void (__fastcall *)(void *))UFG::qString::~qString);
  UFG::DUIWindow::~DUIWindow(this);
}

// File Line: 394
// RVA: 0x19C2B0
__int64 __fastcall UFG::DUILogWindow::PrintHandler(_QWORD *user_data, const char *text)
{
  int i; // edi
  char *v5; // rax
  int v6; // ebx
  __int64 v7; // rax
  UFG::qDateTime date_time; // [rsp+38h] [rbp-40h] BYREF
  UFG::qString v10; // [rsp+48h] [rbp-30h] BYREF

  UFG::qString::qString(&v10);
  UFG::qGetDateTime(&date_time);
  UFG::qString::Format(&v10, "[%02d:%02d:%02d] ", date_time.mHour, date_time.mMinute, date_time.mSecond);
  for ( i = UFG::qStringLength(text); *text; i += -1 - v6 )
  {
    if ( i == -1 )
      break;
    v5 = UFG::qStringFind(text, i, "\n", 1, 0);
    v6 = v5 ? (_DWORD)v5 - (_DWORD)text : i;
    v7 = user_data[201] % 32i64;
    UFG::qString::Set((UFG::qString *)&user_data[4 * v7 + 41 + v7], v10.mData, v10.mLength, text, v6);
    ++user_data[201];
    text += v6 + 1;
  }
  UFG::qString::~qString(&v10);
  return 1i64;
}

// File Line: 432
// RVA: 0x1A0080
void __fastcall UFG::DUILogWindow::UpdateUI(UFG::DUILogWindow *this, UFG::DUIContext *dui)
{
  float v4; // xmm0_4
  int mNumLines; // r14d
  int i; // edi
  char *mData; // rbx
  UFG::DUIRect result; // [rsp+30h] [rbp-28h] BYREF

  UFG::DUIContext::BeginScrollView(dui, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mScrollPos);
  v4 = 0.0;
  if ( (float)(LODWORD(this->mNumLines) - 32) >= 0.0 )
    v4 = (float)(LODWORD(this->mNumLines) - 32);
  mNumLines = this->mNumLines;
  for ( i = (int)v4; i < mNumLines; ++i )
  {
    mData = this->mLines[i % 32].mData;
    UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
    result.mX += 4;
    result.mW -= 4;
    UFG::DUIContext::PushScissor(dui, &result);
    UFG::DUIContext::RenderText(dui, &result, dui->mTheme.mColour, mData, 0x10u);
    UFG::DUIContext::PopScissor(dui);
  }
  UFG::DUIContext::EndScrollView(dui);
}

