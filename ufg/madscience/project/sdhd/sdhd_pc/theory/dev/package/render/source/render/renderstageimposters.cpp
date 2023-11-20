// File Line: 64
// RVA: 0x2E450
void __fastcall UFG::RenderStageImposters::Create(UFG::RenderContext *render_context)
{
  UFG::RenderContext *v1; // rbx
  UFG::RenderStageImposters *v2; // rax

  v1 = render_context;
  v2 = (UFG::RenderStageImposters *)UFG::qMalloc(0x1A110ui64, "RenderStageImposters", 0i64);
  if ( v2 )
    UFG::RenderStageImposters::RenderStageImposters(v2, v1);
}

// File Line: 75
// RVA: 0x2E440
void __fastcall UFG::AddImposterGroup(Render::ImposterGroup *pGroup)
{
  UFG::RenderStageImposters::AddGroup(UFG::RenderWorld::msStageImposters, pGroup);
}

// File Line: 82
// RVA: 0x2E5F0
void __fastcall UFG::RemoveImposterGroup(Render::ImposterGroup *pGroup)
{
  UFG::RenderStageImposters::RemoveGroup(UFG::RenderWorld::msStageImposters, pGroup);
}

// File Line: 94
// RVA: 0x2D910
void __fastcall UFG::RenderStageImposters::RenderStageImposters(UFG::RenderStageImposters *this, UFG::RenderContext *render_context)
{
  UFG::RenderStageImposters *v2; // r15
  UFG::ImposterBucket *v3; // r14
  UFG::qHashMap<UFG::ImposterState,0> **v4; // rdi
  int *v5; // rsi
  signed __int64 v6; // rbp
  char *v7; // rax
  char *v8; // rbx
  unsigned int v9; // eax
  int v10; // edi
  Illusion::Material *v11; // rbx
  Illusion::Material *v12; // rbx
  Illusion::Material *v13; // rbx
  Illusion::Material *v14; // rbx
  Illusion::Material *v15; // rbx
  Illusion::Material *v16; // rbx
  Illusion::Material *v17; // rbx
  Illusion::Material *v18; // rbx
  UFG::qResourceWarehouse *v19; // rax
  unsigned int v20; // ebx
  UFG::qResourceInventory *v21; // rax
  UFG::qResourceWarehouse *v22; // rax

  v2 = this;
  v3 = this->mImposterGroupBuckets;
  `eh vector constructor iterator'(
    this->mImposterGroupBuckets,
    0x2404ui64,
    8,
    (void (__fastcall *)(void *))UFG::ImposterBucket::ImposterBucket);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mImposterModel.mPrev);
  v2->mRenderImposters = 1;
  v4 = v2->mImposterGroupStateMaps;
  v5 = v2->mImposterGroupTargets;
  v6 = 8i64;
  do
  {
    *(v4 - 9236) = 0i64;
    *(v5 - 8) = -1;
    *v5 = 0;
    v3->mImposterBucketArray.size = 0;
    v7 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
    v8 = v7;
    if ( v7 )
      UFG::qHashMapBase::qHashMapBase((UFG::qHashMapBase *)v7, UFG::gMainMemoryPool, 0x100u);
    else
      v8 = 0i64;
    *v4 = (UFG::qHashMap<UFG::ImposterState,0> *)v8;
    ++v5;
    ++v4;
    ++v3;
    --v6;
  }
  while ( v6 );
  Render::gImposterGroupInventory.mAddImposterGroupCallback = UFG::AddImposterGroup;
  Render::gImposterGroupInventory.mRemoveImposterGroupCallback = UFG::RemoveImposterGroup;
  v9 = UFG::qStringHashUpper32("RenderStageImpostersMaterial", 0xFFFFFFFF);
  v2->mFarGroundImposterMaterial = Illusion::Factory::NewMaterial(
                                     "RenderStageImpostersMaterial",
                                     v9,
                                     8u,
                                     0i64,
                                     0i64,
                                     0i64);
  v10 = UFG::qStringHashUpper32("DRFARGROUNDIMPOSTERS", 0xFFFFFFFF);
  v11 = v2->mFarGroundImposterMaterial;
  LOWORD(v11[1].mNode.mChild[0]) = 0;
  HIDWORD(v11[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(v11[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v11[1].mTypeUID = -1957338719;
  LODWORD(v11[1].mResourceHandles.mNode.mNext) = v10;
  v12 = v2->mFarGroundImposterMaterial;
  *(_WORD *)&v12[1].mDebugName[12] = 0;
  *(_DWORD *)&v12[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v12[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v12[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v12[1].mStateBlockMask.mFlags[0]) = 662883558;
  v13 = v2->mFarGroundImposterMaterial;
  LOWORD(v13[1].mMaterialUser.mOffset) = 0;
  *(&v13[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v13[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v13[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v13[2].mNode.mUID = 543723269;
  v14 = v2->mFarGroundImposterMaterial;
  LOWORD(v14[2].mTypeUID) = 0;
  HIDWORD(v14[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v14[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v14[2].0 + 22) = -1958479169;
  *(_DWORD *)&v14[2].mDebugName[28] = 0;
  v15 = v2->mFarGroundImposterMaterial;
  LOWORD(v15[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v15[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v15[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v15[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v15[3].mNode.mChild[0]) = 0;
  v16 = v2->mFarGroundImposterMaterial;
  LOWORD(v16[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v16[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v16[3].mNode.mUID = UFG::qStringHash32("texFadeDitherMask", 0xFFFFFFFF);
  *(_DWORD *)&v16[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v16[3].mDebugName[12] = 0;
  v17 = v2->mFarGroundImposterMaterial;
  *((_WORD *)&v17[3].0 + 44) = 0;
  *(_DWORD *)&v17[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v17[3].mDebugName[28] = UFG::qStringHash32("texEmission", 0xFFFFFFFF);
  LODWORD(v17[4].mNode.mParent) = -1958479169;
  LODWORD(v17[3].mMaterialUser.mOffset) = 0;
  v18 = v2->mFarGroundImposterMaterial;
  LOWORD(v18[4].mNode.mChild[1]) = 0;
  HIDWORD(v18[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v18[4].mNode.mChild[0]) = UFG::qStringHash32("texAmbient", 0xFFFFFFFF);
  *(_DWORD *)&v18[4].mDebugName[4] = -1958479169;
  v18[4].mTypeUID = 0;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, (UFG::qResourceData *)&v2->mFarGroundImposterMaterial->mNode);
  v20 = UFG::qStringHashUpper32("dr_imposter", 0xFFFFFFFF);
  v21 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v22 = UFG::qResourceWarehouse::Instance();
    v21 = UFG::qResourceWarehouse::GetInventory(v22, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v21;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mImposterModel.mPrev, 0xA2ADCD77, v20, v21);
}

// File Line: 140
// RVA: 0x2DD60
void __fastcall UFG::RenderStageImposters::AddGroup(UFG::RenderStageImposters *this, Render::ImposterGroup *pGroup)
{
  Render::ImposterGroup *v2; // r13
  signed int v3; // edx
  UFG::RenderStageImposters *v4; // r15
  unsigned int *v5; // rax
  int v6; // er8
  signed __int64 v7; // rbp
  __int64 v8; // rcx
  unsigned int v9; // er12
  unsigned int v10; // eax
  UFG::ImposterBucket *v11; // rsi
  __int64 v12; // rax
  signed __int64 v13; // rcx
  signed __int64 v14; // rbx
  __int64 v15; // rdi
  float *v16; // r14
  float *v17; // rax
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm5_4
  float v26; // xmm12_4
  float v27; // xmm14_4
  float v28; // xmm9_4
  float v29; // xmm4_4
  float v30; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  __int64 v34; // rcx
  CullInfo **v35; // rbx
  CullResults **v36; // rdi
  CullManager *v37; // rax
  CullInfo *v38; // rcx
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  signed __int64 v43; // r8
  float *v44; // rax
  float v45; // xmm2_4
  float v46; // xmm3_4
  float v47; // xmm4_4
  float v48; // xmm0_4
  float v49; // xmm2_4
  float v50; // xmm0_4
  float v51; // xmm3_4
  float v52; // xmm5_4
  float v53; // xmm12_4
  float v54; // xmm14_4
  float v55; // xmm9_4
  float v56; // xmm2_4
  float v57; // xmm0_4
  float v58; // xmm3_4
  float v59; // xmm1_4
  float v60; // xmm4_4
  float v61; // xmm7_4
  float v62; // xmm6_4
  float v63; // xmm2_4
  float v64; // xmm3_4
  float v65; // xmm2_4
  float v66; // xmm0_4
  float v67; // eax
  CullInfo *v68; // rdx
  float v69; // xmm0_4
  float v70; // xmm1_4
  float v71; // [rsp+30h] [rbp-F8h]
  float v72; // [rsp+34h] [rbp-F4h]
  float v73; // [rsp+38h] [rbp-F0h]
  float v74; // [rsp+38h] [rbp-F0h]
  float v75; // [rsp+3Ch] [rbp-ECh]
  __int64 v76; // [rsp+40h] [rbp-E8h]
  __int64 v77; // [rsp+48h] [rbp-E0h]
  float v78; // [rsp+140h] [rbp+18h]
  float v79; // [rsp+140h] [rbp+18h]
  float v80; // [rsp+140h] [rbp+18h]
  float v81; // [rsp+140h] [rbp+18h]
  signed int v82; // [rsp+148h] [rbp+20h]

  v2 = pGroup;
  v3 = -1;
  v4 = this;
  v5 = this->mImposterGroupSectionUIDs;
  v82 = -1;
  v6 = 0;
  v7 = 0i64;
  while ( *v5 != -1 )
  {
    ++v7;
    ++v6;
    ++v5;
    if ( v7 >= 8 )
      return;
  }
  v8 = v6;
  v9 = 0;
  v4->mImposterGroupPtrs[v8] = v2;
  v10 = v2->mNode.mUID;
  v4->mImposterGroupTargets[v8] = 0;
  v4->mImposterGroupSectionUIDs[v8] = v10;
  v76 = v6;
  if ( v2->mNumImposters > 0 )
  {
    v11 = &v4->mImposterGroupBuckets[v7];
    while ( 1 )
    {
      v12 = v2->mImposters.mOffset;
      v13 = (signed __int64)(v12 ? (UFG::qOffset64<Render::Imposter *> *)((char *)&v2->mImposters + v12) : 0i64);
      v14 = v13 + 96i64 * v9;
      if ( *(_DWORD *)(v14 + 80) != v3 )
        break;
      if ( v11->mImposterBucketArray.size )
      {
        v43 = v11->mImposterBucketArray.size - 1;
        v44 = (float *)v4->mImposterModel.mData;
        v45 = v44[23];
        v46 = v44[24];
        v80 = v44[22];
        v71 = (float)((float)((float)(v44[22] * *(float *)v14) + (float)(v44[23] * *(float *)(v14 + 16)))
                    + (float)(v44[24] * *(float *)(v14 + 32)))
            + *(float *)(v14 + 48);
        v47 = (float)((float)((float)(v80 * *(float *)(v14 + 4)) + (float)(v45 * *(float *)(v14 + 20)))
                    + (float)(v46 * *(float *)(v14 + 36)))
            + *(float *)(v14 + 52);
        v48 = (float)(v80 * *(float *)(v14 + 8)) + (float)(v45 * *(float *)(v14 + 24));
        v49 = v44[27];
        v50 = v48 + (float)(v46 * *(float *)(v14 + 40));
        v51 = v44[28];
        v81 = v50 + *(float *)(v14 + 56);
        v52 = v81;
        v74 = v44[26];
        v53 = (float)((float)((float)(v74 * *(float *)v14) + (float)(v49 * *(float *)(v14 + 16)))
                    + (float)(v44[28] * *(float *)(v14 + 32)))
            + *(float *)(v14 + 48);
        v54 = (float)((float)((float)(v74 * *(float *)(v14 + 8)) + (float)(v49 * *(float *)(v14 + 24)))
                    + (float)(v51 * *(float *)(v14 + 40)))
            + *(float *)(v14 + 56);
        v55 = (float)((float)((float)(v74 * *(float *)(v14 + 4)) + (float)(v44[27] * *(float *)(v14 + 20)))
                    + (float)(v51 * *(float *)(v14 + 36)))
            + *(float *)(v14 + 52);
        if ( v81 >= v54 )
          v56 = (float)((float)((float)(v74 * *(float *)(v14 + 8)) + (float)(v49 * *(float *)(v14 + 24)))
                      + (float)(v51 * *(float *)(v14 + 40)))
              + *(float *)(v14 + 56);
        else
          v56 = v50 + *(float *)(v14 + 56);
        v57 = v47;
        if ( v47 >= v55 )
          v58 = (float)((float)((float)(v74 * *(float *)(v14 + 4)) + (float)(v44[27] * *(float *)(v14 + 20)))
                      + (float)(v51 * *(float *)(v14 + 36)))
              + *(float *)(v14 + 52);
        else
          v58 = v47;
        v59 = (float)((float)((float)(v44[22] * *(float *)v14) + (float)(v44[23] * *(float *)(v14 + 16)))
                    + (float)(v44[24] * *(float *)(v14 + 32)))
            + *(float *)(v14 + 48);
        if ( v71 >= v53 )
          v60 = v53;
        else
          v60 = (float)((float)((float)(v44[22] * *(float *)v14) + (float)(v44[23] * *(float *)(v14 + 16)))
                      + (float)(v44[24] * *(float *)(v14 + 32)))
              + *(float *)(v14 + 48);
        v61 = v11->mImposterBucketArray.p[v11->mImposterBucketArray.size - 1].mAABBMin.z;
        if ( v61 >= v56 )
          v61 = v56;
        v62 = v11->mImposterBucketArray.p[v11->mImposterBucketArray.size - 1].mAABBMin.y;
        if ( v62 >= v58 )
          v62 = v58;
        v63 = v11->mImposterBucketArray.p[v11->mImposterBucketArray.size - 1].mAABBMin.x;
        if ( v63 >= v60 )
          v63 = v60;
        v11->mImposterBucketArray.p[v11->mImposterBucketArray.size - 1].mAABBMin.x = v63;
        v11->mImposterBucketArray.p[v43].mAABBMin.y = v62;
        v11->mImposterBucketArray.p[v43].mAABBMin.z = v61;
        if ( v81 <= v54 )
          v52 = v54;
        if ( v57 <= v55 )
          v57 = v55;
        if ( v71 <= v53 )
          v59 = v53;
        v64 = v11->mImposterBucketArray.p[v43].mAABBMax.z;
        if ( v64 <= v52 )
          v64 = v52;
        v65 = v11->mImposterBucketArray.p[v43].mAABBMax.y;
        if ( v65 <= v57 )
          v65 = v57;
        v66 = v11->mImposterBucketArray.p[v43].mAABBMax.x;
        if ( v66 <= v59 )
          v66 = v59;
        v11->mImposterBucketArray.p[v43].mAABBMax.x = v66;
        v11->mImposterBucketArray.p[v43].mAABBMax.y = v65;
        v11->mImposterBucketArray.p[v43].mAABBMax.z = v64;
        v67 = v11->mImposterBucketArray.p[v43].mAABBMin.x;
        v68 = v4->mImposterGroupCullInfo[0][(v7 << 8) + v11->mImposterBucketArray.size - 1];
        v68->mAABBMin[1] = v62;
        v68->mAABBMin[2] = v61;
        v68->mAABBMin[0] = v67;
        v69 = v11->mImposterBucketArray.p[v43].mAABBMax.y;
        v70 = v11->mImposterBucketArray.p[v43].mAABBMax.z;
        v68->mAABBMax[0] = v11->mImposterBucketArray.p[v43].mAABBMax.x;
        v68->mAABBMax[1] = v69;
        v68->mAABBMax[2] = v70;
        ++v11->mImposterBucketArray.p[v43].mCount;
        goto LABEL_56;
      }
LABEL_57:
      if ( ++v9 >= v2->mNumImposters )
        return;
    }
    v15 = v11->mImposterBucketArray.size;
    v82 = *(_DWORD *)(v14 + 80);
    v77 = v15;
    v16 = (float *)(&v11->mImposterBucketArray.size + 9 * v15);
    v11->mImposterBucketArray.size = v15 + 1;
    *((_DWORD *)v16 + 1) = v9;
    v16[2] = 0.0;
    v16[3] = 2.3509887e-38;
    UFG::qHashMapBase::Set((UFG::qHashMapBase *)&v4->mImposterGroupStateMaps[v7]->mPool, *(_DWORD *)(v14 + 80), v16 + 1);
    v17 = (float *)v4->mImposterModel.mData;
    v18 = v17[23];
    v19 = v17[24];
    v78 = v17[22];
    v75 = (float)((float)((float)(v17[22] * *(float *)v14) + (float)(v17[23] * *(float *)(v14 + 16)))
                + (float)(v17[24] * *(float *)(v14 + 32)))
        + *(float *)(v14 + 48);
    v20 = (float)((float)((float)(v78 * *(float *)(v14 + 4)) + (float)(v18 * *(float *)(v14 + 20)))
                + (float)(v19 * *(float *)(v14 + 36)))
        + *(float *)(v14 + 52);
    v21 = (float)(v78 * *(float *)(v14 + 8)) + (float)(v18 * *(float *)(v14 + 24));
    v22 = v17[27];
    v73 = v20;
    v23 = v21 + (float)(v19 * *(float *)(v14 + 40));
    v24 = v17[28];
    v79 = v23 + *(float *)(v14 + 56);
    v25 = v79;
    v72 = v17[26];
    v26 = (float)((float)((float)(v72 * *(float *)v14) + (float)(v22 * *(float *)(v14 + 16)))
                + (float)(v17[28] * *(float *)(v14 + 32)))
        + *(float *)(v14 + 48);
    v27 = (float)((float)((float)(v72 * *(float *)(v14 + 8)) + (float)(v22 * *(float *)(v14 + 24)))
                + (float)(v24 * *(float *)(v14 + 40)))
        + *(float *)(v14 + 56);
    v28 = (float)((float)((float)(v72 * *(float *)(v14 + 4)) + (float)(v17[27] * *(float *)(v14 + 20)))
                + (float)(v24 * *(float *)(v14 + 36)))
        + *(float *)(v14 + 52);
    if ( v79 >= v27 )
      v29 = (float)((float)((float)(v72 * *(float *)(v14 + 8)) + (float)(v22 * *(float *)(v14 + 24)))
                  + (float)(v24 * *(float *)(v14 + 40)))
          + *(float *)(v14 + 56);
    else
      v29 = v23 + *(float *)(v14 + 56);
    v30 = v73;
    if ( v73 >= v28 )
      v31 = (float)((float)((float)(v72 * *(float *)(v14 + 4)) + (float)(v17[27] * *(float *)(v14 + 20)))
                  + (float)(v24 * *(float *)(v14 + 36)))
          + *(float *)(v14 + 52);
    else
      v31 = v73;
    v32 = (float)((float)((float)(v17[22] * *(float *)v14) + (float)(v17[23] * *(float *)(v14 + 16)))
                + (float)(v17[24] * *(float *)(v14 + 32)))
        + *(float *)(v14 + 48);
    if ( v75 >= v26 )
      v33 = (float)((float)((float)(v72 * *(float *)v14) + (float)(v22 * *(float *)(v14 + 16)))
                  + (float)(v17[28] * *(float *)(v14 + 32)))
          + *(float *)(v14 + 48);
    else
      v33 = (float)((float)((float)(v17[22] * *(float *)v14) + (float)(v17[23] * *(float *)(v14 + 16)))
                  + (float)(v17[24] * *(float *)(v14 + 32)))
          + *(float *)(v14 + 48);
    v16[4] = v33;
    v16[5] = v31;
    v16[6] = v29;
    if ( v79 <= v27 )
      v25 = v27;
    if ( v73 <= v28 )
      v30 = v28;
    if ( v75 <= v26 )
      v32 = v26;
    v16[7] = v32;
    v16[8] = v30;
    v16[9] = v25;
    v34 = v15 + (v76 << 8);
    v35 = (CullInfo **)((char *)v4->mImposterGroupCullInfo + 8 * v34);
    v36 = (CullResults **)((char *)v4 + 8 * (v34 + 11298));
    v37 = CullManager::Instance();
    CullManager::AllocPersistentCullInfo(v37, v36, v35, 0i64, 0i64, 0i64);
    v38 = v4->mImposterGroupCullInfo[0][v77 + (v7 << 8)];
    v38->mpLocalWorld = 0i64;
    *(_DWORD *)&v38->mPixelScaleBias = -130072;
    *(_DWORD *)&v38->mIsLocalWorldIdentity = 0;
    v39 = v16[5];
    v40 = v16[6];
    v38->mAABBMin[0] = v16[4];
    v38->mAABBMin[1] = v39;
    v38->mAABBMin[2] = v40;
    v41 = v16[8];
    v42 = v16[9];
    v38->mAABBMax[0] = v16[7];
    v38->mAABBMax[1] = v41;
    v38->mAABBMax[2] = v42;
LABEL_56:
    v3 = v82;
    goto LABEL_57;
  }
}

// File Line: 218
// RVA: 0x2E4A0
void __fastcall UFG::RenderStageImposters::RemoveGroup(UFG::RenderStageImposters *this, Render::ImposterGroup *pGroup)
{
  Render::ImposterGroup *v2; // rax
  UFG::RenderStageImposters *v3; // r13
  UFG::ImposterBucket *v4; // r14
  UFG::qHashMap<UFG::ImposterState,0> **v5; // r12
  unsigned int *v6; // r15
  signed __int64 v7; // rbp
  unsigned int v8; // esi
  signed __int64 v9; // rcx
  signed __int64 v10; // rdi
  signed __int64 v11; // rbx
  CullManager *v12; // rax
  UFG::qHashMap<UFG::ImposterState,0> *v13; // r8
  unsigned int v14; // eax
  UFG::qHashMapBase::Entry *v15; // rcx
  void **v16; // rdx
  Render::ImposterGroup *v17; // [rsp+58h] [rbp+10h]

  v17 = pGroup;
  v2 = pGroup;
  v3 = this;
  v4 = this->mImposterGroupBuckets;
  v5 = this->mImposterGroupStateMaps;
  v6 = this->mImposterGroupSectionUIDs;
  v7 = 0i64;
  do
  {
    if ( *v6 == v2->mNode.mUID )
    {
      *(v5 - 9236) = 0i64;
      *v6 = -1;
      v8 = 0;
      if ( v4->mImposterBucketArray.size )
      {
        do
        {
          v9 = v7 + v8;
          v10 = v9;
          v11 = v9;
          v12 = CullManager::Instance();
          CullManager::FreePersistentCullInfo(
            v12,
            v3->mImposterGroupCullResults[0][v11],
            v3->mImposterGroupCullInfo[0][v10]);
          ++v8;
          v3->mImposterGroupCullResults[0][v11] = 0i64;
          v3->mImposterGroupCullInfo[0][v10] = 0i64;
        }
        while ( v8 < v4->mImposterBucketArray.size );
      }
      v13 = *v5;
      v14 = (*v5)->mUsedCount;
      v15 = (*v5)->mTable;
      if ( v14 )
      {
        v16 = &v15->value;
        do
        {
          if ( *v16 )
            --v14;
          v16 += 2;
        }
        while ( v14 );
      }
      *(_QWORD *)&v13->mFillCount = 0i64;
      UFG::qMemSet(v15, 0, 16 * (v13->mMask + 1));
      v4->mImposterBucketArray.size = 0;
    }
    v2 = v17;
    v7 += 256i64;
    ++v6;
    ++v5;
    ++v4;
  }
  while ( v7 < 2048 );
}

// File Line: 244
// RVA: 0x2EA70
void __fastcall UFG::RenderStageImposters::UpdateViews(UFG::RenderStageImposters *this, UFG::RenderContext *render_context, float fRealTimeDelta)
{
  UFG::RenderStageImposters *v3; // r14
  unsigned int v4; // eax
  unsigned int v5; // ebx
  char v6; // r13
  UFG::qResourceData *v7; // rdi
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceInventory *v9; // rcx
  signed int v10; // eax
  signed int v11; // edx
  int *v12; // rcx
  UFG::ImposterBucket *v13; // rbp
  Render::ImposterGroup **v14; // r15
  int *v15; // r12
  signed __int64 v16; // rdx
  signed __int64 v17; // rax
  __int64 v18; // rsi
  unsigned int *v19; // rdi
  unsigned int v20; // edx
  signed __int64 v21; // rax
  __int64 v22; // rcx
  signed __int64 v23; // rbx
  unsigned int v24; // ecx
  signed int v25; // er9
  BOOL v26; // er8
  int v27; // ecx
  int v28; // ebx
  int v29; // er10
  int v30; // er11
  int v31; // eax
  int v32; // edx
  char v33; // al
  __int64 v34; // [rsp+20h] [rbp-48h]
  signed __int64 v35; // [rsp+88h] [rbp+20h]

  v3 = this;
  if ( !this->mRenderImposters )
    return;
  if ( !render_context->mRenderFeatures.mWorld )
    return;
  v4 = UFG::SectionChooser::GetCurrentSectionIndex();
  if ( v4 == -1 )
    return;
  v5 = UFG::SectionLayout::GetSectionUIDFromIndex(v4);
  v6 = 0;
  v7 = UFG::qResourceInventory::Get((UFG::qResourceInventory *)&Render::gImposterGroupInventory.vfptr, v5);
  if ( _S1_6 & 1 )
  {
    v9 = texInventory;
  }
  else
  {
    _S1_6 |= 1u;
    v8 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v8, 0x8B43FABF);
    texInventory = v9;
  }
  if ( v7 )
  {
    if ( LODWORD(v7[1].mNode.mChild[0]) )
    {
      v6 = 0;
      if ( v9->vfptr->Get(v9, HIDWORD(v7[1].mNode.mChild[0])) )
        v6 = 1;
    }
  }
  v10 = 0;
  if ( v6 == 1 )
  {
    v11 = 0;
    v12 = v3->mImposterGroupTargets;
    do
    {
      if ( *(v12 - 8) == v5 )
      {
        *v12 = Render::TransparencySystem::msOpaqueIndex;
        v10 = v11;
      }
      else
      {
        *v12 = 0;
      }
      ++v11;
      ++v12;
    }
    while ( v11 < 8 );
  }
  v34 = v10;
  v13 = v3->mImposterGroupBuckets;
  v14 = v3->mImposterGroupPtrs;
  v15 = v3->mImposterGroupTargets;
  v16 = -136i64 - (_QWORD)v3;
  v17 = 8i64;
  v35 = 8i64;
  do
  {
    v18 = 0i64;
    if ( !v13->mImposterBucketArray.size )
      goto LABEL_49;
    do
    {
      v19 = (unsigned int *)((char *)v3->mImposterGroupBuckets[0].mImposterBucketArray.p + (_QWORD)v13 + 36 * v18 + v16);
      v20 = *v15;
      v19[1] = *v15;
      v21 = (signed __int64)&(*v14)->mImposters;
      v22 = *(_QWORD *)v21;
      if ( *(_QWORD *)v21 )
        v22 += v21;
      v23 = v22 + 96i64 * *v19;
      v24 = *(_DWORD *)(v23 + 80);
      if ( v20 )
      {
        if ( UFG::SectionChooser::GetSTDStreamingStateForSectionIndex(v24) == 1 )
          v19[1] = 0;
        if ( UFG::SectionChooser::GetMIDStreamingStateForSectionIndex(*(_DWORD *)(v23 + 80)) == 1 )
          v19[1] = 0;
      }
      else if ( !UFG::SectionChooser::GetMIDStreamingStateForSectionIndex(v24)
             && !UFG::SectionChooser::GetSTDStreamingStateForSectionIndex(*(_DWORD *)(v23 + 80))
             && (!v6
              || !UFG::qHashMapBase::Lookup(
                    (UFG::qHashMapBase *)&v3->mImposterGroupStateMaps[v34]->mPool,
                    *(_DWORD *)(v23 + 80))->value) )
      {
        v19[1] = Render::TransparencySystem::msOpaqueIndex;
      }
      v25 = v19[1];
      v26 = v25 != 0;
      v27 = *((unsigned __int8 *)v19 + 8);
      v29 = (v26 == 1) + 1;
      v30 = (signed int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
      if ( v26 == 3 )
      {
        v27 = v19[1];
        goto LABEL_43;
      }
      if ( v26 == 2 )
      {
        if ( v30 & 1 )
          goto LABEL_43;
      }
      else
      {
        v28 = *((unsigned __int8 *)v19 + 10);
        v31 = v30 - (v28 + 1) % 255;
        if ( v31 < 0 )
          v31 = (v28 + 1) % 255 - v30;
        if ( v31 > 0 )
        {
          v27 = v19[1];
          goto LABEL_43;
        }
      }
      if ( v27 >= v25 )
      {
        if ( v27 > v25 )
          v27 -= v29;
      }
      else
      {
        v27 += v29;
      }
LABEL_43:
      v32 = 0;
      if ( v27 > 0 )
        v32 = v27;
      v33 = Render::TransparencySystem::msOpaqueIndex;
      if ( v32 < Render::TransparencySystem::msOpaqueIndex )
        v33 = v32;
      *((_BYTE *)v19 + 8) = v33;
      *((_BYTE *)v19 + 9) = v25;
      *((_BYTE *)v19 + 10) = v30;
      v18 = (unsigned int)(v18 + 1);
      v16 = -136i64 - (_QWORD)v3;
    }
    while ( (unsigned int)v18 < v13->mImposterBucketArray.size );
    v17 = v35;
LABEL_49:
    ++v15;
    ++v14;
    ++v13;
    v35 = --v17;
  }
  while ( v17 );
}

// File Line: 355
// RVA: 0x2E600
void __fastcall UFG::RenderStageImposters::Render(UFG::RenderStageImposters *this, UFG::RenderContext *render_context, Render::View *view)
{
  Render::View *v3; // r15
  UFG::RenderStageImposters *v4; // r13
  CB_EnvironmentSettings *v5; // rbx
  Illusion::StateValues *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  signed __int64 v8; // rdi
  _DWORD *v9; // rbp
  signed __int64 v10; // r12
  _DWORD *v11; // r14
  signed __int64 v12; // rsi
  unsigned int v13; // er8
  Illusion::Material *v14; // rbx
  _WORD *v15; // rax
  unsigned int v16; // er8
  Illusion::Material *v17; // rbx
  _WORD *v18; // rax
  unsigned int v19; // er8
  Illusion::Material *v20; // rbx
  _WORD *v21; // rax
  unsigned int v22; // er8
  Illusion::Material *v23; // rbx
  _WORD *v24; // rax
  __int64 v25; // rax
  signed __int64 v26; // r14
  unsigned __int8 v27; // r8
  signed int v28; // ecx
  __int64 v29; // rbx
  unsigned int v30; // er8
  Illusion::Material *v31; // rdi
  _WORD *v32; // rax
  Illusion::Texture *v33; // rax
  unsigned int v34; // er8
  Illusion::Material *v35; // rbx
  _WORD *v36; // rax
  unsigned int v37; // esi
  _QWORD *v38; // rax
  char *v39; // rdx
  UFG::qMatrix44 *v40; // rbx
  char *v41; // rdi
  Illusion::StateValues *v42; // rax
  Illusion::Material *force_mat; // ST20_8
  signed __int64 v44; // [rsp+30h] [rbp-68h]
  signed __int64 v45; // [rsp+40h] [rbp-58h]
  signed __int64 v46; // [rsp+48h] [rbp-50h]
  int v47; // [rsp+A0h] [rbp+8h]
  float distance_from_near_plane; // [rsp+B8h] [rbp+20h]

  v3 = view;
  v4 = this;
  if ( this->mRenderImposters )
  {
    v5 = render_context->mEnvState;
    v6 = Render::View::GetStateValues(view);
    v6->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    v6->mParamValues[55] = v5;
    if ( !(_S2 & 1) )
    {
      _S2 |= 1u;
      v7 = UFG::qResourceWarehouse::Instance();
      texInventory_0 = UFG::qResourceWarehouse::GetInventory(v7, 0x8B43FABF);
    }
    v8 = 0i64;
    v44 = 0i64;
    v9 = v4->mImposterGroupBuckets;
    v46 = (signed __int64)v4->mImposterGroupBuckets;
    v10 = (signed __int64)v4->mImposterGroupPtrs;
    v11 = v4->mImposterGroupSectionUIDs;
    v45 = (signed __int64)v4->mImposterGroupSectionUIDs;
    v12 = -136i64 - (_QWORD)v4;
    while ( 1 )
    {
      if ( *v11 != -1
        && *(_QWORD *)v10
        && (__int64)texInventory_0->vfptr->Get(texInventory_0, *(unsigned int *)(*(_QWORD *)v10 + 100i64)) )
      {
        v13 = *(_DWORD *)(*(_QWORD *)v10 + 100i64);
        v14 = v4->mFarGroundImposterMaterial;
        if ( *(_DWORD *)&v14[2].mDebugName[28] != v13 )
        {
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v14[2].mDebugName[4], *((_DWORD *)&v14[2].0 + 22), v13);
          v15 = (_WORD *)v14->mMaterialUser.mOffset;
          if ( v15 )
            v15 = (_WORD *)((char *)v15 + (_QWORD)v14 + 120);
          *v15 |= 0x20u;
        }
        v16 = *(_DWORD *)(*(_QWORD *)v10 + 104i64);
        v17 = v4->mFarGroundImposterMaterial;
        if ( LODWORD(v17[3].mNode.mChild[0]) != v16 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v17[2].mNumParams,
            (unsigned int)v17[3].mNode.mChild[1],
            v16);
          v18 = (_WORD *)v17->mMaterialUser.mOffset;
          if ( v18 )
            v18 = (_WORD *)((char *)v18 + (_QWORD)v17 + 120);
          *v18 |= 0x20u;
        }
        v19 = *(_DWORD *)(*(_QWORD *)v10 + 108i64);
        v20 = v4->mFarGroundImposterMaterial;
        if ( LODWORD(v20[3].mMaterialUser.mOffset) != v19 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v20[3].mStateBlockMask,
            (unsigned int)v20[4].mNode.mParent,
            v19);
          v21 = (_WORD *)v20->mMaterialUser.mOffset;
          if ( v21 )
            v21 = (_WORD *)((char *)v21 + (_QWORD)v20 + 120);
          *v21 |= 0x20u;
        }
        v22 = *(_DWORD *)(*(_QWORD *)v10 + 112i64);
        v23 = v4->mFarGroundImposterMaterial;
        if ( v23[4].mTypeUID != v22 )
        {
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v23[4].mNode.mUID, *(_DWORD *)&v23[4].mDebugName[4], v22);
          v24 = (_WORD *)v23->mMaterialUser.mOffset;
          if ( v24 )
            v24 = (_WORD *)((char *)v24 + (_QWORD)v23 + 120);
          *v24 |= 0x20u;
        }
        v25 = 0i64;
        v47 = 0;
        if ( *v9 )
          break;
      }
LABEL_61:
      ++v11;
      v45 = (signed __int64)v11;
      v10 += 8i64;
      v9 += 2305;
      v46 = (signed __int64)v9;
      v8 += 256i64;
      v44 = v8;
      if ( v8 >= 2048 )
        return;
    }
    while ( 1 )
    {
      v26 = (signed __int64)v4->mImposterGroupBuckets[0].mImposterBucketArray.p + (_QWORD)&v9[9 * v25] + v12;
      v27 = *(_BYTE *)(v26 + 8);
      if ( v27 )
      {
        if ( v3->mSettings->mCullIndex || v4->mImposterGroupCullResults[0][(unsigned int)v25 + v8]->mViewResult[0] <= 1u )
          break;
      }
LABEL_59:
      v25 = (unsigned int)(v47 + 1);
      v47 = v25;
      if ( (unsigned int)v25 >= *v9 )
      {
        v11 = (_DWORD *)v45;
        goto LABEL_61;
      }
    }
    v28 = *(unsigned __int8 *)(v26 + 9);
    if ( (signed int)v27 <= 0 || v27 >= Render::TransparencySystem::msOpaqueIndex )
    {
      v29 = 0i64;
    }
    else
    {
      v29 = 0i64;
      if ( v27 >= v28 )
      {
        if ( v27 > v28 )
          v29 = *((_QWORD *)&Render::TransparencySystem::msAlphaStateOutHandle[0].mData + 4 * v27);
      }
      else
      {
        v29 = *((_QWORD *)&Render::TransparencySystem::msAlphaStateInHandle[0].mData + 4 * v27);
      }
      if ( v29 )
      {
        v30 = *(_DWORD *)(v29 + 24);
LABEL_38:
        v31 = v4->mFarGroundImposterMaterial;
        if ( LODWORD(v31[1].mStateBlockMask.mFlags[0]) != v30 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v31[1].mDebugName[20],
            v31[1].mStateBlockMask.mFlags[1],
            v30);
          v32 = (_WORD *)v31->mMaterialUser.mOffset;
          if ( v32 )
            v32 = (_WORD *)((char *)v32 + (_QWORD)v31 + 120);
          *v32 |= 0x20u;
        }
        if ( v29 )
          v33 = Render::TransparencySystem::msDitherMaskTextures[*(unsigned __int16 *)(v29 + 100)];
        else
          v33 = qword_142128EE8;
        v34 = v33->mNode.mUID;
        v35 = v4->mFarGroundImposterMaterial;
        if ( *(_DWORD *)&v35[3].mDebugName[12] != v34 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v35[3].mResourceHandles.mNode.mNext,
            *(_DWORD *)&v35[3].mDebugName[20],
            v34);
          v36 = (_WORD *)v35->mMaterialUser.mOffset;
          if ( v36 )
            v36 = (_WORD *)((char *)v36 + (_QWORD)v35 + 120);
          *v36 |= 0x20u;
        }
        v37 = *(_DWORD *)v26;
        if ( *(_DWORD *)v26 < *(_DWORD *)v26 + (unsigned int)*(unsigned __int8 *)(v26 + 11) )
        {
          do
          {
            v38 = (_QWORD *)(*(_QWORD *)v10 + 88i64);
            if ( *v38 )
              v39 = (char *)v38 + *v38;
            else
              v39 = 0i64;
            v40 = (UFG::qMatrix44 *)&v39[96 * v37];
            if ( !v3->mSettings->mCullIndex
              || (unsigned int)Render::View::IsInView(
                                 v3,
                                 &v4->mImposterModel,
                                 (UFG::qMatrix44 *)&v39[96 * v37],
                                 &distance_from_near_plane) )
            {
              v41 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
              UFG::qMemCopy(v41, &v40[1], 0x10u);
              v42 = Render::View::GetStateValues(v3);
              v42->mSetValueMask.mFlags[0] |= 0x8000ui64;
              v42->mParamValues[15] = v41;
              force_mat = v4->mFarGroundImposterMaterial;
              Render::View::Draw(v3, &v4->mImposterModel, v40, 0);
            }
            ++v37;
          }
          while ( v37 < *(_DWORD *)v26 + (unsigned int)*(unsigned __int8 *)(v26 + 11) );
          v9 = (_DWORD *)v46;
        }
        v12 = -136i64 - (_QWORD)v4;
        v8 = v44;
        goto LABEL_59;
      }
    }
    v30 = 662883558;
    goto LABEL_38;
  }
}

