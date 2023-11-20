// File Line: 62
// RVA: 0x15CAA20
void dynamic_initializer_for__hkpShapeInfoClass__()
{
  hkClass::hkClass(
    &hkpShapeInfoClass,
    "hkpShapeInfo",
    &hkReferencedObjectClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkpShapeInfoClass_Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 65
// RVA: 0xCEBD10
hkClass *__fastcall hkpShapeInfo::staticClass()
{
  return &hkpShapeInfoClass;
}

// File Line: 72
// RVA: 0xCEBD20
void __fastcall finishLoadedObjecthkpShapeInfo(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpShapeInfo::`vftable;
}

// File Line: 78
// RVA: 0xCEBD40
void __fastcall cleanupLoadedObjecthkpShapeInfo(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 82
// RVA: 0xCEBD50
void **__fastcall getVtablehkpShapeInfo()
{
  return &hkpShapeInfo::`vftable;
}

// File Line: 104
// RVA: 0x15CAA90
void **dynamic_initializer_for__hkpShapeInfoTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpShapeInfo();
  hkpShapeInfoTypeInfo.m_size = 128i64;
  hkpShapeInfoTypeInfo.m_typeName = "hkpShapeInfo";
  hkpShapeInfoTypeInfo.m_vtable = result;
  hkpShapeInfoTypeInfo.m_scopedName = "!hkpShapeInfo";
  hkpShapeInfoTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpShapeInfo;
  hkpShapeInfoTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpShapeInfo;
  return result;
}

