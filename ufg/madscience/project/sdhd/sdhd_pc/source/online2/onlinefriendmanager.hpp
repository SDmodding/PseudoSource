// File Line: 18
// RVA: 0xA40660
void __fastcall UFG::OnlineFriend::OnlineFriend(UFG::OnlineFriend *this, UFG::OnlineFriend *src)
{
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v2; // rax
  UFG::OnlineId *v3; // [rsp+48h] [rbp+10h]

  v2 = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable';
  v3 = &this->m_cOnlineId;
  v3->mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v3->mPrev;
  this->m_cOnlineId.m_SteamId.m_steamid.m_comp = 0;
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
  UFG::OnlineFriend *v1; // rbx
  UFG::OnlineId *v2; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v3; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v4; // rax
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v5; // rdx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v6; // rcx
  UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *v7; // rax

  v1 = this;
  this->vfptr = (UFG::OnlineFriendVtbl *)&UFG::OnlineFriend::`vftable';
  UFG::qString::~qString(&this->m_sOnlineName);
  v2 = &v1->m_cOnlineId;
  v3 = v1->m_cOnlineId.mPrev;
  v4 = v1->m_cOnlineId.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v2->mPrev;
  v5 = (UFG::qNode<UFG::OnlineFriend,UFG::OnlineFriend> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

