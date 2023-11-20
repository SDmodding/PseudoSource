// File Line: 131
// RVA: 0x140A50
void __fastcall UFG::SoundBankGroup::SoundBankGroup(UFG::SoundBankGroup *this, unsigned int id)
{
  UFG::SoundBankGroup *v2; // rbx
  UFG::qList<UFG::SoundBank,UFG::SoundBankGroupBankList,0,0> *v3; // [rsp+50h] [rbp+18h]

  v2 = this;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = id;
  this->nameId = id;
  this->poolId = -1;
  *(_QWORD *)&this->poolSize = 0i64;
  UFG::qString::qString(&this->nameString);
  v3 = &v2->soundBanks;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
}

// File Line: 161
// RVA: 0x1415D0
void __fastcall UFG::SoundBank::~SoundBank(UFG::SoundBank *this)
{
  UFG::SoundBank *v1; // rbx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList> *v2; // rdx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList> *v3; // rcx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList> *v4; // rax
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *v5; // rdx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *v6; // rcx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *v7; // rax

  v1 = this;
  this->vfptr = (UFG::SoundBankVtbl *)&UFG::SoundBank::`vftable';
  this->m_group = 0i64;
  _((AMD_HD3D *)this->m_name.mUID);
  v2 = (UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = (UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

