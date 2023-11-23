// File Line: 8
// RVA: 0x146D040
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::MenuBar_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::MenuBar", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::sInventory,
    "UFG::Editor::MenuBar",
    v0);
  UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::MenuBar>::`vftable;
  UFG::qReflectInventory<UFG::Editor::MenuBar>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::MenuBar_UFG::DUIWindow_::sInventory__);
}

// File Line: 21
// RVA: 0x201BB0
void __fastcall UFG::Editor::MenuBar::MenuBar(UFG::Editor::MenuBar *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::MenuBar", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::MenuBar::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::MenuBar,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::MenuBar::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&this->mSceneLayer.mFilter_Text);
  this->mSceneLayer.mFilteredList.p = 0i64;
  *(_QWORD *)&this->mSceneLayer.mFilteredList.size = 0i64;
  this->mSceneLayer.mLayer_SelectedItems.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mSceneLayer.mLayer_SelectedItems.mData.p = 0i64;
  *(_QWORD *)&this->mSceneLayer.mLayer_SelectedItems.mData.size = 0i64;
  this->mSceneLayer.mLayer_ScrollPos = 0i64;
  this->mSceneLayer.mMetrics = 0i64;
  this->mSceneLayer.mSortIndex = 1;
  this->mSceneLayer.mOldSortIndex = -1;
  this->mMinSize = (UFG::DUIPoint)0x32000000C8i64;
  UFG::qString::Set(&this->mTitle, "EDITOR");
}

// File Line: 36
// RVA: 0x219960
void __fastcall UFG::Editor::MenuBar::UpdateUI(UFG::Editor::MenuBar *this, UFG::DUIContext *dui)
{
  int v3; // ebx
  UFG::PopupMenuCommand *v4; // rsi
  UFG::CommandContext *v5; // rbx
  __int64 v6; // [rsp+28h] [rbp-40h]
  __int64 v7; // [rsp+30h] [rbp-38h]
  UFG::qArray<UFG::Command *,0> commands; // [rsp+38h] [rbp-30h] BYREF
  UFG::DUIPoint point; // [rsp+80h] [rbp+18h] BYREF
  UFG::CommandContext *v10; // [rsp+88h] [rbp+20h]

  UFG::DUIContext::BeginLayoutHorizontal(dui);
  commands.p = 0i64;
  *(_QWORD *)&commands.size = 0i64;
  UFG::CommandManager::GetCommandsByTag(UFG::gCommandManager, "WorldEditor.RootMenu", &commands);
  v3 = 0;
  if ( commands.size )
  {
    while ( 1 )
    {
      v4 = (UFG::PopupMenuCommand *)commands.p[v3];
      if ( UFG::DUIContext::Button(dui, v4->mDisplayText.mData, 0x12u) )
        break;
      if ( ++v3 >= commands.size )
        goto LABEL_9;
    }
    v6 = *(_QWORD *)&dui->mLastRect.mX;
    v7 = *(_QWORD *)&dui->mLastRect.mW;
    point.mX = v6;
    point.mY = HIDWORD(v6) + HIDWORD(v7);
    v5 = (UFG::CommandContext *)UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
    v10 = v5;
    if ( v5 )
    {
      v5->vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable;
      UFG::qBaseTreeRB::qBaseTreeRB(&v5->mDictionary.mTree);
    }
    else
    {
      v5 = 0i64;
    }
    UFG::DUIContext::ShowPopupMenu(dui, (UFG::qBaseNodeRB **)&point, v4, v5);
  }
LABEL_9:
  UFG::DUIContext::EndLayoutHorizontal(dui);
  if ( commands.p )
    operator delete[](commands.p);
}

