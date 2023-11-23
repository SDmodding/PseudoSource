// File Line: 100
// RVA: 0x15D1410
void dynamic_initializer_for__hkpPhysicsSystemClass__()
{
  hkClass::hkClass(
    &hkpPhysicsSystemClass,
    "hkpPhysicsSystem",
    &hkReferencedObjectClass,
    104,
    0i64,
    0,
    &hkpPhysicsSystemEnums,
    1,
    &hkpPhysicsSystem::Members,
    7,
    &hkpPhysicsSystem_Default,
    0i64,
    0,
    0);
}

// File Line: 103
// RVA: 0xD50F60
hkClass *__fastcall hkpPhysicsSystem::staticClass()
{
  return &hkpPhysicsSystemClass;
}

// File Line: 110
// RVA: 0xD50F70
void __fastcall finishLoadedObjecthkpPhysicsSystem(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v2; // rcx

  if ( p )
  {
    v2 = p + 10;
    v2[-10].m_stringAndFlag = (const char *)&hkpPhysicsSystem::`vftable;
    hkStringPtr::hkStringPtr(v2, finishing);
  }
}

// File Line: 116
// RVA: 0xD50FA0
void __fastcall cleanupLoadedObjecthkpPhysicsSystem(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 120
// RVA: 0xD50FB0
void **__fastcall getVtablehkpPhysicsSystem()
{
  hkStringPtr v1; // [rsp+70h] [rbp-28h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpPhysicsSystem::`vftable;
}

// File Line: 142
// RVA: 0x15D1490
void **dynamic_initializer_for__hkpPhysicsSystemTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpPhysicsSystem();
  hkpPhysicsSystemTypeInfo.m_size = 104i64;
  hkpPhysicsSystemTypeInfo.m_typeName = "hkpPhysicsSystem";
  hkpPhysicsSystemTypeInfo.m_vtable = result;
  hkpPhysicsSystemTypeInfo.m_scopedName = "!hkpPhysicsSystem";
  hkpPhysicsSystemTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpPhysicsSystem;
  hkpPhysicsSystemTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpPhysicsSystem;
  return result;
}

