// File Line: 52
// RVA: 0x15C6910
void dynamic_initializer_for__hkStringObjectClass__()
{
  hkClass::hkClass(
    &hkStringObjectClass,
    "hkStringObject",
    &hkReferencedObjectClass,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkStringObjectClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 55
// RVA: 0xC54EC0
hkClass *__fastcall hkStringObject::staticClass()
{
  return &hkStringObjectClass;
}

// File Line: 62
// RVA: 0xC54ED0
void __fastcall finishLoadedObjecthkStringObject(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v2; // rcx

  if ( p )
  {
    v2 = p + 2;
    v2[-2].m_stringAndFlag = (const char *)&hkStringObject::`vftable;
    hkStringPtr::hkStringPtr(v2, finishing);
  }
}

// File Line: 68
// RVA: 0xC54F00
void __fastcall cleanupLoadedObjecthkStringObject(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xC54F10
void **__fastcall getVtablehkStringObject()
{
  hkStringPtr v1; // [rsp+30h] [rbp-18h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkStringObject::`vftable;
}

// File Line: 94
// RVA: 0x15C6980
void **dynamic_initializer_for__hkStringObjectTypeInfo__()
{
  void **result; // rax

  result = getVtablehkStringObject();
  hkStringObjectTypeInfo.m_size = 24i64;
  hkStringObjectTypeInfo.m_typeName = "hkStringObject";
  hkStringObjectTypeInfo.m_vtable = result;
  hkStringObjectTypeInfo.m_scopedName = "!hkStringObject";
  hkStringObjectTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkStringObject;
  hkStringObjectTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkStringObject;
  return result;
}

