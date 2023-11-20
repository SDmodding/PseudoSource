// File Line: 100
// RVA: 0xD30C40
__int64 __fastcall hkCpuShapeRayCastJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v2; // rbx
  hkJobQueue::JobQueueEntry *v3; // rsi
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  int v8; // ecx
  __int64 v9; // rbx
  __int64 v10; // rdi
  int v11; // er12
  int v12; // eax
  __int64 v13; // r14
  __m128 v14; // xmm1
  __int128 v15; // xmm0
  int v16; // eax
  __int128 v17; // xmm1
  __int64 v18; // r15
  unsigned __int64 v19; // rsi
  __int64 *v20; // rcx
  bool v21; // zf
  __m128 *v22; // r13
  __m128 v23; // xmm6
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  __m128 v30; // xmm5
  __m128 v31; // xmm6
  __m128 v32; // xmm6
  __m128 v33; // xmm4
  __m128 v34; // xmm1
  __m128 v35; // xmm5
  __m128 v36; // xmm2
  __int64 v37; // rax
  signed int v38; // eax
  __m128 *v39; // rcx
  signed __int64 v40; // rdx
  __int64 v41; // r8
  int v42; // eax
  _QWORD *v43; // r8
  _QWORD *v44; // rcx
  unsigned __int64 v45; // rax
  signed __int64 v46; // rcx
  __m128 v48; // [rsp+20h] [rbp-E0h]
  float v49; // [rsp+30h] [rbp-D0h]
  int v50; // [rsp+34h] [rbp-CCh]
  int v51; // [rsp+38h] [rbp-C8h]
  int v52; // [rsp+3Ch] [rbp-C4h]
  int v53; // [rsp+40h] [rbp-C0h]
  int v54; // [rsp+44h] [rbp-BCh]
  int v55; // [rsp+48h] [rbp-B8h]
  int v56; // [rsp+4Ch] [rbp-B4h]
  int v57; // [rsp+50h] [rbp-B0h]
  int v58; // [rsp+54h] [rbp-ACh]
  int v59; // [rsp+58h] [rbp-A8h]
  int v60; // [rsp+5Ch] [rbp-A4h]
  int v61; // [rsp+60h] [rbp-A0h]
  __int64 v62; // [rsp+70h] [rbp-90h]
  void **v63; // [rsp+80h] [rbp-80h]
  int v64; // [rsp+88h] [rbp-78h]
  __int64 v65; // [rsp+90h] [rbp-70h]
  __int64 v66; // [rsp+98h] [rbp-68h]
  int v67; // [rsp+A0h] [rbp-60h]
  int v68; // [rsp+A4h] [rbp-5Ch]
  __int64 v69; // [rsp+A8h] [rbp-58h]
  __m128 v70; // [rsp+B0h] [rbp-50h]
  __m128 v71; // [rsp+C0h] [rbp-40h]
  __int128 v72; // [rsp+D0h] [rbp-30h]
  __int128 v73; // [rsp+E0h] [rbp-20h]
  hkJobQueue *v74; // [rsp+150h] [rbp+50h]
  hkJobQueue::JobQueueEntry *v75; // [rsp+158h] [rbp+58h]
  char v76; // [rsp+160h] [rbp+60h]
  int v77; // [rsp+168h] [rbp+68h]

  v75 = nextJobOut;
  v74 = jobQueue;
  v2 = jobQueue;
  v3 = nextJobOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtCollQueryShapeRayCast";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = 0;
  v77 = 0;
  if ( *(_DWORD *)&v3->m_data[48] > 0 )
  {
    v9 = 0i64;
    while ( 1 )
    {
      v10 = *(_QWORD *)&v3->m_data[40];
      v11 = 0;
      v49 = 1.0;
      v12 = *(_DWORD *)(v9 + v10 + 96);
      v13 = *(_QWORD *)(v9 + v10 + 88);
      v50 = -1;
      v14 = *(__m128 *)(v9 + v10 + 16);
      v70 = *(__m128 *)(v9 + v10);
      v15 = *(_OWORD *)(v9 + v10 + 32);
      v71 = v14;
      v67 = v12;
      v16 = 0;
      v61 = 0;
      v17 = *(_OWORD *)(v9 + v10 + 48);
      v72 = v15;
      g_FixedBufferRayHitCollectorAddRayHitCallbackFunc = hkpFixedBufferRayHitCollector::addRayHitImplementation;
      v53 = -1;
      v62 = 0i64;
      v73 = v17;
      v64 = 1065353216;
      v63 = &hkpFixedBufferRayHitCollector::`vftable';
      v65 = v13;
      v66 = v13;
      v68 = 0;
      v69 = 0i64;
      if ( *(_DWORD *)(v9 + v10 + 80) <= 0 )
        goto LABEL_23;
      v18 = 0i64;
      do
      {
        v19 = *(_QWORD *)(v18 + *(_QWORD *)(v9 + v10 + 72));
        v20 = *(__int64 **)v19;
        if ( !*(_QWORD *)v19 )
          goto LABEL_21;
        v21 = *(_BYTE *)(v9 + v10 + 104) == 0;
        v22 = *(__m128 **)(v19 + 16);
        v23 = _mm_sub_ps(*(__m128 *)(v9 + v10 + 16), v22[3]);
        v24 = v22[2];
        v25 = _mm_unpacklo_ps(*v22, v22[1]);
        v26 = _mm_shuffle_ps(v23, v23, 85);
        v27 = _mm_movelh_ps(v25, v24);
        v28 = _mm_movehl_ps(v27, v25);
        v29 = _mm_shuffle_ps(v23, v23, 0);
        v30 = _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(*v22, v22[1]), v24, 228), _mm_shuffle_ps(v23, v23, 170));
        v31 = *(__m128 *)(v9 + v10);
        v71 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v24, 212), v26), _mm_mul_ps(v29, v27)), v30);
        v32 = _mm_sub_ps(v31, v22[3]);
        v33 = v22[2];
        v34 = _mm_unpacklo_ps(*v22, v22[1]);
        v35 = _mm_shuffle_ps(_mm_unpackhi_ps(*v22, v22[1]), v33, 228);
        v62 = 0i64;
        v49 = 1.0;
        v50 = -1;
        v61 = 0;
        v53 = -1;
        v36 = _mm_movelh_ps(v34, v33);
        v70 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v36, v34), v33, 212), _mm_shuffle_ps(v32, v32, 85)),
                  _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v36)),
                _mm_mul_ps(v35, _mm_shuffle_ps(v32, v32, 170)));
        v37 = *v20;
        if ( !v21 )
        {
          (*(void (__fastcall **)(__int64 *, __m128 *, unsigned __int64, void ***))(v37 + 48))(v20, &v70, v19, &v63);
          goto LABEL_21;
        }
        (*(void (__fastcall **)(__int64 *, char *, __m128 *, __m128 *))(v37 + 40))(v20, &v76, &v70, &v48);
        if ( !v76 )
          goto LABEL_21;
        v38 = *(_DWORD *)(v9 + v10 + 100);
        v39 = *(__m128 **)(v9 + v10 + 88);
        if ( v38 < *(_DWORD *)(v9 + v10 + 96) )
        {
          v39 = (__m128 *)v13;
          v13 += 96i64;
          *(_DWORD *)(v9 + v10 + 100) = v38 + 1;
LABEL_18:
          if ( v39 )
          {
            v48 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), *v22),
                      _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v22[1])),
                    _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), v22[2]));
            *v39 = v48;
            v39[1].m128_f32[0] = v49;
            v39[1].m128_i32[1] = v50;
            v39[1].m128_i32[2] = v51;
            v39[1].m128_i32[3] = v52;
            v39[2].m128_i32[0] = v53;
            v39[2].m128_i32[1] = v54;
            v39[2].m128_i32[2] = v55;
            v39[2].m128_i32[3] = v56;
            v39[3].m128_i32[0] = v57;
            v39[3].m128_i32[1] = v58;
            v39[3].m128_i32[2] = v59;
            v39[3].m128_i32[3] = v60;
            v42 = v61;
            v39[5].m128_u64[0] = v19;
            v39[4].m128_i32[0] = v42;
          }
          goto LABEL_21;
        }
        v40 = (signed __int64)&v39[6];
        if ( v38 > 1 )
        {
          v41 = (unsigned int)(v38 - 1);
          do
          {
            if ( v39[1].m128_f32[0] < *(float *)(v40 + 16) )
              v39 = (__m128 *)v40;
            v40 += 96i64;
            --v41;
          }
          while ( v41 );
        }
        if ( v49 < v39[1].m128_f32[0] )
          goto LABEL_18;
LABEL_21:
        ++v11;
        v18 += 8i64;
      }
      while ( v11 < *(_DWORD *)(v9 + v10 + 80) );
      v16 = v68;
      v8 = v77;
      v3 = v75;
LABEL_23:
      if ( *(_BYTE *)(v9 + v10 + 104) )
        *(_DWORD *)(v9 + v10 + 100) = v16;
      ++v8;
      v9 += 112i64;
      v77 = v8;
      if ( v8 >= *(_DWORD *)&v3->m_data[48] )
      {
        v2 = v74;
        break;
      }
    }
  }
  v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v44 = (_QWORD *)v43[1];
  if ( (unsigned __int64)v44 < v43[3] )
  {
    *v44 = "Et";
    v45 = __rdtsc();
    v46 = (signed __int64)(v44 + 2);
    *(_DWORD *)(v46 - 8) = v45;
    v43[1] = v46;
  }
  return hkJobQueue::finishJobAndGetNextJob(v2, v3, v3, 0);
}

