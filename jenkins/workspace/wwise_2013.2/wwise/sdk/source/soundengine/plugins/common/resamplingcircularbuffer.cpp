// File Line: 20
// RVA: 0xAF90C0
void __fastcall DSP::CAkResamplingCircularBuffer::Reset(DSP::CAkResamplingCircularBuffer *this)
{
  DSP::CAkCircularBuffer::Reset(this);
  *(_QWORD *)&this->m_fPastVal = 0i64;
}

// File Line: 36
// RVA: 0xAF90E0
unsigned int __fastcall DSP::CAkResamplingCircularBuffer::PushFrames(
        DSP::CAkResamplingCircularBuffer *this,
        float *in_pfBuffer,
        unsigned int in_NumFrames,
        float in_fResamplingFactor)
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
__int64 __fastcall DSP::CAkResamplingCircularBuffer::PushFrames(
        DSP::CAkResamplingCircularBuffer *this,
        float *in_pfBuffer,
        unsigned __int16 in_NumFrames,
        float *io_pfData,
        float in_fResamplingFactor)
{
  unsigned int m_uSize; // ebp
  unsigned int m_uWriteOffset; // r11d
  unsigned int v10; // esi
  float m_fInterpLoc; // xmm1_4
  unsigned __int16 v13; // r8
  unsigned __int16 v14; // r9
  float m_fPastVal; // xmm4_4
  float v16; // xmm3_4
  int v17; // edx
  float v18; // xmm3_4
  float v19; // xmm2_4
  __int64 v20; // rax
  __m128i v21; // xmm0

  m_uSize = this->m_uSize;
  m_uWriteOffset = this->m_uWriteOffset;
  v10 = this->m_uSize - this->m_uFramesReady;
  if ( this->m_uSize == this->m_uFramesReady )
    return 0i64;
  m_fInterpLoc = this->m_fInterpLoc;
  v13 = 0;
  v14 = 0;
  while ( 1 )
  {
    if ( m_fInterpLoc >= 0.0 )
    {
      v17 = (int)m_fInterpLoc;
      if ( (unsigned __int16)(int)m_fInterpLoc >= in_NumFrames - 1 )
      {
        if ( (unsigned __int16)v17 <= in_NumFrames - 1 )
        {
          this->m_fPastVal = in_pfBuffer[(unsigned __int16)v17];
          v21 = _mm_cvtsi32_si128((unsigned int)(unsigned __int16)v17 + 1);
        }
        else
        {
          v21 = _mm_cvtsi32_si128(in_NumFrames);
        }
        v13 = in_NumFrames;
        goto LABEL_20;
      }
      m_fPastVal = in_pfBuffer[(unsigned __int16)v17];
      v16 = in_pfBuffer[(unsigned __int16)v17 + 1];
    }
    else
    {
      m_fPastVal = this->m_fPastVal;
      v16 = *in_pfBuffer;
    }
    if ( v14 == v10 )
      break;
    v18 = v16 - m_fPastVal;
    if ( m_fInterpLoc < 0.0 )
      v19 = m_fInterpLoc + 1.0;
    else
      v19 = m_fInterpLoc - (float)(int)m_fInterpLoc;
    v20 = m_uWriteOffset++;
    ++v14;
    m_fInterpLoc = m_fInterpLoc + in_fResamplingFactor;
    io_pfData[v20] = (float)(v19 * v18) + m_fPastVal;
    if ( m_uWriteOffset == m_uSize )
      m_uWriteOffset = 0;
  }
  this->m_fPastVal = m_fPastVal;
  if ( m_fInterpLoc <= 0.0 )
    goto LABEL_21;
  v13 = (int)m_fInterpLoc + 1;
  v21 = _mm_cvtsi32_si128((unsigned int)(unsigned __int16)(int)m_fInterpLoc + 1);
LABEL_20:
  m_fInterpLoc = m_fInterpLoc - _mm_cvtepi32_ps(v21).m128_f32[0];
LABEL_21:
  this->m_uFramesReady += v14;
  this->m_fInterpLoc = m_fInterpLoc;
  this->m_uWriteOffset = m_uWriteOffset;
  return v13;
}

