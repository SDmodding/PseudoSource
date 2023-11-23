// File Line: 52
// RVA: 0x7CFE0
void __fastcall RenderResultBucket(
        UFG::qMemoryStream<CullResultBucket,192> *cull_bucket_stream,
        UFG::qMemoryStream<UFG::SceneryGroup,176> *scenery_group_stream,
        UFG::qMemoryStream<UFG::SceneryGroupComponent,120> *scenery_group_component_stream,
        GBufferSubmitContext *submit_context)
{
  GBufferSubmitContext *v4; // r15
  Illusion::StateArgs *p_mStateArgs; // rsi
  UFG::qMatrix44 *v9; // r13
  float v10; // xmm6_4
  __int64 v11; // r14
  _QWORD *mMainMemoryAddress; // rax
  __int64 v13; // rdi
  void **v14; // rax
  __int64 v15; // rax
  _DWORD *v16; // rbx
  char *v17; // rax
  char v18; // r11
  int v19; // r9d
  _BYTE *v20; // rcx
  int v21; // r8d
  unsigned int v22; // r10d
  signed int v23; // eax
  int v24; // eax
  unsigned __int64 v25; // r15
  __int64 v26; // rax
  __int64 v27; // rdx
  int v28; // eax
  __int64 v29; // rdx
  Illusion::Model *v30; // rbx
  UFG::qMatrix44 *v31; // rdi
  unsigned __int16 Param; // ax
  unsigned __int16 v33; // ax
  Illusion::SubmitContext *v34; // rax
  int v35; // eax
  __int64 v36; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v40; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v41; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v42; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v43; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v44; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v45; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v46; // rax
  Render::cbLocalTransformInverseState v47; // [rsp+20h] [rbp-A8h] BYREF
  Render::cbLocalTransformState arg; // [rsp+58h] [rbp-70h] BYREF
  __int64 v49; // [rsp+80h] [rbp-48h]
  UFG::qMatrix44 result; // [rsp+88h] [rbp-40h] BYREF
  __int64 v51; // [rsp+118h] [rbp+50h]
  UFG::qMemoryStream<UFG::SceneryGroup,176> *v52; // [rsp+120h] [rbp+58h]
  Illusion::SubmitContext *v53; // [rsp+130h] [rbp+68h]
  UFG::qMatrix44 *v54; // [rsp+138h] [rbp+70h] BYREF
  __int64 vars0; // [rsp+140h] [rbp+78h]

  v49 = -2i64;
  v4 = submit_context;
  p_mStateArgs = &submit_context->mStateArgs;
  v9 = v54;
  v10 = v54[2].v1.z * 1.0700001;
  UFG::qMatrix44::operator*(v54 + 4, (UFG::qMatrix44 *)&result.v3.z, v54 + 5);
  v11 = 0i64;
  mMainMemoryAddress = cull_bucket_stream->mMainMemoryAddress;
  if ( *((_DWORD *)mMainMemoryAddress + 2) )
  {
    do
    {
      v13 = mMainMemoryAddress[v11 + 3];
      v14 = (void **)mMainMemoryAddress[v11 + 10];
      if ( v14 != scenery_group_stream->mMainMemoryAddress )
      {
        scenery_group_stream->mMainMemoryAddress = v14;
        scenery_group_component_stream->mMainMemoryAddress = v14[17];
      }
      if ( LODWORD(v9[12].v2.y) || *(_DWORD *)v13 != 1085739069 )
      {
        v15 = *(_QWORD *)(v51 + 8);
        LODWORD(v54) = *(_DWORD *)(v15 + 4 * v11 + 164);
        HIDWORD(v54) = *(_DWORD *)(v15 + 4 * v11 + 136);
        v16 = (char *)scenery_group_stream->mMainMemoryAddress
            + 32 * *(unsigned __int16 *)(v13 + 4)
            + *((_QWORD *)scenery_group_stream->mMainMemoryAddress + 16)
            + 128;
        v17 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
        *(_DWORD *)v17 = *v16;
        *((_DWORD *)v17 + 1) = v16[1];
        *((_DWORD *)v17 + 2) = v16[2];
        *((_DWORD *)v17 + 3) = v16[3];
        *((_DWORD *)v17 + 4) = v16[4];
        *((_DWORD *)v17 + 5) = v16[5];
        *((_DWORD *)v17 + 6) = v16[6];
        *((_DWORD *)v17 + 7) = v16[7];
        *((_DWORD *)v17 + 8) = v16[8];
        *((_DWORD *)v17 + 9) = v16[9];
        *((_DWORD *)v17 + 10) = v16[10];
        *((_DWORD *)v17 + 11) = v16[11];
        *((_DWORD *)v17 + 12) = v16[12];
        *((_DWORD *)v17 + 13) = v16[13];
        *((_DWORD *)v17 + 14) = v16[14];
        *((_DWORD *)v17 + 15) = v16[15];
        v4->mStateValues.mSetValueMask.mFlags[0] |= 0x400000000ui64;
        v4->mStateValues.mParamValues[34] = v17;
        v18 = Render::TransparencySystem::msOpaqueIndex;
        v19 = Render::TransparencySystem::msOpaqueIndex;
        if ( v10 >= *((float *)&v54 + 1) )
          v19 = 0;
        v20 = scenery_group_component_stream->mMainMemoryAddress;
        if ( (unsigned __int8)v20[112] >= v19 )
        {
          v21 = *(unsigned __int8 *)(v13 + 9);
          v22 = 255
              * (((unsigned int)(((unsigned __int64)(2139062143i64 * SLODWORD(v9[2].v1.w)) >> 32) - LODWORD(v9[2].v1.w)) >> 31)
               + ((int)(((unsigned __int64)(2139062143i64 * SLODWORD(v9[2].v1.w)) >> 32) - LODWORD(v9[2].v1.w)) >> 7))
              + LODWORD(v9[2].v1.w);
          v23 = v22 - (*(unsigned __int8 *)(v13 + 11) + 1) % 255;
          if ( v23 < 0 )
            v23 = (*(unsigned __int8 *)(v13 + 11) + 1) % 255
                - (255
                 * (((unsigned int)(((unsigned __int64)(2139062143i64 * SLODWORD(v9[2].v1.w)) >> 32)
                                  - LODWORD(v9[2].v1.w)) >> 31)
                  + ((int)(((unsigned __int64)(2139062143i64 * SLODWORD(v9[2].v1.w)) >> 32) - LODWORD(v9[2].v1.w)) >> 7))
                 + LODWORD(v9[2].v1.w));
          if ( v23 <= 0 )
          {
            if ( v21 >= v19 )
            {
              if ( v21 > v19 )
                --v21;
            }
            else
            {
              ++v21;
            }
          }
          else
          {
            v21 = v19;
          }
          v24 = 0;
          if ( v21 > 0 )
            v24 = v21;
          if ( v24 < Render::TransparencySystem::msOpaqueIndex )
            v18 = v24;
          *(_BYTE *)(v13 + 9) = v18;
          *(_BYTE *)(v13 + 10) = v19;
          *(_BYTE *)(v13 + 11) = v22;
        }
        else
        {
          *(_BYTE *)(v13 + 9) = v20[112];
          *(_BYTE *)(v13 + 10) = *((_BYTE *)scenery_group_component_stream->mMainMemoryAddress + 113);
          *(_BYTE *)(v13 + 11) = *((_BYTE *)scenery_group_component_stream->mMainMemoryAddress + 114);
        }
        v25 = *(_QWORD *)(v13 + 9);
        v26 = *(_QWORD *)(v13 + 16);
        if ( v26 )
          v27 = v26 + v13 + 16;
        else
          v27 = 0i64;
        if ( !(_BYTE)v25 || !v27 )
          goto LABEL_46;
        if ( (*(_BYTE *)(v13 + 8) & 0x10) == 0 )
          goto LABEL_33;
        v28 = Render::TransparencySystem::msOpaqueIndex;
        if ( v10 >= (float)(*((float *)&v54 + 1) * v9[12].v2.z) )
          v28 = 0;
        if ( v28 < Render::TransparencySystem::msOpaqueIndex )
          v29 = v27 + 48;
        else
LABEL_33:
          v29 = v27 + 16;
        v30 = *(Illusion::Model **)(v29 + 16);
        if ( v30 )
        {
          v31 = (UFG::qMatrix44 *)(v13 + 32);
          Render::cbLocalTransformState::cbLocalTransformState(&arg, v9 + 4, &result, v31);
          arg.mPrev = &arg;
          arg.mNext = &arg;
          arg.mCallback = 0i64;
          arg.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
          *(_WORD *)&arg.mFlags = 1;
          if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
          {
            Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
            Render::cbLocalProjectionState::sStateParamIndex = Param;
            arg.mStateParamIndex = Param;
          }
          v47.mCached_Remote.m_Stream = 0i64;
          arg.mCached_Remote.m_Stream = &result;
          v47.mLocalWorld = v31;
          v47.mPrev = &v47;
          v47.mNext = &v47;
          v47.mCallback = 0i64;
          v47.mStateParamIndex = Render::cbLocalTransformInverseState::sStateParamIndex;
          *(_WORD *)&v47.mFlags = 1;
          if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == 0xFFFF )
          {
            v33 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
            Render::cbLocalTransformInverseState::sStateParamIndex = v33;
            v47.mStateParamIndex = v33;
          }
          v47.mCached_Remote.m_Stream = 0i64;
          v47.mWorldView = v9 + 4;
          v47.mLocalWorld = v31;
          Illusion::StateArgs::Set<Render::cbLocalTransformState>(p_mStateArgs, &arg);
          Illusion::StateArgs::Set<Render::cbLocalProjectionState>(p_mStateArgs, (Render::cbLocalProjectionState *)&arg);
          Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(p_mStateArgs, &v47);
          v34 = v53;
          v53[1].vfptr = (Illusion::SubmitContextVtbl *)&v54;
          v34[1].mStateValues.mSetValueMask.mFlags[0] = v25;
          v4 = (GBufferSubmitContext *)v34;
          v35 = Illusion::SubmitContext::Draw(v34, v30, 0i64);
          v36 = vars0;
          ++*(_DWORD *)(vars0 + 40);
          *(_DWORD *)(v36 + 52) += v35;
          mPrev = v47.mPrev;
          mNext = v47.mNext;
          v47.mPrev->mNext = v47.mNext;
          mNext->mPrev = mPrev;
          v47.mPrev = &v47;
          v47.mNext = &v47;
          v47.mIsSet = 0;
          if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[v47.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[v47.mStateParamIndex] )
            p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v47.mStateParamIndex >> 6] &= ~(1i64 << (v47.mStateParamIndex & 0x3F));
          v39 = arg.mPrev;
          v40 = arg.mNext;
          arg.mPrev->mNext = arg.mNext;
          v40->mPrev = v39;
          arg.mPrev = &arg;
          arg.mNext = &arg;
          arg.mIsSet = 0;
          if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[arg.mStateParamIndex] )
            p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
          v41 = arg.mPrev;
          v42 = arg.mNext;
          arg.mPrev->mNext = arg.mNext;
          v42->mPrev = v41;
          arg.mPrev = &arg;
          arg.mNext = &arg;
          arg.mIsSet = 0;
          if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[arg.mStateParamIndex] )
            p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
          v43 = v47.mPrev;
          v44 = v47.mNext;
          v47.mPrev->mNext = v47.mNext;
          v44->mPrev = v43;
          v47.mPrev = &v47;
          v47.mNext = &v47;
          v45 = arg.mPrev;
          v46 = arg.mNext;
          arg.mPrev->mNext = arg.mNext;
          v46->mPrev = v45;
          arg.mPrev = &arg;
          arg.mNext = &arg;
        }
        else
        {
LABEL_46:
          v4 = (GBufferSubmitContext *)v53;
        }
        scenery_group_stream = v52;
      }
      v11 = (unsigned int)(v11 + 1);
      mMainMemoryAddress = *(_QWORD **)(v51 + 8);
    }
    while ( (unsigned int)v11 < *((_DWORD *)mMainMemoryAddress + 2) );
  }
}

// File Line: 189
// RVA: 0x1457580
__int64 dynamic_initializer_for__gTaskFunctionDecl_RenderSceneryTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_RenderSceneryTask,
    &gTaskFunctionDeclData_RenderSceneryTask);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTaskFunctionDecl_RenderSceneryTask__);
}

// File Line: 192
// RVA: 0x7C960
void __fastcall RenderSceneryTask(int workerId, UFG::qMemoryStreamer *memory_streamer, char *param_stream, void *pad0)
{
  unsigned __int16 Param; // ax
  unsigned __int16 v7; // ax
  void *v8; // rax
  void *v9; // rax
  void *v10; // rax
  void *v11; // rax
  void *v12; // rax
  void *v13; // rax
  void *v14; // rax
  void *v15; // rax
  void *v16; // rax
  void *v17; // rax
  void *v18; // rax
  void *v19; // rax
  void *v20; // rax
  void **v21; // rdx
  unsigned int v22; // edi
  BOOL v23; // esi
  void **v24; // rbx
  unsigned int v25; // eax
  void **v26; // rcx
  BOOL v27; // edx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v30; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v31; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v32; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v35; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v36; // rax
  Render::cbExternalViewTransformState v37; // [rsp+30h] [rbp-D0h] BYREF
  Render::cbViewTransformState arg; // [rsp+70h] [rbp-90h] BYREF
  UFG::qMemoryStreamer *v39; // [rsp+C0h] [rbp-40h]
  UFG::qMemoryStream<CullResultBucket,192> cull_bucket_stream; // [rsp+C8h] [rbp-38h] BYREF
  __int64 v41; // [rsp+E0h] [rbp-20h]
  UFG::qMemoryStream<UFG::SceneryGroupComponent,120> scenery_group_component_stream; // [rsp+E8h] [rbp-18h] BYREF
  UFG::qMemoryStream<UFG::SceneryGroup,176> scenery_group_stream; // [rsp+100h] [rbp+0h] BYREF
  __int64 v44[4]; // [rsp+118h] [rbp+18h] BYREF
  int v45; // [rsp+138h] [rbp+38h]
  __int64 v46[8]; // [rsp+140h] [rbp+40h] BYREF
  UFG::qMatrix44 result; // [rsp+180h] [rbp+80h] BYREF
  UFG::qMatrix44 d; // [rsp+1C0h] [rbp+C0h] BYREF
  char *stream_name; // [rsp+200h] [rbp+100h]
  __int64 v50; // [rsp+208h] [rbp+108h]
  int v51; // [rsp+210h] [rbp+110h]
  Render::ViewMetrics *v52; // [rsp+218h] [rbp+118h]
  char v53[141]; // [rsp+303h] [rbp+203h] BYREF
  GBufferSubmitContext dest; // [rsp+390h] [rbp+290h] BYREF

  v46[7] = -2i64;
  stream_name = "<unassigned>";
  v50 = 0i64;
  v51 = 0;
  v52 = (Render::ViewMetrics *)((unsigned __int64)v53 & 0xFFFFFFFFFFFFFF80ui64);
  Render::ViewMetrics::Reset((Render::ViewMetrics *)((unsigned __int64)v53 & 0xFFFFFFFFFFFFFF80ui64));
  Render::ViewMetrics::BeginTarget((Render::ViewMetrics *)((unsigned __int64)v53 & 0xFFFFFFFFFFFFFF80ui64));
  GBufferSubmitContext::GBufferSubmitContext(&dest);
  dest.mRenderQueueProvider = (RenderQueueLayer *)*((_QWORD *)param_stream + 5);
  UFG::qMemSet(dest.mStateValues.mParamValues, 0, 0x400u);
  dest.mStateValues.mSetValueMask.mFlags[1] = 0i64;
  dest.mStateValues.mSetValueMask.mFlags[0] = 0i64;
  UFG::qInverseAffine(&d, (UFG::qMatrix44 *)param_stream + 4);
  UFG::qMatrix44::operator*((UFG::qMatrix44 *)param_stream + 4, &result, (UFG::qMatrix44 *)param_stream + 5);
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
    Render::cbViewTransformState::sStateParamIndex = Param;
    arg.mStateParamIndex = Param;
  }
  arg.mWorldViewProjection = &result;
  arg.mViewWorld = &d;
  arg.mProjection = (UFG::qMatrix44 *)(param_stream + 320);
  arg.mScreenOffset = (UFG::qVector2 *)(param_stream + 244);
  arg.mCached_Remote.m_Stream = 0i64;
  v37.mPrev = &v37;
  v37.mNext = &v37;
  v37.mCallback = 0i64;
  v37.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&v37.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == 0xFFFF )
  {
    v7 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v7;
    v37.mStateParamIndex = v7;
  }
  v37.mWorldView = (UFG::qMatrix44 *)(param_stream + 256);
  v37.mProjection = (UFG::qMatrix44 *)(param_stream + 320);
  v37.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbViewTransformState>(&dest.mStateArgs, &arg);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(&dest.mStateArgs, &v37);
  v44[0] = 0i64;
  v44[1] = 0i64;
  v45 = 0;
  v44[3] = -1i64;
  v44[2] = -1i64;
  dest.mShaderSelector = (Illusion::ShaderSelector *)v44;
  v46[0] = *((_QWORD *)param_stream + 22);
  v46[1] = *((_QWORD *)param_stream + 24);
  v46[4] = *((_QWORD *)param_stream + 23);
  v46[5] = *((_QWORD *)param_stream + 15);
  v46[6] = *((_QWORD *)param_stream + 16);
  v46[2] = *((_QWORD *)param_stream + 25);
  v46[3] = *((_QWORD *)param_stream + 26);
  dest.mPerPhaseParams = (GBufferSubmitContext::PerPhaseParams *)v46;
  v8 = (void *)*((_QWORD *)param_stream + 21);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x2000ui64;
  dest.mStateValues.mParamValues[13] = v8;
  v9 = (void *)*((_QWORD *)param_stream + 8);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x10000000000ui64;
  dest.mStateValues.mParamValues[40] = v9;
  v10 = (void *)*((_QWORD *)param_stream + 9);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x20000000000ui64;
  dest.mStateValues.mParamValues[41] = v10;
  v11 = (void *)*((_QWORD *)param_stream + 10);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x20000000000000ui64;
  dest.mStateValues.mParamValues[53] = v11;
  v12 = (void *)*((_QWORD *)param_stream + 11);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x80000000000ui64;
  dest.mStateValues.mParamValues[43] = v12;
  v13 = (void *)*((_QWORD *)param_stream + 97);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x2000000000000000ui64;
  dest.mStateValues.mParamValues[61] = v13;
  v14 = (void *)*((_QWORD *)param_stream + 7);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x80000000000000ui64;
  dest.mStateValues.mParamValues[55] = v14;
  v15 = (void *)*((_QWORD *)param_stream + 29);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x200000000000ui64;
  dest.mStateValues.mParamValues[45] = v15;
  v16 = (void *)*((_QWORD *)param_stream + 98);
  dest.mStateValues.mSetValueMask.mFlags[1] |= 1ui64;
  dest.mStateValues.mParamValues[64] = v16;
  v17 = (void *)*((_QWORD *)param_stream + 14);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x800000000000000ui64;
  dest.mStateValues.mParamValues[59] = v17;
  v18 = (void *)*((_QWORD *)param_stream + 13);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x400000000000000ui64;
  dest.mStateValues.mParamValues[58] = v18;
  v19 = (void *)*((_QWORD *)param_stream + 12);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x200000000000000ui64;
  dest.mStateValues.mParamValues[57] = v19;
  v20 = (void *)*((_QWORD *)param_stream + 99);
  dest.mStateValues.mSetValueMask.mFlags[0] |= 0x100000000ui64;
  dest.mStateValues.mParamValues[32] = v20;
  scenery_group_stream.mName = "<unassigned>";
  scenery_group_stream.mMainMemoryAddress = 0i64;
  scenery_group_stream.mState = 0;
  scenery_group_component_stream.mName = "<unassigned>";
  scenery_group_component_stream.mMainMemoryAddress = 0i64;
  scenery_group_component_stream.mState = 0;
  v21 = *(void ***)(*((_QWORD *)param_stream + 1) + 8i64 * *((int *)param_stream + 34) + 80);
  v39 = memory_streamer;
  cull_bucket_stream.mName = "CullResultBucketIterator";
  cull_bucket_stream.mState = 0;
  v41 = 0i64;
  v22 = 0;
  v23 = memory_streamer != 0i64;
  v24 = v21;
  if ( v21 != 0i64 && v23 )
    v24 = v21;
  cull_bucket_stream.mMainMemoryAddress = v24;
  if ( v21 )
  {
    while ( 1 )
    {
      v25 = UFG::qAtomicAdd(*((volatile int **)param_stream + 2), 1) - 1;
      if ( v22 < v25 )
        break;
LABEL_13:
      RenderResultBucket(&cull_bucket_stream, &scenery_group_stream, &scenery_group_component_stream, &dest);
    }
    while ( 1 )
    {
      v26 = (void **)*v24;
      v27 = *v24 != 0i64;
      v24 = v26;
      cull_bucket_stream.mMainMemoryAddress = v26;
      if ( v27 && v23 )
        HIDWORD(v41) = ++v22;
      LODWORD(v41) = 0;
      if ( !v26 )
        break;
      if ( v22 >= v25 )
        goto LABEL_13;
    }
  }
  mPrev = v37.mPrev;
  mNext = v37.mNext;
  v37.mPrev->mNext = v37.mNext;
  mNext->mPrev = mPrev;
  v37.mPrev = &v37;
  v37.mNext = &v37;
  v37.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)dest.mStateArgs.mStateArgs[v37.mStateParamIndex].mNode.mNext == &dest.mStateArgs.mStateArgs[v37.mStateParamIndex] )
  {
    v30 = &dest.mStateArgs.mStateArgsCreateMask.mFlags[(unsigned int)v37.mStateParamIndex >> 6];
    *v30 &= ~(1i64 << (v37.mStateParamIndex & 0x3F));
  }
  v31 = arg.mPrev;
  v32 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v32->mPrev = v31;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)dest.mStateArgs.mStateArgs[arg.mStateParamIndex].mNode.mNext == &dest.mStateArgs.mStateArgs[arg.mStateParamIndex] )
    dest.mStateArgs.mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::ViewMetrics::EndTarget(v52);
  UFG::qMemoryStreamer::BeginRawWritePlat(
    memory_streamer,
    stream_name,
    v52,
    0x80ui64,
    *((void **)param_stream + 18),
    0x80ui64);
  v33 = v37.mPrev;
  v34 = v37.mNext;
  v37.mPrev->mNext = v37.mNext;
  v34->mPrev = v33;
  v37.mPrev = &v37;
  v37.mNext = &v37;
  v35 = arg.mPrev;
  v36 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v36->mPrev = v35;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  `eh vector destructor iterator(
    dest.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
}

