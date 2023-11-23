// File Line: 56
// RVA: 0x15CCF40
void dynamic_initializer_for__hkpCogWheelConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpCogWheelConstraintDataAtomsClass,
    "hkpCogWheelConstraintDataAtoms",
    0i64,
    160,
    0i64,
    0,
    0i64,
    0,
    &hkpCogWheelConstraintData_AtomsClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xD436D0
hkClass *__fastcall hkpCogWheelConstraintData::Atoms::staticClass()
{
  return &hkpCogWheelConstraintDataAtomsClass;
}

// File Line: 66
// RVA: 0xD436F0
void __fastcall finishLoadedObjecthkpCogWheelConstraintDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 72
// RVA: 0xD43700
void __fastcall cleanupLoadedObjecthkpCogWheelConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 110
// RVA: 0x15CCFA0
void dynamic_initializer_for__hkpCogWheelConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpCogWheelConstraintDataClass,
    "hkpCogWheelConstraintData",
    &hkpConstraintDataClass,
    192,
    0i64,
    0,
    0i64,
    0,
    &hkpCogWheelConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 113
// RVA: 0xD436E0
hkClass *__fastcall hkpCogWheelConstraintData::staticClass()
{
  return &hkpCogWheelConstraintDataClass;
}

// File Line: 120
// RVA: 0xD43710
void __fastcall finishLoadedObjecthkpCogWheelConstraintData(hkpConstraintData *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkpConstraintData::hkpConstraintData(p, finishing);
    p->vfptr = (hkBaseObjectVtbl *)&hkpCogWheelConstraintData::`vftable;
  }
}

// File Line: 126
// RVA: 0xD43740
void __fastcall cleanupLoadedObjecthkpCogWheelConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 130
// RVA: 0xD43750
void **__fastcall getVtablehkpCogWheelConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-C8h] BYREF

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpCogWheelConstraintData::`vftable;
}

// File Line: 152
// RVA: 0x15CD010
void **dynamic_initializer_for__hkpCogWheelConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpCogWheelConstraintData();
  hkpCogWheelConstraintDataTypeInfo.m_size = 192i64;
  hkpCogWheelConstraintDataTypeInfo.m_typeName = "hkpCogWheelConstraintData";
  hkpCogWheelConstraintDataTypeInfo.m_vtable = result;
  hkpCogWheelConstraintDataTypeInfo.m_scopedName = "!hkpCogWheelConstraintData";
  hkpCogWheelConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpCogWheelConstraintData;
  hkpCogWheelConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpCogWheelConstraintData;
  return result;
}

