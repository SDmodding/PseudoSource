// File Line: 74
// RVA: 0x1514450
__int64 dynamic_initializer_for__UFG::BulletManager::smSettingsHandles__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BulletManager::smSettingsHandles__);
}

// File Line: 76
// RVA: 0x1513C60
__int64 dynamic_initializer_for__UFG::Bullet::mAllocator__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::Bullet::mAllocator);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Bullet::mAllocator__);
}

// File Line: 86
// RVA: 0x1519CB0
__int64 UFG::_dynamic_initializer_for__bulletNameHash__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bullet", -1);
  UFG::bulletNameHash = result;
  return result;
}

// File Line: 87
// RVA: 0x1519CF0
__int64 UFG::_dynamic_initializer_for__gBulletImpactDamageSphereEventChannel__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gBulletImpactDamageSphereEventChannel,
    "BulletImpactDamageSphereEvent",
    "A damage sphere has been hit by a bullet.");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gBulletImpactDamageSphereEventChannel__);
}

// File Line: 111
// RVA: 0x468E00
void UFG::BulletManager::Initialize(void)
{
  unsigned int v0; // ebx
  UFG::allocator::free_link *v1; // rax
  UFG::BulletManager *v2; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v4; // r15
  unsigned int mNumElements; // edi
  unsigned int size; // ecx
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax
  Render::BeamSettingsHandle **v9; // rsi
  Render::BeamSettingsHandle **p; // r9
  unsigned int i; // r8d
  unsigned int v12; // r14d
  __int64 v13; // rsi
  UFG::allocator::free_link *v14; // rax
  Render::BeamSettingsHandle *v15; // rbx
  UFG::qSymbolUC *v16; // rax
  unsigned int mUID; // ebp
  Render::BeamSettingsHandle **v18; // rax
  Render::BeamSettingsHandle *v19; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qResourceHandle *v22; // rbx
  UFG::qResourceInventory *v23; // rax
  UFG::qResourceWarehouse *v24; // rax
  UFG::qSymbol result; // [rsp+70h] [rbp+8h] BYREF
  UFG::allocator::free_link *v26; // [rsp+78h] [rbp+10h]

  v0 = 1;
  if ( !UFG::BulletManager::mInstance )
  {
    v1 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x38ui64, "BulletManager", 0i64, 1u);
    v26 = v1;
    if ( v1 )
      UFG::BulletManager::BulletManager((UFG::BulletManager *)v1);
    else
      v2 = 0i64;
    UFG::BulletManager::mInstance = v2;
  }
  UFG::qSymbol::create_from_string(&result, "config-BulletManager");
  PropertySet = UFG::PropertySetManager::GetPropertySet(&result);
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&PhysicsSym_Tracers,
         DEPTH_RECURSE);
  mNumElements = v4->mNumElements;
  size = UFG::BulletManager::smSettingsHandles.size;
  if ( !UFG::BulletManager::smSettingsHandles.size )
  {
    if ( (int)mNumElements <= 0 )
    {
      if ( mNumElements )
        size = 0;
      UFG::BulletManager::smSettingsHandles.size = size;
    }
    else
    {
      if ( mNumElements > UFG::BulletManager::smSettingsHandles.capacity )
      {
        if ( UFG::BulletManager::smSettingsHandles.capacity )
          v0 = 2 * UFG::BulletManager::smSettingsHandles.capacity;
        for ( ; v0 < mNumElements; v0 *= 2 )
          ;
        if ( v0 <= 2 )
          v0 = 2;
        if ( v0 - mNumElements > 0x10000 )
          v0 = mNumElements + 0x10000;
        if ( v0 )
        {
          v7 = 8i64 * v0;
          if ( !is_mul_ok(v0, 8ui64) )
            v7 = -1i64;
          v8 = UFG::qMalloc(v7, "numTracers", 0i64);
          v9 = (Render::BeamSettingsHandle **)v8;
          p = UFG::BulletManager::smSettingsHandles.p;
          if ( UFG::BulletManager::smSettingsHandles.p )
          {
            for ( i = 0; i < UFG::BulletManager::smSettingsHandles.size; p = UFG::BulletManager::smSettingsHandles.p )
            {
              v8[i].mNext = (UFG::allocator::free_link *)p[i];
              ++i;
            }
            operator delete[](p);
          }
          UFG::BulletManager::smSettingsHandles.p = v9;
          UFG::BulletManager::smSettingsHandles.capacity = v0;
        }
      }
      UFG::BulletManager::smSettingsHandles.size = mNumElements;
    }
    v12 = 0;
    if ( mNumElements )
    {
      v13 = 0i64;
      do
      {
        v14 = UFG::qMalloc(0x20ui64, "BeamSettingsHandle", 0i64);
        v15 = (Render::BeamSettingsHandle *)v14;
        v26 = v14;
        if ( v14 )
          UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)v14);
        else
          v15 = 0i64;
        UFG::BulletManager::smSettingsHandles.p[v13] = v15;
        v16 = UFG::qPropertyList::Get<UFG::qSymbolUC>(v4, v12);
        if ( v16 )
          mUID = v16->mUID;
        else
          mUID = 0;
        v18 = UFG::BulletManager::smSettingsHandles.p;
        v19 = UFG::BulletManager::smSettingsHandles.p[v13];
        if ( v19->mData )
        {
          Inventory = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
          if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
          {
            v21 = UFG::qResourceWarehouse::Instance();
            Inventory = UFG::qResourceWarehouse::GetInventory(v21, 0xA0AAE10F);
            `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = Inventory;
          }
          UFG::qResourceHandle::Close(v19, Inventory);
          v18 = UFG::BulletManager::smSettingsHandles.p;
        }
        v22 = v18[v13];
        v23 = `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result;
        if ( !`UFG::qGetResourceInventory<Render::BeamSettings>::`2::result )
        {
          v24 = UFG::qResourceWarehouse::Instance();
          v23 = UFG::qResourceWarehouse::GetInventory(v24, 0xA0AAE10F);
          `UFG::qGetResourceInventory<Render::BeamSettings>::`2::result = v23;
        }
        UFG::qResourceHandle::Init(v22, 0xA0AAE10F, mUID, v23);
        ++v12;
        ++v13;
      }
      while ( v12 < mNumElements );
    }
  }
}

// File Line: 161
// RVA: 0x44CC90
void __fastcall UFG::ProjectileInfo::ProjectileInfo(
        UFG::ProjectileInfo *this,
        UFG::SimObjectWeaponPropertiesComponent *pSOWPC,
        UFG::SubTargetingLocation *pSubTargetingLocation,
        bool isFullyAccurate,
        bool isHardLocked)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax

  this->m_pSOWPC.mPrev = &this->m_pSOWPC;
  this->m_pSOWPC.mNext = &this->m_pSOWPC;
  this->m_pSOWPC.m_pPointer = 0i64;
  this->m_pSubTargetingLocation = pSubTargetingLocation;
  this->m_bIsFullyAccurate = isFullyAccurate;
  this->m_bIsHardLocked = isHardLocked;
  if ( this->m_pSOWPC.m_pPointer )
  {
    mPrev = this->m_pSOWPC.mPrev;
    mNext = this->m_pSOWPC.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pSOWPC.mPrev = &this->m_pSOWPC;
    this->m_pSOWPC.mNext = &this->m_pSOWPC;
  }
  this->m_pSOWPC.m_pPointer = pSOWPC;
  if ( pSOWPC )
  {
    v8 = pSOWPC->m_SafePointerList.mNode.UFG::SimObjectPropertiesComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v8->mNext = &this->m_pSOWPC;
    this->m_pSOWPC.mPrev = v8;
    this->m_pSOWPC.mNext = &pSOWPC->m_SafePointerList.mNode;
    pSOWPC->m_SafePointerList.mNode.UFG::SimObjectPropertiesComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = &this->m_pSOWPC;
  }
}

// File Line: 205
// RVA: 0x448500
void __fastcall UFG::Bullet::Bullet(
        UFG::Bullet *this,
        UFG::SimObject *pWeaponOwnerSimObject,
        UFG::qVector3 *p,
        UFG::qVector3 *v,
        float projectileGravity,
        float armingDistance,
        bool posIsObscured,
        UFG::qVector3 *unobscuredPos,
        UFG::qColour *tracerColour,
        UFG::qColour *tracerTrailColour,
        Render::BeamSettingsHandle *in_tracerSettingsHandle,
        Render::BeamSettingsHandle *in_tracerTrailSettingsHandle,
        UFG::ProjectileInfo *pi,
        bool isNetworkProxy_,
        bool showTracer_,
        UFG::eTargetTypeEnum eMustHitTarget)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_weaponOwnerSimObject; // r10
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mustHitSimObject; // rdi
  UFG::ProjectileInfo *p_projectileInfo; // rdx
  UFG::SimComponent *m_pPointer; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  __m128 y_low; // xmm1
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::SimObjectGame *v36; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v40; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v43; // rax
  UFG::SimObjectWeaponPropertiesComponent *v44; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v46; // rdi
  unsigned int v47; // eax
  UFG::TransformNodeComponent *v48; // rax
  UFG::TransformNodeComponent *v49; // r8

  this->mPrev = this;
  this->mNext = this;
  p_weaponOwnerSimObject = &this->weaponOwnerSimObject;
  this->weaponOwnerSimObject.mPrev = &this->weaponOwnerSimObject;
  this->weaponOwnerSimObject.mNext = &this->weaponOwnerSimObject;
  this->weaponOwnerSimObject.m_pPointer = 0i64;
  p_mustHitSimObject = &this->mustHitSimObject;
  this->mustHitSimObject.mPrev = &this->mustHitSimObject;
  this->mustHitSimObject.mNext = &this->mustHitSimObject;
  this->mustHitSimObject.m_pPointer = 0i64;
  p_projectileInfo = &this->projectileInfo;
  this->projectileInfo.m_pSOWPC.mPrev = &this->projectileInfo.m_pSOWPC;
  this->projectileInfo.m_pSOWPC.mNext = &this->projectileInfo.m_pSOWPC;
  m_pPointer = pi->m_pSOWPC.m_pPointer;
  p_projectileInfo->m_pSOWPC.m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    p_mNode = &m_pPointer->m_SafePointerList.mNode;
    mPrev = p_mNode->mPrev;
    mPrev->mNext = &p_projectileInfo->m_pSOWPC;
    p_projectileInfo->m_pSOWPC.mPrev = mPrev;
    p_projectileInfo->m_pSOWPC.mNext = p_mNode;
    p_mNode->mPrev = &p_projectileInfo->m_pSOWPC;
  }
  p_projectileInfo->m_pSubTargetingLocation = pi->m_pSubTargetingLocation;
  p_projectileInfo->m_bIsFullyAccurate = pi->m_bIsFullyAccurate;
  p_projectileInfo->m_bIsHardLocked = pi->m_bIsHardLocked;
  this->oneShot.m_pOneShot = 0i64;
  this->transformNodeComponent = 0i64;
  this->tracerSettingsHandle = in_tracerSettingsHandle;
  this->tracerTrailSettingsHandle = in_tracerTrailSettingsHandle;
  y = p->y;
  z = p->z;
  this->pos_t0.x = p->x;
  this->pos_t0.y = y;
  this->pos_t0.z = z;
  v26 = p->y;
  v27 = p->z;
  this->pos_t1.x = p->x;
  this->pos_t1.y = v26;
  this->pos_t1.z = v27;
  v28 = p->y;
  v29 = p->z;
  this->pos_launch.x = p->x;
  this->pos_launch.y = v28;
  this->pos_launch.z = v29;
  v30 = v->y;
  v31 = v->z;
  this->vel.x = v->x;
  this->vel.y = v30;
  this->vel.z = v31;
  this->tracerColour = *tracerColour;
  this->tracerTrailColour = *tracerTrailColour;
  this->mProjectileGravity = projectileGravity;
  this->mArmingDistance = armingDistance;
  this->mDistanceTraveled = 0.0;
  this->age = 0.0;
  this->grenadeEffectID = 0;
  this->mustHitTarget = eMustHitTarget;
  *((_BYTE *)this + 248) &= 0xE0u;
  *((_BYTE *)this + 248) |= 2 * (isNetworkProxy_ | (2 * (showTracer_ | 8)));
  if ( posIsObscured )
  {
    y_low = (__m128)LODWORD(unobscuredPos->y);
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - p->y) * (float)(y_low.m128_f32[0] - p->y))
                              + (float)((float)(unobscuredPos->x - p->x) * (float)(unobscuredPos->x - p->x)))
                      + (float)((float)(unobscuredPos->z - p->z) * (float)(unobscuredPos->z - p->z));
    LODWORD(this->mObscuredLength) = _mm_sqrt_ps(y_low).m128_u32[0];
  }
  else
  {
    this->mObscuredLength = 0.0;
  }
  if ( p_weaponOwnerSimObject->m_pPointer )
  {
    v33 = p_weaponOwnerSimObject->mPrev;
    mNext = p_weaponOwnerSimObject->mNext;
    v33->mNext = mNext;
    mNext->mPrev = v33;
    p_weaponOwnerSimObject->mPrev = p_weaponOwnerSimObject;
    p_weaponOwnerSimObject->mNext = p_weaponOwnerSimObject;
  }
  p_weaponOwnerSimObject->m_pPointer = pWeaponOwnerSimObject;
  if ( pWeaponOwnerSimObject )
  {
    v35 = pWeaponOwnerSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v35->mNext = p_weaponOwnerSimObject;
    p_weaponOwnerSimObject->mPrev = v35;
    p_weaponOwnerSimObject->mNext = &pWeaponOwnerSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pWeaponOwnerSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_weaponOwnerSimObject;
  }
  this->mLifeSpan = *(float *)(*((_QWORD *)&pi->m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                               + HIDWORD(pi->m_pSOWPC.m_pPointer[2].m_pSimObject))
                             + 112i64);
  v36 = (UFG::SimObjectGame *)this->weaponOwnerSimObject.m_pPointer;
  if ( v36
    && ((m_Flags = v36->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                 v36,
                                 UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v36, UFG::TargetingSystemBaseComponent::_TypeUID)),
          m_pComponent = ComponentOfTypeHK)
       : (m_pComponent = v36->m_Components.p[20].m_pComponent))
      : (m_pComponent = v36->m_Components.p[20].m_pComponent),
        m_pComponent) )
  {
    v40 = *(UFG::SimObject **)(56i64
                             * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                  + (unsigned int)this->mustHitTarget
                                                  + 8i64)
                             + *(_QWORD *)&m_pComponent[1].m_TypeUID
                             + 40);
  }
  else
  {
    v40 = 0i64;
  }
  if ( p_mustHitSimObject->m_pPointer )
  {
    v41 = p_mustHitSimObject->mPrev;
    v42 = p_mustHitSimObject->mNext;
    v41->mNext = v42;
    v42->mPrev = v41;
    p_mustHitSimObject->mPrev = p_mustHitSimObject;
    p_mustHitSimObject->mNext = p_mustHitSimObject;
  }
  p_mustHitSimObject->m_pPointer = v40;
  if ( v40 )
  {
    v43 = v40->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v43->mNext = p_mustHitSimObject;
    p_mustHitSimObject->mPrev = v43;
    p_mustHitSimObject->mNext = &v40->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v40->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mustHitSimObject;
  }
  v44 = (UFG::SimObjectWeaponPropertiesComponent *)this->projectileInfo.m_pSOWPC.m_pPointer;
  if ( v44 && v44->mWeaponTypeInfo->mFireModes[v44->mFireMode]->mExplosionType.mUID != -1 )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v46 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
    if ( v46 )
    {
      v47 = UFG::qStringHash32("BulletTransform", 0xFFFFFFFF);
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v46, v47, 0i64, 0);
      v49 = v48;
    }
    else
    {
      v49 = 0i64;
    }
    this->transformNodeComponent = v49;
    this->grenadeEffectID = Render::FXManager::CreateEffect(
                              &Render::gFXManager,
                              *(_DWORD *)(*((_QWORD *)&pi->m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                          + HIDWORD(pi->m_pSOWPC.m_pPointer[2].m_pSimObject))
                                        + 0x7Ci64),
                              v49,
                              0xFFFFFFFF,
                              0i64);
  }
}

// File Line: 231
// RVA: 0x44F610
void __fastcall UFG::Bullet::~Bullet(UFG::Bullet *this)
{
  UFG::SimComponent *m_pPointer; // rax
  UFG::ProjectileInfo *p_projectileInfo; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mustHitSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_weaponOwnerSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v18; // rcx
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v19; // rax

  m_pPointer = this->projectileInfo.m_pSOWPC.m_pPointer;
  if ( m_pPointer
    && *(_DWORD *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                   + HIDWORD(m_pPointer[2].m_pSimObject))
                 + 108i64) != -1
    && this->transformNodeComponent )
  {
    UFG::Bullet::Explode(this);
  }
  if ( UFG::OneShotHandle::IsValid(&this->oneShot) )
    UFG::OneShot::Stop(this->oneShot.m_pOneShot, 0x32u, 0);
  UFG::OneShotHandle::Release(&this->oneShot);
  p_projectileInfo = &this->projectileInfo;
  if ( this->projectileInfo.m_pSOWPC.m_pPointer )
  {
    mPrev = p_projectileInfo->m_pSOWPC.mPrev;
    mNext = this->projectileInfo.m_pSOWPC.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_projectileInfo->m_pSOWPC.mPrev = &p_projectileInfo->m_pSOWPC;
    this->projectileInfo.m_pSOWPC.mNext = &this->projectileInfo.m_pSOWPC;
  }
  this->projectileInfo.m_pSOWPC.m_pPointer = 0i64;
  v6 = p_projectileInfo->m_pSOWPC.mPrev;
  v7 = this->projectileInfo.m_pSOWPC.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_projectileInfo->m_pSOWPC.mPrev = &p_projectileInfo->m_pSOWPC;
  this->projectileInfo.m_pSOWPC.mNext = &this->projectileInfo.m_pSOWPC;
  p_mustHitSimObject = &this->mustHitSimObject;
  if ( this->mustHitSimObject.m_pPointer )
  {
    v9 = p_mustHitSimObject->mPrev;
    v10 = this->mustHitSimObject.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    p_mustHitSimObject->mPrev = p_mustHitSimObject;
    this->mustHitSimObject.mNext = &this->mustHitSimObject;
  }
  this->mustHitSimObject.m_pPointer = 0i64;
  v11 = p_mustHitSimObject->mPrev;
  v12 = this->mustHitSimObject.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  p_mustHitSimObject->mPrev = p_mustHitSimObject;
  this->mustHitSimObject.mNext = &this->mustHitSimObject;
  p_weaponOwnerSimObject = &this->weaponOwnerSimObject;
  if ( this->weaponOwnerSimObject.m_pPointer )
  {
    v14 = p_weaponOwnerSimObject->mPrev;
    v15 = this->weaponOwnerSimObject.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    p_weaponOwnerSimObject->mPrev = p_weaponOwnerSimObject;
    this->weaponOwnerSimObject.mNext = &this->weaponOwnerSimObject;
  }
  this->weaponOwnerSimObject.m_pPointer = 0i64;
  v16 = p_weaponOwnerSimObject->mPrev;
  v17 = this->weaponOwnerSimObject.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  p_weaponOwnerSimObject->mPrev = p_weaponOwnerSimObject;
  this->weaponOwnerSimObject.mNext = &this->weaponOwnerSimObject;
  v18 = this->mPrev;
  v19 = this->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  this->mPrev = this;
  this->mNext = this;
}
  v

// File Line: 249
// RVA: 0x463E40
void __fastcall UFG::Bullet::Explode(UFG::Bullet *this)
{
  UFG::SimObjectWeaponPropertiesComponent *m_pPointer; // rbx
  UFG::SimObject *v3; // rsi
  UFG::TransformNodeComponent *transformNodeComponent; // rdi
  UFG::qSymbol *ExplosionType; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF

  if ( this->grenadeEffectID )
  {
    m_pPointer = (UFG::SimObjectWeaponPropertiesComponent *)this->projectileInfo.m_pSOWPC.m_pPointer;
    v3 = this->weaponOwnerSimObject.m_pPointer;
    transformNodeComponent = this->transformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(transformNodeComponent);
    ExplosionType = UFG::SimObjectWeaponPropertiesComponent::GetExplosionType(m_pPointer, &result);
    UFG::ExplosionManager::CreateExplosion(
      (UFG::qVector3 *)&transformNodeComponent->mWorldTransform.v3,
      ExplosionType,
      v3,
      v3);
    Render::FXManager::KillEffect(&Render::gFXManager, this->grenadeEffectID, FXKILLOPTION_DEFAULT);
    this->transformNodeComponent = 0i64;
    this->grenadeEffectID = 0;
  }
}

// File Line: 267
// RVA: 0x1519CD0
signed __int64 dynamic_initializer_for__bullet_by_uid__()
{
  signed __int64 result; // rax

  result = UFG::TiDo::CalcWwiseUid("play_bullet_by");
  bullet_by_uid = result;
  return result;
}

// File Line: 268
// RVA: 0x151A5C0
signed __int64 dynamic_initializer_for__weapon_type_uid__()
{
  signed __int64 result; // rax

  result = UFG::TiDo::CalcWwiseUid("weapon_type");
  weapon_type_uid = result;
  return result;
}

// File Line: 271
// RVA: 0x46FAF0
void __fastcall UFG::Bullet::PlayBulletBy(UFG::Bullet *this)
{
  UFG::SimComponent *m_pPointer; // rax

  UFG::OneShotPool::GetOneShotHandle(&this->oneShot, &this->pos_t0);
  if ( UFG::OneShotHandle::IsValid(&this->oneShot) )
  {
    m_pPointer = this->projectileInfo.m_pSOWPC.m_pPointer;
    if ( m_pPointer )
      UFG::AudioEntity::SetWwiseSwitch(
        this->oneShot.m_pOneShot,
        weapon_type_uid,
        *(_DWORD *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                    + HIDWORD(m_pPointer[2].m_pSimObject))
                  + 248i64));
    UFG::OneShot::Play(this->oneShot.m_pOneShot, bullet_by_uid);
  }
}

// File Line: 288
// RVA: 0x448A40
void __fastcall UFG::BulletManager::BulletManager(UFG::BulletManager *this)
{
  this->vfptr = (UFG::BulletManagerVtbl *)&UFG::BulletManager::`vftable;
  this->mTargetSpheres.mNode.mPrev = &this->mTargetSpheres.mNode;
  this->mTargetSpheres.mNode.mNext = &this->mTargetSpheres.mNode;
  this->mBulletList.mNode.mPrev = &this->mBulletList.mNode;
  this->mBulletList.mNode.mNext = &this->mBulletList.mNode;
  this->mSimObjectsToIgnore.p = 0i64;
  *(_QWORD *)&this->mSimObjectsToIgnore.size = 0i64;
  UFG::qFixedAllocator::Init(&UFG::Bullet::mAllocator, 25600, 256, "BulletPool", 0i64);
}

// File Line: 300
// RVA: 0x44F830
void __fastcall UFG::BulletManager::~BulletManager(UFG::BulletManager *this)
{
  UFG::qList<UFG::TargetSphere,UFG::TargetSphere,1,0> *p_mTargetSpheres; // r8
  UFG::BulletManager *mNext; // rax
  UFG::BulletManagerVtbl *vfptr; // rdx
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *mPrev; // rcx
  UFG::qList<UFG::Bullet,UFG::Bullet,1,0> *p_mBulletList; // rsi
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v8; // rbx
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v9; // rcx
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v10; // rax
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v11; // rcx
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v12; // rax

  this->vfptr = (UFG::BulletManagerVtbl *)&UFG::BulletManager::`vftable;
  p_mTargetSpheres = &UFG::BulletManager::mInstance->mTargetSpheres;
  mNext = (UFG::BulletManager *)UFG::BulletManager::mInstance->mTargetSpheres.mNode.mNext;
  if ( mNext != (UFG::BulletManager *)&UFG::BulletManager::mInstance->mTargetSpheres )
  {
    do
    {
      vfptr = mNext->vfptr;
      mPrev = mNext->mTargetSpheres.mNode.mPrev;
      vfptr[1].__vecDelDtor = (void *(__fastcall *)(UFG::BulletManager *, unsigned int))mPrev;
      mPrev->mPrev = (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)vfptr;
      mNext->vfptr = (UFG::BulletManagerVtbl *)mNext;
      mNext->mTargetSpheres.mNode.mPrev = (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)mNext;
      mNext = (UFG::BulletManager *)p_mTargetSpheres->mNode.mNext;
    }
    while ( mNext != (UFG::BulletManager *)p_mTargetSpheres );
  }
  p_mBulletList = &this->mBulletList;
  UFG::qList<UFG::Bullet,UFG::Bullet,1,0>::DeleteNodes(&this->mBulletList);
  UFG::qFixedAllocator::Close(&UFG::Bullet::mAllocator);
  p = this->mSimObjectsToIgnore.p;
  if ( p )
  {
    v8 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v8);
  }
  this->mSimObjectsToIgnore.p = 0i64;
  *(_QWORD *)&this->mSimObjectsToIgnore.size = 0i64;
  UFG::qList<UFG::Bullet,UFG::Bullet,1,0>::DeleteNodes(&this->mBulletList);
  v9 = p_mBulletList->mNode.mPrev;
  v10 = this->mBulletList.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mBulletList->mNode.mPrev = &p_mBulletList->mNode;
  this->mBulletList.mNode.mNext = &this->mBulletList.mNode;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mTargetSpheres);
  v11 = this->mTargetSpheres.mNode.mPrev;
  v12 = this->mTargetSpheres.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  this->mTargetSpheres.mNode.mPrev = &this->mTargetSpheres.mNode;
  this->mTargetSpheres.mNode.mNext = &this->mTargetSpheres.mNode;
}

// File Line: 327
// RVA: 0x4649A0
void __fastcall UFG::BulletManager::FireBullet(
        UFG::BulletManager *this,
        UFG::SimObjectCharacter *pWeaponOwnerSimObject,
        UFG::qVector3 *muzzleDir,
        UFG::qVector3 *pos,
        UFG::qVector3 *vel,
        float projectileGravity,
        float armingDistance,
        bool posIsObscured,
        UFG::qVector3 *unobscuredPos,
        UFG::ProjectileInfo *pi,
        bool showTracer,
        bool isNetworkProxy,
        UFG::eTargetTypeEnum eMustHitTarget)
{
  float y; // xmm1_4
  float z; // xmm0_4
  float x; // xmm10_4
  float v19; // xmm12_4
  float v20; // xmm11_4
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  float v23; // xmm5_4
  __m128 x_low; // xmm3
  float v25; // xmm4_4
  __m128 v26; // xmm2
  float v27; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm0_4
  bool showTracer_; // r13
  __int64 v32; // rbx
  Render::BeamSettingsHandle *in_tracerSettingsHandle; // r15
  Render::BeamSettingsHandle *in_tracerTrailSettingsHandle; // r14
  bool IsAnyLocalPlayer; // r14
  float *mData; // rsi
  float v37; // xmm0_4
  float v38; // xmm8_4
  float v39; // xmm7_4
  float v40; // xmm6_4
  __int64 v41; // rcx
  float *v42; // rsi
  float v43; // xmm0_4
  float v44; // xmm8_4
  float v45; // xmm7_4
  float v46; // xmm6_4
  char *mFreeListHead; // rsi
  unsigned int v48; // eax
  float v49; // xmm11_4
  float v50; // xmm12_4
  __int64 v51; // rax
  UFG::GameStatTracker *v52; // rax
  UFG::qNode<UFG::Bullet,UFG::Bullet> *mPrev; // rax
  UFG::qVector3 p; // [rsp+88h] [rbp-F0h] BYREF
  UFG::qVector3 v; // [rsp+98h] [rbp-E0h] BYREF
  UFG::qColour tracerTrailColour; // [rsp+A8h] [rbp-D0h] BYREF
  UFG::qColour tracerColour; // [rsp+B8h] [rbp-C0h] BYREF

  y = pos->y;
  z = pos->z;
  p.x = pos->x;
  p.y = y;
  p.z = z;
  x = UFG::qVector3::msZero.x;
  v19 = UFG::qVector3::msZero.y;
  v20 = UFG::qVector3::msZero.z;
  if ( pWeaponOwnerSimObject )
  {
    m_Flags = pWeaponOwnerSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = pWeaponOwnerSimObject->m_Components.p[44].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                       pWeaponOwnerSimObject,
                       UFG::CharacterOccupantComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(
                       pWeaponOwnerSimObject,
                       UFG::CharacterOccupantComponent::_TypeUID);
    if ( m_pComponent )
    {
      v23 = vel->y;
      x_low = (__m128)LODWORD(vel->x);
      v25 = vel->z;
      v26 = x_low;
      v26.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v23 * v23))
                      + (float)(v25 * v25);
      if ( v26.m128_f32[0] == 0.0 )
        v27 = 0.0;
      else
        v27 = 1.0 / _mm_sqrt_ps(v26).m128_f32[0];
      v28 = (float)((float)(v25 * v27) * s_fOriginOffset) + pos->z;
      v29 = (float)((float)(v23 * v27) * s_fOriginOffset) + pos->y;
      p.x = (float)((float)(x_low.m128_f32[0] * v27) * s_fOriginOffset) + pos->x;
      p.y = v29;
      p.z = v28;
    }
  }
  if ( (_S7_12 & 1) == 0 )
  {
    _S7_12 |= 1u;
    s_fMuzzleShotToleranceRad = FLOAT_0_78539819;
  }
  v30 = UFG::qAngleBetween(muzzleDir, vel);
  showTracer_ = showTracer && v30 <= s_fMuzzleShotToleranceRad;
  v32 = 0i64;
  in_tracerSettingsHandle = 0i64;
  in_tracerTrailSettingsHandle = 0i64;
  if ( showTracer_ && pi->m_pSOWPC.m_pPointer )
  {
    IsAnyLocalPlayer = UFG::IsAnyLocalPlayer(pWeaponOwnerSimObject);
    if ( IsAnyLocalPlayer )
      in_tracerSettingsHandle = *(Render::BeamSettingsHandle **)(*((_QWORD *)&pi->m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                                                 + HIDWORD(pi->m_pSOWPC.m_pPointer[2].m_pSimObject))
                                                               + 0xD8i64);
    else
      in_tracerSettingsHandle = *(Render::BeamSettingsHandle **)(*((_QWORD *)&pi->m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                                                 + HIDWORD(pi->m_pSOWPC.m_pPointer[2].m_pSimObject))
                                                               + 224i64);
    if ( in_tracerSettingsHandle )
    {
      mData = (float *)in_tracerSettingsHandle->mData;
      if ( mData )
      {
        v37 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
        v38 = (float)((float)(mData[29] - mData[25]) * v37) + mData[25];
        v39 = (float)((float)(mData[28] - mData[24]) * v37) + mData[24];
        v40 = (float)((float)(mData[27] - mData[23]) * v37) + mData[23];
        tracerColour.r = (float)((float)(mData[26] - mData[22]) * v37) + mData[22];
        tracerColour.g = v40;
        tracerColour.b = v39;
        tracerColour.a = v38;
      }
    }
    v41 = *((_QWORD *)&pi->m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
          + HIDWORD(pi->m_pSOWPC.m_pPointer[2].m_pSimObject));
    if ( IsAnyLocalPlayer )
      in_tracerTrailSettingsHandle = *(Render::BeamSettingsHandle **)(v41 + 232);
    else
      in_tracerTrailSettingsHandle = *(Render::BeamSettingsHandle **)(v41 + 240);
    if ( in_tracerTrailSettingsHandle )
    {
      v42 = (float *)in_tracerTrailSettingsHandle->mData;
      if ( v42 )
      {
        v43 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
        v44 = (float)((float)(v42[29] - v42[25]) * v43) + v42[25];
        v45 = (float)((float)(v42[28] - v42[24]) * v43) + v42[24];
        v46 = (float)((float)(v42[27] - v42[23]) * v43) + v42[23];
        tracerTrailColour.r = v42[22] + (float)((float)(v42[26] - v42[22]) * v43);
        tracerTrailColour.g = v46;
        tracerTrailColour.b = v45;
        tracerTrailColour.a = v44;
      }
    }
  }
  mFreeListHead = UFG::Bullet::mAllocator.mFreeListHead;
  if ( UFG::Bullet::mAllocator.mFreeListHead )
  {
    UFG::Bullet::mAllocator.mFreeListHead = *(char **)UFG::Bullet::mAllocator.mFreeListHead;
    v48 = UFG::Bullet::mAllocator.mNumSlotsAllocated + 1;
    UFG::Bullet::mAllocator.mNumSlotsAllocated = v48;
    if ( UFG::Bullet::mAllocator.mMostSlotsAllocated <= v48 )
      UFG::Bullet::mAllocator.mMostSlotsAllocated = v48;
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&UFG::Bullet::mAllocator);
  }
  if ( mFreeListHead )
  {
    v49 = v20 + vel->z;
    v50 = v19 + vel->y;
    v.x = x + vel->x;
    v.y = v50;
    v.z = v49;
    UFG::Bullet::Bullet(
      (UFG::Bullet *)mFreeListHead,
      pWeaponOwnerSimObject,
      &p,
      &v,
      projectileGravity,
      armingDistance,
      posIsObscured,
      unobscuredPos,
      &tracerColour,
      &tracerTrailColour,
      in_tracerSettingsHandle,
      in_tracerTrailSettingsHandle,
      pi,
      isNetworkProxy,
      showTracer_,
      eMustHitTarget);
    v32 = v51;
  }
  if ( v32 )
  {
    if ( UFG::IsAnyLocalPlayer(pWeaponOwnerSimObject) )
    {
      v52 = UFG::GameStatTracker::Instance();
      if ( UFG::GameStatTracker::GetStat(v52, Sharpshooter_Activated) > 0.0 )
        *(_BYTE *)(v32 + 248) |= 1u;
    }
    if ( !UFG::IsAnyLocalPlayer(pWeaponOwnerSimObject) )
      UFG::Bullet::PlayBulletBy((UFG::Bullet *)v32);
    mPrev = this->mBulletList.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)v32;
    *(_QWORD *)v32 = mPrev;
    *(_QWORD *)(v32 + 8) = &this->mBulletList;
    this->mBulletList.mNode.mPrev = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)v32;
  }
}

// File Line: 442
// RVA: 0x4701D0
void __fastcall UFG::BulletManager::PreRayCastUpdate(UFG::BulletManager *this, float deltaT)
{
  float *mNext; // rbx
  UFG::qList<UFG::Bullet,UFG::Bullet,1,0> *i; // rsi
  UFG::SimObjectGame *v5; // rcx
  __int16 m_Flags; // dx
  UFG::AimingBaseComponent *m_pComponent; // rax
  UFG::eTargetTypeEnum v8; // r8d
  __m128 v9; // xmm2
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  UFG::qVector3 *v16; // r8
  int v17; // xmm0_4
  int v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  float v24; // xmm6_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm5_4
  UFG::Bullet *v31; // rdi
  UFG::qVector3 vTargetNormalAimPosition; // [rsp+40h] [rbp-78h] BYREF
  float v33; // [rsp+50h] [rbp-68h] BYREF
  float v34; // [rsp+54h] [rbp-64h]
  float v35; // [rsp+58h] [rbp-60h]

  mNext = (float *)this->mBulletList.mNode.mNext;
  for ( i = &this->mBulletList; mNext != (float *)i; mNext = (float *)*((_QWORD *)mNext + 1) )
  {
    if ( *((_DWORD *)mNext + 61) )
    {
      v5 = (UFG::SimObjectGame *)*((_QWORD *)mNext + 4);
      if ( v5 )
      {
        m_Flags = v5->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
          m_pComponent = (UFG::AimingBaseComponent *)v5->m_Components.p[47].m_pComponent;
        else
          m_pComponent = (UFG::AimingBaseComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v5,
                                                        UFG::AimingBaseComponent::_TypeUID)
                                                    : UFG::SimObject::GetComponentOfType(
                                                        v5,
                                                        UFG::AimingBaseComponent::_TypeUID));
        if ( m_pComponent )
        {
          v8 = *((_DWORD *)mNext + 61);
          vTargetNormalAimPosition = UFG::qVector3::msZero;
          UFG::AimingBaseComponent::GetTargetNormalAimPosition(m_pComponent, &vTargetNormalAimPosition, v8, 0i64);
          v9 = (__m128)*((unsigned int *)mNext + 43);
          v10 = vTargetNormalAimPosition.z - mNext[39];
          v9.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(mNext[44] * mNext[44]))
                         + (float)(mNext[45] * mNext[45]);
          v11 = vTargetNormalAimPosition.y - mNext[38];
          mNext[43] = vTargetNormalAimPosition.x - mNext[37];
          mNext[44] = v11;
          mNext[45] = v10;
          v12 = _mm_sqrt_ps(v9).m128_f32[0];
          v13 = v12 * mNext[45];
          v14 = v12 * mNext[43];
          v15 = v12 * mNext[44];
          mNext[45] = v13;
          mNext[43] = v14;
          mNext[44] = v15;
        }
      }
    }
    else
    {
      mNext[45] = mNext[45] - (float)(deltaT * mNext[54]);
    }
    v16 = (UFG::qVector3 *)(mNext + 37);
    v17 = *((_DWORD *)mNext + 38);
    v18 = *((_DWORD *)mNext + 39);
    mNext[34] = mNext[37];
    *((_DWORD *)mNext + 36) = v18;
    *((_DWORD *)mNext + 35) = v17;
    v19 = (float)(deltaT * mNext[43]) + mNext[37];
    v20 = (float)(deltaT * mNext[44]) + mNext[38];
    v21 = (float)(deltaT * mNext[45]) + mNext[39];
    mNext[37] = v19;
    mNext[38] = v20;
    mNext[39] = v21;
    v23 = mNext[35];
    v24 = mNext[36];
    v33 = mNext[34];
    v22 = v33;
    v34 = v23;
    v35 = v24;
    v25 = fsqrt(
            (float)((float)((float)(v20 - v23) * (float)(v20 - v23)) + (float)((float)(v19 - v22) * (float)(v19 - v22)))
          + (float)((float)(v21 - v24) * (float)(v21 - v24)));
    v26 = mNext[59] - v25;
    mNext[59] = v26;
    if ( v26 <= 0.0
      && (v26 >= 0.0
       || (LODWORD(v27) = LODWORD(v26) & _xmm, v27 >= v25)
       || (v28 = 1.0 - (float)(v27 / v25),
           v29 = (float)(mNext[39] - v24) * v28,
           v30 = v23 + (float)((float)(mNext[38] - v23) * v28),
           v33 = v22 + (float)((float)(v16->x - v22) * v28),
           v34 = v30,
           v35 = v24 + v29,
           v28 < 1.0))
      || mNext[54] > 0.0 )
    {
      if ( !UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay(
              UFG::BasePhysicsSystem::mInstance,
              (UFG::qVector3 *)&v33,
              v16,
              0x19u,
              (void (__fastcall *)(UFG::RayCastData *, UFG::SimComponent *, void *))UFG::BulletManager::AsyncRayCallback,
              0i64,
              mNext) )
      {
        v31 = (UFG::Bullet *)mNext;
        mNext = *(float **)mNext;
        if ( v31 )
        {
          UFG::Bullet::~Bullet(v31);
          v31->mPrev = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)UFG::Bullet::mAllocator.mFreeListHead;
          --UFG::Bullet::mAllocator.mNumSlotsAllocated;
          UFG::Bullet::mAllocator.mFreeListHead = (char *)v31;
        }
      }
    }
  }
}

// File Line: 525
// RVA: 0x4588F0
void __fastcall UFG::BulletManager::AsyncRayCallback(
        UFG::RayCastData *ray,
        UFG::SimComponent *__formal,
        UFG::Bullet *callbackUserData)
{
  float x; // xmm10_4
  float y; // xmm11_4
  float z; // xmm12_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  UFG::SimObjectCVBase *m_pSimObject; // rsi
  UFG::TargetSphere *v12; // r14
  float v13; // xmm6_4
  float v14; // xmm9_4
  float v15; // xmm8_4
  float v16; // xmm7_4
  UFG::allocator::free_link *v17; // rax
  __int64 v18; // rax
  __int64 v19; // rbp
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rdx
  UFG::SimObject *m_pPointer; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  float v25; // xmm1_4
  float v26; // xmm2_4
  UFG::HavokUserData *v27; // r14
  void *mHavokRigidBody; // rax
  UFG::SimComponent *v29; // rsi
  bool v30; // bp
  UFG::SimObjectCharacter *v31; // r15
  float v32; // xmm3_4
  __m128 y_low; // xmm4
  float v34; // xmm5_4
  __m128 v35; // xmm2
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  UFG::SimObject *v39; // rax
  unsigned int v40; // edx
  unsigned int size; // r8d
  bool v42; // cl
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  float v45; // xmm0_4
  float v46; // xmm6_4
  float v47; // xmm5_4
  bool v48; // si
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v49; // rcx
  const char *TypeName; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v51; // rcx
  const char *v52; // rax
  UFG::qReflectObject *mData; // rdx
  UFG::SimComponent *v54; // rax
  float v55; // xmm0_4
  UFG::SimComponent *v56; // rax
  float v57; // xmm5_4
  float v58; // xmm3_4
  float v59; // xmm4_4
  float v60; // xmm2_4
  float v61; // xmm10_4
  float v62; // xmm8_4
  float v63; // xmm6_4
  char v64; // al
  float v65; // xmm4_4
  __m128 x_low; // xmm3
  float v67; // xmm5_4
  __m128 v68; // xmm2
  float v69; // xmm0_4
  float v70; // xmm3_4
  float v71; // xmm1_4
  float v72; // xmm2_4
  float v73; // xmm1_4
  UFG::qReflectHandleBase v74; // [rsp+38h] [rbp-F0h] BYREF
  UFG::qReflectHandleBase v75; // [rsp+60h] [rbp-C8h] BYREF
  UFG::allocator::free_link *t; // [rsp+140h] [rbp+18h] BYREF

  if ( !callbackUserData->weaponOwnerSimObject.m_pPointer )
  {
    *((_BYTE *)callbackUserData + 248) |= 8u;
    return;
  }
  x = callbackUserData->pos_t0.x;
  y = callbackUserData->pos_t0.y;
  z = callbackUserData->pos_t0.z;
  v8 = callbackUserData->pos_t1.x;
  v9 = callbackUserData->pos_t1.y;
  v10 = callbackUserData->pos_t1.z;
  m_pSimObject = 0i64;
  *(float *)&t = FLOAT_N1_0;
  v12 = UFG::BulletManager::TestAgainstTargetSpheres(UFG::BulletManager::mInstance, callbackUserData, (float *)&t);
  if ( !v12 )
    goto LABEL_85;
  v13 = *(float *)&t;
  if ( !ray->hit || *(float *)&t < ray->t )
  {
    v14 = (float)((float)(v10 - z) * *(float *)&t) + z;
    v15 = (float)((float)(v9 - y) * *(float *)&t) + y;
    v16 = (float)((float)(v8 - x) * *(float *)&t) + x;
    v17 = UFG::qMalloc(0xA0ui64, "BulletImpactDamageSphereEvent", 0i64);
    t = v17;
    if ( v17 )
    {
      UFG::BulletImpactDamageSphereEvent::BulletImpactDamageSphereEvent((UFG::BulletImpactDamageSphereEvent *)v17);
      v19 = v18;
    }
    else
    {
      v19 = 0i64;
    }
    *(_QWORD *)(v19 + 152) = v12;
    v20 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v19 + 56);
    m_pPointer = callbackUserData->weaponOwnerSimObject.m_pPointer;
    if ( *(_QWORD *)(v19 + 72) )
    {
      mPrev = v20->mPrev;
      v23 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v19 + 64);
      mPrev->mNext = v23;
      v23->mPrev = mPrev;
      v20->mPrev = v20;
      *(_QWORD *)(v19 + 64) = v19 + 56;
    }
    *(_QWORD *)(v19 + 72) = m_pPointer;
    if ( m_pPointer )
    {
      v24 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v24->mNext = v20;
      v20->mPrev = v24;
      *(_QWORD *)(v19 + 64) = &m_pPointer->m_SafePointerList;
      m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v20;
    }
    UFG::ProjectileInfo::operator=((UFG::ProjectileInfo *)(v19 + 80), &callbackUserData->projectileInfo);
    v25 = callbackUserData->vel.y;
    v26 = callbackUserData->vel.z;
    *(float *)(v19 + 120) = callbackUserData->vel.x;
    *(float *)(v19 + 124) = v25;
    *(float *)(v19 + 128) = v26;
    *(float *)(v19 + 132) = v16;
    *(float *)(v19 + 136) = v15;
    *(float *)(v19 + 140) = v14;
    *(_QWORD *)(v19 + 144) = 0i64;
    UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v19);
    *((_BYTE *)callbackUserData + 248) |= 0x10u;
  }
  if ( ray->hit && v13 > ray->t )
  {
LABEL_85:
    v27 = 0i64;
    if ( ray->hit )
    {
      mHavokRigidBody = ray->mHavokRigidBody;
      if ( mHavokRigidBody || (mHavokRigidBody = ray->mHavokPhantom) != 0i64 )
      {
        v27 = (UFG::HavokUserData *)*((_QWORD *)mHavokRigidBody + 3);
        if ( v27 )
        {
          v29 = v27->simComponent.m_pPointer;
          if ( v29 )
            m_pSimObject = (UFG::SimObjectCVBase *)v29->m_pSimObject;
          else
            m_pSimObject = 0i64;
        }
      }
      v30 = 1;
      v31 = (UFG::SimObjectCharacter *)callbackUserData->weaponOwnerSimObject.m_pPointer;
      if ( m_pSimObject == v31 )
      {
        v32 = callbackUserData->vel.x;
        y_low = (__m128)LODWORD(callbackUserData->vel.y);
        v34 = callbackUserData->vel.z;
        v35 = y_low;
        v35.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v32 * v32))
                        + (float)(v34 * v34);
        if ( v35.m128_f32[0] == 0.0 )
          v36 = 0.0;
        else
          v36 = 1.0 / _mm_sqrt_ps(v35).m128_f32[0];
        v37 = (float)((float)(v36 * v34) * 0.0099999998) + ray->point.z;
        v38 = (float)((float)(v36 * y_low.m128_f32[0]) * 0.0099999998) + ray->point.y;
        callbackUserData->pos_t1.x = (float)((float)(v36 * v32) * 0.0099999998) + ray->point.x;
        callbackUserData->pos_t1.y = v38;
        callbackUserData->pos_t1.z = v37;
        v30 = 0;
      }
      else if ( v31 == UFG::GetLocalPlayer()
             || !UFG::AreCharactersAllied(
                   m_pSimObject,
                   (UFG::SimObjectCVBase *)callbackUserData->weaponOwnerSimObject.m_pPointer)
             || UFG::IsHostage(m_pSimObject) )
      {
        v39 = callbackUserData->mustHitSimObject.m_pPointer;
        if ( v39 )
          v30 = v39 == m_pSimObject;
      }
      else
      {
        v30 = 0;
        *((_BYTE *)callbackUserData + 248) |= 0x10u;
      }
      v40 = 0;
      size = UFG::BulletManager::mInstance->mSimObjectsToIgnore.size;
      if ( size )
      {
        do
        {
          v42 = v30;
          if ( UFG::BulletManager::mInstance->mSimObjectsToIgnore.p[v40].mUID == m_pSimObject->m_Name.mUID )
            v42 = 0;
          v30 = v42;
          ++v40;
        }
        while ( v40 < size );
      }
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::HealthComponent::_TypeUID)
                       : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
        }
        if ( m_pComponent && BYTE5(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) )
        {
          *((_BYTE *)callbackUserData + 248) |= 0x10u;
          return;
        }
      }
      if ( v30 )
      {
        v45 = ray->t;
        v46 = (float)((float)(ray->mInput.m_to.m_quad.m128_f32[2] - ray->mInput.m_from.m_quad.m128_f32[2]) * v45)
            + ray->mInput.m_from.m_quad.m128_f32[2];
        v47 = (float)((float)(ray->mInput.m_to.m_quad.m128_f32[1] - ray->mInput.m_from.m_quad.m128_f32[1]) * v45)
            + ray->mInput.m_from.m_quad.m128_f32[1];
        callbackUserData->pos_t1.x = (float)((float)(ray->mInput.m_to.m_quad.m128_f32[0]
                                                   - ray->mInput.m_from.m_quad.m128_f32[0])
                                           * v45)
                                   + ray->mInput.m_from.m_quad.m128_f32[0];
        callbackUserData->pos_t1.y = v47;
        callbackUserData->pos_t1.z = v46;
        if ( (ray->mHavokRigidBody || ray->mHavokPhantom) && v27 )
        {
          if ( (unsigned __int8)UFG::BulletManager::ApplyDamage(
                                  UFG::BulletManager::mInstance,
                                  callbackUserData,
                                  ray,
                                  v27) )
            UFG::BulletManager::ApplyBulletImpactImpulse(UFG::BulletManager::mInstance, callbackUserData, ray, v27);
          UFG::BulletManager::SendBulletImpactEvent(
            UFG::BulletManager::mInstance,
            m_pSimObject,
            callbackUserData->weaponOwnerSimObject.m_pPointer);
          UFG::BulletManager::SendBulletImpactEvent(UFG::BulletManager::mInstance, callbackUserData, ray, v27);
        }
        v48 = 1;
        if ( !ray->mPhysicsObjectPropertyHandleUid )
          goto LABEL_84;
        UFG::qReflectHandleBase::qReflectHandleBase(&v75);
        TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v49);
        v75.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v75, v75.mTypeUID, ray->mPhysicsObjectPropertyHandleUid);
        if ( !v75.mData )
          UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v75);
        UFG::qReflectHandleBase::qReflectHandleBase(&v74);
        v52 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v51);
        v74.mTypeUID = UFG::qStringHash64(v52, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v74, v74.mTypeUID, ray->mPhysicsSurfacePropertyHandleUid);
        mData = v74.mData;
        if ( !v74.mData )
        {
          UFG::qReflectHandleBase::operator=(&v74, (UFG::qReflectHandleBase *)&v75.mData[3].mTypeUID);
          mData = v74.mData;
        }
        v54 = callbackUserData->projectileInfo.m_pSOWPC.m_pPointer;
        if ( !v54
          || *(_DWORD *)(*((_QWORD *)&v54[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v54[2].m_pSimObject))
                       + 108i64) == -1 )
        {
          if ( *(float *)&mData[1].mBaseNode.mUID > 0.0 )
          {
            v55 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
            if ( v55 <= *(float *)&v74.mData[1].mBaseNode.mUID )
              v48 = 0;
          }
        }
        else
        {
          v48 = BYTE6(mData[1].mBaseNode.mParent) == 0;
        }
        UFG::qReflectHandleBase::~qReflectHandleBase(&v74);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v75);
        if ( v48 )
        {
LABEL_84:
          if ( ray->hit )
          {
            v56 = callbackUserData->projectileInfo.m_pSOWPC.m_pPointer;
            if ( v56
              && *(_DWORD *)(*((_QWORD *)&v56[2].m_BoundComponentHandles.mNode.mPrev->mNext
                             + HIDWORD(v56[2].m_pSimObject))
                           + 108i64) != -1 )
            {
              v57 = callbackUserData->vel.y;
              v58 = callbackUserData->vel.x;
              v59 = callbackUserData->vel.z;
              v60 = (float)((float)(ray->normal.y * v57) + (float)(ray->normal.x * v58)) + (float)(ray->normal.z * v59);
              v61 = FLOAT_0_1;
              v62 = (float)((float)(ray->normal.y * v60) * -0.1)
                  + (float)((float)(v57 - (float)(ray->normal.y * v60)) * 0.1);
              v63 = (float)((float)(ray->normal.z * v60) * -0.1)
                  + (float)((float)(v59 - (float)(ray->normal.z * v60)) * 0.1);
              callbackUserData->vel.x = (float)((float)(ray->normal.x * v60) * -0.1)
                                      + (float)((float)(v58 - (float)(ray->normal.x * v60)) * 0.1);
              callbackUserData->vel.y = v62;
              callbackUserData->vel.z = v63;
              v64 = *((_BYTE *)callbackUserData + 248);
              if ( (v64 & 0x20) != 0 && callbackUserData->mArmingDistance <= callbackUserData->mDistanceTraveled )
                *((_BYTE *)callbackUserData + 248) = v64 | 0x10;
              *((_BYTE *)callbackUserData + 248) &= ~0x20u;
              goto LABEL_78;
            }
            *((_BYTE *)callbackUserData + 248) |= 0x10u;
          }
        }
        v61 = FLOAT_0_1;
LABEL_78:
        v65 = callbackUserData->vel.y;
        x_low = (__m128)LODWORD(callbackUserData->vel.x);
        v67 = callbackUserData->vel.z;
        v68 = x_low;
        v68.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v65 * v65))
                        + (float)(v67 * v67);
        v69 = _mm_sqrt_ps(v68).m128_f32[0];
        if ( v69 <= v61 )
        {
          v71 = UFG::qVector3::msZero.y;
          v72 = UFG::qVector3::msZero.z;
          callbackUserData->vel.x = UFG::qVector3::msZero.x;
          callbackUserData->vel.y = v71;
          callbackUserData->vel.z = v72;
          callbackUserData->mProjectileGravity = 0.0;
          v70 = (float)(ray->normal.x * 0.079999998) + ray->point.x;
          v73 = (float)(ray->normal.z * 0.079999998) + ray->point.z;
          callbackUserData->pos_t1.y = (float)(ray->normal.y * 0.079999998) + ray->point.y;
          callbackUserData->pos_t1.z = v73;
        }
        else
        {
          v70 = (float)(x_low.m128_f32[0] * (float)(0.0099999998 / v69)) + callbackUserData->pos_t1.x;
          callbackUserData->pos_t1.y = (float)(v65 * (float)(0.0099999998 / v69)) + callbackUserData->pos_t1.y;
          callbackUserData->pos_t1.z = (float)(v67 * (float)(0.0099999998 / v69)) + callbackUserData->pos_t1.z;
        }
        callbackUserData->pos_t1.x = v70;
      }
    }
  }
}

// File Line: 749
// RVA: 0x46FB70
void __fastcall UFG::BulletManager::PostRayCastUpdate(UFG::BulletManager *this, float deltaT)
{
  UFG::qNode<UFG::Bullet,UFG::Bullet> *mNext; // rbx
  UFG::qList<UFG::Bullet,UFG::Bullet,1,0> *i; // rsi
  bool v5; // zf
  __m128 mNext_high; // xmm2
  UFG::TransformNodeComponent *mPrev; // rcx
  float v8; // xmm11_4
  float v9; // xmm12_4
  float v10; // xmm13_4
  float v11; // xmm4_4
  __m128 v12; // xmm3
  float v13; // xmm5_4
  __m128 v14; // xmm2
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  __m128 x_low; // xmm2
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm9_4
  float v23; // xmm2_4
  float v24; // xmm9_4
  float v25; // xmm1_4
  float v26; // xmm10_4
  float v27; // xmm2_4
  float v28; // xmm9_4
  float v29; // xmm6_4
  float v30; // xmm1_4
  float v31; // xmm6_4
  float v32; // xmm8_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v36; // rcx
  int v37; // xmm0_4
  int v38; // xmm1_4
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v39; // rax
  float *v40; // rax
  float v41; // xmm8_4
  __m128 mPrev_high; // xmm2
  float v43; // xmm6_4
  float v44; // xmm9_4
  float v45; // xmm1_4
  float v46; // xmm4_4
  __m128 v47; // xmm3
  float v48; // xmm5_4
  __m128 v49; // xmm2
  float v50; // xmm6_4
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm0_4
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v55; // rax
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v56; // rax
  float v57; // xmm3_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // xmm0_4
  float v64; // xmm1_4
  char v65; // cl
  float v66; // xmm0_4
  bool v67; // cc
  UFG::Bullet *v68; // rdi
  UFG::qMatrix44 m; // [rsp+20h] [rbp-81h] BYREF

  mNext = this->mBulletList.mNode.mNext;
  for ( i = &this->mBulletList; mNext != (UFG::qNode<UFG::Bullet,UFG::Bullet> *)i; mNext = mNext->mNext )
  {
    v5 = ((__int64)mNext[15].mNext & 4) == 0;
    mNext_high = (__m128)HIDWORD(mNext[10].mNext);
    mNext_high.m128_f32[0] = (float)((float)(mNext_high.m128_f32[0] * mNext_high.m128_f32[0])
                                   + (float)(*(float *)&mNext[11].mPrev * *(float *)&mNext[11].mPrev))
                           + (float)(*((float *)&mNext[11].mPrev + 1) * *((float *)&mNext[11].mPrev + 1));
    *(float *)&mNext[14].mPrev = (float)(_mm_sqrt_ps(mNext_high).m128_f32[0] * deltaT) + *(float *)&mNext[14].mPrev;
    if ( !v5 )
    {
      mPrev = (UFG::TransformNodeComponent *)mNext[7].mPrev;
      v8 = *((float *)&mNext[9].mPrev + 1);
      v9 = *(float *)&mNext[9].mNext;
      v10 = *((float *)&mNext[9].mNext + 1);
      if ( mPrev )
      {
        v11 = *(float *)&mNext[11].mPrev;
        v12 = (__m128)HIDWORD(mNext[10].mNext);
        v13 = *((float *)&mNext[11].mPrev + 1);
        v14 = v12;
        v14.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
        if ( _mm_sqrt_ps(v14).m128_f32[0] >= 0.1 )
        {
          if ( v14.m128_f32[0] == 0.0 )
            v15 = 0.0;
          else
            v15 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
          v16 = v12.m128_f32[0] * v15;
          v17 = v11 * v15;
          v18 = v13 * v15;
          x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
          m.v0.x = v16;
          m.v0.y = v17;
          m.v0.z = v18;
          x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                    + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                            + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
          if ( x_low.m128_f32[0] == 0.0 )
            v20 = 0.0;
          else
            v20 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
          v21 = v20;
          v22 = v20;
          v23 = v20 * UFG::qVector3::msDirUp.z;
          v24 = v22 * UFG::qVector3::msDirUp.x;
          v25 = v21 * UFG::qVector3::msDirUp.y;
          v26 = (float)(v25 * v18) - (float)(v23 * v17);
          v27 = (float)(v23 * v16) - (float)(v24 * v18);
          v28 = (float)(v24 * v17) - (float)(v25 * v16);
          v29 = (float)((float)(v27 * v27) + (float)(v26 * v26)) + (float)(v28 * v28);
          if ( v29 == 0.0 )
            v30 = 0.0;
          else
            v30 = 1.0 / fsqrt(v29);
          m.v1.y = 0.0;
          m.v0.w = v27 * v30;
          m.v1.x = v28 * v30;
          m.v0.z = v26 * v30;
          v31 = (float)((float)(v28 * v30) * v17) - (float)((float)(v27 * v30) * v18);
          v32 = (float)((float)(v26 * v30) * v18) - (float)((float)(v28 * v30) * v16);
          v33 = (float)((float)(v27 * v30) * v16) - (float)((float)(v26 * v30) * v17);
          v34 = (float)((float)(v32 * v32) + (float)(v31 * v31)) + (float)(v33 * v33);
          if ( v34 == 0.0 )
            v35 = 0.0;
          else
            v35 = 1.0 / fsqrt(v34);
          m.v2.z = v8;
          m.v2.w = v9;
          m.v2.y = 0.0;
          m.v3.y = 1.0;
          m.v1.z = v31 * v35;
          m.v1.w = v32 * v35;
          m.v2.x = v33 * v35;
          m.v3.x = v10;
          UFG::TransformNodeComponent::SetLocalTransform(mPrev, &m);
        }
      }
      if ( UFG::OneShotHandle::IsValid((UFG::OneShotHandle *)&mNext[6].mNext) )
      {
        v36 = mNext[6].mNext;
        v37 = (int)mNext[9].mNext;
        v38 = HIDWORD(mNext[9].mNext);
        LODWORD(v36[5].mPrev) = HIDWORD(mNext[9].mPrev);
        HIDWORD(v36[5].mNext) = 1065353216;
        HIDWORD(v36[5].mPrev) = v37;
        LODWORD(v36[5].mNext) = v38;
        UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)v36);
      }
      v39 = mNext[7].mNext;
      if ( v39 )
      {
        v40 = (float *)v39[1].mPrev;
        if ( v40 )
        {
          v41 = *(float *)&mNext[14].mNext;
          if ( v41 <= v40[35] )
          {
            mPrev_high = (__m128)HIDWORD(mNext[10].mPrev);
            v43 = v40[33];
            v44 = v40[32];
            mPrev_high.m128_f32[0] = (float)((float)((float)(mPrev_high.m128_f32[0] - v9)
                                                   * (float)(mPrev_high.m128_f32[0] - v9))
                                           + (float)((float)(*(float *)&mNext[10].mPrev - v8)
                                                   * (float)(*(float *)&mNext[10].mPrev - v8)))
                                   + (float)((float)(*(float *)&mNext[10].mNext - v10)
                                           * (float)(*(float *)&mNext[10].mNext - v10));
            v45 = _mm_sqrt_ps(mPrev_high).m128_f32[0];
            if ( v45 < v43 )
              v43 = v45;
            v46 = *(float *)&mNext[11].mPrev;
            v47 = (__m128)HIDWORD(mNext[10].mNext);
            v48 = *((float *)&mNext[11].mPrev + 1);
            LODWORD(m.v0.x) = (_DWORD)v40;
            v49 = v47;
            m.v0.w = v8;
            m.v1.x = v9;
            v49.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(v46 * v46))
                            + (float)(v48 * v48);
            m.v1.y = v10;
            m.v2.z = v44;
            m.v2.w = v41;
            v50 = v43 / _mm_sqrt_ps(v49).m128_f32[0];
            m.v0.y = v9 - (float)(v46 * v50);
            v51 = *((float *)&mNext[11].mNext + 1);
            m.v0.z = v10 - (float)(v48 * v50);
            v52 = *(float *)&mNext[11].mNext;
            m.v1.w = v51;
            v53 = *((float *)&mNext[12].mPrev + 1);
            m.v1.z = v52;
            v54 = *(float *)&mNext[12].mPrev;
            m.v2.y = v53;
            m.v2.x = v54;
            m.v0.z = v8 - (float)(v47.m128_f32[0] * v50);
            Render::BeamManager::AddBeam(&Render::gBeamManager, (Render::BeamManager::AddBeamParameters *)&m);
          }
        }
      }
      v55 = mNext[8].mPrev;
      if ( v55 )
      {
        v56 = v55[1].mPrev;
        if ( v56 )
        {
          v57 = *(float *)&mNext[14].mNext;
          if ( v57 <= *((float *)&v56[8].mNext + 1) )
          {
            v58 = *(float *)&mNext[10].mPrev;
            v59 = *((float *)&mNext[10].mPrev + 1);
            v60 = *(float *)&mNext[10].mNext;
            *(_QWORD *)&m.v0.x = v56;
            m.v0.z = v58;
            v61 = *(float *)&mNext[11].mNext;
            m.v0.y = v59;
            v62 = *((float *)&mNext[11].mNext + 1);
            m.v1.z = v61;
            m.v2.x = *(float *)&mNext[12].mPrev;
            v63 = *(float *)&v56[8].mPrev;
            m.v1.w = v62;
            v64 = *((float *)&mNext[12].mPrev + 1);
            m.v2.z = v63;
            m.v0.z = v60;
            m.v0.w = v8;
            m.v1.x = v9;
            m.v1.y = v10;
            m.v2.y = v64;
            m.v2.w = v57;
            Render::BeamManager::AddBeam(&Render::gBeamManager, (Render::BeamManager::AddBeamParameters *)&m);
          }
        }
      }
    }
    v65 = (char)mNext[15].mNext;
    if ( (v65 & 0x10) == 0 && (v65 & 8) == 0 )
    {
      v66 = deltaT + *(float *)&mNext[14].mNext;
      v67 = v66 <= *((float *)&mNext[14].mPrev + 1);
      *(float *)&mNext[14].mNext = v66;
      if ( v67 )
        continue;
    }
    v68 = (UFG::Bullet *)mNext;
    mNext = mNext->mPrev;
    if ( v68 )
    {
      UFG::Bullet::~Bullet(v68);
      v68->mPrev = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)UFG::Bullet::mAllocator.mFreeListHead;
      --UFG::Bullet::mAllocator.mNumSlotsAllocated;
      UFG::Bullet::mAllocator.mFreeListHead = (char *)v68;
    }
  }
}

// File Line: 888
// RVA: 0x456B40
__int64 __fastcall UFG::BulletManager::ApplyDamage(
        UFG::BulletManager *this,
        UFG::Bullet *bullet,
        UFG::RayCastData *bulletRay,
        UFG::HavokUserData *hd)
{
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v9; // rcx
  const char *v10; // rax
  unsigned int v11; // ecx
  __int16 v12; // cx
  UFG::VehicleEffectsComponent *v13; // rax
  unsigned __int8 v14; // bl
  UFG::SimComponent *m_pPointer; // rdi
  UFG::SimComponent *v16; // rax
  float v17; // xmm6_4
  float v18; // xmm6_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rdi
  UFG::SimObject *v20; // r14
  UFG::GameStatTracker *v21; // rax
  float v22; // xmm1_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  void *(__fastcall *vecDelDtor)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rax
  void *(__fastcall *v27)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  float v28; // xmm0_4
  bool v29; // cf
  UFG::SimObject *v30; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rcx
  void *(__fastcall *v33)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax
  void *(__fastcall *v35)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  __int16 m_Flags; // cx
  UFG::PhysicsMoverInterface *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v39; // rax
  float v40; // xmm2_4
  __int16 v41; // cx
  hkSimpleLocalFrame *v42; // rdi
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectCVBase *Texture; // rdi
  UFG::SimObjectCharacter *LocalPlayer; // rax
  __int16 v46; // dx
  UFG::CharacterAnimationComponent *v47; // rax
  bool pIsAmbient; // [rsp+18h] [rbp-31h] BYREF
  bool subjectToAttackCooldown[8]; // [rsp+20h] [rbp-29h]
  UFG::qReflectHandleBase v51; // [rsp+28h] [rbp-21h] BYREF
  UFG::qReflectHandleBase v52; // [rsp+50h] [rbp+7h] BYREF
  void *retaddr; // [rsp+B8h] [rbp+6Fh] BYREF
  UFG::SimObjectCVBase *v54; // [rsp+C8h] [rbp+7Fh]

  *(_QWORD *)subjectToAttackCooldown = -2i64;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v52.mNameUID);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
  v52.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v52, v52.mTypeUID, bulletRay->mPhysicsObjectPropertyHandleUid);
  if ( !v52.mData )
    UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v52);
  UFG::qReflectHandleBase::qReflectHandleBase(&v51);
  v10 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v9);
  v51.mTypeUID = UFG::qStringHash64(v10, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v51, v51.mTypeUID, bulletRay->mPhysicsSurfacePropertyHandleUid);
  if ( !v51.mData )
    UFG::qReflectHandleBase::operator=(&v51, (UFG::qReflectHandleBase *)&v52.mData[3].mTypeUID);
  if ( (_S8_12 & 1) != 0 )
  {
    v11 = glassVehicleUid;
  }
  else
  {
    _S8_12 |= 1u;
    v11 = UFG::qStringHashUpper32("Glass_Vehicle", -1);
    glassVehicleUid = v11;
  }
  if ( LODWORD(v51.mData[2].vfptr) != v11 || !v54 )
  {
LABEL_20:
    m_pPointer = hd->simComponent.m_pPointer;
    if ( m_pPointer )
    {
      if ( UFG::SimComponent::IsType(m_pPointer, UFG::RigidBodyComponent::_RigidBodyComponentTypeUID) )
      {
        v16 = bullet->projectileInfo.m_pSOWPC.m_pPointer;
        if ( v16 )
        {
          v17 = *(float *)(*((_QWORD *)&v16[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v16[2].m_pSimObject))
                         + 144i64);
          if ( bullet->projectileInfo.m_bIsFullyAccurate )
            v17 = v17 * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fFullyAccurateDamageMultiplier;
          v18 = v17 * *((float *)&v51.mData[1].mBaseNode.mUID + 1);
          vfptr = m_pPointer[6].vfptr;
          if ( vfptr )
          {
            if ( (*((_BYTE *)bullet + 248) & 1) != 0 )
            {
              v20 = bullet->weaponOwnerSimObject.m_pPointer;
              v21 = UFG::GameStatTracker::Instance();
              v22 = UFG::GameStatTracker::GetStat(v21, Sharpshooter_Damage_Multiplier) * v18;
              if ( v22 > 0.0 )
              {
                if ( v20 )
                {
                  v23 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&vfptr[24];
                  if ( vfptr[26].__vecDelDtor )
                  {
                    mPrev = v23->mPrev;
                    vecDelDtor = vfptr[25].__vecDelDtor;
                    mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)vecDelDtor;
                    *(_QWORD *)vecDelDtor = mPrev;
                    v23->mPrev = v23;
                    vfptr[25].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&vfptr[24];
                  }
                  vfptr[26].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v20;
                  v26 = v20->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                  v26->mNext = v23;
                  v23->mPrev = v26;
                  vfptr[25].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&v20->m_SafePointerList;
                  v20->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v23;
                }
                v27 = vfptr[19].__vecDelDtor;
                if ( v27 )
                {
                  v28 = *((float *)&vfptr[33].__vecDelDtor + 1) - (float)(v22 * *((float *)v27 + 25));
                  v29 = v28 < 0.0;
                  goto LABEL_41;
                }
              }
            }
            else
            {
              v30 = bullet->weaponOwnerSimObject.m_pPointer;
              if ( v18 > 0.0 )
              {
                if ( v30 )
                {
                  v31 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&vfptr[24];
                  if ( vfptr[26].__vecDelDtor )
                  {
                    v32 = v31->mPrev;
                    v33 = vfptr[25].__vecDelDtor;
                    v32->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v33;
                    *(_QWORD *)v33 = v32;
                    v31->mPrev = v31;
                    vfptr[25].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&vfptr[24];
                  }
                  vfptr[26].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v30;
                  v34 = v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                  v34->mNext = v31;
                  v31->mPrev = v34;
                  vfptr[25].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&v30->m_SafePointerList;
                  v30->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v31;
                }
                v35 = vfptr[19].__vecDelDtor;
                if ( v35 )
                {
                  v28 = *((float *)&vfptr[33].__vecDelDtor + 1) - (float)(v18 * *((float *)v35 + 25));
                  v29 = v28 < 0.0;
LABEL_41:
                  *((float *)&vfptr[33].__vecDelDtor + 1) = v28;
                  if ( v29 )
                    HIDWORD(vfptr[33].__vecDelDtor) = 0;
                }
              }
            }
          }
        }
      }
    }
    if ( !v54 )
    {
LABEL_82:
      v14 = 1;
      goto LABEL_83;
    }
    m_Flags = v54->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          goto LABEL_72;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v54, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v54, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = (UFG::PhysicsMoverInterface *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::PhysicsMoverInterface *)v54->m_Components.p[34].m_pComponent;
      }
      if ( m_pComponent )
      {
        v39 = bullet->projectileInfo.m_pSOWPC.m_pPointer;
        if ( v39 )
        {
          v40 = *(float *)(*((_QWORD *)&v39[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v39[2].m_pSimObject))
                         + 148i64)
              * *((float *)&v51.mData[1].mBaseNode.mUID + 1);
          subjectToAttackCooldown[0] = 0;
          UFG::PhysicsMoverInterface::DamageEngine(m_pComponent, bullet->weaponOwnerSimObject.m_pPointer, v40, dtBULLET);
          if ( UFG::GetLocalPlayer() == bullet->weaponOwnerSimObject.m_pPointer )
          {
            UFG::GameStatAction::MissionScoring::DeduceFaction(v54, (bool *)&retaddr, &pIsAmbient);
            if ( !pIsAmbient )
            {
              v41 = v54->m_Flags;
              if ( (v41 & 0x4000) != 0 )
                goto LABEL_62;
              if ( v41 < 0 )
              {
                v42 = (hkSimpleLocalFrame *)v54->m_Components.p[30].m_pComponent;
LABEL_65:
                if ( v42 )
                {
                  if ( (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants((UFG::VehicleOccupantComponent *)v42) )
                  {
                    if ( !Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v42)
                      || (Texture = (UFG::SimObjectCVBase *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v42)) == 0i64
                      || (LocalPlayer = UFG::GetLocalPlayer(), !UFG::AreCharactersAllied(LocalPlayer, Texture)) )
                    {
                      UFG::GameStatAction::MissionScoring::LogTriadEvent(TRIAD_VEHICLE_DAMAGE, 0, &customCaption);
                    }
                  }
                }
                goto LABEL_72;
              }
              if ( (v41 & 0x2000) != 0 || (v41 & 0x1000) != 0 )
LABEL_62:
                ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v54, UFG::VehicleOccupantComponent::_TypeUID);
              else
                ComponentOfType = UFG::SimObject::GetComponentOfType(v54, UFG::VehicleOccupantComponent::_TypeUID);
              v42 = (hkSimpleLocalFrame *)ComponentOfType;
              goto LABEL_65;
            }
            UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_DAMAGE, 0, &customCaption);
          }
        }
      }
    }
LABEL_72:
    v46 = v54->m_Flags;
    if ( (v46 & 0x4000) != 0 || v46 < 0 )
    {
      v47 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v54);
    }
    else if ( (v46 & 0x2000) != 0 )
    {
      v47 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v54);
    }
    else if ( (v46 & 0x1000) != 0 )
    {
      v47 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v54,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      v47 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                  v54,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    if ( v47 )
      UFG::CharacterAnimationComponent::ApplyBulletDamage(v47, bulletRay);
    goto LABEL_82;
  }
  v12 = v54->m_Flags;
  if ( (v12 & 0x4000) != 0 )
    goto LABEL_16;
  if ( v12 < 0 )
  {
    v13 = (UFG::VehicleEffectsComponent *)v54->m_Components.p[32].m_pComponent;
    goto LABEL_18;
  }
  if ( (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0 )
LABEL_16:
    v13 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v54,
                                            UFG::VehicleEffectsComponent::_TypeUID);
  else
    v13 = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                            v54,
                                            UFG::VehicleEffectsComponent::_TypeUID);
LABEL_18:
  if ( !v13 )
    goto LABEL_20;
  UFG::VehicleEffectsComponent::DamageGlass(v13, &bulletRay->point);
  v14 = 0;
LABEL_83:
  UFG::qReflectHandleBase::~qReflectHandleBase(&v51);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v52);
  return v14;
}

// File Line: 1022
// RVA: 0x4742F0
void __fastcall UFG::BulletManager::SendBulletImpactEvent(
        UFG::BulletManager *this,
        UFG::SimObjectGame *simObject,
        UFG::SimObject *initiatorSimObject)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-28h] BYREF

  if ( simObject )
  {
    m_Flags = simObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = simObject->m_Components.p[3].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = simObject->m_Components.p[4].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(simObject, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(simObject, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = simObject->m_Components.p[3].m_pComponent;
    }
    if ( m_pComponent )
    {
      if ( LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == 1 )
      {
        stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
        stimulus_parameters.m_MaxStimulusDuration = -1.0;
        stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
        stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_IVE_BEEN_SHOT,
          &stimulus_parameters,
          initiatorSimObject,
          simObject);
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_IVE_BEEN_SHOT_NEARBY,
          &stimulus_parameters,
          simObject);
      }
    }
  }
}

// File Line: 1041
// RVA: 0x474400
void __fastcall UFG::BulletManager::SendBulletImpactEvent(
        UFG::BulletManager *this,
        UFG::Bullet *bullet,
        UFG::RayCastData *bulletRay,
        UFG::HavokUserData *hd)
{
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  UFG::SimObjectGame *v8; // rbx
  signed __int16 m_Flags; // cx
  UFG::VehicleEffectsComponent *m_pComponent; // rax
  UFG::SimComponent *m_pPointer; // rax
  unsigned int v12; // r15d
  UFG::SimComponent *v13; // rax
  UFG::allocator::free_link *v14; // rax
  __int64 v15; // rax
  __int64 v16; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  __m128 x_low; // xmm2
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  __int64 *v26; // rdx
  __int64 v27; // rcx
  _QWORD *v28; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v29; // rcx
  const char *v30; // rax
  unsigned int v31; // r14d
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v32; // rcx
  const char *v33; // rax
  float v34; // xmm4_4
  float v35; // xmm3_4
  __m128 v36; // xmm2
  __m128 v37; // xmm5
  float v38; // xmm1_4
  Render::FXSimComponent *fxComponent; // rdi
  UFG::SimComponent *v40; // rbx
  __int16 v41; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v43; // cx
  UFG::SimComponent *ComponentOfType; // rax
  float v45; // xmm4_4
  __m128 v46; // xmm5
  float v47; // xmm3_4
  __m128 v48; // xmm2
  float v49; // xmm6_4
  UFG::StateMachineComponent *vfptr; // rcx
  UFG::StimulusParameters stimulus_parameters; // [rsp+50h] [rbp-88h] BYREF
  float vRay[2]; // [rsp+68h] [rbp-70h] BYREF
  unsigned __int64 v53; // [rsp+70h] [rbp-68h]
  float vNormal[2]; // [rsp+78h] [rbp-60h] BYREF
  __int64 v55; // [rsp+80h] [rbp-58h]
  UFG::qReflectHandleBase v56; // [rsp+88h] [rbp-50h] BYREF
  __int64 v57; // [rsp+B0h] [rbp-28h]
  UFG::qReflectHandleBase v58; // [rsp+B8h] [rbp-20h] BYREF
  UFG::SimObjectGame *retaddr; // [rsp+158h] [rbp+80h]

  v57 = -2i64;
  UFG::qReflectHandleBase::qReflectHandleBase(&v56);
  TypeName = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v6);
  v53 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(
    (UFG::qReflectHandleBase *)&stimulus_parameters.m_MaxStimulusDuration,
    v53,
    bulletRay->mPhysicsSurfacePropertyHandleUid);
  v8 = retaddr;
  if ( retaddr )
  {
    m_Flags = retaddr->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags < 0 )
      {
        m_pComponent = (UFG::VehicleEffectsComponent *)retaddr->m_Components.p[32].m_pComponent;
LABEL_10:
        if ( m_pComponent
          && v55
          && *(float *)(v55 + 88) != 0.0
          && UFG::VehicleEffectsComponent::IsGlassBroken(m_pComponent, &bulletRay->point) )
        {
          goto LABEL_61;
        }
        goto LABEL_14;
      }
      if ( (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                         retaddr,
                                                         UFG::VehicleEffectsComponent::_TypeUID);
        goto LABEL_10;
      }
    }
    m_pComponent = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     retaddr,
                                                     UFG::VehicleEffectsComponent::_TypeUID);
    goto LABEL_10;
  }
LABEL_14:
  m_pPointer = bullet->projectileInfo.m_pSOWPC.m_pPointer;
  if ( m_pPointer && *(float *)&m_pPointer[3].vfptr > 0.5 )
  {
    stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
    stimulus_parameters.m_MaxStimulusDuration = -1.0;
    stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
    stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
    UFG::StimulusManager::BeginStimulus(
      UFG::StimulusManager::s_pInstance,
      eSTIMULUS_BULLET_IMPACT,
      &stimulus_parameters,
      &bulletRay->point);
    LODWORD(bullet->projectileInfo.m_pSOWPC.m_pPointer[3].vfptr) = 0;
  }
  v12 = 0;
  v13 = bullet->projectileInfo.m_pSOWPC.m_pPointer;
  if ( v13 )
    v12 = *(_DWORD *)(*((_QWORD *)&v13[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v13[2].m_pSimObject))
                    + 120i64);
  v14 = UFG::qMalloc(0xF0ui64, "BulletCollisionEvent", 0i64);
  retaddr = (UFG::SimObjectGame *)v14;
  if ( v14 )
  {
    UFG::BulletCollisionEvent::BulletCollisionEvent((UFG::BulletCollisionEvent *)v14);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  if ( v16 )
  {
    *(_DWORD *)(v16 + 56) = 0;
    y = bulletRay->point.y;
    z = bulletRay->point.z;
    *(float *)(v16 + 60) = bulletRay->point.x;
    *(float *)(v16 + 64) = y;
    *(float *)(v16 + 68) = z;
    v19 = bulletRay->normal.y;
    v20 = bulletRay->normal.z;
    *(float *)(v16 + 72) = bulletRay->normal.x;
    *(float *)(v16 + 76) = v19;
    *(float *)(v16 + 80) = v20;
    x_low = (__m128)LODWORD(bullet->vel.x);
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(bullet->vel.y * bullet->vel.y))
                      + (float)(bullet->vel.z * bullet->vel.z);
    *(_DWORD *)(v16 + 84) = _mm_sqrt_ps(x_low).m128_u32[0];
    v22 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v16 + 96);
    if ( *(_QWORD *)(v16 + 112) )
    {
      mPrev = v22->mPrev;
      v24 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v16 + 104);
      mPrev->mNext = v24;
      v24->mPrev = mPrev;
      v22->mPrev = v22;
      *(_QWORD *)(v16 + 104) = v16 + 96;
    }
    *(_QWORD *)(v16 + 112) = v8;
    if ( v8 )
    {
      v25 = v8->m_SafePointerList.UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v25->mNext = v22;
      v22->mPrev = v25;
      *(_QWORD *)(v16 + 104) = &v8->m_SafePointerList;
      v8->m_SafePointerList.UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v22;
    }
    v26 = (__int64 *)(v16 + 120);
    if ( *(_QWORD *)(v16 + 136) )
    {
      v27 = *v26;
      v28 = *(_QWORD **)(v16 + 128);
      *(_QWORD *)(v27 + 8) = v28;
      *v28 = v27;
      *v26 = (__int64)v26;
      *(_QWORD *)(v16 + 128) = v16 + 120;
    }
    *(_QWORD *)(v16 + 136) = 0i64;
    *(_QWORD *)(v16 + 208) = bulletRay->mPhysicsSurfacePropertyHandleUid;
    *(_QWORD *)(v16 + 216) = 0i64;
    *(_QWORD *)(v16 + 192) = bulletRay->mPhysicsObjectPropertyHandleUid;
    UFG::qReflectHandleBase::qReflectHandleBase(&v58);
    v30 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v29);
    v58.mTypeUID = UFG::qStringHash64(v30, 0xFFFFFFFFFFFFFFFFui64);
    UFG::PhysicsPropertyManager::GetObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v58, v12, 1);
    *(_QWORD *)(v16 + 200) = v58.mData->mBaseNode.mUID;
    v31 = 0;
    if ( v55 )
    {
      v31 = *(_DWORD *)(v55 + 108);
    }
    else
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v56);
      v33 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v32);
      v56.mTypeUID = UFG::qStringHash64(v33, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v56, v56.mTypeUID, bulletRay->mPhysicsObjectPropertyHandleUid);
      if ( v56.mData )
        v31 = *(_DWORD *)(v56.mData[4].mBaseNode.mUID + 108);
      UFG::qReflectHandleBase::~qReflectHandleBase(&v56);
    }
    v36 = (__m128)bulletRay->mInput.m_to.m_quad.m128_u32[0];
    v34 = bulletRay->mInput.m_to.m_quad.m128_f32[2] - bulletRay->mInput.m_from.m_quad.m128_f32[2];
    v35 = bulletRay->mInput.m_to.m_quad.m128_f32[1] - bulletRay->mInput.m_from.m_quad.m128_f32[1];
    v36.m128_f32[0] = v36.m128_f32[0] - bulletRay->mInput.m_from.m_quad.m128_f32[0];
    v37 = v36;
    v37.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v35 * v35)) + (float)(v34 * v34);
    if ( v37.m128_f32[0] == 0.0 )
      v38 = 0.0;
    else
      v38 = 1.0 / _mm_sqrt_ps(v37).m128_f32[0];
    vRay[0] = v36.m128_f32[0] * v38;
    vRay[1] = v35 * v38;
    *(float *)&v53 = v34 * v38;
    if ( v8 )
    {
      v41 = v8->m_Flags;
      if ( (v41 & 0x4000) != 0 || v41 < 0 || (v41 & 0x2000) != 0 || (v41 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, Render::FXSimComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, Render::FXSimComponent::_TypeUID);
      fxComponent = (Render::FXSimComponent *)ComponentOfTypeHK;
      v43 = v8->m_Flags;
      if ( (v43 & 0x4000) != 0 || v43 < 0 || (v43 & 0x2000) != 0 || (v43 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::RigidBodyComponent::_TypeUID);
      v40 = ComponentOfType;
    }
    else
    {
      fxComponent = 0i64;
      v40 = 0i64;
    }
    v45 = bulletRay->normal.y;
    v46 = (__m128)LODWORD(bulletRay->normal.x);
    v47 = bulletRay->normal.z;
    v48 = v46;
    v48.m128_f32[0] = (float)((float)(v46.m128_f32[0] * v46.m128_f32[0]) + (float)(v45 * v45)) + (float)(v47 * v47);
    if ( v48.m128_f32[0] == 0.0 )
      v49 = 0.0;
    else
      v49 = 1.0 / _mm_sqrt_ps(v48).m128_f32[0];
    vNormal[0] = v46.m128_f32[0] * v49;
    vNormal[1] = v45 * v49;
    stimulus_parameters.m_StimulusProducerOffset.z = v47 * v49;
    Render::ImpactManager::HandleImpactEvent(
      &Render::gImpactManager,
      v12,
      v31,
      &bulletRay->point,
      (UFG::qVector3 *)vRay,
      (UFG::qVector3 *)vNormal,
      fxComponent,
      0,
      &stimulus_parameters.m_StimulusProducerOffset);
    if ( v40 )
    {
      vfptr = (UFG::StateMachineComponent *)v40[6].vfptr;
      if ( vfptr )
        UFG::StateMachineComponent::ApplyImpactEffect(
          vfptr,
          &bulletRay->point,
          &stimulus_parameters.m_StimulusProducerOffset);
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v58);
  }
LABEL_61:
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&stimulus_parameters.m_MaxStimulusDuration);
}

// File Line: 1149
// RVA: 0x456350
void __fastcall UFG::BulletManager::ApplyBulletImpactImpulse(
        UFG::BulletManager *this,
        UFG::Bullet *bullet,
        UFG::RayCastData *ray,
        UFG::HavokUserData *hd)
{
  UFG::SimObjectGame *v7; // rsi
  UFG::SimComponent *m_pPointer; // rsi
  __int16 m_Flags; // cx
  UFG::HitReactionComponent *m_pComponent; // r10
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rcx
  float y; // xmm1_4
  float z; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  hkpRigidBody *mHavokRigidBody; // rcx
  unsigned __int64 ObjectPropertiesHandleUid; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v19; // rcx
  const char *TypeName; // rax
  unsigned __int64 v21; // rdx
  hkpRigidBody *v22; // rbx
  char m_storage; // cl
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  float v28; // xmm5_4
  UFG::SimComponent *v29; // rax
  __m128 v30; // xmm0
  UFG::Destruction *v31; // r13
  UFG::SimComponent *v32; // r15
  UFG::CollisionMeshData *v33; // r15
  hkpRigidBody *v34; // r9
  hkpShape *m_shape; // rdx
  hkpShape *m_userData; // rbx
  unsigned int v37; // esi
  char v38; // r8
  UFG::CollisionMeshData::PartDetails *PartDetails; // rax
  hkpWorld *m_world; // r12
  UFG::CollisionMeshData::Part *Part; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v42; // rcx
  const char *v43; // rax
  __m128 v44; // xmm4
  __m128 v45; // xmm3
  __m128 v46; // xmm3
  __m128 v47; // xmm0
  float v48; // xmm5_4
  __m128 v49; // xmm0
  hkpRigidBody *v50; // rbx
  __int64 m_size; // rdi
  hkpRigidBody **m_data; // r14
  int v53; // esi
  int v54; // r9d
  hkpEntity **v55; // rax
  char *v56; // rdx
  signed __int64 v57; // r14
  unsigned __int64 type_uid[2]; // [rsp+50h] [rbp-88h] BYREF
  __m128 v59; // [rsp+60h] [rbp-78h] BYREF
  UFG::qReflectHandleBase v60; // [rsp+70h] [rbp-68h] BYREF
  hkVector4f v61; // [rsp+98h] [rbp-40h]
  __int64 v62; // [rsp+A8h] [rbp-30h]
  __int128 v63[2]; // [rsp+B8h] [rbp-20h] BYREF
  hkpPhysicsSystem sys; // [rsp+D8h] [rbp+0h] BYREF
  hkpRigidBody **array; // [rsp+148h] [rbp+70h] BYREF
  int v66; // [rsp+150h] [rbp+78h]
  int v67; // [rsp+154h] [rbp+7Ch]
  hkpRigidBody *v68; // [rsp+158h] [rbp+80h] BYREF
  hkResult result; // [rsp+5A0h] [rbp+4C8h] BYREF

  v62 = -2i64;
  if ( (*((_BYTE *)bullet + 248) & 2) == 0 )
  {
    v7 = 0i64;
    if ( hd )
    {
      m_pPointer = hd->simComponent.m_pPointer;
      v7 = m_pPointer ? (UFG::SimObjectGame *)m_pPointer->m_pSimObject : 0i64;
      if ( v7 )
      {
        m_Flags = v7->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::HitReactionComponent *)v7->m_Components.p[15].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          v11 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HitReactionComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v7, UFG::HitReactionComponent::_TypeUID);
          m_pComponent = (UFG::HitReactionComponent *)v11;
        }
        else
        {
          m_pComponent = (UFG::HitReactionComponent *)v7->m_Components.p[15].m_pComponent;
        }
        if ( m_pComponent )
        {
          v12 = bullet->weaponOwnerSimObject.m_pPointer;
          y = bullet->vel.y;
          z = bullet->vel.z;
          v59.m128_i32[0] = LODWORD(bullet->vel.x);
          *(unsigned __int64 *)((char *)v59.m128_u64 + 4) = __PAIR64__(LODWORD(z), LODWORD(y));
          v15 = ray->point.y;
          v16 = ray->point.z;
          *(float *)type_uid = ray->point.x;
          *((float *)type_uid + 1) = v15;
          *(float *)&type_uid[1] = v16;
          UFG::HitReactionComponent::ApplyBulletImpactImpulse(
            m_pComponent,
            (UFG::qVector3 *)type_uid,
            (UFG::qVector3 *)&v59,
            &bullet->projectileInfo,
            v12,
            ray->mPhysicsObjectPropertyHandleUid);
        }
      }
    }
    mHavokRigidBody = ray->mHavokRigidBody;
    if ( mHavokRigidBody )
    {
      ObjectPropertiesHandleUid = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(mHavokRigidBody);
      UFG::qReflectHandleBase::qReflectHandleBase(&v60);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v19);
      type_uid[1] = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v60, type_uid[1], ObjectPropertiesHandleUid);
      v21 = v59.m128_u64[1];
      if ( !v59.m128_u64[1] )
      {
        UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v60);
        v21 = v59.m128_u64[1];
      }
      if ( !v7 || (v7->m_Flags & 0x400) != 0 )
        goto LABEL_71;
      v22 = ray->mHavokRigidBody;
      m_storage = v22->m_motion.m_type.m_storage;
      if ( m_storage != 5 && m_storage != 4 )
      {
        v59 = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)LODWORD(ray->point.x), (__m128)LODWORD(ray->point.z)),
                _mm_unpacklo_ps((__m128)LODWORD(ray->point.y), (__m128)0i64));
        v24 = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)LODWORD(bullet->vel.x), (__m128)LODWORD(bullet->vel.z)),
                _mm_unpacklo_ps((__m128)LODWORD(bullet->vel.y), (__m128)0i64));
        *(__m128 *)type_uid = v24;
        v25 = _mm_mul_ps(v24, v24);
        v26 = _mm_add_ps(
                _mm_shuffle_ps(v25, v25, 170),
                _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)));
        v27 = _mm_rsqrt_ps(v26);
        v28 = _mm_andnot_ps(
                _mm_cmple_ps(v26, (__m128)0i64),
                _mm_mul_ps(
                  v26,
                  _mm_mul_ps(
                    _mm_mul_ps(*(__m128 *)_xmm, v27),
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27))))).m128_f32[0];
        if ( v28 > 0.0099999998 )
        {
          v29 = bullet->projectileInfo.m_pSOWPC.m_pPointer;
          if ( v29 )
            v30 = (__m128)*(unsigned int *)(*((_QWORD *)&v29[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                            + HIDWORD(v29[2].m_pSimObject))
                                          + 92i64);
          else
            v30 = (__m128)LODWORD(FLOAT_50_0);
          if ( v21 )
            v30.m128_f32[0] = v30.m128_f32[0] * *(float *)(v21 + 132);
          v30.m128_f32[0] = v30.m128_f32[0] / v28;
          *(__m128 *)type_uid = _mm_mul_ps(v24, _mm_shuffle_ps(v30, v30, 0));
          hkpEntity::activate(v22);
          ((void (__fastcall *)(hkpMaxSizeMotion *, unsigned __int64 *, __m128 *))v22->m_motion.hkpEntity::vfptr[11].__first_virtual_table_function__)(
            &v22->m_motion,
            type_uid,
            &v59);
        }
      }
      v31 = UFG::Destruction::mInstance;
      type_uid[0] = 0i64;
      type_uid[1] = 0x8000000000000000ui64;
      hkpPhysicsSystem::hkpPhysicsSystem(&sys);
      v61.m_quad = _mm_unpacklo_ps(
                     _mm_unpacklo_ps((__m128)LODWORD(ray->normal.x), (__m128)LODWORD(ray->normal.z)),
                     _mm_unpacklo_ps((__m128)LODWORD(ray->normal.y), (__m128)0i64));
      v63[1] = (__int128)_mm_unpacklo_ps(
                           _mm_unpacklo_ps((__m128)LODWORD(ray->point.x), (__m128)LODWORD(ray->point.z)),
                           _mm_unpacklo_ps((__m128)LODWORD(ray->point.y), (__m128)0i64));
      v32 = hd->simComponent.m_pPointer;
      if ( !v32
        || !UFG::SimComponent::IsType(v32, UFG::RigidBodyComponent::_RigidBodyComponentTypeUID)
        || (v33 = *(UFG::CollisionMeshData **)&v32[2].m_Flags) == 0i64
        || ray->mOutput.m_shapeKeys[0] == -1
        || ray->mOutput.m_shapeKeys[1] == -1 )
      {
LABEL_68:
        hkpPhysicsSystem::~hkpPhysicsSystem(&sys);
        LODWORD(type_uid[1]) = 0;
        if ( (type_uid[1] & 0x8000000000000000ui64) == 0i64 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            (void *)type_uid[0],
            4 * HIDWORD(type_uid[1]));
        type_uid[0] = 0i64;
        HIDWORD(type_uid[1]) = 0x80000000;
LABEL_71:
        UFG::qReflectHandleBase::~qReflectHandleBase(&v60);
        return;
      }
      v34 = ray->mHavokRigidBody;
      m_shape = v34->m_collidable.m_shape;
      m_userData = 0i64;
      v37 = -1;
      v38 = m_shape->m_type.m_storage;
      if ( v38 == 9 )
      {
        m_userData = (hkpShape *)m_shape[2].m_userData;
      }
      else
      {
        if ( v38 != 8 )
        {
LABEL_42:
          if ( UFG::Destruction::IsPartMarkedAsBreakable(v31, ray->mHavokRigidBody, v37)
            && m_userData->m_type.m_storage == 8
            && v37 != -1 )
          {
            PartDetails = UFG::CollisionMeshData::GetPartDetails(v33, v37);
            if ( PartDetails )
            {
              if ( PartDetails->mShearImpulse > 0.0 )
              {
                m_world = ray->mHavokRigidBody->m_world;
                Part = UFG::CollisionMeshData::GetPart(v33, v37);
                UFG::qReflectHandleBase::qReflectHandleBase(&v60);
                v43 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v42);
                v60.mTypeUID = UFG::qStringHash64(v43, 0xFFFFFFFFFFFFFFFFui64);
                UFG::qReflectHandleBase::Init(&v60, v60.mTypeUID, Part->mBaseProperty.objectPropertyHandleId);
                if ( v60.mData && BYTE3(v60.mData[1].mHandles.mNode.mNext) )
                  UFG::Destruction::breakOffSubPart(v31, 0i64, ray->mHavokRigidBody, v37);
                hkpWorld::addPhysicsSystem(m_world, &sys);
                if ( sys.m_rigidBodies.m_size > 0 )
                {
                  v63[0] = (__int128)_mm_unpacklo_ps(
                                       _mm_unpacklo_ps((__m128)LODWORD(ray->point.x), (__m128)LODWORD(ray->point.z)),
                                       _mm_unpacklo_ps((__m128)LODWORD(ray->point.y), (__m128)0i64));
                  v44 = _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)LODWORD(bullet->vel.x), (__m128)LODWORD(bullet->vel.z)),
                          _mm_unpacklo_ps((__m128)LODWORD(bullet->vel.y), (__m128)0i64));
                  v59 = v44;
                  v45 = _mm_mul_ps(v44, v44);
                  v46 = _mm_add_ps(
                          _mm_shuffle_ps(v45, v45, 170),
                          _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)));
                  v47 = _mm_rsqrt_ps(v46);
                  v48 = _mm_andnot_ps(
                          _mm_cmple_ps(v46, (__m128)0i64),
                          _mm_mul_ps(
                            v46,
                            _mm_mul_ps(
                              _mm_mul_ps(*(__m128 *)_xmm, v47),
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v47, v46), v47))))).m128_f32[0];
                  if ( v48 > 0.0099999998 )
                  {
                    v49 = (__m128)*(unsigned int *)(*((_QWORD *)&bullet->projectileInfo.m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                                    + HIDWORD(bullet->projectileInfo.m_pSOWPC.m_pPointer[2].m_pSimObject))
                                                  + 92i64);
                    if ( v59.m128_u64[1] )
                      v49.m128_f32[0] = v49.m128_f32[0] * *(float *)(v59.m128_u64[1] + 132);
                    v49.m128_f32[0] = v49.m128_f32[0] / v48;
                    v59 = _mm_mul_ps(v44, _mm_shuffle_ps(v49, v49, 0));
                    v50 = *sys.m_rigidBodies.m_data;
                    hkpEntity::activate(*sys.m_rigidBodies.m_data);
                    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __int128 *))v50->m_motion.hkpEntity::vfptr[11].__first_virtual_table_function__)(
                      &v50->m_motion,
                      &v59,
                      v63);
                  }
                }
                array = &v68;
                v66 = 0;
                v67 = -2147483520;
                v68 = ray->mHavokRigidBody;
                v66 = 1;
                m_size = sys.m_rigidBodies.m_size;
                m_data = sys.m_rigidBodies.m_data;
                v53 = sys.m_rigidBodies.m_size + 1;
                if ( sys.m_rigidBodies.m_size + 1 > 128 )
                {
                  v54 = sys.m_rigidBodies.m_size + 1;
                  if ( v53 < 2 * (v67 & 0x3FFFFFFF) )
                    v54 = 2 * (v67 & 0x3FFFFFFF);
                  hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v54, 8);
                }
                hkMemUtil::memMove(&array[m_size + 1], array + 1, 0);
                v55 = array;
                v56 = (char *)(array + 1);
                if ( m_size > 0 )
                {
                  v57 = (char *)m_data - v56;
                  do
                  {
                    *(_QWORD *)v56 = *(_QWORD *)&v56[v57];
                    v56 += 8;
                    --m_size;
                  }
                  while ( m_size );
                  v55 = array;
                }
                v66 = v53;
                if ( v53 )
                {
                  hkpWorld::reintegrateAndRecollideEntities(m_world, v55, v53, RR_MODE_RECOLLIDE_NARROWPHASE);
                  hkReferencedObject::lockAll();
                  hkpPhysicsSystem::removeAll(&sys);
                  hkReferencedObject::unlockAll();
                }
                v66 = 0;
                if ( v67 >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v67);
                array = 0i64;
                v67 = 0x80000000;
                UFG::qReflectHandleBase::~qReflectHandleBase(&v60);
              }
            }
          }
          goto LABEL_68;
        }
        m_userData = v34->m_collidable.m_shape;
      }
      v37 = ray->mOutput.m_shapeKeys[0];
      goto LABEL_42;
    }
  }
}

// File Line: 1315
// RVA: 0x455D40
void __fastcall UFG::BulletManager::AddTargetSphere(UFG::BulletManager *this, UFG::TargetSphere *sphere)
{
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *mNext; // rax
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *mPrev; // r8
  UFG::qList<UFG::TargetSphere,UFG::TargetSphere,1,0> *p_mTargetSpheres; // rcx
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v5; // rax

  mNext = sphere->mNext;
  mPrev = sphere->mPrev;
  p_mTargetSpheres = &this->mTargetSpheres;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  sphere->mPrev = sphere;
  sphere->mNext = sphere;
  v5 = p_mTargetSpheres->mNode.mPrev;
  v5->mNext = sphere;
  sphere->mPrev = v5;
  sphere->mNext = &p_mTargetSpheres->mNode;
  p_mTargetSpheres->mNode.mPrev = sphere;
}

// File Line: 1323
// RVA: 0x473240
void __fastcall UFG::BulletManager::RemoveTargetSphere(UFG::BulletManager *this, UFG::TargetSphere *sphere)
{
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *mPrev; // rcx
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *mNext; // rax

  mPrev = sphere->mPrev;
  mNext = sphere->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  sphere->mPrev = sphere;
  sphere->mNext = sphere;
}

// File Line: 1330
// RVA: 0x4661D0
Render::BeamSettingsHandle *__fastcall UFG::BulletManager::GetBeamSettingsHandle(
        UFG::BulletManager *this,
        _DWORD *beamSettingsSymbol)
{
  __int64 v3; // rax
  Render::BeamSettingsHandle **i; // rcx

  if ( *beamSettingsSymbol == -1 )
    return 0i64;
  v3 = 0i64;
  if ( !UFG::BulletManager::smSettingsHandles.size )
    return *UFG::BulletManager::smSettingsHandles.p;
  for ( i = UFG::BulletManager::smSettingsHandles.p; !*i || (*i)->mNameUID != *beamSettingsSymbol; ++i )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= UFG::BulletManager::smSettingsHandles.size )
      return *UFG::BulletManager::smSettingsHandles.p;
  }
  return UFG::BulletManager::smSettingsHandles.p[v3];
}

// File Line: 1355
// RVA: 0x476CD0
UFG::TargetSphere *__fastcall UFG::BulletManager::TestAgainstTargetSpheres(
        UFG::BulletManager *this,
        UFG::Bullet *bullet,
        float *t)
{
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *mNext; // rbx
  UFG::qList<UFG::TargetSphere,UFG::TargetSphere,1,0> *p_mTargetSpheres; // rsi
  UFG::TargetSphere *v5; // rdi
  float v6; // xmm6_4
  UFG::qVector3 *q1; // rbp
  UFG::qVector3 *q0; // r14
  UFG::TargetSphere *result; // rax
  float v11; // [rsp+80h] [rbp+8h] BYREF

  mNext = this->mTargetSpheres.mNode.mNext;
  p_mTargetSpheres = &this->mTargetSpheres;
  v5 = 0i64;
  v6 = FLOAT_1000000_0;
  if ( mNext == (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)&this->mTargetSpheres )
    return 0i64;
  q1 = &bullet->pos_t1;
  q0 = &bullet->pos_t0;
  do
  {
    if ( UFG::SweptSphereQuery(
           *(float *)&mNext[2].mNext,
           (UFG::qVector3 *)&mNext[1],
           (UFG::qVector3 *)((char *)&mNext[1].mNext + 4),
           0.0099999998,
           q0,
           q1,
           &v11)
      && v6 > v11 )
    {
      v5 = (UFG::TargetSphere *)mNext;
      v6 = v11;
    }
    mNext = mNext->mNext;
  }
  while ( mNext != (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)p_mTargetSpheres );
  result = v5;
  if ( v6 <= 1.0 )
    *t = v6;
  return result;
}

// File Line: 1385
// RVA: 0x461980
void __fastcall UFG::BulletManager::DisableBulletImpacts(UFG::BulletManager *this, UFG::SimObject *simObject)
{
  UFG::qArray<UFG::qSymbol,0> *p_mSimObjectsToIgnore; // rsi
  __int64 size; // rdi
  unsigned int v4; // r8d
  UFG::qSymbol *p; // rax
  unsigned int capacity; // edx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  UFG::qSymbol *v10; // rcx

  if ( simObject )
  {
    p_mSimObjectsToIgnore = &this->mSimObjectsToIgnore;
    size = this->mSimObjectsToIgnore.size;
    v4 = 0;
    if ( (_DWORD)size )
    {
      p = this->mSimObjectsToIgnore.p;
      while ( simObject->m_Name.mUID != p->mUID )
      {
        ++v4;
        ++p;
        if ( v4 >= (unsigned int)size )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      capacity = this->mSimObjectsToIgnore.capacity;
      v8 = size + 1;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v9 = 2 * capacity;
        else
          v9 = 1;
        for ( ; v9 < v8; v9 *= 2 )
          ;
        if ( v9 <= 4 )
          v9 = 4;
        if ( v9 - v8 > 0x10000 )
          v9 = size + 65537;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(&this->mSimObjectsToIgnore, v9, "qArray.Add");
      }
      v10 = p_mSimObjectsToIgnore->p;
      p_mSimObjectsToIgnore->size = v8;
      v10[size] = simObject->m_Name;
    }
  }
}

// File Line: 1405
// RVA: 0x463DA0
void __fastcall UFG::BulletManager::EnableBulletImpacts(UFG::BulletManager *this, UFG::SimObject *simObject)
{
  unsigned int size; // ecx
  __int64 v4; // r9
  unsigned int mUID; // edx
  UFG::qSymbol *i; // rax
  unsigned int v7; // eax

  size = this->mSimObjectsToIgnore.size;
  v4 = 0i64;
  if ( size )
  {
    mUID = simObject->m_Name.mUID;
    for ( i = this->mSimObjectsToIgnore.p; mUID != i->mUID; ++i )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= size )
        return;
    }
    this->mSimObjectsToIgnore.p[v4].mUID = this->mSimObjectsToIgnore.p[size - 1].mUID;
    v7 = this->mSimObjectsToIgnore.size;
    if ( v7 > 1 )
      this->mSimObjectsToIgnore.size = v7 - 1;
    else
      this->mSimObjectsToIgnore.size = 0;
  }
}

