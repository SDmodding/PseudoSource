// File Line: 67
// RVA: 0x15C3220
void dynamic_initializer_for__hkaiVolumePathfindingUtilFindPathInputClass__()
{
  hkClass::hkClass(
    &hkaiVolumePathfindingUtilFindPathInputClass,
    "hkaiVolumePathfindingUtilFindPathInput",
    &hkReferencedObjectClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkaiVolumePathfindingUtil_FindPathInputClass_Members,
    8,
    0i64,
    0i64,
    0,
    6u);
}

// File Line: 70
// RVA: 0xBB7AA0
hkClass *__fastcall hkaiVolumePathfindingUtil::FindPathInput::staticClass()
{
  return &hkaiVolumePathfindingUtilFindPathInputClass;
}

// File Line: 77
// RVA: 0xBB7AC0
void __fastcall finishLoadedObjecthkaiVolumePathfindingUtilFindPathInput(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiVolumePathfindingUtil::FindPathInput::FindPathInput);
}

// File Line: 83
// RVA: 0xBB7AE0
void __fastcall cleanupLoadedObjecthkaiVolumePathfindingUtilFindPathInput(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 87
// RVA: 0xBB7AF0
hkBaseObjectVtbl *__fastcall getVtablehkaiVolumePathfindingUtilFindPathInput()
{
  hkaiVolumePathfindingUtil::FindPathInput v1; // [rsp+20h] [rbp-98h]

  hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(&v1, 0);
  return v1.vfptr;
}

// File Line: 109
// RVA: 0x15C3290
hkBaseObjectVtbl *dynamic_initializer_for__hkaiVolumePathfindingUtilFindPathInputTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiVolumePathfindingUtilFindPathInput();
  hkaiVolumePathfindingUtilFindPathInputTypeInfo.m_size = 144i64;
  hkaiVolumePathfindingUtilFindPathInputTypeInfo.m_typeName = "hkaiVolumePathfindingUtilFindPathInput";
  hkaiVolumePathfindingUtilFindPathInputTypeInfo.m_vtable = result;
  hkaiVolumePathfindingUtilFindPathInputTypeInfo.m_scopedName = "!hkaiVolumePathfindingUtil::FindPathInput";
  hkaiVolumePathfindingUtilFindPathInputTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiVolumePathfindingUtilFindPathInput;
  hkaiVolumePathfindingUtilFindPathInputTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiVolumePathfindingUtilFindPathInput;
  return result;
}

// File Line: 137
// RVA: 0x15C32F0
void dynamic_initializer_for__hkaiVolumePathfindingUtilFindPathOutputClass__()
{
  hkClass::hkClass(
    &hkaiVolumePathfindingUtilFindPathOutputClass,
    "hkaiVolumePathfindingUtilFindPathOutput",
    &hkReferencedObjectClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkaiVolumePathfindingUtil_FindPathOutputClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 140
// RVA: 0xBB7AB0
hkClass *__fastcall hkaiVolumePathfindingUtil::FindPathOutput::staticClass()
{
  return &hkaiVolumePathfindingUtilFindPathOutputClass;
}

// File Line: 147
// RVA: 0xBB7B20
void __fastcall finishLoadedObjecthkaiVolumePathfindingUtilFindPathOutput(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiVolumePathfindingUtil::FindPathOutput::FindPathOutput);
}

// File Line: 153
// RVA: 0xBB7B40
void __fastcall cleanupLoadedObjecthkaiVolumePathfindingUtilFindPathOutput(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 157
// RVA: 0xBB7B50
hkBaseObjectVtbl *__fastcall getVtablehkaiVolumePathfindingUtilFindPathOutput()
{
  hkaiVolumePathfindingUtil::FindPathOutput v1; // [rsp+20h] [rbp-48h]

  hkaiVolumePathfindingUtil::FindPathOutput::FindPathOutput(&v1, 0);
  return v1.vfptr;
}

// File Line: 179
// RVA: 0x15C3360
hkBaseObjectVtbl *dynamic_initializer_for__hkaiVolumePathfindingUtilFindPathOutputTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiVolumePathfindingUtilFindPathOutput();
  hkaiVolumePathfindingUtilFindPathOutputTypeInfo.m_size = 64i64;
  hkaiVolumePathfindingUtilFindPathOutputTypeInfo.m_typeName = "hkaiVolumePathfindingUtilFindPathOutput";
  hkaiVolumePathfindingUtilFindPathOutputTypeInfo.m_vtable = result;
  hkaiVolumePathfindingUtilFindPathOutputTypeInfo.m_scopedName = "!hkaiVolumePathfindingUtil::FindPathOutput";
  hkaiVolumePathfindingUtilFindPathOutputTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiVolumePathfindingUtilFindPathOutput;
  hkaiVolumePathfindingUtilFindPathOutputTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiVolumePathfindingUtilFindPathOutput;
  return result;
}

// File Line: 200
// RVA: 0x15C31C0
void dynamic_initializer_for__hkaiVolumePathfindingUtilClass__()
{
  hkClass::hkClass(
    &hkaiVolumePathfindingUtilClass,
    "hkaiVolumePathfindingUtil",
    0i64,
    1,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 203
// RVA: 0xBB7A90
hkClass *__fastcall hkaiVolumePathfindingUtil::staticClass()
{
  return &hkaiVolumePathfindingUtilClass;
}

// File Line: 210
// RVA: 0xBB7B70
void __fastcall cleanupLoadedObjecthkaiVolumePathfindingUtil(void *p)
{
  ;
}

