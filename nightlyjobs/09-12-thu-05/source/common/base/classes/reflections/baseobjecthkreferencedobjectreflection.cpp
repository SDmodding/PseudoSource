// File Line: 55
// RVA: 0x15C6740
void dynamic_initializer_for__hkReferencedObjectClass__()
{
  hkClass::hkClass(
    &hkReferencedObjectClass,
    "hkReferencedObject",
    &hkBaseObjectClass,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkReferencedObjectClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xC54E30
hkClass *__fastcall hkReferencedObject::staticClass()
{
  return &hkReferencedObjectClass;
}

// File Line: 65
// RVA: 0xC54E40
void __fastcall finishLoadedObjecthkReferencedObject(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkReferencedObject::`vftable;
}

// File Line: 71
// RVA: 0xC54E60
void __fastcall cleanupLoadedObjecthkReferencedObject(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xC54E70
void **__fastcall getVtablehkReferencedObject()
{
  return &hkReferencedObject::`vftable;
}

// File Line: 97
// RVA: 0x15C67B0
void **dynamic_initializer_for__hkReferencedObjectTypeInfo__()
{
  void **result; // rax

  result = getVtablehkReferencedObject();
  hkReferencedObjectTypeInfo.m_size = 16i64;
  hkReferencedObjectTypeInfo.m_typeName = "hkReferencedObject";
  hkReferencedObjectTypeInfo.m_vtable = result;
  hkReferencedObjectTypeInfo.m_scopedName = "!hkReferencedObject";
  hkReferencedObjectTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkReferencedObject;
  hkReferencedObjectTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkReferencedObject;
  return result;
}

