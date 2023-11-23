// File Line: 61
// RVA: 0x15D0830
void dynamic_initializer_for__hkpBreakableConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpBreakableConstraintDataClass,
    "hkpBreakableConstraintData",
    &hkpConstraintDataClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpBreakableConstraintDataClass_Members,
    7,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 64
// RVA: 0xD50120
hkClass *__fastcall hkpBreakableConstraintData::staticClass()
{
  return &hkpBreakableConstraintDataClass;
}

// File Line: 71
// RVA: 0xD50130
void __fastcall finishLoadedObjecthkpBreakableConstraintData(
        hkpBreakableConstraintData *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpBreakableConstraintData::hkpBreakableConstraintData(p, finishing);
}

// File Line: 77
// RVA: 0xD50150
void __fastcall cleanupLoadedObjecthkpBreakableConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 81
// RVA: 0xD50160
hkBaseObjectVtbl *__fastcall getVtablehkpBreakableConstraintData()
{
  hkpBreakableConstraintData v1; // [rsp+20h] [rbp-68h] BYREF

  hkpBreakableConstraintData::hkpBreakableConstraintData(&v1, 0);
  return v1.vfptr;
}

// File Line: 103
// RVA: 0x15D08A0
hkBaseObjectVtbl *dynamic_initializer_for__hkpBreakableConstraintDataTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpBreakableConstraintData();
  hkpBreakableConstraintDataTypeInfo.m_size = 96i64;
  hkpBreakableConstraintDataTypeInfo.m_typeName = "hkpBreakableConstraintData";
  hkpBreakableConstraintDataTypeInfo.m_vtable = result;
  hkpBreakableConstraintDataTypeInfo.m_scopedName = "!hkpBreakableConstraintData";
  hkpBreakableConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpBreakableConstraintData;
  hkpBreakableConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpBreakableConstraintData;
  return result;
}

