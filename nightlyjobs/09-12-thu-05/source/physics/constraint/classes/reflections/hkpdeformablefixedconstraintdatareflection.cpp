// File Line: 58
// RVA: 0x15CD070
void dynamic_initializer_for__hkpDeformableFixedConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpDeformableFixedConstraintDataAtomsClass,
    "hkpDeformableFixedConstraintDataAtoms",
    0i64,
    336,
    0i64,
    0,
    0i64,
    0,
    &hkpDeformableFixedConstraintData_AtomsClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xD43780
hkClass *__fastcall hkpDeformableFixedConstraintData::Atoms::staticClass()
{
  return &hkpDeformableFixedConstraintDataAtomsClass;
}

// File Line: 68
// RVA: 0xD437A0
void __fastcall finishLoadedObjecthkpDeformableFixedConstraintDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 74
// RVA: 0xD437B0
void __fastcall cleanupLoadedObjecthkpDeformableFixedConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 112
// RVA: 0x15CD0D0
void dynamic_initializer_for__hkpDeformableFixedConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpDeformableFixedConstraintDataClass,
    "hkpDeformableFixedConstraintData",
    &hkpConstraintDataClass,
    368,
    0i64,
    0,
    0i64,
    0,
    &hkpDeformableFixedConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 115
// RVA: 0xD43790
hkClass *__fastcall hkpDeformableFixedConstraintData::staticClass()
{
  return &hkpDeformableFixedConstraintDataClass;
}

// File Line: 122
// RVA: 0xD437C0
void __fastcall finishLoadedObjecthkpDeformableFixedConstraintData(
        hkpConstraintData *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkpConstraintData::hkpConstraintData(p, finishing);
    p->vfptr = (hkBaseObjectVtbl *)&hkpDeformableFixedConstraintData::`vftable;
  }
}

// File Line: 128
// RVA: 0xD437F0
void __fastcall cleanupLoadedObjecthkpDeformableFixedConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 132
// RVA: 0xD43800
void **__fastcall getVtablehkpDeformableFixedConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-178h] BYREF

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpDeformableFixedConstraintData::`vftable;
}

// File Line: 154
// RVA: 0x15CD140
void **dynamic_initializer_for__hkpDeformableFixedConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpDeformableFixedConstraintData();
  hkpDeformableFixedConstraintDataTypeInfo.m_size = 368i64;
  hkpDeformableFixedConstraintDataTypeInfo.m_typeName = "hkpDeformableFixedConstraintData";
  hkpDeformableFixedConstraintDataTypeInfo.m_vtable = result;
  hkpDeformableFixedConstraintDataTypeInfo.m_scopedName = "!hkpDeformableFixedConstraintData";
  hkpDeformableFixedConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpDeformableFixedConstraintData;
  hkpDeformableFixedConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpDeformableFixedConstraintData;
  return result;
}

