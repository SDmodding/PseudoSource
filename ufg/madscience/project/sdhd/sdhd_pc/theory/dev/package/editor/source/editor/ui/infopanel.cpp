// File Line: 27
// RVA: 0x146C3B0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::InfoPanel_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::InfoPanel", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::Editor::InfoPanel>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 35
// RVA: 0x201A40
void __fastcall UFG::Editor::InfoPanel::InfoPanel(UFG::Editor::InfoPanel *this)
{
  UFG::Editor::InfoPanel *v1; // rbx

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::InfoPanel", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::InfoPanel::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::InfoPanel::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mScrollPosition = 0i64;
  UFG::qString::Set(&v1->mTitle, "Info");
}

// File Line: 41
// RVA: 0x218E80
void __fastcall UFG::Editor::InfoPanel::UpdateUI(UFG::Editor::InfoPanel *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rsi
  UFG::Editor::InfoPanel *v3; // rdx
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **v4; // rbx
  int v5; // ecx
  UFG::qNode<UFG::Editor::HoverItem,UFG::Editor::HoverItem> *v6; // r15
  UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *v7; // rax
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> *v8; // rcx
  float v9; // xmm8_4
  float v10; // xmm0_4
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v11; // rdi
  int v12; // ebx
  UFG::Editor::DAGPath *v13; // rbx
  UFG::Editor::SmartHandleObject *v14; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v15; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v16; // rax
  UFG::qSymbol *v17; // rax
  unsigned int v18; // ebx
  const char *v19; // r14
  void *(__fastcall *v20)(UFG::Editor::FnModifier *, unsigned int); // rbx
  unsigned int v21; // ecx
  UFG::Editor::FnObject *v22; // rax
  UFG::qBaseTreeRB *v23; // rax
  UFG::Editor::SmartHandleObject *v24; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v25; // rax
  int v26; // ecx
  unsigned int v27; // edx
  UFG::Editor::FnModifier **v28; // r8
  UFG::Editor::FnModifier *v29; // rax
  char *v30; // rax
  const char *v31; // r9
  UFG::qSymbol *v32; // rax
  char *v33; // rax
  const char *v34; // r9
  UFG::qSymbol *v35; // rax
  unsigned int v36; // edi
  UFG::Editor::DAGPathType::Enum v37; // edx
  UFG::Editor::SmartHandleObject *v38; // rax
  UFG::qBaseTreeRB *v39; // rax
  UFG::Editor::SmartHandleObject *v40; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v41; // rax
  UFG::qBaseNodeRB *v42; // rax
  bool v43; // al
  UFG::qBaseNodeRB *v44; // rbx
  char *v45; // rax
  UFG::SceneObjectProperties *v46; // rcx
  UFG::qSymbolUC *v47; // rax
  char *v48; // rax
  UFG::Editor::FnModifier *v49; // rax
  void *(__fastcall *v50)(UFG::Editor::FnModifier *, unsigned int); // rdi
  UFG::qBaseNodeRB *v51; // rbx
  char *v52; // rax
  const char *v53; // r9
  UFG::qSymbolUC *v54; // rax
  char *v55; // rax
  const char *v56; // r9
  char *v57; // rax
  const char *v58; // r9
  char *v59; // rax
  const char *v60; // r9
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v61; // rcx
  const char *v62; // rax
  UFG::qReflectObject *v63; // rcx
  char *v64; // rax
  const char *v65; // r9
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v66; // rcx
  const char *v67; // rax
  UFG::qReflectObject *v68; // rcx
  char *v69; // rax
  unsigned int *v70; // rbx
  UFG::qSymbol *v71; // rbx
  __int64 v72; // [rsp+20h] [rbp-E0h]
  UFG::Editor::DAGPath path; // [rsp+30h] [rbp-D0h]
  int v74; // [rsp+90h] [rbp-70h]
  UFG::qReflectHandleBase v75; // [rsp+98h] [rbp-68h]
  __int64 v76; // [rsp+C0h] [rbp-40h]
  char dest; // [rsp+D0h] [rbp-30h]
  UFG::Editor::DAGPath *result; // [rsp+320h] [rbp+220h]
  UFG::qSymbol v79; // [rsp+328h] [rbp+228h]
  UFG::Editor::DAGPath **v80; // [rsp+330h] [rbp+230h]

  v76 = -2i64;
  v2 = dui;
  v3 = this;
  v74 = 0;
  if ( UFG::Editor::mInitialized
    && (v4 = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext != (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
    while ( !*((_BYTE *)v4 + 88) )
    {
      v4 = &v4[2][-1].mNext;
      if ( v4 == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v4 = 0i64;
  }
  v5 = 0;
  v6 = UFG::Editor::mHoverObjectList.mNode.mNext;
  v7 = (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)UFG::Editor::mHoverObjectList.mNode.mNext;
  if ( (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)UFG::Editor::mHoverObjectList.mNode.mNext == &UFG::Editor::mHoverObjectList )
    goto LABEL_126;
  do
  {
    ++v5;
    v7 = (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)v7->mNode.mNext;
  }
  while ( v7 != &UFG::Editor::mHoverObjectList );
  if ( v5 <= 0 )
LABEL_126:
    v6 = 0i64;
  UFG::DUIContext::BeginScrollView(v2, &v3->mScrollPosition);
  UFG::DUIContext::BeginVerticalLayout(v2);
  UFG::DUIContext::Separator(v2);
  UFG::qSPrintf(&dest, 512, "Pivot Dist   : %.3f", COERCE_FLOAT(HIDWORD(v4[10][6].mNext) & _xmm));
  UFG::DUIContext::Label(v2, &dest);
  v8 = v4[9];
  LODWORD(v72) = HIDWORD(v8[2].mPrev);
  UFG::qSPrintf(&dest, 512, "View Dim     : %d %d", LODWORD(v8[2].mPrev), v72);
  UFG::DUIContext::Label(v2, &dest);
  UFG::qSPrintf(
    &dest,
    512,
    "Aspect       : %f",
    (float)((float)SLODWORD(v4[9][2].mPrev) / (float)SHIDWORD(v4[9][2].mPrev)));
  UFG::DUIContext::Label(v2, &dest);
  v9 = (float)(UFG::Editor::Camera::GetFOVHorz((UFG::Editor::Camera *)v4[10]) * 180.0) * 0.31830987;
  v10 = UFG::Editor::Camera::GetFOVVert((UFG::Editor::Camera *)v4[10]);
  UFG::qSPrintf(&dest, 512, "FOV Horz Vert: %04.1f %04.1f", v9, (float)((float)(v10 * 180.0) * 0.31830987));
  UFG::DUIContext::Label(v2, &dest);
  UFG::qSPrintf(
    &dest,
    512,
    "Mouse        : %6.4f %6.4f",
    (float)((float)((float)((float)v2->mInputState.mMousePos.mX * 2.0) / (float)SLODWORD(v4[9][2].mPrev)) - 1.0),
    (float)((float)((float)(1.0 - (float)((float)v2->mInputState.mMousePos.mY / (float)SHIDWORD(v4[9][2].mPrev))) * 2.0)
          - 1.0));
  UFG::DUIContext::Label(v2, &dest);
  UFG::DUIContext::Separator(v2);
  v11 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v12 = (int)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext;
  result = &path;
  path.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
  path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
  path.mFnObject.mPtr = 0i64;
  path.mFnObject.mTypeId = -1998658210;
  path.mSystemName.mUID = -1;
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&path.mElements, 4u, "qArray.Reallocate(Constructor)");
  path.mInterfaceName.mUID = -1;
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  path.mPathType = 0;
  if ( v12 == 1 )
  {
    v13 = (UFG::Editor::DAGPath *)v11[4].mPrev;
    if ( v13 != &path )
    {
      UFG::Editor::DAGPath::Clear(&path);
      if ( path.mPathType == Default )
      {
        v14 = v13->mFnObject.mPtr;
        if ( !path.mFnObject.mPtr )
        {
          if ( v14 )
          {
            path.mFnObject.mTypeId = v14->mTypeId;
            path.mFnObject.mPtr = v14;
            v15 = &v14->mSmartHandleList.mNode;
            v16 = v15->mPrev;
            v16->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
            path.mFnObject.mPrev = v16;
            path.mFnObject.mNext = v15;
            v15->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
          }
        }
      }
      path.mSystemName.mUID = v13->mSystemName.mUID;
      UFG::qArray<UFG::qSymbol,0>::Clone(&v13->mElements, &path.mElements);
      path.mInterfaceName.mUID = v13->mInterfaceName.mUID;
      UFG::qArray<UFG::qString,0>::Clone(&v13->mSubElements, &path.mSubElements);
    }
  }
  v17 = UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result);
  v18 = UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID;
  v19 = "Unknown";
  if ( v17->mUID == UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID )
  {
    if ( !path.mElements.size )
    {
      v20 = 0i64;
      goto LABEL_43;
    }
    v21 = path.mInterfaceName.mUID;
    LODWORD(result) = path.mInterfaceName.mUID;
    if ( path.mPathType == 1 )
      goto LABEL_40;
    v22 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
    if ( path.mFnObject.mPtr )
      goto LABEL_30;
    if ( !path.mSystemName.mUID )
      goto LABEL_40;
    v23 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, path.mSystemName.mUID);
    if ( v23 && v23 != (UFG::qBaseTreeRB *)8 )
    {
      v24 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v23[-1].mCount, &path);
      v22 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
      if ( path.mFnObject.mPtr )
      {
LABEL_29:
        v21 = path.mInterfaceName.mUID;
LABEL_30:
        if ( v21 == -1 )
        {
          v26 = 0;
          v27 = v22->mFnModifiers.size;
          if ( v27 )
          {
            v28 = v22->mFnModifiers.p;
            while ( 1 )
            {
              v29 = v28[v26];
              if ( v29->mTypeID == -1570916174 )
                break;
              if ( ++v26 >= v27 )
                goto LABEL_35;
            }
          }
          else
          {
LABEL_35:
            v29 = 0i64;
          }
        }
        else
        {
          v29 = UFG::Editor::FnObject::GetModifier(v22, (UFG::qSymbol *)&result);
          if ( !v29 || v29->mTypeID != -1570916174 )
            goto LABEL_40;
        }
        if ( v29 )
        {
          v20 = v29[1].vfptr->__vecDelDtor;
          goto LABEL_41;
        }
LABEL_40:
        v20 = 0i64;
LABEL_41:
        if ( v20 )
        {
          v30 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v20 + 16);
          goto LABEL_44;
        }
LABEL_43:
        v30 = 0i64;
LABEL_44:
        v31 = "Unknown";
        if ( v30 )
          v31 = v30;
        UFG::qSPrintf(&dest, 512, "Selected Obj : %s", v31);
        UFG::DUIContext::Label(v2, &dest);
        if ( v20 )
        {
          v32 = UFG::qPropertySet::Get<UFG::qSymbol>(
                  (UFG::qPropertySet *)v20,
                  (UFG::qSymbol *)&UFG::Editor::gsymObjectType.mUID,
                  DEPTH_RECURSE);
          if ( !v32 )
          {
            v33 = "Unknown";
LABEL_51:
            v34 = "Unknown";
            if ( v33 )
              v34 = v33;
            UFG::qSPrintf(&dest, 512, "Selected Type: %s", v34);
            UFG::DUIContext::Label(v2, &dest);
            v18 = UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID;
            goto LABEL_54;
          }
        }
        else
        {
          v32 = &UFG::gNullQSymbol;
        }
        v33 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v32);
        goto LABEL_51;
      }
      if ( !v24 )
        goto LABEL_40;
      path.mFnObject.mTypeId = v24->mTypeId;
      path.mFnObject.mPtr = v24;
      v25 = v24->mSmartHandleList.mNode.mPrev;
      v25->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      path.mFnObject.mPrev = v25;
      path.mFnObject.mNext = &v24->mSmartHandleList.mNode;
      v24->mSmartHandleList.mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    }
    v22 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
    if ( !path.mFnObject.mPtr )
      goto LABEL_40;
    goto LABEL_29;
  }
LABEL_54:
  v35 = UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result);
  v36 = UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID;
  if ( v35->mUID != UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID )
    goto LABEL_78;
  if ( !path.mElements.size )
    goto LABEL_77;
  if ( UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result)->mUID != v18 )
  {
    v74 = 1;
    v43 = UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result)->mUID != v36;
    v74 = 0;
    if ( v43 )
    {
      v44 = 0i64;
LABEL_74:
      if ( v44 )
      {
        v45 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v44[2].mChild);
        UFG::qSPrintf(&dest, 512, "Selected Obj : %s", v45);
        UFG::DUIContext::Label(v2, &dest);
        v46 = (UFG::SceneObjectProperties *)v44[2].mChild[1];
        if ( v46 )
        {
          v47 = (UFG::qSymbolUC *)UFG::SceneObjectProperties::GetArchetypePropertiesName(v46);
          v48 = UFG::qSymbol::as_cstr_dbg(v47);
          UFG::qSPrintf(&dest, 512, "ArchetypeProp: %s", v48);
          UFG::DUIContext::Label(v2, &dest);
        }
      }
      goto LABEL_77;
    }
    v42 = UFG::Simulation::GetSimObject(&UFG::gSim, path.mElements.p);
LABEL_73:
    v44 = v42;
    goto LABEL_74;
  }
  v37 = path.mPathType;
  if ( path.mPathType == 1 )
    goto LABEL_77;
  v38 = path.mFnObject.mPtr;
  if ( path.mFnObject.mPtr )
  {
LABEL_67:
    if ( v37 == 1 )
      v38 = 0i64;
    v42 = UFG::Simulation::GetSimObject(&UFG::gSim, (unsigned int)v38[2].mSmartHandleList.mNode.mNext);
    goto LABEL_73;
  }
  if ( !path.mSystemName.mUID )
    goto LABEL_77;
  v39 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, path.mSystemName.mUID);
  if ( !v39 || v39 == (UFG::qBaseTreeRB *)8 )
    goto LABEL_65;
  v40 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v39[-1].mCount, &path);
  v38 = path.mFnObject.mPtr;
  if ( path.mFnObject.mPtr )
  {
LABEL_66:
    v37 = path.mPathType;
    goto LABEL_67;
  }
  if ( v40 )
  {
    path.mFnObject.mTypeId = v40->mTypeId;
    path.mFnObject.mPtr = v40;
    v41 = v40->mSmartHandleList.mNode.mPrev;
    v41->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    path.mFnObject.mPrev = v41;
    path.mFnObject.mNext = &v40->mSmartHandleList.mNode;
    v40->mSmartHandleList.mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
LABEL_65:
    v38 = path.mFnObject.mPtr;
    if ( path.mFnObject.mPtr )
      goto LABEL_66;
  }
LABEL_77:
  UFG::qSPrintf(&dest, 512, "Selected Type: SimObject");
  UFG::DUIContext::Label(v2, &dest);
LABEL_78:
  UFG::DUIContext::Separator(v2);
  if ( v6 )
  {
    if ( UFG::Editor::DAGPath::GetSystemName((UFG::Editor::DAGPath *)&v6[1], &v79)->mUID == UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID
      && LODWORD(v6[3].mNext)
      && (v80 = &result,
          LODWORD(result) = v6[4].mNext,
          (v49 = UFG::Editor::DAGPath::GetInterface((UFG::Editor::DAGPath *)&v6[1], 0xA25DB8B2, (__int64)&result)) != 0i64) )
    {
      v50 = v49[1].vfptr->__vecDelDtor;
    }
    else
    {
      v50 = 0i64;
    }
    if ( UFG::Editor::DAGPath::GetSystemName((UFG::Editor::DAGPath *)&v6[1], (UFG::qSymbol *)&result)->mUID == UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID )
      v51 = UFG::Editor::Core::CastToSimObject((UFG::Editor::DAGPath *)&v6[1]);
    else
      v51 = 0i64;
    if ( v50 )
    {
      v52 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v50 + 16);
      v53 = "Unknown";
      if ( v52 )
        v53 = v52;
      UFG::qSPrintf(&dest, 512, "Hover Obj    : %s", v53);
      UFG::DUIContext::Label(v2, &dest);
      v54 = (UFG::qSymbolUC *)UFG::qPropertySet::Get<UFG::qSymbol>(
                                (UFG::qPropertySet *)v50,
                                (UFG::qSymbol *)&UFG::Editor::gsymObjectType.mUID,
                                DEPTH_RECURSE);
      if ( v54 )
        v55 = UFG::qSymbol::as_cstr_dbg(v54);
      else
        v55 = "Unknown";
      v56 = "Unknown";
      if ( v55 )
        v56 = v55;
      UFG::qSPrintf(&dest, 512, "Hover Type   : %s", v56);
      UFG::DUIContext::Label(v2, &dest);
    }
    if ( v51 )
    {
      v57 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v51[2].mChild);
      v58 = "Unknown";
      if ( v57 )
        v58 = v57;
      UFG::qSPrintf(&dest, 512, "Hover Obj    : %s", v58);
      UFG::DUIContext::Label(v2, &dest);
      UFG::qSPrintf(&dest, 512, "Hover Type   : SimObject");
      UFG::DUIContext::Label(v2, &dest);
    }
  }
  if ( UFG::Editor::mPhysicsCollisionModelName.mUID != -1
    || UFG::Editor::mPhysicsObjectPropertyHandleUid
    || UFG::Editor::mPhysicsSurfacePropertyHandleUid )
  {
    UFG::DUIContext::Separator(v2);
    if ( UFG::Editor::mPhysicsCollisionModelName.mUID != -1 )
    {
      v59 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&UFG::Editor::mPhysicsCollisionModelName);
      v60 = "Unknown";
      if ( v59 )
        v60 = v59;
      UFG::qSPrintf(&dest, 512, "Fiz Coll Mod : %s", v60);
      UFG::DUIContext::Label(v2, &dest);
    }
    if ( UFG::Editor::mPhysicsObjectPropertyHandleUid )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v75);
      v62 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v61);
      v75.mTypeUID = UFG::qStringHash64(v62, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v75, v75.mTypeUID, UFG::Editor::mPhysicsObjectPropertyHandleUid);
      v63 = v75.mData;
      if ( !v75.mData )
      {
        UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v75);
        v63 = v75.mData;
      }
      v64 = UFG::qReflectObject::GetName(v63);
      v65 = "Unknown";
      if ( v64 )
        v65 = v64;
      UFG::qSPrintf(&dest, 512, "Fiz Obj Prop : %s", v65);
      UFG::DUIContext::Label(v2, &dest);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v75);
    }
    if ( UFG::Editor::mPhysicsSurfacePropertyHandleUid )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v75);
      v67 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v66);
      v75.mTypeUID = UFG::qStringHash64(v67, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v75, v75.mTypeUID, UFG::Editor::mPhysicsSurfacePropertyHandleUid);
      v68 = v75.mData;
      if ( !v75.mData )
      {
        UFG::PhysicsPropertyManager::GetDefaultSurfaceProperties((UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *)&v75);
        v68 = v75.mData;
      }
      v69 = UFG::qReflectObject::GetName(v68);
      if ( v69 )
        v19 = v69;
      UFG::qSPrintf(&dest, 512, "Fiz Surf Name: %s", v19);
      UFG::DUIContext::Label(v2, &dest);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v75);
    }
  }
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::EndScrollView(v2);
  if ( path.mSubElements.p )
  {
    v70 = &path.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator'(
      path.mSubElements.p,
      0x28ui64,
      path.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v70);
  }
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  if ( path.mElements.p )
  {
    v71 = path.mElements.p - 1;
    `eh vector destructor iterator'(path.mElements.p, 4ui64, path.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v71);
  }
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(&path.mFnObject);
}

