// File Line: 17
// RVA: 0xC7F560
void __fastcall hkDefaultError::hkDefaultError(
        hkDefaultError *this,
        void (__fastcall *errorReportFunction)(const char *, void *),
        void *errorReportObject)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkDefaultError::`vftable;
  this->m_disabledAssertIds.m_map.m_hashMod = -1;
  this->m_disabledAssertIds.m_map.m_elem = 0i64;
  this->m_disabledAssertIds.m_map.m_numElems = 0;
  this->m_sectionIds.m_data = 0i64;
  this->m_sectionIds.m_size = 0;
  this->m_sectionIds.m_capacityAndFlags = 0x80000000;
  this->m_minimumMessageLevel = MESSAGE_ALL;
  this->m_errorFunction = errorReportFunction;
  this->m_errorObject = errorReportObject;
}

// File Line: 29
// RVA: 0xC7F5B0
void __fastcall hkDefaultError::setEnabled(hkDefaultError *this, int id, hkBool enabled)
{
  hkPointerMap<int,int,hkContainerHeapAllocator> *p_m_disabledAssertIds; // rcx
  hkResult result; // [rsp+48h] [rbp+20h] BYREF

  p_m_disabledAssertIds = &this->m_disabledAssertIds;
  if ( enabled.m_bool )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
      &p_m_disabledAssertIds->m_map,
      &result,
      id);
  else
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &p_m_disabledAssertIds->m_map,
      &hkContainerHeapAllocator::s_alloc,
      id,
      1ui64);
}

// File Line: 41
// RVA: 0xC7F5F0
hkBool *__fastcall hkDefaultError::isEnabled(hkDefaultError *this, hkBool *result, int id)
{
  result->m_bool = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                   &this->m_disabledAssertIds.m_map,
                                   id,
                                   0i64) == 0;
  return result;
}

// File Line: 46
// RVA: 0xC7F620
void __fastcall hkDefaultError::enableAll(hkDefaultError *this)
{
  this->m_minimumMessageLevel = MESSAGE_ALL;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_disabledAssertIds.m_map);
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
void __fastcall hkDefaultError::showMessage(
        hkDefaultError *this,
        const char *what,
        int id,
        const char *desc,
        const char *file,
        int line,
        hkBool stackTrace)
{
  void *m_errorObject; // rdx
  int v9; // edi
  unsigned __int64 trace; // [rsp+40h] [rbp-2408h] BYREF
  unsigned __int64 v11[126]; // [rsp+50h] [rbp-23F8h] BYREF
  char buf[8200]; // [rsp+440h] [rbp-2008h] BYREF
  hkStackTracer v13; // [rsp+2450h] [rbp+8h] BYREF

  if ( id )
  {
    if ( id != -1 )
    {
      hkString::snprintf(buf, 0x2000, "%s(%d): [0x%08X] %s: %s", file, line, id, what, desc);
      goto LABEL_7;
    }
  }
  else if ( !file )
  {
    hkString::snprintf(buf, 0x2000, "%s", desc);
    goto LABEL_7;
  }
  hkString::snprintf(buf, 0x2000, "%s(%d): %s: %s", file, line, what, desc);
LABEL_7:
  m_errorObject = this->m_errorObject;
  buf[0x1FFF] = 0;
  this->m_errorFunction(buf, m_errorObject);
  if ( stackTrace.m_bool )
  {
    hkStackTracer::hkStackTracer(&v13);
    v9 = hkStackTracer::getStackTrace(&v13, (void **)&trace, 0x80u, 0);
    if ( v9 > 2 )
    {
      this->m_errorFunction("Stack trace is:\n", this->m_errorObject);
      hkStackTracer::dumpStackTrace(&v13, v11, v9 - 2, this->m_errorFunction, this->m_errorObject);
    }
    hkStackTracer::~hkStackTracer(&v13);
  }
}

// File Line: 117
// RVA: 0xC7F660
_BOOL8 __fastcall hkDefaultError::message(
        hkDefaultError *this,
        int msg,
        unsigned int id,
        const char *description,
        const char *file,
        int line)
{
  unsigned int v7; // esi
  char v11; // al
  char *v12; // r11
  char v13; // [rsp+58h] [rbp+10h] BYREF

  v7 = id;
  if ( id == -1 && this->m_sectionIds.m_size )
    v7 = this->m_sectionIds.m_data[this->m_sectionIds.m_size - 1];
  if ( msg < ((int (__fastcall *)(hkDefaultError *))this->vfptr[3].__first_virtual_table_function__)(this)
    || !*(_BYTE *)((__int64 (__fastcall *)(hkDefaultError *, char *, _QWORD))this->vfptr[2].__first_virtual_table_function__)(
                    this,
                    &v13,
                    v7) )
  {
    return 0i64;
  }
  v11 = 0;
  v12 = &customCaption;
  if ( msg )
  {
    switch ( msg )
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
  ((void (__fastcall *)(hkDefaultError *, char *, _QWORD, const char *, const char *, int, char))this->vfptr[5].__first_virtual_table_function__)(
    this,
    v12,
    v7,
    description,
    file,
    line,
    v11);
  return (unsigned int)(msg - 2) <= 1;
}

// File Line: 162
// RVA: 0xC7F750
void __fastcall hkDefaultError::sectionBegin(hkDefaultError *this, int id, const char *sectionName)
{
  hkArray<int,hkContainerHeapAllocator> *p_m_sectionIds; // rbx

  p_m_sectionIds = &this->m_sectionIds;
  if ( this->m_sectionIds.m_size == (this->m_sectionIds.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_sectionIds->m_data, 4);
  p_m_sectionIds->m_data[p_m_sectionIds->m_size++] = id;
}

// File Line: 167
// RVA: 0xC7F7A0
void __fastcall hkDefaultError::sectionEnd(hkDefaultError *this)
{
  --this->m_sectionIds.m_size;
}

