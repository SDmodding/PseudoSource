// File Line: 164
// RVA: 0x331E40
void __fastcall UFG::PedFormationProfile::Slot::Slot(UFG::PedFormationProfile::Slot *this)
{
  UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>::qSafePointerNode<UFG::PedFormationProfile::Slot>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>Vtbl *)&UFG::PedFormationProfile::Slot::`vftable;
  this->mFacingType = ePedFormationFacingType_Invalid;
  this->mAngle = 0;
  this->mCanCrossLeader = 0;
  this->mPreference = 1.0;
  *(_QWORD *)&this->mMinFollowers = 1i64;
  *(_QWORD *)&this->mMaxDistance = 0i64;
  *(_QWORD *)&this->mMinFacingDifference = 0i64;
  *(_QWORD *)&this->mMaxRadialDistanceFromDesiredPosition = 0i64;
  *(_QWORD *)&this->mMinRadialHysteresisModifier = 0i64;
  *(_QWORD *)&this->mMaxRadialDistanceFromDesiredPositionHysteresisLarge = 0i64;
  *(_QWORD *)&this->mMaxRadialDistanceFromDesiredPositionHysteresisFar = 0i64;
  this->mMaxLateralDistanceFromDesiredPositionHysteresisFar = 0.0;
}

// File Line: 168
// RVA: 0x3682D0
void __fastcall UFG::PedFormationProfile::Slot::InitFromPropertySet(
        UFG::PedFormationProfile::Slot *this,
        UFG::qPropertySet *pPropertySet)
{
  UFG::qArray<unsigned long,0> *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  float mMinDistance; // xmm0_4
  UFG::qArray<unsigned long,0> *v10; // rax
  UFG::qArray<unsigned long,0> *v11; // rax
  UFG::qArray<unsigned long,0> *v12; // rax
  UFG::qArray<unsigned long,0> *v13; // rax
  UFG::qArray<unsigned long,0> *v14; // rax
  UFG::qArray<unsigned long,0> *v15; // rax
  UFG::qArray<unsigned long,0> *v16; // rax
  UFG::qArray<unsigned long,0> *v17; // rax
  UFG::qArray<unsigned long,0> *v18; // rax
  UFG::qArray<unsigned long,0> *v19; // rax
  UFG::qSymbol v20; // [rsp+20h] [rbp-50h] BYREF
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-48h] BYREF
  UFG::qArray<unsigned long,0> v22; // [rsp+48h] [rbp-28h] BYREF
  UFG::qArray<unsigned long,0> v23; // [rsp+58h] [rbp-18h] BYREF
  UFG::qArray<unsigned long,0> result; // [rsp+90h] [rbp+20h] BYREF
  UFG::qArray<unsigned long,0> name; // [rsp+A0h] [rbp+30h] BYREF

  v23.p = (unsigned int *)-2i64;
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, "Angle");
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&name, "CanCrossLeader");
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&name.p, "Preference");
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&v22.p, "MinFollowers");
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&v22.capacity, "MinDistance");
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&v22.p + 1, "MaxDistance");
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&v22, "MaxLookAhead");
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&v23, "MinFacingDifference");
  v4 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v20, "FacingType");
  v5 = UFG::qPropertySet::Get<UFG::qSymbol>(pPropertySet, v4, DEPTH_RECURSE);
  if ( v5 )
  {
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v5->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gPedFormationFacingTypeTracksEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gPedFormationFacingTypeTracksEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gPedFormationFacingTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gPedFormationFacingTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gPedFormationFacingTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gPedFormationFacingTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    this->mFacingType = pTrackEnumBinding.m_EnumValue;
    v7 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v7;
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
  }
  this->mAngle = (int)(float)((float)(*UFG::qPropertySet::Get<float>(pPropertySet, &result, DEPTH_RECURSE) * 65536.0)
                            * 0.0027777778);
  this->mCanCrossLeader = *UFG::qPropertySet::Get<bool>(pPropertySet, &name, DEPTH_RECURSE);
  this->mPreference = *UFG::qPropertySet::Get<float>(
                         pPropertySet,
                         (UFG::qArray<unsigned long,0> *)&name.p,
                         DEPTH_RECURSE);
  this->mMinFollowers = *UFG::qPropertySet::Get<unsigned long>(
                           pPropertySet,
                           (UFG::qArray<unsigned long,0> *)&v22.p,
                           DEPTH_RECURSE);
  this->mMinDistance = *UFG::qPropertySet::Get<float>(
                          pPropertySet,
                          (UFG::qArray<unsigned long,0> *)&v22.capacity,
                          DEPTH_RECURSE);
  mMinDistance = *UFG::qPropertySet::Get<float>(
                    pPropertySet,
                    (UFG::qArray<unsigned long,0> *)((char *)&v22.p + 4),
                    DEPTH_RECURSE);
  if ( mMinDistance <= this->mMinDistance )
    mMinDistance = this->mMinDistance;
  this->mMaxDistance = mMinDistance;
  this->mMaxLookAhead = *UFG::qPropertySet::Get<float>(pPropertySet, &v22, DEPTH_RECURSE);
  this->mMinFacingDifference = *UFG::qPropertySet::Get<float>(pPropertySet, &v23, DEPTH_RECURSE);
  v10 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v20, "MinFacingDifferenceHysteresis");
  this->mMinFacingDifferenceHysteresis = *UFG::qPropertySet::Get<float>(pPropertySet, v10, DEPTH_RECURSE);
  v11 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v20, "MaxRadialDistanceFromDesiredPosition");
  this->mMaxRadialDistanceFromDesiredPosition = *UFG::qPropertySet::Get<float>(pPropertySet, v11, DEPTH_RECURSE);
  v12 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v20, "MaxLateralDistanceFromDesiredPosition");
  this->mMaxLateralDistanceFromDesiredPosition = *UFG::qPropertySet::Get<float>(pPropertySet, v12, DEPTH_RECURSE);
  v13 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v20, "MinRadialHysteresisModifier");
  this->mMinRadialHysteresisModifier = *UFG::qPropertySet::Get<float>(pPropertySet, v13, DEPTH_RECURSE);
  v14 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v20, "MaxRadialHysteresisModifier");
  this->mMaxRadialHysteresisModifier = *UFG::qPropertySet::Get<float>(pPropertySet, v14, DEPTH_RECURSE);
  v15 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                          &v20,
                                          "MaxRadialDistanceFromDesiredPositionHysteresisLarge");
  this->mMaxRadialDistanceFromDesiredPositionHysteresisLarge = *UFG::qPropertySet::Get<float>(
                                                                  pPropertySet,
                                                                  v15,
                                                                  DEPTH_RECURSE);
  v16 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                          &v20,
                                          "MaxRadialDistanceFromDesiredPositionHysteresis");
  this->mMaxRadialDistanceFromDesiredPositionHysteresis = *UFG::qPropertySet::Get<float>(
                                                             pPropertySet,
                                                             v16,
                                                             DEPTH_RECURSE);
  v17 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                          &v20,
                                          "MaxRadialDistanceFromDesiredPositionHysteresisFar");
  this->mMaxRadialDistanceFromDesiredPositionHysteresisFar = *UFG::qPropertySet::Get<float>(
                                                                pPropertySet,
                                                                v17,
                                                                DEPTH_RECURSE);
  v18 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                          &v20,
                                          "MaxLateralDistanceFromDesiredPositionHysteresis");
  this->mMaxLateralDistanceFromDesiredPositionHysteresis = *UFG::qPropertySet::Get<float>(
                                                              pPropertySet,
                                                              v18,
                                                              DEPTH_RECURSE);
  v19 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                          &v20,
                                          "MaxLateralDistanceFromDesiredPositionHysteresisFar");
  this->mMaxLateralDistanceFromDesiredPositionHysteresisFar = *UFG::qPropertySet::Get<float>(
                                                                 pPropertySet,
                                                                 v19,
                                                                 DEPTH_RECURSE);
}

// File Line: 240
// RVA: 0x367CB0
void __fastcall UFG::PedFormationProfile::InitFromPropertySet(
        UFG::PedFormationProfile *this,
        UFG::qPropertySet *pPropertySet)
{
  UFG::qArray<unsigned long,0> *v4; // rax
  UFG::qArray<unsigned long,0> *v5; // rax
  UFG::qArray<unsigned long,0> *v6; // rax
  UFG::qArray<unsigned long,0> *v7; // rax
  UFG::qArray<unsigned long,0> *v8; // rax
  UFG::qArray<unsigned long,0> *v9; // rax
  UFG::qArray<unsigned long,0> *v10; // rax
  UFG::qArray<unsigned long,0> *v11; // rax
  UFG::qPropertyList *v12; // r14
  unsigned int mNumElements; // esi
  unsigned int v14; // edi
  char *ValuePtr; // rax
  UFG::qPropertySet *v16; // r8
  __int64 size; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *mNext; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::PedFormationProfile::Slot v25; // [rsp+30h] [rbp-39h] BYREF
  UFG::qSymbol result; // [rsp+D0h] [rbp+67h] BYREF
  UFG::qList<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // [rsp+D8h] [rbp+6Fh]
  UFG::qList<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList,1,0> *v28; // [rsp+E0h] [rbp+77h]

  this->mSlots.size = 0;
  *(_QWORD *)&this->mDistanceToBeConsideredClose = 0i64;
  *(_QWORD *)&this->mMaxTimeForLargeHysteresis = 0i64;
  *(_QWORD *)&this->mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = 0i64;
  this->mIsActive = 1;
  if ( pPropertySet )
  {
    this->mNode.mUID = pPropertySet->mName.mUID;
    v4 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "DistanceToBeConsideredClose");
    this->mDistanceToBeConsideredClose = *UFG::qPropertySet::Get<float>(pPropertySet, v4, DEPTH_RECURSE);
    v5 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "MinTimeForLargeHysteresis");
    this->mMinTimeForLargeHysteresis = *UFG::qPropertySet::Get<float>(pPropertySet, v5, DEPTH_RECURSE);
    v6 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "MaxTimeForLargeHysteresis");
    this->mMaxTimeForLargeHysteresis = *UFG::qPropertySet::Get<float>(pPropertySet, v6, DEPTH_RECURSE);
    v7 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "MinTimeBetweenSlotChanges");
    this->mMinTimeBetweenSlotChanges = *UFG::qPropertySet::Get<float>(pPropertySet, v7, DEPTH_RECURSE);
    v8 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(
                                           &result,
                                           "MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting_Formation");
    this->mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = *UFG::qPropertySet::Get<float>(
                                                                                        pPropertySet,
                                                                                        v8,
                                                                                        DEPTH_RECURSE);
    v9 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "Active");
    this->mIsActive = *UFG::qPropertySet::Get<bool>(pPropertySet, v9, DEPTH_RECURSE);
    v10 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "MaxFollowers");
    this->mMaxFollowers = *UFG::qPropertySet::Get<unsigned long>(pPropertySet, v10, DEPTH_RECURSE);
    v11 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "SlotList");
    v12 = UFG::qPropertySet::Get<UFG::qPropertyList>(pPropertySet, v11, DEPTH_RECURSE);
    mNumElements = v12->mNumElements;
    if ( mNumElements > 9 )
      mNumElements = 9;
    if ( this->mMaxFollowers > mNumElements )
      this->mMaxFollowers = mNumElements;
    v14 = 0;
    if ( mNumElements )
    {
      p_m_SafePointerList = &v25.m_SafePointerList;
      v28 = &v25.m_SafePointerList;
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v12, 0x1Au, v14);
        if ( !ValuePtr || (v16 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
          v16 = 0i64;
        v25.m_SafePointerList.mNode.mPrev = &v25.m_SafePointerList.mNode;
        v25.m_SafePointerList.mNode.mNext = &v25.m_SafePointerList.mNode;
        v25.vfptr = (UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>Vtbl *)&UFG::PedFormationProfile::Slot::`vftable;
        v25.mFacingType = ePedFormationFacingType_Invalid;
        v25.mAngle = 0;
        v25.mCanCrossLeader = 0;
        v25.mPreference = 1.0;
        *(_QWORD *)&v25.mMinFollowers = 1i64;
        memset(&v25.mMaxDistance, 0, 52);
        UFG::PedFormationProfile::Slot::InitFromPropertySet(&v25, v16);
        size = this->mSlots.size;
        this->mSlots.p[size].mFacingType = v25.mFacingType;
        this->mSlots.p[size].mAngle = v25.mAngle;
        this->mSlots.p[size].mCanCrossLeader = v25.mCanCrossLeader;
        this->mSlots.p[size].mPreference = v25.mPreference;
        *(_QWORD *)&this->mSlots.p[size].mMinFollowers = *(_QWORD *)&v25.mMinFollowers;
        this->mSlots.p[size].mMaxDistance = v25.mMaxDistance;
        this->mSlots.p[size].mMaxLookAhead = v25.mMaxLookAhead;
        this->mSlots.p[size].mMinFacingDifference = v25.mMinFacingDifference;
        this->mSlots.p[size].mMinFacingDifferenceHysteresis = v25.mMinFacingDifferenceHysteresis;
        this->mSlots.p[size].mMaxRadialDistanceFromDesiredPosition = v25.mMaxRadialDistanceFromDesiredPosition;
        this->mSlots.p[size].mMaxLateralDistanceFromDesiredPosition = v25.mMaxLateralDistanceFromDesiredPosition;
        this->mSlots.p[size].mMinRadialHysteresisModifier = v25.mMinRadialHysteresisModifier;
        this->mSlots.p[size].mMaxRadialHysteresisModifier = v25.mMaxRadialHysteresisModifier;
        this->mSlots.p[size].mMaxRadialDistanceFromDesiredPositionHysteresisLarge = v25.mMaxRadialDistanceFromDesiredPositionHysteresisLarge;
        this->mSlots.p[size].mMaxRadialDistanceFromDesiredPositionHysteresis = v25.mMaxRadialDistanceFromDesiredPositionHysteresis;
        this->mSlots.p[size].mMaxRadialDistanceFromDesiredPositionHysteresisFar = v25.mMaxRadialDistanceFromDesiredPositionHysteresisFar;
        this->mSlots.p[size].mMaxLateralDistanceFromDesiredPositionHysteresis = v25.mMaxLateralDistanceFromDesiredPositionHysteresis;
        this->mSlots.p[size].mMaxLateralDistanceFromDesiredPositionHysteresisFar = v25.mMaxLateralDistanceFromDesiredPositionHysteresisFar;
        ++this->mSlots.size;
        v25.vfptr = (UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>Vtbl *)&UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>::`vftable;
        mNext = v25.m_SafePointerList.mNode.mNext;
        if ( (UFG::qList<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList,1,0> *)v25.m_SafePointerList.mNode.mNext != &v25.m_SafePointerList )
        {
          while ( (unsigned __int64)mNext >= 0x10 )
          {
            if ( mNext[1].mPrev
              || (v19 = mNext->mPrev,
                  v20 = mNext->mNext,
                  v19->mNext = v20,
                  v20->mPrev = v19,
                  mNext->mPrev = mNext,
                  mNext->mNext = mNext,
                  mNext[1].mPrev) )
            {
              mPrev = mNext->mPrev;
              v22 = mNext->mNext;
              mPrev->mNext = v22;
              v22->mPrev = mPrev;
              mNext->mPrev = mNext;
              mNext->mNext = mNext;
            }
            mNext[1].mPrev = 0i64;
            mNext = v25.m_SafePointerList.mNode.mNext;
            if ( (UFG::qList<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList,1,0> *)v25.m_SafePointerList.mNode.mNext == &v25.m_SafePointerList )
              goto LABEL_19;
          }
          v25.m_SafePointerList.mNode.mPrev = &v25.m_SafePointerList.mNode;
          v25.m_SafePointerList.mNode.mNext = &v25.m_SafePointerList.mNode;
        }
LABEL_19:
        UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v25.m_SafePointerList);
        v23 = v25.m_SafePointerList.mNode.mPrev;
        v24 = v25.m_SafePointerList.mNode.mNext;
        v25.m_SafePointerList.mNode.mPrev->mNext = v25.m_SafePointerList.mNode.mNext;
        v24->mPrev = v23;
        v25.m_SafePointerList.mNode.mPrev = &v25.m_SafePointerList.mNode;
        v25.m_SafePointerList.mNode.mNext = &v25.m_SafePointerList.mNode;
        ++v14;
      }
      while ( v14 < mNumElements );
    }
  }
}

// File Line: 323
// RVA: 0x384C60
void __fastcall UFG::PedFormationTimer::Set(UFG::PedFormationTimer *this, float min_time, float max_time)
{
  float mSimTime_Temp; // xmm8_4
  float v5; // xmm0_4

  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( min_time < 0.0 || max_time <= 0.0 )
  {
    this->mNextTime = -1.0;
  }
  else
  {
    v5 = max_time;
    if ( max_time > min_time )
    {
      v5 = UFG::qRandom(max_time - min_time, (unsigned int *)&UFG::qDefaultSeed) + min_time;
      if ( v5 <= min_time )
        v5 = min_time;
      if ( v5 >= max_time )
        v5 = max_time;
    }
    this->mNextTime = v5 + mSimTime_Temp;
  }
}

// File Line: 399
// RVA: 0x3689F0
void __fastcall UFG::PedFormationSlot::InitWithDefaults(
        UFG::PedFormationSlot *this,
        UFG::PedFormationManagerComponent *parent)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *p_m_pPedFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *p_m_pMember; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::PedFormationPair *p_m_Pair; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax

  p_m_pPedFormationManagerComponent = &this->m_pPedFormationManagerComponent;
  *(_QWORD *)&this->m_Direction.x = 0i64;
  this->m_Direction.z = 0.0;
  *(_QWORD *)&this->m_FacingDirection.x = 0i64;
  *(_QWORD *)&this->m_FacingDirection.z = 0i64;
  this->m_Angle = 0;
  *(_QWORD *)&this->m_DesiredMoveType = 1i64;
  this->m_TimeGotIntoPosition = -99999.0;
  this->m_TimeFinishUsingLargeHysteresis = -1.0;
  *(_WORD *)&this->m_CurrentlyInRange = 0;
  this->m_RadialHysteresisModifier = 0.0;
  this->m_CurrentlyStayingClose = 0;
  if ( this->m_pPedFormationManagerComponent.m_pPointer )
  {
    mPrev = p_m_pPedFormationManagerComponent->mPrev;
    mNext = p_m_pPedFormationManagerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pPedFormationManagerComponent->mPrev = p_m_pPedFormationManagerComponent;
    p_m_pPedFormationManagerComponent->mNext = p_m_pPedFormationManagerComponent;
  }
  p_m_pPedFormationManagerComponent->m_pPointer = parent;
  if ( parent )
  {
    v7 = parent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v7->mNext = p_m_pPedFormationManagerComponent;
    p_m_pPedFormationManagerComponent->mPrev = v7;
    p_m_pPedFormationManagerComponent->mNext = &parent->m_SafePointerList.mNode;
    parent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pPedFormationManagerComponent;
  }
  p_m_pMember = &this->m_pMember;
  this->m_pProfileSlot = 0i64;
  this->m_SlotChangeAllowedTimer.mNextTime = -1.0;
  if ( this->m_pMember.m_pPointer )
  {
    v9 = p_m_pMember->mPrev;
    v10 = this->m_pMember.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    p_m_pMember->mPrev = p_m_pMember;
    this->m_pMember.mNext = &this->m_pMember;
  }
  p_m_Pair = &this->m_Pair;
  p_m_pMember->m_pPointer = 0i64;
  if ( p_m_Pair->m_pPair.m_pPointer )
  {
    v12 = p_m_Pair->m_pPair.mPrev;
    v13 = p_m_Pair->m_pPair.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    p_m_Pair->m_pPair.mPrev = &p_m_Pair->m_pPair;
    p_m_Pair->m_pPair.mNext = &p_m_Pair->m_pPair;
  }
  p_m_Pair->m_pPair.m_pPointer = 0i64;
  p_m_Pair->m_PairChangeAllowedTimer.mNextTime = -1.0;
}

// File Line: 430
// RVA: 0x387B70
void __fastcall UFG::PedFormationSlot::SetRadialHysteresisModifier(UFG::PedFormationSlot *this)
{
  UFG::PedFormationProfile::Slot *m_pProfileSlot; // rax
  float mMaxRadialHysteresisModifier; // xmm6_4
  float mMinRadialHysteresisModifier; // xmm7_4
  float v5; // xmm0_4

  m_pProfileSlot = this->m_pProfileSlot;
  if ( m_pProfileSlot )
  {
    mMaxRadialHysteresisModifier = m_pProfileSlot->mMaxRadialHysteresisModifier;
    mMinRadialHysteresisModifier = m_pProfileSlot->mMinRadialHysteresisModifier;
    v5 = mMaxRadialHysteresisModifier;
    if ( mMaxRadialHysteresisModifier > mMinRadialHysteresisModifier )
    {
      v5 = UFG::qRandom(mMaxRadialHysteresisModifier - mMinRadialHysteresisModifier, (unsigned int *)&UFG::qDefaultSeed)
         + mMinRadialHysteresisModifier;
      if ( v5 <= mMinRadialHysteresisModifier )
        v5 = mMinRadialHysteresisModifier;
      if ( v5 >= mMaxRadialHysteresisModifier )
        v5 = mMaxRadialHysteresisModifier;
    }
    this->m_RadialHysteresisModifier = v5;
  }
}

// File Line: 439
// RVA: 0x386760
void __fastcall UFG::PedFormationSlot::SetInPosition(
        UFG::PedFormationSlot *this,
        UFG::PedFormationSlot::ePositionType in_position)
{
  float mSimTime_Temp; // xmm0_4

  if ( this->m_InPosition && in_position == ePOSITION_IN_POSITION )
  {
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    this->m_DesiredMoveType = eMoveType_Walk;
    this->m_TimeGotIntoPosition = mSimTime_Temp;
    UFG::PedFormationSlot::SetRadialHysteresisModifier(this);
  }
  if ( this->m_InPosition != in_position )
    this->m_InPosition = in_position;
}

// File Line: 459
// RVA: 0x14AEBA0
__int64 dynamic_initializer_for__UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList__);
}

// File Line: 460
// RVA: 0x3633C0
const char *__fastcall UFG::PedFormationManagerComponent::GetTypeName(UFG::PedFormationManagerComponent *this)
{
  return "PedFormationManagerComponent";
}

// File Line: 462
// RVA: 0x14AEBC0
__int64 dynamic_initializer_for__UFG::PedFormationManagerComponent::s_ProfilePool__()
{
  `eh vector constructor iterator(
    (char *)&ptr,
    0x3A8ui64,
    16,
    (void (__fastcall *)(void *))UFG::PedFormationProfile::PedFormationProfile);
  UFG::PedFormationManagerComponent::s_ProfilePool.size = 0;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedFormationManagerComponent::s_ProfilePool__);
}

// File Line: 463
// RVA: 0x14AEC60
__int64 dynamic_initializer_for__UFG::PedFormationManagerComponent::s_Profiles__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PedFormationManagerComponent::s_Profiles.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PedFormationManagerComponent::s_Profiles__);
}

// File Line: 468
// RVA: 0x389030
void UFG::PedFormationManagerComponent::StaticInit(void)
{
  UFG::qPropertySet *PropertySet; // rbx
  UFG::qPropertyList *v1; // rax
  UFG::qPropertyList *v2; // rbp
  unsigned int mNumElements; // esi
  unsigned int i; // edi
  UFG::qSymbol *v5; // rax
  UFG::qSymbolUC *v6; // rbx
  UFG::qPropertySet *v7; // rax
  unsigned int size; // ecx
  UFG::PedFormationProfile *v9; // rbx
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax
  char *v13; // rax
  UFG::qArray<unsigned long,0> name; // [rsp+40h] [rbp+8h] BYREF

  UFG::qSymbol::create_from_string((UFG::qSymbol *)&name.p, "default-formation-manifest");
  PropertySet = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&name.p);
  if ( PropertySet )
  {
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&name, "archetypes");
    v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, &name, DEPTH_RECURSE);
    v2 = v1;
    if ( v1 )
    {
      mNumElements = v1->mNumElements;
      for ( i = 0; i < mNumElements; ++i )
      {
        v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v2, i);
        v6 = (UFG::qSymbolUC *)v5;
        if ( v5 )
        {
          v7 = UFG::PropertySetManager::GetPropertySet(v5);
          if ( v7 )
          {
            size = UFG::PedFormationManagerComponent::s_ProfilePool.size;
            if ( UFG::PedFormationManagerComponent::s_ProfilePool.size >= 0x10 )
            {
              v10 = UFG::qSymbol::as_cstr_dbg(v6);
              UFG::qPrintf(
                "WARNING: PedFormationManagerComponent::StaticInit: Pool is Full (%d) Not Adding (%s)\n",
                16i64,
                v10);
            }
            else
            {
              ++UFG::PedFormationManagerComponent::s_ProfilePool.size;
              v9 = &ptr + size;
              UFG::PedFormationProfile::InitFromPropertySet(v9, v7);
              UFG::qBaseTreeRB::Add(&UFG::PedFormationManagerComponent::s_Profiles.mTree, &v9->mNode);
            }
          }
          else
          {
            v11 = UFG::qSymbol::as_cstr_dbg(v6);
            UFG::qPrintf("WARNING: PedFormationManagerComponent::StaticInit: Profile Not Found: %s\n", v11);
          }
        }
      }
    }
    else
    {
      v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name);
      UFG::qPrintf("WARNING: PedFormationManagerComponent::StaticInit: Property List Not Found: %s\n", v12);
    }
  }
  else
  {
    v13 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name.p);
    UFG::qPrintf("WARNING: PedFormationManagerComponent::StaticInit: Manifest File Not Found: %s\n", v13);
  }
}

// File Line: 547
// RVA: 0x331090
void __fastcall UFG::PedFormationManagerComponent::PedFormationManagerComponent(
        UFG::PedFormationManagerComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties)
{
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent>;
  this->mNext = &this->UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PedFormationManagerComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::PedFormationManagerComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::RebindingComponentHandle<UFG::AIEntityComponent,0>(&this->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&this->m_pTargetingSystemBaseComponent);
  `eh vector constructor iterator(
    this->m_Slots.p,
    0xA0ui64,
    4,
    (void (__fastcall *)(void *))UFG::PedFormationSlot::PedFormationSlot);
  this->m_Slots.size = 0;
  this->m_CurrentlySprinting = 0;
  *(_QWORD *)&this->m_LeaderMoveType = 1i64;
  *(_QWORD *)&this->m_AngularVelocity = 0i64;
  *(_QWORD *)&this->m_FormationForward.y = 0i64;
  this->m_PrevFormationForward.y = 0.0;
  `eh vector constructor iterator(
    this->m_ProfileSlots.p,
    0x38ui64,
    9,
    (void (__fastcall *)(void *))UFG::PedFormationProfileSlot::PedFormationProfileSlot);
  this->m_ProfileSlots.size = 0;
  this->m_Pair.m_pPair.mPrev = &this->m_Pair.m_pPair;
  this->m_Pair.m_pPair.mNext = &this->m_Pair.m_pPair;
  this->m_Pair.m_pPair.m_pPointer = 0i64;
  this->m_Pair.m_PairChangeAllowedTimer.mNextTime = -1.0;
  this->m_LeaderWaitTime.mNextTime = -1.0;
  this->m_LeaderNoWaitTime.mNextTime = -1.0;
  *(_QWORD *)&this->m_Destination.x = 0i64;
  this->m_Destination.z = 0.0;
  *(_WORD *)&this->m_IsDestinationValid = 0;
  this->m_Ticket.mPrev = &this->m_Ticket;
  this->m_Ticket.mNext = &this->m_Ticket;
  this->m_Ticket.mTimestamp = 0i64;
  this->m_Ticket.mActiveCallback.m_Closure.m_pthis = 0i64;
  this->m_Ticket.mActiveCallback.m_Closure.m_pFunction = 0i64;
  this->m_Ticket.mInactiveCallback.m_Closure.m_pthis = 0i64;
  this->m_Ticket.mInactiveCallback.m_Closure.m_pFunction = 0i64;
  mPrev = UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList.mNode.mPrev;
  UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *)&UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList;
  UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList.mNode.mPrev = &this->UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::PedFormationManagerComponent::_PedFormationManagerComponentTypeUID,
    "PedFormationManagerComponent");
  this->m_DebugDrawEnabled = 0;
  UFG::PedFormationManagerComponent::SetCurrentProfile(this, &ptr);
}

// File Line: 557
// RVA: 0x339EC0
void __fastcall UFG::PedFormationManagerComponent::~PedFormationManagerComponent(
        UFG::PedFormationManagerComponent *this)
{
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *v2; // rdi
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *mPrev; // rcx
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *mNext; // rax
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v5; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v6; // rax
  UFG::PedFormationPair *p_m_Pair; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *v12; // rcx
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *v13; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PedFormationManagerComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::PedFormationManagerComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::PedFormationManagerComponent::s_PedFormationManagerComponentpCurrentIterator )
    UFG::PedFormationManagerComponent::s_PedFormationManagerComponentpCurrentIterator = (UFG::PedFormationManagerComponent *)&this->mPrev[-5].mNext;
  v2 = &this->UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = this->m_Ticket.mPrev;
  v6 = this->m_Ticket.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->m_Ticket.mPrev = &this->m_Ticket;
  this->m_Ticket.mNext = &this->m_Ticket;
  p_m_Pair = &this->m_Pair;
  if ( this->m_Pair.m_pPair.m_pPointer )
  {
    v8 = p_m_Pair->m_pPair.mPrev;
    v9 = this->m_Pair.m_pPair.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_Pair->m_pPair.mPrev = &p_m_Pair->m_pPair;
    this->m_Pair.m_pPair.mNext = &this->m_Pair.m_pPair;
  }
  this->m_Pair.m_pPair.m_pPointer = 0i64;
  v10 = p_m_Pair->m_pPair.mPrev;
  v11 = this->m_Pair.m_pPair.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_Pair->m_pPair.mPrev = &p_m_Pair->m_pPair;
  this->m_Pair.m_pPair.mNext = &this->m_Pair.m_pPair;
  this->m_ProfileSlots.size = 0;
  `eh vector destructor iterator(
    this->m_ProfileSlots.p,
    0x38ui64,
    9,
    (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
  this->m_Slots.size = 0;
  `eh vector destructor iterator(
    this->m_Slots.p,
    0xA0ui64,
    4,
    (void (__fastcall *)(void *))UFG::PedFormationSlot::~PedFormationSlot);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->m_pTransformNodeComponent);
  v12 = v2->mPrev;
  v13 = v2->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 574
// RVA: 0x37F190
UFG::PedFormationManagerComponent *__fastcall UFG::PedFormationManagerComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x650ui64, "PedFormationManagerComponent", 0i64, 1u);
  if ( v4 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::PedFormationManagerComponent::PedFormationManagerComponent(
      (UFG::PedFormationManagerComponent *)v4,
      pSceneObj->m_NameUID,
      mpWritableProperties);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v9 = 33;
  else
    v9 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v7, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return (UFG::PedFormationManagerComponent *)v7;
}

// File Line: 582
// RVA: 0x385370
void __fastcall UFG::PedFormationManagerComponent::SetCurrentProfile(
        UFG::PedFormationManagerComponent *this,
        UFG::PedFormationProfile *pCurrentProfile)
{
  unsigned int mMaxFollowers; // eax
  unsigned int i; // edi
  unsigned int v6; // r8d
  unsigned int size; // ecx
  UFG::PedFormationProfile::Slot *v8; // r9
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v9; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v13; // rcx

  UFG::PedFormationManagerComponent::Clear(this);
  if ( this->m_pCurrentProfile != pCurrentProfile )
  {
    this->m_pCurrentProfile = pCurrentProfile;
    if ( pCurrentProfile )
    {
      mMaxFollowers = pCurrentProfile->mMaxFollowers;
      this->m_Slots.size = mMaxFollowers;
      for ( i = 0; i < this->m_Slots.size; ++i )
        UFG::PedFormationSlot::InitWithDefaults(&this->m_Slots.p[i], this);
      v6 = 0;
      size = this->m_pCurrentProfile->mSlots.size;
      this->m_ProfileSlots.size = size;
      if ( size )
      {
        do
        {
          v8 = &this->m_pCurrentProfile->mSlots.p[v6];
          v9 = &(&this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr)[7 * v6];
          v10 = (UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *)(v9 + 125);
          if ( v9[127] )
          {
            mPrev = v10->mPrev;
            v12 = v9[126];
            mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *)v12;
            v12->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))mPrev;
            v10->mPrev = v10;
            v9[126] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)(v9 + 125);
          }
          v9[127] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v8;
          if ( v8 )
          {
            v13 = v8->m_SafePointerList.mNode.mPrev;
            v13->mNext = v10;
            v10->mPrev = v13;
            v9[126] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&v8->m_SafePointerList;
            v8->m_SafePointerList.mNode.mPrev = v10;
          }
          ++v6;
          v9[128] = 0i64;
        }
        while ( v6 < this->m_ProfileSlots.size );
      }
    }
  }
}

// File Line: 608
// RVA: 0x382EF0
void __fastcall UFG::PedFormationManagerComponent::Reset(UFG::PedFormationManagerComponent *this)
{
  UFG::PedFormationManagerComponent::SetCurrentProfile(this, &ptr);
}

// File Line: 613
// RVA: 0x34EBF0
void __fastcall UFG::PedFormationManagerComponent::Clear(UFG::PedFormationManagerComponent *this)
{
  unsigned int i; // edi
  unsigned int j; // r8d
  UFG::PedFormationProfileSlot *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *mNext; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::PedFormationPair *p_m_Pair; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax

  *(_QWORD *)&this->m_NumFreeSlots = 0i64;
  for ( i = 0; i < this->m_Slots.size; ++i )
    UFG::PedFormationSlot::InitWithDefaults(&this->m_Slots.p[i], this);
  this->m_Slots.size = 0;
  for ( j = 0; j < this->m_ProfileSlots.size; *(_QWORD *)&v4->mForwardClearance = 0i64 )
  {
    v4 = &this->m_ProfileSlots.p[j];
    if ( v4->mProfileSlot.m_pPointer )
    {
      mPrev = v4->mProfileSlot.mPrev;
      mNext = v4->mProfileSlot.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v4->mProfileSlot.mPrev = &v4->mProfileSlot;
      v4->mProfileSlot.mNext = &v4->mProfileSlot;
    }
    v4->mProfileSlot.m_pPointer = 0i64;
    v4->mMemberSlot = 0i64;
    *(_WORD *)&v4->mIsClear = 0;
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    ++j;
    v4->mOffset.x = UFG::qVector3::msZero.x;
    v4->mOffset.y = y;
    v4->mOffset.z = z;
  }
  this->m_ProfileSlots.size = 0;
  this->m_pCurrentProfile = 0i64;
  p_m_Pair = &this->m_Pair;
  if ( p_m_Pair->m_pPair.m_pPointer )
  {
    v10 = p_m_Pair->m_pPair.mPrev;
    v11 = p_m_Pair->m_pPair.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    p_m_Pair->m_pPair.mPrev = &p_m_Pair->m_pPair;
    p_m_Pair->m_pPair.mNext = &p_m_Pair->m_pPair;
  }
  p_m_Pair->m_pPair.m_pPointer = 0i64;
  p_m_Pair->m_PairChangeAllowedTimer.mNextTime = -1.0;
}

// File Line: 635
// RVA: 0x3790C0
void __fastcall UFG::PedFormationManagerComponent::OnAttach(
        UFG::PedFormationManagerComponent *this,
        UFG::SimObjectCharacter *object)
{
  fastdelegate::FastDelegate1<float,void> v4; // [rsp+20h] [rbp-18h] BYREF

  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pTransformNodeComponent,
    object);
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pAIEntityComponent,
    object);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pActionTreeComponent,
    object);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pTargetingSystemBaseComponent,
    object);
  v4.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::PedFormationManagerComponent::UpdatePeriodic;
  v4.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::TicketBoothManager::Register(UFG::TicketBoothManager::mpSingleton, 8, &this->m_Ticket, &v4);
}

// File Line: 646
// RVA: 0x37AE80
void __fastcall UFG::PedFormationManagerComponent::OnDetach(UFG::PedFormationManagerComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_m_pTransformNodeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax

  UFG::TicketBoothManager::Unregister(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_PEDFORMATIONMANANGER_UPDATE,
    &this->m_Ticket);
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mNext = this->m_pTransformNodeComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->m_pTransformNodeComponent.m_pSimObject = 0i64;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    goto LABEL_8;
  }
  if ( this->m_pTransformNodeComponent.m_pSimObject
    && (p_m_pTransformNodeComponent->mPrev != p_m_pTransformNodeComponent
     || this->m_pTransformNodeComponent.mNext != &this->m_pTransformNodeComponent) )
  {
    v5 = p_m_pTransformNodeComponent->mPrev;
    v6 = this->m_pTransformNodeComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pTransformNodeComponent.m_Changed = 1;
  if ( this->m_pAIEntityComponent.m_pSimComponent )
  {
    v8 = p_m_pAIEntityComponent->mPrev;
    v9 = this->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->m_pAIEntityComponent.m_pSimObject = 0i64;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    goto LABEL_15;
  }
  if ( this->m_pAIEntityComponent.m_pSimObject
    && (p_m_pAIEntityComponent->mPrev != p_m_pAIEntityComponent
     || this->m_pAIEntityComponent.mNext != &this->m_pAIEntityComponent) )
  {
    v10 = p_m_pAIEntityComponent->mPrev;
    v11 = this->m_pAIEntityComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->m_pAIEntityComponent.m_Changed = 1;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pSimComponent )
  {
    v13 = p_m_pActionTreeComponent->mPrev;
    v14 = this->m_pActionTreeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->m_pActionTreeComponent.m_pSimObject = 0i64;
    this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    goto LABEL_22;
  }
  if ( this->m_pActionTreeComponent.m_pSimObject
    && (p_m_pActionTreeComponent->mPrev != p_m_pActionTreeComponent
     || this->m_pActionTreeComponent.mNext != &this->m_pActionTreeComponent) )
  {
    v15 = p_m_pActionTreeComponent->mPrev;
    v16 = this->m_pActionTreeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->m_pActionTreeComponent.m_Changed = 1;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v18 = p_m_pTargetingSystemBaseComponent->mPrev;
    v19 = this->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    goto LABEL_29;
  }
  if ( this->m_pTargetingSystemBaseComponent.m_pSimObject
    && (p_m_pTargetingSystemBaseComponent->mPrev != p_m_pTargetingSystemBaseComponent
     || this->m_pTargetingSystemBaseComponent.mNext != &this->m_pTargetingSystemBaseComponent) )
  {
    v20 = p_m_pTargetingSystemBaseComponent->mPrev;
    v21 = this->m_pTargetingSystemBaseComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  this->m_pTargetingSystemBaseComponent.m_Changed = 1;
  UFG::PedFormationManagerComponent::Clear(this);
}

// File Line: 669
// RVA: 0x3982B0
void __fastcall UFG::PedFormationManagerComponent::UpdateProfileSlots(UFG::PedFormationManagerComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  UFG::HavokNavPosition *p_mNext; // r15
  unsigned int i; // ebp
  __int64 v7; // rsi
  UFG::PedFormationProfile::Slot *m_pPointer; // rax
  __m128 x_low; // xmm3
  float y; // xmm4_4
  UFG::TransformNodeComponent *m_pSimComponent; // rcx
  __m128 v12; // xmm1
  float v13; // xmm2_4
  UFG::PedFormationProfile::Slot *v14; // rbx
  float z; // xmm8_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  UFG::qVector3 *p_mOffset; // r14
  float v20; // xmm4_4
  float mMinDistance; // xmm0_4
  bool v22; // al
  UFG::TransformNodeComponent *v23; // rbx
  unsigned int m_packedKey; // eax
  float x; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  UFG::qVector3 direction; // [rsp+30h] [rbp-118h] BYREF
  UFG::HavokNavPosition npStartPos; // [rsp+40h] [rbp-108h] BYREF

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[36].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::NavComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::NavComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    if ( m_pComponent )
    {
      p_mNext = (UFG::HavokNavPosition *)&m_pComponent[1].m_SafePointerList.mNode.mNext;
      for ( i = 0; i < this->m_ProfileSlots.size; ++i )
      {
        v7 = i;
        m_pPointer = this->m_ProfileSlots.p[v7].mProfileSlot.m_pPointer;
        if ( m_pPointer )
        {
          x_low = (__m128)LODWORD(this->m_FormationForward.x);
          y = this->m_FormationForward.y;
          m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
          v12 = x_low;
          v12.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y);
          v13 = m_pPointer->mMaxLookAhead / _mm_sqrt_ps(v12).m128_f32[0];
          direction.z = v13 * 0.0;
          direction.x = x_low.m128_f32[0] * v13;
          direction.y = y * v13;
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
          v14 = this->m_ProfileSlots.p[v7].mProfileSlot.m_pPointer;
          z = UFG::qVector3::msZero.z;
          v16 = (float)((float)(unsigned __int16)(v14->mAngle
                                                + (int)(float)((float)(atan2f(
                                                                         this->m_FormationForward.y,
                                                                         this->m_FormationForward.x)
                                                                     * 32768.0)
                                                             * 0.31830987))
                      * 3.1415927)
              * 0.000030517578;
          v17 = sinf(v16);
          v18 = cosf(v16);
          p_mOffset = &this->m_ProfileSlots.p[v7].mOffset;
          v20 = v14->mMaxDistance / fsqrt((float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(z * z));
          p_mOffset->x = v18 * v20;
          p_mOffset->y = v17 * v20;
          p_mOffset->z = z * v20;
          if ( this->m_NumFollowers < this->m_ProfileSlots.p[v7].mProfileSlot.m_pPointer->mMinFollowers )
          {
            *(_WORD *)&this->m_ProfileSlots.p[v7].mIsClear = 0;
            *(_QWORD *)&this->m_ProfileSlots.p[v7].mForwardClearance = 0i64;
          }
          else
          {
            this->m_ProfileSlots.p[v7].mIsEnabled = 1;
            UFG::PedFormationManagerComponent::DirectionIsClear(
              this,
              p_mNext,
              &this->m_ProfileSlots.p[v7].mOffset,
              &this->m_ProfileSlots.p[v7].mClearDistance,
              eCONSTRAIN_TO_SIDEWALKS_YES);
            mMinDistance = this->m_ProfileSlots.p[v7].mProfileSlot.m_pPointer->mMinDistance;
            this->m_ProfileSlots.p[v7].mForwardClearance = 0.0;
            v22 = (float)(mMinDistance - 0.0099999998) <= this->m_ProfileSlots.p[v7].mClearDistance;
            this->m_ProfileSlots.p[v7].mIsClear = v22;
            if ( v22 )
            {
              v23 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(v23);
              m_packedKey = p_mNext->m_packedKey;
              x = v23->mWorldTransform.v3.x;
              v26 = v23->mWorldTransform.v3.y;
              v27 = v23->mWorldTransform.v3.z;
              npStartPos.m_hkvMeshPosition = p_mNext->m_hkvMeshPosition;
              npStartPos.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
              npStartPos.m_packedKey = m_packedKey;
              npStartPos.m_aiMeshUid = -1;
              v28 = x + p_mOffset->x;
              v29 = v26 + p_mOffset->y;
              v30 = v27 + p_mOffset->z;
              npStartPos.m_bValid = 0;
              npStartPos.m_vPosition.x = v28;
              npStartPos.m_vPosition.y = v29;
              npStartPos.m_vPosition.z = v30;
              UFG::HavokNavPosition::Validate(
                &npStartPos,
                COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
                COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
                0.0);
              UFG::PedFormationManagerComponent::DirectionIsClear(
                this,
                &npStartPos,
                &direction,
                &this->m_ProfileSlots.p[v7].mForwardClearance,
                eCONSTRAIN_TO_SIDEWALKS_NO);
            }
          }
        }
      }
    }
  }
}

// File Line: 720
// RVA: 0x3917F0
void __fastcall UFG::PedFormationManagerComponent::Update(UFG::PedFormationManagerComponent *this, float delta_sec)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::PedFormationProfile *v5; // rdx

  mNext = this->m_pTransformNodeComponent.mNext;
  if ( mNext )
  {
    mPrev = mNext[60].mPrev;
    if ( mPrev )
    {
      v5 = (UFG::PedFormationProfile *)mPrev[14].mPrev;
      if ( v5 )
      {
        if ( v5 != *(UFG::PedFormationProfile **)&this->m_Slots.p[3].m_TimeGotIntoPosition )
          UFG::PedFormationManagerComponent::SetCurrentProfile(
            (UFG::PedFormationManagerComponent *)((char *)this - 64),
            v5);
      }
    }
  }
  if ( *(_QWORD *)&this->m_Slots.p[3].m_TimeGotIntoPosition )
  {
    UFG::PedFormationManagerComponent::UpdateSpeed((UFG::PedFormationManagerComponent *)((char *)this - 64), delta_sec);
    UFG::PedFormationManagerComponent::CheckIfSprinting((UFG::PedFormationManagerComponent *)((char *)this - 64));
  }
}

// File Line: 731
// RVA: 0x397F60
void __fastcall UFG::PedFormationManagerComponent::UpdatePeriodic(
        UFG::PedFormationManagerComponent *this,
        float delta_sec)
{
  unsigned int size; // edx
  UFG::GetInPedFormationNode **p_m_pPointer; // rax
  __int64 v5; // rcx

  if ( (this->m_Flags & 2) == 0 && this->m_pCurrentProfile )
  {
    UFG::PedFormationManagerComponent::UnregisterIncorrectlyRegisteredPeople(this);
    UFG::PedFormationManagerComponent::UnregisterInvalidFollowers(this);
    size = this->m_Slots.size;
    *(_QWORD *)&this->m_NumFreeSlots = 0i64;
    if ( size )
    {
      p_m_pPointer = &this->m_Slots.p[0].m_pMember.m_pPointer;
      v5 = size;
      do
      {
        if ( *p_m_pPointer )
          ++this->m_NumFollowers;
        else
          ++this->m_NumFreeSlots;
        p_m_pPointer += 20;
        --v5;
      }
      while ( v5 );
    }
    if ( this->m_pCurrentProfile->mIsActive )
    {
      if ( size )
      {
        UFG::PedFormationManagerComponent::UpdateProfileSlots(this);
        UFG::PedFormationManagerComponent::UpdateDesiredFacing(this);
        UFG::PedFormationManagerComponent::CheckIfInDesiredPosition(this);
        UFG::PedFormationManagerComponent::MaybeSetDesiredPositionFromProfile(this);
        UFG::PedFormationManagerComponent::UpdatePairs(this);
      }
    }
  }
}

// File Line: 757
// RVA: 0x398D80
void __fastcall UFG::PedFormationManagerComponent::UpdateSpeed(
        UFG::PedFormationManagerComponent *this,
        float delta_sec)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  __m128 vfptr_high; // xmm2
  UFG::SimComponent *v6; // rbx
  float v7; // xmm1_4
  UFG::SimObject *m_pSimObject; // r8
  UFG::NavComponent *m_pComponent; // rsi
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v12; // zf
  UFG::SimObjectGame *v13; // rcx
  UFG::NavModuleLocal *m_pNavModuleLocal; // rbx
  UFG::qVector4 *CurrentPosition; // rax
  float v16; // xmm3_4
  float v17; // xmm4_4
  __m128 z_low; // xmm1
  float v19; // xmm2_4
  int v20; // xmm0_4
  float v21; // xmm2_4
  float y; // xmm2_4
  float x; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  double v26; // xmm0_8
  float v27; // xmm0_4
  UFG::qVector3 n2; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 n1; // [rsp+2Ch] [rbp-3Ch] BYREF

  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    vfptr_high = (__m128)HIDWORD(m_pSimComponent[4].vfptr);
    vfptr_high.m128_f32[0] = (float)(vfptr_high.m128_f32[0] * vfptr_high.m128_f32[0])
                           + (float)(*(float *)&m_pSimComponent[4].vfptr * *(float *)&m_pSimComponent[4].vfptr);
    LODWORD(this->m_Speed) = _mm_sqrt_ps(vfptr_high).m128_u32[0];
    v6 = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6);
    v7 = *((float *)&v6[2].vfptr + 1);
    this->m_FormationForward.x = *(float *)&v6[2].vfptr;
    this->m_FormationForward.y = v7;
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::NavComponent *)m_pSimObject->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)this->m_pSimObject,
                                UFG::NavComponent::_TypeUID);
        }
        else
        {
          v12 = (m_Flags & 0x1000) == 0;
          v13 = (UFG::SimObjectGame *)this->m_pSimObject;
          if ( v12 )
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v13, UFG::NavComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::NavComponent::_TypeUID);
        }
        m_pComponent = (UFG::NavComponent *)ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    if ( UFG::NavComponent::HasDestination(m_pComponent) )
    {
      m_pNavModuleLocal = m_pComponent->m_pNavModuleLocal;
      CurrentPosition = UFG::NavComponent::GetCurrentPosition(m_pComponent);
      z_low = (__m128)LODWORD(m_pNavModuleLocal->m_adjustedWaypoint.m_navPosition.m_vPosition.z);
      v16 = m_pNavModuleLocal->m_adjustedWaypoint.m_navPosition.m_vPosition.x - CurrentPosition->x;
      v17 = m_pNavModuleLocal->m_adjustedWaypoint.m_navPosition.m_vPosition.y - CurrentPosition->y;
      z_low.m128_f32[0] = z_low.m128_f32[0] - CurrentPosition->z;
      v19 = (float)(v17 * v17) + (float)(v16 * v16);
      *(float *)&v20 = v19;
      if ( v19 < 0.0 )
        v20 = LODWORD(v19) ^ _xmm[0];
      if ( *(float *)&v20 >= 0.001 )
      {
        z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + v19;
        if ( z_low.m128_f32[0] == 0.0 )
          v21 = 0.0;
        else
          v21 = 1.0 / _mm_sqrt_ps(z_low).m128_f32[0];
        this->m_FormationForward.x = v16 * v21;
        this->m_FormationForward.y = v17 * v21;
      }
    }
    y = this->m_PrevFormationForward.y;
    x = this->m_PrevFormationForward.x;
    if ( (float)((float)(x * x) + (float)(y * y)) > 0.0 )
    {
      v24 = this->m_FormationForward.x;
      v25 = this->m_FormationForward.y;
      n2.z = 0.0;
      n1.z = 0.0;
      n1.x = v24;
      n1.y = v25;
      n2.x = x;
      n2.y = y;
      v26 = UFG::qAngleBetweenNormals(&n1, &n2);
      this->m_AngularVelocity = COERCE_FLOAT(LODWORD(v26) & _xmm) * delta_sec;
    }
    v27 = this->m_FormationForward.y;
    this->m_PrevFormationForward.x = this->m_FormationForward.x;
    this->m_PrevFormationForward.y = v27;
  }
}

// File Line: 789
// RVA: 0x34DD90
void __fastcall UFG::PedFormationManagerComponent::CheckIfSprinting(UFG::PedFormationManagerComponent *this)
{
  UFG::PedFormationProfile *m_pCurrentProfile; // rax
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  unsigned int v5; // edi
  UFG::AICharacterControllerBaseComponent *v6; // rdx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  unsigned __int64 v9; // rax
  bool v10; // r8
  unsigned __int64 v11; // rax
  UFG::eMoveType m_LeaderMoveType; // eax
  __int64 v13; // rcx
  UFG::eMoveType v14; // eax
  UFG::PedFormationTimer *p_m_ReactionTimer; // rcx

  m_pCurrentProfile = this->m_pCurrentProfile;
  if ( m_pCurrentProfile )
  {
    if ( m_pCurrentProfile->mIsActive )
    {
      if ( this->m_Slots.size )
      {
        m_pSimComponent = this->m_pActionTreeComponent.m_pSimComponent;
        if ( m_pSimComponent )
        {
          m_pSimObject = (UFG::SimObjectCVBase *)m_pSimComponent->m_pSimObject;
          v5 = 0;
          if ( m_pSimObject )
          {
            m_Flags = m_pSimObject->m_Flags;
            if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
            {
              ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pSimObject);
            }
            else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            {
              ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                               m_pSimObject,
                                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
            }
            else
            {
              ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                               m_pSimObject,
                                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
            }
            v6 = ComponentOfTypeHK;
          }
          else
          {
            v6 = 0i64;
          }
          v9 = v6->m_Intention.mActionRequests.mBits[(__int64)(int)gActionRequest_Jog.m_EnumValue >> 6];
          v10 = _bittest64((const __int64 *)&v9, gActionRequest_Jog.m_EnumValue & 0x3F) != 0;
          v11 = v6->m_Intention.mActionRequests.mBits[(__int64)(int)gActionRequest_Sprint.m_EnumValue >> 6];
          LOBYTE(v11) = _bittest64((const __int64 *)&v11, gActionRequest_Sprint.m_EnumValue & 0x3F) != 0;
          this->m_CurrentlySprinting = v11;
          this->m_LeaderMoveType = eMoveType_Walk;
          if ( (_BYTE)v11 )
          {
            this->m_LeaderMoveType = eMoveType_Run;
          }
          else
          {
            m_LeaderMoveType = this->m_LeaderMoveType;
            if ( v10 )
              m_LeaderMoveType = eMoveType_Jog;
            this->m_LeaderMoveType = m_LeaderMoveType;
          }
          if ( this->m_Slots.size )
          {
            do
            {
              v13 = v5;
              if ( this->m_Slots.p[v13].m_pMember.m_pPointer )
              {
                v14 = this->m_LeaderMoveType;
                if ( v14 > this->m_Slots.p[v13].m_DesiredMoveType )
                {
                  this->m_Slots.p[v13].m_NextMoveType = v14;
                  p_m_ReactionTimer = &this->m_Slots.p[v13].m_ReactionTimer;
                  if ( p_m_ReactionTimer->mNextTime < 0.0 )
                    UFG::PedFormationTimer::Set(p_m_ReactionTimer, unk_14206D788, aFff[0]);
                }
              }
              ++v5;
            }
            while ( v5 < this->m_Slots.size );
          }
        }
      }
    }
  }
}

// File Line: 836
// RVA: 0x38AB80
void __fastcall UFG::PedFormationManagerComponent::UnregisterIncorrectlyRegisteredPeople(
        UFG::PedFormationManagerComponent *this)
{
  __int64 i; // rbx
  UFG::GetInPedFormationNode *m_pPointer; // rax

  for ( i = 0i64; (unsigned int)i < this->m_Slots.size; i = (unsigned int)(i + 1) )
  {
    m_pPointer = this->m_Slots.p[i].m_pMember.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer->m_SlotIndex != (_DWORD)i )
        UFG::PedFormationManagerComponent::UnregisterSlot(this, i);
    }
  }
}

// File Line: 857
// RVA: 0x38ABE0
void __fastcall UFG::PedFormationManagerComponent::UnregisterInvalidFollowers(UFG::PedFormationManagerComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // r14
  __int64 i; // rsi
  UFG::GetInPedFormationNode *m_pPointer; // rbp
  __int64 j; // rbx
  UFG::GetInPedFormationNode *v7; // rax

  m_pSimComponent = this->m_pAIEntityComponent.m_pSimComponent;
  vfptr = 0i64;
  if ( m_pSimComponent )
  {
    vfptr = m_pSimComponent[15].vfptr;
    if ( vfptr )
      UFG::GroupComponent::UnregisterFarFollowers(
        (UFG::GroupComponent *)m_pSimComponent[15].vfptr,
        PedFormationTuning::sDefault.mMaxTetherDistanceSqr);
  }
  for ( i = 0i64; (unsigned int)i < this->m_Slots.size; i = (unsigned int)(i + 1) )
  {
    if ( this->m_Slots.p[i].m_pMember.m_pPointer )
    {
      if ( !((unsigned __int8 (__fastcall *)(UFG::PedFormationManagerComponent *, UFG::qSafePointerNode<UFG::SimComponent>Vtbl *, _QWORD))this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
              this,
              vfptr,
              (unsigned int)i) )
      {
        m_pPointer = this->m_Slots.p[i].m_pMember.m_pPointer;
        for ( j = 0i64; (unsigned int)j < this->m_Slots.size; j = (unsigned int)(j + 1) )
        {
          v7 = this->m_Slots.p[j].m_pMember.m_pPointer;
          if ( v7 )
          {
            if ( m_pPointer == v7 )
              UFG::PedFormationManagerComponent::UnregisterSlot(this, j);
          }
        }
      }
    }
  }
}

// File Line: 905
// RVA: 0x37C2B0
bool __fastcall UFG::PedFormationManagerComponent::PedFormationSlotIsOccupied(
        UFG::PedFormationManagerComponent *this,
        UFG::GroupComponent *pGC,
        unsigned int slot_index)
{
  char *v4; // rdi
  __int64 v5; // rcx
  __int64 v6; // rax
  unsigned int v7; // ebx
  bool v8; // bp
  __int64 v9; // rax
  UFG::HealthComponent *v10; // rdx
  UFG::ActionTreeComponent *v11; // rcx
  __int64 v12; // rcx
  UFG::ActionTreeComponent *v13; // rcx
  bool v14; // r8
  __int64 v15; // rax
  UFG::GroupComponent *v16; // rcx
  unsigned int size; // edx
  UFG::GroupComponent **p_m_pPointer; // rax
  char v19; // al

  v4 = (char *)this + 160 * slot_index;
  v5 = *((_QWORD *)v4 + 45);
  if ( !v5 )
    return 0;
  v6 = *(_QWORD *)(v5 + 88);
  v7 = 0;
  v8 = v6 && *(_QWORD *)(v6 + 120) && (*(_BYTE *)(*(_QWORD *)(v6 + 120) + 32i64) & 3) == 1;
  v9 = *(_QWORD *)(v5 + 88);
  v10 = v9 ? *(UFG::HealthComponent **)(v9 + 216) : 0i64;
  v11 = v9 ? *(UFG::ActionTreeComponent **)(v9 + 168) : 0i64;
  v14 = 0;
  if ( !UFG::IsDowned(v11, v10) )
  {
    v12 = *(_QWORD *)(*((_QWORD *)v4 + 45) + 88i64);
    v13 = v12 ? *(UFG::ActionTreeComponent **)(v12 + 168) : 0i64;
    if ( !UFG::IsStunned(v13) )
      v14 = 1;
  }
  v15 = *(_QWORD *)(*((_QWORD *)v4 + 45) + 88i64);
  if ( v15
    && *(_QWORD *)(v15 + 120)
    && pGC
    && (v16 = *(UFG::GroupComponent **)(*(_QWORD *)(v15 + 120) + 960i64)) != 0i64
    && (size = pGC->mGroupLeader.mFollowers.size) != 0 )
  {
    p_m_pPointer = &pGC->mGroupLeader.mFollowers.p[0].m_pPointer;
    while ( v16 != *p_m_pPointer )
    {
      ++v7;
      p_m_pPointer += 3;
      if ( v7 >= size )
        goto LABEL_28;
    }
    v19 = 1;
  }
  else
  {
LABEL_28:
    v19 = 0;
  }
  return v8 && v14 && v19;
}

// File Line: 934
// RVA: 0x395190
void __fastcall UFG::PedFormationManagerComponent::UpdateDesiredFacing(UFG::PedFormationManagerComponent *this)
{
  float v2; // xmm8_4
  float v3; // xmm7_4
  float v4; // xmm9_4
  float x; // xmm10_4
  float y; // xmm11_4
  UFG::SimComponent *m_pSimComponent; // rbx
  UFG::TransformNodeComponent *v8; // rbx
  __int64 i; // rbp
  __int64 v10; // rbx
  UFG::GetInPedFormationNode *m_pPointer; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4

  v2 = 0.0;
  v3 = *(float *)&FLOAT_1_0;
  v4 = 0.0;
  x = 0.0;
  y = 0.0;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    v3 = *(float *)&m_pSimComponent[2].vfptr;
    v2 = *((float *)&m_pSimComponent[2].vfptr + 1);
    v4 = *(float *)&m_pSimComponent[2].m_SafePointerList.mNode.mPrev;
    v8 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v8);
    x = v8->mWorldTransform.v3.x;
    y = v8->mWorldTransform.v3.y;
  }
  for ( i = 0i64; (unsigned int)i < this->m_Slots.size; i = (unsigned int)(i + 1) )
  {
    v10 = i;
    m_pPointer = this->m_Slots.p[i].m_pMember.m_pPointer;
    if ( m_pPointer )
    {
      if ( this->m_Slots.p[v10].m_pProfileSlot->mFacingType == ePedFormationFacingType_Leader_Direction )
      {
        this->m_Slots.p[v10].m_FacingDirection.x = v3;
        this->m_Slots.p[v10].m_FacingDirection.y = v2;
        this->m_Slots.p[v10].m_FacingDirection.z = v4;
      }
      else if ( this->m_Slots.p[v10].m_pProfileSlot->mFacingType == ePedFormationFacingType_Centre )
      {
        v12 = m_pPointer->m_pOwner.m_pPointer;
        if ( v12 )
        {
          m_pSimObject = v12->m_pSimObject;
          if ( m_pSimObject )
          {
            if ( m_pSimObject->m_pTransformNodeComponent )
            {
              m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              v15 = x - m_pTransformNodeComponent->mWorldTransform.v3.x;
              v16 = y - m_pTransformNodeComponent->mWorldTransform.v3.y;
              v17 = fsqrt((float)(v16 * v16) + (float)(v15 * v15));
              if ( v17 > 0.001 )
              {
                this->m_Slots.p[v10].m_FacingDirection.z = (float)(1.0 / v17) * 0.0;
                this->m_Slots.p[v10].m_FacingDirection.x = (float)(1.0 / v17) * v15;
                this->m_Slots.p[v10].m_FacingDirection.y = (float)(1.0 / v17) * v16;
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 1004
// RVA: 0x3974F0
void __fastcall UFG::PedFormationManagerComponent::UpdatePairs(UFG::PedFormationManagerComponent *this)
{
  float mSimTime_Temp; // xmm6_4
  __int64 v3; // rdi
  UFG::SimComponent *m_pSimComponent; // rbx
  float v5; // xmm1_4
  float v6; // xmm2_4
  __int64 i; // rbp
  UFG::GetInPedFormationNode *m_pPointer; // rax
  UFG::SimComponent *v9; // rcx
  UFG::TransformNodeComponent *m_pSimObject; // rdi
  UFG::SimObject *v11; // r15
  __int64 v12; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  unsigned int v15; // r9d
  unsigned int size; // r11d
  float *p_m_pMyPair; // r10
  UFG::SimObject *m_pMe; // r8
  float v19; // xmm2_4
  float v20; // xmm0_4
  unsigned int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float *v25; // rdx
  __int64 v26; // rcx
  _QWORD *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::qFixedArray<PedFormationPairing,10> v29; // [rsp+30h] [rbp-178h] BYREF

  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::qFixedArray<PedFormationPairing,10>::qFixedArray<PedFormationPairing,10>(&v29);
    v3 = v29.size++;
    m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    v29.p[v3].m_pMe = this->m_pSimObject;
    v29.p[v3].m_pMyPair = &this->m_Pair;
    v5 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v6 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
    v29.p[v3].m_MyPosition.x = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    v29.p[v3].m_MyPosition.y = v5;
    v29.p[v3].m_MyPosition.z = v6;
    for ( i = 0i64; (unsigned int)i < this->m_Slots.size; i = (unsigned int)(i + 1) )
    {
      m_pPointer = this->m_Slots.p[i].m_pMember.m_pPointer;
      if ( m_pPointer )
      {
        v9 = m_pPointer->m_pOwner.m_pPointer;
        if ( v9 )
        {
          m_pSimObject = (UFG::TransformNodeComponent *)v9->m_pSimObject;
          if ( m_pSimObject )
            m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
          if ( m_pSimObject )
          {
            v11 = v9->m_pSimObject;
            if ( v11 )
            {
              v12 = v29.size++;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
              v29.p[v12].m_pMe = v11;
              v29.p[v12].m_pMyPair = &this->m_Slots.p[i].m_Pair;
              y = m_pSimObject->mWorldTransform.v3.y;
              z = m_pSimObject->mWorldTransform.v3.z;
              v29.p[v12].m_MyPosition.x = m_pSimObject->mWorldTransform.v3.x;
              v29.p[v12].m_MyPosition.y = y;
              v29.p[v12].m_MyPosition.z = z;
            }
          }
        }
      }
    }
    v15 = 0;
    size = v29.size;
    if ( v29.size )
    {
      p_m_pMyPair = (float *)&v29.p[0].m_pMyPair;
      do
      {
        m_pMe = 0i64;
        v19 = 0.0;
        if ( *(float *)(*(_QWORD *)p_m_pMyPair + 24i64) < 0.0
          || (v20 = *(float *)(*(_QWORD *)p_m_pMyPair + 24i64), v20 > 0.0) && mSimTime_Temp >= v20 )
        {
          v21 = 0;
          do
          {
            if ( v15 != v21 )
            {
              v22 = p_m_pMyPair[3] - v29.p[v21].m_MyPosition.y;
              v23 = p_m_pMyPair[2] - v29.p[v21].m_MyPosition.x;
              v24 = (float)(v23 * v23) + (float)(v22 * v22);
              if ( !m_pMe || v24 < v19 )
              {
                v19 = v24;
                m_pMe = v29.p[v21].m_pMe;
              }
            }
            ++v21;
          }
          while ( v21 < size );
          v25 = *(float **)p_m_pMyPair;
          if ( *(_QWORD *)(*(_QWORD *)p_m_pMyPair + 16i64) )
          {
            v26 = *(_QWORD *)v25;
            v27 = (_QWORD *)*((_QWORD *)v25 + 1);
            *(_QWORD *)(v26 + 8) = v27;
            *v27 = v26;
            *(_QWORD *)v25 = v25;
            *((_QWORD *)v25 + 1) = v25;
          }
          *((_QWORD *)v25 + 2) = m_pMe;
          if ( m_pMe
            && (mPrev = m_pMe->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev,
                mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v25,
                *(_QWORD *)v25 = mPrev,
                *((_QWORD *)v25 + 1) = &m_pMe->m_SafePointerList,
                m_pMe->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v25,
                unk_14206D748 > 0.0) )
          {
            v25[6] = UFG::Metrics::msInstance.mSimTime_Temp + unk_14206D748;
          }
          else
          {
            v25[6] = -1.0;
          }
        }
        ++v15;
        p_m_pMyPair += 8;
      }
      while ( v15 < size );
    }
  }
}

// File Line: 1079
// RVA: 0x34D610
void __fastcall UFG::PedFormationManagerComponent::CheckIfInDesiredPosition(UFG::PedFormationManagerComponent *this)
{
  float mSimTime_Temp; // xmm15_4
  UFG::TransformNodeComponent *m_pSimComponent; // r15
  unsigned int i; // ebp
  UFG::PedFormationSlot *v5; // rbx
  UFG::GetInPedFormationNode *m_pPointer; // rdi
  UFG::SimComponent *v7; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *v9; // rax
  UFG::SimObject *v10; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::PedFormationProfile::Slot *m_pProfileSlot; // rax
  __m128 y_low; // xmm0
  float x; // xmm2_4
  float mMinFacingDifference; // xmm9_4
  float mMinDistance; // xmm8_4
  float v19; // xmm10_4
  float v20; // xmm11_4
  UFG::PedFormationProfile *m_pCurrentProfile; // rax
  bool v22; // r14
  float *v23; // rax
  float v24; // xmm6_4
  float max_lateral_offset; // xmm7_4
  unsigned int m_InPosition; // ecx
  float v27; // xmm6_4
  float v28; // xmm9_4
  bool v29; // al
  unsigned int v30; // edi
  float v31; // xmm0_4
  float v32; // xmm1_4
  bool v33; // r8
  bool v34; // dl
  UFG::PedFormationProfile *v35; // rax
  float mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting; // xmm0_4
  float v37; // xmm0_4
  UFG::PedFormationProfile::Slot *v38; // rcx
  char v39; // al
  UFG::qVector3 follower_position; // [rsp+40h] [rbp-E8h] BYREF
  UFG::qVector3 desired_position; // [rsp+50h] [rbp-D8h] BYREF
  float current_radial_offset; // [rsp+130h] [rbp+8h] BYREF
  float current_lateral_offset; // [rsp+138h] [rbp+10h] BYREF

  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    for ( i = 0; i < this->m_Slots.size; ++i )
    {
      v5 = &this->m_Slots.p[i];
      m_pPointer = v5->m_pMember.m_pPointer;
      if ( !m_pPointer
        || (v7 = m_pPointer->m_pOwner.m_pPointer) == 0i64
        || (m_pSimObject = v7->m_pSimObject) == 0i64
        || !m_pSimObject->m_pTransformNodeComponent
        || !UFG::PedFormationManagerComponent::GetDesiredPosition(this, v5->m_pMember.m_pPointer, &desired_position) )
      {
        if ( v5->m_InPosition != ePOSITION_NOT_IN_POSITION )
          v5->m_InPosition = ePOSITION_NOT_IN_POSITION;
        *(_WORD *)&v5->m_CurrentlyInRange = 0;
        continue;
      }
      v9 = m_pPointer->m_pOwner.m_pPointer;
      if ( v9 && (v10 = v9->m_pSimObject) != 0i64 )
        m_pTransformNodeComponent = v10->m_pTransformNodeComponent;
      else
        m_pTransformNodeComponent = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      y = m_pTransformNodeComponent->mWorldTransform.v3.y;
      z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      follower_position.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
      follower_position.y = y;
      follower_position.z = z;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      m_pProfileSlot = v5->m_pProfileSlot;
      current_lateral_offset = 0.0;
      y_low = (__m128)LODWORD(follower_position.y);
      x = m_pTransformNodeComponent->mWorldTransform.v0.x;
      current_radial_offset = 0.0;
      mMinFacingDifference = m_pProfileSlot->mMinFacingDifference;
      mMinDistance = m_pProfileSlot->mMinDistance;
      y_low.m128_f32[0] = (float)((float)(follower_position.y - m_pSimComponent->mWorldTransform.v3.y)
                                * (float)(follower_position.y - m_pSimComponent->mWorldTransform.v3.y))
                        + (float)((float)(follower_position.x - m_pSimComponent->mWorldTransform.v3.x)
                                * (float)(follower_position.x - m_pSimComponent->mWorldTransform.v3.x));
      LODWORD(v19) = _mm_sqrt_ps(y_low).m128_u32[0];
      v20 = (float)((float)(m_pTransformNodeComponent->mWorldTransform.v0.y * v5->m_FacingDirection.y)
                  + (float)(x * v5->m_FacingDirection.x))
          + (float)(m_pTransformNodeComponent->mWorldTransform.v0.z * v5->m_FacingDirection.z);
      if ( v5->m_InPosition == ePOSITION_IN_POSITION )
      {
        mMinDistance = mMinDistance - 1.0;
        if ( mMinDistance <= 0.0 )
          mMinDistance = 0.0;
      }
      m_pCurrentProfile = this->m_pCurrentProfile;
      v22 = v19 < m_pCurrentProfile->mDistanceToBeConsideredClose;
      if ( !v5->m_CurrentlyStayingClose && v19 < m_pCurrentProfile->mDistanceToBeConsideredClose )
        v5->m_TimeFinishUsingLargeHysteresis = UFG::GetRandomNumberInRange(
                                                 m_pCurrentProfile->mMinTimeForLargeHysteresis,
                                                 m_pCurrentProfile->mMaxTimeForLargeHysteresis)
                                             + mSimTime_Temp;
      v23 = (float *)v5->m_pProfileSlot;
      v24 = v23[15];
      max_lateral_offset = v23[16];
      if ( !this->m_CurrentlySprinting )
      {
        m_InPosition = v5->m_InPosition;
        if ( m_InPosition <= 1 )
        {
          if ( UFG::Metrics::msInstance.mSimTime_Temp > v5->m_TimeFinishUsingLargeHysteresis )
            v27 = v24 + v23[20];
          else
            v27 = v24 + v23[19];
          v24 = v27 + v5->m_RadialHysteresisModifier;
          max_lateral_offset = max_lateral_offset + v23[22];
        }
        else if ( m_InPosition == 4 )
        {
          v24 = v24 + v23[21];
          max_lateral_offset = max_lateral_offset + v23[23];
        }
      }
      if ( v5->m_CurrentlyFacingCorrectly )
        mMinFacingDifference = mMinFacingDifference + v23[14];
      v28 = cosf((float)(mMinFacingDifference * 3.1415927) * 0.0055555557);
      v29 = UFG::PedFormationManagerComponent::IsInPosition(
              this,
              &follower_position,
              &desired_position,
              v24,
              max_lateral_offset,
              &current_radial_offset,
              &current_lateral_offset,
              0);
      v30 = v5->m_InPosition;
      v31 = *(float *)&FLOAT_1_0;
      v32 = *(float *)&FLOAT_1_0;
      v33 = v29;
      if ( v30 <= 2 )
      {
        v31 = FLOAT_2_0;
        v32 = FLOAT_2_0;
      }
      v34 = current_radial_offset <= v31 && current_lateral_offset <= v32;
      if ( this->m_CurrentlySprinting && (v35 = this->m_pCurrentProfile) != 0i64 )
        mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = v35->mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting;
      else
        mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = (float)(v5->m_pProfileSlot->mMaxRadialDistanceFromDesiredPositionHysteresis
                                                                                         + v5->m_pProfileSlot->mMaxRadialDistanceFromDesiredPosition)
                                                                                 + 5.0;
      if ( v30 == 4 && v19 < mMinDistance )
      {
        v5->m_InPosition = ePOSITION_NOT_IN_POSITION;
      }
      else
      {
        if ( current_radial_offset >= mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting )
          goto LABEL_57;
        if ( v30 == 4 )
        {
          if ( !v33 )
          {
LABEL_57:
            if ( v30 != 4 )
              v5->m_InPosition = ePOSITION_FAR;
            goto LABEL_59;
          }
        }
        else if ( !v33 )
        {
          if ( v34 )
          {
            if ( v30 != 2 )
              v5->m_InPosition = ePOSITION_CLOSE;
          }
          else if ( v30 != 3 )
          {
            v5->m_InPosition = ePOSITION_NOT_IN_POSITION;
          }
          goto LABEL_59;
        }
        if ( UFG::PedFormationManagerComponent::IsMoving(this, 0) )
        {
          if ( v30 != 1 )
            v5->m_InPosition = ePOSITION_STAYING_IN_POSITION;
        }
        else
        {
          if ( v30 )
          {
            v37 = UFG::Metrics::msInstance.mSimTime_Temp;
            v5->m_DesiredMoveType = eMoveType_Walk;
            v5->m_TimeGotIntoPosition = v37;
            UFG::PedFormationSlot::SetRadialHysteresisModifier(v5);
          }
          if ( v5->m_InPosition )
            v5->m_InPosition = ePOSITION_IN_POSITION;
        }
      }
LABEL_59:
      v38 = v5->m_pProfileSlot;
      if ( v19 < v38->mMaxDistance || (v39 = 0, v5->m_InPosition == ePOSITION_IN_POSITION) )
        v39 = 1;
      v5->m_CurrentlyInRange = v39;
      v5->m_CurrentlyStayingClose = v22;
      v5->m_CurrentlyFacingCorrectly = v20 > v28;
      if ( v38->mFacingType == ePedFormationFacingType_None )
        v5->m_CurrentlyFacingCorrectly = 1;
    }
  }
}

// File Line: 1255
// RVA: 0x36B150
bool __fastcall UFG::PedFormationManagerComponent::IsInPosition(
        UFG::PedFormationManagerComponent *this,
        UFG::qVector3 *follower_position,
        UFG::qVector3 *desired_position,
        float max_radial_offset,
        float max_lateral_offset,
        float *current_radial_offset,
        float *current_lateral_offset,
        bool debug_print)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  float v13; // xmm7_4
  UFG::TransformNodeComponent *v14; // rbx
  float v15; // xmm7_4
  __m128 mPrev_high; // xmm6
  float v17; // xmm5_4
  __m128 y_low; // xmm3
  float v19; // xmm8_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm7_4
  float v23; // xmm6_4
  float v24; // xmm1_4
  float x; // xmm7_4
  __m128 v26; // xmm0
  float v27; // xmm6_4
  float v28; // xmm7_4
  Render::DebugDrawContext *Context; // rax

  m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
  v13 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
  mPrev_high = (__m128)HIDWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev);
  v14 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v15 = v13 - follower_position->x;
  mPrev_high.m128_f32[0] = mPrev_high.m128_f32[0] - follower_position->y;
  UFG::TransformNodeComponent::UpdateWorldTransform(v14);
  y_low = (__m128)LODWORD(follower_position->y);
  v17 = follower_position->x - desired_position->x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - desired_position->y;
  v19 = follower_position->z - desired_position->z;
  v20 = (float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]) + (float)(v15 * v15);
  if ( v20 <= 0.001 )
  {
    x = UFG::qVector3::msZero.x;
    mPrev_high = (__m128)LODWORD(UFG::qVector3::msZero.y);
  }
  else
  {
    if ( v20 == 0.0 )
      v21 = 0.0;
    else
      v21 = 1.0 / _mm_sqrt_ps(mPrev_high).m128_f32[0];
    v22 = v15 * v21;
    v23 = mPrev_high.m128_f32[0] * v21;
    v24 = (float)((float)(v23 * y_low.m128_f32[0]) + (float)(v22 * v17)) + (float)((float)(v21 * 0.0) * v19);
    x = v22 * v24;
    mPrev_high.m128_f32[0] = v23 * v24;
  }
  v26 = y_low;
  v26.m128_f32[0] = (float)(v26.m128_f32[0] - mPrev_high.m128_f32[0])
                  * (float)(v26.m128_f32[0] - mPrev_high.m128_f32[0]);
  mPrev_high.m128_f32[0] = (float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]) + (float)(x * x);
  LODWORD(v27) = _mm_sqrt_ps(mPrev_high).m128_u32[0];
  v26.m128_f32[0] = v26.m128_f32[0] + (float)((float)(v17 - x) * (float)(v17 - x));
  LODWORD(v28) = _mm_sqrt_ps(v26).m128_u32[0];
  if ( (float)((float)((float)(y_low.m128_f32[0] * (float)(v14->mWorldTransform.v3.y - desired_position->y))
                     + (float)(v17 * (float)(v14->mWorldTransform.v3.x - desired_position->x)))
             + (float)(v19 * (float)(v14->mWorldTransform.v3.z - desired_position->z))) > 0.0 )
    LODWORD(v27) ^= _xmm[0];
  if ( debug_print )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    Render::DebugDrawContext::DrawText(Context, follower_position, &UFG::qColour::White, "R: %.1f L: %.1f", v27, v28);
  }
  *current_radial_offset = v27;
  *current_lateral_offset = v28;
  return max_radial_offset > COERCE_FLOAT(LODWORD(v27) & _xmm) && max_lateral_offset > COERCE_FLOAT(LODWORD(v28) & _xmm);
}

// File Line: 1296
// RVA: 0x36B8A0
bool __fastcall UFG::PedFormationManagerComponent::IsMoving(
        UFG::PedFormationManagerComponent *this,
        bool includeTurning)
{
  return unk_14206D75C < this->m_Speed || includeTurning && unk_14206D754 < this->m_AngularVelocity;
}

// File Line: 1350
// RVA: 0x375FB0
void __fastcall UFG::PedFormationManagerComponent::MaybeSetDesiredPositionFromProfile(
        UFG::PedFormationManagerComponent *this)
{
  float mSimTime_Temp; // xmm13_4
  float v3; // xmm9_4
  __int64 v4; // rax
  UFG::PedFormationSlot *v5; // rdi
  UFG::GetInPedFormationNode *m_pPointer; // r13
  UFG::SimComponent *v7; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::PedFormationProfileSlot *v10; // r14
  char v11; // r15
  UFG::qVector3 *v12; // r12
  float v13; // xmm8_4
  float mNextTime; // xmm0_4
  unsigned int v15; // ebp
  UFG::TransformNodeComponent *v16; // r13
  UFG::PedFormationProfileSlot *v17; // rbx
  UFG::PedFormationSlot *mMemberSlot; // rax
  float v19; // xmm6_4
  float v20; // xmm7_4
  UFG::PedFormationProfile::Slot *v21; // rax
  float v22; // xmm1_4
  UFG::PedFormationProfile::Slot *v23; // rcx
  UFG::PedFormationProfile::Slot *v24; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::GetInPedFormationNode *v27; // r13
  UFG::PedFormationSlot::ePositionType m_InPosition; // ebx
  float v29; // xmm0_4
  bool v30; // zf
  float v31; // xmm1_4
  float v32; // xmm0_4
  float *m_pProfileSlot; // rax
  float v34; // xmm3_4
  float max_lateral_offset; // xmm0_4
  unsigned int v36; // ecx
  float v37; // xmm3_4
  bool v38; // al
  unsigned int v39; // ebx
  float v40; // xmm1_4
  float v41; // xmm2_4
  bool v42; // cl
  bool v43; // al
  float v44; // xmm0_4
  UFG::qVector2 follower_start; // [rsp+40h] [rbp-108h] BYREF
  UFG::TransformNodeComponent *m_pSimComponent; // [rsp+48h] [rbp-100h]
  UFG::GetInPedFormationNode *get_in_formation; // [rsp+50h] [rbp-F8h]
  UFG::qVector3 desired_direction; // [rsp+58h] [rbp-F0h] BYREF
  UFG::qVector3 desired_position; // [rsp+68h] [rbp-E0h] BYREF
  int slot_index; // [rsp+150h] [rbp+8h]
  float current_radial_offset; // [rsp+158h] [rbp+10h] BYREF
  float current_lateral_offset; // [rsp+160h] [rbp+18h] BYREF
  UFG::qVector2 follower_end; // [rsp+168h] [rbp+20h] BYREF

  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
    v3 = unk_14206D75C >= this->m_Speed ? 0.0 : unk_14206D74C;
    v4 = 0i64;
    for ( slot_index = 0; (unsigned int)v4 < this->m_Slots.size; slot_index = v4 )
    {
      v5 = &this->m_Slots.p[v4];
      m_pPointer = v5->m_pMember.m_pPointer;
      get_in_formation = m_pPointer;
      if ( m_pPointer )
      {
        v7 = m_pPointer->m_pOwner.m_pPointer;
        if ( v7 )
        {
          m_pSimObject = v7->m_pSimObject;
          if ( m_pSimObject )
          {
            if ( m_pSimObject->m_pTransformNodeComponent )
            {
              m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              v10 = 0i64;
              v11 = 0;
              v12 = (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3;
              v13 = 0.0;
              desired_direction = UFG::qVector3::msZero;
              mNextTime = v5->m_SlotChangeAllowedTimer.mNextTime;
              if ( mNextTime < 0.0 || mNextTime > 0.0 && mSimTime_Temp >= mNextTime )
                v11 = 1;
              v15 = 0;
              if ( this->m_ProfileSlots.size )
              {
                v16 = m_pSimComponent;
                do
                {
                  v17 = &this->m_ProfileSlots.p[v15];
                  mMemberSlot = v17->mMemberSlot;
                  if ( mMemberSlot == v5 || !mMemberSlot && v11 )
                  {
                    v19 = v16->mWorldTransform.v3.x + v17->mOffset.x;
                    v20 = v16->mWorldTransform.v3.y + v17->mOffset.y;
                    if ( v17->mIsClear && v3 <= v17->mForwardClearance )
                    {
                      v21 = v17->mProfileSlot.m_pPointer;
                      if ( v21 )
                      {
                        if ( v21->mCanCrossLeader
                          || (v22 = v12->y,
                              follower_start.x = v12->x,
                              follower_start.y = v22,
                              follower_end.x = v19,
                              follower_end.y = v20,
                              !UFG::PedFormationManagerComponent::CrossesLeadersPath(
                                 this,
                                 &follower_start,
                                 &follower_end)) )
                        {
                          if ( !v10
                            || (v23 = v10->mProfileSlot.m_pPointer,
                                v24 = v17->mProfileSlot.m_pPointer,
                                v23->mMinDistance >= v24->mMinDistance)
                            && v23->mPreference <= v24->mPreference
                            && (float)((float)((float)(v12->y - v20) * (float)(v12->y - v20))
                                     + (float)((float)(v12->x - v19) * (float)(v12->x - v19))) < v13 )
                          {
                            v13 = (float)((float)(v12->y - v20) * (float)(v12->y - v20))
                                + (float)((float)(v12->x - v19) * (float)(v12->x - v19));
                            y = v17->mOffset.y;
                            v10 = &this->m_ProfileSlots.p[v15];
                            desired_direction.x = v17->mOffset.x;
                            z = v17->mOffset.z;
                            desired_direction.y = y;
                            desired_direction.z = z;
                          }
                        }
                      }
                    }
                  }
                  ++v15;
                }
                while ( v15 < this->m_ProfileSlots.size );
                v27 = get_in_formation;
                if ( v10 )
                {
                  if ( v10->mMemberSlot != v5 )
                  {
                    UFG::PedFormationTimer::Set(
                      &v5->m_SlotChangeAllowedTimer,
                      this->m_pCurrentProfile->mMinTimeBetweenSlotChanges,
                      this->m_pCurrentProfile->mMinTimeBetweenSlotChanges);
                    UFG::PedFormationManagerComponent::AssignProfileSlot(this, v10, v5);
                  }
                  m_InPosition = v5->m_InPosition;
                  UFG::PedFormationManagerComponent::SetDesiredDirection(this, slot_index, v27, &desired_direction);
                  if ( v5->m_InPosition && m_InPosition == ePOSITION_IN_POSITION )
                  {
                    v29 = UFG::Metrics::msInstance.mSimTime_Temp;
                    v5->m_DesiredMoveType = eMoveType_Walk;
                    v5->m_TimeGotIntoPosition = v29;
                    UFG::PedFormationSlot::SetRadialHysteresisModifier(v5);
                  }
                  if ( v5->m_InPosition != m_InPosition )
                    v5->m_InPosition = m_InPosition;
                  v30 = !this->m_CurrentlySprinting;
                  v31 = v5->m_Direction.y;
                  current_lateral_offset = 0.0;
                  current_radial_offset = 0.0;
                  v32 = m_pSimComponent->mWorldTransform.v3.x + v5->m_Direction.x;
                  desired_position.y = v31 + m_pSimComponent->mWorldTransform.v3.y;
                  desired_position.x = v32;
                  m_pProfileSlot = (float *)v5->m_pProfileSlot;
                  v34 = m_pProfileSlot[15];
                  desired_position.z = v5->m_Direction.z + m_pSimComponent->mWorldTransform.v3.z;
                  max_lateral_offset = m_pProfileSlot[16];
                  if ( v30 )
                  {
                    v36 = v5->m_InPosition;
                    if ( v36 <= 1 )
                    {
                      if ( UFG::Metrics::msInstance.mSimTime_Temp > v5->m_TimeFinishUsingLargeHysteresis )
                        v37 = v34 + m_pProfileSlot[20];
                      else
                        v37 = v34 + m_pProfileSlot[19];
                      v34 = v37 + v5->m_RadialHysteresisModifier;
                      max_lateral_offset = max_lateral_offset + m_pProfileSlot[22];
                    }
                    else if ( v36 == 4 )
                    {
                      v34 = v34 + m_pProfileSlot[21];
                      max_lateral_offset = max_lateral_offset + m_pProfileSlot[23];
                    }
                  }
                  v38 = UFG::PedFormationManagerComponent::IsInPosition(
                          this,
                          v12,
                          &desired_position,
                          v34,
                          max_lateral_offset,
                          &current_radial_offset,
                          &current_lateral_offset,
                          0);
                  v39 = v5->m_InPosition;
                  v40 = *(float *)&FLOAT_1_0;
                  v41 = *(float *)&FLOAT_1_0;
                  v42 = v38;
                  if ( v39 <= 2 )
                  {
                    v40 = FLOAT_2_0;
                    v41 = FLOAT_2_0;
                  }
                  v43 = current_radial_offset <= v40 && current_lateral_offset <= v41;
                  if ( v42 )
                  {
                    if ( UFG::PedFormationManagerComponent::IsMoving(this, 0) )
                    {
                      if ( v39 != 1 )
                        v5->m_InPosition = ePOSITION_STAYING_IN_POSITION;
                    }
                    else
                    {
                      if ( v39 )
                      {
                        v44 = UFG::Metrics::msInstance.mSimTime_Temp;
                        v5->m_DesiredMoveType = eMoveType_Walk;
                        v5->m_TimeGotIntoPosition = v44;
                        UFG::PedFormationSlot::SetRadialHysteresisModifier(v5);
                      }
                      if ( v5->m_InPosition )
                        v5->m_InPosition = ePOSITION_IN_POSITION;
                    }
                  }
                  else if ( v43 && v39 != 2 )
                  {
                    v5->m_InPosition = ePOSITION_CLOSE;
                  }
                }
              }
            }
          }
        }
      }
      v4 = (unsigned int)(slot_index + 1);
    }
  }
}

// File Line: 1484
// RVA: 0x352A20
bool __fastcall UFG::PedFormationManagerComponent::DirectionIsClear(
        UFG::PedFormationManagerComponent *this,
        UFG::HavokNavPosition *npStartPos,
        UFG::qVector3 *direction,
        float *max_clear_distance,
        UFG::eConstrainToSidewalks constrain_to_sidewalks)
{
  __m128 x_low; // xmm6
  __m128 y_low; // xmm7
  __m128 z_low; // xmm8
  UFG::SimObjectGame *m_pSimObject; // r8
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // cx
  __int64 v13; // rax
  bool result; // al
  __m128 v15; // xmm1
  float v16; // [rsp+30h] [rbp-88h] BYREF
  float v17; // [rsp+34h] [rbp-84h]
  __int64 (__fastcall **v18)(_QWORD); // [rsp+40h] [rbp-78h] BYREF
  int v19; // [rsp+48h] [rbp-70h]
  int v20; // [rsp+4Ch] [rbp-6Ch]
  int v21; // [rsp+50h] [rbp-68h]
  char v22; // [rsp+58h] [rbp-60h]
  __m128 v23; // [rsp+60h] [rbp-58h]
  __int64 v24; // [rsp+70h] [rbp-48h]
  __int64 v25; // [rsp+C0h] [rbp+8h] BYREF

  if ( !this->m_pAIEntityComponent.m_pSimComponent )
    return 1;
  x_low = (__m128)LODWORD(direction->x);
  y_low = (__m128)LODWORD(direction->y);
  x_low.m128_f32[0] = x_low.m128_f32[0] + npStartPos->m_vPosition.x;
  z_low = (__m128)LODWORD(npStartPos->m_vPosition.z);
  y_low.m128_f32[0] = y_low.m128_f32[0] + npStartPos->m_vPosition.y;
  z_low.m128_f32[0] = z_low.m128_f32[0] + direction->z;
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[36].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::NavComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::NavComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v19 = x_low.m128_i32[0];
  v22 = 0;
  v24 = -1i64;
  v20 = y_low.m128_i32[0];
  v21 = z_low.m128_i32[0];
  v18 = &UFG::HavokNavPosition::`vftable;
  v23 = _mm_unpacklo_ps(_mm_unpacklo_ps(x_low, z_low), _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
  v13 = *(__int64 *)((char *)&m_pComponent[2].m_BoundComponentHandles.mNode.mNext + 4);
  v25 = v13;
  if ( constrain_to_sidewalks )
    HIDWORD(v25) |= 0x200u;
  else
    HIDWORD(v25) = HIDWORD(v13) & 0xFFFFFDFF;
  result = !UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
              UFG::NavManager::ms_pInstance,
              npStartPos,
              (UFG::HavokNavPosition *)&v18,
              (UFG::NavParams *)&v25,
              (UFG::qVector3 *)&v16);
  if ( max_clear_distance )
  {
    v15 = (__m128)LODWORD(npStartPos->m_vPosition.y);
    v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] - v17) * (float)(v15.m128_f32[0] - v17))
                    + (float)((float)(npStartPos->m_vPosition.x - v16) * (float)(npStartPos->m_vPosition.x - v16));
    *(_DWORD *)max_clear_distance = _mm_sqrt_ps(v15).m128_u32[0];
  }
  return result;
}

// File Line: 1570
// RVA: 0x3808C0
void __fastcall UFG::PedFormationManagerComponent::Register(
        UFG::PedFormationManagerComponent *this,
        UFG::GetInPedFormationNode *get_in_formation)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // rbp
  unsigned int size; // ecx
  int v5; // r15d
  int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // edx
  UFG::PedFormationSlot *v10; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *p_m_pMember; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::PedFormationPair *p_m_Pair; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::PedFormationProfile::Slot *m_pProfileSlot; // r8
  __int64 v19; // r9
  unsigned int v20; // edx
  int v21; // ecx
  UFG::PedFormationProfile::Slot *m_pPointer; // rax
  float mMaxRadialHysteresisModifier; // xmm6_4
  float mMinRadialHysteresisModifier; // xmm7_4
  float v25; // xmm0_4
  UFG::SimComponent *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax

  v2 = 0i64;
  size = this->m_Slots.size;
  v5 = -1;
  v7 = 0;
  if ( size )
  {
    while ( this->m_Slots.p[v7].m_pMember.m_pPointer )
    {
      if ( ++v7 >= size )
        goto LABEL_34;
    }
    v5 = v7;
    if ( v7 != -1 )
    {
      v8 = this->m_ProfileSlots.size;
      v9 = 0;
      if ( v8 )
      {
        while ( this->m_ProfileSlots.p[v9].mMemberSlot )
        {
          if ( ++v9 >= v8 )
            goto LABEL_34;
        }
        v10 = &this->m_Slots.p[v7];
        p_m_pMember = &v10->m_pMember;
        if ( v10->m_pMember.m_pPointer )
        {
          mPrev = p_m_pMember->mPrev;
          mNext = v10->m_pMember.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_m_pMember->mPrev = p_m_pMember;
          v10->m_pMember.mNext = &v10->m_pMember;
        }
        v10->m_pMember.m_pPointer = get_in_formation;
        if ( get_in_formation )
        {
          v14 = get_in_formation->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInPedFormationNode>::mPrev;
          v14->mNext = p_m_pMember;
          p_m_pMember->mPrev = v14;
          v10->m_pMember.mNext = &get_in_formation->m_SafePointerList.mNode;
          get_in_formation->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInPedFormationNode>::mPrev = p_m_pMember;
        }
        p_m_Pair = &v10->m_Pair;
        if ( v10->m_Pair.m_pPair.m_pPointer )
        {
          v16 = p_m_Pair->m_pPair.mPrev;
          v17 = v10->m_Pair.m_pPair.mNext;
          v16->mNext = v17;
          v17->mPrev = v16;
          p_m_Pair->m_pPair.mPrev = &p_m_Pair->m_pPair;
          v10->m_Pair.m_pPair.mNext = &v10->m_Pair.m_pPair;
        }
        v10->m_Pair.m_pPair.m_pPointer = 0i64;
        v10->m_Pair.m_PairChangeAllowedTimer.mNextTime = -1.0;
        m_pProfileSlot = v10->m_pProfileSlot;
        v19 = v9;
        if ( m_pProfileSlot )
        {
          v20 = this->m_ProfileSlots.size;
          v21 = 0;
          if ( v20 )
          {
            while ( m_pProfileSlot != this->m_ProfileSlots.p[v21].mProfileSlot.m_pPointer )
            {
              if ( ++v21 >= v20 )
                goto LABEL_22;
            }
            this->m_ProfileSlots.p[v21].mMemberSlot = 0i64;
            v10->m_pProfileSlot = 0i64;
          }
        }
LABEL_22:
        m_pPointer = this->m_ProfileSlots.p[v19].mProfileSlot.m_pPointer;
        this->m_ProfileSlots.p[v19].mMemberSlot = v10;
        v10->m_pProfileSlot = m_pPointer;
        if ( m_pPointer )
        {
          mMaxRadialHysteresisModifier = m_pPointer->mMaxRadialHysteresisModifier;
          mMinRadialHysteresisModifier = m_pPointer->mMinRadialHysteresisModifier;
          v25 = mMaxRadialHysteresisModifier;
          if ( mMaxRadialHysteresisModifier > mMinRadialHysteresisModifier )
          {
            v25 = UFG::qRandom(
                    mMaxRadialHysteresisModifier - mMinRadialHysteresisModifier,
                    (unsigned int *)&UFG::qDefaultSeed)
                + mMinRadialHysteresisModifier;
            if ( v25 <= mMinRadialHysteresisModifier )
              v25 = mMinRadialHysteresisModifier;
            if ( v25 >= mMaxRadialHysteresisModifier )
              v25 = mMaxRadialHysteresisModifier;
          }
          v10->m_RadialHysteresisModifier = v25;
        }
        v26 = get_in_formation->m_pOwner.m_pPointer;
        get_in_formation->m_SlotIndex = v7;
        if ( v26 )
          v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v26[1].m_BoundComponentHandles.mNode.mNext;
        v27 = v2 + 105;
        if ( v2[106].mPrev )
        {
          v28 = v27->mPrev;
          v29 = v2[105].mNext;
          v28->mNext = v29;
          v29->mPrev = v28;
          v27->mPrev = v27;
          v2[105].mNext = v2 + 105;
        }
        v2[106].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)this;
        v30 = this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        v30->mNext = v27;
        v27->mPrev = v30;
        v2[105].mNext = &this->m_SafePointerList.mNode;
        this->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v27;
        --this->m_NumFreeSlots;
      }
    }
  }
LABEL_34:
  UFG::PedFormationManagerComponent::SetDesiredDirectionFromCurrentPosition(this, v5, get_in_formation);
}

// File Line: 1616
// RVA: 0x342360
void __fastcall UFG::PedFormationManagerComponent::AssignProfileSlot(
        UFG::PedFormationManagerComponent *this,
        UFG::PedFormationProfileSlot *profileSlot,
        UFG::PedFormationSlot *slot)
{
  UFG::PedFormationProfile::Slot *m_pProfileSlot; // r11
  unsigned int size; // r10d
  __int64 v6; // rax
  UFG::PedFormationProfile::Slot **p_m_pPointer; // r8
  UFG::PedFormationProfile::Slot *m_pPointer; // rax

  m_pProfileSlot = slot->m_pProfileSlot;
  if ( m_pProfileSlot )
  {
    size = this->m_ProfileSlots.size;
    v6 = 0i64;
    if ( size )
    {
      p_m_pPointer = &this->m_ProfileSlots.p[0].mProfileSlot.m_pPointer;
      while ( m_pProfileSlot != *p_m_pPointer )
      {
        v6 = (unsigned int)(v6 + 1);
        p_m_pPointer += 7;
        if ( (unsigned int)v6 >= size )
          goto LABEL_8;
      }
      this->m_ProfileSlots.p[v6].mMemberSlot = 0i64;
      slot->m_pProfileSlot = 0i64;
    }
  }
LABEL_8:
  m_pPointer = profileSlot->mProfileSlot.m_pPointer;
  profileSlot->mMemberSlot = slot;
  slot->m_pProfileSlot = m_pPointer;
  if ( m_pPointer )
    UFG::PedFormationSlot::SetRadialHysteresisModifier(slot);
}

// File Line: 1647
// RVA: 0x385F70
void __fastcall UFG::PedFormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
        UFG::PedFormationManagerComponent *this,
        unsigned int slot_index,
        UFG::GetInPedFormationNode *get_in_formation)
{
  float *m_pSimComponent; // rdi
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimObject *m_pSimObject; // r9
  UFG::SimComponent *v9; // rbx
  UFG::SimObject *v10; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v12; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 desired_direction; // [rsp+20h] [rbp-18h] BYREF

  m_pSimComponent = (float *)this->m_pTransformNodeComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    m_pPointer = get_in_formation->m_pOwner.m_pPointer;
    if ( m_pPointer )
    {
      m_pSimObject = m_pPointer->m_pSimObject;
      if ( m_pSimObject )
      {
        if ( m_pSimObject->m_pTransformNodeComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
          v9 = get_in_formation->m_pOwner.m_pPointer;
          if ( v9 && (v10 = v9->m_pSimObject) != 0i64 )
            m_pTransformNodeComponent = v10->m_pTransformNodeComponent;
          else
            m_pTransformNodeComponent = 0i64;
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          v12 = m_pTransformNodeComponent->mWorldTransform.v3.y - m_pSimComponent[45];
          desired_direction.x = m_pTransformNodeComponent->mWorldTransform.v3.x - m_pSimComponent[44];
          z = m_pTransformNodeComponent->mWorldTransform.v3.z;
          desired_direction.y = v12;
          desired_direction.z = z - m_pSimComponent[46];
          UFG::PedFormationManagerComponent::SetDesiredDirection(this, slot_index, get_in_formation, &desired_direction);
        }
      }
    }
  }
}

// File Line: 1660
// RVA: 0x3859C0
void __fastcall UFG::PedFormationManagerComponent::SetDesiredDirection(
        UFG::PedFormationManagerComponent *this,
        unsigned int slot_index,
        UFG::GetInPedFormationNode *get_in_formation,
        UFG::qVector3 *desired_direction)
{
  UFG::PedFormationSlot *p; // rbx
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::PedFormationSlot *v9; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimObject *v13; // rdx
  UFG::TransformNodeComponent *m_pSimComponent; // rbp
  UFG::HavokNavPosition *p_mNext; // r15
  UFG::SimComponent *v16; // rdi
  UFG::SimObject *v17; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::PedFormationProfile::Slot *m_pProfileSlot; // rax
  char v20; // r12
  __m128 y_low; // xmm0
  float v22; // xmm1_4
  float mMinDistance; // xmm2_4
  float mMaxDistance; // xmm1_4
  float v25; // xmm9_4
  float v26; // xmm6_4
  float v27; // xmm0_4
  float x; // xmm3_4
  float y; // xmm4_4
  float v30; // xmm7_4
  float v31; // xmm8_4
  __m128 v32; // xmm1
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm4_4
  __m128 v36; // xmm1
  float v37; // xmm2_4
  UFG::PedFormationProfile::Slot *v38; // rax
  float v39; // xmm1_4
  float mMaxRadialDistanceFromDesiredPosition; // xmm3_4
  float mMaxLateralDistanceFromDesiredPosition; // xmm0_4
  bool v42; // al
  unsigned int m_InPosition; // r15d
  float v44; // xmm0_4
  bool v45; // r14
  float v46; // xmm1_4
  bool v47; // bp
  int v48; // edi
  float v49; // xmm0_4
  UFG::qVector3 direction; // [rsp+40h] [rbp-78h] BYREF
  float current_lateral_offset; // [rsp+C0h] [rbp+8h] BYREF
  float max_clear_distance; // [rsp+C8h] [rbp+10h] BYREF

  p = this->m_Slots.p;
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  v9 = &p[slot_index];
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pSimObject->m_Components.p[36].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::NavComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::NavComponent::_TypeUID);
    if ( m_pComponent )
    {
      if ( this->m_pTransformNodeComponent.m_pSimComponent )
      {
        m_pPointer = get_in_formation->m_pOwner.m_pPointer;
        if ( m_pPointer )
        {
          v13 = m_pPointer->m_pSimObject;
          if ( v13 )
          {
            if ( v13->m_pTransformNodeComponent && v9->m_pProfileSlot )
            {
              m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
              p_mNext = (UFG::HavokNavPosition *)&m_pComponent[1].m_SafePointerList.mNode.mNext;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
              v16 = get_in_formation->m_pOwner.m_pPointer;
              if ( v16 && (v17 = v16->m_pSimObject) != 0i64 )
                m_pTransformNodeComponent = v17->m_pTransformNodeComponent;
              else
                m_pTransformNodeComponent = 0i64;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              m_pProfileSlot = v9->m_pProfileSlot;
              v20 = 1;
              y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
              v22 = m_pTransformNodeComponent->mWorldTransform.v3.x - m_pSimComponent->mWorldTransform.v3.x;
              mMinDistance = m_pProfileSlot->mMinDistance;
              y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - m_pSimComponent->mWorldTransform.v3.y)
                                        * (float)(y_low.m128_f32[0] - m_pSimComponent->mWorldTransform.v3.y))
                                + (float)(v22 * v22);
              mMaxDistance = m_pProfileSlot->mMaxDistance;
              v25 = _mm_sqrt_ps(y_low).m128_f32[0];
              v26 = v25;
              if ( v25 <= mMinDistance )
                v27 = m_pProfileSlot->mMinDistance;
              else
                v27 = v25;
              if ( v27 >= mMaxDistance )
                v27 = m_pProfileSlot->mMaxDistance;
              if ( v25 != v27 )
              {
                v20 = 0;
                v26 = (float)(mMaxDistance + mMinDistance) * 0.5;
              }
              x = desired_direction->x;
              y = desired_direction->y;
              v30 = 0.0;
              v31 = 0.0;
              if ( (float)((float)(y * y) + (float)(x * x)) > 0.0099999998 )
              {
                v32 = (__m128)LODWORD(desired_direction->y);
                v32.m128_f32[0] = (float)(y * y) + (float)(x * x);
                v33 = v26 / _mm_sqrt_ps(v32).m128_f32[0];
                v30 = x * v33;
                v31 = y * v33;
              }
              direction.x = v30;
              direction.y = v31;
              direction.z = 0.0;
              max_clear_distance = 0.0;
              if ( !UFG::PedFormationManagerComponent::DirectionIsClear(
                      this,
                      p_mNext,
                      &direction,
                      &max_clear_distance,
                      eCONSTRAIN_TO_SIDEWALKS_NO) )
              {
                v34 = desired_direction->x;
                v35 = desired_direction->y;
                v26 = max_clear_distance;
                if ( (float)((float)(v35 * v35) + (float)(v34 * v34)) > 0.0099999998 )
                {
                  v36 = (__m128)LODWORD(desired_direction->y);
                  v36.m128_f32[0] = (float)(v35 * v35) + (float)(v34 * v34);
                  v37 = max_clear_distance / _mm_sqrt_ps(v36).m128_f32[0];
                  v30 = v34 * v37;
                  v31 = v35 * v37;
                }
              }
              v38 = v9->m_pProfileSlot;
              v39 = v31 + m_pSimComponent->mWorldTransform.v3.y;
              mMaxRadialDistanceFromDesiredPosition = v38->mMaxRadialDistanceFromDesiredPosition;
              direction.x = v30 + m_pSimComponent->mWorldTransform.v3.x;
              direction.z = m_pSimComponent->mWorldTransform.v3.z;
              mMaxLateralDistanceFromDesiredPosition = v38->mMaxLateralDistanceFromDesiredPosition;
              direction.y = v39;
              current_lateral_offset = 0.0;
              max_clear_distance = 0.0;
              v42 = UFG::PedFormationManagerComponent::IsInPosition(
                      this,
                      (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
                      &direction,
                      mMaxRadialDistanceFromDesiredPosition,
                      mMaxLateralDistanceFromDesiredPosition,
                      &max_clear_distance,
                      &current_lateral_offset,
                      0);
              m_InPosition = v9->m_InPosition;
              v44 = *(float *)&FLOAT_1_0;
              v45 = v42;
              v46 = *(float *)&FLOAT_1_0;
              if ( m_InPosition <= 2 )
              {
                v44 = FLOAT_2_0;
                v46 = FLOAT_2_0;
              }
              v47 = max_clear_distance <= v44 && current_lateral_offset <= v46;
              v48 = 0;
              if ( !UFG::PedFormationManagerComponent::IsFarFromPosition(
                      this,
                      v9->m_pProfileSlot,
                      max_clear_distance,
                      v25) )
              {
                if ( m_InPosition != 4 )
                {
                  if ( v45 )
                  {
LABEL_41:
                    if ( unk_14206D75C < this->m_Speed )
                      v48 = 1;
                    goto LABEL_46;
                  }
                  v48 = 3 - v47;
LABEL_46:
                  v9->m_Direction.x = v30;
                  v9->m_Direction.y = v31;
                  v9->m_Direction.z = 0.0;
                  v49 = atan2f(v31, v30);
                  v9->m_Distance = v26;
                  v9->m_CurrentlyInRange = v20;
                  v9->m_Angle = (int)(float)((float)(v49 * 32768.0) * 0.31830987);
                  UFG::PedFormationSlot::SetInPosition(v9, (UFG::PedFormationSlot::ePositionType)v48);
                  return;
                }
                if ( v45 )
                  goto LABEL_41;
              }
              v48 = 4;
              goto LABEL_46;
            }
          }
        }
      }
    }
  }
}

// File Line: 1759
// RVA: 0x36A970
bool __fastcall UFG::PedFormationManagerComponent::IsFarFromPosition(
        UFG::PedFormationManagerComponent *this,
        UFG::PedFormationProfile::Slot *profileSlot,
        float current_radial_offset,
        float current_distance_from_centre)
{
  UFG::PedFormationProfile *m_pCurrentProfile; // rax

  if ( this->m_CurrentlySprinting && (m_pCurrentProfile = this->m_pCurrentProfile) != 0i64 )
    return current_radial_offset >= m_pCurrentProfile->mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting;
  else
    return current_radial_offset >= (float)((float)(profileSlot->mMaxRadialDistanceFromDesiredPositionHysteresis
                                                  + profileSlot->mMaxRadialDistanceFromDesiredPosition)
                                          + 5.0);
}

// File Line: 1777
// RVA: 0x35FC00
UFG::GetInPedFormationNode *__fastcall UFG::PedFormationManagerComponent::GetFollowersPair(
        UFG::PedFormationManagerComponent *this,
        UFG::SimObject *pFollower)
{
  unsigned int size; // r9d
  int v3; // r8d
  UFG::GetInPedFormationNode **i; // rax
  UFG::SimObject *m_pPointer; // rcx

  size = this->m_Slots.size;
  v3 = 0;
  if ( !size )
    return 0i64;
  for ( i = &this->m_Slots.p[0].m_pMember.m_pPointer; ; i += 20 )
  {
    if ( *i )
    {
      m_pPointer = (UFG::SimObject *)(*i)->m_pOwner.m_pPointer;
      if ( m_pPointer )
        m_pPointer = (UFG::SimObject *)m_pPointer->mNode.mParent;
      if ( m_pPointer == pFollower )
        break;
    }
    if ( ++v3 >= size )
      return 0i64;
  }
  return i[3];
}

// File Line: 1791
// RVA: 0x360970
UFG::SimObject *__fastcall UFG::PedFormationManagerComponent::GetLeadersPair(UFG::PedFormationManagerComponent *this)
{
  return this->m_Pair.m_pPair.m_pPointer;
}

// File Line: 1796
// RVA: 0x35AFE0
UFG::SimObject *__fastcall UFG::PedFormationManagerComponent::GetClosestMember(
        UFG::PedFormationManagerComponent *this,
        UFG::qVector3 *pos,
        UFG::SimObject *pExclude1,
        UFG::SimObject *pExclude2)
{
  float *m_pSimComponent; // rdi
  UFG::SimObject *v5; // r14
  float v9; // xmm6_4
  UFG::SimObject *m_pSimObject; // rbx
  __int64 i; // rsi
  UFG::GetInPedFormationNode *m_pPointer; // rax
  UFG::SimComponent *v14; // rcx
  UFG::SimObject *v15; // rdx
  UFG::SimObject *v16; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi

  m_pSimComponent = (float *)this->m_pTransformNodeComponent.m_pSimComponent;
  v5 = 0i64;
  v9 = 0.0;
  if ( m_pSimComponent )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject != pExclude1 && m_pSimObject != pExclude2 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
      v5 = m_pSimObject;
      v9 = (float)((float)((float)(m_pSimComponent[45] - pos->y) * (float)(m_pSimComponent[45] - pos->y))
                 + (float)((float)(m_pSimComponent[44] - pos->x) * (float)(m_pSimComponent[44] - pos->x)))
         + (float)((float)(m_pSimComponent[46] - pos->z) * (float)(m_pSimComponent[46] - pos->z));
    }
  }
  for ( i = 0i64; (unsigned int)i < this->m_Slots.size; i = (unsigned int)(i + 1) )
  {
    m_pPointer = this->m_Slots.p[i].m_pMember.m_pPointer;
    if ( m_pPointer )
    {
      v14 = m_pPointer->m_pOwner.m_pPointer;
      if ( v14 )
      {
        v15 = v14->m_pSimObject;
        if ( v15 )
        {
          if ( v15->m_pTransformNodeComponent )
          {
            v16 = v14->m_pSimObject;
            if ( v16 != pExclude1 && v16 != pExclude2 )
            {
              m_pTransformNodeComponent = v15->m_pTransformNodeComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              if ( !v5
                || (float)((float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - pos->y)
                                         * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - pos->y))
                                 + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - pos->x)
                                         * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - pos->x)))
                         + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - pos->z)
                                 * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - pos->z))) < v9 )
              {
                v9 = (float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - pos->y)
                                   * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - pos->y))
                           + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - pos->x)
                                   * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - pos->x)))
                   + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - pos->z)
                           * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - pos->z));
                v5 = v16;
              }
            }
          }
        }
      }
    }
  }
  return v5;
}

// File Line: 1834
// RVA: 0x38ACD0
void __fastcall UFG::PedFormationManagerComponent::UnregisterSlot(
        UFG::PedFormationManagerComponent *this,
        unsigned int slot_index)
{
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *p_m_pMember; // rcx
  __int64 v4; // r10
  __int64 v5; // r11
  __int64 *v6; // rcx
  __int64 v7; // rdx
  _QWORD *v8; // rax
  UFG::PedFormationPair *p_m_Pair; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::PedFormationProfile::Slot *m_pProfileSlot; // r9
  unsigned int size; // edx
  int v14; // ecx
  __int64 *v15; // rdx
  __int64 v16; // rcx
  _QWORD *v17; // rax
  __int64 v18; // rdx
  __int64 v19; // rdx
  __int64 *v20; // rdx
  __int64 v21; // rcx
  _QWORD *v22; // rax

  p_m_pMember = &this->m_Slots.p[0].m_pMember;
  v4 = slot_index;
  v5 = *(__int64 *)((char *)&p_m_pMember->m_pPointer + v4 * 160);
  v6 = (__int64 *)((char *)p_m_pMember + v4 * 160);
  if ( v6[2] )
  {
    v7 = *v6;
    v8 = (_QWORD *)v6[1];
    *(_QWORD *)(v7 + 8) = v8;
    *v8 = v7;
    *v6 = (__int64)v6;
    v6[1] = (__int64)v6;
  }
  p_m_Pair = &this->m_Slots.p[v4].m_Pair;
  v6[2] = 0i64;
  if ( p_m_Pair->m_pPair.m_pPointer )
  {
    mPrev = p_m_Pair->m_pPair.mPrev;
    mNext = p_m_Pair->m_pPair.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_Pair->m_pPair.mPrev = &p_m_Pair->m_pPair;
    p_m_Pair->m_pPair.mNext = &p_m_Pair->m_pPair;
  }
  p_m_Pair->m_pPair.m_pPointer = 0i64;
  p_m_Pair->m_PairChangeAllowedTimer.mNextTime = -1.0;
  m_pProfileSlot = this->m_Slots.p[v4].m_pProfileSlot;
  if ( m_pProfileSlot )
  {
    size = this->m_ProfileSlots.size;
    v14 = 0;
    if ( size )
    {
      while ( m_pProfileSlot != this->m_ProfileSlots.p[v14].mProfileSlot.m_pPointer )
      {
        if ( ++v14 >= size )
          goto LABEL_11;
      }
      this->m_ProfileSlots.p[v14].mMemberSlot = 0i64;
      this->m_Slots.p[v4].m_pProfileSlot = 0i64;
    }
  }
LABEL_11:
  if ( v5 )
  {
    v15 = (__int64 *)(v5 + 48);
    *(_DWORD *)(v5 + 40) = -1;
    if ( *(_QWORD *)(v5 + 64) )
    {
      v16 = *v15;
      v17 = *(_QWORD **)(v5 + 56);
      *(_QWORD *)(v16 + 8) = v17;
      *v17 = v16;
      *v15 = (__int64)v15;
      *(_QWORD *)(v5 + 56) = v5 + 48;
    }
    *(_QWORD *)(v5 + 64) = 0i64;
    v18 = *(_QWORD *)(v5 + 88);
    if ( v18 )
      v19 = *(_QWORD *)(v18 + 120);
    else
      v19 = 0i64;
    v20 = (__int64 *)(v19 + 1680);
    if ( v20[2] )
    {
      v21 = *v20;
      v22 = (_QWORD *)v20[1];
      *(_QWORD *)(v21 + 8) = v22;
      *v22 = v21;
      *v20 = (__int64)v20;
      v20[1] = (__int64)v20;
    }
    v20[2] = 0i64;
    ++this->m_NumFreeSlots;
  }
}

// File Line: 1858
// RVA: 0x360020
__int64 __fastcall UFG::PedFormationManagerComponent::GetInPositionType(
        UFG::PedFormationManagerComponent *this,
        UFG::GetInPedFormationNode *get_in_formation)
{
  __int64 m_SlotIndex; // r8

  if ( get_in_formation
    && (m_SlotIndex = (unsigned int)get_in_formation->m_SlotIndex, (_DWORD)m_SlotIndex != -1)
    && (unsigned int)m_SlotIndex < this->m_Slots.size
    && this->m_Slots.p[m_SlotIndex].m_pMember.m_pPointer == get_in_formation )
  {
    return (unsigned int)this->m_Slots.p[m_SlotIndex].m_InPosition;
  }
  else
  {
    return 3i64;
  }
}

// File Line: 1887
// RVA: 0x377D20
void __fastcall UFG::PedFormationManagerComponent::OnArrived(
        UFG::PedFormationManagerComponent *this,
        UFG::GetInPedFormationNode *get_in_formation,
        UFG::qVector3 *desired_position,
        float desired_speed)
{
  __int64 v4; // r9
  UFG::PedFormationSlot *v5; // rbx
  float mSimTime_Temp; // xmm0_4
  __int64 m_SlotIndex; // r9

  if ( unk_14206D75C < this->m_Speed )
  {
    if ( get_in_formation )
    {
      m_SlotIndex = (unsigned int)get_in_formation->m_SlotIndex;
      if ( (_DWORD)m_SlotIndex != -1
        && (unsigned int)m_SlotIndex < this->m_Slots.size
        && this->m_Slots.p[m_SlotIndex].m_pMember.m_pPointer == get_in_formation
        && this->m_Slots.p[m_SlotIndex].m_InPosition != ePOSITION_STAYING_IN_POSITION )
      {
        this->m_Slots.p[m_SlotIndex].m_InPosition = ePOSITION_STAYING_IN_POSITION;
      }
    }
  }
  else if ( get_in_formation )
  {
    v4 = (unsigned int)get_in_formation->m_SlotIndex;
    if ( (_DWORD)v4 != -1
      && (unsigned int)v4 < this->m_Slots.size
      && this->m_Slots.p[v4].m_pMember.m_pPointer == get_in_formation )
    {
      v5 = &this->m_Slots.p[v4];
      if ( v5->m_InPosition )
      {
        mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
        v5->m_DesiredMoveType = eMoveType_Walk;
        v5->m_TimeGotIntoPosition = mSimTime_Temp;
        UFG::PedFormationSlot::SetRadialHysteresisModifier(&this->m_Slots.p[v4]);
        if ( v5->m_InPosition )
          v5->m_InPosition = ePOSITION_IN_POSITION;
      }
    }
  }
}

// File Line: 1900
// RVA: 0x351850
_BOOL8 __fastcall UFG::PedFormationManagerComponent::CrossesLeadersPath(
        UFG::PedFormationManagerComponent *this,
        UFG::qVector2 *follower_start,
        UFG::qVector2 *follower_end)
{
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  UFG::qVector2 intersection; // [rsp+30h] [rbp-48h] BYREF
  UFG::qVector2 lA1; // [rsp+80h] [rbp+8h] BYREF
  UFG::qVector2 lA0; // [rsp+98h] [rbp+20h] BYREF

  if ( !this->m_pTransformNodeComponent.m_pSimComponent )
    return 0i64;
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v7 = COERCE_FLOAT(unk_14206D764 ^ _xmm[0]) * this->m_FormationForward.y;
  v8 = COERCE_FLOAT(unk_14206D764 ^ _xmm[0]) * this->m_FormationForward.x;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  v9 = unk_14206D760 * this->m_FormationForward.y;
  v10 = unk_14206D760 * this->m_FormationForward.x;
  v11 = m_pSimComponent->mWorldTransform.v3.y + v7;
  lA0.x = v8 + m_pSimComponent->mWorldTransform.v3.x;
  lA0.y = v11;
  lA1.x = v10 + lA0.x;
  lA1.y = v9 + v11;
  return (unsigned int)UFG::qIntersect(&intersection, &lA0, &lA1, follower_start, follower_end, 0i64) == 3;
}

// File Line: 1919
// RVA: 0x35DB90
char __fastcall UFG::PedFormationManagerComponent::GetDesiredPosition(
        UFG::PedFormationManagerComponent *this,
        UFG::GetInPedFormationNode *get_in_formation,
        UFG::qVector3 *desired_position)
{
  __int64 m_SlotIndex; // rax
  UFG::TransformNodeComponent *m_pSimComponent; // rbp
  __int64 v8; // rax
  UFG::SimObject *m_pSimObject; // r8
  float x; // xmm9_4
  float y; // xmm10_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float z; // xmm8_4
  __int16 m_Flags; // cx
  UFG::NavComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v18; // zf
  UFG::SimObjectGame *v19; // rcx
  float v20; // xmm0_4
  float v21; // xmm7_4
  float v22; // xmm8_4
  float AvoidanceRadius; // xmm0_4
  float v24; // xmm9_4
  float v25; // xmm10_4
  float v26; // xmm7_4
  float v27; // xmm8_4

  if ( !this->m_pTransformNodeComponent.m_pSimComponent )
    return 0;
  if ( !get_in_formation )
    return 0;
  m_SlotIndex = (unsigned int)get_in_formation->m_SlotIndex;
  if ( (_DWORD)m_SlotIndex == -1
    || (unsigned int)m_SlotIndex >= this->m_Slots.size
    || this->m_Slots.p[m_SlotIndex].m_pMember.m_pPointer != get_in_formation )
  {
    return 0;
  }
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  v8 = (unsigned int)get_in_formation->m_SlotIndex;
  m_pSimObject = this->m_pSimObject;
  x = this->m_FormationForward.x;
  y = this->m_FormationForward.y;
  v12 = this->m_Slots.p[v8].m_Direction.x;
  v13 = this->m_Slots.p[v8].m_Direction.y;
  z = this->m_Slots.p[v8].m_Direction.z;
  if ( m_pSimObject
    && ((m_Flags = m_pSimObject->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags < 0 || (m_Flags & 0x2000) != 0
       ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)this->m_pSimObject,
                                UFG::NavComponent::_TypeUID))
       : (v18 = (m_Flags & 0x1000) == 0, v19 = (UFG::SimObjectGame *)this->m_pSimObject, v18)
       ? (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v19, UFG::NavComponent::_TypeUID))
       : (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::NavComponent::_TypeUID)),
         m_pComponent = (UFG::NavComponent *)ComponentOfTypeHK)
      : (m_pComponent = (UFG::NavComponent *)m_pSimObject->m_Components.p[36].m_pComponent),
        m_pComponent) )
  {
    if ( unk_14206D75C < this->m_Speed )
    {
      v20 = UFG::NavComponent::GetAvoidanceRadius(m_pComponent) * 2.75;
      v12 = v12 * v20;
      v13 = v13 * v20;
      z = z * v20;
    }
    v21 = v13 + m_pSimComponent->mWorldTransform.v3.y;
    v22 = z + m_pSimComponent->mWorldTransform.v3.z;
    desired_position->x = v12 + m_pSimComponent->mWorldTransform.v3.x;
    desired_position->y = v21;
    desired_position->z = v22;
    if ( unk_14206D75C < this->m_Speed )
    {
      AvoidanceRadius = UFG::NavComponent::GetAvoidanceRadius(m_pComponent);
      v24 = (float)(x * AvoidanceRadius) + desired_position->x;
      v25 = (float)(y * AvoidanceRadius) + desired_position->y;
      desired_position->z = (float)(AvoidanceRadius * 0.0) + desired_position->z;
      desired_position->x = v24;
      desired_position->y = v25;
    }
  }
  else
  {
    v26 = v13 + m_pSimComponent->mWorldTransform.v3.y;
    v27 = z + m_pSimComponent->mWorldTransform.v3.z;
    desired_position->x = v12 + m_pSimComponent->mWorldTransform.v3.x;
    desired_position->y = v26;
    desired_position->z = v27;
  }
  return 1;
}

// File Line: 1954
// RVA: 0x35E3A0
bool __fastcall UFG::PedFormationManagerComponent::GetDesiredWaypoint(
        UFG::PedFormationManagerComponent *this,
        UFG::GetInPedFormationNode *get_in_formation,
        UFG::qVector3 *desired_waypoint,
        float *desired_speed)
{
  __int64 m_SlotIndex; // rdi
  UFG::SimComponent *m_pPointer; // rbp
  UFG::SimObject *m_pSimObject; // rbp
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  UFG::SimComponent *v12; // rcx
  UFG::SimObject *v13; // rcx
  UFG::TransformNodeComponent *v14; // rcx
  float mMaxLookAhead; // xmm6_4
  float y; // xmm7_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  __int128 y_low; // xmm3
  float x; // xmm2_4
  __m128 v26; // xmm1
  float v27; // xmm6_4
  float v28; // xmm1_4
  float m_Speed; // xmm0_4
  bool result; // al
  UFG::SimComponent *v31; // rbp
  UFG::SimObject *v32; // rbp
  UFG::TransformNodeComponent *v33; // rbp
  float v34; // xmm7_4
  float v35; // xmm6_4
  float Value; // xmm8_4
  UFG::eMoveType m_NextMoveType; // eax
  float mNextTime; // xmm1_4
  UFG::eMoveType m_DesiredMoveType; // eax
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm8_4
  UFG::SimObjectGame *v43; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  int v46; // ecx
  UFG::qVector2 follower_end; // [rsp+20h] [rbp-58h] BYREF
  UFG::qVector2 follower_start; // [rsp+28h] [rbp-50h] BYREF

  if ( UFG::PedFormationManagerComponent::GetDesiredPosition(this, get_in_formation, desired_waypoint) )
  {
    m_SlotIndex = (unsigned int)get_in_formation->m_SlotIndex;
    m_pPointer = this->m_Slots.p[m_SlotIndex].m_pMember.m_pPointer->m_pOwner.m_pPointer;
    if ( m_pPointer && (m_pSimObject = m_pPointer->m_pSimObject) != 0i64 )
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v12 = this->m_Slots.p[m_SlotIndex].m_pMember.m_pPointer->m_pOwner.m_pPointer;
    if ( v12 && (v13 = v12->m_pSimObject) != 0i64 )
      v14 = v13->m_pTransformNodeComponent;
    else
      v14 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v14);
    mMaxLookAhead = this->m_Slots.p[m_SlotIndex].m_pProfileSlot->mMaxLookAhead;
    if ( this->m_IsDestinationValid
      && this->m_IsApproachingTurn
      && (float)((float)((float)((float)(desired_waypoint->y - this->m_Destination.y)
                               * (float)(desired_waypoint->y - this->m_Destination.y))
                       + (float)((float)(desired_waypoint->x - this->m_Destination.x)
                               * (float)(desired_waypoint->x - this->m_Destination.x)))
               + (float)((float)(desired_waypoint->z - this->m_Destination.z)
                       * (float)(desired_waypoint->z - this->m_Destination.z))) < (float)((float)(unk_14206D784
                                                                                                + mMaxLookAhead)
                                                                                        * (float)(unk_14206D784
                                                                                                + mMaxLookAhead)) )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
      y = desired_waypoint->y;
      v17 = this->m_FormationForward.y;
      v18 = unk_14206D784;
      v19 = (float)(this->m_FormationForward.x * (float)(this->m_Destination.x - desired_waypoint->x))
          + (float)(v17 * (float)(this->m_Destination.y - y));
      if ( v19 < unk_14206D784 )
      {
        LODWORD(v20) = COERCE_UNSIGNED_INT(unk_14206D784 - v19) ^ _xmm[0];
        desired_waypoint->x = (float)(this->m_FormationForward.x * v20) + desired_waypoint->x;
        desired_waypoint->y = (float)(v17 * v20) + y;
        v18 = unk_14206D784;
      }
      v21 = v19 - v18;
      if ( v21 <= 0.0 )
        v21 = 0.0;
      if ( v21 < mMaxLookAhead )
        mMaxLookAhead = v21;
    }
    v22 = desired_waypoint->y;
    v23 = this->m_FormationForward.y * 0.5;
    follower_end.x = desired_waypoint->x + (float)(this->m_FormationForward.x * 0.5);
    follower_start.y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    follower_end.y = v22 + v23;
    follower_start.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    if ( UFG::PedFormationManagerComponent::CrossesLeadersPath(this, &follower_start, &follower_end) )
      mMaxLookAhead = 0.0;
    if ( unk_14206D75C < this->m_Speed && this->m_Slots.p[m_SlotIndex].m_InPosition == ePOSITION_STAYING_IN_POSITION )
    {
      if ( mMaxLookAhead >= unk_14206D714 )
        mMaxLookAhead = unk_14206D714;
      y_low = LODWORD(this->m_FormationForward.y);
      x = this->m_FormationForward.x;
      v26 = (__m128)y_low;
      v26.m128_f32[0] = (float)(*(float *)&y_low * *(float *)&y_low) + (float)(x * x);
      v27 = mMaxLookAhead / _mm_sqrt_ps(v26).m128_f32[0];
      *(float *)&y_low = (float)(*(float *)&y_low * v27) + desired_waypoint->y;
      desired_waypoint->x = (float)(x * v27) + desired_waypoint->x;
      LODWORD(desired_waypoint->y) = y_low;
    }
    v28 = (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - desired_waypoint->y)
                * this->m_FormationForward.y)
        + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - desired_waypoint->x)
                * this->m_FormationForward.x);
    if ( v28 > 0.0 )
    {
      m_Speed = this->m_Speed;
      if ( m_Speed > 0.1 && (float)(v28 / m_Speed) < unk_14206D758 )
        return 0;
    }
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
    v31 = this->m_Slots.p[m_SlotIndex].m_pMember.m_pPointer->m_pOwner.m_pPointer;
    if ( v31 && (v32 = v31->m_pSimObject) != 0i64 )
      v33 = v32->m_pTransformNodeComponent;
    else
      v33 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v33);
    v34 = v33->mWorldTransform.v3.x - desired_waypoint->x;
    v35 = v33->mWorldTransform.v3.y - desired_waypoint->y;
    Value = UFG::LinearGraph<float>::GetValue(
              &stru_14206D718,
              (float)(v35 * this->m_FormationForward.y) + (float)(v34 * this->m_FormationForward.x));
    if ( (float)((float)(v35 * v35) + (float)(v34 * v34)) > unk_14206D750 && Value <= 1.0 )
      Value = *(float *)&FLOAT_1_0;
    m_NextMoveType = this->m_Slots.p[m_SlotIndex].m_NextMoveType;
    if ( m_NextMoveType )
    {
      mNextTime = this->m_Slots.p[m_SlotIndex].m_ReactionTimer.mNextTime;
      if ( mNextTime < 0.0 || mNextTime > 0.0 && UFG::Metrics::msInstance.mSimTime_Temp >= mNextTime )
      {
        this->m_Slots.p[m_SlotIndex].m_DesiredMoveType = m_NextMoveType;
        this->m_Slots.p[m_SlotIndex].m_NextMoveType = eMoveType_None;
        this->m_Slots.p[m_SlotIndex].m_ReactionTimer.mNextTime = -1.0;
      }
    }
    else if ( this->m_Slots.p[m_SlotIndex].m_InPosition <= (unsigned int)ePOSITION_STAYING_IN_POSITION )
    {
      this->m_Slots.p[m_SlotIndex].m_DesiredMoveType = this->m_LeaderMoveType;
      v43 = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( v43 )
      {
        m_Flags = v43->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
          m_pComponent = v43->m_Components.p[36].m_pComponent;
        else
          m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                       ? UFG::SimObjectGame::GetComponentOfTypeHK(v43, UFG::NavComponent::_TypeUID)
                       : UFG::SimObject::GetComponentOfType(v43, UFG::NavComponent::_TypeUID);
        if ( m_pComponent )
        {
          v46 = *(_DWORD *)(*(_QWORD *)&m_pComponent[2].m_TypeUID + 52i64);
          result = 1;
          *(_DWORD *)desired_speed = v46;
          return result;
        }
      }
    }
    m_DesiredMoveType = this->m_Slots.p[m_SlotIndex].m_DesiredMoveType;
    if ( m_DesiredMoveType == eMoveType_Run )
    {
      v40 = FLOAT_7_5;
      v41 = FLOAT_4_8000002;
      v42 = Value * 7.5;
      if ( v42 <= 4.8000002 )
      {
LABEL_44:
        v42 = v41;
LABEL_66:
        result = 1;
        *desired_speed = v42;
        return result;
      }
    }
    else
    {
      if ( m_DesiredMoveType == eMoveType_Jog )
      {
        v41 = FLOAT_3_0;
        v42 = Value * 3.95;
        if ( v42 > 3.0 )
        {
          if ( v42 >= 3.95 )
          {
            *desired_speed = FLOAT_3_95;
            return 1;
          }
          goto LABEL_66;
        }
        goto LABEL_44;
      }
      v42 = Value * 1.5;
      if ( v42 <= 0.0 )
      {
        v42 = 0.0;
        goto LABEL_66;
      }
      v40 = FLOAT_3_0;
    }
    if ( v42 >= v40 )
    {
      *desired_speed = v40;
      return 1;
    }
    goto LABEL_66;
  }
  return 0;
}

// File Line: 2249
// RVA: 0x36AE60
bool __fastcall UFG::PedFormationManagerComponent::IsInPedFormation(
        UFG::PedFormationManagerComponent *this,
        UFG::GetInPedFormationNode *get_in_formation)
{
  __int64 m_SlotIndex; // r8
  unsigned int size; // r10d
  bool result; // al

  result = 0;
  if ( get_in_formation )
  {
    m_SlotIndex = (unsigned int)get_in_formation->m_SlotIndex;
    if ( (_DWORD)m_SlotIndex != -1 )
    {
      size = this->m_Slots.size;
      if ( (unsigned int)m_SlotIndex < size
        && this->m_Slots.p[m_SlotIndex].m_pMember.m_pPointer == get_in_formation
        && this->m_Slots.p[m_SlotIndex].m_InPosition == ePOSITION_IN_POSITION
        && (unsigned int)m_SlotIndex < size
        && this->m_Slots.p[m_SlotIndex].m_pMember.m_pPointer == get_in_formation
        && this->m_Slots.p[m_SlotIndex].m_CurrentlyFacingCorrectly )
      {
        return 1;
      }
    }
  }
  return result;
}

