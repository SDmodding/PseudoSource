// File Line: 23
// RVA: 0x944400
void __fastcall Scaleform::Render::ShapeDataFloatMP::ShapeDataFloatMP(Scaleform::Render::ShapeDataFloatMP *this)
{
  Scaleform::Render::ShapeDataFloatMP *v1; // rbx
  Scaleform::Render::ShapeDataFloat *v2; // rdi
  Scaleform::Render::ShapeDataFloat *v3; // rax
  Scaleform::Render::ShapeDataFloat *v4; // rax
  Scaleform::Render::ShapeDataFloat *v5; // rcx
  int v6; // [rsp+48h] [rbp+10h]
  Scaleform::Render::ShapeDataFloat *v7; // [rsp+50h] [rbp+18h]

  v1 = this;
  Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider((Scaleform::Render::ShapeMeshProvider *)&this->vfptr);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataFloatMP::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshProvider_RCImpl,2>'};
  v1->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::ShapeDataFloatMP::`vftable'{for `Scaleform::Render::MeshProvider'};
  v2 = 0i64;
  v1->pData.pObject = 0i64;
  v6 = 71;
  v3 = (Scaleform::Render::ShapeDataFloat *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::ShapeDataFloatMP *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              v1,
                                              128i64,
                                              &v6,
                                              -2i64);
  v7 = v3;
  if ( v3 )
  {
    Scaleform::Render::ShapeDataFloat::ShapeDataFloat(v3);
    v2 = v4;
  }
  v5 = v1->pData.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount) && v5 )
    v5->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
  v1->pData.pObject = v2;
}

// File Line: 28
// RVA: 0x965350
void __fastcall Scaleform::Render::ShapeDataFloatMP::CountLayers(Scaleform::Render::ShapeDataFloatMP *this)
{
  Scaleform::Render::ShapeDataFloatMP *v1; // rbx
  Scaleform::Render::ShapeDataFloat *v2; // rdi
  Scaleform::Render::ShapeDataInterface *v3; // rcx

  v1 = this;
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape((Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&this->pData.pObject->vfptr);
  v2 = v1->pData.pObject;
  if ( v2 )
    _InterlockedExchangeAdd(&v2->RefCount, 1u);
  v3 = v1->pShapeData.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) && v3 )
    v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  v1->pShapeData.pObject = (Scaleform::Render::ShapeDataInterface *)&v2->vfptr;
  Scaleform::Render::ShapeMeshProvider::acquireShapeData((Scaleform::Render::ShapeMeshProvider *)&v1->vfptr);
}

