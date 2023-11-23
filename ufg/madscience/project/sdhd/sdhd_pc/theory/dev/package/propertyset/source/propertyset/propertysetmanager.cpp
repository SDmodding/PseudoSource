// File Line: 55
// RVA: 0x146BD80
__int64 UFG::_dynamic_initializer_for__PropertySetManager_SchemaComponentPropertyLookup__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PropertySetManager_SchemaComponentPropertyLookup.mTree);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__PropertySetManager_SchemaComponentPropertyLookup__);
}

// File Line: 62
// RVA: 0x1ECE60
void __fastcall UFG::SchemaDef::SchemaDef(
        UFG::SchemaDef *this,
        UFG::qPropertySet *propertySet,
        UFG::SchemaDef *parentSchema)
{
  UFG::qArray<unsigned long,0> *Name; // rax
  UFG::qSymbol *v4; // rax
  const char *NameString; // rax
  const char *UsedSpace; // rax
  const char *v7; // rax
  const char *v8; // rax
  const char *v9; // rax
  UFG::qArray<unsigned long,0> *v10; // rax
  unsigned int v11; // eax
  unsigned int v12; // eax
  UFG::qBaseNodeRB *v13; // [rsp+28h] [rbp-110h]
  AMD_HD3D v14; // [rsp+40h] [rbp-F8h] BYREF
  UFG::qPropertySetResource *Resource; // [rsp+60h] [rbp-D8h]
  UFG::qSymbol *source; // [rsp+68h] [rbp-D0h]
  UFG::qString *v17; // [rsp+70h] [rbp-C8h]
  UFG::qList<UFG::qPropertySet,UFG::qPropertySet,1,0> *p_mPropertySetInstances; // [rsp+78h] [rbp-C0h]
  UFG::qString *v19; // [rsp+80h] [rbp-B8h]
  UFG::qBaseNodeRB *p_mNode; // [rsp+88h] [rbp-B0h]
  UFG::qSymbol *v21; // [rsp+90h] [rbp-A8h]
  UFG::qString *text; // [rsp+98h] [rbp-A0h]
  UFG::qSymbol *v23; // [rsp+A0h] [rbp-98h]
  UFG::qTypedResourceHandle<1415605297,UFG::qPropertySetResource> *p_mPropertySet; // [rsp+A8h] [rbp-90h]
  UFG::qString *v25; // [rsp+B8h] [rbp-80h]
  UFG::qList<UFG::SchemaDef,UFG::SchemaDef,0,0> *p_mDerivedSchemas; // [rsp+C0h] [rbp-78h]
  UFG::qSymbol *v27; // [rsp+C8h] [rbp-70h]
  __int64 v28; // [rsp+D0h] [rbp-68h]
  UFG::qString result; // [rsp+D8h] [rbp-60h] BYREF
  UFG::qString v30; // [rsp+100h] [rbp-38h] BYREF

  v28 = -2i64;
  this->mPrev = this;
  this->mNext = this;
  Name = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(propertySet);
  v14.mWidth = UFG::qSymbolUC::as_uint32(Name);
  p_mNode = &this->mNode;
  UFG::qBaseNodeRB::qBaseNodeRB(&this->mNode, v14.mWidth);
  this->mbComponentSchema = 0;
  this->mbSkipParentCheck = 0;
  BackInfo::BackInfo(&this->mName);
  UFG::qString::qString(&this->mNameString);
  BackInfo::BackInfo(&this->mClassName);
  UFG::qString::qString(&this->mClassNameString);
  BackInfo::BackInfo(&this->mPropertyName);
  UFG::qString::qString(&this->mPropertyNameString);
  p_mPropertySet = &this->mPropertySet;
  UFG::qTypedResourceHandle<1415605297,UFG::qPropertySetResource>::qTypedResourceHandle<1415605297,UFG::qPropertySetResource>(&this->mPropertySet);
  p_mPropertySetInstances = &this->mPropertySetInstances;
  this->mPropertySetInstances.mNode.mPrev = &this->mPropertySetInstances.mNode;
  this->mPropertySetInstances.mNode.mNext = &this->mPropertySetInstances.mNode;
  this->mpParentSchema = parentSchema;
  p_mDerivedSchemas = &this->mDerivedSchemas;
  this->mDerivedSchemas.mNode.mPrev = &this->mDerivedSchemas.mNode;
  this->mDerivedSchemas.mNode.mNext = &this->mDerivedSchemas.mNode;
  Resource = UFG::qPropertySet::GetResource(propertySet);
  v4 = UFG::qPropertySet::GetName(propertySet);
  UFG::qSymbol::qSymbol(&this->mName, v4);
  NameString = UFG::qPropertySetResource::GetNameString(Resource);
  UFG::qString::operator=(&this->mNameString, NameString);
  UsedSpace = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&this->mNameString);
  v25 = UFG::PropertySchemaUtils::classNameFromPropSetName(&result, UsedSpace);
  text = v25;
  UFG::qString::operator=(&this->mPropertyNameString, v25);
  UFG::qString::~qString(&result);
  v7 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&this->mPropertyNameString);
  v27 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v14.mStereo, v7);
  source = v27;
  UFG::qSymbol::qSymbol(&this->mPropertyName, v27);
  _((AMD_HD3D *)&v14.mStereo);
  v8 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&this->mNameString);
  v17 = UFG::PropertySchemaUtils::classNameFromPropSetName(&v30, v8);
  v19 = v17;
  UFG::qString::operator=(&this->mClassNameString, v17);
  UFG::qString::~qString(&v30);
  v9 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&this->mClassNameString);
  v21 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v14, v9);
  v23 = v21;
  UFG::qSymbol::qSymbol(&this->mClassName, v21);
  _(&v14);
  v10 = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(propertySet);
  v11 = UFG::qSymbolUC::as_uint32(v10);
  UFG::qPropertySetHandle::Init(&this->mPropertySet, v11);
  if ( parentSchema )
    UFG::SchemaDef::AddDerivedSchema(parentSchema, this);
  v13 = (UFG::qBaseNodeRB *)AMemory::malloc_default(0x28ui64);
  if ( v13 )
  {
    v12 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&this->mPropertyName);
    UFG::qBaseNodeRB::qBaseNodeRB(v13, v12);
    v13[1].mParent = (UFG::qBaseNodeRB *)this;
    v14.mExtension = (IAmdDxExt *)v13;
  }
  else
  {
    v14.mExtension = 0i64;
  }
  UFG::qBaseTreeRB::Add(
    &UFG::PropertySetManager_SchemaComponentPropertyLookup.mTree,
    (UFG::qBaseNodeRB *)v14.mExtension);
}

// File Line: 84
// RVA: 0x1F18D0
void __fastcall UFG::SchemaDef::AddDerivedSchema(UFG::SchemaDef *this, UFG::SchemaDef *derivedDef)
{
  UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *mPrev; // [rsp+10h] [rbp-28h]

  derivedDef->mpParentSchema = this;
  mPrev = this->mDerivedSchemas.mNode.mPrev;
  mPrev->mNext = derivedDef;
  derivedDef->mPrev = mPrev;
  derivedDef->mNext = &this->mDerivedSchemas.mNode;
  this->mDerivedSchemas.mNode.mPrev = derivedDef;
}

// File Line: 90
// RVA: 0x1F9A00
char __fastcall UFG::SchemaDef::IsDerivedFrom(UFG::SchemaDef *this, UFG::SchemaDef *otherSchema)
{
  while ( this )
  {
    if ( this == otherSchema )
      return 1;
    this = this->mpParentSchema;
  }
  return 0;
}

// File Line: 121
// RVA: 0x146BD50
__int64 UFG::_dynamic_initializer_for__PropertySetManager_Rootpath__()
{
  UFG::qString::qString(&UFG::PropertySetManager_Rootpath, "Data\\PropertySets\\");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__PropertySetManager_Rootpath__);
}

// File Line: 126
// RVA: 0x146BCC0
__int64 UFG::_dynamic_initializer_for__PropertySetManager_CurrentlyLoadingFileStack__()
{
  UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::PropertySetManager_CurrentlyLoadingFileStack;
  UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::PropertySetManager_CurrentlyLoadingFileStack;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__PropertySetManager_CurrentlyLoadingFileStack__);
}

// File Line: 131
// RVA: 0x146BDB0
__int64 UFG::_dynamic_initializer_for__PropertySetManager_SchemaDefs__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PropertySetManager_SchemaDefs.mTree);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__PropertySetManager_SchemaDefs__);
}

// File Line: 132
// RVA: 0x146BD10
__int64 UFG::_dynamic_initializer_for__PropertySetManager_PropertyLookup__()
{
  UFG::PropertySetManager_PropertyLookup.p = 0i64;
  UFG::PropertySetManager_PropertyLookup.size = 0;
  UFG::PropertySetManager_PropertyLookup.capacity = 0;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__PropertySetManager_PropertyLookup__);
}

// File Line: 139
// RVA: 0x1ECD10
void __fastcall UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(
        UFG::PropertyModificationCallbackSupress *this)
{
  ++UFG::PropertySetManager_CallbackSupressionRefCount;
}

// File Line: 144
// RVA: 0x1EE570
void __fastcall UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(
        UFG::PropertyModificationCallbackSupress *this)
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
  UFG::SchemaDef *schema_defa; // [rsp+28h] [rbp-80h]
  unsigned int size; // [rsp+30h] [rbp-78h]

  if ( schema_def->mDerivedSchemas.mNode.mNext == (UFG::qNode<UFG::SchemaDef,UFG::SchemaDef> *)&schema_def->mDerivedSchemas )
  {
    size = derived_schemas->size;
    UFG::qArray<UFG::SchemaDef *,0>::Grow(derived_schemas, 1u, "qArray.Add");
    derived_schemas->p[size] = schema_def;
  }
  for ( schema_defa = (UFG::SchemaDef *)schema_def->mDerivedSchemas.mNode.mNext;
        schema_defa != (UFG::SchemaDef *)&schema_def->mDerivedSchemas;
        schema_defa = (UFG::SchemaDef *)schema_defa->mNext )
  {
    UFG::GetDerivedSchemaList(schema_defa, derived_schemas);
  }
}

// File Line: 168
// RVA: 0x1F5590
UFG::SchemaDef *__fastcall UFG::FindSchema(
        UFG::qPropertySet *propertySet,
        UFG::qArray<UFG::SchemaDef *,0> *derived_schemas)
{
  unsigned int i; // [rsp+20h] [rbp-38h]
  unsigned int parent_index; // [rsp+24h] [rbp-34h]
  unsigned int v5; // [rsp+2Ch] [rbp-2Ch]
  UFG::SchemaDef *v6; // [rsp+30h] [rbp-28h]
  UFG::SchemaDef *Schema; // [rsp+38h] [rbp-20h]
  UFG::qPropertySet *propertySeta; // [rsp+40h] [rbp-18h]

  for ( i = 0; i < derived_schemas->size; ++i )
  {
    v6 = derived_schemas->p[i];
    if ( UFG::qPropertySet::PropertyExists(propertySet, &v6->mPropertyName, DEPTH_LOCAL) )
      return v6;
  }
  v5 = UFG::qPropertySet::NumParents(propertySet);
  for ( parent_index = 0; parent_index < v5; ++parent_index )
  {
    propertySeta = UFG::qPropertySet::GetParentFromIdx(propertySet, parent_index);
    Schema = UFG::FindSchema(propertySeta, derived_schemas);
    if ( Schema )
      return Schema;
  }
  return 0i64;
}

// File Line: 217
// RVA: 0x1F8200
UFG::SchemaDef *__fastcall UFG::PropertySetManager::GetSchemaForProperty(
        UFG::qPropertySet *propertySet,
        UFG::qArray<unsigned long,0> *propertyName)
{
  UFG::qSymbolUC *Name; // rax
  char *v3; // rax
  int v5; // [rsp+30h] [rbp-68h]
  UFG::SchemaDef *schema_def; // [rsp+38h] [rbp-60h]
  unsigned int mPropertyNameUID; // [rsp+40h] [rbp-58h]
  signed int v8; // [rsp+44h] [rbp-54h]
  signed int v9; // [rsp+48h] [rbp-50h]
  UFG::SchemaDef *v10; // [rsp+50h] [rbp-48h]
  UFG::qArray<UFG::SchemaDef *,0> derived_schemas; // [rsp+60h] [rbp-38h] BYREF
  hkResourceContainer *UsedSpace; // [rsp+70h] [rbp-28h]
  hkResourceContainer *CurrentlyLoadingFilename; // [rsp+78h] [rbp-20h]
  char *v14; // [rsp+80h] [rbp-18h]
  __int64 v15; // [rsp+88h] [rbp-10h]

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
    mPropertyNameUID = UFG::PropertySetManager_PropertyLookup.p[v5].mPropertyNameUID;
    if ( (unsigned int)UFG::qSymbolUC::as_uint32(propertyName) <= mPropertyNameUID )
    {
      if ( (unsigned int)UFG::qSymbolUC::as_uint32(propertyName) >= mPropertyNameUID )
      {
        if ( (unsigned int)UFG::qSymbolUC::as_uint32(propertyName) == mPropertyNameUID )
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
    if ( propertySet )
    {
      v10 = schema_def;
      if ( !schema_def->mbSkipParentCheck )
      {
        derived_schemas.p = 0i64;
        derived_schemas.size = 0;
        derived_schemas.capacity = 0;
        UFG::GetDerivedSchemaList(schema_def, &derived_schemas);
        schema_def = UFG::FindSchema(propertySet, &derived_schemas);
        if ( !schema_def && UFG::PropertySetManager::GetCurrentlyLoadingFilename() )
        {
          CurrentlyLoadingFilename = UFG::PropertySetManager::GetCurrentlyLoadingFilename();
          UsedSpace = Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&v10->mNameString);
          v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)propertyName);
          Name = (UFG::qSymbolUC *)UFG::qPropertySet::GetName(propertySet);
          v3 = UFG::qSymbol::as_cstr_dbg(Name);
          UFG::qPrintf(
            "Warning: %s defines property %s without parent %s [%s]\n",
            v3,
            v14,
            (const char *)UsedSpace,
            (const char *)CurrentlyLoadingFilename);
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
UFG::qBaseNodeRB *__fastcall UFG::PropertySetManager::GetSchemaForComponentPropertyName(
        UFG::qArray<unsigned long,0> *componentPropertyName)
{
  unsigned int uid; // [rsp+20h] [rbp-28h]
  UFG::qBaseTreeRB *v3; // [rsp+28h] [rbp-20h]

  uid = UFG::qSymbolUC::as_uint32(componentPropertyName);
  if ( uid )
    v3 = UFG::qBaseTreeRB::Get(&UFG::PropertySetManager_SchemaComponentPropertyLookup.mTree, uid);
  else
    v3 = 0i64;
  if ( v3 )
    return v3->mNULL.mParent;
  else
    return 0i64;
}

// File Line: 308
// RVA: 0x1F99A0
bool __fastcall UFG::PropertySetManager::IsComponentPropertySet(UFG::qPropertySet *property_set)
{
  UFG::qSymbol *SchemaName; // rax
  UFG::qArray<unsigned long,0> *v3; // rax

  if ( !property_set )
    return 0;
  SchemaName = UFG::qPropertySet::GetSchemaName(property_set);
  if ( UFG::qSymbol::operator==(SchemaName, &UFG::gNullQSymbol) )
    return 0;
  v3 = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetSchemaName(property_set);
  return UFG::PropertySetManager::GetSchema(v3)->mbComponentSchema;
}

// File Line: 317
// RVA: 0x1F8110
UFG::SchemaDef *__fastcall UFG::PropertySetManager::GetSchema(UFG::qArray<unsigned long,0> *schemaName)
{
  unsigned int uid; // [rsp+20h] [rbp-38h]
  UFG::qBaseTreeRB *v3; // [rsp+28h] [rbp-30h]

  uid = UFG::qSymbolUC::as_uint32(schemaName);
  if ( !uid )
    return 0i64;
  v3 = UFG::qBaseTreeRB::Get(&UFG::PropertySetManager_SchemaDefs.mTree, uid);
  if ( v3 )
    return (UFG::SchemaDef *)&v3[-1].mNULL.mUID;
  else
    return 0i64;
}

// File Line: 336
// RVA: 0x1E8F50
void __fastcall UFG::CopyProperty<short>(
        UFG::qPropertySet *target_set,
        UFG::qPropertySet *source_set,
        UFG::qSymbol *property_name)
{
  __int16 *v3; // [rsp+20h] [rbp-18h]

  v3 = UFG::qPropertySet::Get<short>(source_set, property_name, DEPTH_RECURSE);
  if ( v3 )
    UFG::qPropertySet::Set<short>(target_set, property_name, *v3);
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
  unsigned int v2; // eax
  UFG::UnPermute_lookup *property_name; // [rsp+30h] [rbp-88h]
  unsigned int index; // [rsp+38h] [rbp-80h]
  unsigned int i; // [rsp+3Ch] [rbp-7Ch]
  unsigned int newsize; // [rsp+40h] [rbp-78h]
  UFG::qArray<UFG::UnPermute_lookup,0> v7; // [rsp+48h] [rbp-70h] BYREF
  unsigned int type_uid; // [rsp+58h] [rbp-60h]
  ePropertyType v9; // [rsp+5Ch] [rbp-5Ch]
  ePropertyType property_type; // [rsp+60h] [rbp-58h]
  UFG::qArray<unsigned long,0> *PropertyNameFromIndex; // [rsp+68h] [rbp-50h]
  UFG::qPropertyList *v12; // [rsp+70h] [rbp-48h]
  UFG::qPropertySet *v13; // [rsp+78h] [rbp-40h]
  char *v; // [rsp+80h] [rbp-38h]
  UFG::qPropertySet *v15; // [rsp+88h] [rbp-30h]
  char *ValuePtr; // [rsp+90h] [rbp-28h]
  unsigned int size; // [rsp+98h] [rbp-20h]
  UFG::qPropertyList *v18; // [rsp+A0h] [rbp-18h]
  __int64 v19; // [rsp+A8h] [rbp-10h]

  v19 = -2i64;
  newsize = UFG::qPropertySet::NumProperties(source_set);
  v7.p = 0i64;
  v7.size = 0;
  v7.capacity = 0;
  if ( newsize )
    UFG::qArray<UFG::UnPermute_lookup,0>::Reallocate(&v7, newsize, "qArray.Reallocate(Reserve)");
  for ( index = 0; index < newsize; ++index )
  {
    type_uid = UFG::qPropertySet::GetPropertyTypeFromIndex(source_set, index);
    PropertyNameFromIndex = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetPropertyNameFromIndex(
                                                              source_set,
                                                              index);
    v2 = UFG::qSymbolUC::as_uint32(PropertyNameFromIndex);
    ValuePtr = (char *)UFG::qPropertySet::GetValuePtr(source_set, type_uid, v2, DEPTH_RECURSE, 0i64);
    size = v7.size;
    UFG::qArray<UFG::UnPermute_lookup,0>::Grow(&v7, 1u, "qArray.Add");
    UFG::qSymbol::qSymbol(&v7.p[index].property_name, (UFG::qSymbol *)PropertyNameFromIndex);
    v7.p[index].property_type = type_uid;
    v7.p[index].property_value_address = ValuePtr;
    v7.p[index].property_index_local = index;
  }
  UFG::qSort<UFG::UnPermute_lookup,bool (*)(UFG::UnPermute_lookup const &,UFG::UnPermute_lookup const &)>(
    v7.p,
    v7.size,
    UFG::fnSortUnPermute);
  for ( i = 0; i < newsize; ++i )
  {
    property_type = v7.p[i].property_type;
    property_name = &v7.p[i];
    v9 = property_type;
    switch ( property_type )
    {
      case UID_int8:
        UFG::CopyProperty<signed char>(target_set, source_set, &property_name->property_name);
        break;
      case UID_int16:
        UFG::CopyProperty<short>(target_set, source_set, &property_name->property_name);
        break;
      case UID_int32:
        UFG::CopyProperty<long>(target_set, source_set, &property_name->property_name);
        break;
      case UID_int64:
        UFG::CopyProperty<__int64>(target_set, source_set, &property_name->property_name);
        break;
      case UID_uint8:
        UFG::CopyProperty<unsigned char>(target_set, source_set, &property_name->property_name);
        break;
      case UID_uint16:
        UFG::CopyProperty<unsigned short>(target_set, source_set, &property_name->property_name);
        break;
      case UID_uint32:
        UFG::CopyProperty<unsigned long>(target_set, source_set, &property_name->property_name);
        break;
      case UID_uint64:
        UFG::CopyProperty<unsigned __int64>(target_set, source_set, &property_name->property_name);
        break;
      case UID_bool:
        UFG::CopyProperty<bool>(target_set, source_set, &property_name->property_name);
        break;
      case UID_float:
        UFG::CopyProperty<float>(target_set, source_set, &property_name->property_name);
        break;
      case UID_string:
        UFG::PSWrapper::EnableSchemaPropertyChecking(0);
        v = UFG::qPropertySet::Get<char const *>(
              source_set,
              (UFG::qArray<unsigned long,0> *)property_name,
              DEPTH_RECURSE);
        UFG::qPropertySet::Set<char const *>(target_set, (UFG::qArray<unsigned long,0> *)property_name, v);
        UFG::PSWrapper::EnableSchemaPropertyChecking(1);
        break;
      case UID_qVector2:
        UFG::CopyProperty<UFG::qVector2>(target_set, source_set, &property_name->property_name);
        break;
      case UID_qVector3:
        UFG::CopyProperty<UFG::qVector3>(target_set, source_set, &property_name->property_name);
        break;
      case UID_qVector4:
        UFG::CopyProperty<UFG::qVector4>(target_set, source_set, &property_name->property_name);
        break;
      case UID_qMatrix44:
      case UID_TransRot:
        UFG::CopyProperty<UFG::qMatrix44>(target_set, source_set, &property_name->property_name);
        break;
      case UID_qSymbol:
        UFG::CopyProperty<UFG::qSymbol>(target_set, source_set, &property_name->property_name);
        break;
      case UID_qSymbolUC:
        UFG::CopyProperty<UFG::qSymbolUC>(target_set, source_set, &property_name->property_name);
        break;
      case UID_qWiseSymbol:
        UFG::CopyProperty<UFG::qWiseSymbol>(target_set, source_set, &property_name->property_name);
        break;
      case UID_list:
        UFG::PSWrapper::EnableSchemaPropertyChecking(0);
        v18 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                source_set,
                (UFG::qArray<unsigned long,0> *)property_name,
                DEPTH_RECURSE);
        v12 = (UFG::qPropertyList *)UFG::qPropertyList::Clone(v18);
        UFG::qPropertySet::Set<UFG::qPropertyList>(target_set, (UFG::qArray<unsigned long,0> *)property_name, v12);
        UFG::PSWrapper::EnableSchemaPropertyChecking(1);
        break;
      case UID_propertyset:
        UFG::PSWrapper::EnableSchemaPropertyChecking(0);
        v13 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                source_set,
                (UFG::qArray<unsigned long,0> *)property_name,
                DEPTH_RECURSE);
        v15 = UFG::qPropertySet::Clone(v13);
        UFG::qPropertySet::Set<UFG::qPropertySet>(target_set, (UFG::qArray<unsigned long,0> *)property_name, v15);
        UFG::PSWrapper::EnableSchemaPropertyChecking(1);
        break;
      case UID_qTransQuat:
        UFG::CopyProperty<UFG::qTransQuat>(target_set, source_set, &property_name->property_name);
        break;
      default:
        continue;
    }
  }
  UFG::qArray<UFG::UnPermute_lookup,0>::Clear(&v7);
}

// File Line: 457
// RVA: 0x1F54A0
UFG::qPropertySet *__fastcall UFG::FindParentSchemaSetRecurse(UFG::qPropertySet *propertySet, UFG::SchemaDef *schema)
{
  UFG::qSymbol *SchemaName; // rax
  unsigned int parent_index; // [rsp+20h] [rbp-28h]
  unsigned int v5; // [rsp+24h] [rbp-24h]
  UFG::qPropertySet *propertySeta; // [rsp+28h] [rbp-20h]
  UFG::qPropertySet *ParentSchemaSetRecurse; // [rsp+30h] [rbp-18h]

  v5 = UFG::qPropertySet::NumParents(propertySet);
  for ( parent_index = 0; parent_index < v5; ++parent_index )
  {
    propertySeta = UFG::qPropertySet::GetParentFromIdx(propertySet, parent_index);
    SchemaName = UFG::qPropertySet::GetSchemaName(propertySeta);
    if ( UFG::qSymbol::operator==(SchemaName, &schema->mName) )
      return propertySeta;
    ParentSchemaSetRecurse = UFG::FindParentSchemaSetRecurse(propertySeta, schema);
    if ( ParentSchemaSetRecurse )
      return ParentSchemaSetRecurse;
  }
  return 0i64;
}

// File Line: 481
// RVA: 0x1FEE20
void __fastcall UFG::SetupSchemaSetRecurse(UFG::SchemaDef *schema_def, UFG::qPropertySet *propertySet)
{
  UFG::qPropertySet *ParentSchemaSetRecurse; // [rsp+20h] [rbp-18h]
  UFG::qPropertySet *source_set; // [rsp+28h] [rbp-10h]

  if ( schema_def->mpParentSchema )
    UFG::SetupSchemaSetRecurse(schema_def->mpParentSchema, propertySet);
  ParentSchemaSetRecurse = UFG::FindParentSchemaSetRecurse(propertySet, schema_def);
  if ( ParentSchemaSetRecurse )
  {
    UFG::CopyPropertiesTo(propertySet, ParentSchemaSetRecurse);
  }
  else
  {
    source_set = (UFG::qPropertySet *)UFG::qPropertySetHandle::Get(&schema_def->mPropertySet);
    UFG::CopyPropertiesTo(propertySet, source_set);
  }
}

// File Line: 493
// RVA: 0x1FECB0
void __fastcall UFG::PropertySetManager::SetupSchemaSet(
        UFG::qPropertySet *propertySet,
        UFG::qArray<unsigned long,0> *schemaName)
{
  UFG::PropertyModificationCallbackSupress v2; // [rsp+20h] [rbp-78h] BYREF
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v3; // [rsp+28h] [rbp-70h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v4; // [rsp+30h] [rbp-68h]
  UFG::qList<UFG::qPropertySet,UFG::qPropertySet,1,0> *p_mPropertySetInstances; // [rsp+38h] [rbp-60h]
  UFG::SchemaDef *schema_def; // [rsp+40h] [rbp-58h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *mNext; // [rsp+48h] [rbp-50h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *mPrev; // [rsp+50h] [rbp-48h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v9; // [rsp+58h] [rbp-40h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v10; // [rsp+60h] [rbp-38h]
  __int64 v11; // [rsp+68h] [rbp-30h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v12; // [rsp+70h] [rbp-28h]
  __int64 v13; // [rsp+78h] [rbp-20h]
  __int64 v14; // [rsp+80h] [rbp-18h]

  v13 = -2i64;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v2);
  UFG::qPropertySet::RemovePropertiesAllLocal(propertySet);
  v3 = &propertySet->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>;
  mPrev = propertySet->mPrev;
  mNext = propertySet->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v11 = 16i64;
  v12 = v3 - 1;
  schema_def = UFG::PropertySetManager::GetSchema(schemaName);
  UFG::SetupSchemaSetRecurse(schema_def, propertySet);
  p_mPropertySetInstances = &schema_def->mPropertySetInstances;
  v14 = 16i64;
  v10 = &propertySet->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>;
  v4 = &propertySet->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>;
  v9 = schema_def->mPropertySetInstances.mNode.mPrev;
  v9->mNext = &propertySet->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>;
  v4->mPrev = v9;
  v4->mNext = &p_mPropertySetInstances->mNode;
  p_mPropertySetInstances->mNode.mPrev = v4;
  UFG::qPropertySet::SetAllPropertiesToDefault(propertySet);
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v2);
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
UFG::qPropertySet *__fastcall UFG::PropertySetManager::CreateTopLevelPropertySet(UFG::qSymbolUC *propSetName)
{
  return UFG::qPropertySet::CreateResourceSet(propSetName, "CreatePropertySet");
}

// File Line: 589
// RVA: 0x1F4680
UFG::qPropertySet *__fastcall UFG::PropertySetManager::CreateOrFindPropertySet(UFG::qSymbol *propSetName)
{
  UFG::qPropertySetResource *Resource; // rax
  UFG::qPropertySet *PropSet; // [rsp+20h] [rbp-18h]

  PropSet = UFG::PropertySetCache::GetPropSet(propSetName);
  if ( !PropSet )
  {
    PropSet = UFG::PropertySetManager::CreateTopLevelPropertySet(propSetName);
    Resource = UFG::qPropertySet::GetResource(PropSet);
    UFG::PropertySetCache::Add(Resource);
  }
  return PropSet;
}

// File Line: 617
// RVA: 0x1FB3D0
UFG::qPropertySet *__fastcall UFG::PropertySetManager::ReloadPropertySet(UFG::qSymbol *propSetName)
{
  char *v1; // rax
  const char *UsedSpace; // rax
  UFG::qPropertySet *pExistingPropSet; // [rsp+20h] [rbp-48h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-40h]
  _BYTE result[48]; // [rsp+38h] [rbp-30h] BYREF

  pExistingPropSet = UFG::PropertySetCache::GetPropSet(propSetName);
  if ( !pExistingPropSet )
    return UFG::PropertySetManager::CreateTopLevelPropertySet((UFG::qSymbolUC *)propSetName);
  v1 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)propSetName);
  UFG::PropertySetManager::DeterminePathAndFilename((UFG::qString *)result, v1, 0i64);
  UsedSpace = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)result);
  v5 = UFG::PropertySetManager::LoadFromFile(UsedSpace, 1, pExistingPropSet);
  UFG::qString::~qString((UFG::qString *)result);
  return v5;
}

// File Line: 637
// RVA: 0x1F9DF0
UFG::qPropertySet *__fastcall UFG::PropertySetManager::LoadPropertySetFromXML(SimpleXML::XMLDocument *pDocument)
{
  return UFG::PropertySetManager::LoadPropertySetFromXML(pDocument, 0);
}

// File Line: 642
// RVA: 0x1F9E10
UFG::qPropertySet *__fastcall UFG::PropertySetManager::LoadPropertySetFromXML(
        SimpleXML::XMLDocument *pDocument,
        bool alwaysReload)
{
  AMD_HD3D result; // [rsp+20h] [rbp-38h] BYREF
  char *name; // [rsp+40h] [rbp-18h]
  __int64 v5; // [rsp+48h] [rbp-10h]

  v5 = -2i64;
  *(_QWORD *)&result.mWidth = 0i64;
  if ( pDocument )
  {
    name = "PropertySet";
    result.mStereo = (IAmdDxExtQuadBufferStereo *)SimpleXML::XMLDocument::GetNode(pDocument, "PropertySet", 0i64);
    if ( result.mStereo )
    {
      result.mExtension = (IAmdDxExt *)SimpleXML::XMLNode::GetAttribute((SimpleXML::XMLNode *)result.mStereo, "name");
      if ( result.mExtension )
      {
        UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, (const char *)result.mExtension);
        *(_QWORD *)&result.mWidth = UFG::PropertySetCache::GetPropSet((UFG::qSymbol *)&result);
        if ( *(_QWORD *)&result.mWidth && alwaysReload )
          UFG::qPropertySetResource::LoadSetFromXMLNode(pDocument, 0i64, *(UFG::qPropertySet **)&result.mWidth, 1);
        _(&result);
      }
      if ( !*(_QWORD *)&result.mWidth )
      {
        *(_QWORD *)&result.mWidth = UFG::qPropertySet::CreateResourceSet(
                                      (UFG::qSymbolUC *)&UFG::gNullQSymbol,
                                      "TopLevelPropertySet");
        if ( !UFG::qPropertySetResource::LoadSetFromXMLNode(pDocument, 0i64, *(UFG::qPropertySet **)&result.mWidth, 1) )
        {
          UFG::qPropertySet::Destroy(*(UFG::qPropertySet **)&result.mWidth);
          *(_QWORD *)&result.mWidth = 0i64;
        }
      }
    }
  }
  return *(UFG::qPropertySet **)&result.mWidth;
}

// File Line: 780
// RVA: 0x1F9B40
UFG::qPropertySet *__fastcall UFG::PropertySetManager::LoadFromFile(
        const char *fullPath,
        char propertiesFlags,
        UFG::qPropertySet *pExistingPropSet)
{
  UFG::qPropertySetResource *Resource; // rax
  UFG::qPropertySetResource *v5; // rax
  UFG::PropertyModificationCallbackSupress v6; // [rsp+20h] [rbp-58h] BYREF
  UFG::qPropertySet *propSet; // [rsp+28h] [rbp-50h]
  SimpleXML::XMLDocument *v9; // [rsp+30h] [rbp-48h]
  SimpleXML::XMLDocument *xml_doc; // [rsp+38h] [rbp-40h]
  SimpleXML::XMLDocument *v11; // [rsp+40h] [rbp-38h]
  __int64 v12; // [rsp+48h] [rbp-30h]
  UFG::qPropertySet *v13; // [rsp+50h] [rbp-28h]
  SimpleXML::XMLDocument *v14; // [rsp+58h] [rbp-20h]
  __int64 v15; // [rsp+60h] [rbp-18h]

  v15 = -2i64;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v6);
  if ( UFG::qFileExists(fullPath) )
  {
    propSet = pExistingPropSet;
    if ( pExistingPropSet && UFG::PropertySetCache::ContainsSet(propSet) )
    {
      Resource = UFG::qPropertySet::GetResource(propSet);
      UFG::PropertySetCache::Remove(Resource);
    }
    xml_doc = SimpleXML::XMLDocument::Open(fullPath, 1ui64, 0i64);
    if ( xml_doc )
    {
      if ( propSet )
      {
        UFG::qPropertySet::RemoveParentsAll(propSet);
        UFG::qPropertySet::RemovePropertiesAllLocal(propSet);
      }
      else
      {
        propSet = UFG::qPropertySet::CreateResourceSet((UFG::qSymbolUC *)&UFG::gNullQSymbol, "LoadFromFilePS");
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
      if ( (propertiesFlags & 1) != 0 )
      {
        v5 = UFG::qPropertySet::GetResource(propSet);
        UFG::PropertySetCache::Add(v5);
      }
    }
    v13 = propSet;
    UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v6);
    return v13;
  }
  else
  {
    v12 = 0i64;
    UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v6);
    return (UFG::qPropertySet *)v12;
  }
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
UFG::qString *__fastcall UFG::PropertySetManager::DeterminePathAndFilename(
        UFG::qString *result,
        char *propSetName,
        hkResourceContainer *alt_root_path)
{
  const char *UsedSpace; // rax
  hkResourceContainer *v4; // rax
  const char *v5; // rax
  int v6; // eax
  int lengthb; // [rsp+34h] [rbp-84h]
  char *format; // [rsp+38h] [rbp-80h]
  char *Last; // [rsp+40h] [rbp-78h]
  hkResourceContainer *v11; // [rsp+48h] [rbp-70h]
  hkMemoryResourceContainer v12; // [rsp+58h] [rbp-60h] BYREF
  char *textb; // [rsp+98h] [rbp-20h]
  __int64 v14; // [rsp+A0h] [rbp-18h]

  v14 = -2i64;
  format = (char *)Assembly::GetRCX(propSetName);
  UFG::qString::qString((UFG::qString *)&v12, format);
  if ( (unsigned int)UFG::qString::ReplaceString((UFG::qString *)&v12, "-", "\\", 0) )
  {
    UsedSpace = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(&v12);
    v12.m_children.m_data = (hkRefPtr<hkMemoryResourceContainer> *)UFG::qStringFindLast(UsedSpace, "\\");
    v4 = Scaleform::SysAllocPagedMalloc::GetUsedSpace(&v12);
    *(_QWORD *)&v12.m_children.m_size = (char *)v12.m_children.m_data - (char *)v4;
    v5 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(&v12);
    UFG::qString::Set((UFG::qString *)&v12, v5, v12.m_children.m_size, 0i64, 0);
  }
  else
  {
    UFG::qString::operator=((UFG::qString *)&v12, &customCaption);
  }
  if ( alt_root_path )
    v11 = alt_root_path;
  else
    v11 = Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&UFG::PropertySetManager_Rootpath);
  *(_QWORD *)&v12.m_resourceHandles.m_size = v11;
  lengthb = hkaMatrix<float>::Width((hkaMatrix<float> *)&v12);
  textb = (char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace(&v12);
  v6 = UFG::qStringLength(*(const char **)&v12.m_resourceHandles.m_size);
  UFG::qString::Set((UFG::qString *)&v12, *(const char **)&v12.m_resourceHandles.m_size, v6, textb, lengthb);
  UFG::qString::operator+=((UFG::qString *)&v12, "\\");
  Last = UFG::qStringFindLast(format, "-");
  if ( Last )
    UFG::qString::operator+=((UFG::qString *)&v12, Last + 1);
  else
    UFG::qString::operator+=((UFG::qString *)&v12, format);
  UFG::qString::operator+=((UFG::qString *)&v12, UFG::PropertySetManager_extension_xml);
  UFG::qString::qString(result, (UFG::qString *)&v12);
  UFG::qString::~qString((UFG::qString *)&v12);
  return result;
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
  UFG::qSymbol *SchemaName; // rax
  UFG::qPropertySet *ParentFromIdx; // [rsp+20h] [rbp-18h]
  UFG::qSymbol *sym; // [rsp+28h] [rbp-10h]

  while ( UFG::qPropertySet::NumParents(property_set) )
  {
    ParentFromIdx = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(property_set, 0);
    sym = UFG::qPropertySet::GetName(ParentFromIdx);
    SchemaName = UFG::qPropertySet::GetSchemaName(ParentFromIdx);
    if ( UFG::qSymbol::operator==(SchemaName, sym) )
      return ParentFromIdx;
    property_set = ParentFromIdx;
  }
  return 0i64;
}

// File Line: 935
// RVA: 0x1F1CA0
UFG::SchemaDef *__fastcall UFG::PropertySetManager::AddSchemaDef(
        UFG::qPropertySet *property_set,
        UFG::SchemaDef *parent_schema_def)
{
  __int64 v2; // rax
  UFG::qPropertySet *v3; // rax
  unsigned int property_index; // [rsp+20h] [rbp-78h]
  unsigned int v6; // [rsp+30h] [rbp-68h]
  unsigned int size; // [rsp+34h] [rbp-64h]
  __int64 v8; // [rsp+38h] [rbp-60h]
  UFG::qSymbol *name; // [rsp+40h] [rbp-58h]
  UFG::SchemaDef *v10; // [rsp+50h] [rbp-48h]
  __int64 v11[7]; // [rsp+60h] [rbp-38h] BYREF

  v11[2] = -2i64;
  v10 = (UFG::SchemaDef *)AMemory::malloc_default(0x108ui64);
  if ( v10 )
  {
    UFG::SchemaDef::SchemaDef(v10, property_set, parent_schema_def);
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
  v6 = UFG::qPropertySet::NumProperties(property_set);
  for ( property_index = 0; property_index < v6; ++property_index )
  {
    if ( !UFG::qPropertySet::PropertyIsDefaultIdx(property_set, property_index) )
    {
      name = UFG::qPropertySet::GetPropertyNameFromIndex(property_set, property_index);
      if ( !parent_schema_def
        || (v3 = UFG::qPropertySetHandle::Get(&parent_schema_def->mPropertySet),
            !UFG::qPropertySet::PropertyExists(v3, name, DEPTH_RECURSE)) )
      {
        LODWORD(v11[0]) = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
        v11[1] = v8;
        size = UFG::PropertySetManager_PropertyLookup.size;
        UFG::qArray<UFG::PropertyLookup,0>::Grow(&UFG::PropertySetManager_PropertyLookup, 1u, "qArray.Add");
        qmemcpy(
          &UFG::PropertySetManager_PropertyLookup.p[size],
          v11,
          sizeof(UFG::PropertySetManager_PropertyLookup.p[size]));
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
  UFG::qPropertySet *PropSet; // [rsp+30h] [rbp-78h]
  UFG::qSymbol result; // [rsp+38h] [rbp-70h] BYREF
  SimpleXML::XMLDocument *pDocument; // [rsp+40h] [rbp-68h]
  SimpleXML::XMLDocument *v6; // [rsp+48h] [rbp-60h]
  __int128 text_buffer; // [rsp+50h] [rbp-58h] BYREF
  unsigned int sourceCRC; // [rsp+60h] [rbp-48h]
  UFG::qPropertySetResource *pPropResource; // [rsp+68h] [rbp-40h]
  char *pszSymbolString; // [rsp+70h] [rbp-38h]
  SimpleXML::XMLNode *Node; // [rsp+78h] [rbp-30h]
  char *v12; // [rsp+80h] [rbp-28h]
  SimpleXML::XMLDocument *v13; // [rsp+88h] [rbp-20h]
  SimpleXML::XMLDocument *v14; // [rsp+90h] [rbp-18h]
  __int64 v15; // [rsp+98h] [rbp-10h]

  v15 = -2i64;
  UFG::PropertySetManager::PushCurrentlyLoadingFilename(propSetFilename);
  *found_existing = 0;
  PropSet = 0i64;
  text_buffer = (unsigned __int64)UFG::qReadEntireFile(propSetFilename, (__int64 *)&text_buffer + 1, 0i64, 0i64, 0i64);
  if ( (_QWORD)text_buffer )
  {
    pDocument = (SimpleXML::XMLDocument *)SimpleXML::XMLDocument::OpenBuffer(
                                            (const char *)text_buffer,
                                            SDWORD2(text_buffer));
    if ( pDocument )
    {
      sourceCRC = UFG::qDataHash32((char *)text_buffer, *((unsigned __int64 *)&text_buffer + 1), 0xFFFFFFFF);
      v12 = "PropertySet";
      Node = SimpleXML::XMLDocument::GetNode(pDocument, "PropertySet", 0i64);
      if ( Node )
      {
        pszSymbolString = SimpleXML::XMLNode::GetAttribute(Node, "name");
        if ( pszSymbolString )
        {
          UFG::qSymbol::create_from_string(&result, pszSymbolString);
          PropSet = UFG::PropertySetCache::GetPropSet(&result);
          if ( PropSet )
          {
            *found_existing = 1;
          }
          else
          {
            PropSet = UFG::PropertySetManager::LoadPropertySetFromXML(pDocument);
            if ( PropSet )
            {
              UFG::qPropertySet::AddRef(PropSet);
              pPropResource = UFG::qPropertySet::GetResource(PropSet);
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
    UFG::qFreeEntireFile((char *)text_buffer, 0i64);
  }
  UFG::PropertySetManager::PopCurrentlyLoadingFilename();
  return PropSet;
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
__int64 __fastcall UFG::PropertySetManager::AppendParentLocal(
        UFG::qPropertySet *propertySet,
        UFG::qSymbolUC *parentName)
{
  const char *parentNameString; // [rsp+20h] [rbp-18h]

  parentNameString = UFG::qSymbol::as_cstr_dbg(parentName);
  return UFG::PropertySetManager::AppendParentLocal(propertySet, parentNameString);
}

// File Line: 1094
// RVA: 0x1F1F10
__int64 __fastcall UFG::PropertySetManager::AppendParentLocal(
        UFG::qPropertySet *propertySet,
        const char *parentNameString)
{
  const char *UsedSpace; // rax
  UFG::qSymbol *SchemaName; // rax
  char *NameStringDBG; // rax
  bool found_existing; // [rsp+20h] [rbp-68h] BYREF
  int appended; // [rsp+24h] [rbp-64h]
  AMD_HD3D result; // [rsp+28h] [rbp-60h] BYREF
  hkResourceContainer *CurrentlyLoadingFilename; // [rsp+48h] [rbp-40h]
  __int64 v10; // [rsp+50h] [rbp-38h]
  _BYTE v11[48]; // [rsp+58h] [rbp-30h] BYREF

  v10 = -2i64;
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, parentNameString);
  *(_QWORD *)&result.mWidth = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&result);
  appended = -1;
  if ( *(_QWORD *)&result.mWidth )
  {
    appended = UFG::PSWrapper::AppendParentLocal(propertySet, *(UFG::qPropertySet **)&result.mWidth);
  }
  else
  {
    UFG::PropertySetManager::DeterminePathAndFilename((UFG::qString *)v11, parentNameString, 0i64);
    found_existing = 0;
    UsedSpace = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)v11);
    *(_QWORD *)&result.mWidth = UFG::PropertySetManager::NewLoadXML(UsedSpace, &found_existing);
    if ( *(_QWORD *)&result.mWidth )
    {
      appended = UFG::PSWrapper::AppendParentLocal(propertySet, *(UFG::qPropertySet **)&result.mWidth);
    }
    else
    {
      if ( UFG::PropertySetManager::IsSchemaBuildMode() )
      {
        SchemaName = UFG::qPropertySet::GetSchemaName(propertySet);
        if ( UFG::qSymbol::is_null(SchemaName) )
        {
          HIDWORD(result.mStereo) = appended;
          UFG::qString::~qString((UFG::qString *)v11);
          _(&result);
          return HIDWORD(result.mStereo);
        }
      }
      if ( UFG::PropertySetManager::IsSupressingAsserts() )
      {
        CurrentlyLoadingFilename = UFG::PropertySetManager::GetCurrentlyLoadingFilename();
        result.mExtension = (IAmdDxExt *)UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
        NameStringDBG = UFG::qPropertySet::GetNameStringDBG(propertySet);
        UFG::qPrintf(
          "Error: failed to find parent of property set [%s] named [%s] - %s\n",
          NameStringDBG,
          (const char *)result.mExtension,
          (const char *)CurrentlyLoadingFilename);
        ++UFG::PropertySetManager_SupressedAssertCount;
      }
    }
    UFG::qString::~qString((UFG::qString *)v11);
  }
  if ( appended != -1 )
    Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
      (hkgpIndexedMesh::EdgeBarrier *)propertySet,
      0i64);
  LODWORD(result.mStereo) = appended;
  _(&result);
  return LODWORD(result.mStereo);
}

// File Line: 1143
// RVA: 0x1FBD10
void __fastcall UFG::PropertySetManager::RemoveParentLocal(
        UFG::qPropertySet *propertySet,
        UFG::qArray<unsigned long,0> *parentName)
{
  UFG::qPropertySet::RemoveParent(propertySet, parentName);
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
    (hkgpIndexedMesh::EdgeBarrier *)propertySet,
    0i64);
}

// File Line: 1150
// RVA: 0x1F7930
UFG::qSymbol *__fastcall UFG::GetPropertyNameForPropertyCollection(
        UFG::qSymbol *result,
        UFG::qPropertySet *owner,
        UFG::qPropertyCollection *collectionToFind)
{
  unsigned int index; // [rsp+24h] [rbp-44h]
  ePropertyType PropertyTypeFromIndex; // [rsp+28h] [rbp-40h]
  unsigned int v6; // [rsp+2Ch] [rbp-3Ch]
  UFG::qSymbol *name; // [rsp+30h] [rbp-38h]
  UFG::qSymbol *source; // [rsp+38h] [rbp-30h]

  v6 = UFG::qPropertySet::NumProperties(owner);
  for ( index = 0; index < v6; ++index )
  {
    PropertyTypeFromIndex = UFG::qPropertySet::GetPropertyTypeFromIndex(owner, index);
    if ( UFG::qPropertyCollection::IsPropertySet(collectionToFind) && PropertyTypeFromIndex == UID_propertyset )
    {
      name = UFG::qPropertySet::GetPropertyNameFromIndex(owner, index);
      if ( UFG::qPropertySet::Get<UFG::qPropertySet>(owner, (UFG::qArray<unsigned long,0> *)name, DEPTH_RECURSE) == collectionToFind )
      {
        UFG::qSymbol::qSymbol(result, name);
        return result;
      }
    }
    else if ( UFG::qPropertyCollection::IsPropertyList(collectionToFind) && PropertyTypeFromIndex == UID_list )
    {
      source = UFG::qPropertySet::GetPropertyNameFromIndex(owner, index);
      if ( UFG::qPropertySet::Get<UFG::qPropertyList>(owner, (UFG::qArray<unsigned long,0> *)source, DEPTH_RECURSE) == collectionToFind )
      {
        UFG::qSymbol::qSymbol(result, source);
        return result;
      }
    }
  }
  UFG::qSymbol::qSymbol(result, &UFG::gNullQSymbol);
  return result;
}

// File Line: 1184
// RVA: 0x1F77C0
__int64 __fastcall UFG::GetPropertyIndexForPropertyCollection(
        hkMemoryResourceContainer *owner,
        UFG::qPropertySet *collectionToFind)
{
  unsigned int index; // [rsp+20h] [rbp-28h]
  unsigned int StartingPos; // [rsp+24h] [rbp-24h]

  StartingPos = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(owner);
  for ( index = 0; index < StartingPos; ++index )
  {
    if ( UFG::qPropertyCollection::IsPropertySet(collectionToFind) )
    {
      if ( UFG::qPropertyList::Get<UFG::qPropertySet>((UFG::qPropertyList *)owner, index) == collectionToFind )
        return index;
    }
    else if ( UFG::qPropertyList::Get<UFG::qPropertyList>((UFG::qPropertyList *)owner, index) == (UFG::qPropertyList *)collectionToFind )
    {
      return index;
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 1212
// RVA: 0x1F7EA0
UFG::qPropertySet *__fastcall UFG::PropertySetManager::GetPtrFromPath(
        UFG::qPropertyPath *path,
        UFG::qPropertySet *basePropertySet)
{
  UFG::qArray<unsigned long,0> *Name; // rax
  unsigned int i; // [rsp+20h] [rbp-48h]
  UFG::qArray<unsigned long,0> result; // [rsp+24h] [rbp-44h] BYREF
  unsigned int size; // [rsp+34h] [rbp-34h]
  unsigned int *v7; // [rsp+38h] [rbp-30h]
  unsigned int *v8; // [rsp+40h] [rbp-28h]
  UFG::qPropertyList *v9; // [rsp+48h] [rbp-20h]
  unsigned int *p; // [rsp+50h] [rbp-18h]
  __int64 v11; // [rsp+58h] [rbp-10h]

  v11 = -2i64;
  *(_QWORD *)&result.capacity = 0i64;
  p = path->mPath.p;
  Name = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(basePropertySet);
  if ( (unsigned int)UFG::qSymbolUC::as_uint32(Name) == *p )
  {
    *(_QWORD *)&result.capacity = basePropertySet;
    for ( i = 1; ; ++i )
    {
      size = path->mPath.size;
      if ( i >= size )
        break;
      v7 = &path->mPath.p[i];
      UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, *v7);
      HIDWORD(result.p) = UFG::qPropertySet::GetPropertyTypeFromName(
                            *(UFG::qPropertySet **)&result.capacity,
                            &result,
                            DEPTH_RECURSE);
      if ( HIDWORD(result.p) == 25 )
      {
        v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(*(UFG::qPropertySet **)&result.capacity, &result, DEPTH_RECURSE);
        v8 = &path->mPath.p[++i];
        *(_QWORD *)&result.capacity = UFG::qPropertyList::Get<UFG::qPropertySet>(v9, *v8);
      }
      else if ( HIDWORD(result.p) == 26 )
      {
        *(_QWORD *)&result.capacity = UFG::qPropertySet::Get<UFG::qPropertySet>(
                                        *(UFG::qPropertySet **)&result.capacity,
                                        &result,
                                        DEPTH_RECURSE);
      }
      else
      {
        *(_QWORD *)&result.capacity = 0i64;
      }
      _((AMD_HD3D *)&result);
    }
  }
  return *(UFG::qPropertySet **)&result.capacity;
}

// File Line: 1240
// RVA: 0x1F7340
_BOOL8 __fastcall UFG::GetPathCore(UFG::qPropertyPath *path, UFG::qPropertySet *propertyCollection, int extraUID)
{
  UFG::qArray<unsigned long,0> *Name; // rax
  unsigned int newsize; // [rsp+20h] [rbp-E8h]
  unsigned int i; // [rsp+30h] [rbp-D8h]
  AMD_HD3D result; // [rsp+34h] [rbp-D4h] BYREF
  UFG::qPropertyList *v9; // [rsp+58h] [rbp-B0h]
  UFG::qPropertyList *OwningList; // [rsp+60h] [rbp-A8h]
  UFG::qPropertySet *owner; // [rsp+68h] [rbp-A0h]
  __int64 v12; // [rsp+70h] [rbp-98h]
  int v13[34]; // [rsp+80h] [rbp-88h]

  v12 = -2i64;
  newsize = 0;
  if ( extraUID != -1 )
  {
    v13[0] = extraUID;
    newsize = 1;
  }
  while ( propertyCollection )
  {
    if ( UFG::qPropertyCollection::IsPropertySet(propertyCollection) )
    {
      owner = UFG::qPropertyCollection::GetOwningSet(propertyCollection);
      OwningList = UFG::qPropertyCollection::GetOwningList(propertyCollection);
      if ( owner )
      {
        UFG::GetPropertyNameForPropertyCollection((UFG::qSymbol *)&result, owner, propertyCollection);
        v13[newsize++] = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&result);
        propertyCollection = owner;
        _(&result);
      }
      else
      {
        if ( !OwningList )
        {
          Name = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(propertyCollection);
          v13[newsize++] = UFG::qSymbolUC::as_uint32(Name);
          break;
        }
        HIDWORD(result.mExtension) = UFG::GetPropertyIndexForPropertyCollection(OwningList, propertyCollection);
        v13[newsize++] = HIDWORD(result.mExtension);
        propertyCollection = (UFG::qPropertySet *)OwningList;
      }
    }
    else
    {
      *(IAmdDxExtQuadBufferStereo **)((char *)&result.mStereo + 4) = (IAmdDxExtQuadBufferStereo *)UFG::qPropertyCollection::GetOwningSet(propertyCollection);
      v9 = UFG::qPropertyCollection::GetOwningList(propertyCollection);
      if ( *(IAmdDxExtQuadBufferStereo **)((char *)&result.mStereo + 4) )
      {
        UFG::GetPropertyNameForPropertyCollection(
          (UFG::qSymbol *)&result.mWidth,
          *(UFG::qPropertySet **)((char *)&result.mStereo + 4),
          propertyCollection);
        v13[newsize++] = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&result.mWidth);
        propertyCollection = *(UFG::qPropertySet **)((char *)&result.mStereo + 4);
        _((AMD_HD3D *)&result.mWidth);
      }
      else
      {
        if ( !v9 )
          break;
        result.mHeight = UFG::GetPropertyIndexForPropertyCollection(v9, propertyCollection);
        v13[newsize++] = result.mHeight;
        propertyCollection = (UFG::qPropertySet *)v9;
      }
    }
  }
  UFG::qPropertyPath::Clear(path);
  UFG::qArray<unsigned long,0>::Resize(&path->mPath, newsize, "qArray.Reallocate(Resize)");
  for ( i = 0; i < newsize; ++i )
    path->mPath.p[newsize - 1 - i] = v13[i];
  return newsize != 0;
}

// File Line: 1315
// RVA: 0x1F7300
bool __fastcall UFG::PropertySetManager::GetPath(
        UFG::qPropertyPath *path,
        UFG::qPropertySet *propertySet,
        UFG::qArray<unsigned long,0> *propertyName)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(propertyName);
  return UFG::GetPathCore(path, propertySet, v3);
}

// File Line: 1353
// RVA: 0x1FE000
char __fastcall UFG::PropertySetManager::SetModificationCallback(
        bool (__fastcall *callback)(UFG::qPropertyCollection *, unsigned int))
{
  UFG::PropertySetManager_PropertyModificationCallback = callback;
  return 1;
}

// File Line: 1359
// RVA: 0x1FF530
char __fastcall UFG::UpdateDefaultValuesRecurse(
        UFG::qPropertySet *component_property_prop_set,
        UFG::qPropertySet *property_set,
        UFG::qArray<unsigned long,0> *componentPropertyName,
        UFG::qArray<unsigned long,0> *propertyName,
        unsigned int property_index,
        const char *source_set_name)
{
  unsigned int parent_index; // [rsp+30h] [rbp-28h]
  unsigned int v8; // [rsp+34h] [rbp-24h]
  UFG::qPropertySet *srcPropSet; // [rsp+38h] [rbp-20h]
  UFG::qPropertySet *property_seta; // [rsp+40h] [rbp-18h]

  v8 = UFG::qPropertySet::NumParents(property_set);
  for ( parent_index = 0; parent_index < v8; ++parent_index )
  {
    property_seta = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(property_set, parent_index);
    srcPropSet = UFG::qPropertySet::Get<UFG::qPropertySet>(property_seta, componentPropertyName, DEPTH_LOCAL);
    if ( srcPropSet && !UFG::qPropertySet::PropertyIsDefaultByName(srcPropSet, propertyName) )
    {
      UFG::PSWrapper::EnableSchemaPropertyChecking(0);
      UFG::PropertySchemaUtils::CopyPropertyValue(srcPropSet, component_property_prop_set, propertyName);
      UFG::PSWrapper::EnableSchemaPropertyChecking(1);
      return 1;
    }
    if ( UFG::UpdateDefaultValuesRecurse(
           component_property_prop_set,
           property_seta,
           (UFG::qSymbol *)componentPropertyName,
           (UFG::qSymbol *)propertyName,
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
void __fastcall UFG::PropertySetManager::UpdateDefaultValues(
        UFG::qPropertySet *component_property_prop_set,
        UFG::qPropertySet *property_set,
        UFG::qSymbol *componentPropertyName)
{
  UFG::qSymbolUC *Name; // rax
  unsigned int index; // [rsp+30h] [rbp-28h]
  unsigned int v5; // [rsp+34h] [rbp-24h]
  const char *source_set_name; // [rsp+38h] [rbp-20h]
  UFG::qSymbol *propertyName; // [rsp+40h] [rbp-18h]

  Name = (UFG::qSymbolUC *)UFG::qPropertySet::GetName(property_set);
  source_set_name = UFG::qSymbol::as_cstr_dbg(Name);
  v5 = UFG::qPropertySet::NumProperties(component_property_prop_set);
  for ( index = 0; index < v5; ++index )
  {
    propertyName = UFG::qPropertySet::GetPropertyNameFromIndex(component_property_prop_set, index);
    if ( UFG::qPropertySet::PropertyIsDefaultIdx(component_property_prop_set, index) )
      UFG::UpdateDefaultValuesRecurse(
        component_property_prop_set,
        property_set,
        componentPropertyName,
        propertyName,
        index,
        source_set_name);
  }
}

// File Line: 1410
// RVA: 0x1F1760
UFG::qPropertySet *__fastcall UFG::PropertySetManager::AddComponentPropertySet(
        UFG::qPropertySet *property_set,
        UFG::SchemaDef *component_schema,
        UFG::qPropertySet *component_parent_set)
{
  UFG::qSymbol *SchemaName; // rax
  UFG::PropertyModificationCallbackSupress v5; // [rsp+20h] [rbp-28h] BYREF
  UFG::qPropertySet *propertySet; // [rsp+28h] [rbp-20h]
  UFG::SchemaDef *i; // [rsp+30h] [rbp-18h]
  __int64 v8; // [rsp+38h] [rbp-10h]

  v8 = -2i64;
  propertySet = UFG::qPropertySet::Get<UFG::qPropertySet>(
                  property_set,
                  (UFG::qArray<unsigned long,0> *)&component_schema->mPropertyName,
                  DEPTH_LOCAL);
  if ( !propertySet )
  {
    propertySet = UFG::qPropertySet::CreateContainedSet(&component_schema->mPropertyName, "child_set");
    UFG::qPropertySet::SetSchemaName(propertySet, &component_schema->mName);
    UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(&v5);
    if ( component_parent_set )
    {
      UFG::qPropertySet::AddParent(propertySet, component_parent_set);
      UFG::qPropertySet::CopyFrom(propertySet, component_parent_set, 0);
    }
    else
    {
      SchemaName = UFG::qPropertySet::GetSchemaName(propertySet);
      UFG::PropertySetManager::SetupSchemaSet(propertySet, SchemaName);
      UFG::PropertySetManager::UpdateDefaultValues(propertySet, property_set, &component_schema->mPropertyName);
    }
    UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(&v5);
    for ( i = component_schema; i; i = Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::GetFilePtr(i) )
    {
      UFG::qPropertySet::Set<UFG::qPropertySet>(
        property_set,
        (UFG::qArray<unsigned long,0> *)&i->mPropertyName,
        propertySet);
      if ( i != component_schema )
        UFG::qPropertySet::SetPropertyDefaultLocal(property_set, &i->mPropertyName, 1);
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
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // [rsp+30h] [rbp-48h]
  UFG::qNode<UFG::qString,UFG::qString> *v3; // [rsp+38h] [rbp-40h]
  UFG::qString *v4; // [rsp+40h] [rbp-38h]

  v4 = (UFG::qString *)AMemory::malloc_default(0x28ui64);
  if ( v4 )
  {
    UFG::qString::qString(v4, filename);
    v3 = v1;
  }
  else
  {
    v3 = 0i64;
  }
  mPrev = UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev;
  UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev->mNext = v3;
  v3->mPrev = mPrev;
  v3->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::PropertySetManager_CurrentlyLoadingFileStack;
  UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev = v3;
}

// File Line: 1465
// RVA: 0x1FA4F0
void UFG::PropertySetManager::PopCurrentlyLoadingFilename(void)
{
  if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mNext != &UFG::PropertySetManager_CurrentlyLoadingFileStack )
    UFG::qList<UFG::qString,UFG::qString,1,0>::Remove(
      &UFG::PropertySetManager_CurrentlyLoadingFileStack,
      (UFG::qString *)UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev);
}

// File Line: 1475
// RVA: 0x1F6C80
hkResourceContainer *__fastcall UFG::PropertySetManager::GetCurrentlyLoadingFilename()
{
  if ( (UFG::qList<UFG::qString,UFG::qString,1,0> *)UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mNext == &UFG::PropertySetManager_CurrentlyLoadingFileStack )
    return 0i64;
  else
    return Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)UFG::PropertySetManager_CurrentlyLoadingFileStack.mNode.mPrev);
}

// File Line: 1522
// RVA: 0x146BEF0
__int64 UFG::PropertyMetadataDatabase::_dynamic_initializer_for__mMetadata__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PropertyMetadataDatabase::mMetadata.mTree);
  return atexit((int (__fastcall *)())UFG::PropertyMetadataDatabase::_dynamic_atexit_destructor_for__mMetadata__);
}

// File Line: 1523
// RVA: 0x146BF20
__int64 UFG::PropertyMetadataDatabase::_dynamic_initializer_for__mSuggestionCommands__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PropertyMetadataDatabase::mSuggestionCommands.mTree);
  return atexit((int (__fastcall *)())UFG::PropertyMetadataDatabase::_dynamic_atexit_destructor_for__mSuggestionCommands__);
}

// File Line: 1536
// RVA: 0x1F6620
UFG::qBaseTreeRB *__fastcall UFG::PropertyMetadataDatabase::Get(UFG::qArray<unsigned long,0> *propertyName)
{
  unsigned int uid; // [rsp+20h] [rbp-28h]

  uid = UFG::qSymbolUC::as_uint32(propertyName);
  if ( uid )
    return UFG::qBaseTreeRB::Get(&UFG::PropertyMetadataDatabase::mMetadata.mTree, uid);
  else
    return 0i64;
}

// File Line: 1691
// RVA: 0x1EF8B0
UFG::qBaseTreeRB *__fastcall UFG::PropertyMetadataDatabase::Add(
        UFG::qArray<unsigned long,0> *propertyName,
        const char *entryName,
        const char *entryValue)
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

  uid = UFG::qSymbolUC::as_uint32(propertyName);
  if ( uid )
    x = UFG::qBaseTreeRB::Get(&UFG::PropertyMetadataDatabase::mMetadata.mTree, uid);
  else
    x = 0i64;
  if ( !x )
  {
    v14 = (UFG::PropertyMetadata *)AMemory::malloc_default(0x90ui64);
    if ( v14 )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)propertyName);
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
  v8 = UFG::qStringHashUpper32(entryName, -1);
  if ( v8 )
    v10 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&x->mNULL, v8);
  else
    v10 = 0i64;
  if ( !v10 )
  {
    v12 = (UFG::PropertyMetadata::Entry *)AMemory::malloc_default(0x70ui64);
    if ( v12 )
    {
      UFG::PropertyMetadata::Entry::Entry(v12, entryName, entryValue);
      v11 = v5;
    }
    else
    {
      v11 = 0i64;
    }
    v10 = (UFG::qBaseTreeRB *)v11;
    UFG::qBaseTreeRB::Add((UFG::qBaseTreeRB *)&x->mNULL, v11);
  }
  return v10;
}

// File Line: 1730
// RVA: 0x1F9CF0
void __fastcall UFG::PropertyMetadataDatabase::LoadFromPropertyNode(
        UFG::qArray<unsigned long,0> *propertyName,
        SimpleXML::XMLNode *node)
{
  const char *UsedSpace; // rax
  unsigned int index; // [rsp+20h] [rbp-78h]
  unsigned int AttributeCount; // [rsp+24h] [rbp-74h]
  char *entryName; // [rsp+28h] [rbp-70h]
  hkMemoryResourceContainer attribute_name; // [rsp+30h] [rbp-68h] BYREF

  *(_QWORD *)&attribute_name.m_resourceHandles.m_size = -2i64;
  AttributeCount = SimpleXML::XMLNode::GetAttributeCount(node);
  for ( index = 0; index < AttributeCount; ++index )
  {
    UFG::qString::qString((UFG::qString *)&attribute_name);
    UFG::qString::qString((UFG::qString *)&attribute_name.m_children);
    SimpleXML::XMLNode::GetAttribute(
      node,
      index,
      (UFG::qString *)&attribute_name,
      (UFG::qString *)&attribute_name.m_children);
    if ( !UFG::qString::IsEmpty((UFG::qString *)&attribute_name)
      && (char)UFG::qString::operator[]((UFG::qString *)&attribute_name, 0) == 95 )
    {
      entryName = (char *)&Scaleform::SysAllocPagedMalloc::GetUsedSpace(&attribute_name)->vfptr + 1;
      UsedSpace = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&attribute_name.m_children);
      UFG::PropertyMetadataDatabase::Add(propertyName, entryName, UsedSpace);
    }
    UFG::qString::~qString((UFG::qString *)&attribute_name.m_children);
    UFG::qString::~qString((UFG::qString *)&attribute_name);
  }
}

