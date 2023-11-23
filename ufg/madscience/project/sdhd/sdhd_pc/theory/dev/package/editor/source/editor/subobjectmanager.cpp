// File Line: 23
// RVA: 0x146E710
__int64 UFG::Editor::SubobjectManager::_dynamic_initializer_for__mObjectsInSubobjectMode__()
{
  return atexit((int (__fastcall *)())UFG::Editor::SubobjectManager::_dynamic_atexit_destructor_for__mObjectsInSubobjectMode__);
}

// File Line: 88
// RVA: 0x20DE40
char __fastcall UFG::Editor::SubobjectManager::IsInSubobjectMode(UFG::Editor::DAGPath *path)
{
  unsigned int size; // r11d
  UFG::qNode<UFG::Editor::SubobjectManager::DAGPathSubobj,UFG::Editor::SubobjectManager::DAGPathSubobj> *i; // r8
  unsigned int mNext; // eax
  __int64 v5; // rdx
  __int64 v6; // r9
  UFG::qSymbol *p; // rax
  signed __int64 v8; // r10

  size = path->mElements.size;
  if ( !size )
    return 0;
  for ( i = UFG::Editor::SubobjectManager::mObjectsInSubobjectMode.mNode.mNext;
        i != (UFG::qNode<UFG::Editor::SubobjectManager::DAGPathSubobj,UFG::Editor::SubobjectManager::DAGPathSubobj> *)&UFG::Editor::SubobjectManager::mObjectsInSubobjectMode;
        i = i->mNext )
  {
    if ( LODWORD(i[3].mPrev) == path->mSystemName.mUID )
    {
      mNext = (unsigned int)i[3].mNext;
      if ( mNext == size )
      {
        v5 = 0i64;
        v6 = mNext;
        if ( !LODWORD(i[3].mNext) )
          return 1;
        p = path->mElements.p;
        v8 = (char *)i[4].mPrev - (char *)p;
        while ( *(unsigned int *)((char *)&p->mUID + v8) == p->mUID )
        {
          ++v5;
          ++p;
          if ( v5 >= v6 )
            return 1;
        }
      }
    }
  }
  return 0;
}

