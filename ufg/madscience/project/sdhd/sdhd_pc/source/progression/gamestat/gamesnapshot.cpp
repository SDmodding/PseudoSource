// File Line: 47
// RVA: 0x48ADD0
void __fastcall UFG::GameSnapshot::GameSnapshot(UFG::GameSnapshot *this)
{
  UFG::GameSnapshot *v1; // rbx
  UFG::qSymbol *v2; // r15
  UFG::PersistentData::Int *v3; // rsi
  signed __int64 v4; // rdi
  UFG::qString *v5; // r12
  UFG::SimpleTimer *v6; // r14
  signed __int64 v7; // r13
  signed __int64 v8; // rcx
  signed __int64 v9; // rax
  signed __int64 v10; // rax
  signed __int64 v11; // rax
  signed __int64 v12; // rdi
  signed int v13; // edi
  _QWORD *v14; // rsi
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rax
  signed int v17; // edi
  _QWORD *v18; // rsi
  UFG::allocator::free_link *v19; // rax
  signed int v20; // edi
  _QWORD *v21; // rsi
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
  UFG::allocator::free_link *v115; // rax
  UFG::SimpleTimer v116; // [rsp+38h] [rbp-38h]
  UFG::qString v117; // [rsp+48h] [rbp-28h]

  v1 = this;
  `eh vector constructor iterator'(this, 0x10ui64, 30, (void (__fastcall *)(void *))UFG::PersistentData::Time::Time);
  v2 = (UFG::qSymbol *)v1->mIDs;
  `eh vector constructor iterator'(v1->mIDs, 4ui64, 44, (void (__fastcall *)(void *))UFG::PersistentData::ID::ID);
  `eh vector constructor iterator'(
    v1->mBools,
    1ui64,
    58,
    (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  v3 = v1->mInts;
  `eh vector constructor iterator'(
    v1->mInts,
    4ui64,
    163,
    (void (__fastcall *)(void *))UFG::PersistentData::Float::Float);
  `eh vector constructor iterator'(
    v1->mUInt64s,
    8ui64,
    1,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  v4 = (signed __int64)v1->mFloats;
  `eh vector constructor iterator'(
    v1->mFloats,
    4ui64,
    139,
    (void (__fastcall *)(void *))UFG::PersistentData::Float::Float);
  `eh vector constructor iterator'(
    v1->mIntsRanged,
    8ui64,
    7,
    (void (__fastcall *)(void *))UFG::PersistentData::IntRanged::IntRanged);
  `eh vector constructor iterator'(
    v1->mFloatsRanged,
    8ui64,
    1,
    (void (__fastcall *)(void *))UFG::PersistentData::IntRanged::IntRanged);
  v5 = (UFG::qString *)v1->mStrings;
  `eh vector constructor iterator'(
    v1->mStrings,
    0x28ui64,
    25,
    (void (__fastcall *)(void *))UFG::PersistentData::String::String);
  `eh vector constructor iterator'(
    v1->mBinaries,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::PersistentData::Binary::Binary);
  v6 = (UFG::SimpleTimer *)v1;
  v7 = 30i64;
  do
  {
    UFG::SimpleTimer::SimpleTimer(&v116);
    *v6 = v116;
    _((AMD_HD3D *)&v116);
    ++v6;
    --v7;
  }
  while ( v7 );
  v8 = 44i64;
  do
  {
    v2->mUID = UFG::gNullQSymbol.mUID;
    ++v2;
    --v8;
  }
  while ( v8 );
  v9 = (signed __int64)v1->mBools;
  *(_QWORD *)v9 = 0i64;
  *(_QWORD *)(v9 + 8) = 0i64;
  *(_QWORD *)(v9 + 16) = 0i64;
  *(_QWORD *)(v9 + 24) = 0i64;
  *(_QWORD *)(v9 + 32) = 0i64;
  *(_QWORD *)(v9 + 40) = 0i64;
  *(_QWORD *)(v9 + 48) = 0i64;
  *(_WORD *)(v9 + 56) = 0;
  v10 = 10i64;
  do
  {
    *(_QWORD *)&v3->mValue = 0i64;
    *(_QWORD *)&v3[2].mValue = 0i64;
    *(_QWORD *)&v3[4].mValue = 0i64;
    v3 += 16;
    *(_QWORD *)&v3[-10].mValue = 0i64;
    *(_QWORD *)&v3[-8].mValue = 0i64;
    *(_QWORD *)&v3[-6].mValue = 0i64;
    *(_QWORD *)&v3[-4].mValue = 0i64;
    *(_QWORD *)&v3[-2].mValue = 0i64;
    --v10;
  }
  while ( v10 );
  *(_QWORD *)&v3->mValue = 0i64;
  v3[2].mValue = 0;
  v1->mUInt64s[0].mValue = 0i64;
  v11 = 8i64;
  do
  {
    *(_QWORD *)v4 = 0i64;
    *(_QWORD *)(v4 + 8) = 0i64;
    *(_QWORD *)(v4 + 16) = 0i64;
    v4 += 64i64;
    *(_QWORD *)(v4 - 40) = 0i64;
    *(_QWORD *)(v4 - 32) = 0i64;
    *(_QWORD *)(v4 - 24) = 0i64;
    *(_QWORD *)(v4 - 16) = 0i64;
    *(_QWORD *)(v4 - 8) = 0i64;
    --v11;
  }
  while ( v11 );
  *(_QWORD *)v4 = 0i64;
  *(_QWORD *)(v4 + 8) = 0i64;
  *(_QWORD *)(v4 + 16) = 0i64;
  *(_QWORD *)(v4 + 24) = 0i64;
  *(_QWORD *)(v4 + 32) = 0i64;
  *(_DWORD *)(v4 + 40) = 0;
  v1->mIntsRanged[0] = 0i64;
  v1->mIntsRanged[1] = 0i64;
  v1->mIntsRanged[2] = 0i64;
  v1->mIntsRanged[3] = 0i64;
  v1->mIntsRanged[4] = 0i64;
  v1->mIntsRanged[5] = 0i64;
  v1->mIntsRanged[6] = 0i64;
  v1->mFloatsRanged[0] = 0i64;
  v12 = 25i64;
  do
  {
    UFG::qString::qString(&v117);
    UFG::qString::Set(v5, v117.mData, v117.mLength, 0i64, 0);
    UFG::qString::~qString(&v117);
    ++v5;
    --v12;
  }
  while ( v12 );
  v1->mBinaries[0].mpBuffer = 0i64;
  v1->mBinaries[0].mSize = 0;
  v1->mBinaries[1].mpBuffer = 0i64;
  v1->mBinaries[1].mSize = 0;
  v1->mBinaries[2].mpBuffer = 0i64;
  v1->mBinaries[2].mSize = 0;
  v13 = 0;
  v14 = v1->mpMapInts;
  do
  {
    v15 = UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    if ( v15 )
    {
      v15[1].mNext = 0i64;
      v15->mNext = 0i64;
      LODWORD(v15[2].mNext) = v13;
    }
    else
    {
      v15 = 0i64;
    }
    *v14 = v15;
    ++v13;
    ++v14;
  }
  while ( v13 < 47 );
  v16 = UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
  if ( v16 )
  {
    v16[1].mNext = 0i64;
    v16->mNext = 0i64;
    LODWORD(v16[2].mNext) = 0;
  }
  else
  {
    v16 = 0i64;
  }
  v1->mpMapUInt64s[0] = (UFG::PersistentData::MapUInt64 *)v16;
  v17 = 0;
  v18 = v1->mpMapFloats;
  do
  {
    v19 = UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    if ( v19 )
    {
      v19[1].mNext = 0i64;
      v19->mNext = 0i64;
      LODWORD(v19[2].mNext) = v17;
    }
    else
    {
      v19 = 0i64;
    }
    *v18 = v19;
    ++v17;
    ++v18;
  }
  while ( v17 < 18 );
  v20 = 0;
  v21 = v1->mpMapBinaries;
  do
  {
    v22 = UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    if ( v22 )
    {
      v22[1].mNext = 0i64;
      v22->mNext = 0i64;
      LODWORD(v22[2].mNext) = v20;
    }
    else
    {
      v22 = 0i64;
    }
    *v21 = v22;
    ++v20;
    ++v21;
  }
  while ( v20 < 2 );
  v23 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v23 )
  {
    LODWORD(v23->mNext) = 1;
    v23[2].mNext = 0i64;
    v23[1].mNext = 0i64;
    v23[4].mNext = 0i64;
    v23[3].mNext = 0i64;
    LODWORD(v23[5].mNext) = 0;
  }
  else
  {
    v23 = 0i64;
  }
  v1->mpMapBools[0] = (UFG::PersistentData::MapBool *)v23;
  v24 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v24 )
  {
    LODWORD(v24->mNext) = 1;
    v24[2].mNext = 0i64;
    v24[1].mNext = 0i64;
    v24[4].mNext = 0i64;
    v24[3].mNext = 0i64;
    LODWORD(v24[5].mNext) = 1;
  }
  else
  {
    v24 = 0i64;
  }
  v1->mpMapBools[1] = (UFG::PersistentData::MapBool *)v24;
  v25 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v25 )
  {
    LODWORD(v25->mNext) = 1;
    v25[2].mNext = 0i64;
    v25[1].mNext = 0i64;
    v25[4].mNext = 0i64;
    v25[3].mNext = 0i64;
    LODWORD(v25[5].mNext) = 2;
  }
  else
  {
    v25 = 0i64;
  }
  v1->mpMapBools[2] = (UFG::PersistentData::MapBool *)v25;
  v26 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v26 )
  {
    LODWORD(v26->mNext) = 0;
    v26[2].mNext = 0i64;
    v26[1].mNext = 0i64;
    v26[4].mNext = 0i64;
    v26[3].mNext = 0i64;
    LODWORD(v26[5].mNext) = 3;
  }
  else
  {
    v26 = 0i64;
  }
  v1->mpMapBools[3] = (UFG::PersistentData::MapBool *)v26;
  v27 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v27 )
  {
    LODWORD(v27->mNext) = 1;
    v27[2].mNext = 0i64;
    v27[1].mNext = 0i64;
    v27[4].mNext = 0i64;
    v27[3].mNext = 0i64;
    LODWORD(v27[5].mNext) = 4;
  }
  else
  {
    v27 = 0i64;
  }
  v1->mpMapBools[4] = (UFG::PersistentData::MapBool *)v27;
  v28 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v28 )
  {
    LODWORD(v28->mNext) = 0;
    v28[2].mNext = 0i64;
    v28[1].mNext = 0i64;
    v28[4].mNext = 0i64;
    v28[3].mNext = 0i64;
    LODWORD(v28[5].mNext) = 5;
  }
  else
  {
    v28 = 0i64;
  }
  v1->mpMapBools[5] = (UFG::PersistentData::MapBool *)v28;
  v29 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v29 )
  {
    LODWORD(v29->mNext) = 0;
    v29[2].mNext = 0i64;
    v29[1].mNext = 0i64;
    v29[4].mNext = 0i64;
    v29[3].mNext = 0i64;
    LODWORD(v29[5].mNext) = 6;
  }
  else
  {
    v29 = 0i64;
  }
  v1->mpMapBools[6] = (UFG::PersistentData::MapBool *)v29;
  v30 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v30 )
  {
    LODWORD(v30->mNext) = 0;
    v30[2].mNext = 0i64;
    v30[1].mNext = 0i64;
    v30[4].mNext = 0i64;
    v30[3].mNext = 0i64;
    LODWORD(v30[5].mNext) = 7;
  }
  else
  {
    v30 = 0i64;
  }
  v1->mpMapBools[7] = (UFG::PersistentData::MapBool *)v30;
  v31 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v31 )
  {
    LODWORD(v31->mNext) = 1;
    v31[2].mNext = 0i64;
    v31[1].mNext = 0i64;
    v31[4].mNext = 0i64;
    v31[3].mNext = 0i64;
    LODWORD(v31[5].mNext) = 8;
  }
  else
  {
    v31 = 0i64;
  }
  v1->mpMapBools[8] = (UFG::PersistentData::MapBool *)v31;
  v32 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v32 )
  {
    LODWORD(v32->mNext) = 1;
    v32[2].mNext = 0i64;
    v32[1].mNext = 0i64;
    v32[4].mNext = 0i64;
    v32[3].mNext = 0i64;
    LODWORD(v32[5].mNext) = 9;
  }
  else
  {
    v32 = 0i64;
  }
  v1->mpMapBools[9] = (UFG::PersistentData::MapBool *)v32;
  v33 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v33 )
  {
    LODWORD(v33->mNext) = 1;
    v33[2].mNext = 0i64;
    v33[1].mNext = 0i64;
    v33[4].mNext = 0i64;
    v33[3].mNext = 0i64;
    LODWORD(v33[5].mNext) = 10;
  }
  else
  {
    v33 = 0i64;
  }
  v1->mpMapBools[10] = (UFG::PersistentData::MapBool *)v33;
  v34 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v34 )
  {
    LODWORD(v34->mNext) = 0;
    v34[2].mNext = 0i64;
    v34[1].mNext = 0i64;
    v34[4].mNext = 0i64;
    v34[3].mNext = 0i64;
    LODWORD(v34[5].mNext) = 11;
  }
  else
  {
    v34 = 0i64;
  }
  v1->mpMapBools[11] = (UFG::PersistentData::MapBool *)v34;
  v35 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v35 )
  {
    LODWORD(v35->mNext) = 0;
    v35[2].mNext = 0i64;
    v35[1].mNext = 0i64;
    v35[4].mNext = 0i64;
    v35[3].mNext = 0i64;
    LODWORD(v35[5].mNext) = 12;
  }
  else
  {
    v35 = 0i64;
  }
  v1->mpMapBools[12] = (UFG::PersistentData::MapBool *)v35;
  v36 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v36 )
  {
    LODWORD(v36->mNext) = 1;
    v36[2].mNext = 0i64;
    v36[1].mNext = 0i64;
    v36[4].mNext = 0i64;
    v36[3].mNext = 0i64;
    LODWORD(v36[5].mNext) = 13;
  }
  else
  {
    v36 = 0i64;
  }
  v1->mpMapBools[13] = (UFG::PersistentData::MapBool *)v36;
  v37 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v37 )
  {
    LODWORD(v37->mNext) = 1;
    v37[2].mNext = 0i64;
    v37[1].mNext = 0i64;
    v37[4].mNext = 0i64;
    v37[3].mNext = 0i64;
    LODWORD(v37[5].mNext) = 14;
  }
  else
  {
    v37 = 0i64;
  }
  v1->mpMapBools[14] = (UFG::PersistentData::MapBool *)v37;
  v38 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v38 )
  {
    LODWORD(v38->mNext) = 1;
    v38[2].mNext = 0i64;
    v38[1].mNext = 0i64;
    v38[4].mNext = 0i64;
    v38[3].mNext = 0i64;
    LODWORD(v38[5].mNext) = 15;
  }
  else
  {
    v38 = 0i64;
  }
  v1->mpMapBools[15] = (UFG::PersistentData::MapBool *)v38;
  v39 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v39 )
  {
    LODWORD(v39->mNext) = 1;
    v39[2].mNext = 0i64;
    v39[1].mNext = 0i64;
    v39[4].mNext = 0i64;
    v39[3].mNext = 0i64;
    LODWORD(v39[5].mNext) = 16;
  }
  else
  {
    v39 = 0i64;
  }
  v1->mpMapBools[16] = (UFG::PersistentData::MapBool *)v39;
  v40 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v40 )
  {
    LODWORD(v40->mNext) = 1;
    v40[2].mNext = 0i64;
    v40[1].mNext = 0i64;
    v40[4].mNext = 0i64;
    v40[3].mNext = 0i64;
    LODWORD(v40[5].mNext) = 17;
  }
  else
  {
    v40 = 0i64;
  }
  v1->mpMapBools[17] = (UFG::PersistentData::MapBool *)v40;
  v41 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v41 )
  {
    LODWORD(v41->mNext) = 1;
    v41[2].mNext = 0i64;
    v41[1].mNext = 0i64;
    v41[4].mNext = 0i64;
    v41[3].mNext = 0i64;
    LODWORD(v41[5].mNext) = 18;
  }
  else
  {
    v41 = 0i64;
  }
  v1->mpMapBools[18] = (UFG::PersistentData::MapBool *)v41;
  v42 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v42 )
  {
    LODWORD(v42->mNext) = 1;
    v42[2].mNext = 0i64;
    v42[1].mNext = 0i64;
    v42[4].mNext = 0i64;
    v42[3].mNext = 0i64;
    LODWORD(v42[5].mNext) = 19;
  }
  else
  {
    v42 = 0i64;
  }
  v1->mpMapBools[19] = (UFG::PersistentData::MapBool *)v42;
  v43 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v43 )
  {
    LODWORD(v43->mNext) = 1;
    v43[2].mNext = 0i64;
    v43[1].mNext = 0i64;
    v43[4].mNext = 0i64;
    v43[3].mNext = 0i64;
    LODWORD(v43[5].mNext) = 20;
  }
  else
  {
    v43 = 0i64;
  }
  v1->mpMapBools[20] = (UFG::PersistentData::MapBool *)v43;
  v44 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v44 )
  {
    LODWORD(v44->mNext) = 1;
    v44[2].mNext = 0i64;
    v44[1].mNext = 0i64;
    v44[4].mNext = 0i64;
    v44[3].mNext = 0i64;
    LODWORD(v44[5].mNext) = 21;
  }
  else
  {
    v44 = 0i64;
  }
  v1->mpMapBools[21] = (UFG::PersistentData::MapBool *)v44;
  v45 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v45 )
  {
    LODWORD(v45->mNext) = 0;
    v45[2].mNext = 0i64;
    v45[1].mNext = 0i64;
    v45[4].mNext = 0i64;
    v45[3].mNext = 0i64;
    LODWORD(v45[5].mNext) = 22;
  }
  else
  {
    v45 = 0i64;
  }
  v1->mpMapBools[22] = (UFG::PersistentData::MapBool *)v45;
  v46 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v46 )
  {
    LODWORD(v46->mNext) = 0;
    v46[2].mNext = 0i64;
    v46[1].mNext = 0i64;
    v46[4].mNext = 0i64;
    v46[3].mNext = 0i64;
    LODWORD(v46[5].mNext) = 23;
  }
  else
  {
    v46 = 0i64;
  }
  v1->mpMapBools[23] = (UFG::PersistentData::MapBool *)v46;
  v47 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v47 )
  {
    LODWORD(v47->mNext) = 0;
    v47[2].mNext = 0i64;
    v47[1].mNext = 0i64;
    v47[4].mNext = 0i64;
    v47[3].mNext = 0i64;
    LODWORD(v47[5].mNext) = 24;
  }
  else
  {
    v47 = 0i64;
  }
  v1->mpMapBools[24] = (UFG::PersistentData::MapBool *)v47;
  v48 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v48 )
  {
    LODWORD(v48->mNext) = 0;
    v48[2].mNext = 0i64;
    v48[1].mNext = 0i64;
    v48[4].mNext = 0i64;
    v48[3].mNext = 0i64;
    LODWORD(v48[5].mNext) = 25;
  }
  else
  {
    v48 = 0i64;
  }
  v1->mpMapBools[25] = (UFG::PersistentData::MapBool *)v48;
  v49 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v49 )
  {
    LODWORD(v49->mNext) = 0;
    v49[2].mNext = 0i64;
    v49[1].mNext = 0i64;
    v49[4].mNext = 0i64;
    v49[3].mNext = 0i64;
    LODWORD(v49[5].mNext) = 26;
  }
  else
  {
    v49 = 0i64;
  }
  v1->mpMapBools[26] = (UFG::PersistentData::MapBool *)v49;
  v50 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v50 )
  {
    LODWORD(v50->mNext) = 0;
    v50[2].mNext = 0i64;
    v50[1].mNext = 0i64;
    v50[4].mNext = 0i64;
    v50[3].mNext = 0i64;
    LODWORD(v50[5].mNext) = 27;
  }
  else
  {
    v50 = 0i64;
  }
  v1->mpMapBools[27] = (UFG::PersistentData::MapBool *)v50;
  v51 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v51 )
  {
    LODWORD(v51->mNext) = 0;
    v51[2].mNext = 0i64;
    v51[1].mNext = 0i64;
    v51[4].mNext = 0i64;
    v51[3].mNext = 0i64;
    LODWORD(v51[5].mNext) = 28;
  }
  else
  {
    v51 = 0i64;
  }
  v1->mpMapBools[28] = (UFG::PersistentData::MapBool *)v51;
  v52 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v52 )
  {
    LODWORD(v52->mNext) = 0;
    v52[2].mNext = 0i64;
    v52[1].mNext = 0i64;
    v52[4].mNext = 0i64;
    v52[3].mNext = 0i64;
    LODWORD(v52[5].mNext) = 29;
  }
  else
  {
    v52 = 0i64;
  }
  v1->mpMapBools[29] = (UFG::PersistentData::MapBool *)v52;
  v53 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v53 )
  {
    LODWORD(v53->mNext) = 0;
    v53[2].mNext = 0i64;
    v53[1].mNext = 0i64;
    v53[4].mNext = 0i64;
    v53[3].mNext = 0i64;
    LODWORD(v53[5].mNext) = 30;
  }
  else
  {
    v53 = 0i64;
  }
  v1->mpMapBools[30] = (UFG::PersistentData::MapBool *)v53;
  v54 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v54 )
  {
    LODWORD(v54->mNext) = 0;
    v54[2].mNext = 0i64;
    v54[1].mNext = 0i64;
    v54[4].mNext = 0i64;
    v54[3].mNext = 0i64;
    LODWORD(v54[5].mNext) = 31;
  }
  else
  {
    v54 = 0i64;
  }
  v1->mpMapBools[31] = (UFG::PersistentData::MapBool *)v54;
  v55 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v55 )
  {
    LODWORD(v55->mNext) = 0;
    v55[2].mNext = 0i64;
    v55[1].mNext = 0i64;
    v55[4].mNext = 0i64;
    v55[3].mNext = 0i64;
    LODWORD(v55[5].mNext) = 32;
  }
  else
  {
    v55 = 0i64;
  }
  v1->mpMapBools[32] = (UFG::PersistentData::MapBool *)v55;
  v56 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v56 )
  {
    LODWORD(v56->mNext) = 0;
    v56[2].mNext = 0i64;
    v56[1].mNext = 0i64;
    v56[4].mNext = 0i64;
    v56[3].mNext = 0i64;
    LODWORD(v56[5].mNext) = 33;
  }
  else
  {
    v56 = 0i64;
  }
  v1->mpMapBools[33] = (UFG::PersistentData::MapBool *)v56;
  v57 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v57 )
  {
    LODWORD(v57->mNext) = 0;
    v57[2].mNext = 0i64;
    v57[1].mNext = 0i64;
    v57[4].mNext = 0i64;
    v57[3].mNext = 0i64;
    LODWORD(v57[5].mNext) = 34;
  }
  else
  {
    v57 = 0i64;
  }
  v1->mpMapBools[34] = (UFG::PersistentData::MapBool *)v57;
  v58 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v58 )
  {
    LODWORD(v58->mNext) = 0;
    v58[2].mNext = 0i64;
    v58[1].mNext = 0i64;
    v58[4].mNext = 0i64;
    v58[3].mNext = 0i64;
    LODWORD(v58[5].mNext) = 35;
  }
  else
  {
    v58 = 0i64;
  }
  v1->mpMapBools[35] = (UFG::PersistentData::MapBool *)v58;
  v59 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v59 )
  {
    LODWORD(v59->mNext) = 0;
    v59[2].mNext = 0i64;
    v59[1].mNext = 0i64;
    v59[4].mNext = 0i64;
    v59[3].mNext = 0i64;
    LODWORD(v59[5].mNext) = 36;
  }
  else
  {
    v59 = 0i64;
  }
  v1->mpMapBools[36] = (UFG::PersistentData::MapBool *)v59;
  v60 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v60 )
  {
    LODWORD(v60->mNext) = 0;
    v60[2].mNext = 0i64;
    v60[1].mNext = 0i64;
    v60[4].mNext = 0i64;
    v60[3].mNext = 0i64;
    LODWORD(v60[5].mNext) = 37;
  }
  else
  {
    v60 = 0i64;
  }
  v1->mpMapBools[37] = (UFG::PersistentData::MapBool *)v60;
  v61 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v61 )
  {
    LODWORD(v61->mNext) = 0;
    v61[2].mNext = 0i64;
    v61[1].mNext = 0i64;
    v61[4].mNext = 0i64;
    v61[3].mNext = 0i64;
    LODWORD(v61[5].mNext) = 38;
  }
  else
  {
    v61 = 0i64;
  }
  v1->mpMapBools[38] = (UFG::PersistentData::MapBool *)v61;
  v62 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v62 )
  {
    LODWORD(v62->mNext) = 0;
    v62[2].mNext = 0i64;
    v62[1].mNext = 0i64;
    v62[4].mNext = 0i64;
    v62[3].mNext = 0i64;
    LODWORD(v62[5].mNext) = 39;
  }
  else
  {
    v62 = 0i64;
  }
  v1->mpMapBools[39] = (UFG::PersistentData::MapBool *)v62;
  v63 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v63 )
  {
    LODWORD(v63->mNext) = 0;
    v63[2].mNext = 0i64;
    v63[1].mNext = 0i64;
    v63[4].mNext = 0i64;
    v63[3].mNext = 0i64;
    LODWORD(v63[5].mNext) = 40;
  }
  else
  {
    v63 = 0i64;
  }
  v1->mpMapBools[40] = (UFG::PersistentData::MapBool *)v63;
  v64 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v64 )
  {
    LODWORD(v64->mNext) = 0;
    v64[2].mNext = 0i64;
    v64[1].mNext = 0i64;
    v64[4].mNext = 0i64;
    v64[3].mNext = 0i64;
    LODWORD(v64[5].mNext) = 41;
  }
  else
  {
    v64 = 0i64;
  }
  v1->mpMapBools[41] = (UFG::PersistentData::MapBool *)v64;
  v65 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v65 )
  {
    LODWORD(v65->mNext) = 0;
    v65[2].mNext = 0i64;
    v65[1].mNext = 0i64;
    v65[4].mNext = 0i64;
    v65[3].mNext = 0i64;
    LODWORD(v65[5].mNext) = 42;
  }
  else
  {
    v65 = 0i64;
  }
  v1->mpMapBools[42] = (UFG::PersistentData::MapBool *)v65;
  v66 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v66 )
  {
    LODWORD(v66->mNext) = 0;
    v66[2].mNext = 0i64;
    v66[1].mNext = 0i64;
    v66[4].mNext = 0i64;
    v66[3].mNext = 0i64;
    LODWORD(v66[5].mNext) = 43;
  }
  else
  {
    v66 = 0i64;
  }
  v1->mpMapBools[43] = (UFG::PersistentData::MapBool *)v66;
  v67 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v67 )
  {
    LODWORD(v67->mNext) = 0;
    v67[2].mNext = 0i64;
    v67[1].mNext = 0i64;
    v67[4].mNext = 0i64;
    v67[3].mNext = 0i64;
    LODWORD(v67[5].mNext) = 44;
  }
  else
  {
    v67 = 0i64;
  }
  v1->mpMapBools[44] = (UFG::PersistentData::MapBool *)v67;
  v68 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v68 )
  {
    LODWORD(v68->mNext) = 0;
    v68[2].mNext = 0i64;
    v68[1].mNext = 0i64;
    v68[4].mNext = 0i64;
    v68[3].mNext = 0i64;
    LODWORD(v68[5].mNext) = 45;
  }
  else
  {
    v68 = 0i64;
  }
  v1->mpMapBools[45] = (UFG::PersistentData::MapBool *)v68;
  v69 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v69 )
  {
    LODWORD(v69->mNext) = 0;
    v69[2].mNext = 0i64;
    v69[1].mNext = 0i64;
    v69[4].mNext = 0i64;
    v69[3].mNext = 0i64;
    LODWORD(v69[5].mNext) = 46;
  }
  else
  {
    v69 = 0i64;
  }
  v1->mpMapBools[46] = (UFG::PersistentData::MapBool *)v69;
  v70 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v70 )
  {
    LODWORD(v70->mNext) = 0;
    v70[2].mNext = 0i64;
    v70[1].mNext = 0i64;
    v70[4].mNext = 0i64;
    v70[3].mNext = 0i64;
    LODWORD(v70[5].mNext) = 47;
  }
  else
  {
    v70 = 0i64;
  }
  v1->mpMapBools[47] = (UFG::PersistentData::MapBool *)v70;
  v71 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v71 )
  {
    LODWORD(v71->mNext) = 0;
    v71[2].mNext = 0i64;
    v71[1].mNext = 0i64;
    v71[4].mNext = 0i64;
    v71[3].mNext = 0i64;
    LODWORD(v71[5].mNext) = 48;
  }
  else
  {
    v71 = 0i64;
  }
  v1->mpMapBools[48] = (UFG::PersistentData::MapBool *)v71;
  v72 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v72 )
  {
    LODWORD(v72->mNext) = 0;
    v72[2].mNext = 0i64;
    v72[1].mNext = 0i64;
    v72[4].mNext = 0i64;
    v72[3].mNext = 0i64;
    LODWORD(v72[5].mNext) = 49;
  }
  else
  {
    v72 = 0i64;
  }
  v1->mpMapBools[49] = (UFG::PersistentData::MapBool *)v72;
  v73 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v73 )
  {
    LODWORD(v73->mNext) = 0;
    v73[2].mNext = 0i64;
    v73[1].mNext = 0i64;
    v73[4].mNext = 0i64;
    v73[3].mNext = 0i64;
    LODWORD(v73[5].mNext) = 50;
  }
  else
  {
    v73 = 0i64;
  }
  v1->mpMapBools[50] = (UFG::PersistentData::MapBool *)v73;
  v74 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v74 )
  {
    LODWORD(v74->mNext) = 0;
    v74[2].mNext = 0i64;
    v74[1].mNext = 0i64;
    v74[4].mNext = 0i64;
    v74[3].mNext = 0i64;
    LODWORD(v74[5].mNext) = 51;
  }
  else
  {
    v74 = 0i64;
  }
  v1->mpMapBools[51] = (UFG::PersistentData::MapBool *)v74;
  v75 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v75 )
  {
    LODWORD(v75->mNext) = 0;
    v75[2].mNext = 0i64;
    v75[1].mNext = 0i64;
    v75[4].mNext = 0i64;
    v75[3].mNext = 0i64;
    LODWORD(v75[5].mNext) = 52;
  }
  else
  {
    v75 = 0i64;
  }
  v1->mpMapBools[52] = (UFG::PersistentData::MapBool *)v75;
  v76 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v76 )
  {
    LODWORD(v76->mNext) = 0;
    v76[2].mNext = 0i64;
    v76[1].mNext = 0i64;
    v76[4].mNext = 0i64;
    v76[3].mNext = 0i64;
    LODWORD(v76[5].mNext) = 53;
  }
  else
  {
    v76 = 0i64;
  }
  v1->mpMapBools[53] = (UFG::PersistentData::MapBool *)v76;
  v77 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v77 )
  {
    LODWORD(v77->mNext) = 1;
    v77[2].mNext = 0i64;
    v77[1].mNext = 0i64;
    v77[4].mNext = 0i64;
    v77[3].mNext = 0i64;
    LODWORD(v77[5].mNext) = 54;
  }
  else
  {
    v77 = 0i64;
  }
  v1->mpMapBools[54] = (UFG::PersistentData::MapBool *)v77;
  v78 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v78 )
  {
    LODWORD(v78->mNext) = 0;
    v78[2].mNext = 0i64;
    v78[1].mNext = 0i64;
    v78[4].mNext = 0i64;
    v78[3].mNext = 0i64;
    LODWORD(v78[5].mNext) = 55;
  }
  else
  {
    v78 = 0i64;
  }
  v1->mpMapBools[55] = (UFG::PersistentData::MapBool *)v78;
  v79 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v79 )
  {
    LODWORD(v79->mNext) = 1;
    v79[2].mNext = 0i64;
    v79[1].mNext = 0i64;
    v79[4].mNext = 0i64;
    v79[3].mNext = 0i64;
    LODWORD(v79[5].mNext) = 56;
  }
  else
  {
    v79 = 0i64;
  }
  v1->mpMapBools[56] = (UFG::PersistentData::MapBool *)v79;
  v80 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v80 )
  {
    LODWORD(v80->mNext) = 1;
    v80[2].mNext = 0i64;
    v80[1].mNext = 0i64;
    v80[4].mNext = 0i64;
    v80[3].mNext = 0i64;
    LODWORD(v80[5].mNext) = 57;
  }
  else
  {
    v80 = 0i64;
  }
  v1->mpMapBools[57] = (UFG::PersistentData::MapBool *)v80;
  v81 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v81 )
  {
    LODWORD(v81->mNext) = 1;
    v81[2].mNext = 0i64;
    v81[1].mNext = 0i64;
    v81[4].mNext = 0i64;
    v81[3].mNext = 0i64;
    LODWORD(v81[5].mNext) = 58;
  }
  else
  {
    v81 = 0i64;
  }
  v1->mpMapBools[58] = (UFG::PersistentData::MapBool *)v81;
  v82 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v82 )
  {
    LODWORD(v82->mNext) = 1;
    v82[2].mNext = 0i64;
    v82[1].mNext = 0i64;
    v82[4].mNext = 0i64;
    v82[3].mNext = 0i64;
    LODWORD(v82[5].mNext) = 59;
  }
  else
  {
    v82 = 0i64;
  }
  v1->mpMapBools[59] = (UFG::PersistentData::MapBool *)v82;
  v83 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v83 )
  {
    LODWORD(v83->mNext) = 1;
    v83[2].mNext = 0i64;
    v83[1].mNext = 0i64;
    v83[4].mNext = 0i64;
    v83[3].mNext = 0i64;
    LODWORD(v83[5].mNext) = 60;
  }
  else
  {
    v83 = 0i64;
  }
  v1->mpMapBools[60] = (UFG::PersistentData::MapBool *)v83;
  v84 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v84 )
  {
    LODWORD(v84->mNext) = 1;
    v84[2].mNext = 0i64;
    v84[1].mNext = 0i64;
    v84[4].mNext = 0i64;
    v84[3].mNext = 0i64;
    LODWORD(v84[5].mNext) = 61;
  }
  else
  {
    v84 = 0i64;
  }
  v1->mpMapBools[61] = (UFG::PersistentData::MapBool *)v84;
  v85 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v85 )
  {
    LODWORD(v85->mNext) = 1;
    v85[2].mNext = 0i64;
    v85[1].mNext = 0i64;
    v85[4].mNext = 0i64;
    v85[3].mNext = 0i64;
    LODWORD(v85[5].mNext) = 62;
  }
  else
  {
    v85 = 0i64;
  }
  v1->mpMapBools[62] = (UFG::PersistentData::MapBool *)v85;
  v86 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v86 )
  {
    LODWORD(v86->mNext) = 1;
    v86[2].mNext = 0i64;
    v86[1].mNext = 0i64;
    v86[4].mNext = 0i64;
    v86[3].mNext = 0i64;
    LODWORD(v86[5].mNext) = 63;
  }
  else
  {
    v86 = 0i64;
  }
  v1->mpMapBools[63] = (UFG::PersistentData::MapBool *)v86;
  v87 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v87 )
  {
    LODWORD(v87->mNext) = 1;
    v87[2].mNext = 0i64;
    v87[1].mNext = 0i64;
    v87[4].mNext = 0i64;
    v87[3].mNext = 0i64;
    LODWORD(v87[5].mNext) = 64;
  }
  else
  {
    v87 = 0i64;
  }
  v1->mpMapBools[64] = (UFG::PersistentData::MapBool *)v87;
  v88 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v88 )
  {
    LODWORD(v88->mNext) = 0;
    v88[2].mNext = 0i64;
    v88[1].mNext = 0i64;
    v88[4].mNext = 0i64;
    v88[3].mNext = 0i64;
    LODWORD(v88[5].mNext) = 65;
  }
  else
  {
    v88 = 0i64;
  }
  v1->mpMapBools[65] = (UFG::PersistentData::MapBool *)v88;
  v89 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v89 )
  {
    LODWORD(v89->mNext) = 0;
    v89[2].mNext = 0i64;
    v89[1].mNext = 0i64;
    v89[4].mNext = 0i64;
    v89[3].mNext = 0i64;
    LODWORD(v89[5].mNext) = 66;
  }
  else
  {
    v89 = 0i64;
  }
  v1->mpMapBools[66] = (UFG::PersistentData::MapBool *)v89;
  v90 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v90 )
  {
    LODWORD(v90->mNext) = 0;
    v90[2].mNext = 0i64;
    v90[1].mNext = 0i64;
    v90[4].mNext = 0i64;
    v90[3].mNext = 0i64;
    LODWORD(v90[5].mNext) = 67;
  }
  else
  {
    v90 = 0i64;
  }
  v1->mpMapBools[67] = (UFG::PersistentData::MapBool *)v90;
  v91 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v91 )
  {
    LODWORD(v91->mNext) = 0;
    v91[2].mNext = 0i64;
    v91[1].mNext = 0i64;
    v91[4].mNext = 0i64;
    v91[3].mNext = 0i64;
    LODWORD(v91[5].mNext) = 68;
  }
  else
  {
    v91 = 0i64;
  }
  v1->mpMapBools[68] = (UFG::PersistentData::MapBool *)v91;
  v92 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v92 )
  {
    LODWORD(v92->mNext) = 0;
    v92[2].mNext = 0i64;
    v92[1].mNext = 0i64;
    v92[4].mNext = 0i64;
    v92[3].mNext = 0i64;
    LODWORD(v92[5].mNext) = 69;
  }
  else
  {
    v92 = 0i64;
  }
  v1->mpMapBools[69] = (UFG::PersistentData::MapBool *)v92;
  v93 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v93 )
  {
    LODWORD(v93->mNext) = 0;
    v93[2].mNext = 0i64;
    v93[1].mNext = 0i64;
    v93[4].mNext = 0i64;
    v93[3].mNext = 0i64;
    LODWORD(v93[5].mNext) = 70;
  }
  else
  {
    v93 = 0i64;
  }
  v1->mpMapBools[70] = (UFG::PersistentData::MapBool *)v93;
  v94 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v94 )
  {
    LODWORD(v94->mNext) = 0;
    v94[2].mNext = 0i64;
    v94[1].mNext = 0i64;
    v94[4].mNext = 0i64;
    v94[3].mNext = 0i64;
    LODWORD(v94[5].mNext) = 71;
  }
  else
  {
    v94 = 0i64;
  }
  v1->mpMapBools[71] = (UFG::PersistentData::MapBool *)v94;
  v95 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v95 )
  {
    LODWORD(v95->mNext) = 0;
    v95[2].mNext = 0i64;
    v95[1].mNext = 0i64;
    v95[4].mNext = 0i64;
    v95[3].mNext = 0i64;
    LODWORD(v95[5].mNext) = 72;
  }
  else
  {
    v95 = 0i64;
  }
  v1->mpMapBools[72] = (UFG::PersistentData::MapBool *)v95;
  v96 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v96 )
  {
    LODWORD(v96->mNext) = 0;
    v96[2].mNext = 0i64;
    v96[1].mNext = 0i64;
    v96[4].mNext = 0i64;
    v96[3].mNext = 0i64;
    LODWORD(v96[5].mNext) = 73;
  }
  else
  {
    v96 = 0i64;
  }
  v1->mpMapBools[73] = (UFG::PersistentData::MapBool *)v96;
  v97 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v97 )
  {
    LODWORD(v97->mNext) = 0;
    v97[2].mNext = 0i64;
    v97[1].mNext = 0i64;
    v97[4].mNext = 0i64;
    v97[3].mNext = 0i64;
    LODWORD(v97[5].mNext) = 74;
  }
  else
  {
    v97 = 0i64;
  }
  v1->mpMapBools[74] = (UFG::PersistentData::MapBool *)v97;
  v98 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v98 )
  {
    LODWORD(v98->mNext) = 1;
    v98[2].mNext = 0i64;
    v98[1].mNext = 0i64;
    v98[4].mNext = 0i64;
    v98[3].mNext = 0i64;
    LODWORD(v98[5].mNext) = 75;
  }
  else
  {
    v98 = 0i64;
  }
  v1->mpMapBools[75] = (UFG::PersistentData::MapBool *)v98;
  v99 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v99 )
  {
    LODWORD(v99->mNext) = 1;
    v99[2].mNext = 0i64;
    v99[1].mNext = 0i64;
    v99[4].mNext = 0i64;
    v99[3].mNext = 0i64;
    LODWORD(v99[5].mNext) = 76;
  }
  else
  {
    v99 = 0i64;
  }
  v1->mpMapBools[76] = (UFG::PersistentData::MapBool *)v99;
  v100 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v100 )
  {
    LODWORD(v100->mNext) = 0;
    v100[2].mNext = 0i64;
    v100[1].mNext = 0i64;
    v100[4].mNext = 0i64;
    v100[3].mNext = 0i64;
    LODWORD(v100[5].mNext) = 77;
  }
  else
  {
    v100 = 0i64;
  }
  v1->mpMapBools[77] = (UFG::PersistentData::MapBool *)v100;
  v101 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v101 )
  {
    LODWORD(v101->mNext) = 1;
    v101[2].mNext = 0i64;
    v101[1].mNext = 0i64;
    v101[4].mNext = 0i64;
    v101[3].mNext = 0i64;
    LODWORD(v101[5].mNext) = 78;
  }
  else
  {
    v101 = 0i64;
  }
  v1->mpMapBools[78] = (UFG::PersistentData::MapBool *)v101;
  v102 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v102 )
  {
    LODWORD(v102->mNext) = 1;
    v102[2].mNext = 0i64;
    v102[1].mNext = 0i64;
    v102[4].mNext = 0i64;
    v102[3].mNext = 0i64;
    LODWORD(v102[5].mNext) = 79;
  }
  else
  {
    v102 = 0i64;
  }
  v1->mpMapBools[79] = (UFG::PersistentData::MapBool *)v102;
  v103 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v103 )
  {
    LODWORD(v103->mNext) = 1;
    v103[2].mNext = 0i64;
    v103[1].mNext = 0i64;
    v103[4].mNext = 0i64;
    v103[3].mNext = 0i64;
    LODWORD(v103[5].mNext) = 80;
  }
  else
  {
    v103 = 0i64;
  }
  v1->mpMapBools[80] = (UFG::PersistentData::MapBool *)v103;
  v104 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v104 )
  {
    LODWORD(v104->mNext) = 1;
    v104[2].mNext = 0i64;
    v104[1].mNext = 0i64;
    v104[4].mNext = 0i64;
    v104[3].mNext = 0i64;
    LODWORD(v104[5].mNext) = 81;
  }
  else
  {
    v104 = 0i64;
  }
  v1->mpMapBools[81] = (UFG::PersistentData::MapBool *)v104;
  v105 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v105 )
  {
    LODWORD(v105->mNext) = 1;
    v105[2].mNext = 0i64;
    v105[1].mNext = 0i64;
    v105[4].mNext = 0i64;
    v105[3].mNext = 0i64;
    LODWORD(v105[5].mNext) = 82;
  }
  else
  {
    v105 = 0i64;
  }
  v1->mpMapBools[82] = (UFG::PersistentData::MapBool *)v105;
  v106 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v106 )
  {
    LODWORD(v106->mNext) = 1;
    v106[2].mNext = 0i64;
    v106[1].mNext = 0i64;
    v106[4].mNext = 0i64;
    v106[3].mNext = 0i64;
    LODWORD(v106[5].mNext) = 83;
  }
  else
  {
    v106 = 0i64;
  }
  v1->mpMapBools[83] = (UFG::PersistentData::MapBool *)v106;
  v107 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v107 )
  {
    LODWORD(v107->mNext) = 1;
    v107[2].mNext = 0i64;
    v107[1].mNext = 0i64;
    v107[4].mNext = 0i64;
    v107[3].mNext = 0i64;
    LODWORD(v107[5].mNext) = 84;
  }
  else
  {
    v107 = 0i64;
  }
  v1->mpMapBools[84] = (UFG::PersistentData::MapBool *)v107;
  v108 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v108 )
  {
    LODWORD(v108->mNext) = 1;
    v108[2].mNext = 0i64;
    v108[1].mNext = 0i64;
    v108[4].mNext = 0i64;
    v108[3].mNext = 0i64;
    LODWORD(v108[5].mNext) = 85;
  }
  else
  {
    v108 = 0i64;
  }
  v1->mpMapBools[85] = (UFG::PersistentData::MapBool *)v108;
  v109 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v109 )
  {
    LODWORD(v109->mNext) = 1;
    v109[2].mNext = 0i64;
    v109[1].mNext = 0i64;
    v109[4].mNext = 0i64;
    v109[3].mNext = 0i64;
    LODWORD(v109[5].mNext) = 86;
  }
  else
  {
    v109 = 0i64;
  }
  v1->mpMapBools[86] = (UFG::PersistentData::MapBool *)v109;
  v110 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v110 )
  {
    LODWORD(v110->mNext) = 0;
    v110[2].mNext = 0i64;
    v110[1].mNext = 0i64;
    v110[4].mNext = 0i64;
    v110[3].mNext = 0i64;
    LODWORD(v110[5].mNext) = 87;
  }
  else
  {
    v110 = 0i64;
  }
  v1->mpMapBools[87] = (UFG::PersistentData::MapBool *)v110;
  v111 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v111 )
  {
    LODWORD(v111->mNext) = 0;
    v111[2].mNext = 0i64;
    v111[1].mNext = 0i64;
    v111[4].mNext = 0i64;
    v111[3].mNext = 0i64;
    LODWORD(v111[5].mNext) = 88;
  }
  else
  {
    v111 = 0i64;
  }
  v1->mpMapBools[88] = (UFG::PersistentData::MapBool *)v111;
  v112 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v112 )
  {
    LODWORD(v112->mNext) = 1;
    v112[2].mNext = 0i64;
    v112[1].mNext = 0i64;
    v112[4].mNext = 0i64;
    v112[3].mNext = 0i64;
    LODWORD(v112[5].mNext) = 89;
  }
  else
  {
    v112 = 0i64;
  }
  v1->mpMapBools[89] = (UFG::PersistentData::MapBool *)v112;
  v113 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v113 )
  {
    LODWORD(v113->mNext) = 1;
    v113[2].mNext = 0i64;
    v113[1].mNext = 0i64;
    v113[4].mNext = 0i64;
    v113[3].mNext = 0i64;
    LODWORD(v113[5].mNext) = 90;
  }
  else
  {
    v113 = 0i64;
  }
  v1->mpMapBools[90] = (UFG::PersistentData::MapBool *)v113;
  v114 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v114 )
  {
    LODWORD(v114->mNext) = 0;
    v114[2].mNext = 0i64;
    v114[1].mNext = 0i64;
    v114[4].mNext = 0i64;
    v114[3].mNext = 0i64;
    LODWORD(v114[5].mNext) = 91;
  }
  else
  {
    v114 = 0i64;
  }
  v1->mpMapBools[91] = (UFG::PersistentData::MapBool *)v114;
  v115 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v115 )
  {
    LODWORD(v115->mNext) = 0;
    v115[2].mNext = 0i64;
    v115[1].mNext = 0i64;
    v115[4].mNext = 0i64;
    v115[3].mNext = 0i64;
    LODWORD(v115[5].mNext) = 92;
  }
  else
  {
    v115 = 0i64;
  }
  v1->mpMapBools[92] = (UFG::PersistentData::MapBool *)v115;
  UFG::GameSnapshot::CreateList(v1);
}{
    LODWORD(v111->mNext) = 0;
    v111[2].mNext = 0i64;
    v111[1].mNext = 0i64;
    v111[4].mNext = 0i64;
    v111[3].mNext = 0i64;
    LODWORD(v111[5].mNext) = 88;
  }
  else
  {
    v111 = 0i64;
  }
  v1->mpMapBools[88] = (UFG::PersistentData::MapBool *)v111;
  v112 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v112 )
  {
    LODWORD(v112->mNext) = 1;
    v112[2].mNext = 0i64;
    v112[1].mNext = 0i64;
    v112[4].mNext = 0i64;
    v112[3].mNext = 0i64;
    LODWORD(v112[5].mNext) = 89;
  }
  else
  {
    v112 = 0i64;
  }
  v1->mpMapBools[89] = (UFG::PersistentData::MapBool *)v112;
  v113 = UFG::qMalloc(0x30ui64, "GameSnapShot", 0i64);
  if ( v113 )
  {
    LODWORD(v113->mNext) = 1;
    v113[2].mNext = 0i64;
    v113[1].mNext = 0i64;
    v113

// File Line: 137
// RVA: 0x499E60
void __fastcall UFG::GameSnapshot::CreateList(UFG::GameSnapshot *this)
{
  UFG::GameSnapshot *v1; // rsi
  UFG::allocator::free_link *v2; // rax
  UFG::PersistentData::List *v3; // rdi
  UFG::allocator::free_link *v4; // rax

  v1 = this;
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
  v1->mpList[0] = v3;
  v3->mType = 3;
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
  UFG::GameSnapshot *v2; // r13
  UFG::GameSnapshot *v3; // r15
  UFG::PersistentData::Time *v4; // r8
  signed __int64 v5; // r9
  signed __int64 v6; // r10
  UFG::PersistentData::ID *v7; // rcx
  signed __int64 v8; // rdi
  signed __int64 v9; // rdx
  UFG::PersistentData::Bool *v10; // rcx
  signed __int64 v11; // rdx
  UFG::PersistentData::Int *v12; // rcx
  signed __int64 v13; // rdx
  UFG::PersistentData::Float *v14; // rcx
  signed __int64 v15; // rdx
  _DWORD *v16; // rcx
  signed __int64 v17; // rbp
  signed __int64 v18; // rdx
  const char **v19; // rbx
  UFG::qString *v20; // rsi
  signed __int64 v21; // r14
  unsigned int *v22; // rsi
  unsigned int v23; // eax
  UFG::allocator::free_link *v24; // rbx
  UFG::PersistentData::MapBool **v25; // rsi
  signed __int64 v26; // rbp
  UFG::PersistentData::MapBool *v27; // rbx
  UFG::allocator::free_link *v28; // rax
  UFG::PersistentData::MapBool *v29; // rbx
  __int64 v30; // r8
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v31; // rdx
  int v32; // eax
  UFG::PersistentData::MapInt **v33; // r14
  signed __int64 v34; // rbp
  UFG::PersistentData::MapInt *v35; // rsi
  UFG::PersistentData::KeyValue *v36; // rcx
  char *v37; // rbx
  UFG::PersistentData::KeyValue *v38; // rcx
  char *v39; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v40; // rax
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v41; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v42; // rcx
  UFG::PersistentData::MapUInt64 *v43; // rsi
  UFG::PersistentData::KeyValue64 *v44; // rcx
  char *v45; // rbx
  UFG::PersistentData::KeyValue64 *v46; // rcx
  char *v47; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue64,0> *v48; // rax
  UFG::PersistentData::MapUInt64 *v49; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue64,0> *v50; // rcx
  UFG::PersistentData::MapFloat **v51; // r14
  signed __int64 v52; // rbp
  UFG::PersistentData::MapFloat *v53; // rsi
  UFG::PersistentData::KeyValue *v54; // rcx
  char *v55; // rbx
  UFG::PersistentData::KeyValue *v56; // rcx
  char *v57; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v58; // rax
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v59; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v60; // rcx
  UFG::PersistentData::MapBinary **v61; // r14
  signed __int64 v62; // rbp
  UFG::PersistentData::MapBinary *v63; // rsi
  UFG::PersistentData::KeyBinary *v64; // rcx
  unsigned int *v65; // rbx
  UFG::allocator::free_link *v66; // rax
  UFG::PersistentData::MapBinary *v67; // rax
  UFG::PersistentData::List *v68; // rdx
  UFG::PersistentData::List *v69; // rcx

  v2 = src;
  v3 = this;
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
  v7 = this->mIDs;
  v8 = (char *)src - (char *)v3;
  v9 = 22i64;
  do
  {
    v7->mValue.mUID = *(unsigned int *)((char *)v7 + v8);
    v7[1].mValue.mUID = *(unsigned int *)((char *)v7 + v8 + 4);
    v7 += 2;
    --v9;
  }
  while ( v9 );
  v10 = v3->mBools;
  v11 = 29i64;
  do
  {
    v10->mValue = (bool)v10[v8];
    v10[1].mValue = (bool)v10[v8 + 1];
    v10 += 2;
    --v11;
  }
  while ( v11 );
  v12 = v2->mInts;
  v13 = 163i64;
  do
  {
    *(UFG::PersistentData::Int *)((char *)v12 + v5) = (UFG::PersistentData::Int)v12->mValue;
    ++v12;
    --v13;
  }
  while ( v13 );
  v3->mUInt64s[0].mValue = v2->mUInt64s[0].mValue;
  v14 = v3->mFloats;
  v15 = 17i64;
  do
  {
    v14->mValue = *(float *)((char *)v14 + v8);
    v14[1].mValue = *(float *)((char *)v14 + v8 + 4);
    v14[2].mValue = *(float *)((char *)v14 + v8 + 8);
    v14[3].mValue = *(float *)((char *)v14 + v8 + 12);
    v14[4].mValue = *(float *)((char *)v14 + v8 + 16);
    v14[5].mValue = *(float *)((char *)v14 + v8 + 20);
    v14[6].mValue = *(float *)((char *)v14 + v8 + 24);
    v14[7].mValue = *(float *)((char *)v14 + v8 + 28);
    v14 += 8;
    --v15;
  }
  while ( v15 );
  v16 = (_DWORD *)&v2->mFloats[136].mValue;
  v17 = 3i64;
  v18 = 3i64;
  do
  {
    *(_DWORD *)((char *)v16 + v5) = *v16;
    ++v16;
    --v18;
  }
  while ( v18 );
  v3->mIntsRanged[0].mValue = v2->mIntsRanged[0].mValue;
  v3->mIntsRanged[0].mRange = v2->mIntsRanged[0].mRange;
  v3->mIntsRanged[1].mValue = v2->mIntsRanged[1].mValue;
  v3->mIntsRanged[1].mRange = v2->mIntsRanged[1].mRange;
  v3->mIntsRanged[2].mValue = v2->mIntsRanged[2].mValue;
  v3->mIntsRanged[2].mRange = v2->mIntsRanged[2].mRange;
  v3->mIntsRanged[3].mValue = v2->mIntsRanged[3].mValue;
  v3->mIntsRanged[3].mRange = v2->mIntsRanged[3].mRange;
  v3->mIntsRanged[4].mValue = v2->mIntsRanged[4].mValue;
  v3->mIntsRanged[4].mRange = v2->mIntsRanged[4].mRange;
  v3->mIntsRanged[5].mValue = v2->mIntsRanged[5].mValue;
  v3->mIntsRanged[5].mRange = v2->mIntsRanged[5].mRange;
  v3->mIntsRanged[6].mValue = v2->mIntsRanged[6].mValue;
  v3->mIntsRanged[6].mRange = v2->mIntsRanged[6].mRange;
  v3->mFloatsRanged[0].mValue = v2->mFloatsRanged[0].mValue;
  v3->mFloatsRanged[0].mRange = v2->mFloatsRanged[0].mRange;
  v19 = (const char **)&v2->mStrings[0].mValue.mData;
  v20 = (UFG::qString *)v3->mStrings;
  v21 = 25i64;
  do
  {
    UFG::qString::Set(v20, *v19, *((_DWORD *)v19 - 1), 0i64, 0);
    ++v20;
    v19 += 5;
    --v21;
  }
  while ( v21 );
  v22 = &v3->mBinaries[0].mSize;
  do
  {
    if ( *v22 > 0 )
      operator delete[](*((void **)v22 - 1));
    *((_QWORD *)v22 - 1) = 0i64;
    *v22 = 0;
    v23 = *(unsigned int *)((char *)v22 + v8);
    *v22 = v23;
    if ( v23 )
    {
      v24 = UFG::qMalloc(v23, "Binary", 0i64);
      UFG::qMemCopy(v24, *(const void **)((char *)v22 + v8 - 8), *v22);
      *((_QWORD *)v22 - 1) = v24;
    }
    else
    {
      *((_QWORD *)v22 - 1) = 0i64;
    }
    v22 += 4;
    --v17;
  }
  while ( v17 );
  v25 = v3->mpMapBools;
  v26 = 93i64;
  do
  {
    v27 = *v25;
    if ( *v25 )
    {
      UFG::PersistentData::MapBool::~MapBool(*v25);
      operator delete[](v27);
    }
    v28 = UFG::qMalloc(0x30ui64, "GameSnapshot", 0i64);
    v29 = (UFG::PersistentData::MapBool *)v28;
    if ( v28 )
    {
      v30 = *(__int64 *)((char *)v25 + v8);
      LODWORD(v28->mNext) = *(_DWORD *)v30;
      v31 = (UFG::qArray<UFG::PersistentData::KeyValue,0> *)&v28[1];
      v31->p = 0i64;
      *(_QWORD *)&v31->size = 0i64;
      v28[4].mNext = 0i64;
      v28[3].mNext = 0i64;
      LODWORD(v28[5].mNext) = *(_DWORD *)(v30 + 40);
      v32 = (int)v28->mNext;
      if ( v32 )
      {
        if ( (unsigned int)(v32 - 1) <= 1 )
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
    *v25 = v29;
    ++v25;
    --v26;
  }
  while ( v26 );
  v33 = v3->mpMapInts;
  v34 = 47i64;
  do
  {
    v35 = *v33;
    if ( *v33 )
    {
      v36 = v35->mValues.p;
      if ( v36 )
      {
        v37 = (char *)&v36[-1].4;
        `eh vector destructor iterator'(v36, 8ui64, v36[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v37);
      }
      v35->mValues.p = 0i64;
      *(_QWORD *)&v35->mValues.size = 0i64;
      v38 = v35->mValues.p;
      if ( v38 )
      {
        v39 = (char *)&v38[-1].4;
        `eh vector destructor iterator'(v38, 8ui64, v38[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v39);
      }
      v35->mValues.p = 0i64;
      *(_QWORD *)&v35->mValues.size = 0i64;
      operator delete[](v35);
    }
    v40 = (UFG::qArray<UFG::PersistentData::KeyValue,0> *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    v41 = v40;
    if ( v40 )
    {
      v42 = *(UFG::qArray<UFG::PersistentData::KeyValue,0> **)((char *)v33 + v8);
      v40->p = 0i64;
      *(_QWORD *)&v40->size = 0i64;
      v40[1].size = v42[1].size;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Clone(v42, v40);
    }
    else
    {
      v41 = 0i64;
    }
    *v33 = (UFG::PersistentData::MapInt *)v41;
    ++v33;
    --v34;
  }
  while ( v34 );
  v43 = v3->mpMapUInt64s[0];
  if ( v43 )
  {
    v44 = v43->mValues.p;
    if ( v44 )
    {
      v45 = (char *)&v44[-1].mIntValue;
      `eh vector destructor iterator'(v44, 0x10ui64, v44[-1].mIntValue, (void (__fastcall *)(void *))_);
      operator delete[](v45);
    }
    v43->mValues.p = 0i64;
    *(_QWORD *)&v43->mValues.size = 0i64;
    v46 = v43->mValues.p;
    if ( v46 )
    {
      v47 = (char *)&v46[-1].mIntValue;
      `eh vector destructor iterator'(v46, 0x10ui64, v46[-1].mIntValue, (void (__fastcall *)(void *))_);
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
    v50 = &v2->mpMapUInt64s[0]->mValues;
    v48->p = 0i64;
    *(_QWORD *)&v48->size = 0i64;
    v48[1].size = v50[1].size;
    UFG::qArray<UFG::PersistentData::KeyValue64,0>::Clone(v50, v48);
  }
  else
  {
    v49 = 0i64;
  }
  v3->mpMapUInt64s[0] = v49;
  v51 = v3->mpMapFloats;
  v52 = 18i64;
  do
  {
    v53 = *v51;
    if ( *v51 )
    {
      v54 = v53->mValues.p;
      if ( v54 )
      {
        v55 = (char *)&v54[-1].4;
        `eh vector destructor iterator'(v54, 8ui64, v54[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v55);
      }
      v53->mValues.p = 0i64;
      *(_QWORD *)&v53->mValues.size = 0i64;
      v56 = v53->mValues.p;
      if ( v56 )
      {
        v57 = (char *)&v56[-1].4;
        `eh vector destructor iterator'(v56, 8ui64, v56[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v57);
      }
      v53->mValues.p = 0i64;
      *(_QWORD *)&v53->mValues.size = 0i64;
      operator delete[](v53);
    }
    v58 = (UFG::qArray<UFG::PersistentData::KeyValue,0> *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    v59 = v58;
    if ( v58 )
    {
      v60 = *(UFG::qArray<UFG::PersistentData::KeyValue,0> **)((char *)v51 + v8);
      v58->p = 0i64;
      *(_QWORD *)&v58->size = 0i64;
      v58[1].size = v60[1].size;
      UFG::qArray<UFG::PersistentData::KeyValue,0>::Clone(v60, v58);
    }
    else
    {
      v59 = 0i64;
    }
    *v51 = (UFG::PersistentData::MapFloat *)v59;
    ++v51;
    --v52;
  }
  while ( v52 );
  v61 = v3->mpMapBinaries;
  v62 = 2i64;
  do
  {
    v63 = *v61;
    if ( *v61 )
    {
      UFG::PersistentData::MapBinary::Clear(v63);
      v64 = v63->mValues.p;
      if ( v64 )
      {
        v65 = &v64[-1].mBinary.mSize;
        `eh vector destructor iterator'(v64, 0x18ui64, v64[-1].mBinary.mSize, (void (__fastcall *)(void *))_);
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
        *(UFG::PersistentData::MapBinary **)((char *)v61 + v8));
    else
      v67 = 0i64;
    *v61 = v67;
    ++v61;
    --v62;
  }
  while ( v62 );
  UFG::GameSnapshot::CreateList(v3);
  v68 = v3->mpList[0];
  v69 = v2->mpList[0];
  v68->mType = v69->mType;
  switch ( v69->mType )
  {
    case 1:
      UFG::qArray<bool,0>::Clone(v69->mBoolList, v68->mBoolList);
      break;
    case 2:
      UFG::qArray<enum  DNA::PropertyState::Enum,0>::Clone(
        (UFG::qArray<unsigned long,0> *)v69->mIntList,
        (UFG::qArray<unsigned long,0> *)v68->mIntList);
      break;
    case 3:
      UFG::qArray<UFG::qPropertySet *,0>::Clone(
        (UFG::qArray<UFG::RoadNetworkNode *,0> *)v69->mIntList,
        (UFG::qArray<UFG::RoadNetworkNode *,0> *)v68->mIntList);
      break;
    case 4:
      UFG::qArray<float,0>::Clone(v69->mFloatList, v68->mFloatList);
      break;
  }
}

// File Line: 242
// RVA: 0x4905E0
void __fastcall UFG::GameSnapshot::~GameSnapshot(UFG::GameSnapshot *this)
{
  UFG::GameSnapshot *v1; // r14
  UFG::PersistentData::Binary *v2; // rbx
  signed __int64 v3; // rdi
  UFG::PersistentData::MapBool **v4; // rdi
  signed __int64 v5; // rsi
  UFG::PersistentData::MapBool *v6; // rbx
  UFG::PersistentData::MapInt **v7; // rsi
  signed __int64 v8; // rbp
  UFG::PersistentData::MapInt *v9; // rdi
  UFG::PersistentData::KeyValue *v10; // rcx
  char *v11; // rbx
  UFG::PersistentData::KeyValue *v12; // rcx
  char *v13; // rbx
  UFG::PersistentData::MapUInt64 *v14; // rdi
  UFG::PersistentData::KeyValue64 *v15; // rcx
  char *v16; // rbx
  UFG::PersistentData::KeyValue64 *v17; // rcx
  char *v18; // rbx
  UFG::PersistentData::MapFloat **v19; // rsi
  signed __int64 v20; // rbp
  UFG::PersistentData::MapFloat *v21; // rdi
  UFG::PersistentData::KeyValue *v22; // rcx
  char *v23; // rbx
  UFG::PersistentData::KeyValue *v24; // rcx
  char *v25; // rbx
  UFG::PersistentData::MapBinary **v26; // rsi
  signed __int64 v27; // rbp
  UFG::PersistentData::MapBinary *v28; // rdi
  UFG::PersistentData::KeyBinary *v29; // rcx
  unsigned int *v30; // rbx
  UFG::PersistentData::List *v31; // rdi
  UFG::qArray<long,0> *v32; // rbx
  int *v33; // rcx

  v1 = this;
  v2 = this->mBinaries;
  v3 = 3i64;
  do
  {
    if ( v2->mSize > 0 )
      operator delete[](v2->mpBuffer);
    v2->mpBuffer = 0i64;
    v2->mSize = 0;
    ++v2;
    --v3;
  }
  while ( v3 );
  v4 = v1->mpMapBools;
  v5 = 93i64;
  do
  {
    v6 = *v4;
    if ( *v4 )
    {
      UFG::PersistentData::MapBool::~MapBool(*v4);
      operator delete[](v6);
    }
    ++v4;
    --v5;
  }
  while ( v5 );
  v7 = v1->mpMapInts;
  v8 = 47i64;
  do
  {
    v9 = *v7;
    if ( *v7 )
    {
      v10 = v9->mValues.p;
      if ( v10 )
      {
        v11 = (char *)&v10[-1].4;
        `eh vector destructor iterator'(v10, 8ui64, v10[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v11);
      }
      v9->mValues.p = 0i64;
      *(_QWORD *)&v9->mValues.size = 0i64;
      v12 = v9->mValues.p;
      if ( v12 )
      {
        v13 = (char *)&v12[-1].4;
        `eh vector destructor iterator'(v12, 8ui64, v12[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v13);
      }
      v9->mValues.p = 0i64;
      *(_QWORD *)&v9->mValues.size = 0i64;
      operator delete[](v9);
    }
    ++v7;
    --v8;
  }
  while ( v8 );
  v14 = v1->mpMapUInt64s[0];
  if ( v14 )
  {
    v15 = v14->mValues.p;
    if ( v15 )
    {
      v16 = (char *)&v15[-1].mIntValue;
      `eh vector destructor iterator'(v15, 0x10ui64, v15[-1].mIntValue, (void (__fastcall *)(void *))_);
      operator delete[](v16);
    }
    v14->mValues.p = 0i64;
    *(_QWORD *)&v14->mValues.size = 0i64;
    v17 = v14->mValues.p;
    if ( v17 )
    {
      v18 = (char *)&v17[-1].mIntValue;
      `eh vector destructor iterator'(v17, 0x10ui64, v17[-1].mIntValue, (void (__fastcall *)(void *))_);
      operator delete[](v18);
    }
    v14->mValues.p = 0i64;
    *(_QWORD *)&v14->mValues.size = 0i64;
    operator delete[](v14);
  }
  v19 = v1->mpMapFloats;
  v20 = 18i64;
  do
  {
    v21 = *v19;
    if ( *v19 )
    {
      v22 = v21->mValues.p;
      if ( v22 )
      {
        v23 = (char *)&v22[-1].4;
        `eh vector destructor iterator'(v22, 8ui64, v22[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v23);
      }
      v21->mValues.p = 0i64;
      *(_QWORD *)&v21->mValues.size = 0i64;
      v24 = v21->mValues.p;
      if ( v24 )
      {
        v25 = (char *)&v24[-1].4;
        `eh vector destructor iterator'(v24, 8ui64, v24[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v25);
      }
      v21->mValues.p = 0i64;
      *(_QWORD *)&v21->mValues.size = 0i64;
      operator delete[](v21);
    }
    ++v19;
    --v20;
  }
  while ( v20 );
  v26 = v1->mpMapBinaries;
  v27 = 2i64;
  do
  {
    v28 = *v26;
    if ( *v26 )
    {
      UFG::PersistentData::MapBinary::Clear(v28);
      v29 = v28->mValues.p;
      if ( v29 )
      {
        v30 = &v29[-1].mBinary.mSize;
        `eh vector destructor iterator'(v29, 0x18ui64, v29[-1].mBinary.mSize, (void (__fastcall *)(void *))_);
        operator delete[](v30);
      }
      v28->mValues.p = 0i64;
      *(_QWORD *)&v28->mValues.size = 0i64;
      operator delete[](v28);
    }
    ++v26;
    --v27;
  }
  while ( v27 );
  v31 = v1->mpList[0];
  if ( v31 )
  {
    v32 = v31->mIntList;
    if ( v32 && (v31->mType == 1 || v31->mType == 2 || v31->mType == 3 || v31->mType == 4) )
    {
      v33 = v32->p;
      if ( v33 )
        operator delete[](v33);
      v32->p = 0i64;
      *(_QWORD *)&v32->size = 0i64;
      operator delete[](v32);
    }
    operator delete[](v31);
  }
  `eh vector destructor iterator'(v1->mBinaries, 0x10ui64, 3, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(
    v1->mStrings,
    0x28ui64,
    25,
    (void (__fastcall *)(void *))UFG::PersistentData::String::~String);
  `eh vector destructor iterator'(v1->mFloatsRanged, 8ui64, 1, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(v1->mIntsRanged, 8ui64, 7, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(v1->mFloats, 4ui64, 139, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(v1->mUInt64s, 8ui64, 1, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(v1->mInts, 4ui64, 163, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(v1->mBools, 1ui64, 58, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(v1->mIDs, 4ui64, 44, (void (__fastcall *)(void *))_);
  `eh vector destructor iterator'(v1, 0x10ui64, 30, (void (__fastcall *)(void *))UFG::PersistentData::Time::~Time);
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
  signed int v15; // ecx
  const char *v16; // r8
  unsigned int v17; // ecx
  char v18; // dl
  const char *v19; // r8
  char v20; // dl
  signed int v21; // ecx
  const char *v22; // r8
  char v23; // dl
  signed int v24; // ecx
  const char *v25; // r8
  char v26; // dl
  unsigned int v27; // ecx
  const char *v28; // r8
  char v29; // dl
  const char *v30; // r8
  signed int v31; // ecx
  char v32; // dl
  const char *v33; // r8
  unsigned int v34; // ecx
  signed int v35; // ecx
  char v36; // dl
  const char *v37; // r8
  char v38; // dl
  signed int v39; // ecx
  const char *v40; // r8
  char v41; // dl
  signed int v42; // ecx
  const char *v43; // r8
  char v44; // dl
  const char *v45; // r8
  signed int v46; // ecx
  char v47; // dl
  const char *v48; // r8
  signed int v49; // ecx
  char v50; // dl
  signed int v51; // ecx
  const char *v52; // r8
  const char *v53; // r9
  const char *v54; // r8
  char v55; // dl
  signed int v56; // ecx
  char v57; // dl
  const char *v58; // r8
  unsigned int v59; // ecx
  char v60; // dl
  signed int v61; // ecx
  const char *v62; // r8
  char v63; // dl
  signed int v64; // ecx
  const char *v65; // r8
  char v66; // dl
  signed int v67; // ecx
  char v68; // dl
  const char *v69; // r8
  signed int v70; // ecx
  char v71; // dl
  signed int v72; // ecx
  signed int v73; // edx
  char v74; // cl

  v0 = "F";
  v1 = 8;
  v2 = 70;
  v3 = "F";
  do
  {
    if ( (v2 - 70) & 0xDF )
    {
      if ( !((v2 - 67) & 0xDF) )
        v1 |= 1u;
    }
    else
    {
      v1 |= 2u;
    }
    v2 = (v3++)[1];
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
    if ( (v4 - 70) & 0xDF )
    {
      if ( !((v4 - 67) & 0xDF) )
        v6 |= 1u;
    }
    else
    {
      v6 |= 2u;
    }
    v4 = (v5++)[1];
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
    if ( (v10 - 70) & 0xDF )
    {
      if ( !((v10 - 67) & 0xDF) )
        v9 |= 1u;
    }
    else
    {
      v9 |= 2u;
    }
    v10 = (v8++)[1];
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
    if ( (v11 - 70) & 0xDF )
    {
      if ( !((v11 - 67) & 0xDF) )
        v12 |= 1u;
    }
    else
    {
      v12 |= 2u;
    }
    v11 = (v13++)[1];
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
    if ( (v14 - 70) & 0xDF )
    {
      if ( !((v14 - 67) & 0xDF) )
        v15 |= 1u;
    }
    else
    {
      v15 |= 2u;
    }
    v14 = (v16++)[1];
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
    if ( (v18 - 70) & 0xDF )
    {
      if ( !((v18 - 67) & 0xDF) )
        v17 |= 1u;
    }
    else
    {
      v17 |= 2u;
    }
    v18 = (v19++)[1];
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
    if ( (v20 - 70) & 0xDF )
    {
      if ( !((v20 - 67) & 0xDF) )
        v21 |= 1u;
    }
    else
    {
      v21 |= 2u;
    }
    v20 = (v22++)[1];
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
    if ( (v23 - 70) & 0xDF )
    {
      if ( !((v23 - 67) & 0xDF) )
        v24 |= 1u;
    }
    else
    {
      v24 |= 2u;
    }
    v23 = (v25++)[1];
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
    if ( (v26 - 70) & 0xDF )
    {
      if ( !((v26 - 67) & 0xDF) )
        v27 |= 1u;
    }
    else
    {
      v27 |= 2u;
    }
    v26 = (v28++)[1];
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
    if ( (v29 - 70) & 0xDF )
    {
      if ( !((v29 - 67) & 0xDF) )
        v31 |= 1u;
    }
    else
    {
      v31 |= 2u;
    }
    v29 = (v30++)[1];
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
    if ( (v32 - 70) & 0xDF )
    {
      if ( !((v32 - 67) & 0xDF) )
        v34 |= 1u;
    }
    else
    {
      v34 |= 2u;
    }
    v32 = (v33++)[1];
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
    if ( (v36 - 70) & 0xDF )
    {
      if ( !((v36 - 67) & 0xDF) )
        v35 |= 1u;
    }
    else
    {
      v35 |= 2u;
    }
    v36 = (v37++)[1];
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
    if ( (v38 - 70) & 0xDF )
    {
      if ( !((v38 - 67) & 0xDF) )
        v39 |= 1u;
    }
    else
    {
      v39 |= 2u;
    }
    v38 = (v40++)[1];
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
    if ( (v41 - 70) & 0xDF )
    {
      if ( !((v41 - 67) & 0xDF) )
        v42 |= 1u;
    }
    else
    {
      v42 |= 2u;
    }
    v41 = (v43++)[1];
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
    if ( (v44 - 70) & 0xDF )
    {
      if ( !((v44 - 67) & 0xDF) )
        v46 |= 1u;
    }
    else
    {
      v46 |= 2u;
    }
    v44 = (v45++)[1];
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
    if ( (v47 - 70) & 0xDF )
    {
      if ( !((v47 - 67) & 0xDF) )
        v49 |= 1u;
    }
    else
    {
      v49 |= 2u;
    }
    v47 = (v48++)[1];
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
    if ( (v50 - 70) & 0xDF )
    {
      if ( !((v50 - 67) & 0xDF) )
        v51 |= 1u;
    }
    else
    {
      v51 |= 2u;
    }
    v50 = (v52++)[1];
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
    if ( (v55 - 70) & 0xDF )
    {
      if ( !((v55 - 67) & 0xDF) )
        v56 |= 1u;
    }
    else
    {
      v56 |= 2u;
    }
    v55 = (v54++)[1];
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
    if ( (v57 - 70) & 0xDF )
    {
      if ( !((v57 - 67) & 0xDF) )
        v59 |= 1u;
    }
    else
    {
      v59 |= 2u;
    }
    v57 = (v58++)[1];
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
    if ( (v60 - 70) & 0xDF )
    {
      if ( !((v60 - 67) & 0xDF) )
        v61 |= 1u;
    }
    else
    {
      v61 |= 2u;
    }
    v60 = (v62++)[1];
  }
  while ( v60 );
  dword_142405BBC = v61;
  dword_142405BC0 = v61;
  v63 = 70;
  v64 = 0x400000;
  v65 = "FC";
  do
  {
    if ( (v63 - 70) & 0xDF )
    {
      if ( !((v63 - 67) & 0xDF) )
        v64 |= 1u;
    }
    else
    {
      v64 |= 2u;
    }
    v63 = (v65++)[1];
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
    if ( (v66 - 70) & 0xDF )
    {
      if ( !((v66 - 67) & 0xDF) )
        v67 |= 1u;
    }
    else
    {
      v67 |= 2u;
    }
    v66 = (v53++)[1];
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
    if ( (v68 - 70) & 0xDF )
    {
      if ( !((v68 - 67) & 0xDF) )
        v70 |= 1u;
    }
    else
    {
      v70 |= 2u;
    }
    v68 = (v69++)[1];
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
    if ( (v71 - 70) & 0xDF )
    {
      if ( !((v71 - 67) & 0xDF) )
        v72 |= 1u;
    }
    else
    {
      v72 |= 2u;
    }
    v71 = (v7++)[1];
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
  dword_142405F14 = v72;
  v73 = 0x4000000;
  v74 = 70;
  do
  {
    if ( (v74 - 70) & 0xDF )
    {
      if ( !((v74 - 67) & 0xDF) )
        v73 |= 1u;
    }
    else
    {
      v73 |= 2u;
    }
    v74 = (v0++)[1];
  }
  while ( v74 );
  dword_14240563C = v73;
  dword_142405C70 = v73;
} dword_142405EF8 = v70;
  dword_142405EFC = v70;
  dword_142405F00 = v70;
  dword_142405F04 = v70;
  v71 = 70;
  v72 = 0x2000000;
  do
  {
    if ( (v71 - 70) & 0xDF )
    {
      if ( !((v71 - 67) & 0xDF) )
        v72 |= 1u;
    }
    else
    {
      v72 |= 2u;
    }
    v71 = (v7++)[1];
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
  dword_142405F14 = v72;
  v73 = 0x4000000;
  v74 = 70;
  do
  {
    if ( (v74 - 70) & 0xDF )
    {
      if ( !((v74 - 67) & 0xDF) )
        v73 |= 1u;
    }
    else
    {
      v73 |= 2u;
    }
    v74 = (v0++)[1];
  }
  while ( v74 );
  dword_14240563C

// File Line: 321
// RVA: 0x498AC0
void __fastcall UFG::GameSnapshot::CommitByFilter(UFG::GameSnapshot *this, UFG::GameSnapshot *pRecentSnapshot, unsigned int filterMask, unsigned int persistenceMask, unsigned int rejectMask)
{
  __int64 v5; // rdi
  __int64 v6; // r14
  UFG::GameSnapshot *v7; // r13
  UFG::GameSnapshot *v8; // rsi
  UFG::GameSnapshot *v9; // r9
  unsigned int *v10; // r11
  signed __int64 v11; // r8
  signed __int64 v12; // rbx
  unsigned int v13; // er10
  UFG::PersistentData::ID *v14; // rcx
  signed __int64 v15; // r10
  signed __int64 v16; // r9
  int v17; // edx
  __int64 v18; // rcx
  signed __int64 v19; // r9
  unsigned int v20; // edx
  UFG::PersistentData::Int *v21; // rcx
  signed __int64 v22; // r9
  int v23; // edx
  UFG::PersistentData::Float *v24; // rcx
  signed __int64 v25; // r9
  int v26; // edx
  int v27; // edx
  int v28; // edx
  int v29; // edx
  int v30; // edx
  int v31; // edx
  int v32; // edx
  int v33; // edx
  _DWORD *v34; // rcx
  signed __int64 v35; // r13
  signed __int64 v36; // r9
  int v37; // edx
  unsigned int *v38; // r8
  int *v39; // rcx
  signed __int64 v40; // r10
  signed __int64 v41; // r9
  unsigned int v42; // edx
  unsigned int *v43; // rsi
  const char **v44; // rbx
  UFG::qString *v45; // r15
  signed __int64 v46; // r12
  unsigned int v47; // ecx
  unsigned int *v48; // r15
  unsigned int *v49; // rsi
  unsigned int v50; // ecx
  unsigned int v51; // eax
  UFG::allocator::free_link *v52; // rbx
  unsigned int *v53; // r15
  UFG::PersistentData::MapBool **v54; // rsi
  signed __int64 v55; // r12
  unsigned int v56; // ecx
  UFG::PersistentData::MapBool *v57; // rbx
  UFG::allocator::free_link *v58; // rbx
  __int64 v59; // r8
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v60; // rdx
  unsigned int *v61; // r12
  _QWORD **v62; // r15
  signed __int64 v63; // r13
  unsigned int v64; // ecx
  _QWORD *v65; // rsi
  char *v66; // rcx
  char *v67; // rbx
  char *v68; // rcx
  char *v69; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v70; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v71; // rcx
  UFG::PersistentData::MapUInt64 *v72; // rsi
  UFG::PersistentData::KeyValue64 *v73; // rcx
  char *v74; // rbx
  UFG::PersistentData::KeyValue64 *v75; // rcx
  char *v76; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue64,0> *v77; // rax
  UFG::PersistentData::MapUInt64 *v78; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue64,0> *v79; // rcx
  unsigned int *v80; // r12
  _QWORD **v81; // r15
  signed __int64 v82; // r13
  unsigned int v83; // ecx
  _QWORD *v84; // rsi
  char *v85; // rcx
  char *v86; // rbx
  char *v87; // rcx
  char *v88; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v89; // rbx
  UFG::qArray<UFG::PersistentData::KeyValue,0> *v90; // rcx
  unsigned int *v91; // r12
  UFG::PersistentData::MapBinary **v92; // r15
  signed __int64 v93; // r13
  unsigned int v94; // ecx
  UFG::PersistentData::MapBinary *v95; // rsi
  UFG::PersistentData::KeyBinary *v96; // rcx
  unsigned int *v97; // rbx
  UFG::allocator::free_link *v98; // rax
  UFG::PersistentData::MapBinary *v99; // rax
  UFG::PersistentData::List *v100; // rdx
  UFG::PersistentData::List *v101; // rcx
  signed __int64 v102; // [rsp+30h] [rbp-58h]
  UFG::GameSnapshot *v103; // [rsp+90h] [rbp+8h]
  UFG::GameSnapshot *v104; // [rsp+98h] [rbp+10h]

  v104 = pRecentSnapshot;
  v103 = this;
  v5 = persistenceMask;
  v6 = filterMask;
  v7 = pRecentSnapshot;
  v8 = this;
  v9 = pRecentSnapshot;
  v10 = UFG::GameSnapshot::sDefinitionTimes;
  v11 = (char *)this - (char *)pRecentSnapshot;
  v12 = 30i64;
  do
  {
    v13 = *v10;
    if ( *v10 & (unsigned int)v6 && ((unsigned int)v5 & v13) == (_DWORD)v5 && !(v13 & rejectMask) )
    {
      *(unsigned __int64 *)((char *)&v9->mTimes[0].mTimer.mTimestamp + v11) = v9->mTimes[0].mTimer.mTimestamp;
      *(_QWORD *)((char *)&v9->mTimes[0].mTimer.mElapsedTime + v11) = *(_QWORD *)&v9->mTimes[0].mTimer.mElapsedTime;
    }
    ++v10;
    v9 = (UFG::GameSnapshot *)((char *)v9 + 16);
    --v12;
  }
  while ( v12 );
  v14 = pRecentSnapshot->mIDs;
  v15 = (char *)UFG::GameSnapshot::sDefinitionIDs - (char *)pRecentSnapshot;
  v16 = 44i64;
  do
  {
    v17 = *(unsigned int *)((char *)&v14[-120].mValue.mUID + v15);
    if ( v17 & (unsigned int)v6 && ((unsigned int)v5 & v17) == (_DWORD)v5 && !(v17 & rejectMask) )
      *(UFG::PersistentData::ID *)((char *)v14 + v11) = (UFG::PersistentData::ID)v14->mValue.mUID;
    ++v14;
    --v16;
  }
  while ( v16 );
  v18 = 0i64;
  v19 = 58i64;
  do
  {
    v20 = UFG::GameSnapshot::sDefinitionBools[v18];
    if ( v20 & (unsigned int)v6 && ((unsigned int)v5 & v20) == (_DWORD)v5 && !(v20 & rejectMask) )
      v8->mBools[v18].mValue = v7->mBools[v18].mValue;
    ++v18;
    --v19;
  }
  while ( v19 );
  v21 = v7->mInts;
  v22 = 163i64;
  do
  {
    v23 = *(int *)((char *)&v21[-179].mValue + (char *)UFG::GameSnapshot::sDefinitionInts - (char *)v7);
    if ( v23 & (unsigned int)v6 && ((unsigned int)v5 & v23) == (_DWORD)v5 && !(v23 & rejectMask) )
      *(UFG::PersistentData::Int *)((char *)v21 + v11) = (UFG::PersistentData::Int)v21->mValue;
    ++v21;
    --v22;
  }
  while ( v22 );
  if ( v6 & UFG::GameSnapshot::sDefinitionUInt64s[0]
    && (UFG::GameSnapshot::sDefinitionUInt64s[0] & v5) == v5
    && !(rejectMask & UFG::GameSnapshot::sDefinitionUInt64s[0]) )
  {
    v8->mUInt64s[0].mValue = v7->mUInt64s[0].mValue;
  }
  v24 = v7->mFloats;
  v25 = 17i64;
  do
  {
    v26 = *(_DWORD *)((char *)&v24[-344].mValue + (char *)UFG::GameSnapshot::sDefinitionFloats - (char *)v7);
    if ( v26 & (unsigned int)v6 && ((unsigned int)v5 & v26) == (_DWORD)v5 && !(v26 & rejectMask) )
      *(UFG::PersistentData::Float *)((char *)v24 + v11) = LODWORD(v24->mValue);
    v27 = *(_DWORD *)((char *)&v24[-344].mValue + (char *)&dword_1424059C4 - (char *)v7);
    if ( v27 & (unsigned int)v6 && ((unsigned int)v5 & v27) == (_DWORD)v5 && !(v27 & rejectMask) )
      *(UFG::PersistentData::Float *)((char *)v24 + v11 + 4) = v24[1];
    v28 = *(_DWORD *)((char *)&v24[-344].mValue + (char *)&dword_1424059C8 - (char *)v7);
    if ( v28 & (unsigned int)v6 && ((unsigned int)v5 & v28) == (_DWORD)v5 && !(v28 & rejectMask) )
      *(UFG::PersistentData::Float *)((char *)v24 + v11 + 8) = v24[2];
    v29 = *(_DWORD *)((char *)&v24[-344].mValue + (char *)&dword_1424059CC - (char *)v7);
    if ( v29 & (unsigned int)v6 && ((unsigned int)v5 & v29) == (_DWORD)v5 && !(v29 & rejectMask) )
      *(UFG::PersistentData::Float *)((char *)v24 + v11 + 12) = v24[3];
    v30 = *(_DWORD *)((char *)&v24[-344].mValue + (char *)&dword_1424059D0 - (char *)v7);
    if ( v30 & (unsigned int)v6 && ((unsigned int)v5 & v30) == (_DWORD)v5 && !(v30 & rejectMask) )
      *(UFG::PersistentData::Float *)((char *)v24 + v11 + 16) = v24[4];
    v31 = *(_DWORD *)((char *)&v24[-344].mValue + (char *)&dword_1424059D4 - (char *)v7);
    if ( v31 & (unsigned int)v6 && ((unsigned int)v5 & v31) == (_DWORD)v5 && !(v31 & rejectMask) )
      *(UFG::PersistentData::Float *)((char *)v24 + v11 + 20) = v24[5];
    v32 = *(_DWORD *)((char *)&v24[-344].mValue + (char *)&dword_1424059D8 - (char *)v104);
    if ( v32 & (unsigned int)v6 && ((unsigned int)v5 & v32) == (_DWORD)v5 && !(v32 & rejectMask) )
      *(UFG::PersistentData::Float *)((char *)v24 + v11 + 24) = v24[6];
    v33 = *(_DWORD *)((char *)&v24[-344].mValue + (char *)&dword_1424059DC - (char *)v104);
    if ( v33 & (unsigned int)v6 && ((unsigned int)v5 & v33) == (_DWORD)v5 && !(v33 & rejectMask) )
      *(UFG::PersistentData::Float *)((char *)v24 + v11 + 28) = v24[7];
    v24 += 8;
    --v25;
  }
  while ( v25 );
  v34 = (_DWORD *)&v104->mFloats[136].mValue;
  v35 = 3i64;
  v36 = 3i64;
  do
  {
    v37 = *(_DWORD *)((char *)v34 + (char *)&dword_142405BE0 - (char *)v104 - 1920);
    if ( v37 & (unsigned int)v6 && ((unsigned int)v5 & v37) == (_DWORD)v5 && !(v37 & rejectMask) )
      *(_DWORD *)((char *)v34 + v11) = *v34;
    ++v34;
    --v36;
  }
  while ( v36 );
  v38 = UFG::GameSnapshot::sDefinitionIntsRanged;
  v39 = &v103->mIntsRanged[0].mRange;
  v40 = (char *)v104 - (char *)v103;
  v102 = (char *)v104 - (char *)v103;
  v41 = 7i64;
  do
  {
    v42 = *v38;
    if ( *v38 & (unsigned int)v6 && ((unsigned int)v5 & v42) == (_DWORD)v5 && !(v42 & rejectMask) )
    {
      *(v39 - 1) = *(int *)((char *)v39 + v40 - 4);
      *v39 = *(int *)((char *)v39 + v40);
    }
    ++v38;
    v39 += 2;
    --v41;
  }
  while ( v41 );
  if ( UFG::GameSnapshot::sDefinitionFloatsRanged[0] & (unsigned int)v6
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionFloatsRanged[0]) == (_DWORD)v5
    && !(UFG::GameSnapshot::sDefinitionFloatsRanged[0] & rejectMask) )
  {
    v103->mFloatsRanged[0].mValue = v104->mFloatsRanged[0].mValue;
    v103->mFloatsRanged[0].mRange = v104->mFloatsRanged[0].mRange;
  }
  v43 = UFG::GameSnapshot::sDefinitionStrings;
  v44 = (const char **)&v104->mStrings[0].mValue.mData;
  v45 = (UFG::qString *)v103->mStrings;
  v46 = 25i64;
  do
  {
    v47 = *v43;
    if ( *v43 & (unsigned int)v6 && ((unsigned int)v5 & v47) == (_DWORD)v5 && !(v47 & rejectMask) )
      UFG::qString::Set(v45, *v44, *((_DWORD *)v44 - 1), 0i64, 0);
    ++v45;
    v44 += 5;
    ++v43;
    --v46;
  }
  while ( v46 );
  v48 = UFG::GameSnapshot::sDefinitionBinaries;
  v49 = &v103->mBinaries[0].mSize;
  do
  {
    v50 = *v48;
    if ( *v48 & (unsigned int)v6 && ((unsigned int)v5 & v50) == (_DWORD)v5 && !(v50 & rejectMask) )
    {
      if ( *v49 )
        operator delete[](*((void **)v49 - 1));
      *((_QWORD *)v49 - 1) = 0i64;
      *v49 = 0;
      v51 = *(unsigned int *)((char *)v49 + v102);
      *v49 = v51;
      if ( v51 )
      {
        v52 = UFG::qMalloc(v51, "Binary", 0i64);
        UFG::qMemCopy(v52, *(const void **)((char *)v49 + v102 - 8), *v49);
        *((_QWORD *)v49 - 1) = v52;
      }
      else
      {
        *((_QWORD *)v49 - 1) = 0i64;
      }
    }
    ++v48;
    v49 += 4;
    --v35;
  }
  while ( v35 );
  v53 = UFG::GameSnapshot::sDefinitionMapBools;
  v54 = v103->mpMapBools;
  v55 = 93i64;
  do
  {
    v56 = *v53;
    if ( *v53 & (unsigned int)v6 && ((unsigned int)v5 & v56) == (_DWORD)v5 && !(v56 & rejectMask) )
    {
      v57 = *v54;
      if ( *v54 )
      {
        UFG::PersistentData::MapBool::~MapBool(*v54);
        operator delete[](v57);
      }
      v58 = UFG::qMalloc(0x30ui64, "GameSnapshot", 0i64);
      if ( v58 )
      {
        v59 = *(__int64 *)((char *)v54 + v102);
        LODWORD(v58->mNext) = *(_DWORD *)v59;
        v60 = (UFG::qArray<UFG::PersistentData::KeyValue,0> *)&v58[1];
        v60->p = 0i64;
        *(_QWORD *)&v60->size = 0i64;
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
            v60);
        }
      }
      else
      {
        v58 = 0i64;
      }
      *v54 = (UFG::PersistentData::MapBool *)v58;
    }
    ++v54;
    ++v53;
    --v55;
  }
  while ( v55 );
  v61 = UFG::GameSnapshot::sDefinitionMapInts;
  v62 = (_QWORD **)v103->mpMapInts;
  v63 = 47i64;
  do
  {
    v64 = *v61;
    if ( *v61 & (unsigned int)v6 && ((unsigned int)v5 & v64) == (_DWORD)v5 && !(v64 & rejectMask) )
    {
      v65 = *v62;
      if ( *v62 )
      {
        v66 = (char *)v65[1];
        if ( v66 )
        {
          v67 = v66 - 4;
          `eh vector destructor iterator'(v66, 8ui64, *((_DWORD *)v66 - 1), (void (__fastcall *)(void *))_);
          operator delete[](v67);
        }
        v65[1] = 0i64;
        *v65 = 0i64;
        v68 = (char *)v65[1];
        if ( v68 )
        {
          v69 = v68 - 4;
          `eh vector destructor iterator'(v68, 8ui64, *((_DWORD *)v68 - 1), (void (__fastcall *)(void *))_);
          operator delete[](v69);
        }
        v65[1] = 0i64;
        *v65 = 0i64;
        operator delete[](v65);
      }
      v70 = (UFG::qArray<UFG::PersistentData::KeyValue,0> *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
      if ( v70 )
      {
        v71 = *(UFG::qArray<UFG::PersistentData::KeyValue,0> **)((char *)v62 + v102);
        v70->p = 0i64;
        *(_QWORD *)&v70->size = 0i64;
        v70[1].size = v71[1].size;
        UFG::qArray<UFG::PersistentData::KeyValue,0>::Clone(v71, v70);
      }
      else
      {
        v70 = 0i64;
      }
      *v62 = &v70->size;
    }
    ++v62;
    ++v61;
    --v63;
  }
  while ( v63 );
  if ( UFG::GameSnapshot::sDefinitionMapUInt64s[0] & (unsigned int)v6
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionMapUInt64s[0]) == (_DWORD)v5
    && !(UFG::GameSnapshot::sDefinitionMapUInt64s[0] & rejectMask) )
  {
    v72 = v103->mpMapUInt64s[0];
    if ( v72 )
    {
      v73 = v72->mValues.p;
      if ( v73 )
      {
        v74 = (char *)&v73[-1].mIntValue;
        `eh vector destructor iterator'(v73, 0x10ui64, v73[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v74);
      }
      v72->mValues.p = 0i64;
      *(_QWORD *)&v72->mValues.size = 0i64;
      v75 = v72->mValues.p;
      if ( v75 )
      {
        v76 = (char *)&v75[-1].mIntValue;
        `eh vector destructor iterator'(v75, 0x10ui64, v75[-1].mIntValue, (void (__fastcall *)(void *))_);
        operator delete[](v76);
      }
      v72->mValues.p = 0i64;
      *(_QWORD *)&v72->mValues.size = 0i64;
      operator delete[](v72);
    }
    v77 = (UFG::qArray<UFG::PersistentData::KeyValue64,0> *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
    v78 = (UFG::PersistentData::MapUInt64 *)v77;
    if ( v77 )
    {
      v79 = &v104->mpMapUInt64s[0]->mValues;
      v77->p = 0i64;
      *(_QWORD *)&v77->size = 0i64;
      v77[1].size = v79[1].size;
      UFG::qArray<UFG::PersistentData::KeyValue64,0>::Clone(v79, v77);
    }
    else
    {
      v78 = 0i64;
    }
    v103->mpMapUInt64s[0] = v78;
  }
  v80 = UFG::GameSnapshot::sDefinitionMapFloats;
  v81 = (_QWORD **)v103->mpMapFloats;
  v82 = 18i64;
  do
  {
    v83 = *v80;
    if ( *v80 & (unsigned int)v6 && ((unsigned int)v5 & v83) == (_DWORD)v5 && !(v83 & rejectMask) )
    {
      v84 = *v81;
      if ( *v81 )
      {
        v85 = (char *)v84[1];
        if ( v85 )
        {
          v86 = v85 - 4;
          `eh vector destructor iterator'(v85, 8ui64, *((_DWORD *)v85 - 1), (void (__fastcall *)(void *))_);
          operator delete[](v86);
        }
        v84[1] = 0i64;
        *v84 = 0i64;
        v87 = (char *)v84[1];
        if ( v87 )
        {
          v88 = v87 - 4;
          `eh vector destructor iterator'(v87, 8ui64, *((_DWORD *)v87 - 1), (void (__fastcall *)(void *))_);
          operator delete[](v88);
        }
        v84[1] = 0i64;
        *v84 = 0i64;
        operator delete[](v84);
      }
      v89 = (UFG::qArray<UFG::PersistentData::KeyValue,0> *)UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
      if ( v89 )
      {
        v90 = *(UFG::qArray<UFG::PersistentData::KeyValue,0> **)((char *)v81 + v102);
        v89->p = 0i64;
        *(_QWORD *)&v89->size = 0i64;
        v89[1].size = v90[1].size;
        UFG::qArray<UFG::PersistentData::KeyValue,0>::Clone(v90, v89);
      }
      else
      {
        v89 = 0i64;
      }
      *v81 = &v89->size;
    }
    ++v81;
    ++v80;
    --v82;
  }
  while ( v82 );
  v91 = UFG::GameSnapshot::sDefinitionMapBinaries;
  v92 = v103->mpMapBinaries;
  v93 = 2i64;
  do
  {
    v94 = *v91;
    if ( *v91 & (unsigned int)v6 && ((unsigned int)v5 & v94) == (_DWORD)v5 && !(v94 & rejectMask) )
    {
      v95 = *v92;
      if ( *v92 )
      {
        UFG::PersistentData::MapBinary::Clear(v95);
        v96 = v95->mValues.p;
        if ( v96 )
        {
          v97 = &v96[-1].mBinary.mSize;
          `eh vector destructor iterator'(v96, 0x18ui64, v96[-1].mBinary.mSize, (void (__fastcall *)(void *))_);
          operator delete[](v97);
        }
        v95->mValues.p = 0i64;
        *(_QWORD *)&v95->mValues.size = 0i64;
        operator delete[](v95);
      }
      v98 = UFG::qMalloc(0x18ui64, "GameSnapshot", 0i64);
      if ( v98 )
        UFG::PersistentData::MapBinary::MapBinary(
          (UFG::PersistentData::MapBinary *)v98,
          *(UFG::PersistentData::MapBinary **)((char *)v92 + v102));
      else
        v99 = 0i64;
      *v92 = v99;
    }
    ++v92;
    ++v91;
    --v93;
  }
  while ( v93 );
  if ( UFG::GameSnapshot::sDefinitionList[0] & (unsigned int)v6
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionList[0]) == (_DWORD)v5
    && !(UFG::GameSnapshot::sDefinitionList[0] & rejectMask) )
  {
    v100 = v103->mpList[0];
    v101 = v104->mpList[0];
    v100->mType = v101->mType;
    switch ( v101->mType )
    {
      case 1:
        UFG::qArray<bool,0>::Clone(v101->mBoolList, v100->mBoolList);
        break;
      case 2:
        UFG::qArray<enum  DNA::PropertyState::Enum,0>::Clone(
          (UFG::qArray<unsigned long,0> *)v101->mIntList,
          (UFG::qArray<unsigned long,0> *)v100->mIntList);
        break;
      case 3:
        UFG::qArray<UFG::qPropertySet *,0>::Clone(
          (UFG::qArray<UFG::RoadNetworkNode *,0> *)v101->mIntList,
          (UFG::qArray<UFG::RoadNetworkNode *,0> *)v100->mIntList);
        break;
      case 4:
        UFG::qArray<float,0>::Clone(v101->mFloatList, v100->mFloatList);
        break;
    }
  }
}

// File Line: 408
// RVA: 0x496160
signed __int64 __fastcall UFG::GameSnapshot::CalculateSerializeSize(UFG::GameSnapshot *this, unsigned int filterMask, unsigned int persistenceMask)
{
  _DWORD *v3; // r9
  UFG::GameSnapshot *v4; // r13
  unsigned int *v5; // r11
  signed __int64 v6; // rbx
  unsigned int v7; // ecx
  unsigned int v8; // er10
  unsigned int v9; // ecx
  unsigned int v10; // er10
  unsigned int *v11; // r11
  signed __int64 v12; // rbx
  int v13; // ecx
  int v14; // er10
  unsigned int *v15; // r11
  signed __int64 v16; // rbx
  int v17; // ecx
  int v18; // er10
  unsigned int *v19; // r11
  signed __int64 v20; // rbx
  int v21; // ecx
  int v22; // er10
  unsigned int *v23; // r11
  signed __int64 v24; // rbx
  int v25; // ecx
  int v26; // er10
  unsigned int *v27; // r11
  signed __int64 v28; // rbx
  int v29; // er11
  int v30; // ebx
  unsigned int *v31; // r10
  int *v32; // rcx
  signed __int64 v33; // rdi
  unsigned int v34; // eax
  int v35; // er11
  int v36; // ebx
  unsigned int *v37; // rcx
  unsigned int *v38; // r10
  signed __int64 v39; // rdi
  int v40; // er11
  int v41; // ebx
  unsigned int *v42; // r10
  UFG::PersistentData::MapBool **v43; // rcx
  signed __int64 v44; // rdi
  UFG::PersistentData::MapBool *v45; // rax
  int v46; // eax
  int v47; // ebx
  signed __int64 v48; // rsi
  int v49; // edi
  unsigned int *v50; // r10
  UFG::PersistentData::MapInt **v51; // r11
  int v52; // ecx
  int v53; // ebx
  int v54; // edi
  unsigned int *v55; // r10
  UFG::PersistentData::MapFloat **v56; // r11
  signed __int64 v57; // rsi
  int v58; // ebp
  signed __int64 v59; // r15
  signed __int64 v60; // r14
  int v61; // esi
  unsigned int *v62; // rbx
  UFG::PersistentData::MapBinary **v63; // rdi
  signed int v64; // er10
  unsigned int v65; // eax
  __int64 v66; // r11
  unsigned int *v67; // rcx
  unsigned int v68; // eax
  UFG::PersistentData::List *v69; // rax
  UFG::qArray<long,0> *v70; // r8
  UFG::PersistentData::ListType v71; // ecx
  unsigned int v72; // edx
  signed int v73; // ecx
  int v74; // ecx
  int v75; // ecx
  int v76; // ecx
  __int64 v77; // r8
  int v78; // eax

  v3 = 0i64;
  v4 = this;
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
  qword_142405F50 = 0i64;
  qword_142405F58 = 0i64;
  v7 = 0;
  v8 = 0;
  do
  {
    if ( *v5 & filterMask && (persistenceMask & *v5) == persistenceMask )
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
    if ( *v11 & filterMask && (persistenceMask & *v11) == persistenceMask )
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
    if ( *v15 & filterMask && (persistenceMask & *v15) == persistenceMask )
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
    if ( *v19 & filterMask && (persistenceMask & *v19) == persistenceMask )
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
  if ( filterMask & UFG::GameSnapshot::sDefinitionUInt64s[0]
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
    if ( *v23 & filterMask && (persistenceMask & *v23) == persistenceMask )
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
    if ( *v27 & filterMask && (persistenceMask & *v27) == persistenceMask )
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
  if ( UFG::GameSnapshot::sDefinitionFloatsRanged[0] & filterMask
    && (persistenceMask & UFG::GameSnapshot::sDefinitionFloatsRanged[0]) == persistenceMask )
  {
    HIDWORD(qword_142405F78) += 8;
    ++HIDWORD(qword_142405F38);
  }
  v29 = qword_142405F40;
  v30 = qword_142405F80;
  v31 = UFG::GameSnapshot::sDefinitionStrings;
  v32 = &v4->mStrings[0].mValue.mLength;
  v33 = 25i64;
  do
  {
    if ( *v31 & filterMask && (persistenceMask & *v31) == persistenceMask )
    {
      if ( *v32 <= 0 )
        v34 = 0;
      else
        v34 = (*v32 + 4) & 0xFFFFFFFC;
      v30 += v34 + 4;
      LODWORD(qword_142405F40) = ++v29;
      LODWORD(qword_142405F80) = v30;
    }
    v32 += 10;
    ++v31;
    --v33;
  }
  while ( v33 );
  v35 = HIDWORD(qword_142405F40);
  v36 = HIDWORD(qword_142405F80);
  v37 = UFG::GameSnapshot::sDefinitionBinaries;
  v38 = &v4->mBinaries[0].mSize;
  v39 = 3i64;
  do
  {
    if ( *v37 & filterMask && (persistenceMask & *v37) == persistenceMask )
    {
      v36 += ((*v38 + 3) & 0xFFFFFFFC) + 4;
      HIDWORD(qword_142405F40) = ++v35;
      HIDWORD(qword_142405F80) = v36;
    }
    v38 += 4;
    ++v37;
    --v39;
  }
  while ( v39 );
  v40 = qword_142405F48;
  v41 = qword_142405F88;
  v42 = UFG::GameSnapshot::sDefinitionMapBools;
  v43 = v4->mpMapBools;
  v44 = 93i64;
  do
  {
    if ( *v42 & filterMask && (persistenceMask & *v42) == persistenceMask )
    {
      v45 = *v43;
      if ( (*v43)->mKeepType )
        v46 = 4 * v45->mNames.size + 8;
      else
        v46 = 8 * v45->mValues.size + 8;
      v41 += v46;
      LODWORD(qword_142405F48) = ++v40;
      LODWORD(qword_142405F88) = v41;
    }
    ++v43;
    ++v42;
    --v44;
  }
  while ( v44 );
  v47 = HIDWORD(qword_142405F48);
  v48 = 47i64;
  v49 = HIDWORD(qword_142405F88);
  v50 = UFG::GameSnapshot::sDefinitionMapInts;
  v51 = v4->mpMapInts;
  do
  {
    if ( *v50 & filterMask && (persistenceMask & *v50) == persistenceMask )
    {
      v49 += 8 * (*v51)->mValues.size + 4;
      HIDWORD(qword_142405F48) = ++v47;
      HIDWORD(qword_142405F88) = v49;
    }
    ++v51;
    ++v50;
    --v48;
  }
  while ( v48 );
  if ( UFG::GameSnapshot::sDefinitionMapUInt64s[0] & filterMask
    && (persistenceMask & UFG::GameSnapshot::sDefinitionMapUInt64s[0]) == persistenceMask )
  {
    v52 = 16 * v4->mpMapUInt64s[0]->mValues.size;
    LODWORD(qword_142405F50) = qword_142405F50 + 1;
    LODWORD(qword_142405F90) = qword_142405F90 + 8 + v52;
  }
  v53 = HIDWORD(qword_142405F50);
  v54 = HIDWORD(qword_142405F90);
  v55 = UFG::GameSnapshot::sDefinitionMapFloats;
  v56 = v4->mpMapFloats;
  v57 = 18i64;
  do
  {
    if ( *v55 & filterMask && (persistenceMask & *v55) == persistenceMask )
    {
      v54 += 8 * (*v56)->mValues.size + 4;
      HIDWORD(qword_142405F50) = ++v53;
      HIDWORD(qword_142405F90) = v54;
    }
    ++v56;
    ++v55;
    --v57;
  }
  while ( v57 );
  v58 = qword_142405F98;
  v59 = 2i64;
  v60 = 4i64;
  v61 = qword_142405F58;
  v62 = UFG::GameSnapshot::sDefinitionMapBinaries;
  v63 = v4->mpMapBinaries;
  do
  {
    if ( *v62 & filterMask && (persistenceMask & *v62) == persistenceMask )
    {
      v64 = 4;
      v65 = (*v63)->mValues.size;
      if ( v65 )
      {
        v66 = v65;
        v67 = &(*v63)->mValues.p->mBinary.mSize;
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
      LODWORD(qword_142405F58) = ++v61;
      LODWORD(qword_142405F98) = v58;
    }
    ++v63;
    ++v62;
    --v59;
  }
  while ( v59 );
  if ( UFG::GameSnapshot::sDefinitionList[0] & filterMask
    && (persistenceMask & UFG::GameSnapshot::sDefinitionList[0]) == persistenceMask )
  {
    v69 = v4->mpList[0];
    v70 = v69->mIntList;
    if ( v70 || (v71 = v69->mType) != 0 )
    {
      v71 = v69->mType;
      if ( v69->mType == 1 || v69->mType == 2 || v69->mType == 3 || (v72 = 0, v69->mType == 4) )
        v72 = v70->size;
    }
    else
    {
      v72 = 0;
    }
    if ( v70 || v71 )
    {
      v74 = v71 - 1;
      if ( !v74 )
        goto LABEL_105;
      v75 = v74 - 1;
      if ( !v75 )
        goto LABEL_105;
      v76 = v75 - 1;
      if ( !v76 )
      {
        v73 = 8;
        goto LABEL_99;
      }
      if ( v76 == 1 )
      {
LABEL_105:
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
    ++HIDWORD(qword_142405F58);
    HIDWORD(qword_142405F98) += 8 + v72 * v73;
  }
  LODWORD(v77) = 64;
  do
  {
    v78 = v3[1351620552];
    v3 += 4;
    v77 = (unsigned int)(v3[1351620564]
                       + v3[1351620565]
                       + v3[1351620566]
                       + v3[1351620567]
                       + 40 * (v3[1351620550] + v3[1351620551] + v3[1351620549] + v78)
                       + v77
                       + 16);
    --v60;
  }
  while ( v60 );
  return v77 + 4;
}

// File Line: 509
// RVA: 0x4BA980
char __fastcall UFG::GameSnapshot::SerializeByFilter(UFG::GameSnapshot *this, unsigned int filterMask, unsigned int persistenceMask, char **ppBuffer)
{
  void **v4; // rdi
  __int64 v5; // rsi
  UFG::GameSnapshot *v6; // r15
  int v7; // er8
  int v8; // er9
  int v9; // er10
  int v10; // er11
  unsigned int *v11; // rax
  signed __int64 v12; // rcx
  int v13; // er9
  __int64 v14; // rdx
  signed __int64 v15; // r10
  unsigned int *v16; // r8
  unsigned int v17; // er10
  __int64 *v18; // r11
  _DWORD *v19; // r9
  unsigned int v20; // edx
  __int64 v21; // rax
  signed __int64 v22; // rax
  UFG::qSymbol **v23; // r14
  unsigned int *v24; // rbx
  signed __int64 v25; // r12
  unsigned int v26; // er13
  int v27; // er8
  signed __int64 v28; // rdx
  char *v29; // r8
  __int64 v30; // rax
  char *v31; // rax
  signed __int64 v32; // r8
  UFG::qSymbol **v33; // r10
  unsigned int *v34; // r9
  __int64 v35; // r14
  signed __int64 v36; // r11
  __int64 v37; // r15
  unsigned int v38; // ebx
  signed __int64 v39; // rdx
  _BYTE *v40; // r8
  signed __int64 *v41; // rax
  signed __int64 v42; // r8
  __int64 v43; // r9
  signed __int64 v44; // r10
  __int64 v45; // rbx
  unsigned int v46; // er11
  __int64 v47; // r13
  unsigned int v48; // eax
  signed __int64 v49; // rdx
  _BYTE *v50; // r8
  signed __int64 *v51; // rax
  signed __int64 v52; // r8
  UFG::qSymbol **v53; // r10
  unsigned int *v54; // r9
  signed __int64 v55; // r11
  __int64 v56; // r15
  unsigned int v57; // ebx
  signed __int64 v58; // rdx
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
  signed __int64 v69; // r12
  unsigned int v70; // er13
  signed __int64 v71; // rdx
  char *v72; // r8
  char *v73; // rax
  signed __int64 v74; // rax
  unsigned int *v75; // r10
  __int64 v76; // r13
  _DWORD *v77; // r9
  char *v78; // r15
  signed __int64 v79; // r11
  __int64 v80; // r14
  unsigned int v81; // ebx
  signed __int64 v82; // rdx
  char *v83; // r8
  signed __int64 v84; // rax
  signed __int64 v85; // r8
  __int64 v86; // rdx
  _BYTE *v87; // r9
  signed __int64 *v88; // rax
  signed __int64 v89; // r9
  UFG::qSymbol **v90; // r12
  unsigned int *v91; // r15
  signed __int64 v92; // r14
  signed __int64 v93; // r13
  unsigned int v94; // ecx
  _BYTE *v95; // r8
  __int64 v96; // rax
  signed __int64 *v97; // rax
  signed __int64 v98; // r8
  unsigned int v99; // ebx
  UFG::qSymbol **v100; // r12
  unsigned int *v101; // r14
  unsigned int *v102; // rbx
  signed __int64 v103; // r13
  unsigned int v104; // ecx
  _BYTE *v105; // r8
  __int64 v106; // rax
  signed __int64 *v107; // rax
  signed __int64 v108; // r8
  unsigned int v109; // er8
  unsigned int v110; // er15
  UFG::qSymbol **v111; // r14
  unsigned int *v112; // r15
  __int64 v113; // r9
  signed __int64 v114; // r12
  unsigned int v115; // er13
  signed __int64 v116; // rdx
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
  signed __int64 v128; // r12
  unsigned int v129; // er13
  signed __int64 v130; // rdx
  _BYTE *v131; // r8
  __int64 v132; // rax
  signed __int64 *v133; // rax
  signed __int64 v134; // r8
  __int64 v135; // rdx
  unsigned int v136; // ebx
  signed __int64 v137; // r8
  __int64 v138; // rdx
  _BYTE *v139; // r9
  signed __int64 *v140; // rax
  signed __int64 v141; // r9
  const void **v142; // rdx
  unsigned int v143; // ebx
  UFG::qSymbol **v144; // r14
  unsigned int *v145; // r15
  __int64 v146; // r9
  signed __int64 v147; // r12
  unsigned int v148; // er13
  signed __int64 v149; // rdx
  _BYTE *v150; // r8
  __int64 v151; // rax
  signed __int64 *v152; // rax
  signed __int64 v153; // r8
  __int64 v154; // rdx
  unsigned int v155; // ebx
  UFG::qSymbol **v156; // rbx
  unsigned int *v157; // r14
  __int64 v158; // r13
  signed __int64 v159; // r15
  unsigned int v160; // er12
  signed __int64 v161; // rdx
  _BYTE *v162; // r8
  __int64 v163; // rax
  signed __int64 *v164; // rax
  signed __int64 v165; // r8
  signed __int64 v166; // r8
  __int64 v167; // rdx
  _BYTE *v168; // r9
  signed __int64 *v169; // rax
  signed __int64 v170; // r9
  __int64 v172; // [rsp+48h] [rbp-80h]
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
  _DWORD *v189; // [rsp+D0h] [rbp+8h]
  __int64 v190; // [rsp+118h] [rbp+50h]
  int v191; // [rsp+120h] [rbp+58h]
  __int64 source; // [rsp+130h] [rbp+68h]

  v188 = -2i64;
  v4 = (void **)ppBuffer;
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
    v13 += *(_DWORD *)(v14 * 4 + 5406482272i64);
    *(_DWORD *)*v4 = UFG::GameSnapshot::sHeaderCounts[v14];
    *v4 = (char *)*v4 + 4;
    *(_DWORD *)*v4 = v13;
    *v4 = (char *)*v4 + 4;
    ++v14;
    --v15;
  }
  while ( v15 );
  v17 = 0;
  v18 = &v172;
  do
  {
    v19 = *v4;
    *v18 = (__int64)*v4;
    v20 = 0;
    LODWORD(source) = 0;
    v21 = *v16;
    if ( (_DWORD)v21 )
    {
      do
      {
        v22 = (signed __int64)&v19[10 * v20];
        v189 = &v19[10 * v20];
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
    *v4 = (char *)*v4 + 40 * v21;
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
    if ( *v24 & v27 && ((unsigned int)v5 & *v24) == (_DWORD)v5 )
    {
      v28 = 5i64 * v26++;
      v29 = (char *)*v4;
      v30 = v172;
      *(UFG::qSymbol *)(v172 + 8 * v28 + 24) = (UFG::qSymbol)(*v23)->mUID;
      v31 = (char *)(v30 + 8 * v28 + 32);
      if ( v29 )
        v32 = v29 - v31;
      else
        v32 = 0i64;
      *(_QWORD *)v31 = v32;
      LODWORD(source) = UFG::SimpleTimer::GetElapsedSeconds((UFG::SimpleTimer *)v6);
      UFG::qMemCopy(*v4, &source, 4u);
      *v4 = (char *)*v4 + 4;
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
    if ( *v34 & v27 && ((unsigned int)v5 & *v34) == (_DWORD)v5 )
    {
      v39 = 5i64 * v38++;
      v40 = *v4;
      *(UFG::qSymbol *)(v37 + 8 * v39 + 24) = (UFG::qSymbol)(*v33)->mUID;
      v41 = (signed __int64 *)(v37 + 32 + 8 * v39);
      if ( v40 )
        v42 = v40 - (_BYTE *)v41;
      else
        v42 = 0i64;
      *v41 = v42;
      *(_DWORD *)*v4 = *(unsigned int *)((char *)v34 + v35 + 480);
      *v4 = (char *)*v4 + 4;
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
    if ( v48 & v27 && ((unsigned int)v5 & v48) == (_DWORD)v5 )
    {
      v49 = 5i64 * v46++;
      v50 = *v4;
      *(UFG::qSymbol *)(v45 + 8 * v49 + 24) = (UFG::qSymbol)BoolSymbols[v43]->mUID;
      v51 = (signed __int64 *)(v45 + 32 + 8 * v49);
      if ( v50 )
        v52 = v50 - (_BYTE *)v51;
      else
        v52 = 0i64;
      *v51 = v52;
      *(_DWORD *)*v4 = *(unsigned __int8 *)(v43 + v47 + 656);
      *v4 = (char *)*v4 + 4;
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
    if ( *v54 & v27 && ((unsigned int)v5 & *v54) == (_DWORD)v5 )
    {
      v58 = 5i64 * v57++;
      v59 = *v4;
      *(UFG::qSymbol *)(v56 + 8 * v58 + 24) = (UFG::qSymbol)(*v53)->mUID;
      v60 = (signed __int64 *)(v56 + 32 + 8 * v58);
      if ( v59 )
        v61 = v59 - (_BYTE *)v60;
      else
        v61 = 0i64;
      *v60 = v61;
      *(_DWORD *)*v4 = *(unsigned int *)((char *)v54 + v47 - (_QWORD)UFG::GameSnapshot::sDefinitionInts + 716);
      *v4 = (char *)*v4 + 4;
      v27 = v191;
    }
    ++v54;
    ++v53;
    --v55;
  }
  while ( v55 );
  if ( v27 & UFG::GameSnapshot::sDefinitionUInt64s[0] && (UFG::GameSnapshot::sDefinitionUInt64s[0] & v5) == v5 )
  {
    v62 = v176;
    v63 = *v4;
    *(_DWORD *)(v176 + 24) = UInt64Symbols[0]->mUID;
    v64 = (signed __int64 *)(v62 + 32);
    if ( v63 )
      v65 = v63 - (_BYTE *)v64;
    else
      v65 = 0i64;
    *v64 = v65;
    *(_QWORD *)*v4 = *(_QWORD *)(v47 + 1368);
    *v4 = (char *)*v4 + 8;
    v27 = v191;
  }
  v66 = FloatSymbols;
  v67 = UFG::GameSnapshot::sDefinitionFloats;
  v68 = (char *)(v47 + 1376);
  v69 = 139i64;
  v70 = 0;
  do
  {
    if ( *v67 & v27 && ((unsigned int)v5 & *v67) == (_DWORD)v5 )
    {
      v71 = 5i64 * v70++;
      v72 = (char *)*v4;
      v73 = (char *)data;
      *((UFG::qSymbol *)data + 2 * v71 + 6) = (UFG::qSymbol)(*v66)->mUID;
      v74 = (signed __int64)&v73[8 * v71 + 32];
      if ( v72 )
        v72 -= v74;
      *(_QWORD *)v74 = v72;
      UFG::qMemCopy(*v4, v68, 4u);
      *v4 = (char *)*v4 + 4;
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
    if ( *v75 & v27 && ((unsigned int)v5 & *v75) == (_DWORD)v5 )
    {
      v82 = 5i64 * v81++;
      v83 = (char *)*v4;
      *(_DWORD *)(v80 + 8 * v82 + 24) = **(_DWORD **)((char *)v77 + (_QWORD)v78 - 1932);
      v84 = v80 + 32 + 8 * v82;
      if ( v83 )
        v83 -= v84;
      *(_QWORD *)v84 = v83;
      *(_DWORD *)*v4 = *v77;
      *v4 = (char *)*v4 + 4;
      *(_DWORD *)*v4 = v77[1];
      *v4 = (char *)*v4 + 4;
      v27 = v191;
    }
    ++v75;
    v77 += 2;
    --v79;
  }
  while ( v79 );
  if ( UFG::GameSnapshot::sDefinitionFloatsRanged[0] & v27
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionFloatsRanged[0]) == (_DWORD)v5 )
  {
    v85 = 5i64 * HIDWORD(v172);
    v86 = v179;
    v87 = *v4;
    *(_DWORD *)(v179 + 8 * v85 + 24) = FloatRangedSymbols[0]->mUID;
    v88 = (signed __int64 *)(v86 + 32 + 8 * v85);
    if ( v87 )
      v89 = v87 - (_BYTE *)v88;
    else
      v89 = 0i64;
    *v88 = v89;
    UFG::qMemCopy(*v4, (const void *)(v76 + 1988), 4u);
    *v4 = (char *)*v4 + 4;
    UFG::qMemCopy(*v4, (const void *)(v76 + 1992), 4u);
    *v4 = (char *)*v4 + 4;
    v27 = v191;
  }
  v90 = StringSymbols;
  v91 = UFG::GameSnapshot::sDefinitionStrings;
  v92 = v76 + 2020;
  v93 = 25i64;
  v94 = v173;
  do
  {
    if ( *v91 & v27 && ((unsigned int)v5 & *v91) == (_DWORD)v5 )
    {
      LODWORD(source) = v94 + 1;
      v95 = *v4;
      v96 = v180;
      *(UFG::qSymbol *)(v180 + 40i64 * v94 + 24) = (UFG::qSymbol)(*v90)->mUID;
      v97 = (signed __int64 *)(v96 + 40i64 * v94 + 32);
      if ( v95 )
        v98 = v95 - (_BYTE *)v97;
      else
        v98 = 0i64;
      *v97 = v98;
      if ( *(_DWORD *)v92 <= 0 )
        v99 = 0;
      else
        v99 = (*(_DWORD *)v92 + 4) & 0xFFFFFFFC;
      *(_DWORD *)*v4 = v99;
      *v4 = (char *)*v4 + 4;
      if ( v99 )
      {
        UFG::qMemCopy(*v4, *(const void **)(v92 + 4), v99);
        *v4 = (char *)*v4 + v99;
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
    if ( *v101 & v27 && ((unsigned int)v5 & *v101) == (_DWORD)v5 )
    {
      LODWORD(source) = v104 + 1;
      v105 = *v4;
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
      *(_DWORD *)*v4 = *v102;
      *v4 = (char *)*v4 + 4;
      if ( v109 )
      {
        UFG::qMemCopy(*v4, *((const void **)v102 - 1), v109);
        *v4 = (char *)*v4 + v110;
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
    if ( *v112 & v27 && ((unsigned int)v5 & *v112) == (_DWORD)v5 )
    {
      v116 = 5i64 * v115++;
      v117 = *v4;
      v118 = v182;
      *(UFG::qSymbol *)(v182 + 8 * v116 + 24) = (UFG::qSymbol)(*v111)->mUID;
      v119 = (signed __int64 *)(v118 + 8 * v116 + 32);
      if ( v117 )
        v120 = v117 - (_BYTE *)v119;
      else
        v120 = 0i64;
      *v119 = v120;
      v121 = *(__int64 *)((char *)v111 + v113 + 3048);
      *(_DWORD *)*v4 = *(_DWORD *)v121;
      *v4 = (char *)*v4 + 4;
      v122 = *v4;
      if ( *(_DWORD *)v121 )
      {
        *v122 = *(_DWORD *)(v121 + 24);
        *v4 = (char *)*v4 + 4;
        v123 = 4 * *(_DWORD *)(v121 + 24);
        v124 = *(const void **)(v121 + 32);
      }
      else
      {
        *v122 = *(_DWORD *)(v121 + 8);
        *v4 = (char *)*v4 + 4;
        v123 = 8 * *(_DWORD *)(v121 + 8);
        v124 = *(const void **)(v121 + 16);
      }
      UFG::qMemCopy(*v4, v124, v123);
      v27 = v191;
      v113 = source;
      *v4 = (char *)*v4 + v123;
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
    if ( *v126 & v27 && ((unsigned int)v5 & *v126) == (_DWORD)v5 )
    {
      v130 = 5i64 * v129++;
      v131 = *v4;
      v132 = v183;
      *(UFG::qSymbol *)(v183 + 8 * v130 + 24) = (UFG::qSymbol)(*v125)->mUID;
      v133 = (signed __int64 *)(v132 + 8 * v130 + 32);
      if ( v131 )
        v134 = v131 - (_BYTE *)v133;
      else
        v134 = 0i64;
      *v133 = v134;
      v135 = *(__int64 *)((char *)v125 + v127 + 3792);
      *(_DWORD *)*v4 = *(_DWORD *)v135;
      *v4 = (char *)*v4 + 4;
      v136 = 8 * *(_DWORD *)v135;
      UFG::qMemCopy(*v4, *(const void **)(v135 + 8), 8 * *(_DWORD *)v135);
      *v4 = (char *)*v4 + v136;
      v127 = source;
      v27 = v191;
    }
    ++v126;
    ++v125;
    --v128;
  }
  while ( v128 );
  if ( UFG::GameSnapshot::sDefinitionMapUInt64s[0] & v27
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionMapUInt64s[0]) == (_DWORD)v5 )
  {
    v137 = 5i64 * (unsigned int)v175;
    v138 = v184;
    v139 = *v4;
    *(_DWORD *)(v184 + 8 * v137 + 24) = MapUInt64Symbols[0]->mUID;
    v140 = (signed __int64 *)(v138 + 32 + 8 * v137);
    if ( v139 )
      v141 = v139 - (_BYTE *)v140;
    else
      v141 = 0i64;
    *v140 = v141;
    v142 = *(const void ***)(v190 + 4168);
    *(_QWORD *)*v4 = *(unsigned int *)v142;
    *v4 = (char *)*v4 + 8;
    v143 = 16 * *(_DWORD *)v142;
    UFG::qMemCopy(*v4, v142[1], 16 * *(_DWORD *)v142);
    *v4 = (char *)*v4 + v143;
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
    if ( *v145 & v27 && ((unsigned int)v5 & *v145) == (_DWORD)v5 )
    {
      v149 = 5i64 * v148++;
      v150 = *v4;
      v151 = v185;
      *(UFG::qSymbol *)(v185 + 8 * v149 + 24) = (UFG::qSymbol)(*v144)->mUID;
      v152 = (signed __int64 *)(v151 + 8 * v149 + 32);
      if ( v150 )
        v153 = v150 - (_BYTE *)v152;
      else
        v153 = 0i64;
      *v152 = v153;
      v154 = *(__int64 *)((char *)v144 + v146 + 4176);
      *(_DWORD *)*v4 = *(_DWORD *)v154;
      *v4 = (char *)*v4 + 4;
      v155 = 8 * *(_DWORD *)v154;
      UFG::qMemCopy(*v4, *(const void **)(v154 + 8), 8 * *(_DWORD *)v154);
      *v4 = (char *)*v4 + v155;
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
    if ( *v157 & v27 && ((unsigned int)v5 & *v157) == (_DWORD)v5 )
    {
      v161 = 5i64 * v160++;
      v162 = *v4;
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
        (char **)v4);
      v27 = v191;
    }
    ++v157;
    ++v156;
    --v159;
  }
  while ( v159 );
  if ( UFG::GameSnapshot::sDefinitionList[0] & v27
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionList[0]) == (_DWORD)v5 )
  {
    v166 = 5i64 * HIDWORD(v176);
    v167 = v187;
    v168 = *v4;
    *(_DWORD *)(v187 + 8 * v166 + 24) = ListSymbols[0]->mUID;
    v169 = (signed __int64 *)(v167 + 32 + 8 * v166);
    if ( v168 )
      v170 = v168 - (_BYTE *)v169;
    else
      v170 = 0i64;
    *v169 = v170;
    UFG::PersistentData::List::Serialize(*(UFG::PersistentData::List **)(v190 + 4336), (char **)v4);
  }
  *(_DWORD *)*v4 = UFG::qDataHash32(data, (unsigned int)(*(_DWORD *)v4 - (_DWORD)data), 0xFFFFFFFF);
  *v4 = (char *)*v4 + 4;
  return 1;
}

// File Line: 680
// RVA: 0x49B900
char __fastcall UFG::GameSnapshot::DeserializeByFilter(UFG::GameSnapshot *this, unsigned int filterMask, unsigned int persistenceMask, char *pBuffer)
{
  char *v4; // rdi
  __int64 v5; // r12
  float v6; // er14
  unsigned __int64 v7; // rbx
  char *v8; // rsi
  unsigned int v9; // edx
  __int64 v10; // rcx
  unsigned int v11; // eax
  unsigned int v12; // er13
  __int64 v13; // r15
  unsigned int v14; // ebx
  UFG::qBaseTreeRB *v15; // rcx
  char *v16; // r14
  __int64 v17; // rax
  unsigned int **v18; // r15
  unsigned int *v19; // r13
  UFG::SimpleTimer *v20; // r14
  char *v21; // rbx
  int v22; // er8
  UFG::qSymbolUC *v23; // rdi
  unsigned int v24; // edx
  UFG::qBaseTreeRB *v25; // rax
  UFG::qBaseNodeRB *v26; // rcx
  char *v27; // rdx
  UFG::qSymbolUC v28; // ebx
  char *v29; // rax
  unsigned int **v30; // r15
  unsigned int *v31; // r14
  char *v32; // rbx
  signed __int64 v33; // r13
  UFG::qSymbolUC *v34; // rdi
  unsigned int v35; // edx
  UFG::qBaseTreeRB *v36; // rax
  UFG::qBaseNodeRB *v37; // rcx
  unsigned int *v38; // rdx
  UFG::qSymbolUC v39; // ebx
  char *v40; // rax
  __int64 v41; // rdi
  signed __int64 v42; // r15
  unsigned int v43; // eax
  UFG::qSymbolUC *v44; // r14
  UFG::qBaseTreeRB *v45; // rax
  UFG::qBaseNodeRB *v46; // rcx
  _DWORD *v47; // rcx
  bool v48; // al
  UFG::SimpleTimer *v49; // rcx
  UFG::qSymbolUC v50; // ebx
  char *v51; // rax
  unsigned int **v52; // r15
  unsigned int *v53; // rdi
  char *v54; // rbx
  signed __int64 v55; // r13
  UFG::qSymbolUC *v56; // r14
  unsigned int v57; // edx
  UFG::qBaseTreeRB *v58; // rax
  UFG::qBaseNodeRB *v59; // rcx
  unsigned int *v60; // rcx
  UFG::qSymbolUC v61; // ebx
  char *v62; // rax
  UFG::qSymbolUC *v63; // rdi
  UFG::qBaseTreeRB *v64; // rax
  UFG::qBaseNodeRB *v65; // rcx
  _QWORD *v66; // rax
  UFG::qSymbolUC v67; // ebx
  char *v68; // rax
  unsigned int **v69; // r14
  unsigned int *v70; // r15
  UFG::SimpleTimer *v71; // r13
  char *v72; // rbx
  UFG::qSymbolUC *v73; // rdi
  unsigned int v74; // edx
  UFG::qBaseTreeRB *v75; // rax
  UFG::qBaseNodeRB *v76; // rcx
  char *v77; // rdx
  UFG::qSymbolUC v78; // ebx
  char *v79; // rax
  unsigned int *v80; // r15
  bool *v81; // rdi
  char *v82; // rcx
  signed __int64 v83; // r13
  UFG::qSymbolUC *v84; // r14
  UFG::qBaseTreeRB *v85; // rax
  UFG::qBaseNodeRB *v86; // rcx
  _DWORD *v87; // rcx
  UFG::qSymbolUC v88; // ebx
  char *v89; // rax
  UFG::qSymbolUC *v90; // rdi
  UFG::qBaseTreeRB *v91; // rax
  UFG::qBaseNodeRB *v92; // rcx
  signed __int64 v93; // rdi
  UFG::SimpleTimer *v94; // rbx
  UFG::qSymbolUC v95; // ebx
  char *v96; // rax
  unsigned int **v97; // r14
  unsigned int *v98; // r15
  UFG::qString *v99; // r13
  char *v100; // rbx
  UFG::qSymbolUC *v101; // rdi
  unsigned int v102; // edx
  UFG::qBaseTreeRB *v103; // rax
  UFG::qBaseNodeRB *v104; // rcx
  _DWORD *v105; // rdx
  int v106; // eax
  const char *v107; // rdx
  UFG::qSymbolUC v108; // ebx
  char *v109; // rax
  unsigned int **v110; // r15
  unsigned int *v111; // r13
  char *v112; // rdi
  UFG::qSymbolUC *v113; // r14
  unsigned int v114; // edx
  UFG::qBaseTreeRB *v115; // rax
  UFG::qBaseNodeRB *v116; // rcx
  unsigned int *v117; // rbx
  unsigned int v118; // er14
  UFG::qSymbolUC v119; // ebx
  char *v120; // rax
  unsigned int **v121; // rdi
  unsigned int *v122; // r15
  char *v123; // rbx
  signed __int64 v124; // r13
  UFG::qSymbolUC *v125; // r14
  unsigned int v126; // edx
  UFG::qBaseTreeRB *v127; // rax
  UFG::qBaseNodeRB *v128; // rcx
  char *v129; // rdx
  UFG::qSymbolUC v130; // ebx
  char *v131; // rax
  unsigned int **v132; // rdi
  unsigned int *v133; // r15
  char *v134; // rbx
  signed __int64 v135; // r13
  UFG::qSymbolUC *v136; // r14
  unsigned int v137; // edx
  UFG::qBaseTreeRB *v138; // rax
  UFG::qBaseNodeRB *v139; // rcx
  char *v140; // rdx
  UFG::qSymbolUC v141; // ebx
  char *v142; // rax
  UFG::qSymbolUC *v143; // rdi
  UFG::qBaseTreeRB *v144; // rax
  UFG::qBaseNodeRB *v145; // rcx
  char *v146; // rdx
  UFG::qSymbolUC v147; // ebx
  char *v148; // rax
  unsigned int **v149; // rdi
  unsigned int *v150; // r15
  char *v151; // rbx
  signed __int64 v152; // r13
  UFG::qSymbolUC *v153; // r14
  unsigned int v154; // edx
  UFG::qBaseTreeRB *v155; // rax
  UFG::qBaseNodeRB *v156; // rcx
  char *v157; // rdx
  UFG::qSymbolUC v158; // ebx
  char *v159; // rax
  unsigned int **v160; // rdi
  unsigned int *v161; // r15
  char *v162; // rbx
  signed __int64 v163; // r13
  UFG::qSymbolUC *v164; // r14
  unsigned int v165; // edx
  UFG::qBaseTreeRB *v166; // rax
  UFG::qBaseNodeRB *v167; // rcx
  char *v168; // rdx
  UFG::qSymbolUC v169; // ebx
  char *v170; // rax
  UFG::qSymbolUC *v171; // rdi
  UFG::qBaseTreeRB *v172; // rax
  UFG::qBaseNodeRB *v173; // rcx
  UFG::qSymbolUC v174; // ebx
  char *v175; // rax
  char *v176; // rbx
  signed __int64 v177; // rdi
  char v178; // bl
  UFG::allocator::free_link *v180; // [rsp+30h] [rbp-98h]
  unsigned __int64 v181; // [rsp+38h] [rbp-90h]
  int v182[2]; // [rsp+50h] [rbp-78h]
  char ptr[72]; // [rsp+58h] [rbp-70h]
  UFG::qBaseTreeRB v184; // [rsp+A0h] [rbp-28h]
  UFG::qBaseTreeRB v185; // [rsp+E8h] [rbp+20h]
  UFG::qBaseTreeRB v186; // [rsp+130h] [rbp+68h]
  UFG::qBaseTreeRB v187; // [rsp+178h] [rbp+B0h]
  UFG::qBaseTreeRB v188; // [rsp+1C0h] [rbp+F8h]
  UFG::qBaseTreeRB v189; // [rsp+208h] [rbp+140h]
  UFG::qBaseTreeRB v190; // [rsp+250h] [rbp+188h]
  UFG::qBaseTreeRB v191; // [rsp+298h] [rbp+1D0h]
  UFG::qBaseTreeRB v192; // [rsp+2E0h] [rbp+218h]
  UFG::qBaseTreeRB v193; // [rsp+328h] [rbp+260h]
  UFG::qBaseTreeRB v194; // [rsp+370h] [rbp+2A8h]
  UFG::qBaseTreeRB v195; // [rsp+3B8h] [rbp+2F0h]
  UFG::qBaseTreeRB v196; // [rsp+400h] [rbp+338h]
  UFG::qBaseTreeRB v197; // [rsp+448h] [rbp+380h]
  UFG::qBaseTreeRB v198; // [rsp+490h] [rbp+3C8h]
  UFG::SimpleTimer *v199; // [rsp+518h] [rbp+450h]
  int v200; // [rsp+520h] [rbp+458h]
  char *v201; // [rsp+530h] [rbp+468h]
  float dest; // [rsp+538h] [rbp+470h]

  v4 = pBuffer;
  v5 = persistenceMask;
  v201 = pBuffer;
  v6 = dest;
  v7 = (unsigned int)(LODWORD(dest) - 4);
  if ( (unsigned int)UFG::qDataHash32(pBuffer, v7, 0xFFFFFFFF) != *(_DWORD *)&pBuffer[v7] )
    return 0;
  `eh vector constructor iterator'(
    ptr,
    0x48ui64,
    16,
    (void (__fastcall *)(void *))UFG::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>);
  v8 = 0i64;
  v9 = 0;
  v10 = 0i64;
  do
  {
    *(_DWORD *)(v10 * 4 + 5406482208i64) = *(_DWORD *)v4;
    v11 = *((_DWORD *)v4 + 1);
    v182[v10] = v11;
    v4 += 8;
    if ( v11 > LODWORD(v6) )
      goto LABEL_201;
    ++v9;
    ++v10;
  }
  while ( v9 < 0x10 );
  v12 = 0;
  v13 = 0i64;
  do
  {
    v14 = 0;
    if ( *(_DWORD *)(v13 * 4 + 0x142405F20i64) > 0u )
    {
      v15 = (UFG::qBaseTreeRB *)&ptr[0x48 * v12];
      v181 = (unsigned __int64)&v201[v182[v13]];
      while ( 1 )
      {
        v16 = v4;
        UFG::qBaseTreeRB::Add(v15, (UFG::qBaseNodeRB *)v4);
        v4 += 40;
        v17 = *((_QWORD *)v16 + 4);
        if ( v17 )
        {
          if ( (unsigned __int64)&v16[v17 + 32] > v181 )
            break;
        }
        ++v14;
        v15 = (UFG::qBaseTreeRB *)&ptr[0x48 * v12];
        if ( v14 >= *(_DWORD *)(v13 * 4 + 5406482208i64) )
          goto LABEL_11;
      }
LABEL_201:
      v178 = 0;
      goto LABEL_202;
    }
LABEL_11:
    ++v12;
    ++v13;
  }
  while ( v12 < 0x10 );
  v18 = (unsigned int **)TimeSymbols;
  v19 = UFG::GameSnapshot::sDefinitionTimes;
  v20 = v199;
  v21 = (char *)30;
  v201 = (char *)30;
  v22 = v200;
  do
  {
    if ( *v19 & v22 && ((unsigned int)v5 & *v19) == (_DWORD)v5 )
    {
      v23 = (UFG::qSymbolUC *)*v18;
      v24 = **v18;
      if ( v24 && (v25 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)ptr, v24)) != 0i64 )
      {
        v26 = v25->mNULL.mParent;
        if ( v26 )
          v27 = (char *)&v25->mNULL + (_QWORD)v26;
        else
          v27 = 0i64;
        UFG::qMemCopy(&dest, v27, 4u);
        UFG::SimpleTimer::Stop(v20);
        UFG::SimpleTimer::SetElapsedTime(v20, dest);
      }
      else
      {
        v28.mUID = v23->mUID;
        v29 = UFG::qSymbol::as_cstr_dbg(v23);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v28.mUID,
          v29);
        v21 = v201;
      }
      v22 = v200;
    }
    ++v20;
    ++v19;
    ++v18;
    v201 = --v21;
  }
  while ( v21 );
  v30 = (unsigned int **)IDSymbols;
  v31 = UFG::GameSnapshot::sDefinitionIDs;
  v32 = (char *)((char *)v199 - (char *)UFG::GameSnapshot::sDefinitionIDs);
  v201 = (char *)((char *)v199 - (char *)UFG::GameSnapshot::sDefinitionIDs);
  v33 = 44i64;
  do
  {
    if ( *v31 & v22 && ((unsigned int)v5 & *v31) == (_DWORD)v5 )
    {
      v34 = (UFG::qSymbolUC *)*v30;
      v35 = **v30;
      if ( v35 && (v36 = UFG::qBaseTreeRB::Get(&v184, v35)) != 0i64 )
      {
        v37 = v36->mNULL.mParent;
        if ( v37 )
          v38 = (unsigned int *)((char *)&v36->mNULL + (_QWORD)v37);
        else
          v38 = 0i64;
        *(UFG::qWiseSymbol *)((char *)v31 + (_QWORD)v32 + 480) = (UFG::qWiseSymbol)UFG::qSymbol::qSymbol(
                                                                                     (UFG::qWiseSymbol *)&dest,
                                                                                     *v38)->mUID;
      }
      else
      {
        v39.mUID = v34->mUID;
        v40 = UFG::qSymbol::as_cstr_dbg(v34);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v39.mUID,
          v40);
        v32 = v201;
      }
      v22 = v200;
    }
    ++v31;
    ++v30;
    --v33;
  }
  while ( v33 );
  v41 = 0i64;
  v42 = 58i64;
  while ( 2 )
  {
    v43 = UFG::GameSnapshot::sDefinitionBools[v41];
    if ( !(v43 & v22) || ((unsigned int)v5 & v43) != (_DWORD)v5 )
    {
LABEL_46:
      v49 = v199;
      goto LABEL_47;
    }
    v44 = (UFG::qSymbolUC *)BoolSymbols[v41];
    if ( !v44->mUID || (v45 = UFG::qBaseTreeRB::Get(&v185, v44->mUID)) == 0i64 )
    {
      v50.mUID = v44->mUID;
      v51 = UFG::qSymbol::as_cstr_dbg(v44);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
        v50.mUID,
        v51);
      v22 = v200;
      goto LABEL_46;
    }
    v46 = v45->mNULL.mParent;
    if ( v46 )
      v47 = (_DWORD *)((char *)&v46[1] + (_QWORD)v45);
    else
      v47 = 0i64;
    v48 = *v47 > 0u;
    v49 = v199;
    *((_BYTE *)&v199[41].mTimestamp + v41) = v48;
    v22 = v200;
LABEL_47:
    ++v41;
    if ( --v42 )
      continue;
    break;
  }
  v52 = (unsigned int **)Int32Symbols;
  v53 = UFG::GameSnapshot::sDefinitionInts;
  v54 = (char *)((char *)v49 - (char *)UFG::GameSnapshot::sDefinitionInts);
  v201 = (char *)((char *)v49 - (char *)UFG::GameSnapshot::sDefinitionInts);
  v55 = 163i64;
  do
  {
    if ( *v53 & v22 && ((unsigned int)v5 & *v53) == (_DWORD)v5 )
    {
      v56 = (UFG::qSymbolUC *)*v52;
      v57 = **v52;
      if ( v57 && (v58 = UFG::qBaseTreeRB::Get(&v186, v57)) != 0i64 )
      {
        v59 = v58->mNULL.mParent;
        if ( v59 )
          v60 = (unsigned int *)((char *)&v59[1] + (_QWORD)v58);
        else
          v60 = 0i64;
        *(unsigned int *)((char *)v53 + (_QWORD)v54 + 716) = *v60;
      }
      else
      {
        v61.mUID = v56->mUID;
        v62 = UFG::qSymbol::as_cstr_dbg(v56);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v61.mUID,
          v62);
        v54 = v201;
      }
      v22 = v200;
    }
    ++v53;
    ++v52;
    --v55;
  }
  while ( v55 );
  if ( v22 & UFG::GameSnapshot::sDefinitionUInt64s[0] && (UFG::GameSnapshot::sDefinitionUInt64s[0] & v5) == v5 )
  {
    v63 = (UFG::qSymbolUC *)UInt64Symbols[0];
    if ( UInt64Symbols[0]->mUID && (v64 = UFG::qBaseTreeRB::Get(&v187, UInt64Symbols[0]->mUID)) != 0i64 )
    {
      v65 = v64->mNULL.mParent;
      if ( v65 )
        v66 = (UFG::qBaseNodeRB **)((char *)&v64->mNULL.mParent + (_QWORD)v65);
      else
        v66 = 0i64;
      *(_QWORD *)&v199[85].mElapsedTime = *v66;
    }
    else
    {
      v67.mUID = v63->mUID;
      v68 = UFG::qSymbol::as_cstr_dbg(v63);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
        v67.mUID,
        v68);
    }
    v22 = v200;
  }
  v69 = (unsigned int **)FloatSymbols;
  v70 = UFG::GameSnapshot::sDefinitionFloats;
  v71 = v199 + 86;
  v72 = (char *)139;
  v201 = (char *)139;
  do
  {
    if ( *v70 & v22 && ((unsigned int)v5 & *v70) == (_DWORD)v5 )
    {
      v73 = (UFG::qSymbolUC *)*v69;
      v74 = **v69;
      if ( v74 && (v75 = UFG::qBaseTreeRB::Get(&v188, v74)) != 0i64 )
      {
        v76 = v75->mNULL.mParent;
        if ( v76 )
          v77 = (char *)&v75->mNULL + (_QWORD)v76;
        else
          v77 = 0i64;
        UFG::qMemCopy(v71, v77, 4u);
      }
      else
      {
        v78.mUID = v73->mUID;
        v79 = UFG::qSymbol::as_cstr_dbg(v73);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v78.mUID,
          v79);
        v72 = v201;
      }
      v22 = v200;
    }
    v71 = (UFG::SimpleTimer *)((char *)v71 + 4);
    ++v70;
    ++v69;
    v201 = --v72;
  }
  while ( v72 );
  v80 = UFG::GameSnapshot::sDefinitionIntsRanged;
  v81 = &v199[120].mIsStarted;
  v82 = (char *)((char *)Int32RangedSymbols - (char *)v199);
  v201 = (char *)((char *)Int32RangedSymbols - (char *)v199);
  v83 = 7i64;
  do
  {
    if ( *v80 & v22 && ((unsigned int)v5 & *v80) == (_DWORD)v5 )
    {
      v84 = *(UFG::qSymbolUC **)&v81[(_QWORD)v82 - 1932];
      if ( v84->mUID && (v85 = UFG::qBaseTreeRB::Get(&v189, v84->mUID)) != 0i64 )
      {
        v86 = v85->mNULL.mParent;
        if ( v86 )
          v87 = (_DWORD *)((char *)&v86[1] + (_QWORD)v85);
        else
          v87 = 0i64;
        *(_DWORD *)v81 = *v87;
        *((_DWORD *)v81 + 1) = v87[1];
      }
      else
      {
        v88.mUID = v84->mUID;
        v89 = UFG::qSymbol::as_cstr_dbg(v84);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v88.mUID,
          v89);
      }
      v22 = v200;
      v82 = v201;
    }
    ++v80;
    v81 += 8;
    --v83;
  }
  while ( v83 );
  if ( UFG::GameSnapshot::sDefinitionFloatsRanged[0] & v22
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionFloatsRanged[0]) == (_DWORD)v5 )
  {
    v90 = (UFG::qSymbolUC *)FloatRangedSymbols[0];
    if ( FloatRangedSymbols[0]->mUID && (v91 = UFG::qBaseTreeRB::Get(&v190, FloatRangedSymbols[0]->mUID)) != 0i64 )
    {
      v92 = v91->mNULL.mParent;
      if ( v92 )
        v93 = (signed __int64)&v91->mNULL + (_QWORD)v92;
      else
        v93 = 0i64;
      v94 = v199;
      UFG::qMemCopy((char *)&v199[124].mTimestamp + 4, (const void *)v93, 4u);
      UFG::qMemCopy(&v94[124].mElapsedTime, (const void *)(v93 + 4), 4u);
    }
    else
    {
      v95.mUID = v90->mUID;
      v96 = UFG::qSymbol::as_cstr_dbg(v90);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
        v95.mUID,
        v96);
    }
    v22 = v200;
  }
  v97 = (unsigned int **)StringSymbols;
  v98 = UFG::GameSnapshot::sDefinitionStrings;
  v99 = (UFG::qString *)&v199[125];
  v100 = (char *)25;
  v201 = (char *)25;
  do
  {
    if ( *v98 & v22 && ((unsigned int)v5 & *v98) == (_DWORD)v5 )
    {
      v101 = (UFG::qSymbolUC *)*v97;
      v102 = **v97;
      if ( v102 && (v103 = UFG::qBaseTreeRB::Get(&v191, v102)) != 0i64 )
      {
        v104 = v103->mNULL.mParent;
        if ( v104 )
          v105 = (_DWORD *)((char *)&v103->mNULL + (_QWORD)v104);
        else
          v105 = 0i64;
        v106 = *v105;
        v107 = (const char *)(v105 + 1);
        if ( v106 )
          UFG::qString::Set(v99, v107);
      }
      else
      {
        v108.mUID = v101->mUID;
        v109 = UFG::qSymbol::as_cstr_dbg(v101);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v108.mUID,
          v109);
        v100 = v201;
      }
      v22 = v200;
    }
    ++v99;
    ++v98;
    ++v97;
    v201 = --v100;
  }
  while ( v100 );
  v110 = (unsigned int **)BinarySymbols;
  v111 = UFG::GameSnapshot::sDefinitionBinaries;
  v112 = (char *)&v199[187].mElapsedTime;
  v201 = (char *)3;
  do
  {
    if ( *v111 & v22 && ((unsigned int)v5 & *v111) == (_DWORD)v5 )
    {
      v113 = (UFG::qSymbolUC *)*v110;
      v114 = **v110;
      if ( v114 && (v115 = UFG::qBaseTreeRB::Get(&v192, v114)) != 0i64 )
      {
        v116 = v115->mNULL.mParent;
        if ( v116 )
          v117 = (unsigned int *)((char *)&v115->mNULL + (_QWORD)v116);
        else
          v117 = 0i64;
        v118 = *v117;
        if ( *v117 )
        {
          v180 = UFG::qMalloc(v118, "Binary", 0i64);
          UFG::qMemCopy(v180, v117 + 1, v118);
          if ( *((_DWORD *)v112 + 2) > 0u )
            operator delete[](*(void **)v112);
          *(_QWORD *)v112 = v180;
          *((_DWORD *)v112 + 2) = v118;
        }
      }
      else
      {
        v119.mUID = v113->mUID;
        v120 = UFG::qSymbol::as_cstr_dbg(v113);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v119.mUID,
          v120);
      }
      v22 = v200;
    }
    ++v111;
    ++v110;
    v112 += 16;
    --v201;
  }
  while ( v201 );
  v121 = (unsigned int **)MapBoolSymbols;
  v122 = UFG::GameSnapshot::sDefinitionMapBools;
  v123 = (char *)((char *)v199 - (char *)MapBoolSymbols);
  v201 = (char *)((char *)v199 - (char *)MapBoolSymbols);
  v124 = 93i64;
  do
  {
    if ( *v122 & v22 && ((unsigned int)v5 & *v122) == (_DWORD)v5 )
    {
      v125 = (UFG::qSymbolUC *)*v121;
      v126 = **v121;
      if ( v126 && (v127 = UFG::qBaseTreeRB::Get(&v193, v126)) != 0i64 )
      {
        v128 = v127->mNULL.mParent;
        if ( v128 )
          v129 = (char *)&v127->mNULL + (_QWORD)v128;
        else
          v129 = 0i64;
        UFG::PersistentData::MapBool::Deserialize(
          *(UFG::PersistentData::MapBool **)((char *)v121 + (_QWORD)v123 + 3048),
          v129);
      }
      else
      {
        v130.mUID = v125->mUID;
        v131 = UFG::qSymbol::as_cstr_dbg(v125);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v130.mUID,
          v131);
        v123 = v201;
      }
      v22 = v200;
    }
    ++v122;
    ++v121;
    --v124;
  }
  while ( v124 );
  v132 = (unsigned int **)MapInt32Symbols;
  v133 = UFG::GameSnapshot::sDefinitionMapInts;
  v134 = (char *)((char *)v199 - (char *)MapInt32Symbols);
  v201 = (char *)((char *)v199 - (char *)MapInt32Symbols);
  v135 = 47i64;
  do
  {
    if ( *v133 & v22 && ((unsigned int)v5 & *v133) == (_DWORD)v5 )
    {
      v136 = (UFG::qSymbolUC *)*v132;
      v137 = **v132;
      if ( v137 && (v138 = UFG::qBaseTreeRB::Get(&v194, v137)) != 0i64 )
      {
        v139 = v138->mNULL.mParent;
        if ( v139 )
          v140 = (char *)&v138->mNULL + (_QWORD)v139;
        else
          v140 = 0i64;
        UFG::PersistentData::MapInt::Deserialize(
          *(UFG::PersistentData::MapInt **)((char *)v132 + (_QWORD)v134 + 3792),
          v140);
      }
      else
      {
        v141.mUID = v136->mUID;
        v142 = UFG::qSymbol::as_cstr_dbg(v136);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v141.mUID,
          v142);
        v134 = v201;
      }
      v22 = v200;
    }
    ++v133;
    ++v132;
    --v135;
  }
  while ( v135 );
  if ( UFG::GameSnapshot::sDefinitionMapUInt64s[0] & v22
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionMapUInt64s[0]) == (_DWORD)v5 )
  {
    v143 = (UFG::qSymbolUC *)MapUInt64Symbols[0];
    if ( MapUInt64Symbols[0]->mUID && (v144 = UFG::qBaseTreeRB::Get(&v195, MapUInt64Symbols[0]->mUID)) != 0i64 )
    {
      v145 = v144->mNULL.mParent;
      if ( v145 )
        v146 = (char *)&v144->mNULL + (_QWORD)v145;
      else
        v146 = 0i64;
      UFG::PersistentData::MapUInt64::Deserialize(*(UFG::PersistentData::MapUInt64 **)&v199[260].mElapsedTime, v146);
    }
    else
    {
      v147.mUID = v143->mUID;
      v148 = UFG::qSymbol::as_cstr_dbg(v143);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
        v147.mUID,
        v148);
    }
    v22 = v200;
  }
  v149 = (unsigned int **)MapFloatSymbols;
  v150 = UFG::GameSnapshot::sDefinitionMapFloats;
  v151 = (char *)((char *)v199 - (char *)MapFloatSymbols);
  v201 = (char *)((char *)v199 - (char *)MapFloatSymbols);
  v152 = 18i64;
  do
  {
    if ( *v150 & v22 && ((unsigned int)v5 & *v150) == (_DWORD)v5 )
    {
      v153 = (UFG::qSymbolUC *)*v149;
      v154 = **v149;
      if ( v154 && (v155 = UFG::qBaseTreeRB::Get(&v196, v154)) != 0i64 )
      {
        v156 = v155->mNULL.mParent;
        if ( v156 )
          v157 = (char *)&v155->mNULL + (_QWORD)v156;
        else
          v157 = 0i64;
        UFG::PersistentData::MapInt::Deserialize(
          *(UFG::PersistentData::MapInt **)((char *)v149 + (_QWORD)v151 + 4176),
          v157);
      }
      else
      {
        v158.mUID = v153->mUID;
        v159 = UFG::qSymbol::as_cstr_dbg(v153);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v158.mUID,
          v159);
        v151 = v201;
      }
      v22 = v200;
    }
    ++v150;
    ++v149;
    --v152;
  }
  while ( v152 );
  v160 = (unsigned int **)MapBinarySymbols;
  v161 = UFG::GameSnapshot::sDefinitionMapBinaries;
  v162 = (char *)((char *)v199 - (char *)MapBinarySymbols);
  v201 = (char *)((char *)v199 - (char *)MapBinarySymbols);
  v163 = 2i64;
  do
  {
    if ( *v161 & v22 && ((unsigned int)v5 & *v161) == (_DWORD)v5 )
    {
      v164 = (UFG::qSymbolUC *)*v160;
      v165 = **v160;
      if ( v165 && (v166 = UFG::qBaseTreeRB::Get(&v197, v165)) != 0i64 )
      {
        v167 = v166->mNULL.mParent;
        if ( v167 )
          v168 = (char *)&v166->mNULL + (_QWORD)v167;
        else
          v168 = 0i64;
        UFG::PersistentData::MapBinary::Deserialize(
          *(UFG::PersistentData::MapBinary **)((char *)v160 + (_QWORD)v162 + 4320),
          v168);
      }
      else
      {
        v169.mUID = v164->mUID;
        v170 = UFG::qSymbol::as_cstr_dbg(v164);
        UFG::qPrintf(
          "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
          v169.mUID,
          v170);
        v162 = v201;
      }
      v22 = v200;
    }
    ++v161;
    ++v160;
    --v163;
  }
  while ( v163 );
  if ( UFG::GameSnapshot::sDefinitionList[0] & v22
    && ((unsigned int)v5 & UFG::GameSnapshot::sDefinitionList[0]) == (_DWORD)v5 )
  {
    v171 = (UFG::qSymbolUC *)ListSymbols[0];
    if ( ListSymbols[0]->mUID && (v172 = UFG::qBaseTreeRB::Get(&v198, ListSymbols[0]->mUID)) != 0i64 )
    {
      v173 = v172->mNULL.mParent;
      if ( v173 )
        v8 = (char *)&v172->mNULL + (_QWORD)v173;
      UFG::PersistentData::List::Deserialize((UFG::PersistentData::List *)v199[271].mTimestamp, v8);
    }
    else
    {
      v174.mUID = v171->mUID;
      v175 = UFG::qSymbol::as_cstr_dbg(v171);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game for key %d (%s)\n",
        v174.mUID,
        v175);
    }
  }
  v176 = ptr;
  v177 = 16i64;
  do
  {
    UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)v176);
    v176 += 72;
    --v177;
  }
  while ( v177 );
  v178 = 1;
LABEL_202:
  `eh vector destructor iterator'(
    ptr,
    0x48ui64,
    16,
    (void (__fastcall *)(void *))UFG::qTreeRB<UFG::DataEntry,UFG::DataEntry,0>::~qTreeRB<UFG::DataEntry,UFG::DataEntry,0>);
  return v178;
}t;
      if ( v173 )
        v8 = (char *)&v172->mNULL + (_QWORD)v173;
      UFG::PersistentData::List::Deserialize((UFG::PersistentData::List *)v199[271].mTimestamp, v8);
    }
    else
    {
      v174.mUID = v171->mUID;
      v175 = UFG::qSymbol::as_cstr_dbg(v171);
      UFG::qPrintf(
        "[GameSnapshot::DeserializeByFilter]: could not find entry in save game fo

