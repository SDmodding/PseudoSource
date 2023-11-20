// File Line: 54
// RVA: 0x15D4830
void dynamic_initializer_for__hkpVehicleSuspensionSuspensionWheelParametersClass__()
{
  hkClass::hkClass(
    &hkpVehicleSuspensionSuspensionWheelParametersClass,
    "hkpVehicleSuspensionSuspensionWheelParameters",
    0i64,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleSuspension_SuspensionWheelParametersClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xE24DD0
hkClass *__fastcall hkpVehicleSuspension::SuspensionWheelParameters::staticClass()
{
  return &hkpVehicleSuspensionSuspensionWheelParametersClass;
}

// File Line: 64
// RVA: 0xE24DE0
void __fastcall cleanupLoadedObjecthkpVehicleSuspensionSuspensionWheelParameters(void *p)
{
  ;
}

// File Line: 102
// RVA: 0x15D47C0
void dynamic_initializer_for__hkpVehicleSuspensionClass__()
{
  hkClass::hkClass(
    &hkpVehicleSuspensionClass,
    "hkpVehicleSuspension",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleSuspensionClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 105
// RVA: 0xE24DC0
hkClass *__fastcall hkpVehicleSuspension::staticClass()
{
  return &hkpVehicleSuspensionClass;
}

