// File Line: 55
// RVA: 0x15D6FD0
void dynamic_initializer_for__hkxMaterialShaderSetClass__()
{
  hkClass::hkClass(
    &hkxMaterialShaderSetClass,
    "hkxMaterialShaderSet",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkxMaterialShaderSetClass_Members,
    1,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 58
// RVA: 0xE32560
hkClass *__fastcall hkxMaterialShaderSet::staticClass()
{
  return &hkxMaterialShaderSetClass;
}

// File Line: 65
// RVA: 0xE32570
void __fastcall finishLoadedObjecthkxMaterialShaderSet(hkxMaterialShaderSet *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkxMaterialShaderSet::hkxMaterialShaderSet(p, finishing);
}

// File Line: 71
// RVA: 0xE32590
void __fastcall cleanupLoadedObjecthkxMaterialShaderSet(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE325A0
hkBaseObjectVtbl *__fastcall getVtablehkxMaterialShaderSet()
{
  hkxMaterialShaderSet v1; // [rsp+20h] [rbp-28h] BYREF

  hkxMaterialShaderSet::hkxMaterialShaderSet(&v1, 0);
  return v1.vfptr;
}

// File Line: 97
// RVA: 0x15D7040
hkBaseObjectVtbl *dynamic_initializer_for__hkxMaterialShaderSetTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkxMaterialShaderSet();
  hkxMaterialShaderSetTypeInfo.m_size = 32i64;
  hkxMaterialShaderSetTypeInfo.m_typeName = "hkxMaterialShaderSet";
  hkxMaterialShaderSetTypeInfo.m_vtable = result;
  hkxMaterialShaderSetTypeInfo.m_scopedName = "!hkxMaterialShaderSet";
  hkxMaterialShaderSetTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxMaterialShaderSet;
  hkxMaterialShaderSetTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxMaterialShaderSet;
  return result;
}

