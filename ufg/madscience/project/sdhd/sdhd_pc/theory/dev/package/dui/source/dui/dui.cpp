// File Line: 95
// RVA: 0x192BB0
void __fastcall UFG::DUISuggestionBoxWindow::DUISuggestionBoxWindow(
        UFG::DUISuggestionBoxWindow *this,
        MemImageLoadFlag f)
{
  UFG::qString *mOptions; // rcx
  unsigned int *p_mStringHash32; // rbx

  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUISuggestionBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUISuggestionBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mStyle = Style_None;
  mOptions = this->mOptions;
  if ( mOptions )
  {
    p_mStringHash32 = &mOptions[-1].mStringHash32;
    `eh vector destructor iterator(
      mOptions,
      0x28ui64,
      mOptions[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
    this->mOptions = 0i64;
  }
  *(_QWORD *)&this->mOptionCount = 0i64;
  this->mHasDialogResult = 0;
  this->mDialogResult = -1i64;
}

// File Line: 123
// RVA: 0x1929A0
void __fastcall UFG::DUIMessageBoxWindow::DUIMessageBoxWindow(UFG::DUIMessageBoxWindow *this, MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIMessageBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIMessageBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&this->mMessage);
  this->mOptions.mNode.mPrev = &this->mOptions.mNode;
  this->mOptions.mNode.mNext = &this->mOptions.mNode;
  this->mStyle = Style_ShowBorder;
}

// File Line: 145
// RVA: 0x1926E0
void __fastcall UFG::DUIInfoBoxWindow::DUIInfoBoxWindow(UFG::DUIInfoBoxWindow *this, MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::DUIInfoBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIInfoBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIInfoBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIInfoBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::DUIInfoBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIInfoBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIInfoBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIInfoBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&this->mMessage);
  this->mStyle = Style_Toolbar;
  this->mRect.mW = 300;
  this->mRect.mH = 100;
}

// File Line: 173
// RVA: 0x1925C0
void __fastcall UFG::DUIComboBoxWindow::DUIComboBoxWindow(UFG::DUIComboBoxWindow *this, MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mOptions.mNode.mPrev = &this->mOptions.mNode;
  this->mOptions.mNode.mNext = &this->mOptions.mNode;
  this->mStyle = Style_None;
  UFG::DUIComboBoxWindow::SetData(this, 0, &this->mOptions, 0, 0i64);
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
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::DUIWindow>,
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
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::DUIMessageBoxWindow>,
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
    &UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::sInventory,
    "UFG::DUIComboBoxWindow",
    v0);
  UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::DUIComboBoxWindow>::`vftable;
  UFG::qReflectInventory<UFG::DUIComboBoxWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::DUIComboBoxWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 187
// RVA: 0x1469180
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::DUIPopupMenuWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::DUIPopupMenuWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::sInventory,
    "UFG::DUIPopupMenuWindow",
    v0);
  UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::DUIPopupMenuWindow>::`vftable;
  UFG::qReflectInventory<UFG::DUIPopupMenuWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::DUIPopupMenuWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 188
// RVA: 0x1469200
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::DUISuggestionBoxWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::DUISuggestionBoxWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::sInventory,
    "UFG::DUISuggestionBoxWindow",
    v0);
  UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::DUISuggestionBoxWindow>::`vftable;
  UFG::qReflectInventory<UFG::DUISuggestionBoxWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::DUISuggestionBoxWindow_UFG::DUIWindow_::sInventory__);
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
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::DUIInfoBoxWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 212
// RVA: 0x195150
void __fastcall UFG::BuildCommandKeyString(UFG::Command *command, UFG::qString *out_string)
{
  UFG::qTree64Base *v3; // rax
  UFG::qTree64Base *v4; // rbx
  const char *v5; // rax
  const char *v6; // rax
  const char *v7; // rax
  int v8; // ecx
  const char *v9; // rax

  v3 = UFG::qTree64Base::Get(&command->mManager->mActiveBindingMap->mKeyBindings.mTree, command->mBaseNode.mUID);
  v4 = v3;
  if ( v3 )
  {
    if ( (BYTE4(v3[1].mHead.mNeighbours[0]) & 1) != 0 )
    {
      v5 = UFG::MapInputVKeyToString(17);
      UFG::qString::Set(out_string, v5);
      UFG::qString::operator+=(out_string, "+");
    }
    if ( (BYTE4(v4[1].mHead.mNeighbours[0]) & 2) != 0 )
    {
      v6 = UFG::MapInputVKeyToString(16);
      UFG::qString::operator+=(out_string, v6);
      UFG::qString::operator+=(out_string, "+");
    }
    if ( (BYTE4(v4[1].mHead.mNeighbours[0]) & 4) != 0 )
    {
      v7 = UFG::MapInputVKeyToString(18);
      UFG::qString::operator+=(out_string, v7);
      UFG::qString::operator+=(out_string, "+");
    }
    v8 = (int)v4[1].mHead.mNeighbours[0];
    if ( v8 )
    {
      v9 = UFG::MapInputVKeyToString(v8);
      UFG::qString::operator+=(out_string, v9);
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
void __fastcall UFG::DUILayoutState::DUILayoutState(
        UFG::DUILayoutState *this,
        UFG::DUIRect *working,
        UFG::DUI::LayoutFlag flags,
        bool clip)
{
  this->mPrev = this;
  this->mNext = this;
  this->mWorkingRect = *working;
  this->mCurrentRect = *working;
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
  UFG::DUIIntArray *mAccumulatedItems; // rdi
  unsigned __int64 *p; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mPrev; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // rax

  mAccumulatedItems = this->mAccumulatedItems;
  if ( mAccumulatedItems )
  {
    p = mAccumulatedItems->mData.p;
    if ( p )
      operator delete[](p);
    mAccumulatedItems->mData.p = 0i64;
    *(_QWORD *)&mAccumulatedItems->mData.size = 0i64;
    operator delete[](mAccumulatedItems);
  }
  this->mAccumulatedItems = 0i64;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 550
// RVA: 0x199420
void __fastcall UFG::DUIWindow::Init(UFG::DUIWindow *this)
{
  int mH; // eax
  unsigned int v3; // ebx
  unsigned int v4; // ebx

  UFG::DUIWindow::NoSerializeInit(this);
  *(_QWORD *)&this->mRect.mX = 0i64;
  this->mRect.mW = 200;
  this->mRect.mH = 300;
  mH = this->mRect.mH;
  this->mIsExpanded = 1;
  this->mPrevHeight = mH;
  *(_WORD *)&this->mVisible = 1;
  v3 = UFG::qStringLength(&customCaption) + 1;
  UFG::qReflectArray<char>::Resize(&this->mGroupTag.mText, v3, "qReflectString::Set()");
  UFG::qMemCopy(this->mGroupTag.mText.mData.mItems, &customCaption, v3);
  v4 = UFG::qStringLength(&customCaption) + 1;
  UFG::qReflectArray<char>::Resize(&this->mSurfaceName.mText, v4, "qReflectString::Set()");
  UFG::qMemCopy(this->mSurfaceName.mText.mData.mItems, &customCaption, v4);
  this->mLastID = -1;
}

// File Line: 568
// RVA: 0x19A6E0
void __fastcall UFG::DUIWindow::NoSerializeInit(UFG::DUIWindow *this)
{
  char *Name; // rax

  Name = UFG::qReflectObject::GetName(this);
  UFG::qString::Set(&this->mTitle, Name);
  *(_QWORD *)&this->mLastUpdateDuation = 0i64;
  *(_QWORD *)&this->mClientRect.mY = 0i64;
  this->mMode = F5_1Pt2_512;
  this->mStyle = Style_Default;
  this->mMinSize = (UFG::DUIPoint)0x50000000C8i64;
  *(_WORD *)&this->mInFocus = 0;
  this->mBringToFont = 0;
  *(_WORD *)&this->mIsModal = 0;
  this->mDialogResult = -1i64;
  *(_QWORD *)&this->mClientRect.mH = 0i64;
  this->mSurface = 0i64;
  this->mIsInitialUpdate = 1;
}

// File Line: 1059
// RVA: 0x192A20
void __fastcall UFG::DUIMessageBoxWindow::DUIMessageBoxWindow(UFG::DUIMessageBoxWindow *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::DUIMessageBoxWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIMessageBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIMessageBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&this->mMessage);
  this->mOptions.mNode.mPrev = &this->mOptions.mNode;
  this->mOptions.mNode.mNext = &this->mOptions.mNode;
  this->mStyle = Style_ShowBorder;
  this->mRect.mW = 400;
}

// File Line: 1065
// RVA: 0x19D8F0
void __fastcall UFG::DUIMessageBoxWindow::SetData(
        UFG::DUIMessageBoxWindow *this,
        const char *title,
        const char *message,
        const char **options)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_mOptions; // rbx
  UFG::DUIMessageBoxWindow *mNext; // rdi
  UFG::qReflectObjectVtbl *vfptr; // rdx
  const char *(__fastcall *mUID)(UFG::qReflectObject *); // rax
  UFG::qString *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx

  p_mOptions = &this->mOptions;
  mNext = (UFG::DUIMessageBoxWindow *)this->mOptions.mNode.mNext;
  if ( mNext != (UFG::DUIMessageBoxWindow *)&this->mOptions )
  {
    do
    {
      vfptr = mNext->UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr;
      mUID = (const char *(__fastcall *)(UFG::qReflectObject *))mNext->mBaseNode.mUID;
      vfptr->GetTypeName = mUID;
      *(_QWORD *)mUID = vfptr;
      mNext->UFG::qReflectObjectType<UFG::DUIMessageBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)mNext;
      mNext->mBaseNode.mUID = (unsigned __int64)mNext;
      UFG::qString::~qString((UFG::qString *)mNext);
      operator delete[](mNext);
      mNext = (UFG::DUIMessageBoxWindow *)p_mOptions->mNode.mNext;
    }
    while ( mNext != (UFG::DUIMessageBoxWindow *)p_mOptions );
  }
  UFG::qString::Set(&this->mTitle, title);
  UFG::qString::Set(&this->mMessage, message);
  this->mHasDialogResult = 0;
  for ( this->mDialogResult = -1i64; *options; p_mOptions->mNode.mPrev = v12 )
  {
    v12 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    if ( v12 )
      UFG::qString::qString(v12, *options++);
    mPrev = p_mOptions->mNode.mPrev;
    mPrev->mNext = v12;
    v12->mPrev = mPrev;
    v12->mNext = &p_mOptions->mNode;
  }
}

// File Line: 1083
// RVA: 0x1A0180
void __fastcall UFG::DUIMessageBoxWindow::UpdateUI(UFG::DUIMessageBoxWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIRect *LayoutRect; // rax
  UFG::DUILayoutState *v5; // rax
  char *mData; // rbx
  unsigned int v7; // esi
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v9; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mPrev; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v11; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v12; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v13; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v14; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v15; // rax
  UFG::DUIRect result; // [rsp+38h] [rbp-40h] BYREF

  LayoutRect = UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(dui, LayoutRect, LayoutFlag_FillLastCol);
  *(_QWORD *)&v5->mNumCols = 1i64;
  v5->mColWidths = 0i64;
  v5->mRowHeights = 0i64;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  mData = this->mMessage.mData;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(dui, &result);
  UFG::DUIContext::RenderText(dui, &result, dui->mTheme.mColour, mData, 0x10u);
  UFG::DUIContext::PopScissor(dui);
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v7 = 0;
  mNext = this->mOptions.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::qString,UFG::qString> *)&this->mOptions )
  {
    while ( !UFG::DUIContext::Button(dui, (const char *)mNext[1].mNext, 0x10u) )
    {
      ++v7;
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::qString,UFG::qString> *)&this->mOptions )
        goto LABEL_6;
    }
    this->mHasDialogResult = 1;
    this->mDialogResult = v7;
  }
LABEL_6:
  v9 = dui->mLayoutStack.mNode.mNext;
  mPrev = v9->mPrev;
  v11 = v9->mNext;
  mPrev->mNext = v11;
  v11->mPrev = mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  if ( LOBYTE(v9[4].mNext) )
    UFG::DUIContext::PopScissor(dui);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)dui->mLayoutStack.mNode.mNext != &dui->mLayoutStack
    && dui->mCurrentCompositeLayer != CompositeLayer_Overlay )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&dui->mLayoutStack.mNode.mNext[3], (UFG::DUIRect *)&v9[3]);
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
  UFG::DUIRect *LayoutRect; // rax
  UFG::DUILayoutState *v5; // rax
  char *mData; // rbx
  UFG::DUIRect result; // [rsp+30h] [rbp-18h] BYREF

  LayoutRect = UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(dui, LayoutRect, LayoutFlag_FillLastCol);
  *(_QWORD *)&v5->mNumCols = 1i64;
  v5->mColWidths = 0i64;
  v5->mRowHeights = 0i64;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  mData = this->mMessage.mData;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(dui, &result);
  UFG::DUIContext::RenderText(dui, &result, dui->mTheme.mColour, mData, 0x10u);
  UFG::DUIContext::PopScissor(dui);
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  UFG::DUIContext::BeginGridLayout(dui, 3, 1, 0i64, 0i64, LayoutFlag_None);
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  if ( UFG::DUIContext::Button(dui, "OK", 0x12u) && !this->mMarkedToDestroy )
    this->mMarkedToDestroy = 1;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  UFG::DUIContext::PopLayoutState(dui);
  UFG::DUIContext::PopLayoutState(dui);
}

// File Line: 1154
// RVA: 0x192640
void __fastcall UFG::DUIComboBoxWindow::DUIComboBoxWindow(UFG::DUIComboBoxWindow *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::DUIComboBoxWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mOptions.mNode.mPrev = &this->mOptions.mNode;
  this->mOptions.mNode.mNext = &this->mOptions.mNode;
  this->mToolTips = 0i64;
  this->mStyle = Style_None;
  UFG::DUIComboBoxWindow::SetData(this, 0, &this->mOptions, 0, 0i64);
}

// File Line: 1160
// RVA: 0x193050
void __fastcall UFG::DUIComboBoxWindow::~DUIComboBoxWindow(UFG::DUIComboBoxWindow *this)
{
  UFG::qString *mToolTips; // rcx
  unsigned int *p_mStringHash32; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax

  this->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIComboBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  mToolTips = this->mToolTips;
  if ( mToolTips )
  {
    p_mStringHash32 = &mToolTips[-1].mStringHash32;
    `eh vector destructor iterator(
      mToolTips,
      0x28ui64,
      mToolTips[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&this->mOptions);
  mPrev = this->mOptions.mNode.mPrev;
  mNext = this->mOptions.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mOptions.mNode.mPrev = &this->mOptions.mNode;
  this->mOptions.mNode.mNext = &this->mOptions.mNode;
  UFG::DUIWindow::~DUIWindow(this);
}

// File Line: 1168
// RVA: 0x19D700
void __fastcall UFG::DUIComboBoxWindow::SetData(
        UFG::DUIComboBoxWindow *this,
        int current_value,
        UFG::qString *options,
        unsigned int count,
        const char **tooltips)
{
  unsigned __int64 v5; // r12
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_mOptions; // rsi
  UFG::DUIComboBoxWindow *mNext; // rbx
  UFG::qReflectObjectVtbl *vfptr; // rcx
  const char *(__fastcall *mUID)(UFG::qReflectObject *); // rax
  __int64 v13; // rdi
  unsigned int v14; // ebp
  UFG::qString *i; // rbx
  UFG::qString *v16; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  UFG::qString *mToolTips; // rcx
  unsigned int *p_mStringHash32; // rbx
  const char **v22; // rbx
  unsigned __int64 v23; // rsi
  __int64 v24; // rax
  bool v25; // cf
  unsigned __int64 v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::qString *v28; // rbp

  v5 = count;
  p_mOptions = &this->mOptions;
  mNext = (UFG::DUIComboBoxWindow *)this->mOptions.mNode.mNext;
  if ( mNext != (UFG::DUIComboBoxWindow *)&this->mOptions )
  {
    do
    {
      vfptr = mNext->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr;
      mUID = (const char *(__fastcall *)(UFG::qReflectObject *))mNext->mBaseNode.mUID;
      vfptr->GetTypeName = mUID;
      *(_QWORD *)mUID = vfptr;
      mNext->UFG::qReflectObjectType<UFG::DUIComboBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)mNext;
      mNext->mBaseNode.mUID = (unsigned __int64)mNext;
      UFG::qString::~qString((UFG::qString *)mNext);
      operator delete[](mNext);
      mNext = (UFG::DUIComboBoxWindow *)p_mOptions->mNode.mNext;
    }
    while ( mNext != (UFG::DUIComboBoxWindow *)p_mOptions );
  }
  v13 = 0i64;
  v14 = 0;
  for ( i = (UFG::qString *)options->mNext; i != options; i = (UFG::qString *)i->mNext )
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
    mPrev = p_mOptions->mNode.mPrev;
    mPrev->mNext = v18;
    v18->mPrev = mPrev;
    v18->mNext = &p_mOptions->mNode;
    p_mOptions->mNode.mPrev = v18;
    ++v14;
  }
  mToolTips = this->mToolTips;
  if ( mToolTips )
  {
    p_mStringHash32 = &mToolTips[-1].mStringHash32;
    `eh vector destructor iterator(
      mToolTips,
      0x28ui64,
      mToolTips[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
    this->mToolTips = 0i64;
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
      v28 = (UFG::qString *)&v27[1];
      `eh vector constructor iterator(&v27[1], 0x28ui64, v5, (void (__fastcall *)(void *))UFG::qString::qString);
    }
    else
    {
      v28 = 0i64;
    }
    this->mToolTips = v28;
    if ( (_DWORD)v5 )
    {
      do
      {
        UFG::qString::Set(&this->mToolTips[v13++], *v22++);
        --v23;
      }
      while ( v23 );
    }
  }
  this->mValue = current_value;
  this->mHasDialogResult = 0;
  this->mDialogResult = -1i64;
}

// File Line: 1201
// RVA: 0x19F910
void __fastcall UFG::DUIComboBoxWindow::UpdateUI(UFG::DUIComboBoxWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIRect *LayoutRect; // rax
  UFG::DUILayoutState *v5; // rax
  int v6; // edi
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // r13
  __int64 v8; // r14
  int mY; // edx
  int mX; // ecx
  int v11; // esi
  bool v12; // r12
  int v13; // edi
  int v14; // ecx
  int mH; // r14d
  int mW; // r11d
  int v17; // r10d
  int v18; // ecx
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v19; // r8
  int v20; // r9d
  int mPrev; // ecx
  int v22; // edx
  int mPrev_high; // ecx
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v24; // r8
  int v25; // r9d
  int v26; // ecx
  int v27; // edx
  int v28; // ecx
  int *v29; // rcx
  UFG::qColour *p_colour; // r8
  UFG::qString *mToolTips; // rdx
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v32; // r8
  int v33; // r9d
  int v34; // ecx
  int v35; // edx
  int v36; // ecx
  int v37; // ecx
  int v38; // ecx
  __int64 mValue; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v40; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v41; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v42; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v43; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v44; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v45; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v46; // rax
  UFG::DUIRect current_rect; // [rsp+40h] [rbp-49h] BYREF
  UFG::DUIRect v48; // [rsp+50h] [rbp-39h]
  int v49[4]; // [rsp+60h] [rbp-29h] BYREF
  int v50[4]; // [rsp+70h] [rbp-19h] BYREF
  int v51[4]; // [rsp+80h] [rbp-9h] BYREF
  UFG::qColour colour; // [rsp+90h] [rbp+7h] BYREF
  UFG::DUIRect result; // [rsp+A0h] [rbp+17h] BYREF
  int v54; // [rsp+F0h] [rbp+67h]
  __int64 v55; // [rsp+F8h] [rbp+6Fh]

  LayoutRect = UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(dui, LayoutRect, LayoutFlag_FillLastCol);
  *(_QWORD *)&v5->mNumCols = 1i64;
  v5->mColWidths = 0i64;
  v5->mRowHeights = 0i64;
  UFG::DUIContext::RenderRect(dui, &this->mRect, &dui->mTheme.mColour[4], 0);
  v6 = -1;
  mNext = this->mOptions.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::qString,UFG::qString> *)&this->mOptions )
  {
    v8 = -40i64;
    while ( 1 )
    {
      v54 = v6 + 1;
      v8 += 40i64;
      v55 = v8;
      UFG::DUIContext::GetLayoutRect(dui, &current_rect, 0, 0);
      v48 = current_rect;
      mY = dui->mTheme.mButton_Text.mY;
      mX = dui->mTheme.mButton_Text.mX;
      v11 = _mm_cvtsi128_si32((__m128i)current_rect);
      v48.mX = v11 + mX;
      v48.mW = current_rect.mW - 2 * mX;
      v48.mY = mY + current_rect.mY;
      v48.mH = current_rect.mH - 2 * mY;
      result = v48;
      v12 = v6 + 1 == this->mValue;
      v13 = 0;
      dui->mDoubleClicked = 0;
      if ( UFG::DUIContext::TakeFocus(dui, &current_rect, &current_rect, 0) )
      {
        if ( dui->mInputState.mMouseLBWentDown || dui->mInputState.mMouseLBIsDown )
          v13 = 2;
        v14 = dui->mInputState.mMousePos.mX;
        mH = current_rect.mH;
        mW = current_rect.mW;
        v17 = current_rect.mY;
        if ( v14 >= v11 && v14 <= current_rect.mW + v11 )
        {
          v18 = dui->mInputState.mMousePos.mY;
          if ( v18 >= current_rect.mY
            && v18 <= current_rect.mH + current_rect.mY - 1
            && !dui->mInputState.mMouseEventHandled )
          {
            if ( dui->mInputState.mMouseLBWentUp )
            {
              v13 = 3;
              dui->mDoubleClicked = 0;
            }
            else if ( dui->mInputState.mLMBDoubleClick )
            {
              v13 = 4;
              dui->mDoubleClicked = 1;
            }
          }
        }
        if ( dui->mInputState.mMouseLBWentUp )
        {
          dui->mFocusedID = -1;
          dui->mFocusOffset = (UFG::DUIPoint)-1i64;
          dui->mDoubleClicked = 0;
          if ( v13 == 2 )
          {
            v13 = 0;
            if ( !dui->mInputState.mMouseLBIsDown
              && !dui->mInputState.mMouseRBIsDown
              && !dui->mInputState.mMouseMBIsDown )
            {
              v19 = dui->mScissorStacks[dui->mCurrentCompositeLayer].mNode.mNext;
              v20 = dui->mInputState.mMousePos.mX;
              mPrev = (int)v19[1].mPrev;
              if ( v20 >= mPrev && v20 <= LODWORD(v19[1].mNext) + mPrev )
              {
                v22 = dui->mInputState.mMousePos.mY;
                mPrev_high = HIDWORD(v19[1].mPrev);
                if ( v22 >= mPrev_high
                  && v22 <= HIDWORD(v19[1].mNext) + mPrev_high - 1
                  && v20 >= v11
                  && v20 <= mW + v11
                  && v22 >= v17
                  && v22 <= mH + v17 - 1
                  && !dui->mInputState.mMouseEventHandled )
                {
                  v13 = 1;
                }
              }
            }
          }
        }
        dui->mInputState.mMouseWheelDelta = 0;
        *(_QWORD *)&dui->mInputState.mMouseLBWentDown = 0i64;
        *(_WORD *)&dui->mInputState.mLMBDoubleClick = 0;
        dui->mInputState.mMouseMBWentUp = 0;
        dui->mInputState.mMMBDoubleClick = 0;
        if ( v13 == 3 )
        {
          this->mValue = v54;
          this->mHasDialogResult = 1;
          this->mDialogResult = v54;
          dui->mInputState.mMouseWheelDelta = 0;
          *(_QWORD *)&dui->mInputState.mMouseLBWentDown = 0i64;
          *(_WORD *)&dui->mInputState.mLMBDoubleClick = 0;
          dui->mInputState.mMouseMBWentUp = 0;
          dui->mInputState.mMMBDoubleClick = 0;
          break;
        }
        v8 = v55;
      }
      else if ( !dui->mInputState.mMouseLBIsDown && !dui->mInputState.mMouseRBIsDown && !dui->mInputState.mMouseMBIsDown )
      {
        v24 = dui->mScissorStacks[dui->mCurrentCompositeLayer].mNode.mNext;
        v25 = dui->mInputState.mMousePos.mX;
        v26 = (int)v24[1].mPrev;
        if ( v25 >= v26 && v25 <= LODWORD(v24[1].mNext) + v26 )
        {
          v27 = dui->mInputState.mMousePos.mY;
          v28 = HIDWORD(v24[1].mPrev);
          if ( v27 >= v28
            && v27 <= HIDWORD(v24[1].mNext) + v28 - 1
            && v25 >= v11
            && v25 <= v11 + current_rect.mW
            && v27 >= current_rect.mY
            && v27 <= current_rect.mH + current_rect.mY - 1
            && !dui->mInputState.mMouseEventHandled )
          {
            v13 = 1;
          }
        }
      }
      if ( v13 == 1 )
      {
        colour = dui->mTheme.mColour[12];
        p_colour = &colour;
      }
      else
      {
        if ( v12 )
        {
          v49[0] = 0;
          v49[1] = 1056964608;
          v49[2] = 1065353216;
          v49[3] = 1065353216;
          v29 = v49;
        }
        else
        {
          v50[0] = LODWORD(dui->mTheme.mColour[11].r);
          v50[1] = LODWORD(dui->mTheme.mColour[11].g);
          v50[2] = LODWORD(dui->mTheme.mColour[11].b);
          v50[3] = LODWORD(dui->mTheme.mColour[11].a);
          v29 = v50;
        }
        v51[0] = *v29;
        v51[1] = v29[1];
        v51[2] = v29[2];
        v51[3] = v29[3];
        p_colour = (UFG::qColour *)v51;
      }
      UFG::DUIContext::RenderRect(dui, &current_rect, p_colour, 0);
      UFG::DUIContext::RenderText(dui, &result, &UFG::qColourWhite, (const char *)mNext[1].mNext, 0);
      mToolTips = this->mToolTips;
      if ( mToolTips )
        UFG::DUIContext::Tooltip(dui, *(const char **)((char *)&mToolTips->mData + v8), &current_rect);
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::qString,UFG::qString> *)&this->mOptions )
        break;
      v6 = v54;
    }
  }
  if ( dui->mInputState.mMouseLBWentDown )
  {
    v32 = dui->mScissorStacks[dui->mCurrentCompositeLayer].mNode.mNext;
    v33 = dui->mInputState.mMousePos.mX;
    v34 = (int)v32[1].mPrev;
    if ( v33 < v34
      || v33 > LODWORD(v32[1].mNext) + v34
      || (v35 = dui->mInputState.mMousePos.mY, v36 = HIDWORD(v32[1].mPrev), v35 < v36)
      || v35 > HIDWORD(v32[1].mNext) + v36 - 1
      || (v37 = this->mClientRect.mX, v33 < v37)
      || v33 > this->mClientRect.mW + v37
      || (v38 = this->mClientRect.mY, v35 < v38)
      || v35 > this->mClientRect.mH + v38 - 1
      || dui->mInputState.mMouseEventHandled )
    {
      mValue = this->mValue;
      this->mHasDialogResult = 1;
      this->mDialogResult = mValue;
      dui->mInputState.mMouseWheelDelta = 0;
      *(_QWORD *)&dui->mInputState.mMouseLBWentDown = 0i64;
      *(_WORD *)&dui->mInputState.mLMBDoubleClick = 0;
      dui->mInputState.mMouseMBWentUp = 0;
      dui->mInputState.mMMBDoubleClick = 0;
    }
  }
  v40 = dui->mLayoutStack.mNode.mNext;
  v41 = v40->mPrev;
  v42 = v40->mNext;
  v41->mNext = v42;
  v42->mPrev = v41;
  v40->mPrev = v40;
  v40->mNext = v40;
  if ( LOBYTE(v40[4].mNext) )
    UFG::DUIContext::PopScissor(dui);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)dui->mLayoutStack.mNode.mNext != &dui->mLayoutStack
    && dui->mCurrentCompositeLayer != CompositeLayer_Overlay )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&dui->mLayoutStack.mNode.mNext[3], (UFG::DUIRect *)&v40[3]);
  }
  v43 = v40[7].mNext;
  if ( v43 )
  {
    v44 = v43[1].mPrev;
    if ( v44 )
      operator delete[](v44);
    v43[1].mPrev = 0i64;
    v43->mNext = 0i64;
    operator delete[](v43);
  }
  v40[7].mNext = 0i64;
  v45 = v40->mPrev;
  v46 = v40->mNext;
  v45->mNext = v46;
  v46->mPrev = v45;
  v40->mPrev = v40;
  v40->mNext = v40;
  operator delete[](v40);
}

// File Line: 1265
// RVA: 0x1932B0
void __fastcall UFG::DUISuggestionBoxWindow::~DUISuggestionBoxWindow(UFG::DUISuggestionBoxWindow *this)
{
  UFG::qString *mOptions; // rcx
  unsigned int *p_mStringHash32; // rbx

  this->UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUISuggestionBoxWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUISuggestionBoxWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUISuggestionBoxWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  mOptions = this->mOptions;
  if ( mOptions )
  {
    p_mStringHash32 = &mOptions[-1].mStringHash32;
    `eh vector destructor iterator(
      mOptions,
      0x28ui64,
      mOptions[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  UFG::DUIWindow::~DUIWindow(this);
}

// File Line: 1292
// RVA: 0x1A0920
void __fastcall UFG::DUISuggestionBoxWindow::UpdateUI(UFG::DUISuggestionBoxWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIRect *LayoutRect; // rax
  UFG::DUILayoutState *v5; // rax
  int v6; // edi
  int v7; // r12d
  __int64 v8; // r13
  int mY; // edx
  int mX; // ecx
  int v11; // esi
  bool v12; // r14
  int v13; // ecx
  int mH; // r14d
  int mW; // r11d
  int v16; // r10d
  int v17; // ecx
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // r8
  int v19; // r9d
  int mPrev; // ecx
  int v21; // edx
  int mPrev_high; // ecx
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v23; // r8
  int v24; // r9d
  int v25; // ecx
  int v26; // edx
  int v27; // ecx
  int *v28; // rcx
  UFG::qColour *p_colour; // r8
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v30; // r9
  int v31; // r8d
  int v32; // ecx
  int v33; // edx
  int v34; // ecx
  int v35; // ecx
  int v36; // ecx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v37; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v38; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v39; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v40; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v41; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v42; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v43; // rax
  UFG::DUIRect current_rect; // [rsp+40h] [rbp-49h] BYREF
  UFG::DUIRect v45; // [rsp+50h] [rbp-39h]
  int v46[4]; // [rsp+60h] [rbp-29h] BYREF
  int v47[4]; // [rsp+70h] [rbp-19h] BYREF
  int v48[4]; // [rsp+80h] [rbp-9h] BYREF
  UFG::qColour colour; // [rsp+90h] [rbp+7h] BYREF
  UFG::DUIRect result; // [rsp+A0h] [rbp+17h] BYREF
  bool v51; // [rsp+F0h] [rbp+67h]

  LayoutRect = UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(dui, LayoutRect, LayoutFlag_FillLastCol);
  *(_QWORD *)&v5->mNumCols = 1i64;
  v6 = 0;
  v5->mColWidths = 0i64;
  v5->mRowHeights = 0i64;
  UFG::DUIContext::RenderRect(dui, &this->mRect, &dui->mTheme.mColour[4], 0);
  v7 = 0;
  if ( this->mOptionCount > 0 )
  {
    v8 = 0i64;
    do
    {
      UFG::DUIContext::GetLayoutRect(dui, &current_rect, 0, 0);
      v45 = current_rect;
      mY = dui->mTheme.mButton_Text.mY;
      mX = dui->mTheme.mButton_Text.mX;
      v11 = _mm_cvtsi128_si32((__m128i)current_rect);
      v45.mX = v11 + mX;
      v45.mW = current_rect.mW - 2 * mX;
      v45.mY = mY + current_rect.mY;
      v45.mH = current_rect.mH - 2 * mY;
      result = v45;
      v12 = v7 == this->mValue;
      v51 = v12;
      dui->mDoubleClicked = 0;
      if ( UFG::DUIContext::TakeFocus(dui, &current_rect, &current_rect, 0) )
      {
        if ( dui->mInputState.mMouseLBWentDown || dui->mInputState.mMouseLBIsDown )
          v6 = 2;
        v13 = dui->mInputState.mMousePos.mX;
        mH = current_rect.mH;
        mW = current_rect.mW;
        v16 = current_rect.mY;
        if ( v13 >= v11 && v13 <= current_rect.mW + v11 )
        {
          v17 = dui->mInputState.mMousePos.mY;
          if ( v17 >= current_rect.mY
            && v17 <= current_rect.mH + current_rect.mY - 1
            && !dui->mInputState.mMouseEventHandled )
          {
            if ( dui->mInputState.mMouseLBWentUp )
            {
              v6 = 3;
              dui->mDoubleClicked = 0;
            }
            else if ( dui->mInputState.mLMBDoubleClick )
            {
              v6 = 4;
              dui->mDoubleClicked = 1;
            }
          }
        }
        if ( dui->mInputState.mMouseLBWentUp )
        {
          dui->mFocusedID = -1;
          dui->mFocusOffset = (UFG::DUIPoint)-1i64;
          dui->mDoubleClicked = 0;
          if ( v6 == 2 )
          {
            v6 = 0;
            if ( !dui->mInputState.mMouseLBIsDown
              && !dui->mInputState.mMouseRBIsDown
              && !dui->mInputState.mMouseMBIsDown )
            {
              mNext = dui->mScissorStacks[dui->mCurrentCompositeLayer].mNode.mNext;
              v19 = dui->mInputState.mMousePos.mX;
              mPrev = (int)mNext[1].mPrev;
              if ( v19 >= mPrev && v19 <= LODWORD(mNext[1].mNext) + mPrev )
              {
                v21 = dui->mInputState.mMousePos.mY;
                mPrev_high = HIDWORD(mNext[1].mPrev);
                if ( v21 >= mPrev_high
                  && v21 <= HIDWORD(mNext[1].mNext) + mPrev_high - 1
                  && v19 >= v11
                  && v19 <= mW + v11
                  && v21 >= v16
                  && v21 <= mH + v16 - 1
                  && !dui->mInputState.mMouseEventHandled )
                {
                  v6 = 1;
                }
              }
            }
          }
        }
        dui->mInputState.mMouseWheelDelta = 0;
        *(_QWORD *)&dui->mInputState.mMouseLBWentDown = 0i64;
        *(_WORD *)&dui->mInputState.mLMBDoubleClick = 0;
        dui->mInputState.mMouseMBWentUp = 0;
        dui->mInputState.mMMBDoubleClick = 0;
        if ( v6 == 3 )
        {
          this->mValue = v7;
          this->mHasDialogResult = 1;
          this->mDialogResult = v7;
          dui->mInputState.mMouseWheelDelta = 0;
          *(_QWORD *)&dui->mInputState.mMouseLBWentDown = 0i64;
          *(_WORD *)&dui->mInputState.mLMBDoubleClick = 0;
          dui->mInputState.mMouseMBWentUp = 0;
          dui->mInputState.mMMBDoubleClick = 0;
          break;
        }
        v12 = v51;
      }
      else if ( !dui->mInputState.mMouseLBIsDown && !dui->mInputState.mMouseRBIsDown && !dui->mInputState.mMouseMBIsDown )
      {
        v23 = dui->mScissorStacks[dui->mCurrentCompositeLayer].mNode.mNext;
        v24 = dui->mInputState.mMousePos.mX;
        v25 = (int)v23[1].mPrev;
        if ( v24 >= v25 && v24 <= LODWORD(v23[1].mNext) + v25 )
        {
          v26 = dui->mInputState.mMousePos.mY;
          v27 = HIDWORD(v23[1].mPrev);
          if ( v26 >= v27
            && v26 <= HIDWORD(v23[1].mNext) + v27 - 1
            && v24 >= v11
            && v24 <= v11 + current_rect.mW
            && v26 >= current_rect.mY
            && v26 <= current_rect.mH + current_rect.mY - 1
            && !dui->mInputState.mMouseEventHandled )
          {
            v6 = 1;
          }
        }
      }
      if ( v6 == 1 )
      {
        colour = dui->mTheme.mColour[12];
        p_colour = &colour;
      }
      else
      {
        if ( v12 )
        {
          v46[0] = 0;
          v46[1] = 1056964608;
          v46[2] = 1065353216;
          v46[3] = 1065353216;
          v28 = v46;
        }
        else
        {
          v47[0] = LODWORD(dui->mTheme.mColour[11].r);
          v47[1] = LODWORD(dui->mTheme.mColour[11].g);
          v47[2] = LODWORD(dui->mTheme.mColour[11].b);
          v47[3] = LODWORD(dui->mTheme.mColour[11].a);
          v28 = v47;
        }
        v48[0] = *v28;
        v48[1] = v28[1];
        v48[2] = v28[2];
        v48[3] = v28[3];
        p_colour = (UFG::qColour *)v48;
      }
      UFG::DUIContext::RenderRect(dui, &current_rect, p_colour, 0);
      v6 = 0;
      UFG::DUIContext::RenderText(dui, &result, &UFG::qColourWhite, this->mOptions[v8].mData, 0);
      ++v7;
      ++v8;
    }
    while ( v7 < this->mOptionCount );
  }
  if ( dui->mInputState.mMouseLBWentDown )
  {
    v30 = dui->mScissorStacks[dui->mCurrentCompositeLayer].mNode.mNext;
    v31 = dui->mInputState.mMousePos.mX;
    v32 = (int)v30[1].mPrev;
    if ( v31 < v32
      || v31 > LODWORD(v30[1].mNext) + v32
      || (v33 = dui->mInputState.mMousePos.mY, v34 = HIDWORD(v30[1].mPrev), v33 < v34)
      || v33 > HIDWORD(v30[1].mNext) + v34 - 1
      || (v35 = this->mClientRect.mX, v31 < v35)
      || v31 > this->mClientRect.mW + v35
      || (v36 = this->mClientRect.mY, v33 < v36)
      || v33 > this->mClientRect.mH + v36 - 1
      || dui->mInputState.mMouseEventHandled )
    {
      this->mHasDialogResult = 1;
      this->mDialogResult = -1i64;
    }
  }
  v37 = dui->mLayoutStack.mNode.mNext;
  v38 = v37->mPrev;
  v39 = v37->mNext;
  v38->mNext = v39;
  v39->mPrev = v38;
  v37->mPrev = v37;
  v37->mNext = v37;
  if ( LOBYTE(v37[4].mNext) )
    UFG::DUIContext::PopScissor(dui);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)dui->mLayoutStack.mNode.mNext != &dui->mLayoutStack
    && dui->mCurrentCompositeLayer != CompositeLayer_Overlay )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&dui->mLayoutStack.mNode.mNext[3], (UFG::DUIRect *)&v37[3]);
  }
  v40 = v37[7].mNext;
  if ( v40 )
  {
    v41 = v40[1].mPrev;
    if ( v41 )
      operator delete[](v41);
    v40[1].mPrev = 0i64;
    v40->mNext = 0i64;
    operator delete[](v40);
  }
  v37[7].mNext = 0i64;
  v42 = v37->mPrev;
  v43 = v37->mNext;
  v42->mNext = v43;
  v43->mPrev = v42;
  v37->mPrev = v37;
  v37->mNext = v37;
  operator delete[](v37);
}

// File Line: 1355
// RVA: 0x198C80
__int64 __fastcall UFG::PopupMenuCommand::GetState(
        UFG::PopupMenuCommand *this,
        UFG::CommandContext *context,
        unsigned int *image_uid)
{
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  unsigned int v8; // r12d
  int v9; // ebx
  UFG::Command **p; // rsi
  unsigned int size; // ebp
  UFG::PopupMenuCommand *v12; // rcx
  __int64 result; // rax
  UFG::qArray<UFG::Command *,0> commands; // [rsp+28h] [rbp-40h] BYREF
  int v15; // [rsp+80h] [rbp+18h] BYREF

  v6 = UFG::qStringHashUpper32("DUIPopupMenuWindow", -1);
  if ( v6 && (v7 = UFG::qBaseTreeRB::Get(&context->mDictionary.mTree, v6)) != 0i64 && v7 != (UFG::qBaseTreeRB *)8 )
  {
    v8 = 2;
    if ( this->mHideWhenEmpty )
      v8 = 0;
    commands.p = 0i64;
    *(_QWORD *)&commands.size = 0i64;
    UFG::CommandManager::GetCommandsFromTags(UFG::gCommandManager, &this->mChildTags, &commands);
    v9 = 0;
    p = commands.p;
    size = commands.size;
    if ( commands.size )
    {
      while ( 1 )
      {
        v12 = (UFG::PopupMenuCommand *)p[v9];
        if ( v12 != this )
        {
          v15 = 0;
          if ( v12->vfptr->GetState(v12, context, (unsigned int *)&v15) == State_Enabled )
          {
            if ( context->mDictionary.mTree.mCount )
              break;
          }
        }
        if ( ++v9 >= size )
          goto LABEL_13;
      }
      v8 = 1;
    }
LABEL_13:
    if ( p )
      operator delete[](p);
    commands.p = 0i64;
    *(_QWORD *)&commands.size = 0i64;
    result = v8;
  }
  else
  {
    result = 0i64;
  }
  *image_uid = -514241332;
  return result;
}

// File Line: 1387
// RVA: 0x198280
void __fastcall UFG::PopupMenuCommand::Execute(UFG::PopupMenuCommand *this, UFG::CommandContext *context)
{
  unsigned int v4; // eax
  UFG::qBaseTreeRB *v5; // rax
  UFG::DUIPopupMenuWindow *mParent; // rsi
  UFG::qReflectInventoryBase **p; // rbx
  __int64 size; // rdi
  UFG::qArray<UFG::Command *,0> commands; // [rsp+28h] [rbp-30h] BYREF
  UFG::DUIPopupMenuWindow *v10; // [rsp+60h] [rbp+8h]

  commands.p = 0i64;
  *(_QWORD *)&commands.size = 0i64;
  UFG::CommandManager::GetCommandsFromTags(UFG::gCommandManager, &this->mChildTags, &commands);
  v4 = UFG::qStringHashUpper32("DUIPopupMenuWindow", -1);
  if ( v4 && (v5 = UFG::qBaseTreeRB::Get(&context->mDictionary.mTree, v4)) != 0i64 && v5 != (UFG::qBaseTreeRB *)8 )
    mParent = (UFG::DUIPopupMenuWindow *)v5->mNULL.mParent;
  else
    mParent = v10;
  if ( commands.size )
  {
    p = (UFG::qReflectInventoryBase **)commands.p;
    size = commands.size;
    do
    {
      if ( *p != (UFG::qReflectInventoryBase *)this )
        UFG::DUIPopupMenuWindow::AddCommandItem(mParent, *p);
      ++p;
      --size;
    }
    while ( size );
  }
  if ( commands.p )
    operator delete[](commands.p);
}

// File Line: 1417
// RVA: 0x192AC0
void __fastcall UFG::DUIPopupMenuWindow::DUIPopupMenuWindow(
        UFG::DUIPopupMenuWindow *this,
        UFG::CommandContext *context,
        bool root)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::DUIPopupMenuWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIPopupMenuWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIPopupMenuWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mParentCommand = 0i64;
  this->mCommands.p = 0i64;
  *(_QWORD *)&this->mCommands.size = 0i64;
  this->mParentWindow = 0i64;
  this->mChildWindow = 0i64;
  this->mKeepUp = 0;
  this->mCommandContext = context;
  *(_QWORD *)&this->mRect.mX = 0i64;
  this->mRect.mW = 1;
  this->mRect.mH = 1;
  if ( root )
    this->mParentWindow = this;
  this->mStyle = Style_PopupMenu;
}

// File Line: 1428
// RVA: 0x193220
void __fastcall UFG::DUIPopupMenuWindow::~DUIPopupMenuWindow(UFG::DUIPopupMenuWindow *this)
{
  UFG::DUIPopupMenuWindow *mParentWindow; // rax
  UFG::CommandContext *mCommandContext; // rcx
  UFG::Command **p; // rcx

  this->UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::DUIPopupMenuWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::DUIPopupMenuWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::DUIPopupMenuWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  mParentWindow = this->mParentWindow;
  if ( mParentWindow != this )
    mParentWindow->mChildWindow = 0i64;
  mCommandContext = this->mCommandContext;
  if ( mCommandContext )
    mCommandContext->vfptr->__vecDelDtor(mCommandContext, 1u);
  p = this->mCommands.p;
  if ( p )
    operator delete[](p);
  this->mCommands.p = 0i64;
  *(_QWORD *)&this->mCommands.size = 0i64;
  UFG::DUIWindow::~DUIWindow(this);
}

// File Line: 1445
// RVA: 0x193AD0
void __fastcall UFG::DUIPopupMenuWindow::AddCommandItem(
        UFG::DUIPopupMenuWindow *this,
        UFG::qReflectInventoryBase *command)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_mCommands; // rdi
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **p; // rax

  p_mCommands = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mCommands;
  size = this->mCommands.size;
  capacity = this->mCommands.capacity;
  v6 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_mCommands, v7, "qArray.Add");
  }
  p = p_mCommands->p;
  p_mCommands->size = v6;
  p[size] = command;
}

// File Line: 1450
// RVA: 0x19E670
void __fastcall UFG::DUIPopupMenuWindow::SubmenuHeader(
        UFG::DUIPopupMenuWindow *this,
        UFG::DUIContext *dui,
        UFG::Command *command,
        UFG::Command::State state,
        unsigned int image_uid)
{
  UFG::Command *v5; // r12
  char v8; // r15
  char v9; // r13
  int mW; // r14d
  int mX; // esi
  UFG::DUIPopupMenuWindow *mChildWindow; // rdi
  int mY; // r12d
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // r9
  int v15; // r8d
  int mPrev; // ecx
  int v17; // edx
  int mPrev_high; // ecx
  UFG::allocator::free_link *v19; // r15
  UFG::allocator::free_link *v20; // rax
  UFG::CommandContext *v21; // rax
  UFG::CommandContext *v22; // rdi
  UFG::DUIPopupMenuWindow *v23; // rax
  UFG::DUIPopupMenuWindow *v24; // rdi
  __int64 v25; // rcx
  UFG::Command *mParentCommand; // rax
  UFG::DUIInputState *p_mInputState; // r15
  int v28; // ecx
  int mMenuImage_Inset; // eax
  int v30; // esi
  int v31; // r14d
  UFG::DUIRect v32; // xmm6
  int v33; // edx
  int v34; // ecx
  UFG::qColour *mColour; // rcx
  int v36; // kr00_4
  int v37; // edx
  int v38; // ecx
  UFG::qColour colour; // [rsp+38h] [rbp-40h] BYREF
  UFG::DUIRect result; // [rsp+50h] [rbp-28h] BYREF
  UFG::DUIPopupMenuWindow *data; // [rsp+C8h] [rbp+50h] BYREF
  UFG::Command *v43; // [rsp+D0h] [rbp+58h]
  bool v44; // [rsp+D8h] [rbp+60h]

  v43 = command;
  v5 = command;
  v8 = state == State_Enabled;
  v44 = state == State_Enabled;
  v9 = 0;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  mW = result.mW;
  mX = result.mX;
  if ( !v8 )
    goto LABEL_31;
  mChildWindow = this->mChildWindow;
  mY = result.mY;
  if ( mChildWindow )
  {
    mParentCommand = mChildWindow->mParentCommand;
    if ( mParentCommand && mParentCommand == v43 )
    {
      v9 = 1;
      p_mInputState = &dui->mInputState;
      mChildWindow->mKeepUp = UFG::DUIContext::IsVisible(dui, &dui->mInputState.mMousePos)
                           && p_mInputState->mMousePos.mX >= mX
                           && p_mInputState->mMousePos.mX <= mW + mX
                           && (v28 = dui->mInputState.mMousePos.mY, v28 >= mY)
                           && v28 <= mY + result.mH - 1;
      v8 = v44;
    }
    goto LABEL_30;
  }
  mNext = dui->mScissorStacks[dui->mCurrentCompositeLayer].mNode.mNext;
  v15 = dui->mInputState.mMousePos.mX;
  mPrev = (int)mNext[1].mPrev;
  if ( v15 < mPrev
    || v15 > LODWORD(mNext[1].mNext) + mPrev
    || (v17 = dui->mInputState.mMousePos.mY, mPrev_high = HIDWORD(mNext[1].mPrev), v17 < mPrev_high)
    || v17 > HIDWORD(mNext[1].mNext) + mPrev_high - 1
    || v15 < result.mX
    || v15 > result.mW + result.mX
    || v17 < result.mY
    || v17 > result.mY + result.mH - 1
    || dui->mInputState.mMouseEventHandled )
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
      UFG::CommandContext::CommandContext((UFG::CommandContext *)v20, this->mCommandContext);
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
  UFG::CommandContext::AddContext<UFG::DUIPopupMenuWindow *>(
    v24->mCommandContext,
    "DUIPopupMenuWindow",
    (UFG::qBaseNodeRB **)&data);
  v25 = (__int64)v43;
  v24->mParentCommand = v43;
  v24->mRect.mX = mW + mX - 1;
  v24->mRect.mY = mY;
  v24->mParentWindow = this;
  v24->mKeepUp = 1;
  this->mChildWindow = v24;
  v5 = (UFG::Command *)v25;
  (*(void (__fastcall **)(__int64, UFG::CommandContext *))(*(_QWORD *)v25 + 16i64))(v25, v24->mCommandContext);
  UFG::DUIManager::ShowWindow(
    dui->mManager,
    (UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *)v24,
    (UFG::qNode<UFG::DUIShowWindowParams,UFG::DUIShowWindowParams> *)dui->mSurface,
    0);
  v8 = v44;
LABEL_31:
  mMenuImage_Inset = dui->mTheme.mMenuImage_Inset;
  v30 = mMenuImage_Inset + mX;
  result.mX = v30;
  v31 = mW - mMenuImage_Inset;
  result.mW = v31;
  v32 = result;
  if ( v9 )
  {
    if ( !v8 )
    {
LABEL_35:
      mColour = &dui->mTheme.mColour[1];
      goto LABEL_38;
    }
    v33 = dui->mTheme.mButton_Inset.mY;
    v34 = dui->mTheme.mButton_Inset.mX;
    result.mX = v34 + v30;
    result.mW = v32.mW - 2 * v34;
    result.mY = v33 + v32.mY;
    result.mH = v32.mH - 2 * v33;
    UFG::DUIContext::RenderRoundRect(dui, &result, &dui->mTheme.mColour[12], 0);
  }
  if ( !v8 )
    goto LABEL_35;
  mColour = &dui->mTheme.mColour[2];
  if ( !v9 )
    mColour = dui->mTheme.mColour;
LABEL_38:
  colour = *mColour;
  result = v32;
  v36 = dui->mTheme.mMenuImage_Inset;
  result.mX = v30 + v31 - v36 / 2;
  result.mW = v36 / 2;
  result.mY = v32.mH / 4 + v32.mY;
  result.mH = v32.mH / 2;
  if ( image_uid )
    UFG::DUIContext::RenderRoundRect(dui, &result, &colour, image_uid);
  result = v32;
  v37 = dui->mTheme.mButton_Text.mY;
  v38 = dui->mTheme.mButton_Text.mX;
  result.mX = v38 + v30;
  result.mW = v32.mW - 2 * v38;
  result.mY = v37 + v32.mY;
  result.mH = v32.mH - 2 * v37;
  UFG::DUIContext::RenderText(dui, &result, &colour, v5->mDisplayText.mData, 0x10u);
}

// File Line: 1519
// RVA: 0x19BE50
void __fastcall UFG::DUIPopupMenuWindow::OnCommandClicked(UFG::DUIPopupMenuWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIPopupMenuWindow *mParentWindow; // rdx

  while ( 1 )
  {
    if ( !this->mMarkedToDestroy )
      this->mMarkedToDestroy = 1;
    mParentWindow = this->mParentWindow;
    if ( mParentWindow == this )
      break;
    mParentWindow->mChildWindow = 0i64;
    this = this->mParentWindow;
  }
}

// File Line: 1530
// RVA: 0x1A0370
void __fastcall UFG::DUIPopupMenuWindow::UpdateUI(UFG::DUIPopupMenuWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIRect *LayoutRect; // rax
  UFG::DUILayoutState *v5; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_mTags; // r15
  int mLength; // r14d
  __int64 v8; // rdi
  UFG::Command *v9; // r12
  int v10; // r14d
  int v11; // ecx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rdi
  UFG::qList<UFG::qString,UFG::qString,1,0> *v13; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v14; // rbx
  int v15; // edx
  UFG::Command *mPrev; // rax
  int v17; // eax
  UFG::qNode<UFG::qString,UFG::qString> *i; // rdx
  int v19; // eax
  UFG::CommandContext *mCommandContext; // rdx
  bool v21; // zf
  UFG::CommandVtbl *vfptr; // rax
  UFG::Command::State v23; // ebx
  int mMenuImage_Inset; // edx
  UFG::Command::State v25; // eax
  UFG::Command::State v26; // ebx
  int v27; // edx
  UFG::DUIPopupMenuWindow *mParentWindow; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v29; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v30; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v31; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v32; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v33; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v34; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v35; // rax
  float v36; // xmm0_4
  int v37; // edx
  __int64 v38; // rcx
  UFG::DUIPopupMenuWindow *v39; // rax
  int mX; // edx
  int v41; // ecx
  int mY; // ecx
  int v43; // edx
  bool v44; // al
  UFG::DUIRect rect; // [rsp+38h] [rbp-48h] BYREF
  UFG::DUIRect result; // [rsp+48h] [rbp-38h] BYREF
  UFG::qString out_string; // [rsp+58h] [rbp-28h] BYREF
  char v48; // [rsp+C0h] [rbp+40h]
  int v49; // [rsp+C8h] [rbp+48h]
  unsigned int menu_image_uid; // [rsp+D0h] [rbp+50h] BYREF

  LayoutRect = UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v5 = UFG::DUIContext::PushLayoutState(dui, LayoutRect, LayoutFlag_FillLastCol);
  *(_QWORD *)&v5->mNumCols = 1i64;
  v5->mColWidths = 0i64;
  v5->mRowHeights = 0i64;
  p_mTags = 0i64;
  v48 = 0;
  mLength = 0;
  v49 = 0;
  v8 = 0i64;
  menu_image_uid = 0;
  if ( !this->mCommands.size )
    goto LABEL_39;
  while ( 1 )
  {
    v9 = this->mCommands.p[v8];
    if ( !p_mTags )
    {
      p_mTags = &v9->mTags;
      goto LABEL_18;
    }
    v10 = 0;
    v11 = 0;
    mNext = p_mTags->mNode.mNext;
    v13 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)mNext;
    if ( mNext != (UFG::qNode<UFG::qString,UFG::qString> *)p_mTags )
    {
      do
      {
        ++v11;
        v13 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v13->mNode.mNext;
      }
      while ( v13 != p_mTags );
    }
    v14 = &v9->mTags;
    v15 = 0;
    mPrev = (UFG::Command *)v9->mTags.mNode.mNext;
    if ( mPrev != (UFG::Command *)&v9->mTags )
    {
      do
      {
        ++v15;
        mPrev = (UFG::Command *)mPrev->mPrev;
      }
      while ( mPrev != (UFG::Command *)v14 );
    }
    if ( v11 != v15 )
      goto LABEL_16;
    if ( mNext != (UFG::qNode<UFG::qString,UFG::qString> *)p_mTags )
    {
      while ( 1 )
      {
        v17 = v10;
        for ( i = v9->mTags.mNode.mNext; v17 > 0; i = i->mNext )
        {
          if ( i == (UFG::qNode<UFG::qString,UFG::qString> *)v14 )
            break;
          --v17;
        }
        ++v10;
        if ( (unsigned int)UFG::qStringCompare((const char *)mNext[1].mNext, (const char *)i[1].mNext, -1) )
          break;
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<UFG::qString,UFG::qString> *)p_mTags )
          goto LABEL_17;
      }
LABEL_16:
      v48 = 1;
      p_mTags = &v9->mTags;
    }
LABEL_17:
    mLength = v49;
    LODWORD(v8) = menu_image_uid;
LABEL_18:
    v19 = UFG::qStringCompare(v9->mUserType.mData, "PopupMenuCommand", -1);
    menu_image_uid = 0;
    mCommandContext = this->mCommandContext;
    v21 = v19 == 0;
    vfptr = v9->vfptr;
    if ( v21 )
    {
      v23 = vfptr->GetState(v9, mCommandContext, &menu_image_uid);
      if ( v23 )
      {
        if ( v48 )
        {
          UFG::DUIContext::GetLayoutRect(dui, &rect, 0, 0);
          rect.mY += rect.mH / 2;
          rect.mH = 1;
          mMenuImage_Inset = dui->mTheme.mMenuImage_Inset;
          rect.mX += mMenuImage_Inset + 2;
          rect.mW += 2 * (-2 - mMenuImage_Inset);
          UFG::DUIContext::RenderRect(dui, &rect, &dui->mTheme.mColour[17], 0);
          v48 = 0;
        }
        if ( mLength <= v9->mDisplayText.mLength )
          mLength = v9->mDisplayText.mLength;
        v49 = mLength;
        UFG::DUIPopupMenuWindow::SubmenuHeader(this, dui, v9, v23, menu_image_uid);
      }
      goto LABEL_33;
    }
    v25 = vfptr->GetState(v9, mCommandContext, &menu_image_uid);
    v26 = v25;
    if ( v48 )
    {
      if ( v25 == State_Unavailable )
        goto LABEL_32;
      UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
      result.mY += result.mH / 2;
      result.mH = 1;
      v27 = dui->mTheme.mMenuImage_Inset;
      result.mX += v27 + 2;
      result.mW += 2 * (-2 - v27);
      UFG::DUIContext::RenderRect(dui, &result, &dui->mTheme.mColour[17], 0);
      v48 = 0;
    }
    if ( v26 )
    {
      UFG::qString::qString(&out_string);
      UFG::BuildCommandKeyString(v9, &out_string);
      if ( mLength <= out_string.mLength + 1 + v9->mDisplayText.mLength )
        mLength = out_string.mLength + 1 + v9->mDisplayText.mLength;
      v49 = mLength;
      UFG::qString::~qString(&out_string);
    }
LABEL_32:
    if ( UFG::DUIContext::CommandButton(dui, v9, this->mCommandContext, v26) )
      break;
LABEL_33:
    v8 = (unsigned int)(v8 + 1);
    menu_image_uid = v8;
    if ( (unsigned int)v8 >= this->mCommands.size )
      goto LABEL_39;
  }
  if ( !this->mMarkedToDestroy )
    this->mMarkedToDestroy = 1;
  mParentWindow = this->mParentWindow;
  if ( mParentWindow != this )
  {
    mParentWindow->mChildWindow = 0i64;
    UFG::DUIPopupMenuWindow::OnCommandClicked(this->mParentWindow, dui);
  }
LABEL_39:
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  v29 = dui->mLayoutStack.mNode.mNext;
  v30 = v29->mPrev;
  v31 = v29->mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  v29->mPrev = v29;
  v29->mNext = v29;
  if ( LOBYTE(v29[4].mNext) )
    UFG::DUIContext::PopScissor(dui);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)dui->mLayoutStack.mNode.mNext != &dui->mLayoutStack
    && dui->mCurrentCompositeLayer != CompositeLayer_Overlay )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&dui->mLayoutStack.mNode.mNext[3], (UFG::DUIRect *)&v29[3]);
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
  result = (UFG::DUIRect)dui->mLayoutStack.mNode.mNext[3];
  v36 = FLOAT_200_0;
  if ( (float)(int)((float)((float)((float)mLength * dui->mFontDimensions.x) + (float)dui->mTheme.mMenuImage_Inset) * 1.2) >= 200.0 )
    v36 = (float)(int)((float)((float)((float)mLength * dui->mFontDimensions.x) + (float)dui->mTheme.mMenuImage_Inset)
                     * 1.2);
  v37 = (int)v36;
  this->mRect.mW = (int)v36;
  v38 = HIDWORD(*(_QWORD *)&result.mW);
  this->mRect.mH = result.mH;
  if ( this->mRect.mX + (int)v36 > dui->mRect.mW )
  {
    v39 = this->mParentWindow;
    if ( v39 )
      this->mRect.mX = v39->mRect.mX - v37;
    else
      this->mRect.mX -= v37;
  }
  if ( this->mRect.mY + (int)v38 > dui->mRect.mH )
  {
    if ( this->mParentWindow )
      this->mRect.mY += dui->mTheme.mRowHeight - v38;
    else
      this->mRect.mY -= v38;
    if ( this->mRect.mY < 0 )
      this->mRect.mY = 0;
  }
  mX = dui->mInputState.mMousePos.mX;
  v41 = this->mRect.mX;
  v44 = 0;
  if ( mX >= v41 && mX <= this->mRect.mW + v41 )
  {
    mY = this->mRect.mY;
    v43 = dui->mInputState.mMousePos.mY;
    if ( v43 >= mY && v43 <= this->mRect.mH + mY - 1 && !dui->mInputState.mMouseEventHandled )
      v44 = 1;
  }
  if ( dui->mInputState.mMouseLBWentDown
    || dui->mInputState.mMouseRBWentDown
    || dui->mInputState.mMouseMBWentDown
    || this->mParentWindow != this && !this->mKeepUp && !v44 )
  {
    if ( !this->mMarkedToDestroy )
      this->mMarkedToDestroy = 1;
  }
  else
  {
    dui->mInputState.mMouseEventHandled = 1;
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
void __fastcall UFG::DUIContext::RenderText(
        UFG::DUIContext *this,
        UFG::DUIRect *rect,
        UFG::qColour *colour,
        const char *text,
        unsigned int flags)
{
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // r15
  int mH; // ebp
  int mW; // esi
  int mY; // edi
  int mX; // ebx
  UFG::qList<UFG::DUIRenderCommand,UFG::DUIRenderCommand,1,0> *v15; // rcx
  UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *mPrev; // rax
  __int128 v17; // [rsp+30h] [rbp-68h]
  __int128 v18; // [rsp+40h] [rbp-58h]
  __int128 v19; // [rsp+50h] [rbp-48h]
  __int128 v20; // [rsp+60h] [rbp-38h]

  if ( this->mBuildCommandList
    && rect->mW > 0
    && rect->mH > 0
    && UFG::DUIRect::Overlaps(rect, (UFG::DUIRect *)&this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext[1]) )
  {
    v9 = UFG::qMalloc(0xA8ui64, "DUIRenderCommand", 0x800ui64);
    v10 = v9;
    if ( v9 )
    {
      v20 = (__int128)*colour;
      v19 = (__int128)*colour;
      v18 = (__int128)*colour;
      v17 = (__int128)*colour;
      mH = rect->mH;
      mW = rect->mW;
      mY = rect->mY;
      mX = rect->mX;
      v9->mNext = v9;
      v9[1].mNext = v9;
      UFG::qString::qString((UFG::qString *)&v9[14]);
      LODWORD(v10[2].mNext) = 5;
      HIDWORD(v10[2].mNext) = mX;
      LODWORD(v10[3].mNext) = mY;
      HIDWORD(v10[3].mNext) = mW;
      LODWORD(v10[4].mNext) = mH;
      v10[5].mNext = 0i64;
      *(_OWORD *)&v10[6].mNext = v17;
      *(_OWORD *)&v10[8].mNext = v18;
      *(_OWORD *)&v10[10].mNext = v19;
      *(_OWORD *)&v10[12].mNext = v20;
      UFG::qString::Set((UFG::qString *)&v10[14], text);
      LODWORD(v10[19].mNext) = flags;
    }
    else
    {
      v10 = 0i64;
    }
    v15 = &this->mRenderCommands[this->mCurrentCompositeLayer];
    mPrev = v15->mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v10;
    v10->mNext = (UFG::allocator::free_link *)mPrev;
    v10[1].mNext = (UFG::allocator::free_link *)v15;
    v15->mNode.mPrev = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v10;
  }
}

// File Line: 1785
// RVA: 0x19CB20
void __fastcall UFG::DUIContext::RenderRect(
        UFG::DUIContext *this,
        UFG::DUIRect *rect,
        UFG::qColour *colour,
        unsigned int texture_uid)
{
  UFG::allocator::free_link *v4; // r13
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // r15
  int mH; // ebp
  int mW; // esi
  int mY; // edi
  int mX; // ebx
  UFG::qList<UFG::DUIRenderCommand,UFG::DUIRenderCommand,1,0> *v14; // rcx
  UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *mPrev; // rax
  __int128 v16; // [rsp+30h] [rbp-68h]
  __int128 v17; // [rsp+40h] [rbp-58h]
  __int128 v18; // [rsp+50h] [rbp-48h]
  __int128 v19; // [rsp+60h] [rbp-38h]

  v4 = (UFG::allocator::free_link *)texture_uid;
  if ( this->mBuildCommandList
    && rect->mW > 0
    && rect->mH > 0
    && UFG::DUIRect::Overlaps(rect, (UFG::DUIRect *)&this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext[1]) )
  {
    v8 = UFG::qMalloc(0xA8ui64, "DUIRenderCommand", 0x800ui64);
    v9 = v8;
    if ( v8 )
    {
      v19 = (__int128)*colour;
      v18 = (__int128)*colour;
      v17 = (__int128)*colour;
      v16 = (__int128)*colour;
      mH = rect->mH;
      mW = rect->mW;
      mY = rect->mY;
      mX = rect->mX;
      v8->mNext = v8;
      v8[1].mNext = v8;
      UFG::qString::qString((UFG::qString *)&v8[14]);
      LODWORD(v9[2].mNext) = 6;
      HIDWORD(v9[2].mNext) = mX;
      LODWORD(v9[3].mNext) = mY;
      HIDWORD(v9[3].mNext) = mW;
      LODWORD(v9[4].mNext) = mH;
      v9[5].mNext = v4;
      *(_OWORD *)&v9[6].mNext = v16;
      *(_OWORD *)&v9[8].mNext = v17;
      *(_OWORD *)&v9[10].mNext = v18;
      *(_OWORD *)&v9[12].mNext = v19;
      UFG::qString::Set((UFG::qString *)&v9[14], 0i64);
      LODWORD(v9[19].mNext) = 0;
    }
    else
    {
      v9 = 0i64;
    }
    v14 = &this->mRenderCommands[this->mCurrentCompositeLayer];
    mPrev = v14->mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v9;
    v9->mNext = (UFG::allocator::free_link *)mPrev;
    v9[1].mNext = (UFG::allocator::free_link *)v14;
    v14->mNode.mPrev = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v9;
  }
}

// File Line: 1793
// RVA: 0x19CE20
void __fastcall UFG::DUIContext::RenderRoundRect(
        UFG::DUIContext *this,
        UFG::DUIRect *rect,
        UFG::qColour *colour,
        unsigned int texture_uid)
{
  UFG::allocator::free_link *v4; // r13
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // r15
  int mH; // ebp
  int mW; // esi
  int mY; // edi
  int mX; // ebx
  UFG::qList<UFG::DUIRenderCommand,UFG::DUIRenderCommand,1,0> *v14; // rcx
  UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *mPrev; // rax
  __int128 v16; // [rsp+30h] [rbp-68h]
  __int128 v17; // [rsp+40h] [rbp-58h]
  __int128 v18; // [rsp+50h] [rbp-48h]
  __int128 v19; // [rsp+60h] [rbp-38h]

  v4 = (UFG::allocator::free_link *)texture_uid;
  if ( this->mBuildCommandList
    && rect->mW > 0
    && rect->mH > 0
    && UFG::DUIRect::Overlaps(rect, (UFG::DUIRect *)&this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext[1]) )
  {
    v8 = UFG::qMalloc(0xA8ui64, "DUIRenderCommand", 0x800ui64);
    v9 = v8;
    if ( v8 )
    {
      v19 = (__int128)*colour;
      v18 = (__int128)*colour;
      v17 = (__int128)*colour;
      v16 = (__int128)*colour;
      mH = rect->mH;
      mW = rect->mW;
      mY = rect->mY;
      mX = rect->mX;
      v8->mNext = v8;
      v8[1].mNext = v8;
      UFG::qString::qString((UFG::qString *)&v8[14]);
      LODWORD(v9[2].mNext) = 7;
      HIDWORD(v9[2].mNext) = mX;
      LODWORD(v9[3].mNext) = mY;
      HIDWORD(v9[3].mNext) = mW;
      LODWORD(v9[4].mNext) = mH;
      v9[5].mNext = v4;
      *(_OWORD *)&v9[6].mNext = v16;
      *(_OWORD *)&v9[8].mNext = v17;
      *(_OWORD *)&v9[10].mNext = v18;
      *(_OWORD *)&v9[12].mNext = v19;
      UFG::qString::Set((UFG::qString *)&v9[14], 0i64);
      LODWORD(v9[19].mNext) = 0;
    }
    else
    {
      v9 = 0i64;
    }
    v14 = &this->mRenderCommands[this->mCurrentCompositeLayer];
    mPrev = v14->mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v9;
    v9->mNext = (UFG::allocator::free_link *)mPrev;
    v9[1].mNext = (UFG::allocator::free_link *)v14;
    v14->mNode.mPrev = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v9;
  }
}

// File Line: 1801
// RVA: 0x19CCA0
void __fastcall UFG::DUIContext::RenderRoundRect(
        UFG::DUIContext *this,
        UFG::DUIRect *rect,
        UFG::qColour *colourL,
        UFG::qColour *colourR,
        unsigned int texture_uid)
{
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // r15
  int mH; // ebp
  int mW; // esi
  int mY; // edi
  int mX; // ebx
  UFG::qList<UFG::DUIRenderCommand,UFG::DUIRenderCommand,1,0> *v15; // rcx
  UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *mPrev; // rax
  __int128 v17; // [rsp+30h] [rbp-68h]
  __int128 v18; // [rsp+40h] [rbp-58h]
  __int128 v19; // [rsp+50h] [rbp-48h]
  __int128 v20; // [rsp+60h] [rbp-38h]

  if ( this->mBuildCommandList
    && rect->mW > 0
    && rect->mH > 0
    && UFG::DUIRect::Overlaps(rect, (UFG::DUIRect *)&this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext[1]) )
  {
    v9 = UFG::qMalloc(0xA8ui64, "DUIRenderCommand", 0x800ui64);
    v10 = v9;
    if ( v9 )
    {
      v20 = (__int128)*colourL;
      v19 = (__int128)*colourR;
      v18 = (__int128)*colourR;
      v17 = (__int128)*colourL;
      mH = rect->mH;
      mW = rect->mW;
      mY = rect->mY;
      mX = rect->mX;
      v9->mNext = v9;
      v9[1].mNext = v9;
      UFG::qString::qString((UFG::qString *)&v9[14]);
      LODWORD(v10[2].mNext) = 7;
      HIDWORD(v10[2].mNext) = mX;
      LODWORD(v10[3].mNext) = mY;
      HIDWORD(v10[3].mNext) = mW;
      LODWORD(v10[4].mNext) = mH;
      v10[5].mNext = (UFG::allocator::free_link *)texture_uid;
      *(_OWORD *)&v10[6].mNext = v17;
      *(_OWORD *)&v10[8].mNext = v18;
      *(_OWORD *)&v10[10].mNext = v19;
      *(_OWORD *)&v10[12].mNext = v20;
      UFG::qString::Set((UFG::qString *)&v10[14], 0i64);
      LODWORD(v10[19].mNext) = 0;
    }
    else
    {
      v10 = 0i64;
    }
    v15 = &this->mRenderCommands[this->mCurrentCompositeLayer];
    mPrev = v15->mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v10;
    v10->mNext = (UFG::allocator::free_link *)mPrev;
    v10[1].mNext = (UFG::allocator::free_link *)v15;
    v15->mNode.mPrev = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v10;
  }
}

// File Line: 1839
// RVA: 0x19D120
void __fastcall UFG::DUIContext::ReplaceSelection(
        UFG::qString *text,
        int selection_start,
        int selection_end,
        const char *new_text,
        int *highlightStart,
        int *caret_pos,
        bool insert)
{
  __int64 v7; // rbp
  __int64 v8; // r13
  unsigned __int64 v11; // r14
  UFG::allocator::free_link *v12; // rdi
  int mLength; // r8d
  char *v14; // rcx
  signed int v15; // r8d
  int v16; // ecx
  UFG::qString v17; // [rsp+28h] [rbp-50h] BYREF

  v7 = selection_end;
  v8 = selection_start;
  UFG::qString::qString(&v17, new_text);
  if ( (int)v7 - (int)v8 > 0 )
    insert = 1;
  v11 = (unsigned int)(text->mLength + 1 + v17.mLength - (v7 - v8));
  v12 = UFG::qMalloc(v11, UFG::gGlobalNewName, 0i64);
  UFG::qMemCopy(v12, text->mData, v8);
  UFG::qMemCopy((char *)v12 + v8, v17.mData, v17.mLength);
  mLength = text->mLength;
  if ( insert )
  {
    UFG::qMemCopy((char *)v12 + v8 + v17.mLength, &text->mData[v7], mLength - v7);
    v14 = (char *)v12 + v11 - 1;
  }
  else
  {
    v15 = mLength - v17.mLength - v7;
    if ( v15 <= 0 )
    {
      v14 = (char *)v12 + *caret_pos + v17.mLength;
    }
    else
    {
      UFG::qMemCopy((char *)v12 + v8 + v17.mLength, &text->mData[v17.mLength + v7], v15);
      v14 = (char *)&v12[-1].mNext + v11 - v17.mLength + 7;
    }
  }
  UFG::qMemSet(v14, 0, 1u);
  v16 = v8 + v17.mLength;
  *caret_pos = v8 + v17.mLength;
  *highlightStart = v16;
  UFG::qString::Set(text, (const char *)v12);
  operator delete[](v12);
  UFG::qString::~qString(&v17);
}

// File Line: 1882
// RVA: 0x193EB0
void __fastcall UFG::DUIContext::ApplyKeystrokes(
        UFG::qString *text,
        int *caret_pos,
        int *select_pos,
        unsigned __int16 keystroke)
{
  int v4; // r10d
  __int64 mLength; // r13
  int v7; // r9d
  bool v9; // r14
  unsigned int v12; // ebp
  bool v13; // cc
  int v14; // r8d
  int v15; // edi
  UFG::allocator::free_link *v16; // rsi
  __int64 v17; // rax
  bool v18; // sf
  int v19; // eax
  int v20; // eax

  v4 = *caret_pos;
  mLength = text->mLength;
  v7 = *select_pos;
  v9 = *caret_pos < (int)mLength;
  v12 = abs32(*select_pos - *caret_pos);
  if ( keystroke )
  {
    if ( v12 )
    {
      v13 = v7 <= v4;
      v14 = *caret_pos;
      if ( v7 < v4 )
        v4 = v7;
      if ( !v13 )
        v14 = v7;
      UFG::DUIContext::ReplaceSelection(text, v4, v14, &customCaption, select_pos, caret_pos, 1);
    }
    v15 = mLength + 2;
    v16 = UFG::qMalloc((unsigned int)(mLength + 2), UFG::gGlobalNewName, 0i64);
    UFG::qMemCopy(v16, text->mData, mLength);
    UFG::qMemSet((char *)v16 + mLength, 0, 2u);
    if ( (_BYTE)keystroke == 8 )
    {
      if ( !v12 )
      {
        if ( v9 )
        {
          v17 = *caret_pos;
          if ( (int)v17 > 0 )
          {
            UFG::qMemCopy((char *)v16 + v17 - 1, (char *)v16 + v17, v15 - v17);
            v18 = --*caret_pos < 0;
            v19 = 0;
            if ( !v18 )
              v19 = *caret_pos;
            *caret_pos = v19;
          }
        }
        else
        {
          v18 = --*caret_pos < 0;
          v20 = 0;
          if ( !v18 )
            v20 = *caret_pos;
          *caret_pos = v20;
          *((_BYTE *)&v16->mNext + v20) = 0;
        }
      }
    }
    else if ( (_BYTE)keystroke == 127 )
    {
      if ( v9 && !v12 )
        UFG::qMemCopy((char *)v16 + *caret_pos, (char *)&v16->mNext + *caret_pos + 1, v15 - *caret_pos - 1);
    }
    else
    {
      if ( v9 && UFG::DUIContext::sInsertOn )
        UFG::qMemCopy((char *)&v16->mNext + *caret_pos + 1, (char *)v16 + *caret_pos, v15 - *caret_pos - 1);
      *((_BYTE *)&v16->mNext + (*caret_pos)++) = keystroke;
    }
    *select_pos = *caret_pos;
    UFG::qString::Set(text, (const char *)v16);
    operator delete[](v16);
  }
}

// File Line: 1989
// RVA: 0x19A090
bool __fastcall UFG::DUIContext::IsVisible(UFG::DUIContext *this, UFG::DUIPoint *point)
{
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // r8
  int mPrev; // ecx
  int mY; // edx
  int mPrev_high; // ecx
  bool result; // al

  mNext = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
  mPrev = (int)mNext[1].mPrev;
  result = 0;
  if ( point->mX >= mPrev && point->mX <= LODWORD(mNext[1].mNext) + mPrev )
  {
    mY = point->mY;
    mPrev_high = HIDWORD(mNext[1].mPrev);
    if ( mY >= mPrev_high && mY <= HIDWORD(mNext[1].mNext) + mPrev_high - 1 )
      return 1;
  }
  return result;
}

// File Line: 1994
// RVA: 0x1956B0
__int64 __fastcall UFG::DUIContext::ClampCaret(UFG::DUIContext *this, int string_length)
{
  int mCaretPos; // eax
  int mHighlightStart; // eax

  mCaretPos = this->mCaretPos;
  if ( mCaretPos >= 0 )
  {
    if ( mCaretPos > string_length )
      this->mCaretPos = string_length;
  }
  else
  {
    this->mCaretPos = 0;
  }
  mHighlightStart = this->mHighlightStart;
  if ( mHighlightStart >= 0 )
  {
    if ( mHighlightStart > string_length )
      this->mHighlightStart = string_length;
    return (unsigned int)(this->mHighlightStart - this->mCaretPos);
  }
  else
  {
    this->mHighlightStart = 0;
    return (unsigned int)-this->mCaretPos;
  }
}

// File Line: 2017
// RVA: 0x19C3F0
UFG::DUIContext *__fastcall UFG::DUIContext::PushColour(
        UFG::DUIContext *this,
        UFG::DUITheme::ColourKey key,
        UFG::qColour *colour)
{
  __int64 v4; // rsi
  UFG::allocator::free_link *v6; // rax
  UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > *v7; // r9
  __int128 v8; // xmm0
  UFG::qList<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour>,1,0> *v9; // rcx
  UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > *mNext; // rax
  UFG::qColour *v11; // rcx

  v4 = key;
  v6 = UFG::qMalloc(0x20ui64, "DUIColourNode", 0i64);
  v7 = (UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > *)v6;
  if ( v6 )
  {
    v8 = (__int128)*colour;
    v6->mNext = v6;
    v6[1].mNext = v6;
    *(_OWORD *)&v6[2].mNext = v8;
  }
  else
  {
    v7 = 0i64;
  }
  v9 = &this->mThemeColourModifier[v4];
  mNext = v9->mNode.mNext;
  v9->mNode.mNext = v7;
  v7->mPrev = &v9->mNode;
  v7->mNext = mNext;
  mNext->mPrev = v7;
  v11 = &this->mTheme.mColour[v4];
  v11->r = colour->r;
  v11->g = colour->g;
  v11->b = colour->b;
  v11->a = colour->a;
  return this;
}

// File Line: 2042
// RVA: 0x19BFA0
UFG::DUIContext *__fastcall UFG::DUIContext::PopColour(UFG::DUIContext *this, int key)
{
  __int64 v3; // rdi
  __int64 v4; // rsi
  UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > *mNext; // rcx
  UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > *mPrev; // rdx
  UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > *v7; // rax
  UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > *v8; // rdx
  UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > *v9; // rax
  __int64 v10; // r8
  UFG::DUITheme *mSharedTheme; // rcx
  UFG::qColour *v12; // rdx
  UFG::DUIContextVtbl *v13; // rdx
  UFG::qColour *v14; // rcx

  v3 = key;
  v4 = 2 * (key + 63i64);
  mNext = this->mThemeColourModifier[key].mNode.mNext;
  mPrev = mNext->mPrev;
  v7 = mNext->mNext;
  mPrev->mNext = v7;
  v7->mPrev = mPrev;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  v8 = mNext->mPrev;
  v9 = mNext->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  operator delete[](mNext);
  v10 = v3;
  if ( (UFG::qList<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour>,1,0> *)this->mThemeColourModifier[v3].mNode.mNext == &this->mThemeColourModifier[v3] )
  {
    mSharedTheme = this->mSharedTheme;
    v12 = &this->mTheme.mColour[v3];
    v12->r = mSharedTheme->mColour[v10].r;
    v12->g = mSharedTheme->mColour[v10].g;
    v12->b = mSharedTheme->mColour[v10].b;
    v12->a = mSharedTheme->mColour[v10].a;
  }
  else
  {
    v13 = (&this->vfptr)[v4];
    v14 = &this->mTheme.mColour[v3];
    v14->r = *(float *)&v13[2].UpdateUI;
    v14->g = *((float *)&v13[2].UpdateUI + 1);
    v14->b = *(float *)&v13[3].UpdateUI;
    v14->a = *((float *)&v13[3].UpdateUI + 1);
  }
  return this;
}

// File Line: 2353
// RVA: 0x199FB0
bool __fastcall UFG::DUIContext::IsHot(UFG::DUIContext *this, UFG::DUIRect *rect)
{
  return !this->mInputState.mMouseLBIsDown
      && !this->mInputState.mMouseRBIsDown
      && !this->mInputState.mMouseMBIsDown
      && UFG::DUIContext::IsMouseOver(this, rect)
      && !this->mInputState.mMouseEventHandled;
}

// File Line: 2358
// RVA: 0x19A000
bool __fastcall UFG::DUIContext::IsMouseOver(UFG::DUIContext *this, UFG::DUIRect *rect)
{
  int mX; // r11d
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // r9
  int mPrev; // ecx
  int mY; // edx
  int mPrev_high; // ecx
  int v9; // ecx
  bool result; // al

  mX = this->mInputState.mMousePos.mX;
  mNext = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
  mPrev = (int)mNext[1].mPrev;
  result = 0;
  if ( mX >= mPrev && mX <= LODWORD(mNext[1].mNext) + mPrev )
  {
    mY = this->mInputState.mMousePos.mY;
    mPrev_high = HIDWORD(mNext[1].mPrev);
    if ( mY >= mPrev_high
      && mY <= HIDWORD(mNext[1].mNext) + mPrev_high - 1
      && mX >= rect->mX
      && mX <= rect->mW + rect->mX )
    {
      v9 = rect->mY;
      if ( mY >= v9 && mY <= rect->mH + v9 - 1 && !this->mInputState.mMouseEventHandled )
        return 1;
    }
  }
  return result;
}

// File Line: 2368
// RVA: 0x19EA40
bool __fastcall UFG::DUIContext::TakeFocus(
        UFG::DUIContext *this,
        UFG::DUIRect *current_rect,
        UFG::DUIRect *rect_grip,
        bool navigable)
{
  int v4; // ebp
  int mFocusedID; // r8d
  UFG::DUI::NavigationAction mNavigationAction; // r15d
  UFG::DUIInputState *p_mInputState; // rsi
  char v12; // al
  char v13; // cl
  int mY; // edx
  int v15; // ecx
  bool v16; // al
  int v17; // eax
  int mPreviousNavigableID; // eax
  int v19; // eax
  int v20; // edx
  bool v21; // zf
  int v23; // [rsp+50h] [rbp+8h]

  v4 = ++this->mCurrentID;
  mFocusedID = this->mFocusedID;
  v23 = mFocusedID;
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
  mNavigationAction = this->mNavigationAction;
  if ( mNavigationAction == NavigateNowhere )
  {
    p_mInputState = &this->mInputState;
    v12 = 1;
    if ( this->mInputState.mMouseLBWentDown
      || this->mInputState.mMouseRBWentDown
      || (v13 = 0, p_mInputState->mMouseMBWentDown) )
    {
      v13 = 1;
    }
    if ( !p_mInputState->mLMBDoubleClick && !p_mInputState->mRMBDoubleClick && !p_mInputState->mMMBDoubleClick )
      v12 = 0;
    if ( (unsigned __int8)v13 | (unsigned __int8)v12 )
    {
      if ( p_mInputState->mMousePos.mX >= rect_grip->mX && p_mInputState->mMousePos.mX <= rect_grip->mW + rect_grip->mX )
      {
        mY = p_mInputState->mMousePos.mY;
        v15 = rect_grip->mY;
        if ( mY >= v15 && mY <= rect_grip->mH + v15 - 1 )
        {
          v16 = UFG::DUIRect::Contains(
                  (UFG::DUIRect *)&this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext[1],
                  &p_mInputState->mMousePos);
          mFocusedID = v23;
          if ( v16 )
          {
            this->mFocusedID = v4;
            this->mFocusOffset.mX = current_rect->mX - p_mInputState->mMousePos.mX;
            this->mFocusOffset.mY = current_rect->mY - this->mInputState.mMousePos.mY;
          }
        }
      }
    }
  }
  v17 = this->mFocusedID;
  if ( v4 == v17 )
  {
    if ( this->mSeekingNavigable && navigable )
    {
      this->mSeekingNavigable = 0;
      this->mNavigationAction = NavigateNowhere;
      goto LABEL_36;
    }
    switch ( mNavigationAction )
    {
      case NavigateNowhere:
        goto LABEL_36;
      case NavigateToNext:
        mPreviousNavigableID = v17 + 1;
        break;
      case NavigateToPrevious:
        v19 = v17 - 1;
        this->mFocusedID = v19;
        if ( v19 < 0 )
          goto LABEL_35;
        mPreviousNavigableID = this->mPreviousNavigableID;
        break;
      default:
        goto LABEL_35;
    }
    this->mFocusedID = mPreviousNavigableID;
LABEL_35:
    this->mSeekingNavigable = 1;
  }
LABEL_36:
  if ( navigable )
    this->mPreviousNavigableID = v4;
  ++this->mNavigableCount;
LABEL_39:
  v20 = this->mFocusedID;
  if ( mFocusedID != v20 )
  {
    v21 = this->mLastLostFocusID == -1;
    this->mTextBoxCanDragSelect = 0;
    *(_QWORD *)&this->mHighlightStart = 0x7FFFFFFFi64;
    this->mCaretPos = 0;
    this->mFocusRect.mX = rect_grip->mX;
    this->mFocusRect.mY = rect_grip->mY;
    this->mFocusRect.mW = rect_grip->mW;
    this->mFocusRect.mH = rect_grip->mH;
    if ( v21 )
      this->mLastLostFocusID = mFocusedID;
  }
  return v4 == v20;
}

// File Line: 2485
// RVA: 0x19C820
void __fastcall UFG::RedistributeGridLines(__int64 ints, int count, unsigned int scale)
{
  int v3; // r10d
  __int64 v4; // r9
  signed int v6; // edi
  __m128i v7; // xmm2
  __m128i v8; // xmm1
  __int64 v9; // rax
  __m128i v10; // xmm0
  __m128i v11; // xmm1
  __m128i v12; // xmm1
  __int64 v13; // r8
  int v14; // r11d
  int v15; // ebx
  int v16; // edx
  __m128d v17; // xmm2
  __m128d v18; // xmm3
  int v19; // eax
  __int64 v20; // rcx
  unsigned int *v21; // rdx
  unsigned __int64 v22; // r10
  double v23; // xmm4_8
  double v24; // xmm2_8
  __m128i v25; // xmm0
  __m128i v26; // xmm1
  int v27; // eax
  int v28; // eax
  __m128i v29; // xmm0

  v3 = 0;
  v4 = ints;
  v6 = 0;
  LODWORD(ints) = 0;
  if ( count >= 8 )
  {
    v7 = 0i64;
    v8 = 0i64;
    do
    {
      v9 = (int)ints;
      LODWORD(ints) = ints + 8;
      v7 = _mm_add_epi32(_mm_loadu_si128((const __m128i *)(v4 + 4 * v9)), v7);
      v10 = _mm_add_epi32(_mm_loadu_si128((const __m128i *)(v4 + 4 * v9 + 16)), v8);
      v8 = v10;
    }
    while ( (int)ints < (int)(count - (count & 0x80000007)) );
    v11 = _mm_add_epi32(v10, v7);
    v12 = _mm_add_epi32(v11, _mm_srli_si128(v11, 8));
    v6 = _mm_cvtsi128_si32(_mm_add_epi32(v12, _mm_srli_si128(v12, 4)));
  }
  ints = (int)ints;
  v13 = count;
  v14 = 0;
  v15 = 0;
  if ( (int)ints < (__int64)count )
  {
    if ( count - (__int64)(int)ints >= 2 )
    {
      do
      {
        v14 += *(_DWORD *)(v4 + 4 * ints);
        v15 += *(_DWORD *)(v4 + 4 * ints + 4);
        ints += 2i64;
      }
      while ( ints < count - 1i64 );
    }
    if ( ints < count )
      v6 += *(_DWORD *)(v4 + 4 * ints);
    v6 += v15 + v14;
  }
  if ( count >= 4 )
  {
    v16 = count - (count & 0x80000003);
    v17 = _mm_cvtepi32_pd(_mm_shuffle_epi32(_mm_cvtsi32_si128(v6), 0));
    v18 = _mm_cvtepi32_pd(_mm_shuffle_epi32(_mm_cvtsi32_si128(scale), 0));
    do
    {
      *(_QWORD *)(v4 + 4i64 * v3) = _mm_cvttpd_epi32(
                                      _mm_mul_pd(
                                        _mm_div_pd(
                                          _mm_cvtepi32_pd(_mm_loadl_epi64((const __m128i *)(v4 + 4i64 * v3))),
                                          v17),
                                        v18)).m128i_u64[0];
      v19 = v3 + 2;
      v3 += 4;
      *(_QWORD *)(v4 + 4i64 * v19) = _mm_cvttpd_epi32(
                                       _mm_mul_pd(
                                         _mm_div_pd(
                                           _mm_cvtepi32_pd(_mm_loadl_epi64((const __m128i *)(v4 + 4i64 * v19))),
                                           v17),
                                         v18)).m128i_u64[0];
    }
    while ( v3 < v16 );
  }
  v20 = v3;
  if ( v3 < v13 )
  {
    if ( v13 - v3 >= 4 )
    {
      v21 = (unsigned int *)(v4 + 8 + 4i64 * v3);
      v22 = ((unsigned __int64)(v13 - v3 - 4) >> 2) + 1;
      v23 = (double)(int)scale;
      v24 = 1.0 / (double)v6;
      v20 += 4 * v22;
      do
      {
        v25 = _mm_cvtsi32_si128(*(v21 - 2));
        v26 = _mm_cvtsi32_si128(*v21);
        v21 += 4;
        v27 = (int)(_mm_cvtepi32_pd(v25).m128d_f64[0] * v24 * v23);
        *(double *)v25.m128i_i64 = (double)(int)*(v21 - 5);
        *(v21 - 6) = v27;
        v28 = (int)(*(double *)v25.m128i_i64 * v24 * v23);
        *(double *)v25.m128i_i64 = (double)(int)*(v21 - 3);
        *(v21 - 5) = v28;
        *(v21 - 4) = (int)(_mm_cvtepi32_pd(v26).m128d_f64[0] * v24 * v23);
        *(v21 - 3) = (int)(*(double *)v25.m128i_i64 * v24 * v23);
        --v22;
      }
      while ( v22 );
    }
    for ( ;
          v20 < v13;
          *(_DWORD *)(v4 + 4 * v20 - 4) = (int)(_mm_cvtepi32_pd(v29).m128d_f64[0]
                                              * (1.0
                                               / (double)v6)
                                              * (double)(int)scale) )
    {
      v29 = _mm_cvtsi32_si128(*(_DWORD *)(v4 + 4 * v20++));
    }
  }
}

// File Line: 2500
// RVA: 0x198940
UFG::DUIRect *__fastcall UFG::DUIContext::GetLayoutRect(
        UFG::DUIContext *this,
        UFG::DUIRect *result,
        int rect_width,
        int rect_height)
{
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // r10
  int v5; // esi
  int mRowHeight; // ebp
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v9; // rdi
  int mPrev_high; // r14d
  int v11; // r8d
  int v12; // r9d
  int mLayout_SplitterWidth; // r13d
  int v14; // r12d
  int v15; // r15d
  int mNext_high; // eax
  int mPrev; // eax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v18; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v19; // rcx
  int v20; // eax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v21; // rcx
  bool v22; // cl
  int mX; // r14d
  int mW; // esi
  int mH; // ecx
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

  mNext = this->mLayoutStack.mNode.mNext;
  v5 = rect_height;
  mRowHeight = rect_width;
  v9 = mNext + 1;
  if ( !this->mLayoutOverrideRectEnabled )
  {
    if ( !rect_width )
      mRowHeight = this->mTheme.mRowHeight;
    if ( !rect_height )
      v5 = this->mTheme.mRowHeight;
    mPrev_high = HIDWORD(mNext[4].mPrev);
    v11 = HIDWORD(mNext[5].mPrev);
    v12 = (int)mNext[5].mNext;
    *result = (UFG::DUIRect)mNext[2];
    mLayout_SplitterWidth = 0;
    v14 = 0;
    v15 = 0;
    v37 = 0;
    if ( (mPrev_high & 8) != 0 )
    {
      mNext_high = HIDWORD(mNext[4].mNext);
      if ( mNext_high > 0 && mNext_high <= v11 )
      {
        mLayout_SplitterWidth = this->mTheme.mLayout_SplitterWidth;
        v14 = -mLayout_SplitterWidth;
      }
      mPrev = (int)mNext[5].mPrev;
      if ( mPrev > 0 && mPrev < v12 )
      {
        v37 = this->mTheme.mLayout_SplitterWidth;
        v15 = -v37;
      }
    }
    if ( !v12 )
      result->mH = v5;
    if ( !v11 )
      result->mW = mRowHeight;
    v18 = mNext[6].mPrev;
    if ( (mPrev_high & 4) != 0 )
    {
      if ( v18 )
      {
        result->mW = *((_DWORD *)&v18->mPrev + SHIDWORD(mNext[4].mNext));
      }
      else if ( v11 > 0 )
      {
        result->mW = SLODWORD(mNext[1].mNext) / v11;
      }
      v19 = mNext[6].mNext;
      if ( v19 )
      {
        result->mH = *((_DWORD *)&v19->mPrev + SLODWORD(mNext[5].mPrev));
        goto LABEL_42;
      }
      if ( v12 > 0 )
      {
        v20 = SHIDWORD(mNext[1].mNext) / v12;
LABEL_41:
        result->mH = v20;
      }
    }
    else
    {
      if ( v18 )
      {
        result->mW = *((_DWORD *)&v18->mPrev + SHIDWORD(mNext[4].mNext));
      }
      else if ( v11 > 0 )
      {
        result->mW = SLODWORD(mNext[1].mNext) / v11;
      }
      v21 = mNext[6].mNext;
      if ( v21 )
      {
        result->mH = *((_DWORD *)&v21->mPrev + SLODWORD(mNext[5].mPrev));
      }
      else if ( v12 > 0 )
      {
        result->mH = v5;
      }
      if ( (mPrev_high & 3) != 0 )
      {
        v22 = LODWORD(mNext[5].mPrev) == v12 - 1;
        if ( HIDWORD(mNext[4].mNext) == v11 - 1 && (mPrev_high & 1) != 0 )
          result->mW = LODWORD(v9->mPrev) + LODWORD(mNext[1].mNext) - LODWORD(mNext[2].mPrev);
        if ( v22 && (mPrev_high & 2) != 0 )
        {
          v20 = HIDWORD(mNext[1].mPrev) + HIDWORD(mNext[1].mNext) - HIDWORD(mNext[2].mPrev);
          goto LABEL_41;
        }
      }
    }
LABEL_42:
    result->mX += mLayout_SplitterWidth;
    result->mW += v14;
    result->mH += v15;
    mX = result->mX;
    mW = result->mW;
    result->mY += v37;
    mH = result->mH;
    if ( v11 <= 0 )
    {
      if ( v12 <= 0 )
        goto LABEL_50;
      if ( ++LODWORD(mNext[5].mPrev) >= v12 )
      {
        ++HIDWORD(mNext[4].mNext);
        LODWORD(mNext[5].mPrev) = 0;
        LODWORD(mNext[2].mPrev) += mW;
        HIDWORD(mNext[2].mPrev) = HIDWORD(mNext[1].mPrev);
        goto LABEL_50;
      }
    }
    else
    {
      if ( ++HIDWORD(mNext[4].mNext) < v11 )
      {
        LODWORD(mNext[2].mPrev) += mW - v14;
LABEL_50:
        mNext = this->mLayoutStack.mNode.mNext;
        v26 = this->mTheme.mIndent * LODWORD(mNext[4].mPrev);
        result->mX = v26 + mX + LODWORD(mNext[9].mNext);
        v27 = HIDWORD(mNext[9].mNext);
        result->mW = mW - v26;
        result->mY += v27;
        goto LABEL_52;
      }
      ++LODWORD(mNext[5].mPrev);
      HIDWORD(mNext[4].mNext) = 0;
      LODWORD(mNext[2].mPrev) = v9->mPrev;
    }
    HIDWORD(mNext[2].mPrev) += mH - v15;
    goto LABEL_50;
  }
  v28 = this->mLayoutOverrideRect.mX;
  this->mLayoutOverrideRectEnabled = 0;
  result->mX = v28;
  result->mY = this->mLayoutOverrideRect.mY;
  result->mW = this->mLayoutOverrideRect.mW;
  result->mH = this->mLayoutOverrideRect.mH;
LABEL_52:
  v29 = *(_QWORD *)&result->mW;
  v30 = _mm_cvtsi32_si128(-HIDWORD(v9->mPrev));
  v31 = (float)(int)HIDWORD(*(_QWORD *)&result->mX);
  v32 = (int)mNext[3].mNext;
  if ( v32 < (int)v29 + (int)(float)((float)-LODWORD(v9->mPrev) + (float)(int)*(_QWORD *)&result->mX) )
    v32 = v29 + (int)(float)((float)-LODWORD(v9->mPrev) + (float)(int)*(_QWORD *)&result->mX);
  v33 = HIDWORD(mNext[3].mNext);
  LODWORD(mNext[3].mNext) = v32;
  v34 = HIDWORD(v29) + (int)(float)(_mm_cvtepi32_ps(v30).m128_f32[0] + v31);
  if ( v33 < v34 )
    v33 = v34;
  v35 = result->mX;
  HIDWORD(mNext[3].mNext) = v33;
  this->mLastRect.mX = v35;
  this->mLastRect.mY = result->mY;
  this->mLastRect.mW = result->mW;
  this->mLastRect.mH = result->mH;
  return result;
}

// File Line: 2681
// RVA: 0x198F00
UFG::DUIContext *__fastcall UFG::DUIContext::GridSplitter(
        UFG::DUIContext *this,
        int width,
        int *xy,
        UFG::DUIContext::Orient orient)
{
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // r10
  int mPrev; // eax
  int mNext_high; // ecx
  int grip_min_w; // eax
  bool v10; // al
  UFG::DUIRect rect_track; // [rsp+70h] [rbp-28h] BYREF
  UFG::DUIRect rect_grip; // [rsp+80h] [rbp-18h] BYREF
  long double value_y; // [rsp+A0h] [rbp+8h] BYREF
  long double value_x; // [rsp+B0h] [rbp+18h] BYREF

  mNext = this->mLayoutStack.mNode.mNext;
  mPrev = (int)mNext[1].mPrev;
  mNext_high = HIDWORD(mNext[1].mNext);
  value_y = (double)*xy;
  rect_track.mX = mPrev;
  rect_track.mY = HIDWORD(mNext[1].mPrev);
  grip_min_w = (int)mNext[1].mNext;
  rect_track.mH = mNext_high;
  *(_QWORD *)&rect_grip.mX = 0i64;
  *(_QWORD *)&rect_grip.mW = 0i64;
  rect_track.mW = grip_min_w;
  if ( orient )
  {
    if ( orient != Orient_Horizontal )
      goto LABEL_7;
    value_x = 0.0;
    v10 = UFG::DUIContext::Draggable2D(
            this,
            &value_x,
            &value_y,
            &rect_grip,
            &rect_track,
            0.0,
            0.0,
            0.0,
            (double)(mNext_high - width),
            1.0,
            1.0 / (double)mNext_high * (double)width,
            grip_min_w,
            width,
            0);
  }
  else
  {
    value_x = 0.0;
    v10 = UFG::DUIContext::Draggable2D(
            this,
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
    this->mInputState.mMouseWheelDelta = 0;
    *(_QWORD *)&this->mInputState.mMouseLBWentDown = 0i64;
    *(_WORD *)&this->mInputState.mLMBDoubleClick = 0;
    this->mInputState.mMouseMBWentUp = 0;
    this->mInputState.mMMBDoubleClick = 0;
    this->mInputState.mMouseEventHandled = 1;
  }
LABEL_7:
  *xy = (int)value_y;
  return this;
}

// File Line: 2717
// RVA: 0x19DA00
UFG::DUIContext *__fastcall UFG::DUIContext::SetLayoutRect(UFG::DUIContext *this, UFG::DUIRect *rect)
{
  int mH; // eax

  this->mLayoutOverrideRect.mX = rect->mX;
  this->mLayoutOverrideRect.mY = rect->mY;
  this->mLayoutOverrideRect.mW = rect->mW;
  mH = rect->mH;
  this->mLayoutOverrideRectEnabled = 1;
  this->mLayoutOverrideRect.mH = mH;
  return this;
}

// File Line: 2731
// RVA: 0x19C540
UFG::DUILayoutState *__fastcall UFG::DUIContext::PushLayoutState(
        UFG::DUIContext *this,
        UFG::DUIRect *rect,
        UFG::DUI::LayoutFlag flags)
{
  UFG::allocator::free_link *v6; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v7; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v8; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // rcx

  v6 = UFG::qMalloc(0xB8ui64, "DUILayoutState", 0x800ui64);
  if ( v6 )
  {
    UFG::DUILayoutState::DUILayoutState((UFG::DUILayoutState *)v6, rect, flags, 0);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  mNext = this->mLayoutStack.mNode.mNext;
  this->mLayoutStack.mNode.mNext = v8;
  v8->mPrev = &this->mLayoutStack.mNode;
  v8->mNext = mNext;
  mNext->mPrev = v8;
  return (UFG::DUILayoutState *)v8;
}

// File Line: 2739
// RVA: 0x19C4A0
UFG::DUILayoutState *__fastcall UFG::DUIContext::PushLayoutState(
        UFG::DUIContext *this,
        UFG::DUIRect *rect,
        UFG::DUIRect *scissor_rect,
        UFG::DUI::LayoutFlag flags)
{
  UFG::allocator::free_link *v8; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v9; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v10; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // rcx

  v8 = UFG::qMalloc(0xB8ui64, "DUILayoutState", 0x800ui64);
  if ( v8 )
  {
    UFG::DUILayoutState::DUILayoutState((UFG::DUILayoutState *)v8, rect, flags, 1);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  mNext = this->mLayoutStack.mNode.mNext;
  this->mLayoutStack.mNode.mNext = v10;
  v10->mPrev = &this->mLayoutStack.mNode;
  v10->mNext = mNext;
  mNext->mPrev = v10;
  UFG::DUIContext::PushScissor(this, scissor_rect);
  return (UFG::DUILayoutState *)v10;
}

// File Line: 2749
// RVA: 0x19C5D0
void __fastcall UFG::DUIContext::PushScissor(UFG::DUIContext *this, UFG::DUIRect *scissor_rect)
{
  __int64 mCurrentCompositeLayer; // rcx
  int mX; // r15d
  int mY; // r8d
  int mPrev_high; // r12d
  int v7; // ebp
  int v8; // ebp
  int v9; // r14d
  int v10; // r14d
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v12; // rdx
  UFG::qList<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect>,1,0> *v13; // rcx
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rdi
  UFG::qColour v17; // xmm6
  UFG::qList<UFG::DUIRenderCommand,UFG::DUIRenderCommand,1,0> *v18; // rcx
  UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *mPrev; // rax
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > v20; // [rsp+30h] [rbp-78h]

  mCurrentCompositeLayer = this->mCurrentCompositeLayer;
  if ( (UFG::qList<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect>,1,0> *)this->mScissorStacks[mCurrentCompositeLayer].mNode.mNext == &this->mScissorStacks[mCurrentCompositeLayer] )
  {
    v20.mPrev = 0i64;
    v20.mNext = (UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *)0xC35000001388i64;
  }
  else
  {
    v20 = this->mScissorStacks[mCurrentCompositeLayer].mNode.mNext[1];
  }
  mX = scissor_rect->mX;
  if ( SLODWORD(v20.mPrev) > scissor_rect->mX )
    mX = (int)v20.mPrev;
  mY = scissor_rect->mY;
  mPrev_high = mY;
  if ( SHIDWORD(v20.mPrev) > mY )
    mPrev_high = HIDWORD(v20.mPrev);
  v7 = scissor_rect->mX + scissor_rect->mW;
  if ( LODWORD(v20.mNext) + LODWORD(v20.mPrev) < v7 )
    v7 = LODWORD(v20.mNext) + LODWORD(v20.mPrev);
  v8 = v7 - mX;
  v9 = mY + scissor_rect->mH;
  if ( HIDWORD(v20.mNext) + HIDWORD(v20.mPrev) < v9 )
    v9 = HIDWORD(v20.mNext) + HIDWORD(v20.mPrev);
  v10 = v9 - mPrev_high;
  v11 = UFG::qMalloc(0x20ui64, "DUIScissorRect", 0i64);
  v12 = (UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *)v11;
  if ( v11 )
  {
    v11->mNext = v11;
    v11[1].mNext = v11;
    LODWORD(v11[2].mNext) = mX;
    HIDWORD(v11[2].mNext) = mPrev_high;
    LODWORD(v11[3].mNext) = v8;
    HIDWORD(v11[3].mNext) = v10;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = &this->mScissorStacks[this->mCurrentCompositeLayer];
  mNext = v13->mNode.mNext;
  v13->mNode.mNext = v12;
  v12->mPrev = &v13->mNode;
  v12->mNext = mNext;
  mNext->mPrev = v12;
  if ( this->mBuildCommandList )
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
      HIDWORD(v16[2].mNext) = mX;
      LODWORD(v16[3].mNext) = mPrev_high;
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
    v18 = &this->mRenderCommands[this->mCurrentCompositeLayer];
    mPrev = v18->mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v16;
    v16->mNext = (UFG::allocator::free_link *)mPrev;
    v16[1].mNext = (UFG::allocator::free_link *)v18;
    v18->mNode.mPrev = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v16;
  }
}

// File Line: 2780
// RVA: 0x19C110
void __fastcall UFG::DUIContext::PopScissor(UFG::DUIContext *this)
{
  UFG::qList<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect>,1,0> *v2; // rcx
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // rcx
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mPrev; // rdx
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v5; // rax
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v6; // rdx
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v7; // rax
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v8; // rbx
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // r15
  int mNext_high; // ebp
  int v12; // esi
  int mPrev_high; // edi
  int v14; // ebx
  UFG::qList<UFG::DUIRenderCommand,UFG::DUIRenderCommand,1,0> *v15; // rcx
  UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *v16; // rax
  UFG::qColour v17; // [rsp+30h] [rbp-68h]
  UFG::qColour v18; // [rsp+40h] [rbp-58h]
  UFG::qColour v19; // [rsp+50h] [rbp-48h]
  UFG::qColour v20; // [rsp+60h] [rbp-38h]

  v2 = &this->mScissorStacks[this->mCurrentCompositeLayer];
  if ( (UFG::qList<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect>,1,0> *)v2->mNode.mNext != v2 )
  {
    mNext = v2->mNode.mNext;
    mPrev = mNext->mPrev;
    v5 = mNext->mNext;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v6 = mNext->mPrev;
    v7 = mNext->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    operator delete[](mNext);
    v8 = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
    if ( this->mBuildCommandList )
    {
      v9 = UFG::qMalloc(0xA8ui64, "DUIRenderCommand", 0x800ui64);
      v10 = v9;
      if ( v9 )
      {
        v20 = UFG::qColourWhite;
        v19 = UFG::qColourWhite;
        v18 = UFG::qColourWhite;
        v17 = UFG::qColourWhite;
        mNext_high = HIDWORD(v8[1].mNext);
        v12 = (int)v8[1].mNext;
        mPrev_high = HIDWORD(v8[1].mPrev);
        v14 = (int)v8[1].mPrev;
        v9->mNext = v9;
        v9[1].mNext = v9;
        UFG::qString::qString((UFG::qString *)&v9[14]);
        LODWORD(v10[2].mNext) = 3;
        HIDWORD(v10[2].mNext) = v14;
        LODWORD(v10[3].mNext) = mPrev_high;
        HIDWORD(v10[3].mNext) = v12;
        LODWORD(v10[4].mNext) = mNext_high;
        v10[5].mNext = 0i64;
        *(UFG::qColour *)&v10[6].mNext = v17;
        *(UFG::qColour *)&v10[8].mNext = v18;
        *(UFG::qColour *)&v10[10].mNext = v19;
        *(UFG::qColour *)&v10[12].mNext = v20;
        UFG::qString::Set((UFG::qString *)&v10[14], 0i64);
        LODWORD(v10[19].mNext) = 0;
      }
      else
      {
        v10 = 0i64;
      }
      v15 = &this->mRenderCommands[this->mCurrentCompositeLayer];
      v16 = v15->mNode.mPrev;
      v16->mNext = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v10;
      v10->mNext = (UFG::allocator::free_link *)v16;
      v10[1].mNext = (UFG::allocator::free_link *)v15;
      v15->mNode.mPrev = (UFG::qNode<UFG::DUIRenderCommand,UFG::DUIRenderCommand> *)v10;
    }
  }
}

// File Line: 2797
// RVA: 0x19C090
void __fastcall UFG::DUIContext::PopLayoutState(UFG::DUIContext *this)
{
  UFG::DUILayoutState *mNext; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mPrev; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v4; // rax

  mNext = (UFG::DUILayoutState *)this->mLayoutStack.mNode.mNext;
  mPrev = mNext->mPrev;
  v4 = mNext->mNext;
  mPrev->mNext = v4;
  v4->mPrev = mPrev;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  if ( mNext->mClip )
    UFG::DUIContext::PopScissor(this);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)this->mLayoutStack.mNode.mNext != &this->mLayoutStack
    && this->mCurrentCompositeLayer != CompositeLayer_Overlay )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&this->mLayoutStack.mNode.mNext[3], &mNext->mMaximumRect);
  }
  UFG::DUILayoutState::~DUILayoutState(mNext);
  operator delete[](mNext);
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
  LODWORD(this->mLayoutStack.mNode.mNext[4].mPrev) = (int)v1;
  return this;
}

// File Line: 3005
// RVA: 0x195720
bool __fastcall UFG::DUIContext::Clickable(
        UFG::DUIContext *this,
        UFG::DUIContext::ClickableState *click_state,
        UFG::DUIRect *current_rect,
        UFG::DUIRect *rect_grip,
        UFG::DUIContext::ClickableFlags flags)
{
  int mX; // edx
  int mY; // edx
  int v10; // ecx

  *click_state = Clickable_Unknown;
  this->mDoubleClicked = 0;
  if ( UFG::DUIContext::TakeFocus(this, current_rect, rect_grip, 0) )
  {
    if ( this->mInputState.mMouseLBWentDown || this->mInputState.mMouseLBIsDown )
      *click_state = Clickable_HasFocus;
    mX = this->mInputState.mMousePos.mX;
    if ( mX >= rect_grip->mX && mX <= rect_grip->mW + rect_grip->mX )
    {
      mY = this->mInputState.mMousePos.mY;
      v10 = rect_grip->mY;
      if ( mY >= v10 && mY <= rect_grip->mH + v10 - 1 && !this->mInputState.mMouseEventHandled )
      {
        if ( this->mInputState.mMouseLBWentUp )
        {
          *click_state = Clickable_Clicked;
          this->mDoubleClicked = 0;
        }
        else if ( this->mInputState.mLMBDoubleClick )
        {
          *click_state = Clickable_DblClicked;
          this->mDoubleClicked = 1;
        }
      }
    }
    if ( this->mInputState.mMouseLBWentUp )
    {
      this->mFocusedID = -1;
      this->mFocusOffset = (UFG::DUIPoint)-1i64;
      this->mDoubleClicked = 0;
      if ( *click_state == Clickable_HasFocus )
        *click_state = UFG::DUIContext::IsHot(this, rect_grip);
    }
    if ( (flags & 1) != 0 )
    {
      this->mInputState.mMouseWheelDelta = 0;
      *(_QWORD *)&this->mInputState.mMouseLBWentDown = 0i64;
      *(_WORD *)&this->mInputState.mLMBDoubleClick = 0;
      this->mInputState.mMouseMBWentUp = 0;
      this->mInputState.mMMBDoubleClick = 0;
    }
  }
  else if ( !this->mInputState.mMouseLBIsDown
         && !this->mInputState.mMouseRBIsDown
         && !this->mInputState.mMouseMBIsDown
         && UFG::DUIContext::IsMouseOver(this, rect_grip)
         && !this->mInputState.mMouseEventHandled )
  {
    *click_state = Clickable_IsHot;
  }
  return *click_state == Clickable_Clicked;
}

// File Line: 3159
// RVA: 0x197670
bool __fastcall UFG::DUIContext::Draggable2D(
        UFG::DUIContext *this,
        long double *value_x,
        long double *value_y,
        UFG::DUIRect *rect_grip,
        UFG::DUIRect *rect_track,
        double value_min_x,
        double value_min_y,
        double value_max_x,
        double value_max_y,
        double grip_pw,
        double grip_ph,
        int grip_min_w,
        int grip_min_h,
        bool quantize_value)
{
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
  int mW; // ebp
  int mH; // r12d
  int v34; // r8d
  int v35; // edx
  double v36; // xmm0_8
  int v37; // ecx
  int v38; // ebp
  int v39; // r12d
  int v40; // eax
  int mX; // edx
  int mY; // ecx
  float v43; // xmm2_4
  int v44; // edx
  int v45; // eax
  int v46; // r8d
  int v47; // edx
  int v48; // ecx
  int v49; // eax
  int v50; // ecx
  int v51; // eax
  double v52; // xmm0_8
  bool result; // al
  double value_min_xa; // [rsp+118h] [rbp+30h]
  double value_max_xa; // [rsp+128h] [rbp+40h]

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
  mW = rect_track->mW;
  mH = rect_track->mH;
  v34 = mW;
  v35 = mH;
  if ( (int)((double)mW * v29) > grip_min_w )
    v31 = (int)((double)rect_track->mW * v29);
  if ( v31 < mW )
    v34 = v31;
  v37 = grip_min_h;
  v36 = (double)rect_track->mH;
  if ( (int)(v36 * v30) > grip_min_h )
    v37 = (int)(v36 * v30);
  if ( v37 < mH )
    v35 = v37;
  v38 = mW - v34 - 1;
  v39 = mH - v35 - 1;
  value_max_xa = v22 / (double)v38;
  value_min_xa = v26 / (double)v39;
  rect_grip->mX = rect_track->mX + (int)((double)v38 * v27);
  v40 = rect_track->mY + (int)((double)v39 * v28);
  rect_grip->mH = v35;
  rect_grip->mW = v34;
  rect_grip->mY = v40;
  UFG::DUIContext::Clickable(
    this,
    (UFG::DUIContext::ClickableState *)&grip_min_w,
    rect_grip,
    rect_grip,
    ClickableFlags_None);
  if ( grip_min_w != 2 )
    return 0;
  if ( value_max_xa < 1.0 )
    mX = 0;
  else
    mX = this->mFocusOffset.mX;
  if ( value_min_xa < 1.0 )
    mY = 0;
  else
    mY = this->mFocusOffset.mY;
  v43 = (float)(mY + this->mInputState.mMousePos.mY - rect_track->mY) / (float)rect_track->mH;
  v44 = rect_track->mX
      + (int)(float)((float)((float)(mX + this->mInputState.mMousePos.mX - rect_track->mX) / (float)rect_track->mW)
                   * (float)rect_track->mW);
  rect_grip->mX = v44;
  v45 = rect_track->mY + (int)(float)((float)rect_track->mH * v43);
  rect_grip->mY = v45;
  v46 = rect_track->mX - rect_grip->mW + rect_track->mW - 1;
  if ( v44 < v46 )
    v46 = v44;
  rect_grip->mX = v46;
  v47 = rect_track->mH - rect_grip->mH + rect_track->mY - 1;
  if ( v45 < v47 )
    v47 = v45;
  rect_grip->mY = v47;
  v48 = rect_track->mX;
  if ( v46 > rect_track->mX )
    v48 = v46;
  rect_grip->mX = v48;
  v49 = rect_track->mY;
  if ( v47 > v49 )
    v49 = v47;
  rect_grip->mY = v49;
  v50 = v48 - rect_track->mX;
  v51 = v49 - rect_track->mY;
  if ( v50 > 0 )
  {
    if ( v50 < v38 )
      *value_x = (double)v50 * value_max_xa + value_min_x;
    else
      *value_x = value_max_x;
  }
  else
  {
    *value_x = value_min_x;
  }
  if ( v51 > 0 )
  {
    if ( v51 < v39 )
      *value_y = (double)v51 * value_min_xa + value_min_y;
    else
      *value_y = value_max_y;
  }
  else
  {
    *value_y = value_min_y;
  }
  if ( quantize_value )
  {
    if ( v22 <= 0.0 )
      v52 = 0.0;
    else
      v52 = ((double)(int)*value_x - value_min_x) / v22;
    if ( v26 > 0.0 )
      v25 = ((double)(int)*value_y - value_min_y) / v26;
    rect_grip->mX = rect_track->mX + (int)((double)v38 * v52);
    rect_grip->mY = rect_track->mY + (int)((double)v39 * v25);
  }
  this->mInputState.mMouseWheelDelta = 0;
  *(_QWORD *)&this->mInputState.mMouseLBWentDown = 0i64;
  *(_WORD *)&this->mInputState.mLMBDoubleClick = 0;
  this->mInputState.mMouseMBWentUp = 0;
  this->mInputState.mMMBDoubleClick = 0;
  result = 1;
  this->mInputState.mMouseEventHandled = 1;
  return result;
}

// File Line: 3261
// RVA: 0x19D290
bool __fastcall UFG::DUIContext::Scrollbar(UFG::DUIContext *this, UFG::DUIRect *rect, int *current_value, int min)
{
  int v4; // r12d
  int v6; // r14d
  int v8; // r8d
  int v9; // ecx
  int mX; // edi
  int mY; // r11d
  double v12; // xmm6_8
  bool v13; // r10
  int mSliderSize; // eax
  long double *v15; // r8
  long double *p_value_y; // rdx
  int v17; // eax
  bool v18; // al
  int v19; // r9d
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // rdx
  int mPrev; // ecx
  int v22; // r8d
  int mPrev_high; // ecx
  bool v24; // cl
  UFG::qColour *mColour; // rax
  float g; // xmm1_4
  float b; // xmm0_4
  float a; // xmm1_4
  double value_min_x; // [rsp+28h] [rbp-51h]
  double value_min_y; // [rsp+30h] [rbp-49h]
  double value_max_x; // [rsp+38h] [rbp-41h]
  double value_max_y; // [rsp+40h] [rbp-39h]
  UFG::DUIRect rect_grip; // [rsp+48h] [rbp-31h] BYREF
  UFG::DUIRect recta; // [rsp+58h] [rbp-21h] BYREF
  UFG::qColour quantize_value[5]; // [rsp+68h] [rbp-11h] BYREF
  long double value_y; // [rsp+C8h] [rbp+4Fh] BYREF
  long double value_x[2]; // [rsp+D0h] [rbp+57h] BYREF
  void *retaddr; // [rsp+E8h] [rbp+6Fh]
  int v40; // [rsp+F0h] [rbp+77h]
  int v41; // [rsp+F8h] [rbp+7Fh]

  v4 = *current_value;
  v6 = rect->mW - 4;
  recta.mX = rect->mX + 2;
  v8 = rect->mH - 4;
  recta.mY = rect->mY + 1;
  recta.mW = v6;
  recta.mH = v8;
  v9 = (_DWORD)retaddr - v40;
  mX = 0;
  *(_QWORD *)&rect_grip.mX = 0i64;
  mY = 0;
  *(_QWORD *)&rect_grip.mW = 0i64;
  if ( min > (int)retaddr - v40 )
    v9 = min;
  if ( (int)retaddr - min <= 0 )
    v12 = DOUBLE_1_0;
  else
    v12 = (double)v40 / (double)((int)retaddr - min);
  v13 = 0;
  value_y = (double)v4;
  if ( v41 == 1 )
  {
    mSliderSize = this->mTheme.mSliderSize;
    LOBYTE(quantize_value[0].r) = 1;
    recta.mW = v8;
    recta.mX = mSliderSize;
    v15 = value_x;
    p_value_y = &value_y;
    *(long double *)&rect_grip.mW = DOUBLE_1_0;
    *(double *)&rect_grip.mX = v12;
    value_max_y = 0.0;
    value_max_x = (double)v9;
    value_min_y = 0.0;
    value_min_x = (double)min;
LABEL_10:
    value_x[0] = 0.0;
    v18 = UFG::DUIContext::Draggable2D(
            this,
            p_value_y,
            v15,
            &rect_grip,
            &recta,
            value_min_x,
            value_min_y,
            value_max_x,
            value_max_y,
            *(double *)&rect_grip.mX,
            *(double *)&rect_grip.mW,
            recta.mX,
            recta.mW,
            SLOBYTE(quantize_value[0].r));
    mX = rect_grip.mX;
    mY = rect_grip.mY;
    v13 = v18;
    goto LABEL_11;
  }
  if ( !v41 )
  {
    v17 = this->mTheme.mSliderSize;
    LOBYTE(quantize_value[0].r) = 1;
    recta.mW = v17;
    recta.mX = v6;
    v15 = &value_y;
    p_value_y = value_x;
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
  if ( !this->mInputState.mMouseLBIsDown && !this->mInputState.mMouseRBIsDown && !this->mInputState.mMouseMBIsDown )
  {
    v19 = this->mInputState.mMousePos.mX;
    mNext = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
    mPrev = (int)mNext[1].mPrev;
    if ( v19 >= mPrev && v19 <= LODWORD(mNext[1].mNext) + mPrev )
    {
      v22 = this->mInputState.mMousePos.mY;
      mPrev_high = HIDWORD(mNext[1].mPrev);
      if ( v22 >= mPrev_high
        && v22 <= HIDWORD(mNext[1].mNext) + mPrev_high - 1
        && v19 >= mX
        && v19 <= mX + rect_grip.mW
        && v22 >= mY
        && v22 <= mY + rect_grip.mH - 1
        && !this->mInputState.mMouseEventHandled )
      {
        v24 = 1;
      }
    }
  }
  if ( v13 )
    *current_value = (int)value_y;
  if ( v24 || (mColour = this->mTheme.mColour, v13) )
    mColour = &this->mTheme.mColour[20];
  g = mColour->g;
  quantize_value[0].r = mColour->r;
  b = mColour->b;
  quantize_value[0].g = g;
  a = mColour->a;
  quantize_value[0].b = b;
  quantize_value[0].a = a;
  if ( v12 >= 1.0 )
    quantize_value[0].a = FLOAT_0_2;
  UFG::DUIContext::RenderRoundRect(this, &recta, &this->mTheme.mColour[18], 0);
  UFG::DUIContext::RenderRoundRect(this, &rect_grip, quantize_value, 0);
  return *current_value != v4;
}

// File Line: 3318
// RVA: 0x1992B0
void __fastcall UFG::DUIContext::Header(
        UFG::DUIContext *this,
        const char *name,
        UFG::qColour *fg_colour,
        UFG::qColour *bg_colour)
{
  UFG::qColour *v4; // rdi
  UFG::qColour *mColour; // rsi
  int mX; // ecx
  int mY; // edx
  int v10; // r8d
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  UFG::DUIRect v14; // xmm0
  UFG::DUIRect v15; // [rsp+30h] [rbp-30h] BYREF
  UFG::DUIRect result; // [rsp+40h] [rbp-20h] BYREF
  UFG::DUIRect rect; // [rsp+50h] [rbp-10h] BYREF

  v4 = bg_colour;
  mColour = fg_colour;
  if ( !fg_colour )
    mColour = this->mTheme.mColour;
  if ( !bg_colour )
    v4 = &this->mTheme.mColour[11];
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  mX = this->mTheme.mButton_Inset.mX;
  mY = this->mTheme.mButton_Inset.mY;
  v15.mH = result.mH;
  v10 = _mm_cvtsi128_si32((__m128i)result);
  v15.mY = mY + result.mY;
  v15.mX = v10 + mX;
  v15.mW = result.mW - 2 * mX;
  v11 = result.mH - 2 * mY;
  v12 = this->mTheme.mButton_Text.mY;
  v15.mH = v11;
  v13 = this->mTheme.mButton_Text.mX;
  v14 = v15;
  v15.mY = v12 + result.mY;
  rect = v14;
  v15.mX = v10 + v13;
  v15.mW = result.mW - 2 * v13;
  v15.mH = result.mH - 2 * v12;
  UFG::DUIContext::PushScissor(this, &result);
  UFG::DUIContext::RenderRect(this, &rect, v4, 0);
  UFG::DUIContext::RenderText(this, &v15, mColour, name, 0x10u);
  UFG::DUIContext::PopScissor(this);
}

// File Line: 3340
// RVA: 0x19A0E0
void __fastcall UFG::DUIContext::Label(UFG::DUIContext *this, const char *name)
{
  UFG::DUIRect result; // [rsp+30h] [rbp-18h] BYREF

  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  result.mX += 4;
  result.mW -= 4;
  UFG::DUIContext::PushScissor(this, &result);
  UFG::DUIContext::RenderText(this, &result, this->mTheme.mColour, name, 0x10u);
  UFG::DUIContext::PopScissor(this);
}

// File Line: 3355
// RVA: 0x19D560
void __fastcall UFG::DUIContext::Separator(UFG::DUIContext *this)
{
  int mSeperator_TopLineY; // ecx
  int mSeperator_TopLineH; // eax
  __int64 v4; // rdx
  int mSeperator_BotLineH; // eax
  int v6; // ecx
  UFG::DUIRect rect; // [rsp+20h] [rbp-28h] BYREF
  UFG::DUIRect result; // [rsp+30h] [rbp-18h] BYREF

  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  mSeperator_TopLineY = this->mTheme.mSeperator_TopLineY;
  result.mH = this->mTheme.mSeperator_RowH;
  mSeperator_TopLineH = this->mTheme.mSeperator_TopLineH;
  rect = result;
  v4 = HIDWORD(*(_QWORD *)&result.mX);
  result.mH = mSeperator_TopLineH;
  mSeperator_BotLineH = this->mTheme.mSeperator_BotLineH;
  result.mY += mSeperator_TopLineY;
  v6 = v4 + this->mTheme.mSeperator_BotLineY;
  rect.mH = mSeperator_BotLineH;
  rect.mY = v6;
  UFG::DUIContext::RenderRoundRect(this, &rect, &this->mTheme.mColour[17], 0);
  UFG::DUIContext::RenderRoundRect(this, &result, &this->mTheme.mColour[16], 0);
}

// File Line: 3373
// RVA: 0x197B20
void __fastcall UFG::DUIContext::Empty(UFG::DUIContext *this)
{
  UFG::DUIRect result; // [rsp+20h] [rbp-18h] BYREF

  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
}

// File Line: 3411
// RVA: 0x19F480
void __fastcall UFG::DUIContext::Tooltip(UFG::DUIContext *this, const char *text, UFG::DUIRect *rect_hover)
{
  unsigned __int64 Ticks; // rax
  int mX; // edx
  int mY; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // r8d
  int v12; // r9d
  int v13; // edx
  UFG::DUIRect rect; // [rsp+30h] [rbp-30h] BYREF
  UFG::DUIRect v15; // [rsp+40h] [rbp-20h] BYREF
  UFG::DUIRect v16; // [rsp+50h] [rbp-10h] BYREF

  if ( text && *text )
  {
    this->mCurrentCompositeLayer = CompositeLayer_Overlay;
    UFG::DUIContext::PushLayoutState(this, &this->mRect, &this->mRect, LayoutFlag_FillLastCell);
    Ticks = UFG::qGetTicks();
    if ( UFG::qGetTickTime(this->mInputState.mLastCursorMoveTime, Ticks) >= 0.31999999 )
    {
      mX = this->mInputState.mMousePos.mX;
      if ( mX >= rect_hover->mX && mX <= rect_hover->mW + rect_hover->mX )
      {
        mY = this->mInputState.mMousePos.mY;
        v9 = rect_hover->mY;
        if ( mY >= v9 && mY <= rect_hover->mH + v9 - 1 )
        {
          v10 = UFG::qStringLength(text);
          v11 = this->mTheme.mButton_Text.mX;
          v12 = this->mTheme.mButton_Text.mY;
          v13 = (int)this->mFontDimensions.y + 2 * v12;
          v16.mX = this->mInputState.mMousePos.mX;
          v16.mH = v13;
          v16.mW = (int)(float)((float)((float)v10 + 1.0) * this->mFontDimensions.x) + 2 * v11;
          v16.mY = v13 + this->mInputState.mMousePos.mY - this->mTheme.mButton_Inset.mY;
          v15.mY = v12 + v16.mY;
          rect.mW = v16.mW + 2;
          rect.mY = v16.mY - 1;
          rect.mH = v13 + 2;
          rect.mX = v16.mX - 1;
          v15.mX = v11 + v16.mX;
          v15.mW = v16.mW - 2 * v11;
          v15.mH = v13 - 2 * v12;
          UFG::DUIContext::RenderRect(this, &rect, &UFG::qColourBlack, 0);
          UFG::DUIContext::RenderRect(this, &v16, &this->mTheme.mColour[11], 0);
          UFG::DUIContext::RenderText(this, &v15, &UFG::qColourWhite, text, 0);
        }
      }
    }
    UFG::DUIContext::PopLayoutState(this);
    this->mCurrentCompositeLayer = CompositeLayer_Normal;
  }
}

// File Line: 3443
// RVA: 0x1981B0
char __fastcall UFG::EvaluateExpression(UFG::qString *expression, float *value)
{
  UEL::Expression *v4; // rax
  UEL::Expression *v5; // rbx
  float v7; // xmm0_4
  __int64 v8; // [rsp+38h] [rbp-30h] BYREF
  __int16 v9; // [rsp+4Ch] [rbp-1Ch]
  int v10; // [rsp+50h] [rbp-18h]

  v4 = UEL::Expression::Compile(expression->mData);
  v5 = v4;
  if ( v4 && v4->vfptr->Resolve(v4, 0i64) )
  {
    v5->vfptr->Eval(v5, (UEL::Value *)&v8, 0i64, 0i64, 0i64);
    if ( v9 == 1 && UFG::gNullQSymbol.mUID == v10 )
      v7 = (float)(int)v8;
    else
      v7 = *(float *)&v8;
    *value = v7;
    v5->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
    operator delete[](v5);
    UFG::qString::~qString(expression);
    return 1;
  }
  else
  {
    UFG::qString::~qString(expression);
    return 0;
  }
}

// File Line: 3516
// RVA: 0x19A780
__int64 __fastcall UFG::DUIContext::NumericTextBox(
        UFG::DUIContext *this,
        UFG::DUIRect *rect_val,
        unsigned int *val,
        char show_spinners)
{
  bool v8; // dl
  bool v9; // r13
  int v10; // r15d
  __m128i v11; // xmm6
  int mCurrentID; // eax
  int mFocusedID; // ecx
  bool v14; // r14
  bool v15; // bl
  unsigned __int8 v16; // si
  UFG::qString *p_mPrevNumericBoxExpression; // rdx
  UFG::qString *v18; // rax
  __int64 v19; // r8
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // r8
  int mX; // edx
  int mPrev; // ecx
  int mY; // r9d
  int mPrev_high; // ecx
  char v25; // al
  bool mMouseLBWentUp; // r10
  char v27; // r15
  int v28; // ecx
  int v29; // r9d
  int v30; // ecx
  char v31; // al
  bool v32; // bl
  UFG::qColour *v33; // r14
  int v34; // eax
  float v35; // xmm6_4
  __int64 v36; // r8
  UFG::qColour *v37; // r8
  int v38; // eax
  float v39; // xmm0_4
  int v40; // eax
  __int64 v41; // r8
  char v43; // [rsp+71h] [rbp-8Fh]
  UFG::DUIRect rect; // [rsp+80h] [rbp-80h] BYREF
  UFG::DUIRect v45; // [rsp+90h] [rbp-70h] BYREF
  UFG::DUIRect rect_space; // [rsp+A0h] [rbp-60h] BYREF
  long double value_x; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qString str_val; // [rsp+B8h] [rbp-48h] BYREF
  UFG::DUIRect rect_track; // [rsp+E0h] [rbp-20h] BYREF
  UFG::qString dest; // [rsp+F0h] [rbp-10h] BYREF
  __int64 v51; // [rsp+130h] [rbp+30h]
  UFG::qString text; // [rsp+138h] [rbp+38h] BYREF
  bool v53; // [rsp+1C0h] [rbp+C0h]
  long double value_y; // [rsp+1C8h] [rbp+C8h] BYREF
  char v55; // [rsp+1D8h] [rbp+D8h]

  v55 = show_spinners;
  v51 = -2i64;
  v8 = UFG::DUIContext::TakeFocus(this, rect_val, rect_val, 1);
  v53 = v8;
  rect_space = *rect_val;
  v9 = 0;
  *(_QWORD *)&rect.mX = 0i64;
  v10 = 0;
  LODWORD(value_x) = 0;
  rect.mW = 0;
  rect.mH = 0;
  *(_QWORD *)&v45.mX = 0i64;
  *(_QWORD *)&v45.mW = 0i64;
  if ( show_spinners )
  {
    LODWORD(value_x) = this->mTheme.mNumericButtonWidth;
    rect_space.mW -= LODWORD(value_x);
    rect.mX = rect_space.mW + _mm_cvtsi128_si32((__m128i)rect_space) + 1;
    rect.mW = LODWORD(value_x);
    rect.mH = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)rect_space, 12)) / 2;
    v10 = rect_space.mY + 1;
    rect.mY = rect_space.mY + 1;
    v11 = (__m128i)rect;
    v45 = rect;
    v45.mY = rect.mH + rect_space.mY;
  }
  else
  {
    v11 = (__m128i)rect;
  }
  mCurrentID = this->mCurrentID;
  mFocusedID = this->mFocusedID;
  v14 = mFocusedID == mCurrentID && this->mBeginFrameFocusID != mCurrentID;
  v15 = this->mPrevFocusID == mCurrentID && mFocusedID != mCurrentID;
  if ( v8 && !UFG::DUIContext::IsMouseOver(this, rect_val) && this->mInputState.mMouseLBWentDown )
  {
    this->mFocusedID = -1;
    this->mFocusOffset = (UFG::DUIPoint)-1i64;
    v15 = 1;
    v53 = 0;
  }
  v43 = 0;
  LOBYTE(value_y) = 0;
  UFG::qString::qString(&str_val);
  if ( !v53 || v14 )
  {
    if ( v15 )
    {
      LOBYTE(value_y) = 1;
    }
    else
    {
      UFG::qSPrintf((char *)&dest, "%d", *val);
      UFG::qString::Set(&str_val, (const char *)&dest);
    }
  }
  else
  {
    UFG::qString::Set(&str_val, this->mNumericBoxExpression.mData, this->mNumericBoxExpression.mLength, 0i64, 0);
  }
  v16 = UFG::DUIContext::InternalTextControl(this, &rect_space, &str_val, v53);
  if ( v53 )
  {
    UFG::qString::Set(&this->mNumericBoxExpression, str_val.mData, str_val.mLength, 0i64, 0);
    if ( !v14 )
      UFG::qString::Set(
        &this->mPrevNumericBoxExpression,
        this->mNumericBoxExpression.mData,
        this->mNumericBoxExpression.mLength,
        0i64,
        0);
  }
  if ( LOBYTE(value_y) )
  {
    p_mPrevNumericBoxExpression = &this->mPrevNumericBoxExpression;
    if ( !v15 )
      p_mPrevNumericBoxExpression = &this->mNumericBoxExpression;
    UFG::qString::qString(&text, p_mPrevNumericBoxExpression);
    LODWORD(value_y) = 0;
    *(_QWORD *)&rect_track.mX = &dest;
    UFG::qString::qString(&dest, &text);
    if ( UFG::EvaluateExpression(v18, (float *)&value_y) )
    {
      v19 = (unsigned int)(int)*(float *)&value_y;
      *val = v19;
      UFG::qSPrintf((char *)&dest, "%d", v19);
      UFG::qString::Set(&str_val, (const char *)&dest);
      v16 = 1;
    }
    else
    {
      UFG::DUIContext::Tooltip(this, "Unable to evaluate expression.", &rect_space);
    }
    this->mCaretPos = 0;
    this->mHighlightStart = str_val.mLength;
    UFG::qString::~qString(&text);
  }
  if ( v55 )
  {
    mNext = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
    mX = this->mInputState.mMousePos.mX;
    mPrev = (int)mNext[1].mPrev;
    if ( mX < mPrev
      || mX > LODWORD(mNext[1].mNext) + mPrev
      || (mY = this->mInputState.mMousePos.mY, mPrev_high = HIDWORD(mNext[1].mPrev), mY < mPrev_high)
      || mY > HIDWORD(mNext[1].mNext) + mPrev_high - 1
      || mX < rect.mX
      || mX > LODWORD(value_x) + rect.mX
      || mY < v10
      || mY > v10 + rect.mH - 1
      || (v25 = 1, this->mInputState.mMouseEventHandled) )
    {
      v25 = 0;
    }
    mMouseLBWentUp = this->mInputState.mMouseLBWentUp;
    v27 = v25 & mMouseLBWentUp;
    v28 = (int)mNext[1].mPrev;
    if ( mX < v28
      || mX > LODWORD(mNext[1].mNext) + v28
      || (v29 = this->mInputState.mMousePos.mY, v30 = HIDWORD(mNext[1].mPrev), v29 < v30)
      || v29 > HIDWORD(mNext[1].mNext) + v30 - 1
      || mX < v45.mX
      || mX > v45.mW + v45.mX
      || v29 < v45.mY
      || v29 > v45.mH + v45.mY - 1
      || (v31 = 1, this->mInputState.mMouseEventHandled) )
    {
      v31 = 0;
    }
    v55 = v31 & mMouseLBWentUp;
    rect_track = (UFG::DUIRect)v11;
    rect_track.mH = 2 * HIDWORD(_mm_srli_si128(v11, 8).m128i_u64[0]);
    *(_QWORD *)&rect_space.mX = 0i64;
    *(_QWORD *)&rect_space.mW = 0i64;
    value_y = 0.0;
    value_x = 0.0;
    v32 = UFG::DUIContext::Draggable2D(
            this,
            &value_x,
            &value_y,
            &rect_space,
            &rect_track,
            0.0,
            0.0,
            0.0,
            1.0,
            1.0,
            1.0 / (double)rect_track.mH * (double)rect_track.mW,
            rect_track.mW,
            rect_track.mW,
            0);
    *val = UFG::qToInt32(str_val.mData, 0);
    v33 = &UFG::qColourWhite;
    if ( v32 )
    {
      v34 = this->mInputState.mMousePosDelta.mY;
      if ( v34 )
      {
        v35 = (float)-v34 * this->mTheme.mDeltaPerPixel;
        v36 = (unsigned int)(int)(float)((float)(int)UFG::qToInt32(str_val.mData, 0) + v35);
        *val = v36;
        v16 = 1;
        if ( v35 <= 0.0 )
          v9 = v35 < 0.0;
        else
          v43 = 1;
        UFG::qSPrintf((char *)&dest, "%d", v36);
        UFG::qString::Set(&str_val, (const char *)&dest);
        if ( v43 )
        {
          v37 = &this->mTheme.mColour[12];
LABEL_65:
          UFG::DUIContext::RenderRect(this, &rect, v37, 0x7EF7433u);
          if ( v9 )
            v33 = &this->mTheme.mColour[12];
          UFG::DUIContext::RenderRect(this, &v45, v33, 0xEDF7E02F);
          goto LABEL_68;
        }
LABEL_64:
        v37 = &UFG::qColourWhite;
        goto LABEL_65;
      }
    }
    if ( v27 )
    {
      v38 = UFG::qToInt32(str_val.mData, 0);
      *val = v38;
      v39 = (float)v38 + this->mTheme.mDeltaPerPixel;
    }
    else
    {
      if ( !v55 )
        goto LABEL_64;
      v40 = UFG::qToInt32(str_val.mData, 0);
      *val = v40;
      v39 = (float)v40 - this->mTheme.mDeltaPerPixel;
    }
    v41 = (unsigned int)(int)v39;
    v16 = 1;
    *val = v41;
    UFG::qSPrintf((char *)&dest, "%d", v41);
    UFG::qString::Set(&str_val, (const char *)&dest);
    this->mInputState.mMouseWheelDelta = 0;
    *(_QWORD *)&this->mInputState.mMouseLBWentDown = 0i64;
    *(_WORD *)&this->mInputState.mLMBDoubleClick = 0;
    this->mInputState.mMouseMBWentUp = 0;
    this->mInputState.mMMBDoubleClick = 0;
    this->mInputState.mMouseEventHandled = 1;
    goto LABEL_64;
  }
LABEL_68:
  if ( v16 && v53 )
    UFG::qString::Set(&this->mNumericBoxExpression, str_val.mData);
  UFG::qString::~qString(&str_val);
  return v16;
}   this->mInputState.mMMBDoubleClick = 0;
    this->mInputState.mMouseEventHandled = 1;
    goto LABEL_64;
  }
LABEL_68:
  if ( v16

// File Line: 3682
// RVA: 0x19B690
bool __fastcall UFG::DUIContext::NumericTextBox(
        UFG::DUIContext *this,
        const char *label,
        float *val,
        bool show_spinners,
        float label_proportion)
{
  float v10; // xmm6_4
  unsigned int flags; // edi
  int v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm0_4
  UFG::DUIRect result; // [rsp+30h] [rbp-48h] BYREF
  UFG::DUIRect scissor_rect; // [rsp+40h] [rbp-38h] BYREF

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
  scissor_rect = result;
  if ( v10 <= 0.0 )
  {
    v10 = 0.0;
  }
  else
  {
    v13 = *(float *)&FLOAT_1_0;
    if ( v10 >= 1.0 )
      goto LABEL_11;
  }
  v13 = v10;
LABEL_11:
  v14 = (float)v12 * v13;
  result.mX += (int)v14;
  scissor_rect.mW = (int)v14;
  result.mW = v12 - (int)v14;
  UFG::DUIContext::PushScissor(this, &scissor_rect);
  UFG::DUIContext::RenderText(this, &scissor_rect, this->mTheme.mColour, label, flags);
  UFG::DUIContext::PopScissor(this);
  return UFG::DUIContext::NumericTextBox(this, &result, val, show_spinners);
}

// File Line: 3713
// RVA: 0x19AE30
__int64 __fastcall UFG::DUIContext::NumericTextBox(
        UFG::DUIContext *this,
        UFG::DUIRect *rect_val,
        float *val,
        bool show_spinners)
{
  char v8; // dl
  int v9; // r13d
  int v10; // r15d
  UFG::DUIRect v11; // xmm8
  int mCurrentID; // eax
  int mFocusedID; // ecx
  bool v14; // r14
  bool v15; // di
  char v16; // si
  unsigned __int8 v17; // r12
  UFG::qString *p_mPrevNumericBoxExpression; // rdx
  UFG::qString *v19; // rax
  float *v20; // rdi
  float v21; // xmm6_4
  float v22; // xmm0_4
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // r8
  int mX; // edx
  int mPrev; // ecx
  int v26; // r9d
  int v27; // ecx
  int v28; // edi
  int v29; // ecx
  int mY; // r9d
  int mPrev_high; // ecx
  int v32; // esi
  int v33; // r14d
  int v34; // r10d
  int v35; // ecx
  int v36; // r9d
  int v37; // ecx
  bool v38; // r15
  int v39; // ecx
  int v40; // r9d
  int v41; // ecx
  bool v42; // r14
  bool v43; // r13
  bool v44; // di
  unsigned __int64 Ticks; // rax
  float mDeltaPerPixel; // xmm6_4
  float v47; // xmm0_4
  float *v48; // rcx
  UFG::qColour *v49; // rsi
  int v50; // eax
  float v51; // xmm2_4
  BOOL v52; // eax
  UFG::qColour *v53; // r8
  float v54; // xmm0_4
  long double value_max_y[2]; // [rsp+40h] [rbp-80h] BYREF
  long double grip_ph[2]; // [rsp+50h] [rbp-70h] BYREF
  long double value_y; // [rsp+60h] [rbp-60h] BYREF
  bool quantize_value[4]; // [rsp+68h] [rbp-58h]
  UFG::DUIRect rect_space; // [rsp+70h] [rbp-50h] BYREF
  long double value_x; // [rsp+80h] [rbp-40h] BYREF
  UFG::qString str_val; // [rsp+88h] [rbp-38h] BYREF
  UFG::DUIRect rect_track; // [rsp+B0h] [rbp-10h] BYREF
  UFG::qString dest; // [rsp+C0h] [rbp+0h] BYREF
  __int64 v65; // [rsp+100h] [rbp+40h]
  UFG::qString text; // [rsp+108h] [rbp+48h] BYREF
  char v67; // [rsp+1B0h] [rbp+F0h]
  bool v68[4]; // [rsp+1B8h] [rbp+F8h] BYREF
  float *v69; // [rsp+1C0h] [rbp+100h]
  char v70; // [rsp+1C8h] [rbp+108h]

  v65 = -2i64;
  v8 = UFG::DUIContext::TakeFocus(this, rect_val, rect_val, 1);
  v67 = v8;
  rect_space = *rect_val;
  v9 = 0;
  grip_ph[0] = 0.0;
  v10 = 0;
  LODWORD(value_y) = 0;
  grip_ph[1] = 0.0;
  value_max_y[0] = 0.0;
  value_max_y[1] = 0.0;
  if ( show_spinners )
  {
    LODWORD(value_y) = this->mTheme.mNumericButtonWidth;
    rect_space.mW -= LODWORD(value_y);
    v9 = rect_space.mW + _mm_cvtsi128_si32((__m128i)rect_space) + 1;
    LODWORD(grip_ph[0]) = v9;
    LODWORD(grip_ph[1]) = LODWORD(value_y);
    HIDWORD(grip_ph[1]) = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)rect_space, 12)) / 2;
    v10 = rect_space.mY + 1;
    HIDWORD(grip_ph[0]) = rect_space.mY + 1;
    v11 = *(UFG::DUIRect *)grip_ph;
    *(_OWORD *)value_max_y = *(_OWORD *)grip_ph;
    HIDWORD(value_max_y[0]) = HIDWORD(grip_ph[1]) + rect_space.mY;
    v8 = v67;
  }
  else
  {
    v11 = *(UFG::DUIRect *)grip_ph;
  }
  mCurrentID = this->mCurrentID;
  mFocusedID = this->mFocusedID;
  v14 = mFocusedID == mCurrentID && this->mBeginFrameFocusID != mCurrentID;
  v15 = this->mPrevFocusID == mCurrentID && mFocusedID != mCurrentID;
  if ( v8 && !UFG::DUIContext::IsMouseOver(this, rect_val) && this->mInputState.mMouseLBWentDown )
  {
    this->mFocusedID = -1;
    this->mFocusOffset = (UFG::DUIPoint)-1i64;
    v15 = 1;
    v16 = 0;
    v67 = 0;
  }
  else
  {
    v16 = v67;
  }
  LOBYTE(rect_space.mX) = 0;
  quantize_value[0] = 0;
  v68[0] = 0;
  UFG::qString::qString(&str_val);
  if ( !v16 || v14 )
  {
    if ( v15 )
    {
      v68[0] = 1;
    }
    else
    {
      UFG::qSPrintf((char *)&dest, "%f", *val);
      UFG::qString::Set(&str_val, (const char *)&dest);
    }
  }
  else
  {
    UFG::qString::Set(&str_val, this->mNumericBoxExpression.mData, this->mNumericBoxExpression.mLength, 0i64, 0);
  }
  v17 = UFG::DUIContext::InternalTextControl(this, &rect_space, &str_val, v16);
  if ( v16 )
  {
    UFG::qString::Set(&this->mNumericBoxExpression, str_val.mData, str_val.mLength, 0i64, 0);
    if ( !v14 )
      UFG::qString::Set(
        &this->mPrevNumericBoxExpression,
        this->mNumericBoxExpression.mData,
        this->mNumericBoxExpression.mLength,
        0i64,
        0);
  }
  if ( v68[0] )
  {
    p_mPrevNumericBoxExpression = &this->mPrevNumericBoxExpression;
    if ( !v15 )
      p_mPrevNumericBoxExpression = &this->mNumericBoxExpression;
    UFG::qString::qString(&text, p_mPrevNumericBoxExpression);
    *(_DWORD *)v68 = 0;
    *(_QWORD *)&value_x = &dest;
    UFG::qString::qString(&dest, &text);
    if ( UFG::EvaluateExpression(v19, (float *)v68) )
    {
      v20 = v69;
      v21 = *v69;
      v22 = *(float *)v68;
      *v69 = *(float *)v68;
      UFG::qSPrintf((char *)&dest, "%0.5f", v22);
      UFG::qString::Set(&str_val, (const char *)&dest);
      v17 = v21 != *v20;
    }
    else
    {
      UFG::DUIContext::Tooltip(this, "Unable to evaluate expression.", &rect_space);
    }
    this->mCaretPos = 0;
    this->mHighlightStart = str_val.mLength;
    UFG::qString::~qString(&text);
  }
  if ( v70 )
  {
    mNext = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
    mX = this->mInputState.mMousePos.mX;
    mPrev = (int)mNext[1].mPrev;
    if ( mX < mPrev
      || mX > LODWORD(mNext[1].mNext) + mPrev
      || (v26 = this->mInputState.mMousePos.mY, v27 = HIDWORD(mNext[1].mPrev), v26 < v27)
      || v26 > HIDWORD(mNext[1].mNext) + v27 - 1 )
    {
      v28 = HIDWORD(grip_ph[1]);
    }
    else
    {
      v28 = HIDWORD(grip_ph[1]);
      if ( mX >= v9
        && mX <= LODWORD(value_y) + v9
        && v26 >= v10
        && v26 <= v10 + HIDWORD(grip_ph[1]) - 1
        && !this->mInputState.mMouseEventHandled
        && this->mInputState.mMouseLBWentUp )
      {
        v70 = 1;
LABEL_46:
        v29 = (int)mNext[1].mPrev;
        if ( mX < v29 || mX > LODWORD(mNext[1].mNext) + v29 )
        {
          v33 = LODWORD(value_max_y[1]);
          v32 = LODWORD(value_max_y[0]);
        }
        else
        {
          mY = this->mInputState.mMousePos.mY;
          mPrev_high = HIDWORD(mNext[1].mPrev);
          v32 = LODWORD(value_max_y[0]);
          v33 = LODWORD(value_max_y[1]);
          if ( mY >= mPrev_high && mY <= HIDWORD(mNext[1].mNext) + mPrev_high - 1 )
          {
            v34 = HIDWORD(value_max_y[0]);
            if ( mX >= SLODWORD(value_max_y[0])
              && mX <= LODWORD(value_max_y[1]) + LODWORD(value_max_y[0])
              && mY >= SHIDWORD(value_max_y[0])
              && mY <= HIDWORD(value_max_y[0]) + HIDWORD(value_max_y[1]) - 1
              && !this->mInputState.mMouseEventHandled
              && this->mInputState.mMouseLBWentUp )
            {
              v68[0] = 1;
LABEL_60:
              v35 = (int)mNext[1].mPrev;
              v38 = 0;
              if ( mX >= v35 && mX <= LODWORD(mNext[1].mNext) + v35 )
              {
                v36 = this->mInputState.mMousePos.mY;
                v37 = HIDWORD(mNext[1].mPrev);
                if ( v36 >= v37
                  && v36 <= HIDWORD(mNext[1].mNext) + v37 - 1
                  && mX >= v9
                  && mX <= LODWORD(value_y) + v9
                  && v36 >= v10
                  && v36 <= v10 + v28 - 1
                  && !this->mInputState.mMouseEventHandled
                  && this->mInputState.mMouseLBIsDown )
                {
                  v38 = 1;
                }
              }
              v39 = (int)mNext[1].mPrev;
              v42 = 0;
              if ( mX >= v39 && mX <= LODWORD(mNext[1].mNext) + v39 )
              {
                v40 = this->mInputState.mMousePos.mY;
                v41 = HIDWORD(mNext[1].mPrev);
                if ( v40 >= v41
                  && v40 <= HIDWORD(mNext[1].mNext) + v41 - 1
                  && mX >= v32
                  && mX <= v33 + v32
                  && v40 >= v34
                  && v40 <= v34 + HIDWORD(value_max_y[1]) - 1
                  && !this->mInputState.mMouseEventHandled
                  && this->mInputState.mMouseLBIsDown )
                {
                  v42 = 1;
                }
              }
              rect_track = v11;
              rect_track.mH = 2 * HIDWORD(_mm_srli_si128((__m128i)v11, 8).m128i_u64[0]);
              *(_QWORD *)&rect_space.mX = 0i64;
              *(_QWORD *)&rect_space.mW = 0i64;
              value_x = 0.0;
              v43 = UFG::DUIContext::Draggable2D(
                      this,
                      &value_x,
                      &value_y,
                      &rect_space,
                      &rect_track,
                      0.0,
                      0.0,
                      0.0,
                      1.0,
                      1.0,
                      1.0 / (double)rect_track.mH * (double)rect_track.mW,
                      rect_track.mW,
                      rect_track.mW,
                      0);
              if ( (v42 || v38) && !this->mSpinner_start_press )
                this->mSpinner_start_press = UFG::qGetTicks();
              v44 = 0;
              if ( (v42 || v38) && this->mSpinner_start_press )
              {
                Ticks = UFG::qGetTicks();
                v44 = UFG::qGetTickTime(this->mSpinner_start_press, Ticks) > 0.2;
              }
              mDeltaPerPixel = this->mTheme.mDeltaPerPixel;
              v47 = UFG::qToFloat(str_val.mData, 0.0);
              v48 = v69;
              *v69 = v47;
              if ( v47 >= 10.0 || v47 <= -10.0 )
              {
                if ( v47 < 100.0 && v47 > -100.0 )
                  mDeltaPerPixel = mDeltaPerPixel * 0.1;
              }
              else
              {
                mDeltaPerPixel = mDeltaPerPixel * 0.0099999998;
              }
              v49 = &UFG::qColourWhite;
              if ( v70 || v44 && v38 )
              {
                v54 = v47 + mDeltaPerPixel;
              }
              else
              {
                if ( !v68[0] && (!v44 || !v42) )
                {
                  if ( v43 )
                  {
                    v50 = this->mInputState.mMousePosDelta.mY;
                    if ( v50 )
                    {
                      v51 = (float)-v50;
                      *v48 = (float)(v51 * mDeltaPerPixel) + v47;
                      v17 = 1;
                      if ( v51 <= 0.0 )
                      {
                        v52 = quantize_value[0];
                        if ( v51 < 0.0 )
                          v52 = 1;
                        *(_DWORD *)quantize_value = v52;
                      }
                      else
                      {
                        LOBYTE(rect_space.mX) = 1;
                      }
                      UFG::qSPrintf((char *)&dest, "%f", v51);
                      UFG::qString::Set(&str_val, (const char *)&dest);
                      this->mSpinner_start_press = 0i64;
                      if ( LOBYTE(rect_space.mX) )
                      {
                        v53 = &this->mTheme.mColour[12];
LABEL_118:
                        UFG::DUIContext::RenderRect(this, (UFG::DUIRect *)grip_ph, v53, 0x7EF7433u);
                        if ( quantize_value[0] )
                          v49 = &this->mTheme.mColour[12];
                        UFG::DUIContext::RenderRect(this, (UFG::DUIRect *)value_max_y, v49, 0xEDF7E02F);
                        goto LABEL_121;
                      }
                    }
                  }
LABEL_117:
                  v53 = &UFG::qColourWhite;
                  goto LABEL_118;
                }
                v54 = v47 - mDeltaPerPixel;
              }
              *v48 = v54;
              v17 = 1;
              UFG::qSPrintf((char *)&dest, "%f", v54);
              UFG::qString::Set(&str_val, (const char *)&dest);
              this->mInputState.mMouseWheelDelta = 0;
              *(_QWORD *)&this->mInputState.mMouseLBWentDown = 0i64;
              *(_WORD *)&this->mInputState.mLMBDoubleClick = 0;
              this->mInputState.mMouseMBWentUp = 0;
              this->mInputState.mMMBDoubleClick = 0;
              this->mInputState.mMouseEventHandled = 1;
              if ( !v44 )
                this->mSpinner_start_press = 0i64;
              goto LABEL_117;
            }
LABEL_59:
            v68[0] = 0;
            goto LABEL_60;
          }
        }
        v34 = HIDWORD(value_max_y[0]);
        goto LABEL_59;
      }
    }
    v70 = 0;
    goto LABEL_46;
  }
LABEL_121:
  if ( v17 && v67 )
    UFG::qString::Set(&this->mNumericBoxExpression, str_val.mData);
  UFG::qString::~qString(&str_val);
  return v17;
}

// File Line: 3906
// RVA: 0x19F240
__int64 __fastcall UFG::DUIContext::TextBox(
        UFG::DUIContext *this,
        UFG::qString *current_value,
        const char *placeholderText,
        bool is_valid,
        const char **suggestions,
        int count)
{
  UFG::DUIRect result; // [rsp+40h] [rbp-18h] BYREF

  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  return UFG::DUIContext::TextBox(this, &result, current_value, placeholderText, is_valid, suggestions, count);
}

// File Line: 3914
// RVA: 0x19EC80
__int64 __fastcall UFG::DUIContext::TextBox(
        UFG::DUIContext *this,
        UFG::DUIRect *rect,
        UFG::qString *current_value,
        const char *placeholderText,
        bool is_valid,
        const char **suggestions,
        int count)
{
  UFG::DUIRect *v8; // r15
  bool v10; // r14
  unsigned __int8 v11; // r12
  int v13; // edi
  const char **v14; // rax
  int v15; // eax
  int mRowHeight; // eax
  __int64 v17; // r14
  __int64 v18; // rax
  int mY; // edi
  char v20; // r12
  __int64 v21; // r15
  int mX; // ecx
  int v23; // edx
  int v24; // r9d
  int v25; // r10d
  int v26; // r11d
  __int64 mCurrentCompositeLayer; // rax
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // r8
  int mPrev; // ecx
  int mPrev_high; // ecx
  int v31; // edx
  bool v32; // zf
  int v33; // r9d
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v34; // rdx
  int v35; // ecx
  int v36; // ecx
  int v37; // r8d
  int v38; // r11d
  int mW; // esi
  int v40; // r10d
  int v41; // edi
  int v42; // edx
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v43; // r8
  int v44; // ecx
  int v45; // r9d
  int v46; // ecx
  int v47; // ecx
  int v48; // ecx
  int v49; // r9d
  int v50; // ecx
  unsigned __int8 v52; // [rsp+41h] [rbp-40h]
  int v53; // [rsp+50h] [rbp-31h]
  UFG::DUIRect v54; // [rsp+60h] [rbp-21h]
  UFG::DUIRect recta; // [rsp+70h] [rbp-11h] BYREF
  UFG::DUIRect v56; // [rsp+80h] [rbp-1h]
  UFG::DUIRect v57; // [rsp+90h] [rbp+Fh] BYREF
  int suggestionsa; // [rsp+F8h] [rbp+77h]

  v8 = rect;
  v10 = UFG::DUIContext::TakeFocus(this, rect, rect, 1);
  v11 = UFG::DUIContext::InternalTextControl(this, v8, current_value, v10);
  v52 = v11;
  if ( suggestions )
    ++this->mCurrentPopupID;
  if ( v10 )
  {
    if ( !UFG::DUIContext::IsMouseOver(this, v8) && this->mInputState.mMouseLBWentDown )
    {
      if ( !suggestions )
        return v11;
      if ( this->mCurrentPopupID != this->mActivePopupID )
      {
        this->mFocusedID = -1;
        this->mFocusOffset = (UFG::DUIPoint)-1i64;
        v10 = 0;
      }
    }
  }
  else
  {
    if ( !suggestions )
      return v11;
    if ( this->mCurrentPopupID == this->mActivePopupID )
      this->mActivePopupID = -1;
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
      v15 = v8->mH + recta.mY;
      this->mCurrentCompositeLayer = CompositeLayer_Overlay;
      v53 = v15;
      recta.mY = v15;
      recta.mW += 4;
      suggestionsa = v13 * recta.mH + 2;
      recta.mH = suggestionsa;
      this->mActivePopupID = this->mCurrentPopupID;
      UFG::DUIContext::PushLayoutState(this, &this->mRect, &this->mRect, LayoutFlag_FillLastCell);
      UFG::DUIContext::RenderRect(this, &recta, &this->mTheme.mColour[5], 0);
      mRowHeight = this->mTheme.mRowHeight;
      v17 = 0i64;
      v56 = recta;
      v56.mH = mRowHeight;
      v18 = v13;
      if ( v13 > 0 )
      {
        mY = v56.mY;
        v20 = 0;
        v21 = v18;
        do
        {
          mX = this->mTheme.mButton_Text.mX;
          v23 = this->mTheme.mButton_Text.mY;
          mY += this->mTheme.mRowHeight;
          v24 = this->mInputState.mMousePos.mX;
          v54.mY = v23 + v56.mY;
          v25 = mX + v56.mX;
          v54.mX = mX + v56.mX;
          v26 = v56.mW - 2 * mX;
          v56.mY = mY;
          mCurrentCompositeLayer = this->mCurrentCompositeLayer;
          v54.mW = v26;
          v54.mH = v56.mH - 2 * v23;
          v57 = v54;
          mNext = this->mScissorStacks[mCurrentCompositeLayer].mNode.mNext;
          mPrev = (int)mNext[1].mPrev;
          if ( v24 >= mPrev && v24 <= LODWORD(mNext[1].mNext) + mPrev )
          {
            mPrev_high = HIDWORD(mNext[1].mPrev);
            v31 = this->mInputState.mMousePos.mY;
            if ( v31 >= mPrev_high
              && v31 <= HIDWORD(mNext[1].mNext) + mPrev_high - 1
              && v24 >= v25
              && v24 <= v26 + v25
              && v31 >= v54.mY
              && v31 <= v54.mY + v54.mH - 1
              && !this->mInputState.mMouseEventHandled )
            {
              if ( this->mInputState.mMouseLBWentDown )
              {
                UFG::qString::Set(current_value, suggestions[v17]);
                this->mInputState.mMouseWheelDelta = 0;
                *(_QWORD *)&this->mInputState.mMouseLBWentDown = 0i64;
                *(_WORD *)&this->mInputState.mLMBDoubleClick = 0;
                this->mInputState.mMouseMBWentUp = 0;
                this->mInputState.mMMBDoubleClick = 0;
                this->mActivePopupID = -1;
                this->mFocusedID = -1;
                this->mFocusOffset = (UFG::DUIPoint)-1i64;
                v20 = 1;
              }
              UFG::DUIContext::RenderRoundRect(this, &v57, &this->mTheme.mColour[12], 0);
            }
          }
          UFG::DUIContext::RenderText(this, &v57, &UFG::qColourWhite, suggestions[v17++], 0);
        }
        while ( v17 < v21 );
        v8 = rect;
        v32 = v20 == 0;
        v11 = v52;
        if ( !v32 )
          goto LABEL_47;
      }
      v33 = this->mInputState.mMousePos.mX;
      v34 = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
      v35 = (int)v34[1].mPrev;
      if ( v33 >= v35 && v33 <= LODWORD(v34[1].mNext) + v35 )
      {
        v36 = HIDWORD(v34[1].mPrev);
        v37 = this->mInputState.mMousePos.mY;
        v38 = recta.mX;
        mW = recta.mW;
        if ( v37 >= v36 && v37 <= HIDWORD(v34[1].mNext) + v36 - 1 )
        {
          v40 = v53;
          v41 = suggestionsa;
          if ( v33 >= recta.mX
            && v33 <= recta.mW + recta.mX
            && v37 >= v53
            && v37 <= suggestionsa + v53 - 1
            && !this->mInputState.mMouseEventHandled )
          {
            if ( !this->mInputState.mMouseLBWentDown )
            {
LABEL_69:
              UFG::DUIContext::PopLayoutState(this);
              this->mCurrentCompositeLayer = CompositeLayer_Normal;
              return v11;
            }
            this->mInputState.mMouseWheelDelta = 0;
            *(_QWORD *)&this->mInputState.mMouseLBWentDown = 0i64;
            *(_WORD *)&this->mInputState.mLMBDoubleClick = 0;
            this->mInputState.mMouseMBWentUp = 0;
            this->mInputState.mMMBDoubleClick = 0;
          }
LABEL_49:
          if ( this->mInputState.mMouseLBWentDown )
          {
            v42 = this->mInputState.mMousePos.mX;
            v43 = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
            v44 = (int)v43[1].mPrev;
            if ( v42 < v44
              || v42 > LODWORD(v43[1].mNext) + v44
              || (v45 = this->mInputState.mMousePos.mY, v46 = HIDWORD(v43[1].mPrev), v45 < v46)
              || v45 > HIDWORD(v43[1].mNext) + v46 - 1
              || v42 < v38
              || v42 > mW + v38
              || v45 < v40
              || v45 > v41 + v40 - 1
              || this->mInputState.mMouseEventHandled )
            {
              v47 = (int)v43[1].mPrev;
              if ( v42 < v47
                || v42 > LODWORD(v43[1].mNext) + v47
                || (v48 = HIDWORD(v43[1].mPrev), v49 = this->mInputState.mMousePos.mY, v49 < v48)
                || v49 > HIDWORD(v43[1].mNext) + v48 - 1
                || v42 < v8->mX
                || v42 > v8->mW + v8->mX
                || (v50 = v8->mY, v49 < v50)
                || v49 > v8->mH + v50 - 1
                || this->mInputState.mMouseEventHandled )
              {
                this->mActivePopupID = -1;
                this->mInputState.mMouseWheelDelta = 0;
                *(_QWORD *)&this->mInputState.mMouseLBWentDown = 0i64;
                *(_WORD *)&this->mInputState.mLMBDoubleClick = 0;
                this->mInputState.mMouseMBWentUp = 0;
                this->mInputState.mMMBDoubleClick = 0;
                this->mFocusedID = -1;
                this->mFocusOffset = (UFG::DUIPoint)-1i64;
              }
            }
          }
          goto LABEL_69;
        }
      }
      else
      {
LABEL_47:
        mW = recta.mW;
        v38 = recta.mX;
      }
      v40 = v53;
      v41 = suggestionsa;
      goto LABEL_49;
    }
  }
  return v11;
}

// File Line: 4021
// RVA: 0x199500
__int64 __fastcall UFG::DUIContext::InternalTextControl(
        UFG::DUIContext *this,
        UFG::DUIRect *rect_space,
        UFG::qString *str_val,
        bool in_focus)
{
  int mY; // r11d
  int mX; // r10d
  signed int v7; // ebx
  int v8; // r15d
  int v9; // edx
  int v10; // ecx
  UFG::qNode<UFG::qString,UFG::qString> v11; // xmm1
  int v12; // r10d
  int mTextBoxOffset; // eax
  unsigned __int8 v14; // r12
  unsigned __int64 v15; // rdi
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // r9
  int v17; // r8d
  int mPrev; // ecx
  int v19; // edx
  int mPrev_high; // ecx
  char v21; // r13
  char v22; // r12
  __int64 v23; // r11
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v24; // r8
  int v25; // r9d
  int v26; // ecx
  int v27; // edx
  int v28; // ecx
  bool v29; // r13
  bool mMouseLBIsDown; // r9
  int mLength; // edx
  int *p_mCaretPos; // r14
  int mCaretPos; // eax
  int *p_mHighlightStart; // r15
  int mHighlightStart; // eax
  int v36; // ecx
  UFG::DUIContextVtbl *v37; // r9
  int v38; // r10d
  int UpdateUI; // ecx
  int v40; // r8d
  int UpdateUI_high; // ecx
  unsigned __int64 v42; // rdi
  char mKeycodeDown; // al
  int v44; // eax
  char v45; // di
  char v46; // bl
  unsigned __int8 mChar; // r8
  int v48; // r9d
  float x; // xmm2_4
  int v50; // eax
  int v51; // r8d
  int v52; // eax
  int v53; // edi
  int v54; // eax
  int v55; // ebx
  const char *ClipboardText; // r9
  int v57; // r10d
  unsigned int v58; // eax
  unsigned __int8 v59; // bl
  UFG::qColour *v60; // r8
  float v61; // xmm1_4
  int v62; // ecx
  char *mData; // rbx
  float a; // xmm1_4
  UFG::qColour *p_result; // r8
  UFG::DUIRect *v66; // rdx
  char v68; // [rsp+40h] [rbp-80h]
  char v69; // [rsp+41h] [rbp-7Fh]
  char v70; // [rsp+42h] [rbp-7Eh]
  int v71; // [rsp+44h] [rbp-7Ch]
  UFG::DUIRect v72; // [rsp+50h] [rbp-70h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-60h] BYREF
  UFG::DUIRect v74; // [rsp+90h] [rbp-30h] BYREF
  UFG::DUIRect scissor_rect; // [rsp+A0h] [rbp-20h] BYREF
  __int64 v76; // [rsp+B0h] [rbp-10h]
  UFG::DUIRect rect; // [rsp+C0h] [rbp+0h] BYREF
  unsigned __int8 v78; // [rsp+130h] [rbp+70h]
  char v79; // [rsp+138h] [rbp+78h]
  UFG::qString *text; // [rsp+140h] [rbp+80h]
  unsigned __int8 v81; // [rsp+148h] [rbp+88h]
  char v82; // [rsp+150h] [rbp+90h]
  _BYTE *v83; // [rsp+158h] [rbp+98h]
  char *vars0; // [rsp+160h] [rbp+A0h]

  v76 = -2i64;
  *(UFG::DUIRect *)&result.mMagic = *rect_space;
  mY = this->mTheme.mButton_Inset.mY;
  mX = this->mTheme.mButton_Inset.mX;
  v7 = mX + _mm_cvtsi128_si32(*(__m128i *)&result.mMagic);
  result.mMagic = v7;
  v8 = LODWORD(result.mData) - 2 * mX;
  LODWORD(result.mData) = v8;
  result.mLength += mY;
  HIDWORD(result.mData) -= 2 * mY;
  rect = *(UFG::DUIRect *)&result.mMagic;
  v72.mX = v7 + 1;
  v72.mW = v8 - 2;
  v72.mY = result.mLength + 1;
  v72.mH = HIDWORD(result.mData) - 2;
  v74 = v72;
  v72 = *rect_space;
  v9 = this->mTheme.mButton_Text.mY;
  v10 = this->mTheme.mButton_Text.mX;
  v72.mX = v10 + _mm_cvtsi128_si32((__m128i)v72);
  v72.mW -= 2 * v10;
  v72.mH -= 2 * v9;
  v72.mY += v9 + 1;
  v11 = (UFG::qNode<UFG::qString,UFG::qString>)v72;
  scissor_rect = v72;
  v12 = v72.mX;
  if ( in_focus )
  {
    mTextBoxOffset = this->mTextBoxOffset;
    v12 = v72.mX - mTextBoxOffset;
    v72.mX -= mTextBoxOffset;
    v72.mW += mTextBoxOffset;
    v11 = (UFG::qNode<UFG::qString,UFG::qString>)v72;
  }
  *(_QWORD *)&v72.mX = v11.mPrev;
  v72.mH = HIDWORD(_mm_srli_si128((__m128i)v11, 8).m128i_u64[0]) - 2;
  v72.mW = 1;
  result.UFG::qNode<UFG::qString,UFG::qString> = v11;
  v14 = 0;
  v78 = 0;
  v15 = *(_QWORD *)&result.mMagic;
  if ( this->mInputState.mMouseLBIsDown
    || this->mInputState.mMouseRBIsDown
    || this->mInputState.mMouseMBIsDown
    || (mNext = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext,
        v17 = this->mInputState.mMousePos.mX,
        mPrev = (int)mNext[1].mPrev,
        v17 < mPrev)
    || v17 > LODWORD(mNext[1].mNext) + mPrev
    || (v19 = this->mInputState.mMousePos.mY, mPrev_high = HIDWORD(mNext[1].mPrev), v19 < mPrev_high)
    || v19 > HIDWORD(mNext[1].mNext) + mPrev_high - 1
    || v17 < v7
    || v17 > v8 + v7
    || v19 < result.mLength
    || v19 > result.mLength + HIDWORD(result.mData) - 1
    || (v68 = 1, this->mInputState.mMouseEventHandled) )
  {
    v68 = 0;
  }
  v21 = 0;
  v69 = 0;
  if ( v81 )
  {
    v22 = 0;
    v79 = 0;
    v23 = 2 * ((int)this->mCurrentCompositeLayer + 54i64);
    v24 = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
    v25 = this->mInputState.mMousePos.mX;
    v26 = (int)v24[1].mPrev;
    v29 = 0;
    if ( v25 >= v26 && v25 <= LODWORD(v24[1].mNext) + v26 )
    {
      v27 = this->mInputState.mMousePos.mY;
      v28 = HIDWORD(v24[1].mPrev);
      if ( v27 >= v28
        && v27 <= HIDWORD(v24[1].mNext) + v28 - 1
        && v25 >= v7
        && v25 <= v8 + v7
        && v27 >= result.mLength
        && v27 <= result.mLength + HIDWORD(result.mData) - 1
        && !this->mInputState.mMouseEventHandled
        && this->mInputState.mMouseLBWentDown )
      {
        v29 = 1;
      }
    }
    mMouseLBIsDown = this->mInputState.mMouseLBIsDown;
    if ( this->mInputState.mMouseLBWentDown )
    {
      this->mTextBoxCanDragSelect = v29;
    }
    else if ( !mMouseLBIsDown )
    {
      this->mTextBoxCanDragSelect = 0;
    }
    mLength = text->mLength;
    p_mCaretPos = &this->mCaretPos;
    mCaretPos = this->mCaretPos;
    if ( mCaretPos >= 0 )
    {
      if ( mCaretPos > mLength )
        *p_mCaretPos = mLength;
    }
    else
    {
      *p_mCaretPos = 0;
    }
    p_mHighlightStart = &this->mHighlightStart;
    mHighlightStart = this->mHighlightStart;
    if ( mHighlightStart >= 0 )
    {
      if ( mHighlightStart > mLength )
        *p_mHighlightStart = mLength;
    }
    else
    {
      *p_mHighlightStart = 0;
    }
    v71 = *p_mCaretPos;
    v36 = *p_mHighlightStart - *p_mCaretPos;
    if ( mMouseLBIsDown && this->mTextBoxCanDragSelect )
    {
      *p_mCaretPos = (int)(float)((float)((float)(this->mFontDimensions.x * 0.5)
                                        + (float)(this->mInputState.mMousePos.mX - v12))
                                / this->mFontDimensions.x);
      v79 = 1;
      goto LABEL_88;
    }
    if ( this->mInputState.mLMBDoubleClick )
    {
      v37 = (&this->vfptr)[v23];
      v38 = this->mInputState.mMousePos.mX;
      UpdateUI = (int)v37[2].UpdateUI;
      if ( v38 >= UpdateUI && v38 <= LODWORD(v37[3].UpdateUI) + UpdateUI )
      {
        v40 = this->mInputState.mMousePos.mY;
        UpdateUI_high = HIDWORD(v37[2].UpdateUI);
        if ( v40 >= UpdateUI_high
          && v40 <= HIDWORD(v37[3].UpdateUI) + UpdateUI_high - 1
          && v38 >= v7
          && v38 <= v7 + LODWORD(result.mData) )
        {
          v42 = HIDWORD(v15);
          if ( v40 >= (int)v42 && v40 <= (int)v42 + HIDWORD(result.mData) - 1 && !this->mInputState.mMouseEventHandled )
          {
            *p_mHighlightStart = mLength;
            v79 = 1;
LABEL_87:
            *p_mCaretPos = 0;
            goto LABEL_88;
          }
        }
      }
      goto LABEL_88;
    }
    mKeycodeDown = this->mInputState.mKeycodeDown;
    switch ( mKeycodeDown )
    {
      case 37:
        if ( this->mInputState.mKeyIsDownControl )
          v44 = 0;
        else
          v44 = v71 - 1;
        if ( this->mInputState.mKeyIsDownShift )
          goto LABEL_72;
        if ( v36 )
        {
          if ( v36 < 0 )
          {
LABEL_62:
            *p_mCaretPos = *p_mHighlightStart;
LABEL_73:
            v22 = 1;
            goto LABEL_88;
          }
LABEL_70:
          *p_mHighlightStart = *p_mCaretPos;
          goto LABEL_73;
        }
        break;
      case 39:
        if ( this->mInputState.mKeyIsDownControl )
          v44 = mLength;
        else
          v44 = v71 + 1;
        if ( this->mInputState.mKeyIsDownShift )
          goto LABEL_72;
        if ( v36 )
        {
          if ( v36 >= 0 )
            goto LABEL_62;
          goto LABEL_70;
        }
        break;
      case 36:
        *p_mCaretPos = 0;
        if ( !this->mInputState.mKeyIsDownShift )
          *p_mHighlightStart = 0;
        v22 = 1;
        break;
      case 35:
        *p_mCaretPos = mLength;
        if ( !this->mInputState.mKeyIsDownShift )
          *p_mHighlightStart = mLength;
        v22 = 1;
        break;
      case 9:
        this->mNavigationAction = this->mInputState.mKeyIsDownShift + 1;
        *p_mCaretPos = 0;
        *p_mHighlightStart = 0x7FFFFFFF;
        v81 = 0;
        *v83 = 1;
        v22 = 1;
        goto LABEL_88;
      case 13:
      case 94:
        *v83 = 1;
        v22 = 1;
        *p_mHighlightStart = 0x7FFFFFFF;
        goto LABEL_87;
      default:
LABEL_88:
        v45 = 0;
        v46 = 0;
        v70 = 0;
        mChar = this->mInputState.mChar;
        switch ( mChar )
        {
          case 3u:
            v46 = 1;
            v22 = 1;
            break;
          case 0x16u:
            v70 = 1;
            v22 = 1;
            break;
          case 0x18u:
            v45 = 1;
            v22 = 1;
            break;
        }
        if ( !this->mInputState.mKeyIsDownShift && v29 )
        {
          *p_mHighlightStart = *p_mCaretPos;
          v22 = 1;
        }
        if ( *p_mCaretPos >= 0 )
        {
          if ( *p_mCaretPos > mLength )
            *p_mCaretPos = mLength;
        }
        else
        {
          *p_mCaretPos = 0;
        }
        if ( *p_mHighlightStart >= 0 )
        {
          if ( *p_mHighlightStart > mLength )
            *p_mHighlightStart = mLength;
        }
        else
        {
          *p_mHighlightStart = 0;
        }
        v48 = *p_mHighlightStart - *p_mCaretPos;
        if ( ((unsigned __int8)(mChar - 32) <= 0x5Fu || mChar == 8)
          && !this->mInputState.mKeyIsDownAlt
          && !this->mInputState.mKeyIsDownControl
          && (!v82 || ((char)mChar < 65 || (char)mChar > 90) && ((char)mChar < 97 || (char)mChar > 122)) )
        {
          UFG::DUIContext::ApplyKeystrokes(text, &this->mCaretPos, &this->mHighlightStart, mChar);
          v48 = UFG::DUIContext::ClampCaret(this, text->mLength);
          v78 = 1;
          v22 = 1;
        }
        x = this->mFontDimensions.x;
        LODWORD(result.mNext) = (int)(float)((float)(x * COERCE_FLOAT(COERCE_UNSIGNED_INT((float)v48) & _xmm)) + 0.5);
        if ( v48 >= 0 )
        {
          if ( v48 <= 0 )
            goto LABEL_115;
          v50 = (int)(float)((float)*p_mCaretPos * x);
        }
        else
        {
          v50 = (int)(float)((float)((float)*p_mCaretPos * x) - (float)((float)(int)abs32(v48) * x));
        }
        v69 = 1;
        LODWORD(result.mPrev) += v50;
LABEL_115:
        if ( v71 == *p_mCaretPos && UFG::qGetSystemElapsedMSecs() % 0x352 <= 0x1A9 )
        {
          v21 = 0;
        }
        else
        {
          v21 = 1;
          v72.mX += (int)(float)((float)*p_mCaretPos * this->mFontDimensions.x);
        }
        if ( v46 )
        {
          v51 = *p_mCaretPos;
          v52 = abs32(*p_mHighlightStart - *p_mCaretPos);
          if ( *p_mHighlightStart < *p_mCaretPos )
            v51 = *p_mHighlightStart;
          UFG::qString::Substring(text, &result, v51, v52);
          UFG::DUIContext::SetClipboardText(result.mData);
          UFG::qString::~qString(&result);
        }
        else if ( v45 )
        {
          v53 = *p_mCaretPos;
          v54 = abs32(*p_mHighlightStart - *p_mCaretPos);
          if ( *p_mHighlightStart < *p_mCaretPos )
            v53 = *p_mHighlightStart;
          v55 = v53 + v54;
          UFG::qString::Substring(text, &result, v53, v54);
          UFG::DUIContext::SetClipboardText(result.mData);
          UFG::DUIContext::ReplaceSelection(text, v53, v55, &customCaption, &this->mHighlightStart, &this->mCaretPos, 1);
          v78 = 1;
          UFG::qString::~qString(&result);
        }
        else if ( v70 )
        {
          ClipboardText = UFG::DUIContext::GetClipboardText();
          v57 = *p_mCaretPos;
          v58 = abs32(*p_mHighlightStart - *p_mCaretPos);
          if ( *p_mHighlightStart < *p_mCaretPos )
            v57 = *p_mHighlightStart;
          UFG::DUIContext::ReplaceSelection(
            text,
            v57,
            v57 + v58,
            ClipboardText,
            &this->mHighlightStart,
            &this->mCaretPos,
            UFG::DUIContext::sInsertOn);
          v78 = 1;
        }
        if ( v22 )
          *(_WORD *)&this->mInputState.mKeycodeDown = 0;
        v14 = v78;
        if ( v79 )
        {
          this->mInputState.mMouseWheelDelta = 0;
          *(_QWORD *)&this->mInputState.mMouseLBWentDown = 0i64;
          *(_WORD *)&this->mInputState.mLMBDoubleClick = 0;
          this->mInputState.mMouseMBWentUp = 0;
          this->mInputState.mMMBDoubleClick = 0;
        }
        goto LABEL_135;
    }
    *p_mHighlightStart = v44;
LABEL_72:
    *p_mCaretPos = v44;
    goto LABEL_73;
  }
LABEL_135:
  v59 = v81;
  v60 = &this->mTheme.mColour[12];
  if ( !(v81 | (unsigned __int8)v68) )
    v60 = &UFG::qColourBlack;
  UFG::DUIContext::RenderRoundRect(this, &rect, v60, 0);
  UFG::DUIContext::RenderRoundRect(this, &v74, &this->mTheme.mColour[11], 0);
  if ( v69 )
  {
    result.mMagic = 1065353216;
    result.mLength = 1056964608;
    LODWORD(result.mData) = 0;
    *((float *)&result.mData + 1) = FLOAT_0_25;
    UFG::DUIContext::RenderRect(this, (UFG::DUIRect *)&result, (UFG::qColour *)&result.mMagic, 0);
  }
  if ( v59 )
  {
    v61 = this->mFontDimensions.x;
    v62 = this->mCaretPos;
    if ( v62 < (int)(float)((float)this->mTextBoxOffset * (float)(1.0 / v61)) )
      this->mTextBoxOffset = (int)(float)((float)v62 * v61);
    if ( v62 > (int)(float)((float)v72.mW * (float)(1.0 / v61)) )
      this->mTextBoxOffset += (int)(float)((float)v62 * v61) - v72.mW;
  }
  mData = text->mData;
  result.mPrev = *(UFG::qNode<UFG::qString,UFG::qString> **)&this->mTheme.mColour[0].r;
  *(float *)&result.mNext = this->mTheme.mColour[0].b;
  a = this->mTheme.mColour[0].a;
  *((float *)&result.mNext + 1) = a;
  if ( !text->mLength )
  {
    mData = vars0;
    *((float *)&result.mNext + 1) = a * 0.5;
  }
  UFG::DUIContext::PushScissor(this, &scissor_rect);
  UFG::DUIContext::RenderText(this, &v72, (UFG::qColour *)&result, mData, 0);
  UFG::DUIContext::PopScissor(this);
  if ( v21 && !v69 )
  {
    if ( UFG::DUIContext::sInsertOn )
    {
      strcpy((char *)&result, "ff&?ff&?ff&?");
      BYTE5(result.mNext) = 0;
      HIWORD(result.mNext) = 16256;
      p_result = (UFG::qColour *)&result;
      v66 = &v72;
    }
    else
    {
      result.UFG::qNode<UFG::qString,UFG::qString> = (UFG::qNode<UFG::qString,UFG::qString>)v72;
      *(float *)&result.mNext = this->mFontDimensions.x;
      v72.mX = 1059481190;
      v72.mY = 1059481190;
      v72.mW = 1059481190;
      *(float *)&v72.mH = FLOAT_0_80000001;
      p_result = (UFG::qColour *)&v72;
      v66 = (UFG::DUIRect *)&result;
    }
    UFG::DUIContext::RenderRect(this, v66, p_result, 0);
  }
  return v14;
}

// File Line: 4338
// RVA: 0x195230
_BOOL8 __fastcall UFG::DUIContext::Button(UFG::DUIContext *this, const char *name, unsigned int text_alignment)
{
  int v6; // eax
  int mX; // ecx
  int mY; // edx
  int v9; // r8d
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  UFG::DUIRect v13; // xmm0
  bool v14; // r15
  UFG::qColour *v15; // r8
  bool v16; // di
  UFG::qColour *mColour; // r8
  UFG::DUIRect v19; // [rsp+30h] [rbp-30h] BYREF
  UFG::DUIRect result; // [rsp+40h] [rbp-20h] BYREF
  UFG::DUIRect rect; // [rsp+50h] [rbp-10h] BYREF
  UFG::DUIContext::ClickableState click_state; // [rsp+80h] [rbp+20h] BYREF

  v6 = UFG::qStringLength(name);
  UFG::DUIContext::GetLayoutRect(
    this,
    &result,
    (int)(float)((float)v6 * this->mFontDimensions.x) + 2 * this->mTheme.mButton_Text.mX,
    0);
  mX = this->mTheme.mButton_Inset.mX;
  mY = this->mTheme.mButton_Inset.mY;
  v19.mH = result.mH;
  v9 = _mm_cvtsi128_si32((__m128i)result);
  v19.mY = mY + result.mY;
  v19.mX = v9 + mX;
  v19.mW = result.mW - 2 * mX;
  v10 = result.mH - 2 * mY;
  v11 = this->mTheme.mButton_Text.mY;
  v19.mH = v10;
  v12 = this->mTheme.mButton_Text.mX;
  v13 = v19;
  v19.mY = v11 + result.mY;
  rect = v13;
  v19.mX = v9 + v12;
  v19.mW = result.mW - 2 * v12;
  v19.mH = result.mH - 2 * v11;
  UFG::DUIContext::Clickable(this, &click_state, &result, &result, ClickableFlags_ConsumeInput);
  v14 = click_state == Clickable_Clicked;
  v15 = &this->mTheme.mColour[12];
  v16 = click_state == Clickable_IsHot;
  if ( click_state != Clickable_IsHot )
    v15 = &this->mTheme.mColour[11];
  UFG::DUIContext::RenderRoundRect(this, &rect, v15, 0);
  mColour = &this->mTheme.mColour[2];
  if ( !v16 )
    mColour = this->mTheme.mColour;
  UFG::DUIContext::RenderText(this, &v19, mColour, name, text_alignment);
  return v14;
}

// File Line: 4363
// RVA: 0x19F2C0
_BOOL8 __fastcall UFG::DUIContext::ToggleButton(UFG::DUIContext *this, const char *name, bool *current_value)
{
  int v6; // eax
  int mX; // ecx
  int mY; // edx
  int v9; // r8d
  float v10; // ecx
  int v11; // edx
  int v12; // ecx
  UFG::qColour v13; // xmm0
  bool v14; // r14
  unsigned int flags; // esi
  UFG::qColour *v16; // r8
  UFG::qColour *mColour; // rcx
  bool v18; // zf
  UFG::qColour colour; // [rsp+30h] [rbp-40h] BYREF
  UFG::DUIRect result; // [rsp+40h] [rbp-30h] BYREF
  UFG::DUIRect rect; // [rsp+50h] [rbp-20h] BYREF
  UFG::DUIRect v23; // [rsp+60h] [rbp-10h] BYREF
  UFG::DUIContext::ClickableState click_state; // [rsp+90h] [rbp+20h] BYREF

  v6 = UFG::qStringLength(name);
  UFG::DUIContext::GetLayoutRect(
    this,
    &result,
    (int)(float)((float)v6 * this->mFontDimensions.x) + 2 * this->mTheme.mButton_Text.mX,
    0);
  mX = this->mTheme.mButton_Inset.mX;
  mY = this->mTheme.mButton_Inset.mY;
  LODWORD(colour.a) = result.mH;
  v9 = _mm_cvtsi128_si32((__m128i)result);
  LODWORD(colour.g) = mY + result.mY;
  LODWORD(colour.r) = v9 + mX;
  LODWORD(colour.b) = result.mW - 2 * mX;
  LODWORD(v10) = result.mH - 2 * mY;
  v11 = this->mTheme.mButton_Text.mY;
  colour.a = v10;
  v12 = this->mTheme.mButton_Text.mX;
  v13 = colour;
  LODWORD(colour.g) = v11 + result.mY;
  rect = (UFG::DUIRect)v13;
  LODWORD(colour.r) = v9 + v12;
  LODWORD(colour.b) = result.mW - 2 * v12;
  LODWORD(colour.a) = result.mH - 2 * v11;
  v23 = (UFG::DUIRect)colour;
  UFG::DUIContext::Clickable(this, &click_state, &result, &result, ClickableFlags_ConsumeInput);
  v14 = click_state == Clickable_IsHot;
  if ( click_state == Clickable_Clicked )
    *current_value = !*current_value;
  flags = 16;
  v16 = &this->mTheme.mColour[12];
  if ( !*current_value )
    v16 = &this->mTheme.mColour[11];
  UFG::DUIContext::RenderRoundRect(this, &rect, v16, 0);
  mColour = this->mTheme.mColour;
  if ( v14 )
    flags = 80;
  v18 = !*current_value;
  colour.r = mColour->r;
  colour.g = this->mTheme.mColour[0].g;
  colour.b = this->mTheme.mColour[0].b;
  colour.a = this->mTheme.mColour[0].a;
  if ( !v18 )
  {
    if ( !v14 )
      mColour = &this->mTheme.mColour[2];
    colour = *mColour;
  }
  UFG::DUIContext::RenderText(this, &v23, &colour, name, flags);
  return *current_value;
}

// File Line: 4405
// RVA: 0x196D80
bool __fastcall UFG::DUIContext::CommandButton(
        UFG::DUIContext *this,
        UFG::Command *command,
        UFG::CommandContext *context)
{
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  int *p_mCount; // rax
  UFG::allocator::free_link *v9; // rbx
  int v10; // eax
  UFG::qBaseNodeRB *v11; // rdx
  UFG::Command::State v12; // eax
  unsigned int menu_image_uid; // [rsp+60h] [rbp+8h] BYREF
  UFG::allocator::free_link *v15; // [rsp+68h] [rbp+10h]

  v6 = UFG::qStringHashUpper32("DUIContext", -1);
  if ( v6
    && (v7 = UFG::qBaseTreeRB::Get(&context->mDictionary.mTree, v6)) != 0i64
    && (p_mCount = &v7[-1].mCount) != 0i64 )
  {
    *((_QWORD *)p_mCount + 5) = this;
  }
  else
  {
    v9 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v15 = v9;
    if ( v9 )
    {
      v10 = UFG::qStringHashUpper32("DUIContext", -1);
      v9[1].mNext = 0i64;
      v9[2].mNext = 0i64;
      v9[3].mNext = 0i64;
      LODWORD(v9[4].mNext) = v10;
      v9->mNext = (UFG::allocator::free_link *)&UFG::ContextDataBase::`vftable;
      v9->mNext = (UFG::allocator::free_link *)&UFG::ContextData<UFG::DUIContext *>::`vftable;
      v9[5].mNext = (UFG::allocator::free_link *)this;
    }
    else
    {
      v9 = 0i64;
    }
    v11 = (UFG::qBaseNodeRB *)&v9[1];
    if ( !v9 )
      v11 = 0i64;
    UFG::qBaseTreeRB::Add(&context->mDictionary.mTree, v11);
  }
  menu_image_uid = 0;
  v12 = command->vfptr->GetState(command, context, &menu_image_uid);
  return UFG::DUIContext::CommandButton(this, command, context, v12, &menu_image_uid);
}

// File Line: 4415
// RVA: 0x196E90
bool __fastcall UFG::DUIContext::CommandButton(
        UFG::DUIContext *this,
        UFG::Command *command,
        UFG::CommandContext *context,
        UFG::Command::State state)
{
  unsigned int v9; // eax
  UFG::qBaseTreeRB *v10; // rax
  int *p_mCount; // rax
  UFG::allocator::free_link *v12; // rdi
  int v13; // eax
  UFG::qBaseNodeRB *v14; // rdx
  int mY; // ecx
  int mX; // eax
  int v17; // edx
  int v18; // ecx
  bool v19; // r12
  bool v20; // di
  UFG::qColour *v21; // rcx
  UFG::qColour *mColour; // rcx
  UFG::qColour colour; // [rsp+8h] [rbp-51h] BYREF
  UFG::DUIContext::ClickableFlags flags[4]; // [rsp+18h] [rbp-41h] BYREF
  UFG::DUIRect v25; // [rsp+28h] [rbp-31h] BYREF
  UFG::DUIRect result; // [rsp+38h] [rbp-21h] BYREF
  UFG::DUIRect rect; // [rsp+48h] [rbp-11h] BYREF
  __int64 v28; // [rsp+58h] [rbp-1h]
  UFG::qString out_string; // [rsp+60h] [rbp+7h] BYREF
  UFG::DUIContext::ClickableState click_state; // [rsp+D0h] [rbp+77h] BYREF
  unsigned int *retaddr; // [rsp+D8h] [rbp+7Fh]

  v28 = -2i64;
  if ( state == State_Unavailable )
    return 0;
  v9 = UFG::qStringHashUpper32("DUIContext", -1);
  if ( v9
    && (v10 = UFG::qBaseTreeRB::Get(&context->mDictionary.mTree, v9)) != 0i64
    && (p_mCount = &v10[-1].mCount) != 0i64 )
  {
    *((_QWORD *)p_mCount + 5) = this;
  }
  else
  {
    v12 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    *(_QWORD *)flags = v12;
    if ( v12 )
    {
      v13 = UFG::qStringHashUpper32("DUIContext", -1);
      v14 = 0i64;
      v12[1].mNext = 0i64;
      v12[2].mNext = 0i64;
      v12[3].mNext = 0i64;
      LODWORD(v12[4].mNext) = v13;
      v12->mNext = (UFG::allocator::free_link *)&UFG::ContextDataBase::`vftable;
      v12->mNext = (UFG::allocator::free_link *)&UFG::ContextData<UFG::DUIContext *>::`vftable;
      v12[5].mNext = (UFG::allocator::free_link *)this;
    }
    else
    {
      v14 = 0i64;
      v12 = 0i64;
    }
    if ( v12 )
      v14 = (UFG::qBaseNodeRB *)&v12[1];
    UFG::qBaseTreeRB::Add(&context->mDictionary.mTree, v14);
  }
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  rect = result;
  rect.mW = this->mTheme.mMenuImage_Inset;
  *(UFG::DUIRect *)flags = result;
  mY = this->mTheme.mButton_Inset.mY;
  mX = this->mTheme.mButton_Inset.mX;
  flags[0] = mX + rect.mW + _mm_cvtsi128_si32((__m128i)result);
  flags[2] = result.mW - rect.mW - 2 * mX;
  flags[1] = mY + result.mY;
  flags[3] = result.mH - 2 * mY;
  v25 = *(UFG::DUIRect *)flags;
  v17 = this->mTheme.mButton_Text.mY;
  v18 = this->mTheme.mButton_Text.mX;
  v25.mX = v18 + flags[0];
  v25.mW = flags[2] - 2 * v18;
  v25.mY = v17 + flags[1];
  v25.mH = flags[3] - 2 * v17;
  v19 = 0;
  v20 = 0;
  UFG::qString::qString(&out_string);
  if ( *retaddr )
    UFG::DUIContext::RenderRect(this, &rect, &colour, *retaddr);
  UFG::BuildCommandKeyString(command, &out_string);
  if ( state != State_Enabled
    || (UFG::DUIContext::Clickable(this, &click_state, &result, &result, ClickableFlags_ConsumeInput),
        v19 = click_state == Clickable_Clicked,
        v20 = click_state == Clickable_IsHot,
        v21 = &this->mTheme.mColour[12],
        click_state != Clickable_IsHot) )
  {
    v21 = &this->mTheme.mColour[11];
  }
  result = (UFG::DUIRect)*v21;
  if ( state == State_Enabled )
  {
    mColour = &this->mTheme.mColour[2];
    if ( !v20 )
      mColour = this->mTheme.mColour;
  }
  else
  {
    mColour = &this->mTheme.mColour[1];
  }
  colour = *mColour;
  if ( v20 )
    UFG::DUIContext::RenderRoundRect(this, (UFG::DUIRect *)flags, (UFG::qColour *)&result, 0);
  UFG::DUIContext::RenderText(this, &v25, &colour, command->mDisplayText.mData, 0x10u);
  if ( out_string.mLength )
    UFG::DUIContext::RenderText(this, &v25, &colour, out_string.mData, 0x14u);
  if ( v19 && state == State_Enabled )
    command->vfptr->Execute(command, context);
  UFG::qString::~qString(&out_string);
  return v19;
}

// File Line: 4484
// RVA: 0x1971B0
__int64 __fastcall UFG::DUIContext::CommandImageButton(
        UFG::DUIContext *this,
        UFG::Command *command,
        UFG::CommandContext *context)
{
  __int64 v6; // rax
  int v7; // esi
  int mY; // r8d
  int mX; // edx
  bool v10; // r14
  bool v11; // r15
  int v12; // xmm0_4
  UFG::qColour *v13; // rcx
  char *mData; // r8
  UFG::qString *v15; // rax
  UFG::DUIRect rect; // [rsp+30h] [rbp-59h] BYREF
  UFG::DUIRect result; // [rsp+40h] [rbp-49h] BYREF
  UFG::qString out_string; // [rsp+50h] [rbp-39h] BYREF
  __int64 v19; // [rsp+78h] [rbp-11h]
  UFG::qString v20; // [rsp+80h] [rbp-9h] BYREF
  unsigned int texture_uid; // [rsp+F8h] [rbp+6Fh] BYREF
  UFG::DUIContext::ClickableState click_state; // [rsp+108h] [rbp+7Fh] BYREF

  v19 = -2i64;
  texture_uid = 0;
  v6 = ((__int64 (__fastcall *)(UFG::Command *, UFG::CommandContext *, unsigned int *))command->vfptr->GetState)(
         command,
         context,
         &texture_uid);
  v7 = v6;
  if ( (_DWORD)v6 )
  {
    UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
    rect = result;
    mY = this->mTheme.mButton_Inset.mY;
    mX = this->mTheme.mButton_Inset.mX;
    rect.mX = mX + _mm_cvtsi128_si32((__m128i)result);
    rect.mW = result.mW - 2 * mX;
    rect.mY = mY + result.mY;
    rect.mH = result.mH - 2 * mY;
    v10 = 0;
    v11 = 0;
    UFG::qString::qString(&out_string);
    if ( texture_uid )
    {
      v12 = (int)FLOAT_1_0;
      if ( v7 == 2 )
        v12 = LODWORD(FLOAT_0_5);
      result.mX = 1065353216;
      result.mY = 1065353216;
      result.mW = 1065353216;
      result.mH = v12;
      UFG::DUIContext::RenderRoundRect(this, &rect, (UFG::qColour *)&result, texture_uid);
    }
    UFG::BuildCommandKeyString(command, &out_string);
    if ( v7 != 1
      || (UFG::DUIContext::Clickable(this, &click_state, &rect, &rect, ClickableFlags_ConsumeInput),
          v10 = click_state == Clickable_Clicked,
          v11 = click_state == Clickable_IsHot,
          v13 = &this->mTheme.mColour[12],
          click_state != Clickable_IsHot) )
    {
      v13 = &this->mTheme.mColour[11];
    }
    result = (UFG::DUIRect)*v13;
    if ( v11 )
      UFG::DUIContext::RenderRoundRect(this, &rect, (UFG::qColour *)&result, 0);
    mData = command->mDisplayText.mData;
    if ( out_string.mLength )
      v15 = UFG::qString::FormatEx(&v20, "%s (%s)", mData, out_string.mData);
    else
      v15 = UFG::qString::FormatEx(&v20, "%s", mData);
    UFG::DUIContext::Tooltip(this, v15->mData, &rect);
    UFG::qString::~qString(&v20);
    if ( v10 && v7 == 1 )
      command->vfptr->Execute(command, context);
    UFG::qString::~qString(&out_string);
    return v10;
  }
  return v6;
}

// File Line: 4550
// RVA: 0x194FF0
void __fastcall UFG::DUIContext::BeginTreeView(
        UFG::DUIContext *this,
        UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *selected_items,
        UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *expanded_items,
        bool multiselect)
{
  UFG::DUIRect *LayoutRect; // rax
  UFG::DUILayoutState *v9; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v10; // rcx
  UFG::DUIRect result; // [rsp+28h] [rbp-30h] BYREF

  LayoutRect = UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v9 = UFG::DUIContext::PushLayoutState(this, LayoutRect, LayoutFlag_FillLastCol);
  *(_QWORD *)&v9->mNumCols = 1i64;
  v9->mColWidths = 0i64;
  v9->mRowHeights = 0i64;
  LOBYTE(this->mLayoutStack.mNode.mNext[8].mNext) = multiselect;
  this->mLayoutStack.mNode.mNext[8].mPrev = selected_items;
  this->mLayoutStack.mNode.mNext[9].mPrev = expanded_items;
  if ( multiselect && this->mInputState.mKeyIsDownShift
    || ((this->mInputState.mKeycodeDown - 38) & 0xFD) == 0
    && ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))selected_items->mPrev[3].mPrev)(selected_items) == 1 )
  {
    v10 = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)UFG::qMalloc(0x18ui64, "DUIIntArray", 0x800ui64);
    if ( v10 )
    {
      v10->mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&UFG::DUIIntArray::`vftable;
      v10[1].mPrev = 0i64;
      v10->mNext = 0i64;
    }
    else
    {
      v10 = 0i64;
    }
    this->mLayoutStack.mNode.mNext[7].mNext = v10;
  }
}

// File Line: 4567
// RVA: 0x1990D0
void __fastcall UFG::DUIContext::HandleSelection(
        UFG::DUIContext *this,
        unsigned __int64 id,
        UFG::DUIIntArray *accumulatedItems,
        UFG::IDUICollectionView *selectedItems,
        bool *is_selected,
        int *selection_index)
{
  bool v9; // al
  unsigned int v10; // ebx
  unsigned int v11; // ebp
  UFG::IDUICollectionViewVtbl *vfptr; // rbx
  unsigned int v13; // eax
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rsi

  if ( this->mInputState.mKeyIsDownControl )
  {
    v9 = !*is_selected;
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
  if ( accumulatedItems )
  {
    v10 = 0;
    v11 = accumulatedItems->vfptr->Count(accumulatedItems);
    if ( selectedItems->vfptr->Count(selectedItems) )
    {
      vfptr = selectedItems->vfptr;
      v13 = selectedItems->vfptr->Count(selectedItems);
      v14 = vfptr->GetAt(selectedItems, v13 - 1);
      v10 = accumulatedItems->vfptr->IndexOf(accumulatedItems, v14);
    }
    for ( ; v10 < v11; ++v10 )
    {
      v15 = accumulatedItems->vfptr->GetAt(accumulatedItems, v10);
      if ( selectedItems->vfptr->IndexOf(selectedItems, v15) == -1 )
        selectedItems->vfptr->Add(selectedItems, v15);
    }
  }
  else
  {
    selectedItems->vfptr->Add(selectedItems, id);
  }
}

// File Line: 4623
// RVA: 0x19F650
__int64 __fastcall UFG::DUIContext::TreeViewItem(
        UFG::DUIContext *this,
        const char *name,
        unsigned __int64 id,
        bool has_children)
{
  UFG::DUIRect v7; // xmm1
  int mY; // edx
  int mX; // ecx
  int v10; // r8d
  int v11; // edx
  int v12; // ecx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // rcx
  int v14; // eax
  UFG::DUIIntArray *v15; // r12
  unsigned int v16; // r14d
  bool v17; // r13
  bool v18; // bl
  char v19; // r14
  const char *v20; // rdx
  int flags; // [rsp+20h] [rbp-69h]
  UFG::DUIRect selectedItemsa; // [rsp+30h] [rbp-59h]
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *selectedItems; // [rsp+30h] [rbp-59h]
  UFG::DUIContext::ClickableState click_state; // [rsp+40h] [rbp-49h] BYREF
  int selection_index[3]; // [rsp+44h] [rbp-45h] BYREF
  UFG::DUIRect result; // [rsp+50h] [rbp-39h] BYREF
  UFG::DUIRect rect; // [rsp+60h] [rbp-29h] BYREF
  UFG::DUIRect current_rect; // [rsp+70h] [rbp-19h] BYREF
  UFG::qString v30; // [rsp+80h] [rbp-9h] BYREF
  __int64 v31; // [rsp+A8h] [rbp+1Fh]
  bool is_selected; // [rsp+F0h] [rbp+67h] BYREF
  bool v33; // [rsp+108h] [rbp+7Fh]

  v33 = has_children;
  v31 = -2i64;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v7 = result;
  current_rect = result;
  current_rect.mW = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)result, 12));
  mY = this->mTheme.mButton_Text.mY;
  mX = this->mTheme.mButton_Text.mX;
  v10 = _mm_cvtsi128_si32((__m128i)result);
  selectedItemsa.mX = v10 + mX;
  selectedItemsa.mW = result.mW - 2 * mX;
  selectedItemsa.mY = mY + result.mY;
  selectedItemsa.mH = result.mH - 2 * mY;
  result = selectedItemsa;
  v11 = this->mTheme.mButton_Inset.mY;
  v12 = this->mTheme.mButton_Inset.mX;
  selectedItemsa.mX = v10 + v12;
  selectedItemsa.mW = v7.mW - 2 * v12;
  selectedItemsa.mY = v11 + v7.mY;
  selectedItemsa.mH = v7.mH - 2 * v11;
  rect = selectedItemsa;
  mNext = this->mLayoutStack.mNode.mNext;
  v14 = this->mTheme.mIndent * LODWORD(mNext[4].mPrev);
  rect.mX = selectedItemsa.mX - v14;
  rect.mW = v14 + selectedItemsa.mW;
  v15 = (UFG::DUIIntArray *)mNext[7].mNext;
  if ( v15 )
    v15->vfptr->Add((UFG::IDUICollectionView *)mNext[7].mNext, id);
  selectedItems = this->mLayoutStack.mNode.mNext[8].mPrev;
  selection_index[0] = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, unsigned __int64))selectedItems->mPrev[2].mPrev)(
                         mNext,
                         id);
  v16 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, unsigned __int64))this->mLayoutStack.mNode.mNext[9].mPrev->mPrev[2].mPrev)(
          this->mLayoutStack.mNode.mNext[9].mPrev,
          id);
  v17 = selection_index[0] != -1;
  is_selected = v17;
  v18 = v16 != -1;
  UFG::DUIContext::Clickable(this, &click_state, &current_rect, &current_rect, ClickableFlags_ConsumeInput);
  if ( click_state == Clickable_Clicked )
    v18 = v16 == -1;
  UFG::DUIContext::Clickable(this, &click_state, &result, &result, ClickableFlags_ConsumeInput);
  if ( click_state == Clickable_Clicked )
  {
    UFG::DUIContext::HandleSelection(
      this,
      id,
      v15,
      (UFG::IDUICollectionView *)selectedItems,
      &is_selected,
      selection_index);
    v17 = is_selected;
  }
  if ( v18 )
  {
    if ( v16 == -1 )
      ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, unsigned __int64))this->mLayoutStack.mNode.mNext[9].mPrev->mPrev->mPrev)(
        this->mLayoutStack.mNode.mNext[9].mPrev,
        id);
  }
  else if ( v16 != -1 )
  {
    ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, _QWORD))this->mLayoutStack.mNode.mNext[9].mPrev->mPrev[1].mPrev)(
      this->mLayoutStack.mNode.mNext[9].mPrev,
      v16);
  }
  UFG::qString::qString(&v30);
  v19 = v33;
  flags = UFG::qStringLength(name);
  if ( v19 )
  {
    if ( v18 )
      v20 = "- ";
    else
      v20 = "+ ";
  }
  else
  {
    v20 = "  ";
  }
  UFG::qString::Set(&v30, v20, 2, name, flags);
  if ( v17 )
    UFG::DUIContext::RenderRoundRect(this, &rect, &this->mTheme.mColour[12], 0);
  UFG::DUIContext::RenderText(this, &result, this->mTheme.mColour, v30.mData, 0);
  UFG::qString::~qString(&v30);
  return (unsigned __int8)v19 & v18;
}

// File Line: 4718
// RVA: 0x198090
void __fastcall UFG::DUIContext::EndTreeView(UFG::DUIContext *this)
{
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v3; // r14
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mPrev; // rdi
  __int64 v5; // rax
  int v6; // ebx
  int v7; // ebx
  __int64 v8; // rdx
  int v9; // eax
  __int64 v10; // rbx

  mNext = this->mLayoutStack.mNode.mNext;
  v3 = mNext[7].mNext;
  if ( v3 )
  {
    mPrev = mNext[8].mPrev;
    if ( mPrev )
    {
      if ( ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))mPrev->mPrev[3].mPrev)(mPrev) == 1 )
      {
        v5 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, _QWORD))mPrev->mPrev[1].mNext)(
               mPrev,
               0i64);
        v6 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v3->mPrev[2].mPrev)(
               v3,
               v5);
        if ( ((this->mInputState.mKeycodeDown - 38) & 0xFD) == 0
          && UFG::DUIContext::IsMouseOver(this, (UFG::DUIRect *)&this->mLayoutStack.mNode.mNext[1]) )
        {
          if ( this->mInputState.mKeycodeDown == 38 )
            v7 = v6 - 1;
          else
            v7 = v6 + 1;
          v8 = ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v3->mPrev[3].mPrev)(v3)
             - 1;
          v9 = 0;
          if ( v7 > 0 )
            v9 = v7;
          if ( v9 < (int)v8 )
            v8 = (unsigned int)v9;
          v10 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v3->mPrev[1].mNext)(
                  v3,
                  v8);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))mPrev->mPrev[2].mNext)(mPrev);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))mPrev->mPrev->mPrev)(
            mPrev,
            v10);
        }
      }
    }
  }
  UFG::DUIContext::PopLayoutState(this);
}

// File Line: 4747
// RVA: 0x194C30
void __fastcall UFG::DUIContext::BeginListView(
        UFG::DUIContext *this,
        UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *selected_items,
        UFG::DUIPoint *current_scroll_pos,
        bool multiselect)
{
  UFG::DUIRect *LayoutRect; // rax
  UFG::DUILayoutState *v8; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v9; // rcx
  UFG::DUIRect result; // [rsp+28h] [rbp-20h] BYREF

  UFG::DUIContext::BeginScrollView(this, current_scroll_pos);
  LayoutRect = UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v8 = UFG::DUIContext::PushLayoutState(this, LayoutRect, LayoutFlag_FillLastCol);
  *(_QWORD *)&v8->mNumCols = 1i64;
  v8->mColWidths = 0i64;
  v8->mRowHeights = 0i64;
  this->mLayoutStack.mNode.mNext[8].mPrev = selected_items;
  LOBYTE(this->mLayoutStack.mNode.mNext[8].mNext) = multiselect;
  if ( multiselect && this->mInputState.mKeyIsDownShift
    || ((this->mInputState.mKeycodeDown - 38) & 0xFD) == 0
    && ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))selected_items->mPrev[3].mPrev)(selected_items) == 1 )
  {
    v9 = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)UFG::qMalloc(0x18ui64, "DUIIntArray", 0x800ui64);
    if ( v9 )
    {
      v9->mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&UFG::DUIIntArray::`vftable;
      v9[1].mPrev = 0i64;
      v9->mNext = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    this->mLayoutStack.mNode.mNext[7].mNext = v9;
  }
}

// File Line: 4764
// RVA: 0x19A150
bool __fastcall UFG::DUIContext::ListViewItem(
        UFG::DUIContext *this,
        char *name,
        unsigned __int64 id,
        bool *out_is_selected)
{
  int mX; // r8d
  int mY; // r9d
  int v9; // r10d
  int v10; // edx
  int v11; // ecx
  UFG::DUIRect v12; // xmm0
  UFG::DUIIntArray *mNext; // r15
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mPrev; // rsi
  int v15; // eax
  bool v16; // di
  int v17; // r14d
  UFG::DUIContext::ClickableState click_state[4]; // [rsp+30h] [rbp-40h] BYREF
  UFG::DUIRect v20; // [rsp+40h] [rbp-30h] BYREF
  UFG::DUIRect result; // [rsp+50h] [rbp-20h] BYREF
  UFG::DUIRect rect; // [rsp+60h] [rbp-10h] BYREF
  bool is_selected; // [rsp+B0h] [rbp+40h] BYREF
  char *text; // [rsp+B8h] [rbp+48h]
  int selection_index; // [rsp+C8h] [rbp+58h] BYREF

  text = name;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  mX = this->mTheme.mButton_Inset.mX;
  mY = this->mTheme.mButton_Inset.mY;
  v20 = result;
  v9 = _mm_cvtsi128_si32((__m128i)result);
  v20.mY = mY + result.mY;
  v10 = this->mTheme.mButton_Text.mY;
  v20.mX = v9 + mX;
  v20.mW = result.mW - 2 * mX;
  v20.mH = result.mH - 2 * mY;
  v11 = this->mTheme.mButton_Text.mX;
  v12 = v20;
  v20.mH = result.mH;
  v20.mY = v10 + result.mY;
  rect = v12;
  v20.mX = v9 + v11;
  v20.mW = result.mW - 2 * v11;
  mNext = (UFG::DUIIntArray *)this->mLayoutStack.mNode.mNext[7].mNext;
  v20.mH = result.mH - 2 * v10;
  if ( mNext )
    mNext->vfptr->Add(mNext, id);
  mPrev = this->mLayoutStack.mNode.mNext[8].mPrev;
  v15 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, unsigned __int64))mPrev->mPrev[2].mPrev)(
          mPrev,
          id);
  v16 = v15 != -1;
  v17 = v15;
  selection_index = v15;
  is_selected = v16;
  UFG::DUIContext::Clickable(this, click_state, &result, &result, ClickableFlags_ConsumeInput);
  if ( click_state[0] == Clickable_Clicked )
  {
    UFG::DUIContext::HandleSelection(this, id, mNext, (UFG::IDUICollectionView *)mPrev, &is_selected, &selection_index);
    v17 = selection_index;
    v16 = is_selected;
  }
  if ( v16 )
  {
    UFG::DUIContext::RenderRoundRect(this, &rect, &this->mTheme.mColour[12], 0);
    UFG::DUIContext::PushColour(this, TextColour, &UFG::qColourBlack);
  }
  UFG::DUIContext::RenderText(this, &v20, this->mTheme.mColour, text, 0);
  if ( v16 )
    UFG::DUIContext::PopColour(this, TextColour);
  if ( out_is_selected )
    *out_is_selected = v16;
  return v16 != (v17 != -1);
}

// File Line: 4818
// RVA: 0x197D00
void __fastcall UFG::DUIContext::EndListView(UFG::DUIContext *this)
{
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // rsi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v3; // r14
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mPrev; // rsi
  __int64 v5; // rax
  int v6; // ebx
  int v7; // ebx
  __int64 v8; // rdx
  int v9; // eax
  __int64 v10; // rbx

  mNext = this->mLayoutStack.mNode.mNext;
  v3 = mNext[7].mNext;
  if ( v3 )
  {
    mPrev = mNext[8].mPrev;
    if ( mPrev )
    {
      if ( ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))mPrev->mPrev[3].mPrev)(mPrev) == 1 )
      {
        v5 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, _QWORD))mPrev->mPrev[1].mNext)(
               mPrev,
               0i64);
        v6 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v3->mPrev[2].mPrev)(
               v3,
               v5);
        if ( ((this->mInputState.mKeycodeDown - 38) & 0xFD) == 0
          && UFG::DUIContext::IsMouseOver(this, (UFG::DUIRect *)&this->mLayoutStack.mNode.mNext[1]) )
        {
          if ( this->mInputState.mKeycodeDown == 38 )
            v7 = v6 - 1;
          else
            v7 = v6 + 1;
          v8 = ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v3->mPrev[3].mPrev)(v3)
             - 1;
          v9 = 0;
          if ( v7 > 0 )
            v9 = v7;
          if ( v9 < (int)v8 )
            v8 = (unsigned int)v9;
          v10 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v3->mPrev[1].mNext)(
                  v3,
                  v8);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))mPrev->mPrev[2].mNext)(mPrev);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))mPrev->mPrev->mPrev)(
            mPrev,
            v10);
        }
      }
    }
  }
  UFG::DUIContext::PopLayoutState(this);
  UFG::DUIContext::EndScrollView(this);
}

// File Line: 4852
// RVA: 0x194060
void __fastcall UFG::DUIContext::BeginDataGrid(
        UFG::DUIContext *this,
        int num_cols,
        const char **headings,
        int *column_widths,
        UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *selected_items,
        UFG::DUIPoint *current_scroll_pos,
        int *sort_index,
        bool multiselect,
        int virtual_row_count,
        UFG::DUIVirtualGridMetrics *metrics)
{
  UFG::DUIRect *LayoutRect; // rax
  UFG::DUILayoutState *v15; // rax
  __int64 v16; // rdi
  int mX; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // esi
  __int64 i; // rbp
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // rdi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mPrev; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v24; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v25; // rsi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v26; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v27; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v28; // rax
  int v29; // edi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v30; // rcx
  int v31; // edx
  int v32; // ecx
  float v33; // xmm0_4
  int v34; // ecx
  int j; // eax
  int k; // eax
  int v37; // eax
  int v38; // edx
  UFG::DUIRect result; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString v40; // [rsp+48h] [rbp-50h] BYREF

  LayoutRect = UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v15 = UFG::DUIContext::PushLayoutState(this, LayoutRect, LayoutFlag_FillLastCell);
  v15->mNumCols = 1;
  v15->mNumRows = 2;
  v16 = 0i64;
  v15->mColWidths = 0i64;
  v15->mRowHeights = 0i64;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  mX = this->mTheme.mClientInset.mX;
  v18 = -2 * mX - this->mTheme.mScrollbarW + result.mW;
  this->mLayoutOverrideRect.mX = mX + result.mX;
  this->mLayoutOverrideRect.mY = result.mY;
  this->mLayoutOverrideRect.mW = v18;
  this->mLayoutOverrideRect.mH = result.mH;
  this->mLayoutOverrideRectEnabled = 1;
  UFG::DUIContext::BeginGridLayout(this, num_cols, 1, column_widths, 0i64, 12);
  if ( sort_index )
    v19 = *sort_index;
  else
    v19 = -1;
  v20 = 0;
  for ( i = v19; v20 < num_cols; ++v16 )
  {
    if ( i >= 0 )
    {
      if ( v16 == i )
      {
        UFG::qString::FormatEx(&v40, "%s %s", pattern, headings[v16]);
        UFG::DUIContext::Button(this, v40.mData, 0x10u);
        UFG::qString::~qString(&v40);
      }
      else if ( UFG::DUIContext::Button(this, headings[v16], 0x10u) )
      {
        *sort_index = v20;
      }
    }
    else
    {
      UFG::DUIContext::Button(this, headings[v16], 0x10u);
    }
    ++v20;
  }
  mNext = this->mLayoutStack.mNode.mNext;
  mPrev = mNext->mPrev;
  v24 = mNext->mNext;
  mPrev->mNext = v24;
  v24->mPrev = mPrev;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  if ( LOBYTE(mNext[4].mNext) )
    UFG::DUIContext::PopScissor(this);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)this->mLayoutStack.mNode.mNext != &this->mLayoutStack
    && this->mCurrentCompositeLayer != CompositeLayer_Overlay )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&this->mLayoutStack.mNode.mNext[3], (UFG::DUIRect *)&mNext[3]);
  }
  v25 = mNext[7].mNext;
  if ( v25 )
  {
    v26 = v25[1].mPrev;
    if ( v26 )
      operator delete[](v26);
    v25[1].mPrev = 0i64;
    v25->mNext = 0i64;
    operator delete[](v25);
  }
  mNext[7].mNext = 0i64;
  v27 = mNext->mPrev;
  v28 = mNext->mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  operator delete[](mNext);
  UFG::DUIContext::BeginScrollView(this, current_scroll_pos);
  v29 = 0;
  if ( virtual_row_count > -1 )
  {
    this->mLayoutStack.mNode.mNext[9].mNext = 0i64;
    v29 = SHIDWORD(this->mLayoutStack.mNode.mNext[7].mPrev->mPrev) / this->mTheme.mRowHeight;
  }
  UFG::DUIContext::BeginGridLayout(this, num_cols, 0, column_widths, 0i64, 0);
  this->mLayoutStack.mNode.mNext[8].mPrev = selected_items;
  this->mLayoutStack.mNode.mNext[10].mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)virtual_row_count;
  LOBYTE(this->mLayoutStack.mNode.mNext[8].mNext) = multiselect;
  if ( multiselect && this->mInputState.mKeyIsDownShift
    || ((this->mInputState.mKeycodeDown - 38) & 0xFD) == 0
    && ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))selected_items->mPrev[3].mPrev)(selected_items) == 1 )
  {
    v30 = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)UFG::qMalloc(0x18ui64, "DUIIntArray", 0x800ui64);
    if ( v30 )
    {
      v30->mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&UFG::DUIIntArray::`vftable;
      v30[1].mPrev = 0i64;
      v30->mNext = 0i64;
    }
    else
    {
      v30 = 0i64;
    }
    this->mLayoutStack.mNode.mNext[7].mNext = v30;
  }
  if ( virtual_row_count > -1 )
  {
    v31 = (int)(((double)SHIDWORD(this->mLayoutStack.mNode.mNext[1].mNext) + (double)this->mTheme.mRowHeight * 0.5)
              / (double)this->mTheme.mRowHeight);
    v32 = virtual_row_count;
    if ( v31 + v29 < virtual_row_count )
      v32 = v31 + v29;
    v33 = 0.0;
    if ( (float)v32 >= 0.0 )
      v33 = (float)v32;
    v34 = (int)v33;
    for ( j = (int)v33 - v29; j < v31; ++j )
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
    if ( this->mIsScrollViewDragging )
    {
      v37 = v34 - v29;
      v38 = metrics->mEnd - metrics->mStart;
      if ( v34 - v29 < v38 || v37 > v38 )
        this->mFocusedID += v37 - v38;
    }
    metrics->mStart = v29;
    metrics->mEnd = v34;
    HIDWORD(this->mLayoutStack.mNode.mNext[10].mNext) = v29;
    LODWORD(this->mLayoutStack.mNode.mNext[10].mNext) = v34;
  }
}

// File Line: 4943
// RVA: 0x1944A0
_BOOL8 __fastcall UFG::DUIContext::BeginDataGridItem(
        UFG::DUIContext *this,
        unsigned __int64 id,
        bool *out_is_selected,
        UFG::DUIRect *out_rect)
{
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // rax
  UFG::DUIRect v9; // xmm0
  UFG::DUIRect v10; // xmm0
  int mX; // edx
  int mY; // r8d
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v13; // rax
  UFG::DUIIntArray *v14; // r14
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mPrev; // rdi
  int v16; // eax
  bool v17; // di
  int v18; // r15d
  int v19; // esi
  UFG::DUIRect selectedItemsa; // [rsp+30h] [rbp-30h]
  UFG::IDUICollectionView *selectedItems; // [rsp+30h] [rbp-30h]
  UFG::DUIRect result; // [rsp+40h] [rbp-20h] BYREF
  UFG::DUIRect rect; // [rsp+50h] [rbp-10h] BYREF
  bool is_selected; // [rsp+A0h] [rbp+40h] BYREF
  int selection_index; // [rsp+B0h] [rbp+50h] BYREF
  UFG::DUIContext::ClickableState click_state; // [rsp+B8h] [rbp+58h] BYREF

  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  mNext = this->mLayoutStack.mNode.mNext;
  v9 = result;
  this->mLayoutOverrideRectEnabled = 1;
  this->mLayoutOverrideRect = v9;
  result.mW = (int)mNext[1].mNext;
  v10 = result;
  if ( out_rect )
    *out_rect = result;
  mX = this->mTheme.mButton_Inset.mX;
  mY = this->mTheme.mButton_Inset.mY;
  selectedItemsa.mY = mY + v10.mY;
  selectedItemsa.mX = mX + _mm_cvtsi128_si32((__m128i)v10);
  selectedItemsa.mW = v10.mW - 2 * mX;
  v13 = this->mLayoutStack.mNode.mNext;
  v14 = (UFG::DUIIntArray *)v13[7].mNext;
  mPrev = v13[8].mPrev;
  selectedItemsa.mH = v10.mH - 2 * mY;
  rect = selectedItemsa;
  selectedItems = (UFG::IDUICollectionView *)mPrev;
  if ( v14 )
    v14->vfptr->Add(v14, id);
  v16 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, unsigned __int64))mPrev->mPrev[2].mPrev)(
          mPrev,
          id);
  v17 = v16 != -1;
  v18 = 0;
  v19 = v16;
  selection_index = v16;
  is_selected = v17;
  UFG::DUIContext::Clickable(this, &click_state, &result, &result, ClickableFlags_None);
  if ( click_state == Clickable_HasFocus )
  {
    UFG::DUIContext::HandleSelection(this, id, v14, selectedItems, &is_selected, &selection_index);
    v19 = selection_index;
    v17 = is_selected;
  }
  if ( v17 )
    UFG::DUIContext::RenderRoundRect(this, &rect, &this->mTheme.mColour[12], 0);
  if ( out_is_selected )
    *out_is_selected = v17;
  if ( v17 )
  {
    UFG::DUIContext::PushColour(this, TextColour, &this->mTheme.mColour[2]);
    this->mLayoutStack.mNode.mNext[11].mPrev = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)1;
  }
  LOBYTE(v18) = v19 != -1;
  return v17 != v18;
}

// File Line: 5002
// RVA: 0x197C90
void __fastcall UFG::DUIContext::EndDataGridItem(UFG::DUIContext *this)
{
  if ( this->mLayoutStack.mNode.mNext[11].mPrev )
  {
    UFG::DUIContext::PopColour(this, TextColour);
    this->mLayoutStack.mNode.mNext[11].mPrev = 0i64;
  }
}

// File Line: 5011
// RVA: 0x197B40
void __fastcall UFG::DUIContext::EndDataGrid(UFG::DUIContext *this)
{
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // rsi
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v2; // r14
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mPrev; // rsi
  __int64 v5; // rax
  int v6; // ebx
  int v7; // ebx
  __int64 v8; // rdx
  int v9; // eax
  __int64 v10; // rbx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v11; // rax
  int v12; // ebx
  UFG::DUIRect result; // [rsp+20h] [rbp-18h] BYREF

  mNext = this->mLayoutStack.mNode.mNext;
  v2 = mNext[7].mNext;
  if ( v2 )
  {
    mPrev = mNext[8].mPrev;
    if ( mPrev )
    {
      if ( ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))mPrev->mPrev[3].mPrev)(mPrev) == 1 )
      {
        v5 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, _QWORD))mPrev->mPrev[1].mNext)(
               mPrev,
               0i64);
        v6 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v2->mPrev[2].mPrev)(
               v2,
               v5);
        if ( ((this->mInputState.mKeycodeDown - 38) & 0xFD) == 0
          && UFG::DUIContext::IsMouseOver(this, (UFG::DUIRect *)&this->mLayoutStack.mNode.mNext[1]) )
        {
          if ( this->mInputState.mKeycodeDown == 38 )
            v7 = v6 - 1;
          else
            v7 = v6 + 1;
          v8 = ((unsigned int (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))v2->mPrev[3].mPrev)(v2)
             - 1;
          v9 = 0;
          if ( v7 > 0 )
            v9 = v7;
          if ( v9 < (int)v8 )
            v8 = (unsigned int)v9;
          v10 = ((__int64 (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))v2->mPrev[1].mNext)(
                  v2,
                  v8);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *))mPrev->mPrev[2].mNext)(mPrev);
          ((void (__fastcall *)(UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *, __int64))mPrev->mPrev->mPrev)(
            mPrev,
            v10);
        }
      }
    }
  }
  v11 = this->mLayoutStack.mNode.mNext;
  if ( v11[10].mPrev != (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)-1i64 )
  {
    v12 = LODWORD(v11[10].mPrev) + HIDWORD(v11[10].mNext) - LODWORD(v11[10].mNext);
    UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
    HIDWORD(this->mLayoutStack.mNode.mNext[3].mNext) += v12 * this->mTheme.mRowHeight;
  }
  UFG::DUIContext::PopLayoutState(this);
  UFG::DUIContext::EndScrollView(this);
  UFG::DUIContext::PopLayoutState(this);
}

// File Line: 5056
// RVA: 0x1953F0
_BOOL8 __fastcall UFG::DUIContext::Checkbox(UFG::DUIContext *this, const char *name, bool *current_value)
{
  int v6; // eax
  int mX; // r9d
  int mY; // edx
  float v9; // r10d
  int v10; // r8d
  int v11; // eax
  int v12; // ecx
  UFG::DUIRect v13; // xmm1
  float v14; // ecx
  int v15; // eax
  int v16; // edx
  float v17; // ecx
  int v18; // edx
  int v19; // ecx
  UFG::qColour v20; // xmm0
  float v21; // ecx
  int v22; // edx
  int v23; // ecx
  UFG::qColour v24; // xmm0
  bool v25; // cl
  UFG::qColour *mColour; // r8
  UFG::qColour *v27; // rax
  bool v28; // zf
  float g; // xmm1_4
  float b; // xmm0_4
  float a; // xmm1_4
  float v32; // xmm0_4
  UFG::qColour colour; // [rsp+30h] [rbp-19h] BYREF
  UFG::DUIRect v35; // [rsp+40h] [rbp-9h] BYREF
  UFG::DUIRect rect; // [rsp+50h] [rbp+7h] BYREF
  UFG::DUIRect result; // [rsp+60h] [rbp+17h] BYREF
  UFG::DUIRect v38; // [rsp+70h] [rbp+27h] BYREF
  UFG::DUIRect v39; // [rsp+80h] [rbp+37h] BYREF
  UFG::DUIContext::ClickableState click_state; // [rsp+B0h] [rbp+67h] BYREF

  v6 = UFG::qStringLength(name);
  UFG::DUIContext::GetLayoutRect(
    this,
    &result,
    (int)(float)((float)((float)v6 * this->mFontDimensions.x) + (float)(2 * this->mTheme.mCheckBox_Text.mX))
  + (int)(float)((float)(2 * this->mTheme.mCheckBox_Text.mY) + this->mFontDimensions.y),
    0);
  mX = this->mTheme.mCheckBox_Text.mX;
  mY = this->mTheme.mCheckBox_Text.mY;
  LODWORD(colour.g) = mY + result.mY;
  LODWORD(v9) = mX + _mm_cvtsi128_si32((__m128i)result);
  colour.r = v9;
  *(float *)&v35.mX = v9;
  LODWORD(colour.b) = result.mW - 2 * mX;
  v10 = LODWORD(colour.b) - mX;
  LODWORD(colour.a) = result.mH - 2 * mY;
  v11 = LODWORD(colour.a) + mX + LODWORD(v9);
  v35.mY = mY + result.mY;
  rect.mY = mY + result.mY;
  v12 = this->mTheme.mCheckBox_Border.mX;
  v35.mW = LODWORD(colour.a);
  v35.mH = LODWORD(colour.a);
  v13 = v35;
  colour = (UFG::qColour)v35;
  rect.mX = v11;
  LODWORD(colour.r) = v12 + LODWORD(v9);
  LODWORD(v14) = result.mH - 2 * mY - 2 * v12;
  v15 = result.mH - 2 * mY;
  rect.mH = v15;
  v16 = this->mTheme.mCheckBox_Border.mY;
  colour.b = v14;
  rect.mW = v10 - v35.mW;
  LODWORD(colour.g) = v16 + v35.mY;
  LODWORD(v17) = v15 - 2 * v16;
  v18 = this->mTheme.mCheckBox_Inset.mY;
  colour.a = v17;
  v19 = this->mTheme.mCheckBox_Inset.mX;
  v20 = colour;
  colour = (UFG::qColour)v35;
  LODWORD(colour.r) = v19 + LODWORD(v9);
  v35 = (UFG::DUIRect)v20;
  LODWORD(colour.g) += v18;
  LODWORD(colour.b) -= 2 * v19;
  LODWORD(v21) = LODWORD(colour.a) - 2 * v18;
  v22 = this->mTheme.mCheckBox_Check.mY;
  colour.a = v21;
  v23 = this->mTheme.mCheckBox_Check.mX;
  v24 = colour;
  LODWORD(colour.g) = v22 + v13.mY;
  v38 = (UFG::DUIRect)v24;
  LODWORD(colour.r) = v23 + LODWORD(v9);
  LODWORD(colour.b) = v13.mW - 2 * v23;
  LODWORD(colour.a) = v13.mH - 2 * v22;
  v39 = (UFG::DUIRect)colour;
  UFG::DUIContext::Clickable(this, &click_state, &result, &result, ClickableFlags_ConsumeInput);
  v25 = click_state == Clickable_IsHot;
  if ( click_state == Clickable_Clicked )
    *current_value = !*current_value;
  mColour = &this->mTheme.mColour[20];
  if ( v25 )
  {
    v27 = &this->mTheme.mColour[20];
  }
  else
  {
    mColour = this->mTheme.mColour;
    v27 = &this->mTheme.mColour[15];
  }
  v28 = !*current_value;
  g = v27->g;
  colour.r = v27->r;
  b = v27->b;
  colour.g = g;
  a = v27->a;
  colour.b = b;
  colour.a = a;
  if ( v28 )
  {
    if ( v25 )
      v32 = FLOAT_0_30000001;
    else
      v32 = 0.0;
    colour.a = v32;
  }
  UFG::DUIContext::RenderText(this, &rect, mColour, name, 0x10u);
  UFG::DUIContext::RenderRoundRect(this, &v35, &this->mTheme.mColour[13], 0);
  UFG::DUIContext::RenderRoundRect(this, &v38, &this->mTheme.mColour[14], 0);
  UFG::DUIContext::RenderRoundRect(this, &v39, &colour, 0);
  return *current_value;
}

// File Line: 5113
// RVA: 0x1953A0
_BOOL8 __fastcall UFG::DUIContext::Checkbox(
        UFG::DUIContext *this,
        const char *name,
        unsigned int *bitfield,
        unsigned int bitflag)
{
  _BOOL8 result; // rax
  bool current_value; // [rsp+48h] [rbp+20h] BYREF

  current_value = (bitflag & *bitfield) != 0;
  UFG::DUIContext::Checkbox(this, name, &current_value);
  result = current_value;
  if ( current_value )
    *bitfield |= bitflag;
  else
    *bitfield &= ~bitflag;
  return result;
}

// File Line: 5126
// RVA: 0x196C30
_BOOL8 __fastcall UFG::DUIContext::ComboBox(
        UFG::DUIContext *this,
        int *current_index,
        const char **options,
        unsigned int count,
        char **tooltips)
{
  __int64 v8; // rdi
  UFG::qString *v9; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v11; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  bool v13; // di
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // r8
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> optionsa; // [rsp+40h] [rbp-18h] BYREF

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
        UFG::qString::qString(v9, *options);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      mPrev = optionsa.mNode.mPrev;
      optionsa.mNode.mPrev->mNext = v11;
      v11->mPrev = mPrev;
      v11->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&optionsa;
      optionsa.mNode.mPrev = v11;
      ++options;
      --v8;
    }
    while ( v8 );
  }
  v13 = UFG::DUIContext::ComboBox(this, current_index, &optionsa, tooltips, 0xFFFFFFFF);
  for ( i = (UFG::qString *)optionsa.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)optionsa.mNode.mNext != &optionsa;
        i = (UFG::qString *)optionsa.mNode.mNext )
  {
    v15 = i->mPrev;
    mNext = i->mNext;
    v15->mNext = mNext;
    mNext->mPrev = v15;
    i->mPrev = i;
    i->mNext = i;
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
bool __fastcall UFG::DUIContext::ComboBox(
        UFG::DUIContext *this,
        int *current_index,
        UFG::qList<UFG::qString,UFG::qString,1,0> *options,
        char **tooltips,
        unsigned int count)
{
  int mY; // r9d
  int mX; // edx
  float x; // xmm2_4
  int v11; // edi
  UFG::qList<UFG::qString,UFG::qString,1,0> *i; // rax
  int v13; // edi
  int v14; // r12d
  int v15; // r13d
  UFG::allocator::free_link *v16; // rax
  UFG::DUIComboBoxWindow *v17; // rax
  UFG::DUIComboBoxWindow *mComboBoxWindow; // rax
  UFG::DUIComboBoxWindow *v19; // rax
  UFG::DUIComboBoxWindow *v20; // rax
  UFG::qColour *v21; // r8
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // r9
  int v23; // eax
  int v25; // [rsp+30h] [rbp-51h]
  UFG::DUIRect v26; // [rsp+50h] [rbp-31h]
  UFG::DUIRect result; // [rsp+60h] [rbp-21h] BYREF
  UFG::DUIRect v28; // [rsp+70h] [rbp-11h] BYREF
  UFG::DUIRect rect; // [rsp+80h] [rbp-1h] BYREF
  bool v30; // [rsp+E0h] [rbp+5Fh]
  UFG::DUIContext::ClickableState click_state; // [rsp+E8h] [rbp+67h] BYREF
  int v32; // [rsp+F0h] [rbp+6Fh]
  char **tooltipsa; // [rsp+F8h] [rbp+77h]

  tooltipsa = tooltips;
  v32 = *current_index;
  UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  mY = this->mTheme.mButton_Text.mY;
  mX = this->mTheme.mButton_Text.mX;
  v26.mX = result.mX + mX;
  v26.mW = result.mW - 2 * mX;
  v26.mY = mY + result.mY;
  v26.mH = result.mH - 2 * mY;
  rect = v26;
  v28 = v26;
  x = this->mFontDimensions.x;
  v28.mX = (int)(float)((float)((float)v26.mW - x) + (float)(result.mX + mX));
  v28.mW = (int)x;
  v25 = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)result, 12)) + result.mY;
  v11 = 0;
  for ( i = (UFG::qList<UFG::qString,UFG::qString,1,0> *)options->mNode.mNext;
        i != options;
        i = (UFG::qList<UFG::qString,UFG::qString,1,0> *)i->mNode.mNext )
  {
    ++v11;
  }
  v13 = result.mH * v11 + 2;
  v14 = result.mX - 2;
  v15 = result.mW + 4;
  v30 = this->mActivePopupID == ++this->mCurrentPopupID;
  if ( UFG::DUIContext::Clickable(this, &click_state, &result, &result, ClickableFlags_ConsumeInput)
    && this->mActivePopupID == -1 )
  {
    this->mActivePopupID = this->mCurrentPopupID;
    v16 = UFG::qMalloc(0x160ui64, UFG::gGlobalNewName, 0i64);
    if ( v16 )
      UFG::DUIComboBoxWindow::DUIComboBoxWindow((UFG::DUIComboBoxWindow *)v16);
    else
      v17 = 0i64;
    this->mComboBoxWindow = v17;
    UFG::DUIComboBoxWindow::SetData(v17, *current_index, options, count, (const char **)tooltipsa);
    mComboBoxWindow = this->mComboBoxWindow;
    mComboBoxWindow->mRect.mX = v14;
    mComboBoxWindow->mRect.mY = v25;
    mComboBoxWindow->mRect.mW = v15;
    mComboBoxWindow->mRect.mH = v13;
    UFG::DUIManager::ShowWindow(this->mManager, this->mComboBoxWindow, this->mSurface, 1);
  }
  if ( v30 )
  {
    v19 = this->mComboBoxWindow;
    if ( v19->mHasDialogResult )
    {
      this->mActivePopupID = -1;
      *current_index = v19->mDialogResult;
      v20 = this->mComboBoxWindow;
      if ( !v20->mMarkedToDestroy )
        v20->mMarkedToDestroy = 1;
      this->mComboBoxWindow = 0i64;
    }
  }
  v21 = &this->mTheme.mColour[12];
  if ( click_state != Clickable_IsHot )
    v21 = &UFG::qColourBlack;
  UFG::DUIContext::RenderRect(this, &result, v21, 0);
  mNext = options->mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::qString,UFG::qString> *)options )
  {
    v23 = *current_index;
    if ( *current_index != -1 )
    {
      for ( ; v23 > 0; mNext = mNext->mNext )
      {
        if ( mNext == (UFG::qNode<UFG::qString,UFG::qString> *)options )
          break;
        --v23;
      }
      UFG::DUIContext::RenderText(this, &rect, &UFG::qColourWhite, (const char *)mNext[1].mNext, 0);
    }
  }
  UFG::DUIContext::RenderText(this, &v28, &UFG::qColourWhite, "V", 0);
  return *current_index != v32;
}

// File Line: 5198
// RVA: 0x19A400
char __fastcall UFG::DUIContext::MessageBox(
        UFG::DUIContext *this,
        unsigned int *response_value,
        const char *title,
        const char *message,
        const char **options)
{
  UFG::allocator::free_link *v9; // rax
  int mActiveMessageBoxID; // eax
  UFG::DUIMessageBoxWindow *mMessageBoxWindow; // rax
  UFG::DUIMessageBoxWindow *v12; // rcx

  ++this->mCurrentMessageBoxID;
  if ( this->mActiveMessageBoxID == -1 )
  {
    this->mActiveMessageBoxID = this->mCurrentMessageBoxID;
    v9 = UFG::qMalloc(0x178ui64, UFG::gGlobalNewName, 0i64);
    if ( v9 )
      UFG::DUIMessageBoxWindow::DUIMessageBoxWindow((UFG::DUIMessageBoxWindow *)v9);
    this->mMessageBoxWindow = (UFG::DUIMessageBoxWindow *)v9;
    UFG::DUIMessageBoxWindow::SetData((UFG::DUIMessageBoxWindow *)v9, title, message, options);
    this->mMessageBoxWindow->mRect.mX = this->mRect.mW / 2 - this->mMessageBoxWindow->mRect.mW / 2;
    this->mMessageBoxWindow->mRect.mY = this->mRect.mH / 2 - this->mMessageBoxWindow->mRect.mH / 2;
    this->mMessageBoxWindow->mRect.mH = 400;
    UFG::DUIManager::ShowWindow(this->mManager, this->mMessageBoxWindow, this->mSurface, 1);
  }
  mActiveMessageBoxID = this->mActiveMessageBoxID;
  if ( mActiveMessageBoxID == -1 )
    return 0;
  if ( mActiveMessageBoxID != this->mCurrentMessageBoxID )
    return 0;
  mMessageBoxWindow = this->mMessageBoxWindow;
  if ( !mMessageBoxWindow->mHasDialogResult )
    return 0;
  *response_value = mMessageBoxWindow->mDialogResult;
  --this->mCurrentMessageBoxID;
  this->mActiveMessageBoxID = -1;
  v12 = this->mMessageBoxWindow;
  if ( !v12->mMarkedToDestroy )
    v12->mMarkedToDestroy = 1;
  this->mMessageBoxWindow = 0i64;
  return 1;
}

// File Line: 5246
// RVA: 0x19DC40
void __fastcall UFG::DUIContext::ShowPopupMenu(
        UFG::DUIContext *this,
        UFG::qBaseNodeRB **point,
        const char **tags,
        UFG::CommandContext *context)
{
  unsigned __int64 v8; // rax
  UFG::qString *v9; // rax
  char *mData; // rcx
  char *v11; // rcx
  char **v12; // rax
  __int64 v13; // rcx
  char *v14; // rax
  UFG::qNode<UFG::Command,UFG::Command> *mPrev; // rcx
  UFG::qNode<UFG::Command,UFG::Command> *mNext; // rax
  UFG::PopupMenuCommand command; // [rsp+20h] [rbp-C8h] BYREF
  void *p_mData; // [rsp+138h] [rbp+50h]

  command.mChildTags.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)-2i64;
  command.mPrev = &command.UFG::qNode<UFG::Command,UFG::Command>;
  command.mNext = &command.UFG::qNode<UFG::Command,UFG::Command>;
  v8 = UFG::qStringHashUpper64(&customCaption, 0xFFFFFFFFFFFFFFFFui64);
  command.mBaseNode.mParent = &command.mBaseNode;
  command.mBaseNode.mChildren[0] = &command.mBaseNode;
  command.mBaseNode.mChildren[1] = &command.mBaseNode;
  command.mBaseNode.mNeighbours[0] = &command.mBaseNode;
  command.mBaseNode.mNeighbours[1] = &command.mBaseNode;
  command.mBaseNode.mUID = v8;
  UFG::qString::qString(&command.mName, &customCaption);
  UFG::qString::qString((UFG::qString *)&command.mName.mMagic, "popup_menu");
  *(_QWORD *)&command.mDisplayText.mMagic = &command.mDisplayText.mMagic;
  command.mDisplayText.mData = (char *)&command.mDisplayText.mMagic;
  UFG::qString::qString((UFG::qString *)&command.mDisplayText.mStringHash32);
  *(_QWORD *)&command.mUserType.mMagic = 0i64;
  command.vfptr = (UFG::CommandVtbl *)&UFG::PopupMenuCommand::`vftable;
  p_mData = &command.mUserType.mData;
  command.mUserType.mData = (char *)&command.mUserType.mData;
  *(_QWORD *)&command.mUserType.mStringHash32 = &command.mUserType.mData;
  LOBYTE(command.mManager) = 1;
  UFG::qString::Set((UFG::qString *)&command.mDisplayText.mStringHash32, "PopupMenuCommand");
  if ( tags && *tags )
  {
    do
    {
      v9 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      p_mData = v9;
      if ( v9 )
        UFG::qString::qString(v9, *tags++);
      mData = command.mUserType.mData;
      *((_QWORD *)command.mUserType.mData + 1) = v9;
      v9->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)mData;
      v9->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&command.mUserType.mData;
      command.mUserType.mData = (char *)v9;
    }
    while ( *tags );
  }
  UFG::DUIContext::ShowPopupMenu(this, point, &command, context);
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes((UFG::qList<UFG::qString,UFG::qString,1,0> *)&command.mUserType.mData);
  v11 = command.mUserType.mData;
  v12 = *(char ***)&command.mUserType.mStringHash32;
  *((_QWORD *)command.mUserType.mData + 1) = *(_QWORD *)&command.mUserType.mStringHash32;
  *v12 = v11;
  command.mUserType.mData = (char *)&command.mUserType.mData;
  *(_QWORD *)&command.mUserType.mStringHash32 = &command.mUserType.mData;
  command.vfptr = (UFG::CommandVtbl *)&UFG::Command::`vftable;
  UFG::qString::~qString((UFG::qString *)&command.mDisplayText.mStringHash32);
  p_mData = &command.mDisplayText.mMagic;
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes((UFG::qList<UFG::qString,UFG::qString,1,0> *)&command.mDisplayText.mMagic);
  v13 = *(_QWORD *)&command.mDisplayText.mMagic;
  v14 = command.mDisplayText.mData;
  *(_QWORD *)(*(_QWORD *)&command.mDisplayText.mMagic + 8i64) = command.mDisplayText.mData;
  *(_QWORD *)v14 = v13;
  *(_QWORD *)&command.mDisplayText.mMagic = &command.mDisplayText.mMagic;
  command.mDisplayText.mData = (char *)&command.mDisplayText.mMagic;
  UFG::qString::~qString((UFG::qString *)&command.mName.mMagic);
  UFG::qString::~qString(&command.mName);
  mPrev = command.mPrev;
  mNext = command.mNext;
  command.mPrev->mNext = command.mNext;
  mNext->mPrev = mPrev;
}

// File Line: 5252
// RVA: 0x19DAD0
void __fastcall UFG::DUIContext::ShowPopupMenu(
        UFG::DUIContext *this,
        UFG::qBaseNodeRB **point,
        UFG::PopupMenuCommand *command,
        UFG::CommandContext *context)
{
  UFG::allocator::free_link *v8; // rax
  UFG::qBaseNodeRB *v9; // rdi
  UFG::DUIWindow *v10; // rax
  UFG::DUIWindow *v11; // rsi
  unsigned int v12; // eax
  UFG::qBaseTreeRB *v13; // rax
  int *p_mCount; // rax
  UFG::allocator::free_link *v15; // rbx
  int v16; // eax

  v8 = UFG::qMalloc(0x178ui64, UFG::gGlobalNewName, 0i64);
  v9 = 0i64;
  if ( v8 )
  {
    UFG::DUIPopupMenuWindow::DUIPopupMenuWindow((UFG::DUIPopupMenuWindow *)v8, context, 1);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  UFG::CommandContext::AddContext<UFG::DUIPoint>(context, "DUIPopupMenuWindow.OriginalMouseCoords", point);
  v11->mRect.mX = *(_DWORD *)point;
  v11->mRect.mY = *((_DWORD *)point + 1);
  v12 = UFG::qStringHashUpper32("DUIPopupMenuWindow", -1);
  if ( v12
    && (v13 = UFG::qBaseTreeRB::Get(&context->mDictionary.mTree, v12)) != 0i64
    && (p_mCount = &v13[-1].mCount) != 0i64 )
  {
    *((_QWORD *)p_mCount + 5) = v11;
  }
  else
  {
    v15 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    if ( v15 )
    {
      v16 = UFG::qStringHashUpper32("DUIPopupMenuWindow", -1);
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
    UFG::qBaseTreeRB::Add(&context->mDictionary.mTree, v9);
  }
  command->vfptr->Execute(command, context);
  UFG::DUIManager::ShowWindow(this->mManager, v11, this->mSurface, 1);
}

// File Line: 5267
// RVA: 0x19D640
void __fastcall UFG::DUIContext::SetClipboardText(const char *text)
{
  __int64 v2; // rbx
  HGLOBAL v3; // rax
  void *v4; // rbp
  void *v5; // rdi

  if ( text && OpenClipboard(0i64) )
  {
    if ( EmptyClipboard() )
    {
      v2 = -1i64;
      do
        ++v2;
      while ( text[v2] );
      v3 = GlobalAlloc(2u, (unsigned int)(v2 + 1));
      v4 = v3;
      if ( v3 )
      {
        v5 = GlobalLock(v3);
        memmove(v5, text, (unsigned int)v2);
        *((_BYTE *)v5 + (unsigned int)v2) = 0;
        GlobalUnlock(v4);
        SetClipboardData(1u, v4);
      }
    }
    CloseClipboard();
  }
}

// File Line: 5300
// RVA: 0x198490
const char *__fastcall UFG::DUIContext::GetClipboardText()
{
  LPVOID v0; // rbx
  HANDLE ClipboardData; // rax
  void *v2; // rdi

  v0 = 0i64;
  if ( OpenClipboard(ghWnd) )
  {
    ClipboardData = GetClipboardData(1u);
    v2 = ClipboardData;
    if ( ClipboardData )
    {
      v0 = GlobalLock(ClipboardData);
      if ( v0 )
        GlobalUnlock(v2);
    }
    CloseClipboard();
  }
  return (const char *)v0;
}

// File Line: 5325
// RVA: 0x1958A0
__int64 __fastcall UFG::DUIContext::Collapsible(UFG::DUIContext *this, const char *name, bool *current_value)
{
  int mY; // r9d
  int mX; // r8d
  int v8; // r10d
  int v9; // edx
  int v10; // ecx
  bool v11; // r14
  int v12; // eax
  const char *v13; // rdx
  UFG::qColour *v14; // r8
  UFG::qColour *mColour; // r8
  unsigned __int8 v16; // bl
  UFG::DUIRect v18; // [rsp+28h] [rbp-19h] BYREF
  UFG::DUIRect result; // [rsp+38h] [rbp-9h] BYREF
  UFG::DUIRect rect; // [rsp+48h] [rbp+7h] BYREF
  UFG::qString v21; // [rsp+58h] [rbp+17h] BYREF
  UFG::DUIContext::ClickableState click_state; // [rsp+A8h] [rbp+67h] BYREF

  UFG::DUIContext::GetLayoutRect(this, (UFG::DUIRect *)&rect.mW, 0, 0);
  v18 = result;
  mY = this->mTheme.mButton_Inset.mY;
  mX = this->mTheme.mButton_Inset.mX;
  v8 = _mm_cvtsi128_si32((__m128i)result);
  v18.mX = v8 + mX;
  v18.mW = result.mW - 2 * mX;
  v18.mY = mY + result.mY;
  v18.mH = result.mH - 2 * mY;
  rect = v18;
  v18 = result;
  v9 = this->mTheme.mButton_Text.mY;
  v10 = this->mTheme.mButton_Text.mX;
  v18.mX = v8 + v10;
  v18.mW = result.mW - 2 * v10;
  v18.mY = v9 + result.mY;
  v18.mH = result.mH - 2 * v9;
  UFG::DUIContext::Clickable(this, &click_state, &result, &result, ClickableFlags_ConsumeInput);
  v11 = click_state == Clickable_IsHot;
  if ( click_state == Clickable_Clicked )
    *current_value = !*current_value;
  UFG::qString::qString(&v21);
  if ( *current_value )
  {
    v12 = UFG::qStringLength(name);
    v13 = "- ";
  }
  else
  {
    v12 = UFG::qStringLength(name);
    v13 = "+ ";
  }
  UFG::qString::Set(&v21, v13, 2, name, v12);
  v14 = &this->mTheme.mColour[12];
  if ( !v11 )
    v14 = &this->mTheme.mColour[11];
  UFG::DUIContext::RenderRoundRect(this, &rect, v14, 0);
  mColour = &this->mTheme.mColour[2];
  if ( !v11 )
    mColour = this->mTheme.mColour;
  UFG::DUIContext::RenderText(this, &v18, mColour, v21.mData, 0);
  v16 = *current_value;
  UFG::qString::~qString(&v21);
  return v16;
}

// File Line: 5363
// RVA: 0x19E320
_BOOL8 __fastcall UFG::DUIContext::Slider(UFG::DUIContext *this, const char *name, float *current_value, float min)
{
  float v7; // xmm7_4
  int mSlider_ValueBoxWidth; // r10d
  UFG::DUIRect v9; // xmm1
  int mY; // edx
  int mX; // ecx
  int v12; // r8d
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int grip_min_h; // esi
  float v18; // xmm0_4
  bool v19; // r10
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // r9
  int v21; // r8d
  int mPrev; // ecx
  int v23; // edx
  int mPrev_high; // ecx
  bool v25; // al
  UFG::qColour *v26; // rsi
  bool v27; // bl
  UFG::DUIRect result; // [rsp+68h] [rbp-80h] BYREF
  UFG::DUIRect rect_track; // [rsp+78h] [rbp-70h] BYREF
  UFG::DUIRect rect; // [rsp+88h] [rbp-60h] BYREF
  UFG::DUIRect v32; // [rsp+98h] [rbp-50h] BYREF
  UFG::qString v33; // [rsp+A8h] [rbp-40h] BYREF
  long double value_x; // [rsp+118h] [rbp+30h] BYREF
  void *retaddr; // [rsp+128h] [rbp+40h] BYREF
  float v36; // [rsp+138h] [rbp+50h]
  float v37; // [rsp+140h] [rbp+58h]

  *(_QWORD *)&result.mW = -2i64;
  v7 = *current_value;
  UFG::DUIContext::GetLayoutRect(this, (UFG::DUIRect *)&rect_track.mW, 0, 0);
  mSlider_ValueBoxWidth = this->mTheme.mSlider_ValueBoxWidth;
  result.mW = -2 - (mSlider_ValueBoxWidth + this->mTheme.mSlider_TrackValueGap);
  v9 = result;
  mY = this->mTheme.mSlider_Inset.mY;
  mX = this->mTheme.mSlider_Inset.mX;
  v12 = _mm_cvtsi128_si32((__m128i)result);
  result.mX = v12 + mX;
  result.mW -= 2 * mX;
  result.mY += mY;
  result.mH = -1 - 2 * mY;
  rect = result;
  result = v9;
  v13 = this->mTheme.mSlider_Text.mY;
  v14 = this->mTheme.mSlider_Text.mX;
  result.mX = v12 + v14;
  result.mW = v9.mW - 2 * v14;
  result.mY = v13 + v9.mY;
  result.mH = v9.mH - 2 * v13;
  v32 = result;
  result = v9;
  v15 = this->mTheme.mSlider_Track.mY;
  v16 = this->mTheme.mSlider_Track.mX;
  result.mX = v12 + v16;
  result.mW = v9.mW - 2 * v16;
  result.mY = v15 + v9.mY;
  grip_min_h = v9.mH - 2 * v15;
  result.mH = grip_min_h;
  rect_track = result;
  result = v9;
  result.mW = mSlider_ValueBoxWidth;
  result.mX = -2 - mSlider_ValueBoxWidth + v9.mX;
  UFG::DUIContext::NumericTextBox(this, &result, current_value, 0);
  v18 = *current_value;
  if ( *current_value <= min )
    v18 = min;
  if ( v18 >= v36 )
    v18 = v36;
  *current_value = v18;
  value_x = v18;
  retaddr = 0i64;
  v19 = UFG::DUIContext::Draggable2D(
          this,
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
          this->mTheme.mSliderSize,
          grip_min_h,
          0);
  v25 = 0;
  if ( !this->mInputState.mMouseLBIsDown && !this->mInputState.mMouseRBIsDown && !this->mInputState.mMouseMBIsDown )
  {
    mNext = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
    v21 = this->mInputState.mMousePos.mX;
    mPrev = (int)mNext[1].mPrev;
    if ( v21 >= mPrev && v21 <= LODWORD(mNext[1].mNext) + mPrev )
    {
      v23 = this->mInputState.mMousePos.mY;
      mPrev_high = HIDWORD(mNext[1].mPrev);
      if ( v23 >= mPrev_high
        && v23 <= HIDWORD(mNext[1].mNext) + mPrev_high - 1
        && v21 >= result.mX
        && v21 <= result.mW + result.mX
        && v23 >= result.mY
        && v23 <= result.mH + result.mY - 1
        && !this->mInputState.mMouseEventHandled )
      {
        v25 = 1;
      }
    }
  }
  if ( v19 )
    *current_value = value_x;
  if ( v25 || (v26 = &this->mTheme.mColour[19], v19) )
    v26 = &this->mTheme.mColour[20];
  UFG::qString::qString(&v33);
  UFG::qString::Format(&v33, "%.3f", *current_value);
  UFG::DUIContext::RenderRoundRect(this, &rect, &this->mTheme.mColour[18], 0);
  UFG::DUIContext::RenderRoundRect(this, &result, v26, 0);
  UFG::DUIContext::RenderText(this, &v32, this->mTheme.mColour, name, 0x41u);
  v27 = v7 != *current_value;
  UFG::qString::~qString(&v33);
  return v27;
}, &v32, this->mTheme.mColour, name, 0x41u);
  v27 = v7 != *current_value;
  UFG::qString::~qString(&v33);
  

// File Line: 5408
// RVA: 0x19E000
_BOOL8 __fastcall UFG::DUIContext::Slider(
        UFG::DUIContext *this,
        const char *name,
        unsigned int *current_value,
        int min)
{
  unsigned int v8; // r12d
  int mSlider_TrackValueGap; // r11d
  int mSlider_ValueBoxWidth; // r10d
  int mW; // r9d
  UFG::DUIRect v12; // xmm1
  int mY; // edx
  int mX; // ecx
  int v15; // r8d
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // ebx
  int v21; // ecx
  int v22; // eax
  int mSliderSize; // eax
  bool v24; // r10
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // r9
  int v26; // r8d
  int mPrev; // ecx
  int v28; // edx
  int mPrev_high; // ecx
  bool v30; // cl
  UFG::qColour *v31; // rbx
  bool v32; // bl
  UFG::DUIRect result; // [rsp+58h] [rbp-49h] BYREF
  UFG::DUIRect rect_track; // [rsp+68h] [rbp-39h] BYREF
  UFG::DUIRect rect; // [rsp+78h] [rbp-29h] BYREF
  UFG::DUIRect v37; // [rsp+88h] [rbp-19h] BYREF
  UFG::qString v38; // [rsp+98h] [rbp-9h] BYREF
  long double value_x[2]; // [rsp+F8h] [rbp+57h] BYREF
  long double value_y; // [rsp+108h] [rbp+67h] BYREF
  void *retaddr; // [rsp+118h] [rbp+77h]
  float v42; // [rsp+120h] [rbp+7Fh]

  v8 = *current_value;
  UFG::DUIContext::GetLayoutRect(this, (UFG::DUIRect *)&rect.mW, 0, 0);
  mSlider_TrackValueGap = this->mTheme.mSlider_TrackValueGap;
  mSlider_ValueBoxWidth = this->mTheme.mSlider_ValueBoxWidth;
  result.mW -= mSlider_ValueBoxWidth + mSlider_TrackValueGap;
  mW = result.mW;
  v12 = result;
  mY = this->mTheme.mSlider_Inset.mY;
  mX = this->mTheme.mSlider_Inset.mX;
  v15 = _mm_cvtsi128_si32((__m128i)result);
  result.mX = v15 + mX;
  result.mW -= 2 * mX;
  result.mY += mY;
  result.mH -= 2 * mY;
  rect = result;
  result = v12;
  v16 = this->mTheme.mSlider_Text.mY;
  v17 = this->mTheme.mSlider_Text.mX;
  result.mX = v15 + v17;
  result.mW = v12.mW - 2 * v17;
  result.mY = v16 + v12.mY;
  result.mH = v12.mH - 2 * v16;
  v37 = result;
  result = v12;
  v18 = this->mTheme.mSlider_Track.mY;
  v19 = this->mTheme.mSlider_Track.mX;
  result.mX = v15 + v19;
  result.mW = v12.mW - 2 * v19;
  result.mY = v18 + v12.mY;
  v20 = v12.mH - 2 * v18;
  result.mH = v20;
  rect_track = result;
  result = v12;
  result.mW = mSlider_ValueBoxWidth;
  result.mX = mSlider_TrackValueGap + mW + v12.mX;
  UFG::DUIContext::NumericTextBox(this, &result, current_value, 0);
  v21 = min;
  if ( (int)*current_value > min )
    v21 = *current_value;
  v22 = (int)retaddr;
  if ( v21 < (int)retaddr )
    v22 = v21;
  *current_value = v22;
  value_x[0] = (double)v22;
  mSliderSize = this->mTheme.mSliderSize;
  value_y = 0.0;
  v24 = UFG::DUIContext::Draggable2D(
          this,
          value_x,
          &value_y,
          &result,
          &rect_track,
          (double)min,
          0.0,
          (double)(int)retaddr,
          0.0,
          v42,
          1.0,
          mSliderSize,
          v20,
          1);
  v30 = 0;
  if ( !this->mInputState.mMouseLBIsDown && !this->mInputState.mMouseRBIsDown && !this->mInputState.mMouseMBIsDown )
  {
    mNext = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
    v26 = this->mInputState.mMousePos.mX;
    mPrev = (int)mNext[1].mPrev;
    if ( v26 >= mPrev && v26 <= LODWORD(mNext[1].mNext) + mPrev )
    {
      v28 = this->mInputState.mMousePos.mY;
      mPrev_high = HIDWORD(mNext[1].mPrev);
      if ( v28 >= mPrev_high
        && v28 <= HIDWORD(mNext[1].mNext) + mPrev_high - 1
        && v26 >= result.mX
        && v26 <= result.mW + result.mX
        && v28 >= result.mY
        && v28 <= result.mH + result.mY - 1
        && !this->mInputState.mMouseEventHandled )
      {
        v30 = 1;
      }
    }
  }
  if ( v24 )
    *current_value = (int)value_x[0];
  if ( v30 || (v31 = &this->mTheme.mColour[19], v24) )
    v31 = &this->mTheme.mColour[20];
  UFG::qString::qString(&v38);
  UFG::qString::Format(&v38, "%d", *current_value);
  UFG::DUIContext::RenderRoundRect(this, &rect, &this->mTheme.mColour[18], 0);
  UFG::DUIContext::RenderRoundRect(this, &result, v31, 0);
  UFG::DUIContext::RenderText(this, &v37, this->mTheme.mColour, name, 0x41u);
  v32 = *current_value != v8;
  UFG::qString::~qString(&v38);
  return v32;
}

// File Line: 5449
// RVA: 0x195A50
bool __fastcall UFG::DUIContext::ColourBarSlider(
        UFG::DUIContext *this,
        const char *name,
        float *current_value,
        __m128i *rect,
        UFG::qColour *colour_insetL,
        UFG::qColour *colour_insetR)
{
  int mSlider_TrackValueGap; // r10d
  __m128i v7; // xmm0
  int mSlider_ValueBoxWidth; // r9d
  float v12; // xmm6_4
  int mY; // edx
  int v15; // r8d
  int v16; // r11d
  int mH; // eax
  int mX; // ecx
  UFG::DUIRect v19; // xmm0
  int v20; // ecx
  int v21; // edx
  UFG::DUIRect v22; // xmm0
  int grip_min_h; // r14d
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  float v27; // xmm1_4
  float v28; // xmm0_4
  bool v29; // r10
  int v30; // r9d
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // rdx
  int mPrev; // ecx
  int v33; // r8d
  int mPrev_high; // ecx
  bool v35; // al
  UFG::qColour *mColour; // rbx
  int grip_min_w; // [rsp+58h] [rbp-41h]
  UFG::DUIRect rect_val; // [rsp+70h] [rbp-29h] BYREF
  UFG::DUIRect recta; // [rsp+80h] [rbp-19h] BYREF
  UFG::DUIRect rect_track; // [rsp+90h] [rbp-9h] BYREF
  UFG::DUIRect v42; // [rsp+A0h] [rbp+7h] BYREF
  long double value_x; // [rsp+F0h] [rbp+57h] BYREF
  long double value_y; // [rsp+100h] [rbp+67h] BYREF

  mSlider_TrackValueGap = this->mTheme.mSlider_TrackValueGap;
  v7 = *rect;
  mSlider_ValueBoxWidth = this->mTheme.mSlider_ValueBoxWidth;
  v12 = *current_value;
  mY = this->mTheme.mColourPicker_Text.mY;
  v15 = this->mTheme.mColourPicker_Track.mY;
  rect_val = (UFG::DUIRect)v7;
  v16 = this->mTheme.mColourPicker_Inset.mW + v7.m128i_i32[2];
  rect_val.mX = this->mTheme.mColourPicker_Inset.mX + _mm_cvtsi128_si32(v7);
  rect_val.mY = this->mTheme.mColourPicker_Inset.mY + v7.m128i_i32[1];
  mH = this->mTheme.mColourPicker_Inset.mH;
  mX = this->mTheme.mColourPicker_Text.mX;
  rect_val.mH = mH + v7.m128i_i32[3];
  rect_val.mW = v16;
  recta = rect_val;
  recta.mW = v16 - mSlider_ValueBoxWidth - mSlider_TrackValueGap;
  rect_val = (UFG::DUIRect)*rect;
  v19 = rect_val;
  rect_val.mY += mY;
  rect_val.mX = mX + _mm_cvtsi128_si32((__m128i)v19);
  rect_val.mW -= 2 * mX;
  v20 = rect_val.mH - 2 * mY;
  v21 = this->mTheme.mColourPicker_Track.mX;
  rect_val.mH = v20;
  v22 = rect_val;
  *(_QWORD *)&rect_val.mW = *(_QWORD *)&recta.mW;
  rect_val.mY = v15 + recta.mY;
  v42 = v22;
  rect_val.mX = v21 + _mm_cvtsi128_si32((__m128i)recta);
  grip_min_h = recta.mH - 2 * v15;
  v24 = rect->m128i_i32[1];
  rect_val.mW = recta.mW - 2 * v21;
  v25 = rect->m128i_i32[0];
  rect_val.mH = grip_min_h;
  rect_track = rect_val;
  rect_val.mY = v24;
  rect_val.mW = rect->m128i_i32[2];
  v26 = rect->m128i_i32[3];
  rect_val.mW = mSlider_ValueBoxWidth;
  rect_val.mH = v26;
  rect_val.mX = v16 - mSlider_ValueBoxWidth + v25;
  UFG::DUIContext::NumericTextBox(this, &rect_val, current_value, 0);
  v27 = *current_value;
  if ( *current_value <= 0.0 )
  {
    v27 = 0.0;
  }
  else
  {
    v28 = *(float *)&FLOAT_1_0;
    if ( v27 >= 1.0 )
      goto LABEL_6;
  }
  v28 = v27;
LABEL_6:
  *current_value = v28;
  grip_min_w = this->mTheme.mSliderSize;
  value_x = v28;
  value_y = 0.0;
  v29 = UFG::DUIContext::Draggable2D(
          this,
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
  v35 = 0;
  if ( !this->mInputState.mMouseLBIsDown && !this->mInputState.mMouseRBIsDown && !this->mInputState.mMouseMBIsDown )
  {
    v30 = this->mInputState.mMousePos.mX;
    mNext = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
    mPrev = (int)mNext[1].mPrev;
    if ( v30 >= mPrev && v30 <= LODWORD(mNext[1].mNext) + mPrev )
    {
      v33 = this->mInputState.mMousePos.mY;
      mPrev_high = HIDWORD(mNext[1].mPrev);
      if ( v33 >= mPrev_high
        && v33 <= HIDWORD(mNext[1].mNext) + mPrev_high - 1
        && v30 >= rect_val.mX
        && v30 <= rect_val.mW + rect_val.mX
        && v33 >= rect_val.mY
        && v33 <= rect_val.mH + rect_val.mY - 1
        && !this->mInputState.mMouseEventHandled )
      {
        v35 = 1;
      }
    }
  }
  if ( v29 )
    *current_value = value_x;
  if ( v35 || (mColour = this->mTheme.mColour, v29) )
    mColour = &this->mTheme.mColour[20];
  UFG::DUIContext::RenderRoundRect(this, &recta, colour_insetL, colour_insetR, 0);
  UFG::DUIContext::RenderRoundRect(this, &rect_val, mColour, 0);
  UFG::DUIContext::RenderText(this, &v42, this->mTheme.mColour, name, 0x41u);
  return v12 != *current_value;
}

// File Line: 5563
// RVA: 0x195D60
bool __fastcall UFG::DUIContext::ColourBarSliderHSV(
        UFG::DUIContext *this,
        UFG::DUIContext::HSVComponent component,
        UFG::qColour *colour,
        __m128i *rect)
{
  UFG::DUIContext::HSVComponent v6; // r14d
  UFG::qColour *p_g; // r12
  float r; // xmm7_4
  float v10; // xmm6_4
  int mSlider_ValueBoxWidth; // r8d
  int mY; // edx
  __m128i v13; // xmm0
  int mSlider_TrackValueGap; // r9d
  int v15; // r13d
  int v16; // eax
  int mH; // eax
  int mX; // ecx
  int v19; // r13d
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  UFG::DUIRect v24; // xmm0
  int grip_min_h; // esi
  int v26; // eax
  int v27; // ecx
  __int128 v28; // xmm0
  int v29; // eax
  int v30; // eax
  float v31; // xmm0_4
  bool v32; // r10
  int v33; // r9d
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *mNext; // rdx
  int mPrev; // ecx
  int v36; // r8d
  int mPrev_high; // ecx
  bool v38; // al
  float v39; // xmm0_4
  float g; // xmm1_4
  float b; // xmm1_4
  float v42; // xmm0_4
  UFG::qColour *p_colourL; // r8
  int v44; // esi
  __int64 v45; // r15
  UFG::qColour *v46; // rbx
  const char *v47; // r9
  int grip_min_w; // [rsp+58h] [rbp-A0h]
  _BYTE rect_val[24]; // [rsp+70h] [rbp-88h] BYREF
  UFG::DUIRect recta; // [rsp+88h] [rbp-70h] BYREF
  UFG::DUIRect rect_grip; // [rsp+98h] [rbp-60h] BYREF
  UFG::DUIRect v53; // [rsp+A8h] [rbp-50h] BYREF
  UFG::qColour colourL; // [rsp+B8h] [rbp-40h] BYREF
  UFG::qColour v55; // [rsp+C8h] [rbp-30h]
  UFG::qColour v56; // [rsp+D8h] [rbp-20h]
  UFG::qColour v57; // [rsp+E8h] [rbp-10h]
  UFG::qColour v58; // [rsp+F8h] [rbp+0h]
  UFG::qColour v59; // [rsp+108h] [rbp+10h]
  UFG::qColour v60; // [rsp+118h] [rbp+20h]
  UFG::qColour *mColour; // [rsp+198h] [rbp+A0h] BYREF
  UFG::DUIContext::HSVComponent v62; // [rsp+1A0h] [rbp+A8h]
  int v63; // [rsp+1A8h] [rbp+B0h]
  long double value_y; // [rsp+1B0h] [rbp+B8h] BYREF

  v6 = component;
  p_g = colour;
  if ( component == HSVComponent_Sat )
  {
    p_g = (UFG::qColour *)&colour->g;
  }
  else if ( component == HSVComponent_Val )
  {
    p_g = (UFG::qColour *)&colour->b;
  }
  r = p_g->r;
  v10 = *(float *)&FLOAT_1_0;
  if ( component == HSVComponent_Hue )
    v10 = FLOAT_360_0;
  mSlider_ValueBoxWidth = this->mTheme.mSlider_ValueBoxWidth;
  mY = this->mTheme.mColourPicker_Text.mY;
  v13 = *rect;
  mSlider_TrackValueGap = this->mTheme.mSlider_TrackValueGap;
  *(__m128i *)rect_val = v13;
  v15 = this->mTheme.mColourPicker_Inset.mW + v13.m128i_i32[2];
  *(_DWORD *)rect_val = this->mTheme.mColourPicker_Inset.mX + _mm_cvtsi128_si32(v13);
  v16 = this->mTheme.mColourPicker_Inset.mY;
  *(_DWORD *)&rect_val[8] = v15;
  *(_DWORD *)&rect_val[4] = v16 + v13.m128i_i32[1];
  mH = this->mTheme.mColourPicker_Inset.mH;
  mX = this->mTheme.mColourPicker_Text.mX;
  *(_DWORD *)&rect_val[12] = mH + v13.m128i_i32[3];
  v19 = v15 - mSlider_ValueBoxWidth - mSlider_TrackValueGap;
  recta = *(UFG::DUIRect *)rect_val;
  recta.mW = v19;
  *(__m128i *)rect_val = *rect;
  v20 = _mm_cvtsi128_si32(*(__m128i *)rect_val);
  *(_DWORD *)&rect_val[4] += mY;
  *(_DWORD *)rect_val = mX + v20;
  *(_DWORD *)&rect_val[8] -= 2 * mX;
  v21 = *(_DWORD *)&rect_val[12] - 2 * mY;
  v22 = this->mTheme.mColourPicker_Track.mY;
  *(_DWORD *)&rect_val[12] = v21;
  v23 = this->mTheme.mColourPicker_Track.mX;
  v63 = _mm_cvtsi128_si32((__m128i)recta);
  v24 = *(UFG::DUIRect *)rect_val;
  *(_QWORD *)&rect_val[8] = *(_QWORD *)&recta.mW;
  *(_DWORD *)&rect_val[4] = v22 + recta.mY;
  v53 = v24;
  *(_DWORD *)rect_val = v23 + v63;
  grip_min_h = recta.mH - 2 * v22;
  v26 = rect->m128i_i32[1];
  *(_DWORD *)&rect_val[8] = v19 - 2 * v23;
  v27 = rect->m128i_i32[0];
  *(_DWORD *)&rect_val[12] = grip_min_h;
  v28 = *(_OWORD *)rect_val;
  *(_DWORD *)&rect_val[4] = v26;
  v29 = rect->m128i_i32[2];
  *(_OWORD *)&rect_val[8] = v28;
  *(float *)&mColour = r;
  *(_DWORD *)&rect_val[8] = v29;
  v30 = rect->m128i_i32[3];
  *(_DWORD *)&rect_val[8] = mSlider_ValueBoxWidth;
  *(_DWORD *)&rect_val[12] = v30;
  *(_DWORD *)rect_val = mSlider_TrackValueGap + v19 + v27;
  if ( v6 )
    *(float *)&mColour = r * 100.0;
  UFG::DUIContext::NumericTextBox(this, (UFG::DUIRect *)rect_val, (float *)&mColour, 0);
  v31 = *(float *)&mColour;
  if ( v6 )
    v31 = *(float *)&mColour * 0.0099999998;
  p_g->r = v31;
  if ( v31 <= 0.0 )
    v31 = 0.0;
  if ( v31 >= v10 )
    v31 = v10;
  p_g->r = v31;
  grip_min_w = this->mTheme.mSliderSize;
  *(double *)&mColour = v31;
  value_y = 0.0;
  v32 = UFG::DUIContext::Draggable2D(
          this,
          (long double *)&mColour,
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
  v38 = 0;
  if ( !this->mInputState.mMouseLBIsDown && !this->mInputState.mMouseRBIsDown && !this->mInputState.mMouseMBIsDown )
  {
    v33 = this->mInputState.mMousePos.mX;
    mNext = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
    mPrev = (int)mNext[1].mPrev;
    if ( v33 >= mPrev && v33 <= LODWORD(mNext[1].mNext) + mPrev )
    {
      v36 = this->mInputState.mMousePos.mY;
      mPrev_high = HIDWORD(mNext[1].mPrev);
      if ( v36 >= mPrev_high
        && v36 <= HIDWORD(mNext[1].mNext) + mPrev_high - 1
        && v33 >= rect_grip.mX
        && v33 <= rect_grip.mW + rect_grip.mX
        && v36 >= rect_grip.mY
        && v36 <= rect_grip.mH + rect_grip.mY - 1
        && !this->mInputState.mMouseEventHandled )
      {
        v38 = 1;
      }
    }
  }
  if ( v32 )
    p_g->r = *(double *)&mColour;
  if ( v38 || v32 )
    mColour = &this->mTheme.mColour[20];
  else
    mColour = this->mTheme.mColour;
  v55 = UFG::qColour::Yellow;
  v56 = UFG::qColour::Green;
  colourL = UFG::qColour::Red;
  v57 = UFG::qColour::Cyan;
  v58 = UFG::qColour::Blue;
  v60 = UFG::qColour::Red;
  v59 = UFG::qColour::Magenta;
  if ( v6 )
  {
    if ( v6 == HSVComponent_Sat )
    {
      b = colour->b;
      v42 = colour->r;
      *(_DWORD *)&rect_val[20] = 1065353216;
      *(_DWORD *)&rect_val[4] = 1065353216;
      *(float *)&rect_val[16] = b;
      *(_DWORD *)&rect_val[12] = 1065353216;
      *(float *)rect_val = v42;
      *(float *)&rect_val[8] = b;
      UFG::qColourHSVToRGB((UFG::qColour *)rect_val, (UFG::qColour *)rect_val);
      UFG::DUIContext::RenderRoundRect(this, &recta, (UFG::qColour *)&rect_val[8], (UFG::qColour *)rect_val, 0);
    }
    else if ( v6 == HSVComponent_Val )
    {
      v39 = colour->r;
      g = colour->g;
      *(_DWORD *)&rect_val[8] = 1065353216;
      *(_DWORD *)&rect_val[12] = 1065353216;
      *(float *)rect_val = v39;
      *(float *)&rect_val[4] = g;
      UFG::qColourHSVToRGB((UFG::qColour *)rect_val, (UFG::qColour *)rect_val);
      *(UFG::qColour *)&rect_val[8] = UFG::qColour::Black;
      UFG::DUIContext::RenderRoundRect(this, &recta, (UFG::qColour *)&rect_val[8], (UFG::qColour *)rect_val, 0);
    }
  }
  else
  {
    *(_DWORD *)&rect_val[12] = recta.mY;
    p_colourL = &colourL;
    *(_DWORD *)&rect_val[20] = recta.mH;
    v44 = 0;
    v45 = 6i64;
    *(_DWORD *)&rect_val[16] = v19 / 6;
    do
    {
      v46 = p_colourL + 1;
      *(_DWORD *)&rect_val[8] = v63 + v44 / 6;
      UFG::DUIContext::RenderRoundRect(this, (UFG::DUIRect *)&rect_val[8], p_colourL, p_colourL + 1, 0);
      v44 += v19;
      p_colourL = v46;
      --v45;
    }
    while ( v45 );
    v6 = v62;
  }
  UFG::DUIContext::RenderRoundRect(this, &rect_grip, mColour, 0);
  if ( v6 == HSVComponent_Sat )
  {
    v47 = "S";
  }
  else
  {
    v47 = "V";
    if ( v6 != HSVComponent_Val )
      v47 = "H";
  }
  UFG::DUIContext::RenderText(this, &v53, this->mTheme.mColour, v47, 0x41u);
  return r != p_g->r;
}

// File Line: 5666
// RVA: 0x196340
_BOOL8 __fastcall UFG::DUIContext::ColourPicker(
        UFG::DUIContext *this,
        const char *name,
        UFG::qColour *current_colour_rgb,
        bool edit_alpha)
{
  float r; // xmm11_4
  float g; // xmm10_4
  float b; // xmm9_4
  float a; // xmm8_4
  int mColourPicker_Height; // r9d
  UFG::DUIRect *LayoutRect; // rax
  int mX; // ebx
  int mY; // r9d
  int mW; // ecx
  int mH; // r8d
  int v18; // edx
  int v19; // ebx
  int v20; // r11d
  int mColourPicker_SwatchW; // r9d
  __int64 v22; // r8
  int v23; // r12d
  UFG::DUIRect v24; // xmm7
  int v25; // edx
  int v26; // ecx
  int v27; // r14d
  int v28; // r11d
  float v29; // xmm6_4
  __m128 b_low; // xmm3
  float v31; // xmm4_4
  int v32; // ecx
  __m128 g_low; // xmm1
  int v34; // ecx
  __m128 r_low; // xmm2
  int v36; // ecx
  bool v37; // al
  bool v38; // al
  char *mData; // rcx
  __int64 v40; // rdx
  __int64 v41; // r9
  int v42; // ebx
  int v43; // esi
  int v44; // eax
  float v45; // xmm0_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  bool v48; // bl
  UFG::qColour *colour_insetL; // [rsp+20h] [rbp-E0h]
  UFG::DUIRect rect; // [rsp+40h] [rbp-C0h] BYREF
  UFG::DUIRect current_rect; // [rsp+50h] [rbp-B0h] BYREF
  char dest[16]; // [rsp+60h] [rbp-A0h] BYREF
  UFG::DUIRect v54; // [rsp+70h] [rbp-90h] BYREF
  UFG::qColour hsv; // [rsp+80h] [rbp-80h] BYREF
  UFG::DUIRect v56; // [rsp+90h] [rbp-70h] BYREF
  UFG::DUIRect v57; // [rsp+A0h] [rbp-60h] BYREF
  UFG::DUIRect result; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v59; // [rsp+C0h] [rbp-40h]
  UFG::qString str_val; // [rsp+C8h] [rbp-38h] BYREF
  char text; // [rsp+190h] [rbp+90h] BYREF
  char v62; // [rsp+191h] [rbp+91h]
  char v63; // [rsp+192h] [rbp+92h]
  char v64; // [rsp+193h] [rbp+93h]
  char v65; // [rsp+198h] [rbp+98h] BYREF
  char v66; // [rsp+199h] [rbp+99h]
  char v67; // [rsp+19Ah] [rbp+9Ah]
  char v68; // [rsp+19Bh] [rbp+9Bh]
  bool evaluate; // [rsp+1A8h] [rbp+A8h] BYREF
  char v70; // [rsp+1A9h] [rbp+A9h]
  char v71; // [rsp+1AAh] [rbp+AAh]
  char v72; // [rsp+1ABh] [rbp+ABh]

  v59 = -2i64;
  UFG::qColourRGBToHSV(&hsv, current_colour_rgb);
  r = current_colour_rgb->r;
  g = current_colour_rgb->g;
  b = current_colour_rgb->b;
  a = current_colour_rgb->a;
  if ( name && *name )
    UFG::DUIContext::Label(this, name);
  mColourPicker_Height = this->mTheme.mColourPicker_Height;
  if ( !edit_alpha )
    mColourPicker_Height += 3 * this->mTheme.mClientInset.mY / 4 - (mColourPicker_Height >> 2);
  LayoutRect = UFG::DUIContext::GetLayoutRect(this, &result, 0, mColourPicker_Height);
  mX = LayoutRect->mX;
  mY = LayoutRect->mY;
  mW = LayoutRect->mW;
  mH = LayoutRect->mH;
  v18 = this->mTheme.mClientInset.mY;
  LODWORD(LayoutRect) = this->mTheme.mClientInset.mX;
  v19 = (_DWORD)LayoutRect + mX;
  rect.mX = v19;
  v20 = mW - 2 * (_DWORD)LayoutRect;
  rect.mW = v20;
  rect.mY = v18 + mY;
  rect.mH = mH - 2 * v18;
  mColourPicker_SwatchW = this->mTheme.mColourPicker_SwatchW;
  current_rect.mX = v19 + v20 - mColourPicker_SwatchW;
  current_rect.mY = rect.mY;
  current_rect.mW = mColourPicker_SwatchW;
  v22 = HIDWORD(*(_QWORD *)&rect.mW);
  v23 = rect.mH - 16;
  current_rect.mH = rect.mH - 16;
  v24 = current_rect;
  rect = current_rect;
  v25 = this->mTheme.mColourPicker_SwatchBorder.mY;
  v26 = this->mTheme.mColourPicker_SwatchBorder.mX;
  rect.mX = v26 + current_rect.mX;
  rect.mW = mColourPicker_SwatchW - 2 * v26;
  rect.mY = v25 + current_rect.mY;
  rect.mH = current_rect.mH - 2 * v25;
  result = rect;
  v27 = 0;
  v28 = v20 - this->mTheme.mControlInset.mX - mColourPicker_SwatchW;
  rect.mX = v19;
  rect.mY = current_rect.mY;
  rect.mW = v28;
  rect.mH = (int)v22 / (edit_alpha + 3);
  v56.mX = v19;
  v56.mY = current_rect.mY + rect.mH;
  v56.mW = v28;
  v56.mH = rect.mH;
  v57.mX = v19;
  v57.mY = current_rect.mY + 2 * rect.mH;
  v57.mW = v28;
  v57.mH = rect.mH;
  v54.mX = v19;
  v54.mY = rect.mH + v57.mY;
  v54.mW = v28;
  v54.mH = rect.mH;
  UFG::DUIContext::ColourBarSliderHSV(this, HSVComponent_Hue, &hsv, (__m128i *)&rect);
  UFG::DUIContext::ColourBarSliderHSV(this, HSVComponent_Sat, &hsv, (__m128i *)&v56);
  UFG::DUIContext::ColourBarSliderHSV(this, HSVComponent_Val, &hsv, (__m128i *)&v57);
  if ( edit_alpha )
    UFG::DUIContext::ColourBarSlider(this, "A", &hsv.a, (__m128i *)&v54, &UFG::qColour::Black, &UFG::qColour::White);
  UFG::qColourHSVToRGB(current_colour_rgb, &hsv);
  UFG::DUIContext::RenderRoundRect(this, &current_rect, &this->mTheme.mColourPicker_SwatchBorderColour, 0);
  v54.mX = LODWORD(current_colour_rgb->r);
  v54.mY = LODWORD(current_colour_rgb->g);
  v54.mW = LODWORD(current_colour_rgb->b);
  v29 = *(float *)&FLOAT_1_0;
  v54.mH = 1065353216;
  UFG::DUIContext::RenderRoundRect(this, &result, (UFG::qColour *)&v54, 0);
  current_rect = v24;
  current_rect.mY = v23 + v24.mY;
  current_rect.mH = 16;
  b_low = (__m128)LODWORD(current_colour_rgb->b);
  v31 = FLOAT_255_0;
  if ( b_low.m128_f32[0] < 1.0 )
  {
    b_low.m128_f32[0] = b_low.m128_f32[0] * 256.0;
    v32 = (int)b_low.m128_f32[0];
    if ( (int)b_low.m128_f32[0] != 0x80000000 && (float)v32 != b_low.m128_f32[0] )
      b_low.m128_f32[0] = (float)(v32 - (_mm_movemask_ps(_mm_unpacklo_ps(b_low, b_low)) & 1));
  }
  else
  {
    b_low.m128_f32[0] = FLOAT_255_0;
  }
  g_low = (__m128)LODWORD(current_colour_rgb->g);
  if ( g_low.m128_f32[0] < 1.0 )
  {
    g_low.m128_f32[0] = g_low.m128_f32[0] * 256.0;
    v34 = (int)g_low.m128_f32[0];
    if ( (int)g_low.m128_f32[0] != 0x80000000 && (float)v34 != g_low.m128_f32[0] )
      g_low.m128_f32[0] = (float)(v34 - (_mm_movemask_ps(_mm_unpacklo_ps(g_low, g_low)) & 1));
  }
  else
  {
    g_low.m128_f32[0] = FLOAT_255_0;
  }
  r_low = (__m128)LODWORD(current_colour_rgb->r);
  if ( r_low.m128_f32[0] < 1.0 )
  {
    r_low.m128_f32[0] = r_low.m128_f32[0] * 256.0;
    v36 = (int)r_low.m128_f32[0];
    if ( (int)r_low.m128_f32[0] != 0x80000000 && (float)v36 != r_low.m128_f32[0] )
      r_low.m128_f32[0] = (float)(v36 - (_mm_movemask_ps(_mm_unpacklo_ps(r_low, r_low)) & 1));
    v31 = r_low.m128_f32[0];
  }
  LODWORD(colour_insetL) = (unsigned __int8)(int)b_low.m128_f32[0];
  UFG::qSPrintf(dest, "%02x%02x%02x", (unsigned __int8)(int)v31, (unsigned __int8)(int)g_low.m128_f32[0], colour_insetL);
  UFG::qString::qString(&str_val, dest);
  v37 = UFG::DUIContext::TakeFocus(this, &current_rect, &current_rect, 1);
  evaluate = 0;
  v38 = UFG::DUIContext::InternalTextControl(this, &current_rect, &str_val, v37, 0, &evaluate, 0i64);
  if ( evaluate )
  {
    this->mCaretPos = 0;
    this->mHighlightStart = str_val.mLength;
  }
  if ( this->mFocusedID == this->mCurrentID )
    this->mCaretPos = 0;
  if ( v38 )
  {
    mData = str_val.mData;
    v40 = 0i64;
    if ( *str_val.mData )
    {
      v41 = 0x7E0000007E03FFi64;
      do
      {
        if ( v40 >= 15 )
          break;
        if ( (unsigned __int8)(*mData - 48) <= 0x36u && _bittest64(&v41, (char)(*mData - 48)) )
        {
          dest[v40] = *mData;
          ++v27;
          ++v40;
        }
        ++mData;
      }
      while ( *mData );
    }
    dest[v27] = 0;
    evaluate = 35;
    v70 = dest[0];
    v71 = dest[1];
    v72 = 0;
    v42 = UFG::qToUInt32((const char *)&evaluate, 0);
    text = 35;
    v62 = dest[2];
    v63 = dest[3];
    v64 = 0;
    v43 = UFG::qToUInt32(&text, 0);
    v65 = 35;
    v66 = dest[4];
    v67 = dest[5];
    v68 = 0;
    v44 = UFG::qToUInt32(&v65, 0);
    v45 = (float)v42 * 0.0039215689;
    if ( v45 <= 0.0 )
    {
      v45 = 0.0;
    }
    else if ( v45 >= 1.0 )
    {
      v45 = *(float *)&FLOAT_1_0;
    }
    current_colour_rgb->r = v45;
    v46 = (float)v43 * 0.0039215689;
    if ( v46 <= 0.0 )
    {
      v46 = 0.0;
    }
    else if ( v46 >= 1.0 )
    {
      v46 = *(float *)&FLOAT_1_0;
    }
    current_colour_rgb->g = v46;
    v47 = (float)v44 * 0.0039215689;
    if ( v47 <= 0.0 )
    {
      v47 = 0.0;
    }
    else if ( v47 >= 1.0 )
    {
      goto LABEL_48;
    }
    v29 = v47;
LABEL_48:
    current_colour_rgb->b = v29;
  }
  v48 = r != current_colour_rgb->r
     || g != current_colour_rgb->g
     || b != current_colour_rgb->b
     || a != current_colour_rgb->a;
  UFG::qString::~qString(&str_val);
  return v48;
}

// File Line: 5769
// RVA: 0x194D40
UFG::DUIContext *__fastcall UFG::DUIContext::BeginScrollView(
        UFG::DUIContext *this,
        UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *current_scroll_pos)
{
  UFG::allocator::free_link *v4; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v5; // rdx
  int mH; // ecx
  int mW; // r8d
  int mY; // r9d
  int mX; // r10d
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mNext; // rax
  int v11; // r15d
  int v12; // ebp
  int v13; // r12d
  int v14; // r13d
  int v15; // r15d
  int v16; // r12d
  UFG::allocator::free_link *v17; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v18; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v19; // rax
  UFG::DUIRect scissor_rect; // [rsp+28h] [rbp-40h] BYREF
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v22; // [rsp+70h] [rbp+8h]

  UFG::DUIContext::GetLayoutRect(this, &scissor_rect, 0, 0);
  v4 = UFG::qMalloc(0xB8ui64, "DUILayoutState", 0x800ui64);
  v5 = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v4;
  mH = scissor_rect.mH;
  mW = scissor_rect.mW;
  mY = scissor_rect.mY;
  mX = scissor_rect.mX;
  if ( v4 )
  {
    v4->mNext = v4;
    v4[1].mNext = v4;
    LODWORD(v4[2].mNext) = mX;
    HIDWORD(v4[2].mNext) = mY;
    LODWORD(v4[3].mNext) = mW;
    HIDWORD(v4[3].mNext) = mH;
    LODWORD(v4[4].mNext) = mX;
    HIDWORD(v4[4].mNext) = mY;
    LODWORD(v4[5].mNext) = mW;
    HIDWORD(v4[5].mNext) = mH;
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
  mNext = this->mLayoutStack.mNode.mNext;
  this->mLayoutStack.mNode.mNext = v5;
  v5->mPrev = &this->mLayoutStack.mNode;
  v5->mNext = mNext;
  mNext->mPrev = v5;
  v11 = this->mTheme.mClientInset.mX;
  v12 = v11 + mX;
  scissor_rect.mX = v11 + mX;
  v13 = this->mTheme.mClientInset.mY;
  v14 = v13 + mY;
  scissor_rect.mY = v13 + mY;
  v15 = mW + -2 * v11 - this->mTheme.mScrollbarW;
  scissor_rect.mW = v15;
  v16 = mH + -2 * v13 - this->mTheme.mScrollbarH;
  scissor_rect.mH = v16;
  v17 = UFG::qMalloc(0xB8ui64, "DUILayoutState", 0x800ui64);
  v18 = (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)v17;
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
  v19 = this->mLayoutStack.mNode.mNext;
  this->mLayoutStack.mNode.mNext = v18;
  v18->mPrev = &this->mLayoutStack.mNode;
  v18->mNext = v19;
  v19->mPrev = v18;
  UFG::DUIContext::PushScissor(this, &scissor_rect);
  LODWORD(v22) = -LODWORD(current_scroll_pos->mPrev);
  HIDWORD(v22) = -HIDWORD(current_scroll_pos->mPrev);
  this->mLayoutStack.mNode.mNext[9].mNext = v22;
  this->mLayoutStack.mNode.mNext[7].mPrev = current_scroll_pos;
  return this;
}is->mLayoutStack.mNode.mNext[9].mNext = v22;
  this->mLayoutStack.mN

// File Line: 5790
// RVA: 0x197E00
UFG::DUIContext *__fastcall UFG::DUIContext::EndScrollView(UFG::DUIContext *this)
{
  UFG::DUILayoutState *mNext; // rbx
  int *mScrollViewPosition; // r14
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *mPrev; // rdx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v5; // rax
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v6; // r10
  int mX; // r9d
  int v8; // ecx
  int mScrollbarW; // r8d
  int mScrollbarH; // edx
  int v11; // r12d
  int mNext_high; // ebx
  int v13; // r15d
  int mY; // ecx
  int mH; // rdi^4
  int visible; // r12d
  int v17; // eax
  int max; // r9d
  int v19; // edi
  int v20; // r13d
  int v21; // edx
  int v22; // ecx
  int v23; // ebp
  int v24; // ecx
  int v25; // edx
  bool v26; // al
  bool v27; // zf
  int v28; // r9d
  UFG::qNode<UFG::qValueNode<UFG::DUIRect>,UFG::qValueNode<UFG::DUIRect> > *v29; // rdx
  int v30; // ecx
  int v31; // r8d
  int mPrev_high; // ecx
  int mMouseWheelDelta; // eax
  int v34; // eax
  UFG::DUIRect rect; // [rsp+40h] [rbp-48h] BYREF
  UFG::DUIRect v37; // [rsp+50h] [rbp-38h] BYREF

  mNext = (UFG::DUILayoutState *)this->mLayoutStack.mNode.mNext;
  mScrollViewPosition = (int *)mNext->mScrollViewPosition;
  mPrev = mNext->mPrev;
  v5 = mNext->mNext;
  mPrev->mNext = v5;
  v5->mPrev = mPrev;
  mNext->mPrev = mNext;
  mNext->mNext = mNext;
  if ( mNext->mClip )
    UFG::DUIContext::PopScissor(this);
  if ( (UFG::qList<UFG::DUILayoutState,UFG::DUILayoutState,1,0> *)this->mLayoutStack.mNode.mNext != &this->mLayoutStack
    && this->mCurrentCompositeLayer != CompositeLayer_Overlay )
  {
    UFG::DUIRect::Merge((UFG::DUIRect *)&this->mLayoutStack.mNode.mNext[3], &mNext->mMaximumRect);
  }
  UFG::DUILayoutState::~DUILayoutState(mNext);
  operator delete[](mNext);
  v6 = this->mLayoutStack.mNode.mNext;
  mX = this->mTheme.mClientInset.mX;
  v8 = (int)v6[2].mPrev;
  mScrollbarW = this->mTheme.mScrollbarW;
  mScrollbarH = this->mTheme.mScrollbarH;
  v11 = (int)v6[2].mNext;
  mNext_high = HIDWORD(v6[3].mNext);
  rect.mY = HIDWORD(v6[2].mPrev);
  v13 = mX + v8;
  rect.mH = HIDWORD(v6[2].mNext);
  rect.mX = v8;
  mY = this->mTheme.mClientInset.mY;
  rect.mW = v11;
  mH = rect.mH;
  rect.mH = mScrollbarH;
  visible = v11 - 2 * mX - mScrollbarW;
  v17 = mX + visible;
  max = (int)v6[3].mNext;
  v19 = mH - 2 * mY - mScrollbarH;
  v20 = mY + rect.mY;
  v37.mW = mScrollbarW;
  v21 = max - visible;
  v37.mX = v13 + v17;
  if ( max - visible < 0 )
    v21 = 0;
  v22 = 0;
  rect.mY = v19 + v20;
  if ( *mScrollViewPosition > 0 )
    v22 = *mScrollViewPosition;
  v37.mY = v20;
  v37.mH = v19;
  rect.mX = v13;
  if ( v22 < v21 )
    v21 = v22;
  v23 = mNext_high - v19;
  v24 = 0;
  *mScrollViewPosition = v21;
  v25 = mNext_high - v19;
  if ( mNext_high - v19 < 0 )
    v25 = 0;
  if ( mScrollViewPosition[1] > 0 )
    v24 = mScrollViewPosition[1];
  rect.mW = visible;
  if ( v24 < v25 )
    v25 = v24;
  mScrollViewPosition[1] = v25;
  this->mIsScrollViewDragging = UFG::DUIContext::Scrollbar(
                                  this,
                                  &rect,
                                  mScrollViewPosition,
                                  0,
                                  max,
                                  visible,
                                  Orient_Horizontal);
  v26 = UFG::DUIContext::Scrollbar(this, &v37, mScrollViewPosition + 1, 0, mNext_high, v19, Orient_Vertical);
  v27 = this->mFocusedID == -1;
  this->mIsScrollViewDragging = v26;
  if ( v27 )
  {
    v28 = this->mInputState.mMousePos.mX;
    v29 = this->mScissorStacks[this->mCurrentCompositeLayer].mNode.mNext;
    v30 = (int)v29[1].mPrev;
    if ( v28 >= v30 && v28 <= LODWORD(v29[1].mNext) + v30 )
    {
      v31 = this->mInputState.mMousePos.mY;
      mPrev_high = HIDWORD(v29[1].mPrev);
      if ( v31 >= mPrev_high
        && v31 <= HIDWORD(v29[1].mNext) + mPrev_high - 1
        && v28 >= v13
        && v28 <= visible + v13
        && v31 >= v20
        && v31 <= rect.mY - 1
        && !this->mInputState.mMouseEventHandled )
      {
        mMouseWheelDelta = this->mInputState.mMouseWheelDelta;
        if ( mMouseWheelDelta )
        {
          mScrollViewPosition[1] -= mMouseWheelDelta;
          if ( v23 < 0 )
            v23 = 0;
          v34 = 0;
          if ( mScrollViewPosition[1] > 0 )
            v34 = mScrollViewPosition[1];
          if ( v34 < v23 )
            v23 = v34;
          mScrollViewPosition[1] = v23;
          this->mInputState.mMouseWheelDelta = 0;
        }
      }
    }
  }
  UFG::DUIContext::PopLayoutState(this);
  return this;
}

// File Line: 5848
// RVA: 0x195100
UFG::DUIContext *__fastcall UFG::DUIContext::BeginVerticalLayout(UFG::DUIContext *this)
{
  UFG::DUIRect *LayoutRect; // rax
  UFG::DUILayoutState *v3; // rax
  UFG::DUIRect result; // [rsp+20h] [rbp-18h] BYREF

  LayoutRect = UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v3 = UFG::DUIContext::PushLayoutState(this, LayoutRect, LayoutFlag_FillLastCol);
  *(_QWORD *)&v3->mNumCols = 1i64;
  v3->mColWidths = 0i64;
  v3->mRowHeights = 0i64;
  return this;
}

// File Line: 5860
// RVA: 0x194C00
UFG::DUIContext *__fastcall UFG::DUIContext::BeginLayoutHorizontal(UFG::DUIContext *this)
{
  UFG::DUIContext::BeginGridLayout(this, 0, 1, 0i64, 0i64, LayoutFlag_None);
  return this;
}

// File Line: 5872
// RVA: 0x194650
UFG::DUIContext *__fastcall UFG::DUIContext::BeginGridLayout(
        UFG::DUIContext *this,
        int num_cols,
        int num_rows,
        UFG::DUI::LayoutFlag flags)
{
  UFG::DUIRect *LayoutRect; // rax
  UFG::DUILayoutState *v9; // rax
  UFG::DUIRect result; // [rsp+20h] [rbp-18h] BYREF

  LayoutRect = UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v9 = UFG::DUIContext::PushLayoutState(this, LayoutRect, flags);
  v9->mNumRows = num_rows;
  v9->mNumCols = num_cols;
  v9->mColWidths = 0i64;
  v9->mRowHeights = 0i64;
  return this;
}

// File Line: 5878
// RVA: 0x1946C0
UFG::DUIContext *__fastcall UFG::DUIContext::BeginGridLayout(
        UFG::DUIContext *this,
        int num_cols,
        int num_rows,
        int *column_widths,
        int *row_heights,
        UFG::DUI::LayoutFlag layout_flags)
{
  __int64 v6; // r14
  int *v7; // r15
  int v8; // edi
  UFG::DUIRect *LayoutRect; // rax
  char v11; // r12
  UFG::DUILayoutState *v12; // rax
  int *v13; // r13
  __int64 v14; // rsi
  UFG::DUILayoutState *v15; // rcx
  int v16; // r12d
  __int64 v17; // rdi
  int v18; // r13d
  __int64 v19; // rsi
  int mLayout_SplitterWidth; // edx
  int v21; // r14d
  int v22; // edx
  int v23; // ecx
  int v24; // eax
  int v25; // r14d
  int v26; // eax
  int v27; // r12d
  __int64 v28; // rdi
  __int64 v29; // r15
  int grip_min_h; // r8d
  int v31; // ecx
  __m128i v32; // xmm0
  int *mNext; // rcx
  int grip_min_w; // edx
  int v35; // eax
  int v36; // edx
  int v37; // ecx
  int v38; // eax
  char v39; // dl
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v40; // rcx
  int mPrev_high; // r12d
  int mPrev; // edi
  int v43; // eax
  __int64 v44; // r14
  int v45; // r13d
  int mX; // r9d
  __int64 v47; // rax
  UFG::DUIContextVtbl *v48; // rdx
  int UpdateUI; // ecx
  int mY; // r8d
  int UpdateUI_high; // ecx
  UFG::qColour *v52; // rcx
  UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *v53; // rax
  int v54; // r12d
  int v55; // r14d
  int v56; // edi
  int v57; // eax
  UFG::DUI::LayoutFlag v58; // r15d
  int v59; // r9d
  __int64 v60; // rax
  UFG::DUIContextVtbl *v61; // rdx
  int v62; // ecx
  int v63; // r8d
  int v64; // ecx
  UFG::qColour *v65; // rcx
  int v66; // eax
  UFG::DUIContext *v67; // rax
  int v68; // [rsp+70h] [rbp-69h]
  int v69; // [rsp+70h] [rbp-69h]
  UFG::DUILayoutState *v70; // [rsp+78h] [rbp-61h]
  long double value_y; // [rsp+80h] [rbp-59h] BYREF
  long double value_x; // [rsp+88h] [rbp-51h] BYREF
  UFG::DUIRect rect; // [rsp+90h] [rbp-49h] BYREF
  UFG::DUIRect rect_grip; // [rsp+A0h] [rbp-39h] BYREF
  UFG::DUIRect result; // [rsp+B0h] [rbp-29h] BYREF
  int xy; // [rsp+130h] [rbp+57h] BYREF
  int count; // [rsp+138h] [rbp+5Fh]
  int v78; // [rsp+140h] [rbp+67h]
  int *v79; // [rsp+148h] [rbp+6Fh]

  v79 = column_widths;
  v78 = num_rows;
  count = num_cols;
  v6 = num_cols;
  v7 = column_widths;
  v8 = num_rows;
  LayoutRect = UFG::DUIContext::GetLayoutRect(this, &result, 0, 0);
  v11 = layout_flags;
  v12 = UFG::DUIContext::PushLayoutState(this, LayoutRect, layout_flags);
  v13 = row_heights;
  v14 = 0i64;
  v15 = v12;
  v70 = v12;
  v68 = v11 & 8;
  if ( (v11 & 8) != 0 )
  {
    if ( (int)v6 > 1 && v7 )
    {
      v16 = 0;
      v17 = 0i64;
      v18 = 0;
      v19 = v6;
      do
      {
        mLayout_SplitterWidth = this->mTheme.mLayout_SplitterWidth;
        v21 = v16 + v7[v17];
        xy = v21;
        UFG::DUIContext::GridSplitter(this, mLayout_SplitterWidth, &xy, Orient_Vertical);
        v22 = xy;
        v23 = xy - v16;
        if ( this->mTheme.mLayout_SplitterWidth + 1 > xy - v16 )
          v23 = this->mTheme.mLayout_SplitterWidth + 1;
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
      v11 = layout_flags;
    }
    if ( v78 > 1 && v13 )
    {
      v25 = 0;
      v26 = v78;
      if ( (v11 & 2) != 0 )
        v26 = v78 - 1;
      v27 = 0;
      v28 = 0i64;
      if ( v26 > 0 )
      {
        v29 = v26;
        do
        {
          grip_min_h = this->mTheme.mLayout_SplitterWidth;
          v31 = v13[v28];
          value_x = 0.0;
          xy = v25 + v31;
          *(_QWORD *)&rect_grip.mX = 0i64;
          v32 = _mm_cvtsi32_si128(v25 + v31);
          mNext = (int *)this->mLayoutStack.mNode.mNext;
          *(_QWORD *)&rect_grip.mW = 0i64;
          *(_QWORD *)&value_y = *(_OWORD *)&_mm_cvtepi32_pd(v32);
          grip_min_w = mNext[6];
          rect.mX = mNext[4];
          rect.mY = mNext[5];
          v35 = mNext[7];
          rect.mW = grip_min_w;
          rect.mH = v35;
          if ( UFG::DUIContext::Draggable2D(
                 this,
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
            this->mInputState.mMouseWheelDelta = 0;
            *(_QWORD *)&this->mInputState.mMouseLBWentDown = 0i64;
            *(_WORD *)&this->mInputState.mLMBDoubleClick = 0;
            this->mInputState.mMouseMBWentUp = 0;
            this->mInputState.mMMBDoubleClick = 0;
            this->mInputState.mMouseEventHandled = 1;
          }
          v36 = (int)value_y;
          v37 = (int)value_y - v25;
          if ( this->mTheme.mLayout_SplitterWidth + this->mTheme.mRowHeight > v37 )
            v37 = this->mTheme.mLayout_SplitterWidth + this->mTheme.mRowHeight;
          v38 = v78 - 1;
          v13[v28] = v37;
          if ( v27 < v38 )
            v13[v28 + 1] += xy - v36;
          ++v28;
          v25 += v37;
          ++v27;
        }
        while ( v28 < v29 );
        v7 = v79;
      }
    }
    v15 = v70;
    v8 = v78;
  }
  if ( (layout_flags & 4) != 0 )
  {
    if ( v7 )
      UFG::RedistributeGridLines(v7, count, v15->mWorkingRect.mW);
    if ( v13 )
      UFG::RedistributeGridLines(v13, v8, v70->mWorkingRect.mH);
  }
  if ( v68 )
  {
    v39 = layout_flags;
    if ( v7 )
    {
      v40 = this->mLayoutStack.mNode.mNext;
      mPrev_high = HIDWORD(v40[1].mPrev);
      mPrev = (int)v40[1].mPrev;
      rect.mW = (int)v40[1].mNext;
      xy = HIDWORD(v40[1].mNext);
      rect.mH = xy;
      v69 = this->mTheme.mLayout_SplitterWidth;
      rect.mW = v69;
      rect.mY = mPrev_high;
      v43 = count;
      if ( (layout_flags & 1) != 0 )
        v43 = count - 1;
      v44 = 0i64;
      *(_QWORD *)&value_x = v43;
      if ( v43 > 0 )
      {
        v45 = xy;
        do
        {
          mPrev += v7[v44];
          mX = this->mInputState.mMousePos.mX;
          v47 = (int)this->mCurrentCompositeLayer + 54i64;
          rect.mX = mPrev;
          v48 = (&this->vfptr)[2 * v47];
          UpdateUI = (int)v48[2].UpdateUI;
          if ( mX < UpdateUI
            || mX > LODWORD(v48[3].UpdateUI) + UpdateUI
            || (mY = this->mInputState.mMousePos.mY, UpdateUI_high = HIDWORD(v48[2].UpdateUI), mY < UpdateUI_high)
            || mY > HIDWORD(v48[3].UpdateUI) + UpdateUI_high - 1
            || mX < mPrev
            || mX > mPrev + v69
            || mY < mPrev_high
            || mY > mPrev_high + v45 - 1
            || (v52 = &this->mTheme.mColour[12], this->mInputState.mMouseEventHandled) )
          {
            v52 = &this->mTheme.mColour[17];
          }
          rect_grip = (UFG::DUIRect)*v52;
          UFG::DUIContext::RenderRect(this, &rect, (UFG::qColour *)&rect_grip, 0);
          ++v44;
        }
        while ( v44 < *(__int64 *)&value_x );
        v13 = row_heights;
        v39 = layout_flags;
        v14 = 0i64;
      }
    }
    if ( v13 )
    {
      v53 = this->mLayoutStack.mNode.mNext;
      v54 = this->mTheme.mLayout_SplitterWidth;
      v55 = (int)v53[1].mPrev;
      v56 = HIDWORD(v53[1].mPrev);
      layout_flags = (UFG::DUI::LayoutFlag)v53[1].mNext;
      rect.mW = layout_flags;
      rect.mX = v55;
      rect.mH = v54;
      v57 = v78;
      if ( (v39 & 2) != 0 )
        v57 = v78 - 1;
      row_heights = (int *)v57;
      if ( v57 > 0 )
      {
        v58 = layout_flags;
        do
        {
          v56 += v13[v14];
          v59 = this->mInputState.mMousePos.mX;
          v60 = (int)this->mCurrentCompositeLayer + 54i64;
          rect.mY = v56;
          v61 = (&this->vfptr)[2 * v60];
          v62 = (int)v61[2].UpdateUI;
          if ( v59 < v62
            || v59 > LODWORD(v61[3].UpdateUI) + v62
            || (v63 = this->mInputState.mMousePos.mY, v64 = HIDWORD(v61[2].UpdateUI), v63 < v64)
            || v63 > HIDWORD(v61[3].UpdateUI) + v64 - 1
            || v59 < v55
            || v59 > v58 + v55
            || v63 < v56
            || v63 > v56 + v54 - 1
            || (v65 = &this->mTheme.mColour[12], this->mInputState.mMouseEventHandled) )
          {
            v65 = &this->mTheme.mColour[17];
          }
          rect_grip = (UFG::DUIRect)*v65;
          UFG::DUIContext::RenderRect(this, &rect, (UFG::qColour *)&rect_grip, 0);
          ++v14;
        }
        while ( v14 < (__int64)row_heights );
        v7 = v79;
      }
    }
  }
  v70->mNumCols = count;
  v66 = v78;
  v70->mColWidths = v7;
  v70->mNumRows = v66;
  v67 = this;
  v70->mRowHeights = v13;
  return v67;
}

// File Line: 6012
// RVA: 0x198190
UFG::DUIContext *__fastcall UFG::DUIContext::EndLayoutHorizontal(UFG::DUIContext *this)
{
  UFG::DUIContext::PopLayoutState(this);
  return this;
}

// File Line: 6051
// RVA: 0x193B60
void __fastcall UFG::DUIContext::AdjustWindowsToScreen(UFG::DUIContext *this, UFG::DUIRect *prevRect)
{
  UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> *mNext; // rsi
  int mW; // kr00_4
  UFG::qNode<UFG::qValueNode<UFG::qColour>,UFG::qValueNode<UFG::qColour> > **p_mNext; // r13
  UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> **v7; // rsi
  __int64 mH; // kr08_8
  char *v9; // rdx
  int *v10; // rdi
  int v11; // r14d
  int v12; // edx
  int v13; // r8d
  bool v14; // al
  UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> **v15; // rcx
  int v16; // r12d
  int v17; // r8d
  int v18; // ebx
  int v19; // edx
  int v20; // r8d
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  int v25; // ecx
  UFG::DUIRect rect; // [rsp+20h] [rbp-78h] BYREF
  UFG::DUIRect v27; // [rsp+30h] [rbp-68h] BYREF
  UFG::DUIRect v28; // [rsp+40h] [rbp-58h] BYREF
  UFG::DUIRect v29; // [rsp+50h] [rbp-48h] BYREF
  int v30; // [rsp+A0h] [rbp+8h]
  int v31; // [rsp+A8h] [rbp+10h]

  mNext = this->mWindowFrontStack.mNode.mNext;
  mW = prevRect->mW;
  *(_QWORD *)&rect.mX = 0i64;
  p_mNext = &this->mThemeColourModifier[17].mNode.mNext;
  v7 = &mNext[-7].mNext;
  mH = prevRect->mH;
  rect.mW = mW / 2;
  rect.mH = ((int)mH - HIDWORD(mH)) >> 1;
  v27 = rect;
  v28 = rect;
  v27.mY = rect.mH;
  v28.mX = mW / 2;
  v29 = v27;
  v29.mX = mW / 2;
  if ( v7 != (UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> **)&this->mThemeColourModifier[17].mNode.mNext
    || (v7 = &this->mWindowStack.mNode.mNext[-7].mNext,
        v7 != (UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> **)&this->mThemeColourModifier[16].mNode.mNext) )
  {
    if ( v7 )
    {
      do
      {
        if ( *((_BYTE *)v7 + 152) )
        {
          v9 = *((_DWORD *)v7 + 46) ? (char *)v7[22] : &customCaption;
          if ( !v9 || !*v9 || UFG::DUIManager::GetGroupData(this->mManager, v9) )
          {
            v10 = (int *)(v7 + 17);
            v11 = *((_DWORD *)v7 + 34);
            if ( v11 || *((_DWORD *)v7 + 36) != prevRect->mW )
            {
              v16 = *((_DWORD *)v7 + 35);
              if ( v16 || *((_DWORD *)v7 + 37) != prevRect->mH )
              {
                v18 = UFG::DUIRect::OverlappedArea((UFG::DUIRect *)(v7 + 17), &rect);
                v31 = UFG::DUIRect::OverlappedArea((UFG::DUIRect *)(v7 + 17), &v28);
                v30 = UFG::DUIRect::OverlappedArea((UFG::DUIRect *)(v7 + 17), &v29);
                v19 = UFG::DUIRect::OverlappedArea((UFG::DUIRect *)(v7 + 17), &v27);
                v20 = v19;
                if ( v30 > v19 )
                  v19 = v30;
                v21 = v31;
                if ( v18 > v31 )
                  v21 = v18;
                if ( v21 > v19 )
                  v19 = v21;
                if ( v19 != v18 )
                {
                  if ( v19 == v31 )
                  {
                    v22 = v11 - prevRect->mW + this->mRect.mW;
                    *v10 = v22;
                    if ( this->mRect.mW - *((_DWORD *)v7 + 36) < v22 )
                      v22 = this->mRect.mW - *((_DWORD *)v7 + 36);
                    *v10 = v22;
                  }
                  else if ( v19 == v30 )
                  {
                    v23 = v11 - prevRect->mW + this->mRect.mW;
                    *v10 = v23;
                    if ( this->mRect.mW - *((_DWORD *)v7 + 36) < v23 )
                      v23 = this->mRect.mW - *((_DWORD *)v7 + 36);
                    *v10 = v23;
                    *((_DWORD *)v7 + 35) += this->mRect.mH - prevRect->mH;
                    v24 = *((_DWORD *)v7 + 35);
                    if ( this->mRect.mH - *((_DWORD *)v7 + 37) < v24 )
                      v24 = this->mRect.mH - *((_DWORD *)v7 + 37);
                    *((_DWORD *)v7 + 35) = v24;
                  }
                  else if ( v19 == v20 )
                  {
                    v25 = v16 - prevRect->mH + this->mRect.mH;
                    *((_DWORD *)v7 + 35) = v25;
                    if ( this->mRect.mH - *((_DWORD *)v7 + 37) < v25 )
                      v25 = this->mRect.mH - *((_DWORD *)v7 + 37);
                    *((_DWORD *)v7 + 35) = v25;
                  }
                }
              }
              else
              {
                *((_DWORD *)v7 + 37) = this->mRect.mH;
                v17 = prevRect->mW;
                if ( v11 + *((_DWORD *)v7 + 36) == v17 )
                  *v10 = v11 + this->mRect.mW - v17;
              }
            }
            else
            {
              v12 = *((_DWORD *)v7 + 35);
              *((_DWORD *)v7 + 36) = this->mRect.mW;
              v13 = prevRect->mH;
              if ( v12 + *((_DWORD *)v7 + 37) == v13 )
                *((_DWORD *)v7 + 35) = v12 + this->mRect.mH - v13;
            }
          }
        }
        v14 = 0;
        v15 = &this->mWindowFrontStack.mNode.mNext[-7].mNext;
        if ( v15 == (UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> **)p_mNext )
        {
LABEL_18:
          v15 = &this->mWindowStack.mNode.mNext[-7].mNext;
          if ( v15 == (UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> **)&this->mThemeColourModifier[16].mNode.mNext )
            return;
          while ( !v14 )
          {
            v14 = v7 == v15;
            v15 = &v15[14][-7].mNext;
            if ( v15 == (UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> **)&this->mThemeColourModifier[16].mNode.mNext )
              return;
          }
        }
        else
        {
          while ( !v14 )
          {
            v14 = v7 == v15;
            v15 = &v15[14][-7].mNext;
            if ( v15 == (UFG::qNode<UFG::DUIWindow,UFG::DUIWindow> **)p_mNext )
              goto LABEL_18;
          }
        }
        v7 = v15;
      }
      while ( v15 );
    }
  }
}

// File Line: 6137
// RVA: 0x19DA30
void __fastcall UFG::DUIContext::SetOverallRect(UFG::DUIContext *this, UFG::DUIRect *rect)
{
  UFG::DUIRect prevRect; // [rsp+20h] [rbp-18h] BYREF

  if ( this->mRect.mW != rect->mW || this->mRect.mH != rect->mH )
  {
    prevRect = this->mRect;
    this->mRect = *rect;
    *(_QWORD *)&this->mRect.mX = 0i64;
    UFG::DUIContext::AdjustWindowsToScreen(this, &prevRect);
  }
}

