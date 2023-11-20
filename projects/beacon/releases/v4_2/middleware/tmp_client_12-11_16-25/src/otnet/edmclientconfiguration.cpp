// File Line: 14
// RVA: 0xEDD840
void __fastcall OSuite::ZOEdmClientConfiguration::ZOEdmClientConfiguration(OSuite::ZOEdmClientConfiguration *this)
{
  OSuite::ZOEdmClientConfiguration *v1; // rbx

  v1 = this;
  OSuite::ZOEdmBase::ZOEdmBase((OSuite::ZOEdmBase *)&this->vfptr);
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmClientConfiguration::`vftable;
  v1->m_nMetricsThreshold = 0i64;
  v1->m_nMetricsPriorityThreshold = 0i64;
  v1->m_bUsageTrackingEnabled = 0;
  v1->m_nUsageTrackingSamplingInterval = 0i64;
  v1->m_nUsageTrackingMetricsInterval = 0i64;
}

// File Line: 25
// RVA: 0xEDD8B4
void __fastcall OSuite::ZOEdmClientConfiguration::ParseJsonValue(OSuite::ZOEdmClientConfiguration *this, OSuite::ZString *name, OSuite::ZJsonValue *pJson)
{
  OSuite::ZString *v3; // rdi
  OSuite::ZOEdmClientConfiguration *v4; // rbx
  OSuite::ZString v5; // [rsp+20h] [rbp-28h]

  v5.m_pString = 0i64;
  v3 = name;
  v4 = this;
  OSuite::ZString::ZString(&v5, &pJson->m_literal);
  if ( OSuite::ZString::operator==(v3, "MetricsThreshold") )
  {
    v4->m_nMetricsThreshold = OSuite::ZString::ToInt(&v5);
  }
  else if ( OSuite::ZString::operator==(v3, "MetricsPriorityThreshold") )
  {
    v4->m_nMetricsPriorityThreshold = OSuite::ZString::ToInt(&v5);
  }
  else if ( OSuite::ZString::operator==(v3, "UsageTrackingEnabled") )
  {
    v4->m_bUsageTrackingEnabled = OSuite::ZString::operator==(&v5, "true");
  }
  else if ( OSuite::ZString::operator==(v3, "UsageTrackingSamplingInterval") )
  {
    v4->m_nUsageTrackingSamplingInterval = OSuite::ZString::ToInt(&v5);
  }
  else if ( OSuite::ZString::operator==(v3, "UsageTrackingMetricsInterval") )
  {
    v4->m_nUsageTrackingMetricsInterval = OSuite::ZString::ToInt(&v5);
  }
  OSuite::ZString::~ZString(&v5);
}

