// File Line: 55
// RVA: 0x15D3620
void dynamic_initializer_for__hkpMotorActionClass__()
{
  hkClass::hkClass(
    &hkpMotorActionClass,
    "hkpMotorAction",
    &hkpUnaryActionClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpMotorAction::Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xE0B060
hkClass *__fastcall hkpMotorAction::staticClass()
{
  return &hkpMotorActionClass;
}

// File Line: 65
// RVA: 0xE0B070
void __fastcall finishLoadedObjecthkpMotorAction(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v3 = p + 5;
    v3[-5].m_stringAndFlag = (const char *)&hkpAction::`vftable;
    hkStringPtr::hkStringPtr(v3, finishing);
    p->m_stringAndFlag = (const char *)&hkpMotorAction::`vftable;
  }
}

// File Line: 71
// RVA: 0xE0B0B0
void __fastcall cleanupLoadedObjecthkpMotorAction(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE0B0C0
void **__fastcall getVtablehkpMotorAction()
{
  hkStringPtr v1; // [rsp+48h] [rbp-40h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpMotorAction::`vftable;
}

// File Line: 97
// RVA: 0x15D3690
void **dynamic_initializer_for__hkpMotorActionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpMotorAction();
  hkpMotorActionTypeInfo.m_size = 96i64;
  hkpMotorActionTypeInfo.m_typeName = "hkpMotorAction";
  hkpMotorActionTypeInfo.m_vtable = result;
  hkpMotorActionTypeInfo.m_scopedName = "!hkpMotorAction";
  hkpMotorActionTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpMotorAction;
  hkpMotorActionTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpMotorAction;
  return result;
}

