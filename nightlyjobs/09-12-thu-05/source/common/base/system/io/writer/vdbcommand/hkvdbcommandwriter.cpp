// File Line: 19
// RVA: 0x1301800
void __fastcall hkVdbCommandWriter::hkVdbCommandWriter(hkVdbCommandWriter *this, hkStreamWriter *writer, char command, unsigned int size)
{
  unsigned int v4; // edi
  unsigned int v5; // esi
  char v6; // bp
  hkStreamWriter *v7; // r14
  hkVdbCommandWriter *v8; // rbx
  unsigned int v9; // eax
  char *v10; // rcx
  unsigned int v11; // [rsp+50h] [rbp+18h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v4 = 2147483648;
  this->vfptr = (hkBaseObjectVtbl *)&hkVdbCommandWriter::`vftable';
  v5 = size;
  v6 = command;
  v7 = writer;
  v8 = this;
  v9 = size;
  this->m_buffer.m_data = 0i64;
  this->m_buffer.m_size = 0;
  this->m_buffer.m_capacityAndFlags = 2147483648;
  if ( size )
  {
    v11 = size;
    v10 = (char *)hkContainerDebugAllocator::s_alloc.vfptr->bufAlloc(
                    (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc,
                    (int *)&v11);
    v9 = v11;
  }
  else
  {
    v10 = 0i64;
  }
  v8->m_buffer.m_data = v10;
  v8->m_buffer.m_size = v5;
  if ( v9 )
    v4 = v9;
  v8->m_buffer.m_capacityAndFlags = v4;
  v8->m_command = v6;
  v8->m_writer = v7;
  v8->m_writePos = 0;
}

// File Line: 24
// RVA: 0x13018D0
void __fastcall hkVdbCommandWriter::~hkVdbCommandWriter(hkVdbCommandWriter *this)
{
  hkVdbCommandWriter *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkVdbCommandWriter::`vftable';
  hkVdbCommandWriter::flush(this);
  v2 = v1->m_buffer.m_capacityAndFlags;
  v1->m_buffer.m_size = 0;
  if ( v2 >= 0 )
    hkContainerDebugAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc,
      v1->m_buffer.m_data,
      v2 & 0x3FFFFFFF);
  v1->m_buffer.m_data = 0i64;
  v1->m_buffer.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
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
  hkBool *v2; // rbx

  v2 = result;
  ((void (*)(void))this->m_writer->vfptr[1].__first_virtual_table_function__)();
  return v2;
}

// File Line: 45
// RVA: 0x1301970
__int64 __fastcall hkVdbCommandWriter::write(hkVdbCommandWriter *this, const void *buf, int nbytes)
{
  unsigned int v3; // edi
  int v4; // esi
  _BYTE *v5; // rbp
  hkVdbCommandWriter *v6; // rbx
  int v7; // er9
  signed __int64 v8; // rax
  char v9; // cl

  v3 = 0;
  v4 = nbytes;
  v5 = buf;
  v6 = this;
  if ( nbytes )
  {
    do
    {
      v7 = v4 - v3;
      if ( v6->m_buffer.m_size - v6->m_writePos < (signed int)(v4 - v3) )
        v7 = v6->m_buffer.m_size - v6->m_writePos;
      if ( v7 )
      {
        v8 = 0i64;
        if ( v7 > 0 )
        {
          do
          {
            v9 = v5[(signed int)v3 + v8++];
            v6->m_buffer.m_data[v6->m_writePos - 1 + v8] = v9;
          }
          while ( v8 < v7 );
        }
        v3 += v7;
        v6->m_writePos += v7;
      }
      else
      {
        hkVdbCommandWriter::writeCommand(v6, 0);
      }
    }
    while ( v3 != v4 );
  }
  return v3;
}

// File Line: 70
// RVA: 0x1301A20
void __fastcall hkVdbCommandWriter::writeCommand(hkVdbCommandWriter *this, hkBool final)
{
  hkVdbCommandWriter *v2; // rbx
  hkOArchive v3; // [rsp+20h] [rbp-28h]
  char v4; // [rsp+58h] [rbp+10h]

  v4 = final.m_bool;
  v2 = this;
  hkOArchive::hkOArchive(&v3, this->m_writer, 0);
  hkOArchive::write32u(&v3, v2->m_writePos + 2);
  hkOArchive::write8u(&v3, v2->m_command);
  hkOArchive::write8u(&v3, v4 != 0);
  hkOArchive::~hkOArchive(&v3);
  ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD))v2->m_writer->vfptr[2].__vecDelDtor)(
    v2->m_writer,
    v2->m_buffer.m_data,
    (unsigned int)v2->m_writePos);
  v2->m_writePos = 0;
}

