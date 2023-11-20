// File Line: 39
// RVA: 0x428940
void __fastcall UFG::SocialLogData::SocialLogData(UFG::SocialLogData *this)
{
  UFG::SocialLogData *v1; // rbx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v2; // rax
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *v3; // rax
  UFG::OnlineId *v4; // [rsp+48h] [rbp+10h]
  UFG::OnlineId *v5; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v3 = (UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *)&this->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::OSuiteMessage::`vftable';
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData::`vftable';
  this->m_iVersion = 0;
  this->m_iCommId = -1;
  this->m_iTimeStamp = 0i64;
  this->m_iLeaderboardId = -1;
  this->m_iScore = 0;
  v4 = &this->m_cSrcOnlineId;
  v4->mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v4->mPrev;
  this->m_cSrcOnlineId.m_SteamId.m_steamid.m_comp = 0;
  *((_DWORD *)&this->m_cSrcOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_cSrcOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_cSrcOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
  UFG::qString::qString(&this->m_sSrcOnlineName);
  v5 = &v1->m_cDstOnlineId;
  v5->mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v5->mPrev;
  v1->m_cDstOnlineId.m_SteamId.m_steamid.m_comp = 0;
  *((_DWORD *)&v1->m_cDstOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(v1->m_cDstOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&v1->m_cDstOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
  UFG::qString::qString(&v1->m_sDstOnlineName);
}

// File Line: 40
// RVA: 0x429430
void __fastcall UFG::SocialLogData::~SocialLogData(UFG::SocialLogData *this)
{
  UFG::SocialLogData *v1; // rbx
  UFG::OnlineId *v2; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v3; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v4; // rax
  UFG::OnlineId *v5; // rdx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v6; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v7; // rax
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *v8; // rdx
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *v9; // rcx
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *v10; // rax
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v11; // rdx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v12; // rcx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v13; // rax

  v1 = this;
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData::`vftable';
  UFG::qString::~qString(&this->m_sDstOnlineName);
  v2 = &v1->m_cDstOnlineId;
  v3 = v1->m_cDstOnlineId.mPrev;
  v4 = v1->m_cDstOnlineId.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v2->mPrev;
  UFG::qString::~qString(&v1->m_sSrcOnlineName);
  v5 = &v1->m_cSrcOnlineId;
  v6 = v1->m_cSrcOnlineId.mPrev;
  v7 = v1->m_cSrcOnlineId.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::OnlineId,UFG::OnlineId> *)&v5->mPrev;
  v1->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::OSuiteMessage::`vftable';
  v8 = (UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *)&v1->mPrev;
  v9 = v1->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v8->mPrev = v8;
  v8->mNext = v8;
  v11 = (UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *)&v1->mPrev;
  v12 = v1->mPrev;
  v13 = v1->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v11->mPrev = v11;
  v11->mNext = v11;
}

// File Line: 44
// RVA: 0x430EF0
__int64 __fastcall UFG::SocialLogData::Size(UFG::SocialLogData *this)
{
  return ((__int64 (*)(void))this->vfptr[1].__vecDelDtor)() + 8;
}

