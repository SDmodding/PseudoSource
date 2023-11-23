// File Line: 17
// RVA: 0x4A3240
signed __int64 __fastcall UFG::StatAwardPropertyData::GetFormat(const char *formatString)
{
  unsigned int v1; // ebx
  signed __int64 result; // rax

  v1 = -1;
  result = UFG::qStringCompare(formatString, "Rank", -1);
  if ( (_DWORD)result )
  {
    if ( (unsigned int)UFG::qStringCompare(formatString, "Int32", -1) )
    {
      if ( (unsigned int)UFG::qStringCompare(formatString, "Percentage", -1) )
      {
        if ( (unsigned int)UFG::qStringCompare(formatString, "RaceTime", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(formatString, "Money", -1) )
            return 4;
          return v1;
        }
        else
        {
          return 3i64;
        }
      }
      else
      {
        return 2i64;
      }
    }
    else
    {
      return 1i64;
    }
  }
  return result;
}

// File Line: 28
// RVA: 0x4A1530
void __fastcall UFG::StatAwardPropertyData::FormatScore(
        UFG::StatAwardPropertyData *this,
        UFG::qString *scoreStr,
        __int64 score)
{
  int v3; // ebx
  UFG::StatAwardPropertyData::Format m_eFormat; // eax
  UFG::qString *v6; // rax
  UFG::qString *LocalizedTime; // rax
  UFG::qString *v8; // rax
  UFG::qString result; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString v10; // [rsp+60h] [rbp-38h] BYREF

  v3 = score;
  m_eFormat = this->m_eFormat;
  if ( (unsigned int)m_eFormat > Format_Int32 )
  {
    switch ( m_eFormat )
    {
      case Format_Percentage:
        UFG::qString::qString(&result, "%.2f %%", (float)((float)(int)score * 0.001));
        UFG::qString::Set(scoreStr, result.mData, result.mLength, 0i64, 0);
        break;
      case Format_RaceTime:
        LocalizedTime = UFG::UIGfxTranslator::getLocalizedTime(
                          UFG::UIScreenManager::s_instance->m_translator,
                          &result,
                          (float)(int)score,
                          eTS_SECONDS);
        UFG::qString::Set(scoreStr, LocalizedTime->mData, LocalizedTime->mLength, 0i64, 0);
        break;
      case Format_Money:
        UFG::qString::qString(&result);
        UFG::UI::FormatMoneyStr(v3, &result);
        v8 = UFG::qString::FormatEx(&v10, "HK $%s", result.mData);
        UFG::qString::Set(scoreStr, v8->mData, v8->mLength, 0i64, 0);
        UFG::qString::~qString(&v10);
        break;
      default:
        return;
    }
  }
  else
  {
    v6 = UFG::qString::FormatEx(&result, "%d", score);
    UFG::qString::Set(scoreStr, v6->mData, v6->mLength, 0i64, 0);
  }
  UFG::qString::~qString(&result);
}

// File Line: 64
// RVA: 0x4A14D0
UFG::qString *__fastcall UFG::StatAwardPropertyData::FormatScore(
        UFG::StatAwardPropertyData *this,
        UFG::qString *result,
        int score)
{
  UFG::qString::qString(result);
  UFG::StatAwardPropertyData::FormatScore(this, result, score);
  return result;
}

// File Line: 71
// RVA: 0x48DB10
void __fastcall UFG::StatAwardPropertyManager::StatAwardPropertyManager(UFG::StatAwardPropertyManager *this)
{
  UFG::OSuiteLeaderboardManager *v2; // rbp
  unsigned int v3; // edi
  __int64 v4; // rsi
  UFG::OSuiteLeaderboardData *p; // rax
  UFG::StatAwardPropertyData::Format Format; // r13d
  UFG::OSuiteLeaderboardData *v7; // rcx
  int mGold; // r14d
  int mSilver; // r15d
  int mBronze; // r12d
  UFG::allocator::free_link *v11; // rax
  __int64 v12; // rdx
  UFG::qNode<UFG::StatAwardPropertyData,UFG::StatAwardPropertyData> *v13; // rcx
  UFG::qNode<UFG::StatAwardPropertyData,UFG::StatAwardPropertyData> *mPrev; // rax
  unsigned int size; // [rsp+78h] [rbp+10h]

  this->m_lProperties.mNode.mPrev = &this->m_lProperties.mNode;
  this->m_lProperties.mNode.mNext = &this->m_lProperties.mNode;
  v2 = UFG::OSuiteLeaderboardManager::Instance();
  size = v2->mLeaderboardData.size;
  v3 = 0;
  if ( size )
  {
    v4 = 0i64;
    do
    {
      p = v2->mLeaderboardData.p;
      if ( p[v4].mCategory == LeaderboardCategory_StatAward )
      {
        Format = UFG::StatAwardPropertyData::GetFormat(p[v4].mFormat);
        v7 = v2->mLeaderboardData.p;
        mGold = v7[v4].mGold;
        mSilver = v7[v4].mSilver;
        mBronze = v7[v4].mBronze;
        if ( (unsigned int)(Format - 2) <= 1 )
        {
          mGold *= (int)1000.0;
          mSilver *= (int)1000.0;
          mBronze *= (int)1000.0;
        }
        v11 = UFG::qMalloc(0x30ui64, "StatAwardPropertyManager", 0i64);
        if ( v11 )
        {
          v12 = (__int64)&v2->mLeaderboardData.p[v3];
          v11[1].mNext = v11 + 1;
          v11[2].mNext = v11 + 1;
          v11->mNext = (UFG::allocator::free_link *)&UFG::StatAwardPropertyData::`vftable;
          v11[3].mNext = (UFG::allocator::free_link *)v12;
          LODWORD(v11[4].mNext) = Format;
          HIDWORD(v11[4].mNext) = mGold;
          LODWORD(v11[5].mNext) = mSilver;
          HIDWORD(v11[5].mNext) = mBronze;
        }
        v13 = (UFG::qNode<UFG::StatAwardPropertyData,UFG::StatAwardPropertyData> *)&v11[1];
        mPrev = this->m_lProperties.mNode.mPrev;
        mPrev->mNext = v13;
        v13->mPrev = mPrev;
        v13->mNext = &this->m_lProperties.mNode;
        this->m_lProperties.mNode.mPrev = v13;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < size );
  }
}

// File Line: 101
// RVA: 0x4AB860
UFG::StatAwardPropertyManager *__fastcall UFG::StatAwardPropertyManager::Instance()
{
  if ( (_S17_3 & 1) == 0 )
  {
    _S17_3 |= 1u;
    UFG::StatAwardPropertyManager::StatAwardPropertyManager(&instance_7);
    atexit(UFG::StatAwardPropertyManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_7;
}

// File Line: 107
// RVA: 0x4A5FB0
UFG::StatGamePropertyData *__fastcall UFG::StatGamePropertyManager::GetPropertyData(
        UFG::StatGamePropertyManager *this,
        UFG::OSuiteLeaderboardData *pLBD)
{
  UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> *mNext; // rax
  UFG::StatGamePropertyData *p_mNext; // rcx
  UFG::StatGamePropertyData *result; // rax

  mNext = this->m_lProperties.mNode.mNext;
  p_mNext = (UFG::StatGamePropertyData *)&this[-1].m_lProperties.mNode.mNext;
  result = (UFG::StatGamePropertyData *)&mNext[-1].mNext;
  if ( result == p_mNext )
    return 0i64;
  while ( result->m_pLBD != pLBD )
  {
    result = (UFG::StatGamePropertyData *)&result->mNext[-1].mNext;
    if ( result == p_mNext )
      return 0i64;
  }
  return result;
}

