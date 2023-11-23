// File Line: 23
// RVA: 0x944400
void __fastcall Scaleform::Render::ShapeDataFloatMP::ShapeDataFloatMP(Scaleform::Render::ShapeDataFloatMP *this)
{
  Scaleform::Render::ShapeDataFloat *v2; // rdi
  Scaleform::Render::ShapeDataFloat *v3; // rax
  Scaleform::Render::ShapeDataFloat *v4; // rax
  Scaleform::Render::ShapeDataFloat *pObject; // rcx
  int v6; // [rsp+48h] [rbp+10h] BYREF
  Scaleform::Render::ShapeDataFloat *v7; // [rsp+50h] [rbp+18h]

  Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(this);
  this->Scaleform::Render::ShapeMeshProvider::Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataFloatMP::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>};
  this->Scaleform::Render::ShapeMeshProvider::Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::ShapeDataFloatMP::`vftable{for `Scaleform::Render::MeshProvider};
  v2 = 0i64;
  this->pData.pObject = 0i64;
  v6 = 71;
  v3 = (Scaleform::Render::ShapeDataFloat *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::ShapeDataFloatMP *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              128i64,
                                              &v6,
                                              -2i64);
  v7 = v3;
  if ( v3 )
  {
    Scaleform::Render::ShapeDataFloat::ShapeDataFloat(v3);
    v2 = v4;
  }
  pObject = this->pData.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->pData.pObject = v2;
}

// File Line: 28
// RVA: 0x965350
void __fastcall Scaleform::Render::ShapeDataFloatMP::CountLayers(Scaleform::Render::ShapeDataFloatMP *this)
{
  Scaleform::Render::ShapeDataFloat *pObject; // rdi
  Scaleform::Render::ShapeDataInterface *v3; // rcx

  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(this->pData.pObject);
  pObject = this->pData.pObject;
  if ( pObject )
    _InterlockedExchangeAdd(&pObject->RefCount, 1u);
  v3 = this->pShapeData.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) )
    v3->vfptr->__vecDelDtor(v3, 1u);
  this->pShapeData.pObject = pObject;
  Scaleform::Render::ShapeMeshProvider::acquireShapeData(this);
}

