// File Line: 49
// RVA: 0xA15BA0
void __fastcall Illusion::TargetPlat::TargetPlat(Illusion::TargetPlat *this)
{
  ID3D11RenderTargetView *(*mRenderTargetView)[4]; // r8
  __int64 v3; // r9
  ID3D11RenderTargetView *(*v4)[4]; // rax
  __int64 v5; // rcx

  *(_WORD *)&this->mHasDepthSurface = 0;
  this->mResolveDepthSurface = 0;
  this->mInvertedDepth = 0;
  mRenderTargetView = this->mRenderTargetView;
  v3 = 4i64;
  this->mNumMips = 0;
  this->mDepthStencilView = 0i64;
  do
  {
    v4 = mRenderTargetView;
    v5 = 32i64;
    do
    {
      (*v4++)[0] = 0i64;
      --v5;
    }
    while ( v5 );
    mRenderTargetView = (ID3D11RenderTargetView *(*)[4])((char *)mRenderTargetView + 8);
    --v3;
  }
  while ( v3 );
  this->mMSAATargetTexture[0] = 0i64;
  this->mMSAATargetTexture[1] = 0i64;
  this->mMSAATargetTexture[2] = 0i64;
  this->mMSAATargetTexture[3] = 0i64;
  this->mMSAADepthTexture = 0i64;
}

// File Line: 72
// RVA: 0xA16950
void __fastcall Illusion::TargetPlat::~TargetPlat(Illusion::TargetPlat *this)
{
  ID3D11DepthStencilView *mDepthStencilView; // rcx
  __int64 v3; // rbp
  ID3D11RenderTargetView *(*mRenderTargetView)[4]; // rsi
  __int64 v5; // r14
  ID3D11RenderTargetView *(*v6)[4]; // rbx
  __int64 v7; // rdi
  Illusion::Texture **mMSAATargetTexture; // rbx
  Illusion::Texture *mMSAADepthTexture; // rcx

  mDepthStencilView = this->mDepthStencilView;
  if ( mDepthStencilView )
  {
    mDepthStencilView->vfptr->Release(mDepthStencilView);
    this->mDepthStencilView = 0i64;
  }
  v3 = 4i64;
  mRenderTargetView = this->mRenderTargetView;
  v5 = 4i64;
  do
  {
    v6 = mRenderTargetView;
    v7 = 32i64;
    do
    {
      if ( (*v6)[0] )
      {
        (*v6)[0]->vfptr->Release((*v6)[0]);
        (*v6)[0] = 0i64;
      }
      ++v6;
      --v7;
    }
    while ( v7 );
    mRenderTargetView = (ID3D11RenderTargetView *(*)[4])((char *)mRenderTargetView + 8);
    --v5;
  }
  while ( v5 );
  mMSAATargetTexture = this->mMSAATargetTexture;
  do
  {
    if ( *mMSAATargetTexture )
    {
      Illusion::DeleteTexture((AMD_HD3D *)*mMSAATargetTexture, 1);
      *mMSAATargetTexture = 0i64;
    }
    ++mMSAATargetTexture;
    --v3;
  }
  while ( v3 );
  mMSAADepthTexture = this->mMSAADepthTexture;
  if ( mMSAADepthTexture )
  {
    Illusion::DeleteTexture((AMD_HD3D *)mMSAADepthTexture, 1);
    this->mMSAADepthTexture = 0i64;
  }
}

