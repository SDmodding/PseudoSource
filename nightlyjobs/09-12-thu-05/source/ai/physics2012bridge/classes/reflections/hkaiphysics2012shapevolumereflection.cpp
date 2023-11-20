// File Line: 60
// RVA: 0x15C4330
void dynamic_initializer_for__hkaiPhysics2012ShapeVolumeClass__()
{
  hkClass::hkClass(
    &hkaiPhysics2012ShapeVolumeClass,
    "hkaiPhysics2012ShapeVolume",
    &hkaiVolumeClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkaiPhysics2012ShapeVolume::Members,
    4,
    0i64,
    0i64,
    0,
    2u);
}

// File Line: 63
// RVA: 0xC2E420
hkClass *__fastcall hkaiPhysics2012ShapeVolume::staticClass()
{
  return &hkaiPhysics2012ShapeVolumeClass;
}

// File Line: 70
// RVA: 0xC2E430
void __fastcall finishLoadedObjecthkaiPhysics2012ShapeVolume(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiPhysics2012ShapeVolume::hkaiPhysics2012ShapeVolume);
}

// File Line: 76
// RVA: 0xC2E450
void __fastcall cleanupLoadedObjecthkaiPhysics2012ShapeVolume(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 80
// RVA: 0xC2E460
hkBaseObjectVtbl *__fastcall getVtablehkaiPhysics2012ShapeVolume()
{
  hkaiPhysics2012ShapeVolume v1; // [rsp+20h] [rbp-98h]

  hkaiPhysics2012ShapeVolume::hkaiPhysics2012ShapeVolume(&v1, 0);
  return v1.vfptr;
}

// File Line: 102
// RVA: 0x15C43A0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiPhysics2012ShapeVolumeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiPhysics2012ShapeVolume();
  hkaiPhysics2012ShapeVolumeTypeInfo.m_size = 144i64;
  hkaiPhysics2012ShapeVolumeTypeInfo.m_typeName = "hkaiPhysics2012ShapeVolume";
  hkaiPhysics2012ShapeVolumeTypeInfo.m_vtable = result;
  hkaiPhysics2012ShapeVolumeTypeInfo.m_scopedName = "!hkaiPhysics2012ShapeVolume";
  hkaiPhysics2012ShapeVolumeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiPhysics2012ShapeVolume;
  hkaiPhysics2012ShapeVolumeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiPhysics2012ShapeVolume;
  return result;
}

