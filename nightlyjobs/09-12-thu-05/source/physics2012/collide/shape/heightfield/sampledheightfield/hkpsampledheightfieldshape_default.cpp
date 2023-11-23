// File Line: 14
// RVA: 0xD07250
void hkpSampledHeightField_registerAllRayCastFunctions(void)
{
  hkpSampledHeightFieldShape::s_rayCastFunc = hkpSampledHeightFieldShape::castRayDefault;
  hkpSampledHeightFieldShape::s_sphereCastFunc = hkpSampledHeightFieldShape::castSphereDefault;
}

// File Line: 21
// RVA: 0x15CC910
void dynamic_initializer_for__hkOptionalComponent_hkpSampledHeightField_AllCasts__()
{
  hkOptionalComponent::hkOptionalComponent(
    &hkOptionalComponent_hkpSampledHeightField_AllCasts,
    "hkpSampledHeightField_AllCasts",
    hkpSampledHeightField_registerAllRayCastFunctions);
}

// File Line: 28
// RVA: 0xD07210
void __fastcall hkpSampledHeightFieldShape::castRayDefault(
        hkpSampledHeightFieldShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  hkOptionalComponent_hkpSampledHeightField_AllCasts.m_isUsed.m_bool = 1;
  if ( this->m_coarseness > 0 )
    hkpSampledHeightFieldShape::castRayCoarseTree(this, input, cdBody, collector);
  else
    hkpSampledHeightFieldShape::castRayDda(this, input, cdBody, collector);
}

// File Line: 41
// RVA: 0xD07230
void __fastcall hkpSampledHeightFieldShape::castSphereDefault(
        hkpSampledHeightFieldShape *this,
        hkpHeightFieldShape::hkpSphereCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  hkOptionalComponent_hkpSampledHeightField_AllCasts.m_isUsed.m_bool = 1;
  if ( this->m_coarseness > 0 )
    hkpSampledHeightFieldShape::castSphereCoarseTree(this, input, cdBody, collector);
  else
    hkpSampledHeightFieldShape::castSphereDda(this, input, cdBody, collector);
}

