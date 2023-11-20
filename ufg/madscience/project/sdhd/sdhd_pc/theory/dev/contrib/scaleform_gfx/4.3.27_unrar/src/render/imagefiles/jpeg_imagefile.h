// File Line: 92
// RVA: 0x896220
void __fastcall Scaleform::Render::JPEG::ExtraData::ExtraData(Scaleform::Render::JPEG::ExtraData *this, Scaleform::MemoryHeap *heap, unsigned __int64 sz)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::JPEG::ExtraData,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::JPEG::ExtraData::`vftable';
  this->Size = sz;
  this->Data = (char *)heap->vfptr->Alloc(heap, sz, 0i64);
}

// File Line: 96
// RVA: 0x8A45B0
void __fastcall Scaleform::Render::JPEG::ExtraData::~ExtraData(Scaleform::Render::JPEG::ExtraData *this)
{
  Scaleform::Render::JPEG::ExtraData *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::JPEG::ExtraData::`vftable';
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Data);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

