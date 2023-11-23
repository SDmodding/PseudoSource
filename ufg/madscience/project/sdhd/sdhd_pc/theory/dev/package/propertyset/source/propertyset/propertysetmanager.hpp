// File Line: 193
// RVA: 0x1FD060
void __fastcall UFG::SchemaDef::SetComponentSchema(UFG::SchemaDef *this, bool componentSchema)
{
  this->mbComponentSchema = componentSchema;
}

// File Line: 194
// RVA: 0x1FE620
void __fastcall UFG::SchemaDef::SetSkipParentCheck(UFG::SchemaDef *this, bool skipParentCheck)
{
  this->mbSkipParentCheck = skipParentCheck;
}

// File Line: 195
// RVA: 0x1F7270
UFG::SchemaDef *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::GetFilePtr(
        UFG::SchemaDef *this)
{
  return this->mpParentSchema;
}

// File Line: 221
// RVA: 0x1ECCB0
void __fastcall UFG::PropertyMetadata::PropertyMetadata(UFG::PropertyMetadata *this, const char *propertyName)
{
  unsigned int v4; // eax

  v4 = UFG::qStringHash32(propertyName, 0xFFFFFFFF);
  UFG::qNodeRB<UFG::PropertyMetadata>::qNodeRB<UFG::PropertyMetadata>(this, v4);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mEntries.mTree);
  UFG::qString::qString(&this->mPropertyName, propertyName);
}

// File Line: 231
// RVA: 0x1ECC40
void __fastcall UFG::PropertyMetadata::Entry::Entry(
        UFG::PropertyMetadata::Entry *this,
        const char *entryName,
        const char *entryValue)
{
  unsigned int v6; // eax

  v6 = UFG::qStringHashUpper32(entryName, -1);
  UFG::qNodeRB<UFG::PropertyMetadata>::qNodeRB<UFG::PropertyMetadata>((UFG::qNodeRB<UFG::PropertyMetadata> *)this, v6);
  UFG::qString::qString(&this->mEntryName, entryName);
  UFG::qString::qString(&this->mEntryValue, entryValue);
}

// File Line: 269
// RVA: 0x4CB3C0
schema_classlist *__fastcall UFG::PropertySetManager::GetComponentDataPtr<schema_classlist>(
        UFG::PropertySetManager *this,
        UFG::qPropertySet *propSet)
{
  schema_classlist *result; // rax

  result = (schema_classlist *)UFG::qPropertySet::Get<UFG::qPropertySet>(
                                 (UFG::qPropertySet *)this,
                                 (UFG::qArray<unsigned long,0> *)&schema_classlist::sPropertyName,
                                 DEPTH_RECURSE);
  if ( result )
    return (schema_classlist *)UFG::qPropertySet::GetMemImagePtr((UFG::qPropertySet *)result);
  return result;
}

