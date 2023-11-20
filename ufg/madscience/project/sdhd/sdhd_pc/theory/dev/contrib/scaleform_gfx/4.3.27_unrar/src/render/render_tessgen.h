// File Line: 53
// RVA: 0x93FB10
void __fastcall Scaleform::Render::MeshGenerator::MeshGenerator(Scaleform::Render::MeshGenerator *this, Scaleform::MemoryHeap *h)
{
  Scaleform::Render::MeshGenerator *v2; // rsi
  Scaleform::Render::LinearHeap *v3; // r8
  Scaleform::Render::LinearHeap *v4; // rdi
  Scaleform::Render::Stroker *v5; // [rsp+58h] [rbp+10h]

  v2 = this;
  this->Heap1.pHeap = h;
  this->Heap1.Granularity = 0x2000i64;
  this->Heap1.pPagePool = 0i64;
  this->Heap1.pLastPage = 0i64;
  this->Heap1.MaxPages = 0i64;
  v3 = &this->Heap2;
  v3->pHeap = h;
  v3->Granularity = 0x2000i64;
  v3->pPagePool = 0i64;
  v3->pLastPage = 0i64;
  v3->MaxPages = 0i64;
  v4 = &this->Heap3;
  v4->pHeap = h;
  v4->Granularity = 0x2000i64;
  v4->pPagePool = 0i64;
  v4->pLastPage = 0i64;
  v4->MaxPages = 0i64;
  this->Heap4.pHeap = h;
  this->Heap4.Granularity = 0x2000i64;
  this->Heap4.pPagePool = 0i64;
  this->Heap4.pLastPage = 0i64;
  this->Heap4.MaxPages = 0i64;
  Scaleform::Render::Tessellator::Tessellator(&this->mTess, &this->Heap1, &this->Heap2);
  v5 = &v2->mStroker;
  v5->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  v5->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::Stroker::`vftable;
  v2->mStroker.pHeap = v4;
  v2->mStroker.Path.Path.pHeap = v4;
  v2->mStroker.Path.Path.Size = 0i64;
  v2->mStroker.Path.Path.NumPages = 0i64;
  v2->mStroker.Path.Path.MaxPages = 0i64;
  v2->mStroker.Path.Path.Pages = 0i64;
  v2->mStroker.Width = 1.0;
  v2->mStroker.LineJoin = 2;
  v2->mStroker.StartLineCap = 2;
  v2->mStroker.EndLineCap = 2;
  v2->mStroker.MiterLimit = 3.0;
  v2->mStroker.CurveTolerance = 1.0;
  v2->mStroker.IntersectionEpsilon = 0.0099999998;
  v2->mStroker.Closed = 0;
  Scaleform::Render::StrokeSorter::StrokeSorter(&v2->mStrokeSorter, &v2->Heap4);
  Scaleform::Render::Hairliner::Hairliner(&v2->mHairliner, v4);
  Scaleform::Render::StrokerAA::StrokerAA(&v2->mStrokerAA, v4);
}

// File Line: 57
// RVA: 0x95F810
void __fastcall Scaleform::Render::MeshGenerator::Clear(Scaleform::Render::MeshGenerator *this)
{
  Scaleform::Render::MeshGenerator *v1; // rbx

  v1 = this;
  (*((void (**)(void))&this->mTess.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v1->mStroker.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v1->mStrokeSorter.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v1->mHairliner.vfptr->__vecDelDtor + 1))();
  (*((void (**)(void))&v1->mStrokerAA.vfptr->__vecDelDtor + 1))();
  Scaleform::Render::LinearHeap::ClearAndRelease(&v1->Heap1);
  Scaleform::Render::LinearHeap::ClearAndRelease(&v1->Heap2);
  Scaleform::Render::LinearHeap::ClearAndRelease(&v1->Heap3);
  Scaleform::Render::LinearHeap::ClearAndRelease(&v1->Heap4);
}

// File Line: 85
// RVA: 0x945000
void __fastcall Scaleform::Render::StrokeGenerator::StrokeGenerator(Scaleform::Render::StrokeGenerator *this, Scaleform::MemoryHeap *h)
{
  Scaleform::Render::StrokeGenerator *v2; // rbx
  Scaleform::Render::Stroker *v3; // rax
  Scaleform::Render::VertexPath *v4; // [rsp+48h] [rbp+10h]

  v2 = this;
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
  v3 = &this->mStroker;
  v3->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  v3->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::Stroker::`vftable;
  v3->pHeap = &this->Heap1;
  v3->Path.Path.pHeap = &this->Heap1;
  v3->Path.Path.Size = 0i64;
  v3->Path.Path.NumPages = 0i64;
  v3->Path.Path.MaxPages = 0i64;
  v3->Path.Path.Pages = 0i64;
  v3->Width = 1.0;
  v3->LineJoin = 2;
  v3->StartLineCap = 2;
  v3->EndLineCap = 2;
  v3->MiterLimit = 3.0;
  v3->CurveTolerance = 1.0;
  v3->IntersectionEpsilon = 0.0099999998;
  v3->Closed = 0;
  Scaleform::Render::StrokeSorter::StrokeSorter(&v2->mStrokeSorter, &v2->Heap2);
  v4 = &v2->mPath;
  v4->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  v4->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::VertexPath::`vftable;
  v2->mPath.Vertices.pHeap = &v2->Heap1;
  v2->mPath.Vertices.Size = 0i64;
  v2->mPath.Vertices.NumPages = 0i64;
  v2->mPath.Vertices.MaxPages = 0i64;
  v2->mPath.Vertices.Pages = 0i64;
  v2->mPath.Paths.pHeap = &v2->Heap1;
  v2->mPath.Paths.Size = 0i64;
  v2->mPath.Paths.NumPages = 0i64;
  v2->mPath.Paths.MaxPages = 0i64;
  v2->mPath.Paths.Pages = 0i64;
}

