// File Line: 33
// RVA: 0x8EA80
Illusion::Target *__fastcall Illusion::CreateTarget(Illusion::CreateTargetParams *params)
{
  char *v2; // rax
  unsigned int v3; // edi
  __int64 v4; // rax
  __int64 v5; // rsi
  Illusion::Texture *v6; // rax
  Illusion::Texture *depth_texture; // rax

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
  *(_DWORD *)v5 = params->width;
  *(_DWORD *)(v5 + 4) = params->height;
  *(_DWORD *)(v5 + 16) = params->num_mrt;
  UFG::qStringCopy((char *)(v5 + 81), 32, params->name.mData, -1);
  v6 = params->textures[0];
  if ( v6 )
  {
    if ( !params->width || !params->height )
    {
      *(_DWORD *)v5 = v6->mWidth;
      *(_DWORD *)(v5 + 4) = params->textures[0]->mHeight;
    }
    if ( params->num_mrt )
    {
      do
      {
        *(_QWORD *)(v5 + 8i64 * v3 + 24) = params->textures[v3];
        ++v3;
      }
      while ( v3 < params->num_mrt );
    }
  }
  depth_texture = params->depth_texture;
  if ( depth_texture )
  {
    if ( !params->width || !params->height )
    {
      *(_DWORD *)v5 = depth_texture->mWidth;
      *(_DWORD *)(v5 + 4) = params->depth_texture->mHeight;
    }
    *(_QWORD *)(v5 + 64) = params->depth_texture;
  }
  Illusion::ITargetPlat::Create((Illusion::ITargetPlat *)v5, params);
  return (Illusion::Target *)v5;
}

// File Line: 83
// RVA: 0x8F080
void __fastcall Illusion::DeleteTarget(AMD_HD3D *target, bool wait)
{
  unsigned int i; // edi
  __int64 v5; // rsi
  Illusion::Texture *v6; // rbp
  UFG::qResourceWarehouse *v7; // rax
  Illusion::Texture *v8; // rdi
  UFG::qResourceWarehouse *v9; // rax
  Illusion::Texture *v10; // rdi
  UFG::qResourceWarehouse *v11; // rax

  for ( i = 0; i < LODWORD(target->mStereo); (&target->mExtension)[v5] = 0i64 )
  {
    v5 = i;
    if ( *((_BYTE *)&target[1].mExtension + i) )
    {
      v6 = (Illusion::Texture *)(&target->mExtension)[i];
      if ( v6 )
      {
        _((AMD_HD3D *)(&target->mExtension)[i]);
        v7 = UFG::qResourceWarehouse::Instance();
        UFG::qResourceWarehouse::Remove(v7, &v6->UFG::qResourceData);
        Illusion::Factory::Delete(v6, wait);
      }
    }
    ++i;
  }
  if ( LOBYTE(target[2].mStereo) )
  {
    v8 = *(Illusion::Texture **)&target[2].mEnableStereo;
    if ( v8 )
    {
      v9 = UFG::qResourceWarehouse::Instance();
      UFG::qResourceWarehouse::Remove(v9, &v8->UFG::qResourceData);
      Illusion::Factory::Delete(*(Illusion::Texture **)&target[2].mEnableStereo, wait);
    }
  }
  v10 = *(Illusion::Texture **)&target[2].mWidth;
  *(_QWORD *)&target[2].mEnableStereo = 0i64;
  if ( v10 )
  {
    _((AMD_HD3D *)v10);
    v11 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Remove(v11, &v10->UFG::qResourceData);
    Illusion::Factory::Delete(v10, wait);
  }
  *(_QWORD *)&target[2].mWidth = 0i64;
  _(target);
  Illusion::Target::~Target((Illusion::Target *)target);
  operator delete[](target);
}

// File Line: 111
// RVA: 0x95750
void __fastcall Illusion::SetFullscreenViewportScissor(
        Illusion::Target *target,
        Illusion::ViewportScissorState *viewport_scissor,
        char dest_mip_level)
{
  int mHeight; // eax
  Illusion::Texture *mDepthTexture; // rax
  char v5; // al
  float v6; // xmm0_4

  *(_QWORD *)&viewport_scissor->mViewPortX = 0i64;
  viewport_scissor->mViewPortWidth = (float)(target->mWidth >> dest_mip_level);
  mHeight = target->mHeight;
  *(_QWORD *)&viewport_scissor->mScissorX = 0i64;
  viewport_scissor->mViewPortHeight = (float)(mHeight >> dest_mip_level);
  viewport_scissor->mScissorWidth = target->mWidth >> dest_mip_level;
  viewport_scissor->mScissorHeight = target->mHeight >> dest_mip_level;
  mDepthTexture = target->mDepthTexture;
  if ( mDepthTexture && mDepthTexture->mFormat == 17 )
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

