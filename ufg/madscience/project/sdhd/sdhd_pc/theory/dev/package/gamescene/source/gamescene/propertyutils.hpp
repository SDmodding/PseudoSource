// File Line: 34
// RVA: 0x447C30
UFG::qSymbolUC *__fastcall PropertyUtils::GetWithDefault<UFG::qSymbolUC>(
        UFG::qSymbolUC *result,
        UFG::SceneObjectProperties *set,
        UFG::qArray<unsigned long,0> *propertyName,
        unsigned int *defaultValue,
        UFG::qPropertyDepth depth)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qSymbolUC *v8; // rax

  mpWritableProperties = set->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = set->mpConstProperties;
  v8 = PropertyUtils::Get<UFG::qSymbolUC>(mpWritableProperties, propertyName, depth);
  if ( v8 )
    result->mUID = v8->mUID;
  else
    result->mUID = *defaultValue;
  return result;
}

// File Line: 61
// RVA: 0x57BF70
UFG::qSymbolUC *__fastcall PropertyUtils::GetWithDefault<UFG::qSymbolUC>(
        UFG::qSymbolUC *result,
        UFG::qPropertySet *propertySet,
        UFG::qArray<unsigned long,0> *propertyName,
        unsigned int *defaultValue,
        UFG::qPropertyDepth depth)
{
  UFG::qSymbolUC *v7; // rax

  v7 = UFG::qPropertySet::Get<UFG::qSymbolUC>(propertySet, propertyName, depth);
  if ( v7 )
    result->mUID = v7->mUID;
  else
    result->mUID = *defaultValue;
  return result;
}

