// File Line: 121
// RVA: 0x15C6870
hkClassEnum *dynamic_initializer_for__hkClassMember::Members__()
{
  hkClassEnum *result; // rax

  unk_142108E58 = hkClassMemberTypeEnum;
  unk_142108E80 = hkClassMemberTypeEnum;
  result = hkClassMemberFlagValuesEnum;
  unk_142108ED0 = hkClassMemberFlagValuesEnum;
  return result;
}

// File Line: 143
// RVA: 0x15C68A0
void dynamic_initializer_for__hkClassMemberClass__()
{
  hkClass::hkClass(
    &hkClassMemberClass,
    "hkClassMember",
    0i64,
    40,
    0i64,
    0,
    &hkClassMemberEnums,
    3,
    &hkClassMember::Members,
    9,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 146
// RVA: 0xC54EA0
hkClass *__fastcall hkClassMember::staticClass()
{
  return &hkClassMemberClass;
}

// File Line: 153
// RVA: 0xC54EB0
void __fastcall cleanupLoadedObjecthkClassMember(void *p)
{
  ;
}

