// File Line: 45
// RVA: 0x3DFA10
void __fastcall UFG::NavigationConfigs::CreateNavManager()
{
  UFG::allocator::free_link *v0; // rax

  v0 = UFG::qMalloc(0x130ui64, "HavokNavManager", 0i64);
  if ( v0 )
    UFG::HavokNavManager::HavokNavManager((UFG::HavokNavManager *)v0);
}

// File Line: 51
// RVA: 0x3DF870
UFG::allocator::free_link *__fastcall UFG::NavigationConfigs::CreateAvoidanceStrategy()
{
  UFG::allocator::free_link *v0; // rax
  UFG::allocator::free_link *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::NavManager *v6; // rdi
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::NavManager *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rax

  if ( UFG::NavigationConfigs::gNavAvoidanceStrategy )
  {
    switch ( UFG::NavigationConfigs::gNavAvoidanceStrategy )
    {
      case 1:
        v9 = UFG::NavManager::ms_pInstance;
        v10 = UFG::qMalloc(0x80ui64, "NavAvoidanceStrategyRVO", 0i64);
        if ( v10 )
        {
          UFG::NavAvoidanceStrategyRVO::NavAvoidanceStrategyRVO(
            (UFG::NavAvoidanceStrategyRVO *)v10,
            (hkaiWorld *)v9[3].vfptr,
            (hkJobQueue *)v9[10].vfptr,
            (hkJobThreadPool *)v9[11].vfptr,
            AVOIDANCE_SOLVER_PENALTY_FORCES);
          v1 = v11;
        }
        else
        {
          v1 = 0i64;
        }
        break;
      case 2:
        v6 = UFG::NavManager::ms_pInstance;
        v7 = UFG::qMalloc(0x80ui64, "NavAvoidanceStrategyRVO", 0i64);
        v1 = 0i64;
        if ( v7 )
        {
          UFG::NavAvoidanceStrategyRVO::NavAvoidanceStrategyRVO(
            (UFG::NavAvoidanceStrategyRVO *)v7,
            (hkaiWorld *)v6[3].vfptr,
            (hkJobQueue *)v6[10].vfptr,
            (hkJobThreadPool *)v6[11].vfptr,
            0);
          v1 = v8;
        }
        break;
      case 3:
        v4 = UFG::qMalloc(8ui64, "NavAvoidanceStrategyORCA", 0i64);
        if ( v4 )
        {
          UFG::NavAvoidanceStrategyFlowField::NavAvoidanceStrategyFlowField((UFG::NavAvoidanceStrategyFlowField *)v4);
          v1 = v5;
        }
        else
        {
          v1 = 0i64;
        }
        break;
      case 4:
        v2 = UFG::qMalloc(0x7E8ui64, "NavAvoidanceStrategyORCA", 0i64);
        if ( v2 )
        {
          UFG::NavAvoidanceStrategyORCA::NavAvoidanceStrategyORCA((UFG::NavAvoidanceStrategyORCA *)v2);
          v1 = v3;
        }
        else
        {
          v1 = 0i64;
        }
        break;
      default:
        v0 = UFG::qMalloc(8ui64, "NavAvoidanceStrategyNone", 0i64);
        v1 = v0;
        if ( v0 )
        {
          UFG::NavAvoidanceStrategy::NavAvoidanceStrategy((UFG::NavAvoidanceStrategy *)v0);
          v1->mNext = (UFG::allocator::free_link *)&UFG::NavAvoidanceStrategyNone::`vftable';
        }
        else
        {
          v1 = 0i64;
        }
        break;
    }
  }
  else
  {
    v12 = UFG::qMalloc(8ui64, "NavAvoidanceStrategyNone", 0i64);
    v1 = v12;
    if ( v12 )
    {
      UFG::NavAvoidanceStrategy::NavAvoidanceStrategy((UFG::NavAvoidanceStrategy *)v12);
      v1->mNext = (UFG::allocator::free_link *)&UFG::NavAvoidanceStrategyNone::`vftable';
    }
    else
    {
      v1 = 0i64;
    }
  }
  return v1;
}

