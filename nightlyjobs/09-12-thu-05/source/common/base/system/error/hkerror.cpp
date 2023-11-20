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
void __fastcall hkErrStream::hkErrStream(hkErrStream *this, void *buf, int bufSize)
{
  char *v3; // rsi
  __int64 v4; // rbx
  hkErrStream *v5; // rdi
  hkBufferedStreamWriter *v6; // rcx
  hkReferencedObject *v7; // rax
  hkReferencedObject *v8; // rbx
  hkReferencedObject *v9; // rcx

  v3 = (char *)buf;
  v4 = bufSize;
  v5 = this;
  hkOstream::hkOstream((hkOstream *)&this->vfptr, 0i64);
  v5->vfptr = (hkBaseObjectVtbl *)&hkErrStream::`vftable';
  v6 = (hkBufferedStreamWriter *)&v3[v4 - 48];
  if ( v6 )
  {
    hkBufferedStreamWriter::hkBufferedStreamWriter(v6, v3, v4 - 48, (hkBool)1);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( v8 )
    hkReferencedObject::addReference(v8);
  v9 = (hkReferencedObject *)&v5->m_writer.m_pntr->vfptr;
  if ( v9 )
    hkReferencedObject::removeReference(v9);
  v5->m_writer.m_pntr = (hkStreamWriter *)v8;
  hkReferencedObject::addReferenceLockUnchecked(v8);
}

// File Line: 25
// RVA: 0xC670D0
void __fastcall hkReferenceCountError(hkReferencedObject *o, const char *why)
{
  const char *v2; // rsi
  hkReferencedObject *v3; // rbx
  int v4; // edi
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
  hkErrStream v16; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v2 = why;
  v3 = o;
  hkErrStream::hkErrStream(&v16, &buf, 512);
  v4 = v3->m_referenceCount;
  v5 = hkOstream::operator<<((hkOstream *)&v16.vfptr, "Reference count error on object ");
  v6 = hkOstream::operator<<(v5, v3, (int)v5);
  v7 = hkOstream::operator<<(v6, " with ref count of ");
  v8 = hkOstream::operator<<(v7, v4, (int)v7);
  v9 = hkOstream::operator<<(v8, " in ");
  v10 = hkOstream::operator<<(v9, v2);
  v11 = hkOstream::operator<<(v10, ".\n");
  v12 = hkOstream::operator<<(v11, " * Are you calling delete instead of removeReference?\n");
  v13 = hkOstream::operator<<(v12, " * Have you called removeReference too many times?\n");
  v14 = hkOstream::operator<<(
          v13,
          " * In a multithreaded environment, what is the hkReferencedObject lock mode you use (see setLockMode())?\n");
  v15 = hkOstream::operator<<(v14, " * Is this a valid object?\n");
  hkOstream::operator<<(v15, " * Do you have more than 32768 references? (unlikely)\n");
  if ( (unsigned int)hkError::messageError(744944344, &buf, "System\\Error\\hkError.cpp", 33) )
    __debugbreak();
  hkOstream::~hkOstream((hkOstream *)&v16.vfptr);
}

// File Line: 39
// RVA: 0xC671F0
void __fastcall hkErrorMessage(const char *c)
{
  const char *v1; // rbx
  hkErrStream v2; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v1 = c;
  hkErrStream::hkErrStream(&v2, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v2.vfptr, v1);
  if ( (unsigned int)hkError::messageError(641138213, &buf, "System\\Error\\hkError.cpp", 40) )
    __debugbreak();
  hkOstream::~hkOstream((hkOstream *)&v2.vfptr);
}

// File Line: 44
// RVA: 0xC66F40
__int64 __fastcall hkError::messageReport(int id, const char *description, const char *file, int line)
{
  int v4; // ST28_4

  v4 = line;
  return ((__int64 (__fastcall *)(hkError *, _QWORD, _QWORD, const char *, const char *, int))hkSingleton<hkError>::s_instance->vfptr[1].__first_virtual_table_function__)(
           hkSingleton<hkError>::s_instance,
           0i64,
           (unsigned int)id,
           description,
           file,
           v4);
}

// File Line: 49
// RVA: 0xC66F80
__int64 __fastcall hkError::messageWarning(int id, const char *description, const char *file, int line)
{
  int v4; // ST28_4

  v4 = line;
  return ((__int64 (__fastcall *)(hkError *, signed __int64, _QWORD, const char *, const char *, int))hkSingleton<hkError>::s_instance->vfptr[1].__first_virtual_table_function__)(
           hkSingleton<hkError>::s_instance,
           1i64,
           (unsigned int)id,
           description,
           file,
           v4);
}

// File Line: 54
// RVA: 0xC66FC0
__int64 __fastcall hkError::messageAssert(int id, const char *description, const char *file, int line)
{
  int v4; // ST28_4

  v4 = line;
  return ((__int64 (__fastcall *)(hkError *, signed __int64, _QWORD, const char *, const char *, int))hkSingleton<hkError>::s_instance->vfptr[1].__first_virtual_table_function__)(
           hkSingleton<hkError>::s_instance,
           2i64,
           (unsigned int)id,
           description,
           file,
           v4);
}

// File Line: 59
// RVA: 0xC67000
__int64 __fastcall hkError::messageError(int id, const char *description, const char *file, int line)
{
  int v4; // ST28_4

  v4 = line;
  return ((__int64 (__fastcall *)(hkError *, signed __int64, _QWORD, const char *, const char *, int))hkSingleton<hkError>::s_instance->vfptr[1].__first_virtual_table_function__)(
           hkSingleton<hkError>::s_instance,
           3i64,
           (unsigned int)id,
           description,
           file,
           v4);
}

