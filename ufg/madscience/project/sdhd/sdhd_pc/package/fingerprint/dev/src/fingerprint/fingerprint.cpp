// File Line: 17
// RVA: 0x1457840
__int64 UFG::Fingerprint::_dynamic_initializer_for__file_name__()
{
  UFG::qString::qString(&file_name);
  return atexit((int (__fastcall *)())UFG::Fingerprint::_dynamic_atexit_destructor_for__file_name__);
}

// File Line: 29
// RVA: 0x87DD0
void __fastcall UFG::Fingerprint::InitFingerprintSystem(const char *name_of_sig_file)
{
  char *v2; // rax
  char *v3; // r11
  int v4; // r8d
  char *v5; // r9
  __int64 v6; // rdx
  char v7; // al
  char *v8; // r9
  __int64 v9; // r8
  unsigned int v10; // eax
  __int64 v11; // rbx
  __int64 v12; // rdi
  __int64 v13; // rsi
  __int64 v14; // r14
  _BYTE *v15; // r10
  char v16; // cl
  char *v17; // rdx
  char v18; // cl
  char *v19; // rdx
  char *v20; // rdx
  char v21; // cl
  char *v22; // rdx
  char v23; // cl
  bool v24; // dl
  bool v25; // cl
  bool v26; // dl
  bool v27; // cl
  bool v28; // dl
  bool v29; // cl
  bool v30; // r10
  __int64 v31; // rdx
  char v32; // al
  char *v33; // rcx
  char *v34; // r13
  const char *v35; // rbx
  char *v36; // r8
  __int64 v37; // rdx
  signed __int64 v38; // rdi
  signed __int64 v39; // rsi
  signed __int64 v40; // r14
  signed __int64 v41; // r15
  char v42; // al
  char *v43; // rcx
  __int64 v44; // rdx
  char v45; // al
  char *v46; // rcx
  _QWORD v47[4]; // [rsp+30h] [rbp-20h] BYREF
  __int64 loaded_size; // [rsp+88h] [rbp+38h] BYREF

  UFG::qString::Set(&file_name, name_of_sig_file);
  loaded_size = 0i64;
  v2 = (char *)UFG::StreamFileWrapper::ReadEntireFile(
                 name_of_sig_file,
                 &loaded_size,
                 0i64,
                 0,
                 "StreamFileWrapper::ReadEntireFile");
  v47[0] = 0xF2E4AF21CCD00713ui64;
  v3 = v2 + 16;
  LOBYTE(v47[1]) = 26;
  UFG::Fingerprint::g_FileBuffer = v2;
  v4 = 0;
  v5 = UFG::Fingerprint::gKeyList;
  UFG::Fingerprint::gMarker = v2 + 16;
  do
  {
    ++v5;
    v6 = v4 % 9;
    v7 = 13 * v4++;
    *(v5 - 1) = v7 + *((_BYTE *)v47 + v6);
  }
  while ( v4 < 560 );
  v8 = v3 + 16;
  strcpy((char *)v47, "0123456789ABCDEF");
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
  v24 = v3[544] == *((_BYTE *)v47 + (v10 & 0xF));
  if ( v3[545] != *((_BYTE *)v47 + ((unsigned __int8)v10 >> 4)) )
    v24 = 0;
  v25 = v24;
  if ( v3[546] != *((_BYTE *)v47 + (((unsigned __int64)v10 >> 8) & 0xF)) )
    v25 = 0;
  v26 = v25;
  if ( v3[547] != *((_BYTE *)v47 + ((unsigned __int16)v10 >> 12)) )
    v26 = 0;
  v27 = v26;
  if ( v3[548] != *((_BYTE *)v47 + (((unsigned __int64)v10 >> 16) & 0xF)) )
    v27 = 0;
  v28 = v27;
  if ( v3[549] != *((_BYTE *)v47 + (((unsigned __int64)v10 >> 20) & 0xF)) )
    v28 = 0;
  v29 = v28;
  if ( v3[550] != *((_BYTE *)v47 + (((unsigned __int64)v10 >> 24) & 0xF)) )
    v29 = 0;
  v30 = v29;
  if ( v3[551] != *((_BYTE *)v47 + (v10 >> 28)) )
    v30 = 0;
  v31 = 0i64;
  do
  {
    v32 = UFG::Fingerprint::gKeyList[v31];
    v33 = &UFG::Fingerprint::gKeyList[v31];
    v31 += 5i64;
    *v8 ^= v32;
    v8 += 5;
    v33[v11 + 1] ^= v33[1];
    v33[v12 + 1] ^= v33[2];
    v33[v13 + 1] ^= v33[3];
    v33[v14 + 1] ^= v33[4];
  }
  while ( v31 < 560 );
  if ( v30 )
  {
    v34 = UFG::Fingerprint::gMarker;
    v35 = UFG::Fingerprint::gMarker + 16;
    v36 = UFG::Fingerprint::gMarker + 16;
    v37 = 0i64;
    v38 = UFG::Fingerprint::gMarker - &UFG::Fingerprint::gKeyList[1] + 17;
    v39 = UFG::Fingerprint::gMarker - &UFG::Fingerprint::gKeyList[1] + 18;
    v40 = UFG::Fingerprint::gMarker - &UFG::Fingerprint::gKeyList[1] + 19;
    v41 = UFG::Fingerprint::gMarker - &UFG::Fingerprint::gKeyList[1] + 20;
    do
    {
      v42 = UFG::Fingerprint::gKeyList[v37];
      v43 = &UFG::Fingerprint::gKeyList[v37];
      v37 += 5i64;
      *v36 ^= v42;
      v36 += 5;
      v43[v38 + 1] ^= v43[1];
      v43[v39 + 1] ^= v43[2];
      v43[v40 + 1] ^= v43[3];
      v43[v41 + 1] ^= v43[4];
    }
    while ( v37 < 560 );
    UFG::qStringCopy(UFG::Fingerprint::g_WatermarkTrustee, 256, v34 + 272, -1);
    UFG::Fingerprint::g_showTrustee = (unsigned int)UFG::qStringCompare(
                                                      UFG::Fingerprint::g_WatermarkTrustee,
                                                      "nobody",
                                                      6) != 0;
    UFG::qStringCopy(UFG::Fingerprint::g_Registrar, 256, v35, -1);
    UFG::qStringCopy(UFG::Fingerprint::g_SerialNumber, 16, v34 + 528, -1);
    v44 = v35 - v34 - 16;
    do
    {
      v45 = UFG::Fingerprint::gKeyList[v44];
      v46 = &UFG::Fingerprint::gKeyList[v44];
      v44 += 5i64;
      *v35 ^= v45;
      v35 += 5;
      v46[v38 + 1] ^= v46[1];
      v46[v39 + 1] ^= v46[2];
      v46[v40 + 1] ^= v46[3];
      v46[v41 + 1] ^= v46[4];
    }
    while ( v44 < 560 );
  }
}

// File Line: 101
// RVA: 0x87DC0
char *__fastcall UFG::Fingerprint::GetFingerprintDataBlock()
{
  return UFG::Fingerprint::gMarker;
}

