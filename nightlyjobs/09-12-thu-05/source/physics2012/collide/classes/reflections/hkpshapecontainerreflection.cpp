// File Line: 49
// RVA: 0x15CAAF0
void dynamic_initializer_for__hkpShapeContainerClass__()
{
  hkClass::hkClass(&hkpShapeContainerClass, "hkpShapeContainer", 0i64, 8, 0i64, 1, 0i64, 0, 0i64, 0, 0i64, 0i64, 0, 0);
}

// File Line: 52
// RVA: 0xCEBEB0
hkClass *__fastcall hkpShapeContainer::staticClass()
{
  return &hkpShapeContainerClass;
}

// File Line: 80
// RVA: 0x15CAB50
void dynamic_initializer_for__hkpSingleShapeContainerClass__()
{
  hkClass::hkClass(
    &hkpSingleShapeContainerClass,
    "hkpSingleShapeContainer",
    &hkpShapeContainerClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpSingleShapeContainer::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 83
// RVA: 0xCEBEC0
hkClass *__fastcall hkpSingleShapeContainer::staticClass()
{
  return &hkpSingleShapeContainerClass;
}

// File Line: 90
// RVA: 0xCEBED0
void __fastcall finishLoadedObjecthkpSingleShapeContainer(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpSingleShapeContainer::`vftable;
}

// File Line: 96
// RVA: 0xCEBEF0
void __fastcall cleanupLoadedObjecthkpSingleShapeContainer(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 100
// RVA: 0xCEBF00
void **__fastcall getVtablehkpSingleShapeContainer()
{
  return &hkpSingleShapeContainer::`vftable;
}

// File Line: 122
// RVA: 0x15CABC0
void **dynamic_initializer_for__hkpSingleShapeContainerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpSingleShapeContainer();
  hkpSingleShapeContainerTypeInfo.m_size = 16i64;
  hkpSingleShapeContainerTypeInfo.m_typeName = "hkpSingleShapeContainer";
  hkpSingleShapeContainerTypeInfo.m_vtable = result;
  hkpSingleShapeContainerTypeInfo.m_scopedName = "!hkpSingleShapeContainer";
  hkpSingleShapeContainerTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpSingleShapeContainer;
  hkpSingleShapeContainerTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpSingleShapeContainer;
  return result;
}

