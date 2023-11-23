// File Line: 78
// RVA: 0x44E990
void __fastcall UFG::qPidController::qPidController(UFG::qPidController *this)
{
  UFG::qPidControllerCore::qPidControllerCore(this);
  this->m_ParameterBlock.m_ProportionalTimeSpan = 0.016666668;
  this->m_ParameterBlock.m_DerivativeTimeSpan = 0.016666668;
  this->m_ParameterBlock.m_IntegralTimeSpan = 0.1;
  *(_QWORD *)&this->m_ParameterBlock.m_P_Coefficient = 0i64;
  this->m_ParameterBlock.m_D_Coefficient = 0.0;
  UFG::qPidController::SetMaxTimeSpans(this, 0.016666668, 0.016666668, 0.1);
  *(_QWORD *)&this->m_ParameterBlock.m_P_Coefficient = 0i64;
  this->m_ParameterBlock.m_D_Coefficient = 0.0;
  UFG::qPidControllerCore::Clear(this);
}

// File Line: 89
// RVA: 0x4752C0
void __fastcall UFG::qPidController::SetMaxTimeSpans(
        UFG::qPidController *this,
        double p_timespan,
        double i_timespan,
        double d_timespan)
{
  UFG::qAverageWindow<float>::SetMaxTimespan(&this->m_P_Term, p_timespan, 30.0);
  UFG::qAverageWindow<float>::SetMaxTimespan(&this->m_I_Term, i_timespan, 30.0);
  UFG::qAverageWindow<float>::SetMaxTimespan(&this->m_D_Term, d_timespan, 30.0);
  this->m_ParameterBlock.m_ProportionalTimeSpan = *(float *)&p_timespan;
  this->m_ParameterBlock.m_IntegralTimeSpan = *(float *)&i_timespan;
  this->m_ParameterBlock.m_DerivativeTimeSpan = *(float *)&d_timespan;
  UFG::qPidControllerCore::SetParameters(this, &this->m_ParameterBlock);
}

