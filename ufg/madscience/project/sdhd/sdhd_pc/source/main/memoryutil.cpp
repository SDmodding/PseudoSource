// File Line: 12
// RVA: 0x426F20
void __fastcall UFG::MemoryUtil_MarkAllPools(UFG *this)
{
  UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *v1; // rax
  UFG::qMemoryPool *v2; // rbx
  UFG::qMemoryPool *v3; // rdi

  if ( UFG::gPerformExitGameMemoryCheck )
  {
    v1 = UFG::GetMemoryPoolList();
    v2 = (UFG::qMemoryPool *)v1->mNode.mNext;
    v3 = (UFG::qMemoryPool *)v1;
    if ( v2 != (UFG::qMemoryPool *)v1 )
    {
      do
      {
        UFG::qMemoryPool::SetMark(v2);
        v2 = (UFG::qMemoryPool *)v2->mNext;
      }
      while ( v2 != v3 );
    }
  }
}

// File Line: 26
// RVA: 0x426E20
void __fastcall UFG::MemoryUtil_DumpUnmarked(const char *message)
{
  const char *v1; // rbp
  UFG::qList<UFG::qMemoryPool,UFG::qMemoryPool,0,0> *v2; // rdi
  UFG::qMemoryPool *i; // rbx
  int v4; // esi
  const char *v5; // rax
  UFG::qMemoryPool *j; // rbx
  unsigned int v7; // esi
  const char *v8; // rax

  v1 = message;
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
    v2 = UFG::GetMemoryPoolList();
    for ( i = (UFG::qMemoryPool *)v2->mNode.mNext; i != (UFG::qMemoryPool *)v2; i = (UFG::qMemoryPool *)i->mNext )
    {
      v4 = UFG::qMemoryPool::GetUnmarkedCount(i);
      if ( v4 > 0 )
      {
        v5 = UFG::qMemoryPool::GetName(i);
        UFG::qPrintf("   %s: Contains (%d) unmarked!\n", v5, (unsigned int)v4);
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
      v1);
    UFG::GetMemoryPoolList();
    for ( j = (UFG::qMemoryPool *)v2->mNode.mNext; j != (UFG::qMemoryPool *)v2; j = (UFG::qMemoryPool *)j->mNext )
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
      v1);
  }
}

