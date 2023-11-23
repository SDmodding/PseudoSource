// File Line: 24
// RVA: 0x14E7190
__int64 UFG::HKMetrics::_dynamic_initializer_for__sSessionID__()
{
  UFG::qString::qString(&UFG::HKMetrics::sSessionID);
  return atexit((int (__fastcall *)())UFG::HKMetrics::_dynamic_atexit_destructor_for__sSessionID__);
}

// File Line: 25
// RVA: 0x14E7170
__int64 UFG::HKMetrics::_dynamic_initializer_for__sSequenceID__()
{
  UFG::qString::qString(&UFG::HKMetrics::sSequenceID);
  return atexit((int (__fastcall *)())UFG::HKMetrics::_dynamic_atexit_destructor_for__sSequenceID__);
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
  float y; // xmm1_4
  float z; // xmm2_4

  y = position->y;
  z = position->z;
  UFG::HKMetrics::sPosition.x = position->x;
  UFG::HKMetrics::sPosition.y = y;
  UFG::HKMetrics::sPosition.z = z;
}

// File Line: 50
// RVA: 0x3FC830
UFG::qVector3 *__fastcall UFG::HKMetrics::GetSequencePos()
{
  return &UFG::HKMetrics::sPosition;
}

// File Line: 68
// RVA: 0x3FCB70
void __fastcall UFG::HKMetrics::LogMetricCommon(
        UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *Columns,
        char *param1,
        char *param2,
        char *param3,
        char *param4,
        char *param5,
        char *param6)
{
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v12; // r10
  int v13; // ecx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mPrev; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v16; // rbx
  int v17; // eax
  char *v18; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v21; // rsi
  char *mData; // rbx
  int v23; // eax
  char *v24; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v27; // rsi
  char *v28; // rbx
  int v29; // eax
  char *v30; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v31; // rax
  UFG::allocator::free_link *v32; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v33; // rbx
  int v34; // eax
  char *v35; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v36; // rax
  UFG::allocator::free_link *v37; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v38; // rcx
  double v39; // xmm0_8
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v40; // rax
  UFG::allocator::free_link *v41; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v42; // rbx
  int v43; // eax
  char *v44; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v45; // rax
  UFG::allocator::free_link *v46; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v47; // rbx
  int v48; // eax
  char *v49; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v50; // rax
  UFG::allocator::free_link *v51; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v52; // rbx
  int v53; // eax
  char *v54; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v55; // rax
  UFG::allocator::free_link *v56; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v57; // rbx
  int v58; // eax
  char *v59; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v60; // rax
  UFG::allocator::free_link *v61; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v62; // rbx
  int v63; // eax
  char *v64; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v65; // rax
  UFG::allocator::free_link *v66; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v67; // rbx
  int v68; // eax
  char *v69; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v70; // rax

  v11 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v12 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v11;
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
  mPrev = Columns->mNode.mPrev;
  mPrev->mNext = v12;
  v12->mPrev = mPrev;
  v12->mNext = &Columns->mNode;
  Columns->mNode.mPrev = v12;
  v15 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v16 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v15;
  if ( v15 )
  {
    v15->mNext = v15;
    v15[1].mNext = v15;
    LODWORD(v15[2].mNext) = 7;
    v15[4].mNext = (UFG::allocator::free_link *)"Platform";
    LOBYTE(v15[5].mNext) = 0;
    v17 = UFG::qStringLength("PC64");
    v18 = (char *)UFG::qMalloc(v17 + 1, "StringColumn", 0i64);
    v16[1].mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v18;
    UFG::qStringCopy(v18, 0x7FFFFFFF, "PC64", -1);
  }
  else
  {
    v16 = 0i64;
  }
  v19 = Columns->mNode.mPrev;
  v19->mNext = v16;
  v16->mPrev = v19;
  v16->mNext = &Columns->mNode;
  Columns->mNode.mPrev = v16;
  v20 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v21 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v20;
  if ( v20 )
  {
    mData = UFG::HKMetrics::sSessionID.mData;
    v20->mNext = v20;
    v20[1].mNext = v20;
    LODWORD(v20[2].mNext) = 8;
    v20[4].mNext = (UFG::allocator::free_link *)"SessionID";
    LOBYTE(v20[5].mNext) = 0;
    v23 = UFG::qStringLength(mData);
    v24 = (char *)UFG::qMalloc(v23 + 1, "StringColumn", 0i64);
    v21[1].mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v24;
    UFG::qStringCopy(v24, 0x7FFFFFFF, mData, -1);
  }
  else
  {
    v21 = 0i64;
  }
  v25 = Columns->mNode.mPrev;
  v25->mNext = v21;
  v21->mPrev = v25;
  v21->mNext = &Columns->mNode;
  Columns->mNode.mPrev = v21;
  v26 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v27 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v26;
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
    v27[1].mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v30;
    UFG::qStringCopy(v30, 0x7FFFFFFF, v28, -1);
  }
  else
  {
    v27 = 0i64;
  }
  v31 = Columns->mNode.mPrev;
  v31->mNext = v27;
  v27->mPrev = v31;
  v27->mNext = &Columns->mNode;
  Columns->mNode.mPrev = v27;
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
    v33 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v32;
    if ( v32 )
    {
      v32->mNext = v32;
      v32[1].mNext = v32;
      LODWORD(v32[2].mNext) = 8;
      v32[4].mNext = (UFG::allocator::free_link *)"SequencePos";
      LOBYTE(v32[5].mNext) = 0;
      v34 = UFG::qStringLength(szPosition);
      v35 = (char *)UFG::qMalloc(v34 + 1, "StringColumn", 0i64);
      v33[1].mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v35;
      UFG::qStringCopy(v35, 0x7FFFFFFF, szPosition, -1);
    }
    else
    {
      v33 = 0i64;
    }
    v36 = Columns->mNode.mPrev;
    v36->mNext = v33;
    v33->mPrev = v36;
    v33->mNext = &Columns->mNode;
    Columns->mNode.mPrev = v33;
  }
  v37 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v38 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v37;
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
  v40 = Columns->mNode.mPrev;
  v40->mNext = v38;
  v38->mPrev = v40;
  v38->mNext = &Columns->mNode;
  Columns->mNode.mPrev = v38;
  v41 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  v42 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v41;
  if ( v41 )
  {
    v41->mNext = v41;
    v41[1].mNext = v41;
    LODWORD(v41[2].mNext) = 7;
    v41[4].mNext = (UFG::allocator::free_link *)"Param1";
    LOBYTE(v41[5].mNext) = 0;
    v43 = UFG::qStringLength(param1);
    v44 = (char *)UFG::qMalloc(v43 + 1, "StringColumn", 0i64);
    v42[1].mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v44;
    UFG::qStringCopy(v44, 0x7FFFFFFF, param1, -1);
  }
  else
  {
    v42 = 0i64;
  }
  v45 = Columns->mNode.mPrev;
  v45->mNext = v42;
  v42->mPrev = v45;
  v42->mNext = &Columns->mNode;
  Columns->mNode.mPrev = v42;
  if ( param2 )
  {
    v46 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v47 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v46;
    if ( v46 )
    {
      v46->mNext = v46;
      v46[1].mNext = v46;
      LODWORD(v46[2].mNext) = 7;
      v46[4].mNext = (UFG::allocator::free_link *)"Param2";
      LOBYTE(v46[5].mNext) = 0;
      v48 = UFG::qStringLength(param2);
      v49 = (char *)UFG::qMalloc(v48 + 1, "StringColumn", 0i64);
      v47[1].mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v49;
      UFG::qStringCopy(v49, 0x7FFFFFFF, param2, -1);
    }
    else
    {
      v47 = 0i64;
    }
    v50 = Columns->mNode.mPrev;
    v50->mNext = v47;
    v47->mPrev = v50;
    v47->mNext = &Columns->mNode;
    Columns->mNode.mPrev = v47;
  }
  if ( param3 )
  {
    v51 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v52 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v51;
    if ( v51 )
    {
      v51->mNext = v51;
      v51[1].mNext = v51;
      LODWORD(v51[2].mNext) = 7;
      v51[4].mNext = (UFG::allocator::free_link *)"Param3";
      LOBYTE(v51[5].mNext) = 0;
      v53 = UFG::qStringLength(param3);
      v54 = (char *)UFG::qMalloc(v53 + 1, "StringColumn", 0i64);
      v52[1].mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v54;
      UFG::qStringCopy(v54, 0x7FFFFFFF, param3, -1);
    }
    else
    {
      v52 = 0i64;
    }
    v55 = Columns->mNode.mPrev;
    v55->mNext = v52;
    v52->mPrev = v55;
    v52->mNext = &Columns->mNode;
    Columns->mNode.mPrev = v52;
  }
  if ( param4 )
  {
    v56 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v57 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v56;
    if ( v56 )
    {
      v56->mNext = v56;
      v56[1].mNext = v56;
      LODWORD(v56[2].mNext) = 7;
      v56[4].mNext = (UFG::allocator::free_link *)"Param4";
      LOBYTE(v56[5].mNext) = 0;
      v58 = UFG::qStringLength(param4);
      v59 = (char *)UFG::qMalloc(v58 + 1, "StringColumn", 0i64);
      v57[1].mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v59;
      UFG::qStringCopy(v59, 0x7FFFFFFF, param4, -1);
    }
    else
    {
      v57 = 0i64;
    }
    v60 = Columns->mNode.mPrev;
    v60->mNext = v57;
    v57->mPrev = v60;
    v57->mNext = &Columns->mNode;
    Columns->mNode.mPrev = v57;
  }
  if ( param5 )
  {
    v61 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v62 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v61;
    if ( v61 )
    {
      v61->mNext = v61;
      v61[1].mNext = v61;
      LODWORD(v61[2].mNext) = 7;
      v61[4].mNext = (UFG::allocator::free_link *)"Param5";
      LOBYTE(v61[5].mNext) = 0;
      v63 = UFG::qStringLength(param5);
      v64 = (char *)UFG::qMalloc(v63 + 1, "StringColumn", 0i64);
      v62[1].mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v64;
      UFG::qStringCopy(v64, 0x7FFFFFFF, param5, -1);
    }
    else
    {
      v62 = 0i64;
    }
    v65 = Columns->mNode.mPrev;
    v65->mNext = v62;
    v62->mPrev = v65;
    v62->mNext = &Columns->mNode;
    Columns->mNode.mPrev = v62;
  }
  if ( param6 )
  {
    v66 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v67 = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v66;
    if ( v66 )
    {
      v66->mNext = v66;
      v66[1].mNext = v66;
      LODWORD(v66[2].mNext) = 7;
      v66[4].mNext = (UFG::allocator::free_link *)"Param6";
      LOBYTE(v66[5].mNext) = 0;
      v68 = UFG::qStringLength(param6);
      v69 = (char *)UFG::qMalloc(v68 + 1, "StringColumn", 0i64);
      v67[1].mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v69;
      UFG::qStringCopy(v69, 0x7FFFFFFF, param6, -1);
    }
    else
    {
      v67 = 0i64;
    }
    v70 = Columns->mNode.mPrev;
    v70->mNext = v67;
    v67->mPrev = v70;
    v67->mNext = &Columns->mNode;
    Columns->mNode.mPrev = v67;
  }
}

// File Line: 155
// RVA: 0x3FC840
void __fastcall UFG::HKMetrics::LogMemStats(UFG::HKMetrics::MEM_LOG_DETAIL eMemLogDetailRequired)
{
  UFG::qMemoryPool *i; // rdi
  const char *Name; // rbx
  UFG::NameValueColumnType *j; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mPrev; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mNext; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v6; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v7; // rax
  const char *v8; // rbx
  UFG::NameValueColumnType *k; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v10; // rdx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v11; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v12; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v13; // rax
  const char *v14; // rbx
  UFG::NameValueColumnType *m; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v16; // rdx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v17; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v18; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v19; // rax
  const char *v20; // rbx
  UFG::NameValueColumnType *n; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v22; // rdx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v23; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v24; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v25; // rax
  UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> Columns; // [rsp+40h] [rbp+Fh] BYREF
  UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> v27; // [rsp+50h] [rbp+1Fh] BYREF
  UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> v28; // [rsp+60h] [rbp+2Fh] BYREF
  UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> v29; // [rsp+70h] [rbp+3Fh] BYREF

  if ( UFG::HKMetrics::sCollectBuildStats )
  {
    for ( i = (UFG::qMemoryPool *)UFG::qGetMemoryPool(0i64); i; i = (UFG::qMemoryPool *)UFG::qGetMemoryPool(i) )
    {
      Name = UFG::qMemoryPool::GetName(i);
      UFG::qMemoryPool::GetTotalPoolBytes(i);
      Columns.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      Columns.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      UFG::HKMetrics::LogMetricCommon(&Columns, "Memory", Name, "TotalPoolBytes", 0i64, 0i64, 0i64);
      for ( j = (UFG::NameValueColumnType *)Columns.mNode.mNext;
            (UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *)Columns.mNode.mNext != &Columns;
            j = (UFG::NameValueColumnType *)Columns.mNode.mNext )
      {
        mPrev = j->mPrev;
        mNext = j->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        j->mPrev = j;
        j->mNext = j;
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
        k->mPrev = k;
        k->mNext = k;
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
      for ( m = (UFG::NameValueColumnType *)v28.mNode.mNext;
            (UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *)v28.mNode.mNext != &v28;
            m = (UFG::NameValueColumnType *)v28.mNode.mNext )
      {
        v16 = m->mPrev;
        v17 = m->mNext;
        v16->mNext = v17;
        v17->mPrev = v16;
        m->mPrev = m;
        m->mNext = m;
        UFG::NameValueColumnType::~NameValueColumnType(m);
        operator delete[](m);
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
      for ( n = (UFG::NameValueColumnType *)v29.mNode.mNext;
            (UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *)v29.mNode.mNext != &v29;
            n = (UFG::NameValueColumnType *)v29.mNode.mNext )
      {
        v22 = n->mPrev;
        v23 = n->mNext;
        v22->mNext = v23;
        v23->mPrev = v22;
        n->mPrev = n;
        n->mNext = n;
        UFG::NameValueColumnType::~NameValueColumnType(n);
        operator delete[](n);
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
  unsigned int i; // edi
  UFG::NameValueColumnType *j; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mPrev; // rdx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mNext; // rax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v5; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v6; // rax
  UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> Columns; // [rsp+48h] [rbp-40h] BYREF
  char dest[40]; // [rsp+58h] [rbp-30h] BYREF

  if ( dword_14235C0E0
     + HIDWORD(qword_14235C0D8)
     + (_DWORD)qword_14235C0D8
     + HIDWORD(qword_14235C0D0)
     + (_DWORD)qword_14235C0D0
     + UFG::Metrics::msFramesPerSecBuckets[1]
     + UFG::Metrics::msFramesPerSecBuckets[0] )
  {
    for ( i = 0; i < 7; ++i )
    {
      UFG::qSPrintf(dest, "Bucket%02d", i);
      Columns.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      Columns.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      UFG::HKMetrics::LogMetricCommon(&Columns, "Perf", "FPSBuckets", dest, 0i64, 0i64, 0i64);
      for ( j = (UFG::NameValueColumnType *)Columns.mNode.mNext;
            (UFG::qList<UFG::NameValueColumnType,UFG::NameValueColumnType,1,0> *)Columns.mNode.mNext != &Columns;
            j = (UFG::NameValueColumnType *)Columns.mNode.mNext )
      {
        mPrev = j->mPrev;
        mNext = j->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        j->mPrev = j;
        j->mNext = j;
        UFG::NameValueColumnType::~NameValueColumnType(j);
        operator delete[](j);
      }
      v5 = Columns.mNode.mPrev;
      v6 = Columns.mNode.mNext;
      Columns.mNode.mPrev->mNext = Columns.mNode.mNext;
      v6->mPrev = v5;
      Columns.mNode.mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
      Columns.mNode.mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&Columns;
    }
  }
}

