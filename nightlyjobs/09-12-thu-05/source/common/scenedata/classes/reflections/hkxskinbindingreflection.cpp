// File Line: 60
// RVA: 0x15D75E0
void dynamic_initializer_for__hkxSkinBindingClass__()
{
  hkClass::hkClass(
    &hkxSkinBindingClass,
    "hkxSkinBinding",
    &hkReferencedObjectClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkxSkinBindingClass_Members,
    4,
    0i64,
    0i64,
    0,
    2u);
}

// File Line: 63
// RVA: 0xE32D80
hkClass *__fastcall hkxSkinBinding::staticClass()
{
  return &hkxSkinBindingClass;
}

// File Line: 70
// RVA: 0xE32D90
void __fastcall finishLoadedObjecthkxSkinBinding(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkxSkinBinding::`vftable';
}

// File Line: 76
// RVA: 0xE32DB0
void __fastcall cleanupLoadedObjecthkxSkinBinding(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 80
// RVA: 0xE32DC0
void **__fastcall getVtablehkxSkinBinding()
{
  return &hkxSkinBinding::`vftable';
}

// File Line: 102
// RVA: 0x15D7650
void **dynamic_initializer_for__hkxSkinBindingTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxSkinBinding();
  hkxSkinBindingTypeInfo.m_size = 128i64;
  hkxSkinBindingTypeInfo.m_typeName = "hkxSkinBinding";
  hkxSkinBindingTypeInfo.m_vtable = result;
  hkxSkinBindingTypeInfo.m_scopedName = "!hkxSkinBinding";
  hkxSkinBindingTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxSkinBinding;
  hkxSkinBindingTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxSkinBinding;
  return result;
}

