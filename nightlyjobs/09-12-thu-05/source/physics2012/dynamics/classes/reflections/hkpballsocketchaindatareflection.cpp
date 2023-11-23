// File Line: 54
// RVA: 0x15D06B0
void dynamic_initializer_for__hkpBallSocketChainDataConstraintInfoClass__()
{
  hkClass::hkClass(
    &hkpBallSocketChainDataConstraintInfoClass,
    "hkpBallSocketChainDataConstraintInfo",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpBallSocketChainData_ConstraintInfoClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xD50040
hkClass *__fastcall hkpBallSocketChainData::ConstraintInfo::staticClass()
{
  return &hkpBallSocketChainDataConstraintInfoClass;
}

// File Line: 64
// RVA: 0xD50050
void __fastcall cleanupLoadedObjecthkpBallSocketChainDataConstraintInfo(void *p)
{
  ;
}

// File Line: 108
// RVA: 0x15D0640
void dynamic_initializer_for__hkpBallSocketChainDataClass__()
{
  hkClass::hkClass(
    &hkpBallSocketChainDataClass,
    "hkpBallSocketChainData",
    &hkpConstraintChainDataClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkpBallSocketChainData::Members,
    7,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 111
// RVA: 0xD50030
hkClass *__fastcall hkpBallSocketChainData::staticClass()
{
  return &hkpBallSocketChainDataClass;
}

// File Line: 118
// RVA: 0xD50060
void __fastcall finishLoadedObjecthkpBallSocketChainData(hkpBallSocketChainData *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpBallSocketChainData::hkpBallSocketChainData(p, finishing);
}

// File Line: 124
// RVA: 0xD50080
void __fastcall cleanupLoadedObjecthkpBallSocketChainData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 128
// RVA: 0xD50090
hkBaseObjectVtbl *__fastcall getVtablehkpBallSocketChainData()
{
  hkpBallSocketChainData v1; // [rsp+20h] [rbp-78h] BYREF

  hkpBallSocketChainData::hkpBallSocketChainData(&v1, 0);
  return v1.vfptr;
}

// File Line: 150
// RVA: 0x15D0710
hkBaseObjectVtbl *dynamic_initializer_for__hkpBallSocketChainDataTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpBallSocketChainData();
  hkpBallSocketChainDataTypeInfo.m_size = 112i64;
  hkpBallSocketChainDataTypeInfo.m_typeName = "hkpBallSocketChainData";
  hkpBallSocketChainDataTypeInfo.m_vtable = result;
  hkpBallSocketChainDataTypeInfo.m_scopedName = "!hkpBallSocketChainData";
  hkpBallSocketChainDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpBallSocketChainData;
  hkpBallSocketChainDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpBallSocketChainData;
  return result;
}

