// File Line: 52
// RVA: 0x7CFE0
void __fastcall RenderResultBucket(UFG::qMemoryStream<CullResultBucket,192> *cull_bucket_stream, UFG::qMemoryStream<UFG::SceneryGroup,176> *scenery_group_stream, UFG::qMemoryStream<UFG::SceneryGroupComponent,120> *scenery_group_component_stream, GBufferSubmitContext *submit_context)
{
  GBufferSubmitContext *v4; // r15
  UFG::qMemoryStream<UFG::SceneryGroupComponent,120> *v5; // r12
  UFG::qMemoryStream<UFG::SceneryGroup,176> *v6; // rbx
  UFG::qMemoryStream<CullResultBucket,192> *v7; // rdi
  Illusion::StateArgs *v8; // rsi
  UFG::qMatrix44 *v9; // r13
  float v10; // xmm6_4
  __int64 v11; // r14
  _QWORD *v12; // rax
  __int64 v13; // rdi
  void **v14; // rax
  __int64 v15; // rax
  _DWORD *v16; // rbx
  char *v17; // rax
  char v18; // r11
  signed int v19; // er9
  _BYTE *v20; // rcx
  int v21; // er8
  unsigned int v22; // er10
  int v23; // eax
  int v24; // eax
  unsigned __int64 v25; // r15
  __int64 v26; // rax
  signed __int64 v27; // rdx
  int v28; // eax
  signed __int64 v29; // rdx
  Illusion::Model *v30; // rbx
  UFG::qMatrix44 *v31; // rdi
  unsigned __int16 v32; // ax
  unsigned __int16 v33; // ax
  Illusion::SubmitContext *v34; // rax
  int v35; // eax
  __int64 v36; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v37; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v38; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v39; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v40; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v41; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v42; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v43; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v44; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v45; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v46; // rax
  Render::cbLocalTransformInverseState v47; // [rsp+20h] [rbp-A8h]
  Render::cbLocalTransformState arg; // [rsp+58h] [rbp-70h]
  __int64 v49; // [rsp+80h] [rbp-48h]
  UFG::qMatrix44 result; // [rsp+88h] [rbp-40h]
  __int64 v51; // [rsp+118h] [rbp+50h]
  UFG::qMemoryStream<UFG::SceneryGroup,176> *v52; // [rsp+120h] [rbp+58h]
  Illusion::SubmitContext *v53; // [rsp+130h] [rbp+68h]
  UFG::qMatrix44 *v54; // [rsp+138h] [rbp+70h]
  __int64 vars0; // [rsp+140h] [rbp+78h]

  v49 = -2i64;
  v4 = submit_context;
  v5 = scenery_group_component_stream;
  v6 = scenery_group_stream;
  v7 = cull_bucket_stream;
  v8 = &submit_context->mStateArgs;
  v9 = v54;
  v10 = v54[2].v1.z * 1.0700001;
  UFG::qMatrix44::operator*(v54 + 4, (UFG::qMatrix44 *)((char *)&result + 56), v54 + 5);
  v11 = 0i64;
  v12 = v7->mMainMemoryAddress;
  if ( *((_DWORD *)v12 + 2) )
  {
    do
    {
      v13 = v12[v11 + 3];
      v14 = (void **)v12[v11 + 10];
      if ( v14 != v6->mMainMemoryAddress )
      {
        v6->mMainMemoryAddress = v14;
        v5->mMainMemoryAddress = v14[17];
      }
      if ( LODWORD(v9[12].v2.y) || *(_DWORD *)v13 != 1085739069 )
      {
        v15 = *(_QWORD *)(v51 + 8);
        LODWORD(v54) = *(_DWORD *)(v15 + 4 * v11 + 164);
        HIDWORD(v54) = *(_DWORD *)(v15 + 4 * v11 + 136);
        v16 = (char *)v6->mMainMemoryAddress
            + 32 * (*(unsigned __int16 *)(v13 + 4) + 4i64)
            + *((_QWORD *)v6->mMainMemoryAddress + 16);
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
        v20 = v5->mMainMemoryAddress;
        if ( (unsigned __int8)v20[112] >= v19 )
        {
          v21 = *(unsigned __int8 *)(v13 + 9);
          v22 = 255
              * (((unsigned int)(((unsigned __int64)(2139062143i64 * SLODWORD(v9[2].v1.w)) >> 32) - LODWORD(v9[2].v1.w)) >> 31)
               + ((signed int)(((unsigned __int64)(2139062143i64 * SLODWORD(v9[2].v1.w)) >> 32) - LODWORD(v9[2].v1.w)) >> 7))
              + LODWORD(v9[2].v1.w);
          v23 = v22 - (*(unsigned __int8 *)(v13 + 11) + 1) % 255;
          if ( v23 < 0 )
            v23 = (*(unsigned __int8 *)(v13 + 11) + 1) % 255
                - (255
                 * (((unsigned int)(((unsigned __int64)(2139062143i64 * SLODWORD(v9[2].v1.w)) >> 32)
                                  - LODWORD(v9[2].v1.w)) >> 31)
                  + ((signed int)(((unsigned __int64)(2139062143i64 * SLODWORD(v9[2].v1.w)) >> 32) - LODWORD(v9[2].v1.w)) >> 7))
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
          *(_BYTE *)(v13 + 10) = *((_BYTE *)v5->mMainMemoryAddress + 113);
          *(_BYTE *)(v13 + 11) = *((_BYTE *)v5->mMainMemoryAddress + 114);
        }
        v25 = *(_QWORD *)(v13 + 9);
        v26 = *(_QWORD *)(v13 + 16);
        if ( v26 )
          v27 = v26 + v13 + 16;
        else
          v27 = 0i64;
        if ( (unsigned __int8)v25 <= 0u || !v27 )
          goto LABEL_51;
        if ( !(*(_BYTE *)(v13 + 8) & 0x10) )
          goto LABEL_52;
        v28 = Render::TransparencySystem::msOpaqueIndex;
        if ( v10 >= (float)(*((float *)&v54 + 1) * v9[12].v2.z) )
          v28 = 0;
        if ( v28 < Render::TransparencySystem::msOpaqueIndex )
          v29 = v27 + 48;
        else
LABEL_52:
          v29 = v27 + 16;
        v30 = *(Illusion::Model **)(v29 + 16);
        if ( v30 )
        {
          v31 = (UFG::qMatrix44 *)(v13 + 32);
          Render::cbLocalTransformState::cbLocalTransformState(&arg, v9 + 4, &result, v31);
          arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
          arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
          arg.mCallback = 0i64;
          arg.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
          *(_WORD *)&arg.mFlags = 1;
          if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
          {
            v32 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
            Render::cbLocalProjectionState::sStateParamIndex = v32;
            arg.mStateParamIndex = v32;
          }
          v47.mCached_Remote.m_Stream = 0i64;
          arg.mCached_Remote.m_Stream = &result;
          v47.mLocalWorld = v31;
          v47.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v47;
          v47.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v47;
          v47.mCallback = 0i64;
          v47.mStateParamIndex = Render::cbLocalTransformInverseState::sStateParamIndex;
          *(_WORD *)&v47.mFlags = 1;
          if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == -1 )
          {
            v33 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
            Render::cbLocalTransformInverseState::sStateParamIndex = v33;
            v47.mStateParamIndex = v33;
          }
          v47.mCached_Remote.m_Stream = 0i64;
          v47.mWorldView = v9 + 4;
          v47.mLocalWorld = v31;
          Illusion::StateArgs::Set<Render::cbLocalTransformState>(v8, &arg);
          Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v8, (Render::cbLocalProjectionState *)&arg);
          Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(v8, &v47);
          v34 = v53;
          v53[1].vfptr = (Illusion::SubmitContextVtbl *)&v54;
          v34[1].mStateValues.mSetValueMask.mFlags[0] = v25;
          v4 = (GBufferSubmitContext *)v34;
          v35 = Illusion::SubmitContext::Draw(v34, v30, 0i64);
          v36 = vars0;
          ++*(_DWORD *)(v36 + 40);
          *(_DWORD *)(v36 + 52) += v35;
          v37 = v47.mPrev;
          v38 = v47.mNext;
          v47.mPrev->mNext = v47.mNext;
          v38->mPrev = v37;
          v47.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v47;
          v47.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v47;
          v47.mIsSet = 0;
          if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (v47.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (v47.mStateParamIndex + 3i64)) )
            v8->mStateArgsCreateMask.mFlags[(unsigned int)v47.mStateParamIndex >> 6] &= ~(1i64 << (v47.mStateParamIndex & 0x3F));
          v39 = arg.mPrev;
          v40 = arg.mNext;
          arg.mPrev->mNext = arg.mNext;
          v40->mPrev = v39;
          arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
          arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
          arg.mIsSet = 0;
          if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (arg.mStateParamIndex + 3i64)) )
            v8->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
          v41 = arg.mPrev;
          v42 = arg.mNext;
          arg.mPrev->mNext = arg.mNext;
          v42->mPrev = v41;
          arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
          arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
          arg.mIsSet = 0;
          if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (arg.mStateParamIndex + 3i64)) )
            v8->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
          v43 = v47.mPrev;
          v44 = v47.mNext;
          v47.mPrev->mNext = v47.mNext;
          v44->mPrev = v43;
          v47.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v47;
          v47.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v47;
          v45 = arg.mPrev;
          v46 = arg.mNext;
          arg.mPrev->mNext = arg.mNext;
          v46->mPrev = v45;
          arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
          arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
        }
        else
        {
LABEL_51:
          v4 = (GBufferSubmitContext *)v53;
        }
        v6 = v52;
      }
      v11 = (unsigned int)(v11 + 1);
      v12 = *(_QWORD **)(v51 + 8);
    }
    while ( (unsigned int)v11 < *((_DWORD *)v12 + 2) );
  }
}

// File Line: 189
// RVA: 0x1457580
__int64 dynamic_initializer_for__gTaskFunctionDecl_RenderSceneryTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_RenderSceneryTask,
    &gTaskFunctionDeclData_RenderSceneryTask);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_RenderSceneryTask__);
}

// File Line: 192
// RVA: 0x7C960
void __fastcall RenderSceneryTask(int workerId, UFG::qMemoryStreamer *memory_streamer, void *param_stream, void *pad0)
{
  char *v4; // r14
  UFG::qMemoryStreamer *v5; // r12
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // ax
  void *v8; // rax
  unsigned __int64 v9; // rcx
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
  void *v21; // rax
  void **v22; // rdx
  unsigned int v23; // edi
  BOOL v24; // esi
  void **v25; // rbx
  unsigned int v26; // eax
  void **v27; // rcx
  BOOL v28; // edx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v29; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v30; // rax
  unsigned __int64 *v31; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v32; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v35; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v36; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v37; // rax
  Render::cbExternalViewTransformState v38; // [rsp+30h] [rbp-D0h]
  Render::cbViewTransformState arg; // [rsp+70h] [rbp-90h]
  UFG::qMemoryStreamer *v40; // [rsp+C0h] [rbp-40h]
  UFG::qMemoryStream<CullResultBucket,192> cull_bucket_stream; // [rsp+C8h] [rbp-38h]
  __int64 v42; // [rsp+E0h] [rbp-20h]
  UFG::qMemoryStream<UFG::SceneryGroupComponent,120> scenery_group_component_stream; // [rsp+E8h] [rbp-18h]
  UFG::qMemoryStream<UFG::SceneryGroup,176> scenery_group_stream; // [rsp+100h] [rbp+0h]
  __int64 v45; // [rsp+118h] [rbp+18h]
  __int64 v46; // [rsp+120h] [rbp+20h]
  __int64 v47; // [rsp+128h] [rbp+28h]
  __int64 v48; // [rsp+130h] [rbp+30h]
  int v49; // [rsp+138h] [rbp+38h]
  __int64 v50; // [rsp+140h] [rbp+40h]
  __int64 v51; // [rsp+148h] [rbp+48h]
  __int64 v52; // [rsp+150h] [rbp+50h]
  __int64 v53; // [rsp+158h] [rbp+58h]
  __int64 v54; // [rsp+160h] [rbp+60h]
  __int64 v55; // [rsp+168h] [rbp+68h]
  __int64 v56; // [rsp+170h] [rbp+70h]
  __int64 v57; // [rsp+178h] [rbp+78h]
  UFG::qMatrix44 result; // [rsp+180h] [rbp+80h]
  UFG::qMatrix44 d; // [rsp+1C0h] [rbp+C0h]
  char *stream_name; // [rsp+200h] [rbp+100h]
  __int64 v61; // [rsp+208h] [rbp+108h]
  int v62; // [rsp+210h] [rbp+110h]
  Render::ViewMetrics *v63; // [rsp+218h] [rbp+118h]
  char v64; // [rsp+303h] [rbp+203h]
  GBufferSubmitContext dest; // [rsp+390h] [rbp+290h]

  v57 = -2i64;
  v4 = (char *)param_stream;
  v5 = memory_streamer;
  stream_name = "<unassigned>";
  v61 = 0i64;
  v62 = 0;
  v63 = (Render::ViewMetrics *)((unsigned __int64)&v64 & 0xFFFFFFFFFFFFFF80ui64);
  Render::ViewMetrics::Reset((Render::ViewMetrics *)((unsigned __int64)&v64 & 0xFFFFFFFFFFFFFF80ui64));
  Render::ViewMetrics::BeginTarget((Render::ViewMetrics *)((unsigned __int64)&v64 & 0xFFFFFFFFFFFFFF80ui64));
  GBufferSubmitContext::GBufferSubmitContext(&dest);
  dest.mRenderQueueProvider = (RenderQueueLayer *)*((_QWORD *)v4 + 5);
  UFG::qMemSet(dest.mStateValues.mParamValues, 0, 0x400u);
  dest.mStateValues.mSetValueMask.mFlags[1] = 0i64;
  dest.mStateValues.mSetValueMask.mFlags[0] = 0i64;
  UFG::qInverseAffine(&d, (UFG::qMatrix44 *)v4 + 4);
  UFG::qMatrix44::operator*((UFG::qMatrix44 *)v4 + 4, &result, (UFG::qMatrix44 *)v4 + 5);
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == -1 )
  {
    v6 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
    Render::cbViewTransformState::sStateParamIndex = v6;
    arg.mStateParamIndex = v6;
  }
  arg.mWorldViewProjection = &result;
  arg.mViewWorld = &d;
  arg.mProjection = (UFG::qMatrix44 *)(v4 + 320);
  arg.mScreenOffset = (UFG::qVector2 *)(v4 + 244);
  arg.mCached_Remote.m_Stream = 0i64;
  v38.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v38.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v38.mCallback = 0i64;
  v38.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&v38.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v7 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v7;
    v38.mStateParamIndex = v7;
  }
  v38.mWorldView = (UFG::qMatrix44 *)(v4 + 256);
  v38.mProjection = (UFG::qMatrix44 *)(v4 + 320);
  v38.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbViewTransformState>(&dest.mStateArgs, &arg);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(&dest.mStateArgs, &v38);
  v45 = 0i64;
  v46 = 0i64;
  v49 = 0;
  v48 = -1i64;
  v47 = -1i64;
  dest.mShaderSelector = (Illusion::ShaderSelector *)&v45;
  v50 = *((_QWORD *)v4 + 22);
  v51 = *((_QWORD *)v4 + 24);
  v54 = *((_QWORD *)v4 + 23);
  v55 = *((_QWORD *)v4 + 15);
  v56 = *((_QWORD *)v4 + 16);
  v52 = *((_QWORD *)v4 + 25);
  v53 = *((_QWORD *)v4 + 26);
  dest.mPerPhaseParams = (GBufferSubmitContext::PerPhaseParams *)&v50;
  v8 = (void *)*((_QWORD *)v4 + 21);
  v9 = dest.mStateValues.mSetValueMask.mFlags[0] | 0x2000;
  dest.mStateValues.mSetValueMask.mFlags[0] = v9;
  dest.mStateValues.mParamValues[13] = v8;
  v10 = (void *)*((_QWORD *)v4 + 8);
  v9 |= 0x10000000000ui64;
  dest.mStateValues.mSetValueMask.mFlags[0] = v9;
  dest.mStateValues.mParamValues[40] = v10;
  v11 = (void *)*((_QWORD *)v4 + 9);
  v9 |= 0x20000000000ui64;
  dest.mStateValues.mSetValueMask.mFlags[0] = v9;
  dest.mStateValues.mParamValues[41] = v11;
  v12 = (void *)*((_QWORD *)v4 + 10);
  v9 |= 0x20000000000000ui64;
  dest.mStateValues.mSetValueMask.mFlags[0] = v9;
  dest.mStateValues.mParamValues[53] = v12;
  v13 = (void *)*((_QWORD *)v4 + 11);
  v9 |= 0x80000000000ui64;
  dest.mStateValues.mSetValueMask.mFlags[0] = v9;
  dest.mStateValues.mParamValues[43] = v13;
  v14 = (void *)*((_QWORD *)v4 + 97);
  v9 |= 0x2000000000000000ui64;
  dest.mStateValues.mSetValueMask.mFlags[0] = v9;
  dest.mStateValues.mParamValues[61] = v14;
  v15 = (void *)*((_QWORD *)v4 + 7);
  v9 |= 0x80000000000000ui64;
  dest.mStateValues.mSetValueMask.mFlags[0] = v9;
  dest.mStateValues.mParamValues[55] = v15;
  v16 = (void *)*((_QWORD *)v4 + 29);
  v9 |= 0x200000000000ui64;
  dest.mStateValues.mSetValueMask.mFlags[0] = v9;
  dest.mStateValues.mParamValues[45] = v16;
  v17 = (void *)*((_QWORD *)v4 + 98);
  dest.mStateValues.mSetValueMask.mFlags[1] |= 1ui64;
  dest.mStateValues.mParamValues[64] = v17;
  v18 = (void *)*((_QWORD *)v4 + 14);
  v9 |= 0x800000000000000ui64;
  dest.mStateValues.mSetValueMask.mFlags[0] = v9;
  dest.mStateValues.mParamValues[59] = v18;
  v19 = (void *)*((_QWORD *)v4 + 13);
  v9 |= 0x400000000000000ui64;
  dest.mStateValues.mSetValueMask.mFlags[0] = v9;
  dest.mStateValues.mParamValues[58] = v19;
  v20 = (void *)*((_QWORD *)v4 + 12);
  dest.mStateValues.mSetValueMask.mFlags[0] = v9 | 0x200000000000000i64;
  dest.mStateValues.mParamValues[57] = v20;
  v21 = (void *)*((_QWORD *)v4 + 99);
  dest.mStateValues.mSetValueMask.mFlags[0] = v9 | 0x200000100000000i64;
  dest.mStateValues.mParamValues[32] = v21;
  scenery_group_stream.mName = "<unassigned>";
  scenery_group_stream.mMainMemoryAddress = 0i64;
  scenery_group_stream.mState = 0;
  scenery_group_component_stream.mName = "<unassigned>";
  scenery_group_component_stream.mMainMemoryAddress = 0i64;
  scenery_group_component_stream.mState = 0;
  v22 = *(void ***)(*((_QWORD *)v4 + 1) + 8i64 * *((signed int *)v4 + 34) + 80);
  v40 = v5;
  cull_bucket_stream.mName = "CullResultBucketIterator";
  cull_bucket_stream.mState = 0;
  v42 = 0i64;
  v23 = 0;
  v24 = v5 != 0i64;
  v25 = v22;
  if ( (v22 != 0i64) & (unsigned __int8)v24 )
    v25 = v22;
  cull_bucket_stream.mMainMemoryAddress = v25;
  if ( v22 )
  {
    while ( 1 )
    {
      v26 = UFG::qAtomicAdd(*((volatile int **)v4 + 2), 1) - 1;
      if ( v23 < v26 )
        break;
LABEL_13:
      RenderResultBucket(&cull_bucket_stream, &scenery_group_stream, &scenery_group_component_stream, &dest);
    }
    while ( 1 )
    {
      v27 = (void **)*v25;
      v28 = *v25 != 0i64;
      v25 = v27;
      cull_bucket_stream.mMainMemoryAddress = v27;
      if ( v28 && v24 )
        HIDWORD(v42) = ++v23;
      LODWORD(v42) = 0;
      if ( !v27 )
        break;
      if ( v23 >= v26 )
        goto LABEL_13;
    }
  }
  v29 = v38.mPrev;
  v30 = v38.mNext;
  v38.mPrev->mNext = v38.mNext;
  v30->mPrev = v29;
  v38.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v38.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v38.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)dest.mStateArgs.mStateArgs[v38.mStateParamIndex].mNode.mNext == &dest.mStateArgs.mStateArgs[v38.mStateParamIndex] )
  {
    v31 = &dest.mStateArgs.mStateArgsCreateMask.mFlags[(unsigned int)v38.mStateParamIndex >> 6];
    *v31 &= ~(1i64 << (v38.mStateParamIndex & 0x3F));
  }
  v32 = arg.mPrev;
  v33 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v33->mPrev = v32;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)dest.mStateArgs.mStateArgs[arg.mStateParamIndex].mNode.mNext == &dest.mStateArgs.mStateArgs[arg.mStateParamIndex] )
    dest.mStateArgs.mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  Render::ViewMetrics::EndTarget(v63);
  UFG::qMemoryStreamer::BeginRawWritePlat(v5, stream_name, v63, 0x80ui64, *((void **)v4 + 18), 0x80ui64);
  v34 = v38.mPrev;
  v35 = v38.mNext;
  v38.mPrev->mNext = v38.mNext;
  v35->mPrev = v34;
  v38.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v38.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v38;
  v36 = arg.mPrev;
  v37 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v37->mPrev = v36;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  `eh vector destructor iterator(
    dest.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
}

