// File Line: 101
// RVA: 0x15D3410
hkClassEnum *dynamic_initializer_for__hkpFirstPersonGunClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpFirstPersonGunKeyboardKeyEnum;
  unk_142113810 = hkpFirstPersonGunKeyboardKeyEnum;
  return result;
}

// File Line: 142
// RVA: 0x15D3390
void dynamic_initializer_for__hkpFirstPersonGunClass__()
{
  hkClass::hkClass(
    &hkpFirstPersonGunClass,
    "hkpFirstPersonGun",
    &hkReferencedObjectClass,
    56,
    0i64,
    0,
    &hkpFirstPersonGunEnums,
    2,
    &hkpFirstPersonGunClass_Members,
    4,
    &hkpFirstPersonGun_Default,
    0i64,
    0,
    0);
}

// File Line: 145
// RVA: 0xE0AE10
hkClass *__fastcall hkpFirstPersonGun::staticClass()
{
  return &hkpFirstPersonGunClass;
}

// File Line: 152
// RVA: 0xE0AE20
void __fastcall finishLoadedObjecthkpFirstPersonGun(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
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
  }
}

// File Line: 158
// RVA: 0xE0AE80
void __fastcall cleanupLoadedObjecthkpFirstPersonGun(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 162
// RVA: 0xE0AE90
void **__fastcall getVtablehkpFirstPersonGun()
{
  hkStringPtr v1; // [rsp+38h] [rbp-30h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpFirstPersonGun::`vftable;
}

// File Line: 184
// RVA: 0x15D3420
void **dynamic_initializer_for__hkpFirstPersonGunTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpFirstPersonGun();
  hkpFirstPersonGunTypeInfo.m_size = 56i64;
  hkpFirstPersonGunTypeInfo.m_typeName = "hkpFirstPersonGun";
  hkpFirstPersonGunTypeInfo.m_vtable = result;
  hkpFirstPersonGunTypeInfo.m_scopedName = "!hkpFirstPersonGun";
  hkpFirstPersonGunTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpFirstPersonGun;
  hkpFirstPersonGunTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpFirstPersonGun;
  return result;
}

