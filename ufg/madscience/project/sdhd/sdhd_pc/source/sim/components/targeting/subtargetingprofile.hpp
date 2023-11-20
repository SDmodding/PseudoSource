// File Line: 37
// RVA: 0x515ED0
void __fastcall UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::AngularInputToSubTargetingLocation(UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation *this)
{
  UFG::SubTargetingLocationDynamic *v1; // [rsp+28h] [rbp+10h]

  v1 = &this->m_SubTargetingLocationDynamic;
  v1->m_SubTargetingLocationsWithConditions.p[0].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.p[1].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.p[2].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.p[3].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.p[4].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.p[5].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.size = 0;
}

// File Line: 48
// RVA: 0x5197D0
void __fastcall UFG::SubTargetingProfileInfo::SubTargetingProfileInfo(UFG::SubTargetingProfileInfo *this)
{
  UFG::SubTargetingProfileInfo *v1; // rbx

  v1 = this;
  `eh vector constructor iterator(
    this->m_AngularInputToSubTargetingLocations.p,
    0x70ui64,
    6,
    (void (__fastcall *)(void *))UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::AngularInputToSubTargetingLocation);
  v1->m_AngularInputToSubTargetingLocations.size = 0;
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
  UFG::SubTargetingLocationDynamic *v1; // rax
  UFG::SubTargetingLocationDynamic *v2; // rax
  UFG::qFixedArray<UFG::SubTargetingProfileInfo,4> *v3; // rbx

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  v1 = &this->m_DefaultSubTargetingLocationDynamic;
  v1->m_SubTargetingLocationsWithConditions.p[0].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.p[1].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.p[2].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.p[3].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.p[4].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.p[5].m_eDynamicCondition = 0;
  v1->m_SubTargetingLocationsWithConditions.size = 0;
  v2 = &this->m_HeadLookAtSubTargetingLocationDynamic;
  v2->m_SubTargetingLocationsWithConditions.p[0].m_eDynamicCondition = 0;
  v2->m_SubTargetingLocationsWithConditions.p[1].m_eDynamicCondition = 0;
  v2->m_SubTargetingLocationsWithConditions.p[2].m_eDynamicCondition = 0;
  v2->m_SubTargetingLocationsWithConditions.p[3].m_eDynamicCondition = 0;
  v2->m_SubTargetingLocationsWithConditions.p[4].m_eDynamicCondition = 0;
  v2->m_SubTargetingLocationsWithConditions.p[5].m_eDynamicCondition = 0;
  v2->m_SubTargetingLocationsWithConditions.size = 0;
  v3 = &this->m_SubTargetingProfileInfos;
  `eh vector constructor iterator(
    this->m_SubTargetingProfileInfos.p,
    0x2B0ui64,
    4,
    (void (__fastcall *)(void *))UFG::SubTargetingProfileInfo::SubTargetingProfileInfo);
  v3->size = 0;
}

// File Line: 81
// RVA: 0x51CB80
void __fastcall UFG::SubTargetingProfile::~SubTargetingProfile(UFG::SubTargetingProfile *this)
{
  UFG::SubTargetingProfile *v1; // rbx

  v1 = this;
  this->m_SubTargetingProfileInfos.size = 0;
  `eh vector destructor iterator(
    this->m_SubTargetingProfileInfos.p,
    0x2B0ui64,
    4,
    (void (__fastcall *)(void *))UFG::SubTargetingProfileInfo::~SubTargetingProfileInfo);
  v1->m_HeadLookAtSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.size = 0;
  v1->m_DefaultSubTargetingLocationDynamic.m_SubTargetingLocationsWithConditions.size = 0;
}

