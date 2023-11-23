// File Line: 375
// RVA: 0x14FF770
__int64 dynamic_initializer_for__gCurrentLocationDirectory__()
{
  UFG::qString::qString(&gCurrentLocationDirectory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gCurrentLocationDirectory__);
}

// File Line: 376
// RVA: 0x14FF6C0
__int64 dynamic_initializer_for__currVehicle__()
{
  UFG::qString::qString(&currVehicle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__currVehicle__);
}

// File Line: 396
// RVA: 0x14FF960
__int64 dynamic_initializer_for__gPIXCaptureFileName__()
{
  UFG::qString::qString(&gPIXCaptureFileName, "e:\\test.pix2");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gPIXCaptureFileName__);
}

// File Line: 399
// RVA: 0x14FFA70
__int64 dynamic_initializer_for__gUserName__()
{
  UFG::qString::qString(&gUserName);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gUserName__);
}

// File Line: 400
// RVA: 0x14FF920
__int64 dynamic_initializer_for__gLoginPassword__()
{
  UFG::qString::qString(&gLoginPassword);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gLoginPassword__);
}

// File Line: 401
// RVA: 0x14FF9F0
__int64 dynamic_initializer_for__gSessionId__()
{
  UFG::qString::qString(&gSessionId);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gSessionId__);
}

// File Line: 402
// RVA: 0x14FF9B0
__int64 dynamic_initializer_for__gProxyCredentials__()
{
  UFG::qString::qString(&gProxyCredentials);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gProxyCredentials__);
}

// File Line: 403
// RVA: 0x14FF790
__int64 dynamic_initializer_for__gEnvironmentURL__()
{
  UFG::qString::qString(&gEnvironmentURL);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gEnvironmentURL__);
}

// File Line: 431
// RVA: 0x14FF7B0
__int64 UFG::_dynamic_initializer_for__gFlowController__()
{
  UFG::FlowController::FlowController(&UFG::gFlowController);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gFlowController__);
}

// File Line: 435
// RVA: 0x426A10
void __fastcall UFG::qUserCallback_WaitForGPU(UFG *this)
{
  if ( Illusion::gEngine.FrameMemory )
    Illusion::IEnginePlat::WaitUntilGPUDone(&Illusion::gEngine);
}

// File Line: 452
// RVA: 0x14FF9D0
__int64 dynamic_initializer_for__gScaleformMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gScaleformMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gScaleformMemoryPool__);
}

// File Line: 457
// RVA: 0x14FF940
__int64 dynamic_initializer_for__gNetworkMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gNetworkMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gNetworkMemoryPool__);
}

// File Line: 458
// RVA: 0x14FF6E0
__int64 dynamic_initializer_for__gActionTreeMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gActionTreeMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gActionTreeMemoryPool__);
}

// File Line: 459
// RVA: 0x14FF990
__int64 dynamic_initializer_for__gPropertySetMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gPropertySetMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gPropertySetMemoryPool__);
}

// File Line: 460
// RVA: 0x14FFA30
__int64 dynamic_initializer_for__gSkookumMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gSkookumMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gSkookumMemoryPool__);
}

// File Line: 461
// RVA: 0x14FFA10
__int64 dynamic_initializer_for__gSimulationMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gSimulationMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gSimulationMemoryPool__);
}

// File Line: 476
// RVA: 0x14FF7D0
__int64 dynamic_initializer_for__gHKGlobalStreams__()
{
  HKGlobalStreams::HKGlobalStreams(&gHKGlobalStreams);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gHKGlobalStreams__);
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
  stru_14207EE30.mPrev = &stru_14207EE30;
  stru_14207EE30.mNext = &stru_14207EE30;
  stru_14207EE30.mCallback = 0i64;
  stru_14207EE30.mCallbackParam = 0i64;
  stru_14207EE30.mImpl = 0i64;
  *(_DWORD *)&stru_14207EE30.mFlags = 536870915;
  stru_14207EE30._mTargetState.mValue = 1;
  stru_14207EE60.mPrev = &stru_14207EE60;
  stru_14207EE60.mNext = &stru_14207EE60;
  stru_14207EE60.mCallback = 0i64;
  stru_14207EE60.mCallbackParam = 0i64;
  stru_14207EE60.mImpl = 0i64;
  *(_DWORD *)&stru_14207EE60.mFlags = 536870915;
  stru_14207EE60._mTargetState.mValue = 1;
  unk_14207EE98 = 0i64;
  *(_QWORD *)&dword_14207EE90 = 0i64;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gHKLocationStreams__);
}

// File Line: 487
// RVA: 0x14FFA90
__int64 dynamic_initializer_for__gpc_PC_VRamMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gpc_PC_VRamMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gpc_PC_VRamMemoryPool__);
}

// File Line: 542
// RVA: 0x426590
__int64 __fastcall UFG::AgogErrorOutput::determine_choice(
        UFG::AgogErrorOutput *this,
        AErrMsg *msg,
        eAErrAction *pAction)
{
  const char *v5; // r15
  const char *i_title_p; // rdi
  char *i_desc_high_p; // rbp
  char *i_func_name_p; // r8
  char *i_desc_low_p; // r9
  const char *i_source_path_p; // rcx
  eAErrAction v11; // esi
  unsigned __int8 v12; // r14
  __int64 v13; // rbx
  unsigned int v14; // eax
  AStringRef *i_str_ref_p; // rbx
  bool v16; // zf
  AObjReusePool<AStringRef> *pool; // r8
  AObjBlock<AStringRef> *i_block_p; // rax
  unsigned __int64 i_objects_a; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AStringRef *v21; // rdx
  unsigned int i_length; // ebx
  AStringRef *v23; // rax
  unsigned int v24; // ebp
  int v25; // eax
  AStringRef *v26; // rbx
  AObjReusePool<AStringRef> *v27; // r8
  AObjBlock<AStringRef> *v28; // rax
  unsigned __int64 v29; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  AStringRef *v31; // rbx
  AObjReusePool<AStringRef> *v32; // rax
  AObjBlock<AStringRef> *v33; // rcx
  unsigned __int64 v34; // rdx
  bool v35; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v36; // rcx
  __int64 deallocate; // [rsp+20h] [rbp-868h]
  char buffer_p[2104]; // [rsp+50h] [rbp-838h] BYREF
  AString str; // [rsp+898h] [rbp+10h] BYREF
  AString result; // [rsp+8A0h] [rbp+18h] BYREF
  AString v42; // [rsp+8A8h] [rbp+20h] BYREF

  v5 = 0i64;
  if ( msg->i_err_level )
  {
    i_title_p = "Error";
    v5 = "\n"
         "Choose:\n"
         "  Abort  - break into C++ & get callstack [then ignore on continue]\n"
         "  Retry  - attempt recovery/ignore [still tests this assert in future]\n"
         "  Ignore - recover/ignore always [auto-ignores this assert in future]";
  }
  else
  {
    i_title_p = "Internal recoverable exception";
  }
  if ( msg->i_title_p )
    i_title_p = msg->i_title_p;
  AString::AString(&str, buffer_p, 0x800u, 0, 0);
  i_desc_high_p = "An error has occurred.";
  if ( msg->i_desc_high_p )
    i_desc_high_p = (char *)msg->i_desc_high_p;
  i_func_name_p = &customCaption;
  i_desc_low_p = &customCaption;
  if ( msg->i_desc_low_p )
    i_desc_low_p = (char *)msg->i_desc_low_p;
  if ( msg->i_func_name_p )
    i_func_name_p = (char *)msg->i_func_name_p;
  i_source_path_p = msg->i_source_path_p;
  if ( i_source_path_p )
  {
    LODWORD(deallocate) = msg->i_source_line;
    AString::format(
      &str,
      "\n\n  C++ Internal Info:\n    %s\n    %s(%u) :\n    %s\n",
      i_func_name_p,
      i_source_path_p,
      deallocate,
      i_desc_low_p);
  }
  else
  {
    AString::format(&str, "\n\n  C++ Internal Info:\n    %s\n    %s\n", i_func_name_p, i_desc_low_p);
  }
  ADebug::context_string(&result);
  ADebug::print_format("\n###%s : ", i_title_p);
  ADebug::print(i_desc_high_p, 1);
  ADebug::print((AMD_HD3D *)&str, 1);
  ADebug::print((AMD_HD3D *)&result, 1);
  v11 = AErrAction_ignore;
  v12 = 0;
  if ( v5 )
  {
    if ( UFG::gAutoSmoketest )
      goto LABEL_34;
    v13 = -1i64;
    do
      ++v13;
    while ( i_desc_high_p[v13] );
    v14 = AMemory::c_req_byte_size_func(v13 + 1);
    v42.i_str_ref_p = AStringRef::pool_new(i_desc_high_p, v13, v14, 1u, 0, 1);
    AString::insert(&str, &v42, 0);
    i_str_ref_p = v42.i_str_ref_p;
    v16 = v42.i_str_ref_p->i_ref_count-- == 1;
    if ( v16 )
    {
      if ( i_str_ref_p->i_deallocate )
        AMemory::c_free_func(i_str_ref_p->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)i_str_ref_p < i_objects_a
        || (p_i_exp_pool = &pool->i_pool, (unsigned __int64)i_str_ref_p >= i_objects_a + 24i64 * i_block_p->i_size) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
    v21 = result.i_str_ref_p;
    i_length = result.i_str_ref_p->i_length;
    if ( i_length )
    {
      v23 = str.i_str_ref_p;
      v24 = i_length + str.i_str_ref_p->i_length;
      if ( v24 >= str.i_str_ref_p->i_size || str.i_str_ref_p->i_ref_count + str.i_str_ref_p->i_read_only != 1 )
      {
        AString::set_size(&str, v24);
        v23 = str.i_str_ref_p;
        v21 = result.i_str_ref_p;
      }
      memmove(&v23->i_cstr_p[v23->i_length], v21->i_cstr_p, i_length + 1);
      str.i_str_ref_p->i_length = v24;
    }
    AString::append(&str, v5, 0xFFFFFFFF);
    v25 = MessageBoxA(0i64, str.i_str_ref_p->i_cstr_p, i_title_p, 0x10032u);
    if ( v25 == 3 )
    {
LABEL_34:
      v12 = 1;
    }
    else if ( v25 == 5 )
    {
      v11 = AErrAction_ignore_all;
    }
  }
  *pAction = v11;
  v26 = result.i_str_ref_p;
  v16 = result.i_str_ref_p->i_ref_count-- == 1;
  if ( v16 )
  {
    if ( v26->i_deallocate )
      AMemory::c_free_func(v26->i_cstr_p);
    v27 = AStringRef::get_pool();
    v28 = v27->i_block_p;
    v29 = (unsigned __int64)v28->i_objects_a;
    if ( (unsigned __int64)v26 < v29 || (p_i_pool = &v27->i_pool, (unsigned __int64)v26 >= v29 + 24i64 * v28->i_size) )
      p_i_pool = &v27->i_exp_pool;
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, v26);
  }
  v31 = str.i_str_ref_p;
  v16 = str.i_str_ref_p->i_ref_count-- == 1;
  if ( v16 )
  {
    if ( v31->i_deallocate )
      AMemory::c_free_func(v31->i_cstr_p);
    v32 = AStringRef::get_pool();
    v33 = v32->i_block_p;
    v34 = (unsigned __int64)v33->i_objects_a;
    if ( (unsigned __int64)v31 < v34
      || (v35 = (unsigned __int64)v31 < v34 + 24i64 * v33->i_size, v36 = &v32->i_pool, !v35) )
    {
      v36 = &v32->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v36, v31);
  }
  return v12;
}

// File Line: 644
// RVA: 0x426910
AgogCoreVals *__fastcall Agog::get_agog_core_vals()
{
  AgogCoreVals *result; // rax

  if ( (_S7_10 & 1) == 0 )
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
  if ( (_S8_10 & 1) == 0 )
  {
    _S8_10 |= 1u;
    s_simple_err_out.vfptr = (AErrorOutputBaseVtbl *)&UFG::AgogErrorOutput::`vftable;
    atexit(Agog::on_error_pre_::_2_::_dynamic_atexit_destructor_for__s_simple_err_out__);
  }
  return &s_simple_err_out;
}

// File Line: 743
// RVA: 0x14FF710
__int64 dynamic_initializer_for__gAssertContextFuncs__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gAssertContextFuncs__);
}

// File Line: 797
// RVA: 0x421130
__int64 HKAssertHandler(
        const char *pConditionCStr,
        const char *pFileCStr,
        __int64 line,
        bool *pIgnoreAlways,
        const char *pMsgCStr,
        ...)
{
  int v6; // r12d
  const char *v8; // rsi
  unsigned int v9; // edi
  int v10; // r15d
  fastdelegate::FastDelegate<bool __cdecl(UFG::qString *)> *p; // rbx
  fastdelegate::FastDelegate<bool __cdecl(UFG::qString *)> *v12; // rsi
  unsigned __int64 v13; // rdx
  __int64 v14; // rcx
  signed __int64 v15; // rcx
  void *v16; // rsp
  void *v17; // rsp
  int v18; // eax
  int v19; // eax
  UFG::qString v21; // [rsp+40h] [rbp+0h] BYREF
  __int64 v22; // [rsp+68h] [rbp+28h]
  char dest[2112]; // [rsp+70h] [rbp+30h] BYREF
  va_list va; // [rsp+8E8h] [rbp+8A8h] BYREF

  va_start(va, pMsgCStr);
  v22 = -2i64;
  v6 = line;
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
  dest[0] = 0;
  if ( pMsgCStr )
    v10 = UFG::qVSPrintf(dest, 2048, pMsgCStr, va);
  UFG::qString::qString(&v21);
  if ( gAssertContextFuncs.size )
  {
    p = gAssertContextFuncs.p;
    v12 = &gAssertContextFuncs.p[gAssertContextFuncs.size];
    if ( gAssertContextFuncs.p < v12 )
    {
      do
      {
        ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::qString *))p->m_Closure.m_pFunction)(
          p->m_Closure.m_pthis,
          &v21);
        ++p;
      }
      while ( p < v12 );
    }
    v8 = pConditionCStr;
  }
  if ( !pIgnoreAlways || UFG::gAutoSmoketest )
    goto LABEL_15;
  v13 = (unsigned int)(v10 + v21.mLength + 512);
  v14 = v13 + 15;
  if ( v13 + 15 <= v13 )
    v14 = 0xFFFFFFFFFFFFFF0i64;
  v15 = v14 & 0xFFFFFFFFFFFFFFF0ui64;
  v16 = alloca(v15);
  v17 = alloca(v15);
  UFG::qSPrintf(
    (char *)&v21,
    v13,
    "Data Assert Failed!\nFile      :   %s\nLine      :   %d\nCondition :  %s\nMessage   :  %s\n%s\n",
    pFileCStr,
    v6,
    v8,
    dest,
    v21.mData);
  v18 = MessageBoxA(0i64, (LPCSTR)&v21, "Assert Failed!", 0x12032u) - 3;
  if ( !v18 )
    goto LABEL_15;
  v19 = v18 - 1;
  if ( v19 )
  {
    if ( v19 == 1 )
    {
      *pIgnoreAlways = 1;
      goto LABEL_16;
    }
LABEL_15:
    v9 = 1;
  }
LABEL_16:
  UFG::qString::~qString(&v21);
  return v9;
}

// File Line: 880
// RVA: 0x426320
__int64 __fastcall SkookumExtraContext(UFG::qString *pStr)
{
  unsigned __int8 v2; // di
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v8; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString str_p; // [rsp+48h] [rbp+10h] BYREF

  str_p.i_str_ref_p = AStringRef::get_empty();
  ++str_p.i_str_ref_p->i_ref_count;
  if ( ADebug::context_append(&str_p) )
  {
    UFG::qString::append(pStr, str_p.i_str_ref_p->i_cstr_p, str_p.i_str_ref_p->i_length);
    v2 = 1;
  }
  else
  {
    v2 = 0;
  }
  i_str_ref_p = str_p.i_str_ref_p;
  if ( str_p.i_str_ref_p->i_ref_count-- == 1 )
  {
    if ( i_str_ref_p->i_deallocate )
      AMemory::c_free_func(i_str_ref_p->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)i_str_ref_p < i_objects_a
      || (v8 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool,
                                                                                        !v8) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
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
UFG::allocator::free_link *__fastcall LoadTexturePackHK(
        const char *perm_filename,
        UFG::StreamingMemory::DATA_TYPE eDataType)
{
  UFG::allocator::free_link *v4; // rsi
  unsigned int v5; // ebx
  unsigned int v6; // edi
  __int64 v7; // r15
  unsigned int v8; // ebp
  unsigned __int64 v9; // rax
  UFG::allocator::free_link *v10; // r14
  char *v11; // rdx

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
  UFG::DataStreamer::QueueStream(
    (UFG::DataStreamer::Handle *)v4,
    perm_filename,
    eDataType,
    DEFAULT_PRIORITY,
    3u,
    0i64,
    0i64);
  v7 = dword_14207EE90;
  v8 = dword_14207EE90 + 1;
  if ( dword_14207EE90 + 1 <= unk_14207EE94 )
    goto LABEL_21;
  if ( unk_14207EE94 )
    v5 = 2 * unk_14207EE94;
  for ( ; v5 < v8; v5 *= 2 )
    ;
  if ( v5 <= 2 )
    v5 = 2;
  if ( v5 - v8 > 0x10000 )
    v5 = dword_14207EE90 + 65537;
  if ( v5 == dword_14207EE90 )
  {
LABEL_21:
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
  UFG::qString *v2; // rax
  UFG::qString *v3; // rax
  UFG::qString *v4; // rax
  UFG::qString *v5; // rax
  char *mData; // rbx
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
  UFG::qString result; // [rsp+40h] [rbp-B8h] BYREF
  __int64 v24; // [rsp+68h] [rbp-90h]
  UFG::qString v25; // [rsp+70h] [rbp-88h] BYREF
  const char *v26; // [rsp+A8h] [rbp-50h]
  UFG::qString v27; // [rsp+B8h] [rbp-40h] BYREF
  UFG::qString v28; // [rsp+E0h] [rbp-18h] BYREF

  v24 = -2i64;
  v2 = UFG::operator+(&result, dataDir, "\\Global\\StateBlocks.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v2->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v3 = UFG::operator+(&result, dataDir, "\\Global\\TexturePack.perm.bin");
  LoadTexturePackHK(v3->mData, DATA_GAME_GLOBAL_TEXTURES);
  UFG::qString::~qString(&result);
  _(0i64);
  v4 = UFG::operator+(&result, dataDir, "\\Global\\EffectsTexturePack.perm.bin");
  LoadTexturePackHK(v4->mData, DATA_GAME_GLOBAL_TEXTURES);
  UFG::qString::~qString(&result);
  _(0i64);
  v5 = UFG::operator+(&result, dataDir, "\\Global\\LightingTexturePack.perm.bin");
  LoadTexturePackHK(v5->mData, DATA_GAME_GLOBAL_TEXTURES);
  UFG::qString::~qString(&result);
  _(0i64);
  mData = UFG::operator+(&result, dataDir, "\\UI\\global_win32_texturepack.perm.bin")->mData;
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(v7, mData, DEFAULT_PRIORITY, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v8 = UFG::operator+(&result, dataDir, "\\UI\\racecountdown_texturepack.perm.bin")->mData;
  v9 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(v9, v8, DEFAULT_PRIORITY, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v10 = UFG::operator+(&result, dataDir, "\\UI\\widgetarray_texturepack.perm.bin")->mData;
  v11 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(v11, v10, DEFAULT_PRIORITY, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  UFG::operator+((UFG::qString *)&v25.mStringHash32, dataDir, "\\Vehicles_New\\dummyvehiclerig.perm.bin");
  if ( UFG::StreamFileWrapper::FileExists(v26) )
  {
    UFG::DataStreamer::QueueStream(&stru_1423EC590, v26, DATA_TRUECROWD_RESOURCE, DEFAULT_PRIORITY, 7u, 0i64, 0i64);
    _(0i64);
  }
  UFG::operator+(&v27, dataDir, "\\Props_new\\PropPhysics.bin");
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
  UFG::operator+(&v25, dataDir, "\\Vehicles_New\\Global.perm.bin");
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
  UFG::operator+(&v28, dataDir, "\\Characters_New\\Global.perm.bin");
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
  v14 = UFG::operator+(&result, dataDir, "\\Global\\Models.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v14->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v15 = UFG::operator+(&result, dataDir, "\\Global\\fonts.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v15->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v16 = UFG::operator+(&result, dataDir, "\\Global\\Effects.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v16->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v17 = UFG::operator+(&result, dataDir, "\\Global\\Clouds.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v17->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v18 = UFG::operator+(&result, dataDir, "\\Global\\Physics.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v18->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v19 = UFG::operator+(&result, dataDir, "\\Global\\Rig.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v19->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v20 = UFG::operator+(&result, dataDir, "\\Global\\GlobalDNA.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v20->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v21 = UFG::operator+(&result, dataDir, "\\PrefabData\\Database.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v21->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  v22 = UFG::operator+(&result, dataDir, "\\Global\\Audio.perm.bin");
  UFG::StreamResourceLoader::LoadResourceFile(v22->mData, 0i64, 0, 0i64, 0i64, 0i64);
  UFG::qString::~qString(&result);
  _(0i64);
  UFG::qString::~qString(&v28);
  UFG::qString::~qString(&v25);
  UFG::qString::~qString(&v27);
  UFG::qString::~qString((UFG::qString *)&v25.mStringHash32);
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
  UFG::qVector2 *WorldExtents_max; // rsi
  UFG::qVector2 *WorldExtents_min; // rbp
  UFG::qVector2 *v4; // rbx
  UFG::qVector2 *v5; // rdi
  UFG::CoverDataInventory *Instance; // rax
  AMD_HD3D *v7; // rcx
  AMD_HD3D *v8; // rcx

  UFG::InterestPoint::InitGrid();
  WorldExtents_max = UFG::GetWorldExtents_max();
  WorldExtents_min = UFG::GetWorldExtents_min();
  v4 = UFG::GetWorldExtents_max();
  v5 = UFG::GetWorldExtents_min();
  Instance = UFG::CoverDataInventory::GetInstance();
  UFG::GridIntrusive<UFG::CoverCorner>::Init(
    &Instance->m_CornerGrid,
    WorldExtents_min->x,
    v5->y,
    WorldExtents_max->x,
    v4->y,
    100.0);
  UFG::WheeledVehicleManager::InitGlobalData(UFG::WheeledVehicleManager::m_Instance);
  _(v7);
  _(v8);
}

// File Line: 1152
// RVA: 0x4263D0
void UnloadCurrentLocation(void)
{
  UFG::TerrainCollisionManager *Instance; // rax
  UFG::SectionChooser *v1; // rcx
  UFG::ObjectResourceManager *v2; // rax
  UFG::PartDatabase *v3; // rax
  UFG::UIScreenTextureManager *v4; // rax
  UFG::TiDo *v5; // rax

  if ( gCurrentLocationDirectory.mLength )
  {
    Illusion::IEnginePlat::WaitUntilGPUDone(&Illusion::gEngine);
    if ( UFG::WheeledVehicleManager::m_Instance )
      UFG::WheeledVehicleManager::ReleaseGlobalData(UFG::WheeledVehicleManager::m_Instance);
    Instance = UFG::TerrainCollisionManager::GetInstance();
    UFG::TerrainCollisionManager::Shutdown(Instance);
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
    UFG::qString::Set(&stru_1423AA4D0, &customCaption);
    UFG::qString::Set(&stru_1423AA4A8, &customCaption);
    UFG::qString::Set(&gCurrentLocationDirectory, &customCaption);
  }
}

// File Line: 1216
// RVA: 0x4212C0
void __fastcall HK_VRAMMoveCallback(
        UFG::qVRAMemoryHandle *handle,
        char *previous_location,
        UFG::VRAMType usage,
        unsigned __int64 callback_data_64)
{
  void *buffer_ptr; // [rsp+20h] [rbp-18h] BYREF
  unsigned int buffer_size; // [rsp+50h] [rbp+18h] BYREF

  if ( (unsigned int)(usage - 9) <= 1 )
  {
    if ( UFG::DataStreamer::GetBufferFromUID(callback_data_64, (UFG::qBaseNodeRB **)&buffer_ptr, &buffer_size) )
      UFG::StreamResourceLoader::OnVRAMMove((char *)buffer_ptr, buffer_size);
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
    (int)g_HK_SimulationMemoryPoolSize,
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
    UFG::qMemoryPool::EnablePageBasedStompDetection(&gActionTreeMemoryPool);
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
    (int)g_HK_PropertySetPoolSize,
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
    (int)g_HK_SkookumPoolSize,
    g_HK_SkookumPoolSmallBlockSize,
    1,
    1u,
    UFG::gMainMemoryPool,
    1,
    1);
  UFG::qMemoryPool::Init(
    &gOnlineMemoryPool,
    "OnlineMemoryPool",
    (int)g_HK_OnlinePoolSize,
    g_HK_OnlinePoolSmallBlockSize,
    1,
    1u,
    UFG::gMainMemoryPool,
    1,
    1);
  UFG::qMemoryPool::Init(&gpc_PC_VRamMemoryPool, "PCVRAM_MemoryPool", (int)(g_HK_VRAMSize + 4096), 0, 0, 1u, 0i64, 1, 1);
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
  UFG::StreamingMemory::InitParams dest; // [rsp+20h] [rbp-19h] BYREF

  UFG::StreamPool_InitSystem();
  UFG::qMemSet(&dest, 0, 0x68u);
  dest.locationMemoryPoolSize = g_HK_LocationMemoryPoolSize;
  dest.animationMemoryPoolSize = g_HK_AnimationMemoryPoolSize;
  dest.streamedMemoryPoolSize = g_HK_TrueCrowdMemoryPoolSize + g_HK_PartsDBMemoryPoolSize;
  dest.cloudsTexturePoolSize = g_HK_CloudsTexturePoolSize;
  dest.uiMemoryPoolSize = g_HK_UIPoolSize;
  dest.localizationMemoryPoolSize = g_HK_LocalizationPoolSize;
  dest.streamedTextureHeaderPoolSize = g_HK_TrueCrowdTextureHeaderPoolSize + g_HK_PartsDBTextureHeaderPoolSize;
  dest.cellGameplayPoolSize = g_HK_GameplayCellBlockSize;
  dest.scriptPoolSize = g_HK_ScriptPoolSize;
  dest.uiVRamPoolSize = g_HK_UIVRamMemoryPoolSize;
  dest.streamedTexturePoolSize = g_HK_TrueCrowdTexturePoolSize + g_HK_PartsDBTexturePoolSize;
  dest.terrainElementCount = g_MaxTerrainElements;
  dest.terrainElementSize = g_TerrainElementSize;
  dest.globalLocationOverrideSize = 0x1400000;
  dest.terrainVRAMElementSize = g_TerrainVRAMElementSize;
  dest.locationMiscOverrideMemoryPoolSize = 0xA00000;
  *(_QWORD *)&dest.turfMemoryPoolSize = 0i64;
  dest.globalGameplayPoolSize = 0xF00000;
  dest.stdSectionElementSize = g_stdSectionElementSize;
  dest.stdSectionVRAMElementSize = g_stdSectionVRAMElementSize;
  dest.lodcSectionElementSize = g_lodcSectionElementSize;
  dest.lodcSectionVRAMElementSize = g_lodcSectionVRAMElementSize;
  dest.zoneElementSize = g_zoneElementSize;
  dest.zoneVRAMElementSize = g_zoneVRAMElementSize;
  dest.globalVRAMElementSize = g_globalVRAMElementSize;
  UFG::StreamingMemory::Init(&dest);
}

// File Line: 1473
// RVA: 0x426240
void __fastcall SetUpCameraForFERender(UFG *a1)
{
  UFG::qSymbol *v1; // rax
  UFG::SimObject *SimObject; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rbx
  unsigned int v5; // eax
  UFG::BaseCameraComponent *v6; // rax
  UFG::BaseCameraComponent *v7; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h] BYREF
  UFG::qSymbol result; // [rsp+78h] [rbp+10h] BYREF

  UFG::CreateDirector(a1);
  v1 = UFG::qSymbol::create_from_string(&result, "ChaseCamera");
  SimObject = UFG::Simulation::CreateSimObject(&UFG::gSim, v1);
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xD60ui64, "ChaseCameraComponent", 0i64, 1u);
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
  UFG::SimObjectModifier::SimObjectModifier(&v8, SimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v7, 0xFFFFFFFFi64);
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
  UFG::qFile **v2; // rbx
  UFG::BIGFileSize fileSize; // [rsp+30h] [rbp-18h] BYREF

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
  v2 = (UFG::qFile **)v1;
  if ( v1 )
  {
    UFG::StreamFileWrapper::Read(v1, STREAM_DATA_HIGH_PRIORITY, v0, &fileSize, 0i64, 0i64);
    UFG::StreamResourceLoader::Load(
      (unsigned int *)v0,
      fileSize.uncompressed_size,
      "Data\\Global\\PropertySets\\globalproperties.bin",
      DATA_UNKNOWN,
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gLegalTexturePackFileName__);
}

// File Line: 1558
// RVA: 0x14FF8E0
__int64 dynamic_initializer_for__gLegalRatingsPackFileName__()
{
  UFG::qString::qString(&gLegalRatingsPackFileName);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gLegalRatingsPackFileName__);
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
  signed __int64 result; // rax
  int v3; // eax
  unsigned int v4; // ecx

  if ( !code || (unsigned int)UFG::qStringLength(code) != 2 )
    return 59i64;
  if ( !(unsigned int)UFG::qStringCompare(code, "ae", -1) )
    return 56i64;
  result = UFG::qStringCompare(code, "ar", -1);
  if ( (_DWORD)result )
  {
    if ( !(unsigned int)UFG::qStringCompare(code, "at", -1) )
      return 2i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "au", -1) )
      return 1i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "be", -1) )
      return 4i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "bg", -1) )
      return 6i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "bh", -1) )
      return 3i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "br", -1) )
      return 5i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "ca", -1) )
      return 7i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "cn", -1) )
      return 9i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "ch", -1) )
      return 52i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "cl", -1) )
      return 8i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "co", -1) )
      return 10i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "cy", -1) )
      return 12i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "cz", -1) )
      return 13i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "de", -1) )
      return 17i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "dk", -1) )
      return 14i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "es", -1) )
      return 50i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "fi", -1) )
      return 15i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "fr", -1) )
      return 16i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "gb", -1) )
      return 57i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "gr", -1) )
      return 18i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "hk", -1) )
      return 19i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "hr", -1) )
      return 11i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "hu", -1) )
      return 20i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "id", -1) )
      return 23i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "ie", -1) )
      return 24i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "il", -1) )
      return 25i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "in", -1) )
      return 22i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "is", -1) )
      return 21i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "it", -1) )
      return 26i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "jp", -1) )
      return 27i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "kr", -1) )
      return 28i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "kw", -1) )
      return 29i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "lb", -1) )
      return 30i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "lu", -1) )
      return 31i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "mt", -1) )
      return 33i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "mx", -1) )
      return 34i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "my", -1) )
      return 32i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "nl", -1) )
      return 35i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "no", -1) )
      return 37i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "nz", -1) )
      return 36i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "om", -1) )
      return 38i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "pe", -1) )
      return 39i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "pl", -1) )
      return 40i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "pt", -1) )
      return 41i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "qa", -1) )
      return 42i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "ro", -1) )
      return 43i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "ru", -1) )
      return 44i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "sa", -1) )
      return 45i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "se", -1) )
      return 51i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "sg", -1) )
      return 46i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "si", -1) )
      return 48i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "sk", -1) )
      return 47i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "th", -1) )
      return 54i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "tr", -1) )
      return 55i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "tw", -1) )
      return 53i64;
    if ( !(unsigned int)UFG::qStringCompare(code, "ua", -1) )
      return 58i64;
    if ( (unsigned int)UFG::qStringCompare(code, "us", -1) )
    {
      v3 = UFG::qStringCompare(code, "za", -1);
      v4 = 59;
      if ( !v3 )
        return 49;
      return v4;
    }
    return 59i64;
  }
  return result;
}

// File Line: 1705
// RVA: 0x4257B0
const char *__fastcall MapRegionToRegionCode(unsigned int region)
{
  const char *result; // rax

  if ( region == 60 || region == -1 )
  {
    region = 59;
  }
  else if ( region > 0x3B )
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
int __fastcall GetSystemRegion()
{
  int v1; // eax
  int v2; // ecx
  char dest[3]; // [rsp+20h] [rbp-E0h] BYREF
  char code[93]; // [rsp+23h] [rbp-DDh] BYREF
  wchar_t text[88]; // [rsp+80h] [rbp-80h] BYREF

  if ( (int)GetUserDefaultLocaleName(text, 85i64) < 3 )
    return 59;
  UFG::qWideStringCopy(dest, 85, text, -1);
  UFG::qStringToLower(dest);
  if ( (unsigned int)UFG::qStringLength(dest) == 5 )
  {
    code[2] = 0;
    return MapRegionCodeToRegion(code);
  }
  else
  {
    dest[2] = 0;
    if ( (unsigned int)UFG::qStringCompare("zh", dest, -1) )
    {
      if ( (unsigned int)UFG::qStringCompare("da", dest, -1) )
      {
        if ( (unsigned int)UFG::qStringCompare("nl", dest, -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare("en", dest, -1) )
            return 59;
          if ( (unsigned int)UFG::qStringCompare("fi", dest, -1) )
          {
            if ( (unsigned int)UFG::qStringCompare("fr", dest, -1) )
            {
              if ( (unsigned int)UFG::qStringCompare("de", dest, -1) )
              {
                if ( (unsigned int)UFG::qStringCompare("it", dest, -1) )
                {
                  if ( (unsigned int)UFG::qStringCompare("ja", dest, -1) )
                  {
                    if ( (unsigned int)UFG::qStringCompare("ko", dest, -1) )
                    {
                      if ( (unsigned int)UFG::qStringCompare("no", dest, -1) )
                      {
                        if ( (unsigned int)UFG::qStringCompare("pl", dest, -1) )
                        {
                          if ( (unsigned int)UFG::qStringCompare("pt", dest, -1) )
                          {
                            if ( (unsigned int)UFG::qStringCompare("ru", dest, -1) )
                            {
                              if ( (unsigned int)UFG::qStringCompare("es", dest, -1) )
                              {
                                v1 = UFG::qStringCompare("sv", dest, -1);
                                v2 = 59;
                                if ( !v1 )
                                  return 51;
                                return v2;
                              }
                              else
                              {
                                return 50;
                              }
                            }
                            else
                            {
                              return 44;
                            }
                          }
                          else
                          {
                            return 41;
                          }
                        }
                        else
                        {
                          return 40;
                        }
                      }
                      else
                      {
                        return 37;
                      }
                    }
                    else
                    {
                      return 28;
                    }
                  }
                  else
                  {
                    return 27;
                  }
                }
                else
                {
                  return 26;
                }
              }
              else
              {
                return 17;
              }
            }
            else
            {
              return 16;
            }
          }
          else
          {
            return 15;
          }
        }
        else
        {
          return 35;
        }
      }
      else
      {
        return 14;
      }
    }
    else
    {
      return 9;
    }
  }
}

// File Line: 1878
// RVA: 0x4206E0
void __fastcall DisplayLegalLoadScreen(
        UFG::UILanguages::eLanguage systemLanguage,
        UFG::UILanguages::eLanguage gameLanguage,
        Region systemRegion)
{
  UFG::UI *v4; // rcx
  bool v5; // al
  UFG::qString *v6; // rax
  unsigned int mStringHashUpper32; // esi
  UFG::qString *v8; // rax
  int v9; // ebx
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
  Render::LoadScreenInitParams params; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qString v37; // [rsp+A0h] [rbp-58h] BYREF
  UFG::qString v38; // [rsp+C8h] [rbp-30h] BYREF
  UFG::qString v39; // [rsp+F0h] [rbp-8h] BYREF
  UFG::qString v40; // [rsp+118h] [rbp+20h] BYREF
  UFG::qString v41; // [rsp+140h] [rbp+48h] BYREF
  UFG::qString v42; // [rsp+168h] [rbp+70h] BYREF
  UFG::qString v43; // [rsp+190h] [rbp+98h] BYREF
  UFG::qString v44; // [rsp+1B8h] [rbp+C0h] BYREF
  UFG::qString v45; // [rsp+1E0h] [rbp+E8h] BYREF
  UFG::qString v46; // [rsp+208h] [rbp+110h] BYREF
  UFG::qString v47; // [rsp+230h] [rbp+138h] BYREF
  UFG::qString v48; // [rsp+258h] [rbp+160h] BYREF
  UFG::qString v49; // [rsp+280h] [rbp+188h] BYREF
  UFG::qString v50; // [rsp+2A8h] [rbp+1B0h] BYREF
  UFG::qString v51; // [rsp+2D0h] [rbp+1D8h] BYREF
  UFG::qString result; // [rsp+2F8h] [rbp+200h] BYREF
  Render::RenderOutputParams outSettings; // [rsp+328h] [rbp+230h] BYREF

  *(_QWORD *)&params.mBackgroundName.mStringHash32 = -2i64;
  LoadTexturePackHK("Data\\Global\\BootTexturePack.perm.bin", DATA_GAME_GLOBAL_TEXTURES);
  UFG::UI::InitHDSettings(v4);
  v5 = UFG::UI::IsInHDMode();
  switch ( systemRegion )
  {
    case 2:
    case 4:
    case 6:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 24:
    case 26:
    case 31:
    case 33:
    case 35:
    case 37:
    case 40:
    case 41:
    case 43:
    case 44:
    case 47:
    case 48:
    case 50:
    case 51:
    case 52:
    case 57:
    case 58:
      if ( v5 )
      {
        v15 = UFG::qString::FormatEx(&v48, "LEGAL_%s_SCREENENGLISH_EU", "PC64");
        v16 = v15;
        if ( v15->mStringHashUpper32 == -1 )
          v15->mStringHashUpper32 = UFG::qStringHashUpper32(v15->mData, -1);
        mStringHashUpper32 = v16->mStringHashUpper32;
        UFG::qString::~qString(&v48);
        v17 = UFG::qString::FormatEx(&v44, "Data\\UI\\Legal_%s_ScreenEnglish_EU_TexturePack.perm.bin", "PC64");
        v9 = 0;
        UFG::qString::Set(&gLegalTexturePackFileName, v17->mData, v17->mLength, 0i64, 0);
        UFG::qString::~qString(&v44);
        v10 = UFG::qStringHashUpper32("LEGAL_ESRB_EU", -1);
        v18 = UFG::qString::FormatEx(&v37, "Data\\UI\\Legal_ESRB_EU_TexturePack.perm.bin");
        UFG::qString::Set(&gLegalRatingsPackFileName, v18->mData, v18->mLength, 0i64, 0);
        UFG::qString::~qString(&v37);
      }
      else
      {
        v19 = UFG::qString::FormatEx(&v38, "LEGAL_%s_SCREENENGLISH_EU_SD", "PC64");
        v20 = v19;
        if ( v19->mStringHashUpper32 == -1 )
          v19->mStringHashUpper32 = UFG::qStringHashUpper32(v19->mData, -1);
        mStringHashUpper32 = v20->mStringHashUpper32;
        UFG::qString::~qString(&v38);
        v21 = UFG::qString::FormatEx(&v39, "Data\\UI\\Legal_%s_ScreenEnglish_EU_SD_TexturePack.perm.bin", "PC64");
        v9 = 0;
        UFG::qString::Set(&gLegalTexturePackFileName, v21->mData, v21->mLength, 0i64, 0);
        UFG::qString::~qString(&v39);
        v10 = UFG::qStringHashUpper32("LEGAL_ESRB_EU_SD", -1);
        v22 = UFG::qString::FormatEx(&v41, "Data\\UI\\Legal_ESRB_EU_SD_TexturePack.perm.bin");
        UFG::qString::Set(&gLegalRatingsPackFileName, v22->mData, v22->mLength, 0i64, 0);
        UFG::qString::~qString(&v41);
      }
      break;
    case 5:
    case 7:
    case 10:
    case 34:
    case 59:
      if ( v5 )
      {
        v6 = UFG::qString::FormatEx(&result, "LEGAL_%s_SCREENENGLISH_US", "PC64");
        mStringHashUpper32 = UFG::qString::GetStringHashUpper32(v6);
        UFG::qString::~qString(&result);
        v8 = UFG::qString::FormatEx(&v51, "Data\\UI\\Legal_%s_ScreenEnglish_US_TexturePack.perm.bin", "PC64");
        v9 = 0;
        UFG::qString::Set(&gLegalTexturePackFileName, v8->mData, v8->mLength, 0i64, 0);
        UFG::qString::~qString(&v51);
        v10 = UFG::qStringHashUpper32("LEGAL_ESRB_US", -1);
        v11 = UFG::qString::FormatEx(&v46, "Data\\UI\\Legal_ESRB_US_TexturePack.perm.bin");
        UFG::qString::Set(&gLegalRatingsPackFileName, v11->mData, v11->mLength, 0i64, 0);
        UFG::qString::~qString(&v46);
      }
      else
      {
        v12 = UFG::qString::FormatEx(&v40, "LEGAL_%s_SCREENENGLISH_US_SD", "PC64");
        mStringHashUpper32 = UFG::qString::GetStringHashUpper32(v12);
        UFG::qString::~qString(&v40);
        v13 = UFG::qString::FormatEx(&v50, "Data\\UI\\Legal_%s_ScreenEnglish_US_SD_TexturePack.perm.bin", "PC64");
        v9 = 0;
        UFG::qString::Set(&gLegalTexturePackFileName, v13->mData, v13->mLength, 0i64, 0);
        UFG::qString::~qString(&v50);
        v10 = UFG::qStringHashUpper32("LEGAL_ESRB_US_SD", -1);
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
          v23->mStringHashUpper32 = UFG::qStringHashUpper32(v23->mData, -1);
        mStringHashUpper32 = v24->mStringHashUpper32;
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
          v27->mStringHashUpper32 = UFG::qStringHashUpper32(v27->mData, -1);
        mStringHashUpper32 = v28->mStringHashUpper32;
        UFG::qString::~qString(&v47);
        v29 = UFG::qString::FormatEx(&v49, "Data\\UI\\Legal_%s_ScreenEnglish_EU_SD_TexturePack.perm.bin", "PC64");
        v9 = 0;
        UFG::qString::Set(&gLegalTexturePackFileName, v29->mData, v29->mLength, 0i64, 0);
        v26 = &v49;
      }
      UFG::qString::~qString(v26);
      UFG::qString::Set(&gLegalRatingsPackFileName, &customCaption);
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
  params.mBackgroundScale = *((float *)&_xmm + 2);
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
    dword_1423EC6E4 = mStringHashUpper32;
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
    UFG::LoadingLogic::StartLoadScreen(&UFG::gLoadingLogic, 3, gBootSequenceImages, 1u);
    v33 = UFG::qResourceWarehouse::Instance();
    for ( i = UFG::qResourceWarehouse::GetInventory(v33, 0x8B43FABF); !i->vfptr->Get(i, mStringHashUpper32); ++v9 )
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTempFrameMemoryAllocator__);
}

// File Line: 2176
// RVA: 0x420430
void AddFrameMemoryOverflow(void)
{
  unsigned int v0; // edi
  char *v1; // rbx

  if ( gFrameMemoryOverflowBuffer )
  {
    if ( !gFrameMemoryOverflowEnabled )
    {
      UFG::qPrintf(
        "[TempFrameMemory] Added - addr=0x%08x sz=%7d!\n",
        gFrameMemoryOverflowBuffer,
        gFrameMemoryOverflowTotalBytes);
      Illusion::IEnginePlat::WaitUntilGPUDone(&Illusion::gEngine);
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
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  hkBaseSystem::initThread(&result, UFG::BasePhysicsSystem::mMemoryRouter);
}

// File Line: 2237
// RVA: 0x4269D0
void __fastcall qTaskThreadClose()
{
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

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
  int BigFileMode; // ebx

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
    BigFileMode = UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_BOOT, 0i64);
    if ( BigFileMode )
    {
      if ( !v1
        || BigFileMode != (unsigned int)UFG::BigFileLogic::GetBigFileMode(
                                          (const char *)&UFG::BigFileLogic::SYSTEM_GLOBAL->mEnableStereo,
                                          0i64)
        || !v2
        || BigFileMode != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_UI, 0i64)
        || !v3
        || BigFileMode != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_VEHICLES, 0i64)
        || !v4
        || BigFileMode != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_CHARACTERS, 0i64)
        || !v5
        || BigFileMode != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_ANIMATION, 0i64)
        || !v6
        || BigFileMode != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_NISANIMATION, 0i64)
        || !v7
        || BigFileMode != (unsigned int)UFG::BigFileLogic::GetBigFileMode(UFG::BigFileLogic::SYSTEM_WORLD, "Game") )
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
  Render::RenderOutputParams outSettings; // [rsp+20h] [rbp-78h] BYREF

  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  UFG::DataStreamer::DisableSpreadedUnload(v0);
  gIsHDWorldTextures = outSettings.mTextureDetailLevel == TEXTURE_DETAIL_HIGH;
  UFG::SectionChooser::BeginFlush(1);
}

// File Line: 2438
// RVA: 0x426110
void __fastcall RenderSimOcclusionQueriesCallback(UFG::RenderContext *render_context, Render::View *view)
{
  UFG::SimAsyncOcclusionQueryManager *v3; // rax

  v3 = UFG::SimAsyncOcclusionQueryManager::Get();
  if ( v3 )
    UFG::SimAsyncOcclusionQueryManager::UpdateQueries(v3, view);
}

// File Line: 2482
// RVA: 0x425AB0
signed __int64 __fastcall MapSystemLanguageToLanguageGameSupports(unsigned int systemLang)
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
signed __int64 __fastcall InitGameSystems(hkEntitySelectorAll *a1, hkpEntity *a2)
{
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  __int64 size; // rdi
  unsigned int v4; // ebx
  unsigned int v5; // edx
  fastdelegate::FastDelegate<bool __cdecl(UFG::qString *)> *v6; // rcx
  AMD_HD3D *v7; // rcx
  UFG::qString *LocalIP; // rax
  DNA::Database *v9; // rax
  UFG::StreamingMemory *v10; // rcx
  Render *v11; // rcx
  AMD_HD3D *v12; // rcx
  UFG::OnlineManager *v13; // rax
  UFG::OSuiteManager *v14; // rax
  MinimumDistanceTask *v15; // rax
  AMD_HD3D *v16; // rax
  AMD_HD3D *v17; // rax
  UFG *v18; // rcx
  UFG::DataStreamer *v19; // rcx
  unsigned __int64 FileChecksum64; // rsi
  bool v21; // al
  bool v22; // bl
  bool v23; // di
  int v24; // edx
  int v25; // r8d
  hkGeometryUtils::IVertices *v26; // rcx
  hkgpIndexedMesh::EdgeBarrier *v27; // rcx
  int v28; // edx
  int v29; // r8d
  int v30; // r8d
  int v31; // r8d
  int v32; // r8d
  int v33; // r8d
  int v34; // r8d
  int v35; // r8d
  int v36; // r8d
  int v37; // r8d
  int v38; // r8d
  int v39; // r8d
  int SystemRegion; // ebx
  __int64 v41; // rcx
  UFG::UILanguages::eLanguage SystemLanguage; // edi
  UFG::UILanguages::eLanguage v43; // esi
  AMD_HD3D *v44; // rcx
  UFG *v45; // rcx
  UFG::OSuiteLeaderboardManager *v46; // rax
  AMD_HD3D *v47; // rcx
  UFG *v48; // rcx
  UFG::qString *Directory; // rax
  AMD_HD3D *v50; // rcx
  UFG::PartDatabase *v51; // rax
  AMD_HD3D *v52; // rcx
  AMD_HD3D *v53; // rcx
  UFG::OnlineEventManager *v54; // rcx
  UFG *v55; // rcx
  int v56; // edx
  UFG::SectionChooser::Lookahead *RoadNetworkLookahead; // rax
  UFG::GameStatTracker *v58; // rax
  UFG *v59; // rcx
  UFG::TimeOfDayManager *Instance; // rax
  UFG::TimeOfDayManager *v61; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v63; // rax
  UFG::TimeOfDayManager *v64; // rbx
  UFG::qResourceInventory *v65; // rax
  UFG::qResourceWarehouse *v66; // rax
  CullManager *v67; // rax
  UFG *v68; // rcx
  UFG *v69; // rcx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v71; // rax
  UFG::SimComponent *v72; // rax
  UFG::qMemoryPool *v73; // rax
  UFG::allocator::free_link *v74; // rax
  UFG::SimComponent *v75; // rax
  UFG::qMemoryPool *v76; // rax
  UFG::allocator::free_link *v77; // rax
  UFG::SimComponent *v78; // rax
  UFG::qMemoryPool *v79; // rax
  UFG::allocator::free_link *v80; // rax
  UFG::SimComponent *v81; // rax
  UFG::qMemoryPool *v82; // rax
  UFG::allocator::free_link *v83; // rax
  UFG::SimComponent *v84; // rax
  UFG *v85; // rcx
  signed int v86; // r8d
  char **v87; // r9
  EnumList<unsigned long> **p; // r11
  signed int v89; // r10d
  signed int v90; // ecx
  char *v91; // rax
  int v92; // edx
  UFG::UIScreenTextureManager *v93; // rbx
  UFG::UIScreenManager *v94; // rax
  UFG::UIScreenManager *v95; // rax
  UIHKGFxTranslator *v96; // rax
  UFG::UIGfxTranslator *v97; // rax
  UFG::UIGfxTranslator *v98; // rdi
  UFG::UIScreenManager *v99; // rbx
  Scaleform::Render::RenderBuffer *m_translator; // rcx
  UFG::UIScreenTextureManager *v101; // rax
  int v102; // edx
  hkGeometryUtils::IVertices *v103; // rcx
  int v104; // r8d
  UFG::TiDo *v105; // rax
  UFG::TiDo *v106; // rax
  AMD_HD3D *v107; // rcx
  char *v108; // rax
  unsigned int v109; // edi
  UFG::GameState *GameStateObj; // rax
  UFG::ProgressionTracker *v111; // rax
  UFG::GameSetup *GameSetup; // rbx
  char *mData; // rdx
  UFG *v114; // rcx
  UFG *v115; // rcx
  UFG::qString result; // [rsp+50h] [rbp-98h] BYREF
  Render::RenderInitParams params; // [rsp+78h] [rbp-70h] BYREF
  __int64 v119; // [rsp+108h] [rbp+20h]
  Render::RenderCallbacks v120; // [rsp+118h] [rbp+30h] BYREF
  Render::RenderOutputParams v121; // [rsp+188h] [rbp+A0h] BYREF
  UFG::qString v122; // [rsp+1F8h] [rbp+110h] BYREF
  UFG::qString v123; // [rsp+220h] [rbp+138h] BYREF
  UFG::qInitParams init_params; // [rsp+248h] [rbp+160h] BYREF
  Render::RenderCallbacks render_callbacks; // [rsp+278h] [rbp+190h] BYREF
  char *visual_treatment_name[131]; // [rsp+2E8h] [rbp+200h] BYREF
  void *v127; // [rsp+708h] [rbp+620h]

  v119 = -2i64;
  hkaReferencePoseAnimation::getNumOriginalFrames(a1, a2);
  UFG::qInitParams::qInitParams(&init_params);
  UFG::qInit(&init_params);
  UFG::qSetAssertHandler((int (*)(const char *, const char *, int, bool *, const char *, ...))HKAssertHandler);
  mNext = (UFG::qNode<UFG::qString,UFG::qString> *)fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !SkookumExtraContext )
    mNext = 0i64;
  result.mNext = mNext;
  result.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)SkookumExtraContext;
  size = gAssertContextFuncs.size;
  v4 = gAssertContextFuncs.size + 1;
  if ( gAssertContextFuncs.size + 1 > gAssertContextFuncs.capacity )
  {
    if ( gAssertContextFuncs.capacity )
      v5 = 2 * gAssertContextFuncs.capacity;
    else
      v5 = 1;
    for ( ; v5 < v4; v5 *= 2 )
      ;
    if ( v5 - v4 > 0x10000 )
      v5 = gAssertContextFuncs.size + 65537;
    UFG::qArray<fastdelegate::FastDelegate<bool (UFG::qString *)>,0>::Reallocate(&gAssertContextFuncs, v5, "qArray.Add");
    mNext = result.mNext;
  }
  gAssertContextFuncs.size = v4;
  v6 = &gAssertContextFuncs.p[size];
  v6->m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))mNext;
  v6->m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)result.mPrev;
  UFG::qString::Set(&gCurrentLocationDirectory, &customCaption);
  _(v7);
  InitConfig("UserOptions.xml");
  UFG::qString::qString(&v123, "TheoryEngine.PC64_");
  LocalIP = UFG::qGetLocalIP(&result);
  UFG::qString::operator+=(&v123, LocalIP->mData);
  UFG::qString::~qString(&result);
  UFG::HDDmanager::Instantiate();
  UserManager::CreateInstance();
  DNA::Database::Init();
  DNA::Database::Instance();
  DNA::Database::LoadReflectionDatabase(v9, "reflection.rdb", 1);
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
  UFG::StreamingMemory::InitPcCPUPools(v10);
  UFG::PhysicsSystem::InitializeMemory();
  UFG::qTaskManager::Init(&UFG::gTaskManager, qTaskThreadInit, qTaskThreadClose);
  Render::RenderCallbacks::RenderCallbacks(&render_callbacks);
  render_callbacks.mRenderWorldFunc = UFG::RenderWorld::RenderWorldClearScreen;
  Render::SetRenderCallbacks(&render_callbacks);
  Render::RenderCallbacks::RenderCallbacks(&v120);
  v120.mRenderThreadSyncPointFunc = UFG::RenderWorld::RenderThreadSyncUpdate;
  v120.mUpdateWorldFunc = (bool (__fastcall *)(float))MainUpdateGameSystems;
  v120.mRenderWorldFunc = (void (__fastcall *)(float, void *))UFG::RenderWorld::RenderWorldCallback;
  v120.mRenderSim = UFG::RenderSim;
  v120.mRenderSimDebug = (void (__fastcall *)(UFG::RenderContext *, Render::View *))_;
  v120.mRenderSimDebugOverlay = UFG::RenderSimDebugOverlay;
  v120.mChangeTexturePackFunc = RenderChangeTexturePack;
  v120.mRenderSimOcclusionQueries = RenderSimOcclusionQueriesCallback;
  if ( gRunPCRemotely )
  {
    gUsePCController = 0;
    v120.mRenderWorldFunc = 0i64;
  }
  Render::RenderInitParams::RenderInitParams(&params);
  params.mFrameMemoryTotalBytes = g_HK_FrameMemoryTotalSize;
  params.mFrameWriteMemoryTotalBytes = g_HK_FrameWriteTotalSize;
  params.mPrimitiveFrameWriteMemoryTotalBytes = g_HK_PrimitiveFrameWriteTotalSize;
  params.mFramePatchMemoryTotalBytes = g_HK_FramePatchTotalSize;
  params.mFrameIndexMemoryTotalBytes = g_HK_FrameIndexTotalSize;
  params.mTitleName = "Sleeping Dogs: Definitive Edition[PC64-Ship]";
  *(_DWORD *)&params.mIconResourceId = 6684773;
  Render::RenderOutputParams::RenderOutputParams(&v121);
  if ( UFG::GameStatPCDisplaySettings::LoadFromXML(
         (UFG::GameStatPCDisplaySettings *)&v121,
         UFG::GameStatPCDisplaySettings::gDefaultSavePath) )
  {
    params.mRenderOutputParams = v121;
    gIsHDWorldTextures = v121.mTextureDetailLevel == TEXTURE_DETAIL_HIGH;
    gExtendedMidground = _mm_cvtsi128_si32(*(__m128i *)&v121.mLODSetting) > 1;
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
  params.mRenderOutputParams.mDisplayMode.mScanlineMode = SCANLINE_MODE_NOTFILTERED;
LABEL_21:
  Illusion::Engine::Init(&Illusion::gEngine);
  Render::InitStateParams(v11);
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
  _(v12);
  MountBigFiles();
  InitGlobalPools();
  v13 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::Init(v13);
  v14 = UFG::OSuiteManager::Instance();
  UFG::OSuiteManager::Init(v14);
  v15 = (MinimumDistanceTask *)UFG::OSuiteDBLogger::Instance();
  UFG::OSuiteDBLogger::Init(v15);
  v16 = (AMD_HD3D *)UFG::OSuiteTickerManager::Instance();
  _(v16);
  v17 = (AMD_HD3D *)UFG::OSuiteMessenger::Instance();
  _(v17);
  UFG::WebSystem::Init("SDHD", gProxyCredentials.mData, 1);
  UFG::DataLogger::Init();
  InitStreamingPools();
  if ( UFG::gAutoSmoketest )
    UFG::StreamFileWrapper::EnableLogging(1);
  if ( gCreateFinalBinDir )
  {
    UFG::qString::qString(&result, "data\\global\\xmlcache\\XML_CacheList.bin");
    UFG::DataStreamer::QueueStream(&handle, result.mData, DATA_ANIMATION, DEFAULT_PRIORITY, 7u, 0i64, 0i64);
    WaitForStreamer(v18);
    UFG::qString::~qString(&result);
  }
  TracksEnum<unsigned long>::Initialize("Data\\");
  TracksEnum<float>::Initialize("Data\\");
  _(0i64);
  _(0i64);
  Illusion::IEnginePlat::WaitUntilGPUDone(&Illusion::gEngine);
  UFG::qChunkFileSystem::Load("Data\\Shaders\\Shaders.temp.bin", 0i64, 0i64, 0i64, ResourceFileContentType_Standard);
  UFG::qChunkFileSystem::Load("Data\\Shaders\\Shaders.perm.bin", 0i64, 0i64, 0i64, ResourceFileContentType_Standard);
  _(0i64);
  UFG::UIAmbientMapBlipManager::getInstance();
  UFG::Fingerprint::InitFingerprintSystem("Data\\Global\\ufg_sig.sig");
  params.mFrameMemoryTotalBytes = 512000;
  params.mFrameWriteMemoryTotalBytes = 512000;
  result.mData = (char *)0x25800000258000i64;
  Render::DebugDrawManager::Init((Render::DebugDrawManager::InitInfo *)&params);
  UFG::QuarkProbe::Init();
  UFG::GameSetup::msProject = ePROJ_HK;
  _(0i64);
  UFG::DataStreamer::Initialize(v19);
  _((AMD_HD3D *)2);
  _(0i64);
  if ( !gDiskLine )
  {
    FileChecksum64 = -1i64;
    v21 = UFG::qFileExists((const char *)&stru_141787D48);
    v22 = v21;
    v23 = UFG::gBuildingBigFiles;
    if ( !UFG::gBuildingBigFiles && v21 )
      FileChecksum64 = UFG::qGetFileChecksum64((const char *)&stru_141787D48, 0xFFFFFFFFFFFFFFFFui64);
    Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
      (hkgpIndexedMesh::EdgeBarrier *)v23,
      (hkgpIndexedMeshDefinitions::Edge *)0x30000000);
    if ( !v23 )
    {
      if ( !v22 )
      {
LABEL_35:
        LOBYTE(v24) = 1;
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789DD8, v24, v25);
        LOBYTE(v28) = 1;
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789DE8, v28, v29);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789DF8, 0, v30);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E08, 0, v31);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E14, 0, v32);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E20, 0, v33);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E48, 0, v34);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E70, 0, v35);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789E98, 0, v36);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789EC0, 0, v37);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789EE8, 0, v38);
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141789F10, 0, v39);
        goto LABEL_36;
      }
      if ( FileChecksum64 != UFG::qGetFileChecksum64((const char *)&stru_141787D48, 0xFFFFFFFFFFFFFFFFui64) )
      {
        Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v26, v24, v25);
        LOBYTE(v27) = 1;
        Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          v27,
          (hkgpIndexedMeshDefinitions::Edge *)0x30000000);
      }
    }
    if ( v22 )
    {
      LOBYTE(v24) = 1;
      Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(&stru_141787D48, v24, v25);
    }
    goto LABEL_35;
  }
LABEL_36:
  UFG::TicketBoothManager::Initialize();
  UFG::HotSwapFileManager::SetEnabled(0);
  _(0i64);
  Render::SetRenderCallbacks(&v120);
  SystemRegion = GetSystemRegion();
  SystemLanguage = (unsigned int)UFG::UIGfxTranslator::getSystemLanguage(v41);
  v43 = (unsigned int)MapSystemLanguageToLanguageGameSupports(SystemLanguage);
  UFG::UIScreenTextureManager::Init(g_HK_UIVRamMemoryPoolSize);
  DisplayLegalLoadScreen(SystemLanguage, v43, (Region)SystemRegion);
  _(v44);
  _(0i64);
  UFG::LightGroupComponent::LoadLightGroupCache();
  UFG::CreateAndRegisterGameStates(v45);
  UFG::GeographicalLayerManager::GetInstance();
  UFG::PropertySetManager::Init(0i64);
  UFG::PropertySetManager::SetRootPath("Data\\CheckedIn\\Common\\Data\\PropertySets\\");
  _(0i64);
  LoadGlobalPropertySets();
  _(0i64);
  v46 = UFG::OSuiteLeaderboardManager::Instance();
  UFG::OSuiteLeaderboardManager::Init(v46);
  UFG::EventDispatcher::Initialize(&UFG::EventDispatcher::mInstance);
  UFG::SkookumMgr::Init();
  _(v47);
  UFG::StreamResourceLoader::LoadResourceFile("Data\\Global\\PhysicsProperties.perm.bin", 0i64, 0, 0i64, 0i64, 0i64);
  _(0i64);
  UFG::PhysicsSystem::Initialize(v48);
  Directory = UFG::qGetDirectory(&result);
  UFG::qString::FormatEx(&v122, "%s\\Data\\", Directory->mData);
  UFG::qString::~qString(&result);
  MemberMapFileManager::Init(v122.mData);
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
  _(v50);
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
  v51 = UFG::PartDatabase::Instance();
  UFG::PartDatabase::InitPool(v51);
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
  _(v52);
  _(0i64);
  _(v53);
  _(0i64);
  UFG::SimObjectWeaponPropertiesComponent::StaticInit();
  _(0i64);
  NoiseManager::Init();
  _(0i64);
  if ( !gDemoVersion )
  {
    UFG::OnlineEventManager::Initialize(v54);
    UFG::AchievementTrophyManager::Init(60);
    _(0i64);
  }
  UFG::HK_InitInput(v54);
  _(0i64);
  UFG::InputSystem::Init();
  _(0i64);
  UFG::HK_PostInputInit(v55);
  _(0i64);
  UFG::qString::qString(&result, "Data");
  LoadGlobalBins(&result);
  UFG::qString::~qString(&result);
  _(0i64);
  v56 = gDebugControllerPort;
  if ( gDebugControllerPort > 0 )
  {
    if ( !UFG::gInputSystem->mControllers[gDebugControllerPort] )
      v56 = 0;
    gDebugControllerPort = v56;
  }
  RoadNetworkLookahead = UFG::CreateRoadNetworkLookahead();
  UFG::SectionChooser::SetLookahead(RoadNetworkLookahead);
  UFG::SectionChooser::SetOnZoneLayoutLoadCallback(OnZoneLayoutLoadCallback);
  v58 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::Initialize(v58);
  _(0i64);
  UFG::StatGameManager::Instantiate();
  _(0i64);
  UFG::CachedLeaderboardManager::Instance();
  UFG::StatAwardPropertyManager::Instance();
  UFG::Metrics::msInstance.mSimTimeDeltaMax = FLOAT_0_050000001;
  UFG::InitSim(v59);
  _(0i64);
  UFG::GroupManager::CreateInstance();
  _(0i64);
  UFG::PedSpawnManager::CreateInstance();
  _(0i64);
  Instance = UFG::TimeOfDayManager::GetInstance();
  UFG::TimeOfDayManager::Init(Instance);
  v61 = UFG::TimeOfDayManager::GetInstance();
  Inventory = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v63 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v63, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&v61->mSunnyStateBlockHandle, 0x4D04C7F2u, 0x764E403Au, Inventory);
  v64 = UFG::TimeOfDayManager::GetInstance();
  v65 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v66 = UFG::qResourceWarehouse::Instance();
    v65 = UFG::qResourceWarehouse::GetInventory(v66, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v65;
  }
  UFG::qResourceHandle::Init(&v64->mOvercastStateBlockHandle, 0x4D04C7F2u, 0x8512348D, v65);
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
  v67 = CullManager::Instance();
  CullManager::Init(v67, 0i64);
  _(0i64);
  UFG::RenderWorld::Init();
  UFG::CreateHighlightPlugin(v68);
  UFG::CreateWireframePlugin(v69);
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&result, UFG::RenderWorld::msRenderStagePlugin, 1);
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v71 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x58ui64, "DamagePostEffect", 0i64, 1u);
  v127 = v71;
  if ( v71 )
    UFG::DamagePostEffect::DamagePostEffect((UFG::DamagePostEffect *)v71);
  else
    v72 = 0i64;
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&result, v72, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&result, UFG::RenderWorld::msRenderStagePlugin, 1);
  v73 = UFG::GetSimulationMemoryPool();
  v74 = UFG::qMemoryPool::Allocate(v73, 0x58ui64, "GunRecoilPostEffect", 0i64, 1u);
  v127 = v74;
  if ( v74 )
    UFG::GunRecoilPostEffect::GunRecoilPostEffect((UFG::GunRecoilPostEffect *)v74);
  else
    v75 = 0i64;
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&result, v75, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&result, UFG::RenderWorld::msRenderStagePlugin, 1);
  v76 = UFG::GetSimulationMemoryPool();
  v77 = UFG::qMemoryPool::Allocate(v76, 0x250ui64, "VisualTreatmentPostEffect", 0i64, 1u);
  v127 = v77;
  if ( v77 )
    UFG::VisualTreatmentPostEffect::VisualTreatmentPostEffect((UFG::VisualTreatmentPostEffect *)v77);
  else
    v78 = 0i64;
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&result, v78, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&result, UFG::RenderWorld::msRenderStagePlugin, 1);
  v79 = UFG::GetSimulationMemoryPool();
  v80 = UFG::qMemoryPool::Allocate(v79, 0x58ui64, "AccumulationBufferPostEffect", 0i64, 1u);
  v127 = v80;
  if ( v80 )
    UFG::AccumulationBufferPostEffect::AccumulationBufferPostEffect((UFG::AccumulationBufferPostEffect *)v80);
  else
    v81 = 0i64;
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&result, v81, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::SimObjectModifier((UFG::SimObjectModifier *)&result, UFG::RenderWorld::msRenderStagePlugin, 1);
  v82 = UFG::GetSimulationMemoryPool();
  v83 = UFG::qMemoryPool::Allocate(v82, 0x68ui64, "FrontEndPauseEffect", 0i64, 1u);
  v127 = v83;
  if ( v83 )
    UFG::FrontEndPauseEffect::FrontEndPauseEffect((UFG::FrontEndPauseEffect *)v83);
  else
    v84 = 0i64;
  UFG::SimObjectModifier::AttachComponent((UFG::SimObjectModifier *)&result, v84, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close((UFG::SimObjectModifier *)&result);
  UFG::SimObjectModifier::~SimObjectModifier((UFG::SimObjectModifier *)&result);
  UFG::CreateAltColorPlugin(v85);
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
  v86 = 0;
  v87 = visual_treatment_name;
  p = gVisualTreatmentEnum.m_enumLists.p;
  v89 = gVisualTreatmentEnum.m_enumLists.size;
  while ( 1 )
  {
    v90 = v89 < 0 ? 0 : (*p)->m_enumName.size;
    if ( v86 >= v90 )
      break;
    if ( v89 < 0 )
      v91 = 0i64;
    else
      v91 = (*p)->m_enumName.p[v86];
    *v87 = v91;
    ++v86;
    ++v87;
  }
  if ( v89 < 0 )
    v92 = 0;
  else
    v92 = (*p)->m_enumName.size;
  UFG::VisualTreatmentPostEffect::StaticInit((const char **)visual_treatment_name, v92);
  UFG::UIHKTweakables::Initialize();
  UFG::UITiledMapTweakables::Initialize();
  _(0i64);
  UFG::UIHKScreenHud::Initialize();
  _(0i64);
  v93 = UFG::UIScreenTextureManager::Instance();
  v94 = (UFG::UIScreenManager *)UFG::qMemoryPool::Allocate(
                                  &gScaleformMemoryPool,
                                  0x320ui64,
                                  "UIScreenManager::UIScreenManager",
                                  0i64,
                                  1u);
  v127 = v94;
  if ( v94 )
    UFG::UIScreenManager::UIScreenManager(v94, v93);
  else
    v95 = 0i64;
  UFG::UIScreenManager::s_instance = v95;
  v96 = (UIHKGFxTranslator *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                               Scaleform::Memory::pGlobalHeap,
                               20632i64,
                               0i64);
  v127 = v96;
  if ( v96 )
  {
    UIHKGFxTranslator::UIHKGFxTranslator(v96);
    v98 = v97;
  }
  else
  {
    v98 = 0i64;
  }
  v99 = UFG::UIScreenManager::s_instance;
  m_translator = (Scaleform::Render::RenderBuffer *)UFG::UIScreenManager::s_instance->m_translator;
  if ( m_translator )
    Scaleform::RefCountImpl::Release(m_translator);
  v99->m_translator = v98;
  UFG::UIGfxTranslator::init(v98, v99->m_screenFactory, v99->m_gfxMovieLoader);
  UFG::UIGfxTranslator::setLanguage(v99->m_translator, eLang_English, 1);
  UFG::UIScreenManager::s_instance->mScaleViewportInCode = 1;
  ((void (__fastcall *)(UFG::UIScreenManager *))UFG::UIScreenManager::s_instance->vfptr->update)(UFG::UIScreenManager::s_instance);
  _(0i64);
  UFG::UIScreenManager::s_instance->m_DisplayChangeCallback = UFG::UI::DisplayChangeCallback;
  _(0i64);
  UFG::UIScreenManager::s_instance->m_gfxFileOpener->UFG::UIScreenManagerBase::vfptr[4].__vecDelDtor(
    UFG::UIScreenManager::s_instance->m_gfxFileOpener,
    (unsigned int)"Global.BIN");
  UFG::UIGfxTranslator::setLanguage(UFG::UIScreenManager::s_instance->m_translator, v43, 1);
  UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "Global");
  UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "Front-End");
  v101 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v101, "GlobalOverlay", 0i64);
  UFG::TidoGame::CreateInstance(v103, v102, v104);
  if ( UFG::TiDo::GetIsInstantiated() )
  {
    v105 = UFG::TiDo::GetInstance();
    v105->vfptr->Init(v105);
  }
  v106 = UFG::TiDo::GetInstance();
  UFG::TiDo::LoadEventSymbols(v106);
  _(v107);
  _(0i64);
  UFG::qMemoryPool::Init(&gAntlrMemoryPool, "AntlrParser", 0x180000ui64, 0x80000, 1, 1u, UFG::gMainMemoryPool, 1, 1);
  v108 = (char *)UFG::qMemoryPool::Allocate(UFG::gMainMemoryPool, 0x8C8C000ui64, "VideoBroadcast", 0i64, 1u);
  UFG::qMemoryPool::Init(&gVideoBroadcastMemoryPool, "VideoBroadcast", v108, 147374080i64, 0x200000, 1, 1u, 0i64, 1, 1);
  v109 = uidGameStateFE_5;
  if ( UFG::gUIBootModeSkipFE || UFG::gAutoSmoketest || gAutoBenchmarkMode )
  {
    v109 = uidGameStateLoadGame_5;
    if ( gAutoBenchmarkMode )
    {
      UFG::qStringCopy(gameSetupStr, 100, "gameSetupGame_Calibration", -1);
      GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, uidGameStateLoadGame_5);
      if ( GameStateObj )
        UFG::qString::Set(&GameStateObj->mGameStateUserDataStr, gameSetupStr);
    }
    v111 = UFG::ProgressionTracker::Instance();
    GameSetup = UFG::ProgressionTracker::GetGameSetup(v111);
    UFG::GameSetup::SetDebugSaveGame(GameSetup, "Empty");
    mData = UFG::gSmoketestStartTrack.mData;
    if ( !UFG::gTestLevelTest )
      mData = StartTrack.mData;
    UFG::GameSetup::SetLocationDir(GameSetup, mData);
  }
  _(0i64);
  if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, v109) )
    SetUpCameraForFERender(v114);
  DebugTestInit();
  _(0i64);
  if ( (`UFG::qStaticInitAllocator::Instance::`2::`local static guard & 1) == 0 )
  {
    `UFG::qStaticInitAllocator::Instance::`2::`local static guard |= 1u;
    UFG::qStaticInitAllocator::qStaticInitAllocator(&`UFG::qStaticInitAllocator::Instance::`2::instance);
    atexit(`UFG::qStaticInitAllocator::Instance::`2::`dynamic atexit destructor for instance);
  }
  UFG::qStaticInitAllocator::Done(&`UFG::qStaticInitAllocator::Instance::`2::instance);
  InitGameSystems_Stage2();
  UFG::MemoryUtil_MarkAllPools(v115);
  while ( !UFG::LoadingLogic::HasRequiredScreensFinished(&UFG::gLoadingLogic) )
    UFG::qSleep(1u);
  UFG::LoadingLogic::StopLoadScreen(&UFG::gLoadingLogic, 0.0);
  UFG::qString::~qString(&v122);
  UFG::qString::~qString(&v123);
  return 1i64;
}

// File Line: 3547
// RVA: 0x4228E0
signed __int64 __fastcall InitGameSystems_Stage2()
{
  ActionNode *v0; // rbx
  AnimationDataBase *Instance; // rax
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
    Instance = AnimationDataBase::GetInstance();
    AnimationDataBase::ResolveFallbackAnimations(Instance);
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
__int64 __fastcall CloseGameSystems()
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
  UFG::UIScreenManager::s_instance->m_gfxFileOpener->UFG::UIScreenManagerBase::vfptr[5].__vecDelDtor(
    UFG::UIScreenManager::s_instance->m_gfxFileOpener,
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
  bool IsLoadScreenRendering; // bl
  bool v2; // al
  bool v3; // cl
  UFG *v4; // rcx

  UFG::LoadingLogic::UpdateLoadTimers(&UFG::gLoadingLogic, fRealTimeDelta);
  UFG::FlowController::DoMainLoop(&UFG::gFlowController, fRealTimeDelta);
  IsLoadScreenRendering = Render::IsLoadScreenRendering();
  v2 = UFG::UIHK_NISOverlay::IsCurtainVisible() && UFG::UIHK_NISOverlay::IsCurtainStable();
  v3 = IsLoadScreenRendering || v2;
  Render::SetVRAMDefragPerFrameLimits(v3);
  UFG::UpdateIsForcedLetterBox(v4);
  return 1;
}

