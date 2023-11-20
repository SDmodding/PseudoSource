// File Line: 72
// RVA: 0x162600
void __fastcall UFG::qAverageWindow<float>::~qAverageWindow<float>(UFG::qAverageWindow<float> *this)
{
  if ( this->m_pMemoryPool )
    UFG::qMemoryPool::Free(this->m_pMemoryPool, this->m_pBuffer);
}

// File Line: 81
// RVA: 0x17D300
void __fastcall UFG::qAverageWindow<float>::SetTimespan(UFG::qAverageWindow<float> *this, float timespan, float max_framerate)
{
  float v3; // xmm6_4
  UFG::qAverageWindow<float> *v4; // rbx
  UFG::qAverageWindow<float>::TimeValuePair *v5; // rdi
  __int64 v6; // rax
  float v7; // xmm3_4
  int v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm1_4

  v3 = timespan;
  v4 = this;
  if ( timespan > this->m_MaxTimespan )
  {
    UFG::qAverageWindow<float>::SetMaxTimespan(this, timespan, max_framerate);
  }
  else
  {
    this->m_DesiredTimespan = timespan;
    if ( UFG::qAverageWindow<float>::AtLeastOneEntry(this) )
    {
      v5 = v4->m_pBuffer;
      do
      {
        v6 = v4->m_StartIndex;
        v7 = v5[v6].m_Timestep;
        if ( (float)(v4->m_RunningSumTime - v7) <= v3 )
          break;
        v8 = v4->m_BufferSize;
        if ( v8 )
        {
          v9 = v4->m_RunningSum;
          v10 = v7 * v5[v6].m_Value;
          v4->m_RunningSumTime = v4->m_RunningSumTime - v7;
          v4->m_RunningSum = v9 - v10;
          v4->m_StartIndex = ((signed int)v6 + 1) % v8;
        }
      }
      while ( UFG::qAverageWindow<float>::AtLeastOneEntry(v4) );
    }
  }
}

// File Line: 101
// RVA: 0x17CFC0
int UFG::qAverageWindow<float>::SetMaxTimespan(...)
{
  UFG::qAverageWindow<float> *v3; // rbx
  UFG::qMemoryPool *v4; // rcx
  __m128 v5; // xmm6
  signed int v6; // ecx
  int v7; // edx
  UFG::qMemoryPool *v8; // rcx

  v3 = this;
  v4 = this->m_pMemoryPool;
  v5 = (__m128)timespan;
  if ( v4 )
    UFG::qMemoryPool::Free(v4, v3->m_pBuffer);
  LODWORD(v3->m_MaxTimespan) = timespan;
  LODWORD(v3->m_DesiredTimespan) = timespan;
  v5.m128_f32[0] = *(float *)&timespan * max_framerate;
  v6 = (signed int)(float)(*(float *)&timespan * max_framerate);
  if ( v6 != 0x80000000 && (float)v6 != v5.m128_f32[0] )
    v5.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1 ^ 1) + v6);
  v7 = (signed int)v5.m128_f32[0] + 2;
  v3->m_BufferSize = v7;
  v8 = UFG::gMainMemoryPool;
  if ( UFG::gAverageWindowPool )
    v8 = UFG::gAverageWindowPool;
  v3->m_pMemoryPool = v8;
  v3->m_pBuffer = (UFG::qAverageWindow<float>::TimeValuePair *)UFG::qMemoryPool::Allocate(
                                                                 v8,
                                                                 8i64 * v7,
                                                                 "AverageWindow::TimeValuePair",
                                                                 0i64,
                                                                 1u);
  *(_QWORD *)&v3->m_StartIndex = 0i64;
  v3->m_RunningSumTime = 0.0;
  UFG::qMemSet(&v3->m_RunningSum, 0, 4u);
}

// File Line: 131
// RVA: 0x1668B0
void __fastcall UFG::qAverageWindow<float>::AddValue(UFG::qAverageWindow<float> *this, float value, float timestep)
{
  float v3; // xmm3_4
  float v4; // xmm5_4
  __int64 v5; // r11
  int v6; // er10
  int v7; // er9
  bool i; // al
  float v9; // xmm1_4
  UFG::qAverageWindow<float>::TimeValuePair *v10; // rax
  float v11; // xmm1_4

  v3 = timestep;
  v4 = value;
  if ( timestep <= 1.1754944e-38 )
    v3 = FLOAT_1_1754944eN38;
  v5 = this->m_EndIndex;
  v6 = this->m_BufferSize;
  v7 = this->m_StartIndex;
  this->m_RunningSum = (float)(value * v3) + this->m_RunningSum;
  this->m_RunningSumTime = v3 + this->m_RunningSumTime;
  for ( i = ((signed int)v5 + 1) % v6 == v7; v7 != (_DWORD)v5; i = 0 )
  {
    if ( !i )
    {
      v9 = this->m_DesiredTimespan;
      if ( (float)(this->m_RunningSumTime - this->m_pBuffer[v7].m_Timestep) <= v9 && v9 != 0.0 )
        break;
    }
    if ( v6 )
    {
      v10 = this->m_pBuffer;
      v11 = this->m_RunningSumTime - v10[v7].m_Timestep;
      this->m_RunningSum = this->m_RunningSum - (float)(v10[v7].m_Timestep * v10[v7].m_Value);
      this->m_RunningSumTime = v11;
      this->m_StartIndex = (v7 + 1) % v6;
    }
    v7 = this->m_StartIndex;
  }
  if ( v6 )
  {
    this->m_pBuffer[v5].m_Value = v4;
    this->m_pBuffer[this->m_EndIndex].m_Timestep = v3;
    this->m_EndIndex = (this->m_EndIndex + 1) % this->m_BufferSize;
  }
}

