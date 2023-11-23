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
__int64 __fastcall UFG::PSWrapper::AppendParentLocal(UFG::qPropertySet *propSet, UFG::qPropertySet *parentPropSet)
{
  UFG::qArray<unsigned long,0> *Name; // rax

  if ( !UFG::qPropertySet::GetResource(parentPropSet) )
    return UFG::qPropertySet::AddNonResourceBasedParentSet(propSet, parentPropSet);
  Name = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(parentPropSet);
  return UFG::qPropertySet::AddParent(propSet, Name);
}

// File Line: 111
// RVA: 0x1F5420
__int64 __fastcall UFG::PSWrapper::FindElementPropertySet(hkMemoryResourceContainer *list, UFG::qSymbol *name)
{
  UFG::qSymbol *v2; // rax
  unsigned int index; // [rsp+20h] [rbp-18h]
  unsigned int StartingPos; // [rsp+24h] [rbp-14h]
  UFG::qPropertySet *v6; // [rsp+28h] [rbp-10h]

  StartingPos = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(list);
  for ( index = 0; index < StartingPos; ++index )
  {
    v6 = UFG::qPropertyList::Get<UFG::qPropertySet>((UFG::qPropertyList *)list, index);
    v2 = UFG::qPropertySet::GetName(v6);
    if ( UFG::qSymbol::operator==(v2, name) )
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
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__mAllAddedProperties__);
}

