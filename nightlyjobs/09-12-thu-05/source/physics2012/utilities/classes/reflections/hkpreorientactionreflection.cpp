// File Line: 55
// RVA: 0x15D3C90
void dynamic_initializer_for__hkpReorientActionClass__()
{
  hkClass::hkClass(
    &hkpReorientActionClass,
    "hkpReorientAction",
    &hkpUnaryActionClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkpReorientActionClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xE0B700
hkClass *__fastcall hkpReorientAction::staticClass()
{
  return &hkpReorientActionClass;
}

// File Line: 65
// RVA: 0xE0B710
void __fastcall finishLoadedObjecthkpReorientAction(void *p, int finishing)
{
  _QWORD *v2; // rbx
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v2 = p;
    v3 = (hkStringPtr *)((char *)p + 40);
    v3[-5].m_stringAndFlag = (const char *)&hkpAction::`vftable;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpReorientAction::`vftable;
  }
}

// File Line: 71
// RVA: 0xE0B750
void __fastcall cleanupLoadedObjecthkpReorientAction(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE0B760
void **__fastcall getVtablehkpReorientAction()
{
  hkStringPtr v1; // [rsp+48h] [rbp-50h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpReorientAction::`vftable;
}

// File Line: 97
// RVA: 0x15D3D00
void **dynamic_initializer_for__hkpReorientActionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpReorientAction();
  hkpReorientActionTypeInfo.m_size = 112i64;
  hkpReorientActionTypeInfo.m_typeName = "hkpReorientAction";
  hkpReorientActionTypeInfo.m_vtable = result;
  hkpReorientActionTypeInfo.m_scopedName = "!hkpReorientAction";
  hkpReorientActionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpReorientAction;
  hkpReorientActionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpReorientAction;
  return result;
}

