// File Line: 106
// RVA: 0x15C2800
void dynamic_initializer_for__hkaiPathfindingUtilFindPathInputClass__()
{
  hkClass::hkClass(
    &hkaiPathfindingUtilFindPathInputClass,
    "hkaiPathfindingUtilFindPathInput",
    &hkReferencedObjectClass,
    192,
    0i64,
    0,
    0i64,
    0,
    &hkaiPathfindingUtil_FindPathInputClass_Members,
    9,
    &hkaiPathfindingUtilFindPathInput_Default,
    0i64,
    0,
    10);
}

// File Line: 109
// RVA: 0xBB7280
hkClass *__fastcall hkaiPathfindingUtil::FindPathInput::staticClass()
{
  return &hkaiPathfindingUtilFindPathInputClass;
}

// File Line: 116
// RVA: 0xBB72B0
void __fastcall finishLoadedObjecthkaiPathfindingUtilFindPathInput(
        hkaiPathfindingUtil::FindPathInput *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiPathfindingUtil::FindPathInput::FindPathInput(p, finishing);
}

// File Line: 122
// RVA: 0xBB72D0
void __fastcall cleanupLoadedObjecthkaiPathfindingUtilFindPathInput(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 126
// RVA: 0xBB72E0
hkBaseObjectVtbl *__fastcall getVtablehkaiPathfindingUtilFindPathInput()
{
  hkaiPathfindingUtil::FindPathInput v1; // [rsp+20h] [rbp-C8h] BYREF

  hkaiPathfindingUtil::FindPathInput::FindPathInput(&v1, 0);
  return v1.vfptr;
}

// File Line: 148
// RVA: 0x15C2870
hkBaseObjectVtbl *dynamic_initializer_for__hkaiPathfindingUtilFindPathInputTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiPathfindingUtilFindPathInput();
  hkaiPathfindingUtilFindPathInputTypeInfo.m_size = 192i64;
  hkaiPathfindingUtilFindPathInputTypeInfo.m_typeName = "hkaiPathfindingUtilFindPathInput";
  hkaiPathfindingUtilFindPathInputTypeInfo.m_vtable = result;
  hkaiPathfindingUtilFindPathInputTypeInfo.m_scopedName = "!hkaiPathfindingUtil::FindPathInput";
  hkaiPathfindingUtilFindPathInputTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiPathfindingUtilFindPathInput;
  hkaiPathfindingUtilFindPathInputTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiPathfindingUtilFindPathInput;
  return result;
}

// File Line: 176
// RVA: 0x15C28D0
void dynamic_initializer_for__hkaiPathfindingUtilFindPathOutputClass__()
{
  hkClass::hkClass(
    &hkaiPathfindingUtilFindPathOutputClass,
    "hkaiPathfindingUtilFindPathOutput",
    &hkReferencedObjectClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkaiPathfindingUtil_FindPathOutputClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 179
// RVA: 0xBB7290
hkClass *__fastcall hkaiPathfindingUtil::FindPathOutput::staticClass()
{
  return &hkaiPathfindingUtilFindPathOutputClass;
}

// File Line: 186
// RVA: 0xBB7310
void __fastcall finishLoadedObjecthkaiPathfindingUtilFindPathOutput(
        hkaiPathfindingUtil::FindPathOutput *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiPathfindingUtil::FindPathOutput::FindPathOutput(p, finishing);
}

// File Line: 192
// RVA: 0xBB7330
void __fastcall cleanupLoadedObjecthkaiPathfindingUtilFindPathOutput(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 196
// RVA: 0xBB7340
hkBaseObjectVtbl *__fastcall getVtablehkaiPathfindingUtilFindPathOutput()
{
  hkaiPathfindingUtil::FindPathOutput v1; // [rsp+20h] [rbp-48h] BYREF

  hkaiPathfindingUtil::FindPathOutput::FindPathOutput(&v1, 0);
  return v1.vfptr;
}

// File Line: 218
// RVA: 0x15C2940
hkBaseObjectVtbl *dynamic_initializer_for__hkaiPathfindingUtilFindPathOutputTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiPathfindingUtilFindPathOutput();
  hkaiPathfindingUtilFindPathOutputTypeInfo.m_size = 64i64;
  hkaiPathfindingUtilFindPathOutputTypeInfo.m_typeName = "hkaiPathfindingUtilFindPathOutput";
  hkaiPathfindingUtilFindPathOutputTypeInfo.m_vtable = result;
  hkaiPathfindingUtilFindPathOutputTypeInfo.m_scopedName = "!hkaiPathfindingUtil::FindPathOutput";
  hkaiPathfindingUtilFindPathOutputTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiPathfindingUtilFindPathOutput;
  hkaiPathfindingUtilFindPathOutputTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiPathfindingUtilFindPathOutput;
  return result;
}

// File Line: 272
// RVA: 0x15C2790
void dynamic_initializer_for__hkaiPathfindingUtilFindGraphPathInputClass__()
{
  hkClass::hkClass(
    &hkaiPathfindingUtilFindGraphPathInputClass,
    "hkaiPathfindingUtilFindGraphPathInput",
    0i64,
    152,
    0i64,
    0,
    0i64,
    0,
    &hkaiPathfindingUtil_FindGraphPathInputClass_Members,
    9,
    &hkaiPathfindingUtilFindGraphPathInput_Default,
    0i64,
    0,
    2);
}

// File Line: 275
// RVA: 0xBB72A0
hkClass *__fastcall hkaiPathfindingUtil::FindGraphPathInput::staticClass()
{
  return &hkaiPathfindingUtilFindGraphPathInputClass;
}

// File Line: 282
// RVA: 0xBB7360
void __fastcall finishLoadedObjecthkaiPathfindingUtilFindGraphPathInput(
        hkaiPathfindingUtil::FindGraphPathInput *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiPathfindingUtil::FindGraphPathInput::FindGraphPathInput(p, finishing);
}

// File Line: 288
// RVA: 0xBB7380
// attributes: thunk
void __fastcall cleanupLoadedObjecthkaiPathfindingUtilFindGraphPathInput(hkaiPathfindingUtil::FindGraphPathInput *p)
{
  hkaiPathfindingUtil::FindGraphPathInput::~FindGraphPathInput(p);
}

// File Line: 320
// RVA: 0x15C2730
void dynamic_initializer_for__hkaiPathfindingUtilClass__()
{
  hkClass::hkClass(
    &hkaiPathfindingUtilClass,
    "hkaiPathfindingUtil",
    0i64,
    1,
    0i64,
    0,
    &hkaiPathfindingUtilEnums,
    1,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 323
// RVA: 0xBB7270
hkClass *__fastcall hkaiPathfindingUtil::staticClass()
{
  return &hkaiPathfindingUtilClass;
}

// File Line: 330
// RVA: 0xBB7390
void __fastcall cleanupLoadedObjecthkaiPathfindingUtil(void *p)
{
  ;
}

