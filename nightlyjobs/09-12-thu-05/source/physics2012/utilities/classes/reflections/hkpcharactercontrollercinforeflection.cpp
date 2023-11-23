// File Line: 48
// RVA: 0x15D2C50
void dynamic_initializer_for__hkpCharacterControllerCinfoClass__()
{
  hkClass::hkClass(
    &hkpCharacterControllerCinfoClass,
    "hkpCharacterControllerCinfo",
    &hkReferencedObjectClass,
    16,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 51
// RVA: 0xE0A550
hkClass *__fastcall hkpCharacterControllerCinfo::staticClass()
{
  return &hkpCharacterControllerCinfoClass;
}

// File Line: 58
// RVA: 0xE0A560
void __fastcall finishLoadedObjecthkpCharacterControllerCinfo(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpCharacterControllerCinfo::`vftable;
}

// File Line: 64
// RVA: 0xE0A580
void __fastcall cleanupLoadedObjecthkpCharacterControllerCinfo(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 68
// RVA: 0xE0A590
void **__fastcall getVtablehkpCharacterControllerCinfo()
{
  return &hkpCharacterControllerCinfo::`vftable;
}

// File Line: 90
// RVA: 0x15D2CB0
void **dynamic_initializer_for__hkpCharacterControllerCinfoTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpCharacterControllerCinfo();
  hkpCharacterControllerCinfoTypeInfo.m_size = 16i64;
  hkpCharacterControllerCinfoTypeInfo.m_typeName = "hkpCharacterControllerCinfo";
  hkpCharacterControllerCinfoTypeInfo.m_vtable = result;
  hkpCharacterControllerCinfoTypeInfo.m_scopedName = "!hkpCharacterControllerCinfo";
  hkpCharacterControllerCinfoTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpCharacterControllerCinfo;
  hkpCharacterControllerCinfoTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpCharacterControllerCinfo;
  return result;
}

