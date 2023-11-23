// File Line: 57
// RVA: 0x15C4260
void dynamic_initializer_for__hkaiPhysics2012BodySilhouetteGeneratorClass__()
{
  hkClass::hkClass(
    &hkaiPhysics2012BodySilhouetteGeneratorClass,
    "hkaiPhysics2012BodySilhouetteGenerator",
    &hkaiPhysicsBodySilhouetteGeneratorBaseClass,
    192,
    0i64,
    0,
    0i64,
    0,
    &hkaiPhysics2012BodySilhouetteGenerator::Members,
    2,
    0i64,
    0i64,
    0,
    2);
}

// File Line: 60
// RVA: 0xC2E3C0
hkClass *__fastcall hkaiPhysics2012BodySilhouetteGenerator::staticClass()
{
  return &hkaiPhysics2012BodySilhouetteGeneratorClass;
}

// File Line: 67
// RVA: 0xC2E3D0
void __fastcall finishLoadedObjecthkaiPhysics2012BodySilhouetteGenerator(
        hkaiPhysics2012BodySilhouetteGenerator *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiPhysics2012BodySilhouetteGenerator::hkaiPhysics2012BodySilhouetteGenerator(p, finishing);
}

// File Line: 73
// RVA: 0xC2E3F0
void __fastcall cleanupLoadedObjecthkaiPhysics2012BodySilhouetteGenerator(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 77
// RVA: 0xC2E400
hkBaseObjectVtbl *__fastcall getVtablehkaiPhysics2012BodySilhouetteGenerator()
{
  hkaiPhysics2012BodySilhouetteGenerator v1; // [rsp+20h] [rbp-C8h] BYREF

  hkaiPhysics2012BodySilhouetteGenerator::hkaiPhysics2012BodySilhouetteGenerator(&v1, 0);
  return v1.vfptr;
}

// File Line: 99
// RVA: 0x15C42D0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiPhysics2012BodySilhouetteGeneratorTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiPhysics2012BodySilhouetteGenerator();
  hkaiPhysics2012BodySilhouetteGeneratorTypeInfo.m_size = 192i64;
  hkaiPhysics2012BodySilhouetteGeneratorTypeInfo.m_typeName = "hkaiPhysics2012BodySilhouetteGenerator";
  hkaiPhysics2012BodySilhouetteGeneratorTypeInfo.m_vtable = result;
  hkaiPhysics2012BodySilhouetteGeneratorTypeInfo.m_scopedName = "!hkaiPhysics2012BodySilhouetteGenerator";
  hkaiPhysics2012BodySilhouetteGeneratorTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiPhysics2012BodySilhouetteGenerator;
  hkaiPhysics2012BodySilhouetteGeneratorTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiPhysics2012BodySilhouetteGenerator;
  return result;
}

