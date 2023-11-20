// File Line: 8
// RVA: 0x146D040
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::MenuBar_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::MenuBar", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::Editor::MenuBar",
    v0);
  UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::MenuBar>::`vftable;
  UFG::qReflectInventory<UFG::Editor::MenuBar>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::MenuBar_UFG::DUIWindow_::sInventory__);
}

// File Line: 21
// RVA: 0x201BB0
void __fastcall UFG::Editor::MenuBar::MenuBar(UFG::Editor::MenuBar *this)
{
  UFG::Editor::MenuBar *v1; // rdi
  UFG::DUIIntArray *v2; // [rsp+50h] [rbp+18h]

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::MenuBar", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::MenuBar::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::MenuBar::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&v1->mSceneLayer.mFilter_Text);
  v1->mSceneLayer.mFilteredList.p = 0i64;
  *(_QWORD *)&v1->mSceneLayer.mFilteredList.size = 0i64;
  v2 = &v1->mSceneLayer.mLayer_SelectedItems;
  v2->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v2->mData.p = 0i64;
  *(_QWORD *)&v2->mData.size = 0i64;
  v1->mSceneLayer.mLayer_ScrollPos = 0i64;
  v1->mSceneLayer.mMetrics = 0i64;
  v1->mSceneLayer.mSortIndex = 1;
  v1->mSceneLayer.mOldSortIndex = -1;
  v1->mMinSize = (UFG::DUIPoint)214748365000i64;
  UFG::qString::Set(&v1->mTitle, "EDITOR");
}

// File Line: 36
// RVA: 0x219960
void __fastcall UFG::Editor::MenuBar::UpdateUI(UFG::Editor::MenuBar *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  int v3; // ebx
  UFG::PopupMenuCommand *v4; // rsi
  int v5; // ST2C_4
  __int64 v6; // ST30_8
  UFG::CommandContext *v7; // rbx
  UFG::qArray<UFG::Command *,0> commands; // [rsp+38h] [rbp-30h]
  UFG::DUIPoint point; // [rsp+80h] [rbp+18h]
  UFG::CommandContext *v10; // [rsp+88h] [rbp+20h]

  v2 = dui;
  UFG::DUIContext::BeginLayoutHorizontal(dui);
  commands.p = 0i64;
  *(_QWORD *)&commands.size = 0i64;
  UFG::CommandManager::GetCommandsByTag(UFG::gCommandManager, "WorldEditor.RootMenu", &commands);
  v3 = 0;
  if ( commands.size > 0 )
  {
    while ( 1 )
    {
      v4 = (UFG::PopupMenuCommand *)commands.p[v3];
      if ( (unsigned __int8)UFG::DUIContext::Button(v2, v4->mDisplayText.mData, 0x12u) )
        break;
      if ( ++v3 >= commands.size )
        goto LABEL_9;
    }
    v5 = v2->mLastRect.mY;
    v6 = *(_QWORD *)&v2->mLastRect.mW;
    point.mX = v2->mLastRect.mX;
    point.mY = v5 + HIDWORD(v6);
    v7 = (UFG::CommandContext *)UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
    v10 = v7;
    if ( v7 )
    {
      v7->vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable;
      UFG::qBaseTreeRB::qBaseTreeRB(&v7->mDictionary.mTree);
    }
    else
    {
      v7 = 0i64;
    }
    UFG::DUIContext::ShowPopupMenu(v2, &point, v4, v7);
  }
LABEL_9:
  UFG::DUIContext::EndLayoutHorizontal(v2);
  if ( commands.p )
    operator delete[](commands.p);
}

