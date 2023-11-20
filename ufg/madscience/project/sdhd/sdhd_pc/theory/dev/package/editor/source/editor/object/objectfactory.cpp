// File Line: 37
// RVA: 0x146DA00
__int64 UFG::Editor::ObjectFactory::_dynamic_initializer_for__gLastCreationParams__()
{
  Assembly::GetRCX(&stru_1420408AC);
  return atexit(UFG::Editor::ObjectFactory::_dynamic_atexit_destructor_for__gLastCreationParams__);
}

// File Line: 38
// RVA: 0x146DAD0
__int64 UFG::Editor::ObjectFactory::_dynamic_initializer_for__gSceneObjectFactories__()
{
  return atexit(UFG::Editor::ObjectFactory::_dynamic_atexit_destructor_for__gSceneObjectFactories__);
}

// File Line: 42
// RVA: 0x207B50
UFG::qPropertySet *__fastcall UFG::Editor::ObjectFactory::DefaultSceneObjectCreator(UFG::Editor::ObjectFactory::CreationParams *params)
{
  UFG::Editor::ObjectFactory::CreationParams *v1; // rdi
  UFG::qPropertySet *v2; // rax
  UFG::qPropertySet *v3; // rbx

  v1 = params;
  v2 = UFG::qPropertySet::CreateContainedSet(&params->ObjectName, "CreateObject");
  v2->mFlags &= 0xFFFFFFFu;
  v2->mFlags |= 0x20000000u;
  v3 = v2;
  UFG::qPropertySet::AddParent(v2, &v1->Archetype);
  UFG::qPropertySet::Set<UFG::qMatrix44>(v3, (UFG::qSymbol *)&UFG::Editor::gsymXformLocal.mUID, &v1->Transform);
  return v3;
}

// File Line: 89
// RVA: 0x206650
UFG::qPropertySet *__fastcall UFG::Editor::ObjectFactory::CreateObjectFromArcy(const char *assetFullName, UFG::qMatrix44 *transform, const char *spawnNamePrefix)
{
  const char *v3; // rbp
  UFG::qMatrix44 *v4; // r14
  const char *v5; // rsi
  UFG::qSymbol *v6; // rax
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *v8; // rdi
  char *v9; // rax
  const char *v10; // rbx
  char *v11; // r8
  __int64 v12; // rbx
  UFG::qString *v13; // rax
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  UFG::qVector4 v16; // xmm0
  UFG::qPropertySet *(__fastcall *v17)(UFG::Editor::ObjectFactory::CreationParams *); // rax
  UFG::qPropertySet *v18; // rbx
  UFG::qSymbol v19; // [rsp+30h] [rbp-D8h]
  UFG::qString v20; // [rsp+38h] [rbp-D0h]
  UFG::Editor::ObjectFactory::CreationParams params; // [rsp+60h] [rbp-A8h]
  __int64 v22; // [rsp+C0h] [rbp-48h]
  UFG::qString result; // [rsp+C8h] [rbp-40h]
  __int64 v24; // [rsp+128h] [rbp+20h]

  v22 = -2i64;
  v3 = spawnNamePrefix;
  v4 = transform;
  v5 = assetFullName;
  v6 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v24, assetFullName);
  v7 = UFG::PropertySetManager::GetPropertySet(v6);
  v8 = v7;
  if ( v7 )
  {
    v9 = UFG::qStringFindLast(v5, "-");
    if ( v9 )
      v10 = v9 + 1;
    else
      v10 = v5;
    UFG::qString::qString(&v20, v3);
    UFG::qString::operator+=(&v20, v10);
    v11 = v20.mData;
    v12 = 0i64;
    if ( v20.mData[v20.mLength - 1] > 57 || v20.mData[v20.mLength - 1] < 48 )
    {
      v13 = UFG::qString::FormatEx(&result, "%s00001");
      UFG::qString::Set(&v20, v13->mData, v13->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      v11 = v20.mData;
    }
    *(_QWORD *)&params.Archetype.mUID = -1i64;
    params.ParentObjectName.mUID = -1;
    params.Archetype.mUID = v8->mName.mUID;
    params.ObjectCreator = UFG::Editor::ObjectFactory::DefaultSceneObjectCreator;
    params.ObjectName = (UFG::qSymbol)UFG::qSymbol::create_from_string(&v19, v11)->mUID;
    v14 = v4->v1;
    v15 = v4->v2;
    v16 = v4->v3;
    params.Transform.v0 = v4->v0;
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
    v7 = v18;
  }
  return v7;
}

// File Line: 128
// RVA: 0x2064A0
UFG::qPropertySet *__fastcall UFG::Editor::ObjectFactory::CreateObject(UFG::Editor::ObjectFactory::CreationParams *params)
{
  UFG::Editor::ObjectFactory::CreationParams *v1; // rdi
  UFG::qBaseTreeRB *v2; // rax
  UFG::SceneLayer *v3; // rbp
  UFG::qPropertySet *v4; // rsi
  UFG::qPropertySet *v5; // rax
  UFG::qPropertySet *v6; // rbx
  UFG::SceneLayer *v7; // rax
  UFG::SceneLayer *v8; // rax
  UFG::SceneLayerResource *v9; // rax
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  hkSeekableStreamReader v12; // xmm0
  UFG::qSymbol result; // [rsp+58h] [rbp+10h]
  UFG::qPropertySet *parentSceneObject; // [rsp+60h] [rbp+18h]
  UFG::qPropertySet *sceneObject; // [rsp+68h] [rbp+20h]

  v1 = params;
  if ( stru_142040928.size == 1
    && UFG::Editor::DAGPath::GetSystemName(&gWorkingLayerPath, &result)->mUID == UFG::Editor::DAGTypeSceneLayer::TYPE_SYMBOL.mUID )
  {
    v2 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, stru_142040928.p);
    v3 = (UFG::SceneLayer *)v2;
    if ( v2 )
    {
      v4 = 0i64;
      parentSceneObject = 0i64;
      if ( v1->ParentObjectName.mUID != UFG::gNullQSymbol.mUID )
      {
        v4 = UFG::SceneLayer::FindObjectPropertySet((UFG::SceneLayer *)v2, &v1->ParentObjectName);
        parentSceneObject = v4;
      }
      v5 = v1->ObjectCreator(v1);
      v6 = v5;
      sceneObject = v5;
      if ( v4 )
      {
        UFG::Editor::SceneManager::AddChildSceneObject(&parentSceneObject, &sceneObject);
        v6 = sceneObject;
LABEL_15:
        gLastCreationParams.Archetype.mUID = v1->Archetype.mUID;
        unk_1420408A4 = v1->ObjectName.mUID;
        unk_1420408A8 = v1->ParentObjectName.mUID;
        v10 = v1->Transform.v2;
        v11 = v1->Transform.v3;
        v12 = (hkSeekableStreamReader)v1->Transform.v0;
        unk_1420408BC = v1->Transform.v1;
        unk_1420408CC = v10;
        stru_1420408AC = v12;
        unk_1420408DC = v11;
        unk_1420408F0 = v1->HiveAsset;
        unk_1420408F8 = v1->ObjectCreator;
        return v6;
      }
      if ( !v5 || (v5->mFlags & 0xF0000000) != 0x20000000 )
        goto LABEL_15;
      v7 = UFG::Scene::FindLayerContainingObject(&UFG::Scene::msDefault, &v5->mName, 0i64);
      if ( v7 )
      {
        if ( v3 == v7 )
          goto LABEL_15;
        v6 = UFG::Editor::SceneManager::CloneAndDeleteSceneObject(v6);
      }
      UFG::Editor::SceneManager::SetUniqueName(v6, v3, 0i64, &UFG::gNullQSymbol);
      UFG::qPropertySet::RemovePropertyByName(v6, (UFG::qSymbol *)&UFG::Editor::gsymXformParent.mUID);
      v8 = UFG::Editor::Core::OpenForEdit(v3);
      v9 = UFG::SceneLayer::GetSingleEditorSceneLayerResource(v8);
      if ( v9 )
        UFG::SceneLayerResource::AddPropertySet(v9, v6);
      goto LABEL_15;
    }
  }
  return 0i64;
}

