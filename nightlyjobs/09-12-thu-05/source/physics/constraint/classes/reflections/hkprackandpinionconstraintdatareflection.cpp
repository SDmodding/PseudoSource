// File Line: 69
// RVA: 0x15CDCC0
void dynamic_initializer_for__hkpRackAndPinionConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpRackAndPinionConstraintDataAtomsClass,
    "hkpRackAndPinionConstraintDataAtoms",
    0i64,
    160,
    0i64,
    0,
    0i64,
    0,
    &hkpRackAndPinionConstraintData_AtomsClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 72
// RVA: 0xD441B0
hkClass *__fastcall hkpRackAndPinionConstraintData::Atoms::staticClass()
{
  return &hkpRackAndPinionConstraintDataAtomsClass;
}

// File Line: 79
// RVA: 0xD441D0
void __fastcall finishLoadedObjecthkpRackAndPinionConstraintDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 85
// RVA: 0xD441E0
void __fastcall cleanupLoadedObjecthkpRackAndPinionConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 123
// RVA: 0x15CDD20
void dynamic_initializer_for__hkpRackAndPinionConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpRackAndPinionConstraintDataClass,
    "hkpRackAndPinionConstraintData",
    &hkpConstraintDataClass,
    192,
    0i64,
    0,
    &hkpRackAndPinionConstraintDataEnums,
    1,
    &hkpRackAndPinionConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 126
// RVA: 0xD441C0
hkClass *__fastcall hkpRackAndPinionConstraintData::staticClass()
{
  return &hkpRackAndPinionConstraintDataClass;
}

// File Line: 133
// RVA: 0xD441F0
void __fastcall finishLoadedObjecthkpRackAndPinionConstraintData(void *p, int finishing)
{
  _QWORD *v2; // rbx

  if ( p )
  {
    v2 = p;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpRackAndPinionConstraintData::`vftable';
  }
}

// File Line: 139
// RVA: 0xD44220
void __fastcall cleanupLoadedObjecthkpRackAndPinionConstraintData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 143
// RVA: 0xD44230
void **__fastcall getVtablehkpRackAndPinionConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-C8h]

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpRackAndPinionConstraintData::`vftable';
}

// File Line: 165
// RVA: 0x15CDD90
void **dynamic_initializer_for__hkpRackAndPinionConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpRackAndPinionConstraintData();
  hkpRackAndPinionConstraintDataTypeInfo.m_size = 192i64;
  hkpRackAndPinionConstraintDataTypeInfo.m_typeName = "hkpRackAndPinionConstraintData";
  hkpRackAndPinionConstraintDataTypeInfo.m_vtable = result;
  hkpRackAndPinionConstraintDataTypeInfo.m_scopedName = "!hkpRackAndPinionConstraintData";
  hkpRackAndPinionConstraintDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpRackAndPinionConstraintData;
  hkpRackAndPinionConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpRackAndPinionConstraintData;
  return result;
}

