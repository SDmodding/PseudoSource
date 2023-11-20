// File Line: 268
// RVA: 0x15D2DE0
void dynamic_initializer_for__hkpCharacterRigidBodyCinfoClass__()
{
  hkClass::hkClass(
    &hkpCharacterRigidBodyCinfoClass,
    "hkpCharacterRigidBodyCinfo",
    &hkpCharacterControllerCinfoClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkpCharacterRigidBodyCinfoClass_Members,
    16,
    &hkpCharacterRigidBodyCinfo_Default,
    0i64,
    0,
    0);
}

// File Line: 271
// RVA: 0xE0A650
hkClass *__fastcall hkpCharacterRigidBodyCinfo::staticClass()
{
  return &hkpCharacterRigidBodyCinfoClass;
}

// File Line: 278
// RVA: 0xE0A660
void __fastcall finishLoadedObjecthkpCharacterRigidBodyCinfo(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpCharacterRigidBodyCinfo::`vftable;
}

// File Line: 284
// RVA: 0xE0A680
void __fastcall cleanupLoadedObjecthkpCharacterRigidBodyCinfo(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 288
// RVA: 0xE0A690
void **__fastcall getVtablehkpCharacterRigidBodyCinfo()
{
  return &hkpCharacterRigidBodyCinfo::`vftable;
}

// File Line: 310
// RVA: 0x15D2E50
void **dynamic_initializer_for__hkpCharacterRigidBodyCinfoTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpCharacterRigidBodyCinfo();
  hkpCharacterRigidBodyCinfoTypeInfo.m_size = 128i64;
  hkpCharacterRigidBodyCinfoTypeInfo.m_typeName = "hkpCharacterRigidBodyCinfo";
  hkpCharacterRigidBodyCinfoTypeInfo.m_vtable = result;
  hkpCharacterRigidBodyCinfoTypeInfo.m_scopedName = "!hkpCharacterRigidBodyCinfo";
  hkpCharacterRigidBodyCinfoTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpCharacterRigidBodyCinfo;
  hkpCharacterRigidBodyCinfoTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpCharacterRigidBodyCinfo;
  return result;
}

