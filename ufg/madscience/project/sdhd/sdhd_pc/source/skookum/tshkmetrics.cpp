// File Line: 89
// RVA: 0x4EEED0
void __fastcall UFG::TSHKMetrics::MthdC_set_session_id(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HKMetrics::SetSessionID(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 96
// RVA: 0x4EEE40
void __fastcall UFG::TSHKMetrics::MthdC_set_sequence_id(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HKMetrics::SetSequenceID(*(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 103
// RVA: 0x4EEEB0
void __fastcall UFG::TSHKMetrics::MthdC_set_sequence_time(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HKMetrics::SetSequenceTime(*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 110
// RVA: 0x4E88F0
void __fastcall UFG::TSHKMetrics::MthdC_get_sequence_position(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qVector3 *SequencePos; // rbx
  UFG::allocator::free_link *v4; // rax
  float y; // xmm1_4
  float z; // xmm2_4

  SequencePos = UFG::HKMetrics::GetSequencePos();
  v4 = UFG::qMalloc(0xCui64, "Skookum.qVector3", 0i64);
  if ( v4 )
  {
    y = SequencePos->y;
    z = SequencePos->z;
    *(float *)&v4->mNext = SequencePos->x;
    *((float *)&v4->mNext + 1) = y;
    *(float *)&v4[1].mNext = z;
  }
  *ppResult = SSInstance::pool_new(UFG::SkookumMgr::mspVector3Class, (unsigned __int64)v4);
}

// File Line: 116
// RVA: 0x4EEE60
void __fastcall UFG::TSHKMetrics::MthdC_set_sequence_position(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rcx
  SSData *v4; // rax
  float v5; // xmm0_4
  SSInstance *v6; // rcx
  UFG::qVector3 position; // [rsp+20h] [rbp-18h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = i_array_p[1]->i_data_p;
  v4 = i_array_p[2];
  position.x = *(float *)&(*i_array_p)->i_data_p->i_user_data;
  v5 = *(float *)&i_data_p->i_user_data;
  v6 = v4->i_data_p;
  position.y = v5;
  position.z = *(float *)&v6->i_user_data;
  UFG::HKMetrics::SetSequencePos(&position);
}

// File Line: 125
// RVA: 0x4E42A0
// attributes: thunk
void __fastcall UFG::TSHKMetrics::MthdC_capture_perf_metrics(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HKMetrics::LogPerfStats((UFG::HKMetrics *)pScope);
}

// File Line: 130
// RVA: 0x4E4290
void __fastcall UFG::TSHKMetrics::MthdC_capture_memory_summary_metrics(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HKMetrics::LogMemStats(MEM_LOG_DETAIL_SUMMARY);
}

// File Line: 135
// RVA: 0x4E42B0
void __fastcall UFG::TSHKMetrics::MthdC_capture_summary_metrics(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HKMetrics::LogPerfStats((UFG::HKMetrics *)pScope);
  UFG::HKMetrics::LogMemStats(MEM_LOG_DETAIL_SUMMARY);
}

// File Line: 141
// RVA: 0x4D3A50
void UFG::TSHKMetrics::BindAtomics(void)
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

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("HKMetrics");
  SSClass::register_method_func(
    v0,
    "prepare_for_census",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "set_session_id", UFG::TSHKMetrics::MthdC_set_session_id, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "set_sequence_id", UFG::TSHKMetrics::MthdC_set_sequence_id, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "set_sequence_time", UFG::TSHKMetrics::MthdC_set_sequence_time, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "set_sequence_position", UFG::TSHKMetrics::MthdC_set_sequence_position, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v0, "get_sequence_position", UFG::TSHKMetrics::MthdC_get_sequence_position, 1, rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(v0, "capture_perf_metrics", UFG::TSHKMetrics::MthdC_capture_perf_metrics, 1, rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "capture_memory_summary_metrics",
    UFG::TSHKMetrics::MthdC_capture_memory_summary_metrics,
    1,
    rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "capture_summary_metrics",
    UFG::TSHKMetrics::MthdC_capture_summary_metrics,
    1,
    rebindh);
}

