// File Line: 64
// RVA: 0x2E450
void __fastcall UFG::RenderStageImposters::Create(UFG::RenderContext *render_context)
{
  UFG::RenderStageImposters *v2; // rax

  v2 = (UFG::RenderStageImposters *)UFG::qMalloc(0x1A110ui64, "RenderStageImposters", 0i64);
  if ( v2 )
    UFG::RenderStageImposters::RenderStageImposters(v2, render_context);
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
void __fastcall UFG::RenderStageImposters::RenderStageImposters(
        UFG::RenderStageImposters *this,
        UFG::RenderContext *render_context)
{
  UFG::ImposterBucket *mImposterGroupBuckets; // r14
  UFG::qHashMap<UFG::ImposterState,0> **mImposterGroupStateMaps; // rdi
  int *mImposterGroupTargets; // rsi
  __int64 v6; // rbp
  char *v7; // rax
  char *v8; // rbx
  unsigned int v9; // eax
  int v10; // edi
  Illusion::Material *mFarGroundImposterMaterial; // rbx
  Illusion::Material *v12; // rbx
  Illusion::Material *v13; // rbx
  Illusion::Material *v14; // rbx
  Illusion::Material *v15; // rbx
  Illusion::Material *v16; // rbx
  Illusion::Material *v17; // rbx
  Illusion::Material *v18; // rbx
  UFG::qResourceWarehouse *v19; // rax
  unsigned int v20; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v22; // rax

  mImposterGroupBuckets = this->mImposterGroupBuckets;
  `eh vector constructor iterator(
    this->mImposterGroupBuckets,
    0x2404ui64,
    8,
    (void (__fastcall *)(void *))UFG::ImposterBucket::ImposterBucket);
  UFG::qResourceHandle::qResourceHandle(&this->mImposterModel);
  this->mRenderImposters = 1;
  mImposterGroupStateMaps = this->mImposterGroupStateMaps;
  mImposterGroupTargets = this->mImposterGroupTargets;
  v6 = 8i64;
  do
  {
    *(mImposterGroupStateMaps - 9236) = 0i64;
    *(mImposterGroupTargets - 8) = -1;
    *mImposterGroupTargets = 0;
    mImposterGroupBuckets->mImposterBucketArray.size = 0;
    v7 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
    v8 = v7;
    if ( v7 )
      UFG::qHashMapBase::qHashMapBase((UFG::qHashMapBase *)v7, UFG::gMainMemoryPool, 0x100u);
    else
      v8 = 0i64;
    *mImposterGroupStateMaps = (UFG::qHashMap<UFG::ImposterState,0> *)v8;
    ++mImposterGroupTargets;
    ++mImposterGroupStateMaps;
    ++mImposterGroupBuckets;
    --v6;
  }
  while ( v6 );
  Render::gImposterGroupInventory.mAddImposterGroupCallback = UFG::AddImposterGroup;
  Render::gImposterGroupInventory.mRemoveImposterGroupCallback = UFG::RemoveImposterGroup;
  v9 = UFG::qStringHashUpper32("RenderStageImpostersMaterial", 0xFFFFFFFF);
  this->mFarGroundImposterMaterial = Illusion::Factory::NewMaterial(
                                       "RenderStageImpostersMaterial",
                                       v9,
                                       8u,
                                       0i64,
                                       0i64,
                                       0i64);
  v10 = UFG::qStringHashUpper32("DRFARGROUNDIMPOSTERS", 0xFFFFFFFF);
  mFarGroundImposterMaterial = this->mFarGroundImposterMaterial;
  LOWORD(mFarGroundImposterMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(mFarGroundImposterMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  LODWORD(mFarGroundImposterMaterial[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  mFarGroundImposterMaterial[1].mTypeUID = -1957338719;
  LODWORD(mFarGroundImposterMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v10;
  v12 = this->mFarGroundImposterMaterial;
  *(_WORD *)&v12[1].mDebugName[12] = 0;
  *(_DWORD *)&v12[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  *(_DWORD *)&v12[1].mDebugName[4] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v12[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v12[1].mStateBlockMask.mFlags[0]) = 662883558;
  v13 = this->mFarGroundImposterMaterial;
  LOWORD(v13[1].mMaterialUser.mOffset) = 0;
  *(&v13[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v13[1].mNumParams = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v13[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v13[2].mNode.mUID = 543723269;
  v14 = this->mFarGroundImposterMaterial;
  LOWORD(v14[2].mTypeUID) = 0;
  HIDWORD(v14[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v14[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v14[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v14[2].mDebugName[28] = 0;
  v15 = this->mFarGroundImposterMaterial;
  LOWORD(v15[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v15[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v15[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v15[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v15[3].mNode.mChild[0]) = 0;
  v16 = this->mFarGroundImposterMaterial;
  LOWORD(v16[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v16[3].mNode.mUID + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v16[3].mNode.mUID = UFG::qStringHash32("texFadeDitherMask", 0xFFFFFFFF);
  *(_DWORD *)&v16[3].mDebugName[20] = -1958479169;
  *(_DWORD *)&v16[3].mDebugName[12] = 0;
  v17 = this->mFarGroundImposterMaterial;
  *((_WORD *)&v17[3].UFG::qResourceData + 44) = 0;
  *(_DWORD *)&v17[3].mDebugName[32] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  *(_DWORD *)&v17[3].mDebugName[28] = UFG::qStringHash32("texEmission", 0xFFFFFFFF);
  LODWORD(v17[4].mNode.mParent) = -1958479169;
  LODWORD(v17[3].mMaterialUser.mOffset) = 0;
  v18 = this->mFarGroundImposterMaterial;
  LOWORD(v18[4].mNode.mChild[1]) = 0;
  HIDWORD(v18[4].mNode.mChild[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  LODWORD(v18[4].mNode.mChild[0]) = UFG::qStringHash32("texAmbient", 0xFFFFFFFF);
  *(_DWORD *)&v18[4].mDebugName[4] = -1958479169;
  v18[4].mTypeUID = 0;
  v19 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v19, this->mFarGroundImposterMaterial);
  v20 = UFG::qStringHashUpper32("dr_imposter", 0xFFFFFFFF);
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v22 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v22, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mImposterModel, 0xA2ADCD77, v20, Inventory);
}

// File Line: 140
// RVA: 0x2DD60
void __fastcall UFG::RenderStageImposters::AddGroup(UFG::RenderStageImposters *this, Render::ImposterGroup *pGroup)
{
  int v3; // edx
  unsigned int *mImposterGroupSectionUIDs; // rax
  int v6; // r8d
  __int64 v7; // rbp
  int v8; // r12d
  unsigned int mUID; // eax
  UFG::ImposterBucket *v10; // rsi
  __int64 mOffset; // rax
  char *v12; // rcx
  char *v13; // rbx
  __int64 size; // rdi
  float *v15; // r14
  float *v16; // rax
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm5_4
  float v23; // xmm1_4
  float v24; // xmm12_4
  float v25; // xmm14_4
  float v26; // xmm9_4
  float v27; // xmm4_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  __int64 v32; // rcx
  CullInfo **v33; // rbx
  CullResults **v34; // rdi
  CullManager *v35; // rax
  CullInfo *v36; // rcx
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  __int64 v41; // r8
  float *mData; // rax
  float v43; // xmm2_4
  float v44; // xmm3_4
  float v45; // xmm4_4
  float v46; // xmm0_4
  float v47; // xmm2_4
  float v48; // xmm5_4
  float v49; // xmm1_4
  float v50; // xmm12_4
  float v51; // xmm14_4
  float v52; // xmm9_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm3_4
  float v56; // xmm1_4
  float v57; // xmm4_4
  float z; // xmm7_4
  float y; // xmm6_4
  float x; // xmm2_4
  float v61; // xmm3_4
  float v62; // xmm2_4
  float v63; // xmm0_4
  float v64; // eax
  CullInfo *v65; // rdx
  float v66; // xmm0_4
  float v67; // xmm1_4
  float v68; // [rsp+30h] [rbp-F8h]
  float v69; // [rsp+34h] [rbp-F4h]
  float v70; // [rsp+38h] [rbp-F0h]
  float v71; // [rsp+38h] [rbp-F0h]
  float v72; // [rsp+3Ch] [rbp-ECh]
  __int64 v73; // [rsp+40h] [rbp-E8h]
  __int64 v74; // [rsp+48h] [rbp-E0h]
  float v75; // [rsp+140h] [rbp+18h]
  float v76; // [rsp+140h] [rbp+18h]
  float v77; // [rsp+140h] [rbp+18h]
  float v78; // [rsp+140h] [rbp+18h]
  int v79; // [rsp+148h] [rbp+20h]

  v3 = -1;
  mImposterGroupSectionUIDs = this->mImposterGroupSectionUIDs;
  v79 = -1;
  v6 = 0;
  v7 = 0i64;
  while ( *mImposterGroupSectionUIDs != -1 )
  {
    ++v7;
    ++v6;
    ++mImposterGroupSectionUIDs;
    if ( v7 >= 8 )
      return;
  }
  v8 = 0;
  this->mImposterGroupPtrs[v6] = pGroup;
  mUID = pGroup->mNode.mUID;
  this->mImposterGroupTargets[v6] = 0;
  this->mImposterGroupSectionUIDs[v6] = mUID;
  v73 = v6;
  if ( pGroup->mNumImposters )
  {
    v10 = &this->mImposterGroupBuckets[v7];
    while ( 1 )
    {
      mOffset = pGroup->mImposters.mOffset;
      v12 = mOffset ? (char *)&pGroup->mImposters + mOffset : 0i64;
      v13 = &v12[96 * v8];
      if ( *((_DWORD *)v13 + 20) != v3 )
        break;
      if ( v10->mImposterBucketArray.size )
      {
        v41 = v10->mImposterBucketArray.size - 1;
        mData = (float *)this->mImposterModel.mData;
        v43 = mData[23];
        v44 = mData[24];
        v77 = mData[22];
        v68 = (float)((float)((float)(v77 * *(float *)v13) + (float)(v43 * *((float *)v13 + 4)))
                    + (float)(v44 * *((float *)v13 + 8)))
            + *((float *)v13 + 12);
        v45 = (float)((float)((float)(v77 * *((float *)v13 + 1)) + (float)(v43 * *((float *)v13 + 5)))
                    + (float)(v44 * *((float *)v13 + 9)))
            + *((float *)v13 + 13);
        v46 = (float)(v77 * *((float *)v13 + 2)) + (float)(v43 * *((float *)v13 + 6));
        v47 = mData[27];
        v78 = (float)(v46 + (float)(v44 * *((float *)v13 + 10))) + *((float *)v13 + 14);
        v48 = v78;
        v71 = mData[26];
        v49 = mData[28];
        v50 = (float)((float)((float)(v71 * *(float *)v13) + (float)(v47 * *((float *)v13 + 4)))
                    + (float)(v49 * *((float *)v13 + 8)))
            + *((float *)v13 + 12);
        v51 = (float)((float)((float)(v71 * *((float *)v13 + 2)) + (float)(v47 * *((float *)v13 + 6)))
                    + (float)(v49 * *((float *)v13 + 10)))
            + *((float *)v13 + 14);
        v52 = (float)((float)((float)(v71 * *((float *)v13 + 1)) + (float)(v47 * *((float *)v13 + 5)))
                    + (float)(v49 * *((float *)v13 + 9)))
            + *((float *)v13 + 13);
        if ( v78 >= v51 )
          v53 = (float)((float)((float)(v71 * *((float *)v13 + 2)) + (float)(v47 * *((float *)v13 + 6)))
                      + (float)(v49 * *((float *)v13 + 10)))
              + *((float *)v13 + 14);
        else
          v53 = (float)(v46 + (float)(v44 * *((float *)v13 + 10))) + *((float *)v13 + 14);
        v54 = v45;
        if ( v45 >= v52 )
          v55 = (float)((float)((float)(v71 * *((float *)v13 + 1)) + (float)(mData[27] * *((float *)v13 + 5)))
                      + (float)(v49 * *((float *)v13 + 9)))
              + *((float *)v13 + 13);
        else
          v55 = v45;
        v56 = (float)((float)((float)(mData[22] * *(float *)v13) + (float)(mData[23] * *((float *)v13 + 4)))
                    + (float)(mData[24] * *((float *)v13 + 8)))
            + *((float *)v13 + 12);
        if ( v68 >= v50 )
          v57 = v50;
        else
          v57 = (float)((float)((float)(mData[22] * *(float *)v13) + (float)(mData[23] * *((float *)v13 + 4)))
                      + (float)(mData[24] * *((float *)v13 + 8)))
              + *((float *)v13 + 12);
        z = v10->mImposterBucketArray.p[v10->mImposterBucketArray.size - 1].mAABBMin.z;
        if ( z >= v53 )
          z = v53;
        y = v10->mImposterBucketArray.p[v10->mImposterBucketArray.size - 1].mAABBMin.y;
        if ( y >= v55 )
          y = v55;
        x = v10->mImposterBucketArray.p[v10->mImposterBucketArray.size - 1].mAABBMin.x;
        if ( x >= v57 )
          x = v57;
        v10->mImposterBucketArray.p[v10->mImposterBucketArray.size - 1].mAABBMin.x = x;
        v10->mImposterBucketArray.p[v41].mAABBMin.y = y;
        v10->mImposterBucketArray.p[v41].mAABBMin.z = z;
        if ( v78 <= v51 )
          v48 = v51;
        if ( v54 <= v52 )
          v54 = v52;
        if ( v68 <= v50 )
          v56 = v50;
        v61 = v10->mImposterBucketArray.p[v41].mAABBMax.z;
        if ( v61 <= v48 )
          v61 = v48;
        v62 = v10->mImposterBucketArray.p[v41].mAABBMax.y;
        if ( v62 <= v54 )
          v62 = v54;
        v63 = v10->mImposterBucketArray.p[v41].mAABBMax.x;
        if ( v63 <= v56 )
          v63 = v56;
        v10->mImposterBucketArray.p[v41].mAABBMax.x = v63;
        v10->mImposterBucketArray.p[v41].mAABBMax.y = v62;
        v10->mImposterBucketArray.p[v41].mAABBMax.z = v61;
        v64 = v10->mImposterBucketArray.p[v41].mAABBMin.x;
        v65 = this->mImposterGroupCullInfo[v7][v10->mImposterBucketArray.size - 1];
        v65->mAABBMin[1] = y;
        v65->mAABBMin[2] = z;
        v65->mAABBMin[0] = v64;
        v66 = v10->mImposterBucketArray.p[v41].mAABBMax.y;
        v67 = v10->mImposterBucketArray.p[v41].mAABBMax.z;
        v65->mAABBMax[0] = v10->mImposterBucketArray.p[v41].mAABBMax.x;
        v65->mAABBMax[1] = v66;
        v65->mAABBMax[2] = v67;
        ++v10->mImposterBucketArray.p[v41].mCount;
        goto LABEL_56;
      }
LABEL_57:
      if ( ++v8 >= pGroup->mNumImposters )
        return;
    }
    size = v10->mImposterBucketArray.size;
    v79 = *((_DWORD *)v13 + 20);
    v74 = size;
    v15 = (float *)(&v10->mImposterBucketArray.size + 9 * size);
    v10->mImposterBucketArray.size = size + 1;
    *((_DWORD *)v15 + 1) = v8;
    v15[2] = 0.0;
    v15[3] = 2.3509887e-38;
    UFG::qHashMapBase::Set(this->mImposterGroupStateMaps[v7], *((_DWORD *)v13 + 20), v15 + 1);
    v16 = (float *)this->mImposterModel.mData;
    v17 = v16[23];
    v18 = v16[24];
    v75 = v16[22];
    v72 = (float)((float)((float)(v75 * *(float *)v13) + (float)(v17 * *((float *)v13 + 4)))
                + (float)(v18 * *((float *)v13 + 8)))
        + *((float *)v13 + 12);
    v19 = (float)((float)((float)(v75 * *((float *)v13 + 1)) + (float)(v17 * *((float *)v13 + 5)))
                + (float)(v18 * *((float *)v13 + 9)))
        + *((float *)v13 + 13);
    v20 = (float)(v75 * *((float *)v13 + 2)) + (float)(v17 * *((float *)v13 + 6));
    v21 = v16[27];
    v70 = v19;
    v76 = (float)(v20 + (float)(v18 * *((float *)v13 + 10))) + *((float *)v13 + 14);
    v22 = v76;
    v69 = v16[26];
    v23 = v16[28];
    v24 = (float)((float)((float)(v69 * *(float *)v13) + (float)(v21 * *((float *)v13 + 4)))
                + (float)(v23 * *((float *)v13 + 8)))
        + *((float *)v13 + 12);
    v25 = (float)((float)((float)(v69 * *((float *)v13 + 2)) + (float)(v21 * *((float *)v13 + 6)))
                + (float)(v23 * *((float *)v13 + 10)))
        + *((float *)v13 + 14);
    v26 = (float)((float)((float)(v69 * *((float *)v13 + 1)) + (float)(v21 * *((float *)v13 + 5)))
                + (float)(v23 * *((float *)v13 + 9)))
        + *((float *)v13 + 13);
    if ( v76 >= v25 )
      v27 = (float)((float)((float)(v69 * *((float *)v13 + 2)) + (float)(v21 * *((float *)v13 + 6)))
                  + (float)(v23 * *((float *)v13 + 10)))
          + *((float *)v13 + 14);
    else
      v27 = (float)(v20 + (float)(v18 * *((float *)v13 + 10))) + *((float *)v13 + 14);
    v28 = v70;
    if ( v70 >= v26 )
      v29 = (float)((float)((float)(v69 * *((float *)v13 + 1)) + (float)(v16[27] * *((float *)v13 + 5)))
                  + (float)(v23 * *((float *)v13 + 9)))
          + *((float *)v13 + 13);
    else
      v29 = v70;
    v30 = (float)((float)((float)(v16[22] * *(float *)v13) + (float)(v16[23] * *((float *)v13 + 4)))
                + (float)(v16[24] * *((float *)v13 + 8)))
        + *((float *)v13 + 12);
    if ( v72 >= v24 )
      v31 = (float)((float)((float)(v69 * *(float *)v13) + (float)(v21 * *((float *)v13 + 4)))
                  + (float)(v16[28] * *((float *)v13 + 8)))
          + *((float *)v13 + 12);
    else
      v31 = (float)((float)((float)(v16[22] * *(float *)v13) + (float)(v16[23] * *((float *)v13 + 4)))
                  + (float)(v16[24] * *((float *)v13 + 8)))
          + *((float *)v13 + 12);
    v15[4] = v31;
    v15[5] = v29;
    v15[6] = v27;
    if ( v76 <= v25 )
      v22 = v25;
    if ( v70 <= v26 )
      v28 = v26;
    if ( v72 <= v24 )
      v30 = v24;
    v15[7] = v30;
    v15[8] = v28;
    v15[9] = v22;
    v32 = size + (v73 << 8);
    v33 = &this->mImposterGroupCullInfo[0][v32];
    v34 = &this->mImposterGroupCullResults[0][v32];
    v35 = CullManager::Instance();
    CullManager::AllocPersistentCullInfo(v35, v34, v33, 0i64, 0i64, 0i64);
    v36 = this->mImposterGroupCullInfo[v7][v74];
    v36->mpLocalWorld = 0i64;
    *(_DWORD *)&v36->mPixelScaleBias = -130072;
    *(_DWORD *)&v36->mIsLocalWorldIdentity = 0;
    v37 = v15[5];
    v38 = v15[6];
    v36->mAABBMin[0] = v15[4];
    v36->mAABBMin[1] = v37;
    v36->mAABBMin[2] = v38;
    v39 = v15[8];
    v40 = v15[9];
    v36->mAABBMax[0] = v15[7];
    v36->mAABBMax[1] = v39;
    v36->mAABBMax[2] = v40;
LABEL_56:
    v3 = v79;
    goto LABEL_57;
  }
}

// File Line: 218
// RVA: 0x2E4A0
void __fastcall UFG::RenderStageImposters::RemoveGroup(UFG::RenderStageImposters *this, Render::ImposterGroup *pGroup)
{
  Render::ImposterGroup *v2; // rax
  UFG::ImposterBucket *mImposterGroupBuckets; // r14
  UFG::qHashMap<UFG::ImposterState,0> **mImposterGroupStateMaps; // r12
  unsigned int *mImposterGroupSectionUIDs; // r15
  __int64 v7; // rbp
  unsigned int i; // esi
  __int64 v9; // rdi
  CullManager *v10; // rax
  UFG::qHashMap<UFG::ImposterState,0> *v11; // r8
  unsigned int mUsedCount; // eax
  UFG::qHashMapBase::Entry *mTable; // rcx
  void **p_value; // rdx

  v2 = pGroup;
  mImposterGroupBuckets = this->mImposterGroupBuckets;
  mImposterGroupStateMaps = this->mImposterGroupStateMaps;
  mImposterGroupSectionUIDs = this->mImposterGroupSectionUIDs;
  v7 = 0i64;
  do
  {
    if ( *mImposterGroupSectionUIDs == v2->mNode.mUID )
    {
      *(mImposterGroupStateMaps - 9236) = 0i64;
      *mImposterGroupSectionUIDs = -1;
      for ( i = 0; i < mImposterGroupBuckets->mImposterBucketArray.size; this->mImposterGroupCullInfo[0][v9] = 0i64 )
      {
        v9 = v7 + i;
        v10 = CullManager::Instance();
        CullManager::FreePersistentCullInfo(
          v10,
          this->mImposterGroupCullResults[0][v9],
          this->mImposterGroupCullInfo[0][v9]);
        ++i;
        this->mImposterGroupCullResults[0][v9] = 0i64;
      }
      v11 = *mImposterGroupStateMaps;
      mUsedCount = (*mImposterGroupStateMaps)->mUsedCount;
      mTable = (*mImposterGroupStateMaps)->mTable;
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
      *(_QWORD *)&v11->mFillCount = 0i64;
      UFG::qMemSet(mTable, 0, 16 * (v11->mMask + 1));
      mImposterGroupBuckets->mImposterBucketArray.size = 0;
    }
    v2 = pGroup;
    v7 += 256i64;
    ++mImposterGroupSectionUIDs;
    ++mImposterGroupStateMaps;
    ++mImposterGroupBuckets;
  }
  while ( v7 < 2048 );
}

// File Line: 244
// RVA: 0x2EA70
void __fastcall UFG::RenderStageImposters::UpdateViews(
        UFG::RenderStageImposters *this,
        UFG::RenderContext *render_context,
        float fRealTimeDelta)
{
  unsigned int CurrentSectionIndex; // eax
  unsigned int SectionUIDFromIndex; // ebx
  bool v6; // r13
  UFG::qResourceData *v7; // rdi
  UFG::qResourceWarehouse *v8; // rax
  UFG::qResourceInventory *Inventory; // rcx
  int v10; // eax
  int v11; // edx
  int *mImposterGroupTargets; // rcx
  UFG::ImposterBucket *mImposterGroupBuckets; // rbp
  Render::ImposterGroup **mImposterGroupPtrs; // r15
  int *v15; // r12
  __int64 v16; // rdx
  __int64 v17; // rax
  __int64 v18; // rsi
  unsigned int *v19; // rdi
  int v20; // edx
  __int64 p_mImposters; // rax
  __int64 v22; // rcx
  __int64 v23; // rbx
  unsigned int v24; // ecx
  int v25; // r9d
  int v26; // r8d
  int v27; // ecx
  int v28; // ebx
  int v29; // r10d
  int v30; // r11d
  int v31; // eax
  int v32; // edx
  char v33; // al
  __int64 v34; // [rsp+20h] [rbp-48h]
  __int64 v35; // [rsp+88h] [rbp+20h]

  if ( !this->mRenderImposters )
    return;
  if ( !render_context->mRenderFeatures.mWorld )
    return;
  CurrentSectionIndex = UFG::SectionChooser::GetCurrentSectionIndex();
  if ( CurrentSectionIndex == -1 )
    return;
  SectionUIDFromIndex = UFG::SectionLayout::GetSectionUIDFromIndex(CurrentSectionIndex);
  v6 = 0;
  v7 = UFG::qResourceInventory::Get(&Render::gImposterGroupInventory, SectionUIDFromIndex);
  if ( (_S1_6 & 1) != 0 )
  {
    Inventory = texInventory;
  }
  else
  {
    _S1_6 |= 1u;
    v8 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v8, 0x8B43FABF);
    texInventory = Inventory;
  }
  if ( v7 && LODWORD(v7[1].mNode.mChild[0]) )
    v6 = Inventory->vfptr->Get(Inventory, HIDWORD(v7[1].mNode.mChild[0])) != 0;
  v10 = 0;
  if ( v6 )
  {
    v11 = 0;
    mImposterGroupTargets = this->mImposterGroupTargets;
    do
    {
      if ( *(mImposterGroupTargets - 8) == SectionUIDFromIndex )
      {
        *mImposterGroupTargets = Render::TransparencySystem::msOpaqueIndex;
        v10 = v11;
      }
      else
      {
        *mImposterGroupTargets = 0;
      }
      ++v11;
      ++mImposterGroupTargets;
    }
    while ( v11 < 8 );
  }
  v34 = v10;
  mImposterGroupBuckets = this->mImposterGroupBuckets;
  mImposterGroupPtrs = this->mImposterGroupPtrs;
  v15 = this->mImposterGroupTargets;
  v16 = -136i64 - (_QWORD)this;
  v17 = 8i64;
  v35 = 8i64;
  do
  {
    v18 = 0i64;
    if ( !mImposterGroupBuckets->mImposterBucketArray.size )
      goto LABEL_48;
    do
    {
      v19 = (unsigned int *)((char *)&this->mImposterGroupBuckets[0].mImposterBucketArray.p[0].mIndexInGroup
                           + (_QWORD)mImposterGroupBuckets
                           + 36 * v18
                           + v16);
      v20 = *v15;
      v19[1] = *v15;
      p_mImposters = (__int64)&(*mImposterGroupPtrs)->mImposters;
      v22 = *(_QWORD *)p_mImposters;
      if ( *(_QWORD *)p_mImposters )
        v22 += p_mImposters;
      v23 = v22 + 96i64 * *v19;
      v24 = *(_DWORD *)(v23 + 80);
      if ( v20 )
      {
        if ( UFG::SectionChooser::GetSTDStreamingStateForSectionIndex(v24) )
          v19[1] = 0;
        if ( UFG::SectionChooser::GetMIDStreamingStateForSectionIndex(*(_DWORD *)(v23 + 80)) )
          v19[1] = 0;
      }
      else if ( !UFG::SectionChooser::GetMIDStreamingStateForSectionIndex(v24)
             && !UFG::SectionChooser::GetSTDStreamingStateForSectionIndex(*(_DWORD *)(v23 + 80))
             && (!v6 || !UFG::qHashMapBase::Lookup(this->mImposterGroupStateMaps[v34], *(_DWORD *)(v23 + 80))->value) )
      {
        v19[1] = Render::TransparencySystem::msOpaqueIndex;
      }
      v25 = v19[1];
      v26 = v25 != 0;
      v27 = *((unsigned __int8 *)v19 + 8);
      v29 = (v26 == 1) + 1;
      v30 = (int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
      if ( v26 == 3 )
      {
        v27 = v19[1];
        goto LABEL_42;
      }
      if ( v26 == 2 )
      {
        if ( (v30 & 1) != 0 )
          goto LABEL_42;
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
          goto LABEL_42;
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
LABEL_42:
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
      v16 = -136i64 - (_QWORD)this;
    }
    while ( (unsigned int)v18 < mImposterGroupBuckets->mImposterBucketArray.size );
    v17 = v35;
LABEL_48:
    ++v15;
    ++mImposterGroupPtrs;
    ++mImposterGroupBuckets;
    v35 = --v17;
  }
  while ( v17 );
}

// File Line: 355
// RVA: 0x2E600
void __fastcall UFG::RenderStageImposters::Render(
        UFG::RenderStageImposters *this,
        UFG::RenderContext *render_context,
        Render::View *view)
{
  CB_EnvironmentSettings *mEnvState; // rbx
  Illusion::StateValues *StateValues; // rax
  UFG::qResourceWarehouse *v7; // rax
  __int64 v8; // rdi
  UFG::ImposterBucket *mImposterGroupBuckets; // rbp
  Render::ImposterGroup **mImposterGroupPtrs; // r12
  unsigned int *mImposterGroupSectionUIDs; // r14
  __int64 v12; // rsi
  unsigned int v13; // r8d
  Illusion::Material *mFarGroundImposterMaterial; // rbx
  _WORD *mOffset; // rax
  unsigned int v16; // r8d
  Illusion::Material *v17; // rbx
  _WORD *v18; // rax
  unsigned int v19; // r8d
  Illusion::Material *v20; // rbx
  _WORD *v21; // rax
  unsigned int v22; // r8d
  Illusion::Material *v23; // rbx
  _WORD *v24; // rax
  __int64 v25; // rax
  char *v26; // r14
  unsigned __int8 v27; // r8
  int v28; // ecx
  __int64 v29; // rbx
  unsigned int v30; // r8d
  Illusion::Material *v31; // rdi
  _WORD *v32; // rax
  Illusion::Texture *v33; // rax
  unsigned int mUID; // r8d
  Illusion::Material *v35; // rbx
  _WORD *v36; // rax
  unsigned int v37; // esi
  UFG::qOffset64<Render::Imposter *> *p_mImposters; // rax
  char *v39; // rdx
  UFG::qMatrix44 *v40; // rbx
  char *v41; // rdi
  Illusion::StateValues *v42; // rax
  __int64 v43; // [rsp+30h] [rbp-68h]
  unsigned int *v44; // [rsp+40h] [rbp-58h]
  UFG::ImposterBucket *v45; // [rsp+48h] [rbp-50h]
  int v46; // [rsp+A0h] [rbp+8h]
  float distance_from_near_plane; // [rsp+B8h] [rbp+20h] BYREF

  if ( this->mRenderImposters )
  {
    mEnvState = render_context->mEnvState;
    StateValues = Render::View::GetStateValues(view);
    StateValues->mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
    StateValues->mParamValues[55] = mEnvState;
    if ( (_S2 & 1) == 0 )
    {
      _S2 |= 1u;
      v7 = UFG::qResourceWarehouse::Instance();
      texInventory_0 = UFG::qResourceWarehouse::GetInventory(v7, 0x8B43FABF);
    }
    v8 = 0i64;
    v43 = 0i64;
    mImposterGroupBuckets = this->mImposterGroupBuckets;
    v45 = this->mImposterGroupBuckets;
    mImposterGroupPtrs = this->mImposterGroupPtrs;
    mImposterGroupSectionUIDs = this->mImposterGroupSectionUIDs;
    v44 = this->mImposterGroupSectionUIDs;
    v12 = -136i64 - (_QWORD)this;
    while ( 1 )
    {
      if ( *mImposterGroupSectionUIDs != -1
        && *mImposterGroupPtrs
        && texInventory_0->vfptr->Get(texInventory_0, (*mImposterGroupPtrs)->mTextureUID[0]) )
      {
        v13 = (*mImposterGroupPtrs)->mTextureUID[0];
        mFarGroundImposterMaterial = this->mFarGroundImposterMaterial;
        if ( *(_DWORD *)&mFarGroundImposterMaterial[2].mDebugName[28] != v13 )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&mFarGroundImposterMaterial[2].mDebugName[4],
            *((_DWORD *)&mFarGroundImposterMaterial[2].UFG::qResourceData + 22),
            v13);
          mOffset = (_WORD *)mFarGroundImposterMaterial->mMaterialUser.mOffset;
          if ( mOffset )
            mOffset = (_WORD *)((char *)mOffset + (_QWORD)mFarGroundImposterMaterial + 120);
          *mOffset |= 0x20u;
        }
        v16 = (*mImposterGroupPtrs)->mTextureUID[1];
        v17 = this->mFarGroundImposterMaterial;
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
        v19 = (*mImposterGroupPtrs)->mTextureUID[2];
        v20 = this->mFarGroundImposterMaterial;
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
        v22 = (*mImposterGroupPtrs)->mTextureUID[3];
        v23 = this->mFarGroundImposterMaterial;
        if ( v23[4].mTypeUID != v22 )
        {
          UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v23[4].mNode.mUID, *(_DWORD *)&v23[4].mDebugName[4], v22);
          v24 = (_WORD *)v23->mMaterialUser.mOffset;
          if ( v24 )
            v24 = (_WORD *)((char *)v24 + (_QWORD)v23 + 120);
          *v24 |= 0x20u;
        }
        v25 = 0i64;
        v46 = 0;
        if ( mImposterGroupBuckets->mImposterBucketArray.size )
          break;
      }
LABEL_61:
      v44 = ++mImposterGroupSectionUIDs;
      ++mImposterGroupPtrs;
      v45 = ++mImposterGroupBuckets;
      v8 += 256i64;
      v43 = v8;
      if ( v8 >= 2048 )
        return;
    }
    while ( 1 )
    {
      v26 = (char *)this->mImposterGroupBuckets[0].mImposterBucketArray.p
          + (_QWORD)mImposterGroupBuckets
          + 36 * v25
          + v12;
      v27 = v26[8];
      if ( v27 )
      {
        if ( view->mSettings->mCullIndex
          || **((_BYTE **)&this->mImposterGroupCullResults[0][(unsigned int)v25] + v8) <= 1u )
        {
          break;
        }
      }
LABEL_59:
      v25 = (unsigned int)(v46 + 1);
      v46 = v25;
      if ( (unsigned int)v25 >= mImposterGroupBuckets->mImposterBucketArray.size )
      {
        mImposterGroupSectionUIDs = v44;
        goto LABEL_61;
      }
    }
    v28 = (unsigned __int8)v26[9];
    if ( v27 >= Render::TransparencySystem::msOpaqueIndex )
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
        v31 = this->mFarGroundImposterMaterial;
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
        mUID = v33->mNode.mUID;
        v35 = this->mFarGroundImposterMaterial;
        if ( *(_DWORD *)&v35[3].mDebugName[12] != mUID )
        {
          UFG::qResourceHandle::Init(
            (UFG::qResourceHandle *)&v35[3].mResourceHandles.UFG::qResourceData::mNode.mNext,
            *(_DWORD *)&v35[3].mDebugName[20],
            mUID);
          v36 = (_WORD *)v35->mMaterialUser.mOffset;
          if ( v36 )
            v36 = (_WORD *)((char *)v36 + (_QWORD)v35 + 120);
          *v36 |= 0x20u;
        }
        v37 = *(_DWORD *)v26;
        if ( *(_DWORD *)v26 < *(_DWORD *)v26 + (unsigned int)(unsigned __int8)v26[11] )
        {
          do
          {
            p_mImposters = &(*mImposterGroupPtrs)->mImposters;
            if ( p_mImposters->mOffset )
              v39 = (char *)p_mImposters + p_mImposters->mOffset;
            else
              v39 = 0i64;
            v40 = (UFG::qMatrix44 *)&v39[96 * v37];
            if ( !view->mSettings->mCullIndex
              || Render::View::IsInView(
                   view,
                   &this->mImposterModel,
                   (UFG::qMatrix44 *)&v39[96 * v37],
                   &distance_from_near_plane) )
            {
              v41 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x10u);
              UFG::qMemCopy(v41, &v40[1], 0x10u);
              v42 = Render::View::GetStateValues(view);
              v42->mSetValueMask.mFlags[0] |= 0x8000ui64;
              v42->mParamValues[15] = v41;
              Render::View::Draw(view, &this->mImposterModel, v40, 0, this->mFarGroundImposterMaterial);
            }
            ++v37;
          }
          while ( v37 < *(_DWORD *)v26 + (unsigned int)(unsigned __int8)v26[11] );
          mImposterGroupBuckets = v45;
        }
        v12 = -136i64 - (_QWORD)this;
        v8 = v43;
        goto LABEL_59;
      }
    }
    v30 = 662883558;
    goto LABEL_38;
  }
}

