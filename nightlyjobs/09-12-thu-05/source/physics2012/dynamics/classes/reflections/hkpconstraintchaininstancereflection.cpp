// File Line: 58
// RVA: 0x15D0B60
void dynamic_initializer_for__hkpConstraintChainInstanceClass__()
{
  hkClass::hkClass(
    &hkpConstraintChainInstanceClass,
    "hkpConstraintChainInstance",
    &hkpConstraintInstanceClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkpConstraintChainInstanceClass_Members,
    3,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 61
// RVA: 0xD50400
hkClass *__fastcall hkpConstraintChainInstance::staticClass()
{
  return &hkpConstraintChainInstanceClass;
}

// File Line: 68
// RVA: 0xD50410
void __fastcall finishLoadedObjecthkpConstraintChainInstance(void *p, int finishing)
{
  _DWORD *v2; // rbx
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v2 = p;
    v3 = (hkStringPtr *)((char *)p + 80);
    v3[-10].m_stringAndFlag = (const char *)&hkpConstraintInstance::`vftable;
    LODWORD(v3[-1].m_stringAndFlag) = 2147483648;
    v3[-2].m_stringAndFlag = 0i64;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    *(_QWORD *)v2 = &hkpConstraintChainInstance::`vftable;
    v2[26] = -16;
  }
}

// File Line: 74
// RVA: 0xD50460
void __fastcall cleanupLoadedObjecthkpConstraintChainInstance(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 78
// RVA: 0xD50470
void **__fastcall getVtablehkpConstraintChainInstance()
{
  hkStringPtr v1; // [rsp+70h] [rbp-48h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkpConstraintChainInstance::`vftable;
}

// File Line: 100
// RVA: 0x15D0BD0
void **dynamic_initializer_for__hkpConstraintChainInstanceTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpConstraintChainInstance();
  hkpConstraintChainInstanceTypeInfo.m_size = 144i64;
  hkpConstraintChainInstanceTypeInfo.m_typeName = "hkpConstraintChainInstance";
  hkpConstraintChainInstanceTypeInfo.m_vtable = result;
  hkpConstraintChainInstanceTypeInfo.m_scopedName = "!hkpConstraintChainInstance";
  hkpConstraintChainInstanceTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpConstraintChainInstance;
  hkpConstraintChainInstanceTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpConstraintChainInstance;
  return result;
}

