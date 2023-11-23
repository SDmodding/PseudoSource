// File Line: 89
// RVA: 0x3CC070
void __fastcall UFG::HomerCubic<UFG::qVector3>::SetDuration(
        UFG::HomerCubic<UFG::qVector3> *this,
        UFG::qVector3 *duration)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  float z; // xmm3_4
  float y; // xmm2_4
  float x; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4

  v2 = this->mParameter.y / this->mDuration.y;
  v3 = this->mParameter.z / this->mDuration.z;
  this->mParameter.x = this->mParameter.x / this->mDuration.x;
  this->mParameter.y = v2;
  this->mParameter.z = v3;
  z = duration->z;
  if ( z <= 0.0099999998 )
    z = FLOAT_0_0099999998;
  y = duration->y;
  if ( y <= 0.0099999998 )
    y = FLOAT_0_0099999998;
  x = duration->x;
  if ( duration->x <= 0.0099999998 )
    x = FLOAT_0_0099999998;
  this->mDuration.x = x;
  this->mDuration.y = y;
  this->mDuration.z = z;
  v7 = y * this->mParameter.y;
  v8 = z * this->mParameter.z;
  this->mParameter.x = x * this->mParameter.x;
  this->mParameter.y = v7;
  this->mParameter.z = v8;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(this);
}

// File Line: 102
// RVA: 0x3CBF90
void __fastcall UFG::HomerCubic<UFG::qVector3>::SetDesiredPosition(
        UFG::HomerCubic<UFG::qVector3> *this,
        UFG::qVector3 *position)
{
  float y; // xmm0_4
  float z; // xmm1_4

  y = position->y;
  z = position->z;
  this->p1.x = position->x;
  this->p1.y = y;
  this->p1.z = z;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(this);
  *(_QWORD *)&this->mParameter.x = 0i64;
  this->mParameter.z = 0.0;
}

// File Line: 119
// RVA: 0x3CF7F0
void __fastcall UFG::HomerCubic<float>::Update(UFG::HomerCubic<float> *this, const float f_elapsed_seconds)
{
  float mDuration; // xmm5_4
  float A; // xmm4_4
  float B; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4

  mDuration = f_elapsed_seconds + this->mParameter;
  if ( mDuration <= 0.0 )
    mDuration = 0.0;
  if ( mDuration >= this->mDuration )
    mDuration = this->mDuration;
  A = this->A;
  B = this->B;
  this->mParameter = mDuration;
  v5 = (float)((float)((float)((float)(A * 3.0) * mDuration) + (float)(B * 2.0)) * mDuration) + this->C;
  v6 = (float)((float)((float)((float)((float)(A * mDuration) + B) * mDuration) + this->C) * mDuration) + this->D;
  this->v0 = v5;
  this->p0 = v6;
}

// File Line: 156
// RVA: 0xB9CC0
void __fastcall UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(UFG::HomerCubic<UFG::qVector3> *this)
{
  float z; // xmm15_4
  float y; // xmm14_4
  float x; // xmm13_4
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm1_4
  float v7; // xmm6_4
  float v8; // xmm2_4
  float v9; // eax
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4

  z = this->mDuration.z;
  if ( z <= 0.0099999998 )
    z = FLOAT_0_0099999998;
  y = this->mDuration.y;
  if ( y <= 0.0099999998 )
    y = FLOAT_0_0099999998;
  x = this->mDuration.x;
  if ( this->mDuration.x <= 0.0099999998 )
    x = FLOAT_0_0099999998;
  v4 = (float)((float)((float)(this->v1.y + this->v0.y) * y) + (float)((float)(this->p0.y - this->p1.y) * 2.0))
     / (float)((float)(y * y) * y);
  v5 = (float)((float)((float)(this->v0.z + this->v1.z) * z) + (float)((float)(this->p0.z - this->p1.z) * 2.0))
     / (float)((float)(z * z) * z);
  this->A.x = (float)((float)((float)(this->v1.x + this->v0.x) * x) + (float)((float)(this->p0.x - this->p1.x) * 2.0))
            / (float)((float)(x * x) * x);
  this->A.y = v4;
  this->A.z = v5;
  v6 = (float)(this->p1.z - this->p0.z) * 3.0;
  v7 = (float)(this->v0.z * 2.0) + this->v1.z;
  v8 = (float)((float)((float)(this->p1.y - this->p0.y) * 3.0)
             - (float)((float)((float)(this->v0.y * 2.0) + this->v1.y) * y))
     / (float)(y * y);
  this->B.x = (float)((float)((float)(this->p1.x - this->p0.x) * 3.0)
                    - (float)((float)((float)(this->v0.x * 2.0) + this->v1.x) * x))
            / (float)(x * x);
  this->B.y = v8;
  this->B.z = (float)(v6 - (float)(v7 * z)) / (float)(z * z);
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
void __fastcall UFG::HomerCubicAngular::Init(
        UFG::HomerCubicAngular *this,
        float _p0,
        float _p1,
        float _v0,
        float _v1,
        float duration,
        float modulo)
{
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm0_4

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
  this->mHomerCubic.mDuration = v9;
  this->mHomerCubic.v0 = _v0;
  this->mHomerCubic.mParameter = 0.0;
  this->mHomerCubic.v1 = _v1;
  this->mHomerCubic.p0 = _p0;
  this->mHomerCubic.p1 = v10;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mHomerCubic);
}

// File Line: 194
// RVA: 0x3CD280
void __fastcall UFG::HomerCubicAngular::SetPosition(UFG::HomerCubicAngular *this, float position)
{
  this->mHomerCubic.p1 = UFG::HomerCubicAngular::NewDesiredPosition(
                           this,
                           position,
                           this->mHomerCubic.p1,
                           this->mHomerCubic.v0);
  UFG::HomerCubic<float>::MakeCoeffs(&this->mHomerCubic);
  this->mHomerCubic.mParameter = 0.0;
  this->mHomerCubic.p0 = position;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mHomerCubic);
  this->mHomerCubic.mParameter = 0.0;
}

// File Line: 208
// RVA: 0x3CBFD0
void __fastcall UFG::HomerCubicAngular::SetDesiredPosition(UFG::HomerCubicAngular *this, float position)
{
  this->mHomerCubic.p1 = UFG::HomerCubicAngular::NewDesiredPosition(
                           this,
                           this->mHomerCubic.p0,
                           position,
                           this->mHomerCubic.v0);
  UFG::HomerCubic<float>::MakeCoeffs(&this->mHomerCubic);
  this->mHomerCubic.mParameter = 0.0;
}

// File Line: 240
// RVA: 0x3D63B0
void __fastcall UFG::HomerCubicAngular::Update(UFG::HomerCubicAngular *this, float f_elapsed_seconds)
{
  float v3; // xmm8_4
  float v4; // xmm0_4
  __m128 mModuloRecip_low; // xmm2
  __m128 v6; // xmm6
  int v7; // ecx
  int v8; // ecx

  UFG::HomerCubic<float>::Update(&this->mHomerCubic, f_elapsed_seconds);
  v3 = UFG::qSignedMod(COERCE_DOUBLE((unsigned __int64)LODWORD(this->mHomerCubic.p0)), this->mModulo);
  v4 = UFG::qSignedMod(COERCE_DOUBLE((unsigned __int64)LODWORD(this->mHomerCubic.p1)), this->mModulo);
  mModuloRecip_low = (__m128)LODWORD(this->mModuloRecip);
  v6 = mModuloRecip_low;
  v6.m128_f32[0] = mModuloRecip_low.m128_f32[0] * v3;
  v7 = (int)(float)(mModuloRecip_low.m128_f32[0] * v3);
  if ( v7 != 0x80000000 && (float)v7 != v6.m128_f32[0] )
    v6.m128_f32[0] = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v6, v6)) & 1));
  mModuloRecip_low.m128_f32[0] = mModuloRecip_low.m128_f32[0] * v4;
  v8 = (int)mModuloRecip_low.m128_f32[0];
  if ( (int)mModuloRecip_low.m128_f32[0] != 0x80000000 && (float)v8 != mModuloRecip_low.m128_f32[0] )
    mModuloRecip_low.m128_f32[0] = (float)(v8
                                         - (_mm_movemask_ps(_mm_unpacklo_ps(mModuloRecip_low, mModuloRecip_low)) & 1));
  if ( v6.m128_f32[0] == mModuloRecip_low.m128_f32[0] )
  {
    UFG::HomerCubicAngular::SetPosition(this, v3 - (float)(v6.m128_f32[0] * this->mModulo));
    this->mHomerCubic.p1 = UFG::HomerCubicAngular::NewDesiredPosition(
                             this,
                             this->mHomerCubic.p0,
                             v4 - (float)(v6.m128_f32[0] * this->mModulo),
                             this->mHomerCubic.v0);
    UFG::HomerCubic<float>::MakeCoeffs(&this->mHomerCubic);
    this->mHomerCubic.mParameter = 0.0;
  }
}

// File Line: 286
// RVA: 0x3C7590
float __fastcall UFG::HomerCubicAngular::NewDesiredPosition(
        UFG::HomerCubicAngular *this,
        const float _p0,
        const float _p1,
        const float _v0)
{
  __m128 mModuloRecip_low; // xmm3
  float mModulo; // xmm1_4
  __m128 v7; // xmm4
  int v8; // ecx
  float v9; // xmm4_4
  int v10; // ecx
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm2_4

  mModuloRecip_low = (__m128)LODWORD(this->mModuloRecip);
  mModulo = this->mModulo;
  v7 = mModuloRecip_low;
  v7.m128_f32[0] = mModuloRecip_low.m128_f32[0] * _p0;
  v8 = (int)(float)(mModuloRecip_low.m128_f32[0] * _p0);
  if ( v8 != 0x80000000 && (float)v8 != v7.m128_f32[0] )
    v7.m128_f32[0] = (float)(v8 - (_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1));
  mModuloRecip_low.m128_f32[0] = mModuloRecip_low.m128_f32[0] * _p1;
  v9 = v7.m128_f32[0] * mModulo;
  v10 = (int)mModuloRecip_low.m128_f32[0];
  if ( (int)mModuloRecip_low.m128_f32[0] != 0x80000000 && (float)v10 != mModuloRecip_low.m128_f32[0] )
    mModuloRecip_low.m128_f32[0] = (float)(v10
                                         - (_mm_movemask_ps(_mm_unpacklo_ps(mModuloRecip_low, mModuloRecip_low)) & 1));
  v11 = _p1 - (float)(mModuloRecip_low.m128_f32[0] * mModulo);
  if ( (float)(_p0 - v9) >= v11 )
    v12 = 0.0;
  else
    LODWORD(v12) = LODWORD(mModulo) ^ _xmm[0];
  v13 = (float)(v11 + v9) + v12;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(_p0 - v13) & _xmm) >= COERCE_FLOAT(COERCE_UNSIGNED_INT(_p0 - (float)(v13 + mModulo)) & _xmm) )
    return v13 + mModulo;
  else
    return v13;
}

// File Line: 323
// RVA: 0x532D20
// local variable allocation has failed, the output may be wrong!
float __fastcall UFG::LinearTable<float>::GetValue(UFG::LinearTable<float> *this, double x)
{
  float fMin; // xmm0_4
  __m128 fMin_low; // xmm2
  float v5; // xmm1_4
  int v6; // ecx
  int v7; // r8d
  float v8; // xmm2_4

  fMin = this->fMin;
  fMin_low = *(__m128 *)&x;
  if ( *(float *)&x <= fMin )
    fMin_low = (__m128)LODWORD(this->fMin);
  if ( fMin_low.m128_f32[0] >= this->fMax )
    fMin_low = (__m128)LODWORD(this->fMax);
  fMin_low.m128_f32[0] = (float)(fMin_low.m128_f32[0] - fMin) * this->fCoef;
  v5 = fMin_low.m128_f32[0];
  v6 = (int)fMin_low.m128_f32[0];
  if ( (int)fMin_low.m128_f32[0] != 0x80000000 && (float)v6 != fMin_low.m128_f32[0] )
    v5 = (float)(v6 - (_mm_movemask_ps(_mm_unpacklo_ps(fMin_low, fMin_low)) & 1));
  v7 = this->nData - 1;
  v8 = fMin_low.m128_f32[0] - v5;
  if ( (int)v5 + 1 < v7 )
    v7 = (int)v5 + 1;
  return (float)((float)((float)this->pData[v7] - (float)this->pData[v5]) * v8) + (float)this->pData[v5];
}

// File Line: 380
// RVA: 0x47400
float __fastcall UFG::LinearGraph<float>::GetValue(UFG::LinearGraph<float> *this, float x)
{
  const float *fDomain; // rdi
  __int64 nData; // rcx
  __int64 DomainBracket; // rcx
  float v7; // xmm6_4

  fDomain = this->fDomain;
  if ( x <= *fDomain )
    return *this->tRange;
  nData = this->nData;
  if ( x >= fDomain[nData - 1] )
    return this->tRange[nData - 1];
  DomainBracket = (int)UFG::LinearGraph<float>::FindDomainBracket((UFG::LinearGraph<UFG::qVector3> *)this, x);
  v7 = (float)(x - fDomain[DomainBracket - 1]) / (float)(fDomain[DomainBracket] - fDomain[DomainBracket - 1]);
  return (float)((float)(1.0 - v7) * (float)this->tRange[DomainBracket - 1])
       + (float)(v7 * (float)this->tRange[DomainBracket]);
}

// File Line: 492
// RVA: 0x47390
__int64 __fastcall UFG::LinearGraph<float>::FindDomainBracket(UFG::LinearGraph<UFG::qVector3> *this, float x)
{
  int nData; // edx
  const float *fDomain; // r9
  unsigned int v4; // ecx
  unsigned int v5; // r8d
  __int64 v6; // rax
  int v8; // r8d

  nData = this->nData;
  fDomain = this->fDomain;
  if ( this->nData >= 6 )
  {
    v8 = 0;
    if ( nData > 1 )
    {
      do
      {
        if ( x >= fDomain[(nData + v8) >> 1] )
          v8 = (nData + v8) >> 1;
        else
          nData = (nData + v8) >> 1;
      }
      while ( nData - v8 > 1 );
    }
    return (unsigned int)(v8 + 1);
  }
  else
  {
    v4 = 1;
    v5 = nData - 1;
    v6 = 1i64;
    if ( nData - 1 <= 1i64 )
    {
      return v5;
    }
    else
    {
      while ( x >= fDomain[v6] )
      {
        ++v6;
        ++v4;
        if ( v6 >= (int)v5 )
          return v5;
      }
      return v4;
    }
  }
}

// File Line: 651
// RVA: 0x6423B0
void __fastcall UFG::RingBuffer<UFG::Crumb>::RingBuffer<UFG::Crumb>(UFG::RingBuffer<UFG::Crumb> *this, int capacity)
{
  UFG::Crumb *v3; // rdi
  __int64 v5; // rax
  bool v6; // cf
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax

  this->mLast = -1;
  v3 = 0i64;
  this->mCount = 0;
  this->mCapacity = capacity;
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
    LODWORD(v8->mNext) = capacity;
    v3 = (UFG::Crumb *)((char *)&v8->mNext + 4);
    `eh vector constructor iterator(
      (char *)&v8->mNext + 4,
      0x20ui64,
      capacity,
      (void (__fastcall *)(void *))Assembly::GetRCX);
  }
  this->mData = v3;
}

// File Line: 656
// RVA: 0x6438D0
void __fastcall UFG::RingBuffer<UFG::HistoryItem<UFG::qVector2>>::~RingBuffer<UFG::HistoryItem<UFG::qVector2>>(
        UFG::RingBuffer<UFG::HistoryItem<UFG::qVector2> > *this)
{
  operator delete[](this->mData);
}

// File Line: 707
// RVA: 0x6565E0
UFG::Crumb *__fastcall UFG::RingBuffer<UFG::Crumb>::NthNewest(UFG::RingBuffer<UFG::Crumb> *this, int n)
{
  int mCount; // eax
  int v3; // r8d
  int mLast; // ecx

  mCount = this->mCount;
  v3 = 0;
  if ( n > 0 )
    v3 = n;
  mLast = this->mLast;
  if ( v3 < mCount )
    mCount = v3;
  return &this->mData[(int)UFG::qSignedMod(mLast - mCount, this->mCapacity)];
}

// File Line: 802
// RVA: 0x651040
UFG::qVector2 *__fastcall UFG::HistoryBuffer<UFG::qVector2>::GetValue(
        UFG::HistoryBuffer<UFG::qVector2> *this,
        UFG::qVector2 *result,
        float age)
{
  int mCount; // ebp
  UFG::qVector2 *v7; // rax
  int v8; // r14d
  int v9; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  UFG::HistoryItem<UFG::qVector2> *v13; // r12
  __int64 v14; // r15
  float v15; // xmm6_4
  int mCapacity; // ecx
  UFG::HistoryItem<UFG::qVector2> *mData; // rcx
  float y; // eax
  int v19; // eax
  int v20; // eax
  UFG::HistoryItem<UFG::qVector2> *v21; // rcx
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm7_4
  float v25; // xmm0_4

  mCount = this->mRingBuffer.mCount;
  if ( !mCount )
  {
    v7 = result;
    *result = 0i64;
    return v7;
  }
  if ( mCount == 1 )
  {
    *result = this->mRingBuffer.mData[this->mRingBuffer.mLast].mValue;
  }
  else
  {
    v8 = 0;
    v9 = 0;
    if ( mCount <= 0 )
    {
LABEL_12:
      mCapacity = this->mRingBuffer.mCapacity;
      if ( this->mRingBuffer.mCount >= mCapacity )
        mData = &this->mRingBuffer.mData[(this->mRingBuffer.mLast + 1) % mCapacity];
      else
        mData = this->mRingBuffer.mData;
      result->x = mData->mValue.x;
      y = mData->mValue.y;
    }
    else
    {
      while ( 1 )
      {
        v10 = this->mRingBuffer.mCount;
        v11 = 0;
        if ( v9 > 0 )
          v11 = v9;
        if ( v11 < v10 )
          v10 = v11;
        v12 = UFG::qSignedMod(this->mRingBuffer.mLast - v10, this->mRingBuffer.mCapacity);
        v13 = this->mRingBuffer.mData;
        v14 = v12;
        v15 = (float)((float)(this->nTimeStamp - v13[v12].nTimeStamp) * 2.3283064e-10) * this->fDuration;
        if ( age <= v15 )
          break;
        if ( ++v9 >= mCount )
          goto LABEL_12;
      }
      if ( v9 )
      {
        if ( v9 - 1 > 0 )
          v8 = v9 - 1;
        v19 = this->mRingBuffer.mCount;
        if ( v8 < v19 )
          v19 = v8;
        v20 = UFG::qSignedMod(this->mRingBuffer.mLast - v19, this->mRingBuffer.mCapacity);
        v21 = this->mRingBuffer.mData;
        v22 = v21[v20].mValue.y;
        v23 = (float)((float)(this->nTimeStamp - v21[v20].nTimeStamp) * 2.3283064e-10) * this->fDuration;
        v24 = (float)(age - v23) / (float)(v15 - v23);
        v25 = (float)(v13[v14].mValue.y - v22) * v24;
        result->x = v21[v20].mValue.x + (float)((float)(v13[v14].mValue.x - v21[v20].mValue.x) * v24);
        result->y = v22 + v25;
        return result;
      }
      result->x = v13[v12].mValue.x;
      y = v13[v12].mValue.y;
    }
    result->y = y;
  }
  return result;
}

// File Line: 826
// RVA: 0x657CC0
void __fastcall UFG::HistoryBuffer<UFG::qVector2>::Record(
        UFG::HistoryBuffer<UFG::qVector2> *this,
        UFG::qVector2 *value)
{
  float x; // xmm0_4
  float y; // xmm1_4
  unsigned int nTimeStamp; // r9d
  int v7; // edx
  int mCount; // eax
  __int64 v9; // rcx
  UFG::HistoryItem<UFG::qVector2> *mData; // rax
  unsigned int v11; // r8d
  __int64 mLast; // rax
  UFG::HistoryItem<UFG::qVector2> *v13; // rdx
  unsigned int v14; // r8d
  float v15; // xmm0_4
  signed int v16; // eax
  __m128i v17; // xmm0
  int v18; // eax
  int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  int v22; // edx
  int v23; // eax
  bool v24; // cc
  __int64 v25; // rcx
  UFG::HistoryItem<UFG::qVector2> *v26; // rax

  if ( !this->mRingBuffer.mCount )
  {
    x = value->x;
    y = value->y;
    nTimeStamp = this->nTimeStamp;
    v7 = (this->mRingBuffer.mLast + 1) % this->mRingBuffer.mCapacity;
    mCount = this->mRingBuffer.mCount;
    this->mRingBuffer.mLast = v7;
    if ( mCount < this->mRingBuffer.mCapacity )
      this->mRingBuffer.mCount = mCount + 1;
    v9 = v7;
    mData = this->mRingBuffer.mData;
    mData[v9].mValue.x = x;
    mData[v9].mValue.y = y;
    mData[v9].nTimeStamp = nTimeStamp;
    v11 = this->nTimeStamp;
LABEL_11:
    v20 = value->x;
    v21 = value->y;
    v22 = (this->mRingBuffer.mLast + 1) % this->mRingBuffer.mCapacity;
    v23 = this->mRingBuffer.mCount;
    v24 = v23 < this->mRingBuffer.mCapacity;
    this->mRingBuffer.mLast = v22;
    if ( v24 )
      this->mRingBuffer.mCount = v23 + 1;
    v25 = v22;
    v26 = this->mRingBuffer.mData;
    v26[v25].mValue.x = v20;
    v26[v25].mValue.y = v21;
    v26[v25].nTimeStamp = v11;
    return;
  }
  mLast = this->mRingBuffer.mLast;
  v13 = this->mRingBuffer.mData;
  v14 = this->nTimeStamp;
  if ( v14 != v13[mLast].nTimeStamp )
  {
    v15 = value->y;
    v13[mLast].mValue.x = value->x;
    v13[mLast].mValue.y = v15;
    v13[mLast].nTimeStamp = v14;
    v16 = this->mRingBuffer.mCapacity - 1;
    if ( v16 < 1 )
      v16 = 1;
    v17 = _mm_cvtsi32_si128(v16);
    v18 = this->mRingBuffer.mCount;
    if ( v18 > 1 )
      v18 = 1;
    v19 = UFG::qSignedMod(this->mRingBuffer.mLast - v18, this->mRingBuffer.mCapacity);
    v11 = this->nTimeStamp;
    if ( (float)(1.0 / _mm_cvtepi32_ps(v17).m128_f32[0]) < (float)((float)(int)(v11
                                                                              - this->mRingBuffer.mData[v19].nTimeStamp)
                                                                 * 2.3283064e-10) )
      goto LABEL_11;
  }
}

