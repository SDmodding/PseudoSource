// File Line: 56
// RVA: 0x15D7440
void dynamic_initializer_for__hkxNodeSelectionSetClass__()
{
  hkClass::hkClass(
    &hkxNodeSelectionSetClass,
    "hkxNodeSelectionSet",
    &hkxAttributeHolderClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkxNodeSelectionSetClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xE32AF0
hkClass *__fastcall hkxNodeSelectionSet::staticClass()
{
  return &hkxNodeSelectionSetClass;
}

// File Line: 66
// RVA: 0xE32B00
void __fastcall finishLoadedObjecthkxNodeSelectionSet(void *p, int finishing)
{
  hkStringPtr *v2; // rcx

  if ( p )
  {
    v2 = (hkStringPtr *)((char *)p + 48);
    v2[-6].m_stringAndFlag = (const char *)&hkxNodeSelectionSet::`vftable';
    hkStringPtr::hkStringPtr(v2, (hkFinishLoadedObjectFlag)finishing);
  }
}

// File Line: 72
// RVA: 0xE32B30
void __fastcall cleanupLoadedObjecthkxNodeSelectionSet(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xE32B40
void **__fastcall getVtablehkxNodeSelectionSet()
{
  hkStringPtr v1; // [rsp+50h] [rbp-18h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkxNodeSelectionSet::`vftable';
}

// File Line: 98
// RVA: 0x15D74B0
void **dynamic_initializer_for__hkxNodeSelectionSetTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxNodeSelectionSet();
  hkxNodeSelectionSetTypeInfo.m_size = 56i64;
  hkxNodeSelectionSetTypeInfo.m_typeName = "hkxNodeSelectionSet";
  hkxNodeSelectionSetTypeInfo.m_vtable = result;
  hkxNodeSelectionSetTypeInfo.m_scopedName = "!hkxNodeSelectionSet";
  hkxNodeSelectionSetTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxNodeSelectionSet;
  hkxNodeSelectionSetTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxNodeSelectionSet;
  return result;
}

