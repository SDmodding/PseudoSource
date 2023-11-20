// File Line: 60
// RVA: 0x15CD1A0
void dynamic_initializer_for__hkpFixedConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpFixedConstraintDataAtomsClass,
    "hkpFixedConstraintDataAtoms",
    0i64,
    192,
    0i64,
    0,
    0i64,
    0,
    &hkpFixedConstraintData_AtomsClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 63
// RVA: 0xD43890
hkClass *__fastcall hkpFixedConstraintData::Atoms::staticClass()
{
  return &hkpFixedConstraintDataAtomsClass;
}

// File Line: 70
// RVA: 0xD438B0
void __fastcall finishLoadedObjecthkpFixedConstraintDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 76
// RVA: 0xD438C0
void __fastcall cleanupLoadedObjecthkpFixedConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 114
// RVA: 0x15CD200
void dynamic_initializer_for__hkpFixedConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpFixedConstraintDataClass,
    "hkpFixedConstraintData",
    &hkpConstraintDataClass,
    224,
    0i64,
    0,
    0i64,
    0,
    &hkpFixedConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 117
// RVA: 0xD438A0
hkClass *__fastcall hkpFixedConstraintData::staticClass()
{
  return &hkpFixedConstraintDataClass;
}

// File Line: 124
// RVA: 0xD438D0
void __fastcall finishLoadedObjecthkpFixedConstraintData(void *p, int finishing)
{
  _QWORD *v2; // rbx

  if ( p )
  {
    v2 = p;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpFixedConstraintData::`vftable';
  }
}

// File Line: 130
// RVA: 0xD43900
void __fastcall cleanupLoadedObjecthkpFixedConstraintData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 134
// RVA: 0xD43910
void **__fastcall getVtablehkpFixedConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-E8h]

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpFixedConstraintData::`vftable';
}

// File Line: 156
// RVA: 0x15CD270
void **dynamic_initializer_for__hkpFixedConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpFixedConstraintData();
  hkpFixedConstraintDataTypeInfo.m_size = 224i64;
  hkpFixedConstraintDataTypeInfo.m_typeName = "hkpFixedConstraintData";
  hkpFixedConstraintDataTypeInfo.m_vtable = result;
  hkpFixedConstraintDataTypeInfo.m_scopedName = "!hkpFixedConstraintData";
  hkpFixedConstraintDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpFixedConstraintData;
  hkpFixedConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpFixedConstraintData;
  return result;
}

