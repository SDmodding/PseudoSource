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
    1u);
}

// File Line: 57
// RVA: 0xE33330
hkClass *__fastcall hkxTextureFile::staticClass()
{
  return &hkxTextureFileClass;
}

// File Line: 64
// RVA: 0xE33340
void __fastcall finishLoadedObjecthkxTextureFile(void *p, int finishing)
{
  hkStringPtr *v2; // rbx
  hkStringPtr *v3; // rcx
  int v4; // edi

  if ( p )
  {
    v2 = (hkStringPtr *)p;
    v3 = (hkStringPtr *)((char *)p + 16);
    v3[-2].m_stringAndFlag = (const char *)&hkxTextureFile::`vftable';
    v4 = finishing;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    hkStringPtr::hkStringPtr(v2 + 3, (hkFinishLoadedObjectFlag)v4);
    hkStringPtr::hkStringPtr(v2 + 4, (hkFinishLoadedObjectFlag)v4);
  }
}

// File Line: 70
// RVA: 0xE33390
void __fastcall cleanupLoadedObjecthkxTextureFile(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 74
// RVA: 0xE333A0
void **__fastcall getVtablehkxTextureFile()
{
  hkStringPtr v1; // [rsp+30h] [rbp-28h]
  hkStringPtr v2; // [rsp+38h] [rbp-20h]
  hkStringPtr v3; // [rsp+40h] [rbp-18h]

  hkStringPtr::hkStringPtr(&v1, 0);
  hkStringPtr::hkStringPtr(&v2, 0);
  hkStringPtr::hkStringPtr(&v3, 0);
  return &hkxTextureFile::`vftable';
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
  hkxTextureFileTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxTextureFile;
  hkxTextureFileTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxTextureFile;
  return result;
}

