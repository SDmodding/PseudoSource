// File Line: 55
// RVA: 0x15D2F80
void dynamic_initializer_for__hkpDashpotActionClass__()
{
  hkClass::hkClass(
    &hkpDashpotActionClass,
    "hkpDashpotAction",
    &hkpBinaryActionClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkpDashpotAction::Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xE0A7D0
hkClass *__fastcall hkpDashpotAction::staticClass()
{
  return &hkpDashpotActionClass;
}

// File Line: 65
// RVA: 0xE0A7E0
void __fastcall finishLoadedObjecthkpDashpotAction(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v3 = p + 5;
    v3[-5].m_stringAndFlag = (const char *)&hkpAction::`vftable;
    hkStringPtr::hkStringPtr(v3, finishing);
    p->m_stringAndFlag = (const char *)&hkpDashpotAction::`vftable;
  }
}

// File Line: 71
// RVA: 0xE0A820
void __fastcall cleanupLoadedObjecthkpDashpotAction(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE0A830
void **__fastcall getVtablehkpDashpotAction()
{
  hkStringPtr v1; // [rsp+48h] [rbp-60h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpDashpotAction::`vftable;
}

// File Line: 97
// RVA: 0x15D2FF0
void **dynamic_initializer_for__hkpDashpotActionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpDashpotAction();
  hkpDashpotActionTypeInfo.m_size = 128i64;
  hkpDashpotActionTypeInfo.m_typeName = "hkpDashpotAction";
  hkpDashpotActionTypeInfo.m_vtable = result;
  hkpDashpotActionTypeInfo.m_scopedName = "!hkpDashpotAction";
  hkpDashpotActionTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpDashpotAction;
  hkpDashpotActionTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpDashpotAction;
  return result;
}

