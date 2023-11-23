// File Line: 197
// RVA: 0x202620
void __fastcall UFG::Editor::SceneLayerListWindow::SceneLayerListWindow(UFG::Editor::SceneLayerListWindow *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::SceneLayerListWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::SceneLayerListWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::SceneLayerListWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&this->mLayerControl.mFilter_Text);
  this->mLayerControl.mFilteredList.p = 0i64;
  *(_QWORD *)&this->mLayerControl.mFilteredList.size = 0i64;
  this->mLayerControl.mLayer_SelectedItems.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mLayerControl.mLayer_SelectedItems.mData.p = 0i64;
  *(_QWORD *)&this->mLayerControl.mLayer_SelectedItems.mData.size = 0i64;
  this->mLayerControl.mLayer_ScrollPos = 0i64;
  this->mLayerControl.mMetrics = 0i64;
  this->mLayerControl.mSortIndex = 1;
  this->mLayerControl.mOldSortIndex = -1;
  UFG::qString::Set(&this->mTitle, "Layers");
  UFG::Editor::SceneLayerControl::mRefreshFiltered = 1;
}

// File Line: 198
// RVA: 0x202550
void __fastcall UFG::Editor::SceneLayerListWindow::SceneLayerListWindow(
        UFG::Editor::SceneLayerListWindow *this,
        MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::SceneLayerListWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::SceneLayerListWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&this->mLayerControl.mFilter_Text);
  this->mLayerControl.mFilteredList.p = 0i64;
  *(_QWORD *)&this->mLayerControl.mFilteredList.size = 0i64;
  this->mLayerControl.mLayer_SelectedItems.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mLayerControl.mLayer_SelectedItems.mData.p = 0i64;
  *(_QWORD *)&this->mLayerControl.mLayer_SelectedItems.mData.size = 0i64;
  this->mLayerControl.mLayer_ScrollPos = 0i64;
  this->mLayerControl.mMetrics = 0i64;
  this->mLayerControl.mSortIndex = 1;
  this->mLayerControl.mOldSortIndex = -1;
  UFG::qString::Set(&this->mTitle, "Layers");
  UFG::Editor::SceneLayerControl::mRefreshFiltered = 1;
}

// File Line: 200
// RVA: 0x21D010
void __fastcall UFG::Editor::SceneLayerListWindow::UpdateUI(
        UFG::Editor::SceneLayerListWindow *this,
        UFG::DUIContext *dui)
{
  UFG::Editor::SceneLayerControl::UpdateUI(&this->mLayerControl, dui);
}

// File Line: 209
// RVA: 0x202700
void __fastcall UFG::Editor::SceneLayerPropertiesWindow::SceneLayerPropertiesWindow(
        UFG::Editor::SceneLayerPropertiesWindow *this,
        MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::SceneLayerPropertiesWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::SceneLayerPropertiesWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mSceneObject_ExpandedItems.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  this->mSceneObject_ExpandedItems.mData.p = 0i64;
  *(_QWORD *)&this->mSceneObject_ExpandedItems.mData.size = 0i64;
  UFG::qString::qString(&this->mLockedSelection);
  UFG::Editor::SceneLayerPropertiesWindow::Init(this);
}

