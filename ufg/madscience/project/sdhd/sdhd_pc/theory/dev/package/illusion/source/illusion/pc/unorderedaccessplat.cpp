// File Line: 19
// RVA: 0xA18CF0
char __fastcall Illusion::IUnorderedAccessViewPlat::CreatePlat(
        Illusion::IUnorderedAccessViewPlat *this,
        Illusion::UnorderedAccessView *indep)
{
  UFG::allocator::free_link *v4; // rdi
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rdx

  v4 = UFG::qMalloc(8ui64, "UnorderedAccessViewPlat", 0i64);
  this->mPlat = (Illusion::UnorderedAccessViewPlat *)v4;
  if ( indep->mIsBufferResource )
    mNext = indep->mResource.mBuffer[1].mResourceHandles.UFG::qResourceData::mNode.mNext[5].mNext;
  else
    mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)indep->mResource.mBuffer[2].mNode.mChild[0][4].mChild[0];
  if ( ((int (__fastcall *)(ID3D11Device *, UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *, _QWORD, UFG::allocator::free_link *, __int64))UFG::gD3D11Device->vfptr->DrawIndexed)(
         UFG::gD3D11Device,
         mNext,
         0i64,
         v4,
         -2i64) >= 0 )
    return 1;
  if ( v4->mNext )
  {
    ((void (__fastcall *)(UFG::allocator::free_link *))v4->mNext->mNext[2].mNext)(v4->mNext);
    v4->mNext = 0i64;
  }
  return 0;
}

// File Line: 25
// RVA: 0xA22520
void __fastcall Illusion::IUnorderedAccessViewPlat::ShutdownPlat(Illusion::IUnorderedAccessViewPlat *this)
{
  Illusion::UnorderedAccessViewPlat *mPlat; // rdi

  mPlat = this->mPlat;
  if ( this->mPlat )
  {
    if ( mPlat->mD3DUAV )
    {
      mPlat->mD3DUAV->vfptr->Release(mPlat->mD3DUAV);
      mPlat->mD3DUAV = 0i64;
    }
    if ( this->mPlat )
      operator delete[](this->mPlat);
    this->mPlat = 0i64;
  }
}

