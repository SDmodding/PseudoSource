// File Line: 25
// RVA: 0xA15B20
void __fastcall Illusion::Target::Target(Illusion::Target *this)
{
  Illusion::Target *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  Illusion::TargetPlat *v3; // rax

  v1 = this;
  v2 = UFG::qMalloc(0x458ui64, (const char *)&stru_141A183E8.skipToken.getText, 0x800ui64);
  if ( v2 )
    Illusion::TargetPlat::TargetPlat((Illusion::TargetPlat *)v2);
  else
    v3 = 0i64;
  v1->mTargetPlat = v3;
  v1->mDepthTexture = 0i64;
  v1->mDepthTextureCopy = 0i64;
  v1->mNumTargetTextures = 0;
  v1->mTargetTexture[0] = 0i64;
  v1->mTargetTexture[1] = 0i64;
  v1->mTargetTexture[2] = 0i64;
  v1->mTargetTexture[3] = 0i64;
  *(_DWORD *)v1->mOwnsTargetTexture = 0;
  v1->mOwnsDepthTexture = 0;
}

// File Line: 42
// RVA: 0xA16920
void __fastcall Illusion::Target::~Target(Illusion::Target *this)
{
  Illusion::TargetPlat *v1; // rbx

  v1 = this->mTargetPlat;
  if ( v1 )
  {
    Illusion::TargetPlat::~TargetPlat(this->mTargetPlat);
    operator delete[](v1);
  }
}

// File Line: 62
// RVA: 0xA17F70
void __fastcall Illusion::ITargetPlat::Create(Illusion::ITargetPlat *this, Illusion::CreateTargetParams *params)
{
  Illusion::CreateTargetParams *v2; // rbx
  Illusion::ITargetPlat *v3; // r13
  __int64 v4; // r15
  __int64 v5; // rdi
  unsigned int v6; // er12
  __int64 v7; // rsi
  UFG::qString *v8; // rax
  unsigned int v9; // eax
  unsigned int flags; // edi
  unsigned int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  UFG::qResourceData *v14; // rax
  int v15; // edi
  __int128 v16; // xmm1
  UFG::qString *v17; // rax
  UFG::qString *v18; // rcx
  UFG::qString *v19; // rax
  unsigned int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  UFG::qResourceData *v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // r8
  unsigned int v27; // edx
  __int64 v28; // r14
  __int64 v29; // rax
  signed int v30; // edi
  int i; // edi
  signed int v32; // eax
  int v33; // edi
  unsigned int v34; // eax
  char v35; // di
  char v36; // dl
  __int64 v37; // rcx
  __int128 v38; // xmm1
  UFG::qString *v39; // rax
  UFG::qString *v40; // rax
  UFG::qString *v41; // rax
  UFG::qString *v42; // rax
  int v43; // er12
  unsigned int esram_usage_bytes; // eax
  int v45; // er8
  int v46; // edx
  UFG::qResourceData *v47; // rax
  __int64 v48; // rax
  UFG::qString *v49; // rax
  __int64 v50; // rdx
  __int64 v51; // r8
  __int64 v52; // rdx
  __int64 v53; // rax
  __int64 v54; // [rsp+50h] [rbp-88h]
  __int128 v55; // [rsp+58h] [rbp-80h]
  __int64 v56; // [rsp+68h] [rbp-70h]
  UFG::qString v57; // [rsp+70h] [rbp-68h]
  UFG::qString v58; // [rsp+A0h] [rbp-38h]
  UFG::qString v59; // [rsp+C8h] [rbp-10h]
  UFG::qString v60; // [rsp+F8h] [rbp+20h]
  __int64 v61; // [rsp+120h] [rbp+48h]
  UFG::qNode<UFG::qString,UFG::qString> v62; // [rsp+128h] [rbp+50h]
  __int128 v63; // [rsp+138h] [rbp+60h]
  __int64 v64; // [rsp+148h] [rbp+70h]
  UFG::qString v65; // [rsp+158h] [rbp+80h]
  UFG::qString result; // [rsp+180h] [rbp+A8h]
  unsigned int v67; // [rsp+1D8h] [rbp+100h]

  v61 = -2i64;
  v2 = params;
  v3 = this;
  v4 = *(_QWORD *)&this[8];
  v5 = 0i64;
  v67 = 0;
  v6 = 2048;
  if ( *(_DWORD *)&this[16] )
  {
    while ( 1 )
    {
      v7 = (unsigned int)v5;
      if ( !*(_QWORD *)&v3[8 * v5 + 24] )
        break;
LABEL_50:
      v24 = *(_QWORD *)&v3[8 * v7 + 24];
      if ( !v24 || !(*(_DWORD *)(v24 + 88) & 0x800) )
        goto LABEL_74;
      v54 = 0i64;
      *(_QWORD *)&v55 = 0i64;
      DWORD2(v55) = 0;
      v25 = *(_QWORD *)(v24 + 296);
      if ( !v25 || *(_DWORD *)(v25 + 24) != *(_DWORD *)(v24 + 304) )
        Illusion::TextureD3DResourceInventory::ForceLoad(
          &Illusion::gTextureD3DResourceInventory,
          *(_DWORD *)(v24 + 304));
      v26 = *(_QWORD *)&v3[8 * v7 + 24];
      LODWORD(v54) = *(_DWORD *)(*(_QWORD *)(v26 + 296) + 104i64);
      v27 = v2->texture_type;
      if ( v27 == 1 )
        HIDWORD(v54) = 8;
      else
        HIDWORD(v54) = (v27 - 2 <= 1) + 4;
      v28 = *(_QWORD *)(*(_QWORD *)(v26 + 296) + 136i64);
      v29 = *(_QWORD *)(v4 + 8 * v7 + 1072);
      if ( v29 )
        v28 = *(_QWORD *)(*(_QWORD *)(v29 + 296) + 136i64);
      if ( v27 == 2 )
      {
        DWORD2(v55) = 1;
        v30 = 0;
        do
        {
          DWORD1(v55) = v30;
          ((void (__fastcall *)(ID3D11Device *, __int64, __int64 *, __int64))UFG::gD3D11Device->vfptr->Draw)(
            UFG::gD3D11Device,
            v28,
            &v54,
            v4 + 8 * (v7 + 4 * (v30++ + 1i64)));
        }
        while ( v30 < 6 );
LABEL_73:
        LODWORD(v5) = v67;
        goto LABEL_74;
      }
      if ( v27 == 3 )
      {
        DWORD2(v55) = v2->depth;
        DWORD1(v55) = 0;
        ((void (__fastcall *)(ID3D11Device *, __int64, __int64 *, __int64))UFG::gD3D11Device->vfptr->Draw)(
          UFG::gD3D11Device,
          v28,
          &v54,
          v4 + 32 + 8 * v7);
        for ( i = 0;
              i < v2->depth;
              ((void (__fastcall *)(ID3D11Device *, __int64, __int64 *, __int64))UFG::gD3D11Device->vfptr->Draw)(
                UFG::gD3D11Device,
                v28,
                &v54,
                v4 + 8 * (v7 + 4 * (i + 1i64))) )
        {
          *(_QWORD *)((char *)&v55 + 4) = __PAIR__(1, i++);
        }
        goto LABEL_73;
      }
      v32 = v2->num_mips;
      if ( v32 > 1 )
      {
        v33 = 0;
        if ( v32 > 0 )
        {
          do
          {
            LODWORD(v55) = v33;
            ((void (__fastcall *)(ID3D11Device *, __int64, __int64 *, __int64))UFG::gD3D11Device->vfptr->Draw)(
              UFG::gD3D11Device,
              v28,
              &v54,
              v4 + 8 * (v7 + 4 * (v33++ + 1i64)));
          }
          while ( v33 < v2->num_mips );
        }
        goto LABEL_73;
      }
      ((void (__fastcall *)(ID3D11Device *, __int64, __int64 *, __int64))UFG::gD3D11Device->vfptr->Draw)(
        UFG::gD3D11Device,
        v28,
        &v54,
        v4 + 32 + 8 * v7);
LABEL_74:
      v5 = (unsigned int)(v5 + 1);
      v67 = v5;
      if ( (unsigned int)v5 >= *(_DWORD *)&v3[16] )
        goto LABEL_75;
    }
    UFG::qString::qString(&v58);
    if ( *(_DWORD *)&v3[16] <= 1u )
    {
      UFG::qString::Set(&v58, v2->name.mData, v2->name.mLength, 0i64, 0);
    }
    else
    {
      v62 = v2->name.0;
      v63 = *(_OWORD *)&v2->name.mMagic;
      v64 = *(_QWORD *)&v2->name.mStringHash32;
      v8 = UFG::qString::FormatEx(&result, "%s_MRT%d", &v62, (unsigned int)v5);
      UFG::qString::Set(&v58, v8->mData, v8->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
    }
    v9 = v2->target_flags;
    flags = 2048;
    if ( _bittest((const signed int *)&v9, 0xEu) )
      flags = 4458496;
    if ( _bittest((const signed int *)&v9, 0xFu) )
      flags |= 0x400u;
    if ( _bittest((const signed int *)&v9, 0x11u) )
      flags |= 0x80000u;
    if ( _bittest((const signed int *)&v9, 0x12u) )
      flags |= 0x100000u;
    if ( _bittest((const signed int *)&v9, 0x13u) )
      flags |= 0x800000u;
    if ( v2->use_esram[v7] && !(v9 & 8) && !(v9 & 4) )
      flags |= 0x2000000u;
    v11 = v2->texture_type;
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
            v3[v7 + 56] = (Illusion::ITargetPlat)1;
            if ( !(v2->target_flags & 8) && !(v2->target_flags & 4) )
              goto LABEL_49;
            if ( v2->use_esram[v7] )
              flags |= 0x2000000u;
            if ( v2->target_flags & 8 )
              v15 = flags | 0x8000000;
            else
              v15 = flags | 0x4000000;
            UFG::qString::qString(&v60);
            v16 = *(_OWORD *)&v2->name.mMagic;
            if ( *(_DWORD *)&v3[16] <= 1u )
            {
              v57.0 = v2->name.0;
              v55 = v16;
              v56 = *(_QWORD *)&v2->name.mStringHash32;
              v19 = UFG::qString::FormatEx((UFG::qString *)((char *)&v57 + 8), "msaa_%s", &v57);
              UFG::qString::Set(&v60, v19->mData, v19->mLength, 0i64, 0);
              v18 = (UFG::qString *)((char *)&v57 + 8);
            }
            else
            {
              v59.0 = v2->name.0;
              *(_OWORD *)&v59.mMagic = v16;
              *(_QWORD *)&v59.mStringHash32 = *(_QWORD *)&v2->name.mStringHash32;
              v17 = UFG::qString::FormatEx(&v65, "msaa_%s_MRT%d", &v59, v67);
              UFG::qString::Set(&v60, v17->mData, v17->mLength, 0i64, 0);
              v18 = &v65;
            }
            UFG::qString::~qString(v18);
            v20 = v2->texture_type;
            if ( v20 )
            {
              v21 = v20 - 1;
              if ( v21 )
              {
                v22 = v21 - 1;
                if ( v22 )
                {
                  if ( v22 != 1 )
                  {
LABEL_48:
                    UFG::qString::~qString(&v60);
LABEL_49:
                    UFG::qString::~qString(&v58);
                    LODWORD(v5) = v67;
                    goto LABEL_50;
                  }
                  v23 = Illusion::CreateTexture2DArray(
                          v60.mData,
                          v2->width,
                          v2->height,
                          v2->depth,
                          (Illusion::Texture::Format)(unsigned __int8)v2->mrt_formats[v7],
                          v15,
                          v2->num_mips,
                          v2->esram_offset[v7],
                          v2->esram_usage_bytes[v7]);
                }
                else
                {
                  v23 = Illusion::CreateTextureCube(
                          v60.mData,
                          v2->width,
                          v2->height,
                          (Illusion::Texture::Format)(unsigned __int8)v2->mrt_formats[v7],
                          v15,
                          v2->num_mips,
                          v2->esram_offset[v7],
                          v2->esram_usage_bytes[v7]);
                }
              }
              else
              {
                v23 = Illusion::CreateTexture3D(
                        v60.mData,
                        v2->width,
                        v2->height,
                        v2->depth,
                        (Illusion::Texture::Format)(unsigned __int8)v2->mrt_formats[v7],
                        v15,
                        v2->num_mips,
                        v2->esram_offset[v7],
                        v2->esram_usage_bytes[v7]);
              }
            }
            else
            {
              v23 = Illusion::CreateTexture(
                      v60.mData,
                      v2->width,
                      v2->height,
                      (Illusion::Texture::Format)(unsigned __int8)v2->mrt_formats[v7],
                      v15,
                      v2->num_mips,
                      v2->esram_offset[v7],
                      v2->esram_usage_bytes[v7]);
            }
            *(_QWORD *)(v4 + 8 * v7 + 1072) = v23;
            goto LABEL_48;
          }
          v14 = Illusion::CreateTexture2DArray(
                  v58.mData,
                  v2->width,
                  v2->height,
                  v2->depth,
                  (Illusion::Texture::Format)(unsigned __int8)v2->mrt_formats[v7],
                  flags,
                  v2->num_mips,
                  v2->esram_offset[v7],
                  v2->esram_usage_bytes[v7]);
        }
        else
        {
          v14 = Illusion::CreateTextureCube(
                  v58.mData,
                  v2->width,
                  v2->height,
                  (Illusion::Texture::Format)(unsigned __int8)v2->mrt_formats[v7],
                  flags,
                  v2->num_mips,
                  v2->esram_offset[v7],
                  v2->esram_usage_bytes[v7]);
        }
      }
      else
      {
        v14 = Illusion::CreateTexture3D(
                v58.mData,
                v2->width,
                v2->height,
                v2->depth,
                (Illusion::Texture::Format)(unsigned __int8)v2->mrt_formats[v7],
                flags,
                v2->num_mips,
                v2->esram_offset[v7],
                v2->esram_usage_bytes[v7]);
      }
    }
    else
    {
      v14 = Illusion::CreateTexture(
              v58.mData,
              v2->width,
              v2->height,
              (Illusion::Texture::Format)(unsigned __int8)v2->mrt_formats[v7],
              flags,
              v2->num_mips,
              v2->esram_offset[v7],
              v2->esram_usage_bytes[v7]);
    }
    *(_QWORD *)&v3[8 * v7 + 24] = v14;
    goto LABEL_29;
  }
LABEL_75:
  v34 = v2->target_flags;
  v35 = (v2->target_flags >> 1) & 1;
  v36 = (v2->target_flags >> 7) & 1;
  if ( v34 & 1 )
  {
    v37 = *(_QWORD *)&v3[64];
    if ( v37 )
    {
      v48 = *(_QWORD *)(v37 + 296);
      if ( !v48 || *(_DWORD *)(v48 + 24) != *(_DWORD *)(v37 + 304) )
        Illusion::TextureD3DResourceInventory::ForceLoad(
          &Illusion::gTextureD3DResourceInventory,
          *(_DWORD *)(v37 + 304));
    }
    else
    {
      if ( v2->use_esram_depth && !(v34 & 8) && !(v34 & 4) )
        v6 = 33556480;
      v38 = *(_OWORD *)&v2->name.mMagic;
      v57.0 = v2->name.0;
      v55 = v38;
      v56 = *(_QWORD *)&v2->name.mStringHash32;
      if ( v36 )
      {
        if ( v2->texture_type == 3 )
        {
          v39 = UFG::qString::FormatEx((UFG::qString *)((char *)&v57 + 8), "%sDepthOut", &v57);
          *(_QWORD *)&v3[64] = Illusion::CreateTexture2DArray(
                                 v39->mData,
                                 v2->width,
                                 v2->height,
                                 v2->depth,
                                 FORMAT_SHADOW,
                                 v6,
                                 1,
                                 v2->esram_offset_depth,
                                 v2->esram_usage_bytes_depth);
        }
        else
        {
          v40 = UFG::qString::FormatEx((UFG::qString *)((char *)&v57 + 8), "%sDepthOut", &v57);
          *(_QWORD *)&v3[64] = Illusion::CreateTexture(
                                 v40->mData,
                                 v2->width,
                                 v2->height,
                                 FORMAT_SHADOW,
                                 v6,
                                 1,
                                 v2->esram_offset_depth,
                                 v2->esram_usage_bytes_depth);
        }
        UFG::qString::~qString((UFG::qString *)((char *)&v57 + 8));
        *(_BYTE *)(*(_QWORD *)&v3[64] + 105i64) = 1;
      }
      else
      {
        if ( v2->texture_type == 3 )
        {
          v41 = UFG::qString::FormatEx((UFG::qString *)((char *)&v57 + 8), "%sDepthOut", &v57);
          *(_QWORD *)&v3[64] = Illusion::CreateTexture2DArray(
                                 v41->mData,
                                 v2->width,
                                 v2->height,
                                 v2->depth,
                                 FORMAT_D24S8,
                                 v6,
                                 1,
                                 v2->esram_offset_depth,
                                 v2->esram_usage_bytes_depth);
        }
        else
        {
          v42 = UFG::qString::FormatEx((UFG::qString *)((char *)&v57 + 8), "%sDepthOut", &v57);
          *(_QWORD *)&v3[64] = Illusion::CreateTexture(
                                 v42->mData,
                                 v2->width,
                                 v2->height,
                                 FORMAT_D24S8,
                                 v6,
                                 1,
                                 v2->esram_offset_depth,
                                 v2->esram_usage_bytes_depth);
        }
        UFG::qString::~qString((UFG::qString *)((char *)&v57 + 8));
      }
      if ( v2->target_flags & 8 || v2->target_flags & 4 )
      {
        if ( v2->use_esram_depth )
          v6 |= 0x2000000u;
        if ( v2->target_flags & 8 )
          v43 = v6 | 0x8000000;
        else
          v43 = v6 | 0x4000000;
        v57.0 = v2->name.0;
        v55 = *(_OWORD *)&v2->name.mMagic;
        v56 = *(_QWORD *)&v2->name.mStringHash32;
        UFG::qString::FormatEx(&v59, "msaa_%sDepthOut", &v57);
        esram_usage_bytes = v2->esram_usage_bytes_depth;
        v45 = v2->height;
        v46 = v2->width;
        if ( v2->texture_type == 3 )
          v47 = Illusion::CreateTexture2DArray(
                  v59.mData,
                  v46,
                  v45,
                  v2->depth,
                  FORMAT_D24S8,
                  v43,
                  1,
                  v2->esram_offset_depth,
                  esram_usage_bytes);
        else
          v47 = Illusion::CreateTexture(
                  v59.mData,
                  v46,
                  v45,
                  FORMAT_D24S8,
                  v43,
                  1,
                  v2->esram_offset_depth,
                  esram_usage_bytes);
        *(_QWORD *)&v3[64] = v47;
        UFG::qString::~qString(&v59);
      }
      v3[80] = (Illusion::ITargetPlat)1;
    }
    if ( v2->target_flags & 0x10000 )
    {
      v57.0 = v2->name.0;
      v55 = *(_OWORD *)&v2->name.mMagic;
      v56 = *(_QWORD *)&v2->name.mStringHash32;
      v49 = UFG::qString::FormatEx((UFG::qString *)((char *)&v57 + 8), "%sDepth", &v57);
      *(_QWORD *)&v3[72] = Illusion::CreateTexture(v49->mData, v2->width, v2->height, FORMAT_DEPTHCOPY, 0, 1, 0, 0);
      UFG::qString::~qString((UFG::qString *)((char *)&v57 + 8));
      *(_BYTE *)(*(_QWORD *)&v3[72] + 105i64) = 2;
      v50 = *(_QWORD *)&v3[72];
      v51 = *(_QWORD *)(v50 + 296);
      if ( !v51 || *(_DWORD *)(v51 + 24) != *(_DWORD *)(v50 + 304) )
        Illusion::TextureD3DResourceInventory::ForceLoad(
          &Illusion::gTextureD3DResourceInventory,
          *(_DWORD *)(v50 + 304));
    }
    v54 = 0i64;
    v55 = 0ui64;
    LODWORD(v54) = 45;
    switch ( v2->texture_type )
    {
      case 1u:
        goto LABEL_116;
      case 2u:
        HIDWORD(v55) = 1;
        break;
      case 3u:
        HIDWORD(v55) = v2->depth;
        break;
      default:
        HIDWORD(v54) = 3;
LABEL_116:
        v52 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v3[64] + 296i64) + 136i64);
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
        *(_BYTE *)(v4 + 3) = (v2->target_flags >> 12) & 1;
        goto LABEL_119;
    }
    HIDWORD(v54) = 4;
    goto LABEL_116;
  }
LABEL_119:
  *(_WORD *)(v4 + 4) = v2->num_mips;
  *(_BYTE *)(v4 + 2) = v2->num_mrt;
}

// File Line: 402
// RVA: 0xA19F30
void __fastcall Illusion::ITargetPlat::EndQuery(Illusion::OcclusionPlat *this, unsigned int curQuery, unsigned int numTiles)
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
void __fastcall Illusion::ITargetPlat::EndTarget(Illusion::ITargetPlat *this, Illusion::BeginTargetCommandParams *target_params)
{
  __int64 v2; // r12
  unsigned int v3; // ebx
  __int64 v4; // r14
  Illusion::ITargetPlat *v5; // rdi
  Illusion::BeginTargetCommandParams *v6; // r15
  unsigned int v7; // esi
  __int64 v8; // r9
  __int64 v9; // rcx
  __int64 v10; // r8
  int v11; // ST38_4
  __int64 v12; // rcx
  __int64 v13; // rcx
  __int64 v14; // [rsp+20h] [rbp-58h]
  __int64 v15; // [rsp+28h] [rbp-50h]

  v2 = tls_index;
  v3 = 0;
  v4 = *(_QWORD *)&this[8];
  v5 = this;
  v6 = target_params;
  v7 = 0;
  if ( *(_DWORD *)&this[16] )
  {
    do
    {
      v8 = *(_QWORD *)(v4 + 8i64 * v7 + 1072);
      if ( v8 )
      {
        v9 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + v2) + 104i64);
        LODWORD(v15) = Illusion::HardwareState::sTextureFormat[*(unsigned __int8 *)(v8 + 92)];
        LODWORD(v14) = v6->mDestFaceSlice;
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, __int64, __int64))(*(_QWORD *)v9 + 456i64))(
          v9,
          *(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v5[8 * v7 + 24] + 296i64) + 136i64),
          v6->mDestFaceSlice,
          *(_QWORD *)(*(_QWORD *)(v8 + 296) + 136i64),
          v14,
          v15);
      }
      ++v7;
    }
    while ( v7 < *(_DWORD *)&v5[16] );
    v3 = 0;
  }
  v10 = *(_QWORD *)&v5[72];
  if ( v10 && (!v6 || !(v6->mFlags & 8)) )
  {
    v11 = 0;
    v12 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + v2) + 104i64);
    LODWORD(v15) = 0;
    LODWORD(v14) = 0;
    (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, __int64, __int64, _QWORD, int, _QWORD))(*(_QWORD *)v12 + 368i64))(
      v12,
      *(_QWORD *)(*(_QWORD *)(v10 + 296) + 136i64),
      0i64,
      0i64,
      v14,
      v15,
      *(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v5[64] + 296i64) + 136i64),
      v11,
      0i64);
  }
  if ( *(_DWORD *)&v5[16] )
  {
    do
    {
      v13 = *(_QWORD *)&v5[8 * v3 + 24];
      if ( v13 )
      {
        if ( *(_DWORD *)(v13 + 88) & 0x400000 )
          Illusion::TexturePlat::UpdateStagingResources((Illusion::TexturePlat *)(v13 + 208));
      }
      ++v3;
    }
    while ( v3 < *(_DWORD *)&v5[16] );
  }
}

