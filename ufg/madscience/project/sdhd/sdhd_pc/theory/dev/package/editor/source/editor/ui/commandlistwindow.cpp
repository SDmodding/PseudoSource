// File Line: 3
// RVA: 0x146CDC0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::DUICommandListWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::DUICommandListWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::Editor::DUICommandListWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::DUICommandListWindow>::`vftable';
  UFG::qReflectInventory<UFG::Editor::DUICommandListWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::DUICommandListWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 18
// RVA: 0x201530
void __fastcall UFG::Editor::DUICommandListWindow::DUICommandListWindow(UFG::Editor::DUICommandListWindow *this)
{
  UFG::Editor::DUICommandListWindow *v1; // rbx

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::DUICommandListWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::DUICommandListWindow::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::DUICommandListWindow::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mScrollPos = 0i64;
  UFG::qString::Set(&v1->mTitle, "Command List");
}

// File Line: 23
// RVA: 0x218830
void __fastcall UFG::Editor::DUICommandListWindow::UpdateUI(UFG::Editor::DUICommandListWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rsi
  UFG::Editor::DUICommandListWindow *v3; // r14
  signed int v4; // edi
  UFG::CommandKeyBindingMap *i; // rbx
  int v6; // edx
  UFG::qString *v7; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rax
  int v11; // eax
  UFG::qNode<UFG::qString,UFG::qString> *j; // rdx
  UFG::Command *k; // rbx
  Render::SkinningCacheNode *v14; // rax
  signed __int64 v15; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v16; // rdx
  UFG::qString *l; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v19; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+20h] [rbp-21h]
  UFG::CommandContext context; // [rsp+38h] [rbp-9h]
  int current_index; // [rsp+A8h] [rbp+67h]
  char *retaddr; // [rsp+B8h] [rbp+77h]

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginGridLayout(dui, 1, 2, 3);
  current_index = 0;
  options.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  options.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
  v4 = -1;
  for ( i = (UFG::CommandKeyBindingMap *)UFG::qTree64Base::GetHead(&UFG::gCommandManager->mBindingMaps.mTree);
        i;
        i = (UFG::CommandKeyBindingMap *)UFG::qTree64Base::GetNext(
                                           &UFG::gCommandManager->mBindingMaps.mTree,
                                           &i->mBaseNode) )
  {
    ++v4;
    v6 = current_index;
    if ( i == UFG::gCommandManager->mActiveBindingMap )
      v6 = v4;
    current_index = v6;
    v7 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
    retaddr = (char *)v7;
    if ( v7 )
    {
      UFG::qString::qString(v7, &i->mName);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    v10 = options.mNode.mPrev;
    options.mNode.mPrev->mNext = v9;
    v9->mPrev = v10;
    v9->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
    options.mNode.mPrev = v9;
  }
  if ( UFG::DUIContext::ComboBox(v2, &current_index, &options, 0i64, 0xFFFFFFFF) )
  {
    v11 = current_index;
    for ( j = options.mNode.mNext; v11 > 0; j = j->mNext )
    {
      if ( j == (UFG::qNode<UFG::qString,UFG::qString> *)&options )
        break;
      --v11;
    }
    UFG::CommandManager::SetActiveBindingMap(UFG::gCommandManager, (const char *)j[1].mNext);
  }
  context.vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable';
  retaddr = (char *)&context.mDictionary;
  UFG::qBaseTreeRB::qBaseTreeRB(&context.mDictionary.mTree);
  UFG::DUIContext::BeginScrollView(v2, &v3->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(v2);
  for ( k = (UFG::Command *)&UFG::gCommandManager->mCommandList.mNode.mNext[-1].mNext;
        k != (UFG::Command *)&UFG::gCommandManager[-1].mBindingMaps.mTree.mCount;
        k = (UFG::Command *)&k->mNext[-1].mNext )
  {
    UFG::DUIContext::CommandButton(v2, k, &context);
  }
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::EndScrollView(v2);
  context.vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable';
  retaddr = (char *)&context.mDictionary;
  if ( context.mDictionary.mTree.mCount )
  {
    while ( 1 )
    {
      v14 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&context.mDictionary);
      if ( !v14 )
        break;
      v15 = (signed __int64)&v14[-1].mCachedBufferPtr;
      if ( v14 == (Render::SkinningCacheNode *)8 )
        goto LABEL_20;
      v16 = &v14->mNode;
LABEL_21:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&context.mDictionary,
        v16);
      if ( v15 )
        (*(void (__fastcall **)(signed __int64, signed __int64))(*(_QWORD *)v15 + 8i64))(v15, 1i64);
      if ( !context.mDictionary.mTree.mCount )
        goto LABEL_24;
    }
    v15 = 0i64;
LABEL_20:
    v16 = 0i64;
    goto LABEL_21;
  }
LABEL_24:
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&context.mDictionary);
  for ( l = (UFG::qString *)options.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
        l = (UFG::qString *)options.mNode.mNext )
  {
    v18 = l->mPrev;
    v19 = l->mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    l->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&l->mPrev;
    l->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&l->mPrev;
    UFG::qString::~qString(l);
    operator delete[](l);
  }
  v20 = options.mNode.mPrev;
  v21 = options.mNode.mNext;
  options.mNode.mPrev->mNext = options.mNode.mNext;
  v21->mPrev = v20;
  UFG::DUIContext::EndLayoutHorizontal(v2);
}

