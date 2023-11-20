// File Line: 59
// RVA: 0x15C7540
void dynamic_initializer_for__hkMonitorStreamStringMapStringMapClass__()
{
  hkClass::hkClass(
    &hkMonitorStreamStringMapStringMapClass,
    "hkMonitorStreamStringMapStringMap",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkMonitorStreamStringMap_StringMapClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xC55B60
hkClass *__fastcall hkMonitorStreamStringMap::StringMap::staticClass()
{
  return &hkMonitorStreamStringMapStringMapClass;
}

// File Line: 69
// RVA: 0xC55BA0
void __fastcall finishLoadedObjecthkMonitorStreamStringMapStringMap(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkMonitorStreamStringMap::StringMap::StringMap);
}

// File Line: 75
// RVA: 0xC55BC0
void __fastcall cleanupLoadedObjecthkMonitorStreamStringMapStringMap(void *p)
{
  hkStringPtr::~hkStringPtr((hkStringPtr *)p + 1);
}

// File Line: 112
// RVA: 0x15C74E0
void dynamic_initializer_for__hkMonitorStreamStringMapClass__()
{
  hkClass::hkClass(
    &hkMonitorStreamStringMapClass,
    "hkMonitorStreamStringMap",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkMonitorStreamStringMapClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 115
// RVA: 0xC55B50
hkClass *__fastcall hkMonitorStreamStringMap::staticClass()
{
  return &hkMonitorStreamStringMapClass;
}

// File Line: 122
// RVA: 0xC55BD0
void __fastcall finishLoadedObjecthkMonitorStreamStringMap(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkMonitorStreamStringMap::hkMonitorStreamStringMap);
}

// File Line: 128
// RVA: 0xC55BF0
void __fastcall cleanupLoadedObjecthkMonitorStreamStringMap(void *p)
{
  hkMonitorStreamStringMap::~hkMonitorStreamStringMap((hkMonitorStreamStringMap *)p);
}

// File Line: 165
// RVA: 0x15C74D0
hkClassEnum *dynamic_initializer_for__hkMonitorStreamFrameInfoClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkMonitorStreamFrameInfoAbsoluteTimeCounterEnum;
  unk_142109588 = hkMonitorStreamFrameInfoAbsoluteTimeCounterEnum;
  return result;
}

// File Line: 186
// RVA: 0x15C7460
void dynamic_initializer_for__hkMonitorStreamFrameInfoClass__()
{
  hkClass::hkClass(
    &hkMonitorStreamFrameInfoClass,
    "hkMonitorStreamFrameInfo",
    0i64,
    40,
    0i64,
    0,
    &hkMonitorStreamFrameInfoEnums,
    1,
    &hkMonitorStreamFrameInfoClass_Members,
    9,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 189
// RVA: 0xC55B70
hkClass *__fastcall hkMonitorStreamFrameInfo::staticClass()
{
  return &hkMonitorStreamFrameInfoClass;
}

// File Line: 196
// RVA: 0xC55C00
void __fastcall finishLoadedObjecthkMonitorStreamFrameInfo(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkStringPtr::hkStringPtr);
}

// File Line: 202
// RVA: 0xC55C20
void __fastcall cleanupLoadedObjecthkMonitorStreamFrameInfo(void *p)
{
  hkStringPtr::~hkStringPtr((hkStringPtr *)p);
}

// File Line: 238
// RVA: 0x15C73A0
void dynamic_initializer_for__hkMonitorStreamColorTableColorPairClass__()
{
  hkClass::hkClass(
    &hkMonitorStreamColorTableColorPairClass,
    "hkMonitorStreamColorTableColorPair",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkMonitorStreamColorTable_ColorPairClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 241
// RVA: 0xC55B90
hkClass *__fastcall hkMonitorStreamColorTable::ColorPair::staticClass()
{
  return &hkMonitorStreamColorTableColorPairClass;
}

// File Line: 248
// RVA: 0xC55C30
void __fastcall finishLoadedObjecthkMonitorStreamColorTableColorPair(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkStringPtr::hkStringPtr);
}

// File Line: 254
// RVA: 0xC55C50
void __fastcall cleanupLoadedObjecthkMonitorStreamColorTableColorPair(void *p)
{
  hkStringPtr::~hkStringPtr((hkStringPtr *)p);
}

// File Line: 293
// RVA: 0x15C7330
void dynamic_initializer_for__hkMonitorStreamColorTableClass__()
{
  hkClass::hkClass(
    &hkMonitorStreamColorTableClass,
    "hkMonitorStreamColorTable",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkMonitorStreamColorTableClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 296
// RVA: 0xC55B80
hkClass *__fastcall hkMonitorStreamColorTable::staticClass()
{
  return &hkMonitorStreamColorTableClass;
}

// File Line: 303
// RVA: 0xC55C60
void __fastcall finishLoadedObjecthkMonitorStreamColorTable(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkMonitorStreamColorTable::`vftable;
}

// File Line: 309
// RVA: 0xC55C80
void __fastcall cleanupLoadedObjecthkMonitorStreamColorTable(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 313
// RVA: 0xC55C90
void **__fastcall getVtablehkMonitorStreamColorTable()
{
  return &hkMonitorStreamColorTable::`vftable;
}

// File Line: 335
// RVA: 0x15C7400
void **dynamic_initializer_for__hkMonitorStreamColorTableTypeInfo__()
{
  void **result; // rax

  result = getVtablehkMonitorStreamColorTable();
  hkMonitorStreamColorTableTypeInfo.m_size = 40i64;
  hkMonitorStreamColorTableTypeInfo.m_typeName = "hkMonitorStreamColorTable";
  hkMonitorStreamColorTableTypeInfo.m_vtable = result;
  hkMonitorStreamColorTableTypeInfo.m_scopedName = "!hkMonitorStreamColorTable";
  hkMonitorStreamColorTableTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkMonitorStreamColorTable;
  hkMonitorStreamColorTableTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkMonitorStreamColorTable;
  return result;
}

