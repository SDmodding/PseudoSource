// File Line: 79
// RVA: 0x20DCA0
void __fastcall UFG::Editor::SelectionManager::InvalidatePaths(UFG::Editor::SelectionManager *this)
{
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *i; // rsi
  unsigned int j; // edi
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> **v3; // rbx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v4; // rcx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v5; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v6; // rdx

  for ( i = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
        i != (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets;
        i = i->mNext )
  {
    for ( j = 0; j < LODWORD(i[3].mNext); v3[2] = 0i64 )
    {
      v3 = &i[4].mPrev->mPrev + 11 * j;
      v4 = v3[2];
      if ( v4 )
      {
        v5 = v3[1];
        v6 = *v3;
        v6->mNext = v5;
        v5->mPrev = v6;
        *v3 = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)v3;
        v3[1] = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)v3;
        if ( v4[3].mPrev == (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&v4[2].mNext )
          ((void (__fastcall *)(UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *, __int64))v4->mPrev->mPrev)(
            v4,
            1i64);
        v3[2] = 0i64;
      }
      ++j;
    }
  }
}

// File Line: 97
// RVA: 0x20B850
UFG::Editor::SelectionSet *__fastcall UFG::Editor::SelectionManager::GetCreateSelectionSet(const char *name)
{
  UFG::Editor::SelectionSet *result; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *v4; // rbx
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *mPrev; // rcx

  result = UFG::Editor::SelectionManager::GetSelectionSet(name);
  if ( !result )
  {
    v3 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
    v4 = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)v3;
    if ( v3 )
    {
      v3->mNext = v3;
      v3[1].mNext = v3;
      UFG::qString::qString((UFG::qString *)&v3[2], name);
      v4[4].mPrev = 0i64;
      v4[3].mNext = 0i64;
    }
    else
    {
      v4 = 0i64;
    }
    mPrev = UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev;
    UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev->mNext = v4;
    v4->mPrev = mPrev;
    v4->mNext = (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets;
    UFG::Editor::SelectionManager::mSelectionSets.mNode.mPrev = v4;
    return (UFG::Editor::SelectionSet *)v4;
  }
  return result;
}

// File Line: 109
// RVA: 0x20C820
UFG::Editor::SelectionSet *__fastcall UFG::Editor::SelectionManager::GetSelectionSet(const char *name)
{
  UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *mNext; // rbx

  if ( !name )
    return (UFG::Editor::SelectionSet *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  mNext = UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext;
  if ( (UFG::qList<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet,1,0> *)UFG::Editor::SelectionManager::mSelectionSets.mNode.mNext == &UFG::Editor::SelectionManager::mSelectionSets )
    return 0i64;
  while ( (unsigned int)UFG::qStringCompare(name, (const char *)mNext[2].mNext, -1) )
  {
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::Editor::SelectionSet,UFG::Editor::SelectionSet> *)&UFG::Editor::SelectionManager::mSelectionSets )
      return 0i64;
  }
  return (UFG::Editor::SelectionSet *)mNext;
}

