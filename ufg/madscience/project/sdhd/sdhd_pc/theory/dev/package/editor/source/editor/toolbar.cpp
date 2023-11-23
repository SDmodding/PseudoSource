// File Line: 15
// RVA: 0x146D640
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::ToolbarWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::ToolbarWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::sInventory,
    "UFG::Editor::ToolbarWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::ToolbarWindow>::`vftable;
  UFG::qReflectInventory<UFG::Editor::ToolbarWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::ToolbarWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 21
// RVA: 0x202D90
void __fastcall UFG::Editor::ToolbarWindow::ToolbarWindow(UFG::Editor::ToolbarWindow *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::ToolbarWindow", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::ToolbarWindow::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::ToolbarWindow,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::ToolbarWindow::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  UFG::qString::Set(&this->mTitle, "Toolbar");
  this->mStyle = Style_Toolbar;
}

// File Line: 34
// RVA: 0x21D8D0
// bad sp value at call has been detected, the output may be wrong!
void __fastcall UFG::Editor::ToolbarWindow::UpdateUI(UFG::Editor::ToolbarWindow *this, UFG::DUIContext *dui)
{
  int i; // r12d
  UFG::DUIRect *LayoutRect; // r15
  int mX; // ebx
  int v6; // r14d
  int v7; // r11d
  int v8; // ecx
  int v9; // eax
  int v10; // esi
  int mY; // r10d
  int v12; // edi
  int v13; // edx
  int v14; // r9d
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  UFG::Command **v18; // rbx
  UFG::DUIContext *v19; // rax
  int v20; // edx
  int *v21; // rax
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx
  UFG::qArray<UFG::Command *,0> commands; // [rsp+0h] [rbp-59h] BYREF
  UFG::DUIRect result; // [rsp+10h] [rbp-49h] BYREF
  UFG::CommandContext context; // [rsp+20h] [rbp-39h] BYREF
  __int64 v28; // [rsp+70h] [rbp+17h]
  UFG::DUIRect v29; // [rsp+78h] [rbp+1Fh] BYREF
  UFG::qTreeRB<UFG::ContextDataBase,UFG::ContextDataBase,1> *p_mDictionary; // [rsp+C0h] [rbp+67h]

  v28 = -2i64;
  this->mRect.mW = width;
  this->mRect.mH = height;
  UFG::DUIContext::BeginVerticalLayout(dui);
  *(_QWORD *)&commands.size = 0i64;
  UFG::CommandManager::GetCommandsByTag(UFG::gCommandManager, "WorldEditor.Toolbar", &commands);
  p_mDictionary = &context.mDictionary;
  UFG::qBaseTreeRB::qBaseTreeRB(&context.mDictionary.mTree);
  for ( i = 0; i < (int)commands.size; ++i )
  {
    UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
    LayoutRect = UFG::DUIContext::GetLayoutRect(dui, &v29, 0, 0);
    mX = result.mX;
    v6 = result.mX + result.mW;
    v7 = LayoutRect->mX + LayoutRect->mW;
    v8 = result.mX;
    if ( LayoutRect->mX < result.mX )
      v8 = LayoutRect->mX;
    v9 = LayoutRect->mX + LayoutRect->mW;
    if ( v8 < v7 )
      v9 = v8;
    v10 = result.mX + result.mW;
    if ( v9 < v6 )
      v10 = v9;
    mY = result.mY;
    v12 = result.mY + result.mH;
    v13 = LayoutRect->mY;
    v14 = v13 + LayoutRect->mH;
    v15 = result.mY;
    if ( v13 < result.mY )
      v15 = LayoutRect->mY;
    v16 = v13 + LayoutRect->mH;
    if ( v15 < v14 )
      v16 = v15;
    v17 = result.mY + result.mH;
    if ( v16 < v12 )
      v17 = v16;
    if ( LayoutRect->mX > result.mX )
      mX = LayoutRect->mX;
    if ( mX > v7 )
      v7 = mX;
    if ( v7 > v6 )
      v6 = v7;
    if ( v13 > result.mY )
      mY = LayoutRect->mY;
    if ( mY > v14 )
      v14 = mY;
    if ( v14 > v12 )
      v12 = v14;
    LayoutRect->mX = v10;
    LayoutRect->mY = v17;
    LayoutRect->mW = v6 - v10;
    LayoutRect->mH = v12 - v17;
    v18 = &commands.p[i];
    v19 = UFG::DUIContext::SetLayoutRect(dui, &result);
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
    UFG::DUIContext::Separator(dui);
LABEL_31:
    ;
  }
  UFG::DUIContext::EndLayoutHorizontal(dui);
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
        goto LABEL_37;
      p_mNode = &Head->mNode;
LABEL_38:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&context.mDictionary,
        p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mChild[0])(
          p_mCachedBufferPtr,
          1i64);
      if ( !context.mDictionary.mTree.mCount )
        goto LABEL_41;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_37:
    p_mNode = 0i64;
    goto LABEL_38;
  }
LABEL_41:
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&context.mDictionary);
  if ( commands.p )
    operator delete[](commands.p);
}

