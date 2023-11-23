// File Line: 72
// RVA: 0x162600
void __fastcall UFG::qAverageWindow<float>::~qAverageWindow<float>(UFG::qAverageWindow<float> *this)
{
  if ( this->m_pMemoryPool )
    UFG::qMemoryPool::Free(this->m_pMemoryPool, this->m_pBuffer);
}

// File Line: 81
// RVA: 0x17D300
void __fastcall UFG::qAverageWindow<float>::SetTimespan(
        UFG::qAverageWindow<float> *this,
        double timespan,
        float max_framerate)
{
  float v3; // xmm6_4
  UFG::qAverageWindow<float>::TimeValuePair *m_pBuffer; // rdi
  __int64 m_StartIndex; // rax
  float m_Timestep; // xmm3_4
  int m_BufferSize; // ecx
  float m_RunningSum; // xmm0_4
  float v10; // xmm1_4

  v3 = *(float *)&timespan;
  if ( *(float *)&timespan > this->m_MaxTimespan )
  {
    UFG::qAverageWindow<float>::SetMaxTimespan(this, timespan, max_framerate);
  }
  else
  {
    this->m_DesiredTimespan = *(float *)&timespan;
    if ( UFG::qAverageWindow<float>::AtLeastOneEntry(this) )
    {
      m_pBuffer = this->m_pBuffer;
      do
      {
        m_StartIndex = this->m_StartIndex;
        m_Timestep = m_pBuffer[m_StartIndex].m_Timestep;
        if ( (float)(this->m_RunningSumTime - m_Timestep) <= v3 )
          break;
        m_BufferSize = this->m_BufferSize;
        if ( m_BufferSize )
        {
          m_RunningSum = this->m_RunningSum;
          v10 = m_Timestep * m_pBuffer[m_StartIndex].m_Value;
          this->m_RunningSumTime = this->m_RunningSumTime - m_Timestep;
          this->m_RunningSum = m_RunningSum - v10;
          this->m_StartIndex = ((int)m_StartIndex + 1) % m_BufferSize;
        }
      }
      while ( UFG::qAverageWindow<float>::AtLeastOneEntry(this) );
    }
  }
}

// File Line: 101
// RVA: 0x17CFC0
// local variable allocation has failed, the output may be wrong!
void __fastcall UFG::qAverageWindow<float>::SetMaxTimespan(
        UFG::qAverageWindow<float> *this,
        double timespan,
        float max_framerate)
{
  UFG::qMemoryPool *m_pMemoryPool; // rcx
  __m128 v5; // xmm6
  int v6; // ecx
  int v7; // edx
  UFG::qMemoryPool *v8; // rcx

  m_pMemoryPool = this->m_pMemoryPool;
  v5 = *(__m128 *)&timespan;
  if ( m_pMemoryPool )
    UFG::qMemoryPool::Free(m_pMemoryPool, (char *)this->m_pBuffer);
  this->m_MaxTimespan = *(float *)&timespan;
  this->m_DesiredTimespan = *(float *)&timespan;
  v5.m128_f32[0] = *(float *)&timespan * max_framerate;
  v6 = (int)(float)(*(float *)&timespan * max_framerate);
  if ( v6 != 0x80000000 && (float)v6 != v5.m128_f32[0] )
    v5.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1) + v6);
  v7 = (int)v5.m128_f32[0] + 2;
  this->m_BufferSize = v7;
  v8 = UFG::gMainMemoryPool;
  if ( UFG::gAverageWindowPool )
    v8 = UFG::gAverageWindowPool;
  this->m_pMemoryPool = v8;
  this->m_pBuffer = (UFG::qAverageWindow<float>::TimeValuePair *)UFG::qMemoryPool::Allocate(
                                                                   v8,
                                                                   8i64 * v7,
                                                                   "AverageWindow::TimeValuePair",
                                                                   0i64,
                                                                   1u);
  *(_QWORD *)&this->m_StartIndex = 0i64;
  this->m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->m_RunningSum, 0, 4u);
}

// File Line: 131
// RVA: 0x1668B0
void __fastcall UFG::qAverageWindow<float>::AddValue(UFG::qAverageWindow<float> *this, float value, float timestep)
{
  float v3; // xmm3_4
  __int64 m_EndIndex; // r11
  int m_BufferSize; // r10d
  int m_StartIndex; // r9d
  bool i; // al
  float m_DesiredTimespan; // xmm1_4
  UFG::qAverageWindow<float>::TimeValuePair *m_pBuffer; // rax
  float v11; // xmm1_4

  v3 = timestep;
  if ( timestep <= 1.1754944e-38 )
    v3 = FLOAT_1_1754944eN38;
  m_EndIndex = this->m_EndIndex;
  m_BufferSize = this->m_BufferSize;
  m_StartIndex = this->m_StartIndex;
  this->m_RunningSum = (float)(value * v3) + this->m_RunningSum;
  this->m_RunningSumTime = v3 + this->m_RunningSumTime;
  for ( i = ((int)m_EndIndex + 1) % m_BufferSize == m_StartIndex; m_StartIndex != (_DWORD)m_EndIndex; i = 0 )
  {
    if ( !i )
    {
      m_DesiredTimespan = this->m_DesiredTimespan;
      if ( (float)(this->m_RunningSumTime - this->m_pBuffer[m_StartIndex].m_Timestep) <= m_DesiredTimespan
        && m_DesiredTimespan != 0.0 )
      {
        break;
      }
    }
    if ( m_BufferSize )
    {
      m_pBuffer = this->m_pBuffer;
      v11 = this->m_RunningSumTime - m_pBuffer[m_StartIndex].m_Timestep;
      this->m_RunningSum = this->m_RunningSum
                         - (float)(m_pBuffer[m_StartIndex].m_Timestep * m_pBuffer[m_StartIndex].m_Value);
      this->m_RunningSumTime = v11;
      this->m_StartIndex = (m_StartIndex + 1) % m_BufferSize;
    }
    m_StartIndex = this->m_StartIndex;
  }
  if ( m_BufferSize )
  {
    this->m_pBuffer[m_EndIndex].m_Value = value;
    this->m_pBuffer[this->m_EndIndex].m_Timestep = v3;
    this->m_EndIndex = (this->m_EndIndex + 1) % this->m_BufferSize;
  }
}

