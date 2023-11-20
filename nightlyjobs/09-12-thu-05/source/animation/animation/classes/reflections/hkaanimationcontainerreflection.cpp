// File Line: 63
// RVA: 0x15BE910
void dynamic_initializer_for__hkaAnimationContainerClass__()
{
  hkClass::hkClass(
    &hkaAnimationContainerClass,
    "hkaAnimationContainer",
    &hkReferencedObjectClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkaAnimationContainerClass_Members,
    5,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 66
// RVA: 0xB1CE60
hkClass *__fastcall hkaAnimationContainer::staticClass()
{
  return &hkaAnimationContainerClass;
}

// File Line: 73
// RVA: 0xB1CE70
void __fastcall finishLoadedObjecthkaAnimationContainer(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaAnimationContainer::`vftable;
}

// File Line: 79
// RVA: 0xB1CE90
void __fastcall cleanupLoadedObjecthkaAnimationContainer(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 83
// RVA: 0xB1CEA0
void **__fastcall getVtablehkaAnimationContainer()
{
  return &hkaAnimationContainer::`vftable;
}

// File Line: 105
// RVA: 0x15BE980
void **dynamic_initializer_for__hkaAnimationContainerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaAnimationContainer();
  hkaAnimationContainerTypeInfo.m_size = 96i64;
  hkaAnimationContainerTypeInfo.m_typeName = "hkaAnimationContainer";
  hkaAnimationContainerTypeInfo.m_vtable = result;
  hkaAnimationContainerTypeInfo.m_scopedName = "!hkaAnimationContainer";
  hkaAnimationContainerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaAnimationContainer;
  hkaAnimationContainerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaAnimationContainer;
  return result;
}

