// File Line: 24
// RVA: 0x14E7190
__int64 UFG::HKMetrics::_dynamic_initializer_for__sSessionID__()
{
  UFG::qString::qString(&UFG::HKMetrics::sSessionID);
  return atexit(UFG::HKMetrics::_dynamic_atexit_destructor_for__sSessionID__);
}

// File Line: 25
// RVA: 0x14E7170
__int64 UFG::HKMetrics::_dynamic_initializer_for__sSequenceID__()
{
  UFG::qString::qString(&UFG::HKMetrics::sSequenceID);
  return atexit(UFG::HKMetrics::_dynamic_atexit_destructor_for__sSequenceID__);
}

// File Line: 26
// RVA: 0x14E7130
void UFG::HKMetrics::_dynamic_initializer_for__sPosition__()
{
  UFG::HKMetrics::sPosition = UFG::qVector3::msZero;
}

// File Line: 30
// RVA: 0x3FD4C0
void __fastcall UFG::HKMetrics::SetSessionID(const char *sessionID)
{
  UFG::qString::Set(&UFG::HKMetrics::sSessionID, sessionID);
}

// File Line: 35
// RVA: 0x3FD470
void __fastcall UFG::HKMetrics::SetSequenceID(const char *sequenceID)
{
  UFG::qString::Set(&UFG::HKMetrics::sSequenceID, sequenceID);
}

// File Line: 40
// RVA: 0x3FD4B0
void __fastcall UFG::HKMetrics::SetSequenceTime(float time)
{
  UFG::HKMetrics::sTime = time;
}

// File Line: 45
// RVA: 0x3FD480
void __fastcall UFG::HKMetrics::SetSequencePos(UFG::qVector3 *position)
{
  float v1; // xmm1_4
  float v2; // xmm2_4

  v1 = position->y;
  v2 = position->z;
  UFG::HKMetrics::sPosition.x = position->x;
  UFG::HKMetrics::sPosition.y = v1;
  UFG::HKMetrics::sPosition.z = v2;
}

// File Line: 50
// RVA: 0x3FC830
UFG::qVector3 *__fastcall UFG::HKMetrics::GetSequencePos()
{
  return &UFG::HKMetrics::sPosition;
}

// File Line: 68
// RVA: 0x3FCB70
void __fastcall UFG::HKMetrics::LogMetricCommon(UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *Columns, const char *param1, const char *param2, const char *param3, const char *param4, const char *param5, const char *param6)
{
  const char *v7; // r14
  const char *v8; // rbp
  const char *v9; // r15
  UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *v10; // rdi
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // r10
  int v13; // ecx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rbx
  int v17; // eax
  char *v18; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rsi
  char *v22; // rbx
  int v23; // eax
  char *v24; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::allocator::free_link *v27; // rsi
  char *v28; // rbx
  int v29; // eax
  char *v30; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v31; // rax
  UFG::allocator::free_link *v32; // rax
  UFG::allocator::free_link *v33; // rbx
  int v34; // eax
  char *v35; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v36; // rax
  UFG::allocator::free_link *v37; // rax
  UFG::allocator::free_link *v38; // rcx
  double v39; // xmm0_8
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v40; // rax
  UFG::allocator::free_link *v41; // rax
  UFG::allocator::free_link *v42; // rbx
  int v43; // eax
  char *v44; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v45; // rax
  UFG::allocator::free_link *v46; // rax
  UFG::allocator::free_link *v47; // rbx
  int v48; // eax
  char *v49; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v50; // rax
  UFG::allocator::free_link *v51; // rax
  UFG::allocator::free_link *v52; // rbx
  int v53; // eax
  char *v54; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v55; // rax
  UFG::allocator::free_link *v56; // rax
  UFG::allocator::free_link *v57; // rbx
  int v58; // eax
  char *v59; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v60; // rax
  UFG::allocator::free_link *v61; // rax
  UFG::allocator::free_link *v62; // rbx
  int v63; // eax
  char *v64; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v65; // rax
  UFG::allocator::free_link *v66; // rax
  UFG::allocator::free_link *v67; // rbx
  int v68; // eax
  char *v69; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v70; // rax

  v7 = param3;
  v8 = param2;
  v9 = param1;
  v10 = Columns;
  v11 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v12 = v11;
  if ( v11 )
  {
    v13 = UFG::gCL_number;
    v11->mNext = v11;
    v11[1].mNext = v11;
    LODWORD(v11[2].mNext) = 5;
    v11[4].mNext = (UFG::allocator::free_link *)"Changelist";
    LOBYTE(v11[5].mNext) = 0;
    LODWORD(v11[3].mNext) = v13;
  }
  else
  {
    v12 = 0i64;
  }
  v14 = v10->mNode.mPrev;
  v14->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v12;
  v12->mNext = (UFG::allocator::free_link *)v14;
  v12[1].mNext = (UFG::allocator::free_link *)v10;
  v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v12;
  v15 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v16 = v15;
  if ( v15 )
  {
    v15->mNext = v15;
    v15[1].mNext = v15;
    LODWORD(v15[2].mNext) = 7;
    v15[4].mNext = (UFG::allocator::free_link *)"Platform";
    LOBYTE(v15[5].mNext) = 0;
    v17 = UFG::qStringLength("PC64");
    v18 = (char *)UFG::qMalloc(v17 + 1, "StringColumn", 0i64);
    v16[3].mNext = (UFG::allocator::free_link *)v18;
    UFG::qStringCopy(v18, 0x7FFFFFFF, "PC64", -1);
  }
  else
  {
    v16 = 0i64;
  }
  v19 = v10->mNode.mPrev;
  v19->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v16;
  v16->mNext = (UFG::allocator::free_link *)v19;
  v16[1].mNext = (UFG::allocator::free_link *)v10;
  v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v16;
  v20 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v21 = v20;
  if ( v20 )
  {
    v22 = UFG::HKMetrics::sSessionID.mData;
    v20->mNext = v20;
    v20[1].mNext = v20;
    LODWORD(v20[2].mNext) = 8;
    v20[4].mNext = (UFG::allocator::free_link *)"SessionID";
    LOBYTE(v20[5].mNext) = 0;
    v23 = UFG::qStringLength(v22);
    v24 = (char *)UFG::qMalloc(v23 + 1, "StringColumn", 0i64);
    v21[3].mNext = (UFG::allocator::free_link *)v24;
    UFG::qStringCopy(v24, 0x7FFFFFFF, v22, -1);
  }
  else
  {
    v21 = 0i64;
  }
  v25 = v10->mNode.mPrev;
  v25->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v21;
  v21->mNext = (UFG::allocator::free_link *)v25;
  v21[1].mNext = (UFG::allocator::free_link *)v10;
  v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v21;
  v26 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v27 = v26;
  if ( v26 )
  {
    v28 = UFG::HKMetrics::sSequenceID.mData;
    v26->mNext = v26;
    v26[1].mNext = v26;
    LODWORD(v26[2].mNext) = 8;
    v26[4].mNext = (UFG::allocator::free_link *)"SequenceID";
    LOBYTE(v26[5].mNext) = 0;
    v29 = UFG::qStringLength(v28);
    v30 = (char *)UFG::qMalloc(v29 + 1, "StringColumn", 0i64);
    v27[3].mNext = (UFG::allocator::free_link *)v30;
    UFG::qStringCopy(v30, 0x7FFFFFFF, v28, -1);
  }
  else
  {
    v27 = 0i64;
  }
  v31 = v10->mNode.mPrev;
  v31->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v27;
  v27->mNext = (UFG::allocator::free_link *)v31;
  v27[1].mNext = (UFG::allocator::free_link *)v10;
  v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v27;
  if ( UFG::HKMetrics::sPosition.x != UFG::qVector3::msZero.x
    || UFG::HKMetrics::sPosition.y != UFG::qVector3::msZero.y
    || UFG::HKMetrics::sPosition.z != UFG::qVector3::msZero.z )
  {
    UFG::qSPrintf(
      szPosition,
      "%f,%f,%f",
      UFG::HKMetrics::sPosition.x,
      UFG::HKMetrics::sPosition.y,
      UFG::HKMetrics::sPosition.z);
    v32 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v33 = v32;
    if ( v32 )
    {
      v32->mNext = v32;
      v32[1].mNext = v32;
      LODWORD(v32[2].mNext) = 8;
      v32[4].mNext = (UFG::allocator::free_link *)"SequencePos";
      LOBYTE(v32[5].mNext) = 0;
      v34 = UFG::qStringLength(szPosition);
      v35 = (char *)UFG::qMalloc(v34 + 1, "StringColumn", 0i64);
      v33[3].mNext = (UFG::allocator::free_link *)v35;
      UFG::qStringCopy(v35, 0x7FFFFFFF, szPosition, -1);
    }
    else
    {
      v33 = 0i64;
    }
    v36 = v10->mNode.mPrev;
    v36->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v33;
    v33->mNext = (UFG::allocator::free_link *)v36;
    v33[1].mNext = (UFG::allocator::free_link *)v10;
    v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v33;
  }
  v37 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v38 = v37;
  if ( v37 )
  {
    v39 = UFG::HKMetrics::sTime;
    v37->mNext = v37;
    v37[1].mNext = v37;
    LODWORD(v37[2].mNext) = 4;
    v37[4].mNext = (UFG::allocator::free_link *)"SequenceTime";
    LOBYTE(v37[5].mNext) = 0;
    *(double *)&v37[3].mNext = v39;
  }
  else
  {
    v38 = 0i64;
  }
  v40 = v10->mNode.mPrev;
  v40->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v38;
  v38->mNext = (UFG::allocator::free_link *)v40;
  v38[1].mNext = (UFG::allocator::free_link *)v10;
  v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v38;
  v41 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v42 = v41;
  if ( v41 )
  {
    v41->mNext = v41;
    v41[1].mNext = v41;
    LODWORD(v41[2].mNext) = 7;
    v41[4].mNext = (UFG::allocator::free_link *)"Param1";
    LOBYTE(v41[5].mNext) = 0;
    v43 = UFG::qStringLength(v9);
    v44 = (char *)UFG::qMalloc(v43 + 1, "StringColumn", 0i64);
    v42[3].mNext = (UFG::allocator::free_link *)v44;
    UFG::qStringCopy(v44, 0x7FFFFFFF, v9, -1);
  }
  else
  {
    v42 = 0i64;
  }
  v45 = v10->mNode.mPrev;
  v45->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v42;
  v42->mNext = (UFG::allocator::free_link *)v45;
  v42[1].mNext = (UFG::allocator::free_link *)v10;
  v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v42;
  if ( v8 )
  {
    v46 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v47 = v46;
    if ( v46 )
    {
      v46->mNext = v46;
      v46[1].mNext = v46;
      LODWORD(v46[2].mNext) = 7;
      v46[4].mNext = (UFG::allocator::free_link *)"Param2";
      LOBYTE(v46[5].mNext) = 0;
      v48 = UFG::qStringLength(v8);
      v49 = (char *)UFG::qMalloc(v48 + 1, "StringColumn", 0i64);
      v47[3].mNext = (UFG::allocator::free_link *)v49;
      UFG::qStringCopy(v49, 0x7FFFFFFF, v8, -1);
    }
    else
    {
      v47 = 0i64;
    }
    v50 = v10->mNode.mPrev;
    v50->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v47;
    v47->mNext = (UFG::allocator::free_link *)v50;
    v47[1].mNext = (UFG::allocator::free_link *)v10;
    v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v47;
  }
  if ( v7 )
  {
    v51 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v52 = v51;
    if ( v51 )
    {
      v51->mNext = v51;
      v51[1].mNext = v51;
      LODWORD(v51[2].mNext) = 7;
      v51[4].mNext = (UFG::allocator::free_link *)"Param3";
      LOBYTE(v51[5].mNext) = 0;
      v53 = UFG::qStringLength(v7);
      v54 = (char *)UFG::qMalloc(v53 + 1, "StringColumn", 0i64);
      v52[3].mNext = (UFG::allocator::free_link *)v54;
      UFG::qStringCopy(v54, 0x7FFFFFFF, v7, -1);
    }
    else
    {
      v52 = 0i64;
    }
    v55 = v10->mNode.mPrev;
    v55->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v52;
    v52->mNext = (UFG::allocator::free_link *)v55;
    v52[1].mNext = (UFG::allocator::free_link *)v10;
    v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v52;
  }
  if ( param4 )
  {
    v56 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v57 = v56;
    if ( v56 )
    {
      v56->mNext = v56;
      v56[1].mNext = v56;
      LODWORD(v56[2].mNext) = 7;
      v56[4].mNext = (UFG::allocator::free_link *)"Param4";
      LOBYTE(v56[5].mNext) = 0;
      v58 = UFG::qStringLength(param4);
      v59 = (char *)UFG::qMalloc(v58 + 1, "StringColumn", 0i64);
      v57[3].mNext = (UFG::allocator::free_link *)v59;
      UFG::qStringCopy(v59, 0x7FFFFFFF, param4, -1);
    }
    else
    {
      v57 = 0i64;
    }
    v60 = v10->mNode.mPrev;
    v60->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v57;
    v57->mNext = (UFG::allocator::free_link *)v60;
    v57[1].mNext = (UFG::allocator::free_link *)v10;
    v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v57;
  }
  if ( param5 )
  {
    v61 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v62 = v61;
    if ( v61 )
    {
      v61->mNext = v61;
      v61[1].mNext = v61;
      LODWORD(v61[2].mNext) = 7;
      v61[4].mNext = (UFG::allocator::free_link *)"Param5";
      LOBYTE(v61[5].mNext) = 0;
      v63 = UFG::qStringLength(param5);
      v64 = (char *)UFG::qMalloc(v63 + 1, "StringColumn", 0i64);
      v62[3].mNext = (UFG::allocator::free_link *)v64;
      UFG::qStringCopy(v64, 0x7FFFFFFF, param5, -1);
    }
    else
    {
      v62 = 0i64;
    }
    v65 = v10->mNode.mPrev;
    v65->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v62;
    v62->mNext = (UFG::allocator::free_link *)v65;
    v62[1].mNext = (UFG::allocator::free_link *)v10;
    v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v62;
  }
  if ( param6 )
  {
    v66 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v67 = v66;
    if ( v66 )
    {
      v66->mNext = v66;
      v66[1].mNext = v66;
      LODWORD(v66[2].mNext) = 7;
      v66[4].mNext = (UFG::allocator::free_link *)"Param6";
      LOBYTE(v66[5].mNext) = 0;
      v68 = UFG::qStringLength(param6);
      v69 = (char *)UFG::qMalloc(v68 + 1, "StringColumn", 0i64);
      v67[3].mNext = (UFG::allocator::free_link *)v69;
      UFG::qStringCopy(v69, 0x7FFFFFFF, param6, -1);
    }
    else
    {
      v67 = 0i64;
    }
    v70 = v10->mNode.mPrev;
    v70->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v67;
    v67->mNext = (UFG::allocator::free_link *)v70;
    v67[1].mNext = (UFG::allocator::free_link *)v10;
    v10->mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v67;
  }
}

// File Line: 155
// RVA: 0x3FC840
void __fastcall UFG::HKMetrics::LogMemStats(UFG::HKMetrics::MEM_LOG_DETAIL eMemLogDetailRequired)
{
  UFG::qMemoryPool *i; // rdi
  const char *v2; // rbx
  UFG::NameValueColumnType *j; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v4; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v5; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v6; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v7; // rax
  const char *v8; // rbx
  UFG::NameValueColumnType *k; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v10; // rdx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v11; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v12; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v13; // rax
  const char *v14; // rbx
  UFG::NameValueColumnType *l; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v16; // rdx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v17; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v18; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v19; // rax
  const char *v20; // rbx
  UFG::NameValueColumnType *m; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v22; // rdx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v23; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v24; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v25; // rax
  UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> Columns; // [rsp+40h] [rbp+Fh]
  UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> v27; // [rsp+50h] [rbp+1Fh]
  UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> v28; // [rsp+60h] [rbp+2Fh]
  UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> v29; // [rsp+70h] [rbp+3Fh]

  if ( UFG::HKMetrics::sCollectBuildStats )
  {
    for ( i = UFG::qGetMemoryPool(0i64); i; i = UFG::qGetMemoryPool(i) )
    {
      v2 = UFG::qMemoryPool::GetName(i);
      UFG::qMemoryPool::GetTotalPoolBytes(i);
      Columns.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      Columns.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      UFG::HKMetrics::LogMetricCommon(&Columns, "Memory", v2, "TotalPoolBytes", 0i64, 0i64, 0i64);
      for ( j = (UFG::NameValueColumnType *)Columns.mNode.mNext;
            (UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *)Columns.mNode.mNext != &Columns;
            j = (UFG::NameValueColumnType *)Columns.mNode.mNext )
      {
        v4 = j->mPrev;
        v5 = j->mNext;
        v4->mNext = v5;
        v5->mPrev = v4;
        j->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&j->mPrev;
        j->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&j->mPrev;
        UFG::NameValueColumnType::~NameValueColumnType(j);
        operator delete[](j);
      }
      v6 = Columns.mNode.mPrev;
      v7 = Columns.mNode.mNext;
      Columns.mNode.mPrev->mNext = Columns.mNode.mNext;
      v7->mPrev = v6;
      Columns.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      Columns.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      v8 = UFG::qMemoryPool::GetName(i);
      UFG::qMemoryPool::GetLargeFreeBytes(i);
      v27.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v27;
      v27.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v27;
      UFG::HKMetrics::LogMetricCommon(&v27, "Memory", v8, "LargestFreeBytes", 0i64, 0i64, 0i64);
      for ( k = (UFG::NameValueColumnType *)v27.mNode.mNext;
            (UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *)v27.mNode.mNext != &v27;
            k = (UFG::NameValueColumnType *)v27.mNode.mNext )
      {
        v10 = k->mPrev;
        v11 = k->mNext;
        v10->mNext = v11;
        v11->mPrev = v10;
        k->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&k->mPrev;
        k->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&k->mPrev;
        UFG::NameValueColumnType::~NameValueColumnType(k);
        operator delete[](k);
      }
      v12 = v27.mNode.mPrev;
      v13 = v27.mNode.mNext;
      v27.mNode.mPrev->mNext = v27.mNode.mNext;
      v13->mPrev = v12;
      v27.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v27;
      v27.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v27;
      v14 = UFG::qMemoryPool::GetName(i);
      UFG::qMemoryPool::GetTotalFreeBytes(i);
      v28.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v28;
      v28.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v28;
      UFG::HKMetrics::LogMetricCommon(&v28, "Memory", v14, "TotalFreeBytes", 0i64, 0i64, 0i64);
      for ( l = (UFG::NameValueColumnType *)v28.mNode.mNext;
            (UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *)v28.mNode.mNext != &v28;
            l = (UFG::NameValueColumnType *)v28.mNode.mNext )
      {
        v16 = l->mPrev;
        v17 = l->mNext;
        v16->mNext = v17;
        v17->mPrev = v16;
        l->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&l->mPrev;
        l->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&l->mPrev;
        UFG::NameValueColumnType::~NameValueColumnType(l);
        operator delete[](l);
      }
      v18 = v28.mNode.mPrev;
      v19 = v28.mNode.mNext;
      v28.mNode.mPrev->mNext = v28.mNode.mNext;
      v19->mPrev = v18;
      v28.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v28;
      v28.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v28;
      v20 = UFG::qMemoryPool::GetName(i);
      UFG::qMemoryPool::GetLargeHighWaterBytes(i);
      v29.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v29;
      v29.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v29;
      UFG::HKMetrics::LogMetricCommon(&v29, "Memory", v20, "HighWaterBytes", 0i64, 0i64, 0i64);
      for ( m = (UFG::NameValueColumnType *)v29.mNode.mNext;
            (UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *)v29.mNode.mNext != &v29;
            m = (UFG::NameValueColumnType *)v29.mNode.mNext )
      {
        v22 = m->mPrev;
        v23 = m->mNext;
        v22->mNext = v23;
        v23->mPrev = v22;
        m->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&m->mPrev;
        m->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&m->mPrev;
        UFG::NameValueColumnType::~NameValueColumnType(m);
        operator delete[](m);
      }
      v24 = v29.mNode.mPrev;
      v25 = v29.mNode.mNext;
      v29.mNode.mPrev->mNext = v29.mNode.mNext;
      v25->mPrev = v24;
      v29.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v29;
      v29.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v29;
    }
  }
}

// File Line: 227
// RVA: 0x3FD290
void __fastcall UFG::HKMetrics::LogPerfStats(UFG::HKMetrics *this)
{
  unsigned int v1; // edi
  UFG::NameValueColumnType *i; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v3; // rdx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v4; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v5; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v6; // rax
  UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> Columns; // [rsp+48h] [rbp-40h]
  char dest; // [rsp+58h] [rbp-30h]

  if ( dword_14235C0E0
     + HIDWORD(qword_14235C0D8)
     + (_DWORD)qword_14235C0D8
     + HIDWORD(qword_14235C0D0)
     + (_DWORD)qword_14235C0D0
     + UFG::Metrics::msFramesPerSecBuckets[1]
     + UFG::Metrics::msFramesPerSecBuckets[0] )
  {
    v1 = 0;
    do
    {
      UFG::qSPrintf(&dest, "Bucket%02d", v1);
      Columns.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      Columns.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      UFG::HKMetrics::LogMetricCommon(&Columns, "Perf", "FPSBuckets", &dest, 0i64, 0i64, 0i64);
      for ( i = (UFG::NameValueColumnType *)Columns.mNode.mNext;
            (UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *)Columns.mNode.mNext != &Columns;
            i = (UFG::NameValueColumnType *)Columns.mNode.mNext )
      {
        v3 = i->mPrev;
        v4 = i->mNext;
        v3->mNext = v4;
        v4->mPrev = v3;
        i->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&i->mPrev;
        i->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&i->mPrev;
        UFG::NameValueColumnType::~NameValueColumnType(i);
        operator delete[](i);
      }
      v5 = Columns.mNode.mPrev;
      v6 = Columns.mNode.mNext;
      Columns.mNode.mPrev->mNext = Columns.mNode.mNext;
      v6->mPrev = v5;
      Columns.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      Columns.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      ++v1;
    }
    while ( v1 < 7 );
  }
}

