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
  __int64 v3; // rax
  UFG::allocator::free_link *v4; // rax
  __int64 v5; // rax
  UFG::NavManager *v6; // rdi
  UFG::allocator::free_link *v7; // rax
  __int64 v8; // rax
  UFG::NavManager *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  __int64 v11; // rax

  switch ( UFG::NavigationConfigs::gNavAvoidanceStrategy )
  {
    case eNavAvoidanceStrategy_None:
      v0 = UFG::qMalloc(8ui64, "NavAvoidanceStrategyNone", 0i64);
      v1 = v0;
      if ( !v0 )
        return 0i64;
      goto LABEL_21;
    case eNavAvoidanceStrategy_RVO_Penalty:
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
        return (UFG::allocator::free_link *)v11;
      }
      else
      {
        return 0i64;
      }
    case eNavAvoidanceStrategy_RVO_Sampling:
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
          AVOIDANCE_SOLVER_SAMPLING);
        return (UFG::allocator::free_link *)v8;
      }
      break;
    case eNavAvoidanceStrategy_FlowField:
      v4 = UFG::qMalloc(8ui64, "NavAvoidanceStrategyORCA", 0i64);
      if ( v4 )
      {
        UFG::NavAvoidanceStrategyFlowField::NavAvoidanceStrategyFlowField((UFG::NavAvoidanceStrategyFlowField *)v4);
        return (UFG::allocator::free_link *)v5;
      }
      else
      {
        return 0i64;
      }
    case eNavAvoidanceStrategy_ORCA:
      v2 = UFG::qMalloc(0x7E8ui64, "NavAvoidanceStrategyORCA", 0i64);
      if ( v2 )
      {
        UFG::NavAvoidanceStrategyORCA::NavAvoidanceStrategyORCA((UFG::NavAvoidanceStrategyORCA *)v2);
        return (UFG::allocator::free_link *)v3;
      }
      else
      {
        return 0i64;
      }
    default:
      v0 = UFG::qMalloc(8ui64, "NavAvoidanceStrategyNone", 0i64);
      v1 = v0;
      if ( !v0 )
        return 0i64;
LABEL_21:
      UFG::NavAvoidanceStrategy::NavAvoidanceStrategy((UFG::NavAvoidanceStrategy *)v0);
      v1->mNext = (UFG::allocator::free_link *)&UFG::NavAvoidanceStrategyNone::`vftable;
      return v1;
  }
  return v1;
}

