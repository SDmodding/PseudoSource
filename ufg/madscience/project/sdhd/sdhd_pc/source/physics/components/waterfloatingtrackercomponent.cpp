// File Line: 34
// RVA: 0x465BD0
void __fastcall UFG::GenerateSplash(hkpRigidBody *body, float waterElevation, __int64 a3)
{
  hkpRigidBody *v3; // rbx
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
  __m128 v16; // xmm8
  __m128 v17; // xmm2
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  __int128 v22; // xmm11
  __m128 v23; // xmm8
  float v24; // xmm6_4
  __m128 v25; // xmm2
  float v26; // xmm1_4
  float v27; // xmm8_4
  float v28; // xmm2_4
  __m128 v29; // xmm12
  float v30; // xmm8_4
  __m128 v31; // xmm5
  float v32; // xmm3_4
  float v33; // xmm2_4
  unsigned int v34; // er8
  UFG::qBaseTreeRB *v35; // rax
  unsigned int v36; // edx
  float v37; // [rsp+40h] [rbp-B8h]
  float v38; // [rsp+44h] [rbp-B4h]
  float v39; // [rsp+48h] [rbp-B0h]
  float v40; // [rsp+50h] [rbp-A8h]
  float v41; // [rsp+54h] [rbp-A4h]
  float v42; // [rsp+58h] [rbp-A0h]
  UFG::qMatrix44 basis; // [rsp+60h] [rbp-98h]
  float v44; // [rsp+150h] [rbp+58h]

  v3 = body;
  v4 = _S17_2;
  if ( !(_S17_2 & 1) )
  {
    _S17_2 |= 1u;
    impactType = UFG::qStringHashUpper32("WaterSplash", 0xFFFFFFFF);
    v4 = _S17_2;
  }
  if ( !(v4 & 2) )
  {
    _S17_2 = v4 | 2;
    materialType_Low = UFG::qStringHashUpper32("SplashForce_Low", 0xFFFFFFFF);
    v4 = _S17_2;
  }
  if ( !(v4 & 4) )
  {
    _S17_2 = v4 | 4;
    materialType_Med = UFG::qStringHashUpper32("SplashForce_Med", 0xFFFFFFFF);
    v4 = _S17_2;
  }
  if ( !(v4 & 8) )
  {
    _S17_2 = v4 | 8;
    materialType_High = UFG::qStringHashUpper32("SplashForce_High", 0xFFFFFFFF);
  }
  v5 = v3->m_motion.m_linearVelocity.m_quad.m128_f32[0];
  v6 = (__m128)v3->m_motion.m_linearVelocity.m_quad.m128_u32[1];
  v7 = v3->m_motion.m_linearVelocity.m_quad.m128_f32[2];
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
    v10 = v3->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[0] + v9;
    v11 = v6.m128_f32[0] * 0.5;
    if ( (float)(v6.m128_f32[0] * 0.5) <= -1.0 )
    {
      v11 = FLOAT_N1_0;
    }
    else if ( v11 >= 1.0 )
    {
      v11 = *(float *)&FLOAT_1_0;
    }
    v12 = v3->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[1] + v11;
    if ( v8.m128_f32[0] == 0.0 )
    {
      v13 = 0i64;
    }
    else
    {
      v13 = (unsigned int)FLOAT_1_0;
      *(float *)&v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v8));
    }
    v14 = v13;
    *(float *)&v14 = *(float *)&v13 * v5;
    v15 = *(float *)&v13 * v6.m128_f32[0];
    *(float *)&v13 = *(float *)&v13 * 0.0;
    LODWORD(basis.v0.x) = v14;
    basis.v0.y = v15;
    LODWORD(basis.v0.z) = v13;
    basis.v0.w = 0.0;
    v16 = (__m128)LODWORD(UFG::qVector3::msAxisZ.x);
    v17 = v16;
    v17.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0])
                            + (float)(UFG::qVector3::msAxisZ.y * UFG::qVector3::msAxisZ.y))
                    + (float)(UFG::qVector3::msAxisZ.z * UFG::qVector3::msAxisZ.z);
    if ( v17.m128_f32[0] == 0.0 )
      v18 = 0.0;
    else
      v18 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v17));
    v19 = v18 * UFG::qVector3::msAxisZ.x;
    v20 = v18 * UFG::qVector3::msAxisZ.y;
    v21 = v18 * UFG::qVector3::msAxisZ.z;
    v22 = v13;
    *(float *)&v22 = (float)(*(float *)&v13 * v20) - (float)(v15 * v21);
    v23 = (__m128)v14;
    v23.m128_f32[0] = (float)(*(float *)&v14 * v21) - (float)(*(float *)&v13 * v19);
    v24 = (float)(v15 * v19) - (float)(*(float *)&v14 * v20);
    v25 = v23;
    v25.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(*(float *)&v22 * *(float *)&v22))
                    + (float)(v24 * v24);
    if ( v25.m128_f32[0] == 0.0 )
      v26 = 0.0;
    else
      v26 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v25));
    *(float *)&v22 = *(float *)&v22 * v26;
    v27 = v23.m128_f32[0] * v26;
    LODWORD(basis.v1.x) = v22;
    basis.v1.y = v27;
    basis.v1.w = 0.0;
    v28 = (float)((float)(v24 * v26) * v15) - (float)(v27 * *(float *)&v13);
    v29 = (__m128)v22;
    v29.m128_f32[0] = (float)(*(float *)&v22 * *(float *)&v13) - (float)((float)(v24 * v26) * *(float *)&v14);
    v30 = (float)(v27 * *(float *)&v14) - (float)(*(float *)&v22 * v15);
    v31 = v29;
    v31.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v28 * v28)) + (float)(v30 * v30);
    if ( v31.m128_f32[0] == 0.0 )
      v32 = 0.0;
    else
      v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
    basis.v1.z = v28 * v32;
    basis.v1.w = v29.m128_f32[0] * v32;
    basis.v2.x = v30 * v32;
    basis.v2.y = 0.0;
    basis.v2.z = v10;
    basis.v2.w = v12;
    basis.v3.y = 1.0;
    basis.v3.x = v44;
    ((void (__fastcall *)(hkpShape *, hkMotionState *, __int64, float *))v3->m_collidable.m_shape->vfptr[2].__vecDelDtor)(
      v3->m_collidable.m_shape,
      &v3->m_motion.m_motionState,
      a3,
      &v37);
    v33 = (float)((float)((float)((float)(v41 - v38) * (float)(v40 - v37)) * (float)(v42 - v39)) * v7) * -1.0;
    if ( v33 >= 5.0 )
    {
      v34 = materialType_High;
      if ( v33 < 15.0 )
        v34 = materialType_Med;
    }
    else
    {
      v34 = materialType_Low;
    }
    v35 = Render::ImpactManager::GetImpactDesc(&Render::gImpactManager, impactType, v34);
    if ( v35 )
    {
      v36 = (unsigned int)v35->mNULL.mParent;
      if ( v36 != -1 )
        Render::FXManager::CreateEffect(&Render::gFXManager, v36, &basis, 0xFFFFFFFF);
    }
  }
}

// File Line: 112
// RVA: 0x1514410
__int64 dynamic_initializer_for__UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList__);
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gFloatingTrackerComponentName__);
}

// File Line: 121
// RVA: 0x458810
UFG::SimComponent *__fastcall UFG::AquireWaterFloatingTrackerComponent(UFG::SimObject *obj, hkpRigidBody *body)
{
  hkpRigidBody *v2; // rbx
  UFG::SimObject *v3; // rsi
  UFG::qMemoryPool *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // rdi
  unsigned __int16 v8; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v2 = body;
  v3 = obj;
  v4 = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(v4, 0xB8ui64, "WaterFloatingTrackerComponent", 0i64, 1u);
  if ( v5 )
  {
    UFG::WaterFloatingTrackerComponent::WaterFloatingTrackerComponent(
      (UFG::WaterFloatingTrackerComponent *)v5,
      UFG::gFloatingTrackerComponentName.mUID,
      v2);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v3->m_Flags;
  if ( (v8 >> 14) & 1 || (v8 & 0x8000u) == 0 )
    v9 = -1;
  else
    v9 = 35;
  UFG::SimObjectModifier::SimObjectModifier(&v11, v3, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v7, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return v7;
}

// File Line: 146
// RVA: 0x44E510
void __fastcall UFG::WaterFloatingTrackerComponent::WaterFloatingTrackerComponent(UFG::WaterFloatingTrackerComponent *this, unsigned int name_uid, hkpRigidBody *body)
{
  hkpRigidBody *v3; // rbx
  UFG::WaterFloatingTrackerComponent *v4; // rdi
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *v5; // rdx
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *v6; // rax

  v3 = body;
  v4 = this;
  UFG::WaterFloatingTrackerBaseComponent::WaterFloatingTrackerBaseComponent(
    (UFG::WaterFloatingTrackerBaseComponent *)&this->vfptr,
    name_uid,
    body);
  v5 = (UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterFloatingTrackerComponent::`vftable{for `UFG::SimComponent};
  v4->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::WaterFloatingTrackerComponent::`vftable{for `UFG::UpdateInterface};
  v4->mRippleGenerator = 0i64;
  v4->mBody = v3;
  *(_QWORD *)&v4->mInWaterState = 0i64;
  *(_QWORD *)&v4->mLinearDamping = 0i64;
  v4->mSinkRate = -1.0;
  v4->mWaterElevation = -0.31400001;
  v4->mBuoyancyAction = 0i64;
  v4->mGenerateSplash = 1;
  v4->mOnEnterWaterCallback = 0i64;
  v4->mOnExitWaterCallback = 0i64;
  v4->mCallbackObject = 0i64;
  v6 = UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList.mNode.mPrev;
  UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *)&UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList;
  UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentList.mNode.mPrev = (UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::WaterFloatingTrackerComponent::_WaterFloatingTrackerComponentTypeUID,
    "WaterFloatingTrackerComponent");
}

// File Line: 154
// RVA: 0x451A60
void __fastcall UFG::WaterFloatingTrackerComponent::~WaterFloatingTrackerComponent(UFG::WaterFloatingTrackerComponent *this)
{
  UFG::WaterFloatingTrackerComponent *v1; // rbx
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *v2; // rdi
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *v3; // rcx
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *v4; // rax
  UFG::RippleGenerator *v5; // rcx
  hkpAction *v6; // rdx
  UFG::BuoyancyAction *v7; // rcx
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *v8; // rcx
  UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::WaterFloatingTrackerComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::WaterFloatingTrackerComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentpCurrentIterator )
    UFG::WaterFloatingTrackerComponent::s_WaterFloatingTrackerComponentpCurrentIterator = (UFG::WaterFloatingTrackerComponent *)&this->mPrev[-6].mNext;
  v2 = (UFG::qNode<UFG::WaterFloatingTrackerComponent,UFG::WaterFloatingTrackerComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mRippleGenerator;
  if ( v5 )
  {
    UFG::Water::RemoveRippleGenerator(v5);
    v1->mRippleGenerator = 0i64;
  }
  v6 = (hkpAction *)&v1->mBuoyancyAction->vfptr;
  if ( v6 )
  {
    UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, v6);
    v7 = v1->mBuoyancyAction;
    if ( v7 )
      v7->vfptr->__vecDelDtor((hkBaseObject *)&v7->vfptr, 1u);
    v1->mBuoyancyAction = 0i64;
  }
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::WaterFloatingTrackerBaseComponent::~WaterFloatingTrackerBaseComponent((UFG::WaterFloatingTrackerBaseComponent *)&v1->vfptr);
}

// File Line: 178
// RVA: 0x4557F0
void __fastcall UFG::WaterFloatingTrackerComponent::AddRippler(UFG::WaterFloatingTrackerComponent *this, __int64 a2, __int64 a3)
{
  UFG::WaterFloatingTrackerComponent *v3; // rdi
  hkpRigidBody *v4; // rcx
  UFG::TransformNodeComponent *v5; // rbx
  __m128 v6; // xmm0
  __m128 v7; // [rsp+20h] [rbp-28h]
  __m128 v8; // [rsp+30h] [rbp-18h]
  UFG::qVector2 scale; // [rsp+50h] [rbp+8h]

  v3 = this;
  if ( !this->mRippleGenerator )
  {
    v4 = this->mBody;
    if ( v4 )
    {
      v5 = v3->m_pSimObject->m_pTransformNodeComponent;
      ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, __m128 *))v4->m_collidable.m_shape->vfptr[2].__vecDelDtor)(
        v4->m_collidable.m_shape,
        &transform,
        a3,
        &v7);
      v6 = _mm_sub_ps(v8, v7);
      LODWORD(scale.x) = v6.m128_i32[0];
      LODWORD(scale.y) = (unsigned __int128)_mm_shuffle_ps(v6, v6, 85);
      v3->mRippleGenerator = (UFG::RippleGenerator *)UFG::Water::AddRippleGenerator(v5, &scale);
    }
  }
}

// File Line: 197
// RVA: 0x456130
int UFG::WaterFloatingTrackerComponent::AdjustRipple(...)
{
  UFG::WaterFloatingTrackerComponent *v3; // rdi
  hkpRigidBody *v4; // rcx
  hkpRigidBody *v5; // rbx
  __m128 v6; // xmm7
  float v7; // xmm8_4
  hkpShape *v8; // rcx
  UFG::qVector2 *v9; // rax
  UFG::RippleGenerator *v10; // rcx
  float v11; // xmm6_4
  hkVector4f b; // [rsp+20h] [rbp-D8h]
  hkVector4f v13; // [rsp+30h] [rbp-C8h]
  __m128 v14; // [rsp+40h] [rbp-B8h]
  __m128 v15; // [rsp+50h] [rbp-A8h]
  int v16; // [rsp+60h] [rbp-98h]
  __int64 v17; // [rsp+68h] [rbp-90h]
  __int64 v18; // [rsp+70h] [rbp-88h]
  __m128 v19; // [rsp+78h] [rbp-80h]
  __m128 v20; // [rsp+88h] [rbp-70h]
  char v21; // [rsp+98h] [rbp-60h]
  float v22; // [rsp+A8h] [rbp-50h]
  int v23; // [rsp+ACh] [rbp-4Ch]
  int v24; // [rsp+B8h] [rbp-40h]
  int v25; // [rsp+D8h] [rbp-20h]
  unsigned __int64 retaddr; // [rsp+128h] [rbp+30h]
  UFG::qVector2 scale; // [rsp+130h] [rbp+38h]

  v3 = this;
  if ( this->mRippleGenerator )
  {
    v4 = this->mBody;
    if ( v4 )
    {
      ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, __m128 *))v4->m_collidable.m_shape->vfptr[2].__vecDelDtor)(
        v4->m_collidable.m_shape,
        &transform,
        a3,
        &v19);
      v5 = v3->mBody;
      v6 = _mm_sub_ps(v20, v19);
      b.m_quad = (__m128)v5->m_motion.m_motionState.m_transform.m_translation;
      b.m_quad.m128_i32[2] = 0;
      v13.m_quad = b.m_quad;
      v7 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 170)) * 0.75) + (float)(v6.m128_f32[0] * 0.5);
      a2.m128_f32[0] = v7;
      b.m_quad = _mm_add_ps(
                   b.m_quad,
                   _mm_mul_ps(
                     _mm_shuffle_ps(a2, a2, 0),
                     v5->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad));
      hkVector4f::setTransformedInversePos(&b, &v5->m_motion.m_motionState.m_transform, &b);
      hkVector4f::setTransformedInversePos(&v13, &v5->m_motion.m_motionState.m_transform, &v13);
      v8 = v3->mBody->m_collidable.m_shape;
      v22 = 1.0;
      v14 = b.m_quad;
      v15 = v13.m_quad;
      v16 = 0;
      v17 = 0i64;
      v18 = 0i64;
      v19.m128_u64[0] = 0i64;
      v23 = -1;
      v25 = 0;
      v24 = -1;
      if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShape *, unsigned __int64 *, __m128 *, char *))v8->vfptr[2].__first_virtual_table_function__)(
                       v8,
                       &retaddr,
                       &v14,
                       &v21) )
      {
        v9 = UFG::RoadNetworkGuide::GetTargetLocation(v3->mRippleGenerator);
        v10 = v3->mRippleGenerator;
        scale.y = v9->y;
        v11 = (float)((float)(1.0 - v22) * v7) * 2.0;
        retaddr = COERCE_UNSIGNED_INT((float)(v6.m128_f32[0] - v11) * -0.5);
        scale.x = v11 + 0.1;
        UFG::Water::ModifyRippleGeneratorScale(v10, &scale, (UFG::qVector2 *)&retaddr);
      }
    }
  }
}

// File Line: 242
// RVA: 0x476530
void __fastcall UFG::WaterFloatingTrackerComponent::Suspend(UFG::WaterFloatingTrackerComponent *this)
{
  UFG::WaterFloatingTrackerComponent *v1; // rbx
  unsigned __int16 v2; // cx
  hkpAction *v3; // rdx
  UFG::RippleGenerator *v4; // rcx

  v1 = this;
  v2 = this->m_Flags;
  if ( !(((unsigned __int8)v2 >> 1) & 1) )
  {
    v3 = (hkpAction *)&v1->mBuoyancyAction->vfptr;
    v1->m_Flags = v2 | 2;
    if ( v3 )
      UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, v3);
    if ( v1->mInWaterState == 1 )
    {
      v4 = v1->mRippleGenerator;
      if ( v4 )
        UFG::Water::RemoveRippleGenerator(v4);
    }
  }
}

// File Line: 262
// RVA: 0x474010
void __fastcall UFG::WaterFloatingTrackerComponent::Restore(UFG::WaterFloatingTrackerComponent *this, __int64 a2, __int64 a3)
{
  UFG::WaterFloatingTrackerComponent *v3; // rbx
  unsigned __int16 v4; // cx
  hkpAction *v5; // rdx

  v3 = this;
  v4 = this->m_Flags;
  if ( ((unsigned __int8)v4 >> 1) & 1 )
  {
    v5 = (hkpAction *)&v3->mBuoyancyAction->vfptr;
    v3->m_Flags = v4 & 0xFFFD;
    if ( v5 && !v5->m_world )
      UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, v5);
    if ( v3->mInWaterState == 1 )
      UFG::WaterFloatingTrackerComponent::AddRippler(v3, (__int64)v5, a3);
  }
}

// File Line: 282
// RVA: 0x460940
void __fastcall UFG::WaterFloatingTrackerComponent::Deflate(UFG::WaterFloatingTrackerComponent *this)
{
  UFG::BuoyancyAction *v1; // rdx
  UFG::WaterFloatingTrackerComponent *v2; // rbx
  UFG::BuoyancyAction *v3; // rcx
  UFG::RippleGenerator *v4; // rcx

  v1 = this->mBuoyancyAction;
  v2 = this;
  if ( v1 )
  {
    UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, (hkpAction *)&v1->vfptr);
    v3 = v2->mBuoyancyAction;
    if ( v3 )
      v3->vfptr->__vecDelDtor((hkBaseObject *)&v3->vfptr, 1u);
    v2->mBuoyancyAction = 0i64;
  }
  v4 = v2->mRippleGenerator;
  if ( v4 )
  {
    UFG::Water::RemoveRippleGenerator(v4);
    v2->mRippleGenerator = 0i64;
  }
  v2->mBody = 0i64;
}

// File Line: 303
// RVA: 0x468C50
void __fastcall UFG::WaterFloatingTrackerComponent::Inflate(UFG::WaterFloatingTrackerComponent *this, hkpRigidBody *newBody, __int64 a3)
{
  UFG::WaterFloatingTrackerComponent *v3; // rbx
  _QWORD **v4; // rax
  UFG::BuoyancyAction *v5; // rax

  v3 = this;
  this->mBody = newBody;
  if ( this->mInWaterState > 0 && this->mSinkRate >= 0.0 )
  {
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (UFG::BuoyancyAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 336i64);
    if ( v5 )
      UFG::BuoyancyAction::BuoyancyAction(
        v5,
        v3->mBody,
        v3->mWaterElevation,
        v3->mBuoyancyFactor,
        v3->mLinearDamping,
        v3->mAngularDamping,
        v3->mSinkRate);
    v3->mBuoyancyAction = v5;
    UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, (hkpAction *)&v5->vfptr);
  }
  if ( v3->mInWaterState == 1 )
    UFG::WaterFloatingTrackerComponent::AddRippler(v3, (__int64)newBody, a3);
}

// File Line: 322
// RVA: 0x463DF0
void __fastcall UFG::WaterFloatingTrackerComponent::EnableBuoyancyManagment(UFG::WaterFloatingTrackerComponent *this, float buoyancyFactor, float linearDamping, float angularDamping, float sinkRate)
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
bool __fastcall UFG::WaterFloatingTrackerComponent::IsInWater(UFG::WaterFloatingTrackerComponent *this)
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
  UFG::BuoyancyAction *v2; // rdx
  bool result; // al

  v2 = this->mBuoyancyAction;
  result = 0;
  if ( v2 )
    result = value <= v2->mSubmergedPercent;
  return result;
}

// File Line: 361
// RVA: 0x46EB50
void __fastcall UFG::WaterFloatingTrackerComponent::OnEnterWater(UFG::WaterFloatingTrackerComponent *this, __int64 a2, __int64 a3)
{
  UFG::WaterFloatingTrackerComponent *v3; // rbx
  void (__fastcall *v4)(void *); // rax
  _QWORD **v5; // rax
  UFG::BuoyancyAction *v6; // rax
  __int64 v7; // r8

  v3 = this;
  v4 = this->mOnEnterWaterCallback;
  if ( v4 )
    v4(this->mCallbackObject);
  if ( v3->mSinkRate >= 0.0 )
  {
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (UFG::BuoyancyAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 336i64);
    if ( v6 )
      UFG::BuoyancyAction::BuoyancyAction(
        v6,
        v3->mBody,
        v3->mWaterElevation,
        v3->mBuoyancyFactor,
        v3->mLinearDamping,
        v3->mAngularDamping,
        v3->mSinkRate);
    v3->mBuoyancyAction = v6;
    UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, (hkpAction *)&v6->vfptr);
  }
  UFG::WaterFloatingTrackerComponent::AddRippler(v3, a2, a3);
  if ( v3->mGenerateSplash )
    UFG::GenerateSplash(v3->mBody, v3->mWaterElevation, v7);
  v3->mInWaterState = 1;
}

// File Line: 385
// RVA: 0x46EC50
void __fastcall UFG::WaterFloatingTrackerComponent::OnExitWater(UFG::WaterFloatingTrackerComponent *this)
{
  void (__fastcall *v1)(void *); // rax
  UFG::WaterFloatingTrackerComponent *v2; // rbx
  UFG::RippleGenerator *v3; // rcx
  hkpAction *v4; // rdx
  UFG::BuoyancyAction *v5; // rcx

  v1 = this->mOnExitWaterCallback;
  v2 = this;
  if ( v1 )
    v1(this->mCallbackObject);
  v3 = v2->mRippleGenerator;
  if ( v3 )
  {
    UFG::Water::RemoveRippleGenerator(v3);
    v2->mRippleGenerator = 0i64;
  }
  v4 = (hkpAction *)&v2->mBuoyancyAction->vfptr;
  if ( v4 )
  {
    UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, v4);
    v5 = v2->mBuoyancyAction;
    if ( v5 )
      v5->vfptr->__vecDelDtor((hkBaseObject *)&v5->vfptr, 1u);
    v2->mBuoyancyAction = 0i64;
  }
  v2->mInWaterState = 0;
}

// File Line: 413
// RVA: 0x46F6F0
void __fastcall UFG::WaterFloatingTrackerComponent::OnSunk(UFG::WaterFloatingTrackerComponent *this)
{
  UFG::WaterFloatingTrackerComponent *v1; // rbx
  UFG::RippleGenerator *v2; // rcx

  v1 = this;
  v2 = this->mRippleGenerator;
  if ( v2 )
  {
    UFG::Water::RemoveRippleGenerator(v2);
    v1->mRippleGenerator = 0i64;
  }
  v1->mInWaterState = 2;
}

// File Line: 435
// RVA: 0x47DC40
void __fastcall UFG::WaterFloatingTrackerComponent::Update(UFG::WaterFloatingTrackerComponent *this, float deltaTime)
{
  UFG::WaterFloatingTrackerComponent *v2; // rsi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rbp
  bool v4; // r13
  int v5; // xmm6_4
  __m128 v6; // xmm4
  __m128 v7; // xmm4
  __m128 v8; // xmm0
  UFG::BasePhysicsSystem *v9; // rbx
  char v10; // r12
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v11; // r14
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> **v12; // r8
  bool i; // zf
  signed __int64 v14; // r10
  signed __int64 v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *j; // rax
  __int64 v17; // rdx
  signed int v18; // er9
  UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *v19; // rax
  char v20; // r15
  __int128 v21; // xmm1
  __int128 v22; // xmm2
  __int128 v23; // xmm3
  __int64 v24; // rdx
  __int64 v25; // r8
  int v26; // eax
  char v27; // cl
  UFG::WaterPhantomComponent *v28; // rbx
  signed __int64 v29; // rdi
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  UFG::qNode<UFG::WaterFloatingTrackerBaseComponent,UFG::WaterFloatingTrackerBaseComponent> *v32; // rax
  hkVector4f start; // [rsp+20h] [rbp-C8h]
  __int64 v34; // [rsp+30h] [rbp-B8h]
  __m128 v35; // [rsp+40h] [rbp-A8h]
  float v36; // [rsp+58h] [rbp-90h]
  hkVector4f end; // [rsp+60h] [rbp-88h]
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> v38; // [rsp+70h] [rbp-78h]
  __int128 v39; // [rsp+80h] [rbp-68h]
  __int128 v40; // [rsp+90h] [rbp-58h]
  __int128 v41; // [rsp+A0h] [rbp-48h]

  v34 = -2i64;
  v2 = this;
  v3 = this->m_BoundComponentHandles.mNode.mPrev;
  if ( v3 )
  {
    v4 = SLODWORD(this->m_BoundComponentHandles.mNode.mNext) > 0;
    v5 = HIDWORD(this->mPrev);
    if ( this->mNext )
    {
      if ( hkpRigidBody::isDeactivationEnabled((hkpRigidBody *)this->m_BoundComponentHandles.mNode.mPrev) )
        hkpRigidBody::enableDeactivation((hkpRigidBody *)v3, 0);
      v6 = _mm_mul_ps((__m128)v3[26], (__m128)v3[26]);
      v7 = _mm_add_ps(_mm_shuffle_ps(v6, v6, 170), _mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)));
      v8 = _mm_rsqrt_ps(v7);
      v9 = UFG::BasePhysicsSystem::mInstance;
      v8.m128_f32[0] = fmodf(
                         (float)(COERCE_FLOAT(
                                   _mm_andnot_ps(
                                     _mm_cmpleps(v7, (__m128)0i64),
                                     _mm_mul_ps(
                                       v7,
                                       _mm_mul_ps(
                                         _mm_mul_ps(*(__m128 *)_xmm, v8),
                                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v7), v8))))))
                               * *((float *)&UFG::BasePhysicsSystem::mInstance[1].mWorld + 1))
                       + *(float *)&UFG::BasePhysicsSystem::mInstance[1].mBroadPhaseBorder,
                         6.2800002);
      *((float *)&v2->mPrev + 1) = (float)((float)(cosf(v8.m128_f32[0])
                                                 * *(float *)&v9[1].mConstraintsToAdd.m_capacityAndFlags)
                                         + *(float *)&v9[1].mConstraintsToAdd.m_size)
                                 - 0.31400001;
    }
    v10 = 0;
    v11 = (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)((char *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList
                                                                              - 104);
    v12 = &UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mNext[-7].mNext;
    for ( i = &UFG::WaterPhantomComponent::s_WaterPhantomComponentList.mNode.mNext[-7].mNext == (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> **)((char *)&UFG::WaterPhantomComponent::s_WaterPhantomComponentList - 104);
          !i;
          i = v14 == (_QWORD)v11 )
    {
      v14 = (signed __int64)&v12[14][-7].mNext;
      if ( *((_BYTE *)v12 + 724) & 1 )
      {
        v15 = (signed __int64)&v3[2];
        for ( j = v3[3].mNext; j; j = j[1].mNext )
          v15 = (signed __int64)j;
        v17 = 0i64;
        v18 = *((_DWORD *)v12 + 50);
        if ( v18 > 0 )
        {
          v19 = v12[24];
          while ( v19->mPrev != (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)v15
               && v19[1].mPrev != (UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> *)v15 )
          {
            v17 = (unsigned int)(v17 + 1);
            v19 += 2;
            if ( (signed int)v17 >= v18 )
              goto LABEL_16;
          }
          v10 = 1;
          HIDWORD(v2->mPrev) = *((_DWORD *)v12 + 180);
          if ( !v4 )
            UFG::WaterFloatingTrackerComponent::OnEnterWater(
              (UFG::WaterFloatingTrackerComponent *)((char *)v2 - 64),
              v17,
              (__int64)v12);
          break;
        }
      }
LABEL_16:
      v12 = &v12[14][-7].mNext;
    }
    v20 = 0;
    if ( !v10 )
    {
      v21 = (__int128)v3[24];
      v22 = (__int128)v3[25];
      v23 = (__int128)v3[26];
      v38 = v3[23];
      v39 = v21;
      v40 = v22;
      v41 = v23;
      ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, UFG::qNode<UFG::WaterPhantomComponent,UFG::WaterPhantomComponent> **, __m128 *))v3[2].mPrev->mPrev[2].mPrev)(
        v3[2].mPrev,
        &v38,
        v12,
        &v35);
      if ( !(_S18_1 & 1) )
      {
        _S18_1 |= 1u;
        waterCheckBeam.m_quad = (__m128)_xmm;
      }
      if ( v35.m128_f32[2] < -0.31400001 )
      {
        v26 = (int)v2->m_BoundComponentHandles.mNode.mNext;
        if ( v26 > 0 )
        {
          v20 = 1;
          if ( v36 >= -1.0 )
          {
            if ( v26 == 2 )
            {
              UFG::WaterFloatingTrackerComponent::AddRippler(
                (UFG::WaterFloatingTrackerComponent *)((char *)v2 - 64),
                v24,
                v25);
              LODWORD(v2->m_BoundComponentHandles.mNode.mNext) = 1;
            }
          }
          else
          {
            UFG::WaterFloatingTrackerComponent::OnSunk((UFG::WaterFloatingTrackerComponent *)((char *)v2 - 64));
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
              v29 = (signed __int64)&v28->mNext[-7].mNext;
              if ( !(*((_BYTE *)v28 + 724) & 1) )
              {
                v30 = _mm_or_ps(
                        _mm_andnot_ps((__m128)xmmword_141792890, (__m128)v3[26]),
                        _mm_and_ps(v35, (__m128)xmmword_141792890));
                v31 = _mm_add_ps(v30, waterCheckBeam.m_quad);
                start.m_quad = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, waterCheckBeam.m_quad), 196);
                end.m_quad = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, waterCheckBeam.m_quad), 196);
                if ( v27 || UFG::WaterPhantomComponent::IntersectRay(v28, &start, &end) )
                {
                  v27 = 1;
                  HIDWORD(v2->mPrev) = LODWORD(v28->mElevation);
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
                (UFG::WaterFloatingTrackerComponent *)((char *)v2 - 64),
                v24,
                v25);
              v20 = 1;
            }
          }
        }
      }
    }
    if ( v4 && !v10 && !v20 )
      UFG::WaterFloatingTrackerComponent::OnExitWater((UFG::WaterFloatingTrackerComponent *)((char *)v2 - 64));
    v32 = v2->mNext;
    if ( v32 )
      LODWORD(v32[19].mPrev) = v5;
  }
}

