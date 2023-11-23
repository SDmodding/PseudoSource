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
void __fastcall finishLoadedObjecthkpWheelConstraintData(hkpConstraintData *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkpConstraintData::hkpConstraintData(p, finishing);
    p->vfptr = (hkBaseObjectVtbl *)&hkpWheelConstraintData::`vftable;
  }
}

// File Line: 152
// RVA: 0xD447D0
void __fastcall cleanupLoadedObjecthkpWheelConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 156
// RVA: 0xD447E0
void **__fastcall getVtablehkpWheelConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-198h] BYREF

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpWheelConstraintData::`vftable;
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
  hkpWheelConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpWheelConstraintData;
  hkpWheelConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpWheelConstraintData;
  return result;
}

