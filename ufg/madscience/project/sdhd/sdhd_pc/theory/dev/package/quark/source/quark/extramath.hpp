// File Line: 89
// RVA: 0x3CC070
void __fastcall UFG::HomerCubic<UFG::qVector3>::SetDuration(UFG::HomerCubic<UFG::qVector3> *this, UFG::qVector3 *duration)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4

  v2 = this->mParameter.y / this->mDuration.y;
  v3 = this->mParameter.z / this->mDuration.z;
  this->mParameter.x = this->mParameter.x / this->mDuration.x;
  this->mParameter.y = v2;
  this->mParameter.z = v3;
  v4 = duration->z;
  if ( v4 <= 0.0099999998 )
    v4 = FLOAT_0_0099999998;
  v5 = duration->y;
  if ( v5 <= 0.0099999998 )
    v5 = FLOAT_0_0099999998;
  v6 = duration->x;
  if ( duration->x <= 0.0099999998 )
    v6 = FLOAT_0_0099999998;
  this->mDuration.x = v6;
  this->mDuration.y = v5;
  this->mDuration.z = v4;
  v7 = v5 * this->mParameter.y;
  v8 = v4 * this->mParameter.z;
  this->mParameter.x = v6 * this->mParameter.x;
  this->mParameter.y = v7;
  this->mParameter.z = v8;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(this);
}

// File Line: 102
// RVA: 0x3CBF90
void __fastcall UFG::HomerCubic<UFG::qVector3>::SetDesiredPosition(UFG::HomerCubic<UFG::qVector3> *this, UFG::qVector3 *position)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  UFG::HomerCubic<UFG::qVector3> *v4; // rbx

  v2 = position->y;
  v3 = position->z;
  this->p1.x = position->x;
  v4 = this;
  this->p1.y = v2;
  this->p1.z = v3;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(this);
  *(_QWORD *)&v4->mParameter.x = 0i64;
  v4->mParameter.z = 0.0;
}

// File Line: 119
// RVA: 0x3CF7F0
void __fastcall UFG::HomerCubic<float>::Update(UFG::HomerCubic<float> *this, const float f_elapsed_seconds)
{
  float v2; // xmm5_4
  float v3; // xmm4_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4

  v2 = f_elapsed_seconds + this->mParameter;
  if ( v2 <= 0.0 )
    v2 = 0.0;
  if ( v2 >= this->mDuration )
    v2 = this->mDuration;
  v3 = this->A;
  v4 = this->B;
  this->mParameter = v2;
  v5 = (float)((float)((float)((float)(v3 * 3.0) * v2) + (float)(v4 * 2.0)) * v2) + this->C;
  v6 = (float)((float)((float)((float)((float)(v3 * v2) + v4) * v2) + this->C) * v2) + this->D;
  this->v0 = v5;
  this->p0 = v6;
}

// File Line: 156
// RVA: 0xB9CC0
void __fastcall UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(UFG::HomerCubic<UFG::qVector3> *this)
{
  float v1; // xmm15_4
  float v2; // xmm14_4
  float v3; // xmm13_4
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm1_4
  float v7; // xmm6_4
  float v8; // xmm2_4
  float v9; // eax
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4

  v1 = this->mDuration.z;
  if ( v1 <= 0.0099999998 )
    v1 = FLOAT_0_0099999998;
  v2 = this->mDuration.y;
  if ( v2 <= 0.0099999998 )
    v2 = FLOAT_0_0099999998;
  v3 = this->mDuration.x;
  if ( this->mDuration.x <= 0.0099999998 )
    v3 = FLOAT_0_0099999998;
  v4 = (float)((float)((float)(this->v1.y + this->v0.y) * v2) + (float)((float)(this->p0.y - this->p1.y) * 2.0))
     / (float)((float)(v2 * v2) * v2);
  v5 = (float)((float)((float)(this->v0.z + this->v1.z) * v1) + (float)((float)(this->p0.z - this->p1.z) * 2.0))
     / (float)((float)(v1 * v1) * v1);
  this->A.x = (float)((float)((float)(this->v1.x + this->v0.x) * v3) + (float)((float)(this->p0.x - this->p1.x) * 2.0))
            / (float)((float)(v3 * v3) * v3);
  this->A.y = v4;
  this->A.z = v5;
  v6 = (float)(this->p1.z - this->p0.z) * 3.0;
  v7 = (float)(this->v0.z * 2.0) + this->v1.z;
  v8 = (float)((float)((float)(this->p1.y - this->p0.y) * 3.0)
             - (float)((float)((float)(this->v0.y * 2.0) + this->v1.y) * v2))
     / (float)(v2 * v2);
  this->B.x = (float)((float)((float)(this->p1.x - this->p0.x) * 3.0)
                    - (float)((float)((float)(this->v0.x * 2.0) + this->v1.x) * v3))
            / (float)(v3 * v3);
  this->B.y = v8;
  this->B.z = (float)(v6 - (float)(v7 * v1)) / (float)(v1 * v1);
  v9 = this->v0.x;
  v10 = this->v0.z;
  this->C.y = this->v0.y;
  this->C.x = v9;
  this->C.z = v10;
  v11 = this->p0.y;
  v12 = this->p0.z;
  this->D.x = this->p0.x;
  this->D.y = v11;
  this->D.z = v12;
}

// File Line: 181
// RVA: 0x3C5940
void __fastcall UFG::HomerCubicAngular::Init(UFG::HomerCubicAngular *this, const float _p0, const float _p1, const float _v0, const float _v1, const float duration, const float modulo)
{
  UFG::HomerCubicAngular *v7; // rbx
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm0_4

  v7 = this;
  this->mModulo = modulo;
  if ( modulo <= 1.1754944e-38 )
    v8 = FLOAT_3_4028235e38;
  else
    v8 = 1.0 / modulo;
  v9 = duration;
  this->mModuloRecip = v8;
  v10 = UFG::HomerCubicAngular::NewDesiredPosition(this, _p0, _p1, _v0, _v1, duration);
  if ( duration <= 0.0099999998 )
    v9 = FLOAT_0_0099999998;
  v7->mHomerCubic.mDuration = v9;
  v7->mHomerCubic.v0 = _v0;
  v7->mHomerCubic.mParameter = 0.0;
  v7->mHomerCubic.v1 = _v1;
  v7->mHomerCubic.p0 = _p0;
  v7->mHomerCubic.p1 = v10;
  UFG::HomerCubic<float>::MakeCoeffs(&v7->mHomerCubic);
}

// File Line: 194
// RVA: 0x3CD280
void __fastcall UFG::HomerCubicAngular::SetPosition(UFG::HomerCubicAngular *this, const float position)
{
  __int128 v2; // xmm0
  UFG::HomerCubicAngular *v3; // rbx
  float _v1; // ST20_4

  v2 = LODWORD(this->mHomerCubic.mDuration);
  v3 = this;
  _v1 = this->mHomerCubic.v1;
  this->mHomerCubic.p1 = UFG::HomerCubicAngular::NewDesiredPosition(
                           this,
                           position,
                           this->mHomerCubic.p1,
                           this->mHomerCubic.v0);
  UFG::HomerCubic<float>::MakeCoeffs(&v3->mHomerCubic);
  v3->mHomerCubic.mParameter = 0.0;
  v3->mHomerCubic.p0 = position;
  UFG::HomerCubic<float>::MakeCoeffs(&v3->mHomerCubic);
  v3->mHomerCubic.mParameter = 0.0;
}

// File Line: 208
// RVA: 0x3CBFD0
void __fastcall UFG::HomerCubicAngular::SetDesiredPosition(UFG::HomerCubicAngular *this, const float position)
{
  __int128 v2; // xmm0
  UFG::HomerCubicAngular *v3; // rbx
  float _v1; // ST20_4

  v2 = LODWORD(this->mHomerCubic.mDuration);
  v3 = this;
  _v1 = this->mHomerCubic.v1;
  this->mHomerCubic.p1 = UFG::HomerCubicAngular::NewDesiredPosition(
                           this,
                           this->mHomerCubic.p0,
                           position,
                           this->mHomerCubic.v0);
  UFG::HomerCubic<float>::MakeCoeffs(&v3->mHomerCubic);
  v3->mHomerCubic.mParameter = 0.0;
}

// File Line: 240
// RVA: 0x3D63B0
void __fastcall UFG::HomerCubicAngular::Update(UFG::HomerCubicAngular *this, const float f_elapsed_seconds)
{
  UFG::HomerCubicAngular *v2; // rbx
  float v3; // xmm8_4
  float v4; // xmm0_4
  __m128 v5; // xmm2
  float v6; // xmm7_4
  __m128 v7; // xmm6
  signed int v8; // ecx
  signed int v9; // ecx
  __int128 v10; // xmm0
  float _v1; // ST20_4

  v2 = this;
  UFG::HomerCubic<float>::Update(&this->mHomerCubic, f_elapsed_seconds);
  v3 = UFG::qSignedMod(v2->mHomerCubic.p0, v2->mModulo);
  v4 = UFG::qSignedMod(v2->mHomerCubic.p1, v2->mModulo);
  v5 = (__m128)LODWORD(v2->mModuloRecip);
  v7 = (__m128)LODWORD(v2->mModuloRecip);
  v6 = v4;
  v7.m128_f32[0] = v7.m128_f32[0] * v3;
  v8 = (signed int)v7.m128_f32[0];
  if ( (signed int)v7.m128_f32[0] != 0x80000000 && (float)v8 != v7.m128_f32[0] )
    v7.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1));
  v5.m128_f32[0] = v5.m128_f32[0] * v4;
  v9 = (signed int)v5.m128_f32[0];
  if ( (signed int)v5.m128_f32[0] != 0x80000000 && (float)v9 != v5.m128_f32[0] )
    v5.m128_f32[0] = (float)(v9 - (_mm_movemask_ps(_mm_unpacklo_ps(v5, v5)) & 1));
  if ( v7.m128_f32[0] == v5.m128_f32[0] )
  {
    UFG::HomerCubicAngular::SetPosition(v2, v3 - (float)(v7.m128_f32[0] * v2->mModulo));
    v10 = LODWORD(v2->mHomerCubic.mDuration);
    _v1 = v2->mHomerCubic.v1;
    v2->mHomerCubic.p1 = UFG::HomerCubicAngular::NewDesiredPosition(
                           v2,
                           v2->mHomerCubic.p0,
                           v6 - (float)(v7.m128_f32[0] * v2->mModulo),
                           v2->mHomerCubic.v0);
    UFG::HomerCubic<float>::MakeCoeffs(&v2->mHomerCubic);
    v2->mHomerCubic.mParameter = 0.0;
  }
}

// File Line: 286
// RVA: 0x3C7590
float __fastcall UFG::HomerCubicAngular::NewDesiredPosition(UFG::HomerCubicAngular *this, const float _p0, const float _p1, const float _v0)
{
  __m128 v4; // xmm3
  float v5; // xmm5_4
  float v6; // xmm1_4
  __m128 v7; // xmm4
  signed int v8; // ecx
  float v9; // xmm4_4
  signed int v10; // ecx
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float result; // xmm0_4

  v4 = (__m128)LODWORD(this->mModuloRecip);
  v5 = _p0;
  v6 = this->mModulo;
  v7 = (__m128)LODWORD(this->mModuloRecip);
  v7.m128_f32[0] = v7.m128_f32[0] * v5;
  v8 = (signed int)v7.m128_f32[0];
  if ( (signed int)v7.m128_f32[0] != 0x80000000 && (float)v8 != v7.m128_f32[0] )
    v7.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1));
  v4.m128_f32[0] = v4.m128_f32[0] * _p1;
  v9 = v7.m128_f32[0] * v6;
  v10 = (signed int)v4.m128_f32[0];
  if ( (signed int)v4.m128_f32[0] != 0x80000000 && (float)v10 != v4.m128_f32[0] )
    v4.m128_f32[0] = (float)(v10 - (_mm_movemask_ps(_mm_unpacklo_ps(v4, v4)) & 1));
  v11 = _p1 - (float)(v4.m128_f32[0] * v6);
  if ( (float)(v5 - v9) >= v11 )
    v12 = 0.0;
  else
    LODWORD(v12) = LODWORD(v6) ^ _xmm[0];
  v13 = (float)(v11 + v9) + v12;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v5 - v13) & _xmm) >= COERCE_FLOAT(COERCE_UNSIGNED_INT(v5 - (float)(v13 + v6)) & _xmm) )
    result = v13 + v6;
  else
    result = v13;
  return result;
}

// File Line: 323
// RVA: 0x532D20
int UFG::LinearTable<float>::GetValue(...)
{
  float v2; // xmm0_4
  __m128 v3; // xmm2
  UFG::LinearTable<float> *v4; // r9
  float v5; // xmm1_4
  signed int v6; // ecx
  int v7; // er8
  float v8; // xmm2_4

  v2 = this->fMin;
  v3 = (__m128)x;
  v4 = this;
  if ( *(float *)&x <= v2 )
    v3 = (__m128)LODWORD(this->fMin);
  if ( v3.m128_f32[0] >= this->fMax )
    v3 = (__m128)LODWORD(this->fMax);
  v3.m128_f32[0] = (float)(v3.m128_f32[0] - v2) * this->fCoef;
  v5 = v3.m128_f32[0];
  v6 = (signed int)v3.m128_f32[0];
  if ( (signed int)v3.m128_f32[0] != 0x80000000 && (float)v6 != v3.m128_f32[0] )
    v5 = (float)(v6 - (_mm_movemask_ps(_mm_unpacklo_ps(v3, v3)) & 1));
  v7 = v4->nData - 1;
  v8 = v3.m128_f32[0] - v5;
  if ( (signed int)v5 + 1 < v7 )
    v7 = (signed int)v5 + 1;
  return (float)((float)((float)v4->pData[v7] - (float)v4->pData[v5]) * v8) + (float)v4->pData[v5];
}

// File Line: 380
// RVA: 0x47400
float __fastcall UFG::LinearGraph<float>::GetValue(UFG::LinearGraph<float> *this, const float x)
{
  const float *v2; // rdi
  UFG::LinearGraph<UFG::qVector3> *v3; // rbx
  __int64 v5; // rcx
  __int64 v6; // rcx
  float v7; // xmm6_4

  v2 = this->fDomain;
  v3 = (UFG::LinearGraph<UFG::qVector3> *)this;
  if ( x <= *v2 )
    return *this->tRange;
  v5 = this->nData;
  if ( x >= v2[v5 - 1] )
    return *((float *)v3->tRange + v5 - 1);
  v6 = (signed int)UFG::LinearGraph<float>::FindDomainBracket(v3, x);
  v7 = (float)(x - v2[v6 - 1]) / (float)(v2[v6] - v2[v6 - 1]);
  return (float)((float)(1.0 - v7) * *((float *)v3->tRange + v6 - 1)) + (float)(v7 * *(&v3->tRange->x + v6));
}

// File Line: 492
// RVA: 0x47390
__int64 __fastcall UFG::LinearGraph<float>::FindDomainBracket(UFG::LinearGraph<UFG::qVector3> *this, const float x)
{
  int v2; // edx
  const float *v3; // r9
  unsigned int v4; // ecx
  int v5; // er8
  signed __int64 v6; // rax
  __int64 result; // rax
  int v8; // er8

  v2 = this->nData;
  v3 = this->fDomain;
  if ( this->nData >= 6 )
  {
    v8 = 0;
    if ( v2 > 1 )
    {
      do
      {
        if ( x >= v3[(v2 + v8) >> 1] )
          v8 = (v2 + v8) >> 1;
        else
          v2 = (v2 + v8) >> 1;
      }
      while ( v2 - v8 > 1 );
    }
    result = (unsigned int)(v8 + 1);
  }
  else
  {
    v4 = 1;
    v5 = v2 - 1;
    v6 = 1i64;
    if ( v2 - 1 <= 1i64 )
    {
LABEL_5:
      result = (unsigned int)v5;
    }
    else
    {
      while ( x >= v3[v6] )
      {
        ++v6;
        ++v4;
        if ( v6 >= v5 )
          goto LABEL_5;
      }
      result = v4;
    }
  }
  return result;
}

// File Line: 651
// RVA: 0x6423B0
void __fastcall UFG::RingBuffer<UFG::Crumb>::RingBuffer<UFG::Crumb>(UFG::RingBuffer<UFG::Crumb> *this, int capacity)
{
  UFG::RingBuffer<UFG::Crumb> *v2; // rbx
  signed __int64 v3; // rdi
  int v4; // esi
  signed __int64 v5; // rax
  unsigned __int8 v6; // cf
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax

  v2 = this;
  this->mLast = -1;
  v3 = 0i64;
  this->mCount = 0;
  this->mCapacity = capacity;
  v4 = capacity;
  v5 = 32i64 * capacity;
  if ( !is_mul_ok(capacity, 0x20ui64) )
    v5 = -1i64;
  v6 = __CFADD__(v5, 4i64);
  v7 = v5 + 4;
  if ( v6 )
    v7 = -1i64;
  v8 = UFG::qMalloc(v7, "RingBuffer", 0i64);
  if ( v8 )
  {
    LODWORD(v8->mNext) = v4;
    v3 = (signed __int64)&v8->mNext + 4;
    `eh vector constructor iterator'(
      (char *)&v8->mNext + 4,
      0x20ui64,
      v4,
      (void (__fastcall *)(void *))Assembly::GetRCX);
  }
  v2->mData = (UFG::Crumb *)v3;
}

// File Line: 656
// RVA: 0x6438D0
void __fastcall UFG::RingBuffer<UFG::HistoryItem<UFG::qVector2>>::~RingBuffer<UFG::HistoryItem<UFG::qVector2>>(UFG::RingBuffer<UFG::HistoryItem<UFG::qVector2> > *this)
{
  operator delete[](this->mData);
}

// File Line: 707
// RVA: 0x6565E0
UFG::Crumb *__fastcall UFG::RingBuffer<UFG::Crumb>::NthNewest(UFG::RingBuffer<UFG::Crumb> *this, int n)
{
  int v2; // eax
  int v3; // er8
  UFG::RingBuffer<UFG::Crumb> *v4; // rbx
  int v5; // ecx

  v2 = this->mCount;
  v3 = 0;
  if ( n > 0 )
    v3 = n;
  v4 = this;
  v5 = this->mLast;
  if ( v3 < v2 )
    v2 = v3;
  return &v4->mData[(signed int)UFG::qSignedMod(v5 - v2, v4->mCapacity)];
}

// File Line: 802
// RVA: 0x651040
UFG::qVector2 *__fastcall UFG::HistoryBuffer<UFG::qVector2>::GetValue(UFG::HistoryBuffer<UFG::qVector2> *this, UFG::qVector2 *result, float age)
{
  int v3; // ebp
  UFG::qVector2 *v4; // rsi
  float v5; // xmm7_4
  UFG::HistoryBuffer<UFG::qVector2> *v6; // rbx
  UFG::qVector2 *v7; // rax
  __int64 v8; // rax
  UFG::HistoryItem<UFG::qVector2> *v9; // rcx
  int v10; // er14
  int v11; // edi
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  UFG::HistoryItem<UFG::qVector2> *v15; // r12
  signed __int64 v16; // r15
  float v17; // xmm6_4
  int v18; // ecx
  UFG::HistoryItem<UFG::qVector2> *v19; // rcx
  float v20; // eax
  int v21; // eax
  int v22; // eax
  UFG::HistoryItem<UFG::qVector2> *v23; // rcx
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm7_4
  float v27; // xmm0_4

  v3 = this->mRingBuffer.mCount;
  v4 = result;
  v5 = age;
  v6 = this;
  if ( !v3 )
  {
    v7 = result;
    *result = 0i64;
    return v7;
  }
  if ( v3 == 1 )
  {
    v8 = this->mRingBuffer.mLast;
    v9 = this->mRingBuffer.mData;
    result->x = v9[v8].mValue.x;
    result->y = v9[v8].mValue.y;
  }
  else
  {
    v10 = 0;
    v11 = 0;
    if ( v3 <= 0 )
    {
LABEL_12:
      v18 = v6->mRingBuffer.mCapacity;
      if ( v6->mRingBuffer.mCount >= v18 )
        v19 = &v6->mRingBuffer.mData[(v6->mRingBuffer.mLast + 1) % v18];
      else
        v19 = v6->mRingBuffer.mData;
      v4->x = v19->mValue.x;
      v20 = v19->mValue.y;
    }
    else
    {
      while ( 1 )
      {
        v12 = v6->mRingBuffer.mCount;
        v13 = 0;
        if ( v11 > 0 )
          v13 = v11;
        if ( v13 < v12 )
          v12 = v13;
        v14 = UFG::qSignedMod(v6->mRingBuffer.mLast - v12, v6->mRingBuffer.mCapacity);
        v15 = v6->mRingBuffer.mData;
        v16 = v14;
        v17 = (float)((float)(v6->nTimeStamp - v15[v14].nTimeStamp) * 2.3283064e-10) * v6->fDuration;
        if ( age <= v17 )
          break;
        if ( ++v11 >= v3 )
          goto LABEL_12;
      }
      if ( v11 )
      {
        if ( v11 - 1 > 0 )
          v10 = v11 - 1;
        v21 = v6->mRingBuffer.mCount;
        if ( v10 < v21 )
          v21 = v10;
        v22 = UFG::qSignedMod(v6->mRingBuffer.mLast - v21, v6->mRingBuffer.mCapacity);
        v23 = v6->mRingBuffer.mData;
        v24 = v23[v22].mValue.y;
        v25 = (float)((float)(v6->nTimeStamp - v23[v22].nTimeStamp) * 2.3283064e-10) * v6->fDuration;
        v26 = (float)(v5 - v25) / (float)(v17 - v25);
        v27 = (float)(v15[v16].mValue.y - v24) * v26;
        v4->x = v23[v22].mValue.x + (float)((float)(v15[v16].mValue.x - v23[v22].mValue.x) * v26);
        v4->y = v24 + v27;
        return v4;
      }
      v4->x = v15[v14].mValue.x;
      v20 = v15[v14].mValue.y;
    }
    v4->y = v20;
  }
  return v4;
}

// File Line: 826
// RVA: 0x657CC0
void __fastcall UFG::HistoryBuffer<UFG::qVector2>::Record(UFG::HistoryBuffer<UFG::qVector2> *this, UFG::qVector2 *value)
{
  UFG::qVector2 *v2; // rdi
  UFG::HistoryBuffer<UFG::qVector2> *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4
  unsigned int v6; // er9
  int v7; // edx
  int v8; // eax
  signed __int64 v9; // rcx
  UFG::HistoryItem<UFG::qVector2> *v10; // rax
  unsigned int v11; // er8
  __int64 v12; // rax
  UFG::HistoryItem<UFG::qVector2> *v13; // rdx
  unsigned int v14; // er8
  float v15; // xmm0_4
  signed int v16; // eax
  __m128i v17; // xmm0
  int v18; // eax
  int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  int v22; // edx
  int v23; // eax
  bool v24; // sf
  unsigned __int8 v25; // of
  signed __int64 v26; // rcx
  UFG::HistoryItem<UFG::qVector2> *v27; // rax

  v2 = value;
  v3 = this;
  if ( !this->mRingBuffer.mCount )
  {
    v4 = value->x;
    v5 = value->y;
    v6 = this->nTimeStamp;
    v7 = (this->mRingBuffer.mLast + 1) % this->mRingBuffer.mCapacity;
    v8 = this->mRingBuffer.mCount;
    this->mRingBuffer.mLast = v7;
    if ( v8 < this->mRingBuffer.mCapacity )
      this->mRingBuffer.mCount = v8 + 1;
    v9 = v7;
    v10 = v3->mRingBuffer.mData;
    v10[v9].mValue.x = v4;
    v10[v9].mValue.y = v5;
    v10[v9].nTimeStamp = v6;
    v11 = v3->nTimeStamp;
LABEL_11:
    v20 = v2->x;
    v21 = v2->y;
    v22 = (v3->mRingBuffer.mLast + 1) % v3->mRingBuffer.mCapacity;
    v23 = v3->mRingBuffer.mCount;
    v25 = __OFSUB__(v23, v3->mRingBuffer.mCapacity);
    v24 = v23 - v3->mRingBuffer.mCapacity < 0;
    v3->mRingBuffer.mLast = v22;
    if ( v24 ^ v25 )
      v3->mRingBuffer.mCount = v23 + 1;
    v26 = v22;
    v27 = v3->mRingBuffer.mData;
    v27[v26].mValue.x = v20;
    v27[v26].mValue.y = v21;
    v27[v26].nTimeStamp = v11;
    return;
  }
  v12 = this->mRingBuffer.mLast;
  v13 = this->mRingBuffer.mData;
  v14 = this->nTimeStamp;
  if ( v14 != v13[v12].nTimeStamp )
  {
    v15 = v2->y;
    v13[v12].mValue.x = v2->x;
    v13[v12].mValue.y = v15;
    v13[v12].nTimeStamp = v14;
    v16 = this->mRingBuffer.mCapacity - 1;
    if ( v16 < 1 )
      v16 = 1;
    v17 = _mm_cvtsi32_si128(v16);
    v18 = this->mRingBuffer.mCount;
    if ( v18 > 1 )
      v18 = 1;
    v19 = UFG::qSignedMod(this->mRingBuffer.mLast - v18, this->mRingBuffer.mCapacity);
    v11 = v3->nTimeStamp;
    if ( (float)(1.0 / COERCE_FLOAT(_mm_cvtepi32_ps(v17))) < (float)((float)(v3->nTimeStamp
                                                                           - v3->mRingBuffer.mData[v19].nTimeStamp)
                                                                   * 2.3283064e-10) )
      goto LABEL_11;
  }
}

