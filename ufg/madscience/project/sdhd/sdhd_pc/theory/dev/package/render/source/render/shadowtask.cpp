// File Line: 32
// RVA: 0x1457550
__int64 dynamic_initializer_for__gTaskFunctionDecl_FastShadowDrawTask_SceneDB__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_FastShadowDrawTask_SceneDB,
    &gTaskFunctionDeclData_FastShadowDrawTask_SceneDB);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_FastShadowDrawTask_SceneDB__);
}

// File Line: 96
// RVA: 0x7BEE0
void __fastcall ShadowSubmission::RenderResultBucket(ShadowSubmission *this, UFG::qMemoryStream<CullResultBucket,192> *result_bucket)
{
  ShadowSubmission *v2; // r12
  __int64 v3; // rax
  _QWORD *v4; // r8
  __int64 v5; // rbx
  __int64 v6; // rax
  signed __int64 v7; // rdi
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1
  UFG::qVector4 v11; // xmm0
  __int64 v12; // rcx
  signed __int64 v13; // r8
  unsigned int v14; // edx
  unsigned int v15; // eax
  signed __int64 v16; // rcx
  signed __int64 v17; // r15
  __int64 v18; // rbx
  __int64 v19; // rax
  _BYTE *v20; // rax
  UFG::qMatrix44 *v21; // r9
  __int64 v22; // r8
  char v23; // bp
  char v24; // r10
  unsigned int v25; // edx
  _QWORD *v26; // r13
  unsigned int v27; // ecx
  signed __int64 v28; // rax
  __int64 v29; // rax
  signed __int64 v30; // rax
  __int64 v31; // rax
  void *v32; // rdi
  __int64 v33; // rax
  signed __int64 v34; // rax
  void *v35; // rax
  void *v36; // rsi
  Illusion::RenderQueue *v37; // rax
  Illusion::RenderQueue *v38; // rbx
  void *v39; // rax
  Illusion::QueueCommandBucket *v40; // rdx
  __int64 v41; // rax
  signed __int64 v42; // rcx
  char *v43; // rax
  char *v44; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v45; // rax
  Illusion::QueueCommandBucket *v46; // rax
  void *v47; // rcx
  void *v48; // rax
  void *v49; // rdi
  Illusion::QueueCommandBucket *v50; // rdx
  __int64 v51; // rax
  signed __int64 v52; // rcx
  char *v53; // rax
  char *v54; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v55; // rax
  Illusion::QueueCommandBucket *v56; // rax
  void *v57; // rax
  Illusion::QueueCommandBucket *v58; // rdx
  __int64 v59; // rax
  signed __int64 v60; // rcx
  char *v61; // rax
  char *v62; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v63; // rax
  Illusion::QueueCommandBucket *v64; // rax
  void *v65; // rdi
  void *v66; // rax
  Illusion::QueueCommandBucket *v67; // rdx
  __int64 v68; // rax
  signed __int64 v69; // rcx
  char *v70; // rax
  char *v71; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v72; // rax
  Illusion::QueueCommandBucket *v73; // rax
  unsigned int v74; // edi
  __int64 *v75; // r14
  __int64 v76; // rsi
  signed __int64 v77; // rdx
  __int64 v78; // r8
  unsigned int v79; // ecx
  Illusion::QueueCommandBucket *v80; // rdx
  __int64 v81; // rax
  signed __int64 v82; // rcx
  char *v83; // rax
  char *v84; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v85; // rax
  Illusion::QueueCommandBucket *v86; // rax
  void *v87; // rdi
  void *v88; // rax
  Illusion::QueueCommandBucket *v89; // rdx
  __int64 v90; // rax
  signed __int64 v91; // rcx
  char *v92; // rax
  char *v93; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v94; // rax
  Illusion::QueueCommandBucket *v95; // rax
  __int64 v96; // rcx
  char *v97; // rax
  unsigned __int16 v98; // di
  Illusion::QueueCommandBucket *v99; // rdx
  __int64 v100; // rax
  signed __int64 v101; // rcx
  char *v102; // rax
  char *v103; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v104; // rax
  Illusion::QueueCommandBucket *v105; // rax
  _QWORD *v106; // rax
  Illusion::QueueCommandBucket *v107; // rdx
  __int64 v108; // rax
  signed __int64 v109; // rcx
  char *v110; // rax
  char *v111; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v112; // rax
  Illusion::QueueCommandBucket *v113; // rax
  Illusion::QueueCommandBucket *v114; // rcx
  __int64 v115; // rdx
  signed __int64 v116; // rax
  char *v117; // rax
  char *v118; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v119; // rax
  Illusion::QueueCommandBucket *v120; // rax
  unsigned int v121; // [rsp+40h] [rbp-B8h]
  __int64 v122; // [rsp+48h] [rbp-B0h]
  signed __int64 v123; // [rsp+50h] [rbp-A8h]
  char *v124; // [rsp+58h] [rbp-A0h]
  UFG::qMatrix44 result; // [rsp+68h] [rbp-90h]
  ShadowSubmission *v126; // [rsp+100h] [rbp+8h]
  UFG::qMemoryStream<CullResultBucket,192> *v127; // [rsp+108h] [rbp+10h]
  unsigned int v128; // [rsp+110h] [rbp+18h]
  int v129; // [rsp+118h] [rbp+20h]

  v127 = result_bucket;
  v126 = this;
  v2 = this;
  v3 = 0i64;
  v129 = 0;
  v4 = result_bucket->mMainMemoryAddress;
  if ( *((_DWORD *)v4 + 2) )
  {
    do
    {
      v5 = v4[v3 + 3];
      if ( !v2->_params->_force_shadow && !(*(char *)(v5 + 8) & v2->_params->_instance_flag_mask) )
        goto LABEL_160;
      v6 = *(_QWORD *)(v5 + 16);
      if ( !v6 )
        goto LABEL_160;
      v7 = v6 + v5 + 16;
      if ( !v7 )
        goto LABEL_160;
      v124 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
      v8 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)(v5 + 32), &result, &v2->_params->_cascade_world_view_proj);
      v9 = v8->v1;
      v10 = v8->v2;
      v11 = v8->v3;
      *(UFG::qVector4 *)v124 = v8->v0;
      *((UFG::qVector4 *)v124 + 1) = v9;
      *((UFG::qVector4 *)v124 + 2) = v10;
      *((UFG::qVector4 *)v124 + 3) = v11;
      v12 = *(_QWORD *)(v7 + 32);
      if ( !v12 )
        goto LABEL_160;
      *(_DWORD *)(v12 + 212) = Illusion::gEngine.mFrameCount;
      v13 = *(_QWORD *)(v12 + 184) + v12 + 184;
      v123 = *(_QWORD *)(v12 + 184) + v12 + 184;
      v14 = *(_DWORD *)(v12 + 192);
      if ( v14 > 0x20 )
        v14 = 32;
      v121 = v14;
      v15 = 0;
      v128 = 0;
      v16 = 0i64;
      v122 = 0i64;
      if ( !v14 )
        goto LABEL_160;
      do
      {
        v17 = v13 + *(_QWORD *)(v13 + 8 * v16) + 8 * v15;
        v18 = *(_QWORD *)(v17 + 16);
        if ( !Illusion::IEnginePlat::IsValidDrawCall(
                (Illusion::IEnginePlat *)&Illusion::gEngine,
                (Illusion::Mesh *)v17,
                *(Illusion::Material **)(v17 + 16),
                0i64,
                0i64) )
          goto LABEL_159;
        v19 = *(_QWORD *)(v18 + 120);
        v20 = (_BYTE *)(v19 ? v18 + v19 + 120 : 0i64);
        v21 = &v2->_params->_cascade_world_view_proj;
        if ( !v2->_params->_force_shadow && !(*v20 & 0x1E) )
          goto LABEL_159;
        v22 = *(_QWORD *)(v18 + 160);
        if ( !v22 )
          goto LABEL_159;
        v23 = v20[2] & 1;
        v24 = ((unsigned int)*((signed __int16 *)v20 + 1) >> 1) & 1;
        v25 = *(_DWORD *)(v18 + 112);
        if ( v25 > 0x10 )
          v25 = 16;
        v26 = 0i64;
        v27 = 1;
        if ( v25 > 1 )
        {
          v28 = v18 + 184;
          while ( *(_WORD *)(v28 + 8) != 17 )
          {
            ++v27;
            v28 += 56i64;
            if ( v27 >= v25 )
              goto LABEL_33;
          }
          v26 = *(_QWORD **)(v28 + 32);
          if ( v26 )
          {
            v29 = v26[14];
            if ( v29 )
              v30 = (signed __int64)v26 + v29 + 112;
            else
              v30 = 0i64;
            v31 = *(_QWORD *)(v30 + 16);
          }
          else
          {
            v31 = 0i64;
          }
          if ( v31 && *(_BYTE *)(v31 + 93) )
            v23 = 1;
        }
LABEL_33:
        v32 = 0i64;
        v33 = *(_QWORD *)(v22 + 104);
        if ( v33 )
          v34 = v22 + v33 + 104;
        else
          v34 = 0i64;
        if ( v23 )
        {
          if ( *(_QWORD *)(v34 + 48) )
            v32 = *(void **)(v34 + 48);
        }
        else
        {
          v35 = *(void **)(v34 + 16);
          if ( v35 )
            v32 = v35;
        }
        if ( v24 )
          v36 = *(void **)&v21[1].v2.x;
        else
          v36 = *(void **)&v21[1].v1.z;
        v37 = Illusion::RenderQueueBuilder::GetRenderQueue(
                (Illusion::RenderQueueBuilder *)&v2->_shadow_queue.mMaxActiveRenderQueues,
                1ui64,
                0i64);
        v38 = v37;
        v39 = v37->mStateValues.mParamValues[1];
        v38->mStateValues.mParamValues[1] = v32;
        if ( v39 != v32 )
        {
          v40 = v38->mFreeBucket;
          if ( v40 )
          {
            v41 = v40->mNumCommands;
            if ( (unsigned int)v41 < 0x7E )
            {
              v42 = (signed __int64)v40 + 16 * (v41 + 2);
              v40->mNumCommands = v41 + 1;
LABEL_54:
              if ( v42 )
              {
                *(_DWORD *)v42 = 65537;
                *(_QWORD *)(v42 + 8) = v32;
              }
              goto LABEL_56;
            }
            if ( v40 )
            {
              v38->mCommandCount += v40->mNumCommands;
              v38->mFreeBucket = 0i64;
            }
          }
          v43 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
          v44 = v43;
          if ( v43 )
          {
            *(_QWORD *)v43 = v43;
            *((_QWORD *)v43 + 1) = v43;
            *((_QWORD *)v43 + 2) = 0i64;
            *((_DWORD *)v43 + 6) = 0;
            v45 = v38->mBuckets.mNode.mPrev;
            v45->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v44;
            *(_QWORD *)v44 = v45;
            *((_QWORD *)v44 + 1) = (char *)v38 + 16;
            v38->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v44;
            v38->mFreeBucket = (Illusion::QueueCommandBucket *)v44;
          }
          v46 = v38->mFreeBucket;
          if ( v46 )
          {
            v46->mNumCommands = 1;
            v42 = (signed __int64)v38->mFreeBucket->mCommands;
            goto LABEL_54;
          }
LABEL_56:
          v38->mStateValues.mParamValues[(signed __int16)v2->_params->_localprojection_state_param_index] = 0i64;
          v38->mStateValues.mParamValues[17] = 0i64;
        }
        v47 = v2->_params->_default_alphastate_main_mem;
        v48 = v38->mStateValues.mParamValues[9];
        v38->mStateValues.mParamValues[9] = v47;
        if ( v48 == v47 )
          goto LABEL_69;
        v49 = v2->_params->_default_alphastate_main_mem;
        v50 = v38->mFreeBucket;
        if ( v50 )
        {
          v51 = v50->mNumCommands;
          if ( (unsigned int)v51 < 0x7E )
          {
            v52 = (signed __int64)v50 + 16 * (v51 + 2);
            v50->mNumCommands = v51 + 1;
            goto LABEL_67;
          }
          if ( v50 )
          {
            v38->mCommandCount += v50->mNumCommands;
            v38->mFreeBucket = 0i64;
          }
        }
        v53 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v54 = v53;
        if ( v53 )
        {
          *(_QWORD *)v53 = v53;
          *((_QWORD *)v53 + 1) = v53;
          *((_QWORD *)v53 + 2) = 0i64;
          *((_DWORD *)v53 + 6) = 0;
          v55 = v38->mBuckets.mNode.mPrev;
          v55->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v54;
          *(_QWORD *)v54 = v55;
          *((_QWORD *)v54 + 1) = (char *)v38 + 16;
          v38->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v54;
          v38->mFreeBucket = (Illusion::QueueCommandBucket *)v54;
        }
        v56 = v38->mFreeBucket;
        if ( v56 )
        {
          v56->mNumCommands = 1;
          v52 = (signed __int64)v38->mFreeBucket->mCommands;
LABEL_67:
          if ( v52 )
          {
            *(_DWORD *)v52 = 589831;
            *(_QWORD *)(v52 + 8) = v49;
          }
        }
LABEL_69:
        v57 = v38->mStateValues.mParamValues[10];
        v38->mStateValues.mParamValues[10] = v36;
        if ( v57 == v36 )
          goto LABEL_81;
        v58 = v38->mFreeBucket;
        if ( v58 )
        {
          v59 = v58->mNumCommands;
          if ( (unsigned int)v59 < 0x7E )
          {
            v60 = (signed __int64)v58 + 16 * (v59 + 2);
            v58->mNumCommands = v59 + 1;
            goto LABEL_79;
          }
          if ( v58 )
          {
            v38->mCommandCount += v58->mNumCommands;
            v38->mFreeBucket = 0i64;
          }
        }
        v61 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v62 = v61;
        if ( v61 )
        {
          *(_QWORD *)v61 = v61;
          *((_QWORD *)v61 + 1) = v61;
          *((_QWORD *)v61 + 2) = 0i64;
          *((_DWORD *)v61 + 6) = 0;
          v63 = v38->mBuckets.mNode.mPrev;
          v63->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v62;
          *(_QWORD *)v62 = v63;
          *((_QWORD *)v62 + 1) = (char *)v38 + 16;
          v38->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v62;
          v38->mFreeBucket = (Illusion::QueueCommandBucket *)v62;
        }
        v64 = v38->mFreeBucket;
        if ( v64 )
        {
          v64->mNumCommands = 1;
          v60 = (signed __int64)v38->mFreeBucket->mCommands;
LABEL_79:
          if ( v60 )
          {
            *(_DWORD *)v60 = 655368;
            *(_QWORD *)(v60 + 8) = v36;
          }
        }
LABEL_81:
        v65 = *(void **)(v17 + 48);
        v66 = v38->mStateValues.mParamValues[2];
        v38->mStateValues.mParamValues[2] = v65;
        if ( v66 != v65 )
        {
          v67 = v38->mFreeBucket;
          if ( v67 )
          {
            v68 = v67->mNumCommands;
            if ( (unsigned int)v68 < 0x7E )
            {
              v69 = (signed __int64)v67 + 16 * (v68 + 2);
              v67->mNumCommands = v68 + 1;
LABEL_91:
              if ( v69 )
              {
                *(_DWORD *)v69 = 131075;
                *(_QWORD *)(v69 + 8) = v65;
              }
              goto LABEL_93;
            }
            if ( v67 )
            {
              v38->mCommandCount += v67->mNumCommands;
              v38->mFreeBucket = 0i64;
            }
          }
          v70 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
          v71 = v70;
          if ( v70 )
          {
            *(_QWORD *)v70 = v70;
            *((_QWORD *)v70 + 1) = v70;
            *((_QWORD *)v70 + 2) = 0i64;
            *((_DWORD *)v70 + 6) = 0;
            v72 = v38->mBuckets.mNode.mPrev;
            v72->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v71;
            *(_QWORD *)v71 = v72;
            *((_QWORD *)v71 + 1) = (char *)v38 + 16;
            v38->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v71;
            v38->mFreeBucket = (Illusion::QueueCommandBucket *)v71;
          }
          v73 = v38->mFreeBucket;
          if ( !v73 )
            goto LABEL_93;
          v73->mNumCommands = 1;
          v69 = (signed __int64)v38->mFreeBucket->mCommands;
          goto LABEL_91;
        }
LABEL_93:
        v74 = 0;
        v75 = (__int64 *)(v17 + 112);
        do
        {
          v76 = *v75;
          v77 = (signed __int64)v38 + 8 * (signed __int16)(v74 + 4);
          v78 = *(_QWORD *)(v77 + 96);
          v79 = (signed __int16)(v74 + 4);
          if ( v79 >= 0x40 )
            v38->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v79 - 64);
          else
            v38->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << v79;
          *(_QWORD *)(v77 + 96) = v76;
          if ( v78 == v76 )
            goto LABEL_109;
          v80 = v38->mFreeBucket;
          if ( v80 )
          {
            v81 = v80->mNumCommands;
            if ( (unsigned int)v81 < 0x7E )
            {
              v82 = (signed __int64)v80 + 16 * (v81 + 2);
              v80->mNumCommands = v81 + 1;
              goto LABEL_107;
            }
            if ( v80 )
            {
              v38->mCommandCount += v80->mNumCommands;
              v38->mFreeBucket = 0i64;
            }
          }
          v83 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
          v84 = v83;
          if ( v83 )
          {
            *(_QWORD *)v83 = v83;
            *((_QWORD *)v83 + 1) = v83;
            *((_QWORD *)v83 + 2) = 0i64;
            *((_DWORD *)v83 + 6) = 0;
            v85 = v38->mBuckets.mNode.mPrev;
            v85->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v84;
            *(_QWORD *)v84 = v85;
            *((_QWORD *)v84 + 1) = (char *)v38 + 16;
            v38->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v84;
            v38->mFreeBucket = (Illusion::QueueCommandBucket *)v84;
          }
          v86 = v38->mFreeBucket;
          if ( v86 )
          {
            v86->mNumCommands = 1;
            v82 = (signed __int64)v38->mFreeBucket->mCommands;
LABEL_107:
            if ( v82 )
            {
              *(_WORD *)v82 = 5;
              *(_WORD *)(v82 + 2) = v74;
              *(_QWORD *)(v82 + 8) = v76;
            }
          }
LABEL_109:
          ++v74;
          v75 += 4;
        }
        while ( v74 < 4 );
        v87 = *(void **)(v17 + 80);
        v88 = v38->mStateValues.mParamValues[3];
        v38->mStateValues.mParamValues[3] = v87;
        v2 = v126;
        if ( v88 == v87 )
          goto LABEL_122;
        v89 = v38->mFreeBucket;
        if ( v89 )
        {
          v90 = v89->mNumCommands;
          if ( (unsigned int)v90 < 0x7E )
          {
            v91 = (signed __int64)v89 + 16 * (v90 + 2);
            v89->mNumCommands = v90 + 1;
LABEL_120:
            if ( v91 )
            {
              *(_DWORD *)v91 = 196612;
              *(_QWORD *)(v91 + 8) = v87;
            }
            goto LABEL_122;
          }
          if ( v89 )
          {
            v38->mCommandCount += v89->mNumCommands;
            v38->mFreeBucket = 0i64;
          }
        }
        v92 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v93 = v92;
        if ( v92 )
        {
          *(_QWORD *)v92 = v92;
          *((_QWORD *)v92 + 1) = v92;
          *((_QWORD *)v92 + 2) = 0i64;
          *((_DWORD *)v92 + 6) = 0;
          v94 = v38->mBuckets.mNode.mPrev;
          v94->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v93;
          *(_QWORD *)v93 = v94;
          *((_QWORD *)v93 + 1) = (char *)v38 + 16;
          v38->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v93;
          v38->mFreeBucket = (Illusion::QueueCommandBucket *)v93;
        }
        v95 = v38->mFreeBucket;
        if ( v95 )
        {
          v95->mNumCommands = 1;
          v91 = (signed __int64)v38->mFreeBucket->mCommands;
          goto LABEL_120;
        }
LABEL_122:
        v96 = (signed __int16)v126->_params->_localprojection_state_param_index;
        v97 = (char *)v38->mStateValues.mParamValues[v96];
        v38->mStateValues.mParamValues[v96] = v124;
        if ( v97 == v124 )
          goto LABEL_134;
        v98 = v126->_params->_localprojection_state_param_index;
        v99 = v38->mFreeBucket;
        if ( v99 )
        {
          v100 = v99->mNumCommands;
          if ( (unsigned int)v100 < 0x7E )
          {
            v101 = (signed __int64)v99 + 16 * (v100 + 2);
            v99->mNumCommands = v100 + 1;
LABEL_132:
            if ( v101 )
            {
              *(_WORD *)v101 = 2;
              *(_WORD *)(v101 + 2) = v98;
              *(_QWORD *)(v101 + 8) = v124;
            }
            goto LABEL_134;
          }
          if ( v99 )
          {
            v38->mCommandCount += v99->mNumCommands;
            v38->mFreeBucket = 0i64;
          }
        }
        v102 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v103 = v102;
        if ( v102 )
        {
          *(_QWORD *)v102 = v102;
          *((_QWORD *)v102 + 1) = v102;
          *((_QWORD *)v102 + 2) = 0i64;
          *((_DWORD *)v102 + 6) = 0;
          v104 = v38->mBuckets.mNode.mPrev;
          v104->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v103;
          *(_QWORD *)v103 = v104;
          *((_QWORD *)v103 + 1) = (char *)v38 + 16;
          v38->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v103;
          v38->mFreeBucket = (Illusion::QueueCommandBucket *)v103;
        }
        v105 = v38->mFreeBucket;
        if ( v105 )
        {
          v105->mNumCommands = 1;
          v101 = (signed __int64)v38->mFreeBucket->mCommands;
          goto LABEL_132;
        }
LABEL_134:
        if ( !v23 )
          goto LABEL_147;
        v106 = v38->mStateValues.mParamValues[17];
        v38->mStateValues.mParamValues[17] = v26;
        if ( v106 == v26 )
          goto LABEL_147;
        v107 = v38->mFreeBucket;
        if ( v107 )
        {
          v108 = v107->mNumCommands;
          if ( (unsigned int)v108 < 0x7E )
          {
            v109 = (signed __int64)v107 + 16 * (v108 + 2);
            v107->mNumCommands = v108 + 1;
LABEL_145:
            if ( v109 )
            {
              *(_DWORD *)v109 = 1114114;
              *(_QWORD *)(v109 + 8) = v26;
            }
            goto LABEL_147;
          }
          if ( v107 )
          {
            v38->mCommandCount += v107->mNumCommands;
            v38->mFreeBucket = 0i64;
          }
        }
        v110 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v111 = v110;
        if ( v110 )
        {
          *(_QWORD *)v110 = v110;
          *((_QWORD *)v110 + 1) = v110;
          *((_QWORD *)v110 + 2) = 0i64;
          *((_DWORD *)v110 + 6) = 0;
          v112 = v38->mBuckets.mNode.mPrev;
          v112->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v111;
          *(_QWORD *)v111 = v112;
          *((_QWORD *)v111 + 1) = (char *)v38 + 16;
          v38->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v111;
          v38->mFreeBucket = (Illusion::QueueCommandBucket *)v111;
        }
        v113 = v38->mFreeBucket;
        if ( v113 )
        {
          v113->mNumCommands = 1;
          v109 = (signed __int64)v38->mFreeBucket->mCommands;
          goto LABEL_145;
        }
LABEL_147:
        v114 = v38->mFreeBucket;
        if ( v114 )
        {
          v115 = v114->mNumCommands;
          if ( (unsigned int)v115 < 0x7E )
          {
            v114->mNumCommands = v115 + 1;
            v116 = (signed __int64)v114 + 16 * (v115 + 2);
LABEL_156:
            if ( v116 )
            {
              *(_DWORD *)v116 = 10;
              *(_QWORD *)(v116 + 8) = v17;
            }
            goto LABEL_158;
          }
          if ( v114 )
          {
            v38->mCommandCount += v114->mNumCommands;
            v38->mFreeBucket = 0i64;
          }
        }
        v117 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v118 = v117;
        if ( v117 )
        {
          *(_QWORD *)v117 = v117;
          *((_QWORD *)v117 + 1) = v117;
          *((_QWORD *)v117 + 2) = 0i64;
          *((_DWORD *)v117 + 6) = 0;
          v119 = v38->mBuckets.mNode.mPrev;
          v119->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v118;
          *(_QWORD *)v118 = v119;
          *((_QWORD *)v118 + 1) = (char *)v38 + 16;
          v38->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v118;
          v38->mFreeBucket = (Illusion::QueueCommandBucket *)v118;
        }
        v120 = v38->mFreeBucket;
        if ( v120 )
        {
          v120->mNumCommands = 1;
          v116 = (signed __int64)v38->mFreeBucket->mCommands;
          goto LABEL_156;
        }
LABEL_158:
        v38->mPrimitiveCount += *(_DWORD *)(v17 + 232);
        ++v126->_submit_count;
LABEL_159:
        v15 = v128 + 1;
        v128 = v15;
        v16 = v122++ + 1;
        v13 = v123;
      }
      while ( v15 < v121 );
LABEL_160:
      v3 = (unsigned int)(v129 + 1);
      v129 = v3;
      v4 = v127->mMainMemoryAddress;
    }
    while ( (unsigned int)v3 < *((_DWORD *)v4 + 2) );
  }
}ion::QueueCommandBucket> *)v118;
          v38->mFreeBucket = (Illusion::QueueCommandBucket *)v118;
        }
        v120 = v38->mFreeBucket;
        if ( v120 )
        {
          v120->mNumCommands = 1;
          v116 = (signed __int64)v38->mFreeBucket->mCommands;
          goto LABEL_156;
        }
LABEL_158:
        v38->mPrimitiveCount += *(_DWORD *)(v17 + 232);
        ++v126->

// File Line: 304
// RVA: 0x7BB30
void __fastcall FastShadowDrawTask_SceneDB(int workerId, UFG::qMemoryStreamer *memory_streamer, void *param_stream, void *pad0)
{
  unsigned int *v4; // r14
  __int128 v5; // xmm3
  __int128 v6; // xmm1
  __int128 v7; // xmm0
  void **v8; // rdx
  unsigned int v9; // edi
  BOOL v10; // esi
  void **v11; // rbx
  unsigned int v12; // eax
  void **v13; // rcx
  BOOL v14; // edx
  UFG::qMemoryStreamer *v15; // [rsp+40h] [rbp-A8h]
  UFG::qMemoryStream<CullResultBucket,192> result_bucket; // [rsp+48h] [rbp-A0h]
  __int64 v17; // [rsp+60h] [rbp-88h]
  __int128 v18; // [rsp+68h] [rbp-80h]
  __int128 v19; // [rsp+78h] [rbp-70h]
  __int128 v20; // [rsp+88h] [rbp-60h]
  int v21; // [rsp+98h] [rbp-50h]
  bool v22; // [rsp+9Ch] [rbp-4Ch]
  __int16 v23; // [rsp+9Eh] [rbp-4Ah]
  __int64 v24; // [rsp+A0h] [rbp-48h]
  __int64 v25; // [rsp+A8h] [rbp-40h]
  __int64 v26; // [rsp+B0h] [rbp-38h]
  __int64 v27; // [rsp+B8h] [rbp-30h]
  __int64 v28; // [rsp+C0h] [rbp-28h]
  ShadowSubmission ptr; // [rsp+C8h] [rbp-20h]
  Illusion::RenderQueueBuilderStreams<1> *retaddr; // [rsp+1A8h] [rbp+C0h]

  *(_QWORD *)&v18 = -2i64;
  v4 = (unsigned int *)param_stream;
  v15 = (UFG::qMemoryStreamer *)8589934593i64;
  result_bucket.mName = (const char *)34359738372i64;
  LODWORD(result_bucket.mMainMemoryAddress) = 15;
  v5 = *(_OWORD *)param_stream;
  v6 = *((_OWORD *)param_stream + 2);
  v7 = *((_OWORD *)param_stream + 3);
  v18 = *((_OWORD *)param_stream + 1);
  v19 = v6;
  v20 = v7;
  v21 = *((_DWORD *)&v15 + *((unsigned int *)param_stream + 32));
  v22 = *((_DWORD *)param_stream + 26) != 0;
  v23 = *((_WORD *)param_stream + 68);
  v24 = *((_QWORD *)param_stream + 18);
  v25 = *((_QWORD *)param_stream + 12);
  v26 = *((_QWORD *)param_stream + 20);
  v27 = *((_QWORD *)param_stream + 21);
  v28 = *((_QWORD *)param_stream + 19);
  ptr._params = (ShadowSubmissionParams *)((char *)&v18 + 8);
  ptr._shadow_result_stream.mName = "ShadowRenderQueueResults";
  ptr._shadow_result_stream.mMainMemoryAddress = 0i64;
  ptr._shadow_result_stream.mState = 0;
  Illusion::RenderQueueBuilderStreams<1>::RenderQueueBuilderStreams<1>(&ptr._shadow_queue_streams);
  ptr._submit_count = 0;
  ptr._shadow_result_stream.mMainMemoryAddress = (void *)*((_QWORD *)v4 + 15);
  ptr._shadow_queue.mPendingRenderQueueList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)ptr._shadow_result_stream.mMainMemoryAddress;
  ptr._shadow_queue.mMainMemPendingRenderQueueList = ptr._shadow_result_stream.mMainMemoryAddress;
  Illusion::RenderQueueBuilder::Init(
    (Illusion::RenderQueueBuilder *)&ptr._shadow_queue.mMaxActiveRenderQueues,
    1u,
    ptr._shadow_queue_streams.mActiveRenderQueueUIDs,
    ptr._shadow_queue_streams.mActiveRenderQueueStreams,
    ptr._shadow_queue_streams.mQueueCommandBucketStreams,
    Illusion::RenderQueueBuilderSimple::Simple_EndQueue,
    &ptr._shadow_queue);
  v8 = *(void ***)(*((_QWORD *)v4 + 10) + 8i64 * v4[16] + 80);
  v15 = Illusion::gEngine.MemoryStreamer;
  result_bucket.mName = "CullResultBucketIterator";
  result_bucket.mState = 0;
  v17 = 0i64;
  v9 = 0;
  v10 = Illusion::gEngine.MemoryStreamer != 0i64;
  v11 = v8;
  if ( (v8 != 0i64) & (unsigned __int8)v10 )
    v11 = v8;
  result_bucket.mMainMemoryAddress = v11;
  if ( v8 )
  {
    while ( 1 )
    {
      v12 = UFG::qAtomicAdd(*((volatile int **)v4 + 9), 1) - 1;
      if ( v9 < v12 )
        break;
LABEL_9:
      ShadowSubmission::RenderResultBucket(&ptr, &result_bucket);
    }
    while ( 1 )
    {
      v13 = (void **)*v11;
      v14 = *v11 != 0i64;
      v11 = v13;
      result_bucket.mMainMemoryAddress = v13;
      if ( v14 && v10 )
        HIDWORD(v17) = ++v9;
      LODWORD(v17) = 0;
      if ( !v13 )
        break;
      if ( v9 >= v12 )
        goto LABEL_9;
    }
  }
  Illusion::RenderQueueBuilder::Close((Illusion::RenderQueueBuilder *)&ptr._shadow_queue.mMaxActiveRenderQueues);
  retaddr = &ptr._shadow_queue_streams;
  `eh vector destructor iterator(
    ptr._shadow_queue_streams.mQueueCommandBucketStreams,
    0x18ui64,
    1,
    (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(
    ptr._shadow_queue_streams.mActiveRenderQueueStreams,
    0x18ui64,
    1,
    (void (__fastcall *)(void *))_);
}

