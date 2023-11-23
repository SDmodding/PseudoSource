// File Line: 50
// RVA: 0xE0E100
hkUFloat8 *__fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtil::getMaxImpulseForContactPoint(
        hkpBreakOffPartsUtil::LimitContactImpulseUtil *this,
        hkUFloat8 *result,
        unsigned int key,
        hkpRigidBody *other)
{
  char v7; // al
  char m_value; // cl
  unsigned __int16 EncodedFloat; // ax
  float v10; // xmm0_4
  char v11; // cl
  float fv; // [rsp+40h] [rbp+18h] BYREF

  result->m_value = 0;
  if ( key == -1
    || (v7 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
               &this->m_shapeKeyToMaxImpulse.m_map,
               key,
               0i64),
        (result->m_value = v7) == 0) )
  {
    m_value = this->m_maxImpulse.m_value;
    if ( (unsigned __int8)(m_value - 1) > 0xFDu )
      return result;
    result->m_value = m_value;
  }
  if ( 1.0 != other->m_damageMultiplier )
  {
    EncodedFloat = hkUFloat8::getEncodedFloat(result->m_value);
    LODWORD(fv) = (EncodedFloat + 243712) << 12;
    if ( EncodedFloat )
      v10 = fv;
    else
      v10 = 0.0;
    fv = v10 / other->m_damageMultiplier;
    hkUFloat8::operator=(result, &fv);
    v11 = result->m_value;
    if ( !result->m_value )
      v11 = 1;
    result->m_value = v11;
  }
  return result;
}

