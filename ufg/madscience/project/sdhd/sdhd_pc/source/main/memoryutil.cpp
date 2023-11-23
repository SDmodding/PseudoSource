// File Line: 12
// RVA: 0x426F20
void __fastcall UFG::MemoryUtil_MarkAllPools(UFG *this)
{
  UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *MemoryPoolList; // rax
  UFG::qMemoryPool *mNext; // rbx
  UFG::qMemoryPool *v3; // rdi

  if ( UFG::gPerformExitGameMemoryCheck )
  {
    MemoryPoolList = UFG::GetMemoryPoolList();
    mNext = (UFG::qMemoryPool *)MemoryPoolList->mNode.mNext;
    v3 = (UFG::qMemoryPool *)MemoryPoolList;
    if ( mNext != (UFG::qMemoryPool *)MemoryPoolList )
    {
      do
      {
        UFG::qMemoryPool::SetMark(mNext);
        mNext = (UFG::qMemoryPool *)mNext->mNext;
      }
      while ( mNext != v3 );
    }
  }
}

// File Line: 26
// RVA: 0x426E20
void __fastcall UFG::MemoryUtil_DumpUnmarked(const char *message)
{
  UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *MemoryPoolList; // rdi
  UFG::qMemoryPool *i; // rbx
  int UnmarkedCount; // esi
  const char *Name; // rax
  UFG::qMemoryPool *j; // rbx
  unsigned int v7; // esi
  const char *v8; // rax

  if ( UFG::gPerformExitGameMemoryCheck )
  {
    UFG::qPrintf(
      "=============================================\n"
      "=============================================\n"
      "=============================================\n"
      "  %s *Begin*\n"
      "=============================================\n"
      "=============================================\n"
      "=============================================\n",
      message);
    MemoryPoolList = UFG::GetMemoryPoolList();
    for ( i = (UFG::qMemoryPool *)MemoryPoolList->mNode.mNext;
          i != (UFG::qMemoryPool *)MemoryPoolList;
          i = (UFG::qMemoryPool *)i->mNext )
    {
      UnmarkedCount = UFG::qMemoryPool::GetUnmarkedCount(i);
      if ( UnmarkedCount > 0 )
      {
        Name = UFG::qMemoryPool::GetName(i);
        UFG::qPrintf("   %s: Contains (%d) unmarked!\n", Name, (unsigned int)UnmarkedCount);
        UFG::qMemoryPool::ReportUnmarked(i);
      }
    }
    UFG::qPrintf(
      "=============================================\n"
      "=============================================\n"
      "=============================================\n"
      "  %s *Begin*\n"
      "=============================================\n"
      "=============================================\n"
      "=============================================\n",
      message);
    UFG::GetMemoryPoolList();
    for ( j = (UFG::qMemoryPool *)MemoryPoolList->mNode.mNext;
          j != (UFG::qMemoryPool *)MemoryPoolList;
          j = (UFG::qMemoryPool *)j->mNext )
    {
      v7 = UFG::qMemoryPool::GetUnmarkedCount(j);
      if ( v7 )
      {
        v8 = UFG::qMemoryPool::GetName(j);
        UFG::qPrintf("   %s: Contains (%d) unmarked!  (See dump above)\n", v8, v7);
      }
      else
      {
        UFG::qMemoryPool::GetName(j);
      }
    }
    UFG::qPrintf(
      "=============================================\n"
      "=============================================\n"
      "=============================================\n"
      "  %s *End*\n"
      "=============================================\n"
      "=============================================\n"
      "=============================================\n",
      message);
  }
}

