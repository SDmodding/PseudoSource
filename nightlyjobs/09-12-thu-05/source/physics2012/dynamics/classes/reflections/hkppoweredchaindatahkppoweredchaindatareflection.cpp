// File Line: 59
// RVA: 0x15D1F20
void dynamic_initializer_for__hkpPoweredChainDataConstraintInfoClass__()
{
  hkClass::hkClass(
    &hkpPoweredChainDataConstraintInfoClass,
    "hkpPoweredChainDataConstraintInfo",
    0i64,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpPoweredChainData_ConstraintInfoClass_Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xD51540
hkClass *__fastcall hkpPoweredChainData::ConstraintInfo::staticClass()
{
  return &hkpPoweredChainDataConstraintInfoClass;
}

// File Line: 69
// RVA: 0xD51550
void __fastcall cleanupLoadedObjecthkpPoweredChainDataConstraintInfo(void *p)
{
  ;
}

// File Line: 140
// RVA: 0x15D1EB0
void dynamic_initializer_for__hkpPoweredChainDataClass__()
{
  hkClass::hkClass(
    &hkpPoweredChainDataClass,
    "hkpPoweredChainData",
    &hkpConstraintChainDataClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkpPoweredChainDataClass_Members,
    9,
    &hkpPoweredChainData_Default,
    0i64,
    0,
    0);
}

// File Line: 143
// RVA: 0xD51530
hkClass *__fastcall hkpPoweredChainData::staticClass()
{
  return &hkpPoweredChainDataClass;
}

// File Line: 150
// RVA: 0xD51560
void __fastcall finishLoadedObjecthkpPoweredChainData(hkpPoweredChainData *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpPoweredChainData::hkpPoweredChainData(p, finishing);
}

// File Line: 156
// RVA: 0xD51580
void __fastcall cleanupLoadedObjecthkpPoweredChainData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 160
// RVA: 0xD51590
hkBaseObjectVtbl *__fastcall getVtablehkpPoweredChainData()
{
  hkpPoweredChainData v1; // [rsp+20h] [rbp-78h] BYREF

  hkpPoweredChainData::hkpPoweredChainData(&v1, 0);
  return v1.vfptr;
}

// File Line: 182
// RVA: 0x15D1F80
hkBaseObjectVtbl *dynamic_initializer_for__hkpPoweredChainDataTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpPoweredChainData();
  hkpPoweredChainDataTypeInfo.m_size = 112i64;
  hkpPoweredChainDataTypeInfo.m_typeName = "hkpPoweredChainData";
  hkpPoweredChainDataTypeInfo.m_vtable = result;
  hkpPoweredChainDataTypeInfo.m_scopedName = "!hkpPoweredChainData";
  hkpPoweredChainDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpPoweredChainData;
  hkpPoweredChainDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpPoweredChainData;
  return result;
}

