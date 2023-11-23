// File Line: 37
// RVA: 0x515ED0
void __fastcall UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::AngularInputToSubTargetingLocation(
        UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation *this)
{
  this->m_SubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[0].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_SubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[1].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_SubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[2].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_SubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[3].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_SubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[4].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_SubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[5].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_SubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.size = 0;
}

// File Line: 48
// RVA: 0x5197D0
void __fastcall UFG::SubTargetingProfileInfo::SubTargetingProfileInfo(UFG::SubTargetingProfileInfo *this)
{
  `eh vector constructor iterator(
    this->m_AngularInputToSubTargetingLocations.p,
    0x70ui64,
    6,
    (void (__fastcall *)(void *))UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::AngularInputToSubTargetingLocation);
  this->m_AngularInputToSubTargetingLocations.size = 0;
}

// File Line: 49
// RVA: 0x51CBF0
void __fastcall UFG::SubTargetingProfileInfo::~SubTargetingProfileInfo(UFG::SubTargetingProfileInfo *this)
{
  this->m_AngularInputToSubTargetingLocations.size = 0;
  `eh vector destructor iterator(
    this->m_AngularInputToSubTargetingLocations.p,
    0x70ui64,
    6,
    (void (__fastcall *)(void *))UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::~AngularInputToSubTargetingLocation);
}

// File Line: 80
// RVA: 0x519720
void __fastcall UFG::SubTargetingProfile::SubTargetingProfile(UFG::SubTargetingProfile *this)
{
  UFG::qFixedArray<UFG::SubTargetingProfileInfo,4> *p_m_SubTargetingProfileInfos; // rbx

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->m_DefaultSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[0].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_DefaultSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[1].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_DefaultSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[2].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_DefaultSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[3].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_DefaultSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[4].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_DefaultSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[5].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_DefaultSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.size = 0;
  this->m_HeadLookAtSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[0].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_HeadLookAtSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[1].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_HeadLookAtSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[2].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_HeadLookAtSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[3].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_HeadLookAtSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[4].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_HeadLookAtSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.p[5].m_eDynamicCondition = DYNAMIC_CONDITION_INVALID;
  this->m_HeadLookAtSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.size = 0;
  p_m_SubTargetingProfileInfos = &this->m_SubTargetingProfileInfos;
  `eh vector constructor iterator(
    this->m_SubTargetingProfileInfos.p,
    0x2B0ui64,
    4,
    (void (__fastcall *)(void *))UFG::SubTargetingProfileInfo::SubTargetingProfileInfo);
  p_m_SubTargetingProfileInfos->size = 0;
}

// File Line: 81
// RVA: 0x51CB80
void __fastcall UFG::SubTargetingProfile::~SubTargetingProfile(UFG::SubTargetingProfile *this)
{
  UFG::qFixedArray<UFG::SubTargetingProfileInfo,4> *p_m_SubTargetingProfileInfos; // rcx

  p_m_SubTargetingProfileInfos = &this->m_SubTargetingProfileInfos;
  p_m_SubTargetingProfileInfos->size = 0;
  `eh vector destructor iterator(
    p_m_SubTargetingProfileInfos->p,
    0x2B0ui64,
    4,
    (void (__fastcall *)(void *))UFG::SubTargetingProfileInfo::~SubTargetingProfileInfo);
  this->m_HeadLookAtSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.size = 0;
  this->m_DefaultSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.size = 0;
}

