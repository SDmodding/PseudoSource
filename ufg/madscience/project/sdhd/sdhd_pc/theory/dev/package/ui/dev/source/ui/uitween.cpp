// File Line: 35
// RVA: 0xA23790
void __fastcall UFG::UITween::UITween(
        UFG::UITween *this,
        Scaleform::GFx::Movie *movie,
        UFG::qString *path,
        float duration,
        UFG::UITween::eTweenType type)
{
  UFG::UITween::PropertyValues *mValues; // rax
  __int64 v7; // rcx

  this->mPrev = this;
  this->mNext = this;
  this->mMovie = movie;
  UFG::qString::qString(&this->mPath, path);
  this->mDuration = duration;
  this->mType = type;
  *(_QWORD *)&this->mDelay = 0i64;
  this->mLoopType = LOOP_NONE;
  this->mLoopCount = -1;
  *(_QWORD *)&this->mLoopDelay = 0i64;
  this->mRoughnessNumPoints = 0;
  this->mRoughnessRandomize = 1;
  this->mRoughnessTaper = TAPER_NONE;
  this->mRoughnessPoints.mNode.mPrev = &this->mRoughnessPoints.mNode;
  this->mRoughnessPoints.mNode.mNext = &this->mRoughnessPoints.mNode;
  `eh vector constructor iterator(
    this->mCallbacks,
    0x30ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  `eh vector constructor iterator(
    this->mCallbackParams,
    0x30ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  UFG::qString::qString(&this->mTextFormat);
  this->mElapsed = 0.0;
  *(_WORD *)&this->mInited = 0;
  this->mOscillating = 0;
  mValues = this->mValues;
  v7 = 12i64;
  do
  {
    mValues->end = -1.0;
    mValues->start = -1.0;
    mValues->isActive = 0;
    ++mValues;
    --v7;
  }
  while ( v7 );
  this->mCodeCallbacks[0] = 0i64;
  this->mCodeCallbackParams[0] = 0i64;
  this->mCodeCallbacks[1] = 0i64;
  this->mCodeCallbackParams[1] = 0i64;
  this->mCodeCallbacks[2] = 0i64;
  this->mCodeCallbackParams[2] = 0i64;
  this->mCodeCallbacks[3] = 0i64;
  this->mCodeCallbackParams[3] = 0i64;
  this->mCodeCallbacks[4] = 0i64;
  this->mCodeCallbackParams[4] = 0i64;
  this->mCodeCallbacks[5] = 0i64;
  this->mCodeCallbackParams[5] = 0i64;
}

// File Line: 51
// RVA: 0xA282D0
void __fastcall UFG::UITween::SetRange(
        UFG::UITween *this,
        UFG::UITween::eTweenProperty prop,
        float startValue,
        float endValue)
{
  this->mValues[prop].start = startValue;
  this->mValues[prop].end = endValue;
  this->mValues[prop].isActive = startValue != endValue;
}

// File Line: 67
// RVA: 0xA281F0
void __fastcall UFG::UITween::SetCallback(
        UFG::UITween *this,
        UFG::UITween::eCallbackType type,
        Scaleform::GFx::Value *cbFunc)
{
  Scaleform::GFx::Value::operator=(&this->mCallbacks[type], cbFunc);
  if ( (cbFunc->Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&cbFunc->pObjectInterface->vfptr->gap8[8])(
      cbFunc->pObjectInterface,
      cbFunc,
      cbFunc->mValue);
    cbFunc->pObjectInterface = 0i64;
  }
  cbFunc->Type = VT_Undefined;
}

// File Line: 74
// RVA: 0xA28260
void __fastcall UFG::UITween::SetCallbackParams(
        UFG::UITween *this,
        UFG::UITween::eCallbackType type,
        Scaleform::GFx::Value *cbParams)
{
  Scaleform::GFx::Value::operator=(&this->mCallbackParams[type], cbParams);
  if ( (cbParams->Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&cbParams->pObjectInterface->vfptr->gap8[8])(
      cbParams->pObjectInterface,
      cbParams,
      cbParams->mValue);
    cbParams->pObjectInterface = 0i64;
  }
  cbParams->Type = VT_Undefined;
}

// File Line: 81
// RVA: 0xA272F0
char __fastcall UFG::UITween::InvokeCallback(UFG::UITween *this, UFG::UITween::eCallbackType type)
{
  char *v2; // rdi
  unsigned __int64 v3; // r14
  __int64 v4; // rax
  bool v5; // cf
  unsigned __int64 v6; // rax
  UFG::allocator::free_link *v7; // rax
  unsigned int v8; // ebx
  UFG::allocator::free_link *v9; // rbp
  UFG::allocator::free_link *v10; // rsi
  char v11; // di
  void (__fastcall *v13)(void *); // rax
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-48h]

  v2 = (char *)this + 48 * type;
  if ( (v2[392] & 0x8F) == 11 )
  {
    if ( (v2[680] & 0x8F) != 9 )
      return (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64))(**((_QWORD **)v2 + 48)
                                                                                                + 56i64))(
               *((_QWORD *)v2 + 48),
               *((_QWORD *)v2 + 50),
               *((_QWORD *)v2 + 51),
               0i64,
               0i64,
               0i64,
               -2i64);
    v3 = (*(unsigned int (__fastcall **)(_QWORD, _QWORD))(**((_QWORD **)v2 + 84) + 80i64))(
           *((_QWORD *)v2 + 84),
           *((_QWORD *)v2 + 86));
    v4 = 48 * v3;
    if ( !is_mul_ok(v3, 0x30ui64) )
      v4 = -1i64;
    v5 = __CFADD__(v4, 8i64);
    v6 = v4 + 8;
    if ( v5 )
      v6 = -1i64;
    v7 = UFG::qMalloc(v6, "UITween", 0i64);
    v8 = 0;
    if ( v7 )
    {
      LODWORD(v7->mNext) = v3;
      v9 = v7 + 1;
      pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
      `eh vector constructor iterator(&v7[1], 0x30ui64, v3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    }
    else
    {
      v9 = 0i64;
    }
    if ( (_DWORD)v3 )
    {
      v10 = v9;
      do
      {
        (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, UFG::allocator::free_link *, void (__fastcall *)(void *)))(**((_QWORD **)v2 + 84) + 96i64))(
          *((_QWORD *)v2 + 84),
          *((_QWORD *)v2 + 86),
          v8++,
          v10,
          pDtor);
        v10 += 6;
      }
      while ( v8 < (unsigned int)v3 );
    }
    v11 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, UFG::allocator::free_link *, unsigned __int64, __int64))(**((_QWORD **)v2 + 48) + 56i64))(
            *((_QWORD *)v2 + 48),
            *((_QWORD *)v2 + 50),
            *((_QWORD *)v2 + 51),
            0i64,
            v9,
            v3,
            -2i64);
    if ( v9 )
    {
      `eh vector destructor iterator(
        v9,
        0x30ui64,
        (int)v9[-1].mNext,
        (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      operator delete[](&v9[-1]);
    }
    return v11;
  }
  else
  {
    v13 = this->mCodeCallbacks[type];
    if ( v13 )
      v13(this->mCodeCallbackParams[type]);
    return 0;
  }
}

// File Line: 122
// RVA: 0xA28920
float __fastcall UFG::UITween::Update(UFG::UITween *this, float elapsed)
{
  __m128 mDuration_low; // xmm0
  float mDelay; // xmm1_4
  float v7; // xmm8_4
  int v8; // esi
  UFG::UITween::PropertyValues *mValues; // rdi
  UFG::qList<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint,1,0> *p_mRoughnessPoints; // rsi
  unsigned int v11; // r14d
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rdi
  float v14; // xmm1_4
  float v15; // xmm1_4
  UFG::UITween::eTweenRoughnessTaper mRoughnessTaper; // eax
  UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *mNext; // rax
  UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *v18; // rcx
  UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *v19; // rax
  UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *mPrev; // rax
  float v21; // xmm8_4
  float mDuration; // xmm9_4
  int v23; // r15d
  int *v24; // r14
  float *p_end; // rdi
  float *v26; // rsi
  float v27; // xmm4_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  __m128 v30; // xmm5
  float v31; // xmm2_4
  UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *v32; // rax
  float v33; // xmm0_4
  __m128 mStep_low; // xmm6
  float v35; // xmm7_4
  __m128 v36; // xmm1
  float v37; // xmm2_4
  int v38; // ecx
  int v39; // ecx
  float v40; // xmm2_4
  __int16 v41; // ax
  double v42; // r8
  __int64 v43; // rsi
  int mLoopCount; // eax
  float v45; // xmm0_4
  int v46; // xmm0_4
  int v47; // xmm1_4
  int v48; // xmm0_4
  int v49; // xmm1_4
  int v50; // xmm0_4
  int v51; // xmm1_4
  int duration; // [rsp+20h] [rbp-B8h]
  Scaleform::GFx::Value pval; // [rsp+30h] [rbp-A8h] BYREF
  char v54[8]; // [rsp+60h] [rbp-78h] BYREF
  int v55[2]; // [rsp+68h] [rbp-70h] BYREF
  __int64 v56; // [rsp+70h] [rbp-68h]
  float v57; // [rsp+78h] [rbp-60h]
  float v58; // [rsp+7Ch] [rbp-5Ch]
  float v59; // [rsp+80h] [rbp-58h]
  float v60; // [rsp+84h] [rbp-54h]
  float v61; // [rsp+88h] [rbp-50h]
  float v62; // [rsp+8Ch] [rbp-4Ch]
  float v63; // [rsp+90h] [rbp-48h]
  float v64; // [rsp+94h] [rbp-44h]
  __int64 v65[26]; // [rsp+98h] [rbp-40h] BYREF
  __int16 v66; // [rsp+16Ch] [rbp+94h]
  UFG::qString v67; // [rsp+178h] [rbp+A0h] BYREF
  __int64 v68; // [rsp+1A0h] [rbp+C8h]
  UFG::allocator::free_link *v69; // [rsp+248h] [rbp+170h]

  v68 = -2i64;
  if ( !this->mInited )
  {
    UFG::UITween::InvokeCallback(this, ONINIT);
    this->mInited = 1;
  }
  mDelay = this->mDelay;
  if ( mDelay > 0.0 )
  {
    this->mDelay = mDelay - elapsed;
    return 0.0;
  }
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  if ( !(unsigned __int8)Scaleform::GFx::Movie::GetVariable(this->mMovie, &pval, this->mPath.mData) )
  {
    this->mElapsed = this->mDuration;
    v7 = *(float *)&FLOAT_1_0;
    goto LABEL_120;
  }
  if ( this->mElapsed == 0.0 )
  {
    v8 = 0;
    mValues = this->mValues;
    do
    {
      if ( mValues->isActive )
      {
        if ( -1.0 == mValues->start )
          mValues->start = UFG::UITween::GetPropertyValue(this, &pval, (UFG::UITween::eTweenProperty)v8);
        if ( -1.0 == mValues->end )
          mValues->end = UFG::UITween::GetPropertyValue(this, &pval, (UFG::UITween::eTweenProperty)v8);
      }
      ++v8;
      ++mValues;
    }
    while ( v8 < 12 );
  }
  if ( this->mRoughnessNumPoints )
  {
    p_mRoughnessPoints = &this->mRoughnessPoints;
    if ( (UFG::qList<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint,1,0> *)this->mRoughnessPoints.mNode.mNext == &this->mRoughnessPoints )
    {
      v11 = 0;
      do
      {
        v12 = UFG::qMalloc(0x18ui64, "UITween::RoughnessPoint", 0i64);
        v13 = v12;
        v69 = v12;
        if ( v12 )
        {
          v12->mNext = v12;
          v12[1].mNext = v12;
        }
        else
        {
          v13 = 0i64;
        }
        if ( this->mRoughnessRandomize )
          *(float *)&v13[2].mNext = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
        else
          *(float *)&v13[2].mNext = (float)((float)(int)v11 + 1.0)
                                  / (float)((float)(int)this->mRoughnessNumPoints + 1.0);
        mDuration_low = (__m128)LODWORD(this->mDuration);
        *((float *)&v13[2].mNext + 1) = UFG::UITween::GetValue(
                                          this->mType,
                                          0.0,
                                          1.0,
                                          *(float *)&v13[2].mNext,
                                          this->mDuration);
        if ( this->mRoughnessRandomize )
        {
          mDuration_low = (__m128)LODWORD(this->mRoughnessRange);
          v14 = UFG::qRandom(mDuration_low.m128_f32[0] * 2.0, (unsigned int *)&UFG::qDefaultSeed)
              - this->mRoughnessRange;
        }
        else
        {
          if ( (v11 & 1) != 0 )
            v15 = *(float *)&FLOAT_1_0;
          else
            v15 = FLOAT_N1_0;
          v14 = v15 * this->mRoughnessRange;
        }
        mRoughnessTaper = this->mRoughnessTaper;
        if ( mRoughnessTaper == TAPER_IN )
        {
          v14 = v14 * *(float *)&v13[2].mNext;
        }
        else if ( mRoughnessTaper == TAPER_OUT )
        {
          mDuration_low = (__m128)(unsigned int)FLOAT_1_0;
          v14 = v14 * (float)(1.0 - *(float *)&v13[2].mNext);
        }
        *((float *)&v13[2].mNext + 1) = v14 + *((float *)&v13[2].mNext + 1);
        mNext = this->mRoughnessPoints.mNode.mNext;
        if ( mNext == (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)p_mRoughnessPoints )
        {
          this->mRoughnessPoints.mNode.mNext = (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v13;
          v13->mNext = (UFG::allocator::free_link *)p_mRoughnessPoints;
          v13[1].mNext = (UFG::allocator::free_link *)mNext;
          mNext->mPrev = (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v13;
        }
        else
        {
          v18 = this->mRoughnessPoints.mNode.mNext;
          if ( v18 == (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)p_mRoughnessPoints )
          {
LABEL_42:
            mPrev = p_mRoughnessPoints->mNode.mPrev;
            mPrev->mNext = (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v13;
            v13->mNext = (UFG::allocator::free_link *)mPrev;
            v13[1].mNext = (UFG::allocator::free_link *)p_mRoughnessPoints;
            p_mRoughnessPoints->mNode.mPrev = (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v13;
          }
          else
          {
            mDuration_low = (__m128)LODWORD(v13[2].mNext);
            while ( mDuration_low.m128_f32[0] >= *(float *)&v18[1].mPrev )
            {
              v18 = v18->mNext;
              if ( v18 == (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)p_mRoughnessPoints )
                goto LABEL_42;
            }
            v19 = v18->mPrev;
            v19->mNext = (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v13;
            v13->mNext = (UFG::allocator::free_link *)v19;
            v13[1].mNext = (UFG::allocator::free_link *)v18;
            v18->mPrev = (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v13;
          }
        }
        ++v11;
      }
      while ( v11 < this->mRoughnessNumPoints );
    }
  }
  if ( !this->mStarted )
  {
    UFG::UITween::InvokeCallback(this, ONSTART);
    this->mStarted = 1;
  }
  v21 = elapsed + this->mElapsed;
  this->mElapsed = v21;
  mDuration = this->mDuration;
  if ( mDuration <= 0.0 || (v7 = v21 / mDuration, v7 >= 1.0) )
    v7 = *(float *)&FLOAT_1_0;
  v23 = 0;
  v24 = v55;
  p_end = &this->mValues[0].end;
  v26 = &this->mValues[0].end;
  do
  {
    if ( !*((_BYTE *)v26 + 4) )
      goto LABEL_71;
    if ( this->mRoughnessNumPoints )
    {
      v27 = 0.0;
      v28 = *(v26 - 1);
      v29 = v28;
      v30 = (__m128)(unsigned int)FLOAT_1_0;
      v31 = *v26;
      v32 = this->mRoughnessPoints.mNode.mNext;
      if ( v32 != (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)&this->mRoughnessPoints )
      {
        while ( 1 )
        {
          v33 = *(float *)&v32[1].mPrev;
          if ( v33 >= v7 )
            break;
          v27 = *(float *)&v32[1].mPrev;
          v29 = (float)((float)(v31 - v28) * *((float *)&v32[1].mPrev + 1)) + v28;
          v32 = v32->mNext;
          if ( v32 == (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)&this->mRoughnessPoints )
            goto LABEL_57;
        }
        v30.m128_f32[0] = v33;
        v31 = (float)((float)(v31 - v28) * *((float *)&v32[1].mPrev + 1)) + v28;
      }
LABEL_57:
      v30.m128_f32[0] = v30.m128_f32[0] - v27;
      mDuration_low = v30;
      mDuration_low.m128_f32[0] = UFG::UITween::GetValue(
                                    TWEEN_LINEAR,
                                    v29,
                                    v31,
                                    (float)(v7 - v27) / v30.m128_f32[0],
                                    v30.m128_f32[0] * mDuration);
      goto LABEL_70;
    }
    mStep_low = (__m128)LODWORD(this->mStep);
    if ( mStep_low.m128_f32[0] <= 0.0 || v7 >= 1.0 )
    {
      mDuration_low.m128_f32[0] = UFG::UITween::GetValue(this->mType, *(v26 - 1), *v26, v7, mDuration);
LABEL_70:
      *v24 = mDuration_low.m128_i32[0];
      goto LABEL_71;
    }
    v35 = *(v26 - 1);
    mDuration_low.m128_f32[0] = UFG::UITween::GetValue(this->mType, v35, *v26, v7, mDuration);
    v36 = mDuration_low;
    if ( v23 == 11 )
    {
      v37 = (float)((float)(mStep_low.m128_f32[0] * 0.5) + mDuration_low.m128_f32[0]) / mStep_low.m128_f32[0];
      v38 = (int)v37;
      if ( (int)v37 != 0x80000000 )
      {
        mDuration_low = (__m128)COERCE_UNSIGNED_INT((float)v38);
        if ( mDuration_low.m128_f32[0] != v37 )
          v37 = (float)(v38 - (_mm_movemask_ps(_mm_unpacklo_ps(mStep_low, mStep_low)) & 1));
      }
      *(float *)v24 = v37 * mStep_low.m128_f32[0];
    }
    else
    {
      mDuration_low = mStep_low;
      v36.m128_f32[0] = (float)((float)(v36.m128_f32[0] - v35) + (float)(mStep_low.m128_f32[0] * 0.5))
                      / mStep_low.m128_f32[0];
      v39 = (int)v36.m128_f32[0];
      if ( (int)v36.m128_f32[0] != 0x80000000 )
      {
        mDuration_low = (__m128)COERCE_UNSIGNED_INT((float)v39);
        if ( mDuration_low.m128_f32[0] != v36.m128_f32[0] )
          v36.m128_f32[0] = (float)(v39 - (_mm_movemask_ps(_mm_unpacklo_ps(v36, v36)) & 1));
      }
      *(float *)v24 = (float)(v36.m128_f32[0] * mStep_low.m128_f32[0]) + v35;
    }
LABEL_71:
    ++v23;
    v26 += 3;
    ++v24;
  }
  while ( v23 < 12 );
  memset(&v65[12], 0, 112);
  LODWORD(v65[12]) = 1065353216;
  HIDWORD(v65[14]) = 1065353216;
  LODWORD(v65[17]) = 1065353216;
  LODWORD(v65[18]) = 1065353216;
  HIDWORD(v65[20]) = 1065353216;
  LODWORD(v65[23]) = 1065353216;
  HIDWORD(v65[25]) = 1065353216;
  v66 = 0;
  if ( pval.pObjectInterface->vfptr->GetDisplayInfo(
         pval.pObjectInterface,
         (void *)pval.mValue.pString,
         (Scaleform::GFx::Value::DisplayInfo *)v65) )
  {
    if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(this->mMovie) == 1 )
      v40 = *(float *)&FLOAT_1_0;
    else
      v40 = FLOAT_100_0;
    v41 = v66;
    if ( this->mValues[0].isActive )
    {
      v41 = v66 | 1;
      v66 |= 1u;
      *(double *)v65 = *(float *)v55;
    }
    if ( this->mValues[1].isActive )
    {
      v41 |= 2u;
      v66 = v41;
      *(double *)&v65[1] = *(float *)&v55[1];
    }
    if ( this->mValues[2].isActive )
    {
      v41 |= 0x80u;
      v66 = v41;
      *(double *)&v65[6] = *(float *)&v56;
    }
    if ( this->mValues[3].isActive )
    {
      v41 |= 0x20u;
      v66 = v41;
      *(double *)&v65[5] = (float)(*((float *)&v56 + 1) * v40);
    }
    if ( this->mValues[4].isActive )
    {
      v41 |= 8u;
      v66 = v41;
      *(double *)&v65[3] = (float)(v57 * v40);
    }
    if ( this->mValues[5].isActive )
    {
      v41 |= 0x10u;
      v66 = v41;
      *(double *)&v65[4] = (float)(v58 * v40);
    }
    if ( this->mValues[6].isActive )
    {
      v41 |= 0x400u;
      v66 = v41;
      *(double *)&v65[9] = (float)(v59 * v40);
    }
    if ( this->mValues[7].isActive )
    {
      v41 |= 4u;
      v66 = v41;
      *(double *)&v65[2] = v60;
    }
    if ( this->mValues[8].isActive )
    {
      v41 |= 0x100u;
      v66 = v41;
      *(double *)&v65[7] = v61;
    }
    if ( this->mValues[9].isActive )
    {
      v41 |= 0x200u;
      v66 = v41;
      *(double *)&v65[8] = v62;
    }
    if ( this->mValues[10].isActive )
    {
      v66 = v41 | 0x800;
      *(double *)&v65[10] = v63;
    }
    pval.pObjectInterface->vfptr->SetDisplayInfo(
      pval.pObjectInterface,
      (void *)pval.mValue.pString,
      (Scaleform::GFx::Value::DisplayInfo *)v65);
    if ( this->mValues[11].isActive )
    {
      UFG::qString::qString(&v67);
      v42 = v64;
      if ( this->mTextFormat.mLength )
        UFG::qString::Format(&v67, this->mTextFormat.mData, v42);
      else
        UFG::qString::Format(&v67, "%.0f", v42);
      v56 = 0i64;
      LODWORD(v57) = 6;
      pval.DataAux = (unsigned __int64)v67.mData;
      LOBYTE(duration) = (pval.Type & 0x8F) == 10;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, const char *, char *, int))&pval.pObjectInterface->vfptr->gap8[32])(
        pval.pObjectInterface,
        pval.mValue,
        "htmlText",
        v54,
        duration);
      if ( (LOBYTE(v57) & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, unsigned __int64))(*(_QWORD *)v56 + 16i64))(v56, v54, pval.DataAux);
        v56 = 0i64;
      }
      v57 = 0.0;
      UFG::qString::~qString(&v67);
    }
  }
  v43 = 2i64;
  UFG::UITween::InvokeCallback(this, ONUPDATE);
  if ( this->mLoopType )
  {
    if ( v7 >= 1.0 )
    {
      if ( this->mOscillating )
        UFG::UITween::InvokeCallback(this, ONOSCILLATECOMPLETE);
      mLoopCount = this->mLoopCount;
      if ( mLoopCount > 0 )
        this->mLoopCount = mLoopCount - 1;
      if ( this->mLoopCount )
      {
        UFG::UITween::InvokeCallback(this, ONLOOP);
        this->mElapsed = 0.0;
        v45 = this->mDuration;
        if ( v45 <= 0.0 || (v7 = 0.0 / v45, (float)(0.0 / v45) >= 1.0) )
          v7 = *(float *)&FLOAT_1_0;
        this->mDelay = this->mLoopDelay;
        if ( this->mLoopType == LOOP_OSCILLATE )
        {
          do
          {
            v46 = *((_DWORD *)p_end - 1);
            *(p_end - 1) = *p_end;
            *(_DWORD *)p_end = v46;
            v47 = *((_DWORD *)p_end + 2);
            p_end[2] = p_end[3];
            *((_DWORD *)p_end + 3) = v47;
            v48 = *((_DWORD *)p_end + 5);
            p_end[5] = p_end[6];
            *((_DWORD *)p_end + 6) = v48;
            v49 = *((_DWORD *)p_end + 8);
            p_end[8] = p_end[9];
            *((_DWORD *)p_end + 9) = v49;
            v50 = *((_DWORD *)p_end + 11);
            p_end[11] = p_end[12];
            *((_DWORD *)p_end + 12) = v50;
            v51 = *((_DWORD *)p_end + 14);
            p_end[14] = p_end[15];
            *((_DWORD *)p_end + 15) = v51;
            p_end += 18;
            --v43;
          }
          while ( v43 );
          this->mOscillating = !this->mOscillating;
        }
      }
      goto LABEL_118;
    }
  }
  else
  {
LABEL_118:
    if ( v7 >= 1.0 )
      UFG::UITween::InvokeCallback(this, ONCOMPLETE);
  }
LABEL_120:
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  return v7;
}   goto LABEL_118;
    }
  }
  else
  {
LABEL_118:
    if ( v7 >= 1.0 )
      UFG::UITween::InvokeCallback(this, ONCOMPLETE);
  }
LABEL_120:
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
     

// File Line: 393
// RVA: 0xA26500
float __fastcall UFG::UITween::GetValue(
        UFG::UITween::eTweenType type,
        float start,
        float endVal,
        float progress,
        float duration)
{
  __m128 v5; // xmm6
  float v6; // xmm8_4
  float v8; // xmm4_4
  float v9; // xmm7_4
  float result; // xmm0_4
  float v11; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm8_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm4_4
  bool v19; // cf
  float v20; // xmm4_4
  __m128 v21; // xmm0
  float v22; // xmm7_4
  float v23; // xmm4_4
  __m128 v24; // xmm0
  float v25; // xmm1_4
  float v26; // xmm7_4
  float v27; // xmm0_4
  float v28; // xmm6_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm7_4

  v5 = (__m128)(unsigned int)FLOAT_1_0;
  v6 = progress;
  v8 = progress * duration;
  v9 = endVal - start;
  if ( progress >= 1.0 )
    return endVal;
  switch ( type )
  {
    case TWEEN_LINEAR:
      return (float)(v9 * progress) + start;
    case TWEEN_SINE_IN:
      v11 = cosf((float)(v8 / duration) * 1.5707964);
      return (float)((float)(v5.m128_f32[0] - v11) * v9) + start;
    case TWEEN_SINE_OUT:
      return (float)(sinf((float)(v8 / duration) * 1.5707964) * v9) + start;
    case TWEEN_SINE_INOUT:
      return (float)((float)(1.0 - cosf((float)(v8 * 3.1415927) / duration)) * (float)(v9 * 0.5)) + start;
    case TWEEN_QUAD_IN:
LABEL_18:
      v9 = v9 * progress;
      return (float)(v9 * progress) + start;
    case TWEEN_QUAD_OUT:
      v9 = (float)(v9 * -1.0) * progress;
      v6 = progress - 2.0;
      return (float)(v9 * v6) + start;
    case TWEEN_QUAD_INOUT:
      if ( progress < 0.5 )
      {
        v9 = v9 * 2.0;
        goto LABEL_18;
      }
      v13 = (float)((float)((float)(progress * 2.0) - 1.0) * (float)((float)(progress * 2.0) - 3.0)) - 1.0;
      return (float)(v13 * (float)(v9 * -0.5)) + start;
    case TWEEN_CUBIC_IN:
      v14 = FLOAT_3_0;
      return (float)(powf(v8 / duration, v14) * v9) + start;
    case TWEEN_CUBIC_OUT:
      return (float)((float)(powf((float)(v8 / duration) - 1.0, 3.0) + 1.0) * v9) + start;
    case TWEEN_CUBIC_INOUT:
      v15 = FLOAT_0_5;
      v16 = FLOAT_3_0;
      v17 = v8 / (float)(duration * 0.5);
      if ( v17 < 1.0 )
        return (float)(powf(v17, v16) * (float)(v9 * v15)) + start;
      return (float)((float)(powf(v17 - 2.0, v16) + 2.0) * (float)(v9 * v15)) + start;
    case TWEEN_QUART_IN:
      v14 = FLOAT_4_0;
      return (float)(powf(v8 / duration, v14) * v9) + start;
    case TWEEN_QUART_OUT:
      return COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(powf((float)(v8 / duration) - 1.0, 4.0) - 1.0) * v9) ^ _xmm[0])
           + start;
    case TWEEN_QUART_INOUT:
      v15 = FLOAT_0_5;
      v16 = FLOAT_4_0;
      v17 = v8 / (float)(duration * 0.5);
      if ( v17 >= 1.0 )
      {
        v13 = powf(v17 - 2.0, 4.0) - 2.0;
        return (float)(v13 * (float)(v9 * -0.5)) + start;
      }
      return (float)(powf(v17, v16) * (float)(v9 * v15)) + start;
    case TWEEN_QUINT_IN:
      return (float)(powf(v8 / duration, 5.0) * v9) + start;
    case TWEEN_QUINT_OUT:
      return (float)((float)(powf((float)(v8 / duration) - 1.0, 5.0) + 1.0) * v9) + start;
    case TWEEN_QUINT_INOUT:
      v15 = FLOAT_0_5;
      v16 = FLOAT_5_0;
      v17 = v8 / (float)(duration * 0.5);
      if ( v17 < 1.0 )
        return (float)(powf(v17, v16) * (float)(v9 * v15)) + start;
      return (float)((float)(powf(v17 - 2.0, v16) + 2.0) * (float)(v9 * v15)) + start;
    case TWEEN_EXPO_IN:
      return (float)(powf(2.0, (float)((float)(v8 / duration) - 1.0) * 10.0) * v9) + start;
    case TWEEN_EXPO_OUT:
      v11 = powf(2.0, (float)(v8 * -10.0) / duration);
      return (float)((float)(v5.m128_f32[0] - v11) * v9) + start;
  }
  if ( type != TWEEN_EXPO_INOUT )
  {
    switch ( type )
    {
      case TWEEN_CIRC_IN:
        v21 = (__m128)(unsigned int)FLOAT_1_0;
        v21.m128_f32[0] = 1.0 - (float)((float)(v8 / duration) * (float)(v8 / duration));
        return (float)((float)(1.0 - _mm_sqrt_ps(v21).m128_f32[0]) * v9) + start;
      case TWEEN_CIRC_OUT:
        v5.m128_f32[0] = 1.0 - (float)((float)((float)(v8 / duration) - 1.0) * (float)((float)(v8 / duration) - 1.0));
        return (float)(_mm_sqrt_ps(v5).m128_f32[0] * v9) + start;
      case TWEEN_CIRC_INOUT:
        v22 = v9 * 0.5;
        v23 = v8 / (float)(duration * 0.5);
        v24 = (__m128)(unsigned int)FLOAT_1_0;
        if ( v23 >= 1.0 )
        {
          v24.m128_f32[0] = 1.0 - (float)((float)(v23 - 2.0) * (float)(v23 - 2.0));
          return (float)((float)(_mm_sqrt_ps(v24).m128_f32[0] + 1.0) * v22) + start;
        }
        else
        {
          v24.m128_f32[0] = 1.0 - (float)(v23 * v23);
          return (float)((float)(1.0 - _mm_sqrt_ps(v24).m128_f32[0]) * v22) + start;
        }
      case TWEEN_BACK_IN:
        return (float)((float)((float)(v9 * progress) * progress) * (float)((float)(progress * 2.70158) - 1.70158))
             + start;
      case TWEEN_BACK_OUT:
        return (float)((float)((float)((float)((float)((float)(progress - 1.0) * 2.70158) + 1.70158)
                                     * (float)((float)(progress - 1.0) * (float)(progress - 1.0)))
                             + 1.0)
                     * v9)
             + start;
      case TWEEN_BACK_INOUT:
        v25 = progress * 2.0;
        v26 = v9 * 0.5;
        if ( progress >= 0.5 )
          return (float)((float)((float)((float)((float)((float)(v25 + -2.0) * 3.5949094) + 2.5949094)
                                       * (float)((float)(v25 + -2.0) * (float)(v25 + -2.0)))
                               + 2.0)
                       * v26)
               + start;
        else
          return (float)((float)((float)((float)(v25 * 3.5949094) - 2.5949094) * (float)(v25 * v25)) * v26) + start;
    }
    if ( (unsigned int)(type - 25) <= 2 )
    {
      v29 = start;
      v30 = v6;
      if ( type == TWEEN_BOUNCE_IN )
      {
        v29 = 0.0;
        v30 = 1.0 - v6;
      }
      else if ( type == TWEEN_BOUNCE_INOUT )
      {
        v29 = 0.0;
        if ( v6 >= 0.5 )
          v30 = (float)(v6 * 2.0) - 1.0;
        else
          v30 = 1.0 - (float)(v6 * 2.0);
      }
      if ( v30 >= 0.36363637 )
      {
        if ( v30 >= 0.72727275 )
        {
          if ( v30 >= 0.9090909090909091 )
            v32 = (float)((float)((float)(v30 + -0.95454544) * 7.5625) * (float)(v30 + -0.95454544)) + 0.984375;
          else
            v32 = (float)((float)((float)(v30 + -0.81818181) * 7.5625) * (float)(v30 + -0.81818181)) + 0.9375;
        }
        else
        {
          v32 = (float)((float)((float)(v30 + -0.54545456) * 7.5625) * (float)(v30 + -0.54545456)) + 0.75;
        }
        v31 = v32 * v9;
      }
      else
      {
        v31 = (float)((float)(v9 * 7.5625) * v30) * v30;
      }
      result = v31 + v29;
      if ( type == TWEEN_BOUNCE_IN )
      {
        v33 = v9 + start;
      }
      else
      {
        if ( type != TWEEN_BOUNCE_INOUT )
          return result;
        result = result * 0.5;
        v33 = (float)(v9 * 0.5) + start;
        if ( v6 >= 0.5 )
          return v33 + result;
      }
      return v33 - result;
    }
    switch ( type )
    {
      case TWEEN_ELASTIC_IN:
        v6 = progress - 1.0;
        v27 = powf(2.0, (float)(progress - 1.0) * 10.0);
        return start - (float)((float)(v27 * v9) * sinf((float)((float)(v6 - 0.075000003) * 6.2831855) * 3.3333333));
      case TWEEN_ELASTIC_OUT:
        v28 = powf(2.0, progress * -10.0) * v9;
        break;
      case TWEEN_ELASTIC_INOUT:
        v6 = (float)(progress * 2.0) - 1.0;
        if ( progress < 0.5 )
        {
          v27 = powf(2.0, v6 * 10.0);
          v9 = v9 * 0.5;
          return start - (float)((float)(v27 * v9) * sinf((float)((float)(v6 - 0.075000003) * 6.2831855) * 3.3333333));
        }
        v28 = powf(2.0, v6 * -10.0) * (float)(v9 * 0.5);
        break;
      default:
        return (float)(v9 * v6) + start;
    }
    return (float)(v28 * sinf((float)((float)(v6 - 0.075000003) * 6.2831855) * 3.3333333)) + (float)(v9 + start);
  }
  v18 = v8 / (float)(duration * 0.5);
  v19 = v18 < 1.0;
  v20 = v18 - 1.0;
  if ( !v19 )
  {
    v5.m128_f32[0] = FLOAT_2_0;
    v11 = powf(2.0, v20 * -10.0);
    v9 = v9 * 0.5;
    return (float)((float)(v5.m128_f32[0] - v11) * v9) + start;
  }
  return (float)(powf(2.0, v20 * 10.0) * (float)(v9 * 0.5)) + start;
}

// File Line: 647
// RVA: 0xA26290
float __fastcall UFG::UITween::GetPropertyValue(
        UFG::UITween *this,
        Scaleform::GFx::Value *movieClip,
        UFG::UITween::eTweenProperty prop)
{
  float v5; // xmm6_4
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // rcx
  Scaleform::GFx::Value::ValueUnion mValue; // rdx
  float result; // xmm0_4
  __int64 v9[26]; // [rsp+20h] [rbp-F8h] BYREF
  __int16 v10; // [rsp+F4h] [rbp-24h]

  memset(&v9[12], 0, 112);
  v5 = *(float *)&FLOAT_1_0;
  LODWORD(v9[12]) = 1065353216;
  HIDWORD(v9[14]) = 1065353216;
  LODWORD(v9[17]) = 1065353216;
  pObjectInterface = movieClip->pObjectInterface;
  mValue = movieClip->mValue;
  LODWORD(v9[18]) = 1065353216;
  HIDWORD(v9[20]) = 1065353216;
  LODWORD(v9[23]) = 1065353216;
  HIDWORD(v9[25]) = 1065353216;
  v10 = 0;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ValueUnion, __int64 *))pObjectInterface->vfptr->GetDisplayInfo)(
          pObjectInterface,
          mValue,
          v9) )
    return FLOAT_N1_0;
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(this->mMovie) != 1 )
    v5 = FLOAT_100_0;
  switch ( prop )
  {
    case XPOS:
      result = *(double *)v9;
      break;
    case YPOS:
      result = *(double *)&v9[1];
      break;
    case ZPOS:
      result = *(double *)&v9[6];
      break;
    case ALPHA:
      result = *(double *)&v9[5] / v5;
      break;
    case XSCALE:
      result = *(double *)&v9[3] / v5;
      break;
    case YSCALE:
      result = *(double *)&v9[4] / v5;
      break;
    case ZSCALE:
      result = *(double *)&v9[9];
      break;
    case ROTATION:
      result = *(double *)&v9[2];
      break;
    case XROT:
      result = *(double *)&v9[7];
      break;
    case YROT:
      result = *(double *)&v9[8];
      break;
    case FOV:
      result = *(double *)&v9[10];
      break;
    case TEXT:
      result = 0.0;
      break;
    default:
      return FLOAT_N1_0;
  }
  return result;
}

