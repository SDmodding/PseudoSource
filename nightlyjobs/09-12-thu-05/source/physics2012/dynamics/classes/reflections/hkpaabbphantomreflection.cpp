// File Line: 58
// RVA: 0x15CFBD0
void dynamic_initializer_for__hkpAabbPhantomClass__()
{
  hkClass::hkClass(
    &hkpAabbPhantomClass,
    "hkpAabbPhantom",
    &hkpPhantomClass,
    304,
    0i64,
    0,
    0i64,
    0,
    &hkpAabbPhantom::Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xD4F9F0
hkClass *__fastcall hkpAabbPhantom::staticClass()
{
  return &hkpAabbPhantomClass;
}

// File Line: 68
// RVA: 0xD4FA00
void __fastcall finishLoadedObjecthkpAabbPhantom(hkpAabbPhantom *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpAabbPhantom::hkpAabbPhantom(p, finishing);
}

// File Line: 74
// RVA: 0xD4FA20
void __fastcall cleanupLoadedObjecthkpAabbPhantom(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 78
// RVA: 0xD4FA30
hkBaseObjectVtbl *__fastcall getVtablehkpAabbPhantom()
{
  hkpAabbPhantom v1; // [rsp+20h] [rbp-138h] BYREF

  hkpAabbPhantom::hkpAabbPhantom(&v1, 0);
  return v1.vfptr;
}

// File Line: 100
// RVA: 0x15CFC40
hkBaseObjectVtbl *dynamic_initializer_for__hkpAabbPhantomTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpAabbPhantom();
  hkpAabbPhantomTypeInfo.m_size = 304i64;
  hkpAabbPhantomTypeInfo.m_typeName = "hkpAabbPhantom";
  hkpAabbPhantomTypeInfo.m_vtable = result;
  hkpAabbPhantomTypeInfo.m_scopedName = "!hkpAabbPhantom";
  hkpAabbPhantomTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpAabbPhantom;
  hkpAabbPhantomTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpAabbPhantom;
  return result;
}

