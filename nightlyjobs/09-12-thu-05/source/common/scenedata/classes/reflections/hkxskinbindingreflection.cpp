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
    2);
}

// File Line: 63
// RVA: 0xE32D80
hkClass *__fastcall hkxSkinBinding::staticClass()
{
  return &hkxSkinBindingClass;
}

// File Line: 70
// RVA: 0xE32D90
void __fastcall finishLoadedObjecthkxSkinBinding(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxSkinBinding::`vftable;
}

// File Line: 76
// RVA: 0xE32DB0
void __fastcall cleanupLoadedObjecthkxSkinBinding(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 80
// RVA: 0xE32DC0
void **__fastcall getVtablehkxSkinBinding()
{
  return &hkxSkinBinding::`vftable;
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
  hkxSkinBindingTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxSkinBinding;
  hkxSkinBindingTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxSkinBinding;
  return result;
}

