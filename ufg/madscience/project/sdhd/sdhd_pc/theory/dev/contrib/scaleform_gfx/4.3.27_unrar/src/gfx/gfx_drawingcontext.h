// File Line: 53
// RVA: 0x89C0D0
void __fastcall Scaleform::GFx::DrawingContext::PackedShape::PackedShape(
        Scaleform::GFx::DrawingContext::PackedShape *this,
        Scaleform::MemoryHeap *pHeap)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::`vftable;
  this->pContainer = &this->Container;
  this->Decoder.Decoder.Data = &this->Container;
  this->Decoder.OneOverMultiplier = 1.0;
  this->StartingPos = 0;
  this->Multiplier = 1.0;
  this->FillStyles.Data.Data = 0i64;
  this->FillStyles.Data.Size = 0i64;
  this->FillStyles.Data.Policy.Capacity = 0i64;
  this->StrokeStyles.Data.Data = 0i64;
  this->StrokeStyles.Data.Size = 0i64;
  this->StrokeStyles.Data.Policy.Capacity = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::DrawingContext::PackedShape::`vftable;
  this->Container.Data.Data = 0i64;
  this->Container.Data.Size = 0i64;
  this->Container.Data.Policy.Capacity = 0i64;
  this->Container.Data.pHeap = pHeap;
}

