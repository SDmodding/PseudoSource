// File Line: 78
// RVA: 0x44E990
void __fastcall UFG::qPidController::qPidController(UFG::qPidController *this)
{
  UFG::qPidController *v1; // rbx

  v1 = this;
  UFG::qPidControllerCore::qPidControllerCore((UFG::qPidControllerCore *)&this->m_Parameters);
  v1->m_ParameterBlock.m_ProportionalTimeSpan = 0.016666668;
  v1->m_ParameterBlock.m_DerivativeTimeSpan = 0.016666668;
  v1->m_ParameterBlock.m_IntegralTimeSpan = 0.1;
  *(_QWORD *)&v1->m_ParameterBlock.m_P_Coefficient = 0i64;
  v1->m_ParameterBlock.m_D_Coefficient = 0.0;
  UFG::qPidController::SetMaxTimeSpans(v1, 0.016666668, 0.016666668, 0.1);
  *(_QWORD *)&v1->m_ParameterBlock.m_P_Coefficient = 0i64;
  v1->m_ParameterBlock.m_D_Coefficient = 0.0;
  UFG::qPidControllerCore::Clear((UFG::qPidControllerCore *)&v1->m_Parameters);
}

// File Line: 89
// RVA: 0x4752C0
void __fastcall UFG::qPidController::SetMaxTimeSpans(UFG::qPidController *this, float p_timespan, float i_timespan, float d_timespan)
{
  UFG::qPidController *v4; // rbx

  v4 = this;
  UFG::qAverageWindow<float>::SetMaxTimespan(&this->m_P_Term, p_timespan, 30.0);
  UFG::qAverageWindow<float>::SetMaxTimespan(&v4->m_I_Term, i_timespan, 30.0);
  UFG::qAverageWindow<float>::SetMaxTimespan(&v4->m_D_Term, d_timespan, 30.0);
  v4->m_ParameterBlock.m_ProportionalTimeSpan = p_timespan;
  v4->m_ParameterBlock.m_IntegralTimeSpan = i_timespan;
  v4->m_ParameterBlock.m_DerivativeTimeSpan = d_timespan;
  UFG::qPidControllerCore::SetParameters((UFG::qPidControllerCore *)&v4->m_Parameters, &v4->m_ParameterBlock);
}

