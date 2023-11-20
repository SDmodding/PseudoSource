// File Line: 52
// RVA: 0x15D6BC0
hkClassEnum *dynamic_initializer_for__hkxLightClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkxLightLightTypeEnum;
  hkxLightClass_Members.m_enum = hkxLightLightTypeEnum;
  return result;
}

// File Line: 79
// RVA: 0x15D6B50
void dynamic_initializer_for__hkxLightClass__()
{
  hkClass::hkClass(
    &hkxLightClass,
    "hkxLight",
    &hkReferencedObjectClass,
    96,
    0i64,
    0,
    &hkxLightEnums,
    1,
    &hkxLightClass_Members,
    11,
    0i64,
    0i64,
    0,
    3u);
}

// File Line: 82
// RVA: 0xE320D0
hkClass *__fastcall hkxLight::staticClass()
{
  return &hkxLightClass;
}

// File Line: 89
// RVA: 0xE320E0
void __fastcall finishLoadedObjecthkxLight(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkxLight::`vftable;
}

// File Line: 95
// RVA: 0xE32100
void __fastcall cleanupLoadedObjecthkxLight(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 99
// RVA: 0xE32110
void **__fastcall getVtablehkxLight()
{
  return &hkxLight::`vftable;
}

// File Line: 121
// RVA: 0x15D6BD0
void **dynamic_initializer_for__hkxLightTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxLight();
  hkxLightTypeInfo.m_size = 96i64;
  hkxLightTypeInfo.m_typeName = "hkxLight";
  hkxLightTypeInfo.m_vtable = result;
  hkxLightTypeInfo.m_scopedName = "!hkxLight";
  hkxLightTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxLight;
  hkxLightTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxLight;
  return result;
}

