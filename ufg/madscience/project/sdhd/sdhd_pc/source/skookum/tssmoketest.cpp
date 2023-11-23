// File Line: 99
// RVA: 0x4EB400
void __fastcall UFG::TSSmoketest::MthdC_press_button(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  UFG::testController.testInput[SLODWORD(i_data_p->i_user_data)].has_input = !UFG::testController.testInput[SLODWORD(i_data_p->i_user_data)].has_input;
}

// File Line: 106
// RVA: 0x4EB020
void __fastcall UFG::TSSmoketest::MthdC_move_analog_stick(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  __int64 i_user_data_low; // rax
  float v4; // xmm1_4

  i_array_p = pScope->i_data.i_array_p;
  i_user_data_low = SLODWORD((*i_array_p)->i_data_p->i_user_data);
  v4 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
  UFG::testController.testInput[i_user_data_low].fDataX = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  UFG::testController.testInput[i_user_data_low].fDataY = v4;
  UFG::testController.testInput[i_user_data_low].has_input = 1;
}

// File Line: 118
// RVA: 0x4E4240
void __fastcall UFG::TSSmoketest::MthdC_cancel_input(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::testController.testInput[SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data)].has_input = 0;
}

// File Line: 125
// RVA: 0x4E4330
void __fastcall UFG::TSSmoketest::MthdC_clear_all_input(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TestInputData *testInput; // rax

  testInput = UFG::testController.testInput;
  do
  {
    testInput->has_input = 0;
    ++testInput;
  }
  while ( (__int64)testInput < (__int64)&UFG::testController.testInput[18] );
  *(_QWORD *)&UFG::testController.testInput[12].fDataX = 0i64;
  *(_QWORD *)&UFG::testController.testInput[13].fDataX = 0i64;
}

// File Line: 136
// RVA: 0x4EB430
void __fastcall UFG::TSSmoketest::MthdC_press_trigger(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  __int64 i_user_data_low; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_user_data_low = SLODWORD((*i_array_p)->i_data_p->i_user_data);
  UFG::testController.testInput[i_user_data_low].fDataX = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  UFG::testController.testInput[i_user_data_low].has_input = 1;
}

// File Line: 145
// RVA: 0x4F2A00
void __fastcall UFG::TSSmoketest::MthdC_toggle_controller(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::testController.active = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 151
// RVA: 0x4F2410
void __fastcall UFG::TSSmoketest::MthdC_start_auto_smoke(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::gStandardSmoketest);
}

// File Line: 157
// RVA: 0x4F2320
void __fastcall UFG::TSSmoketest::MthdC_start_NIS_test(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::gNISTest);
}

// File Line: 163
// RVA: 0x4F2570
void __fastcall UFG::TSSmoketest::MthdC_start_profile_test(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::gProfileTest);
}

// File Line: 169
// RVA: 0x4F23E0
void __fastcall UFG::TSSmoketest::MthdC_start_auto_PIX_capture(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::gAutoPIXCapture);
}

// File Line: 175
// RVA: 0x4F2630
void __fastcall UFG::TSSmoketest::MthdC_start_soak_test(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::gSoaktest);
}

// File Line: 181
// RVA: 0x4F2450
void __fastcall UFG::TSSmoketest::MthdC_start_census_test(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::gCensusTest);
}

// File Line: 192
// RVA: 0x4F2440
void __fastcall UFG::TSSmoketest::MthdC_start_benchmark_timing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::BenchmarkHelper::StartTiming(&UFG::BenchmarkHelper::gBenchmarkHelper);
}

// File Line: 197
// RVA: 0x4F26D0
void __fastcall UFG::TSSmoketest::MthdC_stop_benchmark_timing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::BenchmarkHelper::EndTiming(&UFG::BenchmarkHelper::gBenchmarkHelper);
}

// File Line: 202
// RVA: 0x4EB200
void __fastcall UFG::TSSmoketest::MthdC_pause_benchmark_timing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::BenchmarkHelper::PauseTiming(&UFG::BenchmarkHelper::gBenchmarkHelper);
}

// File Line: 207
// RVA: 0x4EC560
void __fastcall UFG::TSSmoketest::MthdC_resume_benchmark_timing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::BenchmarkHelper::ResumeTiming(&UFG::BenchmarkHelper::gBenchmarkHelper);
}

// File Line: 212
// RVA: 0x4F3620
void __fastcall UFG::TSSmoketest::MthdC_write_benchmark_timing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::BenchmarkHelper::WriteLastResults(&UFG::BenchmarkHelper::gBenchmarkHelper);
}

// File Line: 217
// RVA: 0x4E47F0
// attributes: thunk
void __fastcall UFG::TSSmoketest::MthdC_collect_memory_info(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::CollectMemoryStats((UFG *)pScope);
}

// File Line: 223
// RVA: 0x4E3E30
void __fastcall UFG::TSSmoketest::MthdC_begin_PIX_capture(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  int i_user_data; // ebx

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  UFG::qString::Set(&gPIXCaptureFileName, *(const char **)i_array_p[1]->i_data_p->i_user_data);
  gNumPIXFrames = i_user_data;
  gGrabPIXCapture = 1;
}

// File Line: 233
// RVA: 0x4E4800
// attributes: thunk
void __fastcall UFG::TSSmoketest::MthdC_collect_streaming_memory_info(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::StreamPool_DBGDumpAllPools((UFG *)pScope);
}

// File Line: 238
// RVA: 0x4E4810
// attributes: thunk
void __fastcall UFG::TSSmoketest::MthdC_collect_summary_memory_info(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qPrintSummaryMemoryPools((UFG *)pScope);
}

// File Line: 243
// RVA: 0x4F2350
void __fastcall UFG::TSSmoketest::MthdC_start_ai_test(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  if ( result_pp )
    *result_pp = SSBoolean::pool_new(0);
}

// File Line: 250
// RVA: 0x4EC5E0
void __fastcall UFG::TSSmoketest::MthdC_retrieve_next_road_point(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float *i_user_data; // rdi
  float v4; // xmm6_4
  __int64 mOffset; // rax
  __int64 v6; // rax
  UFG::qOffset64<UFG::RoadNetworkConnection *> *p_mNextConnection; // rbx
  UFG::RoadNetworkConnection *v8; // rbx
  unsigned int v9; // eax
  UFG::RoadNetworkLane *Path; // rax
  __m128 x_low; // xmm1
  unsigned int v12; // xmm0_4
  __m128 v13; // xmm1
  UFG::qVector3 *Pos; // rbx
  UFG::allocator::free_link *v15; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 result; // [rsp+28h] [rbp-60h] BYREF

  i_user_data = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( UFG::TSSmoketest::mNeedNewConnection )
  {
    v4 = FLOAT_0_1;
    mOffset = UFG::TSSmoketest::mCurrentRoadLane->mNextConnection.mOffset;
    if ( mOffset
      && (UFG::qOffset64<UFG::RoadNetworkConnection *> *)((char *)&UFG::TSSmoketest::mCurrentRoadLane->mNextConnection
                                                        + mOffset) )
    {
      v6 = UFG::TSSmoketest::mCurrentRoadLane->mNextConnection.mOffset;
      if ( v6 )
      {
        p_mNextConnection = &UFG::TSSmoketest::mCurrentRoadLane->mNextConnection;
LABEL_8:
        v8 = (UFG::RoadNetworkConnection *)((char *)p_mNextConnection + v6);
LABEL_10:
        v9 = UFG::qRandom(v8->mNumLanes, (unsigned int *)&UFG::qDefaultSeed);
        Path = UFG::qBezierPathCollectionMemImaged::GetPath(v8, v9);
        UFG::TSSmoketest::mCurrentRoadLane = Path;
        goto LABEL_12;
      }
    }
    else
    {
      v6 = UFG::TSSmoketest::mCurrentRoadLane->mStartConnection.mOffset;
      if ( v6 )
      {
        p_mNextConnection = &UFG::TSSmoketest::mCurrentRoadLane->mStartConnection;
        goto LABEL_8;
      }
    }
    v8 = 0i64;
    goto LABEL_10;
  }
  v4 = UFG::TSSmoketest::mLastPosPercentage;
  Path = UFG::TSSmoketest::mCurrentRoadLane;
LABEL_12:
  UFG::RoadNetworkLane::GetPos(Path, &result, v4);
  x_low = (__m128)LODWORD(result.x);
  x_low.m128_f32[0] = (float)((float)((float)(result.x - *i_user_data) * (float)(result.x - *i_user_data))
                            + (float)((float)(result.y - i_user_data[1]) * (float)(result.y - i_user_data[1])))
                    + (float)((float)(result.z - i_user_data[2]) * (float)(result.z - i_user_data[2]));
  v12 = _mm_sqrt_ps(x_low).m128_u32[0];
  if ( v4 >= 1.0 )
  {
LABEL_17:
    v4 = *(float *)&FLOAT_1_0;
    UFG::TSSmoketest::mNeedNewConnection = 1;
    UFG::TSSmoketest::mLastPosPercentage = 0.0;
  }
  else
  {
    while ( *(float *)&v12 <= 50.0 )
    {
      v4 = v4 + 0.1;
      UFG::RoadNetworkLane::GetPos(UFG::TSSmoketest::mCurrentRoadLane, &result, v4);
      v13 = (__m128)LODWORD(result.x);
      v13.m128_f32[0] = (float)((float)((float)(result.x - *i_user_data) * (float)(result.x - *i_user_data))
                              + (float)((float)(result.y - i_user_data[1]) * (float)(result.y - i_user_data[1])))
                      + (float)((float)(result.z - i_user_data[2]) * (float)(result.z - i_user_data[2]));
      v12 = _mm_sqrt_ps(v13).m128_u32[0];
      if ( v4 >= 1.0 )
        goto LABEL_17;
    }
    UFG::TSSmoketest::mLastPosPercentage = v4;
    UFG::TSSmoketest::mNeedNewConnection = 0;
  }
  Pos = UFG::RoadNetworkLane::GetPos(UFG::TSSmoketest::mCurrentRoadLane, &result, v4);
  v15 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v15 )
  {
    y = Pos->y;
    z = Pos->z;
    *(float *)&v15->mNext = Pos->x;
    *((float *)&v15->mNext + 1) = y;
    *(float *)&v15[1].mNext = z;
  }
  *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v15);
}

// File Line: 294
// RVA: 0x4E8D50
void __fastcall UFG::TSSmoketest::MthdC_has_finished_path_to(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  bool v5; // al

  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    i_data_p = 0i64;
  }
LABEL_7:
  v5 = UFG::TSCharacter::IsAtTarget((UFG::TSCharacter *)i_data_p);
  *ppResult = SSBoolean::pool_new(v5);
}

// File Line: 308
// RVA: 0x4E6D60
void __fastcall UFG::TSSmoketest::MthdC_force_progress(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::qBaseTreeRB *v3; // rbx
  UFG::ProgressionTracker *v4; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF

  name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v2 = UFG::ProgressionTracker::Instance();
  v3 = UFG::ProgressionTracker::Find(v2, &name, 0);
  v4 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::ForceSliceChange(v4, (UFG::GameSlice *)v3, 1);
}

// File Line: 319
// RVA: 0x4E3E80
void __fastcall UFG::TSSmoketest::MthdC_begin_preset_gameslice(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::qBaseTreeRB *v3; // rbx
  UFG::ProgressionTracker *v4; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h] BYREF

  UFG::qSymbol::create_from_string(&result, UFG::gProfileSliceName.mData);
  v2 = UFG::ProgressionTracker::Instance();
  v3 = UFG::ProgressionTracker::Find(v2, &result, 0);
  if ( v3 )
  {
    v4 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::ForceProgress(v4, (UFG::GameSlice *)v3, 0);
  }
}

// File Line: 329
// RVA: 0x4E3ED0
void __fastcall UFG::TSSmoketest::MthdC_begin_profile_capture(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  AStringRef *i_user_data; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r8
  bool v7; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  i_user_data = (AStringRef *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  ++i_user_data->i_ref_count;
  UFG::ProfileWizard::sProfileCaptureFrames = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64)
                                                        + 32i64);
  UFG::ProfileWizard::sProfileIntoDB = 1;
  if ( i_user_data->i_ref_count-- == 1 )
  {
    if ( i_user_data->i_deallocate )
      AMemory::c_free_func(i_user_data->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)i_user_data < i_objects_a
      || (v7 = (unsigned __int64)i_user_data < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool,
                                                                                        !v7) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_user_data);
  }
}

// File Line: 353
// RVA: 0x4E9240
void __fastcall UFG::TSSmoketest::MthdC_initialize_census(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  AMD_HD3D *Instance; // rax

  Instance = (AMD_HD3D *)UFG::CensusHelper::GetInstance();
  _(Instance);
}

// File Line: 358
// RVA: 0x4EC570
void __fastcall UFG::TSSmoketest::MthdC_retrieve_next_census_point(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qString *v3; // rax
  UFG::qString *v4; // rbx
  UFG::CensusHelper *Instance; // rcx
  UFG::qVector3 *v6; // rax
  UFG::qVector3 v7; // [rsp+28h] [rbp-40h] BYREF
  UFG::qString v8; // [rsp+38h] [rbp-30h] BYREF

  if ( ppResult )
  {
    UFG::qString::qString(&v8, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v4 = v3;
    Instance = UFG::CensusHelper::GetInstance();
    v6 = UFG::CensusHelper::RetrieveNextVector(Instance, &v7, v4);
    *ppResult = UFG::TSVector3::AsInstance(v6);
  }
}

// File Line: 370
// RVA: 0x4E47D0
void __fastcall UFG::TSSmoketest::MthdC_collect_census_stats(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  AMD_HD3D *Instance; // rax

  Instance = (AMD_HD3D *)UFG::CensusHelper::GetInstance();
  _(Instance);
}

// File Line: 376
// RVA: 0x4D64B0
void UFG::TSSmoketest::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]
  ASymbol rebindh; // [rsp+20h] [rbp-18h]
  ASymbol rebindi; // [rsp+20h] [rbp-18h]
  ASymbol rebindj; // [rsp+20h] [rbp-18h]
  ASymbol rebindk; // [rsp+20h] [rbp-18h]
  ASymbol rebindl; // [rsp+20h] [rbp-18h]
  ASymbol rebindm; // [rsp+20h] [rbp-18h]
  ASymbol rebindn; // [rsp+20h] [rbp-18h]
  ASymbol rebindo; // [rsp+20h] [rbp-18h]
  ASymbol rebindp; // [rsp+20h] [rbp-18h]
  ASymbol rebindq; // [rsp+20h] [rbp-18h]
  ASymbol rebindr; // [rsp+20h] [rbp-18h]
  ASymbol rebinds; // [rsp+20h] [rbp-18h]
  ASymbol rebindt; // [rsp+20h] [rbp-18h]
  ASymbol rebindu; // [rsp+20h] [rbp-18h]
  ASymbol rebindv; // [rsp+20h] [rbp-18h]
  ASymbol rebindw; // [rsp+20h] [rbp-18h]
  ASymbol rebindx; // [rsp+20h] [rbp-18h]
  ASymbol rebindy; // [rsp+20h] [rbp-18h]
  ASymbol rebindz; // [rsp+20h] [rbp-18h]
  ASymbol rebindba; // [rsp+20h] [rbp-18h]
  ASymbol rebindbb; // [rsp+20h] [rbp-18h]
  ASymbol rebindbc; // [rsp+20h] [rbp-18h]
  ASymbol rebindbd; // [rsp+20h] [rbp-18h]
  ASymbol rebindbe; // [rsp+20h] [rbp-18h]
  ASymbol rebindbf; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("Smoketest");
  SSClass::register_method_func(v0, "press_button", UFG::TSSmoketest::MthdC_press_button, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "toggle_controller", UFG::TSSmoketest::MthdC_toggle_controller, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "press_trigger", UFG::TSSmoketest::MthdC_press_trigger, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "clear_all_input", UFG::TSSmoketest::MthdC_clear_all_input, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "cancel_input", UFG::TSSmoketest::MthdC_cancel_input, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v0, "move_analog_stick", UFG::TSSmoketest::MthdC_move_analog_stick, 1, rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(v0, "start_auto_smoke", UFG::TSSmoketest::MthdC_start_auto_smoke, 1, rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(v0, "start_NIS_test", UFG::TSSmoketest::MthdC_start_NIS_test, 1, rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(v0, "start_soak_test", UFG::TSSmoketest::MthdC_start_soak_test, 1, rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(v0, "start_ai_test", UFG::TSSmoketest::MthdC_start_ai_test, 1, rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(v0, "collect_memory_info", UFG::TSSmoketest::MthdC_collect_memory_info, 1, rebindj);
  LOBYTE(rebindk.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "collect_summary_memory_info",
    UFG::TSSmoketest::MthdC_collect_summary_memory_info,
    1,
    rebindk);
  LOBYTE(rebindl.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "collect_streaming_memory_info",
    UFG::TSSmoketest::MthdC_collect_streaming_memory_info,
    1,
    rebindl);
  LOBYTE(rebindm.i_uid) = 0;
  SSClass::register_method_func(v0, "begin_profile_capture", UFG::TSSmoketest::MthdC_begin_profile_capture, 1, rebindm);
  LOBYTE(rebindn.i_uid) = 0;
  SSClass::register_method_func(v0, "start_profile_test", UFG::TSSmoketest::MthdC_start_profile_test, 1, rebindn);
  LOBYTE(rebindo.i_uid) = 0;
  SSClass::register_method_func(v0, "begin_pix_capture", UFG::TSSmoketest::MthdC_begin_PIX_capture, 1, rebindo);
  LOBYTE(rebindp.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "start_auto_pix_capture",
    UFG::TSSmoketest::MthdC_start_auto_PIX_capture,
    1,
    rebindp);
  LOBYTE(rebindq.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "signal_test_complete",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebindq);
  LOBYTE(rebindr.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "start_benchmark_timing",
    UFG::TSSmoketest::MthdC_start_benchmark_timing,
    1,
    rebindr);
  LOBYTE(rebinds.i_uid) = 0;
  SSClass::register_method_func(v0, "stop_benchmark_timing", UFG::TSSmoketest::MthdC_stop_benchmark_timing, 1, rebinds);
  LOBYTE(rebindt.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "pause_benchmark_timing",
    UFG::TSSmoketest::MthdC_pause_benchmark_timing,
    1,
    rebindt);
  LOBYTE(rebindu.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "resume_benchmark_timing",
    UFG::TSSmoketest::MthdC_resume_benchmark_timing,
    1,
    rebindu);
  LOBYTE(rebindv.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "write_benchmark_timing",
    UFG::TSSmoketest::MthdC_write_benchmark_timing,
    1,
    rebindv);
  LOBYTE(rebindw.i_uid) = 0;
  SSClass::register_method_func(v0, "has_finished_path_to", UFG::TSSmoketest::MthdC_has_finished_path_to, 1, rebindw);
  LOBYTE(rebindx.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "retrieve_next_road_point",
    UFG::TSSmoketest::MthdC_retrieve_next_road_point,
    1,
    rebindx);
  LOBYTE(rebindy.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "initialize_ai_test",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebindy);
  LOBYTE(rebindz.i_uid) = 0;
  SSClass::register_method_func(v0, "force_progress", UFG::TSSmoketest::MthdC_force_progress, 1, rebindz);
  LOBYTE(rebindba.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "begin_preset_gameslice",
    UFG::TSSmoketest::MthdC_begin_preset_gameslice,
    1,
    rebindba);
  LOBYTE(rebindbb.i_uid) = 0;
  SSClass::register_method_func(v0, "start_census_test", UFG::TSSmoketest::MthdC_start_census_test, 1, rebindbb);
  LOBYTE(rebindbc.i_uid) = 0;
  SSClass::register_method_func(v0, "initialize_census", UFG::TSSmoketest::MthdC_initialize_census, 1, rebindbc);
  LOBYTE(rebindbd.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "retrieve_next_census_point",
    UFG::TSSmoketest::MthdC_retrieve_next_census_point,
    1,
    rebindbd);
  LOBYTE(rebindbe.i_uid) = 0;
  SSClass::register_method_func(v0, "reset_census_stats", UFG::TSSmoketest::MthdC_collect_census_stats, 1, rebindbe);
  LOBYTE(rebindbf.i_uid) = 0;
  SSClass::register_method_func(v0, "collect_census_stats", UFG::TSSmoketest::MthdC_collect_census_stats, 1, rebindbf);
}

