// File Line: 99
// RVA: 0x407530
UFG::ComponentIDDesc *__fastcall UFG::PedSpawningInfo::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::PedSpawningInfo::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::PedSpawningInfo::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::PedSpawningInfo::_TypeIDesc.mChildren = v0->mChildren;
    UFG::PedSpawningInfo::_DescInit = 1;
    UFG::PedSpawningInfo::_TypeUID = UFG::PedSpawningInfo::_TypeIDesc.mChildBitMask | (UFG::PedSpawningInfo::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PedSpawningInfo::_PedSpawningInfoTypeUID = UFG::PedSpawningInfo::_TypeIDesc.mChildBitMask | (UFG::PedSpawningInfo::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PedSpawningInfo::_TypeIDesc;
}

// File Line: 271
// RVA: 0x40C870
UFG::qSymbolUC *__fastcall UFG::PedSpawningInfo::GetRigNameSymbol(UFG::PedSpawningInfo *this, UFG::qSymbolUC *result)
{
  result->mUID = (unsigned int)this->mRigNameSymbol;
  return result;
}

// File Line: 286
// RVA: 0x40C470
UFG::qSymbol *__fastcall UFG::PedSpawningInfo::GetLifetimeNameSymbol(UFG::PedSpawningInfo *this, UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->mLifetimeInstanceNameSymbol;
  return result;
}

// File Line: 305
// RVA: 0x40BF20
UFG::qSymbol *__fastcall UFG::PedSpawningInfo::GetArchetypePropertySetName(UFG::PedSpawningInfo *this, UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->mArchetypePropSetSymbol;
  return result;
}

// File Line: 313
// RVA: 0x40BFC0
UFG::qSymbol *__fastcall UFG::PedSpawningInfo::GetFactionSymbol(UFG::PedSpawningInfo *this, UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->mFactionSymbol;
  return result;
}

// File Line: 450
// RVA: 0x404BB0
void __fastcall UFG::ActiveSpawnSetInfo::ActiveSpawnSetInfo(UFG::ActiveSpawnSetInfo *this)
{
  this->mpPropertySet = 0i64;
  *(_QWORD *)&this->mRefCount = 0i64;
  this->mPercentOfGlobalPopulation = 0.0;
  this->mMediumPriorityOverride = 0;
  this->mSpawnInfoArray.p = 0i64;
  *(_QWORD *)&this->mSpawnInfoArray.size = 0i64;
  this->mRareSpawnInfoArray.p = 0i64;
  *(_QWORD *)&this->mRareSpawnInfoArray.size = 0i64;
}

// File Line: 466
// RVA: 0x404CA0
void __fastcall UFG::DisabledThugZone::DisabledThugZone(UFG::DisabledThugZone *this)
{
  UFG::DisabledThugZone *v1; // rbx

  v1 = this;
  this->mNameSymbol.mUID = -1;
  UFG::qSymbol::set_null((UFG::qSymbol *)this);
  v1->mElapsedTotalWhenDisabled = 0.0;
}

