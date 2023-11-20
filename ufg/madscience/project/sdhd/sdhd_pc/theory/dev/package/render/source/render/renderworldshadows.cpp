// File Line: 105
// RVA: 0x29620
void __fastcall FastShadowDraw_Dynamic(Render::ViewSettings *view_settings, int main_view_cull_index, Illusion::RenderQueue **queues, unsigned int num_views)
{
  __int64 v4; // r15
  Illusion::RenderQueue **v5; // r13
  int v6; // esi
  Render::ViewSettings *v7; // rdi
  unsigned int v8; // ebx
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax
  char *v11; // rbx
  __int64 v12; // rsi
  UFG::qMatrix44 *v13; // rax
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  UFG::qVector4 v16; // xmm0
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **v17; // r8
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v18; // r14
  __m128i v19; // xmm0
  char v20; // dl
  unsigned int v21; // edi
  __int64 *v22; // r15
  __int128 *v23; // r12
  Render::ViewSettings *v24; // r8
  int *v25; // rsi
  __int64 v26; // rax
  char *v27; // rbx
  UFG::qMatrix44 *v28; // rax
  UFG::qVector4 v29; // xmm2
  UFG::qVector4 v30; // xmm1
  UFG::qVector4 v31; // xmm0
  __int64 v32; // rcx
  unsigned int v33; // esi
  unsigned int v34; // edx
  __int64 v35; // rax
  signed __int64 v36; // rcx
  _QWORD *v37; // rdx
  __int64 v38; // r14
  __int64 v39; // rbx
  __int64 v40; // rax
  UFG::qResourceData *v41; // r8
  __int64 v42; // rcx
  signed __int64 v43; // rax
  UFG::qResourceData *v44; // rax
  unsigned int v45; // er12
  __int64 v46; // r15
  unsigned int v47; // eax
  Illusion::RenderQueue *v48; // rbx
  Illusion::QueueCommandBucket *v49; // rdx
  __int64 v50; // rax
  signed __int64 v51; // rcx
  char *v52; // rax
  char *v53; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v54; // rax
  Illusion::QueueCommandBucket *v55; // rax
  Illusion::RenderQueue *v56; // rbx
  Illusion::QueueCommandBucket *v57; // rdx
  __int64 v58; // rax
  signed __int64 v59; // rcx
  char *v60; // rax
  char *v61; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v62; // rax
  Illusion::QueueCommandBucket *v63; // rax
  Illusion::RenderQueue *v64; // rbx
  Illusion::QueueCommandBucket *v65; // rdx
  __int64 v66; // rax
  signed __int64 v67; // rcx
  char *v68; // rax
  char *v69; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v70; // rax
  Illusion::QueueCommandBucket *v71; // rax
  AMD_HD3D *v72; // rdi
  Illusion::RenderQueue *v73; // rbx
  Illusion::QueueCommandBucket *v74; // rdx
  __int64 v75; // rax
  signed __int64 v76; // rcx
  char *v77; // rax
  char *v78; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v79; // rax
  Illusion::QueueCommandBucket *v80; // rax
  __int128 *v81; // rdi
  __int64 *v82; // r15
  __int64 v83; // r12
  __int64 v84; // r14
  Illusion::RenderQueue *v85; // rbx
  Illusion::QueueCommandBucket *v86; // rdx
  __int64 v87; // rcx
  signed __int64 v88; // rax
  char *v89; // rax
  char *v90; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v91; // rax
  Illusion::QueueCommandBucket *v92; // rax
  __int64 v93; // r12
  Illusion::RenderQueue *v94; // rbx
  Illusion::QueueCommandBucket *v95; // rdx
  __int64 v96; // rax
  signed __int64 v97; // rcx
  char *v98; // rax
  char *v99; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v100; // rax
  Illusion::QueueCommandBucket *v101; // rax
  __int64 v102; // rdi
  __int16 v103; // si
  Illusion::RenderQueue *v104; // rbx
  Illusion::QueueCommandBucket *v105; // rdx
  __int64 v106; // rax
  signed __int64 v107; // rcx
  char *v108; // rax
  char *v109; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v110; // rax
  Illusion::QueueCommandBucket *v111; // rax
  Illusion::RenderQueue *v112; // rbx
  Illusion::QueueCommandBucket *v113; // rcx
  __int64 v114; // rdx
  signed __int64 v115; // rax
  char *v116; // rax
  char *v117; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v118; // rax
  Illusion::QueueCommandBucket *v119; // rax
  __int64 v120; // rdx
  Illusion::RenderQueue *v121; // rcx
  Illusion::QueueCommandBucket *v122; // rax
  unsigned int v123; // [rsp+30h] [rbp-D0h]
  __int64 v124; // [rsp+38h] [rbp-C8h]
  int v125; // [rsp+40h] [rbp-C0h]
  char *v126; // [rsp+48h] [rbp-B8h]
  unsigned int v127; // [rsp+50h] [rbp-B0h]
  __int64 v128; // [rsp+58h] [rbp-A8h]
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **v129; // [rsp+60h] [rbp-A0h]
  char *v130; // [rsp+68h] [rbp-98h]
  char *v131; // [rsp+70h] [rbp-90h]
  __int64 v132; // [rsp+78h] [rbp-88h]
  UFG::qResourceData *v133; // [rsp+80h] [rbp-80h]
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v134; // [rsp+88h] [rbp-78h]
  UFG::qResourceData *v135; // [rsp+90h] [rbp-70h]
  UFG::qResourceData *v136; // [rsp+98h] [rbp-68h]
  __int64 v137; // [rsp+A0h] [rbp-60h]
  __int128 v138; // [rsp+B0h] [rbp-50h]
  __int128 v139; // [rsp+C0h] [rbp-40h]
  __int128 v140; // [rsp+D0h] [rbp-30h]
  __int128 v141; // [rsp+E0h] [rbp-20h]
  __int128 v142; // [rsp+F0h] [rbp-10h]
  __int128 v143; // [rsp+100h] [rbp+0h]
  __int128 v144; // [rsp+110h] [rbp+10h]
  __int128 v145; // [rsp+120h] [rbp+20h]
  __int128 v146; // [rsp+130h] [rbp+30h]
  AMD_HD3D *v147[2]; // [rsp+140h] [rbp+40h]
  __int128 v148; // [rsp+150h] [rbp+50h]
  AMD_HD3D *v149[2]; // [rsp+160h] [rbp+60h]
  AMD_HD3D *v150[2]; // [rsp+170h] [rbp+70h]
  __int128 v151; // [rsp+180h] [rbp+80h]
  __int128 v152; // [rsp+190h] [rbp+90h]
  __int128 v153; // [rsp+1A0h] [rbp+A0h]
  __int128 v154; // [rsp+1B0h] [rbp+B0h]
  __int128 v155; // [rsp+1C0h] [rbp+C0h]
  __int128 v156; // [rsp+1D0h] [rbp+D0h]
  __int128 v157; // [rsp+1E0h] [rbp+E0h]
  __int128 v158; // [rsp+1F0h] [rbp+F0h]
  __int128 v159; // [rsp+200h] [rbp+100h]
  __int128 v160; // [rsp+210h] [rbp+110h]
  __int128 v161; // [rsp+220h] [rbp+120h]
  __int128 v162; // [rsp+230h] [rbp+130h]
  __int128 v163; // [rsp+240h] [rbp+140h]
  __int128 v164; // [rsp+250h] [rbp+150h]
  __int128 v165; // [rsp+260h] [rbp+160h]
  __int128 v166; // [rsp+270h] [rbp+170h]
  __int128 v167; // [rsp+280h] [rbp+180h]
  __int128 v168; // [rsp+290h] [rbp+190h]
  __int128 v169; // [rsp+2A0h] [rbp+1A0h]
  __int128 v170; // [rsp+2B0h] [rbp+1B0h]
  __int128 v171; // [rsp+2C0h] [rbp+1C0h]
  __int128 v172; // [rsp+2D0h] [rbp+1D0h]
  __int128 v173; // [rsp+2E0h] [rbp+1E0h]
  __int128 v174; // [rsp+2F0h] [rbp+1F0h]
  __int128 v175; // [rsp+300h] [rbp+200h]
  __int128 v176; // [rsp+310h] [rbp+210h]
  __int128 v177; // [rsp+320h] [rbp+220h]
  __int128 v178; // [rsp+330h] [rbp+230h]
  __int128 v179; // [rsp+340h] [rbp+240h]
  __int128 v180; // [rsp+350h] [rbp+250h]
  __int128 v181; // [rsp+360h] [rbp+260h]
  __int128 v182; // [rsp+370h] [rbp+270h]
  __int128 v183; // [rsp+380h] [rbp+280h]
  __int128 v184; // [rsp+390h] [rbp+290h]
  __int128 v185; // [rsp+3A0h] [rbp+2A0h]
  __int128 v186; // [rsp+3B0h] [rbp+2B0h]
  __int128 v187; // [rsp+3C0h] [rbp+2C0h]
  __int128 v188; // [rsp+3D0h] [rbp+2D0h]
  __int128 v189; // [rsp+3E0h] [rbp+2E0h]
  __int128 v190; // [rsp+3F0h] [rbp+2F0h]
  __int128 v191; // [rsp+400h] [rbp+300h]
  __int128 v192; // [rsp+410h] [rbp+310h]
  __int128 v193; // [rsp+420h] [rbp+320h]
  __int128 v194; // [rsp+430h] [rbp+330h]
  __int128 v195; // [rsp+440h] [rbp+340h]
  __int128 v196; // [rsp+450h] [rbp+350h]
  __int128 v197; // [rsp+460h] [rbp+360h]
  UFG::qMatrix44 result; // [rsp+470h] [rbp+370h]
  char v199[32]; // [rsp+4B0h] [rbp+3B0h]
  char v200; // [rsp+4D0h] [rbp+3D0h]
  Render::ViewSettings *v201; // [rsp+800h] [rbp+700h]
  int v202; // [rsp+808h] [rbp+708h]
  Illusion::RenderQueue **v203; // [rsp+810h] [rbp+710h]
  unsigned int v204; // [rsp+818h] [rbp+718h]

  v204 = num_views;
  v203 = queues;
  v202 = main_view_cull_index;
  v201 = view_settings;
  v137 = -2i64;
  v4 = num_views;
  v5 = queues;
  v6 = main_view_cull_index;
  v7 = view_settings;
  if ( !(_S1_4 & 1) )
  {
    _S1_4 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&simpleHandle.mPrev);
    atexit(FastShadowDraw_Dynamic_::_2_::_dynamic_atexit_destructor_for__simpleHandle__);
  }
  if ( !simpleInit )
  {
    v8 = UFG::qStringHashUpper32("DR_EmitDepth", 0xFFFFFFFF);
    v9 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
    {
      v10 = UFG::qResourceWarehouse::Instance();
      v9 = UFG::qResourceWarehouse::GetInventory(v10, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v9;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&simpleHandle.mPrev, 0x8B5561A1, v8, v9);
    simpleInit = 1;
  }
  _mm_store_si128((__m128i *)v150, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v151, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v152, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v153, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v154, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v155, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v174, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v175, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v176, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v177, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v178, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v179, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v180, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v181, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v182, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v183, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v184, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v185, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v186, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v187, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v188, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v189, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v190, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v191, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v192, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v193, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v194, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v195, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v196, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v197, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v162, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v163, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v164, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v165, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v166, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v167, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v156, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v157, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v158, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v159, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v160, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v161, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v144, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v145, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v146, (__m128i)0i64);
  _mm_store_si128((__m128i *)v147, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v148, (__m128i)0i64);
  _mm_store_si128((__m128i *)v149, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v138, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v139, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v140, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v141, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v142, (__m128i)0i64);
  _mm_store_si128((__m128i *)&v143, (__m128i)0i64);
  v135 = AlphaStateNoColourWriteHandle.mData;
  v136 = RasterStateInvertCullingHandle.mData;
  if ( (_DWORD)v4 )
  {
    v11 = &v200;
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
    v6 = v202;
  }
  v17 = &UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext;
  v129 = &UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext;
  while ( v17 != (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList
                                                                                        - 88) )
  {
    if ( ((_BYTE)v17[7] & 3) == 1 )
    {
      v18 = v17[15];
      v134 = v17[19];
      if ( v134 )
      {
        if ( v18 && (v6 > 16 || v6 < 0 || (unsigned __int8)(*((_BYTE *)&v18->mPrev + v6) - 4) > 1u) )
        {
          v124 = 0i64;
          v125 = 0;
          v19 = _mm_load_si128((const __m128i *)&_xmm);
          _mm_store_si128((__m128i *)&v168, v19);
          _mm_store_si128((__m128i *)&v169, v19);
          _mm_store_si128((__m128i *)&v170, v19);
          _mm_store_si128((__m128i *)&v171, v19);
          _mm_store_si128((__m128i *)&v172, v19);
          _mm_store_si128((__m128i *)&v173, v19);
          v20 = 0;
          v21 = 0;
          if ( (_DWORD)v4 )
          {
            v22 = &v124;
            v23 = &v168;
            v24 = v201;
            v25 = &v201->mCullIndex;
            do
            {
              v26 = *v25;
              if ( (signed int)v26 >= 0
                && *((_BYTE *)&v18->mPrev + v26) <= 1u
                && (!v21 || v24[v21 - 1].mCullIndex < 0 || *((_BYTE *)&v18->mPrev + v24[v21 - 1].mCullIndex) != 1) )
              {
                v27 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
                v28 = UFG::qMatrix44::operator*(
                        (UFG::qMatrix44 *)(v129 + 22),
                        &result,
                        (UFG::qMatrix44 *)&v199[64 * (unsigned __int64)v21]);
                v29 = v28->v1;
                v30 = v28->v2;
                v31 = v28->v3;
                *(UFG::qVector4 *)v27 = v28->v0;
                *((UFG::qVector4 *)v27 + 1) = v29;
                *((UFG::qVector4 *)v27 + 2) = v30;
                *((UFG::qVector4 *)v27 + 3) = v31;
                *(_QWORD *)v23 = v27;
                v20 = 1;
                *(_BYTE *)v22 = 1;
                v24 = v201;
              }
              ++v21;
              v25 += 36;
              v23 = (__int128 *)((char *)v23 + 8);
              v22 = (__int64 *)((char *)v22 + 1);
            }
            while ( v21 < v204 );
            v5 = v203;
            if ( v20 )
            {
              v32 = (__int64)v134;
              HIDWORD(v134[13].mPrev) = Illusion::gEngine.mFrameCount;
              v33 = 0;
              v34 = 0;
              v127 = 0;
              if ( *(_DWORD *)(v32 + 192) )
              {
                do
                {
                  v35 = *(_QWORD *)(v32 + 184);
                  if ( v35 )
                    v36 = v35 + v32 + 184;
                  else
                    v36 = 0i64;
                  v37 = (_QWORD *)(v36 + 8i64 * v34);
                  v38 = (__int64)v37 + *v37;
                  if ( !*v37 )
                    v38 = 0i64;
                  v128 = v38;
                  v39 = *(_QWORD *)(v38 + 16);
                  if ( !Illusion::IEnginePlat::IsValidDrawCall(
                          (Illusion::IEnginePlat *)&Illusion::gEngine,
                          (Illusion::Mesh *)v38,
                          *(Illusion::Material **)(v38 + 16),
                          0i64,
                          0i64) )
                    goto LABEL_143;
                  v40 = *(_QWORD *)(v39 + 160);
                  v41 = simpleHandle.mData;
                  v133 = simpleHandle.mData;
                  if ( v40 )
                  {
                    v42 = *(_QWORD *)(v40 + 104);
                    if ( v42 )
                    {
                      v43 = v42 + v40 + 104;
                      if ( v43 )
                      {
                        v44 = *(UFG::qResourceData **)(v43 + 16);
                        if ( v44 )
                          v41 = v44;
                        v133 = v41;
                      }
                    }
                  }
                  v45 = 0;
                  v123 = 0;
                  v46 = 0i64;
                  v132 = 0i64;
                  v47 = v204;
                  do
                  {
                    if ( !*((_BYTE *)&v124 + v46) )
                      goto LABEL_142;
                    if ( *((UFG::qResourceData **)&v156 + v46) == v41 )
                      goto LABEL_76;
                    *((_QWORD *)&v156 + v46) = v41;
                    *((_QWORD *)&v138 + v46) = 0i64;
                    v48 = v203[v46];
                    v49 = v48->mFreeBucket;
                    if ( v49 )
                    {
                      v50 = v49->mNumCommands;
                      if ( (unsigned int)v50 < 0x7E )
                      {
                        v51 = (signed __int64)v49 + 16 * (v50 + 2);
                        v49->mNumCommands = v50 + 1;
                        goto LABEL_52;
                      }
                      if ( v49 )
                      {
                        v48->mCommandCount += v49->mNumCommands;
                        v48->mFreeBucket = 0i64;
                      }
                    }
                    v52 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v53 = v52;
                    v131 = v52;
                    if ( v52 )
                    {
                      v126 = v52;
                      *(_QWORD *)v52 = v52;
                      *((_QWORD *)v52 + 1) = v52;
                      *((_QWORD *)v52 + 2) = 0i64;
                      *((_DWORD *)v52 + 6) = 0;
                      v54 = v48->mBuckets.mNode.mPrev;
                      v54->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v53;
                      *(_QWORD *)v53 = v54;
                      *((_QWORD *)v53 + 1) = (char *)v48 + 16;
                      v48->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v53;
                      v48->mFreeBucket = (Illusion::QueueCommandBucket *)v53;
                    }
                    v55 = v48->mFreeBucket;
                    if ( v55 )
                    {
                      v55->mNumCommands = 1;
                      v51 = (signed __int64)v48->mFreeBucket->mCommands;
                      v41 = v133;
LABEL_52:
                      if ( v51 )
                      {
                        *(_DWORD *)v51 = 1;
                        *(_QWORD *)(v51 + 8) = v41;
                      }
                    }
                    v56 = v203[v46];
                    v57 = v56->mFreeBucket;
                    if ( v57 )
                    {
                      v58 = v57->mNumCommands;
                      if ( (unsigned int)v58 < 0x7E )
                      {
                        v59 = (signed __int64)v57 + 16 * (v58 + 2);
                        v57->mNumCommands = v58 + 1;
                        goto LABEL_63;
                      }
                      if ( v57 )
                      {
                        v56->mCommandCount += v57->mNumCommands;
                        v56->mFreeBucket = 0i64;
                      }
                    }
                    v60 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v61 = v60;
                    v126 = v60;
                    if ( v60 )
                    {
                      v131 = v60;
                      *(_QWORD *)v60 = v60;
                      *((_QWORD *)v60 + 1) = v60;
                      *((_QWORD *)v60 + 2) = 0i64;
                      *((_DWORD *)v60 + 6) = 0;
                      v62 = v56->mBuckets.mNode.mPrev;
                      v62->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v61;
                      *(_QWORD *)v61 = v62;
                      *((_QWORD *)v61 + 1) = (char *)v56 + 16;
                      v56->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v61;
                      v56->mFreeBucket = (Illusion::QueueCommandBucket *)v61;
                    }
                    v63 = v56->mFreeBucket;
                    if ( !v63 )
                      goto LABEL_65;
                    v63->mNumCommands = 1;
                    v59 = (signed __int64)v56->mFreeBucket->mCommands;
LABEL_63:
                    if ( v59 )
                    {
                      *(_DWORD *)v59 = 7;
                      *(_QWORD *)(v59 + 8) = v135;
                    }
LABEL_65:
                    v64 = v203[v46];
                    v65 = v64->mFreeBucket;
                    if ( v65 )
                    {
                      v66 = v65->mNumCommands;
                      if ( (unsigned int)v66 < 0x7E )
                      {
                        v67 = (signed __int64)v65 + 16 * (v66 + 2);
                        v65->mNumCommands = v66 + 1;
                        goto LABEL_74;
                      }
                      if ( v65 )
                      {
                        v64->mCommandCount += v65->mNumCommands;
                        v64->mFreeBucket = 0i64;
                      }
                    }
                    v68 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v69 = v68;
                    v126 = v68;
                    if ( v68 )
                    {
                      v131 = v68;
                      *(_QWORD *)v68 = v68;
                      *((_QWORD *)v68 + 1) = v68;
                      *((_QWORD *)v68 + 2) = 0i64;
                      *((_DWORD *)v68 + 6) = 0;
                      v70 = v64->mBuckets.mNode.mPrev;
                      v70->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v69;
                      *(_QWORD *)v69 = v70;
                      *((_QWORD *)v69 + 1) = (char *)v64 + 16;
                      v64->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v69;
                      v64->mFreeBucket = (Illusion::QueueCommandBucket *)v69;
                    }
                    v71 = v64->mFreeBucket;
                    if ( v71 )
                    {
                      v71->mNumCommands = 1;
                      v67 = (signed __int64)v64->mFreeBucket->mCommands;
LABEL_74:
                      if ( v67 )
                      {
                        *(_DWORD *)v67 = 8;
                        *(_QWORD *)(v67 + 8) = v136;
                      }
                    }
LABEL_76:
                    if ( *((_QWORD *)&v144 + v46) == v38 )
                      goto LABEL_117;
                    *((_QWORD *)&v144 + v46) = v38;
                    v72 = *(AMD_HD3D **)(v38 + 48);
                    v131 = *(char **)(v38 + 80);
                    if ( v150[v46] == v72 )
                      goto LABEL_89;
                    v150[v46] = v72;
                    v73 = v203[v46];
                    v74 = v73->mFreeBucket;
                    if ( v74 )
                    {
                      v75 = v74->mNumCommands;
                      if ( (unsigned int)v75 < 0x7E )
                      {
                        v76 = (signed __int64)v74 + 16 * (v75 + 2);
                        v74->mNumCommands = v75 + 1;
                        goto LABEL_87;
                      }
                      if ( v74 )
                      {
                        v73->mCommandCount += v74->mNumCommands;
                        v73->mFreeBucket = 0i64;
                      }
                    }
                    v77 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v78 = v77;
                    v126 = v77;
                    if ( v77 )
                    {
                      v130 = v77;
                      *(_QWORD *)v77 = v77;
                      *((_QWORD *)v77 + 1) = v77;
                      *((_QWORD *)v77 + 2) = 0i64;
                      *((_DWORD *)v77 + 6) = 0;
                      v79 = v73->mBuckets.mNode.mPrev;
                      v79->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v78;
                      *(_QWORD *)v78 = v79;
                      *((_QWORD *)v78 + 1) = (char *)v73 + 16;
                      v73->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v78;
                      v73->mFreeBucket = (Illusion::QueueCommandBucket *)v78;
                    }
                    v80 = v73->mFreeBucket;
                    if ( !v80 )
                      goto LABEL_89;
                    v80->mNumCommands = 1;
                    v76 = (signed __int64)v73->mFreeBucket->mCommands;
LABEL_87:
                    if ( v76 )
                    {
                      *(_DWORD *)v76 = 3;
                      *(_QWORD *)(v76 + 8) = v72;
                    }
LABEL_89:
                    v81 = &v174 + 2 * v46;
                    v82 = (__int64 *)(v38 + 112);
                    v83 = v132;
                    do
                    {
                      v84 = *v82;
                      if ( *(_QWORD *)v81 == *v82 )
                        goto LABEL_102;
                      *(_QWORD *)v81 = v84;
                      v85 = v203[v83];
                      v86 = v85->mFreeBucket;
                      if ( v86 )
                      {
                        v87 = v86->mNumCommands;
                        if ( (unsigned int)v87 < 0x7E )
                        {
                          v88 = (signed __int64)v86 + 16 * (v87 + 2);
                          v86->mNumCommands = v87 + 1;
                          goto LABEL_100;
                        }
                        if ( v86 )
                        {
                          v85->mCommandCount += v86->mNumCommands;
                          v85->mFreeBucket = 0i64;
                        }
                      }
                      v89 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                      v90 = v89;
                      v130 = v89;
                      if ( v89 )
                      {
                        v126 = v89;
                        *(_QWORD *)v89 = v89;
                        *((_QWORD *)v89 + 1) = v89;
                        *((_QWORD *)v89 + 2) = 0i64;
                        *((_DWORD *)v89 + 6) = 0;
                        v91 = v85->mBuckets.mNode.mPrev;
                        v91->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v90;
                        *(_QWORD *)v90 = v91;
                        *((_QWORD *)v90 + 1) = (char *)v85 + 16;
                        v85->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v90;
                        v85->mFreeBucket = (Illusion::QueueCommandBucket *)v90;
                      }
                      v92 = v85->mFreeBucket;
                      if ( v92 )
                      {
                        v92->mNumCommands = 1;
                        v88 = (signed __int64)v85->mFreeBucket->mCommands;
LABEL_100:
                        if ( v88 )
                        {
                          *(_WORD *)v88 = 5;
                          *(_WORD *)(v88 + 2) = v33;
                          *(_QWORD *)(v88 + 8) = v84;
                        }
                      }
LABEL_102:
                      ++v33;
                      v81 = (__int128 *)((char *)v81 + 8);
                      v82 += 4;
                    }
                    while ( v33 < 4 );
                    v93 = (__int64)v131;
                    v46 = v132;
                    if ( *((char **)&v162 + v132) == v131 )
                      goto LABEL_153;
                    *((_QWORD *)&v162 + v132) = v131;
                    v94 = v203[v46];
                    v95 = v94->mFreeBucket;
                    if ( v95 )
                    {
                      v96 = v95->mNumCommands;
                      if ( (unsigned int)v96 < 0x7E )
                      {
                        v97 = (signed __int64)v95 + 16 * (v96 + 2);
                        v95->mNumCommands = v96 + 1;
                        goto LABEL_113;
                      }
                      if ( v95 )
                      {
                        v94->mCommandCount += v95->mNumCommands;
                        v94->mFreeBucket = 0i64;
                      }
                    }
                    v98 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v99 = v98;
                    v130 = v98;
                    if ( v98 )
                    {
                      v126 = v98;
                      *(_QWORD *)v98 = v98;
                      *((_QWORD *)v98 + 1) = v98;
                      *((_QWORD *)v98 + 2) = 0i64;
                      *((_DWORD *)v98 + 6) = 0;
                      v100 = v94->mBuckets.mNode.mPrev;
                      v100->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v99;
                      *(_QWORD *)v99 = v100;
                      *((_QWORD *)v99 + 1) = (char *)v94 + 16;
                      v94->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v99;
                      v94->mFreeBucket = (Illusion::QueueCommandBucket *)v99;
                    }
                    v101 = v94->mFreeBucket;
                    if ( v101 )
                    {
                      v101->mNumCommands = 1;
                      v97 = (signed __int64)v94->mFreeBucket->mCommands;
LABEL_113:
                      v38 = v128;
                      if ( v97 )
                      {
                        *(_DWORD *)v97 = 4;
                        *(_QWORD *)(v97 + 8) = v93;
                      }
                      v45 = v123;
                    }
                    else
                    {
LABEL_153:
                      v38 = v128;
                      v45 = v123;
                    }
LABEL_117:
                    v102 = *((_QWORD *)&v168 + v46);
                    if ( *((_QWORD *)&v138 + v46) == v102 )
                      goto LABEL_129;
                    *((_QWORD *)&v138 + v46) = v102;
                    v103 = Render::cbLocalProjectionState::sStateParamIndex;
                    v104 = v203[v46];
                    v105 = v104->mFreeBucket;
                    if ( v105 )
                    {
                      v106 = v105->mNumCommands;
                      if ( (unsigned int)v106 < 0x7E )
                      {
                        v107 = (signed __int64)v105 + 16 * (v106 + 2);
                        v105->mNumCommands = v106 + 1;
LABEL_127:
                        if ( v107 )
                        {
                          *(_WORD *)v107 = 2;
                          *(_WORD *)(v107 + 2) = v103;
                          *(_QWORD *)(v107 + 8) = v102;
                        }
                        goto LABEL_129;
                      }
                      if ( v105 )
                      {
                        v104->mCommandCount += v105->mNumCommands;
                        v104->mFreeBucket = 0i64;
                      }
                    }
                    v108 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v109 = v108;
                    v130 = v108;
                    if ( v108 )
                    {
                      v126 = v108;
                      *(_QWORD *)v108 = v108;
                      *((_QWORD *)v108 + 1) = v108;
                      *((_QWORD *)v108 + 2) = 0i64;
                      *((_DWORD *)v108 + 6) = 0;
                      v110 = v104->mBuckets.mNode.mPrev;
                      v110->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v109;
                      *(_QWORD *)v109 = v110;
                      *((_QWORD *)v109 + 1) = (char *)v104 + 16;
                      v104->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v109;
                      v104->mFreeBucket = (Illusion::QueueCommandBucket *)v109;
                    }
                    v111 = v104->mFreeBucket;
                    if ( v111 )
                    {
                      v111->mNumCommands = 1;
                      v107 = (signed __int64)v104->mFreeBucket->mCommands;
                      goto LABEL_127;
                    }
LABEL_129:
                    v112 = v203[v46];
                    v113 = v112->mFreeBucket;
                    if ( v113 )
                    {
                      v114 = v113->mNumCommands;
                      if ( (unsigned int)v114 < 0x7E )
                      {
                        v113->mNumCommands = v114 + 1;
                        v115 = (signed __int64)v113 + 16 * (v114 + 2);
LABEL_138:
                        v33 = 0;
                        if ( v115 )
                        {
                          *(_DWORD *)v115 = 10;
                          *(_QWORD *)(v115 + 8) = v38;
                        }
                        goto LABEL_141;
                      }
                      if ( v113 )
                      {
                        v112->mCommandCount += v113->mNumCommands;
                        v112->mFreeBucket = 0i64;
                      }
                    }
                    v116 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
                    v117 = v116;
                    v130 = v116;
                    if ( v116 )
                    {
                      v126 = v116;
                      *(_QWORD *)v116 = v116;
                      *((_QWORD *)v116 + 1) = v116;
                      *((_QWORD *)v116 + 2) = 0i64;
                      *((_DWORD *)v116 + 6) = 0;
                      v118 = v112->mBuckets.mNode.mPrev;
                      v118->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v117;
                      *(_QWORD *)v117 = v118;
                      *((_QWORD *)v117 + 1) = (char *)v112 + 16;
                      v112->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v117;
                      v112->mFreeBucket = (Illusion::QueueCommandBucket *)v117;
                    }
                    v119 = v112->mFreeBucket;
                    if ( v119 )
                    {
                      v119->mNumCommands = 1;
                      v115 = (signed __int64)v112->mFreeBucket->mCommands;
                      goto LABEL_138;
                    }
                    v33 = 0;
LABEL_141:
                    v203[v46]->mPrimitiveCount += *(_DWORD *)(v38 + 232);
                    v41 = v133;
                    v47 = v204;
LABEL_142:
                    v123 = ++v45;
                    v132 = ++v46;
                  }
                  while ( v45 < v47 );
LABEL_143:
                  v34 = v127 + 1;
                  v127 = v34;
                  v32 = (__int64)v134;
                }
                while ( v34 < LODWORD(v134[12].mPrev) );
              }
            }
            v17 = v129;
            LODWORD(v4) = v204;
          }
        }
      }
    }
    v17 = &v17[12][-6].mNext;
    v129 = v17;
    v6 = v202;
  }
  if ( (_DWORD)v4 )
  {
    v120 = (unsigned int)v4;
    do
    {
      v121 = *v5;
      v122 = (*v5)->mFreeBucket;
      if ( v122 )
      {
        v121->mCommandCount += v122->mNumCommands;
        v121->mFreeBucket = 0i64;
      }
      ++v5;
      --v120;
    }
    while ( v120 );
  }
}v41 = v133;
                    v47 = v204;
LABEL_142:
                    v123 = ++v45;
                    v132 = ++v46;
                  }
                  while ( v45 < v47 );
LABEL_143:
                  v34 = v127 + 1;
                  v127 = v34;
                  v32 = (__int64)v134;
                }
                while ( v34 < LODWORD(v134[12].mPrev) );
              }
            }
            v17 = v129;
            LODWORD(v4) = v204;
          }
        }
      }
    }
    v17 = &v17[12][-6].mNext;
    v129 = v17;
    v6 = v202;
  }
  if ( (_DWORD)v4 )
  {
    v120 = (unsigned int)v4;
    do
    {
      v121 = *v5;
      v122 = (*v5)->mFreeBucket;
      if ( v122 )
      {
        v121->mCommandCount += v

