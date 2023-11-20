// File Line: 84
// RVA: 0x15D36F0
void dynamic_initializer_for__hkpMountedBallGunClass__()
{
  hkClass::hkClass(
    &hkpMountedBallGunClass,
    "hkpMountedBallGun",
    &hkpBallGunClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkpMountedBallGunClass_Members,
    1,
    &hkpMountedBallGun_Default,
    0i64,
    0,
    0);
}

// File Line: 87
// RVA: 0xE0B150
hkClass *__fastcall hkpMountedBallGun::staticClass()
{
  return &hkpMountedBallGunClass;
}

// File Line: 94
// RVA: 0xE0B160
void __fastcall finishLoadedObjecthkpMountedBallGun(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpMountedBallGun::hkpMountedBallGun);
}

// File Line: 100
// RVA: 0xE0B180
void __fastcall cleanupLoadedObjecthkpMountedBallGun(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 104
// RVA: 0xE0B190
hkBaseObjectVtbl *__fastcall getVtablehkpMountedBallGun()
{
  hkpMountedBallGun v1; // [rsp+20h] [rbp-88h]

  hkpMountedBallGun::hkpMountedBallGun(&v1, 0);
  return v1.vfptr;
}

// File Line: 126
// RVA: 0x15D3760
hkBaseObjectVtbl *dynamic_initializer_for__hkpMountedBallGunTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpMountedBallGun();
  hkpMountedBallGunTypeInfo.m_size = 128i64;
  hkpMountedBallGunTypeInfo.m_typeName = "hkpMountedBallGun";
  hkpMountedBallGunTypeInfo.m_vtable = result;
  hkpMountedBallGunTypeInfo.m_scopedName = "!hkpMountedBallGun";
  hkpMountedBallGunTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpMountedBallGun;
  hkpMountedBallGunTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpMountedBallGun;
  return result;
}

