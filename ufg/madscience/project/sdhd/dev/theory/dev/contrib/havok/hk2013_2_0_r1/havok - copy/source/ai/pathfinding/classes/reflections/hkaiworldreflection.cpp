// File Line: 79
// RVA: 0x15C1BB0
void dynamic_initializer_for__hkaiNavMeshPathRequestInfoClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshPathRequestInfoClass,
    "hkaiNavMeshPathRequestInfo",
    &hkReferencedObjectClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshPathRequestInfo::Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 82
// RVA: 0xBB6BE0
hkClass *__fastcall hkaiNavMeshPathRequestInfo::staticClass()
{
  return &hkaiNavMeshPathRequestInfoClass;
}

// File Line: 89
// RVA: 0xBB6C20
void __fastcall finishLoadedObjecthkaiNavMeshPathRequestInfo(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiNavMeshPathRequestInfo::`vftable;
}

// File Line: 95
// RVA: 0xBB6C40
void __fastcall cleanupLoadedObjecthkaiNavMeshPathRequestInfo(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 99
// RVA: 0xBB6C50
void **__fastcall getVtablehkaiNavMeshPathRequestInfo()
{
  return &hkaiNavMeshPathRequestInfo::`vftable;
}

// File Line: 121
// RVA: 0x15C1C20
void **dynamic_initializer_for__hkaiNavMeshPathRequestInfoTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiNavMeshPathRequestInfo();
  hkaiNavMeshPathRequestInfoTypeInfo.m_size = 56i64;
  hkaiNavMeshPathRequestInfoTypeInfo.m_typeName = "hkaiNavMeshPathRequestInfo";
  hkaiNavMeshPathRequestInfoTypeInfo.m_vtable = result;
  hkaiNavMeshPathRequestInfoTypeInfo.m_scopedName = "!hkaiNavMeshPathRequestInfo";
  hkaiNavMeshPathRequestInfoTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiNavMeshPathRequestInfo;
  hkaiNavMeshPathRequestInfoTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiNavMeshPathRequestInfo;
  return result;
}

// File Line: 150
// RVA: 0x15C1C80
void dynamic_initializer_for__hkaiNavVolumePathRequestInfoClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumePathRequestInfoClass,
    "hkaiNavVolumePathRequestInfo",
    &hkReferencedObjectClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolumePathRequestInfo::Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 153
// RVA: 0xBB6BF0
hkClass *__fastcall hkaiNavVolumePathRequestInfo::staticClass()
{
  return &hkaiNavVolumePathRequestInfoClass;
}

// File Line: 160
// RVA: 0xBB6C60
void __fastcall finishLoadedObjecthkaiNavVolumePathRequestInfo(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiNavVolumePathRequestInfo::`vftable;
}

// File Line: 166
// RVA: 0xBB6C80
void __fastcall cleanupLoadedObjecthkaiNavVolumePathRequestInfo(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 170
// RVA: 0xBB6C90
void **__fastcall getVtablehkaiNavVolumePathRequestInfo()
{
  return &hkaiNavVolumePathRequestInfo::`vftable;
}

// File Line: 192
// RVA: 0x15C1CF0
void **dynamic_initializer_for__hkaiNavVolumePathRequestInfoTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiNavVolumePathRequestInfo();
  hkaiNavVolumePathRequestInfoTypeInfo.m_size = 56i64;
  hkaiNavVolumePathRequestInfoTypeInfo.m_typeName = "hkaiNavVolumePathRequestInfo";
  hkaiNavVolumePathRequestInfoTypeInfo.m_vtable = result;
  hkaiNavVolumePathRequestInfoTypeInfo.m_scopedName = "!hkaiNavVolumePathRequestInfo";
  hkaiNavVolumePathRequestInfoTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiNavVolumePathRequestInfo;
  hkaiNavVolumePathRequestInfoTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiNavVolumePathRequestInfo;
  return result;
}

// File Line: 239
// RVA: 0x15C1F00
hkClassEnum *dynamic_initializer_for__hkaiWorld_CharacterStepSerializableContextClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiWorldCharacterCallbackTypeEnum;
  unk_142104E38 = hkaiWorldCharacterCallbackTypeEnum;
  return result;
}

// File Line: 281
// RVA: 0x15C1D50
void dynamic_initializer_for__hkaiWorldCharacterStepSerializableContextClass__()
{
  hkClass::hkClass(
    &hkaiWorldCharacterStepSerializableContextClass,
    "hkaiWorldCharacterStepSerializableContext",
    &hkReferencedObjectClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkaiWorld_CharacterStepSerializableContextClass_Members,
    6,
    &hkaiWorldCharacterStepSerializableContext_Default,
    0i64,
    0,
    2u);
}

// File Line: 284
// RVA: 0xBB6C10
hkClass *__fastcall hkaiWorld::CharacterStepSerializableContext::staticClass()
{
  return &hkaiWorldCharacterStepSerializableContextClass;
}

// File Line: 291
// RVA: 0xBB6CA0
void __fastcall finishLoadedObjecthkaiWorldCharacterStepSerializableContext(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiWorld::CharacterStepSerializableContext::CharacterStepSerializableContext);
}

// File Line: 297
// RVA: 0xBB6CC0
void __fastcall cleanupLoadedObjecthkaiWorldCharacterStepSerializableContext(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 301
// RVA: 0xBB6CD0
hkBaseObjectVtbl *__fastcall getVtablehkaiWorldCharacterStepSerializableContext()
{
  hkaiWorld::CharacterStepSerializableContext v1; // [rsp+20h] [rbp-58h]

  hkaiWorld::CharacterStepSerializableContext::CharacterStepSerializableContext(&v1, 0);
  return v1.vfptr;
}

// File Line: 323
// RVA: 0x15C1DC0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiWorldCharacterStepSerializableContextTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiWorldCharacterStepSerializableContext();
  hkaiWorldCharacterStepSerializableContextTypeInfo.m_size = 80i64;
  hkaiWorldCharacterStepSerializableContextTypeInfo.m_typeName = "hkaiWorldCharacterStepSerializableContext";
  hkaiWorldCharacterStepSerializableContextTypeInfo.m_vtable = result;
  hkaiWorldCharacterStepSerializableContextTypeInfo.m_scopedName = "!hkaiWorld::CharacterStepSerializableContext";
  hkaiWorldCharacterStepSerializableContextTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiWorldCharacterStepSerializableContext;
  hkaiWorldCharacterStepSerializableContextTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiWorldCharacterStepSerializableContext;
  return result;
}

// File Line: 397
// RVA: 0x15C1E20
void dynamic_initializer_for__hkaiWorldClass__()
{
  hkClass::hkClass(
    &hkaiWorldClass,
    "hkaiWorld",
    &hkReferencedObjectClass,
    640,
    0i64,
    0,
    &hkaiWorldEnums,
    3,
    &hkaiWorld::Members,
    29,
    &hkaiWorld_Default,
    0i64,
    0,
    0x20u);
}

// File Line: 400
// RVA: 0xBB6C00
hkClass *__fastcall hkaiWorld::staticClass()
{
  return &hkaiWorldClass;
}

// File Line: 407
// RVA: 0xBB6CF0
void __fastcall finishLoadedObjecthkaiWorld(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiWorld::hkaiWorld);
}

// File Line: 413
// RVA: 0xBB6D10
void __fastcall cleanupLoadedObjecthkaiWorld(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 417
// RVA: 0xBB6D20
hkBaseObjectVtbl *__fastcall getVtablehkaiWorld()
{
  hkaiWorld v1; // [rsp+20h] [rbp-288h]

  hkaiWorld::hkaiWorld(&v1, 0);
  return v1.vfptr;
}

// File Line: 439
// RVA: 0x15C1EA0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiWorldTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiWorld();
  hkaiWorldTypeInfo.m_size = 640i64;
  hkaiWorldTypeInfo.m_typeName = "hkaiWorld";
  hkaiWorldTypeInfo.m_vtable = result;
  hkaiWorldTypeInfo.m_scopedName = "!hkaiWorld";
  hkaiWorldTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiWorld;
  hkaiWorldTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiWorld;
  return result;
}

