// File Line: 23
// RVA: 0x1452890
__int64 dynamic_initializer_for__Render::TransparencySystem::msAlphaStateInHandle__()
{
  `eh vector constructor iterator(
    (char *)Render::TransparencySystem::msAlphaStateInHandle,
    0x20ui64,
    16,
    (void (__fastcall *)(void *))Illusion::AlphaStateHandle::AlphaStateHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::TransparencySystem::msAlphaStateInHandle__);
}

// File Line: 24
// RVA: 0x14528D0
__int64 dynamic_initializer_for__Render::TransparencySystem::msAlphaStateOutHandle__()
{
  `eh vector constructor iterator(
    (char *)Render::TransparencySystem::msAlphaStateOutHandle,
    0x20ui64,
    16,
    (void (__fastcall *)(void *))Illusion::AlphaStateHandle::AlphaStateHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::TransparencySystem::msAlphaStateOutHandle__);
}

// File Line: 48
// RVA: 0x6830
void __fastcall Render::TransparencySystem::Init(char *alpha_state_in_uids, char *alpha_state_out_uids, int num_states)
{
  __int64 v3; // rdi
  signed __int64 v4; // r14
  unsigned int *v5; // rbx
  __int64 v6; // rbp
  UFG::qResourceInventory *Inventory; // rax
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
    v4 = alpha_state_in_uids - alpha_state_out_uids;
    v5 = (unsigned int *)(alpha_state_out_uids + 4);
    v6 = (unsigned int)(num_states - 1);
    do
    {
      Inventory = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
      v8 = *(unsigned int *)((char *)v5 + v4);
      if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
      {
        v9 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v9, 0x12C800F2u);
        `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(&Render::TransparencySystem::msAlphaStateInHandle[v3 + 1], 0x12C800F2u, v8, Inventory);
      v10 = `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result;
      v11 = *v5;
      if ( !`UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result )
      {
        v12 = UFG::qResourceWarehouse::Instance();
        v10 = UFG::qResourceWarehouse::GetInventory(v12, 0x12C800F2u);
        `UFG::qGetResourceInventory<Illusion::AlphaState>::`2::result = v10;
      }
      UFG::qResourceHandle::Init(&Render::TransparencySystem::msAlphaStateOutHandle[++v3], 0x12C800F2u, v11, v10);
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
  unsigned int SamplerAddressFlags; // eax
  int v1; // ebx
  Illusion::Texture **v2; // rdi
  Illusion::Texture *Texture; // rax
  unsigned int v4; // eax
  char v5; // cl
  char *v6; // rcx
  char v7; // al
  char *v8; // rcx
  char v9; // al
  char *v10; // rcx
  char v11; // al
  char *v12; // rcx
  char v13; // al
  char *v14; // rcx
  char v15; // al
  char *v16; // rcx
  char v17; // al
  int v18; // ebx
  Illusion::Texture **v19; // rdi
  Illusion::Texture *v20; // rax
  unsigned int v21; // eax
  char *v22; // rcx
  char v23; // al
  char *v24; // rcx
  char v25; // al
  char *v26; // rcx
  char v27; // al
  char *v28; // rdx
  char v29; // al
  char *v30; // rcx
  char v31; // al
  char *v32; // rcx
  char v33; // al
  char *v34; // rcx
  char v35; // al
  unsigned int v36; // eax
  Illusion::TextureLockInfo info; // [rsp+48h] [rbp-38h] BYREF
  UFG::qString result; // [rsp+58h] [rbp-28h] BYREF

  info.mData = 0i64;
  *(_QWORD *)&info.mLinePitch = 0i64;
  Render::TransparencySystem::msDitherMaskTextures[0] = (Illusion::Texture *)Illusion::CreateTexture(
                                                                               "DitherTex_00",
                                                                               4,
                                                                               2,
                                                                               FORMAT_X8,
                                                                               0x440400u,
                                                                               1,
                                                                               0,
                                                                               0);
  SamplerAddressFlags = Illusion::Texture::GetSamplerAddressFlags(Render::TransparencySystem::msDitherMaskTextures[0]);
  Illusion::Texture::SetSamplerState(
    Render::TransparencySystem::msDitherMaskTextures[0],
    2u,
    SamplerAddressFlags & 0xFFFFFFFC);
  if ( Illusion::ITexturePlat::Lock(Render::TransparencySystem::msDitherMaskTextures[0], LOCK_MODIFY, &info, 0, 0) )
  {
    *info.mData++ = 0;
    *info.mData++ = 0;
    *info.mData++ = 0;
    *info.mData = 0;
    info.mData += info.mLinePitch - 3;
    *info.mData++ = 0;
    *info.mData++ = 0;
    *info.mData++ = 0;
    *info.mData++ = 0;
    Illusion::ITexturePlat::Unlock(Render::TransparencySystem::msDitherMaskTextures[0]);
  }
  v1 = 1;
  v2 = (Illusion::Texture **)&unk_142128E78;
  do
  {
    UFG::qString::FormatEx(&result, "DitherTexIn_%d", (unsigned int)v1);
    Texture = (Illusion::Texture *)Illusion::CreateTexture(result.mData, 4, 2, FORMAT_X8, 0x440400u, 1, 0, 0);
    *v2 = Texture;
    v4 = Illusion::Texture::GetSamplerAddressFlags(Texture);
    Illusion::Texture::SetSamplerState(*v2, 2u, v4 & 0xFFFFFFFC);
    if ( Illusion::ITexturePlat::Lock(*v2, LOCK_MODIFY, &info, 0, 0) )
    {
      v5 = 0;
      if ( v1 > 0 )
        v5 = -1;
      *info.mData = v5;
      v6 = ++info.mData;
      v7 = 0;
      if ( v1 > 4 )
        v7 = -1;
      *v6 = v7;
      v8 = ++info.mData;
      v9 = 0;
      if ( v1 > 2 )
        v9 = -1;
      *v8 = v9;
      v10 = ++info.mData;
      v11 = 0;
      if ( v1 > 6 )
        v11 = -1;
      *v10 = v11;
      info.mData += info.mLinePitch - 3;
      *info.mData = 0;
      v12 = ++info.mData;
      v13 = 0;
      if ( v1 > 1 )
        v13 = -1;
      *v12 = v13;
      v14 = ++info.mData;
      v15 = 0;
      if ( v1 > 5 )
        v15 = -1;
      *v14 = v15;
      v16 = ++info.mData;
      v17 = 0;
      if ( v1 > 3 )
        v17 = -1;
      *v16 = v17;
      ++info.mData;
      Illusion::ITexturePlat::Unlock(*v2);
    }
    UFG::qString::~qString(&result);
    ++v1;
    ++v2;
  }
  while ( v1 <= 7 );
  v18 = 1;
  v19 = (Illusion::Texture **)&unk_142128EB0;
  do
  {
    UFG::qString::FormatEx(&result, "DitherTexOut_%d", (unsigned int)(v18 + 7));
    v20 = (Illusion::Texture *)Illusion::CreateTexture(result.mData, 4, 2, FORMAT_X8, 0x440400u, 1, 0, 0);
    *v19 = v20;
    v21 = Illusion::Texture::GetSamplerAddressFlags(v20);
    Illusion::Texture::SetSamplerState(*v19, 2u, v21 & 0xFFFFFFFC);
    if ( Illusion::ITexturePlat::Lock(*v19, LOCK_MODIFY, &info, 0, 0) )
    {
      *info.mData = 0;
      v22 = ++info.mData;
      v23 = 0;
      if ( v18 > 3 )
        v23 = -1;
      *v22 = v23;
      v24 = ++info.mData;
      v25 = 0;
      if ( v18 > 5 )
        v25 = -1;
      *v24 = v25;
      v26 = ++info.mData;
      v27 = 0;
      if ( v18 > 1 )
        v27 = -1;
      *v26 = v27;
      v28 = &info.mData[info.mLinePitch - 3];
      info.mData = v28;
      v29 = 0;
      if ( v18 > 0 )
        v29 = -1;
      *v28 = v29;
      v30 = ++info.mData;
      v31 = 0;
      if ( v18 > 6 )
        v31 = -1;
      *v30 = v31;
      v32 = ++info.mData;
      v33 = 0;
      if ( v18 > 2 )
        v33 = -1;
      *v32 = v33;
      v34 = ++info.mData;
      v35 = 0;
      if ( v18 > 4 )
        v35 = -1;
      *v34 = v35;
      ++info.mData;
      Illusion::ITexturePlat::Unlock(*v19);
    }
    UFG::qString::~qString(&result);
    ++v18;
    ++v19;
  }
  while ( v18 + 7 <= 14 );
  qword_142128EE8 = (Illusion::Texture *)Illusion::CreateTexture("DitherTex_111", 4, 2, FORMAT_X8, 0x440400u, 1, 0, 0);
  v36 = Illusion::Texture::GetSamplerAddressFlags(qword_142128EE8);
  Illusion::Texture::SetSamplerState(qword_142128EE8, 2u, v36 & 0xFFFFFFFC);
  if ( Illusion::ITexturePlat::Lock(qword_142128EE8, LOCK_MODIFY, &info, 0, 0) )
  {
    *info.mData++ = -1;
    *info.mData++ = -1;
    *info.mData++ = -1;
    *info.mData = -1;
    info.mData += info.mLinePitch - 3;
    *info.mData++ = -1;
    *info.mData++ = -1;
    *info.mData++ = -1;
    *info.mData++ = -1;
    Illusion::ITexturePlat::Unlock(qword_142128EE8);
  }
}

