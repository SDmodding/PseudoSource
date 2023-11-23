// File Line: 57
// RVA: 0x1543D80
__int64 dynamic_initializer_for__UFG::BoostRegion::s_BoostRegionList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BoostRegion::s_BoostRegionList__);
}

// File Line: 58
// RVA: 0x52C940
UFG::ComponentIDDesc *__fastcall UFG::BoostRegion::GetDesc(UFG::BoostRegion *this)
{
  return &UFG::BoostRegion::_TypeIDesc;
}

// File Line: 60
// RVA: 0x15442A0
__int64 dynamic_initializer_for__UFG::BoostRegion::symBoostMagnitude__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("BoostMagnitude", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symBoostMagnitude, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BoostRegion::symBoostMagnitude__);
}

// File Line: 61
// RVA: 0x1544320
__int64 dynamic_initializer_for__UFG::BoostRegion::symBoostMagnitudeMin__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("BoostMagnitudeMin", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symBoostMagnitudeMin, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BoostRegion::symBoostMagnitudeMin__);
}

// File Line: 62
// RVA: 0x15442E0
__int64 dynamic_initializer_for__UFG::BoostRegion::symBoostMagnitudeMax__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("BoostMagnitudeMax", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symBoostMagnitudeMax, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BoostRegion::symBoostMagnitudeMax__);
}

// File Line: 63
// RVA: 0x1544360
__int64 dynamic_initializer_for__UFG::BoostRegion::symMinSpeedToActivate__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MinSpeedToActivate", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symMinSpeedToActivate, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BoostRegion::symMinSpeedToActivate__);
}

// File Line: 64
// RVA: 0x1544420
__int64 dynamic_initializer_for__UFG::BoostRegion::symRollMagnitude__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("RollMagnitude", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symRollMagnitude, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BoostRegion::symRollMagnitude__);
}

// File Line: 65
// RVA: 0x15443E0
__int64 dynamic_initializer_for__UFG::BoostRegion::symPitchMagnitude__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("PitchMagnitude", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symPitchMagnitude, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BoostRegion::symPitchMagnitude__);
}

// File Line: 66
// RVA: 0x15444E0
__int64 dynamic_initializer_for__UFG::BoostRegion::symYawMagnitude__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("YawMagnitude", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symYawMagnitude, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BoostRegion::symYawMagnitude__);
}

// File Line: 101
// RVA: 0x5160F0
void __fastcall UFG::BoostRegion::BoostRegion(UFG::BoostRegion *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *mPrev; // rax

  UFG::MarkerBase::MarkerBase(this, name, pSimObj, 0x30000u);
  this->mPrev = &this->UFG::qNode<UFG::BoostRegion,UFG::BoostRegion>;
  this->mNext = &this->UFG::qNode<UFG::BoostRegion,UFG::BoostRegion>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoostRegion::`vftable;
  this->mTrackedObjects.mNode.mPrev = &this->mTrackedObjects.mNode;
  this->mTrackedObjects.mNode.mNext = &this->mTrackedObjects.mNode;
  this->mfBoostMagnitude = 1.0;
  *(_QWORD *)&this->mfRollMagnitude = 0i64;
  this->mfYawMagnitude = 0.0;
  UFG::SimComponent::AddType(this, UFG::BoostRegion::_BoostRegionTypeUID, "BoostRegion");
  mPrev = UFG::BoostRegion::s_BoostRegionList.mNode.mPrev;
  UFG::BoostRegion::s_BoostRegionList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::BoostRegion,UFG::BoostRegion>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *)&UFG::BoostRegion::s_BoostRegionList;
  UFG::BoostRegion::s_BoostRegionList.mNode.mPrev = &this->UFG::qNode<UFG::BoostRegion,UFG::BoostRegion>;
  UFG::BoostRegion::InitRegion(this, pSimObj);
}

// File Line: 118
// RVA: 0x5390E0
void __fastcall UFG::BoostRegion::InitRegion(UFG::BoostRegion *this, UFG::RegionComponent *pSimObj)
{
  UFG::RegionComponent *ComponentOfType; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SensorPhantom *v5; // rax
  UFG::qBox pBox; // [rsp+38h] [rbp-40h] BYREF
  hkAabb aabb; // [rsp+50h] [rbp-28h] BYREF

  ComponentOfType = pSimObj;
  if ( pSimObj )
    ComponentOfType = (UFG::RegionComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)pSimObj,
                                                UFG::RegionComponent::_TypeUID);
  this->mpRegion = ComponentOfType;
  memset(&pBox, 0, sizeof(pBox));
  UFG::RegionComponent::GetBoundingBox(ComponentOfType, &pBox);
  aabb.m_min.m_quad = _mm_unpacklo_ps(
                        _mm_unpacklo_ps((__m128)LODWORD(pBox.mMin.x), (__m128)LODWORD(pBox.mMin.z)),
                        _mm_unpacklo_ps((__m128)LODWORD(pBox.mMin.y), (__m128)0i64));
  aabb.m_max.m_quad = _mm_unpacklo_ps(
                        _mm_unpacklo_ps((__m128)LODWORD(pBox.mMax.x), (__m128)LODWORD(pBox.mMax.z)),
                        _mm_unpacklo_ps((__m128)LODWORD(pBox.mMax.y), (__m128)0i64));
  v4 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x18ui64, "SensorPhantom", 0i64, 1u);
  if ( v4 )
  {
    UFG::SensorPhantom::SensorPhantom((UFG::SensorPhantom *)v4, &aabb, 0xFu, "BoostRegion");
    this->mPhantom = v5;
  }
  else
  {
    this->mPhantom = 0i64;
  }
}

// File Line: 137
// RVA: 0x51ADC0
void __fastcall UFG::BoostRegion::~BoostRegion(UFG::BoostRegion *this)
{
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *v2; // rdi
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *mPrev; // rcx
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *mNext; // rax
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0> *p_mTrackedObjects; // rsi
  UFG::SensorPhantom *mPhantom; // rcx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v7; // rcx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v8; // rax
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *v9; // rcx
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *v10; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoostRegion::`vftable;
  if ( this == UFG::BoostRegion::s_BoostRegionpCurrentIterator )
    UFG::BoostRegion::s_BoostRegionpCurrentIterator = (UFG::BoostRegion *)&this->mPrev[-7];
  v2 = &this->UFG::qNode<UFG::BoostRegion,UFG::BoostRegion>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p_mTrackedObjects = &this->mTrackedObjects;
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&this->mTrackedObjects);
  mPhantom = this->mPhantom;
  if ( mPhantom )
    mPhantom->vfptr->__vecDelDtor(mPhantom, 1u);
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&this->mTrackedObjects);
  v7 = p_mTrackedObjects->mNode.mPrev;
  v8 = this->mTrackedObjects.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  p_mTrackedObjects->mNode.mPrev = &p_mTrackedObjects->mNode;
  this->mTrackedObjects.mNode.mNext = &this->mTrackedObjects.mNode;
  v9 = v2->mPrev;
  v10 = v2->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 151
// RVA: 0x5593C0
// local variable allocation has failed, the output may be wrong!
void __fastcall UFG::BoostRegion::Update(UFG::BoostRegion *this, float deltaTime, __int64 a3, double a4)
{
  __m128 v4; // xmm7
  __m128 v5; // xmm8
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *mNext; // rax
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0> *i; // rcx
  UFG::SimObjectGame *v9; // rax
  UFG::SimObjectGame *v10; // rbx
  UFG::PhysicsMoverInterface *m_pComponent; // rdi
  __int16 m_Flags; // cx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *p; // rbx
  UFG::SimComponentHolder *v16; // rdx
  hkSimpleLocalFrame *v17; // rax
  unsigned int v18; // r8d
  unsigned int v19; // r10d
  UFG::SimComponentHolder *v20; // rbx
  unsigned int v21; // r8d
  unsigned int v22; // r10d
  UFG::SimComponentHolder *v23; // rbx
  UFG::SimObjectCharacter *Texture; // rbx
  UFG::SimObject *v25; // rcx
  __int16 v26; // dx
  unsigned int vfptr; // r8d
  unsigned int v28; // r10d
  UFG::SimComponentHolder *v29; // rbx
  __int64 v30; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v32; // r8d
  unsigned int v33; // r10d
  unsigned int v34; // r8d
  unsigned int v35; // r10d
  unsigned int v36; // r8d
  unsigned int v37; // r10d
  UFG::GameStatTracker *v38; // rax
  UFG::GameStatTracker *v39; // rax
  hkpEntity *RigidBody; // rdi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __m128 v43; // xmm6
  __m128 v44; // xmm2
  __m128 v45; // xmm2
  __m128 mfMinSpeedToActivate_low; // xmm0
  __m128 v47; // xmm0
  __m128 v48; // xmm1
  UFG::qVector3 result; // [rsp+38h] [rbp-D0h] BYREF
  hkVector4f v50; // [rsp+50h] [rbp-B8h] BYREF
  hkVector4f direction; // [rsp+60h] [rbp-A8h] BYREF
  __m128 v52; // [rsp+70h] [rbp-98h] BYREF
  UFG::SensorPhantomIterator v53; // [rsp+80h] [rbp-88h] BYREF
  UFG::qWiseSymbol v54; // [rsp+110h] [rbp+8h] BYREF

  mNext = this->mTrackedObjects.mNode.mNext;
  for ( i = &this->mTrackedObjects;
        mNext != (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)i;
        mNext = mNext->mNext )
  {
    LOBYTE(mNext[2].mNext) = 0;
  }
  UFG::SensorPhantomIterator::SensorPhantomIterator(&v53, this->mPhantom, 0);
  if ( UFG::SensorPhantomIterator::operator*(&v53) )
  {
    while ( 1 )
    {
      v9 = (UFG::SimObjectGame *)UFG::SensorPhantomIterator::operator*(&v53);
      v10 = v9;
      if ( (v9->m_Flags & 0x8000u) != 0 )
      {
        m_pComponent = (UFG::PhysicsMoverInterface *)v9->m_Components.p[34].m_pComponent;
        if ( m_pComponent )
        {
          UFG::GetPosition(&result, v9);
          if ( UFG::RegionComponent::IsHitPoint(this->mpRegion, &result)
            && !UFG::BoostRegion::TrackObject(this, (UFG::allocator::free_link *)v10) )
          {
            break;
          }
        }
      }
LABEL_78:
      UFG::SensorPhantomIterator::operator++(&v53);
      if ( !UFG::SensorPhantomIterator::operator*(&v53) )
        goto LABEL_79;
    }
    m_Flags = v10->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      mComponentTableEntryCount = v10->mComponentTableEntryCount;
      size = v10->m_Components.size;
      if ( mComponentTableEntryCount < size )
      {
        p = v10->m_Components.p;
        while ( 1 )
        {
          v16 = &p[mComponentTableEntryCount];
          if ( (v16->m_TypeUID & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
            && (UFG::VehicleOccupantComponent::_TypeUID & ~v16->m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++mComponentTableEntryCount >= size )
            goto LABEL_16;
        }
LABEL_15:
        v17 = (hkSimpleLocalFrame *)v16->m_pComponent;
LABEL_34:
        if ( !v17
          || (Texture = (UFG::SimObjectCharacter *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v17),
              Texture != UFG::GetLocalPlayer())
          || (v25 = this->m_pSimObject) == 0i64 )
        {
LABEL_71:
          RigidBody = (hkpEntity *)UFG::PhysicsMoverInterface::GetRigidBody(m_pComponent);
          if ( RigidBody )
          {
            m_pSimObject = this->m_pSimObject;
            if ( m_pSimObject )
              m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
            else
              m_pTransformNodeComponent = 0i64;
            if ( m_pTransformNodeComponent )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              v5.m128_f32[0] = this->mfBoostMagnitudeMax * 0.27777779;
              v5 = _mm_shuffle_ps(v5, v5, 0);
              v4.m128_f32[0] = this->mfBoostMagnitudeMin * 0.27777779;
              v4 = _mm_shuffle_ps(v4, v4, 0);
              v43 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(
                        (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.x),
                        (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.z)),
                      _mm_unpacklo_ps((__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.y), (__m128)0i64));
              *(float *)&a4 = hkpMotion::getMass(&RigidBody->m_motion);
              *(__m128 *)&a4 = _mm_shuffle_ps(*(__m128 *)&a4, *(__m128 *)&a4, 0);
              v44 = _mm_mul_ps(RigidBody->m_motion.m_linearVelocity.m_quad, v43);
              v45 = _mm_add_ps(
                      _mm_shuffle_ps(v44, v44, 170),
                      _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)));
              mfMinSpeedToActivate_low = (__m128)LODWORD(this->mfMinSpeedToActivate);
              mfMinSpeedToActivate_low.m128_f32[0] = mfMinSpeedToActivate_low.m128_f32[0] * 0.27777779;
              if ( v45.m128_f32[0] > _mm_shuffle_ps(mfMinSpeedToActivate_low, mfMinSpeedToActivate_low, 0).m128_f32[0] )
              {
                v47 = _mm_shuffle_ps(
                        RigidBody->m_motion.m_inertiaAndMassInv.m_quad,
                        RigidBody->m_motion.m_inertiaAndMassInv.m_quad,
                        255);
                v47.m128_f32[0] = v47.m128_f32[0] * this->mfBoostMagnitude;
                v5 = _mm_min_ps(v5, _mm_add_ps(_mm_shuffle_ps(v47, v47, 0), v45));
                v4 = _mm_sub_ps(_mm_max_ps(v4, v5), v45);
                v48 = _mm_cmplt_ps(_mm_mul_ps(v4, v45), aabbOut.m_quad);
                v52 = _mm_mul_ps(
                        _mm_mul_ps(_mm_or_ps(_mm_andnot_ps(v48, v4), _mm_and_ps(v48, aabbOut.m_quad)), *(__m128 *)&a4),
                        v43);
                hkpEntity::activate(RigidBody);
                RigidBody->m_motion.vfptr[11].__vecDelDtor(&RigidBody->m_motion, (unsigned int)&v52);
                direction.m_quad = (__m128)RigidBody->m_motion.m_angularVelocity;
                hkVector4f::setRotatedInverseDir(
                  &v50,
                  &RigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1,
                  &direction);
                *(__m128 *)&a4 = _mm_unpacklo_ps(
                                   _mm_unpacklo_ps(
                                     (__m128)LODWORD(this->mfRollMagnitude),
                                     (__m128)LODWORD(this->mfYawMagnitude)),
                                   _mm_unpacklo_ps((__m128)LODWORD(this->mfPitchMagnitude), (__m128)0i64));
                v50.m_quad = _mm_add_ps(v50.m_quad, *(__m128 *)&a4);
                hkVector4f::setRotatedDir(
                  &direction,
                  &RigidBody->m_motion.m_motionState.m_sweptTransform.m_rotation1,
                  &v50);
                hkpEntity::activate(RigidBody);
                ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))RigidBody->m_motion.vfptr[9].__first_virtual_table_function__)(
                  &RigidBody->m_motion,
                  &direction);
              }
            }
          }
          goto LABEL_78;
        }
        v26 = v25->m_Flags;
        if ( (v26 & 0x4000) != 0 )
        {
          vfptr = (unsigned int)v25[1].vfptr;
          v28 = v25->m_Components.size;
          if ( vfptr < v28 )
          {
            v29 = v25->m_Components.p;
            while ( 1 )
            {
              v30 = vfptr;
              if ( (v29[vfptr].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
                && (UFG::CollectibleComponent::_TypeUID & ~v29[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++vfptr >= v28 )
                goto LABEL_45;
            }
LABEL_44:
            ComponentOfType = v29[v30].m_pComponent;
LABEL_68:
            if ( ComponentOfType )
            {
              UFG::qSymbol::qSymbol(&v54, this->m_NameUID);
              v38 = UFG::GameStatTracker::Instance();
              if ( !UFG::GameStatTracker::GetStat(v38, Collectible_BoostRegion, (UFG::qSymbol *)&v54) )
              {
                v39 = UFG::GameStatTracker::Instance();
                UFG::GameStatTracker::SetStat(v39, Collectible_BoostRegion, (UFG::qSymbol *)&v54, 1);
                *(_OWORD *)&a4 = LODWORD(FLOAT_5_0);
                UFG::UIHKInfoPopupWidget::Show(
                  UFG::UIHKScreenHud::InfoPopup,
                  "$HUD_COLLECTIBLES_JUMP_SUCCESS",
                  &qSymbol_Collectible_Jump_16,
                  5.0,
                  POSITION_DEFAULT);
              }
            }
            goto LABEL_71;
          }
        }
        else if ( v26 >= 0 )
        {
          if ( (v26 & 0x2000) != 0 )
          {
            v34 = (unsigned int)v25[1].vfptr;
            v35 = v25->m_Components.size;
            if ( v34 < v35 )
            {
              v29 = v25->m_Components.p;
              do
              {
                v30 = v34;
                if ( (v29[v34].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
                  && (UFG::CollectibleComponent::_TypeUID & ~v29[v34].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_44;
                }
              }
              while ( ++v34 < v35 );
            }
          }
          else
          {
            if ( (v26 & 0x1000) == 0 )
            {
              ComponentOfType = UFG::SimObject::GetComponentOfType(v25, UFG::CollectibleComponent::_TypeUID);
              goto LABEL_68;
            }
            v36 = (unsigned int)v25[1].vfptr;
            v37 = v25->m_Components.size;
            if ( v36 < v37 )
            {
              v29 = v25->m_Components.p;
              do
              {
                v30 = v36;
                if ( (v29[v36].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
                  && (UFG::CollectibleComponent::_TypeUID & ~v29[v36].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_44;
                }
              }
              while ( ++v36 < v37 );
            }
          }
        }
        else
        {
          v32 = (unsigned int)v25[1].vfptr;
          v33 = v25->m_Components.size;
          if ( v32 < v33 )
          {
            v29 = v25->m_Components.p;
            do
            {
              v30 = v32;
              if ( (v29[v32].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
                && (UFG::CollectibleComponent::_TypeUID & ~v29[v32].m_TypeUID & 0x1FFFFFF) == 0 )
              {
                goto LABEL_44;
              }
            }
            while ( ++v32 < v33 );
          }
        }
LABEL_45:
        ComponentOfType = 0i64;
        goto LABEL_68;
      }
    }
    else
    {
      if ( m_Flags < 0 )
      {
        v17 = (hkSimpleLocalFrame *)v10->m_Components.p[30].m_pComponent;
        goto LABEL_34;
      }
      if ( (m_Flags & 0x2000) != 0 )
      {
        v18 = v10->mComponentTableEntryCount;
        v19 = v10->m_Components.size;
        if ( v18 < v19 )
        {
          v20 = v10->m_Components.p;
          do
          {
            v16 = &v20[v18];
            if ( (v16->m_TypeUID & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
              && (UFG::VehicleOccupantComponent::_TypeUID & ~v16->m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_15;
            }
          }
          while ( ++v18 < v19 );
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          v17 = (hkSimpleLocalFrame *)UFG::SimObject::GetComponentOfType(v10, UFG::VehicleOccupantComponent::_TypeUID);
          goto LABEL_34;
        }
        v21 = v10->mComponentTableEntryCount;
        v22 = v10->m_Components.size;
        if ( v21 < v22 )
        {
          v23 = v10->m_Components.p;
          do
          {
            v16 = &v23[v21];
            if ( (v16->m_TypeUID & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
              && (UFG::VehicleOccupantComponent::_TypeUID & ~v16->m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_15;
            }
          }
          while ( ++v21 < v22 );
        }
      }
    }
LABEL_16:
    v17 = 0i64;
    goto LABEL_34;
  }
LABEL_79:
  UFG::BoostRegion::UpdateTrackingPost(this);
  UFG::SensorPhantomIterator::~SensorPhantomIterator(&v53);
}

// File Line: 291
// RVA: 0x556B50
char __fastcall UFG::BoostRegion::TrackObject(UFG::BoostRegion *this, UFG::allocator::free_link *simObject)
{
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *mNext; // rax
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0> *p_mTrackedObjects; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v12; // rcx

  mNext = this->mTrackedObjects.mNode.mNext;
  p_mTrackedObjects = &this->mTrackedObjects;
  if ( mNext == (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)&this->mTrackedObjects )
  {
LABEL_6:
    v6 = UFG::qMalloc(0x30ui64, "BoostRegionTracker", 0i64);
    v7 = v6;
    if ( v6 )
    {
      v6->mNext = v6;
      v6[1].mNext = v6;
      v6[2].mNext = v6 + 2;
      v6[3].mNext = v6 + 2;
      v6[4].mNext = 0i64;
    }
    else
    {
      v7 = 0i64;
    }
    v8 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7[2];
    if ( v7[4].mNext )
    {
      mPrev = v8->mPrev;
      v10 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v7[3].mNext;
      mPrev->mNext = v10;
      v10->mPrev = mPrev;
      v8->mPrev = v8;
      v7[3].mNext = v7 + 2;
    }
    v7[4].mNext = simObject;
    if ( simObject )
    {
      v11 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)simObject[1].mNext;
      v11->mNext = v8;
      v8->mPrev = v11;
      v7[3].mNext = simObject + 1;
      simObject[1].mNext = (UFG::allocator::free_link *)v8;
    }
    LOBYTE(v7[5].mNext) = 1;
    v12 = p_mTrackedObjects->mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)v7;
    v7->mNext = (UFG::allocator::free_link *)v12;
    v7[1].mNext = (UFG::allocator::free_link *)p_mTrackedObjects;
    p_mTrackedObjects->mNode.mPrev = (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)v7;
    return 0;
  }
  else
  {
    while ( simObject != (UFG::allocator::free_link *)mNext[2].mPrev )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)p_mTrackedObjects )
        goto LABEL_6;
    }
    LOBYTE(mNext[2].mNext) = 1;
    return 1;
  }
}

// File Line: 333
// RVA: 0x561280
void __fastcall UFG::BoostRegion::UpdateTrackingPost(UFG::BoostRegion *this)
{
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *mNext; // r9
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0> *p_mTrackedObjects; // rdi
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0> *v3; // rbx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v4; // rax
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *mPrev; // rdx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v6; // rcx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v7; // r8
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v8; // rdx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v9; // rdx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v10; // rax

  mNext = this->mTrackedObjects.mNode.mNext;
  p_mTrackedObjects = &this->mTrackedObjects;
  if ( mNext != (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)&this->mTrackedObjects )
  {
    do
    {
      v3 = (UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0> *)mNext->mNext;
      if ( !LOBYTE(mNext[2].mNext) )
      {
        v4 = mNext + 1;
        if ( mNext[2].mPrev )
        {
          mPrev = v4->mPrev;
          v6 = mNext[1].mNext;
          mPrev->mNext = v6;
          v6->mPrev = mPrev;
          v4->mPrev = v4;
          mNext[1].mNext = mNext + 1;
        }
        mNext[2].mPrev = 0i64;
        v7 = v4->mPrev;
        v8 = mNext[1].mNext;
        v7->mNext = v8;
        v8->mPrev = v7;
        v4->mPrev = v4;
        mNext[1].mNext = mNext + 1;
        v9 = mNext->mPrev;
        v10 = mNext->mNext;
        v9->mNext = v10;
        v10->mPrev = v9;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
        operator delete[](mNext);
      }
      mNext = &v3->mNode;
    }
    while ( v3 != p_mTrackedObjects );
  }
}

// File Line: 377
// RVA: 0x5443C0
UFG::BoostRegion *__fastcall UFG::BoostRegion::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rbp
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v5; // rax
  float *v6; // rax
  float *v7; // rbx
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *v10; // rcx
  UFG::qPropertySet *v11; // rcx
  UFG::qPropertySet *v12; // rcx
  UFG::qPropertySet *v13; // rcx
  UFG::qPropertySet *v14; // rcx
  UFG::qSymbol result; // [rsp+60h] [rbp+8h] BYREF
  UFG::allocator::free_link *v17; // [rsp+68h] [rbp+10h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xC0ui64, "BoostRegion", 0i64, 1u);
  v17 = v3;
  if ( v3 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v5 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(pSceneObj, (UFG::qWiseSymbol *)&result);
    UFG::BoostRegion::BoostRegion((UFG::BoostRegion *)v3, v5, m_pSimObject);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v7[40] = *UFG::qPropertySet::Get<float>(
              mpWritableProperties,
              (UFG::qArray<unsigned long,0> *)&UFG::BoostRegion::symBoostMagnitude,
              DEPTH_RECURSE);
  mpConstProperties = pSceneObj->mpWritableProperties;
  if ( !mpConstProperties )
    mpConstProperties = pSceneObj->mpConstProperties;
  v7[41] = *UFG::qPropertySet::Get<float>(
              mpConstProperties,
              (UFG::qArray<unsigned long,0> *)&UFG::BoostRegion::symBoostMagnitudeMin,
              DEPTH_RECURSE);
  v10 = pSceneObj->mpWritableProperties;
  if ( !v10 )
    v10 = pSceneObj->mpConstProperties;
  v7[42] = *UFG::qPropertySet::Get<float>(
              v10,
              (UFG::qArray<unsigned long,0> *)&UFG::BoostRegion::symBoostMagnitudeMax,
              DEPTH_RECURSE);
  v11 = pSceneObj->mpWritableProperties;
  if ( !v11 )
    v11 = pSceneObj->mpConstProperties;
  v7[43] = *UFG::qPropertySet::Get<float>(
              v11,
              (UFG::qArray<unsigned long,0> *)&UFG::BoostRegion::symMinSpeedToActivate,
              DEPTH_RECURSE);
  v12 = pSceneObj->mpWritableProperties;
  if ( !v12 )
    v12 = pSceneObj->mpConstProperties;
  v7[44] = *UFG::qPropertySet::Get<float>(
              v12,
              (UFG::qArray<unsigned long,0> *)&UFG::BoostRegion::symRollMagnitude,
              DEPTH_RECURSE);
  v13 = pSceneObj->mpWritableProperties;
  if ( !v13 )
    v13 = pSceneObj->mpConstProperties;
  v7[45] = *UFG::qPropertySet::Get<float>(
              v13,
              (UFG::qArray<unsigned long,0> *)&UFG::BoostRegion::symPitchMagnitude,
              DEPTH_RECURSE);
  v14 = pSceneObj->mpWritableProperties;
  if ( !v14 )
    v14 = pSceneObj->mpConstProperties;
  v7[46] = *UFG::qPropertySet::Get<float>(
              v14,
              (UFG::qArray<unsigned long,0> *)&UFG::BoostRegion::symYawMagnitude,
              DEPTH_RECURSE);
  return (UFG::BoostRegion *)v7;
}

