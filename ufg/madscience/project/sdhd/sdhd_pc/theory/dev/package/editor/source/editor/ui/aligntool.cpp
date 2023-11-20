// File Line: 18
// RVA: 0x146C1F0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::AlignTool_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::AlignTool", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::AlignTool,UFG::DUIWindow>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::Editor::AlignTool>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 28
// RVA: 0x200F10
void __fastcall UFG::Editor::AlignTool::AlignTool(UFG::Editor::AlignTool *this)
{
  UFG::Editor::AlignTool *v1; // rbx

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::AlignTool,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::AlignTool,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::AlignTool", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::AlignTool::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::AlignTool::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  *(_WORD *)&v1->mAlignTranslation = 257;
  v1->mAlignScale = 1;
  UFG::qString::Set(&v1->mTitle, "Align Tool");
  v1->mRect.mH = 125;
}

// File Line: 34
// RVA: 0x204E70
void __fastcall UFG::Editor::AlignSelection(UFG::Editor::FnTransform *transform, UFG::Editor::SelectionSet *set, unsigned int startIndex, unsigned int endIndex, bool useTranslation, bool useRotation, bool useScale)
{
  UFG::Editor::SelectionSet *v7; // r15
  unsigned int v8; // ebx
  unsigned int v9; // edi
  signed __int64 v10; // rsi
  __int64 v11; // r14
  UFG::Editor::DAGPath *v12; // rdi
  unsigned int v13; // ebx
  unsigned int v14; // edx
  UFG::qBaseTreeRB *v15; // rax
  UFG::Editor::FnObject *v16; // rax
  unsigned int v17; // ecx
  UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *v18; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v19; // rax
  UFG::Editor::SmartHandleObject *v20; // rax
  unsigned int v21; // edx
  unsigned int v22; // ecx
  UFG::qBaseNodeRB *v23; // rax
  UFG::qBaseNodeRB *v24; // rdi
  UFG::qBaseNodeRB *v25; // rax
  UFG::Editor::DAGPath *v26; // rbx
  unsigned int v27; // edx
  UFG::qBaseTreeRB *v28; // rax
  UFG::Editor::FnObject *v29; // rax
  unsigned int v30; // ecx
  UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *v31; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v32; // rax
  UFG::Editor::SmartHandleObject *v33; // rcx
  UFG::qBaseNodeRB *v34; // rax
  UFG::qBaseNodeRB *v35; // rax
  UFG::qMatrix44 v36; // [rsp+20h] [rbp-61h]
  UFG::qVector4 v37; // [rsp+60h] [rbp-21h]
  UFG::qVector4 v38; // [rsp+70h] [rbp-11h]
  UFG::qVector4 v39; // [rsp+80h] [rbp-1h]
  UFG::qVector4 v40; // [rsp+90h] [rbp+Fh]

  v7 = set;
  v8 = endIndex;
  v9 = startIndex;
  ((void (__fastcall *)(UFG::Editor::FnTransform *, UFG::qVector4 *))transform->vfptr[1].ImplementsGizmoDrawing)(
    transform,
    &v37);
  if ( v9 < v8 )
  {
    v10 = v9;
    v11 = v8 - v9;
    do
    {
      v12 = &v7->mDAGPaths.p[v10];
      v13 = v12->mInterfaceName.mUID;
      if ( v12->mPathType == 1 )
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
                  v17 = v16->mTypeId;
                  v12->mFnObject.mPtr = (UFG::Editor::SmartHandleObject *)&v16->vfptr;
                  v12->mFnObject.mTypeId = v17;
                  v18 = &v16->mSmartHandleList;
                  v19 = v16->mSmartHandleList.mNode.mPrev;
                  v19->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v12->mFnObject.mPrev;
                  v12->mFnObject.mPrev = v19;
                  v12->mFnObject.mNext = &v18->mNode;
                  v18->mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v12->mFnObject.mPrev;
                }
              }
            }
          }
        }
      }
      v20 = v12->mFnObject.mPtr;
      if ( !v20 )
        goto LABEL_42;
      v21 = (unsigned int)v20[1].vfptr;
      v22 = 0;
      if ( v12->mInterfaceName.mUID == -1 )
      {
        if ( v21 )
        {
          v23 = v20[1].mNode.mParent;
          while ( 1 )
          {
            v24 = v23->mParent;
            if ( LODWORD(v23->mParent->mChild[0]) == 1864359155 )
              break;
            ++v22;
            v23 = (UFG::qBaseNodeRB *)((char *)v23 + 8);
            if ( v22 >= v21 )
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
          v26 = &v7->mDAGPaths.p[v10];
          if ( v26->mPathType != 1 )
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
                        v26->mFnObject.mPtr = (UFG::Editor::SmartHandleObject *)&v29->vfptr;
                        v26->mFnObject.mTypeId = v30;
                        v31 = &v29->mSmartHandleList;
                        v32 = v29->mSmartHandleList.mNode.mPrev;
                        v32->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v26->mFnObject.mPrev;
                        v26->mFnObject.mPrev = v32;
                        v26->mFnObject.mNext = &v31->mNode;
                        v31->mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v26->mFnObject.mPrev;
                      }
                    }
                  }
                }
              }
            }
            v33 = v26->mFnObject.mPtr;
            if ( v33 )
              ((void (*)(void))v33->vfptr[4].__vecDelDtor)();
          }
          v34 = v24->mParent;
          v36 = UFG::qMatrix44::msIdentity;
          (*(void (__fastcall **)(UFG::qBaseNodeRB *, UFG::qMatrix44 *))&v34[1].mUID)(v24, &v36);
          if ( useTranslation == 1 )
            v36.v3 = v40;
          if ( useRotation == 1 )
          {
            v36.v0 = v37;
            v36.v1 = v38;
            v36.v2 = v39;
          }
          ((void (__fastcall *)(UFG::qBaseNodeRB *, UFG::qMatrix44 *))v24->mParent[2].mParent)(v24, &v36);
        }
        goto LABEL_42;
      }
      if ( v13 == -1 )
      {
        if ( v21 )
        {
          v25 = v20[1].mNode.mParent;
          while ( 1 )
          {
            v24 = v25->mParent;
            if ( LODWORD(v25->mParent->mChild[0]) == 1864359155 )
              break;
            ++v22;
            v25 = (UFG::qBaseNodeRB *)((char *)v25 + 8);
            if ( v22 >= v21 )
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
        if ( !v21 )
          goto LABEL_42;
        v35 = v20[1].mNode.mParent;
        while ( 1 )
        {
          v24 = v35->mParent;
          if ( HIDWORD(v35->mParent->mChild[0]) == v13 )
            break;
          ++v22;
          v35 = (UFG::qBaseNodeRB *)((char *)v35 + 8);
          if ( v22 >= v21 )
            goto LABEL_42;
        }
      }
      if ( v24 && LODWORD(v24->mChild[0]) == 1864359155 )
        goto LABEL_26;
LABEL_42:
      ++v10;
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 65
// RVA: 0x217880
void __fastcall UFG::Editor::AlignTool::UpdateUI(UFG::Editor::AlignTool *this, UFG::DUIContext *context)
{
  UFG::DUIContext *v2; // rbx
  UFG::Editor::AlignTool *v3; // rsi
  UFG::Editor::SelectionSet *v4; // rdi
  UFG::Editor::DAGPath *v5; // rcx
  UFG::Editor::FnTransform *v6; // r12
  unsigned int v7; // er13
  UFG::Editor::DAGPath *v8; // rcx
  UFG::Editor::FnTransform *v9; // rbp
  UFG::qSymbol interfaceName; // [rsp+90h] [rbp+8h]
  UFG::qSymbol *v11; // [rsp+A0h] [rbp+18h]
  UFG::qSymbol **v12; // [rsp+A8h] [rbp+20h]

  v2 = context;
  v3 = this;
  UFG::DUIContext::BeginVerticalLayout(context);
  UFG::DUIContext::Checkbox(v2, "Align Translation", &v3->mAlignTranslation);
  UFG::DUIContext::Checkbox(v2, "Align Rotation", &v3->mAlignRotation);
  v4 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  if ( UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext
    && LODWORD(UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext) > 1 )
  {
    v5 = (UFG::Editor::DAGPath *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[4].mPrev;
    v11 = &interfaceName;
    interfaceName.mUID = v5->mInterfaceName.mUID;
    v6 = (UFG::Editor::FnTransform *)UFG::Editor::DAGPath::GetInterface(v5, 0x6F1FDCF3u, (__int64)&interfaceName);
    v7 = v4->mDAGPaths.size;
    v8 = &v4->mDAGPaths.p[v7 - 1];
    v12 = &v11;
    LODWORD(v11) = v8->mInterfaceName.mUID;
    v9 = (UFG::Editor::FnTransform *)UFG::Editor::DAGPath::GetInterface(v8, 0x6F1FDCF3u, (__int64)&v11);
    if ( v6 && (unsigned __int8)UFG::DUIContext::Button(v2, "Align To First Selected", 0x10u) )
      UFG::Editor::AlignSelection(v6, v4, 1u, v7, v3->mAlignTranslation, v3->mAlignRotation, v3->mAlignScale);
    if ( v9 && (unsigned __int8)UFG::DUIContext::Button(v2, "Align To Last Selected", 0x10u) )
      UFG::Editor::AlignSelection(v9, v4, 0, v7 - 1, v3->mAlignTranslation, v3->mAlignRotation, v3->mAlignScale);
  }
  UFG::DUIContext::EndLayoutHorizontal(v2);
}

