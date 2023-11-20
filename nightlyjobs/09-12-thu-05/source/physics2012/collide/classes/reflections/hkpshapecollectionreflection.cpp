// File Line: 58
// RVA: 0x15C97B0
hkClassEnum *dynamic_initializer_for__hkpShapeCollectionClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpShapeCollectionCollectionTypeEnum;
  unk_14210C218 = hkpShapeCollectionCollectionTypeEnum;
  return result;
}

// File Line: 96
// RVA: 0x15C9730
void dynamic_initializer_for__hkpShapeCollectionClass__()
{
  hkClass::hkClass(
    &hkpShapeCollectionClass,
    "hkpShapeCollection",
    &hkpShapeClass,
    48,
    0i64,
    1,
    &hkpShapeCollectionEnums,
    1,
    &hkpShapeCollectionClass_Members,
    2,
    &hkpShapeCollection_Default,
    0i64,
    0,
    0);
}

// File Line: 99
// RVA: 0xCEAED0
hkClass *__fastcall hkpShapeCollection::staticClass()
{
  return &hkpShapeCollectionClass;
}

