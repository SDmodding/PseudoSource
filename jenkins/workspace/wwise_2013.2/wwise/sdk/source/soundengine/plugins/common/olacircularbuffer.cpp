// File Line: 19
// RVA: 0xAEECB0
bool __fastcall DSP::CAkOLACircularBuffer::IsDoneTail(DSP::CAkOLACircularBuffer *this)
{
  unsigned int v2; // edx
  unsigned int v3; // eax
  unsigned int v4; // edx

  if ( this->m_uFramesReady )
    return 0;
  v2 = (this->m_uWriteOffset + this->m_uWindowSize) % this->m_uSize;
  v3 = this->m_uReadOffset;
  if ( v2 < v3 )
    v4 = this->m_uSize + v3 - v2;
  else
    v4 = v2 - v3;
  return v4 == 0;
}

// File Line: 40
// RVA: 0xAEECF0
__int64 __fastcall DSP::CAkOLACircularBuffer::Init(DSP::CAkOLACircularBuffer *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uSize, unsigned int in_uWindowSize)
{
  this->m_uWindowSize = in_uWindowSize;
  return DSP::CAkCircularBuffer::Init((DSP::CAkCircularBuffer *)&this->m_uSize, in_pAllocator, in_uSize);
}

// File Line: 51
// RVA: 0xAEED00
bool __fastcall DSP::CAkOLACircularBuffer::PushOverlappedWindow(DSP::CAkOLACircularBuffer *this, float *in_pfBuffer, unsigned int in_uHopSize)
{
  return DSP::CAkOLACircularBuffer::PushOverlappedWindow(this, in_pfBuffer, in_uHopSize, this->m_pfData);
}

// File Line: 65
// RVA: 0xAEED10
unsigned int __fastcall DSP::CAkOLACircularBuffer::PopFrames(DSP::CAkOLACircularBuffer *this, float *out_pfBuffer, unsigned int in_RequestedFrames, bool in_bNoMoredata)
{
  return DSP::CAkOLACircularBuffer::PopFrames(this, out_pfBuffer, in_RequestedFrames, in_bNoMoredata, this->m_pfData);
}

// File Line: 82
// RVA: 0xAEED30
char __fastcall DSP::CAkOLACircularBuffer::PushOverlappedWindow(DSP::CAkOLACircularBuffer *this, float *in_pfBuffer, unsigned int in_uHopSize, float *io_pfData)
{
  unsigned int v4; // er13
  float *v5; // r14
  DSP::CAkOLACircularBuffer *v6; // r15
  unsigned int v7; // ebp
  unsigned int v8; // er12
  unsigned int v9; // er11
  __int64 v10; // rsi
  float *v11; // r8
  __int64 v12; // rbx
  float *v13; // rdx
  unsigned int v14; // er10
  unsigned int v15; // edi
  __int64 v16; // rax
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  unsigned int v19; // eax
  __int64 v20; // rcx
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  signed __int64 v26; // r8
  __int64 v27; // rcx
  float v28; // xmm0_4
  unsigned int v29; // er11
  unsigned __int64 v30; // rdx
  __int64 v31; // rax
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  unsigned int v34; // eax
  __int64 v35; // rcx
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  unsigned __int64 v41; // rdx
  __int64 v42; // rax
  float v43; // xmm0_4
  char result; // al

  v4 = in_uHopSize;
  v5 = in_pfBuffer;
  v6 = this;
  if ( !in_pfBuffer )
    return 0;
  v7 = this->m_uSize;
  v8 = this->m_uFramesReady;
  v9 = this->m_uWindowSize;
  if ( v9 > this->m_uSize - v8 )
    return 0;
  v10 = this->m_uWriteOffset;
  v11 = in_pfBuffer;
  v12 = v7 - (unsigned int)v10;
  v13 = &io_pfData[v10];
  if ( v9 < (unsigned int)v12 )
    v12 = v9;
  v14 = 0;
  v15 = 0;
  if ( (_DWORD)v12 )
  {
    if ( (unsigned int)v12 >= 4 )
    {
      v16 = (unsigned int)(v12 - 1);
      if ( v13 <= &v5[v16] && &v13[v16] >= v5 )
      {
        LODWORD(v10) = this->m_uWriteOffset;
      }
      else
      {
        do
        {
          v17 = *(__m128 *)v13;
          v18 = *(__m128 *)v11;
          v15 += 4;
          v13 += 4;
          v11 += 4;
          *((__m128 *)v13 - 1) = _mm_add_ps(v18, v17);
        }
        while ( v15 < (unsigned __int64)((unsigned int)v12 - (v12 & 3)) );
        LODWORD(v10) = this->m_uWriteOffset;
      }
    }
    if ( v15 < (unsigned int)v12 )
    {
      if ( (signed int)(v12 - v15) >= 4 )
      {
        v19 = (((unsigned int)v12 - v15 - 4) >> 2) + 1;
        v20 = v19;
        v15 += 4 * v19;
        do
        {
          v21 = *v13;
          v22 = v11[1];
          v13 += 4;
          v11 += 4;
          v23 = v22 + *(v13 - 3);
          *(v13 - 4) = v21 + *(v11 - 4);
          v24 = *(v11 - 2);
          *(v13 - 3) = v23;
          v25 = *(v11 - 1) + *(v13 - 1);
          *(v13 - 2) = v24 + *(v13 - 2);
          *(v13 - 1) = v25;
          --v20;
        }
        while ( v20 );
      }
      if ( v15 < (unsigned int)v12 )
      {
        v26 = (char *)v11 - (char *)v13;
        v27 = (signed int)(v12 - v15);
        do
        {
          v28 = *(float *)((char *)v13 + v26);
          ++v13;
          *(v13 - 1) = v28 + *(v13 - 1);
          --v27;
        }
        while ( v27 );
      }
    }
  }
  v29 = v9 - v12;
  if ( v29 )
  {
    v30 = (unsigned __int64)&v5[v12];
    if ( v29 )
    {
      if ( v29 >= 4 )
      {
        v31 = v29 - 1;
        if ( (unsigned __int64)io_pfData > v30 + 4 * v31 || (unsigned __int64)&io_pfData[v31] < v30 )
        {
          do
          {
            v32 = *(__m128 *)io_pfData;
            v33 = *(__m128 *)v30;
            v14 += 4;
            io_pfData += 4;
            v30 += 16i64;
            *((__m128 *)io_pfData - 1) = _mm_add_ps(v33, v32);
          }
          while ( v14 < v29 - (v29 & 3) );
        }
      }
      if ( v14 < v29 )
      {
        if ( (signed int)(v29 - v14) >= 4 )
        {
          v34 = ((v29 - v14 - 4) >> 2) + 1;
          v35 = v34;
          v14 += 4 * v34;
          do
          {
            v36 = *(float *)v30;
            v37 = *(float *)(v30 + 4);
            io_pfData += 4;
            v30 += 16i64;
            v38 = v37 + *(io_pfData - 3);
            *(io_pfData - 4) = v36 + *(io_pfData - 4);
            v39 = *(float *)(v30 - 8);
            *(io_pfData - 3) = v38;
            v40 = *(float *)(v30 - 4) + *(io_pfData - 1);
            *(io_pfData - 2) = v39 + *(io_pfData - 2);
            *(io_pfData - 1) = v40;
            --v35;
          }
          while ( v35 );
        }
        if ( v14 < v29 )
        {
          v41 = v30 - (_QWORD)io_pfData;
          v42 = (signed int)(v29 - v14);
          do
          {
            v43 = *(float *)((char *)io_pfData + v41);
            ++io_pfData;
            *(io_pfData - 1) = v43 + *(io_pfData - 1);
            --v42;
          }
          while ( v42 );
        }
      }
    }
  }
  v6->m_uFramesReady = v8 + v4;
  result = 1;
  v6->m_uWriteOffset = ((unsigned int)v10 + v4) % v7;
  return result;
}

// File Line: 118
// RVA: 0xAEEFE0
__int64 __fastcall DSP::CAkOLACircularBuffer::PopFrames(DSP::CAkOLACircularBuffer *this, float *out_pfBuffer, unsigned int in_RequestedFrames, bool in_bNoMoredata, float *io_pfData)
{
  unsigned int v5; // edi
  float *v6; // r14
  DSP::CAkOLACircularBuffer *v7; // rsi
  unsigned int v8; // ecx
  unsigned int v9; // edx
  unsigned int v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // edx
  unsigned int v13; // eax
  __int64 v14; // rcx
  __int64 v15; // rbp
  size_t v16; // rbx
  __int64 result; // rax

  v5 = in_RequestedFrames;
  v6 = out_pfBuffer;
  v7 = this;
  if ( !out_pfBuffer || !in_RequestedFrames )
    return 0i64;
  if ( !in_bNoMoredata || this->m_uFramesReady )
  {
    v13 = this->m_uFramesReady;
    if ( v13 < in_RequestedFrames )
      v5 = this->m_uFramesReady;
    this->m_uFramesReady = v13 - v5;
  }
  else
  {
    v8 = this->m_uSize;
    v9 = (v7->m_uWriteOffset + v7->m_uWindowSize) % v8;
    v10 = v7->m_uReadOffset;
    if ( v9 <= v10 )
    {
      v12 = v8 + v10 - v9;
      if ( v12 < in_RequestedFrames )
        v5 = v12;
    }
    else
    {
      v11 = v9 - v10;
      if ( v11 < in_RequestedFrames )
        v5 = v11;
    }
  }
  v14 = v7->m_uReadOffset;
  v15 = (unsigned int)(v7->m_uSize - v14);
  if ( v5 < (unsigned int)v15 )
    v15 = v5;
  memmove(v6, &io_pfData[v14], (unsigned int)(4 * v15));
  memset(&io_pfData[v7->m_uReadOffset], 0, (unsigned int)(4 * v15));
  if ( v5 != (_DWORD)v15 )
  {
    v16 = 4 * (v5 - (unsigned int)v15);
    memmove(&v6[v15], io_pfData, v16);
    memset(io_pfData, 0, (unsigned int)v16);
  }
  result = v5;
  v7->m_uReadOffset = (v5 + v7->m_uReadOffset) % v7->m_uSize;
  return result;
}

