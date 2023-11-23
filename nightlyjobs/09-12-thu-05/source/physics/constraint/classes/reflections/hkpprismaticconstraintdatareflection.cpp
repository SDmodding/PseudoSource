// File Line: 78
// RVA: 0x15CDA50
void dynamic_initializer_for__hkpPrismaticConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpPrismaticConstraintDataAtomsClass,
    "hkpPrismaticConstraintDataAtoms",
    0i64,
    256,
    0i64,
    0,
    &hkpPrismaticConstraintDataAtomsEnums,
    1,
    &hkpPrismaticConstraintData_AtomsClass_Members,
    7,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 81
// RVA: 0xD43FC0
hkClass *__fastcall hkpPrismaticConstraintData::Atoms::staticClass()
{
  return &hkpPrismaticConstraintDataAtomsClass;
}

// File Line: 88
// RVA: 0xD43FE0
void __fastcall finishLoadedObjecthkpPrismaticConstraintDataAtoms(
        hkpPrismaticConstraintData::Atoms *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpPrismaticConstraintData::Atoms::Atoms(p, finishing);
}

// File Line: 94
// RVA: 0xD44000
void __fastcall cleanupLoadedObjecthkpPrismaticConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 132
// RVA: 0x15CDAC0
void dynamic_initializer_for__hkpPrismaticConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpPrismaticConstraintDataClass,
    "hkpPrismaticConstraintData",
    &hkpConstraintDataClass,
    288,
    0i64,
    0,
    0i64,
    0,
    &hkpPrismaticConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 135
// RVA: 0xD43FD0
hkClass *__fastcall hkpPrismaticConstraintData::staticClass()
{
  return &hkpPrismaticConstraintDataClass;
}

// File Line: 142
// RVA: 0xD44010
void __fastcall finishLoadedObjecthkpPrismaticConstraintData(char *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, finishing);
    *(_QWORD *)p = &hkpPrismaticConstraintData::`vftable;
    hkpPrismaticConstraintData::Atoms::Atoms((hkpPrismaticConstraintData::Atoms *)(p + 32), finishing);
  }
}

// File Line: 148
// RVA: 0xD44050
void __fastcall cleanupLoadedObjecthkpPrismaticConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 152
// RVA: 0xD44060
hkBaseObjectVtbl *__fastcall getVtablehkpPrismaticConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-128h] BYREF
  hkpPrismaticConstraintData::Atoms v2; // [rsp+40h] [rbp-108h] BYREF

  hkpConstraintData::hkpConstraintData(&v1, 0);
  v1.vfptr = (hkBaseObjectVtbl *)&hkpPrismaticConstraintData::`vftable;
  hkpPrismaticConstraintData::Atoms::Atoms(&v2, 0);
  return v1.vfptr;
}

// File Line: 174
// RVA: 0x15CDB30
hkBaseObjectVtbl *dynamic_initializer_for__hkpPrismaticConstraintDataTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpPrismaticConstraintData();
  hkpPrismaticConstraintDataTypeInfo.m_size = 288i64;
  hkpPrismaticConstraintDataTypeInfo.m_typeName = "hkpPrismaticConstraintData";
  hkpPrismaticConstraintDataTypeInfo.m_vtable = result;
  hkpPrismaticConstraintDataTypeInfo.m_scopedName = "!hkpPrismaticConstraintData";
  hkpPrismaticConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpPrismaticConstraintData;
  hkpPrismaticConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpPrismaticConstraintData;
  return result;
}

