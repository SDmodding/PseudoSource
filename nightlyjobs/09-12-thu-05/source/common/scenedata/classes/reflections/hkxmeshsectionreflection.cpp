// File Line: 63
// RVA: 0x15D7240
void dynamic_initializer_for__hkxMeshSectionClass__()
{
  hkClass::hkClass(
    &hkxMeshSectionClass,
    "hkxMeshSection",
    &hkReferencedObjectClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkxMeshSectionClass_Members,
    6,
    0i64,
    0i64,
    0,
    4);
}

// File Line: 66
// RVA: 0xE32740
hkClass *__fastcall hkxMeshSection::staticClass()
{
  return &hkxMeshSectionClass;
}

// File Line: 73
// RVA: 0xE32750
void __fastcall finishLoadedObjecthkxMeshSection(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxMeshSection::`vftable;
}

// File Line: 79
// RVA: 0xE32770
void __fastcall cleanupLoadedObjecthkxMeshSection(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 83
// RVA: 0xE32780
void **__fastcall getVtablehkxMeshSection()
{
  return &hkxMeshSection::`vftable;
}

// File Line: 105
// RVA: 0x15D72B0
void **dynamic_initializer_for__hkxMeshSectionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxMeshSection();
  hkxMeshSectionTypeInfo.m_size = 96i64;
  hkxMeshSectionTypeInfo.m_typeName = "hkxMeshSection";
  hkxMeshSectionTypeInfo.m_vtable = result;
  hkxMeshSectionTypeInfo.m_scopedName = "!hkxMeshSection";
  hkxMeshSectionTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxMeshSection;
  hkxMeshSectionTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxMeshSection;
  return result;
}

