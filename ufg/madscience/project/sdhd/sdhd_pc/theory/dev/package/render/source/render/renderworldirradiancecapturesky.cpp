// File Line: 14
// RVA: 0x1456480
__int64 dynamic_initializer_for__kIrradCaptureShaderSymbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DRIRRADIANCECAPTURESKYVOLUME", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&kIrradCaptureShaderSymbol, v0);
  return atexit(dynamic_atexit_destructor_for__kIrradCaptureShaderSymbol__);
}

// File Line: 23
// RVA: 0x49700
UFG::ComponentIDDesc *__fastcall EditorCaptureSkyContext::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !EditorCaptureSkyContext::_DescInit )
  {
    v0 = UFG::RenderStagePlugin::AccessComponentDesc();
    ++UFG::RenderStagePlugin::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::RenderStagePlugin::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&EditorCaptureSkyContext::_TypeIDesc.mBaseTypeIndex = v3[0];
    EditorCaptureSkyContext::_TypeIDesc.mChildBitMask = v1;
    EditorCaptureSkyContext::_TypeIDesc.mChildren = 0;
    EditorCaptureSkyContext::_DescInit = 1;
    EditorCaptureSkyContext::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    EditorCaptureSkyContext::_EditorCaptureSkyContextTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &EditorCaptureSkyContext::_TypeIDesc;
}

// File Line: 57
// RVA: 0x1454840
__int64 dynamic_initializer_for__EditorCaptureSkyContext::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = EditorCaptureSkyContext::AccessComponentDesc();
  *(_DWORD *)&EditorCaptureSkyContext::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  EditorCaptureSkyContext::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  EditorCaptureSkyContext::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 468
// RVA: 0x14566A0
__int64 SkyIrradGridGenerator::_dynamic_initializer_for__msZoneFilter__()
{
  UFG::qString::qString(&msZoneFilter, "NP");
  return atexit(SkyIrradGridGenerator::_dynamic_atexit_destructor_for__msZoneFilter__);
}

// File Line: 469
// RVA: 0x1456630
__int64 SkyIrradGridGenerator::_dynamic_initializer_for__msSectionFilter__()
{
  UFG::qString::qString(&msSectionFilter, &customWorldMapCaption);
  return atexit(SkyIrradGridGenerator::_dynamic_atexit_destructor_for__msSectionFilter__);
}

// File Line: 470
// RVA: 0x1456580
__int64 SkyIrradGridGenerator::_dynamic_initializer_for__msLayerName__()
{
  UFG::qString::qString(&msLayerName, "SkyIrrad");
  return atexit(SkyIrradGridGenerator::_dynamic_atexit_destructor_for__msLayerName__);
}

// File Line: 473
// RVA: 0x1456660
__int64 SkyIrradGridGenerator::_dynamic_initializer_for__msSkyIrradParent__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("object-logical-IrradianceSky", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&msSkyIrradParent, v0);
  return atexit(SkyIrradGridGenerator::_dynamic_atexit_destructor_for__msSkyIrradParent__);
}

// File Line: 474
// RVA: 0x14564C0
__int64 SkyIrradGridGenerator::_dynamic_initializer_for__msComponentIrradianceVolumeName__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("component_IrradianceVolume", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&msComponentIrradianceVolumeName, v0);
  return atexit(SkyIrradGridGenerator::_dynamic_atexit_destructor_for__msComponentIrradianceVolumeName__);
}

// File Line: 475
// RVA: 0x1456500
__int64 SkyIrradGridGenerator::_dynamic_initializer_for__msComponentIrradianceVolumeSchema__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-component-IrradianceVolume", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&msComponentIrradianceVolumeSchema, v0);
  return atexit(SkyIrradGridGenerator::_dynamic_atexit_destructor_for__msComponentIrradianceVolumeSchema__);
}

// File Line: 476
// RVA: 0x1456540
__int64 SkyIrradGridGenerator::_dynamic_initializer_for__msComponentRegionName__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-component-Region", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&msComponentRegionName, v0);
  return atexit(SkyIrradGridGenerator::_dynamic_atexit_destructor_for__msComponentRegionName__);
}

// File Line: 477
// RVA: 0x14565F0
__int64 SkyIrradGridGenerator::_dynamic_initializer_for__msRegionMin__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Min", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&msRegionMin, v0);
  return atexit(SkyIrradGridGenerator::_dynamic_atexit_destructor_for__msRegionMin__);
}

// File Line: 478
// RVA: 0x14565B0
__int64 SkyIrradGridGenerator::_dynamic_initializer_for__msRegionMax__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Max", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&msRegionMax, v0);
  return atexit(SkyIrradGridGenerator::_dynamic_atexit_destructor_for__msRegionMax__);
}

