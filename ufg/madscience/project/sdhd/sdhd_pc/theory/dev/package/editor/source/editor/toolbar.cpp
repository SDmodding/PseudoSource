// File Line: 15
// RVA: 0x146D640
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::ToolbarWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::ToolbarWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::Editor::ToolbarWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::ToolbarWindow>::`vftable;
  UFG::qReflectInventory<UFG::Editor::ToolbarWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::ToolbarWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 21
// RVA: 0x202D90
void __fastcall UFG::Editor::ToolbarWindow::ToolbarWindow(UFG::Editor::ToolbarWindow *this)
{
  UFG::Editor::ToolbarWindow *v1; // rbx

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::ToolbarWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::ToolbarWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::ToolbarWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::Set(&v1->mTitle, "Toolbar");
  v1->mStyle = 165;
}

// File Line: 34
// RVA: 0x21D8D0
void __fastcall UFG::Editor::ToolbarWindow::UpdateUI(UFG::Editor::ToolbarWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // r13
  signed int i; // er12
  UFG::DUIRect *v4; // r15
  int v5; // ebx
  int v6; // er14
  int v7; // er11
  int v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // er10
  int v12; // edi
  int v13; // edx
  int v14; // er9
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  UFG::Command **v18; // rbx
  UFG::DUIContext *v19; // rax
  int v20; // edx
  int *v21; // rax
  Render::SkinningCacheNode *v22; // rax
  signed __int64 v23; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v24; // rdx
  UFG::qArray<UFG::Command *,0> commands; // [rsp+0h] [rbp-59h]
  UFG::DUIRect result; // [rsp+10h] [rbp-49h]
  UFG::CommandContext context; // [rsp+20h] [rbp-39h]
  __int64 v28; // [rsp+70h] [rbp+17h]
  UFG::DUIRect v29; // [rsp+78h] [rbp+1Fh]
  UFG::qTreeRB<UFG::ContextDataBase,UFG::ContextDataBase,1> *v30; // [rsp+C0h] [rbp+67h]

  v28 = -2i64;
  v2 = dui;
  this->mRect.mW = width;
  this->mRect.mH = height;
  UFG::DUIContext::BeginVerticalLayout(dui);
  *(_QWORD *)&commands.size = 0i64;
  UFG::CommandManager::GetCommandsByTag(UFG::gCommandManager, "WorldEditor.Toolbar", &commands);
  v30 = &context.mDictionary;
  UFG::qBaseTreeRB::qBaseTreeRB(&context.mDictionary.mTree);
  for ( i = 0; i < (signed int)commands.size; ++i )
  {
    UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
    v4 = UFG::DUIContext::GetLayoutRect(v2, &v29, 0, 0);
    v5 = result.mX;
    v6 = result.mX + result.mW;
    v7 = v4->mX + v4->mW;
    v8 = result.mX;
    if ( v4->mX < result.mX )
      v8 = v4->mX;
    v9 = v4->mX + v4->mW;
    if ( v8 < v7 )
      v9 = v8;
    v10 = result.mX + result.mW;
    if ( v9 < v6 )
      v10 = v9;
    v11 = result.mY;
    v12 = result.mY + result.mH;
    v13 = v4->mY;
    v14 = v13 + v4->mH;
    v15 = result.mY;
    if ( v13 < result.mY )
      v15 = v4->mY;
    v16 = v13 + v4->mH;
    if ( v15 < v14 )
      v16 = v15;
    v17 = result.mY + result.mH;
    if ( v16 < v12 )
      v17 = v16;
    if ( v4->mX > result.mX )
      v5 = v4->mX;
    if ( v5 > v7 )
      v7 = v5;
    if ( v7 > v6 )
      v6 = v7;
    if ( v13 > result.mY )
      v11 = v4->mY;
    if ( v11 > v14 )
      v14 = v11;
    if ( v14 > v12 )
      v12 = v14;
    v4->mX = v10;
    v4->mY = v17;
    v4->mW = v6 - v10;
    v4->mH = v12 - v17;
    result.mX = v10;
    result.mY = v4->mY;
    result.mW = v4->mW;
    result.mH = v4->mH;
    v18 = &commands.p[i];
    v19 = UFG::DUIContext::SetLayoutRect(v2, &result);
    UFG::DUIContext::CommandImageButton(v19, *v18, &context);
    v20 = 0;
    v21 = seps;
    while ( i != *v21 )
    {
      ++v20;
      ++v21;
      if ( (unsigned __int64)v20 >= 4 )
        goto LABEL_31;
    }
    UFG::DUIContext::Separator(v2);
LABEL_31:
    ;
  }
  UFG::DUIContext::EndLayoutHorizontal(v2);
  context.vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable;
  v30 = &context.mDictionary;
  if ( context.mDictionary.mTree.mCount )
  {
    while ( 1 )
    {
      v22 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&context.mDictionary);
      if ( !v22 )
        break;
      v23 = (signed __int64)&v22[-1].mCachedBufferPtr;
      if ( v22 == (Render::SkinningCacheNode *)8 )
        goto LABEL_37;
      v24 = &v22->mNode;
LABEL_38:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&context.mDictionary,
        v24);
      if ( v23 )
        (*(void (__fastcall **)(signed __int64, signed __int64))(*(_QWORD *)v23 + 8i64))(v23, 1i64);
      if ( !context.mDictionary.mTree.mCount )
        goto LABEL_41;
    }
    v23 = 0i64;
LABEL_37:
    v24 = 0i64;
    goto LABEL_38;
  }
LABEL_41:
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&context.mDictionary);
  if ( commands.p )
    operator delete[](commands.p);
}:
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&context.mDictionary);
  if ( commands.p )
    operator delete[](comm

