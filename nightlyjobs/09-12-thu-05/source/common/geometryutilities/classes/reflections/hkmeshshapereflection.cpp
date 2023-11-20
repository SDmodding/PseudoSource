// File Line: 53
// RVA: 0x15DF420
void dynamic_initializer_for__hkMeshMaterialClass__()
{
  hkClass::hkClass(
    &hkMeshMaterialClass,
    "hkMeshMaterial",
    &hkReferencedObjectClass,
    16,
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

// File Line: 56
// RVA: 0x1319560
hkClass *__fastcall hkMeshMaterial::staticClass()
{
  return &hkMeshMaterialClass;
}

// File Line: 94
// RVA: 0x15DF580
hkClassEnum *dynamic_initializer_for__hkMeshSectionClass_Members__()
{
  hkClassEnum *result; // rax

  hkMeshSectionClass_Members.m_enum = hkMeshSectionPrimitiveTypeEnum;
  result = hkMeshSectionMeshSectionIndexTypeEnum;
  unk_142128298 = hkMeshSectionMeshSectionIndexTypeEnum;
  return result;
}

// File Line: 120
// RVA: 0x15DF510
void dynamic_initializer_for__hkMeshSectionClass__()
{
  hkClass::hkClass(
    &hkMeshSectionClass,
    "hkMeshSection",
    0i64,
    56,
    0i64,
    0,
    &hkMeshSectionEnums,
    2,
    &hkMeshSectionClass_Members,
    10,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 123
// RVA: 0x1319570
hkClass *__fastcall hkMeshSection::staticClass()
{
  return &hkMeshSectionClass;
}

// File Line: 130
// RVA: 0x13195A0
void __fastcall cleanupLoadedObjecthkMeshSection(void *p)
{
  ;
}

// File Line: 151
// RVA: 0x15DF4F0
hkClassEnum *dynamic_initializer_for__hkMeshSectionCinfoClass_Members__()
{
  hkClassEnum *result; // rax

  unk_1421283E0 = hkMeshSectionPrimitiveTypeEnum;
  result = hkMeshSectionMeshSectionIndexTypeEnum;
  unk_142128430 = hkMeshSectionMeshSectionIndexTypeEnum;
  return result;
}

// File Line: 173
// RVA: 0x15DF480
void dynamic_initializer_for__hkMeshSectionCinfoClass__()
{
  hkClass::hkClass(
    &hkMeshSectionCinfoClass,
    "hkMeshSectionCinfo",
    0i64,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkMeshSectionCinfoClass_Members,
    8,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 176
// RVA: 0x1319580
hkClass *__fastcall hkMeshSectionCinfo::staticClass()
{
  return &hkMeshSectionCinfoClass;
}

// File Line: 183
// RVA: 0x13195B0
void __fastcall cleanupLoadedObjecthkMeshSectionCinfo(void *p)
{
  ;
}

// File Line: 229
// RVA: 0x15DF5A0
void dynamic_initializer_for__hkMeshShapeClass__()
{
  hkClass::hkClass(
    &hkMeshShapeClass,
    "hkMeshShape",
    &hkReferencedObjectClass,
    16,
    0i64,
    0,
    &hkMeshShapeEnums,
    1,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 232
// RVA: 0x1319590
hkClass *__fastcall hkMeshShape::staticClass()
{
  return &hkMeshShapeClass;
}

