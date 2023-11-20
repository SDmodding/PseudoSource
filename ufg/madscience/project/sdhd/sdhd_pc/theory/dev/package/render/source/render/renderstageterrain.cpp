// File Line: 65
// RVA: 0x304A0
void __fastcall UFG::RenderStageTerrain::Create(UFG::RenderContext *render_context)
{
  UFG::RenderContext *v1; // rbx
  char *v2; // rax

  v1 = render_context;
  v2 = UFG::qMalloc(0x223C8ui64, "RenderStageTerrain", 0i64);
  if ( v2 )
    UFG::RenderStageTerrain::RenderStageTerrain((UFG::RenderStageTerrain *)v2, v1);
}

// File Line: 74
// RVA: 0x30490
void __fastcall UFG::AddTerrainDataCallback(Render::TerrainData *pData)
{
  UFG::RenderStageTerrain::AddTerrainData(UFG::RenderWorld::msStageTerrain, pData);
}

// File Line: 79
// RVA: 0x310D0
void __fastcall UFG::RemoveTerrainDataCallback(Render::TerrainData *pData)
{
  UFG::RenderStageTerrain::RemoveTerrainData(UFG::RenderWorld::msStageTerrain, pData);
}

// File Line: 92
// RVA: 0x2ED60
void __fastcall UFG::RenderStageTerrain::RenderStageTerrain(UFG::RenderStageTerrain *this, UFG::RenderContext *render_context)
{
  UFG::RenderStageTerrain *v2; // r14
  UFG::qFixedArray<UFG::TerrainQuadTreeNode,512> *v3; // rbx
  UFG::TerrainQuadTreeNode **v4; // rcx
  unsigned int v5; // eax
  int v6; // edi
  Illusion::Material *v7; // rbx
  Illusion::Material *v8; // rbx
  Illusion::Material *v9; // rbx
  Illusion::Material *v10; // rbx
  Illusion::Material *v11; // rbx
  Illusion::Material *v12; // rbx
  Illusion::Material *v13; // rbx
  Illusion::Material *v14; // rbx
  Illusion::Material *v15; // rbx
  Illusion::Material *v16; // rbx
  Illusion::Material *v17; // rbx
  Illusion::Material *v18; // rbx
  UFG::qResourceWarehouse *v19; // rax
  unsigned int v20; // eax
  int v21; // edi
  Illusion::Material *v22; // rbx
  Illusion::Material *v23; // rbx
  Illusion::Material *v24; // rbx
  Illusion::Material *v25; // rbx
  Illusion::Material *v26; // rbx
  Illusion::Material *v27; // rbx
  Illusion::Material *v28; // rbx
  Illusion::Material *v29; // rbx
  Illusion::Material *v30; // rbx
  Illusion::Material *v31; // rbx
  Illusion::Material *v32; // rbx
  Illusion::Material *v33; // rbx
  UFG::qResourceWarehouse *v34; // rax
  unsigned int v35; // er15
  signed __int64 v36; // rax
  unsigned int v37; // edi
  unsigned int v38; // esi
  unsigned int *v39; // r14
  __int64 v40; // rbx
  int v41; // edx
  unsigned int v42; // eax
  UFG::qResourceData *v43; // rax
  UFG::qBaseNodeRB *v44; // rcx
  _QWORD *v45; // rax
  __int64 v46; // rdx
  int v47; // edx
  unsigned int v48; // eax
  UFG::qResourceData *v49; // rax
  UFG::qBaseNodeRB *v50; // rcx
  _QWORD *v51; // rax
  __int64 v52; // rdx
  int v53; // edx
  unsigned int v54; // er13
  Illusion::Buffer *v55; // rax
  UFG::qResourceData *v56; // rbx
  __int64 v57; // rax
  signed __int64 v58; // r8
  unsigned int v59; // edx
  signed int v60; // er9
  int v61; // er12
  signed int v62; // ecx
  float v63; // xmm1_4
  signed __int64 v64; // rax
  UFG::qResourceWarehouse *v65; // rax
  unsigned int v66; // esi
  __int64 v67; // r14
  __int64 v68; // rbx
  int v69; // eax
  __int64 v70; // rbx
  int v71; // eax
  unsigned int v72; // er14
  unsigned int v73; // er12
  int v74; // eax
  int v75; // esi
  unsigned int v76; // er13
  __int64 *v77; // rbx
  unsigned int v78; // er15
  int v79; // edx
  unsigned int v80; // eax
  Illusion::Buffer *v81; // rax
  __int64 v82; // rcx
  signed __int64 v83; // r10
  __int64 v84; // r9
  unsigned int v85; // er13
  unsigned int v86; // ecx
  __int16 v87; // ax
  __int16 v88; // di
  __int16 v89; // si
  __int16 v90; // r15
  __int16 v91; // bx
  int v92; // er11
  __int64 v93; // r14
  __int64 v94; // r9
  __int64 v95; // r9
  __int64 v96; // r9
  __int64 v97; // r9
  __int64 v98; // r9
  __int64 v99; // r9
  __int64 v100; // r9
  __int64 v101; // r9
  __int64 v102; // r9
  __int64 v103; // r9
  __int64 v104; // r9
  UFG::qResourceWarehouse *v105; // rax
  unsigned int v106; // eax
  unsigned int v107; // er12
  Illusion::Buffer *v108; // rax
  __int64 v109; // rcx
  signed __int64 v110; // r11
  __int64 v111; // r9
  unsigned int v112; // er13
  unsigned int v113; // er10
  __int16 v114; // bx
  __int16 v115; // r15
  __int16 v116; // si
  __int16 v117; // r14
  __int64 v118; // r9
  __int64 v119; // r9
  __int64 v120; // r9
  __int64 v121; // r9
  __int64 v122; // r9
  __int64 v123; // r9
  __int64 v124; // r9
  __int64 v125; // r9
  __int64 v126; // r9
  __int64 v127; // r9
  __int64 v128; // r9
  UFG::qResourceWarehouse *v129; // rax
  unsigned int v130; // ebx
  __int64 *v131; // rsi
  __int64 v132; // r13
  unsigned int *v133; // r14
  signed __int64 v134; // rdi
  UFG::qResourceWarehouse *v135; // rax
  unsigned int v136; // er15
  UFG::qResourceInventory *v137; // rax
  UFG::qResourceWarehouse *v138; // rax
  unsigned int v139; // er13
  int v140; // er15
  int v141; // eax
  int v142; // esi
  unsigned int v143; // er14
  char *v144; // rbx
  __int16 v145; // di
  int v146; // edx
  unsigned int v147; // eax
  Illusion::Buffer *v148; // rax
  __int64 v149; // rcx
  signed __int64 v150; // r10
  __int64 v151; // r9
  unsigned int v152; // er14
  unsigned int v153; // ecx
  __int16 v154; // si
  __int16 v155; // bx
  int v156; // er11
  __int64 v157; // rdi
  __int64 v158; // r9
  __int64 v159; // r9
  __int64 v160; // r9
  __int64 v161; // r9
  __int64 v162; // r9
  UFG::qResourceWarehouse *v163; // rax
  unsigned int v164; // eax
  unsigned int v165; // er12
  unsigned int v166; // ebx
  Illusion::Buffer *v167; // rax
  __int64 v168; // rcx
  signed __int64 v169; // r11
  __int64 v170; // r9
  unsigned int i; // er13
  unsigned int v172; // er10
  __int16 v173; // si
  __int16 v174; // di
  __int16 v175; // r15
  __int64 v176; // r9
  __int64 v177; // r9
  __int64 v178; // r9
  __int64 v179; // r9
  __int64 v180; // r9
  UFG::qResourceWarehouse *v181; // rax
  unsigned int v182; // ebx
  __int64 *v183; // rdi
  unsigned int *v184; // r12
  UFG::qResourceWarehouse *v185; // rax
  unsigned int v186; // esi
  UFG::qResourceInventory *v187; // rax
  UFG::qResourceWarehouse *v188; // rax
  unsigned int v189; // [rsp+40h] [rbp-88h]
  unsigned int v190; // [rsp+44h] [rbp-84h]
  UFG::qResourceData *data; // [rsp+48h] [rbp-80h]
  UFG::qResourceData *dataa; // [rsp+48h] [rbp-80h]
  int v193; // [rsp+50h] [rbp-78h]
  unsigned int v194; // [rsp+50h] [rbp-78h]
  signed __int64 v195; // [rsp+50h] [rbp-78h]
  UFG::qString v196; // [rsp+58h] [rbp-70h]
  UFG::qString v197; // [rsp+80h] [rbp-48h]
  UFG::qString v198; // [rsp+A8h] [rbp-20h]
  UFG::qString v199; // [rsp+D0h] [rbp+8h]
  UFG::qString v200; // [rsp+F8h] [rbp+30h]
  UFG::qString result; // [rsp+120h] [rbp+58h]
  UFG::qString v202; // [rsp+148h] [rbp+80h]
  __int64 v203; // [rsp+170h] [rbp+A8h]
  __int64 v204[4]; // [rsp+178h] [rbp+B0h]
  __int64 v205; // [rsp+198h] [rbp+D0h]
  __int64 v206[4]; // [rsp+1A0h] [rbp+D8h]
  __int64 v207; // [rsp+1C0h] [rbp+F8h]
  __int64 v208[5]; // [rsp+1C8h] [rbp+100h]
  __int64 v209[12]; // [rsp+1F0h] [rbp+128h]
  UFG::RenderStageTerrain *v210; // [rsp+268h] [rbp+1A0h]
  UFG::qFixedArray<UFG::TerrainQuadTreeNode,512> *v211; // [rsp+278h] [rbp+1B0h]
  UFG::qResourceData *v212; // [rsp+280h] [rbp+1B8h]

  v203 = -2i64;
  v2 = this;
  `eh vector constructor iterator'(
    this->mTerrainModelHandles,
    0x20ui64,
    10,
    (void (__fastcall *)(void *))Illusion::ModelHandle::ModelHandle);
  `eh vector constructor iterator'(
    v2->mDX10TerrainModelHandles,
    0x20ui64,
    10,
    (void (__fastcall *)(void *))Illusion::ModelHandle::ModelHandle);
  v3 = &v2->mTerrainQuadTreeNodes;
  v211 = &v2->mTerrainQuadTreeNodes;
  `eh vector constructor iterator'(
    v2->mTerrainQuadTreeNodes.p,
    0x110ui64,
    512,
    (void (__fastcall *)(void *))UFG::TerrainQuadTreeNode::TerrainQuadTreeNode);
  v3->size = 0;
  v2->mTerrainRenderNodes.p = 0i64;
  *(_QWORD *)&v2->mTerrainRenderNodes.size = 0i64;
  v2->mActiveTerrainNodes.p = 0i64;
  *(_QWORD *)&v2->mActiveTerrainNodes.size = 0i64;
  v2->mLODRanges.p = 0i64;
  *(_QWORD *)&v2->mLODRanges.size = 0i64;
  v2->mAddTerrainDataPhysicsCallback = 0i64;
  v2->mRemoveTerrainDataPhysicsCallback = 0i64;
  v2->mRenderTerrain = 0;
  UFG::qMemSet(&v2->mTerrainParams, 0, 0x88u);
  Render::gTerrainDataInventory.mAddTerrainDataCallback = UFG::AddTerrainDataCallback;
  Render::gTerrainDataInventory.mRemoveTerrainDataCallback = UFG::RemoveTerrainDataCallback;
  v2->mNumTerrainQuadTreeNodes = 0;
  v3->size = 0;
  v2->mTerrainDataMap = 0i64;
  v4 = v2->mActiveTerrainNodes.p;
  if ( v4 )
    operator delete[](v4);
  v2->mActiveTerrainNodes.p = 0i64;
  *(_QWORD *)&v2->mActiveTerrainNodes.size = 0i64;
  v5 = UFG::qStringHashUpper32("RenderStageTerrainMaterial", 0xFFFFFFFF);
  v2->mTerrainMaterial = Illusion::Factory::NewMaterial("RenderStageTerrainMaterial", v5, 0xCu, 0i64, 0i64, 0i64);
  v6 = UFG::qStringHashUpper32("DRHEIGHTMAPTERRAIN", 0xFFFFFFFF);
  v7 = v2->mTerrainMaterial;
  LOWORD(v7[1].mNode.mChild[0]) = 0;
  HIDWORD(v7[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v7[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v7[1].mTypeUID = -1957338719;
  LODWORD(v7[1].mResourceHandles.mNode.mNext) = v6;
  v8 = v2->mTerrainMaterial;
  *(_WORD *)&v8[1].mDebugName[12] = 0;
  *(_DWORD *)&v8[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v8[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v8[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v8[1].mStateBlockMask.mFlags[0]) = 662883558;
  v9 = v2->mTerrainMaterial;
  LOWORD(v9[1].mMaterialUser.mOffset) = 0;
  *(&v9[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v9[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v9[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v9[2].mNode.mUID = 543723269;
  v10 = v2->mTerrainMaterial;
  LOWORD(v10[2].mTypeUID) = 0;
  HIDWORD(v10[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v10[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v10[2].0 + 22) = -1958479169;
  *(_DWORD *)&v10[2].mDebugName[28] = 0;
  v11 = v2->mTerrainMaterial;
  LOWORD(v11[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v11[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v11[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v11[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v11[3].mNode.mChild[0]) = 0;
  v12 = v2->mTerrainMaterial;
  LOWORD(v12[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v12[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v12[3].mNode.mUID = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v12[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v12[3].mDebugName[12] = 0;
  v13 = v2->mTerrainMaterial;
  *((_WORD *)&v13[3].0 + 44) = 0;
  *(_DWORD *)&v13[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v13[3].mDebugName[28] = UFG::qStringHash32("texDetailDiffuse0", 0xFFFFFFFF);
  LODWORD(v13[4].mNode.mParent) = -1958479169;
  LODWORD(v13[3].mMaterialUser.mOffset) = 0;
  v14 = v2->mTerrainMaterial;
  LOWORD(v14[4].mNode.mChild[1]) = 0;
  HIDWORD(v14[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v14[4].mNode.mChild[0]) = UFG::qStringHash32("texDetailNormal0", 0xFFFFFFFF);
  *(_DWORD *)&v14[4].mDebugName[4] = -1958479169;
  v14[4].mTypeUID = 0;
  v15 = v2->mTerrainMaterial;
  *(_WORD *)&v15[4].mDebugName[20] = 0;
  *(_DWORD *)&v15[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v15[4].mDebugName[12] = UFG::qStringHash32("texDetailDiffuse1", 0xFFFFFFFF);
  v15[4].mNumParams = -1958479169;
  LODWORD(v15[4].mStateBlockMask.mFlags[1]) = 0;
  v16 = v2->mTerrainMaterial;
  LOWORD(v16[5].mNode.mParent) = 0;
  HIDWORD(v16[4].mMaterialUser.mOffset) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v16[4].mMaterialUser.mOffset) = UFG::qStringHash32("texDetailNormal1", 0xFFFFFFFF);
  LODWORD(v16[5].mResourceHandles.mNode.mNext) = -1958479169;
  LODWORD(v16[5].mResourceHandles.mNode.mPrev) = 0;
  v17 = v2->mTerrainMaterial;
  *(_WORD *)&v17[5].mDebugName[4] = 0;
  *(_DWORD *)v17[5].mDebugName = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v17[5].mTypeUID = UFG::qStringHash32("texDetailDiffuse2", 0xFFFFFFFF);
  LODWORD(v17[5].mStateBlockMask.mFlags[0]) = -1958479169;
  *((_DWORD *)&v17[5].0 + 22) = 0;
  v18 = v2->mTerrainMaterial;
  LOWORD(v18[5].mNumParams) = 0;
  HIDWORD(v18[5].mStateBlockMask.mFlags[1]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v18[5].mStateBlockMask.mFlags[1]) = UFG::qStringHash32("texDetailNormal2", 0xFFFFFFFF);
  v18[6].mNode.mUID = -1958479169;
  LODWORD(v18[6].mNode.mChild[1]) = 0;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, (UFG::qResourceData *)&v2->mTerrainMaterial->mNode);
  v20 = UFG::qStringHashUpper32("RenderStageTerrainMaterial_DX10", 0xFFFFFFFF);
  v2->mDX10TerrainMaterial = Illusion::Factory::NewMaterial(
                               "RenderStageTerrainMaterial_DX10",
                               v20,
                               0xCu,
                               0i64,
                               0i64,
                               0i64);
  v21 = UFG::qStringHashUpper32("DRHEIGHTMAPTERRAIN_DX10", 0xFFFFFFFF);
  v22 = v2->mDX10TerrainMaterial;
  LOWORD(v22[1].mNode.mChild[0]) = 0;
  HIDWORD(v22[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v22[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v22[1].mTypeUID = -1957338719;
  LODWORD(v22[1].mResourceHandles.mNode.mNext) = v21;
  v23 = v2->mDX10TerrainMaterial;
  *(_WORD *)&v23[1].mDebugName[12] = 0;
  *(_DWORD *)&v23[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v23[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v23[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v23[1].mStateBlockMask.mFlags[0]) = 662883558;
  v24 = v2->mDX10TerrainMaterial;
  LOWORD(v24[1].mMaterialUser.mOffset) = 0;
  *(&v24[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v24[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v24[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v24[2].mNode.mUID = 543723269;
  v25 = v2->mDX10TerrainMaterial;
  LOWORD(v25[2].mTypeUID) = 0;
  HIDWORD(v25[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v25[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v25[2].0 + 22) = -1958479169;
  *(_DWORD *)&v25[2].mDebugName[28] = 0;
  v26 = v2->mDX10TerrainMaterial;
  LOWORD(v26[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v26[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v26[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v26[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v26[3].mNode.mChild[0]) = 0;
  v27 = v2->mDX10TerrainMaterial;
  LOWORD(v27[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v27[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v27[3].mNode.mUID = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v27[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v27[3].mDebugName[12] = 0;
  v28 = v2->mDX10TerrainMaterial;
  *((_WORD *)&v28[3].0 + 44) = 0;
  *(_DWORD *)&v28[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v28[3].mDebugName[28] = UFG::qStringHash32("texDetailDiffuse0", 0xFFFFFFFF);
  LODWORD(v28[4].mNode.mParent) = -1958479169;
  LODWORD(v28[3].mMaterialUser.mOffset) = 0;
  v29 = v2->mDX10TerrainMaterial;
  LOWORD(v29[4].mNode.mChild[1]) = 0;
  HIDWORD(v29[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v29[4].mNode.mChild[0]) = UFG::qStringHash32("texDetailNormal0", 0xFFFFFFFF);
  *(_DWORD *)&v29[4].mDebugName[4] = -1958479169;
  v29[4].mTypeUID = 0;
  v30 = v2->mDX10TerrainMaterial;
  *(_WORD *)&v30[4].mDebugName[20] = 0;
  *(_DWORD *)&v30[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v30[4].mDebugName[12] = UFG::qStringHash32("texDetailDiffuse1", 0xFFFFFFFF);
  v30[4].mNumParams = -1958479169;
  LODWORD(v30[4].mStateBlockMask.mFlags[1]) = 0;
  v31 = v2->mDX10TerrainMaterial;
  LOWORD(v31[5].mNode.mParent) = 0;
  HIDWORD(v31[4].mMaterialUser.mOffset) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v31[4].mMaterialUser.mOffset) = UFG::qStringHash32("texDetailNormal1", 0xFFFFFFFF);
  LODWORD(v31[5].mResourceHandles.mNode.mNext) = -1958479169;
  LODWORD(v31[5].mResourceHandles.mNode.mPrev) = 0;
  v32 = v2->mDX10TerrainMaterial;
  *(_WORD *)&v32[5].mDebugName[4] = 0;
  *(_DWORD *)v32[5].mDebugName = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v32[5].mTypeUID = UFG::qStringHash32("texDetailDiffuse2", 0xFFFFFFFF);
  LODWORD(v32[5].mStateBlockMask.mFlags[0]) = -1958479169;
  *((_DWORD *)&v32[5].0 + 22) = 0;
  v33 = v2->mDX10TerrainMaterial;
  LOWORD(v33[5].mNumParams) = 0;
  HIDWORD(v33[5].mStateBlockMask.mFlags[1]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v33[5].mStateBlockMask.mFlags[1]) = UFG::qStringHash32("texDetailNormal2", 0xFFFFFFFF);
  v33[6].mNode.mUID = -1958479169;
  LODWORD(v33[6].mNode.mChild[1]) = 0;
  v34 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v34, (UFG::qResourceData *)&v2->mDX10TerrainMaterial->mNode);
  v35 = 0;
  v190 = 0;
  v36 = 0i64;
  *(_QWORD *)&v196.mStringHash32 = 0i64;
  do
  {
    v37 = 0x80u >> v35;
    v189 = 0x80u >> v35;
    v38 = 0;
    v39 = (unsigned int *)((char *)v2 + 4 * (5 * v36 + 180));
    v40 = 0i64;
    do
    {
      UFG::qString::FormatEx(&result, "TerrainPatchModel_%d_%d", v35, v38);
      v42 = result.mStringHashUpper32;
      if ( result.mStringHashUpper32 == -1 )
      {
        v42 = UFG::qStringHashUpper32(result.mData, result.mStringHashUpper32 | v41);
        result.mStringHashUpper32 = v42;
      }
      *(v39 - 90) = v42;
      v43 = Illusion::Factory::NewModel(result.mData, v42, 1u, 0i64, 0i64, 0i64);
      v208[v40] = (__int64)v43;
      v44 = v43[2].mNode.mChild[0];
      if ( v44 )
        v45 = (UFG::qBaseNodeRB **)((char *)v43[2].mNode.mChild + (_QWORD)v44);
      else
        v45 = 0i64;
      v46 = (__int64)v45 + *v45;
      if ( !*v45 )
        v46 = 0i64;
      v204[v40] = v46;
      UFG::qString::FormatEx(&v198, "DX10TerrainPatchModel_%d_%d", v35, v38);
      v48 = v198.mStringHashUpper32;
      if ( v198.mStringHashUpper32 == -1 )
      {
        v48 = UFG::qStringHashUpper32(v198.mData, v198.mStringHashUpper32 | v47);
        v198.mStringHashUpper32 = v48;
      }
      *v39 = v48;
      v49 = Illusion::Factory::NewModel(v198.mData, v48, 1u, 0i64, 0i64, 0i64);
      v209[v40] = (__int64)v49;
      v50 = v49[2].mNode.mChild[0];
      if ( v50 )
        v51 = (UFG::qBaseNodeRB **)((char *)v49[2].mNode.mChild + (_QWORD)v50);
      else
        v51 = 0i64;
      v52 = (__int64)v51 + *v51;
      if ( !*v51 )
        v52 = 0i64;
      v206[v40] = v52;
      UFG::qString::~qString(&v198);
      UFG::qString::~qString(&result);
      ++v38;
      ++v39;
      ++v40;
    }
    while ( v38 < 5 );
    UFG::qString::FormatEx(&v200, "TerrainPatchModel.VertexBuffer_%d", v35);
    v54 = v200.mStringHash32;
    if ( v200.mStringHash32 == -1 )
    {
      v54 = UFG::qStringHash32(v200.mData, v200.mStringHash32 | v53);
      v200.mStringHash32 = v54;
    }
    v55 = Illusion::Factory::NewBuffer(v200.mData, v54, 16 * (v37 + 5) * (v37 + 5), 0i64, v200.mData, 0i64, 0i64);
    v56 = (UFG::qResourceData *)v55;
    v55->mBufferType = 0;
    v55->mElementByteSize = 16;
    v55->mNumElements = (v37 + 5) * (v37 + 5);
    v57 = v55->mData.mOffset;
    if ( v57 )
      v58 = (signed __int64)v56[1].mNode.mChild + v57;
    else
      v58 = 0i64;
    v59 = 0;
    v60 = -2;
    v61 = v37 + 2;
    for ( HIDWORD(v196.mPrev) = v37 + 2; v60 <= v61; ++v60 )
    {
      v62 = -2;
      v63 = 1.0 / (float)(signed int)v37;
      do
      {
        v64 = v58 + 16i64 * v59++;
        *(float *)v64 = (float)v62 * v63;
        *(float *)(v64 + 4) = (float)v60 * v63;
        *(_DWORD *)(v64 + 8) = 0;
        *(_DWORD *)(v64 + 12) = 1065353216;
        ++v62;
      }
      while ( v62 <= v61 );
    }
    v65 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v65, v56);
    v66 = 0;
    v67 = 0i64;
    do
    {
      v68 = v204[v67];
      *(_QWORD *)(v68 + 224) = 18i64;
      if ( v66 == 4 )
        v69 = v61 * v61;
      else
        v69 = ((v37 >> 1) + 2) * ((v37 >> 1) + 2);
      *(_DWORD *)(v68 + 232) = v69;
      *(_QWORD *)(v68 + 240) = "TerrainPatchModel";
      *(_DWORD *)(v68 + 120) = v54;
      *(_DWORD *)(v68 + 56) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gSlimDescriptor);
      v70 = v206[v67];
      *(_QWORD *)(v70 + 224) = 3i64;
      if ( v66 == 4 )
        v71 = v61 * v61;
      else
        v71 = ((v37 >> 1) + 2) * ((v37 >> 1) + 2);
      *(_DWORD *)(v70 + 232) = 2 * v71;
      *(_QWORD *)(v70 + 240) = "DX10TerrainPatchModel";
      *(_DWORD *)(v70 + 120) = v54;
      *(_DWORD *)(v70 + 56) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gSlimDescriptor);
      ++v66;
      ++v67;
    }
    while ( v66 < 5 );
    UFG::qString::~qString(&v200);
    v72 = 0;
    LODWORD(v211) = 0;
    v73 = v37 >> 1;
    LODWORD(v196.mData) = v73;
    v74 = (v73 + 2) * (v73 + 2);
    v75 = 12 * v74;
    v193 = 12 * v74;
    v76 = 24 * v74;
    v77 = v204;
    *(_QWORD *)&v196.mMagic = v204;
    v78 = v190;
    do
    {
      UFG::qString::FormatEx(&v202, "TerrainPatchModel.IndexBuffer_%d_%d", v78, v72);
      v80 = v202.mStringHash32;
      LODWORD(v212) = v202.mStringHash32;
      if ( v202.mStringHash32 == -1 )
      {
        v80 = UFG::qStringHash32(v202.mData, v202.mStringHash32 | v79);
        LODWORD(v212) = v80;
        v202.mStringHash32 = v80;
      }
      v81 = Illusion::Factory::NewBuffer(v202.mData, v80, v76, 0i64, v202.mData, 0i64, 0i64);
      v196.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)v81;
      v81->mBufferType = 1;
      v81->mElementByteSize = 2;
      v81->mNumElements = v75;
      v82 = v81->mData.mOffset;
      if ( v82 )
        v83 = (signed __int64)&v81->mData + v82;
      else
        v83 = 0i64;
      v84 = 0i64;
      v85 = 1;
      v86 = v73 + 2;
      if ( v73 + 2 >= 1 )
      {
        do
        {
          v87 = v37 + 5;
          v88 = (v37 + 5) * (v85 + v73 * ((v72 >> 1) & 1) + 2);
          v89 = v87 * (v85 + v73 * ((v72 >> 1) & 1) + 1);
          v90 = (v85 + v73 * ((v72 >> 1) & 1)) * v87;
          v91 = v87 * (v85 + v73 * ((v72 >> 1) & 1) - 1);
          v92 = v73 * (v72 & 1) + 1;
          v93 = v86;
          do
          {
            *(_WORD *)(v83 + 2 * v84) = v92 + v90;
            v94 = (unsigned int)(v84 + 1);
            *(_WORD *)(v83 + 2 * v94) = v92 + v89;
            v95 = (unsigned int)(v94 + 1);
            *(_WORD *)(v83 + 2 * v95) = v92 + v89 + 1;
            v96 = (unsigned int)(v95 + 1);
            *(_WORD *)(v83 + 2 * v96) = v92 + v90 + 1;
            v97 = (unsigned int)(v96 + 1);
            *(_WORD *)(v83 + 2 * v97) = v92 + v90 - 1;
            v98 = (unsigned int)(v97 + 1);
            *(_WORD *)(v83 + 2 * v98) = v92 + v89 - 1;
            v99 = (unsigned int)(v98 + 1);
            *(_WORD *)(v83 + 2 * v99) = v92 + v88;
            v100 = (unsigned int)(v99 + 1);
            *(_WORD *)(v83 + 2 * v100) = v92 + v88 + 1;
            v101 = (unsigned int)(v100 + 1);
            *(_WORD *)(v83 + 2 * v101) = v92 + v89 + 2;
            v102 = (unsigned int)(v101 + 1);
            *(_WORD *)(v83 + 2 * v102) = v92 + v90 + 2;
            v103 = (unsigned int)(v102 + 1);
            *(_WORD *)(v83 + 2 * v103) = v92 + v91 + 1;
            v104 = (unsigned int)(v103 + 1);
            *(_WORD *)(v83 + 2 * v104) = v92 + v91;
            v84 = (unsigned int)(v104 + 1);
            ++v92;
            --v93;
          }
          while ( v93 );
          ++v85;
          v86 = v73 + 2;
          LOWORD(v37) = v189;
          v72 = (unsigned int)v211;
        }
        while ( v85 <= v73 + 2 );
        v78 = v190;
        v77 = *(__int64 **)&v196.mMagic;
        v75 = v193;
      }
      v105 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v105, (UFG::qResourceData *)v196.mNext);
      *(_DWORD *)(*v77 + 88) = (_DWORD)v212;
      UFG::qString::~qString(&v202);
      LODWORD(v211) = ++v72;
      ++v77;
      *(_QWORD *)&v196.mMagic = v77;
      v76 = 2 * v75;
    }
    while ( v72 < 4 );
    UFG::qString::FormatEx(&v196, "TerrainPatchModel.IndexBuffer_FULL_%d", v78);
    v106 = v196.mStringHash32;
    v194 = v196.mStringHash32;
    v107 = HIDWORD(v196.mPrev);
    if ( v196.mStringHash32 == -1 )
    {
      v106 = UFG::qStringHash32(v196.mData, 0xFFFFFFFF);
      v194 = v106;
      v196.mStringHash32 = v106;
    }
    v196.mMagic = v107 * v107;
    v108 = Illusion::Factory::NewBuffer(v196.mData, v106, 24 * v107 * v107, 0i64, v196.mData, 0i64, 0i64);
    data = (UFG::qResourceData *)v108;
    v108->mBufferType = 1;
    v108->mElementByteSize = 2;
    v108->mNumElements = 12 * v107 * v107;
    v109 = v108->mData.mOffset;
    if ( v109 )
      v110 = (signed __int64)&v108->mData + v109;
    else
      v110 = 0i64;
    v111 = 0i64;
    LOWORD(v112) = 1;
    LODWORD(v196.mNext) = 1;
    if ( v107 >= 1 )
    {
      do
      {
        v113 = 1;
        v114 = (v37 + 5) * (v112 + 1);
        v115 = v112 * (v37 + 5);
        LOWORD(v211) = v112 * (v37 + 5) + 1;
        v116 = (v37 + 5) * (v112 + 2);
        LOWORD(v212) = v116 + 1;
        LOWORD(v196.mPrev) = v114 + 2;
        LOWORD(data) = v112 * (v37 + 5) + 2;
        v117 = (v37 + 5) * (v112 - 1);
        do
        {
          *(_WORD *)(v110 + 2 * v111) = v113 + v115;
          v118 = (unsigned int)(v111 + 1);
          *(_WORD *)(v110 + 2 * v118) = v113 + v114;
          v119 = (unsigned int)(v118 + 1);
          *(_WORD *)(v110 + 2 * v119) = v113 + v114 + 1;
          v120 = (unsigned int)(v119 + 1);
          *(_WORD *)(v110 + 2 * v120) = v113 + v115 + 1;
          v121 = (unsigned int)(v120 + 1);
          *(_WORD *)(v110 + 2 * v121) = v113 + v115 - 1;
          v122 = (unsigned int)(v121 + 1);
          *(_WORD *)(v110 + 2 * v122) = v113 + v114 - 1;
          v123 = (unsigned int)(v122 + 1);
          *(_WORD *)(v110 + 2 * v123) = v113 + v116;
          v124 = (unsigned int)(v123 + 1);
          *(_WORD *)(v110 + 2 * v124) = v113 + (_WORD)v212;
          v125 = (unsigned int)(v124 + 1);
          *(_WORD *)(v110 + 2 * v125) = v113 + LOWORD(v196.mPrev);
          v126 = (unsigned int)(v125 + 1);
          *(_WORD *)(v110 + 2 * v126) = v113 + (_WORD)data;
          v127 = (unsigned int)(v126 + 1);
          *(_WORD *)(v110 + 2 * v127) = v113 + v117 + 1;
          v128 = (unsigned int)(v127 + 1);
          *(_WORD *)(v110 + 2 * v128) = v113 + v117;
          v111 = (unsigned int)(v128 + 1);
          ++v113;
        }
        while ( v113 <= v107 );
        v112 = LODWORD(v196.mNext) + 1;
        LODWORD(v196.mNext) = v112;
        LOWORD(v37) = v189;
      }
      while ( v112 <= v107 );
      v78 = v190;
    }
    v129 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v129, data);
    *(_DWORD *)(v205 + 88) = v194;
    UFG::qString::~qString(&v196);
    v130 = 0;
    v195 = 5i64 * (signed int)v78;
    v131 = v208;
    v132 = (__int64)v210;
    v133 = v210->mTerrainModelUIDs[*(_QWORD *)&v196.mStringHash32];
    v134 = 5i64 * (signed int)v78;
    do
    {
      v135 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v135, (UFG::qResourceData *)*v131);
      v136 = *v133;
      v137 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
      {
        v138 = UFG::qResourceWarehouse::Instance();
        v137 = UFG::qResourceWarehouse::GetInventory(v138, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v137;
      }
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)(v132 + 32 * (v134 + (signed int)v130++) + 40),
        0xA2ADCD77,
        v136,
        v137);
      ++v133;
      ++v131;
    }
    while ( v130 < 5 );
    v139 = 0;
    v140 = (int)v196.mData;
    v141 = (LODWORD(v196.mData) + 2) * (LODWORD(v196.mData) + 2);
    v142 = 6 * v141;
    LODWORD(v212) = 6 * v141;
    v143 = 12 * v141;
    v144 = (char *)v206;
    v196.mData = (char *)v206;
    v145 = v189;
    do
    {
      UFG::qString::FormatEx(&v197, "DX10TerrainPatchModel.IndexBuffer_%d_%d", v190, v139);
      v147 = v197.mStringHash32;
      LODWORD(v211) = v197.mStringHash32;
      if ( v197.mStringHash32 == -1 )
      {
        v147 = UFG::qStringHash32(v197.mData, v197.mStringHash32 | v146);
        LODWORD(v211) = v147;
        v197.mStringHash32 = v147;
      }
      v148 = Illusion::Factory::NewBuffer(v197.mData, v147, v143, 0i64, v197.mData, 0i64, 0i64);
      dataa = (UFG::qResourceData *)v148;
      v148->mBufferType = 1;
      v148->mElementByteSize = 2;
      v148->mNumElements = v142;
      v149 = v148->mData.mOffset;
      if ( v149 )
        v150 = (signed __int64)&v148->mData + v149;
      else
        v150 = 0i64;
      v151 = 0i64;
      v152 = 1;
      v153 = v140 + 2;
      if ( (unsigned int)(v140 + 2) >= 1 )
      {
        do
        {
          v154 = (v152 + v140 * ((v139 >> 1) & 1)) * (v145 + 5);
          v155 = (v145 + 5) * (v152 + v140 * ((v139 >> 1) & 1) + 1);
          v156 = v140 * (v139 & 1) + 1;
          v157 = v153;
          do
          {
            *(_WORD *)(v150 + 2 * v151) = v154 + v156;
            v158 = (unsigned int)(v151 + 1);
            *(_WORD *)(v150 + 2 * v158) = v155 + v156 + 1;
            v159 = (unsigned int)(v158 + 1);
            *(_WORD *)(v150 + 2 * v159) = v155 + v156;
            v160 = (unsigned int)(v159 + 1);
            *(_WORD *)(v150 + 2 * v160) = v154 + v156;
            v161 = (unsigned int)(v160 + 1);
            *(_WORD *)(v150 + 2 * v161) = v154 + v156 + 1;
            v162 = (unsigned int)(v161 + 1);
            *(_WORD *)(v150 + 2 * v162) = v155 + v156 + 1;
            v151 = (unsigned int)(v162 + 1);
            ++v156;
            --v157;
          }
          while ( v157 );
          ++v152;
          v153 = v140 + 2;
          v145 = v189;
        }
        while ( v152 <= v140 + 2 );
        v144 = v196.mData;
        v142 = (signed int)v212;
      }
      v163 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v163, dataa);
      *(_DWORD *)(*(_QWORD *)v144 + 88i64) = (_DWORD)v211;
      UFG::qString::~qString(&v197);
      ++v139;
      v144 += 8;
      v196.mData = v144;
      v145 = v189;
      v143 = 2 * v142;
    }
    while ( v139 < 4 );
    UFG::qString::FormatEx(&v199, "DX10TerrainPatchModel.IndexBuffer_FULL_%d", v190);
    v164 = v199.mStringHash32;
    LODWORD(v211) = v199.mStringHash32;
    v165 = HIDWORD(v196.mPrev);
    if ( v199.mStringHash32 == -1 )
    {
      v164 = UFG::qStringHash32(v199.mData, 0xFFFFFFFF);
      LODWORD(v211) = v164;
      v199.mStringHash32 = v164;
    }
    v166 = 6 * v196.mMagic;
    v167 = Illusion::Factory::NewBuffer(v199.mData, v164, 12 * v196.mMagic, 0i64, v199.mData, 0i64, 0i64);
    v212 = (UFG::qResourceData *)v167;
    v167->mBufferType = 1;
    v167->mElementByteSize = 2;
    v167->mNumElements = v166;
    v168 = v167->mData.mOffset;
    if ( v168 )
      v169 = (signed __int64)&v167->mData + v168;
    else
      v169 = 0i64;
    v170 = 0i64;
    for ( i = 1; i <= v165; ++i )
    {
      v172 = 1;
      v173 = i * (v189 + 5);
      v174 = (v189 + 5) * (i + 1);
      v175 = v174 + 1;
      do
      {
        *(_WORD *)(v169 + 2 * v170) = v172 + v173;
        v176 = (unsigned int)(v170 + 1);
        *(_WORD *)(v169 + 2 * v176) = v172 + v175;
        v177 = (unsigned int)(v176 + 1);
        *(_WORD *)(v169 + 2 * v177) = v172 + v174;
        v178 = (unsigned int)(v177 + 1);
        *(_WORD *)(v169 + 2 * v178) = v172 + v173;
        v179 = (unsigned int)(v178 + 1);
        *(_WORD *)(v169 + 2 * v179) = v172 + v173 + 1;
        v180 = (unsigned int)(v179 + 1);
        *(_WORD *)(v169 + 2 * v180) = v172 + v175;
        v170 = (unsigned int)(v180 + 1);
        ++v172;
      }
      while ( v172 <= v165 );
    }
    v181 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v181, v212);
    *(_DWORD *)(v207 + 88) = (_DWORD)v211;
    UFG::qString::~qString(&v199);
    v182 = 0;
    v183 = v209;
    v2 = v210;
    v184 = (unsigned int *)v195;
    do
    {
      v185 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v185, (UFG::qResourceData *)*v183);
      v186 = *v184;
      v187 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
      {
        v188 = UFG::qResourceWarehouse::Instance();
        v187 = UFG::qResourceWarehouse::GetInventory(v188, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v187;
      }
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)v2->mDX10TerrainModelHandles + v195 + (signed int)v182++,
        0xA2ADCD77,
        v186,
        v187);
      ++v184;
      ++v183;
    }
    while ( v182 < 5 );
    v35 = v190 + 1;
    v190 = v35;
    v36 = (*(_QWORD *)&v196.mStringHash32)++ + 1i64;
  }
  while ( (signed int)v35 < 2 );
} do
    {

// File Line: 491
// RVA: 0x31110
void __fastcall UFG::RenderStageTerrain::Shutdown(UFG::RenderStageTerrain *this)
{
  UFG::RenderStageTerrain *v1; // rbx
  float *v2; // rcx
  unsigned int v3; // edi
  signed __int64 v4; // rsi
  CullInfo *v5; // rbp
  CullManager *v6; // rax
  UFG::qHashMap<Render::TerrainData,0> *v7; // r8
  unsigned int v8; // eax
  UFG::qHashMapBase::Entry *v9; // rcx
  void **v10; // rdx
  UFG::qHashMap<Render::TerrainData,0> *v11; // rdi
  UFG::TerrainRenderNode *v12; // rcx
  unsigned int i; // edi
  signed __int64 v14; // rsi
  UFG::DataStreamer::Handle *v15; // rcx
  UFG::TerrainQuadTreeNode **v16; // rcx

  v1 = this;
  this->mRenderTerrain = 0;
  v2 = this->mLODRanges.p;
  if ( v2 )
    operator delete[](v2);
  v1->mLODRanges.p = 0i64;
  *(_QWORD *)&v1->mLODRanges.size = 0i64;
  v3 = 0;
  if ( v1->mNumTerrainQuadTreeNodes )
  {
    do
    {
      v4 = v3;
      v5 = v1->mTerrainQuadTreeNodes.p[v4].mCullInfo;
      if ( v5 )
      {
        v6 = CullManager::Instance();
        CullManager::FreePersistentCullInfo(v6, v1->mTerrainQuadTreeNodes.p[v4].mCullResults, v5);
      }
      ++v3;
    }
    while ( v3 < v1->mNumTerrainQuadTreeNodes );
  }
  v7 = v1->mTerrainDataMap;
  if ( v7 )
  {
    v8 = v7->mUsedCount;
    v9 = v7->mTable;
    if ( v8 )
    {
      v10 = &v9->value;
      do
      {
        if ( *v10 )
          --v8;
        v10 += 2;
      }
      while ( v8 );
    }
    *(_QWORD *)&v7->mFillCount = 0i64;
    UFG::qMemSet(v9, 0, 16 * (v7->mMask + 1));
    v11 = v1->mTerrainDataMap;
    if ( v11 )
    {
      UFG::qMemoryPool::Free(v11->mPool, v11->mTable);
      operator delete[](v11);
    }
    v1->mTerrainDataMap = 0i64;
  }
  v1->mTerrainQuadTreeNodes.size = 0;
  v1->mNumTerrainQuadTreeNodes = 0;
  v12 = v1->mTerrainRenderNodes.p;
  if ( v12 )
    operator delete[](v12);
  v1->mTerrainRenderNodes.p = 0i64;
  *(_QWORD *)&v1->mTerrainRenderNodes.size = 0i64;
  for ( i = 0; i < v1->mActiveTerrainNodes.size; ++i )
  {
    v14 = i;
    v15 = (UFG::DataStreamer::Handle *)v1->mActiveTerrainNodes.p[v14];
    if ( v15 )
    {
      UFG::DataStreamer::ReleaseStream(v15 + 4);
      v1->mActiveTerrainNodes.p[v14] = 0i64;
    }
  }
  v16 = v1->mActiveTerrainNodes.p;
  if ( v16 )
    operator delete[](v16);
  v1->mActiveTerrainNodes.p = 0i64;
  *(_QWORD *)&v1->mActiveTerrainNodes.size = 0i64;
}

// File Line: 530
// RVA: 0x312B0
void __fastcall UFG::RenderStageTerrain::Startup(UFG::RenderStageTerrain *this)
{
  UFG::RenderStageTerrain *v1; // rdi
  unsigned int v2; // ebx
  unsigned int v3; // edx
  unsigned int v4; // edx
  unsigned int v5; // edx
  UFG::qString result; // [rsp+48h] [rbp-40h]

  v1 = this;
  if ( UFG::RenderStageTerrain::msTerrainVramSize )
  {
    v2 = this->mActiveTerrainNodes.size + UFG::RenderStageTerrain::msMaxTerrainElements;
    v3 = this->mActiveTerrainNodes.capacity;
    if ( v2 > v3 )
    {
      if ( v3 )
        v4 = 2 * v3;
      else
        v4 = 1;
      for ( ; v4 < v2; v4 *= 2 )
        ;
      if ( v4 <= 2 )
        v4 = 2;
      if ( v4 - v2 > 0x10000 )
        v4 = v2 + 0x10000;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mActiveTerrainNodes,
        v4,
        "qArray.Reallocate(Grow)");
    }
    v1->mActiveTerrainNodes.size = v2;
    v5 = 0;
    if ( v2 )
    {
      do
        v1->mActiveTerrainNodes.p[v5++] = 0i64;
      while ( v5 < v1->mActiveTerrainNodes.size );
    }
    v1->mNumTerrainQuadTreeNodes = 1;
    v1->mTerrainQuadTreeNodes.size = 1;
    UFG::qMemSet(v1->mTerrainQuadTreeNodes.p, 0, 0x110u);
    if ( v1 != (UFG::RenderStageTerrain *)-968i64 )
    {
      v1->mTerrainQuadTreeNodes.p[0].mStream.mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v1->mTerrainQuadTreeNodes.p[0].mStream.mPrev;
      v1->mTerrainQuadTreeNodes.p[0].mStream.mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v1->mTerrainQuadTreeNodes.p[0].mStream.mPrev;
      v1->mTerrainQuadTreeNodes.p[0].mStream.mCallback = 0i64;
      v1->mTerrainQuadTreeNodes.p[0].mStream.mCallbackParam = 0i64;
      v1->mTerrainQuadTreeNodes.p[0].mStream.mImpl = 0i64;
      *(_DWORD *)&v1->mTerrainQuadTreeNodes.p[0].mStream.mFlags = 536870915;
      v1->mTerrainQuadTreeNodes.p[0].mStream._mTargetState.mValue = 1;
    }
    *v1->mActiveTerrainNodes.p = v1->mTerrainQuadTreeNodes.p;
    UFG::qString::FormatEx(
      &result,
      "data\\world\\%s\\terrain\\terrainnode_l0_x0_y0\\terrainnode_l0_x0_y0.perm.bin",
      stru_1423AA4A8.mData);
    UFG::DataStreamer::QueueStream(
      &(*v1->mActiveTerrainNodes.p)->mStream,
      result.mData,
      DATA_TERRAIN,
      HIGH_PRIORITY,
      0x80u,
      0i64,
      0i64);
    UFG::qString::~qString(&result);
  }
}

// File Line: 561
// RVA: 0x30720
void __fastcall UFG::RenderStageTerrain::Instantiate(UFG::RenderStageTerrain *this, Render::TerrainData *pRootNode)
{
  UFG::RenderStageTerrain *v2; // r14
  __int64 v3; // rax
  _WORD *v4; // rsi
  char *v5; // rdx
  __int64 v6; // r12
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned int v9; // edx
  unsigned int v10; // ebx
  signed int v11; // ecx
  __int64 v12; // rdx
  __int64 v13; // r8
  __m128 v14; // xmm0
  char *v15; // rax
  char *v16; // rdi
  unsigned int v17; // edi
  unsigned __int64 v18; // rax
  char *v19; // rbx
  unsigned int i; // er8
  signed __int64 v21; // rdx
  UFG::TerrainRenderNode *v22; // rcx
  unsigned int v23; // ebx
  unsigned int v24; // er13
  signed int v25; // edx
  unsigned int grid_y; // eax
  unsigned int v27; // er8
  unsigned int grid_x; // er15
  signed __int64 v29; // r12
  signed __int64 v30; // rdi
  float v31; // xmm1_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  UFG::qVector4 v34; // xmm1
  UFG::qVector4 v35; // xmm2
  UFG::qVector4 v36; // xmm3
  signed __int64 v37; // rax
  int v38; // er8
  int v39; // er9
  int v40; // er10
  unsigned int v41; // edi
  signed int v42; // ecx
  unsigned int v43; // eax
  __int64 v44; // rdx
  int v45; // ecx
  unsigned int v46; // er8
  Illusion::Material *v47; // rbx
  __int64 v48; // rax
  _WORD *v49; // rax
  unsigned int v50; // er8
  Illusion::Material *v51; // rbx
  __int64 v52; // rax
  _WORD *v53; // rax
  unsigned int v54; // er8
  Illusion::Material *v55; // rbx
  __int64 v56; // rax
  _WORD *v57; // rax
  unsigned int v58; // er8
  Illusion::Material *v59; // rbx
  __int64 v60; // rax
  _WORD *v61; // rax
  unsigned int v62; // er8
  Illusion::Material *v63; // rbx
  __int64 v64; // rax
  _WORD *v65; // rax
  unsigned int v66; // er8
  Illusion::Material *v67; // rbx
  __int64 v68; // rax
  _WORD *v69; // rax
  unsigned int v70; // er8
  Illusion::Material *v71; // rbx
  __int64 v72; // rax
  _WORD *v73; // rax
  unsigned int v74; // er8
  Illusion::Material *v75; // rbx
  __int64 v76; // rax
  _WORD *v77; // rax
  unsigned int v78; // er8
  Illusion::Material *v79; // rbx
  __int64 v80; // rax
  _WORD *v81; // rax
  unsigned int v82; // er8
  Illusion::Material *v83; // rbx
  __int64 v84; // rax
  _WORD *v85; // rax
  unsigned int v86; // er8
  Illusion::Material *v87; // rbx
  __int64 v88; // rax
  _WORD *v89; // rax
  unsigned int v90; // er8
  Illusion::Material *v91; // rbx
  __int64 v92; // rax
  UFG::qVector3 scale; // [rsp+48h] [rbp-41h]
  UFG::qMatrix44 dest; // [rsp+60h] [rbp-29h]
  unsigned int v95; // [rsp+F0h] [rbp+67h]
  int v96; // [rsp+F8h] [rbp+6Fh]
  unsigned int v97; // [rsp+100h] [rbp+77h]
  int v98; // [rsp+108h] [rbp+7Fh]

  v2 = this;
  v3 = pRootNode->mTerrainDefinition.mOffset;
  v4 = 0i64;
  if ( v3 )
    v5 = (char *)&pRootNode->mTerrainDefinition + v3;
  else
    v5 = 0i64;
  UFG::qMemCopy(&this->mTerrainParams, v5, 0x88u);
  v2->mRenderTerrain = 1;
  v6 = v2->mTerrainParams.mNumLevels;
  v98 = v6;
  v7 = v6 + v2->mLODRanges.size;
  v8 = v2->mLODRanges.capacity;
  if ( v7 > v8 )
  {
    if ( v8 )
      v9 = 2 * v8;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 <= 4 )
      v9 = 4;
    if ( v9 - v7 > 0x10000 )
      v9 = v7 + 0x10000;
    UFG::qArray<float,0>::Reallocate(&v2->mLODRanges, v9, "qArray.Reallocate(Grow)");
  }
  v2->mLODRanges.size = v7;
  v10 = 0;
  v11 = 1;
  if ( (_DWORD)v6 )
  {
    v12 = 0i64;
    v13 = v6;
    do
    {
      v10 += v11 * v11;
      v14 = (__m128)LODWORD(v2->mTerrainParams.mDimensions.x);
      v14.m128_f32[0] = (float)(v14.m128_f32[0] * v14.m128_f32[0]) * 2.0;
      v2->mLODRanges.p[v12] = COERCE_FLOAT(_mm_sqrt_ps(v14)) / (float)v11;
      v11 = __ROL4__(v11, 1);
      ++v12;
      --v13;
    }
    while ( v13 );
  }
  v2->mNumTerrainQuadTreeNodes = v10;
  v2->mTerrainQuadTreeNodes.size = v10;
  v15 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
  v16 = v15;
  if ( v15 )
    UFG::qHashMapBase::qHashMapBase((UFG::qHashMapBase *)v15, UFG::gMainMemoryPool, 16 * v10);
  else
    v16 = 0i64;
  v2->mTerrainDataMap = (UFG::qHashMap<Render::TerrainData,0> *)v16;
  v17 = 36 * v6;
  if ( (unsigned int)(36 * v6) > v2->mTerrainRenderNodes.capacity && v17 != v2->mTerrainRenderNodes.size )
  {
    v18 = 24i64 * v17;
    if ( !is_mul_ok(v17, 0x18ui64) )
      v18 = -1i64;
    v19 = UFG::qMalloc(v18, "qArray.Reallocate(Reserve)", 0i64);
    if ( v2->mTerrainRenderNodes.p )
    {
      for ( i = 0; i < v2->mTerrainRenderNodes.size; ++i )
      {
        v21 = 3i64 * i;
        v22 = v2->mTerrainRenderNodes.p;
        *(_QWORD *)&v19[8 * v21] = v22[i].mTreeNode;
        *(_QWORD *)&v19[8 * v21 + 8] = *(_QWORD *)&v22[i].mTerrainDataUID;
        *(_QWORD *)&v19[8 * v21 + 16] = *(_QWORD *)&v22[i].mQuadrantBits;
      }
      operator delete[](v2->mTerrainRenderNodes.p);
    }
    v2->mTerrainRenderNodes.p = (UFG::TerrainRenderNode *)v19;
    v2->mTerrainRenderNodes.capacity = v17;
  }
  v23 = 0;
  v96 = 0;
  v24 = 0;
  v25 = 1;
  if ( (_DWORD)v6 )
  {
    do
    {
      grid_y = 0;
      v95 = 0;
      if ( v25 )
      {
        v25 = __ROL4__(1, v24);
        v97 = __ROL4__(1, v24);
        v27 = 1 << v24;
        do
        {
          grid_x = 0;
          if ( v27 )
          {
            do
            {
              v29 = v23;
              v2->mTerrainQuadTreeNodes.p[v29].mUID = v23;
              v2->mTerrainQuadTreeNodes.p[v29].mLevel = v24;
              v2->mTerrainQuadTreeNodes.p[v29].mX = grid_x;
              v2->mTerrainQuadTreeNodes.p[v29].mY = grid_y;
              v2->mTerrainQuadTreeNodes.p[v29].mAssignedTerrainDataUIDs.size = 0;
              *(_DWORD *)&v2->mTerrainQuadTreeNodes.p[v29].mTransparencyTarget = 0;
              v30 = (signed __int64)&v2->mTerrainQuadTreeNodes.p[v29].mAABBMin;
              UFG::RenderStageTerrain::GetAABB(
                v2,
                &v2->mTerrainQuadTreeNodes.p[v29].mAABBMin,
                &v2->mTerrainQuadTreeNodes.p[v29].mAABBMax,
                v24,
                grid_x,
                grid_y);
              dest = UFG::qMatrix44::msIdentity;
              v31 = v2->mTerrainQuadTreeNodes.p[v29].mAABBMax.y - *(float *)(v30 + 4);
              scale.x = v2->mTerrainQuadTreeNodes.p[v29].mAABBMax.x - *(float *)v30;
              scale.y = v31;
              scale.z = 1.0;
              UFG::qScaleMatrix(&dest, &scale);
              v32 = *(float *)(v30 + 4);
              v33 = *(float *)(v30 + 8);
              dest.v3.x = *(float *)v30;
              dest.v3.y = v32;
              dest.v3.z = v33;
              dest.v3.w = 1.0;
              v34 = dest.v1;
              v35 = dest.v2;
              v36 = dest.v3;
              v2->mTerrainQuadTreeNodes.p[v29].mTransform.v0 = dest.v0;
              v2->mTerrainQuadTreeNodes.p[v29].mTransform.v1 = v34;
              v2->mTerrainQuadTreeNodes.p[v29].mTransform.v2 = v35;
              v2->mTerrainQuadTreeNodes.p[v29].mTransform.v3 = v36;
              v2->mTerrainQuadTreeNodes.p[v29].mCullInfo = 0i64;
              v2->mTerrainQuadTreeNodes.p[v29].mCullResults = 0i64;
              if ( v96 )
              {
                v37 = (signed __int64)&v2->mTerrainQuadTreeNodes.p[v29].mStream;
                if ( &v2->mTerrainQuadTreeNodes.p[v29].mStream )
                {
                  *(_QWORD *)v37 = v37;
                  *(_QWORD *)(v37 + 8) = v37;
                  *(_QWORD *)(v37 + 16) = 0i64;
                  *(_QWORD *)(v37 + 24) = 0i64;
                  *(_QWORD *)(v37 + 32) = 0i64;
                  *(_DWORD *)(v37 + 40) = 536870915;
                  *(_WORD *)(v37 + 44) = 1;
                }
              }
              if ( v24 == v98 - 1 )
                UFG::qMemSet(v2->mTerrainQuadTreeNodes.p[v29].mChildren, 0, 0x20u);
              if ( v96 )
              {
                v38 = 0;
                v39 = 0;
                v40 = 0;
                v41 = 0;
                v42 = 1;
                if ( (signed int)(v24 - 1) >= 2 )
                {
                  v43 = ((v24 - 3) >> 1) + 1;
                  v44 = v43;
                  v41 = 2 * v43;
                  do
                  {
                    v38 += v42 * v42;
                    v45 = __ROL4__(v42, 1);
                    v39 += v45 * v45;
                    v42 = __ROL4__(v45, 1);
                    --v44;
                  }
                  while ( v44 );
                }
                if ( v41 < v24 - 1 )
                  v40 = v42 * v42;
                v2->mTerrainQuadTreeNodes.p[0].mChildren[(grid_x & 1)
                                                       + 2 * (v95 & 1)
                                                       + 34i64
                                                       * (v40 + v38
                                                              + v39
                                                              + __ROR4__(v97, 1) * (v95 >> 1)
                                                              + (grid_x >> 1))] = &v2->mTerrainQuadTreeNodes.p[v29];
              }
              v23 = v96++ + 1;
              ++grid_x;
              v25 = __ROL4__(1, v24);
              grid_y = v95;
            }
            while ( grid_x < v97 );
            v27 = 1 << v24;
            LODWORD(v6) = v98;
          }
          v95 = ++grid_y;
        }
        while ( grid_y < v27 );
      }
      ++v24;
      v25 = __ROL4__(v25, 1);
    }
    while ( v24 < (unsigned int)v6 );
  }
  v46 = v2->mTerrainParams.mDetailMapParams[0].mDiffuseTextureUID;
  v47 = v2->mTerrainMaterial;
  if ( LODWORD(v47[3].mMaterialUser.mOffset) != v46 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v47[3].mStateBlockMask, (unsigned int)v47[4].mNode.mParent, v46);
    v48 = v47->mMaterialUser.mOffset;
    if ( v48 )
      v49 = (_WORD *)((char *)&v47->mMaterialUser + v48);
    else
      v49 = 0i64;
    *v49 |= 0x20u;
  }
  v50 = v2->mTerrainParams.mDetailMapParams[0].mNormalDisplaceSpecTextureUID;
  v51 = v2->mTerrainMaterial;
  if ( v51[4].mTypeUID != v50 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v51[4].mNode.mUID, *(_DWORD *)&v51[4].mDebugName[4], v50);
    v52 = v51->mMaterialUser.mOffset;
    if ( v52 )
      v53 = (_WORD *)((char *)&v51->mMaterialUser + v52);
    else
      v53 = 0i64;
    *v53 |= 0x20u;
  }
  v54 = v2->mTerrainParams.mDetailMapParams[1].mDiffuseTextureUID;
  v55 = v2->mTerrainMaterial;
  if ( LODWORD(v55[4].mStateBlockMask.mFlags[1]) != v54 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v55[4].mDebugName[28], v55[4].mNumParams, v54);
    v56 = v55->mMaterialUser.mOffset;
    if ( v56 )
      v57 = (_WORD *)((char *)&v55->mMaterialUser + v56);
    else
      v57 = 0i64;
    *v57 |= 0x20u;
  }
  v58 = v2->mTerrainParams.mDetailMapParams[1].mNormalDisplaceSpecTextureUID;
  v59 = v2->mTerrainMaterial;
  if ( LODWORD(v59[5].mResourceHandles.mNode.mPrev) != v58 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)v59[5].mNode.mChild,
      (unsigned int)v59[5].mResourceHandles.mNode.mNext,
      v58);
    v60 = v59->mMaterialUser.mOffset;
    if ( v60 )
      v61 = (_WORD *)((char *)&v59->mMaterialUser + v60);
    else
      v61 = 0i64;
    *v61 |= 0x20u;
  }
  v62 = v2->mTerrainParams.mDetailMapParams[2].mDiffuseTextureUID;
  v63 = v2->mTerrainMaterial;
  if ( *((_DWORD *)&v63[5].0 + 22) != v62 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v63[5].mDebugName[12], v63[5].mStateBlockMask.mFlags[0], v62);
    v64 = v63->mMaterialUser.mOffset;
    if ( v64 )
      v65 = (_WORD *)((char *)&v63->mMaterialUser + v64);
    else
      v65 = 0i64;
    *v65 |= 0x20u;
  }
  v66 = v2->mTerrainParams.mDetailMapParams[2].mNormalDisplaceSpecTextureUID;
  v67 = v2->mTerrainMaterial;
  if ( LODWORD(v67[6].mNode.mChild[1]) != v66 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v67[5].mMaterialUser, v67[6].mNode.mUID, v66);
    v68 = v67->mMaterialUser.mOffset;
    if ( v68 )
      v69 = (_WORD *)((char *)&v67->mMaterialUser + v68);
    else
      v69 = 0i64;
    *v69 |= 0x20u;
  }
  v70 = v2->mTerrainParams.mDetailMapParams[0].mDiffuseTextureUID;
  v71 = v2->mDX10TerrainMaterial;
  if ( LODWORD(v71[3].mMaterialUser.mOffset) != v70 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v71[3].mStateBlockMask, (unsigned int)v71[4].mNode.mParent, v70);
    v72 = v71->mMaterialUser.mOffset;
    if ( v72 )
      v73 = (_WORD *)((char *)&v71->mMaterialUser + v72);
    else
      v73 = 0i64;
    *v73 |= 0x20u;
  }
  v74 = v2->mTerrainParams.mDetailMapParams[0].mNormalDisplaceSpecTextureUID;
  v75 = v2->mDX10TerrainMaterial;
  if ( v75[4].mTypeUID != v74 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v75[4].mNode.mUID, *(_DWORD *)&v75[4].mDebugName[4], v74);
    v76 = v75->mMaterialUser.mOffset;
    if ( v76 )
      v77 = (_WORD *)((char *)&v75->mMaterialUser + v76);
    else
      v77 = 0i64;
    *v77 |= 0x20u;
  }
  v78 = v2->mTerrainParams.mDetailMapParams[1].mDiffuseTextureUID;
  v79 = v2->mDX10TerrainMaterial;
  if ( LODWORD(v79[4].mStateBlockMask.mFlags[1]) != v78 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v79[4].mDebugName[28], v79[4].mNumParams, v78);
    v80 = v79->mMaterialUser.mOffset;
    if ( v80 )
      v81 = (_WORD *)((char *)&v79->mMaterialUser + v80);
    else
      v81 = 0i64;
    *v81 |= 0x20u;
  }
  v82 = v2->mTerrainParams.mDetailMapParams[1].mNormalDisplaceSpecTextureUID;
  v83 = v2->mDX10TerrainMaterial;
  if ( LODWORD(v83[5].mResourceHandles.mNode.mPrev) != v82 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)v83[5].mNode.mChild,
      (unsigned int)v83[5].mResourceHandles.mNode.mNext,
      v82);
    v84 = v83->mMaterialUser.mOffset;
    if ( v84 )
      v85 = (_WORD *)((char *)&v83->mMaterialUser + v84);
    else
      v85 = 0i64;
    *v85 |= 0x20u;
  }
  v86 = v2->mTerrainParams.mDetailMapParams[2].mDiffuseTextureUID;
  v87 = v2->mDX10TerrainMaterial;
  if ( *((_DWORD *)&v87[5].0 + 22) != v86 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v87[5].mDebugName[12], v87[5].mStateBlockMask.mFlags[0], v86);
    v88 = v87->mMaterialUser.mOffset;
    if ( v88 )
      v89 = (_WORD *)((char *)&v87->mMaterialUser + v88);
    else
      v89 = 0i64;
    *v89 |= 0x20u;
  }
  v90 = v2->mTerrainParams.mDetailMapParams[2].mNormalDisplaceSpecTextureUID;
  v91 = v2->mDX10TerrainMaterial;
  if ( LODWORD(v91[6].mNode.mChild[1]) != v90 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v91[5].mMaterialUser, v91[6].mNode.mUID, v90);
    v92 = v91->mMaterialUser.mOffset;
    if ( v92 )
      v4 = (_WORD *)((char *)&v91->mMaterialUser + v92);
    *v4 |= 0x20u;
  }
}

// File Line: 744
// RVA: 0x30690
__int64 __fastcall UFG::RenderStageTerrain::GetQuadTreeNodeIndex(UFG::RenderStageTerrain *this, unsigned int level, unsigned int grid_x, unsigned int grid_y)
{
  int v4; // er11
  unsigned int v5; // esi
  int v6; // ebx
  int v7; // edi
  unsigned int v8; // ebp
  signed int v9; // eax
  unsigned int v10; // ecx
  __int64 v11; // rdx
  int v12; // ecx
  int v13; // eax

  v4 = 0;
  v5 = level;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 1;
  if ( (signed int)level >= 2 )
  {
    v10 = ((level - 2) >> 1) + 1;
    v11 = v10;
    v8 = 2 * v10;
    do
    {
      v12 = v9 * v9;
      v13 = __ROL4__(v9, 1);
      v4 += v12;
      v6 += v13 * v13;
      v9 = __ROL4__(v13, 1);
      --v11;
    }
    while ( v11 );
  }
  if ( v8 < v5 )
    v7 = v9 * v9;
  return grid_x + v7 + v4 + v6 + grid_y * (1 << v5);
}

// File Line: 759
// RVA: 0x304F0
void __fastcall UFG::RenderStageTerrain::GetAABB(UFG::RenderStageTerrain *this, UFG::qVector3 *out_min, UFG::qVector3 *out_max, unsigned int level, unsigned int grid_x, unsigned int grid_y)
{
  UFG::qVector3 *v6; // r10
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4

  v6 = out_min;
  out_min->z = 0.0;
  v7 = 1.0 / (float)(1 << level);
  out_min->x = (float)((float)(signed int)grid_x * v7) - 0.5;
  out_min->y = (float)((float)(signed int)grid_y * v7) - 0.5;
  out_max->z = 1.0;
  out_max->x = (float)((float)(signed int)(grid_x + 1) * v7) - 0.5;
  out_max->y = (float)((float)(signed int)(grid_y + 1) * v7) - 0.5;
  v8 = this->mTerrainParams.mDimensions.z * out_min->z;
  v9 = out_min->x * this->mTerrainParams.mDimensions.x;
  v6->y = v6->y * this->mTerrainParams.mDimensions.y;
  out_min->z = v8;
  out_min->x = v9;
  v10 = this->mTerrainParams.mDimensions.z * out_max->z;
  v11 = out_max->y * this->mTerrainParams.mDimensions.y;
  out_max->x = this->mTerrainParams.mDimensions.x * out_max->x;
  out_max->z = v10;
  out_max->y = v11;
  v12 = this->mTerrainParams.mOrigin.z + out_min->z;
  v13 = out_min->x + this->mTerrainParams.mOrigin.x;
  v6->y = this->mTerrainParams.mOrigin.y + v6->y;
  out_min->z = v12;
  out_min->x = v13;
  v14 = this->mTerrainParams.mOrigin.z + out_max->z;
  v15 = out_max->x + this->mTerrainParams.mOrigin.x;
  out_max->y = this->mTerrainParams.mOrigin.y + out_max->y;
  out_max->z = v14;
  out_max->x = v15;
}

// File Line: 778
// RVA: 0x30330
void __fastcall UFG::RenderStageTerrain::AddTerrainData(UFG::RenderStageTerrain *this, Render::TerrainData *pTerrainData)
{
  Render::TerrainData *v2; // rsi
  UFG::RenderStageTerrain *v3; // rdi
  signed __int64 v4; // rbp
  char *v5; // rdx
  CullInfo **v6; // r14
  __int64 v7; // rcx
  CullManager *v8; // rax
  CullInfo *v9; // rcx
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4

  v2 = pTerrainData;
  v3 = this;
  if ( !this->mRenderTerrain )
    UFG::RenderStageTerrain::Instantiate(this, pTerrainData);
  UFG::qHashMapBase::Set((UFG::qHashMapBase *)&v3->mTerrainDataMap->mPool, v2->mUID, v2);
  v4 = UFG::RenderStageTerrain::GetQuadTreeNodeIndex(v3, v2->mLevel, v2->mGridLocationX, v2->mGridLocationY);
  v5 = (char *)v3 + v4 * 272;
  v6 = (CullInfo **)((char *)v3 + v4 * 272);
  v7 = v3->mTerrainQuadTreeNodes.p[v4].mAssignedTerrainDataUIDs.size;
  *((_DWORD *)v5 + 198) = v7 + 1;
  *(_DWORD *)&v5[4 * v7 + 796] = v2->mUID;
  if ( !v3->mTerrainQuadTreeNodes.p[v4].mCullInfo )
  {
    v8 = CullManager::Instance();
    CullManager::AllocPersistentCullInfo(v8, &v3->mTerrainQuadTreeNodes.p[v4].mCullResults, v6 + 119, 0i64, 0i64, 0i64);
    v9 = v6[119];
    v9->mpLocalWorld = 0i64;
    *(_DWORD *)&v9->mIsLocalWorldIdentity = 0;
    *(_DWORD *)&v9->mPixelScaleBias = -130072;
    v10 = v3->mTerrainQuadTreeNodes.p[v4].mAABBMin.y;
    v11 = v3->mTerrainQuadTreeNodes.p[v4].mAABBMin.z;
    v9->mAABBMin[0] = v3->mTerrainQuadTreeNodes.p[v4].mAABBMin.x;
    v9->mAABBMin[1] = v10;
    v9->mAABBMin[2] = v11;
    v12 = v3->mTerrainQuadTreeNodes.p[v4].mAABBMax.y;
    v13 = v3->mTerrainQuadTreeNodes.p[v4].mAABBMax.z;
    v9->mAABBMax[0] = v3->mTerrainQuadTreeNodes.p[v4].mAABBMax.x;
    v9->mAABBMax[1] = v12;
    v9->mAABBMax[2] = v13;
  }
  if ( v3->mTerrainParams.mNumLevels - 1 == v2->mLevel )
  {
    if ( v3->mAddTerrainDataPhysicsCallback )
      v3->mAddTerrainDataPhysicsCallback(v2, &v3->mTerrainParams, &v3->mTerrainQuadTreeNodes.p[v4]);
  }
}

// File Line: 818
// RVA: 0x30F90
void __fastcall UFG::RenderStageTerrain::RemoveTerrainData(UFG::RenderStageTerrain *this, Render::TerrainData *pTerrainData)
{
  Render::TerrainData *v2; // rsi
  UFG::RenderStageTerrain *v3; // rdi
  unsigned int v4; // eax
  __int64 v5; // rdx
  signed __int64 v6; // rbx
  unsigned int v7; // ecx
  _DWORD *v8; // rax
  __int64 v9; // rax
  CullInfo *v10; // rbp
  CullResults *v11; // r14
  CullManager *v12; // rax
  UFG::qHashMap<Render::TerrainData,0> *v13; // rbx
  UFG::qHashMapBase::Entry *v14; // rax
  void (__fastcall *v15)(Render::TerrainData *); // rax

  v2 = pTerrainData;
  v3 = this;
  if ( this->mTerrainQuadTreeNodes.size )
  {
    v4 = UFG::RenderStageTerrain::GetQuadTreeNodeIndex(
           this,
           pTerrainData->mLevel,
           pTerrainData->mGridLocationX,
           pTerrainData->mGridLocationY);
    v5 = 0i64;
    v6 = (signed __int64)v3 + 272 * v4;
    v7 = *(_DWORD *)(v6 + 792);
    if ( v7 )
    {
      v8 = (_DWORD *)(v6 + 796);
      while ( v2->mUID != *v8 )
      {
        v5 = (unsigned int)(v5 + 1);
        ++v8;
        if ( (unsigned int)v5 >= v7 )
          goto LABEL_12;
      }
      if ( (signed int)v5 >= 0 )
      {
        v9 = v7 - 1;
        *(_DWORD *)(v6 + 792) = v9;
        *(_DWORD *)(v6 + 4 * v5 + 796) = *(_DWORD *)(v6 + 4 * v9 + 796);
        if ( !*(_DWORD *)(v6 + 792) )
        {
          v10 = *(CullInfo **)(v6 + 952);
          if ( v10 )
          {
            v11 = *(CullResults **)(v6 + 960);
            if ( v11 )
            {
              v12 = CullManager::Instance();
              CullManager::FreePersistentCullInfo(v12, v11, v10);
              *(_QWORD *)(v6 + 960) = 0i64;
              *(_QWORD *)(v6 + 952) = 0i64;
              *(_DWORD *)(v6 + 860) = 0;
            }
          }
        }
      }
    }
LABEL_12:
    v13 = v3->mTerrainDataMap;
    v14 = UFG::qHashMapBase::Lookup((UFG::qHashMapBase *)&v3->mTerrainDataMap->mPool, v2->mUID);
    if ( v14->value )
    {
      v14->value = 0i64;
      --v13->mUsedCount;
    }
    v15 = v3->mRemoveTerrainDataPhysicsCallback;
    if ( v15 )
      v15(v2);
  }
}

// File Line: 871
// RVA: 0x310E0
void __fastcall UFG::RenderStageTerrain::Render(UFG::RenderStageTerrain *this, UFG::RenderContext *render_context, Render::View *view)
{
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-78h]

  if ( this->mRenderTerrain )
  {
    Render::RenderOutputParams::RenderOutputParams(&outSettings);
    Render::GetCurrentDisplaySettings(&outSettings);
  }
}

