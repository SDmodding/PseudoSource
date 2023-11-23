// File Line: 131
// RVA: 0x140A50
void __fastcall UFG::SoundBankGroup::SoundBankGroup(UFG::SoundBankGroup *this, unsigned int id)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = id;
  this->nameId = id;
  this->poolId = -1;
  *(_QWORD *)&this->poolSize = 0i64;
  UFG::qString::qString(&this->nameString);
  this->soundBanks.mNode.mPrev = &this->soundBanks.mNode;
  this->soundBanks.mNode.mNext = &this->soundBanks.mNode;
}

// File Line: 161
// RVA: 0x1415D0
void __fastcall UFG::SoundBank::~SoundBank(UFG::SoundBank *this)
{
  UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList> *mPrev; // rcx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList> *mNext; // rax
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *v4; // rcx
  UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList> *v5; // rax

  this->vfptr = (UFG::SoundBankVtbl *)&UFG::SoundBank::`vftable;
  this->m_group = 0i64;
  _((AMD_HD3D *)this->m_name.mUID);
  mPrev = this->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>::mPrev;
  mNext = this->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>::mPrev = &this->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>;
  this->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>::mNext = &this->UFG::qNode<UFG::SoundBank,UFG::SoundBankGroupBankList>;
  v4 = this->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>::mPrev;
  v5 = this->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>::mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>::mPrev = &this->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>;
  this->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>::mNext = &this->UFG::qNode<UFG::SoundBank,UFG::SoundBankManagerBankList>;
}

