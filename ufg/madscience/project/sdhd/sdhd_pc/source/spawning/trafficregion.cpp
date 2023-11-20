// File Line: 58
// RVA: 0x155D520
__int64 dynamic_initializer_for__UFG::TrafficRegion::s_TrafficRegionList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TrafficRegion::s_TrafficRegionList__);
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
void __fastcall UFG::TrafficRegion::TrafficRegion(UFG::TrafficRegion *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::SimObject *v3; // rdi
  UFG::TrafficRegion *v4; // rsi
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v5; // rbx
  float v6; // xmm1_4
  float v7; // xmm2_4
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v8; // rax

  v3 = pSimObj;
  v4 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, pSimObj, 0x30000u);
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPointInterface::`vftable;
  v5 = (UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TrafficRegion::`vftable;
  *(_QWORD *)&v4->mSpawnSet.mUID = -1i64;
  v4->mActiveSpawnSet.mUID = -1;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  v4->mCenterCached.x = UFG::qVector3::msZero.x;
  v4->mCenterCached.y = v6;
  v4->mCenterCached.z = v7;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::TrafficRegion::_TrafficRegionTypeUID,
    "TrafficRegion");
  v8 = UFG::TrafficRegion::s_TrafficRegionList.mNode.mPrev;
  UFG::TrafficRegion::s_TrafficRegionList.mNode.mPrev->mNext = (UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *)&v4->mPrev;
  v5->mPrev = v8;
  v4->mNext = (UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *)&UFG::TrafficRegion::s_TrafficRegionList;
  UFG::TrafficRegion::s_TrafficRegionList.mNode.mPrev = (UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *)&v4->mPrev;
  UFG::TrafficRegion::Initialize(v4, v3);
}

// File Line: 88
// RVA: 0x5B4C00
void __fastcall UFG::TrafficRegion::Initialize(UFG::TrafficRegion *this, UFG::SimObject *pSimObj)
{
  UFG::SceneObjectProperties *v2; // rdi
  UFG::TrafficRegion *v3; // rbx
  UFG::SimComponent *v4; // rax
  unsigned __int16 v5; // cx
  UFG::SimObject *v6; // rax
  UFG::SceneObjectProperties *v7; // rcx
  UFG::SceneObjectProperties *v8; // rcx
  UFG::qPropertySet *v9; // rax
  UFG::SimObject *v10; // rcx
  UFG::qSymbol *v11; // rsi
  UFG::qPropertySet *v12; // rax
  UFG::qSymbol *v13; // rdx
  UFG::qSymbol *v14; // rcx
  unsigned int v15; // ecx
  float v16; // xmm1_4
  float v17; // xmm0_4
  UFG::qVector3 pPos; // [rsp+20h] [rbp-18h]

  v2 = 0i64;
  v3 = this;
  if ( pSimObj )
  {
    v5 = pSimObj->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObj, UFG::RegionComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObj, UFG::RegionComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObj, UFG::RegionComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType(pSimObj, UFG::RegionComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pSimObj, UFG::RegionComponent::_TypeUID);
    }
  }
  else
  {
    v4 = 0i64;
  }
  v3->mpRegion = (UFG::RegionComponent *)v4;
  v6 = v3->m_pSimObject;
  if ( v6 )
    v7 = v6->m_pSceneObj;
  else
    v7 = 0i64;
  v3->mpSceneObjProps = v7;
  if ( v6 )
    v8 = v6->m_pSceneObj;
  else
    v8 = 0i64;
  v9 = PropertyUtils::Get<UFG::qSymbol>(v8, (UFG::qSymbol *)&qSymbol_SpawnSet.mUID);
  v10 = v3->m_pSimObject;
  v11 = (UFG::qSymbol *)v9;
  if ( v10 )
    v2 = v10->m_pSceneObj;
  v12 = PropertyUtils::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&qSymbol_TrafficTimeSet.mUID);
  v13 = &UFG::gNullQSymbol;
  v14 = &UFG::gNullQSymbol;
  if ( v11 )
    v14 = v11;
  v15 = v14->mUID;
  if ( v12 )
    v13 = (UFG::qSymbol *)v12;
  v3->mSpawnSet.mUID = v15;
  v3->mTimeSet = (UFG::qSymbol)v13->mUID;
  v3->mActiveSpawnSet = UFG::gNullQSymbol;
  UFG::RegionComponent::GetCenter(v3->mpRegion, &pPos);
  v16 = pPos.y;
  v3->mCenterCached.x = pPos.x;
  v17 = pPos.z;
  v3->mCenterCached.y = v16;
  v3->mCenterCached.z = v17;
}

// File Line: 105
// RVA: 0x5B2050
void __fastcall UFG::TrafficRegion::~TrafficRegion(UFG::TrafficRegion *this)
{
  UFG::TrafficRegion *v1; // r8
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v2; // rdx
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v3; // rcx
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v4; // rax
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v5; // rcx
  UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TrafficRegion::`vftable;
  if ( this == UFG::TrafficRegion::s_TrafficRegionpCurrentIterator )
    UFG::TrafficRegion::s_TrafficRegionpCurrentIterator = (UFG::TrafficRegion *)&this->mPrev[-7];
  v2 = (UFG::qNode<UFG::TrafficRegion,UFG::TrafficRegion> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 119
// RVA: 0x5B3F60
UFG::qSymbol *__fastcall UFG::TrafficRegion::GetSpawnSet_UseTimeSetIfPresent(UFG::TrafficRegion *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rsi
  UFG::TrafficRegion *v3; // rbx
  UFG::qBaseTreeRB *v4; // rdi
  UFG::TimeOfDayManager *v5; // rax
  unsigned int v6; // er10
  unsigned int v7; // er9
  signed int v8; // er8
  UFG::qBaseNodeRB *v9; // rdx
  signed int v10; // eax
  signed int v11; // ecx
  UFG::qSymbol *v12; // rax
  UFG::qSymbol *v13; // rax

  v2 = result;
  v3 = this;
  if ( this->mTimeSet.mUID == -1 )
  {
    this->mActiveSpawnSet.mUID = this->mSpawnSet.mUID;
    goto LABEL_21;
  }
  v4 = UFG::TimeSetCache::ObtainTimeSet(&UFG::gTimeSetCache, &this->mTimeSet);
  v5 = UFG::TimeOfDayManager::GetInstance();
  v6 = (unsigned int)v4->mNULL.mParent;
  v7 = 0;
  v8 = (signed int)(float)(v5->m_SecondsSinceMidnight * 0.00027777778);
  if ( !v6 )
    goto LABEL_21;
  v9 = v4->mNULL.mChild[0];
  while ( 1 )
  {
    v10 = (signed int)v9->mChild[1];
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
    if ( v7 >= v6 )
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
  v3->mActiveSpawnSet = (UFG::qSymbol)v13->mUID;
LABEL_21:
  v2->mUID = (unsigned int)v3->mActiveSpawnSet;
  return v2;
}

// File Line: 161
// RVA: 0x5B5540
void __fastcall UFG::TrafficRegion::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbp
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rsi
  UFG::SimObject *v5; // rbx
  UFG::qSymbol *v6; // rax
  UFG::qSymbol result; // [rsp+70h] [rbp+18h]
  UFG::allocator::free_link *v8; // [rsp+78h] [rbp+20h]

  v2 = pSceneObj;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0xA8ui64, "TrafficRegion", 0i64, 1u);
  v8 = v4;
  if ( v4 )
  {
    v5 = v2->m_pSimObject;
    v6 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v2, &result);
    UFG::TrafficRegion::TrafficRegion((UFG::TrafficRegion *)v4, v6, v5);
  }
}

