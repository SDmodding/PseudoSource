// File Line: 9
// RVA: 0x146C370
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::GizmoFilterWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::GizmoFilterWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::GizmoFilterWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::Editor::GizmoFilterWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 13
// RVA: 0x146D6C0
__int64 dynamic_initializer_for__UFG::Editor::GizmoFilterWindow::sSearchText__()
{
  unsigned int v0; // ebx

  v0 = (unsigned __int64)UFG::qStringLength(&customWorldMapCaption) + 1;
  UFG::qReflectArray<char>::Resize(&UFG::Editor::GizmoFilterWindow::sSearchText.mText, v0, "qReflectString::Set()");
  UFG::qMemCopy(UFG::Editor::GizmoFilterWindow::sSearchText.mText.mData.mItems, &customWorldMapCaption, v0);
  return atexit(dynamic_atexit_destructor_for__UFG::Editor::GizmoFilterWindow::sSearchText__);
}

// File Line: 23
// RVA: 0x201870
void __fastcall UFG::Editor::GizmoFilterWindow::GizmoFilterWindow(UFG::Editor::GizmoFilterWindow *this)
{
  UFG::Editor::GizmoFilterWindow *v1; // rbx

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::GizmoFilterWindow,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::GizmoFilterWindow,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::GizmoFilterWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::GizmoFilterWindow::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::GizmoFilterWindow::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  UFG::qString::Set(&v1->mTitle, "Gizmo Filters");
}

// File Line: 32
// RVA: 0x218C10
void __fastcall UFG::Editor::GizmoFilterWindow::UpdateUI(UFG::Editor::GizmoFilterWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // r14
  UFG::Editor::OptionsGlobal *v3; // r13
  char *v4; // rdx
  UFG::allocator::free_link *v5; // rbp
  char *v6; // rdi
  unsigned int v7; // ebx
  unsigned int i; // er15
  UFG::Editor::GizmoVisiblity *v9; // rbx
  const char *v10; // rdx
  const char *v11; // rdx
  char *v12; // r12
  int v13; // eax
  unsigned int v14; // esi
  UFG::allocator::free_link *v15; // rax
  unsigned int v16; // edx
  unsigned int v17; // ecx
  UFG::allocator::free_link *v18; // rdx
  __int64 v19; // r8
  __int64 v20; // r9
  char *v21; // rcx
  UFG::qString current_value; // [rsp+38h] [rbp-50h]

  v2 = dui;
  UFG::DUIContext::BeginScrollView(dui, &this->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(v2);
  v3 = UFG::Editor::gOptions.mGlobal;
  v4 = &customWorldMapCaption;
  if ( UFG::Editor::GizmoFilterWindow::sSearchText.mText.mData.mNumItems )
    v4 = UFG::Editor::GizmoFilterWindow::sSearchText.mText.mData.mItems;
  UFG::qString::qString(&current_value, v4);
  v5 = 0i64;
  if ( (unsigned __int8)UFG::DUIContext::TextBox(v2, &current_value, "Search...", 1, 0i64, 0xFFFFFFFF) )
  {
    v6 = current_value.mData;
    v7 = (unsigned __int64)UFG::qStringLength(current_value.mData) + 1;
    UFG::qReflectArray<char>::Resize(&UFG::Editor::GizmoFilterWindow::sSearchText.mText, v7, "qReflectString::Set()");
    UFG::qMemCopy(UFG::Editor::GizmoFilterWindow::sSearchText.mText.mData.mItems, v6, v7);
  }
  for ( i = 0; i < v3->mGizmoVisiblity.mData.mNumItems; ++i )
  {
    UFG::DUIContext::BeginGridLayout(v2, 2, 0, 0i64, 0i64, 0);
    v9 = v3->mGizmoVisiblity.mData.mItems;
    if ( v9[i].mName.mText.mData.mNumItems )
      v10 = v9[i].mName.mText.mData.mItems;
    else
      v10 = &customWorldMapCaption;
    UFG::DUIContext::Checkbox(v2, v10, &v9[i].mVisible);
    if ( v9[i].mFilter.mText.mData.mNumItems )
      v11 = v9[i].mFilter.mText.mData.mItems;
    else
      v11 = &customWorldMapCaption;
    UFG::qString::Set(&current_value, v11);
    if ( (unsigned __int8)UFG::DUIContext::TextBox(v2, &current_value, "Search...", 1, 0i64, 0xFFFFFFFF) )
    {
      v12 = current_value.mData;
      v13 = UFG::qStringLength(current_value.mData);
      v14 = v13 + 1;
      if ( v13 != -1 )
      {
        v15 = UFG::qMalloc(v14, "qReflectString::Set()", 0i64);
        v5 = v15;
        v16 = v9[i].mFilter.mText.mData.mNumItems;
        if ( v16 )
        {
          v17 = v14;
          if ( v16 < v14 )
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
      if ( v21 && !(v9[i].mFilter.mText.mData.mFlags & 2) )
        operator delete[](v21);
      v9[i].mFilter.mText.mData.mItems = (char *)v5;
      v9[i].mFilter.mText.mData.mNumItems = v14;
      v9[i].mFilter.mText.mData.mFlags = 0;
      UFG::qMemCopy(v5, v12, v14);
      v5 = 0i64;
    }
    UFG::DUIContext::EndLayoutHorizontal(v2);
  }
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::EndScrollView(v2);
  UFG::qString::~qString(&current_value);
}

