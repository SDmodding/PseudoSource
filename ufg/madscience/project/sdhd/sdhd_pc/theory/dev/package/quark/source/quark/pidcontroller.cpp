// File Line: 18
// RVA: 0x1617A0
void __fastcall UFG::qPidControllerCore::qPidControllerCore(UFG::qPidControllerCore *this)
{
  *(_QWORD *)&this->m_P_Term.m_MaxTimespan = 0i64;
  this->m_P_Term.m_BufferSize = 0;
  this->m_P_Term.m_pBuffer = 0i64;
  this->m_P_Term.m_pMemoryPool = 0i64;
  *(_QWORD *)&this->m_P_Term.m_StartIndex = 0i64;
  this->m_P_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->m_P_Term.m_RunningSum, 0, 4u);
  *(_QWORD *)&this->m_I_Term.m_MaxTimespan = 0i64;
  this->m_I_Term.m_BufferSize = 0;
  this->m_I_Term.m_pBuffer = 0i64;
  this->m_I_Term.m_pMemoryPool = 0i64;
  *(_QWORD *)&this->m_I_Term.m_StartIndex = 0i64;
  this->m_I_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->m_I_Term.m_RunningSum, 0, 4u);
  *(_QWORD *)&this->m_D_Term.m_MaxTimespan = 0i64;
  this->m_D_Term.m_BufferSize = 0;
  this->m_D_Term.m_pBuffer = 0i64;
  this->m_D_Term.m_pMemoryPool = 0i64;
  *(_QWORD *)&this->m_D_Term.m_StartIndex = 0i64;
  this->m_D_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->m_D_Term.m_RunningSum, 0, 4u);
  this->m_Parameters = 0i64;
  UFG::qAverageWindow<float>::SetMaxTimespan(&this->m_P_Term, 1.0, 60.0);
  UFG::qAverageWindow<float>::SetMaxTimespan(&this->m_I_Term, 1.0, 60.0);
  UFG::qAverageWindow<float>::SetMaxTimespan(&this->m_D_Term, 1.0, 60.0);
}

// File Line: 37
// RVA: 0x163F20
void __fastcall UFG::qPidControllerCore::~qPidControllerCore(UFG::qPidControllerCore *this)
{
  UFG::qMemoryPool *m_pMemoryPool; // rcx
  UFG::qMemoryPool *v3; // rcx
  UFG::qMemoryPool *v4; // rcx

  m_pMemoryPool = this->m_D_Term.m_pMemoryPool;
  if ( m_pMemoryPool )
    UFG::qMemoryPool::Free(m_pMemoryPool, this->m_D_Term.m_pBuffer);
  v3 = this->m_I_Term.m_pMemoryPool;
  if ( v3 )
    UFG::qMemoryPool::Free(v3, this->m_I_Term.m_pBuffer);
  v4 = this->m_P_Term.m_pMemoryPool;
  if ( v4 )
    UFG::qMemoryPool::Free(v4, this->m_P_Term.m_pBuffer);
}

// File Line: 42
// RVA: 0x17D0D0
void __fastcall UFG::qPidControllerCore::SetParameters(
        UFG::qPidControllerCore *this,
        UFG::qPidParameterBlock *parameters)
{
  float m_ProportionalTimeSpan; // xmm1_4

  m_ProportionalTimeSpan = parameters->m_ProportionalTimeSpan;
  this->m_Parameters = parameters;
  UFG::qAverageWindow<float>::SetTimespan(&this->m_P_Term, m_ProportionalTimeSpan, 30.0);
  UFG::qAverageWindow<float>::SetTimespan(&this->m_I_Term, parameters->m_IntegralTimeSpan, 30.0);
  UFG::qAverageWindow<float>::SetTimespan(&this->m_D_Term, parameters->m_DerivativeTimeSpan, 30.0);
}

// File Line: 55
// RVA: 0x167DE0
void __fastcall UFG::qPidControllerCore::Clear(UFG::qPidControllerCore *this)
{
  *(_QWORD *)&this->m_P_Term.m_StartIndex = 0i64;
  this->m_P_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->m_P_Term.m_RunningSum, 0, 4u);
  *(_QWORD *)&this->m_I_Term.m_StartIndex = 0i64;
  this->m_I_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->m_I_Term.m_RunningSum, 0, 4u);
  *(_QWORD *)&this->m_D_Term.m_StartIndex = 0i64;
  this->m_D_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->m_D_Term.m_RunningSum, 0, 4u);
}

// File Line: 80
// RVA: 0x179F80
void __fastcall UFG::qPidControllerCore::Record(
        UFG::qPidControllerCore *this,
        float error,
        float timestep,
        float *derivative_clamp)
{
  int m_EndIndex; // eax
  int m_BufferSize; // edx
  int v8; // eax
  float m_Value; // xmm0_4
  int v10; // xmm6_4
  float dest; // [rsp+68h] [rbp+10h] BYREF

  m_EndIndex = this->m_P_Term.m_EndIndex;
  if ( this->m_P_Term.m_StartIndex == m_EndIndex || (m_BufferSize = this->m_P_Term.m_BufferSize) == 0 )
  {
    UFG::qMemSet(&dest, 0, 4u);
    m_Value = dest;
  }
  else
  {
    v8 = m_EndIndex - 1;
    if ( v8 < 0 )
      v8 = m_BufferSize - 1;
    m_Value = this->m_P_Term.m_pBuffer[v8].m_Value;
  }
  *(float *)&v10 = (float)(error - m_Value) / timestep;
  if ( derivative_clamp )
  {
    if ( *(float *)&v10 <= COERCE_FLOAT(*(_DWORD *)derivative_clamp ^ _xmm[0]) )
      v10 = *(_DWORD *)derivative_clamp ^ _xmm[0];
    if ( *(float *)&v10 >= *derivative_clamp )
      v10 = *(int *)derivative_clamp;
  }
  UFG::qAverageWindow<float>::AddValue(&this->m_P_Term, error, timestep);
  UFG::qAverageWindow<float>::AddValue(&this->m_I_Term, error, timestep);
  UFG::qAverageWindow<float>::AddValue(&this->m_D_Term, *(float *)&v10, timestep);
}

// File Line: 139
// RVA: 0x1715A0
float __fastcall UFG::qPidControllerCore::GetOutput(UFG::qPidControllerCore *this)
{
  float v1; // xmm0_4
  float v2; // xmm1_4
  float m_RunningSumTime; // xmm2_4
  float v4; // xmm4_4

  v1 = 0.0;
  if ( this->m_P_Term.m_StartIndex == this->m_P_Term.m_EndIndex )
  {
    v2 = 0.0;
  }
  else
  {
    m_RunningSumTime = this->m_P_Term.m_RunningSumTime;
    if ( m_RunningSumTime > 0.0 )
      v2 = this->m_P_Term.m_RunningSum / m_RunningSumTime;
    else
      v2 = FLOAT_3_4028235e38;
  }
  if ( this->m_D_Term.m_StartIndex != this->m_D_Term.m_EndIndex )
  {
    v4 = this->m_D_Term.m_RunningSumTime;
    if ( v4 > 0.0 )
      v1 = this->m_D_Term.m_RunningSum / v4;
    else
      v1 = FLOAT_3_4028235e38;
  }
  return (float)((float)(this->m_I_Term.m_RunningSum * this->m_Parameters->m_I_Coefficient)
               + (float)(v2 * this->m_Parameters->m_P_Coefficient))
       + (float)(v1 * this->m_Parameters->m_D_Coefficient);
}

