// File Line: 55
// RVA: 0x15D3960
void dynamic_initializer_for__hkpPhysicsSystemWithContactsClass__()
{
  hkClass::hkClass(
    &hkpPhysicsSystemWithContactsClass,
    "hkpPhysicsSystemWithContacts",
    &hkpPhysicsSystemClass,
    120,
    0i64,
    0,
    0i64,
    0,
    &hkpPhysicsSystemWithContacts::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xE0B3B0
hkClass *__fastcall hkpPhysicsSystemWithContacts::staticClass()
{
  return &hkpPhysicsSystemWithContactsClass;
}

// File Line: 65
// RVA: 0xE0B3C0
void __fastcall finishLoadedObjecthkpPhysicsSystemWithContacts(void *p, int finishing)
{
  _QWORD *v2; // rbx
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v2 = p;
    v3 = (hkStringPtr *)((char *)p + 80);
    v3[-10].m_stringAndFlag = (const char *)&hkpPhysicsSystem::`vftable';
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpPhysicsSystemWithContacts::`vftable';
  }
}

// File Line: 71
// RVA: 0xE0B400
void __fastcall cleanupLoadedObjecthkpPhysicsSystemWithContacts(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE0B410
void **__fastcall getVtablehkpPhysicsSystemWithContacts()
{
  hkStringPtr v1; // [rsp+70h] [rbp-38h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpPhysicsSystemWithContacts::`vftable';
}

// File Line: 97
// RVA: 0x15D39D0
void **dynamic_initializer_for__hkpPhysicsSystemWithContactsTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpPhysicsSystemWithContacts();
  hkpPhysicsSystemWithContactsTypeInfo.m_size = 120i64;
  hkpPhysicsSystemWithContactsTypeInfo.m_typeName = "hkpPhysicsSystemWithContacts";
  hkpPhysicsSystemWithContactsTypeInfo.m_vtable = result;
  hkpPhysicsSystemWithContactsTypeInfo.m_scopedName = "!hkpPhysicsSystemWithContacts";
  hkpPhysicsSystemWithContactsTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpPhysicsSystemWithContacts;
  hkpPhysicsSystemWithContactsTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpPhysicsSystemWithContacts;
  return result;
}

