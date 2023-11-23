// File Line: 158
// RVA: 0x15D3480
void dynamic_initializer_for__hkpGravityGunClass__()
{
  hkClass::hkClass(
    &hkpGravityGunClass,
    "hkpGravityGun",
    &hkpFirstPersonGunClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkpGravityGunClass_Members,
    8,
    &hkpGravityGun_Default,
    0i64,
    0,
    0);
}

// File Line: 161
// RVA: 0xE0AEC0
hkClass *__fastcall hkpGravityGun::staticClass()
{
  return &hkpGravityGunClass;
}

// File Line: 168
// RVA: 0xE0AED0
void __fastcall finishLoadedObjecthkpGravityGun(hkpGravityGun *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpGravityGun::hkpGravityGun(p, finishing);
}

// File Line: 174
// RVA: 0xE0AEF0
void __fastcall cleanupLoadedObjecthkpGravityGun(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 178
// RVA: 0xE0AF00
hkBaseObjectVtbl *__fastcall getVtablehkpGravityGun()
{
  hkpGravityGun v1; // [rsp+20h] [rbp-88h] BYREF

  hkpGravityGun::hkpGravityGun(&v1, 0);
  return v1.vfptr;
}

// File Line: 200
// RVA: 0x15D34F0
hkBaseObjectVtbl *dynamic_initializer_for__hkpGravityGunTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpGravityGun();
  hkpGravityGunTypeInfo.m_size = 128i64;
  hkpGravityGunTypeInfo.m_typeName = "hkpGravityGun";
  hkpGravityGunTypeInfo.m_vtable = result;
  hkpGravityGunTypeInfo.m_scopedName = "!hkpGravityGun";
  hkpGravityGunTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpGravityGun;
  hkpGravityGunTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpGravityGun;
  return result;
}

