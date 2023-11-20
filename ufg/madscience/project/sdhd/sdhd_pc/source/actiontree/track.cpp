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
  TrackGroup *v1; // r13
  char *v2; // r15
  __int64 v3; // r12
  BinPtrArray<ITrack,1,0> *v4; // rsi
  signed __int64 v5; // r15
  __int64 v6; // rdi
  __int64 v7; // r14
  unsigned int v8; // ebx
  unsigned int v9; // edx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  signed __int64 v12; // rdx
  char *v14; // [rsp+70h] [rbp+8h]

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "TrackGroup::CreateClone", 0i64, 1u);
  v14 = v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &Expression::IMemberMap::`vftable';
    *((_QWORD *)v2 + 1) = 0i64;
    *(_QWORD *)v2 = &TrackGroup::`vftable';
    *((_DWORD *)v2 + 4) = 0;
    *((_QWORD *)v2 + 3) = 0i64;
  }
  else
  {
    v2 = 0i64;
    v14 = 0i64;
  }
  v3 = 0i64;
  if ( !(v1->mTracks.mCount & 0x7FFFFFFF) )
    return (Expression::IMemberMap *)v2;
  v4 = (BinPtrArray<ITrack,1,0> *)(v2 + 16);
  v5 = (signed __int64)&v1->mTracks.mData + v1->mTracks.mData.mOffset;
  do
  {
    v6 = (*(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v5 + 8 * v3) + v5 + 8 * v3) + 16i64))();
    v7 = (unsigned int)v4->mCount;
    LODWORD(v7) = v7 & 0x7FFFFFFF;
    v8 = v7 + 1;
    if ( (signed int)v7 + 1 > (unsigned int)v7 )
    {
      v9 = 1;
      if ( (_DWORD)v7 )
        v9 = 2 * v7;
      for ( ; v9 < v8; v9 *= 2 )
        ;
      if ( v9 - v8 > 0x10000 )
        v9 = v7 + 65537;
      BinPtrArray<Condition,1,0>::Reallocate(v4, v9, "BinPtrArray.Add");
    }
    v4->mCount &= 0x80000000;
    v4->mCount |= v8 & 0x7FFFFFFF;
    v10 = v4->mData.mOffset;
    if ( v10 )
      v11 = (signed __int64)&v4->mData + v10;
    else
      v11 = 0i64;
    v12 = v11 + 8 * v7;
    if ( v6 )
      v6 -= v12;
    *(_QWORD *)v12 = v6;
    v3 = (unsigned int)(v3 + 1);
  }
  while ( (unsigned int)v3 < (v1->mTracks.mCount & 0x7FFFFFFFu) );
  return (Expression::IMemberMap *)v14;
}

// File Line: 80
// RVA: 0x2725C0
void __fastcall TrackGroup::Serialize(TrackGroup *this, IActionTreeSerializer *serializer)
{
  IActionTreeSerializer *v2; // r15
  TrackGroup *v3; // rsi
  unsigned int v4; // ebx
  char *v5; // r14
  char *v6; // rcx
  char *v7; // rdi
  __int64 v8; // rax
  __int64 v9; // [rsp+28h] [rbp-40h]
  __int64 v10; // [rsp+30h] [rbp-38h]
  __int64 v11; // [rsp+40h] [rbp-28h]

  v2 = serializer;
  v3 = this;
  v4 = 0;
  v5 = (char *)&this->mTracks.mData + this->mTracks.mData.mOffset;
  if ( this->mTracks.mCount & 0x7FFFFFFF )
  {
    do
    {
      v6 = &v5[8 * v4];
      v7 = &v6[*(_QWORD *)v6];
      if ( v7 )
      {
        v8 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v7 + 32i64))(&v6[*(_QWORD *)v6]);
        LODWORD(v11) = -1;
        LODWORD(v10) = 0;
        LODWORD(v9) = 1;
        v2->vfptr->_PushObjectToSerialize(
          v2,
          v7,
          1u,
          (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
          (const char *)v8,
          (QUEUE_PRIORITY)v9,
          v10,
          0i64,
          v11,
          0i64);
      }
      ++v4;
    }
    while ( v4 < (v3->mTracks.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 132
// RVA: 0x268C70
void __fastcall ITrack::ITrack(ITrack *this, unsigned int class_name_uid)
{
  ITrack *v2; // rdi
  ExpressionParameterFloat *v3; // [rsp+50h] [rbp+18h]

  v2 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  this->m_TrackClassNameUID = class_name_uid;
  this->mMaster = 0;
  v3 = &this->mMasterRate;
  v3->text.mOffset = 1i64;
  BinString::Set(&this->mMasterRate.text, &customWorldMapCaption);
  v3->expression.mOffset = 0i64;
  v3->value = 1.0;
  v2->mTimeBegin = 0.0;
  v2->mTimeEnd = -1.0;
  *(_WORD *)&v2->mBreakPoint = 0;
}

// File Line: 171
// RVA: 0x268D00
void __fastcall ITrack::ITrack(ITrack *this, MemImageLoadFlag flag)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  *(_WORD *)&this->mBreakPoint = 0;
}

