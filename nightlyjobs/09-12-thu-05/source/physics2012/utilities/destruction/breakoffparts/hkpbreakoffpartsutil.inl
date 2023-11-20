// File Line: 50
// RVA: 0xE0E100
hkUFloat8 *__fastcall hkpBreakOffPartsUtil::LimitContactImpulseUtil::getMaxImpulseForContactPoint(hkpBreakOffPartsUtil::LimitContactImpulseUtil *this, hkUFloat8 *result, unsigned int key, hkpRigidBody *other)
{
  hkpRigidBody *v4; // rsi
  hkUFloat8 *v5; // rbx
  hkpBreakOffPartsUtil::LimitContactImpulseUtil *v6; // rdi
  char v7; // al
  char v8; // cl
  unsigned __int16 v9; // ax
  float v10; // xmm0_4
  char v11; // cl
  float fv; // [rsp+40h] [rbp+18h]

  v4 = other;
  v5 = result;
  v6 = this;
  result->m_value = 0;
  if ( key == -1
    || (v7 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
               (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_shapeKeyToMaxImpulse.m_map.m_elem,
               key,
               0i64),
        (v5->m_value = v7) == 0) )
  {
    v8 = v6->m_maxImpulse.m_value;
    if ( (unsigned __int8)(v8 - 1) > 0xFDu )
      return v5;
    v5->m_value = v8;
  }
  if ( 1.0 != v4->m_damageMultiplier )
  {
    v9 = hkUFloat8::getEncodedFloat(v5->m_value);
    LODWORD(fv) = (v9 + 243712) << 12;
    if ( v9 )
      v10 = fv;
    else
      v10 = 0.0;
    fv = v10 / v4->m_damageMultiplier;
    hkUFloat8::operator=(v5, &fv);
    v11 = v5->m_value;
    if ( v5->m_value < 1u )
      v11 = 1;
    v5->m_value = v11;
  }
  return v5;
}

