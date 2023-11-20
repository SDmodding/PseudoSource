// File Line: 82
// RVA: 0x594850
void __fastcall UFG::Rule::~Rule(UFG::Rule *this)
{
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *v1; // rdi
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v2; // rcx
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v3; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v4; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v5; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> **v6; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v7; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v8; // rax
  UFG::KeyValue *v9; // [rsp+48h] [rbp+10h]

  v1 = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)this;
  this->vfptr = (UFG::RuleVtbl *)&UFG::Rule::`vftable';
  v9 = &this->m_apply;
  v2 = this->m_apply.mPrev;
  v3 = v9->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v9->mPrev = (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)&v9->mPrev;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(v1 + 2);
  v4 = v1[2].mNode.mPrev;
  v5 = v1[2].mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1[2].mNode.mPrev = &v1[2].mNode;
  v1[2].mNode.mNext = &v1[2].mNode;
  v6 = &v1->mNode.mNext;
  v7 = v1->mNode.mNext;
  v8 = v1[1].mNode.mPrev;
  v7->mNext = v8;
  v8->mPrev = v7;
  *v6 = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)v6;
  v6[1] = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)v6;
}

