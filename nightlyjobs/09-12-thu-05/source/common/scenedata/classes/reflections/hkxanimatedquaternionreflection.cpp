// File Line: 52
// RVA: 0x15D6180
void dynamic_initializer_for__hkxAnimatedQuaternionClass__()
{
  hkClass::hkClass(
    &hkxAnimatedQuaternionClass,
    "hkxAnimatedQuaternion",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkxAnimatedQuaternionClass_Members,
    1,
    0i64,
    0i64,
    0,
    2);
}

// File Line: 55
// RVA: 0xE31740
hkClass *__fastcall hkxAnimatedQuaternion::staticClass()
{
  return &hkxAnimatedQuaternionClass;
}

// File Line: 62
// RVA: 0xE31750
void __fastcall finishLoadedObjecthkxAnimatedQuaternion(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxAnimatedQuaternion::`vftable;
}

// File Line: 68
// RVA: 0xE31770
void __fastcall cleanupLoadedObjecthkxAnimatedQuaternion(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xE31780
void **__fastcall getVtablehkxAnimatedQuaternion()
{
  return &hkxAnimatedQuaternion::`vftable;
}

// File Line: 94
// RVA: 0x15D61F0
void **dynamic_initializer_for__hkxAnimatedQuaternionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxAnimatedQuaternion();
  hkxAnimatedQuaternionTypeInfo.m_size = 32i64;
  hkxAnimatedQuaternionTypeInfo.m_typeName = "hkxAnimatedQuaternion";
  hkxAnimatedQuaternionTypeInfo.m_vtable = result;
  hkxAnimatedQuaternionTypeInfo.m_scopedName = "!hkxAnimatedQuaternion";
  hkxAnimatedQuaternionTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxAnimatedQuaternion;
  hkxAnimatedQuaternionTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxAnimatedQuaternion;
  return result;
}

