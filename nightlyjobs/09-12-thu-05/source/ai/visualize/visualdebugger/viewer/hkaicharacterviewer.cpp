// File Line: 31
// RVA: 0xC40780
void hkaiCharacterViewer::registerViewer(void)
{
  hkaiCharacterViewer::m_tag = hkProcessFactory::registerProcess(
                                 hkSingleton<hkProcessFactory>::s_instance,
                                 "AI - Characters",
                                 hkaiCharacterViewer::create);
}

// File Line: 36
// RVA: 0xC407B0
hkProcess *__fastcall hkaiCharacterViewer::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkaiCharacterViewer *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiCharacterViewer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 112i64);
  if ( v3 && (hkaiCharacterViewer::hkaiCharacterViewer(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 43
// RVA: 0xC416B0
void __fastcall hkaiCharacterViewer::hkaiCharacterViewer(hkaiCharacterViewer *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiCharacterViewer *v2; // rbx

  v2 = this;
  hkaiViewerBase::hkaiViewerBase((hkaiViewerBase *)&this->vfptr, contexts);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiCharacterViewer::`vftable{for `hkReferencedObject};
  v2->vfptr = (hkProcessVtbl *)&hkaiCharacterViewer::`vftable{for `hkProcess};
  v2->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiCharacterViewer::`vftable{for `hkaiViewerContextWorldListener};
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiCharacterViewer::`vftable;
  v2->m_colors.m_capacityAndFlags = 2147483648;
  v2->m_colors.m_data = 0i64;
  v2->m_colors.m_size = 0;
  v2->m_rand.m_seed = 1147777595;
  v2->m_rand.m_current = 1147777595;
}

// File Line: 49
// RVA: 0xC40810
void __fastcall hkaiCharacterViewer::init(hkaiCharacterViewer *this)
{
  hkProcessHandler *v1; // rax
  int v2; // ebx
  hkaiCharacterViewer *v3; // rsi
  __int64 v4; // rdi

  v1 = this->m_processHandler;
  v2 = 0;
  v3 = this;
  if ( v1 )
  {
    v4 = 0i64;
    do
    {
      if ( v2 >= SLODWORD(v1[22].vfptr) )
        break;
      ((void (__fastcall *)(hkDebugDisplayHandler **, _QWORD))v3->m_displayHandler[1].vfptr)(
        &v3->m_displayHandler,
        *(void *(__fastcall **)(hkProcessHandler *, unsigned int))((char *)&v1[21].vfptr->__vecDelDtor + v4));
      v1 = v3->m_processHandler;
      ++v2;
      v4 += 8i64;
    }
    while ( v1 );
  }
}

// File Line: 57
// RVA: 0xC41720
void __fastcall hkaiCharacterViewer::~hkaiCharacterViewer(hkaiCharacterViewer *this)
{
  int v1; // edi
  hkaiCharacterViewer *v2; // rbx
  __int64 v3; // rsi
  hkaiViewerContext *v4; // rdx
  int v5; // er8

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiCharacterViewer::`vftable{for `hkReferencedObject};
  this->vfptr = (hkProcessVtbl *)&hkaiCharacterViewer::`vftable{for `hkProcess};
  v2 = this;
  this->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiCharacterViewer::`vftable{for `hkaiViewerContextWorldListener};
  this->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiCharacterViewer::`vftable;
  if ( this->m_context.m_pntr )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_context.m_pntr;
      if ( v1 >= v4->m_worlds.m_size )
        break;
      hkaiCharacterViewer::worldRemovedCallback((hkaiCharacterViewer *)((char *)v2 + 64), v4->m_worlds.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v2->m_context.m_pntr );
  }
  v5 = v2->m_colors.m_capacityAndFlags;
  v2->m_colors.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_colors.m_data,
      4 * v5);
  v2->m_colors.m_data = 0i64;
  v2->m_colors.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkaiWorld::ListenerVtbl *)&hkaiWorld::Listener::`vftable;
  hkaiViewerBase::~hkaiViewerBase((hkaiViewerBase *)&v2->vfptr);
}

// File Line: 65
// RVA: 0xC41650
void __fastcall hkaiCharacterViewer::worldAddedCallback(hkaiCharacterViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiCharacterViewer *)64 )
    hkaiWorld::addListener(w, 0i64);
  else
    hkaiWorld::addListener(w, (hkaiWorld::Listener *)&this->vfptr);
}

// File Line: 70
// RVA: 0xC41680
void __fastcall hkaiCharacterViewer::worldRemovedCallback(hkaiCharacterViewer *this, hkaiWorld *w)
{
  if ( this == (hkaiCharacterViewer *)64 )
    hkaiWorld::removeListener(w, 0i64);
  else
    hkaiWorld::removeListener(w, (hkaiWorld::Listener *)&this->vfptr);
}

// File Line: 76
// RVA: 0xC40A00
void __fastcall hkaiCharacterViewer::postStepCallback(hkaiCharacterViewer *this, hkaiWorld *world, hkArrayBase<hkaiBehavior *> *behaviors)
{
  hkPseudoRandomGenerator *v3; // r14
  hkArrayBase<hkaiBehavior *> *v4; // r15
  _QWORD *v5; // rax
  __int64 v6; // r8
  const char *v7; // rdx
  unsigned __int64 v8; // rcx
  _QWORD *v9; // r9
  unsigned __int64 v10; // rax
  int v11; // edi
  __int64 v12; // r13
  __int64 v13; // r12
  __int64 v14; // rbx
  unsigned int v15; // esi
  __m128 v16; // xmm10
  __m128 v17; // xmm9
  __m128 v18; // xmm11
  hkPseudoRandomGenerator *v19; // r12
  __m128 v20; // xmm8
  __m128i v21; // xmm12
  __int64 v22; // rdi
  __m128 v23; // xmm7
  __m128 v24; // xmm6
  __m128 v25; // xmm5
  __m128 v26; // xmm6
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm14
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm14
  __m128 v35; // xmm15
  __m128 v36; // xmm15
  unsigned int v37; // ebx
  hkPseudoRandomGenerator v38; // rcx
  unsigned int v39; // er13
  __m128 v40; // xmm10
  __m128 v41; // xmm0
  const char *v42; // rdx
  unsigned __int8 v43; // cl
  unsigned __int64 v44; // rdx
  _QWORD *v45; // r8
  _QWORD *v46; // rcx
  unsigned __int64 v47; // rax
  signed __int64 v48; // rcx
  __m128 v49; // xmm11
  signed int v50; // er15
  __m128 v51; // xmm2
  __m128 v52; // xmm13
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm12
  __m128i v56; // xmm6
  __int64 *v57; // rax
  __m128 v58; // xmm9
  __m128i v59; // xmm8
  __m128 v60; // xmm9
  __m128 v61; // xmm3
  __m128i v62; // xmm6
  __m128 v63; // xmm2
  __m128 v64; // xmm5
  __m128 v65; // xmm4
  __m128 v66; // xmm2
  __m128 v67; // xmm3
  __int64 v68; // rbx
  int v69; // eax
  int v70; // eax
  _QWORD *v71; // r8
  _QWORD *v72; // rcx
  unsigned __int64 v73; // rax
  signed __int64 v74; // rcx
  float v75; // xmm0_4
  float v76; // xmm5_4
  unsigned int v77; // ST40_4
  __m128 v78; // xmm2
  __m128 v79; // xmm4
  signed int v80; // er15
  __m128 v81; // xmm5
  signed int v82; // ebx
  __m128 i; // xmm7
  __m128 v84; // xmm1
  __m128 v85; // xmm3
  __m128 v86; // xmm4
  __m128 v87; // xmm0
  __m128 v88; // xmm5
  __m128 v89; // xmm6
  __m128 v90; // xmm6
  __m128 v91; // xmm1
  __m128 v92; // xmm3
  __m128 v93; // xmm2
  __m128 v94; // xmm6
  __m128 v95; // xmm1
  _QWORD *v96; // r8
  _QWORD *v97; // rcx
  unsigned __int64 v98; // rax
  signed __int64 v99; // rcx
  hkaiBehavior **v100; // rax
  signed int v101; // esi
  signed __int64 v102; // rdi
  __int64 *v103; // rax
  __int64 v104; // rbx
  __int64 v105; // rax
  _QWORD *v106; // rax
  _QWORD *v107; // rcx
  _QWORD *v108; // r8
  unsigned __int64 v109; // rax
  signed __int64 v110; // rcx
  __int64 id; // [rsp+20h] [rbp-D8h]
  __int64 ida; // [rsp+20h] [rbp-D8h]
  __int64 tag; // [rsp+28h] [rbp-D0h]
  __int64 v114[2]; // [rsp+30h] [rbp-C8h]
  unsigned int v115; // [rsp+48h] [rbp-B0h]
  signed int v116; // [rsp+4Ch] [rbp-ACh]
  char *v117; // [rsp+50h] [rbp-A8h]
  int v118; // [rsp+58h] [rbp-A0h]
  int v119; // [rsp+5Ch] [rbp-9Ch]
  __int64 v120; // [rsp+60h] [rbp-98h]
  __int64 v121; // [rsp+68h] [rbp-90h]
  void *v122; // [rsp+70h] [rbp-88h]
  int v123; // [rsp+78h] [rbp-80h]
  int v124; // [rsp+7Ch] [rbp-7Ch]
  __int64 v125; // [rsp+80h] [rbp-78h]
  hkVector4f v126; // [rsp+88h] [rbp-70h]
  char v127; // [rsp+98h] [rbp-60h]
  char v128; // [rsp+9Ch] [rbp-5Ch]
  hkVector4f from; // [rsp+A8h] [rbp-50h]
  __m128 v130; // [rsp+B8h] [rbp-40h]
  hkVector4f axis; // [rsp+C8h] [rbp-30h]
  __m128 v132; // [rsp+D8h] [rbp-20h]
  hkVector4f start; // [rsp+E8h] [rbp-10h]
  __int128 v134; // [rsp+F8h] [rbp+0h]
  hkVector4f v135; // [rsp+108h] [rbp+10h]
  hkVector4f end; // [rsp+118h] [rbp+20h]
  hkVector4f dir; // [rsp+128h] [rbp+30h]
  __m128 v138; // [rsp+138h] [rbp+40h]
  __m128 v139; // [rsp+148h] [rbp+50h]
  __m128 v140; // [rsp+158h] [rbp+60h]
  hkQuaternionf v141; // [rsp+168h] [rbp+70h]
  hkStringBuf v142; // [rsp+178h] [rbp+80h]
  hkArrayBase<hkaiBehavior *> *v143; // [rsp+2F8h] [rbp+200h]
  unsigned int v144; // [rsp+300h] [rbp+208h]

  v3 = (hkPseudoRandomGenerator *)this;
  v4 = behaviors;
  v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = "Stcircle";
  v8 = v5[1];
  v9 = v5;
  if ( v8 < v5[3] )
  {
    *(_QWORD *)(v8 + 16) = "Stcircle";
    *(_QWORD *)v8 = "LtCharacterViewer";
    v10 = __rdtsc();
    v7 = (const char *)((unsigned __int64)HIDWORD(v10) << 32);
    *(_DWORD *)(v8 + 8) = v10;
    v9[1] = v8 + 24;
  }
  v11 = 0;
  v12 = 0i64;
  v116 = 0;
  v115 = 0;
  v125 = 0i64;
  if ( v4->m_size > 0 )
  {
    v13 = 0i64;
    v14 = 0i64;
    v121 = 0i64;
    v120 = 0i64;
    do
    {
      v15 = 0;
      v144 = 0;
      if ( (*(signed int (__fastcall **)(_QWORD, const char *, __int64, _QWORD *))(**(_QWORD **)((char *)v4->m_data + v14)
                                                                                 + 96i64))(
             *(hkaiBehavior **)((char *)v4->m_data + v14),
             v7,
             v6,
             v9) > 0 )
      {
        v16 = (__m128)_xmm;
        v17 = (__m128)_xmm;
        v18 = *(__m128 *)_xmm;
        v19 = v3 + 1;
        v20 = 0i64;
        v21 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
        _mm_store_si128((__m128i *)&v134, v21);
        do
        {
          v22 = (*(__int64 (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)((char *)v4->m_data + v14) + 104i64))(
                  *(hkaiBehavior **)((char *)v4->m_data + v14),
                  v15);
          v23 = *(__m128 *)(v22 + 80);
          axis.m_quad = v23;
          v24 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v20), 196);
          v25 = _mm_shuffle_ps(v24, v24, 241);
          v26 = _mm_shuffle_ps(v24, v24, 206);
          v27 = _mm_mul_ps(v26, v26);
          v28 = _mm_mul_ps(v25, v25);
          v29 = _mm_cmpltps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                    _mm_shuffle_ps(v28, v28, 170)),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                    _mm_shuffle_ps(v27, v27, 170)));
          v30 = _mm_xor_ps(_mm_or_ps(_mm_andnot_ps(v29, v25), _mm_and_ps(v29, v26)), (__m128)v21);
          v31 = _mm_mul_ps(v30, v30);
          v32 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                  _mm_shuffle_ps(v31, v31, 170));
          v33 = _mm_rsqrt_ps(v32);
          v34 = _mm_mul_ps(
                  v30,
                  _mm_andnot_ps(
                    _mm_cmpleps(v32, v20),
                    _mm_mul_ps(_mm_sub_ps(v17, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)), _mm_mul_ps(v18, v33))));
          v35 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v23),
                  _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v34));
          v36 = _mm_shuffle_ps(v35, v35, 201);
          if ( (signed int)v3[2].m_seed <= v116 )
          {
            v37 = hkColor::getRandomColor(v3 + 3);
            if ( v19[1].m_seed == (v19[1].m_current & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v19, 4);
            *(_DWORD *)(*(_QWORD *)v19 + 4i64 * (signed int)v19[1].m_seed++) = v37;
            v14 = v120;
            v23 = axis.m_quad;
          }
          v38 = *v19;
          v39 = *(_DWORD *)(*(_QWORD *)v19 + 4 * v12);
          v40 = _mm_mul_ps(v16, v23);
          v41 = _mm_add_ps(*(__m128 *)(v22 + 32), v40);
          v139 = v40;
          v126.m_quad = v41;
          if ( hkaiCharacterViewer::m_displayCharacterId.m_bool )
          {
            from.m_quad = _mm_add_ps(_mm_mul_ps((__m128)_xmm, v23), *(__m128 *)(v22 + 32));
            dir.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(v21, 0), v23);
            hkDebugDisplay::displayArrow(
              hkSingleton<hkDebugDisplay>::s_instance,
              &from,
              &dir,
              *(_DWORD *)(*(_QWORD *)&v38 + v121),
              0,
              (int)hkDebugDisplayProcess::m_tag);
            v142.m_string.m_capacityAndFlags = -2147483520;
            v142.m_string.m_size = 1;
            v142.m_string.m_storage[0] = 0;
            v124 = 2147483648;
            v142.m_string.m_data = v142.m_string.m_storage;
            v122 = 0i64;
            v123 = 0;
            (*(void (__fastcall **)(_QWORD, _QWORD, void **))(**(_QWORD **)((char *)v4->m_data + v14) + 40i64))(
              *(hkaiBehavior **)((char *)v4->m_data + v14),
              v15,
              &v122);
            v42 = "%d -?-";
            if ( v123 > 1 )
              v42 = "%d";
            hkStringBuf::printf(&v142, v42, v115);
            v43 = *(_BYTE *)(v22 + 170);
            if ( v43 & 7 )
            {
              LODWORD(ida) = *(unsigned __int16 *)(v22 + 168);
              hkStringBuf::appendPrintf(&v142, "%x : {%d} (%d)", v43, *(unsigned int *)(v22 + 164), ida);
            }
            else
            {
              hkStringBuf::appendPrintf(
                &v142,
                "OFF : {%d} (%d)",
                *(unsigned int *)(v22 + 164),
                *(unsigned __int16 *)(v22 + 168));
            }
            hkDebugDisplay::display3dText(
              hkSingleton<hkDebugDisplay>::s_instance,
              v142.m_string.m_data,
              &from,
              *(_DWORD *)(*(_QWORD *)v19 + v121),
              0,
              (int)hkDebugDisplayProcess::m_tag);
            v123 = 0;
            if ( v124 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                v122,
                16 * v124);
            v122 = 0i64;
            v124 = 2147483648;
            v142.m_string.m_size = 0;
            if ( v142.m_string.m_capacityAndFlags >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                v142.m_string.m_data,
                v142.m_string.m_capacityAndFlags & 0x3FFFFFFF);
          }
          if ( hkaiCharacterViewer::m_displayPosAndRadius.m_bool )
          {
            v45 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v46 = (_QWORD *)v45[1];
            if ( (unsigned __int64)v46 < v45[3] )
            {
              *v46 = "Stcircle";
              v47 = __rdtsc();
              v44 = (unsigned __int64)HIDWORD(v47) << 32;
              v48 = (signed __int64)(v46 + 2);
              *(_DWORD *)(v48 - 8) = v47;
              v45[1] = v48;
            }
            v49 = v126.m_quad;
            v50 = 1;
            v51 = 0i64;
            v51.m128_f32[0] = (float)16;
            v52 = _mm_shuffle_ps((__m128)*(unsigned int *)(v22 + 100), (__m128)*(unsigned int *)(v22 + 100), 0);
            v53 = _mm_shuffle_ps(v51, v51, 0);
            v54 = _mm_rcp_ps(v53);
            v130 = _mm_add_ps(_mm_mul_ps(v52, v34), v126.m_quad);
            v55 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v54, v53)), v54), (__m128)xmmword_141A713F0);
            while ( 1 )
            {
              v56 = _mm_load_si128((const __m128i *)_xmm);
              v23 = *(__m128 *)_xmm;
              v57 = (__int64 *)v3[-4];
              v58 = 0i64;
              v58.m128_f32[0] = (float)v50;
              v59 = _mm_add_epi32(v56, v56);
              v60 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v58, v58, 0), v55), *(__m128 *)offset_1);
              v61 = _mm_andnot_ps(*(__m128 *)_xmm, v60);
              v62 = _mm_andnot_si128(v56, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v61, *(__m128 *)_xmm)), v56));
              v63 = _mm_cvtepi32_ps(v62);
              v64 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v62, v59), (__m128i)0i64);
              v65 = _mm_add_ps(
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v63, *(__m128 *)DP1_0), v61), _mm_mul_ps(*(__m128 *)DP2, v63)),
                      _mm_mul_ps(*(__m128 *)DP3, v63));
              v66 = _mm_mul_ps(v65, v65);
              v67 = _mm_xor_ps(
                      _mm_or_ps(
                        _mm_andnot_ps(
                          v64,
                          _mm_add_ps(
                            _mm_sub_ps(
                              _mm_mul_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_add_ps(_mm_mul_ps(*(__m128 *)cosCoeff0_0, v66), *(__m128 *)cosCoeff1),
                                      v66),
                                    *(__m128 *)cosCoeff2_0),
                                  v66),
                                v66),
                              _mm_mul_ps(*(__m128 *)_xmm, v66)),
                            *(__m128 *)_xmm)),
                        _mm_and_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_add_ps(_mm_mul_ps(*(__m128 *)sinCoeff0, v66), *(__m128 *)sinCoeff1_0),
                                    v66),
                                  *(__m128 *)sinCoeff2_0),
                                v66),
                              v65),
                            v65),
                          v64)),
                      _mm_xor_ps(
                        (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v59, v59), v62), 0x1Du),
                        _mm_and_ps(v60, *(__m128 *)_xmm)));
              v132 = _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v67, v67, 85), v52), v34), v49),
                       _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v67, v67, 0), v52), v36));
              v68 = *v57;
              LODWORD(v114[0]) = (*(__int64 (__fastcall **)(hkPseudoRandomGenerator *, unsigned __int64, _QWORD *))(*(_QWORD *)&v3[-8] + 8i64))(
                                   v3 - 8,
                                   v44,
                                   v45);
              LODWORD(tag) = 0;
              LODWORD(id) = v39;
              (*(void (__fastcall **)(_QWORD, char *, __m128 *, __m128 *, __int64, __int64, __int64))(v68 + 128))(
                *(_QWORD *)&v3[-4],
                &v128,
                &v130,
                &v132,
                id,
                tag,
                v114[0]);
              ++v50;
              v130 = v132;
              if ( v50 > 16 )
                break;
              v49 = v126.m_quad;
            }
            v40 = v139;
            v17 = (__m128)_xmm;
            v18 = *(__m128 *)_xmm;
            v20 = 0i64;
            v19 = v3 + 1;
            v21 = _mm_load_si128((const __m128i *)&v134);
          }
          if ( hkaiCharacterViewer::m_displayForwardDirection.m_bool && *(_BYTE *)(*(_QWORD *)(v22 + 152) + 48i64) == 1 )
          {
            v69 = (*(__int64 (__fastcall **)(hkPseudoRandomGenerator *))(*(_QWORD *)&v3[-8] + 8i64))(v3 - 8);
            hkDebugDisplayHandler::displayArrow(
              *(hkDebugDisplayHandler **)&v3[-4],
              &v126,
              (hkVector4f *)(v22 + 48),
              v39,
              0,
              v69);
          }
          if ( hkaiCharacterViewer::m_displayLinearVelocity.m_bool )
          {
            v70 = (*(__int64 (__fastcall **)(hkPseudoRandomGenerator *))(*(_QWORD *)&v3[-8] + 8i64))(v3 - 8);
            hkDebugDisplayHandler::displayArrow(
              *(hkDebugDisplayHandler **)&v3[-4],
              &v126,
              (hkVector4f *)(v22 + 64),
              hkColor::HOTPINK,
              0,
              v70);
          }
          if ( hkaiCharacterViewer::m_displayAngularVelocity.m_bool && *(_BYTE *)(*(_QWORD *)(v22 + 152) + 48i64) == 1 )
          {
            v71 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v72 = (_QWORD *)v71[1];
            if ( (unsigned __int64)v72 < v71[3] )
            {
              *v72 = "StangVelArc";
              v73 = __rdtsc();
              v74 = (signed __int64)(v72 + 2);
              *(_DWORD *)(v74 - 8) = v73;
              v71[1] = v74;
            }
            v75 = *(float *)(v22 + 76);
            v123 = 1086918619;
            v76 = fminf(v75 * 0.25, 6.2831855);
            if ( v76 > 0.00000011920929 )
            {
              *(float *)&v77 = (float)(v76 * 16.0) * 0.15915494;
              v78 = _mm_sub_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_sub_ps((__m128)v77, *(__m128 *)two23), *(__m128 *)two23),
                        *(__m128 *)two23),
                      *(__m128 *)two23);
              v79 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v77, 1u), 1u));
              v80 = (signed int)(float)(COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                                              v79,
                                                                              _mm_add_ps(
                                                                                _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v77, v78)),
                                                                                v78)) | v79.m128_i32[0] & v77)
                                      + 1.0);
              hkQuaternionf::setAxisAngle(&v141, &axis, v76 / (float)v80);
              v81 = *(__m128 *)(v22 + 48);
              v82 = 1;
              v23.m128_f32[0] = *(float *)(v22 + 100) * 0.89999998;
              for ( i = _mm_shuffle_ps(v23, v23, 0); v82 <= v80; v81 = v94 )
              {
                v84 = _mm_mul_ps(v141.m_vec.m_quad, v81);
                v85 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v81, v81, 201), v141.m_vec.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v141.m_vec.m_quad, v141.m_vec.m_quad, 201), v81));
                v86 = _mm_shuffle_ps(v141.m_vec.m_quad, v141.m_vec.m_quad, 255);
                v87 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v86, v86), (__m128)xmmword_141A711B0), v81);
                v88 = _mm_add_ps(_mm_mul_ps(v81, i), v126.m_quad);
                start.m_quad = v88;
                v89 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
                              _mm_shuffle_ps(v84, v84, 170)),
                            v141.m_vec.m_quad),
                          v87),
                        _mm_mul_ps(_mm_shuffle_ps(v85, v85, 201), v86));
                v90 = _mm_add_ps(v89, v89);
                v91 = _mm_mul_ps(v90, v90);
                v92 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v91, v91, 85), _mm_shuffle_ps(v91, v91, 0)),
                        _mm_shuffle_ps(v91, v91, 170));
                v93 = _mm_rsqrt_ps(v92);
                v94 = _mm_mul_ps(
                        v90,
                        _mm_andnot_ps(
                          _mm_cmpleps(v92, v20),
                          _mm_mul_ps(_mm_sub_ps(v17, _mm_mul_ps(_mm_mul_ps(v93, v92), v93)), _mm_mul_ps(v18, v93))));
                v95 = _mm_add_ps(_mm_mul_ps(v94, i), v126.m_quad);
                end.m_quad = v95;
                if ( v82 == v80 )
                {
                  v135.m_quad = _mm_sub_ps(v95, v88);
                  hkDebugDisplay::displayArrow(
                    hkSingleton<hkDebugDisplay>::s_instance,
                    &start,
                    &v135,
                    hkColor::HOTPINK,
                    0,
                    (int)hkDebugDisplayProcess::m_tag);
                }
                else
                {
                  hkDebugDisplay::displayLine(
                    hkSingleton<hkDebugDisplay>::s_instance,
                    &start,
                    &end,
                    hkColor::HOTPINK,
                    0,
                    (int)hkDebugDisplayProcess::m_tag);
                }
                ++v82;
              }
            }
            v15 = v144;
          }
          if ( hkaiCharacterViewer::m_displayPath.m_bool )
          {
            v96 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
            v97 = (_QWORD *)v96[1];
            if ( (unsigned __int64)v97 < v96[3] )
            {
              *v97 = "Stpath";
              v98 = __rdtsc();
              v99 = (signed __int64)(v97 + 2);
              *(_DWORD *)(v99 - 8) = v98;
              v96[1] = v99;
            }
            v119 = 2147483648;
            v100 = v143->m_data;
            v117 = 0i64;
            v118 = 0;
            ((void (__fastcall *)(_QWORD, _QWORD, char **))(*(hkaiBehavior **)((char *)v100 + v120))->vfptr[2].__first_virtual_table_function__)(
              *(hkaiBehavior **)((char *)v100 + v120),
              v15,
              &v117);
            if ( *(_DWORD *)(v22 + 172) != 3 )
            {
              v101 = 1;
              if ( v118 > 1 )
              {
                v102 = 16i64;
                do
                {
                  v140 = _mm_add_ps(*(__m128 *)&v117[v102 - 16], v40);
                  v103 = (__int64 *)v3[-4];
                  v138 = _mm_add_ps(*(__m128 *)&v117[v102], v40);
                  v104 = *v103;
                  LODWORD(v114[0]) = (*(__int64 (__fastcall **)(hkPseudoRandomGenerator *))(*(_QWORD *)&v3[-8] + 8i64))(v3 - 8);
                  LODWORD(tag) = 0;
                  LODWORD(id) = v39;
                  (*(void (__fastcall **)(_QWORD, char *, __m128 *, __m128 *, __int64, __int64, __int64))(v104 + 128))(
                    *(_QWORD *)&v3[-4],
                    &v127,
                    &v140,
                    &v138,
                    id,
                    tag,
                    v114[0]);
                  ++v101;
                  v102 += 16i64;
                }
                while ( v101 < v118 );
              }
              v15 = v144;
            }
            v118 = 0;
            if ( v119 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                v117,
                16 * v119);
            v117 = 0i64;
            v119 = 2147483648;
          }
          v4 = v143;
          v14 = v120;
          ++v116;
          ++v15;
          v12 = v125 + 1;
          v144 = v15;
          v105 = **(_QWORD **)((char *)v143->m_data + v120);
          ++v125;
          v16 = (__m128)_xmm;
        }
        while ( (signed int)v15 < (*(signed int (**)(void))(v105 + 96))() );
        v11 = v115;
        v13 = v121;
      }
      ++v11;
      v14 += 8i64;
      v13 += 4i64;
      v115 = v11;
      v120 = v14;
      v121 = v13;
    }
    while ( v11 < v4->m_size );
  }
  v106 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v107 = (_QWORD *)v106[1];
  v108 = v106;
  if ( (unsigned __int64)v107 < v106[3] )
  {
    *v107 = "lt";
    v109 = __rdtsc();
    v110 = (signed __int64)(v107 + 2);
    *(_DWORD *)(v110 - 8) = v109;
    v108[1] = v110;
  }
}

// File Line: 257
// RVA: 0xC40880
void __fastcall hkaiCharacterViewer::preCharacterStepCallback(hkaiCharacterViewer *this, hkaiWorld::CharacterStepCallbackContext *ctx)
{
  hkaiCharacterViewer *v2; // rsi
  hkaiWorld::CharacterStepCallbackContext *v3; // rdi
  hkArrayBase<hkaiLocalSteeringInput> *v4; // rdi
  int v5; // ebp
  __int64 v6; // r14
  hkVector4f *v7; // rbx
  hkDebugDisplayHandler *v8; // rax
  int tag; // eax
  hkVector4f from; // [rsp+30h] [rbp-88h]
  hkaiWorld::CharacterStepSerializableContext v11; // [rsp+40h] [rbp-78h]

  v2 = this;
  v3 = ctx;
  hkaiWorld::CharacterStepSerializableContext::CharacterStepSerializableContext(&v11, ctx);
  hkRemoteObjectProcess::sendObject(
    (hkDisplaySerializeOStream *)v2[-1].m_context.m_pntr,
    (hkReferencedObject *)&v11.vfptr,
    SEND_OBJECT_TAGFILE);
  if ( hkaiCharacterViewer::m_displayDesiredVelocity.m_bool )
  {
    v4 = v3->m_localSteeringInputs;
    if ( v4 )
    {
      v5 = 0;
      if ( v4->m_size > 0 )
      {
        v6 = 0i64;
        do
        {
          v7 = (hkVector4f *)v4->m_data[v6].m_character;
          v8 = v2[-1].m_displayHandler;
          from.m_quad = _mm_add_ps(v7[2].m_quad, _mm_mul_ps((__m128)_xmm, v7[5].m_quad));
          tag = ((__int64 (__fastcall *)(hkDebugDisplayHandler **))v8[1].vfptr)(&v2[-1].m_displayHandler);
          hkDebugDisplayHandler::displayArrow(
            (hkDebugDisplayHandler *)v2[-1].vfptr,
            &from,
            v7 + 4,
            hkColor::CYAN,
            0,
            tag);
          ++v5;
          ++v6;
        }
        while ( v5 < v4->m_size );
      }
    }
  }
  hkaiWorld::CharacterStepSerializableContext::~CharacterStepSerializableContext(&v11);
}

// File Line: 282
// RVA: 0xC409C0
void __fastcall hkaiCharacterViewer::postCharacterStepCallback(hkaiCharacterViewer *this, hkaiWorld::CharacterStepCallbackContext *ctx)
{
  hkaiCharacterViewer *v2; // rbx
  hkaiWorld::CharacterStepSerializableContext v3; // [rsp+20h] [rbp-58h]

  v2 = this;
  hkaiWorld::CharacterStepSerializableContext::CharacterStepSerializableContext(&v3, ctx);
  hkRemoteObjectProcess::sendObject(
    (hkDisplaySerializeOStream *)v2[-1].m_context.m_pntr,
    (hkReferencedObject *)&v3.vfptr,
    SEND_OBJECT_TAGFILE);
  hkaiWorld::CharacterStepSerializableContext::~CharacterStepSerializableContext(&v3);
}

