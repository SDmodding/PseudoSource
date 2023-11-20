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
void __fastcall finishLoadedObjecthkpProjectileGun(void *p, int finishing)
{
  _DWORD *v2; // rbx
  hkStringPtr *v3; // rcx
  int v4; // edi

  if ( p )
  {
    v2 = p;
    v3 = (hkStringPtr *)((char *)p + 24);
    v3[-3].m_stringAndFlag = (const char *)&hkpFirstPersonGun::`vftable';
    v4 = finishing;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    v2[13] = 2147483648;
    *((_QWORD *)v2 + 5) = 0i64;
    v2[12] = 0;
    if ( v4 )
      *((_BYTE *)v2 + 16) = 0;
    *(_QWORD *)v2 = &hkpProjectileGun::`vftable';
    *((_QWORD *)v2 + 9) = 0i64;
    v2[20] = 0;
    v2[21] = 2147483648;
  }
}

// File Line: 120
// RVA: 0xE0B610
void __fastcall cleanupLoadedObjecthkpProjectileGun(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 124
// RVA: 0xE0B620
void **__fastcall getVtablehkpProjectileGun()
{
  hkStringPtr v1; // [rsp+38h] [rbp-60h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpProjectileGun::`vftable';
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
  hkpProjectileGunTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpProjectileGun;
  hkpProjectileGunTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpProjectileGun;
  return result;
}

