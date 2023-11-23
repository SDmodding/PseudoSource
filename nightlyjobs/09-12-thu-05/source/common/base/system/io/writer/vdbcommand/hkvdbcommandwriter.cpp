// File Line: 19
// RVA: 0x1301800
void __fastcall hkVdbCommandWriter::hkVdbCommandWriter(
        hkVdbCommandWriter *this,
        hkStreamWriter *writer,
        char command,
        int size)
{
  int v4; // edi
  int v9; // eax
  char *v10; // rcx
  int v11; // [rsp+50h] [rbp+18h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v4 = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkVdbCommandWriter::`vftable;
  v9 = size;
  this->m_buffer.m_data = 0i64;
  this->m_buffer.m_size = 0;
  this->m_buffer.m_capacityAndFlags = 0x80000000;
  if ( size )
  {
    v11 = size;
    v10 = (char *)hkContainerDebugAllocator::s_alloc.vfptr->bufAlloc(&hkContainerDebugAllocator::s_alloc, &v11);
    v9 = v11;
  }
  else
  {
    v10 = 0i64;
  }
  this->m_buffer.m_data = v10;
  this->m_buffer.m_size = size;
  if ( v9 )
    v4 = v9;
  this->m_buffer.m_capacityAndFlags = v4;
  this->m_command = command;
  this->m_writer = writer;
  this->m_writePos = 0;
}

// File Line: 24
// RVA: 0x13018D0
void __fastcall hkVdbCommandWriter::~hkVdbCommandWriter(hkVdbCommandWriter *this)
{
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkVdbCommandWriter::`vftable;
  hkVdbCommandWriter::flush(this);
  m_capacityAndFlags = this->m_buffer.m_capacityAndFlags;
  this->m_buffer.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerDebugAllocator::s_alloc.vfptr->bufFree(
      &hkContainerDebugAllocator::s_alloc,
      this->m_buffer.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_buffer.m_data = 0i64;
  this->m_buffer.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 29
// RVA: 0x13018B0
void __fastcall hkVdbCommandWriter::flush(hkVdbCommandWriter *this)
{
  if ( this->m_writePos )
    hkVdbCommandWriter::writeCommand(this, (hkBool)1);
}

// File Line: 37
// RVA: 0x1301940
hkBool *__fastcall hkVdbCommandWriter::isOk(hkVdbCommandWriter *this, hkBool *result)
{
  this->m_writer->vfptr[1].__first_virtual_table_function__(this->m_writer);
  return result;
}

// File Line: 45
// RVA: 0x1301970
__int64 __fastcall hkVdbCommandWriter::write(hkVdbCommandWriter *this, _BYTE *buf, int nbytes)
{
  unsigned int v3; // edi
  int v7; // r9d
  __int64 i; // rax
  char v9; // cl

  v3 = 0;
  if ( nbytes )
  {
    do
    {
      v7 = nbytes - v3;
      if ( this->m_buffer.m_size - this->m_writePos < (int)(nbytes - v3) )
        v7 = this->m_buffer.m_size - this->m_writePos;
      if ( v7 )
      {
        for ( i = 0i64; i < v7; this->m_buffer.m_data[this->m_writePos - 1 + i] = v9 )
          v9 = buf[(int)v3 + i++];
        v3 += v7;
        this->m_writePos += v7;
      }
      else
      {
        hkVdbCommandWriter::writeCommand(this, 0);
      }
    }
    while ( v3 != nbytes );
  }
  return v3;
}

// File Line: 70
// RVA: 0x1301A20
void __fastcall hkVdbCommandWriter::writeCommand(hkVdbCommandWriter *this, hkBool final)
{
  hkOArchive v3; // [rsp+20h] [rbp-28h] BYREF

  hkOArchive::hkOArchive(&v3, this->m_writer, 0);
  hkOArchive::write32u(&v3, this->m_writePos + 2);
  hkOArchive::write8u(&v3, this->m_command);
  hkOArchive::write8u(&v3, final.m_bool != 0);
  hkOArchive::~hkOArchive(&v3);
  ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD))this->m_writer->vfptr[2].__vecDelDtor)(
    this->m_writer,
    this->m_buffer.m_data,
    (unsigned int)this->m_writePos);
  this->m_writePos = 0;
}

