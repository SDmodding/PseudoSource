// File Line: 32
// RVA: 0x2057B0
void __fastcall UFG::Editor::TSEditor::BindAtomics(UFG::Editor::TSEditor *this)
{
  sEditorClass = SSBrain::get_class("Editor");
  SSClass::register_method_func(sEditorClass, "select", UFG::Editor::TSEditor::Mthd_select, 1, 0);
  SSClass::register_method_func(
    sEditorClass,
    "set_world_transform",
    UFG::Editor::TSEditor::Mthd_set_world_transform,
    1,
    0);
}

// File Line: 42
// RVA: 0x20E080
void __fastcall UFG::Editor::TSEditor::Mthd_select(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::Editor::SelectionSet *v2; // rbx
  SSInstance *v3; // rax
  UFG::Editor::SelectionSet *v4; // rcx
  UFG::Editor::DAGPath *v5; // rsi

  v2 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  v4 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v5 = (UFG::Editor::DAGPath *)v3->i_user_data;
  LODWORD(UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext) = 0;
  UFG::Editor::SelectionSet::DispatchChangedEvent(v4);
  if ( (signed int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(&v2->mDAGPaths, v5) <= -1 )
  {
    UFG::qArray<UFG::Editor::DAGPath,0>::Add(&v2->mDAGPaths, v5, "qArray.Add");
    UFG::Editor::SelectionSet::DispatchChangedEvent(v2);
  }
}

// File Line: 52
// RVA: 0x20E0F0
void __fastcall UFG::Editor::TSEditor::Mthd_set_world_transform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  unsigned __int64 v3; // rdi
  UFG::Editor::SmartHandleObject *v4; // rax
  unsigned int v5; // er8
  unsigned int v6; // ecx
  UFG::qBaseNodeRB *v7; // rdx
  UFG::qBaseNodeRB *v8; // rbx

  v2 = pScope->i_data.i_array_p;
  v3 = v2[1]->i_data_p->i_user_data;
  v4 = UFG::Editor::DAGPath::GetFnObject((UFG::Editor::DAGPath *)(*v2)->i_data_p->i_user_data);
  if ( v4 )
  {
    v5 = (unsigned int)v4[1].vfptr;
    v6 = 0;
    if ( v5 )
    {
      v7 = v4[1].mNode.mParent;
      while ( 1 )
      {
        v8 = v7->mParent;
        if ( LODWORD(v7->mParent->mChild[0]) == 1864359155 )
          break;
        ++v6;
        v7 = (UFG::qBaseNodeRB *)((char *)v7 + 8);
        if ( v6 >= v5 )
          return;
      }
      if ( v8 )
      {
        ((void (__fastcall *)(UFG::Editor::SmartHandleObject *))v4->vfptr[4].__vecDelDtor)(v4);
        ((void (__fastcall *)(UFG::qBaseNodeRB *, unsigned __int64))v8->mParent[2].mParent)(v8, v3);
      }
    }
  }
}

