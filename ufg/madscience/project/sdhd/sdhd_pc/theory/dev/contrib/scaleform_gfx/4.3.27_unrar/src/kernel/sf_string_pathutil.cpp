// File Line: 58
// RVA: 0x9ADB80
char *__fastcall Scaleform::ScanPathProtocol(const char *url)
{
  int v1; // eax
  int v2; // ebx
  int v3; // eax
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  putf8Buffer = (char *)url;
  v1 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
  if ( !v1 )
    --putf8Buffer;
  if ( !v1 )
    return 0i64;
  while ( v1 != 58 )
  {
LABEL_11:
    v1 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    if ( !v1 )
    {
      --putf8Buffer;
      return 0i64;
    }
  }
  v2 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
  if ( !v2 )
    --putf8Buffer;
  v3 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
  if ( !v3 )
  {
    --putf8Buffer;
    goto LABEL_11;
  }
  if ( v3 != 47 || v2 != 47 )
    goto LABEL_11;
  return putf8Buffer;
}

// File Line: 133
// RVA: 0x991360
bool __fastcall Scaleform::String::HasExtension(const char *path)
{
  char *v1; // rbx
  int v2; // eax
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  putf8Buffer = (char *)path;
  v1 = 0i64;
  v2 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
  if ( v2 )
  {
    do
    {
      if ( v2 == 47 || v2 == 92 )
      {
        v1 = 0i64;
      }
      else if ( v2 == 46 )
      {
        v1 = putf8Buffer - 1;
      }
      v2 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    }
    while ( v2 );
    --putf8Buffer;
  }
  else
  {
    --putf8Buffer;
  }
  return v1 != 0i64;
}

// File Line: 145
// RVA: 0x98A4B0
Scaleform::String *__fastcall Scaleform::String::GetPath(Scaleform::String *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rsi
  unsigned __int64 v3; // rbx
  char *v4; // rdi
  int v5; // eax
  signed __int64 v6; // rdi
  char *putf8Buffer; // [rsp+40h] [rbp+8h]
  Scaleform::String *v9; // [rsp+48h] [rbp+10h]

  v9 = result;
  v2 = result;
  v3 = this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v4 = (char *)(v3 + 12);
  putf8Buffer = (char *)(v3 + 12);
  v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
  if ( v5 )
  {
    do
    {
      if ( v5 == 47 || v5 == 92 )
        v4 = putf8Buffer;
      v5 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    }
    while ( v5 );
    --putf8Buffer;
  }
  else
  {
    --putf8Buffer;
  }
  if ( v4 )
    v6 = (signed __int64)&v4[-v3 - 12];
  else
    v6 = *(_QWORD *)v3 & 0x7FFFFFFFFFFFFFFFi64;
  Scaleform::String::String(v2, (const char *)(v3 + 12), v6);
  return v2;
}

// File Line: 156
// RVA: 0x98AC60
Scaleform::String *__fastcall Scaleform::String::GetProtocol(Scaleform::String *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rdi
  Scaleform::String *v3; // rbx
  const char *v4; // rax

  v2 = result;
  v3 = this;
  v4 = Scaleform::ScanPathProtocol((const char *)((this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  if ( v4 )
    v4 = &v4[-(v3->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - 12];
  Scaleform::String::String(v2, (const char *)((v3->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), (unsigned __int64)v4);
  return v2;
}

// File Line: 168
// RVA: 0x983320
Scaleform::String *__fastcall Scaleform::String::GetExtension(Scaleform::String *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rdi
  const char *v3; // rbx
  int v4; // eax
  char *putf8Buffer; // [rsp+40h] [rbp+8h]
  Scaleform::String *v7; // [rsp+48h] [rbp+10h]

  v7 = result;
  v2 = result;
  putf8Buffer = (char *)((this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v3 = 0i64;
  v4 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
  if ( v4 )
  {
    do
    {
      if ( v4 == 47 || v4 == 92 )
      {
        v3 = 0i64;
      }
      else if ( v4 == 46 )
      {
        v3 = putf8Buffer - 1;
      }
      v4 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    }
    while ( v4 );
    --putf8Buffer;
  }
  else
  {
    --putf8Buffer;
  }
  Scaleform::String::String(v2, v3);
  return v2;
}

// File Line: 175
// RVA: 0x9B85D0
Scaleform::String *__fastcall Scaleform::String::StripExtension(Scaleform::String *this)
{
  Scaleform::String *v1; // rdi
  unsigned __int64 v2; // rsi
  char *v3; // rbx
  int v4; // eax
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v3 = 0i64;
  putf8Buffer = (char *)(v2 + 12);
  v4 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
  if ( v4 )
  {
    do
    {
      if ( v4 == 47 || v4 == 92 )
      {
        v3 = 0i64;
      }
      else if ( v4 == 46 )
      {
        v3 = putf8Buffer - 1;
      }
      v4 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    }
    while ( v4 );
    --putf8Buffer;
    if ( v3 )
      Scaleform::String::AssignString(v1, (const char *)(v2 + 12), (unsigned __int64)&v3[-v2 - 12]);
  }
  else
  {
    --putf8Buffer;
  }
  return v1;
}

