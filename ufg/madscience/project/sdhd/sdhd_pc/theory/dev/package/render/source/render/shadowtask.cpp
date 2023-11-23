// File Line: 32
// RVA: 0x1457550
__int64 dynamic_initializer_for__gTaskFunctionDecl_FastShadowDrawTask_SceneDB__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_FastShadowDrawTask_SceneDB,
    &gTaskFunctionDeclData_FastShadowDrawTask_SceneDB);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTaskFunctionDecl_FastShadowDrawTask_SceneDB__);
}

// File Line: 96
// RVA: 0x7BEE0
void __fastcall ShadowSubmission::RenderResultBucket(
        ShadowSubmission *this,
        UFG::qMemoryStream<CullResultBucket,192> *result_bucket)
{
  ShadowSubmission *v2; // r12
  __int64 v3; // rax
  _QWORD *mMainMemoryAddress; // r8
  __int64 v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rdi
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1
  UFG::qVector4 v11; // xmm0
  __int64 v12; // rcx
  __int64 v13; // r8
  unsigned int v14; // edx
  unsigned int v15; // eax
  __int64 v16; // rcx
  Illusion::Mesh *v17; // r15
  Illusion::Material *mData; // rbx
  __int64 mOffset; // rax
  char *v20; // rax
  UFG::qMatrix44 *p_cascade_world_view_proj; // r9
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // r8
  char v23; // bp
  bool v24; // r10
  unsigned int mNumParams; // edx
  _QWORD *v26; // r13
  unsigned int v27; // ecx
  char *v28; // rax
  __int64 v29; // rax
  char *v30; // rax
  __int64 v31; // rax
  void *v32; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax
  char *v34; // rax
  void *v35; // rax
  void *v36; // rsi
  Illusion::RenderQueue *RenderQueue; // rbx
  void *v38; // rax
  Illusion::QueueCommandBucket *mFreeBucket; // rdx
  __int64 mNumCommands; // rax
  __int64 mCommands; // rcx
  char *v42; // rax
  Illusion::QueueCommandBucket *v43; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v44; // rax
  Illusion::QueueCommandBucket *v45; // rax
  void *default_alphastate_main_mem; // rcx
  void *v47; // rax
  void *v48; // rdi
  Illusion::QueueCommandBucket *v49; // rdx
  __int64 v50; // rax
  __int64 v51; // rcx
  char *v52; // rax
  Illusion::QueueCommandBucket *v53; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v54; // rax
  Illusion::QueueCommandBucket *v55; // rax
  void *v56; // rax
  Illusion::QueueCommandBucket *v57; // rdx
  __int64 v58; // rax
  __int64 v59; // rcx
  char *v60; // rax
  Illusion::QueueCommandBucket *v61; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v62; // rax
  Illusion::QueueCommandBucket *v63; // rax
  UFG::qResourceData *v64; // rdi
  UFG::qResourceData *v65; // rax
  Illusion::QueueCommandBucket *v66; // rdx
  __int64 v67; // rax
  __int64 v68; // rcx
  char *v69; // rax
  Illusion::QueueCommandBucket *v70; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v71; // rax
  Illusion::QueueCommandBucket *v72; // rax
  unsigned int v73; // edi
  UFG::qResourceData **p_mData; // r14
  UFG::qResourceData *v75; // rsi
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> **v76; // rdx
  UFG::qResourceData *v77; // r8
  Illusion::QueueCommandBucket *v78; // rdx
  __int64 v79; // rax
  __int64 v80; // rcx
  char *v81; // rax
  Illusion::QueueCommandBucket *v82; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v83; // rax
  Illusion::QueueCommandBucket *v84; // rax
  UFG::qResourceData *v85; // rdi
  UFG::qResourceData *v86; // rax
  Illusion::QueueCommandBucket *v87; // rdx
  __int64 v88; // rax
  __int64 v89; // rcx
  char *v90; // rax
  Illusion::QueueCommandBucket *v91; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v92; // rax
  Illusion::QueueCommandBucket *v93; // rax
  __int64 localprojection_state_param_index; // rcx
  char *v95; // rax
  unsigned __int16 v96; // di
  Illusion::QueueCommandBucket *v97; // rdx
  __int64 v98; // rax
  __int64 v99; // rcx
  char *v100; // rax
  Illusion::QueueCommandBucket *v101; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v102; // rax
  Illusion::QueueCommandBucket *v103; // rax
  _QWORD *v104; // rax
  Illusion::QueueCommandBucket *v105; // rdx
  __int64 v106; // rax
  __int64 v107; // rcx
  char *v108; // rax
  Illusion::QueueCommandBucket *v109; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v110; // rax
  Illusion::QueueCommandBucket *v111; // rax
  Illusion::QueueCommandBucket *v112; // rcx
  __int64 v113; // rdx
  __int64 v114; // rax
  char *v115; // rax
  Illusion::QueueCommandBucket *v116; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v117; // rax
  Illusion::QueueCommandBucket *v118; // rax
  unsigned int v119; // [rsp+40h] [rbp-B8h]
  __int64 v120; // [rsp+48h] [rbp-B0h]
  __int64 v121; // [rsp+50h] [rbp-A8h]
  char *v122; // [rsp+58h] [rbp-A0h]
  UFG::qMatrix44 result; // [rsp+68h] [rbp-90h] BYREF
  unsigned int v126; // [rsp+110h] [rbp+18h]
  int v127; // [rsp+118h] [rbp+20h]

  v2 = this;
  v3 = 0i64;
  v127 = 0;
  mMainMemoryAddress = result_bucket->mMainMemoryAddress;
  if ( *((_DWORD *)mMainMemoryAddress + 2) )
  {
    do
    {
      v5 = mMainMemoryAddress[v3 + 3];
      if ( !v2->_params->_force_shadow && (*(char *)(v5 + 8) & v2->_params->_instance_flag_mask) == 0 )
        goto LABEL_151;
      v6 = *(_QWORD *)(v5 + 16);
      if ( !v6 )
        goto LABEL_151;
      v7 = v6 + v5 + 16;
      if ( !v7 )
        goto LABEL_151;
      v122 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
      v8 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)(v5 + 32), &result, &v2->_params->_cascade_world_view_proj);
      v9 = v8->v1;
      v10 = v8->v2;
      v11 = v8->v3;
      *(UFG::qVector4 *)v122 = v8->v0;
      *((UFG::qVector4 *)v122 + 1) = v9;
      *((UFG::qVector4 *)v122 + 2) = v10;
      *((UFG::qVector4 *)v122 + 3) = v11;
      v12 = *(_QWORD *)(v7 + 32);
      if ( !v12 )
        goto LABEL_151;
      *(_DWORD *)(v12 + 212) = Illusion::gEngine.mFrameCount;
      v13 = *(_QWORD *)(v12 + 184) + v12 + 184;
      v121 = v13;
      v14 = *(_DWORD *)(v12 + 192);
      if ( v14 > 0x20 )
        v14 = 32;
      v119 = v14;
      v15 = 0;
      v126 = 0;
      v16 = 0i64;
      v120 = 0i64;
      if ( !v14 )
        goto LABEL_151;
      do
      {
        v17 = (Illusion::Mesh *)(v13 + *(_QWORD *)(v13 + 8 * v16) + 8 * v15);
        mData = (Illusion::Material *)v17->mMaterialHandle.mData;
        if ( !Illusion::IEnginePlat::IsValidDrawCall(&Illusion::gEngine, v17, mData, 0i64, 0i64) )
          goto LABEL_150;
        mOffset = mData->mMaterialUser.mOffset;
        v20 = mOffset ? (char *)&mData->mMaterialUser + mOffset : 0i64;
        p_cascade_world_view_proj = &v2->_params->_cascade_world_view_proj;
        if ( !v2->_params->_force_shadow && (*v20 & 0x1E) == 0 )
          goto LABEL_150;
        mPrev = mData[1].mResourceHandles.UFG::qResourceData::mNode.mPrev;
        if ( !mPrev )
          goto LABEL_150;
        v23 = v20[2] & 1;
        v24 = (*((_WORD *)v20 + 1) & 2) != 0;
        mNumParams = mData->mNumParams;
        if ( mNumParams > 0x10 )
          mNumParams = 16;
        v26 = 0i64;
        v27 = 1;
        if ( mNumParams > 1 )
        {
          v28 = &mData[1].mDebugName[4];
          while ( *((_WORD *)v28 + 4) != 17 )
          {
            ++v27;
            v28 += 56;
            if ( v27 >= mNumParams )
              goto LABEL_33;
          }
          v26 = (_QWORD *)*((_QWORD *)v28 + 4);
          if ( v26 )
          {
            v29 = v26[14];
            if ( v29 )
              v30 = (char *)v26 + v29 + 112;
            else
              v30 = 0i64;
            v31 = *((_QWORD *)v30 + 2);
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
        mNext = mPrev[6].mNext;
        if ( mNext )
          v34 = (char *)&mNext[6].mNext + (_QWORD)mPrev;
        else
          v34 = 0i64;
        if ( v23 )
        {
          if ( *((_QWORD *)v34 + 6) )
            v32 = (void *)*((_QWORD *)v34 + 6);
        }
        else
        {
          v35 = (void *)*((_QWORD *)v34 + 2);
          if ( v35 )
            v32 = v35;
        }
        if ( v24 )
          v36 = *(void **)&p_cascade_world_view_proj[1].v2.x;
        else
          v36 = *(void **)&p_cascade_world_view_proj[1].v1.z;
        RenderQueue = Illusion::RenderQueueBuilder::GetRenderQueue(&v2->_shadow_queue, 1ui64, 0i64);
        v38 = RenderQueue->mStateValues.mParamValues[1];
        RenderQueue->mStateValues.mParamValues[1] = v32;
        if ( v38 != v32 )
        {
          mFreeBucket = RenderQueue->mFreeBucket;
          if ( mFreeBucket )
          {
            mNumCommands = mFreeBucket->mNumCommands;
            if ( (unsigned int)mNumCommands < 0x7E )
            {
              mCommands = (__int64)&mFreeBucket->mCommands[mNumCommands];
              mFreeBucket->mNumCommands = mNumCommands + 1;
LABEL_53:
              if ( mCommands )
              {
                *(_DWORD *)mCommands = 65537;
                *(_QWORD *)(mCommands + 8) = v32;
              }
              goto LABEL_55;
            }
            RenderQueue->mCommandCount += mFreeBucket->mNumCommands;
            RenderQueue->mFreeBucket = 0i64;
          }
          v42 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
          v43 = (Illusion::QueueCommandBucket *)v42;
          if ( v42 )
          {
            *(_QWORD *)v42 = v42;
            *((_QWORD *)v42 + 1) = v42;
            *((_QWORD *)v42 + 2) = 0i64;
            *((_DWORD *)v42 + 6) = 0;
            v44 = RenderQueue->mBuckets.mNode.mPrev;
            v44->mNext = v43;
            v43->mPrev = v44;
            v43->mNext = &RenderQueue->mBuckets.mNode;
            RenderQueue->mBuckets.mNode.mPrev = v43;
            RenderQueue->mFreeBucket = v43;
          }
          v45 = RenderQueue->mFreeBucket;
          if ( v45 )
          {
            v45->mNumCommands = 1;
            mCommands = (__int64)RenderQueue->mFreeBucket->mCommands;
            goto LABEL_53;
          }
LABEL_55:
          RenderQueue->mStateValues.mParamValues[(__int16)v2->_params->_localprojection_state_param_index] = 0i64;
          RenderQueue->mStateValues.mParamValues[17] = 0i64;
        }
        default_alphastate_main_mem = v2->_params->_default_alphastate_main_mem;
        v47 = RenderQueue->mStateValues.mParamValues[9];
        RenderQueue->mStateValues.mParamValues[9] = default_alphastate_main_mem;
        if ( v47 == default_alphastate_main_mem )
          goto LABEL_67;
        v48 = v2->_params->_default_alphastate_main_mem;
        v49 = RenderQueue->mFreeBucket;
        if ( v49 )
        {
          v50 = v49->mNumCommands;
          if ( (unsigned int)v50 < 0x7E )
          {
            v51 = (__int64)&v49->mCommands[v50];
            v49->mNumCommands = v50 + 1;
            goto LABEL_65;
          }
          RenderQueue->mCommandCount += v49->mNumCommands;
          RenderQueue->mFreeBucket = 0i64;
        }
        v52 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v53 = (Illusion::QueueCommandBucket *)v52;
        if ( v52 )
        {
          *(_QWORD *)v52 = v52;
          *((_QWORD *)v52 + 1) = v52;
          *((_QWORD *)v52 + 2) = 0i64;
          *((_DWORD *)v52 + 6) = 0;
          v54 = RenderQueue->mBuckets.mNode.mPrev;
          v54->mNext = v53;
          v53->mPrev = v54;
          v53->mNext = &RenderQueue->mBuckets.mNode;
          RenderQueue->mBuckets.mNode.mPrev = v53;
          RenderQueue->mFreeBucket = v53;
        }
        v55 = RenderQueue->mFreeBucket;
        if ( v55 )
        {
          v55->mNumCommands = 1;
          v51 = (__int64)RenderQueue->mFreeBucket->mCommands;
LABEL_65:
          if ( v51 )
          {
            *(_DWORD *)v51 = 589831;
            *(_QWORD *)(v51 + 8) = v48;
          }
        }
LABEL_67:
        v56 = RenderQueue->mStateValues.mParamValues[10];
        RenderQueue->mStateValues.mParamValues[10] = v36;
        if ( v56 == v36 )
          goto LABEL_78;
        v57 = RenderQueue->mFreeBucket;
        if ( v57 )
        {
          v58 = v57->mNumCommands;
          if ( (unsigned int)v58 < 0x7E )
          {
            v59 = (__int64)&v57->mCommands[v58];
            v57->mNumCommands = v58 + 1;
            goto LABEL_76;
          }
          RenderQueue->mCommandCount += v57->mNumCommands;
          RenderQueue->mFreeBucket = 0i64;
        }
        v60 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v61 = (Illusion::QueueCommandBucket *)v60;
        if ( v60 )
        {
          *(_QWORD *)v60 = v60;
          *((_QWORD *)v60 + 1) = v60;
          *((_QWORD *)v60 + 2) = 0i64;
          *((_DWORD *)v60 + 6) = 0;
          v62 = RenderQueue->mBuckets.mNode.mPrev;
          v62->mNext = v61;
          v61->mPrev = v62;
          v61->mNext = &RenderQueue->mBuckets.mNode;
          RenderQueue->mBuckets.mNode.mPrev = v61;
          RenderQueue->mFreeBucket = v61;
        }
        v63 = RenderQueue->mFreeBucket;
        if ( v63 )
        {
          v63->mNumCommands = 1;
          v59 = (__int64)RenderQueue->mFreeBucket->mCommands;
LABEL_76:
          if ( v59 )
          {
            *(_DWORD *)v59 = 655368;
            *(_QWORD *)(v59 + 8) = v36;
          }
        }
LABEL_78:
        v64 = v17->mVertexDeclHandle.mData;
        v65 = (UFG::qResourceData *)RenderQueue->mStateValues.mParamValues[2];
        RenderQueue->mStateValues.mParamValues[2] = v64;
        if ( v65 != v64 )
        {
          v66 = RenderQueue->mFreeBucket;
          if ( v66 )
          {
            v67 = v66->mNumCommands;
            if ( (unsigned int)v67 < 0x7E )
            {
              v68 = (__int64)&v66->mCommands[v67];
              v66->mNumCommands = v67 + 1;
LABEL_87:
              if ( v68 )
              {
                *(_DWORD *)v68 = 131075;
                *(_QWORD *)(v68 + 8) = v64;
              }
              goto LABEL_89;
            }
            RenderQueue->mCommandCount += v66->mNumCommands;
            RenderQueue->mFreeBucket = 0i64;
          }
          v69 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
          v70 = (Illusion::QueueCommandBucket *)v69;
          if ( v69 )
          {
            *(_QWORD *)v69 = v69;
            *((_QWORD *)v69 + 1) = v69;
            *((_QWORD *)v69 + 2) = 0i64;
            *((_DWORD *)v69 + 6) = 0;
            v71 = RenderQueue->mBuckets.mNode.mPrev;
            v71->mNext = v70;
            v70->mPrev = v71;
            v70->mNext = &RenderQueue->mBuckets.mNode;
            RenderQueue->mBuckets.mNode.mPrev = v70;
            RenderQueue->mFreeBucket = v70;
          }
          v72 = RenderQueue->mFreeBucket;
          if ( !v72 )
            goto LABEL_89;
          v72->mNumCommands = 1;
          v68 = (__int64)RenderQueue->mFreeBucket->mCommands;
          goto LABEL_87;
        }
LABEL_89:
        v73 = 0;
        p_mData = &v17->mVertexBufferHandles[0].mData;
        do
        {
          v75 = *p_mData;
          v76 = &RenderQueue->mPrev + (__int16)(v73 + 4);
          v77 = (UFG::qResourceData *)v76[12];
          if ( (unsigned int)(__int16)(v73 + 4) >= 0x40 )
            RenderQueue->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v73 - 60);
          else
            RenderQueue->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << ((unsigned __int8)v73 + 4);
          v76[12] = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v75;
          if ( v77 == v75 )
            goto LABEL_104;
          v78 = RenderQueue->mFreeBucket;
          if ( v78 )
          {
            v79 = v78->mNumCommands;
            if ( (unsigned int)v79 < 0x7E )
            {
              v80 = (__int64)&v78->mCommands[v79];
              v78->mNumCommands = v79 + 1;
              goto LABEL_102;
            }
            RenderQueue->mCommandCount += v78->mNumCommands;
            RenderQueue->mFreeBucket = 0i64;
          }
          v81 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
          v82 = (Illusion::QueueCommandBucket *)v81;
          if ( v81 )
          {
            *(_QWORD *)v81 = v81;
            *((_QWORD *)v81 + 1) = v81;
            *((_QWORD *)v81 + 2) = 0i64;
            *((_DWORD *)v81 + 6) = 0;
            v83 = RenderQueue->mBuckets.mNode.mPrev;
            v83->mNext = v82;
            v82->mPrev = v83;
            v82->mNext = &RenderQueue->mBuckets.mNode;
            RenderQueue->mBuckets.mNode.mPrev = v82;
            RenderQueue->mFreeBucket = v82;
          }
          v84 = RenderQueue->mFreeBucket;
          if ( v84 )
          {
            v84->mNumCommands = 1;
            v80 = (__int64)RenderQueue->mFreeBucket->mCommands;
LABEL_102:
            if ( v80 )
            {
              *(_WORD *)v80 = 5;
              *(_WORD *)(v80 + 2) = v73;
              *(_QWORD *)(v80 + 8) = v75;
            }
          }
LABEL_104:
          ++v73;
          p_mData += 4;
        }
        while ( v73 < 4 );
        v85 = v17->mIndexBufferHandle.mData;
        v86 = (UFG::qResourceData *)RenderQueue->mStateValues.mParamValues[3];
        RenderQueue->mStateValues.mParamValues[3] = v85;
        v2 = this;
        if ( v86 == v85 )
          goto LABEL_116;
        v87 = RenderQueue->mFreeBucket;
        if ( v87 )
        {
          v88 = v87->mNumCommands;
          if ( (unsigned int)v88 < 0x7E )
          {
            v89 = (__int64)&v87->mCommands[v88];
            v87->mNumCommands = v88 + 1;
LABEL_114:
            if ( v89 )
            {
              *(_DWORD *)v89 = 196612;
              *(_QWORD *)(v89 + 8) = v85;
            }
            goto LABEL_116;
          }
          RenderQueue->mCommandCount += v87->mNumCommands;
          RenderQueue->mFreeBucket = 0i64;
        }
        v90 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v91 = (Illusion::QueueCommandBucket *)v90;
        if ( v90 )
        {
          *(_QWORD *)v90 = v90;
          *((_QWORD *)v90 + 1) = v90;
          *((_QWORD *)v90 + 2) = 0i64;
          *((_DWORD *)v90 + 6) = 0;
          v92 = RenderQueue->mBuckets.mNode.mPrev;
          v92->mNext = v91;
          v91->mPrev = v92;
          v91->mNext = &RenderQueue->mBuckets.mNode;
          RenderQueue->mBuckets.mNode.mPrev = v91;
          RenderQueue->mFreeBucket = v91;
        }
        v93 = RenderQueue->mFreeBucket;
        if ( v93 )
        {
          v93->mNumCommands = 1;
          v89 = (__int64)RenderQueue->mFreeBucket->mCommands;
          goto LABEL_114;
        }
LABEL_116:
        localprojection_state_param_index = (__int16)this->_params->_localprojection_state_param_index;
        v95 = (char *)RenderQueue->mStateValues.mParamValues[localprojection_state_param_index];
        RenderQueue->mStateValues.mParamValues[localprojection_state_param_index] = v122;
        if ( v95 == v122 )
          goto LABEL_127;
        v96 = this->_params->_localprojection_state_param_index;
        v97 = RenderQueue->mFreeBucket;
        if ( v97 )
        {
          v98 = v97->mNumCommands;
          if ( (unsigned int)v98 < 0x7E )
          {
            v99 = (__int64)&v97->mCommands[v98];
            v97->mNumCommands = v98 + 1;
LABEL_125:
            if ( v99 )
            {
              *(_WORD *)v99 = 2;
              *(_WORD *)(v99 + 2) = v96;
              *(_QWORD *)(v99 + 8) = v122;
            }
            goto LABEL_127;
          }
          RenderQueue->mCommandCount += v97->mNumCommands;
          RenderQueue->mFreeBucket = 0i64;
        }
        v100 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v101 = (Illusion::QueueCommandBucket *)v100;
        if ( v100 )
        {
          *(_QWORD *)v100 = v100;
          *((_QWORD *)v100 + 1) = v100;
          *((_QWORD *)v100 + 2) = 0i64;
          *((_DWORD *)v100 + 6) = 0;
          v102 = RenderQueue->mBuckets.mNode.mPrev;
          v102->mNext = v101;
          v101->mPrev = v102;
          v101->mNext = &RenderQueue->mBuckets.mNode;
          RenderQueue->mBuckets.mNode.mPrev = v101;
          RenderQueue->mFreeBucket = v101;
        }
        v103 = RenderQueue->mFreeBucket;
        if ( v103 )
        {
          v103->mNumCommands = 1;
          v99 = (__int64)RenderQueue->mFreeBucket->mCommands;
          goto LABEL_125;
        }
LABEL_127:
        if ( !v23 )
          goto LABEL_139;
        v104 = RenderQueue->mStateValues.mParamValues[17];
        RenderQueue->mStateValues.mParamValues[17] = v26;
        if ( v104 == v26 )
          goto LABEL_139;
        v105 = RenderQueue->mFreeBucket;
        if ( v105 )
        {
          v106 = v105->mNumCommands;
          if ( (unsigned int)v106 < 0x7E )
          {
            v107 = (__int64)&v105->mCommands[v106];
            v105->mNumCommands = v106 + 1;
LABEL_137:
            if ( v107 )
            {
              *(_DWORD *)v107 = 1114114;
              *(_QWORD *)(v107 + 8) = v26;
            }
            goto LABEL_139;
          }
          RenderQueue->mCommandCount += v105->mNumCommands;
          RenderQueue->mFreeBucket = 0i64;
        }
        v108 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v109 = (Illusion::QueueCommandBucket *)v108;
        if ( v108 )
        {
          *(_QWORD *)v108 = v108;
          *((_QWORD *)v108 + 1) = v108;
          *((_QWORD *)v108 + 2) = 0i64;
          *((_DWORD *)v108 + 6) = 0;
          v110 = RenderQueue->mBuckets.mNode.mPrev;
          v110->mNext = v109;
          v109->mPrev = v110;
          v109->mNext = &RenderQueue->mBuckets.mNode;
          RenderQueue->mBuckets.mNode.mPrev = v109;
          RenderQueue->mFreeBucket = v109;
        }
        v111 = RenderQueue->mFreeBucket;
        if ( v111 )
        {
          v111->mNumCommands = 1;
          v107 = (__int64)RenderQueue->mFreeBucket->mCommands;
          goto LABEL_137;
        }
LABEL_139:
        v112 = RenderQueue->mFreeBucket;
        if ( v112 )
        {
          v113 = v112->mNumCommands;
          if ( (unsigned int)v113 < 0x7E )
          {
            v112->mNumCommands = v113 + 1;
            v114 = (__int64)&v112->mCommands[v113];
LABEL_147:
            if ( v114 )
            {
              *(_DWORD *)v114 = 10;
              *(_QWORD *)(v114 + 8) = v17;
            }
            goto LABEL_149;
          }
          RenderQueue->mCommandCount += v112->mNumCommands;
          RenderQueue->mFreeBucket = 0i64;
        }
        v115 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
        v116 = (Illusion::QueueCommandBucket *)v115;
        if ( v115 )
        {
          *(_QWORD *)v115 = v115;
          *((_QWORD *)v115 + 1) = v115;
          *((_QWORD *)v115 + 2) = 0i64;
          *((_DWORD *)v115 + 6) = 0;
          v117 = RenderQueue->mBuckets.mNode.mPrev;
          v117->mNext = v116;
          v116->mPrev = v117;
          v116->mNext = &RenderQueue->mBuckets.mNode;
          RenderQueue->mBuckets.mNode.mPrev = v116;
          RenderQueue->mFreeBucket = v116;
        }
        v118 = RenderQueue->mFreeBucket;
        if ( v118 )
        {
          v118->mNumCommands = 1;
          v114 = (__int64)RenderQueue->mFreeBucket->mCommands;
          goto LABEL_147;
        }
LABEL_149:
        RenderQueue->mPrimitiveCount += v17->mNumPrims;
        ++this->_submit_count;
LABEL_150:
        v15 = v126 + 1;
        v126 = v15;
        v16 = ++v120;
        v13 = v121;
      }
      while ( v15 < v119 );
LABEL_151:
      v3 = (unsigned int)(v127 + 1);
      v127 = v3;
      mMainMemoryAddress = result_bucket->mMainMemoryAddress;
    }
    while ( (unsigned int)v3 < *((_DWORD *)mMainMemoryAddress + 2) );
  }
}esult_bucket->mMainMemoryAddress;
    }
    while ( (unsigned int)v3 < *((_DWORD *)mMainMemoryAddress + 2) );
  }
}

// File Line: 304
// RVA: 0x7BB30
void __fastcall FastShadowDrawTask_SceneDB(
        int workerId,
        UFG::qMemoryStreamer *memory_streamer,
        unsigned int *param_stream,
        void *pad0)
{
  __int128 v5; // xmm1
  __int128 v6; // xmm0
  void **v7; // rdx
  unsigned int v8; // edi
  BOOL v9; // esi
  void **v10; // rbx
  unsigned int v11; // eax
  void **v12; // rcx
  BOOL v13; // edx
  __int64 MemoryStreamer; // [rsp+40h] [rbp-A8h]
  UFG::qMemoryStream<CullResultBucket,192> result_bucket; // [rsp+48h] [rbp-A0h] BYREF
  __int64 v16; // [rsp+60h] [rbp-88h]
  __int128 v17[3]; // [rsp+68h] [rbp-80h] BYREF
  int v18; // [rsp+98h] [rbp-50h]
  bool v19; // [rsp+9Ch] [rbp-4Ch]
  __int16 v20; // [rsp+9Eh] [rbp-4Ah]
  __int64 v21; // [rsp+A0h] [rbp-48h]
  __int64 v22; // [rsp+A8h] [rbp-40h]
  __int64 v23; // [rsp+B0h] [rbp-38h]
  __int64 v24; // [rsp+B8h] [rbp-30h]
  __int64 v25; // [rsp+C0h] [rbp-28h]
  ShadowSubmission ptr; // [rsp+C8h] [rbp-20h] BYREF
  Illusion::RenderQueueBuilderStreams<1> *p_shadow_queue_streams; // [rsp+1A8h] [rbp+C0h]

  *(_QWORD *)&v17[0] = -2i64;
  MemoryStreamer = 0x200000001i64;
  result_bucket.mName = (const char *)0x800000004i64;
  LODWORD(result_bucket.mMainMemoryAddress) = 15;
  v5 = *((_OWORD *)param_stream + 2);
  v6 = *((_OWORD *)param_stream + 3);
  v17[0] = *((_OWORD *)param_stream + 1);
  v17[1] = v5;
  v17[2] = v6;
  v18 = *((_DWORD *)&MemoryStreamer + param_stream[32]);
  v19 = param_stream[26] != 0;
  v20 = *((_WORD *)param_stream + 68);
  v21 = *((_QWORD *)param_stream + 18);
  v22 = *((_QWORD *)param_stream + 12);
  v23 = *((_QWORD *)param_stream + 20);
  v24 = *((_QWORD *)param_stream + 21);
  v25 = *((_QWORD *)param_stream + 19);
  ptr._params = (ShadowSubmissionParams *)((char *)v17 + 8);
  ptr._shadow_result_stream.mName = "ShadowRenderQueueResults";
  ptr._shadow_result_stream.mMainMemoryAddress = 0i64;
  ptr._shadow_result_stream.mState = 0;
  Illusion::RenderQueueBuilderStreams<1>::RenderQueueBuilderStreams<1>(&ptr._shadow_queue_streams);
  ptr._submit_count = 0;
  ptr._shadow_result_stream.mMainMemoryAddress = (void *)*((_QWORD *)param_stream + 15);
  ptr._shadow_queue.mPendingRenderQueueList = (UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *)ptr._shadow_result_stream.mMainMemoryAddress;
  ptr._shadow_queue.mMainMemPendingRenderQueueList = ptr._shadow_result_stream.mMainMemoryAddress;
  Illusion::RenderQueueBuilder::Init(
    &ptr._shadow_queue,
    1u,
    ptr._shadow_queue_streams.mActiveRenderQueueUIDs,
    ptr._shadow_queue_streams.mActiveRenderQueueStreams,
    ptr._shadow_queue_streams.mQueueCommandBucketStreams,
    Illusion::RenderQueueBuilderSimple::Simple_EndQueue,
    &ptr._shadow_queue);
  v7 = *(void ***)(*((_QWORD *)param_stream + 10) + 8i64 * param_stream[16] + 80);
  MemoryStreamer = (__int64)Illusion::gEngine.MemoryStreamer;
  result_bucket.mName = "CullResultBucketIterator";
  result_bucket.mState = 0;
  v16 = 0i64;
  v8 = 0;
  v9 = Illusion::gEngine.MemoryStreamer != 0i64;
  v10 = v7;
  if ( v7 != 0i64 && v9 )
    v10 = v7;
  result_bucket.mMainMemoryAddress = v10;
  if ( v7 )
  {
    while ( 1 )
    {
      v11 = UFG::qAtomicAdd(*((volatile int **)param_stream + 9), 1) - 1;
      if ( v8 < v11 )
        break;
LABEL_9:
      ShadowSubmission::RenderResultBucket(&ptr, &result_bucket);
    }
    while ( 1 )
    {
      v12 = (void **)*v10;
      v13 = *v10 != 0i64;
      v10 = v12;
      result_bucket.mMainMemoryAddress = v12;
      if ( v13 && v9 )
        HIDWORD(v16) = ++v8;
      LODWORD(v16) = 0;
      if ( !v12 )
        break;
      if ( v8 >= v11 )
        goto LABEL_9;
    }
  }
  Illusion::RenderQueueBuilder::Close(&ptr._shadow_queue);
  p_shadow_queue_streams = &ptr._shadow_queue_streams;
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
}_shadow_queue_streams.mActiveRenderQueueStreams,
    0x18ui64,
    1,

