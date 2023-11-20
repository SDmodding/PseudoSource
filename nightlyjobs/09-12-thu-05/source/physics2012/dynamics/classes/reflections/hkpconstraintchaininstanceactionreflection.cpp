// File Line: 55
// RVA: 0x15D0C30
void dynamic_initializer_for__hkpConstraintChainInstanceActionClass__()
{
  hkClass::hkClass(
    &hkpConstraintChainInstanceActionClass,
    "hkpConstraintChainInstanceAction",
    &hkpActionClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkpConstraintChainInstanceActionClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xD50510
hkClass *__fastcall hkpConstraintChainInstanceAction::staticClass()
{
  return &hkpConstraintChainInstanceActionClass;
}

// File Line: 65
// RVA: 0xD50520
void __fastcall finishLoadedObjecthkpConstraintChainInstanceAction(void *p, int finishing)
{
  _QWORD *v2; // rbx
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v2 = p;
    v3 = (hkStringPtr *)((char *)p + 40);
    v3[-5].m_stringAndFlag = (const char *)&hkpAction::`vftable;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpConstraintChainInstanceAction::`vftable;
  }
}

// File Line: 71
// RVA: 0xD50560
void __fastcall cleanupLoadedObjecthkpConstraintChainInstanceAction(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 75
// RVA: 0xD50570
void **__fastcall getVtablehkpConstraintChainInstanceAction()
{
  hkStringPtr v1; // [rsp+48h] [rbp-20h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpConstraintChainInstanceAction::`vftable;
}

// File Line: 97
// RVA: 0x15D0CA0
void **dynamic_initializer_for__hkpConstraintChainInstanceActionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpConstraintChainInstanceAction();
  hkpConstraintChainInstanceActionTypeInfo.m_size = 56i64;
  hkpConstraintChainInstanceActionTypeInfo.m_typeName = "hkpConstraintChainInstanceAction";
  hkpConstraintChainInstanceActionTypeInfo.m_vtable = result;
  hkpConstraintChainInstanceActionTypeInfo.m_scopedName = "!hkpConstraintChainInstanceAction";
  hkpConstraintChainInstanceActionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpConstraintChainInstanceAction;
  hkpConstraintChainInstanceActionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpConstraintChainInstanceAction;
  return result;
}

