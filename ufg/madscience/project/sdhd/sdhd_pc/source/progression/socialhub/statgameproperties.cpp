// File Line: 17
// RVA: 0x4BC9E0
void __fastcall UFG::StatGamePropertyData::SetFormatType(UFG::StatGamePropertyData *this)
{
  UFG::StatGamePropertyData *v1; // rbx
  const char *v2; // rdi
  char v3; // si

  v1 = this;
  v2 = this->m_pLBD->mFormat;
  v3 = v2[(signed int)UFG::qStringLength(v2) - 1];
  if ( *v2 != 116 || v2[1] != 105 || v2[2] != 109 )
  {
    if ( UFG::qStringFind(v2, "%d") )
    {
      v1->mFormatType = 3;
    }
    else if ( v3 == 109 )
    {
      v1->mFormatType = 2;
    }
    else
    {
      v1->mFormatType = v3 == 115;
    }
  }
  else
  {
    v1->mFormatType = 4;
  }
}

// File Line: 45
// RVA: 0x4A1740
void __fastcall UFG::StatGamePropertyData::FormatScore(UFG::StatGamePropertyData *this, UFG::qString *str, __int64 score)
{
  UFG::qString *v3; // rbx
  UFG::qString *v4; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v3 = str;
  if ( this->mFormatType != 1 )
  {
    if ( this->mFormatType == 2 )
    {
      UFG::qString::Format(str, this->m_pLBD->mFormat, (float)((float)(signed int)score * 0.001));
      return;
    }
    if ( this->mFormatType == 3 )
    {
      UFG::qString::Format(str, this->m_pLBD->mFormat, score);
      return;
    }
    if ( this->mFormatType != 4 )
    {
      UFG::qString::Set(str, &customWorldMapCaption);
      return;
    }
  }
  v4 = UFG::UIGfxTranslator::getLocalizedTime(
         UFG::UIScreenManager::s_instance->m_translator,
         &result,
         (float)(signed int)score,
         0);
  UFG::qString::Set(v3, v4->mData, v4->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
}

// File Line: 68
// RVA: 0x4A16E0
UFG::qString *__fastcall UFG::StatGamePropertyData::FormatScore(UFG::StatGamePropertyData *this, UFG::qString *result, int score)
{
  int v3; // edi
  UFG::qString *v4; // rsi
  UFG::StatGamePropertyData *v5; // rbx

  v3 = score;
  v4 = result;
  v5 = this;
  UFG::qString::qString(result);
  UFG::StatGamePropertyData::FormatScore(v5, v4, v3);
  return v4;
}

// File Line: 75
// RVA: 0x48DD20
void __fastcall UFG::StatGamePropertyManager::StatGamePropertyManager(UFG::StatGamePropertyManager *this)
{
  UFG::StatGamePropertyManager *v1; // rdi
  UFG::OSuiteLeaderboardManager *v2; // r14
  unsigned int v3; // er15
  unsigned int v4; // esi
  __int64 v5; // rbp
  UFG::allocator::free_link *v6; // rax
  UFG::StatGamePropertyData *v7; // rbx
  signed __int64 v8; // rcx
  UFG::allocator::free_link *v9; // rax
  UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> *v10; // rbx
  UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> *v11; // rax

  v1 = this;
  this->m_lProperties.mNode.mPrev = &this->m_lProperties.mNode;
  this->m_lProperties.mNode.mNext = &this->m_lProperties.mNode;
  v2 = UFG::OSuiteLeaderboardManager::Instance();
  v3 = v2->mLeaderboardData.size;
  v4 = 0;
  if ( v3 )
  {
    v5 = 0i64;
    do
    {
      if ( v2->mLeaderboardData.p[v5].mCategory == 1 )
      {
        v6 = UFG::qMalloc(0x28ui64, "StatGamePropertyManager", 0i64);
        v7 = (UFG::StatGamePropertyData *)v6;
        if ( v6 )
        {
          v8 = (signed __int64)&v2->mLeaderboardData.p[v4];
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
        v10 = (UFG::qNode<UFG::StatGamePropertyData,UFG::StatGamePropertyData> *)&v7->mPrev;
        v11 = v1->m_lProperties.mNode.mPrev;
        v11->mNext = v10;
        v10->mPrev = v11;
        v10->mNext = &v1->m_lProperties.mNode;
        v1->m_lProperties.mNode.mPrev = v10;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v3 );
  }
}

// File Line: 90
// RVA: 0x4AB8B0
UFG::StatGamePropertyManager *__fastcall UFG::StatGamePropertyManager::Instance()
{
  if ( !(_S18_2 & 1) )
  {
    _S18_2 |= 1u;
    UFG::StatGamePropertyManager::StatGamePropertyManager(&instance_8);
    atexit(UFG::StatGamePropertyManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance_8;
}

