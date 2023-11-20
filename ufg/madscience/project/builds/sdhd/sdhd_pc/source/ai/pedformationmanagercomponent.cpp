// File Line: 164
// RVA: 0x331E40
void __fastcall UFG::PedFormationProfile::Slot::Slot(UFG::PedFormationProfile::Slot *this)
{
  UFG::PedFormationProfile::Slot *v1; // rbx

  v1 = this;
  UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>::qSafePointerNode<UFG::PedFormationProfile::Slot>((UFG::qSafePointerNode<UFG::PedFormationProfile::Slot> *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>Vtbl *)&UFG::PedFormationProfile::Slot::`vftable';
  v1->mFacingType = 0;
  v1->mAngle = 0;
  v1->mCanCrossLeader = 0;
  v1->mPreference = 1.0;
  *(_QWORD *)&v1->mMinFollowers = 1i64;
  *(_QWORD *)&v1->mMaxDistance = 0i64;
  *(_QWORD *)&v1->mMinFacingDifference = 0i64;
  *(_QWORD *)&v1->mMaxRadialDistanceFromDesiredPosition = 0i64;
  *(_QWORD *)&v1->mMinRadialHysteresisModifier = 0i64;
  *(_QWORD *)&v1->mMaxRadialDistanceFromDesiredPositionHysteresisLarge = 0i64;
  *(_QWORD *)&v1->mMaxRadialDistanceFromDesiredPositionHysteresisFar = 0i64;
  v1->mMaxLateralDistanceFromDesiredPositionHysteresisFar = 0.0;
}

// File Line: 168
// RVA: 0x3682D0
void __fastcall UFG::PedFormationProfile::Slot::InitFromPropertySet(UFG::PedFormationProfile::Slot *this, UFG::qPropertySet *pPropertySet)
{
  UFG::qPropertySet *v2; // rdi
  UFG::PedFormationProfile::Slot *v3; // rbx
  UFG::qSymbol *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rax
  __int128 v9; // xmm0
  UFG::qSymbol *v10; // rax
  UFG::qSymbol *v11; // rax
  UFG::qSymbol *v12; // rax
  UFG::qSymbol *v13; // rax
  UFG::qSymbol *v14; // rax
  UFG::qSymbol *v15; // rax
  UFG::qSymbol *v16; // rax
  UFG::qSymbol *v17; // rax
  UFG::qSymbol *v18; // rax
  UFG::qSymbol *v19; // rax
  UFG::qSymbol v20; // [rsp+20h] [rbp-50h]
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-48h]
  UFG::qSymbol v22; // [rsp+48h] [rbp-28h]
  UFG::qSymbol v23; // [rsp+4Ch] [rbp-24h]
  UFG::qSymbol v24; // [rsp+50h] [rbp-20h]
  UFG::qSymbol v25; // [rsp+54h] [rbp-1Ch]
  UFG::qSymbol v26; // [rsp+58h] [rbp-18h]
  __int64 v27; // [rsp+60h] [rbp-10h]
  UFG::qSymbol result; // [rsp+90h] [rbp+20h]
  UFG::qSymbol name; // [rsp+A0h] [rbp+30h]
  UFG::qSymbol v30; // [rsp+A8h] [rbp+38h]

  v27 = -2i64;
  v2 = pPropertySet;
  v3 = this;
  UFG::qSymbol::create_from_string(&result, "Angle");
  UFG::qSymbol::create_from_string(&name, "CanCrossLeader");
  UFG::qSymbol::create_from_string(&v30, "Preference");
  UFG::qSymbol::create_from_string(&v24, "MinFollowers");
  UFG::qSymbol::create_from_string(&v23, "MinDistance");
  UFG::qSymbol::create_from_string(&v25, "MaxDistance");
  UFG::qSymbol::create_from_string(&v22, "MaxLookAhead");
  UFG::qSymbol::create_from_string(&v26, "MinFacingDifference");
  v4 = UFG::qSymbol::create_from_string(&v20, "FacingType");
  v5 = UFG::qPropertySet::Get<UFG::qSymbol>(v2, v4, DEPTH_RECURSE);
  if ( v5 )
  {
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v6 = UFG::gPedFormationFacingTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gPedFormationFacingTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v6;
      pTrackEnumBinding.mNext = &UFG::gPedFormationFacingTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gPedFormationFacingTypeTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    v3->mFacingType = pTrackEnumBinding.m_EnumValue;
    v7 = pTrackEnumBinding.mPrev;
    v8 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v8->mPrev = v7;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v3->mAngle = (signed int)(float)((float)(*UFG::qPropertySet::Get<float>(v2, &result, DEPTH_RECURSE) * 65536.0)
                                 * 0.0027777778);
  v3->mCanCrossLeader = *UFG::qPropertySet::Get<bool>(v2, &name, DEPTH_RECURSE);
  v3->mPreference = *UFG::qPropertySet::Get<float>(v2, &v30, DEPTH_RECURSE);
  v3->mMinFollowers = *UFG::qPropertySet::Get<unsigned long>(v2, &v24, DEPTH_RECURSE);
  v3->mMinDistance = *UFG::qPropertySet::Get<float>(v2, &v23, DEPTH_RECURSE);
  v9 = *(unsigned int *)UFG::qPropertySet::Get<float>(v2, &v25, DEPTH_RECURSE);
  if ( *(float *)&v9 <= v3->mMinDistance )
    *(float *)&v9 = v3->mMinDistance;
  LODWORD(v3->mMaxDistance) = v9;
  v3->mMaxLookAhead = *UFG::qPropertySet::Get<float>(v2, &v22, DEPTH_RECURSE);
  v3->mMinFacingDifference = *UFG::qPropertySet::Get<float>(v2, &v26, DEPTH_RECURSE);
  v10 = UFG::qSymbol::create_from_string(&v20, "MinFacingDifferenceHysteresis");
  v3->mMinFacingDifferenceHysteresis = *UFG::qPropertySet::Get<float>(v2, v10, DEPTH_RECURSE);
  v11 = UFG::qSymbol::create_from_string(&v20, "MaxRadialDistanceFromDesiredPosition");
  v3->mMaxRadialDistanceFromDesiredPosition = *UFG::qPropertySet::Get<float>(v2, v11, DEPTH_RECURSE);
  v12 = UFG::qSymbol::create_from_string(&v20, "MaxLateralDistanceFromDesiredPosition");
  v3->mMaxLateralDistanceFromDesiredPosition = *UFG::qPropertySet::Get<float>(v2, v12, DEPTH_RECURSE);
  v13 = UFG::qSymbol::create_from_string(&v20, "MinRadialHysteresisModifier");
  v3->mMinRadialHysteresisModifier = *UFG::qPropertySet::Get<float>(v2, v13, DEPTH_RECURSE);
  v14 = UFG::qSymbol::create_from_string(&v20, "MaxRadialHysteresisModifier");
  v3->mMaxRadialHysteresisModifier = *UFG::qPropertySet::Get<float>(v2, v14, DEPTH_RECURSE);
  v15 = UFG::qSymbol::create_from_string(&v20, "MaxRadialDistanceFromDesiredPositionHysteresisLarge");
  v3->mMaxRadialDistanceFromDesiredPositionHysteresisLarge = *UFG::qPropertySet::Get<float>(v2, v15, DEPTH_RECURSE);
  v16 = UFG::qSymbol::create_from_string(&v20, "MaxRadialDistanceFromDesiredPositionHysteresis");
  v3->mMaxRadialDistanceFromDesiredPositionHysteresis = *UFG::qPropertySet::Get<float>(v2, v16, DEPTH_RECURSE);
  v17 = UFG::qSymbol::create_from_string(&v20, "MaxRadialDistanceFromDesiredPositionHysteresisFar");
  v3->mMaxRadialDistanceFromDesiredPositionHysteresisFar = *UFG::qPropertySet::Get<float>(v2, v17, DEPTH_RECURSE);
  v18 = UFG::qSymbol::create_from_string(&v20, "MaxLateralDistanceFromDesiredPositionHysteresis");
  v3->mMaxLateralDistanceFromDesiredPositionHysteresis = *UFG::qPropertySet::Get<float>(v2, v18, DEPTH_RECURSE);
  v19 = UFG::qSymbol::create_from_string(&v20, "MaxLateralDistanceFromDesiredPositionHysteresisFar");
  v3->mMaxLateralDistanceFromDesiredPositionHysteresisFar = *UFG::qPropertySet::Get<float>(v2, v19, DEPTH_RECURSE);
}

// File Line: 240
// RVA: 0x367CB0
void __fastcall UFG::PedFormationProfile::InitFromPropertySet(UFG::PedFormationProfile *this, UFG::qPropertySet *pPropertySet)
{
  UFG::qPropertySet *v2; // rdi
  UFG::PedFormationProfile *v3; // rbx
  UFG::qSymbol *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::qSymbol *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::qSymbol *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qSymbol *v10; // rax
  UFG::qSymbol *v11; // rax
  UFG::qPropertyList *v12; // r14
  unsigned int v13; // esi
  unsigned int v14; // edi
  char *v15; // rax
  UFG::qPropertySet *v16; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v19; // rax
  signed __int64 v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v21; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::PedFormationProfile::Slot v28; // [rsp+30h] [rbp-39h]
  UFG::qSymbol result; // [rsp+D0h] [rbp+67h]
  UFG::qList<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList,1,0> *v30; // [rsp+D8h] [rbp+6Fh]
  UFG::qList<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList,1,0> *v31; // [rsp+E0h] [rbp+77h]

  v2 = pPropertySet;
  v3 = this;
  this->mSlots.size = 0;
  *(_QWORD *)&this->mDistanceToBeConsideredClose = 0i64;
  *(_QWORD *)&this->mMaxTimeForLargeHysteresis = 0i64;
  *(_QWORD *)&this->mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = 0i64;
  this->mIsActive = 1;
  if ( pPropertySet )
  {
    this->mNode.mUID = pPropertySet->mName.mUID;
    v4 = UFG::qSymbol::create_from_string(&result, "DistanceToBeConsideredClose");
    v3->mDistanceToBeConsideredClose = *UFG::qPropertySet::Get<float>(v2, v4, DEPTH_RECURSE);
    v5 = UFG::qSymbol::create_from_string(&result, "MinTimeForLargeHysteresis");
    v3->mMinTimeForLargeHysteresis = *UFG::qPropertySet::Get<float>(v2, v5, DEPTH_RECURSE);
    v6 = UFG::qSymbol::create_from_string(&result, "MaxTimeForLargeHysteresis");
    v3->mMaxTimeForLargeHysteresis = *UFG::qPropertySet::Get<float>(v2, v6, DEPTH_RECURSE);
    v7 = UFG::qSymbol::create_from_string(&result, "MinTimeBetweenSlotChanges");
    v3->mMinTimeBetweenSlotChanges = *UFG::qPropertySet::Get<float>(v2, v7, DEPTH_RECURSE);
    v8 = UFG::qSymbol::create_from_string(
           &result,
           "MaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting_Formation");
    v3->mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting = *UFG::qPropertySet::Get<float>(
                                                                                      v2,
                                                                                      v8,
                                                                                      DEPTH_RECURSE);
    v9 = UFG::qSymbol::create_from_string(&result, "Active");
    v3->mIsActive = *UFG::qPropertySet::Get<bool>(v2, v9, DEPTH_RECURSE);
    v10 = UFG::qSymbol::create_from_string(&result, "MaxFollowers");
    v3->mMaxFollowers = *UFG::qPropertySet::Get<unsigned long>(v2, v10, DEPTH_RECURSE);
    v11 = UFG::qSymbol::create_from_string(&result, "SlotList");
    v12 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, v11, DEPTH_RECURSE);
    v13 = v12->mNumElements;
    if ( v13 > 9 )
      v13 = 9;
    if ( v3->mMaxFollowers > v13 )
      v3->mMaxFollowers = v13;
    v14 = 0;
    if ( v13 )
    {
      v30 = &v28.m_SafePointerList;
      v31 = &v28.m_SafePointerList;
      do
      {
        v15 = UFG::qPropertyList::GetValuePtr(v12, 0x1Au, v14);
        if ( !v15 || (v16 = (UFG::qPropertySet *)&v15[*(_QWORD *)v15], !*(_QWORD *)v15) )
          v16 = 0i64;
        v28.vfptr = (UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>Vtbl *)&UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>::`vftable';
        v28.m_SafePointerList.mNode.mPrev = &v28.m_SafePointerList.mNode;
        v28.m_SafePointerList.mNode.mNext = &v28.m_SafePointerList.mNode;
        v17 = &v28.m_SafePointerList.mNode;
        if ( &v28.m_SafePointerList != &v28.m_SafePointerList )
        {
          do
          {
            v18 = v17->mPrev;
            v19 = v17->mNext;
            v18->mNext = v19;
            v19->mPrev = v18;
            v17->mPrev = v17;
            v17->mNext = v17;
            v17 = v28.m_SafePointerList.mNode.mNext;
          }
          while ( (UFG::qList<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList,1,0> *)v28.m_SafePointerList.mNode.mNext != &v28.m_SafePointerList );
        }
        v28.vfptr = (UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>Vtbl *)&UFG::PedFormationProfile::Slot::`vftable';
        v28.mFacingType = 0;
        v28.mAngle = 0;
        v28.mCanCrossLeader = 0;
        v28.mPreference = 1.0;
        *(_QWORD *)&v28.mMinFollowers = 1i64;
        v28.mMaxDistance = 0.0;
        *(_OWORD *)&v28.mMaxLookAhead = 0i64;
        *(_OWORD *)&v28.mMaxLateralDistanceFromDesiredPosition = 0i64;
        *(_OWORD *)&v28.mMaxRadialDistanceFromDesiredPositionHysteresis = 0i64;
        UFG::PedFormationProfile::Slot::InitFromPropertySet(&v28, v16);
        v20 = v3->mSlots.size;
        v3->mSlots.p[v20].mFacingType = v28.mFacingType;
        v3->mSlots.p[v20].mAngle = v28.mAngle;
        v3->mSlots.p[v20].mCanCrossLeader = v28.mCanCrossLeader;
        v3->mSlots.p[v20].mPreference = v28.mPreference;
        *(_QWORD *)&v3->mSlots.p[v20].mMinFollowers = *(_QWORD *)&v28.mMinFollowers;
        v3->mSlots.p[v20].mMaxDistance = v28.mMaxDistance;
        v3->mSlots.p[v20].mMaxLookAhead = v28.mMaxLookAhead;
        v3->mSlots.p[v20].mMinFacingDifference = v28.mMinFacingDifference;
        v3->mSlots.p[v20].mMinFacingDifferenceHysteresis = v28.mMinFacingDifferenceHysteresis;
        v3->mSlots.p[v20].mMaxRadialDistanceFromDesiredPosition = v28.mMaxRadialDistanceFromDesiredPosition;
        v3->mSlots.p[v20].mMaxLateralDistanceFromDesiredPosition = v28.mMaxLateralDistanceFromDesiredPosition;
        v3->mSlots.p[v20].mMinRadialHysteresisModifier = v28.mMinRadialHysteresisModifier;
        v3->mSlots.p[v20].mMaxRadialHysteresisModifier = v28.mMaxRadialHysteresisModifier;
        v3->mSlots.p[v20].mMaxRadialDistanceFromDesiredPositionHysteresisLarge = v28.mMaxRadialDistanceFromDesiredPositionHysteresisLarge;
        v3->mSlots.p[v20].mMaxRadialDistanceFromDesiredPositionHysteresis = v28.mMaxRadialDistanceFromDesiredPositionHysteresis;
        v3->mSlots.p[v20].mMaxRadialDistanceFromDesiredPositionHysteresisFar = v28.mMaxRadialDistanceFromDesiredPositionHysteresisFar;
        v3->mSlots.p[v20].mMaxLateralDistanceFromDesiredPositionHysteresis = v28.mMaxLateralDistanceFromDesiredPositionHysteresis;
        v3->mSlots.p[v20].mMaxLateralDistanceFromDesiredPositionHysteresisFar = v28.mMaxLateralDistanceFromDesiredPositionHysteresisFar;
        ++v3->mSlots.size;
        v28.vfptr = (UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>Vtbl *)&UFG::qSafePointerNode<UFG::PedFormationProfile::Slot>::`vftable';
        v21 = v28.m_SafePointerList.mNode.mNext;
        if ( (UFG::qList<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList,1,0> *)v28.m_SafePointerList.mNode.mNext != &v28.m_SafePointerList )
        {
          while ( (unsigned __int64)v21 >= 0x10 )
          {
            if ( v21[1].mPrev
              || (v22 = v21->mPrev,
                  v23 = v21->mNext,
                  v22->mNext = v23,
                  v23->mPrev = v22,
                  v21->mPrev = v21,
                  v21->mNext = v21,
                  v21[1].mPrev) )
            {
              v24 = v21->mPrev;
              v25 = v21->mNext;
              v24->mNext = v25;
              v25->mPrev = v24;
              v21->mPrev = v21;
              v21->mNext = v21;
            }
            v21[1].mPrev = 0i64;
            v21 = v28.m_SafePointerList.mNode.mNext;
            if ( (UFG::qList<UFG::qSafePointerBase<UFG::PedFormationProfile::Slot>,UFG::qSafePointerNodeList,1,0> *)v28.m_SafePointerList.mNode.mNext == &v28.m_SafePointerList )
              goto LABEL_21;
          }
          v28.m_SafePointerList.mNode.mPrev = &v28.m_SafePointerList.mNode;
          v28.m_SafePointerList.mNode.mNext = &v28.m_SafePointerList.mNode;
        }
LABEL_21:
        UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v28.m_SafePointerList);
        v26 = v28.m_SafePointerList.mNode.mPrev;
        v27 = v28.m_SafePointerList.mNode.mNext;
        v28.m_SafePointerList.mNode.mPrev->mNext = v28.m_SafePointerList.mNode.mNext;
        v27->mPrev = v26;
        v28.m_SafePointerList.mNode.mPrev = &v28.m_SafePointerList.mNode;
        v28.m_SafePointerList.mNode.mNext = &v28.m_SafePointerList.mNode;
        ++v14;
      }
      while ( v14 < v13 );
    }
  }
}

// File Line: 323
// RVA: 0x384C60
void __fastcall UFG::PedFormationTimer::Set(UFG::PedFormationTimer *this, float min_time, float max_time)
{
  UFG::PedFormationTimer *v3; // rbx
  float v4; // xmm8_4
  float v5; // xmm0_4

  v3 = this;
  v4 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( min_time < 0.0 || max_time <= 0.0 )
  {
    this->mNextTime = -1.0;
  }
  else
  {
    v5 = max_time;
    if ( max_time > min_time )
    {
      v5 = UFG::qRandom(max_time - min_time, &UFG::qDefaultSeed) + min_time;
      if ( v5 <= min_time )
        v5 = min_time;
      if ( v5 >= max_time )
        v5 = max_time;
    }
    v3->mNextTime = v5 + v4;
  }
}

// File Line: 399
// RVA: 0x3689F0
void __fastcall UFG::PedFormationSlot::InitWithDefaults(UFG::PedFormationSlot *this, UFG::PedFormationManagerComponent *parent)
{
  UFG::PedFormationManagerComponent *v2; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *v3; // rdx
  UFG::PedFormationSlot *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v10; // rax
  signed __int64 v11; // r8
  __int64 v12; // rcx
  _QWORD *v13; // rax

  v2 = parent;
  v3 = &this->m_pPedFormationManagerComponent;
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
  v4 = this;
  if ( this->m_pPedFormationManagerComponent.m_pPointer )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = (UFG::SimComponent *)&v2->vfptr;
  if ( v2 )
  {
    v7 = v2->m_SafePointerList.mNode.mPrev;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mPrev = v7;
    v3->mNext = &v2->m_SafePointerList.mNode;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v8 = &v4->m_pMember;
  v4->m_pProfileSlot = 0i64;
  v4->m_SlotChangeAllowedTimer.mNextTime = -1.0;
  if ( v4->m_pMember.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v4->m_pMember.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v4->m_pMember.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v4->m_pMember.mPrev;
  }
  v11 = (signed __int64)&v4->m_Pair;
  v8->m_pPointer = 0i64;
  if ( *(_QWORD *)(v11 + 16) )
  {
    v12 = *(_QWORD *)v11;
    v13 = *(_QWORD **)(v11 + 8);
    *(_QWORD *)(v12 + 8) = v13;
    *v13 = v12;
    *(_QWORD *)v11 = v11;
    *(_QWORD *)(v11 + 8) = v11;
  }
  *(_QWORD *)(v11 + 16) = 0i64;
  *(_DWORD *)(v11 + 24) = -1082130432;
}

// File Line: 430
// RVA: 0x387B70
void __fastcall UFG::PedFormationSlot::SetRadialHysteresisModifier(UFG::PedFormationSlot *this)
{
  UFG::PedFormationProfile::Slot *v1; // rax
  UFG::PedFormationSlot *v2; // rbx
  float v3; // xmm6_4
  float v4; // xmm7_4
  float v5; // xmm0_4

  v1 = this->m_pProfileSlot;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->mMaxRadialHysteresisModifier;
    v4 = v1->mMinRadialHysteresisModifier;
    v5 = v1->mMaxRadialHysteresisModifier;
    if ( v3 > v4 )
    {
      v5 = UFG::qRandom(v3 - v4, &UFG::qDefaultSeed) + v4;
      if ( v5 <= v4 )
        v5 = v4;
      if ( v5 >= v3 )
        v5 = v3;
    }
    v2->m_RadialHysteresisModifier = v5;
  }
}

// File Line: 439
// RVA: 0x386760
void __fastcall UFG::PedFormationSlot::SetInPosition(UFG::PedFormationSlot *this, UFG::PedFormationSlot::ePositionType in_position)
{
  UFG::PedFormationSlot::ePositionType v2; // edi
  UFG::PedFormationSlot *v3; // rbx
  float v4; // xmm0_4

  v2 = in_position;
  v3 = this;
  if ( this->m_InPosition && in_position == ePOSITION_IN_POSITION )
  {
    v4 = UFG::Metrics::msInstance.mSimTime_Temp;
    this->m_DesiredMoveType = 1;
    this->m_TimeGotIntoPosition = v4;
    UFG::PedFormationSlot::SetRadialHysteresisModifier(this);
  }
  if ( v3->m_InPosition != v2 )
    v3->m_InPosition = v2;
}

// File Line: 459
// RVA: 0x14AEBA0
__int64 dynamic_initializer_for__UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList__);
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
  `eh vector constructor iterator'(
    &ptr,
    0x3A8ui64,
    16,
    (void (__fastcall *)(void *))UFG::PedFormationProfile::PedFormationProfile);
  UFG::PedFormationManagerComponent::s_ProfilePool.size = 0;
  return atexit(dynamic_atexit_destructor_for__UFG::PedFormationManagerComponent::s_ProfilePool__);
}

// File Line: 463
// RVA: 0x14AEC60
__int64 dynamic_initializer_for__UFG::PedFormationManagerComponent::s_Profiles__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PedFormationManagerComponent::s_Profiles.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::PedFormationManagerComponent::s_Profiles__);
}

// File Line: 468
// RVA: 0x389030
void UFG::PedFormationManagerComponent::StaticInit(void)
{
  UFG::qPropertySet *v0; // rbx
  UFG::qPropertyList *v1; // rax
  UFG::qPropertyList *v2; // rbp
  unsigned int v3; // esi
  unsigned int v4; // edi
  UFG::qSymbol *v5; // rax
  UFG::qSymbolUC *v6; // rbx
  UFG::qPropertySet *v7; // rax
  unsigned int v8; // ecx
  UFG::PedFormationProfile *v9; // rbx
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax
  char *v13; // rax
  UFG::qSymbol name; // [rsp+40h] [rbp+8h]
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  UFG::qSymbol::create_from_string(&result, "default-formation-manifest");
  v0 = UFG::PropertySetManager::GetPropertySet(&result);
  if ( v0 )
  {
    UFG::qSymbol::create_from_string(&name, "archetypes");
    v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(v0, &name, DEPTH_RECURSE);
    v2 = v1;
    if ( v1 )
    {
      v3 = v1->mNumElements;
      v4 = 0;
      if ( v3 )
      {
        do
        {
          v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v2, v4);
          v6 = (UFG::qSymbolUC *)v5;
          if ( v5 )
          {
            v7 = UFG::PropertySetManager::GetPropertySet(v5);
            if ( v7 )
            {
              v8 = UFG::PedFormationManagerComponent::s_ProfilePool.size;
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
                v9 = &ptr + v8;
                UFG::PedFormationProfile::InitFromPropertySet(&ptr + v8, v7);
                UFG::qBaseTreeRB::Add(&UFG::PedFormationManagerComponent::s_Profiles.mTree, &v9->mNode);
              }
            }
            else
            {
              v11 = UFG::qSymbol::as_cstr_dbg(v6);
              UFG::qPrintf("WARNING: PedFormationManagerComponent::StaticInit: Profile Not Found: %s\n", v11);
            }
          }
          ++v4;
        }
        while ( v4 < v3 );
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
    v13 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
    UFG::qPrintf("WARNING: PedFormationManagerComponent::StaticInit: Manifest File Not Found: %s\n", v13);
  }
}

// File Line: 547
// RVA: 0x331090
void __fastcall UFG::PedFormationManagerComponent::PedFormationManagerComponent(UFG::PedFormationManagerComponent *this, unsigned int name_uid, UFG::qPropertySet *properties)
{
  UFG::PedFormationManagerComponent *v3; // rsi
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *v4; // rdi
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *v5; // rax
  UFG::PedFormationPair *v6; // [rsp+78h] [rbp+20h]
  UFG::Ticket *v7; // [rsp+78h] [rbp+20h]

  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable';
  v4 = (UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PedFormationManagerComponent::`vftable'{for `UFG::SimComponent'};
  v3->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::PedFormationManagerComponent::`vftable'{for `UFG::UpdateInterface'};
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v3->m_pTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::RebindingComponentHandle<UFG::AIEntityComponent,0>(&v3->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::RebindingComponentHandle<UFG::ActionTreeComponent,0>(&v3->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&v3->m_pTargetingSystemBaseComponent);
  `eh vector constructor iterator'(
    v3->m_Slots.p,
    0xA0ui64,
    4,
    (void (__fastcall *)(void *))UFG::PedFormationSlot::PedFormationSlot);
  v3->m_Slots.size = 0;
  v3->m_CurrentlySprinting = 0;
  *(_QWORD *)&v3->m_LeaderMoveType = 1i64;
  *(_QWORD *)&v3->m_AngularVelocity = 0i64;
  *(_QWORD *)&v3->m_FormationForward.y = 0i64;
  v3->m_PrevFormationForward.y = 0.0;
  `eh vector constructor iterator'(
    v3->m_ProfileSlots.p,
    0x38ui64,
    9,
    (void (__fastcall *)(void *))UFG::PedFormationProfileSlot::PedFormationProfileSlot);
  v3->m_ProfileSlots.size = 0;
  v6 = &v3->m_Pair;
  v6->m_pPair.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->m_pPair.mPrev;
  v6->m_pPair.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->m_pPair.mPrev;
  v3->m_Pair.m_pPair.m_pPointer = 0i64;
  v3->m_Pair.m_PairChangeAllowedTimer.mNextTime = -1.0;
  v3->m_LeaderWaitTime.mNextTime = -1.0;
  v3->m_LeaderNoWaitTime.mNextTime = -1.0;
  *(_QWORD *)&v3->m_Destination.x = 0i64;
  v3->m_Destination.z = 0.0;
  *(_WORD *)&v3->m_IsDestinationValid = 0;
  v7 = &v3->m_Ticket;
  v7->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v7->mPrev;
  v3->m_Ticket.mTimestamp = 0i64;
  v3->m_Ticket.mActiveCallback.m_Closure.m_pthis = 0i64;
  v3->m_Ticket.mActiveCallback.m_Closure.m_pFunction = 0i64;
  v3->m_Ticket.mInactiveCallback.m_Closure.m_pthis = 0i64;
  v3->m_Ticket.mInactiveCallback.m_Closure.m_pFunction = 0i64;
  v5 = UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList.mNode.mPrev;
  UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *)&UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList;
  UFG::PedFormationManagerComponent::s_PedFormationManagerComponentList.mNode.mPrev = (UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::PedFormationManagerComponent::_PedFormationManagerComponentTypeUID,
    "PedFormationManagerComponent");
  v3->m_DebugDrawEnabled = 0;
  UFG::PedFormationManagerComponent::SetCurrentProfile(v3, &ptr);
}

// File Line: 557
// RVA: 0x339EC0
void __fastcall UFG::PedFormationManagerComponent::~PedFormationManagerComponent(UFG::PedFormationManagerComponent *this)
{
  UFG::PedFormationManagerComponent *v1; // rbx
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *v2; // rdi
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *v3; // rcx
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *v4; // rax
  UFG::Ticket *v5; // rdx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v6; // rcx
  UFG::qNode<UFG::Ticket,UFG::Ticket> *v7; // rax
  UFG::PedFormationPair *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *v13; // rcx
  UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *v14; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PedFormationManagerComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::PedFormationManagerComponent::`vftable'{for `UFG::UpdateInterface'};
  if ( this == UFG::PedFormationManagerComponent::s_PedFormationManagerComponentpCurrentIterator )
    UFG::PedFormationManagerComponent::s_PedFormationManagerComponentpCurrentIterator = (UFG::PedFormationManagerComponent *)&this->mPrev[-5].mNext;
  v2 = (UFG::qNode<UFG::PedFormationManagerComponent,UFG::PedFormationManagerComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->m_Ticket;
  v6 = v1->m_Ticket.mPrev;
  v7 = v1->m_Ticket.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::Ticket,UFG::Ticket> *)&v5->mPrev;
  v8 = &v1->m_Pair;
  if ( v1->m_Pair.m_pPair.m_pPointer )
  {
    v9 = v8->m_pPair.mPrev;
    v10 = v1->m_Pair.m_pPair.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->m_pPair.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->m_pPair.mPrev;
    v1->m_Pair.m_pPair.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_Pair.m_pPair.mPrev;
  }
  v1->m_Pair.m_pPair.m_pPointer = 0i64;
  v11 = v8->m_pPair.mPrev;
  v12 = v1->m_Pair.m_pPair.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v8->m_pPair.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->m_pPair.mPrev;
  v1->m_Pair.m_pPair.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_Pair.m_pPair.mPrev;
  v1->m_ProfileSlots.size = 0;
  `eh vector destructor iterator'(
    v1->m_ProfileSlots.p,
    0x38ui64,
    9,
    (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
  v1->m_Slots.size = 0;
  `eh vector destructor iterator'(
    v1->m_Slots.p,
    0xA0ui64,
    4,
    (void (__fastcall *)(void *))UFG::PedFormationSlot::~PedFormationSlot);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pActionTreeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->m_pTransformNodeComponent);
  v13 = v2->mPrev;
  v14 = v2->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 574
// RVA: 0x37F190
UFG::SimComponent *__fastcall UFG::PedFormationManagerComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::qPropertySet *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rdi
  UFG::SimObject *v8; // rdx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x650ui64, "PedFormationManagerComponent", 0i64, 1u);
  if ( v4 )
  {
    v5 = v2->mpWritableProperties;
    if ( !v5 )
      v5 = v2->mpConstProperties;
    UFG::PedFormationManagerComponent::PedFormationManagerComponent(
      (UFG::PedFormationManagerComponent *)v4,
      v2->m_NameUID,
      v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v2->m_pSimObject;
  if ( (v8->m_Flags >> 14) & 1 )
    v9 = 33;
  else
    v9 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, v8, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v7, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return v7;
}

// File Line: 582
// RVA: 0x385370
void __fastcall UFG::PedFormationManagerComponent::SetCurrentProfile(UFG::PedFormationManagerComponent *this, UFG::PedFormationProfile *pCurrentProfile)
{
  UFG::PedFormationProfile *v2; // rdi
  UFG::PedFormationManagerComponent *v3; // rbx
  unsigned int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // er8
  unsigned int v7; // ecx
  signed __int64 v8; // r9
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v9; // r10
  __int64 *v10; // rax
  __int64 v11; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v12; // rcx
  __int64 v13; // rcx

  v2 = pCurrentProfile;
  v3 = this;
  UFG::PedFormationManagerComponent::Clear(this);
  if ( v3->m_pCurrentProfile != v2 )
  {
    v3->m_pCurrentProfile = v2;
    if ( v2 )
    {
      v4 = v2->mMaxFollowers;
      v3->m_Slots.size = v4;
      v5 = 0;
      if ( v4 )
      {
        do
          UFG::PedFormationSlot::InitWithDefaults(&v3->m_Slots.p[v5++], v3);
        while ( v5 < v3->m_Slots.size );
      }
      v6 = 0;
      v7 = v3->m_pCurrentProfile->mSlots.size;
      v3->m_ProfileSlots.size = v7;
      if ( v7 )
      {
        do
        {
          v8 = (signed __int64)&v3->m_pCurrentProfile->mSlots.p[v6];
          v9 = &(&v3->vfptr)[7 * v6];
          v10 = (__int64 *)(v9 + 125);
          if ( v9[127] )
          {
            v11 = *v10;
            v12 = v9[126];
            *(_QWORD *)(v11 + 8) = v12;
            v12->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v11;
            *v10 = (__int64)v10;
            v9[126] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)(v9 + 125);
          }
          v9[127] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v8;
          if ( v8 )
          {
            v13 = *(_QWORD *)(v8 + 8);
            *(_QWORD *)(v13 + 8) = v10;
            *v10 = v13;
            v9[126] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)(v8 + 8);
            *(_QWORD *)(v8 + 8) = v10;
          }
          ++v6;
          v9[128] = 0i64;
        }
        while ( v6 < v3->m_ProfileSlots.size );
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
  UFG::PedFormationManagerComponent *v1; // rbx
  unsigned int v2; // edi
  unsigned int i; // er8
  signed __int64 v4; // rdx
  __int64 v5; // rcx
  _QWORD *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4
  signed __int64 v9; // rbx
  __int64 v10; // rcx
  _QWORD *v11; // rax

  v1 = this;
  *(_QWORD *)&this->m_NumFreeSlots = 0i64;
  v2 = 0;
  if ( this->m_Slots.size )
  {
    do
      UFG::PedFormationSlot::InitWithDefaults(&v1->m_Slots.p[v2++], v1);
    while ( v2 < v1->m_Slots.size );
  }
  v1->m_Slots.size = 0;
  for ( i = 0; i < v1->m_ProfileSlots.size; *(_QWORD *)(v4 + 48) = 0i64 )
  {
    v4 = (signed __int64)&v1->m_ProfileSlots.p[i];
    if ( *(_QWORD *)(v4 + 16) )
    {
      v5 = *(_QWORD *)v4;
      v6 = *(_QWORD **)(v4 + 8);
      *(_QWORD *)(v5 + 8) = v6;
      *v6 = v5;
      *(_QWORD *)v4 = v4;
      *(_QWORD *)(v4 + 8) = v4;
    }
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 24) = 0i64;
    *(_WORD *)(v4 + 44) = 0;
    v7 = UFG::qVector3::msZero.y;
    v8 = UFG::qVector3::msZero.z;
    ++i;
    *(float *)(v4 + 32) = UFG::qVector3::msZero.x;
    *(float *)(v4 + 36) = v7;
    *(float *)(v4 + 40) = v8;
  }
  v1->m_ProfileSlots.size = 0;
  v1->m_pCurrentProfile = 0i64;
  v9 = (signed __int64)&v1->m_Pair;
  if ( *(_QWORD *)(v9 + 16) )
  {
    v10 = *(_QWORD *)v9;
    v11 = *(_QWORD **)(v9 + 8);
    *(_QWORD *)(v10 + 8) = v11;
    *v11 = v10;
    *(_QWORD *)v9 = v9;
    *(_QWORD *)(v9 + 8) = v9;
  }
  *(_QWORD *)(v9 + 16) = 0i64;
  *(_DWORD *)(v9 + 24) = -1082130432;
}

// File Line: 635
// RVA: 0x3790C0
void __fastcall UFG::PedFormationManagerComponent::OnAttach(UFG::PedFormationManagerComponent *this, UFG::SimObject *object)
{
  UFG::PedFormationManagerComponent *v2; // rdi
  UFG::SimObjectCharacter *v3; // rbx
  hkSeekableStreamReader *v4; // [rsp+20h] [rbp-18h]
  void (__fastcall *v5)(UFG::PedFormationManagerComponent *, float); // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = (UFG::SimObjectCharacter *)object;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_pTransformNodeComponent,
    (UFG::SimObjectCharacter *)object);
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0>::Bind<UFG::SimObjectCharacter>(&v2->m_pAIEntityComponent, v3);
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pActionTreeComponent,
    v3);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->m_pTargetingSystemBaseComponent,
    v3);
  v5 = UFG::PedFormationManagerComponent::UpdatePeriodic;
  v4 = Assembly::GetRCX(v2);
  UFG::TicketBoothManager::Register(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_PEDFORMATIONMANANGER_UPDATE,
    &v2->m_Ticket,
    (fastdelegate::FastDelegate1<float,void> *)&v4);
}

// File Line: 646
// RVA: 0x37AE80
void __fastcall UFG::PedFormationManagerComponent::OnDetach(UFG::PedFormationManagerComponent *this)
{
  UFG::PedFormationManagerComponent *v1; // rbx
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v2; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax

  v1 = this;
  UFG::TicketBoothManager::Unregister(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_PEDFORMATIONMANANGER_UPDATE,
    &this->m_Ticket);
  v2 = &v1->m_pTransformNodeComponent;
  if ( v1->m_pTransformNodeComponent.m_pSimComponent )
  {
    v3 = v2->mPrev;
    v4 = v1->m_pTransformNodeComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->m_pTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pTransformNodeComponent.m_pSimObject = 0i64;
    v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pTransformNodeComponent.mPrev;
    v2->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mPrev;
    goto LABEL_8;
  }
  if ( v1->m_pTransformNodeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v2->mPrev != v2
     || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->m_pTransformNodeComponent.mNext != &v1->m_pTransformNodeComponent) )
  {
    v5 = v2->mPrev;
    v6 = v1->m_pTransformNodeComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v1->m_pAIEntityComponent;
  v1->m_pTransformNodeComponent.m_Changed = 1;
  if ( v1->m_pAIEntityComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v1->m_pAIEntityComponent.m_pSimComponent = 0i64;
LABEL_14:
    v1->m_pAIEntityComponent.m_pSimObject = 0i64;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pAIEntityComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v1->m_pAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::AIEntityComponent,0> *)v1->m_pAIEntityComponent.mNext != &v1->m_pAIEntityComponent) )
  {
    v10 = v7->mPrev;
    v11 = v1->m_pAIEntityComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v1->m_pAIEntityComponent.m_Changed = 1;
  v12 = &v1->m_pActionTreeComponent;
  if ( v1->m_pActionTreeComponent.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pActionTreeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v1->m_pActionTreeComponent.m_pSimComponent = 0i64;
LABEL_21:
    v1->m_pActionTreeComponent.m_pSimObject = 0i64;
    v1->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pActionTreeComponent.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v1->m_pActionTreeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::ActionTreeComponent,0> *)v1->m_pActionTreeComponent.mNext != &v1->m_pActionTreeComponent) )
  {
    v15 = v12->mPrev;
    v16 = v1->m_pActionTreeComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v1->m_pActionTreeComponent.m_Changed = 1;
  v17 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v1->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v1->m_pTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_28:
    v1->m_pTargetingSystemBaseComponent.m_pSimObject = 0i64;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_29;
  }
  if ( v1->m_pTargetingSystemBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v1->m_pTargetingSystemBaseComponent.mNext != &v1->m_pTargetingSystemBaseComponent) )
  {
    v20 = v17->mPrev;
    v21 = v1->m_pTargetingSystemBaseComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  v1->m_pTargetingSystemBaseComponent.m_Changed = 1;
  UFG::PedFormationManagerComponent::Clear(v1);
}

// File Line: 669
// RVA: 0x3982B0
void __fastcall UFG::PedFormationManagerComponent::UpdateProfileSlots(UFG::PedFormationManagerComponent *this)
{
  UFG::PedFormationManagerComponent *v1; // rdi
  UFG::SimObjectGame *v2; // rcx
  UFG::SimComponent *v3; // rax
  unsigned __int16 v4; // dx
  UFG::HavokNavPosition *v5; // r15
  unsigned int i; // ebp
  signed __int64 v7; // rsi
  UFG::PedFormationProfile::Slot *v8; // rax
  __m128 v9; // xmm3
  float v10; // xmm4_4
  UFG::TransformNodeComponent *v11; // rcx
  __m128 v12; // xmm1
  float v13; // xmm2_4
  UFG::PedFormationProfile::Slot *v14; // rbx
  float v15; // xmm8_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  float *v19; // r14
  float v20; // xmm4_4
  float v21; // xmm0_4
  bool v22; // al
  float *v23; // rbx
  unsigned int v24; // eax
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  UFG::qVector3 direction; // [rsp+30h] [rbp-118h]
  UFG::HavokNavPosition npStartPos; // [rsp+40h] [rbp-108h]

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = v2->m_Components.p[36].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::NavComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
    }
  }
  else
  {
    v3 = 0i64;
  }
  if ( v1->m_pTransformNodeComponent.m_pSimComponent )
  {
    if ( v3 )
    {
      v5 = (UFG::HavokNavPosition *)&v3[1].m_SafePointerList.mNode.mNext;
      for ( i = 0; i < v1->m_ProfileSlots.size; ++i )
      {
        v7 = i;
        v8 = v1->m_ProfileSlots.p[v7].mProfileSlot.m_pPointer;
        if ( v8 )
        {
          v9 = (__m128)LODWORD(v1->m_FormationForward.x);
          v10 = v1->m_FormationForward.y;
          v11 = (UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent;
          v12 = v9;
          v12.m128_f32[0] = (float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v10 * v10);
          v13 = v8->mMaxLookAhead / COERCE_FLOAT(_mm_sqrt_ps(v12));
          direction.z = v13 * 0.0;
          direction.x = v9.m128_f32[0] * v13;
          direction.y = v10 * v13;
          UFG::TransformNodeComponent::UpdateWorldTransform(v11);
          v14 = v1->m_ProfileSlots.p[v7].mProfileSlot.m_pPointer;
          v15 = UFG::qVector3::msZero.z;
          v16 = (float)((float)(unsigned __int16)(v14->mAngle
                                                + (signed int)(float)((float)(atan2f(
                                                                                v1->m_FormationForward.y,
                                                                                v1->m_FormationForward.x)
                                                                            * 32768.0)
                                                                    * 0.31830987))
                      * 3.1415927)
              * 0.000030517578;
          v17 = sinf(v16);
          v18 = cosf(v16);
          v19 = &v1->m_ProfileSlots.p[v7].mOffset.x;
          v20 = v14->mMaxDistance / fsqrt((float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(v15 * v15));
          *v19 = v18 * v20;
          v19[1] = v17 * v20;
          v19[2] = v15 * v20;
          if ( v1->m_NumFollowers < v1->m_ProfileSlots.p[v7].mProfileSlot.m_pPointer->mMinFollowers )
          {
            *(_WORD *)&v1->m_ProfileSlots.p[v7].mIsClear = 0;
            *(_QWORD *)&v1->m_ProfileSlots.p[v7].mForwardClearance = 0i64;
          }
          else
          {
            v1->m_ProfileSlots.p[v7].mIsEnabled = 1;
            UFG::PedFormationManagerComponent::DirectionIsClear(
              v1,
              v5,
              &v1->m_ProfileSlots.p[v7].mOffset,
              &v1->m_ProfileSlots.p[v7].mClearDistance,
              0);
            v21 = v1->m_ProfileSlots.p[v7].mProfileSlot.m_pPointer->mMinDistance;
            v1->m_ProfileSlots.p[v7].mForwardClearance = 0.0;
            v22 = (float)(v21 - 0.0099999998) <= v1->m_ProfileSlots.p[v7].mClearDistance;
            v1->m_ProfileSlots.p[v7].mIsClear = v22;
            if ( v22 )
            {
              v23 = (float *)v1->m_pTransformNodeComponent.m_pSimComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent);
              v24 = v5->m_packedKey;
              v25 = v23[44];
              v26 = v23[45];
              v27 = v23[46];
              npStartPos.m_hkvMeshPosition = v5->m_hkvMeshPosition;
              npStartPos.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
              npStartPos.m_packedKey = v24;
              npStartPos.m_aiMeshUid = -1;
              v28 = v25 + *v19;
              v29 = v26 + v19[1];
              v30 = v27 + v19[2];
              npStartPos.m_bValid = 0;
              npStartPos.m_vPosition.x = v28;
              npStartPos.m_vPosition.y = v29;
              npStartPos.m_vPosition.z = v30;
              UFG::HavokNavPosition::Validate(&npStartPos, 1.0, 1.0, 0.0);
              UFG::PedFormationManagerComponent::DirectionIsClear(
                v1,
                &npStartPos,
                &direction,
                &v1->m_ProfileSlots.p[v7].mForwardClearance,
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
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rdx
  UFG::PedFormationManagerComponent *v3; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rdx
  UFG::PedFormationProfile *v5; // rdx

  v2 = this->m_pTransformNodeComponent.mNext;
  v3 = this;
  if ( v2 )
  {
    v4 = v2[60].mPrev;
    if ( v4 )
    {
      v5 = (UFG::PedFormationProfile *)v4[14].mPrev;
      if ( v5 )
      {
        if ( v5 != *(UFG::PedFormationProfile **)&this->m_Slots.p[3].m_TimeGotIntoPosition )
          UFG::PedFormationManagerComponent::SetCurrentProfile(
            (UFG::PedFormationManagerComponent *)((char *)this - 64),
            v5);
      }
    }
  }
  if ( *(_QWORD *)&v3->m_Slots.p[3].m_TimeGotIntoPosition )
  {
    UFG::PedFormationManagerComponent::UpdateSpeed((UFG::PedFormationManagerComponent *)((char *)v3 - 64), delta_sec);
    UFG::PedFormationManagerComponent::CheckIfSprinting((UFG::PedFormationManagerComponent *)((char *)v3 - 64));
  }
}

// File Line: 731
// RVA: 0x397F60
void __fastcall UFG::PedFormationManagerComponent::UpdatePeriodic(UFG::PedFormationManagerComponent *this, float delta_sec)
{
  UFG::PedFormationManagerComponent *v2; // rbx
  unsigned int v3; // edx
  UFG::GetInPedFormationNode **v4; // rax
  __int64 v5; // rcx

  v2 = this;
  if ( !((LOBYTE(this->m_Flags) >> 1) & 1) && this->m_pCurrentProfile )
  {
    UFG::PedFormationManagerComponent::UnregisterIncorrectlyRegisteredPeople(this);
    UFG::PedFormationManagerComponent::UnregisterInvalidFollowers(v2);
    v3 = v2->m_Slots.size;
    *(_QWORD *)&v2->m_NumFreeSlots = 0i64;
    if ( v3 )
    {
      v4 = &v2->m_Slots.p[0].m_pMember.m_pPointer;
      v5 = v3;
      do
      {
        if ( *v4 )
          ++v2->m_NumFollowers;
        else
          ++v2->m_NumFreeSlots;
        v4 += 20;
        --v5;
      }
      while ( v5 );
    }
    if ( v2->m_pCurrentProfile->mIsActive )
    {
      if ( v3 )
      {
        UFG::PedFormationManagerComponent::UpdateProfileSlots(v2);
        UFG::PedFormationManagerComponent::UpdateDesiredFacing(v2);
        UFG::PedFormationManagerComponent::CheckIfInDesiredPosition(v2);
        UFG::PedFormationManagerComponent::MaybeSetDesiredPositionFromProfile(v2);
        UFG::PedFormationManagerComponent::UpdatePairs(v2);
      }
    }
  }
}

// File Line: 757
// RVA: 0x398D80
void __fastcall UFG::PedFormationManagerComponent::UpdateSpeed(UFG::PedFormationManagerComponent *this, float delta_sec)
{
  UFG::PedFormationManagerComponent *v2; // rdi
  float v3; // xmm7_4
  UFG::SimComponent *v4; // rbx
  __m128 v5; // xmm2
  UFG::SimComponent *v6; // rbx
  float v7; // xmm1_4
  UFG::SimObject *v8; // r8
  UFG::NavComponent *v9; // rsi
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  bool v12; // zf
  UFG::SimObjectGame *v13; // rcx
  UFG::NavModuleLocal *v14; // rbx
  UFG::qVector4 *v15; // rax
  float v16; // xmm3_4
  float v17; // xmm4_4
  __m128 v18; // xmm1
  float v19; // xmm2_4
  int v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  UFG::qVector3 n2; // [rsp+20h] [rbp-48h]
  UFG::qVector3 n1; // [rsp+2Ch] [rbp-3Ch]

  v2 = this;
  v3 = delta_sec;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v4 = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    v5 = (__m128)HIDWORD(v4[4].vfptr);
    v5.m128_f32[0] = (float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(*(float *)&v4[4].vfptr * *(float *)&v4[4].vfptr);
    LODWORD(v2->m_Speed) = (unsigned __int128)_mm_sqrt_ps(v5);
    v6 = v2->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pSimComponent);
    v7 = *((float *)&v6[2].vfptr + 1);
    v2->m_FormationForward.x = *(float *)&v6[2].vfptr;
    v2->m_FormationForward.y = v7;
    v8 = v2->m_pSimObject;
    if ( v8 )
    {
      v10 = v8->m_Flags;
      if ( (v10 >> 14) & 1 )
      {
        v9 = (UFG::NavComponent *)v8->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)v2->m_pSimObject,
                    UFG::NavComponent::_TypeUID);
          }
          else
          {
            v12 = ((v10 >> 12) & 1) == 0;
            v13 = (UFG::SimObjectGame *)v2->m_pSimObject;
            if ( v12 )
              v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::NavComponent::_TypeUID);
            else
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::NavComponent::_TypeUID);
          }
        }
        else
        {
          v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)v2->m_pSimObject,
                  UFG::NavComponent::_TypeUID);
        }
        v9 = (UFG::NavComponent *)v11;
      }
    }
    else
    {
      v9 = 0i64;
    }
    if ( UFG::NavComponent::HasDestination(v9) )
    {
      v14 = v9->m_pNavModuleLocal;
      v15 = UFG::NavComponent::GetCurrentPosition(v9);
      v18 = (__m128)LODWORD(v14->m_adjustedWaypoint.m_navPosition.m_vPosition.z);
      v16 = v14->m_adjustedWaypoint.m_navPosition.m_vPosition.x - v15->x;
      v17 = v14->m_adjustedWaypoint.m_navPosition.m_vPosition.y - v15->y;
      v18.m128_f32[0] = v18.m128_f32[0] - v15->z;
      v19 = (float)(v17 * v17) + (float)(v16 * v16);
      *(float *)&v20 = v19;
      if ( v19 < 0.0 )
        v20 = LODWORD(v19) ^ _xmm[0];
      if ( *(float *)&v20 >= 0.001 )
      {
        v18.m128_f32[0] = (float)(v18.m128_f32[0] * v18.m128_f32[0]) + v19;
        if ( v18.m128_f32[0] == 0.0 )
          v21 = 0.0;
        else
          v21 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v18));
        v2->m_FormationForward.x = v16 * v21;
        v2->m_FormationForward.y = v17 * v21;
      }
    }
    v22 = v2->m_PrevFormationForward.y;
    v23 = v2->m_PrevFormationForward.x;
    if ( (float)((float)(v23 * v23) + (float)(v22 * v22)) > 0.0 )
    {
      v24 = v2->m_FormationForward.x;
      v25 = v2->m_FormationForward.y;
      n2.z = 0.0;
      n1.z = 0.0;
      n1.x = v24;
      n1.y = v25;
      n2.x = v23;
      n2.y = v22;
      UFG::qAngleBetweenNormals(&n1, &n2);
      v2->m_AngularVelocity = COERCE_FLOAT(LODWORD(v24) & _xmm) * v3;
    }
    v26 = v2->m_FormationForward.y;
    v2->m_PrevFormationForward.x = v2->m_FormationForward.x;
    v2->m_PrevFormationForward.y = v26;
  }
}

// File Line: 789
// RVA: 0x34DD90
void __fastcall UFG::PedFormationManagerComponent::CheckIfSprinting(UFG::PedFormationManagerComponent *this)
{
  UFG::PedFormationProfile *v1; // rax
  UFG::PedFormationManagerComponent *v2; // rbx
  UFG::SimComponent *v3; // rcx
  UFG::SimObjectCVBase *v4; // rcx
  unsigned int v5; // edi
  UFG::AICharacterControllerBaseComponent *v6; // rdx
  unsigned __int16 v7; // dx
  UFG::AICharacterControllerBaseComponent *v8; // rax
  unsigned __int64 v9; // rax
  unsigned __int8 v10; // cl
  bool v11; // r8
  unsigned __int64 v12; // rax
  unsigned __int8 v13; // cl
  bool v14; // al
  signed int v15; // eax
  signed __int64 v16; // rcx
  signed int v17; // eax
  UFG::PedFormationTimer *v18; // rcx

  v1 = this->m_pCurrentProfile;
  v2 = this;
  if ( v1 )
  {
    if ( v1->mIsActive )
    {
      if ( this->m_Slots.size )
      {
        v3 = this->m_pActionTreeComponent.m_pSimComponent;
        if ( v3 )
        {
          v4 = (UFG::SimObjectCVBase *)v3->m_pSimObject;
          v5 = 0;
          if ( v4 )
          {
            v7 = v4->m_Flags;
            if ( (v7 >> 14) & 1 )
            {
              v8 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v4);
            }
            else if ( (v7 & 0x8000u) == 0 )
            {
              if ( (v7 >> 13) & 1 )
              {
                v8 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  (UFG::SimObjectGame *)&v4->vfptr,
                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID);
              }
              else if ( (v7 >> 12) & 1 )
              {
                v8 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  (UFG::SimObjectGame *)&v4->vfptr,
                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID);
              }
              else
              {
                v8 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                  (UFG::SimObject *)&v4->vfptr,
                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID);
              }
            }
            else
            {
              v8 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v4);
            }
            v6 = v8;
          }
          else
          {
            v6 = 0i64;
          }
          v9 = v6->m_Intention.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Jog.m_EnumValue >> 6];
          v10 = _bittest64((const signed __int64 *)&v9, gActionRequest_Jog.m_EnumValue & 0x3F);
          v11 = v10 && (!v6->m_Intention.mActionRequestChargeTimes[gActionRequest_Jog.m_EnumValue] || v10);
          v12 = v6->m_Intention.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_Sprint.m_EnumValue >> 6];
          v13 = _bittest64((const signed __int64 *)&v12, gActionRequest_Sprint.m_EnumValue & 0x3F);
          v14 = v13 && (!v6->m_Intention.mActionRequestChargeTimes[gActionRequest_Sprint.m_EnumValue] || v13);
          v2->m_CurrentlySprinting = v14;
          v2->m_LeaderMoveType = 1;
          if ( v14 )
          {
            v2->m_LeaderMoveType = 3;
          }
          else
          {
            v15 = v2->m_LeaderMoveType;
            if ( v11 )
              v15 = 2;
            v2->m_LeaderMoveType = v15;
          }
          if ( v2->m_Slots.size > 0 )
          {
            do
            {
              v16 = v5;
              if ( v2->m_Slots.p[v16].m_pMember.m_pPointer )
              {
                v17 = v2->m_LeaderMoveType;
                if ( v17 > (signed int)v2->m_Slots.p[v16].m_DesiredMoveType )
                {
                  v2->m_Slots.p[v16].m_NextMoveType = v17;
                  v18 = &v2->m_Slots.p[v16].m_ReactionTimer;
                  if ( v18->mNextTime < 0.0 )
                    UFG::PedFormationTimer::Set(v18, unk_14206D788, aFff[0]);
                }
              }
              ++v5;
            }
            while ( v5 < v2->m_Slots.size );
          }
        }
      }
    }
  }
}

// File Line: 836
// RVA: 0x38AB80
void __fastcall UFG::PedFormationManagerComponent::UnregisterIncorrectlyRegisteredPeople(UFG::PedFormationManagerComponent *this)
{
  __int64 v1; // rbx
  UFG::PedFormationManagerComponent *v2; // rdi
  UFG::GetInPedFormationNode *v3; // rax

  v1 = 0i64;
  v2 = this;
  if ( this->m_Slots.size )
  {
    do
    {
      v3 = v2->m_Slots.p[v1].m_pMember.m_pPointer;
      if ( v3 )
      {
        if ( v3->m_SlotIndex != (_DWORD)v1 )
          UFG::PedFormationManagerComponent::UnregisterSlot(v2, v1);
      }
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->m_Slots.size );
  }
}

// File Line: 857
// RVA: 0x38ABE0
void __fastcall UFG::PedFormationManagerComponent::UnregisterInvalidFollowers(UFG::PedFormationManagerComponent *this)
{
  UFG::SimComponent *v1; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v2; // r14
  UFG::PedFormationManagerComponent *v3; // rdi
  __int64 v4; // rsi
  UFG::GetInPedFormationNode *v5; // rbp
  __int64 v6; // rbx
  UFG::GetInPedFormationNode *v7; // rax

  v1 = this->m_pAIEntityComponent.m_pSimComponent;
  v2 = 0i64;
  v3 = this;
  if ( v1 )
  {
    v2 = v1[15].vfptr;
    if ( v2 )
      UFG::GroupComponent::UnregisterFarFollowers(
        (UFG::GroupComponent *)v1[15].vfptr,
        PedFormationTuning::sDefault.mMaxTetherDistanceSqr);
  }
  v4 = 0i64;
  if ( v3->m_Slots.size )
  {
    do
    {
      if ( v3->m_Slots.p[v4].m_pMember.m_pPointer )
      {
        if ( !((unsigned __int8 (__fastcall *)(UFG::PedFormationManagerComponent *, UFG::qSafePointerNode<UFG::SimComponent>Vtbl *, _QWORD))v3->vfptr[14].__vecDelDtor)(
                v3,
                v2,
                (unsigned int)v4) )
        {
          v5 = v3->m_Slots.p[v4].m_pMember.m_pPointer;
          v6 = 0i64;
          if ( v3->m_Slots.size )
          {
            do
            {
              v7 = v3->m_Slots.p[v6].m_pMember.m_pPointer;
              if ( v7 )
              {
                if ( v5 == v7 )
                  UFG::PedFormationManagerComponent::UnregisterSlot(v3, v6);
              }
              v6 = (unsigned int)(v6 + 1);
            }
            while ( (unsigned int)v6 < v3->m_Slots.size );
          }
        }
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v3->m_Slots.size );
  }
}

// File Line: 905
// RVA: 0x37C2B0
char __fastcall UFG::PedFormationManagerComponent::PedFormationSlotIsOccupied(UFG::PedFormationManagerComponent *this, UFG::GroupComponent *pGC, int slot_index)
{
  UFG::GroupComponent *v3; // rsi
  char *v4; // rdi
  __int64 v5; // rcx
  __int64 v6; // rax
  unsigned int v7; // ebx
  __int64 v8; // rax
  bool v9; // bp
  __int64 v10; // rax
  UFG::HealthComponent *v11; // rdx
  UFG::ActionTreeComponent *v12; // rcx
  __int64 v13; // rcx
  UFG::ActionTreeComponent *v14; // rcx
  bool v15; // r8
  __int64 v16; // rax
  __int64 v17; // rcx
  UFG::GroupComponent *v18; // rcx
  unsigned int v19; // edx
  UFG::GroupComponent **v20; // rax
  char v21; // al
  char result; // al

  v3 = pGC;
  v4 = (char *)this + 160 * (unsigned int)slot_index;
  v5 = *((_QWORD *)v4 + 45);
  if ( !v5 )
    goto LABEL_43;
  v9 = 0;
  v6 = *(_QWORD *)(v5 + 88);
  v7 = 0;
  if ( v6 )
  {
    if ( *(_QWORD *)(v6 + 120) )
    {
      v8 = v6 ? *(_QWORD *)(v6 + 120) : 0i64;
      if ( (*(_BYTE *)(v8 + 32) & 3) == 1 )
        v9 = 1;
    }
  }
  v10 = *(_QWORD *)(v5 + 88);
  v11 = (UFG::HealthComponent *)(v10 ? *(_QWORD *)(v10 + 216) : 0i64);
  v12 = (UFG::ActionTreeComponent *)(v10 ? *(_QWORD *)(v10 + 168) : 0i64);
  v15 = 0;
  if ( !UFG::IsDowned(v12, v11) )
  {
    v13 = *(_QWORD *)(*((_QWORD *)v4 + 45) + 88i64);
    v14 = (UFG::ActionTreeComponent *)(v13 ? *(_QWORD *)(v13 + 168) : 0i64);
    if ( !UFG::IsStunned(v14) )
      v15 = 1;
  }
  if ( (v16 = *(_QWORD *)(*((_QWORD *)v4 + 45) + 88i64)) != 0
    && *(_QWORD *)(v16 + 120)
    && v3
    && (!v16 ? (v17 = 0i64) : (v17 = *(_QWORD *)(v16 + 120)),
        (v18 = *(UFG::GroupComponent **)(v17 + 960)) != 0i64 && (v19 = v3->mGroupLeader.mFollowers.size) != 0) )
  {
    v20 = &v3->mGroupLeader.mFollowers.p[0].m_pPointer;
    while ( v18 != *v20 )
    {
      ++v7;
      v20 += 3;
      if ( v7 >= v19 )
        goto LABEL_34;
    }
    v21 = 1;
  }
  else
  {
LABEL_34:
    v21 = 0;
  }
  if ( v9 && v15 && v21 )
    result = 1;
  else
LABEL_43:
    result = 0;
  return result;
}

// File Line: 934
// RVA: 0x395190
void __fastcall UFG::PedFormationManagerComponent::UpdateDesiredFacing(UFG::PedFormationManagerComponent *this)
{
  UFG::PedFormationManagerComponent *v1; // rdi
  float v2; // xmm8_4
  float v3; // xmm7_4
  float v4; // xmm9_4
  float v5; // xmm10_4
  float v6; // xmm11_4
  UFG::SimComponent *v7; // rbx
  UFG::SimComponent *v8; // rbx
  signed __int64 v9; // rbp
  signed __int64 v10; // rbx
  UFG::GetInPedFormationNode *v11; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObject *v13; // rcx
  UFG::TransformNodeComponent *v14; // rsi
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4

  v1 = this;
  v2 = 0.0;
  v3 = *(float *)&FLOAT_1_0;
  v4 = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v7 = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
    v3 = *(float *)&v7[2].vfptr;
    v2 = *((float *)&v7[2].vfptr + 1);
    v4 = *(float *)&v7[2].m_SafePointerList.mNode.mPrev;
    v8 = v1->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent);
    v5 = *(float *)&v8[2].m_BoundComponentHandles.mNode.mPrev;
    v6 = *((float *)&v8[2].m_BoundComponentHandles.mNode.mPrev + 1);
  }
  v9 = 0i64;
  if ( v1->m_Slots.size )
  {
    do
    {
      v10 = v9;
      v11 = v1->m_Slots.p[v9].m_pMember.m_pPointer;
      if ( v11 )
      {
        if ( v1->m_Slots.p[v10].m_pProfileSlot->mFacingType == 2 )
        {
          v1->m_Slots.p[v10].m_FacingDirection.x = v3;
          v1->m_Slots.p[v10].m_FacingDirection.y = v2;
          v1->m_Slots.p[v10].m_FacingDirection.z = v4;
        }
        else if ( v1->m_Slots.p[v10].m_pProfileSlot->mFacingType == 3 )
        {
          v12 = v11->m_pOwner.m_pPointer;
          if ( v12 )
          {
            v13 = v12->m_pSimObject;
            if ( v13 )
            {
              if ( v13->m_pTransformNodeComponent )
              {
                if ( v12 && v13 )
                  v14 = v13->m_pTransformNodeComponent;
                else
                  v14 = 0i64;
                UFG::TransformNodeComponent::UpdateWorldTransform(v14);
                v15 = v5 - v14->mWorldTransform.v3.x;
                v16 = v6 - v14->mWorldTransform.v3.y;
                v17 = fsqrt((float)(v16 * v16) + (float)(v15 * v15));
                if ( v17 > 0.001 )
                {
                  v1->m_Slots.p[v10].m_FacingDirection.z = (float)(1.0 / v17) * 0.0;
                  v1->m_Slots.p[v10].m_FacingDirection.x = (float)(1.0 / v17) * v15;
                  v1->m_Slots.p[v10].m_FacingDirection.y = (float)(1.0 / v17) * v16;
                }
              }
            }
          }
        }
      }
      v9 = (unsigned int)(v9 + 1);
    }
    while ( (unsigned int)v9 < v1->m_Slots.size );
  }
}

// File Line: 1004
// RVA: 0x3974F0
void __fastcall UFG::PedFormationManagerComponent::UpdatePairs(UFG::PedFormationManagerComponent *this)
{
  UFG::PedFormationManagerComponent *v1; // r14
  float v2; // xmm6_4
  __int64 v3; // rdi
  float *v4; // rbx
  float v5; // xmm1_4
  float v6; // xmm2_4
  __int64 v7; // rbp
  UFG::GetInPedFormationNode *v8; // rax
  UFG::SimComponent *v9; // rcx
  UFG::TransformNodeComponent *v10; // rdi
  UFG::SimObject *v11; // r15
  __int64 v12; // rbx
  float v13; // xmm1_4
  float v14; // xmm2_4
  unsigned int v15; // er9
  unsigned int v16; // er11
  float *v17; // r10
  UFG::SimObject *v18; // r8
  float v19; // xmm2_4
  float v20; // xmm0_4
  unsigned int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float *v25; // rdx
  __int64 v26; // rcx
  _QWORD *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qFixedArray<PedFormationPairing,10> v29; // [rsp+30h] [rbp-178h]

  v1 = this;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v2 = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::qFixedArray<PedFormationPairing,10>::qFixedArray<PedFormationPairing,10>(&v29);
    v3 = v29.size;
    ++v29.size;
    v4 = (float *)v1->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent);
    v29.p[v3].m_pMe = v1->m_pSimObject;
    v29.p[v3].m_pMyPair = &v1->m_Pair;
    v5 = v4[45];
    v6 = v4[46];
    v29.p[v3].m_MyPosition.x = v4[44];
    v29.p[v3].m_MyPosition.y = v5;
    v29.p[v3].m_MyPosition.z = v6;
    v7 = 0i64;
    if ( v1->m_Slots.size )
    {
      do
      {
        v8 = v1->m_Slots.p[v7].m_pMember.m_pPointer;
        if ( v8 )
        {
          v9 = v8->m_pOwner.m_pPointer;
          if ( v9 )
          {
            v10 = (UFG::TransformNodeComponent *)v9->m_pSimObject;
            if ( v10 )
              v10 = (UFG::TransformNodeComponent *)v10->mChildren.mNode.mNext;
            if ( v10 )
            {
              if ( v9 )
              {
                v11 = v9->m_pSimObject;
                if ( v11 )
                {
                  v12 = v29.size;
                  ++v29.size;
                  UFG::TransformNodeComponent::UpdateWorldTransform(v10);
                  v29.p[v12].m_pMe = v11;
                  v29.p[v12].m_pMyPair = &v1->m_Slots.p[v7].m_Pair;
                  v13 = v10->mWorldTransform.v3.y;
                  v14 = v10->mWorldTransform.v3.z;
                  v29.p[v12].m_MyPosition.x = v10->mWorldTransform.v3.x;
                  v29.p[v12].m_MyPosition.y = v13;
                  v29.p[v12].m_MyPosition.z = v14;
                }
              }
            }
          }
        }
        v7 = (unsigned int)(v7 + 1);
      }
      while ( (unsigned int)v7 < v1->m_Slots.size );
    }
    v15 = 0;
    v16 = v29.size;
    if ( v29.size )
    {
      v17 = (float *)&v29.p[0].m_pMyPair;
      do
      {
        v18 = 0i64;
        v19 = 0.0;
        if ( *(float *)(*(_QWORD *)v17 + 24i64) < 0.0
          || (v20 = *(float *)(*(_QWORD *)v17 + 24i64), v20 > 0.0) && v2 >= v20 )
        {
          v21 = 0;
          do
          {
            if ( v15 != v21 )
            {
              v22 = v17[3] - v29.p[v21].m_MyPosition.y;
              v23 = v17[2] - v29.p[v21].m_MyPosition.x;
              v24 = (float)(v23 * v23) + (float)(v22 * v22);
              if ( !v18 || v24 < v19 )
              {
                v19 = v24;
                v18 = v29.p[v21].m_pMe;
              }
            }
            ++v21;
          }
          while ( v21 < v16 );
          v25 = *(float **)v17;
          if ( *(_QWORD *)(*(_QWORD *)v17 + 16i64) )
          {
            v26 = *(_QWORD *)v25;
            v27 = (_QWORD *)*((_QWORD *)v25 + 1);
            *(_QWORD *)(v26 + 8) = v27;
            *v27 = v26;
            *(_QWORD *)v25 = v25;
            *((_QWORD *)v25 + 1) = v25;
          }
          *((_QWORD *)v25 + 2) = v18;
          if ( v18
            && (v28 = v18->m_SafePointerList.mNode.mPrev,
                v28->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v25,
                *(_QWORD *)v25 = v28,
                *((_QWORD *)v25 + 1) = (char *)v18 + 8,
                v18->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v25,
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
        v17 += 8;
      }
      while ( v15 < v16 );
    }
  }
}

// File Line: 1079
// RVA: 0x34D610
void __fastcall UFG::PedFormationManagerComponent::CheckIfInDesiredPosition(UFG::PedFormationManagerComponent *this)
{
  UFG::PedFormationManagerComponent *v1; // rsi
  float v2; // xmm15_4
  UFG::SimComponent *v3; // r15
  unsigned int v4; // ebp
  signed __int64 v5; // rbx
  __int64 v6; // rdi
  __int64 v7; // rax
  __int64 v8; // rcx
  __int64 v9; // rax
  __int64 v10; // rdi
  UFG::TransformNodeComponent *v11; // rdi
  float v12; // xmm1_4
  float v13; // xmm2_4
  __int64 v14; // rax
  __m128 v15; // xmm0
  float v16; // xmm2_4
  float v17; // xmm9_4
  float v18; // xmm8_4
  float v19; // xmm10_4
  float v20; // xmm11_4
  float *v21; // rax
  bool v22; // r14
  float *v23; // rax
  float v24; // xmm6_4
  float max_lateral_offset; // xmm7_4
  unsigned int v26; // ecx
  float v27; // xmm6_4
  float v28; // xmm9_4
  bool v29; // al
  unsigned int v30; // edi
  float v31; // xmm0_4
  float v32; // xmm1_4
  bool v33; // r8
  bool v34; // dl
  UFG::PedFormationProfile *v35; // rax
  float v36; // xmm0_4
  float v37; // xmm0_4
  __int64 v38; // rcx
  char v39; // al
  UFG::qVector3 follower_position; // [rsp+40h] [rbp-E8h]
  UFG::qVector3 desired_position; // [rsp+50h] [rbp-D8h]
  float current_radial_offset; // [rsp+130h] [rbp+8h]
  float current_lateral_offset; // [rsp+138h] [rbp+10h]

  v1 = this;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v2 = UFG::Metrics::msInstance.mSimTime_Temp;
    v3 = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
    v4 = 0;
    if ( v1->m_Slots.size )
    {
      do
      {
        v5 = (signed __int64)&v1->m_Slots.p[v4];
        v6 = *(_QWORD *)(v5 + 64);
        if ( !v6
          || (v7 = *(_QWORD *)(v6 + 88)) == 0
          || (v8 = *(_QWORD *)(v7 + 40)) == 0
          || !*(_QWORD *)(v8 + 88)
          || !UFG::PedFormationManagerComponent::GetDesiredPosition(
                v1,
                *(UFG::GetInPedFormationNode **)(v5 + 64),
                &desired_position) )
        {
          if ( *(_DWORD *)(v5 + 32) != 3 )
            *(_DWORD *)(v5 + 32) = 3;
          *(_WORD *)(v5 + 40) = 0;
          goto LABEL_67;
        }
        v9 = *(_QWORD *)(v6 + 88);
        if ( v9 && (v10 = *(_QWORD *)(v9 + 40)) != 0 )
          v11 = *(UFG::TransformNodeComponent **)(v10 + 88);
        else
          v11 = 0i64;
        UFG::TransformNodeComponent::UpdateWorldTransform(v11);
        v12 = v11->mWorldTransform.v3.y;
        v13 = v11->mWorldTransform.v3.z;
        follower_position.x = v11->mWorldTransform.v3.x;
        follower_position.y = v12;
        follower_position.z = v13;
        UFG::TransformNodeComponent::UpdateWorldTransform(v11);
        v14 = *(_QWORD *)(v5 + 152);
        current_lateral_offset = 0.0;
        v15 = (__m128)LODWORD(follower_position.y);
        v16 = v11->mWorldTransform.v0.x;
        current_radial_offset = 0.0;
        v17 = *(float *)(v14 + 52);
        v18 = *(float *)(v14 + 40);
        v15.m128_f32[0] = (float)((float)(follower_position.y
                                        - *((float *)&v3[2].m_BoundComponentHandles.mNode.mPrev + 1))
                                * (float)(follower_position.y
                                        - *((float *)&v3[2].m_BoundComponentHandles.mNode.mPrev + 1)))
                        + (float)((float)(follower_position.x - *(float *)&v3[2].m_BoundComponentHandles.mNode.mPrev)
                                * (float)(follower_position.x - *(float *)&v3[2].m_BoundComponentHandles.mNode.mPrev));
        LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v15);
        v20 = (float)((float)(v11->mWorldTransform.v0.y * *(float *)(v5 + 24)) + (float)(v16 * *(float *)(v5 + 20)))
            + (float)(v11->mWorldTransform.v0.z * *(float *)(v5 + 28));
        if ( !*(_DWORD *)(v5 + 32) )
        {
          v18 = v18 - 1.0;
          if ( v18 <= 0.0 )
            v18 = 0.0;
        }
        v21 = (float *)v1->m_pCurrentProfile;
        v22 = v19 < v21[226];
        if ( !*(_BYTE *)(v5 + 42) && v19 < v21[226] )
          *(float *)(v5 + 36) = UFG::GetRandomNumberInRange(v21[227], v21[228]) + v2;
        v23 = *(float **)(v5 + 152);
        v24 = v23[15];
        max_lateral_offset = v23[16];
        if ( !v1->m_CurrentlySprinting )
        {
          v26 = *(_DWORD *)(v5 + 32);
          if ( v26 <= 1 )
          {
            if ( UFG::Metrics::msInstance.mSimTime_Temp > *(float *)(v5 + 36) )
              v27 = v24 + v23[20];
            else
              v27 = v24 + v23[19];
            v24 = v27 + *(float *)(v5 + 116);
            max_lateral_offset = max_lateral_offset + v23[22];
          }
          else if ( v26 == 4 )
          {
            v24 = v24 + v23[21];
            max_lateral_offset = max_lateral_offset + v23[23];
          }
        }
        if ( *(_BYTE *)(v5 + 41) )
          v17 = v17 + v23[14];
        v28 = cosf((float)(v17 * 3.1415927) * 0.0055555557);
        v29 = UFG::PedFormationManagerComponent::IsInPosition(
                v1,
                &follower_position,
                &desired_position,
                v24,
                max_lateral_offset,
                &current_radial_offset,
                &current_lateral_offset,
                0);
        v30 = *(_DWORD *)(v5 + 32);
        v31 = *(float *)&FLOAT_1_0;
        v32 = *(float *)&FLOAT_1_0;
        v33 = v29;
        if ( v30 <= 2 )
        {
          v31 = FLOAT_2_0;
          v32 = FLOAT_2_0;
        }
        v34 = current_radial_offset <= v31 && current_lateral_offset <= v32;
        if ( v1->m_CurrentlySprinting && (v35 = v1->m_pCurrentProfile) != 0i64 )
          v36 = v35->mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting;
        else
          v36 = (float)(*(float *)(*(_QWORD *)(v5 + 152) + 80i64) + *(float *)(*(_QWORD *)(v5 + 152) + 60i64)) + 5.0;
        if ( v30 != 4 || v19 >= v18 )
        {
          if ( current_radial_offset >= v36 )
            goto LABEL_57;
          if ( v30 == 4 )
          {
            if ( !v33 )
            {
LABEL_57:
              if ( v30 != 4 )
                *(_DWORD *)(v5 + 32) = 4;
              goto LABEL_59;
            }
          }
          else if ( !v33 )
          {
            if ( v34 )
            {
              if ( v30 != 2 )
                *(_DWORD *)(v5 + 32) = 2;
            }
            else if ( v30 != 3 )
            {
              *(_DWORD *)(v5 + 32) = 3;
            }
            goto LABEL_59;
          }
          if ( UFG::PedFormationManagerComponent::IsMoving(v1, 0) )
          {
            if ( v30 != 1 )
              *(_DWORD *)(v5 + 32) = 1;
          }
          else
          {
            if ( v30 )
            {
              v37 = UFG::Metrics::msInstance.mSimTime_Temp;
              *(_DWORD *)(v5 + 108) = 1;
              *(float *)(v5 + 104) = v37;
              UFG::PedFormationSlot::SetRadialHysteresisModifier((UFG::PedFormationSlot *)v5);
            }
            if ( *(_DWORD *)(v5 + 32) )
              *(_DWORD *)(v5 + 32) = 0;
          }
        }
        else
        {
          *(_DWORD *)(v5 + 32) = 3;
        }
LABEL_59:
        v38 = *(_QWORD *)(v5 + 152);
        if ( v19 < *(float *)(v38 + 44) || (v39 = 0, !*(_DWORD *)(v5 + 32)) )
          v39 = 1;
        *(_BYTE *)(v5 + 40) = v39;
        *(_BYTE *)(v5 + 42) = v22;
        *(_BYTE *)(v5 + 41) = v20 > v28;
        if ( *(_DWORD *)(v38 + 24) == 1 )
          *(_BYTE *)(v5 + 41) = 1;
LABEL_67:
        ++v4;
      }
      while ( v4 < v1->m_Slots.size );
    }
  }
}

// File Line: 1255
// RVA: 0x36B150
bool __fastcall UFG::PedFormationManagerComponent::IsInPosition(UFG::PedFormationManagerComponent *this, UFG::qVector3 *follower_position, UFG::qVector3 *desired_position, float max_radial_offset, float max_lateral_offset, float *current_radial_offset, float *current_lateral_offset, bool debug_print)
{
  UFG::SimComponent *v8; // rbx
  UFG::PedFormationManagerComponent *v9; // rdi
  UFG::qVector3 *v10; // rsi
  UFG::qVector3 *v11; // rbp
  float v12; // xmm9_4
  float v13; // xmm7_4
  float *v14; // rbx
  float v15; // xmm7_4
  __m128 v16; // xmm6
  float v17; // xmm5_4
  __m128 v18; // xmm3
  float v19; // xmm8_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm7_4
  float v23; // xmm6_4
  float v24; // xmm1_4
  float v25; // xmm7_4
  __m128 v26; // xmm0
  float v27; // xmm6_4
  float v28; // xmm7_4
  Render::DebugDrawContext *v29; // rax

  v8 = this->m_pTransformNodeComponent.m_pSimComponent;
  v9 = this;
  v10 = desired_position;
  v11 = follower_position;
  v12 = max_radial_offset;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
  v13 = *(float *)&v8[2].m_BoundComponentHandles.mNode.mPrev;
  v16 = (__m128)HIDWORD(v8[2].m_BoundComponentHandles.mNode.mPrev);
  v14 = (float *)v9->m_pTransformNodeComponent.m_pSimComponent;
  v15 = v13 - v11->x;
  v16.m128_f32[0] = v16.m128_f32[0] - v11->y;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9->m_pTransformNodeComponent.m_pSimComponent);
  v18 = (__m128)LODWORD(v11->y);
  v17 = v11->x - v10->x;
  v18.m128_f32[0] = v18.m128_f32[0] - v10->y;
  v19 = v11->z - v10->z;
  v20 = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v15 * v15);
  if ( v20 <= 0.001 )
  {
    v25 = UFG::qVector3::msZero.x;
    v16 = (__m128)LODWORD(UFG::qVector3::msZero.y);
  }
  else
  {
    if ( v20 == 0.0 )
      v21 = 0.0;
    else
      v21 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
    v22 = v15 * v21;
    v23 = v16.m128_f32[0] * v21;
    v24 = (float)((float)(v23 * v18.m128_f32[0]) + (float)(v22 * v17)) + (float)((float)(v21 * 0.0) * v19);
    v25 = v22 * v24;
    v16.m128_f32[0] = v23 * v24;
  }
  v26 = v18;
  v26.m128_f32[0] = (float)(v26.m128_f32[0] - v16.m128_f32[0]) * (float)(v26.m128_f32[0] - v16.m128_f32[0]);
  v16.m128_f32[0] = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v25 * v25);
  LODWORD(v27) = (unsigned __int128)_mm_sqrt_ps(v16);
  v26.m128_f32[0] = v26.m128_f32[0] + (float)((float)(v17 - v25) * (float)(v17 - v25));
  LODWORD(v28) = (unsigned __int128)_mm_sqrt_ps(v26);
  if ( (float)((float)((float)(v18.m128_f32[0] * (float)(v14[45] - v10->y)) + (float)(v17 * (float)(v14[44] - v10->x)))
             + (float)(v19 * (float)(v14[46] - v10->z))) > 0.0 )
    LODWORD(v27) ^= _xmm[0];
  if ( debug_print )
  {
    v29 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    Render::DebugDrawContext::DrawText(v29, v11, &UFG::qColour::White, "R: %.1f L: %.1f", v27, v28);
  }
  *current_radial_offset = v27;
  *current_lateral_offset = v28;
  return v12 > COERCE_FLOAT(LODWORD(v27) & _xmm) && max_lateral_offset > COERCE_FLOAT(LODWORD(v28) & _xmm);
}

// File Line: 1296
// RVA: 0x36B8A0
bool __fastcall UFG::PedFormationManagerComponent::IsMoving(UFG::PedFormationManagerComponent *this, bool includeTurning)
{
  return unk_14206D75C < this->m_Speed || includeTurning && unk_14206D754 < this->m_AngularVelocity;
}

// File Line: 1350
// RVA: 0x375FB0
void __fastcall UFG::PedFormationManagerComponent::MaybeSetDesiredPositionFromProfile(UFG::PedFormationManagerComponent *this)
{
  UFG::PedFormationManagerComponent *v1; // rsi
  float v2; // xmm13_4
  float v3; // xmm9_4
  __int64 v4; // rax
  signed __int64 v5; // rdi
  UFG::GetInPedFormationNode *v6; // r13
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // rcx
  UFG::TransformNodeComponent *v9; // rbx
  UFG::PedFormationProfileSlot *v10; // r14
  char v11; // r15
  UFG::qVector3 *v12; // r12
  float v13; // xmm8_4
  float v14; // xmm0_4
  unsigned int v15; // ebp
  UFG::TransformNodeComponent *v16; // r13
  signed __int64 v17; // rbx
  __int64 v18; // rax
  float v19; // xmm6_4
  float v20; // xmm7_4
  __int64 v21; // rax
  float v22; // xmm1_4
  UFG::PedFormationProfile::Slot *v23; // rcx
  __int64 v24; // rax
  float v25; // xmm1_4
  float v26; // xmm0_4
  UFG::GetInPedFormationNode *v27; // r13
  int v28; // ebx
  float v29; // xmm0_4
  bool v30; // zf
  float v31; // xmm1_4
  float v32; // xmm0_4
  float *v33; // rax
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
  UFG::qVector2 follower_start; // [rsp+40h] [rbp-108h]
  UFG::TransformNodeComponent *v46; // [rsp+48h] [rbp-100h]
  UFG::GetInPedFormationNode *get_in_formation; // [rsp+50h] [rbp-F8h]
  UFG::qVector3 desired_direction; // [rsp+58h] [rbp-F0h]
  UFG::qVector3 desired_position; // [rsp+68h] [rbp-E0h]
  int slot_index; // [rsp+150h] [rbp+8h]
  float current_radial_offset; // [rsp+158h] [rbp+10h]
  float current_lateral_offset; // [rsp+160h] [rbp+18h]
  UFG::qVector2 follower_end; // [rsp+168h] [rbp+20h]

  v1 = this;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v46 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    v2 = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::TransformNodeComponent::UpdateWorldTransform(v46);
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pSimComponent);
    v3 = unk_14206D75C >= v1->m_Speed ? 0.0 : unk_14206D74C;
    v4 = 0i64;
    slot_index = 0;
    if ( v1->m_Slots.size )
    {
      do
      {
        v5 = (signed __int64)&v1->m_Slots.p[v4];
        v6 = *(UFG::GetInPedFormationNode **)(v5 + 64);
        get_in_formation = v6;
        if ( v6 )
        {
          v7 = v6->m_pOwner.m_pPointer;
          if ( v7 )
          {
            v8 = v7->m_pSimObject;
            if ( v8 )
            {
              if ( v8->m_pTransformNodeComponent )
              {
                if ( v7 && v8 )
                  v9 = v8->m_pTransformNodeComponent;
                else
                  v9 = 0i64;
                UFG::TransformNodeComponent::UpdateWorldTransform(v9);
                v10 = 0i64;
                v11 = 0;
                v12 = (UFG::qVector3 *)&v9->mWorldTransform.v3;
                v13 = 0.0;
                desired_direction = UFG::qVector3::msZero;
                v14 = *(float *)(v5 + 120);
                if ( v14 < 0.0 || v14 > 0.0 && v2 >= v14 )
                  v11 = 1;
                v15 = 0;
                if ( v1->m_ProfileSlots.size )
                {
                  v16 = v46;
                  do
                  {
                    v17 = (signed __int64)&v1->m_ProfileSlots.p[v15];
                    v18 = *(_QWORD *)(v17 + 24);
                    if ( v18 == v5 || !v18 && v11 )
                    {
                      v19 = v16->mWorldTransform.v3.x + *(float *)(v17 + 32);
                      v20 = v16->mWorldTransform.v3.y + *(float *)(v17 + 36);
                      if ( *(_BYTE *)(v17 + 44) )
                      {
                        if ( v3 <= *(float *)(v17 + 48) )
                        {
                          v21 = *(_QWORD *)(v17 + 16);
                          if ( v21 )
                          {
                            if ( *(_BYTE *)(v21 + 30)
                              || (v22 = v12->y,
                                  follower_start.x = v12->x,
                                  follower_start.y = v22,
                                  follower_end.x = v19,
                                  follower_end.y = v20,
                                  !(unsigned __int8)UFG::PedFormationManagerComponent::CrossesLeadersPath(
                                                      v1,
                                                      &follower_start,
                                                      &follower_end)) )
                            {
                              if ( !v10
                                || (v23 = v10->mProfileSlot.m_pPointer,
                                    v24 = *(_QWORD *)(v17 + 16),
                                    v23->mMinDistance >= *(float *)(v24 + 40))
                                && v23->mPreference <= *(float *)(v24 + 32)
                                && (float)((float)((float)(v12->y - v20) * (float)(v12->y - v20))
                                         + (float)((float)(v12->x - v19) * (float)(v12->x - v19))) < v13 )
                              {
                                v13 = (float)((float)(v12->y - v20) * (float)(v12->y - v20))
                                    + (float)((float)(v12->x - v19) * (float)(v12->x - v19));
                                v25 = *(float *)(v17 + 36);
                                v10 = &v1->m_ProfileSlots.p[v15];
                                desired_direction.x = *(float *)(v17 + 32);
                                v26 = *(float *)(v17 + 40);
                                desired_direction.y = v25;
                                desired_direction.z = v26;
                              }
                            }
                          }
                        }
                      }
                    }
                    ++v15;
                  }
                  while ( v15 < v1->m_ProfileSlots.size );
                  v27 = get_in_formation;
                  if ( v10 )
                  {
                    if ( v10->mMemberSlot != (UFG::PedFormationSlot *)v5 )
                    {
                      UFG::PedFormationTimer::Set(
                        (UFG::PedFormationTimer *)(v5 + 120),
                        v1->m_pCurrentProfile->mMinTimeBetweenSlotChanges,
                        v1->m_pCurrentProfile->mMinTimeBetweenSlotChanges);
                      UFG::PedFormationManagerComponent::AssignProfileSlot(v1, v10, (UFG::PedFormationSlot *)v5);
                    }
                    v28 = *(_DWORD *)(v5 + 32);
                    UFG::PedFormationManagerComponent::SetDesiredDirection(v1, slot_index, v27, &desired_direction);
                    if ( *(_DWORD *)(v5 + 32) && !v28 )
                    {
                      v29 = UFG::Metrics::msInstance.mSimTime_Temp;
                      *(_DWORD *)(v5 + 108) = 1;
                      *(float *)(v5 + 104) = v29;
                      UFG::PedFormationSlot::SetRadialHysteresisModifier((UFG::PedFormationSlot *)v5);
                    }
                    if ( *(_DWORD *)(v5 + 32) != v28 )
                      *(_DWORD *)(v5 + 32) = v28;
                    v30 = v1->m_CurrentlySprinting == 0;
                    v31 = *(float *)(v5 + 4);
                    current_lateral_offset = 0.0;
                    current_radial_offset = 0.0;
                    v32 = v46->mWorldTransform.v3.x + *(float *)v5;
                    desired_position.y = v31 + v46->mWorldTransform.v3.y;
                    desired_position.x = v32;
                    v33 = *(float **)(v5 + 152);
                    v34 = v33[15];
                    desired_position.z = *(float *)(v5 + 8) + v46->mWorldTransform.v3.z;
                    max_lateral_offset = v33[16];
                    if ( v30 )
                    {
                      v36 = *(_DWORD *)(v5 + 32);
                      if ( v36 <= 1 )
                      {
                        if ( UFG::Metrics::msInstance.mSimTime_Temp > *(float *)(v5 + 36) )
                          v37 = v34 + v33[20];
                        else
                          v37 = v34 + v33[19];
                        v34 = v37 + *(float *)(v5 + 116);
                        max_lateral_offset = max_lateral_offset + v33[22];
                      }
                      else if ( v36 == 4 )
                      {
                        v34 = v34 + v33[21];
                        max_lateral_offset = max_lateral_offset + v33[23];
                      }
                    }
                    v38 = UFG::PedFormationManagerComponent::IsInPosition(
                            v1,
                            v12,
                            &desired_position,
                            v34,
                            max_lateral_offset,
                            &current_radial_offset,
                            &current_lateral_offset,
                            0);
                    v39 = *(_DWORD *)(v5 + 32);
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
                      if ( UFG::PedFormationManagerComponent::IsMoving(v1, 0) )
                      {
                        if ( v39 != 1 )
                          *(_DWORD *)(v5 + 32) = 1;
                      }
                      else
                      {
                        if ( v39 )
                        {
                          v44 = UFG::Metrics::msInstance.mSimTime_Temp;
                          *(_DWORD *)(v5 + 108) = 1;
                          *(float *)(v5 + 104) = v44;
                          UFG::PedFormationSlot::SetRadialHysteresisModifier((UFG::PedFormationSlot *)v5);
                        }
                        if ( *(_DWORD *)(v5 + 32) )
                          *(_DWORD *)(v5 + 32) = 0;
                      }
                    }
                    else if ( v43 && v39 != 2 )
                    {
                      *(_DWORD *)(v5 + 32) = 2;
                    }
                  }
                }
              }
            }
          }
        }
        v4 = (unsigned int)(slot_index + 1);
        slot_index = v4;
      }
      while ( (unsigned int)v4 < v1->m_Slots.size );
    }
  }
}

// File Line: 1484
// RVA: 0x352A20
bool __fastcall UFG::PedFormationManagerComponent::DirectionIsClear(UFG::PedFormationManagerComponent *this, UFG::HavokNavPosition *npStartPos, UFG::qVector3 *direction, float *max_clear_distance, UFG::eConstrainToSidewalks constrain_to_sidewalks)
{
  float *v5; // rdi
  UFG::HavokNavPosition *v6; // rbx
  __m128 v7; // xmm6
  __m128 v8; // xmm7
  __m128 v9; // xmm8
  UFG::SimObjectGame *v10; // r8
  UFG::SimComponent *v11; // rax
  unsigned __int16 v12; // cx
  __int64 v13; // rax
  bool result; // al
  __m128 v15; // xmm1
  float v16; // [rsp+30h] [rbp-88h]
  float v17; // [rsp+34h] [rbp-84h]
  __int64 (__fastcall **v18)(_QWORD); // [rsp+40h] [rbp-78h]
  int v19; // [rsp+48h] [rbp-70h]
  int v20; // [rsp+4Ch] [rbp-6Ch]
  int v21; // [rsp+50h] [rbp-68h]
  char v22; // [rsp+58h] [rbp-60h]
  __m128 v23; // [rsp+60h] [rbp-58h]
  __int64 v24; // [rsp+70h] [rbp-48h]
  __int64 v25; // [rsp+C0h] [rbp+8h]

  v5 = max_clear_distance;
  v6 = npStartPos;
  if ( !this->m_pAIEntityComponent.m_pSimComponent )
    return 1;
  v7 = (__m128)LODWORD(direction->x);
  v8 = (__m128)LODWORD(direction->y);
  v7.m128_f32[0] = v7.m128_f32[0] + npStartPos->m_vPosition.x;
  v9 = (__m128)LODWORD(npStartPos->m_vPosition.z);
  v8.m128_f32[0] = v8.m128_f32[0] + npStartPos->m_vPosition.y;
  v9.m128_f32[0] = v9.m128_f32[0] + direction->z;
  v10 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v10 )
  {
    v12 = v10->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v11 = v10->m_Components.p[36].m_pComponent;
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::NavComponent::_TypeUID);
      }
      else if ( (v12 >> 12) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::NavComponent::_TypeUID);
      }
      else
      {
        v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::NavComponent::_TypeUID);
      }
    }
    else
    {
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::NavComponent::_TypeUID);
    }
  }
  else
  {
    v11 = 0i64;
  }
  v19 = v7.m128_i32[0];
  v22 = 0;
  v24 = -1i64;
  v20 = v8.m128_i32[0];
  v21 = v9.m128_i32[0];
  v18 = &UFG::HavokNavPosition::`vftable';
  v23 = _mm_unpacklo_ps(_mm_unpacklo_ps(v7, v9), _mm_unpacklo_ps(v8, (__m128)(unsigned int)FLOAT_1_0));
  v13 = *(__int64 *)((char *)&v11[2].m_BoundComponentHandles.mNode.mNext + 4);
  v25 = v13;
  if ( constrain_to_sidewalks )
    HIDWORD(v25) |= 0x200u;
  else
    HIDWORD(v25) = HIDWORD(v13) & 0xFFFFFDFF;
  result = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
             UFG::NavManager::ms_pInstance,
             v6,
             (UFG::HavokNavPosition *)&v18,
             (UFG::NavParams *)&v25,
             (UFG::qVector3 *)&v16) == 0;
  if ( v5 )
  {
    v15 = (__m128)LODWORD(v6->m_vPosition.y);
    v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] - v17) * (float)(v15.m128_f32[0] - v17))
                    + (float)((float)(v6->m_vPosition.x - v16) * (float)(v6->m_vPosition.x - v16));
    *(_DWORD *)v5 = (unsigned __int128)_mm_sqrt_ps(v15);
  }
  return result;
}

// File Line: 1570
// RVA: 0x3808C0
void __fastcall UFG::PedFormationManagerComponent::Register(UFG::PedFormationManagerComponent *this, UFG::GetInPedFormationNode *get_in_formation)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rbp
  UFG::PedFormationManagerComponent *v3; // rdi
  unsigned int v4; // ecx
  int v5; // er15
  UFG::GetInPedFormationNode *v6; // r14
  int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // edx
  signed __int64 v10; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v11; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v14; // rax
  __int64 *v15; // r8
  __int64 v16; // rcx
  _QWORD *v17; // rax
  UFG::PedFormationProfile::Slot *v18; // r8
  signed __int64 v19; // r9
  unsigned int v20; // edx
  int v21; // ecx
  UFG::PedFormationProfile::Slot *v22; // rax
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm0_4
  UFG::SimComponent *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax

  v2 = 0i64;
  v3 = this;
  v4 = this->m_Slots.size;
  v5 = -1;
  v6 = get_in_formation;
  v7 = 0;
  if ( v4 )
  {
    while ( v3->m_Slots.p[v7].m_pMember.m_pPointer )
    {
      if ( ++v7 >= v4 )
        goto LABEL_34;
    }
    v5 = v7;
    if ( v7 != -1 )
    {
      v8 = v3->m_ProfileSlots.size;
      v9 = 0;
      if ( v8 )
      {
        while ( v3->m_ProfileSlots.p[v9].mMemberSlot )
        {
          if ( ++v9 >= v8 )
            goto LABEL_34;
        }
        v10 = (signed __int64)&v3->m_Slots.p[v7];
        v11 = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)(v10 + 48);
        if ( *(_QWORD *)(v10 + 64) )
        {
          v12 = v11->mPrev;
          v13 = *(UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> **)(v10 + 56);
          v12->mNext = v13;
          v13->mPrev = v12;
          v11->mPrev = v11;
          *(_QWORD *)(v10 + 56) = v10 + 48;
        }
        *(_QWORD *)(v10 + 64) = v6;
        if ( v6 )
        {
          v14 = v6->m_SafePointerList.mNode.mPrev;
          v14->mNext = v11;
          v11->mPrev = v14;
          *(_QWORD *)(v10 + 56) = (char *)v6 + 8;
          v6->m_SafePointerList.mNode.mPrev = v11;
        }
        v15 = (__int64 *)(v10 + 72);
        if ( *(_QWORD *)(v10 + 88) )
        {
          v16 = *v15;
          v17 = *(_QWORD **)(v10 + 80);
          *(_QWORD *)(v16 + 8) = v17;
          *v17 = v16;
          *v15 = (__int64)v15;
          *(_QWORD *)(v10 + 80) = v10 + 72;
        }
        *(_QWORD *)(v10 + 88) = 0i64;
        *(_DWORD *)(v10 + 96) = -1082130432;
        v18 = *(UFG::PedFormationProfile::Slot **)(v10 + 152);
        v19 = v9;
        if ( v18 )
        {
          v20 = v3->m_ProfileSlots.size;
          v21 = 0;
          if ( v20 )
          {
            while ( v18 != v3->m_ProfileSlots.p[v21].mProfileSlot.m_pPointer )
            {
              if ( ++v21 >= v20 )
                goto LABEL_22;
            }
            v3->m_ProfileSlots.p[v21].mMemberSlot = 0i64;
            *(_QWORD *)(v10 + 152) = 0i64;
          }
        }
LABEL_22:
        v22 = v3->m_ProfileSlots.p[v19].mProfileSlot.m_pPointer;
        v3->m_ProfileSlots.p[v19].mMemberSlot = (UFG::PedFormationSlot *)v10;
        *(_QWORD *)(v10 + 152) = v22;
        if ( v22 )
        {
          v23 = v22->mMaxRadialHysteresisModifier;
          v24 = v22->mMinRadialHysteresisModifier;
          v25 = v22->mMaxRadialHysteresisModifier;
          if ( v23 > v24 )
          {
            v25 = UFG::qRandom(v23 - v24, &UFG::qDefaultSeed) + v24;
            if ( v25 <= v24 )
              v25 = v24;
            if ( v25 >= v23 )
              v25 = v23;
          }
          *(float *)(v10 + 116) = v25;
        }
        v26 = v6->m_pOwner.m_pPointer;
        v6->m_SlotIndex = v7;
        if ( v26 )
          v2 = v26[1].m_BoundComponentHandles.mNode.mNext;
        v27 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2[105];
        if ( v2[106].mPrev )
        {
          v28 = v27->mPrev;
          v29 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v2[105].mNext;
          v28->mNext = v29;
          v29->mPrev = v28;
          v27->mPrev = v27;
          v2[105].mNext = v2 + 105;
        }
        v2[106].mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v3;
        v30 = v3->m_SafePointerList.mNode.mPrev;
        v30->mNext = v27;
        v27->mPrev = v30;
        v2[105].mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_SafePointerList;
        v3->m_SafePointerList.mNode.mPrev = v27;
        --v3->m_NumFreeSlots;
      }
    }
  }
LABEL_34:
  UFG::PedFormationManagerComponent::SetDesiredDirectionFromCurrentPosition(v3, v5, v6);
}

// File Line: 1616
// RVA: 0x342360
void __fastcall UFG::PedFormationManagerComponent::AssignProfileSlot(UFG::PedFormationManagerComponent *this, UFG::PedFormationProfileSlot *profileSlot, UFG::PedFormationSlot *slot)
{
  UFG::PedFormationProfile::Slot *v3; // r11
  UFG::PedFormationSlot *v4; // r9
  unsigned int v5; // er10
  __int64 v6; // rax
  UFG::PedFormationProfile::Slot **v7; // r8
  UFG::PedFormationProfile::Slot *v8; // rax

  v3 = slot->m_pProfileSlot;
  v4 = slot;
  if ( v3 )
  {
    v5 = this->m_ProfileSlots.size;
    v6 = 0i64;
    if ( v5 )
    {
      v7 = &this->m_ProfileSlots.p[0].mProfileSlot.m_pPointer;
      while ( v3 != *v7 )
      {
        v6 = (unsigned int)(v6 + 1);
        v7 += 7;
        if ( (unsigned int)v6 >= v5 )
          goto LABEL_8;
      }
      this->m_ProfileSlots.p[v6].mMemberSlot = 0i64;
      v4->m_pProfileSlot = 0i64;
    }
  }
LABEL_8:
  v8 = profileSlot->mProfileSlot.m_pPointer;
  profileSlot->mMemberSlot = v4;
  v4->m_pProfileSlot = v8;
  if ( v8 )
    UFG::PedFormationSlot::SetRadialHysteresisModifier(v4);
}

// File Line: 1647
// RVA: 0x385F70
void __fastcall UFG::PedFormationManagerComponent::SetDesiredDirectionFromCurrentPosition(UFG::PedFormationManagerComponent *this, int slot_index, UFG::GetInPedFormationNode *get_in_formation)
{
  float *v3; // rdi
  UFG::GetInPedFormationNode *v4; // rsi
  int v5; // er14
  UFG::PedFormationManagerComponent *v6; // rbp
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // r9
  UFG::SimComponent *v9; // rbx
  UFG::SimObject *v10; // rbx
  UFG::TransformNodeComponent *v11; // rbx
  float v12; // xmm1_4
  float v13; // xmm0_4
  UFG::qVector3 desired_direction; // [rsp+20h] [rbp-18h]

  v3 = (float *)this->m_pTransformNodeComponent.m_pSimComponent;
  v4 = get_in_formation;
  v5 = slot_index;
  v6 = this;
  if ( v3 )
  {
    v7 = get_in_formation->m_pOwner.m_pPointer;
    if ( v7 )
    {
      v8 = v7->m_pSimObject;
      if ( v8 )
      {
        if ( v8->m_pTransformNodeComponent )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
          v9 = v4->m_pOwner.m_pPointer;
          if ( v9 && (v10 = v9->m_pSimObject) != 0i64 )
            v11 = v10->m_pTransformNodeComponent;
          else
            v11 = 0i64;
          UFG::TransformNodeComponent::UpdateWorldTransform(v11);
          v12 = v11->mWorldTransform.v3.y - v3[45];
          desired_direction.x = v11->mWorldTransform.v3.x - v3[44];
          v13 = v11->mWorldTransform.v3.z;
          desired_direction.y = v12;
          desired_direction.z = v13 - v3[46];
          UFG::PedFormationManagerComponent::SetDesiredDirection(v6, v5, v4, &desired_direction);
        }
      }
    }
  }
}

// File Line: 1660
// RVA: 0x3859C0
void __fastcall UFG::PedFormationManagerComponent::SetDesiredDirection(UFG::PedFormationManagerComponent *this, int slot_index, UFG::GetInPedFormationNode *get_in_formation, UFG::qVector3 *desired_direction)
{
  UFG::PedFormationSlot *v4; // rbx
  UFG::PedFormationManagerComponent *v5; // rsi
  UFG::SimObjectGame *v6; // rcx
  UFG::qVector3 *v7; // r14
  UFG::GetInPedFormationNode *v8; // rdi
  signed __int64 v9; // rbx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // rcx
  UFG::SimObject *v13; // rdx
  float *v14; // rbp
  UFG::HavokNavPosition *v15; // r15
  UFG::SimComponent *v16; // rdi
  UFG::SimObject *v17; // rdi
  UFG::TransformNodeComponent *v18; // rdi
  __int64 v19; // rax
  char v20; // r12
  __m128 v21; // xmm0
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm9_4
  float v26; // xmm6_4
  float v27; // xmm0_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm7_4
  float v31; // xmm8_4
  __m128 v32; // xmm1
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm4_4
  __m128 v36; // xmm1
  float v37; // xmm2_4
  __int64 v38; // rax
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm0_4
  bool v42; // al
  unsigned int v43; // er15
  float v44; // xmm0_4
  bool v45; // r14
  float v46; // xmm1_4
  bool v47; // bp
  int v48; // edi
  float v49; // xmm0_4
  UFG::qVector3 direction; // [rsp+40h] [rbp-78h]
  float current_lateral_offset; // [rsp+C0h] [rbp+8h]
  float max_clear_distance; // [rsp+C8h] [rbp+10h]

  v4 = this->m_Slots.p;
  v5 = this;
  v6 = (UFG::SimObjectGame *)this->m_pSimObject;
  v7 = desired_direction;
  v8 = get_in_formation;
  v9 = (signed __int64)&v4[slot_index];
  if ( v6 )
  {
    v10 = v6->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = v6->m_Components.p[36].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NavComponent::_TypeUID);
      else
        v11 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NavComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::NavComponent::_TypeUID);
    }
    else
    {
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NavComponent::_TypeUID);
    }
    if ( v11 )
    {
      if ( v5->m_pTransformNodeComponent.m_pSimComponent )
      {
        v12 = v8->m_pOwner.m_pPointer;
        if ( v12 )
        {
          v13 = v12->m_pSimObject;
          if ( v13 )
          {
            if ( v13->m_pTransformNodeComponent && *(_QWORD *)(v9 + 152) )
            {
              v14 = (float *)v5->m_pTransformNodeComponent.m_pSimComponent;
              v15 = (UFG::HavokNavPosition *)&v11[1].m_SafePointerList.mNode.mNext;
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent);
              v16 = v8->m_pOwner.m_pPointer;
              if ( v16 && (v17 = v16->m_pSimObject) != 0i64 )
                v18 = v17->m_pTransformNodeComponent;
              else
                v18 = 0i64;
              UFG::TransformNodeComponent::UpdateWorldTransform(v18);
              v19 = *(_QWORD *)(v9 + 152);
              v20 = 1;
              v21 = (__m128)LODWORD(v18->mWorldTransform.v3.y);
              v22 = v18->mWorldTransform.v3.x - v14[44];
              v23 = *(float *)(v19 + 40);
              v21.m128_f32[0] = (float)((float)(v21.m128_f32[0] - v14[45]) * (float)(v21.m128_f32[0] - v14[45]))
                              + (float)(v22 * v22);
              v24 = *(float *)(v19 + 44);
              LODWORD(v25) = (unsigned __int128)_mm_sqrt_ps(v21);
              v26 = v25;
              if ( v25 <= v23 )
                v27 = *(float *)(v19 + 40);
              else
                v27 = v25;
              if ( v27 >= v24 )
                v27 = *(float *)(v19 + 44);
              if ( v25 != v27 )
              {
                v20 = 0;
                v26 = (float)(v24 + v23) * 0.5;
              }
              v28 = v7->x;
              v29 = v7->y;
              v30 = 0.0;
              v31 = 0.0;
              if ( (float)((float)(v29 * v29) + (float)(v28 * v28)) > 0.0099999998 )
              {
                v32 = (__m128)LODWORD(v7->y);
                v32.m128_f32[0] = (float)(v29 * v29) + (float)(v28 * v28);
                v33 = v26 / COERCE_FLOAT(_mm_sqrt_ps(v32));
                v30 = v28 * v33;
                v31 = v29 * v33;
              }
              direction.x = v30;
              direction.y = v31;
              direction.z = 0.0;
              max_clear_distance = 0.0;
              if ( !UFG::PedFormationManagerComponent::DirectionIsClear(
                      v5,
                      v15,
                      &direction,
                      &max_clear_distance,
                      eCONSTRAIN_TO_SIDEWALKS_NO) )
              {
                v34 = v7->x;
                v35 = v7->y;
                v26 = max_clear_distance;
                if ( (float)((float)(v35 * v35) + (float)(v34 * v34)) > 0.0099999998 )
                {
                  v36 = (__m128)LODWORD(v7->y);
                  v36.m128_f32[0] = (float)(v35 * v35) + (float)(v34 * v34);
                  v37 = max_clear_distance / COERCE_FLOAT(_mm_sqrt_ps(v36));
                  v30 = v34 * v37;
                  v31 = v35 * v37;
                }
              }
              v38 = *(_QWORD *)(v9 + 152);
              v39 = v31 + v14[45];
              v40 = *(float *)(v38 + 60);
              direction.x = v30 + v14[44];
              direction.z = v14[46];
              v41 = *(float *)(v38 + 64);
              direction.y = v39;
              current_lateral_offset = 0.0;
              max_clear_distance = 0.0;
              v42 = UFG::PedFormationManagerComponent::IsInPosition(
                      v5,
                      (UFG::qVector3 *)&v18->mWorldTransform.v3,
                      &direction,
                      v40,
                      v41,
                      &max_clear_distance,
                      &current_lateral_offset,
                      0);
              v43 = *(_DWORD *)(v9 + 32);
              v44 = *(float *)&FLOAT_1_0;
              v45 = v42;
              v46 = *(float *)&FLOAT_1_0;
              if ( v43 <= 2 )
              {
                v44 = FLOAT_2_0;
                v46 = FLOAT_2_0;
              }
              v47 = max_clear_distance <= v44 && current_lateral_offset <= v46;
              v48 = 0;
              if ( !UFG::PedFormationManagerComponent::IsFarFromPosition(
                      v5,
                      *(UFG::PedFormationProfile::Slot **)(v9 + 152),
                      max_clear_distance,
                      v25) )
              {
                if ( v43 != 4 )
                {
                  if ( v45 )
                  {
LABEL_42:
                    if ( unk_14206D75C < v5->m_Speed )
                      v48 = 1;
                    goto LABEL_47;
                  }
                  v48 = 3 - (v47 != 0);
LABEL_47:
                  *(float *)v9 = v30;
                  *(float *)(v9 + 4) = v31;
                  *(_DWORD *)(v9 + 8) = 0;
                  v49 = atan2f(v31, v30);
                  *(float *)(v9 + 16) = v26;
                  *(_BYTE *)(v9 + 40) = v20;
                  *(_WORD *)(v9 + 12) = (signed int)(float)((float)(v49 * 32768.0) * 0.31830987);
                  UFG::PedFormationSlot::SetInPosition(
                    (UFG::PedFormationSlot *)v9,
                    (UFG::PedFormationSlot::ePositionType)v48);
                  return;
                }
                if ( v45 )
                  goto LABEL_42;
              }
              v48 = 4;
              goto LABEL_47;
            }
          }
        }
      }
    }
  }
}        v48 = 4;
              goto LABEL_47;
            }
          }
        }
      }
    }
  }
}

// File Line: 1759
// RVA: 0x36A970
bool __fastcall UFG::PedFormationManagerComponent::IsFarFromPosition(UFG::PedFormationManagerComponent *this, UFG::PedFormationProfile::Slot *profileSlot, float current_radial_offset, float current_distance_from_centre)
{
  UFG::PedFormationProfile *v4; // rax
  bool result; // al

  if ( this->m_CurrentlySprinting && (v4 = this->m_pCurrentProfile) != 0i64 )
    result = current_radial_offset >= v4->mMaxRadialDistanceFromDesiredPositionToBeginSprintingWhenTargetSprinting;
  else
    result = current_radial_offset >= (float)((float)(profileSlot->mMaxRadialDistanceFromDesiredPositionHysteresis
                                                    + profileSlot->mMaxRadialDistanceFromDesiredPosition)
                                            + 5.0);
  return result;
}

// File Line: 1777
// RVA: 0x35FC00
UFG::GetInPedFormationNode *__fastcall UFG::PedFormationManagerComponent::GetFollowersPair(UFG::PedFormationManagerComponent *this, UFG::SimObject *pFollower)
{
  unsigned int v2; // er9
  unsigned int v3; // er8
  UFG::GetInPedFormationNode **v4; // rax
  UFG::SimObject *v5; // rcx

  v2 = this->m_Slots.size;
  v3 = 0;
  if ( !v2 )
    return 0i64;
  v4 = &this->m_Slots.p[0].m_pMember.m_pPointer;
  while ( 1 )
  {
    if ( *v4 )
    {
      v5 = (UFG::SimObject *)(*v4)->m_pOwner.m_pPointer;
      if ( v5 )
        v5 = (UFG::SimObject *)v5->mNode.mParent;
      if ( v5 == pFollower )
        break;
    }
    ++v3;
    v4 += 20;
    if ( v3 >= v2 )
      return 0i64;
  }
  return v4[3];
}

// File Line: 1791
// RVA: 0x360970
UFG::SimObject *__fastcall UFG::PedFormationManagerComponent::GetLeadersPair(UFG::PedFormationManagerComponent *this)
{
  return this->m_Pair.m_pPair.m_pPointer;
}

// File Line: 1796
// RVA: 0x35AFE0
UFG::SimObject *__fastcall UFG::PedFormationManagerComponent::GetClosestMember(UFG::PedFormationManagerComponent *this, UFG::qVector3 *pos, UFG::SimObject *pExclude1, UFG::SimObject *pExclude2)
{
  float *v4; // rdi
  UFG::SimObject *v5; // r14
  UFG::SimObject *v6; // r15
  UFG::SimObject *v7; // r12
  UFG::qVector3 *v8; // r13
  float v9; // xmm6_4
  UFG::PedFormationManagerComponent *v10; // rbp
  UFG::SimObject *v11; // rbx
  __int64 v12; // rsi
  UFG::GetInPedFormationNode *v13; // rax
  UFG::SimComponent *v14; // rcx
  UFG::SimObject *v15; // rdx
  UFG::SimObject *v16; // rbx
  UFG::TransformNodeComponent *v17; // rdi

  v4 = (float *)this->m_pTransformNodeComponent.m_pSimComponent;
  v5 = 0i64;
  v6 = pExclude2;
  v7 = pExclude1;
  v8 = pos;
  v9 = 0.0;
  v10 = this;
  if ( v4 )
  {
    v11 = this->m_pSimObject;
    if ( v11 != pExclude1 && v11 != pExclude2 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
      v5 = v11;
      v9 = (float)((float)((float)(v4[45] - v8->y) * (float)(v4[45] - v8->y))
                 + (float)((float)(v4[44] - v8->x) * (float)(v4[44] - v8->x)))
         + (float)((float)(v4[46] - v8->z) * (float)(v4[46] - v8->z));
    }
  }
  v12 = 0i64;
  if ( v10->m_Slots.size )
  {
    do
    {
      v13 = v10->m_Slots.p[v12].m_pMember.m_pPointer;
      if ( v13 )
      {
        v14 = v13->m_pOwner.m_pPointer;
        if ( v14 )
        {
          v15 = v14->m_pSimObject;
          if ( v15 )
          {
            if ( v15->m_pTransformNodeComponent )
            {
              v16 = v14 ? v14->m_pSimObject : 0i64;
              if ( v16 != v7 && v16 != v6 )
              {
                if ( v14 && v15 )
                  v17 = v15->m_pTransformNodeComponent;
                else
                  v17 = 0i64;
                UFG::TransformNodeComponent::UpdateWorldTransform(v17);
                if ( !v5
                  || (float)((float)((float)((float)(v17->mWorldTransform.v3.y - v8->y)
                                           * (float)(v17->mWorldTransform.v3.y - v8->y))
                                   + (float)((float)(v17->mWorldTransform.v3.x - v8->x)
                                           * (float)(v17->mWorldTransform.v3.x - v8->x)))
                           + (float)((float)(v17->mWorldTransform.v3.z - v8->z)
                                   * (float)(v17->mWorldTransform.v3.z - v8->z))) < v9 )
                {
                  v9 = (float)((float)((float)(v17->mWorldTransform.v3.y - v8->y)
                                     * (float)(v17->mWorldTransform.v3.y - v8->y))
                             + (float)((float)(v17->mWorldTransform.v3.x - v8->x)
                                     * (float)(v17->mWorldTransform.v3.x - v8->x)))
                     + (float)((float)(v17->mWorldTransform.v3.z - v8->z) * (float)(v17->mWorldTransform.v3.z - v8->z));
                  v5 = v16;
                }
              }
            }
          }
        }
      }
      v12 = (unsigned int)(v12 + 1);
    }
    while ( (unsigned int)v12 < v10->m_Slots.size );
  }
  return v5;
}

// File Line: 1834
// RVA: 0x38ACD0
void __fastcall UFG::PedFormationManagerComponent::UnregisterSlot(UFG::PedFormationManagerComponent *this, int slot_index)
{
  UFG::PedFormationManagerComponent *v2; // r8
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v3; // rcx
  signed __int64 v4; // r10
  __int64 v5; // r11
  char *v6; // rcx
  __int64 v7; // rdx
  _QWORD *v8; // rax
  signed __int64 v9; // rdx
  __int64 v10; // rcx
  _QWORD *v11; // rax
  UFG::PedFormationProfile::Slot *v12; // r9
  unsigned int v13; // edx
  int v14; // ecx
  __int64 *v15; // rdx
  __int64 v16; // rcx
  _QWORD *v17; // rax
  __int64 v18; // rdx
  __int64 v19; // rdx
  __int64 *v20; // rdx
  __int64 v21; // rcx
  _QWORD *v22; // rax

  v2 = this;
  v3 = &this->m_Slots.p[0].m_pMember;
  v4 = (unsigned int)slot_index;
  v5 = *(__int64 *)((char *)&v3->m_pPointer + v4 * 160);
  v6 = (char *)v3 + v4 * 160;
  if ( *((_QWORD *)v6 + 2) )
  {
    v7 = *(_QWORD *)v6;
    v8 = (_QWORD *)*((_QWORD *)v6 + 1);
    *(_QWORD *)(v7 + 8) = v8;
    *v8 = v7;
    *(_QWORD *)v6 = v6;
    *((_QWORD *)v6 + 1) = v6;
  }
  v9 = (signed __int64)&v2->m_Slots.p[v4].m_Pair;
  *((_QWORD *)v6 + 2) = 0i64;
  if ( *(_QWORD *)(v9 + 16) )
  {
    v10 = *(_QWORD *)v9;
    v11 = *(_QWORD **)(v9 + 8);
    *(_QWORD *)(v10 + 8) = v11;
    *v11 = v10;
    *(_QWORD *)v9 = v9;
    *(_QWORD *)(v9 + 8) = v9;
  }
  *(_QWORD *)(v9 + 16) = 0i64;
  *(_DWORD *)(v9 + 24) = -1082130432;
  v12 = v2->m_Slots.p[v4].m_pProfileSlot;
  if ( v12 )
  {
    v13 = v2->m_ProfileSlots.size;
    v14 = 0;
    if ( v13 )
    {
      while ( v12 != v2->m_ProfileSlots.p[v14].mProfileSlot.m_pPointer )
      {
        if ( ++v14 >= v13 )
          goto LABEL_11;
      }
      v2->m_ProfileSlots.p[v14].mMemberSlot = 0i64;
      v2->m_Slots.p[v4].m_pProfileSlot = 0i64;
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
    ++v2->m_NumFreeSlots;
  }
}

// File Line: 1858
// RVA: 0x360020
signed __int64 __fastcall UFG::PedFormationManagerComponent::GetInPositionType(UFG::PedFormationManagerComponent *this, UFG::GetInPedFormationNode *get_in_formation)
{
  __int64 v2; // r8
  signed __int64 result; // rax

  if ( get_in_formation
    && (v2 = (unsigned int)get_in_formation->m_SlotIndex, (_DWORD)v2 != -1)
    && (unsigned int)v2 < this->m_Slots.size
    && this->m_Slots.p[v2].m_pMember.m_pPointer == get_in_formation )
  {
    result = (unsigned int)this->m_Slots.p[v2].m_InPosition;
  }
  else
  {
    result = 3i64;
  }
  return result;
}

// File Line: 1887
// RVA: 0x377D20
void __fastcall UFG::PedFormationManagerComponent::OnArrived(UFG::PedFormationManagerComponent *this, UFG::GetInPedFormationNode *get_in_formation, UFG::qVector3 *desired_position, float desired_speed)
{
  __int64 v4; // r9
  float *v5; // rbx
  float v6; // xmm0_4
  __int64 v7; // r9

  if ( unk_14206D75C < this->m_Speed )
  {
    if ( get_in_formation )
    {
      v7 = (unsigned int)get_in_formation->m_SlotIndex;
      if ( (_DWORD)v7 != -1
        && (unsigned int)v7 < this->m_Slots.size
        && this->m_Slots.p[v7].m_pMember.m_pPointer == get_in_formation
        && this->m_Slots.p[v7].m_InPosition != 1 )
      {
        this->m_Slots.p[v7].m_InPosition = 1;
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
      v5 = &this->m_Slots.p[v4].m_Direction.x;
      if ( *((_DWORD *)v5 + 8) )
      {
        v6 = UFG::Metrics::msInstance.mSimTime_Temp;
        *((_DWORD *)v5 + 27) = 1;
        v5[26] = v6;
        UFG::PedFormationSlot::SetRadialHysteresisModifier(&this->m_Slots.p[v4]);
        if ( *((_DWORD *)v5 + 8) )
          v5[8] = 0.0;
      }
    }
  }
}

// File Line: 1900
// RVA: 0x351850
__int64 __fastcall UFG::PedFormationManagerComponent::CrossesLeadersPath(UFG::PedFormationManagerComponent *this, UFG::qVector2 *follower_start, UFG::qVector2 *follower_end)
{
  UFG::qVector2 *lB1; // rsi
  UFG::qVector2 *v4; // rbp
  UFG::PedFormationManagerComponent *v5; // rdi
  UFG::TransformNodeComponent *v6; // rbx
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  int v12; // eax
  unsigned __int8 v13; // cl
  UFG::qVector2 intersection; // [rsp+30h] [rbp-48h]
  UFG::qVector2 lA1; // [rsp+80h] [rbp+8h]
  UFG::qVector2 lA0; // [rsp+98h] [rbp+20h]

  lB1 = follower_end;
  v4 = follower_start;
  v5 = this;
  if ( !this->m_pTransformNodeComponent.m_pSimComponent )
    return 0i64;
  v6 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v7 = COERCE_FLOAT(unk_14206D764 ^ _xmm[0]) * this->m_FormationForward.y;
  v8 = COERCE_FLOAT(unk_14206D764 ^ _xmm[0]) * this->m_FormationForward.x;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  v9 = unk_14206D760 * v5->m_FormationForward.y;
  v10 = unk_14206D760 * v5->m_FormationForward.x;
  v11 = v6->mWorldTransform.v3.y + v7;
  lA0.x = v8 + v6->mWorldTransform.v3.x;
  lA0.y = v11;
  lA1.x = v10 + lA0.x;
  lA1.y = v9 + v11;
  v12 = UFG::qIntersect(&intersection, &lA0, &lA1, v4, lB1, 0i64);
  v13 = 0;
  if ( v12 == 3 )
    v13 = 1;
  return v13;
}

// File Line: 1919
// RVA: 0x35DB90
char __fastcall UFG::PedFormationManagerComponent::GetDesiredPosition(UFG::PedFormationManagerComponent *this, UFG::GetInPedFormationNode *get_in_formation, UFG::qVector3 *desired_position)
{
  UFG::qVector3 *v3; // rsi
  UFG::GetInPedFormationNode *v4; // rdi
  UFG::PedFormationManagerComponent *v5; // rbx
  __int64 v6; // rax
  float *v7; // rbp
  __int64 v8; // rax
  UFG::SimObject *v9; // r8
  float v10; // xmm9_4
  float v11; // xmm10_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  unsigned __int16 v15; // cx
  UFG::NavComponent *v16; // rdi
  UFG::SimComponent *v17; // rax
  bool v18; // zf
  UFG::SimObjectGame *v19; // rcx
  float v20; // xmm0_4
  float v21; // xmm7_4
  float v22; // xmm8_4
  float v23; // xmm0_4
  float v24; // xmm9_4
  float v25; // xmm10_4
  float v26; // xmm7_4
  float v27; // xmm8_4

  v3 = desired_position;
  v4 = get_in_formation;
  v5 = this;
  if ( !this->m_pTransformNodeComponent.m_pSimComponent )
    return 0;
  if ( !get_in_formation )
    return 0;
  v6 = (unsigned int)get_in_formation->m_SlotIndex;
  if ( (_DWORD)v6 == -1
    || (unsigned int)v6 >= this->m_Slots.size
    || this->m_Slots.p[v6].m_pMember.m_pPointer != get_in_formation )
  {
    return 0;
  }
  v7 = (float *)this->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
  v8 = (unsigned int)v4->m_SlotIndex;
  v9 = v5->m_pSimObject;
  v10 = v5->m_FormationForward.x;
  v11 = v5->m_FormationForward.y;
  v12 = v5->m_Slots.p[v8].m_Direction.x;
  v13 = v5->m_Slots.p[v8].m_Direction.y;
  v14 = v5->m_Slots.p[v8].m_Direction.z;
  if ( v9
    && ((v15 = v9->m_Flags, !((v15 >> 14) & 1)) ? ((v15 & 0x8000u) == 0 ? (!((v15 >> 13) & 1) ? ((v18 = ((v15 >> 12) & 1) == 0,
                                                                                                  v19 = (UFG::SimObjectGame *)v5->m_pSimObject,
                                                                                                  v18) ? (v17 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v19->vfptr, UFG::NavComponent::_TypeUID)) : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::NavComponent::_TypeUID))) : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v5->m_pSimObject, UFG::NavComponent::_TypeUID))) : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v5->m_pSimObject, UFG::NavComponent::_TypeUID)),
                                                   v16 = (UFG::NavComponent *)v17) : (v16 = (UFG::NavComponent *)v9->m_Components.p[36].m_pComponent),
        v16) )
  {
    if ( unk_14206D75C < v5->m_Speed )
    {
      v20 = UFG::NavComponent::GetAvoidanceRadius(v16) * 2.75;
      v12 = v12 * v20;
      v13 = v13 * v20;
      v14 = v14 * v20;
    }
    v21 = v13 + v7[45];
    v22 = v14 + v7[46];
    v3->x = v12 + v7[44];
    v3->y = v21;
    v3->z = v22;
    if ( unk_14206D75C < v5->m_Speed )
    {
      v23 = UFG::NavComponent::GetAvoidanceRadius(v16);
      v24 = (float)(v10 * v23) + v3->x;
      v25 = (float)(v11 * v23) + v3->y;
      v3->z = (float)(v23 * 0.0) + v3->z;
      v3->x = v24;
      v3->y = v25;
    }
  }
  else
  {
    v26 = v13 + v7[45];
    v27 = v14 + v7[46];
    v3->x = v12 + v7[44];
    v3->y = v26;
    v3->z = v27;
  }
  return 1;
}

// File Line: 1954
// RVA: 0x35E3A0
bool __fastcall UFG::PedFormationManagerComponent::GetDesiredWaypoint(UFG::PedFormationManagerComponent *this, UFG::GetInPedFormationNode *get_in_formation, UFG::qVector3 *desired_waypoint, float *desired_speed)
{
  float *v4; // r14
  UFG::qVector3 *v5; // rsi
  UFG::GetInPedFormationNode *v6; // rdi
  UFG::PedFormationManagerComponent *v7; // rbx
  signed __int64 v8; // rdi
  UFG::SimComponent *v9; // rbp
  UFG::SimObject *v10; // rbp
  UFG::TransformNodeComponent *v11; // rbp
  UFG::SimComponent *v12; // rcx
  UFG::SimObject *v13; // rcx
  UFG::TransformNodeComponent *v14; // rcx
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  __int128 v24; // xmm3
  float v25; // xmm2_4
  __m128 v26; // xmm1
  float v27; // xmm6_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  bool result; // al
  UFG::SimComponent *v31; // rbp
  UFG::SimObject *v32; // rbp
  UFG::TransformNodeComponent *v33; // rbp
  float v34; // xmm7_4
  float v35; // xmm6_4
  float v36; // xmm8_4
  UFG::eMoveType v37; // eax
  float v38; // xmm1_4
  UFG::eMoveType v39; // eax
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm8_4
  UFG::SimObjectGame *v43; // rcx
  unsigned __int16 v44; // dx
  UFG::SimComponent *v45; // rax
  int v46; // ecx
  UFG::qVector2 follower_end; // [rsp+20h] [rbp-58h]
  UFG::qVector2 follower_start; // [rsp+28h] [rbp-50h]

  v4 = desired_speed;
  v5 = desired_waypoint;
  v6 = get_in_formation;
  v7 = this;
  if ( UFG::PedFormationManagerComponent::GetDesiredPosition(this, get_in_formation, desired_waypoint) )
  {
    v8 = (unsigned int)v6->m_SlotIndex;
    v9 = v7->m_Slots.p[v8].m_pMember.m_pPointer->m_pOwner.m_pPointer;
    if ( v9 && (v10 = v9->m_pSimObject) != 0i64 )
      v11 = v10->m_pTransformNodeComponent;
    else
      v11 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v11);
    v12 = v7->m_Slots.p[v8].m_pMember.m_pPointer->m_pOwner.m_pPointer;
    if ( v12 && (v13 = v12->m_pSimObject) != 0i64 )
      v14 = v13->m_pTransformNodeComponent;
    else
      v14 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v14);
    v15 = v7->m_Slots.p[v8].m_pProfileSlot->mMaxLookAhead;
    if ( v7->m_IsDestinationValid
      && v7->m_IsApproachingTurn
      && (float)((float)((float)((float)(v5->y - v7->m_Destination.y) * (float)(v5->y - v7->m_Destination.y))
                       + (float)((float)(v5->x - v7->m_Destination.x) * (float)(v5->x - v7->m_Destination.x)))
               + (float)((float)(v5->z - v7->m_Destination.z) * (float)(v5->z - v7->m_Destination.z))) < (float)((float)(unk_14206D784 + v15) * (float)(unk_14206D784 + v15)) )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7->m_pTransformNodeComponent.m_pSimComponent);
      v16 = v5->y;
      v17 = v7->m_FormationForward.y;
      v18 = unk_14206D784;
      v19 = (float)(v7->m_FormationForward.x * (float)(v7->m_Destination.x - v5->x))
          + (float)(v7->m_FormationForward.y * (float)(v7->m_Destination.y - v16));
      if ( v19 < unk_14206D784 )
      {
        LODWORD(v20) = COERCE_UNSIGNED_INT(unk_14206D784 - v19) ^ _xmm[0];
        v5->x = (float)(v7->m_FormationForward.x * v20) + v5->x;
        v5->y = (float)(v17 * v20) + v16;
        v18 = unk_14206D784;
      }
      v21 = v19 - v18;
      if ( v21 <= 0.0 )
        v21 = 0.0;
      if ( v21 < v15 )
        v15 = v21;
    }
    v22 = v5->y;
    v23 = v7->m_FormationForward.y * 0.5;
    follower_end.x = v5->x + (float)(v7->m_FormationForward.x * 0.5);
    follower_start.y = v11->mWorldTransform.v3.y;
    follower_end.y = v22 + v23;
    follower_start.x = v11->mWorldTransform.v3.x;
    if ( (unsigned __int8)UFG::PedFormationManagerComponent::CrossesLeadersPath(v7, &follower_start, &follower_end) )
      v15 = 0.0;
    if ( unk_14206D75C < v7->m_Speed && v7->m_Slots.p[v8].m_InPosition == 1 )
    {
      if ( v15 >= unk_14206D714 )
        v15 = unk_14206D714;
      v24 = LODWORD(v7->m_FormationForward.y);
      v25 = v7->m_FormationForward.x;
      v26 = (__m128)v24;
      v26.m128_f32[0] = (float)(*(float *)&v24 * *(float *)&v24) + (float)(v25 * v25);
      v27 = v15 / COERCE_FLOAT(_mm_sqrt_ps(v26));
      *(float *)&v24 = (float)(*(float *)&v24 * v27) + v5->y;
      v5->x = (float)(v25 * v27) + v5->x;
      LODWORD(v5->y) = v24;
    }
    v28 = (float)((float)(v11->mWorldTransform.v3.y - v5->y) * v7->m_FormationForward.y)
        + (float)((float)(v11->mWorldTransform.v3.x - v5->x) * v7->m_FormationForward.x);
    if ( v28 > 0.0 )
    {
      v29 = v7->m_Speed;
      if ( v29 > 0.1 && (float)(v28 / v29) < unk_14206D758 )
        return 0;
    }
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7->m_pTransformNodeComponent.m_pSimComponent);
    v31 = v7->m_Slots.p[v8].m_pMember.m_pPointer->m_pOwner.m_pPointer;
    if ( v31 && (v32 = v31->m_pSimObject) != 0i64 )
      v33 = v32->m_pTransformNodeComponent;
    else
      v33 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v33);
    v34 = v33->mWorldTransform.v3.x - v5->x;
    v35 = v33->mWorldTransform.v3.y - v5->y;
    v36 = UFG::LinearGraph<float>::GetValue(
            &stru_14206D718,
            (float)(v35 * v7->m_FormationForward.y) + (float)(v34 * v7->m_FormationForward.x));
    if ( (float)((float)(v35 * v35) + (float)(v34 * v34)) > unk_14206D750 && v36 <= 1.0 )
      v36 = *(float *)&FLOAT_1_0;
    v37 = v7->m_Slots.p[v8].m_NextMoveType;
    if ( v37 )
    {
      v38 = v7->m_Slots.p[v8].m_ReactionTimer.mNextTime;
      if ( v38 < 0.0 || v38 > 0.0 && UFG::Metrics::msInstance.mSimTime_Temp >= v38 )
      {
        v7->m_Slots.p[v8].m_DesiredMoveType = v37;
        v7->m_Slots.p[v8].m_NextMoveType = 0;
        v7->m_Slots.p[v8].m_ReactionTimer.mNextTime = -1.0;
      }
    }
    else if ( v7->m_Slots.p[v8].m_InPosition <= 1u )
    {
      v7->m_Slots.p[v8].m_DesiredMoveType = v7->m_LeaderMoveType;
      v43 = (UFG::SimObjectGame *)v7->m_pSimObject;
      if ( v43 )
      {
        v44 = v43->m_Flags;
        if ( (v44 >> 14) & 1 )
        {
          v45 = v43->m_Components.p[36].m_pComponent;
        }
        else if ( (v44 & 0x8000u) == 0 )
        {
          if ( (v44 >> 13) & 1 )
            v45 = UFG::SimObjectGame::GetComponentOfTypeHK(v43, UFG::NavComponent::_TypeUID);
          else
            v45 = (v44 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v43, UFG::NavComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v43->vfptr, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v45 = UFG::SimObjectGame::GetComponentOfTypeHK(v43, UFG::NavComponent::_TypeUID);
        }
        if ( v45 )
        {
          v46 = *(_DWORD *)(*(_QWORD *)&v45[2].m_TypeUID + 52i64);
          result = 1;
          *(_DWORD *)v4 = v46;
          return result;
        }
      }
    }
    v39 = v7->m_Slots.p[v8].m_DesiredMoveType;
    if ( v39 == 3 )
    {
      v40 = FLOAT_7_5;
      v41 = FLOAT_4_8000002;
      v42 = v36 * 7.5;
      if ( v42 <= 4.8000002 )
      {
LABEL_45:
        v42 = v41;
LABEL_68:
        result = 1;
        *v4 = v42;
        return result;
      }
    }
    else
    {
      if ( v39 == 2 )
      {
        v41 = FLOAT_3_0;
        v42 = v36 * 3.95;
        if ( v42 > 3.0 )
        {
          if ( v42 >= 3.95 )
          {
            *v4 = FLOAT_3_95;
            return 1;
          }
          goto LABEL_68;
        }
        goto LABEL_45;
      }
      v42 = v36 * 1.5;
      if ( v42 <= 0.0 )
      {
        v42 = 0.0;
        goto LABEL_68;
      }
      v40 = FLOAT_3_0;
    }
    if ( v42 >= v40 )
    {
      *v4 = v40;
      return 1;
    }
    goto LABEL_68;
  }
  return 0;
}

// File Line: 2249
// RVA: 0x36AE60
bool __fastcall UFG::PedFormationManagerComponent::IsInPedFormation(UFG::PedFormationManagerComponent *this, UFG::GetInPedFormationNode *get_in_formation)
{
  __int64 v2; // r8
  unsigned int v3; // er10
  bool result; // al

  result = 0;
  if ( get_in_formation )
  {
    v2 = (unsigned int)get_in_formation->m_SlotIndex;
    if ( (_DWORD)v2 != -1 )
    {
      v3 = this->m_Slots.size;
      if ( (unsigned int)v2 < v3
        && this->m_Slots.p[v2].m_pMember.m_pPointer == get_in_formation
        && this->m_Slots.p[v2].m_InPosition == ePOSITION_IN_POSITION
        && (_DWORD)v2 != -1
        && (unsigned int)v2 < v3
        && this->m_Slots.p[v2].m_pMember.m_pPointer == get_in_formation
        && this->m_Slots.p[v2].m_CurrentlyFacingCorrectly )
      {
        result = 1;
      }
    }
  }
  return result;
}

