// File Line: 51
// RVA: 0x15CE550
void dynamic_initializer_for__hkpWheelFrictionConstraintDataRuntimeClass__()
{
  hkClass::hkClass(
    &hkpWheelFrictionConstraintDataRuntimeClass,
    "hkpWheelFrictionConstraintDataRuntime",
    0i64,
    1,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 54
// RVA: 0xD44870
hkClass *__fastcall hkpWheelFrictionConstraintData::Runtime::staticClass()
{
  return &hkpWheelFrictionConstraintDataRuntimeClass;
}

// File Line: 61
// RVA: 0xD448A0
void __fastcall cleanupLoadedObjecthkpWheelFrictionConstraintDataRuntime(void *p)
{
  ;
}

// File Line: 97
// RVA: 0x15CE480
void dynamic_initializer_for__hkpWheelFrictionConstraintDataAtomsClass__()
{
  hkClass::hkClass(
    &hkpWheelFrictionConstraintDataAtomsClass,
    "hkpWheelFrictionConstraintDataAtoms",
    0i64,
    192,
    0i64,
    0,
    0i64,
    0,
    &hkpWheelFrictionConstraintData_AtomsClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 100
// RVA: 0xD44880
hkClass *__fastcall hkpWheelFrictionConstraintData::Atoms::staticClass()
{
  return &hkpWheelFrictionConstraintDataAtomsClass;
}

// File Line: 107
// RVA: 0xD448B0
void __fastcall finishLoadedObjecthkpWheelFrictionConstraintDataAtoms(char *p, int finishing)
{
  if ( p )
  {
    if ( finishing )
    {
      *(_QWORD *)(p + 164) = 0i64;
      *(_QWORD *)(p + 172) = 0i64;
    }
  }
}

// File Line: 113
// RVA: 0xD448E0
void __fastcall cleanupLoadedObjecthkpWheelFrictionConstraintDataAtoms(void *p)
{
  ;
}

// File Line: 151
// RVA: 0x15CE4E0
void dynamic_initializer_for__hkpWheelFrictionConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpWheelFrictionConstraintDataClass,
    "hkpWheelFrictionConstraintData",
    &hkpConstraintDataClass,
    224,
    0i64,
    0,
    0i64,
    0,
    &hkpWheelFrictionConstraintDataClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 154
// RVA: 0xD44890
hkClass *__fastcall hkpWheelFrictionConstraintData::staticClass()
{
  return &hkpWheelFrictionConstraintDataClass;
}

// File Line: 161
// RVA: 0xD448F0
void __fastcall finishLoadedObjecthkpWheelFrictionConstraintData(char *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, finishing);
    *(_QWORD *)p = &hkpWheelFrictionConstraintData::`vftable;
    if ( finishing.m_finishing )
    {
      *(_QWORD *)(p + 196) = 0i64;
      *(_QWORD *)(p + 204) = 0i64;
    }
  }
}

// File Line: 167
// RVA: 0xD44940
void __fastcall cleanupLoadedObjecthkpWheelFrictionConstraintData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 171
// RVA: 0xD44950
void **__fastcall getVtablehkpWheelFrictionConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-E8h] BYREF

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpWheelFrictionConstraintData::`vftable;
}

// File Line: 193
// RVA: 0x15CE5B0
void **dynamic_initializer_for__hkpWheelFrictionConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpWheelFrictionConstraintData();
  hkpWheelFrictionConstraintDataTypeInfo.m_size = 224i64;
  hkpWheelFrictionConstraintDataTypeInfo.m_typeName = "hkpWheelFrictionConstraintData";
  hkpWheelFrictionConstraintDataTypeInfo.m_vtable = result;
  hkpWheelFrictionConstraintDataTypeInfo.m_scopedName = "!hkpWheelFrictionConstraintData";
  hkpWheelFrictionConstraintDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpWheelFrictionConstraintData;
  hkpWheelFrictionConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpWheelFrictionConstraintData;
  return result;
}

