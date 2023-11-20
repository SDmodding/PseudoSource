// File Line: 34
// RVA: 0x447C30
UFG::qSymbolUC *__fastcall PropertyUtils::GetWithDefault<UFG::qSymbolUC>(UFG::qSymbolUC *result, UFG::SceneObjectProperties *set, UFG::qSymbol *propertyName, __int64 defaultValue, UFG::qPropertyDepth depth)
{
  UFG::qSymbolUC *v5; // rbx
  UFG::qPropertySet *v6; // rcx
  unsigned int *v7; // rdi
  UFG::qSymbolUC *v8; // rax

  v5 = result;
  v6 = set->mpWritableProperties;
  v7 = (unsigned int *)defaultValue;
  if ( !v6 )
    v6 = set->mpConstProperties;
  v8 = PropertyUtils::Get<UFG::qSymbolUC>(v6, propertyName, depth);
  if ( v8 )
    v5->mUID = v8->mUID;
  else
    v5->mUID = *v7;
  return v5;
}

// File Line: 61
// RVA: 0x57BF70
UFG::qSymbolUC *__fastcall PropertyUtils::GetWithDefault<UFG::qSymbolUC>(UFG::qSymbolUC *result, UFG::qPropertySet *propertySet, UFG::qSymbol *propertyName, __int64 defaultValue, UFG::qPropertyDepth depth)
{
  UFG::qSymbolUC *v5; // rbx
  unsigned int *v6; // rdi
  UFG::qSymbolUC *v7; // rax

  v5 = result;
  v6 = (unsigned int *)defaultValue;
  v7 = UFG::qPropertySet::Get<UFG::qSymbolUC>(propertySet, propertyName, depth);
  if ( v7 )
    v5->mUID = v7->mUID;
  else
    v5->mUID = *v6;
  return v5;
}

