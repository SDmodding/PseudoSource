// File Line: 33
// RVA: 0xBBEA0
void __fastcall UFG::UIMapInteriorManager::UIMapInteriorManager(UFG::UIMapInteriorManager *this)
{
  UFG::UIMapInteriorManager *v1; // rbx
  signed int v2; // ecx
  _QWORD *v3; // rax
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rax
  __int64 v27; // rax
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // rax
  __int64 v31; // rax
  __int64 v32; // rax
  __int64 v33; // rax
  __int64 v34; // rax
  __int64 v35; // rax
  __int64 v36; // rax
  __int64 v37; // rax
  __int64 v38; // rax
  __int64 v39; // rax
  __int64 v40; // rax
  __int64 v41; // rax
  __int64 v42; // rax
  __int64 v43; // rax
  __int64 v44; // rax
  __int64 v45; // rax
  __int64 v46; // rax
  __int64 v47; // rax
  __int64 v48; // rax
  __int64 v49; // rax
  __int64 v50; // rax
  __int64 v51; // rax
  __int64 v52; // rax
  __int64 v53; // rax
  __int128 v54; // [rsp+30h] [rbp-40h]
  __int128 v55; // [rsp+30h] [rbp-40h]
  __int128 v56; // [rsp+30h] [rbp-40h]
  __int128 v57; // [rsp+30h] [rbp-40h]
  __int128 v58; // [rsp+30h] [rbp-40h]
  __int128 v59; // [rsp+30h] [rbp-40h]
  __int128 v60; // [rsp+30h] [rbp-40h]
  __int128 v61; // [rsp+30h] [rbp-40h]
  __int128 v62; // [rsp+30h] [rbp-40h]
  __int128 v63; // [rsp+30h] [rbp-40h]
  __int128 v64; // [rsp+30h] [rbp-40h]
  __int128 v65; // [rsp+30h] [rbp-40h]
  __int128 v66; // [rsp+30h] [rbp-40h]
  __int128 v67; // [rsp+30h] [rbp-40h]
  __int128 v68; // [rsp+30h] [rbp-40h]
  __int128 v69; // [rsp+30h] [rbp-40h]
  __int128 v70; // [rsp+30h] [rbp-40h]
  __int128 v71; // [rsp+30h] [rbp-40h]
  __int128 v72; // [rsp+30h] [rbp-40h]
  __int128 v73; // [rsp+30h] [rbp-40h]
  __int128 v74; // [rsp+30h] [rbp-40h]
  __int128 v75; // [rsp+30h] [rbp-40h]
  __int128 v76; // [rsp+30h] [rbp-40h]
  __int128 v77; // [rsp+30h] [rbp-40h]
  __int128 v78; // [rsp+30h] [rbp-40h]
  __int128 v79; // [rsp+40h] [rbp-30h]
  __int128 v80; // [rsp+50h] [rbp-20h]
  __int128 v81; // [rsp+50h] [rbp-20h]
  __int128 v82; // [rsp+50h] [rbp-20h]
  __int128 v83; // [rsp+50h] [rbp-20h]
  __int128 v84; // [rsp+50h] [rbp-20h]
  __int128 v85; // [rsp+50h] [rbp-20h]
  __int128 v86; // [rsp+50h] [rbp-20h]
  __int128 v87; // [rsp+50h] [rbp-20h]
  __int128 v88; // [rsp+50h] [rbp-20h]
  __int128 v89; // [rsp+50h] [rbp-20h]
  __int128 v90; // [rsp+50h] [rbp-20h]
  __int128 v91; // [rsp+50h] [rbp-20h]
  __int128 v92; // [rsp+50h] [rbp-20h]
  __int128 v93; // [rsp+50h] [rbp-20h]
  __int128 v94; // [rsp+50h] [rbp-20h]
  __int128 v95; // [rsp+60h] [rbp-10h]

  v1 = this;
  *(_WORD *)&this->mActive = 0;
  *(_QWORD *)&this->mActiveInterior = 0i64;
  this->mNumInteriors = 0;
  v2 = 24;
  v3 = (_QWORD *)&v1->mData[0].WorldGeo.MinY;
  do
  {
    *(v3 - 1) = 0i64;
    *v3 = 0i64;
    v3[1] = 0i64;
    v3 += 8;
    --v2;
  }
  while ( v2 >= 0 );
  UFG::qString::qString(&v1->mTextureName);
  UFG::qString::qString(&v1->mTexturePack);
  v1->mTextureLoaded = 0;
  *(_QWORD *)&v1->OldMapGeo.MinX = 0i64;
  *(_QWORD *)&v1->OldMapGeo.MinY = 0i64;
  *(_QWORD *)&v1->OldMapGeo.TextureWidth = 0i64;
  LODWORD(v54) = 1;
  *(_QWORD *)((char *)&v54 + 4) = __PAIR__(LODWORD(FLOAT_1776_6589), LODWORD(FLOAT_1700_2));
  *((float *)&v54 + 3) = FLOAT_N376_70001;
  *(float *)&v79 = FLOAT_N300_24103;
  *(_QWORD *)((char *)&v79 + 4) = 4863887598692597760i64;
  *(_QWORD *)&v80 = "Interior_Sweatshop";
  *((_QWORD *)&v80 + 1) = 4692750811720056834i64;
  *(float *)&v95 = FLOAT_15_0;
  DWORD2(v95) = 1065353216;
  v4 = v1->mNumInteriors;
  if ( (_DWORD)v4 != 25 )
  {
    v5 = v4 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v5) = v54;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v5) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v5) = v80;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v5) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v55) = 2;
  *(_QWORD *)((char *)&v55 + 4) = __PAIR__(LODWORD(FLOAT_932_92664), LODWORD(FLOAT_856_20398));
  *((float *)&v55 + 3) = FLOAT_29_049;
  *(float *)&v79 = FLOAT_105_77168;
  *(_QWORD *)((char *)&v79 + 4) = 4863887598692597760i64;
  *(_QWORD *)&v81 = "Interior_BamBam";
  DWORD2(v81) = 1;
  *((float *)&v81 + 3) = FLOAT_26_0;
  DWORD2(v95) = 1065353216;
  v6 = v1->mNumInteriors;
  if ( (_DWORD)v6 != 25 )
  {
    v7 = v6 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v7) = v55;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v7) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v7) = v81;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v7) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v56) = 3;
  *(_QWORD *)((char *)&v56 + 4) = __PAIR__(LODWORD(FLOAT_N283_12863), LODWORD(FLOAT_N436_57401));
  *((float *)&v56 + 3) = FLOAT_996_26501;
  *(float *)&v79 = FLOAT_1149_7104;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v82 = "Interior_Hospital";
  DWORD2(v82) = 1;
  *((float *)&v82 + 3) = FLOAT_13_0;
  DWORD2(v95) = 1065353216;
  v8 = v1->mNumInteriors;
  if ( (_DWORD)v8 != 25 )
  {
    v9 = v8 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v9) = v56;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v9) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v9) = v82;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v9) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v57) = 4;
  *(_QWORD *)((char *)&v57 + 4) = __PAIR__(LODWORD(FLOAT_452_09), LODWORD(FLOAT_422_94));
  *((float *)&v57 + 3) = FLOAT_591_57001;
  *(float *)&v79 = FLOAT_620_72003;
  *(_QWORD *)((char *)&v79 + 4) = 4863887598692597760i64;
  *(_QWORD *)&v82 = "Interior_Vivienne";
  DWORD2(v82) = 0;
  DWORD2(v95) = 1065353216;
  v10 = v1->mNumInteriors;
  if ( (_DWORD)v10 != 25 )
  {
    v11 = v10 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v11) = v57;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v11) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v11) = v82;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v11) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v58) = 5;
  *(_QWORD *)((char *)&v58 + 4) = __PAIR__(LODWORD(FLOAT_N330_26367), LODWORD(FLOAT_N368_625));
  *((float *)&v58 + 3) = FLOAT_427_935;
  *(float *)&v79 = FLOAT_466_29633;
  *(_QWORD *)((char *)&v79 + 4) = 4863887598692597760i64;
  *(_QWORD *)&v82 = "Interior_RivalBoss";
  DWORD2(v82) = 0;
  DWORD2(v95) = 1065353216;
  v12 = v1->mNumInteriors;
  if ( (_DWORD)v12 != 25 )
  {
    v13 = v12 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v13) = v58;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v13) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v13) = v82;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v13) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v59) = 6;
  *(_QWORD *)((char *)&v59 + 4) = __PAIR__(LODWORD(FLOAT_1476_287), LODWORD(FLOAT_1426_287));
  *((float *)&v59 + 3) = FLOAT_N539_23297;
  *(float *)&v79 = FLOAT_N489_23297;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v82 = "Interior_PendrewHQ";
  DWORD2(v82) = 0;
  DWORD2(v95) = 1065353216;
  v14 = v1->mNumInteriors;
  if ( (_DWORD)v14 != 25 )
  {
    v15 = v14 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v15) = v59;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v15) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v15) = v82;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v15) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v60) = 7;
  *(_QWORD *)((char *)&v60 + 4) = __PAIR__(LODWORD(FLOAT_158_78369), LODWORD(FLOAT_82_060997));
  *((float *)&v60 + 3) = FLOAT_505_953;
  *(float *)&v79 = FLOAT_582_67566;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v83 = "Interior_Karaoke";
  DWORD2(v83) = 1;
  *((float *)&v83 + 3) = FLOAT_37_299999;
  DWORD2(v95) = 1065353216;
  v16 = v1->mNumInteriors;
  if ( (_DWORD)v16 != 25 )
  {
    v17 = v16 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v17) = v60;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v17) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v17) = v83;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v17) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v61) = 8;
  *(_QWORD *)((char *)&v61 + 4) = __PAIR__(LODWORD(FLOAT_699_43835), LODWORD(FLOAT_545_99298));
  *((float *)&v61 + 3) = FLOAT_971_797;
  *(float *)&v79 = FLOAT_1125_2424;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v84 = "Interior_Strip01";
  DWORD2(v84) = 1;
  *((float *)&v84 + 3) = FLOAT_9_0;
  DWORD2(v95) = 1065353216;
  v18 = v1->mNumInteriors;
  if ( (_DWORD)v18 != 25 )
  {
    v19 = v18 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v19) = v61;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v19) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v19) = v84;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v19) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v62) = 9;
  *(_QWORD *)((char *)&v62 + 4) = __PAIR__(LODWORD(FLOAT_768_45667), LODWORD(FLOAT_691_73401));
  *((float *)&v62 + 3) = FLOAT_1106_019;
  *(float *)&v79 = FLOAT_1182_7417;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v85 = "Interior_Strip02";
  *((_QWORD *)&v85 + 1) = 4692750811720056833i64;
  DWORD2(v95) = 1065353216;
  v20 = v1->mNumInteriors;
  if ( (_DWORD)v20 != 25 )
  {
    v21 = v20 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v21) = v62;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v21) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v21) = v85;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v21) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v63) = 10;
  *(_QWORD *)((char *)&v63 + 4) = __PAIR__(LODWORD(FLOAT_469_08069), LODWORD(FLOAT_392_358));
  *((float *)&v63 + 3) = FLOAT_999_16803;
  *(float *)&v79 = FLOAT_1075_8907;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v85 = "Interior_Loading01";
  DWORD2(v85) = 0;
  DWORD2(v95) = 1065353216;
  v22 = v1->mNumInteriors;
  if ( (_DWORD)v22 != 25 )
  {
    v23 = v22 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v23) = v63;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v23) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v23) = v85;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v23) = v95;
    ++v1->mNumInteriors;
  }
  *(_QWORD *)&v64 = 4672889938050547723i64;
  *((_QWORD *)&v64 + 1) = __PAIR__(LODWORD(FLOAT_N747_69501), LODWORD(FLOAT_83_517685));
  *(float *)&v79 = FLOAT_N670_97229;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v86 = "Interior_SmilesHQ";
  *((_QWORD *)&v86 + 1) = 4672889938050547713i64;
  DWORD2(v95) = 1065353216;
  v24 = v1->mNumInteriors;
  if ( (_DWORD)v24 != 25 )
  {
    v25 = v24 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v25) = v64;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v25) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v25) = v86;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v25) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v65) = 12;
  *(_QWORD *)((char *)&v65 + 4) = __PAIR__(LODWORD(FLOAT_N0_95600128), LODWORD(FLOAT_N102_882));
  *((float *)&v65 + 3) = FLOAT_1000_968;
  *(float *)&v79 = FLOAT_1102_894;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v87 = "Interior_Banquet";
  DWORD2(v87) = 1;
  *((float *)&v87 + 3) = FLOAT_17_9;
  DWORD2(v95) = 1065353216;
  v26 = v1->mNumInteriors;
  if ( (_DWORD)v26 != 25 )
  {
    v27 = v26 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v27) = v65;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v27) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v27) = v87;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v27) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v66) = 13;
  *(_QWORD *)((char *)&v66 + 4) = __PAIR__(LODWORD(FLOAT_526_85669), LODWORD(FLOAT_450_134));
  *((float *)&v66 + 3) = FLOAT_607_93903;
  *(float *)&v79 = FLOAT_684_66174;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v88 = "Interior_Fifi";
  *((_QWORD *)&v88 + 1) = 4725287065887965185i64;
  DWORD2(v95) = 1065353216;
  v28 = v1->mNumInteriors;
  if ( (_DWORD)v28 != 25 )
  {
    v29 = v28 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v29) = v66;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v29) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v29) = v88;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v29) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v67) = 14;
  *(_QWORD *)((char *)&v67 + 4) = __PAIR__(LODWORD(FLOAT_930_88501), LODWORD(FLOAT_898_61499));
  *((float *)&v67 + 3) = FLOAT_N238_269;
  *(float *)&v79 = FLOAT_N205_99899;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v89 = "Interior_ChuRest";
  DWORD2(v89) = 1;
  *((float *)&v89 + 3) = FLOAT_19_5;
  *((float *)&v95 + 2) = FLOAT_0_60000002;
  v30 = v1->mNumInteriors;
  if ( (_DWORD)v30 != 25 )
  {
    v31 = v30 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v31) = v67;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v31) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v31) = v89;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v31) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v68) = 15;
  *(_QWORD *)((char *)&v68 + 4) = __PAIR__(LODWORD(FLOAT_N242_93799), LODWORD(FLOAT_N282_93799));
  *((float *)&v68 + 3) = FLOAT_N788_73401;
  *(float *)&v79 = FLOAT_N748_73401;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v89 = "Interior_SafehouseAB";
  DWORD2(v89) = 0;
  DWORD2(v95) = 1065353216;
  v32 = v1->mNumInteriors;
  if ( (_DWORD)v32 != 25 )
  {
    v33 = v32 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v33) = v68;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v33) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v33) = v89;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v33) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v69) = 16;
  *(_QWORD *)((char *)&v69 + 4) = __PAIR__(LODWORD(FLOAT_276_24469), LODWORD(FLOAT_199_522));
  *((float *)&v69 + 3) = FLOAT_872_203;
  *(float *)&v79 = FLOAT_948_92566;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v90 = "Interior_SafehouseCT";
  *((_QWORD *)&v90 + 1) = 4725287065887965185i64;
  DWORD2(v95) = 1065353216;
  v34 = v1->mNumInteriors;
  if ( (_DWORD)v34 != 25 )
  {
    v35 = v34 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v35) = v69;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v35) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v35) = v90;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v35) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v70) = 17;
  *(_QWORD *)((char *)&v70 + 4) = __PAIR__(LODWORD(FLOAT_N677_28625), LODWORD(FLOAT_N754_00897));
  *((float *)&v70 + 3) = FLOAT_745_43701;
  *(float *)&v79 = FLOAT_822_15967;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v90 = "Interior_SafehouseKT";
  DWORD2(v90) = 0;
  DWORD2(v95) = 1065353216;
  v36 = v1->mNumInteriors;
  if ( (_DWORD)v36 != 25 )
  {
    v37 = v36 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v37) = v70;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v37) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v37) = v90;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v37) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v71) = 18;
  *(_QWORD *)((char *)&v71 + 4) = __PAIR__(LODWORD(FLOAT_901_43396), LODWORD(FLOAT_865_53198));
  *((float *)&v71 + 3) = FLOAT_N118_362;
  *(float *)&v79 = FLOAT_N82_459999;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v90 = "Interior_SafehouseNP";
  DWORD2(v90) = 0;
  DWORD2(v95) = 1065353216;
  v38 = v1->mNumInteriors;
  if ( (_DWORD)v38 != 25 )
  {
    v39 = v38 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v39) = v71;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v39) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v39) = v90;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v39) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v72) = 19;
  *(_QWORD *)((char *)&v72 + 4) = __PAIR__(LODWORD(FLOAT_N49_455002), LODWORD(FLOAT_N141_07401));
  *((float *)&v72 + 3) = FLOAT_1691_7271;
  *(float *)&v79 = FLOAT_1783_3461;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v91 = "Interior_CTPenthouse";
  DWORD2(v91) = 3;
  *((float *)&v91 + 3) = FLOAT_65_099998;
  *(_QWORD *)&v95 = __PAIR__(LODWORD(FLOAT_73_099998), LODWORD(FLOAT_69_099998));
  DWORD2(v95) = 1065353216;
  v40 = v1->mNumInteriors;
  if ( (_DWORD)v40 != 25 )
  {
    v41 = v40 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v41) = v72;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v41) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v41) = v91;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v41) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v73) = 20;
  *(_QWORD *)((char *)&v73 + 4) = __PAIR__(LODWORD(FLOAT_941_47571), LODWORD(FLOAT_864_75299));
  *((float *)&v73 + 3) = FLOAT_N508_01001;
  *(float *)&v79 = FLOAT_N431_28732;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v91 = "Interior_DojoNP";
  DWORD2(v91) = 0;
  DWORD2(v95) = 1065353216;
  v42 = v1->mNumInteriors;
  if ( (_DWORD)v42 != 25 )
  {
    v43 = v42 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v43) = v73;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v43) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v43) = v91;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v43) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v74) = 21;
  *(_QWORD *)((char *)&v74 + 4) = __PAIR__(LODWORD(FLOAT_N308_6463), LODWORD(FLOAT_N385_36899));
  *((float *)&v74 + 3) = FLOAT_408_547;
  *(float *)&v79 = FLOAT_485_26968;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v92 = "Interior_Mansion";
  DWORD2(v92) = 1;
  *((float *)&v92 + 3) = FLOAT_57_5;
  DWORD2(v95) = 1065353216;
  v44 = v1->mNumInteriors;
  if ( (_DWORD)v44 != 25 )
  {
    v45 = v44 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v45) = v74;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v45) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v45) = v92;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v45) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v75) = 22;
  *(_QWORD *)((char *)&v75 + 4) = __PAIR__(LODWORD(FLOAT_N485_20932), LODWORD(FLOAT_N561_93201));
  *((float *)&v75 + 3) = FLOAT_1945_229;
  *(float *)&v79 = FLOAT_2021_9517;
  *(_QWORD *)((char *)&v79 + 4) = 4863887598692597760i64;
  *(_QWORD *)&v93 = "Interior_GDenCT";
  *((_QWORD *)&v93 + 1) = 4647714815446351872i64;
  DWORD2(v95) = 1065353216;
  v46 = v1->mNumInteriors;
  if ( (_DWORD)v46 != 25 )
  {
    v47 = v46 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v47) = v75;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v47) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v47) = v93;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v47) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v76) = 23;
  *(_QWORD *)((char *)&v76 + 4) = __PAIR__(LODWORD(FLOAT_510_76569), LODWORD(FLOAT_434_043));
  *((float *)&v76 + 3) = FLOAT_N1584_667;
  *(float *)&v79 = FLOAT_N1507_9443;
  *(_QWORD *)((char *)&v79 + 4) = 4863887598692597760i64;
  *(_QWORD *)&v94 = "Interior_GDenNP";
  *((_QWORD *)&v94 + 1) = 4647714815446351872i64;
  DWORD2(v95) = 1065353216;
  v48 = v1->mNumInteriors;
  if ( (_DWORD)v48 != 25 )
  {
    v49 = v48 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v49) = v76;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v49) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v49) = v94;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v49) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v77) = 24;
  *(_QWORD *)((char *)&v77 + 4) = __PAIR__(LODWORD(FLOAT_1464_922), LODWORD(FLOAT_1264_922));
  *((float *)&v77 + 3) = FLOAT_385_62601;
  *(float *)&v79 = FLOAT_585_62598;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v94 = "Interior_Highway";
  DWORD2(v94) = 0;
  DWORD2(v95) = 1065353216;
  v50 = v1->mNumInteriors;
  if ( (_DWORD)v50 != 25 )
  {
    v51 = v50 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v51) = v77;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v51) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v51) = v94;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v51) = v95;
    ++v1->mNumInteriors;
  }
  LODWORD(v78) = 25;
  *(_QWORD *)((char *)&v78 + 4) = __PAIR__(LODWORD(FLOAT_N144_39899), LODWORD(FLOAT_N282_39899));
  *((float *)&v78 + 3) = FLOAT_N565_40198;
  *(float *)&v79 = FLOAT_N427_40198;
  *(_QWORD *)((char *)&v79 + 4) = 4899916395719950336i64;
  *(_QWORD *)&v94 = "Interior_FishMarket";
  DWORD2(v94) = 0;
  DWORD2(v95) = 1065353216;
  v52 = v1->mNumInteriors;
  if ( (_DWORD)v52 != 25 )
  {
    v53 = v52 << 6;
    *(_OWORD *)((char *)&v1->mData[0].InteriorId + v53) = v78;
    *(_OWORD *)((char *)&v1->mData[0].WorldGeo.MaxY + v53) = v79;
    *(_OWORD *)((char *)&v1->mData[0].TexturePrefix + v53) = v94;
    *(_OWORD *)((char *)&v1->mData[0].ElevationLevel[1] + v53) = v95;
    ++v1->mNumInteriors;
  }
}

// File Line: 383
// RVA: 0xC4B60
void __fastcall UFG::UIMapInteriorManager::HandleScreenDestruct(UFG::UIMapInteriorManager *this, UFG::UITiledMapWidget *mapWidget)
{
  if ( this->mActive )
    UFG::UIMapInteriorManager::Deactivate(this, mapWidget, 0i64);
}

// File Line: 393
// RVA: 0xCC370
void __fastcall UFG::UIMapInteriorManager::Update(UFG::UIMapInteriorManager *this, UFG::UIScreen *screen, UFG::qVector3 *playerPos, UFG::UITiledMapWidget *mapWidget, UFG::UITiledMapTextureManager *minimapStreamer)
{
  UFG::UITiledMapWidget *v5; // rsi
  UFG::qVector3 *v6; // rbp
  UFG::UIMapInteriorManager *v7; // rbx
  UFG::UITiledMapInteriorData *v8; // rdi
  UFG::eInteriors v9; // eax
  bool v10; // cl
  UFG::UITiledMapInteriorData *v11; // rax
  unsigned int v12; // er8
  unsigned int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm0_4
  UFG::eInteriors v18; // er8
  unsigned int v19; // ecx
  unsigned int v20; // edx
  UFG::eInteriors v21; // er8
  unsigned int v22; // ecx
  unsigned int v23; // edx
  float *v24; // rcx
  char v25; // [rsp+28h] [rbp-40h]
  __int64 v26; // [rsp+38h] [rbp-30h]
  unsigned int v27; // [rsp+40h] [rbp-28h]
  __int64 v28; // [rsp+48h] [rbp-20h]

  if ( screen )
  {
    v5 = mapWidget;
    v6 = playerPos;
    v7 = this;
    if ( screen->mRenderable->m_movie.pObject )
    {
      v8 = 0i64;
      v26 = 0i64;
      v27 = 0;
      v9 = (unsigned int)UFG::UIMapInteriorManager::CheckPosition(this, playerPos);
      if ( UFG::UITiledMapTweakables::ForceInteriorActive )
      {
        if ( v9 == INTERIOR_NONE )
          v9 = 1;
        if ( v7->mActive )
        {
LABEL_17:
          v11 = UFG::UIMapInteriorManager::FindData(v7, v7->mActiveInterior);
          v8 = v11;
          if ( !v11 )
            goto LABEL_49;
          v12 = 0;
          v13 = 0;
          v14 = v11->ElevationLevelCount;
          if ( v14 )
          {
            do
            {
              if ( v6->z <= v8->ElevationLevel[v13] )
                break;
              ++v12;
              ++v13;
            }
            while ( v13 < v14 );
          }
          v15 = v7->mElevationLevel;
          if ( v15 <= v12 )
          {
            if ( v15 >= v12 )
              goto LABEL_31;
            v17 = 0.0;
            if ( v12 )
              v17 = v8->ElevationLevel[v12 - 1];
            if ( (float)(v17 + 0.2) >= v6->z )
              goto LABEL_31;
          }
          else
          {
            v16 = 0.0;
            if ( v15 )
              v16 = v8->ElevationLevel[v15 - 1];
            if ( (float)(v16 - 0.2) <= v6->z )
              goto LABEL_31;
          }
          v7->mElevationLevel = v12;
          v7->mChanged = 1;
LABEL_31:
          if ( v7->mChanged )
          {
            v7->mChanged = 0;
            if ( !v8 )
            {
              v18 = v7->mActiveInterior;
              if ( v18 == INTERIOR_NONE )
                goto LABEL_49;
              v19 = 0;
              v20 = v7->mNumInteriors;
              if ( !v20 )
                goto LABEL_49;
              while ( v7->mData[(unsigned __int64)v19].InteriorId != v18 )
              {
                if ( ++v19 >= v20 )
                  goto LABEL_49;
              }
              v8 = &v7->mData[(unsigned __int64)v19];
              if ( !v8 )
                goto LABEL_49;
            }
            UFG::UIMapInteriorManager::LoadTexturePack(v7, v8);
          }
          if ( UFG::UITiledMapTweakables::FakeInteriorMapCoords )
          {
            if ( v7->mActive )
            {
              v21 = v7->mActiveInterior;
              if ( v21 )
              {
                v22 = 0;
                v23 = v7->mNumInteriors;
                if ( v23 )
                {
                  while ( v7->mData[(unsigned __int64)v22].InteriorId != v21 )
                  {
                    if ( ++v22 >= v23 )
                      goto LABEL_49;
                  }
                  v24 = (float *)&v7->mData[(unsigned __int64)v22].InteriorId;
                  if ( v24 )
                  {
                    UFG::UITiledMapMath::WorldGeo.MinX = UFG::UITiledMapTweakables::InteriorMapWorldX;
                    UFG::UITiledMapMath::WorldGeo.MinY = UFG::UITiledMapTweakables::InteriorMapWorldY;
                    UFG::UITiledMapMath::WorldGeo.MaxX = (float)(v24[2] - v24[1])
                                                       + UFG::UITiledMapTweakables::InteriorMapWorldX;
                    UFG::UITiledMapMath::WorldGeo.MaxY = (float)(v24[4] - v24[3])
                                                       + UFG::UITiledMapTweakables::InteriorMapWorldY;
                  }
                }
              }
            }
          }
LABEL_49:
          if ( (v27 >> 6) & 1 )
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v26 + 16i64))(v26, &v25, v28);
          return;
        }
        goto LABEL_15;
      }
      v10 = v7->mActive;
      if ( v9 )
      {
        if ( !v10 )
          goto LABEL_15;
      }
      else if ( v10 )
      {
        UFG::UIMapInteriorManager::Deactivate(v7, v5, minimapStreamer);
        goto LABEL_16;
      }
      if ( v7->mActiveInterior == v9 || !v10 )
      {
LABEL_16:
        if ( !v7->mActive )
          goto LABEL_31;
        goto LABEL_17;
      }
LABEL_15:
      UFG::UIMapInteriorManager::Activate(v7, v9, v5, minimapStreamer);
      goto LABEL_16;
    }
  }
}

// File Line: 529
// RVA: 0xBDD20
void __fastcall UFG::UIMapInteriorManager::Activate(UFG::UIMapInteriorManager *this, UFG::eInteriors interior, UFG::UITiledMapWidget *mapWidget, UFG::UITiledMapTextureManager *minimapStreamer)
{
  UFG::UITiledMapTextureManager *v4; // rsi
  bool v5; // r9
  UFG::UITiledMapWidget *v6; // r14
  UFG::eInteriors v7; // edi
  UFG::UIMapInteriorManager *v8; // rbx
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned __int64 v11; // rbp
  float v12; // xmm0_4

  v4 = minimapStreamer;
  v5 = this->mActive;
  v6 = mapWidget;
  v7 = interior;
  v8 = this;
  if ( !this->mActive || this->mActiveInterior != interior )
  {
    if ( interior )
    {
      v9 = this->mNumInteriors;
      v10 = 0;
      if ( v9 )
      {
        while ( v8->mData[(unsigned __int64)v10].InteriorId != v7 )
        {
          if ( ++v10 >= v9 )
            return;
        }
        v11 = (unsigned __int64)&v8->mData[(unsigned __int64)v10];
        if ( v11 )
        {
          if ( v5 )
            UFG::UIMapInteriorManager::Deactivate(v8, mapWidget, 0i64);
          if ( v4 )
          {
            if ( v4->mActive )
            {
              v4->mActive = 0;
              *(_QWORD *)&v4->old_col = -1i64;
              UFG::UITiledMapTextureManager::ReleaseAllTextures(v4);
            }
          }
          *(_WORD *)&v8->mActive = 257;
          v8->mActiveInterior = v7;
          v8->mElevationLevel = 0;
          v8->OldMapGeo.MinX = UFG::UITiledMapMath::WorldGeo.MinX;
          v8->OldMapGeo.MaxX = UFG::UITiledMapMath::WorldGeo.MaxX;
          v8->OldMapGeo.MinY = UFG::UITiledMapMath::WorldGeo.MinY;
          v8->OldMapGeo.MaxY = UFG::UITiledMapMath::WorldGeo.MaxY;
          v8->OldMapGeo.TextureWidth = UFG::UITiledMapMath::WorldGeo.TextureWidth;
          v8->OldMapGeo.TextureHeight = UFG::UITiledMapMath::WorldGeo.TextureHeight;
          v6->m_mapGeo.useTiledMap = 0;
          UFG::UITiledMapMath::WorldGeo.MinX = *(float *)(v11 + 4);
          UFG::UITiledMapMath::WorldGeo.MaxX = *(float *)(v11 + 8);
          UFG::UITiledMapMath::WorldGeo.MinY = *(float *)(v11 + 12);
          UFG::UITiledMapMath::WorldGeo.MaxY = *(float *)(v11 + 16);
          UFG::UITiledMapMath::WorldGeo.TextureWidth = *(float *)(v11 + 20);
          v12 = *(float *)(v11 + 24);
          UFG::UITiledMapTweakables::InteriorMapWorldX = UFG::UITiledMapMath::WorldGeo.MinX;
          UFG::UITiledMapMath::WorldGeo.TextureHeight = v12;
          UFG::UITiledMapTweakables::InteriorMapWorldY = UFG::UITiledMapMath::WorldGeo.MinY;
        }
      }
    }
  }
}

// File Line: 562
// RVA: 0xBECF0
void __fastcall UFG::UIMapInteriorManager::Deactivate(UFG::UIMapInteriorManager *this, UFG::UITiledMapWidget *mapWidget, UFG::UITiledMapTextureManager *minimapStreamer)
{
  char *v3; // rbx
  UFG::UITiledMapTextureManager *v4; // rsi
  UFG::UITiledMapWidget *v5; // rbp
  UFG::UIMapInteriorManager *v6; // rdi
  UFG::UIScreenTextureManager *v7; // rax

  v3 = this->mTexturePack.mData;
  v4 = minimapStreamer;
  v5 = mapWidget;
  v6 = this;
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v7, v3);
  v6->mActive = 0;
  v6->mActiveInterior = 0;
  v6->mTextureLoaded = 0;
  UFG::qString::Set(&v6->mTextureName, &customWorldMapCaption);
  UFG::qString::Set(&v6->mTexturePack, &customWorldMapCaption);
  if ( v4 && v4->mActive != 1 )
    v4->mActive = 1;
  v5->m_mapGeo.useTiledMap = 1;
  UFG::UITiledMapMath::WorldGeo.MinX = v6->OldMapGeo.MinX;
  UFG::UITiledMapMath::WorldGeo.MaxX = v6->OldMapGeo.MaxX;
  UFG::UITiledMapMath::WorldGeo.MinY = v6->OldMapGeo.MinY;
  UFG::UITiledMapMath::WorldGeo.MaxY = v6->OldMapGeo.MaxY;
  UFG::UITiledMapMath::WorldGeo.TextureWidth = v6->OldMapGeo.TextureWidth;
  UFG::UITiledMapMath::WorldGeo.TextureHeight = v6->OldMapGeo.TextureHeight;
}

// File Line: 582
// RVA: 0xBE8A0
__int64 __fastcall UFG::UIMapInteriorManager::CheckPosition(UFG::UIMapInteriorManager *this, UFG::qVector3 *pos)
{
  UFG::qVector3 *v2; // rdi
  UFG::UIMapInteriorManager *v3; // rbx
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  hkgpIndexedMesh::EdgeBarrier *v5; // rcx
  unsigned int v6; // edx
  unsigned int v7; // ecx
  float v8; // xmm1_4
  float *v9; // rax
  float v10; // xmm0_4

  v2 = pos;
  v3 = this;
  if ( !UFG::UITiledMapTweakables::MinimapForceIndoors
    && (UFG::UI::IsPlayerInVehicle()
     || Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v5, v4)
     || !UFG::TidoGame::IsInside()) )
  {
    return 0i64;
  }
  v6 = v3->mNumInteriors;
  v7 = 0;
  if ( !v6 )
    return 0i64;
  v8 = v2->x;
  v9 = &v3->mData[0].WorldGeo.MinY;
  while ( 1 )
  {
    if ( v8 >= *(v9 - 2) )
    {
      v10 = v2->y;
      if ( v10 >= *v9 && v8 <= *(v9 - 1) && v10 <= v9[1] )
        break;
    }
    ++v7;
    v9 += 16;
    if ( v7 >= v6 )
      return 0i64;
  }
  return *((unsigned int *)v9 - 3);
}

// File Line: 618
// RVA: 0xC0510
UFG::UITiledMapInteriorData *__fastcall UFG::UIMapInteriorManager::FindData(UFG::UIMapInteriorManager *this, UFG::eInteriors interior)
{
  UFG::eInteriors v2; // er8
  UFG::UIMapInteriorManager *v3; // r9
  unsigned int v4; // edx
  __int64 v5; // rax
  UFG::UITiledMapInteriorData *v6; // rcx

  v2 = interior;
  v3 = this;
  if ( interior == INTERIOR_NONE )
    return 0i64;
  v4 = this->mNumInteriors;
  v5 = 0i64;
  if ( !v4 )
    return 0i64;
  v6 = this->mData;
  while ( v6->InteriorId != v2 )
  {
    v5 = (unsigned int)(v5 + 1);
    ++v6;
    if ( (unsigned int)v5 >= v4 )
      return 0i64;
  }
  return &v3->mData[v5];
}

// File Line: 635
// RVA: 0xC5FD0
void __fastcall UFG::UIMapInteriorManager::LoadTexturePack(UFG::UIMapInteriorManager *this, UFG::UITiledMapInteriorData *data)
{
  UFG::UITiledMapInteriorData *v2; // rsi
  UFG::UIMapInteriorManager *v3; // rdi
  unsigned int v4; // er9
  const char *v5; // r8
  const char *v6; // rbx
  UFG::UIScreenTextureManager *v7; // rax
  UFG::qString *v8; // rax
  const char *v9; // rbx
  UFG::UIScreenTextureManager *v10; // rax
  UFG::qString v11; // [rsp+38h] [rbp-60h]
  UFG::qString result; // [rsp+60h] [rbp-38h]

  v2 = data;
  v3 = this;
  UFG::qString::qString(&v11);
  v4 = v3->mElevationLevel;
  v5 = v2->TexturePrefix;
  if ( v4 )
    UFG::qString::Format(&v11, "Data\\UI\\%s_%d_TexturePack.perm.bin", v5, v4 + 1);
  else
    UFG::qString::Format(&v11, "Data\\UI\\%s_TexturePack.perm.bin", v5);
  if ( (unsigned int)UFG::qStringCompare(v3->mTexturePack.mData, v11.mData, -1) )
  {
    v6 = v3->mTexturePack.mData;
    v7 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v7, v6);
    UFG::qString::Set(&v3->mTexturePack, v11.mData, v11.mLength, 0i64, 0);
    v8 = UFG::qString::FormatEx(&result, "img://%s_%d", v2->TexturePrefix, v3->mElevationLevel + 1);
    UFG::qString::Set(&v3->mTextureName, v8->mData, v8->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    v3->mTextureLoaded = 0;
    v9 = v3->mTexturePack.mData;
    v10 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v10,
      v9,
      DEFAULT_PRIORITY,
      UFG::UIMapInteriorManager::TextureLoadedCallback,
      0i64);
  }
  UFG::qString::~qString(&v11);
}

// File Line: 662
// RVA: 0xCB9F0
void __fastcall UFG::UIMapInteriorManager::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenHud::HandleMinimapInteriorTextureLoaded();
}

// File Line: 668
// RVA: 0xC4D80
void __fastcall UFG::UIMapInteriorManager::HandleTextureLoaded(UFG::UIMapInteriorManager *this)
{
  this->mChanged = 1;
  this->mTextureLoaded = 1;
}

