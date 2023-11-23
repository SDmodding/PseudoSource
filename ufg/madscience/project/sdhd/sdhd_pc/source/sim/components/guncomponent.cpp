// File Line: 55
// RVA: 0x1543E80
__int64 dynamic_initializer_for__UFG::GunComponent::s_GunComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::GunComponent::s_GunComponentList__);
}

// File Line: 56
// RVA: 0x532460
const char *__fastcall UFG::GunComponent::GetTypeName(UFG::GunComponent *this)
{
  return "GunComponent";
}

// File Line: 72
// RVA: 0x5177C0
void __fastcall UFG::GunComponent::GunComponent(
        UFG::GunComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *mPrev; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pWeaponOwnerSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pShootOriginSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::GunComponent,UFG::GunComponent>;
  this->mNext = &this->UFG::qNode<UFG::GunComponent,UFG::GunComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GunComponent::`vftable;
  *(_QWORD *)&this->mNetShootSequence = 0i64;
  *(_QWORD *)&this->mNetBulletPosition.y = 0i64;
  *(_QWORD *)&this->mNetBulletVelocity.x = 0i64;
  this->mNetBulletVelocity.z = 0.0;
  UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0>::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0>(&this->mSimObjectWeaponPropertiesComponent);
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0>::RebindingComponentHandle<UFG::InventoryItemComponent,0>(&this->mInventoryItemComponent);
  this->mMustHitTarget = eTARGET_TYPE_INVALID;
  this->mLastFiredTime = -1.0;
  this->mRateOfFireOverride = -1.0;
  this->mIfResetAmmoOnDeath = 1;
  this->mShootParams.pShootOriginSimObject.mPrev = &this->mShootParams.pShootOriginSimObject;
  this->mShootParams.pShootOriginSimObject.mNext = &this->mShootParams.pShootOriginSimObject;
  this->mShootParams.pShootOriginSimObject.m_pPointer = 0i64;
  this->mShootParams.shootBoneId.mUID = -1;
  this->mShootParams.pWeaponOwnerSimObject.mPrev = &this->mShootParams.pWeaponOwnerSimObject;
  this->mShootParams.pWeaponOwnerSimObject.mNext = &this->mShootParams.pWeaponOwnerSimObject;
  this->mShootParams.pWeaponOwnerSimObject.m_pPointer = 0i64;
  mPrev = UFG::GunComponent::s_GunComponentList.mNode.mPrev;
  UFG::GunComponent::s_GunComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::GunComponent,UFG::GunComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::GunComponent,UFG::GunComponent> *)&UFG::GunComponent::s_GunComponentList;
  UFG::GunComponent::s_GunComponentList.mNode.mPrev = &this->UFG::qNode<UFG::GunComponent,UFG::GunComponent>;
  UFG::SimComponent::AddType(this, UFG::GunComponent::_GunComponentTypeUID, "GunComponent");
  *(_QWORD *)this->mClipAmmo = 0i64;
  p_pWeaponOwnerSimObject = &this->mShootParams.pWeaponOwnerSimObject;
  if ( this->mShootParams.pWeaponOwnerSimObject.m_pPointer )
  {
    v7 = p_pWeaponOwnerSimObject->mPrev;
    mNext = this->mShootParams.pWeaponOwnerSimObject.mNext;
    v7->mNext = mNext;
    mNext->mPrev = v7;
    p_pWeaponOwnerSimObject->mPrev = p_pWeaponOwnerSimObject;
    this->mShootParams.pWeaponOwnerSimObject.mNext = &this->mShootParams.pWeaponOwnerSimObject;
  }
  this->mShootParams.pWeaponOwnerSimObject.m_pPointer = 0i64;
  p_pShootOriginSimObject = &this->mShootParams.pShootOriginSimObject;
  if ( this->mShootParams.pShootOriginSimObject.m_pPointer )
  {
    v10 = p_pShootOriginSimObject->mPrev;
    v11 = this->mShootParams.pShootOriginSimObject.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    p_pShootOriginSimObject->mPrev = p_pShootOriginSimObject;
    this->mShootParams.pShootOriginSimObject.mNext = &this->mShootParams.pShootOriginSimObject;
  }
  this->mShootParams.pShootOriginSimObject.m_pPointer = 0i64;
  this->mShootParams.shootBoneId = UFG::gNullQSymbolUC;
  this->mShootParams.pAimingC = 0i64;
  this->mShootParams.shootFlags = -1;
  this->mShootParams.pSubTargetingLocation = 0i64;
}otFlags = -1;
  this->mShootParams.pSubTargetingLocation = 0i64;
}

// File Line: 105
// RVA: 0x5392B0
void __fastcall UFG::GunComponent::Initialize(UFG::GunComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rax
  unsigned int v4; // edi
  __int64 v5; // rbp
  __int64 v6; // rax
  int v7; // ebx
  int v8; // eax
  __int64 v9; // rcx

  m_pSimComponent = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    mPrev = m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    v4 = 0;
    if ( HIDWORD(mPrev->mPrev) )
    {
      v5 = 0i64;
      do
      {
        v6 = *(__int64 *)((char *)&mPrev->mNext + v5);
        v7 = *(_DWORD *)(v6 + 200);
        v8 = UFG::qRandom(*(_DWORD *)(v6 + 196) - v7, (unsigned int *)&UFG::qDefaultSeed);
        v9 = v4++;
        v5 += 8i64;
        this->mClipAmmo[v9] = v7 + v8;
        mPrev = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
      }
      while ( v4 < HIDWORD(mPrev->mPrev) );
    }
  }
}

// File Line: 131
// RVA: 0x51B8D0
void __fastcall UFG::GunComponent::~GunComponent(UFG::GunComponent *this)
{
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *v2; // rbx
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *mPrev; // rcx
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *mNext; // rax
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *v5; // rcx
  UFG::qNode<UFG::GunComponent,UFG::GunComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GunComponent::`vftable;
  if ( this == UFG::GunComponent::s_GunComponentpCurrentIterator )
    UFG::GunComponent::s_GunComponentpCurrentIterator = (UFG::GunComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::GunComponent,UFG::GunComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::GunComponent::ShootParams::~ShootParams(&this->mShootParams);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mInventoryItemComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mSimObjectWeaponPropertiesComponent);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 135
// RVA: 0x154CCD0
__int64 UFG::_dynamic_initializer_for__symMuzzle__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Muzzle", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symMuzzle, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symMuzzle__);
}

// File Line: 138
// RVA: 0x561340
void __fastcall UFG::GunComponent::UpdateTransforms(UFG::GunComponent *this)
{
  UFG::AimingBaseComponent *pAimingC; // rdi
  UFG::SimObjectProp *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *m_pComponent; // rcx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *p; // rsi
  Creature *mCreature; // rsi
  unsigned int mUID; // edx
  int BoneID; // eax
  float v13; // xmm7_4
  UFG::SimComponent *m_pSimComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rax
  float projectileGravity; // xmm9_4
  float armingDistance; // xmm10_4
  float v18; // xmm0_4
  bool v19; // si
  UFG::SimComponent *v20; // rcx
  __int64 v21; // rax
  bool isHardLocked; // al
  int v23; // eax
  __int64 v24; // r14
  char posIsObscured; // si
  unsigned int mMustHitTarget; // r8d
  UFG::AimingPlayerComponent *v27; // rax
  float v28; // xmm3_4
  __m128 y_low; // xmm4
  float v30; // xmm5_4
  __m128 v31; // xmm2
  float v32; // xmm1_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pShootOriginSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v38; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pWeaponOwnerSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::qVector3 vWeaponProjectileSpawnPosition; // [rsp+70h] [rbp-90h] BYREF
  UFG::qVector3 vel; // [rsp+80h] [rbp-80h] BYREF
  UFG::qVector3 vTargetNormalAimPosition; // [rsp+90h] [rbp-70h] BYREF
  UFG::qVector3 muzzleDir; // [rsp+A0h] [rbp-60h] BYREF
  UFG::ProjectileInfo pi; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qVector3 vPositionReturn; // [rsp+D8h] [rbp-28h] BYREF
  __int64 v49; // [rsp+E8h] [rbp-18h]
  UFG::qMatrix44 transform; // [rsp+F0h] [rbp-10h] BYREF

  v49 = -2i64;
  if ( this->mShootParams.shootFlags == -1 )
    return;
  pAimingC = this->mShootParams.pAimingC;
  m_pPointer = (UFG::SimObjectProp *)this->mShootParams.pShootOriginSimObject.m_pPointer;
  if ( !m_pPointer )
    goto LABEL_27;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterAnimationComponent *)m_pPointer->m_Components.p[9].m_pComponent;
    if ( !m_pComponent
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_7;
    }
    goto LABEL_25;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::CharacterAnimationComponent *)m_pPointer->m_Components.p[9].m_pComponent;
    if ( !m_pComponent || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_7;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
    goto LABEL_25;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
LABEL_24:
    m_pComponent = ComponentOfType;
    goto LABEL_25;
  }
  if ( (m_Flags & 0x1000) == 0 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_24;
  }
  mComponentTableEntryCount = m_pPointer->mComponentTableEntryCount;
  size = m_pPointer->m_Components.size;
  if ( mComponentTableEntryCount >= size )
  {
LABEL_7:
    m_pComponent = 0i64;
    goto LABEL_25;
  }
  p = m_pPointer->m_Components.p;
  while ( (p[mComponentTableEntryCount].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~p[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) != 0 )
  {
    if ( ++mComponentTableEntryCount >= size )
      goto LABEL_7;
  }
  m_pComponent = (UFG::CharacterAnimationComponent *)p[mComponentTableEntryCount].m_pComponent;
LABEL_25:
  if ( m_pComponent )
  {
    mCreature = m_pComponent->mCreature;
    goto LABEL_28;
  }
LABEL_27:
  mCreature = 0i64;
LABEL_28:
  if ( mCreature )
  {
    mUID = this->mShootParams.shootBoneId.mUID;
    if ( mUID == -1 )
    {
      if ( mCreature->mPose.mRigHandle.mData )
      {
        mUID = UFG::symMuzzle.mUID;
LABEL_34:
        BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, mUID);
        goto LABEL_36;
      }
    }
    else if ( mCreature->mPose.mRigHandle.mData )
    {
      goto LABEL_34;
    }
    BoneID = -1;
LABEL_36:
    Creature::GetTransform(mCreature, BoneID, &transform);
    muzzleDir.x = transform.v0.x;
    muzzleDir.y = transform.v0.y;
    muzzleDir.z = transform.v0.z;
    vWeaponProjectileSpawnPosition.x = transform.v3.x;
    vWeaponProjectileSpawnPosition.y = transform.v3.y;
    vWeaponProjectileSpawnPosition.z = transform.v3.z;
    v13 = UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileSpeed(
            (UFG::SimObjectWeaponPropertiesComponent *)this->mSimObjectWeaponPropertiesComponent.m_pSimComponent,
            this->mShootParams.pWeaponOwnerSimObject.m_pPointer != LocalPlayer);
    m_pSimComponent = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
    mPrev = m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    projectileGravity = *(float *)(*((_QWORD *)&mPrev->mNext + HIDWORD(m_pSimComponent[2].m_pSimObject)) + 60i64);
    armingDistance = *(float *)(*((_QWORD *)&mPrev->mNext + HIDWORD(m_pSimComponent[2].m_pSimObject)) + 64i64);
    vel.x = muzzleDir.x * v13;
    vel.y = muzzleDir.y * v13;
    vel.z = muzzleDir.z * v13;
    vTargetNormalAimPosition.x = (float)(muzzleDir.x * v13) + vWeaponProjectileSpawnPosition.x;
    vTargetNormalAimPosition.y = vWeaponProjectileSpawnPosition.y + (float)(muzzleDir.y * v13);
    vTargetNormalAimPosition.z = vWeaponProjectileSpawnPosition.z + (float)(muzzleDir.z * v13);
    if ( pAimingC )
    {
      v18 = pAimingC->m_Accuracy.m_fAccuracyUnclamped - 1.0;
      if ( v18 < 0.0 )
        LODWORD(v18) ^= _xmm[0];
      v19 = v18 < 0.001;
      v20 = pAimingC->m_pTargetingSystemPedBaseComponent.m_pSimComponent;
      if ( v20 )
      {
        v21 = ((__int64 (__fastcall *)(UFG::SimComponent *))v20->vfptr[19].__vecDelDtor)(v20);
        if ( v21 )
        {
          isHardLocked = *(_DWORD *)(v21 + 3432) == 1;
LABEL_44:
          UFG::ProjectileInfo::ProjectileInfo(
            &pi,
            (UFG::SimObjectWeaponPropertiesComponent *)this->mSimObjectWeaponPropertiesComponent.m_pSimComponent,
            this->mShootParams.pSubTargetingLocation,
            v19,
            isHardLocked);
          v23 = *(_DWORD *)(*((_QWORD *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                            + HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                          + 0x80i64);
          if ( v23 > 0 )
          {
            v24 = (unsigned int)v23;
            do
            {
              posIsObscured = 0;
              vPositionReturn = vWeaponProjectileSpawnPosition;
              if ( this->mShootParams.pWeaponOwnerSimObject.m_pPointer && pAimingC )
              {
                mMustHitTarget = this->mMustHitTarget;
                if ( mMustHitTarget )
                  UFG::AimingBaseComponent::GetTargetNormalAimPosition(
                    pAimingC,
                    &vTargetNormalAimPosition,
                    mMustHitTarget,
                    0i64);
                else
                  pAimingC->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[20].__vecDelDtor(
                    pAimingC,
                    (unsigned int)&vTargetNormalAimPosition);
                if ( this->mShootParams.pWeaponOwnerSimObject.m_pPointer )
                {
                  v27 = (UFG::AimingPlayerComponent *)((__int64 (__fastcall *)(UFG::AimingBaseComponent *))pAimingC->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(pAimingC);
                  if ( v27 )
                    posIsObscured = UFG::AimingPlayerComponent::GetWeaponProjectileSpawnPositionUnobscured(
                                      v27,
                                      &vTargetNormalAimPosition,
                                      &vPositionReturn);
                  else
                    UFG::AimingBaseComponent::GetWeaponProjectileSpawnPosition(
                      pAimingC,
                      &vWeaponProjectileSpawnPosition);
                }
                v28 = vTargetNormalAimPosition.z - vWeaponProjectileSpawnPosition.z;
                y_low = (__m128)LODWORD(vTargetNormalAimPosition.y);
                y_low.m128_f32[0] = vTargetNormalAimPosition.y - vWeaponProjectileSpawnPosition.y;
                v30 = vTargetNormalAimPosition.x - vWeaponProjectileSpawnPosition.x;
                v31 = y_low;
                v31.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v30 * v30))
                                + (float)(v28 * v28);
                if ( v31.m128_f32[0] == 0.0 )
                  v32 = 0.0;
                else
                  v32 = 1.0 / _mm_sqrt_ps(v31).m128_f32[0];
                vel.x = (float)(v30 * v32) * v13;
                vel.y = (float)(y_low.m128_f32[0] * v32) * v13;
                vel.z = (float)(v28 * v32) * v13;
              }
              UFG::BulletManager::FireBullet(
                UFG::BulletManager::mInstance,
                (UFG::SimObjectCharacter *)this->mShootParams.pWeaponOwnerSimObject.m_pPointer,
                &muzzleDir,
                &vWeaponProjectileSpawnPosition,
                &vel,
                projectileGravity,
                armingDistance,
                posIsObscured,
                &vPositionReturn,
                &pi,
                (this->mShootParams.shootFlags & 2) != 0,
                0,
                this->mMustHitTarget);
              --v24;
            }
            while ( v24 );
          }
          if ( pAimingC )
            pAimingC->m_Accuracy.m_fAccuracyPenalty = *(float *)(*((_QWORD *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                                                 + HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                                                               + 164i64)
                                                    + pAimingC->m_Accuracy.m_fAccuracyPenalty;
          this->mNetBulletPosition = vWeaponProjectileSpawnPosition;
          this->mNetBulletVelocity = vel;
          ++this->mNetShootSequence;
          if ( pi.m_pSOWPC.m_pPointer )
          {
            v33 = pi.m_pSOWPC.mPrev;
            mNext = pi.m_pSOWPC.mNext;
            pi.m_pSOWPC.mPrev->mNext = pi.m_pSOWPC.mNext;
            mNext->mPrev = v33;
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
  this->mShootParams.shootFlags = -1;
  p_pShootOriginSimObject = &this->mShootParams.pShootOriginSimObject;
  if ( this->mShootParams.pShootOriginSimObject.m_pPointer )
  {
    v38 = p_pShootOriginSimObject->mPrev;
    v39 = this->mShootParams.pShootOriginSimObject.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    p_pShootOriginSimObject->mPrev = p_pShootOriginSimObject;
    this->mShootParams.pShootOriginSimObject.mNext = &this->mShootParams.pShootOriginSimObject;
  }
  this->mShootParams.pShootOriginSimObject.m_pPointer = 0i64;
  this->mShootParams.shootBoneId = UFG::gNullQSymbolUC;
  p_pWeaponOwnerSimObject = &this->mShootParams.pWeaponOwnerSimObject;
  if ( this->mShootParams.pWeaponOwnerSimObject.m_pPointer )
  {
    v41 = p_pWeaponOwnerSimObject->mPrev;
    v42 = this->mShootParams.pWeaponOwnerSimObject.mNext;
    v41->mNext = v42;
    v42->mPrev = v41;
    p_pWeaponOwnerSimObject->mPrev = p_pWeaponOwnerSimObject;
    this->mShootParams.pWeaponOwnerSimObject.mNext = &this->mShootParams.pWeaponOwnerSimObject;
  }
  this->mShootParams.pWeaponOwnerSimObject.m_pPointer = 0i64;
  this->mShootParams.pAimingC = 0i64;
  this->mShootParams.pSubTargetingLocation = 0i64;
}

// File Line: 264
// RVA: 0x522BE0
bool __fastcall UFG::GunComponent::CanFireWeapon(UFG::GunComponent *this, bool bIsAI)
{
  float mSimTimeMSec_low; // xmm6_4
  float mRateOfFireOverride; // xmm0_4
  float v4; // xmm6_4

  mSimTimeMSec_low = (float)SLODWORD(UFG::Metrics::msInstance.mSimTimeMSec);
  if ( (UFG::Metrics::msInstance.mSimTimeMSec & 0x8000000000000000ui64) != 0i64 )
    mSimTimeMSec_low = mSimTimeMSec_low + 1.8446744e19;
  mRateOfFireOverride = this->mRateOfFireOverride;
  v4 = (float)(mSimTimeMSec_low * 0.001) - this->mLastFiredTime;
  if ( mRateOfFireOverride == -1.0 )
    mRateOfFireOverride = UFG::SimObjectWeaponPropertiesComponent::DetermineRateOfFire(
                            (UFG::SimObjectWeaponPropertiesComponent *)this->mSimObjectWeaponPropertiesComponent.m_pSimComponent,
                            bIsAI);
  return v4 >= mRateOfFireOverride;
}

// File Line: 280
// RVA: 0x5356A0
bool __fastcall UFG::GunComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentGun,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 286
// RVA: 0x544FE0
UFG::GunComponent *__fastcall UFG::GunComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x138ui64, "GunComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = sceneObject->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = sceneObject->mpConstProperties;
    UFG::GunComponent::GunComponent((UFG::GunComponent *)v3, sceneObject->m_NameUID, mpWritableProperties, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, sceneObject->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return (UFG::GunComponent *)v6;
}

// File Line: 296
// RVA: 0x53DDE0
void __fastcall UFG::GunComponent::OnAttach(UFG::GunComponent *this, UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0> *p_mSimObjectWeaponPropertiesComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *p_mInventoryItemComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax

  p_mSimObjectWeaponPropertiesComponent = &this->mSimObjectWeaponPropertiesComponent;
  if ( p_mSimObjectWeaponPropertiesComponent->m_pSimComponent )
  {
    mPrev = p_mSimObjectWeaponPropertiesComponent->mPrev;
    mNext = p_mSimObjectWeaponPropertiesComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mSimObjectWeaponPropertiesComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_mSimObjectWeaponPropertiesComponent->m_pSimObject = 0i64;
    p_mSimObjectWeaponPropertiesComponent->mNext = p_mSimObjectWeaponPropertiesComponent;
    p_mSimObjectWeaponPropertiesComponent->mPrev = p_mSimObjectWeaponPropertiesComponent;
    goto LABEL_8;
  }
  if ( p_mSimObjectWeaponPropertiesComponent->m_pSimObject
    && (p_mSimObjectWeaponPropertiesComponent->mPrev != p_mSimObjectWeaponPropertiesComponent
     || p_mSimObjectWeaponPropertiesComponent->mNext != p_mSimObjectWeaponPropertiesComponent) )
  {
    v7 = p_mSimObjectWeaponPropertiesComponent->mPrev;
    v8 = p_mSimObjectWeaponPropertiesComponent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_mSimObjectWeaponPropertiesComponent->m_Changed = 1;
  p_mSimObjectWeaponPropertiesComponent->m_pSimObject = object;
  p_mSimObjectWeaponPropertiesComponent->m_TypeUID = UFG::SimObjectWeaponPropertiesComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0>::BindInternal<UFG::SimObject>(
    p_mSimObjectWeaponPropertiesComponent,
    object);
  p_mInventoryItemComponent = &this->mInventoryItemComponent;
  if ( this->mInventoryItemComponent.m_pSimComponent )
  {
    v10 = p_mInventoryItemComponent->mPrev;
    v11 = this->mInventoryItemComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->mInventoryItemComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mInventoryItemComponent.m_pSimObject = 0i64;
    this->mInventoryItemComponent.mNext = &this->mInventoryItemComponent;
    p_mInventoryItemComponent->mPrev = p_mInventoryItemComponent;
    goto LABEL_15;
  }
  if ( this->mInventoryItemComponent.m_pSimObject
    && (p_mInventoryItemComponent->mPrev != p_mInventoryItemComponent
     || this->mInventoryItemComponent.mNext != &this->mInventoryItemComponent) )
  {
    v12 = p_mInventoryItemComponent->mPrev;
    v13 = this->mInventoryItemComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->mInventoryItemComponent.m_Changed = 1;
  this->mInventoryItemComponent.m_pSimObject = object;
  this->mInventoryItemComponent.m_TypeUID = UFG::InventoryItemComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0>::BindInternal<UFG::SimObject>(
    &this->mInventoryItemComponent,
    object);
  UFG::GunComponent::Initialize(this);
}

// File Line: 305
// RVA: 0x5404A0
void __fastcall UFG::GunComponent::OnDetach(UFG::GunComponent *this)
{
  UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent,0> *p_mSimObjectWeaponPropertiesComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::InventoryItemComponent,0> *p_mInventoryItemComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax

  p_mSimObjectWeaponPropertiesComponent = &this->mSimObjectWeaponPropertiesComponent;
  if ( this->mSimObjectWeaponPropertiesComponent.m_pSimComponent )
  {
    mPrev = p_mSimObjectWeaponPropertiesComponent->mPrev;
    mNext = this->mSimObjectWeaponPropertiesComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mSimObjectWeaponPropertiesComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_mSimObjectWeaponPropertiesComponent->m_pSimObject = 0i64;
    p_mSimObjectWeaponPropertiesComponent->mNext = p_mSimObjectWeaponPropertiesComponent;
    p_mSimObjectWeaponPropertiesComponent->mPrev = p_mSimObjectWeaponPropertiesComponent;
    goto LABEL_8;
  }
  if ( this->mSimObjectWeaponPropertiesComponent.m_pSimObject
    && (p_mSimObjectWeaponPropertiesComponent->mPrev != p_mSimObjectWeaponPropertiesComponent
     || this->mSimObjectWeaponPropertiesComponent.mNext != &this->mSimObjectWeaponPropertiesComponent) )
  {
    v5 = p_mSimObjectWeaponPropertiesComponent->mPrev;
    v6 = p_mSimObjectWeaponPropertiesComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_mInventoryItemComponent = &this->mInventoryItemComponent;
  p_mSimObjectWeaponPropertiesComponent->m_Changed = 1;
  if ( this->mInventoryItemComponent.m_pSimComponent )
  {
    v8 = p_mInventoryItemComponent->mPrev;
    v9 = this->mInventoryItemComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->mInventoryItemComponent.m_pSimComponent = 0i64;
    this->mInventoryItemComponent.m_pSimObject = 0i64;
    this->mInventoryItemComponent.mNext = &this->mInventoryItemComponent;
    p_mInventoryItemComponent->mPrev = p_mInventoryItemComponent;
    this->mInventoryItemComponent.m_Changed = 1;
  }
  else
  {
    if ( this->mInventoryItemComponent.m_pSimObject
      && (p_mInventoryItemComponent->mPrev != p_mInventoryItemComponent
       || this->mInventoryItemComponent.mNext != &this->mInventoryItemComponent) )
    {
      v10 = p_mInventoryItemComponent->mPrev;
      v11 = this->mInventoryItemComponent.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      this->mInventoryItemComponent.m_pSimObject = 0i64;
      this->mInventoryItemComponent.mNext = &this->mInventoryItemComponent;
      p_mInventoryItemComponent->mPrev = p_mInventoryItemComponent;
    }
    this->mInventoryItemComponent.m_Changed = 1;
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
char __fastcall UFG::GunComponent::Shoot(
        UFG::GunComponent *this,
        UFG::SimObjectCharacter *pWeaponOwnerSimObject,
        UFG::AimingBaseComponent *pAimingC,
        unsigned int shootFlags,
        UFG::SubTargetingLocation *pSubTargetingLocation,
        UFG::SimObject *pShootOriginSimObject,
        UFG::qSymbolUC *originBoneId)
{
  UFG::SimObjectProp *m_pSimObject; // rcx
  __int16 m_Flags; // r10
  UFG::SimObjectCharacter *v13; // rdi
  UFG::CharacterAnimationComponent *m_pComponent; // rcx
  unsigned int m_TypeUID; // edx
  unsigned int v16; // edx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rsi
  UFG::CopSystem *v21; // rax
  UFG::SimComponent *m_pSimComponent; // r9
  int v23; // r8d
  int v24; // eax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pShootOriginSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pWeaponOwnerSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  float mRateOfFireOverride; // xmm2_4
  float mSimTimeMSec_low; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  __int64 v37; // rcx
  UFG::SimObject *v38; // rbx
  UFG::GunshotManager *Instance; // rax

  m_pSimObject = (UFG::SimObjectProp *)this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_Flags = m_pSimObject->m_Flags;
  v13 = 0i64;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_6;
    m_TypeUID = m_pComponent->m_TypeUID;
    if ( ((m_TypeUID ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_6;
    v16 = m_pComponent->m_TypeUID;
    if ( ((v16 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_6;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v16 & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
LABEL_23:
    m_pComponent = ComponentOfType;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x1000) == 0 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pSimObject,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  mComponentTableEntryCount = m_pSimObject->mComponentTableEntryCount;
  size = m_pSimObject->m_Components.size;
  if ( mComponentTableEntryCount >= size )
  {
LABEL_6:
    m_pComponent = 0i64;
    goto LABEL_24;
  }
  p = m_pSimObject->m_Components.p;
  while ( (p[mComponentTableEntryCount].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~p[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) != 0 )
  {
    if ( ++mComponentTableEntryCount >= size )
      goto LABEL_6;
  }
  m_pComponent = (UFG::CharacterAnimationComponent *)p[mComponentTableEntryCount].m_pComponent;
LABEL_24:
  if ( !m_pComponent
    || !this->mClipAmmo[HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject)] )
  {
    return 0;
  }
  if ( (shootFlags & 1) != 0 )
  {
    v21 = UFG::CopSystem::Instance();
    v21->vfptr[97].__vecDelDtor(v21, (unsigned int)pWeaponOwnerSimObject);
    m_pSimComponent = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
    v23 = *(_DWORD *)(*((_QWORD *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                      + HIDWORD(m_pSimComponent[2].m_pSimObject))
                    + 8i64);
    v24 = -10;
    if ( this->mClipAmmo[HIDWORD(m_pSimComponent[2].m_pSimObject)] - 1 > -10 )
      v24 = this->mClipAmmo[HIDWORD(m_pSimComponent[2].m_pSimObject)] - 1;
    if ( v24 < v23 )
      v23 = v24;
    this->mClipAmmo[HIDWORD(m_pSimComponent[2].m_pSimObject)] = v23;
  }
  this->mShootParams.shootFlags = shootFlags;
  p_pShootOriginSimObject = &this->mShootParams.pShootOriginSimObject;
  if ( this->mShootParams.pShootOriginSimObject.m_pPointer )
  {
    mPrev = p_pShootOriginSimObject->mPrev;
    mNext = this->mShootParams.pShootOriginSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_pShootOriginSimObject->mPrev = p_pShootOriginSimObject;
    this->mShootParams.pShootOriginSimObject.mNext = &this->mShootParams.pShootOriginSimObject;
  }
  this->mShootParams.pShootOriginSimObject.m_pPointer = pShootOriginSimObject;
  if ( pShootOriginSimObject )
  {
    v28 = pShootOriginSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v28->mNext = p_pShootOriginSimObject;
    p_pShootOriginSimObject->mPrev = v28;
    this->mShootParams.pShootOriginSimObject.mNext = &pShootOriginSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pShootOriginSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_pShootOriginSimObject;
  }
  this->mShootParams.shootBoneId = (UFG::qSymbolUC)originBoneId->mUID;
  p_pWeaponOwnerSimObject = &this->mShootParams.pWeaponOwnerSimObject;
  if ( this->mShootParams.pWeaponOwnerSimObject.m_pPointer )
  {
    v30 = p_pWeaponOwnerSimObject->mPrev;
    v31 = this->mShootParams.pWeaponOwnerSimObject.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    p_pWeaponOwnerSimObject->mPrev = p_pWeaponOwnerSimObject;
    this->mShootParams.pWeaponOwnerSimObject.mNext = &this->mShootParams.pWeaponOwnerSimObject;
  }
  this->mShootParams.pWeaponOwnerSimObject.m_pPointer = pWeaponOwnerSimObject;
  if ( pWeaponOwnerSimObject )
  {
    v32 = pWeaponOwnerSimObject->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v32->mNext = p_pWeaponOwnerSimObject;
    p_pWeaponOwnerSimObject->mPrev = v32;
    this->mShootParams.pWeaponOwnerSimObject.mNext = &pWeaponOwnerSimObject->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pWeaponOwnerSimObject->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_pWeaponOwnerSimObject;
  }
  this->mShootParams.pSubTargetingLocation = pSubTargetingLocation;
  this->mShootParams.pAimingC = pAimingC;
  mRateOfFireOverride = this->mRateOfFireOverride;
  if ( mRateOfFireOverride == -1.0 )
    mRateOfFireOverride = UFG::SimObjectWeaponPropertiesComponent::DetermineRateOfFire(
                            (UFG::SimObjectWeaponPropertiesComponent *)this->mSimObjectWeaponPropertiesComponent.m_pSimComponent,
                            pWeaponOwnerSimObject != LocalPlayer);
  mSimTimeMSec_low = (float)SLODWORD(UFG::Metrics::msInstance.mSimTimeMSec);
  if ( (UFG::Metrics::msInstance.mSimTimeMSec & 0x8000000000000000ui64) != 0i64 )
    mSimTimeMSec_low = mSimTimeMSec_low + 1.8446744e19;
  v35 = mSimTimeMSec_low * 0.001;
  v36 = (float)(v35 - this->mLastFiredTime) - mRateOfFireOverride;
  if ( !*(_BYTE *)(*((_QWORD *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                   + HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                 + 117i64)
    || v36 > mRateOfFireOverride )
  {
    v36 = 0.0;
  }
  this->mLastFiredTime = v35 - v36;
  v37 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
  if ( v37 )
    v13 = *(UFG::SimObjectCharacter **)(v37 + 40);
  if ( v13 == LocalPlayer )
    UFG::GameStatAction::Weapon::Discharge(this);
  if ( (_S25_0 & 1) == 0 )
  {
    _S25_0 |= 1u;
    play_gunshot.mUID = UFG::qWiseSymbolUIDFromString("play_gunshot", 0x811C9DC5);
    _((AMD_HD3D *)play_gunshot.mUID);
    atexit(UFG::GunComponent::Shoot_::_11_::_dynamic_atexit_destructor_for__play_gunshot__);
  }
  v38 = this->m_pSimObject;
  Instance = UFG::GunshotManager::GetInstance();
  UFG::GunshotManager::RequestShotStart(Instance, play_gunshot.mUID, v38);
  return 1;
}

// File Line: 373
// RVA: 0x520940
void __fastcall UFG::GunComponent::AddClipOfAmmo(UFG::GunComponent *this)
{
  __int64 v1; // r8
  __int64 v2; // rax
  int v3; // edx

  v1 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
  if ( v1 )
  {
    v2 = *(int *)(*((_QWORD *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
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
  UFG::GunComponent *m_pSimComponent; // r10
  int v3; // eax
  UFG::InventoryItemComponent *v4; // r9

  m_pSimComponent = (UFG::GunComponent *)this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  v3 = -10;
  LODWORD(v4) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)&m_pSimComponent->mInventoryItemComponent.m_TypeUID
                                      + 8i64 * HIDWORD(m_pSimComponent->mInventoryItemComponent.mNext)
                                      + 8)
                          + 8i64);
  if ( count > -10 )
    v3 = count;
  if ( v3 < (int)v4 )
    LODWORD(v4) = v3;
  this->mClipAmmo[HIDWORD(m_pSimComponent->mInventoryItemComponent.mNext)] = (int)v4;
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

  v1 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
  if ( !v1 )
    return 0i64;
  v2 = *(int *)(*((_QWORD *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                + HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
              + 4i64);
  if ( *(_BYTE *)(v1 + 936) && (_DWORD)v2 == *(_DWORD *)(v1 + 928) )
    return 1i64;
  else
    return *(unsigned int *)(v1 + 4 * v2 + 92);
}

// File Line: 434
// RVA: 0x54F410
void __fastcall UFG::GunComponent::SetTotalAmmo(UFG::GunComponent *this, int count)
{
  __int64 v3; // r9
  UFG::SimComponent *m_pSimComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rax
  __int64 v6; // r10
  __int64 v7; // rcx
  int v8; // eax
  int v9; // edx

  v3 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
  if ( v3 )
  {
    m_pSimComponent = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
    mPrev = m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    v6 = *(int *)(*((_QWORD *)&mPrev->mNext + HIDWORD(m_pSimComponent[2].m_pSimObject)) + 4i64);
    v7 = *((_QWORD *)&mPrev->mNext + HIDWORD(m_pSimComponent[2].m_pSimObject));
    v8 = 0;
    v9 = *(_DWORD *)(v7 + 12);
    if ( count > 0 )
      v8 = count;
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
  UFG::SimComponent *m_pSimComponent; // r9
  __int64 v3; // rax
  int v4; // r8d
  int v5; // r9d
  __m128 v6; // xmm1
  int v7; // ecx
  __int64 result; // rax

  v1 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
  if ( !v1 )
    return 0i64;
  m_pSimComponent = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  v3 = *(int *)(*((_QWORD *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                + HIDWORD(m_pSimComponent[2].m_pSimObject))
              + 4i64);
  if ( !*(_BYTE *)(v1 + 936) || (v4 = 1, (_DWORD)v3 != *(_DWORD *)(v1 + 928)) )
    v4 = *(_DWORD *)(v1 + 4 * v3 + 92);
  v5 = *(_DWORD *)(*((_QWORD *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                   + HIDWORD(m_pSimComponent[2].m_pSimObject))
                 + 8i64);
  v6 = (__m128)COERCE_UNSIGNED_INT((float)(v4 / v5));
  v7 = (int)v6.m128_f32[0];
  if ( (int)v6.m128_f32[0] != 0x80000000 && (float)v7 != v6.m128_f32[0] )
    v6.m128_f32[0] = (float)(v7 - (_mm_movemask_ps(_mm_unpacklo_ps(v6, v6)) & 1));
  result = (unsigned int)(int)v6.m128_f32[0];
  if ( v4 - (int)result * v5 > 0 )
    return (unsigned int)(result + 1);
  return result;
}

// File Line: 478
// RVA: 0x548CA0
void __fastcall UFG::GunComponent::Reload(UFG::GunComponent *this, int amount)
{
  __int64 v2; // r15
  UFG::SimComponent *m_pSimComponent; // rcx
  int v5; // r8d
  UFG::SimObjectCharacter *mParent; // rax
  bool v7; // di
  UFG::SimComponent *v8; // rdx
  char *v9; // r9
  int v10; // r8d
  int v11; // eax
  int v12; // edx

  m_pSimComponent = this->mInventoryItemComponent.m_pSimComponent;
  v5 = amount;
  mParent = *(UFG::SimObjectCharacter **)&m_pSimComponent[1].m_Flags;
  if ( mParent )
    mParent = (UFG::SimObjectCharacter *)mParent->mNode.mParent;
  v7 = mParent == LocalPlayer;
  if ( m_pSimComponent && mParent == LocalPlayer )
  {
    UFG::GunComponent::ReloadFromInventory(this, amount, v2);
  }
  else
  {
    if ( amount < 0 )
      v5 = *(_DWORD *)(*((_QWORD *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                       + HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject))
                     + 8i64);
    v8 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
    v9 = (char *)this + 4 * HIDWORD(v8[2].m_pSimObject);
    v10 = *((_DWORD *)v9 + 53) + v5;
    v11 = -10;
    v12 = *(_DWORD *)(*((_QWORD *)&v8[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v8[2].m_pSimObject)) + 8i64);
    if ( v10 > -10 )
      v11 = v10;
    if ( v11 < v12 )
      v12 = v11;
    *((_DWORD *)v9 + 53) = v12;
  }
  if ( v7 )
    UFG::GameStatAction::Weapon::Reload(this);
}

// File Line: 498
// RVA: 0x548D70
void __fastcall UFG::GunComponent::ReloadFromInventory(UFG::GunComponent *this, int amount)
{
  __int64 v2; // r15
  UFG::SimComponent *m_pSimComponent; // r8
  UFG::SimComponent *v4; // rax
  UFG::InventoryComponent *v5; // r10
  __int64 m_pSimObject_high; // rax
  UFG::eInventoryItemEnum v7; // r11d
  UFG::SimComponent *v8; // rax
  __int64 v9; // rbx
  int v10; // r8d

  m_pSimComponent = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v4 = this->mInventoryItemComponent.m_pSimComponent;
    if ( v4 )
    {
      v5 = *(UFG::InventoryComponent **)&v4[1].m_Flags;
      if ( v5 )
      {
        m_pSimObject_high = HIDWORD(m_pSimComponent[2].m_pSimObject);
        v7 = *(_DWORD *)(*((_QWORD *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext + m_pSimObject_high)
                       + 4i64);
        if ( this->mClipAmmo[m_pSimObject_high] < 0 )
          this->mClipAmmo[m_pSimObject_high] = 0;
        v8 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
        v9 = HIDWORD(v8[2].m_pSimObject);
        v10 = *(_DWORD *)(*((_QWORD *)&v8[2].m_BoundComponentHandles.mNode.mPrev->mNext + v9) + 8i64)
            - this->mClipAmmo[v9];
        if ( amount > 0 )
          v10 = amount;
        this->mClipAmmo[HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject)] = this->mClipAmmo[v9] + UFG::InventoryComponent::RemoveQuantity(v5, v7, v10, v2);
      }
    }
  }
}

// File Line: 526
// RVA: 0x54BC40
void __fastcall UFG::GunComponent::SetAmmoForAIDeath(UFG::GunComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::SimComponent *v3; // rcx
  unsigned int v4; // ebp
  __int64 v5; // rcx
  UFG::SimObjectCharacter *v6; // rcx
  UFG::SimComponent *v7; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rax
  __int64 m_pSimObject_high; // rsi
  int v10; // edi

  if ( this->mIfResetAmmoOnDeath )
  {
    m_pSimComponent = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
    if ( m_pSimComponent )
    {
      v3 = this->mInventoryItemComponent.m_pSimComponent;
      v4 = 0;
      if ( !v3
        || ((v5 = *(_QWORD *)&v3[1].m_Flags) == 0 ? (v6 = 0i64) : (v6 = *(UFG::SimObjectCharacter **)(v5 + 40)),
            v6 != LocalPlayer) )
      {
        if ( HIDWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mPrev) )
        {
          v7 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
          do
          {
            mPrev = v7[2].m_BoundComponentHandles.mNode.mPrev;
            m_pSimObject_high = HIDWORD(v7[2].m_pSimObject);
            v10 = *(_DWORD *)(*((_QWORD *)&mPrev->mNext + m_pSimObject_high) + 208i64);
            ++v4;
            this->mClipAmmo[m_pSimObject_high] = v10
                                               + UFG::qRandom(
                                                   *(_DWORD *)(*((_QWORD *)&mPrev->mNext + m_pSimObject_high) + 204i64)
                                                 - v10,
                                                   (unsigned int *)&UFG::qDefaultSeed);
            v7 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
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
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v5; // rbx
  unsigned int v6; // esi
  __int64 v7; // rbp
  int *mClipAmmo; // rdi
  __int64 v9; // r8
  char v10; // cl
  __int64 v11; // rdx
  int v12; // eax
  int v13; // r8d
  int v14; // eax
  UFG::SimComponent *v15; // r8
  int v16; // edx

  m_pSimComponent = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( pFromGC )
    {
      v5 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
      if ( v5 )
      {
        v6 = 0;
        if ( HIDWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mPrev) )
        {
          v7 = 0i64;
          mClipAmmo = pFromGC->mClipAmmo;
          do
          {
            v9 = *(__int64 *)((char *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext
                            + v7);
            v10 = *(_BYTE *)(v5 + 936);
            v11 = *(int *)(v9 + 4);
            if ( !v10 || (v12 = 1, (_DWORD)v11 != *(_DWORD *)(v5 + 928)) )
              v12 = *(_DWORD *)(v5 + 4 * v11 + 92);
            if ( v12 < *(_DWORD *)(v9 + 12) )
            {
              v13 = *mClipAmmo;
              if ( *mClipAmmo > 0 )
              {
                if ( !v10 || (v14 = 1, (_DWORD)v11 != *(_DWORD *)(v5 + 928)) )
                  v14 = *(_DWORD *)(v5 + 4 * v11 + 92);
                if ( UFG::InventoryComponent::ms_InventoryItemInfos[v11].m_iCapacity - v14 < v13 )
                  v13 = UFG::InventoryComponent::ms_InventoryItemInfos[v11].m_iCapacity - v14;
                UFG::InventoryComponent::AddQuantity((UFG::InventoryComponent *)v5, (UFG::eInventoryItemEnum)v11, v13);
                v15 = pFromGC->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
                v16 = *(_DWORD *)(*((_QWORD *)&v15[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                  + HIDWORD(v15[2].m_pSimObject))
                                + 8i64);
                if ( v16 > 0 )
                  v16 = 0;
                pFromGC->mClipAmmo[HIDWORD(v15[2].m_pSimObject)] = v16;
                UFG::GunComponent::PlayReloadSFX(this);
              }
            }
            ++v6;
            ++mClipAmmo;
            v7 += 8i64;
          }
          while ( v6 < HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mPrev) );
        }
      }
    }
  }
}

// File Line: 572
// RVA: 0x5427C0
void __fastcall UFG::GunComponent::PlayReloadSFX(UFG::GunComponent *this)
{
  if ( (_S26_1 & 1) == 0 )
  {
    _S26_1 |= 1u;
    UFG::qWiseSymbol::create_from_string(&play_ui_ammo, "play_ui_ammo");
    atexit(UFG::GunComponent::PlayReloadSFX_::_2_::_dynamic_atexit_destructor_for__play_ui_ammo__);
  }
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, play_ui_ammo.mUID, 0i64, 0, 0i64);
}

// File Line: 578
// RVA: 0x522C50
bool __fastcall UFG::GunComponent::CanReload(UFG::GunComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // r9
  UFG::SimComponent *v2; // r10
  UFG::SimObjectCharacter *mParent; // rax
  __int64 v4; // rax
  __int64 v5; // rcx

  m_pSimComponent = this->mInventoryItemComponent.m_pSimComponent;
  if ( !m_pSimComponent )
    return 1;
  v2 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  if ( *(_DWORD *)(*((_QWORD *)&v2[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v2[2].m_pSimObject)) + 8i64) <= this->mClipAmmo[HIDWORD(v2[2].m_pSimObject)] )
    return 0;
  mParent = *(UFG::SimObjectCharacter **)&m_pSimComponent[1].m_Flags;
  if ( mParent )
    mParent = (UFG::SimObjectCharacter *)mParent->mNode.mParent;
  if ( mParent != LocalPlayer )
    return 1;
  v4 = *(int *)(*((_QWORD *)&v2[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v2[2].m_pSimObject)) + 4i64);
  v5 = *(_QWORD *)&m_pSimComponent[1].m_Flags;
  if ( *(_BYTE *)(v5 + 936) )
  {
    if ( (_DWORD)v4 == *(_DWORD *)(v5 + 928) )
      return 1;
  }
  return *(int *)(v5 + 4 * v4 + 92) > 0;
}

// File Line: 609
// RVA: 0x539340
void __fastcall UFG::GunComponent::InitializeGunIntoInventory(UFG::GunComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  __int64 v3; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  __int64 i; // rsi
  char *v6; // r10
  __int64 v7; // rax
  int v8; // r8d
  UFG::InventoryItemInfo *v9; // rcx
  __int64 m_iCapacity; // r9
  int mNext; // edx
  int v12; // r8d
  int v13; // edx
  UFG::SimComponent *v14; // rax

  m_pSimComponent = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  v3 = 0i64;
  mPrev = m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
  if ( HIDWORD(mPrev->mPrev) )
  {
    for ( i = 0i64; ; i += 8i64 )
    {
      v6 = (char *)this + 4 * v3;
      v7 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
      v8 = *((_DWORD *)v6 + 53);
      if ( !v7 )
        goto LABEL_16;
      v9 = *(UFG::InventoryItemInfo **)((char *)&mPrev->mNext + i);
      m_iCapacity = v9[1].m_iCapacity;
      UFG::InventoryComponent::ms_InventoryItemInfos[m_iCapacity] = v9[3];
      mNext = (int)(*(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)((char *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext + i))->mNext;
      if ( v8 <= mNext )
        goto LABEL_16;
      v12 = v8 - mNext;
      *((_DWORD *)v6 + 53) = mNext;
      v13 = UFG::InventoryComponent::ms_InventoryItemInfos[m_iCapacity].m_iCapacity;
      if ( v12 <= v13 )
      {
        *(_DWORD *)(v7 + 4 * m_iCapacity + 92) = v12;
        if ( *(UFG::SimObjectCharacter **)(v7 + 40) == LocalPlayer )
        {
          if ( *(_BYTE *)(v7 + 936) && (_DWORD)m_iCapacity == *(_DWORD *)(v7 + 928) )
            v12 = 1;
          v13 = v12;
          goto LABEL_15;
        }
      }
      else
      {
        *(_DWORD *)(v7 + 4 * m_iCapacity + 92) = v13;
        if ( *(UFG::SimObjectCharacter **)(v7 + 40) == LocalPlayer )
        {
          if ( *(_BYTE *)(v7 + 936) )
          {
            if ( (_DWORD)m_iCapacity == *(_DWORD *)(v7 + 928) )
              v13 = 1;
          }
LABEL_15:
          UFG::GameStatAction::Inventory::UpdateItem((UFG::eInventoryItemEnum)m_iCapacity, v13);
        }
      }
LABEL_16:
      v14 = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
      v3 = (unsigned int)(v3 + 1);
      mPrev = v14[2].m_BoundComponentHandles.mNode.mPrev;
      if ( (unsigned int)v3 >= HIDWORD(mPrev->mPrev) )
      {
        HIDWORD(v14[2].m_pSimObject) = 0;
        return;
      }
    }
  }
  HIDWORD(m_pSimComponent[2].m_pSimObject) = 0;
}

// File Line: 643
// RVA: 0x548FF0
void __fastcall UFG::GunComponent::RemoveGunFromInventory(UFG::GunComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  unsigned int v3; // edi
  __int64 v4; // rbp
  char *v5; // r14
  __int64 v6; // rax
  __int64 mPrev_high; // r8
  int v8; // ecx
  int v9; // esi
  int v10; // edx

  m_pSimComponent = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v3 = 0;
    if ( HIDWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mPrev) )
    {
      v4 = 0i64;
      do
      {
        v5 = (char *)this + 4 * v3;
        v6 = *(_QWORD *)&this->mInventoryItemComponent.m_pSimComponent[1].m_Flags;
        if ( v6 )
        {
          mPrev_high = SHIDWORD((*(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)((char *)&this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mNext + v4))->mPrev);
          if ( !*(_BYTE *)(v6 + 936) || (v8 = 1, (_DWORD)mPrev_high != *(_DWORD *)(v6 + 928)) )
            v8 = *(_DWORD *)(v6 + 4 * mPrev_high + 92);
          v9 = v8 + *((_DWORD *)v5 + 53);
          *(_DWORD *)(v6 + 4 * mPrev_high + 92) = 0;
          if ( *(UFG::SimObjectCharacter **)(v6 + 40) == LocalPlayer )
          {
            if ( !*(_BYTE *)(v6 + 936) || (v10 = 1, (_DWORD)mPrev_high != *(_DWORD *)(v6 + 928)) )
              v10 = 0;
            UFG::GameStatAction::Inventory::UpdateItem((UFG::eInventoryItemEnum)mPrev_high, v10);
          }
          *((_DWORD *)v5 + 53) = v9;
        }
        ++v3;
        v4 += 8i64;
      }
      while ( v3 < HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev->mPrev) );
    }
    HIDWORD(this->mSimObjectWeaponPropertiesComponent.m_pSimComponent[2].m_pSimObject) = 0;
  }
}

