// File Line: 17
// RVA: 0xC7F560
void __fastcall hkDefaultError::hkDefaultError(hkDefaultError *this, void (__fastcall *errorReportFunction)(const char *, void *), void *errorReportObject)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkDefaultError::`vftable;
  this->m_disabledAssertIds.m_map.m_hashMod = -1;
  this->m_disabledAssertIds.m_map.m_elem = 0i64;
  this->m_disabledAssertIds.m_map.m_numElems = 0;
  this->m_sectionIds.m_data = 0i64;
  this->m_sectionIds.m_size = 0;
  this->m_sectionIds.m_capacityAndFlags = 2147483648;
  this->m_minimumMessageLevel = 0;
  this->m_errorFunction = errorReportFunction;
  this->m_errorObject = errorReportObject;
}

// File Line: 29
// RVA: 0xC7F5B0
void __fastcall hkDefaultError::setEnabled(hkDefaultError *this, int id, hkBool enabled)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v3; // rcx
  hkResult result; // [rsp+48h] [rbp+20h]

  v3 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_disabledAssertIds.m_map.m_elem;
  if ( enabled.m_bool )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(v3, &result, id);
  else
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      v3,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      id,
      1ui64);
}

// File Line: 41
// RVA: 0xC7F5F0
hkBool *__fastcall hkDefaultError::isEnabled(hkDefaultError *this, hkBool *result, int id)
{
  hkBool *v3; // rbx

  v3 = result;
  result->m_bool = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                   (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_disabledAssertIds.m_map.m_elem,
                                   id,
                                   0i64) == 0;
  return v3;
}

// File Line: 46
// RVA: 0xC7F620
void __fastcall hkDefaultError::enableAll(hkDefaultError *this)
{
  this->m_minimumMessageLevel = 0;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_disabledAssertIds.m_map.m_elem);
}

// File Line: 53
// RVA: 0xC7F640
void __fastcall hkDefaultError::setMinimumMessageLevel(hkDefaultError *this, hkError::Message msg)
{
  this->m_minimumMessageLevel = msg;
}

// File Line: 59
// RVA: 0xC7F650
__int64 __fastcall hkDefaultError::getMinimumMessageLevel(hkDefaultError *this)
{
  return (unsigned int)this->m_minimumMessageLevel;
}

// File Line: 65
// RVA: 0xC7F7B0
void __fastcall hkDefaultError::showMessage(hkDefaultError *this, const char *what, int id, const char *desc, const char *file, int line, hkBool stackTrace)
{
  hkDefaultError *v7; // rbx
  void *v8; // rdx
  signed int v9; // edi
  void *context; // [rsp+20h] [rbp-2428h]
  __int64 v11; // [rsp+28h] [rbp-2420h]
  unsigned __int64 trace; // [rsp+40h] [rbp-2408h]
  unsigned __int64 v13; // [rsp+50h] [rbp-23F8h]
  char buf; // [rsp+440h] [rbp-2008h]
  char v15; // [rsp+243Fh] [rbp-9h]
  hkStackTracer v16; // [rsp+2450h] [rbp+8h]

  v7 = this;
  if ( id )
  {
    if ( id != -1 )
    {
      LODWORD(v11) = id;
      LODWORD(context) = line;
      hkString::snprintf(&buf, 0x2000, "%s(%d): [0x%08X] %s: %s", file, context, v11, what, desc);
      goto LABEL_7;
    }
  }
  else if ( !file )
  {
    hkString::snprintf(&buf, 0x2000, "%s", desc);
    goto LABEL_7;
  }
  LODWORD(context) = line;
  hkString::snprintf(&buf, 0x2000, "%s(%d): %s: %s", file, context, what, desc);
LABEL_7:
  v8 = v7->m_errorObject;
  v15 = 0;
  v7->m_errorFunction(&buf, v8);
  if ( stackTrace.m_bool )
  {
    hkStackTracer::hkStackTracer(&v16);
    v9 = hkStackTracer::getStackTrace(&v16, &trace, 128, 0);
    if ( v9 > 2 )
    {
      v7->m_errorFunction("Stack trace is:\n", v7->m_errorObject);
      hkStackTracer::dumpStackTrace(&v16, &v13, v9 - 2, v7->m_errorFunction, v7->m_errorObject);
    }
    hkStackTracer::~hkStackTracer(&v16);
  }
}

// File Line: 117
// RVA: 0xC7F660
_BOOL8 __fastcall hkDefaultError::message(hkDefaultError *this, hkError::Message msg, int id, const char *description, const char *file, int line)
{
  const char *v6; // rbp
  unsigned int v7; // esi
  hkError::Message v8; // edi
  hkDefaultError *v9; // rbx
  char v11; // al
  char *v12; // r11
  char v13; // [rsp+58h] [rbp+10h]

  v6 = description;
  v7 = id;
  v8 = msg;
  v9 = this;
  if ( id == -1 && this->m_sectionIds.m_size )
    v7 = this->m_sectionIds.m_data[this->m_sectionIds.m_size - 1];
  if ( msg < ((signed int (*)(void))this->vfptr[3].__first_virtual_table_function__)()
    || !*(_BYTE *)((__int64 (__fastcall *)(hkDefaultError *, char *, _QWORD))v9->vfptr[2].__first_virtual_table_function__)(
                    v9,
                    &v13,
                    v7) )
  {
    return 0i64;
  }
  v11 = 0;
  v12 = &customWorldMapCaption;
  if ( v8 )
  {
    switch ( v8 )
    {
      case 1:
        v12 = "Warning";
        break;
      case 2:
        v12 = "Assert";
        v11 = 1;
        break;
      case 3:
        v12 = "Error";
        v11 = 1;
        break;
    }
  }
  else
  {
    v12 = "Report";
  }
  ((void (__fastcall *)(hkDefaultError *, char *, _QWORD, const char *, const char *, int, char))v9->vfptr[5].__first_virtual_table_function__)(
    v9,
    v12,
    v7,
    v6,
    file,
    line,
    v11);
  return (unsigned int)(v8 - 2) <= 1;
}

// File Line: 162
// RVA: 0xC7F750
void __fastcall hkDefaultError::sectionBegin(hkDefaultError *this, int id, const char *sectionName)
{
  hkArray<int,hkContainerHeapAllocator> *v3; // rbx
  int v4; // edi

  v3 = &this->m_sectionIds;
  v4 = id;
  if ( this->m_sectionIds.m_size == (this->m_sectionIds.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 4);
  v3->m_data[v3->m_size++] = v4;
}

// File Line: 167
// RVA: 0xC7F7A0
void __fastcall hkDefaultError::sectionEnd(hkDefaultError *this)
{
  --this->m_sectionIds.m_size;
}

