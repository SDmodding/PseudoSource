// File Line: 54
// RVA: 0x15D2AB0
void dynamic_initializer_for__hkpAngularDashpotActionClass__()
{
  hkClass::hkClass(
    &hkpAngularDashpotActionClass,
    "hkpAngularDashpotAction",
    &hkpBinaryActionClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpAngularDashpotActionClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xE09FB0
hkClass *__fastcall hkpAngularDashpotAction::staticClass()
{
  return &hkpAngularDashpotActionClass;
}

// File Line: 64
// RVA: 0xE09FC0
void __fastcall finishLoadedObjecthkpAngularDashpotAction(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v3 = p + 5;
    v3[-5].m_stringAndFlag = (const char *)&hkpAction::`vftable;
    hkStringPtr::hkStringPtr(v3, finishing);
    p->m_stringAndFlag = (const char *)&hkpAngularDashpotAction::`vftable;
  }
}

// File Line: 70
// RVA: 0xE0A000
void __fastcall cleanupLoadedObjecthkpAngularDashpotAction(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 74
// RVA: 0xE0A010
void **__fastcall getVtablehkpAngularDashpotAction()
{
  hkStringPtr v1; // [rsp+48h] [rbp-40h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpAngularDashpotAction::`vftable;
}

// File Line: 96
// RVA: 0x15D2B20
void **dynamic_initializer_for__hkpAngularDashpotActionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpAngularDashpotAction();
  hkpAngularDashpotActionTypeInfo.m_size = 96i64;
  hkpAngularDashpotActionTypeInfo.m_typeName = "hkpAngularDashpotAction";
  hkpAngularDashpotActionTypeInfo.m_vtable = result;
  hkpAngularDashpotActionTypeInfo.m_scopedName = "!hkpAngularDashpotAction";
  hkpAngularDashpotActionTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpAngularDashpotAction;
  hkpAngularDashpotActionTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpAngularDashpotAction;
  return result;
}

