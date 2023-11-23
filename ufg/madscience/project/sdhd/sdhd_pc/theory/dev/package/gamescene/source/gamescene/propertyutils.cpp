// File Line: 32
// RVA: 0x236A50
// attributes: thunk
char *__fastcall PropertyUtils::Get<char const *>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<char const *>(set, propName, depth);
}

// File Line: 33
// RVA: 0x236F10
// attributes: thunk
bool *__fastcall PropertyUtils::Get<bool>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<bool>(set, propName, depth);
}

// File Line: 34
// RVA: 0x2368F0
// attributes: thunk
unsigned int *__fastcall PropertyUtils::Get<unsigned long>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<unsigned long>(set, propName, depth);
}

// File Line: 35
// RVA: 0x236840
// attributes: thunk
int *__fastcall PropertyUtils::Get<long>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<long>(set, propName, depth);
}

// File Line: 36
// RVA: 0x2369A0
// attributes: thunk
float *__fastcall PropertyUtils::Get<float>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<float>(set, propName, depth);
}

// File Line: 41
// RVA: 0x236B00
// attributes: thunk
UFG::qMatrix44 *__fastcall PropertyUtils::Get<UFG::qMatrix44>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<UFG::qMatrix44>(set, propName, depth);
}

// File Line: 42
// RVA: 0x236D10
// attributes: thunk
UFG::qSymbol *__fastcall PropertyUtils::Get<UFG::qSymbol>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<UFG::qSymbol>(set, propName, depth);
}

// File Line: 43
// RVA: 0x236D20
// attributes: thunk
UFG::qSymbolUC *__fastcall PropertyUtils::Get<UFG::qSymbolUC>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<UFG::qSymbolUC>(set, propName, depth);
}

// File Line: 44
// RVA: 0x236BC0
// attributes: thunk
UFG::qPropertySet *__fastcall PropertyUtils::Get<UFG::qPropertySet>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<UFG::qPropertySet>(set, propName, depth);
}

// File Line: 45
// RVA: 0x236BB0
// attributes: thunk
UFG::qPropertyList *__fastcall PropertyUtils::Get<UFG::qPropertyList>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<UFG::qPropertyList>(set, propName, depth);
}

// File Line: 54
// RVA: 0x236FC0
// attributes: thunk
void __fastcall PropertyUtils::Set<char const *>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        char *v)
{
  UFG::qPropertySet::Set<char const *>(set, propName, v);
}

// File Line: 55
// RVA: 0x237090
// attributes: thunk
void __fastcall PropertyUtils::Set<bool>(UFG::qPropertySet *set, UFG::qArray<unsigned long,0> *propName, bool v)
{
  UFG::qPropertySet::Set<bool>(set, propName, v);
}

// File Line: 57
// RVA: 0x236FA0
// attributes: thunk
void __fastcall PropertyUtils::Set<long>(UFG::qPropertySet *set, UFG::qArray<unsigned long,0> *propName, int v)
{
  UFG::qPropertySet::Set<long>(set, propName, v);
}

// File Line: 58
// RVA: 0x236FB0
// attributes: thunk
void __fastcall PropertyUtils::Set<float>(UFG::qPropertySet *set, UFG::qArray<unsigned long,0> *propName, float v)
{
  UFG::qPropertySet::Set<float>(set, propName, v);
}

// File Line: 60
// RVA: 0x237070
// attributes: thunk
void __fastcall PropertyUtils::Set<UFG::qSymbol>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qSymbol *v)
{
  UFG::qPropertySet::Set<UFG::qSymbol>(set, propName, v);
}

// File Line: 64
// RVA: 0x237080
// attributes: thunk
void __fastcall PropertyUtils::Set<UFG::qVector3>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qVector3 *v)
{
  UFG::qPropertySet::Set<UFG::qVector3>(set, propName, v);
}

// File Line: 66
// RVA: 0x236FD0
// attributes: thunk
void __fastcall PropertyUtils::Set<UFG::qPropertySet>(
        UFG::qPropertySet *set,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertySet *v)
{
  UFG::qPropertySet::Set<UFG::qPropertySet>(set, propName, v);
}

// File Line: 93
// RVA: 0x2369B0
UFG::qPropertySet *__fastcall PropertyUtils::Get<char const *>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *result; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(
               mpConstProperties,
               (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
               DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<char const *>(result, propName, DEPTH_RECURSE);
  }
  result = sop->mpWritableProperties;
  if ( !result )
  {
    result = sop->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<char const *>(result, propName, DEPTH_RECURSE);
}

// File Line: 94
// RVA: 0x236E70
bool *__fastcall PropertyUtils::Get<bool>(UFG::SceneObjectProperties *sop, UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  bool *result; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    result = (bool *)UFG::qPropertySet::Get<UFG::qPropertySet>(
                       mpConstProperties,
                       (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
                       DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return UFG::qPropertySet::Get<bool>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
  }
  result = (bool *)sop->mpWritableProperties;
  if ( !result )
  {
    result = (bool *)sop->mpConstProperties;
    goto LABEL_9;
  }
  return UFG::qPropertySet::Get<bool>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
}

// File Line: 95
// RVA: 0x236850
UFG::qPropertySet *__fastcall PropertyUtils::Get<unsigned long>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *result; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(
               mpConstProperties,
               (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
               DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<unsigned long>(result, propName, DEPTH_RECURSE);
  }
  result = sop->mpWritableProperties;
  if ( !result )
  {
    result = sop->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<unsigned long>(result, propName, DEPTH_RECURSE);
}

// File Line: 96
// RVA: 0x2367A0
UFG::qPropertySet *__fastcall PropertyUtils::Get<long>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *result; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(
               mpConstProperties,
               (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
               DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<long>(result, propName, DEPTH_RECURSE);
  }
  result = sop->mpWritableProperties;
  if ( !result )
  {
    result = sop->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<long>(result, propName, DEPTH_RECURSE);
}

// File Line: 97
// RVA: 0x236900
float *__fastcall PropertyUtils::Get<float>(UFG::SceneObjectProperties *sop, UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  float *result; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    result = (float *)UFG::qPropertySet::Get<UFG::qPropertySet>(
                        mpConstProperties,
                        (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
                        DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return UFG::qPropertySet::Get<float>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
  }
  result = (float *)&sop->mpWritableProperties->mFlags;
  if ( !result )
  {
    result = (float *)&sop->mpConstProperties->mFlags;
    goto LABEL_9;
  }
  return UFG::qPropertySet::Get<float>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
}

// File Line: 99
// RVA: 0x236C70
UFG::qPropertySet *__fastcall PropertyUtils::Get<UFG::qSymbol>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *result; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(
               mpConstProperties,
               (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
               DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qSymbol>(result, propName, DEPTH_RECURSE);
  }
  result = sop->mpWritableProperties;
  if ( !result )
  {
    result = sop->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qSymbol>(result, propName, DEPTH_RECURSE);
}

// File Line: 101
// RVA: 0x236DD0
UFG::qWiseSymbol *__fastcall PropertyUtils::Get<UFG::qWiseSymbol>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qWiseSymbol *result; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    result = (UFG::qWiseSymbol *)UFG::qPropertySet::Get<UFG::qPropertySet>(
                                   mpConstProperties,
                                   (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
                                   DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return UFG::qPropertySet::Get<UFG::qWiseSymbol>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
  }
  result = (UFG::qWiseSymbol *)sop->mpWritableProperties;
  if ( !result )
  {
    result = (UFG::qWiseSymbol *)sop->mpConstProperties;
    goto LABEL_9;
  }
  return UFG::qPropertySet::Get<UFG::qWiseSymbol>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
}

// File Line: 103
// RVA: 0x236D30
UFG::qVector3 *__fastcall PropertyUtils::Get<UFG::qVector3>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qVector3 *result; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    result = (UFG::qVector3 *)UFG::qPropertySet::Get<UFG::qPropertySet>(
                                mpConstProperties,
                                (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
                                DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return UFG::qPropertySet::Get<UFG::qVector3>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
  }
  result = (UFG::qVector3 *)sop->mpWritableProperties;
  if ( !result )
  {
    result = (UFG::qVector3 *)sop->mpConstProperties;
    goto LABEL_9;
  }
  return UFG::qPropertySet::Get<UFG::qVector3>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
}

// File Line: 105
// RVA: 0x236A60
UFG::qMatrix44 *__fastcall PropertyUtils::Get<UFG::qMatrix44>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qMatrix44 *result; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    result = (UFG::qMatrix44 *)UFG::qPropertySet::Get<UFG::qPropertySet>(
                                 mpConstProperties,
                                 (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
                                 DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return UFG::qPropertySet::Get<UFG::qMatrix44>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
  }
  result = (UFG::qMatrix44 *)sop->mpWritableProperties;
  if ( !result )
  {
    result = (UFG::qMatrix44 *)sop->mpConstProperties;
    goto LABEL_9;
  }
  return UFG::qPropertySet::Get<UFG::qMatrix44>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
}

// File Line: 106
// RVA: 0x236BD0
UFG::qPropertySet *__fastcall PropertyUtils::Get<UFG::qPropertySet>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *result; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(
               mpConstProperties,
               (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
               DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return UFG::qPropertySet::Get<UFG::qPropertySet>(result, propName, DEPTH_RECURSE);
  }
  result = sop->mpWritableProperties;
  if ( !result )
  {
    result = sop->mpConstProperties;
    goto LABEL_9;
  }
  return UFG::qPropertySet::Get<UFG::qPropertySet>(result, propName, DEPTH_RECURSE);
}

// File Line: 107
// RVA: 0x236B10
UFG::qPropertyList *__fastcall PropertyUtils::Get<UFG::qPropertyList>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertyList *result; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    result = (UFG::qPropertyList *)UFG::qPropertySet::Get<UFG::qPropertySet>(
                                     mpConstProperties,
                                     (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
                                     DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return UFG::qPropertySet::Get<UFG::qPropertyList>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
  }
  result = (UFG::qPropertyList *)sop->mpWritableProperties;
  if ( !result )
  {
    result = (UFG::qPropertyList *)sop->mpConstProperties;
    goto LABEL_9;
  }
  return UFG::qPropertySet::Get<UFG::qPropertyList>((UFG::qPropertySet *)result, propName, DEPTH_RECURSE);
}

// File Line: 130
// RVA: 0x236FE0
void __fastcall PropertyUtils::Set<UFG::qSymbol>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qSymbol *v)
{
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v9; // rax

  mpConstProperties = sop->mpConstProperties;
  if ( !mpConstProperties )
    mpConstProperties = sop->mpWritableProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpConstProperties, propName);
  if ( SchemaForProperty )
  {
    mpWritableProperties = sop->mpConstProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = sop->mpWritableProperties;
    v9 = UFG::PropertySetManager::AddComponentPropertySet(mpWritableProperties, SchemaForProperty, 0i64);
LABEL_9:
    if ( !v9 )
      return;
    goto LABEL_10;
  }
  v9 = sop->mpConstProperties;
  if ( !v9 )
  {
    v9 = sop->mpWritableProperties;
    goto LABEL_9;
  }
LABEL_10:
  UFG::qPropertySet::Set<UFG::qSymbol>(v9, propName, v);
}

// File Line: 151
// RVA: 0x237320
void __fastcall PropertyUtils::SetRuntime<bool>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName,
        bool v)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *ContainedSet; // rax
  UFG::PropertyModificationCallbackSupress v8; // [rsp+40h] [rbp+8h] BYREF

  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v8);
  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    ContainedSet = UFG::qPropertySet::CreateContainedSet(&UFG::gLocalPropertySet, "WritableSceneObjProperties");
    sop->mpWritableProperties = ContainedSet;
    UFG::qPropertySet::AddRef(ContainedSet);
    UFG::PSWrapper::AppendParentLocal(sop->mpWritableProperties, sop->mpConstProperties);
    mpWritableProperties = sop->mpWritableProperties;
  }
  UFG::qPropertySet::Set<bool>(mpWritableProperties, propName, v);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v8);
}

// File Line: 153
// RVA: 0x2370A0
void __fastcall PropertyUtils::SetRuntime<unsigned long>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName,
        unsigned int v)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *ContainedSet; // rax
  UFG::PropertyModificationCallbackSupress v8; // [rsp+40h] [rbp+8h] BYREF

  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v8);
  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    ContainedSet = UFG::qPropertySet::CreateContainedSet(&UFG::gLocalPropertySet, "WritableSceneObjProperties");
    sop->mpWritableProperties = ContainedSet;
    UFG::qPropertySet::AddRef(ContainedSet);
    UFG::PSWrapper::AppendParentLocal(sop->mpWritableProperties, sop->mpConstProperties);
    mpWritableProperties = sop->mpWritableProperties;
  }
  UFG::qPropertySet::Set<unsigned long>(mpWritableProperties, propName, v);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v8);
}

// File Line: 154
// RVA: 0x237280
void __fastcall PropertyUtils::SetRuntime<UFG::qSymbol>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qSymbol *v)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *ContainedSet; // rax
  UFG::PropertyModificationCallbackSupress v8; // [rsp+40h] [rbp+8h] BYREF

  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v8);
  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    ContainedSet = UFG::qPropertySet::CreateContainedSet(&UFG::gLocalPropertySet, "WritableSceneObjProperties");
    sop->mpWritableProperties = ContainedSet;
    UFG::qPropertySet::AddRef(ContainedSet);
    UFG::PSWrapper::AppendParentLocal(sop->mpWritableProperties, sop->mpConstProperties);
    mpWritableProperties = sop->mpWritableProperties;
  }
  UFG::qPropertySet::Set<UFG::qSymbol>(mpWritableProperties, propName, v);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v8);
}

// File Line: 157
// RVA: 0x237140
void __fastcall PropertyUtils::SetRuntime<float>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName,
        float v)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *ContainedSet; // rax
  UFG::PropertyModificationCallbackSupress v7; // [rsp+50h] [rbp+8h] BYREF

  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v7);
  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    ContainedSet = UFG::qPropertySet::CreateContainedSet(&UFG::gLocalPropertySet, "WritableSceneObjProperties");
    sop->mpWritableProperties = ContainedSet;
    UFG::qPropertySet::AddRef(ContainedSet);
    UFG::PSWrapper::AppendParentLocal(sop->mpWritableProperties, sop->mpConstProperties);
    mpWritableProperties = sop->mpWritableProperties;
  }
  UFG::qPropertySet::Set<float>(mpWritableProperties, propName, v);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v7);
}

// File Line: 164
// RVA: 0x2371E0
void __fastcall PropertyUtils::SetRuntime<UFG::qPropertyList>(
        UFG::SceneObjectProperties *sop,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyList *v)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *ContainedSet; // rax
  UFG::PropertyModificationCallbackSupress v8; // [rsp+40h] [rbp+8h] BYREF

  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v8);
  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    ContainedSet = UFG::qPropertySet::CreateContainedSet(&UFG::gLocalPropertySet, "WritableSceneObjProperties");
    sop->mpWritableProperties = ContainedSet;
    UFG::qPropertySet::AddRef(ContainedSet);
    UFG::PSWrapper::AppendParentLocal(sop->mpWritableProperties, sop->mpConstProperties);
    mpWritableProperties = sop->mpWritableProperties;
  }
  UFG::qPropertySet::Set<UFG::qPropertyList>(mpWritableProperties, propName, v);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v8);
}

// File Line: 167
// RVA: 0x244530
bool __fastcall PropertyUtils::PropertyExists(UFG::SceneObjectProperties *sop, UFG::qArray<unsigned long,0> *propName)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::SchemaDef *SchemaForProperty; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *v7; // rax

  mpWritableProperties = sop->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sop->mpConstProperties;
  SchemaForProperty = UFG::PropertySetManager::GetSchemaForProperty(mpWritableProperties, propName);
  if ( SchemaForProperty )
  {
    mpConstProperties = sop->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sop->mpConstProperties;
    v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           mpConstProperties,
           (UFG::qArray<unsigned long,0> *)&SchemaForProperty->mPropertyName,
           DEPTH_RECURSE);
  }
  else
  {
    v7 = sop->mpWritableProperties;
    if ( v7 )
      return UFG::qPropertySet::PropertyExists(v7, propName, DEPTH_RECURSE) != 0i64;
    v7 = sop->mpConstProperties;
  }
  if ( v7 )
    return UFG::qPropertySet::PropertyExists(v7, propName, DEPTH_RECURSE) != 0i64;
  return 0;
}

// File Line: 202
// RVA: 0x23E4B0
bool __fastcall PropertyUtils::HasComponentPropertySet(
        UFG::SceneObjectProperties *sceneObject,
        UFG::qArray<unsigned long,0> *componentPropertySetName)
{
  UFG::qPropertySet *mpWritableProperties; // rbx
  UFG::SchemaDef *Schema; // rax

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  Schema = UFG::PropertySetManager::GetSchema(componentPropertySetName);
  if ( Schema )
    return UFG::qPropertySet::PropertyExists(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&Schema->mPropertyName,
             DEPTH_RECURSE) != 0i64;
  else
    return UFG::qPropertySet::GetParentFromName(mpWritableProperties, componentPropertySetName, DEPTH_RECURSE) != 0i64;
}

