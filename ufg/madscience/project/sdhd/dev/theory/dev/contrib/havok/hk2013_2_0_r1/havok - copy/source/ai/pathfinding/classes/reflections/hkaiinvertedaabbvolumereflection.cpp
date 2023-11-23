// File Line: 57
// RVA: 0x15C14E0
void dynamic_initializer_for__hkaiInvertedAabbVolumeClass__()
{
  hkClass::hkClass(
    &hkaiInvertedAabbVolumeClass,
    "hkaiInvertedAabbVolume",
    &hkaiVolumeClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkaiInvertedAabbVolume::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xBB6830
hkClass *__fastcall hkaiInvertedAabbVolume::staticClass()
{
  return &hkaiInvertedAabbVolumeClass;
}

// File Line: 67
// RVA: 0xBB6840
void __fastcall finishLoadedObjecthkaiInvertedAabbVolume(hkGeometry *p, hkFinishLoadedObjectFlag finishing)
{
  hkGeometry *v2; // rcx

  if ( p )
  {
    v2 = p + 1;
    v2[-1].vfptr = (hkBaseObjectVtbl *)&hkaiInvertedAabbVolume::`vftable;
    hkGeometry::hkGeometry(v2, finishing);
  }
}

// File Line: 73
// RVA: 0xBB6870
void __fastcall cleanupLoadedObjecthkaiInvertedAabbVolume(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 77
// RVA: 0xBB6880
void **__fastcall getVtablehkaiInvertedAabbVolume()
{
  hkGeometry v1; // [rsp+50h] [rbp-38h] BYREF

  hkGeometry::hkGeometry(&v1, 0);
  return &hkaiInvertedAabbVolume::`vftable;
}

// File Line: 99
// RVA: 0x15C1550
void **dynamic_initializer_for__hkaiInvertedAabbVolumeTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiInvertedAabbVolume();
  hkaiInvertedAabbVolumeTypeInfo.m_size = 96i64;
  hkaiInvertedAabbVolumeTypeInfo.m_typeName = "hkaiInvertedAabbVolume";
  hkaiInvertedAabbVolumeTypeInfo.m_vtable = result;
  hkaiInvertedAabbVolumeTypeInfo.m_scopedName = "!hkaiInvertedAabbVolume";
  hkaiInvertedAabbVolumeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiInvertedAabbVolume;
  hkaiInvertedAabbVolumeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiInvertedAabbVolume;
  return result;
}

