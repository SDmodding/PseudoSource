// File Line: 57
// RVA: 0x1543D80
__int64 dynamic_initializer_for__UFG::BoostRegion::s_BoostRegionList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::BoostRegion::s_BoostRegionList__);
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
  return atexit(dynamic_atexit_destructor_for__UFG::BoostRegion::symBoostMagnitude__);
}

// File Line: 61
// RVA: 0x1544320
__int64 dynamic_initializer_for__UFG::BoostRegion::symBoostMagnitudeMin__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("BoostMagnitudeMin", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symBoostMagnitudeMin, v0);
  return atexit(dynamic_atexit_destructor_for__UFG::BoostRegion::symBoostMagnitudeMin__);
}

// File Line: 62
// RVA: 0x15442E0
__int64 dynamic_initializer_for__UFG::BoostRegion::symBoostMagnitudeMax__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("BoostMagnitudeMax", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symBoostMagnitudeMax, v0);
  return atexit(dynamic_atexit_destructor_for__UFG::BoostRegion::symBoostMagnitudeMax__);
}

// File Line: 63
// RVA: 0x1544360
__int64 dynamic_initializer_for__UFG::BoostRegion::symMinSpeedToActivate__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MinSpeedToActivate", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symMinSpeedToActivate, v0);
  return atexit(dynamic_atexit_destructor_for__UFG::BoostRegion::symMinSpeedToActivate__);
}

// File Line: 64
// RVA: 0x1544420
__int64 dynamic_initializer_for__UFG::BoostRegion::symRollMagnitude__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("RollMagnitude", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symRollMagnitude, v0);
  return atexit(dynamic_atexit_destructor_for__UFG::BoostRegion::symRollMagnitude__);
}

// File Line: 65
// RVA: 0x15443E0
__int64 dynamic_initializer_for__UFG::BoostRegion::symPitchMagnitude__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("PitchMagnitude", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symPitchMagnitude, v0);
  return atexit(dynamic_atexit_destructor_for__UFG::BoostRegion::symPitchMagnitude__);
}

// File Line: 66
// RVA: 0x15444E0
__int64 dynamic_initializer_for__UFG::BoostRegion::symYawMagnitude__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("YawMagnitude", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::BoostRegion::symYawMagnitude, v0);
  return atexit(dynamic_atexit_destructor_for__UFG::BoostRegion::symYawMagnitude__);
}

// File Line: 101
// RVA: 0x5160F0
void __fastcall UFG::BoostRegion::BoostRegion(UFG::BoostRegion *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::SimObject *v3; // rdi
  UFG::BoostRegion *v4; // rsi
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *v5; // rbx
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *v6; // rax
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0> *v7; // [rsp+58h] [rbp+20h]

  v3 = pSimObj;
  v4 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, pSimObj, 0x30000u);
  v5 = (UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoostRegion::`vftable;
  v7 = &v4->mTrackedObjects;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v4->mfBoostMagnitude = 1.0;
  *(_QWORD *)&v4->mfRollMagnitude = 0i64;
  v4->mfYawMagnitude = 0.0;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v4->vfptr, UFG::BoostRegion::_BoostRegionTypeUID, "BoostRegion");
  v6 = UFG::BoostRegion::s_BoostRegionList.mNode.mPrev;
  UFG::BoostRegion::s_BoostRegionList.mNode.mPrev->mNext = (UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *)&UFG::BoostRegion::s_BoostRegionList;
  UFG::BoostRegion::s_BoostRegionList.mNode.mPrev = (UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *)&v4->mPrev;
  UFG::BoostRegion::InitRegion(v4, v3);
}

// File Line: 118
// RVA: 0x5390E0
void __fastcall UFG::BoostRegion::InitRegion(UFG::BoostRegion *this, UFG::SimObject *pSimObj)
{
  UFG::RegionComponent *v2; // rax
  UFG::BoostRegion *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  UFG::SensorPhantom *v5; // rax
  UFG::qBox pBox; // [rsp+38h] [rbp-40h]
  hkAabb aabb; // [rsp+50h] [rbp-28h]

  v2 = (UFG::RegionComponent *)pSimObj;
  v3 = this;
  if ( pSimObj )
    v2 = (UFG::RegionComponent *)UFG::SimObject::GetComponentOfType(pSimObj, UFG::RegionComponent::_TypeUID);
  v3->mpRegion = v2;
  *(_QWORD *)&pBox.mMin.x = 0i64;
  *(_QWORD *)&pBox.mMin.z = 0i64;
  *(_QWORD *)&pBox.mMax.y = 0i64;
  UFG::RegionComponent::GetBoundingBox(v2, &pBox);
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
    v3->mPhantom = v5;
  }
  else
  {
    v3->mPhantom = 0i64;
  }
}

// File Line: 137
// RVA: 0x51ADC0
void __fastcall UFG::BoostRegion::~BoostRegion(UFG::BoostRegion *this)
{
  UFG::BoostRegion *v1; // rbx
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *v2; // rdi
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *v3; // rcx
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *v4; // rax
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0> *v5; // rsi
  UFG::SensorPhantom *v6; // rcx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v7; // rcx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v8; // rax
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *v9; // rcx
  UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *v10; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoostRegion::`vftable;
  if ( this == UFG::BoostRegion::s_BoostRegionpCurrentIterator )
    UFG::BoostRegion::s_BoostRegionpCurrentIterator = (UFG::BoostRegion *)&this->mPrev[-7];
  v2 = (UFG::qNode<UFG::BoostRegion,UFG::BoostRegion> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->mTrackedObjects;
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&v1->mTrackedObjects);
  v6 = v1->mPhantom;
  if ( v6 )
    v6->vfptr->__vecDelDtor(v6, 1u);
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&v1->mTrackedObjects);
  v7 = v5->mNode.mPrev;
  v8 = v1->mTrackedObjects.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v5->mNode.mPrev = &v5->mNode;
  v1->mTrackedObjects.mNode.mNext = &v1->mTrackedObjects.mNode;
  v9 = v2->mPrev;
  v10 = v2->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 151
// RVA: 0x5593C0
void __usercall UFG::BoostRegion::Update(UFG::BoostRegion *this@<rcx>, float deltaTime@<xmm1>, __m128 a3@<xmm3>, __m128 a4@<xmm7>, __m128 a5@<xmm8>)
{
  UFG::BoostRegion *v5; // rsi
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v6; // rax
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0> *i; // rcx
  UFG::SimObject *v8; // rax
  UFG::SimObject *v9; // rbx
  UFG::PhysicsMoverInterface *v10; // rdi
  unsigned __int16 v11; // cx
  unsigned int v12; // er8
  unsigned int v13; // er10
  UFG::SimComponentHolder *v14; // rbx
  signed __int64 v15; // rdx
  hkSimpleLocalFrame *v16; // rax
  unsigned int v17; // er8
  unsigned int v18; // er10
  UFG::SimComponentHolder *v19; // rbx
  unsigned int v20; // er8
  unsigned int v21; // er10
  UFG::SimComponentHolder *v22; // rbx
  UFG::SimObjectCharacter *v23; // rbx
  UFG::SimObject *v24; // rcx
  unsigned __int16 v25; // dx
  unsigned int v26; // er8
  unsigned int v27; // er10
  UFG::SimComponentHolder *v28; // rbx
  signed __int64 v29; // rdx
  UFG::SimComponent *v30; // rax
  unsigned int v31; // er8
  unsigned int v32; // er10
  unsigned int v33; // er8
  unsigned int v34; // er10
  unsigned int v35; // er8
  unsigned int v36; // er10
  UFG::GameStatTracker *v37; // rax
  UFG::GameStatTracker *v38; // rax
  hkpEntity *v39; // rdi
  UFG::SimObject *v40; // rbx
  UFG::TransformNodeComponent *v41; // rbx
  __m128 v42; // xmm6
  __m128 v43; // xmm2
  __m128 v44; // xmm2
  __m128 v45; // xmm0
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  UFG::qVector3 result; // [rsp+38h] [rbp-D0h]
  hkVector4f v49; // [rsp+50h] [rbp-B8h]
  hkVector4f direction; // [rsp+60h] [rbp-A8h]
  __m128 v51; // [rsp+70h] [rbp-98h]
  UFG::SensorPhantomIterator v52; // [rsp+80h] [rbp-88h]
  UFG::qWiseSymbol v53; // [rsp+110h] [rbp+8h]

  v5 = this;
  v6 = this->mTrackedObjects.mNode.mNext;
  for ( i = &this->mTrackedObjects; v6 != (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)i; v6 = v6->mNext )
    LOBYTE(v6[2].mNext) = 0;
  UFG::SensorPhantomIterator::SensorPhantomIterator(&v52, v5->mPhantom, 0);
  if ( UFG::SensorPhantomIterator::operator*(&v52) )
  {
    while ( 1 )
    {
      v8 = (UFG::SimObject *)UFG::SensorPhantomIterator::operator*(&v52);
      v9 = v8;
      if ( (v8->m_Flags & 0x8000u) != 0 )
      {
        v10 = (UFG::PhysicsMoverInterface *)v8->m_Components.p[34].m_pComponent;
        if ( v10 )
        {
          UFG::GetPosition(&result, v8);
          if ( UFG::RegionComponent::IsHitPoint(v5->mpRegion, &result) && !UFG::BoostRegion::TrackObject(v5, v9) )
            break;
        }
      }
LABEL_78:
      UFG::SensorPhantomIterator::operator++(&v52);
      if ( !UFG::SensorPhantomIterator::operator*(&v52) )
        goto LABEL_79;
    }
    v11 = v9->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = (unsigned int)v9[1].vfptr;
      v13 = v9->m_Components.size;
      if ( v12 < v13 )
      {
        v14 = v9->m_Components.p;
        while ( 1 )
        {
          v15 = (signed __int64)&v14[v12];
          if ( (*(_DWORD *)(v15 + 8) & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
            && !(UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v12 >= v13 )
            goto LABEL_16;
        }
LABEL_15:
        v16 = *(hkSimpleLocalFrame **)v15;
LABEL_34:
        if ( !v16
          || (v23 = (UFG::SimObjectCharacter *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v16),
              v23 != UFG::GetLocalPlayer())
          || (v24 = v5->m_pSimObject) == 0i64 )
        {
LABEL_71:
          v39 = (hkpEntity *)UFG::PhysicsMoverInterface::GetRigidBody(v10);
          if ( v39 )
          {
            v40 = v5->m_pSimObject;
            if ( v40 )
              v41 = v40->m_pTransformNodeComponent;
            else
              v41 = 0i64;
            if ( v41 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v41);
              a5.m128_f32[0] = v5->mfBoostMagnitudeMax * 0.27777779;
              a5 = _mm_shuffle_ps(a5, a5, 0);
              a4.m128_f32[0] = v5->mfBoostMagnitudeMin * 0.27777779;
              a4 = _mm_shuffle_ps(a4, a4, 0);
              v42 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(
                        (__m128)LODWORD(v41->mWorldTransform.v0.x),
                        (__m128)LODWORD(v41->mWorldTransform.v0.z)),
                      _mm_unpacklo_ps((__m128)LODWORD(v41->mWorldTransform.v0.y), (__m128)0i64));
              a3.m128_f32[0] = hkpMotion::getMass((hkpMotion *)&v39->m_motion.vfptr);
              a3 = _mm_shuffle_ps(a3, a3, 0);
              v43 = _mm_mul_ps(v39->m_motion.m_linearVelocity.m_quad, v42);
              v44 = _mm_add_ps(
                      _mm_shuffle_ps(v43, v43, 170),
                      _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)));
              v45 = (__m128)LODWORD(v5->mfMinSpeedToActivate);
              v45.m128_f32[0] = v45.m128_f32[0] * 0.27777779;
              if ( v44.m128_f32[0] > COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 0)) )
              {
                v46 = _mm_shuffle_ps(
                        v39->m_motion.m_inertiaAndMassInv.m_quad,
                        v39->m_motion.m_inertiaAndMassInv.m_quad,
                        255);
                v46.m128_f32[0] = v46.m128_f32[0] * v5->mfBoostMagnitude;
                a5 = _mm_min_ps(a5, _mm_add_ps(_mm_shuffle_ps(v46, v46, 0), v44));
                a4 = _mm_sub_ps(_mm_max_ps(a4, a5), v44);
                v47 = _mm_cmpltps(_mm_mul_ps(a4, v44), aabbOut.m_quad);
                v51 = _mm_mul_ps(
                        _mm_mul_ps(_mm_or_ps(_mm_andnot_ps(v47, a4), _mm_and_ps(v47, aabbOut.m_quad)), a3),
                        v42);
                hkpEntity::activate(v39);
                v39->m_motion.vfptr[11].__vecDelDtor((hkBaseObject *)&v39->m_motion.vfptr, (unsigned int)&v51);
                direction.m_quad = (__m128)v39->m_motion.m_angularVelocity;
                hkVector4f::setRotatedInverseDir(
                  &v49,
                  &v39->m_motion.m_motionState.m_sweptTransform.m_rotation1,
                  &direction);
                a3 = _mm_unpacklo_ps(
                       _mm_unpacklo_ps((__m128)LODWORD(v5->mfRollMagnitude), (__m128)LODWORD(v5->mfYawMagnitude)),
                       _mm_unpacklo_ps((__m128)LODWORD(v5->mfPitchMagnitude), (__m128)0i64));
                v49.m_quad = _mm_add_ps(v49.m_quad, a3);
                hkVector4f::setRotatedDir(&direction, &v39->m_motion.m_motionState.m_sweptTransform.m_rotation1, &v49);
                hkpEntity::activate(v39);
                ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v39->m_motion.vfptr[9].__first_virtual_table_function__)(
                  &v39->m_motion,
                  &direction);
              }
            }
          }
          goto LABEL_78;
        }
        v25 = v24->m_Flags;
        if ( (v25 >> 14) & 1 )
        {
          v26 = (unsigned int)v24[1].vfptr;
          v27 = v24->m_Components.size;
          if ( v26 < v27 )
          {
            v28 = v24->m_Components.p;
            while ( 1 )
            {
              v29 = v26;
              if ( (v28[v26].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
                && !(UFG::CollectibleComponent::_TypeUID & ~v28[v26].m_TypeUID & 0x1FFFFFF) )
              {
                break;
              }
              if ( ++v26 >= v27 )
                goto LABEL_45;
            }
LABEL_44:
            v30 = v28[v29].m_pComponent;
LABEL_68:
            if ( v30 )
            {
              UFG::qSymbol::qSymbol(&v53, v5->m_NameUID);
              v37 = UFG::GameStatTracker::Instance();
              if ( !UFG::GameStatTracker::GetStat(v37, Collectible_BoostRegion, (UFG::qSymbol *)&v53) )
              {
                v38 = UFG::GameStatTracker::Instance();
                UFG::GameStatTracker::SetStat(v38, Collectible_BoostRegion, (UFG::qSymbol *)&v53, 1);
                a3 = (__m128)LODWORD(FLOAT_5_0);
                UFG::UIHKInfoPopupWidget::Show(
                  UFG::UIHKScreenHud::InfoPopup,
                  "$HUD_COLLECTIBLES_JUMP_SUCCESS",
                  (UFG::qSymbol *)&qSymbol_Collectible_Jump_16.mUID,
                  5.0,
                  0);
              }
            }
            goto LABEL_71;
          }
        }
        else if ( (v25 & 0x8000u) == 0 )
        {
          if ( (v25 >> 13) & 1 )
          {
            v33 = (unsigned int)v24[1].vfptr;
            v34 = v24->m_Components.size;
            if ( v33 < v34 )
            {
              v28 = v24->m_Components.p;
              do
              {
                v29 = v33;
                if ( (v28[v33].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
                  && !(UFG::CollectibleComponent::_TypeUID & ~v28[v33].m_TypeUID & 0x1FFFFFF) )
                {
                  goto LABEL_44;
                }
              }
              while ( ++v33 < v34 );
            }
          }
          else
          {
            if ( !((v25 >> 12) & 1) )
            {
              v30 = UFG::SimObject::GetComponentOfType(v24, UFG::CollectibleComponent::_TypeUID);
              goto LABEL_68;
            }
            v35 = (unsigned int)v24[1].vfptr;
            v36 = v24->m_Components.size;
            if ( v35 < v36 )
            {
              v28 = v24->m_Components.p;
              do
              {
                v29 = v35;
                if ( (v28[v35].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
                  && !(UFG::CollectibleComponent::_TypeUID & ~v28[v35].m_TypeUID & 0x1FFFFFF) )
                {
                  goto LABEL_44;
                }
              }
              while ( ++v35 < v36 );
            }
          }
        }
        else
        {
          v31 = (unsigned int)v24[1].vfptr;
          v32 = v24->m_Components.size;
          if ( v31 < v32 )
          {
            v28 = v24->m_Components.p;
            do
            {
              v29 = v31;
              if ( (v28[v31].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
                && !(UFG::CollectibleComponent::_TypeUID & ~v28[v31].m_TypeUID & 0x1FFFFFF) )
              {
                goto LABEL_44;
              }
            }
            while ( ++v31 < v32 );
          }
        }
LABEL_45:
        v30 = 0i64;
        goto LABEL_68;
      }
    }
    else
    {
      if ( (v11 & 0x8000u) != 0 )
      {
        v16 = (hkSimpleLocalFrame *)v9->m_Components.p[30].m_pComponent;
        goto LABEL_34;
      }
      if ( (v11 >> 13) & 1 )
      {
        v17 = (unsigned int)v9[1].vfptr;
        v18 = v9->m_Components.size;
        if ( v17 < v18 )
        {
          v19 = v9->m_Components.p;
          do
          {
            v15 = (signed __int64)&v19[v17];
            if ( (*(_DWORD *)(v15 + 8) & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
              && !(UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF) )
            {
              goto LABEL_15;
            }
          }
          while ( ++v17 < v18 );
        }
      }
      else
      {
        if ( !((v11 >> 12) & 1) )
        {
          v16 = (hkSimpleLocalFrame *)UFG::SimObject::GetComponentOfType(v9, UFG::VehicleOccupantComponent::_TypeUID);
          goto LABEL_34;
        }
        v20 = (unsigned int)v9[1].vfptr;
        v21 = v9->m_Components.size;
        if ( v20 < v21 )
        {
          v22 = v9->m_Components.p;
          do
          {
            v15 = (signed __int64)&v22[v20];
            if ( (*(_DWORD *)(v15 + 8) & 0xFE000000) == (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
              && !(UFG::VehicleOccupantComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF) )
            {
              goto LABEL_15;
            }
          }
          while ( ++v20 < v21 );
        }
      }
    }
LABEL_16:
    v16 = 0i64;
    goto LABEL_34;
  }
LABEL_79:
  UFG::BoostRegion::UpdateTrackingPost(v5);
  UFG::SensorPhantomIterator::~SensorPhantomIterator(&v52);
}

// File Line: 291
// RVA: 0x556B50
char __fastcall UFG::BoostRegion::TrackObject(UFG::BoostRegion *this, UFG::SimObject *simObject)
{
  UFG::SimObject *v2; // rdi
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v3; // rax
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0> *v4; // rbx
  char result; // al
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::allocator::free_link *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::allocator::free_link *v12; // rcx
  UFG::allocator::free_link *v13; // [rsp+50h] [rbp+18h]

  v2 = simObject;
  v3 = this->mTrackedObjects.mNode.mNext;
  v4 = &this->mTrackedObjects;
  if ( v3 == (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)&this->mTrackedObjects )
  {
LABEL_6:
    v6 = UFG::qMalloc(0x30ui64, "BoostRegionTracker", 0i64);
    v7 = v6;
    if ( v6 )
    {
      v6->mNext = v6;
      v6[1].mNext = v6;
      v13 = v6 + 2;
      v13->mNext = v13;
      v13[1].mNext = v13;
      v13[2].mNext = 0i64;
    }
    else
    {
      v7 = 0i64;
    }
    v8 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7[2];
    if ( v7[4].mNext )
    {
      v9 = v8->mPrev;
      v10 = v7[3].mNext;
      v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v10;
      v10->mNext = (UFG::allocator::free_link *)v9;
      v8->mPrev = v8;
      v7[3].mNext = v7 + 2;
    }
    v7[4].mNext = (UFG::allocator::free_link *)v2;
    if ( v2 )
    {
      v11 = v2->m_SafePointerList.mNode.mPrev;
      v11->mNext = v8;
      v8->mPrev = v11;
      v7[3].mNext = (UFG::allocator::free_link *)&v2->m_SafePointerList;
      v2->m_SafePointerList.mNode.mPrev = v8;
    }
    LOBYTE(v7[5].mNext) = 1;
    v12 = (UFG::allocator::free_link *)v4->mNode.mPrev;
    v12[1].mNext = v7;
    v7->mNext = v12;
    v7[1].mNext = (UFG::allocator::free_link *)v4;
    v4->mNode.mPrev = (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)v7;
    result = 0;
  }
  else
  {
    while ( simObject != (UFG::SimObject *)v3[2].mPrev )
    {
      v3 = v3->mNext;
      if ( v3 == (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)v4 )
        goto LABEL_6;
    }
    LOBYTE(v3[2].mNext) = 1;
    result = 1;
  }
  return result;
}

// File Line: 333
// RVA: 0x561280
void __fastcall UFG::BoostRegion::UpdateTrackingPost(UFG::BoostRegion *this)
{
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v1; // r9
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0> *v2; // rdi
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v3; // rbx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v4; // rax
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v5; // rdx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v6; // rcx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v7; // r8
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v8; // rdx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v9; // rdx
  UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *v10; // rax

  v1 = this->mTrackedObjects.mNode.mNext;
  v2 = &this->mTrackedObjects;
  if ( v1 != (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)&this->mTrackedObjects )
  {
    do
    {
      v3 = v1->mNext;
      if ( !LOBYTE(v1[2].mNext) )
      {
        v4 = v1 + 1;
        if ( v1[2].mPrev )
        {
          v5 = v4->mPrev;
          v6 = v1[1].mNext;
          v5->mNext = v6;
          v6->mPrev = v5;
          v4->mPrev = v4;
          v1[1].mNext = v1 + 1;
        }
        v1[2].mPrev = 0i64;
        v7 = v4->mPrev;
        v8 = v1[1].mNext;
        v7->mNext = v8;
        v8->mPrev = v7;
        v4->mPrev = v4;
        v1[1].mNext = v1 + 1;
        v9 = v1->mPrev;
        v10 = v1->mNext;
        v9->mNext = v10;
        v10->mPrev = v9;
        v1->mPrev = v1;
        v1->mNext = v1;
        operator delete[](v1);
      }
      v1 = v3;
    }
    while ( v3 != (UFG::qNode<UFG::BoostRegionTracker,UFG::BoostRegionTracker> *)v2 );
  }
}

// File Line: 377
// RVA: 0x5443C0
UFG::BoostRegion *__fastcall UFG::BoostRegion::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rdi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rbp
  UFG::SimObject *v4; // rbx
  UFG::qSymbol *v5; // rax
  float *v6; // rax
  float *v7; // rbx
  UFG::qPropertySet *v8; // rcx
  UFG::qPropertySet *v9; // rcx
  UFG::qPropertySet *v10; // rcx
  UFG::qPropertySet *v11; // rcx
  UFG::qPropertySet *v12; // rcx
  UFG::qPropertySet *v13; // rcx
  UFG::qPropertySet *v14; // rcx
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]
  UFG::allocator::free_link *v17; // [rsp+68h] [rbp+10h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0xC0ui64, "BoostRegion", 0i64, 1u);
  v17 = v3;
  if ( v3 )
  {
    v4 = v1->m_pSimObject;
    v5 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
    UFG::BoostRegion::BoostRegion((UFG::BoostRegion *)v3, v5, v4);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v1->mpWritableProperties;
  if ( !v8 )
    v8 = v1->mpConstProperties;
  v7[40] = *UFG::qPropertySet::Get<float>(v8, (UFG::qSymbol *)&UFG::BoostRegion::symBoostMagnitude.mUID, DEPTH_RECURSE);
  v9 = v1->mpWritableProperties;
  if ( !v9 )
    v9 = v1->mpConstProperties;
  v7[41] = *UFG::qPropertySet::Get<float>(
              v9,
              (UFG::qSymbol *)&UFG::BoostRegion::symBoostMagnitudeMin.mUID,
              DEPTH_RECURSE);
  v10 = v1->mpWritableProperties;
  if ( !v10 )
    v10 = v1->mpConstProperties;
  v7[42] = *UFG::qPropertySet::Get<float>(
              v10,
              (UFG::qSymbol *)&UFG::BoostRegion::symBoostMagnitudeMax.mUID,
              DEPTH_RECURSE);
  v11 = v1->mpWritableProperties;
  if ( !v11 )
    v11 = v1->mpConstProperties;
  v7[43] = *UFG::qPropertySet::Get<float>(
              v11,
              (UFG::qSymbol *)&UFG::BoostRegion::symMinSpeedToActivate.mUID,
              DEPTH_RECURSE);
  v12 = v1->mpWritableProperties;
  if ( !v12 )
    v12 = v1->mpConstProperties;
  v7[44] = *UFG::qPropertySet::Get<float>(v12, (UFG::qSymbol *)&UFG::BoostRegion::symRollMagnitude.mUID, DEPTH_RECURSE);
  v13 = v1->mpWritableProperties;
  if ( !v13 )
    v13 = v1->mpConstProperties;
  v7[45] = *UFG::qPropertySet::Get<float>(v13, (UFG::qSymbol *)&UFG::BoostRegion::symPitchMagnitude.mUID, DEPTH_RECURSE);
  v14 = v1->mpWritableProperties;
  if ( !v14 )
    v14 = v1->mpConstProperties;
  v7[46] = *UFG::qPropertySet::Get<float>(v14, (UFG::qSymbol *)&UFG::BoostRegion::symYawMagnitude.mUID, DEPTH_RECURSE);
  return (UFG::BoostRegion *)v7;
}

