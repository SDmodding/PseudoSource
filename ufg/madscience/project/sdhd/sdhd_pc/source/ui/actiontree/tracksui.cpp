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
  UIEventTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, UIEventTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<UIEventTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&UIEventTrack::`vftable;
  v1->mEventName.mOffset = 1i64;
  BinString::Set(&v1->mEventName, "NO_EVENT");
}

// File Line: 57
// RVA: 0x149CA30
__int64 dynamic_initializer_for__gUIScreenListEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gUIScreenListEnum, gUIScreenListNames, gUIScreenListCount, 0i64);
  return atexit(dynamic_atexit_destructor_for__gUIScreenListEnum__);
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
  UIScreenTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, UIScreenTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<UIScreenTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&UIScreenTrack::`vftable;
  v1->mScreen = 0;
  *(_WORD *)&v1->mPopHud = 1;
  v1->mDontRemoveOnEnd = 0;
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
  HUDSocialActionChargeTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, HUDSocialActionChargeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<HUDSocialActionChargeTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&HUDSocialActionChargeTrack::`vftable;
  v1->m_Charge = 0.0;
  v1->m_SetValue = 0;
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
  HUDSocialActionEnableTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, HUDSocialActionEnableTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<HUDSocialActionEnableTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&HUDSocialActionEnableTrack::`vftable;
  v1->m_Enabled = 1;
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
  HUDSocialActionActivateTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, HUDSocialActionActivateTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<HUDSocialActionActivateTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&HUDSocialActionActivateTrack::`vftable;
}

