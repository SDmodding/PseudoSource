// File Line: 70
// RVA: 0x15AA5C0
__int64 dynamic_initializer_for__Illusion::TaskRenderEnv::mStateBlockConstantBufferValues__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&Illusion::TaskRenderEnv::mStateBlockConstantBufferValues.mTree.mTree);
  return atexit(dynamic_atexit_destructor_for__Illusion::TaskRenderEnv::mStateBlockConstantBufferValues__);
}

// File Line: 89
// RVA: 0xA20250
void __fastcall Illusion::D3DContextState::PushStateDelta(Illusion::D3DContextState *this, ID3D11DeviceContext *context, Illusion::D3DContextState *prevState)
{
  Illusion::D3DContextState *v3; // rsi
  ID3D11DeviceContext *v4; // rdi
  Illusion::D3DContextState *v5; // rbx
  IUnknownVtbl *v6; // rax
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
  __int64 v17; // [rsp+30h] [rbp-D0h]
  __int64 v18; // [rsp+38h] [rbp-C8h]
  __int64 v19; // [rsp+40h] [rbp-C0h]
  __int64 v20; // [rsp+48h] [rbp-B8h]
  __int64 v21; // [rsp+50h] [rbp-B0h]
  __int64 v22; // [rsp+58h] [rbp-A8h]
  __int64 v23; // [rsp+60h] [rbp-A0h]
  __int64 v24; // [rsp+68h] [rbp-98h]
  __int128 v25; // [rsp+70h] [rbp-90h]
  __int128 v26; // [rsp+80h] [rbp-80h]
  __int128 v27; // [rsp+90h] [rbp-70h]
  __int128 v28; // [rsp+A0h] [rbp-60h]
  __int128 v29; // [rsp+B0h] [rbp-50h]
  __int128 v30; // [rsp+C0h] [rbp-40h]
  __int128 v31; // [rsp+D0h] [rbp-30h]
  __int128 v32; // [rsp+E0h] [rbp-20h]
  __int128 v33; // [rsp+F0h] [rbp-10h]
  __int128 v34; // [rsp+100h] [rbp+0h]

  v3 = prevState;
  v4 = context;
  v5 = this;
  if ( this->mInComputePipeline != prevState->mInComputePipeline )
  {
    v6 = context->vfptr;
    _mm_store_si128((__m128i *)&v29, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v30, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v31, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v32, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v33, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v34, (__m128i)0i64);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, __int128 *))v6[8].AddRef)(
      context,
      0i64,
      12i64,
      &v29);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, __int128 *))v4->vfptr[2].Release)(
      v4,
      0i64,
      12i64,
      &v29);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, __int128 *))v4->vfptr[10].AddRef)(
      v4,
      0i64,
      12i64,
      &v29);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, __int128 *))v4->vfptr[19].Release)(
      v4,
      0i64,
      12i64,
      &v29);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, __int128 *))v4->vfptr[21].QueryInterface)(
      v4,
      0i64,
      12i64,
      &v29);
    v7 = v4->vfptr;
    v17 = 0i64;
    v18 = 0i64;
    v19 = 0i64;
    v20 = 0i64;
    ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64, __int64 *, _QWORD))v7[11].QueryInterface)(
      v4,
      4i64,
      &v17,
      0i64);
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, __int128 *))v4->vfptr[22].AddRef)(
      v4,
      0i64,
      12i64,
      &v29);
    v8 = v4->vfptr;
    _mm_store_si128((__m128i *)&v25, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v26, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v27, (__m128i)0i64);
    _mm_store_si128((__m128i *)&v28, (__m128i)0i64);
    v21 = -1i64;
    v22 = -1i64;
    v23 = -1i64;
    v24 = -1i64;
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, __int128 *, __int64 *))v8[22].Release)(
      v4,
      0i64,
      8i64,
      &v25,
      &v21);
  }
  if ( v5->mInComputePipeline )
  {
    if ( v5->mComputeShader != v3->mComputeShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11ComputeShader *, _QWORD, _QWORD))v4->vfptr[23].QueryInterface)(
        v4,
        v5->mComputeShader,
        0i64,
        0i64);
    if ( memcmp(v5->mComputeConstantBuffers, v3->mComputeConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11Buffer **))v4->vfptr[23].Release)(
        v4,
        0i64,
        8i64,
        v5->mComputeConstantBuffers);
    if ( memcmp(v5->mComputeResources, v3->mComputeResources, 0x60ui64) )
    {
      if ( memcmp(v5->mComputeUAVs, v3->mComputeUAVs, 0x40ui64) )
      {
        v9 = v4->vfptr;
        _mm_store_si128((__m128i *)&v25, (__m128i)0i64);
        _mm_store_si128((__m128i *)&v26, (__m128i)0i64);
        _mm_store_si128((__m128i *)&v27, (__m128i)0i64);
        _mm_store_si128((__m128i *)&v28, (__m128i)0i64);
        v21 = -1i64;
        v22 = -1i64;
        v23 = -1i64;
        v24 = -1i64;
        ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, __int128 *, __int64 *))v9[22].Release)(
          v4,
          0i64,
          8i64,
          &v25,
          &v21);
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11ShaderResourceView **))v4->vfptr[22].AddRef)(
        v4,
        0i64,
        12i64,
        v5->mComputeResources);
    }
    if ( memcmp(v5->mComputeSamplers, v3->mComputeSamplers, 0x60ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11SamplerState **))v4->vfptr[23].AddRef)(
        v4,
        0i64,
        12i64,
        v5->mComputeSamplers);
    if ( memcmp(v5->mComputeUAVs, v3->mComputeUAVs, 0x40ui64) )
    {
      v10 = v4->vfptr;
      v21 = 0i64;
      v22 = 0i64;
      v23 = 0i64;
      v24 = 0i64;
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11UnorderedAccessView **, __int64 *))v10[22].Release)(
        v4,
        0i64,
        8i64,
        v5->mComputeUAVs,
        &v21);
    }
  }
  else
  {
    if ( v5->mInputLayout != v3->mInputLayout )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11InputLayout *))v4->vfptr[5].Release)(v4, v5->mInputLayout);
    if ( v5->mIndexBuffer != v3->mIndexBuffer
      || *(_DWORD *)v5->mIndexBufferFormat != *(_DWORD *)v3->mIndexBufferFormat
      || v5->mIndexBufferOffset != v3->mIndexBufferOffset )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Buffer *, _QWORD, _QWORD))v4->vfptr[6].AddRef)(
        v4,
        v5->mIndexBuffer,
        *(unsigned int *)v5->mIndexBufferFormat,
        v5->mIndexBufferOffset);
    }
    if ( memcmp(v5->mVertexBuffers, v3->mVertexBuffers, 0x40ui64)
      || memcmp(v5->mVertexBufferStrides, v3->mVertexBufferStrides, 0x20ui64)
      || memcmp(v5->mVertexBufferOffsets, v3->mVertexBufferOffsets, 0x20ui64) )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11Buffer **, unsigned int *, unsigned int *))v4->vfptr[6].QueryInterface)(
        v4,
        0i64,
        8i64,
        v5->mVertexBuffers,
        v5->mVertexBufferStrides,
        v5->mVertexBufferOffsets);
    }
    if ( v5->mPrimType != v3->mPrimType )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD))v4->vfptr[8].QueryInterface)(v4, (unsigned int)v5->mPrimType);
    if ( v5->mVertexShader != v3->mVertexShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11VertexShader *, _QWORD, _QWORD))v4->vfptr[3].Release)(
        v4,
        v5->mVertexShader,
        0i64,
        0i64);
    if ( memcmp(v5->mVertexConstantBuffers, v3->mVertexConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11Buffer **))v4->vfptr[2].AddRef)(
        v4,
        0i64,
        8i64,
        v5->mVertexConstantBuffers);
    v11 = 0;
    if ( memcmp(v5->mVertexTextureResources, v3->mVertexTextureResources, 0x60ui64) )
    {
      if ( memcmp(v5->mRenderTargets, v3->mRenderTargets, 0x20ui64) || v5->mDepthStencilView != v3->mDepthStencilView )
      {
        v12 = v4->vfptr;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0i64;
        v20 = 0i64;
        v12[11].QueryInterface((IUnknown *)&v4->vfptr, (_GUID *)4, (void **)&v17);
        v11 = 1;
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11ShaderResourceView **))v4->vfptr[8].AddRef)(
        v4,
        0i64,
        12i64,
        v5->mVertexTextureResources);
    }
    if ( memcmp(v5->mVertexTextureSamplers, v3->mVertexTextureSamplers, 0x60ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11SamplerState **))v4->vfptr[8].Release)(
        v4,
        0i64,
        12i64,
        v5->mVertexTextureSamplers);
    if ( v5->mPixelShader != v3->mPixelShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11PixelShader *, _QWORD, _QWORD))v4->vfptr[3].QueryInterface)(
        v4,
        v5->mPixelShader,
        0i64,
        0i64);
    if ( memcmp(v5->mPixelConstantBuffers, v3->mPixelConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11Buffer **))v4->vfptr[5].AddRef)(
        v4,
        0i64,
        8i64,
        v5->mPixelConstantBuffers);
    if ( memcmp(v5->mPixelTextureResources, v3->mPixelTextureResources, 0x60ui64) )
    {
      if ( !v11
        && (memcmp(v5->mRenderTargets, v3->mRenderTargets, 0x20ui64) || v5->mDepthStencilView != v3->mDepthStencilView) )
      {
        v13 = v4->vfptr;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0i64;
        v20 = 0i64;
        v13[11].QueryInterface((IUnknown *)&v4->vfptr, (_GUID *)4, (void **)&v17);
        v11 = 1;
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11ShaderResourceView **))v4->vfptr[2].Release)(
        v4,
        0i64,
        12i64,
        v5->mPixelTextureResources);
    }
    if ( v5->mPixelShader != v3->mPixelShader || memcmp(v5->mPixelTextureSamplers, v3->mPixelTextureSamplers, 0x60ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11SamplerState **))v4->vfptr[3].AddRef)(
        v4,
        0i64,
        12i64,
        v5->mPixelTextureSamplers);
    if ( v5->mGeometryShader != v3->mGeometryShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11GeometryShader *, _QWORD, _QWORD))v4->vfptr[7].Release)(
        v4,
        v5->mGeometryShader,
        0i64,
        0i64);
    if ( memcmp(v5->mGeometryConstantBuffers, v3->mGeometryConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11Buffer **))v4->vfptr[7].AddRef)(
        v4,
        0i64,
        8i64,
        v5->mGeometryConstantBuffers);
    if ( memcmp(v5->mGeometryTextureResources, v3->mGeometryTextureResources, 0x60ui64) )
    {
      if ( !v11
        && (memcmp(v5->mRenderTargets, v3->mRenderTargets, 0x20ui64) || v5->mDepthStencilView != v3->mDepthStencilView) )
      {
        v14 = v4->vfptr;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0i64;
        v20 = 0i64;
        v14[11].QueryInterface((IUnknown *)&v4->vfptr, (_GUID *)4, (void **)&v17);
        v11 = 1;
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11ShaderResourceView **))v4->vfptr[10].AddRef)(
        v4,
        0i64,
        12i64,
        v5->mGeometryTextureResources);
    }
    if ( v5->mGeometryShader != v3->mGeometryShader
      || memcmp(v5->mGeometryTextureSamplers, v3->mGeometryTextureSamplers, 0x60ui64) )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11SamplerState **))v4->vfptr[10].Release)(
        v4,
        0i64,
        12i64,
        v5->mGeometryTextureSamplers);
    }
    if ( v5->mHullShader != v3->mHullShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11HullShader *, _QWORD, _QWORD))v4->vfptr[20].QueryInterface)(
        v4,
        v5->mHullShader,
        0i64,
        0i64);
    if ( memcmp(v5->mHullConstantBuffers, v3->mHullConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11Buffer **))v4->vfptr[20].Release)(
        v4,
        0i64,
        8i64,
        v5->mHullConstantBuffers);
    if ( memcmp(v5->mHullTextureResources, v3->mHullTextureResources, 0x60ui64) )
    {
      if ( !v11
        && (memcmp(v5->mRenderTargets, v3->mRenderTargets, 0x20ui64) || v5->mDepthStencilView != v3->mDepthStencilView) )
      {
        v15 = v4->vfptr;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0i64;
        v20 = 0i64;
        v15[11].QueryInterface((IUnknown *)&v4->vfptr, (_GUID *)4, (void **)&v17);
        v11 = 1;
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11ShaderResourceView **))v4->vfptr[19].Release)(
        v4,
        0i64,
        12i64,
        v5->mHullTextureResources);
    }
    if ( v5->mHullShader != v3->mHullShader || memcmp(v5->mHullTextureSamplers, v3->mHullTextureSamplers, 0x60ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11SamplerState **))v4->vfptr[20].AddRef)(
        v4,
        0i64,
        12i64,
        v5->mHullTextureSamplers);
    if ( v5->mDomainShader != v3->mDomainShader )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11DomainShader *, _QWORD, _QWORD))v4->vfptr[21].AddRef)(
        v4,
        v5->mDomainShader,
        0i64,
        0i64);
    if ( memcmp(v5->mDomainConstantBuffers, v3->mDomainConstantBuffers, 0x40ui64) )
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11Buffer **))v4->vfptr[22].QueryInterface)(
        v4,
        0i64,
        8i64,
        v5->mDomainConstantBuffers);
    if ( memcmp(v5->mDomainTextureResources, v3->mDomainTextureResources, 0x60ui64) )
    {
      if ( !v11
        && (memcmp(v5->mRenderTargets, v3->mRenderTargets, 0x20ui64) || v5->mDepthStencilView != v3->mDepthStencilView) )
      {
        v16 = v4->vfptr;
        v17 = 0i64;
        v18 = 0i64;
        v19 = 0i64;
        v20 = 0i64;
        v16[11].QueryInterface((IUnknown *)&v4->vfptr, (_GUID *)4, (void **)&v17);
      }
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11ShaderResourceView **))v4->vfptr[21].QueryInterface)(
        v4,
        0i64,
        12i64,
        v5->mDomainTextureResources);
    }
    if ( v5->mDomainShader != v3->mDomainShader
      || memcmp(v5->mDomainTextureSamplers, v3->mDomainTextureSamplers, 0x60ui64) )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11SamplerState **))v4->vfptr[21].Release)(
        v4,
        0i64,
        12i64,
        v5->mDomainTextureSamplers);
    }
    if ( v5->mRasterizerState != v3->mRasterizerState )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11RasterizerState *))v4->vfptr[14].AddRef)(
        v4,
        v5->mRasterizerState);
    if ( *(_QWORD *)&v5->mViewport.TopLeftX != *(_QWORD *)&v3->mViewport.TopLeftX
      || *(_QWORD *)&v5->mViewport.Width != *(_QWORD *)&v3->mViewport.Width
      || *(_QWORD *)&v5->mViewport.MinDepth != *(_QWORD *)&v3->mViewport.MinDepth )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64))v4->vfptr[14].Release)(v4, 1i64);
    }
    if ( *(_QWORD *)&v5->mScissorRect.left != *(_QWORD *)&v3->mScissorRect.left
      || *(_QWORD *)&v5->mScissorRect.right != *(_QWORD *)&v3->mScissorRect.right )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64))v4->vfptr[15].QueryInterface)(v4, 1i64);
    }
    if ( memcmp(v5->mRenderTargets, v3->mRenderTargets, 0x20ui64) || v5->mDepthStencilView != v3->mDepthStencilView )
      ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64, ID3D11RenderTargetView **, ID3D11DepthStencilView *))v4->vfptr[11].QueryInterface)(
        v4,
        4i64,
        v5->mRenderTargets,
        v5->mDepthStencilView);
    if ( v5->mBlendState != v3->mBlendState || v5->mBlendStateMask != v3->mBlendStateMask )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11BlendState *, GUID *, _QWORD))v4->vfptr[11].Release)(
        v4,
        v5->mBlendState,
        &GUID_00000000_0000_0000_0000_000000000000,
        v5->mBlendStateMask);
    if ( v5->mDepthState != v3->mDepthState || v5->mDepthStateStencilRef != v3->mDepthStateStencilRef )
      v4->vfptr[12].QueryInterface((IUnknown *)&v4->vfptr, (_GUID *)v5->mDepthState, (void **)v5->mDepthStateStencilRef);
  }
}BlendState *, GUID *, _QWORD))v4->vfptr[11].Release)(
        v4,
        v5->mBlendState,
        &GUID_00000000_0000_0000_0000_000000000000,
        v5->mBlendStateMask);
    if ( v5->mDepthState != v3->mDepthState || v5->mDepthStateStencilRef != v3->mDepthStateStencilRef )
      v4->vfptr[12].QueryInterface((IUnknown *)&v4->vfptr, (_GUID *)v5->mDepthState, (void **)v5->mDepthStateSten

// File Line: 491
// RVA: 0xA15F70
void __fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::~CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>(Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this)
{
  int v1; // esi
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *v2; // rbx
  __int64 v3; // rdi
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v4; // rcx

  v1 = 0;
  v2 = this;
  if ( this->mCount > 0 )
  {
    v3 = 0i64;
    do
    {
      ((void (*)(void))v2->mElem[v3].mResult->vfptr->Release)();
      ++v1;
      ++v3;
    }
    while ( v1 < v2->mCount );
  }
  v4 = v2->mElem;
  v2->mCount = 0;
  if ( v4 )
  {
    operator delete[](v4);
    v2->mElem = 0i64;
  }
}

// File Line: 509
// RVA: 0xA1A130
void __fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::EnsureCapacity(Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this, int minimum)
{
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *v2; // rbx
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // edi
  unsigned __int64 v6; // rax
  UFG::allocator::free_link *v7; // rsi
  __int64 v8; // rax

  v2 = this;
  if ( this->mCapacity < minimum )
  {
    v3 = (minimum - 1) | ((unsigned int)(minimum - 1) >> 1) | (((minimum - 1) | ((unsigned int)(minimum - 1) >> 1)) >> 2);
    v4 = v3 | (v3 >> 4) | ((v3 | (v3 >> 4)) >> 8);
    v5 = (v4 | (v4 >> 16)) + 1;
    v6 = 16i64 * v5;
    if ( !is_mul_ok(v5, 0x10ui64) )
      v6 = -1i64;
    v7 = UFG::qMalloc(v6, "CombinedObjectCache entries", 0i64);
    v8 = v2->mCount;
    if ( (signed int)v8 > 0 )
    {
      memmove(v7, v2->mElem, 16 * v8);
      if ( v2->mElem )
      {
        operator delete[](v2->mElem);
        v2->mElem = 0i64;
      }
    }
    v2->mElem = (Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *)v7;
    v2->mCapacity = v5;
  }
}

// File Line: 529
// RVA: 0xA1AE20
ID3D11InputLayout *__fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Get(Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this, Illusion::Shader *t1, Illusion::VertexDecl *t2)
{
  int v3; // er9
  unsigned int v4; // er11
  unsigned int v5; // er10
  int v6; // er8
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *v7; // rdi
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v8; // rbx
  int v9; // edx
  signed __int64 v10; // rax
  unsigned int v11; // ecx
  bool v12; // cf
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v13; // rax
  ID3D11InputLayout *result; // rax

  v3 = this->mCount;
  v4 = t2->mNode.mUID;
  v5 = t1->mNode.mUID;
  v6 = 0;
  v7 = this;
  if ( v3 > 0 )
  {
    v8 = this->mElem;
    do
    {
      v9 = (v3 + v6) >> 1;
      v10 = v9;
      v11 = v8[v10].mUidT1;
      v12 = v11 < v5;
      if ( v11 == v5 )
        v12 = v8[v10].mUidT2 < v4;
      if ( v12 )
        v6 = v9 + 1;
      if ( v12 )
        v9 = v3;
      v3 = v9;
    }
    while ( v6 < v9 );
  }
  if ( v6 >= v7->mCount || (v13 = v7->mElem, v7->mElem[v6].mUidT1 != v5) || v13[v6].mUidT2 != v4 )
    result = 0i64;
  else
    result = v13[v6].mResult;
  return result;
}

// File Line: 543
// RVA: 0xA21630
void __fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Set(Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this, Illusion::Shader *t1, Illusion::VertexDecl *t2, ID3D11InputLayout *result)
{
  unsigned int v4; // esi
  unsigned int v5; // ebp
  ID3D11InputLayout *v6; // r15
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *v7; // r14
  int v8; // er10
  int v9; // edi
  __int64 v10; // rdx
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v11; // r9
  int v12; // eax
  signed __int64 v13; // rcx
  unsigned int v14; // er8
  bool v15; // cf
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v16; // rax
  ID3D11InputLayout *v17; // rcx
  signed __int64 v18; // rbx

  v4 = t1->mNode.mUID;
  v5 = t2->mNode.mUID;
  v6 = result;
  v7 = this;
  if ( result )
    result->vfptr->AddRef((IUnknown *)result);
  v8 = v7->mCount;
  v9 = 0;
  v10 = (unsigned int)v8;
  if ( v8 > 0 )
  {
    v11 = v7->mElem;
    do
    {
      v12 = ((signed int)v10 + v9) >> 1;
      v13 = v12;
      v14 = v11[v13].mUidT1;
      v15 = v14 < v4;
      if ( v14 == v4 )
        v15 = v11[v13].mUidT2 < v5;
      if ( v15 )
        v9 = v12 + 1;
      if ( v15 )
        v12 = v10;
      v10 = (unsigned int)v12;
    }
    while ( v9 < v12 );
  }
  if ( v9 >= v8 || (v16 = v7->mElem, v7->mElem[v9].mUidT1 != v4) || v16[v9].mUidT2 != v5 )
  {
    Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::EnsureCapacity(v7, v8 + 1);
    v18 = v9;
    memmove(&v7->mElem[v18 + 1], &v7->mElem[v18], 16i64 * (v7->mCount - v9));
    v7->mElem[v18].mUidT1 = v4;
    v7->mElem[v18].mUidT2 = v5;
    v7->mElem[v18].mResult = v6;
    ++v7->mCount;
  }
  else
  {
    v17 = v16[v9].mResult;
    if ( v17 )
    {
      ((void (__fastcall *)(ID3D11InputLayout *, __int64))v17->vfptr->Release)(v17, v10);
      v7->mElem[v9].mResult = 0i64;
    }
    v7->mElem[v9].mResult = v6;
  }
}

// File Line: 582
// RVA: 0xA211E0
void __fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::RemoveObject(Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this, Illusion::Shader *t1)
{
  unsigned int v2; // er8
  int v3; // edx
  int v4; // ebx
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *v5; // r14
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v6; // rax
  int v7; // edi
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v8; // rcx
  signed __int64 v9; // rbp
  signed __int64 v10; // rsi

  v2 = t1->mNode.mUID;
  v3 = this->mCount;
  v4 = 0;
  v5 = this;
  if ( v3 > 0 )
  {
    v6 = this->mElem;
    do
    {
      if ( v6->mUidT1 >= v2 )
        break;
      ++v4;
      ++v6;
    }
    while ( v4 < v3 );
  }
  v7 = v4;
  if ( v4 < v3 )
  {
    v8 = &this->mElem[v4];
    do
    {
      if ( v8->mUidT1 != v2 )
        break;
      ++v7;
      ++v8;
    }
    while ( v7 < v3 );
    if ( v7 > v4 )
    {
      if ( v4 < (signed __int64)v7 )
      {
        v9 = v7 - (signed __int64)v4;
        v10 = v4;
        do
        {
          ((void (*)(void))v5->mElem[v10].mResult->vfptr->Release)();
          ++v10;
          --v9;
        }
        while ( v9 );
      }
      memmove(&v5->mElem[v4], &v5->mElem[v7], 16i64 * (v5->mCount - v7));
      v5->mCount += v4 - v7;
    }
  }
}

// File Line: 605
// RVA: 0xA212D0
void __fastcall Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::RemoveObject(Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this, Illusion::VertexDecl *t2)
{
  unsigned int v2; // er15
  int v3; // ebp
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *v4; // rsi
  int v5; // ebx
  __int64 v6; // r14
  __int64 v7; // rdi
  Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::MapEntry *v8; // rcx

  v2 = t2->mNode.mUID;
  v3 = 0;
  v4 = this;
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
      v8 = v4->mElem;
      if ( v4->mElem[v7].mUidT2 == v2 )
      {
        ((void (*)(void))v8[v7].mResult->vfptr->Release)();
      }
      else
      {
        ++v3;
        ++v6;
        *(_QWORD *)&v8[v6 - 1].mUidT1 = *(_QWORD *)&v8[v7].mUidT1;
        *((_QWORD *)&v8[v6] - 1) = v8[v7].mResult;
      }
      ++v5;
      ++v7;
    }
    while ( v5 < v4->mCount );
    v4->mCount = v3;
  }
}

// File Line: 630
// RVA: 0xA18C90
ID3D11InputLayout *__fastcall Illusion::InputLayoutCache::CreateD3DObject(Illusion::InputLayoutCache *this, Illusion::Shader *shader, Illusion::VertexDecl *vertex_decl)
{
  UFG::qBaseNodeRB *v3; // r9
  __int64 v5; // [rsp+48h] [rbp+10h]

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
  ID3D11DeviceContext *v2; // rbx
  Illusion::TaskRenderEnv *v3; // rdi
  signed __int64 v4; // [rsp+58h] [rbp+10h]

  v2 = context;
  v3 = this;
  this->mContext = context;
  this->mTarget = 0i64;
  this->mTargetMIP = 0;
  this->mShader = 0i64;
  this->mVertexDecl = 0i64;
  this->mAlphaState = 0i64;
  this->mRasterState = 0i64;
  this->mIndexCount = 0;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mConstantBufferValues.mTree.mTree);
  v4 = (signed __int64)&v3->mInputLayoutCache;
  *(_OWORD *)v4 = (unsigned __int64)&Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::`vftable;
  *(_QWORD *)(v4 + 16) = 0i64;
  v3->mInputLayoutCache.mGlobalCache = &unk_14249AF60;
  *(_QWORD *)v4 = &Illusion::InputLayoutCache::`vftable;
  v3->mAbortNextDraw = 0;
  v3->mContext = v2;
  memset(&v3->mCurrState, 0, 0x910ui64);
  v3->mCurrState.mInComputePipeline = 0;
  v3->mCurrState.mBlendStateMask = -1;
  ((void (__cdecl *)(ID3D11DeviceContext *))v3->mContext->vfptr[36].Release)(v3->mContext);
  memset(&v3->mDeviceState, 0, 0x910ui64);
  v3->mDeviceState.mInComputePipeline = 0;
  v3->mDeviceState.mBlendStateMask = -1;
}

// File Line: 766
// RVA: 0xA221E0
void __fastcall Illusion::TaskRenderEnv::SetTarget(Illusion::TaskRenderEnv *this, Illusion::BeginTargetCommandParams *target_params)
{
  Illusion::BeginTargetCommandParams *v2; // rbx
  Illusion::TaskRenderEnv *v3; // r8
  signed int v4; // er11
  __int64 v5; // r10
  signed __int64 v6; // rdx
  Illusion::Target *v7; // r9
  ID3D11SamplerState *v8; // rax
  __int64 v9; // rcx
  char v10; // al
  __int64 v11; // rax
  Illusion::Target *v12; // rax

  v2 = target_params;
  v3 = this;
  if ( target_params )
    this->mTarget = target_params->mTarget;
  else
    this->mTarget = 0i64;
  if ( this->mTarget )
  {
    v4 = 0;
    v5 = 0i64;
    v6 = 3i64;
    do
    {
      v7 = v3->mTarget;
      v8 = 0i64;
      if ( v4 < (signed int)v7->mNumTargetTextures )
      {
        v9 = *(_QWORD *)((char *)&v7->mWidth + v6 * 8);
        if ( v9 )
        {
          v10 = *(_BYTE *)(v9 + 93);
          if ( v10 != 2 && v10 != 3 )
          {
            if ( *(_BYTE *)(v9 + 104) <= 1u )
            {
              v8 = *(ID3D11SamplerState **)((char *)&v7->mTargetPlat->mViewport.TopLeftX + v6 * 8);
            }
            else
            {
              v11 = v2->mDestMipLevel;
              v3->mTargetMIP = v11;
              v8 = (ID3D11SamplerState *)v7->mTargetPlat->mRenderTargetView[0][v5 + 4 * v11];
            }
          }
          else
          {
            v8 = (ID3D11SamplerState *)v7->mTargetPlat->mRenderTargetView[0][v5 + 4i64 * v2->mDestFaceSlice];
          }
        }
      }
      v3->mCurrState.mDomainTextureSamplers[v6 + 9] = v8;
      ++v6;
      ++v4;
      ++v5;
    }
    while ( v6 < 7 );
    v12 = v3->mTarget;
    if ( v12->mDepthTexture )
      v3->mCurrState.mDepthStencilView = v12->mTargetPlat->mDepthStencilView;
    else
      v3->mCurrState.mDepthStencilView = 0i64;
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
  Illusion::Shader *v2; // r10
  Illusion::TaskRenderEnv *v3; // r9
  __int64 v4; // rax
  ID3D11SamplerState **v5; // r8
  signed __int64 v6; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rcx
  __int64 v11; // rcx
  ID3D11DomainShader *v12; // rcx
  signed __int64 v13; // rdx
  ID3D11SamplerState **v14; // rcx

  v2 = shader;
  v3 = this;
  if ( shader != this->mShader )
  {
    v4 = *(_QWORD *)&shader[1].mNode.mUID;
    if ( v4 )
    {
      v5 = this->mCurrState.mComputeSamplers;
      v6 = 12i64;
      this->mCurrState.mComputeShader = *(ID3D11ComputeShader **)(v4 + 200);
      do
      {
        *(v5 - 12) = 0i64;
        *v5 = 0i64;
        ++v5;
        --v6;
      }
      while ( v6 );
      this->mShader = v2;
    }
    else
    {
      this->mCurrState.mPixelShader = *(ID3D11PixelShader **)&shader[1].mNode.mChild[1][5].mUID;
      this->mCurrState.mVertexShader = (ID3D11VertexShader *)shader[1].mNode.mChild[0][6].mParent;
      v7 = shader[1].mResourceHandles.mNode.mPrev;
      if ( v7 )
        v8 = v7[13].mPrev;
      else
        v8 = 0i64;
      v3->mCurrState.mGeometryShader = (ID3D11GeometryShader *)v8;
      v9 = shader[1].mResourceHandles.mNode.mNext;
      if ( v9 )
        v10 = v9[13].mNext;
      else
        v10 = 0i64;
      v3->mCurrState.mHullShader = (ID3D11HullShader *)v10;
      v11 = *(_QWORD *)&shader[1].mTypeUID;
      if ( v11 )
        v12 = *(ID3D11DomainShader **)(v11 + 224);
      else
        v12 = 0i64;
      v3->mCurrState.mDomainShader = v12;
      v3->mCurrState.mInputLayout = 0i64;
      v13 = 12i64;
      v14 = v3->mCurrState.mPixelTextureSamplers;
      do
      {
        *(v14 - 12) = 0i64;
        *v14 = 0i64;
        v14[29] = 0i64;
        v14[41] = 0i64;
        v14[70] = 0i64;
        v14[82] = 0i64;
        v14[111] = 0i64;
        v14[123] = 0i64;
        ++v14;
        --v13;
      }
      while ( v13 );
      v3->mShader = v2;
    }
  }
}

// File Line: 931
// RVA: 0xA22320
void __fastcall Illusion::TaskRenderEnv::SetTexture(Illusion::TaskRenderEnv *this, Illusion::ShaderParam *shader_param, Illusion::Texture *texture)
{
  _QWORD *v3; // r9
  Illusion::Texture *v4; // r11
  Illusion::TaskRenderEnv *v5; // rbx
  Illusion::Target *v6; // rax
  signed int v7; // er8
  __int64 v8; // rcx
  ID3D11ShaderResourceView *v9; // rax
  __int64 v10; // rcx
  ID3D11ShaderResourceView *v11; // rax
  __int64 v12; // rcx
  ID3D11ShaderResourceView *v13; // rax
  __int64 v14; // rcx
  ID3D11ShaderResourceView *v15; // rax

  v3 = *(_QWORD **)&texture[1].mMipMapBias;
  v4 = texture;
  v5 = this;
  if ( v3 )
  {
    v6 = this->mTarget;
    v7 = -1;
    if ( v6 && v6->mNumTargetTextures == 1 && v4->mNode.mUID == v6->mTargetTexture[0]->mNode.mUID && v3[23] )
      v7 = this->mTargetMIP - 1;
    v8 = shader_param->mPixelTextureSlot;
    if ( (signed int)v8 >= 0 )
    {
      if ( v7 < 0 )
        v9 = (ID3D11ShaderResourceView *)v3[21];
      else
        v9 = *(ID3D11ShaderResourceView **)(v3[23] + 8i64 * v7);
      v5->mCurrState.mPixelTextureResources[v8] = v9;
    }
    v10 = shader_param->mGeometryTextureSlot;
    if ( (signed int)v10 >= 0 )
    {
      if ( v7 < 0 )
        v11 = (ID3D11ShaderResourceView *)v3[21];
      else
        v11 = *(ID3D11ShaderResourceView **)(v3[23] + 8i64 * v7);
      v5->mCurrState.mGeometryTextureResources[v10] = v11;
    }
    v12 = shader_param->mHullTextureSlot;
    if ( (signed int)v12 >= 0 )
    {
      if ( v7 < 0 )
        v13 = (ID3D11ShaderResourceView *)v3[21];
      else
        v13 = *(ID3D11ShaderResourceView **)(v3[23] + 8i64 * v7);
      v5->mCurrState.mHullTextureResources[v12] = v13;
    }
    v14 = shader_param->mDomainTextureSlot;
    if ( (signed int)v14 >= 0 )
    {
      if ( v7 < 0 )
        v15 = (ID3D11ShaderResourceView *)v3[21];
      else
        v15 = *(ID3D11ShaderResourceView **)(v3[23] + 8i64 * v7);
      v5->mCurrState.mDomainTextureResources[v14] = v15;
    }
    if ( shader_param->mVertexTextureSlot >= 0 )
      v5->mCurrState.mVertexTextureResources[shader_param->mVertexTextureSlot] = (ID3D11ShaderResourceView *)v3[21];
    if ( shader_param->mComputeTextureSlot >= 0 )
      v5->mCurrState.mComputeResources[shader_param->mComputeTextureSlot] = (ID3D11ShaderResourceView *)v3[21];
    if ( shader_param->mPixelSamplerSlot >= 0 )
      v5->mCurrState.mPixelTextureSamplers[shader_param->mPixelSamplerSlot] = (ID3D11SamplerState *)v3[24];
    if ( shader_param->mVertexSamplerSlot >= 0 )
      v5->mCurrState.mVertexTextureSamplers[shader_param->mVertexSamplerSlot] = (ID3D11SamplerState *)v3[24];
    if ( shader_param->mComputeSamplerSlot >= 0 )
      v5->mCurrState.mComputeSamplers[shader_param->mComputeSamplerSlot] = (ID3D11SamplerState *)v3[24];
    if ( shader_param->mGeometrySamplerSlot >= 0 )
      v5->mCurrState.mGeometryTextureSamplers[shader_param->mGeometrySamplerSlot] = (ID3D11SamplerState *)v3[24];
    if ( shader_param->mHullSamplerSlot >= 0 )
      v5->mCurrState.mHullTextureSamplers[shader_param->mHullSamplerSlot] = (ID3D11SamplerState *)v3[24];
    if ( shader_param->mDomainSamplerSlot >= 0 )
      v5->mCurrState.mDomainTextureSamplers[shader_param->mDomainSamplerSlot] = (ID3D11SamplerState *)v3[24];
  }
  else
  {
    UFG::qPrintf((const char *)&stru_141A183E8.skipToken.getType, texture->mDebugName);
    v5->mAbortNextDraw = 1;
  }
}

// File Line: 1052
// RVA: 0xA21A50
void __fastcall Illusion::TaskRenderEnv::SetConstBuffer(Illusion::TaskRenderEnv *this, Illusion::ShaderParam *shader_param, void *data)
{
  __int64 v3; // rax
  void *v4; // rbp
  Illusion::ShaderParam *v5; // rbx
  Illusion::TaskRenderEnv *v6; // rdi
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  ID3D11Buffer *v12; // rax
  unsigned int v13; // esi
  UFG::qBaseTreeRB *v14; // rax
  const void **v15; // rax
  int v16; // ST30_4
  unsigned int v17; // ST28_4
  __int64 v18; // [rsp+68h] [rbp+10h]
  void *value; // [rsp+70h] [rbp+18h]

  value = data;
  v3 = shader_param->mPixelConstantSlot;
  v4 = data;
  v5 = shader_param;
  v6 = this;
  if ( (signed int)v3 >= 0 )
  {
    this->mCurrState.mPixelConstantBuffers[v3] = shader_param->mConstantBuffer;
    this->mCurrState.mPixelConstantAddress[shader_param->mPixelConstantSlot] = 0i64;
  }
  v7 = shader_param->mVertexConstantSlot;
  if ( (signed int)v7 >= 0 )
  {
    this->mCurrState.mVertexConstantBuffers[v7] = shader_param->mConstantBuffer;
    this->mCurrState.mVertexConstantAddress[shader_param->mVertexConstantSlot] = 0i64;
  }
  v8 = shader_param->mComputeConstantSlot;
  if ( (signed int)v8 >= 0 )
  {
    this->mCurrState.mComputeConstantBuffers[v8] = shader_param->mConstantBuffer;
    this->mCurrState.mComputeConstantAddress[shader_param->mComputeConstantSlot] = 0i64;
  }
  v9 = shader_param->mGeometryConstantSlot;
  if ( (signed int)v9 >= 0 )
  {
    this->mCurrState.mGeometryConstantBuffers[v9] = shader_param->mConstantBuffer;
    this->mCurrState.mGeometryConstantAddress[shader_param->mGeometryConstantSlot] = 0i64;
  }
  v10 = shader_param->mHullConstantSlot;
  if ( (signed int)v10 >= 0 )
  {
    this->mCurrState.mHullConstantBuffers[v10] = shader_param->mConstantBuffer;
    this->mCurrState.mHullConstantAddress[shader_param->mHullConstantSlot] = 0i64;
  }
  v11 = shader_param->mDomainConstantSlot;
  if ( (signed int)v11 >= 0 )
  {
    this->mCurrState.mDomainConstantBuffers[v11] = shader_param->mConstantBuffer;
    this->mCurrState.mDomainConstantAddress[shader_param->mDomainConstantSlot] = 0i64;
  }
  v12 = shader_param->mConstantBuffer;
  v18 = 0i64;
  v13 = (unsigned int)v12 ^ HIDWORD(v12);
  if ( (_DWORD)v12 != HIDWORD(v12)
    && (v14 = UFG::qBaseTreeRB::Get(&this->mConstantBufferValues.mTree.mTree, v13)) != 0i64 )
  {
    v15 = (const void **)&v14->mNULL.mParent;
  }
  else
  {
    v15 = (const void **)&v18;
  }
  if ( !*v15 || memcmp(*v15, v4, v5->mNumBytes) )
  {
    v16 = 0;
    v17 = v5->mNumBytes;
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Buffer *, _QWORD, _QWORD, void *, unsigned int, int))v6->mContext->vfptr[16].QueryInterface)(
      v6->mContext,
      v5->mConstantBuffer,
      0i64,
      0i64,
      v4,
      v17,
      v16);
    UFG::qMap<void *>::Set(&v6->mConstantBufferValues, v13, &value);
  }
}

// File Line: 1164
// RVA: 0xA21BF0
void __fastcall Illusion::TaskRenderEnv::SetConstBuffer_StateBlock(Illusion::TaskRenderEnv *this, Illusion::ShaderParam *shader_param, void *data)
{
  void *v3; // rdi
  Illusion::ShaderParam *v4; // rbx
  Illusion::TaskRenderEnv *v5; // rsi
  unsigned int v6; // eax
  unsigned int v7; // ebp
  UFG::qBaseTreeRB *v8; // rax
  __int64 *v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // r14
  UFG::qBaseTreeRB *v12; // rdi
  UFG::allocator::free_link *v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // rax
  void *v20; // [rsp+28h] [rbp-50h]
  unsigned int v21; // [rsp+30h] [rbp-48h]
  unsigned int v22; // [rsp+34h] [rbp-44h]
  unsigned int dest; // [rsp+38h] [rbp-40h]
  int v24; // [rsp+3Ch] [rbp-3Ch]
  int v25; // [rsp+40h] [rbp-38h]
  __int64 v26; // [rsp+88h] [rbp+10h]
  UFG::allocator::free_link *v27; // [rsp+98h] [rbp+20h]

  v3 = data;
  v4 = shader_param;
  v5 = this;
  v26 = 0i64;
  v6 = UFG::qDataHash32(data, shader_param->mNumBytes, 0xFFFFFFFF);
  v7 = v6;
  v27 = 0i64;
  if ( !v6
    || (v8 = UFG::qBaseTreeRB::Get(&Illusion::TaskRenderEnv::mStateBlockConstantBufferValues.mTree.mTree, v6),
        v9 = (__int64 *)&v8->mNULL,
        !v8) )
  {
    v9 = (__int64 *)&v27;
  }
  v10 = *v9;
  if ( v10 )
  {
    v26 = v10;
  }
  else
  {
    UFG::qMemSet(&dest, 0, 0x18u);
    dest = v4->mNumBytes;
    v24 = 1;
    v25 = 4;
    v20 = v3;
    v21 = dest;
    v22 = dest;
    ((void (__fastcall *)(ID3D11Device *, unsigned int *, void **, __int64 *, signed __int64, void *, _QWORD, _QWORD, _QWORD))UFG::gD3D11Device->vfptr->VSSetConstantBuffers)(
      UFG::gD3D11Device,
      &dest,
      &v20,
      &v26,
      -2i64,
      v3,
      *(_QWORD *)&v21,
      *(_QWORD *)&dest,
      *(_QWORD *)&v25);
    v11 = v26;
    if ( !v7
      || (v12 = UFG::qBaseTreeRB::Get(&Illusion::TaskRenderEnv::mStateBlockConstantBufferValues.mTree.mTree, v7)) == 0i64 )
    {
      v13 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
      v12 = (UFG::qBaseTreeRB *)v13;
      v27 = v13;
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
    v10 = v26;
  }
  v14 = v4->mPixelConstantSlot;
  if ( (signed int)v14 >= 0 )
  {
    v5->mCurrState.mPixelConstantBuffers[v14] = (ID3D11Buffer *)v10;
    v5->mCurrState.mPixelConstantAddress[v4->mPixelConstantSlot] = 0i64;
    v10 = v26;
  }
  v15 = v4->mVertexConstantSlot;
  if ( (signed int)v15 >= 0 )
  {
    v5->mCurrState.mVertexConstantBuffers[v15] = (ID3D11Buffer *)v10;
    v5->mCurrState.mVertexConstantAddress[v4->mVertexConstantSlot] = 0i64;
    v10 = v26;
  }
  v16 = v4->mComputeConstantSlot;
  if ( (signed int)v16 >= 0 )
  {
    v5->mCurrState.mComputeConstantBuffers[v16] = (ID3D11Buffer *)v10;
    v5->mCurrState.mComputeConstantAddress[v4->mComputeConstantSlot] = 0i64;
    v10 = v26;
  }
  v17 = v4->mGeometryConstantSlot;
  if ( (signed int)v17 >= 0 )
  {
    v5->mCurrState.mGeometryConstantBuffers[v17] = (ID3D11Buffer *)v10;
    v5->mCurrState.mGeometryConstantAddress[v4->mGeometryConstantSlot] = 0i64;
    v10 = v26;
  }
  v18 = v4->mHullConstantSlot;
  if ( (signed int)v18 >= 0 )
  {
    v5->mCurrState.mHullConstantBuffers[v18] = (ID3D11Buffer *)v10;
    v5->mCurrState.mHullConstantAddress[v4->mHullConstantSlot] = 0i64;
    v10 = v26;
  }
  v19 = v4->mDomainConstantSlot;
  if ( (signed int)v19 >= 0 )
  {
    v5->mCurrState.mDomainConstantBuffers[v19] = (ID3D11Buffer *)v10;
    v5->mCurrState.mDomainConstantAddress[v4->mDomainConstantSlot] = 0i64;
  }
}

// File Line: 1331
// RVA: 0xA17BF0
void __fastcall Illusion::TaskRenderEnv::ClearTarget(Illusion::TaskRenderEnv *this, Illusion::ClearCommandParams *clear_params)
{
  Illusion::ClearCommandParams *v2; // rbp
  Illusion::TaskRenderEnv *v3; // r14
  Illusion::Target *v4; // rsi
  unsigned int v5; // er12
  int v6; // xmm1_4
  signed int v7; // ebx
  __int64 v8; // rdi
  int v9; // xmm0_4
  int v10; // xmm1_4
  signed __int64 v11; // r15
  Illusion::BeginTargetCommandParams *v12; // rdx
  Illusion::TargetPlat *v13; // r10
  Illusion::Texture *v14; // rcx
  char v15; // al
  bool v16; // cf
  bool v17; // zf
  ID3D11DeviceContext *v18; // rcx
  unsigned int v19; // eax
  __int128 v20; // xmm3
  char v21; // ST20_1
  float v22; // [rsp+30h] [rbp-28h]
  int v23; // [rsp+34h] [rbp-24h]
  int v24; // [rsp+38h] [rbp-20h]
  int v25; // [rsp+3Ch] [rbp-1Ch]

  v2 = clear_params;
  v3 = this;
  this->mCurrState.mInComputePipeline = 0;
  Illusion::TaskRenderEnv::PushStateToDevice(this);
  v4 = v3->mTarget;
  v5 = 0;
  if ( v2->mFlags & 1 )
  {
    v6 = LODWORD(v2->mColour.g);
    v7 = 0;
    v8 = 0i64;
    v22 = v2->mColour.r;
    v9 = LODWORD(v2->mColour.b);
    v23 = v6;
    v10 = LODWORD(v2->mColour.a);
    v24 = v9;
    v25 = v10;
    if ( (signed int)v4->mNumTargetTextures > 0 )
    {
      v11 = 32i64;
      do
      {
        v12 = v2->mTargetParams;
        v13 = v4->mTargetPlat;
        v14 = v4->mTargetTexture[v7];
        v15 = v14->mType;
        if ( v15 != 2 && v15 != 3 )
        {
          v16 = v14->mNumMipMaps < 1u;
          v17 = v14->mNumMipMaps == 1;
          v18 = v3->mContext;
          if ( v16 || v17 )
            ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, float *))v18->vfptr[16].Release)(
              v18,
              *(_QWORD *)(&v13->mResolveDepthSurface + v11),
              &v22);
          else
            ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11RenderTargetView *, float *))v18->vfptr[16].Release)(
              v18,
              v13->mRenderTargetView[0][v8 + 4i64 * (signed int)v12->mDestMipLevel],
              &v22);
        }
        else
        {
          ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11RenderTargetView *, float *))v3->mContext->vfptr[16].Release)(
            v3->mContext,
            v13->mRenderTargetView[0][v8 + 4i64 * (signed int)v12->mDestFaceSlice],
            &v22);
        }
        ++v7;
        ++v8;
        v11 += 8i64;
      }
      while ( v7 < (signed int)v4->mNumTargetTextures );
    }
  }
  if ( v4->mDepthTexture )
  {
    v19 = v2->mFlags;
    if ( v19 & 2 )
      v5 = 1;
    if ( v19 & 4 )
      v5 |= 2u;
    if ( v5 )
    {
      v20 = LODWORD(v2->mDepth);
      v21 = v2->mStencil;
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11DepthStencilView *, _QWORD))v3->mContext->vfptr[17].Release)(
        v3->mContext,
        v4->mTargetPlat->mDepthStencilView,
        v5);
    }
  }
}

// File Line: 1408
// RVA: 0xA20E10
void __fastcall Illusion::TaskRenderEnv::PushStateToDevice(Illusion::TaskRenderEnv *this)
{
  Illusion::Shader *v1; // rdx
  Illusion::TaskRenderEnv *v2; // rsi
  Illusion::D3DContextState *v3; // rdi
  Illusion::D3DContextState *v4; // rbx
  signed __int64 v5; // rax
  __int128 v6; // xmm0
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  __int128 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1

  v1 = this->mShader;
  v2 = this;
  if ( v1 )
  {
    if ( !this->mCurrState.mInputLayout )
      this->mCurrState.mInputLayout = Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Get(
                                        (Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *)&this->mInputLayoutCache.vfptr,
                                        v1,
                                        this->mVertexDecl);
    if ( !v2->mCurrState.mInputLayout )
      v2->mAbortNextDraw = 1;
  }
  if ( !v2->mAbortNextDraw )
  {
    v3 = &v2->mDeviceState;
    v4 = &v2->mCurrState;
    Illusion::D3DContextState::PushStateDelta(&v2->mCurrState, v2->mContext, &v2->mDeviceState);
    if ( ((unsigned __int8)((_BYTE)v2 + 8) | (unsigned __int8)((_BYTE)v2 + 24)) & 0xF )
    {
      memmove(&v2->mDeviceState, &v2->mCurrState, 0x910ui64);
    }
    else
    {
      v5 = 18i64;
      do
      {
        v6 = *(_OWORD *)&v4->mInComputePipeline;
        v7 = *(_OWORD *)v4->mComputeConstantBuffers;
        v3 = (Illusion::D3DContextState *)((char *)v3 + 128);
        v4 = (Illusion::D3DContextState *)((char *)v4 + 128);
        *(_OWORD *)&v3[-1].mDomainTextureSamplers[5] = v6;
        v8 = *(_OWORD *)&v4[-1].mDomainTextureSamplers[9];
        *(_OWORD *)&v3[-1].mDomainTextureSamplers[7] = v7;
        v9 = *(_OWORD *)&v4[-1].mDomainTextureSamplers[11];
        *(_OWORD *)&v3[-1].mDomainTextureSamplers[9] = v8;
        v10 = *(_OWORD *)&v4[-1].mRenderTargets[1];
        *(_OWORD *)&v3[-1].mDomainTextureSamplers[11] = v9;
        v11 = *(_OWORD *)&v4[-1].mRenderTargets[3];
        *(_OWORD *)&v3[-1].mRenderTargets[1] = v10;
        v12 = *(_OWORD *)&v4[-1].mBlendState;
        *(_OWORD *)&v3[-1].mRenderTargets[3] = v11;
        v13 = *(_OWORD *)&v4[-1].mDepthState;
        *(_OWORD *)&v3[-1].mBlendState = v12;
        *(_OWORD *)&v3[-1].mDepthState = v13;
        --v5;
      }
      while ( v5 );
      *(_OWORD *)&v3->mInComputePipeline = *(_OWORD *)&v4->mInComputePipeline;
    }
  }
}

// File Line: 1430
// RVA: 0xA19D60
_BOOL8 __fastcall Illusion::TaskRenderEnv::DispatchCompute(Illusion::TaskRenderEnv *this, unsigned int thread_group_x, unsigned int thread_group_y, unsigned int thread_group_z)
{
  bool v4; // zf
  unsigned int v5; // esi
  unsigned int v6; // ebp
  unsigned int v7; // er14
  Illusion::TaskRenderEnv *v8; // rbx
  bool v9; // di
  _BOOL8 result; // rax

  v4 = this->mAbortNextDraw == 0;
  v5 = thread_group_z;
  v6 = thread_group_y;
  v7 = thread_group_x;
  v8 = this;
  this->mCurrState.mInComputePipeline = 1;
  v9 = v4;
  Illusion::TaskRenderEnv::PushStateToDevice(this);
  if ( !v8->mAbortNextDraw )
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))v8->mContext->vfptr[13].Release)(
      v8->mContext,
      v7,
      v6,
      v5);
  result = v9;
  v8->mAbortNextDraw = 0;
  return result;
}

// File Line: 1443
// RVA: 0xA22570
_BOOL8 __fastcall Illusion::TaskRenderEnv::SubmitMesh(Illusion::TaskRenderEnv *this, int elem_offset, int index_count)
{
  bool v3; // zf
  unsigned int v4; // ebp
  int v5; // esi
  Illusion::TaskRenderEnv *v6; // rbx
  bool v7; // di

  v3 = this->mAbortNextDraw == 0;
  v4 = index_count;
  v5 = elem_offset;
  v6 = this;
  this->mCurrState.mInComputePipeline = 0;
  v7 = v3;
  Illusion::TaskRenderEnv::PushStateToDevice(this);
  if ( !v6->mAbortNextDraw )
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD))v6->mContext->vfptr[4].QueryInterface)(
      v6->mContext,
      v4,
      v5 - v6->mCurrState.mIndexBufferOffset,
      0i64);
  v6->mAbortNextDraw = 0;
  return v7;
}

// File Line: 1481
// RVA: 0xA225F0
_BOOL8 __fastcall Illusion::TaskRenderEnv::SubmitMeshInstanced(Illusion::TaskRenderEnv *this, unsigned int instanceCount, int elem_offset, int index_count)
{
  bool v4; // zf
  unsigned int v5; // ebp
  int v6; // esi
  unsigned int v7; // er14
  Illusion::TaskRenderEnv *v8; // rbx
  bool v9; // di
  int v10; // ST28_4
  int v11; // ST20_4
  _BOOL8 result; // rax

  v4 = this->mAbortNextDraw == 0;
  v5 = index_count;
  v6 = elem_offset;
  v7 = instanceCount;
  v8 = this;
  this->mCurrState.mInComputePipeline = 0;
  v9 = v4;
  Illusion::TaskRenderEnv::PushStateToDevice(this);
  if ( !v8->mAbortNextDraw )
  {
    v10 = 0;
    v11 = 0;
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, _QWORD, int, int))v8->mContext->vfptr[6].Release)(
      v8->mContext,
      v5,
      v7,
      v6 - v8->mCurrState.mIndexBufferOffset,
      v11,
      v10);
  }
  result = v9;
  v8->mAbortNextDraw = 0;
  return result;
}

