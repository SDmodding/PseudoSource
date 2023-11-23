// File Line: 209
// RVA: 0x98DC00
hkLocalFrameGroup *__fastcall Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(hkSimpleLocalFrame *this)
{
  return this->m_group;
}

// File Line: 257
// RVA: 0x9E8600
void __fastcall Scaleform::Render::RBGenericImpl::DepthStencilBuffer::initSurface(
        Scaleform::Render::RBGenericImpl::DepthStencilBuffer *this,
        Scaleform::Render::DepthStencilSurface *surface)
{
  Scaleform::Render::DepthStencilSurface *pObject; // rcx

  if ( surface )
    _InterlockedExchangeAdd(&surface->RefCount, 1u);
  pObject = this->pSurface.pObject;
  if ( !pObject || _InterlockedDecrement(&pObject->RefCount) )
  {
    this->pSurface.pObject = surface;
  }
  else
  {
    pObject->vfptr->__vecDelDtor(pObject, 1u);
    this->pSurface.pObject = surface;
  }
}

