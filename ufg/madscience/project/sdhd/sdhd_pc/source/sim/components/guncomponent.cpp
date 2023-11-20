// File Line: 55
// RVA: 0x1543E80
__int64 dynamic_initializer_for__UFG::GunComponent::s_GunComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::GunComponent::s_GunComponentList__);
}

// File Line: 56
// RVA: 0x532460
const char *__fastcall UFG::GunComponent::GetTypeName(UFG::GunComponent *this)
{
  return "GunComponent";
}

// File Line: 72
// RVA: 0x5177C0
void __fastcall UFG::GunComponent::GunComponent(UFG::GunComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::GunComponent *v4; // rdi
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *v5; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // ST30_8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // ST30_8
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *v8; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax

  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::GunComponent,UFG::GunComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GunComponent::`vftable;
  *(_QWORD *)&v4->mNetShootSequence = 0i64;
  *(_QWORD *)&v4->mNetBulletPosition.y = 0i64;
  *(_QWORD *)&v4->mNetBulletVelocity.x = 0i64;
  v4->mNetBulletVelocity.z = 0.0;
  UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0>(&v4->mSimObjectWeaponPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0>::RebindingComponentHandle<UFG::InventoryItemComponent,0>(&v4->mInventoryItemComponent);
  v4->mMustHitTarget = 0;
  v4->mLastFiredTime = -1.0;
  v4->mRateOfFireOverride = -1.0;
  v4->mIfResetAmmoOnDeath = 1;
  v6 = &v4->mShootParams.pShootOriginSimObject;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v4->mShootParams.pShootOriginSimObject.m_pPointer = 0i64;
  v4->mShootParams.shootBoneId.mUID = -1;
  v7 = &v4->mShootParams.pWeaponOwnerSimObject;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v4->mShootParams.pWeaponOwnerSimObject.m_pPointer = 0i64;
  v8 = UFG::GunComponent::s_GunComponentList.mNode.mPrev;
  UFG::GunComponent::s_GunComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::GunComponent,UFG::GunComponent> *)&v4->mPrev;
  v5->mPrev = v8;
  v4->mNext = (UFG::qNode<UFG::GunComponent,UFG::GunComponent> *)&UFG::GunComponent::s_GunComponentList;
  UFG::GunComponent::s_GunComponentList.mNode.mPrev = (UFG::qNode<UFG::GunComponent,UFG::GunComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v4->vfptr, UFG::GunComponent::_GunComponentTypeUID, "GunComponent");
  *(_QWORD *)v4->mClipAmmo = 0i64;
  v9 = &v4->mShootParams.pWeaponOwnerSimObject;
  if ( v4->mShootParams.pWeaponOwnerSimObject.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v4->mShootParams.pWeaponOwnerSimObject.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v4->mShootParams.pWeaponOwnerSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mShootParams.pWeaponOwnerSimObject.mPrev;
  }
  v4->mShootParams.pWeaponOwnerSimObject.m_pPointer = 0i64;
  v12 = &v4->mShootParams.pShootOriginSimObject;
  if ( v4->mShootParams.pShootOriginSimObject.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v4->mShootParams.pShootOriginSimObject.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v4->mShootParams.pShootOriginSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mShootParams.pShootOriginSimObject.mPrev;
  }
  v4->mShootParams.pShootOriginSimObject.m_pPointer = 0i64;
  v4->mShootParams.shootBoneId = UFG::gNullQSymbolUC;
  v4->mShootParams.pAimingC = 0i64;
  v4->mShootParams.shootFlags = -1;
  v4->mShootParams.pSubTargetingLocation = 0i64;
}

// File Line: 105
// RVA: 0x5392B0
void __fastcall UFG::GunComponent::Initialize(UFG::GunComponent *this)
{
  UFG::SimComponent *v1; // rax
  UFG::GunComponent *v2; // rsi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rax
  unsigned int v4; // edi
  __int64 v5; // rbp
  __int64 v6; // rax
  int v7; // ebx
  int v8; // eax
  __int64 v9; // rcx

  v1 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  v2 = this;
  if ( v1 )
  {
    v3 = v1[2].m_BoundComponentHandles.mNode.mPrev;
    v4 = 0;
    if ( HIDWORD(v3->mPrev) )
    {
      v5 = 0i64;
      do
      {
        v6 = *(__int64 *)((char *)&v3->mNext + v5);
        v7 = *(_DWORD *)(v6 + 200);
        v8 = UFG::qRandom(*(_DWORD *)(v6 + 196) - v7, &UFG::qDefaultSeed);
        v9 = v4++;
        v5 += 8i64;
        v2->mClipAmmo[v9] = v7 + v8;
        v3 = v2->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
      }
      while ( v4 < HIDWORD(v3->mPrev) );
    }
  }
}

// File Line: 131
// RVA: 0x51B8D0
void __fastcall UFG::GunComponent::~GunComponent(UFG::GunComponent *this)
{
  UFG::GunComponent *v1; // rdi
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *v2; // rbx
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *v3; // rcx
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *v4; // rax
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *v5; // rcx
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GunComponent::`vftable;
  if ( this == UFG::GunComponent::s_GunComponentpCurrentIterator )
    UFG::GunComponent::s_GunComponentpCurrentIterator = (UFG::GunComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::GunComponent,UFG::GunComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::GunComponent::ShootParams::~ShootParams(&v1->mShootParams);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mInventoryItemComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mSimObjectWeaponPropertiesComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 135
// RVA: 0x154CCD0
__int64 UFG::_dynamic_initializer_for__symMuzzle__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Muzzle", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symMuzzle, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symMuzzle__);
}

// File Line: 138
// RVA: 0x561340
void __fastcall UFG::GunComponent::UpdateTransforms(UFG::GunComponent *this)
{
  UFG::GunComponent *v1; // rbx
  UFG::AimingBaseComponent *v2; // rdi
  UFG::SimObjectProp *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterAnimationComponent *v5; // rcx
  UFG::CharacterAnimationComponent *v6; // rax
  unsigned int v7; // er8
  unsigned int v8; // er10
  UFG::SimComponentHolder *v9; // rsi
  Creature *v10; // rsi
  unsigned int v11; // edx
  int v12; // eax
  float v13; // xmm7_4
  UFG::SimComponent *v14; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rax
  float projectileGravity; // xmm9_4
  float armingDistance; // xmm10_4
  float v18; // xmm0_4
  bool v19; // si
  UFG::SimComponent *v20; // rcx
  __int64 v21; // rax
  bool isHardLocked; // al
  unsigned int v23; // eax
  __int64 v24; // r14
  char posIsObscured; // si
  __int64 v26; // r8
  UFG::AimingPlayerComponent *v27; // rax
  float v28; // xmm3_4
  __m128 v29; // xmm4
  float v30; // xmm5_4
  __m128 v31; // xmm2
  float v32; // xmm1_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v37; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v38; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v40; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+70h] [rbp-90h]
  UFG::qVector3 vel; // [rsp+80h] [rbp-80h]
  UFG::qVector3 vTargetNormalAimPosition; // [rsp+90h] [rbp-70h]
  UFG::qVector3 muzzleDir; // [rsp+A0h] [rbp-60h]
  UFG::ProjectileInfo pi; // [rsp+B0h] [rbp-50h]
  UFG::qVector3 vPositionReturn; // [rsp+D8h] [rbp-28h]
  __int64 v49; // [rsp+E8h] [rbp-18h]
  UFG::qMatrix44 transform; // [rsp+F0h] [rbp-10h]

  v49 = -2i64;
  v1 = this;
  if ( this->mShootParams.shootFlags == -1 )
    return;
  v2 = this->mShootParams.pAimingC;
  v3 = (UFG::SimObjectProp *)this->mShootParams.pShootOriginSimObject.m_pPointer;
  if ( !v3 )
    goto LABEL_27;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (UFG::CharacterAnimationComponent *)v3->m_Components.p[9].m_pComponent;
    if ( !v5
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v5->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v5->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_7;
    }
    goto LABEL_25;
  }
  if ( (v4 & 0x8000u) != 0 )
  {
    v5 = (UFG::CharacterAnimationComponent *)v3->m_Components.p[9].m_pComponent;
    if ( !v5 || (UFG::CharacterAnimationComponent::_TypeUID ^ v5->m_TypeUID) & 0xFE000000 )
      goto LABEL_7;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v5->m_TypeUID & 0x1FFFFFF )
      v5 = 0i64;
    goto LABEL_25;
  }
  if ( (v4 >> 13) & 1 )
  {
    v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v3);
LABEL_24:
    v5 = v6;
    goto LABEL_25;
  }
  if ( !((v4 >> 12) & 1) )
  {
    v6 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_24;
  }
  v7 = v3->mComponentTableEntryCount;
  v8 = v3->m_Components.size;
  if ( v7 >= v8 )
  {
LABEL_7:
    v5 = 0i64;
    goto LABEL_25;
  }
  v9 = v3->m_Components.p;
  while ( (v9[v7].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~v9[v7].m_TypeUID & 0x1FFFFFF )
  {
    if ( ++v7 >= v8 )
      goto LABEL_7;
  }
  v5 = (UFG::CharacterAnimationComponent *)v9[v7].m_pComponent;
LABEL_25:
  if ( v5 )
  {
    v10 = v5->mCreature;
    goto LABEL_28;
  }
LABEL_27:
  v10 = 0i64;
LABEL_28:
  if ( v10 )
  {
    v11 = v1->mShootParams.shootBoneId.mUID;
    if ( v11 == -1 )
    {
      if ( v10->mPose.mRigHandle.mData )
      {
        v11 = UFG::symMuzzle.mUID;
LABEL_34:
        v12 = Skeleton::GetBoneID(v10->mPose.mRigHandle.mUFGSkeleton, v11);
        goto LABEL_36;
      }
    }
    else if ( v10->mPose.mRigHandle.mData )
    {
      goto LABEL_34;
    }
    v12 = -1;
LABEL_36:
    Creature::GetTransform(v10, v12, &transform);
    muzzleDir.x = transform.v0.x;
    muzzleDir.y = transform.v0.y;
    muzzleDir.z = transform.v0.z;
    vWeaponProjectileSpawnPosition = *(UFG::qVector3 *)&transform.v3.x;
    v13 = UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileSpeed(
            (UFG::SimObjectWeaponPropertiesComponent *)v1->mSimObjectWeaponPropertiesComponent.m_pSimComponent,
            v1->mShootParams.pWeaponOwnerSimObject.m_pPointer != (UFG::SimObject *)LocalPlayer);
    v14 = v1->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
    v15 = v14[2].m_BoundComponentHandles.mNode.mPrev;
    projectileGravity = *(float *)(*((_QWORD *)&v15->mNext + HIDWORD(v14[2].m_pSimObject)) + 60i64);
    armingDistance = *(float *)(*((_QWORD *)&v15->mNext + HIDWORD(v14[2].m_pSimObject)) + 64i64);
    vel.x = muzzleDir.x * v13;
    vel.y = muzzleDir.y * v13;
    vel.z = muzzleDir.z * v13;
    vTargetNormalAimPosition.x = (float)(muzzleDir.x * v13) + vWeaponProjectileSpawnPosition.x;
    vTargetNormalAimPosition.y = vWeaponProjectileSpawnPosition.y + (float)(muzzleDir.y * v13);
    vTargetNormalAimPosition.z = vWeaponProjectileSpawnPosition.z + (float)(muzzleDir.z * v13);
    if ( v2 )
    {
      v18 = v2->m_Accuracy.m_fAccuracyUnclamped - 1.0;
      if ( v18 < 0.0 )
        LODWORD(v18) ^= _xmm[0];
      v19 = v18 < 0.001;
      v20 = v2->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
      if ( v20 )
      {
        v21 = ((__int64 (*)(void))v20->vfptr[19].__vecDelDtor)();
        if ( v21 )
        {
          isHardLocked = *(_DWORD *)(v21 + 3432) == 1;
LABEL_44:
          UFG::ProjectileInfo::ProjectileInfo(
            &pi,
            (UFG::SimObjectWeaponPropertiesComponent *)v1->mSimObjectWeaponPropertiesComponent.m_pSimComponent,
            v1->mShootParams.pSubTargetingLocation,
            v19,
            isHardLocked);
          v23 = *(_DWORD *)(*((_QWORD *)&v1->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                            + HIDWORD(v1->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                          + 0x80i64);
          if ( (signed int)v23 > 0 )
          {
            v24 = v23;
            do
            {
              posIsObscured = 0;
              vPositionReturn = vWeaponProjectileSpawnPosition;
              if ( v1->mShootParams.pWeaponOwnerSimObject.m_pPointer && v2 )
              {
                v26 = (unsigned int)v1->mMustHitTarget;
                if ( (_DWORD)v26 )
                  UFG::AimingBaseComponent::GetTargetNormalAimPosition(v2, &vTargetNormalAimPosition, v26, 0i64);
                else
                  v2->vfptr[20].__vecDelDtor(
                    (UFG::qSafePointerNode<UFG::SimComponent> *)&v2->vfptr,
                    (unsigned int)&vTargetNormalAimPosition);
                if ( v1->mShootParams.pWeaponOwnerSimObject.m_pPointer )
                {
                  v27 = (UFG::AimingPlayerComponent *)((__int64 (__fastcall *)(UFG::AimingBaseComponent *))v2->vfptr[16].__vecDelDtor)(v2);
                  if ( v27 )
                    posIsObscured = UFG::AimingPlayerComponent::GetWeaponProjectileSpawnPositionUnobscured(
                                      v27,
                                      &vTargetNormalAimPosition,
                                      &vPositionReturn);
                  else
                    UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(v2, &vWeaponProjectileSpawnPosition);
                }
                v28 = vTargetNormalAimPosition.z - vWeaponProjectileSpawnPosition.z;
                v29 = (__m128)LODWORD(vTargetNormalAimPosition.y);
                v29.m128_f32[0] = vTargetNormalAimPosition.y - vWeaponProjectileSpawnPosition.y;
                v30 = vTargetNormalAimPosition.x - vWeaponProjectileSpawnPosition.x;
                v31 = v29;
                v31.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v30 * v30))
                                + (float)(v28 * v28);
                if ( v31.m128_f32[0] == 0.0 )
                  v32 = 0.0;
                else
                  v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
                vel.x = (float)(v30 * v32) * v13;
                vel.y = (float)(v29.m128_f32[0] * v32) * v13;
                vel.z = (float)(v28 * v32) * v13;
              }
              UFG::BulletManager::FireBullet(
                UFG::BulletManager::mInstance,
                v1->mShootParams.pWeaponOwnerSimObject.m_pPointer,
                &muzzleDir,
                &vWeaponProjectileSpawnPosition,
                &vel,
                projectileGravity,
                armingDistance,
                posIsObscured,
                &vPositionReturn,
                &pi,
                (v1->mShootParams.shootFlags >> 1) & 1,
                0,
                v1->mMustHitTarget);
              --v24;
            }
            while ( v24 );
          }
          if ( v2 )
            v2->m_Accuracy.m_fAccuracyPenalty = *(float *)(*((_QWORD *)&v1->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                                           + HIDWORD(v1->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                                                         + 164i64)
                                              + v2->m_Accuracy.m_fAccuracyPenalty;
          v1->mNetBulletPosition.x = vWeaponProjectileSpawnPosition.x;
          v1->mNetBulletPosition.y = vWeaponProjectileSpawnPosition.y;
          v1->mNetBulletPosition.z = vWeaponProjectileSpawnPosition.z;
          v1->mNetBulletVelocity.x = vel.x;
          v1->mNetBulletVelocity.y = vel.y;
          v1->mNetBulletVelocity.z = vel.z;
          ++v1->mNetShootSequence;
          if ( pi.m_pSOWPC.m_pPointer )
          {
            v33 = pi.m_pSOWPC.mPrev;
            v34 = pi.m_pSOWPC.mNext;
            pi.m_pSOWPC.mPrev->mNext = pi.m_pSOWPC.mNext;
            v34->mPrev = v33;
            pi.m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&pi;
            pi.m_pSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&pi;
          }
          pi.m_pSOWPC.m_pPointer = 0i64;
          v35 = pi.m_pSOWPC.mPrev;
          v36 = pi.m_pSOWPC.mNext;
          pi.m_pSOWPC.mPrev->mNext = pi.m_pSOWPC.mNext;
          v36->mPrev = v35;
          pi.m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&pi;
          pi.m_pSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&pi;
          goto LABEL_65;
        }
      }
    }
    else
    {
      v19 = 0;
    }
    isHardLocked = 0;
    goto LABEL_44;
  }
LABEL_65:
  v1->mShootParams.shootFlags = -1;
  v37 = &v1->mShootParams.pShootOriginSimObject;
  if ( v1->mShootParams.pShootOriginSimObject.m_pPointer )
  {
    v38 = v37->mPrev;
    v39 = v1->mShootParams.pShootOriginSimObject.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    v37->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v37->mPrev;
    v1->mShootParams.pShootOriginSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mShootParams.pShootOriginSimObject.mPrev;
  }
  v1->mShootParams.pShootOriginSimObject.m_pPointer = 0i64;
  v1->mShootParams.shootBoneId = UFG::gNullQSymbolUC;
  v40 = &v1->mShootParams.pWeaponOwnerSimObject;
  if ( v1->mShootParams.pWeaponOwnerSimObject.m_pPointer )
  {
    v41 = v40->mPrev;
    v42 = v1->mShootParams.pWeaponOwnerSimObject.mNext;
    v41->mNext = v42;
    v42->mPrev = v41;
    v40->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v40->mPrev;
    v1->mShootParams.pWeaponOwnerSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mShootParams.pWeaponOwnerSimObject.mPrev;
  }
  v1->mShootParams.pWeaponOwnerSimObject.m_pPointer = 0i64;
  v1->mShootParams.pAimingC = 0i64;
  v1->mShootParams.pSubTargetingLocation = 0i64;
}

// File Line: 264
// RVA: 0x522BE0
bool __fastcall UFG::GunComponent::CanFireWeapon(UFG::GunComponent *this, const bool bIsAI)
{
  float v2; // xmm6_4
  float v3; // xmm0_4
  float v4; // xmm6_4

  v2 = (float)SLODWORD(UFG::Metrics::msInstance.mSimTimeMSec);
  if ( (UFG::Metrics::msInstance.mSimTimeMSec & 0x8000000000000000ui64) != 0i64 )
    v2 = v2 + 1.8446744e19;
  v3 = this->mRateOfFireOverride;
  v4 = (float)(v2 * 0.001) - this->mLastFiredTime;
  if ( v3 == -1.0 )
    v3 = UFG::SimObjectWeaponPropertiesComponent::DetermineRateOfFire(
           (UFG::SimObjectWeaponPropertiesComponent *)this->mSimObjectWeaponPropertiesComponent.m_pSimComponent,
           bIsAI);
  return v4 >= v3;
}

// File Line: 280
// RVA: 0x5356A0
bool __fastcall UFG::GunComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(v2, (UFG::qSymbol *)&SimSymX_propset_componentGun.mUID, DEPTH_RECURSE) != 0i64;
}

// File Line: 286
// RVA: 0x544FE0
UFG::SimComponent *__fastcall UFG::GunComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h]

  v1 = sceneObject;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x138ui64, "GunComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v1->mpWritableProperties;
    if ( !v4 )
      v4 = v1->mpConstProperties;
    UFG::GunComponent::GunComponent((UFG::GunComponent *)v3, v1->m_NameUID, v4, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return v6;
}

// File Line: 296
// RVA: 0x53DDE0
void __fastcall UFG::GunComponent::OnAttach(UFG::GunComponent *this, UFG::SimObject *object)
{
  UFG::GunComponent *v2; // rdi
  UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0> *v3; // rcx
  UFG::SimObject *v4; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax

  v2 = this;
  v3 = &this->mSimObjectWeaponPropertiesComponent;
  v4 = object;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pSimObject = 0i64;
    v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0> *)v3->mNext != v3) )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = v4;
  v3->m_TypeUID = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0>::BindInternal<UFG::SimObject>(v3, v4);
  v9 = &v2->mInventoryItemComponent;
  if ( v2->mInventoryItemComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->mInventoryItemComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->mInventoryItemComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mInventoryItemComponent.m_pSimObject = 0i64;
    v2->mInventoryItemComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mInventoryItemComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v2->mInventoryItemComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *)v2->mInventoryItemComponent.mNext != &v2->mInventoryItemComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->mInventoryItemComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v2->mInventoryItemComponent.m_Changed = 1;
  v2->mInventoryItemComponent.m_pSimObject = v4;
  v2->mInventoryItemComponent.m_TypeUID = UFG::InventoryItemComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0>::BindInternal<UFG::SimObject>(
    &v2->mInventoryItemComponent,
    v4);
  UFG::GunComponent::Initialize(v2);
}

// File Line: 305
// RVA: 0x5404A0
void __fastcall UFG::GunComponent::OnDetach(UFG::GunComponent *this)
{
  UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0> *v1; // r8
  UFG::GunComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax

  v1 = &this->mSimObjectWeaponPropertiesComponent;
  v2 = this;
  if ( this->mSimObjectWeaponPropertiesComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->mSimObjectWeaponPropertiesComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->mSimObjectWeaponPropertiesComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->mSimObjectWeaponPropertiesComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0> *)this->mSimObjectWeaponPropertiesComponent.mNext != &this->mSimObjectWeaponPropertiesComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->mInventoryItemComponent;
  v1->m_Changed = 1;
  if ( v2->mInventoryItemComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->mInventoryItemComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->mInventoryItemComponent.m_pSimComponent = 0i64;
    v2->mInventoryItemComponent.m_pSimObject = 0i64;
    v2->mInventoryItemComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mInventoryItemComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    v2->mInventoryItemComponent.m_Changed = 1;
  }
  else
  {
    if ( v2->mInventoryItemComponent.m_pSimObject
      && ((UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *)v7->mPrev != v7
       || (UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *)v2->mInventoryItemComponent.mNext != &v2->mInventoryItemComponent) )
    {
      v10 = v7->mPrev;
      v11 = v2->mInventoryItemComponent.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v2->mInventoryItemComponent.m_pSimObject = 0i64;
      v2->mInventoryItemComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mInventoryItemComponent.mPrev;
      v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    }
    v2->mInventoryItemComponent.m_Changed = 1;
  }
}

// File Line: 313
// RVA: 0x54F520
char __fastcall UFG::GunComponent::Shoot(UFG::GunComponent *this, unsigned int shootFlags)
{
  return UFG::GunComponent::Shoot(this, 0i64, 0i64, shootFlags, 0i64, 0i64, &UFG::gNullQSymbolUC);
}

// File Line: 322
// RVA: 0x54F550
char __fastcall UFG::GunComponent::Shoot(UFG::GunComponent *this, UFG::SimObject *pWeaponOwnerSimObject, UFG::AimingBaseComponent *pAimingC, unsigned int shootFlags, UFG::SubTargetingLocation *pSubTargetingLocation, UFG::SimObject *pShootOriginSimObject, UFG::qSymbolUC *originBoneId)
{
  unsigned int v7; // er14
  UFG::AimingBaseComponent *v8; // r15
  UFG::SimObject *v9; // rbp
  UFG::GunComponent *v10; // rbx
  UFG::SimObjectProp *v11; // rcx
  unsigned __int16 v12; // r10
  UFG::SimObjectCharacter *v13; // rdi
  UFG::CharacterAnimationComponent *v14; // rcx
  unsigned int v15; // edx
  unsigned int v16; // edx
  UFG::CharacterAnimationComponent *v17; // rax
  unsigned int v18; // er8
  unsigned int v19; // er9
  UFG::SimComponentHolder *v20; // rsi
  UFG::CopSystem *v21; // rax
  UFG::SimComponent *v22; // r9
  int v23; // er8
  int v24; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v29; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  __int64 v37; // rcx
  UFG::SimObject *v38; // rbx
  UFG::GunshotManager *v39; // rax

  v7 = shootFlags;
  v8 = pAimingC;
  v9 = pWeaponOwnerSimObject;
  v10 = this;
  v11 = (UFG::SimObjectProp *)this->m_pSimObject;
  if ( !v11 )
    return 0;
  v12 = v11->m_Flags;
  v13 = 0i64;
  if ( (v12 >> 14) & 1 )
  {
    v14 = (UFG::CharacterAnimationComponent *)v11->m_Components.p[9].m_pComponent;
    if ( !v14 )
      goto LABEL_6;
    v15 = v14->m_TypeUID;
    if ( (v15 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v15 & 0x1FFFFFF )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( (v12 & 0x8000u) != 0 )
  {
    v14 = (UFG::CharacterAnimationComponent *)v11->m_Components.p[9].m_pComponent;
    if ( !v14 )
      goto LABEL_6;
    v16 = v14->m_TypeUID;
    if ( (v16 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000 )
      goto LABEL_6;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v16 & 0x1FFFFFF )
      v14 = 0i64;
    goto LABEL_24;
  }
  if ( (v12 >> 13) & 1 )
  {
    v17 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v11);
LABEL_23:
    v14 = v17;
    goto LABEL_24;
  }
  if ( !((v12 >> 12) & 1) )
  {
    v17 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v11->vfptr,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  v18 = v11->mComponentTableEntryCount;
  v19 = v11->m_Components.size;
  if ( v18 >= v19 )
  {
LABEL_6:
    v14 = 0i64;
    goto LABEL_24;
  }
  v20 = v11->m_Components.p;
  while ( (v20[v18].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~v20[v18].m_TypeUID & 0x1FFFFFF )
  {
    if ( ++v18 >= v19 )
      goto LABEL_6;
  }
  v14 = (UFG::CharacterAnimationComponent *)v20[v18].m_pComponent;
LABEL_24:
  if ( !v14 || !v10->mClipAmmo[HIDWORD(v10->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject)] )
    return 0;
  if ( v7 & 1 )
  {
    v21 = UFG::CopSystem::Instance();
    v21->vfptr[97].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v21->vfptr, (unsigned int)v9);
    v22 = v10->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
    v23 = *(_DWORD *)(*((_QWORD *)&v22[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v22[2].m_pSimObject))
                    + 8i64);
    v24 = -10;
    if ( v10->mClipAmmo[HIDWORD(v22[2].m_pSimObject)] - 1 > -10 )
      v24 = v10->mClipAmmo[HIDWORD(v22[2].m_pSimObject)] - 1;
    if ( v24 < v23 )
      v23 = v24;
    v10->mClipAmmo[HIDWORD(v22[2].m_pSimObject)] = v23;
  }
  v10->mShootParams.shootFlags = v7;
  v25 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mShootParams.pShootOriginSimObject.mPrev;
  if ( v10->mShootParams.pShootOriginSimObject.m_pPointer )
  {
    v26 = v25->mPrev;
    v27 = v10->mShootParams.pShootOriginSimObject.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    v25->mPrev = v25;
    v10->mShootParams.pShootOriginSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mShootParams.pShootOriginSimObject.mPrev;
  }
  v10->mShootParams.pShootOriginSimObject.m_pPointer = pShootOriginSimObject;
  if ( pShootOriginSimObject )
  {
    v28 = pShootOriginSimObject->m_SafePointerList.mNode.mPrev;
    v28->mNext = v25;
    v25->mPrev = v28;
    v10->mShootParams.pShootOriginSimObject.mNext = &pShootOriginSimObject->m_SafePointerList.mNode;
    pShootOriginSimObject->m_SafePointerList.mNode.mPrev = v25;
  }
  v10->mShootParams.shootBoneId = (UFG::qSymbolUC)originBoneId->mUID;
  v29 = &v10->mShootParams.pWeaponOwnerSimObject;
  if ( v10->mShootParams.pWeaponOwnerSimObject.m_pPointer )
  {
    v30 = v29->mPrev;
    v31 = v10->mShootParams.pWeaponOwnerSimObject.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    v29->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v29->mPrev;
    v10->mShootParams.pWeaponOwnerSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mShootParams.pWeaponOwnerSimObject.mPrev;
  }
  v10->mShootParams.pWeaponOwnerSimObject.m_pPointer = v9;
  if ( v9 )
  {
    v32 = v9->m_SafePointerList.mNode.mPrev;
    v32->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v29->mPrev;
    v29->mPrev = v32;
    v10->mShootParams.pWeaponOwnerSimObject.mNext = &v9->m_SafePointerList.mNode;
    v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v29->mPrev;
  }
  v10->mShootParams.pSubTargetingLocation = pSubTargetingLocation;
  v10->mShootParams.pAimingC = v8;
  v33 = v10->mRateOfFireOverride;
  if ( v33 == -1.0 )
    v33 = UFG::SimObjectWeaponPropertiesComponent::DetermineRateOfFire(
            (UFG::SimObjectWeaponPropertiesComponent *)v10->mSimObjectWeaponPropertiesComponent.m_pSimComponent,
            v9 != (UFG::SimObject *)LocalPlayer);
  v34 = (float)SLODWORD(UFG::Metrics::msInstance.mSimTimeMSec);
  if ( (UFG::Metrics::msInstance.mSimTimeMSec & 0x8000000000000000ui64) != 0i64 )
    v34 = v34 + 1.8446744e19;
  v35 = v34 * 0.001;
  v36 = (float)(v35 - v10->mLastFiredTime) - v33;
  if ( !*(_BYTE *)(*((_QWORD *)&v10->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                   + HIDWORD(v10->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                 + 117i64)
    || v36 > v33 )
  {
    v36 = 0.0;
  }
  v10->mLastFiredTime = v35 - v36;
  v37 = *(_QWORD *)&v10->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
  if ( v37 )
    v13 = *(UFG::SimObjectCharacter **)(v37 + 40);
  if ( v13 == LocalPlayer )
    UFG::GameStatAction::Weapon::Discharge(v10);
  if ( !(_S25_0 & 1) )
  {
    _S25_0 |= 1u;
    play_gunshot.mUID = UFG::qWiseSymbolUIDFromString("play_gunshot", 0x811C9DC5);
    _((AMD_HD3D *)play_gunshot.mUID);
    atexit(UFG::GunComponent::Shoot_::_11_::_dynamic_atexit_destructor_for__play_gunshot__);
  }
  v38 = v10->m_pSimObject;
  v39 = UFG::GunshotManager::GetInstance();
  UFG::GunshotManager::RequestShotStart(v39, play_gunshot.mUID, v38);
  return 1;
}ructor_for__play_gunshot__);
  }
  v38 = v10->m_pSimObject;
  v39 = UFG::GunshotManager::GetInstance();
  UFG::GunshotManager::Request

// File Line: 373
// RVA: 0x520940
void __fastcall UFG::GunComponent::AddClipOfAmmo(UFG::GunComponent *this)
{
  __int64 v1; // r8
  __int64 v2; // rax
  signed int v3; // edx

  v1 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
  if ( v1 )
  {
    v2 = *(signed int *)(*((_QWORD *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                         + HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                       + 4i64);
    if ( *(_BYTE *)(v1 + 936) && (_DWORD)v2 == *(_DWORD *)(v1 + 928) )
      v3 = 1;
    else
      v3 = *(_DWORD *)(v1 + 4 * v2 + 92);
  }
  else
  {
    v3 = 0;
  }
  UFG::GunComponent::SetTotalAmmo(
    this,
    *(_DWORD *)(*((_QWORD *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                + HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
              + 8i64)
  + v3);
}

// File Line: 389
// RVA: 0x54BF40
void __fastcall UFG::GunComponent::SetClipAmmo(UFG::GunComponent *this, int count)
{
  UFG::GunComponent *v2; // r10
  int v3; // eax
  UFG::InventoryItemComponent *v4; // r9

  v2 = (UFG::GunComponent *)this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  v3 = -10;
  LODWORD(v4) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)&v2->mInventoryItemComponent.m_TypeUID
                                      + 8i64 * HIDWORD(v2->mInventoryItemComponent.mNext)
                                      + 8)
                          + 8i64);
  if ( count > -10 )
    v3 = count;
  if ( v3 < (signed int)v4 )
    LODWORD(v4) = v3;
  this->mClipAmmo[HIDWORD(v2->mInventoryItemComponent.mNext)] = (signed int)v4;
}

// File Line: 403
// RVA: 0x52B1E0
__int64 __fastcall UFG::GunComponent::GetClipAmmo(UFG::GunComponent *this)
{
  return (unsigned int)this->mClipAmmo[HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject)];
}

// File Line: 416
// RVA: 0x52B200
__int64 __fastcall UFG::GunComponent::GetClipCapacity(UFG::GunComponent *this)
{
  return *(unsigned int *)(*((_QWORD *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                           + HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                         + 8i64);
}

// File Line: 422
// RVA: 0x530B50
signed __int64 __fastcall UFG::GunComponent::GetTotalAmmo(UFG::GunComponent *this)
{
  __int64 v1; // rdx
  __int64 v2; // rax
  signed __int64 result; // rax

  v1 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
  if ( !v1 )
    return 0i64;
  v2 = *(signed int *)(*((_QWORD *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                       + HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                     + 4i64);
  if ( *(_BYTE *)(v1 + 936) && (_DWORD)v2 == *(_DWORD *)(v1 + 928) )
    result = 1i64;
  else
    result = *(unsigned int *)(v1 + 4 * v2 + 92);
  return result;
}

// File Line: 434
// RVA: 0x54F410
void __fastcall UFG::GunComponent::SetTotalAmmo(UFG::GunComponent *this, int count)
{
  int v2; // er11
  __int64 v3; // r9
  UFG::SimComponent *v4; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  __int64 v6; // r10
  __int64 v7; // rcx
  int v8; // eax
  int v9; // edx

  v2 = count;
  v3 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
  if ( v3 )
  {
    v4 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
    v5 = v4[2].m_BoundComponentHandles.mNode.mPrev;
    v6 = *(signed int *)(*((_QWORD *)&v5->mNext + HIDWORD(v4[2].m_pSimObject)) + 4i64);
    v7 = *((_QWORD *)&v5->mNext + HIDWORD(v4[2].m_pSimObject));
    v8 = 0;
    v9 = *(_DWORD *)(v7 + 12);
    if ( v2 > 0 )
      v8 = v2;
    if ( v8 < v9 )
      v9 = v8;
    *(_DWORD *)(v3 + 4 * v6 + 92) = v9;
    if ( *(UFG::SimObjectCharacter **)(v3 + 40) == LocalPlayer )
    {
      if ( *(_BYTE *)(v3 + 936) )
      {
        if ( (_DWORD)v6 == *(_DWORD *)(v3 + 928) )
          v9 = 1;
      }
      UFG::GameStatAction::Inventory::UpdateItem((UFG::eInventoryItemEnum)v6, v9);
    }
  }
}

// File Line: 445
// RVA: 0x53C1A0
__int64 __fastcall UFG::GunComponent::IsStowable(UFG::GunComponent *this)
{
  return *(unsigned __int8 *)(*((_QWORD *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                              + HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                            + 0x76i64);
}

// File Line: 451
// RVA: 0x542450
void __fastcall UFG::GunComponent::OverrideRateOfFire(UFG::GunComponent *this, bool bOverride, float fSecondsPerShot)
{
  if ( bOverride )
    this->mRateOfFireOverride = fSecondsPerShot;
  else
    this->mRateOfFireOverride = FLOAT_N1_0;
}

// File Line: 456
// RVA: 0x52B220
__int64 __fastcall UFG::GunComponent::GetClipsRemaining(UFG::GunComponent *this)
{
  __int64 v1; // rdx
  UFG::SimComponent *v2; // r9
  __int64 v3; // rax
  signed int v4; // er8
  int v5; // er9
  __m128 v6; // xmm1
  signed int v7; // ecx
  __int64 result; // rax

  v1 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
  if ( !v1 )
    return 0i64;
  v2 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  v3 = *(signed int *)(*((_QWORD *)&v2[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v2[2].m_pSimObject))
                     + 4i64);
  if ( !*(_BYTE *)(v1 + 936) || (v4 = 1, (_DWORD)v3 != *(_DWORD *)(v1 + 928)) )
    v4 = *(_DWORD *)(v1 + 4 * v3 + 92);
  v5 = *(_DWORD *)(*((_QWORD *)&v2[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v2[2].m_pSimObject)) + 8i64);
  v6 = (__m128)COERCE_UNSIGNED_INT((float)(v4 / v5));
  v7 = (signed int)v6.m128_f32[0];
  if ( (signed int)v6.m128_f32[0] != 0x80000000 && (float)v7 != v6.m128_f32[0] )
    v6.m128_f32[0] = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v6, v6)) & 1));
  result = (unsigned int)(signed int)v6.m128_f32[0];
  if ( v4 - (signed int)result * v5 > 0 )
    result = (unsigned int)(result + 1);
  return result;
}

// File Line: 478
// RVA: 0x548CA0
void __usercall UFG::GunComponent::Reload(UFG::GunComponent *this@<rcx>, int amount@<edx>, __int64 a3@<r15>)
{
  UFG::GunComponent *v3; // rbx
  UFG::SimComponent *v4; // rcx
  int v5; // er8
  __int64 v6; // rax
  bool v7; // di
  UFG::SimComponent *v8; // rdx
  signed __int64 v9; // r9
  int v10; // er8
  signed int v11; // eax
  signed int v12; // edx

  v3 = this;
  v4 = this->mInventoryItemComponent.m_pSimComponent;
  v5 = amount;
  v6 = *(_QWORD *)&v4[1].m_Flags;
  if ( v6 )
    v6 = *(_QWORD *)(v6 + 40);
  v7 = v6 == (_QWORD)LocalPlayer;
  if ( v4 && v7 )
  {
    UFG::GunComponent::ReloadFromInventory(v3, amount, a3);
  }
  else
  {
    if ( amount < 0 )
      v5 = *(_DWORD *)(*((_QWORD *)&v3->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                       + HIDWORD(v3->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                     + 8i64);
    v8 = v3->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
    v9 = (signed __int64)v3 + 4 * HIDWORD(v8[2].m_pSimObject);
    v10 = *(_DWORD *)(v9 + 212) + v5;
    v11 = -10;
    v12 = *(_DWORD *)(*((_QWORD *)&v8[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v8[2].m_pSimObject)) + 8i64);
    if ( v10 > -10 )
      v11 = v10;
    if ( v11 < v12 )
      v12 = v11;
    *(_DWORD *)(v9 + 212) = v12;
  }
  if ( v7 )
    UFG::GameStatAction::Weapon::Reload(v3);
}

// File Line: 498
// RVA: 0x548D70
void __usercall UFG::GunComponent::ReloadFromInventory(UFG::GunComponent *this@<rcx>, int amount@<edx>, __int64 a3@<r15>)
{
  UFG::SimComponent *v3; // r8
  UFG::SimComponent *v4; // rax
  UFG::InventoryComponent *v5; // r10
  __int64 v6; // rax
  UFG::eInventoryItemEnum v7; // er11
  UFG::SimComponent *v8; // rax
  __int64 v9; // rbx
  int v10; // er8

  v3 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  if ( v3 )
  {
    v4 = this->mInventoryItemComponent.m_pSimComponent;
    if ( v4 )
    {
      v5 = *(UFG::InventoryComponent **)&v4[1].m_Flags;
      if ( v5 )
      {
        v6 = HIDWORD(v3[2].m_pSimObject);
        v7 = *(_DWORD *)(*((_QWORD *)&v3[2].m_BoundComponentHandles.mNode.mPrev->mNext + v6) + 4i64);
        if ( this->mClipAmmo[v6] < 0 )
          this->mClipAmmo[v6] = 0;
        v8 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
        v9 = HIDWORD(v8[2].m_pSimObject);
        v10 = *(_DWORD *)(*((_QWORD *)&v8[2].m_BoundComponentHandles.mNode.mPrev->mNext + v9) + 8i64)
            - this->mClipAmmo[v9];
        if ( amount > 0 )
          v10 = amount;
        this->mClipAmmo[HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject)] = this->mClipAmmo[v9] + (unsigned __int64)UFG::InventoryComponent::RemoveQuantity(v5, v7, v10, a3);
      }
    }
  }
}

// File Line: 526
// RVA: 0x54BC40
void __fastcall UFG::GunComponent::SetAmmoForAIDeath(UFG::GunComponent *this)
{
  UFG::GunComponent *v1; // rbx
  UFG::SimComponent *v2; // rax
  UFG::SimComponent *v3; // rcx
  unsigned int v4; // ebp
  __int64 v5; // rcx
  UFG::SimObjectCharacter *v6; // rcx
  UFG::SimComponent *v7; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  __int64 v9; // rsi
  int v10; // edi

  v1 = this;
  if ( this->mIfResetAmmoOnDeath )
  {
    v2 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
    if ( v2 )
    {
      v3 = this->mInventoryItemComponent.m_pSimComponent;
      v4 = 0;
      if ( !v3
        || ((v5 = *(_QWORD *)&v3[1].m_Flags) == 0 ? (v6 = 0i64) : (v6 = *(UFG::SimObjectCharacter **)(v5 + 40)),
            v6 != LocalPlayer) )
      {
        if ( HIDWORD(v2[2].m_BoundComponentHandles.mNode.mPrev->mPrev) > 0 )
        {
          v7 = v1->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
          do
          {
            v8 = v7[2].m_BoundComponentHandles.mNode.mPrev;
            v9 = HIDWORD(v7[2].m_pSimObject);
            v10 = *(_DWORD *)(*((_QWORD *)&v8->mNext + v9) + 208i64);
            ++v4;
            v1->mClipAmmo[v9] = v10
                              + (unsigned __int64)UFG::qRandom(
                                                    *(_DWORD *)(*((_QWORD *)&v8->mNext + v9) + 204i64)
                                                  - *(_DWORD *)(*((_QWORD *)&v8->mNext + v9) + 208i64),
                                                    &UFG::qDefaultSeed);
            v7 = v1->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
          }
          while ( v4 < HIDWORD(v7[2].m_BoundComponentHandles.mNode.mPrev->mPrev) );
        }
      }
    }
  }
}

// File Line: 542
// RVA: 0x556C50
void __fastcall UFG::GunComponent::TransferAmmoFromGun(UFG::GunComponent *this, UFG::GunComponent *pFromGC)
{
  UFG::SimComponent *v2; // rax
  UFG::GunComponent *v3; // r15
  UFG::GunComponent *v4; // r14
  __int64 v5; // rbx
  unsigned int v6; // esi
  __int64 v7; // rbp
  int *v8; // rdi
  __int64 v9; // r8
  char v10; // cl
  __int64 v11; // rdx
  signed int v12; // eax
  int v13; // er8
  signed int v14; // eax
  UFG::SimComponent *v15; // r8
  int v16; // edx

  v2 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  v3 = pFromGC;
  v4 = this;
  if ( v2 )
  {
    if ( pFromGC )
    {
      v5 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
      if ( v5 )
      {
        v6 = 0;
        if ( HIDWORD(v2[2].m_BoundComponentHandles.mNode.mPrev->mPrev) )
        {
          v7 = 0i64;
          v8 = pFromGC->mClipAmmo;
          do
          {
            v9 = *(__int64 *)((char *)&v4->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                            + v7);
            v10 = *(_BYTE *)(v5 + 936);
            v11 = *(signed int *)(v9 + 4);
            if ( !v10 || (v12 = 1, (_DWORD)v11 != *(_DWORD *)(v5 + 928)) )
              v12 = *(_DWORD *)(v5 + 4 * v11 + 92);
            if ( v12 < *(_DWORD *)(v9 + 12) )
            {
              v13 = *v8;
              if ( *v8 > 0 )
              {
                if ( !v10 || (v14 = 1, (_DWORD)v11 != *(_DWORD *)(v5 + 928)) )
                  v14 = *(_DWORD *)(v5 + 4 * v11 + 92);
                if ( UFG::InventoryComponent::ms_InventoryItemInfos[v11].m_iCapacity - v14 < v13 )
                  v13 = UFG::InventoryComponent::ms_InventoryItemInfos[v11].m_iCapacity - v14;
                UFG::InventoryComponent::AddQuantity(
                  (UFG::InventoryComponent *)v5,
                  (UFG::eInventoryItemEnum)v11,
                  v13,
                  (__int64)v3);
                v15 = v3->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
                v16 = *(_DWORD *)(*((_QWORD *)&v15[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                  + HIDWORD(v15[2].m_pSimObject))
                                + 8i64);
                if ( v16 > 0 )
                  v16 = 0;
                v3->mClipAmmo[HIDWORD(v15[2].m_pSimObject)] = v16;
                UFG::GunComponent::PlayReloadSFX(v4);
              }
            }
            ++v6;
            ++v8;
            v7 += 8i64;
          }
          while ( v6 < HIDWORD(v4->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mPrev) );
        }
      }
    }
  }
}

// File Line: 572
// RVA: 0x5427C0
void __fastcall UFG::GunComponent::PlayReloadSFX(UFG::GunComponent *this)
{
  if ( !(_S26_1 & 1) )
  {
    _S26_1 |= 1u;
    UFG::qWiseSymbol::create_from_string(&play_ui_ammo, "play_ui_ammo");
    atexit(UFG::GunComponent::PlayReloadSFX_::_2_::_dynamic_atexit_destructor_for__play_ui_ammo__);
  }
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      play_ui_ammo.mUID,
      0i64,
      0,
      0i64);
}

// File Line: 578
// RVA: 0x522C50
char __fastcall UFG::GunComponent::CanReload(UFG::GunComponent *this)
{
  UFG::SimComponent *v1; // r9
  UFG::SimComponent *v2; // r10
  UFG::SimObjectCharacter *v3; // rax
  __int64 v4; // rax
  __int64 v5; // rcx
  char result; // al

  v1 = this->mInventoryItemComponent.m_pSimComponent;
  if ( !v1 )
    goto LABEL_13;
  v2 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  if ( *(_DWORD *)(*((_QWORD *)&v2[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v2[2].m_pSimObject)) + 8i64) <= this->mClipAmmo[HIDWORD(v2[2].m_pSimObject)] )
    goto LABEL_14;
  v3 = *(UFG::SimObjectCharacter **)&v1[1].m_Flags;
  if ( v3 )
    v3 = (UFG::SimObjectCharacter *)v3->mNode.mParent;
  if ( v3 != LocalPlayer
    || (v4 = *(signed int *)(*((_QWORD *)&v2[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v2[2].m_pSimObject))
                           + 4i64),
        v5 = *(_QWORD *)&v1[1].m_Flags,
        *(_BYTE *)(v5 + 936))
    && (_DWORD)v4 == *(_DWORD *)(v5 + 928)
    || *(_DWORD *)(v5 + 4 * v4 + 92) > 0 )
  {
LABEL_13:
    result = 1;
  }
  else
  {
LABEL_14:
    result = 0;
  }
  return result;
}

// File Line: 609
// RVA: 0x539340
void __fastcall UFG::GunComponent::InitializeGunIntoInventory(UFG::GunComponent *this)
{
  UFG::SimComponent *v1; // rax
  UFG::GunComponent *v2; // rbx
  __int64 v3; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rcx
  __int64 v5; // rsi
  signed __int64 v6; // r10
  __int64 v7; // rax
  int v8; // er8
  UFG::InventoryItemInfo *v9; // rcx
  __int64 v10; // r9
  int v11; // edx
  int v12; // er8
  signed int v13; // edx
  UFG::SimComponent *v14; // rax

  v1 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  v2 = this;
  v3 = 0i64;
  v4 = v1[2].m_BoundComponentHandles.mNode.mPrev;
  if ( HIDWORD(v4->mPrev) )
  {
    v5 = 0i64;
    while ( 1 )
    {
      v6 = (signed __int64)v2 + 4 * v3;
      v7 = *(_QWORD *)&v2->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
      v8 = *(_DWORD *)(v6 + 212);
      if ( !v7 )
        goto LABEL_16;
      v9 = *(UFG::InventoryItemInfo **)((char *)&v4->mNext + v5);
      v10 = v9[1].m_iCapacity;
      UFG::InventoryComponent::ms_InventoryItemInfos[v10] = v9[3];
      v11 = (int)(*(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)((char *)&v2->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext + v5))->mNext;
      if ( v8 <= v11 )
        goto LABEL_16;
      v12 = v8 - v11;
      *(_DWORD *)(v6 + 212) = v11;
      v13 = UFG::InventoryComponent::ms_InventoryItemInfos[v10].m_iCapacity;
      if ( v12 <= v13 )
      {
        *(_DWORD *)(v7 + 4 * v10 + 92) = v12;
        if ( *(UFG::SimObjectCharacter **)(v7 + 40) == LocalPlayer )
        {
          if ( *(_BYTE *)(v7 + 936) && (_DWORD)v10 == *(_DWORD *)(v7 + 928) )
            v12 = 1;
          v13 = v12;
          goto LABEL_15;
        }
      }
      else
      {
        *(_DWORD *)(v7 + 4 * v10 + 92) = v13;
        if ( *(UFG::SimObjectCharacter **)(v7 + 40) == LocalPlayer )
        {
          if ( *(_BYTE *)(v7 + 936) )
          {
            if ( (_DWORD)v10 == *(_DWORD *)(v7 + 928) )
              v13 = 1;
          }
LABEL_15:
          UFG::GameStatAction::Inventory::UpdateItem((UFG::eInventoryItemEnum)v10, v13);
          goto LABEL_16;
        }
      }
LABEL_16:
      v14 = v2->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
      v3 = (unsigned int)(v3 + 1);
      v5 += 8i64;
      v4 = v14[2].m_BoundComponentHandles.mNode.mPrev;
      if ( (unsigned int)v3 >= HIDWORD(v4->mPrev) )
      {
        HIDWORD(v14[2].m_pSimObject) = 0;
        return;
      }
    }
  }
  HIDWORD(v1[2].m_pSimObject) = 0;
}

// File Line: 643
// RVA: 0x548FF0
void __fastcall UFG::GunComponent::RemoveGunFromInventory(UFG::GunComponent *this)
{
  UFG::SimComponent *v1; // rax
  UFG::GunComponent *v2; // rbx
  unsigned int v3; // edi
  __int64 v4; // rbp
  signed __int64 v5; // r14
  __int64 v6; // rax
  __int64 v7; // r8
  signed int v8; // ecx
  int v9; // esi
  int v10; // edx

  v1 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  v2 = this;
  if ( v1 )
  {
    v3 = 0;
    if ( HIDWORD(v1[2].m_BoundComponentHandles.mNode.mPrev->mPrev) )
    {
      v4 = 0i64;
      do
      {
        v5 = (signed __int64)v2 + 4 * v3;
        v6 = *(_QWORD *)&v2->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
        if ( v6 )
        {
          v7 = SHIDWORD((*(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)((char *)&v2->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext + v4))->mPrev);
          if ( !*(_BYTE *)(v6 + 936) || (v8 = 1, (_DWORD)v7 != *(_DWORD *)(v6 + 928)) )
            v8 = *(_DWORD *)(v6 + 4 * v7 + 92);
          v9 = v8 + *(_DWORD *)(v5 + 212);
          *(_DWORD *)(v6 + 4 * v7 + 92) = 0;
          if ( *(UFG::SimObjectCharacter **)(v6 + 40) == LocalPlayer )
          {
            if ( !*(_BYTE *)(v6 + 936) || (v10 = 1, (_DWORD)v7 != *(_DWORD *)(v6 + 928)) )
              v10 = 0;
            UFG::GameStatAction::Inventory::UpdateItem((UFG::eInventoryItemEnum)v7, v10);
          }
          *(_DWORD *)(v5 + 212) = v9;
        }
        ++v3;
        v4 += 8i64;
      }
      while ( v3 < HIDWORD(v2->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mPrev) );
    }
    HIDWORD(v2->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject) = 0;
  }
}

