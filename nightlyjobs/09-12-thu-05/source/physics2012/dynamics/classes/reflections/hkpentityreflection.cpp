// File Line: 79
// RVA: 0x15D0F70
void dynamic_initializer_for__hkpEntitySmallArraySerializeOverrideTypeClass__()
{
  hkClass::hkClass(
    &hkpEntitySmallArraySerializeOverrideTypeClass,
    "hkpEntitySmallArraySerializeOverrideType",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpEntity_SmallArraySerializeOverrideTypeClass_Members,
    3,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 82
// RVA: 0xD50C10
hkClass *__fastcall hkpEntity::SmallArraySerializeOverrideType::staticClass()
{
  return &hkpEntitySmallArraySerializeOverrideTypeClass;
}

// File Line: 89
// RVA: 0xD50C40
void __fastcall cleanupLoadedObjecthkpEntitySmallArraySerializeOverrideType(void *p)
{
  ;
}

// File Line: 127
// RVA: 0x15D0FE0
void dynamic_initializer_for__hkpEntitySpuCollisionCallbackClass__()
{
  hkClass::hkClass(
    &hkpEntitySpuCollisionCallbackClass,
    "hkpEntitySpuCollisionCallback",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpEntity_SpuCollisionCallbackClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 130
// RVA: 0xD50C20
hkClass *__fastcall hkpEntity::SpuCollisionCallback::staticClass()
{
  return &hkpEntitySpuCollisionCallbackClass;
}

// File Line: 137
// RVA: 0xD50C50
void __fastcall finishLoadedObjecthkpEntitySpuCollisionCallback(void *p, int finishing)
{
  ;
}

// File Line: 143
// RVA: 0xD50C60
void __fastcall cleanupLoadedObjecthkpEntitySpuCollisionCallback(void *p)
{
  ;
}

// File Line: 179
// RVA: 0x15D0F10
void dynamic_initializer_for__hkpEntityExtendedListenersClass__()
{
  hkClass::hkClass(
    &hkpEntityExtendedListenersClass,
    "hkpEntityExtendedListeners",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpEntity_ExtendedListenersClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 182
// RVA: 0xD50C30
hkClass *__fastcall hkpEntity::ExtendedListeners::staticClass()
{
  return &hkpEntityExtendedListenersClass;
}

// File Line: 189
// RVA: 0xD50C70
// attributes: thunk
void __fastcall cleanupLoadedObjecthkpEntityExtendedListeners(hkpEntity::ExtendedListeners *p)
{
  hkpEntity::ExtendedListeners::~ExtendedListeners(p);
}

// File Line: 277
// RVA: 0x15D0E90
void dynamic_initializer_for__hkpEntityClass__()
{
  hkClass::hkClass(
    &hkpEntityClass,
    "hkpEntity",
    &hkpWorldObjectClass,
    720,
    0i64,
    0,
    &hkpEntityEnums,
    1,
    &hkpEntity::Members,
    22,
    &hkpEntity_Default,
    0i64,
    0,
    3);
}

// File Line: 280
// RVA: 0xD50C00
hkClass *__fastcall hkpEntity::staticClass()
{
  return &hkpEntityClass;
}

// File Line: 287
// RVA: 0xD50C80
void __fastcall finishLoadedObjecthkpEntity(hkpEntity *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpEntity::hkpEntity(p, finishing);
}

// File Line: 293
// RVA: 0xD50CA0
void __fastcall cleanupLoadedObjecthkpEntity(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 297
// RVA: 0xD50CB0
hkBaseObjectVtbl *__fastcall getVtablehkpEntity()
{
  hkpEntity v1; // [rsp+20h] [rbp-2D8h] BYREF

  hkpEntity::hkpEntity(&v1, 0);
  return v1.vfptr;
}

// File Line: 319
// RVA: 0x15D1040
hkBaseObjectVtbl *dynamic_initializer_for__hkpEntityTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpEntity();
  hkpEntityTypeInfo.m_size = 720i64;
  hkpEntityTypeInfo.m_typeName = "hkpEntity";
  hkpEntityTypeInfo.m_vtable = result;
  hkpEntityTypeInfo.m_scopedName = "!hkpEntity";
  hkpEntityTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpEntity;
  hkpEntityTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpEntity;
  return result;
}

