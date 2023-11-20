// File Line: 33
// RVA: 0x8EA80
Illusion::Target *__fastcall Illusion::CreateTarget(Illusion::CreateTargetParams *params)
{
  Illusion::CreateTargetParams *v1; // rbx
  char *v2; // rax
  unsigned int v3; // edi
  __int64 v4; // rax
  __int64 v5; // rsi
  Illusion::Texture *v6; // rax
  Illusion::Texture *v7; // rax

  v1 = params;
  v2 = UFG::qMalloc(0x78ui64, params->name.mData, 0i64);
  v3 = 0;
  if ( v2 )
  {
    Illusion::Target::Target((Illusion::Target *)v2);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  *(_DWORD *)v5 = v1->width;
  *(_DWORD *)(v5 + 4) = v1->height;
  *(_DWORD *)(v5 + 16) = v1->num_mrt;
  UFG::qStringCopy((char *)(v5 + 81), 32, v1->name.mData, -1);
  v6 = v1->textures[0];
  if ( v6 )
  {
    if ( !v1->width || !v1->height )
    {
      *(_DWORD *)v5 = v6->mWidth;
      *(_DWORD *)(v5 + 4) = v1->textures[0]->mHeight;
    }
    if ( v1->num_mrt )
    {
      do
      {
        *(_QWORD *)(v5 + 8i64 * v3 + 24) = v1->textures[v3];
        ++v3;
      }
      while ( v3 < v1->num_mrt );
    }
  }
  v7 = v1->depth_texture;
  if ( v7 )
  {
    if ( !v1->width || !v1->height )
    {
      *(_DWORD *)v5 = v7->mWidth;
      *(_DWORD *)(v5 + 4) = v1->depth_texture->mHeight;
    }
    *(_QWORD *)(v5 + 64) = v1->depth_texture;
  }
  Illusion::ITargetPlat::Create((Illusion::ITargetPlat *)v5, v1);
  return (Illusion::Target *)v5;
}

// File Line: 83
// RVA: 0x8F080
void __fastcall Illusion::DeleteTarget(Illusion::Target *target, bool wait)
{
  bool v2; // r14
  Illusion::Target *v3; // rbx
  unsigned int v4; // edi
  __int64 v5; // rsi
  Illusion::Texture *v6; // rbp
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceData *v8; // rdi
  UFG::qResourceWarehouse *v9; // rax
  AMD_HD3D *v10; // rdi
  UFG::qResourceWarehouse *v11; // rax

  v2 = wait;
  v3 = target;
  v4 = 0;
  if ( target->mNumTargetTextures )
  {
    do
    {
      v5 = v4;
      if ( v3->mOwnsTargetTexture[v4] )
      {
        v6 = v3->mTargetTexture[v4];
        if ( v6 )
        {
          _((AMD_HD3D *)v3->mTargetTexture[v4]);
          v7 = UFG::qResourceWarehouse::Instance();
          UFG::qResourceWarehouse::Remove(v7, (UFG::qResourceData *)&v6->mNode);
          Illusion::Factory::Delete(v6, v2);
        }
      }
      ++v4;
      v3->mTargetTexture[v5] = 0i64;
    }
    while ( v4 < v3->mNumTargetTextures );
  }
  if ( v3->mOwnsDepthTexture )
  {
    v8 = (UFG::qResourceData *)&v3->mDepthTexture->mNode;
    if ( v8 )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Remove(v9, v8);
      Illusion::Factory::Delete(v3->mDepthTexture, v2);
    }
  }
  v10 = (AMD_HD3D *)v3->mDepthTextureCopy;
  v3->mDepthTexture = 0i64;
  if ( v10 )
  {
    _(v10);
    v11 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v11, (UFG::qResourceData *)v10);
    Illusion::Factory::Delete((Illusion::Texture *)v10, v2);
  }
  v3->mDepthTextureCopy = 0i64;
  _((AMD_HD3D *)v3);
  Illusion::Target::~Target(v3);
  operator delete[](v3);
}

// File Line: 111
// RVA: 0x95750
void __fastcall Illusion::SetFullscreenViewportScissor(Illusion::Target *target, Illusion::ViewportScissorState *viewport_scissor, unsigned int dest_mip_level)
{
  int v3; // eax
  Illusion::Texture *v4; // rax
  char v5; // al
  float v6; // xmm0_4

  *(_QWORD *)&viewport_scissor->mViewPortX = 0i64;
  viewport_scissor->mViewPortWidth = (float)(target->mWidth >> dest_mip_level);
  v3 = target->mHeight;
  *(_QWORD *)&viewport_scissor->mScissorX = 0i64;
  viewport_scissor->mViewPortHeight = (float)(v3 >> dest_mip_level);
  viewport_scissor->mScissorWidth = target->mWidth >> dest_mip_level;
  viewport_scissor->mScissorHeight = target->mHeight >> dest_mip_level;
  v4 = target->mDepthTexture;
  if ( v4 && v4->mFormat == 17 )
  {
    v5 = 1;
    v6 = *(float *)&FLOAT_1_0;
  }
  else
  {
    v5 = 0;
    v6 = 0.0;
  }
  viewport_scissor->mViewPortMinDepth = v6;
  if ( v5 )
    viewport_scissor->mViewPortMaxDepth = 0.0;
  else
    LODWORD(viewport_scissor->mViewPortMaxDepth) = (_DWORD)FLOAT_1_0;
}

