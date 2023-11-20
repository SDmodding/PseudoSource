// File Line: 58
// RVA: 0x15CCA40
void dynamic_initializer_for__hkpStiffSpringConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpStiffSpringConstraintDataAtomsClass,
    "hkpStiffSpringConstraintDataAtoms",
    0i64,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpStiffSpringConstraintData_AtomsClass_Members,
    3,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 61
// RVA: 0xD43400
hkClass *__fastcall hkpStiffSpringConstraintData::Atoms::staticClass()
{
  return &hkpStiffSpringConstraintDataAtomsClass;
}

// File Line: 68
// RVA: 0xD43420
void __fastcall finishLoadedObjecthkpStiffSpringConstraintDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 74
// RVA: 0xD43430
void __fastcall cleanupLoadedObjecthkpStiffSpringConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 112
// RVA: 0x15CCAB0
void dynamic_initializer_for__hkpStiffSpringConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpStiffSpringConstraintDataClass,
    "hkpStiffSpringConstraintData",
    &hkpConstraintDataClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkpStiffSpringConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 115
// RVA: 0xD43410
hkClass *__fastcall hkpStiffSpringConstraintData::staticClass()
{
  return &hkpStiffSpringConstraintDataClass;
}

// File Line: 122
// RVA: 0xD43440
void __fastcall finishLoadedObjecthkpStiffSpringConstraintData(void *p, int finishing)
{
  _QWORD *v2; // rbx

  if ( p )
  {
    v2 = p;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpStiffSpringConstraintData::`vftable;
  }
}

// File Line: 128
// RVA: 0xD43470
void __fastcall cleanupLoadedObjecthkpStiffSpringConstraintData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 132
// RVA: 0xD43480
void **__fastcall getVtablehkpStiffSpringConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-78h]

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpStiffSpringConstraintData::`vftable;
}

// File Line: 154
// RVA: 0x15CCB20
void **dynamic_initializer_for__hkpStiffSpringConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpStiffSpringConstraintData();
  hkpStiffSpringConstraintDataTypeInfo.m_size = 112i64;
  hkpStiffSpringConstraintDataTypeInfo.m_typeName = "hkpStiffSpringConstraintData";
  hkpStiffSpringConstraintDataTypeInfo.m_vtable = result;
  hkpStiffSpringConstraintDataTypeInfo.m_scopedName = "!hkpStiffSpringConstraintData";
  hkpStiffSpringConstraintDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpStiffSpringConstraintData;
  hkpStiffSpringConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpStiffSpringConstraintData;
  return result;
}

