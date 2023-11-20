// File Line: 64
// RVA: 0x15AA6B0
__int64 Illusion::_dynamic_initializer_for__gShaderSystemPlat__()
{
  unk_14249AF60.mObj = (Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *)&Illusion::gShaderSystemPlat;
  UFG::qMutex::qMutex(&stru_14249AF68, &customWorldMapCaption);
  return atexit(Illusion::_dynamic_atexit_destructor_for__gShaderSystemPlat__);
}

// File Line: 77
// RVA: 0xA22190
void __fastcall Illusion::SetShaderParam_Texture(Illusion::TaskRenderEnv *env, Illusion::Shader *__formal, Illusion::ShaderParam *shader_param, void *data)
{
  _DWORD *v4; // rbx

  if ( data )
  {
    v4 = data;
    Illusion::TaskRenderEnv::SetTexture(env, shader_param, (Illusion::Texture *)data);
    v4[31] = Illusion::gEngine.mFrameCount;
  }
}

// File Line: 87
// RVA: 0xA22170
void __fastcall Illusion::SetShaderParam_RawBlock(Illusion::TaskRenderEnv *env, Illusion::Shader *__formal, Illusion::ShaderParam *shader_param, void *data)
{
  Illusion::TaskRenderEnv::SetConstBuffer(env, shader_param, data);
}

// File Line: 93
// RVA: 0xA22180
void __fastcall Illusion::SetShaderParam_StateBlock(Illusion::TaskRenderEnv *env, Illusion::Shader *__formal, Illusion::ShaderParam *shader_param, void *data)
{
  Illusion::TaskRenderEnv::SetConstBuffer_StateBlock(env, shader_param, (char *)data + 128);
}

// File Line: 99
// RVA: 0xA22130
void __fastcall Illusion::SetShaderParam_Buffer(Illusion::TaskRenderEnv *env, Illusion::Shader *shader, Illusion::ShaderParam *shader_param, void *data)
{
  __int64 v4; // rax

  if ( data )
  {
    *((_DWORD *)data + 30) = Illusion::gEngine.mFrameCount;
    v4 = *((_QWORD *)data + 23);
    if ( v4 )
      env->mCurrState.mComputeResources[shader_param->mComputeBufferSlot] = *(ID3D11ShaderResourceView **)(v4 + 120);
    else
      env->mAbortNextDraw = 1;
  }
}

// File Line: 119
// RVA: 0xA221C0
void __fastcall Illusion::SetShaderParam_UAV(Illusion::TaskRenderEnv *env, Illusion::Shader *shader, Illusion::ShaderParam *shader_param, void *data)
{
  if ( data )
    env->mCurrState.mComputeUAVs[shader_param->mComputeUAVSlot] = **(ID3D11UnorderedAccessView ***)data;
}

// File Line: 148
// RVA: 0xA1B610
void __fastcall Illusion::IShaderPlat::Init(Illusion::IShaderPlat *this)
{
  __int64 v1; // rax

  v1 = *(_QWORD *)&this[1216];
  if ( v1 )
    Illusion::ShaderUserPlat::Init((Illusion::ShaderUserPlat *)&this[v1 + 1216], (Illusion::Shader *)this);
  else
    Illusion::ShaderUserPlat::Init(0i64, (Illusion::Shader *)this);
}

// File Line: 155
// RVA: 0xA17D70
void __fastcall Illusion::IShaderPlat::Close(Illusion::IShaderPlat *this)
{
  Illusion::IShaderPlat *v1; // rbx
  Illusion::IShaderPlat *v2; // rbp
  __int64 v3; // rax
  AMD_HD3D *v4; // rcx
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *v5; // rax
  Illusion::StageShader **v6; // rbx
  signed __int64 v7; // rsi
  Illusion::StageShader *v8; // rdi
  __int64 *v9; // rbx
  __int64 v10; // rcx
  _QWORD *v11; // rax
  __int64 v12; // rcx
  __int64 v13; // rcx
  _QWORD *v14; // rax
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor result; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = this + 1168;
  v3 = *(_QWORD *)&this[1216];
  if ( v3 )
    v4 = (AMD_HD3D *)&this[v3 + 1216];
  else
    v4 = 0i64;
  _(v4);
  v5 = UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>>::operator->(
         &unk_14249AF60,
         &result);
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::RemoveObject(
    v5->mObj,
    (Illusion::Shader *)v1);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)result.mLock.mMutex);
  v6 = (Illusion::StageShader **)v2;
  v7 = 6i64;
  do
  {
    v8 = *v6;
    if ( *v6 )
    {
      Illusion::StageShader::~StageShader(*v6);
      operator delete[](v8);
      *v6 = 0i64;
    }
    ++v6;
    --v7;
  }
  while ( v7 );
  while ( *(Illusion::IShaderPlat **)&v2[64] != &v2[56] )
  {
    v9 = *(__int64 **)&v2[64];
    v10 = *v9;
    v11 = (_QWORD *)v9[1];
    *(_QWORD *)(v10 + 8) = v11;
    *v11 = v10;
    *v9 = (__int64)v9;
    v9[1] = (__int64)v9;
    v12 = v9[15];
    if ( v12 )
    {
      (*(void (__cdecl **)(__int64))(*(_QWORD *)v12 + 16i64))(v12);
      v9[15] = 0i64;
    }
    v13 = *v9;
    v14 = (_QWORD *)v9[1];
    *(_QWORD *)(v13 + 8) = v14;
    *v14 = v13;
    *v9 = (__int64)v9;
    v9[1] = (__int64)v9;
    operator delete[](v9);
  }
}

// File Line: 172
// RVA: 0xA17340
void __fastcall Illusion::IShaderPlat::AddShaderStage(Illusion::IShaderPlat *this, Illusion::ShaderBinary *shader_stage_binary)
{
  Illusion::ShaderBinary *v2; // rbx
  Illusion::IShaderPlat *v3; // rbp
  UFG::allocator::free_link *v4; // rax
  char *v5; // rsi
  Illusion::StageShader *v6; // rax
  Illusion::StageShader *v7; // rdi
  __int64 v8; // rax

  v2 = shader_stage_binary;
  v3 = this;
  v4 = UFG::qMalloc(0x1B8ui64, UFG::gGlobalNewName, 0i64);
  v5 = 0i64;
  if ( v4 )
  {
    Illusion::StageShader::StageShader((Illusion::StageShader *)v4);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v2->mData.mOffset;
  if ( v8 )
    v5 = (char *)&v2->mData + v8;
  if ( Illusion::StageShader::LoadShader(v7, v5, v2->mDataByteSize, (Illusion::Shader::StageType)v2->mShaderStageType) )
  {
    *(_QWORD *)&v3[8 * v2->mShaderStageType + 1168] = v7;
    Illusion::ShaderSystemPlat::AddStageShaderResources(&Illusion::gShaderSystemPlat, (Illusion::Shader *)v3, v7);
    Illusion::ShaderSystemPlat::ValidShaderStageInputs(&Illusion::gShaderSystemPlat, (Illusion::Shader *)v3);
  }
  else
  {
    UFG::qPrintf("Warning: couldnt create shader stage %s, hw may not support the feature level.\n", v2->mDebugName);
  }
}

// File Line: 214
// RVA: 0xA17190
Illusion::ShaderParam *__fastcall Illusion::AddShaderParam(Illusion::Shader *shader, const char *state_param_name, int num_bytes, void (__fastcall *pull_function)(Illusion::TaskRenderEnv *, Illusion::Shader *, Illusion::ShaderParam *, void *))
{
  void (__fastcall *v4)(Illusion::TaskRenderEnv *, Illusion::Shader *, Illusion::ShaderParam *, void *); // r15
  int v5; // er12
  const char *v6; // r14
  Illusion::Shader *v7; // rdi
  int v8; // ebp
  Illusion::ShaderParam *result; // rax
  Illusion::ShaderParam *v10; // rsi
  UFG::allocator::free_link *v11; // rax
  Illusion::ShaderParam *v12; // rbx
  UFG::qNode<Illusion::ShaderParam,Illusion::ShaderParam> *v13; // rax
  unsigned int v14; // ecx

  v4 = pull_function;
  v5 = num_bytes;
  v6 = state_param_name;
  v7 = shader;
  if ( !num_bytes || !state_param_name || !pull_function )
    return 0i64;
  v8 = UFG::qStringHash32(state_param_name, 0xFFFFFFFF);
  result = *(Illusion::ShaderParam **)&v7[1].mDebugName[20];
  v10 = (Illusion::ShaderParam *)&v7[1].mDebugName[12];
  if ( result == (Illusion::ShaderParam *)&v7[1].mDebugName[12] )
  {
LABEL_7:
    v11 = UFG::qMalloc(0x90ui64, "ShaderParam", 0x800ui64);
    v12 = (Illusion::ShaderParam *)v11;
    if ( v11 )
    {
      v11->mNext = v11;
      v11[1].mNext = v11;
      LODWORD(v11[2].mNext) = v8;
      LODWORD(v11[3].mNext) = 0;
      v11[4].mNext = 0i64;
      LOBYTE(v11[5].mNext) = 0;
      *(UFG::allocator::free_link **)((char *)&v11[5].mNext + 4) = (UFG::allocator::free_link *)-1i64;
      *(UFG::allocator::free_link **)((char *)&v11[6].mNext + 4) = (UFG::allocator::free_link *)-1i64;
      *(UFG::allocator::free_link **)((char *)&v11[7].mNext + 4) = (UFG::allocator::free_link *)-1i64;
      *(UFG::allocator::free_link **)((char *)&v11[8].mNext + 4) = (UFG::allocator::free_link *)-1i64;
      *(UFG::allocator::free_link **)((char *)&v11[9].mNext + 4) = (UFG::allocator::free_link *)-1i64;
      *(UFG::allocator::free_link **)((char *)&v11[10].mNext + 4) = (UFG::allocator::free_link *)-1i64;
      *(UFG::allocator::free_link **)((char *)&v11[11].mNext + 4) = (UFG::allocator::free_link *)-1i64;
      *(UFG::allocator::free_link **)((char *)&v11[12].mNext + 4) = (UFG::allocator::free_link *)-1i64;
      *(UFG::allocator::free_link **)((char *)&v11[13].mNext + 4) = (UFG::allocator::free_link *)-1i64;
      v11[15].mNext = 0i64;
      LODWORD(v11[16].mNext) = 0;
      *(UFG::allocator::free_link **)((char *)&v11[16].mNext + 4) = (UFG::allocator::free_link *)-1i64;
    }
    else
    {
      v12 = 0i64;
    }
    v12->mNumBytes = v5;
    v12->mPullFunction = v4;
    Illusion::StateSystem::AddParam(&Illusion::gStateSystem, (Illusion::StateParam *)&v12->mNameUID, v6, 0);
    v13 = v10->mPrev;
    v13->mNext = (UFG::qNode<Illusion::ShaderParam,Illusion::ShaderParam> *)&v12->mPrev;
    v12->mPrev = v13;
    v12->mNext = (UFG::qNode<Illusion::ShaderParam,Illusion::ShaderParam> *)&v10->mPrev;
    v10->mPrev = (UFG::qNode<Illusion::ShaderParam,Illusion::ShaderParam> *)&v12->mPrev;
    v7->mShaderParam[v12->mParamIndex] = v12;
    v14 = v12->mParamIndex;
    if ( v14 >= 0x40 )
      v7->mShaderParamInputMask.mFlags[1] |= 1i64 << ((unsigned __int8)v14 - 64);
    else
      v7->mShaderParamInputMask.mFlags[0] |= 1i64 << v14;
    result = v12;
  }
  else
  {
    while ( result->mNameUID != v8 )
    {
      result = (Illusion::ShaderParam *)result->mNext;
      if ( result == v10 )
        goto LABEL_7;
    }
  }
  return result;
}

// File Line: 263
// RVA: 0xA17410
void __fastcall Illusion::ShaderSystemPlat::AddStageShaderResources(Illusion::ShaderSystemPlat *this, Illusion::Shader *shader, Illusion::StageShader *stageShader)
{
  int v3; // er12
  Illusion::StageShader *v4; // r15
  __int64 v5; // r13
  __int64 v6; // rbp
  void (__fastcall *v7)(Illusion::TaskRenderEnv *, Illusion::Shader *, Illusion::ShaderParam *, void *); // rbx
  Illusion::ShaderResourceInfo *v8; // rdi
  int v9; // er14
  const char *v10; // rsi
  unsigned int v11; // edx
  UFG::qBaseTreeRB *v12; // rax
  __int64 *v13; // rax
  Illusion::ShaderParam *v14; // rax
  Illusion::ShaderParam *v15; // rbx
  Illusion::Shader::StageType v16; // eax
  int v17; // edx
  _D3D_SHADER_INPUT_TYPE v18; // ecx
  int v19; // ecx
  _D3D_SHADER_INPUT_TYPE v20; // ecx
  int v21; // ecx
  _D3D_SHADER_INPUT_TYPE v22; // ecx
  int v23; // ecx
  _D3D_SHADER_INPUT_TYPE v24; // ecx
  int v25; // ecx
  _D3D_SHADER_INPUT_TYPE v26; // ecx
  int v27; // ecx
  __int64 dest; // [rsp+20h] [rbp-58h]
  int v29; // [rsp+28h] [rbp-50h]
  Illusion::Shader *shadera; // [rsp+88h] [rbp+10h]
  __int64 v31; // [rsp+90h] [rbp+18h]

  shadera = shader;
  v3 = 0;
  v4 = stageShader;
  if ( stageShader->mResourceCount > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = 0i64;
      v7 = 0i64;
      v8 = &v4->mResourceInfo[v5];
      v9 = 8;
      v10 = v8->mBindDesc.Name;
      switch ( v8->mBindDesc.Type )
      {
        case 0:
          v11 = v8->mNameHash;
          v31 = 0i64;
          if ( v11 && (v12 = UFG::qBaseTreeRB::Get(&v4->mConstBufByName.mTree.mTree, v11)) != 0i64 )
            v13 = (__int64 *)&v12->mNULL;
          else
            v13 = &v31;
          v6 = *v13;
          if ( *v13 )
            v9 = *(_DWORD *)(v6 + 32);
          if ( !strncmp(v10, "sb", 2ui64) )
          {
            v7 = Illusion::SetShaderParam_StateBlock;
          }
          else if ( !strncmp(v10, "cb", 2ui64) )
          {
            v7 = Illusion::SetShaderParam_RawBlock;
          }
          break;
        case 2:
          v7 = Illusion::SetShaderParam_Texture;
          break;
        case 3:
          ++v10;
          v7 = Illusion::SetShaderParam_Texture;
          break;
        case 4:
        case 6:
        case 8:
        case 9:
        case 0xA:
        case 0xB:
          v7 = Illusion::SetShaderParam_UAV;
          break;
        case 5:
        case 7:
          v7 = Illusion::SetShaderParam_Buffer;
          break;
        default:
          break;
      }
      v14 = Illusion::AddShaderParam(shadera, v10, v9, v7);
      v15 = v14;
      v14->mIsResource = 1;
      if ( v8->mBindDesc.Type == D3D10_SIT_CBUFFER && !v14->mConstantBuffer )
      {
        UFG::qMemSet(&dest, 0, 0x18u);
        dest = *(unsigned int *)(v6 + 32);
        v29 = 4;
        ((void (__fastcall *)(ID3D11Device *, __int64 *, _QWORD, ID3D11Buffer **, __int64, _QWORD))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
          UFG::gD3D11Device,
          &dest,
          0i64,
          &v15->mConstantBuffer,
          dest,
          *(_QWORD *)&v29);
      }
      v16 = v4->mStage;
      v17 = v8->mBindDesc.BindPoint;
      if ( v16 == 1 )
      {
        v18 = v8->mBindDesc.Type;
        if ( v18 )
        {
          v19 = v18 - 2;
          if ( v19 )
          {
            if ( v19 == 1 )
              v15->mPixelSamplerSlot = v17;
          }
          else
          {
            v15->mPixelTextureSlot = v17;
          }
        }
        else
        {
          v15->mPixelConstantSlot = v17;
        }
      }
      else if ( v16 )
      {
        switch ( v16 )
        {
          case 2:
            switch ( v8->mBindDesc.Type )
            {
              case 0:
                v15->mComputeConstantSlot = v17;
                break;
              case 2:
                v15->mComputeTextureSlot = v17;
                break;
              case 3:
                v15->mComputeSamplerSlot = v17;
                break;
              case 4:
              case 6:
              case 8:
              case 9:
              case 0xA:
              case 0xB:
                v15->mComputeUAVSlot = v17;
                break;
              case 5:
              case 7:
                v15->mComputeBufferSlot = v17;
                break;
              default:
                goto LABEL_63;
            }
            break;
          case 3:
            v22 = v8->mBindDesc.Type;
            if ( v22 )
            {
              v23 = v22 - 2;
              if ( v23 )
              {
                if ( v23 == 1 )
                  v15->mGeometrySamplerSlot = v17;
              }
              else
              {
                v15->mGeometryTextureSlot = v17;
              }
            }
            else
            {
              v15->mGeometryConstantSlot = v17;
            }
            break;
          case 4:
            v24 = v8->mBindDesc.Type;
            if ( v24 )
            {
              v25 = v24 - 2;
              if ( v25 )
              {
                if ( v25 == 1 )
                  v15->mHullSamplerSlot = v17;
              }
              else
              {
                v15->mHullTextureSlot = v17;
              }
            }
            else
            {
              v15->mHullConstantSlot = v17;
            }
            break;
          case 5:
            v26 = v8->mBindDesc.Type;
            if ( v26 )
            {
              v27 = v26 - 2;
              if ( v27 )
              {
                if ( v27 == 1 )
                  v15->mDomainSamplerSlot = v17;
              }
              else
              {
                v15->mDomainTextureSlot = v17;
              }
            }
            else
            {
              v15->mDomainConstantSlot = v17;
            }
            break;
        }
      }
      else
      {
        v20 = v8->mBindDesc.Type;
        if ( v20 )
        {
          v21 = v20 - 2;
          if ( v21 )
          {
            if ( v21 == 1 )
              v15->mVertexSamplerSlot = v17;
          }
          else
          {
            v15->mVertexTextureSlot = v17;
          }
        }
        else
        {
          v15->mVertexConstantSlot = v17;
        }
      }
LABEL_63:
      ++v3;
      ++v5;
    }
    while ( v3 < v4->mResourceCount );
  }
}

// File Line: 486
// RVA: 0xA22C80
void __usercall Illusion::ShaderSystemPlat::ValidShaderStageInputs(Illusion::ShaderSystemPlat *this@<rcx>, Illusion::Shader *shader@<rdx>, __int64 a3@<rdi>, __int64 a4@<r14>, __int64 a5@<r15>)
{
  Illusion::Shader *v5; // r12
  UFG::qBaseNodeRB *v6; // r13
  unsigned int v7; // esi
  unsigned int v8; // ebp
  __int64 v9; // r14
  __int64 v10; // r15
  char *v11; // rdi
  const char *v12; // rbx
  _QWORD *v13; // rax
  const char **v14; // r8
  const char *v15; // rax
  signed __int64 v16; // rbx
  int v17; // ecx
  int v18; // edx
  __int64 v19; // [rsp+20h] [rbp-38h]
  __int64 v20; // [rsp+28h] [rbp-30h]
  __int64 v21; // [rsp+30h] [rbp-28h]
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v22; // [rsp+68h] [rbp+10h]
  UFG::qBaseNodeRB *v23; // [rsp+70h] [rbp+18h]
  _QWORD *v24; // [rsp+78h] [rbp+20h]

  v5 = shader;
  v6 = shader[1].mNode.mChild[1];
  v22 = shader[1].mResourceHandles.mNode.mPrev;
  v24 = *(_QWORD **)&shader[1].mTypeUID;
  v23 = shader[1].mNode.mChild[0];
  if ( v23 )
  {
    if ( v6 )
    {
      v7 = 0;
      v8 = 0;
      if ( SLODWORD(v6[7].mChild[0]) > 0 )
      {
        v21 = a3;
        v20 = a4;
        v19 = a5;
        v9 = 0i64;
        v10 = 0i64;
        do
        {
          v11 = (char *)v6[7].mChild[1] + v10;
          v12 = *(const char **)v11;
          if ( strcmp(*(const char **)v11, "SV_IsFrontFace") )
          {
            v13 = &v22->mPrev;
            if ( !v22 )
            {
              v13 = &v23->mParent;
              if ( v24 )
                v13 = v24;
            }
            if ( (signed int)v7 < *((_DWORD *)v13 + 62) )
            {
              v14 = (const char **)(v9 + v13[32]);
              if ( !v14 )
                goto LABEL_27;
              v15 = *v14;
              if ( !*v14 || !v12 )
                goto LABEL_27;
              v16 = v12 - v15;
              do
              {
                v17 = (unsigned __int8)v15[v16];
                v18 = *(unsigned __int8 *)v15 - v17;
                if ( *(unsigned __int8 *)v15 != v17 )
                  break;
                ++v15;
              }
              while ( v17 );
              if ( v18
                || *((_DWORD *)v14 + 2) != *((_DWORD *)v11 + 2)
                || *((_DWORD *)v14 + 3) != *((_DWORD *)v11 + 3)
                || *((_DWORD *)v14 + 4) != *((_DWORD *)v11 + 4)
                || *((_DWORD *)v14 + 5) != *((_DWORD *)v11 + 5)
                || *((_BYTE *)v14 + 24) != v11[24] )
              {
LABEL_27:
                UFG::qPrintf(
                  "ERROR: Pixel shader input %d doesnt match previous stage shader output %d for %s\n",
                  v8,
                  v7,
                  v5->mDebugName,
                  v19,
                  v20,
                  v21);
              }
            }
            ++v7;
            v9 += 40i64;
          }
          ++v8;
          v10 += 40i64;
        }
        while ( (signed int)v8 < SLODWORD(v6[7].mChild[0]) );
      }
    }
  }
}

// File Line: 564
// RVA: 0xA15A40
void __fastcall Illusion::StageShader::StageShader(Illusion::StageShader *this)
{
  Illusion::StageShader *v1; // rbx

  v1 = this;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mConstBufByName.mTree.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mResourceByName.mTree.mTree);
  v1->mRawShader = 0i64;
  v1->mRawShaderSize = 0;
  v1->mStage = 99;
  v1->mPixelShader = 0i64;
  v1->mVertexShader = 0i64;
  v1->mComputeShader = 0i64;
  v1->mGeometryShader = 0i64;
  v1->mHullShader = 0i64;
  v1->mDomainShader = 0i64;
  v1->mReflection = 0i64;
  v1->mInputCount = 0;
  v1->mInputInfo = 0i64;
  v1->mOutputCount = 0;
  v1->mOutputInfo = 0i64;
  v1->mConstBufCount = 0;
  v1->mConstBufInfo = 0i64;
  v1->mResourceCount = 0;
  v1->mResourceInfo = 0i64;
  memset(&v1->mShaderDesc, 0, 0xA0ui64);
}

// File Line: 570
// RVA: 0xA16860
void __fastcall Illusion::StageShader::~StageShader(Illusion::StageShader *this)
{
  Illusion::StageShader *v1; // rsi
  Render::SkinningCacheNode *v2; // rbx
  Render::SkinningCacheNode *v3; // rbx

  v1 = this;
  Illusion::StageShader::ReleaseResources(this);
  while ( v1->mResourceByName.mTree.mTree.mCount )
  {
    v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mResourceByName);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mResourceByName,
      &v2->mNode);
    operator delete[](v2);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mResourceByName);
  while ( v1->mConstBufByName.mTree.mTree.mCount )
  {
    v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mConstBufByName);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mConstBufByName,
      &v3->mNode);
    operator delete[](v3);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mConstBufByName);
}

// File Line: 601
// RVA: 0xA21000
void __fastcall Illusion::StageShader::ReleaseResources(Illusion::StageShader *this)
{
  Illusion::StageShader *v1; // rdi
  ID3D11PixelShader *v2; // rcx
  ID3D11VertexShader *v3; // rcx
  ID3D11ComputeShader *v4; // rcx
  ID3D11GeometryShader *v5; // rcx
  ID3D11HullShader *v6; // rcx
  ID3D11DomainShader *v7; // rcx
  ID3D11ShaderReflection *v8; // rcx
  Illusion::ShaderParamInfo *v9; // rcx
  Illusion::ShaderParamInfo *v10; // rcx
  Illusion::ShaderConstBufInfo *v11; // rcx
  Illusion::ShaderConstBufInfo::VarInfo **v12; // rbx
  Illusion::ShaderResourceInfo *v13; // rcx

  v1 = this;
  v2 = this->mPixelShader;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->mPixelShader = 0i64;
  }
  v3 = v1->mVertexShader;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v1->mVertexShader = 0i64;
  }
  v4 = v1->mComputeShader;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr->Release)();
    v1->mComputeShader = 0i64;
  }
  v5 = v1->mGeometryShader;
  if ( v5 )
  {
    ((void (*)(void))v5->vfptr->Release)();
    v1->mGeometryShader = 0i64;
  }
  v6 = v1->mHullShader;
  if ( v6 )
  {
    ((void (*)(void))v6->vfptr->Release)();
    v1->mHullShader = 0i64;
  }
  v7 = v1->mDomainShader;
  if ( v7 )
  {
    ((void (*)(void))v7->vfptr->Release)();
    v1->mDomainShader = 0i64;
  }
  v8 = v1->mReflection;
  if ( v8 )
  {
    ((void (*)(void))v8->vfptr->Release)();
    v1->mReflection = 0i64;
  }
  v9 = v1->mInputInfo;
  if ( v9 )
  {
    operator delete[](v9);
    v1->mInputInfo = 0i64;
  }
  v10 = v1->mOutputInfo;
  if ( v10 )
  {
    operator delete[](v10);
    v1->mOutputInfo = 0i64;
  }
  v11 = v1->mConstBufInfo;
  if ( v11 )
  {
    v12 = &v11[-1].mVarInfo;
    `eh vector destructor iterator(
      v11,
      0x38ui64,
      (int)v11[-1].mVarInfo,
      (void (__fastcall *)(void *))Illusion::ShaderConstBufInfo::~ShaderConstBufInfo);
    operator delete[](v12);
    v1->mConstBufInfo = 0i64;
  }
  v13 = v1->mResourceInfo;
  if ( v13 )
  {
    operator delete[](v13);
    v1->mResourceInfo = 0i64;
  }
  v1->mRawShader = 0i64;
  v1->mRawShaderSize = 0;
  v1->mStage = 99;
  v1->mPixelShader = 0i64;
  v1->mVertexShader = 0i64;
  v1->mComputeShader = 0i64;
  v1->mGeometryShader = 0i64;
  v1->mHullShader = 0i64;
  v1->mDomainShader = 0i64;
  v1->mReflection = 0i64;
  v1->mInputCount = 0;
  v1->mInputInfo = 0i64;
  v1->mOutputCount = 0;
  v1->mOutputInfo = 0i64;
  v1->mConstBufCount = 0;
  v1->mConstBufInfo = 0i64;
  v1->mResourceCount = 0;
  v1->mResourceInfo = 0i64;
  memset(&v1->mShaderDesc, 0, 0xA0ui64);
}

// File Line: 620
// RVA: 0xA1BE00
char __fastcall Illusion::StageShader::LoadShader(Illusion::StageShader *this, void *bin, int size, Illusion::Shader::StageType stageType)
{
  Illusion::Shader::StageType v4; // er13
  __int64 v5; // rdi
  char *v6; // rsi
  Illusion::StageShader *v7; // rbx
  ID3D11ShaderReflection **v8; // r14
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // kr00_8
  unsigned int v12; // edi
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // kr10_8
  unsigned int v16; // edi
  unsigned __int64 v17; // rax
  int v18; // esi
  signed __int64 v19; // rax
  unsigned __int64 v20; // kr20_8
  unsigned __int8 v21; // cf
  unsigned __int64 v22; // rax
  UFG::allocator::free_link *v23; // rax
  signed __int64 v24; // rdi
  int v25; // er12
  __int64 v26; // r13
  Illusion::ShaderConstBufInfo *v27; // rsi
  __int64 v28; // r15
  unsigned __int64 v29; // rcx
  unsigned __int64 v30; // rax
  unsigned int v31; // edi
  signed __int64 v32; // rbp
  __int64 v33; // r14
  signed int (__fastcall ***v34)(_QWORD, signed __int64); // rax
  unsigned int v35; // eax
  unsigned int v36; // ebp
  UFG::qBaseNodeRB *v37; // rdi
  unsigned __int64 v38; // rcx
  unsigned __int64 v39; // rax
  int v40; // er14
  __int64 v41; // r15
  Illusion::ShaderResourceInfo *v42; // rbp
  unsigned int v43; // eax
  unsigned int v44; // esi
  UFG::qBaseNodeRB *v45; // rdi
  Illusion::Shader::StageType v47; // [rsp+88h] [rbp+20h]

  v47 = stageType;
  v4 = stageType;
  v5 = (unsigned int)size;
  v6 = (char *)bin;
  v7 = this;
  Illusion::StageShader::ReleaseResources(this);
  switch ( v4 )
  {
    case 0:
      if ( ((signed int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11VertexShader **))UFG::gD3D11Device->vfptr->IASetVertexBuffers)(
             UFG::gD3D11Device,
             v6,
             (signed int)v5,
             0i64,
             &v7->mVertexShader) >= 0 )
        goto LABEL_13;
      return 0;
    case 1:
      if ( ((signed int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11PixelShader **))UFG::gD3D11Device->vfptr->DrawInstanced)(
             UFG::gD3D11Device,
             v6,
             (signed int)v5,
             0i64,
             &v7->mPixelShader) < 0 )
        return 0;
      goto LABEL_13;
    case 2:
      if ( ((signed int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11ComputeShader **))UFG::gD3D11Device->vfptr->IASetPrimitiveTopology)(
             UFG::gD3D11Device,
             v6,
             (signed int)v5,
             0i64,
             &v7->mComputeShader) < 0 )
        return 0;
      goto LABEL_13;
    case 3:
      if ( ((signed int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11GeometryShader **))UFG::gD3D11Device->vfptr->IASetIndexBuffer)(
             UFG::gD3D11Device,
             v6,
             (signed int)v5,
             0i64,
             &v7->mGeometryShader) < 0 )
        return 0;
      goto LABEL_13;
    case 4:
      if ( ((signed int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11HullShader **))UFG::gD3D11Device->vfptr->GSSetConstantBuffers)(
             UFG::gD3D11Device,
             v6,
             (signed int)v5,
             0i64,
             &v7->mHullShader) < 0 )
        return 0;
      goto LABEL_13;
    case 5:
      if ( ((signed int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11DomainShader **))UFG::gD3D11Device->vfptr->GSSetShader)(
             UFG::gD3D11Device,
             v6,
             (signed int)v5,
             0i64,
             &v7->mDomainShader) < 0 )
        return 0;
LABEL_13:
      v7->mRawShader = v6;
      v7->mRawShaderSize = v5;
      v8 = &v7->mReflection;
      if ( (signed int)D3DReflect_0(v6, v5, &IID_ID3D11ShaderReflection, &v7->mReflection) < 0
        || ((signed int (__fastcall *)(ID3D11ShaderReflection *, _D3D11_SHADER_DESC *))(*v8)->vfptr[1].QueryInterface)(
             *v8,
             &v7->mShaderDesc) < 0 )
      {
        goto $D3D_ERROR_HANDLER_2;
      }
      v9 = (signed int)v7->mShaderDesc.InputParameters;
      v7->mInputCount = v9;
      if ( (signed int)v9 > 0 )
      {
        v11 = v9;
        v10 = 40 * v9;
        if ( !is_mul_ok(v11, 0x28ui64) )
          v10 = -1i64;
        v7->mInputInfo = (Illusion::ShaderParamInfo *)UFG::qMalloc(v10, "StageShader input descriptions", 0i64);
      }
      v12 = 0;
      if ( v7->mInputCount <= 0 )
        goto LABEL_22;
      break;
    default:
      return 0;
  }
  while ( ((signed int (__fastcall *)(ID3D11ShaderReflection *, _QWORD, Illusion::ShaderParamInfo *))(*v8)->vfptr[2].AddRef)(
            *v8,
            v12,
            &v7->mInputInfo[v12]) >= 0 )
  {
    if ( (signed int)++v12 >= v7->mInputCount )
    {
LABEL_22:
      v13 = (signed int)v7->mShaderDesc.OutputParameters;
      v7->mOutputCount = v13;
      if ( (signed int)v13 > 0 )
      {
        v15 = v13;
        v14 = 40 * v13;
        if ( !is_mul_ok(v15, 0x28ui64) )
          v14 = -1i64;
        v7->mOutputInfo = (Illusion::ShaderParamInfo *)UFG::qMalloc(v14, "StageShader output descriptions", 0i64);
      }
      v16 = 0;
      if ( v7->mOutputCount <= 0 )
      {
LABEL_29:
        v17 = (signed int)v7->mShaderDesc.ConstantBuffers;
        v7->mConstBufCount = v17;
        if ( (signed int)v17 > 0 )
        {
          v18 = v17;
          v20 = v17;
          v19 = 56 * v17;
          if ( !is_mul_ok(v20, 0x38ui64) )
            v19 = -1i64;
          v21 = __CFADD__(v19, 8i64);
          v22 = v19 + 8;
          if ( v21 )
            v22 = -1i64;
          v23 = UFG::qMalloc(v22, "ShaderStage constant info", 0i64);
          if ( v23 )
          {
            LODWORD(v23->mNext) = v18;
            v24 = (signed __int64)&v23[1];
            `eh vector constructor iterator(
              &v23[1],
              0x38ui64,
              v18,
              (void (__fastcall *)(void *))Illusion::ShaderConstBufInfo::ShaderConstBufInfo);
          }
          else
          {
            v24 = 0i64;
          }
          v7->mConstBufInfo = (Illusion::ShaderConstBufInfo *)v24;
        }
        v25 = 0;
        if ( v7->mConstBufCount <= 0 )
        {
LABEL_57:
          v38 = (signed int)v7->mShaderDesc.BoundResources;
          v7->mResourceCount = v38;
          if ( (signed int)v38 > 0 )
          {
            v39 = 56 * v38;
            if ( !is_mul_ok(v38, 0x38ui64) )
              v39 = -1i64;
            v7->mResourceInfo = (Illusion::ShaderResourceInfo *)UFG::qMalloc(v39, "ShaderStage resource info", 0i64);
          }
          v40 = 0;
          if ( v7->mResourceCount <= 0 )
          {
LABEL_71:
            v7->mStage = v4;
            return 1;
          }
          v41 = 0i64;
          while ( 1 )
          {
            v42 = &v7->mResourceInfo[v41];
            if ( v7->mReflection->vfptr[2].QueryInterface(
                   (IUnknown *)&v7->mReflection->vfptr,
                   (_GUID *)(unsigned int)v40,
                   (void **)&v42->mBindDesc) < 0 )
              break;
            v43 = UFG::qStringHash32(v42->mBindDesc.Name, 0xFFFFFFFF);
            v44 = v43;
            v42->mNameHash = v43;
            if ( !v43
              || (v45 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&v7->mResourceByName.mTree.mTree, v43)) == 0i64 )
            {
              v45 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
              if ( v45 )
              {
                v45->mParent = 0i64;
                v45->mChild[0] = 0i64;
                v45->mChild[1] = 0i64;
                v45->mUID = v44;
                v45[1].mParent = (UFG::qBaseNodeRB *)v42;
              }
              else
              {
                v45 = 0i64;
              }
              UFG::qBaseTreeRB::Add(&v7->mResourceByName.mTree.mTree, v45);
            }
            v45[1].mParent = (UFG::qBaseNodeRB *)v42;
            ++v40;
            ++v41;
            if ( v40 >= v7->mResourceCount )
              goto LABEL_71;
          }
        }
        else
        {
          v26 = 0i64;
          while ( 1 )
          {
            v27 = &v7->mConstBufInfo[v26];
            v28 = ((__int64 (__fastcall *)(ID3D11ShaderReflection *, _QWORD))(*v8)->vfptr[1].AddRef)(
                    *v8,
                    (unsigned int)v25);
            if ( (**(signed int (__fastcall ***)(__int64, signed __int64))v28)(v28, (signed __int64)&v27->mBufDesc) < 0 )
              break;
            v29 = (signed int)v27->mBufDesc.Variables;
            v27->mVarCount = v29;
            if ( (signed int)v29 > 0 )
            {
              v30 = 88 * v29;
              if ( !is_mul_ok(v29, 0x58ui64) )
                v30 = -1i64;
              v27->mVarInfo = (Illusion::ShaderConstBufInfo::VarInfo *)UFG::qMalloc(
                                                                         v30,
                                                                         "ShaderStage variable info",
                                                                         0i64);
            }
            v31 = 0;
            if ( v27->mVarCount > 0 )
            {
              do
              {
                v32 = (signed __int64)&v27->mVarInfo[v31];
                v33 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v28 + 8i64))(v28, v31);
                if ( (**(signed int (__fastcall ***)(__int64, signed __int64))v33)(v33, v32) < 0 )
                  goto $D3D_ERROR_HANDLER_2;
                v34 = (signed int (__fastcall ***)(_QWORD, signed __int64))(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v33 + 8i64))(v33);
                if ( (**v34)(v34, v32 + 48) < 0 )
                  goto $D3D_ERROR_HANDLER_2;
              }
              while ( (signed int)++v31 < v27->mVarCount );
            }
            v35 = UFG::qStringHash32(v27->mBufDesc.Name, 0xFFFFFFFF);
            v36 = v35;
            v27->mNameHash = v35;
            if ( !v35
              || (v37 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&v7->mConstBufByName.mTree.mTree, v35)) == 0i64 )
            {
              v37 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
              if ( v37 )
              {
                v37->mParent = 0i64;
                v37->mChild[0] = 0i64;
                v37->mChild[1] = 0i64;
                v37->mUID = v36;
                v37[1].mParent = (UFG::qBaseNodeRB *)v27;
              }
              else
              {
                v37 = 0i64;
              }
              UFG::qBaseTreeRB::Add(&v7->mConstBufByName.mTree.mTree, v37);
            }
            v37[1].mParent = (UFG::qBaseNodeRB *)v27;
            ++v25;
            ++v26;
            v8 = &v7->mReflection;
            if ( v25 >= v7->mConstBufCount )
            {
              v4 = v47;
              goto LABEL_57;
            }
          }
        }
      }
      else
      {
        while ( ((signed int (__fastcall *)(ID3D11ShaderReflection *, _QWORD, Illusion::ShaderParamInfo *))(*v8)->vfptr[2].Release)(
                  *v8,
                  v16,
                  &v7->mOutputInfo[v16]) >= 0 )
        {
          if ( (signed int)++v16 >= v7->mOutputCount )
            goto LABEL_29;
        }
      }
      break;
    }
  }
$D3D_ERROR_HANDLER_2:
  Illusion::StageShader::ReleaseResources(v7);
  return 0;
}

