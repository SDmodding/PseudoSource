// File Line: 245
// RVA: 0x51C0
void __fastcall UFG::qReflectObject::~qReflectObject(UFG::qReflectObject *this)
{
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v1; // rbx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v2; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v3; // rax

  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v1 = &this->mHandles;
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0>::DeleteNodes(&this->mHandles);
  v2 = v1->mNode.mPrev;
  v3 = v1->mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 249
// RVA: 0x5600
const char *__fastcall UFG::qReflectObject::GetTypeName(UFG::qReflectObject *this)
{
  return "UFG::qReflectObject";
}

// File Line: 253
// RVA: 0xB430
unsigned __int64 __fastcall UFG::qReflectObject::GetStaticType()
{
  return UFG::qStringHash64("UFG::qReflectObject", 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 271
// RVA: 0x200CE0
void __fastcall UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>(UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget> *this, MemImageLoadFlag f)
{
  UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget> *v2; // rbx

  v2 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Gadget::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Gadget::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2->mStyle = 141;
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v2->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
}

// File Line: 273
// RVA: 0x404990
void __fastcall UFG::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject>::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject>(UFG::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject> *this)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v1; // r8
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v2; // [rsp+48h] [rbp+10h]

  v1 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v1->mBaseNode.mUID = 0i64;
  v1->mBaseNode.mParent = &v1->mBaseNode;
  v1->mBaseNode.mChildren[0] = &v1->mBaseNode;
  v1->mBaseNode.mChildren[1] = &v1->mBaseNode;
  v1->mBaseNode.mNeighbours[0] = &v1->mBaseNode;
  v1->mBaseNode.mNeighbours[1] = &v1->mBaseNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  this->mTypeUID = -1i64;
  v2 = &this->mHandles;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject>::`vftable';
  v1->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::RangedWeaponStatData", 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 283
// RVA: 0x20CFE0
_BOOL8 __fastcall UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::HasFactory(UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow> *this)
{
  return UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::sFactoryOp.mOnCreateFunc != 0i64;
}

// File Line: 284
// RVA: 0x1B4220
const char *__fastcall UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::GetTypeName(UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject> *this)
{
  return "UITest::ArrayPointerTest";
}

// File Line: 287
// RVA: 0x172420
unsigned __int64 __fastcall UFG::qReflectObjectType<UFG::qReflectOnDemandCacheItem,UFG::qReflectObject>::GetStaticType()
{
  const char *v0; // r8
  unsigned __int64 result; // rax
  char v2; // cl

  v0 = "UFG::qReflectOnDemandCacheItem";
  result = -1i64;
  v2 = 85;
  do
  {
    ++v0;
    result = (result >> 8) ^ sCrcTable64[(unsigned __int8)(result ^ v2)];
    v2 = *v0;
  }
  while ( *v0 );
  return result;
}

// File Line: 303
// RVA: 0x2003B0
void __fastcall UFG::OnLoadClass<UFG::Editor::MenuBar>(char *object_data)
{
  if ( object_data )
    UFG::Editor::MenuBar::MenuBar((UFG::Editor::MenuBar *)object_data, 0);
}

// File Line: 308
// RVA: 0x404860
void __fastcall UFG::OnUnloadClass<UITest::HandleArrayTest>(CAkMusicCtx *this)
{
  this->vfptr->OnLastFrame((CAkChildCtx *)this, 0);
}

// File Line: 328
// RVA: 0x192200
UFG::qReflectObject *__fastcall UFG::OnCreateClass<UFG::DUIThemeEditorWindow>(unsigned __int64 object_uid)
{
  unsigned __int64 v1; // rdi
  UFG::allocator::free_link *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx

  v1 = object_uid;
  v2 = UFG::qMalloc(0x280ui64, UFG::gGlobalNewName, 0i64);
  if ( v2 )
  {
    UFG::DUIThemeEditorWindow::DUIThemeEditorWindow((UFG::DUIThemeEditorWindow *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  *(_QWORD *)(v4 + 8) = v1;
  *(_QWORD *)(v4 + 56) = UFG::qStringHash64("UFG::DUIThemeEditorWindow", 0xFFFFFFFFFFFFFFFFui64);
  return (UFG::qReflectObject *)v4;
}

// File Line: 336
// RVA: 0x8CCD0
void __fastcall UFG::OnDeleteClass<UFG::DUIThemeEditorWindow>(hkpReportContactMgr *this)
{
  if ( this )
    this->vfptr->__vecDelDtor((hkBaseObject *)this, 1u);
}

