// File Line: 55
// RVA: 0x15C2B70
void dynamic_initializer_for__hkaiSimpleObstacleGeneratorClass__()
{
  hkClass::hkClass(
    &hkaiSimpleObstacleGeneratorClass,
    "hkaiSimpleObstacleGenerator",
    &hkaiObstacleGeneratorClass,
    176,
    0i64,
    0,
    0i64,
    0,
    &hkaiSimpleObstacleGeneratorClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xBB7560
hkClass *__fastcall hkaiSimpleObstacleGenerator::staticClass()
{
  return &hkaiSimpleObstacleGeneratorClass;
}

// File Line: 65
// RVA: 0xBB7570
void __fastcall finishLoadedObjecthkaiSimpleObstacleGenerator(
        hkaiObstacleGenerator *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkaiObstacleGenerator::hkaiObstacleGenerator(p, finishing);
    p->vfptr = (hkBaseObjectVtbl *)&hkaiSimpleObstacleGenerator::`vftable;
  }
}

// File Line: 71
// RVA: 0xBB75A0
void __fastcall cleanupLoadedObjecthkaiSimpleObstacleGenerator(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xBB75B0
void **__fastcall getVtablehkaiSimpleObstacleGenerator()
{
  hkaiObstacleGenerator v1; // [rsp+20h] [rbp-B8h] BYREF

  hkaiObstacleGenerator::hkaiObstacleGenerator(&v1, 0);
  return &hkaiSimpleObstacleGenerator::`vftable;
}

// File Line: 97
// RVA: 0x15C2BE0
void **dynamic_initializer_for__hkaiSimpleObstacleGeneratorTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiSimpleObstacleGenerator();
  hkaiSimpleObstacleGeneratorTypeInfo.m_size = 176i64;
  hkaiSimpleObstacleGeneratorTypeInfo.m_typeName = "hkaiSimpleObstacleGenerator";
  hkaiSimpleObstacleGeneratorTypeInfo.m_vtable = result;
  hkaiSimpleObstacleGeneratorTypeInfo.m_scopedName = "!hkaiSimpleObstacleGenerator";
  hkaiSimpleObstacleGeneratorTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiSimpleObstacleGenerator;
  hkaiSimpleObstacleGeneratorTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiSimpleObstacleGenerator;
  return result;
}

