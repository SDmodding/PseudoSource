// File Line: 18
// RVA: 0x1617A0
void __fastcall UFG::qPidControllerCore::qPidControllerCore(UFG::qPidControllerCore *this)
{
  UFG::qPidControllerCore *v1; // r14

  v1 = this;
  *(_QWORD *)&this->m_P_Term.m_MaxTimespan = 0i64;
  this->m_P_Term.m_BufferSize = 0;
  this->m_P_Term.m_pBuffer = 0i64;
  this->m_P_Term.m_pMemoryPool = 0i64;
  *(_QWORD *)&this->m_P_Term.m_StartIndex = 0i64;
  this->m_P_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->m_P_Term.m_RunningSum, 0, 4u);
  *(_QWORD *)&v1->m_I_Term.m_MaxTimespan = 0i64;
  v1->m_I_Term.m_BufferSize = 0;
  v1->m_I_Term.m_pBuffer = 0i64;
  v1->m_I_Term.m_pMemoryPool = 0i64;
  *(_QWORD *)&v1->m_I_Term.m_StartIndex = 0i64;
  v1->m_I_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&v1->m_I_Term.m_RunningSum, 0, 4u);
  *(_QWORD *)&v1->m_D_Term.m_MaxTimespan = 0i64;
  v1->m_D_Term.m_BufferSize = 0;
  v1->m_D_Term.m_pBuffer = 0i64;
  v1->m_D_Term.m_pMemoryPool = 0i64;
  *(_QWORD *)&v1->m_D_Term.m_StartIndex = 0i64;
  v1->m_D_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&v1->m_D_Term.m_RunningSum, 0, 4u);
  v1->m_Parameters = 0i64;
  UFG::qAverageWindow<float>::SetMaxTimespan(&v1->m_P_Term, 1.0, 60.0);
  UFG::qAverageWindow<float>::SetMaxTimespan(&v1->m_I_Term, 1.0, 60.0);
  UFG::qAverageWindow<float>::SetMaxTimespan(&v1->m_D_Term, 1.0, 60.0);
}

// File Line: 37
// RVA: 0x163F20
void __fastcall UFG::qPidControllerCore::~qPidControllerCore(UFG::qPidControllerCore *this)
{
  UFG::qPidControllerCore *v1; // rbx
  UFG::qMemoryPool *v2; // rcx
  UFG::qMemoryPool *v3; // rcx
  UFG::qMemoryPool *v4; // rcx

  v1 = this;
  v2 = this->m_D_Term.m_pMemoryPool;
  if ( v2 )
    UFG::qMemoryPool::Free(v2, v1->m_D_Term.m_pBuffer);
  v3 = v1->m_I_Term.m_pMemoryPool;
  if ( v3 )
    UFG::qMemoryPool::Free(v3, v1->m_I_Term.m_pBuffer);
  v4 = v1->m_P_Term.m_pMemoryPool;
  if ( v4 )
    UFG::qMemoryPool::Free(v4, v1->m_P_Term.m_pBuffer);
}

// File Line: 42
// RVA: 0x17D0D0
void __fastcall UFG::qPidControllerCore::SetParameters(UFG::qPidControllerCore *this, UFG::qPidParameterBlock *parameters)
{
  float v2; // xmm1_4
  UFG::qPidControllerCore *v3; // rbx
  UFG::qPidParameterBlock *v4; // rdi

  v2 = parameters->m_ProportionalTimeSpan;
  v3 = this;
  this->m_Parameters = parameters;
  v4 = parameters;
  UFG::qAverageWindow<float>::SetTimespan(&this->m_P_Term, v2, 30.0);
  UFG::qAverageWindow<float>::SetTimespan(&v3->m_I_Term, v4->m_IntegralTimeSpan, 30.0);
  UFG::qAverageWindow<float>::SetTimespan(&v3->m_D_Term, v4->m_DerivativeTimeSpan, 30.0);
}

// File Line: 55
// RVA: 0x167DE0
void __fastcall UFG::qPidControllerCore::Clear(UFG::qPidControllerCore *this)
{
  UFG::qPidControllerCore *v1; // rbx

  v1 = this;
  *(_QWORD *)&this->m_P_Term.m_StartIndex = 0i64;
  this->m_P_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->m_P_Term.m_RunningSum, 0, 4u);
  *(_QWORD *)&v1->m_I_Term.m_StartIndex = 0i64;
  v1->m_I_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&v1->m_I_Term.m_RunningSum, 0, 4u);
  *(_QWORD *)&v1->m_D_Term.m_StartIndex = 0i64;
  v1->m_D_Term.m_RunningSumTime = 0.0;
  UFG::qMemSet(&v1->m_D_Term.m_RunningSum, 0, 4u);
}

// File Line: 80
// RVA: 0x179F80
void __fastcall UFG::qPidControllerCore::Record(UFG::qPidControllerCore *this, float error, float timestep, float *derivative_clamp)
{
  int v4; // eax
  float *v5; // rdi
  UFG::qPidControllerCore *v6; // rsi
  int v7; // edx
  int v8; // eax
  float v9; // xmm0_4
  int v10; // xmm6_4
  float dest; // [rsp+68h] [rbp+10h]

  v4 = this->m_P_Term.m_EndIndex;
  v5 = derivative_clamp;
  v6 = this;
  if ( this->m_P_Term.m_StartIndex != v4 && (v7 = this->m_P_Term.m_BufferSize) != 0 )
  {
    v8 = v4 - 1;
    if ( v8 < 0 )
      v8 = v7 - 1;
    v9 = this->m_P_Term.m_pBuffer[v8].m_Value;
  }
  else
  {
    UFG::qMemSet(&dest, 0, 4u);
    v9 = dest;
  }
  *(float *)&v10 = (float)(error - v9) / timestep;
  if ( v5 )
  {
    if ( *(float *)&v10 <= COERCE_FLOAT(*(_DWORD *)v5 ^ _xmm[0]) )
      v10 = *(_DWORD *)v5 ^ _xmm[0];
    if ( *(float *)&v10 >= *v5 )
      v10 = *(int *)v5;
  }
  UFG::qAverageWindow<float>::AddValue(&v6->m_P_Term, error, timestep);
  UFG::qAverageWindow<float>::AddValue(&v6->m_I_Term, error, timestep);
  UFG::qAverageWindow<float>::AddValue(&v6->m_D_Term, *(float *)&v10, timestep);
}

// File Line: 139
// RVA: 0x1715A0
float __fastcall UFG::qPidControllerCore::GetOutput(UFG::qPidControllerCore *this)
{
  float v1; // xmm0_4
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm4_4

  v1 = 0.0;
  if ( this->m_P_Term.m_StartIndex == this->m_P_Term.m_EndIndex )
  {
    v2 = 0.0;
  }
  else
  {
    v3 = this->m_P_Term.m_RunningSumTime;
    if ( v3 > 0.0 )
      v2 = this->m_P_Term.m_RunningSum / v3;
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

