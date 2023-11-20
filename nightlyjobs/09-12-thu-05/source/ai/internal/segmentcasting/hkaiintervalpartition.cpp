// File Line: 16
// RVA: 0x12E0A40
void __fastcall hkaiIntervalPartition::hkaiIntervalPartition(hkaiIntervalPartition *this)
{
  hkResult result; // [rsp+40h] [rbp+8h]

  this->m_intervals.m_capacityAndFlags = 2147483648;
  this->m_intervals.m_data = 0i64;
  this->m_intervals.m_size = 0;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, 16, 20);
}

// File Line: 21
// RVA: 0x12E0A90
void __fastcall hkaiIntervalPartition::reserve(hkaiIntervalPartition *this, int numIntervals)
{
  int v2; // eax
  int v3; // eax
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this->m_intervals.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v2 < numIntervals )
  {
    v3 = 2 * v2;
    if ( numIntervals < v3 )
      numIntervals = v3;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      this,
      numIntervals,
      20);
  }
}

// File Line: 26
// RVA: 0x12E0DF0
char __fastcall hkaiIntervalPartition::isOk(hkaiIntervalPartition *this)
{
  int v1; // esi
  signed __int64 v2; // rbx
  hkaiIntervalPartition *v3; // r14
  int v4; // edi
  hkaiIntervalPartition::Interval *v5; // r15
  float *v6; // rax

  v1 = this->m_intervals.m_size;
  v2 = 0i64;
  v3 = this;
  v4 = 0;
  if ( v1 <= 0 )
  {
LABEL_5:
    if ( v1 - 1 <= 0 )
      return 1;
    v6 = &v3->m_intervals.m_data[1].m_leftX;
    while ( *v6 >= *(v6 - 4) )
    {
      ++v2;
      v6 += 5;
      if ( v2 >= v1 - 1 )
        return 1;
    }
  }
  else
  {
    v5 = this->m_intervals.m_data;
    while ( hkaiIntervalPartition::Interval::isOk(&v5[v4]) )
    {
      if ( ++v4 >= v1 )
        goto LABEL_5;
    }
  }
  return 0;
}

// File Line: 48
// RVA: 0x12E2C10
void __fastcall hkaiIntervalPartition::addRemovingDupes(hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *intervals, hkaiIntervalPartition::Interval *interval)
{
  float v2; // xmm1_4
  hkaiIntervalPartition::Interval *v3; // rdi
  hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *v4; // rbx
  int v5; // er8
  hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *v6; // rdx
  int v7; // eax
  hkaiIntervalPartition::Interval *v8; // rcx
  hkaiIntervalPartition::Interval *v9; // rcx
  signed __int64 v10; // rdx

  v2 = interval->m_rightX;
  v3 = interval;
  v4 = intervals;
  if ( interval->m_leftX != v2 )
  {
    v5 = intervals->m_size;
    if ( v5 )
    {
      v7 = v5 - 1;
      v8 = intervals->m_data;
      if ( interval->m_slope == v4->m_data[v5 - 1].m_slope
        && interval->m_offset == v8[v7].m_offset
        && interval->m_leftX == v8[v7].m_rightX
        && v8[v5 - 1].m_data == interval->m_data )
      {
        v8[v5 - 1].m_rightX = v2;
        return;
      }
      if ( v5 != (v4->m_capacityAndFlags & 0x3FFFFFFF) )
        goto LABEL_13;
      v6 = v4;
    }
    else
    {
      if ( intervals->m_capacityAndFlags & 0x3FFFFFFF )
      {
LABEL_13:
        v9 = v4->m_data;
        v10 = v4->m_size;
        v9[v10].m_leftX = v3->m_leftX;
        v9[v10].m_rightX = v3->m_rightX;
        v9[v10].m_slope = v3->m_slope;
        v9[v10].m_offset = v3->m_offset;
        v9[v10].m_data = v3->m_data;
        ++v4->m_size;
        return;
      }
      v6 = intervals;
    }
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 20);
    goto LABEL_13;
  }
}

// File Line: 83
// RVA: 0x12E3950
void __fastcall hkaiIntervalPartition::unionOne<1>(hkaiIntervalPartition *this, hkaiIntervalPartition::Interval *interval)
{
  hkaiIntervalPartition::Interval *v2; // rbx
  hkaiIntervalPartition *v3; // r12
  int v4; // eax
  __int64 v5; // r13
  int v6; // er14
  __int64 v7; // r15
  signed __int64 i; // rdi
  hkaiIntervalPartition::Interval *v9; // rsi
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  unsigned int v13; // xmm0_4
  hkaiIntervalPartition::Interval *v14; // rdx
  int v15; // xmm1_4
  int v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  unsigned int v20; // xmm0_4
  float v21; // xmm1_4
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
  int v40; // ecx
  int v41; // er8
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
  float v53; // xmm0_4
  float v54; // xmm1_4
  unsigned int v55; // xmm0_4
  float v56; // xmm1_4
  hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> intervals; // [rsp+30h] [rbp-D0h]
  hkaiIntervalPartition::Interval v58; // [rsp+40h] [rbp-C0h]
  hkaiIntervalPartition::Interval v59; // [rsp+58h] [rbp-A8h]
  hkaiIntervalPartition::Interval v60; // [rsp+70h] [rbp-90h]
  hkaiIntervalPartition::Interval intervala; // [rsp+88h] [rbp-78h]
  hkaiIntervalPartition::Interval other; // [rsp+A0h] [rbp-60h]
  int v63; // [rsp+B4h] [rbp-4Ch]
  int v64; // [rsp+B8h] [rbp-48h]
  int index; // [rsp+150h] [rbp+50h]

  v2 = interval;
  v3 = this;
  v4 = hkaiIntervalPartition::findRightInterval(this, interval->m_leftX);
  index = v4;
  if ( v4 == v3->m_intervals.m_size )
  {
    hkaiIntervalPartition::addRemovingDupes(&v3->m_intervals, v2);
    return;
  }
  v5 = v4;
  intervals.m_capacityAndFlags = 2147483648;
  v6 = v4;
  v7 = v4;
  intervals.m_data = 0i64;
  intervals.m_size = 0;
  for ( i = v4; ; ++i )
  {
    v9 = v3->m_intervals.m_data;
    v10 = v3->m_intervals.m_data[i].m_leftX;
    if ( v7 == v5 )
      break;
    v21 = v2->m_rightX;
    if ( v10 > v21 )
    {
      v58.m_leftX = v2->m_leftX;
      v53 = v2->m_slope;
      v58.m_rightX = v21;
      v54 = v2->m_offset;
      v58.m_slope = v53;
      v55 = v2->m_data;
      v58.m_offset = v54;
      v56 = *((float *)&v9[i] - 4);
      v58.m_data = v55;
      v58.m_leftX = v56;
      hkaiIntervalPartition::addRemovingDupes(&intervals, &v58);
      goto LABEL_28;
    }
    intervala.m_leftX = v2->m_leftX;
    v22 = v2->m_slope;
    intervala.m_rightX = v21;
    v14 = &intervala;
    v23 = v2->m_offset;
    intervala.m_slope = v22;
    v24 = v2->m_data;
    intervala.m_offset = v23;
    v25 = *((float *)&v9[i] - 4);
    intervala.m_data = v24;
    intervala.m_leftX = v25;
    intervala.m_rightX = v10;
LABEL_11:
    hkaiIntervalPartition::addRemovingDupes(&intervals, v14);
    v26 = v9[i].m_leftX;
    v27 = v9[i].m_slope;
    v28 = v2->m_slope;
    v59.m_rightX = v9[i].m_rightX;
    v29 = v9[i].m_data;
    v59.m_leftX = v26;
    v30 = v9[i].m_offset;
    v59.m_data = v29;
    v31 = v2->m_rightX;
    v59.m_offset = v30;
    v32 = v2->m_leftX;
    v60.m_rightX = v31;
    v33 = v2->m_data;
    v60.m_leftX = v32;
    v34 = v2->m_offset;
    v60.m_data = v33;
    v35 = v9[i].m_leftX;
    v60.m_offset = v34;
    v36 = fmaxf(v35, v2->m_leftX);
    v37 = fminf(v9[i].m_rightX, v2->m_rightX);
    v59.m_slope = v27;
    v60.m_rightX = v37;
    v59.m_rightX = v37;
    v60.m_slope = v28;
    v60.m_leftX = v36;
    v59.m_leftX = v36;
    if ( v27 == v28 )
    {
      v38 = &v60;
      if ( v9[i].m_offset > v2->m_offset )
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
    if ( v9[i].m_rightX > v2->m_rightX )
    {
      v50 = v9[i].m_rightX;
      v58.m_leftX = v9[i].m_leftX;
      v51 = v9[i].m_slope;
      v58.m_rightX = v50;
      v52 = v9[i].m_offset;
      v58.m_slope = v51;
      v48 = v9[i].m_data;
      v58.m_offset = v52;
      v49 = v2->m_rightX;
LABEL_25:
      v58.m_data = v48;
      v58.m_leftX = v49;
      hkaiIntervalPartition::addRemovingDupes(&intervals, &v58);
      ++v6;
LABEL_28:
      v41 = index;
      goto LABEL_29;
    }
    if ( v6 == v3->m_intervals.m_size - 1 )
    {
      v45 = v2->m_rightX;
      v58.m_leftX = v2->m_leftX;
      v46 = v2->m_slope;
      v58.m_rightX = v45;
      v47 = v2->m_offset;
      v58.m_slope = v46;
      v48 = v2->m_data;
      v58.m_offset = v47;
      v49 = v9[i].m_rightX;
      goto LABEL_25;
    }
    ++v6;
    ++v7;
  }
  if ( v10 < v2->m_rightX )
  {
    v11 = v2->m_leftX;
    if ( v2->m_leftX >= v10 )
    {
      v17 = v9[i].m_rightX;
      v18 = v9[i].m_slope;
      v58.m_leftX = v3->m_intervals.m_data[i].m_leftX;
      v14 = &v58;
      v58.m_rightX = v17;
      v19 = v9[i].m_offset;
      v58.m_slope = v18;
      v20 = v9[i].m_data;
      v58.m_offset = v19;
      v58.m_rightX = v11;
      v58.m_data = v20;
    }
    else
    {
      v12 = v2->m_rightX;
      v13 = LODWORD(v2->m_slope);
      other.m_slope = v2->m_leftX;
      v14 = (hkaiIntervalPartition::Interval *)((char *)&other + 8);
      other.m_offset = v12;
      v15 = LODWORD(v2->m_offset);
      other.m_data = v13;
      v16 = v2->m_data;
      v63 = v15;
      other.m_offset = v10;
      v64 = v16;
    }
    goto LABEL_11;
  }
  v40 = intervals.m_size;
  if ( intervals.m_size == (intervals.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &intervals, 20);
    v40 = intervals.m_size;
  }
  v41 = index;
  v42 = v40;
  v43 = intervals.m_data;
  v44 = v42;
  v6 = index;
  intervals.m_data[v44].m_leftX = v2->m_leftX;
  v43[v44].m_rightX = v2->m_rightX;
  v43[v44].m_slope = v2->m_slope;
  v43[v44].m_offset = v2->m_offset;
  v43[v44].m_data = v2->m_data;
  ++intervals.m_size;
LABEL_29:
  hkArrayBase<hkaiIntervalPartition::Interval>::_spliceInto(
    (hkArrayBase<hkaiIntervalPartition::Interval> *)&v3->m_intervals.m_data,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v41,
    v6 - v41,
    intervals.m_data,
    intervals.m_size);
  intervals.m_size = 0;
  if ( intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
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
hkaiIntervalPartition::Interval *__fastcall hkaiIntervalPartition::accessInterval(hkaiIntervalPartition *this, int index)
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
void __fastcall hkaiIntervalPartition::Interval::setFromEndpoints(hkaiIntervalPartition::Interval *this, hkVector2f *left, hkVector2f *right, unsigned int data)
{
  hkaiIntervalPartition::Interval::setFromEndpoints(this, left->x, left->y, right->x, right->y, data);
}

// File Line: 225
// RVA: 0x12E0740
void __fastcall hkaiIntervalPartition::Interval::setFromEndpoints(hkaiIntervalPartition::Interval *this, float leftX, float leftY, float rightX, float rightY, unsigned int data)
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
hkVector2f __fastcall hkaiIntervalPartition::Interval::getLeftEndpoint(hkaiIntervalPartition::Interval *this, float *a2)
{
  float v2; // xmm1_4
  hkVector2f v3; // rbx
  float v4; // xmm0_4
  hkVector2f result; // rax

  v2 = this->m_leftX;
  v3 = (hkVector2f)a2;
  *a2 = this->m_leftX;
  v4 = hkaiIntervalPartition::Interval::evaluateAt(this, v2);
  result = v3;
  *(float *)(*(_QWORD *)&v3 + 4i64) = v4;
  return result;
}

// File Line: 247
// RVA: 0x12E0800
hkVector2f __fastcall hkaiIntervalPartition::Interval::getRightEndpoint(hkaiIntervalPartition::Interval *this, float *a2)
{
  float v2; // xmm1_4
  hkVector2f v3; // rbx
  float v4; // xmm0_4
  hkVector2f result; // rax

  v2 = this->m_rightX;
  v3 = (hkVector2f)a2;
  *a2 = v2;
  v4 = hkaiIntervalPartition::Interval::evaluateAt(this, v2);
  result = v3;
  *(float *)(*(_QWORD *)&v3 + 4i64) = v4;
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
hkaiIntervalPartition::Interval *__fastcall hkaiIntervalPartition::Interval::intersect(hkaiIntervalPartition::Interval *this, hkaiIntervalPartition::Interval *other, __int64 a3)
{
  hkaiIntervalPartition::Interval *v3; // rbx
  float v4; // xmm1_4
  float v5; // xmm0_4
  hkaiIntervalPartition::Interval *result; // rax

  v3 = other;
  v4 = (float)(*(float *)(a3 + 12) - this->m_offset) / (float)(this->m_slope - *(float *)(a3 + 8));
  other->m_leftX = v4;
  v5 = hkaiIntervalPartition::Interval::evaluateAt(this, v4);
  result = v3;
  v3->m_rightX = v5;
  return result;
}

// File Line: 272
// RVA: 0x12E0850
_BOOL8 __fastcall hkaiIntervalPartition::Interval::operator==(hkaiIntervalPartition::Interval *this, hkaiIntervalPartition::Interval *other)
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
  float v2; // xmm0_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm0_4

  v2 = shift;
  v3 = shift;
  v4 = shift * this->m_slope;
  v5 = v3 + this->m_rightX;
  this->m_leftX = v2 + this->m_leftX;
  v6 = this->m_offset;
  this->m_rightX = v5;
  this->m_offset = v6 - v4;
}

// File Line: 288
// RVA: 0x12E0940
void __fastcall hkaiIntervalPartition::Interval::shiftY(hkaiIntervalPartition::Interval *this, float shift)
{
  this->m_offset = shift + this->m_offset;
}

// File Line: 293
// RVA: 0x12E0960
bool __fastcall hkaiIntervalPartition::Interval::clampY(hkaiIntervalPartition::Interval *this, float front, float back)
{
  float v3; // xmm3_4
  float v4; // xmm4_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  bool result; // al
  float v12; // xmm0_4
  float v13; // [rsp+10h] [rbp+10h]

  v3 = front;
  if ( front >= back )
    goto LABEL_13;
  v4 = this->m_slope;
  if ( v4 > 0.0 )
  {
    v5 = 1.0 / v4;
    v6 = (float)(v3 - this->m_offset) * (float)(1.0 / v4);
LABEL_6:
    v8 = (float)(back - this->m_offset) * v5;
    v9 = fminf(fmaxf(this->m_leftX, v6), v8);
    v13 = this->m_rightX;
    this->m_leftX = v9;
    v10 = fminf(fmaxf(v13, v6), v8);
    this->m_rightX = v10;
    return v10 > v9;
  }
  if ( v4 < 0.0 )
  {
    v5 = 1.0 / v4;
    v7 = back;
    back = v3;
    v6 = (float)(v7 - this->m_offset) * v5;
    goto LABEL_6;
  }
  v12 = this->m_offset;
  if ( v12 < front || v12 >= back )
LABEL_13:
    result = 0;
  else
    result = 1;
  return result;
}

// File Line: 323
// RVA: 0x12E2D10
_BOOL8 __fastcall hkaiIntervalPartition::Interval::clampFunc<0>(hkaiIntervalPartition::Interval *this, float slope, float offset)
{
  float v3; // xmm7_4
  hkaiIntervalPartition::Interval *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm8_4
  bool v7; // di
  float v9; // [rsp+80h] [rbp+18h]

  v3 = this->m_leftX;
  v4 = this;
  v5 = hkaiIntervalPartition::Interval::evaluateAt(this, this->m_leftX);
  v6 = v4->m_rightX;
  v7 = v5 > (float)((float)(v3 * slope) + offset);
  if ( v7 == hkaiIntervalPartition::Interval::evaluateAt(v4, v4->m_rightX) > (float)((float)(v6 * slope) + offset) )
    return v7;
  v9 = (float)(offset - v4->m_offset) / (float)(v4->m_slope - slope);
  if ( v7 )
    v4->m_rightX = fminf(v6, v9);
  else
    v4->m_leftX = fmaxf(v3, v9);
  return v4->m_leftX < v4->m_rightX;
}

// File Line: 358
// RVA: 0x12E0E90
void __fastcall hkaiIntervalPartition::appendInterval(hkaiIntervalPartition *this, hkaiIntervalPartition::Interval *interval)
{
  hkaiIntervalPartition::Interval *v2; // rdi
  hkaiIntervalPartition *v3; // rbx
  _DWORD *v4; // rdx

  v2 = interval;
  v3 = this;
  if ( this->m_intervals.m_size == (this->m_intervals.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, 20);
  v4 = (_DWORD *)&v3->m_intervals.m_data[v3->m_intervals.m_size].m_leftX;
  *v4 = LODWORD(v2->m_leftX);
  v4[1] = LODWORD(v2->m_rightX);
  v4[2] = LODWORD(v2->m_slope);
  v4[3] = LODWORD(v2->m_offset);
  v4[4] = v2->m_data;
  ++v3->m_intervals.m_size;
}

// File Line: 365
// RVA: 0x12E10B0
__int64 __fastcall hkaiIntervalPartition::findLeftInterval(hkaiIntervalPartition *this, float x)
{
  int v2; // er9
  int v3; // er8
  __int64 v4; // rdx

  v2 = this->m_intervals.m_size;
  v3 = -1;
  while ( v3 < v2 - 1 )
  {
    v4 = (v2 + v3) / 2;
    if ( x < this->m_intervals.m_data[v4].m_leftX )
      v2 = v4;
    else
      v3 = v4;
  }
  return (unsigned int)v3;
}

// File Line: 388
// RVA: 0x12E1100
__int64 __fastcall hkaiIntervalPartition::findRightInterval(hkaiIntervalPartition *this, float x)
{
  unsigned int v2; // er8
  int v3; // er9
  __int64 v4; // rdx

  v2 = this->m_intervals.m_size;
  v3 = -1;
  while ( v3 < (signed int)(v2 - 1) )
  {
    v4 = (signed int)(v2 + v3) / 2;
    if ( x < this->m_intervals.m_data[v4].m_rightX )
      v2 = v4;
    else
      v3 = v4;
  }
  return v2;
}

// File Line: 411
// RVA: 0x12E1070
int __fastcall hkaiIntervalPartition::findInterval(hkaiIntervalPartition *this, float x)
{
  hkaiIntervalPartition *v2; // rbx
  int result; // eax

  v2 = this;
  result = hkaiIntervalPartition::findLeftInterval(this, x);
  if ( result < 0 || x >= v2->m_intervals.m_data[result].m_rightX )
    result = -1;
  return result;
}

// File Line: 417
// RVA: 0x12E1150
signed __int64 __fastcall hkaiIntervalPartition::equals(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  int v2; // edi
  int v4; // ebx
  hkaiIntervalPartition::Interval *v5; // rsi
  hkaiIntervalPartition::Interval *v6; // r14

  v2 = this->m_intervals.m_size;
  if ( v2 != other->m_intervals.m_size )
    return 0i64;
  v4 = 0;
  if ( v2 <= 0 )
    return 1i64;
  v5 = other->m_intervals.m_data;
  v6 = this->m_intervals.m_data;
  while ( (unsigned int)hkaiIntervalPartition::Interval::operator==(&v6[v4], &v5[v4]) )
  {
    if ( ++v4 >= v2 )
      return 1i64;
  }
  return 0i64;
}

// File Line: 435
// RVA: 0x12E1020
void __fastcall hkaiIntervalPartition::appendIntervalFromEndpoints(hkaiIntervalPartition *this, float leftX, float leftY, float rightX, float rightY, unsigned int data)
{
  hkaiIntervalPartition *v6; // rbx
  hkaiIntervalPartition::Interval interval; // [rsp+30h] [rbp-28h]

  v6 = this;
  hkaiIntervalPartition::Interval::setFromEndpoints(&interval, leftX, leftY, rightX, rightY, data);
  hkaiIntervalPartition::appendInterval(v6, &interval);
}

// File Line: 443
// RVA: 0x12E0AE0
void __fastcall hkaiIntervalPartition::shiftX(hkaiIntervalPartition *this, float shift)
{
  int v2; // eax
  hkaiIntervalPartition *v3; // rsi
  __int64 v4; // rdi
  __int64 v5; // rbx

  v2 = this->m_intervals.m_size;
  v3 = this;
  if ( v2 > 0 )
  {
    v4 = (unsigned int)v2;
    v5 = 0i64;
    do
    {
      hkaiIntervalPartition::Interval::shiftX(&v3->m_intervals.m_data[v5], shift);
      ++v5;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 451
// RVA: 0x12E0B50
void __fastcall hkaiIntervalPartition::shiftY(hkaiIntervalPartition *this, float shift)
{
  int v2; // eax
  hkaiIntervalPartition *v3; // rsi
  __int64 v4; // rdi
  __int64 v5; // rbx

  v2 = this->m_intervals.m_size;
  v3 = this;
  if ( v2 > 0 )
  {
    v4 = (unsigned int)v2;
    v5 = 0i64;
    do
    {
      hkaiIntervalPartition::Interval::shiftY(&v3->m_intervals.m_data[v5], shift);
      ++v5;
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
  hkaiIntervalPartition *v3; // rdx
  int v4; // er9
  __int64 v5; // rcx
  __int64 v6; // r11
  float *v7; // r8
  float *v8; // rax
  int v9; // er11
  signed __int64 v10; // r9
  signed __int64 v11; // r9
  __int64 v12; // rcx
  int v13; // eax
  __int64 v14; // r8
  __int64 v15; // rax

  v3 = this;
  v4 = 0;
  v5 = 0i64;
  v6 = v3->m_intervals.m_size;
  if ( (signed int)v6 <= 0 )
    goto LABEL_5;
  v7 = &v3->m_intervals.m_data->m_leftX;
  v8 = &v3->m_intervals.m_data->m_rightX;
  while ( left >= *v8 )
  {
    ++v5;
    ++v4;
    v8 += 5;
    if ( v5 >= v6 )
      goto LABEL_5;
  }
  if ( v4 < 0 )
  {
LABEL_5:
    v3->m_intervals.m_size = 0;
  }
  else
  {
    if ( v4 > 0 )
    {
      v9 = v6 - v4;
      v3->m_intervals.m_size = v9;
      v10 = (signed __int64)&v7[5 * v4];
      if ( 20 * v9 > 0 )
      {
        v11 = v10 - (_QWORD)v7;
        v12 = ((unsigned int)(20 * v9 - 1) >> 2) + 1;
        do
        {
          v13 = *(_DWORD *)((char *)v7 + v11);
          ++v7;
          *((_DWORD *)v7 - 1) = v13;
          --v12;
        }
        while ( v12 );
      }
    }
    if ( v3->m_intervals.m_size )
    {
      v3->m_intervals.m_data->m_leftX = fmaxf(left, v3->m_intervals.m_data->m_leftX);
      if ( v3->m_intervals.m_size )
      {
        do
        {
          v14 = v3->m_intervals.m_size;
          if ( right > v3->m_intervals.m_data[v14 - 1].m_leftX )
            break;
          v3->m_intervals.m_size = v14 - 1;
        }
        while ( (_DWORD)v14 != 1 );
      }
    }
    v15 = v3->m_intervals.m_size;
    if ( (_DWORD)v15 )
      *((float *)&v3->m_intervals.m_data[v15] - 4) = fminf(right, *((float *)&v3->m_intervals.m_data[v15] - 4));
  }
}

// File Line: 502
// RVA: 0x12E0CE0
void __fastcall hkaiIntervalPartition::clipY(hkaiIntervalPartition *this, float front, float back)
{
  __int64 v3; // r14
  int v4; // ebp
  hkaiIntervalPartition *v5; // r15
  int v6; // esi
  __int64 v7; // rdi
  __int64 v8; // rbx
  int v9; // eax
  hkaiIntervalPartition::Interval *v10; // rcx

  v3 = this->m_intervals.m_size;
  v4 = 0;
  v5 = this;
  v6 = 0;
  if ( v3 <= 0 )
  {
    this->m_intervals.m_size = 0;
  }
  else
  {
    v7 = 0i64;
    v8 = 0i64;
    do
    {
      LOBYTE(v9) = hkaiIntervalPartition::Interval::clampY(&v5->m_intervals.m_data[v6], front, back);
      if ( v9 )
      {
        v10 = v5->m_intervals.m_data;
        ++v4;
        ++v7;
        v10[v7 - 1].m_leftX = v5->m_intervals.m_data[v8].m_leftX;
        *((_DWORD *)&v10[v7] - 4) = LODWORD(v10[v8].m_rightX);
        *((_DWORD *)&v10[v7] - 3) = LODWORD(v10[v8].m_slope);
        *((_DWORD *)&v10[v7] - 2) = LODWORD(v10[v8].m_offset);
        *((_DWORD *)&v10[v7] - 1) = v10[v8].m_data;
      }
      ++v6;
      ++v8;
      --v3;
    }
    while ( v3 );
    v5->m_intervals.m_size = v4;
  }
}

// File Line: 517
// RVA: 0x12E2E10
void __fastcall hkaiIntervalPartition::clipFunc<0>(hkaiIntervalPartition *this, float slope, float offset)
{
  __int64 v3; // r14
  int v4; // ebp
  hkaiIntervalPartition *v5; // r15
  int v6; // esi
  __int64 v7; // rdi
  __int64 v8; // rbx
  hkaiIntervalPartition::Interval *v9; // rcx

  v3 = this->m_intervals.m_size;
  v4 = 0;
  v5 = this;
  v6 = 0;
  if ( v3 <= 0 )
  {
    this->m_intervals.m_size = 0;
  }
  else
  {
    v7 = 0i64;
    v8 = 0i64;
    do
    {
      if ( (unsigned int)hkaiIntervalPartition::Interval::clampFunc<0>(&v5->m_intervals.m_data[v6], slope, offset) )
      {
        v9 = v5->m_intervals.m_data;
        ++v4;
        ++v7;
        v9[v7 - 1].m_leftX = v5->m_intervals.m_data[v8].m_leftX;
        *((_DWORD *)&v9[v7] - 4) = LODWORD(v9[v8].m_rightX);
        *((_DWORD *)&v9[v7] - 3) = LODWORD(v9[v8].m_slope);
        *((_DWORD *)&v9[v7] - 2) = LODWORD(v9[v8].m_offset);
        *((_DWORD *)&v9[v7] - 1) = v9[v8].m_data;
      }
      ++v6;
      ++v8;
      --v3;
    }
    while ( v3 );
    v5->m_intervals.m_size = v4;
  }
}

// File Line: 535
// RVA: 0x12E2EE0
void __fastcall hkaiIntervalPartition::combine<0,0>(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  int v2; // eax
  hkaiIntervalPartition *v3; // rbx
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v4; // r13
  int v5; // ecx
  __int64 v6; // rax
  char *v7; // rcx
  __int64 v8; // r8
  signed __int64 v9; // rdx
  int v10; // eax
  __int64 v11; // rsi
  __int64 v12; // r15
  int v13; // er9
  int v14; // er14
  int v15; // edi
  float *v16; // rax
  __int64 v17; // r12
  float v18; // xmm1_4
  __int128 v19; // xmm7
  __int128 v20; // xmm9
  unsigned int v21; // xmm0_4
  unsigned int *v22; // rax
  __int64 v23; // rbx
  __int64 v24; // rsi
  __int128 v25; // xmm6
  __int128 v26; // xmm8
  float v27; // xmm0_4
  float v28; // xmm1_4
  unsigned int v29; // xmm0_4
  hkRelocationInfo::Import *v30; // rax
  float v31; // xmm1_4
  hkaiIntervalPartition::Interval *v32; // rax
  float v33; // xmm1_4
  char v34; // r13
  float v35; // xmm10_4
  float v36; // xmm11_4
  hkaiIntervalPartition::Interval *v37; // rdx
  char v38; // cl
  bool v39; // zf
  hkaiIntervalPartition::Interval *v40; // rax
  float v41; // xmm1_4
  hkaiIntervalPartition::Interval *v42; // rax
  float v43; // xmm1_4
  int v44; // ebx
  int i; // er14
  int v46; // ebx
  int v47; // edi
  hkaiIntervalPartition *v48; // r13
  void *array; // [rsp+30h] [rbp-D0h]
  int v50; // [rsp+38h] [rbp-C8h]
  int v51; // [rsp+3Ch] [rbp-C4h]
  hkaiIntervalPartition::Interval interval; // [rsp+40h] [rbp-C0h]
  hkaiIntervalPartition::Interval v53; // [rsp+58h] [rbp-A8h]
  hkaiIntervalPartition::Interval v54; // [rsp+70h] [rbp-90h]
  hkaiIntervalPartition::Interval v55; // [rsp+88h] [rbp-78h]
  int v56; // [rsp+A0h] [rbp-60h]
  __int64 v57; // [rsp+A8h] [rbp-58h]
  hkaiIntervalPartition::Interval v58; // [rsp+B0h] [rbp-50h]
  hkaiIntervalPartition::Interval othera; // [rsp+C8h] [rbp-38h]
  unsigned int v60; // [rsp+E0h] [rbp-20h]
  hkaiIntervalPartition *v61; // [rsp+1A0h] [rbp+A0h]
  hkaiIntervalPartition *v62; // [rsp+1A8h] [rbp+A8h]
  hkResult result; // [rsp+1B0h] [rbp+B0h]
  int v64; // [rsp+1B8h] [rbp+B8h]

  v62 = other;
  v61 = this;
  v2 = this->m_intervals.m_size;
  v3 = other;
  v4 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this;
  v64 = v2;
  if ( !v2 )
  {
    v5 = this->m_intervals.m_capacityAndFlags;
    if ( (v5 & 0x3FFFFFFF) < other->m_intervals.m_size )
    {
      if ( v5 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v4->m_data,
          20 * (v5 & 0x3FFFFFFF));
      LODWORD(v61) = 20 * v3->m_intervals.m_size;
      v4->m_data = (hkRelocationInfo::Import *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                 (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                 (int *)&v61);
      v4->m_capacityAndFlags = (signed int)v61 / 20;
    }
    v6 = v3->m_intervals.m_size;
    v7 = (char *)v4->m_data;
    v4->m_size = v6;
    v8 = v6;
    if ( (signed int)v6 > 0 )
    {
      v9 = (char *)v3->m_intervals.m_data - v7;
      do
      {
        v10 = *(_DWORD *)&v7[v9];
        v7 += 20;
        *((_DWORD *)v7 - 5) = v10;
        *((_DWORD *)v7 - 4) = *(_DWORD *)&v7[v9 - 16];
        *((_DWORD *)v7 - 3) = *(_DWORD *)&v7[v9 - 12];
        *((_DWORD *)v7 - 2) = *(_DWORD *)&v7[v9 - 8];
        *((_DWORD *)v7 - 1) = *(_DWORD *)&v7[v9 - 4];
        --v8;
      }
      while ( v8 );
    }
    return;
  }
  v11 = other->m_intervals.m_size;
  v56 = v11;
  if ( !(_DWORD)v11 )
    return;
  v12 = 0i64;
  v13 = 2 * (v11 + v2);
  v51 = 2147483648;
  v14 = 0;
  v15 = 0;
  array = 0i64;
  v50 = 0;
  if ( v13 > 0 )
  {
    if ( v13 < 0 )
      v13 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v13, 20);
  }
  hkArrayBase<hkaiIntervalPartition::Interval>::_append(
    (hkArrayBase<hkaiIntervalPartition::Interval> *)&array,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (hkaiIntervalPartition::Interval *)v4->m_data,
    v4->m_size);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array,
    v4);
  v16 = (float *)&v4->m_data->m_fromOffset;
  v50 = 0;
  v57 = v11;
  v17 = 0i64;
  v18 = v16[3];
  v19 = *(unsigned int *)v16;
  v20 = *((unsigned int *)v16 + 1);
  interval.m_slope = v16[2];
  v21 = *((_DWORD *)v16 + 4);
  v22 = (unsigned int *)v3->m_intervals.m_data;
  v23 = 0i64;
  v24 = 0i64;
  v25 = *v22;
  v26 = v22[1];
  interval.m_data = v21;
  v27 = *((float *)v22 + 2);
  interval.m_offset = v18;
  v28 = *((float *)v22 + 3);
  v53.m_slope = v27;
  v29 = v22[4];
  LODWORD(v53.m_leftX) = v25;
  v53.m_data = v29;
  LODWORD(v53.m_rightX) = v26;
  v53.m_offset = v28;
  while ( 2 )
  {
    LODWORD(interval.m_rightX) = v20;
    LODWORD(interval.m_leftX) = v19;
    while ( 1 )
    {
      while ( *(float *)&v19 >= *(float *)&v25 )
      {
        if ( *(float *)&v25 >= *(float *)&v19 )
          goto LABEL_27;
        if ( *(float *)&v26 >= *(float *)&v19 )
        {
          *(_QWORD *)&othera.m_slope = *(_QWORD *)&v53.m_leftX;
          *(_QWORD *)&othera.m_data = *(_QWORD *)&v53.m_slope;
          LODWORD(othera.m_offset) = v19;
          v60 = v53.m_data;
          hkaiIntervalPartition::addRemovingDupes(
            (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
            (hkaiIntervalPartition::Interval *)((char *)&othera + 8));
          v25 = v19;
          LODWORD(v53.m_leftX) = v19;
          goto LABEL_27;
        }
        hkaiIntervalPartition::addRemovingDupes(
          (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
          &v53);
        ++v12;
        ++v15;
        ++v23;
        if ( v12 == v57 )
          goto LABEL_55;
        v32 = v62->m_intervals.m_data;
        v25 = LODWORD(v62->m_intervals.m_data[v23].m_leftX);
        v26 = LODWORD(v62->m_intervals.m_data[v23].m_rightX);
        v33 = v62->m_intervals.m_data[v23].m_offset;
        v53.m_slope = v62->m_intervals.m_data[v23].m_slope;
        v53.m_data = v32[v23].m_data;
        LODWORD(v53.m_leftX) = v25;
        LODWORD(v53.m_rightX) = v26;
        v53.m_offset = v33;
      }
      if ( *(float *)&v20 < *(float *)&v25 )
        break;
      *(_QWORD *)&v58.m_leftX = *(_QWORD *)&interval.m_leftX;
      *(_QWORD *)&v58.m_slope = *(_QWORD *)&interval.m_slope;
      LODWORD(v58.m_rightX) = v25;
      v58.m_data = interval.m_data;
      hkaiIntervalPartition::addRemovingDupes(
        (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
        &v58);
      v19 = v25;
      LODWORD(interval.m_leftX) = v25;
LABEL_27:
      v34 = 0;
      v54 = interval;
      LOBYTE(result.m_enum) = 0;
      v55 = v53;
      if ( *(float *)&v20 >= *(float *)&v26 )
      {
        if ( *(float *)&v26 >= *(float *)&v20 )
        {
          v34 = 1;
          LOBYTE(result.m_enum) = 1;
        }
        else
        {
          v19 = v26;
          LODWORD(v54.m_rightX) = v26;
          LOBYTE(result.m_enum) = 1;
          LODWORD(interval.m_leftX) = v26;
        }
      }
      else
      {
        v25 = v20;
        LODWORD(v55.m_rightX) = v20;
        v34 = 1;
        LODWORD(v53.m_leftX) = v20;
      }
      v35 = v54.m_slope;
      v36 = v55.m_slope;
      if ( v54.m_slope == v55.m_slope )
      {
        v37 = &v54;
        if ( v55.m_offset <= v54.m_offset )
          v37 = &v55;
      }
      else
      {
        hkaiIntervalPartition::Interval::intersect(&v54, &othera, (__int64)&v55);
        if ( othera.m_leftX >= v54.m_leftX )
        {
          if ( othera.m_leftX <= v54.m_rightX )
          {
            if ( v35 >= v36 )
            {
              v54.m_rightX = othera.m_leftX;
              v55.m_leftX = othera.m_leftX;
              hkaiIntervalPartition::addRemovingDupes(
                (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
                &v54);
              v37 = &v55;
            }
            else
            {
              v54.m_leftX = othera.m_leftX;
              v55.m_rightX = othera.m_leftX;
              hkaiIntervalPartition::addRemovingDupes(
                (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
                &v55);
              v37 = &v54;
            }
          }
          else
          {
            v37 = &v55;
            if ( v36 <= v35 )
              v37 = &v54;
          }
        }
        else
        {
          v37 = &v54;
          if ( v36 <= v35 )
            v37 = &v55;
        }
      }
      hkaiIntervalPartition::addRemovingDupes(
        (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
        v37);
      v38 = 0;
      v39 = v34 == 0;
      v4 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v61;
      if ( !v39 )
      {
        ++v17;
        ++v14;
        ++v24;
        if ( v17 == v64 )
        {
          v38 = 1;
        }
        else
        {
          v40 = v61->m_intervals.m_data;
          v19 = LODWORD(v61->m_intervals.m_data[v24].m_leftX);
          v20 = LODWORD(v61->m_intervals.m_data[v24].m_rightX);
          v41 = v61->m_intervals.m_data[v24].m_offset;
          interval.m_slope = v61->m_intervals.m_data[v24].m_slope;
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
        if ( v12 == v57 )
          goto LABEL_55;
        v42 = v62->m_intervals.m_data;
        v25 = LODWORD(v62->m_intervals.m_data[v23].m_leftX);
        v26 = LODWORD(v62->m_intervals.m_data[v23].m_rightX);
        v43 = v62->m_intervals.m_data[v23].m_offset;
        v53.m_slope = v62->m_intervals.m_data[v23].m_slope;
        v53.m_data = v42[v23].m_data;
        LODWORD(v53.m_leftX) = v25;
        LODWORD(v53.m_rightX) = v26;
        v53.m_offset = v43;
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
    if ( v17 != v64 )
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
  v44 = v64;
  if ( v14 < v64 )
  {
    hkaiIntervalPartition::addRemovingDupes(
      (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
      &interval);
    for ( i = v14 + 1; i != v44; ++i )
      hkaiIntervalPartition::addRemovingDupes(
        (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
        (hkaiIntervalPartition::Interval *)v4->m_data + i);
  }
  v46 = v56;
  if ( v15 < v56 )
  {
    hkaiIntervalPartition::addRemovingDupes(
      (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
      &v53);
    v47 = v15 + 1;
    if ( v47 != v46 )
    {
      v48 = v62;
      do
        hkaiIntervalPartition::addRemovingDupes(
          (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
          &v48->m_intervals.m_data[v47++]);
      while ( v47 != v46 );
      v4 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v61;
    }
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    v4,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
  v50 = 0;
  if ( v51 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      20 * (v51 & 0x3FFFFFFF));
}erHeapAll

// File Line: 752
// RVA: 0x12E11D0
void __fastcall hkaiIntervalPartition::clipMin(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  __int64 v2; // r13
  hkaiIntervalPartition *v3; // r12
  hkaiIntervalPartition *v4; // rbx
  __int64 v5; // rdi
  int v6; // er9
  int v7; // esi
  unsigned int *v8; // rax
  __int64 *v9; // rcx
  __int64 v10; // r15
  float v11; // xmm0_4
  float v12; // xmm1_4
  __int128 v13; // xmm7
  hkaiIntervalPartition *v14; // r14
  __int128 v15; // xmm9
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
  float v37; // xmm1_4
  __int64 v38; // rax
  unsigned int v39; // xmm1_4
  int i; // esi
  hkaiIntervalPartition::Interval interval; // [rsp+30h] [rbp-B8h]
  void *array; // [rsp+48h] [rbp-A0h]
  int v43; // [rsp+50h] [rbp-98h]
  int v44; // [rsp+54h] [rbp-94h]
  unsigned __int64 v45; // [rsp+58h] [rbp-90h]
  unsigned __int64 v46; // [rsp+60h] [rbp-88h]
  unsigned int v47; // [rsp+68h] [rbp-80h]
  hkaiIntervalPartition::Interval v48; // [rsp+70h] [rbp-78h]
  float v49; // [rsp+84h] [rbp-64h]
  unsigned int v50; // [rsp+88h] [rbp-60h]
  hkaiIntervalPartition::Interval othera; // [rsp+90h] [rbp-58h]
  unsigned int v52; // [rsp+A8h] [rbp-40h]
  hkaiIntervalPartition *v53; // [rsp+168h] [rbp+80h]
  unsigned int **vars0; // [rsp+170h] [rbp+88h]
  int retaddr; // [rsp+178h] [rbp+90h]
  hkaiIntervalPartition *result; // [rsp+180h] [rbp+98h]
  hkaiIntervalPartition *v57; // [rsp+188h] [rbp+A0h]

  v57 = other;
  result = this;
  v2 = this->m_intervals.m_size;
  v3 = this;
  retaddr = v2;
  if ( !(_DWORD)v2 )
    return;
  v4 = (hkaiIntervalPartition *)other->m_intervals.m_size;
  if ( !(_DWORD)v4 )
    return;
  v5 = 0i64;
  v6 = 2 * ((_DWORD)v4 + v2);
  v44 = 2147483648;
  v7 = 0;
  array = 0i64;
  v43 = 0;
  if ( v6 > 0 )
  {
    if ( v6 < 0 )
      v6 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v6,
      20);
  }
  hkArrayBase<hkaiIntervalPartition::Interval>::_append(
    (hkArrayBase<hkaiIntervalPartition::Interval> *)&array,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v3->m_intervals.m_data,
    v3->m_intervals.m_size);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v3);
  v8 = (unsigned int *)v3->m_intervals.m_data;
  v9 = (__int64 *)vars0;
  v43 = 0;
  result = v4;
  v10 = 0i64;
  v11 = *((float *)v8 + 2);
  v12 = *((float *)v8 + 3);
  v13 = *v8;
  v14 = 0i64;
  *(_QWORD *)&v48.m_leftX = v2;
  v15 = v8[1];
  interval.m_slope = v11;
  v16 = v8[4];
  v17 = *vars0;
  v18 = **vars0;
  v19 = (*vars0)[1];
  interval.m_data = v16;
  v20 = v17[2];
  interval.m_offset = v12;
  v46 = __PAIR__(v17[3], v20);
  v21 = v17[4];
  v45 = __PAIR__(v19, (unsigned int)v18);
  v22 = v4;
  v23 = 0i64;
  v47 = v21;
  while ( 2 )
  {
    LODWORD(interval.m_rightX) = v15;
    LODWORD(interval.m_leftX) = v13;
    while ( *(float *)&v13 >= *(float *)&v18 )
    {
      if ( *(float *)&v18 >= *(float *)&v13 )
        goto LABEL_19;
      if ( *(float *)&v19 >= *(float *)&v13 )
      {
        v18 = v13;
        LODWORD(v45) = v13;
LABEL_19:
        v30 = 0;
        v31 = 0;
        *(_QWORD *)&v48.m_leftX = *(_QWORD *)&interval.m_leftX;
        v47 = interval.m_data;
        *(_QWORD *)&v48.m_slope = v45;
        *(_QWORD *)&v48.m_data = v46;
        v50 = interval.m_data;
        if ( *(float *)&v15 >= *(float *)&v19 )
        {
          if ( *(float *)&v19 >= *(float *)&v15 )
          {
            v30 = 1;
            v31 = 1;
          }
          else
          {
            v13 = v19;
            LODWORD(v48.m_rightX) = v19;
            v31 = 1;
            LODWORD(interval.m_leftX) = v19;
          }
        }
        else
        {
          v18 = v15;
          LODWORD(v48.m_offset) = v15;
          v30 = 1;
          LODWORD(v45) = v15;
        }
        v32 = v48.m_slope;
        v33 = *(float *)&v48.m_data;
        if ( v48.m_slope == *(float *)&v48.m_data )
        {
          if ( v48.m_offset < v49 )
            goto LABEL_36;
        }
        else
        {
          hkaiIntervalPartition::Interval::intersect(&v48, &othera, (__int64)&v48.m_slope);
          if ( othera.m_leftX >= v48.m_leftX )
          {
            if ( othera.m_leftX <= v48.m_rightX )
            {
              if ( v32 >= v33 )
                v48.m_rightX = othera.m_leftX;
              else
                v48.m_leftX = othera.m_leftX;
LABEL_36:
              hkaiIntervalPartition::addRemovingDupes(
                (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
                &v48);
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
        v3 = v53;
        if ( !v35 )
        {
          ++v10;
          ++v7;
          ++v5;
          if ( v10 == *(_QWORD *)&v48.m_leftX )
          {
            v34 = 1;
          }
          else
          {
            v36 = v53->m_intervals.m_data;
            v13 = LODWORD(v53->m_intervals.m_data[v5].m_leftX);
            v15 = LODWORD(v53->m_intervals.m_data[v5].m_rightX);
            v37 = v53->m_intervals.m_data[v5].m_offset;
            interval.m_slope = v53->m_intervals.m_data[v5].m_slope;
            interval.m_data = v36[v5].m_data;
            LODWORD(interval.m_leftX) = v13;
            LODWORD(interval.m_rightX) = v15;
            interval.m_offset = v37;
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
          LODWORD(v46) = (*vars0)[v23 + 2];
          v47 = *(_DWORD *)(v23 * 4 + v38 + 16);
          v45 = __PAIR__(v19, (unsigned int)v18);
          HIDWORD(v46) = v39;
        }
        v22 = result;
        v2 = *(_QWORD *)&v48.m_leftX;
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
        LODWORD(v46) = *(_DWORD *)(v23 * 4 + *v9 + 8);
        v29 = *(_DWORD *)(v23 * 4 + v27 + 16);
        v22 = result;
        v47 = v29;
        v45 = __PAIR__(v19, (unsigned int)v18);
        HIDWORD(v46) = v28;
      }
    }
    if ( *(float *)&v15 >= *(float *)&v18 )
    {
      *(_QWORD *)&othera.m_slope = *(_QWORD *)&interval.m_leftX;
      *(_QWORD *)&othera.m_data = *(_QWORD *)&interval.m_slope;
      LODWORD(othera.m_offset) = v18;
      v52 = interval.m_data;
      hkaiIntervalPartition::addRemovingDupes(
        (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
        (hkaiIntervalPartition::Interval *)((char *)&othera + 8));
      v13 = v18;
      LODWORD(interval.m_leftX) = v18;
      goto LABEL_19;
    }
    hkaiIntervalPartition::addRemovingDupes(
      (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
      &interval);
    ++v10;
    ++v7;
    ++v5;
    if ( v10 != v2 )
    {
      v24 = v3->m_intervals.m_data;
      v9 = (__int64 *)vars0;
      v25 = v3->m_intervals.m_data[v5].m_offset;
      v13 = LODWORD(v3->m_intervals.m_data[v5].m_leftX);
      v15 = LODWORD(v3->m_intervals.m_data[v5].m_rightX);
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
  if ( v7 < retaddr )
  {
    hkaiIntervalPartition::addRemovingDupes(
      (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
      &interval);
    for ( i = v7 + 1; i != retaddr; ++i )
      hkaiIntervalPartition::addRemovingDupes(
        (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
        &v3->m_intervals.m_data[i]);
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v3,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
  v43 = 0;
  if ( v44 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      20 * (v44 & 0x3FFFFFFF));
}

// File Line: 1025
// RVA: 0x12E1CA0
void __fastcall hkaiIntervalPartition::swap(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)other);
}

// File Line: 1030
// RVA: 0x12E1CB0
_BOOL8 __fastcall hkaiIntervalPartition::coversInterval(hkaiIntervalPartition *this, float left, float right)
{
  signed __int64 v3; // rax
  hkaiIntervalPartition::Interval *v5; // r8
  signed __int64 v6; // rcx
  signed __int64 v7; // rdx
  float *v8; // rax

  v3 = this->m_intervals.m_size;
  if ( !(_DWORD)v3 )
    return 0i64;
  v5 = this->m_intervals.m_data;
  if ( left < this->m_intervals.m_data->m_leftX )
    return 0i64;
  v6 = 1i64;
  v7 = v3;
  if ( v3 > 1 )
  {
    v8 = &v5[1].m_leftX;
    while ( *v8 <= *(v8 - 4) )
    {
      ++v6;
      v8 += 5;
      if ( v6 >= v7 )
        return right <= *((float *)&v5[v7] - 4);
    }
    return 0i64;
  }
  return right <= *((float *)&v5[v7] - 4);
}

// File Line: 1059
// RVA: 0x12E1730
void __fastcall hkaiIntervalPartition::clipDefined(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  __int64 v2; // rsi
  hkaiIntervalPartition *v3; // r14
  hkaiIntervalPartition *v4; // r15
  signed __int64 v5; // rdi
  hkaiIntervalPartition::Interval *v6; // rax
  int v7; // er9
  float v8; // xmm1_4
  float v9; // xmm7_4
  float v10; // xmm6_4
  int v11; // xmm0_4
  signed __int64 v12; // rbx
  __int64 v13; // r13
  __int64 v14; // rsi
  hkaiIntervalPartition::Interval *v15; // rax
  float v16; // xmm2_4
  float v17; // xmm8_4
  float v18; // xmm1_4
  int v19; // xmm0_4
  unsigned int v20; // er15
  __int64 v21; // r12
  signed __int64 v22; // rcx
  hkaiIntervalPartition::Interval *v23; // rax
  int v24; // xmm1_4
  void *array; // [rsp+10h] [rbp-69h]
  int v26; // [rsp+18h] [rbp-61h]
  int v27; // [rsp+1Ch] [rbp-5Dh]
  int sizeElem[2]; // [rsp+20h] [rbp-59h]
  __int64 v29; // [rsp+28h] [rbp-51h]
  int v30; // [rsp+30h] [rbp-49h]
  float v31; // [rsp+40h] [rbp-39h]
  float v32; // [rsp+44h] [rbp-35h]
  unsigned int v33; // [rsp+48h] [rbp-31h]
  hkaiIntervalPartition::Interval interval; // [rsp+50h] [rbp-29h]
  hkaiIntervalPartition *v35; // [rsp+E0h] [rbp+67h]
  hkResult result; // [rsp+F0h] [rbp+77h]

  v2 = this->m_intervals.m_size;
  v3 = other;
  v4 = this;
  if ( (_DWORD)v2 )
  {
    v5 = other->m_intervals.m_size;
    if ( (_DWORD)v5 )
    {
      v6 = other->m_intervals.m_data;
      v7 = 2 * (v5 + v2);
      v8 = other->m_intervals.m_data->m_offset;
      v9 = other->m_intervals.m_data->m_leftX;
      v10 = other->m_intervals.m_data->m_rightX;
      v31 = other->m_intervals.m_data->m_slope;
      v11 = v6->m_data;
      array = 0i64;
      v26 = 0;
      v27 = 2147483648;
      v33 = v11;
      v32 = v8;
      if ( v7 > 0 )
      {
        if ( v7 < 0 )
          v7 = 0;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v7, 20);
      }
      hkArrayBase<hkaiIntervalPartition::Interval>::_append(
        (hkArrayBase<hkaiIntervalPartition::Interval> *)&array,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v4->m_intervals.m_data,
        v4->m_intervals.m_size);
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v4);
      v26 = 0;
      v12 = 0i64;
      v13 = v2;
      if ( (signed int)v2 > 0 )
      {
        v14 = 0i64;
        do
        {
          v15 = v4->m_intervals.m_data;
          v16 = v4->m_intervals.m_data[v14].m_leftX;
          v17 = v4->m_intervals.m_data[v14].m_rightX;
          v18 = v4->m_intervals.m_data[v14].m_offset;
          *(float *)&v29 = v4->m_intervals.m_data[v14].m_slope;
          v19 = v15[v14].m_data;
          *(float *)sizeElem = v16;
          *(float *)&sizeElem[1] = v17;
          v30 = v19;
          *((float *)&v29 + 1) = v18;
          if ( v16 < v17 )
          {
            v20 = v30;
            v21 = v29;
            while ( v12 < v5 )
            {
              v22 = v12;
              while ( v16 >= v10 )
              {
                ++v12;
                ++v22;
                if ( v12 >= v5 )
                  goto LABEL_21;
                v23 = v3->m_intervals.m_data;
                v24 = LODWORD(v3->m_intervals.m_data[v22].m_offset);
                v9 = v3->m_intervals.m_data[v22].m_leftX;
                v10 = v3->m_intervals.m_data[v22].m_rightX;
                v31 = v3->m_intervals.m_data[v22].m_slope;
                v33 = v23[v22].m_data;
                v32 = *(float *)&v24;
              }
              if ( v17 <= v9 )
                break;
              if ( v16 < v9 )
              {
                *(_QWORD *)&interval.m_leftX = *(_QWORD *)sizeElem;
                *(_QWORD *)&interval.m_slope = v21;
                interval.m_data = v20;
                interval.m_rightX = v9;
                hkaiIntervalPartition::addRemovingDupes(
                  (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
                  &interval);
              }
              v16 = v10;
              *(float *)sizeElem = v10;
              if ( v10 >= v17 )
                goto LABEL_22;
            }
LABEL_21:
            hkaiIntervalPartition::addRemovingDupes(
              (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
              (hkaiIntervalPartition::Interval *)sizeElem);
LABEL_22:
            v4 = v35;
          }
          ++v14;
          --v13;
        }
        while ( v13 );
      }
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v4,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
      v26 = 0;
      if ( v27 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          20 * (v27 & 0x3FFFFFFF));
    }
  }
}

// File Line: 1121
// RVA: 0x12E19C0
void __fastcall hkaiIntervalPartition::clipNotDefined(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  __int64 v2; // rbx
  hkaiIntervalPartition *v3; // rsi
  hkaiIntervalPartition *v4; // r15
  signed __int64 v5; // rdi
  hkaiIntervalPartition::Interval *v6; // rax
  float v7; // xmm1_4
  int v8; // xmm0_4
  int v9; // er9
  float v10; // xmm8_4
  float v11; // xmm7_4
  __int64 v12; // r13
  __int64 v13; // r14
  signed __int64 i; // rbx
  hkaiIntervalPartition::Interval *v15; // rax
  float v16; // xmm6_4
  float v17; // xmm9_4
  float v18; // xmm1_4
  int v19; // xmm0_4
  unsigned int v20; // er15
  __int64 v21; // r12
  signed __int64 v22; // rcx
  hkaiIntervalPartition::Interval *v23; // rax
  int v24; // xmm1_4
  float v25; // xmm2_4
  void *array; // [rsp+30h] [rbp-79h]
  int v27; // [rsp+38h] [rbp-71h]
  int v28; // [rsp+3Ch] [rbp-6Dh]
  unsigned __int64 v29; // [rsp+40h] [rbp-69h]
  __int64 v30; // [rsp+48h] [rbp-61h]
  int v31; // [rsp+50h] [rbp-59h]
  hkaiIntervalPartition::Interval interval; // [rsp+58h] [rbp-51h]
  float v33; // [rsp+78h] [rbp-31h]
  float v34; // [rsp+7Ch] [rbp-2Dh]
  unsigned int v35; // [rsp+80h] [rbp-29h]
  hkaiIntervalPartition *v36; // [rsp+110h] [rbp+67h]
  hkResult result; // [rsp+120h] [rbp+77h]
  float v38; // [rsp+128h] [rbp+7Fh]

  v36 = this;
  v2 = this->m_intervals.m_size;
  v3 = other;
  v4 = this;
  if ( (_DWORD)v2 )
  {
    v5 = other->m_intervals.m_size;
    if ( (_DWORD)v5 )
    {
      v6 = other->m_intervals.m_data;
      v7 = other->m_intervals.m_data->m_offset;
      v33 = other->m_intervals.m_data->m_slope;
      v8 = v6->m_data;
      v34 = v7;
      v9 = 2 * (v2 + v5);
      v10 = v6->m_leftX;
      v11 = v6->m_rightX;
      v35 = v8;
      array = 0i64;
      v27 = 0;
      v28 = 2147483648;
      if ( v9 > 0 )
      {
        if ( v9 < 0 )
          v9 = 0;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v9, 20);
      }
      hkArrayBase<hkaiIntervalPartition::Interval>::_append(
        (hkArrayBase<hkaiIntervalPartition::Interval> *)&array,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v4->m_intervals.m_data,
        v4->m_intervals.m_size);
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v4);
      v12 = v2;
      v27 = 0;
      v13 = 0i64;
      for ( i = 0i64; v13 < v12; ++v13 )
      {
        v15 = v4->m_intervals.m_data;
        v16 = v4->m_intervals.m_data[v13].m_leftX;
        v17 = v4->m_intervals.m_data[v13].m_rightX;
        v18 = v4->m_intervals.m_data[v13].m_offset;
        *(float *)&v30 = v4->m_intervals.m_data[v13].m_slope;
        v19 = v15[v13].m_data;
        v29 = __PAIR__(LODWORD(v17), LODWORD(v16));
        v31 = v19;
        *((float *)&v30 + 1) = v18;
        if ( v16 < v17 )
        {
          v20 = v31;
          v21 = v30;
          while ( i < v5 )
          {
            v22 = i;
            while ( v16 >= v11 )
            {
              ++i;
              ++v22;
              if ( i >= v5 )
                goto LABEL_21;
              v23 = v3->m_intervals.m_data;
              v24 = LODWORD(v3->m_intervals.m_data[v22].m_offset);
              v10 = v3->m_intervals.m_data[v22].m_leftX;
              v11 = v3->m_intervals.m_data[v22].m_rightX;
              v33 = v3->m_intervals.m_data[v22].m_slope;
              v35 = v23[v22].m_data;
              v34 = *(float *)&v24;
            }
            if ( v17 > v10 )
            {
              *(_QWORD *)&interval.m_slope = v21;
              interval.m_data = v20;
              v25 = fmaxf(v16, v10);
              result.m_enum = HIDWORD(v29);
              v38 = v11;
              v16 = fminf(*((float *)&v29 + 1), v11);
              interval.m_leftX = v25;
              interval.m_rightX = v16;
              if ( v16 > v25 )
                hkaiIntervalPartition::addRemovingDupes(
                  (hkArray<hkaiIntervalPartition::Interval,hkContainerHeapAllocator> *)&array,
                  &interval);
              *(float *)&v29 = v16;
              if ( v16 < v17 )
                continue;
            }
            goto LABEL_22;
          }
LABEL_21:
          v13 = v12;
LABEL_22:
          v4 = v36;
        }
      }
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v4,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
      v27 = 0;
      if ( v28 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          20 * (v28 & 0x3FFFFFFF));
    }
    else
    {
      this->m_intervals.m_size = 0;
    }
  }
}

// File Line: 1190
// RVA: 0x12E1D10
signed __int64 __fastcall hkaiIntervalPartition::tryEvaluateAt(hkaiIntervalPartition *this, float x, float *out)
{
  float *v3; // rdi
  hkaiIntervalPartition *v4; // rbx
  int v5; // eax
  hkaiIntervalPartition::Interval *v6; // rax
  float v7; // xmm0_4
  signed __int64 result; // rax

  v3 = out;
  v4 = this;
  if ( x < 0.0 )
    return 0i64;
  v5 = hkaiIntervalPartition::findInterval(this, x);
  v6 = hkaiIntervalPartition::getInterval(v4, v5);
  v7 = hkaiIntervalPartition::Interval::evaluateAt(v6, x);
  result = 1i64;
  *v3 = v7;
  return result;
}

// File Line: 1205
// RVA: 0x12E1D80
float __fastcall hkaiIntervalPartition::evaluateWithDefault(hkaiIntervalPartition *this, float x, float defaultY)
{
  float out; // [rsp+40h] [rbp+18h]

  out = defaultY;
  hkaiIntervalPartition::tryEvaluateAt(this, x, &out);
  return out;
}

// File Line: 1213
// RVA: 0x12E38C0
void __fastcall hkaiIntervalPartition::Interval::getExtremeY<0>(hkaiIntervalPartition::Interval *this)
{
  if ( this->m_slope <= 0.0 )
    hkaiIntervalPartition::Interval::evaluateAt(this, this->m_rightX);
  else
    hkaiIntervalPartition::Interval::evaluateAt(this, this->m_leftX);
}

// File Line: 1226
// RVA: 0x12E0780
void __fastcall hkaiIntervalPartition::Interval::interpolateParallelogram(hkaiIntervalPartition::Interval *this, hkVector4f *origin, hkVector4f *xVector, hkVector4f *yVector, hkVector4f *leftOut, hkVector4f *rightOut)
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
float __usercall hkaiIntervalPartition::getExtremeY<0>@<xmm0>(hkaiIntervalPartition *this@<rcx>, float a2@<xmm0>)
{
  hkaiIntervalPartition::Interval *v2; // rdi
  hkaiIntervalPartition *v3; // rbx
  signed int v4; // eax
  float v5; // xmm6_4
  hkaiIntervalPartition::Interval *v6; // rbx
  __int64 v7; // rdi

  v2 = this->m_intervals.m_data;
  v3 = this;
  hkaiIntervalPartition::Interval::getExtremeY<0>(this->m_intervals.m_data);
  v4 = v3->m_intervals.m_size;
  v5 = a2;
  if ( v4 > 1 )
  {
    v6 = v2 + 1;
    v7 = (unsigned int)(v4 - 1);
    do
    {
      hkaiIntervalPartition::Interval::getExtremeY<0>(v6);
      ++v6;
      v5 = fminf(v5, a2);
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
  return *((float *)&this->m_intervals.m_data[this->m_intervals.m_size] - 4);
}

// File Line: 1283
// RVA: 0x12E1DB0
void __fastcall hkaiIntervalPartition::complement(hkaiIntervalPartition *this, float minX, float maxX)
{
  hkaiIntervalPartition *v3; // rbx
  float v4; // xmm7_4
  signed int v5; // edi
  signed __int64 v6; // r11
  float v7; // xmm0_4
  float v8; // xmm6_4
  signed __int64 v9; // r9
  signed __int64 v10; // r8
  signed __int64 v11; // rdx
  signed __int64 v12; // rcx
  unsigned __int64 v13; // r10
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  signed __int64 v21; // rdx
  signed __int64 v22; // rcx
  signed __int64 v23; // r9
  float v24; // xmm0_4
  float v25; // xmm1_4
  int v26; // eax
  int v27; // eax
  int v28; // er9
  hkaiIntervalPartition::Interval interval; // [rsp+30h] [rbp-48h]
  hkResult result; // [rsp+80h] [rbp+8h]

  v3 = this;
  v4 = maxX;
  if ( this->m_intervals.m_size )
  {
    v5 = 0;
    v6 = 1i64;
    v7 = this->m_intervals.m_data->m_leftX;
    v8 = this->m_intervals.m_data->m_rightX;
    if ( v7 > minX )
    {
      this->m_intervals.m_data->m_rightX = v7;
      v5 = 1;
      this->m_intervals.m_data->m_leftX = minX;
    }
    v9 = this->m_intervals.m_size;
    v10 = v5;
    if ( v9 > 1 )
    {
      if ( v9 - 1 >= 4 )
      {
        v11 = 1i64;
        v12 = v5;
        v13 = ((unsigned __int64)(v9 - 5) >> 2) + 1;
        v6 = 4 * v13 + 1;
        do
        {
          v14 = v3->m_intervals.m_data[v11].m_leftX;
          v15 = v3->m_intervals.m_data[v11].m_rightX;
          if ( v8 < v14 )
          {
            v3->m_intervals.m_data[v12].m_leftX = v8;
            ++v5;
            ++v10;
            ++v12;
            *((float *)&v3->m_intervals.m_data[v12] - 4) = v14;
          }
          v16 = v3->m_intervals.m_data[v11 + 1].m_leftX;
          v17 = v3->m_intervals.m_data[v11 + 1].m_rightX;
          if ( v15 < v16 )
          {
            v3->m_intervals.m_data[v12].m_leftX = v15;
            ++v5;
            ++v10;
            ++v12;
            *((float *)&v3->m_intervals.m_data[v12] - 4) = v16;
          }
          v18 = v3->m_intervals.m_data[v11 + 2].m_leftX;
          v19 = v3->m_intervals.m_data[v11 + 2].m_rightX;
          if ( v17 < v18 )
          {
            v3->m_intervals.m_data[v12].m_leftX = v17;
            ++v5;
            ++v10;
            ++v12;
            *((float *)&v3->m_intervals.m_data[v12] - 4) = v18;
          }
          v20 = v3->m_intervals.m_data[v11 + 3].m_leftX;
          v8 = v3->m_intervals.m_data[v11 + 3].m_rightX;
          if ( v19 < v20 )
          {
            v3->m_intervals.m_data[v12].m_leftX = v19;
            ++v5;
            ++v10;
            ++v12;
            *((float *)&v3->m_intervals.m_data[v12] - 4) = v20;
          }
          v11 += 4i64;
          --v13;
        }
        while ( v13 );
      }
      if ( v6 < v9 )
      {
        v21 = v10;
        v22 = v6;
        v23 = v9 - v6;
        do
        {
          v24 = v8;
          v25 = v3->m_intervals.m_data[v22].m_leftX;
          v8 = v3->m_intervals.m_data[v22].m_rightX;
          if ( v24 < v25 )
          {
            v3->m_intervals.m_data[v21].m_leftX = v24;
            ++v5;
            ++v21;
            *((float *)&v3->m_intervals.m_data[v21] - 4) = v25;
          }
          ++v22;
          --v23;
        }
        while ( v23 );
      }
    }
    v26 = v3->m_intervals.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v26 < v5 )
    {
      v27 = 2 * v26;
      v28 = v5;
      if ( v5 < v27 )
        v28 = v27;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v28, 20);
    }
    v3->m_intervals.m_size = v5;
    if ( v8 < v4 )
    {
      interval.m_leftX = v8;
      interval.m_rightX = v4;
      *(_QWORD *)&interval.m_slope = 0i64;
      interval.m_data = -1;
      hkaiIntervalPartition::appendInterval(v3, &interval);
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
}

// File Line: 1328
// RVA: 0x12E22F0
void __fastcall hkaiIntervalPartition::remapX(hkaiIntervalPartition *this, float curX1, float curX2, float newX1, float newX2)
{
  signed __int64 v5; // rax
  hkaiIntervalPartition *v6; // r9
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm3_4
  signed __int64 v10; // r10
  float v11; // xmm5_4
  signed __int64 v12; // rdx
  __int64 v13; // rcx
  unsigned __int64 v14; // r8
  hkaiIntervalPartition::Interval *v15; // rax
  float v16; // xmm2_4
  hkaiIntervalPartition::Interval *v17; // rax
  float v18; // xmm2_4
  hkaiIntervalPartition::Interval *v19; // rax
  float v20; // xmm2_4
  hkaiIntervalPartition::Interval *v21; // rax
  float v22; // xmm2_4
  signed __int64 v23; // rcx
  signed __int64 v24; // rdx
  hkaiIntervalPartition::Interval *v25; // rax
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm1_4

  v5 = this->m_intervals.m_size;
  v6 = this;
  if ( (_DWORD)v5 )
  {
    v7 = curX2 - curX1;
    v8 = (float)(newX2 - newX1) / v7;
    v9 = newX1 - (float)(v8 * curX1);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(1.0 - v8)) >> 1) >= 0.000099999997
      || COERCE_FLOAT((unsigned int)(2 * LODWORD(v9)) >> 1) >= 0.0001 )
    {
      v10 = 0i64;
      v11 = 1.0 / v8;
      v12 = this->m_intervals.m_size;
      if ( v5 >= 4 )
      {
        v13 = 0i64;
        v14 = ((unsigned __int64)(v5 - 4) >> 2) + 1;
        v10 = 4 * v14;
        do
        {
          v15 = v6->m_intervals.m_data;
          v13 += 4i64;
          v15[v13 - 4].m_leftX = (float)(v8 * v6->m_intervals.m_data[v13 - 4].m_leftX) + v9;
          *((float *)&v15[v13 - 3] - 4) = (float)(v8 * *((float *)&v15[v13 - 3] - 4)) + v9;
          v16 = v11 * *((float *)&v15[v13 - 3] - 3);
          *((float *)&v15[v13 - 3] - 3) = v16;
          *((float *)&v15[v13 - 3] - 2) = *((float *)&v15[v13 - 3] - 2) - (float)(v16 * v9);
          v17 = v6->m_intervals.m_data;
          v17[v13 - 3].m_leftX = (float)(v8 * v6->m_intervals.m_data[v13 - 3].m_leftX) + v9;
          *((float *)&v17[v13 - 2] - 4) = (float)(v8 * *((float *)&v17[v13 - 2] - 4)) + v9;
          v18 = v11 * *((float *)&v17[v13 - 2] - 3);
          *((float *)&v17[v13 - 2] - 3) = v18;
          *((float *)&v17[v13 - 2] - 2) = *((float *)&v17[v13 - 2] - 2) - (float)(v18 * v9);
          v19 = v6->m_intervals.m_data;
          v19[v13 - 2].m_leftX = (float)(v8 * v6->m_intervals.m_data[v13 - 2].m_leftX) + v9;
          *((float *)&v19[v13 - 1] - 4) = (float)(v8 * *((float *)&v19[v13 - 1] - 4)) + v9;
          v20 = v11 * *((float *)&v19[v13 - 1] - 3);
          *((float *)&v19[v13 - 1] - 3) = v20;
          *((float *)&v19[v13 - 1] - 2) = *((float *)&v19[v13 - 1] - 2) - (float)(v20 * v9);
          v21 = v6->m_intervals.m_data;
          v21[v13 - 1].m_leftX = (float)(v8 * v6->m_intervals.m_data[v13 - 1].m_leftX) + v9;
          *((float *)&v21[v13] - 4) = (float)(v8 * *((float *)&v21[v13] - 4)) + v9;
          v22 = v11 * *((float *)&v21[v13] - 3);
          *((float *)&v21[v13] - 3) = v22;
          *((float *)&v21[v13] - 2) = *((float *)&v21[v13] - 2) - (float)(v22 * v9);
          --v14;
        }
        while ( v14 );
      }
      if ( v10 < v12 )
      {
        v23 = v10;
        v24 = v12 - v10;
        do
        {
          v25 = v6->m_intervals.m_data;
          ++v23;
          v26 = v11 * *((float *)&v6->m_intervals.m_data[v23] - 3);
          v27 = (float)(v8 * v6->m_intervals.m_data[v23 - 1].m_leftX) + v9;
          *((float *)&v25[v23] - 3) = v26;
          v28 = v8 * *((float *)&v25[v23] - 4);
          v25[v23 - 1].m_leftX = v27;
          *((float *)&v25[v23] - 2) = *((float *)&v25[v23] - 2) - (float)(v26 * v9);
          *((float *)&v25[v23] - 4) = v28 + v9;
          --v24;
        }
        while ( v24 );
      }
    }
  }
}

// File Line: 1363
// RVA: 0x12E2550
void __fastcall hkaiIntervalPartition::remapY(hkaiIntervalPartition *this, float curY1, float curY2, float newY1, float newY2)
{
  signed __int64 v5; // rax
  hkaiIntervalPartition *v6; // r8
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm3_4
  signed __int64 v10; // r10
  signed __int64 v11; // rdx
  __int64 v12; // rcx
  unsigned __int64 v13; // r9
  hkaiIntervalPartition::Interval *v14; // rax
  hkaiIntervalPartition::Interval *v15; // rax
  hkaiIntervalPartition::Interval *v16; // rax
  hkaiIntervalPartition::Interval *v17; // rax
  signed __int64 v18; // rcx
  signed __int64 v19; // rdx
  hkaiIntervalPartition::Interval *v20; // rax
  float v21; // xmm1_4

  v5 = this->m_intervals.m_size;
  v6 = this;
  if ( (_DWORD)v5 )
  {
    v7 = curY2 - curY1;
    v8 = (float)(newY2 - newY1) / v7;
    v9 = newY1 - (float)(v8 * curY1);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(1.0 - v9)) >> 1) >= 0.000099999997
      || COERCE_FLOAT((unsigned int)(2 * LODWORD(v8)) >> 1) >= 0.0001 )
    {
      v10 = 0i64;
      v11 = this->m_intervals.m_size;
      if ( v5 >= 4 )
      {
        v12 = 0i64;
        v13 = ((unsigned __int64)(v5 - 4) >> 2) + 1;
        v10 = 4 * v13;
        do
        {
          v14 = v6->m_intervals.m_data;
          v12 += 4i64;
          *((float *)&v14[v12 - 3] - 3) = v8 * *((float *)&v6->m_intervals.m_data[v12 - 3] - 3);
          *((float *)&v14[v12 - 3] - 2) = (float)(v8 * *((float *)&v14[v12 - 3] - 2)) + v9;
          v15 = v6->m_intervals.m_data;
          *((float *)&v15[v12 - 2] - 3) = v8 * *((float *)&v6->m_intervals.m_data[v12 - 2] - 3);
          *((float *)&v15[v12 - 2] - 2) = (float)(v8 * *((float *)&v15[v12 - 2] - 2)) + v9;
          v16 = v6->m_intervals.m_data;
          *((float *)&v16[v12 - 1] - 3) = v8 * *((float *)&v6->m_intervals.m_data[v12 - 1] - 3);
          *((float *)&v16[v12 - 1] - 2) = (float)(v8 * *((float *)&v16[v12 - 1] - 2)) + v9;
          v17 = v6->m_intervals.m_data;
          *((float *)&v17[v12] - 3) = v8 * *((float *)&v6->m_intervals.m_data[v12] - 3);
          *((float *)&v17[v12] - 2) = (float)(v8 * *((float *)&v17[v12] - 2)) + v9;
          --v13;
        }
        while ( v13 );
      }
      if ( v10 < v11 )
      {
        v18 = v10;
        v19 = v11 - v10;
        do
        {
          v20 = v6->m_intervals.m_data;
          ++v18;
          v21 = (float)(v8 * *((float *)&v6->m_intervals.m_data[v18] - 2)) + v9;
          *((float *)&v20[v18] - 3) = v8 * *((float *)&v6->m_intervals.m_data[v18] - 3);
          *((float *)&v20[v18] - 2) = v21;
          --v19;
        }
        while ( v19 );
      }
    }
  }
}

// File Line: 1388
// RVA: 0x12E26F0
void __fastcall hkaiIntervalPartition::spread(hkaiIntervalPartition *this, float maxSpread)
{
  float v2; // xmm3_4
  hkaiIntervalPartition *v3; // rdx
  signed __int64 v4; // rax
  float v5; // xmm4_4
  signed __int64 v6; // rcx
  signed __int64 v7; // r8
  hkaiIntervalPartition::Interval *v8; // rax
  float v9; // xmm2_4
  float v10; // xmm1_4
  signed __int64 v11; // rcx

  v2 = maxSpread;
  v3 = this;
  if ( this->m_intervals.m_size )
  {
    this->m_intervals.m_data->m_leftX = this->m_intervals.m_data->m_leftX - maxSpread;
    v4 = this->m_intervals.m_size;
    if ( v4 > 1 )
    {
      v5 = maxSpread;
      v6 = 1i64;
      v7 = v4 - 1;
      do
      {
        v8 = v3->m_intervals.m_data;
        ++v6;
        v9 = *((float *)&v3->m_intervals.m_data[v6 - 1] - 4);
        v10 = fminf((float)(v3->m_intervals.m_data[v6 - 1].m_leftX - v9) * 0.5, v5);
        *((float *)&v8[v6 - 1] - 4) = v9 + v10;
        v8[v6 - 1].m_leftX = v8[v6 - 1].m_leftX - v10;
        --v7;
      }
      while ( v7 );
    }
    v11 = v3->m_intervals.m_size - 1;
    v3->m_intervals.m_data[v11].m_rightX = v2 + v3->m_intervals.m_data[v11].m_rightX;
  }
}

// File Line: 1433
// RVA: 0x12E27B0
void __fastcall hkaiIntervalPartition::contract(hkaiIntervalPartition *this, float maxContract)
{
  ContractFilter filter; // [rsp+38h] [rbp+10h]

  filter.m_maxContract = maxContract;
  hkaiIntervalPartition::filterIntervals<`anonymous namespace'::ContractFilter>(this, &filter);
}

// File Line: 1438
// RVA: 0x12E27D0
void __fastcall hkaiIntervalPartition::copyFrom(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  hkaiIntervalPartition *v2; // rbx
  int v3; // ecx
  hkaiIntervalPartition *v4; // rdi
  __int64 v5; // rcx
  char *v6; // rax
  __int64 v7; // rdx
  signed __int64 v8; // r8
  int v9; // ecx
  int v10; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = this->m_intervals.m_capacityAndFlags;
  v4 = other;
  if ( (v3 & 0x3FFFFFFF) < other->m_intervals.m_size )
  {
    if ( v3 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v2->m_intervals.m_data,
        20 * (v3 & 0x3FFFFFFF));
    v10 = 20 * v4->m_intervals.m_size;
    v2->m_intervals.m_data = (hkaiIntervalPartition::Interval *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                                  &v10);
    v2->m_intervals.m_capacityAndFlags = v10 / 20;
  }
  v5 = v4->m_intervals.m_size;
  v6 = (char *)v2->m_intervals.m_data;
  v2->m_intervals.m_size = v5;
  v7 = v5;
  if ( (signed int)v5 > 0 )
  {
    v8 = (char *)v4->m_intervals.m_data - v6;
    do
    {
      v9 = *(_DWORD *)&v6[v8];
      v6 += 20;
      *((_DWORD *)v6 - 5) = v9;
      *((_DWORD *)v6 - 4) = *(_DWORD *)&v6[v8 - 16];
      *((_DWORD *)v6 - 3) = *(_DWORD *)&v6[v8 - 12];
      *((_DWORD *)v6 - 2) = *(_DWORD *)&v6[v8 - 8];
      *((_DWORD *)v6 - 1) = *(_DWORD *)&v6[v8 - 4];
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 1443
// RVA: 0x12E0F10
void __fastcall hkaiIntervalPartition::appendPartition(hkaiIntervalPartition *this, hkaiIntervalPartition *other)
{
  int v2; // er9
  hkaiIntervalPartition *v3; // rdi
  hkaiIntervalPartition *v4; // rbx
  int v5; // ecx
  __int64 v6; // rcx
  char *v7; // rax
  __int64 v8; // rdx
  signed __int64 v9; // r8
  int v10; // ecx
  int v11; // [rsp+38h] [rbp+10h]

  v2 = other->m_intervals.m_size;
  v3 = other;
  v4 = this;
  if ( v2 )
  {
    if ( this->m_intervals.m_size )
    {
      hkArrayBase<hkaiIntervalPartition::Interval>::_append(
        (hkArrayBase<hkaiIntervalPartition::Interval> *)&this->m_intervals.m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        other->m_intervals.m_data,
        v2);
    }
    else
    {
      v5 = this->m_intervals.m_capacityAndFlags;
      if ( (v5 & 0x3FFFFFFF) < v2 )
      {
        if ( v5 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v4->m_intervals.m_data,
            20 * (v5 & 0x3FFFFFFF));
        v11 = 20 * v3->m_intervals.m_size;
        v4->m_intervals.m_data = (hkaiIntervalPartition::Interval *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                                      &v11);
        v4->m_intervals.m_capacityAndFlags = v11 / 20;
      }
      v6 = v3->m_intervals.m_size;
      v7 = (char *)v4->m_intervals.m_data;
      v4->m_intervals.m_size = v6;
      v8 = v6;
      if ( (signed int)v6 > 0 )
      {
        v9 = (char *)v3->m_intervals.m_data - v7;
        do
        {
          v10 = *(_DWORD *)&v7[v9];
          v7 += 20;
          *((_DWORD *)v7 - 5) = v10;
          *((_DWORD *)v7 - 4) = *(_DWORD *)&v7[v9 - 16];
          *((_DWORD *)v7 - 3) = *(_DWORD *)&v7[v9 - 12];
          *((_DWORD *)v7 - 2) = *(_DWORD *)&v7[v9 - 8];
          *((_DWORD *)v7 - 1) = *(_DWORD *)&v7[v9 - 4];
          --v8;
        }
        while ( v8 );
      }
    }
  }
}

// File Line: 1460
// RVA: 0x12E28C0
void __fastcall hkaiIntervalPartition::copyRegionFrom(hkaiIntervalPartition *this, hkaiIntervalPartition *other, float minX, float maxX)
{
  int v4; // ebx
  __int64 v5; // rbp
  hkaiIntervalPartition *v6; // rsi
  hkaiIntervalPartition *v7; // rdi
  hkaiIntervalPartition::Interval *v8; // rax
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm10_4
  unsigned int v12; // xmm11_4
  float v13; // xmm6_4
  signed __int64 v14; // rcx
  hkaiIntervalPartition::Interval *v15; // rax
  int v16; // er14
  bool v17; // zf
  bool v18; // sf
  unsigned __int8 v19; // of
  float v20; // xmm8_4
  float v21; // xmm9_4
  float v22; // xmm10_4
  unsigned int v23; // xmm11_4
  float v24; // xmm6_4
  signed __int64 v25; // rcx
  hkaiIntervalPartition::Interval *v26; // rax

  v4 = 0;
  this->m_intervals.m_size = 0;
  v5 = other->m_intervals.m_size;
  v6 = other;
  v7 = this;
  if ( (_DWORD)v5 )
  {
    if ( minX > other->m_intervals.m_data->m_leftX || maxX < *((float *)&other->m_intervals.m_data[v5] - 4) )
    {
      if ( (signed int)v5 > 0 )
      {
        while ( 1 )
        {
          v8 = hkaiIntervalPartition::getInterval(v6, v4);
          if ( minX < v8->m_rightX )
            break;
          if ( ++v4 >= (signed int)v5 )
            goto LABEL_12;
        }
        v9 = v8->m_rightX;
        v10 = v8->m_slope;
        v11 = v8->m_offset;
        v12 = v8->m_data;
        v13 = fmaxf(v8->m_leftX, minX);
        if ( !(v7->m_intervals.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 20);
        v14 = v7->m_intervals.m_size;
        v15 = v7->m_intervals.m_data;
        v15[v14].m_leftX = v13;
        v15[v14].m_rightX = v9;
        v15[v14].m_slope = v10;
        v15[v14].m_offset = v11;
        v15[v14].m_data = v12;
        ++v7->m_intervals.m_size;
        ++v4;
      }
LABEL_12:
      v16 = hkaiIntervalPartition::findRightInterval(v6, maxX);
      if ( (signed int)v5 - 1 < v16 )
        v16 = v5 - 1;
      v19 = __OFSUB__(v4, v16);
      v17 = v4 == v16;
      v18 = v4 - v16 < 0;
      if ( v4 < v16 )
      {
        hkArrayBase<hkaiIntervalPartition::Interval>::_append(
          (hkArrayBase<hkaiIntervalPartition::Interval> *)&v7->m_intervals.m_data,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v6->m_intervals.m_data[v4],
          v16 - v4);
        v19 = __OFSUB__(v4, v16);
        v17 = v4 == v16;
        v18 = v4 - v16 < 0;
      }
      if ( (unsigned __int8)(v18 ^ v19) | v17 )
      {
        v20 = v6->m_intervals.m_data[v16].m_leftX;
        v21 = v6->m_intervals.m_data[v16].m_slope;
        v22 = v6->m_intervals.m_data[v16].m_offset;
        v23 = v6->m_intervals.m_data[v16].m_data;
        if ( v20 < maxX )
        {
          v24 = fminf(v6->m_intervals.m_data[v16].m_rightX, maxX);
          if ( v7->m_intervals.m_size == (v7->m_intervals.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 20);
          v25 = v7->m_intervals.m_size;
          v26 = v7->m_intervals.m_data;
          v26[v25].m_leftX = v20;
          v26[v25].m_rightX = v24;
          v26[v25].m_slope = v21;
          v26[v25].m_offset = v22;
          v26[v25].m_data = v23;
          ++v7->m_intervals.m_size;
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
  int v1; // eax
  hkaiIntervalPartition *v2; // r10
  int v3; // er11
  signed int v4; // er9
  __int64 v5; // rbx
  signed __int64 v6; // r8
  signed __int64 v7; // rdx
  hkaiIntervalPartition::Interval *v8; // rcx

  v1 = this->m_intervals.m_size;
  v2 = this;
  if ( v1 >= 2 )
  {
    v3 = 0;
    v4 = 1;
    v5 = 0i64;
    if ( v1 > 1 )
    {
      v6 = 0i64;
      v7 = 1i64;
      do
      {
        v8 = v2->m_intervals.m_data;
        if ( v2->m_intervals.m_data[v7].m_leftX == v2->m_intervals.m_data[v6].m_rightX )
        {
          v8[v6].m_rightX = v8[v7].m_rightX;
        }
        else
        {
          ++v3;
          v6 = ++v5;
          v8[v6].m_leftX = v8[v7].m_leftX;
          v8[v6].m_rightX = v8[v7].m_rightX;
          v8[v6].m_slope = v8[v7].m_slope;
          v8[v6].m_offset = v8[v7].m_offset;
          v8[v6].m_data = v8[v7].m_data;
        }
        ++v4;
        ++v7;
      }
      while ( v4 < v2->m_intervals.m_size );
    }
    v2->m_intervals.m_size = v3 + 1;
  }
}

// File Line: 1531
// RVA: 0x12E2BE0
void __fastcall hkaiIntervalPartition::setAllData(hkaiIntervalPartition *this, unsigned int data)
{
  __int64 v2; // r9
  __int64 v3; // rax

  v2 = this->m_intervals.m_size;
  if ( v2 > 0 )
  {
    v3 = 0i64;
    do
    {
      ++v3;
      *((_DWORD *)&this->m_intervals.m_data[v3] - 1) = data;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 1539
// RVA: 0x12E2000
void __fastcall hkaiIntervalPartition::reflectX(hkaiIntervalPartition *this, float mid)
{
  signed __int64 v2; // rax
  signed __int64 v3; // r15
  float v4; // xmm3_4
  signed __int64 v5; // rsi
  hkaiIntervalPartition *v6; // r14
  __int64 v7; // rbp
  signed __int64 v8; // rbx
  __int64 v9; // rdi
  hkaiIntervalPartition::Interval *v10; // r11
  float v11; // ecx
  float v12; // edx
  float v13; // er8
  float v14; // er9
  unsigned int v15; // er10
  __int64 v16; // rcx
  unsigned __int64 v17; // rdx
  float v18; // xmm2_4
  hkaiIntervalPartition::Interval *v19; // rax
  float v20; // xmm1_4
  float v21; // xmm0_4
  hkaiIntervalPartition::Interval *v22; // rax
  float v23; // xmm1_4
  float v24; // xmm0_4
  hkaiIntervalPartition::Interval *v25; // rax
  float v26; // xmm1_4
  float v27; // xmm0_4
  hkaiIntervalPartition::Interval *v28; // rax
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm3_4
  signed __int64 v32; // rcx
  signed __int64 v33; // rsi
  hkaiIntervalPartition::Interval *v34; // rax
  float v35; // xmm2_4
  float v36; // xmm1_4

  v2 = this->m_intervals.m_size;
  v3 = 0i64;
  v4 = mid;
  v5 = v2;
  v6 = this;
  LODWORD(v2) = (signed int)v2 / 2;
  v7 = (signed int)v2;
  if ( (signed int)v2 > 0 )
  {
    v8 = v5;
    v9 = 0i64;
    do
    {
      v10 = v6->m_intervals.m_data;
      --v8;
      ++v9;
      v11 = v6->m_intervals.m_data[v9 - 1].m_leftX;
      v12 = *((float *)&v6->m_intervals.m_data[v9] - 4);
      v13 = *((float *)&v6->m_intervals.m_data[v9] - 3);
      v14 = *((float *)&v6->m_intervals.m_data[v9] - 2);
      v15 = *((_DWORD *)&v6->m_intervals.m_data[v9] - 1);
      v10[v9 - 1].m_leftX = v6->m_intervals.m_data[v8].m_leftX;
      *((_DWORD *)&v10[v9] - 4) = LODWORD(v10[v8].m_rightX);
      *((_DWORD *)&v10[v9] - 3) = LODWORD(v10[v8].m_slope);
      *((_DWORD *)&v10[v9] - 2) = LODWORD(v10[v8].m_offset);
      *((_DWORD *)&v10[v9] - 1) = v10[v8].m_data;
      v10[v8].m_leftX = v11;
      v10[v8].m_rightX = v12;
      v10[v8].m_slope = v13;
      v10[v8].m_offset = v14;
      v10[v8].m_data = v15;
      --v7;
    }
    while ( v7 );
  }
  if ( v5 >= 4 )
  {
    v16 = 0i64;
    v17 = ((unsigned __int64)(v5 - 4) >> 2) + 1;
    v18 = mid * 2.0;
    v3 = 4 * v17;
    do
    {
      v19 = v6->m_intervals.m_data;
      v16 += 4i64;
      v19[v16 - 4].m_leftX = v18 - v6->m_intervals.m_data[v16 - 4].m_leftX;
      v20 = v18 - *((float *)&v19[v16 - 3] - 4);
      *((float *)&v19[v16 - 3] - 4) = v20;
      v21 = v19[v16 - 4].m_leftX;
      v19[v16 - 4].m_leftX = v20;
      *((float *)&v19[v16 - 3] - 4) = v21;
      *((float *)&v19[v16 - 3] - 2) = (float)(v18 * *((float *)&v19[v16 - 3] - 3)) + *((float *)&v19[v16 - 3] - 2);
      *((_DWORD *)&v19[v16 - 3] - 3) ^= _xmm[0];
      v22 = v6->m_intervals.m_data;
      v22[v16 - 3].m_leftX = v18 - v6->m_intervals.m_data[v16 - 3].m_leftX;
      v23 = v18 - *((float *)&v22[v16 - 2] - 4);
      *((float *)&v22[v16 - 2] - 4) = v23;
      v24 = v22[v16 - 3].m_leftX;
      v22[v16 - 3].m_leftX = v23;
      *((float *)&v22[v16 - 2] - 4) = v24;
      *((float *)&v22[v16 - 2] - 2) = (float)(v18 * *((float *)&v22[v16 - 2] - 3)) + *((float *)&v22[v16 - 2] - 2);
      *((_DWORD *)&v22[v16 - 2] - 3) ^= _xmm[0];
      v25 = v6->m_intervals.m_data;
      v25[v16 - 2].m_leftX = v18 - v6->m_intervals.m_data[v16 - 2].m_leftX;
      v26 = v18 - *((float *)&v25[v16 - 1] - 4);
      *((float *)&v25[v16 - 1] - 4) = v26;
      v27 = v25[v16 - 2].m_leftX;
      v25[v16 - 2].m_leftX = v26;
      *((float *)&v25[v16 - 1] - 4) = v27;
      *((float *)&v25[v16 - 1] - 2) = (float)(v18 * *((float *)&v25[v16 - 1] - 3)) + *((float *)&v25[v16 - 1] - 2);
      *((_DWORD *)&v25[v16 - 1] - 3) ^= _xmm[0];
      v28 = v6->m_intervals.m_data;
      v28[v16 - 1].m_leftX = v18 - v6->m_intervals.m_data[v16 - 1].m_leftX;
      v29 = v18 - *((float *)&v28[v16] - 4);
      *((float *)&v28[v16] - 4) = v29;
      v30 = v28[v16 - 1].m_leftX;
      v28[v16 - 1].m_leftX = v29;
      *((float *)&v28[v16] - 4) = v30;
      *((float *)&v28[v16] - 2) = (float)(v18 * *((float *)&v28[v16] - 3)) + *((float *)&v28[v16] - 2);
      *((_DWORD *)&v28[v16] - 3) ^= _xmm[0];
      --v17;
    }
    while ( v17 );
  }
  if ( v3 < v5 )
  {
    v31 = v4 * 2.0;
    v32 = v3;
    v33 = v5 - v3;
    do
    {
      v34 = v6->m_intervals.m_data;
      ++v32;
      v35 = *((float *)&v6->m_intervals.m_data[v32] - 3);
      v36 = v31 - v6->m_intervals.m_data[v32 - 1].m_leftX;
      v34[v32 - 1].m_leftX = v31 - *((float *)&v6->m_intervals.m_data[v32] - 4);
      *((float *)&v34[v32] - 4) = v36;
      *((_DWORD *)&v34[v32] - 3) = LODWORD(v35) ^ _xmm[0];
      *((float *)&v34[v32] - 2) = (float)(v35 * v31) + *((float *)&v34[v32] - 2);
      --v33;
    }
    while ( v33 );
  }
}

