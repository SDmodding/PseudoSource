// File Line: 22
// RVA: 0x7D20
void __fastcall SubmitRenderModel(Render::View *view, Illusion::Model *model, UFG::qMatrix44 *local_world)
{
  UFG::qMatrix44 *v3; // rbx
  Illusion::Model *v4; // r15
  Render::View *v5; // r12
  Illusion::StateArgs *v6; // rsi
  UFG::qMatrix44 *v7; // r14
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // ax
  unsigned int v10; // ebx
  __m128i v11; // xmm0
  __int64 v12; // rcx
  signed __int64 v13; // rdx
  signed __int64 v14; // r9
  signed __int64 v15; // rax
  __int64 v16; // rdx
  Illusion::Mesh *v17; // r8
  signed __int64 v18; // rax
  signed __int64 v19; // rcx
  __int64 v20; // rax
  signed __int64 v21; // r9
  void (__fastcall *v22)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v23)(Illusion::StateArg *, Illusion::StateValues *); // rax
  unsigned __int64 *v24; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v26; // rax
  unsigned __int64 *v27; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v28; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v29; // rax
  void (__fastcall *v30)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v31)(Illusion::StateArg *, Illusion::StateValues *); // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v32; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v35; // rax
  Render::cbLocalProjectionState v36; // [rsp+30h] [rbp-71h]
  UFG::qMatrix44 *v37; // [rsp+68h] [rbp-39h]
  __int64 v38; // [rsp+70h] [rbp-31h]
  Render::cbLocalTransformState arg; // [rsp+78h] [rbp-29h]
  __m128i v40; // [rsp+A8h] [rbp+7h]
  __m128i v41; // [rsp+B8h] [rbp+17h]
  __int64 v42; // [rsp+C8h] [rbp+27h]

  v42 = -2i64;
  v3 = local_world;
  v4 = model;
  v5 = view;
  v40 = 0ui64;
  v6 = Render::View::GetStateArgs(view);
  v7 = &v5->mSettings->mWorldView;
  Render::cbLocalTransformState::cbLocalTransformState(&arg, &v5->mSettings->mWorldView, &v5->mWorldViewProjection, v3);
  v36.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v36;
  v36.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v36;
  v36.mCallback = 0i64;
  v36.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
  {
    v8 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = v8;
    v36.mStateParamIndex = v8;
  }
  v36.mNext = 0i64;
  v36.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)v3;
  v36.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v36.mCallback;
  *(_QWORD *)&v36.mStateParamIndex = (char *)&v36 + 16;
  v36.mWorldViewProjection = 0i64;
  LOWORD(v36.mLocalWorld) = Render::cbLocalTransformInverseState::sStateParamIndex;
  WORD1(v36.mLocalWorld) = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == -1 )
  {
    v9 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v9;
    LOWORD(v36.mLocalWorld) = v9;
  }
  v38 = 0i64;
  v36.mCached_Remote.m_Stream = v7;
  v37 = v3;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(v6, &arg);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v6, &v36);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
    v6,
    (Render::cbLocalTransformInverseState *)&v36.mCallback);
  v4->mLastUsedFrameNum = Illusion::gEngine.mFrameCount;
  v10 = 0;
  if ( v4->mNumMeshes > 0 )
  {
    v11 = v40;
    do
    {
      v12 = v4->mMeshOffsetTable.mOffset;
      if ( v12 )
        v13 = (signed __int64)&v4->mMeshOffsetTable + v12;
      else
        v13 = 0i64;
      v14 = 8i64 * v10;
      v15 = v14 + v13;
      v16 = *(_QWORD *)(v14 + v13);
      v17 = (Illusion::Mesh *)(v16 + v15);
      if ( !v16 )
        v17 = 0i64;
      if ( v12 )
        v18 = (signed __int64)&v4->mMeshOffsetTable + v12;
      else
        v18 = 0i64;
      v19 = v14 + v18;
      v20 = *(_QWORD *)(v14 + v18);
      v21 = v20 + v19;
      if ( !v20 )
        v21 = 0i64;
      _mm_store_si128(&v40, v11);
      Illusion::SubmitContext::Draw(
        v5->mSubmitContext,
        (UFG::BitFlags128 *)&v41,
        v17,
        *(Illusion::Material **)(v21 + 16),
        (UFG::BitFlags128 *)&v40,
        v17);
      v11 = v41;
      ++v10;
    }
    while ( v10 < v4->mNumMeshes );
  }
  v22 = v36.mCallback;
  v23 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v36.mStateParamIndex;
  *((_QWORD *)v36.mCallback + 1) = *(_QWORD *)&v36.mStateParamIndex;
  *v23 = v22;
  v36.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v36.mCallback;
  *(_QWORD *)&v36.mStateParamIndex = (char *)&v36 + 16;
  BYTE3(v36.mLocalWorld) = 0;
  if ( (Illusion::StateArgs *)v6->mStateArgsCreateMask.mFlags[2 * (SLOWORD(v36.mLocalWorld) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v6 + 16 * (SLOWORD(v36.mLocalWorld) + 3i64)) )
  {
    v24 = &v6->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v36.mLocalWorld) >> 6];
    *v24 &= ~(1i64 << ((_QWORD)v36.mLocalWorld & 0x3F));
  }
  v25 = v36.mPrev;
  v26 = v36.mNext;
  v36.mPrev->mNext = v36.mNext;
  v26->mPrev = v25;
  v36.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v36;
  v36.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v36;
  if ( (Illusion::StateArgs *)v6->mStateArgsCreateMask.mFlags[2 * (v36.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v6 + 16 * (v36.mStateParamIndex + 3i64)) )
  {
    v27 = &v6->mStateArgsCreateMask.mFlags[(unsigned int)v36.mStateParamIndex >> 6];
    *v27 &= ~(1i64 << (v36.mStateParamIndex & 0x3F));
  }
  v28 = arg.mPrev;
  v29 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v29->mPrev = v28;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v6->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v6 + 16 * (arg.mStateParamIndex + 3i64)) )
    v6->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v30 = v36.mCallback;
  v31 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v36.mStateParamIndex;
  *((_QWORD *)v36.mCallback + 1) = *(_QWORD *)&v36.mStateParamIndex;
  *v31 = v30;
  v32 = v36.mPrev;
  v33 = v36.mNext;
  v36.mPrev->mNext = v36.mNext;
  v33->mPrev = v32;
  v34 = arg.mPrev;
  v35 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v35->mPrev = v34;
}

// File Line: 54
// RVA: 0x80A0
UFG::BitFlags128 *__fastcall SubmitSkinnedMesh(UFG::BitFlags128 *result, Render::View *view, Illusion::Mesh *mesh, UFG::qMatrix44 *local_world)
{
  UFG::qMatrix44 *v4; // rsi
  Illusion::Mesh *v5; // r13
  Render::View *v6; // rdi
  UFG::BitFlags128 *v7; // r12
  Illusion::StateArgs *v8; // rbx
  UFG::qMatrix44 *v9; // r15
  unsigned __int16 v10; // ax
  unsigned __int16 v11; // ax
  void (__fastcall *v12)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v13)(Illusion::StateArg *, Illusion::StateValues *); // rax
  unsigned __int64 *v14; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rax
  unsigned __int64 *v17; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  void (__fastcall *v20)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v21)(Illusion::StateArg *, Illusion::StateValues *); // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rax
  Render::cbLocalProjectionState v27; // [rsp+30h] [rbp-79h]
  UFG::qMatrix44 *v28; // [rsp+68h] [rbp-41h]
  __int64 v29; // [rsp+70h] [rbp-39h]
  Render::cbLocalTransformState arg; // [rsp+78h] [rbp-31h]
  __int128 v31; // [rsp+A8h] [rbp-1h]
  __int64 v32; // [rsp+B8h] [rbp+Fh]
  Illusion::Material *retaddr; // [rsp+118h] [rbp+6Fh]
  __int128 *v34; // [rsp+120h] [rbp+77h]

  v32 = -2i64;
  v4 = local_world;
  v5 = mesh;
  v6 = view;
  v7 = result;
  v8 = Render::View::GetStateArgs(view);
  v9 = &v6->mSettings->mWorldView;
  Render::cbLocalTransformState::cbLocalTransformState(&arg, &v6->mSettings->mWorldView, &v6->mWorldViewProjection, v4);
  v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mCallback = 0i64;
  v27.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  *(_WORD *)&v27.mFlags = 1;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
  {
    v10 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = v10;
    v27.mStateParamIndex = v10;
  }
  v27.mNext = 0i64;
  v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)v4;
  v27.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v27.mCallback;
  *(_QWORD *)&v27.mStateParamIndex = (char *)&v27 + 16;
  v27.mWorldViewProjection = 0i64;
  LOWORD(v27.mLocalWorld) = Render::cbLocalTransformInverseState::sStateParamIndex;
  WORD1(v27.mLocalWorld) = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == -1 )
  {
    v11 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v11;
    LOWORD(v27.mLocalWorld) = v11;
  }
  v29 = 0i64;
  v27.mCached_Remote.m_Stream = v9;
  v28 = v4;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(v8, &arg);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v8, &v27);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
    v8,
    (Render::cbLocalTransformInverseState *)&v27.mCallback);
  v31 = *v34;
  Illusion::SubmitContext::Draw(v6->mSubmitContext, v7, v5, retaddr, (UFG::BitFlags128 *)&v31, v5);
  v12 = v27.mCallback;
  v13 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v27.mStateParamIndex;
  *((_QWORD *)v27.mCallback + 1) = *(_QWORD *)&v27.mStateParamIndex;
  *v13 = v12;
  v27.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v27.mCallback;
  *(_QWORD *)&v27.mStateParamIndex = (char *)&v27 + 16;
  BYTE3(v27.mLocalWorld) = 0;
  if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (SLOWORD(v27.mLocalWorld) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (SLOWORD(v27.mLocalWorld) + 3i64)) )
  {
    v14 = &v8->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v27.mLocalWorld) >> 6];
    *v14 &= ~(1i64 << ((_QWORD)v27.mLocalWorld & 0x3F));
  }
  v15 = v27.mPrev;
  v16 = v27.mNext;
  v27.mPrev->mNext = v27.mNext;
  v16->mPrev = v15;
  v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mIsSet = 0;
  if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (v27.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (v27.mStateParamIndex + 3i64)) )
  {
    v17 = &v8->mStateArgsCreateMask.mFlags[(unsigned int)v27.mStateParamIndex >> 6];
    *v17 &= ~(1i64 << (v27.mStateParamIndex & 0x3F));
  }
  v18 = arg.mPrev;
  v19 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v19->mPrev = v18;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (arg.mStateParamIndex + 3i64)) )
    v8->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v20 = v27.mCallback;
  v21 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v27.mStateParamIndex;
  *((_QWORD *)v27.mCallback + 1) = *(_QWORD *)&v27.mStateParamIndex;
  *v21 = v20;
  v22 = v27.mPrev;
  v23 = v27.mNext;
  v27.mPrev->mNext = v27.mNext;
  v23->mPrev = v22;
  v24 = arg.mPrev;
  v25 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v25->mPrev = v24;
  return v7;
}

// File Line: 78
// RVA: 0x83A0
UFG::BitFlags128 *__fastcall SubmitSkinnedRMesh(UFG::BitFlags128 *result, Render::View *view, Illusion::rMesh *rmesh, UFG::qMatrix44 *local_world)
{
  UFG::qMatrix44 *v4; // rsi
  Illusion::rMesh *v5; // r13
  Render::View *v6; // rdi
  UFG::BitFlags128 *v7; // r12
  Illusion::StateArgs *v8; // rbx
  UFG::qMatrix44 *v9; // r15
  unsigned __int16 v10; // ax
  unsigned __int16 v11; // ax
  void (__fastcall *v12)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v13)(Illusion::StateArg *, Illusion::StateValues *); // rax
  unsigned __int64 *v14; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rax
  unsigned __int64 *v17; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  void (__fastcall *v20)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v21)(Illusion::StateArg *, Illusion::StateValues *); // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rax
  Render::cbLocalProjectionState v27; // [rsp+30h] [rbp-79h]
  UFG::qMatrix44 *v28; // [rsp+68h] [rbp-41h]
  __int64 v29; // [rsp+70h] [rbp-39h]
  Render::cbLocalTransformState arg; // [rsp+78h] [rbp-31h]
  __int128 v31; // [rsp+A8h] [rbp-1h]
  __int64 v32; // [rsp+B8h] [rbp+Fh]
  Illusion::rMaterial *retaddr; // [rsp+118h] [rbp+6Fh]
  __int128 *v34; // [rsp+120h] [rbp+77h]

  v32 = -2i64;
  v4 = local_world;
  v5 = rmesh;
  v6 = view;
  v7 = result;
  v8 = Render::View::GetStateArgs(view);
  v9 = &v6->mSettings->mWorldView;
  Render::cbLocalTransformState::cbLocalTransformState(&arg, &v6->mSettings->mWorldView, &v6->mWorldViewProjection, v4);
  v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mCallback = 0i64;
  v27.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  *(_WORD *)&v27.mFlags = 1;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
  {
    v10 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = v10;
    v27.mStateParamIndex = v10;
  }
  v27.mNext = 0i64;
  v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)v4;
  v27.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v27.mCallback;
  *(_QWORD *)&v27.mStateParamIndex = (char *)&v27 + 16;
  v27.mWorldViewProjection = 0i64;
  LOWORD(v27.mLocalWorld) = Render::cbLocalTransformInverseState::sStateParamIndex;
  WORD1(v27.mLocalWorld) = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == -1 )
  {
    v11 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v11;
    LOWORD(v27.mLocalWorld) = v11;
  }
  v29 = 0i64;
  v27.mCached_Remote.m_Stream = v9;
  v28 = v4;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(v8, &arg);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v8, &v27);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
    v8,
    (Render::cbLocalTransformInverseState *)&v27.mCallback);
  v31 = *v34;
  Illusion::SubmitContext::Draw(v6->mSubmitContext, v7, v5, retaddr, (UFG::BitFlags128 *)&v31, v5);
  v12 = v27.mCallback;
  v13 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v27.mStateParamIndex;
  *((_QWORD *)v27.mCallback + 1) = *(_QWORD *)&v27.mStateParamIndex;
  *v13 = v12;
  v27.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v27.mCallback;
  *(_QWORD *)&v27.mStateParamIndex = (char *)&v27 + 16;
  BYTE3(v27.mLocalWorld) = 0;
  if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (SLOWORD(v27.mLocalWorld) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (SLOWORD(v27.mLocalWorld) + 3i64)) )
  {
    v14 = &v8->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v27.mLocalWorld) >> 6];
    *v14 &= ~(1i64 << ((_QWORD)v27.mLocalWorld & 0x3F));
  }
  v15 = v27.mPrev;
  v16 = v27.mNext;
  v27.mPrev->mNext = v27.mNext;
  v16->mPrev = v15;
  v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mIsSet = 0;
  if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (v27.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (v27.mStateParamIndex + 3i64)) )
  {
    v17 = &v8->mStateArgsCreateMask.mFlags[(unsigned int)v27.mStateParamIndex >> 6];
    *v17 &= ~(1i64 << (v27.mStateParamIndex & 0x3F));
  }
  v18 = arg.mPrev;
  v19 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v19->mPrev = v18;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (arg.mStateParamIndex + 3i64)) )
    v8->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v20 = v27.mCallback;
  v21 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v27.mStateParamIndex;
  *((_QWORD *)v27.mCallback + 1) = *(_QWORD *)&v27.mStateParamIndex;
  *v21 = v20;
  v22 = v27.mPrev;
  v23 = v27.mNext;
  v27.mPrev->mNext = v27.mNext;
  v23->mPrev = v22;
  v24 = arg.mPrev;
  v25 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v25->mPrev = v24;
  return v7;
}

