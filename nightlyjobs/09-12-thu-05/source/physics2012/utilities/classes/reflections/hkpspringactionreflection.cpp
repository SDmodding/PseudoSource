// File Line: 149
// RVA: 0x15D41F0
void dynamic_initializer_for__hkpSpringActionClass__()
{
  hkClass::hkClass(
    &hkpSpringActionClass,
    "hkpSpringAction",
    &hkpBinaryActionClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkpSpringActionClass_Members,
    8,
    &hkpSpringAction_Default,
    0i64,
    0,
    0);
}

// File Line: 152
// RVA: 0xE0BBB0
hkClass *__fastcall hkpSpringAction::staticClass()
{
  return &hkpSpringActionClass;
}

// File Line: 159
// RVA: 0xE0BBC0
void __fastcall finishLoadedObjecthkpSpringAction(void *p, int finishing)
{
  _QWORD *v2; // rbx
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v2 = p;
    v3 = (hkStringPtr *)((char *)p + 40);
    v3[-5].m_stringAndFlag = (const char *)&hkpAction::`vftable';
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpSpringAction::`vftable';
  }
}

// File Line: 165
// RVA: 0xE0BC00
void __fastcall cleanupLoadedObjecthkpSpringAction(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 169
// RVA: 0xE0BC10
void **__fastcall getVtablehkpSpringAction()
{
  hkStringPtr v1; // [rsp+48h] [rbp-60h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpSpringAction::`vftable';
}

// File Line: 191
// RVA: 0x15D4260
void **dynamic_initializer_for__hkpSpringActionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpSpringAction();
  hkpSpringActionTypeInfo.m_size = 128i64;
  hkpSpringActionTypeInfo.m_typeName = "hkpSpringAction";
  hkpSpringActionTypeInfo.m_vtable = result;
  hkpSpringActionTypeInfo.m_scopedName = "!hkpSpringAction";
  hkpSpringActionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpSpringAction;
  hkpSpringActionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpSpringAction;
  return result;
}

