// File Line: 32
// RVA: 0x2057B0
void __fastcall UFG::Editor::TSEditor::BindAtomics(UFG::Editor::TSEditor *this)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  sEditorClass = SSBrain::get_class("Editor");
  SSClass::register_method_func(sEditorClass, "select", UFG::Editor::TSEditor::Mthd_select, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    sEditorClass,
    "set_world_transform",
    UFG::Editor::TSEditor::Mthd_set_world_transform,
    1,
    rebinda);
}

// File Line: 42
// RVA: 0x20E080
void __fastcall UFG::Editor::TSEditor::Mthd_select(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::Editor::SelectionSet *mNext; // rbx
  SSInstance *i_data_p; // rax
  UFG::Editor::SelectionSet *v4; // rcx
  UFG::Editor::DAGPath *i_user_data; // rsi

  mNext = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  v4 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  i_user_data = (UFG::Editor::DAGPath *)i_data_p->i_user_data;
  LODWORD(UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext) = 0;
  UFG::Editor::SelectionSet::DispatchChangedEvent(v4);
  if ( (int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(&mNext->mDAGPaths, i_user_data) <= -1 )
  {
    UFG::qArray<UFG::Editor::DAGPath,0>::Add(&mNext->mDAGPaths, i_user_data, "qArray.Add");
    UFG::Editor::SelectionSet::DispatchChangedEvent(mNext);
  }
}

// File Line: 52
// RVA: 0x20E0F0
void __fastcall UFG::Editor::TSEditor::Mthd_set_world_transform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  unsigned __int64 i_user_data; // rdi
  UFG::Editor::FnObject *FnObject; // rax
  unsigned int size; // r8d
  int v6; // ecx
  UFG::Editor::FnModifier **i; // rdx
  UFG::Editor::FnModifier *v8; // rbx

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  FnObject = UFG::Editor::DAGPath::GetFnObject((UFG::Editor::DAGPath *)(*i_array_p)->i_data_p->i_user_data);
  if ( FnObject )
  {
    size = FnObject->mFnModifiers.size;
    v6 = 0;
    if ( size )
    {
      for ( i = FnObject->mFnModifiers.p; ; ++i )
      {
        v8 = *i;
        if ( (*i)->mTypeID == 1864359155 )
          break;
        if ( ++v6 >= size )
          return;
      }
      if ( v8 )
      {
        ((void (__fastcall *)(UFG::Editor::FnObject *))FnObject->vfptr[4].__vecDelDtor)(FnObject);
        ((void (__fastcall *)(UFG::Editor::FnModifier *, unsigned __int64))v8->vfptr[1].DrawGizmoHandles)(
          v8,
          i_user_data);
      }
    }
  }
}

