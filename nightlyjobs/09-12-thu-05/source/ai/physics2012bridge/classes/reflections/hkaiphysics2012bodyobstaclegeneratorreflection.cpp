// File Line: 77
// RVA: 0x15C4190
void dynamic_initializer_for__hkaiPhysics2012BodyObstacleGeneratorClass__()
{
  hkClass::hkClass(
    &hkaiPhysics2012BodyObstacleGeneratorClass,
    "hkaiPhysics2012BodyObstacleGenerator",
    &hkaiObstacleGeneratorClass,
    160,
    0i64,
    0,
    0i64,
    0,
    &hkaiPhysics2012BodyObstacleGenerator::Members,
    2,
    &hkaiPhysics2012BodyObstacleGenerator_Default,
    0i64,
    0,
    1);
}

// File Line: 80
// RVA: 0xC2E360
hkClass *__fastcall hkaiPhysics2012BodyObstacleGenerator::staticClass()
{
  return &hkaiPhysics2012BodyObstacleGeneratorClass;
}

// File Line: 87
// RVA: 0xC2E370
void __fastcall finishLoadedObjecthkaiPhysics2012BodyObstacleGenerator(
        hkaiPhysics2012BodyObstacleGenerator *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiPhysics2012BodyObstacleGenerator::hkaiPhysics2012BodyObstacleGenerator(p, finishing);
}

// File Line: 93
// RVA: 0xC2E390
void __fastcall cleanupLoadedObjecthkaiPhysics2012BodyObstacleGenerator(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 97
// RVA: 0xC2E3A0
hkBaseObjectVtbl *__fastcall getVtablehkaiPhysics2012BodyObstacleGenerator()
{
  hkaiPhysics2012BodyObstacleGenerator v1; // [rsp+20h] [rbp-A8h] BYREF

  hkaiPhysics2012BodyObstacleGenerator::hkaiPhysics2012BodyObstacleGenerator(&v1, 0);
  return v1.vfptr;
}

// File Line: 119
// RVA: 0x15C4200
hkBaseObjectVtbl *dynamic_initializer_for__hkaiPhysics2012BodyObstacleGeneratorTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiPhysics2012BodyObstacleGenerator();
  hkaiPhysics2012BodyObstacleGeneratorTypeInfo.m_size = 160i64;
  hkaiPhysics2012BodyObstacleGeneratorTypeInfo.m_typeName = "hkaiPhysics2012BodyObstacleGenerator";
  hkaiPhysics2012BodyObstacleGeneratorTypeInfo.m_vtable = result;
  hkaiPhysics2012BodyObstacleGeneratorTypeInfo.m_scopedName = "!hkaiPhysics2012BodyObstacleGenerator";
  hkaiPhysics2012BodyObstacleGeneratorTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiPhysics2012BodyObstacleGenerator;
  hkaiPhysics2012BodyObstacleGeneratorTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiPhysics2012BodyObstacleGenerator;
  return result;
}

