// File Line: 32
// RVA: 0x236A50
char *__fastcall PropertyUtils::Get<char const *>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<char const *>(set, propName, depth);
}

// File Line: 33
// RVA: 0x236F10
bool *__fastcall PropertyUtils::Get<bool>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<bool>(set, propName, depth);
}

// File Line: 34
// RVA: 0x2368F0
unsigned int *__fastcall PropertyUtils::Get<unsigned long>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<unsigned long>(set, propName, depth);
}

// File Line: 35
// RVA: 0x236840
int *__fastcall PropertyUtils::Get<long>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<long>(set, propName, depth);
}

// File Line: 36
// RVA: 0x2369A0
float *__fastcall PropertyUtils::Get<float>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<float>(set, propName, depth);
}

// File Line: 41
// RVA: 0x236B00
UFG::qMatrix44 *__fastcall PropertyUtils::Get<UFG::qMatrix44>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<UFG::qMatrix44>(set, propName, depth);
}

// File Line: 42
// RVA: 0x236D10
UFG::qSymbol *__fastcall PropertyUtils::Get<UFG::qSymbol>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<UFG::qSymbol>(set, propName, depth);
}

// File Line: 43
// RVA: 0x236D20
UFG::qSymbolUC *__fastcall PropertyUtils::Get<UFG::qSymbolUC>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<UFG::qSymbolUC>(set, propName, depth);
}

// File Line: 44
// RVA: 0x236BC0
UFG::qPropertySet *__fastcall PropertyUtils::Get<UFG::qPropertySet>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<UFG::qPropertySet>(set, propName, depth);
}

// File Line: 45
// RVA: 0x236BB0
UFG::qPropertyList *__fastcall PropertyUtils::Get<UFG::qPropertyList>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qPropertyDepth depth)
{
  return UFG::qPropertySet::Get<UFG::qPropertyList>(set, propName, depth);
}

// File Line: 54
// RVA: 0x236FC0
void __fastcall PropertyUtils::Set<char const *>(UFG::qPropertySet *set, UFG::qSymbol *propName, const char *v)
{
  UFG::qPropertySet::Set<char const *>(set, propName, v);
}

// File Line: 55
// RVA: 0x237090
void __fastcall PropertyUtils::Set<bool>(UFG::qPropertySet *set, UFG::qSymbol *propName, bool v)
{
  UFG::qPropertySet::Set<bool>(set, propName, v);
}

// File Line: 57
// RVA: 0x236FA0
void __fastcall PropertyUtils::Set<long>(UFG::qPropertySet *set, UFG::qSymbol *propName, int v)
{
  UFG::qPropertySet::Set<long>(set, propName, v);
}

// File Line: 58
// RVA: 0x236FB0
void __fastcall PropertyUtils::Set<float>(UFG::qPropertySet *set, UFG::qSymbol *propName, float v)
{
  UFG::qPropertySet::Set<float>(set, propName, v);
}

// File Line: 60
// RVA: 0x237070
void __fastcall PropertyUtils::Set<UFG::qSymbol>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qSymbol *v)
{
  UFG::qPropertySet::Set<UFG::qSymbol>(set, propName, v);
}

// File Line: 64
// RVA: 0x237080
void __fastcall PropertyUtils::Set<UFG::qVector3>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qVector3 *v)
{
  UFG::qPropertySet::Set<UFG::qVector3>(set, propName, v);
}

// File Line: 66
// RVA: 0x236FD0
void __fastcall PropertyUtils::Set<UFG::qPropertySet>(UFG::qPropertySet *set, UFG::qSymbol *propName, UFG::qPropertySet *v)
{
  UFG::qPropertySet::Set<UFG::qPropertySet>(set, propName, v);
}

// File Line: 93
// RVA: 0x2369B0
UFG::qPropertySet *__fastcall PropertyUtils::Get<char const *>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<char const *>(result, v4, DEPTH_RECURSE);
  }
  result = v2->mpWritableProperties;
  if ( !result )
  {
    result = v2->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<char const *>(result, v4, DEPTH_RECURSE);
}

// File Line: 94
// RVA: 0x236E70
UFG::qPropertySet *__fastcall PropertyUtils::Get<bool>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<bool>(result, v4, DEPTH_RECURSE);
  }
  result = v2->mpWritableProperties;
  if ( !result )
  {
    result = v2->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<bool>(result, v4, DEPTH_RECURSE);
}

// File Line: 95
// RVA: 0x236850
UFG::qPropertySet *__fastcall PropertyUtils::Get<unsigned long>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<unsigned long>(result, v4, DEPTH_RECURSE);
  }
  result = v2->mpWritableProperties;
  if ( !result )
  {
    result = v2->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<unsigned long>(result, v4, DEPTH_RECURSE);
}

// File Line: 96
// RVA: 0x2367A0
UFG::qPropertySet *__fastcall PropertyUtils::Get<long>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<long>(result, v4, DEPTH_RECURSE);
  }
  result = v2->mpWritableProperties;
  if ( !result )
  {
    result = v2->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<long>(result, v4, DEPTH_RECURSE);
}

// File Line: 97
// RVA: 0x236900
UFG::qPropertySet *__fastcall PropertyUtils::Get<float>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<float>(result, v4, DEPTH_RECURSE);
  }
  result = v2->mpWritableProperties;
  if ( !result )
  {
    result = v2->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<float>(result, v4, DEPTH_RECURSE);
}

// File Line: 99
// RVA: 0x236C70
UFG::qPropertySet *__fastcall PropertyUtils::Get<UFG::qSymbol>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qSymbol>(result, v4, DEPTH_RECURSE);
  }
  result = v2->mpWritableProperties;
  if ( !result )
  {
    result = v2->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qSymbol>(result, v4, DEPTH_RECURSE);
}

// File Line: 101
// RVA: 0x236DD0
UFG::qPropertySet *__fastcall PropertyUtils::Get<UFG::qWiseSymbol>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qWiseSymbol>(result, v4, DEPTH_RECURSE);
  }
  result = v2->mpWritableProperties;
  if ( !result )
  {
    result = v2->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qWiseSymbol>(result, v4, DEPTH_RECURSE);
}

// File Line: 103
// RVA: 0x236D30
UFG::qPropertySet *__fastcall PropertyUtils::Get<UFG::qVector3>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qVector3>(result, v4, DEPTH_RECURSE);
  }
  result = v2->mpWritableProperties;
  if ( !result )
  {
    result = v2->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qVector3>(result, v4, DEPTH_RECURSE);
}

// File Line: 105
// RVA: 0x236A60
UFG::qPropertySet *__fastcall PropertyUtils::Get<UFG::qMatrix44>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qMatrix44>(result, v4, DEPTH_RECURSE);
  }
  result = v2->mpWritableProperties;
  if ( !result )
  {
    result = v2->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qMatrix44>(result, v4, DEPTH_RECURSE);
}

// File Line: 106
// RVA: 0x236BD0
UFG::qPropertySet *__fastcall PropertyUtils::Get<UFG::qPropertySet>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return UFG::qPropertySet::Get<UFG::qPropertySet>(result, v4, DEPTH_RECURSE);
  }
  result = v2->mpWritableProperties;
  if ( !result )
  {
    result = v2->mpConstProperties;
    goto LABEL_9;
  }
  return UFG::qPropertySet::Get<UFG::qPropertySet>(result, v4, DEPTH_RECURSE);
}

// File Line: 107
// RVA: 0x236B10
UFG::qPropertySet *__fastcall PropertyUtils::Get<UFG::qPropertyList>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
LABEL_9:
    if ( !result )
      return result;
    return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qPropertyList>(result, v4, DEPTH_RECURSE);
  }
  result = v2->mpWritableProperties;
  if ( !result )
  {
    result = v2->mpConstProperties;
    goto LABEL_9;
  }
  return (UFG::qPropertySet *)UFG::qPropertySet::Get<UFG::qPropertyList>(result, v4, DEPTH_RECURSE);
}

// File Line: 130
// RVA: 0x236FE0
void __fastcall PropertyUtils::Set<UFG::qSymbol>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName, UFG::qSymbol *v)
{
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qSymbol *v5; // rsi
  UFG::qSymbol *v6; // rdi
  UFG::SchemaDef *v7; // rax
  UFG::qPropertySet *v8; // rcx
  UFG::qPropertySet *v9; // rax

  v3 = sop;
  v4 = sop->mpConstProperties;
  v5 = v;
  v6 = propName;
  if ( !v4 )
    v4 = v3->mpWritableProperties;
  v7 = UFG::PropertySetManager::GetSchemaForProperty(v4, propName);
  if ( v7 )
  {
    v8 = v3->mpConstProperties;
    if ( !v8 )
      v8 = v3->mpWritableProperties;
    v9 = UFG::PropertySetManager::AddComponentPropertySet(v8, v7, 0i64);
LABEL_9:
    if ( !v9 )
      return;
    goto LABEL_10;
  }
  v9 = v3->mpConstProperties;
  if ( !v9 )
  {
    v9 = v3->mpWritableProperties;
    goto LABEL_9;
  }
LABEL_10:
  UFG::qPropertySet::Set<UFG::qSymbol>(v9, v6, v5);
}

// File Line: 151
// RVA: 0x237320
void __fastcall PropertyUtils::SetRuntime<bool>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName, bool v)
{
  bool v3; // di
  UFG::qSymbol *v4; // rsi
  UFG::SceneObjectProperties *v5; // rbx
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *v7; // rax
  char v8; // [rsp+40h] [rbp+8h]

  v3 = v;
  v4 = propName;
  v5 = sop;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v8);
  v6 = v5->mpWritableProperties;
  if ( !v6 )
  {
    v7 = UFG::qPropertySet::CreateContainedSet(
           (UFG::qSymbol *)&UFG::gLocalPropertySet.mUID,
           "WritableSceneObjProperties");
    v5->mpWritableProperties = v7;
    UFG::qPropertySet::AddRef(v7);
    UFG::PSWrapper::AppendParentLocal(v5->mpWritableProperties, v5->mpConstProperties);
    v6 = v5->mpWritableProperties;
  }
  UFG::qPropertySet::Set<bool>(v6, v4, v3);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v8);
}

// File Line: 153
// RVA: 0x2370A0
void __fastcall PropertyUtils::SetRuntime<unsigned long>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName, unsigned int v)
{
  unsigned int v3; // edi
  UFG::qSymbol *v4; // rsi
  UFG::SceneObjectProperties *v5; // rbx
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *v7; // rax
  char v8; // [rsp+40h] [rbp+8h]

  v3 = v;
  v4 = propName;
  v5 = sop;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v8);
  v6 = v5->mpWritableProperties;
  if ( !v6 )
  {
    v7 = UFG::qPropertySet::CreateContainedSet(
           (UFG::qSymbol *)&UFG::gLocalPropertySet.mUID,
           "WritableSceneObjProperties");
    v5->mpWritableProperties = v7;
    UFG::qPropertySet::AddRef(v7);
    UFG::PSWrapper::AppendParentLocal(v5->mpWritableProperties, v5->mpConstProperties);
    v6 = v5->mpWritableProperties;
  }
  UFG::qPropertySet::Set<unsigned long>(v6, v4, v3);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v8);
}

// File Line: 154
// RVA: 0x237280
void __fastcall PropertyUtils::SetRuntime<UFG::qSymbol>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName, UFG::qSymbol *v)
{
  UFG::qSymbol *v3; // rdi
  UFG::qSymbol *v4; // rsi
  UFG::SceneObjectProperties *v5; // rbx
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *v7; // rax
  char v8; // [rsp+40h] [rbp+8h]

  v3 = v;
  v4 = propName;
  v5 = sop;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v8);
  v6 = v5->mpWritableProperties;
  if ( !v6 )
  {
    v7 = UFG::qPropertySet::CreateContainedSet(
           (UFG::qSymbol *)&UFG::gLocalPropertySet.mUID,
           "WritableSceneObjProperties");
    v5->mpWritableProperties = v7;
    UFG::qPropertySet::AddRef(v7);
    UFG::PSWrapper::AppendParentLocal(v5->mpWritableProperties, v5->mpConstProperties);
    v6 = v5->mpWritableProperties;
  }
  UFG::qPropertySet::Set<UFG::qSymbol>(v6, v4, v3);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v8);
}

// File Line: 157
// RVA: 0x237140
void __fastcall PropertyUtils::SetRuntime<float>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName, float v)
{
  UFG::qSymbol *v3; // rdi
  UFG::SceneObjectProperties *v4; // rbx
  UFG::qPropertySet *v5; // rcx
  UFG::qPropertySet *v6; // rax
  char v7; // [rsp+50h] [rbp+8h]

  v3 = propName;
  v4 = sop;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v7);
  v5 = v4->mpWritableProperties;
  if ( !v5 )
  {
    v6 = UFG::qPropertySet::CreateContainedSet(
           (UFG::qSymbol *)&UFG::gLocalPropertySet.mUID,
           "WritableSceneObjProperties");
    v4->mpWritableProperties = v6;
    UFG::qPropertySet::AddRef(v6);
    UFG::PSWrapper::AppendParentLocal(v4->mpWritableProperties, v4->mpConstProperties);
    v5 = v4->mpWritableProperties;
  }
  UFG::qPropertySet::Set<float>(v5, v3, v);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v7);
}

// File Line: 164
// RVA: 0x2371E0
void __fastcall PropertyUtils::SetRuntime<UFG::qPropertyList>(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName, UFG::qPropertyList *v)
{
  UFG::qPropertyList *v3; // rdi
  UFG::qSymbol *v4; // rsi
  UFG::SceneObjectProperties *v5; // rbx
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *v7; // rax
  char v8; // [rsp+40h] [rbp+8h]

  v3 = v;
  v4 = propName;
  v5 = sop;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v8);
  v6 = v5->mpWritableProperties;
  if ( !v6 )
  {
    v7 = UFG::qPropertySet::CreateContainedSet(
           (UFG::qSymbol *)&UFG::gLocalPropertySet.mUID,
           "WritableSceneObjProperties");
    v5->mpWritableProperties = v7;
    UFG::qPropertySet::AddRef(v7);
    UFG::PSWrapper::AppendParentLocal(v5->mpWritableProperties, v5->mpConstProperties);
    v6 = v5->mpWritableProperties;
  }
  UFG::qPropertySet::Set<UFG::qPropertyList>(v6, v4, v3);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v8);
}

// File Line: 167
// RVA: 0x244530
bool __fastcall PropertyUtils::PropertyExists(UFG::SceneObjectProperties *sop, UFG::qSymbol *propName)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qSymbol *v4; // rdi
  UFG::SchemaDef *v5; // rax
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *v7; // rax

  v2 = sop;
  v3 = sop->mpWritableProperties;
  v4 = propName;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  v5 = UFG::PropertySetManager::GetSchemaForProperty(v3, propName);
  if ( v5 )
  {
    v6 = v2->mpWritableProperties;
    if ( !v6 )
      v6 = v2->mpConstProperties;
    v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, &v5->mPropertyName, DEPTH_RECURSE);
  }
  else
  {
    v7 = v2->mpWritableProperties;
    if ( v7 )
      return UFG::qPropertySet::PropertyExists(v7, v4, DEPTH_RECURSE) != 0i64;
    v7 = v2->mpConstProperties;
  }
  if ( v7 )
    return UFG::qPropertySet::PropertyExists(v7, v4, DEPTH_RECURSE) != 0i64;
  return 0;
}

// File Line: 202
// RVA: 0x23E4B0
bool __fastcall PropertyUtils::HasComponentPropertySet(UFG::SceneObjectProperties *sceneObject, UFG::qSymbol *componentPropertySetName)
{
  UFG::qPropertySet *v2; // rbx
  UFG::qSymbol *v3; // rdi
  UFG::SchemaDef *v4; // rax
  bool result; // al

  v2 = sceneObject->mpWritableProperties;
  v3 = componentPropertySetName;
  if ( !v2 )
    v2 = sceneObject->mpConstProperties;
  v4 = UFG::PropertySetManager::GetSchema(componentPropertySetName);
  if ( v4 )
    result = UFG::qPropertySet::PropertyExists(v2, &v4->mPropertyName, DEPTH_RECURSE) != 0i64;
  else
    result = UFG::qPropertySet::GetParentFromName(v2, v3, DEPTH_RECURSE) != 0i64;
  return result;
}

