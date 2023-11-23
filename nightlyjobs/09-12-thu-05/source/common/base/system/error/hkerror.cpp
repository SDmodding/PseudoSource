// File Line: 11
// RVA: 0x15C7690
hkSingletonInitNode *dynamic_initializer_for__hkSingletonRegisterhkError__()
{
  hkSingletonInitNode *result; // rax

  hkSingletonRegisterhkError.m_next = hkSingletonInitList;
  result = &hkSingletonRegisterhkError;
  hkSingletonInitList = &hkSingletonRegisterhkError;
  return result;
}

// File Line: 15
// RVA: 0xC67040
void __fastcall hkErrStream::hkErrStream(hkErrStream *this, char *buf, int bufSize)
{
  __int64 v4; // rbx
  hkBufferedStreamWriter *v6; // rcx
  hkStreamWriter *v7; // rax
  hkStreamWriter *v8; // rbx
  hkStreamWriter *m_pntr; // rcx

  v4 = bufSize;
  hkOstream::hkOstream(this, 0i64);
  this->vfptr = (hkBaseObjectVtbl *)&hkErrStream::`vftable;
  v6 = (hkBufferedStreamWriter *)&buf[v4 - 48];
  if ( v6 )
  {
    hkBufferedStreamWriter::hkBufferedStreamWriter(v6, buf, v4 - 48, (hkBool)1);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( v8 )
    hkReferencedObject::addReference(v8);
  m_pntr = this->m_writer.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_writer.m_pntr = v8;
  hkReferencedObject::addReferenceLockUnchecked(v8);
}

// File Line: 25
// RVA: 0xC670D0
void __fastcall hkReferenceCountError(hkReferencedObject *o, const char *why)
{
  unsigned int m_referenceCount; // edi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkErrStream v16; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  hkErrStream::hkErrStream(&v16, buf, 512);
  m_referenceCount = o->m_referenceCount;
  v5 = hkOstream::operator<<(&v16, "Reference count error on object ");
  v6 = hkOstream::operator<<(v5, o);
  v7 = hkOstream::operator<<(v6, " with ref count of ");
  v8 = hkOstream::operator<<(v7, m_referenceCount);
  v9 = hkOstream::operator<<(v8, " in ");
  v10 = hkOstream::operator<<(v9, why);
  v11 = hkOstream::operator<<(v10, ".\n");
  v12 = hkOstream::operator<<(v11, " * Are you calling delete instead of removeReference?\n");
  v13 = hkOstream::operator<<(v12, " * Have you called removeReference too many times?\n");
  v14 = hkOstream::operator<<(
          v13,
          " * In a multithreaded environment, what is the hkReferencedObject lock mode you use (see setLockMode())?\n");
  v15 = hkOstream::operator<<(v14, " * Is this a valid object?\n");
  hkOstream::operator<<(v15, " * Do you have more than 32768 references? (unlikely)\n");
  if ( (unsigned int)hkError::messageError(0x2C66F2D8u, buf, "System\\Error\\hkError.cpp", 33) )
    __debugbreak();
  hkOstream::~hkOstream(&v16);
}

// File Line: 39
// RVA: 0xC671F0
void __fastcall hkErrorMessage(const char *c)
{
  hkErrStream v2; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  hkErrStream::hkErrStream(&v2, buf, 512);
  hkOstream::operator<<(&v2, c);
  if ( (unsigned int)hkError::messageError(0x2636FE25u, buf, "System\\Error\\hkError.cpp", 40) )
    __debugbreak();
  hkOstream::~hkOstream(&v2);
}

// File Line: 44
// RVA: 0xC66F40
__int64 __fastcall hkError::messageReport(unsigned int id, const char *description, const char *file, int line)
{
  return ((__int64 (__fastcall *)(hkError *, _QWORD, _QWORD, const char *, const char *, int))hkSingleton<hkError>::s_instance->vfptr[1].__first_virtual_table_function__)(
           hkSingleton<hkError>::s_instance,
           0i64,
           id,
           description,
           file,
           line);
}

// File Line: 49
// RVA: 0xC66F80
__int64 __fastcall hkError::messageWarning(unsigned int id, const char *description, const char *file, int line)
{
  return ((__int64 (__fastcall *)(hkError *, __int64, _QWORD, const char *, const char *, int))hkSingleton<hkError>::s_instance->vfptr[1].__first_virtual_table_function__)(
           hkSingleton<hkError>::s_instance,
           1i64,
           id,
           description,
           file,
           line);
}

// File Line: 54
// RVA: 0xC66FC0
__int64 __fastcall hkError::messageAssert(unsigned int id, const char *description, const char *file, int line)
{
  return ((__int64 (__fastcall *)(hkError *, __int64, _QWORD, const char *, const char *, int))hkSingleton<hkError>::s_instance->vfptr[1].__first_virtual_table_function__)(
           hkSingleton<hkError>::s_instance,
           2i64,
           id,
           description,
           file,
           line);
}

// File Line: 59
// RVA: 0xC67000
__int64 __fastcall hkError::messageError(unsigned int id, const char *description, const char *file, int line)
{
  return ((__int64 (__fastcall *)(hkError *, __int64, _QWORD, const char *, const char *, int))hkSingleton<hkError>::s_instance->vfptr[1].__first_virtual_table_function__)(
           hkSingleton<hkError>::s_instance,
           3i64,
           id,
           description,
           file,
           line);
}

