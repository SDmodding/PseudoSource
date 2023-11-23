// File Line: 27
// RVA: 0x146C3B0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::InfoPanel_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::InfoPanel", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::sDeserializeOp,
    v0,
    (void (__fastcall *)(char *))UFG::OnLoadClass<UFG::Editor::InfoPanel>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 35
// RVA: 0x201A40
void __fastcall UFG::Editor::InfoPanel::InfoPanel(UFG::Editor::InfoPanel *this)
{
  UFG::DUIWindow::DUIWindow(this);
  this->UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mBaseNode.mUID = -1i64;
  this->mTypeUID = UFG::qStringHash64("UFG::Editor::InfoPanel", 0xFFFFFFFFFFFFFFFFui64);
  this->UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::UFG::DUIWindow::UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>::UFG::qReflectObject::vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::InfoPanel::`vftable{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>};
  this->UFG::qReflectObjectType<UFG::Editor::InfoPanel,UFG::DUIWindow>::UFG::DUIWindow::UFG::qSafePointerNode<UFG::DUIWindow>::vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::InfoPanel::`vftable{for `UFG::qSafePointerNode<UFG::DUIWindow>};
  this->mScrollPosition = 0i64;
  UFG::qString::Set(&this->mTitle, "Info");
}

// File Line: 41
// RVA: 0x218E80
void __fastcall UFG::Editor::InfoPanel::UpdateUI(UFG::Editor::InfoPanel *this, UFG::DUIContext *dui)
{
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> **p_mNext; // rbx
  int v5; // ecx
  UFG::qNode<UFG::Editor::HoverItem,UFG::Editor::HoverItem> *mNext; // r15
  UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *v7; // rax
  float v8; // xmm8_4
  float FOVVert; // xmm0_4
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v10; // rdi
  int v11; // ebx
  UFG::Editor::DAGPath *mPrev; // rbx
  UFG::Editor::SmartHandleObject *mPtr; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *p_mNode; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v15; // rax
  UFG::qSymbol *SystemName; // rax
  unsigned int mUID; // ebx
  const char *v18; // r14
  void *(__fastcall *vecDelDtor)(UFG::Editor::FnModifier *, unsigned int); // rbx
  unsigned int v20; // ecx
  UFG::Editor::FnObject *v21; // rax
  UFG::qBaseTreeRB *v22; // rax
  UFG::Editor::FnObject *v23; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v24; // rax
  int v25; // ecx
  unsigned int size; // edx
  UFG::Editor::FnModifier **p; // r8
  UFG::Editor::FnModifier *Modifier; // rax
  char *v29; // rax
  const char *v30; // r9
  UFG::qSymbol *v31; // rax
  char *v32; // rax
  const char *v33; // r9
  UFG::qSymbol *v34; // rax
  unsigned int v35; // edi
  UFG::Editor::DAGPathType::Enum mPathType; // edx
  UFG::Editor::SmartHandleObject *v37; // rax
  UFG::qBaseTreeRB *v38; // rax
  UFG::Editor::FnObject *v39; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v40; // rax
  UFG::qBaseNodeRB *SimObject; // rax
  bool v42; // al
  UFG::qBaseNodeRB *v43; // rbx
  char *v44; // rax
  UFG::SceneObjectProperties *v45; // rcx
  UFG::qSymbolUC *ArchetypePropertiesName; // rax
  char *v47; // rax
  UFG::Editor::FnModifier *Interface; // rax
  void *(__fastcall *v49)(UFG::Editor::FnModifier *, unsigned int); // rdi
  UFG::qBaseNodeRB *v50; // rbx
  char *v51; // rax
  const char *v52; // r9
  UFG::qSymbol *v53; // rax
  char *v54; // rax
  const char *v55; // r9
  char *v56; // rax
  const char *v57; // r9
  char *v58; // rax
  const char *v59; // r9
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v60; // rcx
  const char *TypeName; // rax
  UFG::qReflectObject *mData; // rcx
  char *Name; // rax
  const char *v64; // r9
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v65; // rcx
  const char *v66; // rax
  UFG::qReflectObject *v67; // rcx
  char *v68; // rax
  unsigned int *p_mStringHash32; // rbx
  UFG::qSymbol *v70; // rbx
  UFG::Editor::DAGPath path; // [rsp+30h] [rbp-D0h] BYREF
  int v72; // [rsp+90h] [rbp-70h]
  UFG::qReflectHandleBase v73; // [rsp+98h] [rbp-68h] BYREF
  __int64 v74; // [rsp+C0h] [rbp-40h]
  char dest[512]; // [rsp+D0h] [rbp-30h] BYREF
  UFG::Editor::DAGPath *result; // [rsp+320h] [rbp+220h] BYREF
  UFG::qSymbol v77; // [rsp+328h] [rbp+228h] BYREF
  UFG::Editor::DAGPath **p_result; // [rsp+330h] [rbp+230h]

  v74 = -2i64;
  v72 = 0;
  if ( !UFG::Editor::mInitialized
    || (p_mNext = &UFG::Editor::mViews.mNode.mNext[-1].mNext,
        &UFG::Editor::mViews.mNode.mNext[-1].mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8)) )
  {
LABEL_5:
    p_mNext = 0i64;
  }
  else
  {
    while ( !*((_BYTE *)p_mNext + 88) )
    {
      p_mNext = &p_mNext[2][-1].mNext;
      if ( p_mNext == (UFG::qNode<UFG::Editor::View,UFG::Editor::View> **)((char *)&UFG::Editor::mViews - 8) )
        goto LABEL_5;
    }
  }
  v5 = 0;
  mNext = UFG::Editor::mHoverObjectList.mNode.mNext;
  v7 = (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)UFG::Editor::mHoverObjectList.mNode.mNext;
  if ( (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)UFG::Editor::mHoverObjectList.mNode.mNext == &UFG::Editor::mHoverObjectList )
    goto LABEL_9;
  do
  {
    ++v5;
    v7 = (UFG::qList<UFG::Editor::HoverItem,UFG::Editor::HoverItem,1,0> *)v7->mNode.mNext;
  }
  while ( v7 != &UFG::Editor::mHoverObjectList );
  if ( v5 <= 0 )
LABEL_9:
    mNext = 0i64;
  UFG::DUIContext::BeginScrollView(dui, (UFG::qNode<UFG::DUILayoutState,UFG::DUILayoutState> *)&this->mScrollPosition);
  UFG::DUIContext::BeginVerticalLayout(dui);
  UFG::DUIContext::Separator(dui);
  UFG::qSPrintf(dest, 512, "Pivot Dist   : %.3f", COERCE_FLOAT(HIDWORD(p_mNext[10][6].mNext) & _xmm));
  UFG::DUIContext::Label(dui, dest);
  UFG::qSPrintf(dest, 512, "View Dim     : %d %d", LODWORD(p_mNext[9][2].mPrev), HIDWORD(p_mNext[9][2].mPrev));
  UFG::DUIContext::Label(dui, dest);
  UFG::qSPrintf(
    dest,
    512,
    "Aspect       : %f",
    (float)((float)SLODWORD(p_mNext[9][2].mPrev) / (float)SHIDWORD(p_mNext[9][2].mPrev)));
  UFG::DUIContext::Label(dui, dest);
  v8 = (float)(UFG::Editor::Camera::GetFOVHorz((UFG::Editor::Camera *)p_mNext[10]) * 180.0) * 0.31830987;
  FOVVert = UFG::Editor::Camera::GetFOVVert((UFG::Editor::Camera *)p_mNext[10]);
  UFG::qSPrintf(dest, 512, "FOV Horz Vert: %04.1f %04.1f", v8, (float)((float)(FOVVert * 180.0) * 0.31830987));
  UFG::DUIContext::Label(dui, dest);
  UFG::qSPrintf(
    dest,
    512,
    "Mouse        : %6.4f %6.4f",
    (float)((float)((float)((float)dui->mInputState.mMousePos.mX * 2.0) / (float)SLODWORD(p_mNext[9][2].mPrev)) - 1.0),
    (float)((float)((float)(1.0 - (float)((float)dui->mInputState.mMousePos.mY / (float)SHIDWORD(p_mNext[9][2].mPrev)))
                  * 2.0)
          - 1.0));
  UFG::DUIContext::Label(dui, dest);
  UFG::DUIContext::Separator(dui);
  v10 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v11 = (int)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext;
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
  memset(&path.mSubElements, 0, 20);
  if ( v11 == 1 )
  {
    mPrev = (UFG::Editor::DAGPath *)v10[4].mPrev;
    if ( mPrev != &path )
    {
      UFG::Editor::DAGPath::Clear(&path);
      if ( path.mPathType == Default )
      {
        mPtr = mPrev->mFnObject.mPtr;
        if ( !path.mFnObject.mPtr )
        {
          if ( mPtr )
          {
            path.mFnObject.mTypeId = mPtr->mTypeId;
            path.mFnObject.mPtr = mPtr;
            p_mNode = &mPtr->mSmartHandleList.mNode;
            v15 = p_mNode->mPrev;
            v15->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
            path.mFnObject.mPrev = v15;
            path.mFnObject.mNext = p_mNode;
            p_mNode->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
          }
        }
      }
      path.mSystemName.mUID = mPrev->mSystemName.mUID;
      UFG::qArray<UFG::qSymbol,0>::Clone(&mPrev->mElements, &path.mElements);
      path.mInterfaceName.mUID = mPrev->mInterfaceName.mUID;
      UFG::qArray<UFG::qString,0>::Clone(&mPrev->mSubElements, &path.mSubElements);
    }
  }
  SystemName = UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result);
  mUID = UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID;
  v18 = "Unknown";
  if ( SystemName->mUID == UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID )
  {
    if ( !path.mElements.size )
    {
      vecDelDtor = 0i64;
      goto LABEL_43;
    }
    v20 = path.mInterfaceName.mUID;
    LODWORD(result) = path.mInterfaceName.mUID;
    if ( path.mPathType == Half )
      goto LABEL_40;
    v21 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
    if ( path.mFnObject.mPtr )
      goto LABEL_30;
    if ( !path.mSystemName.mUID )
      goto LABEL_40;
    v22 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, path.mSystemName.mUID);
    if ( v22 && v22 != (UFG::qBaseTreeRB *)8 )
    {
      v23 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v22[-1].mCount, &path);
      v21 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
      if ( path.mFnObject.mPtr )
      {
LABEL_29:
        v20 = path.mInterfaceName.mUID;
LABEL_30:
        if ( v20 == -1 )
        {
          v25 = 0;
          size = v21->mFnModifiers.size;
          if ( size )
          {
            p = v21->mFnModifiers.p;
            while ( 1 )
            {
              Modifier = p[v25];
              if ( Modifier->mTypeID == -1570916174 )
                break;
              if ( ++v25 >= size )
                goto LABEL_35;
            }
          }
          else
          {
LABEL_35:
            Modifier = 0i64;
          }
        }
        else
        {
          Modifier = UFG::Editor::FnObject::GetModifier(v21, (UFG::qSymbol *)&result);
          if ( !Modifier || Modifier->mTypeID != -1570916174 )
            goto LABEL_40;
        }
        if ( Modifier )
        {
          vecDelDtor = Modifier[1].vfptr->__vecDelDtor;
          goto LABEL_41;
        }
LABEL_40:
        vecDelDtor = 0i64;
LABEL_41:
        if ( vecDelDtor )
        {
          v29 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)vecDelDtor + 16);
          goto LABEL_44;
        }
LABEL_43:
        v29 = 0i64;
LABEL_44:
        v30 = "Unknown";
        if ( v29 )
          v30 = v29;
        UFG::qSPrintf(dest, 512, "Selected Obj : %s", v30);
        UFG::DUIContext::Label(dui, dest);
        if ( vecDelDtor )
        {
          v31 = UFG::qPropertySet::Get<UFG::qSymbol>(
                  (UFG::qPropertySet *)vecDelDtor,
                  (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymObjectType,
                  DEPTH_RECURSE);
          if ( !v31 )
          {
            v32 = "Unknown";
LABEL_51:
            v33 = "Unknown";
            if ( v32 )
              v33 = v32;
            UFG::qSPrintf(dest, 512, "Selected Type: %s", v33);
            UFG::DUIContext::Label(dui, dest);
            mUID = UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID;
            goto LABEL_54;
          }
        }
        else
        {
          v31 = &UFG::gNullQSymbol;
        }
        v32 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v31);
        goto LABEL_51;
      }
      if ( !v23 )
        goto LABEL_40;
      path.mFnObject.mTypeId = v23->mTypeId;
      path.mFnObject.mPtr = v23;
      v24 = v23->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
      v24->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      path.mFnObject.mPrev = v24;
      path.mFnObject.mNext = &v23->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode;
      v23->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    }
    v21 = (UFG::Editor::FnObject *)path.mFnObject.mPtr;
    if ( !path.mFnObject.mPtr )
      goto LABEL_40;
    goto LABEL_29;
  }
LABEL_54:
  v34 = UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result);
  v35 = UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID;
  if ( v34->mUID != UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID )
    goto LABEL_78;
  if ( !path.mElements.size )
    goto LABEL_77;
  if ( UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result)->mUID != mUID )
  {
    v72 = 1;
    v42 = UFG::Editor::DAGPath::GetSystemName(&path, (UFG::qSymbol *)&result)->mUID != v35;
    v72 = 0;
    if ( v42 )
    {
      v43 = 0i64;
LABEL_74:
      if ( v43 )
      {
        v44 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v43[2].mChild);
        UFG::qSPrintf(dest, 512, "Selected Obj : %s", v44);
        UFG::DUIContext::Label(dui, dest);
        v45 = (UFG::SceneObjectProperties *)v43[2].mChild[1];
        if ( v45 )
        {
          ArchetypePropertiesName = (UFG::qSymbolUC *)UFG::SceneObjectProperties::GetArchetypePropertiesName(v45);
          v47 = UFG::qSymbol::as_cstr_dbg(ArchetypePropertiesName);
          UFG::qSPrintf(dest, 512, "ArchetypeProp: %s", v47);
          UFG::DUIContext::Label(dui, dest);
        }
      }
      goto LABEL_77;
    }
    SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, path.mElements.p);
LABEL_73:
    v43 = SimObject;
    goto LABEL_74;
  }
  mPathType = path.mPathType;
  if ( path.mPathType == Half )
    goto LABEL_77;
  v37 = path.mFnObject.mPtr;
  if ( path.mFnObject.mPtr )
  {
LABEL_67:
    if ( mPathType == Half )
      v37 = 0i64;
    SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, (unsigned int)v37[2].mSmartHandleList.mNode.mNext);
    goto LABEL_73;
  }
  if ( !path.mSystemName.mUID )
    goto LABEL_77;
  v38 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, path.mSystemName.mUID);
  if ( !v38 || v38 == (UFG::qBaseTreeRB *)8 )
    goto LABEL_65;
  v39 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v38[-1].mCount, &path);
  v37 = path.mFnObject.mPtr;
  if ( path.mFnObject.mPtr )
  {
LABEL_66:
    mPathType = path.mPathType;
    goto LABEL_67;
  }
  if ( v39 )
  {
    path.mFnObject.mTypeId = v39->mTypeId;
    path.mFnObject.mPtr = v39;
    v40 = v39->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev;
    v40->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    path.mFnObject.mPrev = v40;
    path.mFnObject.mNext = &v39->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode;
    v39->mSmartHandleList.UFG::Editor::SmartHandleObject::mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
LABEL_65:
    v37 = path.mFnObject.mPtr;
    if ( path.mFnObject.mPtr )
      goto LABEL_66;
  }
LABEL_77:
  UFG::qSPrintf(dest, 512, "Selected Type: SimObject");
  UFG::DUIContext::Label(dui, dest);
LABEL_78:
  UFG::DUIContext::Separator(dui);
  if ( mNext )
  {
    if ( UFG::Editor::DAGPath::GetSystemName((UFG::Editor::DAGPath *)&mNext[1], &v77)->mUID == UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID
      && LODWORD(mNext[3].mNext)
      && (p_result = &result,
          LODWORD(result) = mNext[4].mNext,
          (Interface = UFG::Editor::DAGPath::GetInterface(
                         (UFG::Editor::DAGPath *)&mNext[1],
                         0xA25DB8B2,
                         (UFG::qSymbol *)&result)) != 0i64) )
    {
      v49 = Interface[1].vfptr->__vecDelDtor;
    }
    else
    {
      v49 = 0i64;
    }
    if ( UFG::Editor::DAGPath::GetSystemName((UFG::Editor::DAGPath *)&mNext[1], (UFG::qSymbol *)&result)->mUID == UFG::Editor::DAGTypeSimObject::TYPE_SYMBOL.mUID )
      v50 = UFG::Editor::Core::CastToSimObject((UFG::Editor::DAGPath *)&mNext[1]);
    else
      v50 = 0i64;
    if ( v49 )
    {
      v51 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v49 + 16);
      v52 = "Unknown";
      if ( v51 )
        v52 = v51;
      UFG::qSPrintf(dest, 512, "Hover Obj    : %s", v52);
      UFG::DUIContext::Label(dui, dest);
      v53 = UFG::qPropertySet::Get<UFG::qSymbol>(
              (UFG::qPropertySet *)v49,
              (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymObjectType,
              DEPTH_RECURSE);
      if ( v53 )
        v54 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v53);
      else
        v54 = "Unknown";
      v55 = "Unknown";
      if ( v54 )
        v55 = v54;
      UFG::qSPrintf(dest, 512, "Hover Type   : %s", v55);
      UFG::DUIContext::Label(dui, dest);
    }
    if ( v50 )
    {
      v56 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v50[2].mChild);
      v57 = "Unknown";
      if ( v56 )
        v57 = v56;
      UFG::qSPrintf(dest, 512, "Hover Obj    : %s", v57);
      UFG::DUIContext::Label(dui, dest);
      UFG::qSPrintf(dest, 512, "Hover Type   : SimObject");
      UFG::DUIContext::Label(dui, dest);
    }
  }
  if ( UFG::Editor::mPhysicsCollisionModelName.mUID != -1
    || UFG::Editor::mPhysicsObjectPropertyHandleUid
    || UFG::Editor::mPhysicsSurfacePropertyHandleUid )
  {
    UFG::DUIContext::Separator(dui);
    if ( UFG::Editor::mPhysicsCollisionModelName.mUID != -1 )
    {
      v58 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&UFG::Editor::mPhysicsCollisionModelName);
      v59 = "Unknown";
      if ( v58 )
        v59 = v58;
      UFG::qSPrintf(dest, 512, "Fiz Coll Mod : %s", v59);
      UFG::DUIContext::Label(dui, dest);
    }
    if ( UFG::Editor::mPhysicsObjectPropertyHandleUid )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v73);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v60);
      v73.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v73, v73.mTypeUID, UFG::Editor::mPhysicsObjectPropertyHandleUid);
      mData = v73.mData;
      if ( !v73.mData )
      {
        UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v73);
        mData = v73.mData;
      }
      Name = UFG::qReflectObject::GetName(mData);
      v64 = "Unknown";
      if ( Name )
        v64 = Name;
      UFG::qSPrintf(dest, 512, "Fiz Obj Prop : %s", v64);
      UFG::DUIContext::Label(dui, dest);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v73);
    }
    if ( UFG::Editor::mPhysicsSurfacePropertyHandleUid )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v73);
      v66 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v65);
      v73.mTypeUID = UFG::qStringHash64(v66, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v73, v73.mTypeUID, UFG::Editor::mPhysicsSurfacePropertyHandleUid);
      v67 = v73.mData;
      if ( !v73.mData )
      {
        UFG::PhysicsPropertyManager::GetDefaultSurfaceProperties((UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *)&v73);
        v67 = v73.mData;
      }
      v68 = UFG::qReflectObject::GetName(v67);
      if ( v68 )
        v18 = v68;
      UFG::qSPrintf(dest, 512, "Fiz Surf Name: %s", v18);
      UFG::DUIContext::Label(dui, dest);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v73);
    }
  }
  UFG::DUIContext::EndLayoutHorizontal(dui);
  UFG::DUIContext::EndScrollView(dui);
  if ( path.mSubElements.p )
  {
    p_mStringHash32 = &path.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator(
      path.mSubElements.p,
      0x28ui64,
      path.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  if ( path.mElements.p )
  {
    v70 = path.mElements.p - 1;
    `eh vector destructor iterator(path.mElements.p, 4ui64, path.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v70);
  }
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(&path.mFnObject);
}

