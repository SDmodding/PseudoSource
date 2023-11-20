// File Line: 9
// RVA: 0xEEB1B8
bool __fastcall operator<<(OSuite::IWriter *writer, OSuite::IReader *reader)
{
  return operator<<(writer, reader);
}

// File Line: 20
// RVA: 0xEEB1C0
char __fastcall operator<<(OSuite::IWriter *writer, OSuite::IReader *pReader)
{
  OSuite::IWriter *v2; // r15
  OSuite::IReader *v3; // r14
  char v4; // si
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdx
  void *v8; // rdi
  signed __int64 v9; // r8
  __int64 v10; // rbp

  v2 = writer;
  v3 = pReader;
  v4 = 1;
  v5 = pReader->vfptr->ReadyToRead(pReader);
  v6 = v5;
  v7 = 0x8000i64;
  if ( v5 <= 0x8000 )
    v7 = v5;
  v8 = OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, v7, 0i64);
  if ( v6 )
  {
    while ( 1 )
    {
      v9 = v6;
      if ( v6 > 0x8000 )
        v9 = 0x8000i64;
      v10 = (*((__int64 (__fastcall **)(OSuite::IReader *, void *, signed __int64))&v3->vfptr->__vecDelDtor + 1))(
              v3,
              v8,
              v9);
      if ( !v10 || !v2->vfptr->WriteBuffer(v2, v8, v10) )
        break;
      v6 -= v10;
      if ( !v6 )
        goto LABEL_11;
    }
    v4 = 0;
  }
LABEL_11:
  OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v8);
  return v4;
}

