// File Line: 169
// RVA: 0x9FF040
Scaleform::Render::D3D1x::TextureManager *__fastcall Scaleform::Render::D3D1x::HAL::GetTextureManager(
        Scaleform::Render::D3D1x::HAL *this)
{
  return this->pTextureManager.pObject;
}

// File Line: 182
// RVA: 0x9FEFF0
Scaleform::Render::D3D1x::MeshCache *__fastcall Scaleform::Render::D3D1x::HAL::GetMeshCache(
        Scaleform::Render::D3D1x::HAL *this)
{
  return &this->Cache;
}

// File Line: 183
// RVA: 0x9FF030
Scaleform::Render::D3D1x::RenderSync *__fastcall Scaleform::Render::D3D1x::HAL::GetRenderSync(
        Scaleform::Render::D3D1x::HAL *this)
{
  return &this->RSync;
}

// File Line: 188
// RVA: 0x9FF4E0
void __fastcall Scaleform::Render::D3D1x::HAL::MapVertexFormat(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::PrimitiveFillType fill,
        Scaleform::Render::VertexFormat *sourceFormat,
        Scaleform::Render::VertexFormat **single,
        Scaleform::Render::VertexFormat **batch,
        Scaleform::Render::VertexFormat **instanced)
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
void __fastcall Scaleform::Render::D3D1x::RenderTargetData::UpdateData(
        Scaleform::Render::RenderBuffer *buffer,
        ID3D11View *prt,
        Scaleform::Render::DepthStencilBuffer *pdsb,
        ID3D11View *pdss)
{
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // rbx
  Scaleform::Render::D3D1x::RenderTargetData *v9; // rax
  Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *vfptr; // rcx
  Scaleform::Render::RenderBuffer *pBuffer; // rcx
  Scaleform::Render::DepthStencilBuffer *pObject; // rcx

  if ( buffer )
  {
    pRenderTargetData = buffer->pRenderTargetData;
    if ( pRenderTargetData )
    {
      if ( prt )
        prt->vfptr->AddRef(prt);
      if ( pdss )
        pdss->vfptr->AddRef(pdss);
      vfptr = pRenderTargetData[1].vfptr;
      if ( vfptr )
        (*((void (__fastcall **)(Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *))vfptr->__vecDelDtor + 2))(vfptr);
      pBuffer = pRenderTargetData[1].pBuffer;
      if ( pBuffer )
        ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))pBuffer->vfptr[2].__vecDelDtor)(pBuffer);
      if ( pdsb )
        ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))pdsb->vfptr[1].__vecDelDtor)(pdsb);
      pObject = pRenderTargetData->pDepthStencilBuffer.pObject;
      if ( pObject )
        ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))pObject->vfptr[2].__vecDelDtor)(pObject);
      pRenderTargetData->pDepthStencilBuffer.pObject = pdsb;
      pRenderTargetData[1].pBuffer = (Scaleform::Render::RenderBuffer *)pdss;
      pRenderTargetData[1].vfptr = (Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *)prt;
    }
    else
    {
      v9 = (Scaleform::Render::D3D1x::RenderTargetData *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           48i64,
                                                           0i64);
      if ( v9 )
        Scaleform::Render::D3D1x::RenderTargetData::RenderTargetData(v9, buffer, prt, pdsb, pdss);
      buffer->pRenderTargetData = v9;
    }
  }
}

// File Line: 267
// RVA: 0x9FB830
void __fastcall Scaleform::Render::D3D1x::RenderTargetData::RenderTargetData(
        Scaleform::Render::D3D1x::RenderTargetData *this,
        Scaleform::Render::RenderBuffer *buffer,
        ID3D11View *prt,
        Scaleform::Render::DepthStencilBuffer *pdsb,
        ID3D11View *pdss)
{
  ID3D11View *pDSSurface; // rcx

  this->vfptr = (Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *)&Scaleform::Render::RenderBuffer::RenderTargetData::`vftable;
  this->pBuffer = buffer;
  if ( pdsb )
    ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))pdsb->vfptr[1].__vecDelDtor)(pdsb);
  this->pDepthStencilBuffer.pObject = pdsb;
  this->CacheID = 0i64;
  this->vfptr = (Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *)&Scaleform::Render::D3D1x::RenderTargetData::`vftable;
  this->pRenderSurface = prt;
  this->pDSSurface = pdss;
  if ( prt )
    prt->vfptr->AddRef(prt);
  pDSSurface = this->pDSSurface;
  if ( pDSSurface )
    pDSSurface->vfptr->AddRef(pDSSurface);
}

