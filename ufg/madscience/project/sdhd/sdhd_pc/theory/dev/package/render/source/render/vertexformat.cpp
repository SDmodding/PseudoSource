// File Line: 451
// RVA: 0x1453660
__int64 Render::_dynamic_initializer_for__gSlimDescriptor__()
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(&Render::gSlimDescriptor, "VertexDecl.Slim", 0x91355905);
  Render::gSlimDescriptor.vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vSlimDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    &Render::gSlimDescriptor,
    VERTEX_ELEMENT_POSITION,
    VERTEX_TYPE_FLOAT3,
    0,
    0i64);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gSlimDescriptor__);
}

// File Line: 452
// RVA: 0x14536D0
__int64 Render::_dynamic_initializer_for__gSlimUVDescriptor__()
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(&Render::gSlimUVDescriptor, "VertexDecl.SlimUV", 0x7E0D7533u);
  Render::gSlimUVDescriptor.vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vSlimUVDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    &Render::gSlimUVDescriptor,
    VERTEX_ELEMENT_POSITION,
    VERTEX_TYPE_FLOAT3,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    &Render::gSlimUVDescriptor,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    1,
    0i64);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gSlimUVDescriptor__);
}

// File Line: 453
// RVA: 0x1453370
__int64 Render::_dynamic_initializer_for__gFBXDescriptor__()
{
  Render::vFBXDescriptor::vFBXDescriptor(&Render::gFBXDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gFBXDescriptor__);
}

// File Line: 454
// RVA: 0x1453350
__int64 Render::_dynamic_initializer_for__gFBX2Descriptor__()
{
  Render::vFBX2Descriptor::vFBX2Descriptor(&Render::gFBX2Descriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gFBX2Descriptor__);
}

// File Line: 455
// RVA: 0x1453330
__int64 Render::_dynamic_initializer_for__gDynamicDescriptor__()
{
  Render::vDynamicDescriptor::vDynamicDescriptor(&Render::gDynamicDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gDynamicDescriptor__);
}

// File Line: 456
// RVA: 0x1453620
__int64 Render::_dynamic_initializer_for__gSkinnedDescriptor__()
{
  Render::vSkinnedDescriptor::vSkinnedDescriptor(&Render::gSkinnedDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gSkinnedDescriptor__);
}

// File Line: 457
// RVA: 0x14533F0
__int64 Render::_dynamic_initializer_for__gMorphTargetDescriptor__()
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    &Render::gMorphTargetDescriptor,
    "VertexDecl.MorphTarget",
    0x7029F5BAu);
  Render::gMorphTargetDescriptor.vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vMorphTargetDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    &Render::gMorphTargetDescriptor,
    VERTEX_ELEMENT_POSITION,
    VERTEX_TYPE_UBYTE4_DELTA,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    &Render::gMorphTargetDescriptor,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gMorphTargetDescriptor__);
}

// File Line: 458
// RVA: 0x1453480
__int64 Render::_dynamic_initializer_for__gMultiMorphTargetDescriptor__()
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(
    &Render::gMultiMorphTargetDescriptor,
    "VertexDecl.MultiMorphTarget",
    0x6649E95u);
  Render::gMultiMorphTargetDescriptor.vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vMultiMorphTargetDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    &Render::gMultiMorphTargetDescriptor,
    VERTEX_ELEMENT_POSITION,
    VERTEX_TYPE_SHORT4_FIXED4_12,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    &Render::gMultiMorphTargetDescriptor,
    VERTEX_ELEMENT_NORMAL,
    VERTEX_TYPE_BYTE4N,
    0,
    0i64);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gMultiMorphTargetDescriptor__);
}

// File Line: 461
// RVA: 0x14535E0
__int64 Render::_dynamic_initializer_for__gScreenParticleDescriptor__()
{
  Render::vScreenParticleDescriptor::vScreenParticleDescriptor(&Render::gScreenParticleDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gScreenParticleDescriptor__);
}

// File Line: 463
// RVA: 0x14533B0
__int64 Render::_dynamic_initializer_for__gLightCardDescriptor__()
{
  Render::vLightCardDescriptor::vLightCardDescriptor(&Render::gLightCardDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gLightCardDescriptor__);
}

// File Line: 464
// RVA: 0x1453550
__int64 Render::_dynamic_initializer_for__gRainDescriptor__()
{
  Illusion::VertexStreamDescriptor::VertexStreamDescriptor(&Render::gRainDescriptor, "VertexDecl.Rain", 0x48649FC8u);
  Render::gRainDescriptor.vfptr = (Illusion::VertexStreamDescriptorVtbl *)&Render::vRainDescriptor::`vftable;
  Illusion::VertexStreamDescriptor::AddElement(
    &Render::gRainDescriptor,
    VERTEX_ELEMENT_POSITION,
    VERTEX_TYPE_FLOAT3,
    0,
    0i64);
  Illusion::VertexStreamDescriptor::AddElement(
    &Render::gRainDescriptor,
    VERTEX_ELEMENT_TEXCOORD0,
    VERTEX_TYPE_HALF2,
    0,
    0i64);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gRainDescriptor__);
}

// File Line: 465
// RVA: 0x1453600
__int64 Render::_dynamic_initializer_for__gSkinnedDecalDescriptor__()
{
  Render::vSkinnedDecalDescriptor::vSkinnedDecalDescriptor(&Render::gSkinnedDecalDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gSkinnedDecalDescriptor__);
}

// File Line: 466
// RVA: 0x14532F0
__int64 Render::_dynamic_initializer_for__gCloudWispDescriptor__()
{
  Render::vCloudWispDescriptor::vCloudWispDescriptor(&Render::gCloudWispDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gCloudWispDescriptor__);
}

// File Line: 468
// RVA: 0x1453900
__int64 Render::_dynamic_initializer_for__gVehicleDescriptor__()
{
  Render::vVehicleUVNTDescriptor::vVehicleUVNTDescriptor(&Render::gVehicleDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gVehicleDescriptor__);
}

// File Line: 469
// RVA: 0x14538E0
__int64 Render::_dynamic_initializer_for__gVehicleDecalDescriptor__()
{
  Render::vVehicleUV2NTDescriptor::vVehicleUV2NTDescriptor(&Render::gVehicleDecalDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gVehicleDecalDescriptor__);
}

// File Line: 470
// RVA: 0x1453920
__int64 Render::_dynamic_initializer_for__gVehicleGlassDescriptor__()
{
  Render::vVehicleGlassUV2NTCDescriptor::vVehicleGlassUV2NTCDescriptor(&Render::gVehicleGlassDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gVehicleGlassDescriptor__);
}

// File Line: 472
// RVA: 0x1453640
__int64 Render::_dynamic_initializer_for__gSkinnedUVNTDescriptor__()
{
  Render::vSkinnedUVNTDescriptor::vSkinnedUVNTDescriptor(&Render::gSkinnedUVNTDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gSkinnedUVNTDescriptor__);
}

// File Line: 474
// RVA: 0x1453780
__int64 Render::_dynamic_initializer_for__gUV2Descriptor__()
{
  Render::vUV2Descriptor::vUV2Descriptor(&Render::gUV2Descriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUV2Descriptor__);
}

// File Line: 476
// RVA: 0x14537E0
__int64 Render::_dynamic_initializer_for__gUV2NTCDescriptor__()
{
  Render::vUV2NTCDescriptor::vUV2NTCDescriptor(&Render::gUV2NTCDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUV2NTCDescriptor__);
}

// File Line: 477
// RVA: 0x1453800
__int64 Render::_dynamic_initializer_for__gUV2NTDescriptor__()
{
  Render::vUV2NTDescriptor::vUV2NTDescriptor(&Render::gUV2NTDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUV2NTDescriptor__);
}

// File Line: 478
// RVA: 0x14537A0
__int64 Render::_dynamic_initializer_for__gUV2NCDescriptor__()
{
  Render::vUV2NCDescriptor::vUV2NCDescriptor(&Render::gUV2NCDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUV2NCDescriptor__);
}

// File Line: 479
// RVA: 0x14537C0
__int64 Render::_dynamic_initializer_for__gUV2NDescriptor__()
{
  Render::vUV2NDescriptor::vUV2NDescriptor(&Render::gUV2NDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUV2NDescriptor__);
}

// File Line: 481
// RVA: 0x14538A0
__int64 Render::_dynamic_initializer_for__gUVNTCDescriptor__()
{
  Render::vUVNTCDescriptor::vUVNTCDescriptor(&Render::gUVNTCDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUVNTCDescriptor__);
}

// File Line: 482
// RVA: 0x14538C0
__int64 Render::_dynamic_initializer_for__gUVNTDescriptor__()
{
  Render::vUVNTDescriptor::vUVNTDescriptor(&Render::gUVNTDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUVNTDescriptor__);
}

// File Line: 483
// RVA: 0x1453860
__int64 Render::_dynamic_initializer_for__gUVNDescriptor__()
{
  Render::vUVNDescriptor::vUVNDescriptor(&Render::gUVNDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUVNDescriptor__);
}

// File Line: 485
// RVA: 0x1453760
__int64 Render::_dynamic_initializer_for__gUV2CDescriptor__()
{
  Render::vUV2CDescriptor::vUV2CDescriptor(&Render::gUV2CDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUV2CDescriptor__);
}

// File Line: 486
// RVA: 0x1453820
__int64 Render::_dynamic_initializer_for__gUVCDescriptor__()
{
  Render::vUVCDescriptor::vUVCDescriptor(&Render::gUVCDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUVCDescriptor__);
}

// File Line: 488
// RVA: 0x1453510
__int64 Render::_dynamic_initializer_for__gNCDescriptor__()
{
  Render::vNCDescriptor::vNCDescriptor(&Render::gNCDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gNCDescriptor__);
}

// File Line: 490
// RVA: 0x1453840
__int64 Render::_dynamic_initializer_for__gUVCNPackedDescriptor__()
{
  Render::vUVCNPackedDescriptor::vUVCNPackedDescriptor(&Render::gUVCNPackedDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUVCNPackedDescriptor__);
}

// File Line: 491
// RVA: 0x1453880
__int64 Render::_dynamic_initializer_for__gUVNPackedDescriptor__()
{
  Render::vUVNPackedDescriptor::vUVNPackedDescriptor(&Render::gUVNPackedDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gUVNPackedDescriptor__);
}

// File Line: 492
// RVA: 0x1453940
__int64 Render::_dynamic_initializer_for__gWaterSurfaceDescriptor__()
{
  Render::vWaterSurfaceDescriptor::vWaterSurfaceDescriptor(&Render::gWaterSurfaceDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gWaterSurfaceDescriptor__);
}

// File Line: 494
// RVA: 0x1453530
__int64 Render::_dynamic_initializer_for__gParticleDescriptor__()
{
  Render::vParticleDescriptor::vParticleDescriptor(&Render::gParticleDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gParticleDescriptor__);
}

// File Line: 495
// RVA: 0x1453390
__int64 Render::_dynamic_initializer_for__gGeoParticleDescriptor__()
{
  Render::vGeoParticleDescriptor::vGeoParticleDescriptor(&Render::gGeoParticleDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gGeoParticleDescriptor__);
}

// File Line: 496
// RVA: 0x1453310
__int64 Render::_dynamic_initializer_for__gDecalDescriptor__()
{
  Render::vDecalDescriptor::vDecalDescriptor(&Render::gDecalDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gDecalDescriptor__);
}

// File Line: 497
// RVA: 0x14533D0
__int64 Render::_dynamic_initializer_for__gLightningDescriptor__()
{
  Render::vLightningDescriptor::vLightningDescriptor(&Render::gLightningDescriptor);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gLightningDescriptor__);
}

