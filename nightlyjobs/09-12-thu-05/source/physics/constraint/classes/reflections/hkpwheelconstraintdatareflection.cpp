// File Line: 80
// RVA: 0x15CE340
void dynamic_initializer_for__hkpWheelConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpWheelConstraintDataAtomsClass,
    "hkpWheelConstraintDataAtoms",
    0i64,
    336,
    0i64,
    0,
    &hkpWheelConstraintDataAtomsEnums,
    1,
    &hkpWheelConstraintData_AtomsClass_Members,
    7,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 83
// RVA: 0xD44760
hkClass *__fastcall hkpWheelConstraintData::Atoms::staticClass()
{
  return &hkpWheelConstraintDataAtomsClass;
}

// File Line: 90
// RVA: 0xD44780
void __fastcall finishLoadedObjecthkpWheelConstraintDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 96
// RVA: 0xD44790
void __fastcall cleanupLoadedObjecthkpWheelConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 136
// RVA: 0x15CE3B0
void dynamic_initializer_for__hkpWheelConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpWheelConstraintDataClass,
    "hkpWheelConstraintData",
    &hkpConstraintDataClass,
    400,
    0i64,
    0,
    0i64,
    0,
    &hkpWheelConstraintDataClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 139
// RVA: 0xD44770
hkClass *__fastcall hkpWheelConstraintData::staticClass()
{
  return &hkpWheelConstraintDataClass;
}

// File Line: 146
// RVA: 0xD447A0
void __fastcall finishLoadedObjecthkpWheelConstraintData(void *p, int finishing)
{
  _QWORD *v2; // rbx

  if ( p )
  {
    v2 = p;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpWheelConstraintData::`vftable';
  }
}

// File Line: 152
// RVA: 0xD447D0
void __fastcall cleanupLoadedObjecthkpWheelConstraintData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 156
// RVA: 0xD447E0
void **__fastcall getVtablehkpWheelConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-198h]

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpWheelConstraintData::`vftable';
}

// File Line: 178
// RVA: 0x15CE420
void **dynamic_initializer_for__hkpWheelConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpWheelConstraintData();
  hkpWheelConstraintDataTypeInfo.m_size = 400i64;
  hkpWheelConstraintDataTypeInfo.m_typeName = "hkpWheelConstraintData";
  hkpWheelConstraintDataTypeInfo.m_vtable = result;
  hkpWheelConstraintDataTypeInfo.m_scopedName = "!hkpWheelConstraintData";
  hkpWheelConstraintDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpWheelConstraintData;
  hkpWheelConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpWheelConstraintData;
  return result;
}

