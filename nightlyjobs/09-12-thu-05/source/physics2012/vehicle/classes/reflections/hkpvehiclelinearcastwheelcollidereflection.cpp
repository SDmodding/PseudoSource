// File Line: 58
// RVA: 0x15D5A30
void dynamic_initializer_for__hkpVehicleLinearCastWheelCollideWheelStateClass__()
{
  hkClass::hkClass(
    &hkpVehicleLinearCastWheelCollideWheelStateClass,
    "hkpVehicleLinearCastWheelCollideWheelState",
    0i64,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleLinearCastWheelCollide_WheelStateClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xE25B20
hkClass *__fastcall hkpVehicleLinearCastWheelCollide::WheelState::staticClass()
{
  return &hkpVehicleLinearCastWheelCollideWheelStateClass;
}

// File Line: 68
// RVA: 0xE25B30
void __fastcall cleanupLoadedObjecthkpVehicleLinearCastWheelCollideWheelState(void *p)
{
  ;
}

// File Line: 110
// RVA: 0x15D5960
void dynamic_initializer_for__hkpVehicleLinearCastWheelCollideClass__()
{
  hkClass::hkClass(
    &hkpVehicleLinearCastWheelCollideClass,
    "hkpVehicleLinearCastWheelCollide",
    &hkpVehicleWheelCollideClass,
    88,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleLinearCastWheelCollideClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 113
// RVA: 0xE25B10
hkClass *__fastcall hkpVehicleLinearCastWheelCollide::staticClass()
{
  return &hkpVehicleLinearCastWheelCollideClass;
}

// File Line: 120
// RVA: 0xE25B40
void __fastcall finishLoadedObjecthkpVehicleLinearCastWheelCollide(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpVehicleWheelCollide::`vftable;
    if ( finishing )
      *((_BYTE *)p + 17) = 0;
    *(_QWORD *)p = &hkpVehicleLinearCastWheelCollide::`vftable;
    *((_QWORD *)p + 6) = &hkpRejectChassisListener::`vftable{for `hkReferencedObject};
    *((_QWORD *)p + 8) = &hkpRejectChassisListener::`vftable{for `hkpPhantomOverlapListener};
    if ( finishing )
      *((_BYTE *)p + 17) = 2;
  }
}

// File Line: 126
// RVA: 0xE25B90
void __fastcall cleanupLoadedObjecthkpVehicleLinearCastWheelCollide(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 130
// RVA: 0xE25BA0
void **__fastcall getVtablehkpVehicleLinearCastWheelCollide()
{
  return &hkpVehicleLinearCastWheelCollide::`vftable;
}

// File Line: 152
// RVA: 0x15D59D0
void **dynamic_initializer_for__hkpVehicleLinearCastWheelCollideTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleLinearCastWheelCollide();
  hkpVehicleLinearCastWheelCollideTypeInfo.m_size = 88i64;
  hkpVehicleLinearCastWheelCollideTypeInfo.m_typeName = "hkpVehicleLinearCastWheelCollide";
  hkpVehicleLinearCastWheelCollideTypeInfo.m_vtable = result;
  hkpVehicleLinearCastWheelCollideTypeInfo.m_scopedName = "!hkpVehicleLinearCastWheelCollide";
  hkpVehicleLinearCastWheelCollideTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehicleLinearCastWheelCollide;
  hkpVehicleLinearCastWheelCollideTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehicleLinearCastWheelCollide;
  return result;
}

