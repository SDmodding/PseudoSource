// File Line: 59
// RVA: 0x15D5E20
void dynamic_initializer_for__hkpVehicleSteeringAckermanClass__()
{
  hkClass::hkClass(
    &hkpVehicleSteeringAckermanClass,
    "hkpVehicleSteeringAckerman",
    &hkpVehicleSteeringClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleSteeringAckermanClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xE25EE0
hkClass *__fastcall hkpVehicleSteeringAckerman::staticClass()
{
  return &hkpVehicleSteeringAckermanClass;
}

// File Line: 69
// RVA: 0xE25EF0
void __fastcall finishLoadedObjecthkpVehicleSteeringAckerman(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpVehicleSteeringAckerman::`vftable;
}

// File Line: 75
// RVA: 0xE25F10
void __fastcall cleanupLoadedObjecthkpVehicleSteeringAckerman(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 79
// RVA: 0xE25F20
void **__fastcall getVtablehkpVehicleSteeringAckerman()
{
  return &hkpVehicleSteeringAckerman::`vftable;
}

// File Line: 101
// RVA: 0x15D5E90
void **dynamic_initializer_for__hkpVehicleSteeringAckermanTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleSteeringAckerman();
  hkpVehicleSteeringAckermanTypeInfo.m_size = 48i64;
  hkpVehicleSteeringAckermanTypeInfo.m_typeName = "hkpVehicleSteeringAckerman";
  hkpVehicleSteeringAckermanTypeInfo.m_vtable = result;
  hkpVehicleSteeringAckermanTypeInfo.m_scopedName = "!hkpVehicleSteeringAckerman";
  hkpVehicleSteeringAckermanTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpVehicleSteeringAckerman;
  hkpVehicleSteeringAckermanTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpVehicleSteeringAckerman;
  return result;
}

