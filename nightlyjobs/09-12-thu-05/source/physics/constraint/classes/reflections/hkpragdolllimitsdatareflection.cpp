// File Line: 73
// RVA: 0x15CDF30
void dynamic_initializer_for__hkpRagdollLimitsDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpRagdollLimitsDataAtomsClass,
    "hkpRagdollLimitsDataAtoms",
    0i64,
    208,
    0i64,
    0,
    &hkpRagdollLimitsDataAtomsEnums,
    1,
    &hkpRagdollLimitsData_AtomsClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 76
// RVA: 0xD44420
hkClass *__fastcall hkpRagdollLimitsData::Atoms::staticClass()
{
  return &hkpRagdollLimitsDataAtomsClass;
}

// File Line: 83
// RVA: 0xD44440
void __fastcall finishLoadedObjecthkpRagdollLimitsDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 89
// RVA: 0xD44450
void __fastcall cleanupLoadedObjecthkpRagdollLimitsDataAtoms(void *p)
{
  ;
}

// File Line: 127
// RVA: 0x15CDFA0
void dynamic_initializer_for__hkpRagdollLimitsDataClass__()
{
  hkClass::hkClass(
    &hkpRagdollLimitsDataClass,
    "hkpRagdollLimitsData",
    &hkpConstraintDataClass,
    240,
    0i64,
    0,
    0i64,
    0,
    &hkpRagdollLimitsDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 130
// RVA: 0xD44430
hkClass *__fastcall hkpRagdollLimitsData::staticClass()
{
  return &hkpRagdollLimitsDataClass;
}

// File Line: 137
// RVA: 0xD44460
void __fastcall finishLoadedObjecthkpRagdollLimitsData(void *p, int finishing)
{
  int v2; // edi
  hkpRagdollLimitsData *v3; // rbx

  if ( p )
  {
    v2 = finishing;
    v3 = (hkpRagdollLimitsData *)p;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, (hkFinishLoadedObjectFlag)finishing);
    v3->vfptr = (hkBaseObjectVtbl *)&hkpRagdollLimitsData::`vftable;
    if ( v2 )
    {
      if ( v3->m_atoms.m_coneLimit.m_memOffsetToAngleOffset )
        hkpRagdollLimitsData::setConeLimitStabilization(v3, (hkBool)1);
    }
  }
}

// File Line: 143
// RVA: 0xD444B0
void __fastcall cleanupLoadedObjecthkpRagdollLimitsData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 147
// RVA: 0xD444C0
void **__fastcall getVtablehkpRagdollLimitsData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-F8h]

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpRagdollLimitsData::`vftable;
}

// File Line: 169
// RVA: 0x15CE010
void **dynamic_initializer_for__hkpRagdollLimitsDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpRagdollLimitsData();
  hkpRagdollLimitsDataTypeInfo.m_size = 240i64;
  hkpRagdollLimitsDataTypeInfo.m_typeName = "hkpRagdollLimitsData";
  hkpRagdollLimitsDataTypeInfo.m_vtable = result;
  hkpRagdollLimitsDataTypeInfo.m_scopedName = "!hkpRagdollLimitsData";
  hkpRagdollLimitsDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpRagdollLimitsData;
  hkpRagdollLimitsDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpRagdollLimitsData;
  return result;
}

