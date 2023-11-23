// File Line: 83
// RVA: 0x5C3A40
void __fastcall UFG::UIHKScreenSocialHub::ChallengeDialogPopupEntry::ChallengeDialogPopupEntry(
        UFG::UIHKScreenSocialHub::ChallengeDialogPopupEntry *this,
        UFG::qString *id,
        UFG::qString *name,
        int lid,
        int score)
{
  this->mPrev = &this->UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry>;
  this->mNext = &this->UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry>;
  this->vfptr = (UFG::DialogPopupEntryVtbl *)&UFG::DialogPopupEntry::`vftable;
  UFG::qString::qString(&this->mName, name);
  this->mChecked = 0;
  this->mType = 0;
  this->vfptr = (UFG::DialogPopupEntryVtbl *)&UFG::UIHKScreenSocialHub::ChallengeDialogPopupEntry::`vftable;
  UFG::qString::qString(&this->mOnlineId, id);
  this->mLeaderboardId = lid;
  this->mScore = score;
  this->mType = 1;
}

// File Line: 186
// RVA: 0x5C3BF0
void __fastcall UFG::UIHKScreenSocialHub::LeaderboardEntry::LeaderboardEntry(
        UFG::UIHKScreenSocialHub::LeaderboardEntry *this,
        UFG::qString *id,
        UFG::qString *name,
        int score)
{
  this->mPrev = this;
  this->mNext = this;
  UFG::qString::qString(&this->m_sId, id);
  UFG::qString::qString(&this->m_sName, name);
  this->m_iScore = score;
}

// File Line: 191
// RVA: 0x5D5C20
bool __fastcall UFG::UIHKScreenSocialHub::CompareASC(
        UFG::UIHKScreenSocialHub::LeaderboardEntry *a,
        UFG::UIHKScreenSocialHub::LeaderboardEntry *b)
{
  return a->m_iScore <= b->m_iScore;
}

// File Line: 192
// RVA: 0x5D5C30
bool __fastcall UFG::UIHKScreenSocialHub::CompareDESC(
        UFG::UIHKScreenSocialHub::LeaderboardEntry *a,
        UFG::UIHKScreenSocialHub::LeaderboardEntry *b)
{
  return a->m_iScore >= b->m_iScore;
}

