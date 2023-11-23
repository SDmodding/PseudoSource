// File Line: 18
// RVA: 0x146C1F0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::AlignTool_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::AlignTool", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::AlignTool,UFG::DUIWindow>::sDeserializeOp,
    v0,
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::Editor::AlignTool>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 28
// RVA: 0x200F10
void __fastcall UFG::Editor::AlignTool::AlignTool(UFG::Editor::AlignTool *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::AlignTool,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::AlignTool,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::AlignTool,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::AlignTool,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::AlignTool", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::AlignTool,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::AlignTool::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::AlignTool,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::AlignTool::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  *(_WORD *)&this->mAlignTranslation = 257;
  this->mAlignScale = 1;
  UFG::qString::Set(&this->mTitle, "Align Tool");
  this->mRect.mH = 125;
}

// File Line: 34
// RVA: 0x204E70
void __fastcall UFG::Editor::AlignSelection(
        UFG::Editor::FnTransform *transform,
        UFG::Editor::SelectionSet *set,
        unsigned int startIndex,
        unsigned int endIndex,
        bool useTranslation,
        bool useRotation,
        bool useScale)
{
  __int64 v10; // rsi
  __int64 i; // r14
  UFG::Editor::DAGPath *v12; // rdi
  unsigned int mUID; // ebx
  unsigned int v14; // edx
  UFG::qBaseTreeRB *v15; // rax
  UFG::Editor::FnObject *v16; // rax
  unsigned int mTypeId; // ecx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *mPrev; // rax
  UFG::Editor::SmartHandleObject *mPtr; // rax
  unsigned int vfptr; // edx
  unsigned int v22; // ecx
  UFG::qBaseNodeRB *mParent; // rax
  UFG::qBaseNodeRB *v24; // rdi
  UFG::qBaseNodeRB *v25; // rax
  UFG::Editor::DAGPath *v26; // rbx
  unsigned int v27; // edx
  UFG::qBaseTreeRB *v28; // rax
  UFG::Editor::FnObject *v29; // rax
  unsigned int v30; // ecx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v31; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v32; // rax
  UFG::Editor::SmartHandleObject *v33; // rcx
  UFG::qBaseNodeRB *v34; // rax
  UFG::qBaseNodeRB *v35; // rax
  UFG::qMatrix44 v36; // [rsp+20h] [rbp-61h] BYREF
  __int128 v37[6]; // [rsp+60h] [rbp-21h] BYREF

  ((void (__fastcall *)(UFG::Editor::FnTransform *, __int128 *))transform->vfptr[1].ImplementsGizmoDrawing)(
    transform,
    v37);
  if ( startIndex < endIndex )
  {
    v10 = startIndex;
    for ( i = endIndex - startIndex; i; --i )
    {
      v12 = &set->mDAGPaths.p[v10];
      mUID = v12->mInterfaceName.mUID;
      if ( v12->mPathType == Half )
        goto LABEL_42;
      if ( !v12->mFnObject.mPtr )
      {
        v14 = v12->mSystemName.mUID;
        if ( v14 )
        {
          v15 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v14);
          if ( v15 )
          {
            if ( v15 != (UFG::qBaseTreeRB *)8 )
            {
              v16 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v15[-1].mCount, v12);
              if ( !v12->mFnObject.mPtr )
              {
                if ( v16 )
                {
                  mTypeId = v16->mTypeId;
                  v12->mFnObject.mPtr = v16;
                  v12->mFnObject.mTypeId = mTypeId;
                  p_mNode = &v16->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode;
                  mPrev = v16->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
                  mPrev->mNext = &v12->mFnObject;
                  v12->mFnObject.mPrev = mPrev;
                  v12->mFnObject.mNext = p_mNode;
                  p_mNode->mPrev = &v12->mFnObject;
                }
              }
            }
          }
        }
      }
      mPtr = v12->mFnObject.mPtr;
      if ( !mPtr )
        goto LABEL_42;
      vfptr = (unsigned int)mPtr[1].vfptr;
      v22 = 0;
      if ( v12->mInterfaceName.mUID == -1 )
      {
        if ( vfptr )
        {
          mParent = mPtr[1].mNode.mParent;
          while ( 1 )
          {
            v24 = mParent->mParent;
            if ( LODWORD(mParent->mParent->mChild[0]) == 1864359155 )
              break;
            ++v22;
            mParent = (UFG::qBaseNodeRB *)((char *)mParent + 8);
            if ( v22 >= vfptr )
              goto LABEL_17;
          }
        }
        else
        {
LABEL_17:
          v24 = 0i64;
        }
LABEL_26:
        if ( v24 )
        {
          v26 = &set->mDAGPaths.p[v10];
          if ( v26->mPathType != Half )
          {
            if ( !v26->mFnObject.mPtr )
            {
              v27 = v26->mSystemName.mUID;
              if ( v27 )
              {
                v28 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v27);
                if ( v28 )
                {
                  if ( v28 != (UFG::qBaseTreeRB *)8 )
                  {
                    v29 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v28[-1].mCount, v26);
                    if ( !v26->mFnObject.mPtr )
                    {
                      if ( v29 )
                      {
                        v30 = v29->mTypeId;
                        v26->mFnObject.mPtr = v29;
                        v26->mFnObject.mTypeId = v30;
                        v31 = &v29->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode;
                        v32 = v29->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
                        v32->mNext = &v26->mFnObject;
                        v26->mFnObject.mPrev = v32;
                        v26->mFnObject.mNext = v31;
                        v31->mPrev = &v26->mFnObject;
                      }
                    }
                  }
                }
              }
            }
            v33 = v26->mFnObject.mPtr;
            if ( v33 )
              ((void (__fastcall *)(UFG::Editor::SmartHandleObject *))v33->vfptr[4].__vecDelDtor)(v33);
          }
          v34 = v24->mParent;
          v36 = UFG::qMatrix44::msIdentity;
          (*(void (__fastcall **)(UFG::qBaseNodeRB *, UFG::qMatrix44 *))&v34[1].mUID)(v24, &v36);
          if ( useTranslation )
            v36.v3 = (UFG::qVector4)v37[3];
          if ( useRotation )
          {
            v36.v0 = (UFG::qVector4)v37[0];
            v36.v1 = (UFG::qVector4)v37[1];
            v36.v2 = (UFG::qVector4)v37[2];
          }
          ((void (__fastcall *)(UFG::qBaseNodeRB *, UFG::qMatrix44 *))v24->mParent[2].mParent)(v24, &v36);
        }
        goto LABEL_42;
      }
      if ( mUID == -1 )
      {
        if ( vfptr )
        {
          v25 = mPtr[1].mNode.mParent;
          while ( 1 )
          {
            v24 = v25->mParent;
            if ( LODWORD(v25->mParent->mChild[0]) == 1864359155 )
              break;
            ++v22;
            v25 = (UFG::qBaseNodeRB *)((char *)v25 + 8);
            if ( v22 >= vfptr )
              goto LABEL_23;
          }
        }
        else
        {
LABEL_23:
          v24 = 0i64;
        }
      }
      else
      {
        if ( !vfptr )
          goto LABEL_42;
        v35 = mPtr[1].mNode.mParent;
        while ( 1 )
        {
          v24 = v35->mParent;
          if ( HIDWORD(v35->mParent->mChild[0]) == mUID )
            break;
          ++v22;
          v35 = (UFG::qBaseNodeRB *)((char *)v35 + 8);
          if ( v22 >= vfptr )
            goto LABEL_42;
        }
      }
      if ( v24 && LODWORD(v24->mChild[0]) == 1864359155 )
        goto LABEL_26;
LABEL_42:
      ++v10;
    }
  }
}

// File Line: 65
// RVA: 0x217880
void __fastcall UFG::Editor::AlignTool::UpdateUI(UFG::Editor::AlignTool *this, UFG::DUIContext *context)
{
  UFG::Editor::SelectionSet *mNext; // rdi
  UFG::Editor::DAGPath *mPrev; // rcx
  UFG::Editor::FnTransform *Interface; // r12
  unsigned int size; // r13d
  UFG::Editor::DAGPath *v8; // rcx
  UFG::Editor::FnTransform *v9; // rbp
  UFG::qSymbol interfaceName; // [rsp+90h] [rbp+8h] BYREF
  UFG::qSymbol *p_interfaceName; // [rsp+A0h] [rbp+18h] BYREF
  UFG::qSymbol **p_p_interfaceName; // [rsp+A8h] [rbp+20h]

  UFG::DUIContext::BeginVerticalLayout(context);
  UFG::DUIContext::Checkbox(context, "Align Translation", &this->mAlignTranslation);
  UFG::DUIContext::Checkbox(context, "Align Rotation", &this->mAlignRotation);
  mNext = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  if ( UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext
    && LODWORD(UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext) > 1 )
  {
    mPrev = (UFG::Editor::DAGPath *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[4].mPrev;
    p_interfaceName = &interfaceName;
    interfaceName.mUID = mPrev->mInterfaceName.mUID;
    Interface = (UFG::Editor::FnTransform *)UFG::Editor::DAGPath::GetInterface(mPrev, 0x6F1FDCF3u, &interfaceName);
    size = mNext->mDAGPaths.size;
    v8 = &mNext->mDAGPaths.p[size - 1];
    p_p_interfaceName = &p_interfaceName;
    LODWORD(p_interfaceName) = v8->mInterfaceName.mUID;
    v9 = (UFG::Editor::FnTransform *)UFG::Editor::DAGPath::GetInterface(
                                       v8,
                                       0x6F1FDCF3u,
                                       (UFG::qSymbol *)&p_interfaceName);
    if ( Interface && UFG::DUIContext::Button(context, "Align To First Selected", 0x10u) )
      UFG::Editor::AlignSelection(
        Interface,
        mNext,
        1u,
        size,
        this->mAlignTranslation,
        this->mAlignRotation,
        this->mAlignScale);
    if ( v9 && UFG::DUIContext::Button(context, "Align To Last Selected", 0x10u) )
      UFG::Editor::AlignSelection(
        v9,
        mNext,
        0,
        size - 1,
        this->mAlignTranslation,
        this->mAlignRotation,
        this->mAlignScale);
  }
  UFG::DUIContext::EndLayoutHorizontal(context);
}

