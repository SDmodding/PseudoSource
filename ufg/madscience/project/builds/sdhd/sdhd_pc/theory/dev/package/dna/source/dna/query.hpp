// File Line: 118
// RVA: 0x9CC50
void __fastcall DNA::Query::~Query(DNA::Query *this)
{
  DNA::IQueryNode *mRoot; // rcx

  mRoot = this->mRoot;
  if ( mRoot )
    ((void (__fastcall *)(DNA::IQueryNode *, __int64))mRoot->vfptr->~IQueryNode)(mRoot, 1i64);
}

