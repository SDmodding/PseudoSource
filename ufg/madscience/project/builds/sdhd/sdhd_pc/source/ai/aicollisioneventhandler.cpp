// File Line: 67
// RVA: 0x32C730
void __fastcall UFG::AiCollisionEventHandler::AiCollisionEventHandler(UFG::AiCollisionEventHandler *this)
{
  UFG::AiCollisionEventHandler *v1; // [rsp+30h] [rbp-18h]
  void (__fastcall *v2)(UFG::AiCollisionEventHandler *, UFG::CollisionEvent *); // [rsp+38h] [rbp-10h]

  v1 = this;
  v2 = UFG::AiCollisionEventHandler::HandleCollisionEvent;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v1,
    UFG::gCollisionEventChannel.mUID,
    0i64,
    0);
}

// File Line: 74
// RVA: 0x3352F0
void __fastcall UFG::AiCollisionEventHandler::~AiCollisionEventHandler(UFG::AiCollisionEventHandler *this)
{
  UFG::AiCollisionEventHandler *v1; // [rsp+20h] [rbp-18h]
  void (__fastcall *v2)(UFG::AiCollisionEventHandler *, UFG::CollisionEvent *); // [rsp+28h] [rbp-10h]

  v1 = this;
  v2 = UFG::AiCollisionEventHandler::HandleCollisionEvent;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v1,
    UFG::gCollisionEventChannel.mUID);
}

// File Line: 81
// RVA: 0x37E2B0
void __fastcall UFG::AiCollisionEventHandler::ProcessSlidingEvent(UFG::AiCollisionEventHandler *this, UFG::CollisionEvent *collisionEvent)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::PhysicsMoverInterface *v4; // rax

  v2 = (UFG::SimObjectGame *)collisionEvent->mSimObject[0].m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( !((v3 >> 14) & 1) )
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
          return;
        if ( (v3 >> 12) & 1 )
          v4 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v2,
                                               UFG::PhysicsMoverInterface::_TypeUID);
        else
          v4 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v2->vfptr,
                                               UFG::PhysicsMoverInterface::_TypeUID);
      }
      else
      {
        v4 = (UFG::PhysicsMoverInterface *)v2->m_Components.p[34].m_pComponent;
      }
      if ( v4 )
        UFG::PhysicsMoverInterface::StartSlide(v4);
    }
  }
}

// File Line: 99
// RVA: 0x363BD0
void __fastcall UFG::AiCollisionEventHandler::HandleCollisionEvent(UFG::AiCollisionEventHandler *this, UFG::CollisionEvent *thisEvent)
{
  UFG::CollisionEvent *v2; // r15
  UFG::AiCollisionEventHandler *v3; // rsi
  UFG::SimObject **v4; // rdi
  UFG::SimObject **v5; // rbx
  signed __int64 v6; // r14
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  unsigned int v9; // xmm12_4
  UFG::GameCameraComponent *v10; // rax
  __int64 v11; // rdi
  int v12; // eax
  __int64 v13; // r14
  BOOL v14; // ebx
  UFG::SimObjectGame *v15; // rcx
  unsigned __int16 v16; // dx
  _BOOL8 v17; // r12
  UFG::SimObjectGame *v18; // rcx
  hkSimpleLocalFrame *v19; // r13
  unsigned __int16 v20; // dx
  UFG::SimComponent *v21; // rax
  UFG::SimObjectGame *v22; // rcx
  unsigned __int16 v23; // dx
  UFG::RigidBody *v24; // rax
  UFG::SimObject *v25; // rbx
  UFG::StimulusManager *v26; // rdi
  __int128 v27; // xmm1
  UFG::PhysicsMoverInterface *v28; // rcx
  __m128 v29; // xmm2
  float v30; // xmm9_4
  UFG::PhysicsVehicle *v31; // rcx
  __m128 v32; // xmm2
  float v33; // xmm10_4
  float v34; // xmm7_4
  float v35; // xmm3_4
  float v36; // xmm8_4
  float v37; // xmm6_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  UFG::SimObject *v40; // rax
  UFG::SimObject *v41; // r13
  UFG::SimObject *v42; // rbx
  UFG::StimulusManager *v43; // rdi
  UFG::StimulusEmitterComponent *v44; // rax
  UFG::PhysicsMoverInterface *v45; // rax
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // xmm5_4
  float v49; // xmm1_4
  UFG::PhysicsMoverInterface *v50; // rbx
  float v51; // xmm4_4
  float v52; // xmm0_4
  hkLocalFrameGroup *v53; // rbx
  UFG::PhysicsMoverInterface *v54; // rcx
  UFG::PhysicsMoverInterface *v55; // rdx
  UFG::SimObjectCVBase *v56; // rcx
  unsigned __int16 v57; // dx
  UFG::CarHumanDriverComponent *v58; // rax
  UFG::OSuiteLeaderboardManager *v59; // rax
  UFG::OSuiteLeaderboardData *v60; // rax
  UFG::SimObjectCVBase *v61; // rcx
  unsigned __int16 v62; // dx
  UFG::AiDriverComponent *v63; // rax
  UFG::SimObjectGame *v64; // rcx
  unsigned __int16 v65; // dx
  UFG::SimComponent *v66; // rax
  UFG::SimObjectVehicle *v67; // rcx
  unsigned __int16 v68; // dx
  UFG::BikePhysicsMoverComponent *v69; // rax
  UFG::PhysicsMotorBike *v70; // rax
  UFG::SimObject *v71; // rbx
  UFG::StimulusManager *v72; // rdi
  UFG::SimObject *v73; // rbx
  UFG::StimulusManager *v74; // rdi
  UFG::SimObject *v75; // r13
  UFG::SimObject *v76; // rbx
  UFG::StimulusManager *v77; // rdi
  UFG::StimulusEmitterComponent *v78; // rax
  UFG::SimObjectGame *v79; // rcx
  unsigned __int16 v80; // dx
  UFG::VehicleEffectsComponent *v81; // rax
  UFG::PhysicsObjectProperties *v82; // rax
  float v83; // xmm1_4
  float v84; // xmm2_4
  UFG::PhysicsMoverInterface *v85; // rbx
  float v86; // xmm0_4
  UFG::PhysicsMoverInterface *v87; // rax
  UFG::SimObjectCVBase *v88; // rcx
  unsigned __int16 v89; // dx
  UFG::AiDriverComponent *v90; // rax
  UFG::SimComponent *i; // rbx
  UFG::StateMachineComponent *v92; // rcx
  UFG::SimObjectCVBase *v93; // rcx
  unsigned __int16 v94; // dx
  UFG::CarHumanDriverComponent *v95; // rax
  UFG::CharacterPhysicsComponent *v96; // rcx
  UFG::PhysicsObjectProperties *v97; // rax
  UFG::SimObjectGame *v98; // rcx
  unsigned __int16 v99; // dx
  UFG::SimComponent *v100; // rax
  float v101; // xmm6_4
  UFG::PhysicsMoverInterface *v102; // rax
  __int64 v103; // rdx
  unsigned __int64 v104; // rcx
  UFG::qReflectObject *v105; // rax
  unsigned __int64 v106; // rax
  float v107; // xmm3_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v108; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v109; // rdx
  __int64 v110; // rcx
  float v111; // xmm1_4
  float v112; // xmm2_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  float v115; // xmm1_4
  float v116; // xmm2_4
  UFG::qReflectHandleBase v117; // [rsp+30h] [rbp-98h]
  __int64 v118; // [rsp+58h] [rbp-70h]
  __int64 v119; // [rsp+60h] [rbp-68h]
  UFG::HitRecord hitrecord; // [rsp+70h] [rbp-58h]
  int v121; // [rsp+250h] [rbp+188h]
  hkSimpleLocalFrame *v122; // [rsp+258h] [rbp+190h]
  UFG::SimObject *v123; // [rsp+260h] [rbp+198h]

  v119 = -2i64;
  v2 = thisEvent;
  v3 = this;
  if ( thisEvent->mType == SLIDING )
    UFG::AiCollisionEventHandler::ProcessSlidingEvent(this, thisEvent);
  if ( v2->mType == UNSUPPORTED )
  {
    v4 = &v2->mSimObject[0].m_pPointer;
    if ( v2->mSimObject[1].m_pPointer != v2->mSimObject[0].m_pPointer )
    {
      v5 = v3->simObject;
      v6 = 2i64;
      do
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v117);
        v8 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
        v117.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(
          &v117,
          v117.mTypeUID,
          *(unsigned __int64 *)((char *)v5 + (char *)v2 - (char *)v3 + 176));
        *(v5 - 2) = (UFG::SimObject *)v117.mData;
        *v5 = *v4;
        UFG::qReflectHandleBase::~qReflectHandleBase(&v117);
        ++v5;
        v4 += 3;
        --v6;
      }
      while ( v6 );
      UFG::AiCollisionEventHandler::Initialize(v3);
      v9 = LODWORD(v2->speed) & _xmm;
      v10 = UFG::GetCurrentGameCamera();
      v11 = (__int64)v10;
      v118 = (__int64)v10;
      if ( v10 )
        v10 = (UFG::GameCameraComponent *)((__int64 (__fastcall *)(UFG::GameCameraComponent *))v10->vfptr[17].__vecDelDtor)(v10);
      v123 = (UFG::SimObject *)v10;
      v12 = 0;
      v121 = 0;
      v13 = 0i64;
      do
      {
        v14 = v12 == 0;
        v15 = (UFG::SimObjectGame *)v3->simObject[v13];
        if ( v15 )
        {
          v16 = v15->m_Flags;
          if ( (v16 >> 14) & 1 )
          {
            UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::VehicleOccupantComponent::_TypeUID);
          }
          else if ( (v16 & 0x8000u) == 0 )
          {
            if ( (v16 >> 13) & 1 )
            {
              UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::VehicleOccupantComponent::_TypeUID);
            }
            else if ( (v16 >> 12) & 1 )
            {
              UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::VehicleOccupantComponent::_TypeUID);
            }
            else
            {
              UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
            }
          }
        }
        v17 = v14;
        v18 = (UFG::SimObjectGame *)v3->simObject[v14];
        if ( v18 )
        {
          v20 = v18->m_Flags;
          if ( (v20 >> 14) & 1 )
          {
            v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::VehicleOccupantComponent::_TypeUID);
LABEL_30:
            v19 = (hkSimpleLocalFrame *)v21;
            goto LABEL_31;
          }
          if ( (v20 & 0x8000u) == 0 )
          {
            if ( (v20 >> 13) & 1 )
            {
              v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::VehicleOccupantComponent::_TypeUID);
            }
            else if ( (v20 >> 12) & 1 )
            {
              v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::VehicleOccupantComponent::_TypeUID);
            }
            else
            {
              v21 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v18->vfptr,
                      UFG::VehicleOccupantComponent::_TypeUID);
            }
            goto LABEL_30;
          }
          v19 = (hkSimpleLocalFrame *)v18->m_Components.p[30].m_pComponent;
        }
        else
        {
          v19 = 0i64;
        }
LABEL_31:
        v122 = v19;
        if ( v3->vehicle[v13] )
        {
          v22 = (UFG::SimObjectGame *)v3->simObject[v14];
          if ( v22 )
          {
            v23 = v22->m_Flags;
            if ( (v23 >> 14) & 1 )
            {
              v24 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::RigidBodyComponent::_TypeUID);
            }
            else if ( (v23 & 0x8000u) == 0 )
            {
              if ( (v23 >> 13) & 1 )
                v24 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::RigidBodyComponent::_TypeUID);
              else
                v24 = (UFG::RigidBody *)((v23 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v22,
                                                             UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                    (UFG::SimObject *)&v22->vfptr,
                                                                                                    UFG::RigidBodyComponent::_TypeUID));
            }
            else
            {
              v24 = (UFG::RigidBody *)UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::RigidBodyComponent::_TypeUID);
            }
            if ( v24 && (unsigned int)UFG::RigidBody::GetCollisionLayer(v24) == 9 )
            {
              v117.mPrev = *(UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> **)&UFG::qVector3::msZero.x;
              v117.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)LODWORD(UFG::qVector3::msZero.z);
              v117.mTypeUID = -4647714812233515008i64;
              v25 = v3->simObject[v13];
              v26 = UFG::StimulusManager::s_pInstance;
              UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
                UFG::StimulusManager::s_pInstance,
                eSTIMULUS_CAR_HIT_BUILDING,
                v3->simObject[v13]);
              UFG::StimulusManager::AttachStimulusEmitterComponent(
                v26,
                &stimulus_description,
                (UFG::StimulusParameters *)&v117,
                v25,
                0);
              v11 = v118;
            }
          }
        }
        if ( v123 && v123 == v3->simObject[v13] )
        {
          v27 = LODWORD(v2->estimatedImpulseMagnitude);
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v11 + 264i64))(v11);
        }
        v28 = v3->vehicle[v13];
        if ( v28 )
        {
          v29 = (__m128)LODWORD(v2->velocity[v13].x);
          v29.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0])
                                  + (float)(v2->velocity[v13].y * v2->velocity[v13].y))
                          + (float)(v2->velocity[v13].z * v2->velocity[v13].z);
          v30 = COERCE_FLOAT(_mm_sqrt_ps(v29)) * 3.5999999;
          v31 = v28->mPhysicsVehicle;
          if ( v31 && (*((_DWORD *)v31 + 151) & 7) == 4 )
            UFG::PhysicsCar::ProcessCollisonEvent((UFG::PhysicsCar *)v31, v2);
          if ( v3->vehicle[v17] )
          {
            v32 = (__m128)LODWORD(v2->velocity[v17].x);
            v32.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0])
                                    + (float)(v2->velocity[v17].y * v2->velocity[v17].y))
                            + (float)(v2->velocity[v17].z * v2->velocity[v17].z);
            v33 = COERCE_FLOAT(_mm_sqrt_ps(v32)) * 3.5999999;
            v34 = v2->velocity[v13].x;
            v35 = v2->velocity[v13].y;
            v36 = v2->velocity[v13].z;
            if ( (float)((float)((float)(v35 * v35) + (float)(v34 * v34)) + (float)(v36 * v36)) > 0.001 )
            {
              v37 = v2->preCollisionPosition[v17].z - v2->preCollisionPosition[v13].z;
              v38 = v2->preCollisionPosition[v17].y - v2->preCollisionPosition[v13].y;
              v39 = v2->preCollisionPosition[v17].x - v2->preCollisionPosition[v13].x;
              if ( (float)((float)((float)(v38 * v38) + (float)(v39 * v39)) + (float)(v37 * v37)) > 0.001
                && ((float)((float)((float)(v35 * v38) + (float)(v34 * v39)) + (float)(v36 * v37)) >= 0.866
                 || *((_BYTE *)v3->vehicle[v13] + 900) & 1) )
              {
                v40 = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v19);
                v41 = v40;
                if ( v40 )
                {
                  v117.mPrev = *(UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> **)&UFG::qVector3::msZero.x;
                  v117.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)LODWORD(UFG::qVector3::msZero.z);
                  v117.mTypeUID = -4647714812233515008i64;
                  v42 = v3->simObject[v13];
                  v43 = UFG::StimulusManager::s_pInstance;
                  UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
                    UFG::StimulusManager::s_pInstance,
                    eSTIMULUS_CAR_HIT_MY_CAR,
                    v3->simObject[v13],
                    v40);
                  v44 = (UFG::StimulusEmitterComponent *)UFG::StimulusManager::AttachStimulusEmitterComponent(
                                                           v43,
                                                           &stru_1423C0C78,
                                                           (UFG::StimulusParameters *)&v117,
                                                           v42,
                                                           0);
                  if ( v44 )
                    UFG::StimulusEmitterComponent::SetIsTargeted(v44, v41);
                }
                v45 = v3->vehicle[v13];
                if ( *((_BYTE *)v45 + 900) & 8 )
                {
                  v46 = v45->mVehicleCollisionMinRamImpulseRequiredToDealDamage;
                  v47 = v45->mVehicleCollisionMaxRamImpulseForDealingDamage;
                  v48 = v45->mVehicleCollisionDamageDealtAtMinRamImpulse;
                  v49 = v45->mVehicleCollisionDamageDealtAtMaxRamImpulse;
                }
                else
                {
                  v46 = v45->mVehicleCollisionMinImpulseRequiredToDealDamage;
                  v47 = v45->mVehicleCollisionMaxImpulseForDealingDamage;
                  v48 = v45->mVehicleCollisionDamageDealtAtMinImpulse;
                  v49 = v45->mVehicleCollisionDamageDealtAtMaxImpulse;
                }
                v50 = v3->vehicle[v17];
                if ( v50->mPostRamImmunityTimer > 0.0 )
                  v46 = v45->mVehicleCollisionMaxImpulseForDealingDamage * 0.89999998;
                v51 = v2->estimatedImpulseMagnitude;
                if ( v51 >= v50->mVehicleCollisionMinImpulseRequiredToTakeDamage && v51 >= v46 )
                {
                  v52 = UFG::AiCollisionEventHandler::ComputeDamageFromImpulseMagnitude(
                          v48,
                          v49,
                          v46,
                          v47,
                          v2->estimatedImpulseMagnitude);
                  if ( (unsigned __int8)UFG::PhysicsMoverInterface::DamageEngine(
                                          v50,
                                          v3->simObject[v13],
                                          v52,
                                          dtVEHICLE_COLLISION) )
                  {
                    if ( v3->vehicle[v17]->mSecondsEngineHasBeenDeteriorating >= 0.5
                      && v2->estimatedImpulseMagnitude >= 5.0 )
                    {
                      v53 = (hkLocalFrameGroup *)LocalPlayer;
                      if ( Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v122) != v53 )
                        *((_BYTE *)v3->vehicle[v17] + 900) |= 0x10u;
                    }
                    v54 = v3->vehicle[v13];
                    if ( *((_BYTE *)v54 + 900) & 8 )
                    {
                      v55 = v3->vehicle[v17];
                      if ( (unsigned int)(v55->mDestructState - 1) > 1 )
                      {
                        UFG::AiCollisionEventHandler::InjectRamCollisionVelocities(v54, v55);
                        v3->vehicle[v17]->mPostRamImmunityTimer = 2.5;
                        v56 = (UFG::SimObjectCVBase *)v3->simObject[v13];
                        if ( v56 )
                        {
                          v57 = v56->m_Flags;
                          if ( (v57 >> 14) & 1 )
                          {
                            v58 = UFG::SimObjectCVBase::GetComponent<UFG::CarHumanDriverComponent>(v56);
                          }
                          else if ( (v57 & 0x8000u) == 0 )
                          {
                            if ( (v57 >> 13) & 1 )
                              v58 = (UFG::CarHumanDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      (UFG::SimObjectGame *)&v56->vfptr,
                                                                      UFG::CarHumanDriverComponent::_TypeUID);
                            else
                              v58 = (UFG::CarHumanDriverComponent *)((v57 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                         (UFG::SimObjectGame *)&v56->vfptr,
                                                                                         UFG::CarHumanDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v56->vfptr, UFG::CarHumanDriverComponent::_TypeUID));
                          }
                          else
                          {
                            v58 = UFG::SimObjectCVBase::GetComponent<UFG::CarHumanDriverComponent>(v56);
                          }
                          if ( v58 )
                          {
                            v59 = UFG::OSuiteLeaderboardManager::Instance();
                            v60 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                    v59,
                                    "StatGamesVehicleTakedownStreak");
                            UFG::StatGameManager::UpdateScore(v60, 1, 1);
                          }
                        }
                      }
                    }
                  }
                  v61 = (UFG::SimObjectCVBase *)v3->simObject[v17];
                  if ( v61 )
                  {
                    v62 = v61->m_Flags;
                    if ( (v62 >> 14) & 1 )
                    {
                      v63 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v61);
                    }
                    else if ( (v62 & 0x8000u) == 0 )
                    {
                      if ( (v62 >> 13) & 1 )
                        v63 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v61->vfptr,
                                                          UFG::AiDriverComponent::_TypeUID);
                      else
                        v63 = (UFG::AiDriverComponent *)((v62 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v61->vfptr,
                                                                             UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v61->vfptr, UFG::AiDriverComponent::_TypeUID));
                    }
                    else
                    {
                      v63 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v61);
                    }
                    if ( v63 )
                      UFG::AiDriverComponent::HandleCollision(v63, v3->simObject[v13], v52, dtVEHICLE_COLLISION);
                  }
                }
              }
            }
            v64 = (UFG::SimObjectGame *)v3->simObject[v17];
            if ( !v64
              || ((v65 = v64->m_Flags, !((v65 >> 14) & 1)) ? ((v65 & 0x8000u) == 0 ? (!((v65 >> 13) & 1) ? (!((v65 >> 12) & 1) ? (v66 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v64->vfptr, UFG::VehicleDriverInterface::_TypeUID)) : (v66 = UFG::SimObjectGame::GetComponentOfTypeHK(v64, UFG::VehicleDriverInterface::_TypeUID))) : (v66 = UFG::SimObjectGame::GetComponentOfTypeHK(v64, UFG::VehicleDriverInterface::_TypeUID))) : (v66 = v64->m_Components.p[23].m_pComponent)) : (v66 = v64->m_Components.p[23].m_pComponent),
                  !v66) )
            {
              v67 = (UFG::SimObjectVehicle *)v3->simObject[v17];
              if ( v67 )
              {
                v68 = v67->m_Flags;
                if ( !((v68 >> 14) & 1) )
                {
                  if ( (v68 & 0x8000u) == 0 )
                  {
                    if ( (v68 >> 13) & 1 )
                      v69 = (UFG::BikePhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                (UFG::SimObjectGame *)&v67->vfptr,
                                                                UFG::BikePhysicsMoverComponent::_TypeUID);
                    else
                      v69 = (UFG::BikePhysicsMoverComponent *)((v68 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                   (UFG::SimObjectGame *)&v67->vfptr,
                                                                                   UFG::BikePhysicsMoverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v67->vfptr, UFG::BikePhysicsMoverComponent::_TypeUID));
                  }
                  else
                  {
                    v69 = UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(v67);
                  }
                  if ( v69 )
                  {
                    v70 = UFG::BikePhysicsMoverComponent::GetPhysicsBike(v69);
                    if ( v70 )
                      v70->mDisableConstraint = 1;
                  }
                }
              }
            }
            if ( v30 > 10.0 && v30 > v33 )
            {
              v117.mPrev = *(UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> **)&UFG::qVector3::msZero.x;
              v117.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)LODWORD(UFG::qVector3::msZero.z);
              v117.mTypeUID = -4647714812233515008i64;
              v71 = v3->simObject[v13];
              v72 = UFG::StimulusManager::s_pInstance;
              UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
                UFG::StimulusManager::s_pInstance,
                eSTIMULUS_CAR_HIT_CAR,
                v3->simObject[v13]);
              UFG::StimulusManager::AttachStimulusEmitterComponent(
                v72,
                &stru_1423C0BE8,
                (UFG::StimulusParameters *)&v117,
                v71,
                0);
            }
          }
          else if ( v3->characterPhysics[v17] )
          {
            if ( gMinVehicleHitPedStimulusVelocity < v2->estimatedImpulseMagnitude && v30 > 2.0 )
            {
              v117.mPrev = *(UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> **)&UFG::qVector3::msZero.x;
              v117.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)LODWORD(UFG::qVector3::msZero.z);
              v117.mTypeUID = -4647714812233515008i64;
              v73 = v3->simObject[v13];
              v74 = UFG::StimulusManager::s_pInstance;
              UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
                UFG::StimulusManager::s_pInstance,
                eSTIMULUS_VEHICLE_HIT_PED,
                v3->simObject[v13]);
              UFG::StimulusManager::AttachStimulusEmitterComponent(
                v74,
                &stru_1423C0690,
                (UFG::StimulusParameters *)&v117,
                v73,
                0);
              HIDWORD(v117.mNext) = 0;
              v75 = v3->simObject[v17];
              v76 = v3->simObject[v13];
              v77 = UFG::StimulusManager::s_pInstance;
              UFG::StimulusManager::DeleteAllStimulusEmittersOfType(
                UFG::StimulusManager::s_pInstance,
                eSTIMULUS_VEHICLE_HIT_YOU,
                v3->simObject[v13],
                v3->simObject[v17]);
              v78 = (UFG::StimulusEmitterComponent *)UFG::StimulusManager::AttachStimulusEmitterComponent(
                                                       v77,
                                                       &stru_1423C06D8,
                                                       (UFG::StimulusParameters *)&v117,
                                                       v76,
                                                       0);
              if ( v75 )
              {
                if ( v78 )
                  UFG::StimulusEmitterComponent::SetIsTargeted(v78, v75);
              }
            }
          }
          v79 = (UFG::SimObjectGame *)v3->simObject[v13];
          if ( v79 )
          {
            v80 = v79->m_Flags;
            if ( (v80 >> 14) & 1 )
            {
              v81 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v79,
                                                      UFG::VehicleEffectsComponent::_TypeUID);
            }
            else if ( (v80 & 0x8000u) == 0 )
            {
              if ( (v80 >> 13) & 1 )
                v81 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v79,
                                                        UFG::VehicleEffectsComponent::_TypeUID);
              else
                v81 = (UFG::VehicleEffectsComponent *)((v80 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           v79,
                                                                           UFG::VehicleEffectsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v79->vfptr, UFG::VehicleEffectsComponent::_TypeUID));
            }
            else
            {
              v81 = (UFG::VehicleEffectsComponent *)v79->m_Components.p[32].m_pComponent;
            }
            if ( v81 )
              UFG::VehicleEffectsComponent::PlayCollisionFX(v81, (UFG::Event *)&v2->vfptr, v30);
          }
          v82 = v3->physicsObjectProperties[v17];
          if ( v82 )
          {
            if ( v82->mMotionType == 1 )
            {
              v83 = v2->estimatedImpulseMagnitude;
              v84 = FLOAT_5_0;
              if ( v83 >= 5.0 )
              {
                v85 = v3->vehicle[v13];
                if ( v85->mPostRamImmunityTimer > 0.0 )
                  v84 = FLOAT_9_0;
                v86 = UFG::AiCollisionEventHandler::ComputeDamageFromImpulseMagnitude(
                        0.0049999999,
                        0.050000001,
                        v84,
                        10.0,
                        v83);
                if ( v85 )
                {
                  if ( (unsigned __int8)UFG::PhysicsMoverInterface::DamageEngine(v85, 0i64, v86, 0) )
                  {
                    v87 = v3->vehicle[v13];
                    if ( v87->mSecondsEngineHasBeenDeteriorating >= 0.5 && v2->estimatedImpulseMagnitude >= 5.0 )
                      *((_BYTE *)v87 + 900) |= 0x10u;
                  }
                }
                v88 = (UFG::SimObjectCVBase *)v3->simObject[v13];
                if ( v88 )
                {
                  v89 = v88->m_Flags;
                  if ( (v89 >> 14) & 1 )
                  {
                    v90 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v88);
                  }
                  else if ( (v89 & 0x8000u) == 0 )
                  {
                    if ( (v89 >> 13) & 1 )
                      v90 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v88->vfptr,
                                                        UFG::AiDriverComponent::_TypeUID);
                    else
                      v90 = (UFG::AiDriverComponent *)((v89 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v88->vfptr,
                                                                           UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v88->vfptr, UFG::AiDriverComponent::_TypeUID));
                  }
                  else
                  {
                    v90 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v88);
                  }
                  if ( v90 )
                    UFG::AiDriverComponent::HandleCollision(v90, 0i64, v86, 0);
                }
              }
            }
          }
        }
        for ( i = (UFG::SimComponent *)&v3->rigidBody[v13]->vfptr;
              i;
              i = (UFG::SimComponent *)UFG::SimObject::GetComponentOfType(
                                         i->m_pSimObject,
                                         UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                         0,
                                         i) )
        {
          v92 = (UFG::StateMachineComponent *)i[6].vfptr;
          if ( v92 )
            UFG::StateMachineComponent::ApplyDamage(v92, v2->estimatedImpulseMagnitude, 0, v3->simObject[v17]);
        }
        v93 = (UFG::SimObjectCVBase *)v3->simObject[v13];
        if ( v93 )
        {
          v94 = v93->m_Flags;
          if ( (v94 >> 14) & 1 )
          {
            v95 = UFG::SimObjectCVBase::GetComponent<UFG::CarHumanDriverComponent>(v93);
          }
          else if ( (v94 & 0x8000u) == 0 )
          {
            if ( (v94 >> 13) & 1 )
              v95 = (UFG::CarHumanDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v93->vfptr,
                                                      UFG::CarHumanDriverComponent::_TypeUID);
            else
              v95 = (UFG::CarHumanDriverComponent *)((v94 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v93->vfptr,
                                                                         UFG::CarHumanDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v93->vfptr, UFG::CarHumanDriverComponent::_TypeUID));
          }
          else
          {
            v95 = UFG::SimObjectCVBase::GetComponent<UFG::CarHumanDriverComponent>(v93);
          }
          if ( v95 )
            UFG::CarHumanDriverComponent::StopCollisionFreeDrive(v95);
        }
        if ( v3->hitComp[v13] )
        {
          v96 = v3->characterPhysics[v13];
          if ( !v96
            || ((v97 = v3->physicsObjectProperties[v17]) == 0i64
             || v97->mMotionType != 1 && !v97->mNoHitReactionsOnWorldCollisions)
            && ((v98 = (UFG::SimObjectGame *)v96->m_pSimObject) == 0i64
             || ((v99 = v98->m_Flags, !((v99 >> 14) & 1)) ? ((v99 & 0x8000u) == 0 ? (!((v99 >> 13) & 1) ? (!((v99 >> 12) & 1) ? (v100 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v98->vfptr, UFG::HealthComponent::_TypeUID)) : (v100 = UFG::SimObjectGame::GetComponentOfTypeHK(v98, UFG::HealthComponent::_TypeUID))) : (v100 = UFG::SimObjectGame::GetComponentOfTypeHK(v98, UFG::HealthComponent::_TypeUID))) : (v100 = v98->m_Components.p[6].m_pComponent)) : (v100 = v98->m_Components.p[6].m_pComponent),
                 !v100 || !BYTE5(v100[1].m_BoundComponentHandles.mNode.mPrev))) )
          {
            if ( !v3->characterPhysics[v17] )
            {
              v101 = 0.0;
              v102 = v3->vehicle[v13];
              if ( v102 )
                v101 = v102->mForwardSpeed;
              UFG::HitRecord::HitRecord(&hitrecord);
              v103 = (__int64)v3->simObject[v17];
              hitrecord.mAttackTypeID = gAttackTypeWorldCollision.m_EnumValue;
              hitrecord.mDamage = 100;
              if ( v118 )
              {
                v104 = v117.mNameUID;
                v105 = v117.mData;
                *(_QWORD *)(v117.mNameUID + 8) = v117.mData;
                v105->vfptr = (UFG::qReflectObjectVtbl *)v104;
                v117.mNameUID = (unsigned __int64)&v117.mNameUID;
                v117.mData = (UFG::qReflectObject *)&v117.mNameUID;
              }
              v118 = v103;
              if ( v103 )
              {
                v106 = *(_QWORD *)(v103 + 8);
                *(_QWORD *)(v106 + 8) = (char *)&v117 + 24;
                v117.mNameUID = v106;
                v117.mData = (UFG::qReflectObject *)(v103 + 8);
                *(_QWORD *)(v103 + 8) = (char *)&v117 + 24;
              }
              v119 = 0i64;
              v107 = v2->estimatedImpulseMagnitude;
              v108 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v2->surfacePropertyHandleUID[v17];
              v109 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v2->surfacePropertyHandleUID[v13];
              v110 = v2->objectPropertyHandleUID[v17];
              *(_QWORD *)&hitrecord.mMeleeInfo.mActionPath.mPath.mCount = v2->objectPropertyHandleUID[v13];
              hitrecord.mMeleeInfo.mActionPath.mPath.mData.mOffset = v110;
              hitrecord.mProjectileInfo.m_pSOWPC.mPrev = v109;
              hitrecord.mProjectileInfo.m_pSOWPC.mNext = v108;
              v111 = v2->position.y;
              v112 = v2->position.z;
              *(float *)&hitrecord.mProjectileInfo.m_pSOWPC.m_pPointer = v2->position.x;
              *((float *)&hitrecord.mProjectileInfo.m_pSOWPC.m_pPointer + 1) = v111;
              *(float *)&hitrecord.mProjectileInfo.m_pSubTargetingLocation = v112;
              v113 = v2->normal.y;
              v114 = v2->normal.z;
              HIDWORD(hitrecord.mProjectileInfo.m_pSubTargetingLocation) = LODWORD(v2->normal.x);
              *(float *)&hitrecord.mProjectileInfo.m_bIsFullyAccurate = v113;
              *(float *)(&hitrecord.mProjectileInfo.m_bIsHardLocked + 3) = v114;
              v115 = v2->velocity[v17].y;
              v116 = v2->velocity[v17].z;
              *(float *)&hitrecord.mCollisionInfo.mPhysicsObjectPropertyHandleUID = v2->velocity[v17].x;
              *((float *)&hitrecord.mCollisionInfo.mPhysicsObjectPropertyHandleUID + 1) = v115;
              hitrecord.mCollisionInfo.mAttackerPhysicsObjectPropertyHandleUID = __PAIR__(v9, LODWORD(v116));
              hitrecord.mCollisionInfo.mSurfacePropertyHandleUID = __PAIR__(LODWORD(v107), LODWORD(v101));
              UFG::HitReactionComponent::HandleHitReaction(v3->hitComp[v13], &hitrecord);
              UFG::HitRecord::~HitRecord(&hitrecord);
            }
          }
        }
        v12 = v121 + 1;
        v121 = v12;
        ++v13;
        v11 = v118;
      }
      while ( v12 < 2 );
    }
  }
}

// File Line: 579
// RVA: 0x368C40
void __fastcall UFG::AiCollisionEventHandler::Initialize(UFG::AiCollisionEventHandler *this)
{
  UFG::SimObject **v1; // rbx
  signed __int64 v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *v6; // r8
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // cx
  UFG::SimObjectProp *v9; // rcx
  UFG::SimObjectWeaponPropertiesComponent *v10; // rax
  unsigned __int16 v11; // dx
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *v13; // rax
  unsigned __int16 v14; // dx
  UFG::SimObjectGame *v15; // rcx
  UFG::SimComponent *v16; // rax
  unsigned __int16 v17; // dx
  UFG::SimObjectGame *v18; // rcx
  unsigned __int16 v19; // dx

  v1 = this->simObject;
  v2 = 2i64;
  do
  {
    v3 = (UFG::SimObjectGame *)*v1;
    if ( *v1 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = v3->m_Components.p[15].m_pComponent;
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
        }
      }
      else
      {
        v5 = v3->m_Components.p[15].m_pComponent;
      }
      v6 = (UFG::SimObjectGame *)*v1;
      v1[2] = (UFG::SimObject *)v5;
      if ( v6 )
      {
        v8 = v6->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v7 = 0i64;
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v7 = 0i64;
          }
          else if ( (v8 >> 12) & 1 )
          {
            v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::PhysicsMoverInterface::_TypeUID);
          }
          else
          {
            v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
          }
        }
        else
        {
          v7 = v6->m_Components.p[34].m_pComponent;
        }
      }
      else
      {
        v7 = 0i64;
      }
      v9 = (UFG::SimObjectProp *)*v1;
      v1[4] = (UFG::SimObject *)v7;
      if ( v9 )
      {
        v11 = v9->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v10 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v9->vfptr,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
          {
            v10 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v9);
          }
          else if ( (v11 >> 12) & 1 )
          {
            v10 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v9->vfptr,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          }
          else
          {
            v10 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v9->vfptr,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          }
        }
        else
        {
          v10 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v9->vfptr,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
      }
      else
      {
        v10 = 0i64;
      }
      v12 = (UFG::SimObjectGame *)*v1;
      v1[6] = (UFG::SimObject *)v10;
      if ( v12 )
      {
        v14 = v12->m_Flags;
        if ( (v14 >> 14) & 1 )
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v14 & 0x8000u) == 0 )
        {
          if ( (v14 >> 13) & 1 )
          {
            v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RigidBodyComponent::_TypeUID);
          }
          else if ( (v14 >> 12) & 1 )
          {
            v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RigidBodyComponent::_TypeUID);
          }
          else
          {
            v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::RigidBodyComponent::_TypeUID);
          }
        }
        else
        {
          v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RigidBodyComponent::_TypeUID);
        }
      }
      else
      {
        v13 = 0i64;
      }
      v15 = (UFG::SimObjectGame *)*v1;
      v1[8] = (UFG::SimObject *)v13;
      if ( v15 )
      {
        v17 = v15->m_Flags;
        if ( (v17 >> 14) & 1 )
        {
          v16 = v15->m_Components.p[27].m_pComponent;
        }
        else if ( (v17 & 0x8000u) == 0 )
        {
          if ( (v17 >> 13) & 1 )
          {
            v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else if ( (v17 >> 12) & 1 )
          {
            v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else
          {
            v16 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v15->vfptr,
                    UFG::CharacterPhysicsComponent::_TypeUID);
          }
        }
        else
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v16 = 0i64;
      }
      v18 = (UFG::SimObjectGame *)*v1;
      v1[10] = (UFG::SimObject *)v16;
      if ( v18 )
      {
        v19 = v18->m_Flags;
        if ( (v19 >> 14) & 1 )
        {
          v1[12] = (UFG::SimObject *)v18->m_Components.p[42].m_pComponent;
        }
        else if ( (v19 & 0x8000u) == 0 )
        {
          if ( (v19 >> 13) & 1 )
          {
            v1[12] = (UFG::SimObject *)UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::RagdollComponent::_TypeUID);
          }
          else if ( (v19 >> 12) & 1 )
          {
            v1[12] = (UFG::SimObject *)UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::RagdollComponent::_TypeUID);
          }
          else
          {
            v1[12] = (UFG::SimObject *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v18->vfptr,
                                         UFG::RagdollComponent::_TypeUID);
          }
        }
        else
        {
          v1[12] = (UFG::SimObject *)UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::RagdollComponent::_TypeUID);
        }
      }
      else
      {
        v1[12] = 0i64;
      }
    }
    else
    {
      v1[2] = 0i64;
      v1[4] = 0i64;
      v1[6] = 0i64;
      v1[8] = 0i64;
      v1[10] = 0i64;
      v1[12] = 0i64;
    }
    ++v1;
    --v2;
  }
  while ( v2 );
}

// File Line: 608
// RVA: 0x34F900
float __fastcall UFG::AiCollisionEventHandler::ComputeDamageFromImpulseMagnitude(float fMinDamage, float fMaxDamage, float fMinImpulse, float fMaxImpulse, float fEstimatedImpulseMagnitude)
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
void __fastcall UFG::AiCollisionEventHandler::InjectRamCollisionVelocities(UFG::PhysicsMoverInterface *pRammerPMI, UFG::PhysicsMoverInterface *pVictimPMI)
{
  UFG::PhysicsMoverInterface *v2; // rdi
  unsigned int *v3; // rsi
  hkpEntity *v4; // rbx
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
  __m128 v19; // [rsp+20h] [rbp-28h]

  if ( pRammerPMI )
  {
    v2 = pVictimPMI;
    v3 = (unsigned int *)pRammerPMI;
    if ( pVictimPMI )
    {
      v4 = (hkpEntity *)UFG::PhysicsMoverInterface::GetRigidBody(pRammerPMI);
      v5 = (hkpEntity *)UFG::PhysicsMoverInterface::GetRigidBody(v2);
      v6 = v5;
      if ( v4 )
      {
        if ( v5 )
        {
          v7 = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)v3[221], (__m128)v3[223]),
                 _mm_unpacklo_ps((__m128)v3[222], (__m128)0i64));
          v8 = _mm_mul_ps(v7, v7);
          v9 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                 _mm_shuffle_ps(v8, v8, 170));
          v10 = _mm_rsqrt_ps(v9);
          v11 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v9), (__m128)0i64);
          v12 = _mm_and_ps(
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmpleps(v9, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                        _mm_mul_ps(*(__m128 *)_xmm, v10))),
                    v7),
                  v11);
          v13 = _mm_andnot_ps(v11, v7);
          v14 = FLOAT_8_0;
          v15 = _mm_or_ps(v12, v13);
          v16 = _mm_mul_ps(v5->m_motion.m_linearVelocity.m_quad, v15);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v16, v16, 170))) < 8.0 )
          {
            v19 = _mm_add_ps(_mm_mul_ps((__m128)_xmm, v15), v5->m_motion.m_linearVelocity.m_quad);
            hkpEntity::activate(v5);
            v6->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v6->m_motion.vfptr, (unsigned int)&v19);
            v14 = FLOAT_8_0;
          }
          v17 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v15);
          v18 = _mm_mul_ps(v4->m_motion.m_linearVelocity.m_quad, v17);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170))) < v14 )
          {
            v19 = _mm_add_ps(_mm_mul_ps((__m128)_xmm, v17), v4->m_motion.m_linearVelocity.m_quad);
            hkpEntity::activate(v4);
            v4->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v4->m_motion.vfptr, (unsigned int)&v19);
          }
        }
      }
    }
  }
}

