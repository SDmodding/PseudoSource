// File Line: 106
// RVA: 0xB7AF50
_BOOL8 __fastcall hk1AxisSweep::IteratorAB::isValid(hk1AxisSweep::IteratorAB *this)
{
  return this->m_numA > 0 && this->m_numB > 0;
}

// File Line: 128
// RVA: 0xB7AF70
void __fastcall hk1AxisSweep::IteratorAB::next(hk1AxisSweep::IteratorAB *this)
{
  hk1AxisSweep::AabbInt *m_currentPtr; // rsi
  unsigned int m_aIsBigger; // ebp
  hk1AxisSweep::AabbInt *m_potentialPtr; // rbx
  unsigned int v5; // edx
  hk1AxisSweep::AabbInt **p_m_pb; // rax
  int *p_m_numB; // rax
  unsigned int v8; // eax

  ++this->m_potentialPtr;
  m_currentPtr = this->m_currentPtr;
  m_aIsBigger = this->m_aIsBigger;
  m_potentialPtr = this->m_potentialPtr;
  while ( 1 )
  {
    v5 = m_currentPtr->m_max[0];
    if ( m_potentialPtr->m_min[0] < v5 )
      break;
LABEL_5:
    p_m_pb = &this->m_pb;
    if ( !m_aIsBigger )
      p_m_pb = &this->m_pa;
    ++*p_m_pb;
    p_m_numB = &this->m_numB;
    if ( !m_aIsBigger )
      p_m_numB = &this->m_numA;
    --*p_m_numB;
    m_potentialPtr = this->m_pa;
    v8 = this->m_pb->m_min[0];
    m_aIsBigger = m_potentialPtr->m_min[0] > v8;
    if ( m_potentialPtr->m_min[0] <= v8 )
    {
      m_currentPtr = this->m_pa;
      m_potentialPtr = this->m_pb;
    }
    else
    {
      m_currentPtr = this->m_pb;
    }
    if ( !hk1AxisSweep::IteratorAB::isValid(this) )
      return;
  }
  while ( (((m_potentialPtr->m_max[2] - m_currentPtr->m_min[2]) | (m_potentialPtr->m_max[1] - m_currentPtr->m_min[1]) | (m_currentPtr->m_max[2] - m_potentialPtr->m_min[2]) | (m_currentPtr->m_max[1] - m_potentialPtr->m_min[1])) & 0x80000000) != 0 )
  {
    ++m_potentialPtr;
    if ( m_potentialPtr->m_min[0] >= v5 )
      goto LABEL_5;
  }
  this->m_potentialPtr = m_potentialPtr;
  this->m_currentPtr = m_currentPtr;
  this->m_aIsBigger = m_aIsBigger;
}

