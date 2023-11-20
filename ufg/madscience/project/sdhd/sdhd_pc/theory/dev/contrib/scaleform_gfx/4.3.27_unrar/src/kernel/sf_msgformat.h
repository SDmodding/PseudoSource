// File Line: 52
// RVA: 0x94A4E0
void __fastcall Scaleform::FmtResource::~FmtResource(Scaleform::FmtResource *this)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable';
}

// File Line: 1031
// RVA: 0x92C590
void __fastcall Scaleform::MsgFormat::FormatD1<bool>(Scaleform::MsgFormat *this, const bool *v)
{
  const bool *v2; // rsi
  Scaleform::MsgFormat *v3; // rdi
  Scaleform::MemoryHeap **v4; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  signed __int64 v7; // rdx
  Scaleform::MemoryHeap *v8; // rcx
  bool v9; // dl

  v2 = v;
  v3 = this;
  if ( Scaleform::MsgFormat::NextFormatter(this) )
  {
    v4 = &v3->MemPool.pHeap;
    do
    {
      if ( v3->MemPool.BuffSize < 0x30 )
      {
        v8 = *v4;
        if ( !*v4 )
          v8 = Scaleform::Memory::pGlobalHeap;
        v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, signed __int64))v8->vfptr->Alloc)(
               v8,
               48i64,
               8i64);
      }
      else
      {
        v5 = (__int64)v3->MemPool.BuffPtr;
        v3->MemPool.BuffPtr = (char *)(((v5 + 47) & 0xFFFFFFFFFFFFFFF8ui64) + 8);
        v6 = ((v5 + 47) & 0xFFFFFFFFFFFFFFF8ui64) - (_QWORD)v4;
        if ( v6 >= 0x200 )
          v7 = 0i64;
        else
          v7 = 512 - v6;
        v3->MemPool.BuffSize = v7;
      }
      if ( v5 )
      {
        v9 = *v2;
        *(_QWORD *)v5 = &Scaleform::FmtResource::`vftable';
        *(_QWORD *)v5 = &Scaleform::Formatter::`vftable';
        *(_QWORD *)(v5 + 8) = v3;
        *(_BYTE *)(v5 + 16) = 0;
        *(_QWORD *)v5 = &Scaleform::BoolFormatter::`vftable';
        *(_BYTE *)(v5 + 24) = v9 | *(_BYTE *)(v5 + 24) & 0xFC;
        *(_QWORD *)(v5 + 32) = 0i64;
        *(_QWORD *)(v5 + 40) = 0i64;
      }
      else
      {
        v5 = 0i64;
      }
      Scaleform::MsgFormat::Bind(v3, (Scaleform::Formatter *)v5, 1);
    }
    while ( Scaleform::MsgFormat::NextFormatter(v3) );
  }
  ++v3->FirstArgNum;
}

// File Line: 1227
// RVA: 0x883740
unsigned __int64 __fastcall Scaleform::Format<Scaleform::String>(Scaleform::MsgFormat::Sink *result, const char *fmt, Scaleform::String *v1)
{
  Scaleform::String *v3; // rdi
  const char *v4; // rbx
  unsigned __int64 v5; // rbx
  Scaleform::MsgFormat v7; // [rsp+30h] [rbp-408h]

  v3 = v1;
  v4 = fmt;
  Scaleform::MsgFormat::MsgFormat(&v7, result);
  Scaleform::MsgFormat::Parse(&v7, v4);
  Scaleform::MsgFormat::FormatD1<Scaleform::String>(&v7, v3);
  Scaleform::MsgFormat::FinishFormatD(&v7);
  v5 = v7.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v7);
  return v5;
}

// File Line: 1758
// RVA: 0x76C1C0
Scaleform::String *__fastcall Scaleform::AsString<unsigned long>(Scaleform::String *result, const unsigned int *v)
{
  const unsigned int *v2; // rbx
  Scaleform::String *v3; // rdi
  Scaleform::MsgFormat::Sink r; // [rsp+30h] [rbp-428h]
  Scaleform::MsgFormat v6; // [rsp+50h] [rbp-408h]

  v2 = v;
  v3 = result;
  Scaleform::String::String(result);
  r.Type = 0;
  r.SinkData.pStr = v3;
  Scaleform::MsgFormat::MsgFormat(&v6, &r);
  Scaleform::MsgFormat::Parse(&v6, "{0}");
  Scaleform::MsgFormat::FormatD1<unsigned long>(&v6, v2);
  Scaleform::MsgFormat::FinishFormatD(&v6);
  Scaleform::MsgFormat::~MsgFormat(&v6);
  return v3;
}

