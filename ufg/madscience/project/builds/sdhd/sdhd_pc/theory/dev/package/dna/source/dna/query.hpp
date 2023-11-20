// File Line: 118
// RVA: 0x9CC50
void __fastcall DNA::Query::~Query(DNA::Query *this)
{
  DNA::IQueryNode *v1; // rcx

  v1 = this->mRoot;
  if ( v1 )
    ((void (__fastcall *)(DNA::IQueryNode *, signed __int64))v1->vfptr->~IQueryNode)(v1, 1i64);
}

