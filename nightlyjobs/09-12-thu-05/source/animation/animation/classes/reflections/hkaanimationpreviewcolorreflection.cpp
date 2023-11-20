// File Line: 52
// RVA: 0x15BE9E0
void dynamic_initializer_for__hkaAnimationPreviewColorContainerClass__()
{
  hkClass::hkClass(
    &hkaAnimationPreviewColorContainerClass,
    "hkaAnimationPreviewColorContainer",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaAnimationPreviewColorContainerClass_Members,
    1,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 55
// RVA: 0xB1D120
hkClass *__fastcall hkaAnimationPreviewColorContainer::staticClass()
{
  return &hkaAnimationPreviewColorContainerClass;
}

// File Line: 62
// RVA: 0xB1D130
void __fastcall finishLoadedObjecthkaAnimationPreviewColorContainer(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaAnimationPreviewColorContainer::`vftable;
}

// File Line: 68
// RVA: 0xB1D150
void __fastcall cleanupLoadedObjecthkaAnimationPreviewColorContainer(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 72
// RVA: 0xB1D160
void **__fastcall getVtablehkaAnimationPreviewColorContainer()
{
  return &hkaAnimationPreviewColorContainer::`vftable;
}

// File Line: 94
// RVA: 0x15BEA50
void **dynamic_initializer_for__hkaAnimationPreviewColorContainerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaAnimationPreviewColorContainer();
  hkaAnimationPreviewColorContainerTypeInfo.m_size = 32i64;
  hkaAnimationPreviewColorContainerTypeInfo.m_typeName = "hkaAnimationPreviewColorContainer";
  hkaAnimationPreviewColorContainerTypeInfo.m_vtable = result;
  hkaAnimationPreviewColorContainerTypeInfo.m_scopedName = "!hkaAnimationPreviewColorContainer";
  hkaAnimationPreviewColorContainerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaAnimationPreviewColorContainer;
  hkaAnimationPreviewColorContainerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaAnimationPreviewColorContainer;
  return result;
}

