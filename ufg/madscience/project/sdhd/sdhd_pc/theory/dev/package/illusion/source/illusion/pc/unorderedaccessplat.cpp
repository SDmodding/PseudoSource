// File Line: 19
// RVA: 0xA18CF0
char __fastcall Illusion::IUnorderedAccessViewPlat::CreatePlat(Illusion::IUnorderedAccessViewPlat *this, Illusion::UnorderedAccessView *indep)
{
  Illusion::UnorderedAccessView *v2; // rsi
  Illusion::IUnorderedAccessViewPlat *v3; // rbx
  UFG::allocator::free_link *v4; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v5; // rdx

  v2 = indep;
  v3 = this;
  v4 = UFG::qMalloc(8ui64, "UnorderedAccessViewPlat", 0i64);
  v3->mPlat = (Illusion::UnorderedAccessViewPlat *)v4;
  if ( v2->mIsBufferResource )
    v5 = v2->mResource.mBuffer[1].mResourceHandles.mNode.mNext[5].mNext;
  else
    v5 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v2->mResource.mBuffer[2].mNode.mChild[0][4].mChild[0];
  if ( ((signed int (__fastcall *)(ID3D11Device *, UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *, _QWORD, UFG::allocator::free_link *, signed __int64))UFG::gD3D11Device->vfptr->DrawIndexed)(
         UFG::gD3D11Device,
         v5,
         0i64,
         v4,
         -2i64) >= 0 )
    return 1;
  if ( v4->mNext )
  {
    ((void (*)(void))v4->mNext->mNext[2].mNext)();
    v4->mNext = 0i64;
  }
  return 0;
}

// File Line: 25
// RVA: 0xA22520
void __fastcall Illusion::IUnorderedAccessViewPlat::ShutdownPlat(Illusion::IUnorderedAccessViewPlat *this)
{
  Illusion::UnorderedAccessViewPlat *v1; // rdi
  Illusion::IUnorderedAccessViewPlat *v2; // rbx

  v1 = this->mPlat;
  v2 = this;
  if ( this->mPlat )
  {
    if ( v1->mD3DUAV )
    {
      ((void (*)(void))v1->mD3DUAV->vfptr->Release)();
      v1->mD3DUAV = 0i64;
    }
    if ( v2->mPlat )
      operator delete[](v2->mPlat);
    v2->mPlat = 0i64;
  }
}

