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
  hk1AxisSweep::AabbInt *v1; // rsi
  unsigned int v2; // ebp
  hk1AxisSweep::AabbInt *v3; // rbx
  hk1AxisSweep::IteratorAB *v4; // rdi
  unsigned int v5; // edx
  hk1AxisSweep::AabbInt **v6; // rax
  int *v7; // rax
  unsigned int v8; // eax

  ++this->m_potentialPtr;
  v1 = this->m_currentPtr;
  v2 = this->m_aIsBigger;
  v3 = this->m_potentialPtr;
  v4 = this;
  while ( 1 )
  {
    v5 = v1->m_max[0];
    if ( v3->m_min[0] < v5 )
      break;
LABEL_5:
    v6 = &v4->m_pb;
    if ( !v2 )
      v6 = &v4->m_pa;
    ++*v6;
    v7 = &v4->m_numB;
    if ( !v2 )
      v7 = &v4->m_numA;
    --*v7;
    v3 = v4->m_pa;
    v8 = v4->m_pb->m_min[0];
    v2 = v3->m_min[0] > v8;
    if ( v3->m_min[0] <= v8 )
    {
      v1 = v4->m_pa;
      v3 = v4->m_pb;
    }
    else
    {
      v1 = v4->m_pb;
    }
    if ( !(unsigned int)hk1AxisSweep::IteratorAB::isValid(v4) )
      return;
  }
  while ( (((v3->m_max[2] - v1->m_min[2]) | (v3->m_max[1] - v1->m_min[1]) | (v1->m_max[2] - v3->m_min[2]) | (v1->m_max[1] - v3->m_min[1])) & 0x80000000) != 0 )
  {
    ++v3;
    if ( v3->m_min[0] >= v5 )
      goto LABEL_5;
  }
  v4->m_potentialPtr = v3;
  v4->m_currentPtr = v1;
  v4->m_aIsBigger = v2;
}

