// File Line: 70
// RVA: 0x3A2810
void __fastcall AttachPose(SkeletalPose *pose, UFG::qMatrix44 *fromMatrixWS, UFG::qMatrix44 *toMatrixWS)
{
  SkeletalPose *v3; // rdi
  UFG::qMatrix44 *v4; // rbx
  UFG::qMatrix44 *v5; // rax
  __m128 v6; // xmm9
  __m128 v7; // xmm8
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  float v10; // xmm1_4
  __m128 v11; // xmm5
  Render::DebugDrawContext *v12; // rax
  UFG::qVector3 t; // [rsp+20h] [rbp-D8h]
  UFG::qQuaternion v14; // [rsp+30h] [rbp-C8h]
  UFG::qQuaternion v15; // [rsp+40h] [rbp-B8h]
  UFG::qMatrix44 mat; // [rsp+50h] [rbp-A8h]
  __m128 v17; // [rsp+98h] [rbp-60h]
  __m128 v18; // [rsp+A8h] [rbp-50h]
  __m128 v19; // [rsp+B8h] [rbp-40h]
  UFG::qMatrix44 d; // [rsp+C8h] [rbp-30h]
  UFG::qMatrix44 newRoot; // [rsp+108h] [rbp+10h]
  UFG::qMatrix44 result; // [rsp+148h] [rbp+50h]

  v3 = pose;
  v4 = toMatrixWS;
  UFG::qInverseAffine((UFG::qMatrix44 *)((char *)&d + 8), fromMatrixWS);
  v5 = UFG::qMatrix44::operator*(&d, &result, v4);
  v6 = (__m128)v5->v0;
  v7 = (__m128)v5->v1;
  v8 = (__m128)v5->v2;
  v9 = (__m128)v5->v3;
  SkeletalPose::GetRootMatrix(v3, (UFG::qMatrix44 *)((char *)&mat + 56));
  mat.v0 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat.v3.z, *(__m128 *)&mat.v3.z, 0), v6),
                                  (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat.v3.z, *(__m128 *)&mat.v3.z, 85), v7)),
                              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat.v3.z, *(__m128 *)&mat.v3.z, 170), v8)),
                            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat.v3.z, *(__m128 *)&mat.v3.z, 255), v9));
  mat.v1 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v6), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v7)),
                              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v8)),
                            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), v9));
  mat.v2 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v6), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v7)),
                              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v8)),
                            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 255), v9));
  *(__m128 *)&mat.v2.z = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v6), (__m128)0i64),
                               _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v7)),
                             _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v8)),
                           _mm_mul_ps(_mm_shuffle_ps(v19, v19, 255), v9));
  UFG::qQuaternion::Set(&v14, &mat);
  v11 = (__m128)LODWORD(v14.y);
  v10 = 0.0;
  v11.m128_f32[0] = (float)((float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v14.x * v14.x))
                          + (float)(v14.z * v14.z))
                  + (float)(v14.w * v14.w);
  if ( v11.m128_f32[0] != 0.0 )
    v10 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  t = *(UFG::qVector3 *)&mat.v2.z;
  v15.x = v14.x * v10;
  v15.y = v14.y * v10;
  v15.w = v10 * v14.w;
  v15.z = v14.z * v10;
  UFG::qQuaternion::GetMatrix(&v15, &newRoot, &t);
  SkeletalPose::SetRoot(v3, &newRoot, 0);
  if ( gSkeletonDebug )
  {
    v12 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawCoord(v12, &mat, 0.5, "Attach Pos");
  }
}

// File Line: 99
// RVA: 0x3AC100
void __fastcall Attachment::OnRemove(Attachment *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::RigidBody *v3; // rax

  v1 = (UFG::SimObjectGame *)this->mAttachedSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                 (UFG::SimObject *)&v1->vfptr,
                                 UFG::RigidBodyComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
    }
    if ( v3 )
      UFG::RigidBody::SetMotionType(v3, 0x80u);
  }
}

// File Line: 115
// RVA: 0x3A7BD0
float __fastcall Attachment::GetBlendWeight(Attachment *this)
{
  float result; // xmm0_4

  result = (float)(sinf((float)(this->mBlendWeight * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  if ( result <= 0.0 )
    return 0.0;
  if ( result >= 1.0 )
    result = *(float *)&FLOAT_1_0;
  return result;
}

// File Line: 125
// RVA: 0x3B2A00
void __fastcall AttachmentCreatureToTransformNode::UpdatePose(AttachmentCreatureToTransformNode *this)
{
  UFG::SimComponent *v1; // rsi
  AttachmentCreatureToTransformNode *v2; // rbx
  UFG::SimComponent *v3; // rdi
  Creature *v4; // rdi
  UFG::qMatrix44 *v5; // rax
  __int128 v6; // xmm3
  __int128 v7; // xmm2
  __int128 v8; // xmm1
  UFG::qVector4 v9; // xmm0
  bool v10; // zf
  int v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm6_4
  int v15; // ebx
  UFG::qMatrix44 *v16; // r8
  char translationWS[24]; // [rsp+20h] [rbp-81h]
  __int128 v18; // [rsp+38h] [rbp-69h]
  __int128 v19; // [rsp+48h] [rbp-59h]
  __int128 v20; // [rsp+58h] [rbp-49h]
  UFG::qMatrix44 matrixWS; // [rsp+68h] [rbp-39h]
  UFG::qMatrix44 result; // [rsp+A8h] [rbp+7h]

  v1 = this->mTransformNodeComponentRoot.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    v3 = this->mAttachedCharacterAnimationComponent.m_pPointer;
    if ( v3 )
    {
      v4 = *(Creature **)&v3[2].m_TypeUID;
      if ( v4 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1);
        if ( v2->mAttachRelative )
        {
          v5 = UFG::qMatrix44::operator*(&v2->mRelativeAttachmentLS, &result, (UFG::qMatrix44 *)&v1[2]);
          v6 = (__int128)v5->v1;
          v7 = (__int128)v5->v2;
          v8 = (__int128)v5->v3;
          v9 = v5->v0;
        }
        else
        {
          v6 = *(_OWORD *)&v1[2].m_SafePointerList.mNode.mNext;
          v7 = *(_OWORD *)&v1[2].m_Flags;
          v8 = (__int128)v1[2].m_BoundComponentHandles;
          v9 = *(UFG::qVector4 *)&v1[2].vfptr;
        }
        v10 = v2->mPositionXYOnly == 0;
        v20 = v8;
        v19 = v7;
        v18 = v6;
        *(UFG::qVector4 *)&translationWS[8] = v9;
        if ( v10 )
        {
          v11 = DWORD2(v20);
        }
        else
        {
          SkeletalPose::GetTranslationWS(&v4->mPose, v2->attachmentJoint, (UFG::qVector3 *)translationWS);
          v11 = *(_DWORD *)&translationWS[8];
          DWORD2(v20) = *(_DWORD *)&translationWS[8];
        }
        if ( v2->mPositionOnly == 1 )
        {
          *(_DWORD *)&translationWS[8] = v11;
          *(_QWORD *)translationWS = v20;
          v12 = Attachment::GetBlendWeight((Attachment *)&v2->vfptr);
          Creature::Attach(v4, v2->attachmentJoint, (UFG::qVector3 *)translationWS, v12);
        }
        else
        {
          v13 = Attachment::GetBlendWeight((Attachment *)&v2->vfptr);
          v14 = v13;
          if ( v2->mUseRubberBand && v13 >= 0.99000001 )
            v14 = FLOAT_0_1;
          v15 = v2->attachmentJoint;
          if ( Creature::IsEndEffector(v4, v15) )
          {
            Creature::SetEndEffectorTarget(v4, v15, (UFG::qMatrix44 *)&translationWS[8]);
          }
          else
          {
            SkeletalPose::GetPositionWS(&v4->mPose, v15, &matrixWS);
            v16 = (UFG::qMatrix44 *)&translationWS[8];
            if ( v14 < 1.0 )
            {
              BlendSlerp(&result, &matrixWS, (UFG::qMatrix44 *)&translationWS[8], v14);
              v16 = &result;
            }
            AttachPose(&v4->mPose, &matrixWS, v16);
          }
          Creature::UpdateAttachmentPoses(v4);
        }
      }
    }
  }
}

// File Line: 186
// RVA: 0x3AC2D0
void __fastcall AttachmentCreatureToTransformNode::OnRemove(AttachmentCreatureToTransformNode *this)
{
  AttachmentCreatureToTransformNode *v1; // rdi
  UFG::SimComponent *v2; // rsi
  Creature *v3; // rsi
  UFG::qNode<PoseDriver,PoseDriver> *v4; // rbx
  signed __int64 v5; // rsi
  UFG::qNode<PoseDriver,PoseDriver> *i; // rbx
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::RigidBody *v9; // rax

  v1 = this;
  if ( this->mAttachedSimObject.m_pPointer )
  {
    v2 = this->mAttachedCharacterAnimationComponent.m_pPointer;
    if ( v2 )
    {
      v3 = *(Creature **)&v2[2].m_TypeUID;
      if ( v3 )
      {
        v3->mIsAttached = 0;
        if ( Creature::IsEndEffector(v3, this->attachedJoint) )
        {
          v4 = v3->mPoseDrivers.mNode.mNext;
          v5 = (signed __int64)&v3->m_SafePointerList;
          for ( i = v4 - 1; i != (UFG::qNode<PoseDriver,PoseDriver> *)v5; i = i[1].mNext - 1 )
          {
            if ( ((unsigned int (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *))i->mPrev[7].mPrev)(i) == v1->attachedJoint )
              ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, _QWORD))i->mPrev[5].mNext)(i, 0i64);
          }
        }
        else
        {
          v7 = (UFG::SimObjectGame *)v1->mAttachedSimObject.m_pPointer;
          if ( v7 )
          {
            v8 = v7->m_Flags;
            if ( (v8 >> 14) & 1 )
            {
              v9 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
            }
            else if ( (v8 & 0x8000u) == 0 )
            {
              if ( (v8 >> 13) & 1 )
                v9 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
              else
                v9 = (UFG::RigidBody *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v7,
                                                           UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                  (UFG::SimObject *)&v7->vfptr,
                                                                                                  UFG::RigidBodyComponent::_TypeUID));
            }
            else
            {
              v9 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
            }
            if ( v9 )
              UFG::RigidBody::SetMotionType(v9, 0x80u);
          }
        }
      }
    }
  }
}

// File Line: 240
// RVA: 0x3B7600
char __fastcall AttachmentCreature::getRootTransform(AttachmentCreature *this, UFG::qMatrix44 *rootBoneTransform)
{
  AttachmentCreature *v2; // rbx
  Creature *v3; // rcx
  UFG::qMatrix44 *v4; // rdi
  UFG::SimComponent *v5; // rax
  __int64 v6; // rsi
  SkeletalPose *v7; // rcx
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm3
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  UFG::qVector3 translationWS; // [rsp+20h] [rbp-98h]
  UFG::qMatrix44 matrixWS; // [rsp+30h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+70h] [rbp-48h]

  v2 = this;
  v3 = this->mRootCreature.m_pPointer;
  v4 = rootBoneTransform;
  if ( !v3 )
    return 0;
  v5 = v2->mAttachedCharacterAnimationComponent.m_pPointer;
  if ( !v5 )
    return 0;
  v6 = *(_QWORD *)&v5[2].m_TypeUID;
  if ( v6 )
  {
    v7 = &v3->mPose;
    if ( v2->mAttachRelative )
    {
      SkeletalPose::GetPositionWS(v7, v2->attachedJoint, &matrixWS);
      v8 = UFG::qMatrix44::operator*(&v2->mRelativeAttachmentLS, &result, &matrixWS);
      v9 = v8->v1;
      v10 = v8->v2;
      v11 = v8->v3;
      v4->v0 = v8->v0;
      v4->v1 = v9;
      v4->v2 = v10;
      v4->v3 = v11;
    }
    else
    {
      SkeletalPose::GetPositionWS(v7, v2->attachedJoint, rootBoneTransform);
    }
    if ( v2->mPositionXYOnly )
    {
      SkeletalPose::GetTranslationWS((SkeletalPose *)(v6 + 240), v2->attachmentJoint, &translationWS);
      v4->v3.z = translationWS.z;
    }
  }
  return 1;
}

// File Line: 284
// RVA: 0x3B2700
void __fastcall AttachmentCreature::UpdatePose(AttachmentCreature *this)
{
  AttachmentCreature *v1; // rdi
  Creature *v2; // rbx
  float v3; // xmm0_4
  float v4; // xmm0_4
  int v5; // esi
  UFG::qMatrix44 *v6; // r8
  UFG::qMatrix44 rootBoneTransform; // [rsp+20h] [rbp-D8h]
  UFG::qMatrix44 matrixWS; // [rsp+60h] [rbp-98h]
  UFG::qMatrix44 dest; // [rsp+A0h] [rbp-58h]

  v1 = this;
  if ( AttachmentCreature::getRootTransform(this, &rootBoneTransform) )
  {
    v2 = *(Creature **)&v1->mAttachedCharacterAnimationComponent.m_pPointer[2].m_TypeUID;
    if ( v2 )
    {
      if ( v1->mPositionOnly )
      {
        v3 = Attachment::GetBlendWeight((Attachment *)&v1->vfptr);
        Creature::Attach(v2, v1->attachmentJoint, (UFG::qVector3 *)&rootBoneTransform.v3, v3);
      }
      else
      {
        v4 = Attachment::GetBlendWeight((Attachment *)&v1->vfptr);
        v5 = v1->attachmentJoint;
        if ( Creature::IsEndEffector(v2, v1->attachmentJoint) )
        {
          Creature::SetEndEffectorTarget(v2, v5, &rootBoneTransform);
        }
        else
        {
          SkeletalPose::GetPositionWS(&v2->mPose, v5, &matrixWS);
          v6 = &rootBoneTransform;
          if ( v4 < 1.0 )
          {
            BlendSlerp(&dest, &matrixWS, &rootBoneTransform, v4);
            v6 = &dest;
          }
          AttachPose(&v2->mPose, &matrixWS, v6);
        }
        Creature::UpdateAttachmentPoses(v2);
      }
      Creature::updateEffectorsToPose(v2);
    }
  }
}

// File Line: 361
// RVA: 0x39D990
void __fastcall AttachmentCreatureEffectorToCreatureReverse::AttachmentCreatureEffectorToCreatureReverse(AttachmentCreatureEffectorToCreatureReverse *this)
{
  UFG::qNode<Attachment,Attachment> *v1; // rax
  UFG::qVector4 v2; // xmm3
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<Creature,Creature> *v4; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *v6; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<Attachment,Attachment> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (AttachmentVtbl *)&Attachment::`vftable;
  *(_WORD *)&this->mPositionOnly = 0;
  this->mUseRubberBand = 0;
  this->attachedJoint = 0;
  v3 = &this->mRootSimObject;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->mRootSimObject.m_pPointer = 0i64;
  v4 = &this->mRootCreature;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->mRootCreature.m_pPointer = 0i64;
  v5 = &this->mAttachedSimObject;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->mAttachedSimObject.m_pPointer = 0i64;
  this->vfptr = (AttachmentVtbl *)&AttachmentCreatureEffectorToCreatureReverse::`vftable;
  v6 = &this->mFollowCharacterAnimationComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->mFollowCharacterAnimationComponent.m_pPointer = 0i64;
  this->mEffector = 0i64;
  *(_QWORD *)&this->mFollowJoint = 0i64;
  this->mAttachSocketJoint = 0;
  this->mOnlyEnablePostPhysics = 0;
  this->mFirstUpdate = 1;
  v2 = 0i64;
  v2.x = (float)1;
  this->mRelativeSpace.v0 = v2;
  this->mRelativeSpace.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 81);
  this->mRelativeSpace.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 69);
  this->mRelativeSpace.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 21);
}

// File Line: 368
// RVA: 0x39F580
void __fastcall AttachmentCreatureEffectorToCreatureReverse::~AttachmentCreatureEffectorToCreatureReverse(AttachmentCreatureEffectorToCreatureReverse *this)
{
  AttachmentCreatureEffectorToCreatureReverse *v1; // rbx
  TwoLinkIKsolver *v2; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = this;
  this->vfptr = (AttachmentVtbl *)&AttachmentCreatureEffectorToCreatureReverse::`vftable;
  v2 = this->mEffector;
  if ( v2 )
    v2->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v2->vfptr, 0);
  v3 = &v1->mFollowCharacterAnimationComponent;
  if ( v1->mFollowCharacterAnimationComponent.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v1->mFollowCharacterAnimationComponent.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v1->mFollowCharacterAnimationComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mFollowCharacterAnimationComponent.mPrev;
  }
  v1->mFollowCharacterAnimationComponent.m_pPointer = 0i64;
  v6 = v3->mPrev;
  v7 = v1->mFollowCharacterAnimationComponent.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->mFollowCharacterAnimationComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mFollowCharacterAnimationComponent.mPrev;
  Attachment::~Attachment((Attachment *)&v1->vfptr);
}

// File Line: 377
// RVA: 0x3B0B60
signed __int64 __fastcall AttachmentCreatureEffectorToCreatureReverse::Update(AttachmentCreatureEffectorToCreatureReverse *this, float timeDelta)
{
  AttachmentCreatureEffectorToCreatureReverse *v2; // rbx
  float v3; // xmm3_4
  __m128 v4; // xmm2
  float v5; // xmm0_4
  signed __int64 result; // rax

  v2 = this;
  this->mEffector->vfptr[1].__vecDelDtor((Expression::IMemberMap *)this->mEffector, 0);
  v3 = v2->mBlendRate;
  v4 = 0i64;
  if ( v3 != 0.0 )
  {
    v5 = (float)(v3 * timeDelta) + v2->mBlendWeight;
    v2->mBlendWeight = v5;
    if ( v3 <= v4.m128_f32[0] )
    {
      if ( v5 <= v4.m128_f32[0] )
        v2->mBlendWeight = 0.0;
    }
    else if ( v5 > 1.0 )
    {
      v2->mBlendWeight = 1.0;
    }
  }
  v2->mFirstUpdate = 1;
  result = 1i64;
  v4.m128_f32[0] = (float)1;
  v2->mRelativeSpace.v0 = (UFG::qVector4)v4;
  v2->mRelativeSpace.v1 = (UFG::qVector4)_mm_shuffle_ps(v4, v4, 81);
  v2->mRelativeSpace.v2 = (UFG::qVector4)_mm_shuffle_ps(v4, v4, 69);
  v2->mRelativeSpace.v3 = (UFG::qVector4)_mm_shuffle_ps(v4, v4, 21);
  return result;
}

// File Line: 388
// RVA: 0x3B2830
void __fastcall AttachmentCreatureEffectorToCreatureReverse::UpdatePose(AttachmentCreatureEffectorToCreatureReverse *this)
{
  AttachmentCreatureEffectorToCreatureReverse *v1; // rbx

  v1 = this;
  if ( !this->mOnlyEnablePostPhysics )
  {
    AttachmentCreatureEffectorToCreatureReverse::applyUpdateRelativeSpace(this);
    AttachmentCreatureEffectorToCreatureReverse::applyAttachmentPose(v1);
  }
}

// File Line: 401
// RVA: 0x3B48D0
void __fastcall AttachmentCreatureEffectorToCreatureReverse::UpdatePostPhysics(AttachmentCreatureEffectorToCreatureReverse *this)
{
  AttachmentCreatureEffectorToCreatureReverse *v1; // rbx

  v1 = this;
  AttachmentCreatureEffectorToCreatureReverse::applyUpdateRelativeSpace(this);
  AttachmentCreatureEffectorToCreatureReverse::applyAttachmentPose(v1);
}

// File Line: 411
// RVA: 0x3B6570
void __fastcall AttachmentCreatureEffectorToCreatureReverse::applyUpdateRelativeSpace(AttachmentCreatureEffectorToCreatureReverse *this)
{
  AttachmentCreatureEffectorToCreatureReverse *v1; // rdi
  int v2; // edx
  UFG::SimComponent *v3; // rax
  Creature *v4; // rbx
  UFG::qMatrix44 *v5; // rax
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  float v9; // xmm0_4
  UFG::qMatrix44 d; // [rsp+20h] [rbp-108h]
  UFG::qMatrix44 matrixWS; // [rsp+60h] [rbp-C8h]
  UFG::qMatrix44 m; // [rsp+A0h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+E0h] [rbp-48h]

  v1 = this;
  if ( this->mEffector )
  {
    v2 = this->mFollowJoint;
    if ( v2 >= 0 && this->mAttachJoint >= 0 && this->mAttachSocketJoint >= 0 )
    {
      v3 = this->mFollowCharacterAnimationComponent.m_pPointer;
      if ( v3 )
      {
        v4 = this->mRootCreature.m_pPointer;
        if ( v4 )
        {
          if ( *(_QWORD *)&v3[2].m_TypeUID )
          {
            if ( this->mFirstUpdate == 1 )
            {
              SkeletalPose::GetPositionWS(&v4->mPose, v2, &matrixWS);
              SkeletalPose::GetPositionWS(&v4->mPose, v1->mAttachJoint, &m);
              UFG::qInverseAffine(&d, &m);
              v5 = UFG::qMatrix44::operator*(&matrixWS, &result, &d);
              v6 = v5->v1;
              v7 = v5->v2;
              v8 = v5->v3;
              v1->mRelativeSpace.v0 = v5->v0;
              v1->mRelativeSpace.v1 = v6;
              v1->mRelativeSpace.v2 = v7;
              v1->mRelativeSpace.v3 = v8;
              v9 = v1->mRelativeSpaceScaleZ;
              v1->mFirstUpdate = 0;
              v1->mRelativeSpace.v3.z = v9 * v1->mRelativeSpace.v3.z;
            }
          }
        }
      }
    }
  }
}

// File Line: 449
// RVA: 0x3B6270
void __fastcall AttachmentCreatureEffectorToCreatureReverse::applyAttachmentPose(AttachmentCreatureEffectorToCreatureReverse *this)
{
  AttachmentCreatureEffectorToCreatureReverse *v1; // rbx
  int v2; // edx
  UFG::SimComponent *v3; // rax
  Creature *v4; // rdi
  __int64 v5; // rax
  __int64 v6; // rdx
  float v7; // xmm0_4
  int v8; // eax
  UFG::qMatrix44 result; // [rsp+20h] [rbp-D8h]
  UFG::qMatrix44 sourceB; // [rsp+60h] [rbp-98h]
  UFG::qMatrix44 sourceA; // [rsp+D8h] [rbp-20h]

  v1 = this;
  if ( this->mEffector )
  {
    if ( this->mFollowJoint >= 0 && this->mAttachJoint >= 0 )
    {
      v2 = this->mAttachSocketJoint;
      if ( v2 >= 0 )
      {
        v3 = this->mFollowCharacterAnimationComponent.m_pPointer;
        if ( v3 )
        {
          v4 = this->mRootCreature.m_pPointer;
          if ( v4 )
          {
            v5 = *(_QWORD *)&v3[2].m_TypeUID;
            if ( v5 )
            {
              if ( !this->mFirstUpdate && v5 != -240 && *(_QWORD *)(v5 + 488) )
              {
                SkeletalPose::GetPositionWS((SkeletalPose *)(v5 + 240), v2, (UFG::qMatrix44 *)((char *)&sourceB + 56));
                UFG::qMatrix44::operator*(&v1->mRelativeSpace, &result, (UFG::qMatrix44 *)((char *)&sourceB + 56));
                v7 = Attachment::GetBlendWeight((Attachment *)&v1->vfptr);
                if ( v7 < 1.0 )
                {
                  v8 = ((__int64 (*)(void))v1->mEffector->vfptr[1].GetClassname)();
                  SkeletalPose::GetPositionWS(&v4->mPose, v8, &sourceA);
                  sourceB.v0 = result.v0;
                  sourceB.v1 = result.v1;
                  *(UFG::qVector4 *)&sourceB.v1.z = result.v2;
                  *(UFG::qVector4 *)&sourceB.v2.z = result.v3;
                  BlendSlerp(&result, &sourceA, &sourceB, v7);
                }
                LOBYTE(v6) = 1;
                v1->mEffector->vfptr[1].__vecDelDtor((Expression::IMemberMap *)v1->mEffector, v6);
                ((void (__fastcall *)(TwoLinkIKsolver *, SkeletalPose *, UFG::qMatrix44 *))v1->mEffector->vfptr[1].GetClassNameUID)(
                  v1->mEffector,
                  &v4->mPose,
                  &result);
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 532
// RVA: 0x3B0C20
char __fastcall AttachmentCreatureToHandle::Update(AttachmentCreatureToHandle *this, float timeDelta)
{
  this->mUpdatedPose = 0;
  return 1;
}

// File Line: 538
// RVA: 0x3B2860
void __fastcall AttachmentCreatureToHandle::UpdatePose(AttachmentCreatureToHandle *this)
{
  AttachmentCreatureToHandle *v1; // rbx
  UFG::SimComponent *v2; // rax
  __int64 v3; // rdi
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  __int64 v7; // rsi
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm0
  UFG::qMatrix44 m; // [rsp+20h] [rbp-C8h]
  UFG::qMatrix44 d; // [rsp+60h] [rbp-88h]
  UFG::qMatrix44 matrixWS; // [rsp+A0h] [rbp-48h]

  v1 = this;
  if ( this->mUpdatedPose != 1 )
  {
    v2 = this->mAttachedCharacterAnimationComponent.m_pPointer;
    this->mUpdatedPose = 1;
    v3 = v2 ? *(_QWORD *)&v2[2].m_TypeUID : 0i64;
    if ( v3 )
    {
      if ( this->mParkourHandle.m_pPointer )
      {
        if ( this->attachedJoint >= 0 )
        {
          v4 = (UFG::SimObjectGame *)this->mParkourSimObject.m_pPointer;
          if ( v4 )
          {
            v5 = v4->m_Flags;
            if ( (v5 >> 14) & 1 )
            {
              v6 = v4->m_Components.p[9].m_pComponent;
            }
            else if ( (v5 & 0x8000u) == 0 )
            {
              if ( (v5 >> 13) & 1 )
              {
                v6 = v4->m_Components.p[8].m_pComponent;
              }
              else if ( (v5 >> 12) & 1 )
              {
                v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::BaseAnimationComponent::_TypeUID);
              }
              else
              {
                v6 = UFG::SimObject::GetComponentOfType(
                       (UFG::SimObject *)&v4->vfptr,
                       UFG::BaseAnimationComponent::_TypeUID);
              }
            }
            else
            {
              v6 = v4->m_Components.p[9].m_pComponent;
            }
            if ( v6 )
            {
              v7 = *(_QWORD *)&v6[2].m_TypeUID;
              if ( v7 )
              {
                SkeletalPose::GetPositionWS((SkeletalPose *)(v3 + 240), v1->attachedJoint, &matrixWS);
                SkeletalPose::GetPositionWS((SkeletalPose *)(v7 + 240), 0, &m);
                UFG::qInverseAffine(&d, &m);
                UFG::qMatrix44::operator*(&matrixWS, &m, &d);
                v8 = m.v2;
                v1->mParkourTransformLS.v0 = m.v0;
                v1->mParkourTransformLS.v1 = m.v1;
                v9 = m.v3;
                v1->mParkourTransformLS.v2 = v8;
                v1->mParkourTransformLS.v3 = v9;
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 582
// RVA: 0x3B7700
char __fastcall AttachmentCreatureToHandle::getRootTransform(AttachmentCreatureToHandle *this, UFG::qMatrix44 *rootBoneTransform)
{
  AttachmentCreatureToHandle *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::qMatrix44 *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  __int64 v7; // rcx
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm3
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  char v12; // al
  UFG::qMatrix44 matrixWS; // [rsp+20h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-48h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->mParkourSimObject.m_pPointer;
  v4 = rootBoneTransform;
  if ( !v3 || !v2->mAttachedCharacterAnimationComponent.m_pPointer )
    return 0;
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[9].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = v3->m_Components.p[8].m_pComponent;
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::BaseAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::BaseAnimationComponent::_TypeUID);
  }
  else
  {
    v6 = v3->m_Components.p[9].m_pComponent;
  }
  v7 = v6 ? *(_QWORD *)&v6[2].m_TypeUID : 0i64;
  if ( !v7 || !*(_QWORD *)&v2->mAttachedCharacterAnimationComponent.m_pPointer[2].m_TypeUID )
    return 0;
  SkeletalPose::GetPositionWS((SkeletalPose *)(v7 + 240), 0, &matrixWS);
  v8 = UFG::qMatrix44::operator*(&v2->mParkourTransformLS, &result, &matrixWS);
  v9 = v8->v1;
  v10 = v8->v2;
  v11 = v8->v3;
  v4->v0 = v8->v0;
  v4->v1 = v9;
  v12 = 1;
  v4->v2 = v10;
  v4->v3 = v11;
  return v12;
}

// File Line: 604
// RVA: 0x3B48F0
void __fastcall AttachmentCreatureToHandle::UpdatePostPhysics(AttachmentCreatureToHandle *this)
{
  AttachmentCreatureToHandle *v1; // rdi
  Creature *v2; // rbx
  float v3; // xmm0_4
  int v4; // esi
  UFG::qMatrix44 *v5; // r8
  UFG::qMatrix44 matrixWS; // [rsp+20h] [rbp-D8h]
  UFG::qMatrix44 rootBoneTransform; // [rsp+60h] [rbp-98h]
  UFG::qMatrix44 dest; // [rsp+A0h] [rbp-58h]

  v1 = this;
  if ( AttachmentCreatureToHandle::getRootTransform(this, &rootBoneTransform) )
  {
    v2 = (Creature *)v1->mAttachedCharacterAnimationComponent.m_pPointer;
    if ( v2 )
      v2 = (Creature *)v2->mLastSetPosition.m_scale.m_quad.m128_u64[1];
    if ( v2 )
    {
      v3 = Attachment::GetBlendWeight((Attachment *)&v1->vfptr);
      v4 = v1->attachedJoint;
      if ( Creature::IsEndEffector(v2, v1->attachedJoint) )
      {
        Creature::SetEndEffectorTarget(v2, v4, &rootBoneTransform);
      }
      else
      {
        SkeletalPose::GetPositionWS(&v2->mPose, v4, &matrixWS);
        v5 = &rootBoneTransform;
        if ( v3 < 1.0 )
        {
          BlendSlerp(&dest, &matrixWS, &rootBoneTransform, v3);
          v5 = &dest;
        }
        AttachPose(&v2->mPose, &matrixWS, v5);
      }
      Creature::UpdateAttachmentPoses(v2);
    }
  }
}

// File Line: 666
// RVA: 0x3B2BE0
void __fastcall AttachmentRigidBody::UpdatePose(AttachmentRigidBody *this)
{
  AttachmentRigidBody *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  UFG::RigidBody *v5; // rdi
  int v6; // edx
  SkeletalPose *v7; // rcx
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1
  UFG::qVector4 v11; // xmm0
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  UFG::qMatrix44 mat; // [rsp+20h] [rbp-F8h]
  hkQsTransformf v17; // [rsp+60h] [rbp-B8h]
  UFG::qMatrix44 matrixWS; // [rsp+90h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+D0h] [rbp-48h]

  v1 = this;
  if ( this->mRootCreature.m_pPointer )
  {
    v2 = (UFG::SimObjectGame *)this->mAttachedSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RigidBodyComponent::_TypeUID);
        else
          v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RigidBodyComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RigidBodyComponent::_TypeUID);
      }
      v5 = (UFG::RigidBody *)v4;
      if ( v4 )
      {
        v6 = v1->attachedJoint;
        v7 = &v1->mRootCreature.m_pPointer->mPose;
        if ( v1->mAttachRelative )
        {
          SkeletalPose::GetPositionWS(v7, v6, &matrixWS);
          v8 = UFG::qMatrix44::operator*(&v1->mRelativeAttachmentLS, &result, &matrixWS);
          v9 = v8->v2;
          v10 = v8->v3;
          v11 = v8->v0;
          mat.v1 = v8->v1;
          mat.v2 = v9;
          mat.v0 = v11;
          mat.v3 = v10;
        }
        else
        {
          SkeletalPose::GetPositionWS(v7, v6, &mat);
        }
        hkTransformf::set4x4ColumnMajor((hkTransformf *)&matrixWS, &mat.v0.x);
        hkQsTransformf::setFromTransformNoScale(&v17, (hkTransformf *)&matrixWS);
        v12 = _mm_mul_ps(v17.m_rotation.m_vec.m_quad, v17.m_rotation.m_vec.m_quad);
        v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
        v14 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13);
        v15 = _mm_rsqrt_ps(v14);
        v17.m_rotation.m_vec.m_quad = _mm_mul_ps(
                                        v17.m_rotation.m_vec.m_quad,
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v15)));
        hkQsTransformf::get4x4ColumnMajor(&v17, &mat.v0.x);
        UFG::RigidBody::SetTransform(v5, &mat);
      }
    }
  }
}

