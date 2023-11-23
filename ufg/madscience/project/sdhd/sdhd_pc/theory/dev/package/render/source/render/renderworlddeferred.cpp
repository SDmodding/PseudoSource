// File Line: 40
// RVA: 0x14561C0
__int64 dynamic_initializer_for__gMatBlit__()
{
  UFG::qResourceHandle::qResourceHandle(&gMatBlit);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMatBlit__);
}

// File Line: 41
// RVA: 0x1456220
__int64 dynamic_initializer_for__gMatPostFog__()
{
  UFG::qResourceHandle::qResourceHandle(&gMatPostFog);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMatPostFog__);
}

// File Line: 42
// RVA: 0x14561F0
__int64 dynamic_initializer_for__gMatHighlight__()
{
  UFG::qResourceHandle::qResourceHandle(&gMatHighlight);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMatHighlight__);
}

// File Line: 136
// RVA: 0x14560F0
__int64 dynamic_initializer_for__gLightCardVertexDecl__()
{
  UFG::qResourceHandle::qResourceHandle(&gLightCardVertexDecl);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gLightCardVertexDecl__);
}

// File Line: 138
// RVA: 0x1456250
__int64 dynamic_initializer_for__gMatStencil__()
{
  UFG::qResourceHandle::qResourceHandle(&gMatStencil);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMatStencil__);
}

// File Line: 139
// RVA: 0x1456280
__int64 dynamic_initializer_for__gMatStencilNear__()
{
  UFG::qResourceHandle::qResourceHandle(&gMatStencilNear);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMatStencilNear__);
}

// File Line: 140
// RVA: 0x14562E0
__int64 dynamic_initializer_for__gMatStencilNoClear__()
{
  UFG::qResourceHandle::qResourceHandle(&gMatStencilNoClear);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMatStencilNoClear__);
}

// File Line: 141
// RVA: 0x14562B0
__int64 dynamic_initializer_for__gMatStencilNearNoClear__()
{
  UFG::qResourceHandle::qResourceHandle(&gMatStencilNearNoClear);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMatStencilNearNoClear__);
}

// File Line: 143
// RVA: 0x1456040
__int64 dynamic_initializer_for__gDeferredSphere__()
{
  UFG::qResourceHandle::qResourceHandle(&gDeferredSphere);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDeferredSphere__);
}

// File Line: 144
// RVA: 0x1456010
__int64 dynamic_initializer_for__gDeferredCube__()
{
  UFG::qResourceHandle::qResourceHandle(&gDeferredCube);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDeferredCube__);
}

// File Line: 145
// RVA: 0x1455FE0
__int64 dynamic_initializer_for__gDeferredCone__()
{
  UFG::qResourceHandle::qResourceHandle(&gDeferredCone);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDeferredCone__);
}

// File Line: 147
// RVA: 0x14560C0
__int64 dynamic_initializer_for__gIrradianceVolumePrimitiveVertexDecl__()
{
  UFG::qResourceHandle::qResourceHandle(&gIrradianceVolumePrimitiveVertexDecl);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gIrradianceVolumePrimitiveVertexDecl__);
}

// File Line: 152
// RVA: 0x52CF0
void LoadLightCardInfo()
{
  SimpleXML::XMLDocument *v0; // rax
  SimpleXML::XMLDocument *v1; // rbp
  SimpleXML::XMLNode *Node; // rbx
  const char *Attribute; // rax
  unsigned int v4; // edi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax
  int ChildCount; // eax
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // kr00_8
  SimpleXML::XMLNode *ChildNode; // rsi
  unsigned int *p_m_channelMask; // r14
  const char *v12; // rbx
  const char *v13; // r15
  __int64 v14; // rbx
  int *v15; // rdi
  unsigned int v16; // xmm2_4
  unsigned int v17; // xmm1_4
  unsigned int v18; // edx
  int v19; // r9d
  unsigned __int16 v20; // r9
  unsigned int v21; // edx
  unsigned int v22; // edx
  int v23; // r8d
  unsigned __int16 v24; // r8
  unsigned int v25; // edx
  UFG::qResourceInventory *v26; // rax
  UFG::qResourceWarehouse *v27; // rax
  int v28; // [rsp+38h] [rbp-90h] BYREF
  int v29; // [rsp+3Ch] [rbp-8Ch] BYREF
  int v30; // [rsp+40h] [rbp-88h] BYREF
  char *string[4]; // [rsp+48h] [rbp-80h]
  UFG::qResourceHandle v32; // [rsp+68h] [rbp-60h] BYREF
  float v33; // [rsp+D0h] [rbp+8h] BYREF
  float v34; // [rsp+D8h] [rbp+10h] BYREF
  unsigned int v35; // [rsp+E0h] [rbp+18h]

  if ( gEnableLightCards )
  {
    v0 = SimpleXML::XMLDocument::Open("Data\\LightCards\\lightcards.xml", 1ui64, 0i64);
    v1 = v0;
    if ( v0 )
    {
      Node = SimpleXML::XMLDocument::GetNode(v0, 0i64, 0i64);
      Attribute = SimpleXML::XMLNode::GetAttribute(Node, "texturename");
      gLightCardTextureUID = UFG::qStringHashUpper32(Attribute, 0xFFFFFFFF);
      UFG::qResourceHandle::qResourceHandle(&v32);
      v4 = gLightCardTextureUID;
      Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
      {
        v6 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0x8B43FABF);
        `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(&v32, 0x8B43FABF, v4, Inventory);
      ChildCount = SimpleXML::XMLNode::GetChildCount(Node);
      gLightCardInfoCount = ChildCount;
      if ( ChildCount )
      {
        v9 = ChildCount;
        v8 = 24i64 * ChildCount;
        if ( !is_mul_ok(v9, 0x18ui64) )
          v8 = -1i64;
        gLightCardInfos = (LightCardInfo *)UFG::qMalloc(v8, "LoadLightCardInfo", 0i64);
        ChildNode = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, Node);
        if ( ChildNode )
        {
          p_m_channelMask = &gLightCardInfos->m_channelMask;
          do
          {
            v12 = SimpleXML::XMLNode::GetAttribute(ChildNode, "name");
            v13 = SimpleXML::XMLNode::GetAttribute(ChildNode, "channelmask");
            string[0] = (char *)SimpleXML::XMLNode::GetAttribute(ChildNode, "uv0");
            string[1] = (char *)SimpleXML::XMLNode::GetAttribute(ChildNode, "uv1");
            string[2] = (char *)SimpleXML::XMLNode::GetAttribute(ChildNode, "uv2");
            string[3] = (char *)SimpleXML::XMLNode::GetAttribute(ChildNode, "uv3");
            *(p_m_channelMask - 1) = UFG::qStringHashUpper32(v12, 0xFFFFFFFF);
            v14 = 0i64;
            v15 = (int *)(p_m_channelMask + 1);
            do
            {
              sscanf(string[v14], "%f,%f", &v33, &v34);
              *(float *)&v16 = v33 / (float)WORD2(v32.mData[1].mNode.mChild[0]);
              v33 = *(float *)&v16;
              *(float *)&v17 = v34 / (float)HIWORD(v32.mData[1].mNode.mChild[0]);
              v34 = *(float *)&v17;
              v35 = v17;
              v18 = v17 & 0x7FFFFFFF;
              v19 = HIWORD(v17) & 0x8000;
              if ( (v17 & 0x7FFFFFFF) <= 0x47FFEFFF )
              {
                if ( v18 >= 0x38800000 )
                  v21 = v18 - 939524096;
                else
                  v21 = (v17 & 0x7FFFFF | 0x800000) >> (113 - (v18 >> 23));
                v20 = ((((v21 >> 13) & 1) + v21 + 4095) >> 13) | v19;
              }
              else
              {
                v20 = v19 | 0x7FFF;
              }
              v35 = v16;
              v22 = v16 & 0x7FFFFFFF;
              v23 = HIWORD(v16) & 0x8000;
              if ( (v16 & 0x7FFFFFFF) <= 0x47FFEFFF )
              {
                if ( v22 >= 0x38800000 )
                  v25 = v22 - 939524096;
                else
                  v25 = (v16 & 0x7FFFFF | 0x800000) >> (113 - (v22 >> 23));
                v24 = ((((v25 >> 13) & 1) + v25 + 4095) >> 13) | v23;
              }
              else
              {
                v24 = v23 | 0x7FFF;
              }
              *v15 = v24 | (v20 << 16);
              ++v14;
              ++v15;
            }
            while ( v14 < 4 );
            sscanf(v13, "%d,%d,%d", &v28, &v29, &v30);
            *p_m_channelMask = (65280 * v29) | (16711680 * v30) | (255 * v28);
            ChildNode = SimpleXML::XMLDocument::GetNode(v1, 0i64, ChildNode);
            p_m_channelMask += 6;
          }
          while ( ChildNode );
        }
      }
      SimpleXML::XMLDocument::~XMLDocument(v1);
      operator delete[](v1);
      v26 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
      {
        v27 = UFG::qResourceWarehouse::Instance();
        v26 = UFG::qResourceWarehouse::GetInventory(v27, 0x8B43FABF);
        `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v26;
      }
      UFG::qResourceHandle::Close(&v32, v26);
      UFG::qResourceHandle::~qResourceHandle(&v32);
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
  UFG::qResourceInventory *Inventory; // rax
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
  LODWORD(v3[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v5;
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
  LODWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v3[2].mNode.mUID = -89056095;
  v3[1].mNumParams = v8;
  LOWORD(v3[2].mTypeUID) = 0;
  HIDWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v9 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v3[2].UFG::qResourceData + 22) = 1002903008;
  LODWORD(v3[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v9;
  *(_DWORD *)&v3[2].mDebugName[28] = 1660426324;
  v10 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v10, v3);
  v11 = UFG::qStringHashUpper32("StencilMaterial", 0xFFFFFFFF);
  v12 = Illusion::Factory::NewMaterial("StencilMaterial", v11, 3u, 0i64, 0i64, 0i64);
  v13 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v12[1].mNode.mChild[0]) = 0;
  HIDWORD(v12[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v14 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v12[1].mTypeUID = -1957338719;
  LODWORD(v12[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v13;
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
  LODWORD(v12[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v12[2].mNode.mUID = 1664809175;
  v12[1].mNumParams = v16;
  v17 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v17, v12);
  v18 = UFG::qStringHashUpper32("StencilMaterialNear", 0xFFFFFFFF);
  v19 = Illusion::Factory::NewMaterial("StencilMaterialNear", v18, 3u, 0i64, 0i64, 0i64);
  v20 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v19[1].mNode.mChild[0]) = 0;
  HIDWORD(v19[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v21 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v19[1].mTypeUID = -1957338719;
  LODWORD(v19[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v20;
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
  LODWORD(v19[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v19[1].mNumParams = v23;
  v19[2].mNode.mUID = -300220655;
  v24 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v24, v19);
  v25 = UFG::qStringHashUpper32("StencilMaterialNoClear", 0xFFFFFFFF);
  v26 = Illusion::Factory::NewMaterial("StencilMaterialNoClear", v25, 3u, 0i64, 0i64, 0i64);
  v27 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v26[1].mNode.mChild[0]) = 0;
  HIDWORD(v26[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v28 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v26[1].mTypeUID = -1957338719;
  LODWORD(v26[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v27;
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
  LODWORD(v26[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v26[2].mNode.mUID = -124816105;
  v26[1].mNumParams = v30;
  v31 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v31, v26);
  v32 = UFG::qStringHashUpper32("StencilMaterialNearNoClear", 0xFFFFFFFF);
  v33 = Illusion::Factory::NewMaterial("StencilMaterialNearNoClear", v32, 3u, 0i64, 0i64, 0i64);
  v34 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
  LOWORD(v33[1].mNode.mChild[0]) = 0;
  v35 = v34;
  HIDWORD(v33[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v36 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v33[1].mTypeUID = -1957338719;
  LODWORD(v33[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v35;
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
  LODWORD(v33[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v33[1].mNumParams = v38;
  v33[2].mNode.mUID = -199860689;
  v39 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v39, v33);
  v40 = UFG::qStringHashUpper32("DR_sphere", 0xFFFFFFFF);
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v42 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v42, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&gDeferredSphere, 0xA2ADCD77, v40, Inventory);
  v43 = UFG::qStringHashUpper32("DR_cube", 0xFFFFFFFF);
  v44 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v45 = UFG::qResourceWarehouse::Instance();
    v44 = UFG::qResourceWarehouse::GetInventory(v45, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v44;
  }
  UFG::qResourceHandle::Init(&gDeferredCube, 0xA2ADCD77, v43, v44);
  v46 = UFG::qStringHashUpper32("DR_Cone", 0xFFFFFFFF);
  v47 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v48 = UFG::qResourceWarehouse::Instance();
    v47 = UFG::qResourceWarehouse::GetInventory(v48, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v47;
  }
  UFG::qResourceHandle::Init(&gDeferredCone, 0xA2ADCD77, v46, v47);
  v49 = UFG::qStringHashUpper32("Blit", 0xFFFFFFFF);
  v50 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v51 = UFG::qResourceWarehouse::Instance();
    v50 = UFG::qResourceWarehouse::GetInventory(v51, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v50;
  }
  UFG::qResourceHandle::Init(&gMatBlit, 0xB4C26312, v49, v50);
  v52 = UFG::qStringHashUpper32("StencilMaterial", 0xFFFFFFFF);
  v53 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v54 = UFG::qResourceWarehouse::Instance();
    v53 = UFG::qResourceWarehouse::GetInventory(v54, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v53;
  }
  UFG::qResourceHandle::Init(&gMatStencil, 0xB4C26312, v52, v53);
  v55 = UFG::qStringHashUpper32("StencilMaterialNear", 0xFFFFFFFF);
  v56 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v57 = UFG::qResourceWarehouse::Instance();
    v56 = UFG::qResourceWarehouse::GetInventory(v57, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v56;
  }
  UFG::qResourceHandle::Init(&gMatStencilNear, 0xB4C26312, v55, v56);
  v58 = UFG::qStringHashUpper32("StencilMaterialNoClear", 0xFFFFFFFF);
  v59 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v60 = UFG::qResourceWarehouse::Instance();
    v59 = UFG::qResourceWarehouse::GetInventory(v60, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v59;
  }
  UFG::qResourceHandle::Init(&gMatStencilNoClear, 0xB4C26312, v58, v59);
  v61 = UFG::qStringHashUpper32("StencilMaterialNearNoClear", 0xFFFFFFFF);
  v62 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v63 = UFG::qResourceWarehouse::Instance();
    v62 = UFG::qResourceWarehouse::GetInventory(v63, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v62;
  }
  UFG::qResourceHandle::Init(&gMatStencilNearNoClear, 0xB4C26312, v61, v62);
  LoadLightCardInfo();
  g_windIndex = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, "sbWindSettings", 0);
  v64 = UFG::qStringHash32("VertexDecl.LightCard", 0xFFFFFFFF);
  v65 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v66 = UFG::qResourceWarehouse::Instance();
    v65 = UFG::qResourceWarehouse::GetInventory(v66, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v65;
  }
  UFG::qResourceHandle::Init(&gLightCardVertexDecl, 0x3E5FDA3Eu, v64, v65);
  v67 = UFG::qStringHash32("VertexDecl.Slim", 0xFFFFFFFF);
  v68 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v69 = UFG::qResourceWarehouse::Instance();
    v68 = UFG::qResourceWarehouse::GetInventory(v69, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v68;
  }
  UFG::qResourceHandle::Init(&gIrradianceVolumePrimitiveVertexDecl, 0x3E5FDA3Eu, v67, v68);
}

// File Line: 616
// RVA: 0x4F4A0
void __fastcall GetAllDeferredLights(
        Render::Light **light_array,
        LightGroupAssoc *group_assoc,
        int *num_lights,
        int *num_groups,
        int max_lights)
{
  int *v5; // rsi
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *Inventory; // rax
  int v11; // r12d
  UFG::qBaseTreeRB *Head; // rbp
  int v13; // r14d
  float v14; // xmm6_4
  UFG::qBaseNodeRB *v15; // rcx
  int *p_mCount; // r8
  __int64 v17; // rdx
  int v18; // ecx
  UFG::qBaseNodeRB *v19; // rax
  unsigned int v20; // edi
  unsigned int v21; // r11d
  __int64 *v22; // r10
  unsigned int v23; // r9d
  Render::Light *v24; // rdx
  _BYTE *v25; // rcx
  unsigned int v26; // r8d
  __int64 v27; // rcx
  __int64 v28; // rsi
  __int64 v29; // rax
  UFG::qVector4 *v30; // rax
  unsigned int v31; // edi
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v33; // rax
  int *p_mNULL; // rax
  float v35; // xmm0_4
  __int64 v36; // rcx
  __int64 v37; // rdi
  __int64 v38; // rax
  UFG::qVector4 *v39; // rax
  unsigned int v40; // ebx
  unsigned int v41; // edx
  UFG::qBaseTreeRB *v42; // rax
  int **v43; // rax
  float v44; // xmm0_4
  UFG::qBaseNodeRB **v45; // [rsp+28h] [rbp-A0h] BYREF
  char *v46; // [rsp+30h] [rbp-98h]
  int v47; // [rsp+38h] [rbp-90h]
  UFG::qBaseNodeRB **v48; // [rsp+40h] [rbp-88h]
  char *v49; // [rsp+48h] [rbp-80h]
  int v50; // [rsp+50h] [rbp-78h]
  int v51; // [rsp+E0h] [rbp+18h] BYREF
  int *v52; // [rsp+E8h] [rbp+20h] BYREF

  v52 = num_groups;
  v5 = num_groups;
  if ( (_S4_1 & 1) != 0 )
  {
    Inventory = light_inventory;
  }
  else
  {
    _S4_1 |= 1u;
    v9 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v9, 0xF0A0724F);
    light_inventory = Inventory;
  }
  *num_lights = 0;
  *v5 = 0;
  v11 = 0;
  Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&Inventory->mResourceDatas);
  if ( Head )
  {
    v13 = max_lights;
    v14 = *(float *)&FLOAT_1_0;
    while ( 1 )
    {
      v15 = Head[1].mRoot.mChild[1];
      v45 = v15 ? (UFG::qBaseNodeRB **)((char *)&Head[1].mRoot.mChild[1] + (_QWORD)v15) : 0i64;
      p_mCount = &Head[1].mCount;
      v17 = *(_QWORD *)&Head[1].mCount;
      v46 = v17 ? (char *)p_mCount + v17 : 0i64;
      v18 = (int)Head[2].mRoot.mChild[0];
      v47 = v18;
      v19 = Head[1].mNULL.mChild[0];
      v48 = v19 ? (UFG::qBaseNodeRB **)((char *)&v19[3].mChild[1] + (_QWORD)Head) : 0i64;
      v49 = v17
          ? (char *)p_mCount
          + v17
          + (unsigned int)(HIDWORD(Head[2].mRoot.mChild[0]) + LODWORD(Head[2].mRoot.mChild[1]) + v18)
          : 0i64;
      v50 = HIDWORD(Head[2].mRoot.mChild[1]);
      v20 = gDoLightVolumeCapture + 1;
      v21 = 0;
      if ( gDoLightVolumeCapture != -1 )
        break;
LABEL_25:
      if ( *num_lights != v11 )
      {
        v27 = *v5;
        v28 = v27;
        *v52 = v27 + 1;
        group_assoc[v27].count = *num_lights - v11;
        if ( *(&Head[2].mRoot.mUID + 1) && (v29 = *(_QWORD *)&Head[1].mNULL.mUID) != 0 )
          v30 = (UFG::qVector4 *)((char *)&Head[1].mNULL.mChild[2] + v29);
        else
          v30 = 0i64;
        group_assoc[v27].clipPlanes = v30;
        group_assoc[v27].numClipPlanes = *(&Head[2].mRoot.mUID + 1);
        v51 = 0;
        v31 = UFG::Metrics::msFrameCount;
        mUID = Head->mRoot.mUID;
        if ( mUID
          && (v33 = UFG::qBaseTreeRB::Get(
                      (UFG::qBaseTreeRB *)&light_inventory[1].UFG::qNodeRB<UFG::qResourceInventory>,
                      mUID)) != 0i64 )
        {
          p_mNULL = (int *)&v33->mNULL;
        }
        else
        {
          p_mNULL = &v51;
        }
        v35 = (float)(int)(v31 - *p_mNULL) * 0.1;
        if ( v35 <= 0.0 )
        {
          v35 = 0.0;
        }
        else if ( v35 >= 1.0 )
        {
          v35 = *(float *)&FLOAT_1_0;
        }
        group_assoc[v28].lightGroupFade = v35;
        v11 = *num_lights;
        v5 = v52;
      }
      Head = UFG::qBaseTreeRB::GetNext(&light_inventory->mResourceDatas.mTree, &Head->mRoot);
      if ( !Head )
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
      if ( (*v25 & 2) != 0 )
      {
        light_array[(*num_lights)++] = v24;
        if ( *num_lights == v13 )
          break;
      }
      ++v26;
      ++v25;
      ++v24;
      if ( v26 >= v23 )
        goto LABEL_24;
    }
    if ( *num_lights != v11 )
    {
      v36 = *v5;
      v37 = v36;
      *v5 = v36 + 1;
      group_assoc[v36].count = *num_lights - v11;
      if ( *(&Head[2].mRoot.mUID + 1) && (v38 = *(_QWORD *)&Head[1].mNULL.mUID) != 0 )
        v39 = (UFG::qVector4 *)((char *)&Head[1].mNULL.mChild[2] + v38);
      else
        v39 = 0i64;
      group_assoc[v36].clipPlanes = v39;
      group_assoc[v36].numClipPlanes = *(&Head[2].mRoot.mUID + 1);
      LODWORD(v52) = 0;
      v40 = UFG::Metrics::msFrameCount;
      v41 = Head->mRoot.mUID;
      if ( v41
        && (v42 = UFG::qBaseTreeRB::Get(
                    (UFG::qBaseTreeRB *)&light_inventory[1].UFG::qNodeRB<UFG::qResourceInventory>,
                    v41)) != 0i64 )
      {
        v43 = (int **)&v42->mNULL;
      }
      else
      {
        v43 = &v52;
      }
      v44 = (float)(int)(v40 - *(_DWORD *)v43) * 0.1;
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
      group_assoc[v37].lightGroupFade = v14;
    }
  }
}

// File Line: 789
// RVA: 0x4E230
__int64 __fastcall GatherLights(Render::Light **pLights, LightGroupAssoc *pGroups)
{
  UFG::qVector4 *v4; // r15
  unsigned int v6; // ebx
  unsigned int v7; // ebx
  int v8; // esi
  Render::DynamicLightComponent *v9; // rbp
  Render::DynamicLightComponent *v10; // rdi
  UFG::TimeOfDayManager *Instance; // rax
  Render::Light *p_mLight; // rbp
  __int64 v13; // rdi
  UFG::qResourceWarehouse *v14; // rax
  UFG::qResourceInventory *Inventory; // rax
  Render::SkinningCacheNode *Head; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v17; // rcx
  unsigned int DynamicLights; // [rsp+90h] [rbp+18h] BYREF
  int v19; // [rsp+98h] [rbp+20h] BYREF

  v4 = 0i64;
  DynamicLights = 0;
  v19 = 0;
  GetAllDeferredLights(pLights, pGroups, (int *)&DynamicLights, &v19, 2048);
  if ( gDoLightVolumeCapture && !gIncludeEffectLightsInCapture )
    return DynamicLights;
  v6 = DynamicLights;
  DynamicLights = Render::DynamicLightManager::GetDynamicLights(
                    &Render::gDynamicLightManager,
                    &pLights[DynamicLights],
                    2048 - DynamicLights);
  v7 = DynamicLights + v6;
  v8 = 0;
  v9 = (Render::DynamicLightComponent *)&Render::DynamicLightComponent::s_DynamicLightComponentList.mNode.mNext[-4];
  if ( (UFG::qList<Render::DynamicLightComponent,Render::DynamicLightComponent,1,0> *)&Render::DynamicLightComponent::s_DynamicLightComponentList.mNode.mNext[-4] != &Render::DynamicLightComponent::s_DynamicLightComponentList - 4 )
  {
    do
    {
      v10 = (Render::DynamicLightComponent *)&v9->mNext[-4];
      Instance = UFG::TimeOfDayManager::GetInstance();
      p_mLight = &v9->mLight;
      if ( Render::IsLightOn(p_mLight, Instance->m_SecondsSinceMidnight) )
      {
        if ( v7 == 2048 )
          break;
        pLights[v7++] = p_mLight;
        ++v8;
      }
      v9 = v10;
    }
    while ( v10 != (Render::DynamicLightComponent *)(&Render::DynamicLightComponent::s_DynamicLightComponentList - 4) );
  }
  if ( v8 + DynamicLights )
  {
    v13 = v19;
    pGroups[v13].count = v8 + DynamicLights;
    pGroups[v13].numClipPlanes = 0;
    pGroups[v13].clipPlanes = 0i64;
    pGroups[v13].lightGroupFade = 1.0;
    if ( (_S5_0 & 1) != 0 )
    {
      Inventory = dynamicLightGroupInventory;
    }
    else
    {
      _S5_0 |= 1u;
      v14 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v14, 0x19B59D34u);
      dynamicLightGroupInventory = Inventory;
    }
    if ( Inventory )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&Inventory->mResourceDatas);
      if ( Head )
      {
        if ( LODWORD(Head[2].mNode.mChild[0]) )
        {
          v17 = Head[2].mNode.mChild[1];
          if ( v17 )
            v4 = (UFG::qVector4 *)((char *)&Head[2].mNode.mChild1 + (_QWORD)v17);
          pGroups[v13].clipPlanes = v4;
          pGroups[v13].numClipPlanes = (unsigned int)Head[2].mNode.mChild[0];
        }
      }
    }
  }
  return v7;
}

// File Line: 906
// RVA: 0x4EA80
void __fastcall GenerateLightCullingInfo(char main_view_cull_index)
{
  char v1; // bp
  signed int v2; // r14d
  __int64 v3; // r12
  int i; // esi
  float v5; // xmm0_4
  unsigned int v6; // edi
  CullManager *v7; // rax
  CullInfo *v8; // rax
  unsigned int v9; // r10d
  __int64 v10; // rbx
  CullInfo *v11; // r13
  int v12; // r15d
  char *v13; // r9
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
  __int64 v30; // r9
  __int64 v31; // rdx
  Render::LightInstance *v32; // rdx
  Render::Light *v33; // r8
  float v34; // xmm1_4
  CullManager *v35; // rax

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
    v6 = (int)v5;
    v7 = CullManager::Instance();
    v8 = CullManager::AllocFrameCullInfos(v7, (int)v5);
    v9 = 0;
    v10 = 0i64;
    v11 = v8;
    if ( (int)v5 >= 4 )
    {
      v12 = i + 1;
      v13 = (char *)&v8[1].mAABBMax[2];
      v14 = ~(1 << v1);
      v15 = ((v6 - 4) >> 2) + 1;
      v16 = v15;
      v9 = 4 * v15;
      v10 = 4i64 * v15;
      do
      {
        v13 += 256;
        v17 = &gCulledLights[v12 - 1];
        v18 = gLights[v17->lightIndex];
        v19 = v18->mDecayRadius * v17->radScale;
        *((_DWORD *)v13 - 86) = LODWORD(v19) ^ _xmm[0];
        *((_DWORD *)v13 - 85) = LODWORD(v19) ^ _xmm[0];
        *((_DWORD *)v13 - 84) = LODWORD(v19) ^ _xmm[0];
        *((float *)v13 - 82) = v19;
        *((float *)v13 - 81) = v19;
        *((float *)v13 - 80) = v19;
        *((_QWORD *)v13 - 36) = v18;
        *((_WORD *)v13 - 158) = 100;
        *((_WORD *)v13 - 157) = v14;
        v20 = &gCulledLights[v12];
        v21 = gLights[v20->lightIndex];
        v22 = v21->mDecayRadius * v20->radScale;
        *((_DWORD *)v13 - 70) = LODWORD(v22) ^ _xmm[0];
        *((_DWORD *)v13 - 69) = LODWORD(v22) ^ _xmm[0];
        *((_DWORD *)v13 - 68) = LODWORD(v22) ^ _xmm[0];
        *((float *)v13 - 66) = v22;
        *((float *)v13 - 65) = v22;
        *((float *)v13 - 64) = v22;
        *((_QWORD *)v13 - 28) = v21;
        *((_WORD *)v13 - 126) = 100;
        *((_WORD *)v13 - 125) = v14;
        v23 = &gCulledLights[v12 + 1];
        v24 = gLights[v23->lightIndex];
        v25 = v24->mDecayRadius * v23->radScale;
        v26 = (unsigned int)(v12 + 2);
        v12 += 4;
        *((_DWORD *)v13 - 54) = LODWORD(v25) ^ _xmm[0];
        *((_DWORD *)v13 - 53) = LODWORD(v25) ^ _xmm[0];
        *((_DWORD *)v13 - 52) = LODWORD(v25) ^ _xmm[0];
        *((float *)v13 - 50) = v25;
        *((float *)v13 - 49) = v25;
        *((float *)v13 - 48) = v25;
        *((_QWORD *)v13 - 20) = v24;
        *((_WORD *)v13 - 94) = 100;
        *((_WORD *)v13 - 93) = v14;
        v27 = &gCulledLights[v26];
        v28 = gLights[v27->lightIndex];
        v29 = v28->mDecayRadius * v27->radScale;
        *((_DWORD *)v13 - 38) = LODWORD(v29) ^ _xmm[0];
        *((_DWORD *)v13 - 37) = LODWORD(v29) ^ _xmm[0];
        *((_DWORD *)v13 - 36) = LODWORD(v29) ^ _xmm[0];
        *((float *)v13 - 34) = v29;
        *((float *)v13 - 33) = v29;
        *((float *)v13 - 32) = v29;
        *((_QWORD *)v13 - 12) = v28;
        *((_WORD *)v13 - 62) = 100;
        *((_WORD *)v13 - 61) = v14;
        --v16;
      }
      while ( v16 );
      v11 = v8;
      v1 = main_view_cull_index;
    }
    if ( v9 < v6 )
    {
      v30 = (__int64)&v11[v10].mAABBMax[2];
      do
      {
        v31 = v9 + i;
        ++v9;
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
void __fastcall SubmitUpdateLightingTask(
        Render::ViewSettings *view_settings,
        int num_lights,
        Render::Light **pLights,
        Render::LightInstance *pResults)
{
  char *v8; // rbx
  float z; // xmm0_4
  float v10; // xmm5_4
  float v11; // xmm8_4
  int v12; // xmm3_4
  int v13; // xmm7_4
  int v14; // xmm6_4
  float v15; // xmm2_4
  float w; // xmm1_4
  float x; // xmm2_4
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
  float y; // xmm8_4
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
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rcx
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r8
  char *mAddress; // r9
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *mPrev; // rax
  UFG::qMatrix44 result; // [rsp+20h] [rbp-B8h] BYREF
  __int64 v102; // [rsp+60h] [rbp-78h]
  int v103; // [rsp+68h] [rbp-70h]
  int v104; // [rsp+6Ch] [rbp-6Ch]
  UFG::qMatrix44 d; // [rsp+70h] [rbp-68h] BYREF
  char *v106; // [rsp+158h] [rbp+80h]
  char *v107; // [rsp+168h] [rbp+90h]
  void *retaddr; // [rsp+178h] [rbp+A0h]

  v102 = -2i64;
  gNumNearLights = 0;
  gNumStencilLights = 0;
  gNumFarLights = 0;
  gNumLightCards = 0;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x108u, 0x10u);
  *((_QWORD *)v8 + 7) = Illusion::gEngine.FrameMemory;
  UFG::qInverseAffine(&d, &view_settings->mWorldView);
  z = view_settings->mProjection.v2.z;
  v10 = 0.0;
  if ( z == 0.0 || z == view_settings->mProjection.v2.w )
    v11 = *(float *)&retaddr;
  else
    v11 = view_settings->mProjection.v3.z / z;
  v12 = LODWORD(d.v0.x) ^ _xmm[0];
  v13 = v104 ^ _xmm[0];
  v14 = v103 ^ _xmm[0];
  v15 = (float)((float)(*(float *)&v14 * *(float *)&v14) + (float)(*(float *)&v13 * *(float *)&v13))
      + (float)(*(float *)&v12 * *(float *)&v12);
  if ( v15 != 0.0 )
    v10 = 1.0 / fsqrt(v15);
  w = d.v0.w;
  x = d.v1.x;
  *((_DWORD *)v8 + 40) = LODWORD(d.v0.z);
  *((float *)v8 + 41) = w;
  *((float *)v8 + 42) = x;
  *((float *)v8 + 44) = *(float *)&v14 * v10;
  *((float *)v8 + 45) = v10 * *(float *)&v13;
  *((float *)v8 + 46) = v10 * *(float *)&v12;
  *((float *)v8 + 10) = v11;
  *(_DWORD *)v8 = num_lights;
  *((_QWORD *)v8 + 6) = pLights;
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
  *((_QWORD *)v8 + 24) = pResults;
  *((_QWORD *)v8 + 25) = &gNumNearLights;
  *((_QWORD *)v8 + 26) = &gNumStencilLights;
  *((_QWORD *)v8 + 27) = &gNumFarLights;
  *((_QWORD *)v8 + 28) = &gNumLightCards;
  v8[36] = 1;
  UFG::qMatrix44::operator*(&view_settings->mWorldView, &result, &view_settings->mProjection);
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
  y = result.v3.y;
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
  *((float *)v8 + 35) = v24 - y;
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
  v63 = _mm_sqrt_ps(v62).m128_f32[0];
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
  v68 = _mm_sqrt_ps(v67).m128_f32[0];
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
  v73 = _mm_sqrt_ps(v72).m128_f32[0];
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
  v78 = _mm_sqrt_ps(v77).m128_f32[0];
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
  v83 = _mm_sqrt_ps(v82).m128_f32[0];
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
  v89 = _mm_sqrt_ps(v88).m128_f32[0];
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
    mSpuElf = gTaskFunctionDeclData_UpdateLightingTask.mSpuElf;
    mTaskFunctionSPU = gTaskFunctionDeclData_UpdateLightingTask.mTaskFunctionSPU;
    mTaskFunctionPPU = gTaskFunctionDeclData_UpdateLightingTask.mTaskFunctionPPU;
    mTaskFunctionOffload = gTaskFunctionDeclData_UpdateLightingTask.mTaskFunctionOffload;
    if ( !gTaskFunctionDeclData_UpdateLightingTask.mCurrentSPUEnabled )
    {
      mSpuElf = 0i64;
      mTaskFunctionSPU = 0i64;
      mTaskFunctionOffload = 0i64;
    }
    v92->mTaskGroup = 0i64;
    v92->mFlags = 2;
    v92->mSyncVars.i64 = 0i64;
    v92->mSyncVars.v.mDependents = 0i64;
    v92->mFunctionDeclData = &gTaskFunctionDeclData_UpdateLightingTask;
    if ( mSpuElf )
      mAddress = mSpuElf->mAddress;
    else
      mAddress = 0i64;
    v92->mSPUElfAddress = mAddress;
    v92->mSPUFunction = mTaskFunctionSPU;
    v92->mPPUFunction = mTaskFunctionPPU;
    v92->mParam0 = v8;
    v92->mParam1 = 0i64;
    v92->mParam2 = 0i64;
    v92->mParam3 = 0i64;
    if ( mTaskFunctionOffload )
    {
      v92->mFlags = 130;
      v92->mOffloadThread = 0;
    }
  }
  mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
  mPrev = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  mPrev->mNext = v92;
  v92->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = mPrev;
  v92->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
  mSingleFrameTasks->mNode.mPrev = v92;
  gUpdateLightTask = v92;
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v92);
}

// File Line: 1007
// RVA: 0x5D0C0
void __fastcall UpdateLightMaterial(
        Illusion::Material *lightmat,
        Render::Light *pLight,
        Render::LightInstance *lightInstance)
{
  bool v6; // si
  char mType; // al
  _WORD *v8; // rdi
  __int64 v9; // rax
  _WORD *v10; // rax
  __int64 v11; // rax
  _WORD *v12; // rax
  unsigned int v13; // r8d
  char *v14; // rcx
  unsigned int v15; // r8d
  __int64 v16; // rax
  _WORD *v17; // rax
  unsigned int v18; // r8d
  __int64 v19; // rax
  _WORD *v20; // rax
  int v21; // eax
  unsigned int mTextureUID; // r8d
  __int64 mOffset; // rax
  _WORD *v24; // rax
  unsigned int mTexDistAttenUID; // r8d
  __int64 v26; // rax
  _WORD *v27; // rax
  __int64 v28; // rax
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-88h] BYREF

  v6 = pLight->mSpecular && !gNoSpecLights;
  mType = pLight->mType;
  if ( mType == 1 || mType == 4 )
  {
    mTextureUID = pLight->mTextureUID;
    if ( mTextureUID == -1 )
      mTextureUID = -1324127765;
    v8 = 0i64;
    if ( LODWORD(lightmat[4].mStateBlockMask.mFlags[1]) != mTextureUID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&lightmat[4].mDebugName[28],
        lightmat[4].mNumParams,
        mTextureUID);
      mOffset = lightmat->mMaterialUser.mOffset;
      if ( mOffset )
        v24 = (_WORD *)((char *)&lightmat->mMaterialUser + mOffset);
      else
        v24 = 0i64;
      *v24 |= 0x20u;
    }
    mTexDistAttenUID = pLight->mTexDistAttenUID;
    if ( mTexDistAttenUID == -1 )
      mTexDistAttenUID = -1324127765;
    if ( *((_DWORD *)&lightmat[5].UFG::qResourceData + 22) != mTexDistAttenUID )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&lightmat[5].mDebugName[12],
        lightmat[5].mStateBlockMask.mFlags[0],
        mTexDistAttenUID);
      v26 = lightmat->mMaterialUser.mOffset;
      if ( v26 )
        v27 = (_WORD *)((char *)&lightmat->mMaterialUser + v26);
      else
        v27 = 0i64;
      *v27 |= 0x20u;
    }
    if ( (lightInstance->flags & 2) != 0 )
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
  if ( mType != 3 )
  {
    if ( mType != 5 )
      return;
    v15 = pLight->mTextureUID;
    if ( v15 == -1 )
      v15 = -1324127765;
    v8 = 0i64;
    if ( LODWORD(lightmat[4].mStateBlockMask.mFlags[1]) != v15 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&lightmat[4].mDebugName[28], lightmat[4].mNumParams, v15);
      v16 = lightmat->mMaterialUser.mOffset;
      if ( v16 )
        v17 = (_WORD *)((char *)&lightmat->mMaterialUser + v16);
      else
        v17 = 0i64;
      *v17 |= 0x20u;
    }
    v18 = pLight->mTexDistAttenUID;
    if ( v18 == -1 )
      v18 = -1324127765;
    if ( *((_DWORD *)&lightmat[5].UFG::qResourceData + 22) != v18 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&lightmat[5].mDebugName[12],
        lightmat[5].mStateBlockMask.mFlags[0],
        v18);
      v19 = lightmat->mMaterialUser.mOffset;
      if ( v19 )
        v20 = (_WORD *)((char *)&lightmat->mMaterialUser + v19);
      else
        v20 = 0i64;
      *v20 |= 0x20u;
    }
    if ( (lightInstance->flags & 2) == 0 )
    {
      if ( v6 )
      {
        v13 = -1448921392;
      }
      else
      {
        v13 = 1753793710;
        if ( pLight->mAreaLightNearOffset < 0.000099999997 )
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
    if ( LODWORD(lightmat[1].mResourceHandles.UFG::qResourceData::mNode.mNext) == v13 )
      return;
    v14 = (char *)&lightmat[1].mNode.mChild[1];
    goto LABEL_65;
  }
  v8 = 0i64;
  if ( LODWORD(lightmat[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != -317094792 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&lightmat[1].mNode.mChild[1], lightmat[1].mTypeUID, 0xED198478);
    v9 = lightmat->mMaterialUser.mOffset;
    if ( v9 )
      v10 = (_WORD *)((char *)&lightmat->mMaterialUser + v9);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
  }
  if ( *(_DWORD *)&lightmat[3].mDebugName[12] != -262489691 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&lightmat[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
      *(_DWORD *)&lightmat[3].mDebugName[20],
      0xF05AB9A5);
    v11 = lightmat->mMaterialUser.mOffset;
    if ( v11 )
      v12 = (_WORD *)((char *)&lightmat->mMaterialUser + v11);
    else
      v12 = 0i64;
    *v12 |= 0x20u;
  }
  v13 = gLightCardTextureUID;
  if ( LODWORD(lightmat[4].mStateBlockMask.mFlags[1]) != gLightCardTextureUID )
  {
    v14 = &lightmat[4].mDebugName[28];
LABEL_65:
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)v14, *((_DWORD *)v14 + 8), v13);
    v28 = lightmat->mMaterialUser.mOffset;
    if ( v28 )
      v8 = (_WORD *)((char *)&lightmat->mMaterialUser + v28);
    *v8 |= 0x20u;
  }
}

// File Line: 1065
// RVA: 0x4DBF0
void __fastcall FlushLightCards(
        UFG::RenderContext *render_context,
        Render::View *view,
        Render::LightInstance *instances,
        unsigned int n_lights)
{
  int v8; // esi
  char *v9; // rax
  char *v10; // r15
  int v11; // r10d
  __int64 v12; // rbp
  LightCardInfo *v13; // rbx
  Render::LightInstance *v14; // rdi
  char *v15; // rdx
  float v16; // xmm13_4
  LightCardInfo *v17; // r8
  Render::Light *v18; // r11
  int v19; // eax
  LightCardInfo *v20; // rcx
  float v21; // xmm5_4
  float v22; // xmm8_4
  float v23; // xmm7_4
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm15_4
  float v31; // xmm14_4
  float v32; // xmm10_4
  float v33; // xmm9_4
  float v34; // xmm11_4
  float v35; // xmm5_4
  int v36; // xmm3_4
  float colorFade; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  unsigned int m_channelMask; // eax
  unsigned int v45; // eax
  unsigned int v46; // eax
  Illusion::Primitive *v47; // rbx
  float v48; // [rsp+40h] [rbp-F8h]
  float mExposure; // [rsp+44h] [rbp-F4h]
  float v50; // [rsp+48h] [rbp-F0h]
  float v51; // [rsp+4Ch] [rbp-ECh]
  float v52; // [rsp+50h] [rbp-E8h]
  float v53; // [rsp+54h] [rbp-E4h]
  float v54; // [rsp+58h] [rbp-E0h]
  float z; // [rsp+140h] [rbp+8h]
  float v56; // [rsp+140h] [rbp+8h]
  float y; // [rsp+150h] [rbp+18h]
  float x; // [rsp+158h] [rbp+20h]
  float v59; // [rsp+158h] [rbp+20h]

  mExposure = UFG::TimeOfDayManager::GetInstance()->mExposure;
  v8 = 6 * n_lights;
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 216 * n_lights, 0x10u);
  v10 = v9;
  if ( n_lights )
  {
    v11 = gLightCardInfoCount;
    v12 = n_lights;
    v13 = gLightCardInfos;
    v14 = instances;
    v15 = v9 + 44;
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
      v25 = v18->mTransform.v0.z * v16;
      v26 = v18->mTransform.v1.x * -0.5;
      v27 = v18->mTransform.v0.z * -0.5;
      y = v18->mTransform.v3.y;
      v28 = v18->mTransform.v1.z * -0.5;
      v29 = v18->mTransform.v1.y * -0.5;
      x = v18->mTransform.v3.x;
      z = v18->mTransform.v3.z;
      v50 = (float)(x + v22) + v26;
      v30 = (float)(z + v25) + v28;
      v31 = (float)(y + v23) + v29;
      v32 = v18->mTransform.v1.y * 0.5;
      v33 = v18->mTransform.v1.z * 0.5;
      v34 = v18->mTransform.v1.x * 0.5;
      v48 = (float)(y + v24) + v29;
      v53 = (float)(x + v21) + v26;
      v52 = (float)(z + v27) + v33;
      v54 = (float)(z + v27) + v28;
      v51 = (float)(x + v21) + v34;
      v59 = (float)(x + v22) + v34;
      v56 = (float)(z + v25) + v33;
      v35 = (float)(y + v24) + v32;
      if ( v18->mBiasLightCard )
        v36 = (int)FLOAT_1_0;
      else
        v36 = 0;
      colorFade = v14->colorFade;
      v38 = colorFade * v18->mColor.z;
      v39 = colorFade * v18->mColor.x;
      v40 = v14->colorFade * v18->mColor.y;
      *((float *)v15 - 11) = v59;
      *((float *)v15 - 10) = (float)(y + v23) + v32;
      *((float *)v15 - 9) = v56;
      *((_DWORD *)v15 - 4) = v17->m_UVs[0];
      v41 = v39 * mExposure;
      v42 = v40 * mExposure;
      v43 = v38 * mExposure;
      *((float *)v15 - 2) = v50;
      *((float *)v15 - 1) = v31;
      *(float *)v15 = v30;
      *((_DWORD *)v15 + 5) = v17->m_UVs[3];
      *((float *)v15 + 7) = v51;
      *((float *)v15 + 8) = v35;
      *((float *)v15 + 9) = v52;
      *((_DWORD *)v15 + 14) = v17->m_UVs[1];
      *((float *)v15 + 16) = v51;
      *((float *)v15 + 17) = v35;
      *((float *)v15 + 18) = v52;
      *((_DWORD *)v15 + 23) = v17->m_UVs[1];
      *((float *)v15 + 25) = v50;
      *((float *)v15 + 26) = v31;
      *((float *)v15 + 27) = v30;
      *((_DWORD *)v15 + 32) = v17->m_UVs[3];
      *((float *)v15 + 34) = v53;
      *((float *)v15 + 36) = v54;
      *((float *)v15 + 35) = v48;
      *((_DWORD *)v15 + 41) = v17->m_UVs[2];
      *((float *)v15 - 8) = v41;
      *((float *)v15 - 7) = v42;
      *((float *)v15 - 6) = v43;
      *((_DWORD *)v15 - 5) = v36;
      m_channelMask = v17->m_channelMask;
      *((float *)v15 + 1) = v41;
      *((float *)v15 + 2) = v42;
      *((_DWORD *)v15 - 3) = m_channelMask;
      *((float *)v15 + 3) = v43;
      *((_DWORD *)v15 + 4) = v36;
      *((_DWORD *)v15 + 6) = v17->m_channelMask;
      *((float *)v15 + 10) = v41;
      *((float *)v15 + 11) = v42;
      *((float *)v15 + 12) = v43;
      *((_DWORD *)v15 + 13) = v36;
      v45 = v17->m_channelMask;
      *((float *)v15 + 19) = v41;
      *((float *)v15 + 20) = v42;
      *((_DWORD *)v15 + 15) = v45;
      *((float *)v15 + 21) = v43;
      *((_DWORD *)v15 + 22) = v36;
      *((_DWORD *)v15 + 24) = v17->m_channelMask;
      *((float *)v15 + 28) = v41;
      *((float *)v15 + 29) = v42;
      *((float *)v15 + 30) = v43;
      *((_DWORD *)v15 + 31) = v36;
      v46 = v17->m_channelMask;
      *((float *)v15 + 37) = v41;
      *((float *)v15 + 38) = v42;
      *((_DWORD *)v15 + 33) = v46;
      *((float *)v15 + 39) = v43;
      v16 = FLOAT_0_5;
      *((_DWORD *)v15 + 40) = v36;
      *((_DWORD *)v15 + 42) = v17->m_channelMask;
      v15 += 216;
      ++v14;
      --v12;
    }
    while ( v12 );
  }
  UpdateLightMaterial(render_context->mLightMaterial, gLights[instances->lightIndex], instances);
  v47 = Illusion::Primitive::Create("LightCards");
  Illusion::Primitive::SetBuffers(
    v47,
    TRIANGLELIST,
    v10,
    v8,
    (Illusion::VertexDecl *)gLightCardVertexDecl.mData,
    0i64,
    0,
    1);
  Render::View::Draw(view, v47, render_context->mLightMaterial, &UFG::qMatrix44::msIdentity);
}

// File Line: 1138
// RVA: 0x519A0
bool __fastcall IrradianceVolumeSortCompare(Render::IrradianceVolume *a, Render::IrradianceVolume *b)
{
  char v2; // r8

  v2 = a->mFlags & 4;
  if ( v2 == (b->mFlags & 4) )
    return (float)((float)(b->mImageDimensions[0] * b->mImageDimensions[1] * b->mImageDimensions[2])
                 / (float)((float)(b->mScale.y * b->mScale.x) * b->mScale.z)) > (float)((float)(a->mImageDimensions[0]
                                                                                              * a->mImageDimensions[1]
                                                                                              * a->mImageDimensions[2])
                                                                                      / (float)((float)(a->mScale.y * a->mScale.x)
                                                                                              * a->mScale.z));
  else
    return v2 != 0;
}

// File Line: 1158
// RVA: 0x4B710
void __fastcall DrawIrradianceVolumes(UFG::RenderContext *render_context, Render::View *view, int irradiance_type)
{
  unsigned int v5; // eax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  __int64 v8; // r14
  UFG::qBaseTreeRB *i; // rsi
  unsigned int j; // edi
  UFG::qBaseNodeRB *mParent; // rax
  char *v12; // rcx
  __int64 v13; // rbx
  UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *v14; // rsi
  Render::IrradianceVolumeComponent *v15; // rbx
  __int64 v16; // r13
  __int64 p_mIrradianceVolume; // rdi
  unsigned int *mTextureUID; // rbx
  __int64 v19; // rsi
  Render::IrradianceVolume **v20; // r12
  __int64 v21; // rax
  int v22; // ecx
  __int64 v23; // rsi
  Render::IrradianceVolume *v24; // rdi
  Render::IrradianceVolume *v25; // rbx
  Render::IrradianceVolume *v26; // rdi
  Render::IrradianceVolume *v27; // r13
  Render::IrradianceVolume *v28; // rdi
  Render::IrradianceVolume *v29; // rsi
  Render::IrradianceVolume **p_a; // rdi
  Render::IrradianceVolume **v31; // rbx
  Render::IrradianceVolume *v32; // rcx
  __int64 v33; // r12
  __int64 *v34; // r13
  UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *v35; // rax
  Render::IrradianceVolume *v36; // rsi
  __int64 v37; // rbx
  Render::IrradianceVolume *v38; // rdi
  UFG::RenderContext *v39; // rbx
  float z; // xmm0_4
  float v41; // xmm15_4
  int v42; // xmm3_4
  int v43; // xmm4_4
  int v44; // xmm13_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm13_4
  float x; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm6_4
  float DisplayAspectRatio; // xmm0_4
  unsigned int k; // ecx
  unsigned int v53; // eax
  __int64 v54; // rdi
  char v55; // cl
  float v56; // xmm7_4
  float v57; // xmm12_4
  int v58; // xmm11_4
  char v59; // al
  Illusion::Material *mIrradianceVolumeMaterial; // rsi
  float v61; // xmm4_4
  float v62; // xmm0_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // xmm5_4
  float v66; // xmm1_4
  float v67; // xmm2_4
  float v68; // xmm1_4
  float v69; // xmm6_4
  float v70; // xmm2_4
  float v71; // xmm1_4
  float v72; // xmm2_4
  float v73; // xmm3_4
  float v74; // xmm1_4
  float v75; // xmm2_4
  float v76; // xmm3_4
  float v77; // xmm1_4
  float v78; // xmm2_4
  float v79; // xmm3_4
  float v80; // xmm1_4
  float v81; // xmm2_4
  float v82; // xmm3_4
  float v83; // xmm1_4
  float v84; // xmm2_4
  float v85; // xmm3_4
  char v86; // al
  unsigned int v87; // r8d
  __int64 mOffset; // rax
  _WORD *v89; // rax
  unsigned int v90; // r8d
  __int64 v91; // rax
  _WORD *v92; // rax
  unsigned int v93; // r8d
  __int64 v94; // rax
  _WORD *v95; // rax
  float v96; // xmm4_4
  float v97; // xmm3_4
  float v98; // xmm2_4
  float v99; // xmm5_4
  int v100; // xmm2_4
  int v101; // xmm1_4
  int v102; // r13d
  bool v103; // r12
  __int64 n; // rax
  float v105; // xmm0_4
  __int128 v106; // xmm2
  __int128 v107; // xmm1
  __int128 v108; // xmm0
  __int128 v109; // xmm2
  __int128 v110; // xmm1
  __int128 v111; // xmm0
  char *v112; // rbx
  UFG::TimeOfDayManager *Instance; // rax
  UFG::TimeOfDayManager *v114; // rax
  UFG::TimeOfDayManager *v115; // rax
  Illusion::StateValues *StateValues; // rax
  unsigned __int16 Param; // ax
  unsigned int v118; // r8d
  __int64 v119; // rax
  _WORD *v120; // rax
  Illusion::Primitive *v121; // rbx
  float v122; // xmm12_4
  float v123; // xmm11_4
  float v124; // xmm7_4
  UFG::qVector3 *v125; // rdi
  unsigned int v126; // r8d
  __int64 v127; // rax
  _WORD *v128; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v131; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v132; // rax
  unsigned int v133; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 scale; // [rsp+48h] [rbp-B8h] BYREF
  UFG::qMatrix44 v135; // [rsp+60h] [rbp-A0h] BYREF
  float v136; // [rsp+A0h] [rbp-60h]
  float v137; // [rsp+A4h] [rbp-5Ch]
  float v138; // [rsp+A8h] [rbp-58h]
  float v139; // [rsp+ACh] [rbp-54h]
  float y; // [rsp+B0h] [rbp-50h]
  UFG::qMatrix44 m; // [rsp+C0h] [rbp-40h] BYREF
  Illusion::StateArgs *StateArgs; // [rsp+100h] [rbp+0h]
  Render::cbShadowTransformState arg; // [rsp+110h] [rbp+10h] BYREF
  int v144[4]; // [rsp+170h] [rbp+70h]
  UFG::qVector3 v145; // [rsp+180h] [rbp+80h] BYREF
  int v146[4]; // [rsp+190h] [rbp+90h] BYREF
  int v147[4]; // [rsp+1A0h] [rbp+A0h]
  UFG::qColour colour; // [rsp+1B0h] [rbp+B0h] BYREF
  UFG::qVector4 plane; // [rsp+1C0h] [rbp+C0h] BYREF
  UFG::qColour v150; // [rsp+1D0h] [rbp+D0h] BYREF
  UFG::qMatrix44 v151; // [rsp+1E0h] [rbp+E0h] BYREF
  UFG::qMatrix44 d; // [rsp+220h] [rbp+120h] BYREF
  __int64 v153; // [rsp+260h] [rbp+160h]
  __int128 v154[8]; // [rsp+270h] [rbp+170h] BYREF
  UFG::qMatrix44 v155; // [rsp+2F0h] [rbp+1F0h] BYREF
  UFG::qMatrix44 v156; // [rsp+330h] [rbp+230h] BYREF
  Render::IrradianceVolume *a; // [rsp+370h] [rbp+270h] BYREF
  __int64 v158[255]; // [rsp+378h] [rbp+278h] BYREF
  ClipCube v159; // [rsp+B70h] [rbp+A70h] BYREF
  char dest[1008]; // [rsp+DB0h] [rbp+CB0h] BYREF
  float distance_from_near_plane; // [rsp+1290h] [rbp+1190h] BYREF
  UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *vertex_count; // [rsp+1298h] [rbp+1198h] BYREF

  if ( irradiance_type )
  {
    v153 = -2i64;
    v5 = _S6_0;
    if ( (_S6_0 & 1) == 0 )
    {
      _S6_0 |= 1u;
      v6 = UFG::qResourceWarehouse::Instance();
      light_inventory_0 = UFG::qResourceWarehouse::GetInventory(v6, 0xF0A0724F);
      v5 = _S6_0;
    }
    if ( (v5 & 2) == 0 )
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
      for ( j = 0; j < LODWORD(i[2].mNULL.mParent); ++j )
      {
        mParent = i[2].mRoot.mParent;
        if ( mParent )
          v12 = (char *)&i[2] + (_QWORD)mParent;
        else
          v12 = 0i64;
        v13 = (__int64)&v12[496 * j];
        if ( *(char *)(v13 + 362) == irradiance_type
          && Render::View::IsInView(view, &gDeferredCube, (UFG::qMatrix44 *)&v12[496 * j], &distance_from_near_plane) )
        {
          v158[v8 - 1] = v13;
          v8 = (unsigned int)(v8 + 1);
        }
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
        v16 = (__int64)&v15->mNext[-4];
        p_mIrradianceVolume = (__int64)&v15->mIrradianceVolume;
        if ( v15->mIrradianceVolume.mType == irradiance_type
          && Render::View::IsInView(view, &gDeferredCube, &v15->mIrradianceVolume.mTransform, &distance_from_near_plane) )
        {
          if ( !v15->mIrradianceVolume.mTextureUID[2]
            || !((__int64 (__fastcall *)(UFG::qResourceInventory *))texture_inventory->vfptr->Get)(texture_inventory) )
          {
            Render::IrradianceVolumeComponent::UpdateTextureUIDs(v15);
          }
          if ( distance_from_near_plane < 600.0
            && (v15->mIrradianceVolume.mTextureUID[2]
             && ((__int64 (__fastcall *)(UFG::qResourceInventory *))texture_inventory->vfptr->Get)(texture_inventory)
             || (v15->mIrradianceVolume.mFlags & 1) != 0) )
          {
            if ( (v15->mIrradianceVolume.mFlags & 0x10) != 0 )
            {
              if ( UFG::SectionChooser::GetSTDStreamingStateForSectionIndex(v15->mIrradianceVolume.mSectionIndex) )
              {
                --dest[v15->mIrradianceVolume.mSectionIndex];
              }
              else
              {
                mTextureUID = v15->mIrradianceVolume.mTextureUID;
                v19 = 3i64;
                do
                {
                  if ( *mTextureUID )
                    Render::SetHighPriorityLoad(*mTextureUID);
                  ++mTextureUID;
                  --v19;
                }
                while ( v19 );
                v14 = vertex_count;
              }
            }
            if ( (*(_BYTE *)(p_mIrradianceVolume + 363) & 0x20) != 0 )
              ++dest[*(int *)(p_mIrradianceVolume + 492)];
            v158[v8 - 1] = p_mIrradianceVolume;
            v8 = (unsigned int)(v8 + 1);
          }
        }
        v15 = (Render::IrradianceVolumeComponent *)v16;
      }
      while ( (UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *)v16 != v14 );
    }
    v20 = (Render::IrradianceVolume **)(&v156.v3.z + 2 * (int)v8);
    v21 = (8i64 * (int)v8 - 8) >> 3;
    v22 = v21 + 1;
    if ( (int)v21 + 1 < 32 )
    {
      if ( v22 >= 2i64 )
      {
        v33 = 0i64;
        v34 = v158;
        v35 = (UFG::qList<Render::IrradianceVolumeComponent,Render::IrradianceVolumeComponent,1,0> *)(v22 - 1i64);
        vertex_count = v35;
        do
        {
          v36 = (Render::IrradianceVolume *)*v34;
          v37 = v33;
          if ( v33 >= 0 )
          {
            do
            {
              v38 = (Render::IrradianceVolume *)v158[v37 - 1];
              if ( !IrradianceVolumeSortCompare(v36, v38) )
                break;
              v158[v37--] = (__int64)v38;
            }
            while ( v37 >= 0 );
            v35 = vertex_count;
          }
          v158[v37] = (__int64)v36;
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
      v24 = (Render::IrradianceVolume *)v158[v21 / 2 - 1];
      v25 = a;
      if ( IrradianceVolumeSortCompare(v24, a) )
      {
        v158[v23 - 1] = (__int64)v25;
        v25 = v24;
        a = v24;
      }
      v26 = (Render::IrradianceVolume *)v158[v23 - 1];
      v27 = *v20;
      if ( IrradianceVolumeSortCompare(*v20, v26) )
      {
        *v20 = v26;
        v158[v23 - 1] = (__int64)v27;
        v25 = a;
      }
      v28 = (Render::IrradianceVolume *)v158[v23 - 1];
      if ( IrradianceVolumeSortCompare(v28, v25) )
      {
        v158[v23 - 1] = (__int64)v25;
        a = v28;
      }
      v29 = (Render::IrradianceVolume *)v158[v23 - 1];
      p_a = &a;
      v31 = (Render::IrradianceVolume **)(&v156.v3.z + 2 * (int)v8);
      if ( &a <= v20 )
      {
        do
        {
          for ( ; IrradianceVolumeSortCompare(*p_a, v29); ++p_a )
          {
            if ( p_a >= v20 )
              break;
          }
          for ( ; IrradianceVolumeSortCompare(v29, *v31); --v31 )
          {
            if ( &a >= v31 )
              break;
          }
          if ( p_a > v31 )
            break;
          v32 = *p_a;
          *p_a = *v31;
          *v31 = v32;
          ++p_a;
          --v31;
        }
        while ( p_a <= v31 );
      }
      if ( &a < v31 )
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
          &a,
          v31,
          IrradianceVolumeSortCompare);
      if ( p_a < v20 )
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
          p_a,
          (Render::IrradianceVolume **)&v156.v3.z + (int)v8,
          IrradianceVolumeSortCompare);
    }
    v39 = render_context;
    UFG::qInverseAffine(&d, &render_context->mMainViewSettings.mWorldView);
    z = render_context->mMainViewSettings.mProjection.v2.z;
    if ( z == 0.0 || z == render_context->mMainViewSettings.mProjection.v2.w )
      v41 = distance_from_near_plane;
    else
      v41 = render_context->mMainViewSettings.mProjection.v3.z / z;
    v42 = LODWORD(d.v2.z) ^ _xmm[0];
    v43 = LODWORD(d.v2.y) ^ _xmm[0];
    v44 = LODWORD(d.v2.x) ^ _xmm[0];
    v45 = (float)((float)(*(float *)&v44 * *(float *)&v44) + (float)(*(float *)&v43 * *(float *)&v43))
        + (float)(*(float *)&v42 * *(float *)&v42);
    if ( v45 == 0.0 )
      v46 = 0.0;
    else
      v46 = 1.0 / fsqrt(v45);
    v136 = v46 * *(float *)&v42;
    v138 = v46 * *(float *)&v43;
    v47 = *(float *)&v44 * v46;
    x = render_context->mMainViewSettings.mProjection.v0.x;
    if ( x == 0.0 )
      v49 = 0.0;
    else
      v49 = atan2f(1.0, x) * 2.0;
    v50 = tanf(v49 * 0.5);
    DisplayAspectRatio = Render::GetDisplayAspectRatio();
    v137 = d.v3.x;
    y = d.v3.y;
    distance_from_near_plane = d.v3.z;
    v139 = fsqrt(
             (float)((float)((float)(v50 * v41) * (float)(v50 * v41))
                   + (float)((float)((float)(v50 / DisplayAspectRatio) * v41)
                           * (float)((float)(v50 / DisplayAspectRatio) * v41)))
           + (float)(v41 * v41));
    ClipCube::ClipCube(&v159);
    for ( k = 0; ; k = v133 + 1 )
    {
      v133 = k;
      v53 = 128;
      if ( (unsigned int)v8 < 0x80 )
        v53 = v8;
      if ( k >= v53 )
        return;
      v54 = v158[k - 1];
      v55 = *(_BYTE *)(v54 + 363);
      if ( ((v55 & 0x20) == 0 || dest[*(int *)(v54 + 492)] > 0) && ((v55 & 0x10) == 0 || dest[*(int *)(v54 + 492)] <= 0) )
      {
        v56 = v39->mEnvState->AmbientColorHorizon[3];
        v57 = FLOAT_0_1;
        v58 = 0;
        scale.x = 1.0;
        scale.y = -1.0;
        scale.z = 0.5;
        v59 = *(_BYTE *)(v54 + 363);
        if ( (v59 & 2) != 0 )
        {
          v56 = *(float *)&FLOAT_1_0;
          v57 = 0.0;
        }
        if ( (v59 & 4) != 0 )
        {
          v58 = (int)FLOAT_1_0;
          scale.y = 1.0;
        }
        if ( (*(_BYTE *)(v54 + 362) != 2 || v56 > 0.0)
          && (*(_DWORD *)(v54 + 376)
           && ((__int64 (__fastcall *)(UFG::qResourceInventory *))texture_inventory->vfptr->Get)(texture_inventory)
           || (*(_BYTE *)(v54 + 363) & 1) != 0) )
        {
          break;
        }
      }
LABEL_171:
      ;
    }
    mIrradianceVolumeMaterial = v39->mIrradianceVolumeMaterial;
    v61 = *(float *)v54;
    v62 = *(float *)(v54 + 4);
    v63 = *(float *)(v54 + 8);
    v64 = *(float *)(v54 + 12);
    m.v0.x = *(float *)v54;
    m.v0.y = v62;
    m.v0.z = v63;
    m.v0.w = v64;
    v65 = *(float *)(v54 + 20);
    v66 = *(float *)(v54 + 24);
    v67 = *(float *)(v54 + 28);
    m.v1.x = *(float *)(v54 + 16);
    m.v1.y = v65;
    m.v1.z = v66;
    m.v1.w = v67;
    v68 = *(float *)(v54 + 36);
    v69 = *(float *)(v54 + 40);
    v70 = *(float *)(v54 + 44);
    m.v2.x = *(float *)(v54 + 32);
    m.v2.y = v68;
    m.v2.z = v69;
    m.v2.w = v70;
    v71 = *(float *)(v54 + 52);
    v72 = *(float *)(v54 + 56);
    v73 = *(float *)(v54 + 60);
    m.v3.x = *(float *)(v54 + 48);
    m.v3.y = v71;
    m.v3.z = v72;
    m.v3.w = v73;
    v74 = *(float *)(v54 + 68);
    v75 = *(float *)(v54 + 72);
    v76 = *(float *)(v54 + 76);
    v135.v0.x = *(float *)(v54 + 64);
    v135.v0.y = v74;
    v135.v0.z = v75;
    v135.v0.w = v76;
    v77 = *(float *)(v54 + 84);
    v78 = *(float *)(v54 + 88);
    v79 = *(float *)(v54 + 92);
    v135.v1.x = *(float *)(v54 + 80);
    v135.v1.y = v77;
    v135.v1.z = v78;
    v135.v1.w = v79;
    v80 = *(float *)(v54 + 100);
    v81 = *(float *)(v54 + 104);
    v82 = *(float *)(v54 + 108);
    v135.v2.x = *(float *)(v54 + 96);
    v135.v2.y = v80;
    v135.v2.z = v81;
    v135.v2.w = v82;
    v83 = *(float *)(v54 + 116);
    v84 = *(float *)(v54 + 120);
    v85 = *(float *)(v54 + 124);
    v135.v3.x = *(float *)(v54 + 112);
    v135.v3.y = v83;
    v135.v3.z = v84;
    v135.v3.w = v85;
    if ( *(_BYTE *)(v54 + 362) == 2 )
    {
      v86 = *(_BYTE *)(v54 + 363);
      mIrradianceVolumeMaterial = (v86 & 1) != 0
                                ? v39->mIrradianceVolumeSkyBlackMaterial
                                : v39->mIrradianceVolumeSkyMaterial;
      if ( (v86 & 4) != 0 )
      {
        m.v0.x = v61 + 0.1;
        m.v1.y = v65 + 0.1;
        m.v2.z = v69 + 0.1;
        UFG::qInverse(&v135, &m);
        mIrradianceVolumeMaterial = v39->mIrradianceVolumeSkyMaterial2;
      }
    }
    v87 = -1324127765;
    if ( *(_DWORD *)(v54 + 368) )
      v87 = *(_DWORD *)(v54 + 368);
    if ( LODWORD(mIrradianceVolumeMaterial[3].mMaterialUser.mOffset) != v87 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mIrradianceVolumeMaterial[3].mStateBlockMask,
        (unsigned int)mIrradianceVolumeMaterial[4].mNode.mParent,
        v87);
      mOffset = mIrradianceVolumeMaterial->mMaterialUser.mOffset;
      if ( mOffset )
        v89 = (_WORD *)((char *)&mIrradianceVolumeMaterial->mMaterialUser + mOffset);
      else
        v89 = 0i64;
      *v89 |= 0x20u;
    }
    v90 = -1324127765;
    if ( *(_DWORD *)(v54 + 372) )
      v90 = *(_DWORD *)(v54 + 372);
    if ( mIrradianceVolumeMaterial[4].mTypeUID != v90 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mIrradianceVolumeMaterial[4].mNode.mUID,
        *(_DWORD *)&mIrradianceVolumeMaterial[4].mDebugName[4],
        v90);
      v91 = mIrradianceVolumeMaterial->mMaterialUser.mOffset;
      if ( v91 )
        v92 = (_WORD *)((char *)&mIrradianceVolumeMaterial->mMaterialUser + v91);
      else
        v92 = 0i64;
      *v92 |= 0x20u;
    }
    v93 = -1324127765;
    if ( *(_DWORD *)(v54 + 376) )
      v93 = *(_DWORD *)(v54 + 376);
    if ( LODWORD(mIrradianceVolumeMaterial[4].mStateBlockMask.mFlags[1]) != v93 )
    {
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&mIrradianceVolumeMaterial[4].mDebugName[28],
        mIrradianceVolumeMaterial[4].mNumParams,
        v93);
      v94 = mIrradianceVolumeMaterial->mMaterialUser.mOffset;
      if ( v94 )
        v95 = (_WORD *)((char *)&mIrradianceVolumeMaterial->mMaterialUser + v94);
      else
        v95 = 0i64;
      *v95 |= 0x20u;
    }
    v96 = (float)((float)((float)(v137 * v135.v0.x) + (float)(y * v135.v1.x))
                + (float)(distance_from_near_plane * v135.v2.x))
        + v135.v3.x;
    v97 = (float)((float)((float)(v137 * v135.v0.y) + (float)(y * v135.v1.y))
                + (float)(distance_from_near_plane * v135.v2.y))
        + v135.v3.y;
    v98 = (float)((float)((float)(v137 * v135.v0.z) + (float)(y * v135.v1.z))
                + (float)(distance_from_near_plane * v135.v2.z))
        + v135.v3.z;
    v99 = (float)((float)((float)(v137 * v135.v0.w) + (float)(y * v135.v1.w))
                + (float)(distance_from_near_plane * v135.v2.w))
        + v135.v3.w;
    if ( v99 < 0.0 )
      LODWORD(v99) ^= _xmm[0];
    if ( v98 < 0.0 )
      LODWORD(v98) ^= _xmm[0];
    if ( v97 < 0.0 )
      LODWORD(v97) ^= _xmm[0];
    if ( v96 < 0.0 )
      LODWORD(v96) ^= _xmm[0];
    *(float *)v147 = v96;
    *(float *)&v147[1] = v97;
    *(float *)&v147[2] = v98;
    *(float *)&v147[3] = v99;
    *(float *)&v100 = (float)(1.0 / *(float *)(v54 + 340)) * v139;
    *(float *)&v101 = (float)(1.0 / *(float *)(v54 + 336)) * v139;
    *(float *)v144 = (float)(1.0 / *(float *)(v54 + 332)) * v139;
    v144[1] = v101;
    v144[2] = v100;
    v102 = 1;
    v103 = 0;
    for ( n = 0i64; n < 3; ++n )
    {
      v105 = *(float *)&v147[n];
      if ( v105 > 1.0 )
      {
        v103 = (float)(*(float *)&v144[n] + 1.0) > v105;
        v102 = 2;
        goto LABEL_133;
      }
    }
    if ( *(_BYTE *)(v54 + 362) == 2 )
      UFG::RenderStageExposureMetering::SetCameraIrradianceVolume(
        UFG::RenderWorld::msExposureMetering,
        (Render::IrradianceVolume *)v54);
LABEL_133:
    StateArgs = Render::View::GetStateArgs(view);
    v106 = *(_OWORD *)(v54 + 80);
    v107 = *(_OWORD *)(v54 + 96);
    v108 = *(_OWORD *)(v54 + 112);
    v154[0] = *(_OWORD *)(v54 + 64);
    v154[1] = v106;
    v154[2] = v107;
    v154[3] = v108;
    v109 = *(_OWORD *)(v54 + 272);
    v110 = *(_OWORD *)(v54 + 288);
    v111 = *(_OWORD *)(v54 + 304);
    v154[4] = *(_OWORD *)(v54 + 256);
    v154[5] = v109;
    v154[6] = v110;
    v154[7] = v111;
    UFG::qScaleMatrix(&v155, &scale);
    v155.v3.z = 0.5;
    v145.x = scale.x * 2.0;
    v145.y = scale.y * 2.0;
    v145.z = scale.z * 2.0;
    UFG::qScaleMatrix(&v156, &v145);
    v156.v3.x = -0.5;
    v156.v3.y = -0.5;
    v112 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
    Instance = UFG::TimeOfDayManager::GetInstance();
    *(float *)&v110 = Instance->mAmbientSkyDirection[0].y;
    *(float *)&v109 = Instance->mAmbientSkyDirection[0].z;
    *(float *)v112 = Instance->mAmbientSkyDirection[0].x;
    *((_DWORD *)v112 + 1) = v110;
    *((_DWORD *)v112 + 2) = v109;
    v114 = UFG::TimeOfDayManager::GetInstance();
    *(float *)&v110 = v114->mAmbientSkyDirection[1].y;
    *(float *)&v109 = v114->mAmbientSkyDirection[1].z;
    *((_DWORD *)v112 + 4) = LODWORD(v114->mAmbientSkyDirection[1].x);
    *((_DWORD *)v112 + 5) = v110;
    *((_DWORD *)v112 + 6) = v109;
    v115 = UFG::TimeOfDayManager::GetInstance();
    *(float *)&v110 = v115->mAmbientSkyDirection[2].y;
    *(float *)&v109 = v115->mAmbientSkyDirection[2].z;
    *((_DWORD *)v112 + 8) = LODWORD(v115->mAmbientSkyDirection[2].x);
    *((_DWORD *)v112 + 9) = v110;
    *((_DWORD *)v112 + 10) = v109;
    *((float *)v112 + 12) = v57;
    *((_DWORD *)v112 + 13) = 1065353216;
    *((float *)v112 + 14) = v56;
    *((_DWORD *)v112 + 15) = v58;
    StateValues = Render::View::GetStateValues(view);
    StateValues->mSetValueMask.mFlags[0] |= 0x8000ui64;
    StateValues->mParamValues[15] = v112;
    *(float *)v146 = (float)(*(float *)(v54 + 332) / (float)*(__int16 *)(v54 + 356))
                   / (float)(*(float *)(v54 + 332) * 2.0);
    *(float *)&v146[1] = (float)(*(float *)(v54 + 336) / (float)*(__int16 *)(v54 + 358))
                       / (float)(*(float *)(v54 + 336) * 2.0);
    *(float *)&v146[2] = (float)(*(float *)(v54 + 340) / (float)*(__int16 *)(v54 + 360))
                       / (float)(*(float *)(v54 + 340) * 2.0);
    v146[3] = 0;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
      Render::cbShadowTransformState::sStateParamIndex = Param;
      arg.mStateParamIndex = Param;
    }
    arg.mViewWorld = &view->mViewWorld;
    arg.mWorldView = (UFG::qMatrix44 *)v154;
    arg.mProjection = &v155;
    arg.mCutplanes = 0i64;
    arg.mBiases = (const float *)v146;
    arg.mBlurWidths = 0i64;
    arg.mCached_Remote.m_Stream = 0i64;
    Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &arg);
    if ( v102 == 1 )
    {
      UFG::RenderStageExposureMetering::SetCameraIrradianceVolume(
        UFG::RenderWorld::msExposureMetering,
        (Render::IrradianceVolume *)v54);
      if ( gClearStencil )
      {
        *(_QWORD *)&colour.r = 0i64;
        *(_QWORD *)&colour.b = 0i64;
        Render::View::Clear(view, &colour, 4u, 1.0, 0);
        Render::View::Draw(view, &gDeferredCube, &m, 0, (Illusion::Material *)gMatStencilNear.mData);
        if ( *(_DWORD *)&mIrradianceVolumeMaterial[3].mDebugName[12] != -1835606658 )
        {
          v118 = -1835606658;
LABEL_141:
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&mIrradianceVolumeMaterial[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
            *(_DWORD *)&mIrradianceVolumeMaterial[3].mDebugName[20],
            v118);
          v119 = mIrradianceVolumeMaterial->mMaterialUser.mOffset;
          if ( v119 )
            v120 = (_WORD *)((char *)&mIrradianceVolumeMaterial->mMaterialUser + v119);
          else
            v120 = 0i64;
          *v120 |= 0x20u;
        }
      }
      else
      {
        Render::View::Draw(view, &gDeferredCube, &m, 0, (Illusion::Material *)gMatStencilNearNoClear.mData);
        if ( *(_DWORD *)&mIrradianceVolumeMaterial[3].mDebugName[12] != 1537965747 )
        {
          v118 = 1537965747;
          goto LABEL_141;
        }
      }
LABEL_145:
      Render::View::Draw(view, &gDeferredCube, &m, 0, mIrradianceVolumeMaterial);
LABEL_168:
      mPrev = arg.mPrev;
      mNext = arg.mNext;
      arg.mPrev->mNext = arg.mNext;
      mNext->mPrev = mPrev;
      arg.mPrev = &arg;
      arg.mNext = &arg;
      arg.mIsSet = 0;
      if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
        StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
      v131 = arg.mPrev;
      v132 = arg.mNext;
      arg.mPrev->mNext = arg.mNext;
      v132->mPrev = v131;
      arg.mPrev = &arg;
      arg.mNext = &arg;
      v39 = render_context;
      goto LABEL_171;
    }
    v121 = 0i64;
    if ( v103 )
    {
      v122 = v136;
      v123 = v138;
      v124 = (float)((float)(COERCE_FLOAT(LODWORD(v47) ^ _xmm[0])
                           * (float)((float)(v47 * 0.001) + (float)((float)(v47 * v41) + d.v3.x)))
                   + (float)(COERCE_FLOAT(LODWORD(v138) ^ _xmm[0])
                           * (float)((float)((float)(v138 * v41) + d.v3.y) + (float)(v138 * 0.001))))
           + (float)(COERCE_FLOAT(LODWORD(v136) ^ _xmm[0])
                   * (float)((float)(d.v3.z + (float)(v136 * v41)) + (float)(v136 * 0.001)));
      UFG::qTranspose(&v151, &m);
      plane.x = (float)((float)((float)(v123 * v151.v1.x) + (float)(v47 * v151.v0.x)) + (float)(v122 * v151.v2.x))
              + (float)(v151.v3.x * v124);
      plane.y = (float)((float)((float)(v123 * v151.v1.y) + (float)(v47 * v151.v0.y)) + (float)(v122 * v151.v2.y))
              + (float)(v151.v3.y * v124);
      plane.z = (float)((float)((float)(v123 * v151.v1.z) + (float)(v47 * v151.v0.z)) + (float)(v122 * v151.v2.z))
              + (float)(v151.v3.z * v124);
      plane.w = (float)((float)((float)(v123 * v151.v1.w) + (float)(v47 * v151.v0.w)) + (float)(v122 * v151.v2.w))
              + (float)(v151.v3.w * v124);
      ClipCube::Reset(&v159);
      ClipCube::ClipToPlane(&v159, &plane);
      if ( ClipCube::GetClipCount(&v159) )
      {
        LODWORD(vertex_count) = 0;
        v125 = ClipCube::GenerateCube(&v159, (unsigned int *)&vertex_count);
        if ( (_DWORD)vertex_count )
        {
          v121 = Illusion::Primitive::Create("ClipCube");
          Illusion::Primitive::SetBuffers(
            v121,
            TRIANGLELIST,
            v125,
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
      *(_QWORD *)&v150.r = 0i64;
      *(_QWORD *)&v150.b = 0i64;
      Render::View::Clear(view, &v150, 4u, 1.0, 0);
      if ( v121 )
        Render::View::Draw(view, v121, (Illusion::Material *)gMatStencil.mData, &m);
      else
        Render::View::Draw(view, &gDeferredCube, &m, 0, (Illusion::Material *)gMatStencil.mData);
      if ( *(_DWORD *)&mIrradianceVolumeMaterial[3].mDebugName[12] != -929296280 )
      {
        v126 = -929296280;
LABEL_161:
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&mIrradianceVolumeMaterial[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
          *(_DWORD *)&mIrradianceVolumeMaterial[3].mDebugName[20],
          v126);
        v127 = mIrradianceVolumeMaterial->mMaterialUser.mOffset;
        if ( v127 )
          v128 = (_WORD *)((char *)&mIrradianceVolumeMaterial->mMaterialUser + v127);
        else
          v128 = 0i64;
        *v128 |= 0x20u;
      }
    }
    else
    {
      if ( v121 )
        Render::View::Draw(view, v121, (Illusion::Material *)gMatStencilNoClear.mData, &m);
      else
        Render::View::Draw(view, &gDeferredCube, &m, 0, (Illusion::Material *)gMatStencilNoClear.mData);
      if ( *(_DWORD *)&mIrradianceVolumeMaterial[3].mDebugName[12] != 1063454199 )
      {
        v126 = 1063454199;
        goto LABEL_161;
      }
    }
    if ( v121 )
    {
      Render::View::Draw(view, v121, mIrradianceVolumeMaterial, &m);
      goto LABEL_168;
    }
    goto LABEL_145;
  }
}

// File Line: 1497
// RVA: 0x4CF00
void __fastcall DrawSpotLight(
        UFG::RenderContext *render_context,
        Render::View *view,
        Render::Light *light,
        Render::LightInstance *light_instance)
{
  float fFar; // xmm2_4
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  float w; // xmm9_4
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
  Illusion::StateArgs *StateArgs; // rdi
  Render::ViewSettings *mSettings; // r14
  unsigned __int16 Param; // ax
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm6_4
  float mTexDistAttenV; // xmm0_4
  unsigned __int16 v31; // ax
  __int64 v32; // rcx
  _QWORD *v33; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  __int64 v36; // rcx
  _QWORD *v37; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rax
  Render::cbDeferredLightState arg; // [rsp+40h] [rbp-98h] BYREF
  UFG::qMatrix44 *p_mViewWorld; // [rsp+A8h] [rbp-30h]
  UFG::qMatrix44 *p_shadowWorldView; // [rsp+B0h] [rbp-28h]
  UFG::qMatrix44 *p_shadowProjection; // [rsp+B8h] [rbp-20h]
  __int64 v44; // [rsp+C0h] [rbp-18h]
  __int128 v45; // [rsp+C8h] [rbp-10h]
  __int64 v46; // [rsp+D8h] [rbp+0h]
  UFG::qMatrix44 local_world; // [rsp+E8h] [rbp+10h] BYREF
  __int64 v48; // [rsp+128h] [rbp+50h]
  UFG::qMatrix44 shadowWorldView; // [rsp+138h] [rbp+60h] BYREF
  UFG::qMatrix44 shadowProjection; // [rsp+178h] [rbp+A0h] BYREF
  float v51; // [rsp+298h] [rbp+1C0h]
  float mExposure; // [rsp+2A0h] [rbp+1C8h]
  Illusion::Material *retaddr; // [rsp+2A8h] [rbp+1D0h]
  float v54; // [rsp+2B0h] [rbp+1D8h]
  float v55; // [rsp+2B8h] [rbp+1E0h]
  char v56; // [rsp+2C0h] [rbp+1E8h]

  v48 = -2i64;
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
    if ( v56 )
      view->mSubmitContext->vfptr->AddRenderCommand(view->mSubmitContext, 21, 0, 0i64);
    mExposure = UFG::TimeOfDayManager::GetInstance()->mExposure;
    x = light->mTransform.v0.x;
    y = light->mTransform.v0.y;
    z = light->mTransform.v0.z;
    w = light->mTransform.v0.w;
    v11 = light->mTransform.v1.x;
    v12 = light->mTransform.v1.y;
    v13 = light->mTransform.v1.z;
    v14 = light->mTransform.v1.w;
    v15 = light->mTransform.v2.x;
    v16 = light->mTransform.v2.y;
    v17 = light->mTransform.v3.y;
    v18 = light->mTransform.v3.z;
    v19 = light->mTransform.v3.w;
    local_world.v3.x = light->mTransform.v3.x;
    local_world.v3.y = v17;
    local_world.v3.z = v18;
    local_world.v3.w = v19;
    v20 = tanf(light->mFovHalfOuter);
    v21 = v20 * v51;
    local_world.v0.x = x * v21;
    local_world.v0.y = y * v21;
    local_world.v0.z = z * v21;
    local_world.v0.w = w * v21;
    local_world.v1.x = v11 * v21;
    local_world.v1.y = v12 * v21;
    local_world.v1.z = v13 * v21;
    local_world.v1.w = v14 * v21;
    local_world.v2.x = v15 * v51;
    local_world.v2.y = v16 * v51;
    local_world.v2.z = light->mTransform.v2.z * v51;
    local_world.v2.w = light->mTransform.v2.w * v51;
    StateArgs = Render::View::GetStateArgs(view);
    mSettings = view->mSettings;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbDeferredLightState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbDeferredLightState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbDeferredLight");
      Render::cbDeferredLightState::sStateParamIndex = Param;
      arg.mStateParamIndex = Param;
    }
    arg.mWorldView = &mSettings->mWorldView;
    v25 = (float)((float)(v55 * light->mColor.z) * mExposure) * (float)((float)(v55 * light->mColor.z) * mExposure);
    v26 = (float)((float)(v55 * light->mColor.y) * mExposure) * (float)((float)(v55 * light->mColor.y) * mExposure);
    arg.mColor.x = (float)((float)(v55 * light->mColor.x) * mExposure)
                 * (float)((float)(v55 * light->mColor.x) * mExposure);
    arg.mColor.y = v26;
    arg.mColor.z = v25;
    v27 = light->mTransform.v3.y;
    v28 = light->mTransform.v3.z;
    arg.mPosition.x = light->mTransform.v3.x;
    arg.mPosition.y = v27;
    arg.mPosition.z = v28;
    *(float *)&arg.mStateParamIndex = v51;
    *(float *)(&arg.mIsSet + 1) = light->mDecayPower;
    arg.mPosition.x = v54;
    v29 = cosf(light->mFovHalfOuter);
    arg.mWorldView = (UFG::qMatrix44 *)__PAIR64__(LODWORD(v29), COERCE_UNSIGNED_INT(cosf(light->mFovHalfInner)));
    if ( light->mTexDistAttenUID == -1 )
      mTexDistAttenV = FLOAT_N1_0;
    else
      mTexDistAttenV = light->mTexDistAttenV;
    arg.mPosition.y = mTexDistAttenV;
    Illusion::StateArgs::Set<Render::cbDeferredLightState>(StateArgs, &arg);
    *(_QWORD *)&arg.mFovInner = &arg.mFovInner;
    *(_QWORD *)&arg.mShadowFade = &arg.mFovInner;
    *(_QWORD *)&arg.mAreaLightWidthHeightNearFar.x = 0i64;
    LOWORD(arg.mAreaLightWidthHeightNearFar.z) = Render::cbShadowTransformState::sStateParamIndex;
    HIWORD(arg.mAreaLightWidthHeightNearFar.z) = 1;
    if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
    {
      v31 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
      Render::cbShadowTransformState::sStateParamIndex = v31;
      LOWORD(arg.mAreaLightWidthHeightNearFar.z) = v31;
    }
    p_mViewWorld = &view->mViewWorld;
    p_shadowWorldView = &shadowWorldView;
    p_shadowProjection = &shadowProjection;
    v44 = 0i64;
    v45 = 0i64;
    v46 = 0i64;
    Illusion::StateArgs::Set<Render::cbShadowTransformState>(
      StateArgs,
      (Render::cbShadowTransformState *)&arg.mFovInner);
    Render::View::Draw(view, &gDeferredCone, &local_world, 0, retaddr);
    v32 = *(_QWORD *)&arg.mFovInner;
    v33 = *(_QWORD **)&arg.mShadowFade;
    *(_QWORD *)(*(_QWORD *)&arg.mFovInner + 8i64) = *(_QWORD *)&arg.mShadowFade;
    *v33 = v32;
    *(_QWORD *)&arg.mFovInner = &arg.mFovInner;
    *(_QWORD *)&arg.mShadowFade = &arg.mFovInner;
    HIBYTE(arg.mAreaLightWidthHeightNearFar.z) = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[SLOWORD(arg.mAreaLightWidthHeightNearFar.z)].mNode.mNext == &StateArgs->mStateArgs[SLOWORD(arg.mAreaLightWidthHeightNearFar.z)] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(arg.mAreaLightWidthHeightNearFar.z) >> 6] &= ~(1i64 << (LOBYTE(arg.mAreaLightWidthHeightNearFar.z) & 0x3F));
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v36 = *(_QWORD *)&arg.mFovInner;
    v37 = *(_QWORD **)&arg.mShadowFade;
    *(_QWORD *)(*(_QWORD *)&arg.mFovInner + 8i64) = *(_QWORD *)&arg.mShadowFade;
    *v37 = v36;
    v38 = arg.mPrev;
    v39 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v39->mPrev = v38;
  }
}

// File Line: 1556
// RVA: 0x4B0F0
void __fastcall DrawAreaLight(
        UFG::RenderContext *render_context,
        Render::View *view,
        Render::Light *light,
        Render::LightInstance *light_instance)
{
  float fFar; // xmm6_4
  float mShadowNear; // xmm3_4
  float x; // xmm7_4
  float y; // xmm8_4
  float z; // xmm9_4
  float w; // xmm10_4
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
  float mFovHalfOuter; // xmm0_4
  float v24; // xmm7_4
  float v25; // xmm8_4
  float v26; // xmm9_4
  float v27; // xmm10_4
  float v28; // xmm11_4
  float v29; // xmm12_4
  float v30; // xmm13_4
  float v31; // xmm14_4
  float v32; // xmm0_4
  Illusion::StateArgs *StateArgs; // rdi
  Render::ViewSettings *mSettings; // r15
  unsigned __int16 Param; // ax
  float mAreaLightIntensityScale; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  float mAreaLightNearOffset; // xmm7_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm6_4
  float mAreaLightFarOffset; // xmm2_4
  float mAreaLightHeight; // xmm1_4
  float mTexDistAttenV; // xmm0_4
  unsigned __int16 v46; // ax
  Illusion::ModelHandle *v47; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  __int64 v50; // rcx
  _QWORD *v51; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v52; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v53; // rax
  __int64 v54; // rcx
  _QWORD *v55; // rax
  UFG::qMatrix44 local_world; // [rsp+40h] [rbp-98h] BYREF
  float v57; // [rsp+80h] [rbp-58h]
  float v58; // [rsp+84h] [rbp-54h]
  float v59; // [rsp+88h] [rbp-50h]
  float v60; // [rsp+8Ch] [rbp-4Ch]
  float v61; // [rsp+90h] [rbp-48h]
  float v62; // [rsp+94h] [rbp-44h]
  float v63; // [rsp+98h] [rbp-40h]
  float mDecayPower; // [rsp+9Ch] [rbp-3Ch]
  float v65; // [rsp+A0h] [rbp-38h]
  float v66; // [rsp+A4h] [rbp-34h]
  int v67; // [rsp+A8h] [rbp-30h]
  float v68; // [rsp+ACh] [rbp-2Ch]
  float mAreaLightWidth; // [rsp+B0h] [rbp-28h]
  float v70; // [rsp+B4h] [rbp-24h]
  float v71; // [rsp+B8h] [rbp-20h]
  float v72; // [rsp+BCh] [rbp-1Ch]
  Render::cbShadowTransformState v73; // [rsp+C8h] [rbp-10h] BYREF
  __int64 v74; // [rsp+128h] [rbp+50h]
  UFG::qMatrix44 shadowWorldView; // [rsp+138h] [rbp+60h] BYREF
  UFG::qMatrix44 shadowProjection; // [rsp+178h] [rbp+A0h] BYREF
  float mExposure; // [rsp+298h] [rbp+1C0h]
  Illusion::Material *retaddr; // [rsp+2A8h] [rbp+1D0h]
  int v79; // [rsp+2B0h] [rbp+1D8h]
  float v80; // [rsp+2B8h] [rbp+1E0h]
  char v81; // [rsp+2C0h] [rbp+1E8h]

  v74 = -2i64;
  fFar = light->mDecayRadius * light_instance->radScale;
  if ( fFar >= 0.0099999998 )
  {
    mShadowNear = light->mShadowNear;
    if ( mShadowNear <= (float)(light->mAreaLightNearOffset * 0.5) )
      mShadowNear = light->mAreaLightNearOffset * 0.5;
    Render::BuildShadowSpotView(
      &shadowWorldView,
      &shadowProjection,
      &light->mTransform,
      mShadowNear,
      fFar,
      light->mFovHalfInner * 2.0,
      light->mAreaLightWidth / light->mAreaLightHeight);
    if ( v81 )
      view->mSubmitContext->vfptr->AddRenderCommand(view->mSubmitContext, 21, 0, 0i64);
    mExposure = UFG::TimeOfDayManager::GetInstance()->mExposure;
    x = light->mTransform.v0.x;
    y = light->mTransform.v0.y;
    z = light->mTransform.v0.z;
    w = light->mTransform.v0.w;
    v12 = light->mTransform.v1.x;
    v13 = light->mTransform.v1.y;
    v14 = light->mTransform.v1.z;
    v15 = light->mTransform.v1.w;
    v16 = light->mTransform.v2.x;
    v17 = light->mTransform.v2.y;
    v18 = light->mTransform.v2.z;
    v19 = light->mTransform.v3.y;
    v20 = light->mTransform.v3.z;
    v21 = light->mTransform.v3.w;
    local_world.v3.x = light->mTransform.v3.x;
    local_world.v3.y = v19;
    local_world.v3.z = v20;
    local_world.v3.w = v21;
    v22 = 1;
    mFovHalfOuter = light->mFovHalfOuter;
    if ( mFovHalfOuter <= 1.0 )
    {
      v32 = tanf(mFovHalfOuter) * fFar;
      v24 = x * v32;
      v25 = y * v32;
      v26 = z * v32;
      v27 = w * v32;
      v28 = v12 * v32;
      v29 = v13 * v32;
      v30 = v14 * v32;
      v31 = v15 * v32;
      local_world.v2.y = light->mTransform.v2.y * fFar;
      local_world.v2.z = light->mTransform.v2.z * fFar;
    }
    else
    {
      v24 = x * fFar;
      v25 = y * fFar;
      v26 = z * fFar;
      v27 = w * fFar;
      v28 = v12 * fFar;
      v29 = v13 * fFar;
      v30 = v14 * fFar;
      v31 = v15 * fFar;
      local_world.v2.y = v17 * fFar;
      local_world.v2.z = v18 * fFar;
      v22 = 0;
    }
    local_world.v2.w = light->mTransform.v2.w * fFar;
    local_world.v2.x = v16 * fFar;
    local_world.v1.w = v31;
    local_world.v1.z = v30;
    local_world.v1.y = v29;
    local_world.v1.x = v28;
    local_world.v0.w = v27;
    local_world.v0.z = v26;
    local_world.v0.y = v25;
    local_world.v0.x = v24;
    StateArgs = Render::View::GetStateArgs(view);
    mSettings = view->mSettings;
    *(_QWORD *)&local_world.v1.z = &local_world.v1.z;
    *(_QWORD *)&local_world.v2.x = &local_world.v1.z;
    *(_QWORD *)&local_world.v2.z = 0i64;
    LOWORD(local_world.v3.x) = Render::cbDeferredLightState::sStateParamIndex;
    HIWORD(local_world.v3.x) = 1;
    if ( (_WORD)Render::cbDeferredLightState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbDeferredLight");
      Render::cbDeferredLightState::sStateParamIndex = Param;
      LOWORD(local_world.v3.x) = Param;
    }
    *(_QWORD *)&local_world.v3.z = mSettings;
    mAreaLightIntensityScale = light->mAreaLightIntensityScale;
    v37 = (float)((float)((float)(v80 * light->mColor.z) * mExposure)
                * (float)((float)(v80 * light->mColor.z) * mExposure))
        * mAreaLightIntensityScale;
    v38 = (float)((float)((float)(v80 * light->mColor.y) * mExposure)
                * (float)((float)(v80 * light->mColor.y) * mExposure))
        * mAreaLightIntensityScale;
    v60 = (float)((float)((float)(v80 * light->mColor.x) * mExposure)
                * (float)((float)(v80 * light->mColor.x) * mExposure))
        * mAreaLightIntensityScale;
    v61 = v38;
    v62 = v37;
    mAreaLightNearOffset = light->mAreaLightNearOffset;
    v40 = (float)((float)(mAreaLightNearOffset * light->mTransform.v2.z) * 0.5) + light->mTransform.v3.z;
    v41 = (float)((float)(mAreaLightNearOffset * light->mTransform.v2.y) * 0.5) + light->mTransform.v3.y;
    v57 = (float)((float)(mAreaLightNearOffset * light->mTransform.v2.x) * 0.5) + light->mTransform.v3.x;
    v58 = v41;
    v59 = v40;
    v63 = (float)(mAreaLightNearOffset * 0.5) + fFar;
    mDecayPower = light->mDecayPower;
    v67 = v79;
    v42 = cosf(light->mFovHalfOuter);
    v65 = cosf(light->mFovHalfInner);
    v66 = v42;
    mAreaLightFarOffset = light->mAreaLightFarOffset;
    mAreaLightHeight = light->mAreaLightHeight;
    mAreaLightWidth = light->mAreaLightWidth;
    v70 = mAreaLightHeight;
    v71 = mAreaLightNearOffset;
    v72 = mAreaLightFarOffset;
    if ( light->mTexDistAttenUID == -1 )
      mTexDistAttenV = FLOAT_N1_0;
    else
      mTexDistAttenV = light->mTexDistAttenV;
    v68 = mTexDistAttenV;
    Illusion::StateArgs::Set<Render::cbDeferredLightState>(StateArgs, (Render::cbDeferredLightState *)&local_world.v1.z);
    v73.mPrev = &v73;
    v73.mNext = &v73;
    v73.mCallback = 0i64;
    v73.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
    *(_WORD *)&v73.mFlags = 1;
    if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == 0xFFFF )
    {
      v46 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
      Render::cbShadowTransformState::sStateParamIndex = v46;
      v73.mStateParamIndex = v46;
    }
    v73.mViewWorld = &view->mViewWorld;
    v73.mWorldView = &shadowWorldView;
    v73.mProjection = &shadowProjection;
    memset(&v73.mCutplanes, 0, 32);
    Illusion::StateArgs::Set<Render::cbShadowTransformState>(StateArgs, &v73);
    v47 = &gDeferredSphere;
    if ( v22 )
      v47 = &gDeferredCone;
    Render::View::Draw(view, v47, &local_world, 0, retaddr);
    mPrev = v73.mPrev;
    mNext = v73.mNext;
    v73.mPrev->mNext = v73.mNext;
    mNext->mPrev = mPrev;
    v73.mPrev = &v73;
    v73.mNext = &v73;
    v73.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v73.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v73.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v73.mStateParamIndex >> 6] &= ~(1i64 << (v73.mStateParamIndex & 0x3F));
    v50 = *(_QWORD *)&local_world.v1.z;
    v51 = *(_QWORD **)&local_world.v2.x;
    *(_QWORD *)(*(_QWORD *)&local_world.v1.z + 8i64) = *(_QWORD *)&local_world.v2.x;
    *v51 = v50;
    *(_QWORD *)&local_world.v1.z = &local_world.v1.z;
    *(_QWORD *)&local_world.v2.x = &local_world.v1.z;
    HIBYTE(local_world.v3.x) = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[SLOWORD(local_world.v3.x)].mNode.mNext == &StateArgs->mStateArgs[SLOWORD(local_world.v3.x)] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(local_world.v3.x) >> 6] &= ~(1i64 << (LOBYTE(local_world.v3.x) & 0x3F));
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
void __fastcall DrawShadowedSpotLights(
        UFG::RenderContext *render_context,
        Render::View *view,
        const unsigned int *indices,
        unsigned int count)
{
  __int64 v7; // r12
  Illusion::Material *mLightMaterial; // rbx
  Render::LightInstance *v9; // rdi
  Render::Light *v10; // rsi
  unsigned int v11; // r8d
  Render::LightInstance *v12; // r9
  Render::Light *v13; // r8
  Render::LightInstance *v14; // r9
  Render::Light *v15; // r8
  __int64 mOffset; // rax
  _WORD *v17; // rax
  UFG::qColour colour; // [rsp+50h] [rbp-68h] BYREF
  UFG::qColour v19; // [rsp+60h] [rbp-58h] BYREF

  if ( count )
  {
    v7 = count;
    while ( 1 )
    {
      mLightMaterial = render_context->mLightMaterial;
      v9 = &gCulledLights[*indices];
      v10 = gLights[v9->lightIndex];
      if ( *indices < gNumNearLights )
      {
        if ( gClearStencil )
        {
          *(_QWORD *)&colour.r = 0i64;
          *(_QWORD *)&colour.b = 0i64;
          Render::View::Clear(view, &colour, 4u, 1.0, 0);
          if ( v10->mType == 5 )
            DrawAreaLight(render_context, view, v10, v9);
          else
            DrawSpotLight(render_context, view, v10, v9);
          if ( *(_DWORD *)&mLightMaterial[3].mDebugName[12] == -1835606658 )
            goto LABEL_33;
          v11 = -1835606658;
        }
        else
        {
          v12 = &gCulledLights[*indices];
          v13 = gLights[v9->lightIndex];
          if ( v10->mType == 5 )
            DrawAreaLight(render_context, view, v13, v12);
          else
            DrawSpotLight(render_context, view, v13, v12);
          if ( *(_DWORD *)&mLightMaterial[3].mDebugName[12] == 1537965747 )
            goto LABEL_33;
          v11 = 1537965747;
        }
        goto LABEL_29;
      }
      if ( *indices < gNumStencilLights + gNumNearLights )
        break;
      if ( *(_DWORD *)&mLightMaterial[3].mDebugName[12] != -262489691 )
      {
        v11 = -262489691;
LABEL_29:
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&mLightMaterial[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
          *(_DWORD *)&mLightMaterial[3].mDebugName[20],
          v11);
        mOffset = mLightMaterial->mMaterialUser.mOffset;
        if ( mOffset )
          v17 = (_WORD *)((char *)&mLightMaterial->mMaterialUser + mOffset);
        else
          v17 = 0i64;
        *v17 |= 0x20u;
      }
LABEL_33:
      UpdateLightMaterial(mLightMaterial, v10, v9);
      if ( v10->mType == 5 )
        DrawAreaLight(render_context, view, v10, v9);
      else
        DrawSpotLight(render_context, view, v10, v9);
      ++indices;
      if ( !--v7 )
        return;
    }
    if ( gClearStencil )
    {
      *(_QWORD *)&v19.r = 0i64;
      *(_QWORD *)&v19.b = 0i64;
      Render::View::Clear(view, &v19, 4u, 1.0, 0);
      if ( v10->mType == 5 )
        DrawAreaLight(render_context, view, v10, v9);
      else
        DrawSpotLight(render_context, view, v10, v9);
      if ( *(_DWORD *)&mLightMaterial[3].mDebugName[12] == -929296280 )
        goto LABEL_33;
      v11 = -929296280;
    }
    else
    {
      v14 = &gCulledLights[*indices];
      v15 = gLights[v9->lightIndex];
      if ( v10->mType == 5 )
        DrawAreaLight(render_context, view, v15, v14);
      else
        DrawSpotLight(render_context, view, v15, v14);
      if ( *(_DWORD *)&mLightMaterial[3].mDebugName[12] == 1063454199 )
        goto LABEL_33;
      v11 = 1063454199;
    }
    goto LABEL_29;
  }
}

// File Line: 1706
// RVA: 0x1456120
__int64 dynamic_initializer_for__gLightRenderLayer__()
{
  RenderQueueLayer::RenderQueueLayer(&gLightRenderLayer);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gLightRenderLayer__);
}

// File Line: 1707
// RVA: 0x1456140
__int64 dynamic_initializer_for__gListRenderLayerSerializationList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gListRenderLayerSerializationList__);
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
  float mNumSpotShadowsAllowed; // xmm0_4
  unsigned int v4; // r8d
  Render::LightInstance *v5; // r9
  Render::Light **v6; // r14
  unsigned __int64 v7; // r11
  __int64 mCullIndex; // rbx
  Render::Light *v9; // r10
  char mType; // al
  __int64 v11; // rax

  if ( render_context->mRenderFeatures.mLights && render_context->mRenderFeatures.mWorld )
  {
    v1 = 0;
    gSpotShadowCount = 0;
    v2 = gNumNearLights + gNumStencilLights + gNumFarLights;
    if ( v2 )
    {
      mNumSpotShadowsAllowed = (float)render_context->mNumSpotShadowsAllowed;
      if ( mNumSpotShadowsAllowed >= 16.0 )
        mNumSpotShadowsAllowed = FLOAT_16_0;
      v4 = 0;
      if ( v2 )
      {
        v5 = gCulledLights;
        v6 = gLights;
        v7 = 0i64;
        do
        {
          mCullIndex = render_context->mMainViewSettings.mCullIndex;
          v9 = v6[v5->lightIndex];
          if ( (int)mCullIndex < 0
            || gCulledLightsResults[v7 >> 8][(unsigned __int64)(unsigned __int8)v7].mViewResult[mCullIndex] <= 1u )
          {
            mType = v9->mType;
            if ( (mType == 1 || (unsigned __int8)(mType - 4) <= 1u)
              && (v5->flags & 2) != 0
              && v1 < (int)mNumSpotShadowsAllowed )
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

// File Line: 1769
// RVA: 0x5B190
void __fastcall SubmitDrawLightingTask(UFG::RenderContext *render_context)
{
  unsigned int v2; // r14d
  unsigned int v3; // eax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  char *v8; // rdi
  char *v9; // rax
  UFG::qTask *v10; // rdx
  char *v11; // rsi
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *mPrev; // rax
  char *v19; // rax
  char *v20; // r15
  char *v21; // rax
  unsigned int v22; // edx
  float mNumSpotShadowsAllowed; // xmm0_4
  unsigned int v24; // r11d
  unsigned int v25; // ebp
  __int64 v26; // rbx
  _QWORD *v27; // r8
  unsigned int v28; // edi
  Render::LightInstance *v29; // r12
  Render::Light *v30; // r14
  __int64 v31; // r10
  __int64 mCullIndex; // r9
  CullResults *v33; // rcx
  bool v34; // r15
  bool v35; // zf
  char mType; // al
  unsigned int mTextureUID; // r9d
  __int64 mTexDistAttenUID; // rdx
  UFG::qVector4 v39; // xmm2
  UFG::qVector4 v40; // xmm1
  UFG::qVector4 v41; // xmm0
  UFG::qVector4 v42; // xmm2
  UFG::qVector4 v43; // xmm1
  UFG::qVector4 v44; // xmm0
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  float *p_mFOVOffset; // rax
  float v47; // xmm1_4
  float v48; // xmm0_4
  UFG::BaseCameraComponent *v49; // rax
  float *v50; // rax
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm0_4
  __int64 v54; // rdx
  __int64 v55; // rdx
  UFG::qResourceInventory *v56; // rcx
  UFG::qResourceInventoryVtbl *vfptr; // rax
  __int64 v58; // rdx
  __int64 v59; // rdx
  __int64 v60; // rdx
  unsigned int v61; // eax
  __int64 v62; // rdx
  UFG::qResourceInventoryVtbl *v63; // rax
  UFG::qResourceData *v64; // rax
  __int64 v65; // rdx
  UFG::qResourceInventory *v66; // rcx
  UFG::qBaseNodeRB *v67; // rcx
  _QWORD *v68; // rax
  char *v69; // rdx
  UFG::qBaseNodeRB *v70; // rcx
  _QWORD *v71; // rax
  signed __int64 v72; // [rsp+20h] [rbp-88h]
  char *v73; // [rsp+28h] [rbp-80h]
  char *v74; // [rsp+30h] [rbp-78h]
  char *v75; // [rsp+38h] [rbp-70h]
  __int64 v76; // [rsp+B0h] [rbp+8h]
  char *v77; // [rsp+B8h] [rbp+10h]

  if ( render_context->mRenderFeatures.mLights && render_context->mRenderFeatures.mWorld )
  {
    v2 = gNumNearLights + gNumStencilLights + gNumFarLights;
    LODWORD(v76) = v2;
    if ( !v2 )
    {
      gSpotShadowCount = 0;
      render_context->mLightingSubmitTask = 0i64;
      render_context->mLightingSubmitTaskParams = 0i64;
      return;
    }
    v3 = _S7_0;
    if ( (_S7_0 & 1) == 0 )
    {
      _S7_0 |= 1u;
      v4 = UFG::qResourceWarehouse::Instance();
      texInventory_1 = UFG::qResourceWarehouse::GetInventory(v4, 0x8B43FABF);
      v3 = _S7_0;
    }
    if ( (v3 & 2) == 0 )
    {
      _S7_0 = v3 | 2;
      v5 = UFG::qResourceWarehouse::Instance();
      shaderInventory = UFG::qResourceWarehouse::GetInventory(v5, 0x8B5561A1);
      v3 = _S7_0;
    }
    if ( (v3 & 4) == 0 )
    {
      _S7_0 = v3 | 4;
      v6 = UFG::qResourceWarehouse::Instance();
      alphaInventory = UFG::qResourceWarehouse::GetInventory(v6, 0x12C800F2u);
      v3 = _S7_0;
    }
    if ( (v3 & 8) == 0 )
    {
      _S7_0 = v3 | 8;
      v7 = UFG::qResourceWarehouse::Instance();
      rasterInventory = UFG::qResourceWarehouse::GetInventory(v7, 0x3BC715E0u);
    }
    v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x1C8u, 0x10u);
    v73 = v8;
    v9 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v10 = (UFG::qTask *)v9;
    v11 = 0i64;
    if ( v9 )
    {
      *(_QWORD *)v9 = v9;
      *((_QWORD *)v9 + 1) = v9;
      *((_QWORD *)v9 + 2) = v9 + 16;
      *((_QWORD *)v9 + 3) = v9 + 16;
      mSpuElf = gTaskFunctionDeclData_SubmitLightingTask.mSpuElf;
      mTaskFunctionSPU = gTaskFunctionDeclData_SubmitLightingTask.mTaskFunctionSPU;
      mTaskFunctionPPU = gTaskFunctionDeclData_SubmitLightingTask.mTaskFunctionPPU;
      mTaskFunctionOffload = gTaskFunctionDeclData_SubmitLightingTask.mTaskFunctionOffload;
      if ( !gTaskFunctionDeclData_SubmitLightingTask.mCurrentSPUEnabled )
      {
        mSpuElf = 0i64;
        mTaskFunctionSPU = 0i64;
        mTaskFunctionOffload = 0i64;
      }
      v10->mTaskGroup = 0i64;
      v10->mFlags = 2;
      v10->mSyncVars.i64 = 0i64;
      v10->mSyncVars.v.mDependents = 0i64;
      v10->mFunctionDeclData = &gTaskFunctionDeclData_SubmitLightingTask;
      if ( mSpuElf )
        mAddress = mSpuElf->mAddress;
      else
        mAddress = 0i64;
      v10->mSPUElfAddress = mAddress;
      v10->mSPUFunction = mTaskFunctionSPU;
      v10->mPPUFunction = mTaskFunctionPPU;
      v10->mParam0 = v8;
      v10->mParam1 = 0i64;
      v10->mParam2 = 0i64;
      v10->mParam3 = 0i64;
      if ( mTaskFunctionOffload )
      {
        v10->mFlags = 130;
        v10->mOffloadThread = 0;
      }
    }
    mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
    mPrev = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
    mPrev->mNext = v10;
    v10->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = mPrev;
    v10->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
    mSingleFrameTasks->mNode.mPrev = v10;
    render_context->mLightingSubmitTask = v10;
    render_context->mLightingSubmitTaskParams = (LightingSubmitTaskParams *)v8;
    v19 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x20u);
    if ( v19 )
    {
      *(_QWORD *)v19 = v19;
      *((_QWORD *)v19 + 1) = v19;
    }
    else
    {
      v19 = 0i64;
    }
    *((_QWORD *)v8 + 19) = v19;
    v20 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 8 * v2, 0x10u);
    v74 = v20;
    v21 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 8 * v2, 0x10u);
    v75 = v21;
    v22 = 0;
    gSpotShadowCount = 0;
    mNumSpotShadowsAllowed = (float)render_context->mNumSpotShadowsAllowed;
    if ( mNumSpotShadowsAllowed >= 16.0 )
      mNumSpotShadowsAllowed = FLOAT_16_0;
    v24 = (int)mNumSpotShadowsAllowed;
    v25 = 0;
    if ( v2 )
    {
      v26 = 0i64;
      v27 = v21;
      v77 = v21;
      v72 = v20 - v21;
      v28 = v2;
      while ( 1 )
      {
        v29 = gCulledLights;
        v30 = gLights[gCulledLights[v26].lightIndex];
        v76 = 0i64;
        v31 = 0i64;
        mCullIndex = render_context->mMainViewSettings.mCullIndex;
        if ( (int)mCullIndex < 0 )
        {
          v34 = 0;
        }
        else
        {
          v33 = &gCulledLightsResults[v25 >> 8][(unsigned __int64)(unsigned __int8)v25];
          v34 = v33->mViewResult[mCullIndex] > 1u;
          v35 = v33->mViewResult[mCullIndex] <= 1u;
          if ( v33->mViewResult[mCullIndex] > 1u )
            goto LABEL_43;
        }
        mType = v30->mType;
        if ( mType == 1 || (unsigned __int8)(mType - 4) <= 1u )
        {
          mTextureUID = v30->mTextureUID;
          if ( mTextureUID != -1 )
          {
            v76 = ((__int64 (__fastcall *)(UFG::qResourceInventory *, _QWORD, _QWORD *))texInventory_1->vfptr->Get)(
                    texInventory_1,
                    mTextureUID,
                    v27);
            v22 = gSpotShadowCount;
            v27 = v77;
            v31 = 0i64;
            v24 = (int)mNumSpotShadowsAllowed;
          }
          if ( (v29[v26].flags & 2) != 0 && v22 < v24 && v30->mShadowFlags )
          {
            v34 = 1;
            gSpotShadowIndices[v22] = v25;
            gSpotShadowCount = v22 + 1;
          }
        }
        mTexDistAttenUID = v30->mTexDistAttenUID;
        if ( (_DWORD)mTexDistAttenUID != -1 )
        {
          v31 = ((__int64 (__fastcall *)(UFG::qResourceInventory *, __int64, _QWORD *))texInventory_1->vfptr->Get)(
                  texInventory_1,
                  mTexDistAttenUID,
                  v27);
          v27 = v77;
        }
        v35 = !v34;
LABEL_43:
        v29[v26].flags |= !v35;
        *(_QWORD *)((char *)v27 + v72) = v76;
        *v27 = v31;
        ++v25;
        ++v26;
        v77 = (char *)++v27;
        if ( v25 >= v28 )
        {
          v8 = v73;
          v20 = v74;
          break;
        }
        v22 = gSpotShadowCount;
        v24 = (int)mNumSpotShadowsAllowed;
      }
    }
    gLightRenderLayer.mSerializationList = &gListRenderLayerSerializationList;
    *((_QWORD *)v8 + 16) = Illusion::gEngine.FrameMemory;
    v39 = render_context->mMainViewSettings.mWorldView.v1;
    v40 = render_context->mMainViewSettings.mWorldView.v2;
    v41 = render_context->mMainViewSettings.mWorldView.v3;
    *(UFG::qVector4 *)v8 = render_context->mMainViewSettings.mWorldView.v0;
    *((UFG::qVector4 *)v8 + 1) = v39;
    *((UFG::qVector4 *)v8 + 2) = v40;
    *((UFG::qVector4 *)v8 + 3) = v41;
    v42 = render_context->mMainViewSettings.mProjection.v1;
    v43 = render_context->mMainViewSettings.mProjection.v2;
    v44 = render_context->mMainViewSettings.mProjection.v3;
    *((_OWORD *)v8 + 4) = render_context->mMainViewSettings.mProjection.v0;
    *((UFG::qVector4 *)v8 + 5) = v42;
    *((UFG::qVector4 *)v8 + 6) = v43;
    *((UFG::qVector4 *)v8 + 7) = v44;
    *((_QWORD *)v8 + 17) = Render::GetViewStateBlockParams();
    *((_QWORD *)v8 + 18) = GetLightSubmitParamIndices();
    *((_QWORD *)v8 + 20) = &gLightRenderLayer;
    *((_QWORD *)v8 + 21) = gLights;
    *((_QWORD *)v8 + 22) = gCulledLights;
    *((_QWORD *)v8 + 23) = v20;
    *((_QWORD *)v8 + 24) = v75;
    *((_DWORD *)v8 + 50) = gNumNearLights;
    *((_DWORD *)v8 + 51) = gNumFarLights;
    *((_DWORD *)v8 + 52) = gNumStencilLights;
    *((_DWORD *)v8 + 53) = 16843008;
    v8[216] = gClearStencil != 0;
    v8[217] = gEnableZBounds != 0;
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      p_mFOVOffset = &mCurrentCamera->mCamera.mFOVOffset;
    else
      p_mFOVOffset = 0i64;
    v47 = p_mFOVOffset[58];
    if ( v47 == 0.0 || v47 == p_mFOVOffset[59] )
      v48 = *(float *)&v76;
    else
      v48 = p_mFOVOffset[62] / v47;
    *((float *)v8 + 55) = v48;
    v49 = UFG::Director::Get()->mCurrentCamera;
    if ( v49 )
      v50 = &v49->mCamera.mFOVOffset;
    else
      v50 = 0i64;
    v51 = v50[58];
    v52 = v50[59];
    if ( v51 == 0.0 || v51 == v52 )
      v53 = *(float *)&v76;
    else
      v53 = (float)(v50[62] - v50[63]) / (float)(v51 - v52);
    *((float *)v8 + 56) = v53;
    *((_DWORD *)v8 + 57) = LODWORD(UFG::TimeOfDayManager::GetInstance()->mExposure);
    if ( render_context->mRenderSettingsForFrame.mSSAO == SSAO_HIGH
      && render_context->mLightBufferTarget->mTargetTexture[1] )
    {
      *((_QWORD *)v8 + 29) = shaderInventory->vfptr->Get(shaderInventory, 3279282853i64);
      *((_QWORD *)v8 + 30) = shaderInventory->vfptr->Get(shaderInventory, 612326710i64);
      v54 = 3279282853i64;
      if ( !gNoSpecLights )
        v54 = 2129313954i64;
      *((_QWORD *)v8 + 31) = shaderInventory->vfptr->Get(shaderInventory, v54);
      *((_QWORD *)v8 + 32) = shaderInventory->vfptr->Get(shaderInventory, 2030768325i64);
      v55 = 2030768325i64;
      if ( !gNoSpecLights )
        v55 = 634163517i64;
      *((_QWORD *)v8 + 33) = shaderInventory->vfptr->Get(shaderInventory, v55);
      *((_QWORD *)v8 + 34) = shaderInventory->vfptr->Get(shaderInventory, 4148067080i64);
      v56 = shaderInventory;
      vfptr = shaderInventory->vfptr;
      if ( gNoSpecLights )
        v58 = 4148067080i64;
      else
        v58 = 1863009884i64;
    }
    else
    {
      *((_QWORD *)v8 + 29) = shaderInventory->vfptr->Get(shaderInventory, 1753793710i64);
      *((_QWORD *)v8 + 30) = shaderInventory->vfptr->Get(shaderInventory, 246770660i64);
      v59 = 1753793710i64;
      if ( !gNoSpecLights )
        v59 = 2846045904i64;
      *((_QWORD *)v8 + 31) = shaderInventory->vfptr->Get(shaderInventory, v59);
      *((_QWORD *)v8 + 32) = shaderInventory->vfptr->Get(shaderInventory, 185628407i64);
      v60 = 185628407i64;
      if ( !gNoSpecLights )
        v60 = 1172639096i64;
      *((_QWORD *)v8 + 33) = shaderInventory->vfptr->Get(shaderInventory, v60);
      *((_QWORD *)v8 + 34) = shaderInventory->vfptr->Get(shaderInventory, 2847309945i64);
      v56 = shaderInventory;
      vfptr = shaderInventory->vfptr;
      v58 = 2847309945i64;
      if ( !gNoSpecLights )
        v58 = 621576348i64;
    }
    *((_QWORD *)v8 + 35) = vfptr->Get(v56, v58);
    *((_QWORD *)v8 + 36) = shaderInventory->vfptr->Get(shaderInventory, 2683637110i64);
    *((_QWORD *)v8 + 37) = shaderInventory->vfptr->Get(shaderInventory, 2233527130i64);
    if ( (_S7_0 & 0x10) != 0 )
    {
      v62 = uidFLAT;
    }
    else
    {
      _S7_0 |= 0x10u;
      v61 = UFG::qStringHash32("FLAT", 0xFFFFFFFF);
      v62 = v61;
      uidFLAT = v61;
    }
    *((_QWORD *)v8 + 38) = shaderInventory->vfptr->Get(shaderInventory, v62);
    *((_QWORD *)v8 + 39) = texInventory_1->vfptr->Get(texInventory_1, 2970839531i64);
    *((_QWORD *)v8 + 40) = *((_QWORD *)&render_context->mLightMaterial[1].UFG::qResourceData + 11);
    *((_QWORD *)v8 + 41) = render_context->mGBufferTarget->mTargetTexture[1];
    *((_QWORD *)v8 + 42) = render_context->mGBufferTarget->mTargetTexture[3];
    *((_QWORD *)v8 + 43) = render_context->mGBufferTarget->mDepthTextureCopy;
    *((_QWORD *)v8 + 44) = alphaInventory->vfptr->Get(alphaInventory, 3262501945i64);
    *((_QWORD *)v8 + 45) = alphaInventory->vfptr->Get(alphaInventory, 2443369811i64);
    *((_QWORD *)v8 + 46) = rasterInventory->vfptr->Get(rasterInventory, 4032477605i64);
    *((_QWORD *)v8 + 47) = rasterInventory->vfptr->Get(rasterInventory, 3471962073i64);
    v63 = rasterInventory->vfptr;
    if ( gClearStencil )
    {
      *((_QWORD *)v8 + 48) = v63->Get(rasterInventory, 1664809175u);
      *((_QWORD *)v8 + 49) = rasterInventory->vfptr->Get(rasterInventory, 3365671016i64);
      v64 = rasterInventory->vfptr->Get(rasterInventory, 3994746641i64);
      v65 = 2459360638i64;
    }
    else
    {
      *((_QWORD *)v8 + 48) = v63->Get(rasterInventory, 4170151191u);
      *((_QWORD *)v8 + 49) = rasterInventory->vfptr->Get(rasterInventory, 1063454199i64);
      v64 = rasterInventory->vfptr->Get(rasterInventory, 4095106607i64);
      v65 = 1537965747i64;
    }
    v66 = rasterInventory;
    *((_QWORD *)v8 + 50) = v64;
    *((_QWORD *)v8 + 51) = v66->vfptr->Get(v66, v65);
    v67 = gDeferredSphere.mData[2].mNode.mChild[0];
    if ( v67 )
      v68 = (UFG::qBaseNodeRB **)((char *)&v67->mParent + (unsigned __int64)gDeferredSphere.mData[2].mNode.mChild);
    else
      v68 = 0i64;
    v69 = (char *)v68 + *v68;
    if ( !*v68 )
      v69 = 0i64;
    *((_QWORD *)v8 + 52) = v69;
    v70 = gDeferredCone.mData[2].mNode.mChild[0];
    if ( v70 )
      v71 = (UFG::qBaseNodeRB **)((char *)&v70->mParent + (unsigned __int64)gDeferredCone.mData[2].mNode.mChild);
    else
      v71 = 0i64;
    if ( *v71 )
      v11 = (char *)v71 + *v71;
    *((_QWORD *)v8 + 53) = v11;
    *((_QWORD *)v8 + 54) = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    *((_QWORD *)v8 + 55) = gLightGroups;
    UFG::qTaskManager::Queue(&UFG::gTaskManager, render_context->mLightingSubmitTask);
  }
}

// File Line: 1968
// RVA: 0x5CD40
void __fastcall SyncFlushDrawLightingTask(UFG::RenderContext *render_context, Render::View *view)
{
  UFG::qTask *mLightingSubmitTask; // rdx
  RenderQueueLayer *v5; // rsi
  Illusion::RenderQueue *mNext; // rbx
  int v7; // ecx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v8; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *mSerializationList; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v11; // rcx
  LightingSubmitTaskResults *mMainMemLightingSubmitTaskResults; // rcx

  if ( render_context->mRenderFeatures.mLights )
  {
    if ( gNumLightCards )
    {
      FlushLightCards(
        render_context,
        view,
        &gCulledLights[gNumNearLights + gNumFarLights + gNumStencilLights],
        gNumLightCards);
      render_context->mRenderStats.mNumLightCards += gNumLightCards;
    }
    mLightingSubmitTask = render_context->mLightingSubmitTask;
    render_context->mRenderStats.mNumLightsNearTotal += gNumNearLights;
    render_context->mRenderStats.mNumLightsStencilTotal += gNumStencilLights;
    render_context->mRenderStats.mNumLightsFarTotal += gNumFarLights;
    if ( mLightingSubmitTask )
    {
      UFG::qTaskManager::Sync(&UFG::gTaskManager, mLightingSubmitTask);
      v5 = (RenderQueueLayer *)view->mSubmitContext[1].mStateValues.mParamValues[0];
      RenderQueueLayer::SerializeRenderQueues(v5);
      RenderQueueLayer::SerializeRenderQueues(&gLightRenderLayer);
      mNext = (Illusion::RenderQueue *)gListRenderLayerSerializationList.mNode.mNext;
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
              Illusion::RenderQueueSystem::Print(mNext);
              mNext = (Illusion::RenderQueue *)mNext->mNext;
            }
            while ( mNext != (Illusion::RenderQueue *)&gListRenderLayerSerializationList );
            mNext = (Illusion::RenderQueue *)gListRenderLayerSerializationList.mNode.mNext;
          }
        }
      }
      mSerializationList = v5->mSerializationList;
      if ( mNext != (Illusion::RenderQueue *)&gListRenderLayerSerializationList )
      {
        mPrev = mSerializationList->mNode.mPrev;
        v11 = gListRenderLayerSerializationList.mNode.mPrev;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v11->mNext = &mSerializationList->mNode;
        mSerializationList->mNode.mPrev = v11;
        gListRenderLayerSerializationList.mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&gListRenderLayerSerializationList;
        gListRenderLayerSerializationList.mNode.mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&gListRenderLayerSerializationList;
      }
      gLightRenderLayer.mSerializationList = 0i64;
      mMainMemLightingSubmitTaskResults = render_context->mLightingSubmitTaskParams->mMainMemLightingSubmitTaskResults;
      render_context->mRenderStats.mNumLightsNearRendered += mMainMemLightingSubmitTaskResults->numNearLightsRendered;
      render_context->mRenderStats.mNumLightsStencilRendered += mMainMemLightingSubmitTaskResults->numStencilLightsRendered;
      render_context->mRenderStats.mNumLightsFarRendered += mMainMemLightingSubmitTaskResults->numFarLightsRendered;
    }
  }
}

