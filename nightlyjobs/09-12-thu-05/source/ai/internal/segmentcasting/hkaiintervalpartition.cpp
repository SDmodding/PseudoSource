// File Line: 16
// RVA: 0x12E0A40
void __fastcall hkaiIntervalPartition::hkaiIntervalPartition(hkaiIntervalPartition *this)
{
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  this->m_intervals.m_capacityAndFlags = 0x80000000;
  this->m_intervals.m_data = 0i64;
  this->m_intervals.m_size = 0;
  hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_intervals.m_data, 16, 20);
}

// File Line: 21
// RVA: 0x12E0A90
void __fastcall hkaiIntervalPartition::reserve(hkaiIntervalPartition *this, int numIntervals)
{
  int v2; // eax
  int v3; // eax
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v2 = this->m_intervals.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v2 < numIntervals )
  {
    v3 = 2 * v2;
    if ( numIntervals < v3 )
      numIntervals = v3;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_intervals.m_data,
      numIntervals,
      20);
  }
}

// File Line: 26
// RVA: 0x12E0DF0
char __fastcall hkaiIntervalPartition::isOk(hkaiIntervalPartition *this)
{
  int m_size; // esi
  __int64 v2; // rbx
  int v4; // edi
  hkaiIntervalPartition::Interval *m_data; // r15
  hkaiIntervalPartition::Interval *i; // rax

  m_size = this->m_intervals.m_size;
  v2 = 0i64;
  v4 = 0;
  if ( m_size <= 0 )
  {
LABEL_5:
    if ( m_size - 1 <= 0 )
      return 1;
    for ( i = this->m_intervals.m_data + 1; i->m_leftX >= i[-1].m_rightX; ++i )
    {
      if ( ++v2 >= m_size - 1 )
        return 1;
    }
  }
  else
  {
    m_data = this->m_intervals.m_data;
    while ( hkaiIntervalPartition::Interval::isOk(&m_data[v4]) )
    {
      if ( ++v4 >= m_size )
        goto LABEL_5;
    }
  }
  return 0;
}

// File Line: 48
// RVA: 0x12E2C10
void __fastcall hkaiIntervalPartition::addRemovingDupes(
        hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *intervals,
        hkaiIntervalPartition::Interval *interval)
{
  float m_rightX; // xmm1_4
  int m_size; // r8d
  hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *v6; // rdx
  int v7; // eax
  hkaiIntervalPartition::Interval *m_data; // rcx
  hkaiIntervalPartition::Interval *v9; // rcx
  __int64 v10; // rdx

  m_rightX = interval->m_rightX;
  if ( interval->m_leftX != m_rightX )
  {
    m_size = intervals->m_size;
    if ( m_size )
    {
      v7 = m_size - 1;
      m_data = intervals->m_data;
      if ( interval->m_slope == intervals->m_data[m_size - 1].m_slope
        && interval->m_offset == m_data[v7].m_offset
        && interval->m_leftX == m_data[v7].m_rightX
        && m_data[m_size - 1].m_data == interval->m_data )
      {
        m_data[m_size - 1].m_rightX = m_rightX;
        return;
      }
      if ( m_size != (intervals->m_capacityAndFlags & 0x3FFFFFFF) )
        goto LABEL_13;
      v6 = intervals;
    }
    else
    {
      if ( (intervals->m_capacityAndFlags & 0x3FFFFFFF) != 0 )
      {
LABEL_13:
        v9 = intervals->m_data;
        v10 = intervals->m_size;
        v9[v10].m_leftX = interval->m_leftX;
        v9[v10].m_rightX = interval->m_rightX;
        v9[v10].m_slope = interval->m_slope;
        v9[v10].m_offset = interval->m_offset;
        v9[v10].m_data = interval->m_data;
        ++intervals->m_size;
        return;
      }
      v6 = intervals;
    }
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v6->m_data, 20);
    goto LABEL_13;
  }
}

// File Line: 83
// RVA: 0x12E3950
void __fastcall hkaiIntervalPartition::unionOne<1>(
        hkaiIntervalPartition *this,
        hkaiIntervalPartition::Interval *interval)
{
  int RightInterval; // eax
  __int64 v5; // r13
  int v6; // r14d
  __int64 v7; // r15
  unsigned __int64 i; // rdi
  hkaiIntervalPartition::Interval *m_data; // rsi
  float m_leftX; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  hkaiIntervalPartition::Interval *p_intervala; // rdx
  float v15; // xmm1_4
  unsigned int v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  unsigned int v20; // xmm0_4
  float m_rightX; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  unsigned int v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm8_4
  float v28; // xmm9_4
  unsigned int v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  unsigned int v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  hkaiIntervalPartition::Interval *v38; // rdx
  float v39; // xmm2_4
  int m_size; // ecx
  int v41; // r8d
  unsigned __int64 v42; // rax
  hkaiIntervalPartition::Interval *v43; // rcx
  unsigned __int64 v44; // rdx
  float v45; // xmm1_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  unsigned int v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  float m_slope; // xmm0_4
  float m_offset; // xmm1_4
  unsigned int v55; // xmm0_4
  float v56; // xmm1_4
  hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> intervals; // [rsp+30h] [rbp-D0h] BYREF
  hkaiIntervalPartition::Interval v58; // [rsp+40h] [rbp-C0h] BYREF
  hkaiIntervalPartition::Interval v59; // [rsp+58h] [rbp-A8h] BYREF
  hkaiIntervalPartition::Interval v60; // [rsp+70h] [rbp-90h] BYREF
  hkaiIntervalPartition::Interval intervala; // [rsp+88h] [rbp-78h] BYREF
  hkaiIntervalPartition::Interval other; // [rsp+A0h] [rbp-60h] BYREF
  float v63; // [rsp+B4h] [rbp-4Ch]
  unsigned int v64; // [rsp+B8h] [rbp-48h]
  int index; // [rsp+150h] [rbp+50h]

  RightInterval = hkaiIntervalPartition::findRightInterval(this, interval->m_leftX);
  index = RightInterval;
  if ( RightInterval == this->m_intervals.m_size )
  {
    hkaiIntervalPartition::addRemovingDupes(&this->m_intervals, interval);
    return;
  }
  v5 = RightInterval;
  intervals.m_capacityAndFlags = 0x80000000;
  v6 = RightInterval;
  v7 = RightInterval;
  intervals.m_data = 0i64;
  intervals.m_size = 0;
  for ( i = RightInterval; ; ++i )
  {
    m_data = this->m_intervals.m_data;
    m_leftX = this->m_intervals.m_data[i].m_leftX;
    if ( v7 == v5 )
      break;
    m_rightX = interval->m_rightX;
    if ( m_leftX > m_rightX )
    {
      v58.m_leftX = interval->m_leftX;
      m_slope = interval->m_slope;
      v58.m_rightX = m_rightX;
      m_offset = interval->m_offset;
      v58.m_slope = m_slope;
      v55 = interval->m_data;
      v58.m_offset = m_offset;
      v56 = m_data[i - 1].m_rightX;
      v58.m_data = v55;
      v58.m_leftX = v56;
      hkaiIntervalPartition::addRemovingDupes(&intervals, &v58);
      goto LABEL_28;
    }
    intervala.m_leftX = interval->m_leftX;
    v22 = interval->m_slope;
    intervala.m_rightX = m_rightX;
    p_intervala = &intervala;
    v23 = interval->m_offset;
    intervala.m_slope = v22;
    v24 = interval->m_data;
    intervala.m_offset = v23;
    v25 = m_data[i - 1].m_rightX;
    intervala.m_data = v24;
    intervala.m_leftX = v25;
    intervala.m_rightX = m_leftX;
LABEL_11:
    hkaiIntervalPartition::addRemovingDupes(&intervals, p_intervala);
    v26 = m_data[i].m_leftX;
    v27 = m_data[i].m_slope;
    v28 = interval->m_slope;
    v59.m_rightX = m_data[i].m_rightX;
    v29 = m_data[i].m_data;
    v59.m_leftX = v26;
    v30 = m_data[i].m_offset;
    v59.m_data = v29;
    v31 = interval->m_rightX;
    v59.m_offset = v30;
    v32 = interval->m_leftX;
    v60.m_rightX = v31;
    v33 = interval->m_data;
    v60.m_leftX = v32;
    v34 = interval->m_offset;
    v60.m_data = v33;
    v35 = m_data[i].m_leftX;
    v60.m_offset = v34;
    v36 = fmaxf(v35, interval->m_leftX);
    v37 = fminf(m_data[i].m_rightX, interval->m_rightX);
    v59.m_slope = v27;
    v60.m_rightX = v37;
    v59.m_rightX = v37;
    v60.m_slope = v28;
    v60.m_leftX = v36;
    v59.m_leftX = v36;
    if ( v27 == v28 )
    {
      v38 = &v60;
      if ( m_data[i].m_offset > interval->m_offset )
        v38 = &v59;
    }
    else
    {
      hkaiIntervalPartition::Interval::intersect(&v59, &other, (__int64)&v60);
      v39 = fminf(fmaxf(other.m_leftX, v36), v37);
      if ( v28 < v27 )
      {
        v60.m_rightX = v39;
        v59.m_leftX = fminf(fmaxf(other.m_leftX, v36), v37);
        hkaiIntervalPartition::addRemovingDupes(&intervals, &v60);
        v38 = &v59;
      }
      else
      {
        v60.m_leftX = v39;
        v59.m_rightX = fminf(fmaxf(other.m_leftX, v36), v37);
        hkaiIntervalPartition::addRemovingDupes(&intervals, &v59);
        v38 = &v60;
      }
    }
    hkaiIntervalPartition::addRemovingDupes(&intervals, v38);
    if ( m_data[i].m_rightX > interval->m_rightX )
    {
      v50 = m_data[i].m_rightX;
      v58.m_leftX = m_data[i].m_leftX;
      v51 = m_data[i].m_slope;
      v58.m_rightX = v50;
      v52 = m_data[i].m_offset;
      v58.m_slope = v51;
      v48 = m_data[i].m_data;
      v58.m_offset = v52;
      v49 = interval->m_rightX;
LABEL_25:
      v58.m_data = v48;
      v58.m_leftX = v49;
      hkaiIntervalPartition::addRemovingDupes(&intervals, &v58);
      ++v6;
LABEL_28:
      v41 = index;
      goto LABEL_29;
    }
    if ( v6 == this->m_intervals.m_size - 1 )
    {
      v45 = interval->m_rightX;
      v58.m_leftX = interval->m_leftX;
      v46 = interval->m_slope;
      v58.m_rightX = v45;
      v47 = interval->m_offset;
      v58.m_slope = v46;
      v48 = interval->m_data;
      v58.m_offset = v47;
      v49 = m_data[i].m_rightX;
      goto LABEL_25;
    }
    ++v6;
    ++v7;
  }
  if ( m_leftX < interval->m_rightX )
  {
    v11 = interval->m_leftX;
    if ( interval->m_leftX >= m_leftX )
    {
      v17 = m_data[i].m_rightX;
      v18 = m_data[i].m_slope;
      v58.m_leftX = this->m_intervals.m_data[i].m_leftX;
      p_intervala = &v58;
      v58.m_rightX = v17;
      v19 = m_data[i].m_offset;
      v58.m_slope = v18;
      v20 = m_data[i].m_data;
      v58.m_offset = v19;
      v58.m_rightX = v11;
      v58.m_data = v20;
    }
    else
    {
      v12 = interval->m_rightX;
      v13 = interval->m_slope;
      other.m_slope = interval->m_leftX;
      p_intervala = (hkaiIntervalPartition::Interval *)&other.m_slope;
      other.m_offset = v12;
      v15 = interval->m_offset;
      *(float *)&other.m_data = v13;
      v16 = interval->m_data;
      v63 = v15;
      other.m_offset = m_leftX;
      v64 = v16;
    }
    goto LABEL_11;
  }
  m_size = intervals.m_size;
  if ( intervals.m_size == (intervals.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&intervals.m_data, 20);
    m_size = intervals.m_size;
  }
  v41 = index;
  v42 = m_size;
  v43 = intervals.m_data;
  v44 = v42;
  v6 = index;
  intervals.m_data[v44].m_leftX = interval->m_leftX;
  v43[v44].m_rightX = interval->m_rightX;
  v43[v44].m_slope = interval->m_slope;
  v43[v44].m_offset = interval->m_offset;
  v43[v44].m_data = interval->m_data;
  ++intervals.m_size;
LABEL_29:
  hkArrayBase<hkaiIntervalPartition::Interval>::_spliceInto(
    &this->m_intervals,
    &hkContainerHeapAllocator::s_alloc,
    v41,
    v6 - v41,
    intervals.m_data,
    intervals.m_size);
  intervals.m_size = 0;
  if ( intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      intervals.m_data,
      20 * (intervals.m_capacityAndFlags & 0x3FFFFFFF));
}tr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      intervals.m_data,
      20 * (intervals.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 204
// RVA: 0x12E0DB0
hkaiIntervalPartition::Interval *__fastcall hkaiIntervalPartition::getInterval(hkaiIntervalPartition *this, int index)
{
  return &this->m_intervals.m_data[index];
}

// File Line: 209
// RVA: 0x12E0DD0
hkaiIntervalPartition::Interval *__fastcall hkaiIntervalPartition::accessInterval(
        hkaiIntervalPartition *this,
        int index)
{
  return &this->m_intervals.m_data[index];
}

// File Line: 214
// RVA: 0x12E0830
float __fastcall hkaiIntervalPartition::Interval::evaluateAt(hkaiIntervalPartition::Interval *this, float x)
{
  return (float)(x * this->m_slope) + this->m_offset;
}

// File Line: 220
// RVA: 0x12E0700
void __fastcall hkaiIntervalPartition::Interval::setFromEndpoints(
        hkaiIntervalPartition::Interval *this,
        hkVector2f *left,
        hkVector2f *right,
        unsigned int data)
{
  hkaiIntervalPartition::Interval::setFromEndpoints(this, left->x, left->y, right->x, right->y, data);
}

// File Line: 225
// RVA: 0x12E0740
void __fastcall hkaiIntervalPartition::Interval::setFromEndpoints(
        hkaiIntervalPartition::Interval *this,
        float leftX,
        float leftY,
        float rightX,
        float rightY,
        unsigned int data)
{
  float v6; // xmm0_4

  this->m_rightX = rightX;
  this->m_data = data;
  this->m_leftX = leftX;
  v6 = (float)(rightY - leftY) / (float)(rightX - leftX);
  this->m_slope = v6;
  this->m_offset = leftY - (float)(v6 * leftX);
}

// File Line: 238
// RVA: 0x12E07D0
hkVector2f __fastcall hkaiIntervalPartition::Interval::getLeftEndpoint(
        hkaiIntervalPartition::Interval *this,
        float *a2)
{
  float m_leftX; // xmm1_4
  float v4; // xmm0_4
  hkVector2f result; // rax

  m_leftX = this->m_leftX;
  *a2 = this->m_leftX;
  v4 = hkaiIntervalPartition::Interval::evaluateAt(this, m_leftX);
  result = (hkVector2f)a2;
  a2[1] = v4;
  return result;
}

// File Line: 247
// RVA: 0x12E0800
hkVector2f __fastcall hkaiIntervalPartition::Interval::getRightEndpoint(
        hkaiIntervalPartition::Interval *this,
        hkVector2f a2)
{
  float m_rightX; // xmm1_4
  float v4; // xmm0_4
  hkVector2f result; // rax

  m_rightX = this->m_rightX;
  **(float **)&a2 = m_rightX;
  v4 = hkaiIntervalPartition::Interval::evaluateAt(this, m_rightX);
  result = a2;
  *(float *)(*(_QWORD *)&a2 + 4i64) = v4;
  return result;
}

// File Line: 256
// RVA: 0x12E08A0
bool __fastcall hkaiIntervalPartition::Interval::isOk(hkaiIntervalPartition::Interval *this)
{
  return this->m_leftX <= this->m_rightX;
}

// File Line: 261
// RVA: 0x12E08C0
hkVector2f __fastcall hkaiIntervalPartition::Interval::intersect(
        hkaiIntervalPartition::Interval *this,
        hkaiIntervalPartition::Interval *other,
        __int64 a3)
{
  float v4; // xmm1_4
  float v5; // xmm0_4
  hkVector2f result; // rax

  v4 = (float)(*(float *)(a3 + 12) - this->m_offset) / (float)(this->m_slope - *(float *)(a3 + 8));
  other->m_leftX = v4;
  v5 = hkaiIntervalPartition::Interval::evaluateAt(this, v4);
  result = (hkVector2f)other;
  other->m_rightX = v5;
  return result;
}

// File Line: 272
// RVA: 0x12E0850
_BOOL8 __fastcall hkaiIntervalPartition::Interval::operator==(
        hkaiIntervalPartition::Interval *this,
        hkaiIntervalPartition::Interval *other)
{
  return other->m_leftX == this->m_leftX
      && other->m_rightX == this->m_rightX
      && other->m_slope == this->m_slope
      && other->m_offset == this->m_offset
      && this->m_data == other->m_data;
}

// File Line: 281
// RVA: 0x12E0900
void __fastcall hkaiIntervalPartition::Interval::shiftX(hkaiIntervalPartition::Interval *this, float shift)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float m_offset; // xmm0_4

  v4 = shift * this->m_slope;
  v5 = shift + this->m_rightX;
  this->m_leftX = shift + this->m_leftX;
  m_offset = this->m_offset;
  this->m_rightX = v5;
  this->m_offset = m_offset - v4;
}

// File Line: 288
// RVA: 0x12E0940
void __fastcall hkaiIntervalPartition::Interval::shiftY(hkaiIntervalPartition::Interval *this, float shift)
{
  this->m_offset = shift + this->m_offset;
}

// File Line: 293
// RVA: 0x12E0960
_BOOL8 __fastcall hkaiIntervalPartition::Interval::clampY(
        hkaiIntervalPartition::Interval *this,
        float front,
        float back)
{
  float m_slope; // xmm4_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float m_offset; // xmm0_4
  float m_rightX; // [rsp+10h] [rbp+10h]
  float v13; // [rsp+20h] [rbp+20h]

  if ( front >= back )
    return 0i64;
  m_slope = this->m_slope;
  if ( m_slope > 0.0 )
  {
    v5 = 1.0 / m_slope;
    v6 = (float)(front - this->m_offset) * (float)(1.0 / m_slope);
LABEL_6:
    v13 = (float)(back - this->m_offset) * v5;
    v8 = fminf(fmaxf(this->m_leftX, v6), v13);
    m_rightX = this->m_rightX;
    this->m_leftX = v8;
    v9 = fminf(fmaxf(m_rightX, v6), v13);
    this->m_rightX = v9;
    return v9 > v8;
  }
  if ( m_slope < 0.0 )
  {
    v5 = 1.0 / m_slope;
    v7 = back;
    back = front;
    v6 = (float)(v7 - this->m_offset) * v5;
    goto LABEL_6;
  }
  m_offset = this->m_offset;
  return m_offset >= front && m_offset < back;
}

// File Line: 323
// RVA: 0x12E2D10
_BOOL8 __fastcall hkaiIntervalPartition::Interval::clampFunc<0>(
        hkaiIntervalPartition::Interval *this,
        float slope,
        float offset)
{
  float m_leftX; // xmm7_4
  float v5; // xmm0_4
  float m_rightX; // xmm8_4
  bool v7; // di
  float v9; // [rsp+80h] [rbp+18h]

  m_leftX = this->m_leftX;
  v5 = hkaiIntervalPartition::Interval::evaluateAt(this, this->m_leftX);
  m_rightX = this->m_rightX;
  v7 = v5 > (float)((float)(m_leftX * slope) + offset);
  if ( v7 == hkaiIntervalPartition::Interval::evaluateAt(this, m_rightX) > (float)((float)(m_rightX * slope) + offset) )
    return v7;
  v9 = (float)(offset - this->m_offset) / (float)(this->m_slope - slope);
  if ( v7 )
    this->m_rightX = fminf(m_rightX, v9);
  else
    this->m_leftX = fmaxf(m_leftX, v9);
  return this->m_leftX < this->m_rightX;
}

// File Line: 358
// RVA: 0x12E0E90
void __fastcall hkaiIntervalPartition::appendInterval(
        hkaiIntervalPartition *this,
        hkaiIntervalPartition::Interval *interval)
{
  hkaiIntervalPartition::Interval *v4; // rdx

  if ( this->m_intervals.m_size == (this->m_intervals.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_intervals.m_data, 20);
  v4 = &this->m_intervals.m_data[this->m_intervals.m_size];
  v4->m_leftX = interval->m_leftX;
  v4->m_rightX = interval->m_rightX;
  v4->m_slope = interval->m_slope;
  v4->m_offset = interval->m_offset;
  v4->m_data = interval->m_data;
  ++this->m_intervals.m_size;
}

// File Line: 365
// RVA: 0x12E10B0
__int64 __fastcall hkaiIntervalPartition::findLeftInterval(hkaiIntervalPartition *this, float x)
{
  int m_size; // r9d
  int v3; // r8d

  m_size = this->m_intervals.m_size;
  v3 = -1;
  while ( v3 < m_size - 1 )
  {
    if ( x < this->m_intervals.m_data[(m_size + v3) / 2].m_leftX )
      m_size = (m_size + v3) / 2;
    else
      v3 = (m_size + v3) / 2;
  }
  return (unsigned int)v3;
}

// File Line: 388
// RVA: 0x12E1100
__int64 __fastcall hkaiIntervalPartition::findRightInterval(hkaiIntervalPartition *this, float x)
{
  unsigned int m_size; // r8d
  int v3; // r9d

  m_size = this->m_intervals.m_size;
  v3 = -1;
  while ( v3 < (int)(m_size - 1) )
  {
    if ( x < this->m_intervals.m_data[(int)(m_size + v3) / 2].m_rightX )
      m_size = (int)(m_size + v3) / 2;
    else
      v3 = (int)(m_size + v3) / 2;
  }
  return m_size;
}

// File Line: 411
// RVA: 0x12E1070
int __fastcall hkaiIntervalPartition::findInterval(hkaiIntervalPartition *this, float x)
{
  int result; // eax

  result = hkaiIntervalPartition::findLeftInterval(this, x);
  if ( result < 0 || x >= this->m_intervals.m_data[result].m_rightX )
    return -1;
  return result;
}

// File Line: 417
// RVA: 0x12E1150
__int64 __fastcall hkaiIntervalPartition::equals(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  int m_size; // edi
  int v4; // ebx
  hkaiIntervalPartition::Interval *m_data; // rsi
  hkaiIntervalPartition::Interval *v6; // r14

  m_size = this->m_intervals.m_size;
  if ( m_size != other->m_intervals.m_size )
    return 0i64;
  v4 = 0;
  if ( m_size <= 0 )
    return 1i64;
  m_data = other->m_intervals.m_data;
  v6 = this->m_intervals.m_data;
  while ( hkaiIntervalPartition::Interval::operator==(&v6[v4], &m_data[v4]) )
  {
    if ( ++v4 >= m_size )
      return 1i64;
  }
  return 0i64;
}

// File Line: 435
// RVA: 0x12E1020
void __fastcall hkaiIntervalPartition::appendIntervalFromEndpoints(
        hkaiIntervalPartition *this,
        float leftX,
        float leftY,
        float rightX,
        float rightY,
        unsigned int data)
{
  hkaiIntervalPartition::Interval interval; // [rsp+30h] [rbp-28h] BYREF

  hkaiIntervalPartition::Interval::setFromEndpoints(&interval, leftX, leftY, rightX, rightY, data);
  hkaiIntervalPartition::appendInterval(this, &interval);
}

// File Line: 443
// RVA: 0x12E0AE0
void __fastcall hkaiIntervalPartition::shiftX(hkaiIntervalPartition *this, float shift)
{
  int m_size; // eax
  __int64 v4; // rdi
  __int64 v5; // rbx

  m_size = this->m_intervals.m_size;
  if ( m_size > 0 )
  {
    v4 = (unsigned int)m_size;
    v5 = 0i64;
    do
    {
      hkaiIntervalPartition::Interval::shiftX(&this->m_intervals.m_data[v5++], shift);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 451
// RVA: 0x12E0B50
void __fastcall hkaiIntervalPartition::shiftY(hkaiIntervalPartition *this, float shift)
{
  int m_size; // eax
  __int64 v4; // rdi
  __int64 v5; // rbx

  m_size = this->m_intervals.m_size;
  if ( m_size > 0 )
  {
    v4 = (unsigned int)m_size;
    v5 = 0i64;
    do
    {
      hkaiIntervalPartition::Interval::shiftY(&this->m_intervals.m_data[v5++], shift);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 459
// RVA: 0x12E0BC0
void __fastcall hkaiIntervalPartition::clear(hkaiIntervalPartition *this)
{
  this->m_intervals.m_size = 0;
}

// File Line: 464
// RVA: 0x12E0BD0
void __fastcall hkaiIntervalPartition::clipX(hkaiIntervalPartition *this, float left, float right)
{
  int v4; // r9d
  __int64 v5; // rcx
  __int64 m_size; // r11
  hkaiIntervalPartition::Interval *m_data; // r8
  float *p_m_rightX; // rax
  int v9; // r11d
  hkaiIntervalPartition::Interval *v10; // r9
  signed __int64 v11; // r9
  __int64 v12; // rcx
  unsigned int v13; // eax
  __int64 v14; // r8
  __int64 v15; // rax

  v4 = 0;
  v5 = 0i64;
  m_size = this->m_intervals.m_size;
  if ( (int)m_size <= 0 )
    goto LABEL_5;
  m_data = this->m_intervals.m_data;
  p_m_rightX = &this->m_intervals.m_data->m_rightX;
  while ( left >= *p_m_rightX )
  {
    ++v5;
    ++v4;
    p_m_rightX += 5;
    if ( v5 >= m_size )
      goto LABEL_5;
  }
  if ( v4 < 0 )
  {
LABEL_5:
    this->m_intervals.m_size = 0;
  }
  else
  {
    if ( v4 > 0 )
    {
      v9 = m_size - v4;
      this->m_intervals.m_size = v9;
      v10 = &m_data[v4];
      if ( 20 * v9 > 0 )
      {
        v11 = (char *)v10 - (char *)m_data;
        v12 = ((unsigned int)(20 * v9 - 1) >> 2) + 1;
        do
        {
          v13 = *(_DWORD *)((char *)&m_data->m_leftX + v11);
          m_data = (hkaiIntervalPartition::Interval *)((char *)m_data + 4);
          m_data[-1].m_data = v13;
          --v12;
        }
        while ( v12 );
      }
    }
    if ( this->m_intervals.m_size )
    {
      this->m_intervals.m_data->m_leftX = fmaxf(left, this->m_intervals.m_data->m_leftX);
      if ( this->m_intervals.m_size )
      {
        do
        {
          v14 = this->m_intervals.m_size;
          if ( right > this->m_intervals.m_data[v14 - 1].m_leftX )
            break;
          this->m_intervals.m_size = v14 - 1;
        }
        while ( (_DWORD)v14 != 1 );
      }
    }
    v15 = this->m_intervals.m_size;
    if ( (_DWORD)v15 )
      this->m_intervals.m_data[v15 - 1].m_rightX = fminf(right, this->m_intervals.m_data[v15 - 1].m_rightX);
  }
}

// File Line: 502
// RVA: 0x12E0CE0
void __fastcall hkaiIntervalPartition::clipY(hkaiIntervalPartition *this, float front, float back)
{
  __int64 m_size; // r14
  int v4; // ebp
  int v6; // esi
  __int64 v7; // rdi
  __int64 v8; // rbx
  hkaiIntervalPartition::Interval *m_data; // rcx

  m_size = this->m_intervals.m_size;
  v4 = 0;
  v6 = 0;
  if ( m_size <= 0 )
  {
    this->m_intervals.m_size = 0;
  }
  else
  {
    v7 = 0i64;
    v8 = 0i64;
    do
    {
      if ( hkaiIntervalPartition::Interval::clampY(&this->m_intervals.m_data[v6], front, back) )
      {
        m_data = this->m_intervals.m_data;
        ++v4;
        m_data[v7++].m_leftX = this->m_intervals.m_data[v8].m_leftX;
        m_data[v7 - 1].m_rightX = m_data[v8].m_rightX;
        m_data[v7 - 1].m_slope = m_data[v8].m_slope;
        m_data[v7 - 1].m_offset = m_data[v8].m_offset;
        m_data[v7 - 1].m_data = m_data[v8].m_data;
      }
      ++v6;
      ++v8;
      --m_size;
    }
    while ( m_size );
    this->m_intervals.m_size = v4;
  }
}

// File Line: 517
// RVA: 0x12E2E10
void __fastcall hkaiIntervalPartition::clipFunc<0>(hkaiIntervalPartition *this, float slope, float offset)
{
  __int64 m_size; // r14
  int v4; // ebp
  int v6; // esi
  __int64 v7; // rdi
  __int64 v8; // rbx
  hkaiIntervalPartition::Interval *m_data; // rcx

  m_size = this->m_intervals.m_size;
  v4 = 0;
  v6 = 0;
  if ( m_size <= 0 )
  {
    this->m_intervals.m_size = 0;
  }
  else
  {
    v7 = 0i64;
    v8 = 0i64;
    do
    {
      if ( hkaiIntervalPartition::Interval::clampFunc<0>(&this->m_intervals.m_data[v6], slope, offset) )
      {
        m_data = this->m_intervals.m_data;
        ++v4;
        m_data[v7++].m_leftX = this->m_intervals.m_data[v8].m_leftX;
        m_data[v7 - 1].m_rightX = m_data[v8].m_rightX;
        m_data[v7 - 1].m_slope = m_data[v8].m_slope;
        m_data[v7 - 1].m_offset = m_data[v8].m_offset;
        m_data[v7 - 1].m_data = m_data[v8].m_data;
      }
      ++v6;
      ++v8;
      --m_size;
    }
    while ( m_size );
    this->m_intervals.m_size = v4;
  }
}

// File Line: 535
// RVA: 0x12E2EE0
void __fastcall hkaiIntervalPartition::combine<0,0>(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  int m_size; // eax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v4; // r13
  int m_capacityAndFlags; // ecx
  __int64 v6; // rax
  char *m_data; // rcx
  __int64 v8; // r8
  signed __int64 v9; // rdx
  int v10; // eax
  __int64 v11; // rsi
  __int64 v12; // r15
  int v13; // r9d
  int v14; // r14d
  int v15; // edi
  float *p_m_fromOffset; // rax
  __int64 v17; // r12
  float v18; // xmm1_4
  __int128 v19; // xmm7
  __int128 v20; // xmm9
  unsigned int v21; // xmm0_4
  unsigned int *v22; // rax
  __int64 v23; // rbx
  __int64 v24; // rsi
  __int128 m_leftX_low; // xmm6
  __int128 m_rightX_low; // xmm8
  float v27; // xmm0_4
  float v28; // xmm1_4
  unsigned int v29; // xmm0_4
  hkRelocationInfo::Import *v30; // rax
  float v31; // xmm1_4
  hkaiIntervalPartition::Interval *v32; // rax
  float m_offset; // xmm1_4
  char v34; // r13
  float m_slope; // xmm10_4
  float v36; // xmm11_4
  hkaiIntervalPartition::Interval *v37; // rdx
  char v38; // cl
  bool v39; // zf
  hkaiIntervalPartition::Interval *v40; // rax
  float v41; // xmm1_4
  hkaiIntervalPartition::Interval *v42; // rax
  float v43; // xmm1_4
  int v44; // ebx
  int i; // r14d
  int v46; // ebx
  int v47; // edi
  hkaiIntervalPartition *v48; // r13
  hkArrayBase<hkaiIntervalPartition::Interval> array; // [rsp+30h] [rbp-D0h] BYREF
  hkaiIntervalPartition::Interval interval; // [rsp+40h] [rbp-C0h] BYREF
  hkaiIntervalPartition::Interval v51; // [rsp+58h] [rbp-A8h] BYREF
  hkaiIntervalPartition::Interval v52; // [rsp+70h] [rbp-90h] BYREF
  hkaiIntervalPartition::Interval v53; // [rsp+88h] [rbp-78h] BYREF
  int v54; // [rsp+A0h] [rbp-60h]
  __int64 v55; // [rsp+A8h] [rbp-58h]
  hkaiIntervalPartition::Interval v56; // [rsp+B0h] [rbp-50h] BYREF
  hkaiIntervalPartition::Interval othera[2]; // [rsp+C8h] [rbp-38h] BYREF
  hkaiIntervalPartition *v58; // [rsp+1A0h] [rbp+A0h] BYREF
  hkaiIntervalPartition *v59; // [rsp+1A8h] [rbp+A8h]
  hkResult result; // [rsp+1B0h] [rbp+B0h] BYREF
  int v61; // [rsp+1B8h] [rbp+B8h]

  v59 = other;
  v58 = this;
  m_size = this->m_intervals.m_size;
  v4 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this;
  v61 = m_size;
  if ( !m_size )
  {
    m_capacityAndFlags = this->m_intervals.m_capacityAndFlags;
    if ( (m_capacityAndFlags & 0x3FFFFFFF) < other->m_intervals.m_size )
    {
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v4->m_data,
          20 * (m_capacityAndFlags & 0x3FFFFFFF));
      LODWORD(v58) = 20 * other->m_intervals.m_size;
      v4->m_data = (hkRelocationInfo::Import *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                 &hkContainerHeapAllocator::s_alloc,
                                                 &v58);
      v4->m_capacityAndFlags = (int)v58 / 20;
    }
    v6 = other->m_intervals.m_size;
    m_data = (char *)v4->m_data;
    v4->m_size = v6;
    v8 = v6;
    if ( (int)v6 > 0 )
    {
      v9 = (char *)other->m_intervals.m_data - m_data;
      do
      {
        v10 = *(_DWORD *)&m_data[v9];
        m_data += 20;
        *((_DWORD *)m_data - 5) = v10;
        *((_DWORD *)m_data - 4) = *(_DWORD *)&m_data[v9 - 16];
        *((_DWORD *)m_data - 3) = *(_DWORD *)&m_data[v9 - 12];
        *((_DWORD *)m_data - 2) = *(_DWORD *)&m_data[v9 - 8];
        *((_DWORD *)m_data - 1) = *(_DWORD *)&m_data[v9 - 4];
        --v8;
      }
      while ( v8 );
    }
    return;
  }
  v11 = other->m_intervals.m_size;
  v54 = v11;
  if ( !(_DWORD)v11 )
    return;
  v12 = 0i64;
  v13 = 2 * (v11 + m_size);
  array.m_capacityAndFlags = 0x80000000;
  v14 = 0;
  v15 = 0;
  array.m_data = 0i64;
  array.m_size = 0;
  if ( v13 > 0 )
  {
    if ( (((_DWORD)v11 + m_size) & 0x40000000) != 0 )
      v13 = 0;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v13, 20);
  }
  hkArrayBase<hkaiIntervalPartition::Interval>::_append(
    &array,
    &hkContainerHeapAllocator::s_alloc,
    (hkaiIntervalPartition::Interval *)v4->m_data,
    v4->m_size);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array,
    v4);
  p_m_fromOffset = (float *)&v4->m_data->m_fromOffset;
  array.m_size = 0;
  v55 = v11;
  v17 = 0i64;
  v18 = p_m_fromOffset[3];
  v19 = *(unsigned int *)p_m_fromOffset;
  v20 = *((unsigned int *)p_m_fromOffset + 1);
  interval.m_slope = p_m_fromOffset[2];
  v21 = *((_DWORD *)p_m_fromOffset + 4);
  v22 = (unsigned int *)other->m_intervals.m_data;
  v23 = 0i64;
  v24 = 0i64;
  m_leftX_low = *v22;
  m_rightX_low = v22[1];
  interval.m_data = v21;
  v27 = *((float *)v22 + 2);
  interval.m_offset = v18;
  v28 = *((float *)v22 + 3);
  v51.m_slope = v27;
  v29 = v22[4];
  LODWORD(v51.m_leftX) = m_leftX_low;
  v51.m_data = v29;
  LODWORD(v51.m_rightX) = m_rightX_low;
  v51.m_offset = v28;
  while ( 2 )
  {
    LODWORD(interval.m_rightX) = v20;
    LODWORD(interval.m_leftX) = v19;
    while ( 1 )
    {
      while ( *(float *)&v19 >= *(float *)&m_leftX_low )
      {
        if ( *(float *)&m_leftX_low >= *(float *)&v19 )
          goto LABEL_27;
        if ( *(float *)&m_rightX_low >= *(float *)&v19 )
        {
          othera[0].m_slope = v51.m_leftX;
          *(_QWORD *)&othera[0].m_data = *(_QWORD *)&v51.m_slope;
          LODWORD(othera[0].m_offset) = v19;
          LODWORD(othera[1].m_rightX) = v51.m_data;
          hkaiIntervalPartition::addRemovingDupes(
            (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
            (hkaiIntervalPartition::Interval *)&othera[0].m_slope);
          m_leftX_low = v19;
          LODWORD(v51.m_leftX) = v19;
          goto LABEL_27;
        }
        hkaiIntervalPartition::addRemovingDupes(
          (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
          &v51);
        ++v12;
        ++v15;
        ++v23;
        if ( v12 == v55 )
          goto LABEL_55;
        v32 = v59->m_intervals.m_data;
        m_leftX_low = LODWORD(v59->m_intervals.m_data[v23].m_leftX);
        m_rightX_low = LODWORD(v59->m_intervals.m_data[v23].m_rightX);
        m_offset = v59->m_intervals.m_data[v23].m_offset;
        v51.m_slope = v59->m_intervals.m_data[v23].m_slope;
        v51.m_data = v32[v23].m_data;
        LODWORD(v51.m_leftX) = m_leftX_low;
        LODWORD(v51.m_rightX) = m_rightX_low;
        v51.m_offset = m_offset;
      }
      if ( *(float *)&v20 < *(float *)&m_leftX_low )
        break;
      v56.m_leftX = interval.m_leftX;
      *(_QWORD *)&v56.m_slope = *(_QWORD *)&interval.m_slope;
      LODWORD(v56.m_rightX) = m_leftX_low;
      v56.m_data = interval.m_data;
      hkaiIntervalPartition::addRemovingDupes(
        (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
        &v56);
      v19 = m_leftX_low;
      LODWORD(interval.m_leftX) = m_leftX_low;
LABEL_27:
      v34 = 0;
      v52 = interval;
      LOBYTE(result.m_enum) = 0;
      v53 = v51;
      if ( *(float *)&v20 >= *(float *)&m_rightX_low )
      {
        if ( *(float *)&m_rightX_low >= *(float *)&v20 )
        {
          v34 = 1;
          LOBYTE(result.m_enum) = 1;
        }
        else
        {
          v19 = m_rightX_low;
          LODWORD(v52.m_rightX) = m_rightX_low;
          LOBYTE(result.m_enum) = 1;
          LODWORD(interval.m_leftX) = m_rightX_low;
        }
      }
      else
      {
        m_leftX_low = v20;
        LODWORD(v53.m_rightX) = v20;
        v34 = 1;
        LODWORD(v51.m_leftX) = v20;
      }
      m_slope = v52.m_slope;
      v36 = v53.m_slope;
      if ( v52.m_slope == v53.m_slope )
      {
        v37 = &v52;
        if ( v53.m_offset <= v52.m_offset )
          v37 = &v53;
      }
      else
      {
        hkaiIntervalPartition::Interval::intersect(&v52, othera, (__int64)&v53);
        if ( othera[0].m_leftX >= v52.m_leftX )
        {
          if ( othera[0].m_leftX <= v52.m_rightX )
          {
            if ( m_slope >= v36 )
            {
              v52.m_rightX = othera[0].m_leftX;
              v53.m_leftX = othera[0].m_leftX;
              hkaiIntervalPartition::addRemovingDupes(
                (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
                &v52);
              v37 = &v53;
            }
            else
            {
              v52.m_leftX = othera[0].m_leftX;
              v53.m_rightX = othera[0].m_leftX;
              hkaiIntervalPartition::addRemovingDupes(
                (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
                &v53);
              v37 = &v52;
            }
          }
          else
          {
            v37 = &v53;
            if ( v36 <= m_slope )
              v37 = &v52;
          }
        }
        else
        {
          v37 = &v52;
          if ( v36 <= m_slope )
            v37 = &v53;
        }
      }
      hkaiIntervalPartition::addRemovingDupes(
        (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
        v37);
      v38 = 0;
      v39 = v34 == 0;
      v4 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v58;
      if ( !v39 )
      {
        ++v17;
        ++v14;
        ++v24;
        if ( v17 == v61 )
        {
          v38 = 1;
        }
        else
        {
          v40 = v58->m_intervals.m_data;
          v19 = LODWORD(v58->m_intervals.m_data[v24].m_leftX);
          v20 = LODWORD(v58->m_intervals.m_data[v24].m_rightX);
          v41 = v58->m_intervals.m_data[v24].m_offset;
          interval.m_slope = v58->m_intervals.m_data[v24].m_slope;
          interval.m_data = v40[v24].m_data;
          LODWORD(interval.m_leftX) = v19;
          LODWORD(interval.m_rightX) = v20;
          interval.m_offset = v41;
        }
      }
      if ( LOBYTE(result.m_enum) )
      {
        ++v12;
        ++v15;
        ++v23;
        if ( v12 == v55 )
          goto LABEL_55;
        v42 = v59->m_intervals.m_data;
        m_leftX_low = LODWORD(v59->m_intervals.m_data[v23].m_leftX);
        m_rightX_low = LODWORD(v59->m_intervals.m_data[v23].m_rightX);
        v43 = v59->m_intervals.m_data[v23].m_offset;
        v51.m_slope = v59->m_intervals.m_data[v23].m_slope;
        v51.m_data = v42[v23].m_data;
        LODWORD(v51.m_leftX) = m_leftX_low;
        LODWORD(v51.m_rightX) = m_rightX_low;
        v51.m_offset = v43;
      }
      if ( v38 )
        goto LABEL_55;
    }
    hkaiIntervalPartition::addRemovingDupes(
      (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
      &interval);
    ++v17;
    ++v14;
    ++v24;
    if ( v17 != v61 )
    {
      v30 = v4->m_data;
      v31 = *(float *)((char *)&v4->m_data->m_identifier + v24 * 20 + 4);
      v19 = *(unsigned int *)((char *)&v4->m_data->m_fromOffset + v24 * 20);
      v20 = *(unsigned int *)((char *)&v4->m_data->m_fromOffset + v24 * 20 + 4);
      interval.m_slope = *(float *)((char *)&v4->m_data->m_identifier + v24 * 20);
      interval.m_data = *(int *)((char *)&v30[1].m_fromOffset + v24 * 20);
      interval.m_offset = v31;
      continue;
    }
    break;
  }
LABEL_55:
  v44 = v61;
  if ( v14 < v61 )
  {
    hkaiIntervalPartition::addRemovingDupes(
      (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
      &interval);
    for ( i = v14 + 1; i != v44; ++i )
      hkaiIntervalPartition::addRemovingDupes(
        (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
        (hkaiIntervalPartition::Interval *)v4->m_data + i);
  }
  v46 = v54;
  if ( v15 < v54 )
  {
    hkaiIntervalPartition::addRemovingDupes(
      (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
      &v51);
    v47 = v15 + 1;
    if ( v47 != v46 )
    {
      v48 = v59;
      do
        hkaiIntervalPartition::addRemovingDupes(
          (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
          &v48->m_intervals.m_data[v47++]);
      while ( v47 != v46 );
      v4 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v58;
    }
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    v4,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      20 * (array.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 752
// RVA: 0x12E11D0
void __fastcall hkaiIntervalPartition::clipMin(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  __int64 m_size; // r13
  hkaiIntervalPartition *v3; // r12
  hkaiIntervalPartition *v4; // rbx
  __int64 v5; // rdi
  int v6; // r9d
  int v7; // esi
  unsigned int *m_data; // rax
  __int64 *v9; // rcx
  __int64 v10; // r15
  float v11; // xmm0_4
  float v12; // xmm1_4
  __int128 m_leftX_low; // xmm7
  hkaiIntervalPartition *v14; // r14
  __int128 m_rightX_low; // xmm9
  unsigned int v16; // xmm0_4
  _DWORD *v17; // rax
  __int128 v18; // xmm6
  __int128 v19; // xmm8
  unsigned int v20; // xmm0_4
  unsigned int v21; // xmm0_4
  hkaiIntervalPartition *v22; // rax
  __int64 v23; // rbx
  hkaiIntervalPartition::Interval *v24; // rax
  float v25; // xmm1_4
  unsigned int v26; // xmm0_4
  __int64 v27; // rax
  int v28; // xmm1_4
  unsigned int v29; // xmm0_4
  char v30; // r12
  char v31; // r13
  float v32; // xmm10_4
  float v33; // xmm11_4
  char v34; // cl
  bool v35; // zf
  hkaiIntervalPartition::Interval *v36; // rax
  float m_offset; // xmm1_4
  __int64 v38; // rax
  unsigned int v39; // xmm1_4
  int i; // esi
  hkaiIntervalPartition::Interval interval; // [rsp+30h] [rbp-B8h] BYREF
  hkArrayBase<hkaiIntervalPartition::Interval> array; // [rsp+48h] [rbp-A0h] BYREF
  unsigned __int64 v43; // [rsp+58h] [rbp-90h]
  unsigned __int64 v44; // [rsp+60h] [rbp-88h]
  unsigned int v45; // [rsp+68h] [rbp-80h]
  char v46[24]; // [rsp+70h] [rbp-78h] BYREF
  unsigned int v47; // [rsp+88h] [rbp-60h]
  hkaiIntervalPartition::Interval othera[3]; // [rsp+90h] [rbp-58h] BYREF
  hkaiIntervalPartition *v49; // [rsp+168h] [rbp+80h]
  unsigned int **vars0; // [rsp+170h] [rbp+88h]
  void *retaddr; // [rsp+178h] [rbp+90h]
  hkaiIntervalPartition *result; // [rsp+180h] [rbp+98h] BYREF
  hkaiIntervalPartition *v53; // [rsp+188h] [rbp+A0h]

  v53 = other;
  result = this;
  m_size = this->m_intervals.m_size;
  v3 = this;
  LODWORD(retaddr) = m_size;
  if ( !(_DWORD)m_size )
    return;
  v4 = (hkaiIntervalPartition *)other->m_intervals.m_size;
  if ( !(_DWORD)v4 )
    return;
  v5 = 0i64;
  v6 = 2 * ((_DWORD)v4 + m_size);
  array.m_capacityAndFlags = 0x80000000;
  v7 = 0;
  array.m_data = 0i64;
  array.m_size = 0;
  if ( v6 > 0 )
  {
    if ( (((_DWORD)v4 + (_DWORD)m_size) & 0x40000000) != 0 )
      v6 = 0;
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v6, 20);
  }
  hkArrayBase<hkaiIntervalPartition::Interval>::_append(
    &array,
    &hkContainerHeapAllocator::s_alloc,
    v3->m_intervals.m_data,
    v3->m_intervals.m_size);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v3);
  m_data = (unsigned int *)v3->m_intervals.m_data;
  v9 = (__int64 *)vars0;
  array.m_size = 0;
  result = v4;
  v10 = 0i64;
  v11 = *((float *)m_data + 2);
  v12 = *((float *)m_data + 3);
  m_leftX_low = *m_data;
  v14 = 0i64;
  *(_QWORD *)v46 = m_size;
  m_rightX_low = m_data[1];
  interval.m_slope = v11;
  v16 = m_data[4];
  v17 = *vars0;
  v18 = **vars0;
  v19 = (*vars0)[1];
  interval.m_data = v16;
  v20 = v17[2];
  interval.m_offset = v12;
  v44 = __PAIR64__(v17[3], v20);
  v21 = v17[4];
  v43 = __PAIR64__(v19, v18);
  v22 = v4;
  v23 = 0i64;
  v45 = v21;
  while ( 2 )
  {
    LODWORD(interval.m_rightX) = m_rightX_low;
    LODWORD(interval.m_leftX) = m_leftX_low;
    while ( *(float *)&m_leftX_low >= *(float *)&v18 )
    {
      if ( *(float *)&v18 >= *(float *)&m_leftX_low )
        goto LABEL_19;
      if ( *(float *)&v19 >= *(float *)&m_leftX_low )
      {
        v18 = m_leftX_low;
        LODWORD(v43) = m_leftX_low;
LABEL_19:
        v30 = 0;
        v31 = 0;
        *(_QWORD *)v46 = *(_QWORD *)&interval.m_leftX;
        v45 = interval.m_data;
        *(_QWORD *)&v46[8] = v43;
        *(_QWORD *)&v46[16] = v44;
        v47 = interval.m_data;
        if ( *(float *)&m_rightX_low >= *(float *)&v19 )
        {
          if ( *(float *)&v19 >= *(float *)&m_rightX_low )
          {
            v30 = 1;
            v31 = 1;
          }
          else
          {
            m_leftX_low = v19;
            *(_DWORD *)&v46[4] = v19;
            v31 = 1;
            LODWORD(interval.m_leftX) = v19;
          }
        }
        else
        {
          v18 = m_rightX_low;
          *(_DWORD *)&v46[12] = m_rightX_low;
          v30 = 1;
          LODWORD(v43) = m_rightX_low;
        }
        v32 = *(float *)&v46[8];
        v33 = *(float *)&v46[16];
        if ( *(float *)&v46[8] == *(float *)&v46[16] )
        {
          if ( *(float *)&v46[12] < *(float *)&v46[20] )
            goto LABEL_36;
        }
        else
        {
          hkaiIntervalPartition::Interval::intersect((hkaiIntervalPartition::Interval *)v46, othera, (__int64)&v46[8]);
          if ( othera[0].m_leftX >= *(float *)v46 )
          {
            if ( othera[0].m_leftX <= *(float *)&v46[4] )
            {
              if ( v32 >= v33 )
                *(float *)&v46[4] = othera[0].m_leftX;
              else
                *(float *)v46 = othera[0].m_leftX;
LABEL_36:
              hkaiIntervalPartition::addRemovingDupes(
                (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
                (hkaiIntervalPartition::Interval *)v46);
              goto LABEL_37;
            }
            if ( v32 > v33 )
              goto LABEL_36;
          }
          else if ( v32 < v33 )
          {
            goto LABEL_36;
          }
        }
LABEL_37:
        v34 = 0;
        v35 = v30 == 0;
        v3 = v49;
        if ( !v35 )
        {
          ++v10;
          ++v7;
          ++v5;
          if ( v10 == *(_QWORD *)v46 )
          {
            v34 = 1;
          }
          else
          {
            v36 = v49->m_intervals.m_data;
            m_leftX_low = LODWORD(v49->m_intervals.m_data[v5].m_leftX);
            m_rightX_low = LODWORD(v49->m_intervals.m_data[v5].m_rightX);
            m_offset = v49->m_intervals.m_data[v5].m_offset;
            interval.m_slope = v49->m_intervals.m_data[v5].m_slope;
            interval.m_data = v36[v5].m_data;
            LODWORD(interval.m_leftX) = m_leftX_low;
            LODWORD(interval.m_rightX) = m_rightX_low;
            interval.m_offset = m_offset;
          }
        }
        if ( v31 )
        {
          v14 = (hkaiIntervalPartition *)((char *)v14 + 1);
          v23 += 5i64;
          if ( v14 == result )
            goto LABEL_45;
          v38 = (__int64)*vars0;
          v18 = (*vars0)[v23];
          v19 = (*vars0)[v23 + 1];
          v39 = (*vars0)[v23 + 3];
          LODWORD(v44) = (*vars0)[v23 + 2];
          v45 = *(_DWORD *)(v23 * 4 + v38 + 16);
          v43 = __PAIR64__(v19, v18);
          HIDWORD(v44) = v39;
        }
        v22 = result;
        m_size = *(_QWORD *)v46;
        v35 = v34 == 0;
        v9 = (__int64 *)vars0;
        if ( !v35 )
          goto LABEL_45;
      }
      else
      {
        v14 = (hkaiIntervalPartition *)((char *)v14 + 1);
        v23 += 5i64;
        if ( v14 == v22 )
          goto LABEL_45;
        v27 = *v9;
        v18 = *(unsigned int *)(v23 * 4 + *v9);
        v19 = *(unsigned int *)(v23 * 4 + *v9 + 4);
        v28 = *(_DWORD *)(v23 * 4 + *v9 + 12);
        LODWORD(v44) = *(_DWORD *)(v23 * 4 + *v9 + 8);
        v29 = *(_DWORD *)(v23 * 4 + v27 + 16);
        v22 = result;
        v45 = v29;
        v43 = __PAIR64__(v19, v18);
        HIDWORD(v44) = v28;
      }
    }
    if ( *(float *)&m_rightX_low >= *(float *)&v18 )
    {
      othera[0].m_slope = interval.m_leftX;
      *(_QWORD *)&othera[0].m_data = *(_QWORD *)&interval.m_slope;
      LODWORD(othera[0].m_offset) = v18;
      LODWORD(othera[1].m_rightX) = interval.m_data;
      hkaiIntervalPartition::addRemovingDupes(
        (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
        (hkaiIntervalPartition::Interval *)&othera[0].m_slope);
      m_leftX_low = v18;
      LODWORD(interval.m_leftX) = v18;
      goto LABEL_19;
    }
    hkaiIntervalPartition::addRemovingDupes(
      (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
      &interval);
    ++v10;
    ++v7;
    ++v5;
    if ( v10 != m_size )
    {
      v24 = v3->m_intervals.m_data;
      v9 = (__int64 *)vars0;
      v25 = v3->m_intervals.m_data[v5].m_offset;
      m_leftX_low = LODWORD(v3->m_intervals.m_data[v5].m_leftX);
      m_rightX_low = LODWORD(v3->m_intervals.m_data[v5].m_rightX);
      interval.m_slope = v3->m_intervals.m_data[v5].m_slope;
      v26 = v24[v5].m_data;
      v22 = result;
      interval.m_data = v26;
      interval.m_offset = v25;
      continue;
    }
    break;
  }
LABEL_45:
  if ( v7 < (int)retaddr )
  {
    hkaiIntervalPartition::addRemovingDupes(
      (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
      &interval);
    for ( i = v7 + 1; i != (_DWORD)retaddr; ++i )
      hkaiIntervalPartition::addRemovingDupes(
        (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
        &v3->m_intervals.m_data[i]);
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v3,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      20 * (array.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 1025
// RVA: 0x12E1CA0
// attributes: thunk
void __fastcall hkaiIntervalPartition::swap(
        hkaiIntervalPartition *this,
        hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *other)
{
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this,
    other);
}

// File Line: 1030
// RVA: 0x12E1CB0
_BOOL8 __fastcall hkaiIntervalPartition::coversInterval(hkaiIntervalPartition *this, float left, float right)
{
  __int64 m_size; // rax
  hkaiIntervalPartition::Interval *m_data; // r8
  __int64 v6; // rcx
  __int64 v7; // rdx
  float *i; // rax

  m_size = this->m_intervals.m_size;
  if ( !(_DWORD)m_size )
    return 0i64;
  m_data = this->m_intervals.m_data;
  if ( left < this->m_intervals.m_data->m_leftX )
    return 0i64;
  v6 = 1i64;
  v7 = m_size;
  if ( m_size > 1 )
  {
    for ( i = &m_data[1].m_leftX; *i <= *(i - 4); i += 5 )
    {
      if ( ++v6 >= v7 )
        return right <= m_data[v7 - 1].m_rightX;
    }
    return 0i64;
  }
  return right <= m_data[v7 - 1].m_rightX;
}

// File Line: 1059
// RVA: 0x12E1730
void __fastcall hkaiIntervalPartition::clipDefined(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  __int64 m_size; // rsi
  hkaiIntervalPartition *v4; // r15
  __int64 v5; // rdi
  hkaiIntervalPartition::Interval *m_data; // rax
  int v7; // r9d
  float m_offset; // xmm1_4
  float m_leftX; // xmm7_4
  float m_rightX; // xmm6_4
  int v11; // xmm0_4
  __int64 v12; // rbx
  __int64 v13; // r13
  __int64 v14; // rsi
  hkaiIntervalPartition::Interval *v15; // rax
  float v16; // xmm2_4
  float v17; // xmm8_4
  float v18; // xmm1_4
  unsigned int v19; // xmm0_4
  unsigned int v20; // r15d
  __int64 v21; // r12
  __int64 v22; // rcx
  hkaiIntervalPartition::Interval *v23; // rax
  float v24; // xmm1_4
  hkArrayBase<hkaiIntervalPartition::Interval> array; // [rsp+10h] [rbp-69h] BYREF
  hkaiIntervalPartition::Interval sizeElem; // [rsp+20h] [rbp-59h] BYREF
  float m_slope; // [rsp+40h] [rbp-39h]
  float v28; // [rsp+44h] [rbp-35h]
  unsigned int v29; // [rsp+48h] [rbp-31h]
  hkaiIntervalPartition::Interval interval; // [rsp+50h] [rbp-29h] BYREF
  hkaiIntervalPartition *v31; // [rsp+E0h] [rbp+67h]
  hkResult result; // [rsp+F0h] [rbp+77h] BYREF

  m_size = this->m_intervals.m_size;
  v4 = this;
  if ( (_DWORD)m_size )
  {
    v5 = other->m_intervals.m_size;
    if ( (_DWORD)v5 )
    {
      m_data = other->m_intervals.m_data;
      v7 = 2 * (v5 + m_size);
      m_offset = other->m_intervals.m_data->m_offset;
      m_leftX = other->m_intervals.m_data->m_leftX;
      m_rightX = other->m_intervals.m_data->m_rightX;
      m_slope = other->m_intervals.m_data->m_slope;
      v11 = m_data->m_data;
      array.m_data = 0i64;
      array.m_size = 0;
      array.m_capacityAndFlags = 0x80000000;
      v29 = v11;
      v28 = m_offset;
      if ( v7 > 0 )
      {
        if ( (((_DWORD)v5 + (_DWORD)m_size) & 0x40000000) != 0 )
          v7 = 0;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v7, 20);
      }
      hkArrayBase<hkaiIntervalPartition::Interval>::_append(
        &array,
        &hkContainerHeapAllocator::s_alloc,
        v4->m_intervals.m_data,
        v4->m_intervals.m_size);
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v4);
      array.m_size = 0;
      v12 = 0i64;
      v13 = m_size;
      if ( (int)m_size > 0 )
      {
        v14 = 0i64;
        do
        {
          v15 = v4->m_intervals.m_data;
          v16 = v4->m_intervals.m_data[v14].m_leftX;
          v17 = v4->m_intervals.m_data[v14].m_rightX;
          v18 = v4->m_intervals.m_data[v14].m_offset;
          sizeElem.m_slope = v4->m_intervals.m_data[v14].m_slope;
          v19 = v15[v14].m_data;
          sizeElem.m_leftX = v16;
          sizeElem.m_rightX = v17;
          sizeElem.m_data = v19;
          sizeElem.m_offset = v18;
          if ( v16 < v17 )
          {
            v20 = sizeElem.m_data;
            v21 = *(_QWORD *)&sizeElem.m_slope;
            while ( v12 < v5 )
            {
              v22 = v12;
              while ( v16 >= m_rightX )
              {
                ++v12;
                ++v22;
                if ( v12 >= v5 )
                  goto LABEL_21;
                v23 = other->m_intervals.m_data;
                v24 = other->m_intervals.m_data[v22].m_offset;
                m_leftX = other->m_intervals.m_data[v22].m_leftX;
                m_rightX = other->m_intervals.m_data[v22].m_rightX;
                m_slope = other->m_intervals.m_data[v22].m_slope;
                v29 = v23[v22].m_data;
                v28 = v24;
              }
              if ( v17 <= m_leftX )
                break;
              if ( v16 < m_leftX )
              {
                interval.m_leftX = sizeElem.m_leftX;
                *(_QWORD *)&interval.m_slope = v21;
                interval.m_data = v20;
                interval.m_rightX = m_leftX;
                hkaiIntervalPartition::addRemovingDupes(
                  (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
                  &interval);
              }
              v16 = m_rightX;
              sizeElem.m_leftX = m_rightX;
              if ( m_rightX >= v17 )
                goto LABEL_22;
            }
LABEL_21:
            hkaiIntervalPartition::addRemovingDupes(
              (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
              &sizeElem);
LABEL_22:
            v4 = v31;
          }
          ++v14;
          --v13;
        }
        while ( v13 );
      }
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v4,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
      array.m_size = 0;
      if ( array.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          array.m_data,
          20 * (array.m_capacityAndFlags & 0x3FFFFFFF));
    }
  }
}

// File Line: 1121
// RVA: 0x12E19C0
void __fastcall hkaiIntervalPartition::clipNotDefined(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  __int64 m_size; // rbx
  hkaiIntervalPartition *v4; // r15
  __int64 v5; // rdi
  hkaiIntervalPartition::Interval *m_data; // rax
  float m_offset; // xmm1_4
  int v8; // xmm0_4
  int v9; // r9d
  float m_leftX; // xmm8_4
  float m_rightX; // xmm7_4
  __int64 v12; // r13
  __int64 v13; // r14
  __int64 i; // rbx
  hkaiIntervalPartition::Interval *v15; // rax
  float v16; // xmm6_4
  float v17; // xmm9_4
  float v18; // xmm1_4
  int v19; // xmm0_4
  unsigned int v20; // r15d
  __int64 v21; // r12
  __int64 v22; // rcx
  hkaiIntervalPartition::Interval *v23; // rax
  float v24; // xmm1_4
  float v25; // xmm2_4
  hkArrayBase<hkaiIntervalPartition::Interval> array; // [rsp+30h] [rbp-79h] BYREF
  float v27; // [rsp+40h] [rbp-69h]
  float v28; // [rsp+44h] [rbp-65h]
  __int64 v29; // [rsp+48h] [rbp-61h]
  int v30; // [rsp+50h] [rbp-59h]
  hkaiIntervalPartition::Interval interval; // [rsp+58h] [rbp-51h] BYREF
  float m_slope; // [rsp+78h] [rbp-31h]
  float v33; // [rsp+7Ch] [rbp-2Dh]
  unsigned int v34; // [rsp+80h] [rbp-29h]
  hkResult result; // [rsp+120h] [rbp+77h] BYREF
  float v37; // [rsp+128h] [rbp+7Fh]

  m_size = this->m_intervals.m_size;
  v4 = this;
  if ( (_DWORD)m_size )
  {
    v5 = other->m_intervals.m_size;
    if ( (_DWORD)v5 )
    {
      m_data = other->m_intervals.m_data;
      m_offset = other->m_intervals.m_data->m_offset;
      m_slope = other->m_intervals.m_data->m_slope;
      v8 = m_data->m_data;
      v33 = m_offset;
      v9 = 2 * (m_size + v5);
      m_leftX = m_data->m_leftX;
      m_rightX = m_data->m_rightX;
      v34 = v8;
      array.m_data = 0i64;
      array.m_size = 0;
      array.m_capacityAndFlags = 0x80000000;
      if ( v9 > 0 )
      {
        if ( (((_DWORD)m_size + (_DWORD)v5) & 0x40000000) != 0 )
          v9 = 0;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v9, 20);
      }
      hkArrayBase<hkaiIntervalPartition::Interval>::_append(
        &array,
        &hkContainerHeapAllocator::s_alloc,
        v4->m_intervals.m_data,
        v4->m_intervals.m_size);
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v4);
      v12 = m_size;
      array.m_size = 0;
      v13 = 0i64;
      for ( i = 0i64; v13 < v12; ++v13 )
      {
        v15 = v4->m_intervals.m_data;
        v16 = v4->m_intervals.m_data[v13].m_leftX;
        v17 = v4->m_intervals.m_data[v13].m_rightX;
        v18 = v4->m_intervals.m_data[v13].m_offset;
        *(float *)&v29 = v4->m_intervals.m_data[v13].m_slope;
        v19 = v15[v13].m_data;
        v27 = v16;
        v28 = v17;
        v30 = v19;
        *((float *)&v29 + 1) = v18;
        if ( v16 < v17 )
        {
          v20 = v30;
          v21 = v29;
          while ( i < v5 )
          {
            v22 = i;
            while ( v16 >= m_rightX )
            {
              ++i;
              ++v22;
              if ( i >= v5 )
                goto LABEL_21;
              v23 = other->m_intervals.m_data;
              v24 = other->m_intervals.m_data[v22].m_offset;
              m_leftX = other->m_intervals.m_data[v22].m_leftX;
              m_rightX = other->m_intervals.m_data[v22].m_rightX;
              m_slope = other->m_intervals.m_data[v22].m_slope;
              v34 = v23[v22].m_data;
              v33 = v24;
            }
            if ( v17 > m_leftX )
            {
              *(_QWORD *)&interval.m_slope = v21;
              interval.m_data = v20;
              v25 = fmaxf(v16, m_leftX);
              result.m_enum = LODWORD(v28);
              v37 = m_rightX;
              v16 = fminf(v28, m_rightX);
              interval.m_leftX = v25;
              interval.m_rightX = v16;
              if ( v16 > v25 )
                hkaiIntervalPartition::addRemovingDupes(
                  (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
                  &interval);
              v27 = v16;
              if ( v16 < v17 )
                continue;
            }
            goto LABEL_22;
          }
LABEL_21:
          v13 = v12;
LABEL_22:
          v4 = this;
        }
      }
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v4,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
      array.m_size = 0;
      if ( array.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          array.m_data,
          20 * (array.m_capacityAndFlags & 0x3FFFFFFF));
    }
    else
    {
      this->m_intervals.m_size = 0;
    }
  }
}

// File Line: 1190
// RVA: 0x12E1D10
__int64 __fastcall hkaiIntervalPartition::tryEvaluateAt(hkaiIntervalPartition *this, float x, float *out)
{
  int Interval; // eax
  hkaiIntervalPartition::Interval *v6; // rax
  float v7; // xmm0_4
  __int64 result; // rax

  if ( x < 0.0 )
    return 0i64;
  Interval = hkaiIntervalPartition::findInterval(this, x);
  v6 = hkaiIntervalPartition::getInterval(this, Interval);
  v7 = hkaiIntervalPartition::Interval::evaluateAt(v6, x);
  result = 1i64;
  *out = v7;
  return result;
}

// File Line: 1205
// RVA: 0x12E1D80
float __fastcall hkaiIntervalPartition::evaluateWithDefault(hkaiIntervalPartition *this, float x, float defaultY)
{
  float out; // [rsp+40h] [rbp+18h] BYREF

  out = defaultY;
  hkaiIntervalPartition::tryEvaluateAt(this, x, &out);
  return out;
}

// File Line: 1213
// RVA: 0x12E38C0
double __fastcall hkaiIntervalPartition::Interval::getExtremeY<0>(hkaiIntervalPartition::Interval *this)
{
  double result; // xmm0_8

  HIDWORD(result) = 0;
  if ( this->m_slope <= 0.0 )
    *(float *)&result = hkaiIntervalPartition::Interval::evaluateAt(this, this->m_rightX);
  else
    *(float *)&result = hkaiIntervalPartition::Interval::evaluateAt(this, this->m_leftX);
  return result;
}

// File Line: 1226
// RVA: 0x12E0780
void __fastcall hkaiIntervalPartition::Interval::interpolateParallelogram(
        hkaiIntervalPartition::Interval *this,
        hkVector4f *origin,
        hkVector4f *xVector,
        hkVector4f *yVector,
        hkVector4f *leftOut,
        hkVector4f *rightOut)
{
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm1

  v6 = *(__m128 *)&this->m_leftX;
  v7 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 170), yVector->m_quad), xVector->m_quad);
  v8 = _mm_add_ps(
         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&this->m_leftX, *(__m128 *)&this->m_leftX, 255), yVector->m_quad),
         origin->m_quad);
  leftOut->m_quad = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&this->m_leftX, *(__m128 *)&this->m_leftX, 0), v7),
                      v8);
  rightOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), v7), v8);
}

// File Line: 1241
// RVA: 0x12E38E0
float __fastcall hkaiIntervalPartition::getExtremeY<0>(hkaiIntervalPartition *this)
{
  hkaiIntervalPartition::Interval *m_data; // rdi
  double Extreme; // xmm0_8
  int m_size; // eax
  float v5; // xmm6_4
  hkaiIntervalPartition::Interval *v6; // rbx
  __int64 v7; // rdi
  double v8; // xmm0_8

  m_data = this->m_intervals.m_data;
  Extreme = hkaiIntervalPartition::Interval::getExtremeY<0>(this->m_intervals.m_data);
  m_size = this->m_intervals.m_size;
  v5 = *(float *)&Extreme;
  if ( m_size > 1 )
  {
    v6 = m_data + 1;
    v7 = (unsigned int)(m_size - 1);
    do
    {
      v8 = hkaiIntervalPartition::Interval::getExtremeY<0>(v6++);
      v5 = fminf(v5, *(float *)&v8);
      --v7;
    }
    while ( v7 );
  }
  return v5;
}

// File Line: 1266
// RVA: 0x12E38A0
float __fastcall hkaiIntervalPartition::getExtremeX<1>(hkaiIntervalPartition *this)
{
  return this->m_intervals.m_data[this->m_intervals.m_size - 1].m_rightX;
}

// File Line: 1283
// RVA: 0x12E1DB0
void __fastcall hkaiIntervalPartition::complement(hkaiIntervalPartition *this, float minX, float maxX)
{
  int v5; // edi
  __int64 v6; // r11
  float m_leftX; // xmm0_4
  float m_rightX; // xmm6_4
  __int64 m_size; // r9
  __int64 v10; // r8
  __int64 v11; // rdx
  __int64 v12; // rcx
  unsigned __int64 v13; // r10
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  __int64 v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // r9
  float v24; // xmm0_4
  float v25; // xmm1_4
  int v26; // eax
  int v27; // eax
  int v28; // r9d
  hkaiIntervalPartition::Interval interval; // [rsp+30h] [rbp-48h] BYREF
  hkResult result; // [rsp+80h] [rbp+8h] BYREF

  if ( this->m_intervals.m_size )
  {
    v5 = 0;
    v6 = 1i64;
    m_leftX = this->m_intervals.m_data->m_leftX;
    m_rightX = this->m_intervals.m_data->m_rightX;
    if ( m_leftX > minX )
    {
      this->m_intervals.m_data->m_rightX = m_leftX;
      v5 = 1;
      this->m_intervals.m_data->m_leftX = minX;
    }
    m_size = this->m_intervals.m_size;
    v10 = v5;
    if ( m_size > 1 )
    {
      if ( m_size - 1 >= 4 )
      {
        v11 = 1i64;
        v12 = v5;
        v13 = ((unsigned __int64)(m_size - 5) >> 2) + 1;
        v6 = 4 * v13 + 1;
        do
        {
          v14 = this->m_intervals.m_data[v11].m_leftX;
          v15 = this->m_intervals.m_data[v11].m_rightX;
          if ( m_rightX < v14 )
          {
            this->m_intervals.m_data[v12].m_leftX = m_rightX;
            ++v5;
            ++v10;
            this->m_intervals.m_data[v12++].m_rightX = v14;
          }
          v16 = this->m_intervals.m_data[v11 + 1].m_leftX;
          v17 = this->m_intervals.m_data[v11 + 1].m_rightX;
          if ( v15 < v16 )
          {
            this->m_intervals.m_data[v12].m_leftX = v15;
            ++v5;
            ++v10;
            this->m_intervals.m_data[v12++].m_rightX = v16;
          }
          v18 = this->m_intervals.m_data[v11 + 2].m_leftX;
          v19 = this->m_intervals.m_data[v11 + 2].m_rightX;
          if ( v17 < v18 )
          {
            this->m_intervals.m_data[v12].m_leftX = v17;
            ++v5;
            ++v10;
            this->m_intervals.m_data[v12++].m_rightX = v18;
          }
          v20 = this->m_intervals.m_data[v11 + 3].m_leftX;
          m_rightX = this->m_intervals.m_data[v11 + 3].m_rightX;
          if ( v19 < v20 )
          {
            this->m_intervals.m_data[v12].m_leftX = v19;
            ++v5;
            ++v10;
            this->m_intervals.m_data[v12++].m_rightX = v20;
          }
          v11 += 4i64;
          --v13;
        }
        while ( v13 );
      }
      if ( v6 < m_size )
      {
        v21 = v10;
        v22 = v6;
        v23 = m_size - v6;
        do
        {
          v24 = m_rightX;
          v25 = this->m_intervals.m_data[v22].m_leftX;
          m_rightX = this->m_intervals.m_data[v22].m_rightX;
          if ( v24 < v25 )
          {
            this->m_intervals.m_data[v21].m_leftX = v24;
            ++v5;
            this->m_intervals.m_data[v21++].m_rightX = v25;
          }
          ++v22;
          --v23;
        }
        while ( v23 );
      }
    }
    v26 = this->m_intervals.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v26 < v5 )
    {
      v27 = 2 * v26;
      v28 = v5;
      if ( v5 < v27 )
        v28 = v27;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_intervals.m_data,
        v28,
        20);
    }
    this->m_intervals.m_size = v5;
    if ( m_rightX < maxX )
    {
      interval.m_leftX = m_rightX;
      interval.m_rightX = maxX;
      *(_QWORD *)&interval.m_slope = 0i64;
      interval.m_data = -1;
      hkaiIntervalPartition::appendInterval(this, &interval);
    }
  }
  else
  {
    interval.m_leftX = minX;
    interval.m_rightX = maxX;
    *(_QWORD *)&interval.m_slope = 0i64;
    interval.m_data = -1;
    hkaiIntervalPartition::appendInterval(this, &interval);
  }
}tX = maxX;
    *(_QWORD *

// File Line: 1328
// RVA: 0x12E22F0
void __fastcall hkaiIntervalPartition::remapX(
        hkaiIntervalPartition *this,
        float curX1,
        float curX2,
        float newX1,
        float newX2)
{
  __int64 m_size; // rax
  float v7; // xmm4_4
  float v8; // xmm3_4
  __int64 v9; // r10
  float v10; // xmm5_4
  __int64 v11; // rdx
  __int64 v12; // rcx
  unsigned __int64 v13; // r8
  hkaiIntervalPartition::Interval *m_data; // rax
  float v15; // xmm2_4
  hkaiIntervalPartition::Interval *v16; // rax
  float v17; // xmm2_4
  hkaiIntervalPartition::Interval *v18; // rax
  float v19; // xmm2_4
  hkaiIntervalPartition::Interval *v20; // rax
  float v21; // xmm2_4
  unsigned __int64 v22; // rcx
  __int64 v23; // rdx
  hkaiIntervalPartition::Interval *v24; // rax
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4

  m_size = this->m_intervals.m_size;
  if ( (_DWORD)m_size )
  {
    v7 = (float)(newX2 - newX1) / (float)(curX2 - curX1);
    v8 = newX1 - (float)(v7 * curX1);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(1.0 - v7)) >> 1) >= 0.000099999997
      || COERCE_FLOAT((unsigned int)(2 * LODWORD(v8)) >> 1) >= 0.0001 )
    {
      v9 = 0i64;
      v10 = 1.0 / v7;
      v11 = this->m_intervals.m_size;
      if ( m_size >= 4 )
      {
        v12 = 0i64;
        v13 = ((unsigned __int64)(m_size - 4) >> 2) + 1;
        v9 = 4 * v13;
        do
        {
          m_data = this->m_intervals.m_data;
          v12 += 4i64;
          m_data[v12 - 4].m_leftX = (float)(v7 * this->m_intervals.m_data[v12 - 4].m_leftX) + v8;
          *((float *)&m_data[v12 - 3] - 4) = (float)(v7 * *((float *)&m_data[v12 - 3] - 4)) + v8;
          v15 = v10 * *((float *)&m_data[v12 - 3] - 3);
          *((float *)&m_data[v12 - 3] - 3) = v15;
          *((float *)&m_data[v12 - 3] - 2) = *((float *)&m_data[v12 - 3] - 2) - (float)(v15 * v8);
          v16 = this->m_intervals.m_data;
          v16[v12 - 3].m_leftX = (float)(v7 * this->m_intervals.m_data[v12 - 3].m_leftX) + v8;
          *((float *)&v16[v12 - 2] - 4) = (float)(v7 * *((float *)&v16[v12 - 2] - 4)) + v8;
          v17 = v10 * *((float *)&v16[v12 - 2] - 3);
          *((float *)&v16[v12 - 2] - 3) = v17;
          *((float *)&v16[v12 - 2] - 2) = *((float *)&v16[v12 - 2] - 2) - (float)(v17 * v8);
          v18 = this->m_intervals.m_data;
          v18[v12 - 2].m_leftX = (float)(v7 * this->m_intervals.m_data[v12 - 2].m_leftX) + v8;
          *((float *)&v18[v12 - 1] - 4) = (float)(v7 * *((float *)&v18[v12 - 1] - 4)) + v8;
          v19 = v10 * *((float *)&v18[v12 - 1] - 3);
          *((float *)&v18[v12 - 1] - 3) = v19;
          *((float *)&v18[v12 - 1] - 2) = *((float *)&v18[v12 - 1] - 2) - (float)(v19 * v8);
          v20 = this->m_intervals.m_data;
          v20[v12 - 1].m_leftX = (float)(v7 * this->m_intervals.m_data[v12 - 1].m_leftX) + v8;
          v20[v12 - 1].m_rightX = (float)(v7 * v20[v12 - 1].m_rightX) + v8;
          v21 = v10 * v20[v12 - 1].m_slope;
          v20[v12 - 1].m_slope = v21;
          v20[v12 - 1].m_offset = v20[v12 - 1].m_offset - (float)(v21 * v8);
          --v13;
        }
        while ( v13 );
      }
      if ( v9 < v11 )
      {
        v22 = v9;
        v23 = v11 - v9;
        do
        {
          v24 = this->m_intervals.m_data;
          v25 = v10 * this->m_intervals.m_data[v22++].m_slope;
          v26 = (float)(v7 * this->m_intervals.m_data[v22 - 1].m_leftX) + v8;
          v24[v22 - 1].m_slope = v25;
          v27 = v7 * v24[v22 - 1].m_rightX;
          v24[v22 - 1].m_leftX = v26;
          v24[v22 - 1].m_offset = v24[v22 - 1].m_offset - (float)(v25 * v8);
          v24[v22 - 1].m_rightX = v27 + v8;
          --v23;
        }
        while ( v23 );
      }
    }
  }
}

// File Line: 1363
// RVA: 0x12E2550
void __fastcall hkaiIntervalPartition::remapY(
        hkaiIntervalPartition *this,
        float curY1,
        float curY2,
        float newY1,
        float newY2)
{
  __int64 m_size; // rax
  float v7; // xmm4_4
  float v8; // xmm3_4
  __int64 v9; // r10
  __int64 v10; // rdx
  __int64 v11; // rcx
  unsigned __int64 v12; // r9
  hkaiIntervalPartition::Interval *m_data; // rax
  hkaiIntervalPartition::Interval *v14; // rax
  hkaiIntervalPartition::Interval *v15; // rax
  hkaiIntervalPartition::Interval *v16; // rax
  __int64 v17; // rcx
  __int64 v18; // rdx
  hkaiIntervalPartition::Interval *v19; // rax
  float v20; // xmm1_4

  m_size = this->m_intervals.m_size;
  if ( (_DWORD)m_size )
  {
    v7 = (float)(newY2 - newY1) / (float)(curY2 - curY1);
    v8 = newY1 - (float)(v7 * curY1);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(1.0 - v8)) >> 1) >= 0.000099999997
      || COERCE_FLOAT((unsigned int)(2 * LODWORD(v7)) >> 1) >= 0.0001 )
    {
      v9 = 0i64;
      v10 = this->m_intervals.m_size;
      if ( m_size >= 4 )
      {
        v11 = 0i64;
        v12 = ((unsigned __int64)(m_size - 4) >> 2) + 1;
        v9 = 4 * v12;
        do
        {
          m_data = this->m_intervals.m_data;
          v11 += 4i64;
          *((float *)&m_data[v11 - 3] - 3) = v7 * *((float *)&this->m_intervals.m_data[v11 - 3] - 3);
          *((float *)&m_data[v11 - 3] - 2) = (float)(v7 * *((float *)&m_data[v11 - 3] - 2)) + v8;
          v14 = this->m_intervals.m_data;
          *((float *)&v14[v11 - 2] - 3) = v7 * *((float *)&this->m_intervals.m_data[v11 - 2] - 3);
          *((float *)&v14[v11 - 2] - 2) = (float)(v7 * *((float *)&v14[v11 - 2] - 2)) + v8;
          v15 = this->m_intervals.m_data;
          *((float *)&v15[v11 - 1] - 3) = v7 * *((float *)&this->m_intervals.m_data[v11 - 1] - 3);
          *((float *)&v15[v11 - 1] - 2) = (float)(v7 * *((float *)&v15[v11 - 1] - 2)) + v8;
          v16 = this->m_intervals.m_data;
          v16[v11 - 1].m_slope = v7 * this->m_intervals.m_data[v11 - 1].m_slope;
          v16[v11 - 1].m_offset = (float)(v7 * v16[v11 - 1].m_offset) + v8;
          --v12;
        }
        while ( v12 );
      }
      if ( v9 < v10 )
      {
        v17 = v9;
        v18 = v10 - v9;
        do
        {
          v19 = this->m_intervals.m_data;
          v20 = (float)(v7 * this->m_intervals.m_data[v17++].m_offset) + v8;
          v19[v17 - 1].m_slope = v7 * this->m_intervals.m_data[v17 - 1].m_slope;
          v19[v17 - 1].m_offset = v20;
          --v18;
        }
        while ( v18 );
      }
    }
  }
}

// File Line: 1388
// RVA: 0x12E26F0
void __fastcall hkaiIntervalPartition::spread(hkaiIntervalPartition *this, float maxSpread)
{
  __int64 m_size; // rax
  __int64 v6; // rcx
  __int64 v7; // r8
  hkaiIntervalPartition::Interval *m_data; // rax
  float v9; // xmm2_4
  float v10; // xmm1_4
  __int64 v11; // rcx

  if ( this->m_intervals.m_size )
  {
    this->m_intervals.m_data->m_leftX = this->m_intervals.m_data->m_leftX - maxSpread;
    m_size = this->m_intervals.m_size;
    if ( m_size > 1 )
    {
      v6 = 1i64;
      v7 = m_size - 1;
      do
      {
        m_data = this->m_intervals.m_data;
        v9 = *((float *)&this->m_intervals.m_data[v6++] - 4);
        v10 = fminf((float)(this->m_intervals.m_data[v6 - 1].m_leftX - v9) * 0.5, maxSpread);
        *((float *)&m_data[v6 - 1] - 4) = v9 + v10;
        m_data[v6 - 1].m_leftX = m_data[v6 - 1].m_leftX - v10;
        --v7;
      }
      while ( v7 );
    }
    v11 = this->m_intervals.m_size - 1;
    this->m_intervals.m_data[v11].m_rightX = maxSpread + this->m_intervals.m_data[v11].m_rightX;
  }
}

// File Line: 1433
// RVA: 0x12E27B0
void __fastcall hkaiIntervalPartition::contract(hkaiIntervalPartition *this, float maxContract)
{
  ContractFilter filter; // [rsp+38h] [rbp+10h] BYREF

  filter.m_maxContract = maxContract;
  hkaiIntervalPartition::filterIntervals<`anonymous namespace::ContractFilter>(this, &filter);
}

// File Line: 1438
// RVA: 0x12E27D0
void __fastcall hkaiIntervalPartition::copyFrom(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  int m_capacityAndFlags; // ecx
  __int64 m_size; // rcx
  hkaiIntervalPartition::Interval *m_data; // rax
  __int64 v7; // rdx
  char *v8; // r8
  float v9; // ecx
  int v10; // [rsp+30h] [rbp+8h] BYREF

  m_capacityAndFlags = this->m_intervals.m_capacityAndFlags;
  if ( (m_capacityAndFlags & 0x3FFFFFFF) < other->m_intervals.m_size )
  {
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_intervals.m_data,
        20 * (m_capacityAndFlags & 0x3FFFFFFF));
    v10 = 20 * other->m_intervals.m_size;
    this->m_intervals.m_data = (hkaiIntervalPartition::Interval *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                    &hkContainerHeapAllocator::s_alloc,
                                                                    &v10);
    this->m_intervals.m_capacityAndFlags = v10 / 20;
  }
  m_size = other->m_intervals.m_size;
  m_data = this->m_intervals.m_data;
  this->m_intervals.m_size = m_size;
  v7 = m_size;
  if ( (int)m_size > 0 )
  {
    v8 = (char *)((char *)other->m_intervals.m_data - (char *)m_data);
    do
    {
      v9 = *(float *)((char *)&m_data->m_leftX + (_QWORD)v8);
      ++m_data;
      m_data[-1].m_leftX = v9;
      m_data[-1].m_rightX = *(float *)((char *)m_data + (_QWORD)v8 - 16);
      m_data[-1].m_slope = *(float *)((char *)m_data + (_QWORD)v8 - 12);
      m_data[-1].m_offset = *(float *)((char *)m_data + (_QWORD)v8 - 8);
      m_data[-1].m_data = *(_DWORD *)((char *)m_data + (_QWORD)v8 - 4);
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 1443
// RVA: 0x12E0F10
void __fastcall hkaiIntervalPartition::appendPartition(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  int m_size; // r9d
  int m_capacityAndFlags; // ecx
  __int64 v6; // rcx
  hkaiIntervalPartition::Interval *m_data; // rax
  __int64 v8; // rdx
  char *v9; // r8
  float v10; // ecx
  int v11; // [rsp+38h] [rbp+10h] BYREF

  m_size = other->m_intervals.m_size;
  if ( m_size )
  {
    if ( this->m_intervals.m_size )
    {
      hkArrayBase<hkaiIntervalPartition::Interval>::_append(
        &this->m_intervals,
        &hkContainerHeapAllocator::s_alloc,
        other->m_intervals.m_data,
        m_size);
    }
    else
    {
      m_capacityAndFlags = this->m_intervals.m_capacityAndFlags;
      if ( (m_capacityAndFlags & 0x3FFFFFFF) < m_size )
      {
        if ( m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            this->m_intervals.m_data,
            20 * (m_capacityAndFlags & 0x3FFFFFFF));
        v11 = 20 * other->m_intervals.m_size;
        this->m_intervals.m_data = (hkaiIntervalPartition::Interval *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                        &hkContainerHeapAllocator::s_alloc,
                                                                        &v11);
        this->m_intervals.m_capacityAndFlags = v11 / 20;
      }
      v6 = other->m_intervals.m_size;
      m_data = this->m_intervals.m_data;
      this->m_intervals.m_size = v6;
      v8 = v6;
      if ( (int)v6 > 0 )
      {
        v9 = (char *)((char *)other->m_intervals.m_data - (char *)m_data);
        do
        {
          v10 = *(float *)((char *)&m_data->m_leftX + (_QWORD)v9);
          ++m_data;
          m_data[-1].m_leftX = v10;
          m_data[-1].m_rightX = *(float *)((char *)m_data + (_QWORD)v9 - 16);
          m_data[-1].m_slope = *(float *)((char *)m_data + (_QWORD)v9 - 12);
          m_data[-1].m_offset = *(float *)((char *)m_data + (_QWORD)v9 - 8);
          m_data[-1].m_data = *(_DWORD *)((char *)m_data + (_QWORD)v9 - 4);
          --v8;
        }
        while ( v8 );
      }
    }
  }
}

// File Line: 1460
// RVA: 0x12E28C0
void __fastcall hkaiIntervalPartition::copyRegionFrom(
        hkaiIntervalPartition *this,
        hkaiIntervalPartition *other,
        float minX,
        float maxX)
{
  int v4; // ebx
  __int64 m_size; // rbp
  hkaiIntervalPartition::Interval *Interval; // rax
  float m_rightX; // xmm8_4
  float m_slope; // xmm9_4
  float m_offset; // xmm10_4
  unsigned int m_data; // xmm11_4
  float v13; // xmm6_4
  __int64 v14; // rcx
  hkaiIntervalPartition::Interval *v15; // rax
  int RightInterval; // r14d
  bool v17; // cc
  float m_leftX; // xmm8_4
  float v19; // xmm9_4
  float v20; // xmm10_4
  unsigned int v21; // xmm11_4
  float v22; // xmm6_4
  __int64 v23; // rcx
  hkaiIntervalPartition::Interval *v24; // rax

  v4 = 0;
  this->m_intervals.m_size = 0;
  m_size = other->m_intervals.m_size;
  if ( (_DWORD)m_size )
  {
    if ( minX > other->m_intervals.m_data->m_leftX || maxX < other->m_intervals.m_data[m_size - 1].m_rightX )
    {
      if ( (int)m_size > 0 )
      {
        while ( 1 )
        {
          Interval = hkaiIntervalPartition::getInterval(other, v4);
          if ( minX < Interval->m_rightX )
            break;
          if ( ++v4 >= (int)m_size )
            goto LABEL_12;
        }
        m_rightX = Interval->m_rightX;
        m_slope = Interval->m_slope;
        m_offset = Interval->m_offset;
        m_data = Interval->m_data;
        v13 = fmaxf(Interval->m_leftX, minX);
        if ( (this->m_intervals.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_intervals.m_data, 20);
        v14 = this->m_intervals.m_size;
        v15 = this->m_intervals.m_data;
        v15[v14].m_leftX = v13;
        v15[v14].m_rightX = m_rightX;
        v15[v14].m_slope = m_slope;
        v15[v14].m_offset = m_offset;
        v15[v14].m_data = m_data;
        ++this->m_intervals.m_size;
        ++v4;
      }
LABEL_12:
      RightInterval = hkaiIntervalPartition::findRightInterval(other, maxX);
      if ( (int)m_size - 1 < RightInterval )
        RightInterval = m_size - 1;
      v17 = v4 <= RightInterval;
      if ( v4 < RightInterval )
      {
        hkArrayBase<hkaiIntervalPartition::Interval>::_append(
          &this->m_intervals,
          &hkContainerHeapAllocator::s_alloc,
          &other->m_intervals.m_data[v4],
          RightInterval - v4);
        v17 = v4 <= RightInterval;
      }
      if ( v17 )
      {
        m_leftX = other->m_intervals.m_data[RightInterval].m_leftX;
        v19 = other->m_intervals.m_data[RightInterval].m_slope;
        v20 = other->m_intervals.m_data[RightInterval].m_offset;
        v21 = other->m_intervals.m_data[RightInterval].m_data;
        if ( m_leftX < maxX )
        {
          v22 = fminf(other->m_intervals.m_data[RightInterval].m_rightX, maxX);
          if ( this->m_intervals.m_size == (this->m_intervals.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_intervals.m_data, 20);
          v23 = this->m_intervals.m_size;
          v24 = this->m_intervals.m_data;
          v24[v23].m_leftX = m_leftX;
          v24[v23].m_rightX = v22;
          v24[v23].m_slope = v19;
          v24[v23].m_offset = v20;
          v24[v23].m_data = v21;
          ++this->m_intervals.m_size;
        }
      }
    }
    else
    {
      hkaiIntervalPartition::copyFrom(this, other);
    }
  }
}

// File Line: 1508
// RVA: 0x12E2B30
void __fastcall hkaiIntervalPartition::discardRange(hkaiIntervalPartition *this)
{
  int v2; // r11d
  int v3; // r9d
  __int64 v4; // rbx
  unsigned __int64 v5; // r8
  unsigned __int64 v6; // rdx
  hkaiIntervalPartition::Interval *m_data; // rcx

  if ( this->m_intervals.m_size >= 2 )
  {
    v2 = 0;
    v3 = 1;
    v4 = 0i64;
    v5 = 0i64;
    v6 = 1i64;
    do
    {
      m_data = this->m_intervals.m_data;
      if ( this->m_intervals.m_data[v6].m_leftX == this->m_intervals.m_data[v5].m_rightX )
      {
        m_data[v5].m_rightX = m_data[v6].m_rightX;
      }
      else
      {
        ++v2;
        v5 = ++v4;
        m_data[v5].m_leftX = m_data[v6].m_leftX;
        m_data[v5].m_rightX = m_data[v6].m_rightX;
        m_data[v5].m_slope = m_data[v6].m_slope;
        m_data[v5].m_offset = m_data[v6].m_offset;
        m_data[v5].m_data = m_data[v6].m_data;
      }
      ++v3;
      ++v6;
    }
    while ( v3 < this->m_intervals.m_size );
    this->m_intervals.m_size = v2 + 1;
  }
}

// File Line: 1531
// RVA: 0x12E2BE0
void __fastcall hkaiIntervalPartition::setAllData(hkaiIntervalPartition *this, unsigned int data)
{
  __int64 m_size; // r9
  __int64 v3; // rax

  m_size = this->m_intervals.m_size;
  if ( m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      this->m_intervals.m_data[v3++].m_data = data;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 1539
// RVA: 0x12E2000
void __fastcall hkaiIntervalPartition::reflectX(hkaiIntervalPartition *this, float mid)
{
  __int64 v2; // r15
  __int64 m_size; // rsi
  __int64 v6; // rbp
  unsigned __int64 v7; // rbx
  __int64 v8; // rdi
  hkaiIntervalPartition::Interval *m_data; // r11
  float m_leftX; // ecx
  float m_rightX; // edx
  float m_slope; // r8d
  float m_offset; // r9d
  unsigned int v14; // r10d
  __int64 v15; // rcx
  unsigned __int64 v16; // rdx
  float v17; // xmm2_4
  hkaiIntervalPartition::Interval *v18; // rax
  float v19; // xmm1_4
  float v20; // xmm0_4
  hkaiIntervalPartition::Interval *v21; // rax
  float v22; // xmm1_4
  float v23; // xmm0_4
  hkaiIntervalPartition::Interval *v24; // rax
  float v25; // xmm1_4
  float v26; // xmm0_4
  hkaiIntervalPartition::Interval *v27; // rax
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  unsigned __int64 v31; // rcx
  __int64 v32; // rsi
  hkaiIntervalPartition::Interval *v33; // rax
  float v34; // xmm2_4
  float v35; // xmm1_4

  v2 = 0i64;
  m_size = this->m_intervals.m_size;
  v6 = (int)m_size / 2;
  if ( (int)m_size / 2 > 0 )
  {
    v7 = m_size;
    v8 = 0i64;
    do
    {
      m_data = this->m_intervals.m_data;
      --v7;
      m_leftX = this->m_intervals.m_data[v8++].m_leftX;
      m_rightX = this->m_intervals.m_data[v8 - 1].m_rightX;
      m_slope = this->m_intervals.m_data[v8 - 1].m_slope;
      m_offset = this->m_intervals.m_data[v8 - 1].m_offset;
      v14 = this->m_intervals.m_data[v8 - 1].m_data;
      m_data[v8 - 1].m_leftX = this->m_intervals.m_data[v7].m_leftX;
      m_data[v8 - 1].m_rightX = m_data[v7].m_rightX;
      m_data[v8 - 1].m_slope = m_data[v7].m_slope;
      m_data[v8 - 1].m_offset = m_data[v7].m_offset;
      m_data[v8 - 1].m_data = m_data[v7].m_data;
      m_data[v7].m_leftX = m_leftX;
      m_data[v7].m_rightX = m_rightX;
      m_data[v7].m_slope = m_slope;
      m_data[v7].m_offset = m_offset;
      m_data[v7].m_data = v14;
      --v6;
    }
    while ( v6 );
  }
  if ( m_size >= 4 )
  {
    v15 = 0i64;
    v16 = ((unsigned __int64)(m_size - 4) >> 2) + 1;
    v17 = mid * 2.0;
    v2 = 4 * v16;
    do
    {
      v18 = this->m_intervals.m_data;
      v15 += 4i64;
      v18[v15 - 4].m_leftX = v17 - this->m_intervals.m_data[v15 - 4].m_leftX;
      v19 = v17 - *((float *)&v18[v15 - 3] - 4);
      *((float *)&v18[v15 - 3] - 4) = v19;
      v20 = v18[v15 - 4].m_leftX;
      v18[v15 - 4].m_leftX = v19;
      *((float *)&v18[v15 - 3] - 4) = v20;
      *((float *)&v18[v15 - 3] - 2) = (float)(v17 * *((float *)&v18[v15 - 3] - 3)) + *((float *)&v18[v15 - 3] - 2);
      *((_DWORD *)&v18[v15 - 3] - 3) ^= _xmm[0];
      v21 = this->m_intervals.m_data;
      v21[v15 - 3].m_leftX = v17 - this->m_intervals.m_data[v15 - 3].m_leftX;
      v22 = v17 - *((float *)&v21[v15 - 2] - 4);
      *((float *)&v21[v15 - 2] - 4) = v22;
      v23 = v21[v15 - 3].m_leftX;
      v21[v15 - 3].m_leftX = v22;
      *((float *)&v21[v15 - 2] - 4) = v23;
      *((float *)&v21[v15 - 2] - 2) = (float)(v17 * *((float *)&v21[v15 - 2] - 3)) + *((float *)&v21[v15 - 2] - 2);
      *((_DWORD *)&v21[v15 - 2] - 3) ^= _xmm[0];
      v24 = this->m_intervals.m_data;
      v24[v15 - 2].m_leftX = v17 - this->m_intervals.m_data[v15 - 2].m_leftX;
      v25 = v17 - *((float *)&v24[v15 - 1] - 4);
      *((float *)&v24[v15 - 1] - 4) = v25;
      v26 = v24[v15 - 2].m_leftX;
      v24[v15 - 2].m_leftX = v25;
      *((float *)&v24[v15 - 1] - 4) = v26;
      *((float *)&v24[v15 - 1] - 2) = (float)(v17 * *((float *)&v24[v15 - 1] - 3)) + *((float *)&v24[v15 - 1] - 2);
      *((_DWORD *)&v24[v15 - 1] - 3) ^= _xmm[0];
      v27 = this->m_intervals.m_data;
      v27[v15 - 1].m_leftX = v17 - this->m_intervals.m_data[v15 - 1].m_leftX;
      v28 = v17 - v27[v15 - 1].m_rightX;
      v27[v15 - 1].m_rightX = v28;
      v29 = v27[v15 - 1].m_leftX;
      v27[v15 - 1].m_leftX = v28;
      v27[v15 - 1].m_rightX = v29;
      v27[v15 - 1].m_offset = (float)(v17 * v27[v15 - 1].m_slope) + v27[v15 - 1].m_offset;
      LODWORD(v27[v15 - 1].m_slope) ^= _xmm[0];
      --v16;
    }
    while ( v16 );
  }
  if ( v2 < m_size )
  {
    v30 = mid * 2.0;
    v31 = v2;
    v32 = m_size - v2;
    do
    {
      v33 = this->m_intervals.m_data;
      v34 = this->m_intervals.m_data[v31++].m_slope;
      v35 = v30 - this->m_intervals.m_data[v31 - 1].m_leftX;
      v33[v31 - 1].m_leftX = v30 - this->m_intervals.m_data[v31 - 1].m_rightX;
      v33[v31 - 1].m_rightX = v35;
      LODWORD(v33[v31 - 1].m_slope) = LODWORD(v34) ^ _xmm[0];
      v33[v31 - 1].m_offset = (float)(v34 * v30) + v33[v31 - 1].m_offset;
      --v32;
    }
    while ( v32 );
  }
}

