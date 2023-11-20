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
UFG::SchemaDef *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::GetFilePtr(UFG::SchemaDef *this)
{
  return this->mpParentSchema;
}

// File Line: 221
// RVA: 0x1ECCB0
void __fastcall UFG::PropertyMetadata::PropertyMetadata(UFG::PropertyMetadata *this, const char *propertyName)
{
  const char *v2; // rbx
  UFG::PropertyMetadata *v3; // rdi
  unsigned int v4; // eax

  v2 = propertyName;
  v3 = this;
  v4 = UFG::qStringHash32(propertyName, 0xFFFFFFFF);
  UFG::qNodeRB<UFG::PropertyMetadata>::qNodeRB<UFG::PropertyMetadata>(
    (UFG::qNodeRB<UFG::PropertyMetadata> *)&v3->mNode,
    v4);
  UFG::qBaseTreeRB::qBaseTreeRB(&v3->mEntries.mTree);
  UFG::qString::qString(&v3->mPropertyName, v2);
}

// File Line: 231
// RVA: 0x1ECC40
void __fastcall UFG::PropertyMetadata::Entry::Entry(UFG::PropertyMetadata::Entry *this, const char *entryName, const char *entryValue)
{
  const char *v3; // rdi
  const char *v4; // rbx
  UFG::PropertyMetadata::Entry *v5; // rsi
  unsigned int v6; // eax

  v3 = entryValue;
  v4 = entryName;
  v5 = this;
  v6 = UFG::qStringHashUpper32(entryName, 0xFFFFFFFF);
  UFG::qNodeRB<UFG::PropertyMetadata>::qNodeRB<UFG::PropertyMetadata>((UFG::qNodeRB<UFG::PropertyMetadata> *)v5, v6);
  UFG::qString::qString(&v5->mEntryName, v4);
  UFG::qString::qString(&v5->mEntryValue, v3);
}

// File Line: 269
// RVA: 0x4CB3C0
UFG::qPropertySet *__fastcall UFG::PropertySetManager::GetComponentDataPtr<schema_classlist>(UFG::PropertySetManager *this, UFG::qPropertySet *propSet)
{
  UFG::qPropertySet *result; // rax

  result = UFG::qPropertySet::Get<UFG::qPropertySet>(
             (UFG::qPropertySet *)this,
             (UFG::qSymbol *)&schema_classlist::sPropertyName.mUID,
             DEPTH_RECURSE);
  if ( result )
    result = (UFG::qPropertySet *)UFG::qPropertySet::GetMemImagePtr(result);
  return result;
}

