// File Line: 47
// RVA: 0x1F8090
UFG::qResourceData *__fastcall UFG::PropertySetCache::GetResource(UFG::qSymbol *propSetName)
{
  unsigned int v1; // eax

  v1 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)propSetName);
  return UFG::qResourceInventory::Get((UFG::qResourceInventory *)&UFG::gPropertySetInventory.vfptr, v1);
}

// File Line: 53
// RVA: 0x1F75F0
UFG::qPropertySet *__fastcall UFG::PropertySetCache::GetPropSet(UFG::qSymbol *propSetName)
{
  UFG::qPropertySet *result; // rax
  UFG::qPropertySetResource *v2; // [rsp+20h] [rbp-18h]

  v2 = (UFG::qPropertySetResource *)UFG::PropertySetCache::GetResource(propSetName);
  if ( v2 )
    result = UFG::qPropertySetResource::GetPropertySet(v2);
  else
    result = 0i64;
  return result;
}

// File Line: 64
// RVA: 0x1F25E0
_BOOL8 __fastcall UFG::PropertySetCache::Contains(UFG::qPropertySetResource *pPropResource)
{
  return UFG::qBaseTreeRB::Contains(&UFG::gPropertySetInventory.mResourceDatas.mTree, &pPropResource->mNode) != 0;
}

// File Line: 69
// RVA: 0x1F2630
_BOOL8 __fastcall UFG::PropertySetCache::ContainsSet(UFG::qPropertySet *propSet)
{
  UFG::qPropertySetResource *v1; // rax

  v1 = UFG::qPropertySet::GetResource(propSet);
  return UFG::PropertySetCache::Contains(v1);
}

// File Line: 74
// RVA: 0x1EFA80
void __fastcall UFG::PropertySetCache::Add(UFG::qPropertySetResource *pPropResource)
{
  UFG::qPropertySetResource *v1; // [rsp+40h] [rbp+8h]

  v1 = pPropResource;
  UFG::qPropertySetResource::GetPropertySet(pPropResource);
  UFG::qPropertySetInventory::Add(&UFG::gPropertySetInventory, (UFG::qResourceData *)&v1->mNode);
}

// File Line: 83
// RVA: 0x1FB580
void __fastcall UFG::PropertySetCache::Remove(UFG::qPropertySetResource *pPropResource)
{
  UFG::qPropertySetInventory::Remove(&UFG::gPropertySetInventory, (UFG::qResourceData *)&pPropResource->mNode);
}

