// File Line: 29
// RVA: 0x532680
__int64 __fastcall UFG::SimObjectWeaponPropertiesComponent::GetTypeSize(UFG::qReflectInventory<UFG::ModelAsset> *this)
{
  return 232i64;
}

// File Line: 37
// RVA: 0x516BA0
void __fastcall UFG::CollectibleWeaponSpawnerComponent::CollectibleWeaponSpawnerComponent(
        UFG::CollectibleWeaponSpawnerComponent *this,
        UFG::qSymbol *name,
        UFG::SimObject *pSimObj)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool v8; // di
  bool *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *result; // [rsp+50h] [rbp+18h] BYREF

  UFG::CollectibleComponent::CollectibleComponent(this, name, pSimObj);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CollectibleWeaponSpawnerComponent::`vftable;
  result = &this->mpWeapon;
  this->mpWeapon.mPrev = &this->mpWeapon;
  this->mpWeapon.mNext = &this->mpWeapon;
  this->mpWeapon.m_pPointer = 0i64;
  *(_WORD *)&this->mSpawned = 256;
  this->mIgnoreCollectibleFlag = 0;
  this->mDefaultSpawnName.mUID = -1;
  UFG::SimComponent::AddType(
    this,
    UFG::CollectibleWeaponSpawnerComponent::_CollectibleWeaponSpawnerComponentTypeUID,
    "CollectibleWeaponSpawnerComponent");
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject || (m_pSceneObj = m_pSimObject->m_pSceneObj) == 0i64 )
  {
    mpWritableProperties = 0i64;
LABEL_6:
    if ( !mpWritableProperties )
      goto LABEL_11;
    goto LABEL_7;
  }
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  v8 = 1;
  v9 = UFG::qPropertySet::Get<bool>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&qSymbol_IgnoreCollectibleFlag,
         DEPTH_RECURSE);
  if ( !v9 || !*v9 )
    v8 = 0;
  this->mIgnoreCollectibleFlag = v8;
LABEL_11:
  this->mDefaultSpawnName.mUID = UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&result, &pSimObj->m_Name, "_weapon")->mUID;
}

// File Line: 52
// RVA: 0x51B2E0
void __fastcall UFG::CollectibleWeaponSpawnerComponent::~CollectibleWeaponSpawnerComponent(
        UFG::CollectibleWeaponSpawnerComponent *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpWeapon; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CollectibleWeaponSpawnerComponent::`vftable;
  p_mpWeapon = &this->mpWeapon;
  if ( this->mpWeapon.m_pPointer )
  {
    mPrev = p_mpWeapon->mPrev;
    mNext = p_mpWeapon->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpWeapon->mPrev = p_mpWeapon;
    p_mpWeapon->mNext = p_mpWeapon;
  }
  p_mpWeapon->m_pPointer = 0i64;
  v5 = p_mpWeapon->mPrev;
  v6 = p_mpWeapon->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpWeapon->mPrev = p_mpWeapon;
  p_mpWeapon->mNext = p_mpWeapon;
  UFG::CollectibleComponent::~CollectibleComponent(this);
}

// File Line: 56
// RVA: 0x556E30
void __fastcall UFG::CollectibleWeaponSpawnerComponent::TrySpawnWeapon(UFG::CollectibleWeaponSpawnerComponent *this)
{
  UFG::GameStatTracker *v2; // rax
  UFG::PersistentData::MapFloat *MapFloat; // rbx
  float Status; // xmm6_4
  float m_SecondsSinceMidnight; // xmm7_4
  bool v6; // zf
  UFG::SimObject *SimObject; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpWeapon; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObject *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v18; // rdx
  __int64 v19; // rdx
  UFG::qSymbol *v20; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v21; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qSymbol *v27; // rax
  UFG::SimObject *v28; // rsi
  UFG::qSymbol *v29; // rbp
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::SimComponent *v31; // rax
  UFG::qSymbol name; // [rsp+70h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+78h] [rbp+10h] BYREF

  v2 = UFG::GameStatTracker::Instance();
  MapFloat = UFG::GameStatTracker::GetMapFloat(v2, WeaponSpawnerTimestamp);
  Status = UFG::PersistentData::MapFloat::GetStatus(MapFloat, &this->m_pSimObject->m_Name);
  m_SecondsSinceMidnight = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
  if ( Status < m_SecondsSinceMidnight )
  {
    v6 = this->mpWeapon.m_pPointer == 0i64;
    name.mUID = this->mDefaultSpawnName.mUID;
    if ( v6 )
    {
      SimObject = (UFG::SimObject *)UFG::Simulation::GetSimObject(&UFG::gSim, &name);
      p_mpWeapon = &this->mpWeapon;
      if ( this->mpWeapon.m_pPointer )
      {
        mPrev = p_mpWeapon->mPrev;
        mNext = this->mpWeapon.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpWeapon->mPrev = p_mpWeapon;
        this->mpWeapon.mNext = &this->mpWeapon;
      }
      this->mpWeapon.m_pPointer = SimObject;
      if ( SimObject )
      {
        p_mNode = &SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v12 = SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v12->mNext = p_mpWeapon;
        p_mpWeapon->mPrev = v12;
        this->mpWeapon.mNext = p_mNode;
        p_mNode->mPrev = p_mpWeapon;
      }
    }
    m_pPointer = this->mpWeapon.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = m_pPointer->m_Components.p[11].m_pComponent;
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          vfptr = (unsigned int)m_pPointer[1].vfptr;
          size = m_pPointer->m_Components.size;
          if ( vfptr >= size )
          {
LABEL_18:
            m_pComponent = 0i64;
          }
          else
          {
            v18 = (__int64)&m_pPointer->m_Components.p[vfptr];
            while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
                 || (UFG::InventoryItemComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF) != 0 )
            {
              ++vfptr;
              v18 += 16i64;
              if ( vfptr >= size )
                goto LABEL_18;
            }
            m_pComponent = *(UFG::SimComponent **)v18;
          }
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InventoryItemComponent::_TypeUID);
        }
        if ( m_pComponent )
        {
          v19 = *(_QWORD *)&m_pComponent[1].m_Flags;
          if ( v19 )
          {
            if ( *(_QWORD *)(v19 + 40) )
            {
              if ( this->mPickedup )
              {
                v20 = UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, &name);
                v21 = &this->mpWeapon;
                v6 = this->mpWeapon.m_pPointer == 0i64;
                name.mUID = v20->mUID;
                if ( !v6 )
                {
                  v22 = v21->mPrev;
                  v23 = this->mpWeapon.mNext;
                  v22->mNext = v23;
                  v23->mPrev = v22;
                  v21->mPrev = v21;
                  this->mpWeapon.mNext = &this->mpWeapon;
                }
                this->mpWeapon.m_pPointer = 0i64;
              }
              else
              {
                UFG::PersistentData::MapFloat::SetStatus(
                  MapFloat,
                  &this->m_pSimObject->m_Name,
                  m_SecondsSinceMidnight + 3600.0);
                this->mPickedup = 1;
              }
            }
          }
        }
      }
    }
    else if ( this->mSpawned && !this->mPickedup )
    {
      UFG::PersistentData::MapFloat::SetStatus(MapFloat, &this->m_pSimObject->m_Name, m_SecondsSinceMidnight + 3600.0);
      *(_WORD *)&this->mSpawned = 256;
    }
    if ( !this->mpWeapon.m_pPointer )
    {
      m_pSimObject = this->m_pSimObject;
      if ( m_pSimObject && (m_pSceneObj = m_pSimObject->m_pSceneObj) != 0i64 )
      {
        mpWritableProperties = m_pSceneObj->mpWritableProperties;
        if ( mpWritableProperties )
        {
LABEL_39:
          v27 = UFG::qPropertySet::Get<UFG::qSymbol>(
                  mpWritableProperties,
                  (UFG::qArray<unsigned long,0> *)&qSymbol_WeaponType,
                  DEPTH_RECURSE);
          v28 = this->m_pSimObject;
          v29 = v27;
          if ( v28 )
          {
            m_pTransformNodeComponent = v28->m_pTransformNodeComponent;
            if ( m_pTransformNodeComponent )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              v31 = (UFG::SimComponent *)UFG::SpawnInfoInterface::SpawnObject(
                                           &name,
                                           v29,
                                           &m_pTransformNodeComponent->mWorldTransform,
                                           UnReferenced,
                                           0i64,
                                           0i64);
              UFG::qSafePointer<Creature,Creature>::operator=(
                (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->mpWeapon,
                v31);
              v6 = this->mpWeapon.m_pPointer == 0i64;
              this->mPickedup = 0;
              this->mSpawned = !v6;
            }
          }
          return;
        }
        mpWritableProperties = m_pSceneObj->mpConstProperties;
      }
      else
      {
        mpWritableProperties = 0i64;
      }
      if ( !mpWritableProperties )
        return;
      goto LABEL_39;
    }
  }
}

// File Line: 132
// RVA: 0x534AE0
void __fastcall UFG::CollectibleWeaponSpawnerComponent::HandleSpawnObject(
        UFG::CollectibleWeaponSpawnerComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        bool status)
{
  UFG::qPropertySet *mpWritableProperties; // rdx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  UFG::CollectibleComponent::HandleSpawnObject(this, mpWritableProperties, status);
  if ( status )
    UFG::CollectibleWeaponSpawnerComponent::TrySpawnWeapon(this);
}

// File Line: 142
// RVA: 0x533D10
void __fastcall UFG::CollectibleWeaponSpawnerComponent::HandleDespawnObject(
        UFG::CollectibleWeaponSpawnerComponent *this)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObject *v6; // rdi
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v11; // rdx
  __int64 v12; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpWeapon; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax

  m_pPointer = this->mpObject.m_pPointer;
  if ( m_pPointer )
  {
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, m_pPointer);
    p_mpObject = &this->mpObject;
    if ( this->mpObject.m_pPointer )
    {
      mPrev = p_mpObject->mPrev;
      mNext = this->mpObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpObject->mPrev = p_mpObject;
      this->mpObject.mNext = &this->mpObject;
    }
    this->mpObject.m_pPointer = 0i64;
  }
  v6 = this->mpWeapon.m_pPointer;
  if ( v6 )
  {
    m_Flags = v6->m_Flags;
    if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = v6->m_Components.p[11].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)v6[1].vfptr;
        size = v6->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_16:
          m_pComponent = 0i64;
        }
        else
        {
          v11 = (__int64)&v6->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
               || (UFG::InventoryItemComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v11 += 16i64;
            if ( vfptr >= size )
              goto LABEL_16;
          }
          m_pComponent = *(UFG::SimComponent **)v11;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(
                         this->mpWeapon.m_pPointer,
                         UFG::InventoryItemComponent::_TypeUID);
      }
      if ( m_pComponent )
      {
        v12 = *(_QWORD *)&m_pComponent[1].m_Flags;
        if ( !v12 || !*(_QWORD *)(v12 + 40) )
        {
          p_mpWeapon = &this->mpWeapon;
          if ( this->mpWeapon.m_pPointer )
          {
            v14 = p_mpWeapon->mPrev;
            v15 = this->mpWeapon.mNext;
            v14->mNext = v15;
            v15->mPrev = v14;
            p_mpWeapon->mPrev = p_mpWeapon;
            this->mpWeapon.mNext = &this->mpWeapon;
          }
          this->mpWeapon.m_pPointer = 0i64;
          UFG::SimObject::Destroy(v6);
        }
      }
    }
  }
  this->mSpawned = 0;
}

// File Line: 166
// RVA: 0x55AA90
void __fastcall UFG::CollectibleWeaponSpawnerComponent::Update(
        UFG::CollectibleWeaponSpawnerComponent *this,
        float deltaTime)
{
  if ( this->mEnabled )
  {
    if ( ((unsigned __int8 (__fastcall *)(UFG::CollectibleWeaponSpawnerComponent *))this->vfptr[19].__vecDelDtor)(this) )
      UFG::CollectibleWeaponSpawnerComponent::TrySpawnWeapon(this);
  }
}

// File Line: 177
// RVA: 0x5230D0
void __fastcall UFG::CollectibleWeaponSpawnerComponent::Collect(
        UFG::CollectibleWeaponSpawnerComponent *this,
        bool status)
{
  UFG::GameStatTracker *v4; // rax
  UFG::SimObject *m_pSimObject; // r8
  UFG::GameStatTracker *v6; // rsi
  UFG::SceneObjectProperties *m_pSceneObj; // r8
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qSymbol *v9; // rax

  if ( !this->mIgnoreCollectibleFlag )
  {
    v4 = UFG::GameStatTracker::Instance();
    m_pSimObject = this->m_pSimObject;
    v6 = v4;
    if ( m_pSimObject && (m_pSceneObj = m_pSimObject->m_pSceneObj) != 0i64 )
    {
      mpWritableProperties = m_pSceneObj->mpWritableProperties;
      if ( !mpWritableProperties )
        mpWritableProperties = m_pSceneObj->mpConstProperties;
    }
    else
    {
      mpWritableProperties = 0i64;
    }
    v9 = UFG::qPropertySet::Get<UFG::qSymbol>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&qSymbol_WeaponType,
           DEPTH_RECURSE);
    UFG::GameStatTracker::SetStat(v6, this->mType, v9, status);
  }
}

// File Line: 194
// RVA: 0x539F10
bool __fastcall UFG::CollectibleWeaponSpawnerComponent::IsCollected(UFG::CollectibleWeaponSpawnerComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qSymbol *v6; // rbx
  UFG::GameStatTracker *v7; // rax

  if ( this->mIgnoreCollectibleFlag )
    return 1;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject && (m_pSceneObj = m_pSimObject->m_pSceneObj) != 0i64 )
  {
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = m_pSceneObj->mpConstProperties;
  }
  else
  {
    mpWritableProperties = 0i64;
  }
  v6 = UFG::qPropertySet::Get<UFG::qSymbol>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&qSymbol_WeaponType,
         DEPTH_RECURSE);
  v7 = UFG::GameStatTracker::Instance();
  return UFG::GameStatTracker::GetStat(v7, this->mType, v6);
}

// File Line: 211
// RVA: 0x535560
bool __fastcall UFG::CollectibleWeaponSpawnerComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentCollectibleWeaponSpawner,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 217
// RVA: 0x544B40
UFG::CollectibleWeaponSpawnerComponent *__fastcall UFG::CollectibleWeaponSpawnerComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // edx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v7; // r8
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v9; // edx
  unsigned int v10; // r9d
  unsigned int v11; // edx
  unsigned int v12; // r9d
  unsigned int v13; // edx
  unsigned int v14; // r9d
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v17; // rsi
  UFG::SimObject *v18; // rbx
  UFG::qSymbol *v19; // rax
  _BYTE *v20; // rax
  _BYTE *v21; // rbx
  UFG::qSymbol result; // [rsp+60h] [rbp+8h] BYREF
  UFG::allocator::free_link *v23; // [rsp+68h] [rbp+10h]

  m_pSimObject = pSceneObj->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_35;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v7 = vfptr;
        if ( (p[vfptr].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++vfptr >= size )
          goto LABEL_10;
      }
LABEL_9:
      m_pComponent = p[v7].m_pComponent;
      goto LABEL_33;
    }
    goto LABEL_10;
  }
  if ( m_Flags < 0 )
  {
    v9 = (unsigned int)m_pSimObject[1].vfptr;
    v10 = m_pSimObject->m_Components.size;
    if ( v9 < v10 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v7 = v9;
        if ( (p[v9].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[v9].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_9;
        }
        if ( ++v9 >= v10 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v11 = (unsigned int)m_pSimObject[1].vfptr;
    v12 = m_pSimObject->m_Components.size;
    if ( v11 < v12 )
    {
      p = m_pSimObject->m_Components.p;
      while ( 1 )
      {
        v7 = v11;
        if ( (p[v11].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[v11].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_9;
        }
        if ( ++v11 >= v12 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v13 = (unsigned int)m_pSimObject[1].vfptr;
    v14 = m_pSimObject->m_Components.size;
    if ( v13 < v14 )
    {
      p = m_pSimObject->m_Components.p;
      do
      {
        v7 = v13;
        if ( (p[v13].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && (UFG::CollectibleComponent::_TypeUID & ~p[v13].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_9;
        }
      }
      while ( ++v13 < v14 );
    }
LABEL_10:
    m_pComponent = 0i64;
    goto LABEL_33;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CollectibleComponent::_TypeUID);
LABEL_33:
  if ( m_pComponent )
    return 0i64;
LABEL_35:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v17 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE8ui64, "CollectibleWeaponSpawnerComponent", 0i64, 1u);
  v23 = v17;
  if ( v17 )
  {
    v18 = pSceneObj->m_pSimObject;
    v19 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(
                            pSceneObj,
                            (UFG::qWiseSymbol *)&result);
    UFG::CollectibleWeaponSpawnerComponent::CollectibleWeaponSpawnerComponent(
      (UFG::CollectibleWeaponSpawnerComponent *)v17,
      v19,
      v18);
    v21 = v20;
  }
  else
  {
    v21 = 0i64;
  }
  v21[194] = (*(__int64 (__fastcall **)(_BYTE *))(*(_QWORD *)v21 + 152i64))(v21);
  return (UFG::CollectibleWeaponSpawnerComponent *)v21;
}

