// File Line: 18
// RVA: 0x1495970
__int64 dynamic_initializer_for__POIBehaviourActiveTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("POIBehaviourActiveTrack", 0xFFFFFFFF);
  POIBehaviourActiveTrack::sClassNameUID = result;
  return result;
}

// File Line: 28
// RVA: 0x14959D0
__int64 dynamic_initializer_for__POIManagementTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("POIManagementTrack", 0xFFFFFFFF);
  POIManagementTrack::sClassNameUID = result;
  return result;
}

// File Line: 39
// RVA: 0x1495990
__int64 dynamic_initializer_for__POIDisableSelfTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("POIDisableSelfTrack", 0xFFFFFFFF);
  POIDisableSelfTrack::sClassNameUID = result;
  return result;
}

// File Line: 56
// RVA: 0x2DFC00
void __fastcall InteractionPointInteractWithBestTrack::InteractionPointInteractWithBestTrack(
        InteractionPointInteractWithBestTrack *this)
{
  ITrack::ITrack(this, InteractionPointInteractWithBestTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<InteractionPointInteractWithBestTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointInteractWithBestTrack::`vftable;
}

// File Line: 59
// RVA: 0x14956D0
__int64 dynamic_initializer_for__InteractionPointInteractWithBestTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InteractionPointInteractWithBestTrack", 0xFFFFFFFF);
  InteractionPointInteractWithBestTrack::sClassNameUID = result;
  return result;
}

// File Line: 81
// RVA: 0x2DFC40
void __fastcall InteractionPointSetupTrack::InteractionPointSetupTrack(InteractionPointSetupTrack *this)
{
  ITrack::ITrack(this, InteractionPointSetupTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<InteractionPointSetupTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointSetupTrack::`vftable;
  *(_WORD *)&this->m_eTargetType.mValue = 325;
  this->m_eInteractionUpdate.mValue = 0;
  this->m_fDistance = 0.0;
  this->m_BoneName.mUID = -1;
  this->m_bDeactivateOnEnd = 0;
}

// File Line: 84
// RVA: 0x14956F0
__int64 dynamic_initializer_for__InteractionPointSetupTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InteractionPointSetupTrack", 0xFFFFFFFF);
  InteractionPointSetupTrack::sClassNameUID = result;
  return result;
}

// File Line: 113
// RVA: 0x2DFB60
void __fastcall InteractionPointActivateTrack::InteractionPointActivateTrack(InteractionPointActivateTrack *this)
{
  ITrack::ITrack(this, InteractionPointActivateTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<InteractionPointActivateTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointActivateTrack::`vftable;
  *(_WORD *)&this->m_eTargetType.mValue = 70;
}

// File Line: 116
// RVA: 0x1495690
__int64 dynamic_initializer_for__InteractionPointActivateTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InteractionPointActivateTrack", 0xFFFFFFFF);
  InteractionPointActivateTrack::sClassNameUID = result;
  return result;
}

// File Line: 137
// RVA: 0x2DFBB0
void __fastcall InteractionPointDeactivateTrack::InteractionPointDeactivateTrack(InteractionPointDeactivateTrack *this)
{
  ITrack::ITrack(this, InteractionPointDeactivateTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<InteractionPointDeactivateTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&InteractionPointDeactivateTrack::`vftable;
  this->m_eTargetType.mValue = 70;
}

// File Line: 140
// RVA: 0x14956B0
__int64 dynamic_initializer_for__InteractionPointDeactivateTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InteractionPointDeactivateTrack", 0xFFFFFFFF);
  InteractionPointDeactivateTrack::sClassNameUID = result;
  return result;
}

// File Line: 155
// RVA: 0x14959B0
__int64 dynamic_initializer_for__POIEnableChildTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("POIEnableChildTrack", 0xFFFFFFFF);
  POIEnableChildTrack::sClassNameUID = result;
  return result;
}

// File Line: 169
// RVA: 0x2DFFF0
void __fastcall POIEnableChildTrack::POIEnableChildTrack(POIEnableChildTrack *this)
{
  ITrack::ITrack(this, POIEnableChildTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<POIEnableChildTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&POIEnableChildTrack::`vftable;
  this->m_ChildName.mOffset = 1i64;
  BinString::Set(&this->m_ChildName, &customCaption);
  this->m_Index = 0;
  this->m_Active = 0;
}

