// File Line: 58
// RVA: 0x15D5D50
void dynamic_initializer_for__hkpVehicleRayCastWheelCollideClass__()
{
  hkClass::hkClass(
    &hkpVehicleRayCastWheelCollideClass,
    "hkpVehicleRayCastWheelCollide",
    &hkpVehicleWheelCollideClass,
    72,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleRayCastWheelCollideClass_Members,
    3,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 61
// RVA: 0xE25E00
hkClass *__fastcall hkpVehicleRayCastWheelCollide::staticClass()
{
  return &hkpVehicleRayCastWheelCollideClass;
}

// File Line: 68
// RVA: 0xE25E10
void __fastcall finishLoadedObjecthkpVehicleRayCastWheelCollide(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpVehicleWheelCollide::`vftable;
    if ( finishing )
      *((_BYTE *)p + 17) = 0;
    *(_QWORD *)p = &hkpVehicleRayCastWheelCollide::`vftable;
    *((_QWORD *)p + 5) = &hkpRejectChassisListener::`vftable{for `hkReferencedObject};
    *((_QWORD *)p + 7) = &hkpRejectChassisListener::`vftable{for `hkpPhantomOverlapListener};
    if ( finishing )
      *((_BYTE *)p + 17) = 1;
  }
}

// File Line: 74
// RVA: 0xE25E60
void __fastcall cleanupLoadedObjecthkpVehicleRayCastWheelCollide(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 78
// RVA: 0xE25E70
void **__fastcall getVtablehkpVehicleRayCastWheelCollide()
{
  return &hkpVehicleRayCastWheelCollide::`vftable;
}

// File Line: 100
// RVA: 0x15D5DC0
void **dynamic_initializer_for__hkpVehicleRayCastWheelCollideTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleRayCastWheelCollide();
  hkpVehicleRayCastWheelCollideTypeInfo.m_size = 72i64;
  hkpVehicleRayCastWheelCollideTypeInfo.m_typeName = "hkpVehicleRayCastWheelCollide";
  hkpVehicleRayCastWheelCollideTypeInfo.m_vtable = result;
  hkpVehicleRayCastWheelCollideTypeInfo.m_scopedName = "!hkpVehicleRayCastWheelCollide";
  hkpVehicleRayCastWheelCollideTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehicleRayCastWheelCollide;
  hkpVehicleRayCastWheelCollideTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehicleRayCastWheelCollide;
  return result;
}

