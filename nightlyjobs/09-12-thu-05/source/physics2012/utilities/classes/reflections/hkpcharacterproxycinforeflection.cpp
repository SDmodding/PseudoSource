// File Line: 312
// RVA: 0x15D2D10
void dynamic_initializer_for__hkpCharacterProxyCinfoClass__()
{
  hkClass::hkClass(
    &hkpCharacterProxyCinfoClass,
    "hkpCharacterProxyCinfo",
    &hkpCharacterControllerCinfoClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkpCharacterProxyCinfoClass_Members,
    19,
    &hkpCharacterProxyCinfo_Default,
    0i64,
    0,
    1u);
}

// File Line: 315
// RVA: 0xE0A5A0
hkClass *__fastcall hkpCharacterProxyCinfo::staticClass()
{
  return &hkpCharacterProxyCinfoClass;
}

// File Line: 322
// RVA: 0xE0A5B0
void __fastcall finishLoadedObjecthkpCharacterProxyCinfo(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpCharacterProxyCinfo::`vftable;
}

// File Line: 328
// RVA: 0xE0A5D0
void __fastcall cleanupLoadedObjecthkpCharacterProxyCinfo(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 332
// RVA: 0xE0A5E0
void **__fastcall getVtablehkpCharacterProxyCinfo()
{
  return &hkpCharacterProxyCinfo::`vftable;
}

// File Line: 354
// RVA: 0x15D2D80
void **dynamic_initializer_for__hkpCharacterProxyCinfoTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpCharacterProxyCinfo();
  hkpCharacterProxyCinfoTypeInfo.m_size = 144i64;
  hkpCharacterProxyCinfoTypeInfo.m_typeName = "hkpCharacterProxyCinfo";
  hkpCharacterProxyCinfoTypeInfo.m_vtable = result;
  hkpCharacterProxyCinfoTypeInfo.m_scopedName = "!hkpCharacterProxyCinfo";
  hkpCharacterProxyCinfoTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpCharacterProxyCinfo;
  hkpCharacterProxyCinfoTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpCharacterProxyCinfo;
  return result;
}

