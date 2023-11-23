// File Line: 46
// RVA: 0x146C010
__int64 dynamic_initializer_for__UFG::Editor::FnPrefab::NAME_SYMBOL__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("prefab", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::Editor::FnPrefab::NAME_SYMBOL, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Editor::FnPrefab::NAME_SYMBOL__);
}

// File Line: 70
// RVA: 0x20C3D0
UFG::qPropertySet *__fastcall UFG::Editor::FnPrefab::GetPrefabData(UFG::Editor::FnPrefab *this)
{
  UFG::qPropertySet *v1; // rax
  __int64 v2; // rbx
  char *MemImagePtr; // rax
  UFG::qPropertySet *result; // rax
  UFG::qPropertySet *v5; // rax

  v1 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         (UFG::qPropertySet *)this->mFnObject[1].vfptr,
         (UFG::qArray<unsigned long,0> *)&component_Prefab::sPropertyName,
         DEPTH_RECURSE);
  v2 = 0i64;
  if ( v1 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v1);
  else
    MemImagePtr = 0i64;
  result = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)MemImagePtr);
  if ( result )
  {
    v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           result,
           (UFG::qArray<unsigned long,0> *)&component_PrefabData::sPropertyName,
           DEPTH_RECURSE);
    if ( v5 )
      return (UFG::qPropertySet *)UFG::qPropertySet::GetMemImagePtr(v5);
    return (UFG::qPropertySet *)v2;
  }
  return result;
}

