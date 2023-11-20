// File Line: 62
// RVA: 0x15C2200
void dynamic_initializer_for__hkaiObstacleGeneratorClass__()
{
  hkClass::hkClass(
    &hkaiObstacleGeneratorClass,
    "hkaiObstacleGenerator",
    &hkReferencedObjectClass,
    144,
    0i64,
    0,
    0i64,
    0,
    &hkaiObstacleGeneratorClass_Members,
    7,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 65
// RVA: 0xBB6EF0
hkClass *__fastcall hkaiObstacleGenerator::staticClass()
{
  return &hkaiObstacleGeneratorClass;
}

// File Line: 72
// RVA: 0xBB6F00
void __fastcall finishLoadedObjecthkaiObstacleGenerator(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiObstacleGenerator::hkaiObstacleGenerator);
}

// File Line: 78
// RVA: 0xBB6F20
void __fastcall cleanupLoadedObjecthkaiObstacleGenerator(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 82
// RVA: 0xBB6F30
hkBaseObjectVtbl *__fastcall getVtablehkaiObstacleGenerator()
{
  hkaiObstacleGenerator v1; // [rsp+20h] [rbp-98h]

  hkaiObstacleGenerator::hkaiObstacleGenerator(&v1, 0);
  return v1.vfptr;
}

// File Line: 104
// RVA: 0x15C2270
hkBaseObjectVtbl *dynamic_initializer_for__hkaiObstacleGeneratorTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiObstacleGenerator();
  hkaiObstacleGeneratorTypeInfo.m_size = 144i64;
  hkaiObstacleGeneratorTypeInfo.m_typeName = "hkaiObstacleGenerator";
  hkaiObstacleGeneratorTypeInfo.m_vtable = result;
  hkaiObstacleGeneratorTypeInfo.m_scopedName = "!hkaiObstacleGenerator";
  hkaiObstacleGeneratorTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiObstacleGenerator;
  hkaiObstacleGeneratorTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiObstacleGenerator;
  return result;
}

