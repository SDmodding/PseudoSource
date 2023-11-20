// File Line: 36
// RVA: 0x8EA10
Illusion::UnorderedAccessView *__fastcall Illusion::UnorderedAccessView::Create(Illusion::Texture *resource)
{
  Illusion::Texture *v1; // rdi
  char *v2; // rax
  Illusion::UnorderedAccessView *v3; // rbx

  v1 = resource;
  v2 = UFG::qMalloc(0x18ui64, "UnorderedAccessView", 0i64);
  v3 = (Illusion::UnorderedAccessView *)v2;
  if ( v2 )
    *(_QWORD *)v2 = 0i64;
  else
    v3 = 0i64;
  v3->mResource.mBuffer = (Illusion::Buffer *)v1;
  v3->mIsBufferResource = 0;
  Illusion::IUnorderedAccessViewPlat::CreatePlat((Illusion::IUnorderedAccessViewPlat *)&v3->mPlat, v3);
  return v3;
}

// File Line: 50
// RVA: 0x8EDA0
void __fastcall Illusion::UnorderedAccessView::Delete(Illusion::UnorderedAccessView *this)
{
  Illusion::UnorderedAccessView *v1; // rbx

  v1 = this;
  Illusion::IUnorderedAccessViewPlat::ShutdownPlat((Illusion::IUnorderedAccessViewPlat *)&this->mPlat);
  if ( v1 )
    operator delete[](v1);
}

