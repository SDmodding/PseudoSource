// File Line: 89
// RVA: 0x15C38B0
hkClassEnum *dynamic_initializer_for__hkaiLineOfSightUtil_InputBaseClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiLineOfSightUtilInputBaseQueryModeEnum;
  unk_142105E18 = hkaiLineOfSightUtilInputBaseQueryModeEnum;
  return result;
}

// File Line: 130
// RVA: 0x15C3750
void dynamic_initializer_for__hkaiLineOfSightUtilInputBaseClass__()
{
  hkClass::hkClass(
    &hkaiLineOfSightUtilInputBaseClass,
    "hkaiLineOfSightUtilInputBase",
    0i64,
    80,
    0i64,
    0,
    &hkaiLineOfSightUtilInputBaseEnums,
    1,
    &hkaiLineOfSightUtil_InputBaseClass_Members,
    14,
    &hkaiLineOfSightUtilInputBase_Default,
    0i64,
    0,
    2u);
}

// File Line: 133
// RVA: 0xBB7CB0
hkClass *__fastcall hkaiLineOfSightUtil::InputBase::staticClass()
{
  return &hkaiLineOfSightUtilInputBaseClass;
}

// File Line: 140
// RVA: 0xBB7CF0
void __fastcall finishLoadedObjecthkaiLineOfSightUtilInputBase(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiLineOfSightUtil::InputBase::InputBase);
}

// File Line: 146
// RVA: 0xBB7D10
void __fastcall cleanupLoadedObjecthkaiLineOfSightUtilInputBase(void *p)
{
  ;
}

// File Line: 184
// RVA: 0x15C37D0
void dynamic_initializer_for__hkaiLineOfSightUtilLineOfSightInputClass__()
{
  hkClass::hkClass(
    &hkaiLineOfSightUtilLineOfSightInputClass,
    "hkaiLineOfSightUtilLineOfSightInput",
    &hkaiLineOfSightUtilInputBaseClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkaiLineOfSightUtil_LineOfSightInputClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 187
// RVA: 0xBB7CC0
hkClass *__fastcall hkaiLineOfSightUtil::LineOfSightInput::staticClass()
{
  return &hkaiLineOfSightUtilLineOfSightInputClass;
}

// File Line: 194
// RVA: 0xBB7D20
void __fastcall finishLoadedObjecthkaiLineOfSightUtilLineOfSightInput(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiLineOfSightUtil::LineOfSightInput::LineOfSightInput);
}

// File Line: 200
// RVA: 0xBB7D40
void __fastcall cleanupLoadedObjecthkaiLineOfSightUtilLineOfSightInput(void *p)
{
  ;
}

// File Line: 237
// RVA: 0x15C36E0
void dynamic_initializer_for__hkaiLineOfSightUtilDirectPathInputClass__()
{
  hkClass::hkClass(
    &hkaiLineOfSightUtilDirectPathInputClass,
    "hkaiLineOfSightUtilDirectPathInput",
    &hkaiLineOfSightUtilInputBaseClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkaiLineOfSightUtil_DirectPathInputClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 240
// RVA: 0xBB7CD0
hkClass *__fastcall hkaiLineOfSightUtil::DirectPathInput::staticClass()
{
  return &hkaiLineOfSightUtilDirectPathInputClass;
}

// File Line: 247
// RVA: 0xBB7D50
void __fastcall finishLoadedObjecthkaiLineOfSightUtilDirectPathInput(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiLineOfSightUtil::DirectPathInput::DirectPathInput);
}

// File Line: 253
// RVA: 0xBB7D70
void __fastcall cleanupLoadedObjecthkaiLineOfSightUtilDirectPathInput(void *p)
{
  ;
}

// File Line: 316
// RVA: 0x15C3840
void dynamic_initializer_for__hkaiLineOfSightUtilLineOfSightOutputClass__()
{
  hkClass::hkClass(
    &hkaiLineOfSightUtilLineOfSightOutputClass,
    "hkaiLineOfSightUtilLineOfSightOutput",
    0i64,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkaiLineOfSightUtil_LineOfSightOutputClass_Members,
    8,
    &hkaiLineOfSightUtilLineOfSightOutput_Default,
    0i64,
    0,
    0);
}

// File Line: 319
// RVA: 0xBB7CE0
hkClass *__fastcall hkaiLineOfSightUtil::LineOfSightOutput::staticClass()
{
  return &hkaiLineOfSightUtilLineOfSightOutputClass;
}

// File Line: 326
// RVA: 0xBB7D80
void __fastcall finishLoadedObjecthkaiLineOfSightUtilLineOfSightOutput(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput);
}

// File Line: 332
// RVA: 0xBB7DA0
void __fastcall cleanupLoadedObjecthkaiLineOfSightUtilLineOfSightOutput(void *p)
{
  hkaiLineOfSightUtil::LineOfSightOutput::~LineOfSightOutput((hkaiLineOfSightUtil::LineOfSightOutput *)p);
}

// File Line: 364
// RVA: 0x15C3680
void dynamic_initializer_for__hkaiLineOfSightUtilClass__()
{
  hkClass::hkClass(
    &hkaiLineOfSightUtilClass,
    "hkaiLineOfSightUtil",
    0i64,
    1,
    0i64,
    0,
    &hkaiLineOfSightUtilEnums,
    1,
    0i64,
    0,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 367
// RVA: 0xBB7CA0
hkClass *__fastcall hkaiLineOfSightUtil::staticClass()
{
  return &hkaiLineOfSightUtilClass;
}

// File Line: 374
// RVA: 0xBB7DB0
void __fastcall cleanupLoadedObjecthkaiLineOfSightUtil(void *p)
{
  ;
}

