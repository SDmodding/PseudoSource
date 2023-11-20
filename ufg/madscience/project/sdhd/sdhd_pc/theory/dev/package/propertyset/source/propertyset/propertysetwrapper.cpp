// File Line: 72
// RVA: 0x1F53F0
void __fastcall UFG::PSWrapper::EnableSchemaPropertyChecking(bool enable)
{
  if ( enable )
    ++UFG::PSWrapper::PSWrapper_EnableSchemaPropertyChecking_RefCount;
  else
    --UFG::PSWrapper::PSWrapper_EnableSchemaPropertyChecking_RefCount;
}

// File Line: 99
// RVA: 0x1F1E70
signed __int64 __fastcall UFG::PSWrapper::AppendParentLocal(UFG::qPropertySet *propSet, UFG::qPropertySet *parentPropSet)
{
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *v4; // [rsp+40h] [rbp+8h]
  UFG::qPropertySet *parent_set; // [rsp+48h] [rbp+10h]

  parent_set = parentPropSet;
  v4 = propSet;
  if ( !UFG::qPropertySet::GetResource(parentPropSet) )
    return UFG::qPropertySet::AddNonResourceBasedParentSet(v4, parent_set);
  v3 = UFG::qPropertySet::GetName(parent_set);
  return UFG::qPropertySet::AddParent(v4, v3);
}

// File Line: 111
// RVA: 0x1F5420
signed __int64 __fastcall UFG::PSWrapper::FindElementPropertySet(UFG::qPropertyList *list, UFG::qSymbol *name)
{
  UFG::qPropertySet *v2; // rax
  UFG::qSymbol *v3; // rax
  unsigned int index; // [rsp+20h] [rbp-18h]
  unsigned int v6; // [rsp+24h] [rbp-14h]
  UFG::qPropertyList *v7; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *sym; // [rsp+48h] [rbp+10h]

  sym = name;
  v7 = list;
  v6 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos((hkMemoryResourceContainer *)list);
  for ( index = 0; index < v6; ++index )
  {
    v2 = UFG::qPropertyList::Get<UFG::qPropertySet>(v7, index);
    v3 = UFG::qPropertySet::GetName(v2);
    if ( UFG::qSymbol::operator==(v3, sym) )
      return index;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 138
// RVA: 0x146BEA0
__int64 UFG::_dynamic_initializer_for__mAllAddedProperties__()
{
  UFG::mAllAddedProperties.mNode.mPrev = (UFG::qNode<UFG::AddedProperty,UFG::_FullList> *)&UFG::mAllAddedProperties;
  UFG::mAllAddedProperties.mNode.mNext = (UFG::qNode<UFG::AddedProperty,UFG::_FullList> *)&UFG::mAllAddedProperties;
  return atexit(UFG::_dynamic_atexit_destructor_for__mAllAddedProperties__);
}

