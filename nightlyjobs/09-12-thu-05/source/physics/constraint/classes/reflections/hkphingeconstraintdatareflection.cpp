// File Line: 72
// RVA: 0x15CD2D0
void dynamic_initializer_for__hkpHingeConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpHingeConstraintDataAtomsClass,
    "hkpHingeConstraintDataAtoms",
    0i64,
    192,
    0i64,
    0,
    &hkpHingeConstraintDataAtomsEnums,
    1,
    &hkpHingeConstraintData_AtomsClass_Members,
    4,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 75
// RVA: 0xD43940
hkClass *__fastcall hkpHingeConstraintData::Atoms::staticClass()
{
  return &hkpHingeConstraintDataAtomsClass;
}

// File Line: 82
// RVA: 0xD43960
void __fastcall finishLoadedObjecthkpHingeConstraintDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 88
// RVA: 0xD43970
void __fastcall cleanupLoadedObjecthkpHingeConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 126
// RVA: 0x15CD340
void dynamic_initializer_for__hkpHingeConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpHingeConstraintDataClass,
    "hkpHingeConstraintData",
    &hkpConstraintDataClass,
    224,
    0i64,
    0,
    0i64,
    0,
    &hkpHingeConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 129
// RVA: 0xD43950
hkClass *__fastcall hkpHingeConstraintData::staticClass()
{
  return &hkpHingeConstraintDataClass;
}

// File Line: 136
// RVA: 0xD43980
void __fastcall finishLoadedObjecthkpHingeConstraintData(void *p, int finishing)
{
  _QWORD *v2; // rbx

  if ( p )
  {
    v2 = p;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpHingeConstraintData::`vftable';
  }
}

// File Line: 142
// RVA: 0xD439B0
void __fastcall cleanupLoadedObjecthkpHingeConstraintData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 146
// RVA: 0xD439C0
void **__fastcall getVtablehkpHingeConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-E8h]

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpHingeConstraintData::`vftable';
}

// File Line: 168
// RVA: 0x15CD3B0
void **dynamic_initializer_for__hkpHingeConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpHingeConstraintData();
  hkpHingeConstraintDataTypeInfo.m_size = 224i64;
  hkpHingeConstraintDataTypeInfo.m_typeName = "hkpHingeConstraintData";
  hkpHingeConstraintDataTypeInfo.m_vtable = result;
  hkpHingeConstraintDataTypeInfo.m_scopedName = "!hkpHingeConstraintData";
  hkpHingeConstraintDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpHingeConstraintData;
  hkpHingeConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpHingeConstraintData;
  return result;
}

