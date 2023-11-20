// File Line: 91
// RVA: 0x1456090
__int64 dynamic_initializer_for__gIrrHelperModelHandle__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gIrrHelperModelHandle.mPrev);
  return atexit(dynamic_atexit_destructor_for__gIrrHelperModelHandle__);
}

// File Line: 98
// RVA: 0x1456420
__int64 dynamic_initializer_for__kGaussBlur3x3HDR_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GAUSSBLUR3X3_HDR", 0xFFFFFFFF);
  kGaussBlur3x3HDR_UID = result;
  return result;
}

// File Line: 107
// RVA: 0x1456160
__int64 dynamic_initializer_for__gLogFilename__()
{
  UFG::qString::qString(&gLogFilename, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__gLogFilename__);
}

// File Line: 241
// RVA: 0x1455ED0
__int64 dynamic_initializer_for__gCaptureContextQueue__()
{
  return atexit(dynamic_atexit_destructor_for__gCaptureContextQueue__);
}

// File Line: 1742
// RVA: 0x51690
void InitIrradianceCaptureSystem(void)
{
  unsigned int v0; // eax
  int v1; // eax
  Illusion::Material *v2; // rbx
  int v3; // edi
  int v4; // eax
  Illusion::Material *v5; // rbx
  int v6; // eax
  Illusion::Material *v7; // rbx
  unsigned int v8; // eax
  Illusion::Material *v9; // rbx
  int v10; // eax
  Illusion::Material *v11; // rbx
  int v12; // eax
  Illusion::Material *v13; // rbx
  unsigned int v14; // eax
  UFG::qResourceWarehouse *v15; // rax
  unsigned int v16; // ebx
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax

  v0 = UFG::qStringHashUpper32("IrradianceVolumeProbe", 0xFFFFFFFF);
  gRenderVolumeHelperMaterial = Illusion::Factory::NewMaterial("IrradianceVolumeProbe", v0, 6u, 0i64, 0i64, 0i64);
  v1 = UFG::qStringHashUpper32("DEBUGVOLUME", 0xFFFFFFFF);
  v2 = gRenderVolumeHelperMaterial;
  v3 = v1;
  LOWORD(gRenderVolumeHelperMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(v2[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v2[1].mTypeUID = -1957338719;
  LODWORD(v2[1].mResourceHandles.mNode.mNext) = v3;
  LODWORD(v2[1].mNode.mParent) = v4;
  v5 = gRenderVolumeHelperMaterial;
  *(_WORD *)&gRenderVolumeHelperMaterial[1].mDebugName[12] = 0;
  *(_DWORD *)&v5[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v6 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v5[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v5[1].mStateBlockMask.mFlags[0]) = 662883558;
  *(_DWORD *)&v5[1].mDebugName[4] = v6;
  v7 = gRenderVolumeHelperMaterial;
  LOWORD(gRenderVolumeHelperMaterial[1].mMaterialUser.mOffset) = 0;
  *(&v7[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v8 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v7[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v7[2].mNode.mUID = 543723269;
  v7[1].mNumParams = v8;
  v9 = gRenderVolumeHelperMaterial;
  LOWORD(gRenderVolumeHelperMaterial[2].mTypeUID) = 0;
  HIDWORD(v9[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("texVolume0", 0xFFFFFFFF);
  *((_DWORD *)&v9[2].0 + 22) = -1958479169;
  *(_DWORD *)&v9[2].mDebugName[28] = 0;
  LODWORD(v9[2].mResourceHandles.mNode.mNext) = v10;
  v11 = gRenderVolumeHelperMaterial;
  LOWORD(gRenderVolumeHelperMaterial[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v11[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v12 = UFG::qStringHash32("texVolume1", 0xFFFFFFFF);
  LODWORD(v11[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v11[3].mNode.mChild[0]) = 0;
  LODWORD(v11[2].mStateBlockMask.mFlags[0]) = v12;
  v13 = gRenderVolumeHelperMaterial;
  LOWORD(gRenderVolumeHelperMaterial[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v13[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v14 = UFG::qStringHash32("texVolume2", 0xFFFFFFFF);
  *(_DWORD *)&v13[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v13[3].mDebugName[12] = 0;
  v13[3].mNode.mUID = v14;
  v15 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v15, (UFG::qResourceData *)&gRenderVolumeHelperMaterial->mNode);
  v16 = UFG::qStringHash32("UNITSPHERE", 0xFFFFFFFF);
  v17 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v18 = UFG::qResourceWarehouse::Instance();
    v17 = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v17;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gIrrHelperModelHandle.mPrev, 0xA2ADCD77, v16, v17);
}

