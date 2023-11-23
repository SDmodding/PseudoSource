// File Line: 58
// RVA: 0x15D09D0
void dynamic_initializer_for__hkpCachingShapePhantomClass__()
{
  hkClass::hkClass(
    &hkpCachingShapePhantomClass,
    "hkpCachingShapePhantom",
    &hkpShapePhantomClass,
    448,
    0i64,
    0,
    0i64,
    0,
    &hkpCachingShapePhantom::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xD50260
hkClass *__fastcall hkpCachingShapePhantom::staticClass()
{
  return &hkpCachingShapePhantomClass;
}

// File Line: 68
// RVA: 0xD50270
void __fastcall finishLoadedObjecthkpCachingShapePhantom(hkpCachingShapePhantom *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpCachingShapePhantom::hkpCachingShapePhantom(p, finishing);
}

// File Line: 74
// RVA: 0xD50290
void __fastcall cleanupLoadedObjecthkpCachingShapePhantom(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 78
// RVA: 0xD502A0
hkBaseObjectVtbl *__fastcall getVtablehkpCachingShapePhantom()
{
  hkpCachingShapePhantom v1; // [rsp+20h] [rbp-1C8h] BYREF

  hkpCachingShapePhantom::hkpCachingShapePhantom(&v1, 0);
  return v1.vfptr;
}

// File Line: 100
// RVA: 0x15D0A40
hkBaseObjectVtbl *dynamic_initializer_for__hkpCachingShapePhantomTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpCachingShapePhantom();
  hkpCachingShapePhantomTypeInfo.m_size = 448i64;
  hkpCachingShapePhantomTypeInfo.m_typeName = "hkpCachingShapePhantom";
  hkpCachingShapePhantomTypeInfo.m_vtable = result;
  hkpCachingShapePhantomTypeInfo.m_scopedName = "!hkpCachingShapePhantom";
  hkpCachingShapePhantomTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpCachingShapePhantom;
  hkpCachingShapePhantomTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpCachingShapePhantom;
  return result;
}

