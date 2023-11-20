// File Line: 81
// RVA: 0x1AFBC0
void __fastcall DNA::DUIDNAInspector::DUIDNAInspector(DNA::DUIDNAInspector *this, MemImageLoadFlag f)
{
  DNA::DUIDNAInspector *v2; // rbx
  signed __int64 v3; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->mBaseNode.mUID = -1i64;
  v2->mTypeUID = UFG::qStringHash64("DNA::DUIDNAInspector", 0xFFFFFFFFFFFFFFFFui64);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&DNA::DUIDNAInspector::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&DNA::DUIDNAInspector::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v3 = (signed __int64)&v2->mWidget;
  *(_QWORD *)(v3 + 16) = 0i64;
  *(_QWORD *)(v3 + 8) = 0i64;
  v2->mWidget.mExpandState.p = 0i64;
  *(_QWORD *)&v2->mWidget.mExpandState.size = 0i64;
  v2->mWidget.mProperties = 0i64;
  v2->mWidget.mWrapper = 0i64;
  v2->mWidget.mActiveEdit = 0i64;
  UFG::qString::qString(&v2->mWidget.mEditValue);
  v2->mScrollPos = 0i64;
}

// File Line: 82
// RVA: 0x1AFC70
void __fastcall DNA::DUIDNAInspector::DUIDNAInspector(DNA::DUIDNAInspector *this)
{
  DNA::DUIDNAInspector *v1; // rbx
  signed __int64 v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<DNA::DUIDNAInspector,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("DNA::DUIDNAInspector", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&DNA::DUIDNAInspector::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&DNA::DUIDNAInspector::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2 = (signed __int64)&v1->mWidget;
  *(_QWORD *)(v2 + 16) = 0i64;
  *(_QWORD *)(v2 + 8) = 0i64;
  v1->mWidget.mExpandState.p = 0i64;
  *(_QWORD *)&v1->mWidget.mExpandState.size = 0i64;
  v1->mWidget.mProperties = 0i64;
  v1->mWidget.mWrapper = 0i64;
  v1->mWidget.mActiveEdit = 0i64;
  UFG::qString::qString(&v1->mWidget.mEditValue);
  v1->mScrollPos = 0i64;
}

// File Line: 200
// RVA: 0x1AFDE0
void __fastcall DNA::DUIReflectInspector::DUIReflectInspector(DNA::DUIReflectInspector *this)
{
  DNA::DUIReflectInspector *v1; // rbx
  unsigned __int64 v2; // rax

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<DNA::DUIReflectInspector,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<DNA::DUIReflectInspector,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("DNA::DUIReflectInspector", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&DNA::DUIReflectInspector::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&DNA::DUIReflectInspector::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2 = UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &v1->mNotification,
    v2,
    DNA::DUIReflectInspector::OnPropertyChanged,
    DNA::DUIReflectInspector::OnObjectReloaded,
    0i64);
  UFG::qReflectHandleBase::qReflectHandleBase(&v1->mObjectHandle);
  DNA::DUIReflectWidget::DUIReflectWidget(&v1->mWidget);
  v1->mScrollPos = 0i64;
  v1->mNotification.mUserData = v1;
}

// File Line: 208
// RVA: 0x1AFD20
void __fastcall DNA::DUIReflectInspector::DUIReflectInspector(DNA::DUIReflectInspector *this, MemImageLoadFlag f)
{
  DNA::DUIReflectInspector *v2; // rbx
  unsigned __int64 v3; // rax

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<DNA::DUIReflectInspector,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<DNA::DUIReflectInspector,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&DNA::DUIReflectInspector::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&DNA::DUIReflectInspector::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v3 = UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &v2->mNotification,
    v3,
    DNA::DUIReflectInspector::OnPropertyChanged,
    DNA::DUIReflectInspector::OnObjectReloaded,
    0i64);
  UFG::qReflectHandleBase::qReflectHandleBase(&v2->mObjectHandle);
  DNA::DUIReflectWidget::DUIReflectWidget(&v2->mWidget);
  v2->mScrollPos = 0i64;
  v2->mNotification.mUserData = v2;
}

