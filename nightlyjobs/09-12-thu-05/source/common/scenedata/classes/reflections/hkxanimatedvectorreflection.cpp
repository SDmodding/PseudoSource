// File Line: 39
// RVA: 0x15D62C0
hkClassEnum *dynamic_initializer_for__hkxAnimatedVectorClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkxAttributeHintEnum;
  unk_142114E08 = hkxAttributeHintEnum;
  return result;
}

// File Line: 56
// RVA: 0x15D6250
void dynamic_initializer_for__hkxAnimatedVectorClass__()
{
  hkClass::hkClass(
    &hkxAnimatedVectorClass,
    "hkxAnimatedVector",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkxAnimatedVectorClass_Members,
    2,
    0i64,
    0i64,
    0,
    2u);
}

// File Line: 59
// RVA: 0xE31790
hkClass *__fastcall hkxAnimatedVector::staticClass()
{
  return &hkxAnimatedVectorClass;
}

// File Line: 66
// RVA: 0xE317A0
void __fastcall finishLoadedObjecthkxAnimatedVector(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkxAnimatedVector::`vftable';
}

// File Line: 72
// RVA: 0xE317C0
void __fastcall cleanupLoadedObjecthkxAnimatedVector(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xE317D0
void **__fastcall getVtablehkxAnimatedVector()
{
  return &hkxAnimatedVector::`vftable';
}

// File Line: 98
// RVA: 0x15D62D0
void **dynamic_initializer_for__hkxAnimatedVectorTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxAnimatedVector();
  hkxAnimatedVectorTypeInfo.m_size = 40i64;
  hkxAnimatedVectorTypeInfo.m_typeName = "hkxAnimatedVector";
  hkxAnimatedVectorTypeInfo.m_vtable = result;
  hkxAnimatedVectorTypeInfo.m_scopedName = "!hkxAnimatedVector";
  hkxAnimatedVectorTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxAnimatedVector;
  hkxAnimatedVectorTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxAnimatedVector;
  return result;
}

