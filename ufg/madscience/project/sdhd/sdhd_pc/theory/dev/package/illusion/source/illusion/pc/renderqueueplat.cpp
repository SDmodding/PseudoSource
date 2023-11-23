// File Line: 318
// RVA: 0xA1B640
void Illusion::RenderQueueSystem::Init(void)
{
  Illusion::RenderThreadManager::Init(&Illusion::gRenderThreadManager);
}

// File Line: 357
// RVA: 0xA1AA30
UFG::qTaskGroup *__fastcall Illusion::RenderQueueSystem::FlushRenderPhase(
        Illusion::RenderPhase *phase,
        unsigned int flush_task_count,
        unsigned int flush_task_dbg_id,
        UFG::qTask *flush_task_dep)
{
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *mPrev; // rax

  phase->mFlushTaskDependency = flush_task_dep;
  mPrev = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mPrev;
  Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mPrev->mNext = phase;
  phase->mPrev = mPrev;
  phase->mNext = (UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *)&Illusion::RenderQueuePlat::mFlushedRenderPhases;
  Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mPrev = phase;
  return 0i64;
}

// File Line: 375
// RVA: 0x15AA5A0
__int64 dynamic_initializer_for__Illusion::RenderQueuePlat::mFlushedRenderPhases__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Illusion::RenderQueuePlat::mFlushedRenderPhases__);
}

// File Line: 380
// RVA: 0xA1B1F0
UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *__fastcall Illusion::RenderQueuePlat::GetRenderPhasesForNextFrame()
{
  UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *result; // rax
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *mNext; // r8
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *mPrev; // rcx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v3; // rdx

  result = (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)UFG::qLinearAllocator::Malloc(
                                                                            Illusion::gEngine.FrameMemory,
                                                                            0x10u,
                                                                            0x10u);
  if ( result )
  {
    result->mNode.mPrev = &result->mNode;
    result->mNode.mNext = &result->mNode;
  }
  mNext = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext;
  if ( (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext != &Illusion::RenderQueuePlat::mFlushedRenderPhases )
  {
    mPrev = result->mNode.mPrev;
    v3 = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mPrev;
    mPrev->mNext = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext;
    mNext->mPrev = mPrev;
    v3->mNext = &result->mNode;
    result->mNode.mPrev = v3;
    Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mPrev = (UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *)&Illusion::RenderQueuePlat::mFlushedRenderPhases;
    Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext = (UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *)&Illusion::RenderQueuePlat::mFlushedRenderPhases;
  }
  return result;
}

// File Line: 409
// RVA: 0xA1A1F0
void __fastcall Illusion::IRenderQueuePlat::Execute(
        Illusion::IRenderQueuePlat *this,
        Illusion::TaskRenderEnv *context_param)
{
  int v2; // r13d
  Illusion::IRenderQueuePlat *v4; // r14
  Illusion::IRenderQueuePlat *v5; // rcx
  unsigned int v6; // ebp
  __int64 v7; // rsi
  __int64 v8; // rdx
  Illusion::VertexDecl *v9; // rbx
  ID3D11Buffer *v10; // r15
  unsigned int v11; // r12d
  __int64 v12; // rax
  int v13; // eax
  int v14; // ecx
  ID3D11Buffer *v15; // r15
  unsigned int v16; // r12d
  __int64 v17; // rax
  unsigned int v18; // eax
  float v19; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  int mUID; // eax
  int mPrev; // ecx
  int mPrev_high; // r8d
  int v27; // edx
  __int64 v28; // rax
  Illusion::Shader *mShader; // rdx
  _QWORD *v30; // r8
  void (__fastcall *v31)(Illusion::TaskRenderEnv *, Illusion::Shader *, _QWORD *, Illusion::VertexDecl *); // rax
  UFG::qBaseNodeRB *mParent; // rcx
  unsigned int mParent_high; // edx
  unsigned int v34; // ecx
  int v35; // edx
  ID3D11Buffer *v36; // rax
  Illusion::BeginTargetCommandParams *v37; // rdx
  int v38; // [rsp+50h] [rbp+8h]

  v2 = 0;
  v4 = this - 16;
  if ( !this )
    v4 = 0i64;
  UFG::qMemSet(&v4[96], 0, 0x400u);
  *(_QWORD *)&v4[88] = 0i64;
  *(_QWORD *)&v4[80] = 0i64;
  v5 = v4 + 16;
  v6 = 0;
  v7 = *(_QWORD *)&v4[24];
  if ( (Illusion::IRenderQueuePlat *)v7 != &v4[16] )
  {
    do
    {
      v8 = *(unsigned __int16 *)(v7 + 16 * (v6 + 2i64) + 2);
      v9 = *(Illusion::VertexDecl **)(v7 + 16 * (v6 + 2i64) + 8);
      switch ( *(_WORD *)(v7 + 16 * (v6 + 2i64)) )
      {
        case 1:
          *(_QWORD *)&v4[104] = v9;
          Illusion::TaskRenderEnv::SetShader(context_param, (Illusion::Shader *)v9);
          goto LABEL_52;
        case 2:
          if ( (unsigned int)(__int16)v8 >= 0x40 )
            *(_QWORD *)&v4[88] |= 1i64 << ((unsigned __int8)v8 - 64);
          else
            *(_QWORD *)&v4[80] |= 1i64 << v8;
          v28 = (__int16)v8;
          *(_QWORD *)&v4[8 * (__int16)v8 + 96] = v9;
          mShader = context_param->mShader;
          v30 = mShader->mShaderParam[v28];
          if ( v30 )
          {
            v31 = (void (__fastcall *)(Illusion::TaskRenderEnv *, Illusion::Shader *, _QWORD *, Illusion::VertexDecl *))v30[4];
            if ( v31 )
              v31(context_param, mShader, v30, v9);
          }
          goto LABEL_52;
        case 3:
          v5 = v4 + 16;
          if ( v9 != context_param->mVertexDecl )
          {
            context_param->mCurrState.mInputLayout = 0i64;
            context_param->mVertexDecl = v9;
          }
          break;
        case 4:
          v10 = 0i64;
          v11 = 0;
          if ( v9 )
          {
            LODWORD(v9->mVertexDeclUser.mOffset) = Illusion::gEngine.mFrameCount;
            v12 = *(_QWORD *)&v9[1].mDebugName[4];
            if ( v12 )
            {
              v10 = *(ID3D11Buffer **)(v12 + 88);
              v11 = v9->mStreamStrides[1];
              v2 = v9->mStreamStrides[2];
            }
            else
            {
              UFG::qPrintf(
                "!!! ERROR !!! Trying to render with a buffer object (%s) that hasnt been fully created yet. This is an "
                "error in the PC D3D resource system.",
                v9->mDebugName);
              context_param->mAbortNextDraw = 1;
            }
          }
          v13 = 57;
          if ( v11 == 4 )
            v13 = 42;
          context_param->mIndexCount = v2;
          context_param->mCurrState.mIndexBuffer = v10;
          context_param->mCurrState.mIndexBufferOffset = 0;
          v2 = 0;
          *(_DWORD *)context_param->mCurrState.mIndexBufferFormat = v13;
          goto LABEL_52;
        case 5:
          goto $LN34_21;
        case 6:
          LOWORD(v8) = 4;
$LN34_21:
          v14 = (__int16)v8;
          v15 = 0i64;
          v16 = 0;
          v38 = (__int16)v8;
          if ( v9 )
          {
            LODWORD(v9->mVertexDeclUser.mOffset) = Illusion::gEngine.mFrameCount;
            v17 = *(_QWORD *)&v9[1].mDebugName[4];
            if ( v17 )
            {
              v15 = *(ID3D11Buffer **)(v17 + 88);
              v16 = v9->mStreamStrides[1];
              v2 = *(_DWORD *)(v17 + 96);
            }
            else
            {
              UFG::qPrintf(
                "!!! Error !!! Trying to render with a buffer object (%s) that hasnt been fully created yet. This is an "
                "error in the PC D3D resource system.",
                v9->mDebugName);
              v14 = v38;
              context_param->mAbortNextDraw = 1;
            }
          }
          context_param->mCurrState.mVertexBuffers[v14] = v15;
          context_param->mCurrState.mVertexBufferOffsets[v14] = v2;
          v2 = 0;
          context_param->mCurrState.mVertexBufferStrides[v14] = v16;
          goto LABEL_52;
        case 7:
          v5 = v4 + 16;
          if ( v9 )
          {
            context_param->mAlphaState = (Illusion::AlphaState *)v9;
            context_param->mCurrState.mBlendState = *(ID3D11BlendState **)&v9->mStreamStrides[3];
          }
          break;
        case 8:
          v5 = v4 + 16;
          if ( v9 )
          {
            context_param->mRasterState = (Illusion::RasterState *)v9;
            v18 = BYTE1(v9->mStreamStrides[0]);
            context_param->mCurrState.mBlendStateMask = -1;
            context_param->mCurrState.mDepthStateStencilRef = v18;
            context_param->mCurrState.mDepthState = (ID3D11DepthStencilState *)v9[1].mNode.mParent;
            context_param->mCurrState.mRasterizerState = (ID3D11RasterizerState *)v9[1].mNode.mChild[0];
          }
          break;
        case 9:
          if ( v9 )
          {
            v19 = *((float *)&v9->mNode.mChild[1] + 1);
            v20 = *(float *)&v9->mNode.mChild[1];
            v21 = *((float *)v9->mNode.mChild + 1);
            v22 = *(float *)v9->mNode.mChild;
            v23 = *((float *)&v9->mNode.mParent + 1);
            context_param->mCurrState.mViewport.TopLeftX = *(float *)&v9->mNode.mParent;
            context_param->mCurrState.mViewport.TopLeftY = v23;
            context_param->mCurrState.mViewport.Width = v22;
            context_param->mCurrState.mViewport.Height = v21;
            context_param->mCurrState.mViewport.MinDepth = v20;
            context_param->mCurrState.mViewport.MaxDepth = v19;
            mUID = v9->mNode.mUID;
            mPrev = (int)v9->mResourceHandles.UFG::qResourceData::mNode.mPrev;
            mPrev_high = HIDWORD(v9->mResourceHandles.UFG::qResourceData::mNode.mPrev);
            v27 = *(&v9->mNode.mUID + 1);
            context_param->mCurrState.mScissorRect.left = mUID;
            context_param->mCurrState.mScissorRect.right = mPrev + mUID;
            context_param->mCurrState.mScissorRect.top = v27;
            context_param->mCurrState.mScissorRect.bottom = v27 + mPrev_high;
          }
          goto LABEL_52;
        case 0xA:
          context_param->mCurrState.mPrimType = Illusion::HardwareState::sPrimType[v9[1].mNumElements];
          Illusion::TaskRenderEnv::SubmitMesh(
            context_param,
            v9[1].mStreamStrides[0],
            v9[1].mStreamStrides[1] * Illusion::HardwareState::sIndicesPerPrim[v9[1].mNumElements]);
          goto LABEL_52;
        case 0xB:
          context_param->mCurrState.mPrimType = Illusion::HardwareState::sPrimType[LODWORD(v9[1].mVertexDeclUser.mOffset)];
          Illusion::TaskRenderEnv::SubmitMesh(
            context_param,
            HIDWORD(v9[1].mVertexDeclUser.mOffset),
            LODWORD(v9[2].mNode.mParent)
          * Illusion::HardwareState::sIndicesPerPrim[LODWORD(v9[1].mVertexDeclUser.mOffset)]);
          goto LABEL_52;
        case 0xC:
          mParent_high = HIDWORD(v9->mNode.mChild[0][3].mParent);
          context_param->mCurrState.mPrimType = Illusion::HardwareState::sPrimType[*((unsigned __int16 *)&v9->mNode.mUID
                                                                                   + 2)];
          v34 = *(_DWORD *)&v9->mDebugName[4];
          context_param->mCurrState.mVertexBuffers[0] = *(ID3D11Buffer **)&v9->mTypeUID;
          context_param->mCurrState.mVertexBufferOffsets[0] = v34;
          context_param->mCurrState.mVertexBufferStrides[0] = mParent_high;
          v35 = *(_DWORD *)&v9->mDebugName[24];
          v36 = *(ID3D11Buffer **)&v9->mDebugName[12];
          context_param->mCurrState.mIndexBufferOffset = *(_DWORD *)&v9->mDebugName[20];
          context_param->mCurrState.mIndexBuffer = v36;
          context_param->mIndexCount = v35;
          *(_DWORD *)context_param->mCurrState.mIndexBufferFormat = 57;
          Illusion::TaskRenderEnv::SubmitMesh(
            context_param,
            *(_DWORD *)&v9->mDebugName[20],
            *(_DWORD *)&v9->mDebugName[24]);
          goto LABEL_52;
        case 0xD:
          mParent = v9->mNode.mParent;
          context_param->mCurrState.mPrimType = Illusion::HardwareState::sPrimType[LODWORD(v9->mNode.mParent[7].mParent)];
          Illusion::TaskRenderEnv::SubmitMeshInstanced(
            context_param,
            (unsigned int)v9->mNode.mChild[0],
            HIDWORD(mParent[7].mParent),
            LODWORD(mParent[7].mChild[0]) * Illusion::HardwareState::sIndicesPerPrim[LODWORD(mParent[7].mParent)]);
          goto LABEL_52;
        case 0xE:
          Illusion::TaskRenderEnv::SetTarget(context_param, (Illusion::BeginTargetCommandParams *)v9);
          goto LABEL_52;
        case 0xF:
          if ( v9 && v9->mNode.mParent )
            Illusion::ITargetPlat::EndTarget(
              (Illusion::ITargetPlat *)v9->mNode.mParent,
              (Illusion::BeginTargetCommandParams *)v9);
          v5 = v4 + 16;
          if ( context_param->mTarget )
            context_param->mTarget = 0i64;
          break;
        case 0x10:
          v37 = (Illusion::BeginTargetCommandParams *)v9->mNode.mParent;
          if ( v9->mNode.mParent && v37->mTarget )
            Illusion::TaskRenderEnv::SetTarget(context_param, v37);
          Illusion::TaskRenderEnv::ClearTarget(context_param, (Illusion::ClearCommandParams *)v9);
          goto LABEL_52;
        case 0x11:
          ((void (__fastcall *)(UFG::qBaseNodeRB *, __int64, unsigned __int64))v9->mNode.mChild[0])(
            v9->mNode.mParent,
            v8,
            0x140000000ui64);
          goto LABEL_52;
        case 0x12:
          Illusion::OcclusionPlat::BeginQuery(&Illusion::gOcclusionPlat, (unsigned int)v9->mNode.mChild[0], 1u);
          goto LABEL_52;
        case 0x13:
          Illusion::ITargetPlat::EndQuery(
            (Illusion::OcclusionPlat *)v9->mNode.mParent->mParent,
            (unsigned int)v9->mNode.mChild[0],
            0x40000000u);
          goto LABEL_52;
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
          goto LABEL_52;
        case 0x1A:
          Illusion::TaskRenderEnv::DispatchCompute(
            context_param,
            (unsigned int)v9->mNode.mParent,
            HIDWORD(v9->mNode.mParent),
            (unsigned int)v9->mNode.mChild[0]);
          goto LABEL_52;
        case 0x1B:
          ((void (__fastcall *)(ID3D11DeviceContext *, __int64, unsigned __int64))context_param->mContext->vfptr[36].Release)(
            context_param->mContext,
            v8,
            0x140000000ui64);
          memset(&context_param->mDeviceState, 0, sizeof(context_param->mDeviceState));
          context_param->mDeviceState.mInComputePipeline = 0;
          context_param->mDeviceState.mBlendStateMask = -1;
LABEL_52:
          v5 = v4 + 16;
          break;
        default:
          break;
      }
      if ( ++v6 >= *(_DWORD *)(v7 + 24) )
      {
        v7 = *(_QWORD *)(v7 + 8);
        v6 = 0;
      }
    }
    while ( (Illusion::IRenderQueuePlat *)v7 != v5 );
  }
}
        v6 = 0;
      }
    }
    while ( (Illusion::IRenderQueuePlat *)v7 != v5 );
  }
}

// File Line: 847
// RVA: 0xA1A7B0
void __fastcall Illusion::RenderQueuePlat::ExecuteFlushedRenderPhasesImmediate(
        UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *flushed_render_phases)
{
  UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *i; // rbx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *mPrev; // rcx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *mNext; // rax
  UFG::qTask *v5; // rdx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v6; // rdx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v7; // rcx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *v8; // rax
  Render::SkinningCacheNode *Head; // rbx
  Illusion::TaskRenderEnv context_param; // [rsp+30h] [rbp-12D8h] BYREF

  Illusion::TaskRenderEnv::TaskRenderEnv(
    &context_param,
    *(ID3D11DeviceContext **)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64));
  Illusion::RenderQueuePlat::msPrintFlushedQueues = 0;
  for ( i = (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)flushed_render_phases->mNode.mNext;
        i != flushed_render_phases;
        i = (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)flushed_render_phases->mNode.mNext )
  {
    mPrev = i->mNode.mPrev;
    mNext = i->mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
    v5 = (UFG::qTask *)i[2].mNode.mPrev;
    if ( v5 )
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v5);
    while ( (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)i[1].mNode.mNext != &i[1] )
    {
      v6 = i[1].mNode.mNext;
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = v6;
      v6->mNext = v6;
      Illusion::IRenderQueuePlat::Execute((Illusion::IRenderQueuePlat *)&v6[1], &context_param);
    }
  }
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::~CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>(&context_param.mInputLayoutCache.mLocalCache);
  while ( context_param.mConstantBufferValues.mTree.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&context_param.mConstantBufferValues);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&context_param.mConstantBufferValues,
      &Head->mNode);
    operator delete[](Head);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&context_param.mConstantBufferValues);
}

// File Line: 904
// RVA: 0xA17BA0
void Illusion::RenderQueuePlat::ClearFlushedRenderPhases(void)
{
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *i; // rax
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *mPrev; // rdx
  UFG::qNode<Illusion::RenderPhase,Illusion::RenderPhase> *mNext; // rcx

  for ( i = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext;
        (UFG::qList<Illusion::RenderPhase,Illusion::RenderPhase,1,0> *)Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext != &Illusion::RenderQueuePlat::mFlushedRenderPhases;
        i = Illusion::RenderQueuePlat::mFlushedRenderPhases.mNode.mNext )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
  }
}

