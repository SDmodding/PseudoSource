// File Line: 35
// RVA: 0x419240
void UFG::OperationManager::CreateInstance(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::OperationManager *v1; // rbx

  v0 = UFG::qMalloc(0x58ui64, "OperationManager", 0i64);
  v1 = (UFG::OperationManager *)v0;
  if ( v0 )
  {
    LODWORD(v0->mNext) = -1;
    UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)&v0[1]);
    v1->m_CurrentOperation = 0i64;
    UFG::OperationManager::m_Instance = v1;
  }
  else
  {
    UFG::OperationManager::m_Instance = 0i64;
  }
}

// File Line: 41
// RVA: 0x4192B0
UFG::OperationManager *__fastcall UFG::OperationManager::Get()
{
  return UFG::OperationManager::m_Instance;
}

// File Line: 70
// RVA: 0x419680
void __fastcall UFG::OperationManager::Update(UFG::OperationManager *this, float deltaSeconds)
{
  UFG::qBaseTreeRB *v2; // rbx
  UFG::qBaseTreeRB *i; // rax
  signed __int64 v4; // rdx

  v2 = &this->m_GOperations.mTree;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->m_GOperations);
        ;
        i = UFG::qBaseTreeRB::GetNext(v2, (UFG::qBaseNodeRB *)(v4 + 8)) )
  {
    v4 = (signed __int64)(i ? &i[-1].mCount : 0i64);
    if ( !v4 )
      break;
  }
}

