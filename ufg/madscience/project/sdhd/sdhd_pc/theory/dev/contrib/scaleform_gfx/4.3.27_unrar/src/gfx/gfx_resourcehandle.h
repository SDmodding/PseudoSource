// File Line: 99
// RVA: 0x78DB10
void __fastcall Scaleform::GFx::ResourceHandle::~ResourceHandle(Scaleform::GFx::ResourceHandle *this)
{
  if ( this->HType == RH_Pointer )
    JUMPOUT(this->pResource, 0i64, Scaleform::GFx::Resource::Release);
}

// File Line: 105
// RVA: 0x8A9000
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::ResourceHandle::operator=(Scaleform::GFx::ResourceHandle *this, Scaleform::GFx::ResourceHandle *src)
{
  Scaleform::GFx::ResourceHandle *v2; // rsi
  Scaleform::GFx::ResourceHandle *v3; // rdi
  Scaleform::GFx::Resource *v4; // rcx
  Scaleform::GFx::Resource *v5; // rbx
  Scaleform::GFx::ResourceLibBase *v6; // rcx

  v2 = src;
  v3 = this;
  if ( src->HType == RH_Pointer )
  {
    v4 = src->pResource;
    if ( v4 )
      _InterlockedExchangeAdd(&v4->RefCount.Value, 1u);
  }
  if ( v3->HType == RH_Pointer )
  {
    v5 = v3->pResource;
    if ( v5 )
    {
      if ( !_InterlockedDecrement(&v5->RefCount.Value) )
      {
        v6 = v5->pLib;
        if ( v6 )
        {
          v6->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)v5);
          v5->pLib = 0i64;
        }
        v5->vfptr->__vecDelDtor(v5, 1u);
      }
    }
  }
  v3->HType = v2->HType;
  v3->pResource = v2->pResource;
  return v3;
}

// File Line: 205
// RVA: 0x790970
Scaleform::GFx::ResourceBindData *__fastcall Scaleform::GFx::ResourceBindData::operator=(Scaleform::GFx::ResourceBindData *this, Scaleform::GFx::ResourceBindData *src)
{
  Scaleform::GFx::ResourceBindData *v2; // rbx
  Scaleform::GFx::ResourceBindData *v3; // rdi

  v2 = this;
  v3 = src;
  if ( src->pResource.pObject )
    Scaleform::Render::RenderBuffer::AddRef(src->pResource.pObject);
  if ( v2->pResource.pObject )
    Scaleform::GFx::Resource::Release(v2->pResource.pObject);
  v2->pResource.pObject = v3->pResource.pObject;
  v2->pBinding = v3->pBinding;
  return v2;
}

// File Line: 297
// RVA: 0x8DD940
Scaleform::GFx::ResourceBindData *__fastcall Scaleform::GFx::ResourceBinding::GetResourceData(Scaleform::GFx::ResourceBinding *this, Scaleform::GFx::ResourceBindData *result, Scaleform::GFx::ResourceHandle *h)
{
  Scaleform::GFx::ResourceBindData *v3; // rbx
  volatile unsigned int v4; // er8
  Scaleform::GFx::Resource *v5; // rsi
  Scaleform::GFx::Resource *v6; // rdi
  Scaleform::GFx::ResourceLibBase *v7; // rcx

  v3 = result;
  result->pResource.pObject = 0i64;
  result->pBinding = 0i64;
  if ( h->HType == 1 )
  {
    v4 = h->BindIndex;
    if ( this->Frozen && v4 < this->ResourceCount )
      Scaleform::GFx::ResourceBindData::operator=(result, &this->pResources[v4]);
    else
      Scaleform::GFx::ResourceBinding::GetResourceData_Locked(this, result, v4);
  }
  else
  {
    result->pBinding = this;
    if ( h->HType )
    {
      v5 = 0i64;
    }
    else
    {
      v5 = h->pResource;
      if ( v5 )
        _InterlockedExchangeAdd(&v5->RefCount.Value, 1u);
    }
    v6 = result->pResource.pObject;
    if ( result->pResource.pObject && !_InterlockedDecrement(&v6->RefCount.Value) )
    {
      v7 = v6->pLib;
      if ( v7 )
      {
        v7->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)v6);
        v6->pLib = 0i64;
      }
      v6->vfptr->__vecDelDtor(v6, 1u);
    }
    v3->pResource.pObject = v5;
  }
  return v3;
}

// File Line: 325
// RVA: 0x7EED30
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::ResourceHandle::GetResource(Scaleform::GFx::ResourceHandle *this, Scaleform::GFx::ResourceBinding *pbinding)
{
  volatile unsigned int v3; // er8
  Scaleform::GFx::ResourceBindData *v4; // rdi
  Scaleform::GFx::Resource *v5; // rbx
  Scaleform::GFx::ResourceBindData pdata; // [rsp+28h] [rbp-20h]

  if ( this->HType == RH_Pointer )
    return this->pResource;
  pdata.pResource.pObject = 0i64;
  pdata.pBinding = 0i64;
  v3 = this->BindIndex;
  if ( pbinding->Frozen && v3 < pbinding->ResourceCount )
  {
    v4 = &pbinding->pResources[v3];
    if ( v4->pResource.pObject )
      Scaleform::Render::RenderBuffer::AddRef(v4->pResource.pObject);
    if ( pdata.pResource.pObject )
      Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
    v5 = v4->pResource.pObject;
    pdata.pResource.pObject = v4->pResource.pObject;
    pdata.pBinding = v4->pBinding;
  }
  else
  {
    Scaleform::GFx::ResourceBinding::GetResourceData_Locked(pbinding, &pdata, v3);
    v5 = pdata.pResource.pObject;
  }
  if ( pdata.pResource.pObject )
    Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
  return v5;
}

// File Line: 372
// RVA: 0x8A3A20
void __fastcall Scaleform::GFx::ResourceData::DataInterface::~DataInterface(Scaleform::GFx::ResourceData::DataInterface *this)
{
  this->vfptr = (Scaleform::GFx::ResourceData::DataInterfaceVtbl *)&Scaleform::GFx::ResourceData::DataInterface::`vftable';
}

// File Line: 378
// RVA: 0x8B1E70
void __fastcall Scaleform::GFx::ImageFileKeyInterface::AddRef(Scaleform::GFx::ImageFileKeyInterface *this, void *hdata)
{
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)hdata);
}

// File Line: 380
// RVA: 0x8FE620
void __fastcall Scaleform::GFx::GFxSystemFontResourceKeyInterface::Release(Scaleform::GFx::ImageFileKeyInterface *this, void *hdata)
{
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)hdata);
}

