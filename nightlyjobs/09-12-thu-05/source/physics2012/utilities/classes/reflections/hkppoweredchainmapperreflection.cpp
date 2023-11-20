// File Line: 58
// RVA: 0x15D3B00
void dynamic_initializer_for__hkpPoweredChainMapperTargetClass__()
{
  hkClass::hkClass(
    &hkpPoweredChainMapperTargetClass,
    "hkpPoweredChainMapperTarget",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpPoweredChainMapper_TargetClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xE0B4B0
hkClass *__fastcall hkpPoweredChainMapper::Target::staticClass()
{
  return &hkpPoweredChainMapperTargetClass;
}

// File Line: 68
// RVA: 0xE0B4D0
void __fastcall cleanupLoadedObjecthkpPoweredChainMapperTarget(void *p)
{
  ;
}

// File Line: 105
// RVA: 0x15D3AA0
void dynamic_initializer_for__hkpPoweredChainMapperLinkInfoClass__()
{
  hkClass::hkClass(
    &hkpPoweredChainMapperLinkInfoClass,
    "hkpPoweredChainMapperLinkInfo",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpPoweredChainMapper_LinkInfoClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 108
// RVA: 0xE0B4C0
hkClass *__fastcall hkpPoweredChainMapper::LinkInfo::staticClass()
{
  return &hkpPoweredChainMapperLinkInfoClass;
}

// File Line: 115
// RVA: 0xE0B4E0
void __fastcall cleanupLoadedObjecthkpPoweredChainMapperLinkInfo(void *p)
{
  ;
}

// File Line: 155
// RVA: 0x15D3A30
void dynamic_initializer_for__hkpPoweredChainMapperClass__()
{
  hkClass::hkClass(
    &hkpPoweredChainMapperClass,
    "hkpPoweredChainMapper",
    &hkReferencedObjectClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkpPoweredChainMapperClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 158
// RVA: 0xE0B4A0
hkClass *__fastcall hkpPoweredChainMapper::staticClass()
{
  return &hkpPoweredChainMapperClass;
}

// File Line: 165
// RVA: 0xE0B4F0
void __fastcall finishLoadedObjecthkpPoweredChainMapper(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpPoweredChainMapper::`vftable';
}

// File Line: 171
// RVA: 0xE0B510
void __fastcall cleanupLoadedObjecthkpPoweredChainMapper(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 175
// RVA: 0xE0B520
void **__fastcall getVtablehkpPoweredChainMapper()
{
  return &hkpPoweredChainMapper::`vftable';
}

// File Line: 197
// RVA: 0x15D3B60
void **dynamic_initializer_for__hkpPoweredChainMapperTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpPoweredChainMapper();
  hkpPoweredChainMapperTypeInfo.m_size = 64i64;
  hkpPoweredChainMapperTypeInfo.m_typeName = "hkpPoweredChainMapper";
  hkpPoweredChainMapperTypeInfo.m_vtable = result;
  hkpPoweredChainMapperTypeInfo.m_scopedName = "!hkpPoweredChainMapper";
  hkpPoweredChainMapperTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpPoweredChainMapper;
  hkpPoweredChainMapperTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpPoweredChainMapper;
  return result;
}

