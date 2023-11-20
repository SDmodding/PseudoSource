// File Line: 9
// RVA: 0x1585DE0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::SimObjectDebugWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::SimObjectDebugWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::SimObjectDebugWindow,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::Editor::SimObjectDebugWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::SimObjectDebugWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::SimObjectDebugWindow>::`vftable;
  UFG::qReflectInventory<UFG::Editor::SimObjectDebugWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::SimObjectDebugWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::SimObjectDebugWindow,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::SimObjectDebugWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 26
// RVA: 0x69CB00
void __fastcall UFG::Editor::SimObjectDebugWindow::SimObjectDebugWindow(UFG::Editor::SimObjectDebugWindow *this)
{
  UFG::Editor::SimObjectDebugWindow *v1; // rbx

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::SimObjectDebugWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::SimObjectDebugWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::SimObjectDebugWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::SimObjectDebugWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::SimObjectDebugWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::Set(&v1->mTitle, "Sim Object Debug");
}

