// File Line: 25
// RVA: 0xA15B20
void __fastcall Illusion::Target::Target(Illusion::Target *this)
{
  UFG::allocator::free_link *v2; // rax
  Illusion::TargetPlat *v3; // rax

  v2 = UFG::qMalloc(0x458ui64, (const char *)&stru_141A183E8.skipToken.getText, 0x800ui64);
  if ( v2 )
    Illusion::TargetPlat::TargetPlat((Illusion::TargetPlat *)v2);
  else
    v3 = 0i64;
  this->mTargetPlat = v3;
  this->mDepthTexture = 0i64;
  this->mDepthTextureCopy = 0i64;
  this->mNumTargetTextures = 0;
  this->mTargetTexture[0] = 0i64;
  this->mTargetTexture[1] = 0i64;
  this->mTargetTexture[2] = 0i64;
  this->mTargetTexture[3] = 0i64;
  *(_DWORD *)this->mOwnsTargetTexture = 0;
  this->mOwnsDepthTexture = 0;
}

// File Line: 42
// RVA: 0xA16920
void __fastcall Illusion::Target::~Target(Illusion::Target *this)
{
  Illusion::TargetPlat *mTargetPlat; // rbx

  mTargetPlat = this->mTargetPlat;
  if ( mTargetPlat )
  {
    Illusion::TargetPlat::~TargetPlat(this->mTargetPlat);
    operator delete[](mTargetPlat);
  }
}

// File Line: 62
// RVA: 0xA17F70
void __fastcall Illusion::ITargetPlat::Create(Illusion::ITargetPlat *this, Illusion::CreateTargetParams *params)
{
  __int64 v4; // r15
  __int64 v5; // rdi
  unsigned int v6; // r12d
  __int64 v7; // rsi
  UFG::qString *v8; // rax
  unsigned int target_flags; // eax
  unsigned int flags; // edi
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  Illusion::Texture *TextureCube; // rax
  unsigned int v15; // ecx
  int v16; // edi
  __int128 v17; // xmm1
  UFG::qString *v18; // rax
  UFG::qString *p_mNext; // rcx
  UFG::qString *v20; // rax
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  Illusion::Texture *Texture2DArray; // rax
  __int64 v25; // rcx
  __int64 v26; // rax
  __int64 v27; // r8
  unsigned int texture_type; // edx
  __int64 v29; // r14
  __int64 v30; // rax
  int i; // edi
  int j; // edi
  int v33; // edi
  unsigned int v34; // eax
  bool v35; // di
  __int64 v36; // rcx
  __int128 v37; // xmm1
  UFG::qString *v38; // rax
  UFG::qString *v39; // rax
  UFG::qString *v40; // rax
  UFG::qString *v41; // rax
  unsigned int v42; // ecx
  int v43; // r12d
  unsigned int esram_usage_bytes; // eax
  int height; // r8d
  int width; // edx
  UFG::qResourceData *Texture; // rax
  __int64 v48; // rax
  UFG::qString *v49; // rax
  __int64 v50; // rdx
  __int64 v51; // r8
  __int64 v52; // rdx
  __int64 v53; // rax
  __int64 v54; // [rsp+50h] [rbp-88h] BYREF
  __int128 v55; // [rsp+58h] [rbp-80h]
  __int64 v56; // [rsp+68h] [rbp-70h]
  UFG::qString v57; // [rsp+70h] [rbp-68h] BYREF
  UFG::qString v58; // [rsp+A0h] [rbp-38h] BYREF
  UFG::qString v59; // [rsp+C8h] [rbp-10h] BYREF
  UFG::qString v60; // [rsp+F8h] [rbp+20h] BYREF
  __int64 v61; // [rsp+120h] [rbp+48h]
  __int128 v62[2]; // [rsp+128h] [rbp+50h] BYREF
  __int64 v63; // [rsp+148h] [rbp+70h]
  UFG::qString v64; // [rsp+158h] [rbp+80h] BYREF
  UFG::qString result; // [rsp+180h] [rbp+A8h] BYREF
  unsigned int v66; // [rsp+1D8h] [rbp+100h]

  v61 = -2i64;
  v4 = *(_QWORD *)&this[8];
  v5 = 0i64;
  v66 = 0;
  v6 = 2048;
  if ( *(_DWORD *)&this[16] )
  {
    while ( 1 )
    {
      v7 = (unsigned int)v5;
      if ( !*(_QWORD *)&this[8 * v5 + 24] )
        break;
LABEL_50:
      v25 = *(_QWORD *)&this[8 * v7 + 24];
      if ( !v25 || (*(_DWORD *)(v25 + 88) & 0x800) == 0 )
        goto LABEL_74;
      v54 = 0i64;
      *(_QWORD *)&v55 = 0i64;
      DWORD2(v55) = 0;
      v26 = *(_QWORD *)(v25 + 296);
      if ( !v26 || *(_DWORD *)(v26 + 24) != *(_DWORD *)(v25 + 304) )
        Illusion::TextureD3DResourceInventory::ForceLoad(
          &Illusion::gTextureD3DResourceInventory,
          *(_DWORD *)(v25 + 304));
      v27 = *(_QWORD *)&this[8 * v7 + 24];
      LODWORD(v54) = *(_DWORD *)(*(_QWORD *)(v27 + 296) + 104i64);
      texture_type = params->texture_type;
      if ( texture_type == 1 )
        HIDWORD(v54) = 8;
      else
        HIDWORD(v54) = (texture_type - 2 <= 1) + 4;
      v29 = *(_QWORD *)(*(_QWORD *)(v27 + 296) + 136i64);
      v30 = *(_QWORD *)(v4 + 8 * v7 + 1072);
      if ( v30 )
        v29 = *(_QWORD *)(*(_QWORD *)(v30 + 296) + 136i64);
      if ( texture_type == 2 )
      {
        DWORD2(v55) = 1;
        for ( i = 0; i < 6; ++i )
        {
          DWORD1(v55) = i;
          ((void (__fastcall *)(ID3D11Device *, __int64, __int64 *, __int64))UFG::gD3D11Device->vfptr->Draw)(
            UFG::gD3D11Device,
            v29,
            &v54,
            v4 + 8 * (v7 + 4 * (i + 1i64)));
        }
LABEL_73:
        LODWORD(v5) = v66;
        goto LABEL_74;
      }
      if ( texture_type == 3 )
      {
        DWORD2(v55) = params->depth;
        DWORD1(v55) = 0;
        ((void (__fastcall *)(ID3D11Device *, __int64, __int64 *, __int64))UFG::gD3D11Device->vfptr->Draw)(
          UFG::gD3D11Device,
          v29,
          &v54,
          v4 + 32 + 8 * v7);
        for ( j = 0;
              j < params->depth;
              ((void (__fastcall *)(ID3D11Device *, __int64, __int64 *, __int64))UFG::gD3D11Device->vfptr->Draw)(
                UFG::gD3D11Device,
                v29,
                &v54,
                v4 + 8 * (v7 + 4 * (j + 1i64))) )
        {
          *(_QWORD *)((char *)&v55 + 4) = (unsigned int)j++ | 0x100000000i64;
        }
        goto LABEL_73;
      }
      if ( params->num_mips > 1 )
      {
        v33 = 0;
        do
        {
          LODWORD(v55) = v33;
          ((void (__fastcall *)(ID3D11Device *, __int64, __int64 *, __int64))UFG::gD3D11Device->vfptr->Draw)(
            UFG::gD3D11Device,
            v29,
            &v54,
            v4 + 8 * (v7 + 4 * ++v33));
        }
        while ( v33 < params->num_mips );
        goto LABEL_73;
      }
      ((void (__fastcall *)(ID3D11Device *, __int64, __int64 *, __int64))UFG::gD3D11Device->vfptr->Draw)(
        UFG::gD3D11Device,
        v29,
        &v54,
        v4 + 32 + 8 * v7);
LABEL_74:
      v5 = (unsigned int)(v5 + 1);
      v66 = v5;
      if ( (unsigned int)v5 >= *(_DWORD *)&this[16] )
        goto LABEL_75;
    }
    UFG::qString::qString(&v58);
    if ( *(_DWORD *)&this[16] <= 1u )
    {
      UFG::qString::Set(&v58, params->name.mData, params->name.mLength, 0i64, 0);
    }
    else
    {
      v62[0] = (__int128)params->name.UFG::qNode<UFG::qString,UFG::qString>;
      v62[1] = *(_OWORD *)&params->name.mMagic;
      v63 = *(_QWORD *)&params->name.mStringHash32;
      v8 = UFG::qString::FormatEx(&result, "%s_MRT%d", (const char *)v62, (unsigned int)v5);
      UFG::qString::Set(&v58, v8->mData, v8->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
    }
    target_flags = params->target_flags;
    flags = 2048;
    if ( (target_flags & 0x4000) != 0 )
      flags = 4458496;
    if ( (target_flags & 0x8000) != 0 )
      flags |= 0x400u;
    if ( (target_flags & 0x20000) != 0 )
      flags |= 0x80000u;
    if ( (target_flags & 0x40000) != 0 )
      flags |= 0x100000u;
    if ( (target_flags & 0x80000) != 0 )
      flags |= 0x800000u;
    if ( params->use_esram[v7] && (target_flags & 8) == 0 && (target_flags & 4) == 0 )
      flags |= 0x2000000u;
    v11 = params->texture_type;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( v12 )
      {
        v13 = v12 - 1;
        if ( v13 )
        {
          if ( v13 != 1 )
          {
LABEL_29:
            this[v7 + 56] = (Illusion::ITargetPlat)1;
            v15 = params->target_flags;
            if ( (v15 & 8) == 0 && (v15 & 4) == 0 )
              goto LABEL_49;
            if ( params->use_esram[v7] )
              flags |= 0x2000000u;
            if ( (params->target_flags & 8) != 0 )
              v16 = flags | 0x8000000;
            else
              v16 = flags | 0x4000000;
            UFG::qString::qString(&v60);
            v17 = *(_OWORD *)&params->name.mMagic;
            if ( *(_DWORD *)&this[16] <= 1u )
            {
              v57.UFG::qNode<UFG::qString,UFG::qString> = params->name.UFG::qNode<UFG::qString,UFG::qString>;
              v55 = v17;
              v56 = *(_QWORD *)&params->name.mStringHash32;
              v20 = UFG::qString::FormatEx((UFG::qString *)&v57.mNext, "msaa_%s", (const char *)&v57);
              UFG::qString::Set(&v60, v20->mData, v20->mLength, 0i64, 0);
              p_mNext = (UFG::qString *)&v57.mNext;
            }
            else
            {
              v59.UFG::qNode<UFG::qString,UFG::qString> = params->name.UFG::qNode<UFG::qString,UFG::qString>;
              *(_OWORD *)&v59.mMagic = v17;
              *(_QWORD *)&v59.mStringHash32 = *(_QWORD *)&params->name.mStringHash32;
              v18 = UFG::qString::FormatEx(&v64, "msaa_%s_MRT%d", (const char *)&v59, v66);
              UFG::qString::Set(&v60, v18->mData, v18->mLength, 0i64, 0);
              p_mNext = &v64;
            }
            UFG::qString::~qString(p_mNext);
            v21 = params->texture_type;
            if ( v21 )
            {
              v22 = v21 - 1;
              if ( v22 )
              {
                v23 = v22 - 1;
                if ( v23 )
                {
                  if ( v23 != 1 )
                  {
LABEL_48:
                    UFG::qString::~qString(&v60);
LABEL_49:
                    UFG::qString::~qString(&v58);
                    LODWORD(v5) = v66;
                    goto LABEL_50;
                  }
                  Texture2DArray = (Illusion::Texture *)Illusion::CreateTexture2DArray(
                                                          v60.mData,
                                                          params->width,
                                                          params->height,
                                                          params->depth,
                                                          (Illusion::Texture::Format)(unsigned __int8)params->mrt_formats[v7],
                                                          v16,
                                                          params->num_mips,
                                                          params->esram_offset[v7],
                                                          params->esram_usage_bytes[v7]);
                }
                else
                {
                  Texture2DArray = Illusion::CreateTextureCube(
                                     v60.mData,
                                     params->width,
                                     params->height,
                                     (Illusion::Texture::Format)(unsigned __int8)params->mrt_formats[v7],
                                     v16,
                                     params->num_mips,
                                     params->esram_offset[v7],
                                     params->esram_usage_bytes[v7]);
                }
              }
              else
              {
                Texture2DArray = Illusion::CreateTexture3D(
                                   v60.mData,
                                   params->width,
                                   params->height,
                                   params->depth,
                                   (Illusion::Texture::Format)(unsigned __int8)params->mrt_formats[v7],
                                   v16,
                                   params->num_mips,
                                   params->esram_offset[v7],
                                   params->esram_usage_bytes[v7]);
              }
            }
            else
            {
              Texture2DArray = (Illusion::Texture *)Illusion::CreateTexture(
                                                      v60.mData,
                                                      params->width,
                                                      params->height,
                                                      (Illusion::Texture::Format)(unsigned __int8)params->mrt_formats[v7],
                                                      v16,
                                                      params->num_mips,
                                                      params->esram_offset[v7],
                                                      params->esram_usage_bytes[v7]);
            }
            *(_QWORD *)(v4 + 8 * v7 + 1072) = Texture2DArray;
            goto LABEL_48;
          }
          TextureCube = (Illusion::Texture *)Illusion::CreateTexture2DArray(
                                               v58.mData,
                                               params->width,
                                               params->height,
                                               params->depth,
                                               (Illusion::Texture::Format)(unsigned __int8)params->mrt_formats[v7],
                                               flags,
                                               params->num_mips,
                                               params->esram_offset[v7],
                                               params->esram_usage_bytes[v7]);
        }
        else
        {
          TextureCube = Illusion::CreateTextureCube(
                          v58.mData,
                          params->width,
                          params->height,
                          (Illusion::Texture::Format)(unsigned __int8)params->mrt_formats[v7],
                          flags,
                          params->num_mips,
                          params->esram_offset[v7],
                          params->esram_usage_bytes[v7]);
        }
      }
      else
      {
        TextureCube = Illusion::CreateTexture3D(
                        v58.mData,
                        params->width,
                        params->height,
                        params->depth,
                        (Illusion::Texture::Format)(unsigned __int8)params->mrt_formats[v7],
                        flags,
                        params->num_mips,
                        params->esram_offset[v7],
                        params->esram_usage_bytes[v7]);
      }
    }
    else
    {
      TextureCube = (Illusion::Texture *)Illusion::CreateTexture(
                                           v58.mData,
                                           params->width,
                                           params->height,
                                           (Illusion::Texture::Format)(unsigned __int8)params->mrt_formats[v7],
                                           flags,
                                           params->num_mips,
                                           params->esram_offset[v7],
                                           params->esram_usage_bytes[v7]);
    }
    *(_QWORD *)&this[8 * v7 + 24] = TextureCube;
    goto LABEL_29;
  }
LABEL_75:
  v34 = params->target_flags;
  v35 = (v34 & 2) != 0;
  if ( (v34 & 1) != 0 )
  {
    v36 = *(_QWORD *)&this[64];
    if ( v36 )
    {
      v48 = *(_QWORD *)(v36 + 296);
      if ( !v48 || *(_DWORD *)(v48 + 24) != *(_DWORD *)(v36 + 304) )
        Illusion::TextureD3DResourceInventory::ForceLoad(
          &Illusion::gTextureD3DResourceInventory,
          *(_DWORD *)(v36 + 304));
    }
    else
    {
      if ( params->use_esram_depth && (v34 & 8) == 0 && (v34 & 4) == 0 )
        v6 = 33556480;
      v37 = *(_OWORD *)&params->name.mMagic;
      v57.UFG::qNode<UFG::qString,UFG::qString> = params->name.UFG::qNode<UFG::qString,UFG::qString>;
      v55 = v37;
      v56 = *(_QWORD *)&params->name.mStringHash32;
      if ( (v34 & 0x80) != 0 )
      {
        if ( params->texture_type == 3 )
        {
          v38 = UFG::qString::FormatEx((UFG::qString *)&v57.mNext, "%sDepthOut", (const char *)&v57);
          *(_QWORD *)&this[64] = Illusion::CreateTexture2DArray(
                                   v38->mData,
                                   params->width,
                                   params->height,
                                   params->depth,
                                   FORMAT_SHADOW,
                                   v6,
                                   1,
                                   params->esram_offset_depth,
                                   params->esram_usage_bytes_depth);
        }
        else
        {
          v39 = UFG::qString::FormatEx((UFG::qString *)&v57.mNext, "%sDepthOut", (const char *)&v57);
          *(_QWORD *)&this[64] = Illusion::CreateTexture(
                                   v39->mData,
                                   params->width,
                                   params->height,
                                   FORMAT_SHADOW,
                                   v6,
                                   1,
                                   params->esram_offset_depth,
                                   params->esram_usage_bytes_depth);
        }
        UFG::qString::~qString((UFG::qString *)&v57.mNext);
        *(_BYTE *)(*(_QWORD *)&this[64] + 105i64) = 1;
      }
      else
      {
        if ( params->texture_type == 3 )
        {
          v40 = UFG::qString::FormatEx((UFG::qString *)&v57.mNext, "%sDepthOut", (const char *)&v57);
          *(_QWORD *)&this[64] = Illusion::CreateTexture2DArray(
                                   v40->mData,
                                   params->width,
                                   params->height,
                                   params->depth,
                                   FORMAT_D24S8,
                                   v6,
                                   1,
                                   params->esram_offset_depth,
                                   params->esram_usage_bytes_depth);
        }
        else
        {
          v41 = UFG::qString::FormatEx((UFG::qString *)&v57.mNext, "%sDepthOut", (const char *)&v57);
          *(_QWORD *)&this[64] = Illusion::CreateTexture(
                                   v41->mData,
                                   params->width,
                                   params->height,
                                   FORMAT_D24S8,
                                   v6,
                                   1,
                                   params->esram_offset_depth,
                                   params->esram_usage_bytes_depth);
        }
        UFG::qString::~qString((UFG::qString *)&v57.mNext);
      }
      v42 = params->target_flags;
      if ( (v42 & 8) != 0 || (v42 & 4) != 0 )
      {
        if ( params->use_esram_depth )
          v6 |= 0x2000000u;
        if ( (params->target_flags & 8) != 0 )
          v43 = v6 | 0x8000000;
        else
          v43 = v6 | 0x4000000;
        v57.UFG::qNode<UFG::qString,UFG::qString> = params->name.UFG::qNode<UFG::qString,UFG::qString>;
        v55 = *(_OWORD *)&params->name.mMagic;
        v56 = *(_QWORD *)&params->name.mStringHash32;
        UFG::qString::FormatEx(&v59, "msaa_%sDepthOut", (const char *)&v57);
        esram_usage_bytes = params->esram_usage_bytes_depth;
        height = params->height;
        width = params->width;
        if ( params->texture_type == 3 )
          Texture = Illusion::CreateTexture2DArray(
                      v59.mData,
                      width,
                      height,
                      params->depth,
                      FORMAT_D24S8,
                      v43,
                      1,
                      params->esram_offset_depth,
                      esram_usage_bytes);
        else
          Texture = Illusion::CreateTexture(
                      v59.mData,
                      width,
                      height,
                      FORMAT_D24S8,
                      v43,
                      1,
                      params->esram_offset_depth,
                      esram_usage_bytes);
        *(_QWORD *)&this[64] = Texture;
        UFG::qString::~qString(&v59);
      }
      this[80] = (Illusion::ITargetPlat)1;
    }
    if ( (params->target_flags & 0x10000) != 0 )
    {
      v57.UFG::qNode<UFG::qString,UFG::qString> = params->name.UFG::qNode<UFG::qString,UFG::qString>;
      v55 = *(_OWORD *)&params->name.mMagic;
      v56 = *(_QWORD *)&params->name.mStringHash32;
      v49 = UFG::qString::FormatEx((UFG::qString *)&v57.mNext, "%sDepth", (const char *)&v57);
      *(_QWORD *)&this[72] = Illusion::CreateTexture(
                               v49->mData,
                               params->width,
                               params->height,
                               FORMAT_DEPTHCOPY,
                               0,
                               1,
                               0,
                               0);
      UFG::qString::~qString((UFG::qString *)&v57.mNext);
      *(_BYTE *)(*(_QWORD *)&this[72] + 105i64) = 2;
      v50 = *(_QWORD *)&this[72];
      v51 = *(_QWORD *)(v50 + 296);
      if ( !v51 || *(_DWORD *)(v51 + 24) != *(_DWORD *)(v50 + 304) )
        Illusion::TextureD3DResourceInventory::ForceLoad(
          &Illusion::gTextureD3DResourceInventory,
          *(_DWORD *)(v50 + 304));
    }
    v55 = 0ui64;
    v54 = 45i64;
    switch ( params->texture_type )
    {
      case 1u:
        goto LABEL_116;
      case 2u:
        HIDWORD(v55) = 1;
        break;
      case 3u:
        HIDWORD(v55) = params->depth;
        break;
      default:
        HIDWORD(v54) = 3;
LABEL_116:
        v52 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)&this[64] + 296i64) + 136i64);
        v53 = *(_QWORD *)(v4 + 1104);
        if ( v53 )
          v52 = *(_QWORD *)(*(_QWORD *)(v53 + 296) + 136i64);
        ((void (__fastcall *)(ID3D11Device *, __int64, __int64 *, __int64))UFG::gD3D11Device->vfptr->PSSetConstantBuffers)(
          UFG::gD3D11Device,
          v52,
          &v54,
          v4 + 1056);
        *(_BYTE *)(v4 + 1) = 1;
        *(_BYTE *)v4 = v35;
        *(_BYTE *)(v4 + 3) = (params->target_flags & 0x1000) != 0;
        goto LABEL_119;
    }
    HIDWORD(v54) = 4;
    goto LABEL_116;
  }
LABEL_119:
  *(_WORD *)(v4 + 4) = params->num_mips;
  *(_BYTE *)(v4 + 2) = params->num_mrt;
}

// File Line: 402
// RVA: 0xA19F30
void __fastcall Illusion::ITargetPlat::EndQuery(
        Illusion::OcclusionPlat *this,
        unsigned int curQuery,
        unsigned int numTiles)
{
  __int64 v3; // rbx
  __int64 v4; // rcx

  if ( curQuery != -1 )
  {
    v3 = curQuery;
    if ( Illusion::gOcclusionBank.pQueries[curQuery].mState == 2 )
    {
      v4 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
      (*(void (__fastcall **)(__int64, ID3D11Query *))(*(_QWORD *)v4 + 224i64))(
        v4,
        Illusion::gOcclusionBank.pQueries[curQuery].mQuery);
      Illusion::gOcclusionBank.pQueries[v3].mState = 3;
    }
  }
}

// File Line: 418
// RVA: 0xA19FA0
void __fastcall Illusion::ITargetPlat::EndTarget(
        Illusion::ITargetPlat *this,
        Illusion::BeginTargetCommandParams *target_params)
{
  __int64 v2; // r12
  unsigned int v3; // ebx
  __int64 v4; // r14
  unsigned int v7; // esi
  __int64 v8; // r9
  __int64 v9; // rcx
  __int64 v10; // r8
  __int64 v11; // rcx
  __int64 v12; // rcx

  v2 = tls_index;
  v3 = 0;
  v4 = *(_QWORD *)&this[8];
  v7 = 0;
  if ( *(_DWORD *)&this[16] )
  {
    do
    {
      v8 = *(_QWORD *)(v4 + 8i64 * v7 + 1072);
      if ( v8 )
      {
        v9 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + v2) + 104i64);
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, unsigned int, unsigned int))(*(_QWORD *)v9 + 456i64))(
          v9,
          *(_QWORD *)(*(_QWORD *)(*(_QWORD *)&this[8 * v7 + 24] + 296i64) + 136i64),
          target_params->mDestFaceSlice,
          *(_QWORD *)(*(_QWORD *)(v8 + 296) + 136i64),
          target_params->mDestFaceSlice,
          Illusion::HardwareState::sTextureFormat[*(unsigned __int8 *)(v8 + 92)]);
      }
      ++v7;
    }
    while ( v7 < *(_DWORD *)&this[16] );
    v3 = 0;
  }
  v10 = *(_QWORD *)&this[72];
  if ( v10 && (!target_params || (target_params->mFlags & 8) == 0) )
  {
    v11 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + v2) + 104i64);
    (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD, _DWORD, _QWORD))(*(_QWORD *)v11 + 368i64))(
      v11,
      *(_QWORD *)(*(_QWORD *)(v10 + 296) + 136i64),
      0i64,
      0i64,
      0,
      0,
      *(_QWORD *)(*(_QWORD *)(*(_QWORD *)&this[64] + 296i64) + 136i64),
      0,
      0i64);
  }
  if ( *(_DWORD *)&this[16] )
  {
    do
    {
      v12 = *(_QWORD *)&this[8 * v3 + 24];
      if ( v12 )
      {
        if ( (*(_DWORD *)(v12 + 88) & 0x400000) != 0 )
          Illusion::TexturePlat::UpdateStagingResources((Illusion::TexturePlat *)(v12 + 208));
      }
      ++v3;
    }
    while ( v3 < *(_DWORD *)&this[16] );
  }
}

