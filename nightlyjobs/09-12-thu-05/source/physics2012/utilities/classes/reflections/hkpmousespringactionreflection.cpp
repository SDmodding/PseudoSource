// File Line: 59
// RVA: 0x15D37C0
void dynamic_initializer_for__hkpMouseSpringActionClass__()
{
  hkClass::hkClass(
    &hkpMouseSpringActionClass,
    "hkpMouseSpringAction",
    &hkpUnaryActionClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkpMouseSpringActionClass_Members,
    8,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xE0B1B0
hkClass *__fastcall hkpMouseSpringAction::staticClass()
{
  return &hkpMouseSpringActionClass;
}

// File Line: 69
// RVA: 0xE0B1C0
void __fastcall finishLoadedObjecthkpMouseSpringAction(void *p, int finishing)
{
  _DWORD *v2; // rbx
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v2 = p;
    v3 = (hkStringPtr *)((char *)p + 40);
    v3[-5].m_stringAndFlag = (const char *)&hkpAction::`vftable;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    *(_QWORD *)v2 = &hkpMouseSpringAction::`vftable;
    v2[33] = 2147483648;
    *((_QWORD *)v2 + 15) = 0i64;
    v2[32] = 0;
  }
}

// File Line: 75
// RVA: 0xE0B210
void __fastcall cleanupLoadedObjecthkpMouseSpringAction(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 79
// RVA: 0xE0B220
void **__fastcall getVtablehkpMouseSpringAction()
{
  hkStringPtr v1; // [rsp+48h] [rbp-70h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpMouseSpringAction::`vftable;
}

// File Line: 101
// RVA: 0x15D3830
void **dynamic_initializer_for__hkpMouseSpringActionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpMouseSpringAction();
  hkpMouseSpringActionTypeInfo.m_size = 144i64;
  hkpMouseSpringActionTypeInfo.m_typeName = "hkpMouseSpringAction";
  hkpMouseSpringActionTypeInfo.m_vtable = result;
  hkpMouseSpringActionTypeInfo.m_scopedName = "!hkpMouseSpringAction";
  hkpMouseSpringActionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpMouseSpringAction;
  hkpMouseSpringActionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpMouseSpringAction;
  return result;
}

