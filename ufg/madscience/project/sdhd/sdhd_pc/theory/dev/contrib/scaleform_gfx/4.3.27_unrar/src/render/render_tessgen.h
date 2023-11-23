// File Line: 53
// RVA: 0x93FB10
void __fastcall Scaleform::Render::MeshGenerator::MeshGenerator(
        Scaleform::Render::MeshGenerator *this,
        Scaleform::MemoryHeap *h)
{
  Scaleform::Render::LinearHeap *p_Heap3; // rdi

  this->Heap1.pHeap = h;
  this->Heap1.Granularity = 0x2000i64;
  this->Heap1.pPagePool = 0i64;
  this->Heap1.pLastPage = 0i64;
  this->Heap1.MaxPages = 0i64;
  this->Heap2.pHeap = h;
  this->Heap2.Granularity = 0x2000i64;
  this->Heap2.pPagePool = 0i64;
  this->Heap2.pLastPage = 0i64;
  this->Heap2.MaxPages = 0i64;
  p_Heap3 = &this->Heap3;
  this->Heap3.pHeap = h;
  this->Heap3.Granularity = 0x2000i64;
  this->Heap3.pPagePool = 0i64;
  this->Heap3.pLastPage = 0i64;
  this->Heap3.MaxPages = 0i64;
  this->Heap4.pHeap = h;
  this->Heap4.Granularity = 0x2000i64;
  this->Heap4.pPagePool = 0i64;
  this->Heap4.pLastPage = 0i64;
  this->Heap4.MaxPages = 0i64;
  Scaleform::Render::Tessellator::Tessellator(&this->mTess, &this->Heap1, &this->Heap2);
  this->mStroker.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->mStroker.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::Stroker::`vftable;
  this->mStroker.pHeap = p_Heap3;
  this->mStroker.Path.Path.pHeap = p_Heap3;
  this->mStroker.Path.Path.Size = 0i64;
  this->mStroker.Path.Path.NumPages = 0i64;
  this->mStroker.Path.Path.MaxPages = 0i64;
  this->mStroker.Path.Path.Pages = 0i64;
  this->mStroker.Width = 1.0;
  this->mStroker.LineJoin = RoundJoin;
  this->mStroker.StartLineCap = RoundCap;
  this->mStroker.EndLineCap = RoundCap;
  this->mStroker.MiterLimit = 3.0;
  this->mStroker.CurveTolerance = 1.0;
  this->mStroker.IntersectionEpsilon = 0.0099999998;
  this->mStroker.Closed = 0;
  Scaleform::Render::StrokeSorter::StrokeSorter(&this->mStrokeSorter, &this->Heap4);
  Scaleform::Render::Hairliner::Hairliner(&this->mHairliner, p_Heap3);
  Scaleform::Render::StrokerAA::StrokerAA(&this->mStrokerAA, p_Heap3);
}

// File Line: 57
// RVA: 0x95F810
void __fastcall Scaleform::Render::MeshGenerator::Clear(Scaleform::Render::MeshGenerator *this)
{
  (*((void (__fastcall **)(Scaleform::Render::Tessellator *))&this->mTess.vfptr->__vecDelDtor + 1))(&this->mTess);
  (*((void (__fastcall **)(Scaleform::Render::Stroker *))&this->mStroker.vfptr->__vecDelDtor + 1))(&this->mStroker);
  (*((void (__fastcall **)(Scaleform::Render::StrokeSorter *))&this->mStrokeSorter.vfptr->__vecDelDtor + 1))(&this->mStrokeSorter);
  (*((void (__fastcall **)(Scaleform::Render::Hairliner *))&this->mHairliner.vfptr->__vecDelDtor + 1))(&this->mHairliner);
  (*((void (__fastcall **)(Scaleform::Render::StrokerAA *))&this->mStrokerAA.vfptr->__vecDelDtor + 1))(&this->mStrokerAA);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Heap1);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Heap2);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Heap3);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Heap4);
}

// File Line: 85
// RVA: 0x945000
void __fastcall Scaleform::Render::StrokeGenerator::StrokeGenerator(
        Scaleform::Render::StrokeGenerator *this,
        Scaleform::MemoryHeap *h)
{
  this->Heap1.pHeap = h;
  this->Heap1.Granularity = 0x2000i64;
  this->Heap1.pPagePool = 0i64;
  this->Heap1.pLastPage = 0i64;
  this->Heap1.MaxPages = 0i64;
  this->Heap2.pHeap = h;
  this->Heap2.Granularity = 0x2000i64;
  this->Heap2.pPagePool = 0i64;
  this->Heap2.pLastPage = 0i64;
  this->Heap2.MaxPages = 0i64;
  this->mStroker.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->mStroker.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::Stroker::`vftable;
  this->mStroker.pHeap = &this->Heap1;
  this->mStroker.Path.Path.pHeap = &this->Heap1;
  this->mStroker.Path.Path.Size = 0i64;
  this->mStroker.Path.Path.NumPages = 0i64;
  this->mStroker.Path.Path.MaxPages = 0i64;
  this->mStroker.Path.Path.Pages = 0i64;
  this->mStroker.Width = 1.0;
  this->mStroker.LineJoin = RoundJoin;
  this->mStroker.StartLineCap = RoundCap;
  this->mStroker.EndLineCap = RoundCap;
  this->mStroker.MiterLimit = 3.0;
  this->mStroker.CurveTolerance = 1.0;
  this->mStroker.IntersectionEpsilon = 0.0099999998;
  this->mStroker.Closed = 0;
  Scaleform::Render::StrokeSorter::StrokeSorter(&this->mStrokeSorter, &this->Heap2);
  this->mPath.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->mPath.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::VertexPath::`vftable;
  this->mPath.Vertices.pHeap = &this->Heap1;
  this->mPath.Vertices.Size = 0i64;
  this->mPath.Vertices.NumPages = 0i64;
  this->mPath.Vertices.MaxPages = 0i64;
  this->mPath.Vertices.Pages = 0i64;
  this->mPath.Paths.pHeap = &this->Heap1;
  this->mPath.Paths.Size = 0i64;
  this->mPath.Paths.NumPages = 0i64;
  this->mPath.Paths.MaxPages = 0i64;
  this->mPath.Paths.Pages = 0i64;
}

