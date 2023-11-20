// File Line: 53
// RVA: 0x15C6B70
void dynamic_initializer_for__hkCustomAttributesAttributeClass__()
{
  hkClass::hkClass(
    &hkCustomAttributesAttributeClass,
    "hkCustomAttributesAttribute",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkCustomAttributes_AttributeClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 56
// RVA: 0xC54FD0
hkClass *__fastcall hkCustomAttributes::Attribute::staticClass()
{
  return &hkCustomAttributesAttributeClass;
}

// File Line: 63
// RVA: 0xC54FE0
void __fastcall cleanupLoadedObjecthkCustomAttributesAttribute(void *p)
{
  ;
}

// File Line: 99
// RVA: 0x15C6BD0
void dynamic_initializer_for__hkCustomAttributesClass__()
{
  hkClass::hkClass(
    &hkCustomAttributesClass,
    "hkCustomAttributes",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkCustomAttributes::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 102
// RVA: 0xC54FC0
hkClass *__fastcall hkCustomAttributes::staticClass()
{
  return &hkCustomAttributesClass;
}

// File Line: 109
// RVA: 0xC54FF0
void __fastcall cleanupLoadedObjecthkCustomAttributes(void *p)
{
  ;
}

