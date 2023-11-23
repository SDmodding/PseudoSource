// File Line: 52
// RVA: 0x15D6400
void dynamic_initializer_for__hkxBlobClass__()
{
  hkClass::hkClass(
    &hkxBlobClass,
    "hkxBlob",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkxBlobClass_Members,
    1,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 55
// RVA: 0xE31940
hkClass *__fastcall hkxBlob::staticClass()
{
  return &hkxBlobClass;
}

// File Line: 62
// RVA: 0xE31950
void __fastcall finishLoadedObjecthkxBlob(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxBlob::`vftable;
}

// File Line: 68
// RVA: 0xE31970
void __fastcall cleanupLoadedObjecthkxBlob(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xE31980
void **__fastcall getVtablehkxBlob()
{
  return &hkxBlob::`vftable;
}

// File Line: 94
// RVA: 0x15D6470
void **dynamic_initializer_for__hkxBlobTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxBlob();
  hkxBlobTypeInfo.m_size = 32i64;
  hkxBlobTypeInfo.m_typeName = "hkxBlob";
  hkxBlobTypeInfo.m_vtable = result;
  hkxBlobTypeInfo.m_scopedName = "!hkxBlob";
  hkxBlobTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxBlob;
  hkxBlobTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxBlob;
  return result;
}

