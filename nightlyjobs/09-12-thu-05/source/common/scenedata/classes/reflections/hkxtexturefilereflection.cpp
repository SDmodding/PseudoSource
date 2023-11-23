// File Line: 54
// RVA: 0x15D7A70
void dynamic_initializer_for__hkxTextureFileClass__()
{
  hkClass::hkClass(
    &hkxTextureFileClass,
    "hkxTextureFile",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkxTextureFileClass_Members,
    3,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 57
// RVA: 0xE33330
hkClass *__fastcall hkxTextureFile::staticClass()
{
  return &hkxTextureFileClass;
}

// File Line: 64
// RVA: 0xE33340
void __fastcall finishLoadedObjecthkxTextureFile(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v3 = p + 2;
    v3[-2].m_stringAndFlag = (const char *)&hkxTextureFile::`vftable;
    hkStringPtr::hkStringPtr(v3, finishing);
    hkStringPtr::hkStringPtr(p + 3, finishing);
    hkStringPtr::hkStringPtr(p + 4, finishing);
  }
}

// File Line: 70
// RVA: 0xE33390
void __fastcall cleanupLoadedObjecthkxTextureFile(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 74
// RVA: 0xE333A0
void **__fastcall getVtablehkxTextureFile()
{
  hkStringPtr v1; // [rsp+30h] [rbp-28h] BYREF
  hkStringPtr v2; // [rsp+38h] [rbp-20h] BYREF
  hkStringPtr v3; // [rsp+40h] [rbp-18h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  hkStringPtr::hkStringPtr(&v2, 0);
  hkStringPtr::hkStringPtr(&v3, 0);
  return &hkxTextureFile::`vftable;
}

// File Line: 96
// RVA: 0x15D7AE0
void **dynamic_initializer_for__hkxTextureFileTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxTextureFile();
  hkxTextureFileTypeInfo.m_size = 40i64;
  hkxTextureFileTypeInfo.m_typeName = "hkxTextureFile";
  hkxTextureFileTypeInfo.m_vtable = result;
  hkxTextureFileTypeInfo.m_scopedName = "!hkxTextureFile";
  hkxTextureFileTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxTextureFile;
  hkxTextureFileTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxTextureFile;
  return result;
}

