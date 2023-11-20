// File Line: 18
// RVA: 0x69CC20
void __fastcall UFG::Editor::SpawnRacketWindow::SpawnRacketWindow(UFG::Editor::SpawnRacketWindow *this)
{
  UFG::Editor::SpawnRacketWindow *v1; // rbx
  UFG::DUIIntArray *v2; // [rsp+48h] [rbp+10h]
  UFG::DUIIntArray *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::SpawnRacketWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::SpawnRacketWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::SpawnRacketWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2 = &v1->mTree_Selection;
  v2->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v2->mData.p = 0i64;
  *(_QWORD *)&v2->mData.size = 0i64;
  v3 = &v1->mTree_ExpandedItems;
  v3->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v3->mData.p = 0i64;
  *(_QWORD *)&v3->mData.size = 0i64;
  UFG::qString::Set(&v1->mTitle, "Spawn Racket");
}

// File Line: 19
// RVA: 0x69CB80
void __fastcall UFG::Editor::SpawnRacketWindow::SpawnRacketWindow(UFG::Editor::SpawnRacketWindow *this, MemImageLoadFlag f)
{
  UFG::Editor::SpawnRacketWindow *v2; // rbx
  UFG::DUIIntArray *v3; // [rsp+50h] [rbp+18h]
  UFG::DUIIntArray *v4; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::SpawnRacketWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::SpawnRacketWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::SpawnRacketWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v3 = &v2->mTree_Selection;
  v3->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v3->mData.p = 0i64;
  *(_QWORD *)&v3->mData.size = 0i64;
  v4 = &v2->mTree_ExpandedItems;
  v4->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable;
  v4->mData.p = 0i64;
  *(_QWORD *)&v4->mData.size = 0i64;
  UFG::qString::Set(&v2->mTitle, "Spawn Racket");
}

