// File Line: 16
// RVA: 0x146C6B0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::Terminal_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::Terminal", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::sDeserializeOp,
    v0,
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::Editor::Terminal>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 44
// RVA: 0x146D750
__int64 dynamic_initializer_for__UFG::Editor::Terminal::sTerminals__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Editor::Terminal::sTerminals__);
}

// File Line: 55
// RVA: 0x202C30
void __fastcall UFG::Editor::Terminal::Terminal(UFG::Editor::Terminal *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::Terminal", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qSafePointerNode<UFG::Editor::Terminal>::qSafePointerNode<UFG::Editor::Terminal>(&this->UFG::qSafePointerNode<UFG::Editor::Terminal>);
  this->UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Terminal::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Terminal::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qSafePointerNode<UFG::Editor::Terminal>::vfptr = (UFG::qSafePointerNode<UFG::Editor::Terminal>Vtbl *)&UFG::Editor::Terminal::`vftable;
  *(_WORD *)&this->mFollowTail = 1;
  *(_QWORD *)&this->mChannel = 3i64;
  this->mScrollPos.mY = 0;
  `eh vector constructor iterator(
    this->mLines,
    0x30ui64,
    512,
    (void (__fastcall *)(void *))UFG::PersistentData::String::String);
  *(_QWORD *)&this->mEOL = 0i64;
  UFG::Editor::Terminal::Initialize(this);
}

// File Line: 61
// RVA: 0x20D830
void __fastcall UFG::Editor::Terminal::Initialize(UFG::Editor::Terminal *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::allocator::free_link *v3; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v6; // rax
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v7; // rcx
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v8; // rax
  __int64 *v9; // rcx
  _QWORD *p_mPrev; // rax
  __int64 *v11; // rcx
  _QWORD *v12; // rax
  __int64 *v13; // [rsp+28h] [rbp-38h] BYREF
  UFG::qList<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // [rsp+30h] [rbp-30h]
  UFG::Editor::Terminal *v15; // [rsp+38h] [rbp-28h]
  UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> v16; // [rsp+40h] [rbp-20h] BYREF

  UFG::qString::Set(&this->mTitle, "Terminal");
  UFG::qAddPrintHandler(
    (UFG::allocator::free_link *)UFG::Editor::Terminal::PrintHandlerBridge,
    (UFG::allocator::free_link *)this);
  v13 = (__int64 *)&v13;
  p_m_SafePointerList = (UFG::qList<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList,1,0> *)&v13;
  v15 = this;
  if ( this )
  {
    mPrev = this->UFG::qSafePointerNode<UFG::Editor::Terminal>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Editor::Terminal>::mPrev;
    mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v13;
    v13 = (__int64 *)mPrev;
    p_m_SafePointerList = &this->UFG::qSafePointerNode<UFG::Editor::Terminal>::m_SafePointerList;
    this->UFG::qSafePointerNode<UFG::Editor::Terminal>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Editor::Terminal>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v13;
  }
  v3 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  if ( v3 )
  {
    v16.mPrev = &v16;
    v16.mNext = &v16;
    v16.m_pPointer = v15;
    if ( v15 )
    {
      p_mNode = &v15->UFG::qSafePointerNode<UFG::Editor::Terminal>::m_SafePointerList.mNode;
      v5 = v15->UFG::qSafePointerNode<UFG::Editor::Terminal>::m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Editor::Terminal>::mPrev;
      v5->mNext = &v16;
      v16.mPrev = v5;
      v16.mNext = p_mNode;
      p_mNode->mPrev = &v16;
    }
    UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal>>::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal>>(
      (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v3,
      &v16);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = UFG::Editor::Terminal::sTerminals.mNode.mPrev;
  UFG::Editor::Terminal::sTerminals.mNode.mPrev->mNext = v7;
  v7->mPrev = v8;
  v7->mNext = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&UFG::Editor::Terminal::sTerminals;
  UFG::Editor::Terminal::sTerminals.mNode.mPrev = v7;
  this->mLineNumber = 0;
  UFG::Editor::Terminal::TextOutA(this, "Editor Terminal Output");
  if ( v15 )
  {
    v9 = v13;
    p_mPrev = &p_m_SafePointerList->mNode.mPrev;
    v13[1] = (__int64)p_m_SafePointerList;
    *p_mPrev = v9;
    v13 = (__int64 *)&v13;
    p_m_SafePointerList = (UFG::qList<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList,1,0> *)&v13;
  }
  v11 = v13;
  v12 = &p_m_SafePointerList->mNode.mPrev;
  v13[1] = (__int64)p_m_SafePointerList;
  *v12 = v11;
}

// File Line: 74
// RVA: 0x203C50
void __fastcall UFG::Editor::Terminal::~Terminal(UFG::Editor::Terminal *this)
{
  UFG::qSafePointerNode<UFG::Editor::Terminal> *v2; // rsi
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *mNext; // rbx
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *mPrev; // rdx
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v5; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v13; // rax

  this->UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Terminal::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Terminal::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2 = &this->UFG::qSafePointerNode<UFG::Editor::Terminal>;
  this->UFG::qSafePointerNode<UFG::Editor::Terminal>::vfptr = (UFG::qSafePointerNode<UFG::Editor::Terminal>Vtbl *)&UFG::Editor::Terminal::`vftable;
  mNext = UFG::Editor::Terminal::sTerminals.mNode.mNext;
  if ( (UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)UFG::Editor::Terminal::sTerminals.mNode.mNext != &UFG::Editor::Terminal::sTerminals )
  {
    while ( (UFG::Editor::Terminal *)mNext[2].mPrev != this )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&UFG::Editor::Terminal::sTerminals )
        goto LABEL_6;
    }
    mPrev = mNext->mPrev;
    v5 = mNext->mNext;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry((UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)mNext);
    operator delete[](mNext);
  }
LABEL_6:
  UFG::qRemovePrintHandler(UFG::Editor::Terminal::PrintHandlerBridge, this);
  `eh vector destructor iterator(
    this->mLines,
    0x30ui64,
    512,
    (void (__fastcall *)(void *))UFG::PersistentData::String::~String);
  v2->vfptr = (UFG::qSafePointerNode<UFG::Editor::Terminal>Vtbl *)&UFG::qSafePointerNode<UFG::Editor::Terminal>::`vftable;
  p_m_SafePointerList = &v2->m_SafePointerList;
  if ( (UFG::qList<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList,1,0> *)v2->m_SafePointerList.mNode.mNext != &v2->m_SafePointerList )
  {
    while ( 1 )
    {
      v7 = v2->m_SafePointerList.mNode.mNext;
      if ( (unsigned __int64)v7 < 0x10 )
        break;
      if ( v7[1].mPrev
        || (v8 = v7->mPrev, v9 = v7->mNext, v8->mNext = v9, v9->mPrev = v8, v7->mPrev = v7, v7->mNext = v7, v7[1].mPrev) )
      {
        v10 = v7->mPrev;
        v11 = v7->mNext;
        v10->mNext = v11;
        v11->mPrev = v10;
        v7->mPrev = v7;
        v7->mNext = v7;
      }
      v7[1].mPrev = 0i64;
      if ( (UFG::qList<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList,1,0> *)v2->m_SafePointerList.mNode.mNext == &v2->m_SafePointerList )
        goto LABEL_14;
    }
    p_m_SafePointerList->mNode.mPrev = &p_m_SafePointerList->mNode;
    v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  }
LABEL_14:
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v2->m_SafePointerList);
  v12 = p_m_SafePointerList->mNode.mPrev;
  v13 = v2->m_SafePointerList.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  p_m_SafePointerList->mNode.mPrev = &p_m_SafePointerList->mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  UFG::DUIWindow::~DUIWindow(this);
}

// File Line: 97
// RVA: 0x213B40
__int64 __fastcall UFG::Editor::Terminal::TextOutA(UFG::Editor::Terminal *this, const char *text)
{
  const char *v2; // rbx
  int i; // esi
  char *v5; // rax
  char *v6; // r14
  int v7; // edi
  int mEOL; // eax
  BOOL v9; // r8d

  v2 = text;
  if ( !text || !*text )
    return 0i64;
  for ( i = UFG::qStringLength(text); *v2; i -= v9 + v7 )
  {
    v5 = UFG::qStringFind(v2, i, "\n", 1, 0);
    v6 = v5;
    if ( v5 )
      v7 = (_DWORD)v5 - (_DWORD)v2;
    else
      v7 = i;
    UFG::qString::Set(&this->mLines[this->mEOL].mText, v2, v7, 0i64, 0);
    this->mLines[this->mEOL].mLineNumber = this->mLineNumber;
    mEOL = this->mEOL;
    ++this->mLineNumber;
    this->mEOL = (mEOL + 1) % 512;
    v9 = v6 != 0i64;
    v2 += v9 + v7;
  }
  return 1i64;
}

// File Line: 122
// RVA: 0x21D700
void __fastcall UFG::Editor::Terminal::UpdateUI(UFG::Editor::Terminal *this, UFG::DUIContext *dui)
{
  int mEOL; // eax
  int v5; // ebx
  char *mData; // rdx
  char dest[256]; // [rsp+30h] [rbp-108h] BYREF

  UFG::DUIContext::BeginGridLayout(dui, 1, 3, LayoutFlag_FillLastCell);
  UFG::DUIContext::BeginLayoutHorizontal(dui);
  UFG::DUIContext::Checkbox(dui, "Editor Output", (unsigned int *)&this->mChannel, 1u);
  UFG::DUIContext::Empty(dui);
  UFG::DUIContext::Checkbox(dui, "Game Output", (unsigned int *)&this->mChannel, 2u);
  UFG::DUIContext::Empty(dui);
  UFG::DUIContext::Checkbox(dui, "Follow Tail", &this->mFollowTail);
  UFG::DUIContext::Empty(dui);
  UFG::DUIContext::Checkbox(dui, "Line Numbers", &this->mShowLineNumbers);
  UFG::DUIContext::Empty(dui);
  UFG::DUIContext::EndLayoutHorizontal(dui);
  UFG::DUIContext::Separator(dui);
  UFG::DUIContext::BeginScrollView(dui, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(dui);
  mEOL = this->mEOL;
  v5 = (mEOL + 1) % 512;
  if ( v5 != mEOL )
  {
    do
    {
      mData = this->mLines[v5].mText.mData;
      if ( mData && *mData )
      {
        if ( this->mShowLineNumbers )
        {
          UFG::qSPrintf(dest, 256, "%05d: %s", (unsigned int)this->mLines[v5].mLineNumber, this->mLines[v5].mText.mData);
          mData = dest;
        }
        UFG::DUIContext::Label(dui, mData);
      }
      v5 = (v5 + 1) % 512;
    }
    while ( v5 != this->mEOL );
  }
  UFG::DUIContext::EndLayoutHorizontal(dui);
  if ( this->mFollowTail )
    this->mScrollPos.mY = 20000;
  UFG::DUIContext::EndScrollView(dui);
  UFG::DUIContext::EndLayoutHorizontal(dui);
}

