// File Line: 47
// RVA: 0x666D90
void __fastcall UFG::AttackData::AttackData(UFG::AttackData *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v1; // [rsp+28h] [rbp+10h]

  this->pAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->pAttacker.mPrev;
  this->pAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->pAttacker.mPrev;
  this->pAttacker.m_pPointer = 0i64;
  v1 = &this->pAttacked;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  this->pAttacked.m_pPointer = 0i64;
  this->fElapsedTime = 0.0;
}

// File Line: 55
// RVA: 0x66DBC0
UFG::AttackData *__fastcall UFG::AttackData::operator=(UFG::AttackData *this, UFG::AttackData *right)
{
  UFG::AttackData *v2; // r9
  UFG::SimObject *v3; // rcx
  UFG::AttackData *v4; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::SimObject *v9; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax

  v2 = this;
  v3 = right->pAttacker.m_pPointer;
  v4 = right;
  if ( v2->pAttacker.m_pPointer )
  {
    v5 = v2->pAttacker.mPrev;
    v6 = v2->pAttacker.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->pAttacker.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->pAttacker.mPrev;
    v2->pAttacker.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->pAttacker.mPrev;
  }
  v2->pAttacker.m_pPointer = v3;
  if ( v3 )
  {
    v7 = v3->m_SafePointerList.mNode.mPrev;
    v8 = &v3->m_SafePointerList.mNode;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->pAttacker.mPrev;
    v2->pAttacker.mPrev = v7;
    v2->pAttacker.mNext = v8;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->pAttacker.mPrev;
  }
  v9 = right->pAttacked.m_pPointer;
  v10 = &v2->pAttacked;
  if ( v2->pAttacked.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v2->pAttacked.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v2->pAttacked.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->pAttacked.mPrev;
  }
  v2->pAttacked.m_pPointer = v9;
  if ( v9 )
  {
    v13 = v9->m_SafePointerList.mNode.mPrev;
    v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v10->mPrev = v13;
    v2->pAttacked.mNext = &v9->m_SafePointerList.mNode;
    v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  }
  v2->fElapsedTime = v4->fElapsedTime;
  return v2;
}

// File Line: 150
// RVA: 0x66EEE0
UFG::ComponentIDDesc *__fastcall UFG::PhysicsMoverInterface::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::PhysicsMoverInterface::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::PhysicsMoverInterface::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::PhysicsMoverInterface::_TypeIDesc.mChildren = v0->mChildren;
    UFG::PhysicsMoverInterface::_DescInit = 1;
    UFG::PhysicsMoverInterface::_TypeUID = UFG::PhysicsMoverInterface::_TypeIDesc.mChildBitMask | (UFG::PhysicsMoverInterface::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::PhysicsMoverInterface::_PhysicsMoverInterfaceTypeUID = UFG::PhysicsMoverInterface::_TypeIDesc.mChildBitMask | (UFG::PhysicsMoverInterface::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::PhysicsMoverInterface::_TypeIDesc;
}

