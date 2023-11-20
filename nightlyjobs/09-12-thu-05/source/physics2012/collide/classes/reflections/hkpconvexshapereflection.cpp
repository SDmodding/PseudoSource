// File Line: 69
// RVA: 0x15CC570
void dynamic_initializer_for__hkpConvexShapeClass__()
{
  hkClass::hkClass(
    &hkpConvexShapeClass,
    "hkpConvexShape",
    &hkpSphereRepShapeClass,
    40,
    0i64,
    0,
    &hkpConvexShapeEnums,
    1,
    &hkpConvexShape::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 72
// RVA: 0xCECE00
hkClass *__fastcall hkpConvexShape::staticClass()
{
  return &hkpConvexShapeClass;
}

// File Line: 101
// RVA: 0x15CC5E0
void dynamic_initializer_for__hkpConvexTransformShapeBaseClass__()
{
  hkClass::hkClass(
    &hkpConvexTransformShapeBaseClass,
    "hkpConvexTransformShapeBase",
    &hkpConvexShapeClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkpConvexTransformShapeBase::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 104
// RVA: 0xCECE10
hkClass *__fastcall hkpConvexTransformShapeBase::staticClass()
{
  return &hkpConvexTransformShapeBaseClass;
}

