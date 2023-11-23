// File Line: 26
// RVA: 0x1453F00
void Render::_dynamic_initializer_for__sRasterizeInitialZ__()
{
  sRasterizeInitialZ = _mm_load_si128((const __m128i *)&_xmm);
}

// File Line: 42
// RVA: 0x25370
void __fastcall Render::RasterizeZ::Init(Render::RasterizeZ *this, unsigned int *zbuffer, char flags)
{
  __m128i si128; // xmm0
  __m128i *v4; // rax
  __int64 v5; // rdx

  this->mZBuffer = 0i64;
  this->mZBufferTag = 0i64;
  if ( zbuffer )
  {
    this->mZBuffer = zbuffer;
    this->mZBufferTag = zbuffer + 0x4000;
    if ( (flags & 1) != 0 )
    {
      si128 = _mm_load_si128(&sRasterizeInitialZ);
      v4 = (__m128i *)(zbuffer + 8);
      v5 = 512i64;
      do
      {
        v4[-2] = si128;
        v4[-1] = si128;
        *v4 = si128;
        v4[1] = si128;
        v4[2] = si128;
        v4[3] = si128;
        v4[4] = si128;
        v4[5] = si128;
        v4 += 8;
        --v5;
      }
      while ( v5 );
      *this->mZBufferTag = -1;
    }
  }
  *(_QWORD *)&this->mNumPolys_Total = 0i64;
  *(_QWORD *)&this->mNumPolys_BackFace = 0i64;
  *(_QWORD *)&this->mNumBlocks8 = 0i64;
  this->mNumBlocks4_ZRejected = 0;
}

// File Line: 88
// RVA: 0x24C30
void __fastcall Render::RasterizeZ::Clear(Render::RasterizeZ *this)
{
  _OWORD *mZBuffer; // rax
  __m128i si128; // xmm0
  __int64 v3; // rdx

  mZBuffer = this->mZBuffer;
  si128 = _mm_load_si128(&sRasterizeInitialZ);
  v3 = 512i64;
  do
  {
    *mZBuffer = si128;
    mZBuffer[1] = si128;
    mZBuffer[2] = si128;
    mZBuffer[3] = si128;
    mZBuffer[4] = si128;
    mZBuffer[5] = si128;
    mZBuffer[6] = si128;
    mZBuffer[7] = si128;
    mZBuffer += 8;
    --v3;
  }
  while ( v3 );
  *this->mZBufferTag = -1;
}

// File Line: 128
// RVA: 0x24C80
void __fastcall Render::RasterizeZ::Composite(Render::RasterizeZ *this, __m128i *zbuffer)
{
  const __m128i *mZBuffer; // rax
  __m128i *v3; // rdx
  __m128i *v4; // rcx
  __int64 v5; // r8
  __m128i v6; // xmm2
  __m128i si128; // xmm0
  __m128i v8; // xmm3
  __m128i v9; // xmm0
  __m128i v10; // xmm6
  __m128i v11; // xmm2
  __m128i v12; // xmm0
  __m128i v13; // xmm5
  __m128i v14; // xmm2
  __m128i v15; // xmm0
  __m128i v16; // xmm4
  __m128i v17; // xmm0
  __m128i v18; // xmm2

  mZBuffer = (const __m128i *)this->mZBuffer;
  v3 = zbuffer + 2;
  v4 = (__m128i *)((char *)this->mZBuffer + 32);
  v5 = 1024i64;
  do
  {
    v6 = v3[-2];
    si128 = _mm_load_si128(mZBuffer);
    v8 = v3[1];
    v4 += 4;
    mZBuffer += 4;
    v3 += 4;
    v9 = _mm_cmpgt_epi32(si128, v6);
    v10 = _mm_or_si128(_mm_andnot_si128(v9, mZBuffer[-4]), _mm_and_si128(v6, v9));
    v11 = v3[-5];
    v12 = _mm_cmpgt_epi32(_mm_load_si128(v4 - 5), v11);
    v13 = _mm_or_si128(_mm_andnot_si128(v12, v4[-5]), _mm_and_si128(v11, v12));
    v14 = v3[-4];
    v15 = _mm_cmpgt_epi32(_mm_load_si128(v4 - 4), v14);
    v16 = _mm_or_si128(_mm_andnot_si128(v15, v4[-4]), _mm_and_si128(v14, v15));
    v17 = _mm_cmpgt_epi32(_mm_load_si128(v4 - 3), v8);
    v18 = _mm_andnot_si128(v17, v4[-3]);
    mZBuffer[-4] = v10;
    v4[-5] = v13;
    v4[-4] = v16;
    v4[-3] = _mm_or_si128(v18, _mm_and_si128(v8, v17));
    --v5;
  }
  while ( v5 );
}

// File Line: 258
// RVA: 0x25360
void __fastcall Render::OcclusionMap::Init(Render::OcclusionMap *this, char *obuffer)
{
  this->mOBuffer0 = obuffer;
  this->mOBuffer1 = obuffer + 0x8000;
}

// File Line: 264
// RVA: 0x24C20
void __fastcall Render::OcclusionMap::BeginFrame(Render::OcclusionMap *this, UFG::qMatrix44 *world_view_projection)
{
  this->mWorldViewProjection = world_view_projection;
  this->mNumPixelsTested = 0;
}

// File Line: 278
// RVA: 0x24D50
void __fastcall Render::OcclusionMap::CreateFromZBuffer(Render::OcclusionMap *this, const __m128i *zbuffer)
{
  __int64 v2; // r10
  __m128i *v4; // r9
  __int64 v5; // r8
  __m128i *v6; // rax
  __int64 v7; // rcx
  __m128i si128; // xmm5
  __m128i v9; // xmm3
  __m128i v10; // xmm1
  __m128i v11; // xmm6
  __m128i v12; // xmm4
  __m128i v13; // xmm2
  __m128i v14; // xmm0
  __m128i *mOBuffer0; // rax
  __m128i *mOBuffer1; // rcx
  __m128i v17; // xmm5
  __m128i v18; // xmm4
  __m128i v19; // xmm7
  __m128i v20; // xmm8
  __m128i v21; // xmm9
  __m128i v22; // xmm12
  __m128i v23; // xmm1
  __m128i v24; // xmm6
  __m128i v25; // xmm10
  __m128i v26; // xmm1
  __m128i v27; // xmm13
  __m128i v28; // xmm0
  __m128i v29; // xmm4
  __m128i v30; // xmm15
  __m128i v31; // xmm14
  __m128i v32; // xmm10
  __m128i v33; // xmm0
  __m128i v34; // xmm15
  __m128i v35; // xmm2
  __m128i v36; // xmm13
  __m128i v37; // xmm6
  __m128i v38; // xmm2
  __m128i v39; // xmm3
  __m128i v40; // xmm0
  __m128i v41; // xmm5
  __m128i v42; // xmm11
  __m128i v43; // xmm0
  __m128i v44; // xmm8
  __m128i v45; // xmm1
  __m128i v46; // xmm12
  __m128i v47; // xmm14
  __m128i v48; // xmm0
  __m128i v49; // xmm8
  __m128i v50; // xmm9
  __m128i v51; // xmm3
  __m128i v52; // xmm9
  __m128i v53; // xmm1
  __m128i v54; // xmm7
  __m128i v55; // xmm11
  __m128i v56; // xmm12
  __m128i v57; // xmm4
  __m128i v58; // xmm6
  __m128i v59; // xmm3
  __m128i v60; // xmm10
  __m128i v61; // xmm5
  __m128i v62; // xmm11
  __m128i v63; // xmm2
  __m128i v64; // xmm4
  __m128i v65; // xmm7
  __m128i v66; // xmm1
  __m128i v67; // xmm3
  __m128i v68; // xmm10
  __m128i v69; // xmm12
  __m128i v70; // xmm6
  __m128i v71; // xmm4
  __m128i v72; // xmm1
  __m128i v73; // xmm13
  __m128i v74; // xmm10
  __m128i v75; // xmm14
  __m128i v76; // xmm11
  __m128i v77; // xmm5
  __m128i v78; // xmm2
  __m128i v79; // xmm15
  __m128i v80; // xmm2
  __m128i v81; // xmm9
  __m128i v82; // xmm3
  __m128i v83; // xmm8
  __m128i v84; // xmm1
  __m128i v85; // xmm7
  __m128i v86; // xmm3
  __m128i v87; // xmm6
  __m128i v88; // xmm10
  __m128i v89; // xmm6
  __m128i v90; // xmm2
  __m128i v91; // xmm5
  __m128i v92; // xmm3
  __m128i v93; // xmm4
  __m128i v94; // xmm4
  __m128i v95; // xmm2
  __m128i v96; // xmm1
  __m128i v97; // [rsp+0h] [rbp-148h]
  __m128i v98; // [rsp+0h] [rbp-148h]
  __m128i v99; // [rsp+0h] [rbp-148h]
  __m128i v100; // [rsp+10h] [rbp-138h]
  __m128i v101; // [rsp+10h] [rbp-138h]
  __m128i v102; // [rsp+20h] [rbp-128h]
  __m128i v103; // [rsp+20h] [rbp-128h]
  __m128i v104; // [rsp+30h] [rbp-118h]
  __m128i v105; // [rsp+40h] [rbp-108h]
  __m128i v106; // [rsp+60h] [rbp-E8h]
  __m128i v107; // [rsp+70h] [rbp-D8h]
  __m128i v108; // [rsp+80h] [rbp-C8h]
  __m128i v109; // [rsp+90h] [rbp-B8h]

  v2 = 32i64;
  v4 = (__m128i *)((char *)this->mOBuffer0 + 512);
  v5 = 128i64;
  do
  {
    v6 = v4;
    v7 = 16i64;
    do
    {
      si128 = _mm_load_si128(&UFG::gVmxPlat_32768_sw);
      v9 = _mm_load_si128(&UFG::gVmxPlat_32768_sh);
      ++v6;
      v10 = _mm_sub_epi32(_mm_load_si128(zbuffer), si128);
      v11 = _mm_add_epi16(
              _mm_packs_epi32(
                _mm_sub_epi32(_mm_load_si128(zbuffer + 1), si128),
                _mm_sub_epi32(_mm_load_si128(zbuffer + 5), si128)),
              v9);
      v12 = _mm_add_epi16(
              _mm_packs_epi32(
                _mm_sub_epi32(_mm_load_si128(zbuffer + 2), si128),
                _mm_sub_epi32(_mm_load_si128(zbuffer + 6), si128)),
              v9);
      v13 = _mm_add_epi16(
              _mm_packs_epi32(
                _mm_sub_epi32(_mm_load_si128(zbuffer + 3), si128),
                _mm_sub_epi32(_mm_load_si128(zbuffer + 7), si128)),
              v9);
      v14 = _mm_load_si128(zbuffer + 4);
      zbuffer += 8;
      v6[-33] = _mm_add_epi16(_mm_packs_epi32(v10, _mm_sub_epi32(v14, si128)), v9);
      v6[-17] = v11;
      v6[-1] = v12;
      v6[15] = v13;
      --v7;
    }
    while ( v7 );
    v4 += 64;
    --v2;
  }
  while ( v2 );
  mOBuffer0 = (__m128i *)this->mOBuffer0;
  mOBuffer1 = (__m128i *)this->mOBuffer1;
  do
  {
    v17 = mOBuffer0[12];
    v18 = mOBuffer0[2];
    v19 = mOBuffer0[13];
    v20 = mOBuffer0[14];
    v21 = mOBuffer0[15];
    v22 = mOBuffer0[11];
    v23 = mOBuffer0[3];
    v24 = _mm_unpackhi_epi16(v23, mOBuffer0[7]);
    v25 = _mm_unpacklo_epi16(*mOBuffer0, mOBuffer0[4]);
    v26 = _mm_unpacklo_epi16(v23, mOBuffer0[7]);
    v100 = _mm_unpackhi_epi16(*mOBuffer0, mOBuffer0[4]);
    v27 = mOBuffer0[1];
    v28 = _mm_unpacklo_epi16(v18, mOBuffer0[6]);
    v29 = _mm_unpackhi_epi16(v18, mOBuffer0[6]);
    v30 = _mm_unpackhi_epi16(v27, mOBuffer0[5]);
    v31 = _mm_unpacklo_epi16(v25, v28);
    v102 = _mm_unpackhi_epi16(v25, v28);
    v32 = _mm_unpacklo_epi16(v30, v24);
    v108 = _mm_unpacklo_epi16(v100, v29);
    v33 = mOBuffer0[8];
    v101 = _mm_unpackhi_epi16(v100, v29);
    v34 = _mm_unpackhi_epi16(v30, v24);
    v35 = _mm_unpacklo_epi16(v27, mOBuffer0[5]);
    v36 = _mm_unpackhi_epi16(v35, v26);
    v97 = _mm_unpackhi_epi16(v33, v17);
    v37 = _mm_unpacklo_epi16(v33, v17);
    v38 = _mm_unpacklo_epi16(v35, v26);
    v39 = mOBuffer0[9];
    v40 = mOBuffer0[10];
    v41 = _mm_unpackhi_epi16(v39, v19);
    v42 = _mm_unpackhi_epi16(v40, v20);
    v43 = _mm_unpacklo_epi16(v40, v20);
    v44 = v31;
    v45 = _mm_unpacklo_epi16(v22, v21);
    v104 = _mm_unpacklo_epi16(v37, v43);
    v106 = _mm_unpackhi_epi16(v37, v43);
    v46 = _mm_unpackhi_epi16(v22, v21);
    v47 = _mm_unpacklo_epi16(v31, v38);
    v48 = _mm_unpacklo_epi16(v97, v42);
    v49 = _mm_unpackhi_epi16(v44, v38);
    v50 = _mm_unpacklo_epi16(v39, v19);
    v98 = _mm_unpackhi_epi16(v97, v42);
    v51 = _mm_unpackhi_epi16(v50, v45);
    v52 = _mm_unpacklo_epi16(v50, v45);
    v53 = _mm_load_si128(&UFG::gVmxConstI_Min_sh);
    v107 = _mm_unpacklo_epi16(v41, v46);
    v105 = v51;
    v109 = _mm_unpackhi_epi16(v41, v46);
    v54 = _mm_cmpgt_epi16(_mm_add_epi16(v47, v53), _mm_add_epi16(v49, v53));
    v55 = _mm_unpacklo_epi16(v108, v32);
    v56 = _mm_unpacklo_epi16(v102, v36);
    v57 = _mm_unpackhi_epi16(v102, v36);
    v58 = _mm_unpackhi_epi16(v108, v32);
    v59 = _mm_cmpgt_epi16(_mm_add_epi16(v56, v53), _mm_add_epi16(v57, v53));
    v60 = _mm_unpacklo_epi16(v101, v34);
    v61 = _mm_cmpgt_epi16(_mm_add_epi16(v55, v53), _mm_add_epi16(v58, v53));
    v103 = _mm_or_si128(_mm_and_si128(v56, v59), _mm_andnot_si128(v59, v57));
    v62 = _mm_or_si128(_mm_and_si128(v55, v61), _mm_andnot_si128(v61, v58));
    v63 = _mm_unpackhi_epi16(v101, v34);
    v64 = _mm_or_si128(_mm_and_si128(v54, v47), _mm_andnot_si128(v54, v49));
    v65 = v53;
    v66 = _mm_cmpgt_epi16(_mm_add_epi16(v60, UFG::gVmxConstI_Min_sh), _mm_add_epi16(v63, UFG::gVmxConstI_Min_sh));
    v67 = _mm_cmpgt_epi16(_mm_add_epi16(v64, v65), _mm_add_epi16(v103, v65));
    v68 = _mm_or_si128(_mm_and_si128(v60, v66), _mm_andnot_si128(v66, v63));
    v69 = _mm_or_si128(_mm_andnot_si128(v67, v103), _mm_and_si128(v64, v67));
    v70 = _mm_unpacklo_epi16(v106, v105);
    v71 = _mm_unpackhi_epi16(v106, v105);
    v72 = _mm_cmpgt_epi16(_mm_add_epi16(v62, v65), _mm_add_epi16(v68, v65));
    v73 = _mm_or_si128(_mm_andnot_si128(v72, v68), _mm_and_si128(v62, v72));
    v74 = _mm_unpackhi_epi16(v104, v52);
    v75 = _mm_unpacklo_epi16(v104, v52);
    v76 = _mm_cmpgt_epi16(_mm_add_epi16(v69, v65), _mm_add_epi16(v73, v65));
    v77 = _mm_cmpgt_epi16(_mm_add_epi16(v75, v65), _mm_add_epi16(v74, v65));
    mOBuffer1 += 2;
    mOBuffer0 += 16;
    v78 = v98;
    v79 = _mm_unpacklo_epi16(v48, v107);
    v99 = _mm_unpacklo_epi16(v98, v109);
    v80 = _mm_unpackhi_epi16(v78, v109);
    v81 = _mm_unpackhi_epi16(v48, v107);
    v82 = _mm_cmpgt_epi16(_mm_add_epi16(v70, v65), _mm_add_epi16(v71, v65));
    v83 = _mm_cmpgt_epi16(_mm_add_epi16(v79, v65), _mm_add_epi16(v81, v65));
    v84 = _mm_cmpgt_epi16(_mm_add_epi16(v99, v65), _mm_add_epi16(v80, v65));
    v85 = _mm_or_si128(_mm_andnot_si128(v82, v71), _mm_and_si128(v70, v82));
    v86 = _mm_andnot_si128(v84, v80);
    v87 = _mm_andnot_si128(v77, v74);
    v88 = _mm_load_si128(&UFG::gVmxConstI_Min_sh);
    mOBuffer1[-2] = _mm_or_si128(_mm_and_si128(v69, v76), _mm_andnot_si128(v76, v73));
    v89 = _mm_or_si128(v87, _mm_and_si128(v75, v77));
    v90 = _mm_or_si128(_mm_andnot_si128(v83, v81), _mm_and_si128(v79, v83));
    v91 = _mm_cmpgt_epi16(_mm_add_epi16(v89, v88), _mm_add_epi16(v85, v88));
    v92 = _mm_or_si128(v86, _mm_and_si128(v99, v84));
    v93 = _mm_cmpgt_epi16(_mm_add_epi16(v90, v88), _mm_add_epi16(v92, v88));
    v94 = _mm_or_si128(_mm_andnot_si128(v93, v92), _mm_and_si128(v93, v90));
    v95 = _mm_or_si128(_mm_andnot_si128(v91, v85), _mm_and_si128(v91, v89));
    v96 = _mm_cmpgt_epi16(_mm_add_epi16(v95, v88), _mm_add_epi16(v94, v88));
    mOBuffer1[-1] = _mm_or_si128(_mm_andnot_si128(v96, v94), _mm_and_si128(v95, v96));
    --v5;
  }
  while ( v5 );
}

// File Line: 500
// RVA: 0x1453D70
void Render::_dynamic_initializer_for__masks__()
{
  xmmword_142133D90 = (__int128)_mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffff0000);
  masks[0][0] = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  xmmword_142133D80 = (__int128)masks[0][0];
  xmmword_142133DA0 = (__int128)masks[0][0];
  xmmword_142133DC0 = (__int128)masks[0][0];
  xmmword_142133DE0 = (__int128)masks[0][0];
  xmmword_142133E00 = (__int128)masks[0][0];
  xmmword_142133E20 = (__int128)masks[0][0];
  xmmword_142133E40 = (__int128)masks[0][0];
  xmmword_142133E60 = (__int128)masks[0][0];
  xmmword_142133E80 = (__int128)masks[0][0];
  xmmword_142133DB0 = (__int128)_mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffff00000000);
  xmmword_142133EA0 = xmmword_142133D90;
  xmmword_142133EC0 = xmmword_142133DB0;
  xmmword_142133DD0 = (__int128)_mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffff000000000000);
  xmmword_142133DF0 = (__int128)_mm_load_si128((const __m128i *)&_xmm_ffffffffffffffff0000000000000000);
  xmmword_142133E10 = (__int128)_mm_load_si128((const __m128i *)&_xmm_ffffffffffff00000000000000000000);
  xmmword_142133E30 = (__int128)_mm_load_si128((const __m128i *)&_xmm_ffffffff000000000000000000000000);
  xmmword_142133E50 = (__int128)_mm_load_si128((const __m128i *)&_xmm_ffff0000000000000000000000000000);
  xmmword_142133E70 = 0i64;
  xmmword_142133E90 = 0i64;
  xmmword_142133EB0 = 0i64;
  xmmword_142133ED0 = 0i64;
  xmmword_142133EE0 = xmmword_142133DD0;
  xmmword_142133EF0 = 0i64;
  xmmword_142133F00 = xmmword_142133DF0;
  xmmword_142133F10 = 0i64;
  xmmword_142133F20 = xmmword_142133E10;
  xmmword_142133F30 = 0i64;
  xmmword_142133F40 = xmmword_142133E30;
  xmmword_142133F50 = 0i64;
  xmmword_142133F60 = xmmword_142133E50;
  xmmword_142133F70 = 0i64;
  xmmword_142133F80 = 0i64;
}

// File Line: 520
// RVA: 0x25400
signed __int64 __fastcall Render::OcclusionMap::TestRect(
        Render::OcclusionMap *this,
        unsigned int minx,
        unsigned int miny,
        unsigned int maxx,
        unsigned int maxy,
        unsigned int minw)
{
  unsigned int v6; // r10d
  signed __int64 result; // rax
  unsigned int v9; // r11d
  __m128i si128; // xmm10
  unsigned int v11; // ebp
  unsigned int v12; // esi
  __int64 v13; // rax
  __int64 v14; // rcx
  __m128 v15; // xmm8
  __m128 v16; // xmm7
  __m128 v17; // xmm9
  __m128 v18; // xmm6
  __m128i v19; // xmm5
  int v20; // r8d
  const __m128i *v21; // rdx
  __m128i v22; // xmm0
  const __m128i *v23; // r9
  char *v24; // r8
  __m128i v25; // xmm4
  __m128i v26; // xmm3
  __m128i v27; // xmm2
  __m128i v28; // xmm0
  __m128i v29; // xmm1

  v6 = miny;
  if ( minw <= 0x80 )
    return 1i64;
  v9 = maxy;
  if ( minx >= 0x7F )
    minx = 127;
  si128 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  if ( miny >= 0x7F )
    v6 = 127;
  if ( maxx >= 0x7F )
    maxx = 127;
  if ( maxy >= 0x7F )
    v9 = 127;
  v11 = maxx >> 3;
  v12 = minx >> 3;
  v13 = maxx >> 3;
  v14 = (minx >> 3) + 1i64;
  v15 = (__m128)masks[minx & 7][0];
  v16 = _mm_and_ps(_mm_xor_ps((__m128)masks[v13][0], (__m128)si128), (__m128)masks[v14][0]);
  v17 = _mm_and_ps(_mm_xor_ps((__m128)masks[v13][1], (__m128)si128), (__m128)masks[v14][1]);
  v18 = _mm_xor_ps((__m128)masks[(maxx & 7) + 1][0], (__m128)si128);
  if ( minx >> 3 == maxx >> 3 )
  {
    v16 = 0i64;
    v15 = _mm_and_ps(v15, v18);
    v18 = 0i64;
    v17 = 0i64;
  }
  v19 = _mm_load_si128(&UFG::gVmxConstI_Min_sh);
  v20 = (16 * v6) & 0x1FFFFFFF;
  v21 = (const __m128i *)((char *)this->mOBuffer1 + 32 * v6);
  v22 = _mm_cvtsi32_si128((unsigned __int16)(minw - 128) | ((unsigned __int16)(minw - 128) << 16));
  v23 = (const __m128i *)((char *)this->mOBuffer0 + 16 * v20 + 16 * v12);
  v24 = (char *)((char *)this->mOBuffer0 + 16 * v11 + 16 * v20 - (char *)v23);
  v25 = _mm_add_epi16(_mm_unpacklo_epi32(_mm_unpacklo_epi32(v22, v22), _mm_unpacklo_epi32(v22, v22)), v19);
  while ( 1 )
  {
    v26 = _mm_load_si128(v21);
    v27 = _mm_load_si128(v21 + 1);
    ++v6;
    v21 += 2;
    v28 = _mm_add_epi16(_mm_load_si128(v23), v19);
    v29 = _mm_add_epi16(_mm_load_si128((const __m128i *)&v24[(_QWORD)v23]), v19);
    v23 += 16;
    result = (unsigned int)_mm_movemask_epi8(
                             _mm_cmpeq_epi16(
                               (__m128i)_mm_or_ps(
                                          _mm_or_ps(
                                            _mm_and_ps((__m128)_mm_cmpgt_epi16(v29, v25), v18),
                                            _mm_and_ps((__m128)_mm_cmpgt_epi16(v28, v25), v15)),
                                          _mm_or_ps(
                                            _mm_and_ps((__m128)_mm_cmpgt_epi16(_mm_add_epi16(v27, v19), v25), v17),
                                            _mm_and_ps((__m128)_mm_cmpgt_epi16(_mm_add_epi16(v26, v19), v25), v16))),
                               si128));
    if ( (_DWORD)result )
      break;
    if ( v6 > v9 )
      return result;
  }
  return 1i64;
}

