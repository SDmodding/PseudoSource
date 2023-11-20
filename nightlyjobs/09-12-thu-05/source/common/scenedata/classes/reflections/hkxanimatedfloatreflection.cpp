// File Line: 39
// RVA: 0x15D6030
hkClassEnum *dynamic_initializer_for__hkxAnimatedFloatClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkxAttributeHintEnum;
  unk_142114CD8 = hkxAttributeHintEnum;
  return result;
}

// File Line: 56
// RVA: 0x15D5FC0
void dynamic_initializer_for__hkxAnimatedFloatClass__()
{
  hkClass::hkClass(
    &hkxAnimatedFloatClass,
    "hkxAnimatedFloat",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkxAnimatedFloatClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 59
// RVA: 0xE31690
hkClass *__fastcall hkxAnimatedFloat::staticClass()
{
  return &hkxAnimatedFloatClass;
}

// File Line: 66
// RVA: 0xE316A0
void __fastcall finishLoadedObjecthkxAnimatedFloat(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkxAnimatedFloat::`vftable;
}

// File Line: 72
// RVA: 0xE316C0
void __fastcall cleanupLoadedObjecthkxAnimatedFloat(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xE316D0
void **__fastcall getVtablehkxAnimatedFloat()
{
  return &hkxAnimatedFloat::`vftable;
}

// File Line: 98
// RVA: 0x15D6040
void **dynamic_initializer_for__hkxAnimatedFloatTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxAnimatedFloat();
  hkxAnimatedFloatTypeInfo.m_size = 40i64;
  hkxAnimatedFloatTypeInfo.m_typeName = "hkxAnimatedFloat";
  hkxAnimatedFloatTypeInfo.m_vtable = result;
  hkxAnimatedFloatTypeInfo.m_scopedName = "!hkxAnimatedFloat";
  hkxAnimatedFloatTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxAnimatedFloat;
  hkxAnimatedFloatTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxAnimatedFloat;
  return result;
}

