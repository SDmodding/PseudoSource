// File Line: 375
// RVA: 0x14FF770
__int64 dynamic_initializer_for__gCurrentLocationDirectory__()
{
  UFG::qString::qString(&gCurrentLocationDirectory);
  return atexit(dynamic_atexit_destructor_for__gCurrentLocationDirectory__);
}

// File Line: 376
// RVA: 0x14FF6C0
__int64 dynamic_initializer_for__currVehicle__()
{
  UFG::qString::qString(&currVehicle);
  return atexit(dynamic_atexit_destructor_for__currVehicle__);
}

// File Line: 396
// RVA: 0x14FF960
__int64 dynamic_initializer_for__gPIXCaptureFileName__()
{
  UFG::qString::qString(&gPIXCaptureFileName, "e:\\test.pix2");
  return atexit(dynamic_atexit_destructor_for__gPIXCaptureFileName__);
}

// File Line: 399
// RVA: 0x14FFA70
__int64 dynamic_initializer_for__gUserName__()
{
  UFG::qString::qString(&gUserName);
  return atexit(dynamic_atexit_destructor_for__gUserName__);
}

// File Line: 400
// RVA: 0x14FF920
__int64 dynamic_initializer_for__gLoginPassword__()
{
  UFG::qString::qString(&gLoginPassword);
  return atexit(dynamic_atexit_destructor_for__gLoginPassword__);
}

// File Line: 401
// RVA: 0x14FF9F0
__int64 dynamic_initializer_for__gSessionId__()
{
  UFG::qString::qString(&gSessionId);
  return atexit(dynamic_atexit_destructor_for__gSessionId__);
}

// File Line: 402
// RVA: 0x14FF9B0
__int64 dynamic_initializer_for__gProxyCredentials__()
{
  UFG::qString::qString(&gProxyCredentials);
  return atexit(dynamic_atexit_destructor_for__gProxyCredentials__);
}

// File Line: 403
// RVA: 0x14FF790
__int64 dynamic_initializer_for__gEnvironmentURL__()
{
  UFG::qString::qString(&gEnvironmentURL);
  return atexit(dynamic_atexit_destructor_for__gEnvironmentURL__);
}

// File Line: 431
// RVA: 0x14FF7B0
__int64 UFG::_dynamic_initializer_for__gFlowController__()
{
  UFG::FlowController::FlowController(&UFG::gFlowController);
  return atexit(UFG::_dynamic_atexit_destructor_for__gFlowController__);
}

// File Line: 435
// RVA: 0x426A10
void __fastcall UFG::qUserCallback_WaitForGPU(UFG *this)
{
  if ( Illusion::gEngine.FrameMemory )
    Illusion::IEnginePlat::WaitUntilGPUDone((Illusion::IEnginePlat *)&Illusion::gEngine);
}

// File Line: 452
// RVA: 0x14FF9D0
__int64 dynamic_initializer_for__gScaleformMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gScaleformMemoryPool);
  return atexit(dynamic_atexit_destructor_for__gScaleformMemoryPool__);
}

// File Line: 457
// RVA: 0x14FF940
__int64 dynamic_initializer_for__gNetworkMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gNetworkMemoryPool);
  return atexit(dynamic_atexit_destructor_for__gNetworkMemoryPool__);
}

// File Line: 458
// RVA: 0x14FF6E0
__int64 dynamic_initializer_for__gActionTreeMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool((UFG::qMemoryPool *)&gActionTreeMemoryPool.mPrev);
  return atexit(dynamic_atexit_destructor_for__gActionTreeMemoryPool__);
}

// File Line: 459
// RVA: 0x14FF990
__int64 dynamic_initializer_for__gPropertySetMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gPropertySetMemoryPool);
  return atexit(dynamic_atexit_destructor_for__gPropertySetMemoryPool__);
}

// File Line: 460
// RVA: 0x14FFA30
__int64 dynamic_initializer_for__gSkookumMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gSkookumMemoryPool);
  return atexit(dynamic_atexit_destructor_for__gSkookumMemoryPool__);
}

// File Line: 461
// RVA: 0x14FFA10
__int64 dynamic_initializer_for__gSimulationMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gSimulationMemoryPool);
  return atexit(dynamic_atexit_destructor_for__gSimulationMemoryPool__);
}

// File Line: 476
// RVA: 0x14FF7D0
__int64 dynamic_initializer_for__gHKGlobalStreams__()
{
  HKGlobalStreams::HKGlobalStreams(&gHKGlobalStreams);
  return atexit(dynamic_atexit_destructor_for__gHKGlobalStreams__);
}

// File Line: 477
// RVA: 0x14FF7F0
__int64 dynamic_initializer_for__gHKLocationStreams__()
{
  unk_14207EE10 = 0i64;
  unk_14207EE18 = 0i64;
  unk_14207EE20 = 0i64;
  unk_14207EE28 = 536870915;
  unk_14207EE2C = 1;
  stru_14207EE30.mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&stru_14207EE30;
  stru_14207EE30.mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&stru_14207EE30;
  stru_14207EE30.mCallback = 0i64;
  stru_14207EE30.mCallbackParam = 0i64;
  stru_14207EE30.mImpl = 0i64;
  *(_DWORD *)&stru_14207EE30.mFlags = 536870915;
  stru_14207EE30._mTargetState.mValue = 1;
  stru_14207EE60.mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&stru_14207EE60;
  stru_14207EE60.mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&stru_14207EE60;
  stru_14207EE60.mCallback = 0i64;
  stru_14207EE60.mCallbackParam = 0i64;
  stru_14207EE60.mImpl = 0i64;
  *(_DWORD *)&stru_14207EE60.mFlags = 536870915;
  stru_14207EE60._mTargetState.mValue = 1;
  unk_14207EE98 = 0i64;
  *(_QWORD *)&dword_14207EE90 = 0i64;
  return atexit(dynamic_atexit_destructor_for__gHKLocationStreams__);
}

// File Line: 487
// RVA: 0x14FFA90
__int64 dynamic_initializer_for__gpc_PC_VRamMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gpc_PC_VRamMemoryPool);
  return atexit(dynamic_atexit_destructor_for__gpc_PC_VRamMemoryPool__);
}

// File Line: 542
// RVA: 0x426590
__int64 __fastcall UFG::AgogErrorOutput::determine_choice(UFG::AgogErrorOutput *this, AErrMsg *msg, eAErrAction *pAction)
{
  eAErrAction *v3; // r12
  AErrMsg *v4; // rbx
  const char *v5; // r15
  const char *v6; // rdi
  const char *v7; // rbp
  char *v8; // r8
  char *v9; // r9
  const char *v10; // rcx
  signed int v11; // esi
  unsigned __int8 v12; // r14
  signed __int64 v13; // rbx
  unsigned int v14; // eax
  AStringRef *v15; // rbx
  bool v16; // zf
  AObjReusePool<AStringRef> *v17; // rax
  AObjReusePool<AStringRef> *v18; // r8
  AObjBlock<AStringRef> *v19; // rax
  unsigned __int64 v20; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v21; // rcx
  AStringRef *v22; // rdx
  unsigned int v23; // ebx
  AStringRef *v24; // rax
  unsigned int v25; // ebp
  int v26; // eax
  AStringRef *v27; // rbx
  AObjReusePool<AStringRef> *v28; // rax
  AObjReusePool<AStringRef> *v29; // r8
  AObjBlock<AStringRef> *v30; // rax
  unsigned __int64 v31; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v32; // rcx
  AStringRef *v33; // rbx
  AObjReusePool<AStringRef> *v34; // rax
  AObjBlock<AStringRef> *v35; // rcx
  unsigned __int64 v36; // rdx
  bool v37; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v38; // rcx
  __int64 deallocate; // [rsp+20h] [rbp-868h]
  __int64 v41; // [rsp+30h] [rbp-858h]
  char buffer_p; // [rsp+50h] [rbp-838h]
  AString str; // [rsp+898h] [rbp+10h]
  AString result; // [rsp+8A0h] [rbp+18h]
  AString v45; // [rsp+8A8h] [rbp+20h]

  v3 = pAction;
  v4 = msg;
  v5 = 0i64;
  if ( msg->i_err_level )
  {
    v6 = "Error";
    v5 = "\n"
         "Choose:\n"
         "  'Abort'  - break into C++ & get callstack [then ignore on continue]\n"
         "  'Retry'  - attempt recovery/ignore [still tests this assert in future]\n"
         "  'Ignore' - recover/ignore always [auto-ignores this assert in future]";
  }
  else
  {
    v6 = "Internal recoverable exception";
  }
  if ( msg->i_title_p )
    v6 = msg->i_title_p;
  AString::AString(&str, &buffer_p, 0x800u, 0, 0);
  v7 = "An error has occurred.";
  if ( v4->i_desc_high_p )
    v7 = v4->i_desc_high_p;
  v8 = &customWorldMapCaption;
  v9 = &customWorldMapCaption;
  if ( v4->i_desc_low_p )
    v9 = (char *)v4->i_desc_low_p;
  if ( v4->i_func_name_p )
    v8 = (char *)v4->i_func_name_p;
  v10 = v4->i_source_path_p;
  if ( v10 )
  {
    LODWORD(v41) = v4->i_err_id;
    LODWORD(deallocate) = v4->i_source_line;
    AString::format(&str, "\n\n  C++ Internal Info:\n    %s\n    %s(%u) :\n    %s\n", v8, v10, deallocate, v9, v41);
  }
  else
  {
    LODWORD(deallocate) = v4->i_err_id;
    AString::format(&str, "\n\n  C++ Internal Info:\n    %s\n    %s\n", v8, v9, deallocate);
  }
  ADebug::context_string(&result);
  ADebug::print_format("\n###%s : ", v6);
  ADebug::print(v7, 1);
  ADebug::print(&str, 1);
  ADebug::print(&result, 1);
  v11 = 3;
  v12 = 0;
  if ( v5 )
  {
    if ( UFG::gAutoSmoketest )
      goto LABEL_53;
    v13 = -1i64;
    do
      ++v13;
    while ( v7[v13] );
    v14 = AMemory::c_req_byte_size_func(v13 + 1);
    v45.i_str_ref_p = AStringRef::pool_new(v7, v13, v14, 1u, 0, 1);
    AString::insert(&str, &v45, 0);
    v15 = v45.i_str_ref_p;
    v16 = v45.i_str_ref_p->i_ref_count == 1;
    --v15->i_ref_count;
    if ( v16 )
    {
      if ( v15->i_deallocate )
        AMemory::c_free_func(v15->i_cstr_p);
      v17 = AStringRef::get_pool();
      v18 = v17;
      v19 = v17->i_block_p;
      v20 = (unsigned __int64)v19->i_objects_a;
      if ( (unsigned __int64)v15 < v20 || (v21 = &v18->i_pool, (unsigned __int64)v15 >= v20 + 24i64 * v19->i_size) )
        v21 = &v18->i_exp_pool;
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v21, v15);
    }
    v22 = result.i_str_ref_p;
    v23 = result.i_str_ref_p->i_length;
    if ( v23 )
    {
      v24 = str.i_str_ref_p;
      v25 = v23 + str.i_str_ref_p->i_length;
      if ( v25 >= str.i_str_ref_p->i_size || str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&str, v25);
        v24 = str.i_str_ref_p;
        v22 = result.i_str_ref_p;
      }
      memmove(&v24->i_cstr_p[v24->i_length], v22->i_cstr_p, v23 + 1);
      str.i_str_ref_p->i_length = v25;
    }
    AString::append(&str, v5, 0xFFFFFFFF);
    v26 = MessageBoxA(0i64, str.i_str_ref_p->i_cstr_p, v6, 0x10032u);
    if ( v26 == 3 )
    {
LABEL_53:
      v12 = 1;
    }
    else if ( v26 != 4 && v26 == 5 )
    {
      v11 = 4;
    }
  }
  *v3 = v11;
  v27 = result.i_str_ref_p;
  v16 = result.i_str_ref_p->i_ref_count == 1;
  --v27->i_ref_count;
  if ( v16 )
  {
    if ( v27->i_deallocate )
      AMemory::c_free_func(v27->i_cstr_p);
    v28 = AStringRef::get_pool();
    v29 = v28;
    v30 = v28->i_block_p;
    v31 = (unsigned __int64)v30->i_objects_a;
    if ( (unsigned __int64)v27 < v31 || (v32 = &v29->i_pool, (unsigned __int64)v27 >= v31 + 24i64 * v30->i_size) )
      v32 = &v29->i_exp_pool;
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v32, v27);
  }
  v33 = str.i_str_ref_p;
  v16 = str.i_str_ref_p->i_ref_count == 1;
  --v33->i_ref_count;
  if ( v16 )
  {
    if ( v33->i_deallocate )
      AMemory::c_free_func(v33->i_cstr_p);
    v34 = AStringRef::get_pool();
    v35 = v34->i_block_p;
    v36 = (unsigned __int64)v35->i_objects_a;
    if ( (unsigned __int64)v33 < v36
      || (v37 = (unsigned __int64)v33 < v36 + 24i64 * v35->i_size, v38 = &v34->i_pool, !v37) )
    {
      v38 = &v34->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v38, v33);
  }
  return v12;
}

// File Line: 644
// RVA: 0x426910
AgogCoreVals *__fastcall Agog::get_agog_core_vals()
{
  AgogCoreVals *result; // rax

  if ( !(_S7_10 & 1) )
  {
    _S7_10 |= 1u;
    AgogCoreVals::AgogCoreVals(&s_values);
  }
  result = &s_values;
  if ( s_values.i_using_defaults )
  {
    s_values.i_pool_init_string_ref = 18000;
    s_values.i_pool_incr_string_ref = 256;
    s_values.i_using_defaults = 0;
  }
  return result;
}

// File Line: 691
// RVA: 0x426970
UFG::AgogErrorOutput *__fastcall Agog::on_error_pre(bool nested)
{
  if ( !(_S8_10 & 1) )
  {
    _S8_10 |= 1u;
    s_simple_err_out.vfptr = (AErrorOutputBaseVtbl *)&UFG::AgogErrorOutput::`vftable';
    atexit(Agog::on_error_pre_::_2_::_dynamic_atexit_destructor_for__s_simple_err_out__);
  }
  return &s_simple_err_out;
}

// File Line: 743
// RVA: 0x14FF710
__int64 dynamic_initializer_for__gAssertContextFuncs__()
{
  return atexit(dynamic_atexit_destructor_for__gAssertContextFuncs__);
}

// File Line: 797
// RVA: 0x421130
__int64 HKAssertHandler(const char *pConditionCStr, const char *pFileCStr, __int64 line, bool *pIgnoreAlways, const char *pMsgCStr, ...)
{
  bool *v5; // r14
  int v6; // er12
  const char *v7; // r13
  const char *v8; // rsi
  unsigned int v9; // edi
  int v10; // er15
  fastdelegate::FastDelegate<bool __cdecl(UFG::qString *)> *v11; // rbx
  fastdelegate::FastDelegate<bool __cdecl(UFG::qString *)> *v12; // rsi
  unsigned __int64 v13; // rdx
  signed __int64 v14; // rcx
  signed __int64 v15; // rcx
  void *v16; // rsp
  void *v17; // rsp
  int v18; // eax
  int v19; // eax
  __int64 v21; // [rsp+20h] [rbp-20h]
  UFG::qString v22; // [rsp+40h] [rbp+0h]
  __int64 v23; // [rsp+68h] [rbp+28h]
  char dest; // [rsp+70h] [rbp+30h]
  const char *v25; // [rsp+8C0h] [rbp+880h]
  va_list va; // [rsp+8E8h] [rbp+8A8h]

  va_start(va, pMsgCStr);
  v25 = pConditionCStr;
  v23 = -2i64;
  v5 = pIgnoreAlways;
  v6 = line;
  v7 = pFileCStr;
  v8 = pConditionCStr;
  UFG::qPrintf(
    "\n"
    "\n"
    "*********************************\n"
    "********** ASSERT FAIL **********\n"
    "*********************************\n"
    "%s(%d):\n"
    "CONDITION = %s\n",
    pFileCStr,
    line,
    pConditionCStr);
  v9 = 0;
  v10 = 0;
  dest = 0;
  if ( pMsgCStr )
    v10 = UFG::qVSPrintf(&dest, 2048, pMsgCStr, va);
  UFG::qString::qString(&v22);
  if ( gAssertContextFuncs.size )
  {
    v11 = gAssertContextFuncs.p;
    v12 = &gAssertContextFuncs.p[gAssertContextFuncs.size];
    if ( gAssertContextFuncs.p < v12 )
    {
      do
      {
        ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::qString *))v11->m_Closure.m_pFunction)(
          v11->m_Closure.m_pthis,
          &v22);
        ++v11;
      }
      while ( v11 < v12 );
    }
    v8 = v25;
  }
  if ( !v5 || UFG::gAutoSmoketest )
    goto LABEL_15;
  v13 = (unsigned int)(v10 + v22.mLength + 512);
  v14 = v13 + 15;
  if ( v13 + 15 <= v13 )
    v14 = 1152921504606846960i64;
  v15 = v14 & 0xFFFFFFFFFFFFFFF0ui64;
  v16 = alloca(v15);
  v17 = alloca(v15);
  LODWORD(v21) = v6;
  UFG::qSPrintf(
    (char *)&v22,
    v13,
    "Data Assert Failed!\nFile      :   %s\nLine      :   %d\nCondition :  %s\nMessage   :  %s\n%s\n",
    v7,
    v21,
    v8,
    &dest,
    v22.mData);
  v18 = MessageBoxA(0i64, (LPCSTR)&v22, "Assert Failed!", 0x12032u) - 3;
  if ( !v18 )
    goto LABEL_15;
  v19 = v18 - 1;
  if ( v19 )
  {
    if ( v19 == 1 )
    {
      *v5 = 1;
      goto LABEL_16;
    }
LABEL_15:
    v9 = 1;
  }
LABEL_16:
  UFG::qString::~qString(&v22);
  return v9;
}

// File Line: 880
// RVA: 0x426320
__int64 __fastcall SkookumExtraContext(UFG::qString *pStr)
{
  UFG::qString *v1; // rbx
  unsigned __int8 v2; // di
  AStringRef *v3; // rbx
  bool v4; // zf
  AObjReusePool<AStringRef> *v5; // rax
  AObjBlock<AStringRef> *v6; // rcx
  unsigned __int64 v7; // rdx
  bool v8; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v9; // rcx
  AString str_p; // [rsp+48h] [rbp+10h]

  v1 = pStr;
  str_p.i_str_ref_p = AStringRef::get_empty();
  ++str_p.i_str_ref_p->i_ref_count;
  if ( ADebug::context_append(&str_p) )
  {
    UFG::qString::append(v1, str_p.i_str_ref_p->i_cstr_p, str_p.i_str_ref_p->i_length);
    v2 = 1;
  }
  else
  {
    v2 = 0;
  }
  v3 = str_p.i_str_ref_p;
  v4 = str_p.i_str_ref_p->i_ref_count == 1;
  --v3->i_ref_count;
  if ( v4 )
  {
    if ( v3->i_deallocate )
      AMemory::c_free_func(v3->i_cstr_p);
    v5 = AStringRef::get_pool();
    v6 = v5->i_block_p;
    v7 = (unsigned __int64)v6->i_objects_a;
    if ( (unsigned __int64)v3 < v7 || (v8 = (unsigned __int64)v3 < v7 + 24i64 * v6->i_size, v9 = &v5->i_pool, !v8) )
      v9 = &v5->i_exp_pool;
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v9, v3);
  }
  return v2;
}

// File Line: 896
// RVA: 0x426530
char __fastcall WaitForStreamer(UFG *a1)
{
  while ( 1 )
  {
    UFG::qFileService(a1);
    UFG::DataStreamer::Service(0.033333335);
    Render::StreamingLoopProcessQueuedOperations(1, 0);
    if ( UFG::DataStreamer::IsStalled(0i64, 0) )
      break;
    if ( !UFG::DataStreamer::IsBusy(0i64, 0) )
      return 1;
  }
  return 0;
}

// File Line: 925
// RVA: 0x424D70
UFG::allocator::free_link *__fastcall LoadTexturePackHK(const char *perm_filename, UFG::StreamingMemory::DATA_TYPE eDataType)
{
  UFG::StreamingMemory::DATA_TYPE v2; // ebp
  const char *v3; // r14
  UFG::allocator::free_link *v4; // rsi
  unsigned int v5; // ebx
  unsigned int v6; // edi
  __int64 v7; // r15
  unsigned int v8; // ebp
  unsigned __int64 v9; // rax
  UFG::allocator::free_link *v10; // r14
  char *v11; // rdx

  v2 = eDataType;
  v3 = perm_filename;
  v4 = UFG::qMalloc(0x30ui64, "DataStreamer::Handle", 0i64);
  v5 = 1;
  if ( v4 )
  {
    v4->mNext = v4;
    v4[1].mNext = v4;
    v6 = 0;
    v4[2].mNext = 0i64;
    v4[3].mNext = 0i64;
    v4[4].mNext = 0i64;
    LODWORD(v4[5].mNext) = 536870915;
    WORD2(v4[5].mNext) = 1;
  }
  else
  {
    v6 = 0;
    v4 = 0i64;
  }
  UFG::DataStreamer::QueueStream((UFG::DataStreamer::Handle *)v4, v3, v2, DEFAULT_PRIORITY, 3u, 0i64, 0i64);
  v7 = dword_14207EE90;
  v8 = dword_14207EE90 + 1;
  if ( dword_14207EE90 + 1 <= unk_14207EE94 )
    goto LABEL_25;
  if ( unk_14207EE94 )
    v5 = 2 * unk_14207EE94;
  for ( ; v5 < v8; v5 *= 2 )
    ;
  if ( v5 <= 2 )
    v5 = 2;
  if ( v5 - v8 > 0x10000 )
    v5 = dword_14207EE90 + 65537;
  if ( v5 == (_DWORD)v7 )
  {
LABEL_25:
    v10 = (UFG::allocator::free_link *)unk_14207EE98;
  }
  else
  {
    v9 = 8i64 * v5;
    if ( !is_mul_ok(v5, 8ui64) )
      v9 = -1i64;
    v10 = UFG::qMalloc(v9, "qArray.Add", 0i64);
    v11 = (char *)unk_14207EE98;
    if ( unk_14207EE98 )
    {
      if ( dword_14207EE90 )
      {
        do
        {
          v10[v6] = *(UFG::allocator::free_link *)&v11[8 * v6];
          ++v6;
          v11 = (char *)unk_14207EE98;
        }
        while ( v6 < dword_14207EE90 );
      }
      operator delete[](v11);
    }
    unk_14207EE98 = v10;
    unk_14207EE94 = v5;
  }
  dword_14207EE90 = v8;
  v10[v7].mNext = v4;
  return v4;
}

// File Line: 964
// RVA: 0x424680
void __fastcall LoadGlobalBins(UFG::qString *dataDir)
{
  UFG::qString *v1; // rdi
  UFG::qString *v2; // rax
  UFG::qString *v3; // rax
  UFG::qString *v4; // rax
  UFG::qString *v5; // rax
  char *v6; // rbx
  UFG::UIScreenTextureManager *v7; // rax
  char *v8; // rbx
  UFG::UIScreenTextureManager *v9; // rax
  char *v10; // rbx
  UFG::UIScreenTextureManager *v11; // rax
  UFG::PartDatabase *v12; // rax
  UFG *v13; // rcx
  UFG::qString *v14; // rax
  UFG::qString *v15; // rax
  UFG::qString *v16; // rax
  UFG::qString *v17; // rax
  UFG::qString *v18; // rax
  UFG::qString *v19; // rax
  UFG::qString *v20; // rax
  UFG::qString *v21; // rax
  UFG::qString *v22; // rax
  UFG::qString result; // [rsp+40h] [rbp-B8h]
  __int64 v24; // [rsp+68h] [rbp-90h]
  UFG::qString v25; // [rsp+70h] [rbp-88h]
  const char *v26; // [rsp+A8h] [rbp-50h]
  UFG::qString v27; // [rsp+B8h] [rbp-40h]
  UFG::qString v28; // [rsp+E0h] [rbp-18h]

  v24 = -2i64;
  v1 = dataDir;
  v2 = UFG::operator+(&result, dataDir, "\\Global\\StateBlocks.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v2->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v3 = UFG::operator+(&result, v1, "\\Global\\TexturePack.perm.bin");
  LoadTexturePackHK(v3->mData, DATA_GAME_GLOBAL_TEXTURES);
  UFG::qString::~qString(&result);
  _(0i64);
  v4 = UFG::operator+(&result, v1, "\\Global\\EffectsTexturePack.perm.bin");
  LoadTexturePackHK(v4->mData, DATA_GAME_GLOBAL_TEXTURES);
  UFG::qString::~qString(&result);
  _(0i64);
  v5 = UFG::operator+(&result, v1, "\\Global\\LightingTexturePack.perm.bin");
  LoadTexturePackHK(v5->mData, DATA_GAME_GLOBAL_TEXTURES);
  UFG::qString::~qString(&result);
  _(0i64);
  v6 = UFG::operator+(&result, v1, "\\UI\\global_win32_texturepack.perm.bin")->mData;
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(v7, v6, DEFAULT_PRIORITY, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v8 = UFG::operator+(&result, v1, "\\UI\\racecountdown_texturepack.perm.bin")->mData;
  v9 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(v9, v8, DEFAULT_PRIORITY, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v10 = UFG::operator+(&result, v1, "\\UI\\widgetarray_texturepack.perm.bin")->mData;
  v11 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(v11, v10, DEFAULT_PRIORITY, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  UFG::operator+((UFG::qString *)((char *)&v25 + 32), v1, "\\Vehicles_New\\dummyvehiclerig.perm.bin");
  if ( UFG::StreamFileWrapper::FileExists(v26) )
  {
    UFG::DataStreamer::QueueStream(&stru_1423EC590, v26, DATA_TRUECROWD_RESOURCE, DEFAULT_PRIORITY, 7u, 0i64, 0i64);
    _(0i64);
  }
  UFG::operator+(&v27, v1, "\\Props_new\\PropPhysics.bin");
  if ( UFG::StreamFileWrapper::FileExists(v27.mData) )
  {
    UFG::DataStreamer::QueueStream(
      &stru_1423EC5F0,
      v27.mData,
      DATA_TRUECROWD_RESOURCE,
      DEFAULT_PRIORITY,
      7u,
      0i64,
      0i64);
    _(0i64);
  }
  UFG::operator+(&v25, v1, "\\Vehicles_New\\Global.perm.bin");
  if ( UFG::StreamFileWrapper::FileExists(*(const char **)&v25.mMagic) )
  {
    UFG::DataStreamer::QueueStream(
      &stru_1423EC620,
      *(const char **)&v25.mMagic,
      DATA_TRUECROWD_TEXTURE_RESOURCE,
      DEFAULT_PRIORITY,
      7u,
      0i64,
      0i64);
    _(0i64);
  }
  UFG::operator+(&v28, v1, "\\Characters_New\\Global.perm.bin");
  if ( UFG::StreamFileWrapper::FileExists(v28.mData) )
  {
    UFG::DataStreamer::QueueStream(
      &stru_1423EC650,
      v28.mData,
      DATA_TRUECROWD_TEXTURE_RESOURCE,
      DEFAULT_PRIORITY,
      7u,
      0i64,
      0i64);
    _(0i64);
  }
  v12 = UFG::PartDatabase::Instance();
  UFG::PartDatabase::LoadDatabase(v12);
  do
  {
    UFG::qFileService(v13);
    UFG::DataStreamer::Service(0.033333335);
    Render::StreamingLoopProcessQueuedOperations(1, 0);
  }
  while ( !UFG::DataStreamer::IsStalled(0i64, 0) && UFG::DataStreamer::IsBusy(0i64, 0) );
  v14 = UFG::operator+(&result, v1, "\\Global\\Models.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v14->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v15 = UFG::operator+(&result, v1, "\\Global\\fonts.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v15->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v16 = UFG::operator+(&result, v1, "\\Global\\Effects.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v16->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v17 = UFG::operator+(&result, v1, "\\Global\\Clouds.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v17->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v18 = UFG::operator+(&result, v1, "\\Global\\Physics.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v18->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v19 = UFG::operator+(&result, v1, "\\Global\\Rig.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v19->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v20 = UFG::operator+(&result, v1, "\\Global\\GlobalDNA.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v20->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v21 = UFG::operator+(&result, v1, "\\PrefabData\\Database.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v21->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v22 = UFG::operator+(&result, v1, "\\Global\\Audio.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v22->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  UFG::qString::~qString(&v28);
  UFG::qString::~qString(&v25);
  UFG::qString::~qString(&v27);
  UFG::qString::~qString((UFG::qString *)((char *)&v25 + 32));
}

// File Line: 1071
// RVA: 0x425F10
void QueueLoadRigs(void)
{
  if ( hack_do_this_once )
  {
    if ( UFG::StreamFileWrapper::FileExists("Data\\Characters\\CharacterRigs.bin") )
      UFG::DataStreamer::QueueStream(
        &gHKGlobalStreams.mhCharacterRigs,
        "Data\\Characters\\CharacterRigs.bin",
        DATA_TRUECROWD_RESOURCE,
        DEFAULT_PRIORITY,
        7u,
        0i64,
        0i64);
    if ( UFG::StreamFileWrapper::FileExists("Data\\Characters_New\\CharacterRigs.bin") )
      UFG::DataStreamer::QueueStream(
        &stru_1423EC530,
        "Data\\Characters_New\\CharacterRigs.bin",
        DATA_TRUECROWD_RESOURCE,
        DEFAULT_PRIORITY,
        7u,
        0i64,
        0i64);
    if ( UFG::StreamFileWrapper::FileExists("Data\\Characters_New\\CharacterRigs.bin") )
      UFG::DataStreamer::QueueStream(
        &stru_1423EC5C0,
        "Data\\Props_New\\PropRigs.bin",
        DATA_TRUECROWD_RESOURCE,
        DEFAULT_PRIORITY,
        7u,
        0i64,
        0i64);
    hack_do_this_once = 0;
  }
}

// File Line: 1138
// RVA: 0x425E70
void __fastcall OnZoneLayoutLoadCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::qVector2 *v2; // rsi
  UFG::qVector2 *v3; // rbp
  UFG::qVector2 *v4; // rbx
  UFG::qVector2 *v5; // rdi
  UFG::CoverDataInventory *v6; // rax
  AMD_HD3D *v7; // rcx
  AMD_HD3D *v8; // rcx

  UFG::InterestPoint::InitGrid();
  v2 = UFG::GetWorldExtents_max();
  v3 = UFG::GetWorldExtents_min();
  v4 = UFG::GetWorldExtents_max();
  v5 = UFG::GetWorldExtents_min();
  v6 = UFG::CoverDataInventory::GetInstance();
  UFG::GridIntrusive<UFG::CoverCorner>::Init(&v6->m_CornerGrid, v3->x, v5->y, v2->x, v4->y, 100.0);
  UFG::WheeledVehicleManager::InitGlobalData(UFG::WheeledVehicleManager::m_Instance);
  _(v7);
  _(v8);
}

// File Line: 1152
// RVA: 0x4263D0
void UnloadCurrentLocation(void)
{
  UFG::TerrainCollisionManager *v0; // rax
  UFG::SectionChooser *v1; // rcx
  UFG::ObjectResourceManager *v2; // rax
  UFG::PartDatabase *v3; // rax
  UFG::UIScreenTextureManager *v4; // rax
  UFG::TiDo *v5; // rax

  if ( gCurrentLocationDirectory.mLength )
  {
    Illusion::IEnginePlat::WaitUntilGPUDone((Illusion::IEnginePlat *)&Illusion::gEngine);
    if ( UFG::WheeledVehicleManager::m_Instance )
      UFG::WheeledVehicleManager::ReleaseGlobalData(UFG::WheeledVehicleManager::m_Instance);
    v0 = UFG::TerrainCollisionManager::GetInstance();
    UFG::TerrainCollisionManager::Shutdown(v0);
    UFG::SectionChooser::Destroy(v1);
    UFG::InterestPoint::DeleteGrid();
    v2 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::FlushResources(v2, 1);
    v3 = UFG::PartDatabase::Instance();
    UFG::PartDatabase::FlushParts(v3, 1);
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::Update(v4, 0.0);
    UFG::RenderStageTerrain::Shutdown(UFG::RenderWorld::msStageTerrain);
    Render::FXManager::KillAllEffects(&Render::gFXManager);
    UFG::Scene::Purge(&UFG::Scene::msDefault);
    v5 = UFG::TiDo::GetInstance();
    v5->vfptr->UnloadAudio(v5, gCurrentLocationDirectory.mData);
    UFG::DataStreamer::Service(0.1);
    UFG::DataStreamer::Service(0.1);
    UFG::DataStreamer::Service(0.1);
    Render::StreamingLoopProcessQueuedOperations(1, 0);
    UFG::BigFileLogic::SetSystemBigFileEnabled(UFG::BigFileLogic::SYSTEM_WORLD, gCurrentLocationDirectory.mData, 0);
    UFG::qString::Set(&stru_1423AA4D0, &customWorldMapCaption);
    UFG::qString::Set(&stru_1423AA4A8, &customWorldMapCaption);
    UFG::qString::Set(&gCurrentLocationDirectory, &customWorldMapCaption);
  }
}

// File Line: 1216
// RVA: 0x4212C0
void __fastcall HK_VRAMMoveCallback(UFG::qVRAMemoryHandle *handle, char *previous_location, UFG::VRAMType usage, unsigned __int64 callback_data_64)
{
  void *buffer_ptr; // [rsp+20h] [rbp-18h]
  unsigned int buffer_size; // [rsp+50h] [rbp+18h]

  if ( (unsigned int)(usage - 9) <= 1 )
  {
    if ( UFG::DataStreamer::GetBufferFromUID(callback_data_64, &buffer_ptr, &buffer_size) )
      UFG::StreamResourceLoader::OnVRAMMove(buffer_ptr, buffer_size);
  }
}

// File Line: 1268
// RVA: 0x4229D0
void InitGlobalPools(void)
{
  UFG::SkookumMgr::MemoryInit();
  if ( UFG::gPageBasedStompDetector )
    UFG::qMemoryPool::EnablePageBasedStompDetection(&gSimulationMemoryPool);
  UFG::qMemoryPool::Init(
    &gSimulationMemoryPool,
    "SimulationMemoryPool",
    (signed int)g_HK_SimulationMemoryPoolSize,
    g_HK_SimulationMemorySmallBlockSize,
    1,
    1u,
    UFG::gMainMemoryPool,
    1,
    1);
  UFG::SetSimulationMemoryPool(&gSimulationMemoryPool);
  UFG::qMemoryPool::Init(
    &gAIMemoryPool,
    "AIMemoryPool",
    g_HK_AIMemoryPoolSize,
    g_HK_AIMemorySmallBlockSize,
    1,
    1u,
    0i64,
    1,
    1);
  if ( UFG::gPageBasedStompDetector )
    UFG::qMemoryPool::EnablePageBasedStompDetection((UFG::qMemoryPool *)&gActionTreeMemoryPool.mPrev);
  UFG::qMemoryPool2::Init(
    &gActionTreeMemoryPool,
    "ActionTreeMemoryPool",
    g_HK_ActionTreeMemoryPoolSize,
    g_HK_ActionTreeMemoryPoolSize_Small,
    1,
    1u,
    UFG::gMainMemoryPool,
    1);
  if ( UFG::gPageBasedStompDetector )
    UFG::qMemoryPool::EnablePageBasedStompDetection(&gPropertySetMemoryPool);
  UFG::qMemoryPool::Init(
    &gPropertySetMemoryPool,
    "PropertySetMemoryPool",
    (signed int)g_HK_PropertySetPoolSize,
    g_HK_PropertySetPoolSmallBlockSize,
    1,
    1u,
    UFG::gMainMemoryPool,
    1,
    1);
  if ( UFG::gPageBasedStompDetector )
    UFG::qMemoryPool::EnablePageBasedStompDetection(&gSkookumMemoryPool);
  UFG::qMemoryPool::Init(
    &gSkookumMemoryPool,
    "SkookumMemoryPool",
    (signed int)g_HK_SkookumPoolSize,
    g_HK_SkookumPoolSmallBlockSize,
    1,
    1u,
    UFG::gMainMemoryPool,
    1,
    1);
  UFG::qMemoryPool::Init(
    &gOnlineMemoryPool,
    "OnlineMemoryPool",
    (signed int)g_HK_OnlinePoolSize,
    g_HK_OnlinePoolSmallBlockSize,
    1,
    1u,
    UFG::gMainMemoryPool,
    1,
    1);
  UFG::qMemoryPool::Init(
    &gpc_PC_VRamMemoryPool,
    "PCVRAM_MemoryPool",
    (signed int)(g_HK_VRAMSize + 4096),
    0,
    0,
    1u,
    0i64,
    1,
    1);
  gpPC_VRAM = UFG::qMemoryPool::Allocate(&gpc_PC_VRamMemoryPool, g_HK_VRAMSize, "PCVRAMbuffer", 0i64, 1u);
  UFG::qVRAMemoryPools::InitSystem((char *)gpPC_VRAM, g_HK_VRAMSize, "Global", 0, 0x80u, 0i64, 0, 0x1F40u, 0i64, 0);
  UFG::qVRAMemoryPool::SetCanDefrag(UFG::gMainVRAMemoryPool, 0);
  UFG::qVRAMemoryPools::SetDefaultDefragCallback((void (__fastcall *)(UFG::qVRAMemoryHandle *, char *, UFG::VRAMType, unsigned __int64, unsigned int))HK_VRAMMoveCallback);
  UFG::qMemoryPool::Init(
    &gScaleformMemoryPool,
    "Scaleform_MemoryPool",
    g_HK_ScaleformMemoryPoolSize,
    g_HK_ScaleformMemoryPoolSmallBlockSize,
    1,
    1u,
    UFG::gMainMemoryPool,
    1,
    1);
}

// File Line: 1348
// RVA: 0x422D00
void InitStreamingPools(void)
{
  unsigned int dest; // [rsp+20h] [rbp-19h]
  int v1; // [rsp+24h] [rbp-15h]
  int v2; // [rsp+28h] [rbp-11h]
  unsigned int v3; // [rsp+2Ch] [rbp-Dh]
  unsigned int v4; // [rsp+30h] [rbp-9h]
  unsigned int v5; // [rsp+34h] [rbp-5h]
  unsigned int v6; // [rsp+38h] [rbp-1h]
  int v7; // [rsp+3Ch] [rbp+3h]
  unsigned int v8; // [rsp+40h] [rbp+7h]
  unsigned int v9; // [rsp+44h] [rbp+Bh]
  unsigned int v10; // [rsp+48h] [rbp+Fh]
  unsigned int v11; // [rsp+4Ch] [rbp+13h]
  unsigned int v12; // [rsp+50h] [rbp+17h]
  unsigned int v13; // [rsp+54h] [rbp+1Bh]
  unsigned int v14; // [rsp+58h] [rbp+1Fh]
  unsigned int v15; // [rsp+5Ch] [rbp+23h]
  unsigned int v16; // [rsp+60h] [rbp+27h]
  __int64 v17; // [rsp+64h] [rbp+2Bh]
  unsigned int v18; // [rsp+6Ch] [rbp+33h]
  unsigned int v19; // [rsp+70h] [rbp+37h]
  unsigned int v20; // [rsp+74h] [rbp+3Bh]
  unsigned int v21; // [rsp+78h] [rbp+3Fh]
  unsigned int v22; // [rsp+7Ch] [rbp+43h]
  unsigned int v23; // [rsp+80h] [rbp+47h]
  unsigned int v24; // [rsp+84h] [rbp+4Bh]

  UFG::StreamPool_InitSystem();
  UFG::qMemSet(&dest, 0, 0x68u);
  dest = g_HK_LocationMemoryPoolSize;
  v3 = g_HK_AnimationMemoryPoolSize;
  v14 = g_HK_TrueCrowdMemoryPoolSize + g_HK_PartsDBMemoryPoolSize;
  v4 = g_HK_CloudsTexturePoolSize;
  v5 = g_HK_UIPoolSize;
  v6 = g_HK_LocalizationPoolSize;
  v15 = g_HK_TrueCrowdTextureHeaderPoolSize + g_HK_PartsDBTextureHeaderPoolSize;
  v8 = g_HK_GameplayCellBlockSize;
  v9 = g_HK_ScriptPoolSize;
  v10 = g_HK_UIVRamMemoryPoolSize;
  v16 = g_HK_TrueCrowdTexturePoolSize + g_HK_PartsDBTexturePoolSize;
  v11 = g_MaxTerrainElements;
  v12 = g_TerrainElementSize;
  v1 = 0x1400000;
  v13 = g_TerrainVRAMElementSize;
  v2 = 0xA00000;
  v17 = 0i64;
  v7 = 0xF00000;
  v18 = g_stdSectionElementSize;
  v19 = g_stdSectionVRAMElementSize;
  v20 = g_lodcSectionElementSize;
  v21 = g_lodcSectionVRAMElementSize;
  v22 = g_zoneElementSize;
  v23 = g_zoneVRAMElementSize;
  v24 = g_globalVRAMElementSize;
  UFG::StreamingMemory::Init((UFG::StreamingMemory::InitParams *)&dest);
}

// File Line: 1473
// RVA: 0x426240
void __fastcall SetUpCameraForFERender(UFG *a1)
{
  UFG::qSymbol *v1; // rax
  UFG::SimObject *v2; // rdi
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rbx
  unsigned int v5; // eax
  UFG::BaseCameraComponent *v6; // rax
  UFG::BaseCameraComponent *v7; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h]
  UFG::qSymbol result; // [rsp+78h] [rbp+10h]

  UFG::CreateDirector(a1);
  v1 = UFG::qSymbol::create_from_string(&result, "ChaseCamera");
  v2 = UFG::Simulation::CreateSimObject(&UFG::gSim, v1);
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0xD60ui64, "ChaseCameraComponent", 0i64, 1u);
  if ( v4 )
  {
    v5 = UFG::qStringHash32("ChaseCamera", 0xFFFFFFFF);
    UFG::ChaseCameraComponent::ChaseCameraComponent((UFG::ChaseCameraComponent *)v4, v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, v2, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, (UFG::SimComponent *)&v7->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  UFG::AttachCameraToView(v7);
}

// File Line: 1487
// RVA: 0x424CA0
void LoadGlobalPropertySets(void)
{
  UFG::allocator::free_link *v0; // rdi
  UFG::allocator::free_link *v1; // rax
  UFG::allocator::free_link *v2; // rbx
  UFG::BIGFileSize fileSize; // [rsp+30h] [rbp-18h]

  *(_QWORD *)&fileSize.load_offset = 0i64;
  *(_QWORD *)&fileSize.compressed_extra = 0i64;
  UFG::StreamFileWrapper::GetFileSize("Data\\Global\\PropertySets\\globalproperties.bin", &fileSize);
  v0 = UFG::qMemoryPool::Allocate(
         UFG::gMainMemoryPool,
         fileSize.uncompressed_size + fileSize.compressed_extra,
         "globalpropertybin",
         0i64,
         1u);
  v1 = UFG::StreamFileWrapper::Open("Data\\Global\\PropertySets\\globalproperties.bin", QACCESS_READ, 1, 0i64, 0i64);
  v2 = v1;
  if ( v1 )
  {
    UFG::StreamFileWrapper::Read(v1, STREAM_DATA_HIGH_PRIORITY, v0, &fileSize, 0i64, 0i64);
    UFG::StreamResourceLoader::Load(
      v0,
      fileSize.uncompressed_size,
      "Data\\Global\\PropertySets\\globalproperties.bin",
      0,
      0i64);
    UFG::StreamFileWrapper::Close(v2);
  }
}

// File Line: 1512
// RVA: 0x423020
char __fastcall LoadBinaryACTandABKFiles()
{
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\wst_files.bin", UFG::gMainMemoryPool, 0, 0i64, 0i64, 0i64);
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\rig_files.bin", UFG::gMainMemoryPool, 0, 0i64, 0i64, 0i64);
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\abk_files.bin", UFG::gMainMemoryPool, 0, 0i64, 0i64, 0i64);
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\btr_files.bin", UFG::gMainMemoryPool, 0, 0i64, 0i64, 0i64);
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\act_files.bin", UFG::gMainMemoryPool, 0, 0i64, 0i64, 0i64);
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\uef_files.bin", UFG::gMainMemoryPool, 0, 0i64, 0i64, 0i64);
  return 1;
}

// File Line: 1550
// RVA: 0x426510
void UnloadXMLCache(void)
{
  if ( gCreateFinalBinDir )
    UFG::DataStreamer::ReleaseStream(&handle);
}

// File Line: 1557
// RVA: 0x14FF900
__int64 dynamic_initializer_for__gLegalTexturePackFileName__()
{
  UFG::qString::qString(&gLegalTexturePackFileName);
  return atexit(dynamic_atexit_destructor_for__gLegalTexturePackFileName__);
}

// File Line: 1558
// RVA: 0x14FF8E0
__int64 dynamic_initializer_for__gLegalRatingsPackFileName__()
{
  UFG::qString::qString(&gLegalRatingsPackFileName);
  return atexit(dynamic_atexit_destructor_for__gLegalRatingsPackFileName__);
}

// File Line: 1559
// RVA: 0x14FF720
__int64 dynamic_initializer_for__gBootSequenceImages__()
{
  __int64 result; // rax

  result = 0i64;
  gBootSequenceImages[0].mRequiredTimeLength = 0.0;
  dword_1423EC6E4 = -1;
  qword_1423EC6E8 = 0i64;
  qword_1423EC6F0 = 0i64;
  dword_1423EC6F8 = 0;
  qword_1423EC700 = 0i64;
  qword_1423EC708 = 0i64;
  dword_1423EC6FC = -1;
  return result;
}

// File Line: 1632
// RVA: 0x424F90
signed __int64 __fastcall MapRegionCodeToRegion(const char *code)
{
  const char *v1; // rbx
  signed __int64 result; // rax
  int v3; // eax
  unsigned int v4; // ecx

  v1 = code;
  if ( !code || (unsigned int)UFG::qStringLength(code) != 2 )
    goto LABEL_122;
  if ( !(unsigned int)UFG::qStringCompare(v1, "ae", -1) )
    return 56i64;
  result = UFG::qStringCompare(v1, "ar", -1);
  if ( (_DWORD)result )
  {
    if ( !(unsigned int)UFG::qStringCompare(v1, "at", -1) )
      return 2i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "au", -1) )
      return 1i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "be", -1) )
      return 4i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "bg", -1) )
      return 6i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "bh", -1) )
      return 3i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "br", -1) )
      return 5i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "ca", -1) )
      return 7i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "cn", -1) )
      return 9i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "ch", -1) )
      return 52i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "cl", -1) )
      return 8i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "co", -1) )
      return 10i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "cy", -1) )
      return 12i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "cz", -1) )
      return 13i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "de", -1) )
      return 17i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "dk", -1) )
      return 14i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "es", -1) )
      return 50i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "fi", -1) )
      return 15i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "fr", -1) )
      return 16i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "gb", -1) )
      return 57i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "gr", -1) )
      return 18i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "hk", -1) )
      return 19i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "hr", -1) )
      return 11i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "hu", -1) )
      return 20i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "id", -1) )
      return 23i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "ie", -1) )
      return 24i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "il", -1) )
      return 25i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "in", -1) )
      return 22i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "is", -1) )
      return 21i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "it", -1) )
      return 26i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "jp", -1) )
      return 27i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "kr", -1) )
      return 28i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "kw", -1) )
      return 29i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "lb", -1) )
      return 30i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "lu", -1) )
      return 31i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "mt", -1) )
      return 33i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "mx", -1) )
      return 34i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "my", -1) )
      return 32i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "nl", -1) )
      return 35i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "no", -1) )
      return 37i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "nz", -1) )
      return 36i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "om", -1) )
      return 38i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "pe", -1) )
      return 39i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "pl", -1) )
      return 40i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "pt", -1) )
      return 41i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "qa", -1) )
      return 42i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "ro", -1) )
      return 43i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "ru", -1) )
      return 44i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "sa", -1) )
      return 45i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "se", -1) )
      return 51i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "sg", -1) )
      return 46i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "si", -1) )
      return 48i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "sk", -1) )
      return 47i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "th", -1) )
      return 54i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "tr", -1) )
      return 55i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "tw", -1) )
      return 53i64;
    if ( !(unsigned int)UFG::qStringCompare(v1, "ua", -1) )
      return 58i64;
    if ( (unsigned int)UFG::qStringCompare(v1, "us", -1) )
    {
      v3 = UFG::qStringCompare(v1, "za", -1);
      v4 = 59;
      if ( !v3 )
        v4 = 49;
      return v4;
    }
LABEL_122:
    result = 59i64;
  }
  return result;
}

// File Line: 1705
// RVA: 0x4257B0
const char *__fastcall MapRegionToRegionCode(Region region)
{
  const char *result; // rax

  if ( region == 60 || region == -1 )
  {
    region = 59;
  }
  else if ( (unsigned int)region > 0x3B )
  {
    return "us";
  }
  switch ( region )
  {
    case 0u:
      result = "ar";
      break;
    case 1u:
      result = "au";
      break;
    case 2u:
      result = "at";
      break;
    case 3u:
      result = "bh";
      break;
    case 4u:
      result = "be";
      break;
    case 5u:
      result = "br";
      break;
    case 6u:
      result = "bg";
      break;
    case 7u:
      result = "ca";
      break;
    case 8u:
      result = "cl";
      break;
    case 9u:
      result = "cn";
      break;
    case 0xAu:
      result = "co";
      break;
    case 0xBu:
      result = "hr";
      break;
    case 0xCu:
      result = "cy";
      break;
    case 0xDu:
      result = "cz";
      break;
    case 0xEu:
      result = "dk";
      break;
    case 0xFu:
      result = "fi";
      break;
    case 0x10u:
      result = "fr";
      break;
    case 0x11u:
      result = "de";
      break;
    case 0x12u:
      result = "gr";
      break;
    case 0x13u:
      result = "hk";
      break;
    case 0x14u:
      result = "hu";
      break;
    case 0x15u:
      result = "is";
      break;
    case 0x16u:
      result = "in";
      break;
    case 0x17u:
      result = "id";
      break;
    case 0x18u:
      result = "ie";
      break;
    case 0x19u:
      result = "il";
      break;
    case 0x1Au:
      result = "it";
      break;
    case 0x1Bu:
      result = "jp";
      break;
    case 0x1Cu:
      result = "kr";
      break;
    case 0x1Du:
      result = "kw";
      break;
    case 0x1Eu:
      result = "lb";
      break;
    case 0x1Fu:
      result = "lu";
      break;
    case 0x20u:
      result = "my";
      break;
    case 0x21u:
      result = "mt";
      break;
    case 0x22u:
      result = "mx";
      break;
    case 0x23u:
      result = "nl";
      break;
    case 0x24u:
      result = "nz";
      break;
    case 0x25u:
      result = "no";
      break;
    case 0x26u:
      result = "om";
      break;
    case 0x27u:
      result = "pe";
      break;
    case 0x28u:
      result = "pl";
      break;
    case 0x29u:
      result = "pt";
      break;
    case 0x2Au:
      result = "qa";
      break;
    case 0x2Bu:
      result = "ro";
      break;
    case 0x2Cu:
      result = "ru";
      break;
    case 0x2Du:
      result = "sa";
      break;
    case 0x2Eu:
      result = "sg";
      break;
    case 0x2Fu:
      result = "sk";
      break;
    case 0x30u:
      result = "si";
      break;
    case 0x31u:
      result = "za";
      break;
    case 0x32u:
      result = "es";
      break;
    case 0x33u:
      result = "se";
      break;
    case 0x34u:
      result = "ch";
      break;
    case 0x35u:
      result = "tw";
      break;
    case 0x36u:
      result = "th";
      break;
    case 0x37u:
      result = "tr";
      break;
    case 0x38u:
      result = "ae";
      break;
    case 0x39u:
      result = "gb";
      break;
    case 0x3Au:
      result = "ua";
      break;
    default:
      return "us";
  }
  return result;
}

// File Line: 1777
// RVA: 0x420E40
Region __fastcall GetSystemRegion()
{
  Region result; // eax
  int v1; // eax
  Region v2; // ecx
  char dest; // [rsp+20h] [rbp-E0h]
  char v4; // [rsp+22h] [rbp-DEh]
  char code; // [rsp+23h] [rbp-DDh]
  char v6; // [rsp+25h] [rbp-DBh]
  wchar_t text; // [rsp+80h] [rbp-80h]

  if ( (signed int)GetUserDefaultLocaleName(&text, 85i64) < 3 )
    return 59;
  UFG::qWideStringCopy(&dest, 85, &text, -1);
  UFG::qStringToLower(&dest);
  if ( (unsigned int)UFG::qStringLength(&dest) == 5 )
  {
    v6 = 0;
    result = MapRegionCodeToRegion(&code);
  }
  else
  {
    v4 = 0;
    if ( (unsigned int)UFG::qStringCompare("zh", &dest, -1) )
    {
      if ( (unsigned int)UFG::qStringCompare("da", &dest, -1) )
      {
        if ( (unsigned int)UFG::qStringCompare("nl", &dest, -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare("en", &dest, -1) )
            return 59;
          if ( (unsigned int)UFG::qStringCompare("fi", &dest, -1) )
          {
            if ( (unsigned int)UFG::qStringCompare("fr", &dest, -1) )
            {
              if ( (unsigned int)UFG::qStringCompare("de", &dest, -1) )
              {
                if ( (unsigned int)UFG::qStringCompare("it", &dest, -1) )
                {
                  if ( (unsigned int)UFG::qStringCompare("ja", &dest, -1) )
                  {
                    if ( (unsigned int)UFG::qStringCompare("ko", &dest, -1) )
                    {
                      if ( (unsigned int)UFG::qStringCompare("no", &dest, -1) )
                      {
                        if ( (unsigned int)UFG::qStringCompare("pl", &dest, -1) )
                        {
                          if ( (unsigned int)UFG::qStringCompare("pt", &dest, -1) )
                          {
                            if ( (unsigned int)UFG::qStringCompare("ru", &dest, -1) )
                            {
                              if ( (unsigned int)UFG::qStringCompare("es", &dest, -1) )
                              {
                                v1 = UFG::qStringCompare("sv", &dest, -1);
                                v2 = 59;
                                if ( !v1 )
                                  v2 = 51;
                                result = v2;
                              }
                              else
                              {
                                result = 50;
                              }
                            }
                            else
                            {
                              result = 44;
                            }
                          }
                          else
                          {
                            result = 41;
                          }
                        }
                        else
                        {
                          result = 40;
                        }
                      }
                      else
                      {
                        result = 37;
                      }
                    }
                    else
                    {
                      result = 28;
                    }
                  }
                  else
                  {
                    result = 27;
                  }
                }
                else
                {
                  result = 26;
                }
              }
              else
              {
                result = 17;
              }
            }
            else
            {
              result = 16;
            }
          }
          else
          {
            result = 15;
          }
        }
        else
        {
          result = 35;
        }
      }
      else
      {
        result = 14;
      }
    }
    else
    {
      result = 9;
    }
  }
  return result;
}

// File Line: 1878
// RVA: 0x4206E0
void __fastcall DisplayLegalLoadScreen(UFG::UILanguages::eLanguage systemLanguage, UFG::UILanguages::eLanguage gameLanguage, Region systemRegion)
{
  Region v3; // ebx
  UFG::UI *v4; // rcx
  bool v5; // al
  UFG::qString *v6; // rax
  unsigned int v7; // esi
  UFG::qString *v8; // rax
  signed int v9; // ebx
  int v10; // edi
  UFG::qString *v11; // rax
  UFG::qString *v12; // rax
  UFG::qString *v13; // rax
  UFG::qString *v14; // rax
  UFG::qString *v15; // rax
  UFG::qString *v16; // rbx
  UFG::qString *v17; // rax
  UFG::qString *v18; // rax
  UFG::qString *v19; // rax
  UFG::qString *v20; // rbx
  UFG::qString *v21; // rax
  UFG::qString *v22; // rax
  UFG::qString *v23; // rax
  UFG::qString *v24; // rbx
  UFG::qString *v25; // rax
  UFG::qString *v26; // rcx
  UFG::qString *v27; // rax
  UFG::qString *v28; // rbx
  UFG::qString *v29; // rax
  UFG *v30; // rcx
  float v31; // xmm0_4
  float v32; // xmm1_4
  UFG::qResourceWarehouse *v33; // rax
  UFG::qResourceInventory *i; // rdi
  UFG *v35; // rcx
  Render::LoadScreenInitParams params; // [rsp+30h] [rbp-C8h]
  UFG::qString v37; // [rsp+A0h] [rbp-58h]
  UFG::qString v38; // [rsp+C8h] [rbp-30h]
  UFG::qString v39; // [rsp+F0h] [rbp-8h]
  UFG::qString v40; // [rsp+118h] [rbp+20h]
  UFG::qString v41; // [rsp+140h] [rbp+48h]
  UFG::qString v42; // [rsp+168h] [rbp+70h]
  UFG::qString v43; // [rsp+190h] [rbp+98h]
  UFG::qString v44; // [rsp+1B8h] [rbp+C0h]
  UFG::qString v45; // [rsp+1E0h] [rbp+E8h]
  UFG::qString v46; // [rsp+208h] [rbp+110h]
  UFG::qString v47; // [rsp+230h] [rbp+138h]
  UFG::qString v48; // [rsp+258h] [rbp+160h]
  UFG::qString v49; // [rsp+280h] [rbp+188h]
  UFG::qString v50; // [rsp+2A8h] [rbp+1B0h]
  UFG::qString v51; // [rsp+2D0h] [rbp+1D8h]
  UFG::qString result; // [rsp+2F8h] [rbp+200h]
  Render::RenderOutputParams outSettings; // [rsp+328h] [rbp+230h]

  *(_QWORD *)&params.mBackgroundName.mStringHash32 = -2i64;
  v3 = systemRegion;
  LoadTexturePackHK("Data\\Global\\BootTexturePack.perm.bin", DATA_GAME_GLOBAL_TEXTURES);
  UFG::UI::InitHDSettings(v4);
  v5 = UFG::UI::IsInHDMode();
  switch ( v3 )
  {
    case 2u:
    case 4u:
    case 6u:
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
    case 0x12u:
    case 0x13u:
    case 0x14u:
    case 0x15u:
    case 0x18u:
    case 0x1Au:
    case 0x1Fu:
    case 0x21u:
    case 0x23u:
    case 0x25u:
    case 0x28u:
    case 0x29u:
    case 0x2Bu:
    case 0x2Cu:
    case 0x2Fu:
    case 0x30u:
    case 0x32u:
    case 0x33u:
    case 0x34u:
    case 0x39u:
    case 0x3Au:
      if ( v5 )
      {
        v15 = UFG::qString::FormatEx(&v48, "LEGAL_%s_SCREENENGLISH_EU", "PC64");
        v16 = v15;
        if ( v15->mStringHashUpper32 == -1 )
          v15->mStringHashUpper32 = UFG::qStringHashUpper32(v15->mData, 0xFFFFFFFF);
        v7 = v16->mStringHashUpper32;
        UFG::qString::~qString(&v48);
        v17 = UFG::qString::FormatEx(&v44, "Data\\UI\\Legal_%s_ScreenEnglish_EU_TexturePack.perm.bin", "PC64");
        v9 = 0;
        UFG::qString::Set(&gLegalTexturePackFileName, v17->mData, v17->mLength, 0i64, 0);
        UFG::qString::~qString(&v44);
        v10 = UFG::qStringHashUpper32("LEGAL_ESRB_EU", 0xFFFFFFFF);
        v18 = UFG::qString::FormatEx(&v37, "Data\\UI\\Legal_ESRB_EU_TexturePack.perm.bin");
        UFG::qString::Set(&gLegalRatingsPackFileName, v18->mData, v18->mLength, 0i64, 0);
        UFG::qString::~qString(&v37);
      }
      else
      {
        v19 = UFG::qString::FormatEx(&v38, "LEGAL_%s_SCREENENGLISH_EU_SD", "PC64");
        v20 = v19;
        if ( v19->mStringHashUpper32 == -1 )
          v19->mStringHashUpper32 = UFG::qStringHashUpper32(v19->mData, 0xFFFFFFFF);
        v7 = v20->mStringHashUpper32;
        UFG::qString::~qString(&v38);
        v21 = UFG::qString::FormatEx(&v39, "Data\\UI\\Legal_%s_ScreenEnglish_EU_SD_TexturePack.perm.bin", "PC64");
        v9 = 0;
        UFG::qString::Set(&gLegalTexturePackFileName, v21->mData, v21->mLength, 0i64, 0);
        UFG::qString::~qString(&v39);
        v10 = UFG::qStringHashUpper32("LEGAL_ESRB_EU_SD", 0xFFFFFFFF);
        v22 = UFG::qString::FormatEx(&v41, "Data\\UI\\Legal_ESRB_EU_SD_TexturePack.perm.bin");
        UFG::qString::Set(&gLegalRatingsPackFileName, v22->mData, v22->mLength, 0i64, 0);
        UFG::qString::~qString(&v41);
      }
      break;
    case 5u:
    case 7u:
    case 0xAu:
    case 0x22u:
    case 0x3Bu:
      if ( v5 )
      {
        v6 = UFG::qString::FormatEx(&result, "LEGAL_%s_SCREENENGLISH_US", "PC64");
        v7 = UFG::qString::GetStringHashUpper32(v6);
        UFG::qString::~qString(&result);
        v8 = UFG::qString::FormatEx(&v51, "Data\\UI\\Legal_%s_ScreenEnglish_US_TexturePack.perm.bin", "PC64");
        v9 = 0;
        UFG::qString::Set(&gLegalTexturePackFileName, v8->mData, v8->mLength, 0i64, 0);
        UFG::qString::~qString(&v51);
        v10 = UFG::qStringHashUpper32("LEGAL_ESRB_US", 0xFFFFFFFF);
        v11 = UFG::qString::FormatEx(&v46, "Data\\UI\\Legal_ESRB_US_TexturePack.perm.bin");
        UFG::qString::Set(&gLegalRatingsPackFileName, v11->mData, v11->mLength, 0i64, 0);
        UFG::qString::~qString(&v46);
      }
      else
      {
        v12 = UFG::qString::FormatEx(&v40, "LEGAL_%s_SCREENENGLISH_US_SD", "PC64");
        v7 = UFG::qString::GetStringHashUpper32(v12);
        UFG::qString::~qString(&v40);
        v13 = UFG::qString::FormatEx(&v50, "Data\\UI\\Legal_%s_ScreenEnglish_US_SD_TexturePack.perm.bin", "PC64");
        v9 = 0;
        UFG::qString::Set(&gLegalTexturePackFileName, v13->mData, v13->mLength, 0i64, 0);
        UFG::qString::~qString(&v50);
        v10 = UFG::qStringHashUpper32("LEGAL_ESRB_US_SD", 0xFFFFFFFF);
        v14 = UFG::qString::FormatEx(&v42, "Data\\UI\\Legal_ESRB_US_SD_TexturePack.perm.bin");
        UFG::qString::Set(&gLegalRatingsPackFileName, v14->mData, v14->mLength, 0i64, 0);
        UFG::qString::~qString(&v42);
      }
      break;
    default:
      if ( v5 )
      {
        v23 = UFG::qString::FormatEx(&v43, "LEGAL_%s_SCREENENGLISH_EU", "PC64");
        v24 = v23;
        if ( v23->mStringHashUpper32 == -1 )
          v23->mStringHashUpper32 = UFG::qStringHashUpper32(v23->mData, 0xFFFFFFFF);
        v7 = v24->mStringHashUpper32;
        UFG::qString::~qString(&v43);
        v25 = UFG::qString::FormatEx(&v45, "Data\\UI\\Legal_%s_ScreenEnglish_EU_TexturePack.perm.bin", "PC64");
        v9 = 0;
        UFG::qString::Set(&gLegalTexturePackFileName, v25->mData, v25->mLength, 0i64, 0);
        v26 = &v45;
      }
      else
      {
        v27 = UFG::qString::FormatEx(&v47, "LEGAL_%s_SCREENENGLISH_EU_SD", "PC64");
        v28 = v27;
        if ( v27->mStringHashUpper32 == -1 )
          v27->mStringHashUpper32 = UFG::qStringHashUpper32(v27->mData, 0xFFFFFFFF);
        v7 = v28->mStringHashUpper32;
        UFG::qString::~qString(&v47);
        v29 = UFG::qString::FormatEx(&v49, "Data\\UI\\Legal_%s_ScreenEnglish_EU_SD_TexturePack.perm.bin", "PC64");
        v9 = 0;
        UFG::qString::Set(&gLegalTexturePackFileName, v29->mData, v29->mLength, 0i64, 0);
        v26 = &v49;
      }
      UFG::qString::~qString(v26);
      UFG::qString::Set(&gLegalRatingsPackFileName, &customWorldMapCaption);
      v10 = 0;
      break;
  }
  _(0i64);
  do
  {
    UFG::qFileService(v30);
    UFG::DataStreamer::Service(0.033333335);
    Render::StreamingLoopProcessQueuedOperations(1, 0);
  }
  while ( !UFG::DataStreamer::IsStalled(0i64, 0) && UFG::DataStreamer::IsBusy(0i64, 0) );
  params.mFlipbookEnabled = 1;
  params.mNumFlipbookPagesHoriz = 8;
  params.mNumFlipbookPagesVert = 8;
  *(_OWORD *)&params.mFlipbookHorizSpeed = _xmm;
  UFG::qString::qString(&params.mAnimationName, "LoadingAnimation");
  UFG::qString::qString(&params.mBackgroundName, "LoadingAnimationBackground");
  params.mFlipbookVertSpeed = 0.25;
  params.mFlipbookHorizSpeed = 0.25;
  params.mAnimationScale = FLOAT_1_5;
  params.mRotationEnabled = 1.0;
  UFG::qString::Set(&params.mAnimationName, "LoadingAnimation");
  UFG::qString::Set(&params.mBackgroundName, "LoadingAnimationBackground");
  Render::InitLoadScreen(&params);
  Render::SetLoadScreenSpinnerTint(&kMainSpinnerColour);
  if ( !UFG::gUIBootModeSkipFE )
  {
    dword_1423EC6E4 = v7;
    qword_1423EC6E8 = (__int64)gLegalTexturePackFileName.mData;
    qword_1423EC6F0 = 0i64;
    Render::RenderOutputParams::RenderOutputParams(&outSettings);
    Render::GetCurrentDisplaySettings(&outSettings);
    v31 = FLOAT_6_0;
    if ( outSettings.mEnable3D )
      v32 = FLOAT_6_0;
    else
      v32 = FLOAT_2_0;
    gBootSequenceImages[0].mRequiredTimeLength = v32 + 3.0;
    dword_1423EC6FC = v10;
    qword_1423EC700 = (__int64)gLegalRatingsPackFileName.mData;
    qword_1423EC708 = 0i64;
    if ( !outSettings.mEnable3D )
      v31 = FLOAT_2_0;
    *(float *)&dword_1423EC6F8 = v31 + 4.0;
    UFG::LoadingLogic::StartLoadScreen(&UFG::gLoadingLogic, 3u, gBootSequenceImages, 1u);
    v33 = UFG::qResourceWarehouse::Instance();
    for ( i = UFG::qResourceWarehouse::GetInventory(v33, 0x8B43FABF); !(__int64)i->vfptr->Get(i, v7); ++v9 )
    {
      if ( v9 >= 1000 )
        break;
      do
      {
        UFG::qFileService(v35);
        UFG::DataStreamer::Service(0.033333335);
        Render::StreamingLoopProcessQueuedOperations(1, 0);
      }
      while ( !UFG::DataStreamer::IsStalled(0i64, 0) && UFG::DataStreamer::IsBusy(0i64, 0) );
    }
    Render::ExecuteDeferredContextForThread(v35);
    _(0i64);
  }
  UFG::qString::~qString(&params.mBackgroundName);
  UFG::qString::~qString(&params.mAnimationName);
}

// File Line: 2160
// RVA: 0x14FFA50
__int64 dynamic_initializer_for__gTempFrameMemoryAllocator__()
{
  UFG::qLinearAllocator::qLinearAllocator(&gTempFrameMemoryAllocator);
  return atexit(dynamic_atexit_destructor_for__gTempFrameMemoryAllocator__);
}

// File Line: 2176
// RVA: 0x420430
void AddFrameMemoryOverflow(void)
{
  unsigned int v0; // edi
  char *v1; // rbx

  if ( gFrameMemoryOverflowBuffer )
  {
    if ( gFrameMemoryOverflowEnabled != 1 )
    {
      UFG::qPrintf(
        "[TempFrameMemory] Added - addr=0x%08x sz=%7d!\n",
        gFrameMemoryOverflowBuffer,
        gFrameMemoryOverflowTotalBytes);
      Illusion::IEnginePlat::WaitUntilGPUDone((Illusion::IEnginePlat *)&Illusion::gEngine);
      UFG::qTaskManager::Sync(&UFG::gTaskManager);
      UFG::qLinearAllocator::Init(&gTempFrameMemoryAllocator, 0i64, 0i64, 0i64, 0i64);
      v0 = (gFrameMemoryOverflowTotalBytes >> 1) & 0x7FFFFF80;
      v1 = &gFrameMemoryOverflowBuffer[v0];
      Render::SetFrameMemoryOverflow(0, gFrameMemoryOverflowBuffer, v0);
      Render::SetFrameMemoryOverflow(1u, v1, v0);
      gFrameMemoryOverflowEnabled = 1;
    }
  }
}

// File Line: 2231
// RVA: 0x4269F0
void __fastcall qTaskThreadInit()
{
  hkResult result; // [rsp+30h] [rbp+8h]

  hkBaseSystem::initThread(&result, UFG::BasePhysicsSystem::mMemoryRouter);
}

// File Line: 2237
// RVA: 0x4269D0
void __fastcall qTaskThreadClose()
{
  hkResult result; // [rsp+30h] [rbp+8h]

  hkBaseSystem::quitThread(&result);
}

// File Line: 2245
// RVA: 0x425B20
void MountBigFiles(void)
{
  bool v0; // bl
  bool v1; // di
  bool v2; // si
  bool v3; // bp
  bool v4; // r14
  bool v5; // r15
  bool v6; // r12
  bool v7; // r13
  int v8; // ebx

  v0 = UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_BOOT, 0i64, 0i64);
  _(0i64);
  UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_STREAMING_INSTALLER_PART_01, 0i64, 0i64);
  _(0i64);
  v1 = UFG::BigFileLogic::MountSystemBigFile((const char *)&UFG::BigFileLogic::SYSTEM_GLOBAL->mEnableStereo, 0i64, 0i64);
  _(0i64);
  v2 = UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_UI, 0i64, 0i64);
  _(0i64);
  v3 = UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_VEHICLES, 0i64, 0i64);
  _(0i64);
  v4 = UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_CHARACTERS, 0i64, 0i64);
  _(0i64);
  if ( !gForceLowRes )
    UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_CHARACTERS, 0i64, "HD");
  _(0i64);
  v5 = UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_ANIMATION, 0i64, 0i64);
  _(0i64);
  v6 = UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_NISANIMATION, 0i64, 0i64);
  _(0i64);
  UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_GAMEPLAY, 0i64, 0i64);
  _(0i64);
  UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_PARTS, 0i64, 0i64);
  UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_PARTS, 0i64, "LD");
  UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_PARTS, 0i64, "SD");
  UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_PARTS, 0i64, "HD");
  _(0i64);
  UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_PREFAB_DATA, 0i64, 0i64);
  UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_PREFAB_DATA, 0i64, "LD");
  UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_PREFAB_DATA, 0i64, "SD");
  UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_PREFAB_DATA, 0i64, "HD");
  _(0i64);
  v7 = UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_WORLD, "Game", 0i64);
  _(0i64);
  if ( !gForceLowRes )
    UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_WORLD, "Game", "HD");
  _(0i64);
  UFG::BigFileLogic::MountSystemBigFile(UFG::BigFileLogic::SYSTEM_WORLD, "Game", "HD2");
  _(0i64);
  if ( v0 )
  {
    v8 = UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_BOOT, 0i64);
    if ( v8 )
    {
      if ( !v1
        || v8 != (unsigned int)UFG::BigFileLogic::GetBigFileMode(
                                 (const char *)&UFG::BigFileLogic::SYSTEM_GLOBAL->mEnableStereo,
                                 0i64)
        || !v2
        || v8 != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_UI, 0i64)
        || !v3
        || v8 != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_VEHICLES, 0i64)
        || !v4
        || v8 != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_CHARACTERS, 0i64)
        || !v5
        || v8 != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_ANIMATION, 0i64)
        || !v6
        || v8 != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_NISANIMATION, 0i64)
        || !v7
        || v8 != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_WORLD, "Game") )
      {
        UFG::BigFileLogic::UnmountSystemBigFile(UFG::BigFileLogic::SYSTEM_BOOT, 0i64);
      }
    }
  }
}

// File Line: 2422
// RVA: 0x4260D0
void RenderChangeTexturePack(void)
{
  UFG::DataStreamer *v0; // rcx
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-78h]

  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  UFG::DataStreamer::DisableSpreadedUnload(v0);
  gIsHDWorldTextures = outSettings.mTextureDetailLevel == 2;
  UFG::SectionChooser::BeginFlush(1);
}

// File Line: 2438
// RVA: 0x426110
void __fastcall RenderSimOcclusionQueriesCallback(UFG::RenderContext *render_context, Render::View *view)
{
  Render::View *v2; // rbx
  UFG::SimAsyncOcclusionQueryManager *v3; // rax

  v2 = view;
  v3 = UFG::SimAsyncOcclusionQueryManager::Get();
  if ( v3 )
    UFG::SimAsyncOcclusionQueryManager::UpdateQueries(v3, v2);
}

// File Line: 2482
// RVA: 0x425AB0
signed __int64 __fastcall MapSystemLanguageToLanguageGameSupports(UFG::UILanguages::eLanguage systemLang)
{
  signed __int64 result; // rax

  switch ( systemLang )
  {
    case eLang_English:
    case eLang_French:
    case eLang_German:
    case eLang_Italian:
    case eLang_Polish:
    case eLang_Russian:
    case eLang_Spanish:
    case eLang_Spanish_US:
      result = systemLang;
      break;
    case eLang_French_CA:
      result = 10i64;
      break;
    default:
      result = 7i64;
      break;
  }
  return result;
}

// File Line: 2516
// RVA: 0x421470
signed __int64 __usercall InitGameSystems@<rax>(hkEntitySelectorAll *a1@<rcx>, hkpEntity *a2@<rdx>, float a3@<xmm0>)
{
  UFG::qNode<UFG::qString,UFG::qString> *v3; // rax
  __int64 v4; // rdi
  unsigned int v5; // ebx
  unsigned int v6; // edx
  fastdelegate::FastDelegate<bool __cdecl(UFG::qString *)> *v7; // rcx
  AMD_HD3D *v8; // rcx
  UFG::qString *v9; // rax
  DNA::Database *v10; // rax
  UFG::StreamingMemory *v11; // rcx
  Render *v12; // rcx
  AMD_HD3D *v13; // rcx
  UFG::OnlineManager *v14; // rax
  UFG::OSuiteManager *v15; // rax
  MinimumDistanceTask *v16; // rax
  AMD_HD3D *v17; // rax
  AMD_HD3D *v18; // rax
  UFG *v19; // rcx
  UFG::DataStreamer *v20; // rcx
  unsigned __int64 v21; // rsi
  bool v22; // al
  bool v23; // bl
  bool v24; // di
  int v25; // edx
  int v26; // er8
  hkGeometryUtils::IVertices *v27; // rcx
  hkgpIndexedMesh::EdgeBarrier *v28; // rcx
  int v29; // edx
  int v30; // er8
  int v31; // er8
  int v32; // er8
  int v33; // er8
  int v34; // er8
  int v35; // er8
  int v36; // er8
  int v37; // er8
  int v38; // er8
  int v39; // er8
  int v40; // er8
  Region v41; // ebx
  __int64 v42; // rcx
  UFG::UILanguages::eLanguage v43; // edi
  UFG::UILanguages::eLanguage v44; // esi
  AMD_HD3D *v45; // rcx
  UFG *v46; // rcx
  UFG::OSuiteLeaderboardManager *v47; // rax
  AMD_HD3D *v48; // rcx
  UFG *v49; // rcx
  UFG::qString *v50; // rax
  AMD_HD3D *v51; // rcx
  UFG::PartDatabase *v52; // rax
  AMD_HD3D *v53; // rcx
  AMD_HD3D *v54; // rcx
  UFG::OnlineEventManager *v55; // rcx
  UFG *v56; // rcx
  int v57; // edx
  UFG::SectionChooser::Lookahead *v58; // rax
  UFG::GameStatTracker *v59; // rax
  UFG *v60; // rcx
  UFG::TimeOfDayManager *v61; // rax
  UFG::TimeOfDayManager *v62; // rbx
  UFG::qResourceInventory *v63; // rax
  UFG::qResourceWarehouse *v64; // rax
  UFG::TimeOfDayManager *v65; // rbx
  UFG::qResourceInventory *v66; // rax
  UFG::qResourceWarehouse *v67; // rax
  CullManager *v68; // rax
  UFG *v69; // rcx
  UFG *v70; // rcx
  UFG::qMemoryPool *v71; // rax
  UFG::allocator::free_link *v72; // rax
  UFG::SimComponent *v73; // rax
  UFG::qMemoryPool *v74; // rax
  UFG::allocator::free_link *v75; // rax
  UFG::SimComponent *v76; // rax
  UFG::qMemoryPool *v77; // rax
  UFG::allocator::free_link *v78; // rax
  UFG::SimComponent *v79; // rax
  UFG::qMemoryPool *v80; // rax
  UFG::allocator::free_link *v81; // rax
  UFG::SimComponent *v82; // rax
  UFG::qMemoryPool *v83; // rax
  UFG::allocator::free_link *v84; // rax
  UFG::SimComponent *v85; // rax
  UFG *v86; // rcx
  signed int v87; // er8
  char **v88; // r9
  EnumList<unsigned long> **v89; // r11
  signed int v90; // er10
  signed int v91; // ecx
  char *v92; // rax
  int v93; // edx
  UFG::UIScreenTextureManager *v94; // rbx
  UFG::UIScreenManager *v95; // rax
  UFG::UIScreenManager *v96; // rax
  UIHKGFxTranslator *v97; // rax
  UFG::UIGfxTranslator *v98; // rax
  UFG::UIGfxTranslator *v99; // rdi
  UFG::UIScreenManager *v100; // rbx
  Scaleform::Render::RenderBuffer *v101; // rcx
  UFG::UIScreenTextureManager *v102; // rax
  int v103; // edx
  hkGeometryUtils::IVertices *v104; // rcx
  int v105; // er8
  UFG::TiDo *v106; // rax
  UFG::TiDo *v107; // rax
  AMD_HD3D *v108; // rcx
  UFG::allocator::free_link *v109; // rax
  unsigned int v110; // edi
  UFG::GameState *v111; // rax
  UFG::ProgressionTracker *v112; // rax
  UFG::GameSetup *v113; // rbx
  char *v114; // rdx
  UFG *v115; // rcx
  UFG *v116; // rcx
  UFG::qString result; // [rsp+50h] [rbp-98h]
  Render::RenderInitParams params; // [rsp+78h] [rbp-70h]
  __int64 v120; // [rsp+108h] [rbp+20h]
  Render::RenderCallbacks v121; // [rsp+118h] [rbp+30h]
  Render::RenderOutputParams v122; // [rsp+188h] [rbp+A0h]
  UFG::qString v123; // [rsp+1F8h] [rbp+110h]
  UFG::qString v124; // [rsp+220h] [rbp+138h]
  UFG::qInitParams init_params; // [rsp+248h] [rbp+160h]
  Render::RenderCallbacks render_callbacks; // [rsp+278h] [rbp+190h]
  char *visual_treatment_name; // [rsp+2E8h] [rbp+200h]
  void *v128; // [rsp+708h] [rbp+620h]

  v120 = -2i64;
  hkaReferencePoseAnimation::getNumOriginalFrames(a1, a2);
  UFG::qInitParams::qInitParams(&init_params);
  UFG::qInit(&init_params);
  UFG::qSetAssertHandler((int (*)(const char *, const char *, int, bool *, const char *, ...))HKAssertHandler);
  v3 = (UFG::qNode<UFG::qString,UFG::qString> *)fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !SkookumExtraContext )
    v3 = 0i64;
  result.mNext = v3;
  result.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)SkookumExtraContext;
  v4 = gAssertContextFuncs.size;
  v5 = gAssertContextFuncs.size + 1;
  if ( gAssertContextFuncs.size + 1 > gAssertContextFuncs.capacity )
  {
    if ( gAssertContextFuncs.capacity )
      v6 = 2 * gAssertContextFuncs.capacity;
    else
      v6 = 1;
    for ( ; v6 < v5; v6 *= 2 )
      ;
    if ( v6 - v5 > 0x10000 )
      v6 = gAssertContextFuncs.size + 65537;
    UFG::qArray<fastdelegate::FastDelegate<bool (UFG::qString *)>,0>::Reallocate(&gAssertContextFuncs, v6, "qArray.Add");
    v3 = result.mNext;
  }
  gAssertContextFuncs.size = v5;
  v7 = &gAssertContextFuncs.p[v4];
  v7->m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))v3;
  v7->m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)result.mPrev;
  UFG::qString::Set(&gCurrentLocationDirectory, &customWorldMapCaption);
  _(v8);
  InitConfig("UserOptions.xml");
  UFG::qString::qString(&v124, "TheoryEngine.PC64_");
  v9 = UFG::qGetLocalIP(&result);
  UFG::qString::operator+=(&v124, v9->mData);
  UFG::qString::~qString(&result);
  UFG::HDDmanager::Instantiate();
  UserManager::CreateInstance();
  DNA::Database::Init();
  DNA::Database::Instance();
  DNA::Database::LoadReflectionDatabase(v10, "reflection.rdb", 1);
  DNA::DNAFactory::Init();
  UFG::qMemoryPool::Init(
    &gPhysicsMemoryPool,
    "PhysicsAnimMemoryPool",
    g_HK_PhysicsMemoryPoolSize,
    g_HK_PhysicsMemoryPoolSize_Small,
    1,
    1u,
    UFG::gMainMemoryPool,
    1,
    1);
  UFG::StreamingMemory::InitPcCPUPools(v11);
  UFG::PhysicsSystem::InitializeMemory();
  UFG::qTaskManager::Init(&UFG::gTaskManager, qTaskThreadInit, qTaskThreadClose);
  Render::RenderCallbacks::RenderCallbacks(&render_callbacks);
  render_callbacks.mRenderWorldFunc = UFG::RenderWorld::RenderWorldClearScreen;
  Render::SetRenderCallbacks(&render_callbacks);
  Render::RenderCallbacks::RenderCallbacks(&v121);
  v121.mRenderThreadSyncPointFunc = (void (__fastcall *)())UFG::RenderWorld::RenderThreadSyncUpdate;
  v121.mUpdateWorldFunc = (bool (__fastcall *)(float))MainUpdateGameSystems;
  v121.mRenderWorldFunc = UFG::RenderWorld::RenderWorldCallback;
  v121.mRenderSim = UFG::RenderSim;
  v121.mRenderSimDebug = (void (__fastcall *)(UFG::RenderContext *, Render::View *))_;
  v121.mRenderSimDebugOverlay = UFG::RenderSimDebugOverlay;
  v121.mChangeTexturePackFunc = (void (__fastcall *)())RenderChangeTexturePack;
  v121.mRenderSimOcclusionQueries = RenderSimOcclusionQueriesCallback;
  if ( gRunPCRemotely )
  {
    gUsePCController = 0;
    v121.mRenderWorldFunc = 0i64;
  }
  Render::RenderInitParams::RenderInitParams(&params);
  params.mFrameMemoryTotalBytes = g_HK_FrameMemoryTotalSize;
  params.mFrameWriteMemoryTotalBytes = g_HK_FrameWriteTotalSize;
  params.mPrimitiveFrameWriteMemoryTotalBytes = g_HK_PrimitiveFrameWriteTotalSize;
  params.mFramePatchMemoryTotalBytes = g_HK_FramePatchTotalSize;
  params.mFrameIndexMemoryTotalBytes = g_HK_FrameIndexTotalSize;
  params.mTitleName = "Sleeping Dogs: Definitive Edition[PC64-Ship]";
  *(_DWORD *)&params.mIconResourceId = 6684773;
  Render::RenderOutputParams::RenderOutputParams(&v122);
  if ( UFG::GameStatPCDisplaySettings::LoadFromXML(
         (UFG::GameStatPCDisplaySettings *)&v122,
         UFG::GameStatPCDisplaySettings::gDefaultSavePath) )
  {
    params.mRenderOutputParams = v122;
    a3 = *(float *)&v122.mTextureFilterQuality;
    gIsHDWorldTextures = v122.mTextureDetailLevel == 2;
    gExtendedMidground = _mm_cvtsi128_si32(*(__m128i *)&v122.mLODSetting) > 1;
    goto LABEL_21;
  }
  if ( UFG::qString::operator==(&gDebugResolution, "1920x1080") )
  {
    params.mRenderOutputParams.mDisplayMode.mBackBufferWidth = 1920;
    params.mRenderOutputParams.mDisplayMode.mBackBufferHeight = 1080;
  }
  else
  {
    if ( !UFG::qString::operator==(&gDebugResolution, "1440x1080") )
      goto LABEL_21;
    params.mRenderOutputParams.mDisplayMode.mBackBufferWidth = 1600;
    params.mRenderOutputParams.mDisplayMode.mBackBufferHeight = 900;
  }
  params.mRenderOutputParams.mDisplayMode.mScanlineMode = -1;
LABEL_21:
  Illusion::Engine::Init(&Illusion::gEngine);
  Render::InitStateParams(v12);
  Render::InitEngine(&params);
  UFG::RenderWorldState::Init();
  Render::View::InitShared();
  gValidDisplayOptionsOnStartup = Render::ValidateDisplaySettings(&params.mRenderOutputParams);
  gFrameMemoryOverflowTotalBytes = g_HK_FrameMemoryOverflowTotalSize;
  gFrameMemoryOverflowBuffer = (char *)UFG::qMalloc(
                                         g_HK_FrameMemoryOverflowTotalSize,
                                         "FrameMemoryOverflowBuffer",
                                         0x8000ui64);
  AddFrameMemoryOverflow();
  UFG::CompositeDrawableComponent::SystemInit();
  _(v13);
  MountBigFiles();
  InitGlobalPools();
  v14 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::Init(v14);
  v15 = UFG::OSuiteManager::Instance();
  UFG::OSuiteManager::Init(v15);
  v16 = (MinimumDistanceTask *)UFG::OSuiteDBLogger::Instance();
  UFG::OSuiteDBLogger::Init(v16);
  v17 = (AMD_HD3D *)UFG::OSuiteTickerManager::Instance();
  _(v17);
  v18 = (AMD_HD3D *)UFG::OSuiteMessenger::Instance();
  _(v18);
  UFG::WebSystem::Init("SDHD", gProxyCredentials.mData, 1);
  UFG::DataLogger::Init();
  InitStreamingPools();
  if ( UFG::gAutoSmoketest == 1 )
    UFG::StreamFileWrapper::EnableLogging(1);
  if ( gCreateFinalBinDir )
  {
    UFG::qString::qString(&result, "data\\global\\xmlcache\\XML_CacheList.bin");
    UFG::DataStreamer::QueueStream(&handle, result.mData, DATA_ANIMATION, DEFAULT_PRIORITY, 7u, 0i64, 0i64);
    WaitForStreamer(v19);
    UFG::qString::~qString(&result);
  }
  TracksEnum<unsigned long>::Initialize("Data\\");
  TracksEnum<float>::Initialize("Data\\");
  _(0i64);
  _(0i64);
  Illusion::IEnginePlat::WaitUntilGPUDone((Illusion::IEnginePlat *)&Illusion::gEngine);
  UFG::qChunkFileSystem::Load("Data\\Shaders\\Shaders.temp.bin", 0i64, 0i64, 0i64, 0);
  UFG::qChunkFileSystem::Load("Data\\Shaders\\Shaders.perm.bin", 0i64, 0i64, 0i64, 0);
  _(0i64);
  UFG::UIAmbientMapBlipManager::getInstance(a3);
  UFG::Fingerprint::InitFingerprintSystem("Data\\Global\\ufg_sig.sig");
  params.mFrameMemoryTotalBytes = 512000;
  params.mFrameWriteMemoryTotalBytes = 512000;
  result.mData = (char *)10555311629107200i64;
  Render::DebugDrawManager::Init((Render::DebugDrawManager::InitInfo *)&params);
  UFG::QuarkProbe::Init();
  UFG::GameSetup::msProject = 0;
  _(0i64);
  UFG::DataStreamer::Initialize(v20);
  _((AMD_HD3D *)2);
  _(0i64);
  if ( !gDiskLine )
  {
    v21 = -1i64;
    v22 = UFG::qFileExists((const char *)&stru_141787D48);
    v23 = v22;
    v24 = UFG::gBuildingBigFiles;
    if ( !UFG::gBuildingBigFiles && v22 )
      v21 = UFG::qGetFileChecksum64((const char *)&stru_141787D48, 0xFFFFFFFFFFFFFFFFui64);
    Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
      (hkgpIndexedMesh::EdgeBarrier *)v24,
      (hkgpIndexedMeshDefinitions::Edge *)0x30000000);
    if ( !v24 )
    {
      if ( !v23 )
      {
LABEL_35:
        LOBYTE(v25) = 1;
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789DD8, v25, v26);
        LOBYTE(v29) = 1;
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789DE8, v29, v30);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789DF8, 0, v31);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E08, 0, v32);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E14, 0, v33);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E20, 0, v34);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E48, 0, v35);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E70, 0, v36);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E98, 0, v37);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789EC0, 0, v38);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789EE8, 0, v39);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789F10, 0, v40);
        goto LABEL_36;
      }
      if ( v21 != UFG::qGetFileChecksum64((const char *)&stru_141787D48, 0xFFFFFFFFFFFFFFFFui64) )
      {
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v27, v25, v26);
        LOBYTE(v28) = 1;
        Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          v28,
          (hkgpIndexedMeshDefinitions::Edge *)0x30000000);
      }
    }
    if ( v23 )
    {
      LOBYTE(v25) = 1;
      Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141787D48, v25, v26);
    }
    goto LABEL_35;
  }
LABEL_36:
  UFG::TicketBoothManager::Initialize();
  UFG::HotSwapFileManager::SetEnabled(0);
  _(0i64);
  Render::SetRenderCallbacks(&v121);
  v41 = GetSystemRegion();
  v43 = (unsigned int)UFG::UIGfxTranslator::getSystemLanguage(v42);
  v44 = (unsigned int)MapSystemLanguageToLanguageGameSupports(v43);
  UFG::UIScreenTextureManager::Init(g_HK_UIVRamMemoryPoolSize);
  DisplayLegalLoadScreen(v43, v44, v41);
  _(v45);
  _(0i64);
  UFG::LightGroupComponent::LoadLightGroupCache();
  UFG::CreateAndRegisterGameStates(v46);
  UFG::GeographicalLayerManager::GetInstance();
  UFG::PropertySetManager::Init(0i64);
  UFG::PropertySetManager::SetRootPath("Data\\CheckedIn\\Common\\Data\\PropertySets\\");
  _(0i64);
  LoadGlobalPropertySets();
  _(0i64);
  v47 = UFG::OSuiteLeaderboardManager::Instance();
  UFG::OSuiteLeaderboardManager::Init(v47);
  UFG::EventDispatcher::Initialize(&UFG::EventDispatcher::mInstance);
  UFG::SkookumMgr::Init();
  _(v48);
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\PhysicsProperties.perm.bin", 0i64, 0, 0i64, 0i64, 0i64);
  _(0i64);
  UFG::PhysicsSystem::Initialize(v49);
  v50 = UFG::qGetDirectory(&result);
  UFG::qString::FormatEx(&v123, "%s\\Data\\", v50->mData);
  UFG::qString::~qString(&result);
  MemberMapFileManager::Init(v123.mData);
  _(0i64);
  ActionNode::Init();
  UFG::CoverDataInventory::Initialize();
  UFG::AnimationResource::Initialize();
  _(0i64);
  WeightSetDataBase::Init();
  _(0i64);
  Skeleton::Init();
  _(0i64);
  UELFragmentDatabase::Quit();
  AnimationDataBase::Init();
  BlendTreeDataBase::Init();
  PoseCache::Init(0i64);
  RigInfoDataBase::Init();
  _(0i64);
  AnimationNode::Init();
  _(0i64);
  NISManager::Init();
  _(0i64);
  PoseTaskSubmission::Init();
  UFG::RadarSystem::Init();
  _(0i64);
  UFG::WorldEffectsManager::Init();
  _(0i64);
  _(v51);
  _(0i64);
  UFG::SpawnResourceInfoCache::Init();
  _(0i64);
  UFG::TrueCrowdDataBase::Init();
  _(0i64);
  UFG::WeaponManager::Init();
  _(0i64);
  UFG::PropSpawnManager::Init();
  _(0i64);
  UFG::PartDatabase::Init();
  v52 = UFG::PartDatabase::Instance();
  UFG::PartDatabase::InitPool(v52);
  _(0i64);
  UFG::ObjectResourceManager::Init();
  _(0i64);
  UFG::PartCompositeBuilder::Init();
  _(0i64);
  UFG::CustomizeBindings::InitBindings();
  UFG::ActionTreeComponentBase::Init();
  _(0i64);
  UFG::NearbyCharacterManager::CreateInstance();
  _(0i64);
  UFG::BattleManager::CreateInstance();
  _(0i64);
  UFG::GlobalCooldownManager::CreateInstance();
  _(0i64);
  UFG::AISidewalkGraph::Initialize();
  _(0i64);
  UFG::LocalPlayerIsInCombatManager::CreateInstance();
  _(0i64);
  UFG::WheeledVehicleManager::Create();
  _(0i64);
  UFG::VehicleEffectManager::Create();
  _(0i64);
  UFG::RaceManager::Create();
  _(0i64);
  UFG::PhotoManager::Create();
  _(0i64);
  UFG::OperationManager::CreateInstance();
  _(0i64);
  UFG::HintComponentBase::Init();
  _(0i64);
  UFG::StimulusManager::CreateInstance();
  _(0i64);
  UFG::TargetingProfiles::StaticInit();
  _(0i64);
  UFG::SubTargetingLocations::StaticInit();
  _(0i64);
  UFG::SubTargetingProfiles::StaticInit();
  _(0i64);
  UFG::TargetingSystemBaseComponent::StaticInit();
  _(0i64);
  UFG::ActionHijackProfiles::StaticInit();
  _(0i64);
  UFG::PedFormationManagerComponent::StaticInit();
  _(0i64);
  _(v53);
  _(0i64);
  _(v54);
  _(0i64);
  UFG::SimObjectWeaponPropertiesComponent::StaticInit();
  _(0i64);
  NoiseManager::Init();
  _(0i64);
  if ( !gDemoVersion )
  {
    UFG::OnlineEventManager::Initialize(v55);
    UFG::AchievementTrophyManager::Init(60);
    _(0i64);
  }
  UFG::HK_InitInput(v55);
  _(0i64);
  UFG::InputSystem::Init();
  _(0i64);
  UFG::HK_PostInputInit(v56);
  _(0i64);
  UFG::qString::qString(&result, "Data");
  LoadGlobalBins(&result);
  UFG::qString::~qString(&result);
  _(0i64);
  v57 = gDebugControllerPort;
  if ( gDebugControllerPort > 0 )
  {
    if ( !UFG::gInputSystem->mControllers[gDebugControllerPort] )
      v57 = 0;
    gDebugControllerPort = v57;
  }
  v58 = UFG::CreateRoadNetworkLookahead();
  UFG::SectionChooser::SetLookahead(v58);
  UFG::SectionChooser::SetOnZoneLayoutLoadCallback(OnZoneLayoutLoadCallback);
  v59 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::Initialize(v59);
  _(0i64);
  UFG::StatGameManager::Instantiate();
  _(0i64);
  UFG::CachedLeaderboardManager::Instance();
  UFG::StatAwardPropertyManager::Instance();
  UFG::Metrics::msInstance.mSimTimeDeltaMax = FLOAT_0_050000001;
  UFG::InitSim(v60);
  _(0i64);
  UFG::GroupManager::CreateInstance();
  _(0i64);
  UFG::PedSpawnManager::CreateInstance();
  _(0i64);
  v61 = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::Init(v61);
  v62 = UFG::TimeOfDayManager::GetInstance();
  v63 = `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result )
  {
    v64 = UFG::qResourceWarehouse::Instance();
    v63 = UFG::qResourceWarehouse::GetInventory(v64, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result = v63;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v62->mSunnyStateBlockHandle.mPrev, 0x4D04C7F2u, 0x764E403Au, v63);
  v65 = UFG::TimeOfDayManager::GetInstance();
  v66 = `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result )
  {
    v67 = UFG::qResourceWarehouse::Instance();
    v66 = UFG::qResourceWarehouse::GetInventory(v67, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>'::`2'::result = v66;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v65->mOvercastStateBlockHandle.mPrev,
    0x4D04C7F2u,
    0x8512348D,
    v66);
  _(0i64);
  Render::FXManager::Init(&Render::gFXManager, g_HK_NumFXBuffers);
  _(0i64);
  Render::ImpactManager::Init(&Render::gImpactManager);
  _(0i64);
  Render::SkyMarshall::Init(&Render::SkyMarshall::gSkyMarshall);
  _(0i64);
  Render::RainManager::Init(&Render::RainManager::gRainManager);
  _(0i64);
  UFG::VehicleEffectManager::Init(UFG::VehicleEffectManager::m_Instance);
  _(0i64);
  UFG::RenderStageTerrain::msTerrainVramSize = g_TerrainVramSize;
  UFG::RenderStageTerrain::msMaxTerrainElements = g_MaxTerrainElements;
  _(0i64);
  v68 = CullManager::Instance();
  CullManager::Init(v68, 0i64);
  _(0i64);
  UFG::RenderWorld::Init();
  UFG::CreateHighlightPlugin(v69);
  UFG::CreateWireframePlugin(v70);
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&result, UFG::RenderWorld::msRenderStagePlugin, 1);
  v71 = UFG::GetSimulationMemoryPool();
  v72 = UFG::qMemoryPool::Allocate(v71, 0x58ui64, "DamagePostEffect", 0i64, 1u);
  v128 = v72;
  if ( v72 )
    UFG::DamagePostEffect::DamagePostEffect((UFG::DamagePostEffect *)v72);
  else
    v73 = 0i64;
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&result, v73, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&result, UFG::RenderWorld::msRenderStagePlugin, 1);
  v74 = UFG::GetSimulationMemoryPool();
  v75 = UFG::qMemoryPool::Allocate(v74, 0x58ui64, "GunRecoilPostEffect", 0i64, 1u);
  v128 = v75;
  if ( v75 )
    UFG::GunRecoilPostEffect::GunRecoilPostEffect((UFG::GunRecoilPostEffect *)v75);
  else
    v76 = 0i64;
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&result, v76, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&result, UFG::RenderWorld::msRenderStagePlugin, 1);
  v77 = UFG::GetSimulationMemoryPool();
  v78 = UFG::qMemoryPool::Allocate(v77, 0x250ui64, "VisualTreatmentPostEffect", 0i64, 1u);
  v128 = v78;
  if ( v78 )
    UFG::VisualTreatmentPostEffect::VisualTreatmentPostEffect((UFG::VisualTreatmentPostEffect *)v78);
  else
    v79 = 0i64;
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&result, v79, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&result, UFG::RenderWorld::msRenderStagePlugin, 1);
  v80 = UFG::GetSimulationMemoryPool();
  v81 = UFG::qMemoryPool::Allocate(v80, 0x58ui64, "AccumulationBufferPostEffect", 0i64, 1u);
  v128 = v81;
  if ( v81 )
    UFG::AccumulationBufferPostEffect::AccumulationBufferPostEffect((UFG::AccumulationBufferPostEffect *)v81);
  else
    v82 = 0i64;
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&result, v82, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&result, UFG::RenderWorld::msRenderStagePlugin, 1);
  v83 = UFG::GetSimulationMemoryPool();
  v84 = UFG::qMemoryPool::Allocate(v83, 0x68ui64, "FrontEndPauseEffect", 0i64, 1u);
  v128 = v84;
  if ( v84 )
    UFG::FrontEndPauseEffect::FrontEndPauseEffect((UFG::FrontEndPauseEffect *)v84);
  else
    v85 = 0i64;
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&result, v85, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&result);
  UFG::CreateAltColorPlugin(v86);
  UFG::SetAltColorEffectActiveGlobally(1);
  UFG::EnableAltColorEffect(0);
  UFG::TerrainCollisionManager::Initialize();
  Render::Skinning::RegisterUserSkinningTask(
    &Render::Skinning::gSkinning,
    0x9EBC315A,
    0i64,
    &gTaskFunctionDeclData_SkinVehicleBufferTask,
    0i64,
    0i64,
    &gTaskFunctionDeclData_SkinVehicleDecalBufferTask);
  Render::Skinning::RegisterUserSkinningTask(
    &Render::Skinning::gSkinning,
    0xADE348E5,
    0i64,
    &gTaskFunctionDeclData_SkinVehicleGlassBufferTask,
    0i64,
    0i64,
    0i64);
  Render::Skinning::RegisterUserSkinningTask(
    &Render::Skinning::gSkinning,
    0xCEE200FC,
    &gTaskFunctionDeclData_SkinDamageBufferTask,
    &gTaskFunctionDeclData_MorphSkinDamageBufferTask,
    0i64,
    0i64,
    0i64);
  Render::Skinning::RegisterUserSkinningTask(
    &Render::Skinning::gSkinning,
    0x3C1D8CA0u,
    &gTaskFunctionDeclData_SkinDamageBufferTask,
    &gTaskFunctionDeclData_MorphSkinDamageBufferTask,
    0i64,
    0i64,
    0i64);
  Render::Skinning::RegisterUserSkinningTask(
    &Render::Skinning::gSkinning,
    0x2D2AC914u,
    &gTaskFunctionDeclData_SkinDamageBufferTask,
    &gTaskFunctionDeclData_MorphSkinDamageBufferTask,
    0i64,
    0i64,
    0i64);
  Render::Skinning::RegisterUserSkinningTask(
    &Render::Skinning::gSkinning,
    0x5941E056u,
    &gTaskFunctionDeclData_OceanSkinBufferTask,
    0i64,
    0i64,
    0i64,
    0i64);
  v87 = 0;
  v88 = &visual_treatment_name;
  v89 = gVisualTreatmentEnum.m_enumLists.p;
  v90 = gVisualTreatmentEnum.m_enumLists.size;
  while ( 1 )
  {
    v91 = v90 < 0 ? 0 : (*v89)->m_enumName.size;
    if ( v87 >= v91 )
      break;
    if ( v90 < 0 )
      v92 = 0i64;
    else
      v92 = (*v89)->m_enumName.p[v87];
    *v88 = v92;
    ++v87;
    ++v88;
  }
  if ( v90 < 0 )
    v93 = 0;
  else
    v93 = (*v89)->m_enumName.size;
  UFG::VisualTreatmentPostEffect::StaticInit((const char **)&visual_treatment_name, v93);
  UFG::UIHKTweakables::Initialize();
  UFG::UITiledMapTweakables::Initialize();
  _(0i64);
  UFG::UIHKScreenHud::Initialize();
  _(0i64);
  v94 = UFG::UIScreenTextureManager::Instance();
  v95 = (UFG::UIScreenManager *)UFG::qMemoryPool::Allocate(
                                  &gScaleformMemoryPool,
                                  0x320ui64,
                                  "UIScreenManager::UIScreenManager",
                                  0i64,
                                  1u);
  v128 = v95;
  if ( v95 )
    UFG::UIScreenManager::UIScreenManager(v95, (UFG::UIScreenFactory *)&v94->vfptr);
  else
    v96 = 0i64;
  UFG::UIScreenManager::s_instance = v96;
  v97 = (UIHKGFxTranslator *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                               Scaleform::Memory::pGlobalHeap,
                               20632ui64,
                               0i64);
  v128 = v97;
  if ( v97 )
  {
    UIHKGFxTranslator::UIHKGFxTranslator(v97);
    v99 = v98;
  }
  else
  {
    v99 = 0i64;
  }
  v100 = UFG::UIScreenManager::s_instance;
  v101 = (Scaleform::Render::RenderBuffer *)UFG::UIScreenManager::s_instance->m_translator;
  if ( v101 )
    Scaleform::RefCountImpl::Release(v101);
  v100->m_translator = v99;
  UFG::UIGfxTranslator::init(v99, v100->m_screenFactory, v100->m_gfxMovieLoader);
  UFG::UIGfxTranslator::setLanguage(v100->m_translator, eLang_English, 1);
  UFG::UIScreenManager::s_instance->mScaleViewportInCode = 1;
  ((void (*)(void))UFG::UIScreenManager::s_instance->vfptr->update)();
  _(0i64);
  UFG::UIScreenManager::s_instance->m_DisplayChangeCallback = UFG::UI::DisplayChangeCallback;
  _(0i64);
  UFG::UIScreenManager::s_instance->m_gfxFileOpener->vfptr[4].__vecDelDtor(
    (Scaleform::RefCountImplCore *)UFG::UIScreenManager::s_instance->m_gfxFileOpener,
    (unsigned int)"Global.BIN");
  UFG::UIGfxTranslator::setLanguage(UFG::UIScreenManager::s_instance->m_translator, v44, 1);
  UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "Global");
  UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "Front-End");
  v102 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v102, "GlobalOverlay", 0i64);
  UFG::TidoGame::CreateInstance(v104, v103, v105);
  if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
  {
    v106 = UFG::TiDo::GetInstance();
    v106->vfptr->Init(v106);
  }
  v107 = UFG::TiDo::GetInstance();
  UFG::TiDo::LoadEventSymbols(v107);
  _(v108);
  _(0i64);
  UFG::qMemoryPool::Init(&gAntlrMemoryPool, "AntlrParser", 1572864i64, 0x80000, 1, 1u, UFG::gMainMemoryPool, 1, 1);
  v109 = UFG::qMemoryPool::Allocate(UFG::gMainMemoryPool, 0x8C8C000ui64, "VideoBroadcast", 0i64, 1u);
  UFG::qMemoryPool::Init(&gVideoBroadcastMemoryPool, "VideoBroadcast", v109, 147374080i64, 0x200000, 1, 1u, 0i64, 1, 1);
  v110 = uidGameStateFE_5;
  if ( UFG::gUIBootModeSkipFE || UFG::gAutoSmoketest || gAutoBenchmarkMode )
  {
    v110 = uidGameStateLoadGame_5;
    if ( gAutoBenchmarkMode )
    {
      UFG::qStringCopy(gameSetupStr, 100, "gameSetupGame_Calibration", -1);
      v111 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, uidGameStateLoadGame_5);
      if ( v111 )
        UFG::qString::Set(&v111->mGameStateUserDataStr, gameSetupStr);
    }
    v112 = UFG::ProgressionTracker::Instance();
    v113 = UFG::ProgressionTracker::GetGameSetup(v112);
    UFG::GameSetup::SetDebugSaveGame(v113, "Empty");
    v114 = UFG::gSmoketestStartTrack.mData;
    if ( !UFG::gTestLevelTest )
      v114 = StartTrack.mData;
    UFG::GameSetup::SetLocationDir(v113, v114);
  }
  _(0i64);
  if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, v110) )
    SetUpCameraForFERender(v115);
  DebugTestInit();
  _(0i64);
  if ( !(`UFG::qStaticInitAllocator::Instance'::`2'::`local static guard' & 1) )
  {
    `UFG::qStaticInitAllocator::Instance'::`2'::`local static guard' |= 1u;
    UFG::qStaticInitAllocator::qStaticInitAllocator(&`UFG::qStaticInitAllocator::Instance'::`2'::instance);
    atexit(`UFG::qStaticInitAllocator::Instance'::`2'::`dynamic atexit destructor for 'instance'');
  }
  UFG::qStaticInitAllocator::Done(&`UFG::qStaticInitAllocator::Instance'::`2'::instance);
  InitGameSystems_Stage2();
  UFG::MemoryUtil_MarkAllPools(v116);
  while ( !UFG::LoadingLogic::HasRequiredScreensFinished(&UFG::gLoadingLogic) )
    UFG::qSleep(1u);
  UFG::LoadingLogic::StopLoadScreen(&UFG::gLoadingLogic, 0.0);
  UFG::qString::~qString(&v123);
  UFG::qString::~qString(&v124);
  return 1i64;
}

// File Line: 3547
// RVA: 0x4228E0
signed __int64 __fastcall InitGameSystems_Stage2()
{
  ActionNode *v0; // rbx
  AnimationDataBase *v1; // rax
  AnimationDataBase *v2; // rax

  if ( once_2 )
  {
    v0 = ActionNode::smRoot;
    once_2 = 0;
    if ( ActionNode::smRoot )
      ActionNode::BeginDeferredResolve(ActionNode::smRoot);
    UFG::ActionTreeComponentBase::BeginDeferredResolve();
    UFG::UELRuntime::Init();
    UFG::qMemoryPool2::DoneWithLinearAllocations(&gActionTreeMemoryPool);
    LoadBinaryACTandABKFiles();
    ActionNodePlayableDataBase::Init();
    v1 = AnimationDataBase::GetInstance();
    AnimationDataBase::ResolveFallbackAnimations(v1);
    _(0i64);
    if ( v0 )
      ActionNode::EndDeferredResolve(v0);
    UFG::ActionTreeComponentBase::EndDeferredResolve();
    _(0i64);
    RigInfoDataBase::PreLoad();
    _(0i64);
    UFG::PredictiveStreamingStats::CreateInstance();
    _(0i64);
    UFG::PredictiveStreaming::CreateInstance();
    _(0i64);
    v2 = AnimationDataBase::GetInstance();
    AnimationDataBase::BindStaticGroups(v2);
    _(0i64);
    UFG::qMemoryPool2::DoneWithLinearAllocations(&gActionTreeMemoryPool);
    UFG::InterestPoint::StaticInit();
    _(0i64);
    UFG::ItemProfiles::InitItemProfiles();
    _(0i64);
  }
  return 1i64;
}

// File Line: 3644
// RVA: 0x4204F0
signed __int64 __fastcall CloseGameSystems()
{
  AMD_HD3D *v0; // rcx
  AMD_HD3D *v1; // rcx
  UFG::OnlineEventManager *v2; // rcx
  AMD_HD3D *v3; // rcx
  AMD_HD3D *v4; // rcx
  UFG::OSuiteMessenger *v5; // rax
  UFG::OSuiteLeaderboardManager *v6; // rax
  UFG::OSuiteTickerManager *v7; // rax
  UFG::OSuiteDBLogger *v8; // rax
  UFG::OSuiteManager *v9; // rax
  UFG::OnlineManager *v10; // rax
  UFG *v11; // rcx

  UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "Front-End");
  UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "Global");
  UFG::UIScreenManager::s_instance->m_gfxFileOpener->vfptr[5].__vecDelDtor(
    (Scaleform::RefCountImplCore *)UFG::UIScreenManager::s_instance->m_gfxFileOpener,
    (unsigned int)"Global.BIN");
  UFG::UIScreenTextureManager::Quit();
  _((AMD_HD3D *)&Render::SkyMarshall::gSkyMarshall);
  Render::RainManager::Close(&Render::RainManager::gRainManager);
  _((AMD_HD3D *)&Render::gImpactManager);
  PoseTaskSubmission::Destroy();
  NISManager::Quit();
  _(v0);
  UELFragmentDatabase::Quit();
  UFG::ActionTreeComponentBase::DeleteAllMemory();
  UFG::UELRuntime::Shutdown();
  UFG::SkookumMgr::Deinit();
  CloseRenderEngine();
  UFG::StimulusManager::DestroyInstance();
  UFG::LocalPlayerIsInCombatManager::DeleteInstance();
  UFG::NearbyCharacterManager::DeleteInstance();
  UFG::BattleManager::DeleteInstance();
  UFG::GlobalCooldownManager::DeleteInstance();
  UFG::PredictiveStreaming::DeleteInstance();
  UFG::PredictiveStreamingStats::DeleteInstance();
  UFG::ObjectResourceManager::Quit();
  UFG::PartCompositeBuilder::Quit();
  UFG::PartDatabase::Quit();
  UFG::PropSpawnManager::DeInit();
  UFG::WeaponManager::Destroy();
  UFG::SpawnResourceInfoCache::Release();
  _(v1);
  UFG::RadarSystem::Destroy();
  UFG::InputSystem::Close();
  UFG::OnlineEventManager::Shutdown(v2);
  _(v3);
  _(v4);
  UFG::qTaskManager::Close(&UFG::gTaskManager);
  v5 = UFG::OSuiteMessenger::Instance();
  UFG::OSuiteMessenger::Shutdown(v5);
  v6 = UFG::OSuiteLeaderboardManager::Instance();
  UFG::OSuiteLeaderboardManager::Shutdown(v6);
  v7 = UFG::OSuiteTickerManager::Instance();
  UFG::OSuiteTickerManager::Shutdown(v7);
  v8 = UFG::OSuiteDBLogger::Instance();
  UFG::OSuiteDBLogger::Shutdown(v8);
  v9 = UFG::OSuiteManager::Instance();
  UFG::OSuiteManager::Shutdown(v9);
  v10 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::Shutdown(v10);
  UFG::HDDmanager::ShutDown();
  UFG::qClose(v11);
  return 1i64;
}

// File Line: 3834
// RVA: 0x424F10
char __fastcall MainUpdateGameSystems(float fRealTimeDelta)
{
  bool v1; // bl
  bool v2; // al
  bool v3; // cl
  UFG *v4; // rcx

  UFG::LoadingLogic::UpdateLoadTimers(&UFG::gLoadingLogic, fRealTimeDelta);
  UFG::FlowController::DoMainLoop(&UFG::gFlowController, fRealTimeDelta);
  v1 = (unsigned int)Render::IsLoadScreenRendering() != 0;
  v2 = UFG::UIHK_NISOverlay::IsCurtainVisible() && UFG::UIHK_NISOverlay::IsCurtainStable();
  v3 = v1 || v2;
  Render::SetVRAMDefragPerFrameLimits(v3);
  UFG::UpdateIsForcedLetterBox(v4);
  return 1;
}

