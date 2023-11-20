// File Line: 38
// RVA: 0x146C5B0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::SceneLayerListWindow_UFG::DUIWindow_::sDeserializeOp__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::Editor::SceneLayerListWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::SerializeOperation::SerializeOperation(
    &UFG::qReflectObjectType<UFG::Editor::SceneLayerListWindow,UFG::DUIWindow>::sDeserializeOp,
    v0,
    UFG::OnLoadClass<UFG::Editor::SceneLayerListWindow>,
    (void (__fastcall *)(char *))UFG::OnUnloadClass<UITest::HandleArrayTest>);
}

// File Line: 39
// RVA: 0x146D440
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::Editor::SceneLayerPropertiesWindow_UFG::DUIWindow_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::Editor::SceneLayerPropertiesWindow", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::sInventory.vfptr,
    "UFG::Editor::SceneLayerPropertiesWindow",
    v0);
  UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::Editor::SceneLayerPropertiesWindow>::`vftable';
  UFG::qReflectInventory<UFG::Editor::SceneLayerPropertiesWindow>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::Editor::SceneLayerPropertiesWindow_UFG::DUIWindow_::sInventory__);
}

// File Line: 55
// RVA: 0x146DBB0
__int64 UFG::Editor::SceneManager::_dynamic_initializer_for__gWorkingLayerPath__()
{
  unk_142040910 = 0i64;
  unk_142040918 = -1998658210;
  unk_142040920 = -1;
  stru_142040928.p = 0i64;
  *(_QWORD *)&stru_142040928.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&stru_142040928, 4u, "qArray.Reallocate(Constructor)");
  unk_142040938 = -1;
  qword_142040948 = 0i64;
  unk_142040940 = 0i64;
  unk_142040950 = 0;
  return atexit(UFG::Editor::SceneManager::_dynamic_atexit_destructor_for__gWorkingLayerPath__);
}

// File Line: 57
// RVA: 0x146D770
__int64 UFG::Editor::SceneManager::_dynamic_initializer_for__SceneFilePath__()
{
  UFG::qString::qString(&SceneFilePath);
  return atexit(UFG::Editor::SceneManager::_dynamic_atexit_destructor_for__SceneFilePath__);
}

// File Line: 58
// RVA: 0x146D790
__int64 UFG::Editor::SceneManager::_dynamic_initializer_for__SceneLayerList__()
{
  return atexit(UFG::Editor::SceneManager::_dynamic_atexit_destructor_for__SceneLayerList__);
}

// File Line: 88
// RVA: 0x212740
char __fastcall UFG::Editor::SceneManager::SceneLayerNameExists(const char *layerName)
{
  int v1; // eax
  UFG::qNode<UFG::qString,UFG::qString> *v2; // rbx
  int v3; // edi

  v1 = UFG::qStringHashUpper32(layerName, 0xFFFFFFFF);
  v2 = SceneLayerList.mNode.mNext;
  v3 = v1;
  if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)SceneLayerList.mNode.mNext == &SceneLayerList )
    return 0;
  while ( 1 )
  {
    if ( HIDWORD(v2[2].mPrev) == -1 )
      HIDWORD(v2[2].mPrev) = UFG::qStringHashUpper32((const char *)v2[1].mNext, 0xFFFFFFFF);
    if ( HIDWORD(v2[2].mPrev) == v3 )
      break;
    v2 = v2->mNext;
    if ( v2 == (UFG::qNode<UFG::qString,UFG::qString> *)&SceneLayerList )
      return 0;
  }
  return 1;
}

// File Line: 124
// RVA: 0x213450
void __fastcall UFG::Editor::SceneManager::SetWorkingLayer(UFG::SceneLayer *workingLayer)
{
  UFG::SceneLayer *v1; // rbx
  __int64 v2; // rcx
  void **v3; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v4; // rdx

  v1 = workingLayer;
  UFG::Editor::DAGPath::Clear(&gWorkingLayerPath);
  if ( v1 )
  {
    unk_142040920 = UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID;
    UFG::qArray<UFG::qSymbol,0>::Add(&stru_142040928, (UFG::qSymbol *)&v1->mNode.mUID, "qArray.Add");
    v2 = unk_142040910;
    if ( unk_142040910 )
    {
      v3 = off_142040908;
      v4 = gWorkingLayerPath.mFnObject.mPrev;
      gWorkingLayerPath.mFnObject.mPrev->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)off_142040908;
      *v3 = v4;
      gWorkingLayerPath.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&gWorkingLayerPath;
      off_142040908 = (void **)&gWorkingLayerPath;
      if ( *(_QWORD *)(v2 + 48) == v2 + 40 )
      {
        if ( v2 )
          (**(void (__fastcall ***)(__int64, signed __int64))v2)(v2, 1i64);
      }
    }
    unk_142040910 = 0i64;
  }
}

// File Line: 153
// RVA: 0x206810
UFG::SceneLayer *__fastcall UFG::Editor::SceneManager::CreateSceneLayer(UFG::qSymbol *sceneLayerName)
{
  UFG::qSymbol *v1; // rdi
  char *v2; // rax
  char *v3; // rax
  UFG::qBaseTreeRB *v4; // rbx
  UFG::SceneLayer *result; // rax
  UFG::allocator::free_link *v6; // rsi
  UFG::Editor::SmartHandleObject *v7; // rbx
  char *v8; // rax
  UFG::qResourceData *v9; // rax
  UFG::SceneLayer *v10; // r14
  UFG::qString *v11; // rsi
  char *v12; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v13; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::qBaseTreeRB *v16; // rax
  UFG::Editor::SmartHandleObject *v17; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v18; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v19; // rax
  UFG::Editor::DAGPath path; // [rsp+28h] [rbp-19h]
  UFG::Editor::DAGPath *vars0; // [rsp+B0h] [rbp+6Fh]

  v1 = sceneLayerName;
  v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)sceneLayerName);
  if ( UFG::Editor::SceneManager::SceneLayerNameExists(v2) == 1 )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v1);
    UFG::qPrintf("Tried to create scene layer '%s', but a layer with the same name already exists!", v3);
    v4 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, v1);
    if ( !v4 )
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v1);
    result = (UFG::SceneLayer *)v4;
  }
  else
  {
    v6 = UFG::qMemoryPool::Allocate(&gPropertySetMemoryPool, 0xC0ui64, "SceneLayerResource", 0i64, 1u);
    vars0 = (UFG::Editor::DAGPath *)v6;
    v7 = 0i64;
    if ( v6 )
    {
      v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v1);
      UFG::SceneLayerResource::SceneLayerResource((UFG::SceneLayerResource *)v6, v8);
    }
    else
    {
      v9 = 0i64;
    }
    UFG::SceneLayerInventory::Add(&UFG::gSceneLayerInventory, v9);
    v10 = unk_1423AA4F8;
    if ( unk_1423AA4F8 )
    {
      v11 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      vars0 = (UFG::Editor::DAGPath *)v11;
      if ( v11 )
      {
        v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v1);
        UFG::qString::qString(v11, v12);
        v14 = v13;
      }
      else
      {
        v14 = 0i64;
      }
      v15 = SceneLayerList.mNode.mPrev;
      SceneLayerList.mNode.mPrev->mNext = v14;
      v14->mPrev = v15;
      v14->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&SceneLayerList;
      SceneLayerList.mNode.mPrev = v14;
      vars0 = &path;
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
      UFG::Editor::Core::GetDAGPath(&path, v10);
      if ( path.mPathType != 1 )
      {
        if ( !path.mFnObject.mPtr )
        {
          if ( path.mSystemName.mUID )
          {
            v16 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, path.mSystemName.mUID);
            if ( v16 )
            {
              if ( v16 != (UFG::qBaseTreeRB *)8 )
              {
                v17 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v16[-1].mCount, &path);
                if ( !path.mFnObject.mPtr )
                {
                  if ( v17 )
                  {
                    path.mFnObject.mTypeId = v17->mTypeId;
                    path.mFnObject.mPtr = v17;
                    v18 = &v17->mSmartHandleList.mNode;
                    v19 = v17->mSmartHandleList.mNode.mPrev;
                    v19->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
                    path.mFnObject.mPrev = v19;
                    path.mFnObject.mNext = v18;
                    v18->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
                  }
                }
              }
            }
          }
        }
        v7 = path.mFnObject.mPtr;
      }
      v7->vfptr[2].__vecDelDtor(v7, 1u);
      UFG::Editor::DAGPath::~DAGPath(&path);
      result = v10;
    }
    else
    {
      result = 0i64;
    }
  }
  return result;
}

// File Line: 184
// RVA: 0x210B90
char __fastcall UFG::Editor::SceneManager::RenameSceneLayer(UFG::SceneLayer *layerToRename, const char *newNameString)
{
  const char *v2; // r15
  UFG::SceneLayer *v3; // rsi
  UFG::Editor::SmartHandleObject *v4; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v5; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v6; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v7; // rdi
  const char *v8; // rbx
  char *v9; // rax
  UFG::Editor::SmartHandleObject *v10; // rcx
  UFG::qBaseTreeRB *v11; // rax
  UFG::Editor::SmartHandleObject *v12; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v13; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v14; // rax
  UFG::Editor::SmartHandleObject *v15; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v16; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v17; // rax
  unsigned int *v18; // rbx
  UFG::qSymbol *v19; // rbx
  UFG::Editor::SmartHandleObject *v20; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v21; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v22; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v28; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v29; // rax
  UFG::Editor::DAGPath path; // [rsp+10h] [rbp-29h]
  void *v32; // [rsp+A0h] [rbp+67h]

  v2 = newNameString;
  v3 = layerToRename;
  v32 = &path.mElements;
  path.mFnObject.mTypeId = -1998658210;
  path.mSystemName.mUID = -1;
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&path.mElements, 4u, "qArray.Reallocate(Constructor)");
  path.mInterfaceName.mUID = -1;
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  path.mPathType = 0;
  UFG::Editor::DAGPath::Clear(&path);
  if ( v3 )
  {
    path.mSystemName.mUID = UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID;
    UFG::qArray<UFG::qSymbol,0>::Add(&path.mElements, (UFG::qSymbol *)&v3->mNode.mUID, "qArray.Add");
    v4 = path.mFnObject.mPtr;
    if ( path.mFnObject.mPtr )
    {
      v5 = path.mFnObject.mPrev;
      v6 = path.mFnObject.mNext;
      path.mFnObject.mPrev->mNext = path.mFnObject.mNext;
      v6->mPrev = v5;
      path.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v4->mSmartHandleList.mNode.mNext == &v4->mSmartHandleList
        && v4 )
      {
        v4->vfptr->__vecDelDtor(v4, 1u);
      }
      path.mFnObject.mPtr = 0i64;
    }
    path.mFnObject.mPtr = 0i64;
  }
  v7 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)SceneLayerList.mNode.mNext;
  if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)SceneLayerList.mNode.mNext != &SceneLayerList )
  {
    while ( 1 )
    {
      v8 = (const char *)v7[1].mNode.mNext;
      v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mNode.mUID);
      if ( !(unsigned int)UFG::qStringCompare(v8, v9, -1) )
        break;
      v7 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v7->mNode.mNext;
      if ( v7 == &SceneLayerList )
        goto LABEL_13;
    }
    UFG::qString::~qString((UFG::qString *)v7);
    operator delete[](v7);
  }
LABEL_13:
  UFG::Editor::SceneManager::DuplicateSceneLayer(v3, v2);
  if ( path.mPathType != 1 )
  {
    v10 = path.mFnObject.mPtr;
    if ( !path.mFnObject.mPtr )
    {
      if ( !path.mSystemName.mUID )
        goto LABEL_28;
      v11 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, path.mSystemName.mUID);
      if ( !v11 || v11 == (UFG::qBaseTreeRB *)8 )
        goto LABEL_21;
      v12 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v11[-1].mCount, &path);
      v10 = path.mFnObject.mPtr;
      if ( !path.mFnObject.mPtr )
      {
        if ( !v12 )
          goto LABEL_28;
        path.mFnObject.mTypeId = v12->mTypeId;
        path.mFnObject.mPtr = v12;
        v13 = &v12->mSmartHandleList.mNode;
        v14 = v12->mSmartHandleList.mNode.mPrev;
        v14->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
        path.mFnObject.mPrev = v14;
        path.mFnObject.mNext = v13;
        v13->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
LABEL_21:
        v10 = path.mFnObject.mPtr;
        if ( !path.mFnObject.mPtr )
          goto LABEL_28;
        goto LABEL_22;
      }
    }
LABEL_22:
    ((void (*)(void))v10->vfptr[3].__vecDelDtor)();
    v15 = path.mFnObject.mPtr;
    if ( path.mFnObject.mPtr )
    {
      v16 = path.mFnObject.mPrev;
      v17 = path.mFnObject.mNext;
      path.mFnObject.mPrev->mNext = path.mFnObject.mNext;
      v17->mPrev = v16;
      path.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
      if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v15->mSmartHandleList.mNode.mNext == &v15->mSmartHandleList
        && v15 )
      {
        v15->vfptr->__vecDelDtor(v15, 1u);
      }
      path.mFnObject.mPtr = 0i64;
    }
    path.mFnObject.mPtr = 0i64;
  }
LABEL_28:
  if ( path.mSubElements.p )
  {
    v18 = &path.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator'(
      path.mSubElements.p,
      0x28ui64,
      path.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v18);
  }
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  if ( path.mElements.p )
  {
    v19 = path.mElements.p - 1;
    `eh vector destructor iterator'(path.mElements.p, 4ui64, path.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v19);
  }
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  v32 = &path;
  v20 = path.mFnObject.mPtr;
  if ( path.mFnObject.mPtr )
  {
    v21 = path.mFnObject.mPrev;
    v22 = path.mFnObject.mNext;
    path.mFnObject.mPrev->mNext = path.mFnObject.mNext;
    v22->mPrev = v21;
    path.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v20->mSmartHandleList.mNode.mNext == &v20->mSmartHandleList
      && v20 )
    {
      v20->vfptr->__vecDelDtor(v20, 1u);
    }
    path.mFnObject.mPtr = 0i64;
  }
  path.mFnObject.mPtr = 0i64;
  v28 = path.mFnObject.mPrev;
  v29 = path.mFnObject.mNext;
  path.mFnObject.mPrev->mNext = path.mFnObject.mNext;
  v29->mPrev = v28;
  return 1;
}

// File Line: 207
// RVA: 0x209390
UFG::SceneLayer *__fastcall UFG::Editor::SceneManager::DuplicateSceneLayer(UFG::SceneLayer *layerToDuplicate, const char *newNameString)
{
  const char *v2; // rbx
  UFG::SceneLayer *v3; // rdi
  char *v4; // rax
  UFG::SceneLayer *v5; // r15
  UFG::qPropertySet *v6; // rbx
  UFG::qPropertySet *v7; // rax
  UFG::SceneLayerResource *v8; // rbp
  signed __int64 v9; // rsi
  signed __int64 i; // r14
  unsigned int v11; // edi
  unsigned int v12; // ebx
  UFG::qPropertySet *v13; // rax
  UFG::qPropertySet *v14; // rax
  UFG::Editor::SceneManager::SceneObjectVisitor v16; // [rsp+30h] [rbp-78h]
  UFG::qString v17; // [rsp+40h] [rbp-68h]
  UFG::qString v18; // [rsp+68h] [rbp-40h]
  UFG::qSymbol result; // [rsp+B0h] [rbp+8h]

  v2 = newNameString;
  v3 = UFG::Editor::Core::OpenForEdit(layerToDuplicate);
  v16.mPropertyDepth = 0;
  v16.vfptr = (UFG::Editor::SceneManager::SceneObjectVisitorVtbl *)&UFG::Editor::SceneManager::RenameSceneObjectVisitor::`vftable';
  UFG::qString::qString(&v17);
  UFG::qString::qString(&v18);
  v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mNode.mUID);
  UFG::qString::Set(&v17, v4);
  UFG::qString::Set(&v18, v2);
  UFG::qSymbol::create_from_string(&result, v2);
  v5 = UFG::Editor::SceneManager::CreateSceneLayer(&result);
  v6 = UFG::SceneLayer::GetPropertySet(v3);
  v7 = UFG::SceneLayer::GetPropertySet(v5);
  UFG::qPropertySet::CopyFrom(v7, v6, 1);
  v8 = UFG::SceneLayer::GetSingleEditorSceneLayerResource(v5);
  v9 = (signed __int64)&v3->mLayerResources.mNode.mNext[-6].mNext;
  for ( i = (signed __int64)&v3[-1].mBox; v9 != i; v9 = *(_QWORD *)(v9 + 96) - 88i64 )
  {
    v11 = *(_DWORD *)(v9 + 108);
    v12 = 0;
    if ( v11 )
    {
      do
      {
        v13 = (UFG::qPropertySet *)UFG::RoadNetworkResource::GetSegment((UFG::RoadNetworkResource *)v9, v12);
        v14 = UFG::qPropertySet::Clone(v13);
        UFG::SceneLayerResource::AddPropertySet(v8, v14);
        ++v12;
      }
      while ( v12 < v11 );
    }
  }
  UFG::Editor::SceneManager::SceneObjectVisitor::Visit(&v16, v5);
  UFG::qString::~qString(&v18);
  UFG::qString::~qString(&v17);
  return v5;
}

// File Line: 277
// RVA: 0x20C640
UFG::qMatrix44 *__fastcall UFG::Editor::SceneManager::GetSceneObjectWorldMatrix(UFG::qMatrix44 *result, UFG::qPropertySet *sceneObject)
{
  UFG::qPropertySet *v2; // rbx
  UFG::qMatrix44 *v3; // rdi
  UFG::qMatrix44 *v4; // rax
  UFG::qMatrix44 *v5; // r8
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  unsigned int *v18; // rax
  __int64 v19; // rax
  signed __int64 v20; // rbx
  __int64 v21; // rax
  signed __int64 v22; // rbx
  UFG::qMatrix44 *v23; // rax
  UFG::qMatrix44 *v24; // r8
  UFG::qMatrix44 *v25; // rax
  UFG::qVector4 v26; // xmm3
  UFG::qVector4 v27; // xmm2
  UFG::qVector4 v28; // xmm1
  unsigned int *v29; // rax
  UFG::qMatrix44 resulta; // [rsp+20h] [rbp-48h]

  v2 = sceneObject;
  v3 = result;
  v4 = UFG::qPropertySet::Get<UFG::qMatrix44>(
         sceneObject,
         (UFG::qSymbol *)&UFG::Editor::gsymXformLocal.mUID,
         DEPTH_RECURSE);
  v5 = &UFG::qMatrix44::msIdentity;
  if ( v4 )
    v5 = v4;
  v6 = v5->v0.y;
  v7 = v5->v0.z;
  v8 = v5->v0.w;
  v3->v0.x = v5->v0.x;
  v3->v0.y = v6;
  v3->v0.z = v7;
  v3->v0.w = v8;
  v9 = v5->v1.y;
  v10 = v5->v1.z;
  v11 = v5->v1.w;
  v3->v1.x = v5->v1.x;
  v3->v1.y = v9;
  v3->v1.z = v10;
  v3->v1.w = v11;
  v12 = v5->v2.y;
  v13 = v5->v2.z;
  v14 = v5->v2.w;
  v3->v2.x = v5->v2.x;
  v3->v2.y = v12;
  v3->v2.z = v13;
  v3->v2.w = v14;
  v15 = v5->v3.y;
  v16 = v5->v3.z;
  v17 = v5->v3.w;
  v3->v3.x = v5->v3.x;
  v3->v3.y = v15;
  v3->v3.z = v16;
  v3->v3.w = v17;
  v18 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&UFG::Editor::gsymXformParent.mUID, DEPTH_RECURSE);
  if ( v18 && *v18 )
  {
    do
    {
      v19 = v2->mOwner.mOffset;
      v20 = (signed __int64)&v2->mOwner;
      if ( !v19 )
        break;
      v2 = (UFG::qPropertySet *)(v19 + v20);
      if ( !v2 )
        break;
      while ( !((v2->mFlags >> 1) & 1) )
      {
        v21 = v2->mOwner.mOffset;
        v22 = (signed __int64)&v2->mOwner;
        if ( v21 )
        {
          v2 = (UFG::qPropertySet *)(v21 + v22);
          if ( v2 )
            continue;
        }
        return v3;
      }
      v23 = UFG::qPropertySet::Get<UFG::qMatrix44>(v2, (UFG::qSymbol *)&UFG::Editor::gsymXformLocal.mUID, DEPTH_RECURSE);
      v24 = &UFG::qMatrix44::msIdentity;
      if ( v23 )
        v24 = v23;
      v25 = UFG::qMatrix44::operator*(v3, &resulta, v24);
      v26 = v25->v1;
      v27 = v25->v2;
      v28 = v25->v3;
      v3->v0 = v25->v0;
      v3->v1 = v26;
      v3->v2 = v27;
      v3->v3 = v28;
      v29 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&UFG::Editor::gsymXformParent.mUID, DEPTH_RECURSE);
      if ( !v29 )
        break;
    }
    while ( *v29 );
  }
  return v3;
}

// File Line: 297
// RVA: 0x212BC0
void __fastcall UFG::Editor::SceneManager::SetSceneObjectWorldMatrix(UFG::qPropertySet *sceneObject, UFG::qMatrix44 *transform)
{
  UFG::qPropertySet *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::Event *v4; // rdx
  UFG::allocator::free_link *v5; // rax
  UFG::qMatrix44 result; // [rsp+30h] [rbp-48h]

  v2 = sceneObject;
  if ( !(sceneObject->mFlags & 1) )
  {
    UFG::Editor::Utility::ComputeLocalMatrix(&result, sceneObject, transform);
    UFG::qPropertySet::Set<UFG::qMatrix44>(v2, (UFG::qSymbol *)&UFG::Editor::gsymXformLocal.mUID, &result);
    v3 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
    v4 = (UFG::Event *)v3;
    if ( v3 )
    {
      v5 = v3 + 1;
      v5->mNext = v5;
      v5[1].mNext = v5;
      v4->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
      v4->m_EventUID = 1707257979;
      v4->m_NamePTR = 0i64;
    }
    else
    {
      v4 = 0i64;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v4);
  }
}

// File Line: 450
// RVA: 0x205EC0
UFG::qPropertySet *__fastcall UFG::Editor::SceneManager::CloneSceneObject(UFG::qPropertySet *sceneObject)
{
  UFG::qPropertySet *v1; // rdi
  UFG::qPropertySet *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::Event *v4; // rdx
  UFG::allocator::free_link *v5; // rax
  UFG::qMatrix44 result; // [rsp+30h] [rbp-88h]
  UFG::qMatrix44 v; // [rsp+70h] [rbp-48h]

  v1 = UFG::Editor::Core::OpenForEdit(sceneObject);
  v2 = UFG::qPropertySet::Clone(v1);
  UFG::Editor::SceneManager::GetSceneObjectWorldMatrix(&result, v1);
  if ( !(v1->mFlags & 1) )
  {
    UFG::Editor::Utility::ComputeLocalMatrix(&v, v1, &result);
    UFG::qPropertySet::Set<UFG::qMatrix44>(v1, (UFG::qSymbol *)&UFG::Editor::gsymXformLocal.mUID, &v);
    v3 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
    v4 = (UFG::Event *)v3;
    if ( v3 )
    {
      v5 = v3 + 1;
      v5->mNext = v5;
      v5[1].mNext = v5;
      v4->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
      v4->m_EventUID = 1707257979;
      v4->m_NamePTR = 0i64;
    }
    else
    {
      v4 = 0i64;
    }
    UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v4);
  }
  return v2;
}

// File Line: 462
// RVA: 0x205E80
UFG::qPropertySet *__fastcall UFG::Editor::SceneManager::CloneAndDeleteSceneObject(UFG::qPropertySet *sceneObject)
{
  UFG::qPropertySet *v1; // rdi
  UFG::qPropertySet *v2; // rbx

  v1 = UFG::Editor::Core::OpenForEdit(sceneObject);
  v2 = UFG::Editor::SceneManager::CloneSceneObject(v1);
  UFG::Editor::SceneManager::DeleteSceneObject(v1);
  return v2;
}

// File Line: 473
// RVA: 0x2080E0
void __fastcall UFG::Editor::SceneManager::DeleteSceneObject(UFG::qPropertySet *sceneObject)
{
  UFG::qPropertySet *v1; // rbx
  UFG::Editor::SmartHandleObject *v2; // rcx
  UFG::qBaseTreeRB *v3; // rax
  UFG::Editor::SmartHandleObject *v4; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v5; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v6; // rax
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *v8; // rdi
  __int64 v9; // rax
  UFG::qPropertyList *v10; // rbx
  unsigned int v11; // eax
  UFG::SceneLayer *v12; // rax
  UFG::SceneLayerResource *v13; // rbx
  signed __int64 i; // rsi
  unsigned int *v15; // rbx
  UFG::qSymbol *v16; // rbx
  UFG::Editor::DAGPath path; // [rsp+18h] [rbp-19h]
  unsigned int *v18; // [rsp+98h] [rbp+67h]

  if ( !sceneObject )
    return;
  v1 = sceneObject;
  v18 = &path.mFnObject.mTypeId;
  path.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path.mFnObject.mTypeId;
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
  UFG::Editor::Core::GetDAGPath(&path, v1);
  if ( path.mPathType != 1 )
  {
    v2 = path.mFnObject.mPtr;
    if ( !path.mFnObject.mPtr )
    {
      if ( !path.mSystemName.mUID )
        goto LABEL_11;
      v3 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, path.mSystemName.mUID);
      if ( !v3 || v3 == (UFG::qBaseTreeRB *)8 )
        goto LABEL_10;
      v4 = UFG::Editor::DAGType::AquireFnObject((UFG::Editor::DAGType *)&v3[-1].mCount, &path);
      v2 = path.mFnObject.mPtr;
      if ( !path.mFnObject.mPtr )
      {
        if ( !v4 )
          goto LABEL_11;
        path.mFnObject.mTypeId = v4->mTypeId;
        path.mFnObject.mPtr = v4;
        v5 = &v4->mSmartHandleList.mNode;
        v6 = v4->mSmartHandleList.mNode.mPrev;
        v6->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
        path.mFnObject.mPrev = v6;
        path.mFnObject.mNext = v5;
        v5->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&path;
LABEL_10:
        v2 = path.mFnObject.mPtr;
LABEL_11:
        if ( !v2 )
          goto LABEL_13;
        goto LABEL_12;
      }
    }
LABEL_12:
    v2->vfptr->__vecDelDtor(v2, 1u);
  }
LABEL_13:
  v7 = UFG::Editor::Core::OpenForEdit(v1);
  v8 = v7;
  if ( v7->mFlags & 0x20
    && (v9 = v7->mOwner.mOffset) != 0
    && (v10 = (UFG::qPropertyList *)((char *)&v8->mOwner + v9)) != 0i64 )
  {
    v11 = UFG::qPropertyList::FindElement<UFG::qPropertySet>((UFG::qPropertyList *)((char *)&v8->mOwner + v9), v8);
    if ( v11 != -1 )
      UFG::qPropertyList::Remove(v10, v11);
  }
  else
  {
    v12 = UFG::Scene::FindLayerContainingObject(&UFG::Scene::msDefault, &v8->mName, 0i64);
    if ( v12 )
    {
      v13 = (UFG::SceneLayerResource *)&v12->mLayerResources.mNode.mNext[-6].mNext;
      for ( i = (signed __int64)&v12[-1].mBox;
            v13 != (UFG::SceneLayerResource *)i;
            v13 = (UFG::SceneLayerResource *)&v13->mNext[-6].mNext )
      {
        UFG::SceneLayerResource::RemovePropertySet(v13, v8);
      }
    }
  }
  if ( path.mSubElements.p )
  {
    v15 = &path.mSubElements.p[-1].mStringHash32;
    `eh vector destructor iterator'(
      path.mSubElements.p,
      0x28ui64,
      path.mSubElements.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v15);
  }
  path.mSubElements.p = 0i64;
  *(_QWORD *)&path.mSubElements.size = 0i64;
  if ( path.mElements.p )
  {
    v16 = path.mElements.p - 1;
    `eh vector destructor iterator'(path.mElements.p, 4ui64, path.mElements.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v16);
  }
  path.mElements.p = 0i64;
  *(_QWORD *)&path.mElements.size = 0i64;
  UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(&path.mFnObject);
}

// File Line: 523
// RVA: 0x204C90
void __fastcall UFG::Editor::SceneManager::AddChildSceneObject(UFG::qPropertySet **parentSceneObject, UFG::qPropertySet **sceneObject)
{
  UFG::qPropertySet **v2; // rsi
  UFG::qPropertySet **v3; // r14
  UFG::qPropertySet *v4; // rdx
  UFG::qPropertySet *v5; // rdi
  UFG::qPropertySet *v6; // rbx
  UFG::qPropertySet *v7; // rax
  UFG::SceneLayer *v8; // rax
  UFG::qPropertyList *v9; // rbx
  UFG::qMatrix44 result; // [rsp+20h] [rbp-48h]

  v2 = sceneObject;
  v3 = parentSceneObject;
  if ( *parentSceneObject )
  {
    v4 = *sceneObject;
    if ( v4 )
    {
      UFG::Editor::SceneManager::GetSceneObjectWorldMatrix(&result, v4);
      if ( UFG::Scene::FindLayerContainingObject(&UFG::Scene::msDefault, &(*v2)->mName, 0i64) )
      {
        v5 = UFG::Editor::Core::OpenForEdit(*v2);
        v6 = UFG::Editor::SceneManager::CloneSceneObject(v5);
        UFG::Editor::SceneManager::DeleteSceneObject(v5);
        *v2 = v6;
      }
      v7 = UFG::Editor::Core::OpenForEdit(*v3);
      *v3 = v7;
      v8 = UFG::Scene::FindLayerContainingObject(&UFG::Scene::msDefault, &v7->mName, 0i64);
      UFG::Editor::SceneManager::SetUniqueName(*v2, v8, 0i64, &(*v3)->mName);
      v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(*v3, (UFG::qSymbol *)&UFG::Editor::gsymSimObjChildren.mUID, 0);
      if ( !v9 )
      {
        v9 = (UFG::qPropertyList *)UFG::qPropertyList::Create("CreateObject");
        UFG::qPropertySet::Set<UFG::qPropertyList>(*v3, (UFG::qSymbol *)&UFG::Editor::gsymSimObjChildren.mUID, v9);
      }
      UFG::qPropertyList::Add<UFG::qPropertySet>(v9, *v2);
      UFG::qPropertySet::Set<unsigned long>(*v2, (UFG::qSymbol *)&UFG::Editor::gsymXformParent.mUID, 1u);
      UFG::Editor::SceneManager::SetSceneObjectWorldMatrix(*v2, &result);
    }
  }
}

// File Line: 674
// RVA: 0x20C2D0
UFG::qSymbol *__fastcall UFG::Editor::SceneManager::GetNameFromUniqueName(UFG::qSymbol *result, UFG::qSymbol *uniqueName)
{
  UFG::qSymbol *v2; // rbx
  UFG::qSymbol *v3; // rsi
  char *v4; // rax
  const char *v5; // rdi
  char *v6; // rax
  UFG::qSymbol *v7; // rax

  v2 = result;
  v3 = uniqueName;
  v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)uniqueName);
  v5 = v4;
  if ( v4 && ((v6 = UFG::qStringFindLast(v4, ":")) != 0i64 || (v6 = UFG::qStringFindLast(v5, "-")) != 0i64) )
  {
    UFG::qSymbol::create_from_string(v2, v6 + 1);
    v7 = v2;
  }
  else
  {
    v2->mUID = v3->mUID;
    v7 = v2;
  }
  return v7;
}

// File Line: 740
// RVA: 0x212C60
void __fastcall UFG::Editor::SceneManager::SetUniqueName(UFG::qPropertySet *sceneObject, UFG::SceneLayer *layer, UFG::qPropertyList *destList, UFG::qSymbol *baseName)
{
  UFG::qSymbol *v4; // rdi
  UFG::qPropertyList *v5; // rsi
  UFG::SceneLayer *v6; // rbx
  char *v7; // rbx
  char *v8; // rax
  char *v9; // rbx
  char *v10; // rax
  unsigned int v11; // edi
  unsigned int v12; // ebx
  char *v13; // rax
  UFG::qPropertySet *v14; // rax
  UFG::SceneLayer *v15; // rbx
  UFG::SceneLayerResource *v16; // rax
  UFG::qPropertyList *v17; // rax
  UFG::qPropertyList *v18; // rdi
  unsigned int v19; // esi
  unsigned int v20; // ebx
  char *v21; // rax
  UFG::qPropertySet *v22; // rcx
  UFG::qPropertyList *v23; // rsi
  char *v24; // rax
  unsigned int v25; // edi
  char *v26; // rax
  UFG::qPropertySet *v27; // rbx
  UFG::qPropertyList *v28; // rax
  char *v29; // rax
  __int64 v30; // rcx
  UFG::qSymbol v31; // [rsp+20h] [rbp-48h]
  __int64 v32; // [rsp+28h] [rbp-40h]
  UFG::qString v33; // [rsp+30h] [rbp-38h]
  UFG::qPropertySet *v34; // [rsp+90h] [rbp+28h]
  UFG::SceneLayer *layera; // [rsp+98h] [rbp+30h]
  UFG::qSymbol result; // [rsp+A0h] [rbp+38h]
  UFG::qSymbol v37; // [rsp+A8h] [rbp+40h]

  layera = layer;
  v34 = sceneObject;
  v32 = -2i64;
  v4 = baseName;
  v5 = destList;
  v6 = layer;
  UFG::Editor::SceneManager::GetNameFromUniqueName(&result, &sceneObject->mName);
  if ( v4->mUID == -1 )
  {
    if ( !v6 )
      goto LABEL_6;
    v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
    v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&layera->mNode.mUID);
    UFG::qString::FormatEx(&v33, "%s-%s", v10, v9);
    result.mUID = UFG::qSymbol::create_from_string(&v37, v33.mData)->mUID;
  }
  else
  {
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
    v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v4);
    UFG::qString::FormatEx(&v33, "%s:%s", v8, v7);
    result.mUID = UFG::qSymbol::create_from_string(&v37, v33.mData)->mUID;
  }
  UFG::qString::~qString(&v33);
LABEL_6:
  if ( v5 )
  {
    while ( 1 )
    {
      v11 = v5->mNumElements;
      v12 = 0;
      if ( !v11 )
        break;
      while ( 1 )
      {
        v13 = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v12);
        if ( v13 && *(_QWORD *)v13 )
          v14 = (UFG::qPropertySet *)&v13[*(_QWORD *)v13];
        else
          v14 = 0i64;
        if ( v14 != v34 && v14->mName.mUID == result.mUID )
          break;
        if ( ++v12 >= v11 )
          goto LABEL_17;
      }
      result.mUID = UFG::qSymbol::create_increment(&v37, &result, 1)->mUID;
    }
  }
LABEL_17:
  v15 = layera;
  if ( layera )
  {
    while ( 1 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
      v16 = UFG::SceneLayer::GetSingleEditorSceneLayerResource(v15);
      if ( !UFG::SceneLayerResource::FindObjectPropertySet(v16, &result) )
        break;
      result.mUID = UFG::qSymbol::create_increment(&v37, &result, 1)->mUID;
    }
  }
  UFG::qPropertySet::SetName(v34, &result);
  v17 = UFG::qPropertySet::Get<UFG::qPropertyList>(v34, (UFG::qSymbol *)&UFG::Editor::gsymSimObjChildren.mUID, 0);
  v18 = v17;
  if ( v17 )
  {
    v19 = v17->mNumElements;
    v20 = 0;
    if ( v19 )
    {
      do
      {
        v21 = UFG::qPropertyList::GetValuePtr(v18, 0x1Au, v20);
        if ( v21 && *(_QWORD *)v21 )
          v22 = (UFG::qPropertySet *)&v21[*(_QWORD *)v21];
        else
          v22 = 0i64;
        UFG::Editor::SceneManager::SetUniqueName(v22, layera, 0i64, &result);
        ++v20;
      }
      while ( v20 < v19 );
    }
  }
  v23 = UFG::qPropertySet::Get<UFG::qPropertyList>(v34, (UFG::qSymbol *)&UFG::Editor::gsymLinks.mUID, DEPTH_RECURSE);
  if ( v23 )
  {
    v24 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
    UFG::qString::FormatEx(&v33, "%s:link001", v24);
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&layera, v33.mData);
    v37.mUID = v23->mNumElements;
    v25 = 0;
    if ( v37.mUID )
    {
      do
      {
        v26 = UFG::qPropertyList::GetValuePtr(v23, 0x1Au, v25);
        if ( v26 && *(_QWORD *)v26 )
          v27 = (UFG::qPropertySet *)&v26[*(_QWORD *)v26];
        else
          v27 = 0i64;
        UFG::qPropertySet::SetName(v27, (UFG::qSymbol *)&layera);
        v28 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                v34,
                (UFG::qSymbol *)&UFG::Editor::gsymSimObjChildren.mUID,
                DEPTH_RECURSE);
        if ( v28
          && v28->mNumElements
          && (v29 = UFG::qPropertyList::GetValuePtr(v28, 0x1Au, 0)) != 0i64
          && (v30 = *(_QWORD *)v29) != 0
          && &v29[v30] )
        {
          UFG::qPropertySet::Set<UFG::qSymbol>(
            v27,
            (UFG::qSymbol *)&UFG::Editor::gsymLinkEntity.mUID,
            (UFG::qSymbol *)&v29[v30 + 64]);
        }
        else
        {
          UFG::qPropertySet::RemovePropertyByName(v27, (UFG::qSymbol *)&UFG::Editor::gsymLinkEntity.mUID);
        }
        LODWORD(layera) = (UFG::qSymbol)UFG::qSymbol::create_increment(&v31, (UFG::qSymbol *)&layera, 1)->mUID;
        ++v25;
      }
      while ( v25 < v37.mUID );
    }
    UFG::qString::~qString(&v33);
  }
}

// File Line: 820
// RVA: 0x21E7D0
void __fastcall UFG::Editor::SceneManager::SceneObjectVisitor::VisitRecurse(UFG::Editor::SceneManager::SceneObjectVisitor *this, UFG::Editor::DAGPath *path, UFG::qPropertySet *propertySet)
{
  UFG::qPropertySet *v3; // rsi
  UFG::Editor::DAGPath *v4; // rdi
  UFG::Editor::SceneManager::SceneObjectVisitor *v5; // rbx
  UFG::qPropertySet *v6; // rbp
  UFG::qPropertyList *v7; // rax
  UFG::qPropertyList *v8; // r9
  unsigned int v9; // eax
  char *v10; // rax
  unsigned int v11; // ebx
  signed __int64 v12; // r9
  unsigned int v13; // eax
  unsigned int v14; // esi
  unsigned int v15; // edx
  unsigned int v16; // edx
  UFG::Editor::SmartHandleObject *v17; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v18; // rdx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v19; // rax
  UFG::Editor::DAGPath *v20; // rax
  UFG::qString *v21; // rcx
  unsigned int *v22; // rbx
  UFG::qSymbol *v23; // rcx
  UFG::qSymbol *v24; // rbx
  UFG::Editor::SmartHandleObject *v25; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v26; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v27; // rax
  unsigned int v28; // [rsp+20h] [rbp-A8h]
  unsigned int v29; // [rsp+24h] [rbp-A4h]
  UFG::qPropertyList *v30; // [rsp+28h] [rbp-A0h]
  UFG::Editor::DAGPath v31; // [rsp+40h] [rbp-88h]
  UFG::Editor::SceneManager::SceneObjectVisitor *v32; // [rsp+D0h] [rbp+8h]
  UFG::qPropertySet *v33; // [rsp+E0h] [rbp+18h]
  unsigned int v34; // [rsp+E8h] [rbp+20h]

  v33 = propertySet;
  v32 = this;
  v3 = propertySet;
  v4 = path;
  v5 = this;
  v6 = 0i64;
  if ( ((__int64 (*)(void))this->vfptr->OnPushSceneObject)() )
  {
    v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           v3,
           (UFG::qSymbol *)&UFG::Editor::gsymSimObjChildren.mUID,
           v5->mPropertyDepth);
    v8 = v7;
    v30 = v7;
    if ( v7 )
    {
      v29 = v7->mNumElements;
      if ( v29 )
      {
        v9 = 0;
        v34 = 0;
        do
        {
          v10 = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v9);
          if ( v10 && *(_QWORD *)v10 )
            v6 = (UFG::qPropertySet *)&v10[*(_QWORD *)v10];
          v11 = v6->mName.mUID;
          v12 = (signed __int64)&v4->mElements;
          v13 = v4->mElements.size;
          v28 = v13;
          v14 = v13 + 1;
          v15 = v4->mElements.capacity;
          if ( v13 + 1 > v15 )
          {
            if ( v15 )
              v16 = 2 * v15;
            else
              v16 = 1;
            for ( ; v16 < v14; v16 *= 2 )
              ;
            if ( v16 <= 4 )
              v16 = 4;
            if ( v16 - v14 > 0x10000 )
              v16 = v13 + 65537;
            UFG::qArray<UFG::qSymbol,0>::Reallocate(&v4->mElements, v16, "qArray.Add");
            v13 = v28;
            v12 = (signed __int64)&v4->mElements;
          }
          *(_DWORD *)v12 = v14;
          *(_DWORD *)(*(_QWORD *)(v12 + 8) + 4i64 * v13) = v11;
          v17 = v4->mFnObject.mPtr;
          if ( v17 )
          {
            v18 = v4->mFnObject.mPrev;
            v19 = v4->mFnObject.mNext;
            v18->mNext = v19;
            v19->mPrev = v18;
            v4->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v4->mFnObject.mPrev;
            v4->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v4->mFnObject.mPrev;
            if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v17->mSmartHandleList.mNode.mNext == &v17->mSmartHandleList
              && v17 )
            {
              v17->vfptr->__vecDelDtor(v17, 1u);
            }
            v4->mFnObject.mPtr = 0i64;
          }
          v4->mFnObject.mPtr = 0i64;
          UFG::Editor::DAGPath::DAGPath(&v31, v4);
          v5 = v32;
          UFG::Editor::SceneManager::SceneObjectVisitor::VisitRecurse(v32, v20, v6);
          UFG::Editor::DAGPath::RemoveEnd(v4);
          v9 = v34 + 1;
          v34 = v9;
          v8 = v30;
          v6 = 0i64;
        }
        while ( v9 < v29 );
        v3 = v33;
      }
    }
    ((void (__fastcall *)(UFG::Editor::SceneManager::SceneObjectVisitor *, UFG::Editor::DAGPath *, UFG::qPropertySet *, UFG::qPropertyList *))v5->vfptr->OnPopSceneObject)(
      v5,
      v4,
      v3,
      v8);
  }
  v21 = v4->mSubElements.p;
  if ( v21 )
  {
    v22 = &v21[-1].mStringHash32;
    `eh vector destructor iterator'(
      v21,
      0x28ui64,
      v21[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v22);
  }
  v4->mSubElements.p = 0i64;
  *(_QWORD *)&v4->mSubElements.size = 0i64;
  v23 = v4->mElements.p;
  if ( v23 )
  {
    v24 = v23 - 1;
    `eh vector destructor iterator'(v23, 4ui64, v23[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v24);
  }
  v4->mElements.p = 0i64;
  *(_QWORD *)&v4->mElements.size = 0i64;
  v25 = v4->mFnObject.mPtr;
  if ( v25 )
  {
    v26 = v4->mFnObject.mPrev;
    v27 = v4->mFnObject.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    v4->mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v4->mFnObject.mPrev;
    v4->mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v4->mFnObject.mPrev;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v25->mSmartHandleList.mNode.mNext == &v25->mSmartHandleList
      && v25 )
    {
      v25->vfptr->__vecDelDtor(v25, 1u);
    }
    v4->mFnObject.mPtr = 0i64;
  }
  v4->mFnObject.mPtr = 0i64;
  UFG::Editor::SmartHandle::~SmartHandle((UFG::Editor::SmartHandle *)&v4->mFnObject.mPrev);
}

// File Line: 848
// RVA: 0x21E300
void __fastcall UFG::Editor::SceneManager::SceneObjectVisitor::Visit(UFG::Editor::SceneManager::SceneObjectVisitor *this, UFG::SceneLayer *layer)
{
  UFG::SceneLayer *v2; // rbx
  UFG::Editor::SceneManager::SceneObjectVisitor *v3; // r13
  UFG::Editor::SmartHandleObject *v4; // r8
  __int64 *v5; // rcx
  __int64 **v6; // rax
  signed __int64 v7; // r15
  unsigned int v8; // er12
  unsigned int v9; // esi
  UFG::qPropertySet *v10; // r14
  __int64 v11; // rdi
  unsigned int v12; // ebx
  unsigned int v13; // edx
  UFG::Editor::SmartHandleObject *v14; // r8
  __int64 *v15; // rcx
  __int64 **v16; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v17; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v18; // rax
  UFG::Editor::SmartHandleObject *v19; // r8
  __int64 *v20; // rcx
  __int64 **v21; // rax
  unsigned int *v22; // rbx
  UFG::qSymbol *v23; // rbx
  UFG::Editor::SmartHandleObject *v24; // r8
  __int64 *v25; // rcx
  __int64 **v26; // rax
  __int64 *v27; // rcx
  __int64 **v28; // rax
  __int64 *v29; // [rsp+20h] [rbp-99h]
  __int64 **v30; // [rsp+28h] [rbp-91h]
  UFG::Editor::SmartHandleObject *v31; // [rsp+30h] [rbp-89h]
  int v32; // [rsp+38h] [rbp-81h]
  int v33; // [rsp+40h] [rbp-79h]
  UFG::qArray<UFG::qSymbol,0> v34; // [rsp+48h] [rbp-71h]
  unsigned int v35; // [rsp+58h] [rbp-61h]
  UFG::qArray<UFG::qString,0> v36; // [rsp+60h] [rbp-59h]
  int v37; // [rsp+70h] [rbp-49h]
  UFG::Editor::DAGPath v38; // [rsp+80h] [rbp-39h]
  __int64 v39; // [rsp+D8h] [rbp+1Fh]
  signed __int64 i; // [rsp+128h] [rbp+6Fh]

  v39 = -2i64;
  v2 = layer;
  v3 = this;
  v29 = (__int64 *)&v29;
  v30 = &v29;
  v31 = 0i64;
  v32 = -1998658210;
  v33 = -1;
  v34.p = 0i64;
  *(_QWORD *)&v34.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Reallocate(&v34, 4u, "qArray.Reallocate(Constructor)");
  v35 = -1;
  v36.p = 0i64;
  *(_QWORD *)&v36.size = 0i64;
  v37 = 0;
  v33 = UFG::Editor::DAGTypeSceneObject::TYPE_SYMBOL.mUID;
  UFG::qArray<UFG::qSymbol,0>::Insert(&v34, 0, (UFG::qSymbol *)&v2->mNode.mUID, "qArray.Insert");
  v4 = v31;
  if ( v31 )
  {
    v5 = v29;
    v6 = v30;
    v29[1] = (__int64)v30;
    *v6 = v5;
    v29 = (__int64 *)&v29;
    v30 = &v29;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v4->mSmartHandleList.mNode.mNext == &v4->mSmartHandleList
      && v4 )
    {
      v4->vfptr->__vecDelDtor(v4, 1u);
    }
    v31 = 0i64;
  }
  v31 = 0i64;
  v7 = (signed __int64)&v2->mLayerResources.mNode.mNext[-6].mNext;
  for ( i = (signed __int64)&v2[-1].mBox; v7 != i; v7 = *(_QWORD *)(v7 + 96) - 88i64 )
  {
    v8 = *(_DWORD *)(v7 + 108);
    v9 = 0;
    if ( v8 )
    {
      do
      {
        v10 = (UFG::qPropertySet *)UFG::RoadNetworkResource::GetSegment((UFG::RoadNetworkResource *)v7, v9);
        v11 = v34.size;
        v12 = v34.size + 1;
        if ( v34.size + 1 > v34.capacity )
        {
          if ( v34.capacity )
            v13 = 2 * v34.capacity;
          else
            v13 = 1;
          for ( ; v13 < v12; v13 *= 2 )
            ;
          if ( v13 <= 4 )
            v13 = 4;
          if ( v13 - v12 > 0x10000 )
            v13 = v34.size + 65537;
          UFG::qArray<UFG::qSymbol,0>::Reallocate(&v34, v13, "qArray.Add");
        }
        v34.size = v12;
        v34.p[v11].mUID = v10->mName.mUID;
        v14 = v31;
        if ( v31 )
        {
          v15 = v29;
          v16 = v30;
          v29[1] = (__int64)v30;
          *v16 = v15;
          v29 = (__int64 *)&v29;
          v30 = &v29;
          if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v14->mSmartHandleList.mNode.mNext == &v14->mSmartHandleList
            && v14 )
          {
            v14->vfptr->__vecDelDtor(v14, 1u);
          }
          v31 = 0i64;
        }
        v31 = 0i64;
        v38.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v38;
        v38.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v38;
        v38.mFnObject.mPtr = 0i64;
        v38.mFnObject.mTypeId = -1998658210;
        v38.mSystemName.mUID = -1;
        v38.mElements.p = 0i64;
        *(_QWORD *)&v38.mElements.size = 0i64;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(&v38.mElements, 4u, "qArray.Reallocate(Constructor)");
        v38.mInterfaceName.mUID = -1;
        v38.mSubElements.p = 0i64;
        *(_QWORD *)&v38.mSubElements.size = 0i64;
        v38.mPathType = 0;
        UFG::Editor::DAGPath::Clear(&v38);
        if ( v38.mPathType == Default && !v38.mFnObject.mPtr && v31 )
        {
          v38.mFnObject.mTypeId = v31->mTypeId;
          v38.mFnObject.mPtr = v31;
          v17 = &v31->mSmartHandleList.mNode;
          v18 = v31->mSmartHandleList.mNode.mPrev;
          v18->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v38;
          v38.mFnObject.mPrev = v18;
          v38.mFnObject.mNext = v17;
          v17->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v38;
        }
        v38.mSystemName.mUID = v33;
        UFG::qArray<UFG::qSymbol,0>::Clone(&v34, &v38.mElements);
        v38.mInterfaceName.mUID = v35;
        UFG::qArray<UFG::qString,0>::Clone(&v36, &v38.mSubElements);
        UFG::Editor::SceneManager::SceneObjectVisitor::VisitRecurse(v3, &v38, v10);
        if ( v34.size > 1 )
          --v34.size;
        else
          v34.size = 0;
        v19 = v31;
        if ( v31 )
        {
          v20 = v29;
          v21 = v30;
          v29[1] = (__int64)v30;
          *v21 = v20;
          v29 = (__int64 *)&v29;
          v30 = &v29;
          if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v19->mSmartHandleList.mNode.mNext == &v19->mSmartHandleList
            && v19 )
          {
            v19->vfptr->__vecDelDtor(v19, 1u);
          }
          v31 = 0i64;
        }
        v31 = 0i64;
        ++v9;
      }
      while ( v9 < v8 );
    }
  }
  if ( v36.p )
  {
    v22 = &v36.p[-1].mStringHash32;
    `eh vector destructor iterator'(
      v36.p,
      0x28ui64,
      v36.p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v22);
  }
  v36.p = 0i64;
  *(_QWORD *)&v36.size = 0i64;
  if ( v34.p )
  {
    v23 = v34.p - 1;
    `eh vector destructor iterator'(v34.p, 4ui64, v34.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v23);
  }
  v34.p = 0i64;
  *(_QWORD *)&v34.size = 0i64;
  v24 = v31;
  if ( v31 )
  {
    v25 = v29;
    v26 = v30;
    v29[1] = (__int64)v30;
    *v26 = v25;
    v29 = (__int64 *)&v29;
    v30 = &v29;
    if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v24->mSmartHandleList.mNode.mNext == &v24->mSmartHandleList
      && v24 )
    {
      v24->vfptr->__vecDelDtor(v24, 1u);
    }
    v31 = 0i64;
  }
  v27 = v29;
  v28 = v30;
  v29[1] = (__int64)v30;
  *v28 = v27;
}

// File Line: 885
// RVA: 0x210B10
void __fastcall UFG::Editor::SceneManager::RenameSceneObjectVisitor::RenamePropertySet(UFG::Editor::SceneManager::RenameSceneObjectVisitor *this, UFG::qPropertySet *propertySet)
{
  UFG::qPropertySet *v2; // rdi
  UFG::Editor::SceneManager::RenameSceneObjectVisitor *v3; // rbx
  char *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h]
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]

  v2 = propertySet;
  v3 = this;
  v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propertySet->mName);
  UFG::qString::qString(&v6, v4);
  UFG::qString::ReplaceString(&v6, v3->mOldName.mData, v3->mNewName.mData, 0);
  v5 = UFG::qSymbol::create_from_string(&result, v6.mData);
  UFG::qPropertySet::SetName(v2, v5);
  UFG::qString::~qString(&v6);
}

// File Line: 909
// RVA: 0x20F710
char __fastcall UFG::Editor::SceneManager::RenameSceneObjectVisitor::OnPushSceneObject(UFG::Editor::SceneManager::RenameSceneObjectVisitor *this, UFG::Editor::DAGPath *path, UFG::qPropertySet *propertySet)
{
  UFG::qPropertySet *v3; // rbx
  UFG::Editor::SceneManager::RenameSceneObjectVisitor *v4; // rbp
  UFG::qPropertySet *v5; // rax
  UFG::qPropertyList *v6; // rax
  UFG::qPropertyList *v7; // rsi
  unsigned int v8; // edi
  char *v9; // rax
  char *v10; // rbx
  char *v11; // rax
  UFG::qSymbol *v12; // rax
  UFG::qSymbolUC *v13; // rax
  char *v14; // rax
  UFG::qSymbol *v15; // rax
  UFG::qSymbolUC *v16; // rax
  char *v17; // rax
  UFG::qSymbol *v18; // rax
  UFG::qSymbol v20; // [rsp+20h] [rbp-98h]
  UFG::qSymbol v21; // [rsp+24h] [rbp-94h]
  __int64 v22; // [rsp+28h] [rbp-90h]
  UFG::qString v23; // [rsp+30h] [rbp-88h]
  UFG::qString v24; // [rsp+58h] [rbp-60h]
  UFG::qString v25; // [rsp+80h] [rbp-38h]
  UFG::qSymbol result; // [rsp+D8h] [rbp+20h]

  v22 = -2i64;
  v3 = propertySet;
  v4 = this;
  UFG::Editor::SceneManager::RenameSceneObjectVisitor::RenamePropertySet(this, propertySet);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v3,
         (UFG::qSymbol *)&UFG::Editor::gsymDefaultComponentRegion.mUID,
         DEPTH_RECURSE);
  if ( v5 )
    UFG::Editor::SceneManager::RenameSceneObjectVisitor::RenamePropertySet(v4, v5);
  v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qSymbol *)&UFG::Editor::gsymLinks.mUID, DEPTH_RECURSE);
  v7 = v6;
  if ( v6 )
  {
    v8 = 0;
    if ( v6->mNumElements )
    {
      do
      {
        v9 = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, v8);
        if ( v9 && *(_QWORD *)v9 )
          v10 = &v9[*(_QWORD *)v9];
        else
          v10 = 0i64;
        v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v10 + 16);
        UFG::qString::qString(&v24, v11);
        UFG::qString::ReplaceString(&v24, v4->mOldName.mData, v4->mNewName.mData, 0);
        v12 = UFG::qSymbol::create_from_string(&result, v24.mData);
        UFG::qPropertySet::SetName((UFG::qPropertySet *)v10, v12);
        UFG::qString::~qString(&v24);
        v13 = (UFG::qSymbolUC *)UFG::qPropertySet::Get<UFG::qSymbol>(
                                  (UFG::qPropertySet *)v10,
                                  (UFG::qSymbol *)&UFG::Editor::gsymLinkEntity.mUID,
                                  DEPTH_RECURSE);
        if ( v13 )
        {
          v14 = UFG::qSymbol::as_cstr_dbg(v13);
          UFG::qString::qString(&v23, v14);
          UFG::qString::ReplaceString(&v23, v4->mOldName.mData, v4->mNewName.mData, 0);
          v15 = UFG::qSymbol::create_from_string(&v20, v23.mData);
          UFG::qPropertySet::Set<UFG::qSymbol>(
            (UFG::qPropertySet *)v10,
            (UFG::qSymbol *)&UFG::Editor::gsymLinkEntity.mUID,
            v15);
          UFG::qString::~qString(&v23);
        }
        v16 = (UFG::qSymbolUC *)UFG::qPropertySet::Get<UFG::qSymbol>(
                                  (UFG::qPropertySet *)v10,
                                  (UFG::qSymbol *)&UFG::Editor::gsymLinkObjective.mUID,
                                  DEPTH_RECURSE);
        if ( v16 )
        {
          v17 = UFG::qSymbol::as_cstr_dbg(v16);
          UFG::qString::qString(&v25, v17);
          UFG::qString::ReplaceString(&v25, v4->mOldName.mData, v4->mNewName.mData, 0);
          v18 = UFG::qSymbol::create_from_string(&v21, v25.mData);
          UFG::qPropertySet::Set<UFG::qSymbol>(
            (UFG::qPropertySet *)v10,
            (UFG::qSymbol *)&UFG::Editor::gsymLinkObjective.mUID,
            v18);
          UFG::qString::~qString(&v25);
        }
        ++v8;
      }
      while ( v8 < v7->mNumElements );
    }
  }
  return 1;
}

// File Line: 1200
// RVA: 0x20F920
__int64 __fastcall UFG::Editor::UpdateObjectTreeVisitor::OnPushSceneObject(UFG::Editor::UpdateObjectTreeVisitor *this, UFG::Editor::DAGPath *path, UFG::qPropertySet *propertySet)
{
  UFG::qPropertySet *v3; // rsi
  UFG::Editor::DAGPath *v4; // r15
  UFG::Editor::UpdateObjectTreeVisitor *v5; // rbp
  unsigned int v6; // ebx
  unsigned int v7; // edi
  UFG::qPropertyList *v8; // rax
  char *v9; // rsi
  unsigned int v10; // eax
  unsigned __int8 v11; // al
  UFG::qArray<UFG::Editor::DAGPath,0> *v12; // r14
  __int64 v13; // r13
  unsigned __int8 v14; // si
  unsigned int v15; // eax
  unsigned int v16; // edi

  v3 = propertySet;
  v4 = path;
  v5 = this;
  v6 = 1;
  v7 = 0;
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         propertySet,
         (UFG::qSymbol *)&UFG::Editor::gsymSimObjChildren.mUID,
         DEPTH_RECURSE);
  if ( v8 )
    v7 = v8->mNumElements;
  v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mName);
  v10 = UFG::Editor::DAGPath::GetObjectHash(v4);
  v11 = UFG::DUIContext::TreeViewItem(v5->mDUI, v9, v10, v7 != 0);
  v12 = v5->mItems;
  v13 = v12->size;
  v14 = v11;
  v15 = v12->capacity;
  v16 = v13 + 1;
  if ( (signed int)v13 + 1 > v15 )
  {
    if ( v15 )
      v6 = 2 * v15;
    for ( ; v6 < v16; v6 *= 2 )
      ;
    if ( v6 - v16 > 0x10000 )
      v6 = v13 + 65537;
    UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(v5->mItems, v6, "qArray.Add");
  }
  v12->size = v16;
  UFG::Editor::DAGPath::operator=(&v12->p[v13], v4);
  if ( v14 )
    UFG::DUIContext::BeginIndent(v5->mDUI);
  if ( v5->mDUI->mDoubleClicked )
    UFG::CommandManager::ExecuteCommand(UFG::gCommandManager, "frame_selected");
  return v14;
}

// File Line: 1219
// RVA: 0x20F6F0
void __fastcall UFG::Editor::UpdateObjectTreeVisitor::OnPopSceneObject(UFG::Editor::UpdateObjectTreeVisitor *this, UFG::Editor::DAGPath *path, UFG::qPropertySet *propertySet)
{
  UFG::DUIContext::EndIndent(this->mDUI);
}

// File Line: 1231
// RVA: 0x215600
void __fastcall UFG::Editor::NewLayerDialog::UpdateEditorUI(UFG::Editor::NewLayerDialog *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  UFG::Editor::NewLayerDialog *v3; // rsi
  const char *v4; // rbx
  char v5; // bl

  v2 = dui;
  v3 = this;
  UFG::DUIContext::Label(dui, "Layer Name");
  v4 = v3->mLayerName.mData;
  if ( !v4
    || UFG::Editor::SceneManager::SceneLayerNameExists(v3->mLayerName.mData)
    || UFG::qStringFind(v4, " ")
    || UFG::qStringFind(v4, "\\")
    || UFG::qStringFind(v4, "/") )
  {
    v5 = 0;
    UFG::DUIContext::PushColour(v2, 0, &UFG::qColour::Red);
  }
  else
  {
    v5 = 1;
  }
  UFG::DUIContext::TextBox(v2, &v3->mLayerName, 0i64, 1, 0i64, 0xFFFFFFFF);
  if ( !v5 )
    UFG::DUIContext::PopColour(v2, 0);
}

// File Line: 1241
// RVA: 0x20F580
char __fastcall UFG::Editor::NewLayerDialog::OnOK(UFG::Editor::NewLayerDialog *this)
{
  char *v1; // rbx
  UFG::Editor::NewLayerDialog *v2; // rdi
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v1 = this->mLayerName.mData;
  v2 = this;
  if ( !v1 )
    return 0;
  if ( UFG::Editor::SceneManager::SceneLayerNameExists(this->mLayerName.mData) )
    return 0;
  if ( UFG::qStringFind(v1, " ") )
    return 0;
  if ( UFG::qStringFind(v1, "\\") )
    return 0;
  if ( UFG::qStringFind(v1, "/") )
    return 0;
  UFG::qSymbol::create_from_string(&result, v2->mLayerName.mData);
  if ( !UFG::Editor::SceneManager::CreateSceneLayer(&result) )
    return 0;
  UFG::Editor::SceneLayerControl::mRefreshFiltered = 1;
  return 1;
}

// File Line: 1259
// RVA: 0x201CB0
void __fastcall UFG::Editor::NewLayerDialog::NewLayerDialog(UFG::Editor::NewLayerDialog *this)
{
  UFG::Editor::NewLayerDialog *v1; // rbx

  v1 = this;
  UFG::Editor::EditorDialog::EditorDialog((UFG::Editor::EditorDialog *)&this->vfptr, "New Layer");
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::NewLayerDialog::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::NewLayerDialog::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  UFG::qString::qString(&v1->mLayerName);
}

// File Line: 1268
// RVA: 0x2156E0
void __fastcall UFG::Editor::RenameLayerDialog::UpdateEditorUI(UFG::Editor::RenameLayerDialog *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rbx
  UFG::Editor::RenameLayerDialog *v3; // rsi
  const char *v4; // rdi
  char v5; // di

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginGridLayout(dui, 2, 1, 4);
  UFG::DUIContext::Label(v2, "Old Layer Name");
  UFG::DUIContext::Label(v2, v3->mPreviousName.mData);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::BeginGridLayout(v2, 2, 1, 4);
  UFG::DUIContext::Label(v2, "New Layer Name");
  v4 = v3->mNewLayerName.mData;
  if ( !v4
    || UFG::Editor::SceneManager::SceneLayerNameExists(v3->mNewLayerName.mData)
    || UFG::qStringFind(v4, " ")
    || UFG::qStringFind(v4, "\\")
    || UFG::qStringFind(v4, "/") )
  {
    v5 = 0;
    UFG::DUIContext::PushColour(v2, 0, &UFG::qColour::Red);
  }
  else
  {
    v5 = 1;
  }
  if ( v3->mFirstUpdate )
    v2->mNextTakesFocus = 1;
  UFG::DUIContext::TextBox(v2, &v3->mNewLayerName, 0i64, 1, 0i64, 0xFFFFFFFF);
  if ( !v5 )
    UFG::DUIContext::PopColour(v2, 0);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  v3->mFirstUpdate = 0;
}

// File Line: 1293
// RVA: 0x20F630
char __fastcall UFG::Editor::RenameLayerDialog::OnOK(UFG::Editor::RenameLayerDialog *this)
{
  char *v1; // rbx
  UFG::Editor::RenameLayerDialog *v2; // rdi
  UFG::qSymbol *v3; // rax
  UFG::qBaseTreeRB *v4; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v1 = this->mNewLayerName.mData;
  v2 = this;
  if ( !v1 )
    return 0;
  if ( UFG::Editor::SceneManager::SceneLayerNameExists(this->mNewLayerName.mData) )
    return 0;
  if ( UFG::qStringFind(v1, " ") )
    return 0;
  if ( UFG::qStringFind(v1, "\\") )
    return 0;
  if ( UFG::qStringFind(v1, "/") )
    return 0;
  v3 = UFG::qSymbol::create_from_string(&result, v2->mPreviousName.mData);
  v4 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, v3);
  if ( !v4 )
    return 0;
  UFG::Editor::SceneManager::RenameSceneLayer((UFG::SceneLayer *)v4, v2->mNewLayerName.mData);
  UFG::Editor::SceneLayerControl::mRefreshFiltered = 1;
  return 1;
}

// File Line: 1317
// RVA: 0x2024E0
void __fastcall UFG::Editor::RenameLayerDialog::RenameLayerDialog(UFG::Editor::RenameLayerDialog *this)
{
  UFG::Editor::RenameLayerDialog *v1; // rbx

  v1 = this;
  UFG::Editor::EditorDialog::EditorDialog((UFG::Editor::EditorDialog *)&this->vfptr, "Rename Layer");
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::RenameLayerDialog::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::RenameLayerDialog::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  UFG::qString::qString(&v1->mNewLayerName);
  UFG::qString::qString(&v1->mPreviousName);
  v1->mFirstUpdate = 1;
}

// File Line: 1330
// RVA: 0x2154D0
void __fastcall UFG::Editor::DuplicateLayerDialog::UpdateEditorUI(UFG::Editor::DuplicateLayerDialog *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rbx
  UFG::Editor::DuplicateLayerDialog *v3; // rsi
  const char *v4; // rdi
  char v5; // di

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginGridLayout(dui, 2, 1, 4);
  UFG::DUIContext::Label(v2, "Old Layer Name");
  UFG::DUIContext::Label(v2, v3->mPreviousName.mData);
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::DUIContext::BeginGridLayout(v2, 2, 1, 4);
  UFG::DUIContext::Label(v2, "New Layer Name");
  v4 = v3->mNewLayerName.mData;
  if ( !v4
    || UFG::Editor::SceneManager::SceneLayerNameExists(v3->mNewLayerName.mData)
    || UFG::qStringFind(v4, " ")
    || UFG::qStringFind(v4, "\\")
    || UFG::qStringFind(v4, "/") )
  {
    v5 = 0;
    UFG::DUIContext::PushColour(v2, 0, &UFG::qColour::Red);
  }
  else
  {
    v5 = 1;
  }
  UFG::DUIContext::TextBox(v2, &v3->mNewLayerName, 0i64, 1, 0i64, 0xFFFFFFFF);
  if ( !v5 )
    UFG::DUIContext::PopColour(v2, 0);
  UFG::DUIContext::EndLayoutHorizontal(v2);
}

// File Line: 1350
// RVA: 0x20F4C0
char __fastcall UFG::Editor::DuplicateLayerDialog::OnOK(UFG::Editor::DuplicateLayerDialog *this)
{
  char *v1; // rbx
  UFG::Editor::DuplicateLayerDialog *v2; // rdi
  UFG::qSymbol *v3; // rax
  UFG::qBaseTreeRB *v4; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v1 = this->mNewLayerName.mData;
  v2 = this;
  if ( !v1 )
    return 0;
  if ( UFG::Editor::SceneManager::SceneLayerNameExists(this->mNewLayerName.mData) )
    return 0;
  if ( UFG::qStringFind(v1, " ") )
    return 0;
  if ( UFG::qStringFind(v1, "\\") )
    return 0;
  if ( UFG::qStringFind(v1, "/") )
    return 0;
  v3 = UFG::qSymbol::create_from_string(&result, v2->mPreviousName.mData);
  v4 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, v3);
  if ( !v4 )
    return 0;
  UFG::Editor::SceneManager::DuplicateSceneLayer((UFG::SceneLayer *)v4, v2->mNewLayerName.mData);
  UFG::Editor::SceneLayerControl::mRefreshFiltered = 1;
  return 1;
}

// File Line: 1373
// RVA: 0x2015C0
void __fastcall UFG::Editor::DuplicateLayerDialog::DuplicateLayerDialog(UFG::Editor::DuplicateLayerDialog *this)
{
  UFG::Editor::DuplicateLayerDialog *v1; // rbx

  v1 = this;
  UFG::Editor::EditorDialog::EditorDialog((UFG::Editor::EditorDialog *)&this->vfptr, "Duplicate Layer");
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::DuplicateLayerDialog::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::DuplicateLayerDialog::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  UFG::qString::qString(&v1->mNewLayerName);
  UFG::qString::qString(&v1->mPreviousName);
}

// File Line: 1443
// RVA: 0x217290
void __fastcall UFG::Editor::SceneLayerControl::UpdateToolbar(UFG::Editor::SceneLayerControl *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rsi
  unsigned int v3; // edi
  UFG::allocator::free_link *v4; // rax
  UFG::DUIWindow *v5; // rax
  UFG::qBaseTreeRB *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  __int64 v8; // rax
  __int64 v9; // r14
  char *v10; // rax
  char *v11; // rax
  UFG::qBaseTreeRB *v12; // rbx
  UFG::allocator::free_link *v13; // rax
  __int64 v14; // rax
  __int64 v15; // r14
  char *v16; // rax
  char *v17; // rax
  UFG::qBaseTreeRB *v18; // rbx
  UFG::Editor::SmartHandleObject *v19; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v20; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v21; // rax
  __int64 v22; // r14
  unsigned int v23; // ebx
  UFG::Editor::DAGPath *v24; // rbx
  UFG::Editor::SmartHandleObject *v25; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v26; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::Event *v29; // rdx
  UFG::allocator::free_link *v30; // rax
  UFG::Editor::SelectionSet *v31; // rax
  UFG::Editor::DAGPathType::Enum *v32; // rbx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v33; // rcx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v34; // rax
  unsigned int *v35; // rbx
  UFG::qSymbol *v36; // rbx
  UFG::Editor::DAGPath item; // [rsp+30h] [rbp-89h]
  UFG::Editor::SelectionSet selectionSet; // [rsp+90h] [rbp-29h]
  __int64 v39; // [rsp+E0h] [rbp+27h]
  UFG::Editor::DAGPath *result; // [rsp+130h] [rbp+77h]
  UFG::allocator::free_link *v41; // [rsp+138h] [rbp+7Fh]

  v39 = -2i64;
  v2 = dui;
  v3 = 1;
  UFG::DUIContext::BeginGridLayout(dui, 4, 1, 0i64, 0i64, 0);
  if ( (unsigned __int8)UFG::DUIContext::Button(v2, "New", 0x10u) )
  {
    v4 = UFG::qMalloc(0x170ui64, UFG::gGlobalNewName, 0i64);
    result = (UFG::Editor::DAGPath *)v4;
    if ( v4 )
      UFG::Editor::NewLayerDialog::NewLayerDialog((UFG::Editor::NewLayerDialog *)v4);
    else
      v5 = 0i64;
    UFG::DUIContext::ShowDialog(v2, v5);
  }
  if ( (unsigned __int8)UFG::DUIContext::Button(v2, "Dupe", 0x10u) )
  {
    if ( stru_142040928.size == 1
      && UFG::Editor::DAGPath::GetSystemName(&gWorkingLayerPath, (UFG::qSymbol *)&result)->mUID == UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID )
    {
      v6 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, stru_142040928.p);
      if ( v6 )
      {
        v7 = UFG::qMalloc(0x198ui64, UFG::gGlobalNewName, 0i64);
        v41 = v7;
        if ( v7 )
        {
          UFG::Editor::DuplicateLayerDialog::DuplicateLayerDialog((UFG::Editor::DuplicateLayerDialog *)v7);
          v9 = v8;
        }
        else
        {
          v9 = 0i64;
        }
        v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v6->mRoot.mUID);
        UFG::qString::Set((UFG::qString *)(v9 + 328), v10);
        v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v6->mRoot.mUID);
        UFG::qString::Set((UFG::qString *)(v9 + 368), v11);
        UFG::DUIContext::ShowDialog(v2, (UFG::DUIWindow *)v9);
      }
    }
  }
  if ( (unsigned __int8)UFG::DUIContext::Button(v2, "Rename", 0x10u) )
  {
    if ( stru_142040928.size == 1
      && UFG::Editor::DAGPath::GetSystemName(&gWorkingLayerPath, (UFG::qSymbol *)&result)->mUID == UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID )
    {
      v12 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, stru_142040928.p);
      if ( v12 )
      {
        v13 = UFG::qMalloc(0x1A0ui64, UFG::gGlobalNewName, 0i64);
        v41 = v13;
        if ( v13 )
        {
          UFG::Editor::RenameLayerDialog::RenameLayerDialog((UFG::Editor::RenameLayerDialog *)v13);
          v15 = v14;
        }
        else
        {
          v15 = 0i64;
        }
        v16 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v12->mRoot.mUID);
        UFG::qString::Set((UFG::qString *)(v15 + 328), v16);
        v17 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v12->mRoot.mUID);
        UFG::qString::Set((UFG::qString *)(v15 + 368), v17);
        UFG::DUIContext::ShowDialog(v2, (UFG::DUIWindow *)v15);
      }
    }
  }
  if ( (unsigned __int8)UFG::DUIContext::Button(v2, "Del", 0x10u) )
  {
    result = &item;
    item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
    item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
    item.mFnObject.mPtr = 0i64;
    item.mFnObject.mTypeId = -1998658210;
    item.mSystemName.mUID = -1;
    item.mElements.p = 0i64;
    *(_QWORD *)&item.mElements.size = 0i64;
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&item.mElements, 4u, "qArray.Reallocate(Constructor)");
    item.mInterfaceName.mUID = -1;
    item.mSubElements.p = 0i64;
    *(_QWORD *)&item.mSubElements.size = 0i64;
    item.mPathType = 0;
    if ( stru_142040928.size != 1
      || UFG::Editor::DAGPath::GetSystemName(&gWorkingLayerPath, (UFG::qSymbol *)&result)->mUID != UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID )
    {
      v18 = 0i64;
    }
    else
    {
      v18 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, stru_142040928.p);
    }
    UFG::Editor::DAGPath::Clear(&item);
    if ( v18 )
    {
      item.mSystemName.mUID = UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID;
      UFG::qArray<UFG::qSymbol,0>::Add(&item.mElements, (UFG::qSymbol *)&v18->mRoot.mUID, "qArray.Add");
      v19 = item.mFnObject.mPtr;
      if ( item.mFnObject.mPtr )
      {
        v20 = item.mFnObject.mPrev;
        v21 = item.mFnObject.mNext;
        item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
        v21->mPrev = v20;
        item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
        item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
        if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v19->mSmartHandleList.mNode.mNext == &v19->mSmartHandleList
          && v19 )
        {
          v19->vfptr->__vecDelDtor(v19, 1u);
        }
        item.mFnObject.mPtr = 0i64;
      }
      item.mFnObject.mPtr = 0i64;
      if ( (item.mElements.size != 0) == 1 )
      {
        selectionSet.mPrev = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&selectionSet;
        selectionSet.mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&selectionSet;
        UFG::qString::qString(&selectionSet.mName, "ToDelete");
        selectionSet.mDAGPaths.p = 0i64;
        *(_QWORD *)&selectionSet.mDAGPaths.size = 0i64;
        if ( (signed int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(&selectionSet.mDAGPaths, &item) <= -1 )
        {
          v22 = selectionSet.mDAGPaths.size;
          v23 = selectionSet.mDAGPaths.size + 1;
          if ( selectionSet.mDAGPaths.size + 1 > selectionSet.mDAGPaths.capacity )
          {
            if ( selectionSet.mDAGPaths.capacity )
              v3 = 2 * selectionSet.mDAGPaths.capacity;
            for ( ; v3 < v23; v3 *= 2 )
              ;
            if ( v3 - v23 > 0x10000 )
              v3 = selectionSet.mDAGPaths.size + 65537;
            UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(&selectionSet.mDAGPaths, v3, "qArray.Add");
          }
          selectionSet.mDAGPaths.size = v23;
          v24 = &selectionSet.mDAGPaths.p[v22];
          if ( &item != v24 )
          {
            UFG::Editor::DAGPath::Clear(&selectionSet.mDAGPaths.p[v22]);
            if ( v24->mPathType == Default )
            {
              v25 = item.mFnObject.mPtr;
              if ( !v24->mFnObject.mPtr )
              {
                if ( item.mFnObject.mPtr )
                {
                  v24->mFnObject.mTypeId = item.mFnObject.mPtr->mTypeId;
                  v24->mFnObject.mPtr = v25;
                  v26 = &v25->mSmartHandleList.mNode;
                  v27 = v26->mPrev;
                  v27->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v24->mFnObject.mPrev;
                  v24->mFnObject.mPrev = v27;
                  v24->mFnObject.mNext = v26;
                  v26->mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&v24->mFnObject.mPrev;
                }
              }
            }
            v24->mSystemName.mUID = item.mSystemName.mUID;
            UFG::qArray<UFG::qSymbol,0>::Clone(&item.mElements, &v24->mElements);
            v24->mInterfaceName.mUID = item.mInterfaceName.mUID;
            UFG::qArray<UFG::qString,0>::Clone(&item.mSubElements, &v24->mSubElements);
          }
          v28 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
          v29 = (UFG::Event *)v28;
          result = (UFG::Editor::DAGPath *)v28;
          if ( v28 )
          {
            v30 = v28 + 1;
            v30->mNext = v30;
            v30[1].mNext = v30;
            v29->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
            v29->m_EventUID = 609910773;
            v29->m_NamePTR = 0i64;
          }
          else
          {
            v29 = 0i64;
          }
          v29->mUserData0 = (unsigned __int64)&selectionSet;
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v29);
        }
        UFG::Editor::Core::DeleteSelection(&selectionSet);
        v31 = UFG::Editor::SelectionManager::GetCreateSelectionSet("Layers");
        v31->mDAGPaths.size = 0;
        UFG::Editor::SelectionSet::DispatchChangedEvent(v31);
        UFG::Editor::SceneLayerControl::mRefreshFiltered = 1;
        if ( selectionSet.mDAGPaths.p )
        {
          v32 = &selectionSet.mDAGPaths.p[-1].mPathType;
          `eh vector destructor iterator'(
            selectionSet.mDAGPaths.p,
            0x58ui64,
            selectionSet.mDAGPaths.p[-1].mPathType,
            (void (__fastcall *)(void *))UFG::Editor::DAGPath::~DAGPath);
          operator delete[](v32);
        }
        selectionSet.mDAGPaths.p = 0i64;
        *(_QWORD *)&selectionSet.mDAGPaths.size = 0i64;
        UFG::qString::~qString(&selectionSet.mName);
        v33 = selectionSet.mPrev;
        v34 = selectionSet.mNext;
        selectionSet.mPrev->mNext = selectionSet.mNext;
        v34->mPrev = v33;
        selectionSet.mPrev = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&selectionSet;
        selectionSet.mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&selectionSet;
      }
    }
    if ( item.mSubElements.p )
    {
      v35 = &item.mSubElements.p[-1].mStringHash32;
      `eh vector destructor iterator'(
        item.mSubElements.p,
        0x28ui64,
        item.mSubElements.p[-1].mStringHash32,
        (void (__fastcall *)(void *))UFG::qString::~qString);
      operator delete[](v35);
    }
    item.mSubElements.p = 0i64;
    *(_QWORD *)&item.mSubElements.size = 0i64;
    if ( item.mElements.p )
    {
      v36 = item.mElements.p - 1;
      `eh vector destructor iterator'(
        item.mElements.p,
        4ui64,
        item.mElements.p[-1].mUID,
        (void (__fastcall *)(void *))_);
      operator delete[](v36);
    }
    item.mElements.p = 0i64;
    *(_QWORD *)&item.mElements.size = 0i64;
    UFG::Editor::TypedSmartHandle<2296309086,UFG::Editor::FnObject>::~TypedSmartHandle<2296309086,UFG::Editor::FnObject>(&item.mFnObject);
  }
  UFG::DUIContext::EndLayoutHorizontal(v2);
}

// File Line: 1498
// RVA: 0x213910
bool __fastcall UFG::Editor::SortByActive(UFG::qString *a, UFG::qString *b)
{
  UFG::qString *v2; // rbx
  UFG::qSymbol *v3; // rax
  UFG::qBaseTreeRB *v4; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qBaseTreeRB *v6; // rax
  char v7; // cl
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]
  UFG::qSymbol v10; // [rsp+38h] [rbp+10h]

  v2 = b;
  v3 = UFG::qSymbol::create_from_string(&result, a->mData);
  v4 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, v3);
  v5 = UFG::qSymbol::create_from_string(&v10, v2->mData);
  v6 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, v5);
  if ( v4 )
    v7 = (LODWORD(v4->mNULL.mChild[1]) >> 1) & 1;
  else
    v7 = 0;
  if ( v6 )
    LOBYTE(v6) = (LODWORD(v6->mNULL.mChild[1]) >> 1) & 1;
  return v7 && !(_BYTE)v6;
}

// File Line: 1509
// RVA: 0x2139A0
bool __fastcall UFG::Editor::SortByType(UFG::qString *a, UFG::qString *b)
{
  UFG::qString *v2; // rbx
  UFG::qSymbol *v3; // rax
  UFG::qBaseTreeRB *v4; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qBaseTreeRB *v6; // rax
  const char *v7; // rdx
  const char *v8; // rcx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]
  UFG::qSymbol v11; // [rsp+38h] [rbp+10h]

  v2 = b;
  v3 = UFG::qSymbol::create_from_string(&result, a->mData);
  v4 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, v3);
  v5 = UFG::qSymbol::create_from_string(&v11, v2->mData);
  v6 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, v5);
  v7 = "Normal";
  if ( v4 )
  {
    v8 = "Normal";
    if ( (LODWORD(v4->mNULL.mChild[1]) >> 14) & 1 )
      v8 = "Geo";
  }
  else
  {
    v8 = "Unloaded";
  }
  if ( v6 )
  {
    if ( (LODWORD(v6->mNULL.mChild[1]) >> 14) & 1 )
      v7 = "Geo";
  }
  else
  {
    v7 = "Unloaded";
  }
  return (signed int)UFG::qStringCompareInsensitive(v8, v7, -1) < 0;
}

// File Line: 1520
// RVA: 0x215830
void __fastcall UFG::Editor::SceneLayerControl::UpdateLayerList(UFG::Editor::SceneLayerControl *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // r15
  UFG::Editor::SceneLayerControl *v3; // r12
  int *sort_index; // r14
  UFG::qNode<UFG::qString,UFG::qString> *i; // rdi
  char *v6; // r8
  char *v7; // rcx
  char v8; // al
  bool v9; // zf
  __int64 v10; // r14
  unsigned int v11; // ebx
  unsigned int v12; // edx
  unsigned int v13; // edx
  int v14; // eax
  bool (__fastcall *v15)(UFG::qString *, UFG::qString *); // r8
  int virtual_row_count; // ebx
  signed __int64 v17; // r13
  UFG::DUIContext *v18; // rax
  __int64 v19; // rax
  signed __int64 v20; // rbx
  UFG::qBaseTreeRB *v21; // rax
  UFG::SceneLayer *v22; // r13
  char v23; // si
  bool v24; // di
  bool v25; // r14
  UFG::CommandContext *v26; // rsi
  const char *v27; // r14
  unsigned int v28; // eax
  UFG::qBaseTreeRB *v29; // rax
  signed __int64 v30; // rax
  UFG::allocator::free_link *v31; // rbx
  int v32; // eax
  UFG::qBaseNodeRB *v33; // rdx
  bool v34; // r9
  bool v35; // dl
  UFG::SceneLayer *v36; // rcx
  UFG::DUIWindow *v37; // rdi
  UFG::Editor::SelectionSet *v38; // rbx
  UFG::Editor::SelectionSet *v39; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v40; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v41; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v42; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v43; // rax
  const char *v44; // rdx
  unsigned int v45; // eax
  UFG::SceneLayer *v46; // r15
  __int64 v47; // rdi
  unsigned int v48; // ebx
  unsigned int v49; // edx
  UFG::Editor::SmartHandleObject *v50; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v51; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v52; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v53; // rbx
  UFG::allocator::free_link *v54; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v55; // rax
  UFG::allocator::free_link *v56; // rax
  UFG::Event *v57; // rdx
  UFG::allocator::free_link *v58; // rax
  __int64 v59; // r14
  unsigned int v60; // edi
  unsigned int v61; // edx
  unsigned int v62; // edx
  signed __int64 v63; // rdi
  UFG::Editor::SmartHandleObject *v64; // rcx
  __int64 *v65; // rcx
  __int64 v66; // rax
  UFG::allocator::free_link *v67; // rax
  UFG::Event *v68; // rdx
  UFG::allocator::free_link *v69; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v70; // rdi
  UFG::allocator::free_link *v71; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v72; // rax
  UFG::allocator::free_link *v73; // rax
  UFG::Event *v74; // rdx
  UFG::allocator::free_link *v75; // rax
  unsigned int *v76; // rbx
  UFG::qSymbol *v77; // rbx
  UFG::Editor::SmartHandleObject *v78; // r8
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v79; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v80; // rax
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v86; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v87; // rax
  bool v88; // [rsp+50h] [rbp-B0h]
  bool current_value; // [rsp+51h] [rbp-AFh]
  bool v90; // [rsp+52h] [rbp-AEh]
  UFG::Editor::DAGPath item; // [rsp+60h] [rbp-A0h]
  int v92; // [rsp+C0h] [rbp-40h]
  UFG::qSymbol name; // [rsp+C4h] [rbp-3Ch]
  UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> v94; // [rsp+C8h] [rbp-38h]
  int column_widths; // [rsp+E0h] [rbp-20h]
  int v96; // [rsp+E4h] [rbp-1Ch]
  int v97; // [rsp+E8h] [rbp-18h]
  UFG::DUIRect rect; // [rsp+F0h] [rbp-10h]
  UFG::DUIIntArray *v99; // [rsp+100h] [rbp+0h]
  __int64 v100; // [rsp+108h] [rbp+8h]
  void *v101; // [rsp+110h] [rbp+10h]
  UFG::DUIRect result; // [rsp+118h] [rbp+18h]
  UFG::CommandContext *v103; // [rsp+128h] [rbp+28h]
  UFG::qString v104; // [rsp+130h] [rbp+30h]
  __int64 v105; // [rsp+158h] [rbp+58h]
  UFG::DUIRect out_rect; // [rsp+160h] [rbp+60h]
  UFG::Editor::SceneLayerControl *v107; // [rsp+1B0h] [rbp+B0h]
  char v108; // [rsp+1C0h] [rbp+C0h]
  bool out_is_selected; // [rsp+1C8h] [rbp+C8h]

  v107 = this;
  v105 = -2i64;
  v2 = dui;
  v3 = this;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  column_widths = 22;
  v96 = result.mW - 120;
  v97 = 60;
  v108 = 0;
  if ( UFG::Editor::SceneLayerControl::mRefreshFiltered
    || (sort_index = &v3->mSortIndex, v3->mSortIndex != v3->mOldSortIndex) )
  {
    v3->mFilteredList.size = 0;
    for ( i = SceneLayerList.mNode.mNext; i != (UFG::qNode<UFG::qString,UFG::qString> *)&SceneLayerList; i = i->mNext )
    {
      if ( v3->mFilter_Text.mLength )
      {
        v6 = v3->mFilter_Text.mData;
        if ( v6 && (v7 = v3->mFilter_Text.mData, (v8 = *v6) != 0) )
        {
          while ( v8 != 42 && v8 != 63 )
          {
            v8 = *++v7;
            if ( !*v7 )
              goto LABEL_12;
          }
          v9 = (unsigned int)UFG::qWildcardMatchInsensitive(v3->mFilter_Text.mData, (const char *)i[1].mNext) == 0;
        }
        else
        {
LABEL_12:
          v9 = UFG::qStringFindInsensitive((const char *)i[1].mNext, v3->mFilter_Text.mData) == 0i64;
        }
        if ( v9 )
          continue;
      }
      v10 = v3->mFilteredList.size;
      v11 = v10 + 1;
      v12 = v3->mFilteredList.capacity;
      if ( (signed int)v10 + 1 > v12 )
      {
        if ( v12 )
          v13 = 2 * v12;
        else
          v13 = 1;
        for ( ; v13 < v11; v13 *= 2 )
          ;
        if ( v13 - v11 > 0x10000 )
          v13 = v10 + 65537;
        UFG::qArray<UFG::qString,0>::Reallocate(&v3->mFilteredList, v13, "qArray.Add");
      }
      v3->mFilteredList.size = v11;
      UFG::qString::Set(&v3->mFilteredList.p[v10], (const char *)i[1].mNext, HIDWORD(i[1].mPrev), 0i64, 0);
    }
    sort_index = &v3->mSortIndex;
    v14 = v3->mSortIndex;
    if ( v14 )
    {
      if ( v14 == 1 )
      {
        v15 = UFG::Editor::SortByName;
      }
      else
      {
        if ( v14 != 2 )
        {
LABEL_32:
          v3->mOldSortIndex = *sort_index;
          UFG::Editor::SceneLayerControl::mRefreshFiltered = 0;
          goto LABEL_33;
        }
        v15 = UFG::Editor::SortByType;
      }
    }
    else
    {
      v15 = UFG::Editor::SortByActive;
    }
    UFG::qQuickSortImpl<UFG::qString,bool (*)(UFG::qString const &,UFG::qString const &)>(
      v3->mFilteredList.p,
      &v3->mFilteredList.p[(signed int)v3->mFilteredList.size - 1i64],
      v15);
    goto LABEL_32;
  }
LABEL_33:
  virtual_row_count = v3->mFilteredList.size;
  v17 = (signed __int64)&v3->mLayer_SelectedItems;
  v99 = &v3->mLayer_SelectedItems;
  v18 = UFG::DUIContext::SetLayoutRect(v2, &result);
  UFG::DUIContext::BeginDataGrid(
    v18,
    3,
    headings,
    &column_widths,
    (UFG::IDUICollectionView *)&v3->mLayer_SelectedItems.vfptr,
    &v3->mLayer_ScrollPos,
    sort_index,
    0,
    virtual_row_count,
    &v3->mMetrics);
  v19 = (unsigned int)v3->mMetrics.mStart;
  v92 = v19;
  if ( (unsigned int)v19 < v3->mMetrics.mEnd )
  {
    while ( 1 )
    {
      v20 = (signed __int64)&v3->mFilteredList.p[v19];
      v100 = v20;
      UFG::qSymbol::create_from_string(&name, *(const char **)(v20 + 24));
      v21 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, &name);
      v22 = (UFG::SceneLayer *)v21;
      v23 = v21 != 0i64;
      v90 = v21 != 0i64;
      if ( v21 )
        v24 = (LODWORD(v21->mNULL.mChild[1]) >> 1) & 1;
      else
        v24 = 0;
      out_is_selected = 0;
      v108 |= UFG::DUIContext::BeginDataGridItem(v2, name.mUID, &out_is_selected, &out_rect);
      v25 = v2->mDoubleClicked;
      v88 = v25;
      if ( v25 )
      {
        UFG::DUIInputState::ConsumeMouseButtonEvents(&v2->mInputState);
      }
      else if ( v2->mInputState.mMouseRBWentUp && UFG::DUIContext::IsMouseOver(v2, &out_rect) )
      {
        UFG::DUIInputState::ConsumeMouseButtonEvents(&v2->mInputState);
        v26 = (UFG::CommandContext *)UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
        v103 = v26;
        if ( v26 )
        {
          v26->vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable';
          v101 = &v26->mDictionary;
          UFG::qBaseTreeRB::qBaseTreeRB(&v26->mDictionary.mTree);
        }
        else
        {
          v26 = 0i64;
        }
        v27 = UFG::Editor::SceneManager::SceneLayerContext;
        v28 = UFG::qStringHashUpper32(UFG::Editor::SceneManager::SceneLayerContext, 0xFFFFFFFF);
        if ( v28
          && (v29 = UFG::qBaseTreeRB::Get(&v26->mDictionary.mTree, v28)) != 0i64
          && (v30 = (signed __int64)&v29[-1].mCount) != 0 )
        {
          *(_QWORD *)(v30 + 40) = v22;
        }
        else
        {
          v31 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
          v101 = v31;
          if ( v31 )
          {
            v32 = UFG::qStringHashUpper32(v27, 0xFFFFFFFF);
            v31[1].mNext = 0i64;
            v31[2].mNext = 0i64;
            v31[3].mNext = 0i64;
            LODWORD(v31[4].mNext) = v32;
            v31->mNext = (UFG::allocator::free_link *)&UFG::ContextDataBase::`vftable';
            v31->mNext = (UFG::allocator::free_link *)&UFG::ContextData<UFG::SceneLayer *>::`vftable';
            v31[5].mNext = (UFG::allocator::free_link *)v22;
          }
          else
          {
            v31 = 0i64;
          }
          v33 = (UFG::qBaseNodeRB *)&v31[1];
          if ( !v31 )
            v33 = 0i64;
          UFG::qBaseTreeRB::Add(&v26->mDictionary.mTree, v33);
          v20 = v100;
        }
        UFG::DUIContext::ShowPopupMenu(v2, &v2->mInputState.mMousePos, UFG::Editor::SceneLayerControl::Commands, v26);
        v3 = v107;
        v23 = v90;
        v25 = v88;
      }
      current_value = v24;
      if ( (unsigned __int8)UFG::DUIContext::Checkbox(v2, 0i64, &current_value) )
      {
        if ( v24 )
          goto LABEL_63;
        if ( !v23 )
        {
          v22 = 0i64;
          goto LABEL_63;
        }
        v22 = (UFG::SceneLayer *)UFG::Editor::Core::OpenForEdit(v22);
        v34 = 0;
        v35 = 1;
        v36 = v22;
      }
      else
      {
        if ( !v24 )
          goto LABEL_63;
        v34 = 1;
        v35 = 0;
        v36 = v22;
      }
      UFG::SceneLayer::EnableActivate(v36, v35, 0, v34);
LABEL_63:
      UFG::qString::qString(&v104);
      if ( v23 && (v22->mFlags >> 3) & 1 )
        UFG::qString::Set(&v104, pattern, 1, *(const char **)(v20 + 24), *(_DWORD *)(v20 + 20));
      else
        UFG::qString::Set(&v104, *(const char **)(v20 + 24), *(_DWORD *)(v20 + 20), 0i64, 0);
      UFG::DUIContext::Label(v2, v104.mData);
      if ( v25 )
      {
        rect.mX = v2->mLastRect.mX;
        rect.mY = v2->mLastRect.mY;
        rect.mW = v2->mLastRect.mW;
        rect.mH = v2->mLastRect.mH;
        if ( UFG::DUIContext::IsMouseOver(v2, &rect) )
        {
          UFG::Editor::EditorWindowManager::CreateWindow(&v94, "UFG::Editor::SceneLayerPropertiesWindow");
          v37 = v94.m_pPointer;
          if ( v94.m_pPointer && !LOBYTE(v94.m_pPointer[1].mBaseNode.mNeighbours[1]) )
          {
            v38 = UFG::Editor::SelectionManager::GetCreateSelectionSet((const char *)v94.m_pPointer[1].vfptr);
            v38->mDAGPaths.size = 0;
            UFG::Editor::SelectionSet::DispatchChangedEvent(v38);
            v39 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::GetSelectionSet("Layers");
            UFG::Editor::SelectionSet::Add(v38, v39);
            LOBYTE(v37[1].mBaseNode.mNeighbours[1]) = 1;
          }
          if ( v94.m_pPointer )
          {
            v40 = v94.mPrev;
            v41 = v94.mNext;
            v94.mPrev->mNext = v94.mNext;
            v41->mPrev = v40;
            v94.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *)&v94;
            v94.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *)&v94;
          }
          v94.m_pPointer = 0i64;
          v42 = v94.mPrev;
          v43 = v94.mNext;
          v94.mPrev->mNext = v94.mNext;
          v43->mPrev = v42;
          v94.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *)&v94;
          v94.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *)&v94;
        }
      }
      if ( v23 )
      {
        v44 = "Normal";
        if ( (v22->mFlags >> 14) & 1 )
          v44 = "Geo";
      }
      else
      {
        v44 = "Unloaded";
      }
      UFG::DUIContext::Label(v2, v44);
      UFG::qString::~qString(&v104);
      UFG::DUIContext::EndDataGridItem(v2);
      v19 = (unsigned int)(v92 + 1);
      v92 = v19;
      if ( (unsigned int)v19 >= v3->mMetrics.mEnd )
      {
        v17 = (signed __int64)v99;
        break;
      }
    }
  }
  UFG::DUIContext::EndDataGrid(v2);
  if ( v108 )
  {
    v45 = (*(__int64 (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v17 + 24i64))(v17, 0i64);
    if ( v45 )
    {
      v46 = (UFG::SceneLayer *)UFG::qBaseTreeRB::Get(&UFG::Scene::msDefault.mLayers.mTree, v45);
      if ( v46 )
      {
        item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
        item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
        item.mFnObject.mPtr = 0i64;
        item.mFnObject.mTypeId = -1998658210;
        item.mSystemName.mUID = -1;
        item.mElements.p = 0i64;
        *(_QWORD *)&item.mElements.size = 0i64;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(&item.mElements, 4u, "qArray.Reallocate(Constructor)");
        item.mInterfaceName.mUID = -1;
        item.mSubElements.p = 0i64;
        *(_QWORD *)&item.mSubElements.size = 0i64;
        item.mPathType = 0;
        UFG::Editor::DAGPath::Clear(&item);
        item.mSystemName.mUID = UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID;
        v47 = item.mElements.size;
        v48 = item.mElements.size + 1;
        if ( item.mElements.size + 1 > item.mElements.capacity )
        {
          if ( item.mElements.capacity )
            v49 = 2 * item.mElements.capacity;
          else
            v49 = 1;
          for ( ; v49 < v48; v49 *= 2 )
            ;
          if ( v49 <= 4 )
            v49 = 4;
          if ( v49 - v48 > 0x10000 )
            v49 = item.mElements.size + 65537;
          UFG::qArray<UFG::qSymbol,0>::Reallocate(&item.mElements, v49, "qArray.Add");
        }
        item.mElements.size = v48;
        item.mElements.p[v47].mUID = v46->mNode.mUID;
        v50 = item.mFnObject.mPtr;
        if ( item.mFnObject.mPtr )
        {
          v51 = item.mFnObject.mPrev;
          v52 = item.mFnObject.mNext;
          item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
          v52->mPrev = v51;
          item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v50->mSmartHandleList.mNode.mNext == &v50->mSmartHandleList
            && v50 )
          {
            v50->vfptr->__vecDelDtor(v50, 1u);
          }
          item.mFnObject.mPtr = 0i64;
        }
        item.mFnObject.mPtr = 0i64;
        v53 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
        if ( (UFG::qList<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet,1,0> *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext == &UFG::Editor::SelectionManager::mSelectionSets )
        {
LABEL_104:
          v54 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
          v53 = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)v54;
          if ( v54 )
          {
            v54->mNext = v54;
            v54[1].mNext = v54;
            UFG::qString::qString((UFG::qString *)&v54[2], "Layers");
            v53[4].mPrev = 0i64;
            v53[3].mNext = 0i64;
          }
          else
          {
            v53 = 0i64;
          }
          v55 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev;
          UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev->mNext = v53;
          v53->mPrev = v55;
          v53->mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets;
          UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev = v53;
        }
        else
        {
          while ( (unsigned int)UFG::qStringCompare("Layers", (const char *)v53[2].mNext, -1) )
          {
            v53 = v53->mNext;
            if ( v53 == (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets )
              goto LABEL_104;
          }
        }
        LODWORD(v53[3].mNext) = 0;
        v56 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
        v57 = (UFG::Event *)v56;
        if ( v56 )
        {
          v58 = v56 + 1;
          v58->mNext = v58;
          v58[1].mNext = v58;
          v57->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
          v57->m_EventUID = 609910773;
          v57->m_NamePTR = 0i64;
        }
        else
        {
          v57 = 0i64;
        }
        v57->mUserData0 = (unsigned __int64)v53;
        UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v57);
        if ( (signed int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(
                           (UFG::qArray<UFG::Editor::DAGPath,0> *)&v53[3].mNext,
                           &item) <= -1 )
        {
          v59 = LODWORD(v53[3].mNext);
          v60 = v59 + 1;
          v61 = HIDWORD(v53[3].mNext);
          if ( (signed int)v59 + 1 > v61 )
          {
            if ( v61 )
              v62 = 2 * v61;
            else
              v62 = 1;
            for ( ; v62 < v60; v62 *= 2 )
              ;
            if ( v62 - v60 > 0x10000 )
              v62 = v59 + 65537;
            UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(
              (UFG::qArray<UFG::Editor::DAGPath,0> *)&v53[3].mNext,
              v62,
              "qArray.Add");
          }
          LODWORD(v53[3].mNext) = v60;
          v63 = (signed __int64)v53[4].mPrev + 88 * v59;
          if ( &item != (UFG::Editor::DAGPath *)v63 )
          {
            UFG::Editor::DAGPath::Clear((UFG::Editor::DAGPath *)v53[4].mPrev + v59);
            if ( !*(_DWORD *)(v63 + 80) )
            {
              v64 = item.mFnObject.mPtr;
              if ( !*(_QWORD *)(v63 + 16) )
              {
                if ( item.mFnObject.mPtr )
                {
                  *(_DWORD *)(v63 + 24) = item.mFnObject.mPtr->mTypeId;
                  *(_QWORD *)(v63 + 16) = v64;
                  v65 = (__int64 *)&v64->mSmartHandleList;
                  v66 = *v65;
                  *(_QWORD *)(v66 + 8) = v63;
                  *(_QWORD *)v63 = v66;
                  *(_QWORD *)(v63 + 8) = v65;
                  *v65 = v63;
                }
              }
            }
            *(_DWORD *)(v63 + 32) = item.mSystemName.mUID;
            UFG::qArray<UFG::qSymbol,0>::Clone(&item.mElements, (UFG::qArray<UFG::qSymbol,0> *)(v63 + 40));
            *(_DWORD *)(v63 + 56) = item.mInterfaceName.mUID;
            UFG::qArray<UFG::qString,0>::Clone(&item.mSubElements, (UFG::qArray<UFG::qString,0> *)(v63 + 64));
          }
          v67 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
          v68 = (UFG::Event *)v67;
          if ( v67 )
          {
            v69 = v67 + 1;
            v69->mNext = v69;
            v69[1].mNext = v69;
            v68->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
            v68->m_EventUID = 609910773;
            v68->m_NamePTR = 0i64;
          }
          else
          {
            v68 = 0i64;
          }
          v68->mUserData0 = (unsigned __int64)v53;
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v68);
        }
        v70 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
        if ( (UFG::qList<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet,1,0> *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext == &UFG::Editor::SelectionManager::mSelectionSets )
        {
LABEL_134:
          v71 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
          v70 = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)v71;
          if ( v71 )
          {
            v71->mNext = v71;
            v71[1].mNext = v71;
            UFG::qString::qString((UFG::qString *)&v71[2], "LastSelection");
            v70[4].mPrev = 0i64;
            v70[3].mNext = 0i64;
          }
          else
          {
            v70 = 0i64;
          }
          v72 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev;
          UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev->mNext = v70;
          v70->mPrev = v72;
          v70->mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets;
          UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev = v70;
        }
        else
        {
          while ( (unsigned int)UFG::qStringCompare("LastSelection", (const char *)v70[2].mNext, -1) )
          {
            v70 = v70->mNext;
            if ( v70 == (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets )
              goto LABEL_134;
          }
        }
        LODWORD(v70[3].mNext) = 0;
        v73 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
        v74 = (UFG::Event *)v73;
        if ( v73 )
        {
          v75 = v73 + 1;
          v75->mNext = v75;
          v75[1].mNext = v75;
          v74->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
          v74->m_EventUID = 609910773;
          v74->m_NamePTR = 0i64;
        }
        else
        {
          v74 = 0i64;
        }
        v74->mUserData0 = (unsigned __int64)v70;
        UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v74);
        UFG::Editor::SelectionSet::Add((UFG::Editor::SelectionSet *)v70, (UFG::Editor::SelectionSet *)v53);
        UFG::Editor::SceneManager::SetWorkingLayer(v46);
        if ( item.mSubElements.p )
        {
          v76 = &item.mSubElements.p[-1].mStringHash32;
          `eh vector destructor iterator'(
            item.mSubElements.p,
            0x28ui64,
            item.mSubElements.p[-1].mStringHash32,
            (void (__fastcall *)(void *))UFG::qString::~qString);
          operator delete[](v76);
        }
        item.mSubElements.p = 0i64;
        *(_QWORD *)&item.mSubElements.size = 0i64;
        if ( item.mElements.p )
        {
          v77 = item.mElements.p - 1;
          `eh vector destructor iterator'(
            item.mElements.p,
            4ui64,
            item.mElements.p[-1].mUID,
            (void (__fastcall *)(void *))_);
          operator delete[](v77);
        }
        item.mElements.p = 0i64;
        *(_QWORD *)&item.mElements.size = 0i64;
        v78 = item.mFnObject.mPtr;
        if ( item.mFnObject.mPtr )
        {
          v79 = item.mFnObject.mPrev;
          v80 = item.mFnObject.mNext;
          item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
          v80->mPrev = v79;
          item.mFnObject.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v78->mSmartHandleList.mNode.mNext == &v78->mSmartHandleList
            && v78 )
          {
            v78->vfptr->__vecDelDtor(v78, 1u);
          }
          item.mFnObject.mPtr = 0i64;
        }
        item.mFnObject.mPtr = 0i64;
        v86 = item.mFnObject.mPrev;
        v87 = item.mFnObject.mNext;
        item.mFnObject.mPrev->mNext = item.mFnObject.mNext;
        v87->mPrev = v86;
      }
    }
  }
}martHandleList> *)&item;
          item.mFnObject.mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)&item;
          if ( (UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *)v78->mSmartHandleList.mNode.mNext == &v78->mSmartHandleList
            && v78 )
          {
        

// File Line: 1667
// RVA: 0x21CF20
void __fastcall UFG::Editor::SceneLayerControl::UpdateUI(UFG::Editor::SceneLayerControl *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rdi
  UFG::Editor::SceneLayerControl *v3; // rbx
  UFG::DUIContext *v4; // rax
  char v5; // al
  char v6; // cl
  UFG::DUIRect result; // [rsp+30h] [rbp-18h]
  int row_heights; // [rsp+50h] [rbp+8h]
  int v9; // [rsp+54h] [rbp+Ch]

  v2 = dui;
  v3 = this;
  UFG::DUIContext::GetLayoutRect(dui, &result, 0, 0);
  row_heights = 50;
  v9 = result.mH - 50;
  v4 = UFG::DUIContext::SetLayoutRect(v2, &result);
  UFG::DUIContext::BeginGridLayout(v4, 1, 2, 0i64, &row_heights, 0);
  UFG::DUIContext::BeginVerticalLayout(v2);
  UFG::Editor::SceneLayerControl::UpdateToolbar(v3, v2);
  UFG::DUIContext::Separator(v2);
  v5 = UFG::DUIContext::TextBox(v2, &v3->mFilter_Text, "Search...", 1, 0i64, 0xFFFFFFFF);
  v6 = UFG::Editor::SceneLayerControl::mRefreshFiltered;
  if ( v5 )
    v6 = 1;
  UFG::Editor::SceneLayerControl::mRefreshFiltered = v6;
  UFG::DUIContext::EndLayoutHorizontal(v2);
  UFG::Editor::SceneLayerControl::UpdateLayerList(v3, v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
}

// File Line: 1697
// RVA: 0x202790
void __fastcall UFG::Editor::SceneLayerPropertiesWindow::SceneLayerPropertiesWindow(UFG::Editor::SceneLayerPropertiesWindow *this)
{
  UFG::Editor::SceneLayerPropertiesWindow *v1; // rbx
  UFG::DUIIntArray *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::DUIWindow::DUIWindow((UFG::DUIWindow *)&this->vfptr);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::qReflectObjectType<UFG::Editor::SceneLayerPropertiesWindow,UFG::DUIWindow>::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v1->mBaseNode.mUID = -1i64;
  v1->mTypeUID = UFG::qStringHash64("UFG::Editor::SceneLayerPropertiesWindow", 0xFFFFFFFFFFFFFFFFui64);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::Editor::SceneLayerPropertiesWindow::`vftable'{for `UFG::qReflectObjectType<UFG::DUIWindow,UFG::qReflectObject>'};
  v1->vfptr = (UFG::qSafePointerNode<UFG::DUIWindow>Vtbl *)&UFG::Editor::SceneLayerPropertiesWindow::`vftable'{for `UFG::qSafePointerNode<UFG::DUIWindow>'};
  v2 = &v1->mSceneObject_ExpandedItems;
  v2->vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable';
  v2->mData.p = 0i64;
  *(_QWORD *)&v2->mData.size = 0i64;
  UFG::qString::qString(&v1->mLockedSelection);
  v1->mGridWidths[0] = 50;
  v1->mGridWidths[1] = 50;
  UFG::Editor::SceneLayerPropertiesWindow::Init(v1);
  v1->mRect.mW = 250;
  v1->mRect.mH = 400;
}

// File Line: 1707
// RVA: 0x20D790
void __fastcall UFG::Editor::SceneLayerPropertiesWindow::Init(UFG::Editor::SceneLayerPropertiesWindow *this)
{
  UFG::Editor::SceneLayerPropertiesWindow *v1; // rbx
  __int64 v2; // r8
  UFG::qString *v3; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v1 = this;
  UFG::qString::Set(&this->mTitle, "Layer Hierarchy");
  v2 = (unsigned int)nextSelSetIdx_0--;
  v3 = UFG::qString::FormatEx(&result, "SceneLayerProperties(%x)", v2);
  UFG::qString::Set(&v1->mLockedSelection, v3->mData, v3->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  UFG::Editor::SelectionManager::GetCreateSelectionSet(v1->mLockedSelection.mData);
  UFG::Editor::SelectionManager::GetCreateSelectionSet("Layers");
  v1->mLockSelection = 0;
}

// File Line: 1721
// RVA: 0x212B40
void __fastcall UFG::Editor::SceneLayerPropertiesWindow::SetLockSelection(UFG::Editor::SceneLayerPropertiesWindow *this, bool locked)
{
  bool v2; // al
  UFG::Editor::SceneLayerPropertiesWindow *v3; // rdi
  UFG::Editor::SelectionSet *v4; // rbx
  UFG::Editor::SelectionSet *v5; // rax

  v2 = this->mLockSelection;
  v3 = this;
  if ( !v2 )
    goto LABEL_9;
  if ( !locked )
  {
    this->mLockSelection = 0;
    return;
  }
  if ( !v2 )
  {
LABEL_9:
    if ( locked )
    {
      v4 = UFG::Editor::SelectionManager::GetCreateSelectionSet(this->mLockedSelection.mData);
      v4->mDAGPaths.size = 0;
      UFG::Editor::SelectionSet::DispatchChangedEvent(v4);
      v5 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::GetSelectionSet("Layers");
      UFG::Editor::SelectionSet::Add(v4, v5);
      v3->mLockSelection = 1;
    }
  }
}

// File Line: 1737
// RVA: 0x216AC0
void __fastcall UFG::Editor::SceneLayerPropertiesWindow::UpdateSceneObjectTree(UFG::Editor::SceneLayerPropertiesWindow *this, UFG::DUIContext *dui, UFG::SceneLayer *layer)
{
  UFG::SceneLayer *v3; // rdi
  UFG::DUIContext *v4; // rbx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v5; // r13
  unsigned int v6; // er15
  signed __int64 v7; // rax
  unsigned int v8; // er9
  unsigned __int64 v9; // rdx
  unsigned int v10; // er8
  __int64 v11; // r10
  unsigned __int64 v12; // rcx
  UFG::RoadNetworkNode *v13; // r12
  __int64 v14; // r14
  unsigned int v15; // edi
  unsigned int v16; // ebx
  unsigned __int64 v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::RoadNetworkNode **v19; // rsi
  UFG::RoadNetworkNode **v20; // r9
  __int64 v21; // r8
  UFG::RoadNetworkNode **v22; // r12
  int v23; // edx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v24; // r13
  UFG::allocator::free_link *v25; // rax
  UFG::Event *v26; // rdx
  UFG::allocator::free_link *v27; // rax
  int v28; // er15
  unsigned int v29; // er8
  char *v30; // rdi
  unsigned __int64 v31; // rdx
  unsigned int v32; // er9
  unsigned int v33; // er10
  __int64 v34; // r11
  unsigned __int64 v35; // rcx
  __int64 v36; // rsi
  unsigned int v37; // ebx
  unsigned int v38; // edx
  unsigned int v39; // edx
  signed __int64 v40; // rbx
  __int64 v41; // rcx
  signed __int64 *v42; // rcx
  signed __int64 v43; // rax
  UFG::allocator::free_link *v44; // rax
  UFG::Event *v45; // rdx
  UFG::allocator::free_link *v46; // rax
  int v47; // ebx
  unsigned int v48; // edx
  UFG::qBaseTreeRB *v49; // rax
  UFG::Editor::SmartHandleObject *v50; // rax
  UFG::qList<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList,1,0> *v51; // rcx
  UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *v52; // rax
  __int64 v53; // rax
  unsigned int v54; // ecx
  unsigned int v55; // edx
  __int64 v56; // r8
  __int64 v57; // rax
  __int64 v58; // r8
  __int64 v59; // r8
  UFG::qPropertySet *v60; // rax
  char *v61; // rax
  UFG::qPropertySet *v62; // rax
  UFG::Editor::SelectionSet *v63; // rdi
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v64; // rbx
  UFG::allocator::free_link *v65; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v66; // rax
  UFG::allocator::free_link *v67; // rax
  UFG::Event *v68; // rdx
  UFG::allocator::free_link *v69; // rax
  char *v70; // rbx
  __int64 v71; // [rsp+8h] [rbp-41h]
  void *ptr; // [rsp+10h] [rbp-39h]
  UFG::IDUICollectionView selected_items; // [rsp+18h] [rbp-31h]
  UFG::qArray<UFG::RoadNetworkNode *,0> v74; // [rsp+20h] [rbp-29h]
  UFG::qArray<UFG::RoadNetworkNode *,0> _dst; // [rsp+38h] [rbp-11h]
  UFG::Editor::SceneManager::SceneObjectVisitor v76; // [rsp+48h] [rbp-1h]
  UFG::DUIContext *v77; // [rsp+58h] [rbp+Fh]
  __int64 *v78; // [rsp+60h] [rbp+17h]
  UFG::IDUICollectionView *v79; // [rsp+B0h] [rbp+67h]
  UFG::DUIContext *v80; // [rsp+B8h] [rbp+6Fh]
  UFG::allocator::free_link *v81; // [rsp+C0h] [rbp+77h]

  v3 = layer;
  v4 = dui;
  v5 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  selected_items.vfptr = (UFG::IDUICollectionViewVtbl *)&UFG::DUIIntArray::`vftable';
  v74.p = 0i64;
  *(_QWORD *)&v74.size = 0i64;
  v6 = 0;
  if ( LODWORD(UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext) > 0 )
  {
    do
    {
      v7 = (signed __int64)v5[4].mPrev + 88 * v6;
      v8 = *(_DWORD *)(v7 + 40);
      if ( v8 )
      {
        LODWORD(v9) = *(_DWORD *)(v7 + 32);
        v10 = 0;
        do
        {
          v11 = *(_QWORD *)(v7 + 48);
          v12 = 65
              * (21
               * (((((unsigned int)v9 | ((unsigned __int64)*(unsigned int *)(v11 + 4i64 * v10) << 32)) << 18)
                 + ~((unsigned int)v9 | ((unsigned __int64)*(unsigned int *)(v11 + 4i64 * v10) << 32))) ^ (((((unsigned int)v9 | ((unsigned __int64)*(unsigned int *)(v11 + 4i64 * v10) << 32)) << 18) + ~((unsigned int)v9 | ((unsigned __int64)*(unsigned int *)(v11 + 4i64 * v10) << 32))) >> 31)) ^ (21 * (((((unsigned int)v9 | ((unsigned __int64)*(unsigned int *)(v11 + 4i64 * v10) << 32)) << 18) + ~((unsigned int)v9 | ((unsigned __int64)*(unsigned int *)(v11 + 4i64 * v10) << 32))) ^ (((((unsigned int)v9 | ((unsigned __int64)*(unsigned int *)(v11 + 4i64 * v10) << 32)) << 18) + ~((unsigned int)v9 | ((unsigned __int64)*(unsigned int *)(v11 + 4i64 * v10) << 32))) >> 31)) >> 11));
          v9 = v12 ^ (v12 >> 22);
          ++v10;
        }
        while ( v10 < v8 );
        v13 = (UFG::RoadNetworkNode *)(unsigned int)v9;
        v14 = v74.size;
        v15 = v74.size + 1;
        if ( v74.size + 1 <= v74.capacity )
          goto LABEL_119;
        if ( v74.capacity )
          v16 = 2 * v74.capacity;
        else
          v16 = 1;
        for ( ; v16 < v15; v16 *= 2 )
          ;
        if ( v16 <= 2 )
          v16 = 2;
        if ( v16 - v15 > 0x10000 )
          v16 = v74.size + 65537;
        if ( v16 == v74.size )
        {
LABEL_119:
          v19 = v74.p;
        }
        else
        {
          v17 = 8i64 * v16;
          if ( !is_mul_ok(v16, 8ui64) )
            v17 = -1i64;
          v18 = UFG::qMalloc(v17, "qArray.Add", 0i64);
          v19 = (UFG::RoadNetworkNode **)v18;
          v20 = v74.p;
          if ( v74.p )
          {
            v21 = 0i64;
            if ( v74.size )
            {
              do
              {
                v18[v21].mNext = (UFG::allocator::free_link *)v20[v21];
                v21 = (unsigned int)(v21 + 1);
                v20 = v74.p;
              }
              while ( (unsigned int)v21 < v74.size );
            }
            operator delete[](v20);
          }
          v74.p = v19;
          v74.capacity = v16;
        }
        v74.size = v15;
        v19[v14] = v13;
      }
      ++v6;
    }
    while ( v6 < LODWORD(v5[3].mNext) );
    v4 = v80;
    v3 = (UFG::SceneLayer *)v81;
  }
  _dst.p = 0i64;
  *(_QWORD *)&_dst.size = 0i64;
  UFG::qArray<UFG::qPropertySet *,0>::Clone(&v74, &_dst);
  ptr = 0i64;
  v71 = 0i64;
  UFG::DUIContext::BeginTreeView(v4, &selected_items, v79 + 42, 1);
  if ( v3 )
  {
    v76.mPropertyDepth = 1;
    v76.vfptr = (UFG::Editor::SceneManager::SceneObjectVisitorVtbl *)&UFG::Editor::UpdateObjectTreeVisitor::`vftable';
    v77 = v4;
    v78 = &v71;
    UFG::Editor::SceneManager::SceneObjectVisitor::Visit(&v76, v3);
  }
  UFG::DUIContext::EndTreeView(v4);
  v22 = _dst.p;
  if ( _dst.size == v74.size )
  {
    v23 = 0;
    if ( !v74.size )
      goto LABEL_111;
    while ( _dst.p[v23] == v74.p[v23] )
    {
      if ( ++v23 >= v74.size )
        goto LABEL_111;
    }
  }
  else if ( (_dst.size != v74.size) != 1 )
  {
    goto LABEL_111;
  }
  v24 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  LODWORD(UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext[3].mNext) = 0;
  v25 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
  v26 = (UFG::Event *)v25;
  v81 = v25;
  if ( v25 )
  {
    v27 = v25 + 1;
    v27->mNext = v27;
    v27[1].mNext = v27;
    v26->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
    v26->m_EventUID = 609910773;
    v26->m_NamePTR = 0i64;
  }
  else
  {
    v26 = 0i64;
  }
  v26->mUserData0 = (unsigned __int64)v24;
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v26);
  v28 = 0;
  if ( v74.size )
  {
    while ( 1 )
    {
      v29 = 0;
      if ( !(_DWORD)v71 )
        goto LABEL_98;
      while ( 1 )
      {
        v30 = (char *)ptr + 88 * v29;
        LODWORD(v31) = *((_DWORD *)v30 + 8);
        v32 = 0;
        v33 = *((_DWORD *)v30 + 10);
        if ( v33 )
        {
          do
          {
            v34 = *((_QWORD *)v30 + 6);
            v35 = 65
                * (21
                 * (((((unsigned int)v31 | ((unsigned __int64)*(unsigned int *)(v34 + 4i64 * v32) << 32)) << 18)
                   + ~((unsigned int)v31 | ((unsigned __int64)*(unsigned int *)(v34 + 4i64 * v32) << 32))) ^ (((((unsigned int)v31 | ((unsigned __int64)*(unsigned int *)(v34 + 4i64 * v32) << 32)) << 18) + ~((unsigned int)v31 | ((unsigned __int64)*(unsigned int *)(v34 + 4i64 * v32) << 32))) >> 31)) ^ (21 * (((((unsigned int)v31 | ((unsigned __int64)*(unsigned int *)(v34 + 4i64 * v32) << 32)) << 18) + ~((unsigned int)v31 | ((unsigned __int64)*(unsigned int *)(v34 + 4i64 * v32) << 32))) ^ (((((unsigned int)v31 | ((unsigned __int64)*(unsigned int *)(v34 + 4i64 * v32) << 32)) << 18) + ~((unsigned int)v31 | ((unsigned __int64)*(unsigned int *)(v34 + 4i64 * v32) << 32))) >> 31)) >> 11));
            v31 = v35 ^ (v35 >> 22);
            ++v32;
          }
          while ( v32 < v33 );
        }
        if ( (UFG::RoadNetworkNode *)(unsigned int)v31 == v74.p[v28] )
          break;
        if ( ++v29 >= (unsigned int)v71 )
          goto LABEL_98;
      }
      if ( (signed int)UFG::qArray<UFG::Editor::DAGPath,0>::Find(
                         (UFG::qArray<UFG::Editor::DAGPath,0> *)&v24[3].mNext,
                         (UFG::Editor::DAGPath *)ptr + v29) <= -1 )
      {
        v36 = LODWORD(v24[3].mNext);
        v37 = v36 + 1;
        v38 = HIDWORD(v24[3].mNext);
        if ( (signed int)v36 + 1 > v38 )
        {
          if ( v38 )
            v39 = 2 * v38;
          else
            v39 = 1;
          for ( ; v39 < v37; v39 *= 2 )
            ;
          if ( v39 - v37 > 0x10000 )
            v39 = v36 + 65537;
          UFG::qArray<UFG::Editor::DAGPath,0>::Reallocate(
            (UFG::qArray<UFG::Editor::DAGPath,0> *)&v24[3].mNext,
            v39,
            "qArray.Add");
        }
        LODWORD(v24[3].mNext) = v37;
        v40 = (signed __int64)v24[4].mPrev + 88 * v36;
        if ( v30 != (char *)v40 )
        {
          UFG::Editor::DAGPath::Clear((UFG::Editor::DAGPath *)v24[4].mPrev + v36);
          if ( !*(_DWORD *)(v40 + 80) )
          {
            v41 = *((_QWORD *)v30 + 2);
            if ( !*(_QWORD *)(v40 + 16) )
            {
              if ( v41 )
              {
                *(_DWORD *)(v40 + 24) = *(_DWORD *)(v41 + 56);
                *(_QWORD *)(v40 + 16) = v41;
                v42 = (signed __int64 *)(v41 + 40);
                v43 = *v42;
                *(_QWORD *)(v43 + 8) = v40;
                *(_QWORD *)v40 = v43;
                *(_QWORD *)(v40 + 8) = v42;
                *v42 = v40;
              }
            }
          }
          *(_DWORD *)(v40 + 32) = *((_DWORD *)v30 + 8);
          UFG::qArray<UFG::qSymbol,0>::Clone(
            (UFG::qArray<UFG::qSymbol,0> *)(v30 + 40),
            (UFG::qArray<UFG::qSymbol,0> *)(v40 + 40));
          *(_DWORD *)(v40 + 56) = *((_DWORD *)v30 + 14);
          UFG::qArray<UFG::qString,0>::Clone(
            (UFG::qArray<UFG::qString,0> *)v30 + 4,
            (UFG::qArray<UFG::qString,0> *)(v40 + 64));
        }
        v44 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
        v45 = (UFG::Event *)v44;
        v81 = v44;
        if ( v44 )
        {
          v46 = v44 + 1;
          v46->mNext = v46;
          v46[1].mNext = v46;
          v45->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
          v45->m_EventUID = 609910773;
          v45->m_NamePTR = 0i64;
        }
        else
        {
          v45 = 0i64;
        }
        v45->mUserData0 = (unsigned __int64)v24;
        UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v45);
      }
      v47 = *((_DWORD *)v30 + 14);
      if ( *((_DWORD *)v30 + 20) == 1 )
        goto LABEL_98;
      if ( !*((_QWORD *)v30 + 2) )
      {
        v48 = *((_DWORD *)v30 + 8);
        if ( v48 )
        {
          v49 = UFG::qBaseTreeRB::Get(&gDAGTypeLookup.mTree, v48);
          if ( v49 )
          {
            if ( v49 != (UFG::qBaseTreeRB *)8 )
            {
              v50 = UFG::Editor::DAGType::AquireFnObject(
                      (UFG::Editor::DAGType *)&v49[-1].mCount,
                      (UFG::Editor::DAGPath *)v30);
              if ( !*((_QWORD *)v30 + 2) )
              {
                if ( v50 )
                {
                  *((_DWORD *)v30 + 6) = v50->mTypeId;
                  *((_QWORD *)v30 + 2) = v50;
                  v51 = &v50->mSmartHandleList;
                  v52 = v50->mSmartHandleList.mNode.mPrev;
                  v52->mNext = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v30;
                  *(_QWORD *)v30 = v52;
                  *((_QWORD *)v30 + 1) = v51;
                  v51->mNode.mPrev = (UFG::qNode<UFG::Editor::SmartHandle,UFG::Editor::SmartHandleList> *)v30;
                }
              }
            }
          }
        }
      }
      v53 = *((_QWORD *)v30 + 2);
      if ( !v53 )
        goto LABEL_98;
      v54 = 0;
      v55 = *(_DWORD *)(v53 + 64);
      if ( *((_DWORD *)v30 + 14) == -1 )
      {
        if ( v55 )
        {
          v56 = *(_QWORD *)(v53 + 72);
          while ( 1 )
          {
            v57 = *(_QWORD *)(v56 + 8i64 * v54);
            if ( *(_DWORD *)(v57 + 8) == 884077544 )
              break;
            if ( ++v54 >= v55 )
              goto LABEL_79;
          }
        }
        else
        {
LABEL_79:
          v57 = 0i64;
        }
LABEL_93:
        if ( v57 )
        {
          v60 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                  *(UFG::qPropertySet **)(*(_QWORD *)(v57 + 16) + 168i64),
                  (UFG::qSymbol *)&component_Prefab::sPropertyName.mUID,
                  DEPTH_RECURSE);
          if ( v60 )
            v61 = UFG::qPropertySet::GetMemImagePtr(v60);
          else
            v61 = 0i64;
          v62 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)v61);
          UFG::Editor::Core::OpenForEdit(v62);
        }
        goto LABEL_98;
      }
      if ( v47 == -1 )
      {
        if ( v55 )
        {
          v58 = *(_QWORD *)(v53 + 72);
          while ( 1 )
          {
            v57 = *(_QWORD *)(v58 + 8i64 * v54);
            if ( *(_DWORD *)(v57 + 8) == 1864359155 )
              break;
            if ( ++v54 >= v55 )
              goto LABEL_85;
          }
        }
        else
        {
LABEL_85:
          v57 = 0i64;
        }
      }
      else
      {
        if ( !v55 )
          goto LABEL_98;
        v59 = *(_QWORD *)(v53 + 72);
        while ( 1 )
        {
          v57 = *(_QWORD *)(v59 + 8i64 * v54);
          if ( *(_DWORD *)(v57 + 12) == v47 )
            break;
          if ( ++v54 >= v55 )
            goto LABEL_98;
        }
      }
      if ( v57 && *(_DWORD *)(v57 + 8) == 884077544 )
        goto LABEL_93;
LABEL_98:
      if ( ++v28 >= v74.size )
      {
        v22 = _dst.p;
        break;
      }
    }
  }
  v63 = (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  v64 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  if ( (UFG::qList<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet,1,0> *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext == &UFG::Editor::SelectionManager::mSelectionSets )
  {
LABEL_103:
    v65 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
    v64 = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)v65;
    v81 = v65;
    if ( v65 )
    {
      v65->mNext = v65;
      v65[1].mNext = v65;
      UFG::qString::qString((UFG::qString *)&v65[2], "LastSelection");
      v64[4].mPrev = 0i64;
      v64[3].mNext = 0i64;
    }
    else
    {
      v64 = 0i64;
    }
    v66 = UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev;
    UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev->mNext = v64;
    v64->mPrev = v66;
    v64->mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets;
    UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev = v64;
  }
  else
  {
    while ( (unsigned int)UFG::qStringCompare("LastSelection", (const char *)v64[2].mNext, -1) )
    {
      v64 = v64->mNext;
      if ( v64 == (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets )
        goto LABEL_103;
    }
  }
  LODWORD(v64[3].mNext) = 0;
  v67 = UFG::qMalloc(0x38ui64, UFG::gGlobalNewName, 0i64);
  v68 = (UFG::Event *)v67;
  v81 = v67;
  if ( v67 )
  {
    v69 = v67 + 1;
    v69->mNext = v69;
    v69[1].mNext = v69;
    v68->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
    v68->m_EventUID = 609910773;
    v68->m_NamePTR = 0i64;
  }
  else
  {
    v68 = 0i64;
  }
  v68->mUserData0 = (unsigned __int64)v64;
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v68);
  UFG::Editor::SelectionSet::Add((UFG::Editor::SelectionSet *)v64, v63);
LABEL_111:
  if ( ptr )
  {
    v70 = (char *)ptr - 8;
    `eh vector destructor iterator'(
      ptr,
      0x58ui64,
      *((_DWORD *)ptr - 2),
      (void (__fastcall *)(void *))UFG::Editor::DAGPath::~DAGPath);
    operator delete[](v70);
  }
  ptr = 0i64;
  v71 = 0i64;
  if ( v22 )
    operator delete[](v22);
  _dst.p = 0i64;
  *(_QWORD *)&_dst.size = 0i64;
  if ( v74.p )
    operator delete[](v74.p);
}

// File Line: 1805
// RVA: 0x21D020
void __fastcall UFG::Editor::SceneLayerPropertiesWindow::UpdateUI(UFG::Editor::SceneLayerPropertiesWindow *this, UFG::DUIContext *dui)
{
  UFG::DUIContext *v2; // rbx
  UFG::Editor::SceneLayerPropertiesWindow *v3; // rsi
  const char *v4; // rcx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v5; // rax
  UFG::qBaseTreeRB *v6; // rdi
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v7; // rbp
  char *v8; // rax
  UFG::qString *v9; // rax
  UFG::DUIRect result; // [rsp+28h] [rbp-50h]
  UFG::qString v11; // [rsp+38h] [rbp-40h]
  bool current_value; // [rsp+80h] [rbp+8h]
  UFG::qSymbol v13; // [rsp+90h] [rbp+18h]

  v2 = dui;
  v3 = this;
  UFG::DUIContext::BeginGridLayout(dui, 1, 3, 3);
  current_value = v3->mLockSelection;
  UFG::DUIContext::Checkbox(v2, "Lock Layer", &current_value);
  if ( current_value != v3->mLockSelection )
    UFG::Editor::SceneLayerPropertiesWindow::SetLockSelection(v3, current_value);
  UFG::DUIContext::Separator(v2);
  UFG::DUIContext::GetLayoutRect(v2, &result, 0, 0);
  UFG::DUIContext::SetLayoutRect(v2, &result);
  if ( UFG::DUIContext::IsMouseOver(v2, &result) && v2->mInputState.mMouseRBWentUp )
  {
    UFG::Editor::ShowContextMenu(v2);
    UFG::DUIInputState::ConsumeMouseButtonEvents(&v2->mInputState);
  }
  if ( v3->mLockSelection )
    v4 = v3->mLockedSelection.mData;
  else
    v4 = "Layers";
  v5 = UFG::Editor::SelectionManager::GetSelectionSet(v4);
  v6 = 0i64;
  if ( LODWORD(v5[3].mNext) )
  {
    v7 = v5[4].mPrev;
    if ( LODWORD(v7[2].mNext) == 1
      && UFG::Editor::DAGPath::GetSystemName((UFG::Editor::DAGPath *)v5[4].mPrev, &v13)->mUID == UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID )
    {
      v6 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, (UFG::qSymbol *)v7[3].mPrev);
    }
    if ( v6 )
    {
      v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v6->mRoot.mUID);
      v9 = UFG::qString::FormatEx(&v11, "%s - Hierarchy", v8);
      UFG::qString::Set(&v3->mTitle, v9->mData);
      UFG::qString::~qString(&v11);
    }
  }
  UFG::DUIContext::BeginScrollView(v2, &v3->mSceneObject_ScrollPos);
  UFG::Editor::SceneLayerPropertiesWindow::UpdateSceneObjectTree(v3, v2, (UFG::SceneLayer *)v6);
  UFG::DUIContext::EndScrollView(v2);
  UFG::DUIContext::EndLayoutHorizontal(v2);
}

