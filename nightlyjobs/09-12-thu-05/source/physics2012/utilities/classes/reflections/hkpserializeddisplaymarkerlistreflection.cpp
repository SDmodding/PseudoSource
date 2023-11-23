// File Line: 55
// RVA: 0x15D3FF0
void dynamic_initializer_for__hkpSerializedDisplayMarkerListClass__()
{
  hkClass::hkClass(
    &hkpSerializedDisplayMarkerListClass,
    "hkpSerializedDisplayMarkerList",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpSerializedDisplayMarkerListClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xE0B980
hkClass *__fastcall hkpSerializedDisplayMarkerList::staticClass()
{
  return &hkpSerializedDisplayMarkerListClass;
}

// File Line: 65
// RVA: 0xE0B990
void __fastcall finishLoadedObjecthkpSerializedDisplayMarkerList(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpSerializedDisplayMarkerList::`vftable;
}

// File Line: 71
// RVA: 0xE0B9B0
void __fastcall cleanupLoadedObjecthkpSerializedDisplayMarkerList(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE0B9C0
void **__fastcall getVtablehkpSerializedDisplayMarkerList()
{
  return &hkpSerializedDisplayMarkerList::`vftable;
}

// File Line: 97
// RVA: 0x15D4060
void **dynamic_initializer_for__hkpSerializedDisplayMarkerListTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpSerializedDisplayMarkerList();
  hkpSerializedDisplayMarkerListTypeInfo.m_size = 32i64;
  hkpSerializedDisplayMarkerListTypeInfo.m_typeName = "hkpSerializedDisplayMarkerList";
  hkpSerializedDisplayMarkerListTypeInfo.m_vtable = result;
  hkpSerializedDisplayMarkerListTypeInfo.m_scopedName = "!hkpSerializedDisplayMarkerList";
  hkpSerializedDisplayMarkerListTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpSerializedDisplayMarkerList;
  hkpSerializedDisplayMarkerListTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpSerializedDisplayMarkerList;
  return result;
}

