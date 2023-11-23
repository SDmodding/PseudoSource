// File Line: 47
// RVA: 0x666D90
void __fastcall UFG::AttackData::AttackData(UFG::AttackData *this)
{
  this->pAttacker.mPrev = &this->pAttacker;
  this->pAttacker.mNext = &this->pAttacker;
  this->pAttacker.m_pPointer = 0i64;
  this->pAttacked.mPrev = &this->pAttacked;
  this->pAttacked.mNext = &this->pAttacked;
  this->pAttacked.m_pPointer = 0i64;
  this->fElapsedTime = 0.0;
}

// File Line: 55
// RVA: 0x66DBC0
UFG::AttackData *__fastcall UFG::AttackData::operator=(UFG::AttackData *this, UFG::AttackData *right)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::SimObject *v9; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pAttacked; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax

  m_pPointer = right->pAttacker.m_pPointer;
  if ( this->pAttacker.m_pPointer )
  {
    mPrev = this->pAttacker.mPrev;
    mNext = this->pAttacker.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->pAttacker.mPrev = &this->pAttacker;
    this->pAttacker.mNext = &this->pAttacker;
  }
  this->pAttacker.m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v7 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    p_mNode = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v7->mNext = &this->pAttacker;
    this->pAttacker.mPrev = v7;
    this->pAttacker.mNext = p_mNode;
    p_mNode->mPrev = &this->pAttacker;
  }
  v9 = right->pAttacked.m_pPointer;
  p_pAttacked = &this->pAttacked;
  if ( this->pAttacked.m_pPointer )
  {
    v11 = p_pAttacked->mPrev;
    v12 = this->pAttacked.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_pAttacked->mPrev = p_pAttacked;
    this->pAttacked.mNext = &this->pAttacked;
  }
  this->pAttacked.m_pPointer = v9;
  if ( v9 )
  {
    v13 = v9->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v13->mNext = p_pAttacked;
    p_pAttacked->mPrev = v13;
    this->pAttacked.mNext = &v9->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v9->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_pAttacked;
  }
  this->fElapsedTime = right->fElapsedTime;
  return this;
}

// File Line: 150
// RVA: 0x66EEE0
UFG::ComponentIDDesc *__fastcall UFG::PhysicsMoverInterface::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::PhysicsMoverInterface::_DescInit )
  {
    UFG::PhysicsMoverInterface::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::PhysicsMoverInterface::_DescInit = 1;
    UFG::PhysicsMoverInterface::_TypeUID = UFG::PhysicsMoverInterface::_TypeIDesc.mChildBitMask | (UFG::PhysicsMoverInterface::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PhysicsMoverInterface::_PhysicsMoverInterfaceTypeUID = UFG::PhysicsMoverInterface::_TypeIDesc.mChildBitMask | (UFG::PhysicsMoverInterface::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PhysicsMoverInterface::_TypeIDesc;
}

