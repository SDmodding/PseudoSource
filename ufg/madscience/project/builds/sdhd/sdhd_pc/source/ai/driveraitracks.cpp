// File Line: 29
// RVA: 0x14ADDA0
__int64 dynamic_initializer_for__DriverPathfindToTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DriverPathfindToTargetTrack", 0xFFFFFFFF);
  DriverPathfindToTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 37
// RVA: 0x32DF50
void __fastcall DriverPathfindToTargetTrack::DriverPathfindToTargetTrack(DriverPathfindToTargetTrack *this)
{
  DriverPathfindToTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DriverPathfindToTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DriverPathfindToTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DriverPathfindToTargetTrack::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = 22;
  v1->m_ToleranceRadius = 20.0;
}

// File Line: 44
// RVA: 0x336460
void __fastcall DriverPathfindToTargetTrack::~DriverPathfindToTargetTrack(DriverPathfindToTargetTrack *this)
{
  DriverPathfindToTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverPathfindToTargetTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 60
// RVA: 0x14ADD80
__int64 dynamic_initializer_for__DriverFollowTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DriverFollowTargetTrack", 0xFFFFFFFF);
  DriverFollowTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 66
// RVA: 0x32DE50
void __fastcall DriverFollowTargetTrack::DriverFollowTargetTrack(DriverFollowTargetTrack *this)
{
  DriverFollowTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DriverFollowTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DriverFollowTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DriverFollowTargetTrack::`vftable';
  v1->m_TargetType.mValue = 22;
}

// File Line: 71
// RVA: 0x3363F0
void __fastcall DriverFollowTargetTrack::~DriverFollowTargetTrack(DriverFollowTargetTrack *this)
{
  DriverFollowTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverFollowTargetTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 86
// RVA: 0x14ADCE0
__int64 dynamic_initializer_for__DriverChaseTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DriverChaseTargetTrack", 0xFFFFFFFF);
  DriverChaseTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 92
// RVA: 0x32DCB0
void __fastcall DriverChaseTargetTrack::DriverChaseTargetTrack(DriverChaseTargetTrack *this)
{
  DriverChaseTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DriverChaseTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DriverChaseTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DriverChaseTargetTrack::`vftable';
  v1->m_TargetType.mValue = 22;
}

// File Line: 97
// RVA: 0x336280
void __fastcall DriverChaseTargetTrack::~DriverChaseTargetTrack(DriverChaseTargetTrack *this)
{
  DriverChaseTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverChaseTargetTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 111
// RVA: 0x14ADDE0
__int64 dynamic_initializer_for__DriverWanderTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DriverWanderTrack", 0xFFFFFFFF);
  DriverWanderTrack::sClassNameUID = result;
  return result;
}

// File Line: 116
// RVA: 0x32E0A0
void __fastcall DriverWanderTrack::DriverWanderTrack(DriverWanderTrack *this)
{
  DriverWanderTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DriverWanderTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DriverWanderTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DriverWanderTrack::`vftable';
}

// File Line: 120
// RVA: 0x336660
void __fastcall DriverWanderTrack::~DriverWanderTrack(DriverWanderTrack *this)
{
  DriverWanderTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverWanderTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 133
// RVA: 0x14ADDC0
__int64 dynamic_initializer_for__DriverStopTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DriverStopTrack", 0xFFFFFFFF);
  DriverStopTrack::sClassNameUID = result;
  return result;
}

// File Line: 138
// RVA: 0x32E000
void __fastcall DriverStopTrack::DriverStopTrack(DriverStopTrack *this)
{
  DriverStopTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DriverStopTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DriverStopTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DriverStopTrack::`vftable';
}

// File Line: 142
// RVA: 0x336560
void __fastcall DriverStopTrack::~DriverStopTrack(DriverStopTrack *this)
{
  DriverStopTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DriverStopTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

