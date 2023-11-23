// File Line: 115
// RVA: 0xEEE7A4
void __fastcall RNG_initialize(const char *seed_buf, int size)
{
  int v2; // eax
  DWORD LastError; // eax
  DWORD dwFlags; // [rsp+20h] [rbp-18h]

  v2 = rng_ref_count;
  if ( !rng_ref_count )
  {
    if ( !CryptAcquireContextA(&gCryptProv, 0i64, 0i64, rng_ref_count + 1, rng_ref_count & dwFlags)
      && GetLastError() == -2146893802
      && !CryptAcquireContextA(&gCryptProv, 0i64, 0i64, 1u, 8u) )
    {
      LastError = GetLastError();
      printf("CryptoLib: %s %x\n", "Error: Feature not supported\n", LastError);
      exit(1);
    }
    v2 = rng_ref_count;
  }
  rng_ref_count = v2 + 1;
}

// File Line: 171
// RVA: 0xEEE83C
void RNG_terminate(void)
{
  if ( !--rng_ref_count )
    CryptReleaseContext(gCryptProv, 0);
}

// File Line: 186
// RVA: 0xEEE85C
void __fastcall get_random(DWORD num_rand_bytes, char *rand_data)
{
  CryptGenRandom(gCryptProv, num_rand_bytes, rand_data);
}

// File Line: 233
// RVA: 0xEEE870
void __fastcall get_random_NZ(DWORD num_rand_bytes, char *rand_data)
{
  __int64 v2; // rbx
  char *v3; // rdi
  char v4; // al

  v2 = (int)num_rand_bytes;
  v3 = rand_data;
  CryptGenRandom(gCryptProv, num_rand_bytes, rand_data);
  if ( v2 > 0 )
  {
    do
    {
      if ( !*v3 )
      {
        do
        {
          v4 = rand();
          *v3 = v4;
        }
        while ( !v4 );
      }
      ++v3;
      --v2;
    }
    while ( v2 );
  }
}

