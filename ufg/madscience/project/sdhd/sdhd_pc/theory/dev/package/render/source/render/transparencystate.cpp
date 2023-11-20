// File Line: 23
// RVA: 0x1452890
__int64 dynamic_initializer_for__Render::TransparencySystem::msAlphaStateInHandle__()
{
  `eh vector constructor iterator(
    Render::TransparencySystem::msAlphaStateInHandle,
    0x20ui64,
    16,
    (void (__fastcall *)(void *))Illusion::AlphaStateHandle::AlphaStateHandle);
  return atexit(dynamic_atexit_destructor_for__Render::TransparencySystem::msAlphaStateInHandle__);
}

// File Line: 24
// RVA: 0x14528D0
__int64 dynamic_initializer_for__Render::TransparencySystem::msAlphaStateOutHandle__()
{
  `eh vector constructor iterator(
    Render::TransparencySystem::msAlphaStateOutHandle,
    0x20ui64,
    16,
    (void (__fastcall *)(void *))Illusion::AlphaStateHandle::AlphaStateHandle);
  return atexit(dynamic_atexit_destructor_for__Render::TransparencySystem::msAlphaStateOutHandle__);
}

// File Line: 48
// RVA: 0x6830
void __fastcall Render::TransparencySystem::Init(const unsigned int *alpha_state_in_uids, const unsigned int *alpha_state_out_uids, int num_states)
{
  __int64 v3; // rdi
  signed __int64 v4; // r14
  unsigned int *v5; // rbx
  __int64 v6; // rbp
  UFG::qResourceInventory *v7; // rax
  unsigned int v8; // esi
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rax
  unsigned int v11; // esi
  UFG::qResourceWarehouse *v12; // rax

  Render::TransparencySystem::msNumTransparencyStateHandles = num_states + 2;
  Render::TransparencySystem::msOpaqueIndex = num_states + 1;
  if ( num_states > 1 )
  {
    v3 = 0i64;
    v4 = (char *)alpha_state_in_uids - (char *)alpha_state_out_uids;
    v5 = (unsigned int *)(alpha_state_out_uids + 1);
    v6 = (unsigned int)(num_states - 1);
    do
    {
      v7 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
      v8 = *(unsigned int *)((char *)v5 + v4);
      if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
      {
        v9 = UFG::qResourceWarehouse::Instance();
        v7 = UFG::qResourceWarehouse::GetInventory(v9, 0x12C800F2u);
        `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v7;
      }
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::TransparencySystem::msAlphaStateInHandle[v3 + 1].mPrev,
        0x12C800F2u,
        v8,
        v7);
      v10 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
      v11 = *v5;
      if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
      {
        v12 = UFG::qResourceWarehouse::Instance();
        v10 = UFG::qResourceWarehouse::GetInventory(v12, 0x12C800F2u);
        `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v10;
      }
      UFG::qResourceHandle::Init(
        (UFG::qResourceHandle *)&Render::TransparencySystem::msAlphaStateOutHandle[v3 + 1].mPrev,
        0x12C800F2u,
        v11,
        v10);
      ++v3;
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  Render::TransparencySystem::InitDitherMaskTextures();
}

// File Line: 68
// RVA: 0x6950
void Render::TransparencySystem::InitDitherMaskTextures(void)
{
  Illusion::Texture *v0; // rax
  unsigned int v1; // eax
  signed int v2; // ebx
  Illusion::Texture **v3; // rdi
  Illusion::Texture *v4; // rax
  unsigned int v5; // eax
  char v6; // cl
  char *v7; // rcx
  char v8; // al
  char *v9; // rcx
  char v10; // al
  char *v11; // rcx
  char v12; // al
  char *v13; // rcx
  char v14; // al
  char *v15; // rcx
  char v16; // al
  char *v17; // rcx
  char v18; // al
  signed int v19; // ebx
  Illusion::Texture **v20; // rdi
  Illusion::Texture *v21; // rax
  unsigned int v22; // eax
  char *v23; // rcx
  char v24; // al
  char *v25; // rcx
  char v26; // al
  char *v27; // rcx
  char v28; // al
  __int64 v29; // rcx
  char *v30; // rdx
  char v31; // al
  char *v32; // rcx
  char v33; // al
  char *v34; // rcx
  char v35; // al
  char *v36; // rcx
  char v37; // al
  Illusion::Texture *v38; // rax
  unsigned int v39; // eax
  Illusion::TextureLockInfo info; // [rsp+48h] [rbp-38h]
  UFG::qString result; // [rsp+58h] [rbp-28h]

  info.mData = 0i64;
  *(_QWORD *)&info.mLinePitch = 0i64;
  v0 = (Illusion::Texture *)Illusion::CreateTexture("DitherTex_00", 4, 2, FORMAT_X8, 0x440400u, 1, 0, 0);
  Render::TransparencySystem::msDitherMaskTextures[0] = v0;
  v1 = Illusion::Texture::GetSamplerAddressFlags(v0);
  Illusion::Texture::SetSamplerState(Render::TransparencySystem::msDitherMaskTextures[0], 2u, v1 & 0xFFFFFFFC);
  if ( Illusion::ITexturePlat::Lock(
         (Illusion::ITexturePlat *)Render::TransparencySystem::msDitherMaskTextures[0],
         LOCK_MODIFY,
         &info,
         0,
         0) )
  {
    *info.mData = 0;
    ++info.mData;
    *info.mData = 0;
    ++info.mData;
    *info.mData = 0;
    ++info.mData;
    *info.mData = 0;
    info.mData += info.mLinePitch - 3;
    *info.mData = 0;
    ++info.mData;
    *info.mData = 0;
    ++info.mData;
    *info.mData = 0;
    ++info.mData;
    *info.mData = 0;
    ++info.mData;
    Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)Render::TransparencySystem::msDitherMaskTextures[0]);
  }
  v2 = 1;
  v3 = (Illusion::Texture **)&unk_142128E78;
  do
  {
    UFG::qString::FormatEx(&result, "DitherTexIn_%d", (unsigned int)v2);
    v4 = (Illusion::Texture *)Illusion::CreateTexture(result.mData, 4, 2, FORMAT_X8, 0x440400u, 1, 0, 0);
    *v3 = v4;
    v5 = Illusion::Texture::GetSamplerAddressFlags(v4);
    Illusion::Texture::SetSamplerState(*v3, 2u, v5 & 0xFFFFFFFC);
    if ( Illusion::ITexturePlat::Lock((Illusion::ITexturePlat *)*v3, LOCK_MODIFY, &info, 0, 0) )
    {
      v6 = 0;
      if ( v2 > 0 )
        v6 = -1;
      *info.mData = v6;
      v7 = info.mData++ + 1;
      v8 = 0;
      if ( v2 > 4 )
        v8 = -1;
      *v7 = v8;
      v9 = info.mData++ + 1;
      v10 = 0;
      if ( v2 > 2 )
        v10 = -1;
      *v9 = v10;
      v11 = info.mData++ + 1;
      v12 = 0;
      if ( v2 > 6 )
        v12 = -1;
      *v11 = v12;
      info.mData += info.mLinePitch - 3;
      *info.mData = 0;
      v13 = info.mData++ + 1;
      v14 = 0;
      if ( v2 > 1 )
        v14 = -1;
      *v13 = v14;
      v15 = info.mData++ + 1;
      v16 = 0;
      if ( v2 > 5 )
        v16 = -1;
      *v15 = v16;
      v17 = info.mData++ + 1;
      v18 = 0;
      if ( v2 > 3 )
        v18 = -1;
      *v17 = v18;
      ++info.mData;
      Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)*v3);
    }
    UFG::qString::~qString(&result);
    ++v2;
    ++v3;
  }
  while ( v2 <= 7 );
  v19 = 1;
  v20 = (Illusion::Texture **)&unk_142128EB0;
  do
  {
    UFG::qString::FormatEx(&result, "DitherTexOut_%d", (unsigned int)(v19 + 7));
    v21 = (Illusion::Texture *)Illusion::CreateTexture(result.mData, 4, 2, FORMAT_X8, 0x440400u, 1, 0, 0);
    *v20 = v21;
    v22 = Illusion::Texture::GetSamplerAddressFlags(v21);
    Illusion::Texture::SetSamplerState(*v20, 2u, v22 & 0xFFFFFFFC);
    if ( Illusion::ITexturePlat::Lock((Illusion::ITexturePlat *)*v20, LOCK_MODIFY, &info, 0, 0) )
    {
      *info.mData = 0;
      v23 = info.mData++ + 1;
      v24 = 0;
      if ( v19 > 3 )
        v24 = -1;
      *v23 = v24;
      v25 = info.mData++ + 1;
      v26 = 0;
      if ( v19 > 5 )
        v26 = -1;
      *v25 = v26;
      v27 = info.mData++ + 1;
      v28 = 0;
      if ( v19 > 1 )
        v28 = -1;
      *v27 = v28;
      v29 = info.mLinePitch - 4;
      v30 = &info.mData[v29 + 1];
      info.mData += v29 + 1;
      v31 = 0;
      if ( v19 > 0 )
        v31 = -1;
      *v30 = v31;
      v32 = info.mData++ + 1;
      v33 = 0;
      if ( v19 > 6 )
        v33 = -1;
      *v32 = v33;
      v34 = info.mData++ + 1;
      v35 = 0;
      if ( v19 > 2 )
        v35 = -1;
      *v34 = v35;
      v36 = info.mData++ + 1;
      v37 = 0;
      if ( v19 > 4 )
        v37 = -1;
      *v36 = v37;
      ++info.mData;
      Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)*v20);
    }
    UFG::qString::~qString(&result);
    ++v19;
    ++v20;
  }
  while ( v19 + 7 <= 14 );
  v38 = (Illusion::Texture *)Illusion::CreateTexture("DitherTex_111", 4, 2, FORMAT_X8, 0x440400u, 1, 0, 0);
  qword_142128EE8 = v38;
  v39 = Illusion::Texture::GetSamplerAddressFlags(v38);
  Illusion::Texture::SetSamplerState(qword_142128EE8, 2u, v39 & 0xFFFFFFFC);
  if ( Illusion::ITexturePlat::Lock((Illusion::ITexturePlat *)qword_142128EE8, LOCK_MODIFY, &info, 0, 0) )
  {
    *info.mData = -1;
    ++info.mData;
    *info.mData = -1;
    ++info.mData;
    *info.mData = -1;
    ++info.mData;
    *info.mData = -1;
    info.mData += info.mLinePitch - 3;
    *info.mData = -1;
    ++info.mData;
    *info.mData = -1;
    ++info.mData;
    *info.mData = -1;
    ++info.mData;
    *info.mData = -1;
    ++info.mData;
    Illusion::ITexturePlat::Unlock((Illusion::ITexturePlat *)qword_142128EE8);
  }
}

