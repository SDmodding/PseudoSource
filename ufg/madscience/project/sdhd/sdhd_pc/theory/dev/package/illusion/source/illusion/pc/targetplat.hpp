// File Line: 49
// RVA: 0xA15BA0
void __fastcall Illusion::TargetPlat::TargetPlat(Illusion::TargetPlat *this)
{
  Illusion::TargetPlat *v1; // rdx
  ID3D11RenderTargetView *(*v2)[4]; // r8
  signed __int64 v3; // r9
  ID3D11RenderTargetView *(*v4)[4]; // rax
  signed __int64 v5; // rcx

  v1 = this;
  *(_WORD *)&this->mHasDepthSurface = 0;
  this->mResolveDepthSurface = 0;
  this->mInvertedDepth = 0;
  v2 = this->mRenderTargetView;
  v3 = 4i64;
  this->mNumMips = 0;
  this->mDepthStencilView = 0i64;
  do
  {
    v4 = v2;
    v5 = 32i64;
    do
    {
      (*v4)[0] = 0i64;
      ++v4;
      --v5;
    }
    while ( v5 );
    v2 = (ID3D11RenderTargetView *(*)[4])((char *)v2 + 8);
    --v3;
  }
  while ( v3 );
  v1->mMSAATargetTexture[0] = 0i64;
  v1->mMSAATargetTexture[1] = 0i64;
  v1->mMSAATargetTexture[2] = 0i64;
  v1->mMSAATargetTexture[3] = 0i64;
  v1->mMSAADepthTexture = 0i64;
}

// File Line: 72
// RVA: 0xA16950
void __fastcall Illusion::TargetPlat::~TargetPlat(Illusion::TargetPlat *this)
{
  Illusion::TargetPlat *v1; // r15
  ID3D11DepthStencilView *v2; // rcx
  signed __int64 v3; // rbp
  signed __int64 v4; // rsi
  signed __int64 v5; // r14
  signed __int64 v6; // rbx
  signed __int64 v7; // rdi
  Illusion::Texture **v8; // rbx
  Illusion::Texture *v9; // rcx

  v1 = this;
  v2 = this->mDepthStencilView;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->mDepthStencilView = 0i64;
  }
  v3 = 4i64;
  v4 = (signed __int64)v1->mRenderTargetView;
  v5 = 4i64;
  do
  {
    v6 = v4;
    v7 = 32i64;
    do
    {
      if ( *(_QWORD *)v6 )
      {
        (*(void (**)(void))(**(_QWORD **)v6 + 16i64))();
        *(_QWORD *)v6 = 0i64;
      }
      v6 += 32i64;
      --v7;
    }
    while ( v7 );
    v4 += 8i64;
    --v5;
  }
  while ( v5 );
  v8 = v1->mMSAATargetTexture;
  do
  {
    if ( *v8 )
    {
      Illusion::DeleteTexture(*v8, 1);
      *v8 = 0i64;
    }
    ++v8;
    --v3;
  }
  while ( v3 );
  v9 = v1->mMSAADepthTexture;
  if ( v9 )
  {
    Illusion::DeleteTexture(v9, 1);
    v1->mMSAADepthTexture = 0i64;
  }
}

