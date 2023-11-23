// File Line: 52
// RVA: 0x15D3F20
void dynamic_initializer_for__hkpSerializedDisplayMarkerClass__()
{
  hkClass::hkClass(
    &hkpSerializedDisplayMarkerClass,
    "hkpSerializedDisplayMarker",
    &hkReferencedObjectClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpSerializedDisplayMarkerClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 55
// RVA: 0xE0B930
hkClass *__fastcall hkpSerializedDisplayMarker::staticClass()
{
  return &hkpSerializedDisplayMarkerClass;
}

// File Line: 62
// RVA: 0xE0B940
void __fastcall finishLoadedObjecthkpSerializedDisplayMarker(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpSerializedDisplayMarker::`vftable;
}

// File Line: 68
// RVA: 0xE0B960
void __fastcall cleanupLoadedObjecthkpSerializedDisplayMarker(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xE0B970
void **__fastcall getVtablehkpSerializedDisplayMarker()
{
  return &hkpSerializedDisplayMarker::`vftable;
}

// File Line: 94
// RVA: 0x15D3F90
void **dynamic_initializer_for__hkpSerializedDisplayMarkerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpSerializedDisplayMarker();
  hkpSerializedDisplayMarkerTypeInfo.m_size = 80i64;
  hkpSerializedDisplayMarkerTypeInfo.m_typeName = "hkpSerializedDisplayMarker";
  hkpSerializedDisplayMarkerTypeInfo.m_vtable = result;
  hkpSerializedDisplayMarkerTypeInfo.m_scopedName = "!hkpSerializedDisplayMarker";
  hkpSerializedDisplayMarkerTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpSerializedDisplayMarker;
  hkpSerializedDisplayMarkerTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpSerializedDisplayMarker;
  return result;
}

