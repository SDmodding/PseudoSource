// File Line: 93
// RVA: 0x15CD690
void dynamic_initializer_for__hkpLinearClearanceConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpLinearClearanceConstraintDataAtomsClass,
    "hkpLinearClearanceConstraintDataAtoms",
    0i64,
    288,
    0i64,
    0,
    &hkpLinearClearanceConstraintDataAtomsEnums,
    1,
    &hkpLinearClearanceConstraintData_AtomsClass_Members,
    9,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 96
// RVA: 0xD43BE0
hkClass *__fastcall hkpLinearClearanceConstraintData::Atoms::staticClass()
{
  return &hkpLinearClearanceConstraintDataAtomsClass;
}

// File Line: 103
// RVA: 0xD43C00
void __fastcall finishLoadedObjecthkpLinearClearanceConstraintDataAtoms(
        hkpLinearClearanceConstraintData::Atoms *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpLinearClearanceConstraintData::Atoms::Atoms(p, finishing);
}

// File Line: 109
// RVA: 0xD43C20
void __fastcall cleanupLoadedObjecthkpLinearClearanceConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 147
// RVA: 0x15CD700
void dynamic_initializer_for__hkpLinearClearanceConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpLinearClearanceConstraintDataClass,
    "hkpLinearClearanceConstraintData",
    &hkpConstraintDataClass,
    320,
    0i64,
    0,
    &hkpLinearClearanceConstraintDataEnums,
    1,
    &hkpLinearClearanceConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 150
// RVA: 0xD43BF0
hkClass *__fastcall hkpLinearClearanceConstraintData::staticClass()
{
  return &hkpLinearClearanceConstraintDataClass;
}

// File Line: 157
// RVA: 0xD43C30
void __fastcall finishLoadedObjecthkpLinearClearanceConstraintData(char *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, finishing);
    *(_QWORD *)p = &hkpLinearClearanceConstraintData::`vftable;
    hkpLinearClearanceConstraintData::Atoms::Atoms((hkpLinearClearanceConstraintData::Atoms *)(p + 32), finishing);
  }
}

// File Line: 163
// RVA: 0xD43C70
void __fastcall cleanupLoadedObjecthkpLinearClearanceConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 167
// RVA: 0xD43C80
hkBaseObjectVtbl *__fastcall getVtablehkpLinearClearanceConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-148h] BYREF
  hkpLinearClearanceConstraintData::Atoms v2; // [rsp+40h] [rbp-128h] BYREF

  hkpConstraintData::hkpConstraintData(&v1, 0);
  v1.vfptr = (hkBaseObjectVtbl *)&hkpLinearClearanceConstraintData::`vftable;
  hkpLinearClearanceConstraintData::Atoms::Atoms(&v2, 0);
  return v1.vfptr;
}

// File Line: 189
// RVA: 0x15CD770
hkBaseObjectVtbl *dynamic_initializer_for__hkpLinearClearanceConstraintDataTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpLinearClearanceConstraintData();
  hkpLinearClearanceConstraintDataTypeInfo.m_size = 320i64;
  hkpLinearClearanceConstraintDataTypeInfo.m_typeName = "hkpLinearClearanceConstraintData";
  hkpLinearClearanceConstraintDataTypeInfo.m_vtable = result;
  hkpLinearClearanceConstraintDataTypeInfo.m_scopedName = "!hkpLinearClearanceConstraintData";
  hkpLinearClearanceConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpLinearClearanceConstraintData;
  hkpLinearClearanceConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpLinearClearanceConstraintData;
  return result;
}

