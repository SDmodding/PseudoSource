// File Line: 26
// RVA: 0xABC4C0
__int64 __fastcall vorbis_dsp_restart(
        vorbis_dsp_state *v,
        unsigned __int16 in_uExtraSamplesBegin,
        unsigned __int16 in_uExtraSamplesEnd)
{
  *(_QWORD *)&v->state.out_begin = -1i64;
  v->state.extra_samples_begin = in_uExtraSamplesBegin;
  v->state.extra_samples_end = in_uExtraSamplesEnd;
  return 0i64;
}

// File Line: 36
// RVA: 0xABC280
__int64 __fastcall vorbis_dsp_init(vorbis_dsp_state *v, int channels)
{
  __int64 v2; // r12
  int v4; // eax
  signed int v5; // r14d
  signed int v6; // ebp
  int *v7; // rax
  int *v8; // rbx
  int *v9; // rdi
  __int64 v10; // rcx
  int **mdctright; // rax

  v2 = channels;
  v->channels = channels;
  v->work[0] = 0i64;
  v4 = v->csi->blocksizes[1];
  v5 = (4 * channels * (v4 >> 2) + 15) & 0xFFFFFFF0;
  v6 = (4 * channels * (v4 >> 1) + 15) & 0xFFFFFFF0;
  if ( !(v5 + v6) )
    return 0xFFFFFFFFi64;
  v7 = (int *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, (unsigned int)(v5 + v6));
  v8 = v7;
  if ( !v7 )
    return 0xFFFFFFFFi64;
  v9 = (int *)((char *)v7 + v6);
  memset(v7, 0, (unsigned int)(v5 + v6));
  v10 = v2;
  if ( (int)v2 > 0 )
  {
    mdctright = v->mdctright;
    do
    {
      *(mdctright - 8) = v8;
      *mdctright = v9;
      v8 = (int *)((char *)v8 + v6 / (int)v2);
      v9 = (int *)((char *)v9 + v5 / (int)v2);
      ++mdctright;
      --v10;
    }
    while ( v10 );
  }
  *(_QWORD *)&v->state.lW = 0i64;
  return 0i64;
}

// File Line: 81
// RVA: 0xABC250
void __fastcall vorbis_dsp_clear(vorbis_dsp_state *v)
{
  int *v1; // rdx

  v1 = v->work[0];
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
    v->work[0] = 0i64;
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
  int out_begin; // eax
  int out_end; // edi
  int v7; // edi
  codec_setup_info *csi; // rbp
  float *w0; // r12
  float *v10; // rax
  int step; // r9d
  int v12; // esi
  const float *w1; // r13
  float **work; // r14

  out_begin = v->state.out_begin;
  out_end = v->state.out_end;
  if ( out_begin >= out_end )
    return 0i64;
  v7 = out_end - out_begin;
  if ( pcm )
  {
    csi = v->csi;
    if ( v7 > samples )
      v7 = samples;
    w0 = vorbis_window(csi->blocksizes[0] >> 1);
    v10 = vorbis_window(csi->blocksizes[1] >> 1);
    step = v->channels;
    v12 = 0;
    w1 = v10;
    work = (float **)v->work;
    do
    {
      mdct_unroll_lap(
        csi->blocksizes[0],
        csi->blocksizes[1],
        v->state.lW,
        v->state.W,
        *work,
        work[8],
        w0,
        w1,
        &pcm[v12],
        step,
        v->state.out_begin,
        v->state.out_begin + v7);
      step = v->channels;
      ++v12;
      ++work;
    }
    while ( v12 < step );
    v->state.out_begin += v7;
  }
  return (unsigned int)v7;
}

// File Line: 168
// RVA: 0xABC4E0
void __fastcall vorbis_dsp_synthesis(vorbis_dsp_state *vd, ogg_packet *op)
{
  codec_setup_info *csi; // r14
  int v5; // eax
  __int64 W; // rdx
  int v7; // esi
  __int64 v8; // r12
  int **work; // rdi
  int v10; // ebp
  __int64 v11; // rax
  unsigned __int16 v12; // dx
  int v13; // r8d
  int v14; // ecx
  int out_begin; // eax
  int extra_samples_begin; // ecx

  csi = vd->csi;
  vd->opb.headbit = 0;
  vd->opb.headptr = op->buffer.data;
  vd->opb.headend = op->buffer.size;
  v5 = oggpack_read(&vd->opb, 1);
  W = vd->state.W;
  vd->state.lW = W;
  v7 = 0;
  v8 = v5;
  work = vd->work;
  vd->state.W = (unsigned __int8)csi->mode_param[v8].blockflag;
  v10 = csi->blocksizes[W];
  do
  {
    mdct_shift_right(v10, *work, work[8]);
    ++v7;
    ++work;
  }
  while ( v7 < vd->channels );
  if ( vd->state.out_begin == -1 )
  {
    extra_samples_begin = vd->state.extra_samples_begin;
    *(_QWORD *)&vd->state.out_begin = 0i64;
    if ( extra_samples_begin >= csi->blocksizes[1] / 2 )
      return;
  }
  else
  {
    v11 = vd->state.W;
    vd->state.out_begin = 0;
    v12 = vd->state.extra_samples_begin;
    v13 = v10 / 4 + csi->blocksizes[v11] / 4;
    vd->state.out_end = v13;
    if ( v12 )
    {
      vd->state.out_begin = v12;
      if ( v12 <= v13 )
      {
        vd->state.extra_samples_begin = 0;
      }
      else
      {
        vd->state.out_begin = v13;
        v14 = (unsigned __int16)(v12 - v13);
        vd->state.extra_samples_begin = v14;
        if ( v14 >= csi->blocksizes[1] / 2 )
          return;
      }
    }
    if ( op->e_o_s )
    {
      vd->state.out_end -= vd->state.extra_samples_end;
      out_begin = vd->state.out_begin;
      if ( vd->state.out_end < out_begin )
        vd->state.out_end = out_begin;
    }
  }
  mapping_inverse(vd, &csi->map_param[(unsigned __int8)csi->mode_param[v8].mapping]);
}

