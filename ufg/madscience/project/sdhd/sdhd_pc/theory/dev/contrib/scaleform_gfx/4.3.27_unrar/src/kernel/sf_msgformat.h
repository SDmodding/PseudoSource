// File Line: 52
// RVA: 0x94A4E0
void __fastcall Scaleform::FmtResource::~FmtResource(Scaleform::FmtResource *this)
{
  this->vfptr = (Scaleform::FmtResourceVtbl *)&Scaleform::FmtResource::`vftable;
}

// File Line: 1031
// RVA: 0x92C590
void __fastcall Scaleform::MsgFormat::FormatD1<bool>(Scaleform::MsgFormat *this, const bool *v)
{
  Scaleform::StackMemPool<512,8,Scaleform::MemPoolImmediateFree> *p_MemPool; // rbx
  char *BuffPtr; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rdx
  Scaleform::MemoryHeap *pHeap; // rcx
  char v9; // dl

  if ( Scaleform::MsgFormat::NextFormatter(this) )
  {
    p_MemPool = &this->MemPool;
    do
    {
      if ( this->MemPool.BuffSize < 0x30 )
      {
        pHeap = p_MemPool->pHeap;
        if ( !p_MemPool->pHeap )
          pHeap = Scaleform::Memory::pGlobalHeap;
        BuffPtr = (char *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))pHeap->vfptr->Alloc)(
                            pHeap,
                            48i64,
                            8i64);
      }
      else
      {
        BuffPtr = this->MemPool.BuffPtr;
        this->MemPool.BuffPtr = (char *)(((unsigned __int64)(BuffPtr + 47) & 0xFFFFFFFFFFFFFFF8ui64) + 8);
        v6 = ((unsigned __int64)(BuffPtr + 47) & 0xFFFFFFFFFFFFFFF8ui64) - (_QWORD)p_MemPool;
        if ( v6 >= 0x200 )
          v7 = 0i64;
        else
          v7 = 512 - v6;
        this->MemPool.BuffSize = v7;
      }
      if ( BuffPtr )
      {
        v9 = *v;
        *(_QWORD *)BuffPtr = &Scaleform::FmtResource::`vftable;
        *(_QWORD *)BuffPtr = &Scaleform::Formatter::`vftable;
        *((_QWORD *)BuffPtr + 1) = this;
        BuffPtr[16] = 0;
        *(_QWORD *)BuffPtr = &Scaleform::BoolFormatter::`vftable;
        BuffPtr[24] = v9 & 1 | BuffPtr[24] & 0xFC;
        *((_QWORD *)BuffPtr + 4) = 0i64;
        *((_QWORD *)BuffPtr + 5) = 0i64;
      }
      else
      {
        BuffPtr = 0i64;
      }
      Scaleform::MsgFormat::Bind(this, (Scaleform::Formatter *)BuffPtr, 1);
    }
    while ( Scaleform::MsgFormat::NextFormatter(this) );
  }
  ++this->FirstArgNum;
}

// File Line: 1227
// RVA: 0x883740
unsigned __int64 __fastcall Scaleform::Format<Scaleform::String>(
        Scaleform::MsgFormat::Sink *result,
        const char *fmt,
        Scaleform::String *v1)
{
  unsigned __int64 StrSize; // rbx
  Scaleform::MsgFormat v7; // [rsp+30h] [rbp-408h] BYREF

  Scaleform::MsgFormat::MsgFormat(&v7, result);
  Scaleform::MsgFormat::Parse(&v7, fmt);
  Scaleform::MsgFormat::FormatD1<Scaleform::String>(&v7, v1);
  Scaleform::MsgFormat::FinishFormatD(&v7);
  StrSize = v7.StrSize;
  Scaleform::MsgFormat::~MsgFormat(&v7);
  return StrSize;
}

// File Line: 1758
// RVA: 0x76C1C0
Scaleform::String *__fastcall Scaleform::AsString<unsigned long>(Scaleform::String *result, const unsigned int *v)
{
  Scaleform::MsgFormat::Sink r; // [rsp+30h] [rbp-428h] BYREF
  Scaleform::MsgFormat v6; // [rsp+50h] [rbp-408h] BYREF

  Scaleform::String::String(result);
  r.Type = tStr;
  r.SinkData.pStr = result;
  Scaleform::MsgFormat::MsgFormat(&v6, &r);
  Scaleform::MsgFormat::Parse(&v6, "{0}");
  Scaleform::MsgFormat::FormatD1<unsigned long>(&v6, v);
  Scaleform::MsgFormat::FinishFormatD(&v6);
  Scaleform::MsgFormat::~MsgFormat(&v6);
  return result;
}

