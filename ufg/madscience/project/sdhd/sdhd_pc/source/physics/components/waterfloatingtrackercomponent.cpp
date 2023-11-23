// File Line: 34
// RVA: 0x465BD0
void __fastcall UFG::GenerateSplash(hkpRigidBody *body, float waterElevation, __int64 a3)
{
  unsigned int v4; // eax
  float v5; // xmm6_4
  __m128 v6; // xmm8
  float v7; // xmm13_4
  __m128 v8; // xmm2
  float v9; // xmm0_4
  float v10; // xmm14_4
  float v11; // xmm0_4
  float v12; // xmm15_4
  __int128 v13; // xmm5
  __int128 v14; // xmm9
  float v15; // xmm10_4
  __m128 x_low; // xmm2
  float v17; // xmm6_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm6_4
  __int128 v21; // xmm11
  __m128 v22; // xmm8
  float v23; // xmm6_4
  __m128 v24; // xmm2
  float v25; // xmm1_4
  float v26; // xmm2_4
  __m128 v27; // xmm12
  float v28; // xmm8_4
  __m128 v29; // xmm5
  float v30; // xmm3_4
  float v31; // xmm2_4
  unsigned int v32; // r8d
  UFG::qBaseTreeRB *ImpactDesc; // rax
  unsigned int mParent; // edx
  int v35[8]; // [rsp+40h] [rbp-B8h] BYREF
  UFG::qMatrix44 basis; // [rsp+60h] [rbp-98h] BYREF
  float v37; // [rsp+150h] [rbp+58h]

  v4 = _S17_2;
  if ( (_S17_2 & 1) == 0 )
  {
    _S17_2 |= 1u;
    impactType = UFG::qStringHashUpper32("WaterSplash", -1);
    v4 = _S17_2;
  }
  if ( (v4 & 2) == 0 )
  {
    _S17_2 = v4 | 2;
    materialType_Low = UFG::qStringHashUpper32("SplashForce_Low", -1);
    v4 = _S17_2;
  }
  if ( (v4 & 4) == 0 )
  {
    _S17_2 = v4 | 4;
    materialType_Med = UFG::qStringHashUpper32("SplashForce_Med", -1);
    v4 = _S17_2;
  }
  if ( (v4 & 8) == 0 )
  {
    _S17_2 = v4 | 8;
    materialType_High = UFG::qStringHashUpper32("SplashForce_High", -1);
  }
  v5 = body->m_motion.m_linearVelocity.m_quad.m128_f32[0];
  v6 = (__m128)body->m_motion.m_linearVelocity.m_quad.m128_u32[1];
  v7 = body->m_motion.m_linearVelocity.m_quad.m128_f32[2];
  v8 = v6;
  v8.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5);
  if ( (float)((float)(v7 * v7) + v8.m128_f32[0]) >= 2.25 )
  {
    v9 = v5 * 0.5;
    if ( (float)(v5 * 0.5) <= -1.0 )
    {
      v9 = FLOAT_N1_0;
    }
    else if ( v9 >= 1.0 )
    {
      v9 = *(float *)&FLOAT_1_0;
    }
    v10 = body->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[0] + v9;
    v11 = v6.m128_f32[0] * 0.5;
    if ( (float)(v6.m128_f32[0] * 0.5) <= -1.0 )
    {
      v11 = FLOAT_N1_0;
    }
    else if ( v11 >= 1.0 )
    {
      v11 = *(float *)&FLOAT_1_0;
    }
    v12 = body->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[1] + v11;
    if ( v8.m128_f32[0] == 0.0 )
    {
      v13 = 0i64;
    }
    else
    {
      v13 = (unsigned int)FLOAT_1_0;
      *(float *)&v13 = 1.0 / _mm_sqrt_ps(v8).m128_f32[0];
    }
    v14 = v13;
    *(float *)&v14 = *(float *)&v13 * v5;
    v15 = *(float *)&v13 * v6.m128_f32[0];
    *(float *)&v13 = *(float *)&v13 * 0.0;
    LODWORD(basis.v0.x) = v14;
    basis.v0.y = v15;
    LODWORD(basis.v0.z) = v13;
    basis.v0.w = 0.0;
    x_low = (__m128)LODWORD(UFG::qVector3::msAxisZ.x);
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                              + (float)(UFG::qVector3::msAxisZ.y * UFG::qVector3::msAxisZ.y))
                      + (float)(UFG::qVector3::msAxisZ.z * UFG::qVector3::msAxisZ.z);
    if ( x_low.m128_f32[0] == 0.0 )
      v17 = 0.0;
    else
      v17 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
    v18 = v17 * UFG::qVector3::msAxisZ.x;
    v19 = v17 * UFG::qVector3::msAxisZ.y;
    v20 = v17 * UFG::qVector3::msAxisZ.z;
    v21 = v13;
    *(float *)&v21 = (float)(*(float *)&v13 * v19) - (float)(v15 * v20);
    v22 = (__m128)v14;
    v22.m128_f32[0] = (float)(*(float *)&v14 * v20) - (float)(*(float *)&v13 * v18);
    v23 = (float)(v15 * v18) - (float)(*(float *)&v14 * v19);
    v24 = v22;
    v24.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(*(float *)&v21 * *(float *)&v21))
                    + (float)(v23 * v23);
    if ( v24.m128_f32[0] == 0.0 )
      v25 = 0.0;
    else
      v25 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
    *(float *)&v21 = *(float *)&v21 * v25;
    LODWORD(basis.v1.x) = v21;
    basis.v1.y = v22.m128_f32[0] * v25;
    basis.v1.w = 0.0;
    v26 = (float)((float)(v23 * v25) * v15) - (float)((float)(v22.m128_f32[0] * v25) * *(float *)&v13);
    v27 = (__m128)v21;
    v27.m128_f32[0] = (float)(*(float *)&v21 * *(float *)&v13) - (float)((float)(v23 * v25) * *(float *)&v14);
    v28 = (float)((float)(v22.m128_f32[0] * v25) * *(float *)&v14) - (float)(*(float *)&v21 * v15);
    v29 = v27;
    v29.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v26 * v26)) + (float)(v28 * v28);
    if ( v29.m128_f32[0] == 0.0 )
      v30 = 0.0;
    else
      v30 = 1.0 / _mm_sqrt_ps(v29).m128_f32[0];
    basis.v1.z = v26 * v30;
    basis.v1.w = v27.m128_f32[0] * v30;
    basis.v2.x = v28 * v30;
    basis.v2.y = 0.0;
    basis.v2.z = v10;
    basis.v2.w = v12;
    basis.v3.y = 1.0;
    basis.v3.x = v37;
    ((void (__fastcall *)(hkpShape *, hkMotionState *, __int64, int *))body->m_collidable.m_shape->hkpEntity::hkpWorldObject::vfptr[2].__vecDelDtor)(
      body->m_collidable.m_shape,
      &body->m_motion.m_motionState,
      a3,
      v35);
    v31 = (float)((float)((float)((float)(*(float *)&v35[5] - *(float *)&v35[1])
                                * (float)(*(float *)&v35[4] - *(float *)v35))
                        * (float)(*(float *)&v35[6] - *(float *)&v35[2]))
                * v7)
        * -1.0;
    if ( v31 >= 5.0 )
    {
      v32 = materialType_High;
      if ( v31 < 15.0 )
        v32 = materialType_Med;
    }
    else
    {
      v32 = materialType_Low;
    }
    ImpactDesc = Render::ImpactManager::GetImpactDesc(&Render::gImpactManager, impactType, v32);
    if ( ImpactDesc )
    {
      mParent = (unsigned int)ImpactDesc->mNULL.mParent;
      if ( mParent != -1 )
        Render::FXManager::CreateEffect(&Render::gFXManager, mParent, &basis, 0xFFFFFFFF);
    }
  }
}

// File Line: 112
// RVA: 0x1514410
__int64 dynamic_initializer_for__UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList__);
}

// File Line: 113
// RVA: 0x466480
UFG::ComponentIDDesc *__fastcall UFG::WaterFloatingTrackerComponent::GetDesc(UFG::WaterFloatingTrackerComponent *this)
{
  return &UFG::WaterFloatingTrackerComponent::_TypeIDesc;
}

// File Line: 118
// RVA: 0x1519DE0
__int64 UFG::_dynamic_initializer_for__gFloatingTrackerComponentName__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("WaterFloatingTracker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gFloatingTrackerComponentName, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gFloatingTrackerComponentName__);
}

// File Line: 121
// RVA: 0x458810
UFG::WaterFloatingTrackerBaseComponent *__fastcall UFG::AquireWaterFloatingTrackerComponent(
        UFG::SimObject *obj,
        hkpRigidBody *body)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rdi
  signed __int16 m_Flags; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xB8ui64, "WaterFloatingTrackerComponent", 0i64, 1u);
  if ( v5 )
  {
    UFG::WaterFloatingTrackerComponent::WaterFloatingTrackerComponent(
      (UFG::WaterFloatingTrackerComponent *)v5,
      UFG::gFloatingTrackerComponentName.mUID,
      body);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  m_Flags = obj->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags >= 0 )
    v9 = -1;
  else
    v9 = 35;
  UFG::SimObjectModifier::SimObjectModifier(&v11, obj, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v7, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return (UFG::WaterFloatingTrackerBaseComponent *)v7;
}

// File Line: 146
// RVA: 0x44E510
void __fastcall UFG::WaterFloatingTrackerComponent::WaterFloatingTrackerComponent(
        UFG::WaterFloatingTrackerComponent *this,
        unsigned int name_uid,
        hkpRigidBody *body)
{
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *mPrev; // rax

  UFG::WaterFloatingTrackerBaseComponent::WaterFloatingTrackerBaseComponent(this, name_uid, body);
  this->UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent>::mPrev = &this->UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent>;
  this->UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent>::mNext = &this->UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent>;
  this->UFG::WaterFloatingTrackerBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterFloatingTrackerComponent::`vftable{for `UFG::SimComponent};
  this->UFG::WaterFloatingTrackerBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::WaterFloatingTrackerComponent::`vftable{for `UFG::UpdateInterface};
  this->mRippleGenerator = 0i64;
  this->mBody = body;
  *(_QWORD *)&this->mInWaterState = 0i64;
  *(_QWORD *)&this->mLinearDamping = 0i64;
  this->mSinkRate = -1.0;
  this->mWaterElevation = -0.31400001;
  this->mBuoyancyAction = 0i64;
  this->mGenerateSplash = 1;
  this->mOnEnterWaterCallback = 0i64;
  this->mOnExitWaterCallback = 0i64;
  this->mCallbackObject = 0i64;
  mPrev = UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList.mNode.mPrev;
  UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent>;
  this->UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent>::mNext = (UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *)&UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList;
  UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList.mNode.mPrev = &this->UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID,
    "WaterFloatingTrackerComponent");
}

// File Line: 154
// RVA: 0x451A60
void __fastcall UFG::WaterFloatingTrackerComponent::~WaterFloatingTrackerComponent(
        UFG::WaterFloatingTrackerComponent *this)
{
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *v2; // rdi
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *mPrev; // rcx
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *mNext; // rax
  UFG::RippleGenerator *mRippleGenerator; // rcx
  UFG::BuoyancyAction *mBuoyancyAction; // rdx
  UFG::BuoyancyAction *v7; // rcx
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *v8; // rcx
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *v9; // rax

  this->UFG::WaterFloatingTrackerBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterFloatingTrackerComponent::`vftable{for `UFG::SimComponent};
  this->UFG::WaterFloatingTrackerBaseComponent::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::WaterFloatingTrackerComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentpCurrentIterator )
    UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentpCurrentIterator = (UFG::WaterFloatingTrackerComponent *)&this->UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent>::mPrev[-6].mNext;
  v2 = &this->UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent>;
  mPrev = this->UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  mRippleGenerator = this->mRippleGenerator;
  if ( mRippleGenerator )
  {
    UFG::Water::RemoveRippleGenerator(mRippleGenerator);
    this->mRippleGenerator = 0i64;
  }
  mBuoyancyAction = this->mBuoyancyAction;
  if ( mBuoyancyAction )
  {
    UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, mBuoyancyAction);
    v7 = this->mBuoyancyAction;
    if ( v7 )
      v7->vfptr->__vecDelDtor(v7, 1u);
    this->mBuoyancyAction = 0i64;
  }
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::WaterFloatingTrackerBaseComponent::~WaterFloatingTrackerBaseComponent(this);
}

// File Line: 178
// RVA: 0x4557F0
void __fastcall UFG::WaterFloatingTrackerComponent::AddRippler(
        UFG::WaterFloatingTrackerComponent *this,
        __int64 a2,
        __int64 a3)
{
  hkpRigidBody *mBody; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __m128 v6; // xmm0
  __m128 v7[2]; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector2 scale; // [rsp+50h] [rbp+8h] BYREF

  if ( !this->mRippleGenerator )
  {
    mBody = this->mBody;
    if ( mBody )
    {
      m_pTransformNodeComponent = this->m_pSimObject->m_pTransformNodeComponent;
      ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, __m128 *))mBody->m_collidable.m_shape->hkpEntity::hkpWorldObject::vfptr[2].__vecDelDtor)(
        mBody->m_collidable.m_shape,
        &transform,
        a3,
        v7);
      v6 = _mm_sub_ps(v7[1], v7[0]);
      LODWORD(scale.x) = v6.m128_i32[0];
      LODWORD(scale.y) = _mm_shuffle_ps(v6, v6, 85).m128_u32[0];
      this->mRippleGenerator = UFG::Water::AddRippleGenerator(
                                 (UFG::qNode<UFG::RippleGenerator,UFG::RippleGenerator> *)m_pTransformNodeComponent,
                                 &scale);
    }
  }
}

// File Line: 197
// RVA: 0x456130
// local variable allocation has failed, the output may be wrong!
void __fastcall UFG::WaterFloatingTrackerComponent::AdjustRipple(
        UFG::WaterFloatingTrackerComponent *this,
        double a2,
        __int64 a3)
{
  hkpRigidBody *mBody; // rcx
  hkpRigidBody *v5; // rbx
  __m128 v6; // xmm7
  float v7; // xmm8_4
  hkpShape *m_shape; // rcx
  UFG::qVector2 *TargetLocation; // rax
  UFG::RippleGenerator *mRippleGenerator; // rcx
  float v11; // xmm6_4
  hkVector4f b; // [rsp+20h] [rbp-D8h] BYREF
  hkVector4f v13; // [rsp+30h] [rbp-C8h] BYREF
  __int128 v14[2]; // [rsp+40h] [rbp-B8h] BYREF
  int v15; // [rsp+60h] [rbp-98h]
  __int64 v16; // [rsp+68h] [rbp-90h]
  __int64 v17; // [rsp+70h] [rbp-88h]
  __m128 v18[2]; // [rsp+78h] [rbp-80h] BYREF
  char v19[16]; // [rsp+98h] [rbp-60h] BYREF
  float v20; // [rsp+A8h] [rbp-50h]
  int v21; // [rsp+ACh] [rbp-4Ch]
  int v22; // [rsp+B8h] [rbp-40h]
  int v23; // [rsp+D8h] [rbp-20h]
  unsigned __int64 retaddr; // [rsp+128h] [rbp+30h] BYREF
  UFG::qVector2 scale; // [rsp+130h] [rbp+38h] BYREF

  if ( this->mRippleGenerator )
  {
    mBody = this->mBody;
    if ( mBody )
    {
      ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, __m128 *))mBody->m_collidable.m_shape->hkpEntity::hkpWorldObject::vfptr[2].__vecDelDtor)(
        mBody->m_collidable.m_shape,
        &transform,
        a3,
        v18);
      v5 = this->mBody;
      v6 = _mm_sub_ps(v18[1], v18[0]);
      b.m_quad = (__m128)v5->m_motion.m_motionState.m_transform.m_translation;
      b.m_quad.m128_i32[2] = 0;
      v13.m_quad = b.m_quad;
      v7 = (float)(_mm_shuffle_ps(v6, v6, 170).m128_f32[0] * 0.75) + (float)(v6.m128_f32[0] * 0.5);
      *(float *)&a2 = v7;
      b.m_quad = _mm_add_ps(
                   b.m_quad,
                   _mm_mul_ps(
                     _mm_shuffle_ps(*(__m128 *)&a2, *(__m128 *)&a2, 0),
                     v5->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad));
      hkVector4f::setTransformedInversePos(&b, &v5->m_motion.m_motionState.m_transform, &b);
      hkVector4f::setTransformedInversePos(&v13, &v5->m_motion.m_motionState.m_transform, &v13);
      m_shape = this->mBody->m_collidable.m_shape;
      v20 = 1.0;
      v14[0] = (__int128)b.m_quad;
      v14[1] = (__int128)v13.m_quad;
      v15 = 0;
      v16 = 0i64;
      v17 = 0i64;
      v18[0].m128_u64[0] = 0i64;
      v21 = -1;
      v23 = 0;
      v22 = -1;
      if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShape *, unsigned __int64 *, __int128 *, char *))m_shape->vfptr[2].__first_virtual_table_function__)(
                       m_shape,
                       &retaddr,
                       v14,
                       v19) )
      {
        TargetLocation = UFG::RoadNetworkGuide::GetTargetLocation(this->mRippleGenerator);
        mRippleGenerator = this->mRippleGenerator;
        scale.y = TargetLocation->y;
        v11 = (float)((float)(1.0 - v20) * v7) * 2.0;
        retaddr = COERCE_UNSIGNED_INT((float)(v6.m128_f32[0] - v11) * -0.5);
        scale.x = v11 + 0.1;
        UFG::Water::ModifyRippleGeneratorScale(mRippleGenerator, &scale, (UFG::qVector2 *)&retaddr);
      }
    }
  }
}

// File Line: 242
// RVA: 0x476530
void __fastcall UFG::WaterFloatingTrackerComponent::Suspend(UFG::WaterFloatingTrackerComponent *this)
{
  unsigned __int16 m_Flags; // cx
  UFG::BuoyancyAction *mBuoyancyAction; // rdx
  UFG::RippleGenerator *mRippleGenerator; // rcx

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0 )
  {
    mBuoyancyAction = this->mBuoyancyAction;
    this->m_Flags = m_Flags | 2;
    if ( mBuoyancyAction )
      UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, mBuoyancyAction);
    if ( this->mInWaterState == 1 )
    {
      mRippleGenerator = this->mRippleGenerator;
      if ( mRippleGenerator )
        UFG::Water::RemoveRippleGenerator(mRippleGenerator);
    }
  }
}

// File Line: 262
// RVA: 0x474010
void __fastcall UFG::WaterFloatingTrackerComponent::Restore(
        UFG::WaterFloatingTrackerComponent *this,
        __int64 a2,
        __int64 a3)
{
  unsigned __int16 m_Flags; // cx
  UFG::BuoyancyAction *mBuoyancyAction; // rdx

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) != 0 )
  {
    mBuoyancyAction = this->mBuoyancyAction;
    this->m_Flags = m_Flags & 0xFFFD;
    if ( mBuoyancyAction && !mBuoyancyAction->m_world )
      UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, mBuoyancyAction);
    if ( this->mInWaterState == 1 )
      UFG::WaterFloatingTrackerComponent::AddRippler(this, (__int64)mBuoyancyAction, a3);
  }
}

// File Line: 282
// RVA: 0x460940
void __fastcall UFG::WaterFloatingTrackerComponent::Deflate(UFG::WaterFloatingTrackerComponent *this)
{
  UFG::BuoyancyAction *mBuoyancyAction; // rdx
  UFG::BuoyancyAction *v3; // rcx
  UFG::RippleGenerator *mRippleGenerator; // rcx

  mBuoyancyAction = this->mBuoyancyAction;
  if ( mBuoyancyAction )
  {
    UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, mBuoyancyAction);
    v3 = this->mBuoyancyAction;
    if ( v3 )
      v3->vfptr->__vecDelDtor(v3, 1u);
    this->mBuoyancyAction = 0i64;
  }
  mRippleGenerator = this->mRippleGenerator;
  if ( mRippleGenerator )
  {
    UFG::Water::RemoveRippleGenerator(mRippleGenerator);
    this->mRippleGenerator = 0i64;
  }
  this->mBody = 0i64;
}

// File Line: 303
// RVA: 0x468C50
void __fastcall UFG::WaterFloatingTrackerComponent::Inflate(
        UFG::WaterFloatingTrackerComponent *this,
        hkpRigidBody *newBody,
        __int64 a3)
{
  _QWORD **Value; // rax
  UFG::BuoyancyAction *v5; // rax

  this->mBody = newBody;
  if ( this->mInWaterState > 0 && this->mSinkRate >= 0.0 )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (UFG::BuoyancyAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 336i64);
    if ( v5 )
      UFG::BuoyancyAction::BuoyancyAction(
        v5,
        this->mBody,
        this->mWaterElevation,
        this->mBuoyancyFactor,
        this->mLinearDamping,
        this->mAngularDamping,
        this->mSinkRate);
    this->mBuoyancyAction = v5;
    UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, v5);
  }
  if ( this->mInWaterState == 1 )
    UFG::WaterFloatingTrackerComponent::AddRippler(this, (__int64)newBody, a3);
}

// File Line: 322
// RVA: 0x463DF0
void __fastcall UFG::WaterFloatingTrackerComponent::EnableBuoyancyManagment(
        UFG::WaterFloatingTrackerComponent *this,
        float buoyancyFactor,
        float linearDamping,
        float angularDamping,
        float sinkRate)
{
  this->mBuoyancyFactor = buoyancyFactor;
  this->mLinearDamping = linearDamping;
  this->mSinkRate = sinkRate;
  this->mAngularDamping = angularDamping;
}

// File Line: 333
// RVA: 0x461EA0
void __fastcall UFG::WaterFloatingTrackerComponent::DisableSplashGeneration(UFG::WaterFloatingTrackerComponent *this)
{
  this->mGenerateSplash = 0;
}

// File Line: 341
// RVA: 0x46AFA0
_BOOL8 __fastcall UFG::WaterFloatingTrackerComponent::IsInWater(UFG::WaterFloatingTrackerComponent *this)
{
  return this->mInWaterState > 0;
}

// File Line: 348
// RVA: 0x46B4F0
bool __fastcall UFG::WaterFloatingTrackerComponent::IsSunk(UFG::WaterFloatingTrackerComponent *this)
{
  return this->mInWaterState == 2;
}

// File Line: 353
// RVA: 0x46B4D0
bool __fastcall UFG::WaterFloatingTrackerComponent::IsSubmerged(UFG::WaterFloatingTrackerComponent *this, float value)
{
  UFG::BuoyancyAction *mBuoyancyAction; // rdx
  bool result; // al

  mBuoyancyAction = this->mBuoyancyAction;
  result = 0;
  if ( mBuoyancyAction )
    return value <= mBuoyancyAction->mSubmergedPercent;
  return result;
}

// File Line: 361
// RVA: 0x46EB50
void __fastcall UFG::WaterFloatingTrackerComponent::OnEnterWater(
        UFG::WaterFloatingTrackerComponent *this,
        __int64 a2,
        __int64 a3)
{
  void (__fastcall *mOnEnterWaterCallback)(void *); // rax
  _QWORD **Value; // rax
  UFG::BuoyancyAction *v6; // rax
  __int64 v7; // r8

  mOnEnterWaterCallback = this->mOnEnterWaterCallback;
  if ( mOnEnterWaterCallback )
    mOnEnterWaterCallback(this->mCallbackObject);
  if ( this->mSinkRate >= 0.0 )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (UFG::BuoyancyAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 336i64);
    if ( v6 )
      UFG::BuoyancyAction::BuoyancyAction(
        v6,
        this->mBody,
        this->mWaterElevation,
        this->mBuoyancyFactor,
        this->mLinearDamping,
        this->mAngularDamping,
        this->mSinkRate);
    this->mBuoyancyAction = v6;
    UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, v6);
  }
  UFG::WaterFloatingTrackerComponent::AddRippler(this, a2, a3);
  if ( this->mGenerateSplash )
    UFG::GenerateSplash(this->mBody, this->mWaterElevation, v7);
  this->mInWaterState = 1;
}

// File Line: 385
// RVA: 0x46EC50
void __fastcall UFG::WaterFloatingTrackerComponent::OnExitWater(UFG::WaterFloatingTrackerComponent *this)
{
  void (__fastcall *mOnExitWaterCallback)(void *); // rax
  UFG::RippleGenerator *mRippleGenerator; // rcx
  UFG::BuoyancyAction *mBuoyancyAction; // rdx
  UFG::BuoyancyAction *v5; // rcx

  mOnExitWaterCallback = this->mOnExitWaterCallback;
  if ( mOnExitWaterCallback )
    mOnExitWaterCallback(this->mCallbackObject);
  mRippleGenerator = this->mRippleGenerator;
  if ( mRippleGenerator )
  {
    UFG::Water::RemoveRippleGenerator(mRippleGenerator);
    this->mRippleGenerator = 0i64;
  }
  mBuoyancyAction = this->mBuoyancyAction;
  if ( mBuoyancyAction )
  {
    UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, mBuoyancyAction);
    v5 = this->mBuoyancyAction;
    if ( v5 )
      v5->vfptr->__vecDelDtor(v5, 1u);
    this->mBuoyancyAction = 0i64;
  }
  this->mInWaterState = 0;
}

// File Line: 413
// RVA: 0x46F6F0
void __fastcall UFG::WaterFloatingTrackerComponent::OnSunk(UFG::WaterFloatingTrackerComponent *this)
{
  UFG::RippleGenerator *mRippleGenerator; // rcx

  mRippleGenerator = this->mRippleGenerator;
  if ( mRippleGenerator )
  {
    UFG::Water::RemoveRippleGenerator(mRippleGenerator);
    this->mRippleGenerator = 0i64;
  }
  this->mInWaterState = 2;
}

// File Line: 435
// RVA: 0x47DC40
void __fastcall UFG::WaterFloatingTrackerComponent::Update(UFG::WaterFloatingTrackerComponent *this, float deltaTime)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rbp
  bool v4; // r13
  int mPrev_high; // xmm6_4
  __m128 v6; // xmm4
  __m128 v7; // xmm4
  __m128 v8; // xmm0
  UFG::BasePhysicsSystem *v9; // rbx
  char v10; // r12
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v11; // r14
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> **p_mNext; // r8
  bool i; // zf
  __int64 v14; // r10
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *j; // rax
  __int64 v17; // rdx
  int v18; // r9d
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v19; // rax
  char v20; // r15
  __int128 v21; // xmm1
  __int128 v22; // xmm2
  __int128 v23; // xmm3
  __int64 v24; // rdx
  __int64 v25; // r8
  int mNext; // eax
  char v27; // cl
  UFG::WaterPhantomComponent *v28; // rbx
  __int64 v29; // rdi
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v32; // rax
  hkVector4f start; // [rsp+20h] [rbp-C8h] BYREF
  __int64 v34; // [rsp+30h] [rbp-B8h]
  __m128 v35; // [rsp+40h] [rbp-A8h] BYREF
  float v36; // [rsp+58h] [rbp-90h]
  hkVector4f end; // [rsp+60h] [rbp-88h] BYREF
  __int128 v38[5]; // [rsp+70h] [rbp-78h] BYREF

  v34 = -2i64;
  mPrev = this->m_BoundComponentHandles.mNode.UFG::WaterFloatingTrackerBaseComponent::UFG::SimComponent::mPrev;
  if ( mPrev )
  {
    v4 = SLODWORD(this->m_BoundComponentHandles.mNode.mNext) > 0;
    mPrev_high = HIDWORD(this->UFG::WaterFloatingTrackerBaseComponent::UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent>::mPrev);
    if ( this->UFG::WaterFloatingTrackerBaseComponent::UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent>::mNext )
    {
      if ( hkpRigidBody::isDeactivationEnabled((hkpRigidBody *)this->m_BoundComponentHandles.mNode.UFG::WaterFloatingTrackerBaseComponent::UFG::SimComponent::mPrev) )
        hkpRigidBody::enableDeactivation((hkpRigidBody *)mPrev, 0);
      v6 = _mm_mul_ps((__m128)mPrev[26], (__m128)mPrev[26]);
      v7 = _mm_add_ps(_mm_shuffle_ps(v6, v6, 170), _mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)));
      v8 = _mm_rsqrt_ps(v7);
      v9 = UFG::BasePhysicsSystem::mInstance;
      v8.m128_f32[0] = fmodf(
                         (float)(_mm_andnot_ps(
                                   _mm_cmple_ps(v7, (__m128)0i64),
                                   _mm_mul_ps(
                                     v7,
                                     _mm_mul_ps(
                                       _mm_mul_ps(*(__m128 *)_xmm, v8),
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8))))).m128_f32[0]
                               * *((float *)&UFG::BasePhysicsSystem::mInstance[1].mWorld + 1))
                       + *(float *)&UFG::BasePhysicsSystem::mInstance[1].mBroadPhaseBorder,
                         6.2800002);
      *((float *)&this->UFG::WaterFloatingTrackerBaseComponent::UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent>::mPrev
      + 1) = (float)((float)(cosf(v8.m128_f32[0]) * *(float *)&v9[1].mConstraintsToAdd.m_capacityAndFlags)
                   + *(float *)&v9[1].mConstraintsToAdd.m_size)
           - 0.31400001;
    }
    v10 = 0;
    v11 = (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)((char *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList
                                                                              - 104);
    p_mNext = &UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mNext[-7].mNext;
    for ( i = &UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mNext[-7].mNext == (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> **)((char *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList - 104);
          !i;
          i = v14 == (_QWORD)v11 )
    {
      v14 = (__int64)&p_mNext[14][-7].mNext;
      if ( (*((_BYTE *)p_mNext + 724) & 1) != 0 )
      {
        v15 = mPrev + 2;
        for ( j = mPrev[3].mNext; j; j = j[1].mNext )
          v15 = j;
        v17 = 0i64;
        v18 = *((_DWORD *)p_mNext + 50);
        if ( v18 > 0 )
        {
          v19 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)p_mNext[24];
          while ( *v19 != v15 && v19[2] != v15 )
          {
            v17 = (unsigned int)(v17 + 1);
            v19 += 4;
            if ( (int)v17 >= v18 )
              goto LABEL_16;
          }
          v10 = 1;
          HIDWORD(this->UFG::WaterFloatingTrackerBaseComponent::UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent>::mPrev) = *((_DWORD *)p_mNext + 180);
          if ( !v4 )
            UFG::WaterFloatingTrackerComponent::OnEnterWater(
              (UFG::WaterFloatingTrackerComponent *)((char *)this - 64),
              v17,
              (__int64)p_mNext);
          break;
        }
      }
LABEL_16:
      p_mNext = &p_mNext[14][-7].mNext;
    }
    v20 = 0;
    if ( !v10 )
    {
      v21 = (__int128)mPrev[24];
      v22 = (__int128)mPrev[25];
      v23 = (__int128)mPrev[26];
      v38[0] = (__int128)mPrev[23];
      v38[1] = v21;
      v38[2] = v22;
      v38[3] = v23;
      ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, __int128 *, UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> **, __m128 *))mPrev[2].mPrev->mPrev[2].mPrev)(
        mPrev[2].mPrev,
        v38,
        p_mNext,
        &v35);
      if ( (_S18_1 & 1) == 0 )
      {
        _S18_1 |= 1u;
        waterCheckBeam.m_quad = (__m128)_xmm;
      }
      if ( v35.m128_f32[2] < -0.31400001 )
      {
        mNext = (int)this->m_BoundComponentHandles.mNode.mNext;
        if ( mNext > 0 )
        {
          v20 = 1;
          if ( v36 >= -1.0 )
          {
            if ( mNext == 2 )
            {
              UFG::WaterFloatingTrackerComponent::AddRippler(
                (UFG::WaterFloatingTrackerComponent *)((char *)this - 64),
                v24,
                v25);
              LODWORD(this->m_BoundComponentHandles.mNode.mNext) = 1;
            }
          }
          else
          {
            UFG::WaterFloatingTrackerComponent::OnSunk((UFG::WaterFloatingTrackerComponent *)((char *)this - 64));
          }
        }
        else
        {
          v27 = 0;
          v28 = (UFG::WaterPhantomComponent *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mNext[-7].mNext;
          if ( (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)((char *)UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mNext
                                                                                   - 104) != v11 )
          {
            do
            {
              v29 = (__int64)&v28->mNext[-7].mNext;
              if ( (*((_BYTE *)v28 + 724) & 1) == 0 )
              {
                v30 = _mm_or_ps(
                        _mm_andnot_ps((__m128)xmmword_141792890, (__m128)mPrev[26]),
                        _mm_and_ps(v35, (__m128)xmmword_141792890));
                v31 = _mm_add_ps(v30, waterCheckBeam.m_quad);
                start.m_quad = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, waterCheckBeam.m_quad), 196);
                end.m_quad = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, waterCheckBeam.m_quad), 196);
                if ( v27 || UFG::WaterPhantomComponent::IntersectRay(v28, &start, &end) )
                {
                  v27 = 1;
                  HIDWORD(this->UFG::WaterFloatingTrackerBaseComponent::UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent>::mPrev) = LODWORD(v28->mElevation);
                }
                else
                {
                  v27 = 0;
                }
              }
              v28 = (UFG::WaterPhantomComponent *)v29;
            }
            while ( (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)v29 != v11 );
            if ( v27 )
            {
              UFG::WaterFloatingTrackerComponent::OnEnterWater(
                (UFG::WaterFloatingTrackerComponent *)((char *)this - 64),
                v24,
                v25);
              v20 = 1;
            }
          }
        }
      }
    }
    if ( v4 && !v10 && !v20 )
      UFG::WaterFloatingTrackerComponent::OnExitWater((UFG::WaterFloatingTrackerComponent *)((char *)this - 64));
    v32 = this->UFG::WaterFloatingTrackerBaseComponent::UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent>::mNext;
    if ( v32 )
      LODWORD(v32[19].mPrev) = mPrev_high;
  }
}

