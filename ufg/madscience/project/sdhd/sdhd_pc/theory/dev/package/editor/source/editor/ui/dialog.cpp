// File Line: 16
// RVA: 0x146CE40
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::EditorDialog_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::EditorDialog", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::Editor::EditorDialog",
    v0);
  UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::EditorDialog>::`vftable;
  UFG::qReflectInventory<UFG::Editor::EditorDialog>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::EditorDialog_UFG::DUIWindow_::sInventory__);
}

// File Line: 22
// RVA: 0x218AD0
void __fastcall UFG::Editor::EditorDialog::UpdateUI(UFG::Editor::EditorDialog *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  UFG::Editor::EditorDialog *v3; // rbx
  int v4; // eax
  char v5; // al
  bool v6; // si
  bool v7; // bp

  v2 = dui;
  v3 = this;
  if ( this->mbHidden )
  {
    this->mRect.mW = 300;
    this->mRect.mH = 120;
    this->mRect.mX = dui->mInputState.mMousePos.mX - 150;
    v4 = dui->mInputState.mMousePos.mY;
    this->mbHidden = 0;
    this->mRect.mY = v4 - 60;
  }
  UFG::DUIContext::BeginVerticalLayout(dui);
  v5 = v2->mInputState.mKeycodeDown;
  v6 = v5 == 13;
  v7 = v5 == 27;
  v3->vfptr[2].__vecDelDtor((UFG::qReflectObject *)&v3->vfptr, (unsigned int)v2);
  UFG::DUIContext::Separator(v2);
  UFG::DUIContext::BeginGridLayout(v2, 2, 1, 4);
  if ( ((unsigned __int8)UFG::DUIContext::Button(v2, "OK", 0x10u) || v6)
    && (unsigned __int8)v3->vfptr[2].GetTypeName((UFG::qReflectObject *)&v3->vfptr) )
  {
    UFG::DUIContext::HideWindow(v2, (UFG::DUIWindow *)&v3->vfptr);
    v3->mbHidden = 1;
  }
  if ( (unsigned __int8)UFG::DUIContext::Button(v2, "Cancel", 0x10u) || v7 )
  {
    if ( ((unsigned __int8 (__fastcall *)(UFG::Editor::EditorDialog *))v3->vfptr[3].__vecDelDtor)(v3) )
    {
      UFG::DUIContext::HideWindow(v2, (UFG::DUIWindow *)&v3->vfptr);
      v3->mbHidden = 1;
    }
  }
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
}

