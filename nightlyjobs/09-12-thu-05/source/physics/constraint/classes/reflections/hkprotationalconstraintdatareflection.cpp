// File Line: 56
// RVA: 0x15CE070
void dynamic_initializer_for__hkpRotationalConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpRotationalConstraintDataAtomsClass,
    "hkpRotationalConstraintDataAtoms",
    0i64,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkpRotationalConstraintData_AtomsClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xD44550
hkClass *__fastcall hkpRotationalConstraintData::Atoms::staticClass()
{
  return &hkpRotationalConstraintDataAtomsClass;
}

// File Line: 66
// RVA: 0xD44570
void __fastcall finishLoadedObjecthkpRotationalConstraintDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 72
// RVA: 0xD44580
void __fastcall cleanupLoadedObjecthkpRotationalConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 110
// RVA: 0x15CE0D0
void dynamic_initializer_for__hkpRotationalConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpRotationalConstraintDataClass,
    "hkpRotationalConstraintData",
    &hkpConstraintDataClass,
    160,
    0i64,
    0,
    0i64,
    0,
    &hkpRotationalConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 113
// RVA: 0xD44560
hkClass *__fastcall hkpRotationalConstraintData::staticClass()
{
  return &hkpRotationalConstraintDataClass;
}

// File Line: 120
// RVA: 0xD44590
void __fastcall finishLoadedObjecthkpRotationalConstraintData(hkpConstraintData *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkpConstraintData::hkpConstraintData(p, finishing);
    p->vfptr = (hkBaseObjectVtbl *)&hkpRotationalConstraintData::`vftable;
  }
}

// File Line: 126
// RVA: 0xD445C0
void __fastcall cleanupLoadedObjecthkpRotationalConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 130
// RVA: 0xD445D0
void **__fastcall getVtablehkpRotationalConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-A8h] BYREF

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpRotationalConstraintData::`vftable;
}

// File Line: 152
// RVA: 0x15CE140
void **dynamic_initializer_for__hkpRotationalConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpRotationalConstraintData();
  hkpRotationalConstraintDataTypeInfo.m_size = 160i64;
  hkpRotationalConstraintDataTypeInfo.m_typeName = "hkpRotationalConstraintData";
  hkpRotationalConstraintDataTypeInfo.m_vtable = result;
  hkpRotationalConstraintDataTypeInfo.m_scopedName = "!hkpRotationalConstraintData";
  hkpRotationalConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpRotationalConstraintData;
  hkpRotationalConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpRotationalConstraintData;
  return result;
}

