// File Line: 17
// RVA: 0x4BC9E0
void __fastcall UFG::StatGamePropertyData::SetFormatType(UFG::StatGamePropertyData *this)
{
  const char *mFormat; // rdi
  char v3; // si

  mFormat = this->m_pLBD->mFormat;
  v3 = mFormat[(int)UFG::qStringLength(mFormat) - 1];
  if ( *(_WORD *)mFormat == 26996 && mFormat[2] == 109 )
  {
    this->mFormatType = FEDT_RACETIME;
  }
  else if ( UFG::qStringFind(mFormat, "%d") )
  {
    this->mFormatType = FEDT_COUNT;
  }
  else if ( v3 == 109 )
  {
    this->mFormatType = FEDT_DISTANCE;
  }
  else
  {
    this->mFormatType = v3 == 115;
  }
}

// File Line: 45
// RVA: 0x4A1740
void __fastcall UFG::StatGamePropertyData::FormatScore(
        UFG::StatGamePropertyData *this,
        UFG::qString *str,
        __int64 score)
{
  UFG::qString *LocalizedTime; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  if ( this->mFormatType != FEDT_FLOATTIME )
  {
    if ( this->mFormatType == FEDT_DISTANCE )
    {
      UFG::qString::Format(str, this->m_pLBD->mFormat, (float)((float)(int)score * 0.001));
      return;
    }
    if ( this->mFormatType == FEDT_COUNT )
    {
      UFG::qString::Format(str, this->m_pLBD->mFormat, score);
      return;
    }
    if ( this->mFormatType != FEDT_RACETIME )
    {
      UFG::qString::Set(str, &customCaption);
      return;
    }
  }
  LocalizedTime = UFG::UIGfxTranslator::getLocalizedTime(
                    UFG::UIScreenManager::s_instance->m_translator,
                    &result,
                    (float)(int)score,
                    eTS_MILLISECONDS);
  UFG::qString::Set(str, LocalizedTime->mData, LocalizedTime->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
}

// File Line: 68
// RVA: 0x4A16E0
UFG::qString *__fastcall UFG::StatGamePropertyData::FormatScore(
        UFG::StatGamePropertyData *this,
        UFG::qString *result,
        int score)
{
  UFG::qString::qString(result);
  UFG::StatGamePropertyData::FormatScore(this, result, score);
  return result;
}

// File Line: 75
// RVA: 0x48DD20
void __fastcall UFG::StatGamePropertyManager::StatGamePropertyManager(UFG::StatGamePropertyManager *this)
{
  UFG::OSuiteLeaderboardManager *v2; // r14
  unsigned int size; // r15d
  unsigned int v4; // esi
  __int64 v5; // rbp
  UFG::allocator::free_link *v6; // rax
  UFG::StatGamePropertyData *v7; // rbx
  __int64 v8; // rcx
  UFG::allocator::free_link *v9; // rax
  UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> *v10; // rbx
  UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> *mPrev; // rax

  this->m_lProperties.mNode.mPrev = &this->m_lProperties.mNode;
  this->m_lProperties.mNode.mNext = &this->m_lProperties.mNode;
  v2 = UFG::OSuiteLeaderboardManager::Instance();
  size = v2->mLeaderboardData.size;
  v4 = 0;
  if ( size )
  {
    v5 = 0i64;
    do
    {
      if ( v2->mLeaderboardData.p[v5].mCategory == LeaderboardCategory_StatGame )
      {
        v6 = UFG::qMalloc(0x28ui64, "StatGamePropertyManager", 0i64);
        v7 = (UFG::StatGamePropertyData *)v6;
        if ( v6 )
        {
          v8 = (__int64)&v2->mLeaderboardData.p[v4];
          v9 = v6 + 1;
          v9->mNext = v9;
          v9[1].mNext = v9;
          v7->vfptr = (UFG::StatGamePropertyDataVtbl *)&UFG::StatGamePropertyData::`vftable;
          v7->m_pLBD = (UFG::OSuiteLeaderboardData *)v8;
        }
        else
        {
          v7 = 0i64;
        }
        UFG::StatGamePropertyData::SetFormatType(v7);
        v10 = &v7->UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData>;
        mPrev = this->m_lProperties.mNode.mPrev;
        mPrev->mNext = v10;
        v10->mPrev = mPrev;
        v10->mNext = &this->m_lProperties.mNode;
        this->m_lProperties.mNode.mPrev = v10;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < size );
  }
}

// File Line: 90
// RVA: 0x4AB8B0
UFG::StatGamePropertyManager *__fastcall UFG::StatGamePropertyManager::Instance()
{
  if ( (_S18_2 & 1) == 0 )
  {
    _S18_2 |= 1u;
    UFG::StatGamePropertyManager::StatGamePropertyManager(&instance_8);
    atexit(UFG::StatGamePropertyManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_8;
}

