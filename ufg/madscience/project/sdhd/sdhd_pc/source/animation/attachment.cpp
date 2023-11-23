// File Line: 70
// RVA: 0x3A2810
void __fastcall AttachPose(SkeletalPose *pose, UFG::qMatrix44 *fromMatrixWS, UFG::qMatrix44 *toMatrixWS)
{
  UFG::qMatrix44 *v5; // rax
  __m128 v6; // xmm9
  __m128 v7; // xmm8
  __m128 v8; // xmm7
  __m128 v9; // xmm6
  float v10; // xmm1_4
  __m128 y_low; // xmm5
  Render::DebugDrawContext *Context; // rax
  UFG::qVector3 t; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qQuaternion v14; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qQuaternion v15; // [rsp+40h] [rbp-B8h] BYREF
  char mat[120]; // [rsp+50h] [rbp-A8h] BYREF
  UFG::qMatrix44 d; // [rsp+C8h] [rbp-30h] BYREF
  UFG::qMatrix44 newRoot; // [rsp+108h] [rbp+10h] BYREF
  UFG::qMatrix44 result; // [rsp+148h] [rbp+50h] BYREF

  UFG::qInverseAffine((UFG::qMatrix44 *)&d.v0.z, fromMatrixWS);
  v5 = UFG::qMatrix44::operator*(&d, &result, toMatrixWS);
  v6 = (__m128)v5->v0;
  v7 = (__m128)v5->v1;
  v8 = (__m128)v5->v2;
  v9 = (__m128)v5->v3;
  SkeletalPose::GetRootMatrix(pose, (UFG::qMatrix44 *)&mat[56]);
  *(__m128 *)mat = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[56], *(__m128 *)&mat[56], 0), v6),
                           (__m128)0i64),
                         _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[56], *(__m128 *)&mat[56], 85), v7)),
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[56], *(__m128 *)&mat[56], 170), v8)),
                     _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[56], *(__m128 *)&mat[56], 255), v9));
  *(__m128 *)&mat[16] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[72], *(__m128 *)&mat[72], 0), v6),
                                (__m128)0i64),
                              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[72], *(__m128 *)&mat[72], 85), v7)),
                            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[72], *(__m128 *)&mat[72], 170), v8)),
                          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[72], *(__m128 *)&mat[72], 255), v9));
  *(_QWORD *)&mat[32] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[88], *(__m128 *)&mat[88], 0), v6),
                                (__m128)0i64),
                              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[88], *(__m128 *)&mat[88], 85), v7)),
                            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[88], *(__m128 *)&mat[88], 170), v8)),
                          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[88], *(__m128 *)&mat[88], 255), v9)).m128_u64[0];
  *(__m128 *)&mat[40] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[104], *(__m128 *)&mat[104], 0), v6),
                                (__m128)0i64),
                              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[104], *(__m128 *)&mat[104], 85), v7)),
                            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[104], *(__m128 *)&mat[104], 170), v8)),
                          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&mat[104], *(__m128 *)&mat[104], 255), v9));
  UFG::qQuaternion::Set(&v14, (UFG::qMatrix44 *)mat);
  y_low = (__m128)LODWORD(v14.y);
  v10 = 0.0;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v14.x * v14.x))
                            + (float)(v14.z * v14.z))
                    + (float)(v14.w * v14.w);
  if ( y_low.m128_f32[0] != 0.0 )
    v10 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
  t = *(UFG::qVector3 *)&mat[40];
  v15.x = v14.x * v10;
  v15.y = v14.y * v10;
  v15.w = v10 * v14.w;
  v15.z = v14.z * v10;
  UFG::qQuaternion::GetMatrix(&v15, &newRoot, &t);
  SkeletalPose::SetRoot(pose, &newRoot, 0);
  if ( gSkeletonDebug )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawCoord(Context, (UFG::qMatrix44 *)mat, 0.5, "Attach Pos");
  }
}

// File Line: 99
// RVA: 0x3AC100
void __fastcall Attachment::OnRemove(Attachment *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RigidBody *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mAttachedSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              m_pPointer,
                                              UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                              m_pPointer,
                                              UFG::RigidBodyComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::RigidBody::SetMotionType(ComponentOfTypeHK, 0x80u);
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
    return *(float *)&FLOAT_1_0;
  return result;
}

// File Line: 125
// RVA: 0x3B2A00
void __fastcall AttachmentCreatureToTransformNode::UpdatePose(AttachmentCreatureToTransformNode *this)
{
  UFG::SimComponent *m_pPointer; // rsi
  UFG::SimComponent *v3; // rdi
  Creature *v4; // rdi
  UFG::qMatrix44 *v5; // rax
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 m_BoundComponentHandles; // xmm1
  UFG::qVector4 v9; // xmm0
  bool v10; // zf
  float z; // xmm2_4
  float BlendWeight; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm6_4
  int attachmentJoint; // ebx
  UFG::qMatrix44 *p_translationWS_8; // r8
  __int64 translationWS; // [rsp+20h] [rbp-81h] BYREF
  UFG::qMatrix44 translationWS_8; // [rsp+28h] [rbp-79h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+68h] [rbp-39h] BYREF
  UFG::qMatrix44 result; // [rsp+A8h] [rbp+7h] BYREF

  m_pPointer = this->mTransformNodeComponentRoot.m_pPointer;
  if ( m_pPointer )
  {
    v3 = this->mAttachedCharacterAnimationComponent.m_pPointer;
    if ( v3 )
    {
      v4 = *(Creature **)&v3[2].m_TypeUID;
      if ( v4 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
        if ( this->mAttachRelative )
        {
          v5 = UFG::qMatrix44::operator*(&this->mRelativeAttachmentLS, &result, (UFG::qMatrix44 *)&m_pPointer[2]);
          v6 = v5->v1;
          v7 = v5->v2;
          m_BoundComponentHandles = v5->v3;
          v9 = v5->v0;
        }
        else
        {
          v6 = *(UFG::qVector4 *)&m_pPointer[2].m_SafePointerList.mNode.mNext;
          v7 = *(UFG::qVector4 *)&m_pPointer[2].m_Flags;
          m_BoundComponentHandles = (UFG::qVector4)m_pPointer[2].m_BoundComponentHandles;
          v9 = *(UFG::qVector4 *)&m_pPointer[2].vfptr;
        }
        v10 = !this->mPositionXYOnly;
        translationWS_8.v3 = m_BoundComponentHandles;
        translationWS_8.v2 = v7;
        translationWS_8.v1 = v6;
        translationWS_8.v0 = v9;
        if ( v10 )
        {
          z = translationWS_8.v3.z;
        }
        else
        {
          SkeletalPose::GetTranslationWS(&v4->mPose, this->attachmentJoint, (UFG::qVector3 *)&translationWS);
          z = translationWS_8.v0.x;
          translationWS_8.v3.z = translationWS_8.v0.x;
        }
        if ( this->mPositionOnly )
        {
          translationWS_8.v0.x = z;
          translationWS = *(_QWORD *)&translationWS_8.v3.x;
          BlendWeight = Attachment::GetBlendWeight(this);
          Creature::Attach(v4, this->attachmentJoint, (UFG::qVector3 *)&translationWS, BlendWeight);
        }
        else
        {
          v13 = Attachment::GetBlendWeight(this);
          v14 = v13;
          if ( this->mUseRubberBand && v13 >= 0.99000001 )
            v14 = FLOAT_0_1;
          attachmentJoint = this->attachmentJoint;
          if ( Creature::IsEndEffector(v4, attachmentJoint) )
          {
            Creature::SetEndEffectorTarget(v4, attachmentJoint, &translationWS_8);
          }
          else
          {
            SkeletalPose::GetPositionWS(&v4->mPose, attachmentJoint, &matrixWS);
            p_translationWS_8 = &translationWS_8;
            if ( v14 < 1.0 )
            {
              BlendSlerp(&result, &matrixWS, &translationWS_8, v14);
              p_translationWS_8 = &result;
            }
            AttachPose(&v4->mPose, &matrixWS, p_translationWS_8);
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
  UFG::SimComponent *m_pPointer; // rsi
  Creature *v3; // rsi
  UFG::qNode<PoseDriver,PoseDriver> *mNext; // rbx
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rsi
  UFG::qNode<PoseDriver,PoseDriver> *i; // rbx
  UFG::SimObjectGame *v7; // rcx
  __int16 m_Flags; // dx
  UFG::RigidBody *ComponentOfTypeHK; // rax

  if ( this->mAttachedSimObject.m_pPointer )
  {
    m_pPointer = this->mAttachedCharacterAnimationComponent.m_pPointer;
    if ( m_pPointer )
    {
      v3 = *(Creature **)&m_pPointer[2].m_TypeUID;
      if ( v3 )
      {
        v3->mIsAttached = 0;
        if ( Creature::IsEndEffector(v3, this->attachedJoint) )
        {
          mNext = v3->mPoseDrivers.mNode.mNext;
          p_m_SafePointerList = &v3->m_SafePointerList;
          for ( i = mNext - 1; i != (UFG::qNode<PoseDriver,PoseDriver> *)p_m_SafePointerList; i = i[1].mNext - 1 )
          {
            if ( ((unsigned int (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *))i->mPrev[7].mPrev)(i) == this->attachedJoint )
              ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, _QWORD))i->mPrev[5].mNext)(i, 0i64);
          }
        }
        else
        {
          v7 = (UFG::SimObjectGame *)this->mAttachedSimObject.m_pPointer;
          if ( v7 )
          {
            m_Flags = v7->m_Flags;
            if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v7,
                                                      UFG::RigidBodyComponent::_TypeUID);
            else
              ComponentOfTypeHK = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                                      v7,
                                                      UFG::RigidBodyComponent::_TypeUID);
            if ( ComponentOfTypeHK )
              UFG::RigidBody::SetMotionType(ComponentOfTypeHK, 0x80u);
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
  Creature *m_pPointer; // rcx
  UFG::SimComponent *v5; // rax
  __int64 v6; // rsi
  SkeletalPose *p_mPose; // rcx
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm3
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  UFG::qVector3 translationWS; // [rsp+20h] [rbp-98h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+30h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+70h] [rbp-48h] BYREF

  m_pPointer = this->mRootCreature.m_pPointer;
  if ( !m_pPointer )
    return 0;
  v5 = this->mAttachedCharacterAnimationComponent.m_pPointer;
  if ( !v5 )
    return 0;
  v6 = *(_QWORD *)&v5[2].m_TypeUID;
  if ( v6 )
  {
    p_mPose = &m_pPointer->mPose;
    if ( this->mAttachRelative )
    {
      SkeletalPose::GetPositionWS(p_mPose, this->attachedJoint, &matrixWS);
      v8 = UFG::qMatrix44::operator*(&this->mRelativeAttachmentLS, &result, &matrixWS);
      v9 = v8->v1;
      v10 = v8->v2;
      v11 = v8->v3;
      rootBoneTransform->v0 = v8->v0;
      rootBoneTransform->v1 = v9;
      rootBoneTransform->v2 = v10;
      rootBoneTransform->v3 = v11;
    }
    else
    {
      SkeletalPose::GetPositionWS(p_mPose, this->attachedJoint, rootBoneTransform);
    }
    if ( this->mPositionXYOnly )
    {
      SkeletalPose::GetTranslationWS((SkeletalPose *)(v6 + 240), this->attachmentJoint, &translationWS);
      rootBoneTransform->v3.z = translationWS.z;
    }
  }
  return 1;
}

// File Line: 284
// RVA: 0x3B2700
void __fastcall AttachmentCreature::UpdatePose(AttachmentCreature *this)
{
  Creature *v2; // rbx
  float BlendWeight; // xmm0_4
  float v4; // xmm0_4
  int attachmentJoint; // esi
  UFG::qMatrix44 *p_rootBoneTransform; // r8
  UFG::qMatrix44 rootBoneTransform; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+60h] [rbp-98h] BYREF
  UFG::qMatrix44 dest; // [rsp+A0h] [rbp-58h] BYREF

  if ( AttachmentCreature::getRootTransform(this, &rootBoneTransform) )
  {
    v2 = *(Creature **)&this->mAttachedCharacterAnimationComponent.m_pPointer[2].m_TypeUID;
    if ( v2 )
    {
      if ( this->mPositionOnly )
      {
        BlendWeight = Attachment::GetBlendWeight(this);
        Creature::Attach(v2, this->attachmentJoint, (UFG::qVector3 *)&rootBoneTransform.v3, BlendWeight);
      }
      else
      {
        v4 = Attachment::GetBlendWeight(this);
        attachmentJoint = this->attachmentJoint;
        if ( Creature::IsEndEffector(v2, attachmentJoint) )
        {
          Creature::SetEndEffectorTarget(v2, attachmentJoint, &rootBoneTransform);
        }
        else
        {
          SkeletalPose::GetPositionWS(&v2->mPose, attachmentJoint, &matrixWS);
          p_rootBoneTransform = &rootBoneTransform;
          if ( v4 < 1.0 )
          {
            BlendSlerp(&dest, &matrixWS, &rootBoneTransform, v4);
            p_rootBoneTransform = &dest;
          }
          AttachPose(&v2->mPose, &matrixWS, p_rootBoneTransform);
        }
        Creature::UpdateAttachmentPoses(v2);
      }
      Creature::updateEffectorsToPose(v2);
    }
  }
}

// File Line: 361
// RVA: 0x39D990
void __fastcall AttachmentCreatureEffectorToCreatureReverse::AttachmentCreatureEffectorToCreatureReverse(
        AttachmentCreatureEffectorToCreatureReverse *this)
{
  UFG::qVector4 v1; // xmm3

  this->mPrev = &this->UFG::qNode<Attachment,Attachment>;
  this->mNext = &this->UFG::qNode<Attachment,Attachment>;
  this->vfptr = (AttachmentVtbl *)&Attachment::`vftable;
  *(_WORD *)&this->mPositionOnly = 0;
  this->mUseRubberBand = 0;
  this->attachedJoint = 0;
  this->mRootSimObject.Attachment::mPrev = &this->mRootSimObject;
  this->mRootSimObject.mNext = &this->mRootSimObject;
  this->mRootSimObject.m_pPointer = 0i64;
  this->mRootCreature.Attachment::mPrev = &this->mRootCreature;
  this->mRootCreature.mNext = &this->mRootCreature;
  this->mRootCreature.m_pPointer = 0i64;
  this->mAttachedSimObject.Attachment::mPrev = &this->mAttachedSimObject;
  this->mAttachedSimObject.mNext = &this->mAttachedSimObject;
  this->mAttachedSimObject.m_pPointer = 0i64;
  this->vfptr = (AttachmentVtbl *)&AttachmentCreatureEffectorToCreatureReverse::`vftable;
  this->mFollowCharacterAnimationComponent.mPrev = &this->mFollowCharacterAnimationComponent;
  this->mFollowCharacterAnimationComponent.mNext = &this->mFollowCharacterAnimationComponent;
  this->mFollowCharacterAnimationComponent.m_pPointer = 0i64;
  this->mEffector = 0i64;
  *(_QWORD *)&this->mFollowJoint = 0i64;
  this->mAttachSocketJoint = 0;
  this->mOnlyEnablePostPhysics = 0;
  this->mFirstUpdate = 1;
  v1 = 0i64;
  v1.x = (float)1;
  this->mRelativeSpace.v0 = v1;
  this->mRelativeSpace.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v1, (__m128)v1, 81);
  this->mRelativeSpace.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v1, (__m128)v1, 69);
  this->mRelativeSpace.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v1, (__m128)v1, 21);
}

// File Line: 368
// RVA: 0x39F580
void __fastcall AttachmentCreatureEffectorToCreatureReverse::~AttachmentCreatureEffectorToCreatureReverse(
        AttachmentCreatureEffectorToCreatureReverse *this)
{
  TwoLinkIKsolver *mEffector; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *p_mFollowCharacterAnimationComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  this->vfptr = (AttachmentVtbl *)&AttachmentCreatureEffectorToCreatureReverse::`vftable;
  mEffector = this->mEffector;
  if ( mEffector )
    mEffector->vfptr[1].__vecDelDtor(mEffector, 0);
  p_mFollowCharacterAnimationComponent = &this->mFollowCharacterAnimationComponent;
  if ( this->mFollowCharacterAnimationComponent.m_pPointer )
  {
    mPrev = p_mFollowCharacterAnimationComponent->mPrev;
    mNext = this->mFollowCharacterAnimationComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mFollowCharacterAnimationComponent->mPrev = p_mFollowCharacterAnimationComponent;
    this->mFollowCharacterAnimationComponent.mNext = &this->mFollowCharacterAnimationComponent;
  }
  this->mFollowCharacterAnimationComponent.m_pPointer = 0i64;
  v6 = p_mFollowCharacterAnimationComponent->mPrev;
  v7 = this->mFollowCharacterAnimationComponent.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_mFollowCharacterAnimationComponent->mPrev = p_mFollowCharacterAnimationComponent;
  this->mFollowCharacterAnimationComponent.mNext = &this->mFollowCharacterAnimationComponent;
  Attachment::~Attachment(this);
}

// File Line: 377
// RVA: 0x3B0B60
__int64 __fastcall AttachmentCreatureEffectorToCreatureReverse::Update(
        AttachmentCreatureEffectorToCreatureReverse *this,
        float timeDelta)
{
  float mBlendRate; // xmm3_4
  UFG::qVector4 v4; // xmm2
  float v5; // xmm0_4
  __int64 result; // rax

  this->mEffector->vfptr[1].__vecDelDtor(this->mEffector, 0);
  mBlendRate = this->mBlendRate;
  v4 = 0i64;
  if ( mBlendRate != 0.0 )
  {
    v5 = (float)(mBlendRate * timeDelta) + this->mBlendWeight;
    this->mBlendWeight = v5;
    if ( mBlendRate <= 0.0 )
    {
      if ( v5 <= 0.0 )
        this->mBlendWeight = 0.0;
    }
    else if ( v5 > 1.0 )
    {
      this->mBlendWeight = 1.0;
    }
  }
  this->mFirstUpdate = 1;
  result = 1i64;
  v4.x = (float)1;
  this->mRelativeSpace.v0 = v4;
  this->mRelativeSpace.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v4, (__m128)v4, 81);
  this->mRelativeSpace.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v4, (__m128)v4, 69);
  this->mRelativeSpace.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v4, (__m128)v4, 21);
  return result;
}

// File Line: 388
// RVA: 0x3B2830
void __fastcall AttachmentCreatureEffectorToCreatureReverse::UpdatePose(
        AttachmentCreatureEffectorToCreatureReverse *this)
{
  if ( !this->mOnlyEnablePostPhysics )
  {
    AttachmentCreatureEffectorToCreatureReverse::applyUpdateRelativeSpace(this);
    AttachmentCreatureEffectorToCreatureReverse::applyAttachmentPose(this);
  }
}

// File Line: 401
// RVA: 0x3B48D0
void __fastcall AttachmentCreatureEffectorToCreatureReverse::UpdatePostPhysics(
        AttachmentCreatureEffectorToCreatureReverse *this)
{
  AttachmentCreatureEffectorToCreatureReverse::applyUpdateRelativeSpace(this);
  AttachmentCreatureEffectorToCreatureReverse::applyAttachmentPose(this);
}

// File Line: 411
// RVA: 0x3B6570
void __fastcall AttachmentCreatureEffectorToCreatureReverse::applyUpdateRelativeSpace(
        AttachmentCreatureEffectorToCreatureReverse *this)
{
  int mFollowJoint; // edx
  UFG::SimComponent *m_pPointer; // rax
  Creature *v4; // rbx
  UFG::qMatrix44 *v5; // rax
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  float mRelativeSpaceScaleZ; // xmm0_4
  UFG::qMatrix44 d; // [rsp+20h] [rbp-108h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+60h] [rbp-C8h] BYREF
  UFG::qMatrix44 m; // [rsp+A0h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+E0h] [rbp-48h] BYREF

  if ( this->mEffector )
  {
    mFollowJoint = this->mFollowJoint;
    if ( mFollowJoint >= 0 && this->mAttachJoint >= 0 && this->mAttachSocketJoint >= 0 )
    {
      m_pPointer = this->mFollowCharacterAnimationComponent.m_pPointer;
      if ( m_pPointer )
      {
        v4 = this->mRootCreature.m_pPointer;
        if ( v4 )
        {
          if ( *(_QWORD *)&m_pPointer[2].m_TypeUID )
          {
            if ( this->mFirstUpdate )
            {
              SkeletalPose::GetPositionWS(&v4->mPose, mFollowJoint, &matrixWS);
              SkeletalPose::GetPositionWS(&v4->mPose, this->mAttachJoint, &m);
              UFG::qInverseAffine(&d, &m);
              v5 = UFG::qMatrix44::operator*(&matrixWS, &result, &d);
              v6 = v5->v1;
              v7 = v5->v2;
              v8 = v5->v3;
              this->mRelativeSpace.v0 = v5->v0;
              this->mRelativeSpace.v1 = v6;
              this->mRelativeSpace.v2 = v7;
              this->mRelativeSpace.v3 = v8;
              mRelativeSpaceScaleZ = this->mRelativeSpaceScaleZ;
              this->mFirstUpdate = 0;
              this->mRelativeSpace.v3.z = mRelativeSpaceScaleZ * this->mRelativeSpace.v3.z;
            }
          }
        }
      }
    }
  }
}

// File Line: 449
// RVA: 0x3B6270
void __fastcall AttachmentCreatureEffectorToCreatureReverse::applyAttachmentPose(
        AttachmentCreatureEffectorToCreatureReverse *this)
{
  int mAttachSocketJoint; // edx
  UFG::SimComponent *m_pPointer; // rax
  Creature *v4; // rdi
  __int64 v5; // rax
  __int64 v6; // rdx
  float BlendWeight; // xmm0_4
  int v8; // eax
  UFG::qMatrix44 result; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qMatrix44 sourceB; // [rsp+60h] [rbp-98h] BYREF
  UFG::qMatrix44 sourceA; // [rsp+D8h] [rbp-20h] BYREF

  if ( this->mEffector )
  {
    if ( this->mFollowJoint >= 0 && this->mAttachJoint >= 0 )
    {
      mAttachSocketJoint = this->mAttachSocketJoint;
      if ( mAttachSocketJoint >= 0 )
      {
        m_pPointer = this->mFollowCharacterAnimationComponent.m_pPointer;
        if ( m_pPointer )
        {
          v4 = this->mRootCreature.m_pPointer;
          if ( v4 )
          {
            v5 = *(_QWORD *)&m_pPointer[2].m_TypeUID;
            if ( v5 )
            {
              if ( !this->mFirstUpdate && v5 != -240 && *(_QWORD *)(v5 + 488) )
              {
                SkeletalPose::GetPositionWS(
                  (SkeletalPose *)(v5 + 240),
                  mAttachSocketJoint,
                  (UFG::qMatrix44 *)&sourceB.v3.z);
                UFG::qMatrix44::operator*(&this->mRelativeSpace, &result, (UFG::qMatrix44 *)&sourceB.v3.z);
                BlendWeight = Attachment::GetBlendWeight(this);
                if ( BlendWeight < 1.0 )
                {
                  v8 = (int)this->mEffector->vfptr[1].GetClassname(this->mEffector);
                  SkeletalPose::GetPositionWS(&v4->mPose, v8, &sourceA);
                  sourceB.v0 = result.v0;
                  *(_QWORD *)&sourceB.v1.x = *(_QWORD *)&result.v1.x;
                  *(UFG::qVector4 *)&sourceB.v1.z = result.v2;
                  *(UFG::qVector4 *)&sourceB.v2.z = result.v3;
                  BlendSlerp(&result, &sourceA, &sourceB, BlendWeight);
                }
                LOBYTE(v6) = 1;
                this->mEffector->vfptr[1].__vecDelDtor(this->mEffector, v6);
                ((void (__fastcall *)(TwoLinkIKsolver *, SkeletalPose *, UFG::qMatrix44 *))this->mEffector->vfptr[1].GetClassNameUID)(
                  this->mEffector,
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
  UFG::SimComponent *m_pPointer; // rax
  __int64 v3; // rdi
  UFG::SimObjectGame *v4; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  __int64 v7; // rsi
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm0
  UFG::qMatrix44 m; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qMatrix44 d; // [rsp+60h] [rbp-88h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+A0h] [rbp-48h] BYREF

  if ( !this->mUpdatedPose )
  {
    m_pPointer = this->mAttachedCharacterAnimationComponent.m_pPointer;
    this->mUpdatedPose = 1;
    v3 = m_pPointer ? *(_QWORD *)&m_pPointer[2].m_TypeUID : 0i64;
    if ( v3 )
    {
      if ( this->mParkourHandle.m_pPointer )
      {
        if ( this->attachedJoint >= 0 )
        {
          v4 = (UFG::SimObjectGame *)this->mParkourSimObject.m_pPointer;
          if ( v4 )
          {
            m_Flags = v4->m_Flags;
            if ( (m_Flags & 0x4000) != 0 )
            {
              m_pComponent = v4->m_Components.p[9].m_pComponent;
            }
            else if ( m_Flags >= 0 )
            {
              if ( (m_Flags & 0x2000) != 0 )
              {
                m_pComponent = v4->m_Components.p[8].m_pComponent;
              }
              else if ( (m_Flags & 0x1000) != 0 )
              {
                m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::BaseAnimationComponent::_TypeUID);
              }
              else
              {
                m_pComponent = UFG::SimObject::GetComponentOfType(v4, UFG::BaseAnimationComponent::_TypeUID);
              }
            }
            else
            {
              m_pComponent = v4->m_Components.p[9].m_pComponent;
            }
            if ( m_pComponent )
            {
              v7 = *(_QWORD *)&m_pComponent[2].m_TypeUID;
              if ( v7 )
              {
                SkeletalPose::GetPositionWS((SkeletalPose *)(v3 + 240), this->attachedJoint, &matrixWS);
                SkeletalPose::GetPositionWS((SkeletalPose *)(v7 + 240), 0, &m);
                UFG::qInverseAffine(&d, &m);
                UFG::qMatrix44::operator*(&matrixWS, &m, &d);
                v8 = m.v2;
                this->mParkourTransformLS.v0 = m.v0;
                this->mParkourTransformLS.v1 = m.v1;
                v9 = m.v3;
                this->mParkourTransformLS.v2 = v8;
                this->mParkourTransformLS.v3 = v9;
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
bool __fastcall AttachmentCreatureToHandle::getRootTransform(
        AttachmentCreatureToHandle *this,
        UFG::qMatrix44 *rootBoneTransform)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  __int64 v7; // rcx
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm3
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  bool v12; // al
  UFG::qMatrix44 matrixWS; // [rsp+20h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+60h] [rbp-48h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mParkourSimObject.m_pPointer;
  if ( !m_pPointer || !this->mAttachedCharacterAnimationComponent.m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[9].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[8].m_pComponent;
    else
      m_pComponent = (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::BaseAnimationComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::BaseAnimationComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[9].m_pComponent;
  }
  v7 = m_pComponent ? *(_QWORD *)&m_pComponent[2].m_TypeUID : 0i64;
  if ( !v7 || !*(_QWORD *)&this->mAttachedCharacterAnimationComponent.m_pPointer[2].m_TypeUID )
    return 0;
  SkeletalPose::GetPositionWS((SkeletalPose *)(v7 + 240), 0, &matrixWS);
  v8 = UFG::qMatrix44::operator*(&this->mParkourTransformLS, &result, &matrixWS);
  v9 = v8->v1;
  v10 = v8->v2;
  v11 = v8->v3;
  rootBoneTransform->v0 = v8->v0;
  rootBoneTransform->v1 = v9;
  v12 = 1;
  rootBoneTransform->v2 = v10;
  rootBoneTransform->v3 = v11;
  return v12;
}

// File Line: 604
// RVA: 0x3B48F0
void __fastcall AttachmentCreatureToHandle::UpdatePostPhysics(AttachmentCreatureToHandle *this)
{
  Creature *m_pPointer; // rbx
  float BlendWeight; // xmm0_4
  int attachedJoint; // esi
  UFG::qMatrix44 *p_rootBoneTransform; // r8
  UFG::qMatrix44 matrixWS; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qMatrix44 rootBoneTransform; // [rsp+60h] [rbp-98h] BYREF
  UFG::qMatrix44 dest; // [rsp+A0h] [rbp-58h] BYREF

  if ( AttachmentCreatureToHandle::getRootTransform(this, &rootBoneTransform) )
  {
    m_pPointer = (Creature *)this->mAttachedCharacterAnimationComponent.m_pPointer;
    if ( m_pPointer )
      m_pPointer = (Creature *)m_pPointer->mLastSetPosition.m_scale.m_quad.m128_u64[1];
    if ( m_pPointer )
    {
      BlendWeight = Attachment::GetBlendWeight(this);
      attachedJoint = this->attachedJoint;
      if ( Creature::IsEndEffector(m_pPointer, attachedJoint) )
      {
        Creature::SetEndEffectorTarget(m_pPointer, attachedJoint, &rootBoneTransform);
      }
      else
      {
        SkeletalPose::GetPositionWS(&m_pPointer->mPose, attachedJoint, &matrixWS);
        p_rootBoneTransform = &rootBoneTransform;
        if ( BlendWeight < 1.0 )
        {
          BlendSlerp(&dest, &matrixWS, &rootBoneTransform, BlendWeight);
          p_rootBoneTransform = &dest;
        }
        AttachPose(&m_pPointer->mPose, &matrixWS, p_rootBoneTransform);
      }
      Creature::UpdateAttachmentPoses(m_pPointer);
    }
  }
}

// File Line: 666
// RVA: 0x3B2BE0
void __fastcall AttachmentRigidBody::UpdatePose(AttachmentRigidBody *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::RigidBody *v5; // rdi
  int attachedJoint; // edx
  SkeletalPose *p_mPose; // rcx
  UFG::qMatrix44 *v8; // rax
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1
  UFG::qVector4 v11; // xmm0
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  UFG::qMatrix44 mat; // [rsp+20h] [rbp-F8h] BYREF
  hkQsTransformf v17; // [rsp+60h] [rbp-B8h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+90h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+D0h] [rbp-48h] BYREF

  if ( this->mRootCreature.m_pPointer )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mAttachedSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RigidBodyComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RigidBodyComponent::_TypeUID);
      v5 = (UFG::RigidBody *)ComponentOfTypeHK;
      if ( ComponentOfTypeHK )
      {
        attachedJoint = this->attachedJoint;
        p_mPose = &this->mRootCreature.m_pPointer->mPose;
        if ( this->mAttachRelative )
        {
          SkeletalPose::GetPositionWS(p_mPose, attachedJoint, &matrixWS);
          v8 = UFG::qMatrix44::operator*(&this->mRelativeAttachmentLS, &result, &matrixWS);
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
          SkeletalPose::GetPositionWS(p_mPose, attachedJoint, &mat);
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

