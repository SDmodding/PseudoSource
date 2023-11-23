// File Line: 24
// RVA: 0x14B9530
__int64 UFG::AIAwareness::_dynamic_initializer_for__gSymHeadBone__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Head", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::AIAwareness::gSymHeadBone, v0);
  return atexit((int (__fastcall *)())UFG::AIAwareness::_dynamic_atexit_destructor_for__gSymHeadBone__);
}

// File Line: 77
// RVA: 0x39BD90
void __fastcall UFG::AIAwareness::Effector::UpdateScanLogic(
        UFG::AIAwareness::Effector *this,
        UFG::AIAwareness::SubProfileAI *pAIProperties,
        UFG::qVector3 *forward)
{
  float mTimeTotal; // xmm0_4
  float v6; // xmm8_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm8_4
  float x; // xmm0_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-68h] BYREF
  UFG::qVector3 dest; // [rsp+30h] [rbp-58h] BYREF
  UFG::qVector3 source; // [rsp+40h] [rbp-48h] BYREF

  if ( this->mType == EFFECTORTYPE_HEAD )
  {
    mTimeTotal = this->mTimeTotal;
    v6 = 0.0;
    v7 = (float)(mTimeTotal - 0.5) - 0.5;
    if ( this->mPerformCheckoutSequence && v7 > 0.0 )
    {
      v8 = (float)(mTimeTotal - this->mTimeLeft) - 0.5;
      if ( v8 > 0.0 && v8 < v7 )
        v6 = (float)((float)(sinf((float)(v8 / v7) * 3.1415927) * -20.0) * 3.1415927) * 0.0055555557;
    }
    v9 = v6 + (float)((float)(pAIProperties->mHeightOffsetAngle * 3.1415927) * 0.0055555557);
    x = this->mActivePosition.x;
    v2.z = this->mActivePosition.z - this->mMyPosition.z;
    v2.x = x - this->mMyPosition.x;
    v2.y = this->mActivePosition.y - this->mMyPosition.y;
    v11 = UFG::qHeadingDifference2D(&UFG::qVector3::msAxisX, &v2);
    UFG::qRotateVectorZ(&dest, &v2, v11);
    v12 = sinf(v9);
    v13 = cosf(v9);
    source.y = dest.y;
    source.z = (float)(dest.x * v12) + (float)(dest.z * v13);
    source.x = (float)(dest.x * v13) - (float)(dest.z * v12);
    UFG::qRotateVectorZ(&this->mActivePosition, &source, COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]));
    v14 = this->mMyPosition.z + this->mActivePosition.z;
    v15 = this->mActivePosition.x + this->mMyPosition.x;
    this->mActivePosition.y = this->mActivePosition.y + this->mMyPosition.y;
    this->mActivePosition.z = v14;
    this->mActivePosition.x = v15;
  }
}

// File Line: 150
// RVA: 0x39B940
void __fastcall UFG::AIAwareness::Effector::UpdateActivePosition(
        UFG::AIAwareness::Effector *this,
        UFG::qVector3 *forward)
{
  UFG::qVector3 *p_mForward; // rdi
  float y; // xmm0_4
  float z; // xmm1_4
  float v6; // xmm2_4
  __m128 y_low; // xmm3
  __m128 v8; // xmm1
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4

  if ( this->mState == EFFECTORSTATE_WAIT )
  {
    p_mForward = &this->mForward;
  }
  else
  {
    if ( this->mActiveType != CANDIDATETYPE_SIMOBJECT )
    {
      this->mHasValidPosition = 1;
      y_low = (__m128)LODWORD(this->mActivePosition.y);
      v6 = this->mActivePosition.x - this->mMyPosition.x;
      y_low.m128_f32[0] = y_low.m128_f32[0] - this->mMyPosition.y;
      v8 = y_low;
      v8.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v6 * v6);
      if ( v8.m128_f32[0] == 0.0 )
        v9 = 0.0;
      else
        v9 = 1.0 / _mm_sqrt_ps(v8).m128_f32[0];
      p_mForward = &this->mForward;
      this->mForward.x = v6 * v9;
      this->mForward.y = y_low.m128_f32[0] * v9;
      z = v9 * 0.0;
      goto LABEL_11;
    }
    p_mForward = &this->mForward;
    if ( this->mActiveSimObject.m_pPointer )
    {
      this->mHasValidPosition = UFG::AIAwareness::Effector::UpdateSimObjectPosition(
                                  this,
                                  this->mActiveSimObject.m_pPointer,
                                  &this->mActivePosition,
                                  &this->mForward);
      goto LABEL_12;
    }
  }
  this->mHasValidPosition = 0;
  y = forward->y;
  z = forward->z;
  p_mForward->x = forward->x;
  p_mForward->y = y;
LABEL_11:
  p_mForward->z = z;
LABEL_12:
  if ( !this->mHasValidPosition )
  {
    v10 = p_mForward->y;
    v11 = p_mForward->z;
    this->mActivePosition.x = p_mForward->x;
    v12 = this->mActivePosition.x * 10.0;
    v13 = v10 * 10.0;
    v14 = v11 * 10.0;
    this->mActivePosition.x = v12;
    this->mActivePosition.y = v13;
    this->mActivePosition.z = v14;
    v15 = v13 + this->mMyPosition.y;
    v16 = v14 + this->mMyPosition.z;
    this->mActivePosition.x = v12 + this->mMyPosition.x;
    this->mActivePosition.y = v15;
    this->mActivePosition.z = v16;
  }
}

// File Line: 208
// RVA: 0x39B600
void __fastcall UFG::AIAwareness::Effector::Update(
        UFG::AIAwareness::Effector *this,
        float deltaTime,
        UFG::SimObject *pOwner,
        UFG::qVector3 *forward)
{
  __int64 v5; // rdx
  UFG::AIAwareness::Profile *mpCurrentProfile; // rax
  UFG::qNode<UFG::qString,UFG::qString> **v7; // rdi
  float v9; // xmm2_4
  UFG::AIAwareness::KnowledgeSpace *mpKnowledgeSpace; // rax
  float v11; // xmm0_4
  bool v12; // zf
  float mTimeTotal; // eax
  float v14; // xmm4_4
  __m128 y_low; // xmm5
  float v16; // xmm6_4
  __m128 v17; // xmm3
  UFG::qVector3 generatedForward; // [rsp+20h] [rbp-28h] BYREF

  v5 = 5i64 * (int)this->mType;
  mpCurrentProfile = this->mpCurrentProfile;
  this->mpOwner = pOwner;
  v7 = &mpCurrentProfile->mName.mPrev + v5;
  UFG::AIAwareness::Effector::UpdateSimObjectPosition(this, pOwner, &this->mMyPosition, &generatedForward);
  if ( !this->mpKnowledgeSpace->mHasOverridingTarget || !UFG::AIAwareness::Effector::UpdateOverridingTarget(this) )
    this->mTimeLeft = this->mTimeLeft - deltaTime;
  v9 = 0.0;
  if ( this->mTimeLeft < 0.0 )
  {
    mpKnowledgeSpace = this->mpKnowledgeSpace;
    this->mPerformCheckoutSequence = 0;
    if ( mpKnowledgeSpace->mNumPositionCandidates && UFG::AIAwareness::Effector::GenerateNewTarget(this, forward) )
    {
      this->mState = EFFECTORSTATE_TRACKING;
      v11 = UFG::qRandom(*((float *)v7 + 14) - *((float *)v7 + 13), (unsigned int *)&UFG::qDefaultSeed);
      v12 = this->mActiveType == CANDIDATETYPE_SIMOBJECT;
      this->mTimeTotal = v11 + *((float *)v7 + 13);
      if ( v12
        && (float)((float)((float)(this->mActivePosition.y - this->mMyPosition.y)
                         * (float)(this->mActivePosition.y - this->mMyPosition.y))
                 + (float)((float)(this->mActivePosition.x - this->mMyPosition.x)
                         * (float)(this->mActivePosition.x - this->mMyPosition.x))) < 9.0 )
      {
        mTimeTotal = this->mTimeTotal;
        this->mPerformCheckoutSequence = 1;
        this->mTimeLeft = mTimeTotal;
        goto LABEL_16;
      }
    }
    else
    {
      this->mState = EFFECTORSTATE_WAIT;
      this->mTimeTotal = 0.0;
    }
    this->mTimeLeft = this->mTimeTotal;
    goto LABEL_16;
  }
  y_low = (__m128)LODWORD(this->mActivePosition.y);
  v14 = this->mActivePosition.x - this->mMyPosition.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->mMyPosition.y;
  v16 = this->mActivePosition.z - this->mMyPosition.z;
  v17 = y_low;
  v17.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v14 * v14)) + (float)(v16 * v16);
  if ( v17.m128_f32[0] != 0.0 )
    v9 = 1.0 / _mm_sqrt_ps(v17).m128_f32[0];
  generatedForward.x = v14 * v9;
  generatedForward.y = y_low.m128_f32[0] * v9;
  generatedForward.z = v16 * v9;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::qHeadingDifference2D(forward, &generatedForward)) & _xmm) > (float)((float)(*((float *)v7 + 20) * 3.1415927) * 0.0055555557) )
  {
    this->mState = EFFECTORSTATE_WAIT;
    *(_QWORD *)&this->mTimeTotal = 0i64;
  }
LABEL_16:
  UFG::AIAwareness::Effector::UpdateActivePosition(this, forward);
  UFG::AIAwareness::Effector::UpdateScanLogic(this, (UFG::AIAwareness::SubProfileAI *)((char *)v7 + 44), forward);
}

// File Line: 298
// RVA: 0x39C400
void __fastcall UFG::AIAwareness::Effector::UpdateWithSameTarget(
        UFG::AIAwareness::Effector *this,
        UFG::AIAwareness::Effector *targetSource,
        float deltaTime,
        UFG::SimObjectCVBase *pOwner,
        UFG::qVector3 *forward)
{
  __int64 mType; // rax
  UFG::qString *v7; // rsi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mActiveSimObject; // rdx
  UFG::SimObject *m_pPointer; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qVector3 generatedForward; // [rsp+20h] [rbp-18h] BYREF

  mType = this->mType;
  this->mpOwner = pOwner;
  v7 = &this->mpCurrentProfile->mName + mType;
  UFG::AIAwareness::Effector::UpdateSimObjectPosition(this, pOwner, &this->mMyPosition, &generatedForward);
  p_mActiveSimObject = &this->mActiveSimObject;
  this->mActiveType = targetSource->mActiveType;
  m_pPointer = targetSource->mActiveSimObject.m_pPointer;
  if ( this->mActiveSimObject.m_pPointer )
  {
    mPrev = p_mActiveSimObject->mPrev;
    mNext = this->mActiveSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mActiveSimObject->mPrev = p_mActiveSimObject;
    this->mActiveSimObject.mNext = &this->mActiveSimObject;
  }
  this->mActiveSimObject.m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v13 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v13->mNext = p_mActiveSimObject;
    p_mActiveSimObject->mPrev = v13;
    this->mActiveSimObject.mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mActiveSimObject;
  }
  y = targetSource->mActivePosition.y;
  z = targetSource->mActivePosition.z;
  this->mActivePosition.x = targetSource->mActivePosition.x;
  this->mActivePosition.y = y;
  this->mActivePosition.z = z;
  UFG::AIAwareness::Effector::UpdateActivePosition(this, forward);
  UFG::AIAwareness::Effector::UpdateScanLogic(
    this,
    (UFG::AIAwareness::SubProfileAI *)((char *)&v7[1].mPrev + 4),
    forward);
}

// File Line: 333
// RVA: 0x39B020
__int64 __fastcall UFG::AIAwareness::Effector::ScorePositionTargets(
        UFG::AIAwareness::Effector *this,
        UFG::AIAwareness::Effector::ScoreIndex *pScoreIndexes,
        UFG::qVector3 *forward)
{
  unsigned int v3; // r12d
  UFG::AIAwareness::KnowledgeSpace *mpKnowledgeSpace; // rcx
  int v8; // esi
  __int64 i; // rdi
  UFG::AIAwareness::Profile *mpCurrentProfile; // r14
  __int64 mType; // rbp
  UFG::AIAwareness::KnowledgeSpace *v12; // rax
  float v13; // xmm2_4
  float v14; // xmm3_4
  __m128 z_low; // xmm4
  float v16; // xmm6_4
  __m128 v17; // xmm1
  float v18; // xmm1_4
  float v19; // xmm2_4
  float mPersonalSpaceScoreBonus; // xmm2_4
  float v21; // xmm1_4
  UFG::AIAwareness::KnowledgeSpace *v22; // rax
  __int64 mPriority; // rcx
  UFG::qVector3 v2; // [rsp+20h] [rbp-C8h] BYREF
  int v26[4]; // [rsp+30h] [rbp-B8h]
  UFG::qVector3 generatedForward; // [rsp+40h] [rbp-A8h] BYREF
  float v28; // [rsp+F0h] [rbp+8h]

  v3 = 0;
  mpKnowledgeSpace = this->mpKnowledgeSpace;
  v8 = 0;
  if ( mpKnowledgeSpace->mNumPositionCandidates > 0 )
  {
    for ( i = 0i64; ; ++i )
    {
      mpCurrentProfile = this->mpCurrentProfile;
      mType = this->mType;
      if ( mpKnowledgeSpace->mPositionCandidates[i].mType != CANDIDATETYPE_SIMOBJECT
        || UFG::AIAwareness::Effector::UpdateSimObjectPosition(
             this,
             mpKnowledgeSpace->mPositionCandidates[i].mSimObject.m_pPointer,
             &mpKnowledgeSpace->mPositionCandidates[v8].mPosition,
             &generatedForward) )
      {
        break;
      }
LABEL_18:
      mpKnowledgeSpace = this->mpKnowledgeSpace;
      if ( ++v8 >= mpKnowledgeSpace->mNumPositionCandidates )
        return v3;
    }
    v12 = this->mpKnowledgeSpace;
    z_low = (__m128)LODWORD(v12->mPositionCandidates[i].mPosition.z);
    v13 = v12->mPositionCandidates[i].mPosition.x - this->mMyPosition.x;
    v14 = v12->mPositionCandidates[i].mPosition.y - this->mMyPosition.y;
    z_low.m128_f32[0] = z_low.m128_f32[0] - this->mMyPosition.z;
    v17 = z_low;
    v16 = (float)(v14 * v14) + (float)(v13 * v13);
    v17.m128_f32[0] = (float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + v16;
    if ( v17.m128_f32[0] == 0.0 )
      v18 = 0.0;
    else
      v18 = 1.0 / _mm_sqrt_ps(v17).m128_f32[0];
    v2.x = v13 * v18;
    v2.y = v14 * v18;
    v2.z = z_low.m128_f32[0] * v18;
    LODWORD(v19) = COERCE_UNSIGNED_INT(UFG::qHeadingDifference2D(forward, &v2)) & _xmm;
    if ( v16 >= (float)(mpCurrentProfile->mAIProperties[mType].mPersonalSpaceDistance
                      * mpCurrentProfile->mAIProperties[mType].mPersonalSpaceDistance) )
    {
      if ( v19 < (float)((float)(mpCurrentProfile->mAIProperties[mType].mMaxAngle * 3.1415927) * 0.0055555557) )
      {
        mPersonalSpaceScoreBonus = *(float *)&FLOAT_1_0;
        goto LABEL_14;
      }
    }
    else if ( v19 < (float)((float)(mpCurrentProfile->mAIProperties[mType].mPersonalSpaceMaxAngle * 3.1415927)
                          * 0.0055555557) )
    {
      mPersonalSpaceScoreBonus = mpCurrentProfile->mAIProperties[mType].mPersonalSpaceScoreBonus;
LABEL_14:
      v21 = 1.0 - (float)(v16 / (float)(this->mMaxCharacterAwarenessDistance * this->mMaxCharacterAwarenessDistance));
      if ( v21 < 0.0 )
        v21 = 0.0;
      v22 = this->mpKnowledgeSpace;
      v26[0] = 0;
      mPriority = v22->mPositionCandidates[i].mPriority;
      v26[1] = 1077936128;
      v26[2] = 1077936128;
      v28 = (float)((float)(v21 * mPersonalSpaceScoreBonus) + *(float *)&v26[mPriority]) * 100.0;
      if ( (int)v28 > 0 )
      {
        pScoreIndexes->mIndex = v8;
        pScoreIndexes->mScore = (int)v28;
        ++v3;
        ++pScoreIndexes;
      }
      goto LABEL_18;
    }
    mPersonalSpaceScoreBonus = FLOAT_N1_0;
    goto LABEL_14;
  }
  return v3;
}

// File Line: 434
// RVA: 0x39B2D0
__int64 __fastcall UFG::AIAwareness::Effector::ScoreSpaceTargets(
        UFG::AIAwareness::Effector *this,
        UFG::AIAwareness::Effector::ScoreIndex *pScoreIndexes,
        UFG::qVector3 *forward)
{
  unsigned int v3; // ebp
  int v6; // ebx
  float *v8; // rsi
  UFG::AIAwareness::Profile *mpCurrentProfile; // r12
  __int64 mType; // r15
  float v11; // xmm2_4
  float v12; // xmm3_4
  __m128 v13; // xmm4
  float v14; // xmm6_4
  __m128 v15; // xmm1
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-B8h] BYREF
  int v21[4]; // [rsp+30h] [rbp-A8h]
  float v22; // [rsp+F8h] [rbp+20h]

  v3 = 0;
  v6 = 0;
  if ( UFG::AIAwareness::KnowledgeSpace::mNumSpaceCandidates > 0 )
  {
    v21[0] = 0;
    v21[1] = 1077936128;
    v21[2] = 1077936128;
    v8 = (float *)&unk_1423C1CD4;
    do
    {
      v13 = (__m128)*(unsigned int *)v8;
      mpCurrentProfile = this->mpCurrentProfile;
      mType = this->mType;
      v11 = *(v8 - 2) - this->mMyPosition.x;
      v12 = *(v8 - 1) - this->mMyPosition.y;
      v13.m128_f32[0] = v13.m128_f32[0] - this->mMyPosition.z;
      v15 = v13;
      v14 = (float)(v12 * v12) + (float)(v11 * v11);
      v15.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + v14;
      if ( v15.m128_f32[0] == 0.0 )
        v16 = 0.0;
      else
        v16 = 1.0 / _mm_sqrt_ps(v15).m128_f32[0];
      v2.x = v11 * v16;
      v2.y = v12 * v16;
      v2.z = v13.m128_f32[0] * v16;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::qHeadingDifference2D(forward, &v2)) & _xmm) >= (float)((float)(mpCurrentProfile->mAIProperties[mType].mMaxAngle * 3.1415927) * 0.0055555557) )
        v17 = FLOAT_N1_0;
      else
        v17 = *(float *)&FLOAT_1_0;
      v18 = 1.0 - (float)(v14 / (float)(this->mMaxSpaceAwarenessDistance * this->mMaxSpaceAwarenessDistance));
      if ( v18 < 0.0 )
        v18 = 0.0;
      v22 = (float)((float)(v18 * v17) + *(float *)&v21[*((int *)v8 - 21)]) * 25.0;
      if ( (int)v22 > 0 )
      {
        pScoreIndexes->mIndex = v6;
        pScoreIndexes->mScore = (int)v22;
        ++v3;
        ++pScoreIndexes;
      }
      ++v6;
      v8 += 25;
    }
    while ( v6 < UFG::AIAwareness::KnowledgeSpace::mNumSpaceCandidates );
  }
  return v3;
}

// File Line: 515
// RVA: 0x39A850
bool __fastcall UFG::AIAwareness::Effector::CompareScoreIndex(
        UFG::AIAwareness::Effector::ScoreIndex *a,
        UFG::AIAwareness::Effector::ScoreIndex *b)
{
  return b->mScore < a->mScore;
}

// File Line: 520
// RVA: 0x39A860
bool __fastcall UFG::AIAwareness::Effector::GenerateNewTarget(UFG::AIAwareness::Effector *this, UFG::qVector3 *forward)
{
  int v3; // esi
  int v4; // r15d
  int v5; // ebx
  int v6; // r11d
  int v7; // r9d
  __m128i v8; // xmm4
  __int64 v9; // rcx
  __m128i v10; // xmm0
  __m128i v11; // xmm2
  __m128i v12; // xmm3
  __m128i v13; // xmm3
  __m128i v14; // xmm4
  __int64 v15; // rcx
  int v16; // edx
  int v17; // r8d
  int v18; // r10d
  int v19; // r9d
  __m128i v20; // xmm4
  __int64 v21; // rcx
  __m128i v22; // xmm0
  __m128i v23; // xmm2
  __m128i v24; // xmm3
  __m128i v25; // xmm3
  __m128i v26; // xmm4
  __int64 v27; // rcx
  int v28; // edx
  int v29; // r8d
  int v30; // eax
  int v31; // edx
  __int64 v32; // rcx
  __int64 v33; // rcx
  bool result; // al
  UFG::AIAwareness::KnowledgeSpace *mpKnowledgeSpace; // rcx
  __int64 mIndex; // r8
  UFG::AIAwareness::KnowledgeSpace::CandidateType mType; // eax
  UFG::SimObject *m_pPointer; // r9
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mActiveSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::AIAwareness::KnowledgeSpace *v43; // rax
  float v44; // xmm0_4
  float z; // xmm1_4
  float x; // eax
  float v47; // xmm0_4
  __int64 v48; // rcx
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  __int128 v53; // xmm1
  UFG::qVector4 v54; // xmm3
  UFG::qVector4 v55; // xmm2
  float y; // xmm0_4
  float v57; // xmm0_4
  UFG::AIAwareness::Effector::ScoreIndex right; // [rsp+18h] [rbp-E8h] BYREF
  UFG::AIAwareness::Effector::ScoreIndex dest[100]; // [rsp+20h] [rbp-E0h] BYREF
  UFG::AIAwareness::Effector::ScoreIndex pScoreIndexes; // [rsp+340h] [rbp+240h] BYREF
  int v61[997]; // [rsp+34Ch] [rbp+24Ch]

  UFG::qMemSet(dest, 0, 0x320u);
  v3 = UFG::AIAwareness::Effector::ScorePositionTargets(this, dest, &this->mForward);
  UFG::qQuickSortImpl<UFG::MapFloatSortUtil,bool (*)(UFG::MapFloatSortUtil const &,UFG::MapFloatSortUtil const &)>(
    (UFG::qPropertySet **)dest,
    &right + v3,
    (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::AIAwareness::Effector::CompareScoreIndex);
  if ( v3 >= 10 )
    v3 = 10;
  UFG::qMemSet(&pScoreIndexes, 0, 0xFA0u);
  v4 = UFG::AIAwareness::Effector::ScoreSpaceTargets(this, &pScoreIndexes, &this->mForward);
  UFG::qQuickSortImpl<UFG::MapFloatSortUtil,bool (*)(UFG::MapFloatSortUtil const &,UFG::MapFloatSortUtil const &)>(
    (UFG::qPropertySet **)&pScoreIndexes,
    &dest[v4 + 99],
    (bool (__fastcall *)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))UFG::AIAwareness::Effector::CompareScoreIndex);
  if ( v4 >= 10 )
    v4 = 10;
  if ( !(v4 + v3) )
    return 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  if ( v3 >= 4 )
  {
    v8 = 0i64;
    v9 = 0i64;
    do
    {
      v10 = _mm_cvtsi32_si128(dest[v9 + 2].mScore);
      v7 += 4;
      v11 = _mm_unpacklo_epi32(_mm_cvtsi32_si128(dest[v9 + 1].mScore), _mm_cvtsi32_si128(dest[v9 + 3].mScore));
      v12 = _mm_cvtsi32_si128(dest[v9].mScore);
      v9 += 4i64;
      v13 = _mm_add_epi32(_mm_unpacklo_epi32(_mm_unpacklo_epi32(v12, v10), v11), v8);
      v8 = v13;
    }
    while ( v9 < (int)(v3 - (v3 & 0x80000003)) );
    v14 = _mm_add_epi32(v13, _mm_srli_si128(v13, 8));
    v6 = _mm_cvtsi128_si32(_mm_add_epi32(v14, _mm_srli_si128(v14, 4)));
  }
  v15 = v7;
  v16 = 0;
  v17 = 0;
  if ( v7 < (__int64)v3 )
  {
    if ( v3 - (__int64)v7 >= 2 )
    {
      do
      {
        v16 += dest[v15].mScore;
        v17 += dest[v15 + 1].mScore;
        v15 += 2i64;
      }
      while ( v15 < v3 - 1i64 );
    }
    if ( v15 < v3 )
      v6 += dest[v15].mScore;
    v6 += v17 + v16;
  }
  v18 = 0;
  v19 = 0;
  if ( v4 >= 4 )
  {
    v20 = 0i64;
    v21 = 0i64;
    do
    {
      v22 = _mm_cvtsi32_si128(v61[2 * v21 + 2]);
      v19 += 4;
      v23 = _mm_unpacklo_epi32(_mm_cvtsi32_si128(v61[2 * v21]), _mm_cvtsi32_si128(v61[2 * v21 + 4]));
      v24 = _mm_cvtsi32_si128(*(&pScoreIndexes.mScore + 2 * v21));
      v21 += 4i64;
      v25 = _mm_add_epi32(_mm_unpacklo_epi32(_mm_unpacklo_epi32(v24, v22), v23), v20);
      v20 = v25;
    }
    while ( v21 < (int)(v4 - (v4 & 0x80000003)) );
    v26 = _mm_add_epi32(v25, _mm_srli_si128(v25, 8));
    v18 = _mm_cvtsi128_si32(_mm_add_epi32(v26, _mm_srli_si128(v26, 4)));
  }
  v27 = v19;
  v28 = 0;
  v29 = 0;
  if ( v19 < (__int64)v4 )
  {
    if ( v4 - (__int64)v19 >= 2 )
    {
      do
      {
        v28 += *(&pScoreIndexes.mScore + 2 * v27);
        v29 += v61[2 * v27];
        v27 += 2i64;
      }
      while ( v27 < v4 - 1i64 );
    }
    if ( v27 < v4 )
      v18 += *(&pScoreIndexes.mScore + 2 * v27);
    v18 += v29 + v28;
  }
  v30 = UFG::qRandom(v18 + v6 - 1, (unsigned int *)&UFG::qDefaultSeed);
  v31 = 0;
  v32 = 0i64;
  if ( v3 <= 0i64 )
  {
LABEL_29:
    v33 = 0i64;
    if ( v4 > 0 )
    {
      while ( 1 )
      {
        v30 -= *(&pScoreIndexes.mScore + 2 * v33);
        if ( v30 <= 0 )
          break;
        ++v33;
        ++v5;
        if ( v33 >= v4 )
          return 0;
      }
      v48 = 100i64 * *(&pScoreIndexes.mIndex + 2 * v5);
      this->mActiveType = *(_DWORD *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 92);
      this->mActiveSpace.mPriority = *(_DWORD *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.vfptr + v48);
      v49 = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.m_memSizeAndFlags + v48);
      v50 = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.m_referenceCount + v48 + 2);
      this->mActiveSpace.mMinAABB.x = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.vfptr
                                               + v48
                                               + 4);
      this->mActiveSpace.mMinAABB.y = v49;
      this->mActiveSpace.mMinAABB.z = v50;
      v51 = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 20);
      v52 = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 24);
      this->mActiveSpace.mMaxAABB.x = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 16);
      this->mActiveSpace.mMaxAABB.y = v51;
      this->mActiveSpace.mMaxAABB.z = v52;
      v53 = *(__int128 *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 76);
      v54 = *(UFG::qVector4 *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 44);
      v55 = *(UFG::qVector4 *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 60);
      this->mActiveSpace.mLocalWorld.v0 = *(UFG::qVector4 *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates
                                                           + v48
                                                           + 28);
      this->mActiveSpace.mLocalWorld.v1 = v54;
      this->mActiveSpace.mLocalWorld.v2 = v55;
      this->mActiveSpace.mLocalWorld.v3 = (UFG::qVector4)v53;
      this->mActiveSpace.mType = *(_DWORD *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 92);
      this->mActiveSpace.mLockRefCount = *((_BYTE *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 96);
      this->mActiveSpace.mRefCount = *((_BYTE *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 97);
      y = this->mActiveSpace.mLocalWorld.v3.y;
      *(float *)&v53 = this->mActiveSpace.mLocalWorld.v3.z;
      this->mActivePosition.x = this->mActiveSpace.mLocalWorld.v3.x;
      this->mActivePosition.y = y;
      LODWORD(this->mActivePosition.z) = v53;
      v57 = UFG::qRandom(
              (float)(this->mActiveSpace.mMaxAABB.z + *(float *)&v53) - this->mMyPosition.z,
              (unsigned int *)&UFG::qDefaultSeed);
      result = 1;
      this->mActivePosition.z = v57 + this->mMyPosition.z;
      return result;
    }
    return 0;
  }
  while ( 1 )
  {
    v30 -= dest[v32].mScore;
    if ( v30 <= 0 )
      break;
    ++v32;
    ++v31;
    if ( v32 >= v3 )
      goto LABEL_29;
  }
  mpKnowledgeSpace = this->mpKnowledgeSpace;
  mIndex = dest[v31].mIndex;
  mType = mpKnowledgeSpace->mPositionCandidates[mIndex].mType;
  this->mActiveType = mType;
  if ( mType == CANDIDATETYPE_SIMOBJECT )
  {
    m_pPointer = mpKnowledgeSpace->mPositionCandidates[mIndex].mSimObject.m_pPointer;
    p_mActiveSimObject = &this->mActiveSimObject;
    if ( this->mActiveSimObject.m_pPointer )
    {
      mPrev = p_mActiveSimObject->mPrev;
      mNext = this->mActiveSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mActiveSimObject->mPrev = p_mActiveSimObject;
      this->mActiveSimObject.mNext = &this->mActiveSimObject;
    }
    this->mActiveSimObject.m_pPointer = m_pPointer;
    if ( m_pPointer )
    {
      v42 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v42->mNext = p_mActiveSimObject;
      p_mActiveSimObject->mPrev = v42;
      this->mActiveSimObject.mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mActiveSimObject;
    }
    v43 = this->mpKnowledgeSpace;
    v44 = v43->mPositionCandidates[mIndex].mPosition.y;
    z = v43->mPositionCandidates[mIndex].mPosition.z;
    *(float *)&v43 = v43->mPositionCandidates[mIndex].mPosition.x;
    this->mActivePosition.z = z;
    this->mActivePosition.y = v44;
    LODWORD(this->mActivePosition.x) = (_DWORD)v43;
    return 1;
  }
  else
  {
    x = mpKnowledgeSpace->mPositionCandidates[mIndex].mPosition.x;
    v47 = mpKnowledgeSpace->mPositionCandidates[mIndex].mPosition.y;
    this->mActivePosition.z = mpKnowledgeSpace->mPositionCandidates[mIndex].mPosition.z;
    this->mActivePosition.y = v47;
    this->mActivePosition.x = x;
    return 1;
  }
}

// File Line: 596
// RVA: 0x39C190
char __fastcall UFG::AIAwareness::Effector::UpdateSimObjectPosition(
        UFG::AIAwareness::Effector *this,
        UFG::SimObjectCVBase *pSimObject,
        UFG::qVector3 *generatedPosition,
        UFG::qVector3 *generatedForward)
{
  char v4; // bp
  unsigned __int16 m_Flags; // cx
  UFG::CharacterAnimationComponent *v11; // rax
  Creature *mCreature; // rbx
  int BoneID; // eax
  UFG::qVector3 *Translation; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // eax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm6_4
  float v22; // xmm8_4
  float v23; // xmm6_4
  UFG::TransformNodeComponent *v24; // rbx
  UFG::SimObject *mpOwner; // rax
  UFG::TransformNodeComponent *v26; // rbx
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  __m128 y_low; // xmm3
  __m128 v31; // xmm1
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  UFG::qVector3 result; // [rsp+20h] [rbp-58h] BYREF

  v4 = 0;
  if ( !pSimObject )
    return 0;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(pSimObject);
    if ( v11 )
    {
      mCreature = v11->mCreature;
      if ( mCreature )
      {
        if ( mCreature->mPose.mRigHandle.mData )
        {
          BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::AIAwareness::gSymHeadBone.mUID);
          if ( BoneID >= 0 )
          {
            v4 = 1;
            Translation = Creature::GetTranslation(mCreature, &result, BoneID);
            y = Translation->y;
            z = Translation->z;
            x = Translation->x;
LABEL_14:
            generatedPosition->z = z;
            generatedPosition->y = y;
            generatedPosition->x = x;
            goto LABEL_15;
          }
        }
      }
    }
  }
  else if ( (m_Flags & 0x1000) != 0 )
  {
    m_pTransformNodeComponent = pSimObject->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v19 = m_pTransformNodeComponent->mWorldTransform.v0.x * 1.2;
      v20 = m_pTransformNodeComponent->mWorldTransform.v0.y * 1.2;
      v21 = (float)(m_pTransformNodeComponent->mWorldTransform.v0.z * 1.2) + 1.8;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v4 = 1;
      v22 = v20 + m_pTransformNodeComponent->mWorldTransform.v3.y;
      v23 = v21 + m_pTransformNodeComponent->mWorldTransform.v3.z;
      generatedPosition->x = v19 + m_pTransformNodeComponent->mWorldTransform.v3.x;
      generatedPosition->y = v22;
      generatedPosition->z = v23;
LABEL_15:
      mpOwner = this->mpOwner;
      if ( mpOwner )
        v26 = mpOwner->m_pTransformNodeComponent;
      else
        v26 = 0i64;
      if ( mpOwner == pSimObject )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v26);
        v27 = v26->mWorldTransform.v0.y;
        v28 = v26->mWorldTransform.v0.z;
        generatedForward->x = v26->mWorldTransform.v0.x;
        generatedForward->y = v27;
      }
      else
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v26);
        y_low = (__m128)LODWORD(generatedPosition->y);
        v29 = generatedPosition->x - v26->mWorldTransform.v3.x;
        y_low.m128_f32[0] = y_low.m128_f32[0] - v26->mWorldTransform.v3.y;
        v31 = y_low;
        v31.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v29 * v29);
        if ( v31.m128_f32[0] == 0.0 )
          v32 = 0.0;
        else
          v32 = 1.0 / _mm_sqrt_ps(v31).m128_f32[0];
        v33 = v29 * v32;
        v34 = y_low.m128_f32[0] * v32;
        v28 = v32 * 0.0;
        generatedForward->x = v33;
        generatedForward->y = v34;
      }
      generatedForward->z = v28;
      return v4;
    }
  }
  v24 = pSimObject->m_pTransformNodeComponent;
  if ( v24 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(pSimObject->m_pTransformNodeComponent);
    x = v24->mWorldTransform.v3.x;
    v4 = 1;
    y = v24->mWorldTransform.v3.y;
    z = v24->mWorldTransform.v3.z;
    goto LABEL_14;
  }
  return v4;
}

// File Line: 676
// RVA: 0x39BB70
bool __fastcall UFG::AIAwareness::Effector::UpdateOverridingTarget(UFG::AIAwareness::Effector *this)
{
  UFG::AIAwareness::KnowledgeSpace *mpKnowledgeSpace; // rcx
  int v3; // esi
  __int64 i; // rdi
  bool result; // al
  UFG::AIAwareness::KnowledgeSpace *v6; // rcx
  UFG::AIAwareness::KnowledgeSpace::CandidateType mActiveType; // edx
  __int64 v8; // rdi
  UFG::AIAwareness::KnowledgeSpace::CandidateType mType; // r8d
  bool v10; // al
  __int64 v11; // rax
  UFG::SimObject *m_pPointer; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mActiveSimObject; // rdx
  UFG::AIAwareness::Profile *mpCurrentProfile; // rbp
  __int64 v15; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  float v19; // xmm0_4
  UFG::AIAwareness::KnowledgeSpace *v20; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qVector3 generatedForward; // [rsp+20h] [rbp-28h] BYREF

  mpKnowledgeSpace = this->mpKnowledgeSpace;
  v3 = 0;
  if ( mpKnowledgeSpace->mNumPositionCandidates <= 0 )
    return 0;
  for ( i = 0i64; ; ++i )
  {
    if ( mpKnowledgeSpace->mPositionCandidates[i].mPriority == TARGETPRIORITY_OVERRIDE )
    {
      if ( this->mActiveType == CANDIDATETYPE_SIMOBJECT )
        UFG::AIAwareness::Effector::UpdateSimObjectPosition(
          this,
          mpKnowledgeSpace->mPositionCandidates[i].mSimObject.m_pPointer,
          &mpKnowledgeSpace->mPositionCandidates[v3].mPosition,
          &generatedForward);
      if ( this->mPerformOverriding )
        break;
      mpKnowledgeSpace = this->mpKnowledgeSpace;
      if ( (float)((float)((float)((float)(mpKnowledgeSpace->mPositionCandidates[i].mPosition.y - this->mMyPosition.y)
                                 * (float)(mpKnowledgeSpace->mPositionCandidates[i].mPosition.y - this->mMyPosition.y))
                         + (float)((float)(mpKnowledgeSpace->mPositionCandidates[i].mPosition.x - this->mMyPosition.x)
                                 * (float)(mpKnowledgeSpace->mPositionCandidates[i].mPosition.x - this->mMyPosition.x)))
                 + (float)((float)(mpKnowledgeSpace->mPositionCandidates[i].mPosition.z - this->mMyPosition.z)
                         * (float)(mpKnowledgeSpace->mPositionCandidates[i].mPosition.z - this->mMyPosition.z))) < 100.0 )
        break;
    }
    if ( ++v3 >= mpKnowledgeSpace->mNumPositionCandidates )
      return 0;
  }
  v6 = this->mpKnowledgeSpace;
  mActiveType = this->mActiveType;
  v8 = v3;
  mType = v6->mPositionCandidates[v8].mType;
  if ( mActiveType != mType
    || (mActiveType != CANDIDATETYPE_SIMOBJECT
      ? (v10 = (float)((float)((float)((float)(this->mActivePosition.y - v6->mPositionCandidates[v8].mPosition.y)
                                     * (float)(this->mActivePosition.y - v6->mPositionCandidates[v8].mPosition.y))
                             + (float)((float)(this->mActivePosition.x - v6->mPositionCandidates[v8].mPosition.x)
                                     * (float)(this->mActivePosition.x - v6->mPositionCandidates[v8].mPosition.x)))
                     + (float)((float)(this->mActivePosition.z - v6->mPositionCandidates[v8].mPosition.z)
                             * (float)(this->mActivePosition.z - v6->mPositionCandidates[v8].mPosition.z))) < 1.0)
      : (v10 = v6->mPositionCandidates[v8].mSimObject.m_pPointer == this->mActiveSimObject.m_pPointer),
        !v10) )
  {
    v11 = this->mType;
    this->mActiveType = mType;
    m_pPointer = v6->mPositionCandidates[v8].mSimObject.m_pPointer;
    p_mActiveSimObject = &this->mActiveSimObject;
    mpCurrentProfile = this->mpCurrentProfile;
    v15 = v11;
    if ( this->mActiveSimObject.m_pPointer )
    {
      mPrev = p_mActiveSimObject->mPrev;
      mNext = this->mActiveSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mActiveSimObject->mPrev = p_mActiveSimObject;
      this->mActiveSimObject.mNext = &this->mActiveSimObject;
    }
    this->mActiveSimObject.m_pPointer = m_pPointer;
    if ( m_pPointer )
    {
      v18 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v18->mNext = p_mActiveSimObject;
      p_mActiveSimObject->mPrev = v18;
      this->mActiveSimObject.mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mActiveSimObject;
    }
    v19 = UFG::qRandom(
            mpCurrentProfile->mAIProperties[v15].mNewTargetTimeMax
          - mpCurrentProfile->mAIProperties[v15].mNewTargetTimeMin,
            (unsigned int *)&UFG::qDefaultSeed)
        + mpCurrentProfile->mAIProperties[v15].mNewTargetTimeMin;
    this->mState = EFFECTORSTATE_TRACKING;
    *(_WORD *)&this->mPerformCheckoutSequence = 256;
    this->mTimeTotal = v19;
    this->mTimeLeft = this->mTimeTotal;
  }
  v20 = this->mpKnowledgeSpace;
  y = v20->mPositionCandidates[v8].mPosition.y;
  z = v20->mPositionCandidates[v8].mPosition.z;
  this->mActivePosition.x = v20->mPositionCandidates[v8].mPosition.x;
  result = 1;
  this->mActivePosition.y = y;
  this->mActivePosition.z = z;
  return result;
}

