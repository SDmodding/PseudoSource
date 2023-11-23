// File Line: 65
// RVA: 0x8D100
void __fastcall Illusion::SubmitContext::SubmitContext(Illusion::SubmitContext *this)
{
  this->vfptr = (Illusion::SubmitContextVtbl *)&Illusion::SubmitContext::`vftable;
  UFG::qMemSet(this->mStateValues.mParamValues, 0, 0x400u);
  this->mStateValues.mSetValueMask.mFlags[1] = 0i64;
  this->mStateValues.mSetValueMask.mFlags[0] = 0i64;
  `eh vector constructor iterator(
    this->mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
  this->mStateArgs.mStateArgsCreateMask.mFlags[1] = 0i64;
  this->mStateArgs.mStateArgsCreateMask.mFlags[0] = 0i64;
  this->mStateArgs.mStateParamModelFreqMask.mFlags[1] = 0i64;
  this->mStateArgs.mStateParamModelFreqMask.mFlags[0] = 0i64;
  this->mStateArgs.mStateParamMeshFreqMask.mFlags[1] = 0i64;
  this->mStateArgs.mStateParamMeshFreqMask.mFlags[0] = 0i64;
  this->mRenderPass = Solid;
  this->mShaderSelector = 0i64;
  this->mMaterialModifier = 0i64;
}

// File Line: 69
// RVA: 0x908E0
__int64 __fastcall Illusion::SubmitContext::Draw(
        Illusion::SubmitContext *this,
        Illusion::Model *model,
        Illusion::Material *force_material)
{
  unsigned int mNumMeshes; // edi
  __int64 v4; // rbx
  char *v7; // r14
  __int64 v8; // rsi
  __int64 v9; // r8
  Illusion::Mesh *v10; // r8
  Illusion::Material *mData; // r9
  UFG::BitFlags128 v13; // [rsp+30h] [rbp-48h]
  UFG::BitFlags128 v14; // [rsp+40h] [rbp-38h] BYREF
  UFG::BitFlags128 v15; // [rsp+50h] [rbp-28h] BYREF

  mNumMeshes = model->mNumMeshes;
  v4 = 0i64;
  v7 = (char *)&model->mMeshOffsetTable + model->mMeshOffsetTable.mOffset;
  v13 = (UFG::BitFlags128)0i64;
  model->mLastUsedFrameNum = Illusion::gEngine.mFrameCount;
  if ( mNumMeshes )
  {
    v8 = mNumMeshes;
    do
    {
      v9 = v4 + *(_QWORD *)&v7[v4];
      v14 = v13;
      v10 = (Illusion::Mesh *)&v7[v9];
      mData = (Illusion::Material *)v10->mMaterialHandle.mData;
      if ( force_material )
        mData = force_material;
      v4 += 8i64;
      v13 = *Illusion::SubmitContext::Draw(this, &v15, v10, mData, &v14, v10);
      --v8;
    }
    while ( v8 );
  }
  return mNumMeshes;
}

// File Line: 161
// RVA: 0x8F1D0
UFG::BitFlags128 *__fastcall Illusion::SubmitContext::Draw(
        Illusion::SubmitContext *this,
        UFG::BitFlags128 *result,
        Illusion::Mesh *mesh,
        Illusion::Material *material,
        UFG::BitFlags128 *already_called_funcs_mask,
        void *main_mem_mesh)
{
  Illusion::Mesh *v7; // rdi
  UFG::BitFlags128 *v8; // r13
  Illusion::SubmitContext *v9; // r12
  unsigned __int64 v10; // rax
  UFG::BitFlags128 *v11; // rsi
  unsigned int mNumParams; // ecx
  Illusion::Material *v13; // rdx
  __int64 v14; // r8
  Illusion::MaterialModifierData *mMaterialModifier; // rax
  Illusion::ParamOverride *mOverridesPtr; // rbx
  int mNumOverrides; // r14d
  __int64 mStateParamIndex; // rsi
  int mCondition; // edi
  UFG::qResourceData *v20; // r15
  char *v21; // r13
  UFG::qResourceData *v22; // r12
  int i; // edx
  __int64 v24; // rax
  UFG::qResourceData *v25; // r8
  __int64 v26; // rax
  Illusion::RenderQueue *v27; // rbx
  void *v28; // rdi
  void *v29; // rcx
  __int64 v30; // rdx
  __int64 v31; // rax
  __int64 mCommands; // rcx
  char *v33; // rax
  char *v34; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *mPrev; // rax
  Illusion::QueueCommandBucket *mFreeBucket; // rax
  void *v37; // rdi
  void *v38; // rax
  Illusion::QueueCommandBucket *v39; // rdx
  __int64 mNumCommands; // rax
  __int64 v41; // rcx
  char *v42; // rax
  char *v43; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v44; // rax
  Illusion::QueueCommandBucket *v45; // rax
  void *v46; // rdi
  void *v47; // rax
  Illusion::QueueCommandBucket *v48; // rdx
  __int64 v49; // rax
  __int64 v50; // rcx
  char *v51; // rax
  char *v52; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v53; // rax
  Illusion::QueueCommandBucket *v54; // rax
  unsigned int j; // edi
  void *v56; // rsi
  __int64 v57; // rax
  void *v58; // rcx
  Illusion::QueueCommandBucket *v59; // rdx
  __int64 v60; // rax
  __int64 v61; // rcx
  char *v62; // rax
  char *v63; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v64; // rax
  Illusion::QueueCommandBucket *v65; // rax
  void *v66; // rdi
  void *v67; // rax
  Illusion::QueueCommandBucket *v68; // rdx
  __int64 v69; // rax
  __int64 v70; // rcx
  char *v71; // rax
  char *v72; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v73; // rax
  Illusion::QueueCommandBucket *v74; // rax
  void *v75; // rdi
  void *v76; // rax
  Illusion::QueueCommandBucket *v77; // rdx
  __int64 v78; // rax
  __int64 v79; // rcx
  char *v80; // rax
  char *v81; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v82; // rax
  Illusion::QueueCommandBucket *v83; // rax
  void *v84; // rdi
  void *v85; // rax
  Illusion::QueueCommandBucket *v86; // rdx
  __int64 v87; // rax
  __int64 v88; // rcx
  char *v89; // rax
  char *v90; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v91; // rax
  Illusion::QueueCommandBucket *v92; // rax
  __int64 v93; // rcx
  __int64 v94; // rsi
  unsigned __int64 v95; // rdi
  bool v96; // zf
  __int64 v97; // rcx
  int v98; // eax
  __int16 v99; // r14
  void *v100; // r15
  __int64 v101; // rax
  void *v102; // rcx
  Illusion::QueueCommandBucket *v103; // rdx
  __int64 v104; // rax
  __int64 v105; // rcx
  char *v106; // rax
  char *v107; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v108; // rax
  Illusion::QueueCommandBucket *v109; // rax
  __int64 v110; // rsi
  unsigned __int64 v111; // rdi
  __int64 v112; // rcx
  int v113; // eax
  __int16 v114; // r14
  void *v115; // r15
  __int64 v116; // rax
  void *v117; // rcx
  Illusion::QueueCommandBucket *v118; // rdx
  __int64 v119; // rax
  __int64 v120; // rcx
  char *v121; // rax
  char *v122; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v123; // rax
  Illusion::QueueCommandBucket *v124; // rax
  Illusion::QueueCommandBucket *v125; // rdx
  __int64 v126; // rcx
  __int64 v127; // rcx
  char *v128; // rax
  char *v129; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v130; // rax
  Illusion::QueueCommandBucket *v131; // rax
  unsigned __int64 v132; // rax
  UFG::qResourceData *mData; // [rsp+30h] [rbp-30h]
  UFG::qResourceData *v135; // [rsp+38h] [rbp-28h]
  const char *v136; // [rsp+48h] [rbp-18h] BYREF
  _QWORD *v137; // [rsp+50h] [rbp-10h]
  int v138; // [rsp+58h] [rbp-8h]
  unsigned int mNumPrims; // [rsp+B0h] [rbp+50h]

  v7 = mesh;
  v8 = result;
  v9 = this;
  mData = mesh->mVertexDeclHandle.mData;
  v135 = mesh->mIndexBufferHandle.mData;
  if ( mData == 0i64 || v135 == 0i64 )
  {
    *result = *already_called_funcs_mask;
    return v8;
  }
  v10 = ~this->mStateArgs.mStateParamMeshFreqMask.mFlags[1];
  v11 = already_called_funcs_mask;
  already_called_funcs_mask->mFlags[0] &= ~this->mStateArgs.mStateParamMeshFreqMask.mFlags[0];
  already_called_funcs_mask->mFlags[1] &= v10;
  if ( !Illusion::IEnginePlat::IsValidDrawCall(&Illusion::gEngine, mesh, material, 0i64, 0i64) )
  {
LABEL_160:
    v8->mFlags[0] = v11->mFlags[0];
    v132 = v11->mFlags[1];
    goto LABEL_161;
  }
  if ( !material )
  {
LABEL_10:
    mMaterialModifier = v9->mMaterialModifier;
    if ( !mMaterialModifier )
      goto LABEL_29;
    mOverridesPtr = mMaterialModifier->mOverridesPtr;
    mNumOverrides = mMaterialModifier->mNumOverrides;
    if ( mNumOverrides <= 0 )
      goto LABEL_29;
    while ( 1 )
    {
      mStateParamIndex = mOverridesPtr->mStateParamIndex;
      if ( (_DWORD)mStateParamIndex != -1 )
      {
        mCondition = mOverridesPtr->mCondition;
        v20 = (UFG::qResourceData *)v9->mStateValues.mParamValues[mStateParamIndex];
        v21 = (char *)mOverridesPtr->mOverrideResourceHandle.mData;
        v22 = mOverridesPtr->mOriginalResourceHandle.mData;
        if ( !Illusion::IEnginePlat::IsAnInvalidTextureResourceHandle(
                &Illusion::gEngine,
                &mOverridesPtr->mOverrideResourceHandle)
          && !mCondition )
        {
          goto LABEL_22;
        }
        if ( mCondition == 3 )
        {
          v21 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, mOverridesPtr->mConstantBlockSize, 0x10u);
          UFG::qMemCopy(v21, mOverridesPtr->mConstantBlock, mOverridesPtr->mConstantBlockSize);
LABEL_22:
          v9 = this;
          if ( (unsigned int)(__int16)mStateParamIndex >= 0x40 )
            this->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mStateParamIndex - 64);
          else
            this->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << mStateParamIndex;
          this->mStateValues.mParamValues[(__int16)mStateParamIndex] = v21;
          goto LABEL_27;
        }
        if ( mCondition == 1 )
        {
          if ( v20 == v22 )
            goto LABEL_22;
        }
        else if ( mCondition == 2 && v20 != v22 )
        {
          goto LABEL_22;
        }
        v9 = this;
      }
LABEL_27:
      --mNumOverrides;
      ++mOverridesPtr;
      if ( mNumOverrides <= 0 )
      {
        v7 = mesh;
        v8 = result;
        v11 = already_called_funcs_mask;
        goto LABEL_29;
      }
    }
  }
  mNumParams = material->mNumParams;
  if ( mNumParams )
  {
    v13 = material + 1;
    v9->mStateValues.mSetValueMask.mFlags[0] = material->mStateBlockMask.mFlags[0];
    v9->mStateValues.mSetValueMask.mFlags[1] = material->mStateBlockMask.mFlags[1];
    v14 = mNumParams;
    do
    {
      if ( v13 )
        v9->mStateValues.mParamValues[SLOWORD(v13->mNode.mChild[0])] = v13->mResourceHandles.UFG::qResourceData::mNode.mPrev;
      v13 = (Illusion::Material *)((char *)v13 + 56);
      --v14;
    }
    while ( v14 );
    goto LABEL_10;
  }
LABEL_29:
  v9->mStateValues.mParamValues[2] = mData;
  v9->mStateValues.mParamValues[3] = v135;
  v9->mStateValues.mParamValues[8] = 0i64;
  for ( i = 0; i < 4; ++i )
  {
    v24 = i;
    v25 = v7->mVertexBufferHandles[v24].mData;
    if ( v7->mVertexBufferHandles[v24].mNameUID != 0 && v25 == 0i64 )
      goto LABEL_160;
    v9->mStateValues.mParamValues[(__int16)(i + 4)] = v25;
  }
  mNumPrims = v7->mNumPrims;
  v136 = "<unassigned>";
  v137 = 0i64;
  v138 = 0;
  if ( !v9->mStateValues.mParamValues[1] )
    goto LABEL_159;
  v137 = v9->mStateValues.mParamValues[1];
  v26 = (__int64)v9->vfptr->OnPreSubmit(v9, (UFG::qMemoryStream<Illusion::Shader,1160> *)&v136, v11);
  v27 = (Illusion::RenderQueue *)v26;
  if ( !v26 )
    goto LABEL_159;
  v28 = v9->mStateValues.mParamValues[1];
  v29 = *(void **)(v26 + 104);
  *(_QWORD *)(v26 + 104) = v28;
  if ( v29 != v28 )
  {
    v30 = *(_QWORD *)(v26 + 40);
    if ( v30 )
    {
      v31 = *(unsigned int *)(v30 + 24);
      if ( (unsigned int)v31 < 0x7E )
      {
        mCommands = v30 + 16 * (v31 + 2);
        *(_DWORD *)(v30 + 24) = v31 + 1;
        goto LABEL_43;
      }
      v27->mCommandCount += *(_DWORD *)(v30 + 24);
      v27->mFreeBucket = 0i64;
    }
    v33 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v34 = v33;
    if ( v33 )
    {
      *(_QWORD *)v33 = v33;
      *((_QWORD *)v33 + 1) = v33;
      *((_QWORD *)v33 + 2) = 0i64;
      *((_DWORD *)v33 + 6) = 0;
      mPrev = v27->mBuckets.mNode.mPrev;
      mPrev->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v34;
      *(_QWORD *)v34 = mPrev;
      *((_QWORD *)v34 + 1) = &v27->mBuckets;
      v27->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v34;
      v27->mFreeBucket = (Illusion::QueueCommandBucket *)v34;
    }
    mFreeBucket = v27->mFreeBucket;
    if ( !mFreeBucket )
      goto LABEL_45;
    mFreeBucket->mNumCommands = 1;
    mCommands = (__int64)v27->mFreeBucket->mCommands;
LABEL_43:
    if ( mCommands )
    {
      *(_DWORD *)mCommands = 65537;
      *(_QWORD *)(mCommands + 8) = v28;
    }
LABEL_45:
    UFG::qMemSet(&v27->mStateValues.mParamValues[13], 0, 0x398u);
    v27->mStateValues.mSetValueMask.mFlags[0] &= 0x1FFFui64;
    v27->mStateValues.mSetValueMask.mFlags[1] = 0i64;
  }
  v37 = v9->mStateValues.mParamValues[2];
  v38 = v27->mStateValues.mParamValues[2];
  v27->mStateValues.mParamValues[2] = v37;
  if ( v38 == v37 )
    goto LABEL_57;
  v39 = v27->mFreeBucket;
  if ( v39 )
  {
    mNumCommands = v39->mNumCommands;
    if ( (unsigned int)mNumCommands < 0x7E )
    {
      v41 = (__int64)&v39->mCommands[mNumCommands];
      v39->mNumCommands = mNumCommands + 1;
      goto LABEL_55;
    }
    v27->mCommandCount += v39->mNumCommands;
    v27->mFreeBucket = 0i64;
  }
  v42 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v43 = v42;
  if ( v42 )
  {
    *(_QWORD *)v42 = v42;
    *((_QWORD *)v42 + 1) = v42;
    *((_QWORD *)v42 + 2) = 0i64;
    *((_DWORD *)v42 + 6) = 0;
    v44 = v27->mBuckets.mNode.mPrev;
    v44->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v43;
    *(_QWORD *)v43 = v44;
    *((_QWORD *)v43 + 1) = &v27->mBuckets;
    v27->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v43;
    v27->mFreeBucket = (Illusion::QueueCommandBucket *)v43;
  }
  v45 = v27->mFreeBucket;
  if ( v45 )
  {
    v45->mNumCommands = 1;
    v41 = (__int64)v27->mFreeBucket->mCommands;
LABEL_55:
    if ( v41 )
    {
      *(_DWORD *)v41 = 131075;
      *(_QWORD *)(v41 + 8) = v37;
    }
  }
LABEL_57:
  v46 = v9->mStateValues.mParamValues[3];
  v47 = v27->mStateValues.mParamValues[3];
  v27->mStateValues.mParamValues[3] = v46;
  if ( v47 != v46 )
  {
    v48 = v27->mFreeBucket;
    if ( v48 )
    {
      v49 = v48->mNumCommands;
      if ( (unsigned int)v49 < 0x7E )
      {
        v50 = (__int64)&v48->mCommands[v49];
        v48->mNumCommands = v49 + 1;
LABEL_66:
        if ( v50 )
        {
          *(_DWORD *)v50 = 196612;
          *(_QWORD *)(v50 + 8) = v46;
        }
        goto LABEL_68;
      }
      v27->mCommandCount += v48->mNumCommands;
      v27->mFreeBucket = 0i64;
    }
    v51 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v52 = v51;
    if ( v51 )
    {
      *(_QWORD *)v51 = v51;
      *((_QWORD *)v51 + 1) = v51;
      *((_QWORD *)v51 + 2) = 0i64;
      *((_DWORD *)v51 + 6) = 0;
      v53 = v27->mBuckets.mNode.mPrev;
      v53->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v52;
      *(_QWORD *)v52 = v53;
      *((_QWORD *)v52 + 1) = &v27->mBuckets;
      v27->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v52;
      v27->mFreeBucket = (Illusion::QueueCommandBucket *)v52;
    }
    v54 = v27->mFreeBucket;
    if ( !v54 )
      goto LABEL_68;
    v54->mNumCommands = 1;
    v50 = (__int64)v27->mFreeBucket->mCommands;
    goto LABEL_66;
  }
LABEL_68:
  for ( j = 0; j < 4; ++j )
  {
    v56 = v9->mStateValues.mParamValues[(int)j + 4];
    v57 = (__int16)(j + 4);
    v58 = v27->mStateValues.mParamValues[v57];
    v27->mStateValues.mParamValues[v57] = v56;
    if ( v58 == v56 )
      continue;
    v59 = v27->mFreeBucket;
    if ( v59 )
    {
      v60 = v59->mNumCommands;
      if ( (unsigned int)v60 < 0x7E )
      {
        v61 = (__int64)&v59->mCommands[v60];
        v59->mNumCommands = v60 + 1;
        goto LABEL_78;
      }
      v27->mCommandCount += v59->mNumCommands;
      v27->mFreeBucket = 0i64;
    }
    v62 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v63 = v62;
    if ( v62 )
    {
      *(_QWORD *)v62 = v62;
      *((_QWORD *)v62 + 1) = v62;
      *((_QWORD *)v62 + 2) = 0i64;
      *((_DWORD *)v62 + 6) = 0;
      v64 = v27->mBuckets.mNode.mPrev;
      v64->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v63;
      *(_QWORD *)v63 = v64;
      *((_QWORD *)v63 + 1) = &v27->mBuckets;
      v27->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v63;
      v27->mFreeBucket = (Illusion::QueueCommandBucket *)v63;
    }
    v65 = v27->mFreeBucket;
    if ( v65 )
    {
      v65->mNumCommands = 1;
      v61 = (__int64)v27->mFreeBucket->mCommands;
LABEL_78:
      if ( v61 )
      {
        *(_WORD *)v61 = 5;
        *(_WORD *)(v61 + 2) = j;
        *(_QWORD *)(v61 + 8) = v56;
      }
      continue;
    }
  }
  v66 = v9->mStateValues.mParamValues[8];
  v67 = v27->mStateValues.mParamValues[8];
  v27->mStateValues.mParamValues[8] = v66;
  if ( v67 == v66 )
    goto LABEL_92;
  v68 = v27->mFreeBucket;
  if ( v68 )
  {
    v69 = v68->mNumCommands;
    if ( (unsigned int)v69 < 0x7E )
    {
      v70 = (__int64)&v68->mCommands[v69];
      v68->mNumCommands = v69 + 1;
LABEL_90:
      if ( v70 )
      {
        *(_DWORD *)v70 = 524294;
        *(_QWORD *)(v70 + 8) = v66;
      }
      goto LABEL_92;
    }
    v27->mCommandCount += v68->mNumCommands;
    v27->mFreeBucket = 0i64;
  }
  v71 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v72 = v71;
  if ( v71 )
  {
    *(_QWORD *)v71 = v71;
    *((_QWORD *)v71 + 1) = v71;
    *((_QWORD *)v71 + 2) = 0i64;
    *((_DWORD *)v71 + 6) = 0;
    v73 = v27->mBuckets.mNode.mPrev;
    v73->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v72;
    *(_QWORD *)v72 = v73;
    *((_QWORD *)v72 + 1) = &v27->mBuckets;
    v27->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v72;
    v27->mFreeBucket = (Illusion::QueueCommandBucket *)v72;
  }
  v74 = v27->mFreeBucket;
  if ( v74 )
  {
    v74->mNumCommands = 1;
    v70 = (__int64)v27->mFreeBucket->mCommands;
    goto LABEL_90;
  }
LABEL_92:
  v75 = v9->mStateValues.mParamValues[9];
  v76 = v27->mStateValues.mParamValues[9];
  v27->mStateValues.mParamValues[9] = v75;
  if ( v76 == v75 )
    goto LABEL_103;
  v77 = v27->mFreeBucket;
  if ( v77 )
  {
    v78 = v77->mNumCommands;
    if ( (unsigned int)v78 < 0x7E )
    {
      v79 = (__int64)&v77->mCommands[v78];
      v77->mNumCommands = v78 + 1;
LABEL_101:
      if ( v79 )
      {
        *(_DWORD *)v79 = 589831;
        *(_QWORD *)(v79 + 8) = v75;
      }
      goto LABEL_103;
    }
    v27->mCommandCount += v77->mNumCommands;
    v27->mFreeBucket = 0i64;
  }
  v80 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v81 = v80;
  if ( v80 )
  {
    *(_QWORD *)v80 = v80;
    *((_QWORD *)v80 + 1) = v80;
    *((_QWORD *)v80 + 2) = 0i64;
    *((_DWORD *)v80 + 6) = 0;
    v82 = v27->mBuckets.mNode.mPrev;
    v82->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v81;
    *(_QWORD *)v81 = v82;
    *((_QWORD *)v81 + 1) = &v27->mBuckets;
    v27->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v81;
    v27->mFreeBucket = (Illusion::QueueCommandBucket *)v81;
  }
  v83 = v27->mFreeBucket;
  if ( v83 )
  {
    v83->mNumCommands = 1;
    v79 = (__int64)v27->mFreeBucket->mCommands;
    goto LABEL_101;
  }
LABEL_103:
  v84 = v9->mStateValues.mParamValues[10];
  v85 = v27->mStateValues.mParamValues[10];
  v27->mStateValues.mParamValues[10] = v84;
  if ( v85 == v84 )
    goto LABEL_114;
  v86 = v27->mFreeBucket;
  if ( v86 )
  {
    v87 = v86->mNumCommands;
    if ( (unsigned int)v87 < 0x7E )
    {
      v88 = (__int64)&v86->mCommands[v87];
      v86->mNumCommands = v87 + 1;
LABEL_112:
      if ( v88 )
      {
        *(_DWORD *)v88 = 655368;
        *(_QWORD *)(v88 + 8) = v84;
      }
      goto LABEL_114;
    }
    v27->mCommandCount += v86->mNumCommands;
    v27->mFreeBucket = 0i64;
  }
  v89 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v90 = v89;
  if ( v89 )
  {
    *(_QWORD *)v89 = v89;
    *((_QWORD *)v89 + 1) = v89;
    *((_QWORD *)v89 + 2) = 0i64;
    *((_DWORD *)v89 + 6) = 0;
    v91 = v27->mBuckets.mNode.mPrev;
    v91->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v90;
    *(_QWORD *)v90 = v91;
    *((_QWORD *)v90 + 1) = &v27->mBuckets;
    v27->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v90;
    v27->mFreeBucket = (Illusion::QueueCommandBucket *)v90;
  }
  v92 = v27->mFreeBucket;
  if ( v92 )
  {
    v92->mNumCommands = 1;
    v88 = (__int64)v27->mFreeBucket->mCommands;
    goto LABEL_112;
  }
LABEL_114:
  v93 = (__int64)v137;
  v94 = v137[11];
  if ( v94 )
  {
    while ( 2 )
    {
      v95 = v94 & -v94;
      v96 = !_BitScanReverse64((unsigned __int64 *)&v97, v95);
      if ( v96 )
        v98 = 0;
      else
        v98 = 63 - v97;
      v99 = 63 - v98;
      v100 = v9->mStateValues.mParamValues[63 - v98];
      v101 = (__int16)(63 - v98);
      v102 = v27->mStateValues.mParamValues[v101];
      v27->mStateValues.mParamValues[v101] = v100;
      if ( v102 == v100 )
        goto LABEL_129;
      v103 = v27->mFreeBucket;
      if ( v103 )
      {
        v104 = v103->mNumCommands;
        if ( (unsigned int)v104 < 0x7E )
        {
          v105 = (__int64)&v103->mCommands[v104];
          v103->mNumCommands = v104 + 1;
LABEL_127:
          if ( v105 )
          {
            *(_WORD *)v105 = 2;
            *(_WORD *)(v105 + 2) = v99;
            *(_QWORD *)(v105 + 8) = v100;
          }
          goto LABEL_129;
        }
        v27->mCommandCount += v103->mNumCommands;
        v27->mFreeBucket = 0i64;
      }
      v106 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
      v107 = v106;
      if ( v106 )
      {
        *(_QWORD *)v106 = v106;
        *((_QWORD *)v106 + 1) = v106;
        *((_QWORD *)v106 + 2) = 0i64;
        *((_DWORD *)v106 + 6) = 0;
        v108 = v27->mBuckets.mNode.mPrev;
        v108->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v107;
        *(_QWORD *)v107 = v108;
        *((_QWORD *)v107 + 1) = &v27->mBuckets;
        v27->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v107;
        v27->mFreeBucket = (Illusion::QueueCommandBucket *)v107;
      }
      v109 = v27->mFreeBucket;
      if ( v109 )
      {
        v109->mNumCommands = 1;
        v105 = (__int64)v27->mFreeBucket->mCommands;
        goto LABEL_127;
      }
LABEL_129:
      v94 ^= v95;
      if ( !v94 )
      {
        v93 = (__int64)v137;
        v8 = result;
        break;
      }
      continue;
    }
  }
  v110 = *(_QWORD *)(v93 + 96);
  if ( !v110 )
    goto LABEL_148;
  while ( 2 )
  {
    v111 = v110 & -v110;
    v96 = !_BitScanReverse64((unsigned __int64 *)&v112, v111);
    if ( v96 )
      v113 = 0;
    else
      v113 = 63 - v112;
    v114 = 127 - v113;
    v115 = v9->mStateValues.mParamValues[127 - v113];
    v116 = (__int16)(127 - v113);
    v117 = v27->mStateValues.mParamValues[v116];
    v27->mStateValues.mParamValues[v116] = v115;
    if ( v117 == v115 )
      goto LABEL_146;
    v118 = v27->mFreeBucket;
    if ( v118 )
    {
      v119 = v118->mNumCommands;
      if ( (unsigned int)v119 < 0x7E )
      {
        v120 = (__int64)&v118->mCommands[v119];
        v118->mNumCommands = v119 + 1;
LABEL_144:
        if ( v120 )
        {
          *(_WORD *)v120 = 2;
          *(_WORD *)(v120 + 2) = v114;
          *(_QWORD *)(v120 + 8) = v115;
        }
        goto LABEL_146;
      }
      v27->mCommandCount += v118->mNumCommands;
      v27->mFreeBucket = 0i64;
    }
    v121 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v122 = v121;
    if ( v121 )
    {
      *(_QWORD *)v121 = v121;
      *((_QWORD *)v121 + 1) = v121;
      *((_QWORD *)v121 + 2) = 0i64;
      *((_DWORD *)v121 + 6) = 0;
      v123 = v27->mBuckets.mNode.mPrev;
      v123->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v122;
      *(_QWORD *)v122 = v123;
      *((_QWORD *)v122 + 1) = &v27->mBuckets;
      v27->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v122;
      v27->mFreeBucket = (Illusion::QueueCommandBucket *)v122;
    }
    v124 = v27->mFreeBucket;
    if ( v124 )
    {
      v124->mNumCommands = 1;
      v120 = (__int64)v27->mFreeBucket->mCommands;
      goto LABEL_144;
    }
LABEL_146:
    v110 ^= v111;
    if ( v110 )
      continue;
    break;
  }
  v93 = (__int64)v137;
  v8 = result;
LABEL_148:
  v27->mStateValues.mSetValueMask.mFlags[0] |= *(_QWORD *)(v93 + 88);
  v27->mStateValues.mSetValueMask.mFlags[1] |= *(_QWORD *)(v93 + 96);
  v125 = v27->mFreeBucket;
  if ( v125 )
  {
    v126 = v125->mNumCommands;
    if ( (unsigned int)v126 < 0x7E )
    {
      v125->mNumCommands = v126 + 1;
      v127 = (__int64)&v125->mCommands[v126];
LABEL_156:
      if ( v127 )
      {
        *(_DWORD *)v127 = 10;
        *(_QWORD *)(v127 + 8) = main_mem_mesh;
      }
      goto LABEL_158;
    }
    v27->mCommandCount += v125->mNumCommands;
    v27->mFreeBucket = 0i64;
  }
  v128 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v129 = v128;
  if ( v128 )
  {
    *(_QWORD *)v128 = v128;
    *((_QWORD *)v128 + 1) = v128;
    *((_QWORD *)v128 + 2) = 0i64;
    *((_DWORD *)v128 + 6) = 0;
    v130 = v27->mBuckets.mNode.mPrev;
    v130->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v129;
    *(_QWORD *)v129 = v130;
    *((_QWORD *)v129 + 1) = &v27->mBuckets;
    v27->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v129;
    v27->mFreeBucket = (Illusion::QueueCommandBucket *)v129;
  }
  v131 = v27->mFreeBucket;
  if ( v131 )
  {
    v131->mNumCommands = 1;
    v127 = (__int64)v27->mFreeBucket->mCommands;
    goto LABEL_156;
  }
LABEL_158:
  v27->mPrimitiveCount += mNumPrims;
  v9->vfptr->OnPostSubmit(v9, v27);
LABEL_159:
  v8->mFlags[0] = already_called_funcs_mask->mFlags[0];
  v132 = already_called_funcs_mask->mFlags[1];
LABEL_161:
  v8->mFlags[1] = v132;
  return v8;
} = v27->mBuckets.mNode.mPrev;
    v130->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v129;
    *(_QWORD *)v129 = v130;
    *((_QWORD *)v129 + 1) = &v27->mBuckets;
    v27->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v129;
    v27->mFreeBucket = (Illusion::QueueCommandBucket *)v129;
  }
  v131 = v27->mFreeBucket;
  if ( v131 )
  {
    v131->mNumCommands = 1;
    v127 = (__int64)v27->mFreeBucket->mCommands;
    goto LABEL_156;
  }
LABE

// File Line: 212
// RVA: 0x8FD50
UFG::BitFlags128 *__fastcall Illusion::SubmitContext::Draw(
        Illusion::SubmitContext *this,
        UFG::BitFlags128 *result,
        Illusion::rMesh *rmesh,
        Illusion::rMaterial *rmaterial,
        UFG::BitFlags128 *already_called_funcs_mask,
        void *main_mem_mesh)
{
  Illusion::rMesh *v7; // rdi
  UFG::BitFlags128 *v8; // r13
  Illusion::SubmitContext *v9; // r12
  unsigned __int64 v10; // rax
  UFG::BitFlags128 *v11; // rsi
  __int64 mRenderPass; // r8
  Illusion::MaterialModifierData *mMaterialModifier; // rax
  Illusion::ParamOverride *mOverridesPtr; // rbx
  int mNumOverrides; // r14d
  __int64 mStateParamIndex; // rsi
  int mCondition; // edi
  UFG::qResourceData *v18; // r15
  char *v19; // r13
  UFG::qResourceData *v20; // r12
  int i; // edx
  __int64 v22; // rax
  UFG::qResourceData *v23; // r8
  __int64 v24; // rax
  Illusion::RenderQueue *v25; // rbx
  void *v26; // rdi
  void *v27; // rcx
  __int64 v28; // rdx
  __int64 v29; // rax
  __int64 mCommands; // rcx
  char *v31; // rax
  char *v32; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *mPrev; // rax
  Illusion::QueueCommandBucket *mFreeBucket; // rax
  void *v35; // rdi
  void *v36; // rax
  Illusion::QueueCommandBucket *v37; // rdx
  __int64 mNumCommands; // rax
  __int64 v39; // rcx
  char *v40; // rax
  char *v41; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v42; // rax
  Illusion::QueueCommandBucket *v43; // rax
  void *v44; // rdi
  void *v45; // rax
  Illusion::QueueCommandBucket *v46; // rdx
  __int64 v47; // rax
  __int64 v48; // rcx
  char *v49; // rax
  char *v50; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v51; // rax
  Illusion::QueueCommandBucket *v52; // rax
  int v53; // edi
  void *v54; // rsi
  __int64 v55; // rax
  void *v56; // rcx
  Illusion::QueueCommandBucket *v57; // rdx
  __int64 v58; // rax
  __int64 v59; // rcx
  char *v60; // rax
  char *v61; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v62; // rax
  Illusion::QueueCommandBucket *v63; // rax
  void *v64; // rdi
  void *v65; // rax
  Illusion::QueueCommandBucket *v66; // rdx
  __int64 v67; // rax
  __int64 v68; // rcx
  char *v69; // rax
  char *v70; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v71; // rax
  Illusion::QueueCommandBucket *v72; // rax
  void *v73; // rdi
  void *v74; // rax
  Illusion::QueueCommandBucket *v75; // rdx
  __int64 v76; // rax
  __int64 v77; // rcx
  char *v78; // rax
  char *v79; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v80; // rax
  Illusion::QueueCommandBucket *v81; // rax
  void *v82; // rdi
  void *v83; // rax
  Illusion::QueueCommandBucket *v84; // rdx
  __int64 v85; // rax
  __int64 v86; // rcx
  char *v87; // rax
  char *v88; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v89; // rax
  Illusion::QueueCommandBucket *v90; // rax
  __int64 v91; // rcx
  __int64 v92; // rsi
  unsigned __int64 v93; // rdi
  bool v94; // zf
  __int64 v95; // rcx
  int v96; // eax
  __int16 v97; // r14
  void *v98; // r15
  __int64 v99; // rax
  void *v100; // rcx
  Illusion::QueueCommandBucket *v101; // rdx
  __int64 v102; // rax
  __int64 v103; // rcx
  char *v104; // rax
  char *v105; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v106; // rax
  Illusion::QueueCommandBucket *v107; // rax
  __int64 v108; // rsi
  unsigned __int64 v109; // rdi
  __int64 v110; // rcx
  int v111; // eax
  __int16 v112; // r14
  void *v113; // r15
  __int64 v114; // rax
  void *v115; // rcx
  Illusion::QueueCommandBucket *v116; // rdx
  __int64 v117; // rax
  __int64 v118; // rcx
  char *v119; // rax
  char *v120; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v121; // rax
  Illusion::QueueCommandBucket *v122; // rax
  Illusion::QueueCommandBucket *v123; // rdx
  __int64 v124; // rcx
  __int64 v125; // rcx
  char *v126; // rax
  char *v127; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v128; // rax
  Illusion::QueueCommandBucket *v129; // rax
  unsigned __int64 v130; // rax
  UFG::qResourceData *mData; // [rsp+30h] [rbp-30h]
  UFG::qResourceData *v133; // [rsp+38h] [rbp-28h]
  const char *v134; // [rsp+48h] [rbp-18h] BYREF
  _QWORD *v135; // [rsp+50h] [rbp-10h]
  int v136; // [rsp+58h] [rbp-8h]
  unsigned int mNumPrims; // [rsp+B0h] [rbp+50h]

  v7 = rmesh;
  v8 = result;
  v9 = this;
  mData = rmesh->mVertexDeclHandle.mData;
  v133 = rmesh->mIndexBufferHandle.mData;
  if ( mData == 0i64 || v133 == 0i64 )
  {
    *result = *already_called_funcs_mask;
    return v8;
  }
  v10 = ~this->mStateArgs.mStateParamMeshFreqMask.mFlags[1];
  v11 = already_called_funcs_mask;
  already_called_funcs_mask->mFlags[0] &= ~this->mStateArgs.mStateParamMeshFreqMask.mFlags[0];
  already_called_funcs_mask->mFlags[1] &= v10;
  if ( !Illusion::IEnginePlat::IsValidDrawCall(&Illusion::gEngine, rmesh, rmaterial, 0i64, 0i64) )
    goto LABEL_159;
  if ( rmaterial )
  {
    mRenderPass = v9->mRenderPass;
    if ( (_DWORD)mRenderPass == -1
      || rmaterial->mRenderPass[mRenderPass].mIsActive && rmaterial->mStaticRenderPass->mShaderHandle[mRenderPass].mData )
    {
      Illusion::rMaterial::SetStateValues(rmaterial, &v9->mStateValues, (Illusion::eRenderPass::Enum)mRenderPass);
      goto LABEL_9;
    }
LABEL_159:
    v8->mFlags[0] = v11->mFlags[0];
    v130 = v11->mFlags[1];
    goto LABEL_160;
  }
LABEL_9:
  mMaterialModifier = v9->mMaterialModifier;
  if ( !mMaterialModifier )
    goto LABEL_28;
  mOverridesPtr = mMaterialModifier->mOverridesPtr;
  mNumOverrides = mMaterialModifier->mNumOverrides;
  if ( mNumOverrides <= 0 )
    goto LABEL_28;
  do
  {
    mStateParamIndex = mOverridesPtr->mStateParamIndex;
    if ( (_DWORD)mStateParamIndex == -1 )
      goto LABEL_26;
    mCondition = mOverridesPtr->mCondition;
    v18 = (UFG::qResourceData *)v9->mStateValues.mParamValues[mStateParamIndex];
    v19 = (char *)mOverridesPtr->mOverrideResourceHandle.mData;
    v20 = mOverridesPtr->mOriginalResourceHandle.mData;
    if ( Illusion::IEnginePlat::IsAnInvalidTextureResourceHandle(
           &Illusion::gEngine,
           &mOverridesPtr->mOverrideResourceHandle)
      || mCondition )
    {
      if ( mCondition == 3 )
      {
        v19 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, mOverridesPtr->mConstantBlockSize, 0x10u);
        UFG::qMemCopy(v19, mOverridesPtr->mConstantBlock, mOverridesPtr->mConstantBlockSize);
      }
      else if ( mCondition == 1 )
      {
        if ( v18 != v20 )
          goto LABEL_25;
      }
      else if ( mCondition != 2 || v18 == v20 )
      {
LABEL_25:
        v9 = this;
        goto LABEL_26;
      }
    }
    v9 = this;
    if ( (unsigned int)(__int16)mStateParamIndex >= 0x40 )
      this->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mStateParamIndex - 64);
    else
      this->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << mStateParamIndex;
    this->mStateValues.mParamValues[(__int16)mStateParamIndex] = v19;
LABEL_26:
    --mNumOverrides;
    ++mOverridesPtr;
  }
  while ( mNumOverrides > 0 );
  v7 = rmesh;
  v8 = result;
  v11 = already_called_funcs_mask;
LABEL_28:
  v9->mStateValues.mParamValues[2] = mData;
  v9->mStateValues.mParamValues[3] = v133;
  v9->mStateValues.mParamValues[8] = 0i64;
  for ( i = 0; i < 4; ++i )
  {
    v22 = i;
    v23 = v7->mVertexBufferHandles[v22].mData;
    if ( v7->mVertexBufferHandles[v22].mNameUID != 0 && v23 == 0i64 )
      goto LABEL_159;
    v9->mStateValues.mParamValues[(__int16)(i + 4)] = v23;
  }
  mNumPrims = v7->mNumPrims;
  v134 = "<unassigned>";
  v135 = 0i64;
  v136 = 0;
  if ( !v9->mStateValues.mParamValues[1] )
    goto LABEL_158;
  v135 = v9->mStateValues.mParamValues[1];
  v24 = (__int64)v9->vfptr->OnPreSubmit(v9, (UFG::qMemoryStream<Illusion::Shader,1160> *)&v134, v11);
  v25 = (Illusion::RenderQueue *)v24;
  if ( !v24 )
    goto LABEL_158;
  v26 = v9->mStateValues.mParamValues[1];
  v27 = *(void **)(v24 + 104);
  *(_QWORD *)(v24 + 104) = v26;
  if ( v27 != v26 )
  {
    v28 = *(_QWORD *)(v24 + 40);
    if ( v28 )
    {
      v29 = *(unsigned int *)(v28 + 24);
      if ( (unsigned int)v29 < 0x7E )
      {
        mCommands = v28 + 16 * (v29 + 2);
        *(_DWORD *)(v28 + 24) = v29 + 1;
LABEL_42:
        if ( mCommands )
        {
          *(_DWORD *)mCommands = 65537;
          *(_QWORD *)(mCommands + 8) = v26;
        }
        goto LABEL_44;
      }
      v25->mCommandCount += *(_DWORD *)(v28 + 24);
      v25->mFreeBucket = 0i64;
    }
    v31 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v32 = v31;
    if ( v31 )
    {
      *(_QWORD *)v31 = v31;
      *((_QWORD *)v31 + 1) = v31;
      *((_QWORD *)v31 + 2) = 0i64;
      *((_DWORD *)v31 + 6) = 0;
      mPrev = v25->mBuckets.mNode.mPrev;
      mPrev->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v32;
      *(_QWORD *)v32 = mPrev;
      *((_QWORD *)v32 + 1) = &v25->mBuckets;
      v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v32;
      v25->mFreeBucket = (Illusion::QueueCommandBucket *)v32;
    }
    mFreeBucket = v25->mFreeBucket;
    if ( mFreeBucket )
    {
      mFreeBucket->mNumCommands = 1;
      mCommands = (__int64)v25->mFreeBucket->mCommands;
      goto LABEL_42;
    }
LABEL_44:
    UFG::qMemSet(&v25->mStateValues.mParamValues[13], 0, 0x398u);
    v25->mStateValues.mSetValueMask.mFlags[0] &= 0x1FFFui64;
    v25->mStateValues.mSetValueMask.mFlags[1] = 0i64;
  }
  v35 = v9->mStateValues.mParamValues[2];
  v36 = v25->mStateValues.mParamValues[2];
  v25->mStateValues.mParamValues[2] = v35;
  if ( v36 == v35 )
    goto LABEL_56;
  v37 = v25->mFreeBucket;
  if ( v37 )
  {
    mNumCommands = v37->mNumCommands;
    if ( (unsigned int)mNumCommands < 0x7E )
    {
      v39 = (__int64)&v37->mCommands[mNumCommands];
      v37->mNumCommands = mNumCommands + 1;
LABEL_54:
      if ( v39 )
      {
        *(_DWORD *)v39 = 131075;
        *(_QWORD *)(v39 + 8) = v35;
      }
      goto LABEL_56;
    }
    v25->mCommandCount += v37->mNumCommands;
    v25->mFreeBucket = 0i64;
  }
  v40 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v41 = v40;
  if ( v40 )
  {
    *(_QWORD *)v40 = v40;
    *((_QWORD *)v40 + 1) = v40;
    *((_QWORD *)v40 + 2) = 0i64;
    *((_DWORD *)v40 + 6) = 0;
    v42 = v25->mBuckets.mNode.mPrev;
    v42->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v41;
    *(_QWORD *)v41 = v42;
    *((_QWORD *)v41 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v41;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v41;
  }
  v43 = v25->mFreeBucket;
  if ( v43 )
  {
    v43->mNumCommands = 1;
    v39 = (__int64)v25->mFreeBucket->mCommands;
    goto LABEL_54;
  }
LABEL_56:
  v44 = v9->mStateValues.mParamValues[3];
  v45 = v25->mStateValues.mParamValues[3];
  v25->mStateValues.mParamValues[3] = v44;
  if ( v45 == v44 )
    goto LABEL_67;
  v46 = v25->mFreeBucket;
  if ( v46 )
  {
    v47 = v46->mNumCommands;
    if ( (unsigned int)v47 < 0x7E )
    {
      v48 = (__int64)&v46->mCommands[v47];
      v46->mNumCommands = v47 + 1;
LABEL_65:
      if ( v48 )
      {
        *(_DWORD *)v48 = 196612;
        *(_QWORD *)(v48 + 8) = v44;
      }
      goto LABEL_67;
    }
    v25->mCommandCount += v46->mNumCommands;
    v25->mFreeBucket = 0i64;
  }
  v49 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v50 = v49;
  if ( v49 )
  {
    *(_QWORD *)v49 = v49;
    *((_QWORD *)v49 + 1) = v49;
    *((_QWORD *)v49 + 2) = 0i64;
    *((_DWORD *)v49 + 6) = 0;
    v51 = v25->mBuckets.mNode.mPrev;
    v51->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v50;
    *(_QWORD *)v50 = v51;
    *((_QWORD *)v50 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v50;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v50;
  }
  v52 = v25->mFreeBucket;
  if ( v52 )
  {
    v52->mNumCommands = 1;
    v48 = (__int64)v25->mFreeBucket->mCommands;
    goto LABEL_65;
  }
LABEL_67:
  v53 = 0;
  while ( 2 )
  {
    v54 = v9->mStateValues.mParamValues[v53 + 4];
    v55 = (__int16)(v53 + 4);
    v56 = v25->mStateValues.mParamValues[v55];
    v25->mStateValues.mParamValues[v55] = v54;
    if ( v56 == v54 )
      goto LABEL_79;
    v57 = v25->mFreeBucket;
    if ( v57 )
    {
      v58 = v57->mNumCommands;
      if ( (unsigned int)v58 < 0x7E )
      {
        v59 = (__int64)&v57->mCommands[v58];
        v57->mNumCommands = v58 + 1;
LABEL_77:
        if ( v59 )
        {
          *(_WORD *)v59 = 5;
          *(_WORD *)(v59 + 2) = v53;
          *(_QWORD *)(v59 + 8) = v54;
        }
        goto LABEL_79;
      }
      v25->mCommandCount += v57->mNumCommands;
      v25->mFreeBucket = 0i64;
    }
    v60 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v61 = v60;
    if ( v60 )
    {
      *(_QWORD *)v60 = v60;
      *((_QWORD *)v60 + 1) = v60;
      *((_QWORD *)v60 + 2) = 0i64;
      *((_DWORD *)v60 + 6) = 0;
      v62 = v25->mBuckets.mNode.mPrev;
      v62->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v61;
      *(_QWORD *)v61 = v62;
      *((_QWORD *)v61 + 1) = &v25->mBuckets;
      v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v61;
      v25->mFreeBucket = (Illusion::QueueCommandBucket *)v61;
    }
    v63 = v25->mFreeBucket;
    if ( v63 )
    {
      v63->mNumCommands = 1;
      v59 = (__int64)v25->mFreeBucket->mCommands;
      goto LABEL_77;
    }
LABEL_79:
    if ( (unsigned int)++v53 < 4 )
      continue;
    break;
  }
  v64 = v9->mStateValues.mParamValues[8];
  v65 = v25->mStateValues.mParamValues[8];
  v25->mStateValues.mParamValues[8] = v64;
  if ( v65 == v64 )
    goto LABEL_91;
  v66 = v25->mFreeBucket;
  if ( v66 )
  {
    v67 = v66->mNumCommands;
    if ( (unsigned int)v67 < 0x7E )
    {
      v68 = (__int64)&v66->mCommands[v67];
      v66->mNumCommands = v67 + 1;
LABEL_89:
      if ( v68 )
      {
        *(_DWORD *)v68 = 524294;
        *(_QWORD *)(v68 + 8) = v64;
      }
      goto LABEL_91;
    }
    v25->mCommandCount += v66->mNumCommands;
    v25->mFreeBucket = 0i64;
  }
  v69 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v70 = v69;
  if ( v69 )
  {
    *(_QWORD *)v69 = v69;
    *((_QWORD *)v69 + 1) = v69;
    *((_QWORD *)v69 + 2) = 0i64;
    *((_DWORD *)v69 + 6) = 0;
    v71 = v25->mBuckets.mNode.mPrev;
    v71->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v70;
    *(_QWORD *)v70 = v71;
    *((_QWORD *)v70 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v70;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v70;
  }
  v72 = v25->mFreeBucket;
  if ( v72 )
  {
    v72->mNumCommands = 1;
    v68 = (__int64)v25->mFreeBucket->mCommands;
    goto LABEL_89;
  }
LABEL_91:
  v73 = v9->mStateValues.mParamValues[9];
  v74 = v25->mStateValues.mParamValues[9];
  v25->mStateValues.mParamValues[9] = v73;
  if ( v74 == v73 )
    goto LABEL_102;
  v75 = v25->mFreeBucket;
  if ( v75 )
  {
    v76 = v75->mNumCommands;
    if ( (unsigned int)v76 < 0x7E )
    {
      v77 = (__int64)&v75->mCommands[v76];
      v75->mNumCommands = v76 + 1;
LABEL_100:
      if ( v77 )
      {
        *(_DWORD *)v77 = 589831;
        *(_QWORD *)(v77 + 8) = v73;
      }
      goto LABEL_102;
    }
    v25->mCommandCount += v75->mNumCommands;
    v25->mFreeBucket = 0i64;
  }
  v78 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v79 = v78;
  if ( v78 )
  {
    *(_QWORD *)v78 = v78;
    *((_QWORD *)v78 + 1) = v78;
    *((_QWORD *)v78 + 2) = 0i64;
    *((_DWORD *)v78 + 6) = 0;
    v80 = v25->mBuckets.mNode.mPrev;
    v80->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v79;
    *(_QWORD *)v79 = v80;
    *((_QWORD *)v79 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v79;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v79;
  }
  v81 = v25->mFreeBucket;
  if ( v81 )
  {
    v81->mNumCommands = 1;
    v77 = (__int64)v25->mFreeBucket->mCommands;
    goto LABEL_100;
  }
LABEL_102:
  v82 = v9->mStateValues.mParamValues[10];
  v83 = v25->mStateValues.mParamValues[10];
  v25->mStateValues.mParamValues[10] = v82;
  if ( v83 == v82 )
    goto LABEL_113;
  v84 = v25->mFreeBucket;
  if ( v84 )
  {
    v85 = v84->mNumCommands;
    if ( (unsigned int)v85 < 0x7E )
    {
      v86 = (__int64)&v84->mCommands[v85];
      v84->mNumCommands = v85 + 1;
LABEL_111:
      if ( v86 )
      {
        *(_DWORD *)v86 = 655368;
        *(_QWORD *)(v86 + 8) = v82;
      }
      goto LABEL_113;
    }
    v25->mCommandCount += v84->mNumCommands;
    v25->mFreeBucket = 0i64;
  }
  v87 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v88 = v87;
  if ( v87 )
  {
    *(_QWORD *)v87 = v87;
    *((_QWORD *)v87 + 1) = v87;
    *((_QWORD *)v87 + 2) = 0i64;
    *((_DWORD *)v87 + 6) = 0;
    v89 = v25->mBuckets.mNode.mPrev;
    v89->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v88;
    *(_QWORD *)v88 = v89;
    *((_QWORD *)v88 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v88;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v88;
  }
  v90 = v25->mFreeBucket;
  if ( v90 )
  {
    v90->mNumCommands = 1;
    v86 = (__int64)v25->mFreeBucket->mCommands;
    goto LABEL_111;
  }
LABEL_113:
  v91 = (__int64)v135;
  v92 = v135[11];
  if ( v92 )
  {
    while ( 2 )
    {
      v93 = v92 & -v92;
      v94 = !_BitScanReverse64((unsigned __int64 *)&v95, v93);
      if ( v94 )
        v96 = 0;
      else
        v96 = 63 - v95;
      v97 = 63 - v96;
      v98 = v9->mStateValues.mParamValues[63 - v96];
      v99 = (__int16)(63 - v96);
      v100 = v25->mStateValues.mParamValues[v99];
      v25->mStateValues.mParamValues[v99] = v98;
      if ( v100 == v98 )
        goto LABEL_128;
      v101 = v25->mFreeBucket;
      if ( v101 )
      {
        v102 = v101->mNumCommands;
        if ( (unsigned int)v102 < 0x7E )
        {
          v103 = (__int64)&v101->mCommands[v102];
          v101->mNumCommands = v102 + 1;
LABEL_126:
          if ( v103 )
          {
            *(_WORD *)v103 = 2;
            *(_WORD *)(v103 + 2) = v97;
            *(_QWORD *)(v103 + 8) = v98;
          }
          goto LABEL_128;
        }
        v25->mCommandCount += v101->mNumCommands;
        v25->mFreeBucket = 0i64;
      }
      v104 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
      v105 = v104;
      if ( v104 )
      {
        *(_QWORD *)v104 = v104;
        *((_QWORD *)v104 + 1) = v104;
        *((_QWORD *)v104 + 2) = 0i64;
        *((_DWORD *)v104 + 6) = 0;
        v106 = v25->mBuckets.mNode.mPrev;
        v106->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v105;
        *(_QWORD *)v105 = v106;
        *((_QWORD *)v105 + 1) = &v25->mBuckets;
        v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v105;
        v25->mFreeBucket = (Illusion::QueueCommandBucket *)v105;
      }
      v107 = v25->mFreeBucket;
      if ( v107 )
      {
        v107->mNumCommands = 1;
        v103 = (__int64)v25->mFreeBucket->mCommands;
        goto LABEL_126;
      }
LABEL_128:
      v92 ^= v93;
      if ( !v92 )
      {
        v91 = (__int64)v135;
        v8 = result;
        break;
      }
      continue;
    }
  }
  v108 = *(_QWORD *)(v91 + 96);
  if ( !v108 )
    goto LABEL_147;
  while ( 2 )
  {
    v109 = v108 & -v108;
    v94 = !_BitScanReverse64((unsigned __int64 *)&v110, v109);
    if ( v94 )
      v111 = 0;
    else
      v111 = 63 - v110;
    v112 = 127 - v111;
    v113 = v9->mStateValues.mParamValues[127 - v111];
    v114 = (__int16)(127 - v111);
    v115 = v25->mStateValues.mParamValues[v114];
    v25->mStateValues.mParamValues[v114] = v113;
    if ( v115 == v113 )
      goto LABEL_145;
    v116 = v25->mFreeBucket;
    if ( v116 )
    {
      v117 = v116->mNumCommands;
      if ( (unsigned int)v117 < 0x7E )
      {
        v118 = (__int64)&v116->mCommands[v117];
        v116->mNumCommands = v117 + 1;
LABEL_143:
        if ( v118 )
        {
          *(_WORD *)v118 = 2;
          *(_WORD *)(v118 + 2) = v112;
          *(_QWORD *)(v118 + 8) = v113;
        }
        goto LABEL_145;
      }
      v25->mCommandCount += v116->mNumCommands;
      v25->mFreeBucket = 0i64;
    }
    v119 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v120 = v119;
    if ( v119 )
    {
      *(_QWORD *)v119 = v119;
      *((_QWORD *)v119 + 1) = v119;
      *((_QWORD *)v119 + 2) = 0i64;
      *((_DWORD *)v119 + 6) = 0;
      v121 = v25->mBuckets.mNode.mPrev;
      v121->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v120;
      *(_QWORD *)v120 = v121;
      *((_QWORD *)v120 + 1) = &v25->mBuckets;
      v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v120;
      v25->mFreeBucket = (Illusion::QueueCommandBucket *)v120;
    }
    v122 = v25->mFreeBucket;
    if ( v122 )
    {
      v122->mNumCommands = 1;
      v118 = (__int64)v25->mFreeBucket->mCommands;
      goto LABEL_143;
    }
LABEL_145:
    v108 ^= v109;
    if ( v108 )
      continue;
    break;
  }
  v91 = (__int64)v135;
  v8 = result;
LABEL_147:
  v25->mStateValues.mSetValueMask.mFlags[0] |= *(_QWORD *)(v91 + 88);
  v25->mStateValues.mSetValueMask.mFlags[1] |= *(_QWORD *)(v91 + 96);
  v123 = v25->mFreeBucket;
  if ( v123 )
  {
    v124 = v123->mNumCommands;
    if ( (unsigned int)v124 < 0x7E )
    {
      v123->mNumCommands = v124 + 1;
      v125 = (__int64)&v123->mCommands[v124];
LABEL_155:
      if ( v125 )
      {
        *(_DWORD *)v125 = 11;
        *(_QWORD *)(v125 + 8) = main_mem_mesh;
      }
      goto LABEL_157;
    }
    v25->mCommandCount += v123->mNumCommands;
    v25->mFreeBucket = 0i64;
  }
  v126 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v127 = v126;
  if ( v126 )
  {
    *(_QWORD *)v126 = v126;
    *((_QWORD *)v126 + 1) = v126;
    *((_QWORD *)v126 + 2) = 0i64;
    *((_DWORD *)v126 + 6) = 0;
    v128 = v25->mBuckets.mNode.mPrev;
    v128->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v127;
    *(_QWORD *)v127 = v128;
    *((_QWORD *)v127 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v127;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v127;
  }
  v129 = v25->mFreeBucket;
  if ( v129 )
  {
    v129->mNumCommands = 1;
    v125 = (__int64)v25->mFreeBucket->mCommands;
    goto LABEL_155;
  }
LABEL_157:
  v25->mPrimitiveCount += mNumPrims;
  v9->vfptr->OnPostSubmit(v9, v25);
LABEL_158:
  v8->mFlags[0] = already_called_funcs_mask->mFlags[0];
  v130 = already_called_funcs_mask->mFlags[1];
LABEL_160:
  v8->mFlags[1] = v130;
  return v8;
}eady_called_funcs_mask->mFlags[0];
  v130 = already_called_funcs_mask->mFlags[1];
LABEL_160:
  v8->mFlags[1] = v130;
  return v8;
}

// File Line: 276
// RVA: 0x909B0
void __fastcall Illusion::SubmitContext::Draw(
        Illusion::SubmitContext *this,
        Illusion::Primitive *primitive,
        Illusion::Material *material)
{
  Illusion::Primitive *v4; // r13
  Illusion::SubmitContext *v5; // r12
  unsigned int mNumParams; // ecx
  Illusion::Material *v7; // rdx
  __int64 v8; // r8
  Illusion::MaterialModifierData *mMaterialModifier; // rax
  Illusion::ParamOverride *mOverridesPtr; // rbx
  int mNumOverrides; // r14d
  __int64 mStateParamIndex; // rsi
  int mCondition; // edi
  UFG::qResourceData *v14; // r15
  char *mData; // r13
  UFG::qResourceData *v16; // r12
  __int64 v17; // rax
  Illusion::RenderQueue *v18; // rbx
  void *v19; // rdi
  void *v20; // rcx
  __int64 v21; // rdx
  __int64 v22; // rax
  __int64 mCommands; // rcx
  char *v24; // rax
  char *v25; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *mPrev; // rax
  Illusion::QueueCommandBucket *mFreeBucket; // rax
  void *v28; // rdi
  void *v29; // rax
  Illusion::QueueCommandBucket *v30; // rdx
  __int64 mNumCommands; // rax
  __int64 v32; // rcx
  char *v33; // rax
  char *v34; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v35; // rax
  Illusion::QueueCommandBucket *v36; // rax
  void *v37; // rdi
  void *v38; // rax
  Illusion::QueueCommandBucket *v39; // rdx
  __int64 v40; // rax
  __int64 v41; // rcx
  char *v42; // rax
  char *v43; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v44; // rax
  Illusion::QueueCommandBucket *v45; // rax
  unsigned int i; // edi
  void *v47; // rsi
  __int64 v48; // rax
  void *v49; // rcx
  Illusion::QueueCommandBucket *v50; // rdx
  __int64 v51; // rax
  __int64 v52; // rcx
  char *v53; // rax
  char *v54; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v55; // rax
  Illusion::QueueCommandBucket *v56; // rax
  void *v57; // rdi
  void *v58; // rax
  Illusion::QueueCommandBucket *v59; // rdx
  __int64 v60; // rax
  __int64 v61; // rcx
  char *v62; // rax
  char *v63; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v64; // rax
  Illusion::QueueCommandBucket *v65; // rax
  void *v66; // rdi
  void *v67; // rax
  Illusion::QueueCommandBucket *v68; // rdx
  __int64 v69; // rax
  __int64 v70; // rcx
  char *v71; // rax
  char *v72; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v73; // rax
  Illusion::QueueCommandBucket *v74; // rax
  void *v75; // rdi
  void *v76; // rax
  Illusion::QueueCommandBucket *v77; // rdx
  __int64 v78; // rax
  __int64 v79; // rcx
  char *v80; // rax
  char *v81; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v82; // rax
  Illusion::QueueCommandBucket *v83; // rax
  __int64 v84; // rcx
  __int64 v85; // rsi
  unsigned __int64 v86; // rdi
  bool v87; // zf
  __int64 v88; // rcx
  int v89; // eax
  __int16 v90; // r14
  void *v91; // r15
  __int64 v92; // rax
  void *v93; // rcx
  Illusion::QueueCommandBucket *v94; // rdx
  __int64 v95; // rax
  __int64 v96; // rcx
  char *v97; // rax
  char *v98; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v99; // rax
  Illusion::QueueCommandBucket *v100; // rax
  __int64 v101; // rsi
  unsigned __int64 v102; // rdi
  __int64 v103; // rcx
  int v104; // eax
  __int16 v105; // r14
  void *v106; // r15
  __int64 v107; // rax
  void *v108; // rcx
  Illusion::QueueCommandBucket *v109; // rdx
  __int64 v110; // rax
  __int64 v111; // rcx
  char *v112; // rax
  char *v113; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v114; // rax
  Illusion::QueueCommandBucket *v115; // rax
  Illusion::QueueCommandBucket *v116; // rcx
  __int64 v117; // rdx
  __int64 v118; // rax
  char *v119; // rax
  char *v120; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v121; // rax
  Illusion::QueueCommandBucket *v122; // rax
  __int64 v123[2]; // [rsp+30h] [rbp-30h] BYREF
  const char *v124; // [rsp+40h] [rbp-20h] BYREF
  _QWORD *v125; // [rsp+48h] [rbp-18h]
  int v126; // [rsp+50h] [rbp-10h]

  v4 = primitive;
  v5 = this;
  if ( !Illusion::IEnginePlat::IsValidDrawCall(&Illusion::gEngine, material) )
    return;
  if ( material )
  {
    mNumParams = material->mNumParams;
    if ( !mNumParams )
      goto LABEL_27;
    v7 = material + 1;
    v5->mStateValues.mSetValueMask.mFlags[0] = material->mStateBlockMask.mFlags[0];
    v5->mStateValues.mSetValueMask.mFlags[1] = material->mStateBlockMask.mFlags[1];
    v8 = mNumParams;
    do
    {
      if ( v7 )
        v5->mStateValues.mParamValues[SLOWORD(v7->mNode.mChild[0])] = v7->mResourceHandles.UFG::qResourceData::mNode.mPrev;
      v7 = (Illusion::Material *)((char *)v7 + 56);
      --v8;
    }
    while ( v8 );
  }
  mMaterialModifier = v5->mMaterialModifier;
  if ( mMaterialModifier )
  {
    mOverridesPtr = mMaterialModifier->mOverridesPtr;
    mNumOverrides = mMaterialModifier->mNumOverrides;
    if ( mNumOverrides > 0 )
    {
      while ( 1 )
      {
        mStateParamIndex = mOverridesPtr->mStateParamIndex;
        if ( (_DWORD)mStateParamIndex != -1 )
        {
          mCondition = mOverridesPtr->mCondition;
          v14 = (UFG::qResourceData *)v5->mStateValues.mParamValues[mStateParamIndex];
          mData = (char *)mOverridesPtr->mOverrideResourceHandle.mData;
          v16 = mOverridesPtr->mOriginalResourceHandle.mData;
          if ( !Illusion::IEnginePlat::IsAnInvalidTextureResourceHandle(
                  &Illusion::gEngine,
                  &mOverridesPtr->mOverrideResourceHandle)
            && !mCondition )
          {
            goto LABEL_20;
          }
          if ( mCondition == 3 )
          {
            mData = UFG::qLinearAllocator::Malloc(
                      Illusion::gEngine.FrameMemory,
                      mOverridesPtr->mConstantBlockSize,
                      0x10u);
            UFG::qMemCopy(mData, mOverridesPtr->mConstantBlock, mOverridesPtr->mConstantBlockSize);
LABEL_20:
            v5 = this;
            if ( (unsigned int)(__int16)mStateParamIndex >= 0x40 )
              this->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mStateParamIndex - 64);
            else
              this->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << mStateParamIndex;
            this->mStateValues.mParamValues[(__int16)mStateParamIndex] = mData;
            goto LABEL_25;
          }
          if ( mCondition == 1 )
          {
            if ( v14 == v16 )
              goto LABEL_20;
          }
          else if ( mCondition == 2 && v14 != v16 )
          {
            goto LABEL_20;
          }
          v5 = this;
        }
LABEL_25:
        --mNumOverrides;
        ++mOverridesPtr;
        if ( mNumOverrides <= 0 )
        {
          v4 = primitive;
          break;
        }
      }
    }
  }
LABEL_27:
  v5->mStateValues.mParamValues[2] = v4->mVertexDecl;
  v5->mStateValues.mParamValues[3] = 0i64;
  v5->mStateValues.mParamValues[4] = 0i64;
  v5->mStateValues.mParamValues[5] = 0i64;
  v5->mStateValues.mParamValues[6] = 0i64;
  v5->mStateValues.mParamValues[7] = 0i64;
  v5->mStateValues.mParamValues[8] = 0i64;
  v123[0] = 0i64;
  v123[1] = 0i64;
  v124 = "<unassigned>";
  v125 = 0i64;
  v126 = 0;
  if ( !v5->mStateValues.mParamValues[1] )
    return;
  v125 = v5->mStateValues.mParamValues[1];
  v17 = (__int64)v5->vfptr->OnPreSubmit(
                   v5,
                   (UFG::qMemoryStream<Illusion::Shader,1160> *)&v124,
                   (UFG::BitFlags128 *)v123);
  v18 = (Illusion::RenderQueue *)v17;
  if ( !v17 )
    return;
  v19 = v5->mStateValues.mParamValues[1];
  v20 = *(void **)(v17 + 104);
  *(_QWORD *)(v17 + 104) = v19;
  if ( v20 != v19 )
  {
    v21 = *(_QWORD *)(v17 + 40);
    if ( v21 )
    {
      v22 = *(unsigned int *)(v21 + 24);
      if ( (unsigned int)v22 < 0x7E )
      {
        mCommands = v21 + 16 * (v22 + 2);
        *(_DWORD *)(v21 + 24) = v22 + 1;
        goto LABEL_38;
      }
      v18->mCommandCount += *(_DWORD *)(v21 + 24);
      v18->mFreeBucket = 0i64;
    }
    v24 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v25 = v24;
    if ( v24 )
    {
      *(_QWORD *)v24 = v24;
      *((_QWORD *)v24 + 1) = v24;
      *((_QWORD *)v24 + 2) = 0i64;
      *((_DWORD *)v24 + 6) = 0;
      mPrev = v18->mBuckets.mNode.mPrev;
      mPrev->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v25;
      *(_QWORD *)v25 = mPrev;
      *((_QWORD *)v25 + 1) = &v18->mBuckets;
      v18->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v25;
      v18->mFreeBucket = (Illusion::QueueCommandBucket *)v25;
    }
    mFreeBucket = v18->mFreeBucket;
    if ( !mFreeBucket )
      goto LABEL_40;
    mFreeBucket->mNumCommands = 1;
    mCommands = (__int64)v18->mFreeBucket->mCommands;
LABEL_38:
    if ( mCommands )
    {
      *(_DWORD *)mCommands = 65537;
      *(_QWORD *)(mCommands + 8) = v19;
    }
LABEL_40:
    UFG::qMemSet(&v18->mStateValues.mParamValues[13], 0, 0x398u);
    v18->mStateValues.mSetValueMask.mFlags[0] &= 0x1FFFui64;
    v18->mStateValues.mSetValueMask.mFlags[1] = 0i64;
  }
  v28 = v5->mStateValues.mParamValues[2];
  v29 = v18->mStateValues.mParamValues[2];
  v18->mStateValues.mParamValues[2] = v28;
  if ( v29 == v28 )
    goto LABEL_52;
  v30 = v18->mFreeBucket;
  if ( v30 )
  {
    mNumCommands = v30->mNumCommands;
    if ( (unsigned int)mNumCommands < 0x7E )
    {
      v32 = (__int64)&v30->mCommands[mNumCommands];
      v30->mNumCommands = mNumCommands + 1;
      goto LABEL_50;
    }
    v18->mCommandCount += v30->mNumCommands;
    v18->mFreeBucket = 0i64;
  }
  v33 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v34 = v33;
  if ( v33 )
  {
    *(_QWORD *)v33 = v33;
    *((_QWORD *)v33 + 1) = v33;
    *((_QWORD *)v33 + 2) = 0i64;
    *((_DWORD *)v33 + 6) = 0;
    v35 = v18->mBuckets.mNode.mPrev;
    v35->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v34;
    *(_QWORD *)v34 = v35;
    *((_QWORD *)v34 + 1) = &v18->mBuckets;
    v18->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v34;
    v18->mFreeBucket = (Illusion::QueueCommandBucket *)v34;
  }
  v36 = v18->mFreeBucket;
  if ( v36 )
  {
    v36->mNumCommands = 1;
    v32 = (__int64)v18->mFreeBucket->mCommands;
LABEL_50:
    if ( v32 )
    {
      *(_DWORD *)v32 = 131075;
      *(_QWORD *)(v32 + 8) = v28;
    }
  }
LABEL_52:
  v37 = v5->mStateValues.mParamValues[3];
  v38 = v18->mStateValues.mParamValues[3];
  v18->mStateValues.mParamValues[3] = v37;
  if ( v38 != v37 )
  {
    v39 = v18->mFreeBucket;
    if ( v39 )
    {
      v40 = v39->mNumCommands;
      if ( (unsigned int)v40 < 0x7E )
      {
        v41 = (__int64)&v39->mCommands[v40];
        v39->mNumCommands = v40 + 1;
LABEL_61:
        if ( v41 )
        {
          *(_DWORD *)v41 = 196612;
          *(_QWORD *)(v41 + 8) = v37;
        }
        goto LABEL_63;
      }
      v18->mCommandCount += v39->mNumCommands;
      v18->mFreeBucket = 0i64;
    }
    v42 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v43 = v42;
    if ( v42 )
    {
      *(_QWORD *)v42 = v42;
      *((_QWORD *)v42 + 1) = v42;
      *((_QWORD *)v42 + 2) = 0i64;
      *((_DWORD *)v42 + 6) = 0;
      v44 = v18->mBuckets.mNode.mPrev;
      v44->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v43;
      *(_QWORD *)v43 = v44;
      *((_QWORD *)v43 + 1) = &v18->mBuckets;
      v18->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v43;
      v18->mFreeBucket = (Illusion::QueueCommandBucket *)v43;
    }
    v45 = v18->mFreeBucket;
    if ( !v45 )
      goto LABEL_63;
    v45->mNumCommands = 1;
    v41 = (__int64)v18->mFreeBucket->mCommands;
    goto LABEL_61;
  }
LABEL_63:
  for ( i = 0; i < 4; ++i )
  {
    v47 = v5->mStateValues.mParamValues[(int)i + 4];
    v48 = (__int16)(i + 4);
    v49 = v18->mStateValues.mParamValues[v48];
    v18->mStateValues.mParamValues[v48] = v47;
    if ( v49 == v47 )
      continue;
    v50 = v18->mFreeBucket;
    if ( v50 )
    {
      v51 = v50->mNumCommands;
      if ( (unsigned int)v51 < 0x7E )
      {
        v52 = (__int64)&v50->mCommands[v51];
        v50->mNumCommands = v51 + 1;
        goto LABEL_73;
      }
      v18->mCommandCount += v50->mNumCommands;
      v18->mFreeBucket = 0i64;
    }
    v53 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v54 = v53;
    if ( v53 )
    {
      *(_QWORD *)v53 = v53;
      *((_QWORD *)v53 + 1) = v53;
      *((_QWORD *)v53 + 2) = 0i64;
      *((_DWORD *)v53 + 6) = 0;
      v55 = v18->mBuckets.mNode.mPrev;
      v55->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v54;
      *(_QWORD *)v54 = v55;
      *((_QWORD *)v54 + 1) = &v18->mBuckets;
      v18->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v54;
      v18->mFreeBucket = (Illusion::QueueCommandBucket *)v54;
    }
    v56 = v18->mFreeBucket;
    if ( v56 )
    {
      v56->mNumCommands = 1;
      v52 = (__int64)v18->mFreeBucket->mCommands;
LABEL_73:
      if ( v52 )
      {
        *(_WORD *)v52 = 5;
        *(_WORD *)(v52 + 2) = i;
        *(_QWORD *)(v52 + 8) = v47;
      }
      continue;
    }
  }
  v57 = v5->mStateValues.mParamValues[8];
  v58 = v18->mStateValues.mParamValues[8];
  v18->mStateValues.mParamValues[8] = v57;
  if ( v58 == v57 )
    goto LABEL_87;
  v59 = v18->mFreeBucket;
  if ( v59 )
  {
    v60 = v59->mNumCommands;
    if ( (unsigned int)v60 < 0x7E )
    {
      v61 = (__int64)&v59->mCommands[v60];
      v59->mNumCommands = v60 + 1;
LABEL_85:
      if ( v61 )
      {
        *(_DWORD *)v61 = 524294;
        *(_QWORD *)(v61 + 8) = v57;
      }
      goto LABEL_87;
    }
    v18->mCommandCount += v59->mNumCommands;
    v18->mFreeBucket = 0i64;
  }
  v62 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v63 = v62;
  if ( v62 )
  {
    *(_QWORD *)v62 = v62;
    *((_QWORD *)v62 + 1) = v62;
    *((_QWORD *)v62 + 2) = 0i64;
    *((_DWORD *)v62 + 6) = 0;
    v64 = v18->mBuckets.mNode.mPrev;
    v64->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v63;
    *(_QWORD *)v63 = v64;
    *((_QWORD *)v63 + 1) = &v18->mBuckets;
    v18->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v63;
    v18->mFreeBucket = (Illusion::QueueCommandBucket *)v63;
  }
  v65 = v18->mFreeBucket;
  if ( v65 )
  {
    v65->mNumCommands = 1;
    v61 = (__int64)v18->mFreeBucket->mCommands;
    goto LABEL_85;
  }
LABEL_87:
  v66 = v5->mStateValues.mParamValues[9];
  v67 = v18->mStateValues.mParamValues[9];
  v18->mStateValues.mParamValues[9] = v66;
  if ( v67 == v66 )
    goto LABEL_98;
  v68 = v18->mFreeBucket;
  if ( v68 )
  {
    v69 = v68->mNumCommands;
    if ( (unsigned int)v69 < 0x7E )
    {
      v70 = (__int64)&v68->mCommands[v69];
      v68->mNumCommands = v69 + 1;
LABEL_96:
      if ( v70 )
      {
        *(_DWORD *)v70 = 589831;
        *(_QWORD *)(v70 + 8) = v66;
      }
      goto LABEL_98;
    }
    v18->mCommandCount += v68->mNumCommands;
    v18->mFreeBucket = 0i64;
  }
  v71 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v72 = v71;
  if ( v71 )
  {
    *(_QWORD *)v71 = v71;
    *((_QWORD *)v71 + 1) = v71;
    *((_QWORD *)v71 + 2) = 0i64;
    *((_DWORD *)v71 + 6) = 0;
    v73 = v18->mBuckets.mNode.mPrev;
    v73->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v72;
    *(_QWORD *)v72 = v73;
    *((_QWORD *)v72 + 1) = &v18->mBuckets;
    v18->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v72;
    v18->mFreeBucket = (Illusion::QueueCommandBucket *)v72;
  }
  v74 = v18->mFreeBucket;
  if ( v74 )
  {
    v74->mNumCommands = 1;
    v70 = (__int64)v18->mFreeBucket->mCommands;
    goto LABEL_96;
  }
LABEL_98:
  v75 = v5->mStateValues.mParamValues[10];
  v76 = v18->mStateValues.mParamValues[10];
  v18->mStateValues.mParamValues[10] = v75;
  if ( v76 == v75 )
    goto LABEL_109;
  v77 = v18->mFreeBucket;
  if ( v77 )
  {
    v78 = v77->mNumCommands;
    if ( (unsigned int)v78 < 0x7E )
    {
      v79 = (__int64)&v77->mCommands[v78];
      v77->mNumCommands = v78 + 1;
LABEL_107:
      if ( v79 )
      {
        *(_DWORD *)v79 = 655368;
        *(_QWORD *)(v79 + 8) = v75;
      }
      goto LABEL_109;
    }
    v18->mCommandCount += v77->mNumCommands;
    v18->mFreeBucket = 0i64;
  }
  v80 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v81 = v80;
  if ( v80 )
  {
    *(_QWORD *)v80 = v80;
    *((_QWORD *)v80 + 1) = v80;
    *((_QWORD *)v80 + 2) = 0i64;
    *((_DWORD *)v80 + 6) = 0;
    v82 = v18->mBuckets.mNode.mPrev;
    v82->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v81;
    *(_QWORD *)v81 = v82;
    *((_QWORD *)v81 + 1) = &v18->mBuckets;
    v18->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v81;
    v18->mFreeBucket = (Illusion::QueueCommandBucket *)v81;
  }
  v83 = v18->mFreeBucket;
  if ( v83 )
  {
    v83->mNumCommands = 1;
    v79 = (__int64)v18->mFreeBucket->mCommands;
    goto LABEL_107;
  }
LABEL_109:
  v84 = (__int64)v125;
  v85 = v125[11];
  if ( v85 )
  {
    while ( 2 )
    {
      v86 = v85 & -v85;
      v87 = !_BitScanReverse64((unsigned __int64 *)&v88, v86);
      if ( v87 )
        v89 = 0;
      else
        v89 = 63 - v88;
      v90 = 63 - v89;
      v91 = v5->mStateValues.mParamValues[63 - v89];
      v92 = (__int16)(63 - v89);
      v93 = v18->mStateValues.mParamValues[v92];
      v18->mStateValues.mParamValues[v92] = v91;
      if ( v93 == v91 )
        goto LABEL_124;
      v94 = v18->mFreeBucket;
      if ( v94 )
      {
        v95 = v94->mNumCommands;
        if ( (unsigned int)v95 < 0x7E )
        {
          v96 = (__int64)&v94->mCommands[v95];
          v94->mNumCommands = v95 + 1;
LABEL_122:
          if ( v96 )
          {
            *(_WORD *)v96 = 2;
            *(_WORD *)(v96 + 2) = v90;
            *(_QWORD *)(v96 + 8) = v91;
          }
          goto LABEL_124;
        }
        v18->mCommandCount += v94->mNumCommands;
        v18->mFreeBucket = 0i64;
      }
      v97 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
      v98 = v97;
      if ( v97 )
      {
        *(_QWORD *)v97 = v97;
        *((_QWORD *)v97 + 1) = v97;
        *((_QWORD *)v97 + 2) = 0i64;
        *((_DWORD *)v97 + 6) = 0;
        v99 = v18->mBuckets.mNode.mPrev;
        v99->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v98;
        *(_QWORD *)v98 = v99;
        *((_QWORD *)v98 + 1) = &v18->mBuckets;
        v18->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v98;
        v18->mFreeBucket = (Illusion::QueueCommandBucket *)v98;
      }
      v100 = v18->mFreeBucket;
      if ( v100 )
      {
        v100->mNumCommands = 1;
        v96 = (__int64)v18->mFreeBucket->mCommands;
        goto LABEL_122;
      }
LABEL_124:
      v85 ^= v86;
      if ( !v85 )
      {
        v84 = (__int64)v125;
        v4 = primitive;
        break;
      }
      continue;
    }
  }
  v101 = *(_QWORD *)(v84 + 96);
  if ( !v101 )
    goto LABEL_143;
  while ( 2 )
  {
    v102 = v101 & -v101;
    v87 = !_BitScanReverse64((unsigned __int64 *)&v103, v102);
    if ( v87 )
      v104 = 0;
    else
      v104 = 63 - v103;
    v105 = 127 - v104;
    v106 = v5->mStateValues.mParamValues[127 - v104];
    v107 = (__int16)(127 - v104);
    v108 = v18->mStateValues.mParamValues[v107];
    v18->mStateValues.mParamValues[v107] = v106;
    if ( v108 == v106 )
      goto LABEL_141;
    v109 = v18->mFreeBucket;
    if ( v109 )
    {
      v110 = v109->mNumCommands;
      if ( (unsigned int)v110 < 0x7E )
      {
        v111 = (__int64)&v109->mCommands[v110];
        v109->mNumCommands = v110 + 1;
LABEL_139:
        if ( v111 )
        {
          *(_WORD *)v111 = 2;
          *(_WORD *)(v111 + 2) = v105;
          *(_QWORD *)(v111 + 8) = v106;
        }
        goto LABEL_141;
      }
      v18->mCommandCount += v109->mNumCommands;
      v18->mFreeBucket = 0i64;
    }
    v112 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v113 = v112;
    if ( v112 )
    {
      *(_QWORD *)v112 = v112;
      *((_QWORD *)v112 + 1) = v112;
      *((_QWORD *)v112 + 2) = 0i64;
      *((_DWORD *)v112 + 6) = 0;
      v114 = v18->mBuckets.mNode.mPrev;
      v114->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v113;
      *(_QWORD *)v113 = v114;
      *((_QWORD *)v113 + 1) = &v18->mBuckets;
      v18->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v113;
      v18->mFreeBucket = (Illusion::QueueCommandBucket *)v113;
    }
    v115 = v18->mFreeBucket;
    if ( v115 )
    {
      v115->mNumCommands = 1;
      v111 = (__int64)v18->mFreeBucket->mCommands;
      goto LABEL_139;
    }
LABEL_141:
    v101 ^= v102;
    if ( v101 )
      continue;
    break;
  }
  v84 = (__int64)v125;
  v4 = primitive;
LABEL_143:
  v18->mStateValues.mSetValueMask.mFlags[0] |= *(_QWORD *)(v84 + 88);
  v18->mStateValues.mSetValueMask.mFlags[1] |= *(_QWORD *)(v84 + 96);
  v116 = v18->mFreeBucket;
  if ( v116 )
  {
    v117 = v116->mNumCommands;
    if ( (unsigned int)v117 < 0x7E )
    {
      v116->mNumCommands = v117 + 1;
      v118 = (__int64)&v116->mCommands[v117];
LABEL_151:
      if ( v118 )
      {
        *(_DWORD *)v118 = 12;
        *(_QWORD *)(v118 + 8) = v4;
      }
      goto LABEL_153;
    }
    v18->mCommandCount += v116->mNumCommands;
    v18->mFreeBucket = 0i64;
  }
  v119 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v120 = v119;
  if ( v119 )
  {
    *(_QWORD *)v119 = v119;
    *((_QWORD *)v119 + 1) = v119;
    *((_QWORD *)v119 + 2) = 0i64;
    *((_DWORD *)v119 + 6) = 0;
    v121 = v18->mBuckets.mNode.mPrev;
    v121->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v120;
    *(_QWORD *)v120 = v121;
    *((_QWORD *)v120 + 1) = &v18->mBuckets;
    v18->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v120;
    v18->mFreeBucket = (Illusion::QueueCommandBucket *)v120;
  }
  v122 = v18->mFreeBucket;
  if ( v122 )
  {
    v122->mNumCommands = 1;
    v118 = (__int64)v18->mFreeBucket->mCommands;
    goto LABEL_151;
  }
LABEL_153:
  v5->vfptr->OnPostSubmit(v5, v18);
}

// File Line: 310
// RVA: 0x91470
void __fastcall Illusion::SubmitContext::DrawInstanced(
        Illusion::SubmitContext *this,
        Illusion::Mesh *mesh,
        Illusion::Buffer *instance_buffer,
        unsigned int instance_count,
        Illusion::Material *force_mat,
        Illusion::Buffer *force_index_buffer,
        void *main_mem_mesh)
{
  unsigned int v7; // edi
  Illusion::SubmitContext *v8; // r12
  Illusion::Buffer *v9; // rax
  Illusion::Material *v10; // rbx
  unsigned int mNumParams; // ecx
  Illusion::Material *v12; // rdx
  __int64 v13; // r8
  Illusion::MaterialModifierData *mMaterialModifier; // rax
  Illusion::ParamOverride *mOverridesPtr; // rbx
  int mNumOverrides; // r14d
  __int64 mStateParamIndex; // rsi
  int mCondition; // edi
  UFG::qResourceData *v19; // r15
  char *v20; // r13
  UFG::qResourceData *v21; // r12
  char *v22; // rax
  void *v23; // r13
  __int64 v24; // rax
  Illusion::RenderQueue *v25; // rbx
  void *v26; // rdi
  void *v27; // rcx
  __int64 v28; // rdx
  __int64 v29; // rax
  __int64 mCommands; // rcx
  char *v31; // rax
  char *v32; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *mPrev; // rax
  Illusion::QueueCommandBucket *mFreeBucket; // rax
  void *v35; // rdi
  void *v36; // rax
  Illusion::QueueCommandBucket *v37; // rdx
  __int64 mNumCommands; // rax
  __int64 v39; // rcx
  char *v40; // rax
  char *v41; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v42; // rax
  Illusion::QueueCommandBucket *v43; // rax
  void *v44; // rdi
  void *v45; // rax
  Illusion::QueueCommandBucket *v46; // rdx
  __int64 v47; // rax
  __int64 v48; // rcx
  char *v49; // rax
  char *v50; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v51; // rax
  Illusion::QueueCommandBucket *v52; // rax
  unsigned int i; // edi
  void *v54; // rsi
  __int64 v55; // rax
  void *v56; // rcx
  Illusion::QueueCommandBucket *v57; // rdx
  __int64 v58; // rax
  __int64 v59; // rcx
  char *v60; // rax
  char *v61; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v62; // rax
  Illusion::QueueCommandBucket *v63; // rax
  void *v64; // rdi
  void *v65; // rax
  Illusion::QueueCommandBucket *v66; // rdx
  __int64 v67; // rax
  __int64 v68; // rcx
  char *v69; // rax
  char *v70; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v71; // rax
  Illusion::QueueCommandBucket *v72; // rax
  void *v73; // rdi
  void *v74; // rax
  Illusion::QueueCommandBucket *v75; // rdx
  __int64 v76; // rax
  __int64 v77; // rcx
  char *v78; // rax
  char *v79; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v80; // rax
  Illusion::QueueCommandBucket *v81; // rax
  void *v82; // rdi
  void *v83; // rax
  Illusion::QueueCommandBucket *v84; // rdx
  __int64 v85; // rax
  __int64 v86; // rcx
  char *v87; // rax
  char *v88; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v89; // rax
  Illusion::QueueCommandBucket *v90; // rax
  __int64 v91; // rcx
  __int64 v92; // rsi
  unsigned __int64 v93; // rdi
  bool v94; // zf
  __int64 v95; // rcx
  int v96; // eax
  __int16 v97; // r14
  void *v98; // r15
  __int64 v99; // rax
  void *v100; // rcx
  Illusion::QueueCommandBucket *v101; // rdx
  __int64 v102; // rax
  __int64 v103; // rcx
  char *v104; // rax
  char *v105; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v106; // rax
  Illusion::QueueCommandBucket *v107; // rax
  __int64 v108; // rsi
  unsigned __int64 v109; // rdi
  __int64 v110; // rcx
  int v111; // eax
  __int16 v112; // r14
  void *v113; // r15
  __int64 v114; // rax
  void *v115; // rcx
  Illusion::QueueCommandBucket *v116; // rdx
  __int64 v117; // rax
  __int64 v118; // rcx
  char *v119; // rax
  char *v120; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v121; // rax
  Illusion::QueueCommandBucket *v122; // rax
  Illusion::QueueCommandBucket *v123; // rcx
  __int64 v124; // rdx
  __int64 v125; // rax
  char *v126; // rax
  char *v127; // rdx
  UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *v128; // rax
  Illusion::QueueCommandBucket *v129; // rax
  UFG::qResourceData *v130; // [rsp+30h] [rbp-48h]
  __int64 v131[2]; // [rsp+40h] [rbp-38h] BYREF
  const char *v132; // [rsp+50h] [rbp-28h] BYREF
  _QWORD *v133; // [rsp+58h] [rbp-20h]
  int v134; // [rsp+60h] [rbp-18h]
  UFG::qResourceData *mData; // [rsp+C8h] [rbp+50h]
  Illusion::Buffer *force_index_buffera; // [rsp+E8h] [rbp+70h]

  v7 = instance_count;
  v8 = this;
  mData = mesh->mVertexDeclHandle.mData;
  v130 = mesh->mVertexBufferHandles[0].mData;
  v9 = force_index_buffer;
  if ( !force_index_buffer )
  {
    v9 = (Illusion::Buffer *)mesh->mIndexBufferHandle.mData;
    force_index_buffer = v9;
  }
  v10 = force_mat;
  if ( !force_mat )
    v10 = (Illusion::Material *)mesh->mMaterialHandle.mData;
  if ( !Illusion::IEnginePlat::IsValidDrawCall(&Illusion::gEngine, mesh, v10, v9, instance_buffer) )
    return;
  if ( v10 )
  {
    mNumParams = v10->mNumParams;
    if ( !mNumParams )
      goto LABEL_31;
    v12 = v10 + 1;
    v8->mStateValues.mSetValueMask.mFlags[0] = v10->mStateBlockMask.mFlags[0];
    v8->mStateValues.mSetValueMask.mFlags[1] = v10->mStateBlockMask.mFlags[1];
    v13 = mNumParams;
    do
    {
      if ( v12 )
        v8->mStateValues.mParamValues[SLOWORD(v12->mNode.mChild[0])] = v12->mResourceHandles.UFG::qResourceData::mNode.mPrev;
      v12 = (Illusion::Material *)((char *)v12 + 56);
      --v13;
    }
    while ( v13 );
  }
  mMaterialModifier = v8->mMaterialModifier;
  if ( mMaterialModifier )
  {
    mOverridesPtr = mMaterialModifier->mOverridesPtr;
    mNumOverrides = mMaterialModifier->mNumOverrides;
    if ( mNumOverrides > 0 )
    {
      while ( 1 )
      {
        mStateParamIndex = mOverridesPtr->mStateParamIndex;
        if ( (_DWORD)mStateParamIndex != -1 )
        {
          mCondition = mOverridesPtr->mCondition;
          v19 = (UFG::qResourceData *)v8->mStateValues.mParamValues[mStateParamIndex];
          v20 = (char *)mOverridesPtr->mOverrideResourceHandle.mData;
          v21 = mOverridesPtr->mOriginalResourceHandle.mData;
          if ( !Illusion::IEnginePlat::IsAnInvalidTextureResourceHandle(
                  &Illusion::gEngine,
                  &mOverridesPtr->mOverrideResourceHandle)
            && !mCondition )
          {
            goto LABEL_24;
          }
          if ( mCondition == 3 )
          {
            v20 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, mOverridesPtr->mConstantBlockSize, 0x10u);
            UFG::qMemCopy(v20, mOverridesPtr->mConstantBlock, mOverridesPtr->mConstantBlockSize);
LABEL_24:
            v8 = this;
            if ( (unsigned int)(__int16)mStateParamIndex >= 0x40 )
              this->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)mStateParamIndex - 64);
            else
              this->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << mStateParamIndex;
            this->mStateValues.mParamValues[(__int16)mStateParamIndex] = v20;
            goto LABEL_29;
          }
          if ( mCondition == 1 )
          {
            if ( v19 == v21 )
              goto LABEL_24;
          }
          else if ( mCondition == 2 && v19 != v21 )
          {
            goto LABEL_24;
          }
          v8 = this;
        }
LABEL_29:
        --mNumOverrides;
        ++mOverridesPtr;
        if ( mNumOverrides <= 0 )
        {
          v7 = instance_count;
          break;
        }
      }
    }
  }
LABEL_31:
  v8->mStateValues.mParamValues[2] = mData;
  v8->mStateValues.mParamValues[4] = v130;
  v8->mStateValues.mParamValues[5] = 0i64;
  v8->mStateValues.mParamValues[6] = 0i64;
  v8->mStateValues.mParamValues[3] = force_index_buffer;
  v8->mStateValues.mParamValues[7] = 0i64;
  v8->mStateValues.mParamValues[8] = instance_buffer;
  v22 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
  v23 = v22;
  force_index_buffera = (Illusion::Buffer *)v22;
  if ( v22 )
  {
    *(_QWORD *)v22 = main_mem_mesh;
    *((_DWORD *)v22 + 2) = v7;
  }
  v131[0] = 0i64;
  v131[1] = 0i64;
  v132 = "<unassigned>";
  v133 = 0i64;
  v134 = 0;
  if ( !v8->mStateValues.mParamValues[1] )
    return;
  v133 = v8->mStateValues.mParamValues[1];
  v24 = (__int64)v8->vfptr->OnPreSubmit(
                   v8,
                   (UFG::qMemoryStream<Illusion::Shader,1160> *)&v132,
                   (UFG::BitFlags128 *)v131);
  v25 = (Illusion::RenderQueue *)v24;
  if ( !v24 )
    return;
  v26 = v8->mStateValues.mParamValues[1];
  v27 = *(void **)(v24 + 104);
  *(_QWORD *)(v24 + 104) = v26;
  if ( v27 != v26 )
  {
    v28 = *(_QWORD *)(v24 + 40);
    if ( v28 )
    {
      v29 = *(unsigned int *)(v28 + 24);
      if ( (unsigned int)v29 < 0x7E )
      {
        mCommands = v28 + 16 * (v29 + 2);
        *(_DWORD *)(v28 + 24) = v29 + 1;
        goto LABEL_44;
      }
      v25->mCommandCount += *(_DWORD *)(v28 + 24);
      v25->mFreeBucket = 0i64;
    }
    v31 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v32 = v31;
    if ( v31 )
    {
      *(_QWORD *)v31 = v31;
      *((_QWORD *)v31 + 1) = v31;
      *((_QWORD *)v31 + 2) = 0i64;
      *((_DWORD *)v31 + 6) = 0;
      mPrev = v25->mBuckets.mNode.mPrev;
      mPrev->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v32;
      *(_QWORD *)v32 = mPrev;
      *((_QWORD *)v32 + 1) = &v25->mBuckets;
      v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v32;
      v25->mFreeBucket = (Illusion::QueueCommandBucket *)v32;
    }
    mFreeBucket = v25->mFreeBucket;
    if ( !mFreeBucket )
      goto LABEL_46;
    mFreeBucket->mNumCommands = 1;
    mCommands = (__int64)v25->mFreeBucket->mCommands;
LABEL_44:
    if ( mCommands )
    {
      *(_DWORD *)mCommands = 65537;
      *(_QWORD *)(mCommands + 8) = v26;
    }
LABEL_46:
    UFG::qMemSet(&v25->mStateValues.mParamValues[13], 0, 0x398u);
    v25->mStateValues.mSetValueMask.mFlags[0] &= 0x1FFFui64;
    v25->mStateValues.mSetValueMask.mFlags[1] = 0i64;
  }
  v35 = v8->mStateValues.mParamValues[2];
  v36 = v25->mStateValues.mParamValues[2];
  v25->mStateValues.mParamValues[2] = v35;
  if ( v36 == v35 )
    goto LABEL_58;
  v37 = v25->mFreeBucket;
  if ( v37 )
  {
    mNumCommands = v37->mNumCommands;
    if ( (unsigned int)mNumCommands < 0x7E )
    {
      v39 = (__int64)&v37->mCommands[mNumCommands];
      v37->mNumCommands = mNumCommands + 1;
      goto LABEL_56;
    }
    v25->mCommandCount += v37->mNumCommands;
    v25->mFreeBucket = 0i64;
  }
  v40 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v41 = v40;
  if ( v40 )
  {
    *(_QWORD *)v40 = v40;
    *((_QWORD *)v40 + 1) = v40;
    *((_QWORD *)v40 + 2) = 0i64;
    *((_DWORD *)v40 + 6) = 0;
    v42 = v25->mBuckets.mNode.mPrev;
    v42->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v41;
    *(_QWORD *)v41 = v42;
    *((_QWORD *)v41 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v41;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v41;
  }
  v43 = v25->mFreeBucket;
  if ( v43 )
  {
    v43->mNumCommands = 1;
    v39 = (__int64)v25->mFreeBucket->mCommands;
LABEL_56:
    if ( v39 )
    {
      *(_DWORD *)v39 = 131075;
      *(_QWORD *)(v39 + 8) = v35;
    }
  }
LABEL_58:
  v44 = v8->mStateValues.mParamValues[3];
  v45 = v25->mStateValues.mParamValues[3];
  v25->mStateValues.mParamValues[3] = v44;
  if ( v45 != v44 )
  {
    v46 = v25->mFreeBucket;
    if ( v46 )
    {
      v47 = v46->mNumCommands;
      if ( (unsigned int)v47 < 0x7E )
      {
        v48 = (__int64)&v46->mCommands[v47];
        v46->mNumCommands = v47 + 1;
LABEL_67:
        if ( v48 )
        {
          *(_DWORD *)v48 = 196612;
          *(_QWORD *)(v48 + 8) = v44;
        }
        goto LABEL_69;
      }
      v25->mCommandCount += v46->mNumCommands;
      v25->mFreeBucket = 0i64;
    }
    v49 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v50 = v49;
    if ( v49 )
    {
      *(_QWORD *)v49 = v49;
      *((_QWORD *)v49 + 1) = v49;
      *((_QWORD *)v49 + 2) = 0i64;
      *((_DWORD *)v49 + 6) = 0;
      v51 = v25->mBuckets.mNode.mPrev;
      v51->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v50;
      *(_QWORD *)v50 = v51;
      *((_QWORD *)v50 + 1) = &v25->mBuckets;
      v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v50;
      v25->mFreeBucket = (Illusion::QueueCommandBucket *)v50;
    }
    v52 = v25->mFreeBucket;
    if ( !v52 )
      goto LABEL_69;
    v52->mNumCommands = 1;
    v48 = (__int64)v25->mFreeBucket->mCommands;
    goto LABEL_67;
  }
LABEL_69:
  for ( i = 0; i < 4; ++i )
  {
    v54 = v8->mStateValues.mParamValues[(int)i + 4];
    v55 = (__int16)(i + 4);
    v56 = v25->mStateValues.mParamValues[v55];
    v25->mStateValues.mParamValues[v55] = v54;
    if ( v56 == v54 )
      continue;
    v57 = v25->mFreeBucket;
    if ( v57 )
    {
      v58 = v57->mNumCommands;
      if ( (unsigned int)v58 < 0x7E )
      {
        v59 = (__int64)&v57->mCommands[v58];
        v57->mNumCommands = v58 + 1;
        goto LABEL_79;
      }
      v25->mCommandCount += v57->mNumCommands;
      v25->mFreeBucket = 0i64;
    }
    v60 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v61 = v60;
    if ( v60 )
    {
      *(_QWORD *)v60 = v60;
      *((_QWORD *)v60 + 1) = v60;
      *((_QWORD *)v60 + 2) = 0i64;
      *((_DWORD *)v60 + 6) = 0;
      v62 = v25->mBuckets.mNode.mPrev;
      v62->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v61;
      *(_QWORD *)v61 = v62;
      *((_QWORD *)v61 + 1) = &v25->mBuckets;
      v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v61;
      v25->mFreeBucket = (Illusion::QueueCommandBucket *)v61;
    }
    v63 = v25->mFreeBucket;
    if ( v63 )
    {
      v63->mNumCommands = 1;
      v59 = (__int64)v25->mFreeBucket->mCommands;
LABEL_79:
      if ( v59 )
      {
        *(_WORD *)v59 = 5;
        *(_WORD *)(v59 + 2) = i;
        *(_QWORD *)(v59 + 8) = v54;
      }
      continue;
    }
  }
  v64 = v8->mStateValues.mParamValues[8];
  v65 = v25->mStateValues.mParamValues[8];
  v25->mStateValues.mParamValues[8] = v64;
  if ( v65 == v64 )
    goto LABEL_93;
  v66 = v25->mFreeBucket;
  if ( v66 )
  {
    v67 = v66->mNumCommands;
    if ( (unsigned int)v67 < 0x7E )
    {
      v68 = (__int64)&v66->mCommands[v67];
      v66->mNumCommands = v67 + 1;
LABEL_91:
      if ( v68 )
      {
        *(_DWORD *)v68 = 524294;
        *(_QWORD *)(v68 + 8) = v64;
      }
      goto LABEL_93;
    }
    v25->mCommandCount += v66->mNumCommands;
    v25->mFreeBucket = 0i64;
  }
  v69 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v70 = v69;
  if ( v69 )
  {
    *(_QWORD *)v69 = v69;
    *((_QWORD *)v69 + 1) = v69;
    *((_QWORD *)v69 + 2) = 0i64;
    *((_DWORD *)v69 + 6) = 0;
    v71 = v25->mBuckets.mNode.mPrev;
    v71->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v70;
    *(_QWORD *)v70 = v71;
    *((_QWORD *)v70 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v70;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v70;
  }
  v72 = v25->mFreeBucket;
  if ( v72 )
  {
    v72->mNumCommands = 1;
    v68 = (__int64)v25->mFreeBucket->mCommands;
    goto LABEL_91;
  }
LABEL_93:
  v73 = v8->mStateValues.mParamValues[9];
  v74 = v25->mStateValues.mParamValues[9];
  v25->mStateValues.mParamValues[9] = v73;
  if ( v74 == v73 )
    goto LABEL_104;
  v75 = v25->mFreeBucket;
  if ( v75 )
  {
    v76 = v75->mNumCommands;
    if ( (unsigned int)v76 < 0x7E )
    {
      v77 = (__int64)&v75->mCommands[v76];
      v75->mNumCommands = v76 + 1;
LABEL_102:
      if ( v77 )
      {
        *(_DWORD *)v77 = 589831;
        *(_QWORD *)(v77 + 8) = v73;
      }
      goto LABEL_104;
    }
    v25->mCommandCount += v75->mNumCommands;
    v25->mFreeBucket = 0i64;
  }
  v78 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v79 = v78;
  if ( v78 )
  {
    *(_QWORD *)v78 = v78;
    *((_QWORD *)v78 + 1) = v78;
    *((_QWORD *)v78 + 2) = 0i64;
    *((_DWORD *)v78 + 6) = 0;
    v80 = v25->mBuckets.mNode.mPrev;
    v80->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v79;
    *(_QWORD *)v79 = v80;
    *((_QWORD *)v79 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v79;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v79;
  }
  v81 = v25->mFreeBucket;
  if ( v81 )
  {
    v81->mNumCommands = 1;
    v77 = (__int64)v25->mFreeBucket->mCommands;
    goto LABEL_102;
  }
LABEL_104:
  v82 = v8->mStateValues.mParamValues[10];
  v83 = v25->mStateValues.mParamValues[10];
  v25->mStateValues.mParamValues[10] = v82;
  if ( v83 == v82 )
    goto LABEL_115;
  v84 = v25->mFreeBucket;
  if ( v84 )
  {
    v85 = v84->mNumCommands;
    if ( (unsigned int)v85 < 0x7E )
    {
      v86 = (__int64)&v84->mCommands[v85];
      v84->mNumCommands = v85 + 1;
LABEL_113:
      if ( v86 )
      {
        *(_DWORD *)v86 = 655368;
        *(_QWORD *)(v86 + 8) = v82;
      }
      goto LABEL_115;
    }
    v25->mCommandCount += v84->mNumCommands;
    v25->mFreeBucket = 0i64;
  }
  v87 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v88 = v87;
  if ( v87 )
  {
    *(_QWORD *)v87 = v87;
    *((_QWORD *)v87 + 1) = v87;
    *((_QWORD *)v87 + 2) = 0i64;
    *((_DWORD *)v87 + 6) = 0;
    v89 = v25->mBuckets.mNode.mPrev;
    v89->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v88;
    *(_QWORD *)v88 = v89;
    *((_QWORD *)v88 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v88;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v88;
  }
  v90 = v25->mFreeBucket;
  if ( v90 )
  {
    v90->mNumCommands = 1;
    v86 = (__int64)v25->mFreeBucket->mCommands;
    goto LABEL_113;
  }
LABEL_115:
  v91 = (__int64)v133;
  v92 = v133[11];
  if ( v92 )
  {
    while ( 2 )
    {
      v93 = v92 & -v92;
      v94 = !_BitScanReverse64((unsigned __int64 *)&v95, v93);
      if ( v94 )
        v96 = 0;
      else
        v96 = 63 - v95;
      v97 = 63 - v96;
      v98 = v8->mStateValues.mParamValues[63 - v96];
      v99 = (__int16)(63 - v96);
      v100 = v25->mStateValues.mParamValues[v99];
      v25->mStateValues.mParamValues[v99] = v98;
      if ( v100 == v98 )
        goto LABEL_130;
      v101 = v25->mFreeBucket;
      if ( v101 )
      {
        v102 = v101->mNumCommands;
        if ( (unsigned int)v102 < 0x7E )
        {
          v103 = (__int64)&v101->mCommands[v102];
          v101->mNumCommands = v102 + 1;
LABEL_128:
          if ( v103 )
          {
            *(_WORD *)v103 = 2;
            *(_WORD *)(v103 + 2) = v97;
            *(_QWORD *)(v103 + 8) = v98;
          }
          goto LABEL_130;
        }
        v25->mCommandCount += v101->mNumCommands;
        v25->mFreeBucket = 0i64;
      }
      v104 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
      v105 = v104;
      if ( v104 )
      {
        *(_QWORD *)v104 = v104;
        *((_QWORD *)v104 + 1) = v104;
        *((_QWORD *)v104 + 2) = 0i64;
        *((_DWORD *)v104 + 6) = 0;
        v106 = v25->mBuckets.mNode.mPrev;
        v106->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v105;
        *(_QWORD *)v105 = v106;
        *((_QWORD *)v105 + 1) = &v25->mBuckets;
        v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v105;
        v25->mFreeBucket = (Illusion::QueueCommandBucket *)v105;
      }
      v107 = v25->mFreeBucket;
      if ( v107 )
      {
        v107->mNumCommands = 1;
        v103 = (__int64)v25->mFreeBucket->mCommands;
        goto LABEL_128;
      }
LABEL_130:
      v92 ^= v93;
      if ( !v92 )
      {
        v91 = (__int64)v133;
        v23 = force_index_buffera;
        break;
      }
      continue;
    }
  }
  v108 = *(_QWORD *)(v91 + 96);
  if ( !v108 )
    goto LABEL_149;
  while ( 2 )
  {
    v109 = v108 & -v108;
    v94 = !_BitScanReverse64((unsigned __int64 *)&v110, v109);
    if ( v94 )
      v111 = 0;
    else
      v111 = 63 - v110;
    v112 = 127 - v111;
    v113 = v8->mStateValues.mParamValues[127 - v111];
    v114 = (__int16)(127 - v111);
    v115 = v25->mStateValues.mParamValues[v114];
    v25->mStateValues.mParamValues[v114] = v113;
    if ( v115 == v113 )
      goto LABEL_147;
    v116 = v25->mFreeBucket;
    if ( v116 )
    {
      v117 = v116->mNumCommands;
      if ( (unsigned int)v117 < 0x7E )
      {
        v118 = (__int64)&v116->mCommands[v117];
        v116->mNumCommands = v117 + 1;
LABEL_145:
        if ( v118 )
        {
          *(_WORD *)v118 = 2;
          *(_WORD *)(v118 + 2) = v112;
          *(_QWORD *)(v118 + 8) = v113;
        }
        goto LABEL_147;
      }
      v25->mCommandCount += v116->mNumCommands;
      v25->mFreeBucket = 0i64;
    }
    v119 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
    v120 = v119;
    if ( v119 )
    {
      *(_QWORD *)v119 = v119;
      *((_QWORD *)v119 + 1) = v119;
      *((_QWORD *)v119 + 2) = 0i64;
      *((_DWORD *)v119 + 6) = 0;
      v121 = v25->mBuckets.mNode.mPrev;
      v121->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v120;
      *(_QWORD *)v120 = v121;
      *((_QWORD *)v120 + 1) = &v25->mBuckets;
      v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v120;
      v25->mFreeBucket = (Illusion::QueueCommandBucket *)v120;
    }
    v122 = v25->mFreeBucket;
    if ( v122 )
    {
      v122->mNumCommands = 1;
      v118 = (__int64)v25->mFreeBucket->mCommands;
      goto LABEL_145;
    }
LABEL_147:
    v108 ^= v109;
    if ( v108 )
      continue;
    break;
  }
  v91 = (__int64)v133;
  v23 = force_index_buffera;
LABEL_149:
  v25->mStateValues.mSetValueMask.mFlags[0] |= *(_QWORD *)(v91 + 88);
  v25->mStateValues.mSetValueMask.mFlags[1] |= *(_QWORD *)(v91 + 96);
  v123 = v25->mFreeBucket;
  if ( v123 )
  {
    v124 = v123->mNumCommands;
    if ( (unsigned int)v124 < 0x7E )
    {
      v123->mNumCommands = v124 + 1;
      v125 = (__int64)&v123->mCommands[v124];
LABEL_157:
      if ( v125 )
      {
        *(_DWORD *)v125 = 13;
        *(_QWORD *)(v125 + 8) = v23;
      }
      goto LABEL_159;
    }
    v25->mCommandCount += v123->mNumCommands;
    v25->mFreeBucket = 0i64;
  }
  v126 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v127 = v126;
  if ( v126 )
  {
    *(_QWORD *)v126 = v126;
    *((_QWORD *)v126 + 1) = v126;
    *((_QWORD *)v126 + 2) = 0i64;
    *((_DWORD *)v126 + 6) = 0;
    v128 = v25->mBuckets.mNode.mPrev;
    v128->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v127;
    *(_QWORD *)v127 = v128;
    *((_QWORD *)v127 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v127;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v127;
  }
  v129 = v25->mFreeBucket;
  if ( v129 )
  {
    v129->mNumCommands = 1;
    v125 = (__int64)v25->mFreeBucket->mCommands;
    goto LABEL_157;
  }
LABEL_159:
  v8->vfptr->OnPostSubmit(v8, v25);
}ory, 0x800u, 0x10u);
  v127 = v126;
  if ( v126 )
  {
    *(_QWORD *)v126 = v126;
    *((_QWORD *)v126 + 1) = v126;
    *((_QWORD *)v126 + 2) = 0i64;
    *((_DWORD *)v126 + 6) = 0;
    v128 = v25->mBuckets.mNode.mPrev;
    v128->mNext = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v127;
    *(_QWORD *)v127 = v128;
    *((_QWORD *)v127 + 1) = &v25->mBuckets;
    v25->mBuckets.mNode.mPrev = (UFG::qNode<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket> *)v127;
    v25->mFreeBucket = (Illusion::QueueCommandBucket *)v127;
  }
  v129 = v25->mFreeBucket;
  if ( v129 )
  {
    v129->mNumCommands = 1;
    v125 = (__int64

// File Line: 360
// RVA: 0x92C90
bool __fastcall Illusion::SubmitContext::LoadShader(
        Illusion::SubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream)
{
  void *v2; // rax

  v2 = this->mStateValues.mParamValues[1];
  if ( v2 )
  {
    shader_stream->mMainMemoryAddress = v2;
    LOBYTE(v2) = 1;
  }
  return (char)v2;
}

// File Line: 381
// RVA: 0x8E480
void __fastcall Illusion::SubmitContext::ApplyShaderTemplate(
        Illusion::SubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream)
{
  Illusion::ShaderSelector *mShaderSelector; // r8
  Illusion::Shader *v5; // rbp
  Illusion::ShaderTemplate *v6; // rcx
  Illusion::Shader *v7; // rax

  mShaderSelector = this->mShaderSelector;
  if ( mShaderSelector )
  {
    v5 = (Illusion::Shader *)this->mStateValues.mParamValues[1];
    v6 = *(Illusion::ShaderTemplate **)((char *)&v5->mShaderParam[18]
                                      + *((_QWORD *)shader_stream->mMainMemoryAddress + 13));
    if ( v6 )
    {
      v7 = Illusion::ShaderTemplate::SelectShader(v6, &this->mStateValues, mShaderSelector);
      if ( v7 != v5 )
      {
        this->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
        this->mStateValues.mParamValues[1] = v7;
        if ( v7 )
          shader_stream->mMainMemoryAddress = v7;
      }
    }
  }
}

// File Line: 413
// RVA: 0x8E500
void __fastcall Illusion::SubmitContext::ApplyStateArgs(
        Illusion::SubmitContext *this,
        UFG::qMemoryStream<Illusion::Shader,1160> *shader_stream,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  _QWORD *mMainMemoryAddress; // rdx
  unsigned __int64 v5; // r14
  unsigned __int64 v6; // r15
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rbp
  bool v9; // zf
  __int64 v10; // rax
  int v11; // ecx
  __int64 v12; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rbx
  char v14; // al
  UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *i; // rsi
  UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *v16; // rsi
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *j; // rbx
  unsigned __int64 v18; // rbp
  __int64 v19; // rax
  int v20; // ecx
  __int64 v21; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rbx
  char v23; // cl
  UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *k; // rsi
  UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *v25; // rsi
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *m; // rbx

  mMainMemoryAddress = shader_stream->mMainMemoryAddress;
  v5 = (mMainMemoryAddress[11] | 0x1FFFi64) & this->mStateArgs.mStateArgsCreateMask.mFlags[0] & ~already_called_funcs_mask->mFlags[0];
  v6 = mMainMemoryAddress[12] & this->mStateArgs.mStateArgsCreateMask.mFlags[1] & ~already_called_funcs_mask->mFlags[1];
  v7 = v6 | already_called_funcs_mask->mFlags[1];
  already_called_funcs_mask->mFlags[0] |= v5;
  for ( already_called_funcs_mask->mFlags[1] = v7; v5; v5 ^= v8 )
  {
    v8 = v5 & -(__int64)v5;
    v9 = !_BitScanReverse64((unsigned __int64 *)&v10, v8);
    if ( v9 )
      v11 = 0;
    else
      v11 = 63 - v10;
    v12 = 63 - v11;
    mNext = this->mStateArgs.mStateArgs[v12].mNode.mNext;
    v14 = BYTE2(mNext[1].mNext);
    if ( (v14 & 8) != 0 )
    {
      for ( i = &this->mStateArgs.mStateArgs[v12];
            mNext != (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)i;
            mNext = mNext->mNext )
      {
        ((void (__fastcall *)(UFG::qNode<Illusion::StateArg,Illusion::StateArg> *, Illusion::StateValues *))mNext[1].mPrev)(
          mNext,
          &this->mStateValues);
      }
    }
    else if ( (v14 & 0x10) != 0 )
    {
      v16 = &this->mStateArgs.mStateArgs[v12];
      for ( j = v16->mNode.mPrev; j != (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)v16; j = j->mPrev )
        ((void (__fastcall *)(UFG::qNode<Illusion::StateArg,Illusion::StateArg> *, Illusion::StateValues *))j[1].mPrev)(
          j,
          &this->mStateValues);
    }
    else
    {
      ((void (__fastcall *)(UFG::qNode<Illusion::StateArg,Illusion::StateArg> *, Illusion::StateValues *))mNext[1].mPrev)(
        this->mStateArgs.mStateArgs[v12].mNode.mNext,
        &this->mStateValues);
    }
  }
  for ( ; v6; v6 ^= v18 )
  {
    v18 = v6 & -(__int64)v6;
    v9 = !_BitScanReverse64((unsigned __int64 *)&v19, v18);
    if ( v9 )
      v20 = 0;
    else
      v20 = 63 - v19;
    v21 = 127 - v20;
    v22 = this->mStateArgs.mStateArgs[v21].mNode.mNext;
    v23 = BYTE2(v22[1].mNext);
    if ( (v23 & 8) != 0 )
    {
      for ( k = &this->mStateArgs.mStateArgs[v21];
            v22 != (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)k;
            v22 = v22->mNext )
      {
        ((void (__fastcall *)(UFG::qNode<Illusion::StateArg,Illusion::StateArg> *, Illusion::StateValues *))v22[1].mPrev)(
          v22,
          &this->mStateValues);
      }
    }
    else if ( (v23 & 0x10) != 0 )
    {
      v25 = &this->mStateArgs.mStateArgs[v21];
      for ( m = v25->mNode.mPrev; m != (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)v25; m = m->mPrev )
        ((void (__fastcall *)(UFG::qNode<Illusion::StateArg,Illusion::StateArg> *, Illusion::StateValues *))m[1].mPrev)(
          m,
          &this->mStateValues);
    }
    else
    {
      ((void (__fastcall *)(UFG::qNode<Illusion::StateArg,Illusion::StateArg> *, Illusion::StateValues *))v22[1].mPrev)(
        v22,
        &this->mStateValues);
    }
  }
}eArg> *, Illusion::Sta

