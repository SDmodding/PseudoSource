// File Line: 55
// RVA: 0x146BD80
__int64 UFG::_dynamic_initializer_for__PropertySetManager_SchemaComponentPropertyLookup__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PropertySetManager_SchemaComponentPropertyLookup.mTree);
  return atexit(UFG::_dynamic_atexit_destructor_for__PropertySetManager_SchemaComponentPropertyLookup__);
}

// File Line: 62
// RVA: 0x1ECE60
void __fastcall UFG::SchemaDef::SchemaDef(UFG::SchemaDef *this, UFG::qPropertySet *propertySet, UFG::SchemaDef *parentSchema)
{
  UFG::qArray<unsigned long,0> *v3; // rax
  UFG::qSymbol *v4; // rax
  const char *v5; // rax
  const char *v6; // rax
  const char *v7; // rax
  const char *v8; // rax
  const char *v9; // rax
  UFG::qArray<unsigned long,0> *v10; // rax
  unsigned int v11; // eax
  unsigned int v12; // eax
  UFG::qBaseNodeRB *v13; // [rsp+28h] [rbp-110h]
  UFG::qSymbol v14; // [rsp+40h] [rbp-F8h]
  unsigned int uid; // [rsp+48h] [rbp-F0h]
  UFG::qSymbol v16; // [rsp+50h] [rbp-E8h]
  UFG::qBaseNodeRB *v17; // [rsp+58h] [rbp-E0h]
  UFG::qPropertySetResource *v18; // [rsp+60h] [rbp-D8h]
  UFG::qSymbol *source; // [rsp+68h] [rbp-D0h]
  UFG::qString *v20; // [rsp+70h] [rbp-C8h]
  UFG::qList<UFG::qPropertySet,UFG::qPropertySet,1,0> *v21; // [rsp+78h] [rbp-C0h]
  UFG::qString *v22; // [rsp+80h] [rbp-B8h]
  UFG::qBaseNodeRB *v23; // [rsp+88h] [rbp-B0h]
  UFG::qSymbol *v24; // [rsp+90h] [rbp-A8h]
  UFG::qString *text; // [rsp+98h] [rbp-A0h]
  UFG::qSymbol *v26; // [rsp+A0h] [rbp-98h]
  UFG::qTypedResourceHandle<1415605297,UFG::qPropertySetResource> *v27; // [rsp+A8h] [rbp-90h]
  UFG::qBaseNodeRB *x; // [rsp+B0h] [rbp-88h]
  UFG::qString *v29; // [rsp+B8h] [rbp-80h]
  UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0> *v30; // [rsp+C0h] [rbp-78h]
  UFG::qSymbol *v31; // [rsp+C8h] [rbp-70h]
  __int64 v32; // [rsp+D0h] [rbp-68h]
  UFG::qString result; // [rsp+D8h] [rbp-60h]
  UFG::qString v34; // [rsp+100h] [rbp-38h]
  UFG::SchemaDef *derivedDef; // [rsp+140h] [rbp+8h]
  UFG::qPropertySet *v36; // [rsp+148h] [rbp+10h]
  UFG::SchemaDef *v37; // [rsp+150h] [rbp+18h]

  v37 = parentSchema;
  v36 = propertySet;
  derivedDef = this;
  v32 = -2i64;
  this->mPrev = (UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *)&this->mPrev;
  v3 = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(propertySet);
  uid = UFG::qSymbolUC::as_uint32(v3);
  v23 = &derivedDef->mNode;
  UFG::qBaseNodeRB::qBaseNodeRB(&derivedDef->mNode, uid);
  derivedDef->mbComponentSchema = 0;
  derivedDef->mbSkipParentCheck = 0;
  BackInfo::BackInfo(&derivedDef->mName);
  UFG::qString::qString(&derivedDef->mNameString);
  BackInfo::BackInfo(&derivedDef->mClassName);
  UFG::qString::qString(&derivedDef->mClassNameString);
  BackInfo::BackInfo(&derivedDef->mPropertyName);
  UFG::qString::qString(&derivedDef->mPropertyNameString);
  v27 = (UFG::qTypedResourceHandle<1415605297,UFG::qPropertySetResource> *)&derivedDef->mPropertySet.mPrev;
  UFG::qTypedResourceHandle<1415605297,UFG::qPropertySetResource>::qTypedResourceHandle<1415605297,UFG::qPropertySetResource>((UFG::qTypedResourceHandle<1415605297,UFG::qPropertySetResource> *)&derivedDef->mPropertySet.mPrev);
  v21 = &derivedDef->mPropertySetInstances;
  derivedDef->mPropertySetInstances.mNode.mPrev = &derivedDef->mPropertySetInstances.mNode;
  derivedDef->mPropertySetInstances.mNode.mNext = &derivedDef->mPropertySetInstances.mNode;
  derivedDef->mpParentSchema = v37;
  v30 = &derivedDef->mDerivedSchemas;
  derivedDef->mDerivedSchemas.mNode.mPrev = &derivedDef->mDerivedSchemas.mNode;
  derivedDef->mDerivedSchemas.mNode.mNext = &derivedDef->mDerivedSchemas.mNode;
  v18 = UFG::qPropertySet::GetResource(v36);
  v4 = UFG::qPropertySet::GetName(v36);
  UFG::qSymbol::qSymbol(&derivedDef->mName, v4);
  v5 = UFG::qPropertySetResource::GetNameString(v18);
  UFG::qString::operator=(&derivedDef->mNameString, v5);
  v6 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&derivedDef->mNameString);
  v29 = UFG::PropertySchemaUtils::classNameFromPropSetName(&result, v6);
  text = v29;
  UFG::qString::operator=(&derivedDef->mPropertyNameString, v29);
  UFG::qString::~qString(&result);
  v7 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&derivedDef->mPropertyNameString);
  v31 = UFG::qSymbol::create_from_string(&v16, v7);
  source = v31;
  UFG::qSymbol::qSymbol(&derivedDef->mPropertyName, v31);
  _((AMD_HD3D *)&v16);
  v8 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&derivedDef->mNameString);
  v20 = UFG::PropertySchemaUtils::classNameFromPropSetName(&v34, v8);
  v22 = v20;
  UFG::qString::operator=(&derivedDef->mClassNameString, v20);
  UFG::qString::~qString(&v34);
  v9 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&derivedDef->mClassNameString);
  v24 = UFG::qSymbol::create_from_string(&v14, v9);
  v26 = v24;
  UFG::qSymbol::qSymbol(&derivedDef->mClassName, v24);
  _((AMD_HD3D *)&v14);
  v10 = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(v36);
  v11 = UFG::qSymbolUC::as_uint32(v10);
  UFG::qPropertySetHandle::Init(&derivedDef->mPropertySet, v11);
  if ( v37 )
    UFG::SchemaDef::AddDerivedSchema(v37, derivedDef);
  v13 = (UFG::qBaseNodeRB *)AMemory::malloc_default(0x28ui64);
  if ( v13 )
  {
    v12 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&derivedDef->mPropertyName);
    UFG::qBaseNodeRB::qBaseNodeRB(v13, v12);
    v13[1].mParent = (UFG::qBaseNodeRB *)derivedDef;
    v17 = v13;
  }
  else
  {
    v17 = 0i64;
  }
  x = v17;
  UFG::qBaseTreeRB::Add(&UFG::PropertySetManager_SchemaComponentPropertyLookup.mTree, v17);
}

// File Line: 84
// RVA: 0x1F18D0
void __fastcall UFG::SchemaDef::AddDerivedSchema(UFG::SchemaDef *this, UFG::SchemaDef *derivedDef)
{
  UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *v2; // ST10_8

  derivedDef->mpParentSchema = this;
  v2 = this->mDerivedSchemas.mNode.mPrev;
  v2->mNext = (UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *)&derivedDef->mPrev;
  derivedDef->mPrev = v2;
  derivedDef->mNext = &this->mDerivedSchemas.mNode;
  this->mDerivedSchemas.mNode.mPrev = (UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *)&derivedDef->mPrev;
}

// File Line: 90
// RVA: 0x1F9A00
char __fastcall UFG::SchemaDef::IsDerivedFrom(UFG::SchemaDef *this, UFG::SchemaDef *otherSchema)
{
  UFG::SchemaDef *i; // [rsp+0h] [rbp-18h]

  for ( i = this; i; i = i->mpParentSchema )
  {
    if ( i == otherSchema )
      return 1;
  }
  return 0;
}

// File Line: 121
// RVA: 0x146BD50
__int64 UFG::_dynamic_initializer_for__PropertySetManager_Rootpath__()
{
  UFG::qString::qString(&UFG::PropertySetManager_Rootpath, "Data\\PropertySets\\");
  return atexit(UFG::_dynamic_atexit_destructor_for__PropertySetManager_Rootpath__);
}

// File Line: 126
// RVA: 0x146BCC0
__int64 UFG::_dynamic_initializer_for__PropertySetManager_CurrentlyLoadingFileStack__()
{
  UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::PropertySetManager_CurrentlyLoadingFileStack;
  UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::PropertySetManager_CurrentlyLoadingFileStack;
  return atexit(UFG::_dynamic_atexit_destructor_for__PropertySetManager_CurrentlyLoadingFileStack__);
}

// File Line: 131
// RVA: 0x146BDB0
__int64 UFG::_dynamic_initializer_for__PropertySetManager_SchemaDefs__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PropertySetManager_SchemaDefs.mTree);
  return atexit(UFG::_dynamic_atexit_destructor_for__PropertySetManager_SchemaDefs__);
}

// File Line: 132
// RVA: 0x146BD10
__int64 UFG::_dynamic_initializer_for__PropertySetManager_PropertyLookup__()
{
  UFG::PropertySetManager_PropertyLookup.p = 0i64;
  UFG::PropertySetManager_PropertyLookup.size = 0;
  UFG::PropertySetManager_PropertyLookup.capacity = 0;
  return atexit(UFG::_dynamic_atexit_destructor_for__PropertySetManager_PropertyLookup__);
}

// File Line: 139
// RVA: 0x1ECD10
void __fastcall UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(UFG::PropertyModificationCallbackSupress *this)
{
  ++UFG::PropertySetManager_CallbackSupressionRefCount;
}

// File Line: 144
// RVA: 0x1EE570
void __fastcall UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(UFG::PropertyModificationCallbackSupress *this)
{
  --UFG::PropertySetManager_CallbackSupressionRefCount;
}

// File Line: 149
// RVA: 0x1FF740
_BOOL8 __fastcall UFG::fnSortPropertyLookup(UFG::PropertyLookup *a, UFG::PropertyLookup *b)
{
  return a->mPropertyNameUID < b->mPropertyNameUID;
}

// File Line: 154
// RVA: 0x1F6D20
void __fastcall UFG::GetDerivedSchemaList(UFG::SchemaDef *schema_def, UFG::qArray<UFG::SchemaDef *,0> *derived_schemas)
{
  unsigned int v2; // ST30_4
  UFG::SchemaDef *schema_defa; // [rsp+28h] [rbp-80h]
  UFG::SchemaDef *v4; // [rsp+B0h] [rbp+8h]
  UFG::qArray<UFG::SchemaDef *,0> *derived_schemasa; // [rsp+B8h] [rbp+10h]

  derived_schemasa = derived_schemas;
  v4 = schema_def;
  if ( schema_def->mDerivedSchemas.mNode.mNext == &schema_def->mDerivedSchemas.mNode )
  {
    v2 = derived_schemas->size;
    UFG::qArray<UFG::SchemaDef *,0>::Grow(derived_schemas, 1u, "qArray.Add");
    derived_schemasa->p[v2] = v4;
  }
  for ( schema_defa = (UFG::SchemaDef *)v4->mDerivedSchemas.mNode.mNext;
        schema_defa != (UFG::SchemaDef *)&v4->mDerivedSchemas;
        schema_defa = (UFG::SchemaDef *)schema_defa->mNext )
  {
    UFG::GetDerivedSchemaList(schema_defa, derived_schemasa);
  }
}

// File Line: 168
// RVA: 0x1F5590
UFG::qSymbol *__fastcall UFG::FindSchema(UFG::qPropertySet *propertySet, UFG::qArray<UFG::SchemaDef *,0> *derived_schemas)
{
  UFG::qPropertySet *v3; // ST40_8
  unsigned int i; // [rsp+20h] [rbp-38h]
  unsigned int parent_index; // [rsp+24h] [rbp-34h]
  unsigned int v6; // [rsp+2Ch] [rbp-2Ch]
  UFG::qSymbol *v7; // [rsp+30h] [rbp-28h]
  UFG::SchemaDef *v8; // [rsp+38h] [rbp-20h]
  UFG::qPropertySet *v9; // [rsp+60h] [rbp+8h]
  UFG::qArray<UFG::SchemaDef *,0> *derived_schemasa; // [rsp+68h] [rbp+10h]

  derived_schemasa = derived_schemas;
  v9 = propertySet;
  for ( i = 0; i < derived_schemasa->size; ++i )
  {
    v7 = (UFG::qSymbol *)derived_schemasa->p[i];
    if ( UFG::qPropertySet::PropertyExists(v9, v7 + 36, 0) )
      return v7;
  }
  v6 = UFG::qPropertySet::NumParents(v9);
  for ( parent_index = 0; parent_index < v6; ++parent_index )
  {
    v3 = UFG::qPropertySet::GetParentFromIdx(v9, parent_index);
    v8 = UFG::FindSchema(v3, derived_schemasa);
    if ( v8 )
      return (UFG::qSymbol *)v8;
  }
  return 0i64;
}

// File Line: 217
// RVA: 0x1F8200
UFG::SchemaDef *__fastcall UFG::PropertySetManager::GetSchemaForProperty(UFG::qPropertySet *propertySet, UFG::qSymbol *propertyName)
{
  UFG::qSymbolUC *v2; // rax
  char *v3; // rax
  int v5; // [rsp+30h] [rbp-68h]
  UFG::SchemaDef *schema_def; // [rsp+38h] [rbp-60h]
  unsigned int v7; // [rsp+40h] [rbp-58h]
  int v8; // [rsp+44h] [rbp-54h]
  int v9; // [rsp+48h] [rbp-50h]
  UFG::SchemaDef *v10; // [rsp+50h] [rbp-48h]
  UFG::qArray<UFG::SchemaDef *,0> derived_schemas; // [rsp+60h] [rbp-38h]
  hkResourceContainer *v12; // [rsp+70h] [rbp-28h]
  hkResourceContainer *v13; // [rsp+78h] [rbp-20h]
  char *v14; // [rsp+80h] [rbp-18h]
  __int64 v15; // [rsp+88h] [rbp-10h]
  UFG::qPropertySet *propertySeta; // [rsp+A0h] [rbp+8h]
  UFG::qArray<unsigned long,0> *v17; // [rsp+A8h] [rbp+10h]

  v17 = (UFG::qArray<unsigned long,0> *)propertyName;
  propertySeta = propertySet;
  v15 = -2i64;
  if ( !UFG::PropertySetManager_PropertyLookup_IsSorted )
  {
    UFG::qSort<UFG::PropertyLookup,bool (*)(UFG::PropertyLookup const &,UFG::PropertyLookup const &)>(
      UFG::PropertySetManager_PropertyLookup.p,
      UFG::PropertySetManager_PropertyLookup.size,
      UFG::fnSortPropertyLookup);
    UFG::PropertySetManager_PropertyLookup_IsSorted = 1;
  }
  schema_def = 0i64;
  v9 = 0;
  v8 = UFG::PropertySetManager_PropertyLookup.size - 1;
  while ( v9 <= v8 )
  {
    v5 = (v8 + v9) / 2;
    v7 = UFG::PropertySetManager_PropertyLookup.p[v5].mPropertyNameUID;
    if ( (unsigned int)UFG::qSymbolUC::as_uint32(v17) <= v7 )
    {
      if ( (unsigned int)UFG::qSymbolUC::as_uint32(v17) >= v7 )
      {
        if ( (unsigned int)UFG::qSymbolUC::as_uint32(v17) == v7 )
        {
          schema_def = UFG::PropertySetManager_PropertyLookup.p[v5].mSchemaDef;
          break;
        }
      }
      else
      {
        v8 = v5 - 1;
      }
    }
    else
    {
      v9 = v5 + 1;
    }
  }
  if ( schema_def )
  {
    if ( propertySeta )
    {
      v10 = schema_def;
      if ( !schema_def->mbSkipParentCheck )
      {
        derived_schemas.p = 0i64;
        derived_schemas.size = 0;
        derived_schemas.capacity = 0;
        UFG::GetDerivedSchemaList(schema_def, &derived_schemas);
        schema_def = (UFG::SchemaDef *)UFG::FindSchema(propertySeta, &derived_schemas);
        if ( !schema_def && UFG::PropertySetManager::GetCurrentlyLoadingFilename() )
        {
          v13 = UFG::PropertySetManager::GetCurrentlyLoadingFilename();
          v12 = Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&v10->mNameString);
          v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v17);
          v2 = (UFG::qSymbolUC *)UFG::qPropertySet::GetName(propertySeta);
          v3 = UFG::qSymbol::as_cstr_dbg(v2);
          UFG::qPrintf("Warning: %s defines property %s without parent %s [%s]\n", v3, v14, v12, v13);
          schema_def = v10;
        }
        UFG::qArray<UFG::PropertyLookup,0>::Clear((UFG::qArray<UFG::PropertyLookup,0> *)&derived_schemas);
      }
    }
  }
  return schema_def;
}

// File Line: 274
// RVA: 0x1F8190
UFG::qBaseNodeRB *__fastcall UFG::PropertySetManager::GetSchemaForComponentPropertyName(UFG::qSymbol *componentPropertyName)
{
  UFG::qBaseNodeRB *result; // rax
  unsigned int uid; // [rsp+20h] [rbp-28h]
  UFG::qBaseTreeRB *v3; // [rsp+28h] [rbp-20h]

  uid = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)componentPropertyName);
  if ( uid )
    v3 = UFG::qBaseTreeRB::Get(&UFG::PropertySetManager_SchemaComponentPropertyLookup.mTree, uid);
  else
    v3 = 0i64;
  if ( v3 )
    result = v3->mNULL.mParent;
  else
    result = 0i64;
  return result;
}

// File Line: 308
// RVA: 0x1F99A0
bool __fastcall UFG::PropertySetManager::IsComponentPropertySet(UFG::qPropertySet *property_set)
{
  UFG::qSymbol *v1; // rax
  _BOOL8 v2; // rax
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]

  v5 = property_set;
  if ( property_set
    && (v1 = UFG::qPropertySet::GetSchemaName(property_set), !UFG::qSymbol::operator==(v1, &UFG::gNullQSymbol)) )
  {
    v3 = UFG::qPropertySet::GetSchemaName(v5);
    v2 = UFG::PropertySetManager::GetSchema(v3)->mbComponentSchema;
  }
  else
  {
    LOBYTE(v2) = 0;
  }
  return v2;
}

// File Line: 317
// RVA: 0x1F8110
UFG::SchemaDef *__fastcall UFG::PropertySetManager::GetSchema(UFG::qSymbol *schemaName)
{
  unsigned int uid; // [rsp+20h] [rbp-38h]
  UFG::qBaseTreeRB *v3; // [rsp+28h] [rbp-30h]
  signed __int64 v4; // [rsp+30h] [rbp-28h]

  uid = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)schemaName);
  if ( !uid )
    return 0i64;
  v3 = UFG::qBaseTreeRB::Get(&UFG::PropertySetManager_SchemaDefs.mTree, uid);
  if ( v3 )
    v4 = (signed __int64)&v3[-1].mNULL.mUID;
  else
    v4 = 0i64;
  return (UFG::SchemaDef *)v4;
}

// File Line: 336
// RVA: 0x1E8F50
void __fastcall UFG::CopyProperty<short>(UFG::qPropertySet *target_set, UFG::qPropertySet *source_set, UFG::qSymbol *property_name)
{
  __int16 *v3; // [rsp+20h] [rbp-18h]
  UFG::qPropertySet *v4; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *name; // [rsp+50h] [rbp+18h]

  name = property_name;
  v4 = target_set;
  v3 = UFG::qPropertySet::Get<short>(source_set, property_name, DEPTH_RECURSE);
  if ( v3 )
    UFG::qPropertySet::Set<short>(v4, name, *v3);
}

// File Line: 355
// RVA: 0x1FF780
_BOOL8 __fastcall UFG::fnSortUnPermute(UFG::UnPermute_lookup *a, UFG::UnPermute_lookup *b)
{
  return a->property_value_address < b->property_value_address;
}

// File Line: 361
// RVA: 0x1F33F0
void __fastcall UFG::CopyPropertiesTo(UFG::qPropertySet *target_set, UFG::qPropertySet *source_set)
{
  UFG::qArray<unsigned long,0> *v2; // rax
  unsigned int v3; // eax
  UFG::UnPermute_lookup *property_name; // [rsp+30h] [rbp-88h]
  unsigned int index; // [rsp+38h] [rbp-80h]
  unsigned int i; // [rsp+3Ch] [rbp-7Ch]
  unsigned int newsize; // [rsp+40h] [rbp-78h]
  UFG::qArray<UFG::UnPermute_lookup,0> v8; // [rsp+48h] [rbp-70h]
  unsigned int type_uid; // [rsp+58h] [rbp-60h]
  ePropertyType v10; // [rsp+5Ch] [rbp-5Ch]
  ePropertyType v11; // [rsp+60h] [rbp-58h]
  UFG::qArray<unsigned long,0> *v12; // [rsp+68h] [rbp-50h]
  UFG::qPropertyList *v13; // [rsp+70h] [rbp-48h]
  UFG::qPropertySet *v14; // [rsp+78h] [rbp-40h]
  char *v; // [rsp+80h] [rbp-38h]
  UFG::qPropertySet *v16; // [rsp+88h] [rbp-30h]
  char *v17; // [rsp+90h] [rbp-28h]
  unsigned int v18; // [rsp+98h] [rbp-20h]
  UFG::qPropertyList *v19; // [rsp+A0h] [rbp-18h]
  __int64 v20; // [rsp+A8h] [rbp-10h]
  UFG::qPropertySet *target_seta; // [rsp+C0h] [rbp+8h]
  UFG::qPropertySet *source_seta; // [rsp+C8h] [rbp+10h]

  source_seta = source_set;
  target_seta = target_set;
  v20 = -2i64;
  newsize = UFG::qPropertySet::NumProperties(source_set);
  v8.p = 0i64;
  v8.size = 0;
  v8.capacity = 0;
  if ( newsize > 0 )
    UFG::qArray<UFG::UnPermute_lookup,0>::Reallocate(&v8, newsize, "qArray.Reallocate(Reserve)");
  for ( index = 0; index < newsize; ++index )
  {
    type_uid = UFG::qPropertySet::GetPropertyTypeFromIndex(source_seta, index);
    v2 = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetPropertyNameFromIndex(source_seta, index);
    v12 = v2;
    v3 = UFG::qSymbolUC::as_uint32(v2);
    v17 = (char *)UFG::qPropertySet::GetValuePtr(source_seta, type_uid, v3, DEPTH_RECURSE, 0i64);
    v18 = v8.size;
    UFG::qArray<UFG::UnPermute_lookup,0>::Grow(&v8, 1u, "qArray.Add");
    UFG::qSymbol::qSymbol(&v8.p[index].property_name, (UFG::qSymbol *)v12);
    v8.p[index].property_type = type_uid;
    v8.p[index].property_value_address = v17;
    v8.p[index].property_index_local = index;
  }
  UFG::qSort<UFG::UnPermute_lookup,bool (*)(UFG::UnPermute_lookup const &,UFG::UnPermute_lookup const &)>(
    v8.p,
    v8.size,
    UFG::fnSortUnPermute);
  for ( i = 0; i < newsize; ++i )
  {
    v11 = v8.p[i].property_type;
    property_name = &v8.p[i];
    v10 = v11;
    switch ( v11 )
    {
      case 0:
        UFG::CopyProperty<signed char>(target_seta, source_seta, &property_name->property_name);
        break;
      case 1:
        UFG::CopyProperty<short>(target_seta, source_seta, &property_name->property_name);
        break;
      case 2:
        UFG::CopyProperty<long>(target_seta, source_seta, &property_name->property_name);
        break;
      case 3:
        UFG::CopyProperty<__int64>(target_seta, source_seta, &property_name->property_name);
        break;
      case 5:
        UFG::CopyProperty<unsigned char>(target_seta, source_seta, &property_name->property_name);
        break;
      case 6:
        UFG::CopyProperty<unsigned short>(target_seta, source_seta, &property_name->property_name);
        break;
      case 7:
        UFG::CopyProperty<unsigned long>(target_seta, source_seta, &property_name->property_name);
        break;
      case 8:
        UFG::CopyProperty<unsigned __int64>(target_seta, source_seta, &property_name->property_name);
        break;
      case 9:
        UFG::CopyProperty<bool>(target_seta, source_seta, &property_name->property_name);
        break;
      case 10:
        UFG::CopyProperty<float>(target_seta, source_seta, &property_name->property_name);
        break;
      case 12:
        UFG::PSWrapper::EnableSchemaPropertyChecking(0);
        v = UFG::qPropertySet::Get<char const *>(source_seta, &property_name->property_name, DEPTH_RECURSE);
        UFG::qPropertySet::Set<char const *>(target_seta, &property_name->property_name, v);
        UFG::PSWrapper::EnableSchemaPropertyChecking(1);
        break;
      case 17:
        UFG::CopyProperty<UFG::qVector2>(target_seta, source_seta, &property_name->property_name);
        break;
      case 18:
        UFG::CopyProperty<UFG::qVector3>(target_seta, source_seta, &property_name->property_name);
        break;
      case 19:
        UFG::CopyProperty<UFG::qVector4>(target_seta, source_seta, &property_name->property_name);
        break;
      case 20:
        UFG::CopyProperty<UFG::qMatrix44>(target_seta, source_seta, &property_name->property_name);
        break;
      case 22:
        UFG::CopyProperty<UFG::qSymbol>(target_seta, source_seta, &property_name->property_name);
        break;
      case 23:
        UFG::CopyProperty<UFG::qSymbolUC>(target_seta, source_seta, &property_name->property_name);
        break;
      case 24:
        UFG::CopyProperty<UFG::qWiseSymbol>(target_seta, source_seta, &property_name->property_name);
        break;
      case 25:
        UFG::PSWrapper::EnableSchemaPropertyChecking(0);
        v19 = UFG::qPropertySet::Get<UFG::qPropertyList>(source_seta, &property_name->property_name, DEPTH_RECURSE);
        v13 = (UFG::qPropertyList *)UFG::qPropertyList::Clone(v19);
        UFG::qPropertySet::Set<UFG::qPropertyList>(target_seta, &property_name->property_name, v13);
        UFG::PSWrapper::EnableSchemaPropertyChecking(1);
        break;
      case 26:
        UFG::PSWrapper::EnableSchemaPropertyChecking(0);
        v14 = UFG::qPropertySet::Get<UFG::qPropertySet>(source_seta, &property_name->property_name, DEPTH_RECURSE);
        v16 = UFG::qPropertySet::Clone(v14);
        UFG::qPropertySet::Set<UFG::qPropertySet>(target_seta, &property_name->property_name, v16);
        UFG::PSWrapper::EnableSchemaPropertyChecking(1);
        break;
      case 27:
        UFG::CopyProperty<UFG::qMatrix44>(target_seta, source_seta, &property_name->property_name);
        break;
      case 28:
        UFG::CopyProperty<UFG::qTransQuat>(target_seta, source_seta, &property_name->property_name);
        break;
      default:
        continue;
    }
  }
  UFG::qArray<UFG::UnPermute_lookup,0>::Clear(&v8);
}

// File Line: 457
// RVA: 0x1F54A0
UFG::qPropertySet *__fastcall UFG::FindParentSchemaSetRecurse(UFG::qPropertySet *propertySet, UFG::SchemaDef *schema)
{
  UFG::qPropertySet *v2; // rax
  UFG::qSymbol *v3; // rax
  unsigned int parent_index; // [rsp+20h] [rbp-28h]
  unsigned int v6; // [rsp+24h] [rbp-24h]
  UFG::qPropertySet *propertySeta; // [rsp+28h] [rbp-20h]
  UFG::qPropertySet *v8; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *v9; // [rsp+50h] [rbp+8h]
  UFG::SchemaDef *schemaa; // [rsp+58h] [rbp+10h]

  schemaa = schema;
  v9 = propertySet;
  v6 = UFG::qPropertySet::NumParents(propertySet);
  for ( parent_index = 0; parent_index < v6; ++parent_index )
  {
    v2 = UFG::qPropertySet::GetParentFromIdx(v9, parent_index);
    propertySeta = v2;
    v3 = UFG::qPropertySet::GetSchemaName(v2);
    if ( UFG::qSymbol::operator==(v3, &schemaa->mName) )
      return propertySeta;
    v8 = UFG::FindParentSchemaSetRecurse(propertySeta, schemaa);
    if ( v8 )
      return v8;
  }
  return 0i64;
}

// File Line: 481
// RVA: 0x1FEE20
void __fastcall UFG::SetupSchemaSetRecurse(UFG::SchemaDef *schema_def, UFG::qPropertySet *propertySet)
{
  UFG::qPropertySet *source_set; // ST28_8
  UFG::qPropertySet *v3; // [rsp+20h] [rbp-18h]
  UFG::SchemaDef *schema; // [rsp+40h] [rbp+8h]
  UFG::qPropertySet *propertySeta; // [rsp+48h] [rbp+10h]

  propertySeta = propertySet;
  schema = schema_def;
  if ( schema_def->mpParentSchema )
    UFG::SetupSchemaSetRecurse(schema_def->mpParentSchema, propertySet);
  v3 = UFG::FindParentSchemaSetRecurse(propertySeta, schema);
  if ( v3 )
  {
    UFG::CopyPropertiesTo(propertySeta, v3);
  }
  else
  {
    source_set = (UFG::qPropertySet *)UFG::qPropertySetHandle::Get(&schema->mPropertySet);
    UFG::CopyPropertiesTo(propertySeta, source_set);
  }
}

// File Line: 493
// RVA: 0x1FECB0
void __fastcall UFG::PropertySetManager::SetupSchemaSet(UFG::qPropertySet *propertySet, UFG::qSymbol *schemaName)
{
  char v2; // [rsp+20h] [rbp-78h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v3; // [rsp+28h] [rbp-70h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v4; // [rsp+30h] [rbp-68h]
  UFG::qList<UFG::qPropertySet,UFG::qPropertySet,1,0> *v5; // [rsp+38h] [rbp-60h]
  UFG::SchemaDef *schema_def; // [rsp+40h] [rbp-58h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v7; // [rsp+48h] [rbp-50h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v8; // [rsp+50h] [rbp-48h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v9; // [rsp+58h] [rbp-40h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v10; // [rsp+60h] [rbp-38h]
  __int64 v11; // [rsp+68h] [rbp-30h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v12; // [rsp+70h] [rbp-28h]
  __int64 v13; // [rsp+78h] [rbp-20h]
  __int64 v14; // [rsp+80h] [rbp-18h]
  UFG::qPropertySet *propertySeta; // [rsp+A0h] [rbp+8h]
  UFG::qSymbol *schemaNamea; // [rsp+A8h] [rbp+10h]

  schemaNamea = schemaName;
  propertySeta = propertySet;
  v13 = -2i64;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v2);
  UFG::qPropertySet::RemovePropertiesAllLocal(propertySeta);
  v3 = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&propertySeta->mPrev;
  v8 = propertySeta->mPrev;
  v7 = propertySeta->mNext;
  v8->mNext = v7;
  v7->mPrev = v8;
  v3->mPrev = v3;
  v3->mNext = v3;
  v11 = 16i64;
  v12 = v3 - 1;
  schema_def = UFG::PropertySetManager::GetSchema(schemaNamea);
  UFG::SetupSchemaSetRecurse(schema_def, propertySeta);
  v5 = &schema_def->mPropertySetInstances;
  v14 = 16i64;
  v10 = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&propertySeta->mPrev;
  v4 = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&propertySeta->mPrev;
  v9 = schema_def->mPropertySetInstances.mNode.mPrev;
  v9->mNext = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&propertySeta->mPrev;
  v4->mPrev = v9;
  v4->mNext = &v5->mNode;
  v5->mNode.mPrev = v4;
  UFG::qPropertySet::SetAllPropertiesToDefault(propertySeta);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v2);
}

// File Line: 538
// RVA: 0x1FE600
void __fastcall UFG::PropertySetManager::SetRootPath(const char *rootPath)
{
  UFG::qString::operator=(&UFG::PropertySetManager_Rootpath, rootPath);
}

// File Line: 567
// RVA: 0x1F4110
UFG::qPropertySet *__fastcall UFG::PropertySetManager::CreateContainedPropertySet(UFG::qSymbol *propSetName)
{
  return UFG::qPropertySet::CreateContainedSet(propSetName, "CreatePropertySet");
}

// File Line: 577
// RVA: 0x1F4760
UFG::qPropertySet *__fastcall UFG::PropertySetManager::CreateTopLevelPropertySet(UFG::qSymbol *propSetName)
{
  return UFG::qPropertySet::CreateResourceSet(propSetName, "CreatePropertySet");
}

// File Line: 589
// RVA: 0x1F4680
UFG::qPropertySet *__fastcall UFG::PropertySetManager::CreateOrFindPropertySet(UFG::qSymbol *propSetName)
{
  UFG::qPropertySet *v2; // rax
  UFG::qPropertySetResource *v3; // rax
  UFG::qPropertySet *v4; // [rsp+20h] [rbp-18h]
  UFG::qSymbol *propSetNamea; // [rsp+40h] [rbp+8h]

  propSetNamea = propSetName;
  v4 = UFG::PropertySetCache::GetPropSet(propSetName);
  if ( !v4 )
  {
    v2 = UFG::PropertySetManager::CreateTopLevelPropertySet(propSetNamea);
    v4 = v2;
    v3 = UFG::qPropertySet::GetResource(v2);
    UFG::PropertySetCache::Add(v3);
  }
  return v4;
}

// File Line: 617
// RVA: 0x1FB3D0
UFG::qPropertySet *__fastcall UFG::PropertySetManager::ReloadPropertySet(UFG::qSymbol *propSetName)
{
  char *v1; // rax
  const char *v2; // rax
  UFG::qPropertySet *v3; // ST28_8
  UFG::qPropertySet *pExistingPropSet; // [rsp+20h] [rbp-48h]
  UFG::qString result; // [rsp+38h] [rbp-30h]
  UFG::qSymbol *propSetNamea; // [rsp+70h] [rbp+8h]

  propSetNamea = propSetName;
  pExistingPropSet = UFG::PropertySetCache::GetPropSet(propSetName);
  if ( !pExistingPropSet )
    return UFG::PropertySetManager::CreateTopLevelPropertySet(propSetNamea);
  v1 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)propSetNamea);
  UFG::PropertySetManager::DeterminePathAndFilename(&result, v1, 0i64);
  v2 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&result);
  v3 = UFG::PropertySetManager::LoadFromFile(v2, 1u, pExistingPropSet);
  UFG::qString::~qString(&result);
  return v3;
}

// File Line: 637
// RVA: 0x1F9DF0
UFG::qPropertySet *__fastcall UFG::PropertySetManager::LoadPropertySetFromXML(SimpleXML::XMLDocument *pDocument)
{
  return UFG::PropertySetManager::LoadPropertySetFromXML(pDocument, 0);
}

// File Line: 642
// RVA: 0x1F9E10
UFG::qPropertySet *__fastcall UFG::PropertySetManager::LoadPropertySetFromXML(SimpleXML::XMLDocument *pDocument, bool alwaysReload)
{
  UFG::qSymbol result; // [rsp+20h] [rbp-38h]
  UFG::qPropertySet *existing_set; // [rsp+28h] [rbp-30h]
  SimpleXML::XMLNode *v5; // [rsp+30h] [rbp-28h]
  char *pszSymbolString; // [rsp+38h] [rbp-20h]
  char *name; // [rsp+40h] [rbp-18h]
  __int64 v8; // [rsp+48h] [rbp-10h]
  SimpleXML::XMLDocument *xml_doc; // [rsp+60h] [rbp+8h]
  bool v10; // [rsp+68h] [rbp+10h]

  v10 = alwaysReload;
  xml_doc = pDocument;
  v8 = -2i64;
  existing_set = 0i64;
  if ( pDocument )
  {
    name = "PropertySet";
    v5 = SimpleXML::XMLDocument::GetNode(pDocument, "PropertySet", 0i64);
    if ( v5 )
    {
      pszSymbolString = SimpleXML::XMLNode::GetAttribute(v5, "name");
      if ( pszSymbolString )
      {
        UFG::qSymbol::create_from_string(&result, pszSymbolString);
        existing_set = UFG::PropertySetCache::GetPropSet(&result);
        if ( existing_set && v10 == 1 )
          UFG::qPropertySetResource::LoadSetFromXMLNode(xml_doc, 0i64, existing_set, 1);
        _((AMD_HD3D *)&result);
      }
      if ( !existing_set )
      {
        existing_set = UFG::qPropertySet::CreateResourceSet(&UFG::gNullQSymbol, "TopLevelPropertySet");
        if ( !UFG::qPropertySetResource::LoadSetFromXMLNode(xml_doc, 0i64, existing_set, 1) )
        {
          UFG::qPropertySet::Destroy(existing_set);
          existing_set = 0i64;
        }
      }
    }
  }
  return existing_set;
}

// File Line: 780
// RVA: 0x1F9B40
UFG::qPropertySet *__fastcall UFG::PropertySetManager::LoadFromFile(const char *fullPath, unsigned int propertiesFlags, UFG::qPropertySet *pExistingPropSet)
{
  UFG::qPropertySet *result; // rax
  UFG::qPropertySetResource *v4; // rax
  UFG::qPropertySetResource *v5; // rax
  char v6; // [rsp+20h] [rbp-58h]
  bool v7; // [rsp+21h] [rbp-57h]
  UFG::qPropertySet *propSet; // [rsp+28h] [rbp-50h]
  SimpleXML::XMLDocument *v9; // [rsp+30h] [rbp-48h]
  SimpleXML::XMLDocument *xml_doc; // [rsp+38h] [rbp-40h]
  SimpleXML::XMLDocument *v11; // [rsp+40h] [rbp-38h]
  UFG::qPropertySet *v12; // [rsp+48h] [rbp-30h]
  UFG::qPropertySet *v13; // [rsp+50h] [rbp-28h]
  SimpleXML::XMLDocument *v14; // [rsp+58h] [rbp-20h]
  __int64 v15; // [rsp+60h] [rbp-18h]
  char *filename; // [rsp+80h] [rbp+8h]
  unsigned int v17; // [rsp+88h] [rbp+10h]
  UFG::qPropertySet *v18; // [rsp+90h] [rbp+18h]

  v18 = pExistingPropSet;
  v17 = propertiesFlags;
  filename = (char *)fullPath;
  v15 = -2i64;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v6);
  v7 = UFG::qFileExists(filename);
  if ( v7 )
  {
    propSet = v18;
    if ( v18 && (unsigned __int8)UFG::PropertySetCache::ContainsSet(propSet) )
    {
      v4 = UFG::qPropertySet::GetResource(propSet);
      UFG::PropertySetCache::Remove(v4);
    }
    xml_doc = SimpleXML::XMLDocument::Open(filename, 1ui64, 0i64);
    if ( xml_doc )
    {
      if ( propSet )
      {
        UFG::qPropertySet::RemoveParentsAll(propSet);
        UFG::qPropertySet::RemovePropertiesAllLocal(propSet);
      }
      else
      {
        propSet = UFG::qPropertySet::CreateResourceSet(&UFG::gNullQSymbol, "LoadFromFilePS");
      }
      propSet = UFG::qPropertySetResource::LoadSetFromXMLNode(xml_doc, 0i64, propSet, 1);
      v14 = xml_doc;
      v9 = xml_doc;
      if ( xml_doc )
      {
        SimpleXML::XMLDocument::~XMLDocument(v9);
        Illusion::ShaderParam::operator delete(v9);
        v11 = v9;
      }
      else
      {
        v11 = 0i64;
      }
    }
    if ( propSet )
    {
      if ( v17 & 1 )
      {
        v5 = UFG::qPropertySet::GetResource(propSet);
        UFG::PropertySetCache::Add(v5);
      }
    }
    v13 = propSet;
    UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v6);
    result = v13;
  }
  else
  {
    v12 = 0i64;
    UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v6);
    result = v12;
  }
  return result;
}

// File Line: 839
// RVA: 0x1F5560
UFG::qPropertySet *__fastcall UFG::PropertySetManager::FindPropertySet(UFG::qSymbol *propSetName)
{
  return UFG::PropertySetCache::GetPropSet(propSetName);
}

// File Line: 856
// RVA: 0x1F7B30
UFG::qPropertySet *__fastcall UFG::PropertySetManager::GetPropertySet(UFG::qSymbol *propSetName)
{
  return UFG::PropertySetManager::FindPropertySet(propSetName);
}

// File Line: 880
// RVA: 0x1F51D0
UFG::qString *__fastcall UFG::PropertySetManager::DeterminePathAndFilename(UFG::qString *result, const char *propSetName, const char *alt_root_path)
{
  const char *v3; // rax
  hkResourceContainer *v4; // rax
  const char *v5; // rax
  int lengthb; // ST34_4
  int v7; // eax
  char *format; // [rsp+38h] [rbp-80h]
  char *v10; // [rsp+40h] [rbp-78h]
  char *v11; // [rsp+48h] [rbp-70h]
  UFG::qString v12; // [rsp+58h] [rbp-60h]
  char *text; // [rsp+80h] [rbp-38h]
  char *v14; // [rsp+88h] [rbp-30h]
  int length[2]; // [rsp+90h] [rbp-28h]
  char *textb; // [rsp+98h] [rbp-20h]
  __int64 v17; // [rsp+A0h] [rbp-18h]
  UFG::qString *v18; // [rsp+C0h] [rbp+8h]
  const char *v19; // [rsp+D0h] [rbp+18h]

  v19 = alt_root_path;
  v18 = result;
  v17 = -2i64;
  format = (char *)Assembly::GetRCX((void *)propSetName);
  UFG::qString::qString(&v12, format);
  if ( (unsigned int)UFG::qString::ReplaceString(&v12, "-", "\\", 0) )
  {
    v3 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&v12);
    v14 = UFG::qStringFindLast(v3, "\\");
    v4 = Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&v12);
    *(_QWORD *)length = v14 - (char *)v4;
    v5 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&v12);
    UFG::qString::Set(&v12, v5, length[0], 0i64, 0);
  }
  else
  {
    UFG::qString::operator=(&v12, &customWorldMapCaption);
  }
  if ( v19 )
    v11 = (char *)v19;
  else
    v11 = (char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&UFG::PropertySetManager_Rootpath);
  text = v11;
  lengthb = hkaMatrix<float>::Width((hkaMatrix<float> *)&v12);
  textb = (char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&v12);
  v7 = UFG::qStringLength(text);
  UFG::qString::Set(&v12, text, v7, textb, lengthb);
  UFG::qString::operator+=(&v12, "\\");
  v10 = UFG::qStringFindLast(format, "-");
  if ( v10 )
    UFG::qString::operator+=(&v12, v10 + 1);
  else
    UFG::qString::operator+=(&v12, format);
  UFG::qString::operator+=(&v12, UFG::PropertySetManager_extension_xml);
  UFG::qString::qString(v18, &v12);
  UFG::qString::~qString(&v12);
  return v18;
}

// File Line: 912
// RVA: 0x1F9670
void __fastcall UFG::PropertySetManager::Init(const char *rootDir)
{
  ;
}

// File Line: 916
// RVA: 0x1F7280
UFG::qPropertySet *__fastcall UFG::PropertySetManager::GetParentSchemaSet(UFG::qPropertySet *property_set)
{
  UFG::qSymbol *sym; // ST28_8
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *v4; // [rsp+20h] [rbp-18h]
  UFG::qPropertySet *i; // [rsp+40h] [rbp+8h]

  for ( i = property_set; UFG::qPropertySet::NumParents(i); i = v4 )
  {
    v4 = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(i, 0);
    sym = UFG::qPropertySet::GetName(v4);
    v2 = UFG::qPropertySet::GetSchemaName(v4);
    if ( UFG::qSymbol::operator==(v2, sym) )
      return v4;
  }
  return 0i64;
}

// File Line: 935
// RVA: 0x1F1CA0
UFG::SchemaDef *__fastcall UFG::PropertySetManager::AddSchemaDef(UFG::qPropertySet *property_set, UFG::SchemaDef *parent_schema_def)
{
  __int64 v2; // rax
  UFG::qPropertySet *v3; // rax
  unsigned int v4; // ST34_4
  unsigned int property_index; // [rsp+20h] [rbp-78h]
  unsigned int v7; // [rsp+30h] [rbp-68h]
  __int64 v8; // [rsp+38h] [rbp-60h]
  UFG::qSymbol *name; // [rsp+40h] [rbp-58h]
  UFG::SchemaDef *v10; // [rsp+50h] [rbp-48h]
  int v11; // [rsp+60h] [rbp-38h]
  __int64 v12; // [rsp+68h] [rbp-30h]
  __int64 v13; // [rsp+70h] [rbp-28h]
  UFG::qPropertySet *propertySet; // [rsp+A0h] [rbp+8h]
  UFG::SchemaDef *parentSchema; // [rsp+A8h] [rbp+10h]

  parentSchema = parent_schema_def;
  propertySet = property_set;
  v13 = -2i64;
  v10 = (UFG::SchemaDef *)AMemory::malloc_default(0x108ui64);
  if ( v10 )
  {
    UFG::SchemaDef::SchemaDef(v10, propertySet, parentSchema);
    v8 = v2;
  }
  else
  {
    v8 = 0i64;
  }
  if ( v8 )
    UFG::qBaseTreeRB::Add(&UFG::PropertySetManager_SchemaDefs.mTree, (UFG::qBaseNodeRB *)(v8 + 16));
  else
    UFG::qBaseTreeRB::Add(&UFG::PropertySetManager_SchemaDefs.mTree, 0i64);
  v7 = UFG::qPropertySet::NumProperties(propertySet);
  for ( property_index = 0; property_index < v7; ++property_index )
  {
    if ( !UFG::qPropertySet::PropertyIsDefaultIdx(propertySet, property_index) )
    {
      name = UFG::qPropertySet::GetPropertyNameFromIndex(propertySet, property_index);
      if ( !parentSchema
        || (v3 = UFG::qPropertySetHandle::Get(&parentSchema->mPropertySet),
            !UFG::qPropertySet::PropertyExists(v3, name, DEPTH_RECURSE)) )
      {
        v11 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
        v12 = v8;
        v4 = UFG::PropertySetManager_PropertyLookup.size;
        UFG::qArray<UFG::PropertyLookup,0>::Grow(&UFG::PropertySetManager_PropertyLookup, 1u, "qArray.Add");
        qmemcpy(
          &UFG::PropertySetManager_PropertyLookup.p[v4],
          &v11,
          sizeof(UFG::PropertySetManager_PropertyLookup.p[v4]));
        UFG::PropertySetManager_PropertyLookup_IsSorted = 0;
      }
    }
  }
  return (UFG::SchemaDef *)v8;
}

// File Line: 965
// RVA: 0x1FA250
UFG::qPropertySet *__fastcall UFG::PropertySetManager::NewLoadXML(const char *propSetFilename, bool *found_existing)
{
  UFG::qPropertySet *v3; // [rsp+30h] [rbp-78h]
  UFG::qSymbol result; // [rsp+38h] [rbp-70h]
  SimpleXML::XMLDocument *pDocument; // [rsp+40h] [rbp-68h]
  SimpleXML::XMLDocument *v6; // [rsp+48h] [rbp-60h]
  __int128 text_buffer; // [rsp+50h] [rbp-58h]
  unsigned int sourceCRC; // [rsp+60h] [rbp-48h]
  UFG::qPropertySetResource *pPropResource; // [rsp+68h] [rbp-40h]
  char *pszSymbolString; // [rsp+70h] [rbp-38h]
  SimpleXML::XMLNode *v11; // [rsp+78h] [rbp-30h]
  char *v12; // [rsp+80h] [rbp-28h]
  SimpleXML::XMLDocument *v13; // [rsp+88h] [rbp-20h]
  SimpleXML::XMLDocument *v14; // [rsp+90h] [rbp-18h]
  __int64 v15; // [rsp+98h] [rbp-10h]
  char *filename; // [rsp+B0h] [rbp+8h]
  bool *v17; // [rsp+B8h] [rbp+10h]

  v17 = found_existing;
  filename = (char *)propSetFilename;
  v15 = -2i64;
  UFG::PropertySetManager::PushCurrentlyLoadingFilename(propSetFilename);
  *v17 = 0;
  v3 = 0i64;
  text_buffer = (unsigned __int64)UFG::qReadEntireFile(filename, (__int64 *)&text_buffer + 1, 0i64, 0i64, 0i64);
  if ( (_QWORD)text_buffer )
  {
    pDocument = (SimpleXML::XMLDocument *)SimpleXML::XMLDocument::OpenBuffer(
                                            (const char *)text_buffer,
                                            SDWORD2(text_buffer));
    if ( pDocument )
    {
      sourceCRC = UFG::qDataHash32((const void *)text_buffer, *((unsigned __int64 *)&text_buffer + 1), 0xFFFFFFFF);
      v12 = "PropertySet";
      v11 = SimpleXML::XMLDocument::GetNode(pDocument, "PropertySet", 0i64);
      if ( v11 )
      {
        pszSymbolString = SimpleXML::XMLNode::GetAttribute(v11, "name");
        if ( pszSymbolString )
        {
          UFG::qSymbol::create_from_string(&result, pszSymbolString);
          v3 = UFG::PropertySetCache::GetPropSet(&result);
          if ( v3 )
          {
            *v17 = 1;
          }
          else
          {
            v3 = UFG::PropertySetManager::LoadPropertySetFromXML(pDocument);
            if ( v3 )
            {
              UFG::qPropertySet::AddRef(v3);
              pPropResource = UFG::qPropertySet::GetResource(v3);
              UFG::qPropertySetResource::SetSourceCRC(pPropResource, sourceCRC);
              UFG::PropertySetCache::Add(pPropResource);
            }
          }
          _((AMD_HD3D *)&result);
        }
      }
      v14 = pDocument;
      v6 = pDocument;
      if ( pDocument )
      {
        SimpleXML::XMLDocument::~XMLDocument(v6);
        Illusion::ShaderParam::operator delete(v6);
        v13 = v6;
      }
      else
      {
        v13 = 0i64;
      }
    }
    UFG::qFreeEntireFile((void *)text_buffer, 0i64);
  }
  UFG::PropertySetManager::PopCurrentlyLoadingFilename();
  return v3;
}

// File Line: 1067
// RVA: 0x1F9AF0
_BOOL8 __fastcall UFG::PropertySetManager::IsSupressingAsserts()
{
  return UFG::PropertySetManager_bSupressAsserts;
}

// File Line: 1082
// RVA: 0x1F9AE0
_BOOL8 __fastcall UFG::PropertySetManager::IsSchemaBuildMode()
{
  return UFG::PropertySetManager_bSchemaBuildMode;
}

// File Line: 1087
// RVA: 0x1F1ED0
__int64 __fastcall UFG::PropertySetManager::AppendParentLocal(UFG::qPropertySet *propertySet, UFG::qSymbol *parentName)
{
  const char *parentNameString; // ST20_8
  UFG::qPropertySet *propertySeta; // [rsp+40h] [rbp+8h]

  propertySeta = propertySet;
  parentNameString = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)parentName);
  return UFG::PropertySetManager::AppendParentLocal(propertySeta, parentNameString);
}

// File Line: 1094
// RVA: 0x1F1F10
__int64 __fastcall UFG::PropertySetManager::AppendParentLocal(UFG::qPropertySet *propertySet, const char *parentNameString)
{
  const char *v2; // rax
  UFG::qSymbol *v3; // rax
  char *v5; // rax
  bool found_existing; // [rsp+20h] [rbp-68h]
  unsigned int v7; // [rsp+24h] [rbp-64h]
  UFG::qSymbol result; // [rsp+28h] [rbp-60h]
  UFG::qPropertySet *parentPropSet; // [rsp+30h] [rbp-58h]
  unsigned int v10; // [rsp+38h] [rbp-50h]
  unsigned int v11; // [rsp+3Ch] [rbp-4Ch]
  char *v12; // [rsp+40h] [rbp-48h]
  hkResourceContainer *v13; // [rsp+48h] [rbp-40h]
  __int64 v14; // [rsp+50h] [rbp-38h]
  UFG::qString v15; // [rsp+58h] [rbp-30h]
  UFG::qPropertySet *propSet; // [rsp+90h] [rbp+8h]
  char *pszSymbolString; // [rsp+98h] [rbp+10h]

  pszSymbolString = (char *)parentNameString;
  propSet = propertySet;
  v14 = -2i64;
  UFG::qSymbol::create_from_string(&result, parentNameString);
  parentPropSet = UFG::PropertySetManager::FindPropertySet(&result);
  v7 = -1;
  if ( parentPropSet )
  {
    v7 = UFG::PSWrapper::AppendParentLocal(propSet, parentPropSet);
  }
  else
  {
    UFG::PropertySetManager::DeterminePathAndFilename(&v15, pszSymbolString, 0i64);
    found_existing = 0;
    v2 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&v15);
    parentPropSet = UFG::PropertySetManager::NewLoadXML(v2, &found_existing);
    if ( parentPropSet )
    {
      v7 = UFG::PSWrapper::AppendParentLocal(propSet, parentPropSet);
    }
    else
    {
      if ( UFG::PropertySetManager::IsSchemaBuildMode() )
      {
        v3 = UFG::qPropertySet::GetSchemaName(propSet);
        if ( UFG::qSymbol::is_null(v3) )
        {
          v11 = v7;
          UFG::qString::~qString(&v15);
          _((AMD_HD3D *)&result);
          return v11;
        }
      }
      if ( UFG::PropertySetManager::IsSupressingAsserts() )
      {
        v13 = UFG::PropertySetManager::GetCurrentlyLoadingFilename();
        v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
        v5 = UFG::qPropertySet::GetNameStringDBG(propSet);
        UFG::qPrintf(
          "Error: failed to find parent of property set [%s] named [%s] - %s\n",
          v5,
          v12,
          v13,
          *(_QWORD *)&found_existing);
        ++UFG::PropertySetManager_SupressedAssertCount;
      }
    }
    UFG::qString::~qString(&v15);
  }
  if ( v7 != -1 )
    Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)propSet, 0i64);
  v10 = v7;
  _((AMD_HD3D *)&result);
  return v10;
}

// File Line: 1143
// RVA: 0x1FBD10
void __fastcall UFG::PropertySetManager::RemoveParentLocal(UFG::qPropertySet *propertySet, UFG::qSymbol *parentName)
{
  UFG::qPropertySet *v2; // [rsp+30h] [rbp+8h]

  v2 = propertySet;
  UFG::qPropertySet::RemoveParent(propertySet, parentName);
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v2, 0i64);
}

// File Line: 1150
// RVA: 0x1F7930
UFG::qSymbol *__fastcall UFG::GetPropertyNameForPropertyCollection(UFG::qSymbol *result, UFG::qPropertySet *owner, UFG::qPropertyCollection *collectionToFind)
{
  unsigned int index; // [rsp+24h] [rbp-44h]
  ePropertyType v5; // [rsp+28h] [rbp-40h]
  unsigned int v6; // [rsp+2Ch] [rbp-3Ch]
  UFG::qSymbol *name; // [rsp+30h] [rbp-38h]
  UFG::qSymbol *source; // [rsp+38h] [rbp-30h]
  UFG::qSymbol *v9; // [rsp+70h] [rbp+8h]
  UFG::qPropertySet *v10; // [rsp+78h] [rbp+10h]
  UFG::qPropertySet *v11; // [rsp+80h] [rbp+18h]

  v11 = (UFG::qPropertySet *)collectionToFind;
  v10 = owner;
  v9 = result;
  v6 = UFG::qPropertySet::NumProperties(owner);
  for ( index = 0; index < v6; ++index )
  {
    v5 = UFG::qPropertySet::GetPropertyTypeFromIndex(v10, index);
    if ( UFG::qPropertyCollection::IsPropertySet((UFG::qPropertyCollection *)&v11->mFlags) && v5 == 26 )
    {
      name = UFG::qPropertySet::GetPropertyNameFromIndex(v10, index);
      if ( UFG::qPropertySet::Get<UFG::qPropertySet>(v10, name, DEPTH_RECURSE) == v11 )
      {
        UFG::qSymbol::qSymbol(v9, name);
        return v9;
      }
    }
    else if ( UFG::qPropertyCollection::IsPropertyList((UFG::qPropertyCollection *)&v11->mFlags) && v5 == 25 )
    {
      source = UFG::qPropertySet::GetPropertyNameFromIndex(v10, index);
      if ( UFG::qPropertySet::Get<UFG::qPropertyList>(v10, source, DEPTH_RECURSE) == (UFG::qPropertyList *)v11 )
      {
        UFG::qSymbol::qSymbol(v9, source);
        return v9;
      }
    }
  }
  UFG::qSymbol::qSymbol(v9, &UFG::gNullQSymbol);
  return v9;
}

// File Line: 1184
// RVA: 0x1F77C0
signed __int64 __fastcall UFG::GetPropertyIndexForPropertyCollection(UFG::qPropertyList *owner, UFG::qPropertyCollection *collectionToFind)
{
  unsigned int index; // [rsp+20h] [rbp-28h]
  unsigned int v4; // [rsp+24h] [rbp-24h]
  UFG::qPropertyList *v5; // [rsp+50h] [rbp+8h]
  UFG::qPropertySet *v6; // [rsp+58h] [rbp+10h]

  v6 = (UFG::qPropertySet *)collectionToFind;
  v5 = owner;
  v4 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos((hkMemoryResourceContainer *)owner);
  for ( index = 0; index < v4; ++index )
  {
    if ( UFG::qPropertyCollection::IsPropertySet((UFG::qPropertyCollection *)&v6->mFlags) )
    {
      if ( UFG::qPropertyList::Get<UFG::qPropertySet>(v5, index) == v6 )
        return index;
    }
    else if ( UFG::qPropertyList::Get<UFG::qPropertyList>(v5, index) == (UFG::qPropertyList *)v6 )
    {
      return index;
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 1212
// RVA: 0x1F7EA0
UFG::qPropertySet *__fastcall UFG::PropertySetManager::GetPtrFromPath(UFG::qPropertyPath *path, UFG::qPropertySet *basePropertySet)
{
  UFG::qArray<unsigned long,0> *v2; // rax
  unsigned int i; // [rsp+20h] [rbp-48h]
  UFG::qWiseSymbol result; // [rsp+24h] [rbp-44h]
  UFG::qPropertySet *v6; // [rsp+28h] [rbp-40h]
  unsigned int v7; // [rsp+30h] [rbp-38h]
  unsigned int v8; // [rsp+34h] [rbp-34h]
  unsigned int *v9; // [rsp+38h] [rbp-30h]
  unsigned int *v10; // [rsp+40h] [rbp-28h]
  UFG::qPropertyList *v11; // [rsp+48h] [rbp-20h]
  unsigned int *v12; // [rsp+50h] [rbp-18h]
  __int64 v13; // [rsp+58h] [rbp-10h]
  UFG::qPropertyPath *v14; // [rsp+70h] [rbp+8h]
  UFG::qPropertySet *v15; // [rsp+78h] [rbp+10h]

  v15 = basePropertySet;
  v14 = path;
  v13 = -2i64;
  v6 = 0i64;
  v12 = path->mPath.p;
  v2 = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(basePropertySet);
  if ( (unsigned int)UFG::qSymbolUC::as_uint32(v2) == *v12 )
  {
    v6 = v15;
    for ( i = 1; ; ++i )
    {
      v8 = v14->mPath.size;
      if ( i >= v8 )
        break;
      v9 = &v14->mPath.p[i];
      UFG::qSymbol::qSymbol(&result, *v9);
      v7 = UFG::qPropertySet::GetPropertyTypeFromName(v6, (UFG::qSymbol *)&result, DEPTH_RECURSE);
      if ( v7 == 25 )
      {
        v11 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, (UFG::qSymbol *)&result, DEPTH_RECURSE);
        v10 = &v14->mPath.p[++i];
        v6 = UFG::qPropertyList::Get<UFG::qPropertySet>(v11, *v10);
      }
      else if ( v7 == 26 )
      {
        v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, (UFG::qSymbol *)&result, DEPTH_RECURSE);
      }
      else
      {
        v6 = 0i64;
      }
      _((AMD_HD3D *)&result);
    }
  }
  return v6;
}

// File Line: 1240
// RVA: 0x1F7340
_BOOL8 __fastcall UFG::GetPathCore(UFG::qPropertyPath *path, UFG::qPropertyCollection *propertyCollection, unsigned int extraUID)
{
  UFG::qArray<unsigned long,0> *v3; // rax
  unsigned int newsize; // [rsp+20h] [rbp-E8h]
  UFG::qPropertySet *collectionToFind; // [rsp+28h] [rbp-E0h]
  unsigned int i; // [rsp+30h] [rbp-D8h]
  UFG::qSymbol result; // [rsp+34h] [rbp-D4h]
  UFG::qSymbol v9; // [rsp+3Ch] [rbp-CCh]
  unsigned int v10; // [rsp+40h] [rbp-C8h]
  UFG::qPropertySet *v11; // [rsp+48h] [rbp-C0h]
  unsigned int v12; // [rsp+50h] [rbp-B8h]
  UFG::qPropertyList *v13; // [rsp+58h] [rbp-B0h]
  UFG::qPropertyList *v14; // [rsp+60h] [rbp-A8h]
  UFG::qPropertySet *owner; // [rsp+68h] [rbp-A0h]
  __int64 v16; // [rsp+70h] [rbp-98h]
  int v17[34]; // [rsp+80h] [rbp-88h]
  UFG::qPropertyPath *v18; // [rsp+110h] [rbp+8h]

  v18 = path;
  v16 = -2i64;
  collectionToFind = (UFG::qPropertySet *)propertyCollection;
  newsize = 0;
  if ( extraUID != -1 )
  {
    v17[0] = extraUID;
    newsize = 1;
  }
  while ( collectionToFind )
  {
    if ( UFG::qPropertyCollection::IsPropertySet((UFG::qPropertyCollection *)&collectionToFind->mFlags) )
    {
      owner = UFG::qPropertyCollection::GetOwningSet((UFG::qPropertyCollection *)&collectionToFind->mFlags);
      v14 = UFG::qPropertyCollection::GetOwningList((UFG::qPropertyCollection *)&collectionToFind->mFlags);
      if ( owner )
      {
        UFG::GetPropertyNameForPropertyCollection(&result, owner, (UFG::qPropertyCollection *)&collectionToFind->mFlags);
        v17[newsize++] = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&result);
        collectionToFind = owner;
        _((AMD_HD3D *)&result);
      }
      else
      {
        if ( !v14 )
        {
          v3 = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(collectionToFind);
          v17[newsize++] = UFG::qSymbolUC::as_uint32(v3);
          break;
        }
        v12 = UFG::GetPropertyIndexForPropertyCollection(v14, (UFG::qPropertyCollection *)&collectionToFind->mFlags);
        v17[newsize++] = v12;
        collectionToFind = (UFG::qPropertySet *)v14;
      }
    }
    else
    {
      v11 = UFG::qPropertyCollection::GetOwningSet((UFG::qPropertyCollection *)&collectionToFind->mFlags);
      v13 = UFG::qPropertyCollection::GetOwningList((UFG::qPropertyCollection *)&collectionToFind->mFlags);
      if ( v11 )
      {
        UFG::GetPropertyNameForPropertyCollection(&v9, v11, (UFG::qPropertyCollection *)&collectionToFind->mFlags);
        v17[newsize++] = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&v9);
        collectionToFind = v11;
        _((AMD_HD3D *)&v9);
      }
      else
      {
        if ( !v13 )
          break;
        v10 = UFG::GetPropertyIndexForPropertyCollection(v13, (UFG::qPropertyCollection *)&collectionToFind->mFlags);
        v17[newsize++] = v10;
        collectionToFind = (UFG::qPropertySet *)v13;
      }
    }
  }
  UFG::qPropertyPath::Clear(v18);
  UFG::qArray<unsigned long,0>::Resize(&v18->mPath, newsize, "qArray.Reallocate(Resize)");
  for ( i = 0; i < newsize; ++i )
    v18->mPath.p[newsize - 1 - i] = v17[i];
  return newsize != 0;
}

// File Line: 1315
// RVA: 0x1F7300
bool __fastcall UFG::PropertySetManager::GetPath(UFG::qPropertyPath *path, UFG::qPropertySet *propertySet, UFG::qSymbol *propertyName)
{
  unsigned int v3; // eax
  UFG::qPropertyPath *patha; // [rsp+30h] [rbp+8h]
  UFG::qPropertySet *propertyCollection; // [rsp+38h] [rbp+10h]

  propertyCollection = propertySet;
  patha = path;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)propertyName);
  return UFG::GetPathCore(patha, (UFG::qPropertyCollection *)&propertyCollection->mFlags, v3);
}

// File Line: 1353
// RVA: 0x1FE000
char __fastcall UFG::PropertySetManager::SetModificationCallback(bool (__fastcall *callback)(UFG::qPropertyCollection *, unsigned int))
{
  UFG::PropertySetManager_PropertyModificationCallback = callback;
  return 1;
}

// File Line: 1359
// RVA: 0x1FF530
char __fastcall UFG::UpdateDefaultValuesRecurse(UFG::qPropertySet *component_property_prop_set, UFG::qPropertySet *property_set, UFG::qSymbol *componentPropertyName, UFG::qSymbol *propertyName, unsigned int property_index, const char *source_set_name)
{
  unsigned int parent_index; // [rsp+30h] [rbp-28h]
  unsigned int v8; // [rsp+34h] [rbp-24h]
  UFG::qPropertySet *srcPropSet; // [rsp+38h] [rbp-20h]
  UFG::qPropertySet *property_seta; // [rsp+40h] [rbp-18h]
  UFG::qPropertySet *dstPropSet; // [rsp+60h] [rbp+8h]
  UFG::qPropertySet *v12; // [rsp+68h] [rbp+10h]
  UFG::qSymbol *name; // [rsp+70h] [rbp+18h]
  UFG::qSymbol *propertyNamea; // [rsp+78h] [rbp+20h]

  propertyNamea = propertyName;
  name = componentPropertyName;
  v12 = property_set;
  dstPropSet = component_property_prop_set;
  v8 = UFG::qPropertySet::NumParents(property_set);
  for ( parent_index = 0; parent_index < v8; ++parent_index )
  {
    property_seta = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(v12, parent_index);
    srcPropSet = UFG::qPropertySet::Get<UFG::qPropertySet>(property_seta, name, 0);
    if ( srcPropSet && !UFG::qPropertySet::PropertyIsDefaultByName(srcPropSet, propertyNamea) )
    {
      UFG::PSWrapper::EnableSchemaPropertyChecking(0);
      UFG::PropertySchemaUtils::CopyPropertyValue(srcPropSet, dstPropSet, propertyNamea);
      UFG::PSWrapper::EnableSchemaPropertyChecking(1);
      return 1;
    }
    if ( UFG::UpdateDefaultValuesRecurse(
           dstPropSet,
           property_seta,
           name,
           propertyNamea,
           property_index,
           source_set_name) )
    {
      return 1;
    }
  }
  return 0;
}

// File Line: 1394
// RVA: 0x1FF480
void __fastcall UFG::PropertySetManager::UpdateDefaultValues(UFG::qPropertySet *component_property_prop_set, UFG::qPropertySet *property_set, UFG::qSymbol *componentPropertyName)
{
  UFG::qSymbolUC *v3; // rax
  unsigned int index; // [rsp+30h] [rbp-28h]
  unsigned int v5; // [rsp+34h] [rbp-24h]
  const char *source_set_name; // [rsp+38h] [rbp-20h]
  UFG::qSymbol *propertyName; // [rsp+40h] [rbp-18h]
  UFG::qPropertySet *component_property_prop_seta; // [rsp+60h] [rbp+8h]
  UFG::qPropertySet *property_seta; // [rsp+68h] [rbp+10h]
  UFG::qSymbol *componentPropertyNamea; // [rsp+70h] [rbp+18h]

  componentPropertyNamea = componentPropertyName;
  property_seta = property_set;
  component_property_prop_seta = component_property_prop_set;
  v3 = (UFG::qSymbolUC *)UFG::qPropertySet::GetName(property_set);
  source_set_name = UFG::qSymbol::as_cstr_dbg(v3);
  v5 = UFG::qPropertySet::NumProperties(component_property_prop_seta);
  for ( index = 0; index < v5; ++index )
  {
    propertyName = UFG::qPropertySet::GetPropertyNameFromIndex(component_property_prop_seta, index);
    if ( (unsigned __int8)UFG::qPropertySet::PropertyIsDefaultIdx(component_property_prop_seta, index) )
      UFG::UpdateDefaultValuesRecurse(
        component_property_prop_seta,
        property_seta,
        componentPropertyNamea,
        propertyName,
        index,
        source_set_name);
  }
}

// File Line: 1410
// RVA: 0x1F1760
UFG::qPropertySet *__fastcall UFG::PropertySetManager::AddComponentPropertySet(UFG::qPropertySet *property_set, UFG::SchemaDef *component_schema, UFG::qPropertySet *component_parent_set)
{
  UFG::qSymbol *v3; // rax
  char v5; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *propertySet; // [rsp+28h] [rbp-20h]
  UFG::SchemaDef *i; // [rsp+30h] [rbp-18h]
  __int64 v8; // [rsp+38h] [rbp-10h]
  UFG::qPropertySet *property_seta; // [rsp+50h] [rbp+8h]
  UFG::SchemaDef *v10; // [rsp+58h] [rbp+10h]
  UFG::qPropertySet *parent; // [rsp+60h] [rbp+18h]

  parent = component_parent_set;
  v10 = component_schema;
  property_seta = property_set;
  v8 = -2i64;
  propertySet = UFG::qPropertySet::Get<UFG::qPropertySet>(property_set, &component_schema->mPropertyName, 0);
  if ( !propertySet )
  {
    propertySet = UFG::qPropertySet::CreateContainedSet(&v10->mPropertyName, "child_set");
    UFG::qPropertySet::SetSchemaName(propertySet, &v10->mName);
    UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v5);
    if ( parent )
    {
      UFG::qPropertySet::AddParent(propertySet, parent);
      UFG::qPropertySet::CopyFrom(propertySet, parent, 0);
    }
    else
    {
      v3 = UFG::qPropertySet::GetSchemaName(propertySet);
      UFG::PropertySetManager::SetupSchemaSet(propertySet, v3);
      UFG::PropertySetManager::UpdateDefaultValues(propertySet, property_seta, &v10->mPropertyName);
    }
    UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v5);
    for ( i = v10; i; i = Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::GetFilePtr(i) )
    {
      UFG::qPropertySet::Set<UFG::qPropertySet>(property_seta, &i->mPropertyName, propertySet);
      if ( i != v10 )
        UFG::qPropertySet::SetPropertyDefaultLocal(property_seta, &i->mPropertyName, 1);
    }
    UFG::qPropertySet::SetAllPropertiesToDefault(propertySet);
  }
  return propertySet;
}

// File Line: 1460
// RVA: 0x1FA9C0
void __fastcall UFG::PropertySetManager::PushCurrentlyLoadingFilename(const char *filename)
{
  UFG::qNode<UFG::qString,UFG::qString> *v1; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v2; // ST30_8
  UFG::qNode<UFG::qString,UFG::qString> *v3; // [rsp+38h] [rbp-40h]
  UFG::qString *v4; // [rsp+40h] [rbp-38h]
  char *format; // [rsp+80h] [rbp+8h]

  format = (char *)filename;
  v4 = (UFG::qString *)AMemory::malloc_default(0x28ui64);
  if ( v4 )
  {
    UFG::qString::qString(v4, format);
    v3 = v1;
  }
  else
  {
    v3 = 0i64;
  }
  v2 = UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev;
  UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev->mNext = v3;
  v3->mPrev = v2;
  v3->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::PropertySetManager_CurrentlyLoadingFileStack;
  UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev = v3;
}

// File Line: 1465
// RVA: 0x1FA4F0
void UFG::PropertySetManager::PopCurrentlyLoadingFilename(void)
{
  if ( UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mNext != (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::PropertySetManager_CurrentlyLoadingFileStack )
    UFG::qList<UFG::qString,UFG::qString,1,0>::Remove(
      &UFG::PropertySetManager_CurrentlyLoadingFileStack,
      (UFG::qString *)UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev);
}

// File Line: 1475
// RVA: 0x1F6C80
hkResourceContainer *__fastcall UFG::PropertySetManager::GetCurrentlyLoadingFilename()
{
  hkResourceContainer *result; // rax

  if ( UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mNext == (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::PropertySetManager_CurrentlyLoadingFileStack )
    result = 0i64;
  else
    result = Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev);
  return result;
}

// File Line: 1522
// RVA: 0x146BEF0
__int64 UFG::PropertyMetadataDatabase::_dynamic_initializer_for__mMetadata__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PropertyMetadataDatabase::mMetadata.mTree);
  return atexit(UFG::PropertyMetadataDatabase::_dynamic_atexit_destructor_for__mMetadata__);
}

// File Line: 1523
// RVA: 0x146BF20
__int64 UFG::PropertyMetadataDatabase::_dynamic_initializer_for__mSuggestionCommands__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PropertyMetadataDatabase::mSuggestionCommands.mTree);
  return atexit(UFG::PropertyMetadataDatabase::_dynamic_atexit_destructor_for__mSuggestionCommands__);
}

// File Line: 1536
// RVA: 0x1F6620
UFG::qBaseTreeRB *__fastcall UFG::PropertyMetadataDatabase::Get(UFG::qSymbol *propertyName)
{
  unsigned int uid; // [rsp+20h] [rbp-28h]
  UFG::qBaseTreeRB *v3; // [rsp+28h] [rbp-20h]

  uid = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)propertyName);
  if ( uid )
    v3 = UFG::qBaseTreeRB::Get(&UFG::PropertyMetadataDatabase::mMetadata.mTree, uid);
  else
    v3 = 0i64;
  return v3;
}

// File Line: 1691
// RVA: 0x1EF8B0
UFG::qBaseTreeRB *__fastcall UFG::PropertyMetadataDatabase::Add(UFG::qSymbol *propertyName, const char *entryName, const char *entryValue)
{
  char *v3; // rax
  UFG::qBaseNodeRB *v4; // rax
  UFG::qBaseNodeRB *v5; // rax
  UFG::qBaseTreeRB *x; // [rsp+20h] [rbp-88h]
  unsigned int v8; // [rsp+28h] [rbp-80h]
  unsigned int uid; // [rsp+30h] [rbp-78h]
  UFG::qBaseTreeRB *v10; // [rsp+38h] [rbp-70h]
  UFG::qBaseNodeRB *v11; // [rsp+40h] [rbp-68h]
  UFG::PropertyMetadata::Entry *v12; // [rsp+48h] [rbp-60h]
  UFG::qBaseNodeRB *v13; // [rsp+50h] [rbp-58h]
  UFG::PropertyMetadata *v14; // [rsp+58h] [rbp-50h]
  UFG::qSymbol *v15; // [rsp+B0h] [rbp+8h]
  char *str; // [rsp+B8h] [rbp+10h]
  char *entryValuea; // [rsp+C0h] [rbp+18h]

  entryValuea = (char *)entryValue;
  str = (char *)entryName;
  v15 = propertyName;
  uid = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)propertyName);
  if ( uid )
    x = UFG::qBaseTreeRB::Get(&UFG::PropertyMetadataDatabase::mMetadata.mTree, uid);
  else
    x = 0i64;
  if ( !x )
  {
    v14 = (UFG::PropertyMetadata *)AMemory::malloc_default(0x90ui64);
    if ( v14 )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v15);
      UFG::PropertyMetadata::PropertyMetadata(v14, v3);
      v13 = v4;
    }
    else
    {
      v13 = 0i64;
    }
    x = (UFG::qBaseTreeRB *)v13;
    UFG::qBaseTreeRB::Add(&UFG::PropertyMetadataDatabase::mMetadata.mTree, v13);
  }
  v8 = UFG::qStringHashUpper32(str, 0xFFFFFFFF);
  if ( v8 )
    v10 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)((char *)x + 32), v8);
  else
    v10 = 0i64;
  if ( !v10 )
  {
    v12 = (UFG::PropertyMetadata::Entry *)AMemory::malloc_default(0x70ui64);
    if ( v12 )
    {
      UFG::PropertyMetadata::Entry::Entry(v12, str, entryValuea);
      v11 = v5;
    }
    else
    {
      v11 = 0i64;
    }
    v10 = (UFG::qBaseTreeRB *)v11;
    UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)((char *)x + 32), v11);
  }
  return v10;
}

// File Line: 1730
// RVA: 0x1F9CF0
void __fastcall UFG::PropertyMetadataDatabase::LoadFromPropertyNode(UFG::qSymbol *propertyName, SimpleXML::XMLNode *node)
{
  char *entryName; // ST28_8
  const char *v3; // rax
  unsigned int index; // [rsp+20h] [rbp-78h]
  unsigned int v5; // [rsp+24h] [rbp-74h]
  UFG::qString attribute_name; // [rsp+30h] [rbp-68h]
  __int64 v7; // [rsp+58h] [rbp-40h]
  UFG::qString attribute_value; // [rsp+60h] [rbp-38h]
  UFG::qSymbol *propertyNamea; // [rsp+A0h] [rbp+8h]
  SimpleXML::XMLNode *v10; // [rsp+A8h] [rbp+10h]

  v10 = node;
  propertyNamea = propertyName;
  v7 = -2i64;
  v5 = SimpleXML::XMLNode::GetAttributeCount(node);
  for ( index = 0; index < v5; ++index )
  {
    UFG::qString::qString(&attribute_name);
    UFG::qString::qString(&attribute_value);
    SimpleXML::XMLNode::GetAttribute(v10, index, &attribute_name, &attribute_value);
    if ( !(unsigned int)UFG::qString::IsEmpty(&attribute_name)
      && (char)UFG::qString::operator[](&attribute_name, 0) == 95 )
    {
      entryName = (char *)&Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&attribute_name)->vfptr
                + 1;
      v3 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&attribute_value);
      UFG::PropertyMetadataDatabase::Add(propertyNamea, entryName, v3);
    }
    UFG::qString::~qString(&attribute_value);
    UFG::qString::~qString(&attribute_name);
  }
}

