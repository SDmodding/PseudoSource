// File Line: 55
// RVA: 0x15D1940
void dynamic_initializer_for__hkpStiffSpringChainDataConstraintInfoClass__()
{
  hkClass::hkClass(
    &hkpStiffSpringChainDataConstraintInfoClass,
    "hkpStiffSpringChainDataConstraintInfo",
    0i64,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpStiffSpringChainData_ConstraintInfoClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xD51290
hkClass *__fastcall hkpStiffSpringChainData::ConstraintInfo::staticClass()
{
  return &hkpStiffSpringChainDataConstraintInfoClass;
}

// File Line: 65
// RVA: 0xD512A0
void __fastcall cleanupLoadedObjecthkpStiffSpringChainDataConstraintInfo(void *p)
{
  ;
}

// File Line: 107
// RVA: 0x15D18D0
void dynamic_initializer_for__hkpStiffSpringChainDataClass__()
{
  hkClass::hkClass(
    &hkpStiffSpringChainDataClass,
    "hkpStiffSpringChainData",
    &hkpConstraintChainDataClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpStiffSpringChainDataClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 110
// RVA: 0xD51280
hkClass *__fastcall hkpStiffSpringChainData::staticClass()
{
  return &hkpStiffSpringChainDataClass;
}

// File Line: 117
// RVA: 0xD512B0
void __fastcall finishLoadedObjecthkpStiffSpringChainData(
        hkpStiffSpringChainData *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpStiffSpringChainData::hkpStiffSpringChainData(p, finishing);
}

// File Line: 123
// RVA: 0xD512D0
void __fastcall cleanupLoadedObjecthkpStiffSpringChainData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 127
// RVA: 0xD512E0
hkBaseObjectVtbl *__fastcall getVtablehkpStiffSpringChainData()
{
  hkpStiffSpringChainData v1; // [rsp+20h] [rbp-68h] BYREF

  hkpStiffSpringChainData::hkpStiffSpringChainData(&v1, 0);
  return v1.vfptr;
}

// File Line: 149
// RVA: 0x15D19A0
hkBaseObjectVtbl *dynamic_initializer_for__hkpStiffSpringChainDataTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpStiffSpringChainData();
  hkpStiffSpringChainDataTypeInfo.m_size = 96i64;
  hkpStiffSpringChainDataTypeInfo.m_typeName = "hkpStiffSpringChainData";
  hkpStiffSpringChainDataTypeInfo.m_vtable = result;
  hkpStiffSpringChainDataTypeInfo.m_scopedName = "!hkpStiffSpringChainData";
  hkpStiffSpringChainDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpStiffSpringChainData;
  hkpStiffSpringChainDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpStiffSpringChainData;
  return result;
}

