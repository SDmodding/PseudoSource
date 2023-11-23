// File Line: 55
// RVA: 0x15D6330
void dynamic_initializer_for__hkxAttributeHolderClass__()
{
  hkClass::hkClass(
    &hkxAttributeHolderClass,
    "hkxAttributeHolder",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkxAttributeHolderClass_Members,
    1,
    0i64,
    0i64,
    0,
    2);
}

// File Line: 58
// RVA: 0xE317E0
hkClass *__fastcall hkxAttributeHolder::staticClass()
{
  return &hkxAttributeHolderClass;
}

// File Line: 65
// RVA: 0xE317F0
void __fastcall finishLoadedObjecthkxAttributeHolder(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxAttributeHolder::`vftable;
}

// File Line: 71
// RVA: 0xE31810
void __fastcall cleanupLoadedObjecthkxAttributeHolder(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE31820
void **__fastcall getVtablehkxAttributeHolder()
{
  return &hkxAttributeHolder::`vftable;
}

// File Line: 97
// RVA: 0x15D63A0
void **dynamic_initializer_for__hkxAttributeHolderTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxAttributeHolder();
  hkxAttributeHolderTypeInfo.m_size = 32i64;
  hkxAttributeHolderTypeInfo.m_typeName = "hkxAttributeHolder";
  hkxAttributeHolderTypeInfo.m_vtable = result;
  hkxAttributeHolderTypeInfo.m_scopedName = "!hkxAttributeHolder";
  hkxAttributeHolderTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxAttributeHolder;
  hkxAttributeHolderTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxAttributeHolder;
  return result;
}

