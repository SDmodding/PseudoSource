// File Line: 35
// RVA: 0xA23790
void __fastcall UFG::UITween::UITween(UFG::UITween *this, Scaleform::GFx::Movie *movie, UFG::qString *path, float duration, UFG::UITween::eTweenType type)
{
  UFG::UITween *v5; // rbx
  signed __int64 v6; // rax
  signed __int64 v7; // rcx
  UFG::qList<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint,1,0> *v8; // [rsp+68h] [rbp+10h]

  v5 = this;
  this->mPrev = (UFG::qNode<UFG::UITween,UFG::UITween> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)&this->mPrev;
  this->mMovie = movie;
  UFG::qString::qString(&this->mPath, path);
  v5->mDuration = duration;
  v5->mType = type;
  *(_QWORD *)&v5->mDelay = 0i64;
  v5->mLoopType = 0;
  v5->mLoopCount = -1;
  *(_QWORD *)&v5->mLoopDelay = 0i64;
  v5->mRoughnessNumPoints = 0;
  v5->mRoughnessRandomize = 1;
  v5->mRoughnessTaper = 0;
  v8 = &v5->mRoughnessPoints;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  `eh vector constructor iterator(
    v5->mCallbacks,
    0x30ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  `eh vector constructor iterator(
    v5->mCallbackParams,
    0x30ui64,
    6,
    (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  UFG::qString::qString(&v5->mTextFormat);
  v5->mElapsed = 0.0;
  *(_WORD *)&v5->mInited = 0;
  v5->mOscillating = 0;
  v6 = (signed __int64)v5->mValues;
  v7 = 12i64;
  do
  {
    *(_DWORD *)(v6 + 4) = -1082130432;
    *(_DWORD *)v6 = -1082130432;
    *(_BYTE *)(v6 + 8) = 0;
    v6 += 12i64;
    --v7;
  }
  while ( v7 );
  v5->mCodeCallbacks[0] = 0i64;
  v5->mCodeCallbackParams[0] = 0i64;
  v5->mCodeCallbacks[1] = 0i64;
  v5->mCodeCallbackParams[1] = 0i64;
  v5->mCodeCallbacks[2] = 0i64;
  v5->mCodeCallbackParams[2] = 0i64;
  v5->mCodeCallbacks[3] = 0i64;
  v5->mCodeCallbackParams[3] = 0i64;
  v5->mCodeCallbacks[4] = 0i64;
  v5->mCodeCallbackParams[4] = 0i64;
  v5->mCodeCallbacks[5] = 0i64;
  v5->mCodeCallbackParams[5] = 0i64;
}

// File Line: 51
// RVA: 0xA282D0
void __fastcall UFG::UITween::SetRange(UFG::UITween *this, UFG::UITween::eTweenProperty prop, float startValue, float endValue)
{
  this->mValues[prop].start = startValue;
  this->mValues[prop].end = endValue;
  this->mValues[prop].isActive = startValue != endValue;
}

// File Line: 67
// RVA: 0xA281F0
void __fastcall UFG::UITween::SetCallback(UFG::UITween *this, UFG::UITween::eCallbackType type, Scaleform::GFx::Value *cbFunc)
{
  Scaleform::GFx::Value *v3; // rbx

  v3 = cbFunc;
  Scaleform::GFx::Value::operator=(&this->mCallbacks[type], cbFunc);
  if ( ((unsigned int)v3->Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v3->pObjectInterface->vfptr->gap8[8])(
      v3->pObjectInterface,
      v3,
      *(_QWORD *)&v3->mValue.NValue);
    v3->pObjectInterface = 0i64;
  }
  v3->Type = 0;
}

// File Line: 74
// RVA: 0xA28260
void __fastcall UFG::UITween::SetCallbackParams(UFG::UITween *this, UFG::UITween::eCallbackType type, Scaleform::GFx::Value *cbParams)
{
  Scaleform::GFx::Value *v3; // rbx

  v3 = cbParams;
  Scaleform::GFx::Value::operator=(&this->mCallbackParams[type], cbParams);
  if ( ((unsigned int)v3->Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v3->pObjectInterface->vfptr->gap8[8])(
      v3->pObjectInterface,
      v3,
      *(_QWORD *)&v3->mValue.NValue);
    v3->pObjectInterface = 0i64;
  }
  v3->Type = 0;
}

// File Line: 81
// RVA: 0xA272F0
char __fastcall UFG::UITween::InvokeCallback(UFG::UITween *this, UFG::UITween::eCallbackType type)
{
  char *v2; // rdi
  unsigned int v3; // eax
  __int64 v4; // r14
  signed __int64 v5; // rax
  unsigned __int64 v6; // kr00_8
  unsigned __int8 v7; // cf
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  unsigned int v10; // ebx
  UFG::allocator::free_link *v11; // rbp
  UFG::allocator::free_link *v12; // rsi
  char v13; // di
  char result; // al
  void (__fastcall *v15)(void *); // rax
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-48h]

  v2 = (char *)this + 48 * type;
  if ( (v2[392] & 0x8F) == 11 )
  {
    if ( (v2[680] & 0x8F) == 9 )
    {
      v3 = (*(__int64 (__fastcall **)(_QWORD, _QWORD))(**((_QWORD **)v2 + 84) + 80i64))(
             *((_QWORD *)v2 + 84),
             *((_QWORD *)v2 + 86));
      v4 = v3;
      v6 = v3;
      v5 = 48i64 * v3;
      if ( !is_mul_ok(v6, 0x30ui64) )
        v5 = -1i64;
      v7 = __CFADD__(v5, 8i64);
      v8 = v5 + 8;
      if ( v7 )
        v8 = -1i64;
      v9 = UFG::qMalloc(v8, "UITween", 0i64);
      v10 = 0;
      if ( v9 )
      {
        LODWORD(v9->mNext) = v4;
        v11 = v9 + 1;
        pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
        `eh vector constructor iterator(
          &v9[1],
          0x30ui64,
          v4,
          (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      }
      else
      {
        v11 = 0i64;
      }
      if ( (_DWORD)v4 )
      {
        v12 = v11;
        do
        {
          (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, UFG::allocator::free_link *, void (__fastcall *)(void *)))(**((_QWORD **)v2 + 84) + 96i64))(
            *((_QWORD *)v2 + 84),
            *((_QWORD *)v2 + 86),
            v10++,
            v12,
            pDtor);
          v12 += 6;
        }
        while ( v10 < (unsigned int)v4 );
      }
      v13 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, UFG::allocator::free_link *, __int64, signed __int64))(**((_QWORD **)v2 + 48) + 56i64))(
              *((_QWORD *)v2 + 48),
              *((_QWORD *)v2 + 50),
              *((_QWORD *)v2 + 51),
              0i64,
              v11,
              v4,
              -2i64);
      if ( v11 )
      {
        `eh vector destructor iterator(
          v11,
          0x30ui64,
          (int)v11[-1].mNext,
          (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        operator delete[](&v11[-1]);
      }
    }
    else
    {
      v13 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, signed __int64))(**((_QWORD **)v2 + 48) + 56i64))(
              *((_QWORD *)v2 + 48),
              *((_QWORD *)v2 + 50),
              *((_QWORD *)v2 + 51),
              0i64,
              0i64,
              0i64,
              -2i64);
    }
    result = v13;
  }
  else
  {
    v15 = this->mCodeCallbacks[type];
    if ( v15 )
      v15(this->mCodeCallbackParams[type]);
    result = 0;
  }
  return result;
}

// File Line: 122
// RVA: 0xA28920
float __usercall UFG::UITween::Update@<xmm0>(UFG::UITween *this@<rcx>, float elapsed@<xmm1>, __m128 a3@<xmm0>)
{
  float v3; // xmm8_4
  UFG::UITween *v4; // rbx
  float v5; // xmm1_4
  float v7; // xmm8_4
  UFG::UITween::eTweenProperty v8; // esi
  signed __int64 v9; // rdi
  unsigned int v10; // eax
  UFG::qList<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint,1,0> *v11; // rsi
  signed int v12; // er14
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // rdi
  float v15; // xmm1_4
  float v16; // xmm1_4
  UFG::UITween::eTweenRoughnessTaper v17; // eax
  UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *v18; // rax
  UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *v19; // rcx
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rax
  float v22; // xmm8_4
  float v23; // xmm9_4
  signed int v24; // er15
  float *v25; // r14
  _DWORD *v26; // rdi
  signed __int64 v27; // rsi
  float v28; // xmm4_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  __m128 v31; // xmm5
  float v32; // xmm2_4
  UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *v33; // rax
  float v34; // xmm0_4
  __m128 v35; // xmm6
  float v36; // xmm7_4
  __m128 v37; // xmm1
  float v38; // xmm2_4
  signed int v39; // ecx
  signed int v40; // ecx
  float v41; // xmm2_4
  __int16 v42; // ax
  const char *v43; // rdx
  signed __int64 v44; // rsi
  int v45; // eax
  float v46; // xmm0_4
  int v47; // xmm0_4
  int v48; // xmm1_4
  int v49; // xmm0_4
  int v50; // xmm1_4
  int v51; // xmm0_4
  int v52; // xmm1_4
  __int64 duration[2]; // [rsp+20h] [rbp-B8h]
  Scaleform::GFx::Value pval; // [rsp+30h] [rbp-A8h]
  char v55; // [rsp+60h] [rbp-78h]
  float v56; // [rsp+68h] [rbp-70h]
  float v57; // [rsp+6Ch] [rbp-6Ch]
  __int64 v58; // [rsp+70h] [rbp-68h]
  float v59; // [rsp+78h] [rbp-60h]
  float v60; // [rsp+7Ch] [rbp-5Ch]
  float v61; // [rsp+80h] [rbp-58h]
  float v62; // [rsp+84h] [rbp-54h]
  float v63; // [rsp+88h] [rbp-50h]
  float v64; // [rsp+8Ch] [rbp-4Ch]
  float v65; // [rsp+90h] [rbp-48h]
  int v66; // [rsp+94h] [rbp-44h]
  double v67; // [rsp+98h] [rbp-40h]
  double v68; // [rsp+A0h] [rbp-38h]
  double v69; // [rsp+A8h] [rbp-30h]
  double v70; // [rsp+B0h] [rbp-28h]
  double v71; // [rsp+B8h] [rbp-20h]
  double v72; // [rsp+C0h] [rbp-18h]
  double v73; // [rsp+C8h] [rbp-10h]
  double v74; // [rsp+D0h] [rbp-8h]
  double v75; // [rsp+D8h] [rbp+0h]
  double v76; // [rsp+E0h] [rbp+8h]
  double v77; // [rsp+E8h] [rbp+10h]
  int Dst; // [rsp+F8h] [rbp+20h]
  int v79; // [rsp+10Ch] [rbp+34h]
  int v80; // [rsp+120h] [rbp+48h]
  int v81; // [rsp+128h] [rbp+50h]
  int v82; // [rsp+13Ch] [rbp+64h]
  int v83; // [rsp+150h] [rbp+78h]
  int v84; // [rsp+164h] [rbp+8Ch]
  __int16 v85; // [rsp+16Ch] [rbp+94h]
  UFG::qString v86; // [rsp+178h] [rbp+A0h]
  __int64 v87; // [rsp+1A0h] [rbp+C8h]
  UFG::allocator::free_link *v88; // [rsp+248h] [rbp+170h]

  v87 = -2i64;
  v3 = elapsed;
  v4 = this;
  if ( !this->mInited )
  {
    UFG::UITween::InvokeCallback(this, 0);
    v4->mInited = 1;
  }
  v5 = v4->mDelay;
  if ( v5 > 0.0 )
  {
    v4->mDelay = v5 - v3;
    return 0.0;
  }
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  if ( !(unsigned __int8)Scaleform::GFx::Movie::GetVariable(v4->mMovie, &pval, v4->mPath.mData) )
  {
    v4->mElapsed = v4->mDuration;
    v7 = *(float *)&FLOAT_1_0;
    goto LABEL_120;
  }
  if ( 0.0 == v4->mElapsed )
  {
    v8 = 0;
    v9 = (signed __int64)v4->mValues;
    do
    {
      if ( *(_BYTE *)(v9 + 8) )
      {
        if ( -1.0 == *(float *)v9 )
          *(float *)v9 = UFG::UITween::GetPropertyValue(v4, &pval, v8);
        if ( -1.0 == *(float *)(v9 + 4) )
          *(float *)(v9 + 4) = UFG::UITween::GetPropertyValue(v4, &pval, v8);
      }
      ++v8;
      v9 += 12i64;
    }
    while ( (signed int)v8 < 12 );
  }
  v10 = v4->mRoughnessNumPoints;
  if ( v10 )
  {
    v11 = &v4->mRoughnessPoints;
    if ( (UFG::qList<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint,1,0> *)v4->mRoughnessPoints.mNode.mNext == &v4->mRoughnessPoints )
    {
      v12 = 0;
      if ( v10 )
      {
        do
        {
          v13 = UFG::qMalloc(0x18ui64, "UITween::RoughnessPoint", 0i64);
          v14 = v13;
          v88 = v13;
          if ( v13 )
          {
            v13->mNext = v13;
            v13[1].mNext = v13;
          }
          else
          {
            v14 = 0i64;
          }
          if ( v4->mRoughnessRandomize )
            *(float *)&v14[2].mNext = UFG::qRandom(1.0, &UFG::qDefaultSeed);
          else
            *(float *)&v14[2].mNext = (float)((float)v12 + 1.0)
                                    / (float)((float)(signed int)v4->mRoughnessNumPoints + 1.0);
          a3 = (__m128)LODWORD(v4->mDuration);
          *((float *)&v14[2].mNext + 1) = UFG::UITween::GetValue(
                                            v4->mType,
                                            0.0,
                                            1.0,
                                            *(float *)&v14[2].mNext,
                                            v4->mDuration);
          if ( v4->mRoughnessRandomize )
          {
            a3 = (__m128)LODWORD(v4->mRoughnessRange);
            v15 = UFG::qRandom(a3.m128_f32[0] * 2.0, &UFG::qDefaultSeed) - v4->mRoughnessRange;
          }
          else
          {
            if ( v12 & 1 )
              v16 = *(float *)&FLOAT_1_0;
            else
              v16 = FLOAT_N1_0;
            v15 = v16 * v4->mRoughnessRange;
          }
          v17 = v4->mRoughnessTaper;
          if ( v17 == 1 )
          {
            v15 = v15 * *(float *)&v14[2].mNext;
          }
          else if ( v17 == 2 )
          {
            a3 = (__m128)(unsigned int)FLOAT_1_0;
            v15 = v15 * (float)(1.0 - *(float *)&v14[2].mNext);
          }
          *((float *)&v14[2].mNext + 1) = v15 + *((float *)&v14[2].mNext + 1);
          v18 = v4->mRoughnessPoints.mNode.mNext;
          if ( v18 == (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v11 )
          {
            v4->mRoughnessPoints.mNode.mNext = (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v14;
            v14->mNext = (UFG::allocator::free_link *)v11;
            v14[1].mNext = (UFG::allocator::free_link *)v18;
            v18->mPrev = (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v14;
          }
          else
          {
            v19 = v4->mRoughnessPoints.mNode.mNext;
            if ( v19 == (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v11 )
            {
LABEL_42:
              v21 = (UFG::allocator::free_link *)v11->mNode.mPrev;
              v21[1].mNext = v14;
              v14->mNext = v21;
              v14[1].mNext = (UFG::allocator::free_link *)v11;
              v11->mNode.mPrev = (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v14;
            }
            else
            {
              a3 = (__m128)LODWORD(v14[2].mNext);
              while ( a3.m128_f32[0] >= *(float *)&v19[1].mPrev )
              {
                v19 = v19->mNext;
                if ( v19 == (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v11 )
                  goto LABEL_42;
              }
              v20 = (UFG::allocator::free_link *)v19->mPrev;
              v20[1].mNext = v14;
              v14->mNext = v20;
              v14[1].mNext = (UFG::allocator::free_link *)v19;
              v19->mPrev = (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)v14;
            }
          }
          ++v12;
        }
        while ( v12 < v4->mRoughnessNumPoints );
      }
    }
  }
  if ( !v4->mStarted )
  {
    UFG::UITween::InvokeCallback(v4, ONSTART);
    v4->mStarted = 1;
  }
  v22 = v3 + v4->mElapsed;
  v4->mElapsed = v22;
  v23 = v4->mDuration;
  if ( v23 <= 0.0 || (v7 = v22 / v23, v7 >= 1.0) )
    v7 = *(float *)&FLOAT_1_0;
  v24 = 0;
  v25 = &v56;
  v26 = (_DWORD *)&v4->mValues[0].end;
  v27 = (signed __int64)&v4->mValues[0].end;
  do
  {
    if ( !*(_BYTE *)(v27 + 4) )
      goto LABEL_71;
    if ( v4->mRoughnessNumPoints )
    {
      v28 = 0.0;
      v29 = *(float *)(v27 - 4);
      v30 = *(float *)(v27 - 4);
      v31 = (__m128)(unsigned int)FLOAT_1_0;
      v32 = *(float *)v27;
      v33 = v4->mRoughnessPoints.mNode.mNext;
      if ( v33 != (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)&v4->mRoughnessPoints )
      {
        while ( 1 )
        {
          v34 = *(float *)&v33[1].mPrev;
          if ( v34 >= v7 )
            break;
          v28 = *(float *)&v33[1].mPrev;
          v30 = (float)((float)(v32 - v29) * *((float *)&v33[1].mPrev + 1)) + v29;
          v33 = v33->mNext;
          if ( v33 == (UFG::qNode<UFG::UITween::RoughnessPoint,UFG::UITween::RoughnessPoint> *)&v4->mRoughnessPoints )
            goto LABEL_57;
        }
        v31.m128_f32[0] = v34;
        v32 = (float)((float)(v32 - v29) * *((float *)&v33[1].mPrev + 1)) + v29;
      }
LABEL_57:
      v31.m128_f32[0] = v31.m128_f32[0] - v28;
      a3 = v31;
      a3.m128_f32[0] = UFG::UITween::GetValue(0, v30, v32, (float)(v7 - v28) / v31.m128_f32[0], v31.m128_f32[0] * v23);
      goto LABEL_70;
    }
    v35 = (__m128)LODWORD(v4->mStep);
    if ( v35.m128_f32[0] <= 0.0 || v7 >= 1.0 )
    {
      a3.m128_f32[0] = UFG::UITween::GetValue(v4->mType, *(float *)(v27 - 4), *(float *)v27, v7, v23);
LABEL_70:
      *v25 = a3.m128_f32[0];
      goto LABEL_71;
    }
    v36 = *(float *)(v27 - 4);
    a3.m128_f32[0] = UFG::UITween::GetValue(v4->mType, *(float *)(v27 - 4), *(float *)v27, v7, v23);
    v37 = a3;
    if ( v24 == 11 )
    {
      v38 = (float)((float)(v35.m128_f32[0] * 0.5) + a3.m128_f32[0]) / v35.m128_f32[0];
      v39 = (signed int)v38;
      if ( (signed int)v38 != 0x80000000 )
      {
        a3 = (__m128)COERCE_UNSIGNED_INT((float)v39);
        if ( a3.m128_f32[0] != v38 )
          v38 = (float)(v39 - (_mm_movemask_ps(_mm_unpacklo_ps(v35, v35)) & 1));
      }
      *v25 = v38 * v35.m128_f32[0];
    }
    else
    {
      a3 = v35;
      v37.m128_f32[0] = (float)((float)(v37.m128_f32[0] - v36) + (float)(v35.m128_f32[0] * 0.5)) / v35.m128_f32[0];
      v40 = (signed int)v37.m128_f32[0];
      if ( (signed int)v37.m128_f32[0] != 0x80000000 )
      {
        a3 = (__m128)COERCE_UNSIGNED_INT((float)v40);
        if ( a3.m128_f32[0] != v37.m128_f32[0] )
          v37.m128_f32[0] = (float)(v40 - (_mm_movemask_ps(_mm_unpacklo_ps(v37, v37)) & 1));
      }
      *v25 = (float)(v37.m128_f32[0] * v35.m128_f32[0]) + v36;
    }
LABEL_71:
    ++v24;
    v27 += 12i64;
    ++v25;
  }
  while ( v24 < 12 );
  memset(&Dst, 0, 0x30ui64);
  Dst = 1065353216;
  v79 = 1065353216;
  v80 = 1065353216;
  memset(&v81, 0, 0x40ui64);
  v81 = 1065353216;
  v82 = 1065353216;
  v83 = 1065353216;
  v84 = 1065353216;
  v85 = 0;
  if ( pval.pObjectInterface->vfptr->GetDisplayInfo(
         pval.pObjectInterface,
         *(void **)&pval.mValue.NValue,
         (Scaleform::GFx::Value::DisplayInfo *)&v67) )
  {
    if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(v4->mMovie) == 1 )
      v41 = *(float *)&FLOAT_1_0;
    else
      v41 = FLOAT_100_0;
    v42 = v85;
    if ( v4->mValues[0].isActive )
    {
      v42 = v85 | 1;
      v85 |= 1u;
      v67 = v56;
    }
    if ( v4->mValues[1].isActive )
    {
      v42 |= 2u;
      v85 = v42;
      v68 = v57;
    }
    if ( v4->mValues[2].isActive )
    {
      v42 |= 0x80u;
      v85 = v42;
      v73 = *(float *)&v58;
    }
    if ( v4->mValues[3].isActive )
    {
      v42 |= 0x20u;
      v85 = v42;
      v72 = (float)(*((float *)&v58 + 1) * v41);
    }
    if ( v4->mValues[4].isActive )
    {
      v42 |= 8u;
      v85 = v42;
      v70 = (float)(v59 * v41);
    }
    if ( v4->mValues[5].isActive )
    {
      v42 |= 0x10u;
      v85 = v42;
      v71 = (float)(v60 * v41);
    }
    if ( v4->mValues[6].isActive )
    {
      v42 |= 0x400u;
      v85 = v42;
      v76 = (float)(v61 * v41);
    }
    if ( v4->mValues[7].isActive )
    {
      v42 |= 4u;
      v85 = v42;
      v69 = v62;
    }
    if ( v4->mValues[8].isActive )
    {
      v42 |= 0x100u;
      v85 = v42;
      v74 = v63;
    }
    if ( v4->mValues[9].isActive )
    {
      v42 |= 0x200u;
      v85 = v42;
      v75 = v64;
    }
    if ( v4->mValues[10].isActive )
    {
      v85 = v42 | 0x800;
      v77 = v65;
    }
    pval.pObjectInterface->vfptr->SetDisplayInfo(
      pval.pObjectInterface,
      *(void **)&pval.mValue.NValue,
      (Scaleform::GFx::Value::DisplayInfo *)&v67);
    if ( v4->mValues[11].isActive )
    {
      UFG::qString::qString(&v86);
      if ( v4->mTextFormat.mLength )
        v43 = v4->mTextFormat.mData;
      else
        v43 = "%.0f";
      UFG::qString::Format(&v86, v43, v66);
      v58 = 0i64;
      LODWORD(v59) = 6;
      pval.DataAux = (unsigned __int64)v86.mData;
      LOBYTE(duration[0]) = (pval.Type & 0x8F) == 10;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, _QWORD, const char *, char *, __int64))&pval.pObjectInterface->vfptr->gap8[32])(
        pval.pObjectInterface,
        *(_QWORD *)&pval.mValue.NValue,
        "htmlText",
        &v55,
        duration[0]);
      if ( (LODWORD(v59) >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, unsigned __int64))(*(_QWORD *)v58 + 16i64))(v58, &v55, pval.DataAux);
        v58 = 0i64;
      }
      v59 = 0.0;
      UFG::qString::~qString(&v86);
    }
  }
  v44 = 2i64;
  UFG::UITween::InvokeCallback(v4, ONUPDATE);
  if ( v4->mLoopType )
  {
    if ( v7 >= 1.0 )
    {
      if ( v4->mOscillating )
        UFG::UITween::InvokeCallback(v4, ONOSCILLATECOMPLETE);
      v45 = v4->mLoopCount;
      if ( v45 > 0 )
        v4->mLoopCount = v45 - 1;
      if ( v4->mLoopCount )
      {
        UFG::UITween::InvokeCallback(v4, ONLOOP);
        v4->mElapsed = 0.0;
        v46 = v4->mDuration;
        if ( v46 <= 0.0 || (v7 = 0.0 / v46, (float)(0.0 / v46) >= 1.0) )
          v7 = *(float *)&FLOAT_1_0;
        v4->mDelay = v4->mLoopDelay;
        if ( v4->mLoopType == 1 )
        {
          do
          {
            v47 = *(v26 - 1);
            *(v26 - 1) = *v26;
            *v26 = v47;
            v48 = v26[2];
            v26[2] = v26[3];
            v26[3] = v48;
            v49 = v26[5];
            v26[5] = v26[6];
            v26[6] = v49;
            v50 = v26[8];
            v26[8] = v26[9];
            v26[9] = v50;
            v51 = v26[11];
            v26[11] = v26[12];
            v26[12] = v51;
            v52 = v26[14];
            v26[14] = v26[15];
            v26[15] = v52;
            v26 += 18;
            --v44;
          }
          while ( v44 );
          v4->mOscillating = v4->mOscillating == 0;
        }
      }
      goto LABEL_118;
    }
  }
  else
  {
LABEL_118:
    if ( v7 >= 1.0 )
      UFG::UITween::InvokeCallback(v4, ONCOMPLETE);
  }
LABEL_120:
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v7;
}

// File Line: 393
// RVA: 0xA26500
float __fastcall UFG::UITween::GetValue(UFG::UITween::eTweenType type, float start, float endVal, float progress, float duration)
{
  __m128 v5; // xmm6
  float v6; // xmm8_4
  float v7; // xmm9_4
  float v8; // xmm4_4
  float v9; // xmm7_4
  float result; // xmm0_4
  float v11; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm4_4
  float v16; // xmm8_4
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm4_4
  bool v20; // cf
  float v21; // xmm4_4
  __m128 v22; // xmm0
  float v23; // xmm7_4
  float v24; // xmm4_4
  __m128 v25; // xmm0
  float v26; // xmm1_4
  float v27; // xmm7_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm7_4

  v5 = (__m128)(unsigned int)FLOAT_1_0;
  v6 = progress;
  v7 = start;
  v8 = progress * duration;
  v9 = endVal - start;
  if ( progress >= 1.0 )
    return endVal;
  switch ( type )
  {
    case 0:
      return (float)(v9 * progress) + start;
    case 1:
      v11 = cosf((float)(v8 / duration) * 1.5707964);
      return (float)((float)(v5.m128_f32[0] - v11) * v9) + start;
    case 2:
      return (float)(sinf((float)(v8 / duration) * 1.5707964) * v9) + start;
    case 3:
      return (float)((float)(1.0 - cosf((float)(v8 * 3.1415927) / duration)) * (float)(v9 * 0.5)) + start;
    case 4:
LABEL_18:
      v9 = v9 * progress;
      return (float)(v9 * progress) + start;
    case 5:
      v9 = (float)(v9 * -1.0) * progress;
      v6 = progress - 2.0;
      return (float)(v9 * v6) + start;
    case 6:
      if ( progress < 0.5 )
      {
        v9 = v9 * 2.0;
        goto LABEL_18;
      }
      v13 = (float)((float)((float)(progress * 2.0) - 1.0) * (float)((float)(progress * 2.0) - 3.0)) - 1.0;
      return (float)(v13 * (float)(v9 * -0.5)) + v7;
    case 7:
      v14 = FLOAT_3_0;
      return (float)(powf(v8 / duration, v14) * v9) + v7;
    case 8:
      return (float)((float)(powf((float)(v8 / duration) - 1.0, 3.0) + 1.0) * v9) + start;
    case 9:
      v15 = v8 / (float)(duration * 0.5);
      if ( v15 >= 1.0 )
        result = (float)((float)(powf(v15 - 2.0, 3.0) + 2.0) * (float)(v9 * 0.5)) + start;
      else
        result = (float)(powf(v15, 3.0) * (float)(v9 * 0.5)) + start;
      return result;
    case 10:
      v14 = FLOAT_4_0;
      return (float)(powf(v8 / duration, v14) * v9) + v7;
    case 11:
      return COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(powf((float)(v8 / duration) - 1.0, 4.0) - 1.0) * v9) ^ _xmm[0])
           + start;
    case 12:
      v16 = FLOAT_0_5;
      v17 = FLOAT_4_0;
      v18 = v8 / (float)(duration * 0.5);
      if ( v18 >= 1.0 )
      {
        v13 = powf(v18 - 2.0, 4.0) - 2.0;
        return (float)(v13 * (float)(v9 * -0.5)) + v7;
      }
      return (float)(powf(v18, v17) * (float)(v9 * v16)) + v7;
    case 13:
      return (float)(powf(v8 / duration, 5.0) * v9) + start;
    case 14:
      return (float)((float)(powf((float)(v8 / duration) - 1.0, 5.0) + 1.0) * v9) + start;
    case 15:
      v16 = FLOAT_0_5;
      v17 = FLOAT_5_0;
      v18 = v8 / (float)(duration * 0.5);
      if ( v18 >= 1.0 )
        return (float)((float)(powf(v18 - 2.0, 5.0) + 2.0) * (float)(v9 * 0.5)) + v7;
      return (float)(powf(v18, v17) * (float)(v9 * v16)) + v7;
    case 16:
      return (float)(powf(2.0, (float)((float)(v8 / duration) - 1.0) * 10.0) * v9) + start;
    case 17:
      v11 = powf(2.0, (float)(v8 * -10.0) / duration);
      return (float)((float)(v5.m128_f32[0] - v11) * v9) + start;
  }
  if ( type != 18 )
  {
    switch ( type )
    {
      case 19:
        v22 = (__m128)(unsigned int)FLOAT_1_0;
        v22.m128_f32[0] = 1.0 - (float)((float)(v8 / duration) * (float)(v8 / duration));
        return (float)((float)(1.0 - COERCE_FLOAT(_mm_sqrt_ps(v22))) * v9) + start;
      case 20:
        v5.m128_f32[0] = 1.0 - (float)((float)((float)(v8 / duration) - 1.0) * (float)((float)(v8 / duration) - 1.0));
        return (float)(COERCE_FLOAT(_mm_sqrt_ps(v5)) * v9) + start;
      case 21:
        v23 = v9 * 0.5;
        v24 = v8 / (float)(duration * 0.5);
        v25 = (__m128)(unsigned int)FLOAT_1_0;
        if ( v24 >= 1.0 )
        {
          v25.m128_f32[0] = 1.0 - (float)((float)(v24 - 2.0) * (float)(v24 - 2.0));
          result = (float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v25)) + 1.0) * v23) + start;
        }
        else
        {
          v25.m128_f32[0] = 1.0 - (float)(v24 * v24);
          result = (float)((float)(1.0 - COERCE_FLOAT(_mm_sqrt_ps(v25))) * v23) + start;
        }
        return result;
      case 22:
        return (float)((float)((float)(v9 * progress) * progress) * (float)((float)(progress * 2.70158) - 1.70158))
             + start;
      case 23:
        return (float)((float)((float)((float)((float)((float)(progress - 1.0) * 2.70158) + 1.70158)
                                     * (float)((float)(progress - 1.0) * (float)(progress - 1.0)))
                             + 1.0)
                     * v9)
             + start;
      case 24:
        v26 = progress * 2.0;
        v27 = v9 * 0.5;
        if ( progress >= 0.5 )
          result = (float)((float)((float)((float)((float)((float)(v26 + -2.0) * 3.5949094) + 2.5949094)
                                         * (float)((float)(v26 + -2.0) * (float)(v26 + -2.0)))
                                 + 2.0)
                         * v27)
                 + v7;
        else
          result = (float)((float)((float)((float)(v26 * 3.5949094) - 2.5949094) * (float)(v26 * v26)) * v27) + v7;
        return result;
    }
    if ( (unsigned int)(type - 25) <= 2 )
    {
      v30 = start;
      v31 = v6;
      if ( type == 25 )
      {
        v30 = 0.0;
        v31 = 1.0 - v6;
      }
      else if ( type == 27 )
      {
        v30 = 0.0;
        if ( v6 >= 0.5 )
          v31 = (float)(v6 * 2.0) - 1.0;
        else
          v31 = 1.0 - (float)(v6 * 2.0);
      }
      if ( v31 >= 0.36363637 )
      {
        if ( v31 >= 0.72727275 )
        {
          if ( v31 >= 0.9090909090909091 )
            v33 = (float)((float)((float)(v31 + -0.95454544) * 7.5625) * (float)(v31 + -0.95454544)) + 0.984375;
          else
            v33 = (float)((float)((float)(v31 + -0.81818181) * 7.5625) * (float)(v31 + -0.81818181)) + 0.9375;
        }
        else
        {
          v33 = (float)((float)((float)(v31 + -0.54545456) * 7.5625) * (float)(v31 + -0.54545456)) + 0.75;
        }
        v32 = v33 * v9;
      }
      else
      {
        v32 = (float)((float)(v9 * 7.5625) * v31) * v31;
      }
      result = v32 + v30;
      if ( type == 25 )
      {
        v34 = v9 + v7;
      }
      else
      {
        if ( type != 27 )
          return result;
        result = result * 0.5;
        v34 = (float)(v9 * 0.5) + v7;
        if ( v6 >= 0.5 )
          return v34 + result;
      }
      return v34 - result;
    }
    switch ( type )
    {
      case 28:
        v6 = progress - 1.0;
        v28 = powf(2.0, (float)(progress - 1.0) * 10.0);
        return start - (float)((float)(v28 * v9) * sinf((float)((float)(v6 - 0.075000003) * 6.2831855) * 3.3333333));
      case 29:
        v29 = powf(2.0, progress * -10.0) * v9;
        break;
      case 30:
        v6 = (float)(progress * 2.0) - 1.0;
        if ( progress < 0.5 )
        {
          v28 = powf(2.0, v6 * 10.0);
          v9 = v9 * 0.5;
          return start - (float)((float)(v28 * v9) * sinf((float)((float)(v6 - 0.075000003) * 6.2831855) * 3.3333333));
        }
        v29 = powf(2.0, v6 * -10.0) * (float)(v9 * 0.5);
        break;
      default:
        return (float)(v9 * v6) + start;
    }
    return (float)(v29 * sinf((float)((float)(v6 - 0.075000003) * 6.2831855) * 3.3333333)) + (float)(v9 + start);
  }
  v19 = v8 / (float)(duration * 0.5);
  v20 = v19 < 1.0;
  v21 = v19 - 1.0;
  if ( !v20 )
  {
    v5.m128_f32[0] = FLOAT_2_0;
    v11 = powf(2.0, v21 * -10.0);
    v9 = v9 * 0.5;
    return (float)((float)(v5.m128_f32[0] - v11) * v9) + start;
  }
  return (float)(powf(2.0, v21 * 10.0) * (float)(v9 * 0.5)) + start;
}f ( !v20 )
  {
    v5.m128_f32[0] = FLOAT_2_0;
    v11 = powf(2.0, v21 * -10.0);
    v9 = v9 * 0.5

// File Line: 647
// RVA: 0xA26290
float __fastcall UFG::UITween::GetPropertyValue(UFG::UITween *this, Scaleform::GFx::Value *movieClip, UFG::UITween::eTweenProperty prop)
{
  Scaleform::GFx::Value *v3; // rbx
  UFG::UITween::eTweenProperty v4; // edi
  UFG::UITween *v5; // rsi
  float v6; // xmm6_4
  Scaleform::GFx::Value::ObjectInterface *v7; // rcx
  long double v8; // rdx
  float result; // xmm0_4
  double v10; // [rsp+20h] [rbp-F8h]
  double v11; // [rsp+28h] [rbp-F0h]
  double v12; // [rsp+30h] [rbp-E8h]
  double v13; // [rsp+38h] [rbp-E0h]
  double v14; // [rsp+40h] [rbp-D8h]
  double v15; // [rsp+48h] [rbp-D0h]
  double v16; // [rsp+50h] [rbp-C8h]
  double v17; // [rsp+58h] [rbp-C0h]
  double v18; // [rsp+60h] [rbp-B8h]
  double v19; // [rsp+68h] [rbp-B0h]
  double v20; // [rsp+70h] [rbp-A8h]
  int v21; // [rsp+80h] [rbp-98h]
  int v22; // [rsp+94h] [rbp-84h]
  int v23; // [rsp+A8h] [rbp-70h]
  int Dst; // [rsp+B0h] [rbp-68h]
  int v25; // [rsp+C4h] [rbp-54h]
  int v26; // [rsp+D8h] [rbp-40h]
  int v27; // [rsp+ECh] [rbp-2Ch]
  __int16 v28; // [rsp+F4h] [rbp-24h]

  v3 = movieClip;
  v4 = prop;
  v5 = this;
  memset(&v21, 0, 0x30ui64);
  v6 = *(float *)&FLOAT_1_0;
  v21 = 1065353216;
  v22 = 1065353216;
  v23 = 1065353216;
  memset(&Dst, 0, 0x40ui64);
  v7 = v3->pObjectInterface;
  v8 = v3->mValue.NValue;
  Dst = 1065353216;
  v25 = 1065353216;
  v26 = 1065353216;
  v27 = 1065353216;
  v28 = 0;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Value::ObjectInterface *, long double, double *))v7->vfptr->GetDisplayInfo)(
          v7,
          COERCE_LONG_DOUBLE(*(_QWORD *)&v8),
          &v10) )
    return FLOAT_N1_0;
  if ( (unsigned int)Scaleform::GFx::Movie::GetAVMVersion(v5->mMovie) != 1 )
    v6 = FLOAT_100_0;
  switch ( v4 )
  {
    case 0:
      result = v10;
      break;
    case 1:
      result = v11;
      break;
    case 2:
      result = v16;
      break;
    case 3:
      result = v15 / v6;
      break;
    case 4:
      result = v13 / v6;
      break;
    case 5:
      result = v14 / v6;
      break;
    case 6:
      result = v19;
      break;
    case 7:
      result = v12;
      break;
    case 8:
      result = v17;
      break;
    case 9:
      result = v18;
      break;
    case 10:
      result = v20;
      break;
    case 11:
      result = 0.0;
      break;
    default:
      return FLOAT_N1_0;
  }
  return result;
}

