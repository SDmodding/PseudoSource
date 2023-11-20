// File Line: 57
// RVA: 0x15CC8A0
hkClassEnum *dynamic_initializer_for__hkpCollisionFilterClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpCollisionFilterhkpFilterTypeEnum;
  unk_14210D898 = hkpCollisionFilterhkpFilterTypeEnum;
  return result;
}

// File Line: 75
// RVA: 0x15CC830
void dynamic_initializer_for__hkpCollisionFilterClass__()
{
  hkClass::hkClass(
    &hkpCollisionFilterClass,
    "hkpCollisionFilter",
    &hkReferencedObjectClass,
    72,
    0i64,
    4,
    &hkpCollisionFilterEnums,
    1,
    &hkpCollisionFilterClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 78
// RVA: 0xCECE70
hkClass *__fastcall hkpCollisionFilter::staticClass()
{
  return &hkpCollisionFilterClass;
}

