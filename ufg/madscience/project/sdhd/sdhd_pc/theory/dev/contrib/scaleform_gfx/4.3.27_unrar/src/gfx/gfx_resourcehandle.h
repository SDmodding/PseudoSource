// File Line: 99
// RVA: 0x78DB10
void __fastcall Scaleform::GFx::ResourceHandle::~ResourceHandle(Scaleform::GFx::ResourceHandle *this)
{
  Scaleform::GFx::Resource *pResource; // rcx

  if ( this->HType == RH_Pointer )
  {
    pResource = this->pResource;
    if ( pResource )
      Scaleform::GFx::Resource::Release(pResource);
  }
}

// File Line: 105
// RVA: 0x8A9000
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::ResourceHandle::operator=(
        Scaleform::GFx::ResourceHandle *this,
        Scaleform::GFx::ResourceHandle *src)
{
  Scaleform::GFx::Resource *pResource; // rcx
  Scaleform::GFx::Resource *v5; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  if ( src->HType == RH_Pointer )
  {
    pResource = src->pResource;
    if ( pResource )
      _InterlockedExchangeAdd(&pResource->RefCount.Value, 1u);
  }
  if ( this->HType == RH_Pointer )
  {
    v5 = this->pResource;
    if ( v5 )
    {
      if ( !_InterlockedDecrement(&v5->RefCount.Value) )
      {
        pLib = v5->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v5);
          v5->pLib = 0i64;
        }
        v5->vfptr->__vecDelDtor(v5, 1u);
      }
    }
  }
  this->HType = src->HType;
  this->pResource = src->pResource;
  return this;
}

// File Line: 205
// RVA: 0x790970
Scaleform::GFx::ResourceBindData *__fastcall Scaleform::GFx::ResourceBindData::operator=(
        Scaleform::GFx::ResourceBindData *this,
        Scaleform::GFx::ResourceBindData *src)
{
  if ( src->pResource.pObject )
    Scaleform::Render::RenderBuffer::AddRef(src->pResource.pObject);
  if ( this->pResource.pObject )
    Scaleform::GFx::Resource::Release(this->pResource.pObject);
  this->pResource.pObject = src->pResource.pObject;
  this->pBinding = src->pBinding;
  return this;
}

// File Line: 297
// RVA: 0x8DD940
Scaleform::GFx::ResourceBindData *__fastcall Scaleform::GFx::ResourceBinding::GetResourceData(
        Scaleform::GFx::ResourceBinding *this,
        Scaleform::GFx::ResourceBindData *result,
        Scaleform::GFx::ResourceHandle *h)
{
  volatile unsigned int BindIndex; // r8d
  Scaleform::GFx::Resource *pResource; // rsi
  Scaleform::GFx::Resource *pObject; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  result->pResource.pObject = 0i64;
  result->pBinding = 0i64;
  if ( h->HType == RH_Index )
  {
    BindIndex = h->BindIndex;
    if ( this->Frozen && BindIndex < this->ResourceCount )
      Scaleform::GFx::ResourceBindData::operator=(result, &this->pResources[BindIndex]);
    else
      Scaleform::GFx::ResourceBinding::GetResourceData_Locked(this, result, BindIndex);
  }
  else
  {
    result->pBinding = this;
    if ( h->HType )
    {
      pResource = 0i64;
    }
    else
    {
      pResource = h->pResource;
      if ( pResource )
        _InterlockedExchangeAdd(&pResource->RefCount.Value, 1u);
    }
    pObject = result->pResource.pObject;
    if ( result->pResource.pObject && !_InterlockedDecrement(&pObject->RefCount.Value) )
    {
      pLib = pObject->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pObject);
        pObject->pLib = 0i64;
      }
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    }
    result->pResource.pObject = pResource;
  }
  return result;
}

// File Line: 325
// RVA: 0x7EED30
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::ResourceHandle::GetResource(
        Scaleform::GFx::ResourceHandle *this,
        Scaleform::GFx::ResourceBinding *pbinding)
{
  volatile unsigned int BindIndex; // r8d
  Scaleform::GFx::ResourceBindData *v4; // rdi
  Scaleform::GFx::Resource *pObject; // rbx
  Scaleform::GFx::ResourceBindData pdata; // [rsp+28h] [rbp-20h] BYREF

  if ( this->HType == RH_Pointer )
    return this->pResource;
  pdata.pResource.pObject = 0i64;
  pdata.pBinding = 0i64;
  BindIndex = this->BindIndex;
  if ( pbinding->Frozen && BindIndex < pbinding->ResourceCount )
  {
    v4 = &pbinding->pResources[BindIndex];
    if ( v4->pResource.pObject )
      Scaleform::Render::RenderBuffer::AddRef(v4->pResource.pObject);
    pObject = v4->pResource.pObject;
    pdata = *v4;
  }
  else
  {
    Scaleform::GFx::ResourceBinding::GetResourceData_Locked(pbinding, &pdata, BindIndex);
    pObject = pdata.pResource.pObject;
  }
  if ( pdata.pResource.pObject )
    Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
  return pObject;
}

// File Line: 372
// RVA: 0x8A3A20
void __fastcall Scaleform::GFx::ResourceData::DataInterface::~DataInterface(
        Scaleform::GFx::ResourceData::DataInterface *this)
{
  this->vfptr = (Scaleform::GFx::ResourceData::DataInterfaceVtbl *)&Scaleform::GFx::ResourceData::DataInterface::`vftable;
}

// File Line: 378
// RVA: 0x8B1E70
void __fastcall Scaleform::GFx::ImageFileKeyInterface::AddRef(
        Scaleform::GFx::ImageFileKeyInterface *this,
        Scaleform::GFx::Resource *hdata)
{
  Scaleform::Render::RenderBuffer::AddRef(hdata);
}

// File Line: 380
// RVA: 0x8FE620
void __fastcall Scaleform::GFx::GFxSystemFontResourceKeyInterface::Release(
        Scaleform::GFx::ImageFileKeyInterface *this,
        Scaleform::Render::RenderBuffer *hdata)
{
  Scaleform::RefCountImpl::Release(hdata);
}

