// File Line: 80
// RVA: 0x15CD550
void dynamic_initializer_for__hkpLimitedHingeConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpLimitedHingeConstraintDataAtomsClass,
    "hkpLimitedHingeConstraintDataAtoms",
    0i64,
    272,
    0i64,
    0,
    &hkpLimitedHingeConstraintDataAtomsEnums,
    1,
    &hkpLimitedHingeConstraintData_AtomsClass_Members,
    7,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 83
// RVA: 0xD43AA0
hkClass *__fastcall hkpLimitedHingeConstraintData::Atoms::staticClass()
{
  return &hkpLimitedHingeConstraintDataAtomsClass;
}

// File Line: 90
// RVA: 0xD43AC0
void __fastcall finishLoadedObjecthkpLimitedHingeConstraintDataAtoms(
        hkpLimitedHingeConstraintData::Atoms *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpLimitedHingeConstraintData::Atoms::Atoms(p, finishing);
}

// File Line: 96
// RVA: 0xD43AE0
void __fastcall cleanupLoadedObjecthkpLimitedHingeConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 134
// RVA: 0x15CD5C0
void dynamic_initializer_for__hkpLimitedHingeConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpLimitedHingeConstraintDataClass,
    "hkpLimitedHingeConstraintData",
    &hkpConstraintDataClass,
    304,
    0i64,
    0,
    0i64,
    0,
    &hkpLimitedHingeConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 137
// RVA: 0xD43AB0
hkClass *__fastcall hkpLimitedHingeConstraintData::staticClass()
{
  return &hkpLimitedHingeConstraintDataClass;
}

// File Line: 144
// RVA: 0xD43AF0
void __fastcall finishLoadedObjecthkpLimitedHingeConstraintData(char *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, finishing);
    *(_QWORD *)p = &hkpLimitedHingeConstraintData::`vftable;
    hkpLimitedHingeConstraintData::Atoms::Atoms((hkpLimitedHingeConstraintData::Atoms *)(p + 32), finishing);
  }
}

// File Line: 150
// RVA: 0xD43B30
void __fastcall cleanupLoadedObjecthkpLimitedHingeConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 154
// RVA: 0xD43B40
hkBaseObjectVtbl *__fastcall getVtablehkpLimitedHingeConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-138h] BYREF
  hkpLimitedHingeConstraintData::Atoms v2; // [rsp+40h] [rbp-118h] BYREF

  hkpConstraintData::hkpConstraintData(&v1, 0);
  v1.vfptr = (hkBaseObjectVtbl *)&hkpLimitedHingeConstraintData::`vftable;
  hkpLimitedHingeConstraintData::Atoms::Atoms(&v2, 0);
  return v1.vfptr;
}

// File Line: 176
// RVA: 0x15CD630
hkBaseObjectVtbl *dynamic_initializer_for__hkpLimitedHingeConstraintDataTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpLimitedHingeConstraintData();
  hkpLimitedHingeConstraintDataTypeInfo.m_size = 304i64;
  hkpLimitedHingeConstraintDataTypeInfo.m_typeName = "hkpLimitedHingeConstraintData";
  hkpLimitedHingeConstraintDataTypeInfo.m_vtable = result;
  hkpLimitedHingeConstraintDataTypeInfo.m_scopedName = "!hkpLimitedHingeConstraintData";
  hkpLimitedHingeConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpLimitedHingeConstraintData;
  hkpLimitedHingeConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpLimitedHingeConstraintData;
  return result;
}

