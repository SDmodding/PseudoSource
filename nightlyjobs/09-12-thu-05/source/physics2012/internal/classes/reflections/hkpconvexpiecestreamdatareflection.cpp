// File Line: 54
// RVA: 0x15D25B0
void dynamic_initializer_for__hkpConvexPieceStreamDataClass__()
{
  hkClass::hkClass(
    &hkpConvexPieceStreamDataClass,
    "hkpConvexPieceStreamData",
    &hkReferencedObjectClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkpConvexPieceStreamDataClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xD99080
hkClass *__fastcall hkpConvexPieceStreamData::staticClass()
{
  return &hkpConvexPieceStreamDataClass;
}

// File Line: 64
// RVA: 0xD99090
void __fastcall finishLoadedObjecthkpConvexPieceStreamData(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpConvexPieceStreamData::`vftable';
}

// File Line: 70
// RVA: 0xD990B0
void __fastcall cleanupLoadedObjecthkpConvexPieceStreamData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 74
// RVA: 0xD990C0
void **__fastcall getVtablehkpConvexPieceStreamData()
{
  return &hkpConvexPieceStreamData::`vftable';
}

// File Line: 96
// RVA: 0x15D2620
void **dynamic_initializer_for__hkpConvexPieceStreamDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpConvexPieceStreamData();
  hkpConvexPieceStreamDataTypeInfo.m_size = 64i64;
  hkpConvexPieceStreamDataTypeInfo.m_typeName = "hkpConvexPieceStreamData";
  hkpConvexPieceStreamDataTypeInfo.m_vtable = result;
  hkpConvexPieceStreamDataTypeInfo.m_scopedName = "!hkpConvexPieceStreamData";
  hkpConvexPieceStreamDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpConvexPieceStreamData;
  hkpConvexPieceStreamDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpConvexPieceStreamData;
  return result;
}

