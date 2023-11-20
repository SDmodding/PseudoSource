// File Line: 24
// RVA: 0xD310C0
void __fastcall hkpFixedBufferRayHitCollector::addRayHit(hkpFixedBufferRayHitCollector *this, hkpCdBody *cdBody, hkpShapeRayCastCollectorOutput *hitInfo)
{
  g_FixedBufferRayHitCollectorAddRayHitCallbackFunc(cdBody, hitInfo, this);
}

