// File Line: 104
// RVA: 0x15D3BC0
void dynamic_initializer_for__hkpProjectileGunClass__()
{
  hkClass::hkClass(
    &hkpProjectileGunClass,
    "hkpProjectileGun",
    &hkpFirstPersonGunClass,
    104,
    0i64,
    0,
    0i64,
    0,
    &hkpProjectileGunClass_Members,
    6,
    &hkpProjectileGun_Default,
    0i64,
    0,
    0);
}

// File Line: 107
// RVA: 0xE0B590
hkClass *__fastcall hkpProjectileGun::staticClass()
{
  return &hkpProjectileGunClass;
}

// File Line: 114
// RVA: 0xE0B5A0
void __fastcall finishLoadedObjecthkpProjectileGun(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v3 = p + 3;
    v3[-3].m_stringAndFlag = (const char *)&hkpFirstPersonGun::`vftable;
    hkStringPtr::hkStringPtr(v3, finishing);
    HIDWORD(p[6].m_stringAndFlag) = 0x80000000;
    p[5].m_stringAndFlag = 0i64;
    LODWORD(p[6].m_stringAndFlag) = 0;
    if ( finishing.m_finishing )
      LOBYTE(p[2].m_stringAndFlag) = 0;
    p->m_stringAndFlag = (const char *)&hkpProjectileGun::`vftable;
    p[9].m_stringAndFlag = 0i64;
    LODWORD(p[10].m_stringAndFlag) = 0;
    HIDWORD(p[10].m_stringAndFlag) = 0x80000000;
  }
}

// File Line: 120
// RVA: 0xE0B610
void __fastcall cleanupLoadedObjecthkpProjectileGun(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 124
// RVA: 0xE0B620
void **__fastcall getVtablehkpProjectileGun()
{
  hkStringPtr v1; // [rsp+38h] [rbp-60h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpProjectileGun::`vftable;
}

// File Line: 146
// RVA: 0x15D3C30
void **dynamic_initializer_for__hkpProjectileGunTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpProjectileGun();
  hkpProjectileGunTypeInfo.m_size = 104i64;
  hkpProjectileGunTypeInfo.m_typeName = "hkpProjectileGun";
  hkpProjectileGunTypeInfo.m_vtable = result;
  hkpProjectileGunTypeInfo.m_scopedName = "!hkpProjectileGun";
  hkpProjectileGunTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpProjectileGun;
  hkpProjectileGunTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpProjectileGun;
  return result;
}

