// File Line: 105
// RVA: 0x29620
void __fastcall FastShadowDraw_Dynamic(
        Render::ViewSettings *view_settings,
        int main_view_cull_index,
        Illusion::RenderQueue **queues,
        unsigned int num_views)
{
  __int64 v4; // r15
  Illusion::RenderQueue **v5; // r13
  int v6; // esi
  Render::ViewSettings *v7; // rdi
  unsigned int v8; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v10; // rax
  char *v11; // rbx
  __int64 v12; // rsi
  UFG::qMatrix44 *v13; // rax
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  UFG::qVector4 v16; // xmm0
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **p_mNext; // r8
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v18; // r14
  char v19; // dl
  unsigned int v20; // edi
  __int64 *v21; // r15
  __int128 *v22; // r12
  Render::ViewSettings *v23; // r8
  int *p_mCullIndex; // rsi
  __int64 v25; // rax
  char *v26; // rbx
  UFG::qMatrix44 *v27; // rax
  UFG::qVector4 v28; // xmm2
  UFG::qVector4 v29; // xmm1
  UFG::qVector4 v30; // xmm0
  __int64 v31; // rcx
  unsigned int v32; // esi
  unsigned int v33; // edx
  __int64 v34; // rax
  __int64 v35; // rcx
  _QWORD *v36; // rdx
  Illusion::Mesh *v37; // r14
  Illusion::Material *v38; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  UFG::qResourceData *v40; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rcx
  char *v42; // rax
  UFG::qResourceData *v43; // rax
  unsigned int v44; // r12d
  __int64 v45; // r15
  unsigned int v46; // eax
  Illusion::RenderQueue *v47; // rbx
  Illusion::QueueCommandBucket *mFreeBucket; // rdx
  __int64 mNumCommands; // rax
  __int64 mCommands; // rcx
  char *v51; // rax
  Illusion::QueueCommandBucket *v52; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v53; // rax
  Illusion::QueueCommandBucket *v54; // rax
  Illusion::RenderQueue *v55; // rbx
  Illusion::QueueCommandBucket *v56; // rdx
  __int64 v57; // rax
  __int64 v58; // rcx
  char *v59; // rax
  Illusion::QueueCommandBucket *v60; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v61; // rax
  Illusion::QueueCommandBucket *v62; // rax
  Illusion::RenderQueue *v63; // rbx
  Illusion::QueueCommandBucket *v64; // rdx
  __int64 v65; // rax
  __int64 v66; // rcx
  char *v67; // rax
  Illusion::QueueCommandBucket *v68; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v69; // rax
  Illusion::QueueCommandBucket *v70; // rax
  AMD_HD3D *v71; // rdi
  Illusion::RenderQueue *v72; // rbx
  Illusion::QueueCommandBucket *v73; // rdx
  __int64 v74; // rax
  __int64 v75; // rcx
  char *v76; // rax
  Illusion::QueueCommandBucket *v77; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v78; // rax
  Illusion::QueueCommandBucket *v79; // rax
  __int128 *v80; // rdi
  UFG::qResourceData **p_mData; // r15
  __int64 v82; // r12
  UFG::qResourceData *v83; // r14
  Illusion::RenderQueue *v84; // rbx
  Illusion::QueueCommandBucket *v85; // rdx
  __int64 v86; // rcx
  __int64 v87; // rax
  char *v88; // rax
  Illusion::QueueCommandBucket *v89; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v90; // rax
  Illusion::QueueCommandBucket *v91; // rax
  __int64 v92; // r12
  Illusion::RenderQueue *v93; // rbx
  Illusion::QueueCommandBucket *v94; // rdx
  __int64 v95; // rax
  __int64 v96; // rcx
  char *v97; // rax
  Illusion::QueueCommandBucket *v98; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v99; // rax
  Illusion::QueueCommandBucket *v100; // rax
  __int64 v101; // rdi
  __int16 v102; // si
  Illusion::RenderQueue *v103; // rbx
  Illusion::QueueCommandBucket *v104; // rdx
  __int64 v105; // rax
  __int64 v106; // rcx
  char *v107; // rax
  Illusion::QueueCommandBucket *v108; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v109; // rax
  Illusion::QueueCommandBucket *v110; // rax
  Illusion::RenderQueue *v111; // rbx
  Illusion::QueueCommandBucket *v112; // rcx
  __int64 v113; // rdx
  __int64 v114; // rax
  char *v115; // rax
  Illusion::QueueCommandBucket *v116; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v117; // rax
  Illusion::QueueCommandBucket *v118; // rax
  __int64 v119; // rdx
  Illusion::RenderQueue *v120; // rcx
  Illusion::QueueCommandBucket *v121; // rax
  unsigned int v122; // [rsp+30h] [rbp-D0h]
  __int64 v123; // [rsp+38h] [rbp-C8h] BYREF
  int v124; // [rsp+40h] [rbp-C0h]
  char *v125; // [rsp+48h] [rbp-B8h]
  unsigned int v126; // [rsp+50h] [rbp-B0h]
  Illusion::Mesh *v127; // [rsp+58h] [rbp-A8h]
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **v128; // [rsp+60h] [rbp-A0h]
  char *v129; // [rsp+68h] [rbp-98h]
  void *v130; // [rsp+70h] [rbp-90h]
  __int64 v131; // [rsp+78h] [rbp-88h]
  UFG::qResourceData *v132; // [rsp+80h] [rbp-80h]
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v133; // [rsp+88h] [rbp-78h]
  UFG::qResourceData *mData; // [rsp+90h] [rbp-70h]
  UFG::qResourceData *v135; // [rsp+98h] [rbp-68h]
  __int64 v136; // [rsp+A0h] [rbp-60h]
  __int128 v137[6]; // [rsp+B0h] [rbp-50h] BYREF
  __int128 v138[3]; // [rsp+110h] [rbp+10h] BYREF
  AMD_HD3D *v139[2]; // [rsp+140h] [rbp+40h]
  __int128 v140; // [rsp+150h] [rbp+50h]
  AMD_HD3D *v141[2]; // [rsp+160h] [rbp+60h]
  AMD_HD3D *v142[2]; // [rsp+170h] [rbp+70h]
  __int128 v143; // [rsp+180h] [rbp+80h]
  __int128 v144; // [rsp+190h] [rbp+90h]
  __int128 v145; // [rsp+1A0h] [rbp+A0h]
  __int128 v146; // [rsp+1B0h] [rbp+B0h]
  __int128 v147; // [rsp+1C0h] [rbp+C0h]
  __int128 v148[6]; // [rsp+1D0h] [rbp+D0h] BYREF
  __int128 v149[6]; // [rsp+230h] [rbp+130h] BYREF
  __int128 v150[6]; // [rsp+290h] [rbp+190h] BYREF
  __int128 v151[24]; // [rsp+2F0h] [rbp+1F0h] BYREF
  UFG::qMatrix44 result; // [rsp+470h] [rbp+370h] BYREF
  char v153[32]; // [rsp+4B0h] [rbp+3B0h] BYREF
  char v154; // [rsp+4D0h] [rbp+3D0h] BYREF

  v136 = -2i64;
  v4 = num_views;
  v5 = queues;
  v6 = main_view_cull_index;
  v7 = view_settings;
  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&simpleHandle);
    atexit(FastShadowDraw_Dynamic_::_2_::_dynamic_atexit_destructor_for__simpleHandle__);
  }
  if ( !simpleInit )
  {
    v8 = UFG::qStringHashUpper32("DR_EmitDepth", 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v10 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v10, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&simpleHandle, 0x8B5561A1, v8, Inventory);
    simpleInit = 1;
  }
  *(_OWORD *)v142 = 0i64;
  v143 = 0i64;
  v144 = 0i64;
  v145 = 0i64;
  v146 = 0i64;
  v147 = 0i64;
  memset(v151, 0, sizeof(v151));
  memset(v149, 0, sizeof(v149));
  memset(v148, 0, sizeof(v148));
  memset(v138, 0, sizeof(v138));
  *(_OWORD *)v139 = 0i64;
  v140 = 0i64;
  *(_OWORD *)v141 = 0i64;
  memset(v137, 0, sizeof(v137));
  mData = AlphaStateNoColourWriteHandle.mData;
  v135 = RasterStateInvertCullingHandle.mData;
  if ( (_DWORD)v4 )
  {
    v11 = &v154;
    v12 = v4;
    do
    {
      v13 = UFG::qMatrix44::operator*(&v7->mWorldView, &result, &v7->mProjection);
      v14 = v13->v1;
      v15 = v13->v2;
      v16 = v13->v3;
      *((_OWORD *)v11 - 2) = v13->v0;
      *((UFG::qVector4 *)v11 - 1) = v14;
      *(UFG::qVector4 *)v11 = v15;
      *((UFG::qVector4 *)v11 + 1) = v16;
      ++v7;
      v11 += 64;
      --v12;
    }
    while ( v12 );
    v6 = main_view_cull_index;
  }
  p_mNext = &UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext;
  v128 = &UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext;
  while ( p_mNext != (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList
                                                                                            - 88) )
  {
    if ( ((_BYTE)p_mNext[7] & 3) == 1 )
    {
      v18 = p_mNext[15];
      v133 = p_mNext[19];
      if ( v133 )
      {
        if ( v18 && (v6 > 16 || v6 < 0 || (unsigned __int8)(*((_BYTE *)&v18->mPrev + v6) - 4) > 1u) )
        {
          v123 = 0i64;
          v124 = 0;
          v150[0] = (__int128)_mm_load_si128((const __m128i *)&_xmm);
          v150[1] = v150[0];
          v150[2] = v150[0];
          v150[3] = v150[0];
          v150[4] = v150[0];
          v150[5] = v150[0];
          v19 = 0;
          v20 = 0;
          if ( (_DWORD)v4 )
          {
            v21 = &v123;
            v22 = v150;
            v23 = view_settings;
            p_mCullIndex = &view_settings->mCullIndex;
            do
            {
              v25 = *p_mCullIndex;
              if ( (int)v25 >= 0
                && *((_BYTE *)&v18->mPrev + v25) <= 1u
                && (!v20 || v23[v20 - 1].mCullIndex < 0 || *((_BYTE *)&v18->mPrev + v23[v20 - 1].mCullIndex) != 1) )
              {
                v26 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
                v27 = UFG::qMatrix44::operator*(
                        (UFG::qMatrix44 *)(v128 + 22),
                        &result,
                        (UFG::qMatrix44 *)&v153[64 * (unsigned __int64)v20]);
                v28 = v27->v1;
                v29 = v27->v2;
                v30 = v27->v3;
                *(UFG::qVector4 *)v26 = v27->v0;
                *((UFG::qVector4 *)v26 + 1) = v28;
                *((UFG::qVector4 *)v26 + 2) = v29;
                *((UFG::qVector4 *)v26 + 3) = v30;
                *(_QWORD *)v22 = v26;
                v19 = 1;
                *(_BYTE *)v21 = 1;
                v23 = view_settings;
              }
              ++v20;
              p_mCullIndex += 36;
              v22 = (__int128 *)((char *)v22 + 8);
              v21 = (__int64 *)((char *)v21 + 1);
            }
            while ( v20 < num_views );
            v5 = queues;
            if ( v19 )
            {
              v31 = (__int64)v133;
              HIDWORD(v133[13].mPrev) = Illusion::gEngine.mFrameCount;
              v32 = 0;
              v33 = 0;
              v126 = 0;
              if ( *(_DWORD *)(v31 + 192) )
              {
                do
                {
                  v34 = *(_QWORD *)(v31 + 184);
                  if ( v34 )
                    v35 = v34 + v31 + 184;
                  else
                    v35 = 0i64;
                  v36 = (_QWORD *)(v35 + 8i64 * v33);
                  v37 = (Illusion::Mesh *)((char *)v36 + *v36);
                  if ( !*v36 )
                    v37 = 0i64;
                  v127 = v37;
                  v38 = (Illusion::Material *)v37->mMaterialHandle.mData;
                  if ( !Illusion::IEnginePlat::IsValidDrawCall(&Illusion::gEngine, v37, v38, 0i64, 0i64) )
                    goto LABEL_135;
                  mPrev = v38[1].mResourceHandles.UFG::qResourceData::mNode.mPrev;
                  v40 = simpleHandle.mData;
                  v132 = simpleHandle.mData;
                  if ( mPrev )
                  {
                    mNext = mPrev[6].mNext;
                    if ( mNext )
                    {
                      v42 = (char *)&mPrev[6].mNext + (_QWORD)mNext;
                      if ( v42 )
                      {
                        v43 = (UFG::qResourceData *)*((_QWORD *)v42 + 2);
                        if ( v43 )
                          v40 = v43;
                        v132 = v40;
                      }
                    }
                  }
                  v44 = 0;
                  v122 = 0;
                  v45 = 0i64;
                  v131 = 0i64;
                  v46 = num_views;
                  do
                  {
                    if ( !*((_BYTE *)&v123 + v45) )
                      goto LABEL_134;
                    if ( *((UFG::qResourceData **)v148 + v45) == v40 )
                      goto LABEL_73;
                    *((_QWORD *)v148 + v45) = v40;
                    *((_QWORD *)v137 + v45) = 0i64;
                    v47 = queues[v45];
                    mFreeBucket = v47->mFreeBucket;
                    if ( mFreeBucket )
                    {
                      mNumCommands = mFreeBucket->mNumCommands;
                      if ( (unsigned int)mNumCommands < 0x7E )
                      {
                        mCommands = (__int64)&mFreeBucket->mCommands[mNumCommands];
                        mFreeBucket->mNumCommands = mNumCommands + 1;
                        goto LABEL_51;
                      }
                      v47->mCommandCount += mFreeBucket->mNumCommands;
                      v47->mFreeBucket = 0i64;
                    }
                    v51 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v52 = (Illusion::QueueCommandBucket *)v51;
                    v130 = v51;
                    if ( v51 )
                    {
                      v125 = v51;
                      *(_QWORD *)v51 = v51;
                      *((_QWORD *)v51 + 1) = v51;
                      *((_QWORD *)v51 + 2) = 0i64;
                      *((_DWORD *)v51 + 6) = 0;
                      v53 = v47->mBuckets.mNode.mPrev;
                      v53->mNext = v52;
                      v52->mPrev = v53;
                      v52->mNext = &v47->mBuckets.mNode;
                      v47->mBuckets.mNode.mPrev = v52;
                      v47->mFreeBucket = v52;
                    }
                    v54 = v47->mFreeBucket;
                    if ( v54 )
                    {
                      v54->mNumCommands = 1;
                      mCommands = (__int64)v47->mFreeBucket->mCommands;
                      v40 = v132;
LABEL_51:
                      if ( mCommands )
                      {
                        *(_DWORD *)mCommands = 1;
                        *(_QWORD *)(mCommands + 8) = v40;
                      }
                    }
                    v55 = queues[v45];
                    v56 = v55->mFreeBucket;
                    if ( v56 )
                    {
                      v57 = v56->mNumCommands;
                      if ( (unsigned int)v57 < 0x7E )
                      {
                        v58 = (__int64)&v56->mCommands[v57];
                        v56->mNumCommands = v57 + 1;
                        goto LABEL_61;
                      }
                      v55->mCommandCount += v56->mNumCommands;
                      v55->mFreeBucket = 0i64;
                    }
                    v59 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v60 = (Illusion::QueueCommandBucket *)v59;
                    v125 = v59;
                    if ( v59 )
                    {
                      v130 = v59;
                      *(_QWORD *)v59 = v59;
                      *((_QWORD *)v59 + 1) = v59;
                      *((_QWORD *)v59 + 2) = 0i64;
                      *((_DWORD *)v59 + 6) = 0;
                      v61 = v55->mBuckets.mNode.mPrev;
                      v61->mNext = v60;
                      v60->mPrev = v61;
                      v60->mNext = &v55->mBuckets.mNode;
                      v55->mBuckets.mNode.mPrev = v60;
                      v55->mFreeBucket = v60;
                    }
                    v62 = v55->mFreeBucket;
                    if ( !v62 )
                      goto LABEL_63;
                    v62->mNumCommands = 1;
                    v58 = (__int64)v55->mFreeBucket->mCommands;
LABEL_61:
                    if ( v58 )
                    {
                      *(_DWORD *)v58 = 7;
                      *(_QWORD *)(v58 + 8) = mData;
                    }
LABEL_63:
                    v63 = queues[v45];
                    v64 = v63->mFreeBucket;
                    if ( v64 )
                    {
                      v65 = v64->mNumCommands;
                      if ( (unsigned int)v65 < 0x7E )
                      {
                        v66 = (__int64)&v64->mCommands[v65];
                        v64->mNumCommands = v65 + 1;
                        goto LABEL_71;
                      }
                      v63->mCommandCount += v64->mNumCommands;
                      v63->mFreeBucket = 0i64;
                    }
                    v67 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v68 = (Illusion::QueueCommandBucket *)v67;
                    v125 = v67;
                    if ( v67 )
                    {
                      v130 = v67;
                      *(_QWORD *)v67 = v67;
                      *((_QWORD *)v67 + 1) = v67;
                      *((_QWORD *)v67 + 2) = 0i64;
                      *((_DWORD *)v67 + 6) = 0;
                      v69 = v63->mBuckets.mNode.mPrev;
                      v69->mNext = v68;
                      v68->mPrev = v69;
                      v68->mNext = &v63->mBuckets.mNode;
                      v63->mBuckets.mNode.mPrev = v68;
                      v63->mFreeBucket = v68;
                    }
                    v70 = v63->mFreeBucket;
                    if ( v70 )
                    {
                      v70->mNumCommands = 1;
                      v66 = (__int64)v63->mFreeBucket->mCommands;
LABEL_71:
                      if ( v66 )
                      {
                        *(_DWORD *)v66 = 8;
                        *(_QWORD *)(v66 + 8) = v135;
                      }
                    }
LABEL_73:
                    if ( *((Illusion::Mesh **)v138 + v45) == v37 )
                      goto LABEL_111;
                    *((_QWORD *)v138 + v45) = v37;
                    v71 = (AMD_HD3D *)v37->mVertexDeclHandle.mData;
                    v130 = v37->mIndexBufferHandle.mData;
                    if ( v142[v45] == v71 )
                      goto LABEL_85;
                    v142[v45] = v71;
                    v72 = queues[v45];
                    v73 = v72->mFreeBucket;
                    if ( v73 )
                    {
                      v74 = v73->mNumCommands;
                      if ( (unsigned int)v74 < 0x7E )
                      {
                        v75 = (__int64)&v73->mCommands[v74];
                        v73->mNumCommands = v74 + 1;
                        goto LABEL_83;
                      }
                      v72->mCommandCount += v73->mNumCommands;
                      v72->mFreeBucket = 0i64;
                    }
                    v76 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v77 = (Illusion::QueueCommandBucket *)v76;
                    v125 = v76;
                    if ( v76 )
                    {
                      v129 = v76;
                      *(_QWORD *)v76 = v76;
                      *((_QWORD *)v76 + 1) = v76;
                      *((_QWORD *)v76 + 2) = 0i64;
                      *((_DWORD *)v76 + 6) = 0;
                      v78 = v72->mBuckets.mNode.mPrev;
                      v78->mNext = v77;
                      v77->mPrev = v78;
                      v77->mNext = &v72->mBuckets.mNode;
                      v72->mBuckets.mNode.mPrev = v77;
                      v72->mFreeBucket = v77;
                    }
                    v79 = v72->mFreeBucket;
                    if ( !v79 )
                      goto LABEL_85;
                    v79->mNumCommands = 1;
                    v75 = (__int64)v72->mFreeBucket->mCommands;
LABEL_83:
                    if ( v75 )
                    {
                      *(_DWORD *)v75 = 3;
                      *(_QWORD *)(v75 + 8) = v71;
                    }
LABEL_85:
                    v80 = &v151[2 * v45];
                    p_mData = &v37->mVertexBufferHandles[0].mData;
                    v82 = v131;
                    do
                    {
                      v83 = *p_mData;
                      if ( *(UFG::qResourceData **)v80 == *p_mData )
                        goto LABEL_97;
                      *(_QWORD *)v80 = v83;
                      v84 = queues[v82];
                      v85 = v84->mFreeBucket;
                      if ( v85 )
                      {
                        v86 = v85->mNumCommands;
                        if ( (unsigned int)v86 < 0x7E )
                        {
                          v87 = (__int64)&v85->mCommands[v86];
                          v85->mNumCommands = v86 + 1;
                          goto LABEL_95;
                        }
                        v84->mCommandCount += v85->mNumCommands;
                        v84->mFreeBucket = 0i64;
                      }
                      v88 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                      v89 = (Illusion::QueueCommandBucket *)v88;
                      v129 = v88;
                      if ( v88 )
                      {
                        v125 = v88;
                        *(_QWORD *)v88 = v88;
                        *((_QWORD *)v88 + 1) = v88;
                        *((_QWORD *)v88 + 2) = 0i64;
                        *((_DWORD *)v88 + 6) = 0;
                        v90 = v84->mBuckets.mNode.mPrev;
                        v90->mNext = v89;
                        v89->mPrev = v90;
                        v89->mNext = &v84->mBuckets.mNode;
                        v84->mBuckets.mNode.mPrev = v89;
                        v84->mFreeBucket = v89;
                      }
                      v91 = v84->mFreeBucket;
                      if ( v91 )
                      {
                        v91->mNumCommands = 1;
                        v87 = (__int64)v84->mFreeBucket->mCommands;
LABEL_95:
                        if ( v87 )
                        {
                          *(_WORD *)v87 = 5;
                          *(_WORD *)(v87 + 2) = v32;
                          *(_QWORD *)(v87 + 8) = v83;
                        }
                      }
LABEL_97:
                      ++v32;
                      v80 = (__int128 *)((char *)v80 + 8);
                      p_mData += 4;
                    }
                    while ( v32 < 4 );
                    v92 = (__int64)v130;
                    v45 = v131;
                    if ( *((void **)v149 + v131) == v130 )
                      goto LABEL_110;
                    *((_QWORD *)v149 + v131) = v130;
                    v93 = queues[v45];
                    v94 = v93->mFreeBucket;
                    if ( v94 )
                    {
                      v95 = v94->mNumCommands;
                      if ( (unsigned int)v95 < 0x7E )
                      {
                        v96 = (__int64)&v94->mCommands[v95];
                        v94->mNumCommands = v95 + 1;
                        goto LABEL_107;
                      }
                      v93->mCommandCount += v94->mNumCommands;
                      v93->mFreeBucket = 0i64;
                    }
                    v97 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v98 = (Illusion::QueueCommandBucket *)v97;
                    v129 = v97;
                    if ( v97 )
                    {
                      v125 = v97;
                      *(_QWORD *)v97 = v97;
                      *((_QWORD *)v97 + 1) = v97;
                      *((_QWORD *)v97 + 2) = 0i64;
                      *((_DWORD *)v97 + 6) = 0;
                      v99 = v93->mBuckets.mNode.mPrev;
                      v99->mNext = v98;
                      v98->mPrev = v99;
                      v98->mNext = &v93->mBuckets.mNode;
                      v93->mBuckets.mNode.mPrev = v98;
                      v93->mFreeBucket = v98;
                    }
                    v100 = v93->mFreeBucket;
                    if ( !v100 )
                    {
LABEL_110:
                      v37 = v127;
                      v44 = v122;
                    }
                    else
                    {
                      v100->mNumCommands = 1;
                      v96 = (__int64)v93->mFreeBucket->mCommands;
LABEL_107:
                      v37 = v127;
                      if ( v96 )
                      {
                        *(_DWORD *)v96 = 4;
                        *(_QWORD *)(v96 + 8) = v92;
                      }
                      v44 = v122;
                    }
LABEL_111:
                    v101 = *((_QWORD *)v150 + v45);
                    if ( *((_QWORD *)v137 + v45) == v101 )
                      goto LABEL_122;
                    *((_QWORD *)v137 + v45) = v101;
                    v102 = Render::cbLocalProjectionState::sStateParamIndex;
                    v103 = queues[v45];
                    v104 = v103->mFreeBucket;
                    if ( v104 )
                    {
                      v105 = v104->mNumCommands;
                      if ( (unsigned int)v105 < 0x7E )
                      {
                        v106 = (__int64)&v104->mCommands[v105];
                        v104->mNumCommands = v105 + 1;
LABEL_120:
                        if ( v106 )
                        {
                          *(_WORD *)v106 = 2;
                          *(_WORD *)(v106 + 2) = v102;
                          *(_QWORD *)(v106 + 8) = v101;
                        }
                        goto LABEL_122;
                      }
                      v103->mCommandCount += v104->mNumCommands;
                      v103->mFreeBucket = 0i64;
                    }
                    v107 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v108 = (Illusion::QueueCommandBucket *)v107;
                    v129 = v107;
                    if ( v107 )
                    {
                      v125 = v107;
                      *(_QWORD *)v107 = v107;
                      *((_QWORD *)v107 + 1) = v107;
                      *((_QWORD *)v107 + 2) = 0i64;
                      *((_DWORD *)v107 + 6) = 0;
                      v109 = v103->mBuckets.mNode.mPrev;
                      v109->mNext = v108;
                      v108->mPrev = v109;
                      v108->mNext = &v103->mBuckets.mNode;
                      v103->mBuckets.mNode.mPrev = v108;
                      v103->mFreeBucket = v108;
                    }
                    v110 = v103->mFreeBucket;
                    if ( v110 )
                    {
                      v110->mNumCommands = 1;
                      v106 = (__int64)v103->mFreeBucket->mCommands;
                      goto LABEL_120;
                    }
LABEL_122:
                    v111 = queues[v45];
                    v112 = v111->mFreeBucket;
                    if ( v112 )
                    {
                      v113 = v112->mNumCommands;
                      if ( (unsigned int)v113 < 0x7E )
                      {
                        v112->mNumCommands = v113 + 1;
                        v114 = (__int64)&v112->mCommands[v113];
LABEL_130:
                        v32 = 0;
                        if ( v114 )
                        {
                          *(_DWORD *)v114 = 10;
                          *(_QWORD *)(v114 + 8) = v37;
                        }
                        goto LABEL_133;
                      }
                      v111->mCommandCount += v112->mNumCommands;
                      v111->mFreeBucket = 0i64;
                    }
                    v115 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v116 = (Illusion::QueueCommandBucket *)v115;
                    v129 = v115;
                    if ( v115 )
                    {
                      v125 = v115;
                      *(_QWORD *)v115 = v115;
                      *((_QWORD *)v115 + 1) = v115;
                      *((_QWORD *)v115 + 2) = 0i64;
                      *((_DWORD *)v115 + 6) = 0;
                      v117 = v111->mBuckets.mNode.mPrev;
                      v117->mNext = v116;
                      v116->mPrev = v117;
                      v116->mNext = &v111->mBuckets.mNode;
                      v111->mBuckets.mNode.mPrev = v116;
                      v111->mFreeBucket = v116;
                    }
                    v118 = v111->mFreeBucket;
                    if ( v118 )
                    {
                      v118->mNumCommands = 1;
                      v114 = (__int64)v111->mFreeBucket->mCommands;
                      goto LABEL_130;
                    }
                    v32 = 0;
LABEL_133:
                    queues[v45]->mPrimitiveCount += v37->mNumPrims;
                    v40 = v132;
                    v46 = num_views;
LABEL_134:
                    v122 = ++v44;
                    v131 = ++v45;
                  }
                  while ( v44 < v46 );
LABEL_135:
                  v33 = v126 + 1;
                  v126 = v33;
                  v31 = (__int64)v133;
                }
                while ( v33 < LODWORD(v133[12].mPrev) );
              }
            }
            p_mNext = v128;
            LODWORD(v4) = num_views;
          }
        }
      }
    }
    p_mNext = &p_mNext[12][-6].mNext;
    v128 = p_mNext;
    v6 = main_view_cull_index;
  }
  if ( (_DWORD)v4 )
  {
    v119 = (unsigned int)v4;
    do
    {
      v120 = *v5;
      v121 = (*v5)->mFreeBucket;
      if ( v121 )
      {
        v120->mCommandCount += v121->mNumCommands;
        v120->mFreeBucket = 0i64;
      }
      ++v5;
      --v119;
    }
    while ( v119 );
  }
}

