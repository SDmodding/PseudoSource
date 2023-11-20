// File Line: 74
// RVA: 0x1514450
__int64 dynamic_initializer_for__UFG::BulletManager::smSettingsHandles__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::BulletManager::smSettingsHandles__);
}

// File Line: 76
// RVA: 0x1513C60
__int64 dynamic_initializer_for__UFG::Bullet::mAllocator__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::Bullet::mAllocator);
  return atexit(dynamic_atexit_destructor_for__UFG::Bullet::mAllocator__);
}

// File Line: 86
// RVA: 0x1519CB0
__int64 UFG::_dynamic_initializer_for__bulletNameHash__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bullet", 0xFFFFFFFF);
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gBulletImpactDamageSphereEventChannel__);
}

// File Line: 111
// RVA: 0x468E00
void UFG::BulletManager::Initialize(void)
{
  unsigned int v0; // ebx
  UFG::allocator::free_link *v1; // rax
  UFG::BulletManager *v2; // rax
  UFG::qPropertySet *v3; // rax
  UFG::qPropertyList *v4; // r15
  unsigned int v5; // edi
  unsigned int v6; // ecx
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax
  Render::BeamSettingsHandle **v9; // rsi
  Render::BeamSettingsHandle **v10; // r9
  unsigned int i; // er8
  unsigned int v12; // er14
  __int64 v13; // rsi
  UFG::allocator::free_link *v14; // rax
  Render::BeamSettingsHandle *v15; // rbx
  UFG::qSymbolUC *v16; // rax
  unsigned int v17; // ebp
  Render::BeamSettingsHandle **v18; // rax
  Render::BeamSettingsHandle *v19; // rbx
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qResourceHandle *v22; // rbx
  UFG::qResourceInventory *v23; // rax
  UFG::qResourceWarehouse *v24; // rax
  UFG::qSymbol result; // [rsp+70h] [rbp+8h]
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
  v3 = UFG::PropertySetManager::GetPropertySet(&result);
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qSymbol *)&PhysicsSym_Tracers.mUID, DEPTH_RECURSE);
  v5 = v4->mNumElements;
  v6 = UFG::BulletManager::smSettingsHandles.size;
  if ( !UFG::BulletManager::smSettingsHandles.size )
  {
    if ( (signed int)v5 <= 0 )
    {
      if ( v5 )
        v6 = 0;
      UFG::BulletManager::smSettingsHandles.size = v6;
    }
    else
    {
      if ( v5 > UFG::BulletManager::smSettingsHandles.capacity )
      {
        if ( UFG::BulletManager::smSettingsHandles.capacity )
          v0 = 2 * UFG::BulletManager::smSettingsHandles.capacity;
        for ( ; v0 < v5; v0 *= 2 )
          ;
        if ( v0 <= 2 )
          v0 = 2;
        if ( v0 - v5 > 0x10000 )
          v0 = v5 + 0x10000;
        if ( v0 )
        {
          v7 = 8i64 * v0;
          if ( !is_mul_ok(v0, 8ui64) )
            v7 = -1i64;
          v8 = UFG::qMalloc(v7, "numTracers", 0i64);
          v9 = (Render::BeamSettingsHandle **)v8;
          v10 = UFG::BulletManager::smSettingsHandles.p;
          if ( UFG::BulletManager::smSettingsHandles.p )
          {
            for ( i = 0; i < UFG::BulletManager::smSettingsHandles.size; v10 = UFG::BulletManager::smSettingsHandles.p )
            {
              v8[i].mNext = (UFG::allocator::free_link *)v10[i];
              ++i;
            }
            operator delete[](v10);
          }
          UFG::BulletManager::smSettingsHandles.p = v9;
          UFG::BulletManager::smSettingsHandles.capacity = v0;
        }
      }
      UFG::BulletManager::smSettingsHandles.size = v5;
    }
    v12 = 0;
    if ( v5 )
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
          v17 = v16->mUID;
        else
          v17 = 0;
        v18 = UFG::BulletManager::smSettingsHandles.p;
        v19 = UFG::BulletManager::smSettingsHandles.p[v13];
        if ( v19->mData )
        {
          v20 = `UFG::qGetResourceInventory<Render::BeamSettings>'::`2'::result;
          if ( !`UFG::qGetResourceInventory<Render::BeamSettings>'::`2'::result )
          {
            v21 = UFG::qResourceWarehouse::Instance();
            v20 = UFG::qResourceWarehouse::GetInventory(v21, 0xA0AAE10F);
            `UFG::qGetResourceInventory<Render::BeamSettings>'::`2'::result = v20;
          }
          UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v19->mPrev, v20);
          v18 = UFG::BulletManager::smSettingsHandles.p;
        }
        v22 = (UFG::qResourceHandle *)&v18[v13]->mPrev;
        v23 = `UFG::qGetResourceInventory<Render::BeamSettings>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<Render::BeamSettings>'::`2'::result )
        {
          v24 = UFG::qResourceWarehouse::Instance();
          v23 = UFG::qResourceWarehouse::GetInventory(v24, 0xA0AAE10F);
          `UFG::qGetResourceInventory<Render::BeamSettings>'::`2'::result = v23;
        }
        UFG::qResourceHandle::Init(v22, 0xA0AAE10F, v17, v23);
        ++v12;
        ++v13;
      }
      while ( v12 < v5 );
    }
  }
}

// File Line: 161
// RVA: 0x44CC90
void __fastcall UFG::ProjectileInfo::ProjectileInfo(UFG::ProjectileInfo *this, UFG::SimObjectWeaponPropertiesComponent *pSOWPC, UFG::SubTargetingLocation *pSubTargetingLocation, bool isFullyAccurate, bool isHardLocked)
{
  UFG::ProjectileInfo *v5; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax

  v5 = this;
  this->m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pSOWPC.mPrev;
  this->m_pSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pSOWPC.mPrev;
  this->m_pSOWPC.m_pPointer = 0i64;
  this->m_pSubTargetingLocation = pSubTargetingLocation;
  this->m_bIsFullyAccurate = isFullyAccurate;
  this->m_bIsHardLocked = isHardLocked;
  if ( this->m_pSOWPC.m_pPointer )
  {
    v6 = this->m_pSOWPC.mPrev;
    v7 = v5->m_pSOWPC.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pSOWPC.mPrev;
    v5->m_pSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pSOWPC.mPrev;
  }
  v5->m_pSOWPC.m_pPointer = (UFG::SimComponent *)&pSOWPC->vfptr;
  if ( pSOWPC )
  {
    v8 = pSOWPC->m_SafePointerList.mNode.mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pSOWPC.mPrev;
    v5->m_pSOWPC.mPrev = v8;
    v5->m_pSOWPC.mNext = &pSOWPC->m_SafePointerList.mNode;
    pSOWPC->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pSOWPC.mPrev;
  }
}

// File Line: 205
// RVA: 0x448500
void __fastcall UFG::Bullet::Bullet(UFG::Bullet *this, UFG::SimObject *pWeaponOwnerSimObject, UFG::qVector3 *p, UFG::qVector3 *v, float projectileGravity, float armingDistance, bool posIsObscured, UFG::qVector3 *unobscuredPos, UFG::qColour *tracerColour, UFG::qColour *tracerTrailColour, Render::BeamSettingsHandle *in_tracerSettingsHandle, Render::BeamSettingsHandle *in_tracerTrailSettingsHandle, UFG::ProjectileInfo *pi, bool isNetworkProxy_, bool showTracer_, UFG::eTargetTypeEnum eMustHitTarget)
{
  UFG::SimObject *v16; // r11
  UFG::Bullet *v17; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v18; // r10
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v19; // rdi
  UFG::ProjectileInfo *v20; // rdx
  UFG::SimComponent *v21; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  __m128 v32; // xmm1
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::SimObjectGame *v36; // rcx
  unsigned __int16 v37; // dx
  UFG::SimComponent *v38; // r8
  UFG::SimComponent *v39; // rax
  UFG::SimObject *v40; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v42; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v43; // rax
  UFG::SimObjectWeaponPropertiesComponent *v44; // rax
  UFG::qMemoryPool *v45; // rax
  UFG::allocator::free_link *v46; // rdi
  unsigned int v47; // eax
  UFG::TransformNodeComponent *v48; // rax
  UFG::TransformNodeComponent *v49; // r8

  v16 = pWeaponOwnerSimObject;
  v17 = this;
  this->mPrev = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)&this->mPrev;
  v18 = &this->weaponOwnerSimObject;
  v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  this->weaponOwnerSimObject.m_pPointer = 0i64;
  v19 = &this->mustHitSimObject;
  v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
  v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
  this->mustHitSimObject.m_pPointer = 0i64;
  v20 = &this->projectileInfo;
  v20->m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->m_pSOWPC.mPrev;
  v20->m_pSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->m_pSOWPC.mPrev;
  v21 = pi->m_pSOWPC.m_pPointer;
  v20->m_pSOWPC.m_pPointer = v21;
  if ( v21 )
  {
    v22 = &v21->m_SafePointerList;
    v23 = v22->mNode.mPrev;
    v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->m_pSOWPC.mPrev;
    v20->m_pSOWPC.mPrev = v23;
    v20->m_pSOWPC.mNext = &v22->mNode;
    v22->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->m_pSOWPC.mPrev;
  }
  v20->m_pSubTargetingLocation = pi->m_pSubTargetingLocation;
  v20->m_bIsFullyAccurate = pi->m_bIsFullyAccurate;
  v20->m_bIsHardLocked = pi->m_bIsHardLocked;
  v17->oneShot.m_pOneShot = 0i64;
  v17->transformNodeComponent = 0i64;
  v17->tracerSettingsHandle = in_tracerSettingsHandle;
  v17->tracerTrailSettingsHandle = in_tracerTrailSettingsHandle;
  v24 = p->y;
  v25 = p->z;
  v17->pos_t0.x = p->x;
  v17->pos_t0.y = v24;
  v17->pos_t0.z = v25;
  v26 = p->y;
  v27 = p->z;
  v17->pos_t1.x = p->x;
  v17->pos_t1.y = v26;
  v17->pos_t1.z = v27;
  v28 = p->y;
  v29 = p->z;
  v17->pos_launch.x = p->x;
  v17->pos_launch.y = v28;
  v17->pos_launch.z = v29;
  v30 = v->y;
  v31 = v->z;
  v17->vel.x = v->x;
  v17->vel.y = v30;
  v17->vel.z = v31;
  v17->tracerColour.r = tracerColour->r;
  v17->tracerColour.g = tracerColour->g;
  v17->tracerColour.b = tracerColour->b;
  v17->tracerColour.a = tracerColour->a;
  v17->tracerTrailColour.r = tracerTrailColour->r;
  v17->tracerTrailColour.g = tracerTrailColour->g;
  v17->tracerTrailColour.b = tracerTrailColour->b;
  v17->tracerTrailColour.a = tracerTrailColour->a;
  v17->mProjectileGravity = projectileGravity;
  v17->mArmingDistance = armingDistance;
  v17->mDistanceTraveled = 0.0;
  v17->age = 0.0;
  v17->grenadeEffectID = 0;
  v17->mustHitTarget = eMustHitTarget;
  *((_BYTE *)v17 + 248) &= 0xE0u;
  *((_BYTE *)v17 + 248) |= 2 * (isNetworkProxy_ | 2 * (showTracer_ | 8));
  if ( posIsObscured )
  {
    v32 = (__m128)LODWORD(unobscuredPos->y);
    v32.m128_f32[0] = (float)((float)((float)(v32.m128_f32[0] - p->y) * (float)(v32.m128_f32[0] - p->y))
                            + (float)((float)(unobscuredPos->x - p->x) * (float)(unobscuredPos->x - p->x)))
                    + (float)((float)(unobscuredPos->z - p->z) * (float)(unobscuredPos->z - p->z));
    LODWORD(v17->mObscuredLength) = (unsigned __int128)_mm_sqrt_ps(v32);
  }
  else
  {
    v17->mObscuredLength = 0.0;
  }
  if ( v18->m_pPointer )
  {
    v33 = v18->mPrev;
    v34 = v18->mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
    v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  }
  v18->m_pPointer = v16;
  if ( v16 )
  {
    v35 = v16->m_SafePointerList.mNode.mPrev;
    v35->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
    v18->mPrev = v35;
    v18->mNext = &v16->m_SafePointerList.mNode;
    v16->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  }
  v17->mLifeSpan = *(float *)(*((_QWORD *)&pi->m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                              + HIDWORD(pi->m_pSOWPC.m_pPointer[2].m_pSimObject))
                            + 112i64);
  v36 = (UFG::SimObjectGame *)v17->weaponOwnerSimObject.m_pPointer;
  if ( v36
    && ((v37 = v36->m_Flags, !((v37 >> 14) & 1)) ? ((v37 & 0x8000u) == 0 ? (!((v37 >> 13) & 1) ? (!((v37 >> 12) & 1) ? (v39 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v36->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v39 = UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v39 = UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                            v38 = v39) : (v38 = v36->m_Components.p[20].m_pComponent)) : (v38 = v36->m_Components.p[20].m_pComponent),
        v38) )
  {
    v40 = *(UFG::SimObject **)(56i64
                             * *(unsigned __int8 *)(*(_QWORD *)&v38[1].m_Flags + (unsigned int)v17->mustHitTarget + 8i64)
                             + *(_QWORD *)&v38[1].m_TypeUID
                             + 40);
  }
  else
  {
    v40 = 0i64;
  }
  if ( v19->m_pPointer )
  {
    v41 = v19->mPrev;
    v42 = v19->mNext;
    v41->mNext = v42;
    v42->mPrev = v41;
    v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
    v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
  }
  v19->m_pPointer = v40;
  if ( v40 )
  {
    v43 = v40->m_SafePointerList.mNode.mPrev;
    v43->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
    v19->mPrev = v43;
    v19->mNext = &v40->m_SafePointerList.mNode;
    v40->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
  }
  v44 = (UFG::SimObjectWeaponPropertiesComponent *)v17->projectileInfo.m_pSOWPC.m_pPointer;
  if ( v44 && v44->mWeaponTypeInfo->mFireModes[v44->mFireMode]->mExplosionType.mUID != -1 )
  {
    v45 = UFG::GetSimulationMemoryPool();
    v46 = UFG::qMemoryPool::Allocate(v45, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
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
    v17->transformNodeComponent = v49;
    v17->grenadeEffectID = Render::FXManager::CreateEffect(
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
  UFG::Bullet *v1; // rbx
  UFG::SimComponent *v2; // rax
  UFG::ProjectileInfo *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v18; // rcx
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v19; // rax

  v1 = this;
  v2 = this->projectileInfo.m_pSOWPC.m_pPointer;
  if ( v2
    && *(_DWORD *)(*((_QWORD *)&v2[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v2[2].m_pSimObject)) + 108i64) != -1
    && this->transformNodeComponent )
  {
    UFG::Bullet::Explode(this);
  }
  if ( UFG::OneShotHandle::IsValid(&v1->oneShot) )
    UFG::OneShot::Stop(v1->oneShot.m_pOneShot, 0x32u, 0);
  UFG::OneShotHandle::Release(&v1->oneShot);
  v3 = &v1->projectileInfo;
  if ( v1->projectileInfo.m_pSOWPC.m_pPointer )
  {
    v4 = v3->m_pSOWPC.mPrev;
    v5 = v1->projectileInfo.m_pSOWPC.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pSOWPC.mPrev;
    v1->projectileInfo.m_pSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->projectileInfo.m_pSOWPC.mPrev;
  }
  v1->projectileInfo.m_pSOWPC.m_pPointer = 0i64;
  v6 = v3->m_pSOWPC.mPrev;
  v7 = v1->projectileInfo.m_pSOWPC.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v3->m_pSOWPC.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pSOWPC.mPrev;
  v1->projectileInfo.m_pSOWPC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->projectileInfo.m_pSOWPC.mPrev;
  v8 = &v1->mustHitSimObject;
  if ( v1->mustHitSimObject.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v1->mustHitSimObject.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v1->mustHitSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mustHitSimObject.mPrev;
  }
  v1->mustHitSimObject.m_pPointer = 0i64;
  v11 = v8->mPrev;
  v12 = v1->mustHitSimObject.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v1->mustHitSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mustHitSimObject.mPrev;
  v13 = &v1->weaponOwnerSimObject;
  if ( v1->weaponOwnerSimObject.m_pPointer )
  {
    v14 = v13->mPrev;
    v15 = v1->weaponOwnerSimObject.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v1->weaponOwnerSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->weaponOwnerSimObject.mPrev;
  }
  v1->weaponOwnerSimObject.m_pPointer = 0i64;
  v16 = v13->mPrev;
  v17 = v1->weaponOwnerSimObject.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v1->weaponOwnerSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->weaponOwnerSimObject.mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v1->mPrev = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)&v1->mPrev;
}

// File Line: 249
// RVA: 0x463E40
void __fastcall UFG::Bullet::Explode(UFG::Bullet *this)
{
  UFG::Bullet *v1; // rbp
  UFG::SimObjectWeaponPropertiesComponent *v2; // rbx
  UFG::SimObject *v3; // rsi
  UFG::TransformNodeComponent *v4; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( this->grenadeEffectID )
  {
    v2 = (UFG::SimObjectWeaponPropertiesComponent *)this->projectileInfo.m_pSOWPC.m_pPointer;
    v3 = this->weaponOwnerSimObject.m_pPointer;
    v4 = this->transformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(this->transformNodeComponent);
    v5 = UFG::SimObjectWeaponPropertiesComponent::GetExplosionType(v2, &result);
    UFG::ExplosionManager::CreateExplosion((UFG::qVector3 *)&v4->mWorldTransform.v3, v5, v3, v3);
    Render::FXManager::KillEffect(&Render::gFXManager, v1->grenadeEffectID, 0);
    v1->transformNodeComponent = 0i64;
    v1->grenadeEffectID = 0;
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
  UFG::Bullet *v1; // rdi
  UFG::SimComponent *v2; // rax

  v1 = this;
  UFG::OneShotPool::GetOneShotHandle(&this->oneShot, &this->pos_t0);
  if ( UFG::OneShotHandle::IsValid(&v1->oneShot) )
  {
    v2 = v1->projectileInfo.m_pSOWPC.m_pPointer;
    if ( v2 )
      UFG::AudioEntity::SetWwiseSwitch(
        (UFG::AudioEntity *)&v1->oneShot.m_pOneShot->vfptr,
        weapon_type_uid,
        *(_DWORD *)(*((_QWORD *)&v2[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v2[2].m_pSimObject)) + 248i64));
    UFG::OneShot::Play(v1->oneShot.m_pOneShot, bullet_by_uid);
  }
}

// File Line: 288
// RVA: 0x448A40
void __fastcall UFG::BulletManager::BulletManager(UFG::BulletManager *this)
{
  UFG::qList<UFG::TargetSphere,UFG::TargetSphere,1,0> *v1; // [rsp+58h] [rbp+10h]
  UFG::qList<UFG::Bullet,UFG::Bullet,1,0> *v2; // [rsp+58h] [rbp+10h]

  this->vfptr = (UFG::BulletManagerVtbl *)&UFG::BulletManager::`vftable';
  v1 = &this->mTargetSpheres;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
  v2 = &this->mBulletList;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  this->mSimObjectsToIgnore.p = 0i64;
  *(_QWORD *)&this->mSimObjectsToIgnore.size = 0i64;
  UFG::qFixedAllocator::Init(&UFG::Bullet::mAllocator, 25600, 256, "BulletPool", 0i64);
}

// File Line: 300
// RVA: 0x44F830
void __fastcall UFG::BulletManager::~BulletManager(UFG::BulletManager *this)
{
  UFG::BulletManager *v1; // rdi
  UFG::BulletManager *v2; // r8
  UFG::BulletManager *v3; // rax
  UFG::BulletManagerVtbl *v4; // rdx
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v5; // rcx
  UFG::qList<UFG::Bullet,UFG::Bullet,1,0> *v6; // rsi
  UFG::qSymbol *v7; // rcx
  UFG::qSymbol *v8; // rbx
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v9; // rcx
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v10; // rax
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v11; // rcx
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::BulletManagerVtbl *)&UFG::BulletManager::`vftable';
  v2 = (UFG::BulletManager *)((char *)UFG::BulletManager::mInstance + 8);
  v3 = (UFG::BulletManager *)UFG::BulletManager::mInstance->mTargetSpheres.mNode.mNext;
  if ( v3 != (UFG::BulletManager *)&UFG::BulletManager::mInstance->mTargetSpheres )
  {
    do
    {
      v4 = v3->vfptr;
      v5 = v3->mTargetSpheres.mNode.mPrev;
      v4[1].__vecDelDtor = (void *(__fastcall *)(UFG::BulletManager *, unsigned int))v5;
      v5->mPrev = (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)v4;
      v3->vfptr = (UFG::BulletManagerVtbl *)v3;
      v3->mTargetSpheres.mNode.mPrev = (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)v3;
      v3 = (UFG::BulletManager *)v2->mTargetSpheres.mNode.mPrev;
    }
    while ( v3 != v2 );
  }
  v6 = &v1->mBulletList;
  UFG::qList<UFG::Bullet,UFG::Bullet,1,0>::DeleteNodes(&v1->mBulletList);
  UFG::qFixedAllocator::Close(&UFG::Bullet::mAllocator);
  v7 = v1->mSimObjectsToIgnore.p;
  if ( v7 )
  {
    v8 = v7 - 1;
    `eh vector destructor iterator'(v7, 4ui64, v7[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v8);
  }
  v1->mSimObjectsToIgnore.p = 0i64;
  *(_QWORD *)&v1->mSimObjectsToIgnore.size = 0i64;
  UFG::qList<UFG::Bullet,UFG::Bullet,1,0>::DeleteNodes(&v1->mBulletList);
  v9 = v6->mNode.mPrev;
  v10 = v1->mBulletList.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mNode.mPrev = &v6->mNode;
  v1->mBulletList.mNode.mNext = &v1->mBulletList.mNode;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->mTargetSpheres);
  v11 = v1->mTargetSpheres.mNode.mPrev;
  v12 = v1->mTargetSpheres.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v1->mTargetSpheres.mNode.mPrev = &v1->mTargetSpheres.mNode;
  v1->mTargetSpheres.mNode.mNext = &v1->mTargetSpheres.mNode;
}

// File Line: 327
// RVA: 0x4649A0
void __fastcall UFG::BulletManager::FireBullet(UFG::BulletManager *this, UFG::SimObject *pWeaponOwnerSimObject, UFG::qVector3 *muzzleDir, UFG::qVector3 *pos, UFG::qVector3 *vel, float projectileGravity, float armingDistance, bool posIsObscured, UFG::qVector3 *unobscuredPos, UFG::ProjectileInfo *pi, bool showTracer, bool isNetworkProxy, UFG::eTargetTypeEnum eMustHitTarget)
{
  UFG::qVector3 *v13; // rbx
  UFG::qVector3 *v14; // rsi
  UFG::SimObject *v15; // rdi
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm10_4
  float v19; // xmm12_4
  float v20; // xmm11_4
  unsigned __int16 v21; // cx
  UFG::SimComponent *v22; // rax
  float v23; // xmm5_4
  __m128 v24; // xmm3
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
  bool v35; // r14
  float *v36; // rsi
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
  char *v47; // rsi
  unsigned int v48; // eax
  float v49; // xmm11_4
  float v50; // xmm12_4
  __int64 v51; // rax
  UFG::GameStatTracker *v52; // rax
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v53; // rax
  UFG::qVector3 p; // [rsp+88h] [rbp-F0h]
  UFG::qVector3 v; // [rsp+98h] [rbp-E0h]
  UFG::qColour tracerTrailColour; // [rsp+A8h] [rbp-D0h]
  UFG::qColour tracerColour; // [rsp+B8h] [rbp-C0h]
  UFG::BulletManager *v58; // [rsp+180h] [rbp+8h]

  v58 = this;
  v13 = pos;
  v14 = muzzleDir;
  v15 = pWeaponOwnerSimObject;
  v16 = pos->y;
  v17 = pos->z;
  p.x = pos->x;
  p.y = v16;
  p.z = v17;
  v18 = UFG::qVector3::msZero.x;
  v19 = UFG::qVector3::msZero.y;
  v20 = UFG::qVector3::msZero.z;
  if ( pWeaponOwnerSimObject )
  {
    v21 = pWeaponOwnerSimObject->m_Flags;
    if ( (v21 >> 14) & 1 )
    {
      v22 = pWeaponOwnerSimObject->m_Components.p[44].m_pComponent;
    }
    else if ( (v21 & 0x8000u) == 0 )
    {
      if ( (v21 >> 13) & 1 )
        v22 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)pWeaponOwnerSimObject,
                UFG::CharacterOccupantComponent::_TypeUID);
      else
        v22 = (v21 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                  (UFG::SimObjectGame *)pWeaponOwnerSimObject,
                                  UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                 pWeaponOwnerSimObject,
                                                                                 UFG::CharacterOccupantComponent::_TypeUID);
    }
    else
    {
      v22 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)pWeaponOwnerSimObject,
              UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v22 )
    {
      v23 = vel->y;
      v24 = (__m128)LODWORD(vel->x);
      v25 = vel->z;
      v26 = v24;
      v26.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v23 * v23)) + (float)(v25 * v25);
      if ( v26.m128_f32[0] == 0.0 )
        v27 = 0.0;
      else
        v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
      v28 = (float)((float)(v25 * v27) * s_fOriginOffset) + v13->z;
      v29 = (float)((float)(v23 * v27) * s_fOriginOffset) + v13->y;
      p.x = (float)((float)(v24.m128_f32[0] * v27) * s_fOriginOffset) + v13->x;
      p.y = v29;
      p.z = v28;
    }
  }
  if ( !(_S7_12 & 1) )
  {
    _S7_12 |= 1u;
    s_fMuzzleShotToleranceRad = FLOAT_0_78539819;
  }
  v30 = UFG::qAngleBetween(v14, vel);
  showTracer_ = showTracer && v30 <= s_fMuzzleShotToleranceRad;
  v32 = 0i64;
  in_tracerSettingsHandle = 0i64;
  in_tracerTrailSettingsHandle = 0i64;
  if ( showTracer_ && pi->m_pSOWPC.m_pPointer )
  {
    v35 = UFG::IsAnyLocalPlayer(v15);
    if ( v35 )
      in_tracerSettingsHandle = *(Render::BeamSettingsHandle **)(*((_QWORD *)&pi->m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                                                 + HIDWORD(pi->m_pSOWPC.m_pPointer[2].m_pSimObject))
                                                               + 0xD8i64);
    else
      in_tracerSettingsHandle = *(Render::BeamSettingsHandle **)(*((_QWORD *)&pi->m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                                                 + HIDWORD(pi->m_pSOWPC.m_pPointer[2].m_pSimObject))
                                                               + 224i64);
    if ( in_tracerSettingsHandle )
    {
      v36 = (float *)in_tracerSettingsHandle->mData;
      if ( v36 )
      {
        v37 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
        v38 = (float)((float)(v36[29] - v36[25]) * v37) + v36[25];
        v39 = (float)((float)(v36[28] - v36[24]) * v37) + v36[24];
        v40 = (float)((float)(v36[27] - v36[23]) * v37) + v36[23];
        tracerColour.r = (float)((float)(v36[26] - v36[22]) * v37) + v36[22];
        tracerColour.g = v40;
        tracerColour.b = v39;
        tracerColour.a = v38;
      }
    }
    v41 = *((_QWORD *)&pi->m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
          + HIDWORD(pi->m_pSOWPC.m_pPointer[2].m_pSimObject));
    if ( v35 )
      in_tracerTrailSettingsHandle = *(Render::BeamSettingsHandle **)(v41 + 232);
    else
      in_tracerTrailSettingsHandle = *(Render::BeamSettingsHandle **)(v41 + 240);
    if ( in_tracerTrailSettingsHandle )
    {
      v42 = (float *)in_tracerTrailSettingsHandle->mData;
      if ( v42 )
      {
        v43 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
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
  v47 = UFG::Bullet::mAllocator.mFreeListHead;
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
  if ( v47 )
  {
    v49 = v20 + vel->z;
    v50 = v19 + vel->y;
    v.x = v18 + vel->x;
    v.y = v50;
    v.z = v49;
    UFG::Bullet::Bullet(
      (UFG::Bullet *)v47,
      v15,
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
    if ( UFG::IsAnyLocalPlayer(v15) )
    {
      v52 = UFG::GameStatTracker::Instance();
      if ( UFG::GameStatTracker::GetStat(v52, Sharpshooter_Activated) > 0.0 )
        *(_BYTE *)(v32 + 248) |= 1u;
    }
    if ( !UFG::IsAnyLocalPlayer(v15) )
      UFG::Bullet::PlayBulletBy((UFG::Bullet *)v32);
    v53 = v58->mBulletList.mNode.mPrev;
    v53->mNext = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)v32;
    *(_QWORD *)v32 = v53;
    *(_QWORD *)(v32 + 8) = (char *)v58 + 24;
    v58->mBulletList.mNode.mPrev = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)v32;
  }
}char *)v58 + 24;
    v58->mBulletList.mNode.mPrev = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)v32;
  }
}

// File Line: 442
// RVA: 0x4701D0
void __fastcall UFG::BulletManager::PreRayCastUpdate(UFG::BulletManager *this, float deltaT)
{
  float *v2; // rbx
  float *v3; // rsi
  float v4; // xmm8_4
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::AimingBaseComponent *v7; // rax
  UFG::eTargetTypeEnum v8; // er8
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
  UFG::qVector3 vTargetNormalAimPosition; // [rsp+40h] [rbp-78h]
  float v33; // [rsp+50h] [rbp-68h]
  float v34; // [rsp+54h] [rbp-64h]
  float v35; // [rsp+58h] [rbp-60h]

  v2 = (float *)this->mBulletList.mNode.mNext;
  v3 = (float *)&this->mBulletList;
  v4 = deltaT;
  if ( v2 != (float *)&this->mBulletList )
  {
    do
    {
      if ( *((_DWORD *)v2 + 61) )
      {
        v5 = (UFG::SimObjectGame *)*((_QWORD *)v2 + 4);
        if ( v5 )
        {
          v6 = v5->m_Flags;
          if ( (v6 >> 14) & 1 )
          {
            v7 = (UFG::AimingBaseComponent *)v5->m_Components.p[47].m_pComponent;
          }
          else if ( (v6 & 0x8000u) == 0 )
          {
            if ( (v6 >> 13) & 1 )
              v7 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v5,
                                                 UFG::AimingBaseComponent::_TypeUID);
            else
              v7 = (UFG::AimingBaseComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v5,
                                                                   UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::AimingBaseComponent::_TypeUID));
          }
          else
          {
            v7 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v5,
                                               UFG::AimingBaseComponent::_TypeUID);
          }
          if ( v7 )
          {
            v8 = *((_DWORD *)v2 + 61);
            vTargetNormalAimPosition = UFG::qVector3::msZero;
            UFG::AimingBaseComponent::GetTargetNormalAimPosition(v7, &vTargetNormalAimPosition, v8, 0i64);
            v9 = (__m128)*((unsigned int *)v2 + 43);
            v10 = vTargetNormalAimPosition.z - v2[39];
            v9.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v2[44] * v2[44]))
                           + (float)(v2[45] * v2[45]);
            v11 = vTargetNormalAimPosition.y - v2[38];
            v2[43] = vTargetNormalAimPosition.x - v2[37];
            v2[44] = v11;
            v2[45] = v10;
            LODWORD(v12) = (unsigned __int128)_mm_sqrt_ps(v9);
            v13 = v12 * v2[45];
            v14 = v12 * v2[43];
            v15 = v12 * v2[44];
            v2[45] = v13;
            v2[43] = v14;
            v2[44] = v15;
          }
        }
      }
      else
      {
        v2[45] = v2[45] - (float)(v4 * v2[54]);
      }
      v16 = (UFG::qVector3 *)(v2 + 37);
      v17 = *((_DWORD *)v2 + 38);
      v18 = *((_DWORD *)v2 + 39);
      v2[34] = v2[37];
      *((_DWORD *)v2 + 36) = v18;
      *((_DWORD *)v2 + 35) = v17;
      v19 = (float)(v4 * v2[43]) + v2[37];
      v20 = (float)(v4 * v2[44]) + v2[38];
      v21 = (float)(v4 * v2[45]) + v2[39];
      v16->x = v19;
      v16->y = v20;
      v16->z = v21;
      v23 = v2[35];
      v24 = v2[36];
      v33 = v2[34];
      v22 = v33;
      v34 = v23;
      v35 = v24;
      v25 = fsqrt(
              (float)((float)((float)(v20 - v23) * (float)(v20 - v23)) + (float)((float)(v19 - v22) * (float)(v19 - v22)))
            + (float)((float)(v21 - v24) * (float)(v21 - v24)));
      v26 = v2[59] - v25;
      v2[59] = v26;
      if ( v26 <= 0.0
        && (v26 >= 0.0
         || (LODWORD(v27) = LODWORD(v26) & _xmm, v27 >= v25)
         || (v28 = 1.0 - (float)(v27 / v25),
             v29 = (float)(v2[39] - v24) * v28,
             v30 = v23 + (float)((float)(v2[38] - v23) * v28),
             v33 = v22 + (float)((float)(v16->x - v22) * v28),
             v34 = v30,
             v35 = v24 + v29,
             v28 < 1.0))
        || v2[54] > 0.0 )
      {
        if ( !UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay(
                UFG::BasePhysicsSystem::mInstance,
                (UFG::qVector3 *)&v33,
                v16,
                0x19u,
                (void (__fastcall *)(UFG::RayCastData *, UFG::SimComponent *, void *))UFG::BulletManager::AsyncRayCallback,
                0i64,
                v2) )
        {
          v31 = (UFG::Bullet *)v2;
          v2 = *(float **)v2;
          if ( v31 )
          {
            UFG::Bullet::~Bullet(v31);
            v31->mPrev = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)UFG::Bullet::mAllocator.mFreeListHead;
            --UFG::Bullet::mAllocator.mNumSlotsAllocated;
            UFG::Bullet::mAllocator.mFreeListHead = (char *)v31;
          }
        }
      }
      v2 = (float *)*((_QWORD *)v2 + 1);
    }
    while ( v2 != v3 );
  }
}

// File Line: 525
// RVA: 0x4588F0
void __fastcall UFG::BulletManager::AsyncRayCallback(UFG::RayCastData *ray, UFG::SimComponent *__formal, UFG::Bullet *callbackUserData)
{
  UFG::Bullet *v3; // rbx
  UFG::RayCastData *v4; // rdi
  float v5; // xmm10_4
  float v6; // xmm11_4
  float v7; // xmm12_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  UFG::SimObjectGame *v11; // rsi
  UFG::TargetSphere *v12; // r14
  float v13; // xmm6_4
  float v14; // xmm9_4
  float v15; // xmm8_4
  float v16; // xmm7_4
  UFG::allocator::free_link *v17; // rax
  __int64 v18; // rax
  __int64 v19; // rbp
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rdx
  UFG::SimObject *v21; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  float v25; // xmm1_4
  float v26; // xmm2_4
  UFG::HavokUserData *v27; // r14
  void *v28; // rax
  UFG::SimComponent *v29; // rsi
  char v30; // bp
  UFG::SimObjectCharacter *v31; // r15
  float v32; // xmm3_4
  __m128 v33; // xmm4
  float v34; // xmm5_4
  __m128 v35; // xmm2
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  UFG::SimObjectGame *v39; // rax
  unsigned int v40; // edx
  unsigned int v41; // er8
  char v42; // cl
  unsigned __int16 v43; // cx
  UFG::SimComponent *v44; // rax
  float v45; // xmm0_4
  float v46; // xmm6_4
  float v47; // xmm5_4
  char v48; // si
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v49; // rcx
  const char *v50; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v51; // rcx
  const char *v52; // rax
  UFG::qReflectObject *v53; // rdx
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
  __m128 v66; // xmm3
  float v67; // xmm5_4
  __m128 v68; // xmm2
  float v69; // xmm0_4
  float v70; // xmm3_4
  float v71; // xmm1_4
  float v72; // xmm2_4
  float v73; // xmm1_4
  UFG::qReflectHandleBase v74; // [rsp+38h] [rbp-F0h]
  UFG::qReflectHandleBase v75; // [rsp+60h] [rbp-C8h]
  float t; // [rsp+140h] [rbp+18h]

  v3 = callbackUserData;
  v4 = ray;
  if ( !callbackUserData->weaponOwnerSimObject.m_pPointer )
  {
    *((_BYTE *)callbackUserData + 248) |= 8u;
    return;
  }
  v5 = callbackUserData->pos_t0.x;
  v6 = callbackUserData->pos_t0.y;
  v7 = callbackUserData->pos_t0.z;
  v8 = callbackUserData->pos_t1.x;
  v9 = callbackUserData->pos_t1.y;
  v10 = callbackUserData->pos_t1.z;
  v11 = 0i64;
  t = FLOAT_N1_0;
  v12 = UFG::BulletManager::TestAgainstTargetSpheres(UFG::BulletManager::mInstance, callbackUserData, &t);
  if ( !v12 )
    goto LABEL_89;
  v13 = t;
  if ( !v4->hit || t < v4->t )
  {
    v14 = (float)((float)(v10 - v7) * t) + v7;
    v15 = (float)((float)(v9 - v6) * t) + v6;
    v16 = (float)((float)(v8 - v5) * t) + v5;
    v17 = UFG::qMalloc(0xA0ui64, "BulletImpactDamageSphereEvent", 0i64);
    *(_QWORD *)&t = v17;
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
    v21 = v3->weaponOwnerSimObject.m_pPointer;
    if ( *(_QWORD *)(v19 + 72) )
    {
      v22 = v20->mPrev;
      v23 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v19 + 64);
      v22->mNext = v23;
      v23->mPrev = v22;
      v20->mPrev = v20;
      *(_QWORD *)(v19 + 64) = v19 + 56;
    }
    *(_QWORD *)(v19 + 72) = v21;
    if ( v21 )
    {
      v24 = v21->m_SafePointerList.mNode.mPrev;
      v24->mNext = v20;
      v20->mPrev = v24;
      *(_QWORD *)(v19 + 64) = (char *)v21 + 8;
      v21->m_SafePointerList.mNode.mPrev = v20;
    }
    UFG::ProjectileInfo::operator=((UFG::ProjectileInfo *)(v19 + 80), &v3->projectileInfo);
    v25 = v3->vel.y;
    v26 = v3->vel.z;
    *(float *)(v19 + 120) = v3->vel.x;
    *(float *)(v19 + 124) = v25;
    *(float *)(v19 + 128) = v26;
    *(float *)(v19 + 132) = v16;
    *(float *)(v19 + 136) = v15;
    *(float *)(v19 + 140) = v14;
    *(_QWORD *)(v19 + 144) = 0i64;
    UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v19);
    *((_BYTE *)v3 + 248) |= 0x10u;
  }
  if ( v4->hit && v13 > v4->t )
  {
LABEL_89:
    v27 = 0i64;
    if ( v4->hit )
    {
      v28 = v4->mHavokRigidBody;
      if ( v28 || (v28 = v4->mHavokPhantom) != 0i64 )
      {
        v27 = (UFG::HavokUserData *)*((_QWORD *)v28 + 3);
        if ( v27 )
        {
          v29 = v27->simComponent.m_pPointer;
          if ( v29 )
            v11 = (UFG::SimObjectGame *)v29->m_pSimObject;
          else
            v11 = 0i64;
        }
      }
      v30 = 1;
      v31 = (UFG::SimObjectCharacter *)v3->weaponOwnerSimObject.m_pPointer;
      if ( v11 == (UFG::SimObjectGame *)v31 )
      {
        v32 = v3->vel.x;
        v33 = (__m128)LODWORD(v3->vel.y);
        v34 = v3->vel.z;
        v35 = v33;
        v35.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32)) + (float)(v34 * v34);
        if ( v35.m128_f32[0] == 0.0 )
          v36 = 0.0;
        else
          v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
        v37 = (float)((float)(v36 * v34) * 0.0099999998) + v4->point.z;
        v38 = (float)((float)(v36 * v33.m128_f32[0]) * 0.0099999998) + v4->point.y;
        v3->pos_t1.x = (float)((float)(v36 * v32) * 0.0099999998) + v4->point.x;
        v3->pos_t1.y = v38;
        v3->pos_t1.z = v37;
        v30 = 0;
      }
      else if ( v31 == UFG::GetLocalPlayer()
             || !UFG::AreCharactersAllied((UFG::SimObject *)&v11->vfptr, v3->weaponOwnerSimObject.m_pPointer)
             || UFG::IsHostage((UFG::SimObject *)&v11->vfptr) )
      {
        v39 = (UFG::SimObjectGame *)v3->mustHitSimObject.m_pPointer;
        if ( v39 )
        {
          v30 = 1;
          if ( v39 != v11 )
            v30 = 0;
        }
      }
      else
      {
        v30 = 0;
        *((_BYTE *)v3 + 248) |= 0x10u;
      }
      v40 = 0;
      v41 = UFG::BulletManager::mInstance->mSimObjectsToIgnore.size;
      if ( v41 )
      {
        do
        {
          v42 = v30;
          if ( UFG::BulletManager::mInstance->mSimObjectsToIgnore.p[v40].mUID == v11->m_Name.mUID )
            v42 = 0;
          v30 = v42;
          ++v40;
        }
        while ( v40 < v41 );
      }
      if ( v11 )
      {
        v43 = v11->m_Flags;
        if ( (v43 >> 14) & 1 )
        {
          v44 = v11->m_Components.p[6].m_pComponent;
        }
        else if ( (v43 & 0x8000u) == 0 )
        {
          if ( (v43 >> 13) & 1 )
            v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::HealthComponent::_TypeUID);
          else
            v44 = (v43 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          v44 = v11->m_Components.p[6].m_pComponent;
        }
        if ( v44 && BYTE5(v44[1].m_BoundComponentHandles.mNode.mPrev) )
        {
          *((_BYTE *)v3 + 248) |= 0x10u;
          return;
        }
      }
      if ( v30 )
      {
        v45 = v4->t;
        v46 = (float)((float)(v4->mInput.m_to.m_quad.m128_f32[2] - v4->mInput.m_from.m_quad.m128_f32[2]) * v45)
            + v4->mInput.m_from.m_quad.m128_f32[2];
        v47 = (float)((float)(v4->mInput.m_to.m_quad.m128_f32[1] - v4->mInput.m_from.m_quad.m128_f32[1]) * v45)
            + v4->mInput.m_from.m_quad.m128_f32[1];
        v3->pos_t1.x = (float)((float)(v4->mInput.m_to.m_quad.m128_f32[0] - v4->mInput.m_from.m_quad.m128_f32[0]) * v45)
                     + v4->mInput.m_from.m_quad.m128_f32[0];
        v3->pos_t1.y = v47;
        v3->pos_t1.z = v46;
        if ( (v4->mHavokRigidBody || v4->mHavokPhantom) && v27 )
        {
          if ( (unsigned __int8)UFG::BulletManager::ApplyDamage(UFG::BulletManager::mInstance, v3, v4, v27) )
            UFG::BulletManager::ApplyBulletImpactImpulse(UFG::BulletManager::mInstance, v3, v4, v27);
          UFG::BulletManager::SendBulletImpactEvent(
            UFG::BulletManager::mInstance,
            (UFG::SimObject *)&v11->vfptr,
            v3->weaponOwnerSimObject.m_pPointer);
          UFG::BulletManager::SendBulletImpactEvent(UFG::BulletManager::mInstance, v3, v4, v27);
        }
        v48 = 1;
        if ( !v4->mPhysicsObjectPropertyHandleUid )
          goto LABEL_88;
        UFG::qReflectHandleBase::qReflectHandleBase(&v75);
        v50 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v49);
        v75.mTypeUID = UFG::qStringHash64(v50, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v75, v75.mTypeUID, v4->mPhysicsObjectPropertyHandleUid);
        if ( !v75.mData )
          UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v75);
        UFG::qReflectHandleBase::qReflectHandleBase(&v74);
        v52 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v51);
        v74.mTypeUID = UFG::qStringHash64(v52, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v74, v74.mTypeUID, v4->mPhysicsSurfacePropertyHandleUid);
        v53 = v74.mData;
        if ( !v74.mData )
        {
          UFG::qReflectHandleBase::operator=(&v74, (UFG::qReflectHandleBase *)&v75.mData[3].mTypeUID);
          v53 = v74.mData;
        }
        v54 = v3->projectileInfo.m_pSOWPC.m_pPointer;
        if ( v54
          && *(_DWORD *)(*((_QWORD *)&v54[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v54[2].m_pSimObject))
                       + 108i64) != -1 )
        {
          v48 = 1;
          if ( BYTE6(v53[1].mBaseNode.mParent) )
            v48 = 0;
        }
        else if ( *(float *)&v53[1].mBaseNode.mUID > 0.0 )
        {
          v55 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
          if ( v55 <= *(float *)&v74.mData[1].mBaseNode.mUID )
            v48 = 0;
        }
        UFG::qReflectHandleBase::~qReflectHandleBase(&v74);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v75);
        if ( v48 )
        {
LABEL_88:
          if ( v4->hit )
          {
            v56 = v3->projectileInfo.m_pSOWPC.m_pPointer;
            if ( v56
              && *(_DWORD *)(*((_QWORD *)&v56[2].m_BoundComponentHandles.mNode.mPrev->mNext
                             + HIDWORD(v56[2].m_pSimObject))
                           + 108i64) != -1 )
            {
              v57 = v3->vel.y;
              v58 = v3->vel.x;
              v59 = v3->vel.z;
              v60 = (float)((float)(v4->normal.y * v57) + (float)(v4->normal.x * v58)) + (float)(v4->normal.z * v59);
              v61 = FLOAT_0_1;
              v62 = (float)((float)(v4->normal.y * v60) * -0.1)
                  + (float)((float)(v57 - (float)(v4->normal.y * v60)) * 0.1);
              v63 = (float)((float)(v4->normal.z * v60) * -0.1)
                  + (float)((float)(v59 - (float)(v4->normal.z * v60)) * 0.1);
              v3->vel.x = (float)((float)(v4->normal.x * v60) * -0.1)
                        + (float)((float)(v58 - (float)(v4->normal.x * v60)) * 0.1);
              v3->vel.y = v62;
              v3->vel.z = v63;
              v64 = *((_BYTE *)v3 + 248);
              if ( v64 & 0x20 && v3->mArmingDistance <= v3->mDistanceTraveled )
                *((_BYTE *)v3 + 248) = v64 | 0x10;
              *((_BYTE *)v3 + 248) &= 0xDFu;
              goto LABEL_82;
            }
            *((_BYTE *)v3 + 248) |= 0x10u;
          }
        }
        v61 = FLOAT_0_1;
LABEL_82:
        v65 = v3->vel.y;
        v66 = (__m128)LODWORD(v3->vel.x);
        v67 = v3->vel.z;
        v68 = v66;
        v68.m128_f32[0] = (float)((float)(v66.m128_f32[0] * v66.m128_f32[0]) + (float)(v65 * v65)) + (float)(v67 * v67);
        LODWORD(v69) = (unsigned __int128)_mm_sqrt_ps(v68);
        if ( v69 <= v61 )
        {
          v71 = UFG::qVector3::msZero.y;
          v72 = UFG::qVector3::msZero.z;
          v3->vel.x = UFG::qVector3::msZero.x;
          v3->vel.y = v71;
          v3->vel.z = v72;
          v3->mProjectileGravity = 0.0;
          v70 = (float)(v4->normal.x * 0.079999998) + v4->point.x;
          v73 = (float)(v4->normal.z * 0.079999998) + v4->point.z;
          v3->pos_t1.y = (float)(v4->normal.y * 0.079999998) + v4->point.y;
          v3->pos_t1.z = v73;
        }
        else
        {
          v70 = (float)(v66.m128_f32[0] * (float)(0.0099999998 / v69)) + v3->pos_t1.x;
          v3->pos_t1.y = (float)(v65 * (float)(0.0099999998 / v69)) + v3->pos_t1.y;
          v3->pos_t1.z = (float)(v67 * (float)(0.0099999998 / v69)) + v3->pos_t1.z;
        }
        v3->pos_t1.x = v70;
        return;
      }
    }
  }
}

// File Line: 749
// RVA: 0x46FB70
void __fastcall UFG::BulletManager::PostRayCastUpdate(UFG::BulletManager *this, float deltaT)
{
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v2; // rbx
  UFG::qList<UFG::Bullet,UFG::Bullet,1,0> *v3; // rsi
  float v4; // xmm15_4
  bool v5; // zf
  __m128 v6; // xmm2
  UFG::TransformNodeComponent *v7; // rcx
  float v8; // xmm11_4
  float v9; // xmm12_4
  float v10; // xmm13_4
  float v11; // xmm4_4
  __m128 v12; // xmm3
  float v13; // xmm5_4
  __m128 v14; // xmm2
  float v15; // xmm1_4
  __m128 v16; // xmm6
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  __m128 v20; // xmm2
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm9_4
  float v24; // xmm2_4
  float v25; // xmm9_4
  float v26; // xmm1_4
  float v27; // xmm10_4
  float v28; // xmm2_4
  float v29; // xmm9_4
  float v30; // xmm6_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm6_4
  float v34; // xmm8_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm1_4
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v38; // rcx
  int v39; // xmm0_4
  int v40; // xmm1_4
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v41; // rax
  float *v42; // rax
  float v43; // xmm8_4
  __m128 v44; // xmm2
  float v45; // xmm6_4
  float v46; // xmm9_4
  float v47; // xmm1_4
  float v48; // xmm4_4
  __m128 v49; // xmm3
  float v50; // xmm5_4
  __m128 v51; // xmm2
  float v52; // xmm6_4
  float v53; // xmm1_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm0_4
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v57; // rax
  UFG::qNode<UFG::Bullet,UFG::Bullet> *v58; // rax
  float v59; // xmm3_4
  float v60; // xmm0_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm0_4
  float v64; // xmm1_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  unsigned __int8 v67; // cl
  float v68; // xmm0_4
  bool v69; // cf
  UFG::Bullet *v70; // rdi
  UFG::qMatrix44 m; // [rsp+20h] [rbp-81h]

  v2 = this->mBulletList.mNode.mNext;
  v3 = &this->mBulletList;
  v4 = deltaT;
  if ( v2 != (UFG::qNode<UFG::Bullet,UFG::Bullet> *)&this->mBulletList )
  {
    do
    {
      v5 = ((_QWORD)v2[15].mNext & 4) == 0;
      v6 = (__m128)HIDWORD(v2[10].mNext);
      v6.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0])
                             + (float)(*(float *)&v2[11].mPrev * *(float *)&v2[11].mPrev))
                     + (float)(*((float *)&v2[11].mPrev + 1) * *((float *)&v2[11].mPrev + 1));
      *(float *)&v2[14].mPrev = (float)(COERCE_FLOAT(_mm_sqrt_ps(v6)) * v4) + *(float *)&v2[14].mPrev;
      if ( !v5 )
      {
        v7 = (UFG::TransformNodeComponent *)v2[7].mPrev;
        v8 = *((float *)&v2[9].mPrev + 1);
        v9 = *(float *)&v2[9].mNext;
        v10 = *((float *)&v2[9].mNext + 1);
        if ( v7 )
        {
          v11 = *(float *)&v2[11].mPrev;
          v12 = (__m128)HIDWORD(v2[10].mNext);
          v13 = *((float *)&v2[11].mPrev + 1);
          v14 = v12;
          v14.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11))
                          + (float)(v13 * v13);
          if ( COERCE_FLOAT(_mm_sqrt_ps(v14)) >= 0.1 )
          {
            if ( v14.m128_f32[0] == 0.0 )
              v15 = 0.0;
            else
              v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
            v16 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
            v17 = v12.m128_f32[0] * v15;
            v18 = v11 * v15;
            v19 = v13 * v15;
            v20 = v16;
            m.v0.x = v17;
            m.v0.y = v18;
            m.v0.z = v19;
            v20.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0])
                                    + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                            + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
            if ( v20.m128_f32[0] == 0.0 )
              v21 = 0.0;
            else
              v21 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v20));
            v22 = v21;
            v23 = v21;
            v24 = v21 * UFG::qVector3::msDirUp.z;
            v25 = v23 * UFG::qVector3::msDirUp.x;
            v26 = v22 * UFG::qVector3::msDirUp.y;
            v27 = (float)(v26 * v19) - (float)(v24 * v18);
            v28 = (float)(v24 * v17) - (float)(v25 * v19);
            v29 = (float)(v25 * v18) - (float)(v26 * v17);
            v30 = (float)((float)(v28 * v28) + (float)(v27 * v27)) + (float)(v29 * v29);
            if ( v30 == 0.0 )
              v31 = 0.0;
            else
              v31 = 1.0 / fsqrt(v30);
            v32 = v28 * v31;
            m.v1.y = 0.0;
            m.v0.w = v32;
            m.v1.x = v29 * v31;
            m.v0.z = v27 * v31;
            v33 = (float)((float)(v29 * v31) * v18) - (float)(v32 * v19);
            v34 = (float)((float)(v27 * v31) * v19) - (float)((float)(v29 * v31) * v17);
            v35 = (float)(v32 * v17) - (float)((float)(v27 * v31) * v18);
            v36 = (float)((float)(v34 * v34) + (float)(v33 * v33)) + (float)(v35 * v35);
            if ( v36 == 0.0 )
              v37 = 0.0;
            else
              v37 = 1.0 / fsqrt(v36);
            m.v2.z = v8;
            m.v2.w = v9;
            m.v2.y = 0.0;
            m.v3.y = 1.0;
            m.v1.z = v33 * v37;
            m.v1.w = v34 * v37;
            m.v2.x = v35 * v37;
            m.v3.x = v10;
            UFG::TransformNodeComponent::SetLocalTransform(v7, &m);
          }
        }
        if ( UFG::OneShotHandle::IsValid((UFG::OneShotHandle *)&v2[6].mNext) )
        {
          v38 = v2[6].mNext;
          v39 = (int)v2[9].mNext;
          v40 = HIDWORD(v2[9].mNext);
          LODWORD(v38[5].mPrev) = HIDWORD(v2[9].mPrev);
          HIDWORD(v38[5].mNext) = 1065353216;
          HIDWORD(v38[5].mPrev) = v39;
          LODWORD(v38[5].mNext) = v40;
          UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)v38);
        }
        v41 = v2[7].mNext;
        if ( v41 )
        {
          v42 = (float *)v41[1].mPrev;
          if ( v42 )
          {
            v43 = *(float *)&v2[14].mNext;
            if ( v43 <= v42[35] )
            {
              v44 = (__m128)HIDWORD(v2[10].mPrev);
              v45 = v42[33];
              v46 = v42[32];
              v44.m128_f32[0] = (float)((float)((float)(v44.m128_f32[0] - v9) * (float)(v44.m128_f32[0] - v9))
                                      + (float)((float)(*(float *)&v2[10].mPrev - v8)
                                              * (float)(*(float *)&v2[10].mPrev - v8)))
                              + (float)((float)(*(float *)&v2[10].mNext - v10) * (float)(*(float *)&v2[10].mNext - v10));
              LODWORD(v47) = (unsigned __int128)_mm_sqrt_ps(v44);
              if ( v47 < v45 )
                v45 = v47;
              v48 = *(float *)&v2[11].mPrev;
              v49 = (__m128)HIDWORD(v2[10].mNext);
              v50 = *((float *)&v2[11].mPrev + 1);
              *(_QWORD *)&m.v0.x = v42;
              v51 = v49;
              m.v0.w = v8;
              m.v1.x = v9;
              v51.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v48 * v48))
                              + (float)(v50 * v50);
              m.v1.y = v10;
              m.v2.z = v46;
              m.v2.w = v43;
              v52 = v45 / COERCE_FLOAT(_mm_sqrt_ps(v51));
              m.v0.y = v9 - (float)(v48 * v52);
              v53 = *((float *)&v2[11].mNext + 1);
              m.v0.z = v10 - (float)(v50 * v52);
              v54 = *(float *)&v2[11].mNext;
              m.v1.w = v53;
              v55 = *((float *)&v2[12].mPrev + 1);
              m.v1.z = v54;
              v56 = *(float *)&v2[12].mPrev;
              m.v2.y = v55;
              m.v2.x = v56;
              m.v0.z = v8 - (float)(v49.m128_f32[0] * v52);
              Render::BeamManager::AddBeam(&Render::gBeamManager, (Render::BeamManager::AddBeamParameters *)&m);
            }
          }
        }
        v57 = v2[8].mPrev;
        if ( v57 )
        {
          v58 = v57[1].mPrev;
          if ( v58 )
          {
            v59 = *(float *)&v2[14].mNext;
            if ( v59 <= *((float *)&v58[8].mNext + 1) )
            {
              v60 = *(float *)&v2[10].mPrev;
              v61 = *((float *)&v2[10].mPrev + 1);
              v62 = *(float *)&v2[10].mNext;
              *(_QWORD *)&m.v0.x = v58;
              m.v0.z = v60;
              v63 = *(float *)&v2[11].mNext;
              m.v0.y = v61;
              v64 = *((float *)&v2[11].mNext + 1);
              m.v1.z = v63;
              m.v2.x = *(float *)&v2[12].mPrev;
              v65 = *(float *)&v58[8].mPrev;
              m.v1.w = v64;
              v66 = *((float *)&v2[12].mPrev + 1);
              m.v2.z = v65;
              m.v0.z = v62;
              m.v0.w = v8;
              m.v1.x = v9;
              m.v1.y = v10;
              m.v2.y = v66;
              m.v2.w = v59;
              Render::BeamManager::AddBeam(&Render::gBeamManager, (Render::BeamManager::AddBeamParameters *)&m);
            }
          }
        }
      }
      v67 = (unsigned __int8)v2[15].mNext;
      if ( (v67 >> 4) & 1
        || (v67 >> 3) & 1
        || (v68 = v4 + *(float *)&v2[14].mNext,
            v69 = v68 < *((float *)&v2[14].mPrev + 1),
            v5 = v68 == *((float *)&v2[14].mPrev + 1),
            *(float *)&v2[14].mNext = v68,
            !v69 && !v5) )
      {
        v70 = (UFG::Bullet *)v2;
        v2 = v2->mPrev;
        if ( v70 )
        {
          UFG::Bullet::~Bullet(v70);
          v70->mPrev = (UFG::qNode<UFG::Bullet,UFG::Bullet> *)UFG::Bullet::mAllocator.mFreeListHead;
          --UFG::Bullet::mAllocator.mNumSlotsAllocated;
          UFG::Bullet::mAllocator.mFreeListHead = (char *)v70;
        }
      }
      v2 = v2->mNext;
    }
    while ( v2 != (UFG::qNode<UFG::Bullet,UFG::Bullet> *)v3 );
  }
}

// File Line: 888
// RVA: 0x456B40
__int64 __fastcall UFG::BulletManager::ApplyDamage(UFG::BulletManager *this, UFG::Bullet *bullet, UFG::RayCastData *bulletRay, UFG::HavokUserData *hd)
{
  UFG::HavokUserData *v4; // rdi
  UFG::RayCastData *v5; // r15
  UFG::Bullet *v6; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v9; // rcx
  const char *v10; // rax
  unsigned int v11; // ecx
  unsigned __int16 v12; // cx
  UFG::VehicleEffectsComponent *v13; // rax
  unsigned __int8 v14; // bl
  UFG::SimComponent *v15; // rdi
  UFG::SimComponent *v16; // rax
  float v17; // xmm6_4
  float v18; // xmm6_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v19; // rdi
  UFG::SimObject *v20; // r14
  UFG::GameStatTracker *v21; // rax
  float v22; // xmm1_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v23; // rdx
  void *(__fastcall *v24)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rcx
  void *(__fastcall *v25)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rax
  void *(__fastcall *v27)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  float v28; // xmm0_4
  bool v29; // cf
  UFG::SimObject *v30; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v31; // rdx
  void *(__fastcall *v32)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rcx
  void *(__fastcall *v33)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax
  void *(__fastcall *v35)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  unsigned __int16 v36; // cx
  UFG::PhysicsMoverInterface *v37; // r8
  UFG::SimComponent *v38; // rax
  UFG::SimComponent *v39; // rax
  float v40; // xmm2_4
  unsigned __int16 v41; // cx
  UFG::SimComponent *v42; // rax
  hkSimpleLocalFrame *v43; // rdi
  UFG::SimObject *v44; // rdi
  UFG::SimObjectCharacter *v45; // rax
  unsigned __int16 v46; // dx
  UFG::CharacterAnimationComponent *v47; // rax
  bool pIsAmbient; // [rsp+18h] [rbp-31h]
  bool subjectToAttackCooldown[8]; // [rsp+20h] [rbp-29h]
  UFG::qReflectHandleBase v51; // [rsp+28h] [rbp-21h]
  UFG::qReflectHandleBase v52; // [rsp+50h] [rbp+7h]
  void *retaddr; // [rsp+B8h] [rbp+6Fh]
  UFG::SimObjectCVBase *v54; // [rsp+C8h] [rbp+7Fh]

  *(_QWORD *)subjectToAttackCooldown = -2i64;
  v4 = hd;
  v5 = bulletRay;
  v6 = bullet;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)((char *)&v52 + 24));
  v8 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
  v52.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v52, v52.mTypeUID, v5->mPhysicsObjectPropertyHandleUid);
  if ( !v52.mData )
    UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v52);
  UFG::qReflectHandleBase::qReflectHandleBase(&v51);
  v10 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v9);
  v51.mTypeUID = UFG::qStringHash64(v10, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v51, v51.mTypeUID, v5->mPhysicsSurfacePropertyHandleUid);
  if ( !v51.mData )
    UFG::qReflectHandleBase::operator=(&v51, (UFG::qReflectHandleBase *)&v52.mData[3].mTypeUID);
  if ( _S8_12 & 1 )
  {
    v11 = glassVehicleUid;
  }
  else
  {
    _S8_12 |= 1u;
    v11 = UFG::qStringHashUpper32("Glass_Vehicle", 0xFFFFFFFF);
    glassVehicleUid = v11;
  }
  if ( LODWORD(v51.mData[2].vfptr) != v11
    || !v54
    || ((v12 = v54->m_Flags, !((v12 >> 14) & 1)) ? ((v12 & 0x8000u) == 0 ? (!((v12 >> 13) & 1) ? (!((v12 >> 12) & 1) ? (v13 = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v54->vfptr, UFG::VehicleEffectsComponent::_TypeUID)) : (v13 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v54->vfptr, UFG::VehicleEffectsComponent::_TypeUID))) : (v13 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v54->vfptr, UFG::VehicleEffectsComponent::_TypeUID))) : (v13 = (UFG::VehicleEffectsComponent *)v54->m_Components.p[32].m_pComponent)) : (v13 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v54->vfptr, UFG::VehicleEffectsComponent::_TypeUID)),
        !v13) )
  {
    v15 = v4->simComponent.m_pPointer;
    if ( v15 )
    {
      if ( UFG::SimComponent::IsType(v15, UFG::RigidBodyComponent::_RigidBodyComponentTypeUID) )
      {
        v16 = v6->projectileInfo.m_pSOWPC.m_pPointer;
        if ( v16 )
        {
          v17 = *(float *)(*((_QWORD *)&v16[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v16[2].m_pSimObject))
                         + 144i64);
          if ( v6->projectileInfo.m_bIsFullyAccurate )
            v17 = v17 * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fFullyAccurateDamageMultiplier;
          v18 = v17 * *((float *)&v51.mData[1].mBaseNode.mUID + 1);
          v19 = v15[6].vfptr;
          if ( v19 )
          {
            if ( *((_BYTE *)v6 + 248) & 1 )
            {
              v20 = v6->weaponOwnerSimObject.m_pPointer;
              v21 = UFG::GameStatTracker::Instance();
              v22 = UFG::GameStatTracker::GetStat(v21, Sharpshooter_Damage_Multiplier) * v18;
              if ( v22 > 0.0 )
              {
                if ( v20 )
                {
                  v23 = v19 + 24;
                  if ( v19[26].__vecDelDtor )
                  {
                    v24 = v23->__vecDelDtor;
                    v25 = v19[25].__vecDelDtor;
                    *((_QWORD *)v24 + 1) = v25;
                    *(_QWORD *)v25 = v24;
                    v23->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v23;
                    v19[25].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&v19[24];
                  }
                  v19[26].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v20;
                  v26 = v20->m_SafePointerList.mNode.mPrev;
                  v26->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v23;
                  v23->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v26;
                  v19[25].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&v20->m_SafePointerList;
                  v20->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v23;
                }
                v27 = v19[19].__vecDelDtor;
                if ( v27 )
                {
                  v28 = *((float *)&v19[33].__vecDelDtor + 1) - (float)(v22 * *((float *)v27 + 25));
                  v29 = v28 < 0.0;
                  goto LABEL_42;
                }
              }
            }
            else
            {
              v30 = v6->weaponOwnerSimObject.m_pPointer;
              if ( v18 > 0.0 )
              {
                if ( v30 )
                {
                  v31 = v19 + 24;
                  if ( v19[26].__vecDelDtor )
                  {
                    v32 = v31->__vecDelDtor;
                    v33 = v19[25].__vecDelDtor;
                    *((_QWORD *)v32 + 1) = v33;
                    *(_QWORD *)v33 = v32;
                    v31->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v31;
                    v19[25].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&v19[24];
                  }
                  v19[26].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v30;
                  v34 = v30->m_SafePointerList.mNode.mPrev;
                  v34->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v31;
                  v31->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v34;
                  v19[25].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))&v30->m_SafePointerList;
                  v30->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v31;
                }
                v35 = v19[19].__vecDelDtor;
                if ( v35 )
                {
                  v28 = *((float *)&v19[33].__vecDelDtor + 1) - (float)(v18 * *((float *)v35 + 25));
                  v29 = v28 < 0.0;
LABEL_42:
                  *((float *)&v19[33].__vecDelDtor + 1) = v28;
                  if ( v29 )
                    HIDWORD(v19[33].__vecDelDtor) = 0;
                  goto LABEL_44;
                }
              }
            }
          }
        }
      }
    }
LABEL_44:
    if ( !v54 )
    {
LABEL_86:
      v14 = 1;
      goto LABEL_87;
    }
    v36 = v54->m_Flags;
    if ( !((v36 >> 14) & 1) )
    {
      if ( (v36 & 0x8000u) == 0 )
      {
        if ( (v36 >> 13) & 1 )
          goto LABEL_75;
        if ( (v36 >> 12) & 1 )
          v38 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v54->vfptr,
                  UFG::PhysicsMoverInterface::_TypeUID);
        else
          v38 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v54->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v37 = (UFG::PhysicsMoverInterface *)v38;
      }
      else
      {
        v37 = (UFG::PhysicsMoverInterface *)v54->m_Components.p[34].m_pComponent;
      }
      if ( v37 )
      {
        v39 = v6->projectileInfo.m_pSOWPC.m_pPointer;
        if ( v39 )
        {
          v40 = *(float *)(*((_QWORD *)&v39[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v39[2].m_pSimObject))
                         + 148i64)
              * *((float *)&v51.mData[1].mBaseNode.mUID + 1);
          subjectToAttackCooldown[0] = 0;
          UFG::PhysicsMoverInterface::DamageEngine(v37, v6->weaponOwnerSimObject.m_pPointer, v40, dtBULLET);
          if ( UFG::GetLocalPlayer() == (UFG::SimObjectCharacter *)v6->weaponOwnerSimObject.m_pPointer )
          {
            UFG::GameStatAction::MissionScoring::DeduceFaction(
              (UFG::SimObject *)&v54->vfptr,
              (bool *)&retaddr,
              &pIsAmbient);
            if ( !pIsAmbient )
            {
              v41 = v54->m_Flags;
              if ( (v41 >> 14) & 1 )
              {
                v42 = UFG::SimObjectGame::GetComponentOfTypeHK(
                        (UFG::SimObjectGame *)&v54->vfptr,
                        UFG::VehicleOccupantComponent::_TypeUID);
              }
              else
              {
                if ( (v41 & 0x8000u) != 0 )
                {
                  v43 = (hkSimpleLocalFrame *)v54->m_Components.p[30].m_pComponent;
LABEL_68:
                  if ( v43 )
                  {
                    if ( (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants((UFG::VehicleOccupantComponent *)v43) )
                    {
                      if ( !Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v43)
                        || (v44 = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(v43)) == 0i64
                        || (v45 = UFG::GetLocalPlayer(), !UFG::AreCharactersAllied((UFG::SimObject *)&v45->vfptr, v44)) )
                      {
                        UFG::GameStatAction::MissionScoring::LogTriadEvent(
                          TRIAD_VEHICLE_DAMAGE,
                          0,
                          &customWorldMapCaption);
                      }
                    }
                  }
                  goto LABEL_75;
                }
                if ( (v41 >> 13) & 1 )
                {
                  v42 = UFG::SimObjectGame::GetComponentOfTypeHK(
                          (UFG::SimObjectGame *)&v54->vfptr,
                          UFG::VehicleOccupantComponent::_TypeUID);
                }
                else if ( (v41 >> 12) & 1 )
                {
                  v42 = UFG::SimObjectGame::GetComponentOfTypeHK(
                          (UFG::SimObjectGame *)&v54->vfptr,
                          UFG::VehicleOccupantComponent::_TypeUID);
                }
                else
                {
                  v42 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v54->vfptr,
                          UFG::VehicleOccupantComponent::_TypeUID);
                }
              }
              v43 = (hkSimpleLocalFrame *)v42;
              goto LABEL_68;
            }
            UFG::GameStatAction::MissionScoring::LogCopEvent(COP_VEHICLE_DAMAGE, 0, &customWorldMapCaption);
          }
        }
      }
    }
LABEL_75:
    v46 = v54->m_Flags;
    if ( (v46 >> 14) & 1 )
    {
      v47 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v54);
    }
    else if ( (v46 & 0x8000u) == 0 )
    {
      if ( (v46 >> 13) & 1 )
      {
        v47 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v54);
      }
      else if ( (v46 >> 12) & 1 )
      {
        v47 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v54->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v47 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v54->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v47 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v54);
    }
    if ( v47 )
      UFG::CharacterAnimationComponent::ApplyBulletDamage(v47, v5);
    goto LABEL_86;
  }
  UFG::VehicleEffectsComponent::DamageGlass(v13, &v5->point);
  v14 = 0;
LABEL_87:
  UFG::qReflectHandleBase::~qReflectHandleBase(&v51);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v52);
  return v14;
}

// File Line: 1022
// RVA: 0x4742F0
void __fastcall UFG::BulletManager::SendBulletImpactEvent(UFG::BulletManager *this, UFG::SimObject *simObject, UFG::SimObject *initiatorSimObject)
{
  unsigned __int16 v3; // cx
  UFG::SimObject *v4; // rdi
  UFG::SimObject *stimulus_target_object; // rbx
  UFG::SimComponent *v6; // rax
  UFG::StimulusParameters stimulus_parameters; // [rsp+30h] [rbp-28h]

  if ( simObject )
  {
    v3 = simObject->m_Flags;
    v4 = initiatorSimObject;
    stimulus_target_object = simObject;
    if ( (v3 >> 14) & 1 )
    {
      v6 = simObject->m_Components.p[3].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v6 = simObject->m_Components.p[4].m_pComponent;
      }
      else if ( (v3 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)simObject,
               UFG::SimObjectPropertiesComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(simObject, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v6 = simObject->m_Components.p[3].m_pComponent;
    }
    if ( v6 )
    {
      if ( LODWORD(v6[1].m_SafePointerList.mNode.mNext) == 1 )
      {
        stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
        stimulus_parameters.m_MaxStimulusDuration = -1.0;
        stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
        stimulus_parameters.m_StimulusEmissionType = 0;
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_IVE_BEEN_SHOT,
          &stimulus_parameters,
          v4,
          stimulus_target_object);
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_IVE_BEEN_SHOT_NEARBY,
          &stimulus_parameters,
          stimulus_target_object);
      }
    }
  }
}

// File Line: 1041
// RVA: 0x474400
void __fastcall UFG::BulletManager::SendBulletImpactEvent(UFG::BulletManager *this, UFG::Bullet *bullet, UFG::RayCastData *bulletRay, UFG::HavokUserData *hd)
{
  UFG::RayCastData *v4; // rsi
  UFG::Bullet *v5; // r14
  UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  UFG::SimObjectGame *v8; // rbx
  unsigned __int16 v9; // cx
  UFG::VehicleEffectsComponent *v10; // rax
  UFG::SimComponent *v11; // rax
  unsigned int v12; // er15
  UFG::SimComponent *v13; // rax
  UFG::BulletCollisionEvent *v14; // rax
  __int64 v15; // rax
  __int64 v16; // rdi
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  __m128 v21; // xmm2
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  __int64 *v26; // rdx
  __int64 v27; // rcx
  _QWORD *v28; // rax
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v29; // rcx
  const char *v30; // rax
  unsigned int v31; // er14
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v32; // rcx
  const char *v33; // rax
  float v34; // xmm4_4
  float v35; // xmm3_4
  __m128 v36; // xmm2
  __m128 v37; // xmm5
  float v38; // xmm1_4
  Render::FXSimComponent *fxComponent; // rdi
  UFG::SimComponent *v40; // rbx
  unsigned __int16 v41; // cx
  UFG::SimComponent *v42; // rax
  unsigned __int16 v43; // cx
  UFG::SimComponent *v44; // rax
  float v45; // xmm4_4
  __m128 v46; // xmm5
  float v47; // xmm3_4
  __m128 v48; // xmm2
  float v49; // xmm6_4
  UFG::StateMachineComponent *v50; // rcx
  UFG::StimulusParameters stimulus_parameters; // [rsp+50h] [rbp-88h]
  __int128 vRay; // [rsp+68h] [rbp-70h]
  __int128 vNormal; // [rsp+78h] [rbp-60h]
  UFG::qReflectHandleBase v54; // [rsp+88h] [rbp-50h]
  __int64 v55; // [rsp+B0h] [rbp-28h]
  UFG::qReflectHandleBase v56; // [rsp+B8h] [rbp-20h]
  UFG::SimObjectGame *retaddr; // [rsp+158h] [rbp+80h]

  v55 = -2i64;
  v4 = bulletRay;
  v5 = bullet;
  UFG::qReflectHandleBase::qReflectHandleBase(&v54);
  v7 = UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::GetTypeName(v6);
  *((_QWORD *)&vRay + 1) = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(
    (UFG::qReflectHandleBase *)&stimulus_parameters.m_MaxStimulusDuration,
    *((unsigned __int64 *)&vRay + 1),
    v4->mPhysicsSurfacePropertyHandleUid);
  v8 = retaddr;
  if ( !retaddr
    || ((v9 = retaddr->m_Flags, !((v9 >> 14) & 1)) ? ((v9 & 0x8000u) == 0 ? (!((v9 >> 13) & 1) ? (!((v9 >> 12) & 1) ? (v10 = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&retaddr->vfptr, UFG::VehicleEffectsComponent::_TypeUID)) : (v10 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(retaddr, UFG::VehicleEffectsComponent::_TypeUID))) : (v10 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(retaddr, UFG::VehicleEffectsComponent::_TypeUID))) : (v10 = (UFG::VehicleEffectsComponent *)retaddr->m_Components.p[32].m_pComponent)) : (v10 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(retaddr, UFG::VehicleEffectsComponent::_TypeUID)),
        !v10
     || !*((_QWORD *)&vNormal + 1)
     || 0.0 == *(float *)(*((_QWORD *)&vNormal + 1) + 88i64)
     || !UFG::VehicleEffectsComponent::IsGlassBroken(v10, &v4->point)) )
  {
    v11 = v5->projectileInfo.m_pSOWPC.m_pPointer;
    if ( v11 && *(float *)&v11[3].vfptr > 0.5 )
    {
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusEmissionType = 0;
      UFG::StimulusManager::BeginStimulus(
        UFG::StimulusManager::s_pInstance,
        eSTIMULUS_BULLET_IMPACT,
        &stimulus_parameters,
        &v4->point);
      LODWORD(v5->projectileInfo.m_pSOWPC.m_pPointer[3].vfptr) = 0;
    }
    v12 = 0;
    v13 = v5->projectileInfo.m_pSOWPC.m_pPointer;
    if ( v13 )
      v12 = *(_DWORD *)(*((_QWORD *)&v13[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v13[2].m_pSimObject))
                      + 120i64);
    v14 = (UFG::BulletCollisionEvent *)UFG::qMalloc(0xF0ui64, "BulletCollisionEvent", 0i64);
    retaddr = (UFG::SimObjectGame *)v14;
    if ( v14 )
    {
      UFG::BulletCollisionEvent::BulletCollisionEvent(v14);
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    if ( v16 )
    {
      *(_DWORD *)(v16 + 56) = 0;
      v17 = v4->point.y;
      v18 = v4->point.z;
      *(float *)(v16 + 60) = v4->point.x;
      *(float *)(v16 + 64) = v17;
      *(float *)(v16 + 68) = v18;
      v19 = v4->normal.y;
      v20 = v4->normal.z;
      *(float *)(v16 + 72) = v4->normal.x;
      *(float *)(v16 + 76) = v19;
      *(float *)(v16 + 80) = v20;
      v21 = (__m128)LODWORD(v5->vel.x);
      v21.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v5->vel.y * v5->vel.y))
                      + (float)(v5->vel.z * v5->vel.z);
      *(_DWORD *)(v16 + 84) = (unsigned __int128)_mm_sqrt_ps(v21);
      v22 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v16 + 96);
      if ( *(_QWORD *)(v16 + 112) )
      {
        v23 = v22->mPrev;
        v24 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v16 + 104);
        v23->mNext = v24;
        v24->mPrev = v23;
        v22->mPrev = v22;
        *(_QWORD *)(v16 + 104) = v16 + 96;
      }
      *(_QWORD *)(v16 + 112) = v8;
      if ( v8 )
      {
        v25 = v8->m_SafePointerList.mNode.mPrev;
        v25->mNext = v22;
        v22->mPrev = v25;
        *(_QWORD *)(v16 + 104) = (char *)v8 + 8;
        v8->m_SafePointerList.mNode.mPrev = v22;
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
      *(_QWORD *)(v16 + 208) = v4->mPhysicsSurfacePropertyHandleUid;
      *(_QWORD *)(v16 + 216) = 0i64;
      *(_QWORD *)(v16 + 192) = v4->mPhysicsObjectPropertyHandleUid;
      UFG::qReflectHandleBase::qReflectHandleBase(&v56);
      v30 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v29);
      v56.mTypeUID = UFG::qStringHash64(v30, 0xFFFFFFFFFFFFFFFFui64);
      UFG::PhysicsPropertyManager::GetObjectProperties(
        (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v56,
        v12,
        1);
      *(_QWORD *)(v16 + 200) = v56.mData->mBaseNode.mUID;
      v31 = 0;
      if ( *((_QWORD *)&vNormal + 1) )
      {
        v31 = *(_DWORD *)(*((_QWORD *)&vNormal + 1) + 108i64);
      }
      else
      {
        UFG::qReflectHandleBase::qReflectHandleBase(&v54);
        v33 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v32);
        v54.mTypeUID = UFG::qStringHash64(v33, 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init(&v54, v54.mTypeUID, v4->mPhysicsObjectPropertyHandleUid);
        if ( v54.mData )
          v31 = *(_DWORD *)(v54.mData[4].mBaseNode.mUID + 108);
        UFG::qReflectHandleBase::~qReflectHandleBase(&v54);
      }
      v36 = (__m128)v4->mInput.m_to.m_quad.m128_u32[0];
      v34 = v4->mInput.m_to.m_quad.m128_f32[2] - v4->mInput.m_from.m_quad.m128_f32[2];
      v35 = v4->mInput.m_to.m_quad.m128_f32[1] - v4->mInput.m_from.m_quad.m128_f32[1];
      v36.m128_f32[0] = v36.m128_f32[0] - v4->mInput.m_from.m_quad.m128_f32[0];
      v37 = v36;
      v37.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v35 * v35)) + (float)(v34 * v34);
      if ( v37.m128_f32[0] == 0.0 )
        v38 = 0.0;
      else
        v38 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v37));
      *(float *)&vRay = v36.m128_f32[0] * v38;
      *((float *)&vRay + 1) = v35 * v38;
      *((float *)&vRay + 2) = v34 * v38;
      if ( v8 )
      {
        v41 = v8->m_Flags;
        if ( (v41 >> 14) & 1 )
        {
          v42 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, Render::FXSimComponent::_TypeUID);
        }
        else if ( (v41 & 0x8000u) == 0 )
        {
          if ( (v41 >> 13) & 1 )
          {
            v42 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, Render::FXSimComponent::_TypeUID);
          }
          else if ( (v41 >> 12) & 1 )
          {
            v42 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, Render::FXSimComponent::_TypeUID);
          }
          else
          {
            v42 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, Render::FXSimComponent::_TypeUID);
          }
        }
        else
        {
          v42 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, Render::FXSimComponent::_TypeUID);
        }
        fxComponent = (Render::FXSimComponent *)v42;
        v43 = v8->m_Flags;
        if ( (v43 >> 14) & 1 )
        {
          v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v43 & 0x8000u) == 0 )
        {
          if ( (v43 >> 13) & 1 )
          {
            v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
          }
          else if ( (v43 >> 12) & 1 )
          {
            v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
          }
          else
          {
            v44 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::RigidBodyComponent::_TypeUID);
          }
        }
        else
        {
          v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
        }
        v40 = v44;
      }
      else
      {
        fxComponent = 0i64;
        v40 = 0i64;
      }
      v45 = v4->normal.y;
      v46 = (__m128)LODWORD(v4->normal.x);
      v47 = v4->normal.z;
      v48 = v46;
      v48.m128_f32[0] = (float)((float)(v46.m128_f32[0] * v46.m128_f32[0]) + (float)(v45 * v45)) + (float)(v47 * v47);
      if ( v48.m128_f32[0] == 0.0 )
        v49 = 0.0;
      else
        v49 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v48));
      *(float *)&vNormal = v46.m128_f32[0] * v49;
      *((float *)&vNormal + 1) = v45 * v49;
      stimulus_parameters.m_StimulusProducerOffset.z = v47 * v49;
      Render::ImpactManager::HandleImpactEvent(
        &Render::gImpactManager,
        v12,
        v31,
        &v4->point,
        (UFG::qVector3 *)&vRay,
        (UFG::qVector3 *)&vNormal,
        fxComponent,
        0,
        &stimulus_parameters.m_StimulusProducerOffset);
      if ( v40 )
      {
        v50 = (UFG::StateMachineComponent *)v40[6].vfptr;
        if ( v50 )
          UFG::StateMachineComponent::ApplyImpactEffect(v50, &v4->point, &stimulus_parameters.m_StimulusProducerOffset);
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v56);
    }
  }
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&stimulus_parameters.m_MaxStimulusDuration);
}

// File Line: 1149
// RVA: 0x456350
void __fastcall UFG::BulletManager::ApplyBulletImpactImpulse(UFG::BulletManager *this, UFG::Bullet *bullet, UFG::RayCastData *ray, UFG::HavokUserData *hd)
{
  UFG::HavokUserData *v4; // r15
  UFG::RayCastData *v5; // rdi
  UFG::Bullet *v6; // r14
  UFG::SimObjectGame *v7; // rsi
  UFG::SimComponent *v8; // rsi
  unsigned __int16 v9; // cx
  UFG::HitReactionComponent *v10; // r10
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rcx
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  hkpWorldObject *v17; // rcx
  unsigned __int64 v18; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v19; // rcx
  const char *v20; // rax
  unsigned __int64 v21; // rdx
  hkpEntity *v22; // rbx
  char v23; // cl
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
  hkpShape *v35; // rdx
  hkpShape *v36; // rbx
  signed int v37; // esi
  char v38; // r8
  signed __int64 v39; // rax
  hkpWorld *v40; // r12
  signed __int64 v41; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v42; // rcx
  const char *v43; // rax
  __m128 v44; // xmm4
  __m128 v45; // xmm3
  __m128 v46; // xmm3
  __m128 v47; // xmm0
  float v48; // xmm5_4
  __m128 v49; // xmm0
  hkpRigidBody *v50; // rbx
  hkpRigidBody *v51; // rbx
  int v52; // ecx
  int v53; // ebx
  __int64 v54; // rdi
  hkpRigidBody **v55; // r14
  int v56; // esi
  int v57; // eax
  int v58; // eax
  int v59; // er9
  hkpEntity **v60; // rax
  char *v61; // rdx
  signed __int64 v62; // r14
  unsigned __int64 type_uid[2]; // [rsp+50h] [rbp-88h]
  __m128 v64; // [rsp+60h] [rbp-78h]
  UFG::qReflectHandleBase v65; // [rsp+70h] [rbp-68h]
  hkVector4f v66; // [rsp+98h] [rbp-40h]
  __int64 v67; // [rsp+A8h] [rbp-30h]
  __m128 v68; // [rsp+B8h] [rbp-20h]
  hkVector4f v69; // [rsp+C8h] [rbp-10h]
  hkpPhysicsSystem sys; // [rsp+D8h] [rbp+0h]
  char *array; // [rsp+148h] [rbp+70h]
  int v72; // [rsp+150h] [rbp+78h]
  int v73; // [rsp+154h] [rbp+7Ch]
  char v74; // [rsp+158h] [rbp+80h]
  hkResult result; // [rsp+5A0h] [rbp+4C8h]

  v67 = -2i64;
  v4 = hd;
  v5 = ray;
  v6 = bullet;
  if ( !(*((_BYTE *)bullet + 248) & 2) )
  {
    v7 = 0i64;
    if ( hd )
    {
      v8 = hd->simComponent.m_pPointer;
      v7 = (UFG::SimObjectGame *)(v8 ? v8->m_pSimObject : 0i64);
      if ( v7 )
      {
        v9 = v7->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = (UFG::HitReactionComponent *)v7->m_Components.p[15].m_pComponent;
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HitReactionComponent::_TypeUID);
          else
            v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::HitReactionComponent::_TypeUID);
          v10 = (UFG::HitReactionComponent *)v11;
        }
        else
        {
          v10 = (UFG::HitReactionComponent *)v7->m_Components.p[15].m_pComponent;
        }
        if ( v10 )
        {
          v12 = v6->weaponOwnerSimObject.m_pPointer;
          v13 = v6->vel.y;
          v14 = v6->vel.z;
          v64.m128_i32[0] = LODWORD(v6->vel.x);
          *(unsigned __int64 *)((char *)v64.m128_u64 + 4) = __PAIR__(LODWORD(v14), LODWORD(v13));
          v15 = v5->point.y;
          v16 = v5->point.z;
          *(float *)type_uid = v5->point.x;
          *((float *)type_uid + 1) = v15;
          *(float *)&type_uid[1] = v16;
          UFG::HitReactionComponent::ApplyBulletImpactImpulse(
            v10,
            (UFG::qVector3 *)type_uid,
            (UFG::qVector3 *)&v64,
            &v6->projectileInfo,
            v12,
            v5->mPhysicsObjectPropertyHandleUid);
        }
      }
    }
    v17 = (hkpWorldObject *)&v5->mHavokRigidBody->vfptr;
    if ( v17 )
    {
      v18 = UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(v17);
      UFG::qReflectHandleBase::qReflectHandleBase(&v65);
      v20 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v19);
      type_uid[1] = UFG::qStringHash64(v20, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v65, type_uid[1], v18);
      v21 = v64.m128_u64[1];
      if ( !v64.m128_u64[1] )
      {
        UFG::PhysicsPropertyManager::GetDefaultObjectProperties((UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&v65);
        v21 = v64.m128_u64[1];
      }
      if ( !v7 || (v7->m_Flags >> 10) & 1 )
        goto LABEL_75;
      v22 = (hkpEntity *)&v5->mHavokRigidBody->vfptr;
      v23 = v22->m_motion.m_type.m_storage;
      if ( v23 != 5 && v23 != 4 )
      {
        v64 = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)LODWORD(v5->point.x), (__m128)LODWORD(v5->point.z)),
                _mm_unpacklo_ps((__m128)LODWORD(v5->point.y), (__m128)0i64));
        v24 = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)LODWORD(v6->vel.x), (__m128)LODWORD(v6->vel.z)),
                _mm_unpacklo_ps((__m128)LODWORD(v6->vel.y), (__m128)0i64));
        *(__m128 *)type_uid = v24;
        v25 = _mm_mul_ps(v24, v24);
        v26 = _mm_add_ps(
                _mm_shuffle_ps(v25, v25, 170),
                _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)));
        v27 = _mm_rsqrt_ps(v26);
        LODWORD(v28) = (unsigned __int128)_mm_andnot_ps(
                                            _mm_cmpleps(v26, (__m128)0i64),
                                            _mm_mul_ps(
                                              v26,
                                              _mm_mul_ps(
                                                _mm_mul_ps(*(__m128 *)_xmm, v27),
                                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)))));
        if ( v28 > 0.0099999998 )
        {
          v29 = v6->projectileInfo.m_pSOWPC.m_pPointer;
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
          ((void (__fastcall *)(hkpMaxSizeMotion *, unsigned __int64 *, __m128 *))v22->m_motion.vfptr[11].__first_virtual_table_function__)(
            &v22->m_motion,
            type_uid,
            &v64);
        }
      }
      v31 = UFG::Destruction::mInstance;
      type_uid[0] = 0i64;
      type_uid[1] = 0x8000000000000000i64;
      hkpPhysicsSystem::hkpPhysicsSystem(&sys);
      v66.m_quad = _mm_unpacklo_ps(
                     _mm_unpacklo_ps((__m128)LODWORD(v5->normal.x), (__m128)LODWORD(v5->normal.z)),
                     _mm_unpacklo_ps((__m128)LODWORD(v5->normal.y), (__m128)0i64));
      v69.m_quad = _mm_unpacklo_ps(
                     _mm_unpacklo_ps((__m128)LODWORD(v5->point.x), (__m128)LODWORD(v5->point.z)),
                     _mm_unpacklo_ps((__m128)LODWORD(v5->point.y), (__m128)0i64));
      v32 = v4->simComponent.m_pPointer;
      if ( !v32
        || !UFG::SimComponent::IsType(v32, UFG::RigidBodyComponent::_RigidBodyComponentTypeUID)
        || (v33 = *(UFG::CollisionMeshData **)&v32[2].m_Flags) == 0i64
        || v5->mOutput.m_shapeKeys[0] == -1
        || v5->mOutput.m_shapeKeys[1] == -1 )
      {
LABEL_72:
        hkpPhysicsSystem::~hkpPhysicsSystem(&sys);
        LODWORD(type_uid[1]) = 0;
        if ( (type_uid[1] & 0x8000000000000000ui64) == 0i64 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (void *)type_uid[0],
            4 * HIDWORD(type_uid[1]));
        type_uid[0] = 0i64;
        HIDWORD(type_uid[1]) = 2147483648;
LABEL_75:
        UFG::qReflectHandleBase::~qReflectHandleBase(&v65);
        return;
      }
      v34 = v5->mHavokRigidBody;
      v35 = v34->m_collidable.m_shape;
      v36 = 0i64;
      v37 = -1;
      v38 = v35->m_type.m_storage;
      if ( v38 == 9 )
      {
        v36 = (hkpShape *)v35[2].m_userData;
      }
      else
      {
        if ( v38 != 8 )
        {
LABEL_43:
          if ( UFG::Destruction::IsPartMarkedAsBreakable(v31, (hkpEntity *)&v5->mHavokRigidBody->vfptr, v37)
            && v36->m_type.m_storage == 8
            && v37 != -1 )
          {
            v39 = UFG::CollisionMeshData::GetPartDetails(v33, v37);
            if ( v39 )
            {
              if ( *(float *)(v39 + 68) > 0.0 )
              {
                v40 = v5->mHavokRigidBody->m_world;
                v41 = UFG::CollisionMeshData::GetPart(v33, v37);
                UFG::qReflectHandleBase::qReflectHandleBase(&v65);
                v43 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v42);
                v65.mTypeUID = UFG::qStringHash64(v43, 0xFFFFFFFFFFFFFFFFui64);
                UFG::qReflectHandleBase::Init(&v65, v65.mTypeUID, *(_QWORD *)(v41 + 16));
                if ( v65.mData && BYTE3(v65.mData[1].mHandles.mNode.mNext) )
                  UFG::Destruction::breakOffSubPart(v31, 0i64, v5->mHavokRigidBody, v37);
                hkpWorld::addPhysicsSystem(v40, &sys);
                if ( sys.m_rigidBodies.m_size > 0 )
                {
                  v68 = _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)LODWORD(v5->point.x), (__m128)LODWORD(v5->point.z)),
                          _mm_unpacklo_ps((__m128)LODWORD(v5->point.y), (__m128)0i64));
                  v44 = _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)LODWORD(v6->vel.x), (__m128)LODWORD(v6->vel.z)),
                          _mm_unpacklo_ps((__m128)LODWORD(v6->vel.y), (__m128)0i64));
                  v64 = v44;
                  v45 = _mm_mul_ps(v44, v44);
                  v46 = _mm_add_ps(
                          _mm_shuffle_ps(v45, v45, 170),
                          _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)));
                  v47 = _mm_rsqrt_ps(v46);
                  LODWORD(v48) = (unsigned __int128)_mm_andnot_ps(
                                                      _mm_cmpleps(v46, (__m128)0i64),
                                                      _mm_mul_ps(
                                                        v46,
                                                        _mm_mul_ps(
                                                          _mm_mul_ps(*(__m128 *)_xmm, v47),
                                                          _mm_sub_ps(
                                                            (__m128)_xmm,
                                                            _mm_mul_ps(_mm_mul_ps(v47, v46), v47)))));
                  if ( v48 > 0.0099999998 )
                  {
                    v49 = (__m128)*(unsigned int *)(*((_QWORD *)&v6->projectileInfo.m_pSOWPC.m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                                                    + HIDWORD(v6->projectileInfo.m_pSOWPC.m_pPointer[2].m_pSimObject))
                                                  + 92i64);
                    if ( v64.m128_u64[1] )
                      v49.m128_f32[0] = v49.m128_f32[0] * *(float *)(v64.m128_u64[1] + 132);
                    v49.m128_f32[0] = v49.m128_f32[0] / v48;
                    v64 = _mm_mul_ps(v44, _mm_shuffle_ps(v49, v49, 0));
                    v50 = *sys.m_rigidBodies.m_data;
                    hkpEntity::activate(*(hkpEntity **)sys.m_rigidBodies.m_data);
                    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __m128 *))v50->m_motion.vfptr[11].__first_virtual_table_function__)(
                      &v50->m_motion,
                      &v64,
                      &v68);
                  }
                }
                array = &v74;
                v72 = 0;
                v73 = -2147483520;
                v51 = v5->mHavokRigidBody;
                v52 = 0;
                *(_QWORD *)&array[8 * v52] = v51;
                v53 = v72 + 1;
                v72 = v53;
                v54 = sys.m_rigidBodies.m_size;
                v55 = sys.m_rigidBodies.m_data;
                v56 = sys.m_rigidBodies.m_size + v53;
                v57 = v73 & 0x3FFFFFFF;
                if ( sys.m_rigidBodies.m_size + v53 > (v73 & 0x3FFFFFFF) && v57 < v56 )
                {
                  v58 = 2 * v57;
                  v59 = sys.m_rigidBodies.m_size + v53;
                  if ( v56 < v58 )
                    v59 = v58;
                  hkArrayUtil::_reserve(
                    &result,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    &array,
                    v59,
                    8);
                }
                hkMemUtil::memMove(&array[8 * (v54 + v53)], &array[8 * v53], 0);
                v60 = (hkpEntity **)array;
                v61 = &array[8 * v53];
                if ( v54 > 0 )
                {
                  v62 = (char *)v55 - v61;
                  do
                  {
                    *(_QWORD *)v61 = *(_QWORD *)&v61[v62];
                    v61 += 8;
                    --v54;
                  }
                  while ( v54 );
                  v60 = (hkpEntity **)array;
                }
                v72 = v56;
                if ( v56 )
                {
                  hkpWorld::reintegrateAndRecollideEntities(v40, v60, v56, RR_MODE_RECOLLIDE_NARROWPHASE);
                  hkReferencedObject::lockAll();
                  hkpPhysicsSystem::removeAll(&sys);
                  hkReferencedObject::unlockAll();
                }
                v72 = 0;
                if ( v73 >= 0 )
                  hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                    array,
                    8 * v73);
                array = 0i64;
                v73 = 2147483648;
                UFG::qReflectHandleBase::~qReflectHandleBase(&v65);
              }
            }
          }
          goto LABEL_72;
        }
        v36 = v34->m_collidable.m_shape;
      }
      v37 = v5->mOutput.m_shapeKeys[0];
      goto LABEL_43;
    }
  }
}

// File Line: 1315
// RVA: 0x455D40
void __fastcall UFG::BulletManager::AddTargetSphere(UFG::BulletManager *this, UFG::TargetSphere *sphere)
{
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v2; // rax
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v3; // r8
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v4; // rcx
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v5; // rax

  v2 = sphere->mNext;
  v3 = sphere->mPrev;
  v4 = &this->mTargetSpheres.mNode;
  v3->mNext = v2;
  v2->mPrev = v3;
  sphere->mPrev = (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)&sphere->mPrev;
  sphere->mNext = (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)&sphere->mPrev;
  v5 = v4->mPrev;
  v5->mNext = (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)&sphere->mPrev;
  sphere->mPrev = v5;
  sphere->mNext = v4;
  v4->mPrev = (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)&sphere->mPrev;
}

// File Line: 1323
// RVA: 0x473240
void __fastcall UFG::BulletManager::RemoveTargetSphere(UFG::BulletManager *this, UFG::TargetSphere *sphere)
{
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v2; // rcx
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v3; // rax

  v2 = sphere->mPrev;
  v3 = sphere->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  sphere->mPrev = (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)&sphere->mPrev;
  sphere->mNext = (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)&sphere->mPrev;
}

// File Line: 1330
// RVA: 0x4661D0
Render::BeamSettingsHandle *__fastcall UFG::BulletManager::GetBeamSettingsHandle(UFG::BulletManager *this, __int64 beamSettingsSymbol)
{
  __int64 v3; // rax
  Render::BeamSettingsHandle **v4; // rcx

  if ( *(_DWORD *)beamSettingsSymbol == -1 )
    return 0i64;
  v3 = 0i64;
  if ( !UFG::BulletManager::smSettingsHandles.size )
    return *UFG::BulletManager::smSettingsHandles.p;
  v4 = UFG::BulletManager::smSettingsHandles.p;
  while ( !*v4 || (*v4)->mNameUID != *(_DWORD *)beamSettingsSymbol )
  {
    v3 = (unsigned int)(v3 + 1);
    ++v4;
    if ( (unsigned int)v3 >= UFG::BulletManager::smSettingsHandles.size )
      return *UFG::BulletManager::smSettingsHandles.p;
  }
  return UFG::BulletManager::smSettingsHandles.p[v3];
}

// File Line: 1355
// RVA: 0x476CD0
UFG::TargetSphere *__fastcall UFG::BulletManager::TestAgainstTargetSpheres(UFG::BulletManager *this, UFG::Bullet *bullet, float *t)
{
  UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *v3; // rbx
  UFG::qList<UFG::TargetSphere,UFG::TargetSphere,1,0> *v4; // rsi
  UFG::TargetSphere *v5; // rdi
  float v6; // xmm6_4
  float *v7; // r15
  UFG::qVector3 *q1; // rbp
  UFG::qVector3 *q0; // r14
  UFG::TargetSphere *result; // rax
  float v11; // [rsp+80h] [rbp+8h]

  v3 = this->mTargetSpheres.mNode.mNext;
  v4 = &this->mTargetSpheres;
  v5 = 0i64;
  v6 = FLOAT_1000000_0;
  v7 = t;
  if ( v3 == (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)&this->mTargetSpheres )
    return 0i64;
  q1 = &bullet->pos_t1;
  q0 = &bullet->pos_t0;
  do
  {
    if ( UFG::SweptSphereQuery(
           *(float *)&v3[2].mNext,
           (UFG::qVector3 *)&v3[1],
           (UFG::qVector3 *)((char *)&v3[1].mNext + 4),
           0.0099999998,
           q0,
           q1,
           &v11)
      && v6 > v11 )
    {
      v5 = (UFG::TargetSphere *)v3;
      v6 = v11;
    }
    v3 = v3->mNext;
  }
  while ( v3 != (UFG::qNode<UFG::TargetSphere,UFG::TargetSphere> *)v4 );
  result = v5;
  if ( v6 <= 1.0 )
    *v7 = v6;
  return result;
}

// File Line: 1385
// RVA: 0x461980
void __fastcall UFG::BulletManager::DisableBulletImpacts(UFG::BulletManager *this, UFG::SimObject *simObject)
{
  UFG::qArray<UFG::qSymbol,0> *v2; // rsi
  __int64 v3; // rdi
  unsigned int v4; // er8
  UFG::SimObject *v5; // rbp
  UFG::qSymbol *v6; // rax
  unsigned int v7; // edx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  UFG::qSymbol *v10; // rcx

  if ( simObject )
  {
    v2 = &this->mSimObjectsToIgnore;
    v3 = this->mSimObjectsToIgnore.size;
    v4 = 0;
    v5 = simObject;
    if ( (_DWORD)v3 )
    {
      v6 = this->mSimObjectsToIgnore.p;
      while ( simObject->m_Name.mUID != v6->mUID )
      {
        ++v4;
        ++v6;
        if ( v4 >= (unsigned int)v3 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      v7 = this->mSimObjectsToIgnore.capacity;
      v8 = v3 + 1;
      if ( (signed int)v3 + 1 > v7 )
      {
        if ( v7 )
          v9 = 2 * v7;
        else
          v9 = 1;
        for ( ; v9 < v8; v9 *= 2 )
          ;
        if ( v9 <= 4 )
          v9 = 4;
        if ( v9 - v8 > 0x10000 )
          v9 = v3 + 65537;
        UFG::qArray<UFG::qSymbol,0>::Reallocate(&this->mSimObjectsToIgnore, v9, "qArray.Add");
      }
      v10 = v2->p;
      v2->size = v8;
      v10[v3] = v5->m_Name;
    }
  }
}

// File Line: 1405
// RVA: 0x463DA0
void __fastcall UFG::BulletManager::EnableBulletImpacts(UFG::BulletManager *this, UFG::SimObject *simObject)
{
  UFG::BulletManager *v2; // r10
  unsigned int v3; // ecx
  __int64 v4; // r9
  unsigned int v5; // edx
  UFG::qSymbol *v6; // rax
  unsigned int v7; // eax

  v2 = this;
  v3 = this->mSimObjectsToIgnore.size;
  v4 = 0i64;
  if ( v3 )
  {
    v5 = simObject->m_Name.mUID;
    v6 = v2->mSimObjectsToIgnore.p;
    while ( v5 != v6->mUID )
    {
      v4 = (unsigned int)(v4 + 1);
      ++v6;
      if ( (unsigned int)v4 >= v3 )
        return;
    }
    v2->mSimObjectsToIgnore.p[v4].mUID = v2->mSimObjectsToIgnore.p[v3 - 1].mUID;
    v7 = v2->mSimObjectsToIgnore.size;
    if ( v7 > 1 )
      v2->mSimObjectsToIgnore.size = v7 - 1;
    else
      v2->mSimObjectsToIgnore.size = 0;
  }
}

