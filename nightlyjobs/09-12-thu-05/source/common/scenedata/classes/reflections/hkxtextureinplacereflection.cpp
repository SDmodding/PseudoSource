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
    1u);
}

// File Line: 58
// RVA: 0xE33460
hkClass *__fastcall hkxTextureInplace::staticClass()
{
  return &hkxTextureInplaceClass;
}

// File Line: 65
// RVA: 0xE33470
void __fastcall finishLoadedObjecthkxTextureInplace(void *p, int finishing)
{
  hkStringPtr *v2; // rbx
  hkStringPtr *v3; // rcx
  int v4; // edi

  if ( p )
  {
    v2 = (hkStringPtr *)p;
    v3 = (hkStringPtr *)((char *)p + 40);
    v3[-5].m_stringAndFlag = (const char *)&hkxTextureInplace::`vftable';
    v4 = finishing;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    hkStringPtr::hkStringPtr(v2 + 6, (hkFinishLoadedObjectFlag)v4);
  }
}

// File Line: 71
// RVA: 0xE334C0
void __fastcall cleanupLoadedObjecthkxTextureInplace(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE334D0
void **__fastcall getVtablehkxTextureInplace()
{
  hkStringPtr v1; // [rsp+48h] [rbp-20h]
  hkStringPtr v2; // [rsp+50h] [rbp-18h]

  hkStringPtr::hkStringPtr(&v1, 0);
  hkStringPtr::hkStringPtr(&v2, 0);
  return &hkxTextureInplace::`vftable';
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
  hkxTextureInplaceTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxTextureInplace;
  hkxTextureInplaceTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxTextureInplace;
  return result;
}

