// File Line: 74
// RVA: 0x15C0CD0
void dynamic_initializer_for__hkaiDefaultAstarCostModifierClass__()
{
  hkClass::hkClass(
    &hkaiDefaultAstarCostModifierClass,
    "hkaiDefaultAstarCostModifier",
    &hkaiAstarCostModifierClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkaiDefaultAstarCostModifierClass_Members,
    2,
    &hkaiDefaultAstarCostModifier_Default,
    0i64,
    0,
    3);
}

// File Line: 77
// RVA: 0xBB64A0
hkClass *__fastcall hkaiDefaultAstarCostModifier::staticClass()
{
  return &hkaiDefaultAstarCostModifierClass;
}

// File Line: 84
// RVA: 0xBB64B0
void __fastcall finishLoadedObjecthkaiDefaultAstarCostModifier(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkaiDefaultAstarCostModifier::`vftable;
}

// File Line: 90
// RVA: 0xBB64D0
void __fastcall cleanupLoadedObjecthkaiDefaultAstarCostModifier(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 94
// RVA: 0xBB64E0
void **__fastcall getVtablehkaiDefaultAstarCostModifier()
{
  return &hkaiDefaultAstarCostModifier::`vftable;
}

// File Line: 116
// RVA: 0x15C0D40
void **dynamic_initializer_for__hkaiDefaultAstarCostModifierTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiDefaultAstarCostModifier();
  hkaiDefaultAstarCostModifierTypeInfo.m_size = 96i64;
  hkaiDefaultAstarCostModifierTypeInfo.m_typeName = "hkaiDefaultAstarCostModifier";
  hkaiDefaultAstarCostModifierTypeInfo.m_vtable = result;
  hkaiDefaultAstarCostModifierTypeInfo.m_scopedName = "!hkaiDefaultAstarCostModifier";
  hkaiDefaultAstarCostModifierTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiDefaultAstarCostModifier;
  hkaiDefaultAstarCostModifierTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiDefaultAstarCostModifier;
  return result;
}

