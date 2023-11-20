// File Line: 57
// RVA: 0x15BE8A0
hkClassEnum *dynamic_initializer_for__hkaAnimationBindingClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaAnimationBindingBlendHintEnum;
  unk_142101258 = hkaAnimationBindingBlendHintEnum;
  return result;
}

// File Line: 95
// RVA: 0x15BE820
void dynamic_initializer_for__hkaAnimationBindingClass__()
{
  hkClass::hkClass(
    &hkaAnimationBindingClass,
    "hkaAnimationBinding",
    &hkReferencedObjectClass,
    88,
    0i64,
    0,
    &hkaAnimationBindingEnums,
    1,
    &hkaAnimationBindingClass_Members,
    6,
    &hkaAnimationBinding_Default,
    0i64,
    0,
    3u);
}

// File Line: 98
// RVA: 0xB1CC90
hkClass *__fastcall hkaAnimationBinding::staticClass()
{
  return &hkaAnimationBindingClass;
}

// File Line: 105
// RVA: 0xB1CCA0
void __fastcall finishLoadedObjecthkaAnimationBinding(void *p, int finishing)
{
  hkStringPtr *v2; // rcx

  if ( p )
  {
    v2 = (hkStringPtr *)((char *)p + 16);
    v2[-2].m_stringAndFlag = (const char *)&hkaAnimationBinding::`vftable;
    hkStringPtr::hkStringPtr(v2, (hkFinishLoadedObjectFlag)finishing);
  }
}

// File Line: 111
// RVA: 0xB1CCD0
void __fastcall cleanupLoadedObjecthkaAnimationBinding(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 115
// RVA: 0xB1CCE0
void **__fastcall getVtablehkaAnimationBinding()
{
  hkStringPtr v1; // [rsp+30h] [rbp-58h]

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkaAnimationBinding::`vftable;
}

// File Line: 137
// RVA: 0x15BE8B0
void **dynamic_initializer_for__hkaAnimationBindingTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaAnimationBinding();
  hkaAnimationBindingTypeInfo.m_size = 88i64;
  hkaAnimationBindingTypeInfo.m_typeName = "hkaAnimationBinding";
  hkaAnimationBindingTypeInfo.m_vtable = result;
  hkaAnimationBindingTypeInfo.m_scopedName = "!hkaAnimationBinding";
  hkaAnimationBindingTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaAnimationBinding;
  hkaAnimationBindingTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaAnimationBinding;
  return result;
}

