// File Line: 56
// RVA: 0x15CCB80
void dynamic_initializer_for__hkpPointToPlaneConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpPointToPlaneConstraintDataAtomsClass,
    "hkpPointToPlaneConstraintDataAtoms",
    0i64,
    160,
    0i64,
    0,
    0i64,
    0,
    &hkpPointToPlaneConstraintData_AtomsClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xD434B0
hkClass *__fastcall hkpPointToPlaneConstraintData::Atoms::staticClass()
{
  return &hkpPointToPlaneConstraintDataAtomsClass;
}

// File Line: 66
// RVA: 0xD434D0
void __fastcall finishLoadedObjecthkpPointToPlaneConstraintDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 72
// RVA: 0xD434E0
void __fastcall cleanupLoadedObjecthkpPointToPlaneConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 110
// RVA: 0x15CCBE0
void dynamic_initializer_for__hkpPointToPlaneConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpPointToPlaneConstraintDataClass,
    "hkpPointToPlaneConstraintData",
    &hkpConstraintDataClass,
    192,
    0i64,
    0,
    0i64,
    0,
    &hkpPointToPlaneConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 113
// RVA: 0xD434C0
hkClass *__fastcall hkpPointToPlaneConstraintData::staticClass()
{
  return &hkpPointToPlaneConstraintDataClass;
}

// File Line: 120
// RVA: 0xD434F0
void __fastcall finishLoadedObjecthkpPointToPlaneConstraintData(void *p, int finishing)
{
  _QWORD *v2; // rbx

  if ( p )
  {
    v2 = p;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpPointToPlaneConstraintData::`vftable';
  }
}

// File Line: 126
// RVA: 0xD43520
void __fastcall cleanupLoadedObjecthkpPointToPlaneConstraintData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 130
// RVA: 0xD43530
void **__fastcall getVtablehkpPointToPlaneConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-C8h]

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpPointToPlaneConstraintData::`vftable';
}

// File Line: 152
// RVA: 0x15CCC50
void **dynamic_initializer_for__hkpPointToPlaneConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpPointToPlaneConstraintData();
  hkpPointToPlaneConstraintDataTypeInfo.m_size = 192i64;
  hkpPointToPlaneConstraintDataTypeInfo.m_typeName = "hkpPointToPlaneConstraintData";
  hkpPointToPlaneConstraintDataTypeInfo.m_vtable = result;
  hkpPointToPlaneConstraintDataTypeInfo.m_scopedName = "!hkpPointToPlaneConstraintData";
  hkpPointToPlaneConstraintDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpPointToPlaneConstraintData;
  hkpPointToPlaneConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpPointToPlaneConstraintData;
  return result;
}

