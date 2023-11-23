// File Line: 42
// RVA: 0x333350
void __fastcall UFG::qSafePointerBase<NISInstance>::~qSafePointerBase<NISInstance>(
        UFG::qSafePointerBase<UFG::SimObject> *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  if ( this->m_pPointer )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
  }
  this->m_pPointer = 0i64;
  v4 = this->mPrev;
  v5 = this->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 81
// RVA: 0x32A350
void __fastcall UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>(
        UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *this)
{
  this->mPrev = this;
  this->mNext = this;
  this->m_pPointer = 0i64;
}

// File Line: 85
// RVA: 0x33BB10
UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *__fastcall UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint>::operator=(
        UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *this,
        UFG::InterestPoint *pointer)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v4; // rax

  if ( this->m_pPointer )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
  }
  this->m_pPointer = pointer;
  if ( pointer )
  {
    v4 = pointer->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev;
    v4->mNext = this;
    this->mPrev = v4;
    this->mNext = &pointer->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode;
    pointer->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev = this;
  }
  return this;
}

// File Line: 86
// RVA: 0x33BAC0
UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *__fastcall UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint>::operator=(
        UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *this,
        UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *safe_pointer)
{
  UFG::InterestPoint *m_pPointer; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *p_mNode; // rcx

  m_pPointer = safe_pointer->m_pPointer;
  if ( this->m_pPointer )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
  }
  this->m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v6 = m_pPointer->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev;
    p_mNode = &m_pPointer->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode;
    v6->mNext = this;
    this->mPrev = v6;
    this->mNext = p_mNode;
    p_mNode->mPrev = this;
  }
  return this;
}

// File Line: 306
// RVA: 0x3DFA50
void __fastcall UFG::qSafePointerNode<NISInstance>::qSafePointerNode<NISInstance>(
        UFG::qSafePointerNode<NISInstance> *this)
{
  UFG::qList<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // r8
  UFG::qSafePointerNode<NISInstance> *mNext; // rax
  UFG::qSafePointerNode<NISInstance>Vtbl *vfptr; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mPrev; // rcx

  this->vfptr = (UFG::qSafePointerNode<NISInstance>Vtbl *)&UFG::qSafePointerNode<NISInstance>::`vftable;
  p_m_SafePointerList = &this->m_SafePointerList;
  this->m_SafePointerList.mNode.mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  mNext = (UFG::qSafePointerNode<NISInstance> *)this->m_SafePointerList.mNode.mNext;
  if ( mNext != (UFG::qSafePointerNode<NISInstance> *)&this->m_SafePointerList )
  {
    do
    {
      vfptr = mNext->vfptr;
      mPrev = mNext->m_SafePointerList.mNode.mPrev;
      vfptr[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<NISInstance> *, unsigned int))mPrev;
      mPrev->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)vfptr;
      mNext->vfptr = (UFG::qSafePointerNode<NISInstance>Vtbl *)mNext;
      mNext->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)mNext;
      mNext = (UFG::qSafePointerNode<NISInstance> *)p_m_SafePointerList->mNode.mNext;
    }
    while ( mNext != (UFG::qSafePointerNode<NISInstance> *)p_m_SafePointerList );
  }
}

// File Line: 307
// RVA: 0x3334D0
void __fastcall UFG::qSafePointerNode<UFG::GetInPedFormationNode>::~qSafePointerNode<UFG::GetInPedFormationNode>(
        UFG::qSafePointerNode<UFG::GetInPedFormationNode> *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *mNext; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::GetInPedFormationNode>Vtbl *)&UFG::qSafePointerNode<UFG::GetInPedFormationNode>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  mPrev = this->m_SafePointerList.mNode.mPrev;
  mNext = this->m_SafePointerList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_SafePointerList.mNode.mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
}

