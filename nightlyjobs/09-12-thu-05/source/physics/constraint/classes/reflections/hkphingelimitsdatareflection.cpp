// File Line: 72
// RVA: 0x15CD410
void dynamic_initializer_for__hkpHingeLimitsDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpHingeLimitsDataAtomsClass,
    "hkpHingeLimitsDataAtoms",
    0i64,
    144,
    0i64,
    0,
    &hkpHingeLimitsDataAtomsEnums,
    1,
    &hkpHingeLimitsData_AtomsClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 75
// RVA: 0xD439F0
hkClass *__fastcall hkpHingeLimitsData::Atoms::staticClass()
{
  return &hkpHingeLimitsDataAtomsClass;
}

// File Line: 82
// RVA: 0xD43A10
void __fastcall finishLoadedObjecthkpHingeLimitsDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 88
// RVA: 0xD43A20
void __fastcall cleanupLoadedObjecthkpHingeLimitsDataAtoms(void *p)
{
  ;
}

// File Line: 126
// RVA: 0x15CD480
void dynamic_initializer_for__hkpHingeLimitsDataClass__()
{
  hkClass::hkClass(
    &hkpHingeLimitsDataClass,
    "hkpHingeLimitsData",
    &hkpConstraintDataClass,
    176,
    0i64,
    0,
    0i64,
    0,
    &hkpHingeLimitsDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 129
// RVA: 0xD43A00
hkClass *__fastcall hkpHingeLimitsData::staticClass()
{
  return &hkpHingeLimitsDataClass;
}

// File Line: 136
// RVA: 0xD43A30
void __fastcall finishLoadedObjecthkpHingeLimitsData(void *p, int finishing)
{
  _QWORD *v2; // rbx

  if ( p )
  {
    v2 = p;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpHingeLimitsData::`vftable;
  }
}

// File Line: 142
// RVA: 0xD43A60
void __fastcall cleanupLoadedObjecthkpHingeLimitsData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 146
// RVA: 0xD43A70
void **__fastcall getVtablehkpHingeLimitsData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-B8h]

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpHingeLimitsData::`vftable;
}

// File Line: 168
// RVA: 0x15CD4F0
void **dynamic_initializer_for__hkpHingeLimitsDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpHingeLimitsData();
  hkpHingeLimitsDataTypeInfo.m_size = 176i64;
  hkpHingeLimitsDataTypeInfo.m_typeName = "hkpHingeLimitsData";
  hkpHingeLimitsDataTypeInfo.m_vtable = result;
  hkpHingeLimitsDataTypeInfo.m_scopedName = "!hkpHingeLimitsData";
  hkpHingeLimitsDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpHingeLimitsData;
  hkpHingeLimitsDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpHingeLimitsData;
  return result;
}

