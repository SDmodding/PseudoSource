// File Line: 23
// RVA: 0x146E710
__int64 UFG::Editor::SubobjectManager::_dynamic_initializer_for__mObjectsInSubobjectMode__()
{
  return atexit(UFG::Editor::SubobjectManager::_dynamic_atexit_destructor_for__mObjectsInSubobjectMode__);
}

// File Line: 88
// RVA: 0x20DE40
char __fastcall UFG::Editor::SubobjectManager::IsInSubobjectMode(UFG::Editor::DAGPath *path)
{
  unsigned int v1; // er11
  UFG::qNode<UFG::Editor::SubobjectManager::DAGPathSubobj,UFG::Editor::SubobjectManager::DAGPathSubobj> *i; // r8
  __int64 v4; // rax
  __int64 v5; // rdx
  __int64 v6; // r9
  UFG::qSymbol *v7; // rax
  signed __int64 v8; // r10

  v1 = path->mElements.size;
  if ( !v1 )
    return 0;
  for ( i = UFG::Editor::SubobjectManager::mObjectsInSubobjectMode.mNode.mNext;
        i != (UFG::qNode<UFG::Editor::SubobjectManager::DAGPathSubobj,UFG::Editor::SubobjectManager::DAGPathSubobj> *)&UFG::Editor::SubobjectManager::mObjectsInSubobjectMode;
        i = i->mNext )
  {
    if ( LODWORD(i[3].mPrev) == path->mSystemName.mUID )
    {
      v4 = LODWORD(i[3].mNext);
      if ( (_DWORD)v4 == v1 )
      {
        v5 = 0i64;
        v6 = (unsigned int)v4;
        if ( v4 <= 0 )
          return 1;
        v7 = path->mElements.p;
        v8 = (char *)i[4].mPrev - (char *)v7;
        while ( *(unsigned int *)((char *)&v7->mUID + v8) == v7->mUID )
        {
          ++v5;
          ++v7;
          if ( v5 >= v6 )
            return 1;
        }
      }
    }
  }
  return 0;
}

