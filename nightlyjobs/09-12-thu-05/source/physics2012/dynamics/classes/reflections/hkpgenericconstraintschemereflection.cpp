// File Line: 59
// RVA: 0x15CFDD0
void dynamic_initializer_for__hkpGenericConstraintDataSchemeConstraintInfoClass__()
{
  hkClass::hkClass(
    &hkpGenericConstraintDataSchemeConstraintInfoClass,
    "hkpGenericConstraintDataSchemeConstraintInfo",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpGenericConstraintDataScheme_ConstraintInfoClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xD4FB80
hkClass *__fastcall hkpGenericConstraintDataScheme::ConstraintInfo::staticClass()
{
  return &hkpGenericConstraintDataSchemeConstraintInfoClass;
}

// File Line: 69
// RVA: 0xD4FBA0
void __fastcall cleanupLoadedObjecthkpGenericConstraintDataSchemeConstraintInfo(void *p)
{
  ;
}

// File Line: 109
// RVA: 0x15CFD70
void dynamic_initializer_for__hkpGenericConstraintDataSchemeClass__()
{
  hkClass::hkClass(
    &hkpGenericConstraintDataSchemeClass,
    "hkpGenericConstraintDataScheme",
    0i64,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpGenericConstraintDataSchemeClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 112
// RVA: 0xD4FB90
hkClass *__fastcall hkpGenericConstraintDataScheme::staticClass()
{
  return &hkpGenericConstraintDataSchemeClass;
}

// File Line: 119
// RVA: 0xD4FBB0
void __fastcall finishLoadedObjecthkpGenericConstraintDataScheme(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpGenericConstraintDataScheme::hkpGenericConstraintDataScheme);
}

// File Line: 125
// RVA: 0xD4FBD0
void __fastcall cleanupLoadedObjecthkpGenericConstraintDataScheme(void *p)
{
  hkpGenericConstraintDataScheme::~hkpGenericConstraintDataScheme((hkpGenericConstraintDataScheme *)p);
}

