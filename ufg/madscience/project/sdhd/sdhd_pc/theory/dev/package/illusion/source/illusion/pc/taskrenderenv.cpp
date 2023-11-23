// File Line: 70
// RVA: 0x15AA5C0
__int64 dynamic_initializer_for__Illusion::TaskRenderEnv::mStateBlockConstantBufferValues__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&Illusion::TaskRenderEnv::mStateBlockConstantBufferValues.mTree.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Illusion::TaskRenderEnv::mStateBlockConstantBufferValues__);
}

// File Line: 89
// RVA: 0xA20250
void __fastcall Illusion::D3DContextState::PushStateDelta(
        Illusion::D3DContextState *this,
        ID3D11DeviceContext *context,
        Illusion::D3DContextState *prevState)
{
  IUnknownVtbl *vfptr; // rax
  IUnknownVtbl *v7; // rax
  IUnknownVtbl *v8; // rax
  IUnknownVtbl *v9; // rax
  IUnknownVtbl *v10; // rax
  char v11; // r14
  IUnknownVtbl *v12; // rax
  IUnknownVtbl *v13; // rax
  IUnknownVtbl *v14; // rax
  IUnknownVtbl *v15; // rax
  IUnknownVtbl *v16; // rax
  __int64 v17; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v18; // [rsp+38h] [rbp-C8h]
  __int64 v19; // [rsp+40h] [rbp-C0h]
  __int64 v20; // [rsp+48h] [rbp-B8h]
  __int64 v21; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v22; // [rsp+58h] [rbp-A8h]
  __int64 v23; // [rsp+60h] [rbp-A0h]
  __int64 v24; // [rsp+68h] [rbp-98h]
  __int128 v25; // [rsp+70h] [rbp-90h] BYREF
  __int128 v26; // [rsp+80h] [rbp-80h]
  __int128 v27; // [rsp+90h] [rbp-70h]
  __int128 v28; // [rsp+A0h] [rbp-60h]
  __int128 v29[6]; // [rsp+B0h] [rbp-50h] BYREF

  if ( this->mInComputePipeline != prevState->mInComputePipeline )
  {
    vfptr = context->vfptr;
    memset(v29, 0, sizeof(v29));
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, __int128 *))vfptr[8].AddRef)(
      context,
      0i64,
      12i64,
      v29);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, __int128 *))context->vfptr[2].Release)(
      context,
      0i64,
      12i64,
      v29);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, __int128 *))context->vfptr[10].AddRef)(
      context,
      0i64,
      12i64,
      v29);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, __int128 *))context->vfptr[19].Release)(
      context,
      0i64,
      12i64,
      v29);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, __int128 *))context->vfptr[21].QueryInterface)(
      context,
      0i64,
      12i64,
      v29);
    v7 = context->vfptr;
    v17 = 0i64;
    v18 = 0i64;
    v19 = 0i64;
    v20 = 0i64;
    ((void (__fastcall *)(ID3D11DeviceContext *, __int64, __int64 *, _QWORD))v7[11].QueryInterface)(
      context,
      4i64,
      &v17,
      0i64);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, __int128 *))context->vfptr[22].AddRef)(
      context,
      0i64,
      12i64,
      v29);
    v8 = context->vfptr;
    v25 = 0i64;
    v26 = 0i64;
    v27 = 0i64;
    v28 = 0i64;
    v21 = -1i64;
    v22 = -1i64;
    v23 = -1i64;
    v24 = -1i64;
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, __int128 *, __int64 *))v8[22].Release)(
      context,
      0i64,
      8i64,
      &v25,
      &v21);
  }
  if ( this->mInComputePipeline )
  {
    if ( this->mComputeShader != prevState->mComputeShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11ComputeShader *, _QWORD, _QWORD))context->vfptr[23].QueryInterface)(
        context,
        this->mComputeShader,
        0i64,
        0i64);
    if ( memcmp(this->mComputeConstantBuffers, prevState->mComputeConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11Buffer **))context->vfptr[23].Release)(
        context,
        0i64,
        8i64,
        this->mComputeConstantBuffers);
    if ( memcmp(this->mComputeResources, prevState->mComputeResources, 0x60ui64) )
    {
      if ( memcmp(this->mComputeUAVs, prevState->mComputeUAVs, 0x40ui64) )
      {
        v9 = context->vfptr;
        v25 = 0i64;
        v26 = 0i64;
        v27 = 0i64;
        v28 = 0i64;
        v21 = -1i64;
        v22 = -1i64;
        v23 = -1i64;
        v24 = -1i64;
        ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, __int128 *, __int64 *))v9[22].Release)(
          context,
          0i64,
          8i64,
          &v25,
          &v21);
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11ShaderResourceView **))context->vfptr[22].AddRef)(
        context,
        0i64,
        12i64,
        this->mComputeResources);
    }
    if ( memcmp(this->mComputeSamplers, prevState->mComputeSamplers, 0x60ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11SamplerState **))context->vfptr[23].AddRef)(
        context,
        0i64,
        12i64,
        this->mComputeSamplers);
    if ( memcmp(this->mComputeUAVs, prevState->mComputeUAVs, 0x40ui64) )
    {
      v10 = context->vfptr;
      v21 = 0i64;
      v22 = 0i64;
      v23 = 0i64;
      v24 = 0i64;
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11UnorderedAccessView **, __int64 *))v10[22].Release)(
        context,
        0i64,
        8i64,
        this->mComputeUAVs,
        &v21);
    }
  }
  else
  {
    if ( this->mInputLayout != prevState->mInputLayout )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11InputLayout *))context->vfptr[5].Release)(
        context,
        this->mInputLayout);
    if ( this->mIndexBuffer != prevState->mIndexBuffer
      || *(_DWORD *)this->mIndexBufferFormat != *(_DWORD *)prevState->mIndexBufferFormat
      || this->mIndexBufferOffset != prevState->mIndexBufferOffset )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Buffer *, _QWORD, _QWORD))context->vfptr[6].AddRef)(
        context,
        this->mIndexBuffer,
        *(unsigned int *)this->mIndexBufferFormat,
        this->mIndexBufferOffset);
    }
    if ( memcmp(this->mVertexBuffers, prevState->mVertexBuffers, 0x40ui64)
      || memcmp(this->mVertexBufferStrides, prevState->mVertexBufferStrides, 0x20ui64)
      || memcmp(this->mVertexBufferOffsets, prevState->mVertexBufferOffsets, 0x20ui64) )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11Buffer **, unsigned int *, unsigned int *))context->vfptr[6].QueryInterface)(
        context,
        0i64,
        8i64,
        this->mVertexBuffers,
        this->mVertexBufferStrides,
        this->mVertexBufferOffsets);
    }
    if ( this->mPrimType != prevState->mPrimType )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD))context->vfptr[8].QueryInterface)(
        context,
        (unsigned int)this->mPrimType);
    if ( this->mVertexShader != prevState->mVertexShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11VertexShader *, _QWORD, _QWORD))context->vfptr[3].Release)(
        context,
        this->mVertexShader,
        0i64,
        0i64);
    if ( memcmp(this->mVertexConstantBuffers, prevState->mVertexConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11Buffer **))context->vfptr[2].AddRef)(
        context,
        0i64,
        8i64,
        this->mVertexConstantBuffers);
    v11 = 0;
    if ( memcmp(this->mVertexTextureResources, prevState->mVertexTextureResources, 0x60ui64) )
    {
      if ( memcmp(this->mRenderTargets, prevState->mRenderTargets, 0x20ui64)
        || this->mDepthStencilView != prevState->mDepthStencilView )
      {
        v12 = context->vfptr;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0i64;
        v20 = 0i64;
        v12[11].QueryInterface(context, (_GUID *)4, (void **)&v17);
        v11 = 1;
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11ShaderResourceView **))context->vfptr[8].AddRef)(
        context,
        0i64,
        12i64,
        this->mVertexTextureResources);
    }
    if ( memcmp(this->mVertexTextureSamplers, prevState->mVertexTextureSamplers, 0x60ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11SamplerState **))context->vfptr[8].Release)(
        context,
        0i64,
        12i64,
        this->mVertexTextureSamplers);
    if ( this->mPixelShader != prevState->mPixelShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11PixelShader *, _QWORD, _QWORD))context->vfptr[3].QueryInterface)(
        context,
        this->mPixelShader,
        0i64,
        0i64);
    if ( memcmp(this->mPixelConstantBuffers, prevState->mPixelConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11Buffer **))context->vfptr[5].AddRef)(
        context,
        0i64,
        8i64,
        this->mPixelConstantBuffers);
    if ( memcmp(this->mPixelTextureResources, prevState->mPixelTextureResources, 0x60ui64) )
    {
      if ( !v11
        && (memcmp(this->mRenderTargets, prevState->mRenderTargets, 0x20ui64)
         || this->mDepthStencilView != prevState->mDepthStencilView) )
      {
        v13 = context->vfptr;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0i64;
        v20 = 0i64;
        v13[11].QueryInterface(context, (_GUID *)4, (void **)&v17);
        v11 = 1;
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11ShaderResourceView **))context->vfptr[2].Release)(
        context,
        0i64,
        12i64,
        this->mPixelTextureResources);
    }
    if ( this->mPixelShader != prevState->mPixelShader
      || memcmp(this->mPixelTextureSamplers, prevState->mPixelTextureSamplers, 0x60ui64) )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11SamplerState **))context->vfptr[3].AddRef)(
        context,
        0i64,
        12i64,
        this->mPixelTextureSamplers);
    }
    if ( this->mGeometryShader != prevState->mGeometryShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11GeometryShader *, _QWORD, _QWORD))context->vfptr[7].Release)(
        context,
        this->mGeometryShader,
        0i64,
        0i64);
    if ( memcmp(this->mGeometryConstantBuffers, prevState->mGeometryConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11Buffer **))context->vfptr[7].AddRef)(
        context,
        0i64,
        8i64,
        this->mGeometryConstantBuffers);
    if ( memcmp(this->mGeometryTextureResources, prevState->mGeometryTextureResources, 0x60ui64) )
    {
      if ( !v11
        && (memcmp(this->mRenderTargets, prevState->mRenderTargets, 0x20ui64)
         || this->mDepthStencilView != prevState->mDepthStencilView) )
      {
        v14 = context->vfptr;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0i64;
        v20 = 0i64;
        v14[11].QueryInterface(context, (_GUID *)4, (void **)&v17);
        v11 = 1;
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11ShaderResourceView **))context->vfptr[10].AddRef)(
        context,
        0i64,
        12i64,
        this->mGeometryTextureResources);
    }
    if ( this->mGeometryShader != prevState->mGeometryShader
      || memcmp(this->mGeometryTextureSamplers, prevState->mGeometryTextureSamplers, 0x60ui64) )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11SamplerState **))context->vfptr[10].Release)(
        context,
        0i64,
        12i64,
        this->mGeometryTextureSamplers);
    }
    if ( this->mHullShader != prevState->mHullShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11HullShader *, _QWORD, _QWORD))context->vfptr[20].QueryInterface)(
        context,
        this->mHullShader,
        0i64,
        0i64);
    if ( memcmp(this->mHullConstantBuffers, prevState->mHullConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11Buffer **))context->vfptr[20].Release)(
        context,
        0i64,
        8i64,
        this->mHullConstantBuffers);
    if ( memcmp(this->mHullTextureResources, prevState->mHullTextureResources, 0x60ui64) )
    {
      if ( !v11
        && (memcmp(this->mRenderTargets, prevState->mRenderTargets, 0x20ui64)
         || this->mDepthStencilView != prevState->mDepthStencilView) )
      {
        v15 = context->vfptr;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0i64;
        v20 = 0i64;
        v15[11].QueryInterface(context, (_GUID *)4, (void **)&v17);
        v11 = 1;
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11ShaderResourceView **))context->vfptr[19].Release)(
        context,
        0i64,
        12i64,
        this->mHullTextureResources);
    }
    if ( this->mHullShader != prevState->mHullShader
      || memcmp(this->mHullTextureSamplers, prevState->mHullTextureSamplers, 0x60ui64) )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11SamplerState **))context->vfptr[20].AddRef)(
        context,
        0i64,
        12i64,
        this->mHullTextureSamplers);
    }
    if ( this->mDomainShader != prevState->mDomainShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11DomainShader *, _QWORD, _QWORD))context->vfptr[21].AddRef)(
        context,
        this->mDomainShader,
        0i64,
        0i64);
    if ( memcmp(this->mDomainConstantBuffers, prevState->mDomainConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11Buffer **))context->vfptr[22].QueryInterface)(
        context,
        0i64,
        8i64,
        this->mDomainConstantBuffers);
    if ( memcmp(this->mDomainTextureResources, prevState->mDomainTextureResources, 0x60ui64) )
    {
      if ( !v11
        && (memcmp(this->mRenderTargets, prevState->mRenderTargets, 0x20ui64)
         || this->mDepthStencilView != prevState->mDepthStencilView) )
      {
        v16 = context->vfptr;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0i64;
        v20 = 0i64;
        v16[11].QueryInterface(context, (_GUID *)4, (void **)&v17);
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11ShaderResourceView **))context->vfptr[21].QueryInterface)(
        context,
        0i64,
        12i64,
        this->mDomainTextureResources);
    }
    if ( this->mDomainShader != prevState->mDomainShader
      || memcmp(this->mDomainTextureSamplers, prevState->mDomainTextureSamplers, 0x60ui64) )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11SamplerState **))context->vfptr[21].Release)(
        context,
        0i64,
        12i64,
        this->mDomainTextureSamplers);
    }
    if ( this->mRasterizerState != prevState->mRasterizerState )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11RasterizerState *))context->vfptr[14].AddRef)(
        context,
        this->mRasterizerState);
    if ( *(_QWORD *)&this->mViewport.TopLeftX != *(_QWORD *)&prevState->mViewport.TopLeftX
      || *(_QWORD *)&this->mViewport.Width != *(_QWORD *)&prevState->mViewport.Width
      || *(_QWORD *)&this->mViewport.MinDepth != *(_QWORD *)&prevState->mViewport.MinDepth )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, __int64))context->vfptr[14].Release)(context, 1i64);
    }
    if ( *(_QWORD *)&this->mScissorRect.left != *(_QWORD *)&prevState->mScissorRect.left
      || *(_QWORD *)&this->mScissorRect.right != *(_QWORD *)&prevState->mScissorRect.right )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, __int64))context->vfptr[15].QueryInterface)(context, 1i64);
    }
    if ( memcmp(this->mRenderTargets, prevState->mRenderTargets, 0x20ui64)
      || this->mDepthStencilView != prevState->mDepthStencilView )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, __int64, ID3D11RenderTargetView **, ID3D11DepthStencilView *))context->vfptr[11].QueryInterface)(
        context,
        4i64,
        this->mRenderTargets,
        this->mDepthStencilView);
    }
    if ( this->mBlendState != prevState->mBlendState || this->mBlendStateMask != prevState->mBlendStateMask )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11BlendState *, GUID *, _QWORD))context->vfptr[11].Release)(
        context,
        this->mBlendState,
        &GUID_00000000_0000_0000_0000_000000000000,
        this->mBlendStateMask);
    if ( this->mDepthState != prevState->mDepthState || this->mDepthStateStencilRef != prevState->mDepthStateStencilRef )
      context->vfptr[12].QueryInterface(context, (_GUID *)this->mDepthState, (void **)this->mDepthStateStencilRef);
  }
} _QWORD))context->vfptr[11].Release)(
        context,
        this->mBlendState,
        &GUID_00000000_0000_0000_0000_000000000000,
        this->mBlendStateMask);
    if ( this->mDepthState != prevState->mDepthState || this->mDepthStateStencilRef != prevState->mDepthStateStencilRef )
      context->vfptr[12].QueryInterface(context, (_GUID *)this->mDepthState, (void **)this->mD

// File Line: 491
// RVA: 0xA15F70
void __fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::~CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>(
        Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this)
{
  int v1; // esi
  __int64 v3; // rdi
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *mElem; // rcx

  v1 = 0;
  if ( this->mCount > 0 )
  {
    v3 = 0i64;
    do
    {
      this->mElem[v3].mResult->vfptr->Release(this->mElem[v3].mResult);
      ++v1;
      ++v3;
    }
    while ( v1 < this->mCount );
  }
  mElem = this->mElem;
  this->mCount = 0;
  if ( mElem )
  {
    operator delete[](mElem);
    this->mElem = 0i64;
  }
}

// File Line: 509
// RVA: 0xA1A130
void __fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::EnsureCapacity(
        Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this,
        int minimum)
{
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // edi
  unsigned __int64 v6; // rax
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v7; // rsi
  __int64 mCount; // rax

  if ( this->mCapacity < minimum )
  {
    v3 = (minimum - 1) | ((unsigned int)(minimum - 1) >> 1) | (((minimum - 1) | ((unsigned int)(minimum - 1) >> 1)) >> 2);
    v4 = v3 | (v3 >> 4) | ((v3 | (v3 >> 4)) >> 8);
    v5 = (v4 | HIWORD(v4)) + 1;
    v6 = 16i64 * v5;
    if ( !is_mul_ok(v5, 0x10ui64) )
      v6 = -1i64;
    v7 = (Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *)UFG::qMalloc(v6, "CombinedObjectCache entries", 0i64);
    mCount = this->mCount;
    if ( (int)mCount > 0 )
    {
      memmove(v7, this->mElem, 16 * mCount);
      if ( this->mElem )
      {
        operator delete[](this->mElem);
        this->mElem = 0i64;
      }
    }
    this->mElem = v7;
    this->mCapacity = v5;
  }
}

// File Line: 529
// RVA: 0xA1AE20
ID3D11InputLayout *__fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Get(
        Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this,
        Illusion::Shader *t1,
        Illusion::VertexDecl *t2)
{
  int mCount; // r9d
  unsigned int mUID; // r11d
  unsigned int v5; // r10d
  int v6; // r8d
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *mElem; // rbx
  int v9; // edx
  __int64 v10; // rax
  unsigned int mUidT1; // ecx
  bool v12; // cf
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v13; // rax

  mCount = this->mCount;
  mUID = t2->mNode.mUID;
  v5 = t1->mNode.mUID;
  v6 = 0;
  if ( mCount > 0 )
  {
    mElem = this->mElem;
    do
    {
      v9 = (mCount + v6) >> 1;
      v10 = v9;
      mUidT1 = mElem[v10].mUidT1;
      v12 = mUidT1 < v5;
      if ( mUidT1 == v5 )
        v12 = mElem[v10].mUidT2 < mUID;
      if ( v12 )
        v6 = v9 + 1;
      if ( v12 )
        v9 = mCount;
      mCount = v9;
    }
    while ( v6 < v9 );
  }
  if ( v6 < this->mCount && (v13 = this->mElem, this->mElem[v6].mUidT1 == v5) && v13[v6].mUidT2 == mUID )
    return v13[v6].mResult;
  else
    return 0i64;
}

// File Line: 543
// RVA: 0xA21630
void __fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Set(
        Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this,
        Illusion::Shader *t1,
        Illusion::VertexDecl *t2,
        ID3D11InputLayout *result)
{
  unsigned int mUID; // esi
  unsigned int v5; // ebp
  int mCount; // r10d
  int v9; // edi
  __int64 v10; // rdx
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *mElem; // r9
  int v12; // eax
  __int64 v13; // rcx
  unsigned int mUidT1; // r8d
  bool v15; // cf
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v16; // rax
  ID3D11InputLayout *mResult; // rcx
  __int64 v18; // rbx

  mUID = t1->mNode.mUID;
  v5 = t2->mNode.mUID;
  if ( result )
    result->vfptr->AddRef(result);
  mCount = this->mCount;
  v9 = 0;
  v10 = (unsigned int)mCount;
  if ( mCount > 0 )
  {
    mElem = this->mElem;
    do
    {
      v12 = ((int)v10 + v9) >> 1;
      v13 = v12;
      mUidT1 = mElem[v13].mUidT1;
      v15 = mUidT1 < mUID;
      if ( mUidT1 == mUID )
        v15 = mElem[v13].mUidT2 < v5;
      if ( v15 )
        v9 = v12 + 1;
      if ( v15 )
        v12 = v10;
      v10 = (unsigned int)v12;
    }
    while ( v9 < v12 );
  }
  if ( v9 < mCount && (v16 = this->mElem, this->mElem[v9].mUidT1 == mUID) && v16[v9].mUidT2 == v5 )
  {
    mResult = v16[v9].mResult;
    if ( mResult )
    {
      ((void (__fastcall *)(ID3D11InputLayout *, __int64))mResult->vfptr->Release)(mResult, v10);
      this->mElem[v9].mResult = 0i64;
    }
    this->mElem[v9].mResult = result;
  }
  else
  {
    Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::EnsureCapacity(
      this,
      mCount + 1);
    v18 = v9;
    memmove(&this->mElem[v18 + 1], &this->mElem[v18], 16i64 * (this->mCount - v9));
    this->mElem[v18].mUidT1 = mUID;
    this->mElem[v18].mUidT2 = v5;
    this->mElem[v18].mResult = result;
    ++this->mCount;
  }
}

// File Line: 582
// RVA: 0xA211E0
void __fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::RemoveObject(
        Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this,
        Illusion::Shader *t1)
{
  unsigned int mUID; // r8d
  int mCount; // edx
  int v4; // ebx
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *mElem; // rax
  int v7; // edi
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v8; // rcx
  __int64 v9; // rbp
  __int64 v10; // rsi

  mUID = t1->mNode.mUID;
  mCount = this->mCount;
  v4 = 0;
  if ( mCount > 0 )
  {
    mElem = this->mElem;
    do
    {
      if ( mElem->mUidT1 >= mUID )
        break;
      ++v4;
      ++mElem;
    }
    while ( v4 < mCount );
  }
  v7 = v4;
  if ( v4 < mCount )
  {
    v8 = &this->mElem[v4];
    do
    {
      if ( v8->mUidT1 != mUID )
        break;
      ++v7;
      ++v8;
    }
    while ( v7 < mCount );
    if ( v7 > v4 )
    {
      if ( v4 < (__int64)v7 )
      {
        v9 = v7 - (__int64)v4;
        v10 = v4;
        do
        {
          this->mElem[v10].mResult->vfptr->Release(this->mElem[v10].mResult);
          ++v10;
          --v9;
        }
        while ( v9 );
      }
      memmove(&this->mElem[v4], &this->mElem[v7], 16i64 * (this->mCount - v7));
      this->mCount += v4 - v7;
    }
  }
}

// File Line: 605
// RVA: 0xA212D0
void __fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::RemoveObject(
        Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this,
        Illusion::VertexDecl *t2)
{
  unsigned int mUID; // r15d
  int v3; // ebp
  int v5; // ebx
  __int64 v6; // r14
  __int64 v7; // rdi
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *mElem; // rcx

  mUID = t2->mNode.mUID;
  v3 = 0;
  v5 = 0;
  if ( this->mCount <= 0 )
  {
    this->mCount = 0;
  }
  else
  {
    v6 = 0i64;
    v7 = 0i64;
    do
    {
      mElem = this->mElem;
      if ( this->mElem[v7].mUidT2 == mUID )
      {
        mElem[v7].mResult->vfptr->Release(mElem[v7].mResult);
      }
      else
      {
        ++v3;
        *(_QWORD *)&mElem[v6++].mUidT1 = *(_QWORD *)&mElem[v7].mUidT1;
        mElem[v6 - 1].mResult = mElem[v7].mResult;
      }
      ++v5;
      ++v7;
    }
    while ( v5 < this->mCount );
    this->mCount = v3;
  }
}

// File Line: 630
// RVA: 0xA18C90
ID3D11InputLayout *__fastcall Illusion::InputLayoutCache::CreateD3DObject(
        Illusion::InputLayoutCache *this,
        Illusion::Shader *shader,
        Illusion::VertexDecl *vertex_decl)
{
  UFG::qBaseNodeRB *v3; // r9
  __int64 v5; // [rsp+48h] [rbp+10h] BYREF

  v3 = shader[1].mNode.mChild[0];
  v5 = 0i64;
  ((void (__fastcall *)(ID3D11Device *, UFG::qBaseNodeRB *, _QWORD, UFG::qBaseNodeRB *, _QWORD, __int64 *))UFG::gD3D11Device->vfptr->IASetInputLayout)(
    UFG::gD3D11Device,
    vertex_decl[1].mNode.mChild[0],
    LODWORD(vertex_decl[1].mNode.mParent),
    v3->mParent,
    SLODWORD(v3->mChild[0]),
    &v5);
  return (ID3D11InputLayout *)v5;
}

// File Line: 751
// RVA: 0xA15C20
void __fastcall Illusion::TaskRenderEnv::TaskRenderEnv(Illusion::TaskRenderEnv *this, ID3D11DeviceContext *context)
{
  this->mContext = context;
  this->mTarget = 0i64;
  this->mTargetMIP = 0;
  this->mShader = 0i64;
  this->mVertexDecl = 0i64;
  this->mAlphaState = 0i64;
  this->mRasterState = 0i64;
  this->mIndexCount = 0;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mConstantBufferValues.mTree.mTree);
  this->mInputLayoutCache.vfptr = (Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>Vtbl *)&Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::`vftable;
  this->mInputLayoutCache.mLocalCache.mElem = 0i64;
  *(_QWORD *)&this->mInputLayoutCache.mLocalCache.mCount = 0i64;
  this->mInputLayoutCache.mGlobalCache = &unk_14249AF60;
  this->mInputLayoutCache.vfptr = (Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>Vtbl *)&Illusion::InputLayoutCache::`vftable;
  this->mAbortNextDraw = 0;
  this->mContext = context;
  memset(&this->mCurrState, 0, sizeof(this->mCurrState));
  this->mCurrState.mInComputePipeline = 0;
  this->mCurrState.mBlendStateMask = -1;
  this->mContext->vfptr[36].Release(this->mContext);
  memset(&this->mDeviceState, 0, sizeof(this->mDeviceState));
  this->mDeviceState.mInComputePipeline = 0;
  this->mDeviceState.mBlendStateMask = -1;
}

// File Line: 766
// RVA: 0xA221E0
void __fastcall Illusion::TaskRenderEnv::SetTarget(
        Illusion::TaskRenderEnv *this,
        Illusion::BeginTargetCommandParams *target_params)
{
  signed int v4; // r11d
  __int64 v5; // r10
  __int64 i; // rdx
  Illusion::Target *mTarget; // r9
  ID3D11SamplerState *v8; // rax
  __int64 v9; // rcx
  char v10; // al
  __int64 mDestMipLevel; // rax
  Illusion::Target *v12; // rax

  if ( target_params )
    this->mTarget = target_params->mTarget;
  else
    this->mTarget = 0i64;
  if ( this->mTarget )
  {
    v4 = 0;
    v5 = 0i64;
    for ( i = 3i64; i < 7; ++i )
    {
      mTarget = this->mTarget;
      v8 = 0i64;
      if ( v4 < (signed int)mTarget->mNumTargetTextures )
      {
        v9 = *(_QWORD *)((char *)&mTarget->mWidth + i * 8);
        if ( v9 )
        {
          v10 = *(_BYTE *)(v9 + 93);
          if ( v10 == 2 || v10 == 3 )
          {
            v8 = (ID3D11SamplerState *)mTarget->mTargetPlat->mRenderTargetView[target_params->mDestFaceSlice][v5];
          }
          else if ( *(_BYTE *)(v9 + 104) <= 1u )
          {
            v8 = *(ID3D11SamplerState **)((char *)&mTarget->mTargetPlat->mViewport.TopLeftX + i * 8);
          }
          else
          {
            mDestMipLevel = target_params->mDestMipLevel;
            this->mTargetMIP = mDestMipLevel;
            v8 = (ID3D11SamplerState *)mTarget->mTargetPlat->mRenderTargetView[mDestMipLevel][v5];
          }
        }
      }
      this->mCurrState.mDomainTextureSamplers[i + 9] = v8;
      ++v4;
      ++v5;
    }
    v12 = this->mTarget;
    if ( v12->mDepthTexture )
      this->mCurrState.mDepthStencilView = v12->mTargetPlat->mDepthStencilView;
    else
      this->mCurrState.mDepthStencilView = 0i64;
  }
  else
  {
    this->mCurrState.mRenderTargets[0] = 0i64;
    this->mCurrState.mRenderTargets[1] = 0i64;
    this->mCurrState.mRenderTargets[2] = 0i64;
    this->mCurrState.mRenderTargets[3] = 0i64;
    this->mCurrState.mDepthStencilView = 0i64;
  }
}

// File Line: 883
// RVA: 0xA21FE0
void __fastcall Illusion::TaskRenderEnv::SetShader(Illusion::TaskRenderEnv *this, Illusion::Shader *shader)
{
  __int64 v4; // rax
  ID3D11SamplerState **mComputeSamplers; // r8
  __int64 v6; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rcx
  ID3D11GeometryShader *v8; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rcx
  ID3D11HullShader *v10; // rcx
  __int64 v11; // rcx
  ID3D11DomainShader *v12; // rcx
  __int64 v13; // rdx
  ID3D11SamplerState **mPixelTextureSamplers; // rcx

  if ( shader != this->mShader )
  {
    v4 = *(_QWORD *)&shader[1].mNode.mUID;
    if ( v4 )
    {
      mComputeSamplers = this->mCurrState.mComputeSamplers;
      v6 = 12i64;
      this->mCurrState.mComputeShader = *(ID3D11ComputeShader **)(v4 + 200);
      do
      {
        *(mComputeSamplers - 12) = 0i64;
        *mComputeSamplers++ = 0i64;
        --v6;
      }
      while ( v6 );
      this->mShader = shader;
    }
    else
    {
      this->mCurrState.mPixelShader = *(ID3D11PixelShader **)&shader[1].mNode.mChild[1][5].mUID;
      this->mCurrState.mVertexShader = (ID3D11VertexShader *)shader[1].mNode.mChild[0][6].mParent;
      mPrev = shader[1].mResourceHandles.UFG::qResourceData::mNode.mPrev;
      if ( mPrev )
        v8 = (ID3D11GeometryShader *)mPrev[13].mPrev;
      else
        v8 = 0i64;
      this->mCurrState.mGeometryShader = v8;
      mNext = shader[1].mResourceHandles.UFG::qResourceData::mNode.mNext;
      if ( mNext )
        v10 = (ID3D11HullShader *)mNext[13].mNext;
      else
        v10 = 0i64;
      this->mCurrState.mHullShader = v10;
      v11 = *(_QWORD *)&shader[1].mTypeUID;
      if ( v11 )
        v12 = *(ID3D11DomainShader **)(v11 + 224);
      else
        v12 = 0i64;
      this->mCurrState.mDomainShader = v12;
      this->mCurrState.mInputLayout = 0i64;
      v13 = 12i64;
      mPixelTextureSamplers = this->mCurrState.mPixelTextureSamplers;
      do
      {
        *(mPixelTextureSamplers - 12) = 0i64;
        *mPixelTextureSamplers = 0i64;
        mPixelTextureSamplers[29] = 0i64;
        mPixelTextureSamplers[41] = 0i64;
        mPixelTextureSamplers[70] = 0i64;
        mPixelTextureSamplers[82] = 0i64;
        mPixelTextureSamplers[111] = 0i64;
        mPixelTextureSamplers[123] = 0i64;
        ++mPixelTextureSamplers;
        --v13;
      }
      while ( v13 );
      this->mShader = shader;
    }
  }
}

// File Line: 931
// RVA: 0xA22320
void __fastcall Illusion::TaskRenderEnv::SetTexture(
        Illusion::TaskRenderEnv *this,
        Illusion::ShaderParam *shader_param,
        Illusion::Texture *texture)
{
  _QWORD *v3; // r9
  Illusion::Target *mTarget; // rax
  signed int v7; // r8d
  __int64 mPixelTextureSlot; // rcx
  ID3D11ShaderResourceView *v9; // rax
  __int64 mGeometryTextureSlot; // rcx
  ID3D11ShaderResourceView *v11; // rax
  __int64 mHullTextureSlot; // rcx
  ID3D11ShaderResourceView *v13; // rax
  __int64 mDomainTextureSlot; // rcx
  ID3D11ShaderResourceView *v15; // rax

  v3 = *(_QWORD **)&texture[1].mMipMapBias;
  if ( v3 )
  {
    mTarget = this->mTarget;
    v7 = -1;
    if ( mTarget
      && mTarget->mNumTargetTextures == 1
      && texture->mNode.mUID == mTarget->mTargetTexture[0]->mNode.mUID
      && v3[23] )
    {
      v7 = this->mTargetMIP - 1;
    }
    mPixelTextureSlot = shader_param->mPixelTextureSlot;
    if ( (int)mPixelTextureSlot >= 0 )
    {
      if ( v7 < 0 )
        v9 = (ID3D11ShaderResourceView *)v3[21];
      else
        v9 = *(ID3D11ShaderResourceView **)(v3[23] + 8i64 * v7);
      this->mCurrState.mPixelTextureResources[mPixelTextureSlot] = v9;
    }
    mGeometryTextureSlot = shader_param->mGeometryTextureSlot;
    if ( (int)mGeometryTextureSlot >= 0 )
    {
      if ( v7 < 0 )
        v11 = (ID3D11ShaderResourceView *)v3[21];
      else
        v11 = *(ID3D11ShaderResourceView **)(v3[23] + 8i64 * v7);
      this->mCurrState.mGeometryTextureResources[mGeometryTextureSlot] = v11;
    }
    mHullTextureSlot = shader_param->mHullTextureSlot;
    if ( (int)mHullTextureSlot >= 0 )
    {
      if ( v7 < 0 )
        v13 = (ID3D11ShaderResourceView *)v3[21];
      else
        v13 = *(ID3D11ShaderResourceView **)(v3[23] + 8i64 * v7);
      this->mCurrState.mHullTextureResources[mHullTextureSlot] = v13;
    }
    mDomainTextureSlot = shader_param->mDomainTextureSlot;
    if ( (int)mDomainTextureSlot >= 0 )
    {
      if ( v7 < 0 )
        v15 = (ID3D11ShaderResourceView *)v3[21];
      else
        v15 = *(ID3D11ShaderResourceView **)(v3[23] + 8i64 * v7);
      this->mCurrState.mDomainTextureResources[mDomainTextureSlot] = v15;
    }
    if ( shader_param->mVertexTextureSlot >= 0 )
      this->mCurrState.mVertexTextureResources[shader_param->mVertexTextureSlot] = (ID3D11ShaderResourceView *)v3[21];
    if ( shader_param->mComputeTextureSlot >= 0 )
      this->mCurrState.mComputeResources[shader_param->mComputeTextureSlot] = (ID3D11ShaderResourceView *)v3[21];
    if ( shader_param->mPixelSamplerSlot >= 0 )
      this->mCurrState.mPixelTextureSamplers[shader_param->mPixelSamplerSlot] = (ID3D11SamplerState *)v3[24];
    if ( shader_param->mVertexSamplerSlot >= 0 )
      this->mCurrState.mVertexTextureSamplers[shader_param->mVertexSamplerSlot] = (ID3D11SamplerState *)v3[24];
    if ( shader_param->mComputeSamplerSlot >= 0 )
      this->mCurrState.mComputeSamplers[shader_param->mComputeSamplerSlot] = (ID3D11SamplerState *)v3[24];
    if ( shader_param->mGeometrySamplerSlot >= 0 )
      this->mCurrState.mGeometryTextureSamplers[shader_param->mGeometrySamplerSlot] = (ID3D11SamplerState *)v3[24];
    if ( shader_param->mHullSamplerSlot >= 0 )
      this->mCurrState.mHullTextureSamplers[shader_param->mHullSamplerSlot] = (ID3D11SamplerState *)v3[24];
    if ( shader_param->mDomainSamplerSlot >= 0 )
      this->mCurrState.mDomainTextureSamplers[shader_param->mDomainSamplerSlot] = (ID3D11SamplerState *)v3[24];
  }
  else
  {
    UFG::qPrintf((const char *)&stru_141A183E8.skipToken.getType, texture->mDebugName);
    this->mAbortNextDraw = 1;
  }
}

// File Line: 1052
// RVA: 0xA21A50
void __fastcall Illusion::TaskRenderEnv::SetConstBuffer(
        Illusion::TaskRenderEnv *this,
        Illusion::ShaderParam *shader_param,
        void *data)
{
  __int64 mPixelConstantSlot; // rax
  __int64 mVertexConstantSlot; // rax
  __int64 mComputeConstantSlot; // rax
  __int64 mGeometryConstantSlot; // rax
  __int64 mHullConstantSlot; // rax
  __int64 mDomainConstantSlot; // rax
  ID3D11Buffer *mConstantBuffer; // rax
  unsigned int v13; // esi
  UFG::qBaseTreeRB *v14; // rax
  const void **p_mParent; // rax
  __int64 v16; // [rsp+68h] [rbp+10h] BYREF
  void *value; // [rsp+70h] [rbp+18h] BYREF

  value = data;
  mPixelConstantSlot = shader_param->mPixelConstantSlot;
  if ( (int)mPixelConstantSlot >= 0 )
  {
    this->mCurrState.mPixelConstantBuffers[mPixelConstantSlot] = shader_param->mConstantBuffer;
    this->mCurrState.mPixelConstantAddress[shader_param->mPixelConstantSlot] = 0i64;
  }
  mVertexConstantSlot = shader_param->mVertexConstantSlot;
  if ( (int)mVertexConstantSlot >= 0 )
  {
    this->mCurrState.mVertexConstantBuffers[mVertexConstantSlot] = shader_param->mConstantBuffer;
    this->mCurrState.mVertexConstantAddress[shader_param->mVertexConstantSlot] = 0i64;
  }
  mComputeConstantSlot = shader_param->mComputeConstantSlot;
  if ( (int)mComputeConstantSlot >= 0 )
  {
    this->mCurrState.mComputeConstantBuffers[mComputeConstantSlot] = shader_param->mConstantBuffer;
    this->mCurrState.mComputeConstantAddress[shader_param->mComputeConstantSlot] = 0i64;
  }
  mGeometryConstantSlot = shader_param->mGeometryConstantSlot;
  if ( (int)mGeometryConstantSlot >= 0 )
  {
    this->mCurrState.mGeometryConstantBuffers[mGeometryConstantSlot] = shader_param->mConstantBuffer;
    this->mCurrState.mGeometryConstantAddress[shader_param->mGeometryConstantSlot] = 0i64;
  }
  mHullConstantSlot = shader_param->mHullConstantSlot;
  if ( (int)mHullConstantSlot >= 0 )
  {
    this->mCurrState.mHullConstantBuffers[mHullConstantSlot] = shader_param->mConstantBuffer;
    this->mCurrState.mHullConstantAddress[shader_param->mHullConstantSlot] = 0i64;
  }
  mDomainConstantSlot = shader_param->mDomainConstantSlot;
  if ( (int)mDomainConstantSlot >= 0 )
  {
    this->mCurrState.mDomainConstantBuffers[mDomainConstantSlot] = shader_param->mConstantBuffer;
    this->mCurrState.mDomainConstantAddress[shader_param->mDomainConstantSlot] = 0i64;
  }
  mConstantBuffer = shader_param->mConstantBuffer;
  v16 = 0i64;
  v13 = (unsigned int)mConstantBuffer ^ HIDWORD(mConstantBuffer);
  if ( (unsigned int)mConstantBuffer != HIDWORD(mConstantBuffer)
    && (v14 = UFG::qBaseTreeRB::Get(&this->mConstantBufferValues.mTree.mTree, v13)) != 0i64 )
  {
    p_mParent = (const void **)&v14->mNULL.mParent;
  }
  else
  {
    p_mParent = (const void **)&v16;
  }
  if ( !*p_mParent || memcmp(*p_mParent, data, shader_param->mNumBytes) )
  {
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Buffer *, _QWORD, _QWORD, void *, unsigned int, _DWORD))this->mContext->vfptr[16].QueryInterface)(
      this->mContext,
      shader_param->mConstantBuffer,
      0i64,
      0i64,
      data,
      shader_param->mNumBytes,
      0);
    UFG::qMap<void *>::Set(&this->mConstantBufferValues, v13, &value);
  }
}

// File Line: 1164
// RVA: 0xA21BF0
void __fastcall Illusion::TaskRenderEnv::SetConstBuffer_StateBlock(
        Illusion::TaskRenderEnv *this,
        Illusion::ShaderParam *shader_param,
        char *data)
{
  unsigned int v6; // eax
  unsigned int v7; // ebp
  UFG::qBaseTreeRB *v8; // rax
  ID3D11Buffer **p_mNULL; // rcx
  ID3D11Buffer *v10; // rcx
  __int64 v11; // r14
  UFG::qBaseTreeRB *v12; // rdi
  UFG::allocator::free_link *v13; // rax
  __int64 mPixelConstantSlot; // rax
  __int64 mVertexConstantSlot; // rax
  __int64 mComputeConstantSlot; // rax
  __int64 mGeometryConstantSlot; // rax
  __int64 mHullConstantSlot; // rax
  __int64 mDomainConstantSlot; // rax
  char *v20; // [rsp+28h] [rbp-50h] BYREF
  int v21; // [rsp+30h] [rbp-48h]
  int v22; // [rsp+34h] [rbp-44h]
  int dest[16]; // [rsp+38h] [rbp-40h] BYREF
  ID3D11Buffer *v24; // [rsp+88h] [rbp+10h] BYREF
  UFG::allocator::free_link *v25; // [rsp+98h] [rbp+20h] BYREF

  v24 = 0i64;
  v6 = UFG::qDataHash32(data, shader_param->mNumBytes, 0xFFFFFFFF);
  v7 = v6;
  v25 = 0i64;
  if ( !v6
    || (v8 = UFG::qBaseTreeRB::Get(&Illusion::TaskRenderEnv::mStateBlockConstantBufferValues.mTree.mTree, v6),
        p_mNULL = (ID3D11Buffer **)&v8->mNULL,
        !v8) )
  {
    p_mNULL = (ID3D11Buffer **)&v25;
  }
  v10 = *p_mNULL;
  if ( v10 )
  {
    v24 = v10;
  }
  else
  {
    UFG::qMemSet(dest, 0, 0x18u);
    dest[0] = shader_param->mNumBytes;
    dest[1] = 1;
    dest[2] = 4;
    v20 = data;
    v21 = dest[0];
    v22 = dest[0];
    ((void (__fastcall *)(ID3D11Device *, int *, char **, ID3D11Buffer **, __int64))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
      UFG::gD3D11Device,
      dest,
      &v20,
      &v24,
      -2i64);
    v11 = (__int64)v24;
    if ( !v7
      || (v12 = UFG::qBaseTreeRB::Get(&Illusion::TaskRenderEnv::mStateBlockConstantBufferValues.mTree.mTree, v7)) == 0i64 )
    {
      v13 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
      v12 = (UFG::qBaseTreeRB *)v13;
      v25 = v13;
      if ( v13 )
      {
        v13->mNext = 0i64;
        v13[1].mNext = 0i64;
        v13[2].mNext = 0i64;
        LODWORD(v13[3].mNext) = v7;
        v13[4].mNext = (UFG::allocator::free_link *)v11;
      }
      else
      {
        v12 = 0i64;
      }
      UFG::qBaseTreeRB::Add(&Illusion::TaskRenderEnv::mStateBlockConstantBufferValues.mTree.mTree, &v12->mRoot);
    }
    v12->mNULL.mParent = (UFG::qBaseNodeRB *)v11;
    v10 = v24;
  }
  mPixelConstantSlot = shader_param->mPixelConstantSlot;
  if ( (int)mPixelConstantSlot >= 0 )
  {
    this->mCurrState.mPixelConstantBuffers[mPixelConstantSlot] = v10;
    this->mCurrState.mPixelConstantAddress[shader_param->mPixelConstantSlot] = 0i64;
    v10 = v24;
  }
  mVertexConstantSlot = shader_param->mVertexConstantSlot;
  if ( (int)mVertexConstantSlot >= 0 )
  {
    this->mCurrState.mVertexConstantBuffers[mVertexConstantSlot] = v10;
    this->mCurrState.mVertexConstantAddress[shader_param->mVertexConstantSlot] = 0i64;
    v10 = v24;
  }
  mComputeConstantSlot = shader_param->mComputeConstantSlot;
  if ( (int)mComputeConstantSlot >= 0 )
  {
    this->mCurrState.mComputeConstantBuffers[mComputeConstantSlot] = v10;
    this->mCurrState.mComputeConstantAddress[shader_param->mComputeConstantSlot] = 0i64;
    v10 = v24;
  }
  mGeometryConstantSlot = shader_param->mGeometryConstantSlot;
  if ( (int)mGeometryConstantSlot >= 0 )
  {
    this->mCurrState.mGeometryConstantBuffers[mGeometryConstantSlot] = v10;
    this->mCurrState.mGeometryConstantAddress[shader_param->mGeometryConstantSlot] = 0i64;
    v10 = v24;
  }
  mHullConstantSlot = shader_param->mHullConstantSlot;
  if ( (int)mHullConstantSlot >= 0 )
  {
    this->mCurrState.mHullConstantBuffers[mHullConstantSlot] = v10;
    this->mCurrState.mHullConstantAddress[shader_param->mHullConstantSlot] = 0i64;
    v10 = v24;
  }
  mDomainConstantSlot = shader_param->mDomainConstantSlot;
  if ( (int)mDomainConstantSlot >= 0 )
  {
    this->mCurrState.mDomainConstantBuffers[mDomainConstantSlot] = v10;
    this->mCurrState.mDomainConstantAddress[shader_param->mDomainConstantSlot] = 0i64;
  }
}DomainConstantSlot] =

// File Line: 1331
// RVA: 0xA17BF0
void __fastcall Illusion::TaskRenderEnv::ClearTarget(
        Illusion::TaskRenderEnv *this,
        Illusion::ClearCommandParams *clear_params)
{
  Illusion::Target *mTarget; // rsi
  unsigned int v5; // r12d
  float g; // xmm1_4
  signed int v7; // ebx
  __int64 v8; // rdi
  float b; // xmm0_4
  float a; // xmm1_4
  __int64 v11; // r15
  Illusion::BeginTargetCommandParams *mTargetParams; // rdx
  Illusion::TargetPlat *mTargetPlat; // r10
  Illusion::Texture *v14; // rcx
  char mType; // al
  bool v16; // cc
  ID3D11DeviceContext *mContext; // rcx
  unsigned int mFlags; // eax
  int v19[10]; // [rsp+30h] [rbp-28h] BYREF

  this->mCurrState.mInComputePipeline = 0;
  Illusion::TaskRenderEnv::PushStateToDevice(this);
  mTarget = this->mTarget;
  v5 = 0;
  if ( (clear_params->mFlags & 1) != 0 )
  {
    g = clear_params->mColour.g;
    v7 = 0;
    v8 = 0i64;
    v19[0] = LODWORD(clear_params->mColour.r);
    b = clear_params->mColour.b;
    *(float *)&v19[1] = g;
    a = clear_params->mColour.a;
    *(float *)&v19[2] = b;
    *(float *)&v19[3] = a;
    if ( (int)mTarget->mNumTargetTextures > 0 )
    {
      v11 = 32i64;
      do
      {
        mTargetParams = clear_params->mTargetParams;
        mTargetPlat = mTarget->mTargetPlat;
        v14 = mTarget->mTargetTexture[v7];
        mType = v14->mType;
        if ( mType == 2 || mType == 3 )
        {
          ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11RenderTargetView *, int *))this->mContext->vfptr[16].Release)(
            this->mContext,
            mTargetPlat->mRenderTargetView[mTargetParams->mDestFaceSlice][v8],
            v19);
        }
        else
        {
          v16 = v14->mNumMipMaps <= 1u;
          mContext = this->mContext;
          if ( v16 )
            ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, int *))mContext->vfptr[16].Release)(
              mContext,
              *(_QWORD *)(&mTargetPlat->mResolveDepthSurface + v11),
              v19);
          else
            ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11RenderTargetView *, int *))mContext->vfptr[16].Release)(
              mContext,
              mTargetPlat->mRenderTargetView[mTargetParams->mDestMipLevel][v8],
              v19);
        }
        ++v7;
        ++v8;
        v11 += 8i64;
      }
      while ( v7 < (signed int)mTarget->mNumTargetTextures );
    }
  }
  if ( mTarget->mDepthTexture )
  {
    mFlags = clear_params->mFlags;
    if ( (mFlags & 2) != 0 )
      v5 = 1;
    if ( (mFlags & 4) != 0 )
      v5 |= 2u;
    if ( v5 )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11DepthStencilView *, _QWORD))this->mContext->vfptr[17].Release)(
        this->mContext,
        mTarget->mTargetPlat->mDepthStencilView,
        v5);
  }
}

// File Line: 1408
// RVA: 0xA20E10
void __fastcall Illusion::TaskRenderEnv::PushStateToDevice(Illusion::TaskRenderEnv *this)
{
  Illusion::Shader *mShader; // rdx
  Illusion::D3DContextState *p_mDeviceState; // rdi
  Illusion::D3DContextState *p_mCurrState; // rbx
  __int64 v5; // rax
  __int128 v6; // xmm0
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  __int128 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1

  mShader = this->mShader;
  if ( mShader )
  {
    if ( !this->mCurrState.mInputLayout )
      this->mCurrState.mInputLayout = Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Get(
                                        &this->mInputLayoutCache,
                                        mShader,
                                        this->mVertexDecl);
    if ( !this->mCurrState.mInputLayout )
      this->mAbortNextDraw = 1;
  }
  if ( !this->mAbortNextDraw )
  {
    p_mDeviceState = &this->mDeviceState;
    p_mCurrState = &this->mCurrState;
    Illusion::D3DContextState::PushStateDelta(&this->mCurrState, this->mContext, &this->mDeviceState);
    if ( (((unsigned __int8)((_BYTE)this + 8) | (unsigned __int8)((_BYTE)this + 24)) & 0xF) != 0 )
    {
      memmove(&this->mDeviceState, &this->mCurrState, 0x910ui64);
    }
    else
    {
      v5 = 18i64;
      do
      {
        v6 = *(_OWORD *)&p_mCurrState->mInComputePipeline;
        v7 = *(_OWORD *)p_mCurrState->mComputeConstantBuffers;
        p_mDeviceState = (Illusion::D3DContextState *)((char *)p_mDeviceState + 128);
        p_mCurrState = (Illusion::D3DContextState *)((char *)p_mCurrState + 128);
        *(_OWORD *)&p_mDeviceState[-1].mDomainTextureSamplers[5] = v6;
        v8 = *(_OWORD *)&p_mCurrState[-1].mDomainTextureSamplers[9];
        *(_OWORD *)&p_mDeviceState[-1].mDomainTextureSamplers[7] = v7;
        v9 = *(_OWORD *)&p_mCurrState[-1].mDomainTextureSamplers[11];
        *(_OWORD *)&p_mDeviceState[-1].mDomainTextureSamplers[9] = v8;
        v10 = *(_OWORD *)&p_mCurrState[-1].mRenderTargets[1];
        *(_OWORD *)&p_mDeviceState[-1].mDomainTextureSamplers[11] = v9;
        v11 = *(_OWORD *)&p_mCurrState[-1].mRenderTargets[3];
        *(_OWORD *)&p_mDeviceState[-1].mRenderTargets[1] = v10;
        v12 = *(_OWORD *)&p_mCurrState[-1].mBlendState;
        *(_OWORD *)&p_mDeviceState[-1].mRenderTargets[3] = v11;
        v13 = *(_OWORD *)&p_mCurrState[-1].mDepthState;
        *(_OWORD *)&p_mDeviceState[-1].mBlendState = v12;
        *(_OWORD *)&p_mDeviceState[-1].mDepthState = v13;
        --v5;
      }
      while ( v5 );
      *(_OWORD *)&p_mDeviceState->mInComputePipeline = *(_OWORD *)&p_mCurrState->mInComputePipeline;
    }
  }
}

// File Line: 1430
// RVA: 0xA19D60
_BOOL8 __fastcall Illusion::TaskRenderEnv::DispatchCompute(
        Illusion::TaskRenderEnv *this,
        unsigned int thread_group_x,
        unsigned int thread_group_y,
        unsigned int thread_group_z)
{
  bool v4; // zf
  bool v9; // di
  _BOOL8 result; // rax

  v4 = !this->mAbortNextDraw;
  this->mCurrState.mInComputePipeline = 1;
  v9 = v4;
  Illusion::TaskRenderEnv::PushStateToDevice(this);
  if ( !this->mAbortNextDraw )
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))this->mContext->vfptr[13].Release)(
      this->mContext,
      thread_group_x,
      thread_group_y,
      thread_group_z);
  result = v9;
  this->mAbortNextDraw = 0;
  return result;
}

// File Line: 1443
// RVA: 0xA22570
_BOOL8 __fastcall Illusion::TaskRenderEnv::SubmitMesh(
        Illusion::TaskRenderEnv *this,
        int elem_offset,
        unsigned int index_count)
{
  bool v3; // zf
  bool v7; // di

  v3 = !this->mAbortNextDraw;
  this->mCurrState.mInComputePipeline = 0;
  v7 = v3;
  Illusion::TaskRenderEnv::PushStateToDevice(this);
  if ( !this->mAbortNextDraw )
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))this->mContext->vfptr[4].QueryInterface)(
      this->mContext,
      index_count,
      elem_offset - this->mCurrState.mIndexBufferOffset,
      0i64);
  this->mAbortNextDraw = 0;
  return v7;
}

// File Line: 1481
// RVA: 0xA225F0
_BOOL8 __fastcall Illusion::TaskRenderEnv::SubmitMeshInstanced(
        Illusion::TaskRenderEnv *this,
        unsigned int instanceCount,
        int elem_offset,
        unsigned int index_count)
{
  bool v4; // zf
  bool v9; // di
  _BOOL8 result; // rax

  v4 = !this->mAbortNextDraw;
  this->mCurrState.mInComputePipeline = 0;
  v9 = v4;
  Illusion::TaskRenderEnv::PushStateToDevice(this);
  if ( !this->mAbortNextDraw )
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD))this->mContext->vfptr[6].Release)(
      this->mContext,
      index_count,
      instanceCount,
      elem_offset - this->mCurrState.mIndexBufferOffset,
      0,
      0);
  result = v9;
  this->mAbortNextDraw = 0;
  return result;
}

