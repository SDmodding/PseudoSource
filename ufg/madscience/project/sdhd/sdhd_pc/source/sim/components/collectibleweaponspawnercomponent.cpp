// File Line: 29
// RVA: 0x532680
signed __int64 __fastcall UFG::SimObjectWeaponPropertiesComponent::GetTypeSize(UFG::qReflectInventory<UFG::ModelAsset> *this)
{
  return 232i64;
}

// File Line: 37
// RVA: 0x516BA0
void __fastcall UFG::CollectibleWeaponSpawnerComponent::CollectibleWeaponSpawnerComponent(UFG::CollectibleWeaponSpawnerComponent *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::SimObject *v3; // rsi
  UFG::CollectibleWeaponSpawnerComponent *v4; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rax
  UFG::SimObject *v6; // rax
  UFG::SceneObjectProperties *v7; // rax
  UFG::qPropertySet *v8; // rcx
  char v9; // di
  bool *v10; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *result; // [rsp+50h] [rbp+18h]

  v3 = pSimObj;
  v4 = this;
  UFG::CollectibleComponent::CollectibleComponent((UFG::CollectibleComponent *)&this->vfptr, name, pSimObj);
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CollectibleWeaponSpawnerComponent::`vftable;
  v5 = &v4->mpWeapon;
  result = v5;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v4->mpWeapon.m_pPointer = 0i64;
  *(_WORD *)&v4->mSpawned = 256;
  v4->mIgnoreCollectibleFlag = 0;
  v4->mDefaultSpawnName.mUID = -1;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::CollectibleWeaponSpawnerComponent::_CollectibleWeaponSpawnerComponentTypeUID,
    "CollectibleWeaponSpawnerComponent");
  v6 = v4->m_pSimObject;
  if ( !v6 || (v7 = v6->m_pSceneObj) == 0i64 )
  {
    v8 = 0i64;
LABEL_6:
    if ( !v8 )
      goto LABEL_11;
    goto LABEL_7;
  }
  v8 = v7->mpWritableProperties;
  if ( !v8 )
  {
    v8 = v7->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  v9 = 1;
  v10 = UFG::qPropertySet::Get<bool>(v8, (UFG::qSymbol *)&qSymbol_IgnoreCollectibleFlag.mUID, DEPTH_RECURSE);
  if ( !v10 || !*v10 )
    v9 = 0;
  v4->mIgnoreCollectibleFlag = v9;
LABEL_11:
  v4->mDefaultSpawnName = (UFG::qSymbol)UFG::qSymbol::create_suffix((UFG::qSymbol *)&result, &v3->m_Name, "_weapon")->mUID;
}

// File Line: 52
// RVA: 0x51B2E0
void __fastcall UFG::CollectibleWeaponSpawnerComponent::~CollectibleWeaponSpawnerComponent(UFG::CollectibleWeaponSpawnerComponent *this)
{
  UFG::CollectibleWeaponSpawnerComponent *v1; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CollectibleWeaponSpawnerComponent::`vftable;
  v2 = &this->mpWeapon;
  if ( this->mpWeapon.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  UFG::CollectibleComponent::~CollectibleComponent((UFG::CollectibleComponent *)&v1->vfptr);
}

// File Line: 56
// RVA: 0x556E30
void __fastcall UFG::CollectibleWeaponSpawnerComponent::TrySpawnWeapon(UFG::CollectibleWeaponSpawnerComponent *this)
{
  UFG::CollectibleWeaponSpawnerComponent *v1; // rdi
  UFG::GameStatTracker *v2; // rax
  UFG::PersistentData::MapFloat *v3; // rbx
  float v4; // xmm6_4
  float v5; // xmm7_4
  bool v6; // zf
  UFG::qBaseNodeRB *v7; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v8; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qBaseNodeRB **v11; // rcx
  UFG::qBaseNodeRB *v12; // rax
  UFG::SimObject *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  unsigned int v16; // er8
  unsigned int v17; // er9
  signed __int64 v18; // rdx
  __int64 v19; // rdx
  UFG::qSymbol *v20; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v21; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::SimObject *v24; // rax
  UFG::SceneObjectProperties *v25; // rax
  UFG::qPropertySet *v26; // rcx
  UFG::qSymbol *v27; // rax
  UFG::SimObject *v28; // rsi
  UFG::qSymbol *v29; // rbp
  UFG::TransformNodeComponent *v30; // rsi
  UFG::SimComponent *v31; // rax
  UFG::qSymbol name; // [rsp+70h] [rbp+8h]
  UFG::qSymbol result; // [rsp+78h] [rbp+10h]

  v1 = this;
  v2 = UFG::GameStatTracker::Instance();
  v3 = UFG::GameStatTracker::GetMapFloat(v2, WeaponSpawnerTimestamp);
  v4 = UFG::PersistentData::MapFloat::GetStatus(v3, &v1->m_pSimObject->m_Name);
  v5 = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
  if ( v4 < v5 )
  {
    v6 = v1->mpWeapon.m_pPointer == 0i64;
    name.mUID = v1->mDefaultSpawnName.mUID;
    if ( v6 )
    {
      v7 = UFG::Simulation::GetSimObject(&UFG::gSim, &name);
      v8 = &v1->mpWeapon;
      if ( v1->mpWeapon.m_pPointer )
      {
        v9 = v8->mPrev;
        v10 = v1->mpWeapon.mNext;
        v9->mNext = v10;
        v10->mPrev = v9;
        v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
        v1->mpWeapon.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpWeapon.mPrev;
      }
      v1->mpWeapon.m_pPointer = (UFG::SimObject *)v7;
      if ( v7 )
      {
        v11 = v7->mChild;
        v12 = v7->mChild[0];
        v12->mChild[0] = (UFG::qBaseNodeRB *)v8;
        v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v12;
        v1->mpWeapon.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v11;
        *v11 = (UFG::qBaseNodeRB *)v8;
      }
    }
    v13 = v1->mpWeapon.m_pPointer;
    if ( v13 )
    {
      v14 = v13->m_Flags;
      if ( !((v14 >> 14) & 1) && (v14 & 0x8000u) == 0 )
      {
        if ( (v14 >> 13) & 1 )
        {
          v15 = v13->m_Components.p[11].m_pComponent;
        }
        else if ( (v14 >> 12) & 1 )
        {
          v16 = (unsigned int)v13[1].vfptr;
          v17 = v13->m_Components.size;
          if ( v16 >= v17 )
          {
LABEL_18:
            v15 = 0i64;
          }
          else
          {
            v18 = (signed __int64)&v13->m_Components.p[v16];
            while ( (*(_DWORD *)(v18 + 8) & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
                 || UFG::InventoryItemComponent::_TypeUID & ~*(_DWORD *)(v18 + 8) & 0x1FFFFFF )
            {
              ++v16;
              v18 += 16i64;
              if ( v16 >= v17 )
                goto LABEL_18;
            }
            v15 = *(UFG::SimComponent **)v18;
          }
        }
        else
        {
          v15 = UFG::SimObject::GetComponentOfType(v13, UFG::InventoryItemComponent::_TypeUID);
        }
        if ( v15 )
        {
          v19 = *(_QWORD *)&v15[1].m_Flags;
          if ( v19 )
          {
            if ( *(_QWORD *)(v19 + 40) )
            {
              if ( v1->mPickedup )
              {
                v20 = UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, &name);
                v21 = &v1->mpWeapon;
                v6 = v1->mpWeapon.m_pPointer == 0i64;
                name.mUID = v20->mUID;
                if ( !v6 )
                {
                  v22 = v21->mPrev;
                  v23 = v1->mpWeapon.mNext;
                  v22->mNext = v23;
                  v23->mPrev = v22;
                  v21->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v21->mPrev;
                  v1->mpWeapon.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpWeapon.mPrev;
                }
                v1->mpWeapon.m_pPointer = 0i64;
              }
              else
              {
                UFG::PersistentData::MapFloat::SetStatus(v3, &v1->m_pSimObject->m_Name, v5 + 3600.0);
                v1->mPickedup = 1;
              }
            }
          }
        }
      }
    }
    else if ( v1->mSpawned && !v1->mPickedup )
    {
      UFG::PersistentData::MapFloat::SetStatus(v3, &v1->m_pSimObject->m_Name, v5 + 3600.0);
      *(_WORD *)&v1->mSpawned = 256;
    }
    if ( !v1->mpWeapon.m_pPointer )
    {
      v24 = v1->m_pSimObject;
      if ( v24 && (v25 = v24->m_pSceneObj) != 0i64 )
      {
        v26 = v25->mpWritableProperties;
        if ( v26 )
        {
LABEL_39:
          v27 = UFG::qPropertySet::Get<UFG::qSymbol>(v26, (UFG::qSymbol *)&qSymbol_WeaponType.mUID, DEPTH_RECURSE);
          v28 = v1->m_pSimObject;
          v29 = v27;
          if ( v28 )
          {
            v30 = v28->m_pTransformNodeComponent;
            if ( v30 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v30);
              v31 = (UFG::SimComponent *)UFG::SpawnInfoInterface::SpawnObject(
                                           &name,
                                           v29,
                                           &v30->mWorldTransform,
                                           0,
                                           0i64,
                                           0i64);
              UFG::qSafePointer<Creature,Creature>::operator=(
                (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v1->mpWeapon,
                v31);
              v6 = v1->mpWeapon.m_pPointer == 0i64;
              v1->mPickedup = 0;
              v1->mSpawned = !v6;
            }
          }
          return;
        }
        v26 = v25->mpConstProperties;
      }
      else
      {
        v26 = 0i64;
      }
      if ( !v26 )
        return;
      goto LABEL_39;
    }
  }
}

// File Line: 132
// RVA: 0x534AE0
void __fastcall UFG::CollectibleWeaponSpawnerComponent::HandleSpawnObject(UFG::CollectibleWeaponSpawnerComponent *this, UFG::SceneObjectProperties *pSceneObj, bool status)
{
  UFG::SceneObjectProperties *v3; // rax
  UFG::qPropertySet *v4; // rdx
  bool v5; // di
  UFG::CollectibleWeaponSpawnerComponent *v6; // rbx

  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  v5 = status;
  v6 = this;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  UFG::CollectibleComponent::HandleSpawnObject((UFG::CollectibleComponent *)&this->vfptr, v4, status);
  if ( v5 )
    UFG::CollectibleWeaponSpawnerComponent::TrySpawnWeapon(v6);
}

// File Line: 142
// RVA: 0x533D10
void __fastcall UFG::CollectibleWeaponSpawnerComponent::HandleDespawnObject(UFG::CollectibleWeaponSpawnerComponent *this)
{
  UFG::SimObject *v1; // rdx
  UFG::CollectibleWeaponSpawnerComponent *v2; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::SimObject *v6; // rdi
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax
  unsigned int v9; // er8
  unsigned int v10; // er9
  signed __int64 v11; // rdx
  __int64 v12; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax

  v1 = this->mpObject.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v1);
    v3 = &v2->mpObject;
    if ( v2->mpObject.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = v2->mpObject.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      v2->mpObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpObject.mPrev;
    }
    v2->mpObject.m_pPointer = 0i64;
  }
  v6 = v2->mpWeapon.m_pPointer;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( !((v7 >> 14) & 1) && (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = v6->m_Components.p[11].m_pComponent;
      }
      else if ( (v7 >> 12) & 1 )
      {
        v9 = (unsigned int)v6[1].vfptr;
        v10 = v6->m_Components.size;
        if ( v9 >= v10 )
        {
LABEL_16:
          v8 = 0i64;
        }
        else
        {
          v11 = (signed __int64)&v6->m_Components.p[v9];
          while ( (*(_DWORD *)(v11 + 8) & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
               || UFG::InventoryItemComponent::_TypeUID & ~*(_DWORD *)(v11 + 8) & 0x1FFFFFF )
          {
            ++v9;
            v11 += 16i64;
            if ( v9 >= v10 )
              goto LABEL_16;
          }
          v8 = *(UFG::SimComponent **)v11;
        }
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType(v2->mpWeapon.m_pPointer, UFG::InventoryItemComponent::_TypeUID);
      }
      if ( v8 )
      {
        v12 = *(_QWORD *)&v8[1].m_Flags;
        if ( !v12 || !*(_QWORD *)(v12 + 40) )
        {
          v13 = &v2->mpWeapon;
          if ( v2->mpWeapon.m_pPointer )
          {
            v14 = v13->mPrev;
            v15 = v2->mpWeapon.mNext;
            v14->mNext = v15;
            v15->mPrev = v14;
            v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
            v2->mpWeapon.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpWeapon.mPrev;
          }
          v2->mpWeapon.m_pPointer = 0i64;
          UFG::SimObject::Destroy(v6);
        }
      }
    }
  }
  v2->mSpawned = 0;
}

// File Line: 166
// RVA: 0x55AA90
void __fastcall UFG::CollectibleWeaponSpawnerComponent::Update(UFG::CollectibleWeaponSpawnerComponent *this, float deltaTime)
{
  UFG::CollectibleWeaponSpawnerComponent *v2; // rbx

  v2 = this;
  if ( this->mEnabled )
  {
    if ( ((unsigned __int8 (*)(void))this->vfptr[19].__vecDelDtor)() )
      UFG::CollectibleWeaponSpawnerComponent::TrySpawnWeapon(v2);
  }
}

// File Line: 177
// RVA: 0x5230D0
void __fastcall UFG::CollectibleWeaponSpawnerComponent::Collect(UFG::CollectibleWeaponSpawnerComponent *this, bool status)
{
  bool v2; // di
  UFG::CollectibleWeaponSpawnerComponent *v3; // rbx
  UFG::GameStatTracker *v4; // rax
  UFG::SimObject *v5; // r8
  UFG::GameStatTracker *v6; // rsi
  UFG::SceneObjectProperties *v7; // r8
  UFG::qPropertySet *v8; // rcx
  UFG::qSymbol *v9; // rax

  v2 = status;
  v3 = this;
  if ( !this->mIgnoreCollectibleFlag )
  {
    v4 = UFG::GameStatTracker::Instance();
    v5 = v3->m_pSimObject;
    v6 = v4;
    if ( v5 && (v7 = v5->m_pSceneObj) != 0i64 )
    {
      v8 = v7->mpWritableProperties;
      if ( !v8 )
        v8 = v7->mpConstProperties;
    }
    else
    {
      v8 = 0i64;
    }
    v9 = UFG::qPropertySet::Get<UFG::qSymbol>(v8, (UFG::qSymbol *)&qSymbol_WeaponType.mUID, DEPTH_RECURSE);
    UFG::GameStatTracker::SetStat(v6, v3->mType, v9, v2);
  }
}

// File Line: 194
// RVA: 0x539F10
bool __fastcall UFG::CollectibleWeaponSpawnerComponent::IsCollected(UFG::CollectibleWeaponSpawnerComponent *this)
{
  UFG::CollectibleWeaponSpawnerComponent *v1; // rdi
  UFG::SimObject *v3; // rax
  UFG::SceneObjectProperties *v4; // rax
  UFG::qPropertySet *v5; // rcx
  UFG::qSymbol *v6; // rbx
  UFG::GameStatTracker *v7; // rax

  v1 = this;
  if ( this->mIgnoreCollectibleFlag )
    return 1;
  v3 = this->m_pSimObject;
  if ( v3 && (v4 = v3->m_pSceneObj) != 0i64 )
  {
    v5 = v4->mpWritableProperties;
    if ( !v5 )
      v5 = v4->mpConstProperties;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = UFG::qPropertySet::Get<UFG::qSymbol>(v5, (UFG::qSymbol *)&qSymbol_WeaponType.mUID, DEPTH_RECURSE);
  v7 = UFG::GameStatTracker::Instance();
  return UFG::GameStatTracker::GetStat(v7, v1->mType, v6);
}

// File Line: 211
// RVA: 0x535560
bool __fastcall UFG::CollectibleWeaponSpawnerComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentCollectibleWeaponSpawner.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 217
// RVA: 0x544B40
UFG::CollectibleWeaponSpawnerComponent *__fastcall UFG::CollectibleWeaponSpawnerComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbp
  UFG::SimObject *v2; // rcx
  unsigned __int16 v3; // dx
  unsigned int v4; // edx
  unsigned int v5; // er9
  UFG::SimComponentHolder *v6; // rbx
  signed __int64 v7; // r8
  UFG::SimComponent *v8; // rax
  unsigned int v9; // edx
  unsigned int v10; // er9
  unsigned int v11; // edx
  unsigned int v12; // er9
  unsigned int v13; // edx
  unsigned int v14; // er9
  UFG::qMemoryPool *v16; // rax
  UFG::allocator::free_link *v17; // rsi
  UFG::SimObject *v18; // rbx
  UFG::qSymbol *v19; // rax
  _BYTE *v20; // rax
  _BYTE *v21; // rbx
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]
  UFG::allocator::free_link *v23; // [rsp+68h] [rbp+10h]

  v1 = pSceneObj;
  v2 = pSceneObj->m_pSimObject;
  if ( !v2 )
    goto LABEL_35;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = (unsigned int)v2[1].vfptr;
    v5 = v2->m_Components.size;
    if ( v4 < v5 )
    {
      v6 = v2->m_Components.p;
      while ( 1 )
      {
        v7 = v4;
        if ( (v6[v4].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v4].m_TypeUID & 0x1FFFFFF) )
        {
          break;
        }
        if ( ++v4 >= v5 )
          goto LABEL_10;
      }
LABEL_9:
      v8 = v6[v7].m_pComponent;
      goto LABEL_33;
    }
    goto LABEL_10;
  }
  if ( (v3 & 0x8000u) != 0 )
  {
    v9 = (unsigned int)v2[1].vfptr;
    v10 = v2->m_Components.size;
    if ( v9 < v10 )
    {
      v6 = v2->m_Components.p;
      while ( 1 )
      {
        v7 = v9;
        if ( (v6[v9].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v9].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_9;
        }
        if ( ++v9 >= v10 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (v3 >> 13) & 1 )
  {
    v11 = (unsigned int)v2[1].vfptr;
    v12 = v2->m_Components.size;
    if ( v11 < v12 )
    {
      v6 = v2->m_Components.p;
      while ( 1 )
      {
        v7 = v11;
        if ( (v6[v11].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v11].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_9;
        }
        if ( ++v11 >= v12 )
          goto LABEL_10;
      }
    }
    goto LABEL_10;
  }
  if ( (v3 >> 12) & 1 )
  {
    v13 = (unsigned int)v2[1].vfptr;
    v14 = v2->m_Components.size;
    if ( v13 < v14 )
    {
      v6 = v2->m_Components.p;
      do
      {
        v7 = v13;
        if ( (v6[v13].m_TypeUID & 0xFE000000) == (UFG::CollectibleComponent::_TypeUID & 0xFE000000)
          && !(UFG::CollectibleComponent::_TypeUID & ~v6[v13].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_9;
        }
      }
      while ( ++v13 < v14 );
    }
LABEL_10:
    v8 = 0i64;
    goto LABEL_33;
  }
  v8 = UFG::SimObject::GetComponentOfType(v2, UFG::CollectibleComponent::_TypeUID);
LABEL_33:
  if ( v8 )
    return 0i64;
LABEL_35:
  v16 = UFG::GetSimulationMemoryPool();
  v17 = UFG::qMemoryPool::Allocate(v16, 0xE8ui64, "CollectibleWeaponSpawnerComponent", 0i64, 1u);
  v23 = v17;
  if ( v17 )
  {
    v18 = v1->m_pSimObject;
    v19 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
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

