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
void __fastcall finishLoadedObjecthkpAngularDashpotAction(void *p, int finishing)
{
  _QWORD *v2; // rbx
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v2 = p;
    v3 = (hkStringPtr *)((char *)p + 40);
    v3[-5].m_stringAndFlag = (const char *)&hkpAction::`vftable';
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpAngularDashpotAction::`vftable';
  }
}

// File Line: 70
// RVA: 0xE0A000
void __fastcall cleanupLoadedObjecthkpAngularDashpotAction(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 74
// RVA: 0xE0A010
void **__fastcall getVtablehkpAngularDashpotAction()
{
  hkStringPtr v1; // [rsp+48h] [rbp-40h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpAngularDashpotAction::`vftable';
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
  hkpAngularDashpotActionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpAngularDashpotAction;
  hkpAngularDashpotActionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpAngularDashpotAction;
  return result;
}

