// File Line: 42
// RVA: 0x333350
void __fastcall UFG::qSafePointerBase<NISInstance>::~qSafePointerBase<NISInstance>(UFG::qSafePointerBase<UFG::SimObject> *this)
{
  UFG::qSafePointerBase<UFG::SimObject> *v1; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = this;
  if ( this->m_pPointer )
  {
    v2 = this->mPrev;
    v3 = this->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    this->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mPrev;
  }
  this->m_pPointer = 0i64;
  v4 = this->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
}

// File Line: 81
// RVA: 0x32A350
void __fastcall UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>(UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *this)
{
  this->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mPrev;
  this->m_pPointer = 0i64;
}

// File Line: 85
// RVA: 0x33BB10
UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *__fastcall UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint>::operator=(UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *this, UFG::InterestPoint *pointer)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v4; // rax

  if ( this->m_pPointer )
  {
    v2 = this->mPrev;
    v3 = this->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    this->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mPrev;
  }
  this->m_pPointer = pointer;
  if ( pointer )
  {
    v4 = pointer->m_SafePointerList.mNode.mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mPrev;
    this->mPrev = v4;
    this->mNext = &pointer->m_SafePointerList.mNode;
    pointer->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mPrev;
  }
  return this;
}

// File Line: 86
// RVA: 0x33BAC0
UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *__fastcall UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint>::operator=(UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *this, UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *safe_pointer)
{
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *v2; // r8
  UFG::InterestPoint *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v7; // rcx

  v2 = this;
  v3 = safe_pointer->m_pPointer;
  if ( v2->m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = v2->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = v3;
  if ( v3 )
  {
    v6 = v3->m_SafePointerList.mNode.mPrev;
    v7 = &v3->m_SafePointerList.mNode;
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mPrev = v6;
    v2->mNext = v7;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  return v2;
}

// File Line: 306
// RVA: 0x3DFA50
void __fastcall UFG::qSafePointerNode<NISInstance>::qSafePointerNode<NISInstance>(UFG::qSafePointerNode<NISInstance> *this)
{
  UFG::qList<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList,1,0> *v1; // r8
  UFG::qSafePointerNode<NISInstance> *v2; // rax
  UFG::qSafePointerNode<NISInstance>Vtbl *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v4; // rcx

  this->vfptr = (UFG::qSafePointerNode<NISInstance>Vtbl *)&UFG::qSafePointerNode<NISInstance>::`vftable';
  v1 = &this->m_SafePointerList;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
  v2 = (UFG::qSafePointerNode<NISInstance> *)this->m_SafePointerList.mNode.mNext;
  if ( v2 != (UFG::qSafePointerNode<NISInstance> *)&this->m_SafePointerList )
  {
    do
    {
      v3 = v2->vfptr;
      v4 = v2->m_SafePointerList.mNode.mPrev;
      v3[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<NISInstance> *, unsigned int))v4;
      v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)v3;
      v2->vfptr = (UFG::qSafePointerNode<NISInstance>Vtbl *)v2;
      v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)v2;
      v2 = (UFG::qSafePointerNode<NISInstance> *)v1->mNode.mNext;
    }
    while ( v2 != (UFG::qSafePointerNode<NISInstance> *)v1 );
  }
}

// File Line: 307
// RVA: 0x3334D0
void __fastcall UFG::qSafePointerNode<UFG::GetInPedFormationNode>::~qSafePointerNode<UFG::GetInPedFormationNode>(UFG::qSafePointerNode<UFG::GetInPedFormationNode> *this)
{
  UFG::qSafePointerNode<UFG::GetInPedFormationNode> *v1; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList,1,0> *v4; // [rsp+40h] [rbp+8h]

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::GetInPedFormationNode>Vtbl *)&UFG::qSafePointerNode<UFG::GetInPedFormationNode>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  v4 = &v1->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v1->m_SafePointerList);
  v2 = v1->m_SafePointerList.mNode.mPrev;
  v3 = v1->m_SafePointerList.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
}

