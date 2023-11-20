// File Line: 83
// RVA: 0x5C3A40
void __fastcall UFG::UIHKScreenSocialHub::ChallengeDialogPopupEntry::ChallengeDialogPopupEntry(UFG::UIHKScreenSocialHub::ChallengeDialogPopupEntry *this, UFG::qString *id, UFG::qString *name, int lid, int score)
{
  int v5; // edi
  UFG::qString *v6; // rbx
  UFG::UIHKScreenSocialHub::ChallengeDialogPopupEntry *v7; // rsi
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *v8; // rax

  v5 = lid;
  v6 = id;
  v7 = this;
  v8 = (UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *)&this->mPrev;
  v8->mPrev = v8;
  v8->mNext = v8;
  this->vfptr = (UFG::DialogPopupEntryVtbl *)&UFG::DialogPopupEntry::`vftable';
  UFG::qString::qString(&this->mName, name);
  v7->mChecked = 0;
  v7->mType = 0;
  v7->vfptr = (UFG::DialogPopupEntryVtbl *)&UFG::UIHKScreenSocialHub::ChallengeDialogPopupEntry::`vftable';
  UFG::qString::qString(&v7->mOnlineId, v6);
  v7->mLeaderboardId = v5;
  v7->mScore = score;
  v7->mType = 1;
}

// File Line: 186
// RVA: 0x5C3BF0
void __fastcall UFG::UIHKScreenSocialHub::LeaderboardEntry::LeaderboardEntry(UFG::UIHKScreenSocialHub::LeaderboardEntry *this, UFG::qString *id, UFG::qString *name, int score)
{
  int v4; // esi
  UFG::qString *v5; // rbx
  UFG::UIHKScreenSocialHub::LeaderboardEntry *v6; // rdi

  v4 = score;
  v5 = name;
  v6 = this;
  this->mPrev = (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::UIHKScreenSocialHub::LeaderboardEntry,UFG::UIHKScreenSocialHub::LeaderboardEntry> *)&this->mPrev;
  UFG::qString::qString(&this->m_sId, id);
  UFG::qString::qString(&v6->m_sName, v5);
  v6->m_iScore = v4;
}

// File Line: 191
// RVA: 0x5D5C20
bool __fastcall UFG::UIHKScreenSocialHub::CompareASC(UFG::UIHKScreenSocialHub::LeaderboardEntry *a, UFG::UIHKScreenSocialHub::LeaderboardEntry *b)
{
  return a->m_iScore <= b->m_iScore;
}

// File Line: 192
// RVA: 0x5D5C30
bool __fastcall UFG::UIHKScreenSocialHub::CompareDESC(UFG::UIHKScreenSocialHub::LeaderboardEntry *a, UFG::UIHKScreenSocialHub::LeaderboardEntry *b)
{
  return a->m_iScore >= b->m_iScore;
}

