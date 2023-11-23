// File Line: 64
// RVA: 0x15AA6B0
__int64 Illusion::_dynamic_initializer_for__gShaderSystemPlat__()
{
  unk_14249AF60.mObj = (Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *)&Illusion::gShaderSystemPlat;
  UFG::qMutex::qMutex(&stru_14249AF68, &customCaption);
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gShaderSystemPlat__);
}

// File Line: 77
// RVA: 0xA22190
void __fastcall Illusion::SetShaderParam_Texture(
        Illusion::TaskRenderEnv *env,
        Illusion::Shader *__formal,
        Illusion::ShaderParam *shader_param,
        Illusion::Texture *data)
{
  if ( data )
  {
    Illusion::TaskRenderEnv::SetTexture(env, shader_param, data);
    data->mLastUsedFrameNum = Illusion::gEngine.mFrameCount;
  }
}

// File Line: 87
// RVA: 0xA22170
void __fastcall Illusion::SetShaderParam_RawBlock(
        Illusion::TaskRenderEnv *env,
        Illusion::Shader *__formal,
        Illusion::ShaderParam *shader_param,
        void *data)
{
  Illusion::TaskRenderEnv::SetConstBuffer(env, shader_param, data);
}

// File Line: 93
// RVA: 0xA22180
void __fastcall Illusion::SetShaderParam_StateBlock(
        Illusion::TaskRenderEnv *env,
        Illusion::Shader *__formal,
        Illusion::ShaderParam *shader_param,
        char *data)
{
  Illusion::TaskRenderEnv::SetConstBuffer_StateBlock(env, shader_param, data + 128);
}

// File Line: 99
// RVA: 0xA22130
void __fastcall Illusion::SetShaderParam_Buffer(
        Illusion::TaskRenderEnv *env,
        Illusion::Shader *shader,
        Illusion::ShaderParam *shader_param,
        _DWORD *data)
{
  __int64 v4; // rax

  if ( data )
  {
    data[30] = Illusion::gEngine.mFrameCount;
    v4 = *((_QWORD *)data + 23);
    if ( v4 )
      env->mCurrState.mComputeResources[shader_param->mComputeBufferSlot] = *(ID3D11ShaderResourceView **)(v4 + 120);
    else
      env->mAbortNextDraw = 1;
  }
}

// File Line: 119
// RVA: 0xA221C0
void __fastcall Illusion::SetShaderParam_UAV(
        Illusion::TaskRenderEnv *env,
        Illusion::Shader *shader,
        Illusion::ShaderParam *shader_param,
        ID3D11UnorderedAccessView ***data)
{
  if ( data )
    env->mCurrState.mComputeUAVs[shader_param->mComputeUAVSlot] = **data;
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
  Illusion::IShaderPlat *v2; // rbp
  __int64 v3; // rax
  AMD_HD3D *v4; // rcx
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *v5; // rax
  Illusion::StageShader **v6; // rbx
  __int64 v7; // rsi
  Illusion::StageShader *v8; // rdi
  __int64 *v9; // rbx
  __int64 v10; // rcx
  _QWORD *v11; // rax
  __int64 v12; // rcx
  __int64 v13; // rcx
  _QWORD *v14; // rax
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor result; // [rsp+28h] [rbp-30h] BYREF

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
    (Illusion::Shader *)this);
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
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v12 + 16i64))(v12);
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
void __fastcall Illusion::IShaderPlat::AddShaderStage(
        Illusion::IShaderPlat *this,
        Illusion::ShaderBinary *shader_stage_binary)
{
  UFG::allocator::free_link *v4; // rax
  char *v5; // rsi
  Illusion::StageShader *v6; // rax
  Illusion::StageShader *v7; // rdi
  __int64 mOffset; // rax

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
  mOffset = shader_stage_binary->mData.mOffset;
  if ( mOffset )
    v5 = (char *)&shader_stage_binary->mData + mOffset;
  if ( Illusion::StageShader::LoadShader(
         v7,
         v5,
         shader_stage_binary->mDataByteSize,
         (Illusion::Shader::StageType)shader_stage_binary->mShaderStageType) )
  {
    *(_QWORD *)&this[8 * shader_stage_binary->mShaderStageType + 1168] = v7;
    Illusion::ShaderSystemPlat::AddStageShaderResources(&Illusion::gShaderSystemPlat, (Illusion::Shader *)this, v7);
    Illusion::ShaderSystemPlat::ValidShaderStageInputs(&Illusion::gShaderSystemPlat, (Illusion::Shader *)this);
  }
  else
  {
    UFG::qPrintf(
      "Warning: couldnt create shader stage %s, hw may not support the feature level.\n",
      shader_stage_binary->mDebugName);
  }
}

// File Line: 214
// RVA: 0xA17190
Illusion::ShaderParam *__fastcall Illusion::AddShaderParam(
        Illusion::Shader *shader,
        const char *state_param_name,
        int num_bytes,
        void (__fastcall *pull_function)(Illusion::TaskRenderEnv *, Illusion::Shader *, Illusion::ShaderParam *, void *))
{
  int v8; // ebp
  Illusion::ShaderParam *result; // rax
  Illusion::ShaderParam *v10; // rsi
  UFG::allocator::free_link *v11; // rax
  __int16 *v12; // rbx
  UFG::qNode<Illusion::ShaderParam,Illusion::ShaderParam> *mPrev; // rax
  unsigned int v14; // ecx

  if ( !num_bytes || !state_param_name || !pull_function )
    return 0i64;
  v8 = UFG::qStringHash32(state_param_name, 0xFFFFFFFF);
  result = *(Illusion::ShaderParam **)&shader[1].mDebugName[20];
  v10 = (Illusion::ShaderParam *)&shader[1].mDebugName[12];
  if ( result == (Illusion::ShaderParam *)&shader[1].mDebugName[12] )
  {
LABEL_7:
    v11 = UFG::qMalloc(0x90ui64, "ShaderParam", 0x800ui64);
    v12 = (__int16 *)v11;
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
    *((_DWORD *)v12 + 32) = num_bytes;
    *((_QWORD *)v12 + 4) = pull_function;
    Illusion::StateSystem::AddParam(&Illusion::gStateSystem, (Illusion::StateParam *)(v12 + 8), state_param_name, 0);
    mPrev = v10->mPrev;
    mPrev->mNext = (UFG::qNode<Illusion::ShaderParam,Illusion::ShaderParam> *)v12;
    *(_QWORD *)v12 = mPrev;
    *((_QWORD *)v12 + 1) = v10;
    v10->mPrev = (UFG::qNode<Illusion::ShaderParam,Illusion::ShaderParam> *)v12;
    shader->mShaderParam[v12[12]] = v12;
    v14 = v12[12];
    if ( v14 >= 0x40 )
      shader->mShaderParamInputMask.mFlags[1] |= 1i64 << ((unsigned __int8)v14 - 64);
    else
      shader->mShaderParamInputMask.mFlags[0] |= 1i64 << v14;
    return (Illusion::ShaderParam *)v12;
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
void __fastcall Illusion::ShaderSystemPlat::AddStageShaderResources(
        Illusion::ShaderSystemPlat *this,
        Illusion::Shader *shader,
        Illusion::StageShader *stageShader)
{
  int v3; // r12d
  __int64 v5; // r13
  __int64 v6; // rbp
  void (__fastcall *v7)(Illusion::TaskRenderEnv *, Illusion::Shader *, Illusion::ShaderParam *, void *); // rbx
  Illusion::ShaderResourceInfo *v8; // rdi
  int v9; // r14d
  const char *Name; // rsi
  unsigned int mNameHash; // edx
  UFG::qBaseTreeRB *v12; // rax
  __int64 *p_mNULL; // rax
  Illusion::ShaderParam *v14; // rax
  Illusion::ShaderParam *v15; // rbx
  Illusion::Shader::StageType mStage; // eax
  unsigned int BindPoint; // edx
  _D3D_SHADER_INPUT_TYPE Type; // ecx
  __int32 v19; // ecx
  _D3D_SHADER_INPUT_TYPE v20; // ecx
  __int32 v21; // ecx
  _D3D_SHADER_INPUT_TYPE v22; // ecx
  __int32 v23; // ecx
  _D3D_SHADER_INPUT_TYPE v24; // ecx
  __int32 v25; // ecx
  _D3D_SHADER_INPUT_TYPE v26; // ecx
  __int32 v27; // ecx
  __int64 dest; // [rsp+20h] [rbp-58h] BYREF
  int v29; // [rsp+28h] [rbp-50h]
  __int64 v31; // [rsp+90h] [rbp+18h] BYREF

  v3 = 0;
  if ( stageShader->mResourceCount > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = 0i64;
      v7 = 0i64;
      v8 = &stageShader->mResourceInfo[v5];
      v9 = 8;
      Name = v8->mBindDesc.Name;
      switch ( v8->mBindDesc.Type )
      {
        case D3D10_SIT_CBUFFER:
          mNameHash = v8->mNameHash;
          v31 = 0i64;
          if ( mNameHash && (v12 = UFG::qBaseTreeRB::Get(&stageShader->mConstBufByName.mTree.mTree, mNameHash)) != 0i64 )
            p_mNULL = (__int64 *)&v12->mNULL;
          else
            p_mNULL = &v31;
          v6 = *p_mNULL;
          if ( *p_mNULL )
            v9 = *(_DWORD *)(v6 + 32);
          if ( !strncmp(Name, "sb", 2ui64) )
          {
            v7 = Illusion::SetShaderParam_StateBlock;
          }
          else if ( !strncmp(Name, "cb", 2ui64) )
          {
            v7 = Illusion::SetShaderParam_RawBlock;
          }
          break;
        case D3D10_SIT_TEXTURE:
          v7 = Illusion::SetShaderParam_Texture;
          break;
        case D3D10_SIT_SAMPLER:
          ++Name;
          v7 = Illusion::SetShaderParam_Texture;
          break;
        case D3D11_SIT_UAV_RWTYPED:
        case D3D11_SIT_UAV_RWSTRUCTURED:
        case D3D11_SIT_UAV_RWBYTEADDRESS:
        case D3D11_SIT_UAV_APPEND_STRUCTURED:
        case D3D11_SIT_UAV_CONSUME_STRUCTURED:
        case D3D11_SIT_UAV_RWSTRUCTURED_WITH_COUNTER:
          v7 = Illusion::SetShaderParam_UAV;
          break;
        case D3D11_SIT_STRUCTURED:
        case D3D11_SIT_BYTEADDRESS:
          v7 = Illusion::SetShaderParam_Buffer;
          break;
        default:
          break;
      }
      v14 = Illusion::AddShaderParam(shader, Name, v9, v7);
      v15 = v14;
      v14->mIsResource = 1;
      if ( v8->mBindDesc.Type == D3D10_SIT_CBUFFER && !v14->mConstantBuffer )
      {
        UFG::qMemSet(&dest, 0, 0x18u);
        dest = *(unsigned int *)(v6 + 32);
        v29 = 4;
        ((void (__fastcall *)(ID3D11Device *, __int64 *, _QWORD, ID3D11Buffer **))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
          UFG::gD3D11Device,
          &dest,
          0i64,
          &v15->mConstantBuffer);
      }
      mStage = stageShader->mStage;
      BindPoint = v8->mBindDesc.BindPoint;
      if ( mStage == STAGE_PIXEL )
      {
        Type = v8->mBindDesc.Type;
        if ( Type )
        {
          v19 = Type - 2;
          if ( v19 )
          {
            if ( v19 == 1 )
              v15->mPixelSamplerSlot = BindPoint;
          }
          else
          {
            v15->mPixelTextureSlot = BindPoint;
          }
        }
        else
        {
          v15->mPixelConstantSlot = BindPoint;
        }
      }
      else if ( mStage )
      {
        switch ( mStage )
        {
          case STAGE_COMPUTE:
            switch ( v8->mBindDesc.Type )
            {
              case D3D10_SIT_CBUFFER:
                v15->mComputeConstantSlot = BindPoint;
                break;
              case D3D10_SIT_TEXTURE:
                v15->mComputeTextureSlot = BindPoint;
                break;
              case D3D10_SIT_SAMPLER:
                v15->mComputeSamplerSlot = BindPoint;
                break;
              case D3D11_SIT_UAV_RWTYPED:
              case D3D11_SIT_UAV_RWSTRUCTURED:
              case D3D11_SIT_UAV_RWBYTEADDRESS:
              case D3D11_SIT_UAV_APPEND_STRUCTURED:
              case D3D11_SIT_UAV_CONSUME_STRUCTURED:
              case D3D11_SIT_UAV_RWSTRUCTURED_WITH_COUNTER:
                v15->mComputeUAVSlot = BindPoint;
                break;
              case D3D11_SIT_STRUCTURED:
              case D3D11_SIT_BYTEADDRESS:
                v15->mComputeBufferSlot = BindPoint;
                break;
              default:
                goto LABEL_63;
            }
            break;
          case STAGE_GEOMETRY:
            v22 = v8->mBindDesc.Type;
            if ( v22 )
            {
              v23 = v22 - 2;
              if ( v23 )
              {
                if ( v23 == 1 )
                  v15->mGeometrySamplerSlot = BindPoint;
              }
              else
              {
                v15->mGeometryTextureSlot = BindPoint;
              }
            }
            else
            {
              v15->mGeometryConstantSlot = BindPoint;
            }
            break;
          case STAGE_HULL:
            v24 = v8->mBindDesc.Type;
            if ( v24 )
            {
              v25 = v24 - 2;
              if ( v25 )
              {
                if ( v25 == 1 )
                  v15->mHullSamplerSlot = BindPoint;
              }
              else
              {
                v15->mHullTextureSlot = BindPoint;
              }
            }
            else
            {
              v15->mHullConstantSlot = BindPoint;
            }
            break;
          case STAGE_DOMAIN:
            v26 = v8->mBindDesc.Type;
            if ( v26 )
            {
              v27 = v26 - 2;
              if ( v27 )
              {
                if ( v27 == 1 )
                  v15->mDomainSamplerSlot = BindPoint;
              }
              else
              {
                v15->mDomainTextureSlot = BindPoint;
              }
            }
            else
            {
              v15->mDomainConstantSlot = BindPoint;
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
              v15->mVertexSamplerSlot = BindPoint;
          }
          else
          {
            v15->mVertexTextureSlot = BindPoint;
          }
        }
        else
        {
          v15->mVertexConstantSlot = BindPoint;
        }
      }
LABEL_63:
      ++v3;
      ++v5;
    }
    while ( v3 < stageShader->mResourceCount );
  }
}

// File Line: 486
// RVA: 0xA22C80
void __fastcall Illusion::ShaderSystemPlat::ValidShaderStageInputs(
        Illusion::ShaderSystemPlat *this,
        Illusion::Shader *shader)
{
  UFG::qBaseNodeRB *v3; // r13
  unsigned int v4; // esi
  unsigned int v5; // ebp
  __int64 v6; // r14
  __int64 v7; // r15
  char *v8; // rdi
  const char *v9; // rbx
  _QWORD *p_mPrev; // rax
  const char **v11; // r8
  const char *v12; // rax
  signed __int64 v13; // rbx
  int v14; // ecx
  int v15; // edx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // [rsp+68h] [rbp+10h]
  UFG::qBaseNodeRB *v17; // [rsp+70h] [rbp+18h]
  _QWORD *v18; // [rsp+78h] [rbp+20h]

  v3 = shader[1].mNode.mChild[1];
  mPrev = shader[1].mResourceHandles.UFG::qResourceData::mNode.mPrev;
  v18 = *(_QWORD **)&shader[1].mTypeUID;
  v17 = shader[1].mNode.mChild[0];
  if ( v17 )
  {
    if ( v3 )
    {
      v4 = 0;
      v5 = 0;
      if ( SLODWORD(v3[7].mChild[0]) > 0 )
      {
        v6 = 0i64;
        v7 = 0i64;
        do
        {
          v8 = (char *)v3[7].mChild[1] + v7;
          v9 = *(const char **)v8;
          if ( strcmp(*(const char **)v8, "SV_IsFrontFace") )
          {
            p_mPrev = &mPrev->mPrev;
            if ( !mPrev )
            {
              p_mPrev = &v17->mParent;
              if ( v18 )
                p_mPrev = v18;
            }
            if ( (signed int)v4 < *((_DWORD *)p_mPrev + 62) )
            {
              v11 = (const char **)(v6 + p_mPrev[32]);
              if ( !v11 )
                goto LABEL_22;
              v12 = *v11;
              if ( !*v11 || !v9 )
                goto LABEL_22;
              v13 = v9 - v12;
              do
              {
                v14 = (unsigned __int8)v12[v13];
                v15 = *(unsigned __int8 *)v12 - v14;
                if ( v15 )
                  break;
                ++v12;
              }
              while ( v14 );
              if ( v15
                || *((_DWORD *)v11 + 2) != *((_DWORD *)v8 + 2)
                || *((_DWORD *)v11 + 3) != *((_DWORD *)v8 + 3)
                || *((_DWORD *)v11 + 4) != *((_DWORD *)v8 + 4)
                || *((_DWORD *)v11 + 5) != *((_DWORD *)v8 + 5)
                || *((_BYTE *)v11 + 24) != v8[24] )
              {
LABEL_22:
                UFG::qPrintf(
                  "ERROR: Pixel shader input %d doesnt match previous stage shader output %d for %s\n",
                  v5,
                  v4,
                  shader->mDebugName);
              }
            }
            ++v4;
            v6 += 40i64;
          }
          ++v5;
          v7 += 40i64;
        }
        while ( (signed int)v5 < SLODWORD(v3[7].mChild[0]) );
      }
    }
  }
}

// File Line: 564
// RVA: 0xA15A40
void __fastcall Illusion::StageShader::StageShader(Illusion::StageShader *this)
{
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mConstBufByName.mTree.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mResourceByName.mTree.mTree);
  this->mRawShader = 0i64;
  this->mRawShaderSize = 0;
  this->mStage = STAGE_INVALID;
  this->mPixelShader = 0i64;
  this->mVertexShader = 0i64;
  this->mComputeShader = 0i64;
  this->mGeometryShader = 0i64;
  this->mHullShader = 0i64;
  this->mDomainShader = 0i64;
  this->mReflection = 0i64;
  this->mInputCount = 0;
  this->mInputInfo = 0i64;
  this->mOutputCount = 0;
  this->mOutputInfo = 0i64;
  this->mConstBufCount = 0;
  this->mConstBufInfo = 0i64;
  this->mResourceCount = 0;
  this->mResourceInfo = 0i64;
  memset(&this->mShaderDesc, 0, sizeof(this->mShaderDesc));
}

// File Line: 570
// RVA: 0xA16860
void __fastcall Illusion::StageShader::~StageShader(Illusion::StageShader *this)
{
  Render::SkinningCacheNode *Head; // rbx
  Render::SkinningCacheNode *v3; // rbx

  Illusion::StageShader::ReleaseResources(this);
  while ( this->mResourceByName.mTree.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mResourceByName);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mResourceByName,
      &Head->mNode);
    operator delete[](Head);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mResourceByName);
  while ( this->mConstBufByName.mTree.mTree.mCount )
  {
    v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mConstBufByName);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mConstBufByName,
      &v3->mNode);
    operator delete[](v3);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mConstBufByName);
}

// File Line: 601
// RVA: 0xA21000
void __fastcall Illusion::StageShader::ReleaseResources(Illusion::StageShader *this)
{
  ID3D11PixelShader *mPixelShader; // rcx
  ID3D11VertexShader *mVertexShader; // rcx
  ID3D11ComputeShader *mComputeShader; // rcx
  ID3D11GeometryShader *mGeometryShader; // rcx
  ID3D11HullShader *mHullShader; // rcx
  ID3D11DomainShader *mDomainShader; // rcx
  ID3D11ShaderReflection *mReflection; // rcx
  Illusion::ShaderParamInfo *mInputInfo; // rcx
  Illusion::ShaderParamInfo *mOutputInfo; // rcx
  Illusion::ShaderConstBufInfo *mConstBufInfo; // rcx
  Illusion::ShaderConstBufInfo::VarInfo **p_mVarInfo; // rbx
  Illusion::ShaderResourceInfo *mResourceInfo; // rcx

  mPixelShader = this->mPixelShader;
  if ( mPixelShader )
  {
    mPixelShader->vfptr->Release(mPixelShader);
    this->mPixelShader = 0i64;
  }
  mVertexShader = this->mVertexShader;
  if ( mVertexShader )
  {
    mVertexShader->vfptr->Release(mVertexShader);
    this->mVertexShader = 0i64;
  }
  mComputeShader = this->mComputeShader;
  if ( mComputeShader )
  {
    mComputeShader->vfptr->Release(mComputeShader);
    this->mComputeShader = 0i64;
  }
  mGeometryShader = this->mGeometryShader;
  if ( mGeometryShader )
  {
    mGeometryShader->vfptr->Release(mGeometryShader);
    this->mGeometryShader = 0i64;
  }
  mHullShader = this->mHullShader;
  if ( mHullShader )
  {
    mHullShader->vfptr->Release(mHullShader);
    this->mHullShader = 0i64;
  }
  mDomainShader = this->mDomainShader;
  if ( mDomainShader )
  {
    mDomainShader->vfptr->Release(mDomainShader);
    this->mDomainShader = 0i64;
  }
  mReflection = this->mReflection;
  if ( mReflection )
  {
    mReflection->vfptr->Release(mReflection);
    this->mReflection = 0i64;
  }
  mInputInfo = this->mInputInfo;
  if ( mInputInfo )
  {
    operator delete[](mInputInfo);
    this->mInputInfo = 0i64;
  }
  mOutputInfo = this->mOutputInfo;
  if ( mOutputInfo )
  {
    operator delete[](mOutputInfo);
    this->mOutputInfo = 0i64;
  }
  mConstBufInfo = this->mConstBufInfo;
  if ( mConstBufInfo )
  {
    p_mVarInfo = &mConstBufInfo[-1].mVarInfo;
    `eh vector destructor iterator(
      mConstBufInfo,
      0x38ui64,
      (int)mConstBufInfo[-1].mVarInfo,
      (void (__fastcall *)(void *))Illusion::ShaderConstBufInfo::~ShaderConstBufInfo);
    operator delete[](p_mVarInfo);
    this->mConstBufInfo = 0i64;
  }
  mResourceInfo = this->mResourceInfo;
  if ( mResourceInfo )
  {
    operator delete[](mResourceInfo);
    this->mResourceInfo = 0i64;
  }
  this->mRawShader = 0i64;
  this->mRawShaderSize = 0;
  this->mStage = STAGE_INVALID;
  this->mPixelShader = 0i64;
  this->mVertexShader = 0i64;
  this->mComputeShader = 0i64;
  this->mGeometryShader = 0i64;
  this->mHullShader = 0i64;
  this->mDomainShader = 0i64;
  this->mReflection = 0i64;
  this->mInputCount = 0;
  this->mInputInfo = 0i64;
  this->mOutputCount = 0;
  this->mOutputInfo = 0i64;
  this->mConstBufCount = 0;
  this->mConstBufInfo = 0i64;
  this->mResourceCount = 0;
  this->mResourceInfo = 0i64;
  memset(&this->mShaderDesc, 0, sizeof(this->mShaderDesc));
}

// File Line: 620
// RVA: 0xA1BE00
char __fastcall Illusion::StageShader::LoadShader(
        Illusion::StageShader *this,
        char *bin,
        unsigned int size,
        Illusion::Shader::StageType stageType)
{
  Illusion::Shader::StageType v4; // r13d
  __int64 v5; // rdi
  ID3D11ShaderReflection **p_mReflection; // r14
  unsigned __int64 InputParameters; // rax
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // kr00_8
  unsigned int v12; // edi
  unsigned __int64 OutputParameters; // rax
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // kr10_8
  unsigned int v16; // edi
  unsigned __int64 ConstantBuffers; // rax
  int v18; // esi
  __int64 v19; // rax
  unsigned __int64 v20; // kr20_8
  bool v21; // cf
  unsigned __int64 v22; // rax
  UFG::allocator::free_link *v23; // rax
  Illusion::ShaderConstBufInfo *v24; // rdi
  int v25; // r12d
  __int64 v26; // r13
  Illusion::ShaderConstBufInfo *v27; // rsi
  __int64 v28; // r15
  unsigned __int64 Variables; // rcx
  unsigned __int64 v30; // rax
  unsigned int v31; // edi
  __int64 v32; // rbp
  __int64 v33; // r14
  int (__fastcall ***v34)(_QWORD, __int64); // rax
  unsigned int v35; // eax
  unsigned int v36; // ebp
  UFG::qBaseNodeRB *v37; // rdi
  unsigned __int64 BoundResources; // rcx
  unsigned __int64 v39; // rax
  int v40; // r14d
  __int64 v41; // r15
  Illusion::ShaderResourceInfo *v42; // rbp
  unsigned int v43; // eax
  unsigned int v44; // esi
  UFG::qBaseNodeRB *v45; // rdi

  v4 = stageType;
  v5 = size;
  Illusion::StageShader::ReleaseResources(this);
  switch ( v4 )
  {
    case STAGE_VERTEX:
      if ( ((int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11VertexShader **))UFG::gD3D11Device->vfptr->IASetVertexBuffers)(
             UFG::gD3D11Device,
             bin,
             (int)v5,
             0i64,
             &this->mVertexShader) >= 0 )
        goto LABEL_13;
      return 0;
    case STAGE_PIXEL:
      if ( ((int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11PixelShader **))UFG::gD3D11Device->vfptr->DrawInstanced)(
             UFG::gD3D11Device,
             bin,
             (int)v5,
             0i64,
             &this->mPixelShader) < 0 )
        return 0;
      goto LABEL_13;
    case STAGE_COMPUTE:
      if ( ((int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11ComputeShader **))UFG::gD3D11Device->vfptr->IASetPrimitiveTopology)(
             UFG::gD3D11Device,
             bin,
             (int)v5,
             0i64,
             &this->mComputeShader) < 0 )
        return 0;
      goto LABEL_13;
    case STAGE_GEOMETRY:
      if ( ((int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11GeometryShader **))UFG::gD3D11Device->vfptr->IASetIndexBuffer)(
             UFG::gD3D11Device,
             bin,
             (int)v5,
             0i64,
             &this->mGeometryShader) < 0 )
        return 0;
      goto LABEL_13;
    case STAGE_HULL:
      if ( ((int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11HullShader **))UFG::gD3D11Device->vfptr->GSSetConstantBuffers)(
             UFG::gD3D11Device,
             bin,
             (int)v5,
             0i64,
             &this->mHullShader) < 0 )
        return 0;
      goto LABEL_13;
    case STAGE_DOMAIN:
      if ( ((int (__fastcall *)(ID3D11Device *, char *, _QWORD, _QWORD, ID3D11DomainShader **))UFG::gD3D11Device->vfptr->GSSetShader)(
             UFG::gD3D11Device,
             bin,
             (int)v5,
             0i64,
             &this->mDomainShader) < 0 )
        return 0;
LABEL_13:
      this->mRawShader = bin;
      this->mRawShaderSize = v5;
      p_mReflection = &this->mReflection;
      if ( (int)D3DReflect_0(bin, v5, &IID_ID3D11ShaderReflection, &this->mReflection) < 0
        || ((int (__fastcall *)(ID3D11ShaderReflection *, _D3D11_SHADER_DESC *))(*p_mReflection)->vfptr[1].QueryInterface)(
             *p_mReflection,
             &this->mShaderDesc) < 0 )
      {
        goto $D3D_ERROR_HANDLER_2;
      }
      InputParameters = (int)this->mShaderDesc.InputParameters;
      this->mInputCount = InputParameters;
      if ( (int)InputParameters > 0 )
      {
        v11 = InputParameters;
        v10 = 40 * InputParameters;
        if ( !is_mul_ok(v11, 0x28ui64) )
          v10 = -1i64;
        this->mInputInfo = (Illusion::ShaderParamInfo *)UFG::qMalloc(v10, "StageShader input descriptions", 0i64);
      }
      v12 = 0;
      if ( this->mInputCount <= 0 )
        goto LABEL_22;
      break;
    default:
      return 0;
  }
  while ( ((int (__fastcall *)(ID3D11ShaderReflection *, _QWORD, Illusion::ShaderParamInfo *))(*p_mReflection)->vfptr[2].AddRef)(
            *p_mReflection,
            v12,
            &this->mInputInfo[v12]) >= 0 )
  {
    if ( (signed int)++v12 >= this->mInputCount )
    {
LABEL_22:
      OutputParameters = (int)this->mShaderDesc.OutputParameters;
      this->mOutputCount = OutputParameters;
      if ( (int)OutputParameters > 0 )
      {
        v15 = OutputParameters;
        v14 = 40 * OutputParameters;
        if ( !is_mul_ok(v15, 0x28ui64) )
          v14 = -1i64;
        this->mOutputInfo = (Illusion::ShaderParamInfo *)UFG::qMalloc(v14, "StageShader output descriptions", 0i64);
      }
      v16 = 0;
      if ( this->mOutputCount <= 0 )
      {
LABEL_29:
        ConstantBuffers = (int)this->mShaderDesc.ConstantBuffers;
        this->mConstBufCount = ConstantBuffers;
        if ( (int)ConstantBuffers > 0 )
        {
          v18 = ConstantBuffers;
          v20 = ConstantBuffers;
          v19 = 56 * ConstantBuffers;
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
            v24 = (Illusion::ShaderConstBufInfo *)&v23[1];
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
          this->mConstBufInfo = v24;
        }
        v25 = 0;
        if ( this->mConstBufCount <= 0 )
        {
LABEL_57:
          BoundResources = (int)this->mShaderDesc.BoundResources;
          this->mResourceCount = BoundResources;
          if ( (int)BoundResources > 0 )
          {
            v39 = 56 * BoundResources;
            if ( !is_mul_ok(BoundResources, 0x38ui64) )
              v39 = -1i64;
            this->mResourceInfo = (Illusion::ShaderResourceInfo *)UFG::qMalloc(v39, "ShaderStage resource info", 0i64);
          }
          v40 = 0;
          if ( this->mResourceCount <= 0 )
          {
LABEL_71:
            this->mStage = v4;
            return 1;
          }
          v41 = 0i64;
          while ( 1 )
          {
            v42 = &this->mResourceInfo[v41];
            if ( this->mReflection->vfptr[2].QueryInterface(
                   this->mReflection,
                   (_GUID *)(unsigned int)v40,
                   (void **)&v42->mBindDesc) < 0 )
              break;
            v43 = UFG::qStringHash32(v42->mBindDesc.Name, 0xFFFFFFFF);
            v44 = v43;
            v42->mNameHash = v43;
            if ( !v43
              || (v45 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&this->mResourceByName.mTree.mTree, v43)) == 0i64 )
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
              UFG::qBaseTreeRB::Add(&this->mResourceByName.mTree.mTree, v45);
            }
            v45[1].mParent = (UFG::qBaseNodeRB *)v42;
            ++v40;
            ++v41;
            if ( v40 >= this->mResourceCount )
              goto LABEL_71;
          }
        }
        else
        {
          v26 = 0i64;
          while ( 1 )
          {
            v27 = &this->mConstBufInfo[v26];
            v28 = ((__int64 (__fastcall *)(ID3D11ShaderReflection *, _QWORD))(*p_mReflection)->vfptr[1].AddRef)(
                    *p_mReflection,
                    (unsigned int)v25);
            if ( (**(int (__fastcall ***)(__int64, __int64))v28)(v28, (__int64)&v27->mBufDesc) < 0 )
              break;
            Variables = (int)v27->mBufDesc.Variables;
            v27->mVarCount = Variables;
            if ( (int)Variables > 0 )
            {
              v30 = 88 * Variables;
              if ( !is_mul_ok(Variables, 0x58ui64) )
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
                v32 = (__int64)&v27->mVarInfo[v31];
                v33 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v28 + 8i64))(v28, v31);
                if ( (**(int (__fastcall ***)(__int64, __int64))v33)(v33, v32) < 0 )
                  goto $D3D_ERROR_HANDLER_2;
                v34 = (int (__fastcall ***)(_QWORD, __int64))(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v33 + 8i64))(v33);
                if ( (**v34)(v34, v32 + 48) < 0 )
                  goto $D3D_ERROR_HANDLER_2;
              }
              while ( (signed int)++v31 < v27->mVarCount );
            }
            v35 = UFG::qStringHash32(v27->mBufDesc.Name, 0xFFFFFFFF);
            v36 = v35;
            v27->mNameHash = v35;
            if ( !v35
              || (v37 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&this->mConstBufByName.mTree.mTree, v35)) == 0i64 )
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
              UFG::qBaseTreeRB::Add(&this->mConstBufByName.mTree.mTree, v37);
            }
            v37[1].mParent = (UFG::qBaseNodeRB *)v27;
            ++v25;
            ++v26;
            p_mReflection = &this->mReflection;
            if ( v25 >= this->mConstBufCount )
            {
              v4 = stageType;
              goto LABEL_57;
            }
          }
        }
      }
      else
      {
        while ( ((int (__fastcall *)(ID3D11ShaderReflection *, _QWORD, Illusion::ShaderParamInfo *))(*p_mReflection)->vfptr[2].Release)(
                  *p_mReflection,
                  v16,
                  &this->mOutputInfo[v16]) >= 0 )
        {
          if ( (signed int)++v16 >= this->mOutputCount )
            goto LABEL_29;
        }
      }
      break;
    }
  }
$D3D_ERROR_HANDLER_2:
  Illusion::StageShader::ReleaseResources(this);
  return 0;
}

