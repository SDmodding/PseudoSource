// File Line: 57
// RVA: 0x15CF710
void dynamic_initializer_for__hkpGenericConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpGenericConstraintDataClass,
    "hkpGenericConstraintData",
    &hkpConstraintDataClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkpGenericConstraintData::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xD4F4A0
hkClass *__fastcall hkpGenericConstraintData::staticClass()
{
  return &hkpGenericConstraintDataClass;
}

// File Line: 67
// RVA: 0xD4F4B0
void __fastcall finishLoadedObjecthkpGenericConstraintData(
        hkpGenericConstraintData *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpGenericConstraintData::hkpGenericConstraintData(p, finishing);
}

// File Line: 73
// RVA: 0xD4F4D0
void __fastcall cleanupLoadedObjecthkpGenericConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 77
// RVA: 0xD4F4E0
hkBaseObjectVtbl *__fastcall getVtablehkpGenericConstraintData()
{
  hkpGenericConstraintData v1; // [rsp+20h] [rbp-98h] BYREF

  hkpGenericConstraintData::hkpGenericConstraintData(&v1, 0);
  return v1.vfptr;
}

// File Line: 99
// RVA: 0x15CF780
hkBaseObjectVtbl *dynamic_initializer_for__hkpGenericConstraintDataTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpGenericConstraintData();
  hkpGenericConstraintDataTypeInfo.m_size = 144i64;
  hkpGenericConstraintDataTypeInfo.m_typeName = "hkpGenericConstraintData";
  hkpGenericConstraintDataTypeInfo.m_vtable = result;
  hkpGenericConstraintDataTypeInfo.m_scopedName = "!hkpGenericConstraintData";
  hkpGenericConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpGenericConstraintData;
  hkpGenericConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpGenericConstraintData;
  return result;
}

