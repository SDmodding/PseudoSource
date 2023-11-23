// File Line: 9
// RVA: 0x146C370
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::GizmoFilterWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::GizmoFilterWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::GizmoFilterWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::Editor::GizmoFilterWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 13
// RVA: 0x146D6C0
__int64 dynamic_initializer_for__UFG::Editor::GizmoFilterWindow::sSearchText__()
{
  unsigned int v0; // ebx

  v0 = UFG::qStringLength(&customCaption) + 1;
  UFG::qReflectArray<char>::Resize(&UFG::Editor::GizmoFilterWindow::sSearchText.mText, v0, "qReflectString::Set()");
  UFG::qMemCopy(UFG::Editor::GizmoFilterWindow::sSearchText.mText.mData.mItems, &customCaption, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Editor::GizmoFilterWindow::sSearchText__);
}

// File Line: 23
// RVA: 0x201870
void __fastcall UFG::Editor::GizmoFilterWindow::GizmoFilterWindow(UFG::Editor::GizmoFilterWindow *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::GizmoFilterWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::GizmoFilterWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::GizmoFilterWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::GizmoFilterWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::GizmoFilterWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::GizmoFilterWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::GizmoFilterWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::GizmoFilterWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::GizmoFilterWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::Set(&this->mTitle, "Gizmo Filters");
}

// File Line: 32
// RVA: 0x218C10
void __fastcall UFG::Editor::GizmoFilterWindow::UpdateUI(UFG::Editor::GizmoFilterWindow *this, UFG::DUIContext *dui)
{
  UFG::Editor::OptionsGlobal *mGlobal; // r13
  char *mItems; // rdx
  UFG::allocator::free_link *v5; // rbp
  char *mData; // rdi
  unsigned int v7; // ebx
  unsigned int i; // r15d
  UFG::Editor::GizmoVisiblity *v9; // rbx
  const char *v10; // rdx
  const char *v11; // rdx
  char *v12; // r12
  int v13; // eax
  unsigned int v14; // esi
  UFG::allocator::free_link *v15; // rax
  unsigned int mNumItems; // edx
  unsigned int v17; // ecx
  UFG::allocator::free_link *v18; // rdx
  __int64 v19; // r8
  __int64 v20; // r9
  char *v21; // rcx
  UFG::qString current_value; // [rsp+38h] [rbp-50h] BYREF

  UFG::DUIContext::BeginScrollView(dui, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(dui);
  mGlobal = UFG::Editor::gOptions.mGlobal;
  mItems = &customCaption;
  if ( UFG::Editor::GizmoFilterWindow::sSearchText.mText.mData.mNumItems )
    mItems = UFG::Editor::GizmoFilterWindow::sSearchText.mText.mData.mItems;
  UFG::qString::qString(&current_value, mItems);
  v5 = 0i64;
  if ( (unsigned __int8)UFG::DUIContext::TextBox(dui, &current_value, "Search...", 1, 0i64, -1) )
  {
    mData = current_value.mData;
    v7 = UFG::qStringLength(current_value.mData) + 1;
    UFG::qReflectArray<char>::Resize(&UFG::Editor::GizmoFilterWindow::sSearchText.mText, v7, "qReflectString::Set()");
    UFG::qMemCopy(UFG::Editor::GizmoFilterWindow::sSearchText.mText.mData.mItems, mData, v7);
  }
  for ( i = 0; i < mGlobal->mGizmoVisiblity.mData.mNumItems; ++i )
  {
    UFG::DUIContext::BeginGridLayout(dui, 2, 0, 0i64, 0i64, LayoutFlag_None);
    v9 = mGlobal->mGizmoVisiblity.mData.mItems;
    if ( v9[i].mName.mText.mData.mNumItems )
      v10 = v9[i].mName.mText.mData.mItems;
    else
      v10 = &customCaption;
    UFG::DUIContext::Checkbox(dui, v10, &v9[i].mVisible);
    if ( v9[i].mFilter.mText.mData.mNumItems )
      v11 = v9[i].mFilter.mText.mData.mItems;
    else
      v11 = &customCaption;
    UFG::qString::Set(&current_value, v11);
    if ( (unsigned __int8)UFG::DUIContext::TextBox(dui, &current_value, "Search...", 1, 0i64, -1) )
    {
      v12 = current_value.mData;
      v13 = UFG::qStringLength(current_value.mData);
      v14 = v13 + 1;
      if ( v13 != -1 )
      {
        v15 = UFG::qMalloc(v14, "qReflectString::Set()", 0i64);
        v5 = v15;
        mNumItems = v9[i].mFilter.mText.mData.mNumItems;
        if ( mNumItems )
        {
          v17 = v14;
          if ( mNumItems < v14 )
            v17 = v9[i].mFilter.mText.mData.mNumItems;
          if ( v17 )
          {
            v18 = v15;
            v19 = 0i64;
            v20 = v17;
            do
            {
              LOBYTE(v18->mNext) = v9[i].mFilter.mText.mData.mItems[v19++];
              v18 = (UFG::allocator::free_link *)((char *)v18 + 1);
              --v20;
            }
            while ( v20 );
          }
        }
      }
      v21 = v9[i].mFilter.mText.mData.mItems;
      if ( v21 && (v9[i].mFilter.mText.mData.mFlags & 2) == 0 )
        operator delete[](v21);
      v9[i].mFilter.mText.mData.mItems = (char *)v5;
      v9[i].mFilter.mText.mData.mNumItems = v14;
      v9[i].mFilter.mText.mData.mFlags = 0;
      UFG::qMemCopy(v5, v12, v14);
      v5 = 0i64;
    }
    UFG::DUIContext::EndLayoutHorizontal(dui);
  }
  UFG::DUIContext::EndLayoutHorizontal(dui);
  UFG::DUIContext::EndScrollView(dui);
  UFG::qString::~qString(&current_value);
}

