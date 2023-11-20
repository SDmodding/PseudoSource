// File Line: 87
// RVA: 0x15C2660
void dynamic_initializer_for__hkaiPathFollowingPropertiesClass__()
{
  hkClass::hkClass(
    &hkaiPathFollowingPropertiesClass,
    "hkaiPathFollowingProperties",
    &hkReferencedObjectClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkaiPathFollowingPropertiesClass_Members,
    9,
    &hkaiPathFollowingProperties_Default,
    0i64,
    0,
    6u);
}

// File Line: 90
// RVA: 0xBB7220
hkClass *__fastcall hkaiPathFollowingProperties::staticClass()
{
  return &hkaiPathFollowingPropertiesClass;
}

// File Line: 97
// RVA: 0xBB7230
void __fastcall finishLoadedObjecthkaiPathFollowingProperties(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiPathFollowingProperties::`vftable';
}

// File Line: 103
// RVA: 0xBB7250
void __fastcall cleanupLoadedObjecthkaiPathFollowingProperties(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 107
// RVA: 0xBB7260
void **__fastcall getVtablehkaiPathFollowingProperties()
{
  return &hkaiPathFollowingProperties::`vftable';
}

// File Line: 129
// RVA: 0x15C26D0
void **dynamic_initializer_for__hkaiPathFollowingPropertiesTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiPathFollowingProperties();
  hkaiPathFollowingPropertiesTypeInfo.m_size = 48i64;
  hkaiPathFollowingPropertiesTypeInfo.m_typeName = "hkaiPathFollowingProperties";
  hkaiPathFollowingPropertiesTypeInfo.m_vtable = result;
  hkaiPathFollowingPropertiesTypeInfo.m_scopedName = "!hkaiPathFollowingProperties";
  hkaiPathFollowingPropertiesTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiPathFollowingProperties;
  hkaiPathFollowingPropertiesTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiPathFollowingProperties;
  return result;
}

