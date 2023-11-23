// File Line: 10
// RVA: 0xD6C4B0
float __fastcall hkContactPointMaterial::getFriction(hkContactPointMaterial *this)
{
  unsigned __int16 EncodedFloat; // ax
  float result; // xmm0_4

  EncodedFloat = hkUFloat8::getEncodedFloat(this->m_friction.m_value);
  if ( !EncodedFloat )
    return 0.0;
  LODWORD(result) = (EncodedFloat + 243712) << 12;
  return result;
}

// File Line: 54
// RVA: 0xD985F0
float __fastcall hkContactPointMaterial::getMaxImpulsePerStep(hkContactPointMaterial *this)
{
  unsigned __int16 EncodedFloat; // ax
  float result; // xmm0_4

  EncodedFloat = hkUFloat8::getEncodedFloat(this->m_maxImpulse.m_value);
  if ( !EncodedFloat )
    return 0.0;
  LODWORD(result) = (EncodedFloat + 243712) << 12;
  return result;
}

