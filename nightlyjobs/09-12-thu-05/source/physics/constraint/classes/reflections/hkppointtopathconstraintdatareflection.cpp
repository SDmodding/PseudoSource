// File Line: 60
// RVA: 0x15CD8A0
hkClassEnum *dynamic_initializer_for__hkpPointToPathConstraintData::Members__()
{
  hkClassEnum *result; // rax

  result = hkpPointToPathConstraintDataOrientationConstraintTypeEnum;
  unk_14210F6F8 = hkpPointToPathConstraintDataOrientationConstraintTypeEnum;
  return result;
}

// File Line: 78
// RVA: 0x15CD8B0
void dynamic_initializer_for__hkpPointToPathConstraintDataClass__()
{
  hkClass::hkClass(
    &hkpPointToPathConstraintDataClass,
    "hkpPointToPathConstraintData",
    &hkpConstraintDataClass,
    208,
    0i64,
    0,
    &hkpPointToPathConstraintDataEnums,
    1,
    &hkpPointToPathConstraintData::Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 81
// RVA: 0xD43E70
hkClass *__fastcall hkpPointToPathConstraintData::staticClass()
{
  return &hkpPointToPathConstraintDataClass;
}

// File Line: 88
// RVA: 0xD43E80
void __fastcall finishLoadedObjecthkpPointToPathConstraintData(void *p, int finishing)
{
  int v2; // edi
  hkpBridgeConstraintAtom *v3; // rbx

  if ( p )
  {
    v2 = finishing;
    v3 = (hkpBridgeConstraintAtom *)p;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p, (hkFinishLoadedObjectFlag)finishing);
    *(_QWORD *)&v3->m_type.m_storage = &hkpPointToPathConstraintData::`vftable;
    if ( v2 )
      hkpBridgeConstraintAtom::init(v3 + 1, v3[1].m_constraintData);
  }
}

// File Line: 94
// RVA: 0xD43ED0
void __fastcall cleanupLoadedObjecthkpPointToPathConstraintData(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 98
// RVA: 0xD43EE0
void **__fastcall getVtablehkpPointToPathConstraintData()
{
  hkpConstraintData v1; // [rsp+20h] [rbp-D8h]

  hkpConstraintData::hkpConstraintData(&v1, 0);
  return &hkpPointToPathConstraintData::`vftable;
}

// File Line: 120
// RVA: 0x15CD920
void **dynamic_initializer_for__hkpPointToPathConstraintDataTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpPointToPathConstraintData();
  hkpPointToPathConstraintDataTypeInfo.m_size = 208i64;
  hkpPointToPathConstraintDataTypeInfo.m_typeName = "hkpPointToPathConstraintData";
  hkpPointToPathConstraintDataTypeInfo.m_vtable = result;
  hkpPointToPathConstraintDataTypeInfo.m_scopedName = "!hkpPointToPathConstraintData";
  hkpPointToPathConstraintDataTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpPointToPathConstraintData;
  hkpPointToPathConstraintDataTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpPointToPathConstraintData;
  return result;
}

