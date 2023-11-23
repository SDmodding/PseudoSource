// File Line: 16
// RVA: 0xD37360
void __fastcall hkpBoxBoxManifold::hkpBoxBoxManifold(hkpBoxBoxManifold *this)
{
  this->m_contactPoints[0].m_contactPointId = 0;
  this->m_contactPoints[1].m_contactPointId = 0;
  this->m_contactPoints[2].m_contactPointId = 0;
  this->m_contactPoints[3].m_contactPointId = 0;
  this->m_contactPoints[4].m_contactPointId = 0;
  this->m_contactPoints[5].m_contactPointId = 0;
  this->m_contactPoints[6].m_contactPointId = 0;
  *(_DWORD *)&this->m_contactPoints[7].m_contactPointId = 0;
  this->m_isComplete = 0;
}

// File Line: 26
// RVA: 0xD37390
__int64 __fastcall hkpBoxBoxManifold::addPoint(
        hkpBoxBoxManifold *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpFeatureContactPoint *fcp)
{
  unsigned __int8 m_numPoints; // al
  __int64 v6; // r10
  int v7; // eax
  __int64 v8; // rcx
  __int64 result; // rax

  m_numPoints = this->m_numPoints;
  if ( m_numPoints <= 8u )
  {
    v6 = m_numPoints;
    v7 = m_numPoints - 1;
    v8 = v7;
    if ( v7 < 0 )
    {
LABEL_6:
      if ( (int)v6 < 8 )
      {
        result = (unsigned int)v6;
        this->m_contactPoints[v6] = *fcp;
        ++this->m_numPoints;
        return result;
      }
    }
    else
    {
      while ( this->m_contactPoints[v8].m_featureIdA != fcp->m_featureIdA
           || this->m_contactPoints[v8].m_featureIdB != fcp->m_featureIdB )
      {
        if ( --v8 < 0 )
          goto LABEL_6;
      }
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 67
// RVA: 0xD373F0
void __fastcall hkpBoxBoxManifold::removePoint(hkpBoxBoxManifold *this, int i)
{
  __int64 m_numPoints; // rax

  m_numPoints = (unsigned __int8)this->m_numPoints;
  this->m_isComplete = 0;
  this->m_contactPoints[i] = this->m_contactPoints[m_numPoints - 1];
  --this->m_numPoints;
}

