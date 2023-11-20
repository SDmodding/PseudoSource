// File Line: 26
// RVA: 0x1453F00
void Render::_dynamic_initializer_for__sRasterizeInitialZ__()
{
  _mm_store_si128(&sRasterizeInitialZ, _mm_load_si128((const __m128i *)&_xmm));
}

// File Line: 42
// RVA: 0x25370
void __fastcall Render::RasterizeZ::Init(Render::RasterizeZ *this, void *zbuffer, unsigned int flags)
{
  __m128i v3; // xmm0
  __m128i *v4; // rax
  signed __int64 v5; // rdx

  this->mZBuffer = 0i64;
  this->mZBufferTag = 0i64;
  if ( zbuffer )
  {
    this->mZBuffer = zbuffer;
    this->mZBufferTag = (unsigned int *)((char *)zbuffer + 0x10000);
    if ( flags & 1 )
    {
      v3 = _mm_load_si128(&sRasterizeInitialZ);
      v4 = (__m128i *)((char *)zbuffer + 32);
      v5 = 512i64;
      do
      {
        v4[-2] = v3;
        v4[-1] = v3;
        *v4 = v3;
        v4[1] = v3;
        v4[2] = v3;
        v4[3] = v3;
        v4[4] = v3;
        v4[5] = v3;
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
  _OWORD *v1; // rax
  __m128i v2; // xmm0
  signed __int64 v3; // rdx

  v1 = this->mZBuffer;
  v2 = _mm_load_si128(&sRasterizeInitialZ);
  v3 = 512i64;
  do
  {
    *v1 = v2;
    v1[1] = v2;
    v1[2] = v2;
    v1[3] = v2;
    v1[4] = v2;
    v1[5] = v2;
    v1[6] = v2;
    v1[7] = v2;
    v1 += 8;
    --v3;
  }
  while ( v3 );
  *this->mZBufferTag = -1;
}

// File Line: 128
// RVA: 0x24C80
void __fastcall Render::RasterizeZ::Composite(Render::RasterizeZ *this, void *zbuffer)
{
  const __m128i *v2; // rax
  __m128i *v3; // rdx
  __m128i *v4; // rcx
  signed __int64 v5; // r8
  __m128i v6; // xmm2
  __m128i v7; // xmm0
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

  v2 = (const __m128i *)this->mZBuffer;
  v3 = (__m128i *)((char *)zbuffer + 32);
  v4 = (__m128i *)((char *)this->mZBuffer + 32);
  v5 = 1024i64;
  do
  {
    v6 = v3[-2];
    v7 = _mm_load_si128(v2);
    v8 = v3[1];
    v4 += 4;
    v2 += 4;
    v3 += 4;
    v9 = _mm_cmpgt_epi32(v7, v6);
    v10 = _mm_or_si128(_mm_andnot_si128(v9, v2[-4]), _mm_and_si128(v6, v9));
    v11 = v3[-5];
    v12 = _mm_cmpgt_epi32(_mm_load_si128(v4 - 5), v11);
    v13 = _mm_or_si128(_mm_andnot_si128(v12, v4[-5]), _mm_and_si128(v11, v12));
    v14 = v3[-4];
    v15 = _mm_cmpgt_epi32(_mm_load_si128(v4 - 4), v14);
    v16 = _mm_or_si128(_mm_andnot_si128(v15, v4[-4]), _mm_and_si128(v14, v15));
    v17 = _mm_cmpgt_epi32(_mm_load_si128(v4 - 3), v8);
    v18 = _mm_andnot_si128(v17, v4[-3]);
    v2[-4] = v10;
    v4[-5] = v13;
    v4[-4] = v16;
    v4[-3] = _mm_or_si128(v18, _mm_and_si128(v8, v17));
    --v5;
  }
  while ( v5 );
}

// File Line: 258
// RVA: 0x25360
void __fastcall Render::OcclusionMap::Init(Render::OcclusionMap *this, void *obuffer)
{
  this->mOBuffer0 = obuffer;
  this->mOBuffer1 = (char *)obuffer + 0x8000;
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
void __fastcall Render::OcclusionMap::CreateFromZBuffer(Render::OcclusionMap *this, void *zbuffer)
{
  signed __int64 v2; // r10
  Render::OcclusionMap *v3; // r11
  __m128i *v4; // r9
  signed __int64 v5; // r8
  __m128i *v6; // rax
  signed __int64 v7; // rcx
  __m128i v8; // xmm5
  __m128i v9; // xmm3
  __m128i v10; // xmm1
  __m128i v11; // xmm6
  __m128i v12; // xmm4
  __m128i v13; // xmm2
  __m128i v14; // xmm0
  __m128i *v15; // rax
  __m128i *v16; // rcx
  __m128i v17; // xmm5
  __m128i v18; // xmm4
  __m128i v19; // xmm7
  __m128i v20; // xmm8
  __m128i v21; // xmm15
  __m128i v22; // xmm6
  __m128i v23; // xmm9
  __m128i v24; // xmm11
  __m128i v25; // xmm12
  __m128i v26; // xmm1
  __m128i v27; // xmm6
  __m128i v28; // xmm10
  __m128i v29; // xmm1
  __m128i v30; // ST10_16
  __m128i v31; // xmm13
  __m128i v32; // xmm0
  __m128i v33; // xmm4
  __m128i v34; // xmm15
  __m128i v35; // xmm13
  __m128i v36; // xmm14
  __m128i v37; // ST20_16
  __m128i v38; // xmm10
  __m128i v39; // ST80_16
  __m128i v40; // xmm0
  __m128i v41; // ST10_16
  __m128i v42; // xmm15
  __m128i v43; // xmm2
  __m128i v44; // xmm13
  __m128i v45; // ST00_16
  __m128i v46; // xmm6
  __m128i v47; // xmm2
  __m128i v48; // xmm0
  __m128i v49; // xmm11
  __m128i v50; // xmm0
  __m128i v51; // xmm3
  __m128i v52; // xmm8
  __m128i v53; // xmm1
  __m128i v54; // ST30_16
  __m128i v55; // ST60_16
  __m128i v56; // xmm12
  __m128i v57; // xmm14
  __m128i v58; // xmm0
  __m128i v59; // xmm8
  __m128i v60; // xmm9
  __m128i v61; // ST00_16
  __m128i v62; // xmm3
  __m128i v63; // xmm9
  __m128i v64; // xmm1
  __m128i v65; // ST50_16
  __m128i v66; // xmm0
  __m128i v67; // ST70_16
  __m128i v68; // ST40_16
  __m128i v69; // ST90_16
  __m128i v70; // xmm7
  __m128i v71; // xmm11
  __m128i v72; // xmm12
  __m128i v73; // xmm4
  __m128i v74; // xmm6
  __m128i v75; // xmm3
  __m128i v76; // xmm10
  __m128i v77; // xmm5
  __m128i v78; // ST20_16
  __m128i v79; // xmm11
  __m128i v80; // xmm2
  __m128i v81; // xmm4
  __m128i v82; // xmm7
  __m128i v83; // xmm1
  __m128i v84; // xmm3
  __m128i v85; // xmm10
  __m128i v86; // xmm12
  __m128i v87; // xmm6
  __m128i v88; // xmm4
  __m128i v89; // xmm1
  __m128i v90; // xmm13
  __m128i v91; // xmm10
  __m128i v92; // xmm14
  __m128i v93; // xmm11
  __m128i v94; // xmm5
  __m128i v95; // xmm2
  __m128i v96; // xmm1
  __m128i v97; // xmm15
  __m128i v98; // ST00_16
  __m128i v99; // xmm2
  __m128i v100; // xmm9
  __m128i v101; // xmm3
  __m128i v102; // xmm8
  __m128i v103; // xmm1
  __m128i v104; // xmm7
  __m128i v105; // xmm3
  __m128i v106; // xmm6
  __m128i v107; // xmm10
  __m128i v108; // xmm6
  __m128i v109; // xmm2
  __m128i v110; // xmm5
  __m128i v111; // xmm3
  __m128i v112; // xmm1
  __m128i v113; // xmm4
  __m128i v114; // xmm2
  __m128i v115; // xmm1

  v2 = 32i64;
  v3 = this;
  v4 = (__m128i *)((char *)this->mOBuffer0 + 512);
  v5 = 128i64;
  do
  {
    v6 = v4;
    v7 = 16i64;
    do
    {
      v8 = _mm_load_si128(&UFG::gVmxPlat_32768_sw);
      v9 = _mm_load_si128(&UFG::gVmxPlat_32768_sh);
      ++v6;
      v10 = _mm_sub_epi32(_mm_load_si128((const __m128i *)zbuffer), v8);
      v11 = _mm_add_epi16(
              _mm_packs_epi32(
                _mm_sub_epi32(_mm_load_si128((const __m128i *)zbuffer + 1), v8),
                _mm_sub_epi32(_mm_load_si128((const __m128i *)zbuffer + 5), v8)),
              v9);
      v12 = _mm_add_epi16(
              _mm_packs_epi32(
                _mm_sub_epi32(_mm_load_si128((const __m128i *)zbuffer + 2), v8),
                _mm_sub_epi32(_mm_load_si128((const __m128i *)zbuffer + 6), v8)),
              v9);
      v13 = _mm_add_epi16(
              _mm_packs_epi32(
                _mm_sub_epi32(_mm_load_si128((const __m128i *)zbuffer + 3), v8),
                _mm_sub_epi32(_mm_load_si128((const __m128i *)zbuffer + 7), v8)),
              v9);
      v14 = _mm_load_si128((const __m128i *)zbuffer + 4);
      zbuffer = (char *)zbuffer + 128;
      _mm_store_si128(v6 - 33, _mm_add_epi16(_mm_packs_epi32(v10, _mm_sub_epi32(v14, v8)), v9));
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
  v15 = (__m128i *)v3->mOBuffer0;
  v16 = (__m128i *)v3->mOBuffer1;
  do
  {
    v17 = v15[12];
    v18 = v15[2];
    v19 = v15[13];
    v20 = v15[14];
    v21 = v15[1];
    v22 = v15[3];
    v23 = v15[15];
    v24 = v15[10];
    v25 = v15[11];
    v26 = v22;
    v27 = _mm_unpackhi_epi16(v22, v15[7]);
    v28 = _mm_unpacklo_epi16(*v15, v15[4]);
    v29 = _mm_unpacklo_epi16(v26, v15[7]);
    v30 = _mm_unpackhi_epi16(*v15, v15[4]);
    v31 = v21;
    v32 = _mm_unpacklo_epi16(v18, v15[6]);
    v33 = _mm_unpackhi_epi16(v18, v15[6]);
    v34 = _mm_unpackhi_epi16(v21, v15[5]);
    v35 = _mm_unpacklo_epi16(v31, v15[5]);
    v36 = _mm_unpacklo_epi16(v28, v32);
    v37 = _mm_unpackhi_epi16(v28, v32);
    v38 = _mm_unpacklo_epi16(v34, v27);
    v39 = _mm_unpacklo_epi16(v30, v33);
    v40 = v15[8];
    v41 = _mm_unpackhi_epi16(v30, v33);
    v42 = _mm_unpackhi_epi16(v34, v27);
    v43 = v35;
    v44 = _mm_unpackhi_epi16(v35, v29);
    v45 = _mm_unpackhi_epi16(v40, v17);
    v46 = _mm_unpacklo_epi16(v40, v17);
    v47 = _mm_unpacklo_epi16(v43, v29);
    v48 = v24;
    v49 = _mm_unpackhi_epi16(v24, v20);
    v50 = _mm_unpacklo_epi16(v48, v20);
    v51 = _mm_unpacklo_epi16(v15[9], v19);
    v52 = v36;
    v53 = _mm_unpacklo_epi16(v25, v23);
    v54 = _mm_unpacklo_epi16(v46, v50);
    v55 = _mm_unpackhi_epi16(v46, v50);
    v56 = _mm_unpackhi_epi16(v25, v23);
    v57 = _mm_unpacklo_epi16(v36, v47);
    v58 = _mm_unpacklo_epi16(v45, v49);
    v59 = _mm_unpackhi_epi16(v52, v47);
    v60 = v51;
    v61 = _mm_unpackhi_epi16(v45, v49);
    v62 = _mm_unpackhi_epi16(v51, v53);
    v63 = _mm_unpacklo_epi16(v60, v53);
    v64 = _mm_load_si128(&UFG::gVmxConstI_Min_sh);
    v65 = v58;
    v66 = _mm_unpackhi_epi16(v15[9], v19);
    v67 = _mm_unpacklo_epi16(v66, v56);
    v68 = v62;
    v69 = _mm_unpackhi_epi16(v66, v56);
    v70 = _mm_cmpgt_epi16(_mm_add_epi16(v57, v64), _mm_add_epi16(v59, v64));
    v71 = _mm_unpacklo_epi16(v39, v38);
    v72 = _mm_unpacklo_epi16(v37, v44);
    v73 = _mm_unpackhi_epi16(v37, v44);
    v74 = _mm_unpackhi_epi16(v39, v38);
    v75 = _mm_cmpgt_epi16(_mm_add_epi16(v72, v64), _mm_add_epi16(v73, v64));
    v76 = _mm_unpacklo_epi16(v41, v42);
    v77 = _mm_cmpgt_epi16(_mm_add_epi16(v71, v64), _mm_add_epi16(v74, v64));
    v78 = _mm_or_si128(_mm_and_si128(v72, v75), _mm_andnot_si128(v75, v73));
    v79 = _mm_or_si128(_mm_and_si128(v71, v77), _mm_andnot_si128(v77, v74));
    v80 = _mm_unpackhi_epi16(v41, v42);
    v81 = _mm_or_si128(_mm_and_si128(v70, v57), _mm_andnot_si128(v70, v59));
    v82 = v64;
    v83 = _mm_cmpgt_epi16(_mm_add_epi16(v76, UFG::gVmxConstI_Min_sh), _mm_add_epi16(v80, UFG::gVmxConstI_Min_sh));
    v84 = _mm_cmpgt_epi16(_mm_add_epi16(v81, v82), _mm_add_epi16(v78, v82));
    v85 = _mm_or_si128(_mm_and_si128(v76, v83), _mm_andnot_si128(v83, v80));
    v86 = _mm_or_si128(_mm_andnot_si128(v84, v78), _mm_and_si128(v81, v84));
    v87 = _mm_unpacklo_epi16(v55, v68);
    v88 = _mm_unpackhi_epi16(v55, v68);
    v89 = _mm_cmpgt_epi16(_mm_add_epi16(v79, v82), _mm_add_epi16(v85, v82));
    v90 = _mm_or_si128(_mm_andnot_si128(v89, v85), _mm_and_si128(v79, v89));
    v91 = _mm_unpackhi_epi16(v54, v63);
    v92 = _mm_unpacklo_epi16(v54, v63);
    v93 = _mm_cmpgt_epi16(_mm_add_epi16(v86, v82), _mm_add_epi16(v90, v82));
    v94 = _mm_cmpgt_epi16(_mm_add_epi16(v92, v82), _mm_add_epi16(v91, v82));
    v16 += 2;
    v15 += 16;
    v95 = v61;
    v96 = _mm_unpacklo_epi16(v61, v69);
    v97 = _mm_unpacklo_epi16(v65, v67);
    v98 = v96;
    v99 = _mm_unpackhi_epi16(v95, v69);
    v100 = _mm_unpackhi_epi16(v65, v67);
    v101 = _mm_cmpgt_epi16(_mm_add_epi16(v87, v82), _mm_add_epi16(v88, v82));
    v102 = _mm_cmpgt_epi16(_mm_add_epi16(v97, v82), _mm_add_epi16(v100, v82));
    v103 = _mm_cmpgt_epi16(_mm_add_epi16(v96, v82), _mm_add_epi16(v99, v82));
    v104 = _mm_or_si128(_mm_andnot_si128(v101, v88), _mm_and_si128(v87, v101));
    v105 = _mm_andnot_si128(v103, v99);
    v106 = _mm_andnot_si128(v94, v91);
    v107 = _mm_load_si128(&UFG::gVmxConstI_Min_sh);
    v16[-2] = _mm_or_si128(_mm_and_si128(v86, v93), _mm_andnot_si128(v93, v90));
    v108 = _mm_or_si128(v106, _mm_and_si128(v92, v94));
    v109 = _mm_or_si128(_mm_andnot_si128(v102, v100), _mm_and_si128(v97, v102));
    v110 = _mm_cmpgt_epi16(_mm_add_epi16(v108, v107), _mm_add_epi16(v104, v107));
    v111 = _mm_or_si128(v105, _mm_and_si128(v98, v103));
    v112 = _mm_cmpgt_epi16(_mm_add_epi16(v109, v107), _mm_add_epi16(v111, v107));
    v113 = _mm_or_si128(_mm_andnot_si128(v112, v111), _mm_and_si128(v112, v109));
    v114 = _mm_or_si128(_mm_andnot_si128(v110, v104), _mm_and_si128(v110, v108));
    v115 = _mm_cmpgt_epi16(_mm_add_epi16(v114, v107), _mm_add_epi16(v113, v107));
    v16[-1] = _mm_or_si128(_mm_andnot_si128(v115, v113), _mm_and_si128(v114, v115));
    --v5;
  }
  while ( v5 );
}

// File Line: 500
// RVA: 0x1453D70
void Render::_dynamic_initializer_for__masks__()
{
  __m128i v0; // xmm5
  __m128i v1; // xmm4
  __m128i v2; // xmm3
  __m128i v3; // xmm2
  __m128i v4; // xmm1
  __m128i v5; // xmm6
  __m128i v6; // xmm7
  __m128i v7; // xmm8

  v0 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffff000000000000);
  v1 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffff0000000000000000);
  v2 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffff00000000000000000000);
  v3 = _mm_load_si128((const __m128i *)&_xmm_ffffffff000000000000000000000000);
  v4 = _mm_load_si128((const __m128i *)&_xmm_ffff0000000000000000000000000000);
  v5 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffff00000000);
  v6 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffff0000);
  v7 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  _mm_store_si128((__m128i *)&xmmword_142133D90, v6);
  _mm_store_si128((__m128i *)masks, v7);
  _mm_store_si128((__m128i *)&xmmword_142133D80, v7);
  _mm_store_si128((__m128i *)&xmmword_142133DA0, v7);
  _mm_store_si128((__m128i *)&xmmword_142133DC0, v7);
  _mm_store_si128((__m128i *)&xmmword_142133DE0, v7);
  _mm_store_si128((__m128i *)&xmmword_142133E00, v7);
  _mm_store_si128((__m128i *)&xmmword_142133E20, v7);
  _mm_store_si128((__m128i *)&xmmword_142133E40, v7);
  _mm_store_si128((__m128i *)&xmmword_142133E60, v7);
  _mm_store_si128((__m128i *)&xmmword_142133E80, v7);
  _mm_store_si128((__m128i *)&xmmword_142133DB0, v5);
  _mm_store_si128((__m128i *)&xmmword_142133EA0, v6);
  _mm_store_si128((__m128i *)&xmmword_142133EC0, v5);
  _mm_store_si128((__m128i *)&xmmword_142133DD0, v0);
  _mm_store_si128((__m128i *)&xmmword_142133DF0, v1);
  _mm_store_si128((__m128i *)&xmmword_142133E10, v2);
  _mm_store_si128((__m128i *)&xmmword_142133E30, v3);
  _mm_store_si128((__m128i *)&xmmword_142133E50, v4);
  _mm_store_si128((__m128i *)&xmmword_142133E70, (__m128i)0i64);
  _mm_store_si128((__m128i *)&xmmword_142133E90, (__m128i)0i64);
  _mm_store_si128((__m128i *)&xmmword_142133EB0, (__m128i)0i64);
  _mm_store_si128((__m128i *)&xmmword_142133ED0, (__m128i)0i64);
  _mm_store_si128((__m128i *)&xmmword_142133EE0, v0);
  _mm_store_si128((__m128i *)&xmmword_142133EF0, (__m128i)0i64);
  _mm_store_si128((__m128i *)&xmmword_142133F00, v1);
  _mm_store_si128((__m128i *)&xmmword_142133F10, (__m128i)0i64);
  _mm_store_si128((__m128i *)&xmmword_142133F20, v2);
  _mm_store_si128((__m128i *)&xmmword_142133F30, (__m128i)0i64);
  _mm_store_si128((__m128i *)&xmmword_142133F40, v3);
  _mm_store_si128((__m128i *)&xmmword_142133F50, (__m128i)0i64);
  _mm_store_si128((__m128i *)&xmmword_142133F60, v4);
  _mm_store_si128((__m128i *)&xmmword_142133F70, (__m128i)0i64);
  _mm_store_si128((__m128i *)&xmmword_142133F80, (__m128i)0i64);
}

// File Line: 520
// RVA: 0x25400
signed __int64 __fastcall Render::OcclusionMap::TestRect(Render::OcclusionMap *this, unsigned int minx, unsigned int miny, unsigned int maxx, unsigned int maxy, unsigned int minw)
{
  unsigned int v6; // er10
  Render::OcclusionMap *v7; // rdi
  signed __int64 result; // rax
  unsigned int v9; // er11
  __m128i v10; // xmm10
  unsigned int v11; // ebp
  unsigned int v12; // esi
  __int64 v13; // rax
  signed __int64 v14; // rcx
  __m128 v15; // xmm8
  __m128 v16; // xmm7
  __m128 v17; // xmm9
  __m128 v18; // xmm6
  __m128i v19; // xmm5
  int v20; // er8
  const __m128i *v21; // rdx
  __m128i v22; // xmm0
  const __m128i *v23; // r9
  signed __int64 v24; // r8
  __m128i v25; // xmm4
  __m128i v26; // xmm3
  __m128i v27; // xmm2
  __m128i v28; // xmm0
  __m128i v29; // xmm1

  v6 = miny;
  v7 = this;
  if ( minw <= 0x80 )
    return 1i64;
  v9 = maxy;
  if ( minx >= 0x7F )
    minx = 127;
  v10 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
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
  v16 = _mm_and_ps(_mm_xor_ps((__m128)masks[v13][0], (__m128)v10), (__m128)masks[v14][0]);
  v17 = _mm_and_ps(_mm_xor_ps((__m128)masks[v13][1], (__m128)v10), (__m128)masks[v14][1]);
  v18 = _mm_xor_ps((__m128)masks[(maxx & 7) + 1][0], (__m128)v10);
  if ( minx >> 3 == maxx >> 3 )
  {
    v16 = 0i64;
    v15 = _mm_and_ps(v15, v18);
    v18 = 0i64;
    v17 = 0i64;
  }
  v19 = _mm_load_si128(&UFG::gVmxConstI_Min_sh);
  v20 = 16 * v6 & 0x1FFFFFFF;
  v21 = (const __m128i *)((char *)v7->mOBuffer1 + 32 * v6);
  v22 = _mm_cvtsi32_si128((unsigned __int16)(minw - 128) | ((unsigned int)(unsigned __int16)(minw - 128) << 16));
  v23 = (const __m128i *)((char *)v7->mOBuffer0 + 16 * (v20 + v12));
  v24 = (char *)v7->mOBuffer0 + 16 * (v11 + v20) - (char *)v23;
  v25 = _mm_add_epi16(_mm_unpacklo_epi32(_mm_unpacklo_epi32(v22, v22), _mm_unpacklo_epi32(v22, v22)), v19);
  while ( 1 )
  {
    v26 = _mm_load_si128(v21);
    v27 = _mm_load_si128(v21 + 1);
    ++v6;
    v21 += 2;
    v28 = _mm_add_epi16(_mm_load_si128(v23), v19);
    v29 = _mm_add_epi16(_mm_load_si128((const __m128i *)((char *)v23 + v24)), v19);
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
                               v10));
    if ( (_DWORD)result )
      break;
    if ( v6 > v9 )
      return result;
  }
  return 1i64;
}

