// File Line: 70
// RVA: 0x15C2A70
hkClassEnum *dynamic_initializer_for__hkaiPointCloudSilhouetteGenerator::Members__()
{
  hkClassEnum *result; // rax

  unk_1421053B0 = hkaiPointCloudSilhouetteGeneratorDetailLevelEnum;
  result = hkaiPointCloudSilhouetteGeneratorPointCloudFlagBitsEnum;
  unk_1421053D8 = hkaiPointCloudSilhouetteGeneratorPointCloudFlagBitsEnum;
  return result;
}

// File Line: 115
// RVA: 0x15C2A90
void dynamic_initializer_for__hkaiPointCloudSilhouetteGeneratorClass__()
{
  hkClass::hkClass(
    &hkaiPointCloudSilhouetteGeneratorClass,
    "hkaiPointCloudSilhouetteGenerator",
    &hkaiSilhouetteGeneratorClass,
    160,
    0i64,
    0,
    &hkaiPointCloudSilhouetteGeneratorEnums,
    2,
    &hkaiPointCloudSilhouetteGenerator::Members,
    8,
    &hkaiPointCloudSilhouetteGenerator_Default,
    0i64,
    0,
    1);
}

// File Line: 118
// RVA: 0xBB7500
hkClass *__fastcall hkaiPointCloudSilhouetteGenerator::staticClass()
{
  return &hkaiPointCloudSilhouetteGeneratorClass;
}

// File Line: 125
// RVA: 0xBB7510
void __fastcall finishLoadedObjecthkaiPointCloudSilhouetteGenerator(
        hkaiPointCloudSilhouetteGenerator *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator(p, finishing);
}

// File Line: 131
// RVA: 0xBB7530
void __fastcall cleanupLoadedObjecthkaiPointCloudSilhouetteGenerator(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 135
// RVA: 0xBB7540
hkBaseObjectVtbl *__fastcall getVtablehkaiPointCloudSilhouetteGenerator()
{
  hkaiPointCloudSilhouetteGenerator v1; // [rsp+20h] [rbp-A8h] BYREF

  hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator(&v1, 0);
  return v1.vfptr;
}

// File Line: 157
// RVA: 0x15C2B10
hkBaseObjectVtbl *dynamic_initializer_for__hkaiPointCloudSilhouetteGeneratorTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiPointCloudSilhouetteGenerator();
  hkaiPointCloudSilhouetteGeneratorTypeInfo.m_size = 160i64;
  hkaiPointCloudSilhouetteGeneratorTypeInfo.m_typeName = "hkaiPointCloudSilhouetteGenerator";
  hkaiPointCloudSilhouetteGeneratorTypeInfo.m_vtable = result;
  hkaiPointCloudSilhouetteGeneratorTypeInfo.m_scopedName = "!hkaiPointCloudSilhouetteGenerator";
  hkaiPointCloudSilhouetteGeneratorTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiPointCloudSilhouetteGenerator;
  hkaiPointCloudSilhouetteGeneratorTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiPointCloudSilhouetteGenerator;
  return result;
}

