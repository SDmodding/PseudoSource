// File Line: 14
// RVA: 0xEDD840
void __fastcall OSuite::ZOEdmClientConfiguration::ZOEdmClientConfiguration(OSuite::ZOEdmClientConfiguration *this)
{
  OSuite::ZOEdmBase::ZOEdmBase(this);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmClientConfiguration::`vftable;
  this->m_nMetricsThreshold = 0i64;
  this->m_nMetricsPriorityThreshold = 0i64;
  this->m_bUsageTrackingEnabled = 0;
  this->m_nUsageTrackingSamplingInterval = 0i64;
  this->m_nUsageTrackingMetricsInterval = 0i64;
}

// File Line: 25
// RVA: 0xEDD8B4
void __fastcall OSuite::ZOEdmClientConfiguration::ParseJsonValue(
        OSuite::ZOEdmClientConfiguration *this,
        OSuite::ZString *name,
        OSuite::ZJsonValue *pJson)
{
  OSuite::ZString v5; // [rsp+20h] [rbp-28h] BYREF

  v5.m_pString = 0i64;
  OSuite::ZString::ZString(&v5, &pJson->m_literal);
  if ( OSuite::ZString::operator==(name, "MetricsThreshold") )
  {
    this->m_nMetricsThreshold = OSuite::ZString::ToInt(&v5);
  }
  else if ( OSuite::ZString::operator==(name, "MetricsPriorityThreshold") )
  {
    this->m_nMetricsPriorityThreshold = OSuite::ZString::ToInt(&v5);
  }
  else if ( OSuite::ZString::operator==(name, "UsageTrackingEnabled") )
  {
    this->m_bUsageTrackingEnabled = OSuite::ZString::operator==(&v5, "true");
  }
  else if ( OSuite::ZString::operator==(name, "UsageTrackingSamplingInterval") )
  {
    this->m_nUsageTrackingSamplingInterval = OSuite::ZString::ToInt(&v5);
  }
  else if ( OSuite::ZString::operator==(name, "UsageTrackingMetricsInterval") )
  {
    this->m_nUsageTrackingMetricsInterval = OSuite::ZString::ToInt(&v5);
  }
  OSuite::ZString::~ZString(&v5);
}

