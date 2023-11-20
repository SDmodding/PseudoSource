// File Line: 17
// RVA: 0x1457840
__int64 UFG::Fingerprint::_dynamic_initializer_for__file_name__()
{
  UFG::qString::qString(&file_name);
  return atexit(UFG::Fingerprint::_dynamic_atexit_destructor_for__file_name__);
}

// File Line: 29
// RVA: 0x87DD0
void __fastcall UFG::Fingerprint::InitFingerprintSystem(const char *name_of_sig_file)
{
  const char *v1; // rbx
  char *v2; // rax
  char *v3; // r11
  signed int v4; // er8
  char *v5; // r9
  __int64 v6; // rdx
  char v7; // al
  char *v8; // r9
  signed __int64 v9; // r8
  unsigned int v10; // eax
  signed __int64 v11; // rbx
  signed __int64 v12; // rdi
  signed __int64 v13; // rsi
  signed __int64 v14; // r14
  _BYTE *v15; // r10
  char v16; // cl
  char *v17; // rdx
  char v18; // cl
  char *v19; // rdx
  char *v20; // rdx
  char v21; // cl
  char *v22; // rdx
  char v23; // cl
  char v24; // cl
  char v25; // dl
  char v26; // cl
  char v27; // dl
  char v28; // cl
  char v29; // dl
  char v30; // cl
  char v31; // r10
  signed __int64 v32; // rdx
  char v33; // al
  char *v34; // rcx
  char *v35; // r13
  const char *v36; // rbx
  char *v37; // r8
  signed __int64 v38; // rdx
  signed __int64 v39; // rdi
  signed __int64 v40; // rsi
  signed __int64 v41; // r14
  signed __int64 v42; // r15
  char v43; // al
  char *v44; // rcx
  signed __int64 v45; // rdx
  char v46; // al
  char *v47; // rcx
  __int64 v48; // [rsp+30h] [rbp-20h]
  __int64 v49; // [rsp+38h] [rbp-18h]
  char v50; // [rsp+40h] [rbp-10h]
  __int64 loaded_size; // [rsp+88h] [rbp+38h]

  v1 = name_of_sig_file;
  UFG::qString::Set(&file_name, name_of_sig_file);
  loaded_size = 0i64;
  v2 = (char *)UFG::StreamFileWrapper::ReadEntireFile(v1, &loaded_size, 0i64, 0, "StreamFileWrapper::ReadEntireFile");
  v48 = 0xF2E4AF21CCD00713i64;
  v3 = v2 + 16;
  LOBYTE(v49) = 26;
  UFG::Fingerprint::g_FileBuffer = v2;
  v4 = 0;
  v5 = UFG::Fingerprint::gKeyList;
  UFG::Fingerprint::gMarker = v2 + 16;
  do
  {
    ++v5;
    v6 = v4 % 9;
    v7 = 13 * v4++;
    *(v5 - 1) = v7 + *((_BYTE *)&v48 + v6);
  }
  while ( v4 < 560 );
  v8 = v3 + 16;
  v48 = *(_QWORD *)a01234567_0;
  v49 = 5063528411713059128i64;
  v50 = 0;
  v9 = 0i64;
  v10 = 1431655765;
  v11 = v3 - &UFG::Fingerprint::gKeyList[1] + 17;
  v12 = v3 - &UFG::Fingerprint::gKeyList[1] + 18;
  v13 = v3 - &UFG::Fingerprint::gKeyList[1] + 19;
  v14 = v3 - &UFG::Fingerprint::gKeyList[1] + 20;
  v15 = v3 + 16;
  do
  {
    v16 = UFG::Fingerprint::gKeyList[v9];
    v17 = &UFG::Fingerprint::gKeyList[v9];
    v9 += 5i64;
    *v15 ^= v16;
    v15 += 5;
    v17[v11 + 1] ^= v17[1];
    v17[v12 + 1] ^= v17[2];
    v17[v13 + 1] ^= v17[3];
    v17[v14 + 1] ^= v17[4];
  }
  while ( v9 < 560 );
  v18 = *v8;
  v19 = v3 + 16;
  if ( *v8 )
  {
    do
    {
      if ( v19 >= v3 + 272 )
        break;
      ++v19;
      v10 = v18 ^ __ROL4__(v10, 7);
      v18 = *v19;
    }
    while ( *v19 );
  }
  v20 = v3 + 272;
  v21 = v3[272];
  if ( v21 )
  {
    do
    {
      if ( v20 >= v3 + 528 )
        break;
      ++v20;
      v10 = v21 ^ __ROL4__(v10, 7);
      v21 = *v20;
    }
    while ( *v20 );
  }
  v22 = v3 + 528;
  v23 = v3[528];
  if ( v23 )
  {
    do
    {
      if ( v22 >= v3 + 544 )
        break;
      ++v22;
      v10 = v23 ^ __ROL4__(v10, 7);
      v23 = *v22;
    }
    while ( *v22 );
  }
  v24 = 1;
  if ( v3[544] != *((_BYTE *)&v48 + (v10 & 0xF)) )
    v24 = 0;
  v25 = v24;
  if ( v3[545] != *((_BYTE *)&v48 + ((unsigned __int8)v10 >> 4)) )
    v25 = 0;
  v26 = v25;
  if ( v3[546] != *((_BYTE *)&v48 + (((unsigned __int64)v10 >> 8) & 0xF)) )
    v26 = 0;
  v27 = v26;
  if ( v3[547] != *((_BYTE *)&v48 + ((unsigned __int16)v10 >> 12)) )
    v27 = 0;
  v28 = v27;
  if ( v3[548] != *((_BYTE *)&v48 + (((unsigned __int64)v10 >> 16) & 0xF)) )
    v28 = 0;
  v29 = v28;
  if ( v3[549] != *((_BYTE *)&v48 + (((unsigned __int64)v10 >> 20) & 0xF)) )
    v29 = 0;
  v30 = v29;
  if ( v3[550] != *((_BYTE *)&v48 + (((unsigned __int64)v10 >> 24) & 0xF)) )
    v30 = 0;
  v31 = v30;
  if ( v3[551] != *((_BYTE *)&v48 + (v10 >> 28)) )
    v31 = 0;
  v32 = 0i64;
  do
  {
    v33 = UFG::Fingerprint::gKeyList[v32];
    v34 = &UFG::Fingerprint::gKeyList[v32];
    v32 += 5i64;
    *v8 ^= v33;
    v8 += 5;
    v34[v11 + 1] ^= v34[1];
    v34[v12 + 1] ^= v34[2];
    v34[v13 + 1] ^= v34[3];
    v34[v14 + 1] ^= v34[4];
  }
  while ( v32 < 560 );
  if ( v31 )
  {
    v35 = UFG::Fingerprint::gMarker;
    v36 = UFG::Fingerprint::gMarker + 16;
    v37 = UFG::Fingerprint::gMarker + 16;
    v38 = 0i64;
    v39 = UFG::Fingerprint::gMarker - &UFG::Fingerprint::gKeyList[1] + 17;
    v40 = UFG::Fingerprint::gMarker - &UFG::Fingerprint::gKeyList[1] + 18;
    v41 = UFG::Fingerprint::gMarker - &UFG::Fingerprint::gKeyList[1] + 19;
    v42 = UFG::Fingerprint::gMarker - &UFG::Fingerprint::gKeyList[1] + 20;
    do
    {
      v43 = UFG::Fingerprint::gKeyList[v38];
      v44 = &UFG::Fingerprint::gKeyList[v38];
      v38 += 5i64;
      *v37 ^= v43;
      v37 += 5;
      v44[v39 + 1] ^= v44[1];
      v44[v40 + 1] ^= v44[2];
      v44[v41 + 1] ^= v44[3];
      v44[v42 + 1] ^= v44[4];
    }
    while ( v38 < 560 );
    UFG::qStringCopy(UFG::Fingerprint::g_WatermarkTrustee, 256, v35 + 272, -1);
    UFG::Fingerprint::g_showTrustee = (unsigned int)UFG::qStringCompare(
                                                      UFG::Fingerprint::g_WatermarkTrustee,
                                                      "nobody",
                                                      6) != 0;
    UFG::qStringCopy(UFG::Fingerprint::g_Registrar, 256, v36, -1);
    UFG::qStringCopy(UFG::Fingerprint::g_SerialNumber, 16, v35 + 528, -1);
    v45 = v36 - v35 - 16;
    do
    {
      v46 = UFG::Fingerprint::gKeyList[v45];
      v47 = &UFG::Fingerprint::gKeyList[v45];
      v45 += 5i64;
      *v36 ^= v46;
      v36 += 5;
      v47[v39 + 1] ^= v47[1];
      v47[v40 + 1] ^= v47[2];
      v47[v41 + 1] ^= v47[3];
      v47[v42 + 1] ^= v47[4];
    }
    while ( v45 < 560 );
  }
}

// File Line: 101
// RVA: 0x87DC0
char *__fastcall UFG::Fingerprint::GetFingerprintDataBlock()
{
  return UFG::Fingerprint::gMarker;
}

