// File Line: 58
// RVA: 0x15C0850
void dynamic_initializer_for__hkaiSilhouetteGenerationParametersClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteGenerationParametersClass,
    "hkaiSilhouetteGenerationParameters",
    0i64,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkaiSilhouetteGenerationParametersClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xBB6120
hkClass *__fastcall hkaiSilhouetteGenerationParameters::staticClass()
{
  return &hkaiSilhouetteGenerationParametersClass;
}

// File Line: 68
// RVA: 0xBB6160
void __fastcall finishLoadedObjecthkaiSilhouetteGenerationParameters(void *p, int finishing)
{
  ;
}

// File Line: 74
// RVA: 0xBB6170
void __fastcall cleanupLoadedObjecthkaiSilhouetteGenerationParameters(void *p)
{
  ;
}

// File Line: 108
// RVA: 0x15C0780
hkClassEnum *dynamic_initializer_for__hkaiSilhouetteMerger::Members__()
{
  hkClassEnum *result; // rax

  result = hkaiSilhouetteMergerMergeTypeEnum;
  hkaiSilhouetteMerger::Members.m_enum = hkaiSilhouetteMergerMergeTypeEnum;
  return result;
}

// File Line: 126
// RVA: 0x15C08B0
void dynamic_initializer_for__hkaiSilhouetteMergerClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteMergerClass,
    "hkaiSilhouetteMerger",
    &hkReferencedObjectClass,
    96,
    0i64,
    0,
    &hkaiSilhouetteMergerEnums,
    1,
    &hkaiSilhouetteMerger::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 129
// RVA: 0xBB6130
hkClass *__fastcall hkaiSilhouetteMerger::staticClass()
{
  return &hkaiSilhouetteMergerClass;
}

// File Line: 136
// RVA: 0xBB6180
void __fastcall finishLoadedObjecthkaiSilhouetteMerger(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiSilhouetteMerger::`vftable;
}

// File Line: 142
// RVA: 0xBB61A0
void __fastcall cleanupLoadedObjecthkaiSilhouetteMerger(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 146
// RVA: 0xBB61B0
void **__fastcall getVtablehkaiSilhouetteMerger()
{
  return &hkaiSilhouetteMerger::`vftable;
}

// File Line: 168
// RVA: 0x15C0920
void **dynamic_initializer_for__hkaiSilhouetteMergerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiSilhouetteMerger();
  hkaiSilhouetteMergerTypeInfo.m_size = 96i64;
  hkaiSilhouetteMergerTypeInfo.m_typeName = "hkaiSilhouetteMerger";
  hkaiSilhouetteMergerTypeInfo.m_vtable = result;
  hkaiSilhouetteMergerTypeInfo.m_scopedName = "!hkaiSilhouetteMerger";
  hkaiSilhouetteMergerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiSilhouetteMerger;
  hkaiSilhouetteMergerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiSilhouetteMerger;
  return result;
}

// File Line: 190
// RVA: 0x15C0980
void dynamic_initializer_for__hkaiSimpleSilhouetteMergerClass__()
{
  hkClass::hkClass(
    &hkaiSimpleSilhouetteMergerClass,
    "hkaiSimpleSilhouetteMerger",
    &hkaiSilhouetteMergerClass,
    96,
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

// File Line: 193
// RVA: 0xBB6140
hkClass *__fastcall hkaiSimpleSilhouetteMerger::staticClass()
{
  return &hkaiSimpleSilhouetteMergerClass;
}

// File Line: 200
// RVA: 0xBB61C0
void __fastcall finishLoadedObjecthkaiSimpleSilhouetteMerger(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiSimpleSilhouetteMerger::`vftable;
}

// File Line: 206
// RVA: 0xBB61E0
void __fastcall cleanupLoadedObjecthkaiSimpleSilhouetteMerger(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 210
// RVA: 0xBB61F0
void **__fastcall getVtablehkaiSimpleSilhouetteMerger()
{
  return &hkaiSimpleSilhouetteMerger::`vftable;
}

// File Line: 232
// RVA: 0x15C09E0
void **dynamic_initializer_for__hkaiSimpleSilhouetteMergerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiSimpleSilhouetteMerger();
  hkaiSimpleSilhouetteMergerTypeInfo.m_size = 96i64;
  hkaiSimpleSilhouetteMergerTypeInfo.m_typeName = "hkaiSimpleSilhouetteMerger";
  hkaiSimpleSilhouetteMergerTypeInfo.m_vtable = result;
  hkaiSimpleSilhouetteMergerTypeInfo.m_scopedName = "!hkaiSimpleSilhouetteMerger";
  hkaiSimpleSilhouetteMergerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiSimpleSilhouetteMerger;
  hkaiSimpleSilhouetteMergerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiSimpleSilhouetteMerger;
  return result;
}

// File Line: 254
// RVA: 0x15C0790
void dynamic_initializer_for__hkaiConvexHullSilhouetteMergerClass__()
{
  hkClass::hkClass(
    &hkaiConvexHullSilhouetteMergerClass,
    "hkaiConvexHullSilhouetteMerger",
    &hkaiSilhouetteMergerClass,
    96,
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

// File Line: 257
// RVA: 0xBB6150
hkClass *__fastcall hkaiConvexHullSilhouetteMerger::staticClass()
{
  return &hkaiConvexHullSilhouetteMergerClass;
}

// File Line: 264
// RVA: 0xBB6200
void __fastcall finishLoadedObjecthkaiConvexHullSilhouetteMerger(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiConvexHullSilhouetteMerger::`vftable;
}

// File Line: 270
// RVA: 0xBB6220
void __fastcall cleanupLoadedObjecthkaiConvexHullSilhouetteMerger(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 274
// RVA: 0xBB6230
void **__fastcall getVtablehkaiConvexHullSilhouetteMerger()
{
  return &hkaiConvexHullSilhouetteMerger::`vftable;
}

// File Line: 296
// RVA: 0x15C07F0
void **dynamic_initializer_for__hkaiConvexHullSilhouetteMergerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiConvexHullSilhouetteMerger();
  hkaiConvexHullSilhouetteMergerTypeInfo.m_size = 96i64;
  hkaiConvexHullSilhouetteMergerTypeInfo.m_typeName = "hkaiConvexHullSilhouetteMerger";
  hkaiConvexHullSilhouetteMergerTypeInfo.m_vtable = result;
  hkaiConvexHullSilhouetteMergerTypeInfo.m_scopedName = "!hkaiConvexHullSilhouetteMerger";
  hkaiConvexHullSilhouetteMergerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiConvexHullSilhouetteMerger;
  hkaiConvexHullSilhouetteMergerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiConvexHullSilhouetteMerger;
  return result;
}

