// File Line: 95
// RVA: 0x192BB0
void __fastcall UFG::DUISuggestionBoxWindow::DUISuggestionBoxWindow(UFG::DUISuggestionBoxWindow *this, MemImageLoadFlag f)
{
  UFG::DUISuggestionBoxWindow *v2; // rdi
  UFG::qString *v3; // rcx
  unsigned int *v4; // rbx

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUISuggestionBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUISuggestionBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->mStyle = 0;
  v3 = v2->mOptions;
  if ( v3 )
  {
    v4 = &v3[-1].mStringHash32;
    `eh vector destructor iterator(
      v3,
      0x28ui64,
      v3[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v4);
    v2->mOptions = 0i64;
  }
  *(_QWORD *)&v2->mOptionCount = 0i64;
  v2->mHasDialogResult = 0;
  v2->mDialogResult = -1i64;
}

// File Line: 123
// RVA: 0x1929A0
void __fastcall UFG::DUIMessageBoxWindow::DUIMessageBoxWindow(UFG::DUIMessageBoxWindow *this, MemImageLoadFlag f)
{
  UFG::DUIMessageBoxWindow *v2; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v3; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIMessageBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIMessageBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&v2->mMessage);
  v3 = &v2->mOptions;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v2->mStyle = 1;
}

// File Line: 145
// RVA: 0x1926E0
void __fastcall UFG::DUIInfoBoxWindow::DUIInfoBoxWindow(UFG::DUIInfoBoxWindow *this, MemImageLoadFlag f)
{
  UFG::DUIInfoBoxWindow *v2; // rbx

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIInfoBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIInfoBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIInfoBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIInfoBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&v2->mMessage);
  v2->mStyle = 165;
  v2->mRect.mW = 300;
  v2->mRect.mH = 100;
}

// File Line: 173
// RVA: 0x1925C0
void __fastcall UFG::DUIComboBoxWindow::DUIComboBoxWindow(UFG::DUIComboBoxWindow *this, MemImageLoadFlag f)
{
  UFG::DUIComboBoxWindow *v2; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v3; // [rsp+60h] [rbp+18h]

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v3 = &v2->mOptions;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v2->mStyle = 0;
  UFG::DUIComboBoxWindow::SetData(v2, 0, &v2->mOptions, 0, 0i64);
}

// File Line: 184
// RVA: 0x1468E60
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::DUIWindow_UFG::qReflectObject_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::DUIWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::DUIWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 185
// RVA: 0x1468D60
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::DUIMessageBoxWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::DUIMessageBoxWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::DUIMessageBoxWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 186
// RVA: 0x1468F80
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::DUIComboBoxWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::DUIComboBoxWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::DUIComboBoxWindow",
    v0);
  UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::DUIComboBoxWindow>::`vftable;
  UFG::qReflectInventory<UFG::DUIComboBoxWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::DUIComboBoxWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 187
// RVA: 0x1469180
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::DUIPopupMenuWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::DUIPopupMenuWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::DUIPopupMenuWindow",
    v0);
  UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::DUIPopupMenuWindow>::`vftable;
  UFG::qReflectInventory<UFG::DUIPopupMenuWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::DUIPopupMenuWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 188
// RVA: 0x1469200
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::DUISuggestionBoxWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::DUISuggestionBoxWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::DUISuggestionBoxWindow",
    v0);
  UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::DUISuggestionBoxWindow>::`vftable;
  UFG::qReflectInventory<UFG::DUISuggestionBoxWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::DUISuggestionBoxWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 189
// RVA: 0x1468CE0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::DUIInfoBoxWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::DUIInfoBoxWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::DUIInfoBoxWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::DUIInfoBoxWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 212
// RVA: 0x195150
void __fastcall UFG::BuildCommandKeyString(UFG::Command *command, UFG::qString *out_string)
{
  UFG::qString *v2; // rdi
  UFG::qTree64Base *v3; // rax
  UFG::qTree64Base *v4; // rbx
  const char *v5; // rax
  const char *v6; // rax
  const char *v7; // rax
  int v8; // ecx
  const char *v9; // rax

  v2 = out_string;
  v3 = UFG::qTree64Base::Get(&command->mManager->mActiveBindingMap->mKeyBindings.mTree, command->mBaseNode.mUID);
  v4 = v3;
  if ( v3 )
  {
    if ( BYTE4(v3[1].mHead.mNeighbours[0]) & 1 )
    {
      v5 = UFG::MapInputVKeyToString(17);
      UFG::qString::Set(v2, v5);
      UFG::qString::operator+=(v2, "+");
    }
    if ( BYTE4(v4[1].mHead.mNeighbours[0]) & 2 )
    {
      v6 = UFG::MapInputVKeyToString(16);
      UFG::qString::operator+=(v2, v6);
      UFG::qString::operator+=(v2, "+");
    }
    if ( BYTE4(v4[1].mHead.mNeighbours[0]) & 4 )
    {
      v7 = UFG::MapInputVKeyToString(18);
      UFG::qString::operator+=(v2, v7);
      UFG::qString::operator+=(v2, "+");
    }
    v8 = (int)v4[1].mHead.mNeighbours[0];
    if ( v8 )
    {
      v9 = UFG::MapInputVKeyToString(v8);
      UFG::qString::operator+=(v2, v9);
    }
  }
}

// File Line: 371
// RVA: 0x1973D0
void __fastcall UFG::DUIInputState::ConsumeMouseButtonEvents(UFG::DUIInputState *this)
{
  this->mMouseWheelDelta = 0;
  *(_QWORD *)&this->mMouseLBWentDown = 0i64;
  *(_WORD *)&this->mLMBDoubleClick = 0;
  this->mMouseMBWentUp = 0;
  this->mMMBDoubleClick = 0;
}

// File Line: 535
// RVA: 0x192760
void __fastcall UFG::DUILayoutState::DUILayoutState(UFG::DUILayoutState *this, UFG::DUIRect *working, UFG::DUI::LayoutFlag flags, bool clip)
{
  this->mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mPrev;
  this->mWorkingRect.mX = working->mX;
  this->mWorkingRect.mY = working->mY;
  this->mWorkingRect.mW = working->mW;
  this->mWorkingRect.mH = working->mH;
  this->mCurrentRect.mX = working->mX;
  this->mCurrentRect.mY = working->mY;
  this->mCurrentRect.mW = working->mW;
  this->mCurrentRect.mH = working->mH;
  *(_QWORD *)&this->mMaximumRect.mX = 0i64;
  *(_QWORD *)&this->mMaximumRect.mW = 0i64;
  this->mIndent = 0;
  this->mFlags = flags;
  this->mClip = clip;
  this->mGridLocation = 0i64;
  this->mNumCols = 1;
  this->mNumRows = 1;
  this->mColWidths = 0i64;
  this->mRowHeights = 0i64;
  this->mAccumulatedItems = 0i64;
  this->mSelectedItems = 0i64;
  this->mMultiSelect = 0;
  this->mExpandedItems = 0i64;
  this->mOffset = 0i64;
  this->mVirtualRowCount = -1i64;
  *(_QWORD *)&this->mLastVisibleRow = 0i64;
  this->mControlData = 0i64;
}

// File Line: 538
// RVA: 0x193130
void __fastcall UFG::DUILayoutState::~DUILayoutState(UFG::DUILayoutState *this)
{
  UFG::DUILayoutState *v1; // rbx
  UFG::DUIIntArray *v2; // rdi
  unsigned __int64 *v3; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v4; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v5; // rax

  v1 = this;
  v2 = this->mAccumulatedItems;
  if ( v2 )
  {
    v3 = v2->mData.p;
    if ( v3 )
      operator delete[](v3);
    v2->mData.p = 0i64;
    *(_QWORD *)&v2->mData.size = 0i64;
    operator delete[](v2);
  }
  v1->mAccumulatedItems = 0i64;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&v1->mPrev;
}

// File Line: 550
// RVA: 0x199420
void __fastcall UFG::DUIWindow::Init(UFG::DUIWindow *this)
{
  UFG::DUIWindow *v1; // rsi
  int v2; // eax
  unsigned int v3; // ebx
  unsigned int v4; // ebx

  v1 = this;
  UFG::DUIWindow::NoSerializeInit(this);
  *(_QWORD *)&v1->mRect.mX = 0i64;
  v1->mRect.mW = 200;
  v1->mRect.mH = 300;
  v2 = v1->mRect.mH;
  v1->mIsExpanded = 1;
  v1->mPrevHeight = v2;
  *(_WORD *)&v1->mVisible = 1;
  v3 = (unsigned __int64)UFG::qStringLength(&customWorldMapCaption) + 1;
  UFG::qReflectArray<char>::Resize(&v1->mGroupTag.mText, v3, "qReflectString::Set()");
  UFG::qMemCopy(v1->mGroupTag.mText.mData.mItems, &customWorldMapCaption, v3);
  v4 = (unsigned __int64)UFG::qStringLength(&customWorldMapCaption) + 1;
  UFG::qReflectArray<char>::Resize(&v1->mSurfaceName.mText, v4, "qReflectString::Set()");
  UFG::qMemCopy(v1->mSurfaceName.mText.mData.mItems, &customWorldMapCaption, v4);
  v1->mLastID = -1;
}

// File Line: 568
// RVA: 0x19A6E0
void __fastcall UFG::DUIWindow::NoSerializeInit(UFG::DUIWindow *this)
{
  UFG::DUIWindow *v1; // rbx
  char *v2; // rax
  UFG::DUIPoint v3; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&this->vfptr);
  UFG::qString::Set(&v1->mTitle, v2);
  v3.mX = 200;
  *(_QWORD *)&v1->mLastUpdateDuation = 0i64;
  v3.mY = 80;
  *(_QWORD *)&v1->mClientRect.mY = 0i64;
  v1->mMode = 1;
  v1->mStyle = 237;
  v1->mMinSize = v3;
  *(_WORD *)&v1->mInFocus = 0;
  v1->mBringToFont = 0;
  *(_WORD *)&v1->mIsModal = 0;
  v1->mDialogResult = -1i64;
  *(_QWORD *)&v1->mClientRect.mH = 0i64;
  v1->mSurface = 0i64;
  v1->mIsInitialUpdate = 1;
}

// File Line: 1059
// RVA: 0x192A20
void __fastcall UFG::DUIMessageBoxWindow::DUIMessageBoxWindow(UFG::DUIMessageBoxWindow *this)
{
  UFG::DUIMessageBoxWindow *v1; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::DUIMessageBoxWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIMessageBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIMessageBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&v1->mMessage);
  v2 = &v1->mOptions;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v1->mStyle = 1;
  v1->mRect.mW = 400;
}

// File Line: 1065
// RVA: 0x19D8F0
void __fastcall UFG::DUIMessageBoxWindow::SetData(UFG::DUIMessageBoxWindow *this, const char *title, const char *message, const char **options)
{
  const char **v4; // rsi
  const char *v5; // r14
  const char *v6; // r15
  UFG::DUIMessageBoxWindow *v7; // rbp
  UFG::qString *v8; // rbx
  UFG::qString *v9; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rax
  UFG::qString *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rcx

  v4 = options;
  v5 = message;
  v6 = title;
  v7 = this;
  v8 = (UFG::qString *)&this->mOptions;
  v9 = (UFG::qString *)this->mOptions.mNode.mNext;
  if ( v9 != (UFG::qString *)&this->mOptions )
  {
    do
    {
      v10 = v9->mPrev;
      v11 = v9->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v9->mPrev;
      v9->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v9->mPrev;
      UFG::qString::~qString(v9);
      operator delete[](v9);
      v9 = (UFG::qString *)v8->mNext;
    }
    while ( v9 != v8 );
  }
  UFG::qString::Set(&v7->mTitle, v6);
  UFG::qString::Set(&v7->mMessage, v5);
  v7->mHasDialogResult = 0;
  for ( v7->mDialogResult = -1i64; *v4; v8->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v12->mPrev )
  {
    v12 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    if ( v12 )
    {
      UFG::qString::qString(v12, *v4);
      ++v4;
    }
    v13 = v8->mPrev;
    v13->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v12->mPrev;
    v12->mPrev = v13;
    v12->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v8->mPrev;
  }
}

// File Line: 1083
// RVA: 0x1A0180
void __fastcall UFG::DUIMessageBoxWindow::UpdateUI(UFG::DUIMessageBoxWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  UFG::DUIMessageBoxWindow *v3; // r14
  UFG::DUIRect *v4; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v5; // rax
  const char *v6; // rbx
  unsigned int v7; // esi
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v9; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v10; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v11; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v12; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v13; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v14; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v15; // rax
  UFG::DUIRect result; // [rsp+38h] [rbp-40h]

  v2 = dui;
  v3 = this;
  v4 = UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(v2, v4, LayoutFlag_FillLastCol);
  *(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> **)((char *)&v5[5].mPrev + 4) = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)1;
  v5[6].mPrev = 0i64;
  v5[6].mNext = 0i64;
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  v6 = v3->mMessage.mData;
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(v2, &result);
  UFG::DUIContext::RenderText(v2, &result, v2->mTheme.mColour, v6, 0x10u);
  UFG::DUIContext::PopScissor(v2);
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  v7 = 0;
  v8 = v3->mOptions.mNode.mNext;
  if ( v8 != (UFG::qNode<UFG::qString,UFG::qString> *)&v3->mOptions )
  {
    while ( !(unsigned __int8)UFG::DUIContext::Button(v2, (const char *)v8[1].mNext, 0x10u) )
    {
      ++v7;
      v8 = v8->mNext;
      if ( v8 == (UFG::qNode<UFG::qString,UFG::qString> *)&v3->mOptions )
        goto LABEL_6;
    }
    v3->mHasDialogResult = 1;
    v3->mDialogResult = v7;
  }
LABEL_6:
  v9 = v2->mLayoutStack.mNode.mNext;
  v10 = v9->mPrev;
  v11 = v9->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v9->mPrev = v9;
  v9->mNext = v9;
  if ( LOBYTE(v9[4].mNext) )
    UFG::DUIContext::PopScissor(v2);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)v2->mLayoutStack.mNode.mNext != &v2->mLayoutStack
    && v2->mCurrentCompositeLayer != 1 )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&v2->mLayoutStack.mNode.mNext[3], (UFG::DUIRect *)&v9[3]);
  }
  v12 = v9[7].mNext;
  if ( v12 )
  {
    v13 = v12[1].mPrev;
    if ( v13 )
      operator delete[](v13);
    v12[1].mPrev = 0i64;
    v12->mNext = 0i64;
    operator delete[](v12);
  }
  v9[7].mNext = 0i64;
  v14 = v9->mPrev;
  v15 = v9->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v9->mPrev = v9;
  v9->mNext = v9;
  operator delete[](v9);
}

// File Line: 1125
// RVA: 0x19FF20
void __fastcall UFG::DUIInfoBoxWindow::UpdateUI(UFG::DUIInfoBoxWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  UFG::DUIInfoBoxWindow *v3; // rsi
  UFG::DUIRect *v4; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v5; // rax
  const char *v6; // rbx
  UFG::DUIRect result; // [rsp+30h] [rbp-18h]

  v2 = dui;
  v3 = this;
  v4 = UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(v2, v4, LayoutFlag_FillLastCol);
  *(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> **)((char *)&v5[5].mPrev + 4) = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)1;
  v5[6].mPrev = 0i64;
  v5[6].mNext = 0i64;
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  v6 = v3->mMessage.mData;
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(v2, &result);
  UFG::DUIContext::RenderText(v2, &result, v2->mTheme.mColour, v6, 0x10u);
  UFG::DUIContext::PopScissor(v2);
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  UFG::DUIContext::BeginGridLayout(v2, 3, 1, 0i64, 0i64, 0);
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  if ( (unsigned __int8)UFG::DUIContext::Button(v2, "OK", 0x12u) && !v3->mMarkedToDestroy )
    v3->mMarkedToDestroy = 1;
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  UFG::DUIContext::PopLayoutState(v2);
  UFG::DUIContext::PopLayoutState(v2);
}

// File Line: 1154
// RVA: 0x192640
void __fastcall UFG::DUIComboBoxWindow::DUIComboBoxWindow(UFG::DUIComboBoxWindow *this)
{
  UFG::DUIComboBoxWindow *v1; // rbx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v2; // [rsp+58h] [rbp+10h]

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::DUIComboBoxWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2 = &v1->mOptions;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v1->mToolTips = 0i64;
  v1->mStyle = 0;
  UFG::DUIComboBoxWindow::SetData(v1, 0, &v1->mOptions, 0, 0i64);
}

// File Line: 1160
// RVA: 0x193050
void __fastcall UFG::DUIComboBoxWindow::~DUIComboBoxWindow(UFG::DUIComboBoxWindow *this)
{
  UFG::DUIComboBoxWindow *v1; // rdi
  UFG::qString *v2; // rcx
  unsigned int *v3; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2 = this->mToolTips;
  if ( v2 )
  {
    v3 = &v2[-1].mStringHash32;
    `eh vector destructor iterator(
      v2,
      0x28ui64,
      v2[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v3);
  }
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&v1->mOptions);
  v4 = v1->mOptions.mNode.mPrev;
  v5 = v1->mOptions.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mOptions.mNode.mPrev = &v1->mOptions.mNode;
  v1->mOptions.mNode.mNext = &v1->mOptions.mNode;
  UFG::DUIWindow::~DUIWindow((UFG::DUIWindow *)&v1->vfptr);
}

// File Line: 1168
// RVA: 0x19D700
void __fastcall UFG::DUIComboBoxWindow::SetData(UFG::DUIComboBoxWindow *this, int current_value, UFG::qList<UFG::qString,UFG::qString,1,0> *options, unsigned int count, const char **tooltips)
{
  unsigned __int64 v5; // r12
  UFG::qList<UFG::qString,UFG::qString,1,0> *v6; // r15
  int v7; // er13
  UFG::DUIComboBoxWindow *v8; // r14
  UFG::qList<UFG::qString,UFG::qString,1,0> *v9; // rsi
  UFG::qString *v10; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  __int64 v13; // rdi
  unsigned int v14; // ebp
  UFG::qString *i; // rbx
  UFG::qString *v16; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v19; // rax
  UFG::qString *v20; // rcx
  unsigned int *v21; // rbx
  const char **v22; // rbx
  unsigned __int64 v23; // rsi
  signed __int64 v24; // rax
  unsigned __int8 v25; // cf
  unsigned __int64 v26; // rax
  UFG::allocator::free_link *v27; // rax
  signed __int64 v28; // rbp

  v5 = count;
  v6 = options;
  v7 = current_value;
  v8 = this;
  v9 = &this->mOptions;
  v10 = (UFG::qString *)this->mOptions.mNode.mNext;
  if ( v10 != (UFG::qString *)&this->mOptions )
  {
    do
    {
      v11 = v10->mPrev;
      v12 = v10->mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      v10->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v10->mPrev;
      v10->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v10->mPrev;
      UFG::qString::~qString(v10);
      operator delete[](v10);
      v10 = (UFG::qString *)v9->mNode.mNext;
    }
    while ( v10 != (UFG::qString *)v9 );
  }
  v13 = 0i64;
  v14 = 0;
  for ( i = (UFG::qString *)v6->mNode.mNext; i != (UFG::qString *)v6; i = (UFG::qString *)i->mNext )
  {
    if ( v14 >= (unsigned int)v5 )
      break;
    v16 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    if ( v16 )
    {
      UFG::qString::qString(v16, i);
      v18 = v17;
    }
    else
    {
      v18 = 0i64;
    }
    v19 = v9->mNode.mPrev;
    v19->mNext = v18;
    v18->mPrev = v19;
    v18->mNext = &v9->mNode;
    v9->mNode.mPrev = v18;
    ++v14;
  }
  v20 = v8->mToolTips;
  if ( v20 )
  {
    v21 = &v20[-1].mStringHash32;
    `eh vector destructor iterator(
      v20,
      0x28ui64,
      v20[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v21);
    v8->mToolTips = 0i64;
  }
  v22 = tooltips;
  if ( tooltips )
  {
    v23 = v5;
    v24 = 40 * v5;
    if ( !is_mul_ok(v5, 0x28ui64) )
      v24 = -1i64;
    v25 = __CFADD__(v24, 8i64);
    v26 = v24 + 8;
    if ( v25 )
      v26 = -1i64;
    v27 = UFG::qMalloc(v26, UFG::gGlobalNewName, 0i64);
    if ( v27 )
    {
      LODWORD(v27->mNext) = v5;
      v28 = (signed __int64)&v27[1];
      `eh vector constructor iterator(&v27[1], 0x28ui64, v5, (void (__fastcall *)(void *))UFG::qString::qString);
    }
    else
    {
      v28 = 0i64;
    }
    v8->mToolTips = (UFG::qString *)v28;
    if ( (_DWORD)v5 )
    {
      do
      {
        UFG::qString::Set(&v8->mToolTips[v13], *v22);
        ++v13;
        ++v22;
        --v23;
      }
      while ( v23 );
    }
  }
  v8->mValue = v7;
  v8->mHasDialogResult = 0;
  v8->mDialogResult = -1i64;
}

// File Line: 1201
// RVA: 0x19F910
void __fastcall UFG::DUIComboBoxWindow::UpdateUI(UFG::DUIComboBoxWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rbx
  UFG::DUIComboBoxWindow *v3; // r15
  UFG::DUIRect *v4; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v5; // rax
  signed int v6; // edi
  UFG::qNode<UFG::qString,UFG::qString> *v7; // r13
  signed __int64 v8; // r14
  int v9; // edi
  UFG::DUIRect v10; // xmm0
  int v11; // edx
  int v12; // ecx
  int v13; // esi
  bool v14; // r12
  signed int v15; // edi
  int v16; // ecx
  int v17; // er14
  int v18; // er11
  int v19; // er10
  int v20; // ecx
  UFG::DUIContextVtbl *v21; // r8
  int v22; // er9
  int v23; // ecx
  int v24; // edx
  int v25; // ecx
  UFG::DUIContextVtbl *v26; // r8
  int v27; // er9
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  int *v31; // rcx
  UFG::qColour *v32; // r8
  UFG::qString *v33; // rdx
  UFG::DUIContextVtbl *v34; // r8
  int v35; // er9
  int v36; // ecx
  int v37; // edx
  int v38; // ecx
  int v39; // ecx
  int v40; // ecx
  __int64 v41; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v42; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v43; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v44; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v45; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v46; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v47; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v48; // rax
  UFG::DUIRect current_rect; // [rsp+40h] [rbp-49h]
  __m128i v50; // [rsp+50h] [rbp-39h]
  int v51; // [rsp+60h] [rbp-29h]
  int v52; // [rsp+64h] [rbp-25h]
  int v53; // [rsp+68h] [rbp-21h]
  int v54; // [rsp+6Ch] [rbp-1Dh]
  float v55; // [rsp+70h] [rbp-19h]
  float v56; // [rsp+74h] [rbp-15h]
  float v57; // [rsp+78h] [rbp-11h]
  float v58; // [rsp+7Ch] [rbp-Dh]
  int v59; // [rsp+80h] [rbp-9h]
  int v60; // [rsp+84h] [rbp-5h]
  int v61; // [rsp+88h] [rbp-1h]
  int v62; // [rsp+8Ch] [rbp+3h]
  UFG::qColour colour; // [rsp+90h] [rbp+7h]
  UFG::DUIRect result; // [rsp+A0h] [rbp+17h]
  int v65; // [rsp+F0h] [rbp+67h]
  signed __int64 v66; // [rsp+F8h] [rbp+6Fh]

  v2 = dui;
  v3 = this;
  v4 = UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(v2, v4, LayoutFlag_FillLastCol);
  *(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> **)((char *)&v5[5].mPrev + 4) = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)1;
  v5[6].mPrev = 0i64;
  v5[6].mNext = 0i64;
  UFG::DUIContext::RenderRect(v2, &v3->mRect, &v2->mTheme.mColour[4], 0);
  v6 = -1;
  v7 = v3->mOptions.mNode.mNext;
  if ( v7 != (UFG::qNode<UFG::qString,UFG::qString> *)&v3->mOptions )
  {
    v8 = -40i64;
    while ( 1 )
    {
      v9 = v6 + 1;
      v65 = v9;
      v8 += 40i64;
      v66 = v8;
      UFG::DUIContext::GetLayoutRect(v2, &current_rect, 0, 0);
      v10 = current_rect;
      _mm_store_si128(&v50, (__m128i)current_rect);
      v11 = v2->mTheme.mButton_Text.mY;
      v12 = v2->mTheme.mButton_Text.mX;
      v13 = _mm_cvtsi128_si32((__m128i)v10);
      v50.m128i_i32[0] = v13 + v12;
      v50.m128i_i32[2] -= 2 * v12;
      v50.m128i_i32[1] += v11;
      v50.m128i_i32[3] -= 2 * v11;
      _mm_store_si128((__m128i *)&result, v50);
      v14 = v9 == v3->mValue;
      v15 = 0;
      v2->mDoubleClicked = 0;
      if ( UFG::DUIContext::TakeFocus(v2, &current_rect, &current_rect, 0) )
      {
        if ( v2->mInputState.mMouseLBWentDown || v2->mInputState.mMouseLBIsDown )
          v15 = 2;
        v16 = v2->mInputState.mMousePos.mX;
        v17 = current_rect.mH;
        v18 = current_rect.mW;
        v19 = current_rect.mY;
        if ( v16 >= v13 && v16 <= current_rect.mW + v13 )
        {
          v20 = v2->mInputState.mMousePos.mY;
          if ( v20 >= current_rect.mY
            && v20 <= current_rect.mH + current_rect.mY - 1
            && !v2->mInputState.mMouseEventHandled )
          {
            if ( v2->mInputState.mMouseLBWentUp )
            {
              v15 = 3;
              v2->mDoubleClicked = 0;
            }
            else if ( v2->mInputState.mLMBDoubleClick )
            {
              v15 = 4;
              v2->mDoubleClicked = 1;
            }
          }
        }
        if ( v2->mInputState.mMouseLBWentUp )
        {
          v2->mFocusedID = -1;
          v2->mFocusOffset = (UFG::DUIPoint)-1i64;
          v2->mDoubleClicked = 0;
          if ( v15 == 2 )
          {
            v15 = 0;
            if ( !v2->mInputState.mMouseLBIsDown && !v2->mInputState.mMouseRBIsDown && !v2->mInputState.mMouseMBIsDown )
            {
              v21 = (&v2->vfptr)[2 * ((signed int)v2->mCurrentCompositeLayer + 54i64)];
              v22 = v2->mInputState.mMousePos.mX;
              v23 = (int)v21[2].UpdateUI;
              if ( v22 >= v23 && v22 <= LODWORD(v21[3].UpdateUI) + v23 )
              {
                v24 = v2->mInputState.mMousePos.mY;
                v25 = HIDWORD(v21[2].UpdateUI);
                if ( v24 >= v25
                  && v24 <= HIDWORD(v21[3].UpdateUI) + v25 - 1
                  && v22 >= v13
                  && v22 <= v18 + v13
                  && v24 >= v19
                  && v24 <= v17 + v19 - 1
                  && !v2->mInputState.mMouseEventHandled )
                {
                  v15 = 1;
                }
              }
            }
          }
        }
        v2->mInputState.mMouseWheelDelta = 0;
        *(_QWORD *)&v2->mInputState.mMouseLBWentDown = 0i64;
        *(_WORD *)&v2->mInputState.mLMBDoubleClick = 0;
        v2->mInputState.mMouseMBWentUp = 0;
        v2->mInputState.mMMBDoubleClick = 0;
        if ( v15 == 3 )
        {
          v3->mValue = v65;
          v3->mHasDialogResult = 1;
          v3->mDialogResult = v65;
          v2->mInputState.mMouseWheelDelta = 0;
          *(_QWORD *)&v2->mInputState.mMouseLBWentDown = 0i64;
          *(_WORD *)&v2->mInputState.mLMBDoubleClick = 0;
          v2->mInputState.mMouseMBWentUp = 0;
          v2->mInputState.mMMBDoubleClick = 0;
          break;
        }
        v8 = v66;
      }
      else if ( !v2->mInputState.mMouseLBIsDown && !v2->mInputState.mMouseRBIsDown && !v2->mInputState.mMouseMBIsDown )
      {
        v26 = (&v2->vfptr)[2 * ((signed int)v2->mCurrentCompositeLayer + 54i64)];
        v27 = v2->mInputState.mMousePos.mX;
        v28 = (int)v26[2].UpdateUI;
        if ( v27 >= v28 && v27 <= LODWORD(v26[3].UpdateUI) + v28 )
        {
          v29 = v2->mInputState.mMousePos.mY;
          v30 = HIDWORD(v26[2].UpdateUI);
          if ( v29 >= v30
            && v29 <= HIDWORD(v26[3].UpdateUI) + v30 - 1
            && v27 >= v13
            && v27 <= v13 + current_rect.mW
            && v29 >= current_rect.mY
            && v29 <= current_rect.mH + current_rect.mY - 1
            && !v2->mInputState.mMouseEventHandled )
          {
            v15 = 1;
          }
        }
      }
      if ( v15 == 1 )
      {
        colour.r = v2->mTheme.mColour[12].r;
        colour.g = v2->mTheme.mColour[12].g;
        colour.b = v2->mTheme.mColour[12].b;
        colour.a = v2->mTheme.mColour[12].a;
        v32 = &colour;
      }
      else
      {
        if ( v14 )
        {
          v51 = 0;
          v52 = 1056964608;
          v53 = 1065353216;
          v54 = 1065353216;
          v31 = &v51;
        }
        else
        {
          v55 = v2->mTheme.mColour[11].r;
          v56 = v2->mTheme.mColour[11].g;
          v57 = v2->mTheme.mColour[11].b;
          v58 = v2->mTheme.mColour[11].a;
          v31 = (int *)&v55;
        }
        v59 = *v31;
        v60 = v31[1];
        v61 = v31[2];
        v62 = v31[3];
        v32 = (UFG::qColour *)&v59;
      }
      UFG::DUIContext::RenderRect(v2, &current_rect, v32, 0);
      UFG::DUIContext::RenderText(v2, &result, &UFG::qColourWhite, (const char *)v7[1].mNext, 0);
      v33 = v3->mToolTips;
      if ( v33 )
        UFG::DUIContext::Tooltip(v2, *(const char **)((char *)&v33->mData + v8), &current_rect);
      v7 = v7->mNext;
      if ( v7 == (UFG::qNode<UFG::qString,UFG::qString> *)&v3->mOptions )
        break;
      v6 = v65;
    }
  }
  if ( v2->mInputState.mMouseLBWentDown )
  {
    v34 = (&v2->vfptr)[2 * ((signed int)v2->mCurrentCompositeLayer + 54i64)];
    v35 = v2->mInputState.mMousePos.mX;
    v36 = (int)v34[2].UpdateUI;
    if ( v35 < v36
      || v35 > LODWORD(v34[3].UpdateUI) + v36
      || (v37 = v2->mInputState.mMousePos.mY, v38 = HIDWORD(v34[2].UpdateUI), v37 < v38)
      || v37 > HIDWORD(v34[3].UpdateUI) + v38 - 1
      || (v39 = v3->mClientRect.mX, v35 < v39)
      || v35 > v3->mClientRect.mW + v39
      || (v40 = v3->mClientRect.mY, v37 < v40)
      || v37 > v3->mClientRect.mH + v40 - 1
      || v2->mInputState.mMouseEventHandled )
    {
      v41 = v3->mValue;
      v3->mHasDialogResult = 1;
      v3->mDialogResult = v41;
      v2->mInputState.mMouseWheelDelta = 0;
      *(_QWORD *)&v2->mInputState.mMouseLBWentDown = 0i64;
      *(_WORD *)&v2->mInputState.mLMBDoubleClick = 0;
      v2->mInputState.mMouseMBWentUp = 0;
      v2->mInputState.mMMBDoubleClick = 0;
    }
  }
  v42 = v2->mLayoutStack.mNode.mNext;
  v43 = v42->mPrev;
  v44 = v42->mNext;
  v43->mNext = v44;
  v44->mPrev = v43;
  v42->mPrev = v42;
  v42->mNext = v42;
  if ( LOBYTE(v42[4].mNext) )
    UFG::DUIContext::PopScissor(v2);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)v2->mLayoutStack.mNode.mNext != &v2->mLayoutStack
    && v2->mCurrentCompositeLayer != 1 )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&v2->mLayoutStack.mNode.mNext[3], (UFG::DUIRect *)&v42[3]);
  }
  v45 = v42[7].mNext;
  if ( v45 )
  {
    v46 = v45[1].mPrev;
    if ( v46 )
      operator delete[](v46);
    v45[1].mPrev = 0i64;
    v45->mNext = 0i64;
    operator delete[](v45);
  }
  v42[7].mNext = 0i64;
  v47 = v42->mPrev;
  v48 = v42->mNext;
  v47->mNext = v48;
  v48->mPrev = v47;
  v42->mPrev = v42;
  v42->mNext = v42;
  operator delete[](v42);
}

// File Line: 1265
// RVA: 0x1932B0
void __fastcall UFG::DUISuggestionBoxWindow::~DUISuggestionBoxWindow(UFG::DUISuggestionBoxWindow *this)
{
  UFG::DUISuggestionBoxWindow *v1; // rdi
  UFG::qString *v2; // rcx
  unsigned int *v3; // rbx

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUISuggestionBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUISuggestionBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2 = this->mOptions;
  if ( v2 )
  {
    v3 = &v2[-1].mStringHash32;
    `eh vector destructor iterator(
      v2,
      0x28ui64,
      v2[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v3);
  }
  UFG::DUIWindow::~DUIWindow((UFG::DUIWindow *)&v1->vfptr);
}

// File Line: 1292
// RVA: 0x1A0920
void __fastcall UFG::DUISuggestionBoxWindow::UpdateUI(UFG::DUISuggestionBoxWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rbx
  UFG::DUISuggestionBoxWindow *v3; // r15
  UFG::DUIRect *v4; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v5; // rax
  signed int v6; // edi
  int v7; // er12
  __int64 v8; // r13
  UFG::DUIRect v9; // xmm0
  int v10; // edx
  int v11; // ecx
  int v12; // esi
  bool v13; // r14
  int v14; // ecx
  int v15; // er14
  int v16; // er11
  int v17; // er10
  int v18; // ecx
  UFG::DUIContextVtbl *v19; // r8
  int v20; // er9
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  UFG::DUIContextVtbl *v24; // r8
  int v25; // er9
  int v26; // ecx
  int v27; // edx
  int v28; // ecx
  int *v29; // rcx
  UFG::qColour *v30; // r8
  UFG::DUIContextVtbl *v31; // r9
  int v32; // er8
  int v33; // ecx
  int v34; // edx
  int v35; // ecx
  int v36; // ecx
  int v37; // ecx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v38; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v39; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v40; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v41; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v42; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v43; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v44; // rax
  UFG::DUIRect current_rect; // [rsp+40h] [rbp-49h]
  __m128i v46; // [rsp+50h] [rbp-39h]
  int v47; // [rsp+60h] [rbp-29h]
  int v48; // [rsp+64h] [rbp-25h]
  int v49; // [rsp+68h] [rbp-21h]
  int v50; // [rsp+6Ch] [rbp-1Dh]
  float v51; // [rsp+70h] [rbp-19h]
  float v52; // [rsp+74h] [rbp-15h]
  float v53; // [rsp+78h] [rbp-11h]
  float v54; // [rsp+7Ch] [rbp-Dh]
  int v55; // [rsp+80h] [rbp-9h]
  int v56; // [rsp+84h] [rbp-5h]
  int v57; // [rsp+88h] [rbp-1h]
  int v58; // [rsp+8Ch] [rbp+3h]
  UFG::qColour colour; // [rsp+90h] [rbp+7h]
  UFG::DUIRect result; // [rsp+A0h] [rbp+17h]
  bool v61; // [rsp+F0h] [rbp+67h]

  v2 = dui;
  v3 = this;
  v4 = UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(v2, v4, LayoutFlag_FillLastCol);
  *(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> **)((char *)&v5[5].mPrev + 4) = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)1;
  v6 = 0;
  v5[6].mPrev = 0i64;
  v5[6].mNext = 0i64;
  UFG::DUIContext::RenderRect(v2, &v3->mRect, &v2->mTheme.mColour[4], 0);
  v7 = 0;
  if ( v3->mOptionCount > 0 )
  {
    v8 = 0i64;
    do
    {
      UFG::DUIContext::GetLayoutRect(v2, &current_rect, 0, 0);
      v9 = current_rect;
      _mm_store_si128(&v46, (__m128i)current_rect);
      v10 = v2->mTheme.mButton_Text.mY;
      v11 = v2->mTheme.mButton_Text.mX;
      v12 = _mm_cvtsi128_si32((__m128i)v9);
      v46.m128i_i32[0] = v12 + v11;
      v46.m128i_i32[2] -= 2 * v11;
      v46.m128i_i32[1] += v10;
      v46.m128i_i32[3] -= 2 * v10;
      _mm_store_si128((__m128i *)&result, v46);
      v13 = v7 == v3->mValue;
      v61 = v7 == v3->mValue;
      v2->mDoubleClicked = 0;
      if ( UFG::DUIContext::TakeFocus(v2, &current_rect, &current_rect, 0) )
      {
        if ( v2->mInputState.mMouseLBWentDown || v2->mInputState.mMouseLBIsDown )
          v6 = 2;
        v14 = v2->mInputState.mMousePos.mX;
        v15 = current_rect.mH;
        v16 = current_rect.mW;
        v17 = current_rect.mY;
        if ( v14 >= v12 && v14 <= current_rect.mW + v12 )
        {
          v18 = v2->mInputState.mMousePos.mY;
          if ( v18 >= current_rect.mY
            && v18 <= current_rect.mH + current_rect.mY - 1
            && !v2->mInputState.mMouseEventHandled )
          {
            if ( v2->mInputState.mMouseLBWentUp )
            {
              v6 = 3;
              v2->mDoubleClicked = 0;
            }
            else if ( v2->mInputState.mLMBDoubleClick )
            {
              v6 = 4;
              v2->mDoubleClicked = 1;
            }
          }
        }
        if ( v2->mInputState.mMouseLBWentUp )
        {
          v2->mFocusedID = -1;
          v2->mFocusOffset = (UFG::DUIPoint)-1i64;
          v2->mDoubleClicked = 0;
          if ( v6 == 2 )
          {
            v6 = 0;
            if ( !v2->mInputState.mMouseLBIsDown && !v2->mInputState.mMouseRBIsDown && !v2->mInputState.mMouseMBIsDown )
            {
              v19 = (&v2->vfptr)[2 * ((signed int)v2->mCurrentCompositeLayer + 54i64)];
              v20 = v2->mInputState.mMousePos.mX;
              v21 = (int)v19[2].UpdateUI;
              if ( v20 >= v21 && v20 <= LODWORD(v19[3].UpdateUI) + v21 )
              {
                v22 = v2->mInputState.mMousePos.mY;
                v23 = HIDWORD(v19[2].UpdateUI);
                if ( v22 >= v23
                  && v22 <= HIDWORD(v19[3].UpdateUI) + v23 - 1
                  && v20 >= v12
                  && v20 <= v16 + v12
                  && v22 >= v17
                  && v22 <= v15 + v17 - 1
                  && !v2->mInputState.mMouseEventHandled )
                {
                  v6 = 1;
                }
              }
            }
          }
        }
        v2->mInputState.mMouseWheelDelta = 0;
        *(_QWORD *)&v2->mInputState.mMouseLBWentDown = 0i64;
        *(_WORD *)&v2->mInputState.mLMBDoubleClick = 0;
        v2->mInputState.mMouseMBWentUp = 0;
        v2->mInputState.mMMBDoubleClick = 0;
        if ( v6 == 3 )
        {
          v3->mValue = v7;
          v3->mHasDialogResult = 1;
          v3->mDialogResult = v7;
          v2->mInputState.mMouseWheelDelta = 0;
          *(_QWORD *)&v2->mInputState.mMouseLBWentDown = 0i64;
          *(_WORD *)&v2->mInputState.mLMBDoubleClick = 0;
          v2->mInputState.mMouseMBWentUp = 0;
          v2->mInputState.mMMBDoubleClick = 0;
          break;
        }
        v13 = v61;
      }
      else if ( !v2->mInputState.mMouseLBIsDown && !v2->mInputState.mMouseRBIsDown && !v2->mInputState.mMouseMBIsDown )
      {
        v24 = (&v2->vfptr)[2 * ((signed int)v2->mCurrentCompositeLayer + 54i64)];
        v25 = v2->mInputState.mMousePos.mX;
        v26 = (int)v24[2].UpdateUI;
        if ( v25 >= v26 && v25 <= LODWORD(v24[3].UpdateUI) + v26 )
        {
          v27 = v2->mInputState.mMousePos.mY;
          v28 = HIDWORD(v24[2].UpdateUI);
          if ( v27 >= v28
            && v27 <= HIDWORD(v24[3].UpdateUI) + v28 - 1
            && v25 >= v12
            && v25 <= v12 + current_rect.mW
            && v27 >= current_rect.mY
            && v27 <= current_rect.mH + current_rect.mY - 1
            && !v2->mInputState.mMouseEventHandled )
          {
            v6 = 1;
          }
        }
      }
      if ( v6 == 1 )
      {
        colour.r = v2->mTheme.mColour[12].r;
        colour.g = v2->mTheme.mColour[12].g;
        colour.b = v2->mTheme.mColour[12].b;
        colour.a = v2->mTheme.mColour[12].a;
        v30 = &colour;
      }
      else
      {
        if ( v13 )
        {
          v47 = 0;
          v48 = 1056964608;
          v49 = 1065353216;
          v50 = 1065353216;
          v29 = &v47;
        }
        else
        {
          v51 = v2->mTheme.mColour[11].r;
          v52 = v2->mTheme.mColour[11].g;
          v53 = v2->mTheme.mColour[11].b;
          v54 = v2->mTheme.mColour[11].a;
          v29 = (int *)&v51;
        }
        v55 = *v29;
        v56 = v29[1];
        v57 = v29[2];
        v58 = v29[3];
        v30 = (UFG::qColour *)&v55;
      }
      UFG::DUIContext::RenderRect(v2, &current_rect, v30, 0);
      v6 = 0;
      UFG::DUIContext::RenderText(v2, &result, &UFG::qColourWhite, v3->mOptions[v8].mData, 0);
      ++v7;
      ++v8;
    }
    while ( v7 < v3->mOptionCount );
  }
  if ( v2->mInputState.mMouseLBWentDown )
  {
    v31 = (&v2->vfptr)[2 * ((signed int)v2->mCurrentCompositeLayer + 54i64)];
    v32 = v2->mInputState.mMousePos.mX;
    v33 = (int)v31[2].UpdateUI;
    if ( v32 < v33
      || v32 > LODWORD(v31[3].UpdateUI) + v33
      || (v34 = v2->mInputState.mMousePos.mY, v35 = HIDWORD(v31[2].UpdateUI), v34 < v35)
      || v34 > HIDWORD(v31[3].UpdateUI) + v35 - 1
      || (v36 = v3->mClientRect.mX, v32 < v36)
      || v32 > v3->mClientRect.mW + v36
      || (v37 = v3->mClientRect.mY, v34 < v37)
      || v34 > v3->mClientRect.mH + v37 - 1
      || v2->mInputState.mMouseEventHandled )
    {
      v3->mHasDialogResult = 1;
      v3->mDialogResult = -1i64;
    }
  }
  v38 = v2->mLayoutStack.mNode.mNext;
  v39 = v38->mPrev;
  v40 = v38->mNext;
  v39->mNext = v40;
  v40->mPrev = v39;
  v38->mPrev = v38;
  v38->mNext = v38;
  if ( LOBYTE(v38[4].mNext) )
    UFG::DUIContext::PopScissor(v2);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)v2->mLayoutStack.mNode.mNext != &v2->mLayoutStack
    && v2->mCurrentCompositeLayer != 1 )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&v2->mLayoutStack.mNode.mNext[3], (UFG::DUIRect *)&v38[3]);
  }
  v41 = v38[7].mNext;
  if ( v41 )
  {
    v42 = v41[1].mPrev;
    if ( v42 )
      operator delete[](v42);
    v41[1].mPrev = 0i64;
    v41->mNext = 0i64;
    operator delete[](v41);
  }
  v38[7].mNext = 0i64;
  v43 = v38->mPrev;
  v44 = v38->mNext;
  v43->mNext = v44;
  v44->mPrev = v43;
  v38->mPrev = v38;
  v38->mNext = v38;
  operator delete[](v38);
}

// File Line: 1355
// RVA: 0x198C80
__int64 __fastcall UFG::PopupMenuCommand::GetState(UFG::PopupMenuCommand *this, UFG::CommandContext *context, unsigned int *image_uid)
{
  unsigned int *v3; // r14
  UFG::CommandContext *v4; // rdi
  UFG::PopupMenuCommand *v5; // r15
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  unsigned int v8; // er12
  int v9; // ebx
  UFG::Command **v10; // rsi
  unsigned int v11; // ebp
  UFG::PopupMenuCommand *v12; // rcx
  __int64 result; // rax
  UFG::qArray<UFG::Command *,0> commands; // [rsp+28h] [rbp-40h]
  int v15; // [rsp+80h] [rbp+18h]

  v3 = image_uid;
  v4 = context;
  v5 = this;
  v6 = UFG::qStringHashUpper32("DUIPopupMenuWindow", 0xFFFFFFFF);
  if ( v6 && (v7 = UFG::qBaseTreeRB::Get(&v4->mDictionary.mTree, v6)) != 0i64 && v7 != (UFG::qBaseTreeRB *)8 )
  {
    v8 = 2;
    if ( v5->mHideWhenEmpty )
      v8 = 0;
    commands.p = 0i64;
    *(_QWORD *)&commands.size = 0i64;
    UFG::CommandManager::GetCommandsFromTags(UFG::gCommandManager, &v5->mChildTags, &commands);
    v9 = 0;
    v10 = commands.p;
    v11 = commands.size;
    if ( commands.size )
    {
      while ( 1 )
      {
        v12 = (UFG::PopupMenuCommand *)v10[v9];
        if ( v12 != v5 )
        {
          v15 = 0;
          if ( v12->vfptr->GetState((UFG::Command *)&v12->vfptr, v4, (unsigned int *)&v15) == 1
            && (v4->mDictionary.mTree.mCount == 0) <= 0 )
          {
            break;
          }
        }
        if ( ++v9 >= v11 )
          goto LABEL_13;
      }
      v8 = 1;
    }
LABEL_13:
    if ( v10 )
      operator delete[](v10);
    commands.p = 0i64;
    *(_QWORD *)&commands.size = 0i64;
    result = v8;
  }
  else
  {
    result = 0i64;
  }
  *v3 = -514241332;
  return result;
}

// File Line: 1387
// RVA: 0x198280
void __fastcall UFG::PopupMenuCommand::Execute(UFG::PopupMenuCommand *this, UFG::CommandContext *context)
{
  UFG::CommandContext *v2; // rbx
  UFG::PopupMenuCommand *v3; // r14
  unsigned int v4; // eax
  UFG::qBaseTreeRB *v5; // rax
  UFG::DUIPopupMenuWindow *v6; // rsi
  UFG::Command **v7; // rbx
  __int64 v8; // rdi
  UFG::qArray<UFG::Command *,0> commands; // [rsp+28h] [rbp-30h]
  UFG::DUIPopupMenuWindow *v10; // [rsp+60h] [rbp+8h]

  v2 = context;
  v3 = this;
  commands.p = 0i64;
  *(_QWORD *)&commands.size = 0i64;
  UFG::CommandManager::GetCommandsFromTags(UFG::gCommandManager, &this->mChildTags, &commands);
  v4 = UFG::qStringHashUpper32("DUIPopupMenuWindow", 0xFFFFFFFF);
  if ( v4 && (v5 = UFG::qBaseTreeRB::Get(&v2->mDictionary.mTree, v4)) != 0i64 && v5 != (UFG::qBaseTreeRB *)8 )
    v6 = (UFG::DUIPopupMenuWindow *)v5->mNULL.mParent;
  else
    v6 = v10;
  if ( commands.size )
  {
    v7 = commands.p;
    v8 = commands.size;
    do
    {
      if ( *v7 != (UFG::Command *)v3 )
        UFG::DUIPopupMenuWindow::AddCommandItem(v6, *v7);
      ++v7;
      --v8;
    }
    while ( v8 );
  }
  if ( commands.p )
    operator delete[](commands.p);
}

// File Line: 1417
// RVA: 0x192AC0
void __fastcall UFG::DUIPopupMenuWindow::DUIPopupMenuWindow(UFG::DUIPopupMenuWindow *this, UFG::CommandContext *context, bool root)
{
  bool v3; // di
  UFG::CommandContext *v4; // rbx
  UFG::DUIPopupMenuWindow *v5; // rsi

  v3 = root;
  v4 = context;
  v5 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v5->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v5->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v5->mBaseNode.mUID = -1i64;
  v5->mTypeUID = UFG::qStringHash64("UFG::DUIPopupMenuWindow", 0xFFFFFFFFFFFFFFFFui64);
  v5->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIPopupMenuWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v5->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIPopupMenuWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v5->mParentCommand = 0i64;
  v5->mCommands.p = 0i64;
  *(_QWORD *)&v5->mCommands.size = 0i64;
  v5->mParentWindow = 0i64;
  v5->mChildWindow = 0i64;
  v5->mKeepUp = 0;
  v5->mCommandContext = v4;
  *(_QWORD *)&v5->mRect.mX = 0i64;
  v5->mRect.mW = 1;
  v5->mRect.mH = 1;
  if ( v3 )
    v5->mParentWindow = v5;
  v5->mStyle = 17;
}

// File Line: 1428
// RVA: 0x193220
void __fastcall UFG::DUIPopupMenuWindow::~DUIPopupMenuWindow(UFG::DUIPopupMenuWindow *this)
{
  UFG::DUIWindow *v1; // rbx
  UFG::DUIPopupMenuWindow *v2; // rax
  UFG::CommandContext *v3; // rcx
  UFG::qTree64Base::BaseNode *v4; // rcx

  v1 = (UFG::DUIWindow *)&this->vfptr;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIPopupMenuWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIPopupMenuWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2 = this->mParentWindow;
  if ( v2 != this )
    v2->mChildWindow = 0i64;
  v3 = this->mCommandContext;
  if ( v3 )
    v3->vfptr->__vecDelDtor(v3, 1u);
  v4 = v1[1].mBaseNode.mParent;
  if ( v4 )
    operator delete[](v4);
  v1[1].mBaseNode.mParent = 0i64;
  v1[1].mBaseNode.mUID = 0i64;
  UFG::DUIWindow::~DUIWindow(v1);
}

// File Line: 1445
// RVA: 0x193AD0
void __fastcall UFG::DUIPopupMenuWindow::AddCommandItem(UFG::DUIPopupMenuWindow *this, UFG::Command *command)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v2; // rdi
  UFG::Command *v3; // rbp
  __int64 v4; // rsi
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **v8; // rax

  v2 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mCommands;
  v3 = command;
  v4 = this->mCommands.size;
  v5 = this->mCommands.capacity;
  v6 = v4 + 1;
  if ( (signed int)v4 + 1 > v5 )
  {
    if ( v5 )
      v7 = 2 * v5;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = v4 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v2, v7, "qArray.Add");
  }
  v8 = v2->p;
  v2->size = v6;
  v8[v4] = (UFG::qReflectInventoryBase *)v3;
}

// File Line: 1450
// RVA: 0x19E670
void __fastcall UFG::DUIPopupMenuWindow::SubmenuHeader(UFG::DUIPopupMenuWindow *this, UFG::DUIContext *dui, UFG::Command *command, UFG::Command::State state, unsigned int image_uid)
{
  UFG::Command *v5; // r12
  UFG::DUIContext *v6; // rbx
  UFG::DUIPopupMenuWindow *v7; // rdi
  char v8; // r15
  char v9; // r13
  int v10; // er14
  int v11; // esi
  UFG::DUIPopupMenuWindow *v12; // rdi
  int v13; // er12
  UFG::DUIContextVtbl *v14; // r9
  int v15; // er8
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  UFG::allocator::free_link *v19; // r15
  UFG::allocator::free_link *v20; // rax
  UFG::CommandContext *v21; // rax
  UFG::CommandContext *v22; // rdi
  UFG::DUIPopupMenuWindow *v23; // rax
  UFG::DUIPopupMenuWindow *v24; // rdi
  __int64 v25; // rcx
  UFG::Command *v26; // rax
  UFG::DUIInputState *v27; // r15
  int v28; // ecx
  int v29; // eax
  int v30; // esi
  int v31; // er14
  UFG::DUIRect v32; // xmm6
  int v33; // edx
  int v34; // ecx
  float *v35; // rcx
  int v36; // kr00_4
  int v37; // edx
  int v38; // ecx
  UFG::qColour colour; // [rsp+38h] [rbp-40h]
  UFG::DUIRect result; // [rsp+50h] [rbp-28h]
  UFG::DUIPopupMenuWindow *v41; // [rsp+C0h] [rbp+48h]
  UFG::DUIPopupMenuWindow *data; // [rsp+C8h] [rbp+50h]
  UFG::Command *v43; // [rsp+D0h] [rbp+58h]
  bool v44; // [rsp+D8h] [rbp+60h]

  v43 = command;
  v41 = this;
  v5 = command;
  v6 = dui;
  v7 = this;
  v8 = state == 1;
  v44 = state == 1;
  v9 = 0;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v10 = result.mW;
  v11 = result.mX;
  if ( !v8 )
    goto LABEL_31;
  v12 = v7->mChildWindow;
  v13 = result.mY;
  if ( v12 )
  {
    v26 = v12->mParentCommand;
    if ( v26 && v26 == v43 )
    {
      v9 = 1;
      v27 = &v6->mInputState;
      v12->mKeepUp = UFG::DUIContext::IsVisible(v6, &v6->mInputState.mMousePos)
                  && v27->mMousePos.mX >= v11
                  && v27->mMousePos.mX <= v10 + v11
                  && (v28 = v6->mInputState.mMousePos.mY, v28 >= v13)
                  && v28 <= v13 + result.mH - 1;
      v8 = v44;
    }
    goto LABEL_30;
  }
  v14 = (&v6->vfptr)[2 * ((signed int)v6->mCurrentCompositeLayer + 54i64)];
  v15 = v6->mInputState.mMousePos.mX;
  v16 = (int)v14[2].UpdateUI;
  if ( v15 < v16
    || v15 > LODWORD(v14[3].UpdateUI) + v16
    || (v17 = v6->mInputState.mMousePos.mY, v18 = HIDWORD(v14[2].UpdateUI), v17 < v18)
    || v17 > HIDWORD(v14[3].UpdateUI) + v18 - 1
    || v15 < result.mX
    || v15 > result.mW + result.mX
    || v17 < result.mY
    || v17 > result.mY + result.mH - 1
    || v6->mInputState.mMouseEventHandled )
  {
LABEL_30:
    v5 = v43;
    goto LABEL_31;
  }
  v9 = 1;
  v19 = UFG::qMalloc(0x178ui64, UFG::gGlobalNewName, 0i64);
  data = (UFG::DUIPopupMenuWindow *)v19;
  if ( v19 )
  {
    v20 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
    *(_QWORD *)&colour.r = v20;
    if ( v20 )
    {
      UFG::CommandContext::CommandContext((UFG::CommandContext *)v20, v41->mCommandContext);
      v22 = v21;
    }
    else
    {
      v22 = 0i64;
    }
    UFG::DUIPopupMenuWindow::DUIPopupMenuWindow((UFG::DUIPopupMenuWindow *)v19, v22, 0);
    v24 = v23;
  }
  else
  {
    v24 = 0i64;
  }
  data = v24;
  UFG::CommandContext::AddContext<UFG::DUIPopupMenuWindow *>(v24->mCommandContext, "DUIPopupMenuWindow", &data);
  v25 = (__int64)v43;
  v24->mParentCommand = v43;
  v24->mRect.mX = v10 + v11 - 1;
  v24->mRect.mY = v13;
  v24->mParentWindow = v41;
  v24->mKeepUp = 1;
  v41->mChildWindow = v24;
  v5 = (UFG::Command *)v25;
  (*(void (__fastcall **)(__int64, UFG::CommandContext *))(*(_QWORD *)v25 + 16i64))(v25, v24->mCommandContext);
  UFG::DUIManager::ShowWindow(v6->mManager, (UFG::DUIWindow *)&v24->vfptr, v6->mSurface, 0);
  v8 = v44;
LABEL_31:
  v29 = v6->mTheme.mMenuImage_Inset;
  v30 = v29 + v11;
  result.mX = v30;
  v31 = v10 - v29;
  result.mW = v31;
  v32 = result;
  if ( v9 )
  {
    if ( !v8 )
    {
LABEL_35:
      v35 = &v6->mTheme.mColour[1].r;
      goto LABEL_38;
    }
    _mm_store_si128((__m128i *)&result, (__m128i)result);
    v33 = v6->mTheme.mButton_Inset.mY;
    v34 = v6->mTheme.mButton_Inset.mX;
    result.mX = v34 + v30;
    result.mW -= 2 * v34;
    result.mY += v33;
    result.mH -= 2 * v33;
    _mm_store_si128((__m128i *)&result, (__m128i)result);
    UFG::DUIContext::RenderRoundRect(v6, &result, &v6->mTheme.mColour[12], 0);
  }
  if ( !v8 )
    goto LABEL_35;
  v35 = &v6->mTheme.mColour[2].r;
  if ( !v9 )
    v35 = (float *)v6->mTheme.mColour;
LABEL_38:
  colour.r = *v35;
  colour.g = v35[1];
  colour.b = v35[2];
  colour.a = v35[3];
  _mm_store_si128((__m128i *)&result, (__m128i)v32);
  v36 = v6->mTheme.mMenuImage_Inset;
  result.mX = v30 + v31 - v36 / 2;
  result.mW = v36 / 2;
  result.mY += result.mH / 4;
  result.mH /= 2;
  if ( image_uid )
    UFG::DUIContext::RenderRoundRect(v6, &result, &colour, image_uid);
  _mm_store_si128((__m128i *)&result, (__m128i)v32);
  v37 = v6->mTheme.mButton_Text.mY;
  v38 = v6->mTheme.mButton_Text.mX;
  result.mX = v38 + v30;
  result.mW -= 2 * v38;
  result.mY += v37;
  result.mH -= 2 * v37;
  _mm_store_si128((__m128i *)&result, (__m128i)result);
  UFG::DUIContext::RenderText(v6, &result, &colour, v5->mDisplayText.mData, 0x10u);
}

// File Line: 1519
// RVA: 0x19BE50
void __fastcall UFG::DUIPopupMenuWindow::OnCommandClicked(UFG::DUIPopupMenuWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIPopupMenuWindow *v2; // rdx

  while ( 1 )
  {
    if ( !this->mMarkedToDestroy )
      this->mMarkedToDestroy = 1;
    v2 = this->mParentWindow;
    if ( v2 == this )
      break;
    v2->mChildWindow = 0i64;
    this = this->mParentWindow;
  }
}

// File Line: 1530
// RVA: 0x1A0370
void __fastcall UFG::DUIPopupMenuWindow::UpdateUI(UFG::DUIPopupMenuWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // r13
  UFG::DUIPopupMenuWindow *v3; // rsi
  UFG::DUIRect *v4; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v5; // rax
  signed __int64 v6; // r15
  int v7; // er14
  __int64 v8; // rdi
  UFG::Command *v9; // r12
  int v10; // er14
  int v11; // ecx
  __int64 v12; // rdi
  __int64 i; // rax
  signed __int64 v14; // rbx
  int v15; // edx
  UFG::Command *v16; // rax
  int v17; // eax
  UFG::qNode<UFG::qString,UFG::qString> *j; // rdx
  int v19; // eax
  UFG::CommandContext *v20; // rdx
  bool v21; // zf
  UFG::CommandVtbl *v22; // rax
  UFG::Command::State v23; // ebx
  int v24; // edx
  UFG::Command::State v25; // eax
  UFG::Command::State v26; // ebx
  int v27; // edx
  UFG::DUIPopupMenuWindow *v28; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v29; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v30; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v31; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v32; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v33; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v34; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v35; // rax
  int *v36; // rcx
  float v37; // xmm0_4
  signed int v38; // edx
  __int64 v39; // rcx
  UFG::DUIPopupMenuWindow *v40; // rax
  int v41; // edx
  int v42; // ecx
  int v43; // ecx
  int v44; // edx
  bool v45; // al
  UFG::DUIRect rect; // [rsp+38h] [rbp-48h]
  UFG::DUIRect result; // [rsp+48h] [rbp-38h]
  UFG::qString out_string; // [rsp+58h] [rbp-28h]
  char v49; // [rsp+C0h] [rbp+40h]
  int v50; // [rsp+C8h] [rbp+48h]
  unsigned int menu_image_uid; // [rsp+D0h] [rbp+50h]

  v2 = dui;
  v3 = this;
  v4 = UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(v2, v4, LayoutFlag_FillLastCol);
  *(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> **)((char *)&v5[5].mPrev + 4) = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)1;
  v5[6].mPrev = 0i64;
  v5[6].mNext = 0i64;
  v6 = 0i64;
  v49 = 0;
  v7 = 0;
  v50 = 0;
  v8 = 0i64;
  menu_image_uid = 0;
  if ( !v3->mCommands.size )
    goto LABEL_40;
  while ( 1 )
  {
    v9 = v3->mCommands.p[v8];
    if ( !v6 )
    {
      v6 = (signed __int64)&v9->mTags;
      goto LABEL_18;
    }
    v10 = 0;
    v11 = 0;
    v12 = *(_QWORD *)(v6 + 8);
    for ( i = v12; i != v6; i = *(_QWORD *)(i + 8) )
      ++v11;
    v14 = (signed __int64)&v9->mTags;
    v15 = 0;
    v16 = (UFG::Command *)v9->mTags.mNode.mNext;
    if ( v16 != (UFG::Command *)&v9->mTags )
    {
      do
      {
        ++v15;
        v16 = (UFG::Command *)v16->mPrev;
      }
      while ( v16 != (UFG::Command *)v14 );
    }
    if ( v11 != v15 )
      goto LABEL_16;
    if ( v12 != v6 )
    {
      while ( 1 )
      {
        v17 = v10;
        for ( j = v9->mTags.mNode.mNext; v17 > 0; j = j->mNext )
        {
          if ( j == (UFG::qNode<UFG::qString,UFG::qString> *)v14 )
            break;
          --v17;
        }
        ++v10;
        if ( (unsigned int)UFG::qStringCompare(*(const char **)(v12 + 24), (const char *)j[1].mNext, -1) )
          break;
        v12 = *(_QWORD *)(v12 + 8);
        if ( v12 == v6 )
          goto LABEL_17;
      }
LABEL_16:
      v49 = 1;
      v6 = (signed __int64)&v9->mTags;
    }
LABEL_17:
    v7 = v50;
    LODWORD(v8) = menu_image_uid;
LABEL_18:
    v19 = UFG::qStringCompare(v9->mUserType.mData, "PopupMenuCommand", -1);
    menu_image_uid = 0;
    v20 = v3->mCommandContext;
    v21 = v19 == 0;
    v22 = v9->vfptr;
    if ( v21 )
    {
      v23 = (unsigned int)v22->GetState(v9, v20, &menu_image_uid);
      if ( v23 )
      {
        if ( v49 )
        {
          UFG::DUIContext::GetLayoutRect(v2, &rect, 0, 0);
          rect.mY += rect.mH / 2;
          rect.mH = 1;
          v24 = v2->mTheme.mMenuImage_Inset;
          rect.mX += v24 + 2;
          rect.mW += 2 * (-2 - v24);
          UFG::DUIContext::RenderRect(v2, &rect, &v2->mTheme.mColour[17], 0);
          v49 = 0;
        }
        if ( v7 <= v9->mDisplayText.mLength )
          v7 = v9->mDisplayText.mLength;
        v50 = v7;
        UFG::DUIPopupMenuWindow::SubmenuHeader(v3, v2, v9, v23, menu_image_uid);
      }
      goto LABEL_33;
    }
    v25 = (unsigned int)v22->GetState(v9, v20, &menu_image_uid);
    v26 = v25;
    if ( v49 )
    {
      if ( v25 == State_Unavailable )
        goto LABEL_32;
      UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
      result.mY += result.mH / 2;
      result.mH = 1;
      v27 = v2->mTheme.mMenuImage_Inset;
      result.mX += v27 + 2;
      result.mW += 2 * (-2 - v27);
      UFG::DUIContext::RenderRect(v2, &result, &v2->mTheme.mColour[17], 0);
      v49 = 0;
    }
    if ( v26 )
    {
      UFG::qString::qString(&out_string);
      UFG::BuildCommandKeyString(v9, &out_string);
      if ( v7 <= out_string.mLength + 1 + v9->mDisplayText.mLength )
        v7 = out_string.mLength + 1 + v9->mDisplayText.mLength;
      v50 = v7;
      UFG::qString::~qString(&out_string);
    }
LABEL_32:
    if ( UFG::DUIContext::CommandButton(v2, v9, v3->mCommandContext, v26) )
      break;
LABEL_33:
    v8 = (unsigned int)(v8 + 1);
    menu_image_uid = v8;
    if ( (unsigned int)v8 >= v3->mCommands.size )
      goto LABEL_39;
  }
  if ( !v3->mMarkedToDestroy )
    v3->mMarkedToDestroy = 1;
  v28 = v3->mParentWindow;
  if ( v28 != v3 )
  {
    LODWORD(v6) = 0;
    v28->mChildWindow = 0i64;
    UFG::DUIPopupMenuWindow::OnCommandClicked(v3->mParentWindow, v2);
    goto LABEL_40;
  }
LABEL_39:
  LODWORD(v6) = 0;
LABEL_40:
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  v29 = v2->mLayoutStack.mNode.mNext;
  v30 = v29->mPrev;
  v31 = v29->mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  v29->mPrev = v29;
  v29->mNext = v29;
  if ( LOBYTE(v29[4].mNext) )
    UFG::DUIContext::PopScissor(v2);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)v2->mLayoutStack.mNode.mNext != &v2->mLayoutStack
    && v2->mCurrentCompositeLayer != 1 )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&v2->mLayoutStack.mNode.mNext[3], (UFG::DUIRect *)&v29[3]);
  }
  v32 = v29[7].mNext;
  if ( v32 )
  {
    v33 = v32[1].mPrev;
    if ( v33 )
      operator delete[](v33);
    v32[1].mPrev = 0i64;
    v32->mNext = 0i64;
    operator delete[](v32);
  }
  v29[7].mNext = 0i64;
  v34 = v29->mPrev;
  v35 = v29->mNext;
  v34->mNext = v35;
  v35->mPrev = v34;
  v29->mPrev = v29;
  v29->mNext = v29;
  operator delete[](v29);
  v36 = (int *)v2->mLayoutStack.mNode.mNext;
  result.mX = v36[12];
  result.mY = v36[13];
  result.mW = v36[14];
  result.mH = v36[15];
  v37 = FLOAT_200_0;
  if ( (float)(signed int)((float)((float)((float)v7 * v2->mFontDimensions.x) + (float)v2->mTheme.mMenuImage_Inset) * 1.2) >= 200.0 )
    v37 = (float)(signed int)((float)((float)((float)v7 * v2->mFontDimensions.x) + (float)v2->mTheme.mMenuImage_Inset)
                            * 1.2);
  v38 = (signed int)v37;
  v3->mRect.mW = (signed int)v37;
  v39 = *(_QWORD *)&result.mW >> 32;
  v3->mRect.mH = result.mH;
  if ( v3->mRect.mX + (signed int)v37 > v2->mRect.mW )
  {
    v40 = v3->mParentWindow;
    if ( v40 )
      v3->mRect.mX = v40->mRect.mX - v38;
    else
      v3->mRect.mX -= v38;
  }
  if ( v3->mRect.mY + (signed int)v39 > v2->mRect.mH )
  {
    if ( v3->mParentWindow )
      v3->mRect.mY += v2->mTheme.mRowHeight - v39;
    else
      v3->mRect.mY -= v39;
    if ( v3->mRect.mY < 0 )
      v3->mRect.mY = v6;
  }
  v41 = v2->mInputState.mMousePos.mX;
  v42 = v3->mRect.mX;
  v45 = 0;
  if ( v41 >= v42 && v41 <= v3->mRect.mW + v42 )
  {
    v43 = v3->mRect.mY;
    v44 = v2->mInputState.mMousePos.mY;
    if ( v44 >= v43 && v44 <= v3->mRect.mH + v43 - 1 && !v2->mInputState.mMouseEventHandled )
      v45 = 1;
  }
  if ( v2->mInputState.mMouseLBWentDown
    || v2->mInputState.mMouseRBWentDown
    || v2->mInputState.mMouseMBWentDown
    || v3->mParentWindow != v3 && !v3->mKeepUp && !v45 )
  {
    if ( !v3->mMarkedToDestroy )
      v3->mMarkedToDestroy = 1;
  }
  else
  {
    v2->mInputState.mMouseEventHandled = 1;
  }
}

// File Line: 1744
// RVA: 0x19DAB0
void __fastcall UFG::DUIContext::ShowDialog(UFG::DUIContext *this, UFG::DUIWindow *window)
{
  UFG::DUIManager::ShowWindow(this->mManager, window, this->mSurface, 1);
}

// File Line: 1772
// RVA: 0x1993E0
void __fastcall UFG::DUIContext::HideWindow(UFG::DUIContext *this, UFG::DUIWindow *window)
{
  window->mVisible = 0;
}

// File Line: 1777
// RVA: 0x19CFA0
void __fastcall UFG::DUIContext::RenderText(UFG::DUIContext *this, UFG::DUIRect *rect, UFG::qColour *colour, const char *text, unsigned int flags)
{
  const char *v5; // r13
  UFG::qColour *v6; // rdi
  UFG::DUIRect *v7; // rbx
  UFG::DUIContext *v8; // r12
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // r15
  UFG::qColour v11; // ST60_16
  UFG::qColour v12; // ST50_16
  UFG::qColour v13; // ST40_16
  UFG::qColour v14; // ST30_16
  int v15; // ebp
  int v16; // esi
  int v17; // edi
  int v18; // ebx
  UFG::DUIContextVtbl **v19; // rcx
  UFG::allocator::free_link *v20; // rax

  v5 = text;
  v6 = colour;
  v7 = rect;
  v8 = this;
  if ( this->mBuildCommandList
    && rect->mW > 0
    && rect->mH > 0
    && UFG::DUIRect::Overlaps(
         rect,
         (UFG::DUIRect *)&(&this->vfptr)[2 * ((signed int)this->mCurrentCompositeLayer + 54i64)][2]) )
  {
    v9 = UFG::qMalloc(0xA8ui64, "DUIRenderCommand", 0x800ui64);
    v10 = v9;
    if ( v9 )
    {
      v11 = *v6;
      v12 = *v6;
      v13 = *v6;
      v14 = *v6;
      v15 = v7->mH;
      v16 = v7->mW;
      v17 = v7->mY;
      v18 = v7->mX;
      v9->mNext = v9;
      v9[1].mNext = v9;
      UFG::qString::qString((UFG::qString *)&v9[14]);
      LODWORD(v10[2].mNext) = 5;
      HIDWORD(v10[2].mNext) = v18;
      LODWORD(v10[3].mNext) = v17;
      HIDWORD(v10[3].mNext) = v16;
      LODWORD(v10[4].mNext) = v15;
      v10[5].mNext = 0i64;
      *(UFG::qColour *)&v10[6].mNext = v14;
      *(UFG::qColour *)&v10[8].mNext = v13;
      *(UFG::qColour *)&v10[10].mNext = v12;
      *(UFG::qColour *)&v10[12].mNext = v11;
      UFG::qString::Set((UFG::qString *)&v10[14], v5);
      LODWORD(v10[19].mNext) = flags;
    }
    else
    {
      v10 = 0i64;
    }
    v19 = &(&v8->vfptr)[2 * ((signed int)v8->mCurrentCompositeLayer + 88i64)];
    v20 = (UFG::allocator::free_link *)*v19;
    v20[1].mNext = v10;
    v10->mNext = v20;
    v10[1].mNext = (UFG::allocator::free_link *)v19;
    *v19 = (UFG::DUIContextVtbl *)v10;
  }
}

// File Line: 1785
// RVA: 0x19CB20
void __fastcall UFG::DUIContext::RenderRect(UFG::DUIContext *this, UFG::DUIRect *rect, UFG::qColour *colour, unsigned int texture_uid)
{
  UFG::allocator::free_link *v4; // r13
  UFG::qColour *v5; // rdi
  UFG::DUIRect *v6; // rbx
  UFG::DUIContext *v7; // r12
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // r15
  UFG::qColour v10; // ST60_16
  UFG::qColour v11; // ST50_16
  UFG::qColour v12; // ST40_16
  UFG::qColour v13; // ST30_16
  int v14; // ebp
  int v15; // esi
  int v16; // edi
  int v17; // ebx
  UFG::DUIContextVtbl **v18; // rcx
  UFG::allocator::free_link *v19; // rax

  v4 = (UFG::allocator::free_link *)texture_uid;
  v5 = colour;
  v6 = rect;
  v7 = this;
  if ( this->mBuildCommandList
    && rect->mW > 0
    && rect->mH > 0
    && UFG::DUIRect::Overlaps(
         rect,
         (UFG::DUIRect *)&(&this->vfptr)[2 * ((signed int)this->mCurrentCompositeLayer + 54i64)][2]) )
  {
    v8 = UFG::qMalloc(0xA8ui64, "DUIRenderCommand", 0x800ui64);
    v9 = v8;
    if ( v8 )
    {
      v10 = *v5;
      v11 = *v5;
      v12 = *v5;
      v13 = *v5;
      v14 = v6->mH;
      v15 = v6->mW;
      v16 = v6->mY;
      v17 = v6->mX;
      v8->mNext = v8;
      v8[1].mNext = v8;
      UFG::qString::qString((UFG::qString *)&v8[14]);
      LODWORD(v9[2].mNext) = 6;
      HIDWORD(v9[2].mNext) = v17;
      LODWORD(v9[3].mNext) = v16;
      HIDWORD(v9[3].mNext) = v15;
      LODWORD(v9[4].mNext) = v14;
      v9[5].mNext = v4;
      *(UFG::qColour *)&v9[6].mNext = v13;
      *(UFG::qColour *)&v9[8].mNext = v12;
      *(UFG::qColour *)&v9[10].mNext = v11;
      *(UFG::qColour *)&v9[12].mNext = v10;
      UFG::qString::Set((UFG::qString *)&v9[14], 0i64);
      LODWORD(v9[19].mNext) = 0;
    }
    else
    {
      v9 = 0i64;
    }
    v18 = &(&v7->vfptr)[2 * ((signed int)v7->mCurrentCompositeLayer + 88i64)];
    v19 = (UFG::allocator::free_link *)*v18;
    v19[1].mNext = v9;
    v9->mNext = v19;
    v9[1].mNext = (UFG::allocator::free_link *)v18;
    *v18 = (UFG::DUIContextVtbl *)v9;
  }
}

// File Line: 1793
// RVA: 0x19CE20
void __fastcall UFG::DUIContext::RenderRoundRect(UFG::DUIContext *this, UFG::DUIRect *rect, UFG::qColour *colour, unsigned int texture_uid)
{
  UFG::allocator::free_link *v4; // r13
  UFG::qColour *v5; // rdi
  UFG::DUIRect *v6; // rbx
  UFG::DUIContext *v7; // r12
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // r15
  UFG::qColour v10; // ST60_16
  UFG::qColour v11; // ST50_16
  UFG::qColour v12; // ST40_16
  UFG::qColour v13; // ST30_16
  int v14; // ebp
  int v15; // esi
  int v16; // edi
  int v17; // ebx
  UFG::DUIContextVtbl **v18; // rcx
  UFG::allocator::free_link *v19; // rax

  v4 = (UFG::allocator::free_link *)texture_uid;
  v5 = colour;
  v6 = rect;
  v7 = this;
  if ( this->mBuildCommandList
    && rect->mW > 0
    && rect->mH > 0
    && UFG::DUIRect::Overlaps(
         rect,
         (UFG::DUIRect *)&(&this->vfptr)[2 * ((signed int)this->mCurrentCompositeLayer + 54i64)][2]) )
  {
    v8 = UFG::qMalloc(0xA8ui64, "DUIRenderCommand", 0x800ui64);
    v9 = v8;
    if ( v8 )
    {
      v10 = *v5;
      v11 = *v5;
      v12 = *v5;
      v13 = *v5;
      v14 = v6->mH;
      v15 = v6->mW;
      v16 = v6->mY;
      v17 = v6->mX;
      v8->mNext = v8;
      v8[1].mNext = v8;
      UFG::qString::qString((UFG::qString *)&v8[14]);
      LODWORD(v9[2].mNext) = 7;
      HIDWORD(v9[2].mNext) = v17;
      LODWORD(v9[3].mNext) = v16;
      HIDWORD(v9[3].mNext) = v15;
      LODWORD(v9[4].mNext) = v14;
      v9[5].mNext = v4;
      *(UFG::qColour *)&v9[6].mNext = v13;
      *(UFG::qColour *)&v9[8].mNext = v12;
      *(UFG::qColour *)&v9[10].mNext = v11;
      *(UFG::qColour *)&v9[12].mNext = v10;
      UFG::qString::Set((UFG::qString *)&v9[14], 0i64);
      LODWORD(v9[19].mNext) = 0;
    }
    else
    {
      v9 = 0i64;
    }
    v18 = &(&v7->vfptr)[2 * ((signed int)v7->mCurrentCompositeLayer + 88i64)];
    v19 = (UFG::allocator::free_link *)*v18;
    v19[1].mNext = v9;
    v9->mNext = v19;
    v9[1].mNext = (UFG::allocator::free_link *)v18;
    *v18 = (UFG::DUIContextVtbl *)v9;
  }
}

// File Line: 1801
// RVA: 0x19CCA0
void __fastcall UFG::DUIContext::RenderRoundRect(UFG::DUIContext *this, UFG::DUIRect *rect, UFG::qColour *colourL, UFG::qColour *colourR, unsigned int texture_uid)
{
  UFG::qColour *v5; // rdi
  UFG::qColour *v6; // rsi
  UFG::DUIRect *v7; // rbx
  UFG::DUIContext *v8; // r12
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // r15
  UFG::qColour v11; // ST60_16
  UFG::qColour v12; // ST50_16
  UFG::qColour v13; // ST40_16
  UFG::qColour v14; // ST30_16
  int v15; // ebp
  int v16; // esi
  int v17; // edi
  int v18; // ebx
  UFG::DUIContextVtbl **v19; // rcx
  UFG::allocator::free_link *v20; // rax

  v5 = colourR;
  v6 = colourL;
  v7 = rect;
  v8 = this;
  if ( this->mBuildCommandList
    && rect->mW > 0
    && rect->mH > 0
    && UFG::DUIRect::Overlaps(
         rect,
         (UFG::DUIRect *)&(&this->vfptr)[2 * ((signed int)this->mCurrentCompositeLayer + 54i64)][2]) )
  {
    v9 = UFG::qMalloc(0xA8ui64, "DUIRenderCommand", 0x800ui64);
    v10 = v9;
    if ( v9 )
    {
      v11 = *v6;
      v12 = *v5;
      v13 = *v5;
      v14 = *v6;
      v15 = v7->mH;
      v16 = v7->mW;
      v17 = v7->mY;
      v18 = v7->mX;
      v9->mNext = v9;
      v9[1].mNext = v9;
      UFG::qString::qString((UFG::qString *)&v9[14]);
      LODWORD(v10[2].mNext) = 7;
      HIDWORD(v10[2].mNext) = v18;
      LODWORD(v10[3].mNext) = v17;
      HIDWORD(v10[3].mNext) = v16;
      LODWORD(v10[4].mNext) = v15;
      v10[5].mNext = (UFG::allocator::free_link *)texture_uid;
      *(UFG::qColour *)&v10[6].mNext = v14;
      *(UFG::qColour *)&v10[8].mNext = v13;
      *(UFG::qColour *)&v10[10].mNext = v12;
      *(UFG::qColour *)&v10[12].mNext = v11;
      UFG::qString::Set((UFG::qString *)&v10[14], 0i64);
      LODWORD(v10[19].mNext) = 0;
    }
    else
    {
      v10 = 0i64;
    }
    v19 = &(&v8->vfptr)[2 * ((signed int)v8->mCurrentCompositeLayer + 88i64)];
    v20 = (UFG::allocator::free_link *)*v19;
    v20[1].mNext = v10;
    v10->mNext = v20;
    v10[1].mNext = (UFG::allocator::free_link *)v19;
    *v19 = (UFG::DUIContextVtbl *)v10;
  }
}

// File Line: 1839
// RVA: 0x19D120
void __fastcall UFG::DUIContext::ReplaceSelection(UFG::qString *text, int selection_start, int selection_end, const char *new_text, int *highlightStart, int *caret_pos, bool insert)
{
  __int64 v7; // rbp
  __int64 v8; // r13
  UFG::qString *v9; // rsi
  bool v10; // bl
  unsigned __int64 v11; // r14
  UFG::allocator::free_link *v12; // rdi
  int v13; // er8
  char *v14; // rcx
  signed int v15; // er8
  int v16; // ecx
  UFG::qString v17; // [rsp+28h] [rbp-50h]

  v7 = selection_end;
  v8 = selection_start;
  v9 = text;
  UFG::qString::qString(&v17, new_text);
  v10 = insert;
  if ( (signed int)v7 - (signed int)v8 > 0 )
    v10 = 1;
  v11 = (unsigned int)(v9->mLength + 1 + v17.mLength - (v7 - v8));
  v12 = UFG::qMalloc(v11, UFG::gGlobalNewName, 0i64);
  UFG::qMemCopy(v12, v9->mData, v8);
  UFG::qMemCopy((char *)v12 + v8, v17.mData, v17.mLength);
  v13 = v9->mLength;
  if ( v10 )
  {
    UFG::qMemCopy((char *)v12 + v8 + v17.mLength, &v9->mData[v7], v13 - v7);
    v14 = (char *)v12 + v11 - 1;
  }
  else
  {
    v15 = v13 - v17.mLength - v7;
    if ( v15 <= 0 )
    {
      v14 = (char *)v12 + *caret_pos + v17.mLength;
    }
    else
    {
      UFG::qMemCopy((char *)v12 + v8 + v17.mLength, &v9->mData[v17.mLength + v7], v15);
      v14 = (char *)&v12[-1].mNext + v11 - v17.mLength + 7;
    }
  }
  UFG::qMemSet(v14, 0, 1u);
  v16 = v8 + v17.mLength;
  *caret_pos = v8 + v17.mLength;
  *highlightStart = v16;
  UFG::qString::Set(v9, (const char *)v12);
  operator delete[](v12);
  UFG::qString::~qString(&v17);
}

// File Line: 1882
// RVA: 0x193EB0
void __fastcall UFG::DUIContext::ApplyKeystrokes(UFG::qString *text, int *caret_pos, int *select_pos, unsigned __int16 keystroke)
{
  int v4; // er10
  __int64 v5; // r13
  unsigned __int16 v6; // r15
  int v7; // er9
  int *v8; // rbx
  bool v9; // r14
  int *highlightStart; // r11
  UFG::qString *v11; // r12
  int v12; // ebp
  bool v13; // zf
  bool v14; // sf
  unsigned __int8 v15; // of
  int v16; // er8
  int v17; // edi
  UFG::allocator::free_link *v18; // rsi
  __int64 v19; // rax
  int v20; // eax
  int v21; // eax
  int *v22; // [rsp+80h] [rbp+18h]

  v22 = select_pos;
  v4 = *caret_pos;
  v5 = text->mLength;
  v6 = keystroke;
  v7 = *select_pos;
  v8 = caret_pos;
  v9 = *caret_pos < (signed int)v5;
  highlightStart = select_pos;
  v11 = text;
  v12 = abs(*select_pos - *caret_pos);
  if ( v6 )
  {
    if ( v12 )
    {
      v15 = __OFSUB__(v7, v4);
      v13 = v7 == v4;
      v14 = v7 - v4 < 0;
      v16 = *caret_pos;
      if ( v7 < v4 )
        v4 = v7;
      if ( !((unsigned __int8)(v14 ^ v15) | v13) )
        v16 = v7;
      UFG::DUIContext::ReplaceSelection(text, v4, v16, &customWorldMapCaption, highlightStart, caret_pos, 1);
    }
    v17 = v5 + 2;
    v18 = UFG::qMalloc((unsigned int)(v5 + 2), UFG::gGlobalNewName, 0i64);
    UFG::qMemCopy(v18, v11->mData, v5);
    UFG::qMemSet((char *)v18 + v5, 0, 2u);
    if ( (_BYTE)v6 == 8 )
    {
      if ( !v12 )
      {
        if ( v9 )
        {
          v19 = *v8;
          if ( (signed int)v19 > 0 )
          {
            UFG::qMemCopy((char *)v18 + v19 - 1, (char *)v18 + v19, v17 - v19);
            v14 = (*v8)-- - 1 < 0;
            v20 = 0;
            if ( !v14 )
              v20 = *v8;
            *v8 = v20;
          }
        }
        else
        {
          v14 = (*v8)-- - 1 < 0;
          v21 = 0;
          if ( !v14 )
            v21 = *v8;
          *v8 = v21;
          *((_BYTE *)&v18->mNext + v21) = 0;
        }
      }
    }
    else if ( (_BYTE)v6 == 127 )
    {
      if ( v9 && !v12 )
        UFG::qMemCopy((char *)v18 + *v8, (char *)&v18->mNext + *v8 + 1, v17 - *v8 - 1);
    }
    else
    {
      if ( v9 && UFG::DUIContext::sInsertOn )
        UFG::qMemCopy((char *)&v18->mNext + *v8 + 1, (char *)v18 + *v8, v17 - *v8 - 1);
      *((_BYTE *)&v18->mNext + (*v8)++) = v6;
    }
    *v22 = *v8;
    UFG::qString::Set(v11, (const char *)v18);
    operator delete[](v18);
  }
}

// File Line: 1989
// RVA: 0x19A090
bool __fastcall UFG::DUIContext::IsVisible(UFG::DUIContext *this, UFG::DUIPoint *point)
{
  UFG::DUIContextVtbl *v2; // r8
  int v3; // ecx
  int v4; // edx
  int v5; // ecx
  bool result; // al

  v2 = (&this->vfptr)[2 * ((signed int)this->mCurrentCompositeLayer + 54i64)];
  v3 = (int)v2[2].UpdateUI;
  result = 0;
  if ( point->mX >= v3 && point->mX <= LODWORD(v2[3].UpdateUI) + v3 )
  {
    v4 = point->mY;
    v5 = HIDWORD(v2[2].UpdateUI);
    if ( v4 >= v5 && v4 <= HIDWORD(v2[3].UpdateUI) + v5 - 1 )
      result = 1;
  }
  return result;
}

// File Line: 1994
// RVA: 0x1956B0
__int64 __fastcall UFG::DUIContext::ClampCaret(UFG::DUIContext *this, int string_length)
{
  int v2; // eax
  int v3; // eax
  __int64 result; // rax

  v2 = this->mCaretPos;
  if ( v2 >= 0 )
  {
    if ( v2 > string_length )
      this->mCaretPos = string_length;
  }
  else
  {
    this->mCaretPos = 0;
  }
  v3 = this->mHighlightStart;
  if ( v3 >= 0 )
  {
    if ( v3 > string_length )
      this->mHighlightStart = string_length;
    result = (unsigned int)(this->mHighlightStart - this->mCaretPos);
  }
  else
  {
    this->mHighlightStart = 0;
    result = (unsigned int)-this->mCaretPos;
  }
  return result;
}

// File Line: 2017
// RVA: 0x19C3F0
UFG::DUIContext *__fastcall UFG::DUIContext::PushColour(UFG::DUIContext *this, UFG::DUITheme::ColourKey key, UFG::qColour *colour)
{
  UFG::qColour *v3; // rbx
  __int64 v4; // rsi
  UFG::DUIContext *v5; // rdi
  UFG::allocator::free_link *v6; // rax
  _QWORD *v7; // r9
  UFG::qColour v8; // xmm0
  signed __int64 v9; // rcx
  _QWORD *v10; // rax
  _DWORD *v11; // rcx

  v3 = colour;
  v4 = key;
  v5 = this;
  v6 = UFG::qMalloc(0x20ui64, "DUIColourNode", 0i64);
  v7 = &v6->mNext;
  if ( v6 )
  {
    v8 = *v3;
    v6->mNext = v6;
    v6[1].mNext = v6;
    *(UFG::qColour *)&v6[2].mNext = v8;
  }
  else
  {
    v7 = 0i64;
  }
  v9 = (signed __int64)&v5->mThemeColourModifier[v4];
  v10 = *(_QWORD **)(v9 + 8);
  *(_QWORD *)(v9 + 8) = v7;
  *v7 = v9;
  v7[1] = v10;
  *v10 = v7;
  v11 = (_DWORD *)((char *)v5 + 16 * (v4 + 20));
  *v11 = LODWORD(v3->r);
  v11[1] = LODWORD(v3->g);
  v11[2] = LODWORD(v3->b);
  v11[3] = LODWORD(v3->a);
  return v5;
}

// File Line: 2042
// RVA: 0x19BFA0
UFG::DUIContext *__fastcall UFG::DUIContext::PopColour(UFG::DUIContext *this, UFG::DUITheme::ColourKey key)
{
  UFG::DUIContext *v2; // rbx
  signed __int64 v3; // rdi
  signed __int64 v4; // rsi
  UFG::DUIContextVtbl *v5; // rcx
  void (__fastcall *v6)(UFG::DUIContext *); // rdx
  void (__fastcall *v7)(UFG::DUIContext *); // rax
  void (__fastcall *v8)(UFG::DUIContext *); // rdx
  void (__fastcall *v9)(UFG::DUIContext *); // rax
  signed __int64 v10; // r8
  UFG::DUITheme *v11; // rcx
  _DWORD *v12; // rdx
  UFG::DUIContextVtbl *v13; // rdx
  _DWORD *v14; // rcx

  v2 = this;
  v3 = key;
  v4 = 2 * ((signed int)key + 63i64);
  v5 = (&this->vfptr)[2 * ((signed int)key + 63i64)];
  v6 = v5->UpdateUI;
  v7 = v5[1].UpdateUI;
  *((_QWORD *)v6 + 1) = v7;
  *(_QWORD *)v7 = v6;
  v5->UpdateUI = (void (__fastcall *)(UFG::DUIContext *))v5;
  v5[1].UpdateUI = (void (__fastcall *)(UFG::DUIContext *))v5;
  v8 = v5->UpdateUI;
  v9 = v5[1].UpdateUI;
  *((_QWORD *)v8 + 1) = v9;
  *(_QWORD *)v9 = v8;
  v5->UpdateUI = (void (__fastcall *)(UFG::DUIContext *))v5;
  v5[1].UpdateUI = (void (__fastcall *)(UFG::DUIContext *))v5;
  operator delete[](v5);
  v10 = v3;
  if ( (UFG::qList<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour>,1,0> *)v2->mThemeColourModifier[v3].mNode.mNext == &v2->mThemeColourModifier[v3] )
  {
    v11 = v2->mSharedTheme;
    v12 = (_DWORD *)((char *)v2 + 16 * (v3 + 20));
    *v12 = LODWORD(v11->mColour[v10].r);
    v12[1] = LODWORD(v11->mColour[v10].g);
    v12[2] = LODWORD(v11->mColour[v10].b);
    v12[3] = LODWORD(v11->mColour[v10].a);
  }
  else
  {
    v13 = (&v2->vfptr)[v4];
    v14 = (_DWORD *)((char *)v2 + 16 * (v3 + 20));
    *v14 = v13[2].UpdateUI;
    v14[1] = HIDWORD(v13[2].UpdateUI);
    v14[2] = v13[3].UpdateUI;
    v14[3] = HIDWORD(v13[3].UpdateUI);
  }
  return v2;
}

// File Line: 2353
// RVA: 0x199FB0
bool __fastcall UFG::DUIContext::IsHot(UFG::DUIContext *this, UFG::DUIRect *rect)
{
  UFG::DUIContext *v2; // rbx

  v2 = this;
  return !this->mInputState.mMouseLBIsDown
      && !this->mInputState.mMouseRBIsDown
      && !this->mInputState.mMouseMBIsDown
      && UFG::DUIContext::IsMouseOver(this, rect)
      && !v2->mInputState.mMouseEventHandled;
}

// File Line: 2358
// RVA: 0x19A000
bool __fastcall UFG::DUIContext::IsMouseOver(UFG::DUIContext *this, UFG::DUIRect *rect)
{
  int v2; // er11
  UFG::DUIContext *v3; // r10
  UFG::DUIRect *v4; // r8
  UFG::DUIContextVtbl *v5; // r9
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // ecx
  bool result; // al

  v2 = this->mInputState.mMousePos.mX;
  v3 = this;
  v4 = rect;
  v5 = (&this->vfptr)[2 * ((signed int)this->mCurrentCompositeLayer + 54i64)];
  v6 = (int)v5[2].UpdateUI;
  result = 0;
  if ( v2 >= v6 && v2 <= LODWORD(v5[3].UpdateUI) + v6 )
  {
    v7 = v3->mInputState.mMousePos.mY;
    v8 = HIDWORD(v5[2].UpdateUI);
    if ( v7 >= v8 && v7 <= HIDWORD(v5[3].UpdateUI) + v8 - 1 && v2 >= v4->mX && v2 <= v4->mW + v4->mX )
    {
      v9 = v4->mY;
      if ( v7 >= v9 && v7 <= v4->mH + v9 - 1 && !v3->mInputState.mMouseEventHandled )
        result = 1;
    }
  }
  return result;
}

// File Line: 2368
// RVA: 0x19EA40
bool __fastcall UFG::DUIContext::TakeFocus(UFG::DUIContext *this, UFG::DUIRect *current_rect, UFG::DUIRect *rect_grip, bool navigable)
{
  int v4; // ebp
  UFG::DUIRect *v5; // r14
  int v6; // er8
  bool v7; // r12
  UFG::DUIRect *v8; // r13
  UFG::DUIContext *v9; // rbx
  UFG::DUI::NavigationAction v10; // er15
  UFG::DUIInputState *v11; // rsi
  char v12; // al
  char v13; // cl
  int v14; // edx
  int v15; // ecx
  bool v16; // al
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // edx
  bool v21; // zf
  int v23; // [rsp+50h] [rbp+8h]

  v4 = ++this->mCurrentID;
  v5 = rect_grip;
  v6 = this->mFocusedID;
  v7 = navigable;
  v8 = current_rect;
  v9 = this;
  v23 = this->mFocusedID;
  this->mControlLostFocus = 0;
  if ( this->mLastLostFocusID == v4 )
  {
    this->mControlLostFocus = 1;
    this->mLastLostFocusID = -1;
  }
  if ( this->mNextTakesFocus )
  {
    this->mNextTakesFocus = 0;
    this->mFocusedID = v4;
    this->mFocusOffset = 0i64;
    goto LABEL_39;
  }
  if ( navigable && this->mFirstNavigableID == -1 )
  {
    this->mFirstNavigableID = v4;
    this->mNavigableCount = 0;
  }
  v10 = this->mNavigationAction;
  if ( v10 == NavigateNowhere )
  {
    v11 = &this->mInputState;
    v12 = 1;
    if ( this->mInputState.mMouseLBWentDown || this->mInputState.mMouseRBWentDown || (v13 = 0, v11->mMouseMBWentDown) )
      v13 = 1;
    if ( !v11->mLMBDoubleClick && !v11->mRMBDoubleClick && !v11->mMMBDoubleClick )
      v12 = 0;
    if ( (unsigned __int8)v13 | (unsigned __int8)v12 )
    {
      if ( v11->mMousePos.mX >= v5->mX && v11->mMousePos.mX <= v5->mW + v5->mX )
      {
        v14 = v11->mMousePos.mY;
        v15 = v5->mY;
        if ( v14 >= v15 && v14 <= v5->mH + v15 - 1 )
        {
          v16 = UFG::DUIRect::Contains(
                  (UFG::DUIRect *)&(&v9->vfptr)[2 * ((signed int)v9->mCurrentCompositeLayer + 54i64)][2],
                  &v11->mMousePos);
          v6 = v23;
          if ( v16 )
          {
            v9->mFocusedID = v4;
            v9->mFocusOffset.mX = v8->mX - v11->mMousePos.mX;
            v9->mFocusOffset.mY = v8->mY - v9->mInputState.mMousePos.mY;
          }
        }
      }
    }
  }
  v17 = v9->mFocusedID;
  if ( v4 == v17 )
  {
    if ( v9->mSeekingNavigable && v7 )
    {
      v9->mSeekingNavigable = 0;
      v9->mNavigationAction = 0;
      goto LABEL_36;
    }
    switch ( v10 )
    {
      case 0:
        goto LABEL_36;
      case 1:
        v18 = v17 + 1;
        break;
      case 2:
        v19 = v17 - 1;
        v9->mFocusedID = v19;
        if ( v19 < 0 )
          goto LABEL_35;
        v18 = v9->mPreviousNavigableID;
        break;
      default:
        goto LABEL_35;
    }
    v9->mFocusedID = v18;
LABEL_35:
    v9->mSeekingNavigable = 1;
  }
LABEL_36:
  if ( v7 )
    v9->mPreviousNavigableID = v4;
  ++v9->mNavigableCount;
LABEL_39:
  v20 = v9->mFocusedID;
  if ( v6 != v20 )
  {
    v21 = v9->mLastLostFocusID == -1;
    v9->mTextBoxCanDragSelect = 0;
    *(_QWORD *)&v9->mHighlightStart = 0x7FFFFFFFi64;
    v9->mCaretPos = 0;
    v9->mFocusRect.mX = v5->mX;
    v9->mFocusRect.mY = v5->mY;
    v9->mFocusRect.mW = v5->mW;
    v9->mFocusRect.mH = v5->mH;
    if ( v21 )
      v9->mLastLostFocusID = v6;
  }
  return v4 == v20;
}

// File Line: 2485
// RVA: 0x19C820
void __fastcall UFG::RedistributeGridLines(int *ints, int count, int scale)
{
  int v3; // er10
  int *v4; // r9
  int v5; // esi
  signed int v6; // edi
  __m128i v7; // xmm2
  __m128i v8; // xmm1
  __int64 v9; // rax
  __m128i v10; // xmm0
  __m128i v11; // xmm1
  __m128i v12; // xmm1
  signed __int64 v13; // r8
  int v14; // er11
  int v15; // ebx
  int v16; // edx
  __m128d v17; // xmm2
  __m128d v18; // xmm3
  int v19; // eax
  signed __int64 v20; // rcx
  unsigned int *v21; // rdx
  unsigned __int64 v22; // r10
  double v23; // xmm4_8
  double v24; // xmm2_8
  __m128i v25; // xmm0
  __m128i v26; // xmm1
  signed int v27; // eax
  signed int v28; // eax
  __m128i v29; // xmm0

  v3 = 0;
  v4 = ints;
  v5 = scale;
  v6 = 0;
  LODWORD(ints) = 0;
  if ( count > 0 && (unsigned int)count >= 8 )
  {
    v7 = 0i64;
    v8 = 0i64;
    do
    {
      v9 = (signed int)ints;
      LODWORD(ints) = (_DWORD)ints + 8;
      v7 = _mm_add_epi32(_mm_loadu_si128((const __m128i *)&v4[v9]), v7);
      v10 = _mm_add_epi32(_mm_loadu_si128((const __m128i *)&v4[v9 + 4]), v8);
      v8 = v10;
    }
    while ( (signed int)ints < count - count % 8 );
    v11 = _mm_add_epi32(v10, v7);
    v12 = _mm_add_epi32(v11, _mm_srli_si128(v11, 8));
    v6 = _mm_cvtsi128_si32(_mm_add_epi32(v12, _mm_srli_si128(v12, 4)));
  }
  ints = (int *)(signed int)ints;
  v13 = count;
  v14 = 0;
  v15 = 0;
  if ( (signed int)ints < (signed __int64)count )
  {
    if ( count - (signed __int64)ints >= 2 )
    {
      do
      {
        v14 += v4[(_QWORD)ints];
        v15 += v4[(_QWORD)ints + 1];
        ints = (int *)((char *)ints + 2);
      }
      while ( (signed __int64)ints < count - 1i64 );
    }
    if ( (signed __int64)ints < count )
      v6 += v4[(_QWORD)ints];
    v6 += v15 + v14;
  }
  if ( count > 0 && (unsigned int)count >= 4 )
  {
    v16 = count - count % 4;
    v17 = _mm_cvtepi32_pd(_mm_shuffle_epi32(_mm_cvtsi32_si128(v6), 0));
    v18 = _mm_cvtepi32_pd(_mm_shuffle_epi32(_mm_cvtsi32_si128(v5), 0));
    do
    {
      _mm_storel_epi64(
        (__m128i *)&v4[v3],
        _mm_cvttpd_epi32(_mm_mul_pd(_mm_div_pd(_mm_cvtepi32_pd(_mm_loadl_epi64((const __m128i *)&v4[v3])), v17), v18)));
      v19 = v3 + 2;
      v3 += 4;
      _mm_storel_epi64(
        (__m128i *)&v4[v19],
        _mm_cvttpd_epi32(_mm_mul_pd(_mm_div_pd(_mm_cvtepi32_pd(_mm_loadl_epi64((const __m128i *)&v4[v19])), v17), v18)));
    }
    while ( v3 < v16 );
  }
  v20 = v3;
  if ( v3 < v13 )
  {
    if ( v13 - v3 >= 4 )
    {
      v21 = (unsigned int *)&v4[v3 + 2];
      v22 = ((unsigned __int64)(v13 - v3 - 4) >> 2) + 1;
      v23 = (double)v5;
      v24 = 1.0 / (double)v6;
      v20 += 4 * v22;
      do
      {
        v25 = _mm_cvtsi32_si128(*(v21 - 2));
        v26 = _mm_cvtsi32_si128(*v21);
        v21 += 4;
        v27 = (signed int)(COERCE_DOUBLE(_mm_cvtepi32_pd(v25)) * v24 * v23);
        *(double *)v25.m128i_i64 = (double)(signed int)*(v21 - 5);
        *(v21 - 6) = v27;
        v28 = (signed int)(*(double *)v25.m128i_i64 * v24 * v23);
        *(double *)v25.m128i_i64 = (double)(signed int)*(v21 - 3);
        *(v21 - 5) = v28;
        *(v21 - 4) = (signed int)(COERCE_DOUBLE(_mm_cvtepi32_pd(v26)) * v24 * v23);
        *(v21 - 3) = (signed int)(*(double *)v25.m128i_i64 * v24 * v23);
        --v22;
      }
      while ( v22 );
    }
    for ( ; v20 < v13; v4[v20 - 1] = (signed int)(COERCE_DOUBLE(_mm_cvtepi32_pd(v29)) * (1.0 / (double)v6) * (double)v5) )
      v29 = _mm_cvtsi32_si128(v4[v20++]);
  }
}

// File Line: 2500
// RVA: 0x198940
UFG::DUIRect *__fastcall UFG::DUIContext::GetLayoutRect(UFG::DUIContext *this, UFG::DUIRect *result, int rect_width, int rect_height)
{
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v4; // r10
  int v5; // esi
  int v6; // ebp
  UFG::DUIRect *v7; // r11
  UFG::DUIContext *v8; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v9; // rdi
  int v10; // er14
  int v11; // er8
  int v12; // er9
  int v13; // er13
  int v14; // er12
  int v15; // er15
  int v16; // eax
  int v17; // eax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v18; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v19; // rcx
  int v20; // eax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v21; // rcx
  bool v22; // cl
  int v23; // er14
  int v24; // esi
  int v25; // ecx
  int v26; // edx
  int v27; // ecx
  int v28; // eax
  __int64 v29; // r8
  __m128i v30; // xmm1
  float v31; // xmm0_4
  int v32; // eax
  int v33; // ecx
  int v34; // eax
  int v35; // eax
  int v37; // [rsp+40h] [rbp+8h]

  v4 = this->mLayoutStack.mNode.mNext;
  v5 = rect_height;
  v6 = rect_width;
  v7 = result;
  v8 = this;
  v9 = v4 + 1;
  if ( !this->mLayoutOverrideRectEnabled )
  {
    if ( !rect_width )
      v6 = this->mTheme.mRowHeight;
    if ( !rect_height )
      v5 = this->mTheme.mRowHeight;
    v10 = HIDWORD(v4[4].mPrev);
    v11 = HIDWORD(v4[5].mPrev);
    v12 = (int)v4[5].mNext;
    result->mX = (int)v4[2].mPrev;
    result->mY = HIDWORD(v4[2].mPrev);
    v13 = 0;
    result->mW = (int)v4[2].mNext;
    v14 = 0;
    v15 = 0;
    v37 = 0;
    result->mH = HIDWORD(v4[2].mNext);
    if ( v10 & 8 )
    {
      v16 = HIDWORD(v4[4].mNext);
      if ( v16 > 0 && v16 <= v11 )
      {
        v13 = this->mTheme.mLayout_SplitterWidth;
        v14 = -this->mTheme.mLayout_SplitterWidth;
      }
      v17 = (int)v4[5].mPrev;
      if ( v17 > 0 && v17 < v12 )
      {
        v37 = this->mTheme.mLayout_SplitterWidth;
        v15 = -v37;
      }
    }
    if ( !v12 )
      result->mH = v5;
    if ( !v11 )
      result->mW = v6;
    v18 = v4[6].mPrev;
    if ( v10 & 4 )
    {
      if ( v18 )
      {
        result->mW = *((_DWORD *)&v18->mPrev + SHIDWORD(v4[4].mNext));
      }
      else if ( v11 > 0 )
      {
        result->mW = SLODWORD(v4[1].mNext) / v11;
      }
      v19 = v4[6].mNext;
      if ( v19 )
      {
        result->mH = *((_DWORD *)&v19->mPrev + SLODWORD(v4[5].mPrev));
        goto LABEL_42;
      }
      if ( v12 > 0 )
      {
        v20 = SHIDWORD(v4[1].mNext) / v12;
LABEL_41:
        result->mH = v20;
        goto LABEL_42;
      }
    }
    else
    {
      if ( v18 )
      {
        result->mW = *((_DWORD *)&v18->mPrev + SHIDWORD(v4[4].mNext));
      }
      else if ( v11 > 0 )
      {
        result->mW = SLODWORD(v4[1].mNext) / v11;
      }
      v21 = v4[6].mNext;
      if ( v21 )
      {
        result->mH = *((_DWORD *)&v21->mPrev + SLODWORD(v4[5].mPrev));
      }
      else if ( v12 > 0 )
      {
        result->mH = v5;
      }
      if ( v10 & 3 )
      {
        v22 = LODWORD(v4[5].mPrev) == v12 - 1;
        if ( HIDWORD(v4[4].mNext) == v11 - 1 && v10 & 1 )
          result->mW = LODWORD(v9->mPrev) + LODWORD(v4[1].mNext) - LODWORD(v4[2].mPrev);
        if ( v22 && v10 & 2 )
        {
          v20 = HIDWORD(v4[1].mPrev) + HIDWORD(v4[1].mNext) - HIDWORD(v4[2].mPrev);
          goto LABEL_41;
        }
      }
    }
LABEL_42:
    result->mX += v13;
    result->mW += v14;
    result->mH += v15;
    v23 = result->mX;
    v24 = result->mW;
    result->mY += v37;
    v25 = result->mH;
    if ( v11 <= 0 )
    {
      if ( v12 <= 0 )
        goto LABEL_50;
      if ( ++LODWORD(v4[5].mPrev) >= v12 )
      {
        ++HIDWORD(v4[4].mNext);
        LODWORD(v4[5].mPrev) = 0;
        LODWORD(v4[2].mPrev) += v24;
        HIDWORD(v4[2].mPrev) = HIDWORD(v4[1].mPrev);
        goto LABEL_50;
      }
    }
    else
    {
      if ( ++HIDWORD(v4[4].mNext) < v11 )
      {
        LODWORD(v4[2].mPrev) += v24 - v14;
LABEL_50:
        v4 = v8->mLayoutStack.mNode.mNext;
        v26 = v8->mTheme.mIndent * LODWORD(v4[4].mPrev);
        v7->mX = v26 + v23 + LODWORD(v4[9].mNext);
        v27 = HIDWORD(v4[9].mNext);
        v7->mW = v24 - v26;
        v7->mY += v27;
        goto LABEL_52;
      }
      ++LODWORD(v4[5].mPrev);
      HIDWORD(v4[4].mNext) = 0;
      LODWORD(v4[2].mPrev) = v9->mPrev;
    }
    HIDWORD(v4[2].mPrev) += v25 - v15;
    goto LABEL_50;
  }
  v28 = this->mLayoutOverrideRect.mX;
  this->mLayoutOverrideRectEnabled = 0;
  result->mX = v28;
  result->mY = this->mLayoutOverrideRect.mY;
  result->mW = this->mLayoutOverrideRect.mW;
  result->mH = this->mLayoutOverrideRect.mH;
LABEL_52:
  v29 = *(_QWORD *)&v7->mW;
  v30 = _mm_cvtsi32_si128(-HIDWORD(v9->mPrev));
  v31 = (float)(signed int)(*(_QWORD *)&v7->mX >> 32);
  v32 = (int)v4[3].mNext;
  if ( v32 < (signed int)v29 + (signed int)(float)((float)-LODWORD(v9->mPrev) + (float)(signed int)*(_QWORD *)&v7->mX) )
    v32 = v29 + (signed int)(float)((float)-LODWORD(v9->mPrev) + (float)(signed int)*(_QWORD *)&v7->mX);
  v33 = HIDWORD(v4[3].mNext);
  LODWORD(v4[3].mNext) = v32;
  v34 = HIDWORD(v29) + (signed int)(float)(COERCE_FLOAT(_mm_cvtepi32_ps(v30)) + v31);
  if ( v33 < v34 )
    v33 = v34;
  v35 = v7->mX;
  HIDWORD(v4[3].mNext) = v33;
  v8->mLastRect.mX = v35;
  v8->mLastRect.mY = v7->mY;
  v8->mLastRect.mW = v7->mW;
  v8->mLastRect.mH = v7->mH;
  return v7;
}

// File Line: 2681
// RVA: 0x198F00
UFG::DUIContext *__fastcall UFG::DUIContext::GridSplitter(UFG::DUIContext *this, int width, int *xy, UFG::DUIContext::Orient orient)
{
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v4; // r10
  int v5; // eax
  UFG::DUIContext *v6; // rbx
  int v7; // ecx
  int *v8; // rdi
  int grip_min_w; // eax
  char v10; // al
  UFG::DUIRect rect_track; // [rsp+70h] [rbp-28h]
  UFG::DUIRect rect_grip; // [rsp+80h] [rbp-18h]
  long double value_y; // [rsp+A0h] [rbp+8h]
  long double value_x; // [rsp+B0h] [rbp+18h]

  v4 = this->mLayoutStack.mNode.mNext;
  v5 = (int)v4[1].mPrev;
  v6 = this;
  v7 = HIDWORD(v4[1].mNext);
  value_y = (double)*xy;
  rect_track.mX = v5;
  v8 = xy;
  rect_track.mY = HIDWORD(v4[1].mPrev);
  grip_min_w = (int)v4[1].mNext;
  rect_track.mH = v7;
  *(_QWORD *)&rect_grip.mX = 0i64;
  *(_QWORD *)&rect_grip.mW = 0i64;
  rect_track.mW = grip_min_w;
  if ( orient )
  {
    if ( orient != 1 )
      goto LABEL_7;
    value_x = 0.0;
    v10 = UFG::DUIContext::Draggable2D(
            v6,
            &value_x,
            &value_y,
            &rect_grip,
            &rect_track,
            0.0,
            0.0,
            0.0,
            (double)(v7 - width),
            1.0,
            1.0 / (double)v7 * (double)width,
            grip_min_w,
            width,
            0);
  }
  else
  {
    value_x = 0.0;
    v10 = UFG::DUIContext::Draggable2D(
            v6,
            &value_y,
            &value_x,
            &rect_grip,
            &rect_track,
            0.0,
            0.0,
            (double)(grip_min_w - width),
            0.0,
            1.0 / (double)grip_min_w * (double)width,
            1.0,
            width,
            rect_track.mH,
            0);
  }
  if ( v10 )
  {
    v6->mInputState.mMouseWheelDelta = 0;
    *(_QWORD *)&v6->mInputState.mMouseLBWentDown = 0i64;
    *(_WORD *)&v6->mInputState.mLMBDoubleClick = 0;
    v6->mInputState.mMouseMBWentUp = 0;
    v6->mInputState.mMMBDoubleClick = 0;
    v6->mInputState.mMouseEventHandled = 1;
  }
LABEL_7:
  *v8 = (signed int)value_y;
  return v6;
}

// File Line: 2717
// RVA: 0x19DA00
UFG::DUIContext *__fastcall UFG::DUIContext::SetLayoutRect(UFG::DUIContext *this, UFG::DUIRect *rect)
{
  int v2; // eax

  this->mLayoutOverrideRect.mX = rect->mX;
  this->mLayoutOverrideRect.mY = rect->mY;
  this->mLayoutOverrideRect.mW = rect->mW;
  v2 = rect->mH;
  this->mLayoutOverrideRectEnabled = 1;
  this->mLayoutOverrideRect.mH = v2;
  return this;
}

// File Line: 2731
// RVA: 0x19C540
UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *__fastcall UFG::DUIContext::PushLayoutState(UFG::DUIContext *this, UFG::DUIRect *rect, UFG::DUI::LayoutFlag flags)
{
  UFG::DUI::LayoutFlag v3; // edi
  UFG::DUIRect *v4; // rsi
  UFG::DUIContext *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v7; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v8; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v9; // rcx

  v3 = flags;
  v4 = rect;
  v5 = this;
  v6 = UFG::qMalloc(0xB8ui64, "DUILayoutState", 0x800ui64);
  if ( v6 )
  {
    UFG::DUILayoutState::DUILayoutState((UFG::DUILayoutState *)v6, v4, v3, 0);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = v5->mLayoutStack.mNode.mNext;
  v5->mLayoutStack.mNode.mNext = v8;
  v8->mPrev = &v5->mLayoutStack.mNode;
  v8->mNext = v9;
  v9->mPrev = v8;
  return v8;
}

// File Line: 2739
// RVA: 0x19C4A0
UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *__fastcall UFG::DUIContext::PushLayoutState(UFG::DUIContext *this, UFG::DUIRect *rect, UFG::DUIRect *scissor_rect, UFG::DUI::LayoutFlag flags)
{
  UFG::DUI::LayoutFlag v4; // ebx
  UFG::DUIRect *v5; // rsi
  UFG::DUIRect *v6; // rbp
  UFG::DUIContext *v7; // rdi
  UFG::allocator::free_link *v8; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v9; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v10; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v11; // rcx

  v4 = flags;
  v5 = scissor_rect;
  v6 = rect;
  v7 = this;
  v8 = UFG::qMalloc(0xB8ui64, "DUILayoutState", 0x800ui64);
  if ( v8 )
  {
    UFG::DUILayoutState::DUILayoutState((UFG::DUILayoutState *)v8, v6, v4, 1);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = v7->mLayoutStack.mNode.mNext;
  v7->mLayoutStack.mNode.mNext = v10;
  v10->mPrev = &v7->mLayoutStack.mNode;
  v10->mNext = v11;
  v11->mPrev = v10;
  UFG::DUIContext::PushScissor(v7, v5);
  return v10;
}

// File Line: 2749
// RVA: 0x19C5D0
void __fastcall UFG::DUIContext::PushScissor(UFG::DUIContext *this, UFG::DUIRect *scissor_rect)
{
  UFG::DUIContext *v2; // rsi
  __int64 v3; // rcx
  int v4; // er15
  int v5; // er8
  int v6; // er12
  int v7; // ebp
  int v8; // ebp
  int v9; // er14
  int v10; // er14
  UFG::allocator::free_link *v11; // rax
  _QWORD *v12; // rdx
  signed __int64 v13; // rcx
  _QWORD *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rdi
  UFG::qColour v17; // xmm6
  UFG::DUIContextVtbl **v18; // rcx
  UFG::allocator::free_link *v19; // rax
  __m128i v20; // [rsp+30h] [rbp-78h]

  v2 = this;
  v3 = this->mCurrentCompositeLayer;
  if ( (UFG::qList<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect>,1,0> *)v2->mScissorStacks[v3].mNode.mNext == &v2->mScissorStacks[v3] )
  {
    v20.m128i_i64[0] = 0i64;
    v20.m128i_i64[1] = 214748364805000i64;
    _mm_store_si128(&v20, v20);
  }
  else
  {
    v20 = *(__m128i *)&(&v2->vfptr)[2 * (v3 + 54)][2].UpdateUI;
  }
  v4 = scissor_rect->mX;
  if ( v20.m128i_i32[0] > scissor_rect->mX )
    v4 = v20.m128i_i32[0];
  v5 = scissor_rect->mY;
  v6 = v5;
  if ( v20.m128i_i32[1] > v5 )
    v6 = v20.m128i_i32[1];
  v7 = scissor_rect->mX + scissor_rect->mW;
  if ( v20.m128i_i32[2] + v20.m128i_i32[0] < v7 )
    v7 = v20.m128i_i32[2] + v20.m128i_i32[0];
  v8 = v7 - v4;
  v9 = v5 + scissor_rect->mH;
  if ( v20.m128i_i32[3] + v20.m128i_i32[1] < v9 )
    v9 = v20.m128i_i32[3] + v20.m128i_i32[1];
  v10 = v9 - v6;
  v11 = UFG::qMalloc(0x20ui64, "DUIScissorRect", 0i64);
  v12 = &v11->mNext;
  if ( v11 )
  {
    v11->mNext = v11;
    v11[1].mNext = v11;
    LODWORD(v11[2].mNext) = v4;
    HIDWORD(v11[2].mNext) = v6;
    LODWORD(v11[3].mNext) = v8;
    HIDWORD(v11[3].mNext) = v10;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = (signed __int64)&v2->mScissorStacks[v2->mCurrentCompositeLayer];
  v14 = *(_QWORD **)(v13 + 8);
  *(_QWORD *)(v13 + 8) = v12;
  *v12 = v13;
  v12[1] = v14;
  *v14 = v12;
  if ( v2->mBuildCommandList )
  {
    v15 = UFG::qMalloc(0xA8ui64, "DUIScissorRenderCommand", 0x800ui64);
    v16 = v15;
    if ( v15 )
    {
      v17 = UFG::qColourWhite;
      v15->mNext = v15;
      v15[1].mNext = v15;
      UFG::qString::qString((UFG::qString *)&v15[14]);
      LODWORD(v16[2].mNext) = 3;
      HIDWORD(v16[2].mNext) = v4;
      LODWORD(v16[3].mNext) = v6;
      HIDWORD(v16[3].mNext) = v8;
      LODWORD(v16[4].mNext) = v10;
      v16[5].mNext = 0i64;
      *(UFG::qColour *)&v16[6].mNext = v17;
      *(UFG::qColour *)&v16[8].mNext = v17;
      *(UFG::qColour *)&v16[10].mNext = v17;
      *(UFG::qColour *)&v16[12].mNext = v17;
      UFG::qString::Set((UFG::qString *)&v16[14], 0i64);
      LODWORD(v16[19].mNext) = 0;
    }
    else
    {
      v16 = 0i64;
    }
    v18 = &(&v2->vfptr)[2 * ((signed int)v2->mCurrentCompositeLayer + 88i64)];
    v19 = (UFG::allocator::free_link *)*v18;
    v19[1].mNext = v16;
    v16->mNext = v19;
    v16[1].mNext = (UFG::allocator::free_link *)v18;
    *v18 = (UFG::DUIContextVtbl *)v16;
  }
}

// File Line: 2780
// RVA: 0x19C110
void __fastcall UFG::DUIContext::PopScissor(UFG::DUIContext *this)
{
  UFG::DUIContext *v1; // r12
  char *v2; // rcx
  __int64 *v3; // rcx
  __int64 v4; // rdx
  _QWORD *v5; // rax
  __int64 v6; // rdx
  _QWORD *v7; // rax
  UFG::DUIContextVtbl *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // r15
  UFG::qColour v11; // ST60_16
  UFG::qColour v12; // ST50_16
  UFG::qColour v13; // ST40_16
  UFG::qColour v14; // ST30_16
  int v15; // ebp
  int v16; // esi
  int v17; // edi
  int v18; // ebx
  UFG::DUIContextVtbl **v19; // rcx
  UFG::allocator::free_link *v20; // rax

  v1 = this;
  v2 = (char *)&this->mScissorStacks[this->mCurrentCompositeLayer];
  if ( *((char **)v2 + 1) != v2 )
  {
    v3 = (__int64 *)*((_QWORD *)v2 + 1);
    v4 = *v3;
    v5 = (_QWORD *)v3[1];
    *(_QWORD *)(v4 + 8) = v5;
    *v5 = v4;
    *v3 = (__int64)v3;
    v3[1] = (__int64)v3;
    v6 = *v3;
    v7 = (_QWORD *)v3[1];
    *(_QWORD *)(v6 + 8) = v7;
    *v7 = v6;
    *v3 = (__int64)v3;
    v3[1] = (__int64)v3;
    operator delete[](v3);
    v8 = (&v1->vfptr)[2 * ((signed int)v1->mCurrentCompositeLayer + 54i64)];
    if ( v1->mBuildCommandList )
    {
      v9 = UFG::qMalloc(0xA8ui64, "DUIRenderCommand", 0x800ui64);
      v10 = v9;
      if ( v9 )
      {
        v11 = UFG::qColourWhite;
        v12 = UFG::qColourWhite;
        v13 = UFG::qColourWhite;
        v14 = UFG::qColourWhite;
        v15 = HIDWORD(v8[3].UpdateUI);
        v16 = (int)v8[3].UpdateUI;
        v17 = HIDWORD(v8[2].UpdateUI);
        v18 = (int)v8[2].UpdateUI;
        v9->mNext = v9;
        v9[1].mNext = v9;
        UFG::qString::qString((UFG::qString *)&v9[14]);
        LODWORD(v10[2].mNext) = 3;
        HIDWORD(v10[2].mNext) = v18;
        LODWORD(v10[3].mNext) = v17;
        HIDWORD(v10[3].mNext) = v16;
        LODWORD(v10[4].mNext) = v15;
        v10[5].mNext = 0i64;
        *(UFG::qColour *)&v10[6].mNext = v14;
        *(UFG::qColour *)&v10[8].mNext = v13;
        *(UFG::qColour *)&v10[10].mNext = v12;
        *(UFG::qColour *)&v10[12].mNext = v11;
        UFG::qString::Set((UFG::qString *)&v10[14], 0i64);
        LODWORD(v10[19].mNext) = 0;
      }
      else
      {
        v10 = 0i64;
      }
      v19 = &(&v1->vfptr)[2 * ((signed int)v1->mCurrentCompositeLayer + 88i64)];
      v20 = (UFG::allocator::free_link *)*v19;
      v20[1].mNext = v10;
      v10->mNext = v20;
      v10[1].mNext = (UFG::allocator::free_link *)v19;
      *v19 = (UFG::DUIContextVtbl *)v10;
    }
  }
}

// File Line: 2797
// RVA: 0x19C090
void __fastcall UFG::DUIContext::PopLayoutState(UFG::DUIContext *this)
{
  UFG::DUILayoutState *v1; // rbx
  UFG::DUIContext *v2; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v3; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v4; // rax

  v1 = (UFG::DUILayoutState *)this->mLayoutStack.mNode.mNext;
  v2 = this;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v1->mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&v1->mPrev;
  if ( v1->mClip )
    UFG::DUIContext::PopScissor(this);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)v2->mLayoutStack.mNode.mNext != &v2->mLayoutStack
    && v2->mCurrentCompositeLayer != 1 )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&v2->mLayoutStack.mNode.mNext[3], &v1->mMaximumRect);
  }
  UFG::DUILayoutState::~DUILayoutState(v1);
  operator delete[](v1);
}

// File Line: 2822
// RVA: 0x194BF0
UFG::DUIContext *__fastcall UFG::DUIContext::BeginIndent(UFG::DUIContext *this)
{
  ++LODWORD(this->mLayoutStack.mNode.mNext[4].mPrev);
  return this;
}

// File Line: 2828
// RVA: 0x197CD0
UFG::DUIContext *__fastcall UFG::DUIContext::EndIndent(UFG::DUIContext *this)
{
  float v1; // xmm0_4

  v1 = 0.0;
  if ( (float)(LODWORD(this->mLayoutStack.mNode.mNext[4].mPrev) - 1) >= 0.0 )
    v1 = (float)(LODWORD(this->mLayoutStack.mNode.mNext[4].mPrev) - 1);
  LODWORD(this->mLayoutStack.mNode.mNext[4].mPrev) = (signed int)v1;
  return this;
}

// File Line: 3005
// RVA: 0x195720
bool __fastcall UFG::DUIContext::Clickable(UFG::DUIContext *this, UFG::DUIContext::ClickableState *click_state, UFG::DUIRect *current_rect, UFG::DUIRect *rect_grip, UFG::DUIContext::ClickableFlags flags)
{
  UFG::DUIRect *v5; // rsi
  UFG::DUIContext::ClickableState *v6; // rdi
  UFG::DUIContext *v7; // rbx
  int v8; // edx
  int v9; // edx
  int v10; // ecx

  v5 = rect_grip;
  *click_state = 0;
  v6 = click_state;
  v7 = this;
  this->mDoubleClicked = 0;
  if ( UFG::DUIContext::TakeFocus(this, current_rect, rect_grip, 0) )
  {
    if ( v7->mInputState.mMouseLBWentDown || v7->mInputState.mMouseLBIsDown )
      *v6 = 2;
    v8 = v7->mInputState.mMousePos.mX;
    if ( v8 >= v5->mX && v8 <= v5->mW + v5->mX )
    {
      v9 = v7->mInputState.mMousePos.mY;
      v10 = v5->mY;
      if ( v9 >= v10 && v9 <= v5->mH + v10 - 1 && !v7->mInputState.mMouseEventHandled )
      {
        if ( v7->mInputState.mMouseLBWentUp )
        {
          *v6 = 3;
          v7->mDoubleClicked = 0;
        }
        else if ( v7->mInputState.mLMBDoubleClick )
        {
          *v6 = 4;
          v7->mDoubleClicked = 1;
        }
      }
    }
    if ( v7->mInputState.mMouseLBWentUp )
    {
      v7->mFocusedID = -1;
      v7->mFocusOffset = (UFG::DUIPoint)-1i64;
      v7->mDoubleClicked = 0;
      if ( *v6 == 2 )
        *v6 = UFG::DUIContext::IsHot(v7, v5) != 0;
    }
    if ( flags & 1 )
    {
      v7->mInputState.mMouseWheelDelta = 0;
      *(_QWORD *)&v7->mInputState.mMouseLBWentDown = 0i64;
      *(_WORD *)&v7->mInputState.mLMBDoubleClick = 0;
      v7->mInputState.mMouseMBWentUp = 0;
      v7->mInputState.mMMBDoubleClick = 0;
    }
  }
  else if ( !v7->mInputState.mMouseLBIsDown
         && !v7->mInputState.mMouseRBIsDown
         && !v7->mInputState.mMouseMBIsDown
         && UFG::DUIContext::IsMouseOver(v7, v5)
         && !v7->mInputState.mMouseEventHandled )
  {
    *v6 = 1;
  }
  return *v6 == 3;
}

// File Line: 3159
// RVA: 0x197670
char __fastcall UFG::DUIContext::Draggable2D(UFG::DUIContext *this, long double *value_x, long double *value_y, UFG::DUIRect *rect_grip, UFG::DUIRect *rect_track, long double value_min_x, long double value_min_y, long double value_max_x, long double value_max_y, long double grip_pw, long double grip_ph, int grip_min_w, int grip_min_h, bool quantize_value)
{
  UFG::DUIRect *v14; // r14
  long double *v15; // rdi
  long double *v16; // rsi
  UFG::DUIContext *v17; // rbx
  double v18; // xmm10_8
  long double v19; // xmm12_8
  double v20; // xmm8_8
  double v21; // xmm0_8
  double v22; // xmm8_8
  double v23; // xmm9_8
  double v24; // xmm0_8
  double v25; // xmm6_8
  double v26; // xmm9_8
  double v27; // xmm1_8
  double v28; // xmm2_8
  double v29; // xmm3_8
  double v30; // xmm4_8
  int v31; // ecx
  int v32; // ebp
  int v33; // er12
  int v34; // er8
  int v35; // edx
  double v36; // xmm0_8
  int v37; // ecx
  int v38; // ebp
  int v39; // er12
  int v40; // eax
  int v41; // edx
  int v42; // ecx
  float v43; // xmm2_4
  int v44; // edx
  int v45; // eax
  int v46; // er8
  int v47; // edx
  int v48; // ecx
  int v49; // eax
  int v50; // ecx
  int v51; // eax
  double v52; // xmm0_8
  char result; // al
  double value_min_xa; // [rsp+118h] [rbp+30h]
  double value_max_xa; // [rsp+128h] [rbp+40h]

  v14 = rect_grip;
  v15 = value_y;
  v16 = value_x;
  v17 = this;
  v18 = value_min_x;
  v19 = value_max_x;
  if ( value_max_x <= value_min_x )
    v20 = value_min_x;
  else
    v20 = value_max_x;
  if ( value_max_x >= value_min_x )
    v21 = value_min_x;
  else
    v21 = value_max_x;
  v22 = v20 - v21;
  if ( value_max_y <= value_min_y )
    v23 = value_min_y;
  else
    v23 = value_max_y;
  if ( value_max_y >= value_min_y )
    v24 = value_min_y;
  else
    v24 = value_max_y;
  v25 = 0.0;
  v26 = v23 - v24;
  if ( v22 <= 0.0 )
    v27 = 0.0;
  else
    v27 = (*value_x - value_min_x) / v22;
  if ( v26 <= 0.0 )
    v28 = 0.0;
  else
    v28 = (*value_y - value_min_y) / v26;
  if ( v27 <= 0.0 )
  {
    v27 = 0.0;
  }
  else if ( v27 >= 1.0 )
  {
    v27 = DOUBLE_1_0;
  }
  if ( v28 <= 0.0 )
  {
    v28 = 0.0;
  }
  else if ( v28 >= 1.0 )
  {
    v28 = DOUBLE_1_0;
  }
  v29 = grip_pw;
  if ( grip_pw < 0.0 )
    v29 = 1.0 / (v22 + 1.0);
  v30 = grip_ph;
  if ( grip_ph < 0.0 )
    v30 = 1.0 / (v26 + 1.0);
  v31 = grip_min_w;
  v32 = rect_track->mW;
  v33 = rect_track->mH;
  v34 = rect_track->mW;
  v35 = rect_track->mH;
  if ( (signed int)((double)rect_track->mW * v29) > grip_min_w )
    v31 = (signed int)((double)rect_track->mW * v29);
  if ( v31 < v32 )
    v34 = v31;
  v37 = grip_min_h;
  v36 = (double)rect_track->mH;
  if ( (signed int)(v36 * v30) > grip_min_h )
    v37 = (signed int)(v36 * v30);
  if ( v37 < v33 )
    v35 = v37;
  v38 = v32 - v34 - 1;
  v39 = v33 - v35 - 1;
  value_max_xa = v22 / (double)v38;
  value_min_xa = v26 / (double)v39;
  rect_grip->mX = rect_track->mX + (signed int)((double)v38 * v27);
  v40 = rect_track->mY + (signed int)((double)v39 * v28);
  rect_grip->mH = v35;
  rect_grip->mW = v34;
  rect_grip->mY = v40;
  UFG::DUIContext::Clickable(v17, (UFG::DUIContext::ClickableState *)&grip_min_w, rect_grip, rect_grip, 0);
  if ( grip_min_w != 2 )
    return 0;
  if ( value_max_xa < 1.0 )
    v41 = 0;
  else
    v41 = v17->mFocusOffset.mX;
  if ( value_min_xa < 1.0 )
    v42 = 0;
  else
    v42 = v17->mFocusOffset.mY;
  v43 = (float)(v42 + v17->mInputState.mMousePos.mY - rect_track->mY) / (float)rect_track->mH;
  v44 = rect_track->mX
      + (signed int)(float)((float)((float)(v41 + v17->mInputState.mMousePos.mX - rect_track->mX) / (float)rect_track->mW)
                          * (float)rect_track->mW);
  v14->mX = v44;
  v45 = rect_track->mY + (signed int)(float)((float)rect_track->mH * v43);
  v14->mY = v45;
  v46 = rect_track->mX - v14->mW + rect_track->mW - 1;
  if ( v44 < v46 )
    v46 = v44;
  v14->mX = v46;
  v47 = rect_track->mH - v14->mH + rect_track->mY - 1;
  if ( v45 < v47 )
    v47 = v45;
  v14->mY = v47;
  v48 = rect_track->mX;
  if ( v46 > rect_track->mX )
    v48 = v46;
  v14->mX = v48;
  v49 = rect_track->mY;
  if ( v47 > v49 )
    v49 = v47;
  v14->mY = v49;
  v50 = v48 - rect_track->mX;
  v51 = v49 - rect_track->mY;
  if ( v50 > 0 )
  {
    if ( v50 < v38 )
      *v16 = (double)v50 * value_max_xa + v18;
    else
      *v16 = v19;
  }
  else
  {
    *v16 = v18;
  }
  if ( v51 > 0 )
  {
    if ( v51 < v39 )
      *v15 = (double)v51 * value_min_xa + value_min_y;
    else
      *v15 = value_max_y;
  }
  else
  {
    *v15 = value_min_y;
  }
  if ( quantize_value )
  {
    if ( v22 <= 0.0 )
      v52 = 0.0;
    else
      v52 = ((double)(signed int)*v16 - v18) / v22;
    if ( v26 > 0.0 )
      v25 = ((double)(signed int)*v15 - value_min_y) / v26;
    v14->mX = rect_track->mX + (signed int)((double)v38 * v52);
    v14->mY = rect_track->mY + (signed int)((double)v39 * v25);
  }
  v17->mInputState.mMouseWheelDelta = 0;
  *(_QWORD *)&v17->mInputState.mMouseLBWentDown = 0i64;
  *(_WORD *)&v17->mInputState.mLMBDoubleClick = 0;
  v17->mInputState.mMouseMBWentUp = 0;
  v17->mInputState.mMMBDoubleClick = 0;
  result = 1;
  v17->mInputState.mMouseEventHandled = 1;
  return result;
}

// File Line: 3261
// RVA: 0x19D290
bool __fastcall UFG::DUIContext::Scrollbar(UFG::DUIContext *this, UFG::DUIRect *rect, int *current_value, int min)
{
  int v4; // er12
  UFG::DUIContext *v5; // rbx
  int v6; // er14
  int *v7; // r15
  int v8; // er8
  int v9; // ecx
  int v10; // edi
  int v11; // er11
  double v12; // xmm6_8
  char v13; // r10
  int v14; // eax
  long double *v15; // r8
  long double *v16; // rdx
  int v17; // eax
  char v18; // al
  int v19; // er9
  UFG::DUIContextVtbl *v20; // rdx
  int v21; // ecx
  int v22; // er8
  int v23; // ecx
  bool v24; // cl
  UFG::qColour *v25; // rax
  int v26; // xmm1_4
  int v27; // xmm0_4
  float v28; // xmm1_4
  double value_min_x; // [rsp+28h] [rbp-51h]
  double value_min_y; // [rsp+30h] [rbp-49h]
  double value_max_x; // [rsp+38h] [rbp-41h]
  double value_max_y; // [rsp+40h] [rbp-39h]
  UFG::DUIRect rect_grip; // [rsp+48h] [rbp-31h]
  UFG::DUIRect recta; // [rsp+58h] [rbp-21h]
  bool quantize_value[4]; // [rsp+68h] [rbp-11h]
  int v37; // [rsp+6Ch] [rbp-Dh]
  int v38; // [rsp+70h] [rbp-9h]
  float v39; // [rsp+74h] [rbp-5h]
  long double value_y; // [rsp+C8h] [rbp+4Fh]
  long double value_x; // [rsp+D0h] [rbp+57h]
  void *retaddr; // [rsp+E8h] [rbp+6Fh]
  signed int v43; // [rsp+F0h] [rbp+77h]
  int v44; // [rsp+F8h] [rbp+7Fh]

  v4 = *current_value;
  v5 = this;
  v6 = rect->mW - 4;
  recta.mX = rect->mX + 2;
  v7 = current_value;
  v8 = rect->mH - 4;
  recta.mY = rect->mY + 1;
  recta.mW = v6;
  recta.mH = v8;
  v9 = (_DWORD)retaddr - v43;
  v10 = 0;
  *(_QWORD *)&rect_grip.mX = 0i64;
  v11 = 0;
  *(_QWORD *)&rect_grip.mW = 0i64;
  if ( min > (signed int)retaddr - v43 )
    v9 = min;
  if ( (signed int)retaddr - min <= 0 )
    v12 = DOUBLE_1_0;
  else
    v12 = (double)v43 / (double)((signed int)retaddr - min);
  v13 = 0;
  value_y = (double)v4;
  if ( v44 == 1 )
  {
    v14 = v5->mTheme.mSliderSize;
    quantize_value[0] = 1;
    recta.mW = v8;
    recta.mX = v14;
    v15 = &value_x;
    v16 = &value_y;
    *(long double *)&rect_grip.mW = DOUBLE_1_0;
    *(double *)&rect_grip.mX = v12;
    value_max_y = 0.0;
    value_max_x = (double)v9;
    value_min_y = 0.0;
    value_min_x = (double)min;
LABEL_10:
    value_x = 0.0;
    v18 = UFG::DUIContext::Draggable2D(
            v5,
            v16,
            v15,
            &rect_grip,
            &recta,
            value_min_x,
            value_min_y,
            value_max_x,
            value_max_y,
            *(long double *)&rect_grip.mX,
            *(long double *)&rect_grip.mW,
            recta.mX,
            recta.mW,
            quantize_value[0]);
    v10 = rect_grip.mX;
    v11 = rect_grip.mY;
    v13 = v18;
    goto LABEL_11;
  }
  if ( !v44 )
  {
    v17 = v5->mTheme.mSliderSize;
    quantize_value[0] = 1;
    recta.mW = v17;
    recta.mX = v6;
    v15 = &value_y;
    v16 = &value_x;
    *(double *)&rect_grip.mW = v12;
    *(long double *)&rect_grip.mX = DOUBLE_1_0;
    value_max_y = (double)v9;
    value_max_x = 0.0;
    value_min_y = (double)min;
    value_min_x = 0.0;
    goto LABEL_10;
  }
LABEL_11:
  v24 = 0;
  if ( !v5->mInputState.mMouseLBIsDown && !v5->mInputState.mMouseRBIsDown && !v5->mInputState.mMouseMBIsDown )
  {
    v19 = v5->mInputState.mMousePos.mX;
    v20 = (&v5->vfptr)[2 * ((signed int)v5->mCurrentCompositeLayer + 54i64)];
    v21 = (int)v20[2].UpdateUI;
    if ( v19 >= v21 && v19 <= LODWORD(v20[3].UpdateUI) + v21 )
    {
      v22 = v5->mInputState.mMousePos.mY;
      v23 = HIDWORD(v20[2].UpdateUI);
      if ( v22 >= v23
        && v22 <= HIDWORD(v20[3].UpdateUI) + v23 - 1
        && v19 >= v10
        && v19 <= v10 + rect_grip.mW
        && v22 >= v11
        && v22 <= v11 + rect_grip.mH - 1
        && !v5->mInputState.mMouseEventHandled )
      {
        v24 = 1;
      }
    }
  }
  if ( v13 )
    *v7 = (signed int)value_y;
  if ( v24 || (v25 = v5->mTheme.mColour, v13) )
    v25 = &v5->mTheme.mColour[20];
  v26 = LODWORD(v25->g);
  *(float *)quantize_value = v25->r;
  v27 = LODWORD(v25->b);
  v37 = v26;
  v28 = v25->a;
  v38 = v27;
  v39 = v28;
  if ( v12 >= 1.0 )
    v39 = FLOAT_0_2;
  UFG::DUIContext::RenderRoundRect(v5, &recta, &v5->mTheme.mColour[18], 0);
  UFG::DUIContext::RenderRoundRect(v5, &rect_grip, (UFG::qColour *)quantize_value, 0);
  return *v7 != v4;
}

// File Line: 3318
// RVA: 0x1992B0
void __fastcall UFG::DUIContext::Header(UFG::DUIContext *this, const char *name, UFG::qColour *fg_colour, UFG::qColour *bg_colour)
{
  UFG::qColour *v4; // rdi
  UFG::qColour *v5; // rsi
  const char *v6; // r14
  UFG::DUIContext *v7; // rbx
  int v8; // ecx
  int v9; // edx
  UFG::DUIRect v10; // xmm1
  int v11; // er8
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  UFG::DUIRect v15; // xmm0
  UFG::DUIRect v16; // [rsp+30h] [rbp-30h]
  UFG::DUIRect result; // [rsp+40h] [rbp-20h]
  UFG::DUIRect rect; // [rsp+50h] [rbp-10h]

  v4 = bg_colour;
  v5 = fg_colour;
  v6 = name;
  v7 = this;
  if ( !fg_colour )
    v5 = this->mTheme.mColour;
  if ( !bg_colour )
    v4 = &this->mTheme.mColour[11];
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v8 = v7->mTheme.mButton_Inset.mX;
  v9 = v7->mTheme.mButton_Inset.mY;
  v10 = result;
  _mm_store_si128((__m128i *)&v16, (__m128i)result);
  v11 = _mm_cvtsi128_si32((__m128i)v10);
  v16.mY += v9;
  v16.mX = v11 + v8;
  v16.mW -= 2 * v8;
  v12 = v16.mH - 2 * v9;
  v13 = v7->mTheme.mButton_Text.mY;
  v16.mH = v12;
  v14 = v7->mTheme.mButton_Text.mX;
  v15 = v16;
  _mm_store_si128((__m128i *)&v16, (__m128i)v10);
  v16.mY += v13;
  _mm_store_si128((__m128i *)&rect, (__m128i)v15);
  v16.mX = v11 + v14;
  v16.mW -= 2 * v14;
  v16.mH -= 2 * v13;
  _mm_store_si128((__m128i *)&v16, (__m128i)v16);
  UFG::DUIContext::PushScissor(v7, &result);
  UFG::DUIContext::RenderRect(v7, &rect, v4, 0);
  UFG::DUIContext::RenderText(v7, &v16, v5, v6, 0x10u);
  UFG::DUIContext::PopScissor(v7);
}

// File Line: 3340
// RVA: 0x19A0E0
void __fastcall UFG::DUIContext::Label(UFG::DUIContext *this, const char *name)
{
  const char *v2; // rbx
  UFG::DUIContext *v3; // rdi
  UFG::DUIRect result; // [rsp+30h] [rbp-18h]

  v2 = name;
  v3 = this;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(v3, &result);
  UFG::DUIContext::RenderText(v3, &result, v3->mTheme.mColour, v2, 0x10u);
  UFG::DUIContext::PopScissor(v3);
}

// File Line: 3355
// RVA: 0x19D560
void __fastcall UFG::DUIContext::Separator(UFG::DUIContext *this)
{
  UFG::DUIContext *v1; // rbx
  int v2; // ecx
  int v3; // eax
  UFG::DUIRect v4; // xmm0
  int v5; // eax
  int v6; // ecx
  UFG::DUIRect rect; // [rsp+20h] [rbp-28h]
  UFG::DUIRect result; // [rsp+30h] [rbp-18h]

  v1 = this;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v2 = v1->mTheme.mSeperator_TopLineY;
  result.mH = v1->mTheme.mSeperator_RowH;
  v3 = v1->mTheme.mSeperator_TopLineH;
  v4 = result;
  _mm_store_si128((__m128i *)&result, (__m128i)result);
  _mm_store_si128((__m128i *)&rect, (__m128i)v4);
  result.mH = v3;
  v5 = v1->mTheme.mSeperator_BotLineH;
  result.mY = v4.mY + v2;
  v6 = v1->mTheme.mSeperator_BotLineY;
  rect.mH = v5;
  rect.mY = v4.mY + v6;
  UFG::DUIContext::RenderRoundRect(v1, &rect, &v1->mTheme.mColour[17], 0);
  UFG::DUIContext::RenderRoundRect(v1, &result, &v1->mTheme.mColour[16], 0);
}

// File Line: 3373
// RVA: 0x197B20
void __fastcall UFG::DUIContext::Empty(UFG::DUIContext *this)
{
  UFG::DUIRect result; // [rsp+20h] [rbp-18h]

  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
}

// File Line: 3411
// RVA: 0x19F480
void __fastcall UFG::DUIContext::Tooltip(UFG::DUIContext *this, const char *text, UFG::DUIRect *rect_hover)
{
  UFG::DUIRect *v3; // rdi
  const char *v4; // rsi
  UFG::DUIContext *v5; // rbx
  unsigned __int64 v6; // rax
  int v7; // edx
  int v8; // edx
  int v9; // ecx
  signed int v10; // eax
  int v11; // er8
  int v12; // er9
  int v13; // edx
  int v14; // ecx
  UFG::DUIRect v15; // xmm0
  UFG::DUIRect rect; // [rsp+30h] [rbp-30h]
  UFG::DUIRect v17; // [rsp+40h] [rbp-20h]
  UFG::DUIRect v18; // [rsp+50h] [rbp-10h]

  if ( text )
  {
    v3 = rect_hover;
    v4 = text;
    v5 = this;
    if ( *text )
    {
      this->mCurrentCompositeLayer = 1;
      UFG::DUIContext::PushLayoutState(this, &this->mRect, &this->mRect, LayoutFlag_FillLastCell);
      v6 = UFG::qGetTicks();
      if ( UFG::qGetTickTime(v5->mInputState.mLastCursorMoveTime, v6) >= 0.31999999 )
      {
        v7 = v5->mInputState.mMousePos.mX;
        if ( v7 >= v3->mX && v7 <= v3->mW + v3->mX )
        {
          v8 = v5->mInputState.mMousePos.mY;
          v9 = v3->mY;
          if ( v8 >= v9 && v8 <= v3->mH + v9 - 1 )
          {
            v10 = UFG::qStringLength(v4);
            v11 = v5->mTheme.mButton_Text.mX;
            v12 = v5->mTheme.mButton_Text.mY;
            v13 = (signed int)v5->mFontDimensions.y + 2 * v12;
            v18.mX = v5->mInputState.mMousePos.mX;
            v14 = v18.mX;
            v18.mH = v13;
            v18.mW = (signed int)(float)((float)((float)v10 + 1.0) * v5->mFontDimensions.x) + 2 * v11;
            v18.mY = v13 + v5->mInputState.mMousePos.mY - v5->mTheme.mButton_Inset.mY;
            v15 = v18;
            _mm_store_si128((__m128i *)&v17, (__m128i)v18);
            v17.mY += v12;
            _mm_store_si128((__m128i *)&rect, (__m128i)v15);
            rect.mW += 2;
            --rect.mY;
            rect.mH += 2;
            rect.mX = v14 - 1;
            v17.mX = v11 + v14;
            v17.mW -= 2 * v11;
            v17.mH -= 2 * v12;
            UFG::DUIContext::RenderRect(v5, &rect, &UFG::qColourBlack, 0);
            UFG::DUIContext::RenderRect(v5, &v18, &v5->mTheme.mColour[11], 0);
            UFG::DUIContext::RenderText(v5, &v17, &UFG::qColourWhite, v4, 0);
          }
        }
      }
      UFG::DUIContext::PopLayoutState(v5);
      v5->mCurrentCompositeLayer = 0;
    }
  }
}

// File Line: 3443
// RVA: 0x1981B0
char __fastcall UFG::EvaluateExpression(UFG::qString *expression, float *value)
{
  float *v2; // rsi
  UFG::qString *v3; // rdi
  UEL::Expression *v4; // rax
  UEL::Expression *v5; // rbx
  char result; // al
  float v7; // xmm0_4
  __int64 v8; // [rsp+38h] [rbp-30h]
  __int16 v9; // [rsp+4Ch] [rbp-1Ch]
  int v10; // [rsp+50h] [rbp-18h]

  v2 = value;
  v3 = expression;
  v4 = UEL::Expression::Compile(expression->mData);
  v5 = v4;
  if ( v4 && v4->vfptr->Resolve(v4, 0i64) )
  {
    v5->vfptr->Eval(v5, (UEL::Value *)&v8, 0i64, 0i64, 0i64);
    if ( v9 != 1 || UFG::gNullQSymbol.mUID != v10 )
      v7 = *(float *)&v8;
    else
      v7 = (float)(signed int)v8;
    *v2 = v7;
    v5->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
    operator delete[](v5);
    UFG::qString::~qString(v3);
    result = 1;
  }
  else
  {
    UFG::qString::~qString(v3);
    result = 0;
  }
  return result;
}

// File Line: 3516
// RVA: 0x19A780
__int64 __fastcall UFG::DUIContext::NumericTextBox(UFG::DUIContext *this, UFG::DUIRect *rect_val, int *val, bool show_spinners)
{
  bool v4; // bl
  int *v5; // r12
  UFG::DUIRect *v6; // rsi
  UFG::DUIContext *v7; // rdi
  bool v8; // dl
  char v9; // r13
  int v10; // er15
  int v11; // er8
  int v12; // ecx
  UFG::DUIRect v13; // xmm0
  int v14; // eax
  UFG::DUIRect v15; // xmm6
  int v16; // eax
  int v17; // ecx
  bool v18; // r14
  bool v19; // bl
  __int64 v20; // rsi
  UFG::qString *v21; // rdx
  UFG::qString *v22; // rax
  UFG::DUIContextVtbl *v23; // r8
  int v24; // edx
  int v25; // ecx
  int v26; // er9
  int v27; // ecx
  char v28; // al
  bool v29; // r10
  char v30; // r15
  int v31; // ecx
  int v32; // er9
  int v33; // ecx
  char v34; // al
  __m128i v35; // xmm6
  char v36; // bl
  UFG::qColour *v37; // r14
  int v38; // eax
  float v39; // xmm6_4
  UFG::qColour *v40; // r8
  signed int v41; // eax
  float v42; // xmm0_4
  signed int v43; // eax
  char v45; // [rsp+71h] [rbp-8Fh]
  UFG::DUIRect rect; // [rsp+80h] [rbp-80h]
  UFG::DUIRect v47; // [rsp+90h] [rbp-70h]
  UFG::DUIRect rect_space; // [rsp+A0h] [rbp-60h]
  long double value_x; // [rsp+B0h] [rbp-50h]
  UFG::qString str_val; // [rsp+B8h] [rbp-48h]
  UFG::DUIRect rect_track; // [rsp+E0h] [rbp-20h]
  UFG::qString dest; // [rsp+F0h] [rbp-10h]
  __int64 v53; // [rsp+130h] [rbp+30h]
  UFG::qString text; // [rsp+138h] [rbp+38h]
  bool v55; // [rsp+1C0h] [rbp+C0h]
  long double value_y; // [rsp+1C8h] [rbp+C8h]
  char v57; // [rsp+1D8h] [rbp+D8h]

  v57 = show_spinners;
  v53 = -2i64;
  v4 = show_spinners;
  v5 = val;
  v6 = rect_val;
  v7 = this;
  v8 = UFG::DUIContext::TakeFocus(this, rect_val, rect_val, 1);
  v55 = v8;
  rect_space = *v6;
  v9 = 0;
  *(_QWORD *)&rect.mX = 0i64;
  v10 = 0;
  LODWORD(value_x) = 0;
  rect.mW = 0;
  rect.mH = 0;
  *(_QWORD *)&v47.mX = 0i64;
  *(_QWORD *)&v47.mW = 0i64;
  if ( v4 )
  {
    v11 = v7->mTheme.mNumericButtonWidth;
    LODWORD(value_x) = v11;
    rect_space.mW -= v11;
    v12 = rect_space.mW;
    v13 = rect_space;
    _mm_store_si128((__m128i *)&rect, (__m128i)rect_space);
    rect.mX = v12 + _mm_cvtsi128_si32((__m128i)v13) + 1;
    rect.mW = v11;
    v14 = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v13, 12)) / 2;
    rect.mH = v14;
    v10 = rect.mY++ + 1;
    v15 = rect;
    _mm_store_si128((__m128i *)&v47, (__m128i)rect);
    v47.mY = v14 + v15.mY - 1;
  }
  else
  {
    v15 = rect;
  }
  v16 = v7->mCurrentID;
  v17 = v7->mFocusedID;
  v18 = v17 == v16 && v7->mBeginFrameFocusID != v16;
  v19 = v7->mPrevFocusID == v16 && v17 != v16;
  if ( v8 && UFG::DUIContext::IsMouseOver(v7, v6) == 0 && v7->mInputState.mMouseLBWentDown )
  {
    v7->mFocusedID = -1;
    v7->mFocusOffset = (UFG::DUIPoint)-1i64;
    v19 = 1;
    v55 = 0;
  }
  v45 = 0;
  LOBYTE(value_y) = 0;
  UFG::qString::qString(&str_val);
  if ( !v55 || v18 )
  {
    if ( v19 )
    {
      LOBYTE(value_y) = 1;
    }
    else
    {
      UFG::qSPrintf((char *)&dest, "%d", (unsigned int)*v5);
      UFG::qString::Set(&str_val, (const char *)&dest);
    }
  }
  else
  {
    UFG::qString::Set(&str_val, v7->mNumericBoxExpression.mData, v7->mNumericBoxExpression.mLength, 0i64, 0);
  }
  v20 = (unsigned __int8)UFG::DUIContext::InternalTextControl(v7, &rect_space, &str_val, v55);
  if ( v55 )
  {
    UFG::qString::Set(&v7->mNumericBoxExpression, str_val.mData, str_val.mLength, 0i64, 0);
    if ( !v18 )
      UFG::qString::Set(
        &v7->mPrevNumericBoxExpression,
        v7->mNumericBoxExpression.mData,
        v7->mNumericBoxExpression.mLength,
        0i64,
        0);
  }
  if ( LOBYTE(value_y) )
  {
    v21 = &v7->mPrevNumericBoxExpression;
    if ( !v19 )
      v21 = &v7->mNumericBoxExpression;
    UFG::qString::qString(&text, v21);
    LODWORD(value_y) = 0;
    *(_QWORD *)&rect_track.mX = &dest;
    UFG::qString::qString(&dest, &text);
    if ( UFG::EvaluateExpression(v22, (float *)&value_y) )
    {
      *v5 = (signed int)*(float *)&value_y;
      UFG::qSPrintf((char *)&dest, "%d");
      UFG::qString::Set(&str_val, (const char *)&dest);
      LOBYTE(v20) = 1;
    }
    else
    {
      UFG::DUIContext::Tooltip(v7, "Unable to evaluate expression.", &rect_space);
    }
    v7->mCaretPos = 0;
    v7->mHighlightStart = str_val.mLength;
    UFG::qString::~qString(&text);
  }
  if ( v57 )
  {
    v23 = (&v7->vfptr)[2 * ((signed int)v7->mCurrentCompositeLayer + 54i64)];
    v24 = v7->mInputState.mMousePos.mX;
    v25 = (int)v23[2].UpdateUI;
    if ( v24 < v25
      || v24 > LODWORD(v23[3].UpdateUI) + v25
      || (v26 = v7->mInputState.mMousePos.mY, v27 = HIDWORD(v23[2].UpdateUI), v26 < v27)
      || v26 > HIDWORD(v23[3].UpdateUI) + v27 - 1
      || v24 < rect.mX
      || v24 > LODWORD(value_x) + rect.mX
      || v26 < v10
      || v26 > v10 + rect.mH - 1
      || (v28 = 1, v7->mInputState.mMouseEventHandled) )
    {
      v28 = 0;
    }
    v29 = v7->mInputState.mMouseLBWentUp;
    v30 = v28 & v29;
    v31 = (int)v23[2].UpdateUI;
    if ( v24 < v31
      || v24 > LODWORD(v23[3].UpdateUI) + v31
      || (v32 = v7->mInputState.mMousePos.mY, v33 = HIDWORD(v23[2].UpdateUI), v32 < v33)
      || v32 > HIDWORD(v23[3].UpdateUI) + v33 - 1
      || v24 < v47.mX
      || v24 > v47.mW + v47.mX
      || v32 < v47.mY
      || v32 > v47.mH + v47.mY - 1
      || (v34 = 1, v7->mInputState.mMouseEventHandled) )
    {
      v34 = 0;
    }
    v57 = v34 & v29;
    _mm_store_si128((__m128i *)&rect_track, (__m128i)v15);
    v35 = _mm_srli_si128((__m128i)v15, 8);
    rect_track.mH = 2 * v35.m128i_i32[1];
    *(_QWORD *)&rect_space.mX = 0i64;
    *(_QWORD *)&rect_space.mW = 0i64;
    value_y = 0.0;
    value_x = 0.0;
    v36 = UFG::DUIContext::Draggable2D(
            v7,
            &value_x,
            &value_y,
            &rect_space,
            &rect_track,
            0.0,
            0.0,
            0.0,
            1.0,
            1.0,
            1.0 / (double)(2 * v35.m128i_i32[1]) * (double)rect_track.mW,
            rect_track.mW,
            rect_track.mW,
            0);
    *v5 = UFG::qToInt32(str_val.mData, 0);
    v37 = &UFG::qColourWhite;
    if ( v36 )
    {
      v38 = v7->mInputState.mMousePosDelta.mY;
      if ( v38 )
      {
        v39 = (float)-v38 * v7->mTheme.mDeltaPerPixel;
        *v5 = (signed int)(float)((float)(signed int)UFG::qToInt32(str_val.mData, 0) + v39);
        LOBYTE(v20) = 1;
        if ( v39 <= 0.0 )
        {
          v9 = 0;
          if ( v39 < 0.0 )
            v9 = 1;
        }
        else
        {
          v45 = 1;
        }
        UFG::qSPrintf((char *)&dest, "%d");
        UFG::qString::Set(&str_val, (const char *)&dest);
        if ( v45 )
        {
          v40 = &v7->mTheme.mColour[12];
LABEL_66:
          UFG::DUIContext::RenderRect(v7, &rect, v40, 0x7EF7433u);
          if ( v9 )
            v37 = &v7->mTheme.mColour[12];
          UFG::DUIContext::RenderRect(v7, &v47, v37, 0xEDF7E02F);
          goto LABEL_69;
        }
LABEL_65:
        v40 = &UFG::qColourWhite;
        goto LABEL_66;
      }
    }
    if ( v30 )
    {
      v41 = UFG::qToInt32(str_val.mData, 0);
      *v5 = v41;
      v42 = (float)v41 + v7->mTheme.mDeltaPerPixel;
    }
    else
    {
      if ( !v57 )
        goto LABEL_65;
      v43 = UFG::qToInt32(str_val.mData, 0);
      *v5 = v43;
      v42 = (float)v43 - v7->mTheme.mDeltaPerPixel;
    }
    LOBYTE(v20) = 1;
    *v5 = (signed int)v42;
    UFG::qSPrintf((char *)&dest, "%d");
    UFG::qString::Set(&str_val, (const char *)&dest);
    v7->mInputState.mMouseWheelDelta = 0;
    *(_QWORD *)&v7->mInputState.mMouseLBWentDown = 0i64;
    *(_WORD *)&v7->mInputState.mLMBDoubleClick = 0;
    v7->mInputState.mMouseMBWentUp = 0;
    v7->mInputState.mMMBDoubleClick = 0;
    v7->mInputState.mMouseEventHandled = 1;
    goto LABEL_65;
  }
LABEL_69:
  if ( (_BYTE)v20 && v55 )
    UFG::qString::Set(&v7->mNumericBoxExpression, str_val.mData);
  UFG::qString::~qString(&str_val);
  return (unsigned __int8)v20;
}7->mInputState.mMMBDoubleClick = 0;
    v7->mInputState.mMouseEventHandled = 1;
    goto LABEL_65;
  }
LABEL_69:
  if ( (_BYTE)v20 && v55 )
    UFG::qString::Set(&v7->mNumericBoxExpression, str_val.mData);
  UFG::qS

// File Line: 3682
// RVA: 0x19B690
bool __fastcall UFG::DUIContext::NumericTextBox(UFG::DUIContext *this, const char *label, float *val, bool show_spinners, float label_proportion)
{
  bool v5; // bp
  float *v6; // r14
  const char *v7; // rsi
  UFG::DUIContext *v8; // rbx
  float v10; // xmm6_4
  unsigned int flags; // edi
  int v12; // ecx
  UFG::DUIRect v13; // xmm2
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::DUIRect result; // [rsp+30h] [rbp-48h]
  UFG::DUIRect scissor_rect; // [rsp+40h] [rbp-38h]

  v5 = show_spinners;
  v6 = val;
  v7 = label;
  v8 = this;
  if ( !label )
    return 0;
  v10 = label_proportion;
  flags = 16;
  if ( label_proportion >= 0.0 )
    flags = 20;
  else
    v10 = FLOAT_0_5;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  result.mX += 4;
  v12 = result.mW - 4;
  result.mW -= 4;
  v13 = result;
  _mm_store_si128((__m128i *)&scissor_rect, (__m128i)result);
  if ( v10 <= 0.0 )
  {
    v10 = 0.0;
  }
  else
  {
    v14 = *(float *)&FLOAT_1_0;
    if ( v10 >= 1.0 )
      goto LABEL_11;
  }
  v14 = v10;
LABEL_11:
  _mm_store_si128((__m128i *)&result, (__m128i)v13);
  v15 = (float)v12 * v14;
  result.mX += (signed int)v15;
  scissor_rect.mW = (signed int)v15;
  result.mW = v12 - (signed int)v15;
  UFG::DUIContext::PushScissor(v8, &scissor_rect);
  UFG::DUIContext::RenderText(v8, &scissor_rect, v8->mTheme.mColour, v7, flags);
  UFG::DUIContext::PopScissor(v8);
  return UFG::DUIContext::NumericTextBox(v8, &result, v6, v5);
}

// File Line: 3713
// RVA: 0x19AE30
__int64 __fastcall UFG::DUIContext::NumericTextBox(UFG::DUIContext *this, UFG::DUIRect *rect_val, float *val, bool show_spinners)
{
  bool v4; // di
  float *v5; // r12
  UFG::DUIRect *v6; // rsi
  UFG::DUIContext *v7; // rbx
  char v8; // dl
  int v9; // er13
  int v10; // er15
  int v11; // er8
  int v12; // ecx
  __m128i v13; // xmm0
  int v14; // eax
  __m128i v15; // xmm8
  int v16; // eax
  int v17; // ecx
  bool v18; // r14
  bool v19; // di
  char v20; // si
  __int64 v21; // r12
  UFG::qString *v22; // rdx
  UFG::qString *v23; // rax
  float *v24; // rdi
  float v25; // xmm6_4
  float v26; // xmm0_4
  UFG::DUIContextVtbl *v27; // r8
  int v28; // edx
  int v29; // ecx
  int v30; // er9
  int v31; // ecx
  int v32; // edi
  int v33; // ecx
  int v34; // er9
  int v35; // ecx
  int v36; // esi
  int v37; // er14
  int v38; // er10
  int v39; // ecx
  int v40; // er9
  int v41; // ecx
  bool v42; // r15
  int v43; // ecx
  int v44; // er9
  int v45; // ecx
  bool v46; // r14
  __m128i v47; // xmm8
  char v48; // r13
  char v49; // di
  unsigned __int64 v50; // rax
  float v51; // xmm6_4
  float v52; // xmm0_4
  float *v53; // rcx
  UFG::qColour *v54; // rsi
  int v55; // eax
  float v56; // xmm2_4
  BOOL v57; // eax
  UFG::qColour *v58; // r8
  float v59; // xmm0_4
  long double value_max_y[2]; // [rsp+40h] [rbp-80h]
  long double grip_ph[2]; // [rsp+50h] [rbp-70h]
  long double value_y; // [rsp+60h] [rbp-60h]
  bool quantize_value[4]; // [rsp+68h] [rbp-58h]
  char rect_space[24]; // [rsp+70h] [rbp-50h]
  UFG::qString str_val; // [rsp+88h] [rbp-38h]
  UFG::DUIRect rect_track; // [rsp+B0h] [rbp-10h]
  UFG::qString dest; // [rsp+C0h] [rbp+0h]
  __int64 v69; // [rsp+100h] [rbp+40h]
  UFG::qString text; // [rsp+108h] [rbp+48h]
  char v71; // [rsp+1B0h] [rbp+F0h]
  float v72[2]; // [rsp+1B8h] [rbp+F8h]
  float *v73; // [rsp+1C0h] [rbp+100h]
  char v74; // [rsp+1C8h] [rbp+108h]

  v69 = -2i64;
  v4 = show_spinners;
  v5 = val;
  v6 = rect_val;
  v7 = this;
  v8 = UFG::DUIContext::TakeFocus(this, rect_val, rect_val, 1);
  v71 = v8;
  *(UFG::DUIRect *)rect_space = *v6;
  v9 = 0;
  grip_ph[0] = 0.0;
  v10 = 0;
  LODWORD(value_y) = 0;
  grip_ph[1] = 0.0;
  value_max_y[0] = 0.0;
  value_max_y[1] = 0.0;
  if ( v4 )
  {
    v11 = v7->mTheme.mNumericButtonWidth;
    LODWORD(value_y) = v11;
    *(_DWORD *)&rect_space[8] -= v11;
    v12 = *(_DWORD *)&rect_space[8];
    v13 = *(__m128i *)rect_space;
    _mm_store_si128((__m128i *)grip_ph, *(__m128i *)rect_space);
    v9 = v12 + _mm_cvtsi128_si32(v13) + 1;
    LODWORD(grip_ph[0]) = v9;
    LODWORD(grip_ph[1]) = v11;
    v14 = _mm_cvtsi128_si32(_mm_srli_si128(v13, 12)) / 2;
    HIDWORD(grip_ph[1]) = v14;
    v10 = HIDWORD(grip_ph[0])++ + 1;
    v15 = *(__m128i *)grip_ph;
    _mm_store_si128((__m128i *)value_max_y, *(__m128i *)grip_ph);
    HIDWORD(value_max_y[0]) = v14 + v15.m128i_i32[1] - 1;
    v8 = v71;
  }
  else
  {
    v15 = *(__m128i *)grip_ph;
  }
  v16 = v7->mCurrentID;
  v17 = v7->mFocusedID;
  v18 = v17 == v16 && v7->mBeginFrameFocusID != v16;
  v19 = v7->mPrevFocusID == v16 && v17 != v16;
  if ( v8 && UFG::DUIContext::IsMouseOver(v7, v6) == 0 && v7->mInputState.mMouseLBWentDown )
  {
    v7->mFocusedID = -1;
    v7->mFocusOffset = (UFG::DUIPoint)-1i64;
    v19 = 1;
    v20 = 0;
    v71 = 0;
  }
  else
  {
    v20 = v71;
  }
  rect_space[0] = 0;
  quantize_value[0] = 0;
  LOBYTE(v72[0]) = 0;
  UFG::qString::qString(&str_val);
  if ( !v20 || v18 )
  {
    if ( v19 )
    {
      LOBYTE(v72[0]) = 1;
    }
    else
    {
      UFG::qSPrintf((char *)&dest, "%f", *v5);
      UFG::qString::Set(&str_val, (const char *)&dest);
    }
  }
  else
  {
    UFG::qString::Set(&str_val, v7->mNumericBoxExpression.mData, v7->mNumericBoxExpression.mLength, 0i64, 0);
  }
  v21 = (unsigned __int8)UFG::DUIContext::InternalTextControl(v7, (UFG::DUIRect *)rect_space, &str_val, v20);
  if ( v20 )
  {
    UFG::qString::Set(&v7->mNumericBoxExpression, str_val.mData, str_val.mLength, 0i64, 0);
    if ( !v18 )
      UFG::qString::Set(
        &v7->mPrevNumericBoxExpression,
        v7->mNumericBoxExpression.mData,
        v7->mNumericBoxExpression.mLength,
        0i64,
        0);
  }
  if ( LOBYTE(v72[0]) )
  {
    v22 = &v7->mPrevNumericBoxExpression;
    if ( !v19 )
      v22 = &v7->mNumericBoxExpression;
    UFG::qString::qString(&text, v22);
    v72[0] = 0.0;
    *(_QWORD *)&rect_space[16] = &dest;
    UFG::qString::qString(&dest, &text);
    if ( UFG::EvaluateExpression(v23, v72) )
    {
      v24 = v73;
      v25 = *v73;
      v26 = v72[0];
      *v73 = v72[0];
      UFG::qSPrintf((char *)&dest, "%0.5f", v26);
      UFG::qString::Set(&str_val, (const char *)&dest);
      LOBYTE(v21) = v25 != *v24;
    }
    else
    {
      UFG::DUIContext::Tooltip(v7, "Unable to evaluate expression.", (UFG::DUIRect *)rect_space);
    }
    v7->mCaretPos = 0;
    v7->mHighlightStart = str_val.mLength;
    UFG::qString::~qString(&text);
  }
  if ( v74 )
  {
    v27 = (&v7->vfptr)[2 * ((signed int)v7->mCurrentCompositeLayer + 54i64)];
    v28 = v7->mInputState.mMousePos.mX;
    v29 = (int)v27[2].UpdateUI;
    if ( v28 < v29
      || v28 > LODWORD(v27[3].UpdateUI) + v29
      || (v30 = v7->mInputState.mMousePos.mY, v31 = HIDWORD(v27[2].UpdateUI), v30 < v31)
      || v30 > HIDWORD(v27[3].UpdateUI) + v31 - 1 )
    {
      v32 = HIDWORD(grip_ph[1]);
    }
    else
    {
      v32 = HIDWORD(grip_ph[1]);
      if ( v28 >= v9
        && v28 <= LODWORD(value_y) + v9
        && v30 >= v10
        && v30 <= v10 + HIDWORD(grip_ph[1]) - 1
        && !v7->mInputState.mMouseEventHandled
        && v7->mInputState.mMouseLBWentUp )
      {
        v74 = 1;
LABEL_46:
        v33 = (int)v27[2].UpdateUI;
        if ( v28 < v33 || v28 > LODWORD(v27[3].UpdateUI) + v33 )
        {
          v37 = LODWORD(value_max_y[1]);
          v36 = LODWORD(value_max_y[0]);
        }
        else
        {
          v34 = v7->mInputState.mMousePos.mY;
          v35 = HIDWORD(v27[2].UpdateUI);
          v36 = LODWORD(value_max_y[0]);
          v37 = LODWORD(value_max_y[1]);
          if ( v34 >= v35 && v34 <= HIDWORD(v27[3].UpdateUI) + v35 - 1 )
          {
            v38 = HIDWORD(value_max_y[0]);
            if ( v28 >= SLODWORD(value_max_y[0])
              && v28 <= LODWORD(value_max_y[1]) + LODWORD(value_max_y[0])
              && v34 >= SHIDWORD(value_max_y[0])
              && v34 <= HIDWORD(value_max_y[0]) + HIDWORD(value_max_y[1]) - 1
              && !v7->mInputState.mMouseEventHandled
              && v7->mInputState.mMouseLBWentUp )
            {
              LOBYTE(v72[0]) = 1;
LABEL_60:
              v39 = (int)v27[2].UpdateUI;
              v42 = 0;
              if ( v28 >= v39 && v28 <= LODWORD(v27[3].UpdateUI) + v39 )
              {
                v40 = v7->mInputState.mMousePos.mY;
                v41 = HIDWORD(v27[2].UpdateUI);
                if ( v40 >= v41
                  && v40 <= HIDWORD(v27[3].UpdateUI) + v41 - 1
                  && v28 >= v9
                  && v28 <= LODWORD(value_y) + v9
                  && v40 >= v10
                  && v40 <= v10 + v32 - 1
                  && !v7->mInputState.mMouseEventHandled
                  && v7->mInputState.mMouseLBIsDown )
                {
                  v42 = 1;
                }
              }
              v43 = (int)v27[2].UpdateUI;
              v46 = 0;
              if ( v28 >= v43 && v28 <= LODWORD(v27[3].UpdateUI) + v43 )
              {
                v44 = v7->mInputState.mMousePos.mY;
                v45 = HIDWORD(v27[2].UpdateUI);
                if ( v44 >= v45
                  && v44 <= HIDWORD(v27[3].UpdateUI) + v45 - 1
                  && v28 >= v36
                  && v28 <= v37 + v36
                  && v44 >= v38
                  && v44 <= v38 + HIDWORD(value_max_y[1]) - 1
                  && !v7->mInputState.mMouseEventHandled
                  && v7->mInputState.mMouseLBIsDown )
                {
                  v46 = 1;
                }
              }
              _mm_store_si128((__m128i *)&rect_track, v15);
              v47 = _mm_srli_si128(v15, 8);
              rect_track.mH = 2 * v47.m128i_i32[1];
              *(_QWORD *)rect_space = 0i64;
              *(_OWORD *)&rect_space[8] = 0ui64;
              grip_ph[0] = 1.0 / (double)(2 * v47.m128i_i32[1]) * (double)rect_track.mW;
              v48 = UFG::DUIContext::Draggable2D(
                      v7,
                      (long double *)&rect_space[16],
                      &value_y,
                      (UFG::DUIRect *)rect_space,
                      &rect_track,
                      0.0,
                      0.0,
                      0.0,
                      1.0,
                      1.0,
                      grip_ph[0],
                      rect_track.mW,
                      rect_track.mW,
                      0);
              if ( (v46 || v42) && !v7->mSpinner_start_press )
                v7->mSpinner_start_press = UFG::qGetTicks();
              v49 = 0;
              if ( v46 || v42 )
              {
                if ( v7->mSpinner_start_press )
                {
                  v50 = UFG::qGetTicks();
                  v49 = 0;
                  if ( UFG::qGetTickTime(v7->mSpinner_start_press, v50) > 0.2 )
                    v49 = 1;
                }
              }
              v51 = v7->mTheme.mDeltaPerPixel;
              v52 = UFG::qToFloat(str_val.mData, 0.0);
              v53 = v73;
              *v73 = v52;
              if ( v52 >= 10.0 || v52 <= -10.0 )
              {
                if ( v52 < 100.0 && v52 > -100.0 )
                  v51 = v51 * 0.1;
              }
              else
              {
                v51 = v51 * 0.0099999998;
              }
              v54 = &UFG::qColourWhite;
              if ( v74 || v49 && v42 )
              {
                v59 = v52 + v51;
              }
              else
              {
                if ( !LOBYTE(v72[0]) && (!v49 || !v46) )
                {
                  if ( v48 )
                  {
                    v55 = v7->mInputState.mMousePosDelta.mY;
                    if ( v55 )
                    {
                      v56 = (float)-v55;
                      *v53 = (float)(v56 * v51) + v52;
                      LOBYTE(v21) = 1;
                      if ( v56 <= 0.0 )
                      {
                        v57 = quantize_value[0];
                        if ( v56 < 0.0 )
                          v57 = 1;
                        *(_DWORD *)quantize_value = v57;
                      }
                      else
                      {
                        rect_space[0] = 1;
                      }
                      UFG::qSPrintf((char *)&dest, "%f", v56);
                      UFG::qString::Set(&str_val, (const char *)&dest);
                      v7->mSpinner_start_press = 0i64;
                      if ( rect_space[0] )
                      {
                        v58 = &v7->mTheme.mColour[12];
LABEL_119:
                        UFG::DUIContext::RenderRect(v7, (UFG::DUIRect *)grip_ph, v58, 0x7EF7433u);
                        if ( quantize_value[0] )
                          v54 = &v7->mTheme.mColour[12];
                        UFG::DUIContext::RenderRect(v7, (UFG::DUIRect *)value_max_y, v54, 0xEDF7E02F);
                        goto LABEL_122;
                      }
                    }
                  }
LABEL_118:
                  v58 = &UFG::qColourWhite;
                  goto LABEL_119;
                }
                v59 = v52 - v51;
              }
              *v53 = v59;
              LOBYTE(v21) = 1;
              UFG::qSPrintf((char *)&dest, "%f", v59);
              UFG::qString::Set(&str_val, (const char *)&dest);
              v7->mInputState.mMouseWheelDelta = 0;
              *(_QWORD *)&v7->mInputState.mMouseLBWentDown = 0i64;
              *(_WORD *)&v7->mInputState.mLMBDoubleClick = 0;
              v7->mInputState.mMouseMBWentUp = 0;
              v7->mInputState.mMMBDoubleClick = 0;
              v7->mInputState.mMouseEventHandled = 1;
              if ( !v49 )
                v7->mSpinner_start_press = 0i64;
              goto LABEL_118;
            }
LABEL_59:
            LOBYTE(v72[0]) = 0;
            goto LABEL_60;
          }
        }
        v38 = HIDWORD(value_max_y[0]);
        goto LABEL_59;
      }
    }
    v74 = 0;
    goto LABEL_46;
  }
LABEL_122:
  if ( (_BYTE)v21 && v71 )
    UFG::qString::Set(&v7->mNumericBoxExpression, str_val.mData);
  UFG::qString::~qString(&str_val);
  return (unsigned __int8)v21;
}

// File Line: 3906
// RVA: 0x19F240
__int64 __fastcall UFG::DUIContext::TextBox(UFG::DUIContext *this, UFG::qString *current_value, const char *placeholderText, bool is_valid, const char **suggestions, unsigned int count)
{
  UFG::qString *v6; // rsi
  bool v7; // bl
  const char *v8; // rdi
  UFG::DUIContext *v9; // rbp
  UFG::DUIRect result; // [rsp+40h] [rbp-18h]

  v6 = current_value;
  v7 = is_valid;
  v8 = placeholderText;
  v9 = this;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  return UFG::DUIContext::TextBox(v9, &result, v6, v8, v7, suggestions, count);
}

// File Line: 3914
// RVA: 0x19EC80
__int64 __fastcall UFG::DUIContext::TextBox(UFG::DUIContext *this, UFG::DUIRect *rect, UFG::qString *current_value, const char *placeholderText, bool is_valid, const char **suggestions, unsigned int count)
{
  UFG::qString *v7; // r13
  UFG::DUIRect *v8; // r15
  UFG::DUIContext *v9; // rbx
  bool v10; // r14
  unsigned __int8 v11; // r12
  const char **v12; // rsi
  signed int v13; // edi
  const char **v14; // rax
  __int64 v15; // rax
  int v16; // eax
  __int64 v17; // r14
  __int64 v18; // rax
  int v19; // edi
  char v20; // r12
  __int64 v21; // r15
  int v22; // ecx
  int v23; // edx
  int v24; // er10
  int v25; // er9
  int v26; // er10
  int v27; // er11
  __int64 v28; // rax
  UFG::DUIContextVtbl *v29; // r8
  int v30; // ecx
  int v31; // ecx
  int v32; // edx
  bool v33; // zf
  int v34; // er9
  UFG::DUIContextVtbl *v35; // rdx
  int v36; // ecx
  int v37; // ecx
  int v38; // er8
  int v39; // er11
  int v40; // esi
  int v41; // er10
  int v42; // edi
  int v43; // edx
  UFG::DUIContextVtbl *v44; // r8
  int v45; // ecx
  int v46; // er9
  int v47; // ecx
  int v48; // ecx
  int v49; // ecx
  int v50; // er9
  int v51; // ecx
  bool v53; // [rsp+40h] [rbp-41h]
  unsigned __int8 v54; // [rsp+41h] [rbp-40h]
  __int64 v55; // [rsp+50h] [rbp-31h]
  __m128i v56; // [rsp+60h] [rbp-21h]
  UFG::DUIRect recta; // [rsp+70h] [rbp-11h]
  __m128i v58; // [rsp+80h] [rbp-1h]
  UFG::DUIRect v59; // [rsp+90h] [rbp+Fh]
  UFG::DUIRect *v60; // [rsp+D8h] [rbp+57h]
  const char **suggestionsa; // [rsp+F8h] [rbp+77h]

  v60 = rect;
  v7 = current_value;
  v8 = rect;
  v9 = this;
  v10 = UFG::DUIContext::TakeFocus(this, rect, rect, 1);
  v53 = 0;
  v11 = UFG::DUIContext::InternalTextControl(v9, v8, v7, v10);
  v54 = v11;
  if ( v53 )
  {
    v9->mCaretPos = 0;
    v9->mHighlightStart = v7->mLength;
  }
  v12 = suggestions;
  if ( suggestions )
    ++v9->mCurrentPopupID;
  if ( v10 )
  {
    if ( !UFG::DUIContext::IsMouseOver(v9, v8) && v9->mInputState.mMouseLBWentDown )
    {
      if ( !suggestions )
        return v11;
      if ( v9->mCurrentPopupID != v9->mActivePopupID )
      {
        v9->mFocusedID = -1;
        v9->mFocusOffset = (UFG::DUIPoint)-1i64;
        v10 = 0;
      }
    }
  }
  else
  {
    if ( !suggestions )
      return v11;
    if ( v9->mCurrentPopupID == v9->mActivePopupID )
      v9->mActivePopupID = -1;
  }
  if ( suggestions )
  {
    v13 = 0;
    if ( count == -1 )
    {
      if ( *suggestions )
      {
        v14 = suggestions;
        do
        {
          ++v14;
          ++v13;
        }
        while ( *v14 );
      }
    }
    else
    {
      v13 = count;
    }
    if ( v10 )
    {
      recta = *v8;
      recta.mX -= 2;
      v15 = (unsigned int)(v8->mH + recta.mY);
      v9->mCurrentCompositeLayer = 1;
      v55 = v15;
      recta.mY = v15;
      recta.mW += 4;
      suggestionsa = (const char **)(unsigned int)(v13 * recta.mH + 2);
      recta.mH = v13 * recta.mH + 2;
      v9->mActivePopupID = v9->mCurrentPopupID;
      UFG::DUIContext::PushLayoutState(v9, &v9->mRect, &v9->mRect, LayoutFlag_FillLastCell);
      UFG::DUIContext::RenderRect(v9, &recta, &v9->mTheme.mColour[5], 0);
      v16 = v9->mTheme.mRowHeight;
      v17 = 0i64;
      _mm_store_si128(&v58, (__m128i)recta);
      v58.m128i_i32[3] = v16;
      v18 = v13;
      if ( v13 > 0 )
      {
        v19 = v58.m128i_i32[1];
        v20 = 0;
        v21 = v18;
        do
        {
          v22 = v9->mTheme.mButton_Text.mX;
          v23 = v9->mTheme.mButton_Text.mY;
          v24 = v58.m128i_i32[0];
          v19 += v9->mTheme.mRowHeight;
          v25 = v9->mInputState.mMousePos.mX;
          _mm_store_si128(&v56, v58);
          v56.m128i_i32[1] += v23;
          v26 = v22 + v24;
          v56.m128i_i32[0] = v26;
          v27 = v56.m128i_i32[2] - 2 * v22;
          v58.m128i_i32[1] = v19;
          v28 = v9->mCurrentCompositeLayer;
          v56.m128i_i32[2] -= 2 * v22;
          v56.m128i_i32[3] -= 2 * v23;
          _mm_store_si128((__m128i *)&v59, v56);
          v29 = (&v9->vfptr)[2 * (v28 + 54)];
          v30 = (int)v29[2].UpdateUI;
          if ( v25 >= v30 && v25 <= LODWORD(v29[3].UpdateUI) + v30 )
          {
            v31 = HIDWORD(v29[2].UpdateUI);
            v32 = v9->mInputState.mMousePos.mY;
            if ( v32 >= v31
              && v32 <= HIDWORD(v29[3].UpdateUI) + v31 - 1
              && v25 >= v26
              && v25 <= v27 + v26
              && v32 >= v56.m128i_i32[1]
              && v32 <= v56.m128i_i32[1] + v56.m128i_i32[3] - 1
              && !v9->mInputState.mMouseEventHandled )
            {
              if ( v9->mInputState.mMouseLBWentDown )
              {
                UFG::qString::Set(v7, v12[v17]);
                v9->mInputState.mMouseWheelDelta = 0;
                *(_QWORD *)&v9->mInputState.mMouseLBWentDown = 0i64;
                *(_WORD *)&v9->mInputState.mLMBDoubleClick = 0;
                v9->mInputState.mMouseMBWentUp = 0;
                v9->mInputState.mMMBDoubleClick = 0;
                v9->mActivePopupID = -1;
                v9->mFocusedID = -1;
                v9->mFocusOffset = (UFG::DUIPoint)-1i64;
                v20 = 1;
              }
              UFG::DUIContext::RenderRoundRect(v9, &v59, &v9->mTheme.mColour[12], 0);
            }
          }
          UFG::DUIContext::RenderText(v9, &v59, &UFG::qColourWhite, v12[v17++], 0);
        }
        while ( v17 < v21 );
        v8 = v60;
        v33 = v20 == 0;
        v11 = v54;
        if ( !v33 )
          goto LABEL_75;
      }
      v34 = v9->mInputState.mMousePos.mX;
      v35 = (&v9->vfptr)[2 * ((signed int)v9->mCurrentCompositeLayer + 54i64)];
      v36 = (int)v35[2].UpdateUI;
      if ( v34 >= v36 && v34 <= LODWORD(v35[3].UpdateUI) + v36 )
      {
        v37 = HIDWORD(v35[2].UpdateUI);
        v38 = v9->mInputState.mMousePos.mY;
        v39 = recta.mX;
        v40 = recta.mW;
        if ( v38 >= v37 && v38 <= HIDWORD(v35[3].UpdateUI) + v37 - 1 )
        {
          v41 = v55;
          v42 = (signed int)suggestionsa;
          if ( v34 >= recta.mX
            && v34 <= recta.mW + recta.mX
            && v38 >= (signed int)v55
            && v38 <= (signed int)suggestionsa + (signed int)v55 - 1
            && !v9->mInputState.mMouseEventHandled )
          {
            if ( !v9->mInputState.mMouseLBWentDown )
            {
LABEL_71:
              UFG::DUIContext::PopLayoutState(v9);
              v9->mCurrentCompositeLayer = 0;
              return v11;
            }
            v9->mInputState.mMouseWheelDelta = 0;
            *(_QWORD *)&v9->mInputState.mMouseLBWentDown = 0i64;
            *(_WORD *)&v9->mInputState.mLMBDoubleClick = 0;
            v9->mInputState.mMouseMBWentUp = 0;
            v9->mInputState.mMMBDoubleClick = 0;
          }
LABEL_51:
          if ( v9->mInputState.mMouseLBWentDown )
          {
            v43 = v9->mInputState.mMousePos.mX;
            v44 = (&v9->vfptr)[2 * ((signed int)v9->mCurrentCompositeLayer + 54i64)];
            v45 = (int)v44[2].UpdateUI;
            if ( v43 < v45
              || v43 > LODWORD(v44[3].UpdateUI) + v45
              || (v46 = v9->mInputState.mMousePos.mY, v47 = HIDWORD(v44[2].UpdateUI), v46 < v47)
              || v46 > HIDWORD(v44[3].UpdateUI) + v47 - 1
              || v43 < v39
              || v43 > v40 + v39
              || v46 < v41
              || v46 > v42 + v41 - 1
              || v9->mInputState.mMouseEventHandled )
            {
              v48 = (int)v44[2].UpdateUI;
              if ( v43 < v48
                || v43 > LODWORD(v44[3].UpdateUI) + v48
                || (v49 = HIDWORD(v44[2].UpdateUI), v50 = v9->mInputState.mMousePos.mY, v50 < v49)
                || v50 > HIDWORD(v44[3].UpdateUI) + v49 - 1
                || v43 < v8->mX
                || v43 > v8->mW + v8->mX
                || (v51 = v8->mY, v50 < v51)
                || v50 > v8->mH + v51 - 1
                || v9->mInputState.mMouseEventHandled )
              {
                v9->mActivePopupID = -1;
                v9->mInputState.mMouseWheelDelta = 0;
                *(_QWORD *)&v9->mInputState.mMouseLBWentDown = 0i64;
                *(_WORD *)&v9->mInputState.mLMBDoubleClick = 0;
                v9->mInputState.mMouseMBWentUp = 0;
                v9->mInputState.mMMBDoubleClick = 0;
                v9->mFocusedID = -1;
                v9->mFocusOffset = (UFG::DUIPoint)-1i64;
              }
            }
          }
          goto LABEL_71;
        }
      }
      else
      {
LABEL_75:
        v40 = recta.mW;
        v39 = recta.mX;
      }
      v41 = v55;
      v42 = (signed int)suggestionsa;
      goto LABEL_51;
    }
  }
  return v11;
}

// File Line: 4021
// RVA: 0x199500
__int64 __fastcall UFG::DUIContext::InternalTextControl(UFG::DUIContext *this, UFG::DUIRect *rect_space, UFG::qString *str_val, bool in_focus)
{
  UFG::DUIContext *v4; // rsi
  UFG::DUIRect v5; // xmm0
  int v6; // er11
  int v7; // er10
  signed int v8; // ebx
  int v9; // er15
  __m128i v10; // xmm0
  __m128i v11; // xmm0
  int v12; // edx
  int v13; // ecx
  UFG::DUIRect v14; // xmm1
  int v15; // er10
  int v16; // eax
  __m128i v17; // xmm0
  unsigned __int8 v18; // r12
  unsigned __int64 v19; // rdi
  UFG::DUIContextVtbl *v20; // r9
  int v21; // er8
  int v22; // ecx
  int v23; // edx
  int v24; // ecx
  char v25; // r13
  char v26; // r12
  signed __int64 v27; // r11
  UFG::DUIContextVtbl *v28; // r8
  int v29; // er9
  int v30; // ecx
  int v31; // edx
  int v32; // ecx
  bool v33; // r13
  bool v34; // r9
  int v35; // edx
  int *v36; // r14
  int v37; // eax
  int *v38; // r15
  int v39; // eax
  int v40; // ecx
  UFG::DUIContextVtbl *v41; // r9
  int v42; // er10
  int v43; // ecx
  int v44; // er8
  int v45; // ecx
  unsigned __int64 v46; // rdi
  char v47; // al
  int v48; // eax
  char v49; // di
  char v50; // bl
  unsigned __int8 v51; // r8
  int v52; // er9
  UFG::qString *v53; // r13
  float v54; // xmm2_4
  signed int v55; // eax
  int v56; // er8
  int v57; // eax
  int v58; // edi
  int v59; // eax
  int v60; // ebx
  const char *v61; // r9
  int v62; // er10
  int v63; // eax
  unsigned __int8 v64; // bl
  UFG::qColour *v65; // r8
  float v66; // xmm1_4
  signed int v67; // ecx
  char *v68; // rbx
  float v69; // xmm1_4
  UFG::qColour *v70; // r8
  UFG::DUIRect *v71; // rdx
  char v73; // [rsp+40h] [rbp-80h]
  char v74; // [rsp+41h] [rbp-7Fh]
  char v75; // [rsp+42h] [rbp-7Eh]
  int v76; // [rsp+44h] [rbp-7Ch]
  UFG::DUIRect v77; // [rsp+50h] [rbp-70h]
  UFG::qString result; // [rsp+60h] [rbp-60h]
  UFG::DUIRect v79; // [rsp+90h] [rbp-30h]
  UFG::DUIRect scissor_rect; // [rsp+A0h] [rbp-20h]
  __int64 v81; // [rsp+B0h] [rbp-10h]
  UFG::DUIRect rect; // [rsp+C0h] [rbp+0h]
  __int64 v83; // [rsp+D0h] [rbp+10h]
  __int64 v84; // [rsp+100h] [rbp+40h]
  unsigned __int8 v85; // [rsp+130h] [rbp+70h]
  char v86; // [rsp+138h] [rbp+78h]
  UFG::qString *text; // [rsp+140h] [rbp+80h]
  unsigned __int8 v88; // [rsp+148h] [rbp+88h]
  char v89; // [rsp+150h] [rbp+90h]
  _BYTE *v90; // [rsp+158h] [rbp+98h]
  char *vars0; // [rsp+160h] [rbp+A0h]

  v81 = -2i64;
  v4 = this;
  v5 = *rect_space;
  *(UFG::DUIRect *)&result.mMagic = v5;
  v6 = this->mTheme.mButton_Inset.mY;
  v7 = this->mTheme.mButton_Inset.mX;
  v8 = v7 + _mm_cvtsi128_si32((__m128i)v5);
  result.mMagic = v8;
  v9 = v5.mW - 2 * v7;
  LODWORD(result.mData) = v5.mW - 2 * v7;
  result.mLength += v6;
  HIDWORD(result.mData) = v5.mH - 2 * v6;
  v10 = *(__m128i *)&result.mMagic;
  _mm_store_si128((__m128i *)&v84, *(__m128i *)&result.mMagic);
  _mm_store_si128((__m128i *)&v77, v10);
  v77.mX = v8 + 1;
  v77.mW -= 2;
  ++v77.mY;
  v77.mH -= 2;
  _mm_store_si128((__m128i *)&v83, (__m128i)v77);
  v11 = *(__m128i *)rect_space;
  v77 = (UFG::DUIRect)v11;
  v12 = this->mTheme.mButton_Text.mY;
  v13 = this->mTheme.mButton_Text.mX;
  v77.mX = v13 + _mm_cvtsi128_si32(v11);
  v77.mW = v11.m128i_i32[2] - 2 * v13;
  v77.mY += v12;
  v77.mH = v11.m128i_i32[3] - 2 * v12;
  v11.m128i_i32[1] = v77.mY;
  _mm_store_si128((__m128i *)&v77, (__m128i)v77);
  v77.mY = v11.m128i_i32[1] + 1;
  v14 = v77;
  _mm_store_si128((__m128i *)&scissor_rect, (__m128i)v77);
  v15 = v77.mX;
  if ( in_focus )
  {
    v16 = v4->mTextBoxOffset;
    v15 = v77.mX - v16;
    v77.mX -= v16;
    v77.mW += v16;
    v14 = v77;
  }
  _mm_store_si128((__m128i *)&v77, (__m128i)v14);
  v17 = _mm_srli_si128((__m128i)v14, 8);
  v77.mH = v17.m128i_i32[1] - 2;
  v77.mW = 1;
  _mm_store_si128((__m128i *)&result, (__m128i)v14);
  v18 = 0;
  v85 = 0;
  v19 = *(_QWORD *)&result.mMagic;
  if ( v4->mInputState.mMouseLBIsDown
    || v4->mInputState.mMouseRBIsDown
    || v4->mInputState.mMouseMBIsDown
    || (v20 = (&v4->vfptr)[2 * ((signed int)v4->mCurrentCompositeLayer + 54i64)],
        v21 = v4->mInputState.mMousePos.mX,
        v22 = (int)v20[2].UpdateUI,
        v21 < v22)
    || v21 > LODWORD(v20[3].UpdateUI) + v22
    || (v23 = v4->mInputState.mMousePos.mY, v24 = HIDWORD(v20[2].UpdateUI), v23 < v24)
    || v23 > HIDWORD(v20[3].UpdateUI) + v24 - 1
    || v21 < v8
    || v21 > v9 + v8
    || v23 < result.mLength
    || v23 > result.mLength + HIDWORD(result.mData) - 1
    || (v73 = 1, v4->mInputState.mMouseEventHandled) )
  {
    v73 = 0;
  }
  v25 = 0;
  v74 = 0;
  if ( v88 )
  {
    v26 = 0;
    v86 = 0;
    v27 = 2 * ((signed int)v4->mCurrentCompositeLayer + 54i64);
    v28 = (&v4->vfptr)[2 * ((signed int)v4->mCurrentCompositeLayer + 54i64)];
    v29 = v4->mInputState.mMousePos.mX;
    v30 = (int)v28[2].UpdateUI;
    v33 = 0;
    if ( v29 >= v30 && v29 <= LODWORD(v28[3].UpdateUI) + v30 )
    {
      v31 = v4->mInputState.mMousePos.mY;
      v32 = HIDWORD(v28[2].UpdateUI);
      if ( v31 >= v32
        && v31 <= HIDWORD(v28[3].UpdateUI) + v32 - 1
        && v29 >= v8
        && v29 <= v9 + v8
        && v31 >= result.mLength
        && v31 <= result.mLength + HIDWORD(result.mData) - 1
        && !v4->mInputState.mMouseEventHandled
        && v4->mInputState.mMouseLBWentDown )
      {
        v33 = 1;
      }
    }
    v34 = v4->mInputState.mMouseLBIsDown;
    if ( v4->mInputState.mMouseLBWentDown )
    {
      v4->mTextBoxCanDragSelect = v33;
    }
    else if ( !v34 )
    {
      v4->mTextBoxCanDragSelect = 0;
    }
    v35 = text->mLength;
    v36 = &v4->mCaretPos;
    v37 = v4->mCaretPos;
    if ( v37 >= 0 )
    {
      if ( v37 > v35 )
        *v36 = v35;
    }
    else
    {
      *v36 = 0;
    }
    v38 = &v4->mHighlightStart;
    v39 = v4->mHighlightStart;
    if ( v39 >= 0 )
    {
      if ( v39 > v35 )
        *v38 = v35;
    }
    else
    {
      *v38 = 0;
    }
    v76 = *v36;
    v40 = *v38 - *v36;
    if ( v34 && v4->mTextBoxCanDragSelect )
    {
      *v36 = (signed int)(float)((float)((float)(v4->mFontDimensions.x * 0.5)
                                       + (float)(v4->mInputState.mMousePos.mX - v15))
                               / v4->mFontDimensions.x);
      v86 = 1;
      goto LABEL_88;
    }
    if ( v4->mInputState.mLMBDoubleClick )
    {
      v41 = (&v4->vfptr)[v27];
      v42 = v4->mInputState.mMousePos.mX;
      v43 = (int)v41[2].UpdateUI;
      if ( v42 >= v43 && v42 <= LODWORD(v41[3].UpdateUI) + v43 )
      {
        v44 = v4->mInputState.mMousePos.mY;
        v45 = HIDWORD(v41[2].UpdateUI);
        if ( v44 >= v45 && v44 <= HIDWORD(v41[3].UpdateUI) + v45 - 1 && v42 >= v8 && v42 <= v8 + LODWORD(result.mData) )
        {
          v46 = v19 >> 32;
          if ( v44 >= (signed int)v46
            && v44 <= (signed int)v46 + HIDWORD(result.mData) - 1
            && !v4->mInputState.mMouseEventHandled )
          {
            *v38 = v35;
            v86 = 1;
LABEL_87:
            *v36 = 0;
            goto LABEL_88;
          }
        }
      }
      goto LABEL_88;
    }
    v47 = v4->mInputState.mKeycodeDown;
    switch ( v47 )
    {
      case 37:
        if ( v4->mInputState.mKeyIsDownControl )
          v48 = 0;
        else
          v48 = v76 - 1;
        if ( v4->mInputState.mKeyIsDownShift )
          goto LABEL_72;
        if ( *v38 != *v36 )
        {
          if ( v40 < 0 )
          {
LABEL_62:
            *v36 = *v38;
LABEL_73:
            v26 = 1;
            goto LABEL_88;
          }
LABEL_70:
          *v38 = *v36;
          goto LABEL_73;
        }
        break;
      case 39:
        if ( v4->mInputState.mKeyIsDownControl )
          v48 = v35;
        else
          v48 = v76 + 1;
        if ( v4->mInputState.mKeyIsDownShift )
          goto LABEL_72;
        if ( *v38 != *v36 )
        {
          if ( v40 >= 0 )
            goto LABEL_62;
          goto LABEL_70;
        }
        break;
      case 36:
        *v36 = 0;
        if ( !v4->mInputState.mKeyIsDownShift )
          *v38 = 0;
        v26 = 1;
        break;
      case 35:
        *v36 = v35;
        if ( !v4->mInputState.mKeyIsDownShift )
          *v38 = v35;
        v26 = 1;
        break;
      case 9:
        v4->mNavigationAction = (v4->mInputState.mKeyIsDownShift != 0) + 1;
        *v36 = 0;
        *v38 = 0x7FFFFFFF;
        v88 = 0;
        *v90 = 1;
        v26 = 1;
        goto LABEL_88;
      case 13:
      case 94:
        *v90 = 1;
        v26 = 1;
        *v38 = 0x7FFFFFFF;
        goto LABEL_87;
      default:
LABEL_88:
        v49 = 0;
        v50 = 0;
        v75 = 0;
        v51 = v4->mInputState.mChar;
        switch ( v51 )
        {
          case 3u:
            v50 = 1;
            v26 = 1;
            break;
          case 0x16u:
            v75 = 1;
            v26 = 1;
            break;
          case 0x18u:
            v49 = 1;
            v26 = 1;
            break;
        }
        if ( v4->mInputState.mKeyIsDownShift == 0 && v33 )
        {
          *v38 = *v36;
          v26 = 1;
        }
        if ( *v36 >= 0 )
        {
          if ( *v36 > v35 )
            *v36 = v35;
        }
        else
        {
          *v36 = 0;
        }
        if ( *v38 >= 0 )
        {
          if ( *v38 > v35 )
            *v38 = v35;
        }
        else
        {
          *v38 = 0;
        }
        v52 = *v38 - *v36;
        if ( ((unsigned __int8)(v51 - 32) <= 0x5Fu || v51 == 8)
          && !v4->mInputState.mKeyIsDownAlt
          && !v4->mInputState.mKeyIsDownControl
          && (!v89 || ((char)v51 < 65 || (char)v51 > 90) && ((char)v51 < 97 || (char)v51 > 122)) )
        {
          v53 = text;
          UFG::DUIContext::ApplyKeystrokes(text, &v4->mCaretPos, &v4->mHighlightStart, v51);
          v52 = UFG::DUIContext::ClampCaret(v4, v53->mLength);
          v85 = 1;
          v26 = 1;
        }
        v54 = v4->mFontDimensions.x;
        LODWORD(result.mNext) = (signed int)(float)((float)(v4->mFontDimensions.x
                                                          * COERCE_FLOAT(COERCE_UNSIGNED_INT((float)v52) & _xmm))
                                                  + 0.5);
        if ( v52 >= 0 )
        {
          if ( v52 <= 0 )
            goto LABEL_115;
          v55 = (signed int)(float)((float)*v36 * v54);
        }
        else
        {
          v55 = (signed int)(float)((float)((float)*v36 * v54) - (float)((float)(signed int)abs(v52) * v54));
        }
        v74 = 1;
        LODWORD(result.mPrev) += v55;
LABEL_115:
        if ( v76 != *v36 || UFG::qGetSystemElapsedMSecs() % 0x352 > 0x1A9 )
        {
          v25 = 1;
          v77.mX += (signed int)(float)((float)*v36 * v4->mFontDimensions.x);
        }
        else
        {
          v25 = 0;
        }
        if ( v50 )
        {
          v56 = *v36;
          v57 = abs(*v38 - *v36);
          if ( *v38 < *v36 )
            v56 = *v38;
          UFG::qString::Substring(text, &result, v56, v57);
          UFG::DUIContext::SetClipboardText(result.mData);
          UFG::qString::~qString(&result);
        }
        else if ( v49 )
        {
          v58 = *v36;
          v59 = abs(*v38 - *v36);
          if ( *v38 < *v36 )
            v58 = *v38;
          v60 = v58 + v59;
          UFG::qString::Substring(text, &result, v58, v59);
          UFG::DUIContext::SetClipboardText(result.mData);
          UFG::DUIContext::ReplaceSelection(
            text,
            v58,
            v60,
            &customWorldMapCaption,
            &v4->mHighlightStart,
            &v4->mCaretPos,
            1);
          v85 = 1;
          UFG::qString::~qString(&result);
        }
        else if ( v75 )
        {
          v61 = UFG::DUIContext::GetClipboardText();
          v62 = *v36;
          v63 = abs(*v38 - *v36);
          if ( *v38 < *v36 )
            v62 = *v38;
          UFG::DUIContext::ReplaceSelection(
            text,
            v62,
            v62 + v63,
            v61,
            &v4->mHighlightStart,
            &v4->mCaretPos,
            UFG::DUIContext::sInsertOn);
          v85 = 1;
        }
        if ( v26 )
          *(_WORD *)&v4->mInputState.mKeycodeDown = 0;
        v18 = v85;
        if ( v86 )
        {
          v4->mInputState.mMouseWheelDelta = 0;
          *(_QWORD *)&v4->mInputState.mMouseLBWentDown = 0i64;
          *(_WORD *)&v4->mInputState.mLMBDoubleClick = 0;
          v4->mInputState.mMouseMBWentUp = 0;
          v4->mInputState.mMMBDoubleClick = 0;
        }
        goto LABEL_135;
    }
    *v38 = v48;
LABEL_72:
    *v36 = v48;
    goto LABEL_73;
  }
LABEL_135:
  v64 = v88;
  v65 = &v4->mTheme.mColour[12];
  if ( !(v88 | (unsigned __int8)v73) )
    v65 = &UFG::qColourBlack;
  UFG::DUIContext::RenderRoundRect(v4, &rect, v65, 0);
  UFG::DUIContext::RenderRoundRect(v4, &v79, &v4->mTheme.mColour[11], 0);
  if ( v74 )
  {
    result.mMagic = 1065353216;
    result.mLength = 1056964608;
    LODWORD(result.mData) = 0;
    *((float *)&result.mData + 1) = FLOAT_0_25;
    UFG::DUIContext::RenderRect(v4, (UFG::DUIRect *)&result, (UFG::qColour *)&result.mMagic, 0);
  }
  if ( v64 )
  {
    v66 = v4->mFontDimensions.x;
    v67 = v4->mCaretPos;
    if ( v67 < (signed int)(float)((float)v4->mTextBoxOffset * (float)(1.0 / v66)) )
      v4->mTextBoxOffset = (signed int)(float)((float)v67 * v66);
    if ( v67 > (signed int)(float)((float)v77.mW * (float)(1.0 / v66)) )
      v4->mTextBoxOffset += (signed int)(float)((float)v67 * v66) - v77.mW;
  }
  v68 = text->mData;
  result.mPrev = *(UFG::qNode<UFG::qString,UFG::qString> **)&v4->mTheme.mColour[0].r;
  *(float *)&result.mNext = v4->mTheme.mColour[0].b;
  v69 = v4->mTheme.mColour[0].a;
  HIDWORD(result.mNext) = LODWORD(v4->mTheme.mColour[0].a);
  if ( !text->mLength )
  {
    v68 = vars0;
    *((float *)&result.mNext + 1) = v69 * 0.5;
  }
  UFG::DUIContext::PushScissor(v4, &scissor_rect);
  UFG::DUIContext::RenderText(v4, &v77, (UFG::qColour *)&result, v68, 0);
  UFG::DUIContext::PopScissor(v4);
  if ( v25 && !v74 )
  {
    if ( UFG::DUIContext::sInsertOn )
    {
      result.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)4550437062836643430i64;
      result.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)4575657222467905126i64;
      v70 = (UFG::qColour *)&result;
      v71 = &v77;
    }
    else
    {
      _mm_store_si128((__m128i *)&result, (__m128i)v77);
      *(float *)&result.mNext = v4->mFontDimensions.x;
      v77.mX = 1059481190;
      v77.mY = 1059481190;
      v77.mW = 1059481190;
      *(float *)&v77.mH = FLOAT_0_80000001;
      v70 = (UFG::qColour *)&v77;
      v71 = (UFG::DUIRect *)&result;
    }
    UFG::DUIContext::RenderRect(v4, v71, v70, 0);
  }
  return v18;
}

// File Line: 4338
// RVA: 0x195230
_BOOL8 __fastcall UFG::DUIContext::Button(UFG::DUIContext *this, const char *name, unsigned int text_alignment)
{
  UFG::DUIContext *v3; // rbx
  unsigned int flags; // er14
  const char *v5; // rsi
  signed int v6; // eax
  int v7; // ecx
  int v8; // edx
  UFG::DUIRect v9; // xmm1
  int v10; // er8
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  UFG::DUIRect v14; // xmm0
  bool v15; // r15
  UFG::qColour *v16; // r8
  bool v17; // di
  UFG::qColour *v18; // r8
  UFG::DUIRect v20; // [rsp+30h] [rbp-30h]
  UFG::DUIRect result; // [rsp+40h] [rbp-20h]
  UFG::DUIRect rect; // [rsp+50h] [rbp-10h]
  UFG::DUIContext::ClickableState click_state; // [rsp+80h] [rbp+20h]

  v3 = this;
  flags = text_alignment;
  v5 = name;
  v6 = UFG::qStringLength(name);
  UFG::DUIContext::GetLayoutRect(
    v3,
    &result,
    (signed int)(float)((float)v6 * v3->mFontDimensions.x) + 2 * v3->mTheme.mButton_Text.mX,
    0);
  v7 = v3->mTheme.mButton_Inset.mX;
  v8 = v3->mTheme.mButton_Inset.mY;
  v9 = result;
  _mm_store_si128((__m128i *)&v20, (__m128i)result);
  v10 = _mm_cvtsi128_si32((__m128i)v9);
  v20.mY += v8;
  v20.mX = v10 + v7;
  v20.mW -= 2 * v7;
  v11 = v20.mH - 2 * v8;
  v12 = v3->mTheme.mButton_Text.mY;
  v20.mH = v11;
  v13 = v3->mTheme.mButton_Text.mX;
  v14 = v20;
  _mm_store_si128((__m128i *)&v20, (__m128i)v9);
  v20.mY += v12;
  _mm_store_si128((__m128i *)&rect, (__m128i)v14);
  v20.mX = v10 + v13;
  v20.mW -= 2 * v13;
  v20.mH -= 2 * v12;
  _mm_store_si128((__m128i *)&v20, (__m128i)v20);
  UFG::DUIContext::Clickable(v3, &click_state, &result, &result, ClickableFlags_ConsumeInput);
  v15 = click_state == 3;
  v16 = &v3->mTheme.mColour[12];
  v17 = click_state == 1;
  if ( click_state != 1 )
    v16 = &v3->mTheme.mColour[11];
  UFG::DUIContext::RenderRoundRect(v3, &rect, v16, 0);
  v18 = &v3->mTheme.mColour[2];
  if ( !v17 )
    v18 = v3->mTheme.mColour;
  UFG::DUIContext::RenderText(v3, &v20, v18, v5, flags);
  return v15;
}

// File Line: 4363
// RVA: 0x19F2C0
_BOOL8 __fastcall UFG::DUIContext::ToggleButton(UFG::DUIContext *this, const char *name, bool *current_value)
{
  UFG::DUIContext *v3; // rbx
  bool *v4; // rdi
  const char *v5; // r15
  signed int v6; // eax
  int v7; // ecx
  int v8; // edx
  UFG::DUIRect v9; // xmm1
  int v10; // er8
  float v11; // ecx
  int v12; // edx
  int v13; // ecx
  UFG::qColour v14; // xmm0
  bool v15; // r14
  unsigned int flags; // esi
  UFG::qColour *v17; // r8
  float *v18; // rcx
  bool v19; // zf
  UFG::qColour colour; // [rsp+30h] [rbp-40h]
  UFG::DUIRect result; // [rsp+40h] [rbp-30h]
  UFG::DUIRect rect; // [rsp+50h] [rbp-20h]
  UFG::DUIRect v24; // [rsp+60h] [rbp-10h]
  UFG::DUIContext::ClickableState click_state; // [rsp+90h] [rbp+20h]

  v3 = this;
  v4 = current_value;
  v5 = name;
  v6 = UFG::qStringLength(name);
  UFG::DUIContext::GetLayoutRect(
    v3,
    &result,
    (signed int)(float)((float)v6 * v3->mFontDimensions.x) + 2 * v3->mTheme.mButton_Text.mX,
    0);
  v7 = v3->mTheme.mButton_Inset.mX;
  v8 = v3->mTheme.mButton_Inset.mY;
  v9 = result;
  _mm_store_si128((__m128i *)&colour, (__m128i)result);
  v10 = _mm_cvtsi128_si32((__m128i)v9);
  LODWORD(colour.g) += v8;
  LODWORD(colour.r) = v10 + v7;
  LODWORD(colour.b) -= 2 * v7;
  LODWORD(v11) = LODWORD(colour.a) - 2 * v8;
  v12 = v3->mTheme.mButton_Text.mY;
  colour.a = v11;
  v13 = v3->mTheme.mButton_Text.mX;
  v14 = colour;
  _mm_store_si128((__m128i *)&colour, (__m128i)v9);
  LODWORD(colour.g) += v12;
  _mm_store_si128((__m128i *)&rect, (__m128i)v14);
  LODWORD(colour.r) = v10 + v13;
  LODWORD(colour.b) -= 2 * v13;
  LODWORD(colour.a) -= 2 * v12;
  _mm_store_si128((__m128i *)&v24, (__m128i)colour);
  UFG::DUIContext::Clickable(v3, &click_state, &result, &result, ClickableFlags_ConsumeInput);
  v15 = click_state == 1;
  if ( click_state == 3 )
    *v4 = *v4 == 0;
  flags = 16;
  v17 = &v3->mTheme.mColour[12];
  if ( !*v4 )
    v17 = &v3->mTheme.mColour[11];
  UFG::DUIContext::RenderRoundRect(v3, &rect, v17, 0);
  v18 = (float *)v3->mTheme.mColour;
  if ( v15 )
    flags = 80;
  v19 = *v4 == 0;
  colour.r = *v18;
  colour.g = v3->mTheme.mColour[0].g;
  colour.b = v3->mTheme.mColour[0].b;
  colour.a = v3->mTheme.mColour[0].a;
  if ( !v19 )
  {
    if ( !v15 )
      v18 = &v3->mTheme.mColour[2].r;
    colour.r = *v18;
    colour.g = v18[1];
    colour.b = v18[2];
    colour.a = v18[3];
  }
  UFG::DUIContext::RenderText(v3, &v24, &colour, v5, flags);
  return *v4;
}

// File Line: 4405
// RVA: 0x196D80
bool __fastcall UFG::DUIContext::CommandButton(UFG::DUIContext *this, UFG::Command *command, UFG::CommandContext *context)
{
  UFG::CommandContext *v3; // rdi
  UFG::Command *v4; // r14
  UFG::DUIContext *v5; // rsi
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  signed __int64 v8; // rax
  UFG::allocator::free_link *v9; // rbx
  int v10; // eax
  UFG::qBaseNodeRB *v11; // rdx
  UFG::Command::State v12; // eax
  unsigned int menu_image_uid; // [rsp+60h] [rbp+8h]
  UFG::allocator::free_link *v15; // [rsp+68h] [rbp+10h]

  v3 = context;
  v4 = command;
  v5 = this;
  v6 = UFG::qStringHashUpper32("DUIContext", 0xFFFFFFFF);
  if ( v6
    && (v7 = UFG::qBaseTreeRB::Get(&v3->mDictionary.mTree, v6)) != 0i64
    && (v8 = (signed __int64)&v7[-1].mCount) != 0 )
  {
    *(_QWORD *)(v8 + 40) = v5;
  }
  else
  {
    v9 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v15 = v9;
    if ( v9 )
    {
      v10 = UFG::qStringHashUpper32("DUIContext", 0xFFFFFFFF);
      v9[1].mNext = 0i64;
      v9[2].mNext = 0i64;
      v9[3].mNext = 0i64;
      LODWORD(v9[4].mNext) = v10;
      v9->mNext = (UFG::allocator::free_link *)&UFG::ContextDataBase::`vftable;
      v9->mNext = (UFG::allocator::free_link *)&UFG::ContextData<UFG::DUIContext *>::`vftable;
      v9[5].mNext = (UFG::allocator::free_link *)v5;
    }
    else
    {
      v9 = 0i64;
    }
    v11 = (UFG::qBaseNodeRB *)&v9[1];
    if ( !v9 )
      v11 = 0i64;
    UFG::qBaseTreeRB::Add(&v3->mDictionary.mTree, v11);
  }
  menu_image_uid = 0;
  v12 = (unsigned int)v4->vfptr->GetState(v4, v3, &menu_image_uid);
  return UFG::DUIContext::CommandButton(v5, v4, v3, v12, &menu_image_uid);
}

// File Line: 4415
// RVA: 0x196E90
bool __fastcall UFG::DUIContext::CommandButton(UFG::DUIContext *this, UFG::Command *command, UFG::CommandContext *context, UFG::Command::State state)
{
  UFG::Command::State v4; // er15
  UFG::CommandContext *v5; // r14
  UFG::Command *v6; // rsi
  UFG::DUIContext *v7; // rbx
  unsigned int v9; // eax
  UFG::qBaseTreeRB *v10; // rax
  signed __int64 v11; // rax
  UFG::allocator::free_link *v12; // rdi
  int v13; // eax
  UFG::qBaseNodeRB *v14; // rdx
  UFG::DUIRect v15; // xmm0
  int v16; // ecx
  int v17; // er8
  __int32 v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // er8
  int v22; // edx
  int v23; // ecx
  bool v24; // r13
  bool v25; // r12
  bool v26; // di
  int *v27; // rcx
  float *v28; // rcx
  UFG::qColour colour; // [rsp+8h] [rbp-51h]
  UFG::DUIContext::ClickableFlags flags[4]; // [rsp+18h] [rbp-41h]
  UFG::DUIRect v31; // [rsp+28h] [rbp-31h]
  UFG::DUIRect result; // [rsp+38h] [rbp-21h]
  UFG::DUIRect rect; // [rsp+48h] [rbp-11h]
  __int64 v34; // [rsp+58h] [rbp-1h]
  UFG::qString out_string; // [rsp+60h] [rbp+7h]
  UFG::DUIContext::ClickableState click_state; // [rsp+D0h] [rbp+77h]
  unsigned int *retaddr; // [rsp+D8h] [rbp+7Fh]

  v34 = -2i64;
  v4 = state;
  v5 = context;
  v6 = command;
  v7 = this;
  if ( state == State_Unavailable )
    return 0;
  v9 = UFG::qStringHashUpper32("DUIContext", 0xFFFFFFFF);
  if ( v9
    && (v10 = UFG::qBaseTreeRB::Get(&v5->mDictionary.mTree, v9)) != 0i64
    && (v11 = (signed __int64)&v10[-1].mCount) != 0 )
  {
    *(_QWORD *)(v11 + 40) = v7;
  }
  else
  {
    v12 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    *(_QWORD *)flags = v12;
    if ( v12 )
    {
      v13 = UFG::qStringHashUpper32("DUIContext", 0xFFFFFFFF);
      v14 = 0i64;
      v12[1].mNext = 0i64;
      v12[2].mNext = 0i64;
      v12[3].mNext = 0i64;
      LODWORD(v12[4].mNext) = v13;
      v12->mNext = (UFG::allocator::free_link *)&UFG::ContextDataBase::`vftable;
      v12->mNext = (UFG::allocator::free_link *)&UFG::ContextData<UFG::DUIContext *>::`vftable;
      v12[5].mNext = (UFG::allocator::free_link *)v7;
    }
    else
    {
      v14 = 0i64;
      v12 = 0i64;
    }
    if ( v12 )
      v14 = (UFG::qBaseNodeRB *)&v12[1];
    UFG::qBaseTreeRB::Add(&v5->mDictionary.mTree, v14);
  }
  UFG::DUIContext::GetLayoutRect(v7, &result, 0, 0);
  v15 = result;
  _mm_store_si128((__m128i *)&rect, (__m128i)result);
  rect.mW = v7->mTheme.mMenuImage_Inset;
  v16 = rect.mW;
  _mm_store_si128((__m128i *)flags, (__m128i)v15);
  v17 = v16 + _mm_cvtsi128_si32((__m128i)v15);
  v18 = flags[2] - v16;
  v19 = v7->mTheme.mButton_Inset.mY;
  v20 = v7->mTheme.mButton_Inset.mX;
  v21 = v20 + v17;
  flags[0] = v21;
  flags[2] = v18 - 2 * v20;
  flags[1] += v19;
  flags[3] -= 2 * v19;
  _mm_store_si128((__m128i *)&v31, *(__m128i *)flags);
  v22 = v7->mTheme.mButton_Text.mY;
  v23 = v7->mTheme.mButton_Text.mX;
  v31.mX = v23 + v21;
  v31.mW -= 2 * v23;
  v31.mY += v22;
  v31.mH -= 2 * v22;
  v24 = v4 == 1;
  v25 = 0;
  v26 = 0;
  UFG::qString::qString(&out_string);
  if ( *retaddr )
    UFG::DUIContext::RenderRect(v7, &rect, &colour, *retaddr);
  UFG::BuildCommandKeyString(v6, &out_string);
  if ( !v24
    || (UFG::DUIContext::Clickable(v7, &click_state, &result, &result, ClickableFlags_ConsumeInput),
        v25 = click_state == 3,
        v26 = click_state == 1,
        v27 = (int *)&v7->mTheme.mColour[12],
        click_state != 1) )
  {
    v27 = (int *)&v7->mTheme.mColour[11];
  }
  result.mX = *v27;
  result.mY = v27[1];
  result.mW = v27[2];
  result.mH = v27[3];
  if ( v24 )
  {
    v28 = &v7->mTheme.mColour[2].r;
    if ( !v26 )
      v28 = (float *)v7->mTheme.mColour;
  }
  else
  {
    v28 = &v7->mTheme.mColour[1].r;
  }
  colour.r = *v28;
  colour.g = v28[1];
  colour.b = v28[2];
  colour.a = v28[3];
  if ( v26 )
    UFG::DUIContext::RenderRoundRect(v7, (UFG::DUIRect *)flags, (UFG::qColour *)&result, 0);
  UFG::DUIContext::RenderText(v7, &v31, &colour, v6->mDisplayText.mData, 0x10u);
  if ( out_string.mLength )
    UFG::DUIContext::RenderText(v7, &v31, &colour, out_string.mData, 0x14u);
  if ( v25 && v24 )
    v6->vfptr->Execute(v6, v5);
  UFG::qString::~qString(&out_string);
  return v25;
}

// File Line: 4484
// RVA: 0x1971B0
__int64 __fastcall UFG::DUIContext::CommandImageButton(UFG::DUIContext *this, UFG::Command *command, UFG::CommandContext *context)
{
  UFG::CommandContext *v3; // r12
  UFG::Command *v4; // rdi
  UFG::DUIContext *v5; // rbx
  __int64 v6; // rax
  int v7; // esi
  UFG::DUIRect v8; // xmm0
  int v9; // er8
  int v10; // edx
  bool v11; // r13
  bool v12; // r14
  bool v13; // r15
  int v14; // xmm0_4
  int *v15; // rcx
  char *v16; // r8
  UFG::qString *v17; // rax
  UFG::DUIRect rect; // [rsp+30h] [rbp-59h]
  UFG::DUIRect result; // [rsp+40h] [rbp-49h]
  UFG::qString out_string; // [rsp+50h] [rbp-39h]
  __int64 v21; // [rsp+78h] [rbp-11h]
  UFG::qString v22; // [rsp+80h] [rbp-9h]
  unsigned int texture_uid; // [rsp+F8h] [rbp+6Fh]
  UFG::DUIContext::ClickableState click_state; // [rsp+108h] [rbp+7Fh]

  v21 = -2i64;
  v3 = context;
  v4 = command;
  v5 = this;
  texture_uid = 0;
  v6 = command->vfptr->GetState(command, context, &texture_uid);
  v7 = v6;
  if ( (_DWORD)v6 )
  {
    UFG::DUIContext::GetLayoutRect(v5, &result, 0, 0);
    v8 = result;
    _mm_store_si128((__m128i *)&rect, (__m128i)result);
    v9 = v5->mTheme.mButton_Inset.mY;
    v10 = v5->mTheme.mButton_Inset.mX;
    rect.mX = v10 + _mm_cvtsi128_si32((__m128i)v8);
    rect.mW -= 2 * v10;
    rect.mY += v9;
    rect.mH -= 2 * v9;
    _mm_store_si128((__m128i *)&rect, (__m128i)rect);
    v11 = v7 == 1;
    v12 = 0;
    v13 = 0;
    UFG::qString::qString(&out_string);
    if ( texture_uid )
    {
      v14 = (signed int)FLOAT_1_0;
      if ( v7 == 2 )
        v14 = LODWORD(FLOAT_0_5);
      result.mX = 1065353216;
      result.mY = 1065353216;
      result.mW = 1065353216;
      result.mH = v14;
      UFG::DUIContext::RenderRoundRect(v5, &rect, (UFG::qColour *)&result, texture_uid);
    }
    UFG::BuildCommandKeyString(v4, &out_string);
    if ( !v11
      || (UFG::DUIContext::Clickable(v5, &click_state, &rect, &rect, ClickableFlags_ConsumeInput),
          v12 = click_state == 3,
          v13 = click_state == 1,
          v15 = (int *)&v5->mTheme.mColour[12],
          click_state != 1) )
    {
      v15 = (int *)&v5->mTheme.mColour[11];
    }
    result.mX = *v15;
    result.mY = v15[1];
    result.mW = v15[2];
    result.mH = v15[3];
    if ( v13 )
      UFG::DUIContext::RenderRoundRect(v5, &rect, (UFG::qColour *)&result, 0);
    v16 = v4->mDisplayText.mData;
    if ( out_string.mLength )
      v17 = UFG::qString::FormatEx(&v22, "%s (%s)", v16, out_string.mData);
    else
      v17 = UFG::qString::FormatEx(&v22, "%s", v16);
    UFG::DUIContext::Tooltip(v5, v17->mData, &rect);
    UFG::qString::~qString(&v22);
    if ( v12 && v11 )
      v4->vfptr->Execute(v4, v3);
    UFG::qString::~qString(&out_string);
    v6 = v12;
  }
  return v6;
}

// File Line: 4550
// RVA: 0x194FF0
void __fastcall UFG::DUIContext::BeginTreeView(UFG::DUIContext *this, UFG::IDUICollectionView *selected_items, UFG::IDUICollectionView *expanded_items, bool multiselect)
{
  bool v4; // di
  UFG::IDUICollectionView *v5; // rbx
  UFG::IDUICollectionView *v6; // r14
  UFG::DUIContext *v7; // rsi
  UFG::DUIRect *v8; // rax
  UFG::DUILayoutState *v9; // rax
  UFG::allocator::free_link *v10; // rcx
  UFG::DUIRect result; // [rsp+28h] [rbp-30h]

  v4 = multiselect;
  v5 = expanded_items;
  v6 = selected_items;
  v7 = this;
  v8 = UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v9 = UFG::DUIContext::PushLayoutState(v7, v8, LayoutFlag_FillLastCol);
  *(_QWORD *)&v9->mNumCols = 1i64;
  v9->mColWidths = 0i64;
  v9->mRowHeights = 0i64;
  LOBYTE(v7->mLayoutStack.mNode.mNext[8].mNext) = v4;
  v7->mLayoutStack.mNode.mNext[8].mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v6;
  v7->mLayoutStack.mNode.mNext[9].mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v5;
  if ( v4 && v7->mInputState.mKeyIsDownShift
    || !((v7->mInputState.mKeycodeDown - 38) & 0xFD) && v6->vfptr->Count(v6) == 1 )
  {
    v10 = UFG::qMalloc(0x18ui64, "DUIIntArray", 0x800ui64);
    if ( v10 )
    {
      v10->mNext = (UFG::allocator::free_link *)&UFG::DUIIntArray::`vftable;
      v10[2].mNext = 0i64;
      v10[1].mNext = 0i64;
    }
    else
    {
      v10 = 0i64;
    }
    v7->mLayoutStack.mNode.mNext[7].mNext = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v10;
  }
}

// File Line: 4567
// RVA: 0x1990D0
void __fastcall UFG::DUIContext::HandleSelection(UFG::DUIContext *this, unsigned __int64 id, UFG::DUIIntArray *accumulatedItems, UFG::IDUICollectionView *selectedItems, bool *is_selected, int *selection_index)
{
  UFG::IDUICollectionView *v6; // rdi
  UFG::DUIIntArray *v7; // r14
  unsigned __int64 v8; // rbx
  bool v9; // al
  unsigned int v10; // ebx
  unsigned int v11; // ebp
  UFG::IDUICollectionViewVtbl *v12; // rbx
  unsigned int v13; // eax
  __int64 v14; // rax
  __int64 v15; // rsi

  v6 = selectedItems;
  v7 = accumulatedItems;
  v8 = id;
  if ( this->mInputState.mKeyIsDownControl )
  {
    v9 = *is_selected == 0;
    *is_selected = v9;
    if ( !v9 )
    {
      if ( *selection_index != -1 )
        ((void (__fastcall *)(UFG::IDUICollectionView *))selectedItems->vfptr->RemoveAt)(selectedItems);
      return;
    }
  }
  else
  {
    *is_selected = 1;
  }
  if ( LOBYTE(this->mLayoutStack.mNode.mNext[8].mNext) && *(_WORD *)&this->mInputState.mKeyIsDownControl )
  {
    if ( *selection_index != -1 )
      return;
  }
  else
  {
    selectedItems->vfptr->Clear(selectedItems);
    *selection_index = -1;
  }
  if ( v7 )
  {
    v10 = 0;
    v11 = v7->vfptr->Count((UFG::IDUICollectionView *)&v7->vfptr);
    if ( v6->vfptr->Count(v6) )
    {
      v12 = v6->vfptr;
      v13 = v6->vfptr->Count(v6);
      v14 = v12->GetAt(v6, v13 - 1);
      v10 = v7->vfptr->IndexOf((UFG::IDUICollectionView *)&v7->vfptr, v14);
    }
    for ( ; v10 < v11; ++v10 )
    {
      v15 = v7->vfptr->GetAt((UFG::IDUICollectionView *)&v7->vfptr, v10);
      if ( v6->vfptr->IndexOf(v6, v15) == -1 )
        v6->vfptr->Add(v6, v15);
    }
  }
  else
  {
    v6->vfptr->Add(v6, v8);
  }
}

// File Line: 4623
// RVA: 0x19F650
__int64 __fastcall UFG::DUIContext::TreeViewItem(UFG::DUIContext *this, const char *name, unsigned __int64 id, bool has_children)
{
  unsigned __int64 v4; // r15
  const char *v5; // rsi
  UFG::DUIContext *v6; // rdi
  UFG::DUIRect v7; // xmm1
  int v8; // edx
  int v9; // ecx
  int v10; // er8
  int v11; // edx
  int v12; // ecx
  int v13; // er9
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v14; // rcx
  int v15; // eax
  UFG::DUIIntArray *v16; // r12
  int v17; // ebx
  unsigned int v18; // er14
  bool v19; // r13
  bool v20; // bl
  char v21; // r14
  const char *v22; // rdx
  int flags; // [rsp+20h] [rbp-69h]
  UFG::IDUICollectionView *selectedItems[2]; // [rsp+30h] [rbp-59h]
  UFG::DUIContext::ClickableState click_state; // [rsp+40h] [rbp-49h]
  int selection_index; // [rsp+44h] [rbp-45h]
  UFG::DUIRect result; // [rsp+50h] [rbp-39h]
  UFG::DUIRect rect; // [rsp+60h] [rbp-29h]
  UFG::DUIRect current_rect; // [rsp+70h] [rbp-19h]
  UFG::qString v31; // [rsp+80h] [rbp-9h]
  __int64 v32; // [rsp+A8h] [rbp+1Fh]
  bool is_selected; // [rsp+F0h] [rbp+67h]
  bool v34; // [rsp+108h] [rbp+7Fh]

  v34 = has_children;
  v32 = -2i64;
  v4 = id;
  v5 = name;
  v6 = this;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v7 = result;
  _mm_store_si128((__m128i *)&current_rect, (__m128i)result);
  current_rect.mW = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v7, 12));
  _mm_store_si128((__m128i *)selectedItems, (__m128i)v7);
  v8 = v6->mTheme.mButton_Text.mY;
  v9 = v6->mTheme.mButton_Text.mX;
  v10 = _mm_cvtsi128_si32((__m128i)v7);
  LODWORD(selectedItems[0]) = v10 + v9;
  LODWORD(selectedItems[1]) -= 2 * v9;
  HIDWORD(selectedItems[0]) += v8;
  HIDWORD(selectedItems[1]) -= 2 * v8;
  _mm_store_si128((__m128i *)&result, *(__m128i *)selectedItems);
  _mm_store_si128((__m128i *)selectedItems, (__m128i)v7);
  v11 = v6->mTheme.mButton_Inset.mY;
  v12 = v6->mTheme.mButton_Inset.mX;
  v13 = v10 + v12;
  LODWORD(selectedItems[0]) = v10 + v12;
  LODWORD(selectedItems[1]) -= 2 * v12;
  HIDWORD(selectedItems[0]) += v11;
  HIDWORD(selectedItems[1]) -= 2 * v11;
  _mm_store_si128((__m128i *)&rect, *(__m128i *)selectedItems);
  v14 = v6->mLayoutStack.mNode.mNext;
  v15 = v6->mTheme.mIndent * LODWORD(v14[4].mPrev);
  rect.mX = v13 - v15;
  rect.mW += v15;
  v16 = (UFG::DUIIntArray *)v14[7].mNext;
  if ( v16 )
    v16->vfptr->Add((UFG::IDUICollectionView *)v14[7].mNext, v4);
  selectedItems[0] = (UFG::IDUICollectionView *)v6->mLayoutStack.mNode.mNext[8].mPrev;
  v17 = selectedItems[0]->vfptr->IndexOf((UFG::IDUICollectionView *)v14, v4);
  selection_index = v17;
  v18 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, unsigned __int64))v6->mLayoutStack.mNode.mNext[9].mPrev->mPrev[2].mPrev)(
          v6->mLayoutStack.mNode.mNext[9].mPrev,
          v4);
  v19 = v17 != -1;
  is_selected = v17 != -1;
  v20 = v18 != -1;
  UFG::DUIContext::Clickable(v6, &click_state, &current_rect, &current_rect, ClickableFlags_ConsumeInput);
  if ( click_state == 3 )
    v20 = v18 == -1;
  UFG::DUIContext::Clickable(v6, &click_state, &result, &result, ClickableFlags_ConsumeInput);
  if ( click_state == 3 )
  {
    UFG::DUIContext::HandleSelection(v6, v4, v16, selectedItems[0], &is_selected, &selection_index);
    v19 = is_selected;
  }
  if ( v20 )
  {
    if ( v18 == -1 )
      ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, unsigned __int64))v6->mLayoutStack.mNode.mNext[9].mPrev->mPrev->mPrev)(
        v6->mLayoutStack.mNode.mNext[9].mPrev,
        v4);
  }
  else if ( v18 != -1 )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, _QWORD))v6->mLayoutStack.mNode.mNext[9].mPrev->mPrev[1].mPrev)(
      v6->mLayoutStack.mNode.mNext[9].mPrev,
      v18);
  }
  UFG::qString::qString(&v31);
  v21 = v34;
  flags = UFG::qStringLength(v5);
  if ( v21 )
  {
    if ( v20 )
      v22 = "- ";
    else
      v22 = "+ ";
  }
  else
  {
    v22 = "  ";
  }
  UFG::qString::Set(&v31, v22, 2, v5, flags);
  if ( v19 )
    UFG::DUIContext::RenderRoundRect(v6, &rect, &v6->mTheme.mColour[12], 0);
  UFG::DUIContext::RenderText(v6, &result, v6->mTheme.mColour, v31.mData, 0);
  UFG::qString::~qString(&v31);
  return (unsigned __int8)v21 & v20;
}

// File Line: 4718
// RVA: 0x198090
void __fastcall UFG::DUIContext::EndTreeView(UFG::DUIContext *this)
{
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v1; // rdi
  UFG::DUIContext *v2; // rsi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v3; // r14
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v4; // rdi
  __int64 v5; // rax
  int v6; // ebx
  int v7; // ebx
  __int64 v8; // rdx
  signed int v9; // eax
  __int64 v10; // rbx

  v1 = this->mLayoutStack.mNode.mNext;
  v2 = this;
  v3 = v1[7].mNext;
  if ( v3 )
  {
    v4 = v1[8].mPrev;
    if ( v4 )
    {
      if ( ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v4->mPrev[3].mPrev)(v4) == 1 )
      {
        v5 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, _QWORD))v4->mPrev[1].mNext)(
               v4,
               0i64);
        v6 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v3->mPrev[2].mPrev)(
               v3,
               v5);
        if ( !((v2->mInputState.mKeycodeDown - 38) & 0xFD)
          && UFG::DUIContext::IsMouseOver(v2, (UFG::DUIRect *)&v2->mLayoutStack.mNode.mNext[1]) )
        {
          if ( v2->mInputState.mKeycodeDown == 38 )
            v7 = v6 - 1;
          else
            v7 = v6 + 1;
          v8 = ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v3->mPrev[3].mPrev)(v3)
             - 1;
          v9 = 0;
          if ( v7 > 0 )
            v9 = v7;
          if ( v9 < (signed int)v8 )
            v8 = (unsigned int)v9;
          v10 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v3->mPrev[1].mNext)(
                  v3,
                  v8);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v4->mPrev[2].mNext)(v4);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v4->mPrev->mPrev)(
            v4,
            v10);
        }
      }
    }
  }
  UFG::DUIContext::PopLayoutState(v2);
}

// File Line: 4747
// RVA: 0x194C30
void __fastcall UFG::DUIContext::BeginListView(UFG::DUIContext *this, UFG::IDUICollectionView *selected_items, UFG::DUIPoint *current_scroll_pos, bool multiselect)
{
  bool v4; // bl
  UFG::IDUICollectionView *v5; // rsi
  UFG::DUIContext *v6; // rdi
  UFG::DUIRect *v7; // rax
  UFG::DUILayoutState *v8; // rax
  UFG::allocator::free_link *v9; // rcx
  UFG::DUIRect result; // [rsp+28h] [rbp-20h]

  v4 = multiselect;
  v5 = selected_items;
  v6 = this;
  UFG::DUIContext::BeginScrollView(this, current_scroll_pos);
  v7 = UFG::DUIContext::GetLayoutRect(v6, &result, 0, 0);
  v8 = UFG::DUIContext::PushLayoutState(v6, v7, LayoutFlag_FillLastCol);
  *(_QWORD *)&v8->mNumCols = 1i64;
  v8->mColWidths = 0i64;
  v8->mRowHeights = 0i64;
  v6->mLayoutStack.mNode.mNext[8].mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v5;
  LOBYTE(v6->mLayoutStack.mNode.mNext[8].mNext) = v4;
  if ( v4 && v6->mInputState.mKeyIsDownShift
    || !((v6->mInputState.mKeycodeDown - 38) & 0xFD) && v5->vfptr->Count(v5) == 1 )
  {
    v9 = UFG::qMalloc(0x18ui64, "DUIIntArray", 0x800ui64);
    if ( v9 )
    {
      v9->mNext = (UFG::allocator::free_link *)&UFG::DUIIntArray::`vftable;
      v9[2].mNext = 0i64;
      v9[1].mNext = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    v6->mLayoutStack.mNode.mNext[7].mNext = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v9;
  }
}

// File Line: 4764
// RVA: 0x19A150
bool __fastcall UFG::DUIContext::ListViewItem(UFG::DUIContext *this, const char *name, unsigned __int64 id, bool *out_is_selected)
{
  bool *v4; // r13
  unsigned __int64 v5; // r12
  UFG::DUIContext *v6; // rbx
  int v7; // er8
  int v8; // er9
  UFG::DUIRect v9; // xmm1
  int v10; // er10
  int v11; // edx
  int v12; // ecx
  UFG::DUIRect v13; // xmm0
  UFG::DUIIntArray *v14; // r15
  UFG::IDUICollectionView *v15; // rsi
  int v16; // eax
  bool v17; // di
  int v18; // er14
  UFG::DUIContext::ClickableState click_state; // [rsp+30h] [rbp-40h]
  UFG::DUIRect v21; // [rsp+40h] [rbp-30h]
  UFG::DUIRect result; // [rsp+50h] [rbp-20h]
  UFG::DUIRect rect; // [rsp+60h] [rbp-10h]
  bool is_selected; // [rsp+B0h] [rbp+40h]
  char *text; // [rsp+B8h] [rbp+48h]
  int selection_index; // [rsp+C8h] [rbp+58h]

  text = (char *)name;
  v4 = out_is_selected;
  v5 = id;
  v6 = this;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v7 = v6->mTheme.mButton_Inset.mX;
  v8 = v6->mTheme.mButton_Inset.mY;
  v9 = result;
  _mm_store_si128((__m128i *)&v21, (__m128i)result);
  v10 = _mm_cvtsi128_si32((__m128i)v9);
  v21.mY += v8;
  v11 = v6->mTheme.mButton_Text.mY;
  v21.mX = v10 + v7;
  v21.mW -= 2 * v7;
  v21.mH -= 2 * v8;
  v12 = v6->mTheme.mButton_Text.mX;
  v13 = v21;
  _mm_store_si128((__m128i *)&v21, (__m128i)v9);
  v21.mY += v11;
  _mm_store_si128((__m128i *)&rect, (__m128i)v13);
  v21.mX = v10 + v12;
  v21.mW -= 2 * v12;
  v14 = (UFG::DUIIntArray *)v6->mLayoutStack.mNode.mNext[7].mNext;
  v21.mH -= 2 * v11;
  _mm_store_si128((__m128i *)&v21, (__m128i)v21);
  if ( v14 )
    v14->vfptr->Add((UFG::IDUICollectionView *)&v14->vfptr, v5);
  v15 = (UFG::IDUICollectionView *)v6->mLayoutStack.mNode.mNext[8].mPrev;
  v16 = v15->vfptr->IndexOf(v15, v5);
  v17 = v16 != -1;
  v18 = v16;
  selection_index = v16;
  is_selected = v16 != -1;
  UFG::DUIContext::Clickable(v6, &click_state, &result, &result, ClickableFlags_ConsumeInput);
  if ( click_state == 3 )
  {
    UFG::DUIContext::HandleSelection(v6, v5, v14, v15, &is_selected, &selection_index);
    v18 = selection_index;
    v17 = is_selected;
  }
  if ( v17 )
  {
    UFG::DUIContext::RenderRoundRect(v6, &rect, &v6->mTheme.mColour[12], 0);
    UFG::DUIContext::PushColour(v6, 0, &UFG::qColourBlack);
  }
  UFG::DUIContext::RenderText(v6, &v21, v6->mTheme.mColour, text, 0);
  if ( v17 )
    UFG::DUIContext::PopColour(v6, 0);
  if ( v4 )
    *v4 = v17;
  return v17 != (v18 != -1);
}

// File Line: 4818
// RVA: 0x197D00
void __fastcall UFG::DUIContext::EndListView(UFG::DUIContext *this)
{
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v1; // rsi
  UFG::DUIContext *v2; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v3; // r14
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v4; // rsi
  __int64 v5; // rax
  int v6; // ebx
  int v7; // ebx
  __int64 v8; // rdx
  signed int v9; // eax
  __int64 v10; // rbx

  v1 = this->mLayoutStack.mNode.mNext;
  v2 = this;
  v3 = v1[7].mNext;
  if ( v3 )
  {
    v4 = v1[8].mPrev;
    if ( v4 )
    {
      if ( ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v4->mPrev[3].mPrev)(v4) == 1 )
      {
        v5 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, _QWORD))v4->mPrev[1].mNext)(
               v4,
               0i64);
        v6 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v3->mPrev[2].mPrev)(
               v3,
               v5);
        if ( !((v2->mInputState.mKeycodeDown - 38) & 0xFD)
          && UFG::DUIContext::IsMouseOver(v2, (UFG::DUIRect *)&v2->mLayoutStack.mNode.mNext[1]) )
        {
          if ( v2->mInputState.mKeycodeDown == 38 )
            v7 = v6 - 1;
          else
            v7 = v6 + 1;
          v8 = ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v3->mPrev[3].mPrev)(v3)
             - 1;
          v9 = 0;
          if ( v7 > 0 )
            v9 = v7;
          if ( v9 < (signed int)v8 )
            v8 = (unsigned int)v9;
          v10 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v3->mPrev[1].mNext)(
                  v3,
                  v8);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v4->mPrev[2].mNext)(v4);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v4->mPrev->mPrev)(
            v4,
            v10);
        }
      }
    }
  }
  UFG::DUIContext::PopLayoutState(v2);
  UFG::DUIContext::EndScrollView(v2);
}

// File Line: 4852
// RVA: 0x194060
void __fastcall UFG::DUIContext::BeginDataGrid(UFG::DUIContext *this, int num_cols, const char **headings, int *column_widths, UFG::IDUICollectionView *selected_items, UFG::DUIPoint *current_scroll_pos, int *sort_index, bool multiselect, int virtual_row_count, UFG::DUIVirtualGridMetrics *metrics)
{
  int *v10; // r13
  const char **v11; // r14
  int v12; // er15
  UFG::DUIContext *v13; // rbx
  UFG::DUIRect *v14; // rax
  UFG::DUILayoutState *v15; // rax
  __int64 v16; // rdi
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // esi
  __int64 i; // rbp
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v22; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v23; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v24; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v25; // rsi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v26; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v27; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v28; // rax
  int v29; // edi
  UFG::allocator::free_link *v30; // rcx
  signed int v31; // edx
  int v32; // ecx
  float v33; // xmm0_4
  signed int v34; // ecx
  int j; // eax
  int k; // eax
  int v37; // eax
  int v38; // edx
  UFG::DUIRect result; // [rsp+38h] [rbp-60h]
  UFG::qString v40; // [rsp+48h] [rbp-50h]

  v10 = column_widths;
  v11 = headings;
  v12 = num_cols;
  v13 = this;
  v14 = UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v15 = UFG::DUIContext::PushLayoutState(v13, v14, LayoutFlag_FillLastCell);
  v15->mNumCols = 1;
  v15->mNumRows = 2;
  v16 = 0i64;
  v15->mColWidths = 0i64;
  v15->mRowHeights = 0i64;
  UFG::DUIContext::GetLayoutRect(v13, &result, 0, 0);
  v17 = v13->mTheme.mClientInset.mX;
  v18 = -2 * v17 - v13->mTheme.mScrollbarW + result.mW;
  v13->mLayoutOverrideRect.mX = v17 + result.mX;
  v13->mLayoutOverrideRect.mY = result.mY;
  v13->mLayoutOverrideRect.mW = v18;
  v13->mLayoutOverrideRect.mH = result.mH;
  v13->mLayoutOverrideRectEnabled = 1;
  UFG::DUIContext::BeginGridLayout(v13, v12, 1, v10, 0i64, 12);
  if ( sort_index )
    v19 = *sort_index;
  else
    v19 = -1;
  v20 = 0;
  for ( i = v19; v20 < v12; ++v16 )
  {
    if ( i >= 0 )
    {
      if ( v16 == i )
      {
        UFG::qString::FormatEx(&v40, "%s %s", pattern, v11[v16]);
        UFG::DUIContext::Button(v13, v40.mData, 0x10u);
        UFG::qString::~qString(&v40);
      }
      else if ( (unsigned __int8)UFG::DUIContext::Button(v13, v11[v16], 0x10u) )
      {
        *sort_index = v20;
      }
    }
    else
    {
      UFG::DUIContext::Button(v13, v11[v16], 0x10u);
    }
    ++v20;
  }
  v22 = v13->mLayoutStack.mNode.mNext;
  v23 = v22->mPrev;
  v24 = v22->mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  v22->mPrev = v22;
  v22->mNext = v22;
  if ( LOBYTE(v22[4].mNext) )
    UFG::DUIContext::PopScissor(v13);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)v13->mLayoutStack.mNode.mNext != &v13->mLayoutStack
    && v13->mCurrentCompositeLayer != 1 )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&v13->mLayoutStack.mNode.mNext[3], (UFG::DUIRect *)&v22[3]);
  }
  v25 = v22[7].mNext;
  if ( v25 )
  {
    v26 = v25[1].mPrev;
    if ( v26 )
      operator delete[](v26);
    v25[1].mPrev = 0i64;
    v25->mNext = 0i64;
    operator delete[](v25);
  }
  v22[7].mNext = 0i64;
  v27 = v22->mPrev;
  v28 = v22->mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  v22->mPrev = v22;
  v22->mNext = v22;
  operator delete[](v22);
  UFG::DUIContext::BeginScrollView(v13, current_scroll_pos);
  v29 = 0;
  if ( virtual_row_count > -1 )
  {
    v13->mLayoutStack.mNode.mNext[9].mNext = 0i64;
    v29 = SHIDWORD(v13->mLayoutStack.mNode.mNext[7].mPrev->mPrev) / v13->mTheme.mRowHeight;
  }
  UFG::DUIContext::BeginGridLayout(v13, v12, 0, v10, 0i64, 0);
  v13->mLayoutStack.mNode.mNext[8].mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)selected_items;
  v13->mLayoutStack.mNode.mNext[10].mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)virtual_row_count;
  LOBYTE(v13->mLayoutStack.mNode.mNext[8].mNext) = multiselect;
  if ( multiselect && v13->mInputState.mKeyIsDownShift
    || !((v13->mInputState.mKeycodeDown - 38) & 0xFD) && selected_items->vfptr->Count(selected_items) == 1 )
  {
    v30 = UFG::qMalloc(0x18ui64, "DUIIntArray", 0x800ui64);
    if ( v30 )
    {
      v30->mNext = (UFG::allocator::free_link *)&UFG::DUIIntArray::`vftable;
      v30[2].mNext = 0i64;
      v30[1].mNext = 0i64;
    }
    else
    {
      v30 = 0i64;
    }
    v13->mLayoutStack.mNode.mNext[7].mNext = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v30;
  }
  if ( virtual_row_count > -1 )
  {
    v31 = (signed int)(((double)SHIDWORD(v13->mLayoutStack.mNode.mNext[1].mNext) + (double)v13->mTheme.mRowHeight * 0.5)
                     / (double)v13->mTheme.mRowHeight);
    v32 = virtual_row_count;
    if ( v31 + v29 < virtual_row_count )
      v32 = v31 + v29;
    v33 = 0.0;
    if ( (float)v32 >= 0.0 )
      v33 = (float)v32;
    v34 = (signed int)v33;
    for ( j = (signed int)v33 - v29; j < v31; ++j )
    {
      if ( v34 >= virtual_row_count )
        break;
      ++v34;
    }
    for ( k = v34 - v29; k < v31; ++k )
    {
      if ( v29 <= 0 )
        break;
      --v29;
    }
    if ( v13->mIsScrollViewDragging )
    {
      v37 = v34 - v29;
      v38 = metrics->mEnd - metrics->mStart;
      if ( v34 - v29 < v38 || v37 > v38 )
        v13->mFocusedID += v37 - v38;
    }
    metrics->mStart = v29;
    metrics->mEnd = v34;
    HIDWORD(v13->mLayoutStack.mNode.mNext[10].mNext) = v29;
    LODWORD(v13->mLayoutStack.mNode.mNext[10].mNext) = v34;
  }
}

// File Line: 4943
// RVA: 0x1944A0
_BOOL8 __fastcall UFG::DUIContext::BeginDataGridItem(UFG::DUIContext *this, unsigned __int64 id, bool *out_is_selected, UFG::DUIRect *out_rect)
{
  unsigned __int64 v4; // r12
  UFG::DUIRect *v5; // rdi
  bool *v6; // r13
  UFG::DUIContext *v7; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v8; // rax
  UFG::DUIRect v9; // xmm0
  UFG::DUIRect v10; // xmm0
  int v11; // edx
  int v12; // er8
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v13; // rax
  UFG::DUIIntArray *v14; // r14
  UFG::IDUICollectionView *v15; // rdi
  int v16; // eax
  bool v17; // di
  int v18; // er15
  int v19; // esi
  UFG::IDUICollectionView *selectedItems[2]; // [rsp+30h] [rbp-30h]
  UFG::DUIRect result; // [rsp+40h] [rbp-20h]
  UFG::DUIRect rect; // [rsp+50h] [rbp-10h]
  bool is_selected; // [rsp+A0h] [rbp+40h]
  int selection_index; // [rsp+B0h] [rbp+50h]
  UFG::DUIContext::ClickableState click_state; // [rsp+B8h] [rbp+58h]

  v4 = id;
  v5 = out_rect;
  v6 = out_is_selected;
  v7 = this;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v8 = v7->mLayoutStack.mNode.mNext;
  v9 = result;
  v7->mLayoutOverrideRectEnabled = 1;
  v7->mLayoutOverrideRect = v9;
  result.mW = (int)v8[1].mNext;
  v10 = result;
  if ( v5 )
    *v5 = result;
  v11 = v7->mTheme.mButton_Inset.mX;
  v12 = v7->mTheme.mButton_Inset.mY;
  _mm_store_si128((__m128i *)selectedItems, (__m128i)v10);
  HIDWORD(selectedItems[0]) += v12;
  LODWORD(selectedItems[0]) = v11 + _mm_cvtsi128_si32((__m128i)v10);
  LODWORD(selectedItems[1]) -= 2 * v11;
  v13 = v7->mLayoutStack.mNode.mNext;
  v14 = (UFG::DUIIntArray *)v13[7].mNext;
  v15 = (UFG::IDUICollectionView *)v13[8].mPrev;
  HIDWORD(selectedItems[1]) -= 2 * v12;
  _mm_store_si128((__m128i *)&rect, *(__m128i *)selectedItems);
  selectedItems[0] = v15;
  if ( v14 )
    v14->vfptr->Add((UFG::IDUICollectionView *)&v14->vfptr, v4);
  v16 = v15->vfptr->IndexOf(v15, v4);
  v17 = v16 != -1;
  v18 = 0;
  v19 = v16;
  selection_index = v16;
  is_selected = v16 != -1;
  UFG::DUIContext::Clickable(v7, &click_state, &result, &result, 0);
  if ( click_state == 2 )
  {
    UFG::DUIContext::HandleSelection(v7, v4, v14, selectedItems[0], &is_selected, &selection_index);
    v19 = selection_index;
    v17 = is_selected;
  }
  if ( v17 )
    UFG::DUIContext::RenderRoundRect(v7, &rect, &v7->mTheme.mColour[12], 0);
  if ( v6 )
    *v6 = v17;
  if ( v17 )
  {
    UFG::DUIContext::PushColour(v7, 0, &v7->mTheme.mColour[2]);
    v7->mLayoutStack.mNode.mNext[11].mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)1;
  }
  LOBYTE(v18) = v19 != -1;
  return v17 != v18;
}

// File Line: 5002
// RVA: 0x197C90
void __fastcall UFG::DUIContext::EndDataGridItem(UFG::DUIContext *this)
{
  UFG::DUIContext *v1; // rbx

  v1 = this;
  if ( this->mLayoutStack.mNode.mNext[11].mPrev )
  {
    UFG::DUIContext::PopColour(this, 0);
    v1->mLayoutStack.mNode.mNext[11].mPrev = 0i64;
  }
}

// File Line: 5011
// RVA: 0x197B40
void __fastcall UFG::DUIContext::EndDataGrid(UFG::DUIContext *this)
{
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v1; // rsi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v2; // r14
  UFG::DUIContext *v3; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v4; // rsi
  __int64 v5; // rax
  int v6; // ebx
  int v7; // ebx
  __int64 v8; // rdx
  signed int v9; // eax
  __int64 v10; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v11; // rax
  int v12; // ebx
  UFG::DUIRect result; // [rsp+20h] [rbp-18h]

  v1 = this->mLayoutStack.mNode.mNext;
  v2 = v1[7].mNext;
  v3 = this;
  if ( v2 )
  {
    v4 = v1[8].mPrev;
    if ( v4 )
    {
      if ( ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v4->mPrev[3].mPrev)(v4) == 1 )
      {
        v5 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, _QWORD))v4->mPrev[1].mNext)(
               v4,
               0i64);
        v6 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v2->mPrev[2].mPrev)(
               v2,
               v5);
        if ( !((v3->mInputState.mKeycodeDown - 38) & 0xFD)
          && UFG::DUIContext::IsMouseOver(v3, (UFG::DUIRect *)&v3->mLayoutStack.mNode.mNext[1]) )
        {
          if ( v3->mInputState.mKeycodeDown == 38 )
            v7 = v6 - 1;
          else
            v7 = v6 + 1;
          v8 = ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v2->mPrev[3].mPrev)(v2)
             - 1;
          v9 = 0;
          if ( v7 > 0 )
            v9 = v7;
          if ( v9 < (signed int)v8 )
            v8 = (unsigned int)v9;
          v10 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v2->mPrev[1].mNext)(
                  v2,
                  v8);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v4->mPrev[2].mNext)(v4);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v4->mPrev->mPrev)(
            v4,
            v10);
        }
      }
    }
  }
  v11 = v3->mLayoutStack.mNode.mNext;
  if ( v11[10].mPrev != (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)-1i64 )
  {
    v12 = LODWORD(v11[10].mPrev) + HIDWORD(v11[10].mNext) - LODWORD(v11[10].mNext);
    UFG::DUIContext::GetLayoutRect(v3, &result, 0, 0);
    HIDWORD(v3->mLayoutStack.mNode.mNext[3].mNext) += v12 * v3->mTheme.mRowHeight;
  }
  UFG::DUIContext::PopLayoutState(v3);
  UFG::DUIContext::EndScrollView(v3);
  UFG::DUIContext::PopLayoutState(v3);
}

// File Line: 5056
// RVA: 0x1953F0
_BOOL8 __fastcall UFG::DUIContext::Checkbox(UFG::DUIContext *this, const char *name, bool *current_value)
{
  UFG::DUIContext *v3; // rbx
  bool *v4; // rdi
  const char *v5; // r15
  signed int v6; // eax
  int v7; // er9
  int v8; // edx
  UFG::DUIRect v9; // xmm0
  float v10; // er10
  float v11; // er8
  __int64 v12; // rdx
  int v13; // eax
  int v14; // ecx
  UFG::DUIRect v15; // xmm1
  int v16; // er8
  float v17; // ecx
  int v18; // ecx
  UFG::qColour v19; // xmm0
  float v20; // ecx
  int v21; // ecx
  UFG::qColour v22; // xmm0
  bool v23; // cl
  UFG::qColour *v24; // r8
  signed __int64 v25; // rax
  bool v26; // zf
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  UFG::qColour colour; // [rsp+30h] [rbp-19h]
  UFG::DUIRect v33; // [rsp+40h] [rbp-9h]
  UFG::DUIRect rect; // [rsp+50h] [rbp+7h]
  UFG::DUIRect result; // [rsp+60h] [rbp+17h]
  UFG::DUIRect v36; // [rsp+70h] [rbp+27h]
  UFG::DUIRect v37; // [rsp+80h] [rbp+37h]
  UFG::DUIContext::ClickableState click_state; // [rsp+B0h] [rbp+67h]

  v3 = this;
  v4 = current_value;
  v5 = name;
  v6 = UFG::qStringLength(name);
  UFG::DUIContext::GetLayoutRect(
    v3,
    &result,
    (signed int)(float)((float)((float)v6 * v3->mFontDimensions.x) + (float)(2 * v3->mTheme.mCheckBox_Text.mX))
  + (signed int)(float)((float)(2 * v3->mTheme.mCheckBox_Text.mY) + v3->mFontDimensions.y),
    0);
  v7 = v3->mTheme.mCheckBox_Text.mX;
  v8 = v3->mTheme.mCheckBox_Text.mY;
  v9 = result;
  _mm_store_si128((__m128i *)&colour, (__m128i)result);
  LODWORD(colour.g) += v8;
  LODWORD(v10) = v7 + _mm_cvtsi128_si32((__m128i)v9);
  colour.r = v10;
  *(_QWORD *)&v33.mX = __PAIR__(LODWORD(colour.g), LODWORD(v10));
  LODWORD(colour.b) -= 2 * v7;
  v11 = colour.b;
  LODWORD(colour.a) -= 2 * v8;
  v12 = *(_QWORD *)&colour.b >> 32;
  v13 = LODWORD(colour.a) + v7 + LODWORD(v10);
  rect.mY = LODWORD(colour.g);
  v14 = v3->mTheme.mCheckBox_Border.mX;
  v33.mW = LODWORD(colour.a);
  v33.mH = LODWORD(colour.a);
  v15 = v33;
  _mm_store_si128((__m128i *)&colour, (__m128i)v33);
  v16 = LODWORD(v11) - v7 - v12;
  rect.mX = v13;
  LODWORD(colour.r) = v14 + LODWORD(v10);
  rect.mH = v12;
  LODWORD(v12) = v3->mTheme.mCheckBox_Border.mY;
  LODWORD(colour.b) -= 2 * v14;
  rect.mW = v16;
  LODWORD(colour.g) += v12;
  LODWORD(v17) = LODWORD(colour.a) - 2 * v12;
  LODWORD(v12) = v3->mTheme.mCheckBox_Inset.mY;
  colour.a = v17;
  v18 = v3->mTheme.mCheckBox_Inset.mX;
  v19 = colour;
  _mm_store_si128((__m128i *)&colour, (__m128i)v15);
  LODWORD(colour.r) = v18 + LODWORD(v10);
  _mm_store_si128((__m128i *)&v33, (__m128i)v19);
  LODWORD(colour.g) += v12;
  LODWORD(colour.b) -= 2 * v18;
  LODWORD(v20) = LODWORD(colour.a) - 2 * v12;
  LODWORD(v12) = v3->mTheme.mCheckBox_Check.mY;
  colour.a = v20;
  v21 = v3->mTheme.mCheckBox_Check.mX;
  v22 = colour;
  _mm_store_si128((__m128i *)&colour, (__m128i)v15);
  LODWORD(colour.g) += v12;
  _mm_store_si128((__m128i *)&v36, (__m128i)v22);
  LODWORD(colour.r) = v21 + LODWORD(v10);
  LODWORD(colour.b) -= 2 * v21;
  LODWORD(colour.a) -= 2 * v12;
  _mm_store_si128((__m128i *)&v37, (__m128i)colour);
  UFG::DUIContext::Clickable(v3, &click_state, &result, &result, ClickableFlags_ConsumeInput);
  v23 = click_state == 1;
  if ( click_state == 3 )
    *v4 = *v4 == 0;
  v24 = &v3->mTheme.mColour[20];
  if ( v23 )
  {
    v25 = (signed __int64)&v3->mTheme.mColour[20];
  }
  else
  {
    v24 = v3->mTheme.mColour;
    v25 = (signed __int64)&v3->mTheme.mColour[15];
  }
  v26 = *v4 == 0;
  v27 = *(float *)(v25 + 4);
  colour.r = *(float *)v25;
  v28 = *(float *)(v25 + 8);
  colour.g = v27;
  v29 = *(float *)(v25 + 12);
  colour.b = v28;
  colour.a = v29;
  if ( v26 )
  {
    if ( v23 )
      v30 = FLOAT_0_30000001;
    else
      v30 = 0.0;
    colour.a = v30;
  }
  UFG::DUIContext::RenderText(v3, &rect, v24, v5, 0x10u);
  UFG::DUIContext::RenderRoundRect(v3, &v33, &v3->mTheme.mColour[13], 0);
  UFG::DUIContext::RenderRoundRect(v3, &v36, &v3->mTheme.mColour[14], 0);
  UFG::DUIContext::RenderRoundRect(v3, &v37, &colour, 0);
  return *v4;
}:Rend

// File Line: 5113
// RVA: 0x1953A0
_BOOL8 __fastcall UFG::DUIContext::Checkbox(UFG::DUIContext *this, const char *name, unsigned int *bitfield, unsigned int bitflag)
{
  unsigned int *v4; // rbx
  unsigned int v5; // edi
  _BOOL8 result; // rax
  bool current_value; // [rsp+48h] [rbp+20h]

  v4 = bitfield;
  current_value = (bitflag & *bitfield) != 0;
  v5 = bitflag;
  UFG::DUIContext::Checkbox(this, name, &current_value);
  result = current_value;
  if ( current_value )
    *v4 |= v5;
  else
    *v4 &= ~v5;
  return result;
}

// File Line: 5126
// RVA: 0x196C30
_BOOL8 __fastcall UFG::DUIContext::ComboBox(UFG::DUIContext *this, int *current_index, const char **options, unsigned int count, const char **tooltips)
{
  const char **v5; // rbx
  int *v6; // rsi
  UFG::DUIContext *v7; // rbp
  __int64 v8; // rdi
  UFG::qString *v9; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v12; // rax
  bool v13; // di
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // r8
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> optionsa; // [rsp+40h] [rbp-18h]

  v5 = options;
  v6 = current_index;
  v7 = this;
  optionsa.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&optionsa;
  optionsa.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&optionsa;
  if ( count )
  {
    v8 = count;
    do
    {
      v9 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      if ( v9 )
      {
        UFG::qString::qString(v9, *v5);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      v12 = optionsa.mNode.mPrev;
      optionsa.mNode.mPrev->mNext = v11;
      v11->mPrev = v12;
      v11->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&optionsa;
      optionsa.mNode.mPrev = v11;
      ++v5;
      --v8;
    }
    while ( v8 );
  }
  v13 = UFG::DUIContext::ComboBox(v7, v6, &optionsa, tooltips, 0xFFFFFFFF);
  for ( i = (UFG::qString *)optionsa.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)optionsa.mNode.mNext != &optionsa;
        i = (UFG::qString *)optionsa.mNode.mNext )
  {
    v15 = i->mPrev;
    v16 = i->mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v17 = optionsa.mNode.mPrev;
  v18 = optionsa.mNode.mNext;
  optionsa.mNode.mPrev->mNext = optionsa.mNode.mNext;
  v18->mPrev = v17;
  return v13;
}

// File Line: 5137
// RVA: 0x196950
bool __fastcall UFG::DUIContext::ComboBox(UFG::DUIContext *this, int *current_index, UFG::qList<UFG::qString,UFG::qString,1,0> *options, const char **tooltips, unsigned int count)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *v5; // rsi
  int *v6; // r15
  UFG::DUIContext *v7; // rbx
  UFG::DUIRect v8; // xmm3
  int v9; // er9
  int v10; // edx
  signed int v11; // er8
  __m128i v12; // xmm0
  float v13; // xmm2_4
  int v14; // edi
  UFG::qList<UFG::qString,UFG::qString,1,0> *i; // rax
  int v16; // edi
  int v17; // er12
  int v18; // er13
  UFG::allocator::free_link *v19; // rax
  UFG::DUIComboBoxWindow *v20; // rax
  UFG::DUIComboBoxWindow *v21; // rax
  UFG::DUIComboBoxWindow *v22; // rax
  UFG::DUIComboBoxWindow *v23; // rax
  UFG::qColour *v24; // r8
  UFG::qNode<UFG::qString,UFG::qString> *v25; // r9
  int v26; // eax
  int v28; // [rsp+30h] [rbp-51h]
  __m128i v29; // [rsp+50h] [rbp-31h]
  UFG::DUIRect result; // [rsp+60h] [rbp-21h]
  UFG::DUIRect v31; // [rsp+70h] [rbp-11h]
  UFG::DUIRect rect; // [rsp+80h] [rbp-1h]
  bool v33; // [rsp+E0h] [rbp+5Fh]
  UFG::DUIContext::ClickableState click_state; // [rsp+E8h] [rbp+67h]
  int v35; // [rsp+F0h] [rbp+6Fh]
  char **tooltipsa; // [rsp+F8h] [rbp+77h]

  tooltipsa = (char **)tooltips;
  v5 = options;
  v6 = current_index;
  v7 = this;
  v35 = *current_index;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v8 = result;
  _mm_store_si128(&v29, (__m128i)result);
  v9 = v7->mTheme.mButton_Text.mY;
  v10 = v7->mTheme.mButton_Text.mX;
  v29.m128i_i32[0] = v8.mX + v10;
  v29.m128i_i32[2] -= 2 * v10;
  v11 = v29.m128i_i32[2];
  v29.m128i_i32[1] += v9;
  v29.m128i_i32[3] -= 2 * v9;
  v12 = v29;
  _mm_store_si128((__m128i *)&rect, v29);
  _mm_store_si128((__m128i *)&v31, v12);
  v13 = v7->mFontDimensions.x;
  v31.mX = (signed int)(float)((float)((float)v11 - v13) + (float)(v8.mX + v10));
  v31.mW = (signed int)v13;
  _mm_store_si128(&v29, (__m128i)v8);
  v28 = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v8, 12)) + v8.mY;
  v14 = 0;
  for ( i = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v5->mNode.mNext;
        i != v5;
        i = (UFG::qList<UFG::qString,UFG::qString,1,0> *)i->mNode.mNext )
  {
    ++v14;
  }
  v16 = v29.m128i_i32[3] * v14 + 2;
  v17 = v29.m128i_i32[0] - 2;
  v18 = v29.m128i_i32[2] + 4;
  v33 = v7->mActivePopupID == ++v7->mCurrentPopupID;
  if ( UFG::DUIContext::Clickable(v7, &click_state, &result, &result, ClickableFlags_ConsumeInput)
    && v7->mActivePopupID == -1 )
  {
    v7->mActivePopupID = v7->mCurrentPopupID;
    v19 = UFG::qMalloc(0x160ui64, UFG::gGlobalNewName, 0i64);
    v29.m128i_i64[0] = (__int64)v19;
    if ( v19 )
      UFG::DUIComboBoxWindow::DUIComboBoxWindow((UFG::DUIComboBoxWindow *)v19);
    else
      v20 = 0i64;
    v7->mComboBoxWindow = v20;
    UFG::DUIComboBoxWindow::SetData(v20, *v6, v5, count, (const char **)tooltipsa);
    v21 = v7->mComboBoxWindow;
    v21->mRect.mX = v17;
    v21->mRect.mY = v28;
    v21->mRect.mW = v18;
    v21->mRect.mH = v16;
    UFG::DUIManager::ShowWindow(v7->mManager, (UFG::DUIWindow *)&v7->mComboBoxWindow->vfptr, v7->mSurface, 1);
  }
  if ( v33 )
  {
    v22 = v7->mComboBoxWindow;
    if ( v22->mHasDialogResult )
    {
      v7->mActivePopupID = -1;
      *v6 = v22->mDialogResult;
      v23 = v7->mComboBoxWindow;
      if ( !v23->mMarkedToDestroy )
        v23->mMarkedToDestroy = 1;
      v7->mComboBoxWindow = 0i64;
    }
  }
  v24 = &v7->mTheme.mColour[12];
  if ( click_state != 1 )
    v24 = &UFG::qColourBlack;
  UFG::DUIContext::RenderRect(v7, &result, v24, 0);
  v25 = v5->mNode.mNext;
  if ( v25 != (UFG::qNode<UFG::qString,UFG::qString> *)v5 )
  {
    v26 = *v6;
    if ( *v6 != -1 )
    {
      for ( ; v26 > 0; v25 = v25->mNext )
      {
        if ( v25 == (UFG::qNode<UFG::qString,UFG::qString> *)v5 )
          break;
        --v26;
      }
      UFG::DUIContext::RenderText(v7, &rect, &UFG::qColourWhite, (const char *)v25[1].mNext, 0);
    }
  }
  UFG::DUIContext::RenderText(v7, &v31, &UFG::qColourWhite, "V", 0);
  return *v6 != v35;
}[1].mNext, 0);
    }
  }
  UFG::DUIContext::RenderText

// File Line: 5198
// RVA: 0x19A400
char __fastcall UFG::DUIContext::MessageBox(UFG::DUIContext *this, unsigned int *response_value, const char *title, const char *message, const char **options)
{
  const char *v5; // rsi
  const char *v6; // rbp
  unsigned int *v7; // rdi
  UFG::DUIContext *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  int v10; // eax
  UFG::DUIMessageBoxWindow *v11; // rax
  UFG::DUIMessageBoxWindow *v12; // rcx

  v5 = message;
  v6 = title;
  v7 = response_value;
  v8 = this;
  ++this->mCurrentMessageBoxID;
  if ( this->mActiveMessageBoxID == -1 )
  {
    this->mActiveMessageBoxID = this->mCurrentMessageBoxID;
    v9 = UFG::qMalloc(0x178ui64, UFG::gGlobalNewName, 0i64);
    if ( v9 )
      UFG::DUIMessageBoxWindow::DUIMessageBoxWindow((UFG::DUIMessageBoxWindow *)v9);
    v8->mMessageBoxWindow = (UFG::DUIMessageBoxWindow *)v9;
    UFG::DUIMessageBoxWindow::SetData((UFG::DUIMessageBoxWindow *)v9, v6, v5, options);
    v8->mMessageBoxWindow->mRect.mX = v8->mRect.mW / 2 - v8->mMessageBoxWindow->mRect.mW / 2;
    v8->mMessageBoxWindow->mRect.mY = v8->mRect.mH / 2 - v8->mMessageBoxWindow->mRect.mH / 2;
    v8->mMessageBoxWindow->mRect.mH = 400;
    UFG::DUIManager::ShowWindow(v8->mManager, (UFG::DUIWindow *)&v8->mMessageBoxWindow->vfptr, v8->mSurface, 1);
  }
  v10 = v8->mActiveMessageBoxID;
  if ( v10 == -1 )
    return 0;
  if ( v10 != v8->mCurrentMessageBoxID )
    return 0;
  v11 = v8->mMessageBoxWindow;
  if ( !v11->mHasDialogResult )
    return 0;
  *v7 = v11->mDialogResult;
  --v8->mCurrentMessageBoxID;
  v8->mActiveMessageBoxID = -1;
  v12 = v8->mMessageBoxWindow;
  if ( !v12->mMarkedToDestroy )
    v12->mMarkedToDestroy = 1;
  v8->mMessageBoxWindow = 0i64;
  return 1;
}

// File Line: 5246
// RVA: 0x19DC40
void __fastcall UFG::DUIContext::ShowPopupMenu(UFG::DUIContext *this, UFG::DUIPoint *point, const char **tags, UFG::CommandContext *context)
{
  UFG::CommandContext *v4; // rdi
  const char **v5; // rbx
  UFG::DUIPoint *v6; // rsi
  UFG::DUIContext *v7; // r14
  unsigned __int64 v8; // rax
  UFG::qString *v9; // rax
  char *v10; // rcx
  char *v11; // rcx
  char **v12; // rax
  __int64 v13; // rcx
  char *v14; // rax
  UFG::qNode<UFG::Command,UFG::Command> *v15; // rcx
  UFG::qNode<UFG::Command,UFG::Command> *v16; // rax
  UFG::PopupMenuCommand command; // [rsp+20h] [rbp-C8h]
  char *retaddr; // [rsp+138h] [rbp+50h]

  command.mChildTags.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)-2i64;
  v4 = context;
  v5 = tags;
  v6 = point;
  v7 = this;
  command.mPrev = (UFG::qNode<UFG::Command,UFG::Command> *)&command.mPrev;
  command.mNext = (UFG::qNode<UFG::Command,UFG::Command> *)&command.mPrev;
  v8 = UFG::qStringHashUpper64(&customWorldMapCaption, 0xFFFFFFFFFFFFFFFFui64);
  command.mBaseNode.mParent = &command.mBaseNode;
  command.mBaseNode.mChildren[0] = &command.mBaseNode;
  command.mBaseNode.mChildren[1] = &command.mBaseNode;
  command.mBaseNode.mNeighbours[0] = &command.mBaseNode;
  command.mBaseNode.mNeighbours[1] = &command.mBaseNode;
  command.mBaseNode.mUID = v8;
  UFG::qString::qString(&command.mName, &customWorldMapCaption);
  UFG::qString::qString((UFG::qString *)((char *)&command.mName + 16), "popup_menu");
  *(_QWORD *)&command.mDisplayText.mMagic = (char *)&command + 128;
  command.mDisplayText.mData = (char *)&command.mDisplayText.mMagic;
  UFG::qString::qString((UFG::qString *)((char *)&command.mDisplayText + 32));
  *(_QWORD *)&command.mUserType.mMagic = 0i64;
  command.vfptr = (UFG::CommandVtbl *)&UFG::PopupMenuCommand::`vftable;
  retaddr = (char *)&command.mUserType.mData;
  command.mUserType.mData = (char *)&command.mUserType.mData;
  *(_QWORD *)&command.mUserType.mStringHash32 = (char *)&command + 192;
  LOBYTE(command.mManager) = 1;
  UFG::qString::Set((UFG::qString *)((char *)&command.mDisplayText + 32), "PopupMenuCommand");
  if ( v5 && *v5 )
  {
    do
    {
      v9 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      retaddr = (char *)v9;
      if ( v9 )
      {
        UFG::qString::qString(v9, *v5);
        ++v5;
      }
      v10 = command.mUserType.mData;
      *((_QWORD *)command.mUserType.mData + 1) = v9;
      v9->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v10;
      v9->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&command.mUserType.mData;
      command.mUserType.mData = (char *)v9;
    }
    while ( *v5 );
  }
  UFG::DUIContext::ShowPopupMenu(v7, v6, &command, v4);
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes((UFG::qList<UFG::qString,UFG::qString,1,0> *)&command.mUserType.mData);
  v11 = command.mUserType.mData;
  v12 = *(char ***)&command.mUserType.mStringHash32;
  *((_QWORD *)command.mUserType.mData + 1) = *(_QWORD *)&command.mUserType.mStringHash32;
  *v12 = v11;
  command.mUserType.mData = (char *)&command.mUserType.mData;
  *(_QWORD *)&command.mUserType.mStringHash32 = (char *)&command + 192;
  command.vfptr = (UFG::CommandVtbl *)&UFG::Command::`vftable;
  UFG::qString::~qString((UFG::qString *)((char *)&command.mDisplayText + 32));
  retaddr = (char *)&command.mDisplayText.mMagic;
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes((UFG::qList<UFG::qString,UFG::qString,1,0> *)&command.mDisplayText.mMagic);
  v13 = *(_QWORD *)&command.mDisplayText.mMagic;
  v14 = command.mDisplayText.mData;
  *(_QWORD *)(*(_QWORD *)&command.mDisplayText.mMagic + 8i64) = command.mDisplayText.mData;
  *(_QWORD *)v14 = v13;
  *(_QWORD *)&command.mDisplayText.mMagic = (char *)&command + 128;
  command.mDisplayText.mData = (char *)&command.mDisplayText.mMagic;
  UFG::qString::~qString((UFG::qString *)((char *)&command.mName + 16));
  UFG::qString::~qString(&command.mName);
  v15 = command.mPrev;
  v16 = command.mNext;
  command.mPrev->mNext = command.mNext;
  v16->mPrev = v15;
}  v16 = command.mNext;
  command.mPrev->mNext = command.mNext;
  

// File Line: 5252
// RVA: 0x19DAD0
void __fastcall UFG::DUIContext::ShowPopupMenu(UFG::DUIContext *this, UFG::DUIPoint *point, UFG::PopupMenuCommand *command, UFG::CommandContext *context)
{
  UFG::CommandContext *v4; // rbp
  UFG::PopupMenuCommand *v5; // r14
  UFG::DUIPoint *v6; // rbx
  UFG::DUIContext *v7; // r15
  UFG::allocator::free_link *v8; // rax
  UFG::qBaseNodeRB *v9; // rdi
  UFG::DUIWindow *v10; // rax
  UFG::DUIWindow *v11; // rsi
  unsigned int v12; // eax
  UFG::qBaseTreeRB *v13; // rax
  signed __int64 v14; // rax
  UFG::allocator::free_link *v15; // rbx
  int v16; // eax

  v4 = context;
  v5 = command;
  v6 = point;
  v7 = this;
  v8 = UFG::qMalloc(0x178ui64, UFG::gGlobalNewName, 0i64);
  v9 = 0i64;
  if ( v8 )
  {
    UFG::DUIPopupMenuWindow::DUIPopupMenuWindow((UFG::DUIPopupMenuWindow *)v8, v4, 1);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  UFG::CommandContext::AddContext<UFG::DUIPoint>(v4, "DUIPopupMenuWindow.OriginalMouseCoords", v6);
  v11->mRect.mX = v6->mX;
  v11->mRect.mY = v6->mY;
  v12 = UFG::qStringHashUpper32("DUIPopupMenuWindow", 0xFFFFFFFF);
  if ( v12
    && (v13 = UFG::qBaseTreeRB::Get(&v4->mDictionary.mTree, v12)) != 0i64
    && (v14 = (signed __int64)&v13[-1].mCount) != 0 )
  {
    *(_QWORD *)(v14 + 40) = v11;
  }
  else
  {
    v15 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    if ( v15 )
    {
      v16 = UFG::qStringHashUpper32("DUIPopupMenuWindow", 0xFFFFFFFF);
      v15[1].mNext = 0i64;
      v15[2].mNext = 0i64;
      v15[3].mNext = 0i64;
      LODWORD(v15[4].mNext) = v16;
      v15->mNext = (UFG::allocator::free_link *)&UFG::ContextDataBase::`vftable;
      v15->mNext = (UFG::allocator::free_link *)&UFG::ContextData<UFG::DUIPopupMenuWindow *>::`vftable;
      v15[5].mNext = (UFG::allocator::free_link *)v11;
    }
    else
    {
      v15 = 0i64;
    }
    if ( v15 )
      v9 = (UFG::qBaseNodeRB *)&v15[1];
    UFG::qBaseTreeRB::Add(&v4->mDictionary.mTree, v9);
  }
  v5->vfptr->Execute((UFG::Command *)&v5->vfptr, v4);
  UFG::DUIManager::ShowWindow(v7->mManager, v11, v7->mSurface, 1);
}

// File Line: 5267
// RVA: 0x19D640
void __fastcall UFG::DUIContext::SetClipboardText(const char *text)
{
  const char *v1; // rsi
  signed __int64 v2; // rbx
  HGLOBAL v3; // rax
  void *v4; // rbp
  void *v5; // rdi

  if ( text )
  {
    v1 = text;
    if ( OpenClipboard(0i64) )
    {
      if ( EmptyClipboard() )
      {
        v2 = -1i64;
        do
          ++v2;
        while ( v1[v2] );
        v3 = GlobalAlloc(2u, (unsigned int)(v2 + 1));
        v4 = v3;
        if ( v3 )
        {
          v2 = (unsigned int)v2;
          v5 = GlobalLock(v3);
          memmove(v5, v1, (unsigned int)v2);
          *((_BYTE *)v5 + v2) = 0;
          GlobalUnlock(v4);
          SetClipboardData(1u, v4);
        }
      }
      CloseClipboard();
    }
  }
}

// File Line: 5300
// RVA: 0x198490
const char *__fastcall UFG::DUIContext::GetClipboardText()
{
  LPVOID v0; // rbx
  HANDLE v1; // rax
  void *v2; // rdi

  v0 = 0i64;
  if ( OpenClipboard(ghWnd) )
  {
    v1 = GetClipboardData(1u);
    v2 = v1;
    if ( v1 )
    {
      v0 = GlobalLock(v1);
      if ( v0 )
        GlobalUnlock(v2);
    }
    CloseClipboard();
  }
  return (const char *)v0;
}

// File Line: 5325
// RVA: 0x1958A0
_BOOL8 __fastcall UFG::DUIContext::Collapsible(UFG::DUIContext *this, const char *name, bool *current_value)
{
  bool *v3; // rdi
  const char *v4; // rsi
  UFG::DUIContext *v5; // rbx
  UFG::DUIRect v6; // xmm1
  int v7; // er9
  int v8; // er8
  int v9; // er10
  int v10; // edx
  int v11; // ecx
  bool v12; // r14
  int v13; // eax
  const char *v14; // rdx
  UFG::qColour *v15; // r8
  UFG::qColour *v16; // r8
  bool v17; // bl
  UFG::DUIRect v19; // [rsp+28h] [rbp-19h]
  UFG::DUIRect result; // [rsp+38h] [rbp-9h]
  UFG::DUIRect rect; // [rsp+48h] [rbp+7h]
  UFG::qString v22; // [rsp+58h] [rbp+17h]
  UFG::DUIContext::ClickableState click_state; // [rsp+A8h] [rbp+67h]

  v3 = current_value;
  v4 = name;
  v5 = this;
  UFG::DUIContext::GetLayoutRect(this, (UFG::DUIRect *)((char *)&rect + 8), 0, 0);
  v6 = result;
  _mm_store_si128((__m128i *)&v19, (__m128i)result);
  v7 = v5->mTheme.mButton_Inset.mY;
  v8 = v5->mTheme.mButton_Inset.mX;
  v9 = _mm_cvtsi128_si32((__m128i)v6);
  v19.mX = v9 + v8;
  v19.mW -= 2 * v8;
  v19.mY += v7;
  v19.mH -= 2 * v7;
  _mm_store_si128((__m128i *)&rect, (__m128i)v19);
  _mm_store_si128((__m128i *)&v19, (__m128i)v6);
  v10 = v5->mTheme.mButton_Text.mY;
  v11 = v5->mTheme.mButton_Text.mX;
  v19.mX = v9 + v11;
  v19.mW -= 2 * v11;
  v19.mY += v10;
  v19.mH -= 2 * v10;
  _mm_store_si128((__m128i *)&v19, (__m128i)v19);
  UFG::DUIContext::Clickable(v5, &click_state, &result, &result, ClickableFlags_ConsumeInput);
  v12 = click_state == 1;
  if ( click_state == 3 )
    *v3 = *v3 == 0;
  UFG::qString::qString(&v22);
  if ( *v3 )
  {
    v13 = UFG::qStringLength(v4);
    v14 = "- ";
  }
  else
  {
    v13 = UFG::qStringLength(v4);
    v14 = "+ ";
  }
  UFG::qString::Set(&v22, v14, 2, v4, v13);
  v15 = &v5->mTheme.mColour[12];
  if ( !v12 )
    v15 = &v5->mTheme.mColour[11];
  UFG::DUIContext::RenderRoundRect(v5, &rect, v15, 0);
  v16 = &v5->mTheme.mColour[2];
  if ( !v12 )
    v16 = v5->mTheme.mColour;
  UFG::DUIContext::RenderText(v5, &v19, v16, v22.mData, 0);
  v17 = *v3;
  UFG::qString::~qString(&v22);
  return v17;
}

// File Line: 5363
// RVA: 0x19E320
_BOOL8 __fastcall UFG::DUIContext::Slider(UFG::DUIContext *this, const char *name, float *current_value, float min)
{
  float *v4; // rdi
  const char *v5; // r14
  UFG::DUIContext *v6; // rbx
  float v7; // xmm7_4
  int v8; // er10
  UFG::DUIRect v9; // xmm1
  int v10; // edx
  int v11; // ecx
  int v12; // er8
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int grip_min_h; // esi
  float v18; // xmm0_4
  char v19; // r10
  UFG::DUIContextVtbl *v20; // r9
  int v21; // er8
  int v22; // ecx
  int v23; // edx
  int v24; // ecx
  bool v25; // al
  UFG::qColour *v26; // rsi
  bool v27; // bl
  UFG::DUIRect result; // [rsp+68h] [rbp-80h]
  UFG::DUIRect rect_track; // [rsp+78h] [rbp-70h]
  UFG::DUIRect rect; // [rsp+88h] [rbp-60h]
  UFG::DUIRect v32; // [rsp+98h] [rbp-50h]
  UFG::qString v33; // [rsp+A8h] [rbp-40h]
  long double value_x; // [rsp+118h] [rbp+30h]
  __int64 retaddr; // [rsp+128h] [rbp+40h]
  float v36; // [rsp+138h] [rbp+50h]
  float v37; // [rsp+140h] [rbp+58h]

  *(_QWORD *)&result.mW = -2i64;
  v4 = current_value;
  v5 = name;
  v6 = this;
  v7 = *current_value;
  UFG::DUIContext::GetLayoutRect(this, (UFG::DUIRect *)((char *)&rect_track + 8), 0, 0);
  v8 = v6->mTheme.mSlider_ValueBoxWidth;
  result.mW = -2 - (v8 + v6->mTheme.mSlider_TrackValueGap);
  v9 = result;
  _mm_store_si128((__m128i *)&result, (__m128i)result);
  v10 = v6->mTheme.mSlider_Inset.mY;
  v11 = v6->mTheme.mSlider_Inset.mX;
  v12 = _mm_cvtsi128_si32((__m128i)v9);
  result.mX = v12 + v11;
  result.mW -= 2 * v11;
  result.mY += v10;
  result.mH -= 2 * v10;
  _mm_store_si128((__m128i *)&rect, (__m128i)result);
  _mm_store_si128((__m128i *)&result, (__m128i)v9);
  v13 = v6->mTheme.mSlider_Text.mY;
  v14 = v6->mTheme.mSlider_Text.mX;
  result.mX = v12 + v14;
  result.mW -= 2 * v14;
  result.mY += v13;
  result.mH -= 2 * v13;
  _mm_store_si128((__m128i *)&v32, (__m128i)result);
  _mm_store_si128((__m128i *)&result, (__m128i)v9);
  v15 = v6->mTheme.mSlider_Track.mY;
  v16 = v6->mTheme.mSlider_Track.mX;
  result.mX = v12 + v16;
  result.mW -= 2 * v16;
  result.mY += v15;
  grip_min_h = result.mH - 2 * v15;
  result.mH -= 2 * v15;
  _mm_store_si128((__m128i *)&rect_track, (__m128i)result);
  _mm_store_si128((__m128i *)&result, (__m128i)v9);
  result.mW = v8;
  result.mX += -2 - v8;
  UFG::DUIContext::NumericTextBox(v6, &result, v4, 0);
  v18 = *v4;
  if ( *v4 <= min )
    v18 = min;
  if ( v18 >= v36 )
    v18 = v36;
  *v4 = v18;
  value_x = v18;
  retaddr = 0i64;
  v19 = UFG::DUIContext::Draggable2D(
          v6,
          &value_x,
          (long double *)&retaddr,
          &result,
          &rect_track,
          min,
          0.0,
          v36,
          0.0,
          v37,
          1.0,
          v6->mTheme.mSliderSize,
          grip_min_h,
          0);
  v25 = 0;
  if ( !v6->mInputState.mMouseLBIsDown && !v6->mInputState.mMouseRBIsDown && !v6->mInputState.mMouseMBIsDown )
  {
    v20 = (&v6->vfptr)[2 * ((signed int)v6->mCurrentCompositeLayer + 54i64)];
    v21 = v6->mInputState.mMousePos.mX;
    v22 = (int)v20[2].UpdateUI;
    if ( v21 >= v22 && v21 <= LODWORD(v20[3].UpdateUI) + v22 )
    {
      v23 = v6->mInputState.mMousePos.mY;
      v24 = HIDWORD(v20[2].UpdateUI);
      if ( v23 >= v24
        && v23 <= HIDWORD(v20[3].UpdateUI) + v24 - 1
        && v21 >= result.mX
        && v21 <= result.mW + result.mX
        && v23 >= result.mY
        && v23 <= result.mH + result.mY - 1
        && !v6->mInputState.mMouseEventHandled )
      {
        v25 = 1;
      }
    }
  }
  if ( v19 )
    *v4 = value_x;
  if ( v25 || (v26 = &v6->mTheme.mColour[19], v19) )
    v26 = &v6->mTheme.mColour[20];
  UFG::qString::qString(&v33);
  UFG::qString::Format(&v33, "%.3f", *v4);
  UFG::DUIContext::RenderRoundRect(v6, &rect, &v6->mTheme.mColour[18], 0);
  UFG::DUIContext::RenderRoundRect(v6, &result, v26, 0);
  UFG::DUIContext::RenderText(v6, &v32, v6->mTheme.mColour, v5, 0x41u);
  v27 = v7 != *v4;
  UFG::qString::~qString(&v33);
  return v27;
}Context::RenderText(v6, &v32, v6->mTheme.mColour, v5, 0x41u);
  v27 = v7 != *v4;
  U

// File Line: 5408
// RVA: 0x19E000
_BOOL8 __fastcall UFG::DUIContext::Slider(UFG::DUIContext *this, const char *name, int *current_value, int min)
{
  int v4; // edi
  int *v5; // r14
  const char *v6; // r15
  UFG::DUIContext *v7; // rsi
  int v8; // er12
  int v9; // er11
  int v10; // er10
  int v11; // er9
  UFG::DUIRect v12; // xmm1
  int v13; // edx
  int v14; // ecx
  int v15; // er8
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // ebx
  signed int v21; // ecx
  signed int v22; // eax
  int v23; // eax
  char v24; // r10
  UFG::DUIContextVtbl *v25; // r9
  int v26; // er8
  int v27; // ecx
  int v28; // edx
  int v29; // ecx
  bool v30; // cl
  UFG::qColour *v31; // rbx
  bool v32; // bl
  UFG::DUIRect result; // [rsp+58h] [rbp-49h]
  UFG::DUIRect rect_track; // [rsp+68h] [rbp-39h]
  UFG::DUIRect rect; // [rsp+78h] [rbp-29h]
  UFG::DUIRect v37; // [rsp+88h] [rbp-19h]
  UFG::qString v38; // [rsp+98h] [rbp-9h]
  long double value_x; // [rsp+F8h] [rbp+57h]
  long double value_y; // [rsp+108h] [rbp+67h]
  void *retaddr; // [rsp+118h] [rbp+77h]
  float v42; // [rsp+120h] [rbp+7Fh]

  v4 = min;
  v5 = current_value;
  v6 = name;
  v7 = this;
  v8 = *current_value;
  UFG::DUIContext::GetLayoutRect(this, (UFG::DUIRect *)((char *)&rect + 8), 0, 0);
  v9 = v7->mTheme.mSlider_TrackValueGap;
  v10 = v7->mTheme.mSlider_ValueBoxWidth;
  result.mW -= v10 + v9;
  v11 = result.mW;
  v12 = result;
  _mm_store_si128((__m128i *)&result, (__m128i)result);
  v13 = v7->mTheme.mSlider_Inset.mY;
  v14 = v7->mTheme.mSlider_Inset.mX;
  v15 = _mm_cvtsi128_si32((__m128i)v12);
  result.mX = v15 + v14;
  result.mW -= 2 * v14;
  result.mY += v13;
  result.mH -= 2 * v13;
  _mm_store_si128((__m128i *)&rect, (__m128i)result);
  _mm_store_si128((__m128i *)&result, (__m128i)v12);
  v16 = v7->mTheme.mSlider_Text.mY;
  v17 = v7->mTheme.mSlider_Text.mX;
  result.mX = v15 + v17;
  result.mW -= 2 * v17;
  result.mY += v16;
  result.mH -= 2 * v16;
  _mm_store_si128((__m128i *)&v37, (__m128i)result);
  _mm_store_si128((__m128i *)&result, (__m128i)v12);
  v18 = v7->mTheme.mSlider_Track.mY;
  v19 = v7->mTheme.mSlider_Track.mX;
  result.mX = v15 + v19;
  result.mW -= 2 * v19;
  result.mY += v18;
  v20 = result.mH - 2 * v18;
  result.mH -= 2 * v18;
  _mm_store_si128((__m128i *)&rect_track, (__m128i)result);
  _mm_store_si128((__m128i *)&result, (__m128i)v12);
  result.mW = v10;
  result.mX += v9 + v11;
  UFG::DUIContext::NumericTextBox(v7, &result, v5, 0);
  v21 = v4;
  if ( *v5 > v4 )
    v21 = *v5;
  v22 = (signed int)retaddr;
  if ( v21 < (signed int)retaddr )
    v22 = v21;
  *v5 = v22;
  value_x = (double)v22;
  v23 = v7->mTheme.mSliderSize;
  value_y = 0.0;
  v24 = UFG::DUIContext::Draggable2D(
          v7,
          &value_x,
          &value_y,
          &result,
          &rect_track,
          (double)v4,
          0.0,
          (double)(signed int)retaddr,
          0.0,
          v42,
          1.0,
          v23,
          v20,
          1);
  v30 = 0;
  if ( !v7->mInputState.mMouseLBIsDown && !v7->mInputState.mMouseRBIsDown && !v7->mInputState.mMouseMBIsDown )
  {
    v25 = (&v7->vfptr)[2 * ((signed int)v7->mCurrentCompositeLayer + 54i64)];
    v26 = v7->mInputState.mMousePos.mX;
    v27 = (int)v25[2].UpdateUI;
    if ( v26 >= v27 && v26 <= LODWORD(v25[3].UpdateUI) + v27 )
    {
      v28 = v7->mInputState.mMousePos.mY;
      v29 = HIDWORD(v25[2].UpdateUI);
      if ( v28 >= v29
        && v28 <= HIDWORD(v25[3].UpdateUI) + v29 - 1
        && v26 >= result.mX
        && v26 <= result.mW + result.mX
        && v28 >= result.mY
        && v28 <= result.mH + result.mY - 1
        && !v7->mInputState.mMouseEventHandled )
      {
        v30 = 1;
      }
    }
  }
  if ( v24 )
    *v5 = (signed int)value_x;
  if ( v30 || (v31 = &v7->mTheme.mColour[19], v24) )
    v31 = &v7->mTheme.mColour[20];
  UFG::qString::qString(&v38);
  UFG::qString::Format(&v38, "%d", (unsigned int)*v5);
  UFG::DUIContext::RenderRoundRect(v7, &rect, &v7->mTheme.mColour[18], 0);
  UFG::DUIContext::RenderRoundRect(v7, &result, v31, 0);
  UFG::DUIContext::RenderText(v7, &v37, v7->mTheme.mColour, v6, 0x41u);
  v32 = *v5 != v8;
  UFG::qString::~qString(&v38);
  return v32;
}

// File Line: 5449
// RVA: 0x195A50
bool __fastcall UFG::DUIContext::ColourBarSlider(UFG::DUIContext *this, const char *name, float *current_value, UFG::DUIRect *rect, UFG::qColour *colour_insetL, UFG::qColour *colour_insetR)
{
  int v6; // er10
  __m128i v7; // xmm0
  UFG::DUIContext *v8; // rdi
  UFG::DUIRect *v9; // rbx
  int v10; // er9
  const char *v11; // r15
  float v12; // xmm6_4
  int v13; // edx
  float *v14; // rsi
  int v15; // er8
  int v16; // er11
  int v17; // eax
  int v18; // ecx
  int v19; // er11
  UFG::DUIRect v20; // xmm0
  UFG::DUIRect v21; // xmm1
  int v22; // ecx
  int v23; // edx
  UFG::DUIRect v24; // xmm0
  int v25; // eax
  int v26; // ecx
  int grip_min_h; // er14
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  float v31; // xmm1_4
  float v32; // xmm0_4
  int grip_min_w; // ST58_4
  bool v34; // r10
  int v35; // er9
  UFG::DUIContextVtbl *v36; // rdx
  int v37; // ecx
  int v38; // er8
  int v39; // ecx
  bool v40; // al
  UFG::qColour *v41; // rbx
  UFG::DUIRect rect_val; // [rsp+70h] [rbp-29h]
  UFG::DUIRect recta; // [rsp+80h] [rbp-19h]
  UFG::DUIRect rect_track; // [rsp+90h] [rbp-9h]
  UFG::DUIRect v46; // [rsp+A0h] [rbp+7h]
  long double value_x; // [rsp+F0h] [rbp+57h]
  long double value_y; // [rsp+100h] [rbp+67h]

  v6 = this->mTheme.mSlider_TrackValueGap;
  v7 = *(__m128i *)rect;
  v8 = this;
  v9 = rect;
  v10 = this->mTheme.mSlider_ValueBoxWidth;
  v11 = name;
  v12 = *current_value;
  v13 = this->mTheme.mColourPicker_Text.mY;
  v14 = current_value;
  v15 = this->mTheme.mColourPicker_Track.mY;
  rect_val = (UFG::DUIRect)v7;
  v16 = this->mTheme.mColourPicker_Inset.mW + v7.m128i_i32[2];
  rect_val.mX = this->mTheme.mColourPicker_Inset.mX + _mm_cvtsi128_si32(v7);
  rect_val.mY += this->mTheme.mColourPicker_Inset.mY;
  v17 = this->mTheme.mColourPicker_Inset.mH;
  v18 = this->mTheme.mColourPicker_Text.mX;
  rect_val.mH = v17 + v7.m128i_i32[3];
  rect_val.mW = v16;
  _mm_store_si128((__m128i *)&recta, (__m128i)rect_val);
  v19 = v16 - v10 - v6;
  recta.mW = v19;
  v21 = recta;
  rect_val = *v9;
  v20 = rect_val;
  rect_val.mY += v13;
  rect_val.mX = v18 + _mm_cvtsi128_si32((__m128i)v20);
  rect_val.mW -= 2 * v18;
  v22 = rect_val.mH - 2 * v13;
  v23 = v8->mTheme.mColourPicker_Track.mX;
  rect_val.mH = v22;
  v24 = rect_val;
  _mm_store_si128((__m128i *)&rect_val, (__m128i)recta);
  v25 = rect_val.mW;
  rect_val.mY += v15;
  _mm_store_si128((__m128i *)&v46, (__m128i)v24);
  rect_val.mX = v23 + _mm_cvtsi128_si32((__m128i)v21);
  v26 = v25 - 2 * v23;
  grip_min_h = rect_val.mH - 2 * v15;
  v28 = v9->mY;
  rect_val.mW = v26;
  v29 = v9->mX;
  rect_val.mH -= 2 * v15;
  _mm_store_si128((__m128i *)&rect_track, (__m128i)rect_val);
  rect_val.mY = v28;
  rect_val.mW = v9->mW;
  v30 = v9->mH;
  rect_val.mW = v10;
  rect_val.mH = v30;
  rect_val.mX = v6 + v19 + v29;
  UFG::DUIContext::NumericTextBox(v8, &rect_val, v14, 0);
  v31 = *v14;
  if ( *v14 <= 0.0 )
  {
    v31 = 0.0;
  }
  else
  {
    v32 = *(float *)&FLOAT_1_0;
    if ( v31 >= 1.0 )
      goto LABEL_6;
  }
  v32 = v31;
LABEL_6:
  *v14 = v32;
  grip_min_w = v8->mTheme.mSliderSize;
  value_x = v32;
  value_y = 0.0;
  v34 = UFG::DUIContext::Draggable2D(
          v8,
          &value_x,
          &value_y,
          &rect_val,
          &rect_track,
          0.0,
          0.0,
          1.0,
          0.0,
          0.0,
          1.0,
          grip_min_w,
          grip_min_h,
          0);
  v40 = 0;
  if ( !v8->mInputState.mMouseLBIsDown && !v8->mInputState.mMouseRBIsDown && !v8->mInputState.mMouseMBIsDown )
  {
    v35 = v8->mInputState.mMousePos.mX;
    v36 = (&v8->vfptr)[2 * ((signed int)v8->mCurrentCompositeLayer + 54i64)];
    v37 = (int)v36[2].UpdateUI;
    if ( v35 >= v37 && v35 <= LODWORD(v36[3].UpdateUI) + v37 )
    {
      v38 = v8->mInputState.mMousePos.mY;
      v39 = HIDWORD(v36[2].UpdateUI);
      if ( v38 >= v39
        && v38 <= HIDWORD(v36[3].UpdateUI) + v39 - 1
        && v35 >= rect_val.mX
        && v35 <= rect_val.mW + rect_val.mX
        && v38 >= rect_val.mY
        && v38 <= rect_val.mH + rect_val.mY - 1
        && !v8->mInputState.mMouseEventHandled )
      {
        v40 = 1;
      }
    }
  }
  if ( v34 )
    *v14 = value_x;
  if ( v40 || (v41 = v8->mTheme.mColour, v34) )
    v41 = &v8->mTheme.mColour[20];
  UFG::DUIContext::RenderRoundRect(v8, &recta, colour_insetL, colour_insetR, 0);
  UFG::DUIContext::RenderRoundRect(v8, &rect_val, v41, 0);
  UFG::DUIContext::RenderText(v8, &v46, v8->mTheme.mColour, v11, 0x41u);
  return v12 != *v14;
}

// File Line: 5563
// RVA: 0x195D60
bool __fastcall UFG::DUIContext::ColourBarSliderHSV(UFG::DUIContext *this, UFG::DUIContext::HSVComponent component, UFG::qColour *colour, UFG::DUIRect *rect)
{
  UFG::DUIRect *v4; // r10
  UFG::qColour *v5; // rbx
  UFG::DUIContext::HSVComponent v6; // er14
  UFG::DUIContext *v7; // rdi
  UFG::qColour *v8; // r12
  float v9; // xmm7_4
  float v10; // xmm6_4
  int v11; // er8
  int v12; // edx
  UFG::DUIRect v13; // xmm0
  int v14; // er9
  int v15; // er13
  int v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // er13
  __m128i v20; // xmm0
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  __m128i v24; // xmm0
  int v25; // edx
  int grip_min_h; // esi
  int v27; // eax
  int v28; // ecx
  __m128i v29; // xmm0
  int v30; // eax
  int v31; // eax
  float v32; // xmm0_4
  int grip_min_w; // ST58_4
  bool v34; // r10
  int v35; // er9
  UFG::DUIContextVtbl *v36; // rdx
  int v37; // ecx
  int v38; // er8
  int v39; // ecx
  bool v40; // al
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  UFG::qColour *v45; // r8
  int v46; // esi
  signed __int64 v47; // r15
  signed __int64 v48; // rbx
  const char *v49; // r9
  char rect_val[24]; // [rsp+70h] [rbp-88h]
  UFG::DUIRect recta; // [rsp+88h] [rbp-70h]
  UFG::DUIRect rect_grip; // [rsp+98h] [rbp-60h]
  UFG::DUIRect v54; // [rsp+A8h] [rbp-50h]
  UFG::qColour colourL; // [rsp+B8h] [rbp-40h]
  UFG::qColour v56; // [rsp+C8h] [rbp-30h]
  UFG::qColour v57; // [rsp+D8h] [rbp-20h]
  UFG::qColour v58; // [rsp+E8h] [rbp-10h]
  UFG::qColour v59; // [rsp+F8h] [rbp+0h]
  UFG::qColour v60; // [rsp+108h] [rbp+10h]
  UFG::qColour v61; // [rsp+118h] [rbp+20h]
  signed __int64 retaddr; // [rsp+198h] [rbp+A0h]
  UFG::DUIContext::HSVComponent v63; // [rsp+1A0h] [rbp+A8h]
  int v64; // [rsp+1A8h] [rbp+B0h]
  long double value_y; // [rsp+1B0h] [rbp+B8h]

  v4 = rect;
  v5 = colour;
  v6 = component;
  v7 = this;
  v8 = colour;
  if ( component == 1 )
  {
    v8 = (UFG::qColour *)((char *)colour + 4);
  }
  else if ( component == 2 )
  {
    v8 = (UFG::qColour *)((char *)colour + 8);
  }
  v9 = v8->r;
  v10 = *(float *)&FLOAT_1_0;
  if ( component == HSVComponent_Hue )
    v10 = FLOAT_360_0;
  v11 = this->mTheme.mSlider_ValueBoxWidth;
  v12 = this->mTheme.mColourPicker_Text.mY;
  v13 = *rect;
  v14 = this->mTheme.mSlider_TrackValueGap;
  *(UFG::DUIRect *)rect_val = v13;
  v15 = this->mTheme.mColourPicker_Inset.mW + v13.mW;
  *(_DWORD *)rect_val = this->mTheme.mColourPicker_Inset.mX + _mm_cvtsi128_si32((__m128i)v13);
  v16 = this->mTheme.mColourPicker_Inset.mY;
  *(_DWORD *)&rect_val[8] = v15;
  *(_DWORD *)&rect_val[4] += v16;
  v17 = this->mTheme.mColourPicker_Inset.mH;
  v18 = this->mTheme.mColourPicker_Text.mX;
  *(_DWORD *)&rect_val[12] = v17 + v13.mH;
  v19 = v15 - v11 - v14;
  _mm_store_si128((__m128i *)&recta, *(__m128i *)rect_val);
  recta.mW = v19;
  *(UFG::DUIRect *)rect_val = *v4;
  v20 = *(__m128i *)rect_val;
  *(_DWORD *)&rect_val[4] += v12;
  *(_DWORD *)rect_val = v18 + _mm_cvtsi128_si32(v20);
  *(_DWORD *)&rect_val[8] = v20.m128i_i32[2] - 2 * v18;
  v21 = v20.m128i_i32[3] - 2 * v12;
  v22 = v7->mTheme.mColourPicker_Track.mY;
  *(_DWORD *)&rect_val[12] = v21;
  v23 = v7->mTheme.mColourPicker_Track.mX;
  v64 = _mm_cvtsi128_si32((__m128i)recta);
  v24 = *(__m128i *)rect_val;
  _mm_store_si128((__m128i *)rect_val, (__m128i)recta);
  *(_DWORD *)&rect_val[4] += v22;
  _mm_store_si128((__m128i *)&v54, v24);
  *(_DWORD *)rect_val = v23 + v64;
  v25 = -v22;
  grip_min_h = *(_DWORD *)&rect_val[12] + 2 * v25;
  v27 = v4->mY;
  *(_DWORD *)&rect_val[8] -= 2 * v23;
  v28 = v4->mX;
  *(_DWORD *)&rect_val[12] += 2 * v25;
  v29 = *(__m128i *)rect_val;
  *(_DWORD *)&rect_val[4] = v27;
  v30 = v4->mW;
  _mm_store_si128((__m128i *)&rect_val[8], v29);
  *(float *)&retaddr = v9;
  *(_DWORD *)&rect_val[8] = v30;
  v31 = v4->mH;
  *(_DWORD *)&rect_val[8] = v11;
  *(_DWORD *)&rect_val[12] = v31;
  *(_DWORD *)rect_val = v14 + v19 + v28;
  if ( v6 )
    *(float *)&retaddr = v9 * 100.0;
  UFG::DUIContext::NumericTextBox(v7, (UFG::DUIRect *)rect_val, (float *)&retaddr, 0);
  v32 = *(float *)&retaddr;
  if ( v6 )
    v32 = *(float *)&retaddr * 0.0099999998;
  v8->r = v32;
  if ( v32 <= 0.0 )
    v32 = 0.0;
  if ( v32 >= v10 )
    v32 = v10;
  v8->r = v32;
  grip_min_w = v7->mTheme.mSliderSize;
  *(double *)&retaddr = v32;
  value_y = 0.0;
  v34 = UFG::DUIContext::Draggable2D(
          v7,
          (long double *)&retaddr,
          &value_y,
          &rect_grip,
          (UFG::DUIRect *)&rect_val[8],
          0.0,
          0.0,
          v10,
          0.0,
          0.0,
          1.0,
          grip_min_w,
          grip_min_h,
          0);
  v40 = 0;
  if ( !v7->mInputState.mMouseLBIsDown && !v7->mInputState.mMouseRBIsDown && !v7->mInputState.mMouseMBIsDown )
  {
    v35 = v7->mInputState.mMousePos.mX;
    v36 = (&v7->vfptr)[2 * ((signed int)v7->mCurrentCompositeLayer + 54i64)];
    v37 = (int)v36[2].UpdateUI;
    if ( v35 >= v37 && v35 <= LODWORD(v36[3].UpdateUI) + v37 )
    {
      v38 = v7->mInputState.mMousePos.mY;
      v39 = HIDWORD(v36[2].UpdateUI);
      if ( v38 >= v39
        && v38 <= HIDWORD(v36[3].UpdateUI) + v39 - 1
        && v35 >= rect_grip.mX
        && v35 <= rect_grip.mW + rect_grip.mX
        && v38 >= rect_grip.mY
        && v38 <= rect_grip.mH + rect_grip.mY - 1
        && !v7->mInputState.mMouseEventHandled )
      {
        v40 = 1;
      }
    }
  }
  if ( v34 )
    v8->r = *(double *)&retaddr;
  if ( v40 || v34 )
    retaddr = (signed __int64)&v7->mTheme.mColour[20];
  else
    retaddr = (signed __int64)v7->mTheme.mColour;
  v56 = UFG::qColour::Yellow;
  v57 = UFG::qColour::Green;
  colourL = UFG::qColour::Red;
  v58 = UFG::qColour::Cyan;
  v59 = UFG::qColour::Blue;
  v61 = UFG::qColour::Red;
  v60 = UFG::qColour::Magenta;
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      v43 = v5->b;
      v44 = v5->r;
      *(_DWORD *)&rect_val[20] = 1065353216;
      *(_DWORD *)&rect_val[4] = 1065353216;
      *(float *)&rect_val[16] = v43;
      *(_DWORD *)&rect_val[12] = 1065353216;
      *(float *)rect_val = v44;
      *(float *)&rect_val[8] = v43;
      UFG::qColourHSVToRGB((UFG::qColour *)rect_val, (UFG::qColour *)rect_val);
      UFG::DUIContext::RenderRoundRect(v7, &recta, (UFG::qColour *)&rect_val[8], (UFG::qColour *)rect_val, 0);
    }
    else if ( v6 == 2 )
    {
      v41 = v5->r;
      v42 = v5->g;
      *(_DWORD *)&rect_val[8] = 1065353216;
      *(_DWORD *)&rect_val[12] = 1065353216;
      *(float *)rect_val = v41;
      *(float *)&rect_val[4] = v42;
      UFG::qColourHSVToRGB((UFG::qColour *)rect_val, (UFG::qColour *)rect_val);
      *(UFG::qColour *)&rect_val[8] = UFG::qColour::Black;
      UFG::DUIContext::RenderRoundRect(v7, &recta, (UFG::qColour *)&rect_val[8], (UFG::qColour *)rect_val, 0);
    }
  }
  else
  {
    *(_DWORD *)&rect_val[12] = recta.mY;
    v45 = &colourL;
    *(_DWORD *)&rect_val[20] = recta.mH;
    v46 = 0;
    v47 = 6i64;
    *(_DWORD *)&rect_val[16] = v19 / 6;
    do
    {
      v48 = (signed __int64)&v45[1];
      *(_DWORD *)&rect_val[8] = v64 + v46 / 6;
      UFG::DUIContext::RenderRoundRect(v7, (UFG::DUIRect *)&rect_val[8], v45, v45 + 1, 0);
      v46 += v19;
      v45 = (UFG::qColour *)v48;
      --v47;
    }
    while ( v47 );
    v6 = v63;
  }
  UFG::DUIContext::RenderRoundRect(v7, &rect_grip, (UFG::qColour *)retaddr, 0);
  if ( v6 == 1 )
  {
    v49 = "S";
  }
  else
  {
    v49 = "V";
    if ( v6 != 2 )
      v49 = "H";
  }
  UFG::DUIContext::RenderText(v7, &v54, v7->mTheme.mColour, v49, 0x41u);
  return v9 != v8->r;
}

// File Line: 5666
// RVA: 0x196340
_BOOL8 __fastcall UFG::DUIContext::ColourPicker(UFG::DUIContext *this, const char *name, UFG::qColour *current_colour_rgb, bool edit_alpha)
{
  bool v4; // r15
  UFG::qColour *v5; // rdi
  const char *v6; // rbx
  UFG::DUIContext *v7; // rsi
  float v8; // xmm11_4
  float v9; // xmm10_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  int v12; // er9
  UFG::DUIRect *v13; // rax
  int v14; // ebx
  int v15; // er9
  int v16; // ecx
  int v17; // er8
  int v18; // edx
  int v19; // ebx
  int v20; // er11
  int v21; // er9
  __int64 v22; // r10
  __int64 v23; // r8
  int v24; // er12
  UFG::DUIRect v25; // xmm7
  int v26; // edx
  int v27; // ecx
  int v28; // er14
  int v29; // er11
  float v30; // xmm6_4
  __m128 v31; // xmm3
  float v32; // xmm4_4
  signed int v33; // ecx
  __m128 v34; // xmm1
  signed int v35; // ecx
  __m128 v36; // xmm2
  signed int v37; // ecx
  bool v38; // al
  bool v39; // al
  char *v40; // rcx
  signed __int64 v41; // rdx
  signed __int64 v42; // r9
  signed int v43; // ebx
  signed int v44; // esi
  signed int v45; // eax
  float v46; // xmm0_4
  float v47; // xmm0_4
  float v48; // xmm1_4
  bool v49; // bl
  UFG::qColour *colour_insetL; // [rsp+20h] [rbp-E0h]
  UFG::DUIRect rect; // [rsp+40h] [rbp-C0h]
  UFG::DUIRect current_rect; // [rsp+50h] [rbp-B0h]
  char dest; // [rsp+60h] [rbp-A0h]
  char v55; // [rsp+61h] [rbp-9Fh]
  char v56; // [rsp+62h] [rbp-9Eh]
  char v57; // [rsp+63h] [rbp-9Dh]
  char v58; // [rsp+64h] [rbp-9Ch]
  char v59; // [rsp+65h] [rbp-9Bh]
  UFG::DUIRect v60; // [rsp+70h] [rbp-90h]
  UFG::qColour hsv; // [rsp+80h] [rbp-80h]
  UFG::DUIRect v62; // [rsp+90h] [rbp-70h]
  UFG::DUIRect v63; // [rsp+A0h] [rbp-60h]
  UFG::DUIRect result; // [rsp+B0h] [rbp-50h]
  __int64 v65; // [rsp+C0h] [rbp-40h]
  UFG::qString str_val; // [rsp+C8h] [rbp-38h]
  char text; // [rsp+190h] [rbp+90h]
  char v68; // [rsp+191h] [rbp+91h]
  char v69; // [rsp+192h] [rbp+92h]
  char v70; // [rsp+193h] [rbp+93h]
  char v71; // [rsp+198h] [rbp+98h]
  char v72; // [rsp+199h] [rbp+99h]
  char v73; // [rsp+19Ah] [rbp+9Ah]
  char v74; // [rsp+19Bh] [rbp+9Bh]
  bool evaluate; // [rsp+1A8h] [rbp+A8h]
  char v76; // [rsp+1A9h] [rbp+A9h]
  char v77; // [rsp+1AAh] [rbp+AAh]
  char v78; // [rsp+1ABh] [rbp+ABh]

  v65 = -2i64;
  v4 = edit_alpha;
  v5 = current_colour_rgb;
  v6 = name;
  v7 = this;
  UFG::qColourRGBToHSV(&hsv, current_colour_rgb);
  v8 = v5->r;
  v9 = v5->g;
  v10 = v5->b;
  v11 = v5->a;
  if ( v6 && *v6 )
    UFG::DUIContext::Label(v7, v6);
  v12 = v7->mTheme.mColourPicker_Height;
  if ( !v4 )
    v12 += 3 * v7->mTheme.mClientInset.mY / 4 - (v12 >> 2);
  v13 = UFG::DUIContext::GetLayoutRect(v7, &result, 0, v12);
  v14 = v13->mX;
  v15 = v13->mY;
  v16 = v13->mW;
  v17 = v13->mH;
  v18 = v7->mTheme.mClientInset.mY;
  LODWORD(v13) = v7->mTheme.mClientInset.mX;
  v19 = (_DWORD)v13 + v14;
  rect.mX = v19;
  v20 = v16 - 2 * (_DWORD)v13;
  rect.mW = v16 - 2 * (_DWORD)v13;
  rect.mY = v18 + v15;
  rect.mH = v17 - 2 * v18;
  v21 = v7->mTheme.mColourPicker_SwatchW;
  LODWORD(v13) = v19 + v16 - 2 * (_DWORD)v13 - v21;
  current_rect.mX = (signed int)v13;
  v22 = *(_QWORD *)&rect.mX >> 32;
  current_rect.mY = rect.mY;
  current_rect.mW = v21;
  v23 = *(_QWORD *)&rect.mW >> 32;
  v24 = rect.mH - 16;
  current_rect.mH = rect.mH - 16;
  v25 = current_rect;
  _mm_store_si128((__m128i *)&rect, (__m128i)current_rect);
  v26 = v7->mTheme.mColourPicker_SwatchBorder.mY;
  v27 = v7->mTheme.mColourPicker_SwatchBorder.mX;
  rect.mX = v27 + (_DWORD)v13;
  rect.mW -= 2 * v27;
  rect.mY += v26;
  rect.mH -= 2 * v26;
  _mm_store_si128((__m128i *)&result, (__m128i)rect);
  v28 = 0;
  v29 = v20 - v7->mTheme.mControlInset.mX - v21;
  rect.mX = v19;
  rect.mY = v22;
  rect.mW = v29;
  rect.mH = (signed int)v23 / ((v4 != 0) + 3);
  v62.mX = v19;
  v62.mY = v22 + rect.mH;
  v62.mW = v29;
  v62.mH = (signed int)v23 / ((v4 != 0) + 3);
  v63.mX = v19;
  v63.mY = v22 + 2 * rect.mH;
  v63.mW = v29;
  v63.mH = (signed int)v23 / ((v4 != 0) + 3);
  v60.mX = v19;
  v60.mY = rect.mH + v22 + 2 * rect.mH;
  v60.mW = v29;
  v60.mH = (signed int)v23 / ((v4 != 0) + 3);
  UFG::DUIContext::ColourBarSliderHSV(v7, 0, &hsv, &rect);
  UFG::DUIContext::ColourBarSliderHSV(v7, HSVComponent_Sat, &hsv, &v62);
  UFG::DUIContext::ColourBarSliderHSV(v7, HSVComponent_Val, &hsv, &v63);
  if ( v4 )
    UFG::DUIContext::ColourBarSlider(v7, "A", &hsv.a, &v60, &UFG::qColour::Black, &UFG::qColour::White);
  UFG::qColourHSVToRGB(v5, &hsv);
  UFG::DUIContext::RenderRoundRect(v7, &current_rect, &v7->mTheme.mColourPicker_SwatchBorderColour, 0);
  v60.mX = LODWORD(v5->r);
  v60.mY = LODWORD(v5->g);
  v60.mW = LODWORD(v5->b);
  v30 = *(float *)&FLOAT_1_0;
  v60.mH = 1065353216;
  UFG::DUIContext::RenderRoundRect(v7, &result, (UFG::qColour *)&v60, 0);
  _mm_store_si128((__m128i *)&current_rect, (__m128i)v25);
  current_rect.mY = v24 + v25.mY;
  current_rect.mH = 16;
  v31 = (__m128)LODWORD(v5->b);
  v32 = FLOAT_255_0;
  if ( v31.m128_f32[0] < 1.0 )
  {
    v31.m128_f32[0] = v31.m128_f32[0] * 256.0;
    v33 = (signed int)v31.m128_f32[0];
    if ( (signed int)v31.m128_f32[0] != 0x80000000 && (float)v33 != v31.m128_f32[0] )
      v31.m128_f32[0] = (float)(v33 - (_mm_movemask_ps(_mm_unpacklo_ps(v31, v31)) & 1));
  }
  else
  {
    v31.m128_f32[0] = FLOAT_255_0;
  }
  v34 = (__m128)LODWORD(v5->g);
  if ( v34.m128_f32[0] < 1.0 )
  {
    v34.m128_f32[0] = v34.m128_f32[0] * 256.0;
    v35 = (signed int)v34.m128_f32[0];
    if ( (signed int)v34.m128_f32[0] != 0x80000000 && (float)v35 != v34.m128_f32[0] )
      v34.m128_f32[0] = (float)(v35 - (_mm_movemask_ps(_mm_unpacklo_ps(v34, v34)) & 1));
  }
  else
  {
    v34.m128_f32[0] = FLOAT_255_0;
  }
  v36 = (__m128)LODWORD(v5->r);
  if ( v36.m128_f32[0] < 1.0 )
  {
    v36.m128_f32[0] = v36.m128_f32[0] * 256.0;
    v37 = (signed int)v36.m128_f32[0];
    if ( (signed int)v36.m128_f32[0] != 0x80000000 && (float)v37 != v36.m128_f32[0] )
      v36.m128_f32[0] = (float)(v37 - (_mm_movemask_ps(_mm_unpacklo_ps(v36, v36)) & 1));
    v32 = v36.m128_f32[0];
  }
  LODWORD(colour_insetL) = (unsigned __int8)(signed int)v31.m128_f32[0];
  UFG::qSPrintf(
    &dest,
    "%02x%02x%02x",
    (unsigned __int8)(signed int)v32,
    (unsigned __int8)(signed int)v34.m128_f32[0],
    colour_insetL);
  UFG::qString::qString(&str_val, &dest);
  v38 = UFG::DUIContext::TakeFocus(v7, &current_rect, &current_rect, 1);
  evaluate = 0;
  v39 = UFG::DUIContext::InternalTextControl(v7, &current_rect, &str_val, v38, 0, &evaluate, 0i64);
  if ( evaluate )
  {
    v7->mCaretPos = 0;
    v7->mHighlightStart = str_val.mLength;
  }
  if ( v7->mFocusedID == v7->mCurrentID )
    v7->mCaretPos = 0;
  if ( v39 )
  {
    v40 = str_val.mData;
    v41 = 0i64;
    if ( *str_val.mData )
    {
      v42 = 35465847073801215i64;
      do
      {
        if ( v41 >= 15 )
          break;
        if ( (unsigned __int8)(*v40 - 48) <= 0x36u && _bittest64(&v42, (char)(*v40 - 48)) )
        {
          *(&dest + v41) = *v40;
          ++v28;
          ++v41;
        }
        ++v40;
      }
      while ( *v40 );
    }
    *(&dest + v28) = 0;
    evaluate = 35;
    v76 = dest;
    v77 = v55;
    v78 = 0;
    v43 = UFG::qToUInt32((const char *)&evaluate, 0);
    text = 35;
    v68 = v56;
    v69 = v57;
    v70 = 0;
    v44 = UFG::qToUInt32(&text, 0);
    v71 = 35;
    v72 = v58;
    v73 = v59;
    v74 = 0;
    v45 = UFG::qToUInt32(&v71, 0);
    v46 = (float)v43 * 0.0039215689;
    if ( v46 <= 0.0 )
    {
      v46 = 0.0;
    }
    else if ( v46 >= 1.0 )
    {
      v46 = *(float *)&FLOAT_1_0;
    }
    v5->r = v46;
    v47 = (float)v44 * 0.0039215689;
    if ( v47 <= 0.0 )
    {
      v47 = 0.0;
    }
    else if ( v47 >= 1.0 )
    {
      v47 = *(float *)&FLOAT_1_0;
    }
    v5->g = v47;
    v48 = (float)v45 * 0.0039215689;
    if ( v48 <= 0.0 )
    {
      v48 = 0.0;
    }
    else if ( v48 >= 1.0 )
    {
      goto LABEL_48;
    }
    v30 = v48;
LABEL_48:
    v5->b = v30;
  }
  v49 = v8 != v5->r || v9 != v5->g || v10 != v5->b || v11 != v5->a;
  UFG::qString::~qString(&str_val);
  return v49;
}v48 <= 0.0 )
    {
      v48 = 0.0;
    }
    else if ( v48 >= 1.0 )
    {
      goto LABEL_48;
    }
    v30 = v

// File Line: 5769
// RVA: 0x194D40
UFG::DUIContext *__fastcall UFG::DUIContext::BeginScrollView(UFG::DUIContext *this, UFG::DUIPoint *current_scroll_pos)
{
  UFG::DUIPoint *v2; // r14
  UFG::DUIContext *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rdx
  int v6; // ecx
  int v7; // er8
  int v8; // er9
  int v9; // er10
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v10; // rax
  int v11; // er15
  int v12; // ebp
  int v13; // er12
  int v14; // er13
  int v15; // er15
  int v16; // er12
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v19; // rax
  UFG::DUIRect scissor_rect; // [rsp+28h] [rbp-40h]
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v22; // [rsp+70h] [rbp+8h]

  v2 = current_scroll_pos;
  v3 = this;
  UFG::DUIContext::GetLayoutRect(this, &scissor_rect, 0, 0);
  v4 = UFG::qMalloc(0xB8ui64, "DUILayoutState", 0x800ui64);
  v5 = v4;
  v6 = scissor_rect.mH;
  v7 = scissor_rect.mW;
  v8 = scissor_rect.mY;
  v9 = scissor_rect.mX;
  if ( v4 )
  {
    v4->mNext = v4;
    v4[1].mNext = v4;
    LODWORD(v4[2].mNext) = v9;
    HIDWORD(v4[2].mNext) = v8;
    LODWORD(v4[3].mNext) = v7;
    HIDWORD(v4[3].mNext) = v6;
    LODWORD(v4[4].mNext) = v9;
    HIDWORD(v4[4].mNext) = v8;
    LODWORD(v4[5].mNext) = v7;
    HIDWORD(v4[5].mNext) = v6;
    v4[6].mNext = 0i64;
    v4[7].mNext = 0i64;
    LODWORD(v4[8].mNext) = 0;
    HIDWORD(v4[8].mNext) = 3;
    LOBYTE(v4[9].mNext) = 0;
    *(UFG::allocator::free_link **)((char *)&v4[9].mNext + 4) = 0i64;
    HIDWORD(v4[10].mNext) = 1;
    LODWORD(v4[11].mNext) = 1;
    v4[12].mNext = 0i64;
    v4[13].mNext = 0i64;
    v4[15].mNext = 0i64;
    v4[16].mNext = 0i64;
    LOBYTE(v4[17].mNext) = 0;
    v4[18].mNext = 0i64;
    v4[19].mNext = 0i64;
    v4[20].mNext = (UFG::allocator::free_link *)-1i64;
    v4[21].mNext = 0i64;
    v4[22].mNext = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v10 = v3->mLayoutStack.mNode.mNext;
  v3->mLayoutStack.mNode.mNext = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v5;
  v5->mNext = (UFG::allocator::free_link *)&v3->mLayoutStack;
  v5[1].mNext = (UFG::allocator::free_link *)v10;
  v10->mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v5;
  v11 = v3->mTheme.mClientInset.mX;
  v12 = v11 + v9;
  scissor_rect.mX = v11 + v9;
  v13 = v3->mTheme.mClientInset.mY;
  v14 = v13 + v8;
  scissor_rect.mY = v13 + v8;
  v15 = v7 + -2 * v11 - v3->mTheme.mScrollbarW;
  scissor_rect.mW = v15;
  v16 = v6 + -2 * v13 - v3->mTheme.mScrollbarH;
  scissor_rect.mH = v16;
  v17 = UFG::qMalloc(0xB8ui64, "DUILayoutState", 0x800ui64);
  v18 = v17;
  if ( v17 )
  {
    v17->mNext = v17;
    v17[1].mNext = v17;
    LODWORD(v17[2].mNext) = v12;
    HIDWORD(v17[2].mNext) = v14;
    LODWORD(v17[3].mNext) = v15;
    HIDWORD(v17[3].mNext) = v16;
    LODWORD(v17[4].mNext) = v12;
    HIDWORD(v17[4].mNext) = v14;
    LODWORD(v17[5].mNext) = v15;
    HIDWORD(v17[5].mNext) = v16;
    v17[6].mNext = 0i64;
    v17[7].mNext = 0i64;
    LODWORD(v17[8].mNext) = 0;
    HIDWORD(v17[8].mNext) = 3;
    LOBYTE(v17[9].mNext) = 1;
    *(UFG::allocator::free_link **)((char *)&v17[9].mNext + 4) = 0i64;
    HIDWORD(v17[10].mNext) = 1;
    LODWORD(v17[11].mNext) = 1;
    v17[12].mNext = 0i64;
    v17[13].mNext = 0i64;
    v17[15].mNext = 0i64;
    v17[16].mNext = 0i64;
    LOBYTE(v17[17].mNext) = 0;
    v17[18].mNext = 0i64;
    v17[19].mNext = 0i64;
    v17[20].mNext = (UFG::allocator::free_link *)-1i64;
    v17[21].mNext = 0i64;
    v17[22].mNext = 0i64;
  }
  else
  {
    v18 = 0i64;
  }
  v19 = v3->mLayoutStack.mNode.mNext;
  v3->mLayoutStack.mNode.mNext = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v18;
  v18->mNext = (UFG::allocator::free_link *)&v3->mLayoutStack;
  v18[1].mNext = (UFG::allocator::free_link *)v19;
  v19->mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v18;
  UFG::DUIContext::PushScissor(v3, &scissor_rect);
  LODWORD(v22) = -v2->mX;
  HIDWORD(v22) = -v2->mY;
  v3->mLayoutStack.mNode.mNext[9].mNext = v22;
  v3->mLayoutStack.mNode.mNext[7].mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v2;
  return v3;
}

// File Line: 5790
// RVA: 0x197E00
UFG::DUIContext *__fastcall UFG::DUIContext::EndScrollView(UFG::DUIContext *this)
{
  UFG::DUILayoutState *v1; // rbx
  UFG::DUIContext *v2; // rsi
  int *v3; // r14
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v4; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v5; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v6; // r10
  int v7; // er9
  int v8; // ecx
  int v9; // er8
  int v10; // edx
  int v11; // er12
  int v12; // ebx
  int v13; // er15
  int v14; // ecx
  int v15; // edi^4
  int visible; // er12
  int v17; // eax
  int max; // er9
  int v19; // edi
  int v20; // er13
  int v21; // edx
  int v22; // edx
  int v23; // ecx
  int v24; // ebp
  int v25; // ecx
  int v26; // edx
  bool v27; // al
  bool v28; // zf
  int v29; // er9
  UFG::DUIContextVtbl *v30; // rdx
  int v31; // ecx
  int v32; // er8
  int v33; // ecx
  int v34; // eax
  int v35; // eax
  UFG::DUIRect rect; // [rsp+40h] [rbp-48h]
  UFG::DUIRect v38; // [rsp+50h] [rbp-38h]

  v1 = (UFG::DUILayoutState *)this->mLayoutStack.mNode.mNext;
  v2 = this;
  v3 = (int *)v1->mScrollViewPosition;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&v1->mPrev;
  if ( v1->mClip )
    UFG::DUIContext::PopScissor(this);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)v2->mLayoutStack.mNode.mNext != &v2->mLayoutStack
    && v2->mCurrentCompositeLayer != 1 )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&v2->mLayoutStack.mNode.mNext[3], &v1->mMaximumRect);
  }
  UFG::DUILayoutState::~DUILayoutState(v1);
  operator delete[](v1);
  v6 = v2->mLayoutStack.mNode.mNext;
  v7 = v2->mTheme.mClientInset.mX;
  v8 = (int)v6[2].mPrev;
  v9 = v2->mTheme.mScrollbarW;
  v10 = v2->mTheme.mScrollbarH;
  v11 = (int)v6[2].mNext;
  v12 = HIDWORD(v6[3].mNext);
  rect.mY = HIDWORD(v6[2].mPrev);
  v13 = v7 + v8;
  rect.mH = HIDWORD(v6[2].mNext);
  rect.mX = v8;
  v14 = v2->mTheme.mClientInset.mY;
  rect.mW = v11;
  v15 = rect.mH;
  rect.mH = v10;
  visible = v11 - 2 * v7 - v9;
  v17 = v7 + visible;
  max = (int)v6[3].mNext;
  v19 = v15 - 2 * v14 - v10;
  v20 = v14 + rect.mY;
  v21 = (int)v6[3].mNext;
  v38.mW = v9;
  v22 = v21 - visible;
  v38.mX = v13 + v17;
  if ( v22 < 0 )
    v22 = 0;
  v23 = 0;
  rect.mY = v19 + v20;
  if ( *v3 > 0 )
    v23 = *v3;
  v38.mY = v20;
  v38.mH = v19;
  rect.mX = v13;
  if ( v23 < v22 )
    v22 = v23;
  v24 = v12 - v19;
  v25 = 0;
  *v3 = v22;
  v26 = v12 - v19;
  if ( v12 - v19 < 0 )
    v26 = 0;
  if ( v3[1] > 0 )
    v25 = v3[1];
  rect.mW = visible;
  if ( v25 < v26 )
    v26 = v25;
  v3[1] = v26;
  v2->mIsScrollViewDragging = UFG::DUIContext::Scrollbar(v2, &rect, v3, 0, max, visible, Orient_Horizontal);
  v27 = UFG::DUIContext::Scrollbar(v2, &v38, v3 + 1, 0, v12, v19, 0);
  v28 = v2->mFocusedID == -1;
  v2->mIsScrollViewDragging = v27;
  if ( v28 )
  {
    v29 = v2->mInputState.mMousePos.mX;
    v30 = (&v2->vfptr)[2 * ((signed int)v2->mCurrentCompositeLayer + 54i64)];
    v31 = (int)v30[2].UpdateUI;
    if ( v29 >= v31 && v29 <= LODWORD(v30[3].UpdateUI) + v31 )
    {
      v32 = v2->mInputState.mMousePos.mY;
      v33 = HIDWORD(v30[2].UpdateUI);
      if ( v32 >= v33
        && v32 <= HIDWORD(v30[3].UpdateUI) + v33 - 1
        && v29 >= v13
        && v29 <= visible + v13
        && v32 >= v20
        && v32 <= rect.mY - 1
        && !v2->mInputState.mMouseEventHandled )
      {
        v34 = v2->mInputState.mMouseWheelDelta;
        if ( v34 )
        {
          v3[1] -= v34;
          if ( v24 < 0 )
            v24 = 0;
          v35 = 0;
          if ( v3[1] > 0 )
            v35 = v3[1];
          if ( v35 < v24 )
            v24 = v35;
          v3[1] = v24;
          v2->mInputState.mMouseWheelDelta = 0;
        }
      }
    }
  }
  UFG::DUIContext::PopLayoutState(v2);
  return v2;
} = v24;
          v2->mInputState.mMouseWheelDelta = 0;
        }
      }
    }
  }
  UFG::DUIContext::PopLayoutState(v2);
  return v2;

// File Line: 5848
// RVA: 0x195100
UFG::DUIContext *__fastcall UFG::DUIContext::BeginVerticalLayout(UFG::DUIContext *this)
{
  UFG::DUIContext *v1; // rbx
  UFG::DUIRect *v2; // rax
  UFG::DUILayoutState *v3; // rax
  UFG::DUIRect result; // [rsp+20h] [rbp-18h]

  v1 = this;
  v2 = UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v3 = UFG::DUIContext::PushLayoutState(v1, v2, LayoutFlag_FillLastCol);
  *(_QWORD *)&v3->mNumCols = 1i64;
  v3->mColWidths = 0i64;
  v3->mRowHeights = 0i64;
  return v1;
}

// File Line: 5860
// RVA: 0x194C00
UFG::DUIContext *__fastcall UFG::DUIContext::BeginLayoutHorizontal(UFG::DUIContext *this)
{
  UFG::DUIContext *v1; // rbx

  v1 = this;
  UFG::DUIContext::BeginGridLayout(this, 0, 1, 0i64, 0i64, 0);
  return v1;
}

// File Line: 5872
// RVA: 0x194650
UFG::DUIContext *__fastcall UFG::DUIContext::BeginGridLayout(UFG::DUIContext *this, int num_cols, int num_rows, int flags)
{
  int v4; // edi
  int v5; // ebx
  int v6; // esi
  UFG::DUIContext *v7; // rbp
  UFG::DUIRect *v8; // rax
  UFG::DUILayoutState *v9; // rax
  UFG::DUIRect result; // [rsp+20h] [rbp-18h]

  v4 = num_cols;
  v5 = flags;
  v6 = num_rows;
  v7 = this;
  v8 = UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v9 = UFG::DUIContext::PushLayoutState(v7, v8, (UFG::DUI::LayoutFlag)v5);
  v9->mNumRows = v6;
  v9->mNumCols = v4;
  v9->mColWidths = 0i64;
  v9->mRowHeights = 0i64;
  return v7;
}

// File Line: 5878
// RVA: 0x1946C0
UFG::DUIContext *__fastcall UFG::DUIContext::BeginGridLayout(UFG::DUIContext *this, int num_cols, int num_rows, int *column_widths, int *row_heights, int layout_flags)
{
  __int64 v6; // r14
  int *v7; // r15
  int v8; // edi
  UFG::DUIContext *v9; // rbx
  UFG::DUIRect *v10; // rax
  char v11; // r12
  UFG::DUILayoutState *v12; // rax
  int *v13; // r13
  signed __int64 v14; // rsi
  UFG::DUILayoutState *v15; // rcx
  int v16; // er12
  __int64 v17; // rdi
  int v18; // er13
  __int64 v19; // rsi
  int v20; // edx
  int v21; // er14
  int v22; // edx
  int v23; // ecx
  int v24; // eax
  int v25; // er14
  __int64 v26; // rax
  int v27; // er12
  __int64 v28; // rdi
  __int64 v29; // r15
  int grip_min_h; // er8
  int v31; // ecx
  __m128i v32; // xmm0
  int *v33; // rcx
  int grip_min_w; // edx
  int v35; // eax
  signed int v36; // edx
  int v37; // ecx
  int v38; // eax
  char v39; // dl
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v40; // rcx
  int v41; // er12
  int v42; // edi
  int v43; // eax
  int v44; // eax
  __int64 v45; // r14
  int v46; // er13
  int v47; // er9
  signed __int64 v48; // rax
  UFG::DUIContextVtbl *v49; // rdx
  int v50; // ecx
  int v51; // er8
  int v52; // ecx
  int *v53; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v54; // rax
  int v55; // er12
  int v56; // ecx
  int v57; // er14
  int v58; // edi
  int v59; // eax
  int v60; // er15
  int v61; // er9
  signed __int64 v62; // rax
  UFG::DUIContextVtbl *v63; // rdx
  int v64; // ecx
  int v65; // er8
  int v66; // ecx
  int *v67; // rcx
  int v68; // eax
  UFG::DUIContext *v69; // rax
  int v70; // [rsp+70h] [rbp-69h]
  int v71; // [rsp+70h] [rbp-69h]
  UFG::DUILayoutState *v72; // [rsp+78h] [rbp-61h]
  long double value_y; // [rsp+80h] [rbp-59h]
  long double value_x; // [rsp+88h] [rbp-51h]
  UFG::DUIRect rect; // [rsp+90h] [rbp-49h]
  UFG::DUIRect rect_grip; // [rsp+A0h] [rbp-39h]
  UFG::DUIRect result; // [rsp+B0h] [rbp-29h]
  int xy; // [rsp+130h] [rbp+57h]
  int count; // [rsp+138h] [rbp+5Fh]
  int v80; // [rsp+140h] [rbp+67h]
  int *v81; // [rsp+148h] [rbp+6Fh]

  v81 = column_widths;
  v80 = num_rows;
  count = num_cols;
  v6 = num_cols;
  v7 = column_widths;
  v8 = num_rows;
  v9 = this;
  v10 = UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v11 = layout_flags;
  v12 = UFG::DUIContext::PushLayoutState(v9, v10, (UFG::DUI::LayoutFlag)layout_flags);
  v13 = row_heights;
  v14 = 0i64;
  v15 = v12;
  v72 = v12;
  v70 = v11 & 8;
  if ( v11 & 8 )
  {
    if ( (signed int)v6 > 1 && v7 )
    {
      v16 = 0;
      v17 = 0i64;
      if ( (signed int)v6 > 0 )
      {
        v18 = 0;
        v19 = v6;
        do
        {
          v20 = v9->mTheme.mLayout_SplitterWidth;
          v21 = v16 + v7[v17];
          xy = v16 + v7[v17];
          UFG::DUIContext::GridSplitter(v9, v20, &xy, 0);
          v22 = xy;
          v23 = xy - v16;
          if ( v9->mTheme.mLayout_SplitterWidth + 1 > xy - v16 )
            v23 = v9->mTheme.mLayout_SplitterWidth + 1;
          v24 = count - 1;
          v7[v17] = v23;
          if ( v18 < v24 )
            v7[v17 + 1] += v21 - v22;
          ++v17;
          v16 += v23;
          ++v18;
        }
        while ( v17 < v19 );
        v13 = row_heights;
        v14 = 0i64;
      }
      v11 = layout_flags;
    }
    if ( v80 > 1 && v13 )
    {
      v25 = v14;
      LODWORD(v26) = v80;
      if ( v11 & 2 )
        LODWORD(v26) = v80 - 1;
      v26 = (signed int)v26;
      v27 = 0;
      v28 = 0i64;
      if ( (signed int)v26 > 0i64 )
      {
        v29 = v26;
        do
        {
          grip_min_h = v9->mTheme.mLayout_SplitterWidth;
          v31 = v13[v28];
          value_x = 0.0;
          xy = v25 + v31;
          *(_QWORD *)&rect_grip.mX = 0i64;
          v32 = _mm_cvtsi32_si128(v25 + v31);
          v33 = (int *)v9->mLayoutStack.mNode.mNext;
          *(_QWORD *)&rect_grip.mW = 0i64;
          *(_QWORD *)&value_y = (unsigned __int128)_mm_cvtepi32_pd(v32);
          grip_min_w = v33[6];
          rect.mX = v33[4];
          rect.mY = v33[5];
          v35 = v33[7];
          rect.mW = grip_min_w;
          rect.mH = v35;
          if ( UFG::DUIContext::Draggable2D(
                 v9,
                 &value_x,
                 &value_y,
                 &rect_grip,
                 &rect,
                 0.0,
                 0.0,
                 0.0,
                 (double)(v35 - grip_min_h),
                 1.0,
                 1.0 / (double)v35 * (double)grip_min_h,
                 grip_min_w,
                 grip_min_h,
                 0) )
          {
            v9->mInputState.mMouseWheelDelta = v14;
            *(_QWORD *)&v9->mInputState.mMouseLBWentDown = 0i64;
            *(_WORD *)&v9->mInputState.mLMBDoubleClick = 0;
            v9->mInputState.mMouseMBWentUp = 0;
            v9->mInputState.mMMBDoubleClick = 0;
            v9->mInputState.mMouseEventHandled = 1;
          }
          v36 = (signed int)value_y;
          v37 = (signed int)value_y - v25;
          if ( v9->mTheme.mLayout_SplitterWidth + v9->mTheme.mRowHeight > v37 )
            v37 = v9->mTheme.mLayout_SplitterWidth + v9->mTheme.mRowHeight;
          v38 = v80 - 1;
          v13[v28] = v37;
          if ( v27 < v38 )
            v13[v28 + 1] += xy - v36;
          ++v28;
          v25 += v37;
          ++v27;
        }
        while ( v28 < v29 );
        v7 = v81;
      }
    }
    v15 = v72;
    v8 = v80;
  }
  if ( layout_flags & 4 )
  {
    if ( v7 )
      UFG::RedistributeGridLines(v7, count, v15->mWorkingRect.mW);
    if ( v13 )
      UFG::RedistributeGridLines(v13, v8, v72->mWorkingRect.mH);
  }
  if ( v70 )
  {
    v39 = layout_flags;
    if ( v7 )
    {
      v40 = v9->mLayoutStack.mNode.mNext;
      v41 = HIDWORD(v40[1].mPrev);
      v42 = (int)v40[1].mPrev;
      rect.mW = (int)v40[1].mNext;
      v43 = HIDWORD(v40[1].mNext);
      xy = v43;
      rect.mH = v43;
      v71 = v9->mTheme.mLayout_SplitterWidth;
      rect.mW = v9->mTheme.mLayout_SplitterWidth;
      rect.mY = v41;
      v44 = count;
      if ( layout_flags & 1 )
        v44 = count - 1;
      v45 = 0i64;
      *(_QWORD *)&value_x = v44;
      if ( v44 > 0i64 )
      {
        v46 = xy;
        do
        {
          v42 += v7[v45];
          v47 = v9->mInputState.mMousePos.mX;
          v48 = (signed int)v9->mCurrentCompositeLayer + 54i64;
          rect.mX = v42;
          v49 = (&v9->vfptr)[2 * v48];
          v50 = (int)v49[2].UpdateUI;
          if ( v47 < v50
            || v47 > LODWORD(v49[3].UpdateUI) + v50
            || (v51 = v9->mInputState.mMousePos.mY, v52 = HIDWORD(v49[2].UpdateUI), v51 < v52)
            || v51 > HIDWORD(v49[3].UpdateUI) + v52 - 1
            || v47 < v42
            || v47 > v42 + v71
            || v51 < v41
            || v51 > v41 + v46 - 1
            || (v53 = (int *)&v9->mTheme.mColour[12], v9->mInputState.mMouseEventHandled) )
          {
            v53 = (int *)&v9->mTheme.mColour[17];
          }
          rect_grip.mX = *v53;
          rect_grip.mY = v53[1];
          rect_grip.mW = v53[2];
          rect_grip.mH = v53[3];
          UFG::DUIContext::RenderRect(v9, &rect, (UFG::qColour *)&rect_grip, 0);
          ++v45;
        }
        while ( v45 < *(_QWORD *)&value_x );
        v13 = row_heights;
        v39 = layout_flags;
        v14 = 0i64;
      }
    }
    if ( v13 )
    {
      v54 = v9->mLayoutStack.mNode.mNext;
      v55 = v9->mTheme.mLayout_SplitterWidth;
      v56 = (int)v54[1].mNext;
      v57 = (int)v54[1].mPrev;
      v58 = HIDWORD(v54[1].mPrev);
      LODWORD(v54) = HIDWORD(v54[1].mNext);
      layout_flags = v56;
      rect.mW = v56;
      rect.mX = v57;
      rect.mH = v55;
      v59 = v80;
      if ( v39 & 2 )
        v59 = v80 - 1;
      row_heights = (int *)v59;
      if ( v59 > 0i64 )
      {
        v60 = layout_flags;
        do
        {
          v58 += v13[v14];
          v61 = v9->mInputState.mMousePos.mX;
          v62 = (signed int)v9->mCurrentCompositeLayer + 54i64;
          rect.mY = v58;
          v63 = (&v9->vfptr)[2 * v62];
          v64 = (int)v63[2].UpdateUI;
          if ( v61 < v64
            || v61 > LODWORD(v63[3].UpdateUI) + v64
            || (v65 = v9->mInputState.mMousePos.mY, v66 = HIDWORD(v63[2].UpdateUI), v65 < v66)
            || v65 > HIDWORD(v63[3].UpdateUI) + v66 - 1
            || v61 < v57
            || v61 > v60 + v57
            || v65 < v58
            || v65 > v58 + v55 - 1
            || (v67 = (int *)&v9->mTheme.mColour[12], v9->mInputState.mMouseEventHandled) )
          {
            v67 = (int *)&v9->mTheme.mColour[17];
          }
          rect_grip.mX = *v67;
          rect_grip.mY = v67[1];
          rect_grip.mW = v67[2];
          rect_grip.mH = v67[3];
          UFG::DUIContext::RenderRect(v9, &rect, (UFG::qColour *)&rect_grip, 0);
          ++v14;
        }
        while ( v14 < (signed __int64)row_heights );
        v7 = v81;
      }
    }
  }
  v72->mNumCols = count;
  v68 = v80;
  v72->mColWidths = v7;
  v72->mNumRows = v68;
  v69 = v9;
  v72->mRowHeights = v13;
  return v69;
}

// File Line: 6012
// RVA: 0x198190
UFG::DUIContext *__fastcall UFG::DUIContext::EndLayoutHorizontal(UFG::DUIContext *this)
{
  UFG::DUIContext *v1; // rbx

  v1 = this;
  UFG::DUIContext::PopLayoutState(this);
  return v1;
}

// File Line: 6051
// RVA: 0x193B60
void __fastcall UFG::DUIContext::AdjustWindowsToScreen(UFG::DUIContext *this, UFG::DUIRect *prevRect)
{
  UFG::DUIRect *v2; // r15
  UFG::DUIContext *v3; // rbp
  UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *v4; // rsi
  int v5; // kr00_4
  UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **v6; // r13
  UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **v7; // rsi
  __int64 v8; // kr08_8
  const char *v9; // rdx
  int *v10; // rdi
  int v11; // er14
  int v12; // edx
  int v13; // er8
  char v14; // al
  signed __int64 v15; // rcx
  bool v16; // zf
  __int64 v17; // rcx
  __int64 v18; // rcx
  int v19; // er12
  int v20; // er8
  int v21; // ebx
  int v22; // edx
  int v23; // er8
  int v24; // ecx
  int v25; // ecx
  int v26; // ecx
  int v27; // ecx
  int v28; // ecx
  UFG::DUIRect rect; // [rsp+20h] [rbp-78h]
  UFG::DUIRect v30; // [rsp+30h] [rbp-68h]
  UFG::DUIRect v31; // [rsp+40h] [rbp-58h]
  UFG::DUIRect v32; // [rsp+50h] [rbp-48h]
  int v33; // [rsp+A0h] [rbp+8h]
  int v34; // [rsp+A8h] [rbp+10h]

  v2 = prevRect;
  v3 = this;
  v4 = this->mWindowFrontStack.mNode.mNext;
  v5 = prevRect->mW;
  *(_QWORD *)&rect.mX = 0i64;
  v6 = &this->mThemeColourModifier[17].mNode.mNext;
  v7 = (UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **)&v4[-7].mNext;
  v8 = prevRect->mH;
  rect.mW = v5 / 2;
  rect.mH = ((signed int)v8 - HIDWORD(v8)) >> 1;
  _mm_store_si128((__m128i *)&v30, (__m128i)rect);
  _mm_store_si128((__m128i *)&v31, (__m128i)rect);
  v30.mY = ((signed int)v8 - HIDWORD(v8)) >> 1;
  v31.mX = v5 / 2;
  _mm_store_si128((__m128i *)&v32, (__m128i)v30);
  v32.mX = v5 / 2;
  if ( v7 != &this->mThemeColourModifier[17].mNode.mNext
    || (v7 = (UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **)&this->mWindowStack.mNode.mNext[-7].mNext,
        v7 != &this->mThemeColourModifier[16].mNode.mNext) )
  {
    if ( v7 )
    {
      do
      {
        if ( *((_BYTE *)v7 + 152) )
        {
          v9 = (const char *)(*((_DWORD *)v7 + 46) ? v7[22] : &customWorldMapCaption);
          if ( !v9 || !*v9 || UFG::DUIManager::GetGroupData(v3->mManager, v9) != 0i64 )
          {
            v10 = (int *)(v7 + 17);
            v11 = *((_DWORD *)v7 + 34);
            if ( v11 || *((_DWORD *)v7 + 36) != v2->mW )
            {
              v19 = *((_DWORD *)v7 + 35);
              if ( v19 || *((_DWORD *)v7 + 37) != v2->mH )
              {
                v21 = UFG::DUIRect::OverlappedArea((UFG::DUIRect *)(v7 + 17), &rect);
                v34 = UFG::DUIRect::OverlappedArea((UFG::DUIRect *)(v7 + 17), &v31);
                v33 = UFG::DUIRect::OverlappedArea((UFG::DUIRect *)(v7 + 17), &v32);
                v22 = UFG::DUIRect::OverlappedArea((UFG::DUIRect *)(v7 + 17), &v30);
                v23 = v22;
                if ( v33 > v22 )
                  v22 = v33;
                v24 = v34;
                if ( v21 > v34 )
                  v24 = v21;
                if ( v24 > v22 )
                  v22 = v24;
                if ( v22 != v21 )
                {
                  if ( v22 == v34 )
                  {
                    v25 = v11 - v2->mW + v3->mRect.mW;
                    *v10 = v25;
                    if ( v3->mRect.mW - *((_DWORD *)v7 + 36) < v25 )
                      v25 = v3->mRect.mW - *((_DWORD *)v7 + 36);
                    *v10 = v25;
                  }
                  else if ( v22 == v33 )
                  {
                    v26 = v11 - v2->mW + v3->mRect.mW;
                    *v10 = v26;
                    if ( v3->mRect.mW - *((_DWORD *)v7 + 36) < v26 )
                      v26 = v3->mRect.mW - *((_DWORD *)v7 + 36);
                    *v10 = v26;
                    *((_DWORD *)v7 + 35) += v3->mRect.mH - v2->mH;
                    v27 = *((_DWORD *)v7 + 35);
                    if ( v3->mRect.mH - *((_DWORD *)v7 + 37) < v27 )
                      v27 = v3->mRect.mH - *((_DWORD *)v7 + 37);
                    *((_DWORD *)v7 + 35) = v27;
                  }
                  else if ( v22 == v23 )
                  {
                    v28 = v19 - v2->mH + v3->mRect.mH;
                    *((_DWORD *)v7 + 35) = v28;
                    if ( v3->mRect.mH - *((_DWORD *)v7 + 37) < v28 )
                      v28 = v3->mRect.mH - *((_DWORD *)v7 + 37);
                    *((_DWORD *)v7 + 35) = v28;
                  }
                }
              }
              else
              {
                *((_DWORD *)v7 + 37) = v3->mRect.mH;
                v20 = v2->mW;
                if ( v11 + *((_DWORD *)v7 + 36) == v20 )
                  *v10 = v11 + v3->mRect.mW - v20;
              }
            }
            else
            {
              v12 = *((_DWORD *)v7 + 35);
              *((_DWORD *)v7 + 36) = v3->mRect.mW;
              v13 = v2->mH;
              if ( v12 + *((_DWORD *)v7 + 37) == v13 )
                *((_DWORD *)v7 + 35) = v12 + v3->mRect.mH - v13;
            }
          }
        }
        v14 = 0;
        v15 = (signed __int64)&v3->mWindowFrontStack.mNode.mNext[-7].mNext;
        if ( (UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **)v15 == v6 )
        {
LABEL_20:
          v15 = (signed __int64)&v3->mWindowStack.mNode.mNext[-7].mNext;
          if ( (UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **)v15 == &v3->mThemeColourModifier[16].mNode.mNext )
            return;
          while ( !v14 )
          {
            v16 = v7 == (UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **)v15;
            v18 = *(_QWORD *)(v15 + 112);
            v14 = 0;
            if ( v16 )
              v14 = 1;
            v15 = v18 - 104;
            if ( (UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **)v15 == &v3->mThemeColourModifier[16].mNode.mNext )
              return;
          }
        }
        else
        {
          while ( !v14 )
          {
            v16 = v7 == (UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **)v15;
            v17 = *(_QWORD *)(v15 + 112);
            v14 = 0;
            if ( v16 )
              v14 = 1;
            v15 = v17 - 104;
            if ( (UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **)v15 == v6 )
              goto LABEL_20;
          }
        }
        v7 = (UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **)v15;
      }
      while ( v15 );
    }
  }
}

// File Line: 6137
// RVA: 0x19DA30
void __fastcall UFG::DUIContext::SetOverallRect(UFG::DUIContext *this, UFG::DUIRect *rect)
{
  UFG::DUIRect prevRect; // [rsp+20h] [rbp-18h]

  if ( *(_QWORD *)&this->mRect.mW != *(_QWORD *)&rect->mW )
  {
    prevRect.mX = this->mRect.mX;
    prevRect.mY = this->mRect.mY;
    prevRect.mW = this->mRect.mW;
    prevRect.mH = this->mRect.mH;
    this->mRect.mX = rect->mX;
    this->mRect.mY = rect->mY;
    this->mRect.mW = rect->mW;
    this->mRect.mH = rect->mH;
    *(_QWORD *)&this->mRect.mX = 0i64;
    UFG::DUIContext::AdjustWindowsToScreen(this, &prevRect);
  }
}

