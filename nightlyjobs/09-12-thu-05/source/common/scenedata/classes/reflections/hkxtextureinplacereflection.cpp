// File Line: 55
// RVA: 0x15D7B40
void dynamic_initializer_for__hkxTextureInplaceClass__()
{
  hkClass::hkClass(
    &hkxTextureInplaceClass,
    "hkxTextureInplace",
    &hkReferencedObjectClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkxTextureInplaceClass_Members,
    4,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 58
// RVA: 0xE33460
hkClass *__fastcall hkxTextureInplace::staticClass()
{
  return &hkxTextureInplaceClass;
}

// File Line: 65
// RVA: 0xE33470
void __fastcall finishLoadedObjecthkxTextureInplace(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v3 = p + 5;
    v3[-5].m_stringAndFlag = (const char *)&hkxTextureInplace::`vftable;
    hkStringPtr::hkStringPtr(v3, finishing);
    hkStringPtr::hkStringPtr(p + 6, finishing);
  }
}

// File Line: 71
// RVA: 0xE334C0
void __fastcall cleanupLoadedObjecthkxTextureInplace(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE334D0
void **__fastcall getVtablehkxTextureInplace()
{
  hkStringPtr v1; // [rsp+48h] [rbp-20h] BYREF
  hkStringPtr v2; // [rsp+50h] [rbp-18h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  hkStringPtr::hkStringPtr(&v2, 0);
  return &hkxTextureInplace::`vftable;
}

// File Line: 97
// RVA: 0x15D7BB0
void **dynamic_initializer_for__hkxTextureInplaceTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxTextureInplace();
  hkxTextureInplaceTypeInfo.m_size = 56i64;
  hkxTextureInplaceTypeInfo.m_typeName = "hkxTextureInplace";
  hkxTextureInplaceTypeInfo.m_vtable = result;
  hkxTextureInplaceTypeInfo.m_scopedName = "!hkxTextureInplace";
  hkxTextureInplaceTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxTextureInplace;
  hkxTextureInplaceTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxTextureInplace;
  return result;
}

