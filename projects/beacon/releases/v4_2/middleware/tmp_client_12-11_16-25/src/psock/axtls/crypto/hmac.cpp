// File Line: 47
// RVA: 0xEF3C7C
void __fastcall hmac_md5(const char *msg, unsigned int length, const char *key, int key_len, char *digest)
{
  size_t v8; // rbx
  __int64 i; // rax
  MD5_CTX ctx; // [rsp+20h] [rbp-E0h] BYREF
  char msga[64]; // [rsp+80h] [rbp-80h] BYREF
  char Dst[64]; // [rsp+C0h] [rbp-40h] BYREF

  v8 = key_len;
  memset(Dst, 0, sizeof(Dst));
  memset(msga, 0, sizeof(msga));
  memmove(Dst, key, v8);
  memmove(msga, key, v8);
  for ( i = 0i64; i < 64; ++i )
  {
    Dst[i] ^= 0x36u;
    msga[i] ^= 0x5Cu;
  }
  MD5_Init(&ctx);
  MD5_Update(&ctx, Dst, 0x40u);
  MD5_Update(&ctx, msg, length);
  MD5_Final(digest, &ctx);
  MD5_Init(&ctx);
  MD5_Update(&ctx, msga, 0x40u);
  MD5_Update(&ctx, digest, 0x10u);
  MD5_Final(digest, &ctx);
}

// File Line: 79
// RVA: 0xEF3D98
void __fastcall hmac_sha1(const char *msg, unsigned int length, const char *key, int key_len, char *digest)
{
  size_t v8; // rbx
  __int64 i; // rax
  SHA1_CTX context; // [rsp+20h] [rbp-E0h] BYREF
  char data[64]; // [rsp+80h] [rbp-80h] BYREF
  char Dst[64]; // [rsp+C0h] [rbp-40h] BYREF

  v8 = key_len;
  memset(Dst, 0, sizeof(Dst));
  memset(data, 0, sizeof(data));
  memmove(Dst, key, v8);
  memmove(data, key, v8);
  for ( i = 0i64; i < 64; ++i )
  {
    Dst[i] ^= 0x36u;
    data[i] ^= 0x5Cu;
  }
  SHA1_Init(&context);
  SHA1_Update(&context, Dst, 0x40u);
  SHA1_Update(&context, msg, length);
  SHA1_Final(digest, &context);
  SHA1_Init(&context);
  SHA1_Update(&context, data, 0x40u);
  SHA1_Update(&context, digest, 0x14u);
  SHA1_Final(digest, &context);
}

