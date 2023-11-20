// File Line: 16
// RVA: 0x146C6B0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::Terminal_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::Terminal", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::Editor::Terminal>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 44
// RVA: 0x146D750
__int64 dynamic_initializer_for__UFG::Editor::Terminal::sTerminals__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::Editor::Terminal::sTerminals__);
}

// File Line: 55
// RVA: 0x202C30
void __fastcall UFG::Editor::Terminal::Terminal(UFG::Editor::Terminal *this)
{
  UFG::Editor::Terminal *v1; // rdi

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::Terminal,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::Terminal", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qSafePointerNode<UFG::Editor::Terminal>::qSafePointerNode<UFG::Editor::Terminal>((UFG::qSafePointerNode<UFG::Editor::Terminal> *)&v1->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Terminal::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Terminal::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::Editor::Terminal>Vtbl *)&UFG::Editor::Terminal::`vftable';
  *(_WORD *)&v1->mFollowTail = 1;
  *(_QWORD *)&v1->mChannel = 3i64;
  v1->mScrollPos.mY = 0;
  `eh vector constructor iterator'(
    v1->mLines,
    0x30ui64,
    512,
    (void (__fastcall *)(void *))UFG::PersistentData::String::String);
  *(_QWORD *)&v1->mEOL = 0i64;
  UFG::Editor::Terminal::Initialize(v1);
}

// File Line: 61
// RVA: 0x20D830
void __fastcall UFG::Editor::Terminal::Initialize(UFG::Editor::Terminal *this)
{
  UFG::Editor::Terminal *v1; // rbx
  __int64 *v2; // rax
  UFG::allocator::free_link *v3; // r8
  __int64 **v4; // rcx
  __int64 *v5; // rax
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v6; // rax
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v7; // rcx
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v8; // rax
  __int64 *v9; // rcx
  __int64 **v10; // rax
  __int64 *v11; // rcx
  __int64 **v12; // rax
  __int64 *v13; // [rsp+28h] [rbp-38h]
  __int64 **v14; // [rsp+30h] [rbp-30h]
  UFG::Editor::Terminal *v15; // [rsp+38h] [rbp-28h]
  __int64 *v16; // [rsp+40h] [rbp-20h]
  __int64 **v17; // [rsp+48h] [rbp-18h]
  UFG::Editor::Terminal *v18; // [rsp+50h] [rbp-10h]

  v1 = this;
  UFG::qString::Set(&this->mTitle, "Terminal");
  UFG::qAddPrintHandler(UFG::Editor::Terminal::PrintHandlerBridge, v1);
  v13 = (__int64 *)&v13;
  v14 = &v13;
  v15 = v1;
  if ( v1 )
  {
    v2 = (__int64 *)v1->m_SafePointerList.mNode.mPrev;
    v2[1] = (__int64)&v13;
    v13 = v2;
    v14 = (__int64 **)&v1->m_SafePointerList;
    v1->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *)&v13;
  }
  v3 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  if ( v3 )
  {
    v16 = (__int64 *)&v16;
    v17 = &v16;
    v18 = v15;
    if ( v15 )
    {
      v4 = (__int64 **)&v15->m_SafePointerList;
      v5 = (__int64 *)v15->m_SafePointerList.mNode.mPrev;
      v5[1] = (__int64)&v16;
      v16 = v5;
      v17 = v4;
      *v4 = (__int64 *)&v16;
    }
    UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal>>::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal>>(
      (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v3,
      (UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> *)&v16);
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
  v1->mLineNumber = 0;
  UFG::Editor::Terminal::TextOutA(v1, "Editor Terminal Output");
  if ( v15 )
  {
    v9 = v13;
    v10 = v14;
    v13[1] = (__int64)v14;
    *v10 = v9;
    v13 = (__int64 *)&v13;
    v14 = &v13;
  }
  v11 = v13;
  v12 = v14;
  v13[1] = (__int64)v14;
  *v12 = v11;
}

// File Line: 74
// RVA: 0x203C50
void __fastcall UFG::Editor::Terminal::~Terminal(UFG::Editor::Terminal *this)
{
  UFG::Editor::Terminal *v1; // rdi
  UFG::qSafePointerNode<UFG::Editor::Terminal> *v2; // rsi
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v3; // rbx
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v4; // rdx
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v5; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList,1,0> *v6; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Editor::Terminal>,UFG::qSafePointerNodeList> *v13; // rax

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Terminal::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  this->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Terminal::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2 = (UFG::qSafePointerNode<UFG::Editor::Terminal> *)&this->vfptr;
  this->vfptr = (UFG::qSafePointerNode<UFG::Editor::Terminal>Vtbl *)&UFG::Editor::Terminal::`vftable';
  v3 = UFG::Editor::Terminal::sTerminals.mNode.mNext;
  if ( (UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)UFG::Editor::Terminal::sTerminals.mNode.mNext != &UFG::Editor::Terminal::sTerminals )
  {
    while ( (UFG::Editor::Terminal *)v3[2].mPrev != this )
    {
      v3 = v3->mNext;
      if ( v3 == (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&UFG::Editor::Terminal::sTerminals )
        goto LABEL_6;
    }
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = v3;
    v3->mNext = v3;
    UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry((UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v3);
    operator delete[](v3);
  }
LABEL_6:
  UFG::qRemovePrintHandler(UFG::Editor::Terminal::PrintHandlerBridge, v1);
  `eh vector destructor iterator'(
    v1->mLines,
    0x30ui64,
    512,
    (void (__fastcall *)(void *))UFG::PersistentData::String::~String);
  v2->vfptr = (UFG::qSafePointerNode<UFG::Editor::Terminal>Vtbl *)&UFG::qSafePointerNode<UFG::Editor::Terminal>::`vftable';
  v6 = &v2->m_SafePointerList;
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
    v6->mNode.mPrev = &v6->mNode;
    v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  }
LABEL_14:
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v2->m_SafePointerList);
  v12 = v6->mNode.mPrev;
  v13 = v2->m_SafePointerList.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v6->mNode.mPrev = &v6->mNode;
  v2->m_SafePointerList.mNode.mNext = &v2->m_SafePointerList.mNode;
  UFG::DUIWindow::~DUIWindow((UFG::DUIWindow *)&v1->vfptr);
}

// File Line: 97
// RVA: 0x213B40
signed __int64 __fastcall UFG::Editor::Terminal::TextOutA(UFG::Editor::Terminal *this, const char *text)
{
  const char *v2; // rbx
  UFG::Editor::Terminal *v3; // rbp
  int i; // esi
  char *v5; // rax
  char *v6; // r14
  int v7; // edi
  int v8; // eax
  BOOL v9; // er8

  v2 = text;
  v3 = this;
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
    UFG::qString::Set(&v3->mLines[v3->mEOL].mText, v2, v7, 0i64, 0);
    v3->mLines[v3->mEOL].mLineNumber = v3->mLineNumber;
    v8 = v3->mEOL;
    ++v3->mLineNumber;
    v3->mEOL = (v8 + 1) % 512;
    v9 = v6 != 0i64;
    v2 += v9 + v7;
  }
  return 1i64;
}

// File Line: 122
// RVA: 0x21D700
void __fastcall UFG::Editor::Terminal::UpdateUI(UFG::Editor::Terminal *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rsi
  UFG::Editor::Terminal *v3; // rdi
  int v4; // eax
  int v5; // ebx
  char *v6; // rdx
  char dest; // [rsp+30h] [rbp-108h]

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginGridLayout(dui, 1, 3, 3);
  UFG::DUIContext::BeginLayoutHorizontal(v2);
  UFG::DUIContext::Checkbox(v2, "Editor Output", (unsigned int *)&v3->mChannel, 1u);
  UFG::DUIContext::Empty(v2);
  UFG::DUIContext::Checkbox(v2, "Game Output", (unsigned int *)&v3->mChannel, 2u);
  UFG::DUIContext::Empty(v2);
  UFG::DUIContext::Checkbox(v2, "Follow Tail", &v3->mFollowTail);
  UFG::DUIContext::Empty(v2);
  UFG::DUIContext::Checkbox(v2, "Line Numbers", &v3->mShowLineNumbers);
  UFG::DUIContext::Empty(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::Separator(v2);
  UFG::DUIContext::BeginScrollView(v2, &v3->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(v2);
  v4 = v3->mEOL;
  v5 = (v4 + 1) % 512;
  if ( v5 != v4 )
  {
    do
    {
      v6 = (char *)(&v3->vfptr)[6 * (v5 + 8i64)];
      if ( v6 && *v6 )
      {
        if ( v3->mShowLineNumbers )
        {
          UFG::qSPrintf(&dest, 256, "%05d: %s", (unsigned int)v3->mLines[v5].mLineNumber, (&v3->vfptr)[6 * (v5 + 8i64)]);
          v6 = &dest;
        }
        UFG::DUIContext::Label(v2, v6);
      }
      v5 = (v5 + 1) % 512;
    }
    while ( v5 != v3->mEOL );
  }
  UFG::DUIContext::EndLayoutHorizontal(v2);
  if ( v3->mFollowTail )
    v3->mScrollPos.mY = 20000;
  UFG::DUIContext::EndScrollView(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
}

