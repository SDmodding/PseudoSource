// File Line: 169
// RVA: 0x9FF040
Scaleform::Render::D3D1x::TextureManager *__fastcall Scaleform::Render::D3D1x::HAL::GetTextureManager(Scaleform::Render::D3D1x::HAL *this)
{
  return this->pTextureManager.pObject;
}

// File Line: 182
// RVA: 0x9FEFF0
Scaleform::Render::D3D1x::MeshCache *__fastcall Scaleform::Render::D3D1x::HAL::GetMeshCache(Scaleform::Render::D3D1x::HAL *this)
{
  return &this->Cache;
}

// File Line: 183
// RVA: 0x9FF030
Scaleform::Render::D3D1x::RenderSync *__fastcall Scaleform::Render::D3D1x::HAL::GetRenderSync(Scaleform::Render::D3D1x::HAL *this)
{
  return &this->RSync;
}

// File Line: 188
// RVA: 0x9FF4E0
void __fastcall Scaleform::Render::D3D1x::HAL::MapVertexFormat(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::PrimitiveFillType fill, Scaleform::Render::VertexFormat *sourceFormat, Scaleform::Render::VertexFormat **single, Scaleform::Render::VertexFormat **batch, Scaleform::Render::VertexFormat **instanced)
{
  Scaleform::Render::D3D1x::ShaderManager::MapVertexFormat(
    &this->SManager,
    fill,
    sourceFormat,
    single,
    batch,
    instanced);
}

// File Line: 230
// RVA: 0xA032F0
void __fastcall Scaleform::Render::D3D1x::RenderTargetData::UpdateData(Scaleform::Render::RenderBuffer *buffer, ID3D11View *prt, Scaleform::Render::DepthStencilBuffer *pdsb, ID3D11View *pdss)
{
  ID3D11View *v4; // rdi
  Scaleform::Render::DepthStencilBuffer *v5; // r14
  ID3D11View *v6; // rsi
  Scaleform::Render::RenderBuffer *v7; // rbp
  Scaleform::Render::RenderBuffer::RenderTargetData *v8; // rbx
  Scaleform::Render::D3D1x::RenderTargetData *v9; // rax
  Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *v10; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::Render::DepthStencilBuffer *v12; // rcx

  if ( buffer )
  {
    v4 = pdss;
    v5 = pdsb;
    v6 = prt;
    v7 = buffer;
    v8 = buffer->pRenderTargetData;
    if ( v8 )
    {
      if ( prt )
        prt->vfptr->AddRef((IUnknown *)prt);
      if ( v4 )
        v4->vfptr->AddRef((IUnknown *)&v4->vfptr);
      v10 = v8[1].vfptr;
      if ( v10 )
        (*((void (**)(void))v10->__vecDelDtor + 2))();
      v11 = v8[1].pBuffer;
      if ( v11 )
        ((void (*)(void))v11->vfptr[2].__vecDelDtor)();
      if ( v5 )
        ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))v5->vfptr[1].__vecDelDtor)(v5);
      v12 = v8->pDepthStencilBuffer.pObject;
      if ( v12 )
        ((void (*)(void))v12->vfptr[2].__vecDelDtor)();
      v8->pDepthStencilBuffer.pObject = v5;
      v8[1].pBuffer = (Scaleform::Render::RenderBuffer *)v4;
      v8[1].vfptr = (Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *)v6;
    }
    else
    {
      v9 = (Scaleform::Render::D3D1x::RenderTargetData *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           48ui64,
                                                           0i64);
      if ( v9 )
        Scaleform::Render::D3D1x::RenderTargetData::RenderTargetData(v9, v7, v6, v5, v4);
      v7->pRenderTargetData = (Scaleform::Render::RenderBuffer::RenderTargetData *)&v9->vfptr;
    }
  }
}

// File Line: 267
// RVA: 0x9FB830
void __fastcall Scaleform::Render::D3D1x::RenderTargetData::RenderTargetData(Scaleform::Render::D3D1x::RenderTargetData *this, Scaleform::Render::RenderBuffer *buffer, ID3D11View *prt, Scaleform::Render::DepthStencilBuffer *pdsb, ID3D11View *pdss)
{
  Scaleform::Render::DepthStencilBuffer *v5; // rsi
  ID3D11View *v6; // rdi
  Scaleform::Render::D3D1x::RenderTargetData *v7; // rbx
  ID3D11View *v8; // rcx

  v5 = pdsb;
  v6 = prt;
  v7 = this;
  this->vfptr = (Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *)&Scaleform::Render::RenderBuffer::RenderTargetData::`vftable;
  this->pBuffer = buffer;
  if ( pdsb )
    ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))pdsb->vfptr[1].__vecDelDtor)(pdsb);
  v7->pDepthStencilBuffer.pObject = v5;
  v7->CacheID = 0i64;
  v7->vfptr = (Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *)&Scaleform::Render::D3D1x::RenderTargetData::`vftable;
  v7->pRenderSurface = v6;
  v7->pDSSurface = pdss;
  if ( v6 )
    v6->vfptr->AddRef((IUnknown *)&v6->vfptr);
  v8 = v7->pDSSurface;
  if ( v8 )
    ((void (__cdecl *)(ID3D11View *))v8->vfptr->AddRef)(v8);
}

