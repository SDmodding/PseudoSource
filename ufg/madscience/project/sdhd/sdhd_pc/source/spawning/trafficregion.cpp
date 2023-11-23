// File Line: 58
// RVA: 0x155D520
__int64 dynamic_initializer_for__UFG::TrafficRegion::s_TrafficRegionList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TrafficRegion::s_TrafficRegionList__);
}

// File Line: 59
// RVA: 0x155D4A0
__int64 dynamic_initializer_for__UFG::TrafficRegion::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::TrafficRegion::AccessComponentDesc();
  *(_DWORD *)&UFG::TrafficRegion::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::TrafficRegion::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::TrafficRegion::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 76
// RVA: 0x5B1A80
void __fastcall UFG::TrafficRegion::TrafficRegion(
        UFG::TrafficRegion *this,
        UFG::qSymbol *name,
        UFG::SimObject *pSimObj)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *mPrev; // rax

  UFG::MarkerBase::MarkerBase(this, name, pSimObj, 0x30000u);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPointInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion>;
  this->mNext = &this->UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TrafficRegion::`vftable;
  *(_QWORD *)&this->mSpawnSet.mUID = -1i64;
  this->mActiveSpawnSet.mUID = -1;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mCenterCached.x = UFG::qVector3::msZero.x;
  this->mCenterCached.y = y;
  this->mCenterCached.z = z;
  UFG::SimComponent::AddType(this, UFG::TrafficRegion::_TrafficRegionTypeUID, "TrafficRegion");
  mPrev = UFG::TrafficRegion::s_TrafficRegionList.mNode.mPrev;
  UFG::TrafficRegion::s_TrafficRegionList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *)&UFG::TrafficRegion::s_TrafficRegionList;
  UFG::TrafficRegion::s_TrafficRegionList.mNode.mPrev = &this->UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion>;
  UFG::TrafficRegion::Initialize(this, pSimObj);
}

// File Line: 88
// RVA: 0x5B4C00
void __fastcall UFG::TrafficRegion::Initialize(UFG::TrafficRegion *this, UFG::SimObjectGame *pSimObj)
{
  UFG::SceneObjectProperties *v2; // rdi
  UFG::RegionComponent *ComponentOfTypeHK; // rax
  signed __int16 m_Flags; // cx
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::SceneObjectProperties *v8; // rcx
  UFG::qPropertySet *v9; // rax
  UFG::SimObject *v10; // rcx
  UFG::qSymbol *v11; // rsi
  UFG::qPropertySet *v12; // rax
  UFG::qSymbol *v13; // rdx
  UFG::qSymbol *v14; // rcx
  unsigned int mUID; // ecx
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 pPos; // [rsp+20h] [rbp-18h] BYREF

  v2 = 0i64;
  if ( pSimObj )
  {
    m_Flags = pSimObj->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::RegionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    pSimObj,
                                                    UFG::RegionComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::RegionComponent *)UFG::SimObject::GetComponentOfType(
                                                    pSimObj,
                                                    UFG::RegionComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  this->mpRegion = ComponentOfTypeHK;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSceneObj = m_pSimObject->m_pSceneObj;
  else
    m_pSceneObj = 0i64;
  this->mpSceneObjProps = m_pSceneObj;
  if ( m_pSimObject )
    v8 = m_pSimObject->m_pSceneObj;
  else
    v8 = 0i64;
  v9 = PropertyUtils::Get<UFG::qSymbol>(v8, (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnSet);
  v10 = this->m_pSimObject;
  v11 = (UFG::qSymbol *)v9;
  if ( v10 )
    v2 = v10->m_pSceneObj;
  v12 = PropertyUtils::Get<UFG::qSymbol>(v2, (UFG::qArray<unsigned long,0> *)&qSymbol_TrafficTimeSet);
  v13 = &UFG::gNullQSymbol;
  v14 = &UFG::gNullQSymbol;
  if ( v11 )
    v14 = v11;
  mUID = v14->mUID;
  if ( v12 )
    v13 = (UFG::qSymbol *)v12;
  this->mSpawnSet.mUID = mUID;
  this->mTimeSet = (UFG::qSymbol)v13->mUID;
  this->mActiveSpawnSet = UFG::gNullQSymbol;
  UFG::RegionComponent::GetCenter(this->mpRegion, &pPos);
  y = pPos.y;
  this->mCenterCached.x = pPos.x;
  z = pPos.z;
  this->mCenterCached.y = y;
  this->mCenterCached.z = z;
}

// File Line: 105
// RVA: 0x5B2050
void __fastcall UFG::TrafficRegion::~TrafficRegion(UFG::TrafficRegion *this)
{
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v2; // rdx
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *mPrev; // rcx
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *mNext; // rax
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v5; // rcx
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TrafficRegion::`vftable;
  if ( this == UFG::TrafficRegion::s_TrafficRegionpCurrentIterator )
    UFG::TrafficRegion::s_TrafficRegionpCurrentIterator = (UFG::TrafficRegion *)&this->mPrev[-7];
  v2 = &this->UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 119
// RVA: 0x5B3F60
UFG::qSymbol *__fastcall UFG::TrafficRegion::GetSpawnSet_UseTimeSetIfPresent(
        UFG::TrafficRegion *this,
        UFG::qSymbol *result)
{
  UFG::qBaseTreeRB *v4; // rdi
  UFG::TimeOfDayManager *Instance; // rax
  unsigned int mParent; // r10d
  unsigned int v7; // r9d
  int v8; // r8d
  UFG::qBaseNodeRB *v9; // rdx
  int v10; // eax
  int v11; // ecx
  UFG::qSymbol *v12; // rax
  UFG::qSymbol *v13; // rax

  if ( this->mTimeSet.mUID == -1 )
  {
    this->mActiveSpawnSet.mUID = this->mSpawnSet.mUID;
    goto LABEL_21;
  }
  v4 = UFG::TimeSetCache::ObtainTimeSet(&UFG::gTimeSetCache, &this->mTimeSet);
  Instance = UFG::TimeOfDayManager::GetInstance();
  mParent = (unsigned int)v4->mNULL.mParent;
  v7 = 0;
  v8 = (int)(float)(Instance->m_SecondsSinceMidnight * 0.00027777778);
  if ( !mParent )
    goto LABEL_21;
  v9 = v4->mNULL.mChild[0];
  while ( 1 )
  {
    v10 = (int)v9->mChild[1];
    if ( v10 == -1 )
      goto LABEL_17;
    v11 = HIDWORD(v9->mChild[1]);
    if ( v11 == -1 )
      goto LABEL_17;
    if ( v11 <= v10 )
      break;
    if ( v10 <= v8 && v8 < v11 )
      goto LABEL_10;
LABEL_17:
    ++v7;
    ++v9;
    if ( v7 >= mParent )
      goto LABEL_21;
  }
  if ( v11 >= v10 )
  {
    if ( v11 == v10 )
      goto LABEL_10;
    goto LABEL_17;
  }
  if ( v11 <= v8 && v10 > v8 )
    goto LABEL_17;
LABEL_10:
  v12 = (UFG::qSymbol *)v9->mChild[0];
  if ( v12 )
    v13 = v12 + 16;
  else
    v13 = &UFG::gNullQSymbol;
  this->mActiveSpawnSet = (UFG::qSymbol)v13->mUID;
LABEL_21:
  result->mUID = (unsigned int)this->mActiveSpawnSet;
  return result;
}

// File Line: 161
// RVA: 0x5B5540
void __fastcall UFG::TrafficRegion::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rsi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v6; // rax
  UFG::qSymbol result; // [rsp+70h] [rbp+18h] BYREF
  UFG::allocator::free_link *v8; // [rsp+78h] [rbp+20h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xA8ui64, "TrafficRegion", 0i64, 1u);
  v8 = v4;
  if ( v4 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v6 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(pSceneObj, (UFG::qWiseSymbol *)&result);
    UFG::TrafficRegion::TrafficRegion((UFG::TrafficRegion *)v4, v6, m_pSimObject);
  }
}

