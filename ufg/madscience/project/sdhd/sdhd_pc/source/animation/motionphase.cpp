// File Line: 21
// RVA: 0x14BCBF0
__int64 dynamic_initializer_for__animPhaseMarkEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&animPhaseMarkEnum, gAnimationPhaseMarkStringList, 3, 0i64);
  return atexit(dynamic_atexit_destructor_for__animPhaseMarkEnum__);
}

// File Line: 23
// RVA: 0x14B9870
__int64 dynamic_initializer_for__MotionPhase2::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionPhase2", 0xFFFFFFFF);
  MotionPhase2::sClassNameUID = result;
  return result;
}

// File Line: 44
// RVA: 0x39E1D0
void __fastcall MotionPhase2::MotionPhase2(MotionPhase2 *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable';
  *(_QWORD *)&this->mPhaseMark.mValue = 0i64;
  *(_QWORD *)&this->mPhase = 0i64;
}

// File Line: 50
// RVA: 0x39E190
void __fastcall MotionPhase2::MotionPhase2(MotionPhase2 *this, MemImageLoadFlag flag)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionPhase2::`vftable';
}

// File Line: 95
// RVA: 0x14BF290
const char *dynamic_initializer_for__sAnimMotionKeyFactoryList__()
{
  const char *result; // rax

  sAnimMotionKeyFactoryList[0].mClassName = MotionKeyFootStepLeft::sClassName;
  result = MotionKeyFootStepRight::sClassName;
  sAnimMotionKeyFactoryList[1].mClassName = MotionKeyFootStepRight::sClassName;
  return result;
}

// File Line: 101
// RVA: 0x14BCDF0
__int64 dynamic_initializer_for__gAnimMotionKeyFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gAnimMotionKeyFactory,
    sAnimMotionKeyFactoryList,
    sAnimMotionKeyFactoryListNum);
  return atexit(dynamic_atexit_destructor_for__gAnimMotionKeyFactory__);
}

// File Line: 106
// RVA: 0x14B9890
__int64 dynamic_initializer_for__MotionPhaseChannel::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionPhaseChannel", 0xFFFFFFFF);
  MotionPhaseChannel::sClassNameUID = result;
  return result;
}

// File Line: 128
// RVA: 0x3AFB00
void __fastcall MotionPhaseChannel::Sort(MotionPhaseChannel *this)
{
  signed __int64 v1; // rbx
  MotionPhaseChannel *v2; // r11
  unsigned int v3; // edi
  __int64 v4; // r8
  __int64 v5; // rax
  __int64 v6; // r9
  signed __int64 v7; // rcx
  signed __int64 v8; // rdx
  __int64 v9; // rcx
  signed __int64 v10; // r8
  signed int v11; // er9
  __int64 v12; // r10
  signed int v13; // edx
  signed __int64 v14; // rcx
  float v15; // xmm0_4
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // rax
  float v20; // xmm0_4
  __int64 v21; // rax
  __int64 v22; // rdx
  __int64 v23; // r9
  __int64 v24; // rax
  __int64 v25; // rcx
  __int64 v26; // r8
  __int64 v27; // [rsp+0h] [rbp-650h]
  __int64 v28; // [rsp+8h] [rbp-648h]
  __int64 v29[200]; // [rsp+10h] [rbp-640h]

  v1 = (unsigned int)this->mKeys.mCount;
  v2 = this;
  v3 = this->mKeys.mCount & 0x7FFFFFFF;
  if ( v3 )
  {
    v4 = this->mKeys.mData.mOffset;
    v5 = 0i64;
    v6 = v3;
    do
    {
      if ( v4 )
        v7 = (signed __int64)&v2->mKeys.mData + v4;
      else
        v7 = 0i64;
      v8 = v5 + v7;
      v9 = *(_QWORD *)(v5 + v7);
      if ( v9 )
        v9 += v8;
      *(__int64 *)((char *)&v28 + v5) = v9;
      v5 += 8i64;
      --v6;
    }
    while ( v6 );
  }
  v10 = 1i64;
  LODWORD(v1) = v1 & 0x7FFFFFFF;
  if ( v1 > 1 )
  {
    v11 = 0;
    do
    {
      v12 = *(&v28 + v10);
      v13 = v11;
      v14 = v10 - 1;
      if ( v11 >= 0 )
      {
        if ( v11 + 1 < 4 )
        {
LABEL_19:
          if ( v13 >= 0 )
          {
            v20 = *(float *)(v12 + 16);
            do
            {
              v21 = *(&v28 + v14);
              if ( v20 >= *(float *)(v21 + 16) )
                break;
              v29[v14--] = v21;
              --v13;
            }
            while ( v13 >= 0 );
          }
        }
        else
        {
          v15 = *(float *)(v12 + 16);
          while ( 1 )
          {
            v16 = *(&v28 + v14);
            if ( v15 >= *(float *)(v16 + 16) )
              break;
            v29[v14] = v16;
            v17 = *(&v27 + v14--);
            if ( v15 >= *(float *)(v17 + 16) )
              break;
            v29[v14] = v17;
            v18 = *(&v27 + v14--);
            if ( v15 >= *(float *)(v18 + 16) )
              break;
            v29[v14] = v18;
            v19 = *(&v27 + v14--);
            if ( v15 >= *(float *)(v19 + 16) )
              break;
            v13 -= 4;
            v29[v14--] = v19;
            if ( v13 < 3 )
              goto LABEL_19;
          }
        }
      }
      ++v10;
      ++v11;
      v29[v14] = v12;
    }
    while ( v10 < v1 );
  }
  v22 = 0i64;
  if ( v3 )
  {
    v23 = 0i64;
    do
    {
      v24 = v2->mKeys.mData.mOffset;
      v25 = *(&v28 + v22);
      if ( v24 )
        v24 += (__int64)&v2->mKeys.mData;
      v26 = v23 + v24;
      if ( v25 )
        v25 -= v26;
      *(_QWORD *)v26 = v25;
      v22 = (unsigned int)(v22 + 1);
      v23 += 8i64;
    }
    while ( (unsigned int)v22 < (v2->mKeys.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 164
// RVA: 0x14B9830
__int64 dynamic_initializer_for__MotionKeyFootStepLeft::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionKeyFootStepLeft", 0xFFFFFFFF);
  MotionKeyFootStepLeft::sClassNameUID = result;
  return result;
}

// File Line: 176
// RVA: 0x14B9850
__int64 dynamic_initializer_for__MotionKeyFootStepRight::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotionKeyFootStepRight", 0xFFFFFFFF);
  MotionKeyFootStepRight::sClassNameUID = result;
  return result;
}

