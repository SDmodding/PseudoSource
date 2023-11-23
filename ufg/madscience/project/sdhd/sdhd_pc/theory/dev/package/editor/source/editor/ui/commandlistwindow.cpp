// File Line: 3
// RVA: 0x146CDC0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::DUICommandListWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::DUICommandListWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::sInventory,
    "UFG::Editor::DUICommandListWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::DUICommandListWindow>::`vftable;
  UFG::qReflectInventory<UFG::Editor::DUICommandListWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    &UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::DUICommandListWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 18
// RVA: 0x201530
void __fastcall UFG::Editor::DUICommandListWindow::DUICommandListWindow(UFG::Editor::DUICommandListWindow *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::DUICommandListWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::DUICommandListWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::DUICommandListWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::DUICommandListWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mScrollPos = 0i64;
  UFG::qString::Set(&this->mTitle, "Command List");
}

// File Line: 23
// RVA: 0x218830
void __fastcall UFG::Editor::DUICommandListWindow::UpdateUI(
        UFG::Editor::DUICommandListWindow *this,
        UFG::DUIContext *dui)
{
  int v4; // edi
  UFG::CommandKeyBindingMap *i; // rbx
  int v6; // edx
  UFG::qString *v7; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  int v11; // eax
  UFG::qNode<UFG::qString,UFG::qString> *j; // rdx
  UFG::Command *k; // rbx
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx
  UFG::qString *m; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v20; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v21; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> options; // [rsp+20h] [rbp-21h] BYREF
  UFG::CommandContext context; // [rsp+38h] [rbp-9h] BYREF
  int current_index; // [rsp+A8h] [rbp+67h] BYREF
  UFG::qTreeRB<UFG::ContextDataBase,UFG::ContextDataBase,1> *p_mDictionary; // [rsp+B8h] [rbp+77h]

  UFG::DUIContext::BeginGridLayout(dui, 1, 2, LayoutFlag_FillLastCell);
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
    p_mDictionary = (UFG::qTreeRB<UFG::ContextDataBase,UFG::ContextDataBase,1> *)v7;
    if ( v7 )
    {
      UFG::qString::qString(v7, &i->mName);
      v9 = v8;
    }
    else
    {
      v9 = 0i64;
    }
    mPrev = options.mNode.mPrev;
    options.mNode.mPrev->mNext = v9;
    v9->mPrev = mPrev;
    v9->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&options;
    options.mNode.mPrev = v9;
  }
  if ( UFG::DUIContext::ComboBox(dui, &current_index, &options, 0i64, 0xFFFFFFFF) )
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
  context.vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable;
  p_mDictionary = &context.mDictionary;
  UFG::qBaseTreeRB::qBaseTreeRB(&context.mDictionary.mTree);
  UFG::DUIContext::BeginScrollView(dui, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mScrollPos);
  UFG::DUIContext::BeginVerticalLayout(dui);
  for ( k = (UFG::Command *)&UFG::gCommandManager->mCommandList.mNode.mNext[-1].mNext;
        k != (UFG::Command *)&UFG::gCommandManager[-1].mBindingMaps.mTree.mCount;
        k = (UFG::Command *)&k->mNext[-1].mNext )
  {
    UFG::DUIContext::CommandButton(dui, k, &context);
  }
  UFG::DUIContext::EndLayoutHorizontal(dui);
  UFG::DUIContext::EndScrollView(dui);
  context.vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable;
  p_mDictionary = &context.mDictionary;
  if ( context.mDictionary.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&context.mDictionary);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_20;
      p_mNode = &Head->mNode;
LABEL_21:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&context.mDictionary,
        p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mChild[0])(
          p_mCachedBufferPtr,
          1i64);
      if ( !context.mDictionary.mTree.mCount )
        goto LABEL_24;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_20:
    p_mNode = 0i64;
    goto LABEL_21;
  }
LABEL_24:
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&context.mDictionary);
  for ( m = (UFG::qString *)options.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)options.mNode.mNext != &options;
        m = (UFG::qString *)options.mNode.mNext )
  {
    v18 = m->mPrev;
    mNext = m->mNext;
    v18->mNext = mNext;
    mNext->mPrev = v18;
    m->mPrev = m;
    m->mNext = m;
    UFG::qString::~qString(m);
    operator delete[](m);
  }
  v20 = options.mNode.mPrev;
  v21 = options.mNode.mNext;
  options.mNode.mPrev->mNext = options.mNode.mNext;
  v21->mPrev = v20;
  UFG::DUIContext::EndLayoutHorizontal(dui);
}

