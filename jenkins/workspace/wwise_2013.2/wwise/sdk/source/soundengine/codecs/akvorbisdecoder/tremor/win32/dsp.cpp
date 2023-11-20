// File Line: 26
// RVA: 0xABC4C0
__int64 __fastcall vorbis_dsp_restart(vorbis_dsp_state *v, unsigned __int16 in_uExtraSamplesBegin, unsigned __int16 in_uExtraSamplesEnd)
{
  *(_QWORD *)&v->state.out_begin = -1i64;
  v->state.extra_samples_begin = in_uExtraSamplesBegin;
  v->state.extra_samples_end = in_uExtraSamplesEnd;
  return 0i64;
}

// File Line: 36
// RVA: 0xABC280
signed __int64 __fastcall vorbis_dsp_init(vorbis_dsp_state *v, int channels)
{
  __int64 v2; // r12
  vorbis_dsp_state *v3; // rsi
  int v4; // er9
  signed int v5; // er14
  signed int v6; // ebp
  char *v7; // rax
  int *v8; // rbx
  int *v9; // rdi
  __int64 v10; // rcx
  int **v11; // rax

  v2 = channels;
  v3 = v;
  v->channels = channels;
  v->work[0] = 0i64;
  v4 = v->csi->blocksizes[1];
  v5 = (4 * channels * (v4 >> 2) + 15) & 0xFFFFFFF0;
  v6 = (4 * channels * (v4 >> 1) + 15) & 0xFFFFFFF0;
  if ( !(v5 + v6) )
    return 0xFFFFFFFFi64;
  v7 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, (unsigned int)(v5 + v6));
  v8 = (int *)v7;
  if ( !v7 )
    return 0xFFFFFFFFi64;
  v9 = (int *)&v7[v6];
  memset(v7, 0, (unsigned int)(v5 + v6));
  v10 = v2;
  if ( (signed int)v2 > 0 )
  {
    v11 = v3->mdctright;
    do
    {
      *(v11 - 8) = v8;
      *v11 = v9;
      v8 = (int *)((char *)v8 + v6 / (signed int)v2);
      v9 = (int *)((char *)v9 + v5 / (signed int)v2);
      ++v11;
      --v10;
    }
    while ( v10 );
  }
  *(_QWORD *)&v3->state.lW = 0i64;
  return 0i64;
}

// File Line: 81
// RVA: 0xABC250
void __fastcall vorbis_dsp_clear(vorbis_dsp_state *v)
{
  int *v1; // rdx
  vorbis_dsp_state *v2; // rbx

  v1 = v->work[0];
  v2 = v;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
    v2->work[0] = 0i64;
  }
}

// File Line: 90
// RVA: 0xABC1F0
float *__fastcall vorbis_window(int left)
{
  switch ( left )
  {
    case 128:
      return vwin256;
    case 256:
      return vwin512;
    case 512:
      return vwin1024;
    case 1024:
      return vwin2048;
    case 2048:
      return vwin4096;
  }
  return 0i64;
}

// File Line: 121
// RVA: 0xABC390
__int64 __fastcall vorbis_dsp_pcmout(vorbis_dsp_state *v, __int16 *pcm, int samples)
{
  int v3; // eax
  int v4; // edi
  __int16 *v5; // r15
  vorbis_dsp_state *v6; // rbx
  int v7; // edi
  codec_setup_info *v8; // rbp
  float *w0; // r12
  float *v10; // rax
  int step; // er9
  int v12; // esi
  const float *w1; // r13
  float **v14; // r14

  v3 = v->state.out_begin;
  v4 = v->state.out_end;
  v5 = pcm;
  v6 = v;
  if ( v3 >= v4 )
    return 0i64;
  v7 = v4 - v3;
  if ( pcm )
  {
    v8 = v->csi;
    if ( v7 > samples )
      v7 = samples;
    w0 = vorbis_window(v8->blocksizes[0] >> 1);
    v10 = vorbis_window(v8->blocksizes[1] >> 1);
    step = v6->channels;
    v12 = 0;
    w1 = v10;
    v14 = (float **)v6->work;
    do
    {
      mdct_unroll_lap(
        v8->blocksizes[0],
        v8->blocksizes[1],
        v6->state.lW,
        v6->state.W,
        *v14,
        v14[8],
        w0,
        w1,
        &v5[v12],
        step,
        v6->state.out_begin,
        v6->state.out_begin + v7);
      step = v6->channels;
      ++v12;
      ++v14;
    }
    while ( v12 < step );
    v6->state.out_begin += v7;
  }
  return (unsigned int)v7;
}

// File Line: 168
// RVA: 0xABC4E0
void __fastcall vorbis_dsp_synthesis(vorbis_dsp_state *vd, ogg_packet *op)
{
  codec_setup_info *v2; // r14
  ogg_packet *v3; // r15
  vorbis_dsp_state *v4; // rbx
  int v5; // eax
  __int64 v6; // rdx
  int v7; // esi
  signed __int64 v8; // r12
  int **v9; // rdi
  int v10; // ebp
  __int64 v11; // rax
  unsigned __int16 v12; // dx
  int v13; // er8
  int v14; // ecx
  int v15; // eax
  int v16; // ecx

  v2 = vd->csi;
  v3 = op;
  vd->opb.headbit = 0;
  v4 = vd;
  vd->opb.headptr = op->buffer.data;
  vd->opb.headend = op->buffer.size;
  v5 = oggpack_read(&vd->opb, 1);
  v6 = v4->state.W;
  v4->state.lW = v6;
  v7 = 0;
  v8 = v5;
  v9 = v4->work;
  v4->state.W = (unsigned __int8)v2->mode_param[v8].blockflag;
  v10 = v2->blocksizes[v6];
  do
  {
    mdct_shift_right(v10, *v9, v9[8]);
    ++v7;
    ++v9;
  }
  while ( v7 < v4->channels );
  if ( v4->state.out_begin == -1 )
  {
    v16 = v4->state.extra_samples_begin;
    *(_QWORD *)&v4->state.out_begin = 0i64;
    if ( v16 >= v2->blocksizes[1] / 2 )
      return;
  }
  else
  {
    v11 = v4->state.W;
    v4->state.out_begin = 0;
    v12 = v4->state.extra_samples_begin;
    v13 = v10 / 4 + v2->blocksizes[v11] / 4;
    v4->state.out_end = v13;
    if ( v12 )
    {
      v4->state.out_begin = v12;
      if ( v12 <= v13 )
      {
        v4->state.extra_samples_begin = 0;
      }
      else
      {
        v4->state.out_begin = v13;
        v14 = (unsigned __int16)(v12 - v13);
        v4->state.extra_samples_begin = v14;
        if ( v14 >= v2->blocksizes[1] / 2 )
          return;
      }
    }
    if ( v3->e_o_s )
    {
      v4->state.out_end -= v4->state.extra_samples_end;
      v15 = v4->state.out_begin;
      if ( v4->state.out_end < v15 )
        v4->state.out_end = v15;
    }
  }
  mapping_inverse(v4, &v2->map_param[(unsigned __int8)v2->mode_param[v8].mapping]);
}

