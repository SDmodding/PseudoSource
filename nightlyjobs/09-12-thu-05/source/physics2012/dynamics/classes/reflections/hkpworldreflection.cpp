// File Line: 282
// RVA: 0x15CF9B0
void dynamic_initializer_for__hkpWorldClass__()
{
  hkClass::hkClass(
    &hkpWorldClass,
    "hkpWorld",
    &hkReferencedObjectClass,
    1088,
    0i64,
    0,
    &hkpWorldEnums,
    3,
    &hkpWorldClass_Members,
    86,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 285
// RVA: 0xD4F640
hkClass *__fastcall hkpWorld::staticClass()
{
  return &hkpWorldClass;
}

// File Line: 292
// RVA: 0xD4F650
void __fastcall finishLoadedObjecthkpWorld(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpWorld::hkpWorld);
}

// File Line: 298
// RVA: 0xD4F670
void __fastcall cleanupLoadedObjecthkpWorld(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 302
// RVA: 0xD4F680
hkBaseObjectVtbl *__fastcall getVtablehkpWorld()
{
  hkpWorld v1; // [rsp+20h] [rbp-448h]

  hkpWorld::hkpWorld(&v1, 0);
  return v1.vfptr;
}

// File Line: 324
// RVA: 0x15CFA30
hkBaseObjectVtbl *dynamic_initializer_for__hkpWorldTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpWorld();
  hkpWorldTypeInfo.m_size = 1088i64;
  hkpWorldTypeInfo.m_typeName = "hkpWorld";
  hkpWorldTypeInfo.m_vtable = result;
  hkpWorldTypeInfo.m_scopedName = "!hkpWorld";
  hkpWorldTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpWorld;
  hkpWorldTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpWorld;
  return result;
}

