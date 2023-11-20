// File Line: 82
// RVA: 0x15C0130
hkClassEnum *dynamic_initializer_for__hkaiSilhouetteGenerator::Members__()
{
  hkClassEnum *result; // rax

  result = hkaiSilhouetteGeneratorGeneratorTypeEnum;
  unk_1421038A0 = hkaiSilhouetteGeneratorGeneratorTypeEnum;
  return result;
}

// File Line: 125
// RVA: 0x15C0140
void dynamic_initializer_for__hkaiSilhouetteGeneratorClass__()
{
  hkClass::hkClass(
    &hkaiSilhouetteGeneratorClass,
    "hkaiSilhouetteGenerator",
    &hkReferencedObjectClass,
    80,
    0i64,
    0,
    &hkaiSilhouetteGeneratorEnums,
    3,
    &hkaiSilhouetteGenerator::Members,
    7,
    &hkaiSilhouetteGenerator_Default,
    0i64,
    0,
    2u);
}

// File Line: 128
// RVA: 0xBB5E60
hkClass *__fastcall hkaiSilhouetteGenerator::staticClass()
{
  return &hkaiSilhouetteGeneratorClass;
}

