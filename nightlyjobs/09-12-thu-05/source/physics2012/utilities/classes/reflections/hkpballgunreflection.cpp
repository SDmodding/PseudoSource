// File Line: 144
// RVA: 0x15D2B80
void dynamic_initializer_for__hkpBallGunClass__()
{
  hkClass::hkClass(
    &hkpBallGunClass,
    "hkpBallGun",
    &hkpFirstPersonGunClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkpBallGunClass_Members,
    7,
    &hkpBallGun_Default,
    0i64,
    0,
    0);
}

// File Line: 147
// RVA: 0xE0A1B0
hkClass *__fastcall hkpBallGun::staticClass()
{
  return &hkpBallGunClass;
}

// File Line: 154
// RVA: 0xE0A1C0
void __fastcall finishLoadedObjecthkpBallGun(hkpBallGun *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpBallGun::hkpBallGun(p, finishing);
}

// File Line: 160
// RVA: 0xE0A1E0
void __fastcall cleanupLoadedObjecthkpBallGun(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 164
// RVA: 0xE0A1F0
hkBaseObjectVtbl *__fastcall getVtablehkpBallGun()
{
  hkpBallGun v1; // [rsp+20h] [rbp-78h] BYREF

  hkpBallGun::hkpBallGun(&v1, 0);
  return v1.vfptr;
}

// File Line: 186
// RVA: 0x15D2BF0
hkBaseObjectVtbl *dynamic_initializer_for__hkpBallGunTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpBallGun();
  hkpBallGunTypeInfo.m_size = 112i64;
  hkpBallGunTypeInfo.m_typeName = "hkpBallGun";
  hkpBallGunTypeInfo.m_vtable = result;
  hkpBallGunTypeInfo.m_scopedName = "!hkpBallGun";
  hkpBallGunTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpBallGun;
  hkpBallGunTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpBallGun;
  return result;
}

