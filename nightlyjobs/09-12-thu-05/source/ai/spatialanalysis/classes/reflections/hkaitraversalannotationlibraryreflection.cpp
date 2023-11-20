// File Line: 45
// RVA: 0x15C49B0
hkClassEnum *dynamic_initializer_for__hkaiTraversalAnnotationLibrary_AnnotationClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiTraversalTypeEnum;
  unk_1421075E0 = hkaiTraversalTypeEnum;
  return result;
}

// File Line: 61
// RVA: 0x15C4880
void dynamic_initializer_for__hkaiTraversalAnnotationLibraryAnnotationClass__()
{
  hkClass::hkClass(
    &hkaiTraversalAnnotationLibraryAnnotationClass,
    "hkaiTraversalAnnotationLibraryAnnotation",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiTraversalAnnotationLibrary_AnnotationClass_Members,
    7,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 64
// RVA: 0xC323B0
hkClass *__fastcall hkaiTraversalAnnotationLibrary::Annotation::staticClass()
{
  return &hkaiTraversalAnnotationLibraryAnnotationClass;
}

// File Line: 71
// RVA: 0xC323C0
void __fastcall cleanupLoadedObjecthkaiTraversalAnnotationLibraryAnnotation(void *p)
{
  ;
}

// File Line: 113
// RVA: 0x15C48E0
void dynamic_initializer_for__hkaiTraversalAnnotationLibraryClass__()
{
  hkClass::hkClass(
    &hkaiTraversalAnnotationLibraryClass,
    "hkaiTraversalAnnotationLibrary",
    &hkReferencedObjectClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkaiTraversalAnnotationLibrary::Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 116
// RVA: 0xC323A0
hkClass *__fastcall hkaiTraversalAnnotationLibrary::staticClass()
{
  return &hkaiTraversalAnnotationLibraryClass;
}

// File Line: 123
// RVA: 0xC323D0
void __fastcall finishLoadedObjecthkaiTraversalAnnotationLibrary(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiTraversalAnnotationLibrary::`vftable;
}

// File Line: 129
// RVA: 0xC323F0
void __fastcall cleanupLoadedObjecthkaiTraversalAnnotationLibrary(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 133
// RVA: 0xC32400
void **__fastcall getVtablehkaiTraversalAnnotationLibrary()
{
  return &hkaiTraversalAnnotationLibrary::`vftable;
}

// File Line: 155
// RVA: 0x15C4950
void **dynamic_initializer_for__hkaiTraversalAnnotationLibraryTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiTraversalAnnotationLibrary();
  hkaiTraversalAnnotationLibraryTypeInfo.m_size = 112i64;
  hkaiTraversalAnnotationLibraryTypeInfo.m_typeName = "hkaiTraversalAnnotationLibrary";
  hkaiTraversalAnnotationLibraryTypeInfo.m_vtable = result;
  hkaiTraversalAnnotationLibraryTypeInfo.m_scopedName = "!hkaiTraversalAnnotationLibrary";
  hkaiTraversalAnnotationLibraryTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiTraversalAnnotationLibrary;
  hkaiTraversalAnnotationLibraryTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiTraversalAnnotationLibrary;
  return result;
}

