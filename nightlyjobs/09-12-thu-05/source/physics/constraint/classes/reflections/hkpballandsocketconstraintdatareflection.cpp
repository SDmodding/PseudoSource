// File Line: 58
// RVA: 0x15CCD10
void dynamic_initializer_for__hkpBallAndSocketConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpBallAndSocketConstraintDataAtomsClass,
    "hkpBallAndSocketConstraintDataAtoms",
    0i64,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpBallAndSocketConstraintData_AtomsClass_Members,
    3,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 61
// RVA: 0xD43570
hkClass *__fastcall hkpBallAndSocketConstraintData::Atoms::staticClass()
{
  return &hkpBallAndSocketConstraintDataAtomsClass;
}

// File Line: 68
// RVA: 0xD43590
void __fastcall finishLoadedObjecthkpBallAndSocketConstraintDataAtoms(void *p, int finishing)
{
  ;
}

// File Line: 74
// RVA: 0xD435A0
void __fastcall cleanupLoadedObjecthkpBallAndSocketConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 112
// RVA: 0x15CCD80
void dynamic_initializer_for__hkpBallAndSocketConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpBallAndSocketConstraintDataClass,
    "hkpBallAndSocketConstraintData",
    &hkpConstraintDataClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkpBallAndSocketConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 115
// RVA: 0xD43580
hkClass *__fastcall hkpBallAndSocketConstraintData::staticClass()
{
  return &hkpBallAndSocketConstraintDataClass;
}

// File Line: 122
// RVA: 0xD435B0
void __fastcall finishLoadedObjecthkpBallAndSocketConstraintData(void *p, int finishing)
{
  _QWORD *v2; // rbx

  if ( p )
  {
    v2 = p;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpBallAndSocketConstraintData::`vftable;
  }
}

// File Line: 128
// RVA: 0xD435E0
void __fastcall cleanupLoadedObjecthkpBallAndSocketConstraintData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 132
// RVA: 0xD435F0
void **__fastcall getVtablehkpBallAndSocketConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-78h]

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpBallAndSocketConstraintData::`vftable;
}

// File Line: 154
// RVA: 0x15CCDF0
void **dynamic_initializer_for__hkpBallAndSocketConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpBallAndSocketConstraintData();
  hkpBallAndSocketConstraintDataTypeInfo.m_size = 112i64;
  hkpBallAndSocketConstraintDataTypeInfo.m_typeName = "hkpBallAndSocketConstraintData";
  hkpBallAndSocketConstraintDataTypeInfo.m_vtable = result;
  hkpBallAndSocketConstraintDataTypeInfo.m_scopedName = "!hkpBallAndSocketConstraintData";
  hkpBallAndSocketConstraintDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpBallAndSocketConstraintData;
  hkpBallAndSocketConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpBallAndSocketConstraintData;
  return result;
}

