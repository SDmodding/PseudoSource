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
    1);
}

// File Line: 81
// RVA: 0xE323B0
hkClass *__fastcall hkxMaterialShader::staticClass()
{
  return &hkxMaterialShaderClass;
}

// File Line: 88
// RVA: 0xE323C0
void __fastcall finishLoadedObjecthkxMaterialShader(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v3 = p + 2;
    v3[-2].m_stringAndFlag = (const char *)&hkxMaterialShader::`vftable;
    hkStringPtr::hkStringPtr(v3, finishing);
    hkStringPtr::hkStringPtr(p + 4, finishing);
    hkStringPtr::hkStringPtr(p + 5, finishing);
    hkStringPtr::hkStringPtr(p + 6, finishing);
  }
}

// File Line: 94
// RVA: 0xE32420
void __fastcall cleanupLoadedObjecthkxMaterialShader(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 98
// RVA: 0xE32430
void **__fastcall getVtablehkxMaterialShader()
{
  hkStringPtr v1; // [rsp+30h] [rbp-48h] BYREF
  hkStringPtr v2; // [rsp+40h] [rbp-38h] BYREF
  hkStringPtr v3; // [rsp+48h] [rbp-30h] BYREF
  hkStringPtr v4; // [rsp+50h] [rbp-28h] BYREF

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
  hkxMaterialShaderTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxMaterialShader;
  hkxMaterialShaderTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxMaterialShader;
  return result;
}

