// File Line: 47
// RVA: 0xEF3C7C
void __fastcall hmac_md5(const char *msg, int length, const char *key, int key_len, char *digest)
{
  const char *v5; // r14
  const char *v6; // rdi
  int v7; // er15
  size_t v8; // rbx
  signed __int64 v9; // rax
  MD5_CTX ctx; // [rsp+20h] [rbp-E0h]
  char msga[64]; // [rsp+80h] [rbp-80h]
  char Dst[64]; // [rsp+C0h] [rbp-40h]

  v5 = msg;
  v6 = key;
  v7 = length;
  v8 = key_len;
  memset(Dst, 0, 0x40ui64);
  memset(msga, 0, 0x40ui64);
  memmove(Dst, v6, v8);
  memmove(msga, v6, v8);
  v9 = 0i64;
  do
  {
    Dst[v9] ^= 0x36u;
    msga[v9] ^= 0x5Cu;
    ++v9;
  }
  while ( v9 < 64 );
  MD5_Init(&ctx);
  MD5_Update(&ctx, Dst, 64);
  MD5_Update(&ctx, v5, v7);
  MD5_Final(digest, &ctx);
  MD5_Init(&ctx);
  MD5_Update(&ctx, msga, 64);
  MD5_Update(&ctx, digest, 16);
  MD5_Final(digest, &ctx);
}

// File Line: 79
// RVA: 0xEF3D98
void __fastcall hmac_sha1(const char *msg, int length, const char *key, int key_len, char *digest)
{
  const char *v5; // r14
  const char *v6; // rdi
  int v7; // er15
  size_t v8; // rbx
  signed __int64 v9; // rax
  SHA1_CTX context; // [rsp+20h] [rbp-E0h]
  char data[64]; // [rsp+80h] [rbp-80h]
  char Dst[64]; // [rsp+C0h] [rbp-40h]

  v5 = msg;
  v6 = key;
  v7 = length;
  v8 = key_len;
  memset(Dst, 0, 0x40ui64);
  memset(data, 0, 0x40ui64);
  memmove(Dst, v6, v8);
  memmove(data, v6, v8);
  v9 = 0i64;
  do
  {
    Dst[v9] ^= 0x36u;
    data[v9] ^= 0x5Cu;
    ++v9;
  }
  while ( v9 < 64 );
  SHA1_Init(&context);
  SHA1_Update(&context, Dst, 0x40u);
  SHA1_Update(&context, v5, v7);
  SHA1_Final(digest, &context);
  SHA1_Init(&context);
  SHA1_Update(&context, data, 0x40u);
  SHA1_Update(&context, digest, 0x14u);
  SHA1_Final(digest, &context);
}

