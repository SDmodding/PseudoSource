// File Line: 20
// RVA: 0xAF90C0
void __fastcall DSP::CAkResamplingCircularBuffer::Reset(DSP::CAkResamplingCircularBuffer *this)
{
  DSP::CAkResamplingCircularBuffer *v1; // rbx

  v1 = this;
  DSP::CAkCircularBuffer::Reset((DSP::CAkCircularBuffer *)&this->m_uSize);
  *(_QWORD *)&v1->m_fPastVal = 0i64;
}

// File Line: 36
// RVA: 0xAF90E0
unsigned int __fastcall DSP::CAkResamplingCircularBuffer::PushFrames(DSP::CAkResamplingCircularBuffer *this, float *in_pfBuffer, unsigned int in_NumFrames, float in_fResamplingFactor)
{
  return DSP::CAkResamplingCircularBuffer::PushFrames(
           this,
           in_pfBuffer,
           in_NumFrames,
           this->m_pfData,
           in_fResamplingFactor);
}

// File Line: 50
// RVA: 0xAF9100
__int64 __fastcall DSP::CAkResamplingCircularBuffer::PushFrames(DSP::CAkResamplingCircularBuffer *this, float *in_pfBuffer, unsigned int in_NumFrames, float *io_pfData, float in_fResamplingFactor)
{
  unsigned int v5; // ebp
  unsigned int v6; // er11
  float *v7; // r14
  unsigned __int16 v8; // di
  float *v9; // rbx
  unsigned int v10; // esi
  float v12; // xmm1_4
  int v13; // er8
  unsigned __int16 v14; // r9
  float v15; // xmm4_4
  float v16; // xmm3_4
  signed int v17; // edx
  float v18; // xmm3_4
  float v19; // xmm2_4
  __int64 v20; // rax
  __m128i v21; // xmm0

  v5 = this->m_uSize;
  v6 = this->m_uWriteOffset;
  v7 = io_pfData;
  v8 = in_NumFrames;
  v9 = in_pfBuffer;
  v10 = this->m_uSize - this->m_uFramesReady;
  if ( this->m_uSize == this->m_uFramesReady )
    return 0i64;
  v12 = this->m_fInterpLoc;
  LOWORD(v13) = 0;
  v14 = 0;
  while ( 1 )
  {
    if ( v12 >= 0.0 )
    {
      v17 = (signed int)v12;
      if ( (unsigned __int16)(signed int)v12 >= v8 - 1 )
      {
        if ( (unsigned __int16)v17 <= v8 - 1 )
        {
          this->m_fPastVal = v9[(unsigned __int16)v17];
          v21 = _mm_cvtsi32_si128((unsigned int)(unsigned __int16)v17 + 1);
        }
        else
        {
          v21 = _mm_cvtsi32_si128(v8);
        }
        LOWORD(v13) = v8;
        goto LABEL_20;
      }
      v15 = v9[(unsigned __int16)v17];
      v16 = v9[(unsigned __int16)v17 + 1];
    }
    else
    {
      v15 = this->m_fPastVal;
      v16 = *v9;
    }
    if ( v14 == v10 )
      break;
    v18 = v16 - v15;
    if ( v12 < 0.0 )
      v19 = v12 + 1.0;
    else
      v19 = v12 - (float)(signed int)v12;
    v20 = v6++;
    ++v14;
    v12 = v12 + in_fResamplingFactor;
    v7[v20] = (float)(v19 * v18) + v15;
    if ( v6 == v5 )
      v6 = 0;
  }
  this->m_fPastVal = v15;
  if ( v12 <= 0.0 )
    goto LABEL_21;
  v13 = (signed int)v12 + 1;
  v21 = _mm_cvtsi32_si128((unsigned int)(unsigned __int16)(signed int)v12 + 1);
LABEL_20:
  v12 = v12 - COERCE_FLOAT(_mm_cvtepi32_ps(v21));
LABEL_21:
  this->m_uFramesReady += v14;
  this->m_fInterpLoc = v12;
  this->m_uWriteOffset = v6;
  return (unsigned __int16)v13;
}

