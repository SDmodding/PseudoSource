// File Line: 99
// RVA: 0x15D7510
void dynamic_initializer_for__hkxSceneClass__()
{
  hkClass::hkClass(
    &hkxSceneClass,
    "hkxScene",
    &hkReferencedObjectClass,
    240,
    0i64,
    0,
    0i64,
    0,
    &hkxSceneClass_Members,
    15,
    &hkxScene_Default,
    0i64,
    0,
    2u);
}

// File Line: 102
// RVA: 0xE32C70
hkClass *__fastcall hkxScene::staticClass()
{
  return &hkxSceneClass;
}

// File Line: 109
// RVA: 0xE32C80
void __fastcall finishLoadedObjecthkxScene(void *p, int finishing)
{
  hkStringPtr *v2; // rbx
  hkStringPtr *v3; // rcx
  int v4; // edi

  if ( p )
  {
    v2 = (hkStringPtr *)p;
    v3 = (hkStringPtr *)((char *)p + 16);
    v3[-2].m_stringAndFlag = (const char *)&hkxScene::`vftable;
    v4 = finishing;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    hkStringPtr::hkStringPtr(v2 + 3, (hkFinishLoadedObjectFlag)v4);
  }
}

// File Line: 115
// RVA: 0xE32CD0
void __fastcall cleanupLoadedObjecthkxScene(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 119
// RVA: 0xE32CE0
void **__fastcall getVtablehkxScene()
{
  hkStringPtr v1; // [rsp+30h] [rbp-E8h]
  hkStringPtr v2; // [rsp+38h] [rbp-E0h]

  hkStringPtr::hkStringPtr(&v1, 0);
  hkStringPtr::hkStringPtr(&v2, 0);
  return &hkxScene::`vftable;
}

// File Line: 141
// RVA: 0x15D7580
void **dynamic_initializer_for__hkxSceneTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxScene();
  hkxSceneTypeInfo.m_size = 240i64;
  hkxSceneTypeInfo.m_typeName = "hkxScene";
  hkxSceneTypeInfo.m_vtable = result;
  hkxSceneTypeInfo.m_scopedName = "!hkxScene";
  hkxSceneTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxScene;
  hkxSceneTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxScene;
  return result;
}

