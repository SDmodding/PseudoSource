// File Line: 57
// RVA: 0x15D6F60
hkClassEnum *dynamic_initializer_for__hkxMaterialShaderClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkxMaterialShaderShaderTypeEnum;
  unk_1421157D8 = hkxMaterialShaderShaderTypeEnum;
  return result;
}

// File Line: 78
// RVA: 0x15D6EF0
void dynamic_initializer_for__hkxMaterialShaderClass__()
{
  hkClass::hkClass(
    &hkxMaterialShaderClass,
    "hkxMaterialShader",
    &hkReferencedObjectClass,
    72,
    0i64,
    0,
    &hkxMaterialShaderEnums,
    1,
    &hkxMaterialShaderClass_Members,
    6,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 81
// RVA: 0xE323B0
hkClass *__fastcall hkxMaterialShader::staticClass()
{
  return &hkxMaterialShaderClass;
}

// File Line: 88
// RVA: 0xE323C0
void __fastcall finishLoadedObjecthkxMaterialShader(void *p, int finishing)
{
  hkStringPtr *v2; // rbx
  hkStringPtr *v3; // rcx
  int v4; // edi

  if ( p )
  {
    v2 = (hkStringPtr *)p;
    v3 = (hkStringPtr *)((char *)p + 16);
    v3[-2].m_stringAndFlag = (const char *)&hkxMaterialShader::`vftable;
    v4 = finishing;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    hkStringPtr::hkStringPtr(v2 + 4, (hkFinishLoadedObjectFlag)v4);
    hkStringPtr::hkStringPtr(v2 + 5, (hkFinishLoadedObjectFlag)v4);
    hkStringPtr::hkStringPtr(v2 + 6, (hkFinishLoadedObjectFlag)v4);
  }
}

// File Line: 94
// RVA: 0xE32420
void __fastcall cleanupLoadedObjecthkxMaterialShader(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 98
// RVA: 0xE32430
void **__fastcall getVtablehkxMaterialShader()
{
  hkStringPtr v1; // [rsp+30h] [rbp-48h]
  hkStringPtr v2; // [rsp+40h] [rbp-38h]
  hkStringPtr v3; // [rsp+48h] [rbp-30h]
  hkStringPtr v4; // [rsp+50h] [rbp-28h]

  hkStringPtr::hkStringPtr(&v1, 0);
  hkStringPtr::hkStringPtr(&v2, 0);
  hkStringPtr::hkStringPtr(&v3, 0);
  hkStringPtr::hkStringPtr(&v4, 0);
  return &hkxMaterialShader::`vftable;
}

// File Line: 120
// RVA: 0x15D6F70
void **dynamic_initializer_for__hkxMaterialShaderTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxMaterialShader();
  hkxMaterialShaderTypeInfo.m_size = 72i64;
  hkxMaterialShaderTypeInfo.m_typeName = "hkxMaterialShader";
  hkxMaterialShaderTypeInfo.m_vtable = result;
  hkxMaterialShaderTypeInfo.m_scopedName = "!hkxMaterialShader";
  hkxMaterialShaderTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxMaterialShader;
  hkxMaterialShaderTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxMaterialShader;
  return result;
}

