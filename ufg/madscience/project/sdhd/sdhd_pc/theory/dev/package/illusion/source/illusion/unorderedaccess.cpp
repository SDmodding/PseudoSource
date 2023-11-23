// File Line: 36
// RVA: 0x8EA10
Illusion::UnorderedAccessView *__fastcall Illusion::UnorderedAccessView::Create(Illusion::Buffer *resource)
{
  char *v2; // rax
  Illusion::UnorderedAccessView *v3; // rbx

  v2 = UFG::qMalloc(0x18ui64, "UnorderedAccessView", 0i64);
  v3 = (Illusion::UnorderedAccessView *)v2;
  if ( v2 )
    *(_QWORD *)v2 = 0i64;
  else
    v3 = 0i64;
  v3->mResource.mBuffer = resource;
  v3->mIsBufferResource = 0;
  Illusion::IUnorderedAccessViewPlat::CreatePlat(v3, v3);
  return v3;
}

// File Line: 50
// RVA: 0x8EDA0
void __fastcall Illusion::UnorderedAccessView::Delete(Illusion::UnorderedAccessView *this)
{
  Illusion::IUnorderedAccessViewPlat::ShutdownPlat(this);
  if ( this )
    operator delete[](this);
}

