// File Line: 99
// RVA: 0x4EB400
void __fastcall UFG::TSSmoketest::MthdC_press_button(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  UFG::testController.testInput[SLODWORD(v2->i_user_data)].has_input = UFG::testController.testInput[SLODWORD(v2->i_user_data)].has_input == 0;
}

// File Line: 106
// RVA: 0x4EB020
void __fastcall UFG::TSSmoketest::MthdC_move_analog_stick(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  __int64 v3; // rax
  float v4; // xmm1_4

  v2 = pScope->i_data.i_array_p;
  v3 = SLODWORD((*v2)->i_data_p->i_user_data);
  v4 = *(float *)&v2[2]->i_data_p->i_user_data;
  UFG::testController.testInput[v3].fDataX = *(float *)&v2[1]->i_data_p->i_user_data;
  UFG::testController.testInput[v3].fDataY = v4;
  UFG::testController.testInput[v3].has_input = 1;
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
  UFG::TestInputData *v2; // rax

  v2 = UFG::testController.testInput;
  do
  {
    v2->has_input = 0;
    ++v2;
  }
  while ( (signed __int64)v2 < (signed __int64)&UFG::testController.testInput[18] );
  *(_QWORD *)&UFG::testController.testInput[12].fDataX = 0i64;
  *(_QWORD *)&UFG::testController.testInput[13].fDataX = 0i64;
}

// File Line: 136
// RVA: 0x4EB430
void __fastcall UFG::TSSmoketest::MthdC_press_trigger(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  __int64 v3; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = SLODWORD((*v2)->i_data_p->i_user_data);
  UFG::testController.testInput[v3].fDataX = *(float *)&v2[1]->i_data_p->i_user_data;
  UFG::testController.testInput[v3].has_input = 1;
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
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::gStandardSmoketest);
}

// File Line: 157
// RVA: 0x4F2320
void __fastcall UFG::TSSmoketest::MthdC_start_NIS_test(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::gNISTest);
}

// File Line: 163
// RVA: 0x4F2570
void __fastcall UFG::TSSmoketest::MthdC_start_profile_test(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::gProfileTest);
}

// File Line: 169
// RVA: 0x4F23E0
void __fastcall UFG::TSSmoketest::MthdC_start_auto_PIX_capture(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::gAutoPIXCapture);
}

// File Line: 175
// RVA: 0x4F2630
void __fastcall UFG::TSSmoketest::MthdC_start_soak_test(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::gSoaktest);
}

// File Line: 181
// RVA: 0x4F2450
void __fastcall UFG::TSSmoketest::MthdC_start_census_test(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::gCensusTest);
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
void __fastcall UFG::TSSmoketest::MthdC_collect_memory_info(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::CollectMemoryStats((UFG *)pScope);
}

// File Line: 223
// RVA: 0x4E3E30
void __fastcall UFG::TSSmoketest::MthdC_begin_PIX_capture(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  int v3; // ebx

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  UFG::qString::Set(&gPIXCaptureFileName, *(const char **)v2[1]->i_data_p->i_user_data);
  gNumPIXFrames = v3;
  gGrabPIXCapture = 1;
}

// File Line: 233
// RVA: 0x4E4800
void __fastcall UFG::TSSmoketest::MthdC_collect_streaming_memory_info(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::StreamPool_DBGDumpAllPools((UFG *)pScope);
}

// File Line: 238
// RVA: 0x4E4810
void __fastcall UFG::TSSmoketest::MthdC_collect_summary_memory_info(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qPrintSummaryMemoryPools((UFG *)pScope);
}

// File Line: 243
// RVA: 0x4F2350
void __fastcall UFG::TSSmoketest::MthdC_start_ai_test(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  if ( result_pp )
    *result_pp = (SSInstance *)SSBoolean::pool_new(0);
}

// File Line: 250
// RVA: 0x4EC5E0
void __fastcall UFG::TSSmoketest::MthdC_retrieve_next_road_point(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  float *v3; // rdi
  float v4; // xmm6_4
  __int64 v5; // rax
  __int64 v6; // rax
  UFG::qOffset64<UFG::RoadNetworkConnection *> *v7; // rbx
  UFG::RoadNetworkConnection *v8; // rbx
  unsigned int v9; // eax
  UFG::RoadNetworkLane *v10; // rax
  __m128 v11; // xmm1
  float v12; // xmm0_4
  __m128 v13; // xmm1
  UFG::qVector3 *v14; // rbx
  UFG::allocator::free_link *v15; // rax
  float v16; // xmm1_4
  float v17; // xmm2_4
  UFG::qVector3 result; // [rsp+28h] [rbp-60h]

  v2 = ppResult;
  v3 = (float *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( UFG::TSSmoketest::mNeedNewConnection )
  {
    v4 = FLOAT_0_1;
    v5 = UFG::TSSmoketest::mCurrentRoadLane->mNextConnection.mOffset;
    if ( v5
      && (UFG::qOffset64<UFG::RoadNetworkConnection *> *)((char *)&UFG::TSSmoketest::mCurrentRoadLane->mNextConnection
                                                        + v5) )
    {
      v6 = UFG::TSSmoketest::mCurrentRoadLane->mNextConnection.mOffset;
      if ( v6 )
      {
        v7 = &UFG::TSSmoketest::mCurrentRoadLane->mNextConnection;
LABEL_8:
        v8 = (UFG::RoadNetworkConnection *)((char *)v7 + v6);
LABEL_10:
        v9 = UFG::qRandom(v8->mNumLanes, &UFG::qDefaultSeed);
        v10 = UFG::qBezierPathCollectionMemImaged::GetPath(v8, v9);
        UFG::TSSmoketest::mCurrentRoadLane = v10;
        goto LABEL_12;
      }
    }
    else
    {
      v6 = UFG::TSSmoketest::mCurrentRoadLane->mStartConnection.mOffset;
      if ( v6 )
      {
        v7 = &UFG::TSSmoketest::mCurrentRoadLane->mStartConnection;
        goto LABEL_8;
      }
    }
    v8 = 0i64;
    goto LABEL_10;
  }
  v4 = UFG::TSSmoketest::mLastPosPercentage;
  v10 = UFG::TSSmoketest::mCurrentRoadLane;
LABEL_12:
  UFG::RoadNetworkLane::GetPos(v10, &result, v4);
  v11 = (__m128)LODWORD(result.x);
  v11.m128_f32[0] = (float)((float)((float)(result.x - *v3) * (float)(result.x - *v3))
                          + (float)((float)(result.y - v3[1]) * (float)(result.y - v3[1])))
                  + (float)((float)(result.z - v3[2]) * (float)(result.z - v3[2]));
  LODWORD(v12) = (unsigned __int128)_mm_sqrt_ps(v11);
  if ( v4 >= 1.0 )
  {
LABEL_17:
    v4 = *(float *)&FLOAT_1_0;
    UFG::TSSmoketest::mNeedNewConnection = 1;
    UFG::TSSmoketest::mLastPosPercentage = 0.0;
  }
  else
  {
    while ( v12 <= 50.0 )
    {
      v4 = v4 + 0.1;
      UFG::RoadNetworkLane::GetPos(UFG::TSSmoketest::mCurrentRoadLane, &result, v4);
      v13 = (__m128)LODWORD(result.x);
      v13.m128_f32[0] = (float)((float)((float)(result.x - *v3) * (float)(result.x - *v3))
                              + (float)((float)(result.y - v3[1]) * (float)(result.y - v3[1])))
                      + (float)((float)(result.z - v3[2]) * (float)(result.z - v3[2]));
      LODWORD(v12) = (unsigned __int128)_mm_sqrt_ps(v13);
      if ( v4 >= 1.0 )
        goto LABEL_17;
    }
    UFG::TSSmoketest::mLastPosPercentage = v4;
    UFG::TSSmoketest::mNeedNewConnection = 0;
  }
  v14 = UFG::RoadNetworkLane::GetPos(UFG::TSSmoketest::mCurrentRoadLane, &result, v4);
  v15 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v15 )
  {
    v16 = v14->y;
    v17 = v14->z;
    *(float *)&v15->mNext = v14->x;
    *((float *)&v15->mNext + 1) = v16;
    *(float *)&v15[1].mNext = v17;
  }
  *v2 = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v15);
}

// File Line: 294
// RVA: 0x4E8D50
void __fastcall UFG::TSSmoketest::MthdC_has_finished_path_to(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  SSActor *v3; // rbx
  SSClass *v4; // rdi
  bool v5; // al

  v2 = ppResult;
  v3 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v3 )
    goto LABEL_6;
  v4 = v3->i_class_p;
  if ( !v4->vfptr->is_actor_class((SSClassDescBase *)&v4->vfptr) )
  {
    if ( v4 == SSBrain::c_symbol_class_p && LODWORD(v3->i_user_data) != -1 )
    {
      v3 = SSActor::find((ASymbol *)&v3->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    v3 = 0i64;
  }
LABEL_7:
  v5 = UFG::TSCharacter::IsAtTarget((UFG::TSCharacter *)v3);
  *v2 = (SSInstance *)SSBoolean::pool_new(v5);
}

// File Line: 308
// RVA: 0x4E6D60
void __fastcall UFG::TSSmoketest::MthdC_force_progress(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::qBaseTreeRB *v3; // rbx
  UFG::ProgressionTracker *v4; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

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
  UFG::qSymbol result; // [rsp+40h] [rbp+18h]

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
  AStringRef *v2; // rbx
  bool v3; // zf
  AObjReusePool<AStringRef> *v4; // rax
  AObjBlock<AStringRef> *v5; // rcx
  unsigned __int64 v6; // r8
  bool v7; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v8; // rcx

  v2 = (AStringRef *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  ++v2->i_ref_count;
  UFG::ProfileWizard::sProfileCaptureFrames = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64)
                                                        + 32i64);
  UFG::ProfileWizard::sProfileIntoDB = 1;
  v3 = v2->i_ref_count-- == 1;
  if ( v3 )
  {
    if ( v2->i_deallocate )
      AMemory::c_free_func(v2->i_cstr_p);
    v4 = AStringRef::get_pool();
    v5 = v4->i_block_p;
    v6 = (unsigned __int64)v5->i_objects_a;
    if ( (unsigned __int64)v2 < v6 || (v7 = (unsigned __int64)v2 < v6 + 24i64 * v5->i_size, v8 = &v4->i_pool, !v7) )
      v8 = &v4->i_exp_pool;
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v8, v2);
  }
}

// File Line: 353
// RVA: 0x4E9240
void __fastcall UFG::TSSmoketest::MthdC_initialize_census(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  AMD_HD3D *v2; // rax

  v2 = (AMD_HD3D *)UFG::CensusHelper::GetInstance();
  _(v2);
}

// File Line: 358
// RVA: 0x4EC570
void __fastcall UFG::TSSmoketest::MthdC_retrieve_next_census_point(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  UFG::qString *v3; // rax
  UFG::qString *v4; // rbx
  UFG::CensusHelper *v5; // rcx
  UFG::qVector3 *v6; // rax
  char v7; // [rsp+28h] [rbp-40h]
  UFG::qString v8; // [rsp+38h] [rbp-30h]

  if ( ppResult )
  {
    v2 = ppResult;
    UFG::qString::qString(&v8, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v4 = v3;
    v5 = UFG::CensusHelper::GetInstance();
    v6 = UFG::CensusHelper::RetrieveNextVector(v5, (UFG::qVector3 *)&v7, v4);
    *v2 = UFG::TSVector3::AsInstance(v6);
  }
}

// File Line: 370
// RVA: 0x4E47D0
void __fastcall UFG::TSSmoketest::MthdC_collect_census_stats(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  AMD_HD3D *v2; // rax

  v2 = (AMD_HD3D *)UFG::CensusHelper::GetInstance();
  _(v2);
}

// File Line: 376
// RVA: 0x4D64B0
void UFG::TSSmoketest::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Smoketest");
  SSClass::register_method_func(v0, "press_button", UFG::TSSmoketest::MthdC_press_button, 1, 0);
  SSClass::register_method_func(v0, "toggle_controller", UFG::TSSmoketest::MthdC_toggle_controller, 1, 0);
  SSClass::register_method_func(v0, "press_trigger", UFG::TSSmoketest::MthdC_press_trigger, 1, 0);
  SSClass::register_method_func(v0, "clear_all_input", UFG::TSSmoketest::MthdC_clear_all_input, 1, 0);
  SSClass::register_method_func(v0, "cancel_input", UFG::TSSmoketest::MthdC_cancel_input, 1, 0);
  SSClass::register_method_func(v0, "move_analog_stick", UFG::TSSmoketest::MthdC_move_analog_stick, 1, 0);
  SSClass::register_method_func(v0, "start_auto_smoke", UFG::TSSmoketest::MthdC_start_auto_smoke, 1, 0);
  SSClass::register_method_func(v0, "start_NIS_test", UFG::TSSmoketest::MthdC_start_NIS_test, 1, 0);
  SSClass::register_method_func(v0, "start_soak_test", UFG::TSSmoketest::MthdC_start_soak_test, 1, 0);
  SSClass::register_method_func(v0, "start_ai_test", UFG::TSSmoketest::MthdC_start_ai_test, 1, 0);
  SSClass::register_method_func(v0, "collect_memory_info", UFG::TSSmoketest::MthdC_collect_memory_info, 1, 0);
  SSClass::register_method_func(
    v0,
    "collect_summary_memory_info",
    UFG::TSSmoketest::MthdC_collect_summary_memory_info,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "collect_streaming_memory_info",
    UFG::TSSmoketest::MthdC_collect_streaming_memory_info,
    1,
    0);
  SSClass::register_method_func(v0, "begin_profile_capture", UFG::TSSmoketest::MthdC_begin_profile_capture, 1, 0);
  SSClass::register_method_func(v0, "start_profile_test", UFG::TSSmoketest::MthdC_start_profile_test, 1, 0);
  SSClass::register_method_func(v0, "begin_pix_capture", UFG::TSSmoketest::MthdC_begin_PIX_capture, 1, 0);
  SSClass::register_method_func(v0, "start_auto_pix_capture", UFG::TSSmoketest::MthdC_start_auto_PIX_capture, 1, 0);
  SSClass::register_method_func(
    v0,
    "signal_test_complete",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    0);
  SSClass::register_method_func(v0, "start_benchmark_timing", UFG::TSSmoketest::MthdC_start_benchmark_timing, 1, 0);
  SSClass::register_method_func(v0, "stop_benchmark_timing", UFG::TSSmoketest::MthdC_stop_benchmark_timing, 1, 0);
  SSClass::register_method_func(v0, "pause_benchmark_timing", UFG::TSSmoketest::MthdC_pause_benchmark_timing, 1, 0);
  SSClass::register_method_func(v0, "resume_benchmark_timing", UFG::TSSmoketest::MthdC_resume_benchmark_timing, 1, 0);
  SSClass::register_method_func(v0, "write_benchmark_timing", UFG::TSSmoketest::MthdC_write_benchmark_timing, 1, 0);
  SSClass::register_method_func(v0, "has_finished_path_to", UFG::TSSmoketest::MthdC_has_finished_path_to, 1, 0);
  SSClass::register_method_func(v0, "retrieve_next_road_point", UFG::TSSmoketest::MthdC_retrieve_next_road_point, 1, 0);
  SSClass::register_method_func(
    v0,
    "initialize_ai_test",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    0);
  SSClass::register_method_func(v0, "force_progress", UFG::TSSmoketest::MthdC_force_progress, 1, 0);
  SSClass::register_method_func(v0, "begin_preset_gameslice", UFG::TSSmoketest::MthdC_begin_preset_gameslice, 1, 0);
  SSClass::register_method_func(v0, "start_census_test", UFG::TSSmoketest::MthdC_start_census_test, 1, 0);
  SSClass::register_method_func(v0, "initialize_census", UFG::TSSmoketest::MthdC_initialize_census, 1, 0);
  SSClass::register_method_func(
    v0,
    "retrieve_next_census_point",
    UFG::TSSmoketest::MthdC_retrieve_next_census_point,
    1,
    0);
  SSClass::register_method_func(v0, "reset_census_stats", UFG::TSSmoketest::MthdC_collect_census_stats, 1, 0);
  SSClass::register_method_func(v0, "collect_census_stats", UFG::TSSmoketest::MthdC_collect_census_stats, 1, 0);
}

