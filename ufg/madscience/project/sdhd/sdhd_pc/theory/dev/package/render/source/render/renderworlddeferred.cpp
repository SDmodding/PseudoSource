// File Line: 40
// RVA: 0x14561C0
__int64 dynamic_initializer_for__gMatBlit__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gMatBlit.mPrev);
  return atexit(dynamic_atexit_destructor_for__gMatBlit__);
}

// File Line: 41
// RVA: 0x1456220
__int64 dynamic_initializer_for__gMatPostFog__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gMatPostFog.mPrev);
  return atexit(dynamic_atexit_destructor_for__gMatPostFog__);
}

// File Line: 42
// RVA: 0x14561F0
__int64 dynamic_initializer_for__gMatHighlight__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gMatHighlight.mPrev);
  return atexit(dynamic_atexit_destructor_for__gMatHighlight__);
}

// File Line: 136
// RVA: 0x14560F0
__int64 dynamic_initializer_for__gLightCardVertexDecl__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gLightCardVertexDecl.mPrev);
  return atexit(dynamic_atexit_destructor_for__gLightCardVertexDecl__);
}

// File Line: 138
// RVA: 0x1456250
__int64 dynamic_initializer_for__gMatStencil__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gMatStencil.mPrev);
  return atexit(dynamic_atexit_destructor_for__gMatStencil__);
}

// File Line: 139
// RVA: 0x1456280
__int64 dynamic_initializer_for__gMatStencilNear__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gMatStencilNear.mPrev);
  return atexit(dynamic_atexit_destructor_for__gMatStencilNear__);
}

// File Line: 140
// RVA: 0x14562E0
__int64 dynamic_initializer_for__gMatStencilNoClear__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gMatStencilNoClear.mPrev);
  return atexit(dynamic_atexit_destructor_for__gMatStencilNoClear__);
}

// File Line: 141
// RVA: 0x14562B0
__int64 dynamic_initializer_for__gMatStencilNearNoClear__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gMatStencilNearNoClear.mPrev);
  return atexit(dynamic_atexit_destructor_for__gMatStencilNearNoClear__);
}

// File Line: 143
// RVA: 0x1456040
__int64 dynamic_initializer_for__gDeferredSphere__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gDeferredSphere.mPrev);
  return atexit(dynamic_atexit_destructor_for__gDeferredSphere__);
}

// File Line: 144
// RVA: 0x1456010
__int64 dynamic_initializer_for__gDeferredCube__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gDeferredCube.mPrev);
  return atexit(dynamic_atexit_destructor_for__gDeferredCube__);
}

// File Line: 145
// RVA: 0x1455FE0
__int64 dynamic_initializer_for__gDeferredCone__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gDeferredCone.mPrev);
  return atexit(dynamic_atexit_destructor_for__gDeferredCone__);
}

// File Line: 147
// RVA: 0x14560C0
__int64 dynamic_initializer_for__gIrradianceVolumePrimitiveVertexDecl__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&gIrradianceVolumePrimitiveVertexDecl.mPrev);
  return atexit(dynamic_atexit_destructor_for__gIrradianceVolumePrimitiveVertexDecl__);
}

// File Line: 152
// RVA: 0x52CF0
void LoadLightCardInfo()
{
  SimpleXML::XMLDocument *v0; // rax
  SimpleXML::XMLDocument *v1; // rbp
  SimpleXML::XMLNode *v2; // rax
  SimpleXML::XMLNode *v3; // rbx
  const char *v4; // rax
  unsigned int v5; // edi
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  int v8; // eax
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // kr00_8
  SimpleXML::XMLNode *v11; // rsi
  _DWORD *v12; // r14
  const char *v13; // rbx
  const char *v14; // r15
  signed __int64 v15; // rbx
  int *v16; // rdi
  float v17; // xmm2_4
  unsigned int v18; // xmm1_4
  unsigned int v19; // edx
  int v20; // er9
  unsigned __int16 v21; // r9
  unsigned int v22; // edx
  unsigned int v23; // edx
  int v24; // er8
  unsigned __int16 v25; // r8
  unsigned int v26; // edx
  UFG::qResourceInventory *v27; // rax
  UFG::qResourceWarehouse *v28; // rax
  int v29; // [rsp+38h] [rbp-90h]
  int v30; // [rsp+3Ch] [rbp-8Ch]
  int v31; // [rsp+40h] [rbp-88h]
  char *string; // [rsp+48h] [rbp-80h]
  const char *v33; // [rsp+50h] [rbp-78h]
  const char *v34; // [rsp+58h] [rbp-70h]
  const char *v35; // [rsp+60h] [rbp-68h]
  UFG::qResourceHandle v36; // [rsp+68h] [rbp-60h]
  float v37; // [rsp+D0h] [rbp+8h]
  float v38; // [rsp+D8h] [rbp+10h]
  float v39; // [rsp+E0h] [rbp+18h]

  if ( gEnableLightCards )
  {
    v0 = SimpleXML::XMLDocument::Open("Data\\LightCards\\lightcards.xml", 1ui64, 0i64);
    v1 = v0;
    if ( v0 )
    {
      v2 = SimpleXML::XMLDocument::GetNode(v0, 0i64, 0i64);
      v3 = v2;
      v4 = SimpleXML::XMLNode::GetAttribute(v2, "texturename");
      gLightCardTextureUID = UFG::qStringHashUpper32(v4, 0xFFFFFFFF);
      UFG::qResourceHandle::qResourceHandle(&v36);
      v5 = gLightCardTextureUID;
      v6 = `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result )
      {
        v7 = UFG::qResourceWarehouse::Instance();
        v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x8B43FABF);
        `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result = v6;
      }
      UFG::qResourceHandle::Init(&v36, 0x8B43FABF, v5, v6);
      v8 = SimpleXML::XMLNode::GetChildCount(v3);
      gLightCardInfoCount = v8;
      if ( v8 )
      {
        v10 = v8;
        v9 = 24i64 * v8;
        if ( !is_mul_ok(v10, 0x18ui64) )
          v9 = -1i64;
        gLightCardInfos = (LightCardInfo *)UFG::qMalloc(v9, "LoadLightCardInfo", 0i64);
        v11 = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, v3);
        if ( v11 )
        {
          v12 = &gLightCardInfos->m_channelMask;
          do
          {
            v13 = SimpleXML::XMLNode::GetAttribute(v11, "name");
            v14 = SimpleXML::XMLNode::GetAttribute(v11, "channelmask");
            string = (char *)SimpleXML::XMLNode::GetAttribute(v11, "uv0");
            v33 = SimpleXML::XMLNode::GetAttribute(v11, "uv1");
            v34 = SimpleXML::XMLNode::GetAttribute(v11, "uv2");
            v35 = SimpleXML::XMLNode::GetAttribute(v11, "uv3");
            *(v12 - 1) = UFG::qStringHashUpper32(v13, 0xFFFFFFFF);
            v15 = 0i64;
            v16 = v12 + 1;
            do
            {
              sscanf((&string)[v15], "%f,%f", &v37, &v38);
              v17 = v37 / (float)WORD2(v36.mData[1].mNode.mChild[0]);
              v37 = v37 / (float)WORD2(v36.mData[1].mNode.mChild[0]);
              *(float *)&v18 = v38 / (float)HIWORD(v36.mData[1].mNode.mChild[0]);
              v38 = *(float *)&v18;
              v39 = *(float *)&v18;
              v19 = v18 & 0x7FFFFFFF;
              v20 = (v18 >> 16) & 0x8000;
              if ( (v18 & 0x7FFFFFFF) <= 0x47FFEFFF )
              {
                if ( v19 >= 0x38800000 )
                  v22 = v19 - 939524096;
                else
                  v22 = (v18 & 0x7FFFFF | 0x800000) >> (113 - (v19 >> 23));
                v21 = ((((v22 >> 13) & 1) + v22 + 4095) >> 13) | v20;
              }
              else
              {
                v21 = v20 | 0x7FFF;
              }
              v39 = v17;
              v23 = LODWORD(v17) & 0x7FFFFFFF;
              v24 = (LODWORD(v17) >> 16) & 0x8000;
              if ( (LODWORD(v17) & 0x7FFFFFFFu) <= 0x47FFEFFF )
              {
                if ( v23 >= 0x38800000 )
                  v26 = v23 - 939524096;
                else
                  v26 = (LODWORD(v17) & 0x7FFFFF | 0x800000u) >> (113 - (v23 >> 23));
                v25 = ((((v26 >> 13) & 1) + v26 + 4095) >> 13) | v24;
              }
              else
              {
                v25 = v24 | 0x7FFF;
              }
              *v16 = v25 | (v21 << 16);
              ++v15;
              ++v16;
            }
            while ( v15 < 4 );
            sscanf(v14, "%d,%d,%d", &v29, &v30, &v31);
            *v12 = 65280 * v30 | 16711680 * v31 | 255 * v29;
            v11 = SimpleXML::XMLDocument::GetNode(v1, 0i64, v11);
            v12 += 6;
          }
          while ( v11 );
        }
      }
      SimpleXML::XMLDocument::~XMLDocument(v1);
      operator delete[](v1);
      v27 = `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result )
      {
        v28 = UFG::qResourceWarehouse::Instance();
        v27 = UFG::qResourceWarehouse::GetInventory(v28, 0x8B43FABF);
        `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result = v27;
      }
      UFG::qResourceHandle::Close(&v36, v27);
      UFG::qResourceHandle::~qResourceHandle(&v36);
    }
  }
}

// File Line: 217
// RVA: 0x50D00
void __fastcall InitDeferredRendering(UFG::RenderContext *render_context)
{
  unsigned int v1; // eax
  unsigned int v2; // eax
  Illusion::Material *v3; // rdi
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  UFG::qResourceWarehouse *v10; // rax
  unsigned int v11; // eax
  Illusion::Material *v12; // rdi
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  UFG::qResourceWarehouse *v17; // rax
  unsigned int v18; // eax
  Illusion::Material *v19; // rdi
  int v20; // ebx
  int v21; // eax
  int v22; // eax
  unsigned int v23; // eax
  UFG::qResourceWarehouse *v24; // rax
  unsigned int v25; // eax
  Illusion::Material *v26; // rdi
  int v27; // ebx
  int v28; // eax
  int v29; // eax
  unsigned int v30; // eax
  UFG::qResourceWarehouse *v31; // rax
  unsigned int v32; // eax
  Illusion::Material *v33; // rdi
  int v34; // eax
  int v35; // ebx
  int v36; // eax
  int v37; // eax
  unsigned int v38; // eax
  UFG::qResourceWarehouse *v39; // rax
  unsigned int v40; // ebx
  UFG::qResourceInventory *v41; // rax
  UFG::qResourceWarehouse *v42; // rax
  unsigned int v43; // ebx
  UFG::qResourceInventory *v44; // rax
  UFG::qResourceWarehouse *v45; // rax
  unsigned int v46; // ebx
  UFG::qResourceInventory *v47; // rax
  UFG::qResourceWarehouse *v48; // rax
  unsigned int v49; // ebx
  UFG::qResourceInventory *v50; // rax
  UFG::qResourceWarehouse *v51; // rax
  unsigned int v52; // ebx
  UFG::qResourceInventory *v53; // rax
  UFG::qResourceWarehouse *v54; // rax
  unsigned int v55; // ebx
  UFG::qResourceInventory *v56; // rax
  UFG::qResourceWarehouse *v57; // rax
  unsigned int v58; // ebx
  UFG::qResourceInventory *v59; // rax
  UFG::qResourceWarehouse *v60; // rax
  unsigned int v61; // ebx
  UFG::qResourceInventory *v62; // rax
  UFG::qResourceWarehouse *v63; // rax
  unsigned int v64; // ebx
  UFG::qResourceInventory *v65; // rax
  UFG::qResourceWarehouse *v66; // rax
  unsigned int v67; // ebx
  UFG::qResourceInventory *v68; // rax
  UFG::qResourceWarehouse *v69; // rax

  gLights = (Render::Light **)UFG::qMalloc(0x4000ui64, "LightList", 0x1000ui64);
  gCulledLights = (Render::LightInstance *)UFG::qMalloc(0x8000ui64, "LightListCulled", 0x1000ui64);
  v1 = UFG::qStringHash32("cbHkCompositeSettings", 0xFFFFFFFF);
  gCompositeStateIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                             &Illusion::gStateSystem,
                                             v1,
                                             "cbHkCompositeSettings",
                                             0);
  v2 = UFG::qStringHashUpper32("Blit", 0xFFFFFFFF);
  v3 = Illusion::Factory::NewMaterial("Blit", v2, 4u, 0i64, 0i64, 0i64);
  v4 = UFG::qStringHash32("HK_POSTCOMPBLIT", 0xFFFFFFFF);
  LOWORD(v3[1].mNode.mChild[0]) = 0;
  v5 = v4;
  HIDWORD(v3[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v6 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v3[1].mTypeUID = -1957338719;
  LODWORD(v3[1].mResourceHandles.mNode.mNext) = v5;
  LODWORD(v3[1].mNode.mParent) = v6;
  *(_WORD *)&v3[1].mDebugName[12] = 0;
  *(_DWORD *)&v3[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v7 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v3[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v3[1].mStateBlockMask.mFlags[0]) = 0;
  *(_DWORD *)&v3[1].mDebugName[4] = v7;
  LOWORD(v3[1].mMaterialUser.mOffset) = 0;
  *(&v3[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v8 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v3[2].mResourceHandles.mNode.mPrev) = 315097330;
  v3[2].mNode.mUID = -89056095;
  v3[1].mNumParams = v8;
  LOWORD(v3[2].mTypeUID) = 0;
  HIDWORD(v3[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v9 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v3[2].0 + 22) = 1002903008;
  LODWORD(v3[2].mResourceHandles.mNode.mNext) = v9;
  *(_DWORD *)&v3[2].mDebugName[28] = 1660426324;
  v10 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v10, (UFG::qResourceData *)&v3->mNode);
  v11 = UFG::qStringHashUpper32("StencilMaterial", 0xFFFFFFFF);
  v12 = Illusion::Factory::NewMaterial("StencilMaterial", v11, 3u, 0i64, 0i64, 0i64);
  v13 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v12[1].mNode.mChild[0]) = 0;
  HIDWORD(v12[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v14 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v12[1].mTypeUID = -1957338719;
  LODWORD(v12[1].mResourceHandles.mNode.mNext) = v13;
  LODWORD(v12[1].mNode.mParent) = v14;
  *(_WORD *)&v12[1].mDebugName[12] = 0;
  *(_DWORD *)&v12[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v12[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v12[1].mStateBlockMask.mFlags[0]) = -1851597485;
  *(_DWORD *)&v12[1].mDebugName[4] = v15;
  LOWORD(v12[1].mMaterialUser.mOffset) = 0;
  *(&v12[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v16 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v12[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v12[2].mNode.mUID = 1664809175;
  v12[1].mNumParams = v16;
  v17 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v17, (UFG::qResourceData *)&v12->mNode);
  v18 = UFG::qStringHashUpper32("StencilMaterialNear", 0xFFFFFFFF);
  v19 = Illusion::Factory::NewMaterial("StencilMaterialNear", v18, 3u, 0i64, 0i64, 0i64);
  v20 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v19[1].mNode.mChild[0]) = 0;
  HIDWORD(v19[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v21 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v19[1].mTypeUID = -1957338719;
  LODWORD(v19[1].mResourceHandles.mNode.mNext) = v20;
  LODWORD(v19[1].mNode.mParent) = v21;
  *(_WORD *)&v19[1].mDebugName[12] = 0;
  *(_DWORD *)&v19[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v22 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v19[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v19[1].mStateBlockMask.mFlags[0]) = -1851597485;
  *(_DWORD *)&v19[1].mDebugName[4] = v22;
  LOWORD(v19[1].mMaterialUser.mOffset) = 0;
  *(&v19[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v23 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v19[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v19[1].mNumParams = v23;
  v19[2].mNode.mUID = -300220655;
  v24 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v24, (UFG::qResourceData *)&v19->mNode);
  v25 = UFG::qStringHashUpper32("StencilMaterialNoClear", 0xFFFFFFFF);
  v26 = Illusion::Factory::NewMaterial("StencilMaterialNoClear", v25, 3u, 0i64, 0i64, 0i64);
  v27 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v26[1].mNode.mChild[0]) = 0;
  HIDWORD(v26[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v28 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v26[1].mTypeUID = -1957338719;
  LODWORD(v26[1].mResourceHandles.mNode.mNext) = v27;
  LODWORD(v26[1].mNode.mParent) = v28;
  *(_WORD *)&v26[1].mDebugName[12] = 0;
  *(_DWORD *)&v26[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v29 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v26[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v26[1].mStateBlockMask.mFlags[0]) = -1851597485;
  *(_DWORD *)&v26[1].mDebugName[4] = v29;
  LOWORD(v26[1].mMaterialUser.mOffset) = 0;
  *(&v26[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v30 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v26[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v26[2].mNode.mUID = -124816105;
  v26[1].mNumParams = v30;
  v31 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v31, (UFG::qResourceData *)&v26->mNode);
  v32 = UFG::qStringHashUpper32("StencilMaterialNearNoClear", 0xFFFFFFFF);
  v33 = Illusion::Factory::NewMaterial("StencilMaterialNearNoClear", v32, 3u, 0i64, 0i64, 0i64);
  v34 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v33[1].mNode.mChild[0]) = 0;
  v35 = v34;
  HIDWORD(v33[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v36 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v33[1].mTypeUID = -1957338719;
  LODWORD(v33[1].mResourceHandles.mNode.mNext) = v35;
  LODWORD(v33[1].mNode.mParent) = v36;
  *(_WORD *)&v33[1].mDebugName[12] = 0;
  *(_DWORD *)&v33[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v37 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v33[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v33[1].mStateBlockMask.mFlags[0]) = -1851597485;
  *(_DWORD *)&v33[1].mDebugName[4] = v37;
  LOWORD(v33[1].mMaterialUser.mOffset) = 0;
  *(&v33[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v38 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v33[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v33[1].mNumParams = v38;
  v33[2].mNode.mUID = -199860689;
  v39 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v39, (UFG::qResourceData *)&v33->mNode);
  v40 = UFG::qStringHashUpper32("DR_sphere", 0xFFFFFFFF);
  v41 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v42 = UFG::qResourceWarehouse::Instance();
    v41 = UFG::qResourceWarehouse::GetInventory(v42, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v41;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gDeferredSphere.mPrev, 0xA2ADCD77, v40, v41);
  v43 = UFG::qStringHashUpper32("DR_cube", 0xFFFFFFFF);
  v44 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v45 = UFG::qResourceWarehouse::Instance();
    v44 = UFG::qResourceWarehouse::GetInventory(v45, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v44;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gDeferredCube.mPrev, 0xA2ADCD77, v43, v44);
  v46 = UFG::qStringHashUpper32("DR_Cone", 0xFFFFFFFF);
  v47 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v48 = UFG::qResourceWarehouse::Instance();
    v47 = UFG::qResourceWarehouse::GetInventory(v48, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v47;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gDeferredCone.mPrev, 0xA2ADCD77, v46, v47);
  v49 = UFG::qStringHashUpper32("Blit", 0xFFFFFFFF);
  v50 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v51 = UFG::qResourceWarehouse::Instance();
    v50 = UFG::qResourceWarehouse::GetInventory(v51, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v50;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gMatBlit.mPrev, 0xB4C26312, v49, v50);
  v52 = UFG::qStringHashUpper32("StencilMaterial", 0xFFFFFFFF);
  v53 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v54 = UFG::qResourceWarehouse::Instance();
    v53 = UFG::qResourceWarehouse::GetInventory(v54, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v53;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gMatStencil.mPrev, 0xB4C26312, v52, v53);
  v55 = UFG::qStringHashUpper32("StencilMaterialNear", 0xFFFFFFFF);
  v56 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v57 = UFG::qResourceWarehouse::Instance();
    v56 = UFG::qResourceWarehouse::GetInventory(v57, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v56;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gMatStencilNear.mPrev, 0xB4C26312, v55, v56);
  v58 = UFG::qStringHashUpper32("StencilMaterialNoClear", 0xFFFFFFFF);
  v59 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v60 = UFG::qResourceWarehouse::Instance();
    v59 = UFG::qResourceWarehouse::GetInventory(v60, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v59;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gMatStencilNoClear.mPrev, 0xB4C26312, v58, v59);
  v61 = UFG::qStringHashUpper32("StencilMaterialNearNoClear", 0xFFFFFFFF);
  v62 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v63 = UFG::qResourceWarehouse::Instance();
    v62 = UFG::qResourceWarehouse::GetInventory(v63, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v62;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gMatStencilNearNoClear.mPrev, 0xB4C26312, v61, v62);
  LoadLightCardInfo();
  g_windIndex = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "sbWindSettings", 0);
  v64 = UFG::qStringHash32("VertexDecl.LightCard", 0xFFFFFFFF);
  v65 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
  {
    v66 = UFG::qResourceWarehouse::Instance();
    v65 = UFG::qResourceWarehouse::GetInventory(v66, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v65;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gLightCardVertexDecl.mPrev, 0x3E5FDA3Eu, v64, v65);
  v67 = UFG::qStringHash32("VertexDecl.Slim", 0xFFFFFFFF);
  v68 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
  {
    v69 = UFG::qResourceWarehouse::Instance();
    v68 = UFG::qResourceWarehouse::GetInventory(v69, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v68;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&gIrradianceVolumePrimitiveVertexDecl.mPrev, 0x3E5FDA3Eu, v67, v68);
}

// File Line: 616
// RVA: 0x4F4A0
void __fastcall GetAllDeferredLights(Render::Light **light_array, LightGroupAssoc *group_assoc, int *num_lights, int *num_groups, int max_lights)
{
  int *v5; // rsi
  int *v6; // rbx
  LightGroupAssoc *v7; // r13
  Render::Light **v8; // r15
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rax
  int v11; // er12
  UFG::qBaseTreeRB *v12; // rbp
  int v13; // er14
  float v14; // xmm6_4
  UFG::qBaseNodeRB *v15; // rcx
  signed __int64 v16; // r8
  __int64 v17; // rdx
  int v18; // ecx
  UFG::qBaseNodeRB *v19; // rax
  unsigned int v20; // edi
  unsigned int v21; // er11
  __int64 *v22; // r10
  unsigned int v23; // er9
  Render::Light *v24; // rdx
  _BYTE *v25; // rcx
  unsigned int v26; // er8
  signed __int64 v27; // rcx
  signed __int64 v28; // rsi
  __int64 v29; // rax
  signed __int64 v30; // rax
  unsigned int v31; // edi
  unsigned int v32; // edx
  UFG::qBaseTreeRB *v33; // rax
  int *v34; // rax
  float v35; // xmm0_4
  signed __int64 v36; // rcx
  signed __int64 v37; // rdi
  __int64 v38; // rax
  signed __int64 v39; // rax
  unsigned int v40; // ebx
  unsigned int v41; // edx
  UFG::qBaseTreeRB *v42; // rax
  int **v43; // rax
  float v44; // xmm0_4
  UFG::qBaseNodeRB **v45; // [rsp+28h] [rbp-A0h]
  __int64 v46; // [rsp+30h] [rbp-98h]
  int v47; // [rsp+38h] [rbp-90h]
  UFG::qBaseNodeRB **v48; // [rsp+40h] [rbp-88h]
  __int64 v49; // [rsp+48h] [rbp-80h]
  int v50; // [rsp+50h] [rbp-78h]
  int v51; // [rsp+E0h] [rbp+18h]
  int *v52; // [rsp+E8h] [rbp+20h]

  v52 = num_groups;
  v5 = num_groups;
  v6 = num_lights;
  v7 = group_assoc;
  v8 = light_array;
  if ( _S4_1 & 1 )
  {
    v10 = light_inventory;
  }
  else
  {
    _S4_1 |= 1u;
    v9 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v9, 0xF0A0724F);
    light_inventory = v10;
  }
  *v6 = 0;
  *v5 = 0;
  v11 = 0;
  v12 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v10->mResourceDatas);
  if ( v12 )
  {
    v13 = max_lights;
    v14 = *(float *)&FLOAT_1_0;
    while ( 1 )
    {
      v15 = v12[1].mRoot.mChild[1];
      v45 = v15 ? (UFG::qBaseNodeRB **)((char *)&v12[1].mRoot.mChild[1] + (_QWORD)v15) : 0i64;
      v16 = (signed __int64)&v12[1].mCount;
      v17 = *(_QWORD *)&v12[1].mCount;
      v46 = v17 ? v17 + v16 : 0i64;
      v18 = (int)v12[2].mRoot.mChild[0];
      v47 = (int)v12[2].mRoot.mChild[0];
      v19 = v12[1].mNULL.mChild[0];
      v48 = v19 ? (UFG::qBaseNodeRB **)((char *)&v19[3].mChild[1] + (_QWORD)v12) : 0i64;
      v49 = v17 ? v16 + v17 + (unsigned int)(HIDWORD(v12[2].mRoot.mChild[0]) + LODWORD(v12[2].mRoot.mChild[1]) + v18) : 0i64;
      v50 = HIDWORD(v12[2].mRoot.mChild[1]);
      v20 = (gDoLightVolumeCapture != 0) + 1;
      v21 = 0;
      if ( (gDoLightVolumeCapture != 0) != -1 )
        break;
LABEL_25:
      if ( *v6 != v11 )
      {
        v27 = *v5;
        v28 = v27;
        *v52 = v27 + 1;
        v7[v27].count = *v6 - v11;
        if ( *(&v12[2].mRoot.mUID + 1) && (v29 = *(_QWORD *)&v12[1].mNULL.mUID) != 0 )
          v30 = (signed __int64)&v12[1].mNULL.mUID + v29;
        else
          v30 = 0i64;
        v7[v27].clipPlanes = (UFG::qVector4 *)v30;
        v7[v27].numClipPlanes = *(&v12[2].mRoot.mUID + 1);
        v51 = 0;
        v31 = UFG::Metrics::msFrameCount;
        v32 = v12->mRoot.mUID;
        if ( v32 && (v33 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&light_inventory[1].mNode, v32)) != 0i64 )
          v34 = (int *)&v33->mNULL;
        else
          v34 = &v51;
        v35 = (float)(signed int)(v31 - *v34) * 0.1;
        if ( v35 <= 0.0 )
        {
          v35 = 0.0;
        }
        else if ( v35 >= 1.0 )
        {
          v35 = *(float *)&FLOAT_1_0;
        }
        v7[v28].lightGroupFade = v35;
        v11 = *v6;
        v5 = v52;
      }
      v12 = UFG::qBaseTreeRB::GetNext(&light_inventory->mResourceDatas.mTree, &v12->mRoot);
      if ( !v12 )
        return;
    }
    v22 = (__int64 *)&v45;
    while ( 1 )
    {
      v23 = *((_DWORD *)v22 + 4);
      v24 = (Render::Light *)*v22;
      v25 = (_BYTE *)v22[1];
      v26 = 0;
      if ( v23 )
        break;
LABEL_24:
      ++v21;
      v22 += 3;
      if ( v21 >= v20 )
        goto LABEL_25;
    }
    while ( 1 )
    {
      if ( *v25 & 2 )
      {
        v8[(*v6)++] = v24;
        if ( *v6 == v13 )
          break;
      }
      ++v26;
      ++v25;
      ++v24;
      if ( v26 >= v23 )
        goto LABEL_24;
    }
    if ( *v6 != v11 )
    {
      v36 = *v5;
      v37 = v36;
      *v5 = v36 + 1;
      v7[v36].count = *v6 - v11;
      if ( *(&v12[2].mRoot.mUID + 1) && (v38 = *(_QWORD *)&v12[1].mNULL.mUID) != 0 )
        v39 = (signed __int64)&v12[1].mNULL.mUID + v38;
      else
        v39 = 0i64;
      v7[v36].clipPlanes = (UFG::qVector4 *)v39;
      v7[v36].numClipPlanes = *(&v12[2].mRoot.mUID + 1);
      LODWORD(v52) = 0;
      v40 = UFG::Metrics::msFrameCount;
      v41 = v12->mRoot.mUID;
      if ( v41 && (v42 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&light_inventory[1].mNode, v41)) != 0i64 )
        v43 = (int **)&v42->mNULL;
      else
        v43 = &v52;
      v44 = (float)(signed int)(v40 - *(_DWORD *)v43) * 0.1;
      if ( v44 <= 0.0 )
      {
        v44 = 0.0;
      }
      else if ( v44 >= 1.0 )
      {
        goto LABEL_55;
      }
      v14 = v44;
LABEL_55:
      v7[v37].lightGroupFade = v14;
      return;
    }
  }
}

// File Line: 789
// RVA: 0x4E230
__int64 __fastcall GatherLights(Render::Light **pLights, LightGroupAssoc *pGroups)
{
  LightGroupAssoc *v2; // r14
  Render::Light **v3; // r12
  signed __int64 v4; // r15
  unsigned int v6; // ebx
  int v7; // ebx
  int v8; // esi
  Render::DynamicLightComponent *v9; // rbp
  Render::DynamicLightComponent *v10; // rdi
  UFG::TimeOfDayManager *v11; // rax
  Render::Light *v12; // rbp
  signed __int64 v13; // rdi
  UFG::qResourceWarehouse *v14; // rax
  UFG::qResourceInventory *v15; // rax
  Render::SkinningCacheNode *v16; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v17; // rcx
  unsigned int v18; // [rsp+90h] [rbp+18h]
  int v19; // [rsp+98h] [rbp+20h]

  v2 = pGroups;
  v3 = pLights;
  v4 = 0i64;
  v18 = 0;
  v19 = 0;
  GetAllDeferredLights(pLights, pGroups, (int *)&v18, &v19, 2048);
  if ( gDoLightVolumeCapture && !gIncludeEffectLightsInCapture )
    return v18;
  v6 = v18;
  v18 = Render::DynamicLightManager::GetDynamicLights(&Render::gDynamicLightManager, &v3[v18], 2048 - v18);
  v7 = v18 + v6;
  v8 = 0;
  v9 = (Render::DynamicLightComponent *)&Render::DynamicLightComponent::s_DynamicLightComponentList.mNode.mNext[-4];
  if ( (UFG::qList<Render::DynamicLightComponent,Render::DynamicLightComponent,1,0> *)&Render::DynamicLightComponent::s_DynamicLightComponentList.mNode.mNext[-4] != &Render::DynamicLightComponent::s_DynamicLightComponentList - 4 )
  {
    do
    {
      v10 = (Render::DynamicLightComponent *)&v9->mNext[-4];
      v11 = UFG::TimeOfDayManager::GetInstance();
      v12 = &v9->mLight;
      if ( (unsigned int)Render::IsLightOn(v12, v11->m_SecondsSinceMidnight) )
      {
        if ( v7 == 2048 )
          break;
        v3[v7++] = v12;
        ++v8;
      }
      v9 = v10;
    }
    while ( v10 != (Render::DynamicLightComponent *)(&Render::DynamicLightComponent::s_DynamicLightComponentList - 4) );
  }
  if ( v8 + v18 )
  {
    v13 = v19;
    v2[v13].count = v8 + v18;
    v2[v13].numClipPlanes = 0;
    v2[v13].clipPlanes = 0i64;
    v2[v13].lightGroupFade = 1.0;
    if ( _S5_0 & 1 )
    {
      v15 = dynamicLightGroupInventory;
    }
    else
    {
      _S5_0 |= 1u;
      v14 = UFG::qResourceWarehouse::Instance();
      v15 = UFG::qResourceWarehouse::GetInventory(v14, 0x19B59D34u);
      dynamicLightGroupInventory = v15;
    }
    if ( v15 )
    {
      v16 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v15->mResourceDatas);
      if ( v16 )
      {
        if ( LODWORD(v16[2].mNode.mChild[0]) )
        {
          v17 = v16[2].mNode.mChild[1];
          if ( v17 )
            v4 = (signed __int64)&v16[2].mNode.mChild[1] + (_QWORD)v17;
          v2[v13].clipPlanes = (UFG::qVector4 *)v4;
          v2[v13].numClipPlanes = (unsigned int)v16[2].mNode.mChild[0];
        }
      }
    }
  }
  return (unsigned int)v7;
}

// File Line: 906
// RVA: 0x4EA80
void __fastcall GenerateLightCullingInfo(int main_view_cull_index)
{
  char v1; // bp
  signed int v2; // er14
  __int64 v3; // r12
  int i; // esi
  float v5; // xmm0_4
  unsigned int v6; // edi
  CullManager *v7; // rax
  CullInfo *v8; // rax
  unsigned int v9; // er10
  signed __int64 v10; // rbx
  CullInfo *v11; // r13
  int v12; // er15
  signed __int64 v13; // r9
  __int16 v14; // r11
  unsigned int v15; // ecx
  __int64 v16; // rbp
  Render::LightInstance *v17; // rdx
  Render::Light *v18; // r8
  float v19; // xmm1_4
  Render::LightInstance *v20; // rdx
  Render::Light *v21; // r8
  float v22; // xmm1_4
  Render::LightInstance *v23; // rdx
  Render::Light *v24; // r8
  float v25; // xmm1_4
  __int64 v26; // rdx
  Render::LightInstance *v27; // rdx
  Render::Light *v28; // r8
  float v29; // xmm1_4
  signed __int64 v30; // r9
  __int64 v31; // rdx
  Render::LightInstance *v32; // rdx
  Render::Light *v33; // r8
  float v34; // xmm1_4
  CullManager *v35; // rax
  int v36; // [rsp+90h] [rbp+8h]

  v36 = main_view_cull_index;
  v1 = main_view_cull_index;
  if ( gUpdateLightTask )
    UFG::qTaskManager::Sync(&UFG::gTaskManager, gUpdateLightTask);
  gUpdateLightTask = 0i64;
  v2 = gNumNearLights + gNumStencilLights + gNumFarLights;
  UFG::qMemSet(gCulledLightsResults, 0, 0x48u);
  v3 = 0i64;
  for ( i = 0; v2; v2 -= v6 )
  {
    v5 = (float)v2;
    if ( (float)v2 >= 256.0 )
      v5 = FLOAT_256_0;
    v6 = (signed int)v5;
    v7 = CullManager::Instance();
    v8 = CullManager::AllocFrameCullInfos(v7, (signed int)v5);
    v9 = 0;
    v10 = 0i64;
    v11 = v8;
    if ( (signed int)v5 >= 4 )
    {
      v12 = i + 1;
      v13 = (signed __int64)&v8[1].mAABBMax[2];
      v14 = ~(1 << v1);
      v15 = ((v6 - 4) >> 2) + 1;
      v16 = v15;
      v9 = 4 * v15;
      v10 = 4i64 * v15;
      do
      {
        v13 += 256i64;
        v17 = &gCulledLights[v12 - 1];
        v18 = gLights[v17->lightIndex];
        v19 = v18->mDecayRadius * v17->radScale;
        *(_DWORD *)(v13 - 344) = LODWORD(v19) ^ _xmm[0];
        *(_DWORD *)(v13 - 340) = LODWORD(v19) ^ _xmm[0];
        *(_DWORD *)(v13 - 336) = LODWORD(v19) ^ _xmm[0];
        *(float *)(v13 - 328) = v19;
        *(float *)(v13 - 324) = v19;
        *(float *)(v13 - 320) = v19;
        *(_QWORD *)(v13 - 288) = v18;
        *(_WORD *)(v13 - 316) = 100;
        *(_WORD *)(v13 - 314) = v14;
        v20 = &gCulledLights[v12];
        v21 = gLights[v20->lightIndex];
        v22 = v21->mDecayRadius * v20->radScale;
        *(_DWORD *)(v13 - 280) = LODWORD(v22) ^ _xmm[0];
        *(_DWORD *)(v13 - 276) = LODWORD(v22) ^ _xmm[0];
        *(_DWORD *)(v13 - 272) = LODWORD(v22) ^ _xmm[0];
        *(float *)(v13 - 264) = v22;
        *(float *)(v13 - 260) = v22;
        *(float *)(v13 - 256) = v22;
        *(_QWORD *)(v13 - 224) = v21;
        *(_WORD *)(v13 - 252) = 100;
        *(_WORD *)(v13 - 250) = v14;
        v23 = &gCulledLights[v12 + 1];
        v24 = gLights[v23->lightIndex];
        v25 = v24->mDecayRadius * v23->radScale;
        v26 = (unsigned int)(v12 + 2);
        v12 += 4;
        *(_DWORD *)(v13 - 216) = LODWORD(v25) ^ _xmm[0];
        *(_DWORD *)(v13 - 212) = LODWORD(v25) ^ _xmm[0];
        *(_DWORD *)(v13 - 208) = LODWORD(v25) ^ _xmm[0];
        *(float *)(v13 - 200) = v25;
        *(float *)(v13 - 196) = v25;
        *(float *)(v13 - 192) = v25;
        *(_QWORD *)(v13 - 160) = v24;
        *(_WORD *)(v13 - 188) = 100;
        *(_WORD *)(v13 - 186) = v14;
        v27 = &gCulledLights[v26];
        v28 = gLights[v27->lightIndex];
        v29 = v28->mDecayRadius * v27->radScale;
        *(_DWORD *)(v13 - 152) = LODWORD(v29) ^ _xmm[0];
        *(_DWORD *)(v13 - 148) = LODWORD(v29) ^ _xmm[0];
        *(_DWORD *)(v13 - 144) = LODWORD(v29) ^ _xmm[0];
        *(float *)(v13 - 136) = v29;
        *(float *)(v13 - 132) = v29;
        *(float *)(v13 - 128) = v29;
        *(_QWORD *)(v13 - 96) = v28;
        *(_WORD *)(v13 - 124) = 100;
        *(_WORD *)(v13 - 122) = v14;
        --v16;
      }
      while ( v16 );
      v11 = v8;
      v1 = v36;
    }
    if ( v9 < v6 )
    {
      v30 = (signed __int64)&v11[v10].mAABBMax[2];
      do
      {
        v31 = v9++ + i;
        v30 += 64i64;
        v32 = &gCulledLights[v31];
        v33 = gLights[v32->lightIndex];
        v34 = v33->mDecayRadius * v32->radScale;
        *(_DWORD *)(v30 - 88) = LODWORD(v34) ^ _xmm[0];
        *(_DWORD *)(v30 - 84) = LODWORD(v34) ^ _xmm[0];
        *(_DWORD *)(v30 - 80) = LODWORD(v34) ^ _xmm[0];
        *(float *)(v30 - 72) = v34;
        *(float *)(v30 - 68) = v34;
        *(float *)(v30 - 64) = v34;
        *(_QWORD *)(v30 - 32) = v33;
        *(_WORD *)(v30 - 60) = 100;
        *(_WORD *)(v30 - 58) = ~(1 << v1);
      }
      while ( v9 < v6 );
    }
    v35 = CullManager::Instance();
    CullManager::AllocPrebuiltFrameCullInfos(v35, &gCulledLightsResults[v3], v6, v11, 0i64);
    v3 = (unsigned int)(v3 + 1);
    i += v6;
  }
}

// File Line: 951
// RVA: 0x5C400
void __fastcall SubmitUpdateLightingTask(Render::ViewSettings *view_settings, int num_lights, Render::Light **pLights, Render::LightInstance *pResults)
{
  Render::LightInstance *v4; // r15
  Render::Light **v5; // rsi
  int v6; // er14
  Render::ViewSettings *v7; // rdi
  char *v8; // rbx
  float v9; // xmm0_4
  float v10; // xmm5_4
  float v11; // xmm8_4
  int v12; // xmm3_4
  int v13; // xmm7_4
  int v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm14_4
  float v21; // xmm12_4
  float v22; // xmm10_4
  float v23; // xmm7_4
  float v24; // xmm15_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm13_4
  float v28; // xmm2_4
  float v29; // xmm5_4
  float v30; // xmm11_4
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm9_4
  float v34; // xmm8_4
  float v35; // xmm4_4
  float v36; // xmm7_4
  float v37; // xmm2_4
  float v38; // xmm6_4
  float v39; // xmm1_4
  float v40; // xmm5_4
  int v41; // xmm2_4
  int v42; // xmm1_4
  int v43; // xmm0_4
  int v44; // xmm2_4
  int v45; // xmm1_4
  int v46; // xmm0_4
  int v47; // xmm2_4
  int v48; // xmm1_4
  int v49; // xmm0_4
  int v50; // xmm2_4
  int v51; // xmm1_4
  int v52; // xmm0_4
  int v53; // xmm2_4
  int v54; // xmm1_4
  int v55; // xmm0_4
  int v56; // xmm3_4
  int v57; // xmm2_4
  int v58; // xmm1_4
  float v59; // xmm6_4
  __m128 v60; // xmm5
  float v61; // xmm4_4
  __m128 v62; // xmm2
  float v63; // xmm0_4
  float v64; // xmm3_4
  __m128 v65; // xmm6
  float v66; // xmm3_4
  __m128 v67; // xmm2
  float v68; // xmm0_4
  float v69; // xmm4_4
  __m128 v70; // xmm6
  float v71; // xmm3_4
  __m128 v72; // xmm2
  float v73; // xmm0_4
  float v74; // xmm4_4
  __m128 v75; // xmm6
  float v76; // xmm3_4
  __m128 v77; // xmm2
  float v78; // xmm0_4
  float v79; // xmm4_4
  __m128 v80; // xmm6
  float v81; // xmm4_4
  __m128 v82; // xmm2
  float v83; // xmm0_4
  float v84; // xmm3_4
  __m128 v85; // xmm5
  float v86; // xmm4_4
  float v87; // xmm3_4
  __m128 v88; // xmm2
  float v89; // xmm0_4
  float v90; // xmm7_4
  char *v91; // rax
  UFG::qTask *v92; // rdx
  _QWORD *v93; // rax
  UFG::qSpuElf *v94; // rax
  void (__fastcall *v95)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rcx
  void (__fastcall *v96)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v97)(void *, void *, void *, void *); // r8
  char *v98; // r9
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v99; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v100; // rax
  UFG::qMatrix44 result; // [rsp+20h] [rbp-B8h]
  __int64 v102; // [rsp+60h] [rbp-78h]
  int v103; // [rsp+68h] [rbp-70h]
  int v104; // [rsp+6Ch] [rbp-6Ch]
  UFG::qMatrix44 d; // [rsp+70h] [rbp-68h]
  char *v106; // [rsp+158h] [rbp+80h]
  char *v107; // [rsp+168h] [rbp+90h]
  void *retaddr; // [rsp+178h] [rbp+A0h]

  v102 = -2i64;
  v4 = pResults;
  v5 = pLights;
  v6 = num_lights;
  v7 = view_settings;
  gNumNearLights = 0;
  gNumStencilLights = 0;
  gNumFarLights = 0;
  gNumLightCards = 0;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x108u, 0x10u);
  *((_QWORD *)v8 + 7) = Illusion::gEngine.FrameMemory;
  UFG::qInverseAffine(&d, &v7->mWorldView);
  v9 = v7->mProjection.v2.z;
  v10 = 0.0;
  if ( v9 == 0.0 || v9 == v7->mProjection.v2.w )
    v11 = *(float *)&retaddr;
  else
    v11 = v7->mProjection.v3.z / v9;
  v12 = LODWORD(d.v0.x) ^ _xmm[0];
  v13 = v104 ^ _xmm[0];
  v14 = v103 ^ _xmm[0];
  v15 = (float)((float)(*(float *)&v14 * *(float *)&v14) + (float)(*(float *)&v13 * *(float *)&v13))
      + (float)(*(float *)&v12 * *(float *)&v12);
  if ( v15 != 0.0 )
    v10 = 1.0 / fsqrt(v15);
  v16 = d.v0.w;
  v17 = d.v1.x;
  *((_DWORD *)v8 + 40) = LODWORD(d.v0.z);
  *((float *)v8 + 41) = v16;
  *((float *)v8 + 42) = v17;
  *((float *)v8 + 44) = *(float *)&v14 * v10;
  *((float *)v8 + 45) = v10 * *(float *)&v13;
  *((float *)v8 + 46) = v10 * *(float *)&v12;
  *((float *)v8 + 10) = v11;
  *(_DWORD *)v8 = v6;
  *((_QWORD *)v8 + 6) = v5;
  *((_DWORD *)v8 + 43) = 1058642330;
  *((float *)v8 + 3) = gClipThreshold;
  *((float *)v8 + 4) = gFadeThreshold;
  if ( UFG::RenderWorld::msIsNisPlaying )
    v18 = gClipThreshold;
  else
    v18 = gShadowClipThreshold;
  *((float *)v8 + 5) = v18;
  if ( UFG::RenderWorld::msIsNisPlaying )
    v19 = gFadeThreshold;
  else
    v19 = gShadowFadeThreshold;
  *((float *)v8 + 6) = v19;
  *((_DWORD *)v8 + 7) = 1137180672;
  *((_DWORD *)v8 + 8) = 1137836032;
  *((_QWORD *)v8 + 29) = gLightGroups;
  *((float *)v8 + 1) = gOptimizeRadius;
  *((_DWORD *)v8 + 2) = (_DWORD)retaddr;
  *((_QWORD *)v8 + 24) = v4;
  *((_QWORD *)v8 + 25) = &gNumNearLights;
  *((_QWORD *)v8 + 26) = &gNumStencilLights;
  *((_QWORD *)v8 + 27) = &gNumFarLights;
  *((_QWORD *)v8 + 28) = &gNumLightCards;
  v8[36] = 1;
  UFG::qMatrix44::operator*(&v7->mWorldView, &result, &v7->mProjection);
  *((_DWORD *)v8 + 16) = LODWORD(result.v0.z);
  v20 = result.v1.z;
  *((_DWORD *)v8 + 17) = LODWORD(result.v1.z);
  v21 = result.v2.z;
  *((_DWORD *)v8 + 18) = LODWORD(result.v2.z);
  v22 = result.v3.z;
  *((_DWORD *)v8 + 19) = LODWORD(result.v3.z);
  v23 = result.v3.x;
  v24 = result.v3.w;
  v25 = result.v3.x + result.v3.w;
  v26 = result.v2.x;
  v27 = result.v2.w;
  v28 = result.v2.x + result.v2.w;
  v29 = result.v1.x;
  v30 = result.v1.w;
  v31 = result.v1.x + result.v1.w;
  v32 = result.v0.x;
  v33 = result.v0.w;
  *((float *)v8 + 20) = result.v0.x + result.v0.w;
  *((float *)v8 + 21) = v31;
  *((float *)v8 + 22) = v28;
  *((float *)v8 + 23) = v25;
  *((float *)v8 + 24) = v33 - v32;
  *((float *)v8 + 25) = v30 - v29;
  *((float *)v8 + 26) = v27 - v26;
  *((float *)v8 + 27) = v24 - v23;
  v34 = result.v3.y;
  v35 = result.v3.y + v24;
  v36 = result.v2.y;
  v37 = result.v2.y + v27;
  v38 = result.v1.y;
  v39 = result.v1.y + v30;
  v40 = result.v0.y;
  *((float *)v8 + 28) = result.v0.y + v33;
  *((float *)v8 + 29) = v39;
  *((float *)v8 + 30) = v37;
  *((float *)v8 + 31) = v35;
  *((float *)v8 + 32) = v33 - v40;
  *((float *)v8 + 33) = v30 - v38;
  *((float *)v8 + 34) = v27 - v36;
  *((float *)v8 + 35) = v24 - v34;
  *((float *)v8 + 36) = v33 - result.v0.z;
  *((float *)v8 + 37) = v30 - v20;
  *((float *)v8 + 38) = v27 - v21;
  *((float *)v8 + 39) = v24 - v22;
  v41 = *((_DWORD *)v8 + 17) ^ _xmm[0];
  v42 = *((_DWORD *)v8 + 18) ^ _xmm[0];
  v43 = *((_DWORD *)v8 + 19) ^ _xmm[0];
  *((_DWORD *)v8 + 16) ^= _xmm[0];
  *((_DWORD *)v8 + 17) = v41;
  *((_DWORD *)v8 + 18) = v42;
  *((_DWORD *)v8 + 19) = v43;
  v44 = *((_DWORD *)v8 + 21) ^ _xmm[0];
  v45 = *((_DWORD *)v8 + 22) ^ _xmm[0];
  v46 = *((_DWORD *)v8 + 23) ^ _xmm[0];
  *((_DWORD *)v8 + 20) ^= _xmm[0];
  *((_DWORD *)v8 + 21) = v44;
  *((_DWORD *)v8 + 22) = v45;
  *((_DWORD *)v8 + 23) = v46;
  v47 = *((_DWORD *)v8 + 25) ^ _xmm[0];
  v48 = *((_DWORD *)v8 + 26) ^ _xmm[0];
  v49 = *((_DWORD *)v8 + 27) ^ _xmm[0];
  *((_DWORD *)v8 + 24) ^= _xmm[0];
  *((_DWORD *)v8 + 25) = v47;
  *((_DWORD *)v8 + 26) = v48;
  *((_DWORD *)v8 + 27) = v49;
  v50 = *((_DWORD *)v8 + 29) ^ _xmm[0];
  v51 = *((_DWORD *)v8 + 30) ^ _xmm[0];
  v52 = *((_DWORD *)v8 + 31) ^ _xmm[0];
  *((_DWORD *)v8 + 28) ^= _xmm[0];
  *((_DWORD *)v8 + 29) = v50;
  *((_DWORD *)v8 + 30) = v51;
  *((_DWORD *)v8 + 31) = v52;
  v53 = *((_DWORD *)v8 + 33) ^ _xmm[0];
  v54 = *((_DWORD *)v8 + 34) ^ _xmm[0];
  v55 = *((_DWORD *)v8 + 35) ^ _xmm[0];
  *((_DWORD *)v8 + 32) ^= _xmm[0];
  *((_DWORD *)v8 + 33) = v53;
  *((_DWORD *)v8 + 34) = v54;
  *((_DWORD *)v8 + 35) = v55;
  v56 = *((_DWORD *)v8 + 39) ^ _xmm[0];
  v57 = *((_DWORD *)v8 + 38) ^ _xmm[0];
  v58 = *((_DWORD *)v8 + 37) ^ _xmm[0];
  *((_DWORD *)v8 + 36) ^= _xmm[0];
  *((_DWORD *)v8 + 37) = v58;
  *((_DWORD *)v8 + 38) = v57;
  *((_DWORD *)v8 + 39) = v56;
  v59 = *((float *)v8 + 17);
  v60 = (__m128)*((unsigned int *)v8 + 16);
  v61 = *((float *)v8 + 18);
  v62 = v60;
  v62.m128_f32[0] = (float)((float)(v60.m128_f32[0] * v60.m128_f32[0]) + (float)(v59 * v59)) + (float)(v61 * v61);
  LODWORD(v63) = (unsigned __int128)_mm_sqrt_ps(v62);
  v64 = (float)(1.0 / v63) * *((float *)v8 + 19);
  *((float *)v8 + 16) = v60.m128_f32[0] * (float)(1.0 / v63);
  *((float *)v8 + 17) = v59 * (float)(1.0 / v63);
  *((float *)v8 + 18) = (float)(1.0 / v63) * v61;
  *((float *)v8 + 19) = v64;
  v65 = (__m128)*((unsigned int *)v8 + 21);
  v66 = *((float *)v8 + 20);
  v60.m128_i32[0] = *((_DWORD *)v8 + 22);
  v67 = v65;
  v67.m128_f32[0] = (float)((float)(v65.m128_f32[0] * v65.m128_f32[0]) + (float)(v66 * v66))
                  + (float)(v60.m128_f32[0] * v60.m128_f32[0]);
  LODWORD(v68) = (unsigned __int128)_mm_sqrt_ps(v67);
  v69 = (float)(1.0 / v68) * *((float *)v8 + 23);
  *((float *)v8 + 20) = (float)(1.0 / v68) * v66;
  *((float *)v8 + 21) = v65.m128_f32[0] * (float)(1.0 / v68);
  *((float *)v8 + 22) = v60.m128_f32[0] * (float)(1.0 / v68);
  *((float *)v8 + 23) = v69;
  v70 = (__m128)*((unsigned int *)v8 + 25);
  v71 = *((float *)v8 + 24);
  v60.m128_i32[0] = *((_DWORD *)v8 + 26);
  v72 = v70;
  v72.m128_f32[0] = (float)((float)(v70.m128_f32[0] * v70.m128_f32[0]) + (float)(v71 * v71))
                  + (float)(v60.m128_f32[0] * v60.m128_f32[0]);
  LODWORD(v73) = (unsigned __int128)_mm_sqrt_ps(v72);
  v74 = (float)(1.0 / v73) * *((float *)v8 + 27);
  *((float *)v8 + 24) = (float)(1.0 / v73) * v71;
  *((float *)v8 + 25) = v70.m128_f32[0] * (float)(1.0 / v73);
  *((float *)v8 + 26) = v60.m128_f32[0] * (float)(1.0 / v73);
  *((float *)v8 + 27) = v74;
  v75 = (__m128)*((unsigned int *)v8 + 29);
  v76 = *((float *)v8 + 28);
  v60.m128_i32[0] = *((_DWORD *)v8 + 30);
  v77 = v75;
  v77.m128_f32[0] = (float)((float)(v75.m128_f32[0] * v75.m128_f32[0]) + (float)(v76 * v76))
                  + (float)(v60.m128_f32[0] * v60.m128_f32[0]);
  LODWORD(v78) = (unsigned __int128)_mm_sqrt_ps(v77);
  v79 = (float)(1.0 / v78) * *((float *)v8 + 31);
  *((float *)v8 + 28) = (float)(1.0 / v78) * v76;
  *((float *)v8 + 29) = v75.m128_f32[0] * (float)(1.0 / v78);
  *((float *)v8 + 30) = v60.m128_f32[0] * (float)(1.0 / v78);
  *((float *)v8 + 31) = v79;
  v80 = (__m128)*((unsigned int *)v8 + 33);
  v60.m128_i32[0] = *((_DWORD *)v8 + 32);
  v81 = *((float *)v8 + 34);
  v82 = v80;
  v82.m128_f32[0] = (float)((float)(v80.m128_f32[0] * v80.m128_f32[0]) + (float)(v60.m128_f32[0] * v60.m128_f32[0]))
                  + (float)(v81 * v81);
  LODWORD(v83) = (unsigned __int128)_mm_sqrt_ps(v82);
  v84 = (float)(1.0 / v83) * *((float *)v8 + 35);
  *((float *)v8 + 32) = v60.m128_f32[0] * (float)(1.0 / v83);
  *((float *)v8 + 33) = v80.m128_f32[0] * (float)(1.0 / v83);
  *((float *)v8 + 34) = v81 * (float)(1.0 / v83);
  *((float *)v8 + 35) = v84;
  v85 = (__m128)*((unsigned int *)v8 + 37);
  v86 = *((float *)v8 + 36);
  v87 = *((float *)v8 + 38);
  v88 = v85;
  v88.m128_f32[0] = (float)((float)(v85.m128_f32[0] * v85.m128_f32[0]) + (float)(v86 * v86)) + (float)(v87 * v87);
  LODWORD(v89) = (unsigned __int128)_mm_sqrt_ps(v88);
  v90 = (float)(1.0 / v89) * *((float *)v8 + 39);
  *((float *)v8 + 36) = v86 * (float)(1.0 / v89);
  *((float *)v8 + 37) = v85.m128_f32[0] * (float)(1.0 / v89);
  *((float *)v8 + 38) = v87 * (float)(1.0 / v89);
  *((float *)v8 + 39) = v90;
  v91 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v92 = (UFG::qTask *)v91;
  v106 = v91;
  v107 = v91;
  if ( v91 )
  {
    *(_QWORD *)v91 = v91;
    *((_QWORD *)v91 + 1) = v91;
    v93 = v91 + 16;
    *v93 = v93;
    v93[1] = v93;
    v94 = gTaskFunctionDeclData_UpdateLightingTask.mSpuElf;
    v95 = gTaskFunctionDeclData_UpdateLightingTask.mTaskFunctionSPU;
    v96 = gTaskFunctionDeclData_UpdateLightingTask.mTaskFunctionPPU;
    v97 = gTaskFunctionDeclData_UpdateLightingTask.mTaskFunctionOffload;
    if ( !gTaskFunctionDeclData_UpdateLightingTask.mCurrentSPUEnabled )
    {
      v94 = 0i64;
      v95 = 0i64;
      v97 = 0i64;
    }
    v92->mTaskGroup = 0i64;
    v92->mFlags = 2;
    v92->mSyncVars.i64 = 0i64;
    v92->mSyncVars.v.mDependents = 0i64;
    v92->mFunctionDeclData = &gTaskFunctionDeclData_UpdateLightingTask;
    if ( v94 )
      v98 = v94->mAddress;
    else
      v98 = 0i64;
    v92->mSPUElfAddress = v98;
    v92->mSPUFunction = v95;
    v92->mPPUFunction = v96;
    v92->mParam0 = v8;
    v92->mParam1 = 0i64;
    v92->mParam2 = 0i64;
    v92->mParam3 = 0i64;
    if ( v97 )
    {
      v92->mFlags = 130;
      v92->mOffloadThread = 0;
    }
  }
  v99 = UFG::gTaskManager.mSingleFrameTasks;
  v100 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  v100->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v92->mPrev;
  v92->mPrev = v100;
  v92->mNext = &v99->mNode;
  v99->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v92->mPrev;
  gUpdateLightTask = v92;
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v92);
}

// File Line: 1007
// RVA: 0x5D0C0
void __fastcall UpdateLightMaterial(Illusion::Material *lightmat, Render::Light *pLight, Render::LightInstance *lightInstance)
{
  Render::LightInstance *v3; // r15
  Render::Light *v4; // rbp
  Illusion::Material *v5; // rbx
  bool v6; // si
  char v7; // al
  _WORD *v8; // rdi
  __int64 v9; // rax
  _WORD *v10; // rax
  __int64 v11; // rax
  _WORD *v12; // rax
  unsigned int v13; // er8
  signed __int64 v14; // rcx
  signed int v15; // er8
  __int64 v16; // rax
  _WORD *v17; // rax
  unsigned int v18; // er8
  __int64 v19; // rax
  _WORD *v20; // rax
  signed int v21; // eax
  signed int v22; // er8
  __int64 v23; // rax
  _WORD *v24; // rax
  unsigned int v25; // er8
  __int64 v26; // rax
  _WORD *v27; // rax
  __int64 v28; // rax
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-88h]

  v3 = lightInstance;
  v4 = pLight;
  v5 = lightmat;
  v6 = pLight->mSpecular && !gNoSpecLights;
  v7 = pLight->mType;
  if ( v7 == 1 || v7 == 4 )
  {
    v22 = pLight->mTextureUID;
    if ( v22 == -1 )
      v22 = -1324127765;
    v8 = 0i64;
    if ( LODWORD(lightmat[4].mStateBlockMask.mFlags[1]) != v22 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&lightmat[4].mDebugName[28], lightmat[4].mNumParams, v22);
      v23 = v5->mMaterialUser.mOffset;
      if ( v23 )
        v24 = (_WORD *)((char *)&v5->mMaterialUser + v23);
      else
        v24 = 0i64;
      *v24 |= 0x20u;
    }
    v25 = v4->mTexDistAttenUID;
    if ( v25 == -1 )
      v25 = -1324127765;
    if ( *((_DWORD *)&v5[5].0 + 22) != v25 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5[5].mDebugName[12], v5[5].mStateBlockMask.mFlags[0], v25);
      v26 = v5->mMaterialUser.mOffset;
      if ( v26 )
        v27 = (_WORD *)((char *)&v5->mMaterialUser + v26);
      else
        v27 = 0i64;
      *v27 |= 0x20u;
    }
    if ( v3->flags & 2 )
    {
      Render::RenderOutputParams::RenderOutputParams(&outSettings);
      Render::GetCurrentDisplaySettings(&outSettings);
      if ( outSettings.mShadowFilter )
      {
        v21 = -1277344673;
        v13 = 1888878982;
      }
      else
      {
        v21 = 917301752;
        v13 = -1098878608;
      }
    }
    else
    {
      v21 = 1172639096;
      v13 = 185628407;
    }
    goto LABEL_61;
  }
  if ( v7 != 3 )
  {
    if ( v7 != 5 )
      return;
    v15 = pLight->mTextureUID;
    if ( v15 == -1 )
      v15 = -1324127765;
    v8 = 0i64;
    if ( LODWORD(lightmat[4].mStateBlockMask.mFlags[1]) != v15 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&lightmat[4].mDebugName[28], lightmat[4].mNumParams, v15);
      v16 = v5->mMaterialUser.mOffset;
      if ( v16 )
        v17 = (_WORD *)((char *)&v5->mMaterialUser + v16);
      else
        v17 = 0i64;
      *v17 |= 0x20u;
    }
    v18 = v4->mTexDistAttenUID;
    if ( v18 == -1 )
      v18 = -1324127765;
    if ( *((_DWORD *)&v5[5].0 + 22) != v18 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5[5].mDebugName[12], v5[5].mStateBlockMask.mFlags[0], v18);
      v19 = v5->mMaterialUser.mOffset;
      if ( v19 )
        v20 = (_WORD *)((char *)&v5->mMaterialUser + v19);
      else
        v20 = 0i64;
      *v20 |= 0x20u;
    }
    if ( !(v3->flags & 2) )
    {
      if ( v6 )
      {
        v13 = -1448921392;
      }
      else
      {
        v13 = 1753793710;
        if ( v4->mAreaLightNearOffset < 0.000099999997 )
          v13 = 246770660;
      }
      goto LABEL_63;
    }
    v21 = -1378019169;
    v13 = 732975129;
LABEL_61:
    if ( v6 )
      v13 = v21;
LABEL_63:
    if ( LODWORD(v5[1].mResourceHandles.mNode.mNext) == v13 )
      return;
    v14 = (signed __int64)&v5[1].mNode.mChild[1];
    goto LABEL_65;
  }
  v8 = 0i64;
  if ( LODWORD(lightmat[1].mResourceHandles.mNode.mNext) != -317094792 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&lightmat[1].mNode.mChild[1], lightmat[1].mTypeUID, 0xED198478);
    v9 = v5->mMaterialUser.mOffset;
    if ( v9 )
      v10 = (_WORD *)((char *)&v5->mMaterialUser + v9);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
  }
  if ( *(_DWORD *)&v5[3].mDebugName[12] != -262489691 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v5[3].mResourceHandles.mNode.mNext,
      *(_DWORD *)&v5[3].mDebugName[20],
      0xF05AB9A5);
    v11 = v5->mMaterialUser.mOffset;
    if ( v11 )
      v12 = (_WORD *)((char *)&v5->mMaterialUser + v11);
    else
      v12 = 0i64;
    *v12 |= 0x20u;
  }
  v13 = gLightCardTextureUID;
  if ( LODWORD(v5[4].mStateBlockMask.mFlags[1]) != gLightCardTextureUID )
  {
    v14 = (signed __int64)&v5[4].mDebugName[28];
LABEL_65:
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)v14, *(_DWORD *)(v14 + 32), v13);
    v28 = v5->mMaterialUser.mOffset;
    if ( v28 )
      v8 = (_WORD *)((char *)&v5->mMaterialUser + v28);
    *v8 |= 0x20u;
  }
}

// File Line: 1065
// RVA: 0x4DBF0
void __fastcall FlushLightCards(UFG::RenderContext *render_context, Render::View *view, Render::LightInstance *instances, unsigned int n_lights)
{
  unsigned int v4; // ebx
  Render::LightInstance *v5; // r14
  Render::View *v6; // r12
  UFG::RenderContext *v7; // r13
  int v8; // esi
  char *v9; // rax
  char *v10; // r15
  int v11; // er10
  __int64 v12; // rbp
  LightCardInfo *v13; // rbx
  Render::LightInstance *v14; // rdi
  signed __int64 v15; // rdx
  float v16; // xmm13_4
  LightCardInfo *v17; // r8
  Render::Light *v18; // r11
  int v19; // eax
  LightCardInfo *v20; // rcx
  float v21; // xmm5_4
  float v22; // xmm8_4
  float v23; // xmm7_4
  float v24; // xmm4_4
  float v25; // xmm14_4
  float v26; // xmm6_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm15_4
  float v32; // ST40_4
  float v33; // xmm14_4
  float v34; // xmm10_4
  float v35; // xmm9_4
  float v36; // xmm11_4
  float v37; // xmm5_4
  int v38; // xmm3_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  unsigned int v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // eax
  Illusion::Primitive *v50; // rbx
  float v51; // [rsp+40h] [rbp-F8h]
  float v52; // [rsp+44h] [rbp-F4h]
  float v53; // [rsp+48h] [rbp-F0h]
  float v54; // [rsp+4Ch] [rbp-ECh]
  float v55; // [rsp+50h] [rbp-E8h]
  float v56; // [rsp+54h] [rbp-E4h]
  float v57; // [rsp+58h] [rbp-E0h]
  float v58; // [rsp+140h] [rbp+8h]
  float v59; // [rsp+140h] [rbp+8h]
  float v60; // [rsp+150h] [rbp+18h]
  float v61; // [rsp+158h] [rbp+20h]
  float v62; // [rsp+158h] [rbp+20h]

  v4 = n_lights;
  v5 = instances;
  v6 = view;
  v7 = render_context;
  v52 = UFG::TimeOfDayManager::GetInstance()->mExposure;
  v8 = 6 * v4;
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 216 * v4, 0x10u);
  v10 = v9;
  if ( v4 )
  {
    v11 = gLightCardInfoCount;
    v12 = v4;
    v13 = gLightCardInfos;
    v14 = v5;
    v15 = (signed __int64)(v9 + 44);
    v16 = FLOAT_0_5;
    do
    {
      v17 = v13;
      v18 = gLights[v14->lightIndex];
      v19 = 0;
      if ( v11 > 0 )
      {
        v20 = v13;
        while ( v20->m_nameUID != v18->mTextureUID )
        {
          ++v19;
          ++v20;
          if ( v19 >= v11 )
            goto LABEL_9;
        }
        v17 = &v13[v19];
      }
LABEL_9:
      v21 = v18->mTransform.v0.x * -0.5;
      v22 = v18->mTransform.v0.x * v16;
      v23 = v18->mTransform.v0.y * v16;
      v24 = v18->mTransform.v0.y * -0.5;
      v25 = v18->mTransform.v3.y;
      v26 = v18->mTransform.v0.z * v16;
      v27 = v18->mTransform.v1.x * -0.5;
      v28 = v18->mTransform.v0.z * -0.5;
      v60 = v25;
      v29 = v18->mTransform.v1.z * -0.5;
      v30 = v18->mTransform.v1.y * -0.5;
      v61 = v18->mTransform.v3.x;
      v58 = v18->mTransform.v3.z;
      v53 = (float)(v61 + v22) + v27;
      v31 = (float)(v58 + v26) + v29;
      v32 = v25 + v24;
      v33 = (float)(v25 + v23) + v30;
      v34 = v18->mTransform.v1.y * 0.5;
      v35 = v18->mTransform.v1.z * 0.5;
      v36 = v18->mTransform.v1.x * 0.5;
      v51 = v32 + v30;
      v56 = (float)(v61 + v21) + v27;
      v55 = (float)(v58 + v28) + v35;
      v57 = (float)(v58 + v28) + v29;
      v54 = (float)(v61 + v21) + v36;
      v62 = (float)(v61 + v22) + v36;
      v59 = (float)(v58 + v26) + v35;
      v37 = (float)(v60 + v24) + v34;
      if ( v18->mBiasLightCard )
        v38 = (signed int)FLOAT_1_0;
      else
        v38 = 0;
      v39 = v14->colorFade;
      v40 = v39;
      v41 = v39 * v18->mColor.z;
      v42 = v40 * v18->mColor.x;
      v43 = v14->colorFade * v18->mColor.y;
      *(float *)(v15 - 44) = v62;
      *(float *)(v15 - 40) = (float)(v60 + v23) + v34;
      *(float *)(v15 - 36) = v59;
      *(_DWORD *)(v15 - 16) = v17->m_UVs[0];
      v44 = v42 * v52;
      v45 = v43 * v52;
      v46 = v41 * v52;
      *(float *)(v15 - 8) = v53;
      *(float *)(v15 - 4) = v33;
      *(float *)v15 = v31;
      *(_DWORD *)(v15 + 20) = v17->m_UVs[3];
      *(float *)(v15 + 28) = v54;
      *(float *)(v15 + 32) = v37;
      *(float *)(v15 + 36) = v55;
      *(_DWORD *)(v15 + 56) = v17->m_UVs[1];
      *(float *)(v15 + 64) = v54;
      *(float *)(v15 + 68) = v37;
      *(float *)(v15 + 72) = v55;
      *(_DWORD *)(v15 + 92) = v17->m_UVs[1];
      *(float *)(v15 + 100) = v53;
      *(float *)(v15 + 104) = v33;
      *(float *)(v15 + 108) = v31;
      *(_DWORD *)(v15 + 128) = v17->m_UVs[3];
      *(float *)(v15 + 136) = v56;
      *(float *)(v15 + 144) = v57;
      *(float *)(v15 + 140) = v51;
      *(_DWORD *)(v15 + 164) = v17->m_UVs[2];
      *(float *)(v15 - 32) = v44;
      *(float *)(v15 - 28) = v45;
      *(float *)(v15 - 24) = v46;
      *(_DWORD *)(v15 - 20) = v38;
      v47 = v17->m_channelMask;
      *(float *)(v15 + 4) = v44;
      *(float *)(v15 + 8) = v45;
      *(_DWORD *)(v15 - 12) = v47;
      *(float *)(v15 + 12) = v46;
      *(_DWORD *)(v15 + 16) = v38;
      *(_DWORD *)(v15 + 24) = v17->m_channelMask;
      *(float *)(v15 + 40) = v44;
      *(float *)(v15 + 44) = v45;
      *(float *)(v15 + 48) = v46;
      *(_DWORD *)(v15 + 52) = v38;
      v48 = v17->m_channelMask;
      *(float *)(v15 + 76) = v44;
      *(float *)(v15 + 80) = v45;
      *(_DWORD *)(v15 + 60) = v48;
      *(float *)(v15 + 84) = v46;
      *(_DWORD *)(v15 + 88) = v38;
      *(_DWORD *)(v15 + 96) = v17->m_channelMask;
      *(float *)(v15 + 112) = v44;
      *(float *)(v15 + 116) = v45;
      *(float *)(v15 + 120) = v46;
      *(_DWORD *)(v15 + 124) = v38;
      v49 = v17->m_channelMask;
      *(float *)(v15 + 148) = v44;
      *(float *)(v15 + 152) = v45;
      *(_DWORD *)(v15 + 132) = v49;
      *(float *)(v15 + 156) = v46;
      v16 = FLOAT_0_5;
      *(_DWORD *)(v15 + 160) = v38;
      *(_DWORD *)(v15 + 168) = v17->m_channelMask;
      v15 += 216i64;
      ++v14;
      --v12;
    }
    while ( v12 );
  }
  UpdateLightMaterial(v7->mLightMaterial, gLights[v5->lightIndex], v5);
  v50 = Illusion::Primitive::Create("LightCards");
  Illusion::Primitive::SetBuffers(
    v50,
    TRIANGLELIST,
    v10,
    v8,
    (Illusion::VertexDecl *)gLightCardVertexDecl.mData,
    0i64,
    0,
    1);
  Render::View::Draw(v6, v50, v7->mLightMaterial, &UFG::qMatrix44::msIdentity);
}

// File Line: 1138
// RVA: 0x519A0
bool __fastcall IrradianceVolumeSortCompare(Render::IrradianceVolume *a, Render::IrradianceVolume *b)
{
  char v2; // r8
  bool result; // al

  v2 = a->mFlags & 4;
  if ( v2 == (b->mFlags & 4) )
    result = (float)((float)(b->mImageDimensions[0] * b->mImageDimensions[1] * b->mImageDimensions[2])
                   / (float)((float)(b->mScale.y * b->mScale.x) * b->mScale.z)) > (float)((float)(a->mImageDimensions[0]
                                                                                                * a->mImageDimensions[1]
                                                                                                * a->mImageDimensions[2])
                                                                                        / (float)((float)(a->mScale.y * a->mScale.x)
                                                                                                * a->mScale.z));
  else
    result = v2 != 0;
  return result;
}

// File Line: 1158
// RVA: 0x4B710
void __fastcall DrawIrradianceVolumes(UFG::RenderContext *render_context, Render::View *view, int irradiance_type)
{
  int v3; // er12
  Render::View *v4; // r15
  unsigned int v5; // eax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  __int64 v8; // r14
  UFG::qBaseTreeRB *i; // rsi
  unsigned int v10; // edi
  UFG::qBaseNodeRB *v11; // rax
  signed __int64 v12; // rcx
  Render::IrradianceVolume *v13; // rbx
  UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *v14; // rsi
  Render::IrradianceVolumeComponent *v15; // rbx
  signed __int64 v16; // r13
  Render::IrradianceVolume *v17; // rdi
  unsigned int *v18; // rbx
  signed __int64 v19; // rsi
  Render::IrradianceVolume **v20; // r12
  signed __int64 v21; // rax
  int v22; // ecx
  signed __int64 v23; // rsi
  Render::IrradianceVolume *v24; // rdi
  Render::IrradianceVolume *v25; // rbx
  Render::IrradianceVolume *v26; // rdi
  Render::IrradianceVolume *v27; // r13
  Render::IrradianceVolume *v28; // rdi
  Render::IrradianceVolume *v29; // rsi
  Render::IrradianceVolume **v30; // rdi
  Render::IrradianceVolume **v31; // rbx
  Render::IrradianceVolume *v32; // rcx
  __int64 v33; // r12
  __int64 *v34; // r13
  UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *v35; // rax
  Render::IrradianceVolume *v36; // rsi
  __int64 v37; // rbx
  __int64 v38; // rdi
  UFG::RenderContext *v39; // rbx
  float v40; // xmm0_4
  float v41; // xmm15_4
  int v42; // xmm3_4
  int v43; // xmm4_4
  int v44; // xmm13_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm13_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm6_4
  float v51; // xmm0_4
  unsigned int j; // ecx
  unsigned int v53; // eax
  __int64 v54; // rdi
  char v55; // cl
  float v56; // xmm7_4
  float v57; // xmm12_4
  int v58; // xmm11_4
  char v59; // al
  __int64 v60; // rdx
  Illusion::Material *v61; // rsi
  float v62; // xmm4_4
  float v63; // xmm0_4
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm5_4
  float v67; // xmm1_4
  float v68; // xmm2_4
  float v69; // xmm1_4
  float v70; // xmm6_4
  float v71; // xmm2_4
  float v72; // xmm1_4
  float v73; // xmm2_4
  float v74; // xmm3_4
  float v75; // xmm1_4
  float v76; // xmm2_4
  float v77; // xmm3_4
  float v78; // xmm1_4
  float v79; // xmm2_4
  float v80; // xmm3_4
  float v81; // xmm1_4
  float v82; // xmm2_4
  float v83; // xmm3_4
  float v84; // xmm1_4
  float v85; // xmm2_4
  float v86; // xmm3_4
  char v87; // al
  unsigned int v88; // er8
  __int64 v89; // rax
  _WORD *v90; // rax
  unsigned int v91; // er8
  __int64 v92; // rax
  _WORD *v93; // rax
  unsigned int v94; // er8
  __int64 v95; // rax
  _WORD *v96; // rax
  float v97; // xmm4_4
  float v98; // xmm3_4
  float v99; // xmm2_4
  float v100; // xmm5_4
  float v101; // xmm2_4
  float v102; // xmm1_4
  signed int v103; // er13
  char v104; // r12
  signed __int64 v105; // rax
  float v106; // xmm0_4
  __int128 v107; // xmm2
  __int128 v108; // xmm1
  __int128 v109; // xmm0
  __int128 v110; // xmm2
  __int128 v111; // xmm1
  __int128 v112; // xmm0
  char *v113; // rbx
  UFG::TimeOfDayManager *v114; // rax
  UFG::TimeOfDayManager *v115; // rax
  UFG::TimeOfDayManager *v116; // rax
  Illusion::StateValues *v117; // rax
  unsigned __int16 v118; // ax
  unsigned int v119; // er8
  __int64 v120; // rax
  _WORD *v121; // rax
  Illusion::Primitive *v122; // rbx
  float v123; // xmm12_4
  float v124; // xmm11_4
  float v125; // xmm7_4
  UFG::qVector3 *v126; // rdi
  unsigned int v127; // er8
  __int64 v128; // rax
  _WORD *v129; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v130; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v131; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v132; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v133; // rax
  unsigned int v134; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 scale; // [rsp+48h] [rbp-B8h]
  UFG::qMatrix44 v136; // [rsp+60h] [rbp-A0h]
  float v137; // [rsp+A0h] [rbp-60h]
  float v138; // [rsp+A4h] [rbp-5Ch]
  float v139; // [rsp+A8h] [rbp-58h]
  float v140; // [rsp+ACh] [rbp-54h]
  float v141; // [rsp+B0h] [rbp-50h]
  UFG::qMatrix44 m; // [rsp+C0h] [rbp-40h]
  Illusion::StateArgs *v143; // [rsp+100h] [rbp+0h]
  Render::cbShadowTransformState arg; // [rsp+110h] [rbp+10h]
  float v145; // [rsp+170h] [rbp+70h]
  float v146; // [rsp+174h] [rbp+74h]
  float v147; // [rsp+178h] [rbp+78h]
  UFG::qVector3 v148; // [rsp+180h] [rbp+80h]
  float v149; // [rsp+190h] [rbp+90h]
  float v150; // [rsp+194h] [rbp+94h]
  float v151; // [rsp+198h] [rbp+98h]
  int v152; // [rsp+19Ch] [rbp+9Ch]
  float v153; // [rsp+1A0h] [rbp+A0h]
  float v154; // [rsp+1A4h] [rbp+A4h]
  float v155; // [rsp+1A8h] [rbp+A8h]
  float v156; // [rsp+1ACh] [rbp+ACh]
  UFG::qColour colour; // [rsp+1B0h] [rbp+B0h]
  UFG::qVector4 plane; // [rsp+1C0h] [rbp+C0h]
  UFG::qColour v159; // [rsp+1D0h] [rbp+D0h]
  UFG::qMatrix44 v160; // [rsp+1E0h] [rbp+E0h]
  UFG::qMatrix44 d; // [rsp+220h] [rbp+120h]
  __int64 v162; // [rsp+260h] [rbp+160h]
  __int128 v163; // [rsp+270h] [rbp+170h]
  __int128 v164; // [rsp+280h] [rbp+180h]
  __int128 v165; // [rsp+290h] [rbp+190h]
  __int128 v166; // [rsp+2A0h] [rbp+1A0h]
  __int128 v167; // [rsp+2B0h] [rbp+1B0h]
  __int128 v168; // [rsp+2C0h] [rbp+1C0h]
  __int128 v169; // [rsp+2D0h] [rbp+1D0h]
  __int128 v170; // [rsp+2E0h] [rbp+1E0h]
  UFG::qMatrix44 v171; // [rsp+2F0h] [rbp+1F0h]
  UFG::qMatrix44 v172; // [rsp+330h] [rbp+230h]
  Render::IrradianceVolume *a; // [rsp+370h] [rbp+270h]
  __int64 v174[255]; // [rsp+378h] [rbp+278h]
  ClipCube v175; // [rsp+B70h] [rbp+A70h]
  char dest[1008]; // [rsp+DB0h] [rbp+CB0h]
  UFG::RenderContext *v177; // [rsp+1280h] [rbp+1180h]
  float distance_from_near_plane; // [rsp+1290h] [rbp+1190h]
  UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *vertex_count; // [rsp+1298h] [rbp+1198h]

  if ( irradiance_type )
  {
    v177 = render_context;
    v162 = -2i64;
    v3 = irradiance_type;
    v4 = view;
    v5 = _S6_0;
    if ( !(_S6_0 & 1) )
    {
      _S6_0 |= 1u;
      v6 = UFG::qResourceWarehouse::Instance();
      light_inventory_0 = UFG::qResourceWarehouse::GetInventory(v6, 0xF0A0724F);
      v5 = _S6_0;
    }
    if ( !(v5 & 2) )
    {
      _S6_0 = v5 | 2;
      v7 = UFG::qResourceWarehouse::Instance();
      texture_inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x8B43FABF);
    }
    v8 = 0i64;
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&light_inventory_0->mResourceDatas);
          i;
          i = UFG::qBaseTreeRB::GetNext(&light_inventory_0->mResourceDatas.mTree, &i->mRoot) )
    {
      v10 = 0;
      if ( LODWORD(i[2].mNULL.mParent) )
      {
        do
        {
          v11 = i[2].mRoot.mParent;
          if ( v11 )
            v12 = (signed __int64)&i[2] + (_QWORD)v11;
          else
            v12 = 0i64;
          v13 = (Render::IrradianceVolume *)(v12 + 496i64 * v10);
          if ( v13->mType == v3
            && (unsigned int)Render::View::IsInView(
                               v4,
                               &gDeferredCube,
                               (UFG::qMatrix44 *)(v12 + 496i64 * v10),
                               &distance_from_near_plane) )
          {
            *(&a + v8) = v13;
            v8 = (unsigned int)(v8 + 1);
          }
          ++v10;
        }
        while ( v10 < LODWORD(i[2].mNULL.mParent) );
      }
    }
    UFG::qMemSet(dest, 0, 0x3E8u);
    v14 = &Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList - 4;
    vertex_count = &Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList - 4;
    v15 = (Render::IrradianceVolumeComponent *)&Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList.mNode.mNext[-4];
    if ( (UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *)&Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList.mNode.mNext[-4] != &Render::IrradianceVolumeComponent::s_IrradianceVolumeComponentList - 4 )
    {
      do
      {
        v16 = (signed __int64)&v15->mNext[-4];
        v17 = &v15->mIrradianceVolume;
        if ( v15->mIrradianceVolume.mType == v3
          && (unsigned int)Render::View::IsInView(
                             v4,
                             &gDeferredCube,
                             &v15->mIrradianceVolume.mTransform,
                             &distance_from_near_plane) )
        {
          if ( !v15->mIrradianceVolume.mTextureUID[2] || !((__int64 (*)(void))texture_inventory->vfptr->Get)() )
            Render::IrradianceVolumeComponent::UpdateTextureUIDs(v15);
          if ( distance_from_near_plane < 600.0
            && (v15->mIrradianceVolume.mTextureUID[2] && ((__int64 (*)(void))texture_inventory->vfptr->Get)()
             || v15->mIrradianceVolume.mFlags & 1) )
          {
            if ( v15->mIrradianceVolume.mFlags & 0x10 )
            {
              if ( UFG::SectionChooser::GetSTDStreamingStateForSectionIndex(v15->mIrradianceVolume.mSectionIndex) == 1 )
              {
                --dest[v15->mIrradianceVolume.mSectionIndex];
              }
              else
              {
                v18 = v15->mIrradianceVolume.mTextureUID;
                v19 = 3i64;
                do
                {
                  if ( *v18 )
                    Render::SetHighPriorityLoad(*v18);
                  ++v18;
                  --v19;
                }
                while ( v19 );
                v14 = vertex_count;
              }
            }
            if ( v17->mFlags & 0x20 )
              ++dest[v17->mSectionIndex];
            *(&a + v8) = v17;
            v8 = (unsigned int)(v8 + 1);
          }
        }
        v15 = (Render::IrradianceVolumeComponent *)v16;
      }
      while ( (UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *)v16 != v14 );
    }
    v20 = (Render::IrradianceVolume **)(&v172.v3.z + 2 * (signed int)v8);
    v21 = (8i64 * (signed int)v8 - 8) >> 3;
    v22 = v21 + 1;
    if ( (signed int)v21 + 1 < 32 )
    {
      if ( v22 >= 2i64 )
      {
        v33 = 0i64;
        v34 = v174;
        v35 = (UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *)(v22 - 1i64);
        vertex_count = (UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *)(v22 - 1i64);
        do
        {
          v36 = (Render::IrradianceVolume *)*v34;
          v37 = v33;
          if ( v33 >= 0 )
          {
            do
            {
              v38 = (__int64)*(&a + v37);
              if ( !IrradianceVolumeSortCompare(v36, *(&a + v37)) )
                break;
              v174[v37--] = v38;
            }
            while ( v37 >= 0 );
            v35 = vertex_count;
          }
          v174[v37] = (__int64)v36;
          ++v34;
          ++v33;
          v35 = (UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *)((char *)v35 - 1);
          vertex_count = v35;
        }
        while ( v35 );
      }
    }
    else
    {
      v23 = v21 / 2;
      v24 = *(&a + v21 / 2);
      v25 = a;
      if ( IrradianceVolumeSortCompare(*(&a + v21 / 2), a) )
      {
        *(&a + v23) = v25;
        v25 = v24;
        a = v24;
      }
      v26 = *(&a + v23);
      v27 = *v20;
      if ( IrradianceVolumeSortCompare(*v20, *(&a + v23)) )
      {
        *v20 = v26;
        *(&a + v23) = v27;
        v25 = a;
      }
      v28 = *(&a + v23);
      if ( IrradianceVolumeSortCompare(*(&a + v23), v25) )
      {
        *(&a + v23) = v25;
        a = v28;
      }
      v29 = *(&a + v23);
      v30 = &a;
      v31 = (Render::IrradianceVolume **)(&v172.v3.z + 2 * (signed int)v8);
      if ( &a <= v20 )
      {
        do
        {
          for ( ; IrradianceVolumeSortCompare(*v30, v29); ++v30 )
          {
            if ( v30 >= v20 )
              break;
          }
          for ( ; IrradianceVolumeSortCompare(v29, *v31); --v31 )
          {
            if ( &a >= v31 )
              break;
          }
          if ( v30 > v31 )
            break;
          v32 = *v30;
          *v30 = *v31;
          *v31 = v32;
          ++v30;
          --v31;
        }
        while ( v30 <= v31 );
      }
      if ( &a < v31 )
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
          &a,
          v31,
          IrradianceVolumeSortCompare);
      if ( v30 < v20 )
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
          v30,
          (Render::IrradianceVolume **)&v172.v3.z + (signed int)v8,
          IrradianceVolumeSortCompare);
    }
    v39 = v177;
    UFG::qInverseAffine(&d, &v177->mMainViewSettings.mWorldView);
    v40 = v177->mMainViewSettings.mProjection.v2.z;
    if ( v40 == 0.0 || v40 == v177->mMainViewSettings.mProjection.v2.w )
      v41 = distance_from_near_plane;
    else
      v41 = v177->mMainViewSettings.mProjection.v3.z / v40;
    v42 = LODWORD(d.v2.z) ^ _xmm[0];
    v43 = LODWORD(d.v2.y) ^ _xmm[0];
    v44 = LODWORD(d.v2.x) ^ _xmm[0];
    v45 = (float)((float)(*(float *)&v44 * *(float *)&v44) + (float)(*(float *)&v43 * *(float *)&v43))
        + (float)(*(float *)&v42 * *(float *)&v42);
    if ( v45 == 0.0 )
      v46 = 0.0;
    else
      v46 = 1.0 / fsqrt(v45);
    v137 = v46 * *(float *)&v42;
    v139 = v46 * *(float *)&v43;
    v47 = *(float *)&v44 * v46;
    v48 = v177->mMainViewSettings.mProjection.v0.x;
    if ( v48 == 0.0 )
      v49 = 0.0;
    else
      v49 = atan2f(1.0, v48) * 2.0;
    v50 = tanf(v49 * 0.5);
    v51 = Render::GetDisplayAspectRatio();
    v138 = d.v3.x;
    v141 = d.v3.y;
    distance_from_near_plane = d.v3.z;
    v140 = fsqrt(
             (float)((float)((float)(v50 * v41) * (float)(v50 * v41))
                   + (float)((float)((float)(v50 / v51) * v41) * (float)((float)(v50 / v51) * v41)))
           + (float)(v41 * v41));
    ClipCube::ClipCube(&v175);
    for ( j = 0; ; j = v134 + 1 )
    {
      v134 = j;
      v53 = 128;
      if ( (unsigned int)v8 < 0x80 )
        v53 = v8;
      if ( j >= v53 )
        return;
      v54 = (__int64)*(&a + j);
      v55 = *(_BYTE *)(v54 + 363);
      if ( (!(v55 & 0x20) || dest[*(signed int *)(v54 + 492)] > 0)
        && (!(v55 & 0x10) || dest[*(signed int *)(v54 + 492)] <= 0) )
      {
        v56 = v39->mEnvState->AmbientColorHorizon[3];
        v57 = FLOAT_0_1;
        v58 = 0;
        scale.x = 1.0;
        scale.y = -1.0;
        scale.z = 0.5;
        v59 = *(_BYTE *)(v54 + 363);
        if ( v59 & 2 )
        {
          v56 = *(float *)&FLOAT_1_0;
          v57 = 0.0;
        }
        if ( v59 & 4 )
        {
          v58 = (signed int)FLOAT_1_0;
          scale.y = 1.0;
        }
        if ( *(_BYTE *)(v54 + 362) != 2 || v56 > 0.0 )
        {
          v60 = *(unsigned int *)(v54 + 376);
          if ( (_DWORD)v60 )
          {
            if ( ((__int64 (__cdecl *)(UFG::qResourceInventory *, __int64))texture_inventory->vfptr->Get)(
                   texture_inventory,
                   v60) )
            {
              break;
            }
          }
          if ( *(_BYTE *)(v54 + 363) & 1 )
            break;
        }
      }
LABEL_174:
      ;
    }
    v61 = v39->mIrradianceVolumeMaterial;
    v62 = *(float *)v54;
    v63 = *(float *)(v54 + 4);
    v64 = *(float *)(v54 + 8);
    v65 = *(float *)(v54 + 12);
    m.v0.x = *(float *)v54;
    m.v0.y = v63;
    m.v0.z = v64;
    m.v0.w = v65;
    v66 = *(float *)(v54 + 20);
    v67 = *(float *)(v54 + 24);
    v68 = *(float *)(v54 + 28);
    m.v1.x = *(float *)(v54 + 16);
    m.v1.y = v66;
    m.v1.z = v67;
    m.v1.w = v68;
    v69 = *(float *)(v54 + 36);
    v70 = *(float *)(v54 + 40);
    v71 = *(float *)(v54 + 44);
    m.v2.x = *(float *)(v54 + 32);
    m.v2.y = v69;
    m.v2.z = v70;
    m.v2.w = v71;
    v72 = *(float *)(v54 + 52);
    v73 = *(float *)(v54 + 56);
    v74 = *(float *)(v54 + 60);
    m.v3.x = *(float *)(v54 + 48);
    m.v3.y = v72;
    m.v3.z = v73;
    m.v3.w = v74;
    v75 = *(float *)(v54 + 68);
    v76 = *(float *)(v54 + 72);
    v77 = *(float *)(v54 + 76);
    v136.v0.x = *(float *)(v54 + 64);
    v136.v0.y = v75;
    v136.v0.z = v76;
    v136.v0.w = v77;
    v78 = *(float *)(v54 + 84);
    v79 = *(float *)(v54 + 88);
    v80 = *(float *)(v54 + 92);
    v136.v1.x = *(float *)(v54 + 80);
    v136.v1.y = v78;
    v136.v1.z = v79;
    v136.v1.w = v80;
    v81 = *(float *)(v54 + 100);
    v82 = *(float *)(v54 + 104);
    v83 = *(float *)(v54 + 108);
    v136.v2.x = *(float *)(v54 + 96);
    v136.v2.y = v81;
    v136.v2.z = v82;
    v136.v2.w = v83;
    v84 = *(float *)(v54 + 116);
    v85 = *(float *)(v54 + 120);
    v86 = *(float *)(v54 + 124);
    v136.v3.x = *(float *)(v54 + 112);
    v136.v3.y = v84;
    v136.v3.z = v85;
    v136.v3.w = v86;
    if ( *(_BYTE *)(v54 + 362) == 2 )
    {
      v87 = *(_BYTE *)(v54 + 363);
      v61 = v87 & 1 ? v39->mIrradianceVolumeSkyBlackMaterial : v39->mIrradianceVolumeSkyMaterial;
      if ( v87 & 4 )
      {
        m.v0.x = v62 + 0.1;
        m.v1.y = v66 + 0.1;
        m.v2.z = v70 + 0.1;
        UFG::qInverse(&v136, &m);
        v61 = v39->mIrradianceVolumeSkyMaterial2;
      }
    }
    v88 = -1324127765;
    if ( *(_DWORD *)(v54 + 368) )
      v88 = *(_DWORD *)(v54 + 368);
    if ( LODWORD(v61[3].mMaterialUser.mOffset) != v88 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&v61[3].mStateBlockMask,
        (unsigned int)v61[4].mNode.mParent,
        v88);
      v89 = v61->mMaterialUser.mOffset;
      if ( v89 )
        v90 = (_WORD *)((char *)&v61->mMaterialUser + v89);
      else
        v90 = 0i64;
      *v90 |= 0x20u;
    }
    v91 = -1324127765;
    if ( *(_DWORD *)(v54 + 372) )
      v91 = *(_DWORD *)(v54 + 372);
    if ( v61[4].mTypeUID != v91 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v61[4].mNode.mUID, *(_DWORD *)&v61[4].mDebugName[4], v91);
      v92 = v61->mMaterialUser.mOffset;
      if ( v92 )
        v93 = (_WORD *)((char *)&v61->mMaterialUser + v92);
      else
        v93 = 0i64;
      *v93 |= 0x20u;
    }
    v94 = -1324127765;
    if ( *(_DWORD *)(v54 + 376) )
      v94 = *(_DWORD *)(v54 + 376);
    if ( LODWORD(v61[4].mStateBlockMask.mFlags[1]) != v94 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v61[4].mDebugName[28], v61[4].mNumParams, v94);
      v95 = v61->mMaterialUser.mOffset;
      if ( v95 )
        v96 = (_WORD *)((char *)&v61->mMaterialUser + v95);
      else
        v96 = 0i64;
      *v96 |= 0x20u;
    }
    v97 = (float)((float)((float)(v138 * v136.v0.x) + (float)(v141 * v136.v1.x))
                + (float)(distance_from_near_plane * v136.v2.x))
        + v136.v3.x;
    v98 = (float)((float)((float)(v138 * v136.v0.y) + (float)(v141 * v136.v1.y))
                + (float)(distance_from_near_plane * v136.v2.y))
        + v136.v3.y;
    v99 = (float)((float)((float)(v138 * v136.v0.z) + (float)(v141 * v136.v1.z))
                + (float)(distance_from_near_plane * v136.v2.z))
        + v136.v3.z;
    v100 = (float)((float)((float)(v138 * v136.v0.w) + (float)(v141 * v136.v1.w))
                 + (float)(distance_from_near_plane * v136.v2.w))
         + v136.v3.w;
    if ( v100 < 0.0 )
      LODWORD(v100) ^= _xmm[0];
    if ( v99 < 0.0 )
      LODWORD(v99) ^= _xmm[0];
    if ( v98 < 0.0 )
      LODWORD(v98) ^= _xmm[0];
    if ( v97 < 0.0 )
      LODWORD(v97) ^= _xmm[0];
    v153 = v97;
    v154 = v98;
    v155 = v99;
    v156 = v100;
    v101 = (float)(1.0 / *(float *)(v54 + 340)) * v140;
    v102 = (float)(1.0 / *(float *)(v54 + 336)) * v140;
    v145 = (float)(1.0 / *(float *)(v54 + 332)) * v140;
    v146 = v102;
    v147 = v101;
    v103 = 1;
    v104 = 0;
    v105 = 0i64;
    while ( 1 )
    {
      v106 = *(float *)((char *)&v153 + v105);
      if ( v106 > 1.0 )
        break;
      v105 += 4i64;
      if ( v105 >= 12 )
      {
        if ( *(_BYTE *)(v54 + 362) == 2 )
          UFG::RenderStageExposureMetering::SetCameraIrradianceVolume(
            UFG::RenderWorld::msExposureMetering,
            (Render::IrradianceVolume *)v54);
        goto LABEL_135;
      }
    }
    v104 = 0;
    if ( (float)(*(float *)((char *)&v145 + v105) + 1.0) > v106 )
      v104 = 1;
    v103 = 2;
LABEL_135:
    v143 = Render::View::GetStateArgs(v4);
    v107 = *(_OWORD *)(v54 + 80);
    v108 = *(_OWORD *)(v54 + 96);
    v109 = *(_OWORD *)(v54 + 112);
    v163 = *(_OWORD *)(v54 + 64);
    v164 = v107;
    v165 = v108;
    v166 = v109;
    v110 = *(_OWORD *)(v54 + 272);
    v111 = *(_OWORD *)(v54 + 288);
    v112 = *(_OWORD *)(v54 + 304);
    v167 = *(_OWORD *)(v54 + 256);
    v168 = v110;
    v169 = v111;
    v170 = v112;
    UFG::qScaleMatrix(&v171, &scale);
    v171.v3.z = 0.5;
    v148.x = scale.x * 2.0;
    v148.y = scale.y * 2.0;
    v148.z = scale.z * 2.0;
    UFG::qScaleMatrix(&v172, &v148);
    v172.v3.x = -0.5;
    v172.v3.y = -0.5;
    v113 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    v114 = UFG::TimeOfDayManager::GetInstance();
    *(float *)&v111 = v114->mAmbientSkyDirection[0].y;
    *(float *)&v110 = v114->mAmbientSkyDirection[0].z;
    *(float *)v113 = v114->mAmbientSkyDirection[0].x;
    *((_DWORD *)v113 + 1) = v111;
    *((_DWORD *)v113 + 2) = v110;
    v115 = UFG::TimeOfDayManager::GetInstance();
    *(float *)&v111 = v115->mAmbientSkyDirection[1].y;
    *(float *)&v110 = v115->mAmbientSkyDirection[1].z;
    *((_DWORD *)v113 + 4) = LODWORD(v115->mAmbientSkyDirection[1].x);
    *((_DWORD *)v113 + 5) = v111;
    *((_DWORD *)v113 + 6) = v110;
    v116 = UFG::TimeOfDayManager::GetInstance();
    *(float *)&v111 = v116->mAmbientSkyDirection[2].y;
    *(float *)&v110 = v116->mAmbientSkyDirection[2].z;
    *((_DWORD *)v113 + 8) = LODWORD(v116->mAmbientSkyDirection[2].x);
    *((_DWORD *)v113 + 9) = v111;
    *((_DWORD *)v113 + 10) = v110;
    *((float *)v113 + 12) = v57;
    *((_DWORD *)v113 + 13) = 1065353216;
    *((float *)v113 + 14) = v56;
    *((_DWORD *)v113 + 15) = v58;
    v117 = Render::View::GetStateValues(v4);
    v117->mSetValueMask.mFlags[0] |= 0x8000ui64;
    v117->mParamValues[15] = v113;
    v149 = (float)(*(float *)(v54 + 332) / (float)*(signed __int16 *)(v54 + 356)) / (float)(*(float *)(v54 + 332) * 2.0);
    v150 = (float)(*(float *)(v54 + 336) / (float)*(signed __int16 *)(v54 + 358)) / (float)(*(float *)(v54 + 336) * 2.0);
    v151 = (float)(*(float *)(v54 + 340) / (float)*(signed __int16 *)(v54 + 360)) / (float)(*(float *)(v54 + 340) * 2.0);
    v152 = 0;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
    {
      v118 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
      Render::cbShadowTransformState::sStateParamIndex = v118;
      arg.mStateParamIndex = v118;
    }
    arg.mViewWorld = &v4->mViewWorld;
    arg.mWorldView = (UFG::qMatrix44 *)&v163;
    arg.mProjection = &v171;
    arg.mCutplanes = 0i64;
    arg.mBiases = &v149;
    arg.mBlurWidths = 0i64;
    arg.mCached_Remote.m_Stream = 0i64;
    Illusion::StateArgs::Set<Render::cbShadowTransformState>(v143, &arg);
    if ( v103 == 1 )
    {
      UFG::RenderStageExposureMetering::SetCameraIrradianceVolume(
        UFG::RenderWorld::msExposureMetering,
        (Render::IrradianceVolume *)v54);
      if ( gClearStencil )
      {
        *(_QWORD *)&colour.r = 0i64;
        *(_QWORD *)&colour.b = 0i64;
        Render::View::Clear(v4, &colour, 4u, 1.0, 0);
        Render::View::Draw(v4, &gDeferredCube, &m, 0);
        if ( *(_DWORD *)&v61[3].mDebugName[12] != -1835606658 )
        {
          v119 = -1835606658;
LABEL_143:
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v61[3].mResourceHandles.mNode.mNext,
            *(_DWORD *)&v61[3].mDebugName[20],
            v119);
          v120 = v61->mMaterialUser.mOffset;
          if ( v120 )
            v121 = (_WORD *)((char *)&v61->mMaterialUser + v120);
          else
            v121 = 0i64;
          *v121 |= 0x20u;
          goto LABEL_147;
        }
      }
      else
      {
        Render::View::Draw(v4, &gDeferredCube, &m, 0);
        if ( *(_DWORD *)&v61[3].mDebugName[12] != 1537965747 )
        {
          v119 = 1537965747;
          goto LABEL_143;
        }
      }
LABEL_147:
      Render::View::Draw(v4, &gDeferredCube, &m, 0);
      goto LABEL_171;
    }
    if ( v103 != 2 )
      goto LABEL_171;
    v122 = 0i64;
    if ( v104 )
    {
      v123 = v137;
      v124 = v139;
      v125 = (float)((float)(COERCE_FLOAT(LODWORD(v47) ^ _xmm[0])
                           * (float)((float)(v47 * 0.001) + (float)((float)(v47 * v41) + d.v3.x)))
                   + (float)(COERCE_FLOAT(LODWORD(v139) ^ _xmm[0])
                           * (float)((float)((float)(v139 * v41) + d.v3.y) + (float)(v139 * 0.001))))
           + (float)(COERCE_FLOAT(LODWORD(v137) ^ _xmm[0])
                   * (float)((float)(d.v3.z + (float)(v137 * v41)) + (float)(v137 * 0.001)));
      UFG::qTranspose(&v160, &m);
      plane.x = (float)((float)((float)(v124 * v160.v1.x) + (float)(v47 * v160.v0.x)) + (float)(v123 * v160.v2.x))
              + (float)(v160.v3.x * v125);
      plane.y = (float)((float)((float)(v124 * v160.v1.y) + (float)(v47 * v160.v0.y)) + (float)(v123 * v160.v2.y))
              + (float)(v160.v3.y * v125);
      plane.z = (float)((float)((float)(v124 * v160.v1.z) + (float)(v47 * v160.v0.z)) + (float)(v123 * v160.v2.z))
              + (float)(v160.v3.z * v125);
      plane.w = (float)((float)((float)(v124 * v160.v1.w) + (float)(v47 * v160.v0.w)) + (float)(v123 * v160.v2.w))
              + (float)(v160.v3.w * v125);
      ClipCube::Reset(&v175);
      ClipCube::ClipToPlane(&v175, &plane);
      if ( ClipCube::GetClipCount(&v175) )
      {
        LODWORD(vertex_count) = 0;
        v126 = ClipCube::GenerateCube(&v175, (unsigned int *)&vertex_count);
        if ( (_DWORD)vertex_count )
        {
          v122 = Illusion::Primitive::Create("ClipCube");
          Illusion::Primitive::SetBuffers(
            v122,
            TRIANGLELIST,
            v126,
            (const int)vertex_count,
            (Illusion::VertexDecl *)gIrradianceVolumePrimitiveVertexDecl.mData,
            0i64,
            0,
            1);
        }
      }
    }
    if ( gClearStencil )
    {
      *(_QWORD *)&v159.r = 0i64;
      *(_QWORD *)&v159.b = 0i64;
      Render::View::Clear(v4, &v159, 4u, 1.0, 0);
      if ( v122 )
        Render::View::Draw(v4, v122, (Illusion::Material *)gMatStencil.mData, &m);
      else
        Render::View::Draw(v4, &gDeferredCube, &m, 0);
      if ( *(_DWORD *)&v61[3].mDebugName[12] == -929296280 )
        goto LABEL_168;
      v127 = -929296280;
    }
    else
    {
      if ( v122 )
        Render::View::Draw(v4, v122, (Illusion::Material *)gMatStencilNoClear.mData, &m);
      else
        Render::View::Draw(v4, &gDeferredCube, &m, 0);
      if ( *(_DWORD *)&v61[3].mDebugName[12] == 1063454199 )
        goto LABEL_168;
      v127 = 1063454199;
    }
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v61[3].mResourceHandles.mNode.mNext,
      *(_DWORD *)&v61[3].mDebugName[20],
      v127);
    v128 = v61->mMaterialUser.mOffset;
    if ( v128 )
      v129 = (_WORD *)((char *)&v61->mMaterialUser + v128);
    else
      v129 = 0i64;
    *v129 |= 0x20u;
LABEL_168:
    if ( v122 )
      Render::View::Draw(v4, v122, v61, &m);
    else
      Render::View::Draw(v4, &gDeferredCube, &m, 0);
LABEL_171:
    v130 = arg.mPrev;
    v131 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v131->mPrev = v130;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v143->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v143 + 16 * (arg.mStateParamIndex + 3i64)) )
      v143->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v132 = arg.mPrev;
    v133 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v133->mPrev = v132;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    v39 = v177;
    goto LABEL_174;
  }
}

// File Line: 1497
// RVA: 0x4CF00
void __fastcall DrawSpotLight(UFG::RenderContext *render_context, Render::View *view, Render::Light *light, Render::LightInstance *light_instance)
{
  Render::Light *v4; // rbx
  Render::View *v5; // rsi
  float fFar; // xmm2_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm10_4
  float v12; // xmm11_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  float v15; // xmm14_4
  float v16; // xmm15_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  Illusion::StateArgs *v22; // rdi
  UFG::qMatrix44 *v23; // r14
  unsigned __int16 v24; // ax
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  unsigned __int16 v31; // ax
  __int64 v32; // rcx
  _QWORD *v33; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v35; // rax
  __int64 v36; // rcx
  _QWORD *v37; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rax
  Render::cbDeferredLightState arg; // [rsp+40h] [rbp-98h]
  UFG::qMatrix44 *v41; // [rsp+A8h] [rbp-30h]
  UFG::qMatrix44 *v42; // [rsp+B0h] [rbp-28h]
  UFG::qMatrix44 *v43; // [rsp+B8h] [rbp-20h]
  __int64 v44; // [rsp+C0h] [rbp-18h]
  __int128 v45; // [rsp+C8h] [rbp-10h]
  __int64 v46; // [rsp+D8h] [rbp+0h]
  UFG::qMatrix44 local_world; // [rsp+E8h] [rbp+10h]
  __int64 v48; // [rsp+128h] [rbp+50h]
  UFG::qMatrix44 shadowWorldView; // [rsp+138h] [rbp+60h]
  UFG::qMatrix44 shadowProjection; // [rsp+178h] [rbp+A0h]
  float v51; // [rsp+298h] [rbp+1C0h]
  float vars0; // [rsp+2A0h] [rbp+1C8h]
  float v53; // [rsp+2B0h] [rbp+1D8h]
  float v54; // [rsp+2B8h] [rbp+1E0h]
  char v55; // [rsp+2C0h] [rbp+1E8h]

  v48 = -2i64;
  v4 = light;
  v5 = view;
  fFar = light->mDecayRadius * light_instance->radScale;
  v51 = fFar;
  if ( fFar >= 0.0099999998 )
  {
    Render::BuildShadowSpotView(
      &shadowWorldView,
      &shadowProjection,
      &light->mTransform,
      light->mShadowNear,
      fFar,
      light->mFovHalfOuter * 2.0,
      1.0);
    if ( v55 )
      v5->mSubmitContext->vfptr->AddRenderCommand(v5->mSubmitContext, 21, 0, 0i64);
    vars0 = UFG::TimeOfDayManager::GetInstance()->mExposure;
    v7 = v4->mTransform.v0.x;
    v8 = v4->mTransform.v0.y;
    v9 = v4->mTransform.v0.z;
    v10 = v4->mTransform.v0.w;
    v11 = v4->mTransform.v1.x;
    v12 = v4->mTransform.v1.y;
    v13 = v4->mTransform.v1.z;
    v14 = v4->mTransform.v1.w;
    v15 = v4->mTransform.v2.x;
    v16 = v4->mTransform.v2.y;
    v17 = v4->mTransform.v3.y;
    v18 = v4->mTransform.v3.z;
    v19 = v4->mTransform.v3.w;
    local_world.v3.x = v4->mTransform.v3.x;
    local_world.v3.y = v17;
    local_world.v3.z = v18;
    local_world.v3.w = v19;
    v20 = tanf(v4->mFovHalfOuter);
    v21 = v20 * v51;
    local_world.v0.x = v7 * v21;
    local_world.v0.y = v8 * v21;
    local_world.v0.z = v9 * v21;
    local_world.v0.w = v10 * v21;
    local_world.v1.x = v11 * v21;
    local_world.v1.y = v12 * v21;
    local_world.v1.z = v13 * v21;
    local_world.v1.w = v14 * v21;
    local_world.v2.x = v15 * v51;
    local_world.v2.y = v16 * v51;
    local_world.v2.z = v4->mTransform.v2.z * v51;
    local_world.v2.w = v4->mTransform.v2.w * v51;
    v22 = Render::View::GetStateArgs(v5);
    v23 = &v5->mSettings->mWorldView;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbDeferredLightState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbDeferredLightState::sStateParamIndex == -1 )
    {
      v24 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbDeferredLight");
      Render::cbDeferredLightState::sStateParamIndex = v24;
      arg.mStateParamIndex = v24;
    }
    arg.mWorldView = v23;
    v25 = (float)((float)(v54 * v4->mColor.z) * vars0) * (float)((float)(v54 * v4->mColor.z) * vars0);
    v26 = (float)((float)(v54 * v4->mColor.y) * vars0) * (float)((float)(v54 * v4->mColor.y) * vars0);
    arg.mColor.x = (float)((float)(v54 * v4->mColor.x) * vars0) * (float)((float)(v54 * v4->mColor.x) * vars0);
    arg.mColor.y = v26;
    arg.mColor.z = v25;
    v27 = v4->mTransform.v3.y;
    v28 = v4->mTransform.v3.z;
    arg.mPosition.x = v4->mTransform.v3.x;
    arg.mPosition.y = v27;
    arg.mPosition.z = v28;
    *(float *)&arg.mStateParamIndex = v51;
    *(float *)(&arg.mIsSet + 1) = v4->mDecayPower;
    arg.mPosition.x = v53;
    v29 = cosf(v4->mFovHalfOuter);
    arg.mWorldView = (UFG::qMatrix44 *)__PAIR__(LODWORD(v29), COERCE_UNSIGNED_INT(cosf(v4->mFovHalfInner)));
    if ( v4->mTexDistAttenUID == -1 )
      v30 = FLOAT_N1_0;
    else
      v30 = v4->mTexDistAttenV;
    arg.mPosition.y = v30;
    Illusion::StateArgs::Set<Render::cbDeferredLightState>(v22, &arg);
    *(_QWORD *)&arg.mFovInner = (char *)&arg + 72;
    *(_QWORD *)&arg.mShadowFade = (char *)&arg + 72;
    *(_QWORD *)&arg.mAreaLightWidthHeightNearFar.x = 0i64;
    LOWORD(arg.mAreaLightWidthHeightNearFar.z) = Render::cbShadowTransformState::sStateParamIndex;
    HIWORD(arg.mAreaLightWidthHeightNearFar.z) = 1;
    if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
    {
      v31 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
      Render::cbShadowTransformState::sStateParamIndex = v31;
      LOWORD(arg.mAreaLightWidthHeightNearFar.z) = v31;
    }
    v41 = &v5->mViewWorld;
    v42 = &shadowWorldView;
    v43 = &shadowProjection;
    v44 = 0i64;
    _mm_store_si128((__m128i *)&v45, (__m128i)0i64);
    v46 = 0i64;
    Illusion::StateArgs::Set<Render::cbShadowTransformState>(v22, (Render::cbShadowTransformState *)&arg.mFovInner);
    Render::View::Draw(v5, &gDeferredCone, &local_world, 0);
    v32 = *(_QWORD *)&arg.mFovInner;
    v33 = *(_QWORD **)&arg.mShadowFade;
    *(_QWORD *)(*(_QWORD *)&arg.mFovInner + 8i64) = *(_QWORD *)&arg.mShadowFade;
    *v33 = v32;
    *(_QWORD *)&arg.mFovInner = (char *)&arg + 72;
    *(_QWORD *)&arg.mShadowFade = (char *)&arg + 72;
    HIBYTE(arg.mAreaLightWidthHeightNearFar.z) = 0;
    if ( (Illusion::StateArgs *)v22->mStateArgsCreateMask.mFlags[2
                                                               * (SLOWORD(arg.mAreaLightWidthHeightNearFar.z) + 3i64)
                                                               + 1] == (Illusion::StateArgs *)((char *)v22
                                                                                             + 16
                                                                                             * (SLOWORD(arg.mAreaLightWidthHeightNearFar.z)
                                                                                              + 3i64)) )
      v22->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(arg.mAreaLightWidthHeightNearFar.z) >> 6] &= ~(1i64 << (LOBYTE(arg.mAreaLightWidthHeightNearFar.z) & 0x3F));
    v34 = arg.mPrev;
    v35 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v35->mPrev = v34;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v22->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v22 + 16 * (arg.mStateParamIndex + 3i64)) )
      v22->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v36 = *(_QWORD *)&arg.mFovInner;
    v37 = *(_QWORD **)&arg.mShadowFade;
    *(_QWORD *)(*(_QWORD *)&arg.mFovInner + 8i64) = *(_QWORD *)&arg.mShadowFade;
    *v37 = v36;
    v38 = arg.mPrev;
    v39 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v39->mPrev = v38;
  }
}(_QWORD *)&arg.mFovInner + 8i64) = *(_QWORD *)&arg.mShadowFade;
    *v37 = v36;
    v38 = arg.mPrev;
    v39 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v39->mPrev = v38;
 

// File Line: 1556
// RVA: 0x4B0F0
void __fastcall DrawAreaLight(UFG::RenderContext *render_context, Render::View *view, Render::Light *light, Render::LightInstance *light_instance)
{
  Render::Light *v4; // rbx
  Render::View *v5; // rsi
  float fFar; // xmm6_4
  float v7; // xmm3_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm10_4
  float v12; // xmm11_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  float v15; // xmm14_4
  float v16; // xmm15_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  char v22; // r14
  float v23; // xmm0_4
  float v24; // xmm7_4
  float v25; // xmm8_4
  float v26; // xmm9_4
  float v27; // xmm10_4
  float v28; // xmm11_4
  float v29; // xmm12_4
  float v30; // xmm13_4
  float v31; // xmm14_4
  float v32; // xmm0_4
  Illusion::StateArgs *v33; // rdi
  Render::ViewSettings *v34; // r15
  unsigned __int16 v35; // ax
  float v36; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  float v39; // xmm7_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm6_4
  int v43; // xmm2_4
  int v44; // xmm1_4
  float v45; // xmm0_4
  unsigned __int16 v46; // ax
  Illusion::ModelHandle *v47; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v48; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v49; // rax
  __int64 v50; // rcx
  _QWORD *v51; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v52; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v53; // rax
  __int64 v54; // rcx
  _QWORD *v55; // rax
  UFG::qMatrix44 local_world; // [rsp+40h] [rbp-98h]
  float v57; // [rsp+80h] [rbp-58h]
  float v58; // [rsp+84h] [rbp-54h]
  float v59; // [rsp+88h] [rbp-50h]
  float v60; // [rsp+8Ch] [rbp-4Ch]
  float v61; // [rsp+90h] [rbp-48h]
  float v62; // [rsp+94h] [rbp-44h]
  float v63; // [rsp+98h] [rbp-40h]
  float v64; // [rsp+9Ch] [rbp-3Ch]
  float v65; // [rsp+A0h] [rbp-38h]
  float v66; // [rsp+A4h] [rbp-34h]
  int v67; // [rsp+A8h] [rbp-30h]
  float v68; // [rsp+ACh] [rbp-2Ch]
  float v69; // [rsp+B0h] [rbp-28h]
  int v70; // [rsp+B4h] [rbp-24h]
  float v71; // [rsp+B8h] [rbp-20h]
  int v72; // [rsp+BCh] [rbp-1Ch]
  Render::cbShadowTransformState v73; // [rsp+C8h] [rbp-10h]
  __int64 v74; // [rsp+128h] [rbp+50h]
  UFG::qMatrix44 shadowWorldView; // [rsp+138h] [rbp+60h]
  UFG::qMatrix44 shadowProjection; // [rsp+178h] [rbp+A0h]
  float v77; // [rsp+298h] [rbp+1C0h]
  int v78; // [rsp+2B0h] [rbp+1D8h]
  float v79; // [rsp+2B8h] [rbp+1E0h]
  char v80; // [rsp+2C0h] [rbp+1E8h]

  v74 = -2i64;
  v4 = light;
  v5 = view;
  fFar = light->mDecayRadius * light_instance->radScale;
  if ( fFar >= 0.0099999998 )
  {
    v7 = light->mShadowNear;
    if ( v7 <= (float)(light->mAreaLightNearOffset * 0.5) )
      v7 = light->mAreaLightNearOffset * 0.5;
    Render::BuildShadowSpotView(
      &shadowWorldView,
      &shadowProjection,
      &light->mTransform,
      v7,
      fFar,
      light->mFovHalfInner * 2.0,
      light->mAreaLightWidth / light->mAreaLightHeight);
    if ( v80 )
      v5->mSubmitContext->vfptr->AddRenderCommand(v5->mSubmitContext, 21, 0, 0i64);
    v77 = UFG::TimeOfDayManager::GetInstance()->mExposure;
    v8 = v4->mTransform.v0.x;
    v9 = v4->mTransform.v0.y;
    v10 = v4->mTransform.v0.z;
    v11 = v4->mTransform.v0.w;
    v12 = v4->mTransform.v1.x;
    v13 = v4->mTransform.v1.y;
    v14 = v4->mTransform.v1.z;
    v15 = v4->mTransform.v1.w;
    v16 = v4->mTransform.v2.x;
    v17 = v4->mTransform.v2.y;
    v18 = v4->mTransform.v2.z;
    v19 = v4->mTransform.v3.y;
    v20 = v4->mTransform.v3.z;
    v21 = v4->mTransform.v3.w;
    local_world.v3.x = v4->mTransform.v3.x;
    local_world.v3.y = v19;
    local_world.v3.z = v20;
    local_world.v3.w = v21;
    v22 = 1;
    v23 = v4->mFovHalfOuter;
    if ( v23 <= 1.0 )
    {
      v32 = tanf(v23) * fFar;
      v24 = v8 * v32;
      v25 = v9 * v32;
      v26 = v10 * v32;
      v27 = v11 * v32;
      v28 = v12 * v32;
      v29 = v13 * v32;
      v30 = v14 * v32;
      v31 = v15 * v32;
      local_world.v2.y = v4->mTransform.v2.y * fFar;
      local_world.v2.z = v4->mTransform.v2.z * fFar;
    }
    else
    {
      v24 = v8 * fFar;
      v25 = v9 * fFar;
      v26 = v10 * fFar;
      v27 = v11 * fFar;
      v28 = v12 * fFar;
      v29 = v13 * fFar;
      v30 = v14 * fFar;
      v31 = v15 * fFar;
      local_world.v2.y = v17 * fFar;
      local_world.v2.z = v18 * fFar;
      v22 = 0;
    }
    local_world.v2.w = v4->mTransform.v2.w * fFar;
    local_world.v2.x = v16 * fFar;
    local_world.v1.w = v31;
    local_world.v1.z = v30;
    local_world.v1.y = v29;
    local_world.v1.x = v28;
    local_world.v0.w = v27;
    local_world.v0.z = v26;
    local_world.v0.y = v25;
    local_world.v0.x = v24;
    v33 = Render::View::GetStateArgs(v5);
    v34 = v5->mSettings;
    *(_QWORD *)&local_world.v1.z = (char *)&local_world + 24;
    *(_QWORD *)&local_world.v2.x = (char *)&local_world + 24;
    *(_QWORD *)&local_world.v2.z = 0i64;
    LOWORD(local_world.v3.x) = Render::cbDeferredLightState::sStateParamIndex;
    HIWORD(local_world.v3.x) = 1;
    if ( (_WORD)Render::cbDeferredLightState::sStateParamIndex == -1 )
    {
      v35 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbDeferredLight");
      Render::cbDeferredLightState::sStateParamIndex = v35;
      LOWORD(local_world.v3.x) = v35;
    }
    *(_QWORD *)&local_world.v3.z = v34;
    v36 = v4->mAreaLightIntensityScale;
    v37 = (float)((float)((float)(v79 * v4->mColor.z) * v77) * (float)((float)(v79 * v4->mColor.z) * v77)) * v36;
    v38 = (float)((float)((float)(v79 * v4->mColor.y) * v77) * (float)((float)(v79 * v4->mColor.y) * v77)) * v36;
    v60 = (float)((float)((float)(v79 * v4->mColor.x) * v77) * (float)((float)(v79 * v4->mColor.x) * v77)) * v36;
    v61 = v38;
    v62 = v37;
    v39 = v4->mAreaLightNearOffset;
    v40 = (float)((float)(v4->mAreaLightNearOffset * v4->mTransform.v2.z) * 0.5) + v4->mTransform.v3.z;
    v41 = (float)((float)(v4->mAreaLightNearOffset * v4->mTransform.v2.y) * 0.5) + v4->mTransform.v3.y;
    v57 = (float)((float)(v4->mAreaLightNearOffset * v4->mTransform.v2.x) * 0.5) + v4->mTransform.v3.x;
    v58 = v41;
    v59 = v40;
    v63 = (float)(v39 * 0.5) + fFar;
    v64 = v4->mDecayPower;
    v67 = v78;
    v42 = cosf(v4->mFovHalfOuter);
    v65 = cosf(v4->mFovHalfInner);
    v66 = v42;
    v43 = LODWORD(v4->mAreaLightFarOffset);
    v44 = LODWORD(v4->mAreaLightHeight);
    v69 = v4->mAreaLightWidth;
    v70 = v44;
    v71 = v39;
    v72 = v43;
    if ( v4->mTexDistAttenUID == -1 )
      v45 = FLOAT_N1_0;
    else
      v45 = v4->mTexDistAttenV;
    v68 = v45;
    Illusion::StateArgs::Set<Render::cbDeferredLightState>(v33, (Render::cbDeferredLightState *)&local_world.v1.z);
    v73.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v73;
    v73.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v73;
    v73.mCallback = 0i64;
    v73.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
    *(_WORD *)&v73.mFlags = 1;
    if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
    {
      v46 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
      Render::cbShadowTransformState::sStateParamIndex = v46;
      v73.mStateParamIndex = v46;
    }
    v73.mViewWorld = &v5->mViewWorld;
    v73.mWorldView = &shadowWorldView;
    v73.mProjection = &shadowProjection;
    v73.mCutplanes = 0i64;
    _mm_store_si128((__m128i *)&v73.mBiases, (__m128i)0i64);
    v73.mCached_Remote.m_Stream = 0i64;
    Illusion::StateArgs::Set<Render::cbShadowTransformState>(v33, &v73);
    v47 = &gDeferredSphere;
    if ( v22 )
      v47 = &gDeferredCone;
    Render::View::Draw(v5, v47, &local_world, 0);
    v48 = v73.mPrev;
    v49 = v73.mNext;
    v73.mPrev->mNext = v73.mNext;
    v49->mPrev = v48;
    v73.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v73;
    v73.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v73;
    v73.mIsSet = 0;
    if ( (Illusion::StateArgs *)v33->mStateArgsCreateMask.mFlags[2 * (v73.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v33 + 16 * (v73.mStateParamIndex + 3i64)) )
      v33->mStateArgsCreateMask.mFlags[(unsigned int)v73.mStateParamIndex >> 6] &= ~(1i64 << (v73.mStateParamIndex & 0x3F));
    v50 = *(_QWORD *)&local_world.v1.z;
    v51 = *(_QWORD **)&local_world.v2.x;
    *(_QWORD *)(*(_QWORD *)&local_world.v1.z + 8i64) = *(_QWORD *)&local_world.v2.x;
    *v51 = v50;
    *(_QWORD *)&local_world.v1.z = (char *)&local_world + 24;
    *(_QWORD *)&local_world.v2.x = (char *)&local_world + 24;
    HIBYTE(local_world.v3.x) = 0;
    if ( (Illusion::StateArgs *)v33->mStateArgsCreateMask.mFlags[2 * (SLOWORD(local_world.v3.x) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v33 + 16 * (SLOWORD(local_world.v3.x) + 3i64)) )
      v33->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(local_world.v3.x) >> 6] &= ~(1i64 << (LOBYTE(local_world.v3.x) & 0x3F));
    v52 = v73.mPrev;
    v53 = v73.mNext;
    v73.mPrev->mNext = v73.mNext;
    v53->mPrev = v52;
    v54 = *(_QWORD *)&local_world.v1.z;
    v55 = *(_QWORD **)&local_world.v2.x;
    *(_QWORD *)(*(_QWORD *)&local_world.v1.z + 8i64) = *(_QWORD *)&local_world.v2.x;
    *v55 = v54;
  }
}

// File Line: 1633
// RVA: 0x4CB60
void __fastcall DrawShadowedSpotLights(UFG::RenderContext *render_context, Render::View *view, const unsigned int *indices, unsigned int count)
{
  const unsigned int *v4; // r15
  Render::View *v5; // rbp
  UFG::RenderContext *v6; // r14
  __int64 v7; // r12
  Illusion::Material *v8; // rbx
  Render::LightInstance *v9; // rdi
  Render::Light *v10; // rsi
  UFG::qVector4 *groupClipPlanes; // ST40_8
  unsigned int v12; // er8
  Render::LightInstance *v13; // r9
  Render::Light *v14; // r8
  UFG::qVector4 *v15; // ST40_8
  UFG::qVector4 *v16; // ST40_8
  Render::LightInstance *v17; // r9
  Render::Light *v18; // r8
  UFG::qVector4 *v19; // ST40_8
  __int64 v20; // rax
  _WORD *v21; // rax
  __int128 v22; // xmm0
  UFG::qVector4 *v23; // ST40_8
  float shadowFade; // ST28_4
  UFG::qColour colour; // [rsp+50h] [rbp-68h]
  UFG::qColour v26; // [rsp+60h] [rbp-58h]

  if ( count )
  {
    v4 = indices;
    v5 = view;
    v6 = render_context;
    v7 = count;
    while ( 1 )
    {
      v8 = v6->mLightMaterial;
      v9 = &gCulledLights[*v4];
      v10 = gLights[v9->lightIndex];
      if ( *v4 < gNumNearLights )
      {
        if ( gClearStencil )
        {
          *(_QWORD *)&colour.r = 0i64;
          *(_QWORD *)&colour.b = 0i64;
          Render::View::Clear(v5, &colour, 4u, 1.0, 0);
          groupClipPlanes = gLightGroups[(unsigned __int8)v9->groupAssocIndex].clipPlanes;
          if ( v10->mType == 5 )
            DrawAreaLight(v6, v5, v10, v9);
          else
            DrawSpotLight(v6, v5, v10, v9);
          if ( *(_DWORD *)&v8[3].mDebugName[12] == -1835606658 )
            goto LABEL_33;
          v12 = -1835606658;
        }
        else
        {
          v13 = &gCulledLights[*v4];
          v14 = gLights[v9->lightIndex];
          v15 = gLightGroups[(unsigned __int8)v9->groupAssocIndex].clipPlanes;
          if ( v10->mType == 5 )
            DrawAreaLight(v6, v5, v14, v13);
          else
            DrawSpotLight(v6, v5, v14, v13);
          if ( *(_DWORD *)&v8[3].mDebugName[12] == 1537965747 )
            goto LABEL_33;
          v12 = 1537965747;
        }
        goto LABEL_29;
      }
      if ( *v4 < gNumStencilLights + gNumNearLights )
        break;
      if ( *(_DWORD *)&v8[3].mDebugName[12] != -262489691 )
      {
        v12 = -262489691;
LABEL_29:
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&v8[3].mResourceHandles.mNode.mNext,
          *(_DWORD *)&v8[3].mDebugName[20],
          v12);
        v20 = v8->mMaterialUser.mOffset;
        if ( v20 )
          v21 = (_WORD *)((char *)&v8->mMaterialUser + v20);
        else
          v21 = 0i64;
        *v21 |= 0x20u;
      }
LABEL_33:
      UpdateLightMaterial(v8, v10, v9);
      v22 = LODWORD(v9->colorFade);
      v23 = gLightGroups[(unsigned __int8)v9->groupAssocIndex].clipPlanes;
      shadowFade = v9->shadowFade;
      if ( v10->mType == 5 )
        DrawAreaLight(v6, v5, v10, v9);
      else
        DrawSpotLight(v6, v5, v10, v9);
      ++v4;
      if ( !--v7 )
        return;
    }
    if ( gClearStencil )
    {
      *(_QWORD *)&v26.r = 0i64;
      *(_QWORD *)&v26.b = 0i64;
      Render::View::Clear(v5, &v26, 4u, 1.0, 0);
      v16 = gLightGroups[(unsigned __int8)v9->groupAssocIndex].clipPlanes;
      if ( v10->mType == 5 )
        DrawAreaLight(v6, v5, v10, v9);
      else
        DrawSpotLight(v6, v5, v10, v9);
      if ( *(_DWORD *)&v8[3].mDebugName[12] == -929296280 )
        goto LABEL_33;
      v12 = -929296280;
    }
    else
    {
      v17 = &gCulledLights[*v4];
      v18 = gLights[v9->lightIndex];
      v19 = gLightGroups[(unsigned __int8)v9->groupAssocIndex].clipPlanes;
      if ( v10->mType == 5 )
        DrawAreaLight(v6, v5, v18, v17);
      else
        DrawSpotLight(v6, v5, v18, v17);
      if ( *(_DWORD *)&v8[3].mDebugName[12] == 1063454199 )
        goto LABEL_33;
      v12 = 1063454199;
    }
    goto LABEL_29;
  }
}

// File Line: 1706
// RVA: 0x1456120
__int64 dynamic_initializer_for__gLightRenderLayer__()
{
  RenderQueueLayer::RenderQueueLayer(&gLightRenderLayer);
  return atexit(dynamic_atexit_destructor_for__gLightRenderLayer__);
}

// File Line: 1707
// RVA: 0x1456140
__int64 dynamic_initializer_for__gListRenderLayerSerializationList__()
{
  return atexit(dynamic_atexit_destructor_for__gListRenderLayerSerializationList__);
}

// File Line: 1712
// RVA: 0x4F820
LightingSubmitParamIndices *__fastcall GetLightSubmitParamIndices()
{
  unsigned __int16 v0; // ax

  if ( !isInitialized )
  {
    paramIndices.paramIndex_texDiffuse = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                             &Illusion::gStateSystem,
                                                             "texDiffuse",
                                                             0);
    paramIndices.paramIndex_texNormal = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                            &Illusion::gStateSystem,
                                                            "texNormal",
                                                            0);
    paramIndices.paramIndex_texDepth = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                           &Illusion::gStateSystem,
                                                           "texDepth",
                                                           0);
    paramIndices.paramIndex_texDiffuse2 = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                              &Illusion::gStateSystem,
                                                              "texDiffuse2",
                                                              0);
    paramIndices.paramIndex_texAmbient = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                             &Illusion::gStateSystem,
                                                             "texAmbient",
                                                             0);
    paramIndices.paramIndex_texShadow = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                            &Illusion::gStateSystem,
                                                            "texShadow",
                                                            0);
    paramIndices.paramIndex_texDistAtten = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                               &Illusion::gStateSystem,
                                                               "texDistAtten",
                                                               0);
    v0 = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "cbDeferredLight", 0);
    isInitialized = 1;
    paramIndices.paramIndex_cbDeferredLight = v0;
  }
  return &paramIndices;
}

// File Line: 1733
// RVA: 0x4E3E0
void __fastcall GatherShadowedSpotLights(UFG::RenderContext *render_context)
{
  unsigned int v1; // edx
  unsigned int v2; // edi
  float v3; // xmm0_4
  unsigned int v4; // er8
  Render::LightInstance *v5; // r9
  Render::Light **v6; // r14
  unsigned __int64 v7; // r11
  __int64 v8; // rbx
  Render::Light *v9; // r10
  char v10; // al
  __int64 v11; // rax

  if ( render_context->mRenderFeatures.mLights )
  {
    if ( render_context->mRenderFeatures.mWorld )
    {
      v1 = 0;
      gSpotShadowCount = 0;
      v2 = gNumNearLights + gNumStencilLights + gNumFarLights;
      if ( gNumNearLights + gNumStencilLights + gNumFarLights )
      {
        v3 = (float)render_context->mNumSpotShadowsAllowed;
        if ( v3 >= 16.0 )
          v3 = FLOAT_16_0;
        v4 = 0;
        if ( v2 )
        {
          v5 = gCulledLights;
          v6 = gLights;
          v7 = 0i64;
          do
          {
            v8 = render_context->mMainViewSettings.mCullIndex;
            v9 = v6[v5->lightIndex];
            if ( (signed int)v8 < 0
              || gCulledLightsResults[v7 >> 8][(unsigned __int64)(unsigned __int8)v7].mViewResult[v8] <= 1u )
            {
              v10 = v9->mType;
              if ( (v10 == 1 || (unsigned __int8)(v10 - 4) <= 1u) && v5->flags & 2 && v1 < (signed int)v3 )
              {
                if ( v9->mShadowFlags )
                {
                  v11 = v1++;
                  gSpotShadowIndices[v11] = v4;
                  gSpotShadowCount = v1;
                }
              }
            }
            ++v4;
            ++v7;
            ++v5;
          }
          while ( v4 < v2 );
        }
      }
    }
  }
}

// File Line: 1769
// RVA: 0x5B190
void __fastcall SubmitDrawLightingTask(UFG::RenderContext *render_context)
{
  UFG::RenderContext *v1; // r13
  unsigned int v2; // er14
  unsigned int v3; // eax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  char *v8; // rax
  char *v9; // rdi
  char *v10; // rax
  UFG::qTask *v11; // rdx
  char *v12; // rsi
  _QWORD *v13; // rcx
  UFG::qSpuElf *v14; // rax
  void (__fastcall *v15)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v16)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v17)(void *, void *, void *, void *); // r9
  char *v18; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v19; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v20; // rax
  char *v21; // rax
  char *v22; // rax
  char *v23; // r15
  char *v24; // rax
  unsigned int v25; // edx
  float v26; // xmm0_4
  unsigned int v27; // er11
  unsigned int v28; // ebp
  __int64 v29; // rbx
  char *v30; // r8
  unsigned int v31; // edi
  Render::LightInstance *v32; // r12
  Render::Light *v33; // r14
  __int64 v34; // r10
  __int64 v35; // r9
  CullResults *v36; // rcx
  bool v37; // r15
  bool v38; // zf
  char v39; // al
  unsigned int v40; // er9
  __int64 v41; // rdx
  UFG::qVector4 v42; // xmm2
  UFG::qVector4 v43; // xmm1
  UFG::qVector4 v44; // xmm0
  UFG::qVector4 v45; // xmm2
  UFG::qVector4 v46; // xmm1
  UFG::qVector4 v47; // xmm0
  UFG::BaseCameraComponent *v48; // rax
  float *v49; // rax
  float v50; // xmm1_4
  float v51; // xmm0_4
  UFG::BaseCameraComponent *v52; // rax
  float *v53; // rax
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm0_4
  signed __int64 v57; // rdx
  signed __int64 v58; // rdx
  UFG::qResourceInventory *v59; // rcx
  UFG::qResourceInventoryVtbl *v60; // rax
  signed __int64 v61; // rdx
  signed __int64 v62; // rdx
  signed __int64 v63; // rdx
  unsigned int v64; // eax
  __int64 v65; // rdx
  UFG::qResourceInventoryVtbl *v66; // rax
  UFG::qResourceData *v67; // rax
  signed __int64 v68; // rdx
  UFG::qResourceInventory *v69; // rcx
  UFG::qBaseNodeRB *v70; // rcx
  _QWORD *v71; // rax
  char *v72; // rdx
  UFG::qBaseNodeRB *v73; // rcx
  _QWORD *v74; // rax
  signed __int64 v75; // [rsp+20h] [rbp-88h]
  char *v76; // [rsp+28h] [rbp-80h]
  char *v77; // [rsp+30h] [rbp-78h]
  char *v78; // [rsp+38h] [rbp-70h]
  __int64 v79; // [rsp+B0h] [rbp+8h]
  char *v80; // [rsp+B8h] [rbp+10h]

  v1 = render_context;
  if ( render_context->mRenderFeatures.mLights && render_context->mRenderFeatures.mWorld )
  {
    v2 = gNumNearLights + gNumStencilLights + gNumFarLights;
    LODWORD(v79) = gNumNearLights + gNumStencilLights + gNumFarLights;
    if ( !(gNumNearLights + gNumStencilLights + gNumFarLights) )
    {
      gSpotShadowCount = 0;
      render_context->mLightingSubmitTask = 0i64;
      render_context->mLightingSubmitTaskParams = 0i64;
      return;
    }
    v3 = _S7_0;
    if ( !(_S7_0 & 1) )
    {
      _S7_0 |= 1u;
      v4 = UFG::qResourceWarehouse::Instance();
      texInventory_1 = UFG::qResourceWarehouse::GetInventory(v4, 0x8B43FABF);
      v3 = _S7_0;
    }
    if ( !(v3 & 2) )
    {
      _S7_0 = v3 | 2;
      v5 = UFG::qResourceWarehouse::Instance();
      shaderInventory = UFG::qResourceWarehouse::GetInventory(v5, 0x8B5561A1);
      v3 = _S7_0;
    }
    if ( !(v3 & 4) )
    {
      _S7_0 = v3 | 4;
      v6 = UFG::qResourceWarehouse::Instance();
      alphaInventory = UFG::qResourceWarehouse::GetInventory(v6, 0x12C800F2u);
      v3 = _S7_0;
    }
    if ( !(v3 & 8) )
    {
      _S7_0 = v3 | 8;
      v7 = UFG::qResourceWarehouse::Instance();
      rasterInventory = UFG::qResourceWarehouse::GetInventory(v7, 0x3BC715E0u);
    }
    v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x1C8u, 0x10u);
    v9 = v8;
    v76 = v8;
    v10 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v11 = (UFG::qTask *)v10;
    v12 = 0i64;
    if ( v10 )
    {
      *(_QWORD *)v10 = v10;
      *((_QWORD *)v10 + 1) = v10;
      v13 = v10 + 16;
      *v13 = v13;
      v13[1] = v13;
      v14 = gTaskFunctionDeclData_SubmitLightingTask.mSpuElf;
      v15 = gTaskFunctionDeclData_SubmitLightingTask.mTaskFunctionSPU;
      v16 = gTaskFunctionDeclData_SubmitLightingTask.mTaskFunctionPPU;
      v17 = gTaskFunctionDeclData_SubmitLightingTask.mTaskFunctionOffload;
      if ( !gTaskFunctionDeclData_SubmitLightingTask.mCurrentSPUEnabled )
      {
        v14 = 0i64;
        v15 = 0i64;
        v17 = 0i64;
      }
      v11->mTaskGroup = 0i64;
      v11->mFlags = 2;
      v11->mSyncVars.i64 = 0i64;
      v11->mSyncVars.v.mDependents = 0i64;
      v11->mFunctionDeclData = &gTaskFunctionDeclData_SubmitLightingTask;
      if ( v14 )
        v18 = v14->mAddress;
      else
        v18 = 0i64;
      v11->mSPUElfAddress = v18;
      v11->mSPUFunction = v15;
      v11->mPPUFunction = v16;
      v11->mParam0 = v9;
      v11->mParam1 = 0i64;
      v11->mParam2 = 0i64;
      v11->mParam3 = 0i64;
      if ( v17 )
      {
        v11->mFlags = 130;
        v11->mOffloadThread = 0;
      }
    }
    v19 = UFG::gTaskManager.mSingleFrameTasks;
    v20 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
    v20->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v11->mPrev;
    v11->mPrev = v20;
    v11->mNext = &v19->mNode;
    v19->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v11->mPrev;
    v1->mLightingSubmitTask = v11;
    v1->mLightingSubmitTaskParams = (LightingSubmitTaskParams *)v9;
    v21 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x20u);
    if ( v21 )
    {
      *(_QWORD *)v21 = v21;
      *((_QWORD *)v21 + 1) = v21;
    }
    else
    {
      v21 = 0i64;
    }
    *((_QWORD *)v9 + 19) = v21;
    v22 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 8 * v2, 0x10u);
    v23 = v22;
    v77 = v22;
    v24 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 8 * v2, 0x10u);
    v78 = v24;
    v25 = 0;
    gSpotShadowCount = 0;
    v26 = (float)v1->mNumSpotShadowsAllowed;
    if ( v26 >= 16.0 )
      v26 = FLOAT_16_0;
    v27 = (signed int)v26;
    v28 = 0;
    if ( v2 )
    {
      v29 = 0i64;
      v30 = v24;
      v80 = v24;
      v75 = v23 - v24;
      v31 = v79;
      while ( 1 )
      {
        v32 = gCulledLights;
        v33 = gLights[gCulledLights[v29].lightIndex];
        v79 = 0i64;
        v34 = 0i64;
        v35 = v1->mMainViewSettings.mCullIndex;
        if ( (signed int)v35 < 0 )
        {
          v37 = 0;
        }
        else
        {
          v36 = &gCulledLightsResults[v28 >> 8][(unsigned __int64)(unsigned __int8)v28];
          v37 = v36->mViewResult[v35] > 1u;
          v38 = v36->mViewResult[v35] <= 1u;
          if ( v36->mViewResult[v35] > 1u )
            goto LABEL_43;
        }
        v39 = v33->mType;
        if ( v39 == 1 || (unsigned __int8)(v39 - 4) <= 1u )
        {
          v40 = v33->mTextureUID;
          if ( v40 != -1 )
          {
            v79 = ((__int64 (__fastcall *)(UFG::qResourceInventory *, _QWORD, char *))texInventory_1->vfptr->Get)(
                    texInventory_1,
                    v40,
                    v30);
            v25 = gSpotShadowCount;
            v30 = v80;
            v34 = 0i64;
            v27 = (signed int)v26;
          }
          if ( v32[v29].flags & 2 && v25 < v27 && v33->mShadowFlags )
          {
            v37 = 1;
            gSpotShadowIndices[v25] = v28;
            gSpotShadowCount = v25 + 1;
          }
        }
        v41 = v33->mTexDistAttenUID;
        if ( (_DWORD)v41 != -1 )
        {
          v34 = ((__int64 (__fastcall *)(UFG::qResourceInventory *, __int64, char *))texInventory_1->vfptr->Get)(
                  texInventory_1,
                  v41,
                  v30);
          v30 = v80;
        }
        v38 = v37 == 0;
LABEL_43:
        v32[v29].flags |= !v38;
        *(_QWORD *)&v30[v75] = v79;
        *(_QWORD *)v30 = v34;
        ++v28;
        ++v29;
        v30 += 8;
        v80 = v30;
        if ( v28 >= v31 )
        {
          v9 = v76;
          v23 = v77;
          break;
        }
        v25 = gSpotShadowCount;
        v27 = (signed int)v26;
      }
    }
    gLightRenderLayer.mSerializationList = &gListRenderLayerSerializationList;
    *((_QWORD *)v9 + 16) = Illusion::gEngine.FrameMemory;
    v42 = v1->mMainViewSettings.mWorldView.v1;
    v43 = v1->mMainViewSettings.mWorldView.v2;
    v44 = v1->mMainViewSettings.mWorldView.v3;
    *(UFG::qVector4 *)v9 = v1->mMainViewSettings.mWorldView.v0;
    *((UFG::qVector4 *)v9 + 1) = v42;
    *((UFG::qVector4 *)v9 + 2) = v43;
    *((UFG::qVector4 *)v9 + 3) = v44;
    v45 = v1->mMainViewSettings.mProjection.v1;
    v46 = v1->mMainViewSettings.mProjection.v2;
    v47 = v1->mMainViewSettings.mProjection.v3;
    *((_OWORD *)v9 + 4) = v1->mMainViewSettings.mProjection.v0;
    *((UFG::qVector4 *)v9 + 5) = v45;
    *((UFG::qVector4 *)v9 + 6) = v46;
    *((UFG::qVector4 *)v9 + 7) = v47;
    *((_QWORD *)v9 + 17) = Render::GetViewStateBlockParams();
    *((_QWORD *)v9 + 18) = GetLightSubmitParamIndices();
    *((_QWORD *)v9 + 20) = &gLightRenderLayer;
    *((_QWORD *)v9 + 21) = gLights;
    *((_QWORD *)v9 + 22) = gCulledLights;
    *((_QWORD *)v9 + 23) = v23;
    *((_QWORD *)v9 + 24) = v78;
    *((_DWORD *)v9 + 50) = gNumNearLights;
    *((_DWORD *)v9 + 51) = gNumFarLights;
    *((_DWORD *)v9 + 52) = gNumStencilLights;
    *((_DWORD *)v9 + 53) = 16843008;
    v9[216] = gClearStencil != 0;
    v9[217] = gEnableZBounds != 0;
    v48 = UFG::Director::Get()->mCurrentCamera;
    if ( v48 )
      v49 = &v48->mCamera.mFOVOffset;
    else
      v49 = 0i64;
    v50 = v49[58];
    if ( v50 == 0.0 || v50 == v49[59] )
      v51 = *(float *)&v79;
    else
      v51 = v49[62] / v50;
    *((float *)v9 + 55) = v51;
    v52 = UFG::Director::Get()->mCurrentCamera;
    if ( v52 )
      v53 = &v52->mCamera.mFOVOffset;
    else
      v53 = 0i64;
    v54 = v53[58];
    v55 = v53[59];
    if ( v54 == 0.0 || v54 == v55 )
      v56 = *(float *)&v79;
    else
      v56 = (float)(v53[62] - v53[63]) / (float)(v54 - v55);
    *((float *)v9 + 56) = v56;
    *((_DWORD *)v9 + 57) = LODWORD(UFG::TimeOfDayManager::GetInstance()->mExposure);
    if ( v1->mRenderSettingsForFrame.mSSAO == 1 && v1->mLightBufferTarget->mTargetTexture[1] )
    {
      *((_QWORD *)v9 + 29) = shaderInventory->vfptr->Get(shaderInventory, 3279282853u);
      *((_QWORD *)v9 + 30) = shaderInventory->vfptr->Get(shaderInventory, 612326710u);
      v57 = 3279282853i64;
      if ( !gNoSpecLights )
        v57 = 2129313954i64;
      *((_QWORD *)v9 + 31) = shaderInventory->vfptr->Get(shaderInventory, v57);
      *((_QWORD *)v9 + 32) = shaderInventory->vfptr->Get(shaderInventory, 2030768325u);
      v58 = 2030768325i64;
      if ( !gNoSpecLights )
        v58 = 634163517i64;
      *((_QWORD *)v9 + 33) = shaderInventory->vfptr->Get(shaderInventory, v58);
      *((_QWORD *)v9 + 34) = shaderInventory->vfptr->Get(shaderInventory, 4148067080u);
      v59 = shaderInventory;
      v60 = shaderInventory->vfptr;
      if ( gNoSpecLights )
        v61 = 4148067080i64;
      else
        v61 = 1863009884i64;
    }
    else
    {
      *((_QWORD *)v9 + 29) = shaderInventory->vfptr->Get(shaderInventory, 1753793710u);
      *((_QWORD *)v9 + 30) = shaderInventory->vfptr->Get(shaderInventory, 246770660u);
      v62 = 1753793710i64;
      if ( !gNoSpecLights )
        v62 = 2846045904i64;
      *((_QWORD *)v9 + 31) = shaderInventory->vfptr->Get(shaderInventory, v62);
      *((_QWORD *)v9 + 32) = shaderInventory->vfptr->Get(shaderInventory, 185628407u);
      v63 = 185628407i64;
      if ( !gNoSpecLights )
        v63 = 1172639096i64;
      *((_QWORD *)v9 + 33) = shaderInventory->vfptr->Get(shaderInventory, v63);
      *((_QWORD *)v9 + 34) = shaderInventory->vfptr->Get(shaderInventory, 2847309945u);
      v59 = shaderInventory;
      v60 = shaderInventory->vfptr;
      v61 = 2847309945i64;
      if ( !gNoSpecLights )
        v61 = 621576348i64;
    }
    *((_QWORD *)v9 + 35) = v60->Get(v59, v61);
    *((_QWORD *)v9 + 36) = shaderInventory->vfptr->Get(shaderInventory, 2683637110u);
    *((_QWORD *)v9 + 37) = shaderInventory->vfptr->Get(shaderInventory, 2233527130u);
    if ( _S7_0 & 0x10 )
    {
      v65 = uidFLAT;
    }
    else
    {
      _S7_0 |= 0x10u;
      v64 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
      v65 = v64;
      uidFLAT = v64;
    }
    *((_QWORD *)v9 + 38) = shaderInventory->vfptr->Get(shaderInventory, v65);
    *((_QWORD *)v9 + 39) = texInventory_1->vfptr->Get(texInventory_1, 2970839531u);
    *((_QWORD *)v9 + 40) = *((_QWORD *)&v1->mLightMaterial[1].0 + 11);
    *((_QWORD *)v9 + 41) = v1->mGBufferTarget->mTargetTexture[1];
    *((_QWORD *)v9 + 42) = v1->mGBufferTarget->mTargetTexture[3];
    *((_QWORD *)v9 + 43) = v1->mGBufferTarget->mDepthTextureCopy;
    *((_QWORD *)v9 + 44) = alphaInventory->vfptr->Get(alphaInventory, 3262501945u);
    *((_QWORD *)v9 + 45) = alphaInventory->vfptr->Get(alphaInventory, 2443369811u);
    *((_QWORD *)v9 + 46) = rasterInventory->vfptr->Get(rasterInventory, 4032477605u);
    *((_QWORD *)v9 + 47) = rasterInventory->vfptr->Get(rasterInventory, 3471962073u);
    v66 = rasterInventory->vfptr;
    if ( gClearStencil )
    {
      *((_QWORD *)v9 + 48) = v66->Get(rasterInventory, 1664809175u);
      *((_QWORD *)v9 + 49) = rasterInventory->vfptr->Get(rasterInventory, 3365671016u);
      v67 = rasterInventory->vfptr->Get(rasterInventory, 3994746641u);
      v68 = 2459360638i64;
    }
    else
    {
      *((_QWORD *)v9 + 48) = v66->Get(rasterInventory, 4170151191u);
      *((_QWORD *)v9 + 49) = rasterInventory->vfptr->Get(rasterInventory, 1063454199u);
      v67 = rasterInventory->vfptr->Get(rasterInventory, 4095106607u);
      v68 = 1537965747i64;
    }
    v69 = rasterInventory;
    *((_QWORD *)v9 + 50) = v67;
    *((_QWORD *)v9 + 51) = v69->vfptr->Get(v69, v68);
    v70 = gDeferredSphere.mData[2].mNode.mChild[0];
    if ( v70 )
      v71 = (UFG::qBaseNodeRB **)((char *)&v70->mParent + (unsigned __int64)gDeferredSphere.mData[2].mNode.mChild);
    else
      v71 = 0i64;
    v72 = (char *)v71 + *v71;
    if ( !*v71 )
      v72 = 0i64;
    *((_QWORD *)v9 + 52) = v72;
    v73 = gDeferredCone.mData[2].mNode.mChild[0];
    if ( v73 )
      v74 = (UFG::qBaseNodeRB **)((char *)&v73->mParent + (unsigned __int64)gDeferredCone.mData[2].mNode.mChild);
    else
      v74 = 0i64;
    if ( *v74 )
      v12 = (char *)v74 + *v74;
    *((_QWORD *)v9 + 53) = v12;
    *((_QWORD *)v9 + 54) = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *((_QWORD *)v9 + 55) = gLightGroups;
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v1->mLightingSubmitTask);
  }
}

// File Line: 1968
// RVA: 0x5CD40
void __fastcall SyncFlushDrawLightingTask(UFG::RenderContext *render_context, Render::View *view)
{
  Render::View *v2; // rbx
  UFG::RenderContext *v3; // rdi
  UFG::qTask *v4; // rdx
  RenderQueueLayer *v5; // rsi
  Illusion::RenderQueue *v6; // rbx
  int v7; // ecx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v8; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v9; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v10; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v11; // rcx
  LightingSubmitTaskResults *v12; // rcx

  v2 = view;
  v3 = render_context;
  if ( render_context->mRenderFeatures.mLights )
  {
    if ( gNumLightCards )
    {
      FlushLightCards(
        render_context,
        view,
        &gCulledLights[gNumNearLights + gNumFarLights + gNumStencilLights],
        gNumLightCards);
      v3->mRenderStats.mNumLightCards += gNumLightCards;
    }
    v4 = v3->mLightingSubmitTask;
    v3->mRenderStats.mNumLightsNearTotal += gNumNearLights;
    v3->mRenderStats.mNumLightsStencilTotal += gNumStencilLights;
    v3->mRenderStats.mNumLightsFarTotal += gNumFarLights;
    if ( v4 )
    {
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v4);
      v5 = (RenderQueueLayer *)v2->mSubmitContext[1].mStateValues.mParamValues[0];
      RenderQueueLayer::SerializeRenderQueues(v5);
      RenderQueueLayer::SerializeRenderQueues(&gLightRenderLayer);
      v6 = (Illusion::RenderQueue *)gListRenderLayerSerializationList.mNode.mNext;
      if ( do_print )
      {
        v7 = 0;
        v8 = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)gListRenderLayerSerializationList.mNode.mNext;
        if ( (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)gListRenderLayerSerializationList.mNode.mNext != &gListRenderLayerSerializationList )
        {
          do
          {
            v8 = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)v8->mNode.mNext;
            ++v7;
          }
          while ( v8 != &gListRenderLayerSerializationList );
          if ( v7
            && (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)gListRenderLayerSerializationList.mNode.mNext != &gListRenderLayerSerializationList )
          {
            do
            {
              Illusion::RenderQueueSystem::Print(v6);
              v6 = (Illusion::RenderQueue *)v6->mNext;
            }
            while ( v6 != (Illusion::RenderQueue *)&gListRenderLayerSerializationList );
            v6 = (Illusion::RenderQueue *)gListRenderLayerSerializationList.mNode.mNext;
          }
        }
      }
      v9 = v5->mSerializationList;
      if ( v6 != (Illusion::RenderQueue *)&gListRenderLayerSerializationList )
      {
        v10 = v9->mNode.mPrev;
        v11 = gListRenderLayerSerializationList.mNode.mPrev;
        v10->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v6->mPrev;
        v6->mPrev = v10;
        v11->mNext = &v9->mNode;
        v9->mNode.mPrev = v11;
        gListRenderLayerSerializationList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&gListRenderLayerSerializationList;
        gListRenderLayerSerializationList.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&gListRenderLayerSerializationList;
      }
      gLightRenderLayer.mSerializationList = 0i64;
      v12 = v3->mLightingSubmitTaskParams->mMainMemLightingSubmitTaskResults;
      v3->mRenderStats.mNumLightsNearRendered += v12->numNearLightsRendered;
      v3->mRenderStats.mNumLightsStencilRendered += v12->numStencilLightsRendered;
      v3->mRenderStats.mNumLightsFarRendered += v12->numFarLightsRendered;
    }
  }
}

