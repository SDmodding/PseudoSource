// File Line: 58
// RVA: 0x15D65A0
void dynamic_initializer_for__hkxCameraClass__()
{
  hkClass::hkClass(
    &hkxCameraClass,
    "hkxCamera",
    &hkReferencedObjectClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkxCameraClass_Members,
    7,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 61
// RVA: 0xE31BA0
hkClass *__fastcall hkxCamera::staticClass()
{
  return &hkxCameraClass;
}

// File Line: 68
// RVA: 0xE31BB0
void __fastcall finishLoadedObjecthkxCamera(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkxCamera::`vftable;
}

// File Line: 74
// RVA: 0xE31BD0
void __fastcall cleanupLoadedObjecthkxCamera(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 78
// RVA: 0xE31BE0
void **__fastcall getVtablehkxCamera()
{
  return &hkxCamera::`vftable;
}

// File Line: 100
// RVA: 0x15D6610
void **dynamic_initializer_for__hkxCameraTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxCamera();
  hkxCameraTypeInfo.m_size = 80i64;
  hkxCameraTypeInfo.m_typeName = "hkxCamera";
  hkxCameraTypeInfo.m_vtable = result;
  hkxCameraTypeInfo.m_scopedName = "!hkxCamera";
  hkxCameraTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxCamera;
  hkxCameraTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxCamera;
  return result;
}

