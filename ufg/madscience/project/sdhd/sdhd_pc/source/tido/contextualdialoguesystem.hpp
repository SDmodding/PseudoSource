// File Line: 82
// RVA: 0x594850
void __fastcall UFG::Rule::~Rule(UFG::Rule *this)
{
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *mPrev; // rcx
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *mNext; // rax
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v4; // rcx
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v5; // rax
  UFG::qNode<UFG::Rule,UFG::Rule> *v6; // rcx
  UFG::qNode<UFG::Rule,UFG::Rule> *v7; // rax
  UFG::KeyValue *p_m_apply; // [rsp+48h] [rbp+10h]

  this->vfptr = (UFG::RuleVtbl *)&UFG::Rule::`vftable;
  p_m_apply = &this->m_apply;
  mPrev = this->m_apply.mPrev;
  mNext = p_m_apply->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_apply->mPrev = p_m_apply;
  p_m_apply->mNext = p_m_apply;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_criteria);
  v4 = this->m_criteria.mNode.mPrev;
  v5 = this->m_criteria.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->m_criteria.mNode.mPrev = &this->m_criteria.mNode;
  this->m_criteria.mNode.mNext = &this->m_criteria.mNode;
  v6 = this->mPrev;
  v7 = this->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->mPrev = &this->UFG::qNode<UFG::Rule,UFG::Rule>;
  this->mNext = &this->UFG::qNode<UFG::Rule,UFG::Rule>;
}

