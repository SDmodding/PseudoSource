// File Line: 16
// RVA: 0x146CE40
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::EditorDialog_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::EditorDialog", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::sInventory,
    "UFG::Editor::EditorDialog",
    v0);
  UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::EditorDialog>::`vftable;
  UFG::qReflectInventory<UFG::Editor::EditorDialog>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::EditorDialog_UFG::DUIWindow_::sInventory__);
}

// File Line: 22
// RVA: 0x218AD0
void __fastcall UFG::Editor::EditorDialog::UpdateUI(UFG::Editor::EditorDialog *this, UFG::DUIContext *dui)
{
  int mY; // eax
  char mKeycodeDown; // al
  bool v6; // si
  bool v7; // bp

  if ( this->mbHidden )
  {
    this->mRect.mW = 300;
    this->mRect.mH = 120;
    this->mRect.mX = dui->mInputState.mMousePos.mX - 150;
    mY = dui->mInputState.mMousePos.mY;
    this->mbHidden = 0;
    this->mRect.mY = mY - 60;
  }
  UFG::DUIContext::BeginVerticalLayout(dui);
  mKeycodeDown = dui->mInputState.mKeycodeDown;
  v6 = mKeycodeDown == 13;
  v7 = mKeycodeDown == 27;
  this->UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr[2].__vecDelDtor(
    this,
    (unsigned int)dui);
  UFG::DUIContext::Separator(dui);
  UFG::DUIContext::BeginGridLayout(dui, 2, 1, LayoutFlag_DistributeCells);
  if ( (UFG::DUIContext::Button(dui, "OK", 0x10u) || v6)
    && this->UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr[2].GetTypeName(this) )
  {
    UFG::DUIContext::HideWindow(dui, this);
    this->mbHidden = 1;
  }
  if ( UFG::DUIContext::Button(dui, "Cancel", 0x10u) || v7 )
  {
    if ( ((unsigned __int8 (__fastcall *)(UFG::Editor::EditorDialog *))this->UFG::qReflectObjectType<UFG::Editor::EditorDialog,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr[3].__vecDelDtor)(this) )
    {
      UFG::DUIContext::HideWindow(dui, this);
      this->mbHidden = 1;
    }
  }
  UFG::DUIContext::EndLayoutHorizontal(dui);
  UFG::DUIContext::EndLayoutHorizontal(dui);
}

