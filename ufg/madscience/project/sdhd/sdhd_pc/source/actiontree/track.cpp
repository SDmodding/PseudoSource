// File Line: 39
// RVA: 0x1480730
__int64 dynamic_initializer_for__TrackGroup::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TrackGroup", 0xFFFFFFFF);
  TrackGroup::sClassNameUID = result;
  return result;
}

// File Line: 48
// RVA: 0x26D1A0
Expression::IMemberMap *__fastcall TrackGroup::CreateClone(TrackGroup *this)
{
  char *v2; // r15
  __int64 v3; // r12
  BinPtrArray<ITrack,1,0> *v4; // rsi
  char *v5; // r15
  __int64 v6; // rcx
  __int64 v7; // rdi
  __int64 mCount; // r14
  unsigned int v9; // ebx
  unsigned int v10; // edx
  __int64 mOffset; // rax
  char *v12; // rcx
  __int64 *v13; // rdx
  char *v15; // [rsp+70h] [rbp+8h]

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "TrackGroup::CreateClone", 0i64, 1u);
  v15 = v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v2 + 1) = 0i64;
    *(_QWORD *)v2 = &TrackGroup::`vftable;
    *((_DWORD *)v2 + 4) = 0;
    *((_QWORD *)v2 + 3) = 0i64;
  }
  else
  {
    v2 = 0i64;
    v15 = 0i64;
  }
  v3 = 0i64;
  if ( (this->mTracks.mCount & 0x7FFFFFFF) == 0 )
    return (Expression::IMemberMap *)v2;
  v4 = (BinPtrArray<ITrack,1,0> *)(v2 + 16);
  v5 = (char *)&this->mTracks.mData + this->mTracks.mData.mOffset;
  do
  {
    v6 = (__int64)&v5[8 * v3 + *(_QWORD *)&v5[8 * v3]];
    v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6);
    mCount = (unsigned int)v4->mCount;
    LODWORD(mCount) = mCount & 0x7FFFFFFF;
    v9 = mCount + 1;
    if ( (int)mCount + 1 > (unsigned int)mCount )
    {
      v10 = 1;
      if ( (_DWORD)mCount )
        v10 = 2 * mCount;
      for ( ; v10 < v9; v10 *= 2 )
        ;
      if ( v10 - v9 > 0x10000 )
        v10 = mCount + 65537;
      BinPtrArray<Condition,1,0>::Reallocate(v4, v10, "BinPtrArray.Add");
    }
    v4->mCount &= 0x80000000;
    v4->mCount |= v9 & 0x7FFFFFFF;
    mOffset = v4->mData.mOffset;
    if ( mOffset )
      v12 = (char *)&v4->mData + mOffset;
    else
      v12 = 0i64;
    v13 = (__int64 *)&v12[8 * mCount];
    if ( v7 )
      v7 -= (__int64)v13;
    *v13 = v7;
    v3 = (unsigned int)(v3 + 1);
  }
  while ( (unsigned int)v3 < (this->mTracks.mCount & 0x7FFFFFFFu) );
  return (Expression::IMemberMap *)v15;
}

// File Line: 80
// RVA: 0x2725C0
void __fastcall TrackGroup::Serialize(TrackGroup *this, IActionTreeSerializer *serializer)
{
  unsigned int v4; // ebx
  char *v5; // r14
  char *v6; // rcx
  char *v7; // rdi
  const char *v8; // rax

  v4 = 0;
  v5 = (char *)&this->mTracks.mData + this->mTracks.mData.mOffset;
  if ( (this->mTracks.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v6 = &v5[8 * v4];
      v7 = &v6[*(_QWORD *)v6];
      if ( v7 )
      {
        v8 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v7 + 32i64))(&v6[*(_QWORD *)v6]);
        serializer->vfptr->_PushObjectToSerialize(
          serializer,
          v7,
          1u,
          (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
          v8,
          PRIORITY_MEDIUM,
          0,
          0i64,
          -1u,
          0i64);
      }
      ++v4;
    }
    while ( v4 < (this->mTracks.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 132
// RVA: 0x268C70
void __fastcall ITrack::ITrack(ITrack *this, unsigned int class_name_uid)
{
  ExpressionParameterFloat *p_mMasterRate; // rbx

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  this->m_TrackClassNameUID = class_name_uid;
  this->mMaster = 0;
  p_mMasterRate = &this->mMasterRate;
  this->mMasterRate.text.mOffset = 1i64;
  BinString::Set(&this->mMasterRate.text, &customCaption);
  p_mMasterRate->expression.mOffset = 0i64;
  p_mMasterRate->value = 1.0;
  this->mTimeBegin = 0.0;
  this->mTimeEnd = -1.0;
  *(_WORD *)&this->mBreakPoint = 0;
}

// File Line: 171
// RVA: 0x268D00
void __fastcall ITrack::ITrack(ITrack *this, MemImageLoadFlag flag)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  *(_WORD *)&this->mBreakPoint = 0;
}

