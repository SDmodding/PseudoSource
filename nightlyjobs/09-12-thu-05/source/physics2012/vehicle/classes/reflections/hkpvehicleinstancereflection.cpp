// File Line: 85
// RVA: 0x15D5830
void dynamic_initializer_for__hkpVehicleInstanceWheelInfoClass__()
{
  hkClass::hkClass(
    &hkpVehicleInstanceWheelInfoClass,
    "hkpVehicleInstanceWheelInfo",
    0i64,
    224,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleInstance_WheelInfoClass_Members,
    18,
    0i64,
    0i64,
    0,
    2u);
}

// File Line: 88
// RVA: 0xE25900
hkClass *__fastcall hkpVehicleInstance::WheelInfo::staticClass()
{
  return &hkpVehicleInstanceWheelInfoClass;
}

// File Line: 95
// RVA: 0xE25910
void __fastcall cleanupLoadedObjecthkpVehicleInstanceWheelInfo(void *p)
{
  ;
}

// File Line: 178
// RVA: 0x15D5760
void dynamic_initializer_for__hkpVehicleInstanceClass__()
{
  hkClass::hkClass(
    &hkpVehicleInstanceClass,
    "hkpVehicleInstance",
    &hkpUnaryActionClass,
    240,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleInstanceClass_Members,
    26,
    &hkpVehicleInstance_Default,
    0i64,
    0,
    2u);
}

// File Line: 181
// RVA: 0xE258F0
hkClass *__fastcall hkpVehicleInstance::staticClass()
{
  return &hkpVehicleInstanceClass;
}

// File Line: 188
// RVA: 0xE25920
void __fastcall finishLoadedObjecthkpVehicleInstance(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpVehicleInstance::hkpVehicleInstance);
}

// File Line: 194
// RVA: 0xE25940
void __fastcall cleanupLoadedObjecthkpVehicleInstance(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 198
// RVA: 0xE25950
hkBaseObjectVtbl *__fastcall getVtablehkpVehicleInstance()
{
  hkpVehicleInstance v1; // [rsp+20h] [rbp-F8h]

  hkpVehicleInstance::hkpVehicleInstance(&v1, 0);
  return v1.vfptr;
}

// File Line: 220
// RVA: 0x15D57D0
hkBaseObjectVtbl *dynamic_initializer_for__hkpVehicleInstanceTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpVehicleInstance();
  hkpVehicleInstanceTypeInfo.m_size = 240i64;
  hkpVehicleInstanceTypeInfo.m_typeName = "hkpVehicleInstance";
  hkpVehicleInstanceTypeInfo.m_vtable = result;
  hkpVehicleInstanceTypeInfo.m_scopedName = "!hkpVehicleInstance";
  hkpVehicleInstanceTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehicleInstance;
  hkpVehicleInstanceTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehicleInstance;
  return result;
}

