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
void __fastcall finishLoadedObjecthkpPhysicsSystemWithContacts(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v3 = p + 10;
    v3[-10].m_stringAndFlag = (const char *)&hkpPhysicsSystem::`vftable;
    hkStringPtr::hkStringPtr(v3, finishing);
    p->m_stringAndFlag = (const char *)&hkpPhysicsSystemWithContacts::`vftable;
  }
}

// File Line: 71
// RVA: 0xE0B400
void __fastcall cleanupLoadedObjecthkpPhysicsSystemWithContacts(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE0B410
void **__fastcall getVtablehkpPhysicsSystemWithContacts()
{
  hkStringPtr v1; // [rsp+70h] [rbp-38h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpPhysicsSystemWithContacts::`vftable;
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
  hkpPhysicsSystemWithContactsTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpPhysicsSystemWithContacts;
  hkpPhysicsSystemWithContactsTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpPhysicsSystemWithContacts;
  return result;
}

