// File Line: 12
// RVA: 0xD2FEE0
void __fastcall hkpFixedBufferCdPointCollector::reset(hkpFixedBufferCdPointCollector *this)
{
  this->m_numPoints.m_storage = 0;
  this->m_earlyOutDistance = 3.40282e38;
}

// File Line: 50
// RVA: 0xD2FED0
void __fastcall hkpFixedBufferCdPointCollector::addCdPoint(hkpFixedBufferCdPointCollector *this, hkpCdPoint *event)
{
  g_FixedBufferCdPointCollectorAddCdPointCallbackFunc(event, this);
}

