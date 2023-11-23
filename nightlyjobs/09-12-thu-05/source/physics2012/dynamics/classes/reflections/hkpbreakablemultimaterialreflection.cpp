// File Line: 55
// RVA: 0x15D0520
void dynamic_initializer_for__hkpBreakableMultiMaterialInverseMappingDescriptorClass__()
{
  hkClass::hkClass(
    &hkpBreakableMultiMaterialInverseMappingDescriptorClass,
    "hkpBreakableMultiMaterialInverseMappingDescriptor",
    0i64,
    4,
    0i64,
    0,
    0i64,
    0,
    &hkpBreakableMultiMaterial_InverseMappingDescriptorClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xD4FFA0
hkClass *__fastcall hkpBreakableMultiMaterial::InverseMappingDescriptor::staticClass()
{
  return &hkpBreakableMultiMaterialInverseMappingDescriptorClass;
}

// File Line: 65
// RVA: 0xD4FFC0
void __fastcall cleanupLoadedObjecthkpBreakableMultiMaterialInverseMappingDescriptor(void *p)
{
  ;
}

// File Line: 103
// RVA: 0x15D04B0
void dynamic_initializer_for__hkpBreakableMultiMaterialInverseMappingClass__()
{
  hkClass::hkClass(
    &hkpBreakableMultiMaterialInverseMappingClass,
    "hkpBreakableMultiMaterialInverseMapping",
    &hkReferencedObjectClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpBreakableMultiMaterial_InverseMappingClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 106
// RVA: 0xD4FFB0
hkClass *__fastcall hkpBreakableMultiMaterial::InverseMapping::staticClass()
{
  return &hkpBreakableMultiMaterialInverseMappingClass;
}

// File Line: 113
// RVA: 0xD4FFD0
void __fastcall finishLoadedObjecthkpBreakableMultiMaterialInverseMapping(
        hkpBreakableMultiMaterial::InverseMapping *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpBreakableMultiMaterial::InverseMapping::InverseMapping(p, finishing);
}

// File Line: 119
// RVA: 0xD4FFF0
void __fastcall cleanupLoadedObjecthkpBreakableMultiMaterialInverseMapping(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 123
// RVA: 0xD50000
hkBaseObjectVtbl *__fastcall getVtablehkpBreakableMultiMaterialInverseMapping()
{
  hkpBreakableMultiMaterial::InverseMapping v1; // [rsp+20h] [rbp-38h] BYREF

  hkpBreakableMultiMaterial::InverseMapping::InverseMapping(&v1, 0);
  return v1.vfptr;
}

// File Line: 145
// RVA: 0x15D0580
hkBaseObjectVtbl *dynamic_initializer_for__hkpBreakableMultiMaterialInverseMappingTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpBreakableMultiMaterialInverseMapping();
  hkpBreakableMultiMaterialInverseMappingTypeInfo.m_size = 48i64;
  hkpBreakableMultiMaterialInverseMappingTypeInfo.m_typeName = "hkpBreakableMultiMaterialInverseMapping";
  hkpBreakableMultiMaterialInverseMappingTypeInfo.m_vtable = result;
  hkpBreakableMultiMaterialInverseMappingTypeInfo.m_scopedName = "!hkpBreakableMultiMaterial::InverseMapping";
  hkpBreakableMultiMaterialInverseMappingTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpBreakableMultiMaterialInverseMapping;
  hkpBreakableMultiMaterialInverseMappingTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpBreakableMultiMaterialInverseMapping;
  return result;
}

// File Line: 172
// RVA: 0x15D0440
void dynamic_initializer_for__hkpBreakableMultiMaterialClass__()
{
  hkClass::hkClass(
    &hkpBreakableMultiMaterialClass,
    "hkpBreakableMultiMaterial",
    &hkpBreakableMaterialClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkpBreakableMultiMaterial::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 175
// RVA: 0xD4FF90
hkClass *__fastcall hkpBreakableMultiMaterial::staticClass()
{
  return &hkpBreakableMultiMaterialClass;
}

