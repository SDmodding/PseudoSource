// File Line: 197
// RVA: 0x202620
void __fastcall UFG::Editor::SceneLayerListWindow::SceneLayerListWindow(UFG::Editor::SceneLayerListWindow *this)
{
  UFG::Editor::SceneLayerListWindow *v1; // rdi
  UFG::DUIIntArray *v2; // [rsp+50h] [rbp+18h]

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::SceneLayerListWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::SceneLayerListWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::SceneLayerListWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&v1->mLayerControl.mFilter_Text);
  v1->mLayerControl.mFilteredList.p = 0i64;
  *(_QWORD *)&v1->mLayerControl.mFilteredList.size = 0i64;
  v2 = &v1->mLayerControl.mLayer_SelectedItems;
  v2->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v2->mData.p = 0i64;
  *(_QWORD *)&v2->mData.size = 0i64;
  v1->mLayerControl.mLayer_ScrollPos = 0i64;
  v1->mLayerControl.mMetrics = 0i64;
  v1->mLayerControl.mSortIndex = 1;
  v1->mLayerControl.mOldSortIndex = -1;
  UFG::qString::Set(&v1->mTitle, "Layers");
  UFG::Editor::SceneLayerControl::mRefreshFiltered = 1;
}

// File Line: 198
// RVA: 0x202550
void __fastcall UFG::Editor::SceneLayerListWindow::SceneLayerListWindow(UFG::Editor::SceneLayerListWindow *this, MemImageLoadFlag f)
{
  UFG::Editor::SceneLayerListWindow *v2; // rdi
  UFG::DUIIntArray *v3; // [rsp+58h] [rbp+20h]

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::SceneLayerListWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::SceneLayerListWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::qString(&v2->mLayerControl.mFilter_Text);
  v2->mLayerControl.mFilteredList.p = 0i64;
  *(_QWORD *)&v2->mLayerControl.mFilteredList.size = 0i64;
  v3 = &v2->mLayerControl.mLayer_SelectedItems;
  v3->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v3->mData.p = 0i64;
  *(_QWORD *)&v3->mData.size = 0i64;
  v2->mLayerControl.mLayer_ScrollPos = 0i64;
  v2->mLayerControl.mMetrics = 0i64;
  v2->mLayerControl.mSortIndex = 1;
  v2->mLayerControl.mOldSortIndex = -1;
  UFG::qString::Set(&v2->mTitle, "Layers");
  UFG::Editor::SceneLayerControl::mRefreshFiltered = 1;
}

// File Line: 200
// RVA: 0x21D010
void __fastcall UFG::Editor::SceneLayerListWindow::UpdateUI(UFG::Editor::SceneLayerListWindow *this, UFG::DUIContext *dui)
{
  UFG::Editor::SceneLayerControl::UpdateUI(&this->mLayerControl, dui);
}

// File Line: 209
// RVA: 0x202700
void __fastcall UFG::Editor::SceneLayerPropertiesWindow::SceneLayerPropertiesWindow(UFG::Editor::SceneLayerPropertiesWindow *this, MemImageLoadFlag f)
{
  UFG::Editor::SceneLayerPropertiesWindow *v2; // rbx
  UFG::DUIIntArray *v3; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::SceneLayerPropertiesWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::SceneLayerPropertiesWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v3 = &v2->mSceneObject_ExpandedItems;
  v3->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v3->mData.p = 0i64;
  *(_QWORD *)&v3->mData.size = 0i64;
  UFG::qString::qString(&v2->mLockedSelection);
  UFG::Editor::SceneLayerPropertiesWindow::Init(v2);
}

