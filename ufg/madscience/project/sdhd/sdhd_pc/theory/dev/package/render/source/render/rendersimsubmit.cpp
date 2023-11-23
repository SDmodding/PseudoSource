// File Line: 22
// RVA: 0x7D20
void __fastcall SubmitRenderModel(Render::View *view, Illusion::Model *model, UFG::qMatrix44 *local_world)
{
  Illusion::StateArgs *StateArgs; // rsi
  Render::ViewSettings *mSettings; // r14
  unsigned __int16 Param; // ax
  unsigned __int16 v9; // ax
  unsigned int v10; // ebx
  UFG::BitFlags128 v11; // xmm0
  __int64 mOffset; // rcx
  char *v13; // rdx
  __int64 v14; // r9
  char *v15; // rax
  __int64 v16; // rdx
  Illusion::Mesh *v17; // r8
  char *v18; // rax
  char *v19; // rcx
  __int64 v20; // rax
  char *v21; // r9
  void (__fastcall *mCallback)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v23)(Illusion::StateArg *, Illusion::StateValues *); // rax
  unsigned __int64 *v24; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v27; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v28; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v29; // rax
  void (__fastcall *v30)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v31)(Illusion::StateArg *, Illusion::StateValues *); // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v32; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v35; // rax
  Render::cbLocalProjectionState v36; // [rsp+30h] [rbp-71h] BYREF
  UFG::qMatrix44 *v37; // [rsp+68h] [rbp-39h]
  __int64 v38; // [rsp+70h] [rbp-31h]
  Render::cbLocalTransformState arg; // [rsp+78h] [rbp-29h] BYREF
  unsigned __int128 v40; // [rsp+A8h] [rbp+7h] BYREF
  UFG::BitFlags128 v41; // [rsp+B8h] [rbp+17h] BYREF
  __int64 v42; // [rsp+C8h] [rbp+27h]

  v42 = -2i64;
  v40 = 0ui64;
  StateArgs = Render::View::GetStateArgs(view);
  mSettings = view->mSettings;
  Render::cbLocalTransformState::cbLocalTransformState(
    &arg,
    &view->mSettings->mWorldView,
    &view->mWorldViewProjection,
    local_world);
  v36.mPrev = &v36;
  v36.mNext = &v36;
  v36.mCallback = 0i64;
  v36.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = Param;
    v36.mStateParamIndex = Param;
  }
  v36.mNext = 0i64;
  v36.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)local_world;
  v36.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v36.mCallback;
  *(_QWORD *)&v36.mStateParamIndex = &v36.mCallback;
  v36.mWorldViewProjection = 0i64;
  LOWORD(v36.mLocalWorld) = Render::cbLocalTransformInverseState::sStateParamIndex;
  WORD1(v36.mLocalWorld) = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == 0xFFFF )
  {
    v9 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v9;
    LOWORD(v36.mLocalWorld) = v9;
  }
  v38 = 0i64;
  v36.mCached_Remote.m_Stream = mSettings;
  v37 = local_world;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(StateArgs, &arg);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(StateArgs, &v36);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
    StateArgs,
    (Render::cbLocalTransformInverseState *)&v36.mCallback);
  model->mLastUsedFrameNum = Illusion::gEngine.mFrameCount;
  v10 = 0;
  if ( model->mNumMeshes )
  {
    v11 = (UFG::BitFlags128)v40;
    do
    {
      mOffset = model->mMeshOffsetTable.mOffset;
      if ( mOffset )
        v13 = (char *)&model->mMeshOffsetTable + mOffset;
      else
        v13 = 0i64;
      v14 = 8i64 * v10;
      v15 = &v13[v14];
      v16 = *(_QWORD *)&v13[v14];
      v17 = (Illusion::Mesh *)&v15[v16];
      if ( !v16 )
        v17 = 0i64;
      if ( mOffset )
        v18 = (char *)&model->mMeshOffsetTable + mOffset;
      else
        v18 = 0i64;
      v19 = &v18[v14];
      v20 = *(_QWORD *)&v18[v14];
      v21 = &v19[v20];
      if ( !v20 )
        v21 = 0i64;
      v40 = (unsigned __int128)v11;
      Illusion::SubmitContext::Draw(
        view->mSubmitContext,
        &v41,
        v17,
        *((Illusion::Material **)v21 + 2),
        (UFG::BitFlags128 *)&v40,
        v17);
      v11 = v41;
      ++v10;
    }
    while ( v10 < model->mNumMeshes );
  }
  mCallback = v36.mCallback;
  v23 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v36.mStateParamIndex;
  *((_QWORD *)v36.mCallback + 1) = *(_QWORD *)&v36.mStateParamIndex;
  *v23 = mCallback;
  v36.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v36.mCallback;
  *(_QWORD *)&v36.mStateParamIndex = &v36.mCallback;
  BYTE3(v36.mLocalWorld) = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[SLOWORD(v36.mLocalWorld)].mNode.mNext == &StateArgs->mStateArgs[SLOWORD(v36.mLocalWorld)] )
  {
    v24 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v36.mLocalWorld) >> 6];
    *v24 &= ~(1i64 << ((__int64)v36.mLocalWorld & 0x3F));
  }
  mPrev = v36.mPrev;
  mNext = v36.mNext;
  v36.mPrev->mNext = v36.mNext;
  mNext->mPrev = mPrev;
  v36.mPrev = &v36;
  v36.mNext = &v36;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v36.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v36.mStateParamIndex] )
  {
    v27 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v36.mStateParamIndex >> 6];
    *v27 &= ~(1i64 << (v36.mStateParamIndex & 0x3F));
  }
  v28 = arg.mPrev;
  v29 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v29->mPrev = v28;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
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
UFG::BitFlags128 *__fastcall SubmitSkinnedMesh(
        UFG::BitFlags128 *result,
        Render::View *view,
        Illusion::Mesh *mesh,
        UFG::qMatrix44 *local_world)
{
  Illusion::StateArgs *StateArgs; // rbx
  Render::ViewSettings *mSettings; // r15
  unsigned __int16 Param; // ax
  unsigned __int16 v11; // ax
  void (__fastcall *mCallback)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v13)(Illusion::StateArg *, Illusion::StateValues *); // rax
  unsigned __int64 *v14; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v17; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  void (__fastcall *v20)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v21)(Illusion::StateArg *, Illusion::StateValues *); // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rax
  Render::cbLocalProjectionState v27; // [rsp+30h] [rbp-79h] BYREF
  UFG::qMatrix44 *v28; // [rsp+68h] [rbp-41h]
  __int64 v29; // [rsp+70h] [rbp-39h]
  Render::cbLocalTransformState arg; // [rsp+78h] [rbp-31h] BYREF
  UFG::BitFlags128 v31; // [rsp+A8h] [rbp-1h] BYREF
  __int64 v32; // [rsp+B8h] [rbp+Fh]
  Illusion::Material *retaddr; // [rsp+118h] [rbp+6Fh]
  UFG::BitFlags128 *v34; // [rsp+120h] [rbp+77h]

  v32 = -2i64;
  StateArgs = Render::View::GetStateArgs(view);
  mSettings = view->mSettings;
  Render::cbLocalTransformState::cbLocalTransformState(
    &arg,
    &view->mSettings->mWorldView,
    &view->mWorldViewProjection,
    local_world);
  v27.mPrev = &v27;
  v27.mNext = &v27;
  v27.mCallback = 0i64;
  v27.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  *(_WORD *)&v27.mFlags = 1;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = Param;
    v27.mStateParamIndex = Param;
  }
  v27.mNext = 0i64;
  v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)local_world;
  v27.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v27.mCallback;
  *(_QWORD *)&v27.mStateParamIndex = &v27.mCallback;
  v27.mWorldViewProjection = 0i64;
  LOWORD(v27.mLocalWorld) = Render::cbLocalTransformInverseState::sStateParamIndex;
  WORD1(v27.mLocalWorld) = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == 0xFFFF )
  {
    v11 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v11;
    LOWORD(v27.mLocalWorld) = v11;
  }
  v29 = 0i64;
  v27.mCached_Remote.m_Stream = mSettings;
  v28 = local_world;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(StateArgs, &arg);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(StateArgs, &v27);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
    StateArgs,
    (Render::cbLocalTransformInverseState *)&v27.mCallback);
  v31 = *v34;
  Illusion::SubmitContext::Draw(view->mSubmitContext, result, mesh, retaddr, &v31, mesh);
  mCallback = v27.mCallback;
  v13 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v27.mStateParamIndex;
  *((_QWORD *)v27.mCallback + 1) = *(_QWORD *)&v27.mStateParamIndex;
  *v13 = mCallback;
  v27.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v27.mCallback;
  *(_QWORD *)&v27.mStateParamIndex = &v27.mCallback;
  BYTE3(v27.mLocalWorld) = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[SLOWORD(v27.mLocalWorld)].mNode.mNext == &StateArgs->mStateArgs[SLOWORD(v27.mLocalWorld)] )
  {
    v14 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v27.mLocalWorld) >> 6];
    *v14 &= ~(1i64 << ((__int64)v27.mLocalWorld & 0x3F));
  }
  mPrev = v27.mPrev;
  mNext = v27.mNext;
  v27.mPrev->mNext = v27.mNext;
  mNext->mPrev = mPrev;
  v27.mPrev = &v27;
  v27.mNext = &v27;
  v27.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v27.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v27.mStateParamIndex] )
  {
    v17 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v27.mStateParamIndex >> 6];
    *v17 &= ~(1i64 << (v27.mStateParamIndex & 0x3F));
  }
  v18 = arg.mPrev;
  v19 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v19->mPrev = v18;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
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
  return result;
}

// File Line: 78
// RVA: 0x83A0
UFG::BitFlags128 *__fastcall SubmitSkinnedRMesh(
        UFG::BitFlags128 *result,
        Render::View *view,
        Illusion::rMesh *rmesh,
        UFG::qMatrix44 *local_world)
{
  Illusion::StateArgs *StateArgs; // rbx
  Render::ViewSettings *mSettings; // r15
  unsigned __int16 Param; // ax
  unsigned __int16 v11; // ax
  void (__fastcall *mCallback)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v13)(Illusion::StateArg *, Illusion::StateValues *); // rax
  unsigned __int64 *v14; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v17; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  void (__fastcall *v20)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v21)(Illusion::StateArg *, Illusion::StateValues *); // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rax
  Render::cbLocalProjectionState v27; // [rsp+30h] [rbp-79h] BYREF
  UFG::qMatrix44 *v28; // [rsp+68h] [rbp-41h]
  __int64 v29; // [rsp+70h] [rbp-39h]
  Render::cbLocalTransformState arg; // [rsp+78h] [rbp-31h] BYREF
  UFG::BitFlags128 v31; // [rsp+A8h] [rbp-1h] BYREF
  __int64 v32; // [rsp+B8h] [rbp+Fh]
  Illusion::rMaterial *retaddr; // [rsp+118h] [rbp+6Fh]
  UFG::BitFlags128 *v34; // [rsp+120h] [rbp+77h]

  v32 = -2i64;
  StateArgs = Render::View::GetStateArgs(view);
  mSettings = view->mSettings;
  Render::cbLocalTransformState::cbLocalTransformState(
    &arg,
    &view->mSettings->mWorldView,
    &view->mWorldViewProjection,
    local_world);
  v27.mPrev = &v27;
  v27.mNext = &v27;
  v27.mCallback = 0i64;
  v27.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  *(_WORD *)&v27.mFlags = 1;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = Param;
    v27.mStateParamIndex = Param;
  }
  v27.mNext = 0i64;
  v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)local_world;
  v27.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v27.mCallback;
  *(_QWORD *)&v27.mStateParamIndex = &v27.mCallback;
  v27.mWorldViewProjection = 0i64;
  LOWORD(v27.mLocalWorld) = Render::cbLocalTransformInverseState::sStateParamIndex;
  WORD1(v27.mLocalWorld) = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == 0xFFFF )
  {
    v11 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v11;
    LOWORD(v27.mLocalWorld) = v11;
  }
  v29 = 0i64;
  v27.mCached_Remote.m_Stream = mSettings;
  v28 = local_world;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(StateArgs, &arg);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(StateArgs, &v27);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
    StateArgs,
    (Render::cbLocalTransformInverseState *)&v27.mCallback);
  v31 = *v34;
  Illusion::SubmitContext::Draw(view->mSubmitContext, result, rmesh, retaddr, &v31, rmesh);
  mCallback = v27.mCallback;
  v13 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v27.mStateParamIndex;
  *((_QWORD *)v27.mCallback + 1) = *(_QWORD *)&v27.mStateParamIndex;
  *v13 = mCallback;
  v27.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v27.mCallback;
  *(_QWORD *)&v27.mStateParamIndex = &v27.mCallback;
  BYTE3(v27.mLocalWorld) = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[SLOWORD(v27.mLocalWorld)].mNode.mNext == &StateArgs->mStateArgs[SLOWORD(v27.mLocalWorld)] )
  {
    v14 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v27.mLocalWorld) >> 6];
    *v14 &= ~(1i64 << ((__int64)v27.mLocalWorld & 0x3F));
  }
  mPrev = v27.mPrev;
  mNext = v27.mNext;
  v27.mPrev->mNext = v27.mNext;
  mNext->mPrev = mPrev;
  v27.mPrev = &v27;
  v27.mNext = &v27;
  v27.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v27.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v27.mStateParamIndex] )
  {
    v17 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v27.mStateParamIndex >> 6];
    *v17 &= ~(1i64 << (v27.mStateParamIndex & 0x3F));
  }
  v18 = arg.mPrev;
  v19 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v19->mPrev = v18;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
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
  return result;
}

