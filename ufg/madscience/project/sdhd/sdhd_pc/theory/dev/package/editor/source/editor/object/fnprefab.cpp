// File Line: 46
// RVA: 0x146C010
__int64 dynamic_initializer_for__UFG::Editor::FnPrefab::NAME_SYMBOL__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("prefab", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::FnPrefab::NAME_SYMBOL, v0);
  return atexit(dynamic_atexit_destructor_for__UFG::Editor::FnPrefab::NAME_SYMBOL__);
}

// File Line: 70
// RVA: 0x20C3D0
UFG::qPropertySet *__fastcall UFG::Editor::FnPrefab::GetPrefabData(UFG::Editor::FnPrefab *this)
{
  UFG::qPropertySet *v1; // rax
  char *v2; // rbx
  char *v3; // rax
  UFG::qPropertySet *result; // rax
  UFG::qPropertySet *v5; // rax

  v1 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         (UFG::qPropertySet *)this->mFnObject[1].vfptr,
         (UFG::qSymbol *)&component_Prefab::sPropertyName.mUID,
         DEPTH_RECURSE);
  v2 = 0i64;
  if ( v1 )
    v3 = UFG::qPropertySet::GetMemImagePtr(v1);
  else
    v3 = 0i64;
  result = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)v3);
  if ( result )
  {
    v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           result,
           (UFG::qSymbol *)&component_PrefabData::sPropertyName.mUID,
           DEPTH_RECURSE);
    if ( v5 )
      v2 = UFG::qPropertySet::GetMemImagePtr(v5);
    result = (UFG::qPropertySet *)v2;
  }
  return result;
}

