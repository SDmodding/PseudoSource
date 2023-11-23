// File Line: 20
// RVA: 0x14574F0
__int64 dynamic_initializer_for__gTaskFunctionDecl_CloudSortTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(&gTaskFunctionDecl_CloudSortTask, &gTaskFunctionDeclData_CloudSortTask);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTaskFunctionDecl_CloudSortTask__);
}

// File Line: 34
// RVA: 0x7ABB0
bool __fastcall IndexCompare(IndexBlock *a, IndexBlock *b)
{
  return gCurrentInstanceBuffer[(unsigned __int64)b->vrt[0] >> 2].mPosition.w < gCurrentInstanceBuffer[(unsigned __int64)a->vrt[0] >> 2].mPosition.w;
}

// File Line: 51
// RVA: 0x7A060
void __fastcall CloudSortTask(int workerId, UFG::qMemoryStreamer *memory_streamer, char *params_Remote, void *pad0)
{
  __int64 v5; // rbx
  Illusion::StateArgs *v6; // r14
  unsigned __int16 Param; // ax
  unsigned __int16 v8; // ax
  void *v9; // r8
  unsigned int v10; // edx
  char v11; // cl
  Illusion::Mesh *v12; // r12
  unsigned int i; // r15d
  __int64 v14; // rdi
  Render::CloudWispAttribute *v15; // rdx
  float v16; // xmm5_4
  float v17; // xmm6_4
  float v18; // xmm4_4
  unsigned int j; // ecx
  float *p_x; // rax
  IndexBlock *v21; // rcx
  unsigned __int16 v22; // r9
  __int16 v23; // r8
  __int64 v24; // rdx
  char *v25; // r13
  float v26; // xmm2_4
  float v27; // xmm6_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  unsigned int v30; // edx
  char v31; // cl
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v35; // rax
  __int64 v36; // rcx
  UFG::qMatrix44 *mWorldView; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v40; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v41; // rax
  __int64 v42; // rcx
  UFG::qMatrix44 *v43; // rax
  Render::cbExternalViewTransformState arg; // [rsp+40h] [rbp-98h] BYREF
  UFG::qMatrix44 *p_result; // [rsp+78h] [rbp-60h]
  UFG::qMatrix44 *p_d; // [rsp+80h] [rbp-58h]
  char *v47; // [rsp+88h] [rbp-50h]
  char *v48; // [rsp+90h] [rbp-48h]
  __int64 v49; // [rsp+98h] [rbp-40h]
  Render::cbLocalTransformState v50; // [rsp+A8h] [rbp-30h] BYREF
  __int64 v51; // [rsp+D0h] [rbp-8h]
  UFG::qMatrix44 result; // [rsp+D8h] [rbp+0h] BYREF
  UFG::qMatrix44 d; // [rsp+118h] [rbp+40h] BYREF
  SimpleTaskSubmitContext dest; // [rsp+158h] [rbp+80h] BYREF
  Illusion::StateArgs *p_mStateArgs; // [rsp+E18h] [rbp+D40h]

  v51 = -2i64;
  v5 = *((_QWORD *)params_Remote + 18);
  if ( *((_DWORD *)params_Remote + 35) )
  {
    v6 = (Illusion::StateArgs *)*((_QWORD *)params_Remote + 23);
    p_mStateArgs = v6;
    SimpleTaskSubmitContext::SimpleTaskSubmitContext(&dest);
    dest.mRenderQueueProvider = (RenderQueueLayer *)*((_QWORD *)params_Remote + 25);
    UFG::qMemSet(dest.mStateValues.mParamValues, 0, 0x400u);
    dest.mStateValues.mSetValueMask.mFlags[1] = 0i64;
    dest.mStateValues.mSetValueMask.mFlags[0] = 0i64;
    UFG::qInverseAffine(&d, (UFG::qMatrix44 *)params_Remote);
    UFG::qMatrix44::operator*((UFG::qMatrix44 *)params_Remote, &result, (UFG::qMatrix44 *)params_Remote + 1);
    *(_QWORD *)&arg.mStateParamIndex = &arg.mStateParamIndex;
    arg.mWorldView = (UFG::qMatrix44 *)&arg.mStateParamIndex;
    arg.mProjection = 0i64;
    LOWORD(arg.mCached_Remote.m_Stream) = Render::cbViewTransformState::sStateParamIndex;
    WORD1(arg.mCached_Remote.m_Stream) = 1;
    if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
      Render::cbViewTransformState::sStateParamIndex = Param;
      LOWORD(arg.mCached_Remote.m_Stream) = Param;
    }
    p_result = &result;
    p_d = &d;
    v47 = params_Remote + 64;
    v48 = params_Remote + 224;
    v49 = 0i64;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
    {
      v8 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
      Render::cbExternalViewTransformState::sStateParamIndex = v8;
      arg.mStateParamIndex = v8;
    }
    arg.mWorldView = (UFG::qMatrix44 *)params_Remote;
    arg.mProjection = (UFG::qMatrix44 *)(params_Remote + 64);
    arg.mCached_Remote.m_Stream = 0i64;
    Illusion::StateArgs::Set<Render::cbViewTransformState>(
      &dest.mStateArgs,
      (Render::cbViewTransformState *)&arg.mStateParamIndex);
    Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(&dest.mStateArgs, &arg);
    v9 = (void *)*((_QWORD *)params_Remote + 20);
    v10 = SWORD2(v6->mStateArgsCreateMask.mFlags[0]);
    v11 = WORD2(v6->mStateArgsCreateMask.mFlags[0]);
    if ( v10 >= 0x40 )
      dest.mStateValues.mSetValueMask.mFlags[1] |= 1i64 << (v11 - 64);
    else
      dest.mStateValues.mSetValueMask.mFlags[0] |= 1i64 << v11;
    dest.mStateValues.mParamValues[(__int16)v10] = v9;
    v12 = (Illusion::Mesh *)*((_QWORD *)params_Remote + 26);
    for ( i = 0; i < *((_DWORD *)params_Remote + 35); ++i )
    {
      v14 = v5 + 240i64 * i;
      if ( *(_BYTE *)(v14 + 225) )
      {
        v15 = *(Render::CloudWispAttribute **)(v14 + 192);
        gCurrentInstanceBuffer = v15;
        v16 = (float)((float)((float)(*((float *)params_Remote + 33) * *(float *)(v14 + 80))
                            + (float)(*((float *)params_Remote + 32) * *(float *)(v14 + 64)))
                    + (float)(*((float *)params_Remote + 34) * *(float *)(v14 + 96)))
            + *(float *)(v14 + 112);
        v17 = (float)((float)((float)(*((float *)params_Remote + 32) * *(float *)(v14 + 68))
                            + (float)(*((float *)params_Remote + 33) * *(float *)(v14 + 84)))
                    + (float)(*((float *)params_Remote + 34) * *(float *)(v14 + 100)))
            + *(float *)(v14 + 116);
        v18 = (float)((float)((float)(*((float *)params_Remote + 32) * *(float *)(v14 + 72))
                            + (float)(*((float *)params_Remote + 33) * *(float *)(v14 + 88)))
                    + (float)(*((float *)params_Remote + 34) * *(float *)(v14 + 104)))
            + *(float *)(v14 + 120);
        for ( j = 0; j < *(_DWORD *)(v14 + 128); ++j )
        {
          p_x = &v15[(unsigned __int64)j].mPosition.x;
          p_x[3] = (float)((float)((float)(*p_x - v16) * (float)(*p_x - v16))
                         + (float)((float)(p_x[1] - v17) * (float)(p_x[1] - v17)))
                 + (float)((float)(p_x[2] - v18) * (float)(p_x[2] - v18));
        }
        v21 = *(IndexBlock **)(v14 + 208);
        if ( *(_BYTE *)(v14 + 224) )
        {
          v22 = 0;
          if ( *(_DWORD *)(v14 + 128) )
          {
            v23 = 1;
            do
            {
              v24 = v22;
              v21[v24].vrt[0] = v23 - 1;
              v21[v24].vrt[1] = v23;
              v21[v24].vrt[2] = v23 + 2;
              v21[v24].vrt[3] = v23 + 2;
              v21[v24].vrt[4] = v23;
              v21[v24].vrt[5] = v23 + 1;
              ++v22;
              v23 += 4;
            }
            while ( (unsigned int)v22 < *(_DWORD *)(v14 + 128) );
          }
        }
        UFG::qQuickSortImpl<IndexBlock,bool (*)(IndexBlock const &,IndexBlock const &)>(
          v21,
          &v21[*(int *)(v14 + 128) - 1],
          IndexCompare);
      }
      v25 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
      UFG::qMemSet(v25, 0, 0x20u);
      v26 = (float)((float)((float)(*(float *)(v14 + 144) * *(float *)(v14 + 20))
                          + (float)(*(float *)(v14 + 140) * *(float *)(v14 + 4)))
                  + (float)(*(float *)(v14 + 148) * *(float *)(v14 + 36)))
          + *(float *)(v14 + 52);
      v27 = (float)((float)((float)(*(float *)(v14 + 144) * *(float *)(v14 + 24))
                          + (float)(*(float *)(v14 + 140) * *(float *)(v14 + 8)))
                  + (float)(*(float *)(v14 + 148) * *(float *)(v14 + 40)))
          + *(float *)(v14 + 56);
      *(float *)v25 = (float)((float)((float)(*(float *)(v14 + 144) * *(float *)(v14 + 16))
                                    + (float)(*(float *)(v14 + 140) * *(float *)v14))
                            + (float)(*(float *)(v14 + 148) * *(float *)(v14 + 32)))
                    + *(float *)(v14 + 48);
      *((float *)v25 + 1) = v26;
      *((float *)v25 + 2) = v27;
      *((_DWORD *)v25 + 3) = *(_DWORD *)(v14 + 176);
      v28 = (float)((float)((float)(*(float *)(v14 + 8) * *(float *)(v14 + 152))
                          + (float)(*(float *)(v14 + 24) * *(float *)(v14 + 156)))
                  + (float)(*(float *)(v14 + 40) * *(float *)(v14 + 160)))
          + *(float *)(v14 + 56);
      v29 = (float)((float)((float)(*(float *)(v14 + 8) * *(float *)(v14 + 164))
                          + (float)(*(float *)(v14 + 24) * *(float *)(v14 + 168)))
                  + (float)(*(float *)(v14 + 40) * *(float *)(v14 + 172)))
          + *(float *)(v14 + 56);
      *((_DWORD *)v25 + 4) = *(_DWORD *)(v14 + 136);
      *((_DWORD *)v25 + 5) = *(_DWORD *)(v14 + 132);
      *((float *)v25 + 6) = v28;
      *((float *)v25 + 7) = v29 - v28;
      v30 = SLOWORD(p_mStateArgs->mStateArgsCreateMask.mFlags[0]);
      v31 = p_mStateArgs->mStateArgsCreateMask.mFlags[0];
      if ( v30 >= 0x40 )
        dest.mStateValues.mSetValueMask.mFlags[1] |= 1i64 << (v31 - 64);
      else
        dest.mStateValues.mSetValueMask.mFlags[0] |= 1i64 << v31;
      dest.mStateValues.mParamValues[(__int16)v30] = v25;
      Render::cbLocalTransformState::cbLocalTransformState(
        &v50,
        (UFG::qMatrix44 *)params_Remote,
        &result,
        (UFG::qMatrix44 *)(v5 + 240i64 * i));
      Illusion::StateArgs::Set<Render::cbLocalTransformState>(&dest.mStateArgs, &v50);
      Illusion::SubmitContext::DrawInstanced(
        &dest,
        v12,
        *(Illusion::Buffer **)(v14 + 184),
        *(_DWORD *)(v14 + 128),
        *((Illusion::Material **)params_Remote + 27),
        *(Illusion::Buffer **)(v14 + 200),
        *((void **)params_Remote + 26),
        *(const char **)(v14 + 216));
      mPrev = v50.mPrev;
      mNext = v50.mNext;
      v50.mPrev->mNext = v50.mNext;
      mNext->mPrev = mPrev;
      v50.mPrev = &v50;
      v50.mNext = &v50;
      v50.mIsSet = 0;
      if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)dest.mStateArgs.mStateArgs[v50.mStateParamIndex].mNode.mNext == &dest.mStateArgs.mStateArgs[v50.mStateParamIndex] )
        dest.mStateArgs.mStateArgsCreateMask.mFlags[(unsigned int)v50.mStateParamIndex >> 6] &= ~(1i64 << (v50.mStateParamIndex & 0x3F));
      v34 = v50.mPrev;
      v35 = v50.mNext;
      v50.mPrev->mNext = v50.mNext;
      v35->mPrev = v34;
      v50.mPrev = &v50;
      v50.mNext = &v50;
    }
    v36 = *(_QWORD *)&arg.mStateParamIndex;
    mWorldView = arg.mWorldView;
    *(_QWORD *)(*(_QWORD *)&arg.mStateParamIndex + 8i64) = arg.mWorldView;
    *(_QWORD *)&mWorldView->v0.x = v36;
    *(_QWORD *)&arg.mStateParamIndex = &arg.mStateParamIndex;
    arg.mWorldView = (UFG::qMatrix44 *)&arg.mStateParamIndex;
    BYTE3(arg.mCached_Remote.m_Stream) = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)dest.mStateArgs.mStateArgs[SLOWORD(arg.mCached_Remote.m_Stream)].mNode.mNext == &dest.mStateArgs.mStateArgs[SLOWORD(arg.mCached_Remote.m_Stream)] )
      dest.mStateArgs.mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(arg.mCached_Remote.m_Stream) >> 6] &= ~(1i64 << ((__int64)arg.mCached_Remote.m_Stream & 0x3F));
    v38 = arg.mPrev;
    v39 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v39->mPrev = v38;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)dest.mStateArgs.mStateArgs[arg.mStateParamIndex].mNode.mNext == &dest.mStateArgs.mStateArgs[arg.mStateParamIndex] )
      dest.mStateArgs.mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v40 = arg.mPrev;
    v41 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v41->mPrev = v40;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    v42 = *(_QWORD *)&arg.mStateParamIndex;
    v43 = arg.mWorldView;
    *(_QWORD *)(*(_QWORD *)&arg.mStateParamIndex + 8i64) = arg.mWorldView;
    *(_QWORD *)&v43->v0.x = v42;
    *(_QWORD *)&arg.mStateParamIndex = &arg.mStateParamIndex;
    arg.mWorldView = (UFG::qMatrix44 *)&arg.mStateParamIndex;
    p_mStateArgs = &dest.mStateArgs;
    `eh vector destructor iterator(
      dest.mStateArgs.mStateArgs,
      0x10ui64,
      128,
      (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
  }
}

