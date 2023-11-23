// File Line: 53
// RVA: 0x15C3C90
hkClassEnum *dynamic_initializer_for__hkaiReferenceFrameAndExtrusionClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiReferenceFrameAndExtrusionUpVectorTransformMethodEnum;
  unk_1421064D8 = hkaiReferenceFrameAndExtrusionUpVectorTransformMethodEnum;
  return result;
}

// File Line: 91
// RVA: 0x15C3C10
void dynamic_initializer_for__hkaiReferenceFrameAndExtrusionClass__()
{
  hkClass::hkClass(
    &hkaiReferenceFrameAndExtrusionClass,
    "hkaiReferenceFrameAndExtrusion",
    0i64,
    32,
    0i64,
    0,
    &hkaiReferenceFrameAndExtrusionEnums,
    1,
    &hkaiReferenceFrameAndExtrusionClass_Members,
    4,
    &hkaiReferenceFrameAndExtrusion_Default,
    0i64,
    0,
    1);
}

// File Line: 94
// RVA: 0xBB7F90
hkClass *__fastcall hkaiReferenceFrameAndExtrusion::staticClass()
{
  return &hkaiReferenceFrameAndExtrusionClass;
}

// File Line: 101
// RVA: 0xBB7FA0
void __fastcall finishLoadedObjecthkaiReferenceFrameAndExtrusion(void *p, int finishing)
{
  ;
}

// File Line: 107
// RVA: 0xBB7FB0
void __fastcall cleanupLoadedObjecthkaiReferenceFrameAndExtrusion(void *p)
{
  ;
}

