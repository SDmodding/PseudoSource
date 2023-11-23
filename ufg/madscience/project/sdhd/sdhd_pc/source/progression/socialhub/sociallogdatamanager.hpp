// File Line: 39
// RVA: 0x428940
void __fastcall UFG::SocialLogData::SocialLogData(UFG::SocialLogData *this)
{
  this->UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>::mPrev = &this->UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>;
  this->UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>::mNext = &this->UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>;
  this->UFG::OSuiteMessage::UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage>::mPrev = &this->UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage>;
  this->UFG::OSuiteMessage::UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage>::mNext = &this->UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage>;
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::OSuiteMessage::`vftable;
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData::`vftable;
  this->m_iVersion = 0;
  this->m_iCommId = CommId_Invalid;
  this->m_iTimeStamp = 0i64;
  this->m_iLeaderboardId = -1;
  this->m_iScore = 0;
  this->m_cSrcOnlineId.mPrev = &this->m_cSrcOnlineId;
  this->m_cSrcOnlineId.mNext = &this->m_cSrcOnlineId;
  *(_DWORD *)&this->m_cSrcOnlineId.m_SteamId.m_steamid.m_comp = 0;
  *((_DWORD *)&this->m_cSrcOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_cSrcOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_cSrcOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
  UFG::qString::qString(&this->m_sSrcOnlineName);
  this->m_cDstOnlineId.mPrev = &this->m_cDstOnlineId;
  this->m_cDstOnlineId.mNext = &this->m_cDstOnlineId;
  *(_DWORD *)&this->m_cDstOnlineId.m_SteamId.m_steamid.m_comp = 0;
  *((_DWORD *)&this->m_cDstOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_cDstOnlineId.m_SteamId.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_cDstOnlineId.m_SteamId.m_steamid.m_comp + 1) &= 0xFFF00000;
  UFG::qString::qString(&this->m_sDstOnlineName);
}

// File Line: 40
// RVA: 0x429430
void __fastcall UFG::SocialLogData::~SocialLogData(UFG::SocialLogData *this)
{
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mPrev; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *mNext; // rax
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v4; // rcx
  UFG::qNode<UFG::OnlineId,UFG::OnlineId> *v5; // rax
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *v6; // rcx
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *v7; // rax
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v8; // rcx
  UFG::qNode<UFG::SocialLogData,UFG::SocialLogData> *v9; // rax

  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::SocialLogData::`vftable;
  UFG::qString::~qString(&this->m_sDstOnlineName);
  mPrev = this->m_cDstOnlineId.mPrev;
  mNext = this->m_cDstOnlineId.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_cDstOnlineId.mPrev = &this->m_cDstOnlineId;
  this->m_cDstOnlineId.mNext = &this->m_cDstOnlineId;
  UFG::qString::~qString(&this->m_sSrcOnlineName);
  v4 = this->m_cSrcOnlineId.mPrev;
  v5 = this->m_cSrcOnlineId.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->m_cSrcOnlineId.mPrev = &this->m_cSrcOnlineId;
  this->m_cSrcOnlineId.mNext = &this->m_cSrcOnlineId;
  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::OSuiteMessage::`vftable;
  v6 = this->UFG::OSuiteMessage::UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage>::mPrev;
  v7 = this->UFG::OSuiteMessage::UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage>::mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->UFG::OSuiteMessage::UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage>::mPrev = &this->UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage>;
  this->UFG::OSuiteMessage::UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage>::mNext = &this->UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage>;
  v8 = this->UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>::mPrev;
  v9 = this->UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>::mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>::mPrev = &this->UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>;
  this->UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>::mNext = &this->UFG::qNode<UFG::SocialLogData,UFG::SocialLogData>;
}

// File Line: 44
// RVA: 0x430EF0
__int64 __fastcall UFG::SocialLogData::Size(UFG::SocialLogData *this)
{
  return ((__int64 (__fastcall *)(UFG::SocialLogData *))this->vfptr[1].__vecDelDtor)(this) + 8;
}

