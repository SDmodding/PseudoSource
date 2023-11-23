// File Line: 56
// RVA: 0x15CDB90
void dynamic_initializer_for__hkpPulleyConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpPulleyConstraintDataAtomsClass,
    "hkpPulleyConstraintDataAtoms",
    0i64,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkpPulleyConstraintData_AtomsClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xD44100
hkClass *__fastcall hkpPulleyConstraintData::Atoms::staticClass()
{
  return &hkpPulleyConstraintDataAtomsClass;
}

// File Line: 66
// RVA: 0xD44120
void __fastcall finishLoadedObjecthkpPulleyConstraintDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 72
// RVA: 0xD44130
void __fastcall cleanupLoadedObjecthkpPulleyConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 110
// RVA: 0x15CDBF0
void dynamic_initializer_for__hkpPulleyConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpPulleyConstraintDataClass,
    "hkpPulleyConstraintData",
    &hkpConstraintDataClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkpPulleyConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 113
// RVA: 0xD44110
hkClass *__fastcall hkpPulleyConstraintData::staticClass()
{
  return &hkpPulleyConstraintDataClass;
}

// File Line: 120
// RVA: 0xD44140
void __fastcall finishLoadedObjecthkpPulleyConstraintData(hkpConstraintData *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkpConstraintData::hkpConstraintData(p, finishing);
    p->vfptr = (hkBaseObjectVtbl *)&hkpPulleyConstraintData::`vftable;
  }
}

// File Line: 126
// RVA: 0xD44170
void __fastcall cleanupLoadedObjecthkpPulleyConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 130
// RVA: 0xD44180
void **__fastcall getVtablehkpPulleyConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-98h] BYREF

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpPulleyConstraintData::`vftable;
}

// File Line: 152
// RVA: 0x15CDC60
void **dynamic_initializer_for__hkpPulleyConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpPulleyConstraintData();
  hkpPulleyConstraintDataTypeInfo.m_size = 144i64;
  hkpPulleyConstraintDataTypeInfo.m_typeName = "hkpPulleyConstraintData";
  hkpPulleyConstraintDataTypeInfo.m_vtable = result;
  hkpPulleyConstraintDataTypeInfo.m_scopedName = "!hkpPulleyConstraintData";
  hkpPulleyConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpPulleyConstraintData;
  hkpPulleyConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpPulleyConstraintData;
  return result;
}

