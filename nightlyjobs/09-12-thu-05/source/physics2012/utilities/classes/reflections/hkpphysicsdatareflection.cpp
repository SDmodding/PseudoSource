// File Line: 57
// RVA: 0x15D3890
void dynamic_initializer_for__hkpPhysicsDataClass__()
{
  hkClass::hkClass(
    &hkpPhysicsDataClass,
    "hkpPhysicsData",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkpPhysicsData::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xE0B300
hkClass *__fastcall hkpPhysicsData::staticClass()
{
  return &hkpPhysicsDataClass;
}

// File Line: 67
// RVA: 0xE0B310
void __fastcall finishLoadedObjecthkpPhysicsData(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpPhysicsData::`vftable;
}

// File Line: 73
// RVA: 0xE0B330
void __fastcall cleanupLoadedObjecthkpPhysicsData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 77
// RVA: 0xE0B340
void **__fastcall getVtablehkpPhysicsData()
{
  return &hkpPhysicsData::`vftable;
}

// File Line: 99
// RVA: 0x15D3900
void **dynamic_initializer_for__hkpPhysicsDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpPhysicsData();
  hkpPhysicsDataTypeInfo.m_size = 40i64;
  hkpPhysicsDataTypeInfo.m_typeName = "hkpPhysicsData";
  hkpPhysicsDataTypeInfo.m_vtable = result;
  hkpPhysicsDataTypeInfo.m_scopedName = "!hkpPhysicsData";
  hkpPhysicsDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpPhysicsData;
  hkpPhysicsDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpPhysicsData;
  return result;
}

