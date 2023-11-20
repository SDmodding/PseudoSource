// File Line: 17
// RVA: 0x4A3240
signed __int64 __fastcall UFG::StatAwardPropertyData::GetFormat(const char *formatString)
{
  unsigned int v1; // ebx
  const char *v2; // rdi
  signed __int64 result; // rax

  v1 = -1;
  v2 = formatString;
  result = UFG::qStringCompare(formatString, "Rank", -1);
  if ( (_DWORD)result )
  {
    if ( (unsigned int)UFG::qStringCompare(v2, "Int32", -1) )
    {
      if ( (unsigned int)UFG::qStringCompare(v2, "Percentage", -1) )
      {
        if ( (unsigned int)UFG::qStringCompare(v2, "RaceTime", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(v2, "Money", -1) )
            v1 = 4;
          result = v1;
        }
        else
        {
          result = 3i64;
        }
      }
      else
      {
        result = 2i64;
      }
    }
    else
    {
      result = 1i64;
    }
  }
  return result;
}

// File Line: 28
// RVA: 0x4A1530
void __fastcall UFG::StatAwardPropertyData::FormatScore(UFG::StatAwardPropertyData *this, UFG::qString *scoreStr, int score)
{
  int v3; // ebx
  UFG::qString *v4; // rdi
  UFG::StatAwardPropertyData::Format v5; // eax
  UFG::qString *v6; // rax
  UFG::qString *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  UFG::qString result; // [rsp+38h] [rbp-60h]
  UFG::qString v11; // [rsp+60h] [rbp-38h]

  v3 = score;
  v4 = scoreStr;
  v5 = this->m_eFormat;
  if ( v5 )
  {
    switch ( v5 )
    {
      case 1u:
        v7 = UFG::qString::FormatEx(&result, "%d");
        UFG::qString::Set(v4, v7->mData, v7->mLength, 0i64, 0);
        break;
      case 2u:
        UFG::qString::qString(&result, "%.2f %%", (float)((float)score * 0.001));
        UFG::qString::Set(v4, result.mData, result.mLength, 0i64, 0);
        break;
      case 3u:
        v8 = UFG::UIGfxTranslator::getLocalizedTime(
               UFG::UIScreenManager::s_instance->m_translator,
               &result,
               (float)score,
               eTS_SECONDS);
        UFG::qString::Set(v4, v8->mData, v8->mLength, 0i64, 0);
        break;
      case 4u:
        UFG::qString::qString(&result);
        UFG::UI::FormatMoneyStr(v3, &result);
        v9 = UFG::qString::FormatEx(&v11, "HK $%s", result.mData);
        UFG::qString::Set(v4, v9->mData, v9->mLength, 0i64, 0);
        UFG::qString::~qString(&v11);
        break;
      default:
        return;
    }
  }
  else
  {
    v6 = UFG::qString::FormatEx(&result, "%d");
    UFG::qString::Set(v4, v6->mData, v6->mLength, 0i64, 0);
  }
  UFG::qString::~qString(&result);
}

// File Line: 64
// RVA: 0x4A14D0
UFG::qString *__fastcall UFG::StatAwardPropertyData::FormatScore(UFG::StatAwardPropertyData *this, UFG::qString *result, int score)
{
  int v3; // edi
  UFG::qString *v4; // rsi
  UFG::StatAwardPropertyData *v5; // rbx

  v3 = score;
  v4 = result;
  v5 = this;
  UFG::qString::qString(result);
  UFG::StatAwardPropertyData::FormatScore(v5, v4, v3);
  return v4;
}

// File Line: 71
// RVA: 0x48DB10
void __fastcall UFG::StatAwardPropertyManager::StatAwardPropertyManager(UFG::StatAwardPropertyManager *this)
{
  UFG::StatAwardPropertyManager *v1; // rbx
  UFG::OSuiteLeaderboardManager *v2; // rbp
  unsigned int v3; // edi
  __int64 v4; // rsi
  UFG::OSuiteLeaderboardData *v5; // rax
  UFG::StatAwardPropertyData::Format v6; // er13
  UFG::OSuiteLeaderboardData *v7; // rcx
  int v8; // er14
  int v9; // er15
  int v10; // er12
  UFG::allocator::free_link *v11; // rax
  signed __int64 v12; // rdx
  UFG::allocator::free_link *v13; // rcx
  UFG::allocator::free_link *v14; // rcx
  UFG::qNode<UFG::StatAwardPropertyData,UFG::StatAwardPropertyData> *v15; // rax
  unsigned int v16; // [rsp+78h] [rbp+10h]

  v1 = this;
  this->m_lProperties.mNode.mPrev = &this->m_lProperties.mNode;
  this->m_lProperties.mNode.mNext = &this->m_lProperties.mNode;
  v2 = UFG::OSuiteLeaderboardManager::Instance();
  v16 = v2->mLeaderboardData.size;
  v3 = 0;
  if ( v16 )
  {
    v4 = 0i64;
    do
    {
      v5 = v2->mLeaderboardData.p;
      if ( v5[v4].mCategory == LeaderboardCategory_StatAward )
      {
        v6 = UFG::StatAwardPropertyData::GetFormat(v5[v4].mFormat);
        v7 = v2->mLeaderboardData.p;
        v8 = v7[v4].mGold;
        v9 = v7[v4].mSilver;
        v10 = v7[v4].mBronze;
        if ( v6 - 2 <= 1 )
        {
          v8 *= (signed int)1000.0;
          v9 *= (signed int)1000.0;
          v10 *= (signed int)1000.0;
        }
        v11 = UFG::qMalloc(0x30ui64, "StatAwardPropertyManager", 0i64);
        if ( v11 )
        {
          v12 = (signed __int64)&v2->mLeaderboardData.p[v3];
          v13 = v11 + 1;
          v13->mNext = v13;
          v13[1].mNext = v13;
          v11->mNext = (UFG::allocator::free_link *)&UFG::StatAwardPropertyData::`vftable';
          v11[3].mNext = (UFG::allocator::free_link *)v12;
          LODWORD(v11[4].mNext) = v6;
          HIDWORD(v11[4].mNext) = v8;
          LODWORD(v11[5].mNext) = v9;
          HIDWORD(v11[5].mNext) = v10;
        }
        v14 = v11 + 1;
        v15 = v1->m_lProperties.mNode.mPrev;
        v15->mNext = (UFG::qNode<UFG::StatAwardPropertyData,UFG::StatAwardPropertyData> *)v14;
        v14->mNext = (UFG::allocator::free_link *)v15;
        v14[1].mNext = (UFG::allocator::free_link *)v1;
        v1->m_lProperties.mNode.mPrev = (UFG::qNode<UFG::StatAwardPropertyData,UFG::StatAwardPropertyData> *)v14;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < v16 );
  }
}

// File Line: 101
// RVA: 0x4AB860
UFG::StatAwardPropertyManager *__fastcall UFG::StatAwardPropertyManager::Instance()
{
  if ( !(_S17_3 & 1) )
  {
    _S17_3 |= 1u;
    UFG::StatAwardPropertyManager::StatAwardPropertyManager(&instance_7);
    atexit(UFG::StatAwardPropertyManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_7;
}

// File Line: 107
// RVA: 0x4A5FB0
UFG::StatGamePropertyData *__fastcall UFG::StatGamePropertyManager::GetPropertyData(UFG::StatGamePropertyManager *this, UFG::OSuiteLeaderboardData *pLBD)
{
  UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> *v2; // rax
  UFG::StatGamePropertyData *v3; // rcx
  UFG::StatGamePropertyData *result; // rax

  v2 = this->m_lProperties.mNode.mNext;
  v3 = (UFG::StatGamePropertyData *)&this[-1].m_lProperties.mNode.mNext;
  result = (UFG::StatGamePropertyData *)&v2[-1].mNext;
  if ( result == v3 )
    return 0i64;
  while ( result->m_pLBD != pLBD )
  {
    result = (UFG::StatGamePropertyData *)&result->mNext[-1].mNext;
    if ( result == v3 )
      return 0i64;
  }
  return result;
}

