// File Line: 55
// RVA: 0x15D2400
void dynamic_initializer_for__hkpMoppCodeReindexedTerminalClass__()
{
  hkClass::hkClass(
    &hkpMoppCodeReindexedTerminalClass,
    "hkpMoppCodeReindexedTerminal",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkpMoppCodeReindexedTerminalClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xD98EE0
hkClass *__fastcall hkpMoppCodeReindexedTerminal::staticClass()
{
  return &hkpMoppCodeReindexedTerminalClass;
}

// File Line: 65
// RVA: 0xD98F10
void __fastcall cleanupLoadedObjecthkpMoppCodeReindexedTerminal(void *p)
{
  ;
}

// File Line: 114
// RVA: 0x15D23A0
void dynamic_initializer_for__hkpMoppCodeCodeInfoClass__()
{
  hkClass::hkClass(
    &hkpMoppCodeCodeInfoClass,
    "hkpMoppCodeCodeInfo",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpMoppCode_CodeInfoClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 117
// RVA: 0xD98F00
hkClass *__fastcall hkpMoppCode::CodeInfo::staticClass()
{
  return &hkpMoppCodeCodeInfoClass;
}

// File Line: 124
// RVA: 0xD98F20
void __fastcall cleanupLoadedObjecthkpMoppCodeCodeInfo(void *p)
{
  ;
}

// File Line: 147
// RVA: 0x15D2390
hkClassEnum *dynamic_initializer_for__hkpMoppCodeClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpMoppCodeBuildTypeEnum;
  unk_1421127B0 = hkpMoppCodeBuildTypeEnum;
  return result;
}

// File Line: 185
// RVA: 0x15D2310
void dynamic_initializer_for__hkpMoppCodeClass__()
{
  hkClass::hkClass(
    &hkpMoppCodeClass,
    "hkpMoppCode",
    &hkReferencedObjectClass,
    64,
    0i64,
    0,
    &hkpMoppCodeEnums,
    1,
    &hkpMoppCodeClass_Members,
    3,
    &hkpMoppCode_Default,
    0i64,
    0,
    0);
}

// File Line: 188
// RVA: 0xD98EF0
hkClass *__fastcall hkpMoppCode::staticClass()
{
  return &hkpMoppCodeClass;
}

// File Line: 195
// RVA: 0xD98F30
void __fastcall finishLoadedObjecthkpMoppCode(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpMoppCode::`vftable;
}

// File Line: 201
// RVA: 0xD98F50
void __fastcall cleanupLoadedObjecthkpMoppCode(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 205
// RVA: 0xD98F60
void **__fastcall getVtablehkpMoppCode()
{
  return &hkpMoppCode::`vftable;
}

// File Line: 227
// RVA: 0x15D2460
void **dynamic_initializer_for__hkpMoppCodeTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpMoppCode();
  hkpMoppCodeTypeInfo.m_size = 64i64;
  hkpMoppCodeTypeInfo.m_typeName = "hkpMoppCode";
  hkpMoppCodeTypeInfo.m_vtable = result;
  hkpMoppCodeTypeInfo.m_scopedName = "!hkpMoppCode";
  hkpMoppCodeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpMoppCode;
  hkpMoppCodeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpMoppCode;
  return result;
}

