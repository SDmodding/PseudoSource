// File Line: 47
// RVA: 0x1F8090
UFG::qResourceData *__fastcall UFG::PropertySetCache::GetResource(UFG::qArray<unsigned long,0> *propSetName)
{
  unsigned int v1; // eax

  v1 = UFG::qSymbolUC::as_uint32(propSetName);
  return UFG::qResourceInventory::Get(&UFG::gPropertySetInventory, v1);
}

// File Line: 53
// RVA: 0x1F75F0
UFG::qPropertySet *__fastcall UFG::PropertySetCache::GetPropSet(UFG::qSymbol *propSetName)
{
  UFG::qPropertySetResource *Resource; // [rsp+20h] [rbp-18h]

  Resource = (UFG::qPropertySetResource *)UFG::PropertySetCache::GetResource(propSetName);
  if ( Resource )
    return UFG::qPropertySetResource::GetPropertySet(Resource);
  else
    return 0i64;
}

// File Line: 64
// RVA: 0x1F25E0
_BOOL8 __fastcall UFG::PropertySetCache::Contains(UFG::qPropertySetResource *pPropResource)
{
  return UFG::qBaseTreeRB::Contains(&UFG::gPropertySetInventory.mResourceDatas.mTree, &pPropResource->mNode);
}

// File Line: 69
// RVA: 0x1F2630
_BOOL8 __fastcall UFG::PropertySetCache::ContainsSet(UFG::qPropertySet *propSet)
{
  UFG::qPropertySetResource *Resource; // rax

  Resource = UFG::qPropertySet::GetResource(propSet);
  return UFG::PropertySetCache::Contains(Resource);
}

// File Line: 74
// RVA: 0x1EFA80
void __fastcall UFG::PropertySetCache::Add(UFG::qPropertySetResource *pPropResource)
{
  UFG::qPropertySetResource::GetPropertySet(pPropResource);
  UFG::qPropertySetInventory::Add(&UFG::gPropertySetInventory, pPropResource);
}

// File Line: 83
// RVA: 0x1FB580
void __fastcall UFG::PropertySetCache::Remove(UFG::qPropertySetResource *pPropResource)
{
  UFG::qPropertySetInventory::Remove(&UFG::gPropertySetInventory, pPropResource);
}

