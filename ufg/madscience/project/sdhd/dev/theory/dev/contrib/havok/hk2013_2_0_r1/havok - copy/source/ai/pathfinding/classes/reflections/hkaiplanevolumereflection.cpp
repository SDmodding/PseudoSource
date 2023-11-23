// File Line: 80
// RVA: 0x15C29A0
void dynamic_initializer_for__hkaiPlaneVolumeClass__()
{
  hkClass::hkClass(
    &hkaiPlaneVolumeClass,
    "hkaiPlaneVolume",
    &hkaiVolumeClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkaiPlaneVolume::Members,
    4,
    &hkaiPlaneVolume_Default,
    0i64,
    0,
    2);
}

// File Line: 83
// RVA: 0xBB74A0
hkClass *__fastcall hkaiPlaneVolume::staticClass()
{
  return &hkaiPlaneVolumeClass;
}

// File Line: 90
// RVA: 0xBB74B0
void __fastcall finishLoadedObjecthkaiPlaneVolume(hkaiPlaneVolume *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiPlaneVolume::hkaiPlaneVolume(p, finishing);
}

// File Line: 96
// RVA: 0xBB74D0
void __fastcall cleanupLoadedObjecthkaiPlaneVolume(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 100
// RVA: 0xBB74E0
hkBaseObjectVtbl *__fastcall getVtablehkaiPlaneVolume()
{
  hkaiPlaneVolume v1; // [rsp+20h] [rbp-88h] BYREF

  hkaiPlaneVolume::hkaiPlaneVolume(&v1, 0);
  return v1.vfptr;
}

// File Line: 122
// RVA: 0x15C2A10
hkBaseObjectVtbl *dynamic_initializer_for__hkaiPlaneVolumeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiPlaneVolume();
  hkaiPlaneVolumeTypeInfo.m_size = 128i64;
  hkaiPlaneVolumeTypeInfo.m_typeName = "hkaiPlaneVolume";
  hkaiPlaneVolumeTypeInfo.m_vtable = result;
  hkaiPlaneVolumeTypeInfo.m_scopedName = "!hkaiPlaneVolume";
  hkaiPlaneVolumeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiPlaneVolume;
  hkaiPlaneVolumeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiPlaneVolume;
  return result;
}

