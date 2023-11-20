// File Line: 69
// RVA: 0x15C2650
hkClassEnum *dynamic_initializer_for__hkaiPath_PathPointClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiPathPathPointBitsEnum;
  unk_1421051E0 = hkaiPathPathPointBitsEnum;
  return result;
}

// File Line: 85
// RVA: 0x15C2580
void dynamic_initializer_for__hkaiPathPathPointClass__()
{
  hkClass::hkClass(
    &hkaiPathPathPointClass,
    "hkaiPathPathPoint",
    0i64,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkaiPath_PathPointClass_Members,
    5,
    0i64,
    0i64,
    0,
    3u);
}

// File Line: 88
// RVA: 0xBB7110
hkClass *__fastcall hkaiPath::PathPoint::staticClass()
{
  return &hkaiPathPathPointClass;
}

// File Line: 95
// RVA: 0xBB7130
void __fastcall cleanupLoadedObjecthkaiPathPathPoint(void *p)
{
  ;
}

// File Line: 117
// RVA: 0x15C24F0
hkClassEnum *dynamic_initializer_for__hkaiPath::Members__()
{
  hkClassEnum *result; // rax

  result = hkaiPathReferenceFrameEnum;
  unk_142105118 = hkaiPathReferenceFrameEnum;
  return result;
}

// File Line: 154
// RVA: 0x15C2500
void dynamic_initializer_for__hkaiPathClass__()
{
  hkClass::hkClass(
    &hkaiPathClass,
    "hkaiPath",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    &hkaiPathEnums,
    2,
    &hkaiPath::Members,
    2,
    &hkaiPath_Default,
    0i64,
    0,
    0xAu);
}

// File Line: 157
// RVA: 0xBB7120
hkClass *__fastcall hkaiPath::staticClass()
{
  return &hkaiPathClass;
}

// File Line: 164
// RVA: 0xBB7140
void __fastcall finishLoadedObjecthkaiPath(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiPath::`vftable';
}

// File Line: 170
// RVA: 0xBB7160
void __fastcall cleanupLoadedObjecthkaiPath(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 174
// RVA: 0xBB7170
void **__fastcall getVtablehkaiPath()
{
  return &hkaiPath::`vftable';
}

// File Line: 196
// RVA: 0x15C25F0
void **dynamic_initializer_for__hkaiPathTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiPath();
  hkaiPathTypeInfo.m_size = 40i64;
  hkaiPathTypeInfo.m_typeName = "hkaiPath";
  hkaiPathTypeInfo.m_vtable = result;
  hkaiPathTypeInfo.m_scopedName = "!hkaiPath";
  hkaiPathTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiPath;
  hkaiPathTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiPath;
  return result;
}

