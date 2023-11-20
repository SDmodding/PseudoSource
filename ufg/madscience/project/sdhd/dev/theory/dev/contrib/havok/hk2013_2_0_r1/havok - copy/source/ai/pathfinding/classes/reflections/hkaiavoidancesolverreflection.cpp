// File Line: 70
// RVA: 0x15C02F0
hkClassEnum *dynamic_initializer_for__hkaiMovementProperties::Members__()
{
  hkClassEnum *result; // rax

  result = hkaiMovementPropertiesKinematicConstraintTypeEnum;
  unk_142103AD0 = hkaiMovementPropertiesKinematicConstraintTypeEnum;
  return result;
}

// File Line: 115
// RVA: 0x15C0600
void dynamic_initializer_for__hkaiMovementPropertiesClass__()
{
  hkClass::hkClass(
    &hkaiMovementPropertiesClass,
    "hkaiMovementProperties",
    0i64,
    36,
    0i64,
    0,
    &hkaiMovementPropertiesEnums,
    1,
    &hkaiMovementProperties::Members,
    9,
    &hkaiMovementProperties_Default,
    0i64,
    0,
    8u);
}

// File Line: 118
// RVA: 0xBB5EE0
hkClass *__fastcall hkaiMovementProperties::staticClass()
{
  return &hkaiMovementPropertiesClass;
}

// File Line: 125
// RVA: 0xBB5F40
void __fastcall finishLoadedObjecthkaiMovementProperties(void *p, int finishing)
{
  ;
}

// File Line: 131
// RVA: 0xBB5F50
void __fastcall cleanupLoadedObjecthkaiMovementProperties(void *p)
{
  ;
}

// File Line: 177
// RVA: 0x15C04C0
hkClassEnum *dynamic_initializer_for__hkaiAvoidancePropertiesClass_Members__()
{
  hkClassEnum *result; // rax

  unk_142103B58 = hkaiAvoidancePropertiesAvoidanceSolverTypeEnum;
  result = hkaiAvoidancePropertiesNearbyBoundariesSearchTypeEnum;
  unk_142103B80 = hkaiAvoidancePropertiesNearbyBoundariesSearchTypeEnum;
  return result;
}

// File Line: 242
// RVA: 0x15C0440
void dynamic_initializer_for__hkaiAvoidancePropertiesClass__()
{
  hkClass::hkClass(
    &hkaiAvoidancePropertiesClass,
    "hkaiAvoidanceProperties",
    &hkReferencedObjectClass,
    160,
    0i64,
    0,
    &hkaiAvoidancePropertiesEnums,
    2,
    &hkaiAvoidancePropertiesClass_Members,
    17,
    &hkaiAvoidanceProperties_Default,
    0i64,
    0,
    0xCu);
}

// File Line: 245
// RVA: 0xBB5EF0
hkClass *__fastcall hkaiAvoidanceProperties::staticClass()
{
  return &hkaiAvoidancePropertiesClass;
}

// File Line: 252
// RVA: 0xBB5F60
void __fastcall finishLoadedObjecthkaiAvoidanceProperties(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiAvoidanceProperties::`vftable;
}

// File Line: 258
// RVA: 0xBB5F80
void __fastcall cleanupLoadedObjecthkaiAvoidanceProperties(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 262
// RVA: 0xBB5F90
void **__fastcall getVtablehkaiAvoidanceProperties()
{
  return &hkaiAvoidanceProperties::`vftable;
}

// File Line: 284
// RVA: 0x15C04E0
void **dynamic_initializer_for__hkaiAvoidancePropertiesTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiAvoidanceProperties();
  hkaiAvoidancePropertiesTypeInfo.m_size = 160i64;
  hkaiAvoidancePropertiesTypeInfo.m_typeName = "hkaiAvoidanceProperties";
  hkaiAvoidancePropertiesTypeInfo.m_vtable = result;
  hkaiAvoidancePropertiesTypeInfo.m_scopedName = "!hkaiAvoidanceProperties";
  hkaiAvoidancePropertiesTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiAvoidanceProperties;
  hkaiAvoidancePropertiesTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiAvoidanceProperties;
  return result;
}

// File Line: 332
// RVA: 0x15C0370
void dynamic_initializer_for__hkaiAvoidancePairPropertiesPairDataClass__()
{
  hkClass::hkClass(
    &hkaiAvoidancePairPropertiesPairDataClass,
    "hkaiAvoidancePairPropertiesPairData",
    0i64,
    12,
    0i64,
    0,
    0i64,
    0,
    &hkaiAvoidancePairProperties_PairDataClass_Members,
    3,
    &hkaiAvoidancePairPropertiesPairData_Default,
    0i64,
    0,
    1u);
}

// File Line: 335
// RVA: 0xBB5F10
hkClass *__fastcall hkaiAvoidancePairProperties::PairData::staticClass()
{
  return &hkaiAvoidancePairPropertiesPairDataClass;
}

// File Line: 342
// RVA: 0xBB5FA0
void __fastcall cleanupLoadedObjecthkaiAvoidancePairPropertiesPairData(void *p)
{
  ;
}

// File Line: 379
// RVA: 0x15C0300
void dynamic_initializer_for__hkaiAvoidancePairPropertiesClass__()
{
  hkClass::hkClass(
    &hkaiAvoidancePairPropertiesClass,
    "hkaiAvoidancePairProperties",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiAvoidancePairProperties::Members,
    1,
    0i64,
    0i64,
    0,
    2u);
}

// File Line: 382
// RVA: 0xBB5F00
hkClass *__fastcall hkaiAvoidancePairProperties::staticClass()
{
  return &hkaiAvoidancePairPropertiesClass;
}

// File Line: 389
// RVA: 0xBB5FB0
void __fastcall finishLoadedObjecthkaiAvoidancePairProperties(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiAvoidancePairProperties::`vftable;
}

// File Line: 395
// RVA: 0xBB5FD0
void __fastcall cleanupLoadedObjecthkaiAvoidancePairProperties(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 399
// RVA: 0xBB5FE0
void **__fastcall getVtablehkaiAvoidancePairProperties()
{
  return &hkaiAvoidancePairProperties::`vftable;
}

// File Line: 421
// RVA: 0x15C03E0
void **dynamic_initializer_for__hkaiAvoidancePairPropertiesTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiAvoidancePairProperties();
  hkaiAvoidancePairPropertiesTypeInfo.m_size = 32i64;
  hkaiAvoidancePairPropertiesTypeInfo.m_typeName = "hkaiAvoidancePairProperties";
  hkaiAvoidancePairPropertiesTypeInfo.m_vtable = result;
  hkaiAvoidancePairPropertiesTypeInfo.m_scopedName = "!hkaiAvoidancePairProperties";
  hkaiAvoidancePairPropertiesTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiAvoidancePairProperties;
  hkaiAvoidancePairPropertiesTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiAvoidancePairProperties;
  return result;
}

// File Line: 446
// RVA: 0x15C05A0
void dynamic_initializer_for__hkaiAvoidanceSolverSphereObstacleClass__()
{
  hkClass::hkClass(
    &hkaiAvoidanceSolverSphereObstacleClass,
    "hkaiAvoidanceSolverSphereObstacle",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiAvoidanceSolver_SphereObstacleClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 449
// RVA: 0xBB5F20
hkClass *__fastcall hkaiAvoidanceSolver::SphereObstacle::staticClass()
{
  return &hkaiAvoidanceSolverSphereObstacleClass;
}

// File Line: 456
// RVA: 0xBB5FF0
void __fastcall cleanupLoadedObjecthkaiAvoidanceSolverSphereObstacle(void *p)
{
  ;
}

// File Line: 492
// RVA: 0x15C0540
void dynamic_initializer_for__hkaiAvoidanceSolverBoundaryObstacleClass__()
{
  hkClass::hkClass(
    &hkaiAvoidanceSolverBoundaryObstacleClass,
    "hkaiAvoidanceSolverBoundaryObstacle",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiAvoidanceSolver_BoundaryObstacleClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 495
// RVA: 0xBB5F30
hkClass *__fastcall hkaiAvoidanceSolver::BoundaryObstacle::staticClass()
{
  return &hkaiAvoidanceSolverBoundaryObstacleClass;
}

// File Line: 502
// RVA: 0xBB6000
void __fastcall cleanupLoadedObjecthkaiAvoidanceSolverBoundaryObstacle(void *p)
{
  ;
}

