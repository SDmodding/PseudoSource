// File Line: 15
// RVA: 0xD0EA60
__int64 __fastcall hkpDefaultConvexListFilter::getConvexListCollisionType(hkpDefaultConvexListFilter *this, hkpCdBody *convexListBody, hkpCdBody *otherBody, hkpCollisionInput *input)
{
  return (input->m_dispatcher.m_storage->m_hasAlternateType[(unsigned __int8)otherBody->m_shape->m_type.m_storage] >> 22) & 1;
}

