// File Line: 24
// RVA: 0x14B9530
__int64 UFG::AIAwareness::_dynamic_initializer_for__gSymHeadBone__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Head", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::AIAwareness::gSymHeadBone, v0);
  return atexit(UFG::AIAwareness::_dynamic_atexit_destructor_for__gSymHeadBone__);
}

// File Line: 77
// RVA: 0x39BD90
void __fastcall UFG::AIAwareness::Effector::UpdateScanLogic(UFG::AIAwareness::Effector *this, UFG::AIAwareness::SubProfileAI *pAIProperties, UFG::qVector3 *forward)
{
  UFG::AIAwareness::SubProfileAI *v3; // rbx
  UFG::AIAwareness::Effector *v4; // rdi
  float v5; // xmm0_4
  float v6; // xmm8_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm8_4
  float v10; // xmm0_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-68h]
  UFG::qVector3 dest; // [rsp+30h] [rbp-58h]
  UFG::qVector3 source; // [rsp+40h] [rbp-48h]

  v3 = pAIProperties;
  v4 = this;
  if ( this->mType == EFFECTORTYPE_HEAD )
  {
    v5 = this->mTimeTotal;
    v6 = 0.0;
    v7 = (float)(v5 - 0.5) - 0.5;
    if ( this->mPerformCheckoutSequence )
    {
      if ( v7 > 0.0 )
      {
        v8 = (float)(v5 - this->mTimeLeft) - 0.5;
        if ( v8 > 0.0 && v8 < v7 )
          v6 = (float)((float)(sinf((float)(v8 / v7) * 3.1415927) * -20.0) * 3.1415927) * 0.0055555557;
      }
    }
    v9 = v6 + (float)((float)(v3->mHeightOffsetAngle * 3.1415927) * 0.0055555557);
    v10 = v4->mActivePosition.x;
    v2.z = v4->mActivePosition.z - v4->mMyPosition.z;
    v2.x = v10 - v4->mMyPosition.x;
    v2.y = v4->mActivePosition.y - v4->mMyPosition.y;
    v11 = UFG::qHeadingDifference2D(&UFG::qVector3::msAxisX, &v2);
    UFG::qRotateVectorZ(&dest, &v2, v11);
    v12 = sinf(v9);
    v13 = cosf(v9);
    source.y = dest.y;
    source.z = (float)(dest.x * v12) + (float)(dest.z * v13);
    source.x = (float)(dest.x * v13) - (float)(dest.z * v12);
    UFG::qRotateVectorZ(&v4->mActivePosition, &source, COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]));
    v14 = v4->mMyPosition.z + v4->mActivePosition.z;
    v15 = v4->mActivePosition.x + v4->mMyPosition.x;
    v4->mActivePosition.y = v4->mActivePosition.y + v4->mMyPosition.y;
    v4->mActivePosition.z = v14;
    v4->mActivePosition.x = v15;
  }
}

// File Line: 150
// RVA: 0x39B940
void __fastcall UFG::AIAwareness::Effector::UpdateActivePosition(UFG::AIAwareness::Effector *this, UFG::qVector3 *forward)
{
  UFG::AIAwareness::Effector *v2; // rbx
  float *v3; // rdi
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4

  v2 = this;
  if ( this->mState == 1 )
  {
    v3 = &this->mForward.x;
  }
  else
  {
    if ( this->mActiveType != 1 )
    {
      this->mHasValidPosition = 1;
      v7 = (__m128)LODWORD(this->mActivePosition.y);
      v6 = this->mActivePosition.x - this->mMyPosition.x;
      v7.m128_f32[0] = v7.m128_f32[0] - this->mMyPosition.y;
      v8 = v7;
      v8.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v6 * v6);
      if ( v8.m128_f32[0] == 0.0 )
        v9 = 0.0;
      else
        v9 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v8));
      v3 = &this->mForward.x;
      *v3 = v6 * v9;
      v3[1] = v7.m128_f32[0] * v9;
      v5 = v9 * 0.0;
      goto LABEL_11;
    }
    v3 = &this->mForward.x;
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
  v4 = forward->y;
  v5 = forward->z;
  *v3 = forward->x;
  v3[1] = v4;
LABEL_11:
  v3[2] = v5;
LABEL_12:
  if ( !v2->mHasValidPosition )
  {
    v10 = v3[1];
    v11 = v3[2];
    v2->mActivePosition.x = *v3;
    v12 = v2->mActivePosition.x * 10.0;
    v13 = v10 * 10.0;
    v14 = v11 * 10.0;
    v2->mActivePosition.x = v12;
    v2->mActivePosition.y = v13;
    v2->mActivePosition.z = v14;
    v15 = v13 + v2->mMyPosition.y;
    v16 = v14 + v2->mMyPosition.z;
    v2->mActivePosition.x = v12 + v2->mMyPosition.x;
    v2->mActivePosition.y = v15;
    v2->mActivePosition.z = v16;
  }
}

// File Line: 208
// RVA: 0x39B600
void __fastcall UFG::AIAwareness::Effector::Update(UFG::AIAwareness::Effector *this, float deltaTime, UFG::SimObject *pOwner, UFG::qVector3 *forward)
{
  UFG::qVector3 *v4; // rsi
  signed __int64 v5; // rdx
  UFG::AIAwareness::Profile *v6; // rax
  signed __int64 v7; // rdi
  UFG::AIAwareness::Effector *v8; // rbx
  float v9; // xmm2_4
  UFG::AIAwareness::KnowledgeSpace *v10; // rax
  float v11; // xmm0_4
  bool v12; // zf
  float v13; // eax
  float v14; // xmm4_4
  __m128 v15; // xmm5
  float v16; // xmm6_4
  __m128 v17; // xmm3
  UFG::qVector3 generatedForward; // [rsp+20h] [rbp-28h]

  v4 = forward;
  v5 = 5i64 * (signed int)this->mType;
  v6 = this->mpCurrentProfile;
  this->mpOwner = pOwner;
  v7 = (signed __int64)v6 + 8 * v5;
  v8 = this;
  UFG::AIAwareness::Effector::UpdateSimObjectPosition(this, pOwner, &this->mMyPosition, &generatedForward);
  if ( !v8->mpKnowledgeSpace->mHasOverridingTarget || !UFG::AIAwareness::Effector::UpdateOverridingTarget(v8) )
    v8->mTimeLeft = v8->mTimeLeft - deltaTime;
  v9 = 0.0;
  if ( v8->mTimeLeft < 0.0 )
  {
    v10 = v8->mpKnowledgeSpace;
    v8->mPerformCheckoutSequence = 0;
    if ( v10->mNumPositionCandidates && UFG::AIAwareness::Effector::GenerateNewTarget(v8, v4) )
    {
      v8->mState = 0;
      v11 = UFG::qRandom(*(float *)(v7 + 56) - *(float *)(v7 + 52), &UFG::qDefaultSeed);
      v12 = v8->mActiveType == 1;
      v8->mTimeTotal = v11 + *(float *)(v7 + 52);
      if ( v12
        && (float)((float)((float)(v8->mActivePosition.y - v8->mMyPosition.y)
                         * (float)(v8->mActivePosition.y - v8->mMyPosition.y))
                 + (float)((float)(v8->mActivePosition.x - v8->mMyPosition.x)
                         * (float)(v8->mActivePosition.x - v8->mMyPosition.x))) < 9.0 )
      {
        v13 = v8->mTimeTotal;
        v8->mPerformCheckoutSequence = 1;
        v8->mTimeLeft = v13;
        goto LABEL_16;
      }
    }
    else
    {
      v8->mState = 1;
      v8->mTimeTotal = 0.0;
    }
    v8->mTimeLeft = v8->mTimeTotal;
    goto LABEL_16;
  }
  v15 = (__m128)LODWORD(v8->mActivePosition.y);
  v14 = v8->mActivePosition.x - v8->mMyPosition.x;
  v15.m128_f32[0] = v15.m128_f32[0] - v8->mMyPosition.y;
  v16 = v8->mActivePosition.z - v8->mMyPosition.z;
  v17 = v15;
  v17.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14)) + (float)(v16 * v16);
  if ( v17.m128_f32[0] != 0.0 )
    v9 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v17));
  generatedForward.x = v14 * v9;
  generatedForward.y = v15.m128_f32[0] * v9;
  generatedForward.z = v16 * v9;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::qHeadingDifference2D(v4, &generatedForward)) & _xmm) > (float)((float)(*(float *)(v7 + 80) * 3.1415927) * 0.0055555557) )
  {
    v8->mState = 1;
    *(_QWORD *)&v8->mTimeTotal = 0i64;
  }
LABEL_16:
  UFG::AIAwareness::Effector::UpdateActivePosition(v8, v4);
  UFG::AIAwareness::Effector::UpdateScanLogic(v8, (UFG::AIAwareness::SubProfileAI *)(v7 + 44), v4);
}

// File Line: 298
// RVA: 0x39C400
void __fastcall UFG::AIAwareness::Effector::UpdateWithSameTarget(UFG::AIAwareness::Effector *this, UFG::AIAwareness::Effector *targetSource, float deltaTime, UFG::SimObject *pOwner, UFG::qVector3 *forward)
{
  __int64 v5; // rax
  UFG::AIAwareness::Effector *v6; // rbx
  UFG::qString *v7; // rsi
  UFG::AIAwareness::Effector *v8; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // rdx
  UFG::SimObject *v10; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  float v14; // xmm0_4
  float v15; // xmm1_4
  UFG::qVector3 generatedForward; // [rsp+20h] [rbp-18h]

  v5 = this->mType;
  this->mpOwner = pOwner;
  v6 = targetSource;
  v7 = &this->mpCurrentProfile->mName + v5;
  v8 = this;
  UFG::AIAwareness::Effector::UpdateSimObjectPosition(this, pOwner, &this->mMyPosition, &generatedForward);
  v9 = &v8->mActiveSimObject;
  v8->mActiveType = v6->mActiveType;
  v10 = v6->mActiveSimObject.m_pPointer;
  if ( v8->mActiveSimObject.m_pPointer )
  {
    v11 = v9->mPrev;
    v12 = v8->mActiveSimObject.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v8->mActiveSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mActiveSimObject.mPrev;
  }
  v8->mActiveSimObject.m_pPointer = v10;
  if ( v10 )
  {
    v13 = v10->m_SafePointerList.mNode.mPrev;
    v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v13;
    v8->mActiveSimObject.mNext = &v10->m_SafePointerList.mNode;
    v10->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  v14 = v6->mActivePosition.y;
  v15 = v6->mActivePosition.z;
  v8->mActivePosition.x = v6->mActivePosition.x;
  v8->mActivePosition.y = v14;
  v8->mActivePosition.z = v15;
  UFG::AIAwareness::Effector::UpdateActivePosition(v8, forward);
  UFG::AIAwareness::Effector::UpdateScanLogic(v8, (UFG::AIAwareness::SubProfileAI *)((char *)&v7[1].mPrev + 4), forward);
}

// File Line: 333
// RVA: 0x39B020
__int64 __fastcall UFG::AIAwareness::Effector::ScorePositionTargets(UFG::AIAwareness::Effector *this, UFG::AIAwareness::Effector::ScoreIndex *pScoreIndexes, UFG::qVector3 *forward)
{
  unsigned int v3; // er12
  UFG::AIAwareness::Effector *v4; // rbx
  UFG::AIAwareness::KnowledgeSpace *v5; // rcx
  UFG::qVector3 *v6; // r13
  UFG::AIAwareness::Effector::ScoreIndex *v7; // r15
  int v8; // esi
  __int64 v9; // rdi
  UFG::AIAwareness::Profile *v10; // r14
  signed __int64 v11; // rbp
  UFG::AIAwareness::KnowledgeSpace *v12; // rax
  float v13; // xmm2_4
  float v14; // xmm3_4
  __m128 v15; // xmm4
  float v16; // xmm6_4
  __m128 v17; // xmm1
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  UFG::AIAwareness::KnowledgeSpace *v22; // rax
  __int64 v23; // rcx
  UFG::qVector3 v2; // [rsp+20h] [rbp-C8h]
  int v26; // [rsp+30h] [rbp-B8h]
  int v27; // [rsp+34h] [rbp-B4h]
  int v28; // [rsp+38h] [rbp-B0h]
  UFG::qVector3 generatedForward; // [rsp+40h] [rbp-A8h]
  float v30; // [rsp+F0h] [rbp+8h]

  v3 = 0;
  v4 = this;
  v5 = this->mpKnowledgeSpace;
  v6 = forward;
  v7 = pScoreIndexes;
  v8 = 0;
  if ( v5->mNumPositionCandidates > 0 )
  {
    v9 = 0i64;
    while ( 1 )
    {
      v10 = v4->mpCurrentProfile;
      v11 = v4->mType;
      if ( v5->mPositionCandidates[v9].mType != 1
        || UFG::AIAwareness::Effector::UpdateSimObjectPosition(
             v4,
             v5->mPositionCandidates[v9].mSimObject.m_pPointer,
             &v5->mPositionCandidates[v8].mPosition,
             &generatedForward) )
      {
        break;
      }
LABEL_18:
      v5 = v4->mpKnowledgeSpace;
      ++v8;
      ++v9;
      if ( v8 >= v5->mNumPositionCandidates )
        return v3;
    }
    v12 = v4->mpKnowledgeSpace;
    v15 = (__m128)LODWORD(v12->mPositionCandidates[v9].mPosition.z);
    v13 = v12->mPositionCandidates[v9].mPosition.x - v4->mMyPosition.x;
    v14 = v12->mPositionCandidates[v9].mPosition.y - v4->mMyPosition.y;
    v15.m128_f32[0] = v15.m128_f32[0] - v4->mMyPosition.z;
    v17 = v15;
    v16 = (float)(v14 * v14) + (float)(v13 * v13);
    v17.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + v16;
    if ( v17.m128_f32[0] == 0.0 )
      v18 = 0.0;
    else
      v18 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v17));
    v2.x = v13 * v18;
    v2.y = v14 * v18;
    v2.z = v15.m128_f32[0] * v18;
    LODWORD(v19) = COERCE_UNSIGNED_INT(UFG::qHeadingDifference2D(v6, &v2)) & _xmm;
    if ( v16 >= (float)(v10->mAIProperties[v11].mPersonalSpaceDistance * v10->mAIProperties[v11].mPersonalSpaceDistance) )
    {
      if ( v19 < (float)((float)(v10->mAIProperties[v11].mMaxAngle * 3.1415927) * 0.0055555557) )
      {
        v20 = *(float *)&FLOAT_1_0;
        goto LABEL_14;
      }
    }
    else if ( v19 < (float)((float)(v10->mAIProperties[v11].mPersonalSpaceMaxAngle * 3.1415927) * 0.0055555557) )
    {
      v20 = v10->mAIProperties[v11].mPersonalSpaceScoreBonus;
LABEL_14:
      v21 = 1.0 - (float)(v16 / (float)(v4->mMaxCharacterAwarenessDistance * v4->mMaxCharacterAwarenessDistance));
      if ( v21 < 0.0 )
        v21 = 0.0;
      v22 = v4->mpKnowledgeSpace;
      v26 = 0;
      v23 = v22->mPositionCandidates[v9].mPriority;
      v27 = 1077936128;
      v28 = 1077936128;
      v30 = (float)((float)(v21 * v20) + *((float *)&v26 + v23)) * 100.0;
      if ( (signed int)v30 > 0 )
      {
        v7->mIndex = v8;
        v7->mScore = (signed int)v30;
        ++v3;
        ++v7;
      }
      goto LABEL_18;
    }
    v20 = FLOAT_N1_0;
    goto LABEL_14;
  }
  return v3;
}

// File Line: 434
// RVA: 0x39B2D0
__int64 __fastcall UFG::AIAwareness::Effector::ScoreSpaceTargets(UFG::AIAwareness::Effector *this, UFG::AIAwareness::Effector::ScoreIndex *pScoreIndexes, UFG::qVector3 *forward)
{
  unsigned int v3; // ebp
  UFG::qVector3 *v4; // r13
  UFG::AIAwareness::Effector::ScoreIndex *v5; // rdi
  int v6; // ebx
  UFG::AIAwareness::Effector *v7; // r14
  float *v8; // rsi
  UFG::AIAwareness::Profile *v9; // r12
  signed __int64 v10; // r15
  float v11; // xmm2_4
  float v12; // xmm3_4
  __m128 v13; // xmm4
  float v14; // xmm6_4
  __m128 v15; // xmm1
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-B8h]
  int v21; // [rsp+30h] [rbp-A8h]
  int v22; // [rsp+34h] [rbp-A4h]
  int v23; // [rsp+38h] [rbp-A0h]
  float v24; // [rsp+F8h] [rbp+20h]

  v3 = 0;
  v4 = forward;
  v5 = pScoreIndexes;
  v6 = 0;
  v7 = this;
  if ( UFG::AIAwareness::KnowledgeSpace::mNumSpaceCandidates > 0 )
  {
    v21 = 0;
    v22 = 1077936128;
    v23 = 1077936128;
    v8 = (float *)&unk_1423C1CD4;
    do
    {
      v13 = (__m128)*(unsigned int *)v8;
      v9 = v7->mpCurrentProfile;
      v10 = v7->mType;
      v11 = *(v8 - 2) - v7->mMyPosition.x;
      v12 = *(v8 - 1) - v7->mMyPosition.y;
      v13.m128_f32[0] = v13.m128_f32[0] - v7->mMyPosition.z;
      v15 = v13;
      v14 = (float)(v12 * v12) + (float)(v11 * v11);
      v15.m128_f32[0] = (float)(v13.m128_f32[0] * v13.m128_f32[0]) + v14;
      if ( v15.m128_f32[0] == 0.0 )
        v16 = 0.0;
      else
        v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v15));
      v2.x = v11 * v16;
      v2.y = v12 * v16;
      v2.z = v13.m128_f32[0] * v16;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::qHeadingDifference2D(v4, &v2)) & _xmm) >= (float)((float)(v9->mAIProperties[v10].mMaxAngle * 3.1415927)
                                                                                                 * 0.0055555557) )
        v17 = FLOAT_N1_0;
      else
        v17 = *(float *)&FLOAT_1_0;
      v18 = 1.0 - (float)(v14 / (float)(v7->mMaxSpaceAwarenessDistance * v7->mMaxSpaceAwarenessDistance));
      if ( v18 < 0.0 )
        v18 = 0.0;
      v24 = (float)((float)(v18 * v17) + *((float *)&v21 + *((signed int *)v8 - 21))) * 25.0;
      if ( (signed int)v24 > 0 )
      {
        v5->mIndex = v6;
        v5->mScore = (signed int)v24;
        ++v3;
        ++v5;
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
bool __fastcall UFG::AIAwareness::Effector::CompareScoreIndex(UFG::AIAwareness::Effector::ScoreIndex *a, UFG::AIAwareness::Effector::ScoreIndex *b)
{
  return b->mScore < a->mScore;
}

// File Line: 520
// RVA: 0x39A860
char __fastcall UFG::AIAwareness::Effector::GenerateNewTarget(UFG::AIAwareness::Effector *this, UFG::qVector3 *forward)
{
  UFG::AIAwareness::Effector *v2; // rdi
  int v3; // esi
  int v4; // er15
  int v5; // ebx
  int v6; // er11
  int v7; // er9
  __m128i v8; // xmm4
  signed __int64 v9; // rcx
  __m128i v10; // xmm0
  __m128i v11; // xmm2
  __m128i v12; // xmm3
  __m128i v13; // xmm3
  __m128i v14; // xmm4
  signed __int64 v15; // rcx
  int v16; // edx
  int v17; // er8
  int v18; // er10
  int v19; // er9
  __m128i v20; // xmm4
  signed __int64 v21; // rcx
  __m128i v22; // xmm0
  __m128i v23; // xmm2
  __m128i v24; // xmm3
  __m128i v25; // xmm3
  __m128i v26; // xmm4
  signed __int64 v27; // rcx
  int v28; // edx
  int v29; // er8
  int v30; // eax
  int v31; // edx
  signed __int64 v32; // rcx
  signed __int64 v33; // rcx
  char result; // al
  UFG::AIAwareness::KnowledgeSpace *v35; // rcx
  signed __int64 v36; // r8
  UFG::AIAwareness::KnowledgeSpace::CandidateType v37; // eax
  UFG::SimObject *v38; // r9
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v39; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v40; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::AIAwareness::KnowledgeSpace *v43; // rax
  float v44; // xmm0_4
  float v45; // xmm1_4
  float v46; // eax
  float v47; // xmm0_4
  signed __int64 v48; // rcx
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  __int128 v53; // xmm1
  UFG::qVector4 v54; // xmm3
  UFG::qVector4 v55; // xmm2
  float v56; // xmm0_4
  float v57; // xmm0_4
  UFG::AIAwareness::Effector::ScoreIndex right; // [rsp+18h] [rbp-E8h]
  int dest; // [rsp+20h] [rbp-E0h]
  int v60[2]; // [rsp+24h] [rbp-DCh]
  int v61[2]; // [rsp+2Ch] [rbp-D4h]
  int v62[2]; // [rsp+34h] [rbp-CCh]
  int v63[191]; // [rsp+3Ch] [rbp-C4h]
  UFG::AIAwareness::Effector::ScoreIndex v64; // [rsp+338h] [rbp+238h]
  UFG::AIAwareness::Effector::ScoreIndex pScoreIndexes; // [rsp+340h] [rbp+240h]
  int v66[2]; // [rsp+34Ch] [rbp+24Ch]
  int v67[2]; // [rsp+354h] [rbp+254h]
  int v68[993]; // [rsp+35Ch] [rbp+25Ch]

  v2 = this;
  UFG::qMemSet(&dest, 0, 0x320u);
  v3 = UFG::AIAwareness::Effector::ScorePositionTargets(
         v2,
         (UFG::AIAwareness::Effector::ScoreIndex *)&dest,
         &v2->mForward);
  UFG::qQuickSortImpl<UFG::MapFloatSortUtil,bool (*)(UFG::MapFloatSortUtil const &,UFG::MapFloatSortUtil const &)>(
    (UFG::AIAwareness::Effector::ScoreIndex *)&dest,
    &right + v3,
    UFG::AIAwareness::Effector::CompareScoreIndex);
  if ( v3 >= 10 )
    v3 = 10;
  UFG::qMemSet(&pScoreIndexes, 0, 0xFA0u);
  v4 = UFG::AIAwareness::Effector::ScoreSpaceTargets(v2, &pScoreIndexes, &v2->mForward);
  UFG::qQuickSortImpl<UFG::MapFloatSortUtil,bool (*)(UFG::MapFloatSortUtil const &,UFG::MapFloatSortUtil const &)>(
    &pScoreIndexes,
    &v64 + v4,
    UFG::AIAwareness::Effector::CompareScoreIndex);
  if ( v4 >= 10 )
    v4 = 10;
  if ( !(v4 + v3) )
    return 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  if ( v3 > 0 && (unsigned int)v3 >= 4 )
  {
    v8 = 0i64;
    v9 = 0i64;
    do
    {
      v10 = _mm_cvtsi32_si128(v62[2 * v9]);
      v7 += 4;
      v11 = _mm_unpacklo_epi32(_mm_cvtsi32_si128(v61[2 * v9]), _mm_cvtsi32_si128(v63[2 * v9]));
      v12 = _mm_cvtsi32_si128(v60[2 * v9]);
      v9 += 4i64;
      v13 = _mm_add_epi32(_mm_unpacklo_epi32(_mm_unpacklo_epi32(v12, v10), v11), v8);
      v8 = v13;
    }
    while ( v9 < v3 - v3 % 4 );
    v14 = _mm_add_epi32(v13, _mm_srli_si128(v13, 8));
    v6 = _mm_cvtsi128_si32(_mm_add_epi32(v14, _mm_srli_si128(v14, 4)));
  }
  v15 = v7;
  v16 = 0;
  v17 = 0;
  if ( v7 < (signed __int64)v3 )
  {
    if ( v3 - (signed __int64)v7 >= 2 )
    {
      do
      {
        v16 += v60[2 * v15];
        v17 += v61[2 * v15];
        v15 += 2i64;
      }
      while ( v15 < v3 - 1i64 );
    }
    if ( v15 < v3 )
      v6 += v60[2 * v15];
    v6 += v17 + v16;
  }
  v18 = 0;
  v19 = 0;
  if ( v4 > 0 && (unsigned int)v4 >= 4 )
  {
    v20 = 0i64;
    v21 = 0i64;
    do
    {
      v22 = _mm_cvtsi32_si128(v67[2 * v21]);
      v19 += 4;
      v23 = _mm_unpacklo_epi32(_mm_cvtsi32_si128(v66[2 * v21]), _mm_cvtsi32_si128(v68[2 * v21]));
      v24 = _mm_cvtsi32_si128(*(&pScoreIndexes.mScore + 2 * v21));
      v21 += 4i64;
      v25 = _mm_add_epi32(_mm_unpacklo_epi32(_mm_unpacklo_epi32(v24, v22), v23), v20);
      v20 = v25;
    }
    while ( v21 < v4 - v4 % 4 );
    v26 = _mm_add_epi32(v25, _mm_srli_si128(v25, 8));
    v18 = _mm_cvtsi128_si32(_mm_add_epi32(v26, _mm_srli_si128(v26, 4)));
  }
  v27 = v19;
  v28 = 0;
  v29 = 0;
  if ( v19 < (signed __int64)v4 )
  {
    if ( v4 - (signed __int64)v19 >= 2 )
    {
      do
      {
        v28 += *(&pScoreIndexes.mScore + 2 * v27);
        v29 += v66[2 * v27];
        v27 += 2i64;
      }
      while ( v27 < v4 - 1i64 );
    }
    if ( v27 < v4 )
      v18 += *(&pScoreIndexes.mScore + 2 * v27);
    v18 += v29 + v28;
  }
  v30 = UFG::qRandom(v18 + v6 - 1, &UFG::qDefaultSeed);
  v31 = 0;
  v32 = 0i64;
  if ( v3 <= 0i64 )
  {
LABEL_31:
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
      v2->mActiveType = *(_DWORD *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 92);
      v2->mActiveSpace.mPriority = *(_DWORD *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.vfptr + v48);
      v49 = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.m_memSizeAndFlags + v48);
      v50 = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.m_referenceCount + v48 + 2);
      v2->mActiveSpace.mMinAABB.x = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates.vfptr
                                             + v48
                                             + 4);
      v2->mActiveSpace.mMinAABB.y = v49;
      v2->mActiveSpace.mMinAABB.z = v50;
      v51 = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 20);
      v52 = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 24);
      v2->mActiveSpace.mMaxAABB.x = *(float *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 16);
      v2->mActiveSpace.mMaxAABB.y = v51;
      v2->mActiveSpace.mMaxAABB.z = v52;
      v53 = *(__int128 *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 76);
      v54 = *(UFG::qVector4 *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 44);
      v55 = *(UFG::qVector4 *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 60);
      v2->mActiveSpace.mLocalWorld.v0 = *(UFG::qVector4 *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates
                                                         + v48
                                                         + 28);
      v2->mActiveSpace.mLocalWorld.v1 = v54;
      v2->mActiveSpace.mLocalWorld.v2 = v55;
      v2->mActiveSpace.mLocalWorld.v3 = (UFG::qVector4)v53;
      v2->mActiveSpace.mType = *(_DWORD *)((char *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 92);
      v2->mActiveSpace.mLockRefCount = *((_BYTE *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 96);
      v2->mActiveSpace.mRefCount = *((_BYTE *)&UFG::AIAwareness::KnowledgeSpace::mSpaceCandidates + v48 + 97);
      v56 = v2->mActiveSpace.mLocalWorld.v3.y;
      *(float *)&v53 = v2->mActiveSpace.mLocalWorld.v3.z;
      v2->mActivePosition.x = v2->mActiveSpace.mLocalWorld.v3.x;
      v2->mActivePosition.y = v56;
      LODWORD(v2->mActivePosition.z) = v53;
      v57 = UFG::qRandom((float)(v2->mActiveSpace.mMaxAABB.z + *(float *)&v53) - v2->mMyPosition.z, &UFG::qDefaultSeed);
      result = 1;
      v2->mActivePosition.z = v57 + v2->mMyPosition.z;
      return result;
    }
    return 0;
  }
  while ( 1 )
  {
    v30 -= v60[2 * v32];
    if ( v30 <= 0 )
      break;
    ++v32;
    ++v31;
    if ( v32 >= v3 )
      goto LABEL_31;
  }
  v35 = v2->mpKnowledgeSpace;
  v36 = *(&dest + 2 * v31);
  v37 = v35->mPositionCandidates[v36].mType;
  v2->mActiveType = v37;
  if ( v37 == 1 )
  {
    v38 = v35->mPositionCandidates[v36].mSimObject.m_pPointer;
    v39 = &v2->mActiveSimObject;
    if ( v2->mActiveSimObject.m_pPointer )
    {
      v40 = v39->mPrev;
      v41 = v2->mActiveSimObject.mNext;
      v40->mNext = v41;
      v41->mPrev = v40;
      v39->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v39->mPrev;
      v2->mActiveSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mActiveSimObject.mPrev;
    }
    v2->mActiveSimObject.m_pPointer = v38;
    if ( v38 )
    {
      v42 = v38->m_SafePointerList.mNode.mPrev;
      v42->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v39->mPrev;
      v39->mPrev = v42;
      v2->mActiveSimObject.mNext = &v38->m_SafePointerList.mNode;
      v38->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v39->mPrev;
    }
    v43 = v2->mpKnowledgeSpace;
    v44 = v43->mPositionCandidates[v36].mPosition.y;
    v45 = v43->mPositionCandidates[v36].mPosition.z;
    *(float *)&v43 = v43->mPositionCandidates[v36].mPosition.x;
    v2->mActivePosition.z = v45;
    v2->mActivePosition.y = v44;
    LODWORD(v2->mActivePosition.x) = (_DWORD)v43;
    result = 1;
  }
  else
  {
    v46 = v35->mPositionCandidates[v36].mPosition.x;
    v47 = v35->mPositionCandidates[v36].mPosition.y;
    v2->mActivePosition.z = v35->mPositionCandidates[v36].mPosition.z;
    v2->mActivePosition.y = v47;
    v2->mActivePosition.x = v46;
    result = 1;
  }
  return result;
}

// File Line: 596
// RVA: 0x39C190
char __fastcall UFG::AIAwareness::Effector::UpdateSimObjectPosition(UFG::AIAwareness::Effector *this, UFG::SimObject *pSimObject, UFG::qVector3 *generatedPosition, UFG::qVector3 *generatedForward)
{
  char v4; // bp
  UFG::qVector3 *v5; // r14
  UFG::qVector3 *v6; // rsi
  UFG::SimObject *v7; // rdi
  UFG::AIAwareness::Effector *v8; // r15
  unsigned __int16 v10; // cx
  UFG::CharacterAnimationComponent *v11; // rax
  Creature *v12; // rbx
  int v13; // eax
  UFG::qVector3 *v14; // rax
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // eax
  UFG::TransformNodeComponent *v18; // rbx
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm6_4
  float v22; // xmm8_4
  float v23; // xmm6_4
  UFG::TransformNodeComponent *v24; // rbx
  UFG::SimObject *v25; // rax
  UFG::TransformNodeComponent *v26; // rbx
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  UFG::qVector3 result; // [rsp+20h] [rbp-58h]

  v4 = 0;
  v5 = generatedForward;
  v6 = generatedPosition;
  v7 = pSimObject;
  v8 = this;
  if ( !pSimObject )
    return 0;
  v10 = pSimObject->m_Flags;
  if ( (v10 >> 14) & 1 )
  {
    v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)pSimObject);
    if ( v11 )
    {
      v12 = v11->mCreature;
      if ( v12 )
      {
        if ( v12->mPose.mRigHandle.mData )
        {
          v13 = Skeleton::GetBoneID(v12->mPose.mRigHandle.mUFGSkeleton, UFG::AIAwareness::gSymHeadBone.mUID);
          if ( v13 >= 0 )
          {
            v4 = 1;
            v14 = Creature::GetTranslation(v12, &result, v13);
            v15 = v14->y;
            v16 = v14->z;
            v17 = v14->x;
LABEL_14:
            v6->z = v16;
            v6->y = v15;
            v6->x = v17;
            goto LABEL_15;
          }
        }
      }
    }
  }
  else if ( (v10 >> 12) & 1 )
  {
    v18 = pSimObject->m_pTransformNodeComponent;
    if ( v18 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v18);
      v19 = v18->mWorldTransform.v0.x * 1.2;
      v20 = v18->mWorldTransform.v0.y * 1.2;
      v21 = (float)(v18->mWorldTransform.v0.z * 1.2) + 1.8;
      UFG::TransformNodeComponent::UpdateWorldTransform(v18);
      v4 = 1;
      v22 = v20 + v18->mWorldTransform.v3.y;
      v23 = v21 + v18->mWorldTransform.v3.z;
      v6->x = v19 + v18->mWorldTransform.v3.x;
      v6->y = v22;
      v6->z = v23;
LABEL_15:
      v25 = v8->mpOwner;
      if ( v25 )
        v26 = v25->m_pTransformNodeComponent;
      else
        v26 = 0i64;
      if ( v25 == v7 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v26);
        v27 = v26->mWorldTransform.v0.y;
        v28 = v26->mWorldTransform.v0.z;
        v5->x = v26->mWorldTransform.v0.x;
        v5->y = v27;
      }
      else
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v26);
        v30 = (__m128)LODWORD(v6->y);
        v29 = v6->x - v26->mWorldTransform.v3.x;
        v30.m128_f32[0] = v30.m128_f32[0] - v26->mWorldTransform.v3.y;
        v31 = v30;
        v31.m128_f32[0] = (float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v29 * v29);
        if ( v31.m128_f32[0] == 0.0 )
          v32 = 0.0;
        else
          v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
        v33 = v29 * v32;
        v34 = v30.m128_f32[0] * v32;
        v28 = v32 * 0.0;
        v5->x = v33;
        v5->y = v34;
      }
      v5->z = v28;
      return v4;
    }
  }
  v24 = v7->m_pTransformNodeComponent;
  if ( v24 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v7->m_pTransformNodeComponent);
    v17 = v24->mWorldTransform.v3.x;
    v4 = 1;
    v15 = v24->mWorldTransform.v3.y;
    v16 = v24->mWorldTransform.v3.z;
    goto LABEL_14;
  }
  return v4;
}

// File Line: 676
// RVA: 0x39BB70
char __fastcall UFG::AIAwareness::Effector::UpdateOverridingTarget(UFG::AIAwareness::Effector *this)
{
  UFG::AIAwareness::Effector *v1; // rbx
  UFG::AIAwareness::KnowledgeSpace *v2; // rcx
  int v3; // esi
  __int64 v4; // rdi
  char result; // al
  UFG::AIAwareness::KnowledgeSpace *v6; // rcx
  UFG::AIAwareness::KnowledgeSpace::CandidateType v7; // edx
  signed __int64 v8; // rdi
  UFG::AIAwareness::KnowledgeSpace::CandidateType v9; // er8
  bool v10; // al
  signed __int64 v11; // rax
  UFG::SimObject *v12; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v13; // rdx
  UFG::AIAwareness::Profile *v14; // rbp
  signed __int64 v15; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  float v19; // xmm0_4
  UFG::AIAwareness::KnowledgeSpace *v20; // rax
  float v21; // xmm0_4
  float v22; // xmm1_4
  UFG::qVector3 generatedForward; // [rsp+20h] [rbp-28h]

  v1 = this;
  v2 = this->mpKnowledgeSpace;
  v3 = 0;
  if ( v2->mNumPositionCandidates <= 0 )
    return 0;
  v4 = 0i64;
  while ( 1 )
  {
    if ( v2->mPositionCandidates[v4].mPriority == 2 )
    {
      if ( v1->mActiveType == 1 )
        UFG::AIAwareness::Effector::UpdateSimObjectPosition(
          v1,
          v2->mPositionCandidates[v4].mSimObject.m_pPointer,
          &v2->mPositionCandidates[v3].mPosition,
          &generatedForward);
      if ( v1->mPerformOverriding )
        break;
      v2 = v1->mpKnowledgeSpace;
      if ( (float)((float)((float)((float)(v2->mPositionCandidates[v4].mPosition.y - v1->mMyPosition.y)
                                 * (float)(v2->mPositionCandidates[v4].mPosition.y - v1->mMyPosition.y))
                         + (float)((float)(v2->mPositionCandidates[v4].mPosition.x - v1->mMyPosition.x)
                                 * (float)(v2->mPositionCandidates[v4].mPosition.x - v1->mMyPosition.x)))
                 + (float)((float)(v2->mPositionCandidates[v4].mPosition.z - v1->mMyPosition.z)
                         * (float)(v2->mPositionCandidates[v4].mPosition.z - v1->mMyPosition.z))) < 100.0 )
        break;
    }
    ++v3;
    ++v4;
    if ( v3 >= v2->mNumPositionCandidates )
      return 0;
  }
  v6 = v1->mpKnowledgeSpace;
  v7 = v1->mActiveType;
  v8 = v3;
  v9 = v6->mPositionCandidates[v8].mType;
  if ( v7 != v9
    || (v7 != 1 ? (v10 = (float)((float)((float)((float)(v1->mActivePosition.y - v6->mPositionCandidates[v8].mPosition.y)
                                               * (float)(v1->mActivePosition.y - v6->mPositionCandidates[v8].mPosition.y))
                                       + (float)((float)(v1->mActivePosition.x - v6->mPositionCandidates[v8].mPosition.x)
                                               * (float)(v1->mActivePosition.x - v6->mPositionCandidates[v8].mPosition.x)))
                               + (float)((float)(v1->mActivePosition.z - v6->mPositionCandidates[v8].mPosition.z)
                                       * (float)(v1->mActivePosition.z - v6->mPositionCandidates[v8].mPosition.z))) < 1.0) : (v10 = v6->mPositionCandidates[v8].mSimObject.m_pPointer == v1->mActiveSimObject.m_pPointer),
        !v10) )
  {
    v11 = v1->mType;
    v1->mActiveType = v9;
    v12 = v6->mPositionCandidates[v8].mSimObject.m_pPointer;
    v13 = &v1->mActiveSimObject;
    v14 = v1->mpCurrentProfile;
    v15 = v11;
    if ( v1->mActiveSimObject.m_pPointer )
    {
      v16 = v13->mPrev;
      v17 = v1->mActiveSimObject.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v1->mActiveSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mActiveSimObject.mPrev;
    }
    v1->mActiveSimObject.m_pPointer = v12;
    if ( v12 )
    {
      v18 = v12->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v13->mPrev = v18;
      v1->mActiveSimObject.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    }
    v19 = UFG::qRandom(
            v14->mAIProperties[v15].mNewTargetTimeMax - v14->mAIProperties[v15].mNewTargetTimeMin,
            &UFG::qDefaultSeed)
        + v14->mAIProperties[v15].mNewTargetTimeMin;
    v1->mState = 0;
    *(_WORD *)&v1->mPerformCheckoutSequence = 256;
    v1->mTimeTotal = v19;
    v1->mTimeLeft = v1->mTimeTotal;
  }
  v20 = v1->mpKnowledgeSpace;
  v21 = v20->mPositionCandidates[v8].mPosition.y;
  v22 = v20->mPositionCandidates[v8].mPosition.z;
  v1->mActivePosition.x = v20->mPositionCandidates[v8].mPosition.x;
  result = 1;
  v1->mActivePosition.y = v21;
  v1->mActivePosition.z = v22;
  return result;
}

