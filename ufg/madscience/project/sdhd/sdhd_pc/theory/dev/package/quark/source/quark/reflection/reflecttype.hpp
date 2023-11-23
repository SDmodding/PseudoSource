// File Line: 245
// RVA: 0x51C0
void __fastcall UFG::qReflectObject::~qReflectObject(UFG::qReflectObject *this)
{
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *p_mHandles; // rbx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mNext; // rax

  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  p_mHandles = &this->mHandles;
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0>::DeleteNodes(&this->mHandles);
  mPrev = p_mHandles->mNode.mPrev;
  mNext = p_mHandles->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mHandles->mNode.mPrev = &p_mHandles->mNode;
  p_mHandles->mNode.mNext = &p_mHandles->mNode;
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
void __fastcall UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>(
        UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget> *this,
        MemImageLoadFlag f)
{
  UFG::DUIWindow::DUIWindow(this, f);
  this->UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::Gadget::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::Gadget::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mStyle = Style_CloseButton|Style_ShowTitleText|Style_ShowTitleBar|Style_ShowBorder;
  this->UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::Editor::Gadget::UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::OrientationGadget,UFG::Editor::Gadget>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
}

// File Line: 273
// RVA: 0x404990
void __fastcall UFG::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject>::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject>(
        UFG::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject> *this)
{
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  this->mTypeUID = -1i64;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::RangedWeaponStatData,UFG::qReflectObject>::`vftable;
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::RangedWeaponStatData", 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 283
// RVA: 0x20CFE0
_BOOL8 __fastcall UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::HasFactory(
        UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow> *this)
{
  return UFG::qReflectObjectType<UFG::Editor::Gadget,UFG::DUIWindow>::sFactoryOp.mOnCreateFunc != 0i64;
}

// File Line: 284
// RVA: 0x1B4220
const char *__fastcall UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::GetTypeName(
        UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject> *this)
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
void __fastcall UFG::OnLoadClass<UFG::Editor::MenuBar>(UFG::Editor::MenuBar *object_data)
{
  if ( object_data )
    UFG::Editor::MenuBar::MenuBar(object_data, 0);
}

// File Line: 308
// RVA: 0x404860
void __fastcall UFG::OnUnloadClass<UITest::HandleArrayTest>(CAkMusicCtx *this)
{
  this->CAkChildCtx::vfptr->OnLastFrame(this, 0i64);
}

// File Line: 328
// RVA: 0x192200
UFG::qReflectObject *__fastcall UFG::OnCreateClass<UFG::DUIThemeEditorWindow>(unsigned __int64 object_uid)
{
  UFG::allocator::free_link *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx

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
  *(_QWORD *)(v4 + 8) = object_uid;
  *(_QWORD *)(v4 + 56) = UFG::qStringHash64("UFG::DUIThemeEditorWindow", 0xFFFFFFFFFFFFFFFFui64);
  return (UFG::qReflectObject *)v4;
}

// File Line: 336
// RVA: 0x8CCD0
void __fastcall UFG::OnDeleteClass<UFG::DUIThemeEditorWindow>(hkpReportContactMgr *this)
{
  if ( this )
    this->vfptr->__vecDelDtor(this, 1i64);
}

