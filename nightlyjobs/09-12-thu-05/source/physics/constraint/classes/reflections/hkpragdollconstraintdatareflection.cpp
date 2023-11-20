// File Line: 95
// RVA: 0x15CDDF0
void dynamic_initializer_for__hkpRagdollConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpRagdollConstraintDataAtomsClass,
    "hkpRagdollConstraintDataAtoms",
    0i64,
    384,
    0i64,
    0,
    &hkpRagdollConstraintDataAtomsEnums,
    1,
    &hkpRagdollConstraintData_AtomsClass_Members,
    8,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 98
// RVA: 0xD442C0
hkClass *__fastcall hkpRagdollConstraintData::Atoms::staticClass()
{
  return &hkpRagdollConstraintDataAtomsClass;
}

// File Line: 105
// RVA: 0xD442E0
void __fastcall finishLoadedObjecthkpRagdollConstraintDataAtoms(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpRagdollConstraintData::Atoms::Atoms);
}

// File Line: 111
// RVA: 0xD44300
void __fastcall cleanupLoadedObjecthkpRagdollConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 149
// RVA: 0x15CDE60
void dynamic_initializer_for__hkpRagdollConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpRagdollConstraintDataClass,
    "hkpRagdollConstraintData",
    &hkpConstraintDataClass,
    416,
    0i64,
    0,
    &hkpRagdollConstraintDataEnums,
    1,
    &hkpRagdollConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 152
// RVA: 0xD442D0
hkClass *__fastcall hkpRagdollConstraintData::staticClass()
{
  return &hkpRagdollConstraintDataClass;
}

// File Line: 159
// RVA: 0xD44310
void __fastcall finishLoadedObjecthkpRagdollConstraintData(void *p, int finishing)
{
  int v2; // edi
  hkpRagdollConstraintData *v3; // rbx

  if ( p )
  {
    v2 = finishing;
    v3 = (hkpRagdollConstraintData *)p;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, (hkFinishLoadedObjectFlag)finishing);
    v3->vfptr = (hkBaseObjectVtbl *)&hkpRagdollConstraintData::`vftable';
    hkpRagdollConstraintData::Atoms::Atoms(&v3->m_atoms, (hkFinishLoadedObjectFlag)v2);
    if ( v2 )
    {
      if ( v3->m_atoms.m_coneLimit.m_memOffsetToAngleOffset )
        hkpRagdollConstraintData::setConeLimitStabilization(v3, (hkBool)1);
    }
  }
}

// File Line: 165
// RVA: 0xD44370
void __fastcall cleanupLoadedObjecthkpRagdollConstraintData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 169
// RVA: 0xD44380
hkBaseObjectVtbl *__fastcall getVtablehkpRagdollConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-1A8h]
  hkpRagdollConstraintData::Atoms v2; // [rsp+40h] [rbp-188h]

  hkpConstraintData::hkpConstraintData(&v1, 0);
  v1.vfptr = (hkBaseObjectVtbl *)&hkpRagdollConstraintData::`vftable';
  hkpRagdollConstraintData::Atoms::Atoms(&v2, 0);
  return v1.vfptr;
}

// File Line: 191
// RVA: 0x15CDED0
hkBaseObjectVtbl *dynamic_initializer_for__hkpRagdollConstraintDataTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpRagdollConstraintData();
  hkpRagdollConstraintDataTypeInfo.m_size = 416i64;
  hkpRagdollConstraintDataTypeInfo.m_typeName = "hkpRagdollConstraintData";
  hkpRagdollConstraintDataTypeInfo.m_vtable = result;
  hkpRagdollConstraintDataTypeInfo.m_scopedName = "!hkpRagdollConstraintData";
  hkpRagdollConstraintDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpRagdollConstraintData;
  hkpRagdollConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpRagdollConstraintData;
  return result;
}

