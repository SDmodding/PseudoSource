// File Line: 47
// RVA: 0x48ADD0
void __fastcall UFG::GameSnapshot::GameSnapshot(UFG::GameSnapshot *this)
{
  UFG::PersistentData::ID *mIDs; // r15
  UFG::PersistentData::Int *mInts; // rsi
  UFG::PersistentData::Float *mFloats; // rdi
  UFG::PersistentData::String *mStrings; // r12
  UFG::GameSnapshot *v6; // r14
  __int64 v7; // r13
  __int64 v8; // rcx
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rdi
  int v12; // edi
  UFG::PersistentData::MapInt **mpMapInts; // rsi
  UFG::allocator::free_link *v14; // rax
  UFG::PersistentData::MapUInt64 *v15; // rax
  int v16; // edi
  UFG::PersistentData::MapFloat **mpMapFloats; // rsi
  UFG::allocator::free_link *v18; // rax
  int v19; // edi
  UFG::PersistentData::MapBinary **mpMapBinaries; // rsi
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::allocator::free_link *v24; // rax
  UFG::allocator::free_link *v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::allocator::free_link *v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::allocator::free_link *v29; // rax
  UFG::allocator::free_link *v30; // rax
  UFG::allocator::free_link *v31; // rax
  UFG::allocator::free_link *v32; // rax
  UFG::allocator::free_link *v33; // rax
  UFG::allocator::free_link *v34; // rax
  UFG::allocator::free_link *v35; // rax
  UFG::allocator::free_link *v36; // rax
  UFG::allocator::free_link *v37; // rax
  UFG::allocator::free_link *v38; // rax
  UFG::allocator::free_link *v39; // rax
  UFG::allocator::free_link *v40; // rax
  UFG::allocator::free_link *v41; // rax
  UFG::allocator::free_link *v42; // rax
  UFG::allocator::free_link *v43; // rax
  UFG::allocator::free_link *v44; // rax
  UFG::allocator::free_link *v45; // rax
  UFG::allocator::free_link *v46; // rax
  UFG::allocator::free_link *v47; // rax
  UFG::allocator::free_link *v48; // rax
  UFG::allocator::free_link *v49; // rax
  UFG::allocator::free_link *v50; // rax
  UFG::allocator::free_link *v51; // rax
  UFG::allocator::free_link *v52; // rax
  UFG::allocator::free_link *v53; // rax
  UFG::allocator::free_link *v54; // rax
  UFG::allocator::free_link *v55; // rax
  UFG::allocator::free_link *v56; // rax
  UFG::allocator::free_link *v57; // rax
  UFG::allocator::free_link *v58; // rax
  UFG::allocator::free_link *v59; // rax
  UFG::allocator::free_link *v60; // rax
  UFG::allocator::free_link *v61; // rax
  UFG::allocator::free_link *v62; // rax
  UFG::allocator::free_link *v63; // rax
  UFG::allocator::free_link *v64; // rax
  UFG::allocator::free_link *v65; // rax
  UFG::allocator::free_link *v66; // rax
  UFG::allocator::free_link *v67; // rax
  UFG::allocator::free_link *v68; // rax
  UFG::allocator::free_link *v69; // rax
  UFG::allocator::free_link *v70; // rax
  UFG::allocator::free_link *v71; // rax
  UFG::allocator::free_link *v72; // rax
  UFG::allocator::free_link *v73; // rax
  UFG::allocator::free_link *v74; // rax
  UFG::allocator::free_link *v75; // rax
  UFG::allocator::free_link *v76; // rax
  UFG::allocator::free_link *v77; // rax
  UFG::allocator::free_link *v78; // rax
  UFG::allocator::free_link *v79; // rax
  UFG::allocator::free_link *v80; // rax
  UFG::allocator::free_link *v81; // rax
  UFG::allocator::free_link *v82; // rax
  UFG::allocator::free_link *v83; // rax
  UFG::allocator::free_link *v84; // rax
  UFG::allocator::free_link *v85; // rax
  UFG::allocator::free_link *v86; // rax
  UFG::allocator::free_link *v87; // rax
  UFG::allocator::free_link *v88; // rax
  UFG::allocator::free_link *v89; // rax
  UFG::allocator::free_link *v90; // rax
  UFG::allocator::free_link *v91; // rax
  UFG::allocator::free_link *v92; // rax
  UFG::allocator::free_link *v93; // rax
  UFG::allocator::free_link *v94; // rax
  UFG::allocator::free_link *v95; // rax
  UFG::allocator::free_link *v96; // rax
  UFG::allocator::free_link *v97; // rax
  UFG::allocator::free_link *v98; // rax
  UFG::allocator::free_link *v99; // rax
  UFG::allocator::free_link *v100; // rax
  UFG::allocator::free_link *v101; // rax
  UFG::allocator::free_link *v102; // rax
  UFG::allocator::free_link *v103; // rax
  UFG::allocator::free_link *v104; // rax
  UFG::allocator::free_link *v105; // rax
  UFG::allocator::free_link *v106; // rax
  UFG::allocator::free_link *v107; // rax
  UFG::allocator::free_link *v108; // rax
  UFG::allocator::free_link *v109; // rax
  UFG::allocator::free_link *v110; // rax
  UFG::allocator::free_link *v111; // rax
  UFG::allocator::free_link *v112; // rax
  UFG::allocator::free_link *v113; // rax
  UFG::allocator::free_link *v114; // rax
  UFG::SimpleTimer v115; // [rsp+38h] [rbp-38h] BYREF
  UFG::qString v116; // [rsp+48h] [rbp-28h] BYREF

  `eh vector constructor iterator(this, 0x10ui64, 30, (void (__fastcall *)(void *))UFG::PersistentData::Time::Time);
  mIDs = this->mIDs;
  `eh vector constructor iterator(this->mIDs, 4ui64, 44, (void (__fastcall *)(void *))UFG::PersistentData::ID::ID);
  `eh vector constructor iterator(
    this->mBools,
    1ui64,
    58,
    (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  mInts = this->mInts;
  `eh vector constructor iterator(
    this->mInts,
    4ui64,
    163,
    (void (__fastcall *)(void *))UFG::PersistentData::Float::Float);
  `eh vector constructor iterator(
    this->mUInt64s,
    8ui64,
    1,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  mFloats = this->mFloats;
  `eh vector constructor iterator(
    this->mFloats,
    4ui64,
    139,
    (void (__fastcall *)(void *))UFG::PersistentData::Float::Float);
  `eh vector constructor iterator(
    this->mIntsRanged,
    8ui64,
    7,
    (void (__fastcall *)(void *))UFG::PersistentData::IntRanged::IntRanged);
  `eh vector constructor iterator(
    this->mFloatsRanged,
    8ui64,
    1,
    (void (__fastcall *)(void *))UFG::PersistentData::IntRanged::IntRanged);
  mStrings = this->mStrings;
  `eh vector constructor iterator(
    this->mStrings,
    0x28ui64,
    25,
    (void (__fastcall *)(void *))UFG::PersistentData::String::String);
  `eh vector constructor iterator(
    this->mBinaries,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::PersistentData::Binary::Binary);
  v6 = this;
  v7 = 30i64;
  do
  {
    UFG::SimpleTimer::SimpleTimer(&v115);
    v6->mTimes[0].mTimer = v115;
    _((AMD_HD3D *)&v115);
    v6 = (UFG::GameSnapshot *)((char *)v6 + 16);
    --v7;
  }
  while ( v7 );
  v8 = 44i64;
  do
  {
    mIDs->mValue = UFG::gNullQSymbol;
    ++mIDs;
    --v8;
  }
  while ( v8 );
  *(_QWORD *)&this->mBools[0].mValue = 0i64;
  *(_QWORD *)&this->mBools[8].mValue = 0i64;
  *(_QWORD *)&this->mBools[16].mValue = 0i64;
  *(_QWORD *)&this->mBools[24].mValue = 0i64;
  *(_QWORD *)&this->mBools[32].mValue = 0i64;
  *(_QWORD *)&this->mBools[40].mValue = 0i64;
  *(_QWORD *)&this->mBools[48].mValue = 0i64;
  *(_WORD *)&this->mBools[56].mValue = 0;
  v9 = 10i64;
  do
  {
    *(_QWORD *)&mInts->mValue = 0i64;
    *(_QWORD *)&mInts[2].mValue = 0i64;
    *(_QWORD *)&mInts[4].mValue = 0i64;
    mInts += 16;
    *(_QWORD *)&mInts[-10].mValue = 0i64;
    *(_QWORD *)&mInts[-8].mValue = 0i64;
    *(_QWORD *)&mInts[-6].mValue = 0i64;
    *(_QWORD *)&mInts[-4].mValue = 0i64;
    *(_QWORD *)&mInts[-2].mValue = 0i64;
    --v9;
  }
  while ( v9 );
  *(_QWORD *)&mInts->mValue = 0i64;
  mInts[2].mValue = 0;
  this->mUInt64s[0].mValue = 0i64;
  v10 = 8i64;
  do
  {
    *(_QWORD *)&mFloats->mValue = 0i64;
    *(_QWORD *)&mFloats[2].mValue = 0i64;
    *(_QWORD *)&mFloats[4].mValue = 0i64;
    mFloats += 16;
    *(_QWORD *)&mFloats[-10].mValue = 0i64;
    *(_QWORD *)&mFloats[-8].mValue = 0i64;
    *(_QWORD *)&mFloats[-6].mValue = 0i64;
    *(_QWORD *)&mFloats[-4].mValue = 0i64;
    *(_QWORD *)&mFloats[-2].mValue = 0i64;
    --v10;
  }
  while ( v10 );
  *(_QWORD *)&mFloats->mValue = 0i64;
  *(_QWORD *)&mFloats[2].mValue = 0i64;
  *(_QWORD *)&mFloats[4].mValue = 0i64;
  *(_QWORD *)&mFloats[6].mValue = 0i64;
  *(_QWORD *)&mFloats[8].mValue = 0i64;
  mFloats[10].mValue = 0.0;
  this->mIntsRanged[0] = 0i64;
  this->mIntsRanged[1] = 0i64;
  this->mIntsRanged[2] = 0i64;
  this->mIntsRanged[3] = 0i64;
  this->mIntsRanged[4] = 0i64;
  this->mIntsRanged[5] = 0i64;
  this->mIntsRanged[6] = 0i64;
  this->mFloatsRanged[0] = 0i64;
  v11 = 25i64;
  do
  {
    UFG::qString::qString(&v116);
    UFG::qString::Set(&mStrings->mValue, v116.mData, v116.mLength, 0i64, 0);
    UFG::qString::~qString(&v116);
    ++mStrings;
    --v11;
  }
  while ( v11 );
  this->mBinaries[0].mpBuffer = 0i64;
  this->mBinaries[0].mSize = 0;
  this->mBinaries[1].mpBuffer = 0i64;
  this->mBinaries[1].mSize = 0;
  this->mBinaries[2].mpBuffer = 0i64;
  this->mBinaries[2].mSize = 0;
  v12 = 0;
  mpMapInts = this->mpMapInts;
  do
  {
    v14 = UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    if ( v14 )
    {
      v14[1].mNext = 0i64;
      v14->mNext = 0i64;
      LODWORD(v14[2].mNext) = v12;
    }
    else
    {
      v14 = 0i64;
    }
    *mpMapInts = (UFG::PersistentData::MapInt *)v14;
    ++v12;
    ++mpMapInts;
  }
  while ( v12 < 47 );
  v15 = (UFG::PersistentData::MapUInt64 *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
  if ( v15 )
  {
    v15->mValues.p = 0i64;
    *(_QWORD *)&v15->mValues.size = 0i64;
    v15->mPersistentDataType = 0;
  }
  else
  {
    v15 = 0i64;
  }
  this->mpMapUInt64s[0] = v15;
  v16 = 0;
  mpMapFloats = this->mpMapFloats;
  do
  {
    v18 = UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    if ( v18 )
    {
      v18[1].mNext = 0i64;
      v18->mNext = 0i64;
      LODWORD(v18[2].mNext) = v16;
    }
    else
    {
      v18 = 0i64;
    }
    *mpMapFloats = (UFG::PersistentData::MapFloat *)v18;
    ++v16;
    ++mpMapFloats;
  }
  while ( v16 < 18 );
  v19 = 0;
  mpMapBinaries = this->mpMapBinaries;
  do
  {
    v21 = UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    if ( v21 )
    {
      v21[1].mNext = 0i64;
      v21->mNext = 0i64;
      LODWORD(v21[2].mNext) = v19;
    }
    else
    {
      v21 = 0i64;
    }
    *mpMapBinaries = (UFG::PersistentData::MapBinary *)v21;
    ++v19;
    ++mpMapBinaries;
  }
  while ( v19 < 2 );
  v22 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v22 )
  {
    LODWORD(v22->mNext) = 1;
    v22[2].mNext = 0i64;
    v22[1].mNext = 0i64;
    v22[4].mNext = 0i64;
    v22[3].mNext = 0i64;
    LODWORD(v22[5].mNext) = 0;
  }
  else
  {
    v22 = 0i64;
  }
  this->mpMapBools[0] = (UFG::PersistentData::MapBool *)v22;
  v23 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v23 )
  {
    LODWORD(v23->mNext) = 1;
    v23[2].mNext = 0i64;
    v23[1].mNext = 0i64;
    v23[4].mNext = 0i64;
    v23[3].mNext = 0i64;
    LODWORD(v23[5].mNext) = 1;
  }
  else
  {
    v23 = 0i64;
  }
  this->mpMapBools[1] = (UFG::PersistentData::MapBool *)v23;
  v24 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v24 )
  {
    LODWORD(v24->mNext) = 1;
    v24[2].mNext = 0i64;
    v24[1].mNext = 0i64;
    v24[4].mNext = 0i64;
    v24[3].mNext = 0i64;
    LODWORD(v24[5].mNext) = 2;
  }
  else
  {
    v24 = 0i64;
  }
  this->mpMapBools[2] = (UFG::PersistentData::MapBool *)v24;
  v25 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v25 )
  {
    LODWORD(v25->mNext) = 0;
    v25[2].mNext = 0i64;
    v25[1].mNext = 0i64;
    v25[4].mNext = 0i64;
    v25[3].mNext = 0i64;
    LODWORD(v25[5].mNext) = 3;
  }
  else
  {
    v25 = 0i64;
  }
  this->mpMapBools[3] = (UFG::PersistentData::MapBool *)v25;
  v26 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v26 )
  {
    LODWORD(v26->mNext) = 1;
    v26[2].mNext = 0i64;
    v26[1].mNext = 0i64;
    v26[4].mNext = 0i64;
    v26[3].mNext = 0i64;
    LODWORD(v26[5].mNext) = 4;
  }
  else
  {
    v26 = 0i64;
  }
  this->mpMapBools[4] = (UFG::PersistentData::MapBool *)v26;
  v27 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v27 )
  {
    LODWORD(v27->mNext) = 0;
    v27[2].mNext = 0i64;
    v27[1].mNext = 0i64;
    v27[4].mNext = 0i64;
    v27[3].mNext = 0i64;
    LODWORD(v27[5].mNext) = 5;
  }
  else
  {
    v27 = 0i64;
  }
  this->mpMapBools[5] = (UFG::PersistentData::MapBool *)v27;
  v28 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v28 )
  {
    LODWORD(v28->mNext) = 0;
    v28[2].mNext = 0i64;
    v28[1].mNext = 0i64;
    v28[4].mNext = 0i64;
    v28[3].mNext = 0i64;
    LODWORD(v28[5].mNext) = 6;
  }
  else
  {
    v28 = 0i64;
  }
  this->mpMapBools[6] = (UFG::PersistentData::MapBool *)v28;
  v29 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v29 )
  {
    LODWORD(v29->mNext) = 0;
    v29[2].mNext = 0i64;
    v29[1].mNext = 0i64;
    v29[4].mNext = 0i64;
    v29[3].mNext = 0i64;
    LODWORD(v29[5].mNext) = 7;
  }
  else
  {
    v29 = 0i64;
  }
  this->mpMapBools[7] = (UFG::PersistentData::MapBool *)v29;
  v30 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v30 )
  {
    LODWORD(v30->mNext) = 1;
    v30[2].mNext = 0i64;
    v30[1].mNext = 0i64;
    v30[4].mNext = 0i64;
    v30[3].mNext = 0i64;
    LODWORD(v30[5].mNext) = 8;
  }
  else
  {
    v30 = 0i64;
  }
  this->mpMapBools[8] = (UFG::PersistentData::MapBool *)v30;
  v31 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v31 )
  {
    LODWORD(v31->mNext) = 1;
    v31[2].mNext = 0i64;
    v31[1].mNext = 0i64;
    v31[4].mNext = 0i64;
    v31[3].mNext = 0i64;
    LODWORD(v31[5].mNext) = 9;
  }
  else
  {
    v31 = 0i64;
  }
  this->mpMapBools[9] = (UFG::PersistentData::MapBool *)v31;
  v32 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v32 )
  {
    LODWORD(v32->mNext) = 1;
    v32[2].mNext = 0i64;
    v32[1].mNext = 0i64;
    v32[4].mNext = 0i64;
    v32[3].mNext = 0i64;
    LODWORD(v32[5].mNext) = 10;
  }
  else
  {
    v32 = 0i64;
  }
  this->mpMapBools[10] = (UFG::PersistentData::MapBool *)v32;
  v33 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v33 )
  {
    LODWORD(v33->mNext) = 0;
    v33[2].mNext = 0i64;
    v33[1].mNext = 0i64;
    v33[4].mNext = 0i64;
    v33[3].mNext = 0i64;
    LODWORD(v33[5].mNext) = 11;
  }
  else
  {
    v33 = 0i64;
  }
  this->mpMapBools[11] = (UFG::PersistentData::MapBool *)v33;
  v34 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v34 )
  {
    LODWORD(v34->mNext) = 0;
    v34[2].mNext = 0i64;
    v34[1].mNext = 0i64;
    v34[4].mNext = 0i64;
    v34[3].mNext = 0i64;
    LODWORD(v34[5].mNext) = 12;
  }
  else
  {
    v34 = 0i64;
  }
  this->mpMapBools[12] = (UFG::PersistentData::MapBool *)v34;
  v35 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v35 )
  {
    LODWORD(v35->mNext) = 1;
    v35[2].mNext = 0i64;
    v35[1].mNext = 0i64;
    v35[4].mNext = 0i64;
    v35[3].mNext = 0i64;
    LODWORD(v35[5].mNext) = 13;
  }
  else
  {
    v35 = 0i64;
  }
  this->mpMapBools[13] = (UFG::PersistentData::MapBool *)v35;
  v36 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v36 )
  {
    LODWORD(v36->mNext) = 1;
    v36[2].mNext = 0i64;
    v36[1].mNext = 0i64;
    v36[4].mNext = 0i64;
    v36[3].mNext = 0i64;
    LODWORD(v36[5].mNext) = 14;
  }
  else
  {
    v36 = 0i64;
  }
  this->mpMapBools[14] = (UFG::PersistentData::MapBool *)v36;
  v37 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v37 )
  {
    LODWORD(v37->mNext) = 1;
    v37[2].mNext = 0i64;
    v37[1].mNext = 0i64;
    v37[4].mNext = 0i64;
    v37[3].mNext = 0i64;
    LODWORD(v37[5].mNext) = 15;
  }
  else
  {
    v37 = 0i64;
  }
  this->mpMapBools[15] = (UFG::PersistentData::MapBool *)v37;
  v38 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v38 )
  {
    LODWORD(v38->mNext) = 1;
    v38[2].mNext = 0i64;
    v38[1].mNext = 0i64;
    v38[4].mNext = 0i64;
    v38[3].mNext = 0i64;
    LODWORD(v38[5].mNext) = 16;
  }
  else
  {
    v38 = 0i64;
  }
  this->mpMapBools[16] = (UFG::PersistentData::MapBool *)v38;
  v39 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v39 )
  {
    LODWORD(v39->mNext) = 1;
    v39[2].mNext = 0i64;
    v39[1].mNext = 0i64;
    v39[4].mNext = 0i64;
    v39[3].mNext = 0i64;
    LODWORD(v39[5].mNext) = 17;
  }
  else
  {
    v39 = 0i64;
  }
  this->mpMapBools[17] = (UFG::PersistentData::MapBool *)v39;
  v40 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v40 )
  {
    LODWORD(v40->mNext) = 1;
    v40[2].mNext = 0i64;
    v40[1].mNext = 0i64;
    v40[4].mNext = 0i64;
    v40[3].mNext = 0i64;
    LODWORD(v40[5].mNext) = 18;
  }
  else
  {
    v40 = 0i64;
  }
  this->mpMapBools[18] = (UFG::PersistentData::MapBool *)v40;
  v41 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v41 )
  {
    LODWORD(v41->mNext) = 1;
    v41[2].mNext = 0i64;
    v41[1].mNext = 0i64;
    v41[4].mNext = 0i64;
    v41[3].mNext = 0i64;
    LODWORD(v41[5].mNext) = 19;
  }
  else
  {
    v41 = 0i64;
  }
  this->mpMapBools[19] = (UFG::PersistentData::MapBool *)v41;
  v42 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v42 )
  {
    LODWORD(v42->mNext) = 1;
    v42[2].mNext = 0i64;
    v42[1].mNext = 0i64;
    v42[4].mNext = 0i64;
    v42[3].mNext = 0i64;
    LODWORD(v42[5].mNext) = 20;
  }
  else
  {
    v42 = 0i64;
  }
  this->mpMapBools[20] = (UFG::PersistentData::MapBool *)v42;
  v43 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v43 )
  {
    LODWORD(v43->mNext) = 1;
    v43[2].mNext = 0i64;
    v43[1].mNext = 0i64;
    v43[4].mNext = 0i64;
    v43[3].mNext = 0i64;
    LODWORD(v43[5].mNext) = 21;
  }
  else
  {
    v43 = 0i64;
  }
  this->mpMapBools[21] = (UFG::PersistentData::MapBool *)v43;
  v44 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v44 )
  {
    LODWORD(v44->mNext) = 0;
    v44[2].mNext = 0i64;
    v44[1].mNext = 0i64;
    v44[4].mNext = 0i64;
    v44[3].mNext = 0i64;
    LODWORD(v44[5].mNext) = 22;
  }
  else
  {
    v44 = 0i64;
  }
  this->mpMapBools[22] = (UFG::PersistentData::MapBool *)v44;
  v45 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v45 )
  {
    LODWORD(v45->mNext) = 0;
    v45[2].mNext = 0i64;
    v45[1].mNext = 0i64;
    v45[4].mNext = 0i64;
    v45[3].mNext = 0i64;
    LODWORD(v45[5].mNext) = 23;
  }
  else
  {
    v45 = 0i64;
  }
  this->mpMapBools[23] = (UFG::PersistentData::MapBool *)v45;
  v46 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v46 )
  {
    LODWORD(v46->mNext) = 0;
    v46[2].mNext = 0i64;
    v46[1].mNext = 0i64;
    v46[4].mNext = 0i64;
    v46[3].mNext = 0i64;
    LODWORD(v46[5].mNext) = 24;
  }
  else
  {
    v46 = 0i64;
  }
  this->mpMapBools[24] = (UFG::PersistentData::MapBool *)v46;
  v47 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v47 )
  {
    LODWORD(v47->mNext) = 0;
    v47[2].mNext = 0i64;
    v47[1].mNext = 0i64;
    v47[4].mNext = 0i64;
    v47[3].mNext = 0i64;
    LODWORD(v47[5].mNext) = 25;
  }
  else
  {
    v47 = 0i64;
  }
  this->mpMapBools[25] = (UFG::PersistentData::MapBool *)v47;
  v48 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v48 )
  {
    LODWORD(v48->mNext) = 0;
    v48[2].mNext = 0i64;
    v48[1].mNext = 0i64;
    v48[4].mNext = 0i64;
    v48[3].mNext = 0i64;
    LODWORD(v48[5].mNext) = 26;
  }
  else
  {
    v48 = 0i64;
  }
  this->mpMapBools[26] = (UFG::PersistentData::MapBool *)v48;
  v49 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v49 )
  {
    LODWORD(v49->mNext) = 0;
    v49[2].mNext = 0i64;
    v49[1].mNext = 0i64;
    v49[4].mNext = 0i64;
    v49[3].mNext = 0i64;
    LODWORD(v49[5].mNext) = 27;
  }
  else
  {
    v49 = 0i64;
  }
  this->mpMapBools[27] = (UFG::PersistentData::MapBool *)v49;
  v50 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v50 )
  {
    LODWORD(v50->mNext) = 0;
    v50[2].mNext = 0i64;
    v50[1].mNext = 0i64;
    v50[4].mNext = 0i64;
    v50[3].mNext = 0i64;
    LODWORD(v50[5].mNext) = 28;
  }
  else
  {
    v50 = 0i64;
  }
  this->mpMapBools[28] = (UFG::PersistentData::MapBool *)v50;
  v51 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v51 )
  {
    LODWORD(v51->mNext) = 0;
    v51[2].mNext = 0i64;
    v51[1].mNext = 0i64;
    v51[4].mNext = 0i64;
    v51[3].mNext = 0i64;
    LODWORD(v51[5].mNext) = 29;
  }
  else
  {
    v51 = 0i64;
  }
  this->mpMapBools[29] = (UFG::PersistentData::MapBool *)v51;
  v52 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v52 )
  {
    LODWORD(v52->mNext) = 0;
    v52[2].mNext = 0i64;
    v52[1].mNext = 0i64;
    v52[4].mNext = 0i64;
    v52[3].mNext = 0i64;
    LODWORD(v52[5].mNext) = 30;
  }
  else
  {
    v52 = 0i64;
  }
  this->mpMapBools[30] = (UFG::PersistentData::MapBool *)v52;
  v53 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v53 )
  {
    LODWORD(v53->mNext) = 0;
    v53[2].mNext = 0i64;
    v53[1].mNext = 0i64;
    v53[4].mNext = 0i64;
    v53[3].mNext = 0i64;
    LODWORD(v53[5].mNext) = 31;
  }
  else
  {
    v53 = 0i64;
  }
  this->mpMapBools[31] = (UFG::PersistentData::MapBool *)v53;
  v54 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v54 )
  {
    LODWORD(v54->mNext) = 0;
    v54[2].mNext = 0i64;
    v54[1].mNext = 0i64;
    v54[4].mNext = 0i64;
    v54[3].mNext = 0i64;
    LODWORD(v54[5].mNext) = 32;
  }
  else
  {
    v54 = 0i64;
  }
  this->mpMapBools[32] = (UFG::PersistentData::MapBool *)v54;
  v55 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v55 )
  {
    LODWORD(v55->mNext) = 0;
    v55[2].mNext = 0i64;
    v55[1].mNext = 0i64;
    v55[4].mNext = 0i64;
    v55[3].mNext = 0i64;
    LODWORD(v55[5].mNext) = 33;
  }
  else
  {
    v55 = 0i64;
  }
  this->mpMapBools[33] = (UFG::PersistentData::MapBool *)v55;
  v56 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v56 )
  {
    LODWORD(v56->mNext) = 0;
    v56[2].mNext = 0i64;
    v56[1].mNext = 0i64;
    v56[4].mNext = 0i64;
    v56[3].mNext = 0i64;
    LODWORD(v56[5].mNext) = 34;
  }
  else
  {
    v56 = 0i64;
  }
  this->mpMapBools[34] = (UFG::PersistentData::MapBool *)v56;
  v57 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v57 )
  {
    LODWORD(v57->mNext) = 0;
    v57[2].mNext = 0i64;
    v57[1].mNext = 0i64;
    v57[4].mNext = 0i64;
    v57[3].mNext = 0i64;
    LODWORD(v57[5].mNext) = 35;
  }
  else
  {
    v57 = 0i64;
  }
  this->mpMapBools[35] = (UFG::PersistentData::MapBool *)v57;
  v58 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v58 )
  {
    LODWORD(v58->mNext) = 0;
    v58[2].mNext = 0i64;
    v58[1].mNext = 0i64;
    v58[4].mNext = 0i64;
    v58[3].mNext = 0i64;
    LODWORD(v58[5].mNext) = 36;
  }
  else
  {
    v58 = 0i64;
  }
  this->mpMapBools[36] = (UFG::PersistentData::MapBool *)v58;
  v59 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v59 )
  {
    LODWORD(v59->mNext) = 0;
    v59[2].mNext = 0i64;
    v59[1].mNext = 0i64;
    v59[4].mNext = 0i64;
    v59[3].mNext = 0i64;
    LODWORD(v59[5].mNext) = 37;
  }
  else
  {
    v59 = 0i64;
  }
  this->mpMapBools[37] = (UFG::PersistentData::MapBool *)v59;
  v60 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v60 )
  {
    LODWORD(v60->mNext) = 0;
    v60[2].mNext = 0i64;
    v60[1].mNext = 0i64;
    v60[4].mNext = 0i64;
    v60[3].mNext = 0i64;
    LODWORD(v60[5].mNext) = 38;
  }
  else
  {
    v60 = 0i64;
  }
  this->mpMapBools[38] = (UFG::PersistentData::MapBool *)v60;
  v61 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v61 )
  {
    LODWORD(v61->mNext) = 0;
    v61[2].mNext = 0i64;
    v61[1].mNext = 0i64;
    v61[4].mNext = 0i64;
    v61[3].mNext = 0i64;
    LODWORD(v61[5].mNext) = 39;
  }
  else
  {
    v61 = 0i64;
  }
  this->mpMapBools[39] = (UFG::PersistentData::MapBool *)v61;
  v62 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v62 )
  {
    LODWORD(v62->mNext) = 0;
    v62[2].mNext = 0i64;
    v62[1].mNext = 0i64;
    v62[4].mNext = 0i64;
    v62[3].mNext = 0i64;
    LODWORD(v62[5].mNext) = 40;
  }
  else
  {
    v62 = 0i64;
  }
  this->mpMapBools[40] = (UFG::PersistentData::MapBool *)v62;
  v63 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v63 )
  {
    LODWORD(v63->mNext) = 0;
    v63[2].mNext = 0i64;
    v63[1].mNext = 0i64;
    v63[4].mNext = 0i64;
    v63[3].mNext = 0i64;
    LODWORD(v63[5].mNext) = 41;
  }
  else
  {
    v63 = 0i64;
  }
  this->mpMapBools[41] = (UFG::PersistentData::MapBool *)v63;
  v64 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v64 )
  {
    LODWORD(v64->mNext) = 0;
    v64[2].mNext = 0i64;
    v64[1].mNext = 0i64;
    v64[4].mNext = 0i64;
    v64[3].mNext = 0i64;
    LODWORD(v64[5].mNext) = 42;
  }
  else
  {
    v64 = 0i64;
  }
  this->mpMapBools[42] = (UFG::PersistentData::MapBool *)v64;
  v65 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v65 )
  {
    LODWORD(v65->mNext) = 0;
    v65[2].mNext = 0i64;
    v65[1].mNext = 0i64;
    v65[4].mNext = 0i64;
    v65[3].mNext = 0i64;
    LODWORD(v65[5].mNext) = 43;
  }
  else
  {
    v65 = 0i64;
  }
  this->mpMapBools[43] = (UFG::PersistentData::MapBool *)v65;
  v66 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v66 )
  {
    LODWORD(v66->mNext) = 0;
    v66[2].mNext = 0i64;
    v66[1].mNext = 0i64;
    v66[4].mNext = 0i64;
    v66[3].mNext = 0i64;
    LODWORD(v66[5].mNext) = 44;
  }
  else
  {
    v66 = 0i64;
  }
  this->mpMapBools[44] = (UFG::PersistentData::MapBool *)v66;
  v67 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v67 )
  {
    LODWORD(v67->mNext) = 0;
    v67[2].mNext = 0i64;
    v67[1].mNext = 0i64;
    v67[4].mNext = 0i64;
    v67[3].mNext = 0i64;
    LODWORD(v67[5].mNext) = 45;
  }
  else
  {
    v67 = 0i64;
  }
  this->mpMapBools[45] = (UFG::PersistentData::MapBool *)v67;
  v68 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v68 )
  {
    LODWORD(v68->mNext) = 0;
    v68[2].mNext = 0i64;
    v68[1].mNext = 0i64;
    v68[4].mNext = 0i64;
    v68[3].mNext = 0i64;
    LODWORD(v68[5].mNext) = 46;
  }
  else
  {
    v68 = 0i64;
  }
  this->mpMapBools[46] = (UFG::PersistentData::MapBool *)v68;
  v69 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v69 )
  {
    LODWORD(v69->mNext) = 0;
    v69[2].mNext = 0i64;
    v69[1].mNext = 0i64;
    v69[4].mNext = 0i64;
    v69[3].mNext = 0i64;
    LODWORD(v69[5].mNext) = 47;
  }
  else
  {
    v69 = 0i64;
  }
  this->mpMapBools[47] = (UFG::PersistentData::MapBool *)v69;
  v70 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v70 )
  {
    LODWORD(v70->mNext) = 0;
    v70[2].mNext = 0i64;
    v70[1].mNext = 0i64;
    v70[4].mNext = 0i64;
    v70[3].mNext = 0i64;
    LODWORD(v70[5].mNext) = 48;
  }
  else
  {
    v70 = 0i64;
  }
  this->mpMapBools[48] = (UFG::PersistentData::MapBool *)v70;
  v71 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v71 )
  {
    LODWORD(v71->mNext) = 0;
    v71[2].mNext = 0i64;
    v71[1].mNext = 0i64;
    v71[4].mNext = 0i64;
    v71[3].mNext = 0i64;
    LODWORD(v71[5].mNext) = 49;
  }
  else
  {
    v71 = 0i64;
  }
  this->mpMapBools[49] = (UFG::PersistentData::MapBool *)v71;
  v72 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v72 )
  {
    LODWORD(v72->mNext) = 0;
    v72[2].mNext = 0i64;
    v72[1].mNext = 0i64;
    v72[4].mNext = 0i64;
    v72[3].mNext = 0i64;
    LODWORD(v72[5].mNext) = 50;
  }
  else
  {
    v72 = 0i64;
  }
  this->mpMapBools[50] = (UFG::PersistentData::MapBool *)v72;
  v73 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v73 )
  {
    LODWORD(v73->mNext) = 0;
    v73[2].mNext = 0i64;
    v73[1].mNext = 0i64;
    v73[4].mNext = 0i64;
    v73[3].mNext = 0i64;
    LODWORD(v73[5].mNext) = 51;
  }
  else
  {
    v73 = 0i64;
  }
  this->mpMapBools[51] = (UFG::PersistentData::MapBool *)v73;
  v74 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v74 )
  {
    LODWORD(v74->mNext) = 0;
    v74[2].mNext = 0i64;
    v74[1].mNext = 0i64;
    v74[4].mNext = 0i64;
    v74[3].mNext = 0i64;
    LODWORD(v74[5].mNext) = 52;
  }
  else
  {
    v74 = 0i64;
  }
  this->mpMapBools[52] = (UFG::PersistentData::MapBool *)v74;
  v75 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v75 )
  {
    LODWORD(v75->mNext) = 0;
    v75[2].mNext = 0i64;
    v75[1].mNext = 0i64;
    v75[4].mNext = 0i64;
    v75[3].mNext = 0i64;
    LODWORD(v75[5].mNext) = 53;
  }
  else
  {
    v75 = 0i64;
  }
  this->mpMapBools[53] = (UFG::PersistentData::MapBool *)v75;
  v76 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v76 )
  {
    LODWORD(v76->mNext) = 1;
    v76[2].mNext = 0i64;
    v76[1].mNext = 0i64;
    v76[4].mNext = 0i64;
    v76[3].mNext = 0i64;
    LODWORD(v76[5].mNext) = 54;
  }
  else
  {
    v76 = 0i64;
  }
  this->mpMapBools[54] = (UFG::PersistentData::MapBool *)v76;
  v77 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v77 )
  {
    LODWORD(v77->mNext) = 0;
    v77[2].mNext = 0i64;
    v77[1].mNext = 0i64;
    v77[4].mNext = 0i64;
    v77[3].mNext = 0i64;
    LODWORD(v77[5].mNext) = 55;
  }
  else
  {
    v77 = 0i64;
  }
  this->mpMapBools[55] = (UFG::PersistentData::MapBool *)v77;
  v78 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v78 )
  {
    LODWORD(v78->mNext) = 1;
    v78[2].mNext = 0i64;
    v78[1].mNext = 0i64;
    v78[4].mNext = 0i64;
    v78[3].mNext = 0i64;
    LODWORD(v78[5].mNext) = 56;
  }
  else
  {
    v78 = 0i64;
  }
  this->mpMapBools[56] = (UFG::PersistentData::MapBool *)v78;
  v79 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v79 )
  {
    LODWORD(v79->mNext) = 1;
    v79[2].mNext = 0i64;
    v79[1].mNext = 0i64;
    v79[4].mNext = 0i64;
    v79[3].mNext = 0i64;
    LODWORD(v79[5].mNext) = 57;
  }
  else
  {
    v79 = 0i64;
  }
  this->mpMapBools[57] = (UFG::PersistentData::MapBool *)v79;
  v80 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v80 )
  {
    LODWORD(v80->mNext) = 1;
    v80[2].mNext = 0i64;
    v80[1].mNext = 0i64;
    v80[4].mNext = 0i64;
    v80[3].mNext = 0i64;
    LODWORD(v80[5].mNext) = 58;
  }
  else
  {
    v80 = 0i64;
  }
  this->mpMapBools[58] = (UFG::PersistentData::MapBool *)v80;
  v81 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v81 )
  {
    LODWORD(v81->mNext) = 1;
    v81[2].mNext = 0i64;
    v81[1].mNext = 0i64;
    v81[4].mNext = 0i64;
    v81[3].mNext = 0i64;
    LODWORD(v81[5].mNext) = 59;
  }
  else
  {
    v81 = 0i64;
  }
  this->mpMapBools[59] = (UFG::PersistentData::MapBool *)v81;
  v82 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v82 )
  {
    LODWORD(v82->mNext) = 1;
    v82[2].mNext = 0i64;
    v82[1].mNext = 0i64;
    v82[4].mNext = 0i64;
    v82[3].mNext = 0i64;
    LODWORD(v82[5].mNext) = 60;
  }
  else
  {
    v82 = 0i64;
  }
  this->mpMapBools[60] = (UFG::PersistentData::MapBool *)v82;
  v83 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v83 )
  {
    LODWORD(v83->mNext) = 1;
    v83[2].mNext = 0i64;
    v83[1].mNext = 0i64;
    v83[4].mNext = 0i64;
    v83[3].mNext = 0i64;
    LODWORD(v83[5].mNext) = 61;
  }
  else
  {
    v83 = 0i64;
  }
  this->mpMapBools[61] = (UFG::PersistentData::MapBool *)v83;
  v84 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v84 )
  {
    LODWORD(v84->mNext) = 1;
    v84[2].mNext = 0i64;
    v84[1].mNext = 0i64;
    v84[4].mNext = 0i64;
    v84[3].mNext = 0i64;
    LODWORD(v84[5].mNext) = 62;
  }
  else
  {
    v84 = 0i64;
  }
  this->mpMapBools[62] = (UFG::PersistentData::MapBool *)v84;
  v85 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v85 )
  {
    LODWORD(v85->mNext) = 1;
    v85[2].mNext = 0i64;
    v85[1].mNext = 0i64;
    v85[4].mNext = 0i64;
    v85[3].mNext = 0i64;
    LODWORD(v85[5].mNext) = 63;
  }
  else
  {
    v85 = 0i64;
  }
  this->mpMapBools[63] = (UFG::PersistentData::MapBool *)v85;
  v86 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v86 )
  {
    LODWORD(v86->mNext) = 1;
    v86[2].mNext = 0i64;
    v86[1].mNext = 0i64;
    v86[4].mNext = 0i64;
    v86[3].mNext = 0i64;
    LODWORD(v86[5].mNext) = 64;
  }
  else
  {
    v86 = 0i64;
  }
  this->mpMapBools[64] = (UFG::PersistentData::MapBool *)v86;
  v87 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v87 )
  {
    LODWORD(v87->mNext) = 0;
    v87[2].mNext = 0i64;
    v87[1].mNext = 0i64;
    v87[4].mNext = 0i64;
    v87[3].mNext = 0i64;
    LODWORD(v87[5].mNext) = 65;
  }
  else
  {
    v87 = 0i64;
  }
  this->mpMapBools[65] = (UFG::PersistentData::MapBool *)v87;
  v88 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v88 )
  {
    LODWORD(v88->mNext) = 0;
    v88[2].mNext = 0i64;
    v88[1].mNext = 0i64;
    v88[4].mNext = 0i64;
    v88[3].mNext = 0i64;
    LODWORD(v88[5].mNext) = 66;
  }
  else
  {
    v88 = 0i64;
  }
  this->mpMapBools[66] = (UFG::PersistentData::MapBool *)v88;
  v89 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v89 )
  {
    LODWORD(v89->mNext) = 0;
    v89[2].mNext = 0i64;
    v89[1].mNext = 0i64;
    v89[4].mNext = 0i64;
    v89[3].mNext = 0i64;
    LODWORD(v89[5].mNext) = 67;
  }
  else
  {
    v89 = 0i64;
  }
  this->mpMapBools[67] = (UFG::PersistentData::MapBool *)v89;
  v90 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v90 )
  {
    LODWORD(v90->mNext) = 0;
    v90[2].mNext = 0i64;
    v90[1].mNext = 0i64;
    v90[4].mNext = 0i64;
    v90[3].mNext = 0i64;
    LODWORD(v90[5].mNext) = 68;
  }
  else
  {
    v90 = 0i64;
  }
  this->mpMapBools[68] = (UFG::PersistentData::MapBool *)v90;
  v91 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v91 )
  {
    LODWORD(v91->mNext) = 0;
    v91[2].mNext = 0i64;
    v91[1].mNext = 0i64;
    v91[4].mNext = 0i64;
    v91[3].mNext = 0i64;
    LODWORD(v91[5].mNext) = 69;
  }
  else
  {
    v91 = 0i64;
  }
  this->mpMapBools[69] = (UFG::PersistentData::MapBool *)v91;
  v92 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v92 )
  {
    LODWORD(v92->mNext) = 0;
    v92[2].mNext = 0i64;
    v92[1].mNext = 0i64;
    v92[4].mNext = 0i64;
    v92[3].mNext = 0i64;
    LODWORD(v92[5].mNext) = 70;
  }
  else
  {
    v92 = 0i64;
  }
  this->mpMapBools[70] = (UFG::PersistentData::MapBool *)v92;
  v93 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v93 )
  {
    LODWORD(v93->mNext) = 0;
    v93[2].mNext = 0i64;
    v93[1].mNext = 0i64;
    v93[4].mNext = 0i64;
    v93[3].mNext = 0i64;
    LODWORD(v93[5].mNext) = 71;
  }
  else
  {
    v93 = 0i64;
  }
  this->mpMapBools[71] = (UFG::PersistentData::MapBool *)v93;
  v94 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v94 )
  {
    LODWORD(v94->mNext) = 0;
    v94[2].mNext = 0i64;
    v94[1].mNext = 0i64;
    v94[4].mNext = 0i64;
    v94[3].mNext = 0i64;
    LODWORD(v94[5].mNext) = 72;
  }
  else
  {
    v94 = 0i64;
  }
  this->mpMapBools[72] = (UFG::PersistentData::MapBool *)v94;
  v95 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v95 )
  {
    LODWORD(v95->mNext) = 0;
    v95[2].mNext = 0i64;
    v95[1].mNext = 0i64;
    v95[4].mNext = 0i64;
    v95[3].mNext = 0i64;
    LODWORD(v95[5].mNext) = 73;
  }
  else
  {
    v95 = 0i64;
  }
  this->mpMapBools[73] = (UFG::PersistentData::MapBool *)v95;
  v96 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v96 )
  {
    LODWORD(v96->mNext) = 0;
    v96[2].mNext = 0i64;
    v96[1].mNext = 0i64;
    v96[4].mNext = 0i64;
    v96[3].mNext = 0i64;
    LODWORD(v96[5].mNext) = 74;
  }
  else
  {
    v96 = 0i64;
  }
  this->mpMapBools[74] = (UFG::PersistentData::MapBool *)v96;
  v97 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v97 )
  {
    LODWORD(v97->mNext) = 1;
    v97[2].mNext = 0i64;
    v97[1].mNext = 0i64;
    v97[4].mNext = 0i64;
    v97[3].mNext = 0i64;
    LODWORD(v97[5].mNext) = 75;
  }
  else
  {
    v97 = 0i64;
  }
  this->mpMapBools[75] = (UFG::PersistentData::MapBool *)v97;
  v98 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v98 )
  {
    LODWORD(v98->mNext) = 1;
    v98[2].mNext = 0i64;
    v98[1].mNext = 0i64;
    v98[4].mNext = 0i64;
    v98[3].mNext = 0i64;
    LODWORD(v98[5].mNext) = 76;
  }
  else
  {
    v98 = 0i64;
  }
  this->mpMapBools[76] = (UFG::PersistentData::MapBool *)v98;
  v99 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v99 )
  {
    LODWORD(v99->mNext) = 0;
    v99[2].mNext = 0i64;
    v99[1].mNext = 0i64;
    v99[4].mNext = 0i64;
    v99[3].mNext = 0i64;
    LODWORD(v99[5].mNext) = 77;
  }
  else
  {
    v99 = 0i64;
  }
  this->mpMapBools[77] = (UFG::PersistentData::MapBool *)v99;
  v100 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v100 )
  {
    LODWORD(v100->mNext) = 1;
    v100[2].mNext = 0i64;
    v100[1].mNext = 0i64;
    v100[4].mNext = 0i64;
    v100[3].mNext = 0i64;
    LODWORD(v100[5].mNext) = 78;
  }
  else
  {
    v100 = 0i64;
  }
  this->mpMapBools[78] = (UFG::PersistentData::MapBool *)v100;
  v101 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v101 )
  {
    LODWORD(v101->mNext) = 1;
    v101[2].mNext = 0i64;
    v101[1].mNext = 0i64;
    v101[4].mNext = 0i64;
    v101[3].mNext = 0i64;
    LODWORD(v101[5].mNext) = 79;
  }
  else
  {
    v101 = 0i64;
  }
  this->mpMapBools[79] = (UFG::PersistentData::MapBool *)v101;
  v102 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v102 )
  {
    LODWORD(v102->mNext) = 1;
    v102[2].mNext = 0i64;
    v102[1].mNext = 0i64;
    v102[4].mNext = 0i64;
    v102[3].mNext = 0i64;
    LODWORD(v102[5].mNext) = 80;
  }
  else
  {
    v102 = 0i64;
  }
  this->mpMapBools[80] = (UFG::PersistentData::MapBool *)v102;
  v103 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v103 )
  {
    LODWORD(v103->mNext) = 1;
    v103[2].mNext = 0i64;
    v103[1].mNext = 0i64;
    v103[4].mNext = 0i64;
    v103[3].mNext = 0i64;
    LODWORD(v103[5].mNext) = 81;
  }
  else
  {
    v103 = 0i64;
  }
  this->mpMapBools[81] = (UFG::PersistentData::MapBool *)v103;
  v104 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v104 )
  {
    LODWORD(v104->mNext) = 1;
    v104[2].mNext = 0i64;
    v104[1].mNext = 0i64;
    v104[4].mNext = 0i64;
    v104[3].mNext = 0i64;
    LODWORD(v104[5].mNext) = 82;
  }
  else
  {
    v104 = 0i64;
  }
  this->mpMapBools[82] = (UFG::PersistentData::MapBool *)v104;
  v105 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v105 )
  {
    LODWORD(v105->mNext) = 1;
    v105[2].mNext = 0i64;
    v105[1].mNext = 0i64;
    v105[4].mNext = 0i64;
    v105[3].mNext = 0i64;
    LODWORD(v105[5].mNext) = 83;
  }
  else
  {
    v105 = 0i64;
  }
  this->mpMapBools[83] = (UFG::PersistentData::MapBool *)v105;
  v106 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v106 )
  {
    LODWORD(v106->mNext) = 1;
    v106[2].mNext = 0i64;
    v106[1].mNext = 0i64;
    v106[4].mNext = 0i64;
    v106[3].mNext = 0i64;
    LODWORD(v106[5].mNext) = 84;
  }
  else
  {
    v106 = 0i64;
  }
  this->mpMapBools[84] = (UFG::PersistentData::MapBool *)v106;
  v107 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v107 )
  {
    LODWORD(v107->mNext) = 1;
    v107[2].mNext = 0i64;
    v107[1].mNext = 0i64;
    v107[4].mNext = 0i64;
    v107[3].mNext = 0i64;
    LODWORD(v107[5].mNext) = 85;
  }
  else
  {
    v107 = 0i64;
  }
  this->mpMapBools[85] = (UFG::PersistentData::MapBool *)v107;
  v108 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v108 )
  {
    LODWORD(v108->mNext) = 1;
    v108[2].mNext = 0i64;
    v108[1].mNext = 0i64;
    v108[4].mNext = 0i64;
    v108[3].mNext = 0i64;
    LODWORD(v108[5].mNext) = 86;
  }
  else
  {
    v108 = 0i64;
  }
  this->mpMapBools[86] = (UFG::PersistentData::MapBool *)v108;
  v109 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v109 )
  {
    LODWORD(v109->mNext) = 0;
    v109[2].mNext = 0i64;
    v109[1].mNext = 0i64;
    v109[4].mNext = 0i64;
    v109[3].mNext = 0i64;
    LODWORD(v109[5].mNext) = 87;
  }
  else
  {
    v109 = 0i64;
  }
  this->mpMapBools[87] = (UFG::PersistentData::MapBool *)v109;
  v110 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v110 )
  {
    LODWORD(v110->mNext) = 0;
    v110[2].mNext = 0i64;
    v110[1].mNext = 0i64;
    v110[4].mNext = 0i64;
    v110[3].mNext = 0i64;
    LODWORD(v110[5].mNext) = 88;
  }
  else
  {
    v110 = 0i64;
  }
  this->mpMapBools[88] = (UFG::PersistentData::MapBool *)v110;
  v111 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v111 )
  {
    LODWORD(v111->mNext) = 1;
    v111[2].mNext = 0i64;
    v111[1].mNext = 0i64;
    v111[4].mNext = 0i64;
    v111[3].mNext = 0i64;
    LODWORD(v111[5].mNext) = 89;
  }
  else
  {
    v111 = 0i64;
  }
  this->mpMapBools[89] = (UFG::PersistentData::MapBool *)v111;
  v112 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v112 )
  {
    LODWORD(v112->mNext) = 1;
    v112[2].mNext = 0i64;
    v112[1].mNext = 0i64;
    v112[4].mNext = 0i64;
    v112[3].mNext = 0i64;
    LODWORD(v112[5].mNext) = 90;
  }
  else
  {
    v112 = 0i64;
  }
  this->mpMapBools[90] = (UFG::PersistentData::MapBool *)v112;
  v113 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v113 )
  {
    LODWORD(v113->mNext) = 0;
    v113[2].mNext = 0i64;
    v113[1].mNext = 0i64;
    v113[4].mNext = 0i64;
    v113[3].mNext = 0i64;
    LODWORD(v113[5].mNext) = 91;
  }
  else
  {
    v113 = 0i64;
  }
  this->mpMapBools[91] = (UFG::PersistentData::MapBool *)v113;
  v114 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v114 )
  {
    LODWORD(v114->mNext) = 0;
    v114[2].mNext = 0i64;
    v114[1].mNext = 0i64;
    v114[4].mNext = 0i64;
    v114[3].mNext = 0i64;
    LODWORD(v114[5].mNext) = 92;
  }
  else
  {
    v114 = 0i64;
  }
  this->mpMapBools[92] = (UFG::PersistentData::MapBool *)v114;
  UFG::GameSnapshot::CreateList(this);
}110->mNext) = 0;
    v110[2].mNext = 0i

// File Line: 137
// RVA: 0x499E60
void __fastcall UFG::GameSnapshot::CreateList(UFG::GameSnapshot *this)
{
  UFG::allocator::free_link *v2; // rax
  UFG::PersistentData::List *v3; // rdi
  UFG::allocator::free_link *v4; // rax

  v2 = UFG::qMalloc(0x10ui64, "GameSnapShot", 0i64);
  v3 = (UFG::PersistentData::List *)v2;
  if ( v2 )
  {
    LODWORD(v2->mNext) = 0;
    v2[1].mNext = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  this->mpList[0] = v3;
  v3->mType = LT_INT64;
  v4 = UFG::qMalloc(0x10ui64, "PDList", 0i64);
  if ( v4 )
  {
    v4[1].mNext = 0i64;
    v4->mNext = 0i64;
    v3->mIntList = (UFG::qArray<long,0> *)v4;
  }
  else
  {
    v3->mIntList = 0i64;
  }
}

// File Line: 151
// RVA: 0x498000
void __fastcall UFG::GameSnapshot::Clone(UFG::GameSnapshot *this, UFG::GameSnapshot *src)
{
  UFG::PersistentData::Time *v4; // r8
  signed __int64 v5; // r9
  __int64 v6; // r10
  UFG::PersistentData::ID *mIDs; // rcx
  signed __int64 v8; // rdi
  __int64 v9; // rdx
  UFG::PersistentData::Bool *mBools; // rcx
  __int64 v11; // rdx
  UFG::PersistentData::Int *mInts; // rcx
  __int64 v13; // rdx
  UFG::PersistentData::Float *mFloats; // rcx
  __int64 v15; // rdx
  UFG::PersistentData::Float *v16; // rcx
  __int64 v17; // rbp
  __int64 v18; // rdx
  char **p_mData; // rbx
  UFG::PersistentData::String *mStrings; // rsi
  __int64 v21; // r14
  unsigned int *p_mSize; // rsi
  unsigned int v23; // eax
  UFG::allocator::free_link *v24; // rbx
  UFG::PersistentData::MapBool **mpMapBools; // rsi
  __int64 v26; // rbp
  UFG::PersistentData::MapBool *v27; // rbx
  UFG::allocator::free_link *v28; // rax
  UFG::PersistentData::MapBool *v29; // rbx
  __int64 v30; // r8
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v31; // rdx
  int mNext; // eax
  UFG::PersistentData::MapInt **mpMapInts; // r14
  __int64 v34; // rbp
  UFG::PersistentData::MapInt *v35; // rsi
  UFG::PersistentData::KeyValue *p; // rcx
  char *v37; // rbx
  UFG::PersistentData::KeyValue *v38; // rcx
  char *v39; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v40; // rax
  UFG::PersistentData::MapInt *v41; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v42; // rcx
  UFG::PersistentData::MapUInt64 *v43; // rsi
  UFG::PersistentData::KeyValue64 *v44; // rcx
  unsigned __int64 *p_mIntValue; // rbx
  UFG::PersistentData::KeyValue64 *v46; // rcx
  unsigned __int64 *v47; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue64,0> *v48; // rax
  UFG::PersistentData::MapUInt64 *v49; // rbx
  UFG::PersistentData::MapUInt64 *v50; // rcx
  UFG::PersistentData::MapFloat **mpMapFloats; // r14
  __int64 v52; // rbp
  UFG::PersistentData::MapFloat *v53; // rsi
  UFG::PersistentData::KeyValue *v54; // rcx
  char *v55; // rbx
  UFG::PersistentData::KeyValue *v56; // rcx
  char *v57; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v58; // rax
  UFG::PersistentData::MapFloat *v59; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v60; // rcx
  UFG::PersistentData::MapBinary **mpMapBinaries; // r14
  __int64 v62; // rbp
  UFG::PersistentData::MapBinary *v63; // rsi
  UFG::PersistentData::KeyBinary *v64; // rcx
  unsigned int *v65; // rbx
  UFG::allocator::free_link *v66; // rax
  UFG::PersistentData::MapBinary *v67; // rax
  UFG::PersistentData::List *v68; // rdx
  UFG::PersistentData::List *v69; // rcx

  v4 = &src->mTimes[1];
  v5 = (char *)this - (char *)src;
  v6 = 15i64;
  do
  {
    *(unsigned __int64 *)((char *)&v4[-1].mTimer.mTimestamp + v5) = v4[-1].mTimer.mTimestamp;
    *(_QWORD *)((char *)v4 + v5 - 8) = *(_QWORD *)&v4[-1].mTimer.mElapsedTime;
    *(unsigned __int64 *)((char *)&v4->mTimer.mTimestamp + v5) = v4->mTimer.mTimestamp;
    *(_QWORD *)((char *)&v4->mTimer.mElapsedTime + v5) = *(_QWORD *)&v4->mTimer.mElapsedTime;
    v4 += 2;
    --v6;
  }
  while ( v6 );
  mIDs = this->mIDs;
  v8 = (char *)src - (char *)this;
  v9 = 22i64;
  do
  {
    mIDs->mValue.mUID = *(unsigned int *)((char *)mIDs + v8);
    mIDs[1].mValue.mUID = *(unsigned int *)((char *)mIDs + v8 + 4);
    mIDs += 2;
    --v9;
  }
  while ( v9 );
  mBools = this->mBools;
  v11 = 29i64;
  do
  {
    mBools->mValue = (bool)mBools[v8];
    mBools[1].mValue = (bool)mBools[v8 + 1];
    mBools += 2;
    --v11;
  }
  while ( v11 );
  mInts = src->mInts;
  v13 = 163i64;
  do
  {
    *(UFG::PersistentData::Int *)((char *)mInts + v5) = (UFG::PersistentData::Int)mInts->mValue;
    ++mInts;
    --v13;
  }
  while ( v13 );
  this->mUInt64s[0].mValue = src->mUInt64s[0].mValue;
  mFloats = this->mFloats;
  v15 = 17i64;
  do
  {
    mFloats->mValue = *(float *)((char *)mFloats + v8);
    mFloats[1].mValue = *(float *)((char *)mFloats + v8 + 4);
    mFloats[2].mValue = *(float *)((char *)mFloats + v8 + 8);
    mFloats[3].mValue = *(float *)((char *)mFloats + v8 + 12);
    mFloats[4].mValue = *(float *)((char *)mFloats + v8 + 16);
    mFloats[5].mValue = *(float *)((char *)mFloats + v8 + 20);
    mFloats[6].mValue = *(float *)((char *)mFloats + v8 + 24);
    mFloats[7].mValue = *(float *)((char *)mFloats + v8 + 28);
    mFloats += 8;
    --v15;
  }
  while ( v15 );
  v16 = &src->mFloats[136];
  v17 = 3i64;
  v18 = 3i64;
  do
  {
    *(UFG::PersistentData::Float *)((char *)v16 + v5) = LODWORD(v16->mValue);
    ++v16;
    --v18;
  }
  while ( v18 );
  this->mIntsRanged[0].mValue = src->mIntsRanged[0].mValue;
  this->mIntsRanged[0].mRange = src->mIntsRanged[0].mRange;
  this->mIntsRanged[1].mValue = src->mIntsRanged[1].mValue;
  this->mIntsRanged[1].mRange = src->mIntsRanged[1].mRange;
  this->mIntsRanged[2].mValue = src->mIntsRanged[2].mValue;
  this->mIntsRanged[2].mRange = src->mIntsRanged[2].mRange;
  this->mIntsRanged[3].mValue = src->mIntsRanged[3].mValue;
  this->mIntsRanged[3].mRange = src->mIntsRanged[3].mRange;
  this->mIntsRanged[4].mValue = src->mIntsRanged[4].mValue;
  this->mIntsRanged[4].mRange = src->mIntsRanged[4].mRange;
  this->mIntsRanged[5].mValue = src->mIntsRanged[5].mValue;
  this->mIntsRanged[5].mRange = src->mIntsRanged[5].mRange;
  this->mIntsRanged[6].mValue = src->mIntsRanged[6].mValue;
  this->mIntsRanged[6].mRange = src->mIntsRanged[6].mRange;
  this->mFloatsRanged[0].mValue = src->mFloatsRanged[0].mValue;
  this->mFloatsRanged[0].mRange = src->mFloatsRanged[0].mRange;
  p_mData = &src->mStrings[0].mValue.mData;
  mStrings = this->mStrings;
  v21 = 25i64;
  do
  {
    UFG::qString::Set(&mStrings->mValue, *p_mData, *((_DWORD *)p_mData - 1), 0i64, 0);
    ++mStrings;
    p_mData += 5;
    --v21;
  }
  while ( v21 );
  p_mSize = &this->mBinaries[0].mSize;
  do
  {
    if ( *p_mSize )
      operator delete[](*((void **)p_mSize - 1));
    *((_QWORD *)p_mSize - 1) = 0i64;
    *p_mSize = 0;
    v23 = *(unsigned int *)((char *)p_mSize + v8);
    *p_mSize = v23;
    if ( v23 )
    {
      v24 = UFG::qMalloc(v23, "Binary", 0i64);
      UFG::qMemCopy(v24, *(const void **)((char *)p_mSize + v8 - 8), *p_mSize);
      *((_QWORD *)p_mSize - 1) = v24;
    }
    else
    {
      *((_QWORD *)p_mSize - 1) = 0i64;
    }
    p_mSize += 4;
    --v17;
  }
  while ( v17 );
  mpMapBools = this->mpMapBools;
  v26 = 93i64;
  do
  {
    v27 = *mpMapBools;
    if ( *mpMapBools )
    {
      UFG::PersistentData::MapBool::~MapBool(*mpMapBools);
      operator delete[](v27);
    }
    v28 = UFG::qMalloc(0x30ui64, "GameSnapshot", 0i64);
    v29 = (UFG::PersistentData::MapBool *)v28;
    if ( v28 )
    {
      v30 = *(__int64 *)((char *)mpMapBools + v8);
      LODWORD(v28->mNext) = *(_DWORD *)v30;
      v31 = (UFG::qArray<UFG::PersistentData::KeyValue,0> *)&v28[1];
      v28[2].mNext = 0i64;
      v28[1].mNext = 0i64;
      v28[4].mNext = 0i64;
      v28[3].mNext = 0i64;
      LODWORD(v28[5].mNext) = *(_DWORD *)(v30 + 40);
      mNext = (int)v28->mNext;
      if ( mNext )
      {
        if ( (unsigned int)(mNext - 1) <= 1 )
          UFG::qArray<UFG::qSymbol,0>::Clone((UFG::qArray<UFG::qSymbol,0> *)(v30 + 24), &v29->mNames);
      }
      else
      {
        UFG::qArray<UFG::PersistentData::KeyValue,0>::Clone(
          (UFG::qArray<UFG::PersistentData::KeyValue,0> *)(v30 + 8),
          v31);
      }
    }
    else
    {
      v29 = 0i64;
    }
    *mpMapBools++ = v29;
    --v26;
  }
  while ( v26 );
  mpMapInts = this->mpMapInts;
  v34 = 47i64;
  do
  {
    v35 = *mpMapInts;
    if ( *mpMapInts )
    {
      p = v35->mValues.p;
      if ( p )
      {
        v37 = (char *)&p[-1].4;
        `eh vector destructor iterator(p, 8ui64, p[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v37);
      }
      v35->mValues.p = 0i64;
      *(_QWORD *)&v35->mValues.size = 0i64;
      v38 = v35->mValues.p;
      if ( v38 )
      {
        v39 = (char *)&v38[-1].4;
        `eh vector destructor iterator(v38, 8ui64, v38[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v39);
      }
      v35->mValues.p = 0i64;
      *(_QWORD *)&v35->mValues.size = 0i64;
      operator delete[](v35);
    }
    v40 = (UFG::qArray<UFG::PersistentData::KeyValue,0> *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    v41 = (UFG::PersistentData::MapInt *)v40;
    if ( v40 )
    {
      v42 = *(UFG::qArray<UFG::PersistentData::KeyValue,0> **)((char *)mpMapInts + v8);
      v40->p = 0i64;
      *(_QWORD *)&v40->size = 0i64;
      v40[1].size = v42[1].size;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Clone(v42, v40);
    }
    else
    {
      v41 = 0i64;
    }
    *mpMapInts++ = v41;
    --v34;
  }
  while ( v34 );
  v43 = this->mpMapUInt64s[0];
  if ( v43 )
  {
    v44 = v43->mValues.p;
    if ( v44 )
    {
      p_mIntValue = &v44[-1].mIntValue;
      `eh vector destructor iterator(v44, 0x10ui64, v44[-1].mIntValue, (void (__fastcall *)(void *))_);
      operator delete[](p_mIntValue);
    }
    v43->mValues.p = 0i64;
    *(_QWORD *)&v43->mValues.size = 0i64;
    v46 = v43->mValues.p;
    if ( v46 )
    {
      v47 = &v46[-1].mIntValue;
      `eh vector destructor iterator(v46, 0x10ui64, v46[-1].mIntValue, (void (__fastcall *)(void *))_);
      operator delete[](v47);
    }
    v43->mValues.p = 0i64;
    *(_QWORD *)&v43->mValues.size = 0i64;
    operator delete[](v43);
  }
  v48 = (UFG::qArray<UFG::PersistentData::KeyValue64,0> *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
  v49 = (UFG::PersistentData::MapUInt64 *)v48;
  if ( v48 )
  {
    v50 = src->mpMapUInt64s[0];
    v48->p = 0i64;
    *(_QWORD *)&v48->size = 0i64;
    v48[1].size = v50->mPersistentDataType;
    UFG::qArray<UFG::PersistentData::KeyValue64,0>::Clone(&v50->mValues, v48);
  }
  else
  {
    v49 = 0i64;
  }
  this->mpMapUInt64s[0] = v49;
  mpMapFloats = this->mpMapFloats;
  v52 = 18i64;
  do
  {
    v53 = *mpMapFloats;
    if ( *mpMapFloats )
    {
      v54 = v53->mValues.p;
      if ( v54 )
      {
        v55 = (char *)&v54[-1].4;
        `eh vector destructor iterator(v54, 8ui64, v54[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v55);
      }
      v53->mValues.p = 0i64;
      *(_QWORD *)&v53->mValues.size = 0i64;
      v56 = v53->mValues.p;
      if ( v56 )
      {
        v57 = (char *)&v56[-1].4;
        `eh vector destructor iterator(v56, 8ui64, v56[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v57);
      }
      v53->mValues.p = 0i64;
      *(_QWORD *)&v53->mValues.size = 0i64;
      operator delete[](v53);
    }
    v58 = (UFG::qArray<UFG::PersistentData::KeyValue,0> *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    v59 = (UFG::PersistentData::MapFloat *)v58;
    if ( v58 )
    {
      v60 = *(UFG::qArray<UFG::PersistentData::KeyValue,0> **)((char *)mpMapFloats + v8);
      v58->p = 0i64;
      *(_QWORD *)&v58->size = 0i64;
      v58[1].size = v60[1].size;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Clone(v60, v58);
    }
    else
    {
      v59 = 0i64;
    }
    *mpMapFloats++ = v59;
    --v52;
  }
  while ( v52 );
  mpMapBinaries = this->mpMapBinaries;
  v62 = 2i64;
  do
  {
    v63 = *mpMapBinaries;
    if ( *mpMapBinaries )
    {
      UFG::PersistentData::MapBinary::Clear(v63);
      v64 = v63->mValues.p;
      if ( v64 )
      {
        v65 = &v64[-1].mBinary.mSize;
        `eh vector destructor iterator(v64, 0x18ui64, v64[-1].mBinary.mSize, (void (__fastcall *)(void *))_);
        operator delete[](v65);
      }
      v63->mValues.p = 0i64;
      *(_QWORD *)&v63->mValues.size = 0i64;
      operator delete[](v63);
    }
    v66 = UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    if ( v66 )
      UFG::PersistentData::MapBinary::MapBinary(
        (UFG::PersistentData::MapBinary *)v66,
        *(UFG::PersistentData::MapBinary **)((char *)mpMapBinaries + v8));
    else
      v67 = 0i64;
    *mpMapBinaries++ = v67;
    --v62;
  }
  while ( v62 );
  UFG::GameSnapshot::CreateList(this);
  v68 = this->mpList[0];
  v69 = src->mpList[0];
  v68->mType = v69->mType;
  switch ( v69->mType )
  {
    case LT_BOOL:
      UFG::qArray<bool,0>::Clone(v69->mBoolList, v68->mBoolList);
      break;
    case LT_INT:
      UFG::qArray<enum DNA::PropertyState::Enum,0>::Clone(
        (UFG::qArray<unsigned long,0> *)v69->mIntList,
        (UFG::qArray<unsigned long,0> *)v68->mIntList);
      break;
    case LT_INT64:
      UFG::qArray<UFG::qPropertySet *,0>::Clone(
        (UFG::qArray<UFG::RoadNetworkNode *,0> *)v69->mIntList,
        (UFG::qArray<UFG::RoadNetworkNode *,0> *)v68->mIntList);
      break;
    case LT_FLOAT:
      UFG::qArray<float,0>::Clone(v69->mFloatList, v68->mFloatList);
      break;
  }
}

// File Line: 242
// RVA: 0x4905E0
void __fastcall UFG::GameSnapshot::~GameSnapshot(UFG::GameSnapshot *this)
{
  UFG::PersistentData::Binary *mBinaries; // rbx
  __int64 v3; // rdi
  UFG::PersistentData::MapBool **mpMapBools; // rdi
  __int64 v5; // rsi
  UFG::PersistentData::MapBool *v6; // rbx
  UFG::PersistentData::MapInt **mpMapInts; // rsi
  __int64 v8; // rbp
  UFG::PersistentData::MapInt *v9; // rdi
  UFG::PersistentData::KeyValue *p; // rcx
  char *v11; // rbx
  UFG::PersistentData::KeyValue *v12; // rcx
  char *v13; // rbx
  UFG::PersistentData::MapUInt64 *v14; // rdi
  UFG::PersistentData::KeyValue64 *v15; // rcx
  unsigned __int64 *p_mIntValue; // rbx
  UFG::PersistentData::KeyValue64 *v17; // rcx
  unsigned __int64 *v18; // rbx
  UFG::PersistentData::MapFloat **mpMapFloats; // rsi
  __int64 v20; // rbp
  UFG::PersistentData::MapFloat *v21; // rdi
  UFG::PersistentData::KeyValue *v22; // rcx
  char *v23; // rbx
  UFG::PersistentData::KeyValue *v24; // rcx
  char *v25; // rbx
  UFG::PersistentData::MapBinary **mpMapBinaries; // rsi
  __int64 v27; // rbp
  UFG::PersistentData::MapBinary *v28; // rdi
  UFG::PersistentData::KeyBinary *v29; // rcx
  unsigned int *p_mSize; // rbx
  UFG::PersistentData::List *v31; // rdi
  UFG::qArray<long,0> *mIntList; // rbx
  int *v33; // rcx

  mBinaries = this->mBinaries;
  v3 = 3i64;
  do
  {
    if ( mBinaries->mSize )
      operator delete[](mBinaries->mpBuffer);
    mBinaries->mpBuffer = 0i64;
    mBinaries->mSize = 0;
    ++mBinaries;
    --v3;
  }
  while ( v3 );
  mpMapBools = this->mpMapBools;
  v5 = 93i64;
  do
  {
    v6 = *mpMapBools;
    if ( *mpMapBools )
    {
      UFG::PersistentData::MapBool::~MapBool(*mpMapBools);
      operator delete[](v6);
    }
    ++mpMapBools;
    --v5;
  }
  while ( v5 );
  mpMapInts = this->mpMapInts;
  v8 = 47i64;
  do
  {
    v9 = *mpMapInts;
    if ( *mpMapInts )
    {
      p = v9->mValues.p;
      if ( p )
      {
        v11 = (char *)&p[-1].4;
        `eh vector destructor iterator(p, 8ui64, p[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v11);
      }
      v9->mValues.p = 0i64;
      *(_QWORD *)&v9->mValues.size = 0i64;
      v12 = v9->mValues.p;
      if ( v12 )
      {
        v13 = (char *)&v12[-1].4;
        `eh vector destructor iterator(v12, 8ui64, v12[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v13);
      }
      v9->mValues.p = 0i64;
      *(_QWORD *)&v9->mValues.size = 0i64;
      operator delete[](v9);
    }
    ++mpMapInts;
    --v8;
  }
  while ( v8 );
  v14 = this->mpMapUInt64s[0];
  if ( v14 )
  {
    v15 = v14->mValues.p;
    if ( v15 )
    {
      p_mIntValue = &v15[-1].mIntValue;
      `eh vector destructor iterator(v15, 0x10ui64, v15[-1].mIntValue, (void (__fastcall *)(void *))_);
      operator delete[](p_mIntValue);
    }
    v14->mValues.p = 0i64;
    *(_QWORD *)&v14->mValues.size = 0i64;
    v17 = v14->mValues.p;
    if ( v17 )
    {
      v18 = &v17[-1].mIntValue;
      `eh vector destructor iterator(v17, 0x10ui64, v17[-1].mIntValue, (void (__fastcall *)(void *))_);
      operator delete[](v18);
    }
    v14->mValues.p = 0i64;
    *(_QWORD *)&v14->mValues.size = 0i64;
    operator delete[](v14);
  }
  mpMapFloats = this->mpMapFloats;
  v20 = 18i64;
  do
  {
    v21 = *mpMapFloats;
    if ( *mpMapFloats )
    {
      v22 = v21->mValues.p;
      if ( v22 )
      {
        v23 = (char *)&v22[-1].4;
        `eh vector destructor iterator(v22, 8ui64, v22[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v23);
      }
      v21->mValues.p = 0i64;
      *(_QWORD *)&v21->mValues.size = 0i64;
      v24 = v21->mValues.p;
      if ( v24 )
      {
        v25 = (char *)&v24[-1].4;
        `eh vector destructor iterator(v24, 8ui64, v24[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v25);
      }
      v21->mValues.p = 0i64;
      *(_QWORD *)&v21->mValues.size = 0i64;
      operator delete[](v21);
    }
    ++mpMapFloats;
    --v20;
  }
  while ( v20 );
  mpMapBinaries = this->mpMapBinaries;
  v27 = 2i64;
  do
  {
    v28 = *mpMapBinaries;
    if ( *mpMapBinaries )
    {
      UFG::PersistentData::MapBinary::Clear(v28);
      v29 = v28->mValues.p;
      if ( v29 )
      {
        p_mSize = &v29[-1].mBinary.mSize;
        `eh vector destructor iterator(v29, 0x18ui64, v29[-1].mBinary.mSize, (void (__fastcall *)(void *))_);
        operator delete[](p_mSize);
      }
      v28->mValues.p = 0i64;
      *(_QWORD *)&v28->mValues.size = 0i64;
      operator delete[](v28);
    }
    ++mpMapBinaries;
    --v27;
  }
  while ( v27 );
  v31 = this->mpList[0];
  if ( v31 )
  {
    mIntList = v31->mIntList;
    if ( mIntList && (v31->mType == LT_BOOL || v31->mType == LT_INT || (unsigned int)(v31->mType - 3) <= 1) )
    {
      v33 = mIntList->p;
      if ( v33 )
        operator delete[](v33);
      mIntList->p = 0i64;
      *(_QWORD *)&mIntList->size = 0i64;
      operator delete[](mIntList);
    }
    operator delete[](v31);
  }
  `eh vector destructor iterator(this->mBinaries, 0x10ui64, 3, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(
    this->mStrings,
    0x28ui64,
    25,
    (void (__fastcall *)(void *))UFG::PersistentData::String::~String);
  `eh vector destructor iterator(this->mFloatsRanged, 8ui64, 1, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(this->mIntsRanged, 8ui64, 7, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(this->mFloats, 4ui64, 139, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(this->mUInt64s, 8ui64, 1, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(this->mInts, 4ui64, 163, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(this->mBools, 1ui64, 58, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(this->mIDs, 4ui64, 44, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator(this, 0x10ui64, 30, (void (__fastcall *)(void *))UFG::PersistentData::Time::~Time);
}

// File Line: 289
// RVA: 0x4BFD30
void UFG::GameSnapshot::StaticInitialize(void)
{
  const char *v0; // r10
  unsigned int v1; // ecx
  char v2; // dl
  const char *v3; // r8
  char v4; // dl
  const char *v5; // r8
  unsigned int v6; // ecx
  const char *v7; // r11
  const char *v8; // r8
  unsigned int v9; // ecx
  char v10; // dl
  char v11; // dl
  unsigned int v12; // ecx
  const char *v13; // r8
  char v14; // dl
  int v15; // ecx
  const char *v16; // r8
  unsigned int v17; // ecx
  char v18; // dl
  const char *v19; // r8
  char v20; // dl
  int v21; // ecx
  const char *v22; // r8
  char v23; // dl
  int v24; // ecx
  const char *v25; // r8
  char v26; // dl
  unsigned int v27; // ecx
  const char *v28; // r8
  char v29; // dl
  const char *v30; // r8
  int v31; // ecx
  char v32; // dl
  const char *v33; // r8
  unsigned int v34; // ecx
  int v35; // ecx
  char v36; // dl
  const char *v37; // r8
  char v38; // dl
  int v39; // ecx
  const char *v40; // r8
  char v41; // dl
  int v42; // ecx
  const char *v43; // r8
  char v44; // dl
  const char *v45; // r8
  int v46; // ecx
  char v47; // dl
  const char *v48; // r8
  int v49; // ecx
  char v50; // dl
  int v51; // ecx
  const char *v52; // r8
  const char *v53; // r9
  const char *v54; // r8
  char v55; // dl
  int v56; // ecx
  char v57; // dl
  const char *v58; // r8
  unsigned int v59; // ecx
  char v60; // dl
  int v61; // ecx
  const char *v62; // r8
  char v63; // dl
  int v64; // ecx
  const char *v65; // r8
  char v66; // dl
  int v67; // ecx
  char v68; // dl
  const char *v69; // r8
  int v70; // ecx
  char v71; // dl
  int v72; // ecx
  int v73; // edx
  char v74; // cl

  v0 = "F";
  v1 = 8;
  v2 = 70;
  v3 = "F";
  do
  {
    if ( ((v2 - 70) & 0xDF) != 0 )
    {
      if ( ((v2 - 67) & 0xDF) == 0 )
        v1 |= 1u;
    }
    else
    {
      v1 |= 2u;
    }
    v2 = *++v3;
  }
  while ( v2 );
  UFG::GameSnapshot::sDefinitionInts[0] = v1;
  dword_142405734 = v1;
  UFG::GameSnapshot::sDefinitionFloats[0] = v1;
  dword_1424059C4 = v1;
  dword_1424059C8 = v1;
  dword_142405738 = v1;
  dword_14240573C = v1;
  dword_142405740 = v1;
  dword_142405744 = v1;
  dword_142405748 = v1;
  dword_14240574C = v1;
  dword_142405750 = v1;
  dword_142405754 = v1;
  dword_142405758 = v1;
  dword_14240575C = v1;
  dword_142405760 = v1;
  dword_142405764 = v1;
  dword_142405768 = v1;
  dword_14240576C = v1;
  dword_142405770 = v1;
  UFG::GameSnapshot::sDefinitionTimes[0] = v1;
  dword_142405774 = v1;
  UFG::GameSnapshot::sDefinitionMapInts[0] = v1;
  UFG::GameSnapshot::sDefinitionMapBools[0] = v1;
  dword_142405E14 = v1;
  v4 = 70;
  v5 = "F";
  v6 = 16;
  do
  {
    if ( ((v4 - 70) & 0xDF) != 0 )
    {
      if ( ((v4 - 67) & 0xDF) == 0 )
        v6 |= 1u;
    }
    else
    {
      v6 |= 2u;
    }
    v4 = *++v5;
  }
  while ( v4 );
  v7 = "FC";
  UFG::GameSnapshot::sDefinitionMapFloats[0] = v6;
  dword_142405ED4 = v6;
  dword_142405E18 = v6;
  dword_142405E1C = v6;
  dword_142405E20 = v6;
  v8 = "FC";
  v9 = 32;
  v10 = 70;
  do
  {
    if ( ((v10 - 70) & 0xDF) != 0 )
    {
      if ( ((v10 - 67) & 0xDF) == 0 )
        v9 |= 1u;
    }
    else
    {
      v9 |= 2u;
    }
    v10 = *++v8;
  }
  while ( v10 );
  UFG::GameSnapshot::sDefinitionIDs[0] = v9;
  dword_142405594 = v9;
  dword_142405598 = v9;
  dword_14240559C = v9;
  dword_1424055A0 = v9;
  dword_1424055A4 = v9;
  dword_1424055A8 = v9;
  dword_1424055AC = v9;
  dword_1424055B0 = v9;
  dword_1424055B4 = v9;
  dword_1424055B8 = v9;
  dword_1424055BC = v9;
  dword_1424055C0 = v9;
  dword_1424055C4 = v9;
  dword_1424055C8 = v9;
  dword_1424055CC = v9;
  dword_1424055D0 = v9;
  dword_1424055D4 = v9;
  dword_1424055D8 = v9;
  dword_1424055DC = v9;
  dword_1424055E0 = v9;
  dword_1424055E4 = v9;
  dword_142405E24 = v9;
  dword_142405E28 = v9;
  dword_142405E2C = v9;
  dword_142405E30 = v9;
  dword_142405E34 = v9;
  dword_142405E38 = v9;
  dword_142405E3C = v9;
  dword_142405E40 = v9;
  dword_142405E44 = v9;
  UFG::GameSnapshot::sDefinitionMapUInt64s[0] = v9;
  dword_1424059CC = v9;
  dword_1424059D0 = v9;
  dword_1424059D4 = v9;
  dword_1424059D8 = v9;
  dword_1424059DC = v9;
  dword_1424059E0 = v9;
  dword_1424059E4 = v9;
  dword_1424059E8 = v9;
  dword_1424059EC = v9;
  dword_1424059F0 = v9;
  dword_1424059F4 = v9;
  dword_1424059F8 = v9;
  dword_1424059FC = v9;
  dword_142405A00 = v9;
  dword_142405A04 = v9;
  dword_142405A08 = v9;
  dword_142405A0C = v9;
  dword_142405A10 = v9;
  dword_142405A14 = v9;
  dword_142405A18 = v9;
  dword_142405A1C = v9;
  dword_142405A20 = v9;
  dword_142405A24 = v9;
  dword_142405A28 = v9;
  dword_142405A2C = v9;
  dword_142405A30 = v9;
  dword_142405A34 = v9;
  dword_142405A38 = v9;
  dword_142405A3C = v9;
  dword_142405A40 = v9;
  dword_142405A44 = v9;
  dword_142405A48 = v9;
  dword_142405A4C = v9;
  dword_142405A50 = v9;
  dword_142405A54 = v9;
  dword_142405A58 = v9;
  dword_142405A5C = v9;
  dword_142405778 = v9;
  UFG::GameSnapshot::sDefinitionBinaries[0] = v9;
  v11 = 70;
  v12 = 64;
  v13 = "F";
  do
  {
    if ( ((v11 - 70) & 0xDF) != 0 )
    {
      if ( ((v11 - 67) & 0xDF) == 0 )
        v12 |= 1u;
    }
    else
    {
      v12 |= 2u;
    }
    v11 = *++v13;
  }
  while ( v11 );
  dword_142405A60 = v12;
  dword_14240577C = v12;
  dword_142405780 = v12;
  dword_142405784 = v12;
  UFG::GameSnapshot::sDefinitionBools[0] = v12;
  dword_142405788 = v12;
  dword_14240578C = v12;
  dword_142405790 = v12;
  dword_142405794 = v12;
  dword_142405798 = v12;
  dword_14240579C = v12;
  dword_1424057A0 = v12;
  dword_142405A64 = v12;
  dword_142405A68 = v12;
  dword_1424057A4 = v12;
  dword_1424057A8 = v12;
  dword_1424057AC = v12;
  dword_1424057B0 = v12;
  dword_142405A6C = v12;
  dword_142405A70 = v12;
  dword_142405A74 = v12;
  dword_142405A78 = v12;
  dword_1424057B4 = v12;
  dword_1424057B8 = v12;
  dword_1424057BC = v12;
  dword_1424057C0 = v12;
  dword_1424057C4 = v12;
  dword_1424057C8 = v12;
  dword_1424057CC = v12;
  dword_1424057D0 = v12;
  dword_1424057D4 = v12;
  dword_1424057D8 = v12;
  dword_142405A7C = v12;
  dword_142405A80 = v12;
  dword_142405A84 = v12;
  dword_142405A88 = v12;
  dword_142405A8C = v12;
  dword_142405A90 = v12;
  dword_142405A94 = v12;
  dword_142405A98 = v12;
  dword_142405A9C = v12;
  dword_142405AA0 = v12;
  dword_142405AA4 = v12;
  dword_142405AA8 = v12;
  dword_142405AAC = v12;
  dword_142405AB0 = v12;
  dword_142405AB4 = v12;
  dword_142405AB8 = v12;
  dword_142405ABC = v12;
  dword_142405AC0 = v12;
  dword_142405AC4 = v12;
  dword_142405AC8 = v12;
  dword_142405ACC = v12;
  dword_142405AD0 = v12;
  dword_142405AD4 = v12;
  dword_142405AD8 = v12;
  dword_142405ADC = v12;
  dword_1424057DC = v12;
  dword_142405AE0 = v12;
  dword_142405AE4 = v12;
  dword_142405AE8 = v12;
  dword_142405AEC = v12;
  dword_142405AF0 = v12;
  dword_1424057E0 = v12;
  dword_142405AF4 = v12;
  dword_1424057E4 = v12;
  dword_142405AF8 = v12;
  dword_142405E48 = v12;
  v14 = 70;
  v15 = 128;
  v16 = "FC";
  do
  {
    if ( ((v14 - 70) & 0xDF) != 0 )
    {
      if ( ((v14 - 67) & 0xDF) == 0 )
        v15 |= 1u;
    }
    else
    {
      v15 |= 2u;
    }
    v14 = *++v16;
  }
  while ( v14 );
  dword_1424055E8 = v15;
  dword_142405644 = v15;
  dword_1424057E8 = v15;
  dword_1424055EC = v15;
  dword_1424055F0 = v15;
  dword_142405E4C = v15;
  v17 = 256;
  v18 = 70;
  v19 = "F";
  do
  {
    if ( ((v18 - 70) & 0xDF) != 0 )
    {
      if ( ((v18 - 67) & 0xDF) == 0 )
        v17 |= 1u;
    }
    else
    {
      v17 |= 2u;
    }
    v18 = *++v19;
  }
  while ( v18 );
  dword_142405C94 = v17;
  dword_142405C98 = v17;
  dword_142405C9C = v17;
  dword_142405CA0 = v17;
  dword_142405CA4 = v17;
  dword_142405CA8 = v17;
  dword_142405CAC = v17;
  dword_142405E50 = v17;
  dword_142405E54 = v17;
  dword_142405CB0 = v17;
  dword_142405CB4 = v17;
  dword_142405E58 = v17;
  dword_142405CB8 = v17;
  dword_142405CBC = v17;
  dword_142405CC0 = v17;
  dword_142405E5C = v17;
  dword_142405E60 = v17;
  dword_142405CC4 = v17;
  dword_142405CC8 = v17;
  dword_142405CCC = v17;
  dword_142405CD0 = v17;
  dword_142405CD4 = v17;
  dword_142405CD8 = v17;
  dword_142405CDC = v17;
  dword_1424057EC = v17;
  dword_142405CE0 = v17;
  dword_142405CE4 = v17;
  dword_142405514 = v17;
  dword_142405648 = v17;
  dword_142405CE8 = v17;
  dword_142405CEC = v17;
  dword_142405CF0 = v17;
  dword_142405CF4 = v17;
  dword_142405CF8 = v17;
  dword_142405CFC = v17;
  dword_142405D00 = v17;
  dword_142405D04 = v17;
  dword_142405D08 = v17;
  dword_142405D0C = v17;
  dword_142405D10 = v17;
  dword_142405D14 = v17;
  dword_142405D18 = v17;
  dword_142405D1C = v17;
  dword_142405D20 = v17;
  dword_142405D24 = v17;
  dword_142405D28 = v17;
  dword_142405D2C = v17;
  dword_142405D30 = v17;
  dword_142405D34 = v17;
  dword_142405D38 = v17;
  dword_142405D3C = v17;
  dword_142405D40 = v17;
  dword_142405D44 = v17;
  dword_142405D48 = v17;
  dword_142405D4C = v17;
  dword_142405D50 = v17;
  dword_142405D54 = v17;
  dword_142405D58 = v17;
  dword_142405D5C = v17;
  dword_142405D60 = v17;
  dword_142405D64 = v17;
  dword_142405D68 = v17;
  dword_142405D6C = v17;
  UFG::GameSnapshot::sDefinitionMapBinaries[0] = v17;
  dword_1424057F0 = v17;
  v20 = 70;
  v21 = 1024;
  v22 = "F";
  do
  {
    if ( ((v20 - 70) & 0xDF) != 0 )
    {
      if ( ((v20 - 67) & 0xDF) == 0 )
        v21 |= 1u;
    }
    else
    {
      v21 |= 2u;
    }
    v20 = *++v22;
  }
  while ( v20 );
  dword_142405D70 = v21;
  dword_142405D74 = v21;
  dword_142405D78 = v21;
  dword_142405D7C = v21;
  dword_142405D80 = v21;
  v23 = 70;
  v24 = 512;
  v25 = "FC";
  do
  {
    if ( ((v23 - 70) & 0xDF) != 0 )
    {
      if ( ((v23 - 67) & 0xDF) == 0 )
        v24 |= 1u;
    }
    else
    {
      v24 |= 2u;
    }
    v23 = *++v25;
  }
  while ( v23 );
  dword_142405D84 = v24;
  dword_142405D88 = v24;
  dword_142405D8C = v24;
  dword_142405D90 = v24;
  dword_142405D94 = v24;
  v26 = 70;
  v27 = 2048;
  v28 = "F";
  do
  {
    if ( ((v26 - 70) & 0xDF) != 0 )
    {
      if ( ((v26 - 67) & 0xDF) == 0 )
        v27 |= 1u;
    }
    else
    {
      v27 |= 2u;
    }
    v26 = *++v28;
  }
  while ( v26 );
  dword_1424055F4 = v27;
  dword_1424055F8 = v27;
  dword_1424055FC = v27;
  dword_14240564C = v27;
  dword_142405650 = v27;
  dword_142405654 = v27;
  dword_142405658 = v27;
  dword_14240565C = v27;
  dword_142405660 = v27;
  dword_142405664 = v27;
  dword_142405668 = v27;
  dword_14240566C = v27;
  dword_142405670 = v27;
  dword_142405674 = v27;
  dword_142405678 = v27;
  dword_14240567C = v27;
  dword_142405680 = v27;
  dword_142405684 = v27;
  dword_142405688 = v27;
  dword_14240568C = v27;
  dword_142405690 = v27;
  dword_142405694 = v27;
  dword_142405698 = v27;
  dword_14240569C = v27;
  dword_1424056A0 = v27;
  dword_1424056A4 = v27;
  dword_1424056A8 = v27;
  dword_1424056AC = v27;
  dword_1424056B0 = v27;
  dword_1424056B4 = v27;
  dword_1424056B8 = v27;
  dword_1424056BC = v27;
  dword_142405600 = v27;
  dword_142405604 = v27;
  dword_142405AFC = v27;
  dword_142405B00 = v27;
  dword_142405B04 = v27;
  dword_142405B08 = v27;
  dword_142405B0C = v27;
  dword_142405B10 = v27;
  dword_142405B14 = v27;
  dword_142405B18 = v27;
  dword_142405D98 = v27;
  dword_1424057F4 = v27;
  dword_1424057F8 = v27;
  dword_142405D9C = v27;
  dword_1424057FC = v27;
  dword_142405800 = v27;
  dword_142405DA0 = v27;
  dword_142405804 = v27;
  dword_142405808 = v27;
  dword_142405DA4 = v27;
  dword_14240580C = v27;
  dword_142405810 = v27;
  dword_142405DA8 = v27;
  dword_142405814 = v27;
  dword_142405818 = v27;
  dword_142405DAC = v27;
  dword_14240581C = v27;
  dword_142405DB0 = v27;
  dword_142405DB4 = v27;
  UFG::GameSnapshot::sDefinitionStrings[0] = v27;
  dword_142405C14 = v27;
  dword_142405C18 = v27;
  dword_142405C1C = v27;
  dword_142405C20 = v27;
  dword_142405C24 = v27;
  dword_142405E64 = v27;
  dword_142405820 = v27;
  dword_142405DB8 = v27;
  v29 = 70;
  v30 = "FC";
  v31 = 4096;
  do
  {
    if ( ((v29 - 70) & 0xDF) != 0 )
    {
      if ( ((v29 - 67) & 0xDF) == 0 )
        v31 |= 1u;
    }
    else
    {
      v31 |= 2u;
    }
    v29 = *++v30;
  }
  while ( v29 );
  dword_142405C28 = v31;
  dword_142405DBC = v31;
  dword_142405E68 = v31;
  dword_1424056C0 = v31;
  dword_142405DC0 = v31;
  dword_142405E6C = v31;
  dword_142405C7C = v31;
  v32 = 70;
  v33 = "FC";
  v34 = 0x2000;
  do
  {
    if ( ((v32 - 70) & 0xDF) != 0 )
    {
      if ( ((v32 - 67) & 0xDF) == 0 )
        v34 |= 1u;
    }
    else
    {
      v34 |= 2u;
    }
    v32 = *++v33;
  }
  while ( v32 );
  dword_142405824 = v34;
  dword_142405828 = v34;
  dword_14240582C = v34;
  dword_142405830 = v34;
  dword_142405834 = v34;
  dword_142405838 = v34;
  dword_14240583C = v34;
  dword_142405840 = v34;
  dword_142405844 = v34;
  dword_142405848 = v34;
  dword_14240584C = v34;
  dword_142405850 = v34;
  dword_142405854 = v34;
  dword_142405858 = v34;
  dword_14240585C = v34;
  dword_142405860 = v34;
  dword_142405864 = v34;
  UFG::GameSnapshot::sDefinitionIntsRanged[0] = v34;
  dword_142405BF4 = v34;
  dword_142405868 = v34;
  dword_14240586C = v34;
  dword_142405870 = v34;
  dword_142405874 = v34;
  dword_142405878 = v34;
  dword_14240587C = v34;
  dword_142405DC4 = v34;
  dword_142405DC8 = v34;
  v35 = 0x4000;
  v36 = 70;
  v37 = "F";
  do
  {
    if ( ((v36 - 70) & 0xDF) != 0 )
    {
      if ( ((v36 - 67) & 0xDF) == 0 )
        v35 |= 1u;
    }
    else
    {
      v35 |= 2u;
    }
    v36 = *++v37;
  }
  while ( v36 );
  dword_142405880 = v35;
  dword_142405884 = v35;
  dword_142405888 = v35;
  dword_14240588C = v35;
  dword_142405890 = v35;
  dword_142405894 = v35;
  dword_142405898 = v35;
  dword_14240589C = v35;
  dword_142405B1C = v35;
  dword_142405B20 = v35;
  dword_142405BF8 = v35;
  dword_1424058A0 = v35;
  dword_142405B24 = v35;
  dword_142405B28 = v35;
  dword_142405B2C = v35;
  dword_142405B30 = v35;
  dword_142405B34 = v35;
  dword_142405B38 = v35;
  dword_142405B3C = v35;
  dword_1424058A4 = v35;
  dword_142405B40 = v35;
  dword_142405B44 = v35;
  dword_142405B48 = v35;
  v38 = 70;
  v39 = 0x8000;
  v40 = "FC";
  do
  {
    if ( ((v38 - 70) & 0xDF) != 0 )
    {
      if ( ((v38 - 67) & 0xDF) == 0 )
        v39 |= 1u;
    }
    else
    {
      v39 |= 2u;
    }
    v38 = *++v40;
  }
  while ( v38 );
  dword_142405608 = v39;
  dword_1424056C4 = v39;
  dword_142405B4C = v39;
  dword_142405B50 = v39;
  dword_142405B54 = v39;
  v41 = 70;
  v42 = 0x10000;
  v43 = "F";
  do
  {
    if ( ((v41 - 70) & 0xDF) != 0 )
    {
      if ( ((v41 - 67) & 0xDF) == 0 )
        v42 |= 1u;
    }
    else
    {
      v42 |= 2u;
    }
    v41 = *++v43;
  }
  while ( v41 );
  dword_1424058A8 = v42;
  dword_1424058AC = v42;
  dword_1424058B0 = v42;
  dword_1424058B4 = v42;
  dword_1424058B8 = v42;
  dword_142405BFC = v42;
  dword_142405C00 = v42;
  dword_142405C04 = v42;
  dword_142405C08 = v42;
  dword_1424058BC = v42;
  dword_1424058C0 = v42;
  dword_1424058C4 = v42;
  dword_1424058C8 = v42;
  dword_1424058CC = v42;
  dword_1424058D0 = v42;
  dword_1424058D4 = v42;
  dword_1424058D8 = v42;
  dword_1424058DC = v42;
  dword_1424058E0 = v42;
  dword_1424058E4 = v42;
  dword_1424058E8 = v42;
  dword_1424058EC = v42;
  dword_1424058F0 = v42;
  dword_1424058F4 = v42;
  dword_1424058F8 = v42;
  dword_1424058FC = v42;
  dword_142405900 = v42;
  dword_142405B58 = v42;
  dword_142405B5C = v42;
  dword_142405904 = v42;
  dword_142405908 = v42;
  dword_14240590C = v42;
  dword_142405910 = v42;
  dword_142405914 = v42;
  dword_142405B60 = v42;
  dword_142405E70 = v42;
  dword_142405E74 = v42;
  dword_142405E78 = v42;
  dword_142405E7C = v42;
  dword_142405E80 = v42;
  v44 = 70;
  v45 = "F";
  v46 = 0x20000;
  do
  {
    if ( ((v44 - 70) & 0xDF) != 0 )
    {
      if ( ((v44 - 67) & 0xDF) == 0 )
        v46 |= 1u;
    }
    else
    {
      v46 |= 2u;
    }
    v44 = *++v45;
  }
  while ( v44 );
  dword_142405518 = v46;
  dword_14240551C = v46;
  dword_142405B64 = v46;
  dword_142405B68 = v46;
  dword_142405520 = v46;
  dword_142405B6C = v46;
  dword_142405524 = v46;
  dword_142405B70 = v46;
  dword_142405528 = v46;
  dword_14240552C = v46;
  dword_142405530 = v46;
  dword_142405534 = v46;
  dword_142405538 = v46;
  dword_14240553C = v46;
  dword_142405B74 = v46;
  dword_142405B78 = v46;
  dword_142405B7C = v46;
  dword_142405540 = v46;
  dword_142405ED8 = v46;
  dword_142405EDC = v46;
  dword_142405EE0 = v46;
  dword_142405EE4 = v46;
  v47 = 70;
  v48 = "F";
  v49 = 4;
  do
  {
    if ( ((v47 - 70) & 0xDF) != 0 )
    {
      if ( ((v47 - 67) & 0xDF) == 0 )
        v49 |= 1u;
    }
    else
    {
      v49 |= 2u;
    }
    v47 = *++v48;
  }
  while ( v47 );
  dword_142405918 = v49;
  dword_14240591C = v49;
  dword_142405920 = v49;
  dword_142405924 = v49;
  dword_142405928 = v49;
  dword_14240592C = v49;
  dword_142405930 = v49;
  dword_142405934 = v49;
  dword_142405938 = v49;
  dword_14240593C = v49;
  dword_1424056C8 = v49;
  dword_1424056CC = v49;
  dword_1424056D0 = v49;
  dword_1424056D4 = v49;
  dword_1424056D8 = v49;
  dword_1424056DC = v49;
  dword_142405B80 = v49;
  dword_142405B84 = v49;
  dword_1424056E0 = v49;
  dword_142405B88 = v49;
  dword_142405B8C = v49;
  dword_142405B90 = v49;
  dword_1424056E4 = v49;
  dword_1424056E8 = v49;
  dword_142405940 = v49;
  dword_1424056EC = v49;
  dword_1424056F0 = v49;
  dword_1424056F4 = v49;
  dword_142405944 = v49;
  dword_1424056F8 = v49;
  dword_142405B94 = v49;
  dword_1424056FC = v49;
  dword_142405948 = v49;
  dword_14240594C = v49;
  dword_142405950 = v49;
  dword_142405954 = v49;
  dword_142405958 = v49;
  dword_14240595C = v49;
  dword_142405960 = v49;
  dword_142405C8C = v49;
  dword_142405E84 = v49;
  dword_142405DCC = v49;
  dword_142405964 = v49;
  dword_142405E88 = v49;
  dword_142405E8C = v49;
  dword_142405E90 = v49;
  dword_142405E94 = v49;
  dword_142405EE8 = v49;
  dword_142405EEC = v49;
  dword_142405EF0 = v49;
  dword_142405DD0 = v49;
  dword_142405968 = v49;
  dword_14240596C = v49;
  dword_142405970 = v49;
  dword_142405974 = v49;
  dword_142405978 = v49;
  dword_14240597C = v49;
  dword_142405980 = v49;
  dword_142405984 = v49;
  dword_142405700 = v49;
  dword_142405704 = v49;
  dword_142405708 = v49;
  dword_14240570C = v49;
  dword_142405988 = v49;
  dword_142405710 = v49;
  dword_142405714 = v49;
  dword_142405718 = v49;
  dword_14240571C = v49;
  dword_142405720 = v49;
  dword_142405724 = v49;
  dword_142405DD4 = v49;
  dword_142405E98 = v49;
  dword_142405DD8 = v49;
  dword_142405DDC = v49;
  v50 = 70;
  v51 = 0x40000;
  v52 = "F";
  do
  {
    if ( ((v50 - 70) & 0xDF) != 0 )
    {
      if ( ((v50 - 67) & 0xDF) == 0 )
        v51 |= 1u;
    }
    else
    {
      v51 |= 2u;
    }
    v50 = *++v52;
  }
  while ( v50 );
  v53 = "C";
  dword_142405E9C = v51;
  dword_142405EA0 = v51;
  dword_142405EA4 = v51;
  dword_142405EA8 = v51;
  dword_142405EF4 = v51;
  dword_142405DE0 = v51;
  v54 = "C";
  v55 = 67;
  v56 = 0x80000;
  do
  {
    if ( ((v55 - 70) & 0xDF) != 0 )
    {
      if ( ((v55 - 67) & 0xDF) == 0 )
        v56 |= 1u;
    }
    else
    {
      v56 |= 2u;
    }
    v55 = *++v54;
  }
  while ( v55 );
  dword_14240598C = v56;
  dword_142405B98 = v56;
  dword_142405B9C = v56;
  dword_142405BA0 = v56;
  dword_142405BA4 = v56;
  dword_142405BA8 = v56;
  dword_142405BAC = v56;
  dword_142405BB0 = v56;
  dword_142405BB4 = v56;
  dword_142405C2C = v56;
  dword_142405C30 = v56;
  dword_142405C34 = v56;
  dword_142405C38 = v56;
  dword_142405C3C = v56;
  dword_142405C40 = v56;
  dword_142405C44 = v56;
  dword_142405C48 = v56;
  dword_142405C4C = v56;
  dword_142405C50 = v56;
  dword_142405C54 = v56;
  dword_142405C58 = v56;
  dword_142405C5C = v56;
  dword_142405C60 = v56;
  dword_142405C64 = v56;
  dword_142405BB8 = v56;
  dword_142405544 = v56;
  dword_142405548 = v56;
  dword_14240554C = v56;
  dword_142405550 = v56;
  dword_142405554 = v56;
  dword_142405558 = v56;
  dword_142405990 = v56;
  dword_142405994 = v56;
  dword_142405998 = v56;
  dword_14240560C = v56;
  dword_14240599C = v56;
  dword_1424059A0 = v56;
  v57 = 67;
  v58 = "C";
  v59 = 0x100000;
  do
  {
    if ( ((v57 - 70) & 0xDF) != 0 )
    {
      if ( ((v57 - 67) & 0xDF) == 0 )
        v59 |= 1u;
    }
    else
    {
      v59 |= 2u;
    }
    v57 = *++v58;
  }
  while ( v57 );
  UFG::GameSnapshot::sDefinitionFloatsRanged[0] = v59;
  dword_142405C68 = v59;
  dword_142405C80 = v59;
  UFG::GameSnapshot::sDefinitionList[0] = v59;
  v60 = 70;
  UFG::GameSnapshot::sDefinitionUInt64s[0] = v59;
  v61 = 0x200000;
  v62 = "FC";
  do
  {
    if ( ((v60 - 70) & 0xDF) != 0 )
    {
      if ( ((v60 - 67) & 0xDF) == 0 )
        v61 |= 1u;
    }
    else
    {
      v61 |= 2u;
    }
    v60 = *++v62;
  }
  while ( v60 );
  dword_142405BBC = v61;
  dword_142405BC0 = v61;
  v63 = 70;
  v64 = 0x400000;
  v65 = "FC";
  do
  {
    if ( ((v63 - 70) & 0xDF) != 0 )
    {
      if ( ((v63 - 67) & 0xDF) == 0 )
        v64 |= 1u;
    }
    else
    {
      v64 |= 2u;
    }
    v63 = *++v65;
  }
  while ( v63 );
  dword_142405BC4 = v64;
  dword_142405BC8 = v64;
  dword_142405BCC = v64;
  dword_1424059A4 = v64;
  v66 = 67;
  v67 = 0x800000;
  do
  {
    if ( ((v66 - 70) & 0xDF) != 0 )
    {
      if ( ((v66 - 67) & 0xDF) == 0 )
        v67 |= 1u;
    }
    else
    {
      v67 |= 2u;
    }
    v66 = *++v53;
  }
  while ( v66 );
  dword_142405610 = v67;
  dword_142405614 = v67;
  dword_142405618 = v67;
  dword_142405BD0 = v67;
  dword_142405BD4 = v67;
  dword_142405BD8 = v67;
  dword_142405BDC = v67;
  dword_142405BE0 = v67;
  dword_142405BE4 = v67;
  dword_142405BE8 = v67;
  dword_14240555C = v67;
  dword_142405560 = v67;
  dword_142405564 = v67;
  dword_1424059A8 = v67;
  dword_1424059AC = v67;
  dword_1424059B0 = v67;
  dword_1424059B4 = v67;
  dword_1424059B8 = v67;
  dword_142405C6C = v67;
  v68 = 70;
  v69 = "F";
  v70 = 0x1000000;
  do
  {
    if ( ((v68 - 70) & 0xDF) != 0 )
    {
      if ( ((v68 - 67) & 0xDF) == 0 )
        v70 |= 1u;
    }
    else
    {
      v70 |= 2u;
    }
    v68 = *++v69;
  }
  while ( v68 );
  dword_142405568 = v70;
  dword_14240556C = v70;
  dword_142405570 = v70;
  dword_142405574 = v70;
  dword_14240561C = v70;
  dword_142405620 = v70;
  dword_142405624 = v70;
  dword_142405628 = v70;
  dword_142405EAC = v70;
  dword_142405EB0 = v70;
  dword_142405EB4 = v70;
  dword_142405EB8 = v70;
  dword_142405DE4 = v70;
  dword_142405DE8 = v70;
  dword_142405DEC = v70;
  dword_142405DF0 = v70;
  dword_142405EF8 = v70;
  dword_142405EFC = v70;
  dword_142405F00 = v70;
  dword_142405F04 = v70;
  v71 = 70;
  v72 = 0x2000000;
  do
  {
    if ( ((v71 - 70) & 0xDF) != 0 )
    {
      if ( ((v71 - 67) & 0xDF) == 0 )
        v72 |= 1u;
    }
    else
    {
      v72 |= 2u;
    }
    v71 = *++v7;
  }
  while ( v71 );
  dword_142405578 = v72;
  dword_14240557C = v72;
  dword_142405580 = v72;
  dword_142405584 = v72;
  dword_14240562C = v72;
  dword_142405630 = v72;
  dword_142405634 = v72;
  dword_142405638 = v72;
  dword_142405EBC = v72;
  dword_142405EC0 = v72;
  dword_142405EC4 = v72;
  dword_142405EC8 = v72;
  dword_142405DF4 = v72;
  dword_142405DF8 = v72;
  dword_142405DFC = v72;
  dword_142405E00 = v72;
  dword_142405F08 = v72;
  dword_142405F0C = v72;
  dword_142405F10 = v72;
  dword_142405F14[0] = v72;
  v73 = 0x4000000;
  v74 = 70;
  do
  {
    if ( ((v74 - 70) & 0xDF) != 0 )
    {
      if ( ((v74 - 67) & 0xDF) == 0 )
        v73 |= 1u;
    }
    else
    {
      v73 |= 2u;
    }
    v74 = *++v0;
  }
  while ( v74 );
  dword_14240563C = v73;
  dword_142405C70 = v73;
}= v70;
  dword_142405EFC = v70;
  dword_142405F00 = v70;
  dword_142405F04 = v70;
  v71 = 70;
  v72 = 0x2000000;
  do
  {
    if ( ((v71 - 70) & 0xDF) != 0 )
    {
      if ( ((v71 - 67) & 0xDF) == 0 )
        v72 |= 1u;
    }
    else
    {
      v72 |= 2u;
    }
    v71 = *++v7;
  }
  while ( v71 );
  dword_142405578 = v72;
  dword_14240557C = v72;
  dword_142405580 = v72;
  dword_142405584 = v72;
  dword_14240562C = v72;
  dword_142405630 = v72;
  dword_142405634 = v72;
  dword_142405638 = v72;
  dword_142405EBC = v72;
  dword_142405EC0 = v72;
  dword_142405EC4 = v72;
  dword_142405EC8 = v72;
  dword_142405DF4 = v72;
  dword_142405DF8 = v72;
  dword_142405DFC = v72;
  dword_142405E00 = v72;
  dword_142405F08 = v72;
  dword_142405F0C = v72;
  dword_142405F10 = v72;
  dword_142405F14[0] = v72;
  v73 = 0x4000000;
  v74 = 70;
  do
  {
    if ( ((v74 - 70) & 0xDF) != 0 )
    {
      if ( ((v74 - 67) & 0xDF) == 0 )
        v73 |= 1u;
    }
    else
    {
      v73 |= 2u;
    }

// File Line: 321
// RVA: 0x498AC0
void __fastcall UFG::GameSnapshot::CommitByFilter(
        UFG::GameSnapshot *this,
        UFG::GameSnapshot *pRecentSnapshot,
        unsigned int filterMask,
        unsigned int persistenceMask,
        unsigned int rejectMask)
{
  __int64 v5; // rdi
  __int64 v6; // r14
  UFG::GameSnapshot *v9; // r9
  unsigned int *v10; // r11
  signed __int64 v11; // r8
  __int64 v12; // rbx
  unsigned int v13; // r10d
  UFG::PersistentData::ID *mIDs; // rcx
  signed __int64 v15; // r10
  __int64 v16; // r9
  int v17; // edx
  __int64 v18; // rcx
  __int64 v19; // r9
  unsigned int v20; // edx
  UFG::PersistentData::Int *mInts; // rcx
  __int64 v22; // r9
  int v23; // edx
  UFG::PersistentData::Float *mFloats; // rcx
  __int64 v25; // r9
  int v26; // edx
  int v27; // edx
  int v28; // edx
  int v29; // edx
  int v30; // edx
  int v31; // edx
  int v32; // edx
  int v33; // edx
  UFG::PersistentData::Float *v34; // rcx
  __int64 v35; // r13
  __int64 v36; // r9
  int v37; // edx
  unsigned int *v38; // r8
  int *p_mRange; // rcx
  signed __int64 v40; // r10
  __int64 v41; // r9
  unsigned int v42; // edx
  unsigned int *v43; // rsi
  char **p_mData; // rbx
  UFG::PersistentData::String *mStrings; // r15
  __int64 v46; // r12
  unsigned int v47; // ecx
  unsigned int *v48; // r15
  unsigned int *p_mSize; // rsi
  unsigned int v50; // ecx
  unsigned int v51; // eax
  UFG::allocator::free_link *v52; // rbx
  unsigned int *v53; // r15
  UFG::PersistentData::MapBool **mpMapBools; // rsi
  __int64 v55; // r12
  unsigned int v56; // ecx
  UFG::PersistentData::MapBool *v57; // rbx
  UFG::allocator::free_link *v58; // rbx
  __int64 v59; // r8
  unsigned int *v60; // r12
  UFG::PersistentData::MapInt **mpMapInts; // r15
  __int64 v62; // r13
  unsigned int v63; // ecx
  UFG::PersistentData::MapInt *v64; // rsi
  UFG::PersistentData::KeyValue *p; // rcx
  char *v66; // rbx
  UFG::PersistentData::KeyValue *v67; // rcx
  char *v68; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v69; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v70; // rcx
  UFG::PersistentData::MapUInt64 *v71; // rsi
  UFG::PersistentData::KeyValue64 *v72; // rcx
  unsigned __int64 *p_mIntValue; // rbx
  UFG::PersistentData::KeyValue64 *v74; // rcx
  unsigned __int64 *v75; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue64,0> *v76; // rax
  UFG::PersistentData::MapUInt64 *v77; // rbx
  UFG::PersistentData::MapUInt64 *v78; // rcx
  unsigned int *v79; // r12
  UFG::PersistentData::MapFloat **mpMapFloats; // r15
  __int64 v81; // r13
  unsigned int v82; // ecx
  UFG::PersistentData::MapFloat *v83; // rsi
  UFG::PersistentData::KeyValue *v84; // rcx
  char *v85; // rbx
  UFG::PersistentData::KeyValue *v86; // rcx
  char *v87; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v88; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v89; // rcx
  unsigned int *v90; // r12
  UFG::PersistentData::MapBinary **mpMapBinaries; // r15
  __int64 v92; // r13
  unsigned int v93; // ecx
  UFG::PersistentData::MapBinary *v94; // rsi
  UFG::PersistentData::KeyBinary *v95; // rcx
  unsigned int *v96; // rbx
  UFG::allocator::free_link *v97; // rax
  UFG::PersistentData::MapBinary *v98; // rax
  UFG::PersistentData::List *v99; // rdx
  UFG::PersistentData::List *v100; // rcx
  signed __int64 v101; // [rsp+30h] [rbp-58h]

  v5 = persistenceMask;
  v6 = filterMask;
  v9 = pRecentSnapshot;
  v10 = UFG::GameSnapshot::sDefinitionTimes;
  v11 = (char *)this - (char *)pRecentSnapshot;
  v12 = 30i64;
  do
  {
    v13 = *v10;
    if ( (*v10 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v13) == (_DWORD)v5 && (v13 & rejectMask) == 0 )
    {
      *(unsigned __int64 *)((char *)&v9->mTimes[0].mTimer.mTimestamp + v11) = v9->mTimes[0].mTimer.mTimestamp;
      *(_QWORD *)((char *)&v9->mTimes[0].mTimer.mElapsedTime + v11) = *(_QWORD *)&v9->mTimes[0].mTimer.mElapsedTime;
    }
    ++v10;
    v9 = (UFG::GameSnapshot *)((char *)v9 + 16);
    --v12;
  }
  while ( v12 );
  mIDs = pRecentSnapshot->mIDs;
  v15 = (char *)UFG::GameSnapshot::sDefinitionIDs - (char *)pRecentSnapshot;
  v16 = 44i64;
  do
  {
    v17 = *(unsigned int *)((char *)&mIDs[-120].mValue.mUID + v15);
    if ( (v17 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v17) == (_DWORD)v5 && (v17 & rejectMask) == 0 )
      *(UFG::PersistentData::ID *)((char *)mIDs + v11) = (UFG::PersistentData::ID)mIDs->mValue.mUID;
    ++mIDs;
    --v16;
  }
  while ( v16 );
  v18 = 0i64;
  v19 = 58i64;
  do
  {
    v20 = UFG::GameSnapshot::sDefinitionBools[v18];
    if ( (v20 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v20) == (_DWORD)v5 && (v20 & rejectMask) == 0 )
      this->mBools[v18].mValue = pRecentSnapshot->mBools[v18].mValue;
    ++v18;
    --v19;
  }
  while ( v19 );
  mInts = pRecentSnapshot->mInts;
  v22 = 163i64;
  do
  {
    v23 = *(int *)((char *)&mInts[-179].mValue + (char *)UFG::GameSnapshot::sDefinitionInts - (char *)pRecentSnapshot);
    if ( (v23 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v23) == (_DWORD)v5 && (v23 & rejectMask) == 0 )
      *(UFG::PersistentData::Int *)((char *)mInts + v11) = (UFG::PersistentData::Int)mInts->mValue;
    ++mInts;
    --v22;
  }
  while ( v22 );
  if ( (v6 & UFG::GameSnapshot::sDefinitionUInt64s[0]) != 0
    && (UFG::GameSnapshot::sDefinitionUInt64s[0] & v5) == v5
    && (rejectMask & UFG::GameSnapshot::sDefinitionUInt64s[0]) == 0 )
  {
    this->mUInt64s[0].mValue = pRecentSnapshot->mUInt64s[0].mValue;
  }
  mFloats = pRecentSnapshot->mFloats;
  v25 = 17i64;
  do
  {
    v26 = *(_DWORD *)((char *)&mFloats[-344].mValue
                    + (char *)UFG::GameSnapshot::sDefinitionFloats
                    - (char *)pRecentSnapshot);
    if ( (v26 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v26) == (_DWORD)v5 && (v26 & rejectMask) == 0 )
      *(UFG::PersistentData::Float *)((char *)mFloats + v11) = LODWORD(mFloats->mValue);
    v27 = *(_DWORD *)((char *)&mFloats[-344].mValue + (char *)&dword_1424059C4 - (char *)pRecentSnapshot);
    if ( (v27 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v27) == (_DWORD)v5 && (v27 & rejectMask) == 0 )
      *(UFG::PersistentData::Float *)((char *)mFloats + v11 + 4) = mFloats[1];
    v28 = *(_DWORD *)((char *)&mFloats[-344].mValue + (char *)&dword_1424059C8 - (char *)pRecentSnapshot);
    if ( (v28 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v28) == (_DWORD)v5 && (v28 & rejectMask) == 0 )
      *(UFG::PersistentData::Float *)((char *)mFloats + v11 + 8) = mFloats[2];
    v29 = *(_DWORD *)((char *)&mFloats[-344].mValue + (char *)&dword_1424059CC - (char *)pRecentSnapshot);
    if ( (v29 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v29) == (_DWORD)v5 && (v29 & rejectMask) == 0 )
      *(UFG::PersistentData::Float *)((char *)mFloats + v11 + 12) = mFloats[3];
    v30 = *(_DWORD *)((char *)&mFloats[-344].mValue + (char *)&dword_1424059D0 - (char *)pRecentSnapshot);
    if ( (v30 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v30) == (_DWORD)v5 && (v30 & rejectMask) == 0 )
      *(UFG::PersistentData::Float *)((char *)mFloats + v11 + 16) = mFloats[4];
    v31 = *(_DWORD *)((char *)&mFloats[-344].mValue + (char *)&dword_1424059D4 - (char *)pRecentSnapshot);
    if ( (v31 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v31) == (_DWORD)v5 && (v31 & rejectMask) == 0 )
      *(UFG::PersistentData::Float *)((char *)mFloats + v11 + 20) = mFloats[5];
    v32 = *(_DWORD *)((char *)&mFloats[-344].mValue + (char *)&dword_1424059D8 - (char *)pRecentSnapshot);
    if ( (v32 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v32) == (_DWORD)v5 && (v32 & rejectMask) == 0 )
      *(UFG::PersistentData::Float *)((char *)mFloats + v11 + 24) = mFloats[6];
    v33 = *(_DWORD *)((char *)&mFloats[-344].mValue + (char *)&dword_1424059DC - (char *)pRecentSnapshot);
    if ( (v33 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v33) == (_DWORD)v5 && (v33 & rejectMask) == 0 )
      *(UFG::PersistentData::Float *)((char *)mFloats + v11 + 28) = mFloats[7];
    mFloats += 8;
    --v25;
  }
  while ( v25 );
  v34 = &pRecentSnapshot->mFloats[136];
  v35 = 3i64;
  v36 = 3i64;
  do
  {
    v37 = *(_DWORD *)((char *)&v34[-480].mValue + (char *)&dword_142405BE0 - (char *)pRecentSnapshot);
    if ( (v37 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v37) == (_DWORD)v5 && (v37 & rejectMask) == 0 )
      *(UFG::PersistentData::Float *)((char *)v34 + v11) = LODWORD(v34->mValue);
    ++v34;
    --v36;
  }
  while ( v36 );
  v38 = UFG::GameSnapshot::sDefinitionIntsRanged;
  p_mRange = &this->mIntsRanged[0].mRange;
  v40 = (char *)pRecentSnapshot - (char *)this;
  v101 = (char *)pRecentSnapshot - (char *)this;
  v41 = 7i64;
  do
  {
    v42 = *v38;
    if ( (*v38 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v42) == (_DWORD)v5 && (v42 & rejectMask) == 0 )
    {
      *(p_mRange - 1) = *(int *)((char *)p_mRange + v40 - 4);
      *p_mRange = *(int *)((char *)p_mRange + v40);
    }
    ++v38;
    p_mRange += 2;
    --v41;
  }
  while ( v41 );
  if ( (UFG::GameSnapshot::sDefinitionFloatsRanged[0] & (unsigned int)v6) != 0
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionFloatsRanged[0]) == (_DWORD)v5
    && (UFG::GameSnapshot::sDefinitionFloatsRanged[0] & rejectMask) == 0 )
  {
    this->mFloatsRanged[0].mValue = pRecentSnapshot->mFloatsRanged[0].mValue;
    this->mFloatsRanged[0].mRange = pRecentSnapshot->mFloatsRanged[0].mRange;
  }
  v43 = UFG::GameSnapshot::sDefinitionStrings;
  p_mData = &pRecentSnapshot->mStrings[0].mValue.mData;
  mStrings = this->mStrings;
  v46 = 25i64;
  do
  {
    v47 = *v43;
    if ( (*v43 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v47) == (_DWORD)v5 && (v47 & rejectMask) == 0 )
      UFG::qString::Set(&mStrings->mValue, *p_mData, *((_DWORD *)p_mData - 1), 0i64, 0);
    ++mStrings;
    p_mData += 5;
    ++v43;
    --v46;
  }
  while ( v46 );
  v48 = UFG::GameSnapshot::sDefinitionBinaries;
  p_mSize = &this->mBinaries[0].mSize;
  do
  {
    v50 = *v48;
    if ( (*v48 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v50) == (_DWORD)v5 && (v50 & rejectMask) == 0 )
    {
      if ( *p_mSize )
        operator delete[](*((void **)p_mSize - 1));
      *((_QWORD *)p_mSize - 1) = 0i64;
      *p_mSize = 0;
      v51 = *(unsigned int *)((char *)p_mSize + v101);
      *p_mSize = v51;
      if ( v51 )
      {
        v52 = UFG::qMalloc(v51, "Binary", 0i64);
        UFG::qMemCopy(v52, *(const void **)((char *)p_mSize + v101 - 8), *p_mSize);
        *((_QWORD *)p_mSize - 1) = v52;
      }
      else
      {
        *((_QWORD *)p_mSize - 1) = 0i64;
      }
    }
    ++v48;
    p_mSize += 4;
    --v35;
  }
  while ( v35 );
  v53 = UFG::GameSnapshot::sDefinitionMapBools;
  mpMapBools = this->mpMapBools;
  v55 = 93i64;
  do
  {
    v56 = *v53;
    if ( (*v53 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v56) == (_DWORD)v5 && (v56 & rejectMask) == 0 )
    {
      v57 = *mpMapBools;
      if ( *mpMapBools )
      {
        UFG::PersistentData::MapBool::~MapBool(*mpMapBools);
        operator delete[](v57);
      }
      v58 = UFG::qMalloc(0x30ui64, "GameSnapshot", 0i64);
      if ( v58 )
      {
        v59 = *(__int64 *)((char *)mpMapBools + v101);
        LODWORD(v58->mNext) = *(_DWORD *)v59;
        v58[2].mNext = 0i64;
        v58[1].mNext = 0i64;
        v58[4].mNext = 0i64;
        v58[3].mNext = 0i64;
        LODWORD(v58[5].mNext) = *(_DWORD *)(v59 + 40);
        if ( LODWORD(v58->mNext) )
        {
          if ( (unsigned int)(LODWORD(v58->mNext) - 1) <= 1 )
            UFG::qArray<UFG::qSymbol,0>::Clone(
              (UFG::qArray<UFG::qSymbol,0> *)(v59 + 24),
              (UFG::qArray<UFG::qSymbol,0> *)&v58[3]);
        }
        else
        {
          UFG::qArray<UFG::PersistentData::KeyValue,0>::Clone(
            (UFG::qArray<UFG::PersistentData::KeyValue,0> *)(v59 + 8),
            (UFG::qArray<UFG::PersistentData::KeyValue,0> *)&v58[1]);
        }
      }
      else
      {
        v58 = 0i64;
      }
      *mpMapBools = (UFG::PersistentData::MapBool *)v58;
    }
    ++mpMapBools;
    ++v53;
    --v55;
  }
  while ( v55 );
  v60 = UFG::GameSnapshot::sDefinitionMapInts;
  mpMapInts = this->mpMapInts;
  v62 = 47i64;
  do
  {
    v63 = *v60;
    if ( (*v60 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v63) == (_DWORD)v5 && (v63 & rejectMask) == 0 )
    {
      v64 = *mpMapInts;
      if ( *mpMapInts )
      {
        p = v64->mValues.p;
        if ( p )
        {
          v66 = (char *)&p[-1].4;
          `eh vector destructor iterator(p, 8ui64, p[-1].mIntValue, (void (__fastcall *)(void *))_);
          operator delete[](v66);
        }
        v64->mValues.p = 0i64;
        *(_QWORD *)&v64->mValues.size = 0i64;
        v67 = v64->mValues.p;
        if ( v67 )
        {
          v68 = (char *)&v67[-1].4;
          `eh vector destructor iterator(v67, 8ui64, v67[-1].mIntValue, (void (__fastcall *)(void *))_);
          operator delete[](v68);
        }
        v64->mValues.p = 0i64;
        *(_QWORD *)&v64->mValues.size = 0i64;
        operator delete[](v64);
      }
      v69 = (UFG::qArray<UFG::PersistentData::KeyValue,0> *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
      if ( v69 )
      {
        v70 = *(UFG::qArray<UFG::PersistentData::KeyValue,0> **)((char *)mpMapInts + v101);
        v69->p = 0i64;
        *(_QWORD *)&v69->size = 0i64;
        v69[1].size = v70[1].size;
        UFG::qArray<UFG::PersistentData::KeyValue,0>::Clone(v70, v69);
      }
      else
      {
        v69 = 0i64;
      }
      *mpMapInts = (UFG::PersistentData::MapInt *)v69;
    }
    ++mpMapInts;
    ++v60;
    --v62;
  }
  while ( v62 );
  if ( (UFG::GameSnapshot::sDefinitionMapUInt64s[0] & (unsigned int)v6) != 0
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionMapUInt64s[0]) == (_DWORD)v5
    && (UFG::GameSnapshot::sDefinitionMapUInt64s[0] & rejectMask) == 0 )
  {
    v71 = this->mpMapUInt64s[0];
    if ( v71 )
    {
      v72 = v71->mValues.p;
      if ( v72 )
      {
        p_mIntValue = &v72[-1].mIntValue;
        `eh vector destructor iterator(v72, 0x10ui64, v72[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](p_mIntValue);
      }
      v71->mValues.p = 0i64;
      *(_QWORD *)&v71->mValues.size = 0i64;
      v74 = v71->mValues.p;
      if ( v74 )
      {
        v75 = &v74[-1].mIntValue;
        `eh vector destructor iterator(v74, 0x10ui64, v74[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v75);
      }
      v71->mValues.p = 0i64;
      *(_QWORD *)&v71->mValues.size = 0i64;
      operator delete[](v71);
    }
    v76 = (UFG::qArray<UFG::PersistentData::KeyValue64,0> *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    v77 = (UFG::PersistentData::MapUInt64 *)v76;
    if ( v76 )
    {
      v78 = pRecentSnapshot->mpMapUInt64s[0];
      v76->p = 0i64;
      *(_QWORD *)&v76->size = 0i64;
      v76[1].size = v78->mPersistentDataType;
      UFG::qArray<UFG::PersistentData::KeyValue64,0>::Clone(&v78->mValues, v76);
    }
    else
    {
      v77 = 0i64;
    }
    this->mpMapUInt64s[0] = v77;
  }
  v79 = UFG::GameSnapshot::sDefinitionMapFloats;
  mpMapFloats = this->mpMapFloats;
  v81 = 18i64;
  do
  {
    v82 = *v79;
    if ( (*v79 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v82) == (_DWORD)v5 && (v82 & rejectMask) == 0 )
    {
      v83 = *mpMapFloats;
      if ( *mpMapFloats )
      {
        v84 = v83->mValues.p;
        if ( v84 )
        {
          v85 = (char *)&v84[-1].4;
          `eh vector destructor iterator(v84, 8ui64, v84[-1].mIntValue, (void (__fastcall *)(void *))_);
          operator delete[](v85);
        }
        v83->mValues.p = 0i64;
        *(_QWORD *)&v83->mValues.size = 0i64;
        v86 = v83->mValues.p;
        if ( v86 )
        {
          v87 = (char *)&v86[-1].4;
          `eh vector destructor iterator(v86, 8ui64, v86[-1].mIntValue, (void (__fastcall *)(void *))_);
          operator delete[](v87);
        }
        v83->mValues.p = 0i64;
        *(_QWORD *)&v83->mValues.size = 0i64;
        operator delete[](v83);
      }
      v88 = (UFG::qArray<UFG::PersistentData::KeyValue,0> *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
      if ( v88 )
      {
        v89 = *(UFG::qArray<UFG::PersistentData::KeyValue,0> **)((char *)mpMapFloats + v101);
        v88->p = 0i64;
        *(_QWORD *)&v88->size = 0i64;
        v88[1].size = v89[1].size;
        UFG::qArray<UFG::PersistentData::KeyValue,0>::Clone(v89, v88);
      }
      else
      {
        v88 = 0i64;
      }
      *mpMapFloats = (UFG::PersistentData::MapFloat *)v88;
    }
    ++mpMapFloats;
    ++v79;
    --v81;
  }
  while ( v81 );
  v90 = UFG::GameSnapshot::sDefinitionMapBinaries;
  mpMapBinaries = this->mpMapBinaries;
  v92 = 2i64;
  do
  {
    v93 = *v90;
    if ( (*v90 & (unsigned int)v6) != 0 && ((unsigned int)v5 & v93) == (_DWORD)v5 && (v93 & rejectMask) == 0 )
    {
      v94 = *mpMapBinaries;
      if ( *mpMapBinaries )
      {
        UFG::PersistentData::MapBinary::Clear(v94);
        v95 = v94->mValues.p;
        if ( v95 )
        {
          v96 = &v95[-1].mBinary.mSize;
          `eh vector destructor iterator(v95, 0x18ui64, v95[-1].mBinary.mSize, (void (__fastcall *)(void *))_);
          operator delete[](v96);
        }
        v94->mValues.p = 0i64;
        *(_QWORD *)&v94->mValues.size = 0i64;
        operator delete[](v94);
      }
      v97 = UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
      if ( v97 )
        UFG::PersistentData::MapBinary::MapBinary(
          (UFG::PersistentData::MapBinary *)v97,
          *(UFG::PersistentData::MapBinary **)((char *)mpMapBinaries + v101));
      else
        v98 = 0i64;
      *mpMapBinaries = v98;
    }
    ++mpMapBinaries;
    ++v90;
    --v92;
  }
  while ( v92 );
  if ( (UFG::GameSnapshot::sDefinitionList[0] & (unsigned int)v6) != 0
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionList[0]) == (_DWORD)v5
    && (UFG::GameSnapshot::sDefinitionList[0] & rejectMask) == 0 )
  {
    v99 = this->mpList[0];
    v100 = pRecentSnapshot->mpList[0];
    v99->mType = v100->mType;
    switch ( v100->mType )
    {
      case LT_BOOL:
        UFG::qArray<bool,0>::Clone(v100->mBoolList, v99->mBoolList);
        break;
      case LT_INT:
        UFG::qArray<enum DNA::PropertyState::Enum,0>::Clone(
          (UFG::qArray<unsigned long,0> *)v100->mIntList,
          (UFG::qArray<unsigned long,0> *)v99->mIntList);
        break;
      case LT_INT64:
        UFG::qArray<UFG::qPropertySet *,0>::Clone(
          (UFG::qArray<UFG::RoadNetworkNode *,0> *)v100->mIntList,
          (UFG::qArray<UFG::RoadNetworkNode *,0> *)v99->mIntList);
        break;
      case LT_FLOAT:
        UFG::qArray<float,0>::Clone(v100->mFloatList, v99->mFloatList);
        break;
    }
  }
}

// File Line: 408
// RVA: 0x496160
__int64 __fastcall UFG::GameSnapshot::CalculateSerializeSize(
        UFG::GameSnapshot *this,
        unsigned int filterMask,
        unsigned int persistenceMask)
{
  unsigned __int64 v3; // r9
  unsigned int *v5; // r11
  __int64 v6; // rbx
  unsigned int v7; // ecx
  unsigned int v8; // r10d
  unsigned int v9; // ecx
  unsigned int v10; // r10d
  unsigned int *v11; // r11
  __int64 v12; // rbx
  int v13; // ecx
  int v14; // r10d
  unsigned int *v15; // r11
  __int64 v16; // rbx
  int v17; // ecx
  int v18; // r10d
  unsigned int *v19; // r11
  __int64 v20; // rbx
  int v21; // ecx
  int v22; // r10d
  unsigned int *v23; // r11
  __int64 v24; // rbx
  int v25; // ecx
  int v26; // r10d
  unsigned int *v27; // r11
  __int64 v28; // rbx
  int v29; // r11d
  int v30; // ebx
  unsigned int *v31; // r10
  int *p_mLength; // rcx
  __int64 v33; // rdi
  unsigned int v34; // eax
  int v35; // r11d
  int v36; // ebx
  unsigned int *v37; // rcx
  unsigned int *p_mSize; // r10
  __int64 v39; // rdi
  int v40; // r11d
  int v41; // ebx
  unsigned int *v42; // r10
  UFG::PersistentData::MapBool **mpMapBools; // rcx
  __int64 v44; // rdi
  UFG::PersistentData::MapBool *v45; // rax
  int v46; // eax
  int v47; // ebx
  __int64 v48; // rsi
  int v49; // edi
  unsigned int *v50; // r10
  UFG::PersistentData::MapInt **mpMapInts; // r11
  unsigned int v52; // ecx
  int v53; // ebx
  int v54; // edi
  unsigned int *v55; // r10
  UFG::PersistentData::MapFloat **mpMapFloats; // r11
  __int64 v57; // rsi
  int v58; // ebp
  __int64 v59; // r15
  __int64 v60; // r14
  int v61; // esi
  unsigned int *v62; // rbx
  UFG::PersistentData::MapBinary **mpMapBinaries; // rdi
  int v64; // r10d
  unsigned int size; // eax
  __int64 v66; // r11
  unsigned int *v67; // rcx
  unsigned int v68; // eax
  UFG::PersistentData::List *v69; // rax
  UFG::qArray<long,0> *mIntList; // r8
  UFG::PersistentData::ListType mType; // ecx
  unsigned int v72; // edx
  int v73; // ecx
  __int32 v74; // ecx
  int v75; // ecx
  int v76; // ecx
  __int64 v77; // r8
  unsigned int v78; // eax

  v3 = 0i64;
  v5 = UFG::GameSnapshot::sDefinitionTimes;
  v6 = 30i64;
  *(_QWORD *)UFG::GameSnapshot::sWriteSizes = 0i64;
  qword_142405F68 = 0i64;
  qword_142405F70 = 0i64;
  qword_142405F78 = 0i64;
  qword_142405F80 = 0i64;
  qword_142405F88 = 0i64;
  qword_142405F90 = 0i64;
  qword_142405F98 = 0i64;
  *(_QWORD *)UFG::GameSnapshot::sHeaderCounts = 0i64;
  qword_142405F28 = 0i64;
  qword_142405F30 = 0i64;
  qword_142405F38 = 0i64;
  qword_142405F40 = 0i64;
  qword_142405F48 = 0i64;
  qword_142405F50[0] = 0i64;
  qword_142405F58[0] = 0i64;
  v7 = 0;
  v8 = 0;
  do
  {
    if ( (*v5 & filterMask) != 0 && (persistenceMask & *v5) == persistenceMask )
    {
      v8 += 4;
      ++v7;
    }
    ++v5;
    --v6;
  }
  while ( v6 );
  UFG::GameSnapshot::sHeaderCounts[0] = v7;
  v9 = UFG::GameSnapshot::sHeaderCounts[1];
  UFG::GameSnapshot::sWriteSizes[0] = v8;
  v10 = UFG::GameSnapshot::sWriteSizes[1];
  v11 = UFG::GameSnapshot::sDefinitionIDs;
  v12 = 44i64;
  do
  {
    if ( (*v11 & filterMask) != 0 && (persistenceMask & *v11) == persistenceMask )
    {
      v10 += 4;
      ++v9;
    }
    ++v11;
    --v12;
  }
  while ( v12 );
  UFG::GameSnapshot::sHeaderCounts[1] = v9;
  v13 = qword_142405F28;
  UFG::GameSnapshot::sWriteSizes[1] = v10;
  v14 = qword_142405F68;
  v15 = UFG::GameSnapshot::sDefinitionBools;
  v16 = 58i64;
  do
  {
    if ( (*v15 & filterMask) != 0 && (persistenceMask & *v15) == persistenceMask )
    {
      v14 += 4;
      ++v13;
    }
    ++v15;
    --v16;
  }
  while ( v16 );
  LODWORD(qword_142405F28) = v13;
  v17 = HIDWORD(qword_142405F28);
  LODWORD(qword_142405F68) = v14;
  v18 = HIDWORD(qword_142405F68);
  v19 = UFG::GameSnapshot::sDefinitionInts;
  v20 = 163i64;
  do
  {
    if ( (*v19 & filterMask) != 0 && (persistenceMask & *v19) == persistenceMask )
    {
      v18 += 4;
      ++v17;
    }
    ++v19;
    --v20;
  }
  while ( v20 );
  HIDWORD(qword_142405F68) = v18;
  HIDWORD(qword_142405F28) = v17;
  if ( (filterMask & UFG::GameSnapshot::sDefinitionUInt64s[0]) != 0
    && (UFG::GameSnapshot::sDefinitionUInt64s[0] & persistenceMask) == (unsigned __int64)persistenceMask )
  {
    LODWORD(qword_142405F70) = qword_142405F70 + 8;
    LODWORD(qword_142405F30) = qword_142405F30 + 1;
  }
  v21 = HIDWORD(qword_142405F30);
  v22 = HIDWORD(qword_142405F70);
  v23 = UFG::GameSnapshot::sDefinitionFloats;
  v24 = 139i64;
  do
  {
    if ( (*v23 & filterMask) != 0 && (persistenceMask & *v23) == persistenceMask )
    {
      v22 += 4;
      ++v21;
    }
    ++v23;
    --v24;
  }
  while ( v24 );
  HIDWORD(qword_142405F30) = v21;
  v25 = qword_142405F38;
  HIDWORD(qword_142405F70) = v22;
  v26 = qword_142405F78;
  v27 = UFG::GameSnapshot::sDefinitionIntsRanged;
  v28 = 7i64;
  do
  {
    if ( (*v27 & filterMask) != 0 && (persistenceMask & *v27) == persistenceMask )
    {
      v26 += 8;
      ++v25;
    }
    ++v27;
    --v28;
  }
  while ( v28 );
  LODWORD(qword_142405F38) = v25;
  LODWORD(qword_142405F78) = v26;
  if ( (UFG::GameSnapshot::sDefinitionFloatsRanged[0] & filterMask) != 0
    && (persistenceMask & UFG::GameSnapshot::sDefinitionFloatsRanged[0]) == persistenceMask )
  {
    HIDWORD(qword_142405F78) += 8;
    ++HIDWORD(qword_142405F38);
  }
  v29 = qword_142405F40;
  v30 = qword_142405F80;
  v31 = UFG::GameSnapshot::sDefinitionStrings;
  p_mLength = &this->mStrings[0].mValue.mLength;
  v33 = 25i64;
  do
  {
    if ( (*v31 & filterMask) != 0 && (persistenceMask & *v31) == persistenceMask )
    {
      if ( *p_mLength <= 0 )
        v34 = 0;
      else
        v34 = (*p_mLength + 4) & 0xFFFFFFFC;
      v30 += v34 + 4;
      LODWORD(qword_142405F40) = ++v29;
      LODWORD(qword_142405F80) = v30;
    }
    p_mLength += 10;
    ++v31;
    --v33;
  }
  while ( v33 );
  v35 = HIDWORD(qword_142405F40);
  v36 = HIDWORD(qword_142405F80);
  v37 = UFG::GameSnapshot::sDefinitionBinaries;
  p_mSize = &this->mBinaries[0].mSize;
  v39 = 3i64;
  do
  {
    if ( (*v37 & filterMask) != 0 && (persistenceMask & *v37) == persistenceMask )
    {
      v36 += ((*p_mSize + 3) & 0xFFFFFFFC) + 4;
      HIDWORD(qword_142405F40) = ++v35;
      HIDWORD(qword_142405F80) = v36;
    }
    p_mSize += 4;
    ++v37;
    --v39;
  }
  while ( v39 );
  v40 = qword_142405F48;
  v41 = qword_142405F88;
  v42 = UFG::GameSnapshot::sDefinitionMapBools;
  mpMapBools = this->mpMapBools;
  v44 = 93i64;
  do
  {
    if ( (*v42 & filterMask) != 0 && (persistenceMask & *v42) == persistenceMask )
    {
      v45 = *mpMapBools;
      if ( (*mpMapBools)->mKeepType )
        v46 = 4 * v45->mNames.size + 8;
      else
        v46 = 8 * v45->mValues.size + 8;
      v41 += v46;
      LODWORD(qword_142405F48) = ++v40;
      LODWORD(qword_142405F88) = v41;
    }
    ++mpMapBools;
    ++v42;
    --v44;
  }
  while ( v44 );
  v47 = HIDWORD(qword_142405F48);
  v48 = 47i64;
  v49 = HIDWORD(qword_142405F88);
  v50 = UFG::GameSnapshot::sDefinitionMapInts;
  mpMapInts = this->mpMapInts;
  do
  {
    if ( (*v50 & filterMask) != 0 && (persistenceMask & *v50) == persistenceMask )
    {
      v49 += 8 * (*mpMapInts)->mValues.size + 4;
      HIDWORD(qword_142405F48) = ++v47;
      HIDWORD(qword_142405F88) = v49;
    }
    ++mpMapInts;
    ++v50;
    --v48;
  }
  while ( v48 );
  if ( (UFG::GameSnapshot::sDefinitionMapUInt64s[0] & filterMask) != 0
    && (persistenceMask & UFG::GameSnapshot::sDefinitionMapUInt64s[0]) == persistenceMask )
  {
    v52 = 16 * this->mpMapUInt64s[0]->mValues.size;
    ++LODWORD(qword_142405F50[0]);
    LODWORD(qword_142405F90) = qword_142405F90 + 8 + v52;
  }
  v53 = HIDWORD(qword_142405F50[0]);
  v54 = HIDWORD(qword_142405F90);
  v55 = UFG::GameSnapshot::sDefinitionMapFloats;
  mpMapFloats = this->mpMapFloats;
  v57 = 18i64;
  do
  {
    if ( (*v55 & filterMask) != 0 && (persistenceMask & *v55) == persistenceMask )
    {
      v54 += 8 * (*mpMapFloats)->mValues.size + 4;
      HIDWORD(qword_142405F50[0]) = ++v53;
      HIDWORD(qword_142405F90) = v54;
    }
    ++mpMapFloats;
    ++v55;
    --v57;
  }
  while ( v57 );
  v58 = qword_142405F98;
  v59 = 2i64;
  v60 = 4i64;
  v61 = qword_142405F58[0];
  v62 = UFG::GameSnapshot::sDefinitionMapBinaries;
  mpMapBinaries = this->mpMapBinaries;
  do
  {
    if ( (*v62 & filterMask) != 0 && (persistenceMask & *v62) == persistenceMask )
    {
      v64 = 4;
      size = (*mpMapBinaries)->mValues.size;
      if ( size )
      {
        v66 = size;
        v67 = &(*mpMapBinaries)->mValues.p->mBinary.mSize;
        do
        {
          v68 = *v67;
          v67 += 6;
          v64 += ((v68 + 3) & 0xFFFFFFFC) + 8;
          --v66;
        }
        while ( v66 );
      }
      v58 += v64;
      LODWORD(qword_142405F58[0]) = ++v61;
      LODWORD(qword_142405F98) = v58;
    }
    ++mpMapBinaries;
    ++v62;
    --v59;
  }
  while ( v59 );
  if ( (UFG::GameSnapshot::sDefinitionList[0] & filterMask) != 0
    && (persistenceMask & UFG::GameSnapshot::sDefinitionList[0]) == persistenceMask )
  {
    v69 = this->mpList[0];
    mIntList = v69->mIntList;
    if ( mIntList || (mType = v69->mType) != LT_NONE )
    {
      mType = v69->mType;
      if ( v69->mType == LT_BOOL || v69->mType == LT_INT || v69->mType == LT_INT64 || (v72 = 0, v69->mType == LT_FLOAT) )
        v72 = mIntList->size;
    }
    else
    {
      v72 = 0;
    }
    if ( mIntList || mType )
    {
      v74 = mType - 1;
      if ( !v74 )
        goto LABEL_98;
      v75 = v74 - 1;
      if ( !v75 )
        goto LABEL_98;
      v76 = v75 - 1;
      if ( !v76 )
      {
        v73 = 8;
        goto LABEL_99;
      }
      if ( v76 == 1 )
      {
LABEL_98:
        v73 = 4;
        goto LABEL_99;
      }
      v73 = 0;
    }
    else
    {
      v73 = 0;
    }
LABEL_99:
    ++HIDWORD(qword_142405F58[0]);
    HIDWORD(qword_142405F98) += 8 + v72 * v73;
  }
  LODWORD(v77) = 64;
  do
  {
    v78 = UFG::GameSnapshot::sHeaderCounts[v3 / 4];
    v3 += 16i64;
    v77 = LODWORD(qword_142405F50[v3 / 8])
        + HIDWORD(qword_142405F50[v3 / 8])
        + LODWORD(qword_142405F58[v3 / 8])
        + HIDWORD(qword_142405F58[v3 / 8])
        + 40
        * (*(_DWORD *)((char *)&UFG::ProgressionTracker::mspInstance + v3)
         + *(_DWORD *)((char *)&UFG::ProgressionTracker::mspInstance + v3 + 4)
         + dword_142405F14[v3 / 4]
         + v78)
        + (_DWORD)v77
        + 16;
    --v60;
  }
  while ( v60 );
  return v77 + 4;
}

// File Line: 509
// RVA: 0x4BA980
char __fastcall UFG::GameSnapshot::SerializeByFilter(
        UFG::GameSnapshot *this,
        unsigned int filterMask,
        unsigned int persistenceMask,
        char **ppBuffer)
{
  __int64 v5; // rsi
  UFG::GameSnapshot *v6; // r15
  int v7; // r8d
  int v8; // r9d
  int v9; // r10d
  int v10; // r11d
  unsigned int *v11; // rax
  __int64 v12; // rcx
  int v13; // r9d
  __int64 v14; // rdx
  __int64 v15; // r10
  unsigned int *v16; // r8
  unsigned int v17; // r10d
  __int64 *v18; // r11
  void *v19; // r9
  unsigned int v20; // edx
  __int64 v21; // rax
  __int64 v22; // rax
  UFG::qSymbol **v23; // r14
  unsigned int *v24; // rbx
  __int64 v25; // r12
  unsigned int v26; // r13d
  int v27; // r8d
  __int64 v28; // rdx
  _BYTE *v29; // r8
  __int64 v30; // rax
  signed __int64 *v31; // rax
  signed __int64 v32; // r8
  UFG::qSymbol **v33; // r10
  unsigned int *v34; // r9
  __int64 v35; // r14
  __int64 v36; // r11
  __int64 v37; // r15
  unsigned int v38; // ebx
  __int64 v39; // rdx
  _BYTE *v40; // r8
  signed __int64 *v41; // rax
  signed __int64 v42; // r8
  __int64 v43; // r9
  __int64 v44; // r10
  __int64 v45; // rbx
  unsigned int v46; // r11d
  __int64 v47; // r13
  unsigned int v48; // eax
  __int64 v49; // rdx
  _BYTE *v50; // r8
  signed __int64 *v51; // rax
  signed __int64 v52; // r8
  UFG::qSymbol **v53; // r10
  unsigned int *v54; // r9
  __int64 v55; // r11
  __int64 v56; // r15
  unsigned int v57; // ebx
  __int64 v58; // rdx
  _BYTE *v59; // r8
  signed __int64 *v60; // rax
  signed __int64 v61; // r8
  __int64 v62; // rdx
  _BYTE *v63; // r9
  signed __int64 *v64; // rax
  signed __int64 v65; // r9
  UFG::qSymbol **v66; // r15
  unsigned int *v67; // rbx
  char *v68; // r14
  __int64 v69; // r12
  unsigned int v70; // r13d
  __int64 v71; // rdx
  char *v72; // r8
  void *v73; // rax
  __int64 v74; // rax
  unsigned int *v75; // r10
  __int64 v76; // r13
  _DWORD *v77; // r9
  char *v78; // r15
  __int64 v79; // r11
  __int64 v80; // r14
  unsigned int v81; // ebx
  __int64 v82; // rdx
  char *v83; // r8
  __int64 v84; // rax
  __int64 v85; // r8
  __int64 v86; // rdx
  _BYTE *v87; // r9
  signed __int64 *v88; // rax
  signed __int64 v89; // r9
  UFG::qSymbol **v90; // r12
  unsigned int *v91; // r15
  __int64 v92; // r14
  __int64 v93; // r13
  unsigned int v94; // ecx
  _BYTE *v95; // r8
  __int64 v96; // rax
  signed __int64 *v97; // rax
  signed __int64 v98; // r8
  unsigned int v99; // ebx
  UFG::qSymbol **v100; // r12
  unsigned int *v101; // r14
  unsigned int *v102; // rbx
  __int64 v103; // r13
  unsigned int v104; // ecx
  _BYTE *v105; // r8
  __int64 v106; // rax
  signed __int64 *v107; // rax
  signed __int64 v108; // r8
  unsigned int v109; // r8d
  unsigned int v110; // r15d
  UFG::qSymbol **v111; // r14
  unsigned int *v112; // r15
  __int64 v113; // r9
  __int64 v114; // r12
  unsigned int v115; // r13d
  __int64 v116; // rdx
  _BYTE *v117; // r8
  __int64 v118; // rax
  signed __int64 *v119; // rax
  signed __int64 v120; // r8
  __int64 v121; // rdx
  _DWORD *v122; // rcx
  unsigned int v123; // ebx
  const void *v124; // rdx
  UFG::qSymbol **v125; // r14
  unsigned int *v126; // r15
  __int64 v127; // r9
  __int64 v128; // r12
  unsigned int v129; // r13d
  __int64 v130; // rdx
  _BYTE *v131; // r8
  __int64 v132; // rax
  signed __int64 *v133; // rax
  signed __int64 v134; // r8
  __int64 v135; // rdx
  unsigned int v136; // ebx
  __int64 v137; // r8
  __int64 v138; // rdx
  _BYTE *v139; // r9
  signed __int64 *v140; // rax
  signed __int64 v141; // r9
  unsigned int *v142; // rdx
  unsigned int v143; // ebx
  UFG::qSymbol **v144; // r14
  unsigned int *v145; // r15
  __int64 v146; // r9
  __int64 v147; // r12
  unsigned int v148; // r13d
  __int64 v149; // rdx
  _BYTE *v150; // r8
  __int64 v151; // rax
  signed __int64 *v152; // rax
  signed __int64 v153; // r8
  __int64 v154; // rdx
  unsigned int v155; // ebx
  UFG::qSymbol **v156; // rbx
  unsigned int *v157; // r14
  __int64 v158; // r13
  __int64 v159; // r15
  unsigned int v160; // r12d
  __int64 v161; // rdx
  _BYTE *v162; // r8
  __int64 v163; // rax
  signed __int64 *v164; // rax
  signed __int64 v165; // r8
  __int64 v166; // r8
  __int64 v167; // rdx
  _BYTE *v168; // r9
  signed __int64 *v169; // rax
  signed __int64 v170; // r9
  __int64 v172; // [rsp+48h] [rbp-80h] BYREF
  __int64 v173; // [rsp+50h] [rbp-78h]
  __int64 v174; // [rsp+58h] [rbp-70h]
  __int64 v175; // [rsp+60h] [rbp-68h]
  __int64 v176; // [rsp+68h] [rbp-60h]
  void *data; // [rsp+70h] [rbp-58h]
  __int64 v178; // [rsp+78h] [rbp-50h]
  __int64 v179; // [rsp+80h] [rbp-48h]
  __int64 v180; // [rsp+88h] [rbp-40h]
  __int64 v181; // [rsp+90h] [rbp-38h]
  __int64 v182; // [rsp+98h] [rbp-30h]
  __int64 v183; // [rsp+A0h] [rbp-28h]
  __int64 v184; // [rsp+A8h] [rbp-20h]
  __int64 v185; // [rsp+B0h] [rbp-18h]
  __int64 v186; // [rsp+B8h] [rbp-10h]
  __int64 v187; // [rsp+C0h] [rbp-8h]
  __int64 v188; // [rsp+C8h] [rbp+0h]
  __int64 v189; // [rsp+D0h] [rbp+8h]
  __int64 v190; // [rsp+118h] [rbp+50h]
  int v191; // [rsp+120h] [rbp+58h]
  __int64 source; // [rsp+130h] [rbp+68h] BYREF

  v188 = -2i64;
  v5 = persistenceMask;
  v6 = this;
  data = *ppBuffer;
  UFG::GameSnapshot::CalculateSerializeSize(this, filterMask, persistenceMask);
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = &UFG::GameSnapshot::sHeaderCounts[1];
  v12 = 4i64;
  do
  {
    v7 += *(v11 - 1);
    v10 += *v11;
    v9 += v11[1];
    v8 += v11[2];
    v11 += 4;
    --v12;
  }
  while ( v12 );
  v13 = 40 * (v10 + v8 + v9 + v7) + 128;
  v172 = 0i64;
  v173 = 0i64;
  v174 = 0i64;
  v175 = 0i64;
  v176 = 0i64;
  v14 = 0i64;
  v15 = 16i64;
  v16 = UFG::GameSnapshot::sHeaderCounts;
  do
  {
    v13 += UFG::GameSnapshot::sWriteSizes[v14];
    *(_DWORD *)*ppBuffer = UFG::GameSnapshot::sHeaderCounts[v14];
    *ppBuffer += 4;
    *(_DWORD *)*ppBuffer = v13;
    *ppBuffer += 4;
    ++v14;
    --v15;
  }
  while ( v15 );
  v17 = 0;
  v18 = &v172;
  do
  {
    v19 = *ppBuffer;
    *v18 = (__int64)*ppBuffer;
    v20 = 0;
    LODWORD(source) = 0;
    v21 = *v16;
    if ( (_DWORD)v21 )
    {
      do
      {
        v22 = (__int64)v19 + 40 * v20;
        v189 = v22;
        if ( v22 )
        {
          *(_QWORD *)v22 = 0i64;
          *(_QWORD *)(v22 + 8) = 0i64;
          *(_QWORD *)(v22 + 16) = 0i64;
          *(_DWORD *)(v22 + 24) = -1;
          *(_QWORD *)(v22 + 32) = 0i64;
        }
        LODWORD(source) = ++v20;
        v21 = *v16;
      }
      while ( v20 < (unsigned int)v21 );
    }
    *ppBuffer += 40 * v21;
    ++v17;
    ++v18;
    ++v16;
  }
  while ( v17 < 0x10 );
  v23 = TimeSymbols;
  v24 = UFG::GameSnapshot::sDefinitionTimes;
  v25 = 30i64;
  v26 = 0;
  v27 = v191;
  do
  {
    if ( (*v24 & v27) != 0 && ((unsigned int)v5 & *v24) == (_DWORD)v5 )
    {
      v28 = 5i64 * v26++;
      v29 = *ppBuffer;
      v30 = v172;
      *(UFG::qSymbol *)(v172 + 8 * v28 + 24) = (UFG::qSymbol)(*v23)->mUID;
      v31 = (signed __int64 *)(v30 + 8 * v28 + 32);
      if ( v29 )
        v32 = v29 - (_BYTE *)v31;
      else
        v32 = 0i64;
      *v31 = v32;
      LODWORD(source) = UFG::SimpleTimer::GetElapsedSeconds((UFG::SimpleTimer *)v6);
      UFG::qMemCopy(*ppBuffer, &source, 4u);
      *ppBuffer += 4;
      v27 = v191;
    }
    v6 = (UFG::GameSnapshot *)((char *)v6 + 16);
    ++v24;
    ++v23;
    --v25;
  }
  while ( v25 );
  v33 = IDSymbols;
  v34 = UFG::GameSnapshot::sDefinitionIDs;
  v35 = v190 - (_QWORD)UFG::GameSnapshot::sDefinitionIDs;
  v36 = 44i64;
  v37 = v173;
  v38 = 0;
  do
  {
    if ( (*v34 & v27) != 0 && ((unsigned int)v5 & *v34) == (_DWORD)v5 )
    {
      v39 = 5i64 * v38++;
      v40 = *ppBuffer;
      *(UFG::qSymbol *)(v37 + 8 * v39 + 24) = (UFG::qSymbol)(*v33)->mUID;
      v41 = (signed __int64 *)(v37 + 32 + 8 * v39);
      if ( v40 )
        v42 = v40 - (_BYTE *)v41;
      else
        v42 = 0i64;
      *v41 = v42;
      *(_DWORD *)*ppBuffer = *(unsigned int *)((char *)v34 + v35 + 480);
      *ppBuffer += 4;
      v27 = v191;
    }
    ++v34;
    ++v33;
    --v36;
  }
  while ( v36 );
  v43 = 0i64;
  v44 = 58i64;
  v45 = v174;
  v46 = 0;
  v47 = v190;
  do
  {
    v48 = UFG::GameSnapshot::sDefinitionBools[v43];
    if ( (v48 & v27) != 0 && ((unsigned int)v5 & v48) == (_DWORD)v5 )
    {
      v49 = 5i64 * v46++;
      v50 = *ppBuffer;
      *(UFG::qSymbol *)(v45 + 8 * v49 + 24) = (UFG::qSymbol)BoolSymbols[v43]->mUID;
      v51 = (signed __int64 *)(v45 + 32 + 8 * v49);
      if ( v50 )
        v52 = v50 - (_BYTE *)v51;
      else
        v52 = 0i64;
      *v51 = v52;
      *(_DWORD *)*ppBuffer = *(unsigned __int8 *)(v43 + v47 + 656);
      *ppBuffer += 4;
      v27 = v191;
    }
    ++v43;
    --v44;
  }
  while ( v44 );
  v53 = Int32Symbols;
  v54 = UFG::GameSnapshot::sDefinitionInts;
  v55 = 163i64;
  v56 = v175;
  v57 = 0;
  do
  {
    if ( (*v54 & v27) != 0 && ((unsigned int)v5 & *v54) == (_DWORD)v5 )
    {
      v58 = 5i64 * v57++;
      v59 = *ppBuffer;
      *(UFG::qSymbol *)(v56 + 8 * v58 + 24) = (UFG::qSymbol)(*v53)->mUID;
      v60 = (signed __int64 *)(v56 + 32 + 8 * v58);
      if ( v59 )
        v61 = v59 - (_BYTE *)v60;
      else
        v61 = 0i64;
      *v60 = v61;
      *(_DWORD *)*ppBuffer = *(unsigned int *)((char *)v54 + v47 - (_QWORD)UFG::GameSnapshot::sDefinitionInts + 716);
      *ppBuffer += 4;
      v27 = v191;
    }
    ++v54;
    ++v53;
    --v55;
  }
  while ( v55 );
  if ( (v27 & UFG::GameSnapshot::sDefinitionUInt64s[0]) != 0 && (UFG::GameSnapshot::sDefinitionUInt64s[0] & v5) == v5 )
  {
    v62 = v176;
    v63 = *ppBuffer;
    *(_DWORD *)(v176 + 24) = UInt64Symbols[0]->mUID;
    v64 = (signed __int64 *)(v62 + 32);
    if ( v63 )
      v65 = v63 - (_BYTE *)v64;
    else
      v65 = 0i64;
    *v64 = v65;
    *(_QWORD *)*ppBuffer = *(_QWORD *)(v47 + 1368);
    *ppBuffer += 8;
    v27 = v191;
  }
  v66 = FloatSymbols;
  v67 = UFG::GameSnapshot::sDefinitionFloats;
  v68 = (char *)(v47 + 1376);
  v69 = 139i64;
  v70 = 0;
  do
  {
    if ( (*v67 & v27) != 0 && ((unsigned int)v5 & *v67) == (_DWORD)v5 )
    {
      v71 = 5i64 * v70++;
      v72 = *ppBuffer;
      v73 = data;
      *((UFG::qSymbol *)data + 2 * v71 + 6) = (UFG::qSymbol)(*v66)->mUID;
      v74 = (__int64)v73 + 8 * v71 + 32;
      if ( v72 )
        v72 -= v74;
      *(_QWORD *)v74 = v72;
      UFG::qMemCopy(*ppBuffer, v68, 4u);
      *ppBuffer += 4;
      v27 = v191;
    }
    v68 += 4;
    ++v67;
    ++v66;
    --v69;
  }
  while ( v69 );
  v75 = UFG::GameSnapshot::sDefinitionIntsRanged;
  v76 = v190;
  v77 = (_DWORD *)(v190 + 1932);
  v78 = (char *)Int32RangedSymbols - v190;
  v79 = 7i64;
  v80 = v178;
  v81 = v172;
  do
  {
    if ( (*v75 & v27) != 0 && ((unsigned int)v5 & *v75) == (_DWORD)v5 )
    {
      v82 = 5i64 * v81++;
      v83 = *ppBuffer;
      *(_DWORD *)(v80 + 8 * v82 + 24) = **(_DWORD **)((char *)v77 + (_QWORD)v78 - 1932);
      v84 = v80 + 32 + 8 * v82;
      if ( v83 )
        v83 -= v84;
      *(_QWORD *)v84 = v83;
      *(_DWORD *)*ppBuffer = *v77;
      *ppBuffer += 4;
      *(_DWORD *)*ppBuffer = v77[1];
      *ppBuffer += 4;
      v27 = v191;
    }
    ++v75;
    v77 += 2;
    --v79;
  }
  while ( v79 );
  if ( (UFG::GameSnapshot::sDefinitionFloatsRanged[0] & v27) != 0
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionFloatsRanged[0]) == (_DWORD)v5 )
  {
    v85 = 5i64 * HIDWORD(v172);
    v86 = v179;
    v87 = *ppBuffer;
    *(_DWORD *)(v179 + 8 * v85 + 24) = FloatRangedSymbols[0]->mUID;
    v88 = (signed __int64 *)(v86 + 32 + 8 * v85);
    if ( v87 )
      v89 = v87 - (_BYTE *)v88;
    else
      v89 = 0i64;
    *v88 = v89;
    UFG::qMemCopy(*ppBuffer, (const void *)(v76 + 1988), 4u);
    *ppBuffer += 4;
    UFG::qMemCopy(*ppBuffer, (const void *)(v76 + 1992), 4u);
    *ppBuffer += 4;
    v27 = v191;
  }
  v90 = StringSymbols;
  v91 = UFG::GameSnapshot::sDefinitionStrings;
  v92 = v76 + 2020;
  v93 = 25i64;
  v94 = v173;
  do
  {
    if ( (*v91 & v27) != 0 && ((unsigned int)v5 & *v91) == (_DWORD)v5 )
    {
      LODWORD(source) = v94 + 1;
      v95 = *ppBuffer;
      v96 = v180;
      *(UFG::qSymbol *)(v180 + 40i64 * v94 + 24) = (UFG::qSymbol)(*v90)->mUID;
      v97 = (signed __int64 *)(v96 + 40i64 * v94 + 32);
      if ( v95 )
        v98 = v95 - (_BYTE *)v97;
      else
        v98 = 0i64;
      *v97 = v98;
      if ( *(int *)v92 <= 0 )
        v99 = 0;
      else
        v99 = (*(_DWORD *)v92 + 4) & 0xFFFFFFFC;
      *(_DWORD *)*ppBuffer = v99;
      *ppBuffer += 4;
      if ( v99 )
      {
        UFG::qMemCopy(*ppBuffer, *(const void **)(v92 + 4), v99);
        *ppBuffer += v99;
      }
      v27 = v191;
      v94 = source;
    }
    v92 += 40i64;
    ++v91;
    ++v90;
    --v93;
  }
  while ( v93 );
  v100 = BinarySymbols;
  v101 = UFG::GameSnapshot::sDefinitionBinaries;
  v102 = (unsigned int *)(v190 + 3008);
  v103 = 3i64;
  v104 = HIDWORD(v173);
  do
  {
    if ( (*v101 & v27) != 0 && ((unsigned int)v5 & *v101) == (_DWORD)v5 )
    {
      LODWORD(source) = v104 + 1;
      v105 = *ppBuffer;
      v106 = v181;
      *(UFG::qSymbol *)(v181 + 40i64 * v104 + 24) = (UFG::qSymbol)(*v100)->mUID;
      v107 = (signed __int64 *)(v106 + 40i64 * v104 + 32);
      if ( v105 )
        v108 = v105 - (_BYTE *)v107;
      else
        v108 = 0i64;
      *v107 = v108;
      v109 = *v102;
      v110 = (*v102 + 3) & 0xFFFFFFFC;
      *(_DWORD *)*ppBuffer = *v102;
      *ppBuffer += 4;
      if ( v109 )
      {
        UFG::qMemCopy(*ppBuffer, *((const void **)v102 - 1), v109);
        *ppBuffer += v110;
      }
      v27 = v191;
      v104 = source;
    }
    ++v101;
    ++v100;
    v102 += 4;
    --v103;
  }
  while ( v103 );
  v111 = MapBoolSymbols;
  v112 = UFG::GameSnapshot::sDefinitionMapBools;
  v113 = v190 - (_QWORD)MapBoolSymbols;
  source = v190 - (_QWORD)MapBoolSymbols;
  v114 = 93i64;
  v115 = v174;
  do
  {
    if ( (*v112 & v27) != 0 && ((unsigned int)v5 & *v112) == (_DWORD)v5 )
    {
      v116 = 5i64 * v115++;
      v117 = *ppBuffer;
      v118 = v182;
      *(UFG::qSymbol *)(v182 + 8 * v116 + 24) = (UFG::qSymbol)(*v111)->mUID;
      v119 = (signed __int64 *)(v118 + 8 * v116 + 32);
      if ( v117 )
        v120 = v117 - (_BYTE *)v119;
      else
        v120 = 0i64;
      *v119 = v120;
      v121 = *(__int64 *)((char *)v111 + v113 + 3048);
      *(_DWORD *)*ppBuffer = *(_DWORD *)v121;
      *ppBuffer += 4;
      v122 = *ppBuffer;
      if ( *(_DWORD *)v121 )
      {
        *v122 = *(_DWORD *)(v121 + 24);
        *ppBuffer += 4;
        v123 = 4 * *(_DWORD *)(v121 + 24);
        v124 = *(const void **)(v121 + 32);
      }
      else
      {
        *v122 = *(_DWORD *)(v121 + 8);
        *ppBuffer += 4;
        v123 = 8 * *(_DWORD *)(v121 + 8);
        v124 = *(const void **)(v121 + 16);
      }
      UFG::qMemCopy(*ppBuffer, v124, v123);
      v27 = v191;
      v113 = source;
      *ppBuffer += v123;
    }
    ++v112;
    ++v111;
    --v114;
  }
  while ( v114 );
  v125 = MapInt32Symbols;
  v126 = UFG::GameSnapshot::sDefinitionMapInts;
  v127 = v190 - (_QWORD)MapInt32Symbols;
  source = v190 - (_QWORD)MapInt32Symbols;
  v128 = 47i64;
  v129 = HIDWORD(v174);
  do
  {
    if ( (*v126 & v27) != 0 && ((unsigned int)v5 & *v126) == (_DWORD)v5 )
    {
      v130 = 5i64 * v129++;
      v131 = *ppBuffer;
      v132 = v183;
      *(UFG::qSymbol *)(v183 + 8 * v130 + 24) = (UFG::qSymbol)(*v125)->mUID;
      v133 = (signed __int64 *)(v132 + 8 * v130 + 32);
      if ( v131 )
        v134 = v131 - (_BYTE *)v133;
      else
        v134 = 0i64;
      *v133 = v134;
      v135 = *(__int64 *)((char *)v125 + v127 + 3792);
      *(_DWORD *)*ppBuffer = *(_DWORD *)v135;
      *ppBuffer += 4;
      v136 = 8 * *(_DWORD *)v135;
      UFG::qMemCopy(*ppBuffer, *(const void **)(v135 + 8), v136);
      *ppBuffer += v136;
      v127 = source;
      v27 = v191;
    }
    ++v126;
    ++v125;
    --v128;
  }
  while ( v128 );
  if ( (UFG::GameSnapshot::sDefinitionMapUInt64s[0] & v27) != 0
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionMapUInt64s[0]) == (_DWORD)v5 )
  {
    v137 = 5i64 * (unsigned int)v175;
    v138 = v184;
    v139 = *ppBuffer;
    *(_DWORD *)(v184 + 8 * v137 + 24) = MapUInt64Symbols[0]->mUID;
    v140 = (signed __int64 *)(v138 + 32 + 8 * v137);
    if ( v139 )
      v141 = v139 - (_BYTE *)v140;
    else
      v141 = 0i64;
    *v140 = v141;
    v142 = *(unsigned int **)(v190 + 4168);
    *(_QWORD *)*ppBuffer = *v142;
    *ppBuffer += 8;
    v143 = 16 * *v142;
    UFG::qMemCopy(*ppBuffer, *((const void **)v142 + 1), v143);
    *ppBuffer += v143;
    v27 = v191;
  }
  v144 = MapFloatSymbols;
  v145 = UFG::GameSnapshot::sDefinitionMapFloats;
  v146 = v190 - (_QWORD)MapFloatSymbols;
  source = v190 - (_QWORD)MapFloatSymbols;
  v147 = 18i64;
  v148 = HIDWORD(v175);
  do
  {
    if ( (*v145 & v27) != 0 && ((unsigned int)v5 & *v145) == (_DWORD)v5 )
    {
      v149 = 5i64 * v148++;
      v150 = *ppBuffer;
      v151 = v185;
      *(UFG::qSymbol *)(v185 + 8 * v149 + 24) = (UFG::qSymbol)(*v144)->mUID;
      v152 = (signed __int64 *)(v151 + 8 * v149 + 32);
      if ( v150 )
        v153 = v150 - (_BYTE *)v152;
      else
        v153 = 0i64;
      *v152 = v153;
      v154 = *(__int64 *)((char *)v144 + v146 + 4176);
      *(_DWORD *)*ppBuffer = *(_DWORD *)v154;
      *ppBuffer += 4;
      v155 = 8 * *(_DWORD *)v154;
      UFG::qMemCopy(*ppBuffer, *(const void **)(v154 + 8), v155);
      *ppBuffer += v155;
      v146 = source;
      v27 = v191;
    }
    ++v145;
    ++v144;
    --v147;
  }
  while ( v147 );
  v156 = MapBinarySymbols;
  v157 = UFG::GameSnapshot::sDefinitionMapBinaries;
  v158 = v190 - (_QWORD)MapBinarySymbols;
  v159 = 2i64;
  v160 = v176;
  do
  {
    if ( (*v157 & v27) != 0 && ((unsigned int)v5 & *v157) == (_DWORD)v5 )
    {
      v161 = 5i64 * v160++;
      v162 = *ppBuffer;
      v163 = v186;
      *(UFG::qSymbol *)(v186 + 8 * v161 + 24) = (UFG::qSymbol)(*v156)->mUID;
      v164 = (signed __int64 *)(v163 + 8 * v161 + 32);
      if ( v162 )
        v165 = v162 - (_BYTE *)v164;
      else
        v165 = 0i64;
      *v164 = v165;
      UFG::PersistentData::MapBinary::Serialize(
        *(UFG::PersistentData::MapBinary **)((char *)v156 + v158 + 4320),
        ppBuffer);
      v27 = v191;
    }
    ++v157;
    ++v156;
    --v159;
  }
  while ( v159 );
  if ( (UFG::GameSnapshot::sDefinitionList[0] & v27) != 0
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionList[0]) == (_DWORD)v5 )
  {
    v166 = 5i64 * HIDWORD(v176);
    v167 = v187;
    v168 = *ppBuffer;
    *(_DWORD *)(v187 + 8 * v166 + 24) = ListSymbols[0]->mUID;
    v169 = (signed __int64 *)(v167 + 32 + 8 * v166);
    if ( v168 )
      v170 = v168 - (_BYTE *)v169;
    else
      v170 = 0i64;
    *v169 = v170;
    UFG::PersistentData::List::Serialize(*(UFG::PersistentData::List **)(v190 + 4336), ppBuffer);
  }
  *(_DWORD *)*ppBuffer = UFG::qDataHash32((char *)data, (unsigned int)(*(_DWORD *)ppBuffer - (_DWORD)data), 0xFFFFFFFF);
  *ppBuffer += 4;
  return 1;
}

// File Line: 680
// RVA: 0x49B900
char __fastcall UFG::GameSnapshot::DeserializeByFilter(
        UFG::GameSnapshot *this,
        unsigned int filterMask,
        unsigned int persistenceMask,
        char *pBuffer)
{
  char *v4; // rdi
  __int64 v5; // r12
  unsigned int mUID; // r14d
  char *v7; // rsi
  unsigned int v8; // edx
  __int64 v9; // rcx
  unsigned int v10; // eax
  unsigned int v11; // r13d
  __int64 v12; // r15
  unsigned int v13; // ebx
  UFG::qBaseTreeRB *v14; // rcx
  char *v15; // r14
  __int64 v16; // rax
  unsigned int **v17; // r15
  unsigned int *v18; // r13
  UFG::SimpleTimer *v19; // r14
  __int64 v20; // rbx
  int v21; // r8d
  UFG::qSymbolUC *v22; // rdi
  unsigned int v23; // edx
  UFG::qBaseTreeRB *v24; // rax
  UFG::qBaseNodeRB *mParent; // rcx
  char *v26; // rdx
  UFG::qSymbolUC v27; // ebx
  char *v28; // rax
  unsigned int **v29; // r15
  unsigned int *v30; // r14
  signed __int64 v31; // rbx
  __int64 v32; // r13
  UFG::qSymbolUC *v33; // rdi
  unsigned int v34; // edx
  UFG::qBaseTreeRB *v35; // rax
  UFG::qBaseNodeRB *v36; // rcx
  unsigned int *v37; // rdx
  UFG::qSymbolUC v38; // ebx
  char *v39; // rax
  __int64 v40; // rdi
  __int64 v41; // r15
  unsigned int v42; // eax
  UFG::qSymbolUC *v43; // r14
  UFG::qBaseTreeRB *v44; // rax
  UFG::qBaseNodeRB *v45; // rcx
  _DWORD *v46; // rcx
  bool v47; // al
  UFG::SimpleTimer *v48; // rcx
  UFG::qSymbolUC v49; // ebx
  char *v50; // rax
  unsigned int **v51; // r15
  unsigned int *v52; // rdi
  __int64 v53; // rbx
  __int64 v54; // r13
  UFG::qSymbolUC *v55; // r14
  unsigned int v56; // edx
  UFG::qBaseTreeRB *v57; // rax
  UFG::qBaseNodeRB *v58; // rcx
  unsigned int *v59; // rcx
  UFG::qSymbolUC v60; // ebx
  char *v61; // rax
  UFG::qSymbolUC *v62; // rdi
  UFG::qBaseTreeRB *v63; // rax
  UFG::qBaseNodeRB *v64; // rcx
  _QWORD *v65; // rax
  UFG::qSymbolUC v66; // ebx
  char *v67; // rax
  unsigned int **v68; // r14
  unsigned int *v69; // r15
  UFG::SimpleTimer *v70; // r13
  __int64 v71; // rbx
  UFG::qSymbolUC *v72; // rdi
  unsigned int v73; // edx
  UFG::qBaseTreeRB *v74; // rax
  UFG::qBaseNodeRB *v75; // rcx
  char *v76; // rdx
  UFG::qSymbolUC v77; // ebx
  char *v78; // rax
  unsigned int *v79; // r15
  bool *p_mIsStarted; // rdi
  signed __int64 v81; // rcx
  __int64 v82; // r13
  UFG::qSymbolUC *v83; // r14
  UFG::qBaseTreeRB *v84; // rax
  UFG::qBaseNodeRB *v85; // rcx
  _DWORD *v86; // rcx
  UFG::qSymbolUC v87; // ebx
  char *v88; // rax
  UFG::qSymbolUC *v89; // rdi
  UFG::qBaseTreeRB *v90; // rax
  UFG::qBaseNodeRB *v91; // rcx
  char *v92; // rdi
  UFG::SimpleTimer *v93; // rbx
  UFG::qSymbolUC v94; // ebx
  char *v95; // rax
  unsigned int **v96; // r14
  unsigned int *v97; // r15
  UFG::qString *v98; // r13
  __int64 v99; // rbx
  UFG::qSymbolUC *v100; // rdi
  unsigned int v101; // edx
  UFG::qBaseTreeRB *v102; // rax
  UFG::qBaseNodeRB *v103; // rcx
  _DWORD *v104; // rdx
  int v105; // eax
  const char *v106; // rdx
  UFG::qSymbolUC v107; // ebx
  char *v108; // rax
  unsigned int **v109; // r15
  unsigned int *v110; // r13
  char *p_mElapsedTime; // rdi
  UFG::qSymbolUC *v112; // r14
  unsigned int v113; // edx
  UFG::qBaseTreeRB *v114; // rax
  UFG::qBaseNodeRB *v115; // rcx
  unsigned int *v116; // rbx
  unsigned int v117; // r14d
  UFG::qSymbolUC v118; // ebx
  char *v119; // rax
  unsigned int **v120; // rdi
  unsigned int *v121; // r15
  signed __int64 v122; // rbx
  __int64 v123; // r13
  UFG::qSymbolUC *v124; // r14
  unsigned int v125; // edx
  UFG::qBaseTreeRB *v126; // rax
  UFG::qBaseNodeRB *v127; // rcx
  char *v128; // rdx
  UFG::qSymbolUC v129; // ebx
  char *v130; // rax
  unsigned int **v131; // rdi
  unsigned int *v132; // r15
  signed __int64 v133; // rbx
  __int64 v134; // r13
  UFG::qSymbolUC *v135; // r14
  unsigned int v136; // edx
  UFG::qBaseTreeRB *v137; // rax
  UFG::qBaseNodeRB *v138; // rcx
  char *v139; // rdx
  UFG::qSymbolUC v140; // ebx
  char *v141; // rax
  UFG::qSymbolUC *v142; // rdi
  UFG::qBaseTreeRB *v143; // rax
  UFG::qBaseNodeRB *v144; // rcx
  char *v145; // rdx
  UFG::qSymbolUC v146; // ebx
  char *v147; // rax
  unsigned int **v148; // rdi
  unsigned int *v149; // r15
  signed __int64 v150; // rbx
  __int64 v151; // r13
  UFG::qSymbolUC *v152; // r14
  unsigned int v153; // edx
  UFG::qBaseTreeRB *v154; // rax
  UFG::qBaseNodeRB *v155; // rcx
  char *v156; // rdx
  UFG::qSymbolUC v157; // ebx
  char *v158; // rax
  unsigned int **v159; // rdi
  unsigned int *v160; // r15
  signed __int64 v161; // rbx
  __int64 v162; // r13
  UFG::qSymbolUC *v163; // r14
  unsigned int v164; // edx
  UFG::qBaseTreeRB *v165; // rax
  UFG::qBaseNodeRB *v166; // rcx
  char *v167; // rdx
  UFG::qSymbolUC v168; // ebx
  char *v169; // rax
  UFG::qSymbolUC *v170; // rdi
  UFG::qBaseTreeRB *v171; // rax
  UFG::qBaseNodeRB *v172; // rcx
  UFG::qSymbolUC v173; // ebx
  char *v174; // rax
  char *v175; // rbx
  __int64 v176; // rdi
  char v177; // bl
  UFG::allocator::free_link *v179; // [rsp+30h] [rbp-98h]
  unsigned __int64 v180; // [rsp+38h] [rbp-90h]
  int v181[2]; // [rsp+50h] [rbp-78h]
  char ptr[72]; // [rsp+58h] [rbp-70h] BYREF
  UFG::qBaseTreeRB v183; // [rsp+A0h] [rbp-28h] BYREF
  UFG::qBaseTreeRB v184; // [rsp+E8h] [rbp+20h] BYREF
  UFG::qBaseTreeRB v185; // [rsp+130h] [rbp+68h] BYREF
  UFG::qBaseTreeRB v186; // [rsp+178h] [rbp+B0h] BYREF
  UFG::qBaseTreeRB v187; // [rsp+1C0h] [rbp+F8h] BYREF
  UFG::qBaseTreeRB v188; // [rsp+208h] [rbp+140h] BYREF
  UFG::qBaseTreeRB v189; // [rsp+250h] [rbp+188h] BYREF
  UFG::qBaseTreeRB v190; // [rsp+298h] [rbp+1D0h] BYREF
  UFG::qBaseTreeRB v191; // [rsp+2E0h] [rbp+218h] BYREF
  UFG::qBaseTreeRB v192; // [rsp+328h] [rbp+260h] BYREF
  UFG::qBaseTreeRB v193; // [rsp+370h] [rbp+2A8h] BYREF
  UFG::qBaseTreeRB v194; // [rsp+3B8h] [rbp+2F0h] BYREF
  UFG::qBaseTreeRB v195; // [rsp+400h] [rbp+338h] BYREF
  UFG::qBaseTreeRB v196; // [rsp+448h] [rbp+380h] BYREF
  UFG::qBaseTreeRB v197; // [rsp+490h] [rbp+3C8h] BYREF
  UFG::SimpleTimer *v198; // [rsp+518h] [rbp+450h]
  int v199; // [rsp+520h] [rbp+458h]
  __int64 v200; // [rsp+530h] [rbp+468h]
  UFG::qWiseSymbol dest; // [rsp+538h] [rbp+470h] BYREF

  v4 = pBuffer;
  v5 = persistenceMask;
  v200 = (__int64)pBuffer;
  mUID = dest.mUID;
  if ( (unsigned int)UFG::qDataHash32(pBuffer, dest.mUID - 4, 0xFFFFFFFF) != *(_DWORD *)&pBuffer[dest.mUID - 4] )
    return 0;
  `eh vector constructor iterator(
    ptr,
    0x48ui64,
    16,
    (void (__fastcall *)(void *))UFG::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>);
  v7 = 0i64;
  v8 = 0;
  v9 = 0i64;
  do
  {
    UFG::GameSnapshot::sHeaderCounts[v9] = *(_DWORD *)v4;
    v10 = *((_DWORD *)v4 + 1);
    v181[v9] = v10;
    v4 += 8;
    if ( v10 > mUID )
      goto LABEL_201;
    ++v8;
    ++v9;
  }
  while ( v8 < 0x10 );
  v11 = 0;
  v12 = 0i64;
  do
  {
    v13 = 0;
    if ( UFG::GameSnapshot::sHeaderCounts[v12] )
    {
      v14 = (UFG::qBaseTreeRB *)&ptr[0x48 * v11];
      v180 = v200 + (unsigned int)v181[v12];
      while ( 1 )
      {
        v15 = v4;
        UFG::qBaseTreeRB::Add(v14, (UFG::qBaseNodeRB *)v4);
        v4 += 40;
        v16 = *((_QWORD *)v15 + 4);
        if ( v16 )
        {
          if ( (unsigned __int64)&v15[v16 + 32] > v180 )
            break;
        }
        ++v13;
        v14 = (UFG::qBaseTreeRB *)&ptr[0x48 * v11];
        if ( v13 >= UFG::GameSnapshot::sHeaderCounts[v12] )
          goto LABEL_11;
      }
LABEL_201:
      v177 = 0;
      goto LABEL_202;
    }
LABEL_11:
    ++v11;
    ++v12;
  }
  while ( v11 < 0x10 );
  v17 = (unsigned int **)TimeSymbols;
  v18 = UFG::GameSnapshot::sDefinitionTimes;
  v19 = v198;
  v20 = 30i64;
  v200 = 30i64;
  v21 = v199;
  do
  {
    if ( (*v18 & v21) != 0 && ((unsigned int)v5 & *v18) == (_DWORD)v5 )
    {
      v22 = (UFG::qSymbolUC *)*v17;
      v23 = **v17;
      if ( v23 && (v24 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)ptr, v23)) != 0i64 )
      {
        mParent = v24->mNULL.mParent;
        if ( mParent )
          v26 = (char *)&v24->mNULL + (_QWORD)mParent;
        else
          v26 = 0i64;
        UFG::qMemCopy(&dest, v26, 4u);
        UFG::SimpleTimer::Stop(v19);
        UFG::SimpleTimer::SetElapsedTime(v19, *(float *)&dest.mUID);
      }
      else
      {
        v27.mUID = v22->mUID;
        v28 = UFG::qSymbol::as_cstr_dbg(v22);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v27.mUID,
          v28);
        v20 = v200;
      }
      v21 = v199;
    }
    ++v19;
    ++v18;
    ++v17;
    v200 = --v20;
  }
  while ( v20 );
  v29 = (unsigned int **)IDSymbols;
  v30 = UFG::GameSnapshot::sDefinitionIDs;
  v31 = (char *)v198 - (char *)UFG::GameSnapshot::sDefinitionIDs;
  v200 = (char *)v198 - (char *)UFG::GameSnapshot::sDefinitionIDs;
  v32 = 44i64;
  do
  {
    if ( (*v30 & v21) != 0 && ((unsigned int)v5 & *v30) == (_DWORD)v5 )
    {
      v33 = (UFG::qSymbolUC *)*v29;
      v34 = **v29;
      if ( v34 && (v35 = UFG::qBaseTreeRB::Get(&v183, v34)) != 0i64 )
      {
        v36 = v35->mNULL.mParent;
        if ( v36 )
          v37 = (unsigned int *)((char *)&v35->mNULL + (_QWORD)v36);
        else
          v37 = 0i64;
        *(unsigned int *)((char *)v30 + v31 + 480) = UFG::qSymbol::qSymbol(&dest, *v37)->mUID;
      }
      else
      {
        v38.mUID = v33->mUID;
        v39 = UFG::qSymbol::as_cstr_dbg(v33);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v38.mUID,
          v39);
        v31 = v200;
      }
      v21 = v199;
    }
    ++v30;
    ++v29;
    --v32;
  }
  while ( v32 );
  v40 = 0i64;
  v41 = 58i64;
  while ( 2 )
  {
    v42 = UFG::GameSnapshot::sDefinitionBools[v40];
    if ( (v42 & v21) == 0 || ((unsigned int)v5 & v42) != (_DWORD)v5 )
    {
LABEL_46:
      v48 = v198;
      goto LABEL_47;
    }
    v43 = (UFG::qSymbolUC *)BoolSymbols[v40];
    if ( !v43->mUID || (v44 = UFG::qBaseTreeRB::Get(&v184, v43->mUID)) == 0i64 )
    {
      v49.mUID = v43->mUID;
      v50 = UFG::qSymbol::as_cstr_dbg(v43);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
        v49.mUID,
        v50);
      v21 = v199;
      goto LABEL_46;
    }
    v45 = v44->mNULL.mParent;
    if ( v45 )
      v46 = (_DWORD *)((char *)&v45[1] + (_QWORD)v44);
    else
      v46 = 0i64;
    v47 = *v46 != 0;
    v48 = v198;
    *((_BYTE *)&v198[41].mTimestamp + v40) = v47;
    v21 = v199;
LABEL_47:
    ++v40;
    if ( --v41 )
      continue;
    break;
  }
  v51 = (unsigned int **)Int32Symbols;
  v52 = UFG::GameSnapshot::sDefinitionInts;
  v53 = (char *)v48 - (char *)UFG::GameSnapshot::sDefinitionInts;
  v200 = (char *)v48 - (char *)UFG::GameSnapshot::sDefinitionInts;
  v54 = 163i64;
  do
  {
    if ( (*v52 & v21) != 0 && ((unsigned int)v5 & *v52) == (_DWORD)v5 )
    {
      v55 = (UFG::qSymbolUC *)*v51;
      v56 = **v51;
      if ( v56 && (v57 = UFG::qBaseTreeRB::Get(&v185, v56)) != 0i64 )
      {
        v58 = v57->mNULL.mParent;
        if ( v58 )
          v59 = (unsigned int *)((char *)&v58[1] + (_QWORD)v57);
        else
          v59 = 0i64;
        *(unsigned int *)((char *)v52 + v53 + 716) = *v59;
      }
      else
      {
        v60.mUID = v55->mUID;
        v61 = UFG::qSymbol::as_cstr_dbg(v55);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v60.mUID,
          v61);
        v53 = v200;
      }
      v21 = v199;
    }
    ++v52;
    ++v51;
    --v54;
  }
  while ( v54 );
  if ( (v21 & UFG::GameSnapshot::sDefinitionUInt64s[0]) != 0 && (UFG::GameSnapshot::sDefinitionUInt64s[0] & v5) == v5 )
  {
    v62 = (UFG::qSymbolUC *)UInt64Symbols[0];
    if ( UInt64Symbols[0]->mUID && (v63 = UFG::qBaseTreeRB::Get(&v186, UInt64Symbols[0]->mUID)) != 0i64 )
    {
      v64 = v63->mNULL.mParent;
      if ( v64 )
        v65 = (UFG::qBaseNodeRB **)((char *)&v63->mNULL.mParent + (_QWORD)v64);
      else
        v65 = 0i64;
      *(_QWORD *)&v198[85].mElapsedTime = *v65;
    }
    else
    {
      v66.mUID = v62->mUID;
      v67 = UFG::qSymbol::as_cstr_dbg(v62);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
        v66.mUID,
        v67);
    }
    v21 = v199;
  }
  v68 = (unsigned int **)FloatSymbols;
  v69 = UFG::GameSnapshot::sDefinitionFloats;
  v70 = v198 + 86;
  v71 = 139i64;
  v200 = 139i64;
  do
  {
    if ( (*v69 & v21) != 0 && ((unsigned int)v5 & *v69) == (_DWORD)v5 )
    {
      v72 = (UFG::qSymbolUC *)*v68;
      v73 = **v68;
      if ( v73 && (v74 = UFG::qBaseTreeRB::Get(&v187, v73)) != 0i64 )
      {
        v75 = v74->mNULL.mParent;
        if ( v75 )
          v76 = (char *)&v74->mNULL + (_QWORD)v75;
        else
          v76 = 0i64;
        UFG::qMemCopy(v70, v76, 4u);
      }
      else
      {
        v77.mUID = v72->mUID;
        v78 = UFG::qSymbol::as_cstr_dbg(v72);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v77.mUID,
          v78);
        v71 = v200;
      }
      v21 = v199;
    }
    v70 = (UFG::SimpleTimer *)((char *)v70 + 4);
    ++v69;
    ++v68;
    v200 = --v71;
  }
  while ( v71 );
  v79 = UFG::GameSnapshot::sDefinitionIntsRanged;
  p_mIsStarted = &v198[120].mIsStarted;
  v81 = (char *)Int32RangedSymbols - (char *)v198;
  v200 = (char *)Int32RangedSymbols - (char *)v198;
  v82 = 7i64;
  do
  {
    if ( (*v79 & v21) != 0 && ((unsigned int)v5 & *v79) == (_DWORD)v5 )
    {
      v83 = *(UFG::qSymbolUC **)&p_mIsStarted[v81 - 1932];
      if ( v83->mUID && (v84 = UFG::qBaseTreeRB::Get(&v188, v83->mUID)) != 0i64 )
      {
        v85 = v84->mNULL.mParent;
        if ( v85 )
          v86 = (_DWORD *)((char *)&v85[1] + (_QWORD)v84);
        else
          v86 = 0i64;
        *(_DWORD *)p_mIsStarted = *v86;
        *((_DWORD *)p_mIsStarted + 1) = v86[1];
      }
      else
      {
        v87.mUID = v83->mUID;
        v88 = UFG::qSymbol::as_cstr_dbg(v83);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v87.mUID,
          v88);
      }
      v21 = v199;
      v81 = v200;
    }
    ++v79;
    p_mIsStarted += 8;
    --v82;
  }
  while ( v82 );
  if ( (UFG::GameSnapshot::sDefinitionFloatsRanged[0] & v21) != 0
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionFloatsRanged[0]) == (_DWORD)v5 )
  {
    v89 = (UFG::qSymbolUC *)FloatRangedSymbols[0];
    if ( FloatRangedSymbols[0]->mUID && (v90 = UFG::qBaseTreeRB::Get(&v189, FloatRangedSymbols[0]->mUID)) != 0i64 )
    {
      v91 = v90->mNULL.mParent;
      if ( v91 )
        v92 = (char *)&v90->mNULL + (_QWORD)v91;
      else
        v92 = 0i64;
      v93 = v198;
      UFG::qMemCopy((char *)&v198[124].mTimestamp + 4, v92, 4u);
      UFG::qMemCopy(&v93[124].mElapsedTime, v92 + 4, 4u);
    }
    else
    {
      v94.mUID = v89->mUID;
      v95 = UFG::qSymbol::as_cstr_dbg(v89);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
        v94.mUID,
        v95);
    }
    v21 = v199;
  }
  v96 = (unsigned int **)StringSymbols;
  v97 = UFG::GameSnapshot::sDefinitionStrings;
  v98 = (UFG::qString *)&v198[125];
  v99 = 25i64;
  v200 = 25i64;
  do
  {
    if ( (*v97 & v21) != 0 && ((unsigned int)v5 & *v97) == (_DWORD)v5 )
    {
      v100 = (UFG::qSymbolUC *)*v96;
      v101 = **v96;
      if ( v101 && (v102 = UFG::qBaseTreeRB::Get(&v190, v101)) != 0i64 )
      {
        v103 = v102->mNULL.mParent;
        if ( v103 )
          v104 = (_DWORD *)((char *)&v102->mNULL + (_QWORD)v103);
        else
          v104 = 0i64;
        v105 = *v104;
        v106 = (const char *)(v104 + 1);
        if ( v105 )
          UFG::qString::Set(v98, v106);
      }
      else
      {
        v107.mUID = v100->mUID;
        v108 = UFG::qSymbol::as_cstr_dbg(v100);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v107.mUID,
          v108);
        v99 = v200;
      }
      v21 = v199;
    }
    ++v98;
    ++v97;
    ++v96;
    v200 = --v99;
  }
  while ( v99 );
  v109 = (unsigned int **)BinarySymbols;
  v110 = UFG::GameSnapshot::sDefinitionBinaries;
  p_mElapsedTime = (char *)&v198[187].mElapsedTime;
  v200 = 3i64;
  do
  {
    if ( (*v110 & v21) != 0 && ((unsigned int)v5 & *v110) == (_DWORD)v5 )
    {
      v112 = (UFG::qSymbolUC *)*v109;
      v113 = **v109;
      if ( v113 && (v114 = UFG::qBaseTreeRB::Get(&v191, v113)) != 0i64 )
      {
        v115 = v114->mNULL.mParent;
        if ( v115 )
          v116 = (unsigned int *)((char *)&v114->mNULL + (_QWORD)v115);
        else
          v116 = 0i64;
        v117 = *v116;
        if ( *v116 )
        {
          v179 = UFG::qMalloc(v117, "Binary", 0i64);
          UFG::qMemCopy(v179, v116 + 1, v117);
          if ( *((_DWORD *)p_mElapsedTime + 2) )
            operator delete[](*(void **)p_mElapsedTime);
          *(_QWORD *)p_mElapsedTime = v179;
          *((_DWORD *)p_mElapsedTime + 2) = v117;
        }
      }
      else
      {
        v118.mUID = v112->mUID;
        v119 = UFG::qSymbol::as_cstr_dbg(v112);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v118.mUID,
          v119);
      }
      v21 = v199;
    }
    ++v110;
    ++v109;
    p_mElapsedTime += 16;
    --v200;
  }
  while ( v200 );
  v120 = (unsigned int **)MapBoolSymbols;
  v121 = UFG::GameSnapshot::sDefinitionMapBools;
  v122 = (char *)v198 - (char *)MapBoolSymbols;
  v200 = (char *)v198 - (char *)MapBoolSymbols;
  v123 = 93i64;
  do
  {
    if ( (*v121 & v21) != 0 && ((unsigned int)v5 & *v121) == (_DWORD)v5 )
    {
      v124 = (UFG::qSymbolUC *)*v120;
      v125 = **v120;
      if ( v125 && (v126 = UFG::qBaseTreeRB::Get(&v192, v125)) != 0i64 )
      {
        v127 = v126->mNULL.mParent;
        if ( v127 )
          v128 = (char *)&v126->mNULL + (_QWORD)v127;
        else
          v128 = 0i64;
        UFG::PersistentData::MapBool::Deserialize(*(UFG::PersistentData::MapBool **)((char *)v120 + v122 + 3048), v128);
      }
      else
      {
        v129.mUID = v124->mUID;
        v130 = UFG::qSymbol::as_cstr_dbg(v124);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v129.mUID,
          v130);
        v122 = v200;
      }
      v21 = v199;
    }
    ++v121;
    ++v120;
    --v123;
  }
  while ( v123 );
  v131 = (unsigned int **)MapInt32Symbols;
  v132 = UFG::GameSnapshot::sDefinitionMapInts;
  v133 = (char *)v198 - (char *)MapInt32Symbols;
  v200 = (char *)v198 - (char *)MapInt32Symbols;
  v134 = 47i64;
  do
  {
    if ( (*v132 & v21) != 0 && ((unsigned int)v5 & *v132) == (_DWORD)v5 )
    {
      v135 = (UFG::qSymbolUC *)*v131;
      v136 = **v131;
      if ( v136 && (v137 = UFG::qBaseTreeRB::Get(&v193, v136)) != 0i64 )
      {
        v138 = v137->mNULL.mParent;
        if ( v138 )
          v139 = (char *)&v137->mNULL + (_QWORD)v138;
        else
          v139 = 0i64;
        UFG::PersistentData::MapInt::Deserialize(*(UFG::PersistentData::MapInt **)((char *)v131 + v133 + 3792), v139);
      }
      else
      {
        v140.mUID = v135->mUID;
        v141 = UFG::qSymbol::as_cstr_dbg(v135);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v140.mUID,
          v141);
        v133 = v200;
      }
      v21 = v199;
    }
    ++v132;
    ++v131;
    --v134;
  }
  while ( v134 );
  if ( (UFG::GameSnapshot::sDefinitionMapUInt64s[0] & v21) != 0
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionMapUInt64s[0]) == (_DWORD)v5 )
  {
    v142 = (UFG::qSymbolUC *)MapUInt64Symbols[0];
    if ( MapUInt64Symbols[0]->mUID && (v143 = UFG::qBaseTreeRB::Get(&v194, MapUInt64Symbols[0]->mUID)) != 0i64 )
    {
      v144 = v143->mNULL.mParent;
      if ( v144 )
        v145 = (char *)&v143->mNULL + (_QWORD)v144;
      else
        v145 = 0i64;
      UFG::PersistentData::MapUInt64::Deserialize(*(UFG::PersistentData::MapUInt64 **)&v198[260].mElapsedTime, v145);
    }
    else
    {
      v146.mUID = v142->mUID;
      v147 = UFG::qSymbol::as_cstr_dbg(v142);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
        v146.mUID,
        v147);
    }
    v21 = v199;
  }
  v148 = (unsigned int **)MapFloatSymbols;
  v149 = UFG::GameSnapshot::sDefinitionMapFloats;
  v150 = (char *)v198 - (char *)MapFloatSymbols;
  v200 = (char *)v198 - (char *)MapFloatSymbols;
  v151 = 18i64;
  do
  {
    if ( (*v149 & v21) != 0 && ((unsigned int)v5 & *v149) == (_DWORD)v5 )
    {
      v152 = (UFG::qSymbolUC *)*v148;
      v153 = **v148;
      if ( v153 && (v154 = UFG::qBaseTreeRB::Get(&v195, v153)) != 0i64 )
      {
        v155 = v154->mNULL.mParent;
        if ( v155 )
          v156 = (char *)&v154->mNULL + (_QWORD)v155;
        else
          v156 = 0i64;
        UFG::PersistentData::MapInt::Deserialize(*(UFG::PersistentData::MapInt **)((char *)v148 + v150 + 4176), v156);
      }
      else
      {
        v157.mUID = v152->mUID;
        v158 = UFG::qSymbol::as_cstr_dbg(v152);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v157.mUID,
          v158);
        v150 = v200;
      }
      v21 = v199;
    }
    ++v149;
    ++v148;
    --v151;
  }
  while ( v151 );
  v159 = (unsigned int **)MapBinarySymbols;
  v160 = UFG::GameSnapshot::sDefinitionMapBinaries;
  v161 = (char *)v198 - (char *)MapBinarySymbols;
  v200 = (char *)v198 - (char *)MapBinarySymbols;
  v162 = 2i64;
  do
  {
    if ( (*v160 & v21) != 0 && ((unsigned int)v5 & *v160) == (_DWORD)v5 )
    {
      v163 = (UFG::qSymbolUC *)*v159;
      v164 = **v159;
      if ( v164 && (v165 = UFG::qBaseTreeRB::Get(&v196, v164)) != 0i64 )
      {
        v166 = v165->mNULL.mParent;
        if ( v166 )
          v167 = (char *)&v165->mNULL + (_QWORD)v166;
        else
          v167 = 0i64;
        UFG::PersistentData::MapBinary::Deserialize(
          *(UFG::PersistentData::MapBinary **)((char *)v159 + v161 + 4320),
          v167);
      }
      else
      {
        v168.mUID = v163->mUID;
        v169 = UFG::qSymbol::as_cstr_dbg(v163);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v168.mUID,
          v169);
        v161 = v200;
      }
      v21 = v199;
    }
    ++v160;
    ++v159;
    --v162;
  }
  while ( v162 );
  if ( (UFG::GameSnapshot::sDefinitionList[0] & v21) != 0
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionList[0]) == (_DWORD)v5 )
  {
    v170 = (UFG::qSymbolUC *)ListSymbols[0];
    if ( ListSymbols[0]->mUID && (v171 = UFG::qBaseTreeRB::Get(&v197, ListSymbols[0]->mUID)) != 0i64 )
    {
      v172 = v171->mNULL.mParent;
      if ( v172 )
        v7 = (char *)&v171->mNULL + (_QWORD)v172;
      UFG::PersistentData::List::Deserialize((UFG::PersistentData::List *)v198[271].mTimestamp, v7);
    }
    else
    {
      v173.mUID = v170->mUID;
      v174 = UFG::qSymbol::as_cstr_dbg(v170);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
        v173.mUID,
        v174);
    }
  }
  v175 = ptr;
  v176 = 16i64;
  do
  {
    UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)v175);
    v175 += 72;
    --v176;
  }
  while ( v176 );
  v177 = 1;
LABEL_202:
  `eh vector destructor iterator(
    ptr,
    0x48ui64,
    16,
    (void (__fastcall *)(void *))UFG::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>::~qTreeRB<UFG::DataEntry,UFG::DataEntry,0>);
  return v177;
}    if ( v172 )
        v7 = (char *)&v171->mNULL + (_QWORD)v172;
      UFG::PersistentData::List::Deserialize((UFG::PersistentData::List *)v198[271].mTimestamp, v7);
    }
    else
    {
      v173.mUID = v170->mUID;
      v174 = UFG::qSymbol::as_cstr_dbg(v170);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
        v173.mUID,
        v174);
    }
  }
  v175 = ptr;
  v176 = 16i64;
  do
  {
    UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)v175);
    v175 += 72;
    --v176;

