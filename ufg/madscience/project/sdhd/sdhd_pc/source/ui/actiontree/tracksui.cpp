// File Line: 17
// RVA: 0x1496750
__int64 dynamic_initializer_for__UIEventTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UIEventTrack", 0xFFFFFFFF);
  UIEventTrack::sClassNameUID = result;
  return result;
}

// File Line: 23
// RVA: 0x2E21D0
void __fastcall UIEventTrack::UIEventTrack(UIEventTrack *this)
{
  ITrack::ITrack(this, UIEventTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<UIEventTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&UIEventTrack::`vftable;
  this->mEventName.mOffset = 1i64;
  BinString::Set(&this->mEventName, "NO_EVENT");
}

// File Line: 57
// RVA: 0x149CA30
__int64 dynamic_initializer_for__gUIScreenListEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gUIScreenListEnum, gUIScreenListNames, gUIScreenListCount, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gUIScreenListEnum__);
}

// File Line: 58
// RVA: 0x1496770
__int64 dynamic_initializer_for__UIScreenTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UIScreenTrack", 0xFFFFFFFF);
  UIScreenTrack::sClassNameUID = result;
  return result;
}

// File Line: 74
// RVA: 0x2E2290
void __fastcall UIScreenTrack::UIScreenTrack(UIScreenTrack *this)
{
  ITrack::ITrack(this, UIScreenTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<UIScreenTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&UIScreenTrack::`vftable;
  this->mScreen = 0;
  *(_WORD *)&this->mPopHud = 1;
  this->mDontRemoveOnEnd = 0;
}

// File Line: 90
// RVA: 0x1495510
__int64 dynamic_initializer_for__HUDSocialActionChargeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HUDSocialActionChargeTrack", 0xFFFFFFFF);
  HUDSocialActionChargeTrack::sClassNameUID = result;
  return result;
}

// File Line: 102
// RVA: 0x2DF730
void __fastcall HUDSocialActionChargeTrack::HUDSocialActionChargeTrack(HUDSocialActionChargeTrack *this)
{
  ITrack::ITrack(this, HUDSocialActionChargeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<HUDSocialActionChargeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&HUDSocialActionChargeTrack::`vftable;
  this->m_Charge = 0.0;
  this->m_SetValue = 0;
}

// File Line: 116
// RVA: 0x1495530
__int64 dynamic_initializer_for__HUDSocialActionEnableTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HUDSocialActionEnableTrack", 0xFFFFFFFF);
  HUDSocialActionEnableTrack::sClassNameUID = result;
  return result;
}

// File Line: 125
// RVA: 0x2DF780
void __fastcall HUDSocialActionEnableTrack::HUDSocialActionEnableTrack(HUDSocialActionEnableTrack *this)
{
  ITrack::ITrack(this, HUDSocialActionEnableTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<HUDSocialActionEnableTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&HUDSocialActionEnableTrack::`vftable;
  this->m_Enabled = 1;
}

// File Line: 138
// RVA: 0x14954F0
__int64 dynamic_initializer_for__HUDSocialActionActivateTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HUDSocialActionActivateTrack", 0xFFFFFFFF);
  HUDSocialActionActivateTrack::sClassNameUID = result;
  return result;
}

// File Line: 145
// RVA: 0x2DF6F0
void __fastcall HUDSocialActionActivateTrack::HUDSocialActionActivateTrack(HUDSocialActionActivateTrack *this)
{
  ITrack::ITrack(this, HUDSocialActionActivateTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<HUDSocialActionActivateTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&HUDSocialActionActivateTrack::`vftable;
}

