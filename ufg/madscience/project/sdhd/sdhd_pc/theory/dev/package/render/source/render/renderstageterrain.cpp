// File Line: 65
// RVA: 0x304A0
void __fastcall UFG::RenderStageTerrain::Create(UFG::RenderContext *render_context)
{
  char *v2; // rax

  v2 = UFG::qMalloc(0x223C8ui64, "RenderStageTerrain", 0i64);
  if ( v2 )
    UFG::RenderStageTerrain::RenderStageTerrain((UFG::RenderStageTerrain *)v2, render_context);
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
void __fastcall UFG::RenderStageTerrain::RenderStageTerrain(
        UFG::RenderStageTerrain *this,
        UFG::RenderContext *render_context)
{
  UFG::RenderStageTerrain *v2; // r14
  UFG::TerrainQuadTreeNode **p; // rcx
  unsigned int v4; // eax
  int v5; // edi
  Illusion::Material *mTerrainMaterial; // rbx
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
  UFG::qResourceWarehouse *v18; // rax
  unsigned int v19; // eax
  int v20; // edi
  Illusion::Material *mDX10TerrainMaterial; // rbx
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
  UFG::qResourceWarehouse *v33; // rax
  unsigned int v34; // r15d
  __int64 v35; // rax
  unsigned int v36; // edi
  unsigned int v37; // esi
  unsigned int *v38; // r14
  __int64 v39; // rbx
  unsigned int mStringHashUpper32; // eax
  UFG::qResourceData *v41; // rax
  UFG::qBaseNodeRB *v42; // rcx
  _QWORD *v43; // rax
  __int64 v44; // rdx
  unsigned int v45; // eax
  UFG::qResourceData *v46; // rax
  UFG::qBaseNodeRB *v47; // rcx
  _QWORD *v48; // rax
  __int64 v49; // rdx
  unsigned int mStringHash32; // r13d
  Illusion::Buffer *v51; // rbx
  __int64 mOffset; // rax
  char *v53; // r8
  int v54; // edx
  int v55; // r9d
  int v56; // r12d
  int v57; // ecx
  float v58; // xmm1_4
  char *v59; // rax
  UFG::qResourceWarehouse *v60; // rax
  unsigned int v61; // esi
  __int64 v62; // r14
  __int64 v63; // rbx
  int v64; // eax
  __int64 v65; // rbx
  int v66; // eax
  unsigned int v67; // r14d
  unsigned int v68; // r12d
  int v69; // eax
  int v70; // esi
  unsigned int v71; // r13d
  __int64 *v72; // rbx
  unsigned int v73; // r15d
  unsigned int v74; // eax
  Illusion::Buffer *v75; // rax
  __int64 v76; // rcx
  char *v77; // r10
  __int64 v78; // r9
  unsigned int v79; // r13d
  unsigned int v80; // ecx
  __int16 v81; // ax
  __int16 v82; // di
  __int16 v83; // si
  __int16 v84; // r15
  __int16 v85; // bx
  int v86; // r11d
  __int64 v87; // r14
  __int64 v88; // r9
  __int64 v89; // r9
  __int64 v90; // r9
  __int64 v91; // r9
  __int64 v92; // r9
  __int64 v93; // r9
  __int64 v94; // r9
  __int64 v95; // r9
  __int64 v96; // r9
  __int64 v97; // r9
  __int64 v98; // r9
  UFG::qResourceWarehouse *v99; // rax
  unsigned int v100; // eax
  unsigned int mPrev_high; // r12d
  Illusion::Buffer *v102; // rax
  __int64 v103; // rcx
  char *v104; // r11
  __int64 v105; // r9
  unsigned int v106; // r13d
  unsigned int v107; // r10d
  __int16 v108; // bx
  __int16 v109; // r15
  __int16 v110; // si
  __int16 v111; // r14
  __int64 v112; // r9
  __int64 v113; // r9
  __int64 v114; // r9
  __int64 v115; // r9
  __int64 v116; // r9
  __int64 v117; // r9
  __int64 v118; // r9
  __int64 v119; // r9
  __int64 v120; // r9
  __int64 v121; // r9
  __int64 v122; // r9
  UFG::qResourceWarehouse *v123; // rax
  unsigned int v124; // ebx
  __int64 *v125; // rsi
  __int64 v126; // r13
  unsigned int *v127; // r14
  UFG::qResourceWarehouse *v128; // rax
  unsigned int v129; // r15d
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v131; // rax
  unsigned int v132; // r13d
  int mData; // r15d
  int v134; // eax
  int v135; // esi
  unsigned int v136; // r14d
  char *v137; // rbx
  __int16 v138; // di
  unsigned int v139; // eax
  Illusion::Buffer *v140; // rax
  __int64 v141; // rcx
  char *v142; // r10
  __int64 v143; // r9
  unsigned int v144; // r14d
  unsigned int v145; // ecx
  __int16 v146; // si
  __int16 v147; // bx
  int v148; // r11d
  __int64 v149; // rdi
  __int64 v150; // r9
  __int64 v151; // r9
  __int64 v152; // r9
  __int64 v153; // r9
  __int64 v154; // r9
  UFG::qResourceWarehouse *v155; // rax
  unsigned int v156; // eax
  unsigned int v157; // r12d
  unsigned int v158; // ebx
  Illusion::Buffer *v159; // rax
  __int64 v160; // rcx
  char *v161; // r11
  __int64 v162; // r9
  unsigned int i; // r13d
  unsigned int v164; // r10d
  __int16 v165; // si
  __int16 v166; // di
  __int16 v167; // r15
  __int64 v168; // r9
  __int64 v169; // r9
  __int64 v170; // r9
  __int64 v171; // r9
  __int64 v172; // r9
  UFG::qResourceWarehouse *v173; // rax
  unsigned int v174; // ebx
  __int64 *v175; // rdi
  unsigned int *v176; // r12
  UFG::qResourceWarehouse *v177; // rax
  unsigned int v178; // esi
  UFG::qResourceInventory *v179; // rax
  UFG::qResourceWarehouse *v180; // rax
  unsigned int v181; // [rsp+40h] [rbp-88h]
  unsigned int v182; // [rsp+44h] [rbp-84h]
  UFG::qResourceData *data; // [rsp+48h] [rbp-80h]
  UFG::qResourceData *dataa; // [rsp+48h] [rbp-80h]
  int v185; // [rsp+50h] [rbp-78h]
  unsigned int v186; // [rsp+50h] [rbp-78h]
  __int64 v187; // [rsp+50h] [rbp-78h]
  UFG::qString v188; // [rsp+58h] [rbp-70h] BYREF
  UFG::qString v189; // [rsp+80h] [rbp-48h] BYREF
  UFG::qString v190; // [rsp+A8h] [rbp-20h] BYREF
  UFG::qString v191; // [rsp+D0h] [rbp+8h] BYREF
  UFG::qString v192; // [rsp+F8h] [rbp+30h] BYREF
  UFG::qString result; // [rsp+120h] [rbp+58h] BYREF
  UFG::qString v194; // [rsp+148h] [rbp+80h] BYREF
  __int64 v195; // [rsp+170h] [rbp+A8h]
  __int64 v196[4]; // [rsp+178h] [rbp+B0h] BYREF
  __int64 v197; // [rsp+198h] [rbp+D0h]
  __int64 v198[4]; // [rsp+1A0h] [rbp+D8h] BYREF
  __int64 v199; // [rsp+1C0h] [rbp+F8h]
  __int64 v200[5]; // [rsp+1C8h] [rbp+100h] BYREF
  __int64 v201[12]; // [rsp+1F0h] [rbp+128h] BYREF
  UFG::RenderStageTerrain *v202; // [rsp+268h] [rbp+1A0h]
  UFG::qFixedArray<UFG::TerrainQuadTreeNode,512> *p_mTerrainQuadTreeNodes; // [rsp+278h] [rbp+1B0h]
  UFG::qResourceData *v204; // [rsp+280h] [rbp+1B8h]

  v195 = -2i64;
  v2 = this;
  `eh vector constructor iterator(
    this->mTerrainModelHandles,
    0x20ui64,
    10,
    (void (__fastcall *)(void *))Illusion::ModelHandle::ModelHandle);
  `eh vector constructor iterator(
    v2->mDX10TerrainModelHandles,
    0x20ui64,
    10,
    (void (__fastcall *)(void *))Illusion::ModelHandle::ModelHandle);
  p_mTerrainQuadTreeNodes = &v2->mTerrainQuadTreeNodes;
  `eh vector constructor iterator(
    v2->mTerrainQuadTreeNodes.p,
    0x110ui64,
    512,
    (void (__fastcall *)(void *))UFG::TerrainQuadTreeNode::TerrainQuadTreeNode);
  v2->mTerrainQuadTreeNodes.size = 0;
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
  v2->mTerrainQuadTreeNodes.size = 0;
  v2->mTerrainDataMap = 0i64;
  p = v2->mActiveTerrainNodes.p;
  if ( p )
    operator delete[](p);
  v2->mActiveTerrainNodes.p = 0i64;
  *(_QWORD *)&v2->mActiveTerrainNodes.size = 0i64;
  v4 = UFG::qStringHashUpper32("RenderStageTerrainMaterial", 0xFFFFFFFF);
  v2->mTerrainMaterial = Illusion::Factory::NewMaterial("RenderStageTerrainMaterial", v4, 0xCu, 0i64, 0i64, 0i64);
  v5 = UFG::qStringHashUpper32("DRHEIGHTMAPTERRAIN", 0xFFFFFFFF);
  mTerrainMaterial = v2->mTerrainMaterial;
  LOWORD(mTerrainMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(mTerrainMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(mTerrainMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  mTerrainMaterial[1].mTypeUID = -1957338719;
  LODWORD(mTerrainMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v5;
  v7 = v2->mTerrainMaterial;
  *(_WORD *)&v7[1].mDebugName[12] = 0;
  *(_DWORD *)&v7[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v7[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v7[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v7[1].mStateBlockMask.mFlags[0]) = 662883558;
  v8 = v2->mTerrainMaterial;
  LOWORD(v8[1].mMaterialUser.mOffset) = 0;
  *(&v8[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v8[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v8[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v8[2].mNode.mUID = 543723269;
  v9 = v2->mTerrainMaterial;
  LOWORD(v9[2].mTypeUID) = 0;
  HIDWORD(v9[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v9[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v9[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v9[2].mDebugName[28] = 0;
  v10 = v2->mTerrainMaterial;
  LOWORD(v10[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v10[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v10[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v10[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v10[3].mNode.mChild[0]) = 0;
  v11 = v2->mTerrainMaterial;
  LOWORD(v11[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v11[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v11[3].mNode.mUID = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v11[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v11[3].mDebugName[12] = 0;
  v12 = v2->mTerrainMaterial;
  *((_WORD *)&v12[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v12[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v12[3].mDebugName[28] = UFG::qStringHash32("texDetailDiffuse0", 0xFFFFFFFF);
  LODWORD(v12[4].mNode.mParent) = -1958479169;
  LODWORD(v12[3].mMaterialUser.mOffset) = 0;
  v13 = v2->mTerrainMaterial;
  LOWORD(v13[4].mNode.mChild[1]) = 0;
  HIDWORD(v13[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v13[4].mNode.mChild[0]) = UFG::qStringHash32("texDetailNormal0", 0xFFFFFFFF);
  *(_DWORD *)&v13[4].mDebugName[4] = -1958479169;
  v13[4].mTypeUID = 0;
  v14 = v2->mTerrainMaterial;
  *(_WORD *)&v14[4].mDebugName[20] = 0;
  *(_DWORD *)&v14[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v14[4].mDebugName[12] = UFG::qStringHash32("texDetailDiffuse1", 0xFFFFFFFF);
  v14[4].mNumParams = -1958479169;
  LODWORD(v14[4].mStateBlockMask.mFlags[1]) = 0;
  v15 = v2->mTerrainMaterial;
  LOWORD(v15[5].mNode.mParent) = 0;
  HIDWORD(v15[4].mMaterialUser.mOffset) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v15[4].mMaterialUser.mOffset) = UFG::qStringHash32("texDetailNormal1", 0xFFFFFFFF);
  LODWORD(v15[5].mResourceHandles.UFG::qResourceData::mNode.mNext) = -1958479169;
  LODWORD(v15[5].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  v16 = v2->mTerrainMaterial;
  *(_WORD *)&v16[5].mDebugName[4] = 0;
  *(_DWORD *)v16[5].mDebugName = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v16[5].mTypeUID = UFG::qStringHash32("texDetailDiffuse2", 0xFFFFFFFF);
  LODWORD(v16[5].mStateBlockMask.mFlags[0]) = -1958479169;
  *((_DWORD *)&v16[5].UFG::qResourceData + 22) = 0;
  v17 = v2->mTerrainMaterial;
  LOWORD(v17[5].mNumParams) = 0;
  HIDWORD(v17[5].mStateBlockMask.mFlags[1]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v17[5].mStateBlockMask.mFlags[1]) = UFG::qStringHash32("texDetailNormal2", 0xFFFFFFFF);
  v17[6].mNode.mUID = -1958479169;
  LODWORD(v17[6].mNode.mChild[1]) = 0;
  v18 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v18, v2->mTerrainMaterial);
  v19 = UFG::qStringHashUpper32("RenderStageTerrainMaterial_DX10", 0xFFFFFFFF);
  v2->mDX10TerrainMaterial = Illusion::Factory::NewMaterial(
                               "RenderStageTerrainMaterial_DX10",
                               v19,
                               0xCu,
                               0i64,
                               0i64,
                               0i64);
  v20 = UFG::qStringHashUpper32("DRHEIGHTMAPTERRAIN_DX10", 0xFFFFFFFF);
  mDX10TerrainMaterial = v2->mDX10TerrainMaterial;
  LOWORD(mDX10TerrainMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(mDX10TerrainMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(mDX10TerrainMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  mDX10TerrainMaterial[1].mTypeUID = -1957338719;
  LODWORD(mDX10TerrainMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v20;
  v22 = v2->mDX10TerrainMaterial;
  *(_WORD *)&v22[1].mDebugName[12] = 0;
  *(_DWORD *)&v22[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v22[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v22[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v22[1].mStateBlockMask.mFlags[0]) = 662883558;
  v23 = v2->mDX10TerrainMaterial;
  LOWORD(v23[1].mMaterialUser.mOffset) = 0;
  *(&v23[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v23[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v23[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v23[2].mNode.mUID = 543723269;
  v24 = v2->mDX10TerrainMaterial;
  LOWORD(v24[2].mTypeUID) = 0;
  HIDWORD(v24[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v24[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v24[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v24[2].mDebugName[28] = 0;
  v25 = v2->mDX10TerrainMaterial;
  LOWORD(v25[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v25[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v25[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texDepth", 0xFFFFFFFF);
  LODWORD(v25[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v25[3].mNode.mChild[0]) = 0;
  v26 = v2->mDX10TerrainMaterial;
  LOWORD(v26[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v26[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v26[3].mNode.mUID = UFG::qStringHash32("texDiffuse2", 0xFFFFFFFF);
  *(_DWORD *)&v26[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v26[3].mDebugName[12] = 0;
  v27 = v2->mDX10TerrainMaterial;
  *((_WORD *)&v27[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v27[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v27[3].mDebugName[28] = UFG::qStringHash32("texDetailDiffuse0", 0xFFFFFFFF);
  LODWORD(v27[4].mNode.mParent) = -1958479169;
  LODWORD(v27[3].mMaterialUser.mOffset) = 0;
  v28 = v2->mDX10TerrainMaterial;
  LOWORD(v28[4].mNode.mChild[1]) = 0;
  HIDWORD(v28[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v28[4].mNode.mChild[0]) = UFG::qStringHash32("texDetailNormal0", 0xFFFFFFFF);
  *(_DWORD *)&v28[4].mDebugName[4] = -1958479169;
  v28[4].mTypeUID = 0;
  v29 = v2->mDX10TerrainMaterial;
  *(_WORD *)&v29[4].mDebugName[20] = 0;
  *(_DWORD *)&v29[4].mDebugName[16] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v29[4].mDebugName[12] = UFG::qStringHash32("texDetailDiffuse1", 0xFFFFFFFF);
  v29[4].mNumParams = -1958479169;
  LODWORD(v29[4].mStateBlockMask.mFlags[1]) = 0;
  v30 = v2->mDX10TerrainMaterial;
  LOWORD(v30[5].mNode.mParent) = 0;
  HIDWORD(v30[4].mMaterialUser.mOffset) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v30[4].mMaterialUser.mOffset) = UFG::qStringHash32("texDetailNormal1", 0xFFFFFFFF);
  LODWORD(v30[5].mResourceHandles.UFG::qResourceData::mNode.mNext) = -1958479169;
  LODWORD(v30[5].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  v31 = v2->mDX10TerrainMaterial;
  *(_WORD *)&v31[5].mDebugName[4] = 0;
  *(_DWORD *)v31[5].mDebugName = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v31[5].mTypeUID = UFG::qStringHash32("texDetailDiffuse2", 0xFFFFFFFF);
  LODWORD(v31[5].mStateBlockMask.mFlags[0]) = -1958479169;
  *((_DWORD *)&v31[5].UFG::qResourceData + 22) = 0;
  v32 = v2->mDX10TerrainMaterial;
  LOWORD(v32[5].mNumParams) = 0;
  HIDWORD(v32[5].mStateBlockMask.mFlags[1]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v32[5].mStateBlockMask.mFlags[1]) = UFG::qStringHash32("texDetailNormal2", 0xFFFFFFFF);
  v32[6].mNode.mUID = -1958479169;
  LODWORD(v32[6].mNode.mChild[1]) = 0;
  v33 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v33, v2->mDX10TerrainMaterial);
  v34 = 0;
  v182 = 0;
  v35 = 0i64;
  *(_QWORD *)&v188.mStringHash32 = 0i64;
  do
  {
    v36 = 0x80u >> v34;
    v181 = 0x80u >> v34;
    v37 = 0;
    v38 = v2->mDX10TerrainModelUIDs[v35];
    v39 = 0i64;
    do
    {
      UFG::qString::FormatEx(&result, "TerrainPatchModel_%d_%d", v34, v37);
      mStringHashUpper32 = result.mStringHashUpper32;
      if ( result.mStringHashUpper32 == -1 )
      {
        mStringHashUpper32 = UFG::qStringHashUpper32(result.mData, 0xFFFFFFFF);
        result.mStringHashUpper32 = mStringHashUpper32;
      }
      *(v38 - 90) = mStringHashUpper32;
      v41 = Illusion::Factory::NewModel(result.mData, mStringHashUpper32, 1u, 0i64, 0i64, 0i64);
      v200[v39] = (__int64)v41;
      v42 = v41[2].mNode.mChild[0];
      if ( v42 )
        v43 = (UFG::qBaseNodeRB **)((char *)v41[2].mNode.mChild + (_QWORD)v42);
      else
        v43 = 0i64;
      v44 = (__int64)v43 + *v43;
      if ( !*v43 )
        v44 = 0i64;
      v196[v39] = v44;
      UFG::qString::FormatEx(&v190, "DX10TerrainPatchModel_%d_%d", v34, v37);
      v45 = v190.mStringHashUpper32;
      if ( v190.mStringHashUpper32 == -1 )
      {
        v45 = UFG::qStringHashUpper32(v190.mData, 0xFFFFFFFF);
        v190.mStringHashUpper32 = v45;
      }
      *v38 = v45;
      v46 = Illusion::Factory::NewModel(v190.mData, v45, 1u, 0i64, 0i64, 0i64);
      v201[v39] = (__int64)v46;
      v47 = v46[2].mNode.mChild[0];
      if ( v47 )
        v48 = (UFG::qBaseNodeRB **)((char *)v46[2].mNode.mChild + (_QWORD)v47);
      else
        v48 = 0i64;
      v49 = (__int64)v48 + *v48;
      if ( !*v48 )
        v49 = 0i64;
      v198[v39] = v49;
      UFG::qString::~qString(&v190);
      UFG::qString::~qString(&result);
      ++v37;
      ++v38;
      ++v39;
    }
    while ( v37 < 5 );
    UFG::qString::FormatEx(&v192, "TerrainPatchModel.VertexBuffer_%d", v34);
    mStringHash32 = v192.mStringHash32;
    if ( v192.mStringHash32 == -1 )
    {
      mStringHash32 = UFG::qStringHash32(v192.mData, 0xFFFFFFFF);
      v192.mStringHash32 = mStringHash32;
    }
    v51 = Illusion::Factory::NewBuffer(
            v192.mData,
            mStringHash32,
            16 * (v36 + 5) * (v36 + 5),
            0i64,
            v192.mData,
            0i64,
            0i64);
    v51->mBufferType = 0;
    v51->mElementByteSize = 16;
    v51->mNumElements = (v36 + 5) * (v36 + 5);
    mOffset = v51->mData.mOffset;
    if ( mOffset )
      v53 = (char *)&v51->mData + mOffset;
    else
      v53 = 0i64;
    v54 = 0;
    v55 = -2;
    v56 = v36 + 2;
    for ( HIDWORD(v188.mPrev) = v36 + 2; v55 <= v56; ++v55 )
    {
      v57 = -2;
      v58 = 1.0 / (float)(int)v36;
      do
      {
        v59 = &v53[16 * v54++];
        *(float *)v59 = (float)v57 * v58;
        *((float *)v59 + 1) = (float)v55 * v58;
        *((_DWORD *)v59 + 2) = 0;
        *((_DWORD *)v59 + 3) = 1065353216;
        ++v57;
      }
      while ( v57 <= v56 );
    }
    v60 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v60, &v51->UFG::qResourceData);
    v61 = 0;
    v62 = 0i64;
    do
    {
      v63 = v196[v62];
      *(_QWORD *)(v63 + 224) = 18i64;
      if ( v61 == 4 )
        v64 = v56 * v56;
      else
        v64 = ((v36 >> 1) + 2) * ((v36 >> 1) + 2);
      *(_DWORD *)(v63 + 232) = v64;
      *(_QWORD *)(v63 + 240) = "TerrainPatchModel";
      *(_DWORD *)(v63 + 120) = mStringHash32;
      *(_DWORD *)(v63 + 56) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gSlimDescriptor);
      v65 = v198[v62];
      *(_QWORD *)(v65 + 224) = 3i64;
      if ( v61 == 4 )
        v66 = v56 * v56;
      else
        v66 = ((v36 >> 1) + 2) * ((v36 >> 1) + 2);
      *(_DWORD *)(v65 + 232) = 2 * v66;
      *(_QWORD *)(v65 + 240) = "DX10TerrainPatchModel";
      *(_DWORD *)(v65 + 120) = mStringHash32;
      *(_DWORD *)(v65 + 56) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gSlimDescriptor);
      ++v61;
      ++v62;
    }
    while ( v61 < 5 );
    UFG::qString::~qString(&v192);
    v67 = 0;
    LODWORD(p_mTerrainQuadTreeNodes) = 0;
    v68 = v36 >> 1;
    LODWORD(v188.mData) = v68;
    v69 = (v68 + 2) * (v68 + 2);
    v70 = 12 * v69;
    v185 = 12 * v69;
    v71 = 24 * v69;
    v72 = v196;
    *(_QWORD *)&v188.mMagic = v196;
    v73 = v182;
    do
    {
      UFG::qString::FormatEx(&v194, "TerrainPatchModel.IndexBuffer_%d_%d", v73, v67);
      v74 = v194.mStringHash32;
      LODWORD(v204) = v194.mStringHash32;
      if ( v194.mStringHash32 == -1 )
      {
        v74 = UFG::qStringHash32(v194.mData, 0xFFFFFFFF);
        LODWORD(v204) = v74;
        v194.mStringHash32 = v74;
      }
      v75 = Illusion::Factory::NewBuffer(v194.mData, v74, v71, 0i64, v194.mData, 0i64, 0i64);
      v188.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)v75;
      v75->mBufferType = 1;
      v75->mElementByteSize = 2;
      v75->mNumElements = v70;
      v76 = v75->mData.mOffset;
      if ( v76 )
        v77 = (char *)&v75->mData + v76;
      else
        v77 = 0i64;
      v78 = 0i64;
      v79 = 1;
      v80 = v68 + 2;
      if ( v68 != -2 )
      {
        do
        {
          v81 = v36 + 5;
          v82 = (v36 + 5) * (v79 + v68 * ((v67 >> 1) & 1) + 2);
          v83 = v81 * (v79 + v68 * ((v67 >> 1) & 1) + 1);
          v84 = (v79 + v68 * ((v67 >> 1) & 1)) * v81;
          v85 = v81 * (v79 + v68 * ((v67 >> 1) & 1) - 1);
          v86 = v68 * (v67 & 1) + 1;
          v87 = v80;
          do
          {
            *(_WORD *)&v77[2 * v78] = v86 + v84;
            v88 = (unsigned int)(v78 + 1);
            *(_WORD *)&v77[2 * v88] = v86 + v83;
            v89 = (unsigned int)(v88 + 1);
            *(_WORD *)&v77[2 * v89] = v86 + v83 + 1;
            v90 = (unsigned int)(v89 + 1);
            *(_WORD *)&v77[2 * v90] = v86 + v84 + 1;
            v91 = (unsigned int)(v90 + 1);
            *(_WORD *)&v77[2 * v91] = v86 + v84 - 1;
            v92 = (unsigned int)(v91 + 1);
            *(_WORD *)&v77[2 * v92] = v86 + v83 - 1;
            v93 = (unsigned int)(v92 + 1);
            *(_WORD *)&v77[2 * v93] = v86 + v82;
            v94 = (unsigned int)(v93 + 1);
            *(_WORD *)&v77[2 * v94] = v86 + v82 + 1;
            v95 = (unsigned int)(v94 + 1);
            *(_WORD *)&v77[2 * v95] = v86 + v83 + 2;
            v96 = (unsigned int)(v95 + 1);
            *(_WORD *)&v77[2 * v96] = v86 + v84 + 2;
            v97 = (unsigned int)(v96 + 1);
            *(_WORD *)&v77[2 * v97] = v86 + v85 + 1;
            v98 = (unsigned int)(v97 + 1);
            *(_WORD *)&v77[2 * v98] = v86 + v85;
            v78 = (unsigned int)(v98 + 1);
            ++v86;
            --v87;
          }
          while ( v87 );
          ++v79;
          v80 = v68 + 2;
          LOWORD(v36) = v181;
          v67 = (unsigned int)p_mTerrainQuadTreeNodes;
        }
        while ( v79 <= v68 + 2 );
        v73 = v182;
        v72 = *(__int64 **)&v188.mMagic;
        v70 = v185;
      }
      v99 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v99, (UFG::qResourceData *)v188.mNext);
      *(_DWORD *)(*v72 + 88) = (_DWORD)v204;
      UFG::qString::~qString(&v194);
      LODWORD(p_mTerrainQuadTreeNodes) = ++v67;
      *(_QWORD *)&v188.mMagic = ++v72;
      v71 = 2 * v70;
    }
    while ( v67 < 4 );
    UFG::qString::FormatEx(&v188, "TerrainPatchModel.IndexBuffer_FULL_%d", v73);
    v100 = v188.mStringHash32;
    v186 = v188.mStringHash32;
    mPrev_high = HIDWORD(v188.mPrev);
    if ( v188.mStringHash32 == -1 )
    {
      v100 = UFG::qStringHash32(v188.mData, 0xFFFFFFFF);
      v186 = v100;
      v188.mStringHash32 = v100;
    }
    v188.mMagic = mPrev_high * mPrev_high;
    v102 = Illusion::Factory::NewBuffer(v188.mData, v100, 24 * mPrev_high * mPrev_high, 0i64, v188.mData, 0i64, 0i64);
    data = (UFG::qResourceData *)v102;
    v102->mBufferType = 1;
    v102->mElementByteSize = 2;
    v102->mNumElements = 12 * mPrev_high * mPrev_high;
    v103 = v102->mData.mOffset;
    if ( v103 )
      v104 = (char *)&v102->mData + v103;
    else
      v104 = 0i64;
    v105 = 0i64;
    LOWORD(v106) = 1;
    LODWORD(v188.mNext) = 1;
    if ( mPrev_high )
    {
      do
      {
        v107 = 1;
        v108 = (v36 + 5) * (v106 + 1);
        v109 = v106 * (v36 + 5);
        LOWORD(p_mTerrainQuadTreeNodes) = v109 + 1;
        v110 = (v36 + 5) * (v106 + 2);
        LOWORD(v204) = v110 + 1;
        LOWORD(v188.mPrev) = v108 + 2;
        LOWORD(data) = v109 + 2;
        v111 = (v36 + 5) * (v106 - 1);
        do
        {
          *(_WORD *)&v104[2 * v105] = v107 + v109;
          v112 = (unsigned int)(v105 + 1);
          *(_WORD *)&v104[2 * v112] = v107 + v108;
          v113 = (unsigned int)(v112 + 1);
          *(_WORD *)&v104[2 * v113] = v107 + v108 + 1;
          v114 = (unsigned int)(v113 + 1);
          *(_WORD *)&v104[2 * v114] = v107 + v109 + 1;
          v115 = (unsigned int)(v114 + 1);
          *(_WORD *)&v104[2 * v115] = v107 + v109 - 1;
          v116 = (unsigned int)(v115 + 1);
          *(_WORD *)&v104[2 * v116] = v107 + v108 - 1;
          v117 = (unsigned int)(v116 + 1);
          *(_WORD *)&v104[2 * v117] = v107 + v110;
          v118 = (unsigned int)(v117 + 1);
          *(_WORD *)&v104[2 * v118] = v107 + (_WORD)v204;
          v119 = (unsigned int)(v118 + 1);
          *(_WORD *)&v104[2 * v119] = v107 + LOWORD(v188.mPrev);
          v120 = (unsigned int)(v119 + 1);
          *(_WORD *)&v104[2 * v120] = v107 + (_WORD)data;
          v121 = (unsigned int)(v120 + 1);
          *(_WORD *)&v104[2 * v121] = v107 + v111 + 1;
          v122 = (unsigned int)(v121 + 1);
          *(_WORD *)&v104[2 * v122] = v107 + v111;
          v105 = (unsigned int)(v122 + 1);
          ++v107;
        }
        while ( v107 <= mPrev_high );
        v106 = LODWORD(v188.mNext) + 1;
        LODWORD(v188.mNext) = v106;
        LOWORD(v36) = v181;
      }
      while ( v106 <= mPrev_high );
      v73 = v182;
    }
    v123 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v123, data);
    *(_DWORD *)(v197 + 88) = v186;
    UFG::qString::~qString(&v188);
    v124 = 0;
    v187 = 5i64 * (int)v73;
    v125 = v200;
    v126 = (__int64)v202;
    v127 = v202->mTerrainModelUIDs[*(_QWORD *)&v188.mStringHash32];
    do
    {
      v128 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v128, (UFG::qResourceData *)*v125);
      v129 = *v127;
      Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v131 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v131, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)(v126 + 32 * (v187 + (int)v124++) + 40),
        0xA2ADCD77,
        v129,
        Inventory);
      ++v127;
      ++v125;
    }
    while ( v124 < 5 );
    v132 = 0;
    mData = (int)v188.mData;
    v134 = (LODWORD(v188.mData) + 2) * (LODWORD(v188.mData) + 2);
    v135 = 6 * v134;
    LODWORD(v204) = 6 * v134;
    v136 = 12 * v134;
    v137 = (char *)v198;
    v188.mData = (char *)v198;
    v138 = v181;
    do
    {
      UFG::qString::FormatEx(&v189, "DX10TerrainPatchModel.IndexBuffer_%d_%d", v182, v132);
      v139 = v189.mStringHash32;
      LODWORD(p_mTerrainQuadTreeNodes) = v189.mStringHash32;
      if ( v189.mStringHash32 == -1 )
      {
        v139 = UFG::qStringHash32(v189.mData, 0xFFFFFFFF);
        LODWORD(p_mTerrainQuadTreeNodes) = v139;
        v189.mStringHash32 = v139;
      }
      v140 = Illusion::Factory::NewBuffer(v189.mData, v139, v136, 0i64, v189.mData, 0i64, 0i64);
      dataa = (UFG::qResourceData *)v140;
      v140->mBufferType = 1;
      v140->mElementByteSize = 2;
      v140->mNumElements = v135;
      v141 = v140->mData.mOffset;
      if ( v141 )
        v142 = (char *)&v140->mData + v141;
      else
        v142 = 0i64;
      v143 = 0i64;
      v144 = 1;
      v145 = mData + 2;
      if ( mData != -2 )
      {
        do
        {
          v146 = (v144 + mData * ((v132 >> 1) & 1)) * (v138 + 5);
          v147 = (v138 + 5) * (v144 + mData * ((v132 >> 1) & 1) + 1);
          v148 = mData * (v132 & 1) + 1;
          v149 = v145;
          do
          {
            *(_WORD *)&v142[2 * v143] = v146 + v148;
            v150 = (unsigned int)(v143 + 1);
            *(_WORD *)&v142[2 * v150] = v147 + v148 + 1;
            v151 = (unsigned int)(v150 + 1);
            *(_WORD *)&v142[2 * v151] = v147 + v148;
            v152 = (unsigned int)(v151 + 1);
            *(_WORD *)&v142[2 * v152] = v146 + v148;
            v153 = (unsigned int)(v152 + 1);
            *(_WORD *)&v142[2 * v153] = v146 + v148 + 1;
            v154 = (unsigned int)(v153 + 1);
            *(_WORD *)&v142[2 * v154] = v147 + v148 + 1;
            v143 = (unsigned int)(v154 + 1);
            ++v148;
            --v149;
          }
          while ( v149 );
          ++v144;
          v145 = mData + 2;
          v138 = v181;
        }
        while ( v144 <= mData + 2 );
        v137 = v188.mData;
        v135 = (int)v204;
      }
      v155 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v155, dataa);
      *(_DWORD *)(*(_QWORD *)v137 + 88i64) = (_DWORD)p_mTerrainQuadTreeNodes;
      UFG::qString::~qString(&v189);
      ++v132;
      v137 += 8;
      v188.mData = v137;
      v138 = v181;
      v136 = 2 * v135;
    }
    while ( v132 < 4 );
    UFG::qString::FormatEx(&v191, "DX10TerrainPatchModel.IndexBuffer_FULL_%d", v182);
    v156 = v191.mStringHash32;
    LODWORD(p_mTerrainQuadTreeNodes) = v191.mStringHash32;
    v157 = HIDWORD(v188.mPrev);
    if ( v191.mStringHash32 == -1 )
    {
      v156 = UFG::qStringHash32(v191.mData, 0xFFFFFFFF);
      LODWORD(p_mTerrainQuadTreeNodes) = v156;
      v191.mStringHash32 = v156;
    }
    v158 = 6 * v188.mMagic;
    v159 = Illusion::Factory::NewBuffer(v191.mData, v156, 12 * v188.mMagic, 0i64, v191.mData, 0i64, 0i64);
    v204 = (UFG::qResourceData *)v159;
    v159->mBufferType = 1;
    v159->mElementByteSize = 2;
    v159->mNumElements = v158;
    v160 = v159->mData.mOffset;
    if ( v160 )
      v161 = (char *)&v159->mData + v160;
    else
      v161 = 0i64;
    v162 = 0i64;
    for ( i = 1; i <= v157; ++i )
    {
      v164 = 1;
      v165 = i * (v181 + 5);
      v166 = (v181 + 5) * (i + 1);
      v167 = v166 + 1;
      do
      {
        *(_WORD *)&v161[2 * v162] = v164 + v165;
        v168 = (unsigned int)(v162 + 1);
        *(_WORD *)&v161[2 * v168] = v164 + v167;
        v169 = (unsigned int)(v168 + 1);
        *(_WORD *)&v161[2 * v169] = v164 + v166;
        v170 = (unsigned int)(v169 + 1);
        *(_WORD *)&v161[2 * v170] = v164 + v165;
        v171 = (unsigned int)(v170 + 1);
        *(_WORD *)&v161[2 * v171] = v164 + v165 + 1;
        v172 = (unsigned int)(v171 + 1);
        *(_WORD *)&v161[2 * v172] = v164 + v167;
        v162 = (unsigned int)(v172 + 1);
        ++v164;
      }
      while ( v164 <= v157 );
    }
    v173 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v173, v204);
    *(_DWORD *)(v199 + 88) = (_DWORD)p_mTerrainQuadTreeNodes;
    UFG::qString::~qString(&v191);
    v174 = 0;
    v175 = v201;
    v2 = v202;
    v176 = (unsigned int *)v187;
    do
    {
      v177 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Add(v177, (UFG::qResourceData *)*v175);
      v178 = *v176;
      v179 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v180 = UFG::qResourceWarehouse::Instance();
        v179 = UFG::qResourceWarehouse::GetInventory(v180, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v179;
      }
      UFG::qResourceHandle::Init(
        &v2->mDX10TerrainModelHandles[(unsigned __int64)v187 / 5][v174++],
        0xA2ADCD77,
        v178,
        v179);
      ++v176;
      ++v175;
    }
    while ( v174 < 5 );
    v34 = v182 + 1;
    v182 = v34;
    v35 = ++*(_QWORD *)&v188.mStringHash32;
  }
  while ( (int)v34 < 2 );
}

// File Line: 491
// RVA: 0x31110
void __fastcall UFG::RenderStageTerrain::Shutdown(UFG::RenderStageTerrain *this)
{
  float *p; // rcx
  unsigned int i; // edi
  __int64 v4; // rsi
  CullInfo *mCullInfo; // rbp
  CullManager *v6; // rax
  UFG::qHashMap<Render::TerrainData,0> *mTerrainDataMap; // r8
  unsigned int mUsedCount; // eax
  UFG::qHashMapBase::Entry *mTable; // rcx
  void **p_value; // rdx
  UFG::qHashMap<Render::TerrainData,0> *v11; // rdi
  UFG::TerrainRenderNode *v12; // rcx
  unsigned int j; // edi
  __int64 v14; // rsi
  UFG::TerrainQuadTreeNode *v15; // rcx
  UFG::TerrainQuadTreeNode **v16; // rcx

  this->mRenderTerrain = 0;
  p = this->mLODRanges.p;
  if ( p )
    operator delete[](p);
  this->mLODRanges.p = 0i64;
  *(_QWORD *)&this->mLODRanges.size = 0i64;
  for ( i = 0; i < this->mNumTerrainQuadTreeNodes; ++i )
  {
    v4 = i;
    mCullInfo = this->mTerrainQuadTreeNodes.p[v4].mCullInfo;
    if ( mCullInfo )
    {
      v6 = CullManager::Instance();
      CullManager::FreePersistentCullInfo(v6, this->mTerrainQuadTreeNodes.p[v4].mCullResults, mCullInfo);
    }
  }
  mTerrainDataMap = this->mTerrainDataMap;
  if ( mTerrainDataMap )
  {
    mUsedCount = mTerrainDataMap->mUsedCount;
    mTable = mTerrainDataMap->mTable;
    if ( mUsedCount )
    {
      p_value = &mTable->value;
      do
      {
        if ( *p_value )
          --mUsedCount;
        p_value += 2;
      }
      while ( mUsedCount );
    }
    *(_QWORD *)&mTerrainDataMap->mFillCount = 0i64;
    UFG::qMemSet(mTable, 0, 16 * (mTerrainDataMap->mMask + 1));
    v11 = this->mTerrainDataMap;
    if ( v11 )
    {
      UFG::qMemoryPool::Free(v11->mPool, v11->mTable);
      operator delete[](v11);
    }
    this->mTerrainDataMap = 0i64;
  }
  this->mTerrainQuadTreeNodes.size = 0;
  this->mNumTerrainQuadTreeNodes = 0;
  v12 = this->mTerrainRenderNodes.p;
  if ( v12 )
    operator delete[](v12);
  this->mTerrainRenderNodes.p = 0i64;
  *(_QWORD *)&this->mTerrainRenderNodes.size = 0i64;
  for ( j = 0; j < this->mActiveTerrainNodes.size; ++j )
  {
    v14 = j;
    v15 = this->mActiveTerrainNodes.p[v14];
    if ( v15 )
    {
      UFG::DataStreamer::ReleaseStream(&v15->mStream);
      this->mActiveTerrainNodes.p[v14] = 0i64;
    }
  }
  v16 = this->mActiveTerrainNodes.p;
  if ( v16 )
    operator delete[](v16);
  this->mActiveTerrainNodes.p = 0i64;
  *(_QWORD *)&this->mActiveTerrainNodes.size = 0i64;
}

// File Line: 530
// RVA: 0x312B0
void __fastcall UFG::RenderStageTerrain::Startup(UFG::RenderStageTerrain *this)
{
  unsigned int v2; // ebx
  unsigned int capacity; // edx
  unsigned int v4; // edx
  unsigned int i; // edx
  UFG::qString result; // [rsp+48h] [rbp-40h] BYREF

  if ( UFG::RenderStageTerrain::msTerrainVramSize )
  {
    v2 = this->mActiveTerrainNodes.size + UFG::RenderStageTerrain::msMaxTerrainElements;
    capacity = this->mActiveTerrainNodes.capacity;
    if ( v2 > capacity )
    {
      if ( capacity )
        v4 = 2 * capacity;
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
    this->mActiveTerrainNodes.size = v2;
    for ( i = 0; i < this->mActiveTerrainNodes.size; ++i )
      this->mActiveTerrainNodes.p[i] = 0i64;
    this->mNumTerrainQuadTreeNodes = 1;
    this->mTerrainQuadTreeNodes.size = 1;
    UFG::qMemSet(this->mTerrainQuadTreeNodes.p, 0, 0x110u);
    if ( this != (UFG::RenderStageTerrain *)-968i64 )
    {
      this->mTerrainQuadTreeNodes.p[0].mStream.mPrev = &this->mTerrainQuadTreeNodes.p[0].mStream;
      this->mTerrainQuadTreeNodes.p[0].mStream.mNext = &this->mTerrainQuadTreeNodes.p[0].mStream;
      this->mTerrainQuadTreeNodes.p[0].mStream.mCallback = 0i64;
      this->mTerrainQuadTreeNodes.p[0].mStream.mCallbackParam = 0i64;
      this->mTerrainQuadTreeNodes.p[0].mStream.mImpl = 0i64;
      *(_DWORD *)&this->mTerrainQuadTreeNodes.p[0].mStream.mFlags = 536870915;
      this->mTerrainQuadTreeNodes.p[0].mStream._mTargetState.mValue = 1;
    }
    *this->mActiveTerrainNodes.p = this->mTerrainQuadTreeNodes.p;
    UFG::qString::FormatEx(
      &result,
      "data\\world\\%s\\terrain\\terrainnode_l0_x0_y0\\terrainnode_l0_x0_y0.perm.bin",
      stru_1423AA4A8.mData);
    UFG::DataStreamer::QueueStream(
      &(*this->mActiveTerrainNodes.p)->mStream,
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
  __int64 mOffset; // rax
  _WORD *v4; // rsi
  char *v5; // rdx
  __int64 mNumLevels; // r12
  unsigned int v7; // ebx
  unsigned int capacity; // edx
  unsigned int v9; // edx
  unsigned int v10; // ebx
  int v11; // ecx
  __int64 v12; // rdx
  __int64 v13; // r8
  __m128 x_low; // xmm0
  char *v15; // rax
  UFG::qHashMap<Render::TerrainData,0> *v16; // rdi
  unsigned int v17; // edi
  unsigned __int64 v18; // rax
  char *v19; // rbx
  unsigned int i; // r8d
  __int64 v21; // rdx
  UFG::TerrainRenderNode *p; // rcx
  unsigned int v23; // ebx
  unsigned int v24; // r13d
  int j; // edx
  unsigned int grid_y; // eax
  unsigned int v27; // r8d
  unsigned int grid_x; // r15d
  __int64 v29; // r12
  UFG::qVector3 *p_mAABBMin; // rdi
  float v31; // xmm1_4
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector4 v34; // xmm1
  UFG::qVector4 v35; // xmm2
  UFG::qVector4 v36; // xmm3
  UFG::DataStreamer::Handle *p_mStream; // rax
  int v38; // r8d
  int v39; // r9d
  int v40; // r11d
  int v41; // r10d
  unsigned int v42; // edi
  int v43; // ecx
  unsigned int v44; // eax
  __int64 v45; // rdx
  int v46; // ecx
  unsigned int mDiffuseTextureUID; // r8d
  Illusion::Material *mTerrainMaterial; // rbx
  __int64 v49; // rax
  _WORD *v50; // rax
  unsigned int mNormalDisplaceSpecTextureUID; // r8d
  Illusion::Material *v52; // rbx
  __int64 v53; // rax
  _WORD *v54; // rax
  unsigned int v55; // r8d
  Illusion::Material *v56; // rbx
  __int64 v57; // rax
  _WORD *v58; // rax
  unsigned int v59; // r8d
  Illusion::Material *v60; // rbx
  __int64 v61; // rax
  _WORD *v62; // rax
  unsigned int v63; // r8d
  Illusion::Material *v64; // rbx
  __int64 v65; // rax
  _WORD *v66; // rax
  unsigned int v67; // r8d
  Illusion::Material *v68; // rbx
  __int64 v69; // rax
  _WORD *v70; // rax
  unsigned int v71; // r8d
  Illusion::Material *mDX10TerrainMaterial; // rbx
  __int64 v73; // rax
  _WORD *v74; // rax
  unsigned int v75; // r8d
  Illusion::Material *v76; // rbx
  __int64 v77; // rax
  _WORD *v78; // rax
  unsigned int v79; // r8d
  Illusion::Material *v80; // rbx
  __int64 v81; // rax
  _WORD *v82; // rax
  unsigned int v83; // r8d
  Illusion::Material *v84; // rbx
  __int64 v85; // rax
  _WORD *v86; // rax
  unsigned int v87; // r8d
  Illusion::Material *v88; // rbx
  __int64 v89; // rax
  _WORD *v90; // rax
  unsigned int v91; // r8d
  Illusion::Material *v92; // rbx
  __int64 v93; // rax
  UFG::qVector3 scale; // [rsp+48h] [rbp-41h] BYREF
  UFG::qMatrix44 dest; // [rsp+60h] [rbp-29h] BYREF
  unsigned int v96; // [rsp+F0h] [rbp+67h]
  int v97; // [rsp+F8h] [rbp+6Fh]
  unsigned int v98; // [rsp+100h] [rbp+77h]
  int v99; // [rsp+108h] [rbp+7Fh]

  mOffset = pRootNode->mTerrainDefinition.mOffset;
  v4 = 0i64;
  if ( mOffset )
    v5 = (char *)&pRootNode->mTerrainDefinition + mOffset;
  else
    v5 = 0i64;
  UFG::qMemCopy(&this->mTerrainParams, v5, 0x88u);
  this->mRenderTerrain = 1;
  mNumLevels = this->mTerrainParams.mNumLevels;
  v99 = mNumLevels;
  v7 = mNumLevels + this->mLODRanges.size;
  capacity = this->mLODRanges.capacity;
  if ( v7 > capacity )
  {
    if ( capacity )
      v9 = 2 * capacity;
    else
      v9 = 1;
    for ( ; v9 < v7; v9 *= 2 )
      ;
    if ( v9 <= 4 )
      v9 = 4;
    if ( v9 - v7 > 0x10000 )
      v9 = v7 + 0x10000;
    UFG::qArray<float,0>::Reallocate(&this->mLODRanges, v9, "qArray.Reallocate(Grow)");
  }
  this->mLODRanges.size = v7;
  v10 = 0;
  v11 = 1;
  if ( (_DWORD)mNumLevels )
  {
    v12 = 0i64;
    v13 = mNumLevels;
    do
    {
      v10 += v11 * v11;
      x_low = (__m128)LODWORD(this->mTerrainParams.mDimensions.x);
      x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) * 2.0;
      this->mLODRanges.p[v12] = _mm_sqrt_ps(x_low).m128_f32[0] / (float)v11;
      v11 = __ROL4__(v11, 1);
      ++v12;
      --v13;
    }
    while ( v13 );
  }
  this->mNumTerrainQuadTreeNodes = v10;
  this->mTerrainQuadTreeNodes.size = v10;
  v15 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
  v16 = (UFG::qHashMap<Render::TerrainData,0> *)v15;
  if ( v15 )
    UFG::qHashMapBase::qHashMapBase((UFG::qHashMapBase *)v15, UFG::gMainMemoryPool, 16 * v10);
  else
    v16 = 0i64;
  this->mTerrainDataMap = v16;
  v17 = 36 * mNumLevels;
  if ( (unsigned int)(36 * mNumLevels) > this->mTerrainRenderNodes.capacity && v17 != this->mTerrainRenderNodes.size )
  {
    v18 = 24i64 * v17;
    if ( !is_mul_ok(v17, 0x18ui64) )
      v18 = -1i64;
    v19 = UFG::qMalloc(v18, "qArray.Reallocate(Reserve)", 0i64);
    if ( this->mTerrainRenderNodes.p )
    {
      for ( i = 0; i < this->mTerrainRenderNodes.size; ++i )
      {
        v21 = 3i64 * i;
        p = this->mTerrainRenderNodes.p;
        *(_QWORD *)&v19[8 * v21] = p[i].mTreeNode;
        *(_QWORD *)&v19[8 * v21 + 8] = *(_QWORD *)&p[i].mTerrainDataUID;
        *(_QWORD *)&v19[8 * v21 + 16] = *(_QWORD *)&p[i].mQuadrantBits;
      }
      operator delete[](this->mTerrainRenderNodes.p);
    }
    this->mTerrainRenderNodes.p = (UFG::TerrainRenderNode *)v19;
    this->mTerrainRenderNodes.capacity = v17;
  }
  v23 = 0;
  v97 = 0;
  v24 = 0;
  for ( j = 1; v24 < (unsigned int)mNumLevels; j = __ROL4__(j, 1) )
  {
    grid_y = 0;
    v96 = 0;
    if ( j )
    {
      j = __ROL4__(1, v24);
      v98 = j;
      v27 = 1 << v24;
      do
      {
        grid_x = 0;
        if ( v27 )
        {
          do
          {
            v29 = v23;
            this->mTerrainQuadTreeNodes.p[v29].mUID = v23;
            this->mTerrainQuadTreeNodes.p[v29].mLevel = v24;
            this->mTerrainQuadTreeNodes.p[v29].mX = grid_x;
            this->mTerrainQuadTreeNodes.p[v29].mY = grid_y;
            this->mTerrainQuadTreeNodes.p[v29].mAssignedTerrainDataUIDs.size = 0;
            *(_DWORD *)&this->mTerrainQuadTreeNodes.p[v29].mTransparencyTarget = 0;
            p_mAABBMin = &this->mTerrainQuadTreeNodes.p[v29].mAABBMin;
            UFG::RenderStageTerrain::GetAABB(
              this,
              p_mAABBMin,
              &this->mTerrainQuadTreeNodes.p[v29].mAABBMax,
              v24,
              grid_x,
              grid_y);
            dest = UFG::qMatrix44::msIdentity;
            v31 = this->mTerrainQuadTreeNodes.p[v29].mAABBMax.y - p_mAABBMin->y;
            scale.x = this->mTerrainQuadTreeNodes.p[v29].mAABBMax.x - p_mAABBMin->x;
            scale.y = v31;
            scale.z = 1.0;
            UFG::qScaleMatrix(&dest, &scale);
            y = p_mAABBMin->y;
            z = p_mAABBMin->z;
            dest.v3.x = p_mAABBMin->x;
            dest.v3.y = y;
            dest.v3.z = z;
            dest.v3.w = 1.0;
            v34 = dest.v1;
            v35 = dest.v2;
            v36 = dest.v3;
            this->mTerrainQuadTreeNodes.p[v29].mTransform.v0 = dest.v0;
            this->mTerrainQuadTreeNodes.p[v29].mTransform.v1 = v34;
            this->mTerrainQuadTreeNodes.p[v29].mTransform.v2 = v35;
            this->mTerrainQuadTreeNodes.p[v29].mTransform.v3 = v36;
            this->mTerrainQuadTreeNodes.p[v29].mCullInfo = 0i64;
            this->mTerrainQuadTreeNodes.p[v29].mCullResults = 0i64;
            if ( v97 )
            {
              p_mStream = &this->mTerrainQuadTreeNodes.p[v29].mStream;
              if ( p_mStream )
              {
                p_mStream->mPrev = p_mStream;
                p_mStream->mNext = p_mStream;
                p_mStream->mCallback = 0i64;
                p_mStream->mCallbackParam = 0i64;
                p_mStream->mImpl = 0i64;
                *(_DWORD *)&p_mStream->mFlags = 536870915;
                p_mStream->_mTargetState.mValue = 1;
              }
            }
            if ( v24 == v99 - 1 )
              UFG::qMemSet(this->mTerrainQuadTreeNodes.p[v29].mChildren, 0, 0x20u);
            if ( v97 )
            {
              v38 = 0;
              v39 = 0;
              v40 = __ROR4__(v98, 1);
              v41 = 0;
              v42 = 0;
              v43 = 1;
              if ( (int)(v24 - 1) >= 2 )
              {
                v44 = ((v24 - 3) >> 1) + 1;
                v45 = v44;
                v42 = 2 * v44;
                do
                {
                  v38 += v43 * v43;
                  v46 = __ROL4__(v43, 1);
                  v39 += v46 * v46;
                  v43 = __ROL4__(v46, 1);
                  --v45;
                }
                while ( v45 );
              }
              if ( v42 < v24 - 1 )
                v41 = v43 * v43;
              *((_QWORD *)&this->mTerrainQuadTreeNodes.p[v41 + v38 + v39 + v40 * (v96 >> 1) + (grid_x >> 1)].mChildren[2 * (v96 & 1)]
              + (grid_x & 1)) = &this->mTerrainQuadTreeNodes.p[v29];
            }
            v23 = ++v97;
            ++grid_x;
            j = v98;
            grid_y = v96;
          }
          while ( grid_x < v98 );
          v27 = 1 << v24;
          LODWORD(mNumLevels) = v99;
        }
        v96 = ++grid_y;
      }
      while ( grid_y < v27 );
    }
    ++v24;
  }
  mDiffuseTextureUID = this->mTerrainParams.mDetailMapParams[0].mDiffuseTextureUID;
  mTerrainMaterial = this->mTerrainMaterial;
  if ( LODWORD(mTerrainMaterial[3].mMaterialUser.mOffset) != mDiffuseTextureUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mTerrainMaterial[3].mStateBlockMask,
      (unsigned int)mTerrainMaterial[4].mNode.mParent,
      mDiffuseTextureUID);
    v49 = mTerrainMaterial->mMaterialUser.mOffset;
    if ( v49 )
      v50 = (_WORD *)((char *)&mTerrainMaterial->mMaterialUser + v49);
    else
      v50 = 0i64;
    *v50 |= 0x20u;
  }
  mNormalDisplaceSpecTextureUID = this->mTerrainParams.mDetailMapParams[0].mNormalDisplaceSpecTextureUID;
  v52 = this->mTerrainMaterial;
  if ( v52[4].mTypeUID != mNormalDisplaceSpecTextureUID )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v52[4].mNode.mUID,
      *(_DWORD *)&v52[4].mDebugName[4],
      mNormalDisplaceSpecTextureUID);
    v53 = v52->mMaterialUser.mOffset;
    if ( v53 )
      v54 = (_WORD *)((char *)&v52->mMaterialUser + v53);
    else
      v54 = 0i64;
    *v54 |= 0x20u;
  }
  v55 = this->mTerrainParams.mDetailMapParams[1].mDiffuseTextureUID;
  v56 = this->mTerrainMaterial;
  if ( LODWORD(v56[4].mStateBlockMask.mFlags[1]) != v55 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v56[4].mDebugName[28], v56[4].mNumParams, v55);
    v57 = v56->mMaterialUser.mOffset;
    if ( v57 )
      v58 = (_WORD *)((char *)&v56->mMaterialUser + v57);
    else
      v58 = 0i64;
    *v58 |= 0x20u;
  }
  v59 = this->mTerrainParams.mDetailMapParams[1].mNormalDisplaceSpecTextureUID;
  v60 = this->mTerrainMaterial;
  if ( LODWORD(v60[5].mResourceHandles.UFG::qResourceData::mNode.mPrev) != v59 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)v60[5].mNode.mChild,
      (unsigned int)v60[5].mResourceHandles.UFG::qResourceData::mNode.mNext,
      v59);
    v61 = v60->mMaterialUser.mOffset;
    if ( v61 )
      v62 = (_WORD *)((char *)&v60->mMaterialUser + v61);
    else
      v62 = 0i64;
    *v62 |= 0x20u;
  }
  v63 = this->mTerrainParams.mDetailMapParams[2].mDiffuseTextureUID;
  v64 = this->mTerrainMaterial;
  if ( *((_DWORD *)&v64[5].UFG::qResourceData + 22) != v63 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v64[5].mDebugName[12], v64[5].mStateBlockMask.mFlags[0], v63);
    v65 = v64->mMaterialUser.mOffset;
    if ( v65 )
      v66 = (_WORD *)((char *)&v64->mMaterialUser + v65);
    else
      v66 = 0i64;
    *v66 |= 0x20u;
  }
  v67 = this->mTerrainParams.mDetailMapParams[2].mNormalDisplaceSpecTextureUID;
  v68 = this->mTerrainMaterial;
  if ( LODWORD(v68[6].mNode.mChild[1]) != v67 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v68[5].mMaterialUser, v68[6].mNode.mUID, v67);
    v69 = v68->mMaterialUser.mOffset;
    if ( v69 )
      v70 = (_WORD *)((char *)&v68->mMaterialUser + v69);
    else
      v70 = 0i64;
    *v70 |= 0x20u;
  }
  v71 = this->mTerrainParams.mDetailMapParams[0].mDiffuseTextureUID;
  mDX10TerrainMaterial = this->mDX10TerrainMaterial;
  if ( LODWORD(mDX10TerrainMaterial[3].mMaterialUser.mOffset) != v71 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&mDX10TerrainMaterial[3].mStateBlockMask,
      (unsigned int)mDX10TerrainMaterial[4].mNode.mParent,
      v71);
    v73 = mDX10TerrainMaterial->mMaterialUser.mOffset;
    if ( v73 )
      v74 = (_WORD *)((char *)&mDX10TerrainMaterial->mMaterialUser + v73);
    else
      v74 = 0i64;
    *v74 |= 0x20u;
  }
  v75 = this->mTerrainParams.mDetailMapParams[0].mNormalDisplaceSpecTextureUID;
  v76 = this->mDX10TerrainMaterial;
  if ( v76[4].mTypeUID != v75 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v76[4].mNode.mUID, *(_DWORD *)&v76[4].mDebugName[4], v75);
    v77 = v76->mMaterialUser.mOffset;
    if ( v77 )
      v78 = (_WORD *)((char *)&v76->mMaterialUser + v77);
    else
      v78 = 0i64;
    *v78 |= 0x20u;
  }
  v79 = this->mTerrainParams.mDetailMapParams[1].mDiffuseTextureUID;
  v80 = this->mDX10TerrainMaterial;
  if ( LODWORD(v80[4].mStateBlockMask.mFlags[1]) != v79 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v80[4].mDebugName[28], v80[4].mNumParams, v79);
    v81 = v80->mMaterialUser.mOffset;
    if ( v81 )
      v82 = (_WORD *)((char *)&v80->mMaterialUser + v81);
    else
      v82 = 0i64;
    *v82 |= 0x20u;
  }
  v83 = this->mTerrainParams.mDetailMapParams[1].mNormalDisplaceSpecTextureUID;
  v84 = this->mDX10TerrainMaterial;
  if ( LODWORD(v84[5].mResourceHandles.UFG::qResourceData::mNode.mPrev) != v83 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)v84[5].mNode.mChild,
      (unsigned int)v84[5].mResourceHandles.UFG::qResourceData::mNode.mNext,
      v83);
    v85 = v84->mMaterialUser.mOffset;
    if ( v85 )
      v86 = (_WORD *)((char *)&v84->mMaterialUser + v85);
    else
      v86 = 0i64;
    *v86 |= 0x20u;
  }
  v87 = this->mTerrainParams.mDetailMapParams[2].mDiffuseTextureUID;
  v88 = this->mDX10TerrainMaterial;
  if ( *((_DWORD *)&v88[5].UFG::qResourceData + 22) != v87 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v88[5].mDebugName[12], v88[5].mStateBlockMask.mFlags[0], v87);
    v89 = v88->mMaterialUser.mOffset;
    if ( v89 )
      v90 = (_WORD *)((char *)&v88->mMaterialUser + v89);
    else
      v90 = 0i64;
    *v90 |= 0x20u;
  }
  v91 = this->mTerrainParams.mDetailMapParams[2].mNormalDisplaceSpecTextureUID;
  v92 = this->mDX10TerrainMaterial;
  if ( LODWORD(v92[6].mNode.mChild[1]) != v91 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v92[5].mMaterialUser, v92[6].mNode.mUID, v91);
    v93 = v92->mMaterialUser.mOffset;
    if ( v93 )
      v4 = (_WORD *)((char *)&v92->mMaterialUser + v93);
    *v4 |= 0x20u;
  }
}

// File Line: 744
// RVA: 0x30690
__int64 __fastcall UFG::RenderStageTerrain::GetQuadTreeNodeIndex(
        UFG::RenderStageTerrain *this,
        int level,
        unsigned int grid_x,
        unsigned int grid_y)
{
  int v4; // r11d
  int v6; // ebx
  int v7; // edi
  unsigned int v8; // ebp
  int v9; // eax
  unsigned int v10; // ecx
  __int64 v11; // rdx
  int v12; // ecx
  int v13; // eax

  v4 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 1;
  if ( level >= 2 )
  {
    v10 = ((unsigned int)(level - 2) >> 1) + 1;
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
  if ( v8 < level )
    v7 = v9 * v9;
  return grid_x + v7 + v4 + v6 + grid_y * (1 << level);
}

// File Line: 759
// RVA: 0x304F0
void __fastcall UFG::RenderStageTerrain::GetAABB(
        UFG::RenderStageTerrain *this,
        UFG::qVector3 *out_min,
        UFG::qVector3 *out_max,
        char level,
        signed int grid_x,
        signed int grid_y)
{
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4

  out_min->z = 0.0;
  v6 = 1.0 / (float)(1 << level);
  out_min->x = (float)((float)grid_x * v6) - 0.5;
  out_min->y = (float)((float)grid_y * v6) - 0.5;
  out_max->z = 1.0;
  out_max->x = (float)((float)(grid_x + 1) * v6) - 0.5;
  out_max->y = (float)((float)(grid_y + 1) * v6) - 0.5;
  v7 = this->mTerrainParams.mDimensions.z * out_min->z;
  v8 = out_min->x * this->mTerrainParams.mDimensions.x;
  out_min->y = out_min->y * this->mTerrainParams.mDimensions.y;
  out_min->z = v7;
  out_min->x = v8;
  v9 = this->mTerrainParams.mDimensions.z * out_max->z;
  v10 = out_max->y * this->mTerrainParams.mDimensions.y;
  out_max->x = this->mTerrainParams.mDimensions.x * out_max->x;
  out_max->z = v9;
  out_max->y = v10;
  v11 = this->mTerrainParams.mOrigin.z + out_min->z;
  v12 = out_min->x + this->mTerrainParams.mOrigin.x;
  out_min->y = this->mTerrainParams.mOrigin.y + out_min->y;
  out_min->z = v11;
  out_min->x = v12;
  v13 = this->mTerrainParams.mOrigin.z + out_max->z;
  v14 = out_max->x + this->mTerrainParams.mOrigin.x;
  out_max->y = this->mTerrainParams.mOrigin.y + out_max->y;
  out_max->z = v13;
  out_max->x = v14;
}

// File Line: 778
// RVA: 0x30330
void __fastcall UFG::RenderStageTerrain::AddTerrainData(
        UFG::RenderStageTerrain *this,
        Render::TerrainData *pTerrainData)
{
  __int64 QuadTreeNodeIndex; // rbp
  char *v5; // rdx
  CullInfo **v6; // r14
  __int64 size; // rcx
  CullManager *v8; // rax
  CullInfo *v9; // rcx
  float y; // xmm0_4
  float z; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4

  if ( !this->mRenderTerrain )
    UFG::RenderStageTerrain::Instantiate(this, pTerrainData);
  UFG::qHashMapBase::Set(this->mTerrainDataMap, pTerrainData->mUID, pTerrainData);
  QuadTreeNodeIndex = UFG::RenderStageTerrain::GetQuadTreeNodeIndex(
                        this,
                        pTerrainData->mLevel,
                        pTerrainData->mGridLocationX,
                        pTerrainData->mGridLocationY);
  v5 = (char *)this + QuadTreeNodeIndex * 272;
  v6 = (CullInfo **)((char *)this + QuadTreeNodeIndex * 272);
  size = this->mTerrainQuadTreeNodes.p[QuadTreeNodeIndex].mAssignedTerrainDataUIDs.size;
  *((_DWORD *)v5 + 198) = size + 1;
  *(_DWORD *)&v5[4 * size + 796] = pTerrainData->mUID;
  if ( !this->mTerrainQuadTreeNodes.p[QuadTreeNodeIndex].mCullInfo )
  {
    v8 = CullManager::Instance();
    CullManager::AllocPersistentCullInfo(
      v8,
      &this->mTerrainQuadTreeNodes.p[QuadTreeNodeIndex].mCullResults,
      v6 + 119,
      0i64,
      0i64,
      0i64);
    v9 = v6[119];
    v9->mpLocalWorld = 0i64;
    *(_DWORD *)&v9->mIsLocalWorldIdentity = 0;
    *(_DWORD *)&v9->mPixelScaleBias = -130072;
    y = this->mTerrainQuadTreeNodes.p[QuadTreeNodeIndex].mAABBMin.y;
    z = this->mTerrainQuadTreeNodes.p[QuadTreeNodeIndex].mAABBMin.z;
    v9->mAABBMin[0] = this->mTerrainQuadTreeNodes.p[QuadTreeNodeIndex].mAABBMin.x;
    v9->mAABBMin[1] = y;
    v9->mAABBMin[2] = z;
    v12 = this->mTerrainQuadTreeNodes.p[QuadTreeNodeIndex].mAABBMax.y;
    v13 = this->mTerrainQuadTreeNodes.p[QuadTreeNodeIndex].mAABBMax.z;
    v9->mAABBMax[0] = this->mTerrainQuadTreeNodes.p[QuadTreeNodeIndex].mAABBMax.x;
    v9->mAABBMax[1] = v12;
    v9->mAABBMax[2] = v13;
  }
  if ( this->mTerrainParams.mNumLevels - 1 == pTerrainData->mLevel )
  {
    if ( this->mAddTerrainDataPhysicsCallback )
      this->mAddTerrainDataPhysicsCallback(
        pTerrainData,
        &this->mTerrainParams,
        &this->mTerrainQuadTreeNodes.p[QuadTreeNodeIndex]);
  }
}

// File Line: 818
// RVA: 0x30F90
void __fastcall UFG::RenderStageTerrain::RemoveTerrainData(
        UFG::RenderStageTerrain *this,
        Render::TerrainData *pTerrainData)
{
  unsigned int QuadTreeNodeIndex; // eax
  __int64 v5; // rdx
  char *v6; // rbx
  unsigned int v7; // ecx
  _DWORD *v8; // rax
  __int64 v9; // rax
  CullInfo *v10; // rbp
  CullResults *v11; // r14
  CullManager *v12; // rax
  UFG::qHashMap<Render::TerrainData,0> *mTerrainDataMap; // rbx
  UFG::qHashMapBase::Entry *v14; // rax
  void (__fastcall *mRemoveTerrainDataPhysicsCallback)(Render::TerrainData *); // rax

  if ( this->mTerrainQuadTreeNodes.size )
  {
    QuadTreeNodeIndex = UFG::RenderStageTerrain::GetQuadTreeNodeIndex(
                          this,
                          pTerrainData->mLevel,
                          pTerrainData->mGridLocationX,
                          pTerrainData->mGridLocationY);
    v5 = 0i64;
    v6 = (char *)this + 272 * QuadTreeNodeIndex;
    v7 = *((_DWORD *)v6 + 198);
    if ( v7 )
    {
      v8 = v6 + 796;
      while ( pTerrainData->mUID != *v8 )
      {
        v5 = (unsigned int)(v5 + 1);
        ++v8;
        if ( (unsigned int)v5 >= v7 )
          goto LABEL_12;
      }
      if ( (int)v5 >= 0 )
      {
        v9 = v7 - 1;
        *((_DWORD *)v6 + 198) = v9;
        *(_DWORD *)&v6[4 * v5 + 796] = *(_DWORD *)&v6[4 * v9 + 796];
        if ( !*((_DWORD *)v6 + 198) )
        {
          v10 = (CullInfo *)*((_QWORD *)v6 + 119);
          if ( v10 )
          {
            v11 = (CullResults *)*((_QWORD *)v6 + 120);
            if ( v11 )
            {
              v12 = CullManager::Instance();
              CullManager::FreePersistentCullInfo(v12, v11, v10);
              *((_QWORD *)v6 + 120) = 0i64;
              *((_QWORD *)v6 + 119) = 0i64;
              *((_DWORD *)v6 + 215) = 0;
            }
          }
        }
      }
    }
LABEL_12:
    mTerrainDataMap = this->mTerrainDataMap;
    v14 = UFG::qHashMapBase::Lookup(mTerrainDataMap, pTerrainData->mUID);
    if ( v14->value )
    {
      v14->value = 0i64;
      --mTerrainDataMap->mUsedCount;
    }
    mRemoveTerrainDataPhysicsCallback = this->mRemoveTerrainDataPhysicsCallback;
    if ( mRemoveTerrainDataPhysicsCallback )
      mRemoveTerrainDataPhysicsCallback(pTerrainData);
  }
}

// File Line: 871
// RVA: 0x310E0
void __fastcall UFG::RenderStageTerrain::Render(
        UFG::RenderStageTerrain *this,
        UFG::RenderContext *render_context,
        Render::View *view)
{
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-78h] BYREF

  if ( this->mRenderTerrain )
  {
    Render::RenderOutputParams::RenderOutputParams(&outSettings);
    Render::GetCurrentDisplaySettings(&outSettings);
  }
}

