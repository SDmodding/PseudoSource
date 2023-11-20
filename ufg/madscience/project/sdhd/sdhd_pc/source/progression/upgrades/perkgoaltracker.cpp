// File Line: 11
// RVA: 0x4AB6F0
UFG::PerkGoalTracker *__fastcall UFG::PerkGoalTracker::Instance()
{
  if ( !(_S9_13 & 1) )
  {
    _S9_13 |= 1u;
    UFG::PerkGoalTracker::PerkGoalTracker(&sPerkGoalTracker);
    atexit(UFG::PerkGoalTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sPerkGoalTracker__);
  }
  UFG::PerkGoalTracker::m_pInstance = &sPerkGoalTracker;
  return &sPerkGoalTracker;
}

// File Line: 21
// RVA: 0x48D0D0
void __fastcall UFG::PerkGoalTracker::PerkGoalTracker(UFG::PerkGoalTracker *this)
{
  UFG::PerkGoalTracker *v1; // rbx
  UFG::qBaseTreeRB *v2; // rsi
  unsigned int v3; // eax
  unsigned int v4; // ebp
  UFG::qBaseTreeRB *v5; // rdi
  UFG::allocator::free_link *v6; // rax
  unsigned int v7; // eax
  unsigned int v8; // ebp
  UFG::qBaseTreeRB *v9; // rdi
  UFG::allocator::free_link *v10; // rax
  unsigned int v11; // eax
  unsigned int v12; // ebp
  UFG::qBaseTreeRB *v13; // rdi
  UFG::allocator::free_link *v14; // rax
  unsigned int v15; // eax
  unsigned int v16; // ebp
  UFG::qBaseTreeRB *v17; // rdi
  UFG::allocator::free_link *v18; // rax
  unsigned int v19; // eax
  unsigned int v20; // ebp
  UFG::qBaseTreeRB *v21; // rdi
  UFG::allocator::free_link *v22; // rax

  v1 = this;
  v2 = &this->m_hashLookup.mTree.mTree;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->m_hashLookup.mTree.mTree);
  v1->m_maxGoalProgress[0] = 5;
  v1->m_maxGoalProgress[1] = 1;
  v1->m_maxGoalProgress[2] = 5;
  v1->m_maxGoalProgress[3] = 1;
  v1->m_maxGoalProgress[4] = 5;
  v3 = UFG::qStringHash32("no_civilians", 0xFFFFFFFF);
  v4 = v3;
  if ( !v3 || (v5 = UFG::qBaseTreeRB::Get(v2, v3)) == 0i64 )
  {
    v6 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
    v5 = (UFG::qBaseTreeRB *)v6;
    if ( v6 )
    {
      v6->mNext = 0i64;
      v6[1].mNext = 0i64;
      v6[2].mNext = 0i64;
      LODWORD(v6[3].mNext) = v4;
      LODWORD(v6[4].mNext) = 0;
    }
    else
    {
      v5 = 0i64;
    }
    UFG::qBaseTreeRB::Add(v2, &v5->mRoot);
  }
  LODWORD(v5->mNULL.mParent) = 0;
  v7 = UFG::qStringHash32("no_cops", 0xFFFFFFFF);
  v8 = v7;
  if ( !v7 || (v9 = UFG::qBaseTreeRB::Get(v2, v7)) == 0i64 )
  {
    v10 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
    v9 = (UFG::qBaseTreeRB *)v10;
    if ( v10 )
    {
      v10->mNext = 0i64;
      v10[1].mNext = 0i64;
      v10[2].mNext = 0i64;
      LODWORD(v10[3].mNext) = v8;
      LODWORD(v10[4].mNext) = 1;
    }
    else
    {
      v9 = 0i64;
    }
    UFG::qBaseTreeRB::Add(v2, &v9->mRoot);
  }
  LODWORD(v9->mNULL.mParent) = 1;
  v11 = UFG::qStringHash32("no_kills", 0xFFFFFFFF);
  v12 = v11;
  if ( !v11 || (v13 = UFG::qBaseTreeRB::Get(v2, v11)) == 0i64 )
  {
    v14 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
    v13 = (UFG::qBaseTreeRB *)v14;
    if ( v14 )
    {
      v14->mNext = 0i64;
      v14[1].mNext = 0i64;
      v14[2].mNext = 0i64;
      LODWORD(v14[3].mNext) = v12;
      LODWORD(v14[4].mNext) = 2;
    }
    else
    {
      v13 = 0i64;
    }
    UFG::qBaseTreeRB::Add(v2, &v13->mRoot);
  }
  LODWORD(v13->mNULL.mParent) = 2;
  v15 = UFG::qStringHash32("no_alerts", 0xFFFFFFFF);
  v16 = v15;
  if ( !v15 || (v17 = UFG::qBaseTreeRB::Get(v2, v15)) == 0i64 )
  {
    v18 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
    v17 = (UFG::qBaseTreeRB *)v18;
    if ( v18 )
    {
      v18->mNext = 0i64;
      v18[1].mNext = 0i64;
      v18[2].mNext = 0i64;
      LODWORD(v18[3].mNext) = v16;
      LODWORD(v18[4].mNext) = 3;
    }
    else
    {
      v17 = 0i64;
    }
    UFG::qBaseTreeRB::Add(v2, &v17->mRoot);
  }
  LODWORD(v17->mNULL.mParent) = 3;
  v19 = UFG::qStringHash32("no_property_damage", 0xFFFFFFFF);
  v20 = v19;
  if ( !v19 || (v21 = UFG::qBaseTreeRB::Get(v2, v19)) == 0i64 )
  {
    v22 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
    v21 = (UFG::qBaseTreeRB *)v22;
    if ( v22 )
    {
      v22->mNext = 0i64;
      v22[1].mNext = 0i64;
      v22[2].mNext = 0i64;
      LODWORD(v22[3].mNext) = v20;
      LODWORD(v22[4].mNext) = 4;
    }
    else
    {
      v21 = 0i64;
    }
    UFG::qBaseTreeRB::Add(v2, &v21->mRoot);
  }
  LODWORD(v21->mNULL.mParent) = 4;
  *(_WORD *)&v1->m_perks[0].active = 0;
  *(_QWORD *)&v1->m_perks[0].currentProgress = 0i64;
  v1->m_perks[0].maxProgress = v1->m_maxGoalProgress[0];
  *(_WORD *)&v1->m_perks[1].active = 0;
  *(_QWORD *)&v1->m_perks[1].currentProgress = 0i64;
  v1->m_perks[1].maxProgress = v1->m_maxGoalProgress[1];
  *(_WORD *)&v1->m_perks[2].active = 0;
  *(_QWORD *)&v1->m_perks[2].currentProgress = 0i64;
  v1->m_perks[2].maxProgress = v1->m_maxGoalProgress[2];
  *(_WORD *)&v1->m_perks[3].active = 0;
  *(_QWORD *)&v1->m_perks[3].currentProgress = 0i64;
  v1->m_perks[3].maxProgress = v1->m_maxGoalProgress[3];
  *(_WORD *)&v1->m_perks[4].active = 0;
  *(_QWORD *)&v1->m_perks[4].currentProgress = 0i64;
  v1->m_perks[4].maxProgress = v1->m_maxGoalProgress[4];
}

// File Line: 94
// RVA: 0x4A5620
signed __int64 __fastcall UFG::PerkGoalTracker::GetNumGoalsSatisfied(UFG::PerkGoalTracker *this)
{
  signed __int64 result; // rax

  result = 0i64;
  if ( this->m_perks[0].active && !this->m_perks[0].failed )
    result = 1i64;
  if ( this->m_perks[1].active && !this->m_perks[1].failed )
    result = (unsigned int)(result + 1);
  if ( this->m_perks[2].active && !this->m_perks[2].failed )
    result = (unsigned int)(result + 1);
  if ( this->m_perks[3].active && !this->m_perks[3].failed )
    result = (unsigned int)(result + 1);
  if ( this->m_perks[4].active )
  {
    if ( !this->m_perks[4].failed )
      result = (unsigned int)(result + 1);
  }
  return result;
}

