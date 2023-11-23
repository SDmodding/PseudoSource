// File Line: 18
// RVA: 0xA40660
void __fastcall UFG::OnlineFriend::OnlineFriend(UFG::OnlineFriend *this, UFG::OnlineFriend *src)
{
  this->mPrev = &this->UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
  this->mNext = &this->UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
  this->vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
  this->m_cOnlineId.mPrev = &this->m_cOnlineId;
  this->m_cOnlineId.mNext = &this->m_cOnlineId;
  *(_DWORD *)&this->m_cOnlineId.m_SteamId.m_steamid.m_comp = 0;
  *((_DWORD *)&this->m_cOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_cOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
  this->m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits = src->m_cOnlineId.m_SteamId.m_steamid.m_unAll64Bits;
  UFG::qString::qString(&this->m_sOnlineName, &src->m_sOnlineName);
}

// File Line: 20
// RVA: 0x4292F0
void __fastcall UFG::OnlineFriend::~OnlineFriend(UFG::OnlineFriend *this)
{
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v4; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v5; // rax

  this->vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable;
  UFG::qString::~qString(&this->m_sOnlineName);
  mPrev = this->m_cOnlineId.mPrev;
  mNext = this->m_cOnlineId.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_cOnlineId.mPrev = &this->m_cOnlineId;
  this->m_cOnlineId.mNext = &this->m_cOnlineId;
  v4 = this->mPrev;
  v5 = this->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mPrev = &this->UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
  this->mNext = &this->UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend>;
}

