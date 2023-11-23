// File Line: 62
// RVA: 0x15C23C0
void dynamic_initializer_for__hkaiOverlapManagerSectionGeneratorDataClass__()
{
  hkClass::hkClass(
    &hkaiOverlapManagerSectionGeneratorDataClass,
    "hkaiOverlapManagerSectionGeneratorData",
    &hkReferencedObjectClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkaiOverlapManagerSection_GeneratorDataClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 65
// RVA: 0xBB6F60
hkClass *__fastcall hkaiOverlapManagerSection::GeneratorData::staticClass()
{
  return &hkaiOverlapManagerSectionGeneratorDataClass;
}

// File Line: 72
// RVA: 0xBB6F80
void __fastcall finishLoadedObjecthkaiOverlapManagerSectionGeneratorData(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkaiOverlapManagerSection::GeneratorData::`vftable;
}

// File Line: 78
// RVA: 0xBB6FA0
void __fastcall cleanupLoadedObjecthkaiOverlapManagerSectionGeneratorData(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 82
// RVA: 0xBB6FB0
void **__fastcall getVtablehkaiOverlapManagerSectionGeneratorData()
{
  return &hkaiOverlapManagerSection::GeneratorData::`vftable;
}

// File Line: 104
// RVA: 0x15C2430
void **dynamic_initializer_for__hkaiOverlapManagerSectionGeneratorDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiOverlapManagerSectionGeneratorData();
  hkaiOverlapManagerSectionGeneratorDataTypeInfo.m_size = 80i64;
  hkaiOverlapManagerSectionGeneratorDataTypeInfo.m_typeName = "hkaiOverlapManagerSectionGeneratorData";
  hkaiOverlapManagerSectionGeneratorDataTypeInfo.m_vtable = result;
  hkaiOverlapManagerSectionGeneratorDataTypeInfo.m_scopedName = "!hkaiOverlapManagerSection::GeneratorData";
  hkaiOverlapManagerSectionGeneratorDataTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiOverlapManagerSectionGeneratorData;
  hkaiOverlapManagerSectionGeneratorDataTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiOverlapManagerSectionGeneratorData;
  return result;
}

// File Line: 134
// RVA: 0x15C2350
void dynamic_initializer_for__hkaiOverlapManagerSectionClass__()
{
  hkClass::hkClass(
    &hkaiOverlapManagerSectionClass,
    "hkaiOverlapManagerSection",
    0i64,
    72,
    0i64,
    0,
    0i64,
    0,
    &hkaiOverlapManagerSectionClass_Members,
    5,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 137
// RVA: 0xBB6F50
hkClass *__fastcall hkaiOverlapManagerSection::staticClass()
{
  return &hkaiOverlapManagerSectionClass;
}

// File Line: 144
// RVA: 0xBB6FC0
void __fastcall finishLoadedObjecthkaiOverlapManagerSection(_DWORD *p, int finishing)
{
  if ( p )
  {
    p[11] = 0x80000000;
    *((_QWORD *)p + 4) = 0i64;
    p[10] = 0;
  }
}

// File Line: 150
// RVA: 0xBB6FE0
// attributes: thunk
void __fastcall cleanupLoadedObjecthkaiOverlapManagerSection(hkaiOverlapManagerSection *p)
{
  hkaiOverlapManagerSection::~hkaiOverlapManagerSection(p);
}

// File Line: 229
// RVA: 0x15C22D0
void dynamic_initializer_for__hkaiOverlapManagerClass__()
{
  hkClass::hkClass(
    &hkaiOverlapManagerClass,
    "hkaiOverlapManager",
    &hkReferencedObjectClass,
    128,
    0i64,
    1,
    &hkaiOverlapManagerEnums,
    1,
    &hkaiOverlapManager::Members,
    8,
    &hkaiOverlapManager_Default,
    0i64,
    0,
    1);
}

// File Line: 232
// RVA: 0xBB6F70
hkClass *__fastcall hkaiOverlapManager::staticClass()
{
  return &hkaiOverlapManagerClass;
}

// File Line: 239
// RVA: 0xBB6FF0
void __fastcall finishLoadedObjecthkaiOverlapManager(hkaiOverlapManager *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiOverlapManager::hkaiOverlapManager(p, finishing);
}

// File Line: 245
// RVA: 0xBB7010
void __fastcall cleanupLoadedObjecthkaiOverlapManager(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 249
// RVA: 0xBB7020
hkBaseObjectVtbl *__fastcall getVtablehkaiOverlapManager()
{
  hkaiOverlapManager v1; // [rsp+20h] [rbp-88h] BYREF

  hkaiOverlapManager::hkaiOverlapManager(&v1, 0);
  return v1.hkReferencedObject::hkBaseObject::vfptr;
}

// File Line: 271
// RVA: 0x15C2490
hkBaseObjectVtbl *dynamic_initializer_for__hkaiOverlapManagerTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiOverlapManager();
  hkaiOverlapManagerTypeInfo.m_size = 128i64;
  hkaiOverlapManagerTypeInfo.m_typeName = "hkaiOverlapManager";
  hkaiOverlapManagerTypeInfo.m_vtable = result;
  hkaiOverlapManagerTypeInfo.m_scopedName = "!hkaiOverlapManager";
  hkaiOverlapManagerTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiOverlapManager;
  hkaiOverlapManagerTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiOverlapManager;
  return result;
}

