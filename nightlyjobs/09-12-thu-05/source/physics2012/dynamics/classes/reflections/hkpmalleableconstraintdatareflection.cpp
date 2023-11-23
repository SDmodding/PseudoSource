// File Line: 57
// RVA: 0x15CFCA0
void dynamic_initializer_for__hkpMalleableConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpMalleableConstraintDataClass,
    "hkpMalleableConstraintData",
    &hkpConstraintDataClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpMalleableConstraintData::Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xD4FB20
hkClass *__fastcall hkpMalleableConstraintData::staticClass()
{
  return &hkpMalleableConstraintDataClass;
}

// File Line: 67
// RVA: 0xD4FB30
void __fastcall finishLoadedObjecthkpMalleableConstraintData(
        hkpMalleableConstraintData *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpMalleableConstraintData::hkpMalleableConstraintData(p, finishing);
}

// File Line: 73
// RVA: 0xD4FB50
void __fastcall cleanupLoadedObjecthkpMalleableConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 77
// RVA: 0xD4FB60
hkBaseObjectVtbl *__fastcall getVtablehkpMalleableConstraintData()
{
  hkpMalleableConstraintData v1; // [rsp+20h] [rbp-58h] BYREF

  hkpMalleableConstraintData::hkpMalleableConstraintData(&v1, 0);
  return v1.vfptr;
}

// File Line: 99
// RVA: 0x15CFD10
hkBaseObjectVtbl *dynamic_initializer_for__hkpMalleableConstraintDataTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpMalleableConstraintData();
  hkpMalleableConstraintDataTypeInfo.m_size = 80i64;
  hkpMalleableConstraintDataTypeInfo.m_typeName = "hkpMalleableConstraintData";
  hkpMalleableConstraintDataTypeInfo.m_vtable = result;
  hkpMalleableConstraintDataTypeInfo.m_scopedName = "!hkpMalleableConstraintData";
  hkpMalleableConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpMalleableConstraintData;
  hkpMalleableConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpMalleableConstraintData;
  return result;
}

