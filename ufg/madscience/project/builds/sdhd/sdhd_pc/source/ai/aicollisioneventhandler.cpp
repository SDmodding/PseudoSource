// File Line: 67
// RVA: 0x32C730
void __fastcall UFG::AiCollisionEventHandler::AiCollisionEventHandler(UFG::AiCollisionEventHandler *this)
{
  fastdelegate::FastDelegate1<UFG::Event *,void> v1; // [rsp+30h] [rbp-18h] BYREF

  v1.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  v1.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AiCollisionEventHandler::HandleCollisionEvent;
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v1, UFG::gCollisionEventChannel.mUID, 0i64, 0);
}

// File Line: 74
// RVA: 0x3352F0
void __fastcall UFG::AiCollisionEventHandler::~AiCollisionEventHandler(UFG::AiCollisionEventHandler *this)
{
  fastdelegate::FastDelegate1<UFG::Event *,void> v1; // [rsp+20h] [rbp-18h] BYREF

  v1.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
  v1.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AiCollisionEventHandler::HandleCollisionEvent;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v1, UFG::gCollisionEventChannel.mUID);
}

// File Line: 81
// RVA: 0x37E2B0
void __fastcall UFG::AiCollisionEventHandler::ProcessSlidingEvent(
        UFG::AiCollisionEventHandler *this,
        UFG::CollisionEvent *collisionEvent)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)collisionEvent->mSimObject[0].m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          return;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)m_pPointer->m_Components.p[34].m_pComponent;
      }
      if ( ComponentOfTypeHK )
        UFG::PhysicsMoverInterface::StartSlide(ComponentOfTypeHK);
    }
  }
}

// File Line: 99
// RVA: 0x363BD0
void __fastcall UFG::AiCollisionEventHandler::HandleCollisionEvent(
        UFG::AiCollisionEventHandler *this,
        UFG::CollisionEvent *thisEvent)
{
  UFG::SimObject **p_m_pPointer; // rdi
  UFG::SimObject **simObject; // rbx
  __int64 v6; // r14
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  unsigned int v9; // xmm12_4
  UFG::GameCameraComponent *CurrentGameCamera; // rax
  __int64 v11; // rdi
  int v12; // eax
  __int64 i; // r14
  BOOL v14; // ebx
  UFG::SimObjectGame *v15; // rcx
  __int16 m_Flags; // dx
  _BOOL8 v17; // r12
  UFG::SimObjectGame *v18; // rcx
  hkSimpleLocalFrame *m_pComponent; // r13
  __int16 v20; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v22; // rcx
  __int16 v23; // dx
  UFG::RigidBody *ComponentOfType; // rax
  UFG::SimObject *v25; // rbx
  UFG::StimulusManager *v26; // rdi
  UFG::PhysicsMoverInterface *v27; // rcx
  __m128 x_low; // xmm2
  float v29; // xmm9_4
  UFG::PhysicsVehicle *mPhysicsVehicle; // rcx
  __m128 v31; // xmm2
  float v32; // xmm10_4
  float x; // xmm7_4
  float y; // xmm3_4
  float z; // xmm8_4
  float v36; // xmm6_4
  float v37; // xmm5_4
  float v38; // xmm4_4
  UFG::SimObject *Texture; // rax
  UFG::SimObject *v40; // r13
  UFG::SimObject *v41; // rbx
  UFG::StimulusManager *v42; // rdi
  UFG::StimulusEmitterComponent *v43; // rax
  UFG::PhysicsMoverInterface *v44; // rax
  float mVehicleCollisionMinRamImpulseRequiredToDealDamage; // xmm2_4
  float mVehicleCollisionMaxRamImpulseForDealingDamage; // xmm3_4
  float mVehicleCollisionDamageDealtAtMinRamImpulse; // xmm5_4
  float mVehicleCollisionDamageDealtAtMaxRamImpulse; // xmm1_4
  UFG::PhysicsMoverInterface *v49; // rbx
  float estimatedImpulseMagnitude; // xmm4_4
  float v51; // xmm0_4
  hkLocalFrameGroup *v52; // rbx
  UFG::PhysicsMoverInterface *v53; // rcx
  UFG::PhysicsMoverInterface *v54; // rdx
  UFG::SimObjectCVBase *v55; // rcx
  __int16 v56; // dx
  UFG::CarHumanDriverComponent *v57; // rax
  UFG::OSuiteLeaderboardManager *v58; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::SimObjectCVBase *v60; // rcx
  __int16 v61; // dx
  UFG::AiDriverComponent *v62; // rax
  UFG::SimObjectGame *v63; // rcx
  __int16 v64; // dx
  UFG::SimComponent *v65; // rax
  UFG::SimObjectVehicle *v66; // rcx
  __int16 v67; // dx
  UFG::BikePhysicsMoverComponent *v68; // rax
  UFG::PhysicsMotorBike *PhysicsBike; // rax
  UFG::SimObject *v70; // rbx
  UFG::StimulusManager *v71; // rdi
  UFG::SimObject *v72; // rbx
  UFG::StimulusManager *v73; // rdi
  UFG::SimObject *v74; // r13
  UFG::SimObject *v75; // rbx
  UFG::StimulusManager *v76; // rdi
  UFG::StimulusEmitterComponent *v77; // rax
  UFG::SimObjectGame *v78; // rcx
  __int16 v79; // dx
  UFG::VehicleEffectsComponent *v80; // rax
  UFG::PhysicsObjectProperties *v81; // rax
  float v82; // xmm1_4
  float v83; // xmm2_4
  UFG::PhysicsMoverInterface *v84; // rbx
  float v85; // xmm0_4
  UFG::PhysicsMoverInterface *v86; // rax
  UFG::SimObjectCVBase *v87; // rcx
  __int16 v88; // dx
  UFG::AiDriverComponent *v89; // rax
  UFG::RigidBodyComponent *j; // rbx
  UFG::StateMachineComponent *m_pPointer; // rcx
  UFG::SimObjectCVBase *v92; // rcx
  __int16 v93; // dx
  UFG::CarHumanDriverComponent *v94; // rax
  UFG::CharacterPhysicsComponent *v95; // rcx
  UFG::PhysicsObjectProperties *v96; // rax
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 v98; // dx
  UFG::SimComponent *v99; // rax
  float mForwardSpeed; // xmm6_4
  UFG::PhysicsMoverInterface *v101; // rax
  UFG::SimObject *v102; // rdx
  unsigned __int64 mNameUID; // rcx
  UFG::qReflectObject *mData; // rax
  unsigned __int64 mPrev; // rax
  float v106; // xmm3_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v107; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v108; // rdx
  __int64 v109; // rcx
  float v110; // xmm1_4
  float v111; // xmm2_4
  float v112; // xmm1_4
  float v113; // xmm2_4
  float v114; // xmm1_4
  float v115; // xmm2_4
  UFG::qReflectHandleBase v116; // [rsp+30h] [rbp-98h] BYREF
  void *v117; // [rsp+58h] [rbp-70h]
  __int64 v118; // [rsp+60h] [rbp-68h]
  UFG::HitRecord hitrecord; // [rsp+70h] [rbp-58h] BYREF
  int v120; // [rsp+250h] [rbp+188h]
  hkSimpleLocalFrame *v121; // [rsp+258h] [rbp+190h]
  UFG::SimObject *v122; // [rsp+260h] [rbp+198h]

  v118 = -2i64;
  if ( thisEvent->mType == SLIDING )
    UFG::AiCollisionEventHandler::ProcessSlidingEvent(this, thisEvent);
  if ( thisEvent->mType == UNSUPPORTED )
  {
    p_m_pPointer = &thisEvent->mSimObject[0].m_pPointer;
    if ( thisEvent->mSimObject[1].m_pPointer != thisEvent->mSimObject[0].m_pPointer )
    {
      simObject = this->simObject;
      v6 = 2i64;
      do
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v116);
        TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
        v116.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(
          &v116,
          v116.mTypeUID,
          *(unsigned __int64 *)((char *)simObject + (char *)thisEvent - (char *)this + 176));
        *(simObject - 2) = (UFG::SimObject *)v116.mData;
        *simObject = *p_m_pPointer;
        UFG::qReflectHandleBase::~qReflectHandleBase(&v116);
        ++simObject;
        p_m_pPointer += 3;
        --v6;
      }
      while ( v6 );
      UFG::AiCollisionEventHandler::Initialize(this);
      v9 = LODWORD(thisEvent->speed) & _xmm;
      CurrentGameCamera = UFG::GetCurrentGameCamera();
      v11 = (__int64)CurrentGameCamera;
      v117 = CurrentGameCamera;
      if ( CurrentGameCamera )
        CurrentGameCamera = (UFG::GameCameraComponent *)((__int64 (__fastcall *)(UFG::GameCameraComponent *))CurrentGameCamera->vfptr[17].__vecDelDtor)(CurrentGameCamera);
      v122 = (UFG::SimObject *)CurrentGameCamera;
      v12 = 0;
      v120 = 0;
      for ( i = 0i64; ; ++i )
      {
        v14 = v12 == 0;
        v15 = (UFG::SimObjectGame *)this->simObject[i];
        if ( v15 )
        {
          m_Flags = v15->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
            goto LABEL_16;
          if ( m_Flags >= 0 )
            break;
        }
LABEL_18:
        v17 = v14;
        v18 = (UFG::SimObjectGame *)this->simObject[v14];
        if ( !v18 )
        {
          m_pComponent = 0i64;
          goto LABEL_29;
        }
        v20 = v18->m_Flags;
        if ( (v20 & 0x4000) != 0 )
          goto LABEL_26;
        if ( v20 < 0 )
        {
          m_pComponent = (hkSimpleLocalFrame *)v18->m_Components.p[30].m_pComponent;
          goto LABEL_29;
        }
        if ( (v20 & 0x2000) != 0 || (v20 & 0x1000) != 0 )
LABEL_26:
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::VehicleOccupantComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v18, UFG::VehicleOccupantComponent::_TypeUID);
        m_pComponent = (hkSimpleLocalFrame *)ComponentOfTypeHK;
LABEL_29:
        v121 = m_pComponent;
        if ( this->vehicle[i] )
        {
          v22 = (UFG::SimObjectGame *)this->simObject[v14];
          if ( v22 )
          {
            v23 = v22->m_Flags;
            if ( (v23 & 0x4000) != 0 || v23 < 0 || (v23 & 0x2000) != 0 || (v23 & 0x1000) != 0 )
              ComponentOfType = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v22,
                                                    UFG::RigidBodyComponent::_TypeUID);
            else
              ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                                    v22,
                                                    UFG::RigidBodyComponent::_TypeUID);
            if ( ComponentOfType && (unsigned int)UFG::RigidBody::GetCollisionLayer(ComponentOfType) == 9 )
            {
              v116.mPrev = *(UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> **)&UFG::qVector3::msZero.x;
              v116.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)LODWORD(UFG::qVector3::msZero.z);
              v116.mTypeUID = 0xBF800000BF800000ui64;
              v25 = this->simObject[i];
              v26 = UFG::StimulusManager::s_pInstance;
              UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
                UFG::StimulusManager::s_pInstance,
                eSTIMULUS_CAR_HIT_BUILDING,
                v25);
              UFG::StimulusManager::AttachStimulusEmitterComponent(
                v26,
                &stimulus_description,
                (UFG::StimulusParameters *)&v116,
                v25,
                0);
              v11 = (__int64)v117;
            }
          }
        }
        if ( v122 && v122 == this->simObject[i] )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v11 + 264i64))(v11);
        v27 = this->vehicle[i];
        if ( !v27 )
          goto LABEL_151;
        x_low = (__m128)LODWORD(thisEvent->velocity[i].x);
        x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                  + (float)(thisEvent->velocity[i].y * thisEvent->velocity[i].y))
                          + (float)(thisEvent->velocity[i].z * thisEvent->velocity[i].z);
        v29 = _mm_sqrt_ps(x_low).m128_f32[0] * 3.5999999;
        mPhysicsVehicle = v27->mPhysicsVehicle;
        if ( mPhysicsVehicle && (*((_DWORD *)mPhysicsVehicle + 151) & 7) == 4 )
          UFG::PhysicsCar::ProcessCollisonEvent((UFG::PhysicsCar *)mPhysicsVehicle, thisEvent);
        if ( this->vehicle[v17] )
        {
          v31 = (__m128)LODWORD(thisEvent->velocity[v17].x);
          v31.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0])
                                  + (float)(thisEvent->velocity[v17].y * thisEvent->velocity[v17].y))
                          + (float)(thisEvent->velocity[v17].z * thisEvent->velocity[v17].z);
          v32 = _mm_sqrt_ps(v31).m128_f32[0] * 3.5999999;
          x = thisEvent->velocity[i].x;
          y = thisEvent->velocity[i].y;
          z = thisEvent->velocity[i].z;
          if ( (float)((float)((float)(y * y) + (float)(x * x)) + (float)(z * z)) > 0.001 )
          {
            v36 = thisEvent->preCollisionPosition[v17].z - thisEvent->preCollisionPosition[i].z;
            v37 = thisEvent->preCollisionPosition[v17].y - thisEvent->preCollisionPosition[i].y;
            v38 = thisEvent->preCollisionPosition[v17].x - thisEvent->preCollisionPosition[i].x;
            if ( (float)((float)((float)(v37 * v37) + (float)(v38 * v38)) + (float)(v36 * v36)) > 0.001
              && ((float)((float)((float)(y * v37) + (float)(x * v38)) + (float)(z * v36)) >= 0.866
               || (*((_BYTE *)this->vehicle[i] + 900) & 1) != 0) )
            {
              Texture = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(m_pComponent);
              v40 = Texture;
              if ( Texture )
              {
                v116.mPrev = *(UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> **)&UFG::qVector3::msZero.x;
                v116.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)LODWORD(UFG::qVector3::msZero.z);
                v116.mTypeUID = 0xBF800000BF800000ui64;
                v41 = this->simObject[i];
                v42 = UFG::StimulusManager::s_pInstance;
                UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
                  UFG::StimulusManager::s_pInstance,
                  eSTIMULUS_CAR_HIT_MY_CAR,
                  v41,
                  Texture);
                v43 = UFG::StimulusManager::AttachStimulusEmitterComponent(
                        v42,
                        &stru_1423C0C78,
                        (UFG::StimulusParameters *)&v116,
                        v41,
                        0);
                if ( v43 )
                  UFG::StimulusEmitterComponent::SetIsTargeted(v43, v40);
              }
              v44 = this->vehicle[i];
              if ( (*((_BYTE *)v44 + 900) & 8) != 0 )
              {
                mVehicleCollisionMinRamImpulseRequiredToDealDamage = v44->mVehicleCollisionMinRamImpulseRequiredToDealDamage;
                mVehicleCollisionMaxRamImpulseForDealingDamage = v44->mVehicleCollisionMaxRamImpulseForDealingDamage;
                mVehicleCollisionDamageDealtAtMinRamImpulse = v44->mVehicleCollisionDamageDealtAtMinRamImpulse;
                mVehicleCollisionDamageDealtAtMaxRamImpulse = v44->mVehicleCollisionDamageDealtAtMaxRamImpulse;
              }
              else
              {
                mVehicleCollisionMinRamImpulseRequiredToDealDamage = v44->mVehicleCollisionMinImpulseRequiredToDealDamage;
                mVehicleCollisionMaxRamImpulseForDealingDamage = v44->mVehicleCollisionMaxImpulseForDealingDamage;
                mVehicleCollisionDamageDealtAtMinRamImpulse = v44->mVehicleCollisionDamageDealtAtMinImpulse;
                mVehicleCollisionDamageDealtAtMaxRamImpulse = v44->mVehicleCollisionDamageDealtAtMaxImpulse;
              }
              v49 = this->vehicle[v17];
              if ( v49->mPostRamImmunityTimer > 0.0 )
                mVehicleCollisionMinRamImpulseRequiredToDealDamage = v44->mVehicleCollisionMaxImpulseForDealingDamage
                                                                   * 0.89999998;
              estimatedImpulseMagnitude = thisEvent->estimatedImpulseMagnitude;
              if ( estimatedImpulseMagnitude >= v49->mVehicleCollisionMinImpulseRequiredToTakeDamage
                && estimatedImpulseMagnitude >= mVehicleCollisionMinRamImpulseRequiredToDealDamage )
              {
                v51 = UFG::AiCollisionEventHandler::ComputeDamageFromImpulseMagnitude(
                        mVehicleCollisionDamageDealtAtMinRamImpulse,
                        mVehicleCollisionDamageDealtAtMaxRamImpulse,
                        mVehicleCollisionMinRamImpulseRequiredToDealDamage,
                        mVehicleCollisionMaxRamImpulseForDealingDamage,
                        thisEvent->estimatedImpulseMagnitude);
                if ( (unsigned __int8)UFG::PhysicsMoverInterface::DamageEngine(
                                        v49,
                                        this->simObject[i],
                                        v51,
                                        dtVEHICLE_COLLISION) )
                {
                  if ( this->vehicle[v17]->mSecondsEngineHasBeenDeteriorating >= 0.5
                    && thisEvent->estimatedImpulseMagnitude >= 5.0 )
                  {
                    v52 = (hkLocalFrameGroup *)LocalPlayer;
                    if ( Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v121) != v52 )
                      *((_BYTE *)this->vehicle[v17] + 900) |= 0x10u;
                  }
                  v53 = this->vehicle[i];
                  if ( (*((_BYTE *)v53 + 900) & 8) != 0 )
                  {
                    v54 = this->vehicle[v17];
                    if ( (unsigned int)(v54->mDestructState - 1) > 1 )
                    {
                      UFG::AiCollisionEventHandler::InjectRamCollisionVelocities(v53, v54);
                      this->vehicle[v17]->mPostRamImmunityTimer = 2.5;
                      v55 = (UFG::SimObjectCVBase *)this->simObject[i];
                      if ( v55 )
                      {
                        v56 = v55->m_Flags;
                        if ( (v56 & 0x4000) != 0 || v56 < 0 )
                          v57 = UFG::SimObjectCVBase::GetComponent<UFG::CarHumanDriverComponent>(v55);
                        else
                          v57 = (UFG::CarHumanDriverComponent *)((v56 & 0x2000) != 0 || (v56 & 0x1000) != 0
                                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v55,
                                                                   UFG::CarHumanDriverComponent::_TypeUID)
                                                               : UFG::SimObject::GetComponentOfType(
                                                                   v55,
                                                                   UFG::CarHumanDriverComponent::_TypeUID));
                        if ( v57 )
                        {
                          v58 = UFG::OSuiteLeaderboardManager::Instance();
                          LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                                                  v58,
                                                                  "StatGamesVehicleTakedownStreak");
                          UFG::StatGameManager::UpdateScore(LeaderboardDataUsingLeaderboardName, 1, 1);
                        }
                      }
                    }
                  }
                }
                v60 = (UFG::SimObjectCVBase *)this->simObject[v17];
                if ( v60 )
                {
                  v61 = v60->m_Flags;
                  if ( (v61 & 0x4000) != 0 || v61 < 0 )
                    v62 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v60);
                  else
                    v62 = (UFG::AiDriverComponent *)((v61 & 0x2000) != 0 || (v61 & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v60,
                                                       UFG::AiDriverComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       v60,
                                                       UFG::AiDriverComponent::_TypeUID));
                  if ( v62 )
                    UFG::AiDriverComponent::HandleCollision(v62, this->simObject[i], v51, dtVEHICLE_COLLISION);
                }
              }
            }
          }
          v63 = (UFG::SimObjectGame *)this->simObject[v17];
          if ( !v63
            || ((v64 = v63->m_Flags, (v64 & 0x4000) == 0)
              ? (v64 >= 0
               ? ((v64 & 0x2000) != 0 || (v64 & 0x1000) != 0
                ? (v65 = UFG::SimObjectGame::GetComponentOfTypeHK(v63, UFG::VehicleDriverInterface::_TypeUID))
                : (v65 = UFG::SimObject::GetComponentOfType(v63, UFG::VehicleDriverInterface::_TypeUID)))
               : (v65 = v63->m_Components.p[23].m_pComponent))
              : (v65 = v63->m_Components.p[23].m_pComponent),
                !v65) )
          {
            v66 = (UFG::SimObjectVehicle *)this->simObject[v17];
            if ( v66 )
            {
              v67 = v66->m_Flags;
              if ( (v67 & 0x4000) == 0 )
              {
                if ( v67 >= 0 )
                  v68 = (UFG::BikePhysicsMoverComponent *)((v67 & 0x2000) != 0 || (v67 & 0x1000) != 0
                                                         ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v66,
                                                             UFG::BikePhysicsMoverComponent::_TypeUID)
                                                         : UFG::SimObject::GetComponentOfType(
                                                             v66,
                                                             UFG::BikePhysicsMoverComponent::_TypeUID));
                else
                  v68 = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(v66);
                if ( v68 )
                {
                  PhysicsBike = UFG::BikePhysicsMoverComponent::GetPhysicsBike(v68);
                  if ( PhysicsBike )
                    PhysicsBike->mDisableConstraint = 1;
                }
              }
            }
          }
          if ( v29 > 10.0 && v29 > v32 )
          {
            v116.mPrev = *(UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> **)&UFG::qVector3::msZero.x;
            v116.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)LODWORD(UFG::qVector3::msZero.z);
            v116.mTypeUID = 0xBF800000BF800000ui64;
            v70 = this->simObject[i];
            v71 = UFG::StimulusManager::s_pInstance;
            UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
              UFG::StimulusManager::s_pInstance,
              eSTIMULUS_CAR_HIT_CAR,
              v70);
            UFG::StimulusManager::AttachStimulusEmitterComponent(
              v71,
              &stru_1423C0BE8,
              (UFG::StimulusParameters *)&v116,
              v70,
              0);
          }
        }
        else if ( this->characterPhysics[v17] )
        {
          if ( gMinVehicleHitPedStimulusVelocity < thisEvent->estimatedImpulseMagnitude && v29 > 2.0 )
          {
            v116.mPrev = *(UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> **)&UFG::qVector3::msZero.x;
            v116.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)LODWORD(UFG::qVector3::msZero.z);
            v116.mTypeUID = 0xBF800000BF800000ui64;
            v72 = this->simObject[i];
            v73 = UFG::StimulusManager::s_pInstance;
            UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
              UFG::StimulusManager::s_pInstance,
              eSTIMULUS_VEHICLE_HIT_PED,
              v72);
            UFG::StimulusManager::AttachStimulusEmitterComponent(
              v73,
              &stru_1423C0690,
              (UFG::StimulusParameters *)&v116,
              v72,
              0);
            HIDWORD(v116.mNext) = 0;
            v74 = this->simObject[v17];
            v75 = this->simObject[i];
            v76 = UFG::StimulusManager::s_pInstance;
            UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
              UFG::StimulusManager::s_pInstance,
              eSTIMULUS_VEHICLE_HIT_YOU,
              v75,
              v74);
            v77 = UFG::StimulusManager::AttachStimulusEmitterComponent(
                    v76,
                    &stru_1423C06D8,
                    (UFG::StimulusParameters *)&v116,
                    v75,
                    0);
            if ( v74 )
            {
              if ( v77 )
                UFG::StimulusEmitterComponent::SetIsTargeted(v77, v74);
            }
          }
        }
        v78 = (UFG::SimObjectGame *)this->simObject[i];
        if ( v78 )
        {
          v79 = v78->m_Flags;
          if ( (v79 & 0x4000) != 0 )
            goto LABEL_127;
          if ( v79 >= 0 )
          {
            if ( (v79 & 0x2000) != 0 || (v79 & 0x1000) != 0 )
LABEL_127:
              v80 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v78,
                                                      UFG::VehicleEffectsComponent::_TypeUID);
            else
              v80 = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                      v78,
                                                      UFG::VehicleEffectsComponent::_TypeUID);
          }
          else
          {
            v80 = (UFG::VehicleEffectsComponent *)v78->m_Components.p[32].m_pComponent;
          }
          if ( v80 )
            UFG::VehicleEffectsComponent::PlayCollisionFX(v80, thisEvent, v29);
        }
        v81 = this->physicsObjectProperties[v17];
        if ( v81 )
        {
          if ( v81->mMotionType == CGF_STATIC )
          {
            v82 = thisEvent->estimatedImpulseMagnitude;
            v83 = FLOAT_5_0;
            if ( v82 >= 5.0 )
            {
              v84 = this->vehicle[i];
              if ( v84->mPostRamImmunityTimer > 0.0 )
                v83 = FLOAT_9_0;
              v85 = UFG::AiCollisionEventHandler::ComputeDamageFromImpulseMagnitude(
                      0.0049999999,
                      0.050000001,
                      v83,
                      10.0,
                      v82);
              if ( v84 )
              {
                if ( (unsigned __int8)UFG::PhysicsMoverInterface::DamageEngine(v84, 0i64, v85, dtWORLD_COLLISION) )
                {
                  v86 = this->vehicle[i];
                  if ( v86->mSecondsEngineHasBeenDeteriorating >= 0.5 && thisEvent->estimatedImpulseMagnitude >= 5.0 )
                    *((_BYTE *)v86 + 900) |= 0x10u;
                }
              }
              v87 = (UFG::SimObjectCVBase *)this->simObject[i];
              if ( v87 )
              {
                v88 = v87->m_Flags;
                if ( (v88 & 0x4000) != 0 || v88 < 0 )
                  v89 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v87);
                else
                  v89 = (UFG::AiDriverComponent *)((v88 & 0x2000) != 0 || (v88 & 0x1000) != 0
                                                 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v87,
                                                     UFG::AiDriverComponent::_TypeUID)
                                                 : UFG::SimObject::GetComponentOfType(
                                                     v87,
                                                     UFG::AiDriverComponent::_TypeUID));
                if ( v89 )
                  UFG::AiDriverComponent::HandleCollision(v89, 0i64, v85, dtWORLD_COLLISION);
              }
            }
          }
        }
LABEL_151:
        for ( j = this->rigidBody[i];
              j;
              j = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(
                                               j->m_pSimObject,
                                               UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                               0,
                                               j) )
        {
          m_pPointer = (UFG::StateMachineComponent *)j->mStateMachineComponent.m_pPointer;
          if ( m_pPointer )
            UFG::StateMachineComponent::ApplyDamage(
              m_pPointer,
              thisEvent->estimatedImpulseMagnitude,
              IMPACT_DAMAGE,
              this->simObject[v17]);
        }
        v92 = (UFG::SimObjectCVBase *)this->simObject[i];
        if ( v92 )
        {
          v93 = v92->m_Flags;
          if ( (v93 & 0x4000) != 0 || v93 < 0 )
            v94 = UFG::SimObjectCVBase::GetComponent<UFG::CarHumanDriverComponent>(v92);
          else
            v94 = (UFG::CarHumanDriverComponent *)((v93 & 0x2000) != 0 || (v93 & 0x1000) != 0
                                                 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v92,
                                                     UFG::CarHumanDriverComponent::_TypeUID)
                                                 : UFG::SimObject::GetComponentOfType(
                                                     v92,
                                                     UFG::CarHumanDriverComponent::_TypeUID));
          if ( v94 )
            UFG::CarHumanDriverComponent::StopCollisionFreeDrive(v94);
        }
        if ( this->hitComp[i] )
        {
          v95 = this->characterPhysics[i];
          if ( !v95
            || ((v96 = this->physicsObjectProperties[v17]) == 0i64
             || v96->mMotionType != CGF_STATIC && !v96->mNoHitReactionsOnWorldCollisions)
            && ((m_pSimObject = (UFG::SimObjectGame *)v95->m_pSimObject) == 0i64
             || ((v98 = m_pSimObject->m_Flags, (v98 & 0x4000) == 0)
               ? (v98 >= 0
                ? ((v98 & 0x2000) != 0 || (v98 & 0x1000) != 0
                 ? (v99 = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::HealthComponent::_TypeUID))
                 : (v99 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::HealthComponent::_TypeUID)))
                : (v99 = m_pSimObject->m_Components.p[6].m_pComponent))
               : (v99 = m_pSimObject->m_Components.p[6].m_pComponent),
                 !v99 || !BYTE5(v99[1].m_BoundComponentHandles.mNode.mPrev))) )
          {
            if ( !this->characterPhysics[v17] )
            {
              mForwardSpeed = 0.0;
              v101 = this->vehicle[i];
              if ( v101 )
                mForwardSpeed = v101->mForwardSpeed;
              UFG::HitRecord::HitRecord(&hitrecord);
              v102 = this->simObject[v17];
              hitrecord.mAttackTypeID = gAttackTypeWorldCollision.m_EnumValue;
              hitrecord.mDamage = 100;
              if ( v117 )
              {
                mNameUID = v116.mNameUID;
                mData = v116.mData;
                *(_QWORD *)(v116.mNameUID + 8) = v116.mData;
                mData->vfptr = (UFG::qReflectObjectVtbl *)mNameUID;
                v116.mNameUID = (unsigned __int64)&v116.mNameUID;
                v116.mData = (UFG::qReflectObject *)&v116.mNameUID;
              }
              v117 = v102;
              if ( v102 )
              {
                mPrev = (unsigned __int64)v102->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                *(_QWORD *)(mPrev + 8) = &v116.mNameUID;
                v116.mNameUID = mPrev;
                v116.mData = (UFG::qReflectObject *)&v102->m_SafePointerList;
                v102->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v116.mNameUID;
              }
              v118 = 0i64;
              v106 = thisEvent->estimatedImpulseMagnitude;
              v107 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)thisEvent->surfacePropertyHandleUID[v17];
              v108 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)thisEvent->surfacePropertyHandleUID[i];
              v109 = thisEvent->objectPropertyHandleUID[v17];
              *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount = thisEvent->objectPropertyHandleUID[i];
              hitrecord.mMeleeInfo.mActionPath.mPath.mData.mOffset = v109;
              hitrecord.mProjectileInfo.m_pSOWPC.mPrev = v108;
              hitrecord.mProjectileInfo.m_pSOWPC.mNext = v107;
              v110 = thisEvent->position.y;
              v111 = thisEvent->position.z;
              *(float *)&hitrecord.mProjectileInfo.m_pSOWPC.m_pPointer = thisEvent->position.x;
              *((float *)&hitrecord.mProjectileInfo.m_pSOWPC.m_pPointer + 1) = v110;
              *(float *)&hitrecord.mProjectileInfo.m_pSubTargetingLocation = v111;
              v112 = thisEvent->normal.y;
              v113 = thisEvent->normal.z;
              HIDWORD(hitrecord.mProjectileInfo.m_pSubTargetingLocation) = LODWORD(thisEvent->normal.x);
              *(float *)&hitrecord.mProjectileInfo.m_bIsFullyAccurate = v112;
              *(float *)(&hitrecord.mProjectileInfo.m_bIsHardLocked + 3) = v113;
              v114 = thisEvent->velocity[v17].y;
              v115 = thisEvent->velocity[v17].z;
              *(float *)&hitrecord.mCollisionInfo.mPhysicsObjectPropertyHandleUID = thisEvent->velocity[v17].x;
              *((float *)&hitrecord.mCollisionInfo.mPhysicsObjectPropertyHandleUID + 1) = v114;
              hitrecord.mCollisionInfo.mAttackerPhysicsObjectPropertyHandleUID = __PAIR64__(v9, LODWORD(v115));
              hitrecord.mCollisionInfo.mSurfacePropertyHandleUID = __PAIR64__(LODWORD(v106), LODWORD(mForwardSpeed));
              UFG::HitReactionComponent::HandleHitReaction(this->hitComp[i], &hitrecord);
              UFG::HitRecord::~HitRecord(&hitrecord);
            }
          }
        }
        v12 = v120 + 1;
        v120 = v12;
        v11 = (__int64)v117;
        if ( v12 >= 2 )
          return;
      }
      if ( (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0 )
      {
        UFG::SimObject::GetComponentOfType(v15, UFG::VehicleOccupantComponent::_TypeUID);
        goto LABEL_18;
      }
LABEL_16:
      UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::VehicleOccupantComponent::_TypeUID);
      goto LABEL_18;
    }
  }
}ORD(mForwardSpeed));
              UFG::HitReactionComponent::HandleHitReaction(this->hitComp[i], &hitrecord);
              UFG::HitRecord::~HitRecord(&hitrecord);
            }
          }
        }
        v

// File Line: 579
// RVA: 0x368C40
void __fastcall UFG::AiCollisionEventHandler::Initialize(UFG::AiCollisionEventHandler *this)
{
  UFG::SimObject **simObject; // rbx
  __int64 v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *v6; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v8; // cx
  UFG::SimObjectProp *v9; // rcx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  __int16 v11; // dx
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *v13; // rax
  __int16 v14; // dx
  UFG::SimObjectGame *v15; // rcx
  UFG::SimComponent *v16; // rax
  __int16 v17; // dx
  UFG::SimObjectGame *v18; // rcx
  __int16 v19; // dx

  simObject = this->simObject;
  v2 = 2i64;
  do
  {
    v3 = (UFG::SimObjectGame *)*simObject;
    if ( !*simObject )
    {
      simObject[2] = 0i64;
      simObject[4] = 0i64;
      simObject[6] = 0i64;
      simObject[8] = 0i64;
      simObject[10] = 0i64;
      simObject[12] = 0i64;
      goto LABEL_62;
    }
    m_Flags = v3->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v3->m_Components.p[15].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(v3, UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      m_pComponent = v3->m_Components.p[15].m_pComponent;
    }
    v6 = (UFG::SimObjectGame *)*simObject;
    simObject[2] = (UFG::SimObject *)m_pComponent;
    if ( v6 )
    {
      v8 = v6->m_Flags;
      if ( (v8 & 0x4000) != 0 )
      {
        ComponentOfTypeHK = 0i64;
      }
      else if ( v8 >= 0 )
      {
        if ( (v8 & 0x2000) != 0 )
        {
          ComponentOfTypeHK = 0i64;
        }
        else if ( (v8 & 0x1000) != 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::PhysicsMoverInterface::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v6, UFG::PhysicsMoverInterface::_TypeUID);
        }
      }
      else
      {
        ComponentOfTypeHK = v6->m_Components.p[34].m_pComponent;
      }
    }
    else
    {
      ComponentOfTypeHK = 0i64;
    }
    v9 = (UFG::SimObjectProp *)*simObject;
    simObject[4] = (UFG::SimObject *)ComponentOfTypeHK;
    if ( v9 )
    {
      v11 = v9->m_Flags;
      if ( (v11 & 0x4000) != 0 || v11 < 0 )
        goto LABEL_30;
      if ( (v11 & 0x2000) == 0 )
      {
        if ( (v11 & 0x1000) == 0 )
        {
          ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                         v9,
                                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          goto LABEL_32;
        }
LABEL_30:
        ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v9,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        goto LABEL_32;
      }
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v9);
    }
    else
    {
      ComponentOfType = 0i64;
    }
LABEL_32:
    v12 = (UFG::SimObjectGame *)*simObject;
    simObject[6] = (UFG::SimObject *)ComponentOfType;
    if ( v12 )
    {
      v14 = v12->m_Flags;
      if ( (v14 & 0x4000) != 0 || v14 < 0 || (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RigidBodyComponent::_TypeUID);
      else
        v13 = UFG::SimObject::GetComponentOfType(v12, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v13 = 0i64;
    }
    v15 = (UFG::SimObjectGame *)*simObject;
    simObject[8] = (UFG::SimObject *)v13;
    if ( v15 )
    {
      v17 = v15->m_Flags;
      if ( (v17 & 0x4000) != 0 )
      {
        v16 = v15->m_Components.p[27].m_pComponent;
      }
      else if ( v17 < 0 || (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0 )
      {
        v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      else
      {
        v16 = UFG::SimObject::GetComponentOfType(v15, UFG::CharacterPhysicsComponent::_TypeUID);
      }
    }
    else
    {
      v16 = 0i64;
    }
    v18 = (UFG::SimObjectGame *)*simObject;
    simObject[10] = (UFG::SimObject *)v16;
    if ( v18 )
    {
      v19 = v18->m_Flags;
      if ( (v19 & 0x4000) != 0 )
      {
        simObject[12] = (UFG::SimObject *)v18->m_Components.p[42].m_pComponent;
      }
      else if ( v19 < 0 || (v19 & 0x2000) != 0 || (v19 & 0x1000) != 0 )
      {
        simObject[12] = (UFG::SimObject *)UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        simObject[12] = (UFG::SimObject *)UFG::SimObject::GetComponentOfType(v18, UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      simObject[12] = 0i64;
    }
LABEL_62:
    ++simObject;
    --v2;
  }
  while ( v2 );
}

// File Line: 608
// RVA: 0x34F900
float __fastcall UFG::AiCollisionEventHandler::ComputeDamageFromImpulseMagnitude(
        float fMinDamage,
        float fMaxDamage,
        float fMinImpulse,
        float fMaxImpulse,
        float fEstimatedImpulseMagnitude)
{
  if ( fEstimatedImpulseMagnitude < fMinImpulse )
    return 0.0;
  if ( fEstimatedImpulseMagnitude > fMaxImpulse
    || COERCE_FLOAT(COERCE_UNSIGNED_INT(fMaxImpulse - fMinImpulse) & _xmm) < 0.000099999997 )
  {
    return fMaxDamage;
  }
  return (float)((float)((float)((float)((float)(fEstimatedImpulseMagnitude * fEstimatedImpulseMagnitude) * 0.5)
                               - (float)((float)(fMinImpulse * fMinImpulse) * 0.5))
                       / (float)((float)((float)(fMaxImpulse * fMaxImpulse) * 0.5)
                               - (float)((float)(fMinImpulse * fMinImpulse) * 0.5)))
               * (float)(fMaxDamage - fMinDamage))
       + fMinDamage;
}

// File Line: 674
// RVA: 0x369320
void __fastcall UFG::AiCollisionEventHandler::InjectRamCollisionVelocities(
        UFG::PhysicsMoverInterface *pRammerPMI,
        UFG::PhysicsMoverInterface *pVictimPMI)
{
  hkpEntity *RigidBody; // rbx
  hkpEntity *v5; // rax
  hkpEntity *v6; // rdi
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm6
  __m128 v13; // xmm4
  float v14; // xmm5_4
  __m128 v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // [rsp+20h] [rbp-28h] BYREF

  if ( pRammerPMI )
  {
    if ( pVictimPMI )
    {
      RigidBody = (hkpEntity *)UFG::PhysicsMoverInterface::GetRigidBody(pRammerPMI);
      v5 = (hkpEntity *)UFG::PhysicsMoverInterface::GetRigidBody(pVictimPMI);
      v6 = v5;
      if ( RigidBody )
      {
        if ( v5 )
        {
          v7 = _mm_unpacklo_ps(
                 _mm_unpacklo_ps(
                   (__m128)LODWORD(pRammerPMI->mRamVelocity.x),
                   (__m128)LODWORD(pRammerPMI->mRamVelocity.z)),
                 _mm_unpacklo_ps((__m128)LODWORD(pRammerPMI->mRamVelocity.y), (__m128)0i64));
          v8 = _mm_mul_ps(v7, v7);
          v9 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                 _mm_shuffle_ps(v8, v8, 170));
          v10 = _mm_rsqrt_ps(v9);
          v11 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v9), (__m128)0i64);
          v12 = _mm_and_ps(
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmple_ps(v9, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                        _mm_mul_ps(*(__m128 *)_xmm, v10))),
                    v7),
                  v11);
          v13 = _mm_andnot_ps(v11, v7);
          v14 = FLOAT_8_0;
          v15 = _mm_or_ps(v12, v13);
          v16 = _mm_mul_ps(v5->m_motion.m_linearVelocity.m_quad, v15);
          if ( (float)((float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0])
                     + _mm_shuffle_ps(v16, v16, 170).m128_f32[0]) < 8.0 )
          {
            v19 = _mm_add_ps(_mm_mul_ps((__m128)_xmm, v15), v5->m_motion.m_linearVelocity.m_quad);
            hkpEntity::activate(v5);
            v6->m_motion.vfptr[9].__vecDelDtor(&v6->m_motion, (unsigned int)&v19);
            v14 = FLOAT_8_0;
          }
          v17 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v15);
          v18 = _mm_mul_ps(RigidBody->m_motion.m_linearVelocity.m_quad, v17);
          if ( (float)((float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0] + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
                     + _mm_shuffle_ps(v18, v18, 170).m128_f32[0]) < v14 )
          {
            v19 = _mm_add_ps(_mm_mul_ps((__m128)_xmm, v17), RigidBody->m_motion.m_linearVelocity.m_quad);
            hkpEntity::activate(RigidBody);
            RigidBody->m_motion.vfptr[9].__vecDelDtor(&RigidBody->m_motion, (unsigned int)&v19);
          }
        }
      }
    }
  }
}

