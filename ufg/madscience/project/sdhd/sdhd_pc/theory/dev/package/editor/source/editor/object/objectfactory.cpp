// File Line: 37
// RVA: 0x146DA00
__int64 UFG::Editor::ObjectFactory::_dynamic_initializer_for__gLastCreationParams__()
{
  Assembly::GetRCX(&stru_1420408AC);
  return atexit((int (__fastcall *)())UFG::Editor::ObjectFactory::_dynamic_atexit_destructor_for__gLastCreationParams__);
}

// File Line: 38
// RVA: 0x146DAD0
__int64 UFG::Editor::ObjectFactory::_dynamic_initializer_for__gSceneObjectFactories__()
{
  return atexit((int (__fastcall *)())UFG::Editor::ObjectFactory::_dynamic_atexit_destructor_for__gSceneObjectFactories__);
}

// File Line: 42
// RVA: 0x207B50
UFG::qPropertySet *__fastcall UFG::Editor::ObjectFactory::DefaultSceneObjectCreator(
        UFG::qArray<unsigned long,0> *params)
{
  UFG::qPropertySet *ContainedSet; // rax
  UFG::qPropertySet *v3; // rbx

  ContainedSet = UFG::qPropertySet::CreateContainedSet((UFG::qSymbol *)&params->capacity, "CreateObject");
  ContainedSet->mFlags &= 0xFFFFFFFu;
  ContainedSet->mFlags |= 0x20000000u;
  v3 = ContainedSet;
  UFG::qPropertySet::AddParent(ContainedSet, params);
  UFG::qPropertySet::Set<UFG::qMatrix44>(
    v3,
    (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymXformLocal,
    (UFG::qMatrix44 *)((char *)&params->p + 4));
  return v3;
}

// File Line: 89
// RVA: 0x206650
UFG::qPropertySet *__fastcall UFG::Editor::ObjectFactory::CreateObjectFromArcy(
        const char *assetFullName,
        UFG::qMatrix44 *transform,
        const char *spawnNamePrefix)
{
  UFG::qSymbol *v6; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v8; // rdi
  char *Last; // rax
  const char *v10; // rbx
  char *mData; // r8
  __int64 v12; // rbx
  UFG::qString *v13; // rax
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  UFG::qVector4 v16; // xmm0
  UFG::qPropertySet *(__fastcall *v17)(UFG::Editor::ObjectFactory::CreationParams *); // rax
  UFG::qPropertySet *v18; // rbx
  UFG::qSymbol v19; // [rsp+30h] [rbp-D8h] BYREF
  UFG::qString v20; // [rsp+38h] [rbp-D0h] BYREF
  UFG::Editor::ObjectFactory::CreationParams params; // [rsp+60h] [rbp-A8h] BYREF
  __int64 v22; // [rsp+C0h] [rbp-48h]
  UFG::qString result; // [rsp+C8h] [rbp-40h] BYREF
  UFG::qSymbol v24; // [rsp+128h] [rbp+20h] BYREF

  v22 = -2i64;
  v6 = UFG::qSymbol::create_from_string(&v24, assetFullName);
  PropertySet = UFG::PropertySetManager::GetPropertySet(v6);
  v8 = PropertySet;
  if ( PropertySet )
  {
    Last = UFG::qStringFindLast(assetFullName, "-");
    if ( Last )
      v10 = Last + 1;
    else
      v10 = assetFullName;
    UFG::qString::qString(&v20, spawnNamePrefix);
    UFG::qString::operator+=(&v20, v10);
    mData = v20.mData;
    v12 = 0i64;
    if ( v20.mData[v20.mLength - 1] > 57 || v20.mData[v20.mLength - 1] < 48 )
    {
      v13 = UFG::qString::FormatEx(&result, "%s00001", v20.mData);
      UFG::qString::Set(&v20, v13->mData, v13->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      mData = v20.mData;
    }
    *(_QWORD *)&params.Archetype.mUID = -1i64;
    params.ParentObjectName.mUID = -1;
    params.Archetype.mUID = v8->mName.mUID;
    params.ObjectCreator = UFG::Editor::ObjectFactory::DefaultSceneObjectCreator;
    params.ObjectName = (UFG::qSymbol)UFG::qSymbol::create_from_string(&v19, mData)->mUID;
    v14 = transform->v1;
    v15 = transform->v2;
    v16 = transform->v3;
    params.Transform.v0 = transform->v0;
    params.Transform.v1 = v14;
    params.Transform.v2 = v15;
    params.Transform.v3 = v16;
    if ( gSceneObjectFactories.size )
    {
      while ( 1 )
      {
        v17 = gSceneObjectFactories.p[v12](v8);
        if ( v17 )
          break;
        v12 = (unsigned int)(v12 + 1);
        if ( (unsigned int)v12 >= gSceneObjectFactories.size )
          goto LABEL_12;
      }
      params.ObjectCreator = v17;
    }
LABEL_12:
    v18 = UFG::Editor::ObjectFactory::CreateObject(&params);
    UFG::qString::~qString(&v20);
    return v18;
  }
  return PropertySet;
}

// File Line: 128
// RVA: 0x2064A0
UFG::qPropertySet *__fastcall UFG::Editor::ObjectFactory::CreateObject(
        UFG::Editor::ObjectFactory::CreationParams *params)
{
  UFG::qBaseTreeRB *Layer; // rax
  UFG::SceneLayer *v3; // rbp
  UFG::qPropertySet *ObjectPropertySet; // rsi
  UFG::qPropertySet *v5; // rax
  UFG::qPropertySet *v6; // rbx
  UFG::SceneLayer *LayerContainingObject; // rax
  UFG::SceneLayer *v8; // rax
  UFG::SceneLayerResource *SingleEditorSceneLayerResource; // rax
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  UFG::qVector4 v12; // xmm0
  UFG::qSymbol result; // [rsp+58h] [rbp+10h] BYREF
  UFG::qPropertySet *parentSceneObject; // [rsp+60h] [rbp+18h] BYREF
  UFG::qPropertySet *sceneObject; // [rsp+68h] [rbp+20h] BYREF

  if ( stru_142040928.size == 1
    && UFG::Editor::DAGPath::GetSystemName(&gWorkingLayerPath, &result)->mUID == UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID )
  {
    Layer = UFG::Scene::FindLayer(&UFG::Scene::msDefault, stru_142040928.p);
    v3 = (UFG::SceneLayer *)Layer;
    if ( Layer )
    {
      ObjectPropertySet = 0i64;
      parentSceneObject = 0i64;
      if ( params->ParentObjectName.mUID != UFG::gNullQSymbol.mUID )
      {
        ObjectPropertySet = UFG::SceneLayer::FindObjectPropertySet((UFG::SceneLayer *)Layer, &params->ParentObjectName);
        parentSceneObject = ObjectPropertySet;
      }
      v5 = params->ObjectCreator(params);
      v6 = v5;
      sceneObject = v5;
      if ( ObjectPropertySet )
      {
        UFG::Editor::SceneManager::AddChildSceneObject(&parentSceneObject, &sceneObject);
        v6 = sceneObject;
LABEL_15:
        gLastCreationParams.Archetype.mUID = params->Archetype.mUID;
        unk_1420408A4 = params->ObjectName.mUID;
        unk_1420408A8 = params->ParentObjectName.mUID;
        v10 = params->Transform.v2;
        v11 = params->Transform.v3;
        v12 = params->Transform.v0;
        unk_1420408BC = params->Transform.v1;
        unk_1420408CC = v10;
        stru_1420408AC = (hkSeekableStreamReader)v12;
        unk_1420408DC = v11;
        unk_1420408F0 = params->HiveAsset;
        unk_1420408F8 = params->ObjectCreator;
        return v6;
      }
      if ( !v5 || (v5->mFlags & 0xF0000000) != 0x20000000 )
        goto LABEL_15;
      LayerContainingObject = UFG::Scene::FindLayerContainingObject(&UFG::Scene::msDefault, &v5->mName, 0i64);
      if ( LayerContainingObject )
      {
        if ( v3 == LayerContainingObject )
          goto LABEL_15;
        v6 = UFG::Editor::SceneManager::CloneAndDeleteSceneObject(v6);
      }
      UFG::Editor::SceneManager::SetUniqueName(v6, v3, 0i64, &UFG::gNullQSymbol);
      UFG::qPropertySet::RemovePropertyByName(v6, (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymXformParent);
      v8 = UFG::Editor::Core::OpenForEdit(v3);
      SingleEditorSceneLayerResource = UFG::SceneLayer::GetSingleEditorSceneLayerResource(v8);
      if ( SingleEditorSceneLayerResource )
        UFG::SceneLayerResource::AddPropertySet(SingleEditorSceneLayerResource, v6);
      goto LABEL_15;
    }
  }
  return 0i64;
}

